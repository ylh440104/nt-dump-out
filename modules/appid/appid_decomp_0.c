
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
  *param_6 = PTR_DAT_140018008;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_140018008;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_140018020,&local_18,0,0,param_5,param_6);
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



===== __report_rangecheckfailure @ 1400010d0 =====

void __report_rangecheckfailure(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(8);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _stricmp @ 1400010dd =====

int __cdecl _stricmp(char *_Str1,char *_Str2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400010dd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = _stricmp(_Str1,_Str2);
  return iVar1;
}



===== __C_specific_handler @ 140001106 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140001106. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== SymCryptFatal @ 140001138 =====

void SymCryptFatal(undefined4 param_1)

{
  code *pcVar1;
  
  SymCryptFatalEnvWindowsKernelmodeWin8_1nLater(param_1);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== WPP_SF_ @ 140001148 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_D @ 140001174 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WppClassicProviderCallback @ 1400011c0 =====

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



===== _tlgDefineProvider_annotation__Tlgg_hLogProviderProv @ 1400011f4 =====

void _tlgDefineProvider_annotation__Tlgg_hLogProviderProv(void)

{
  return;
}



===== wil_details_RecordCachedUsage @ 140001200 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140001360 =====

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



===== Feature_Servicing_ApplockerNoisyLogs__private_IsEnabledDeviceUsageNoInline @ 1400013e4 =====

ulonglong Feature_Servicing_ApplockerNoisyLogs__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_Servicing_ApplockerNoisyLogs__private_featureState;
  if ((Feature_Servicing_ApplockerNoisyLogs__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Servicing_ApplockerNoisyLogs__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_Servicing_ApplockerNoisyLogs__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Servicing_ApplockerNoisyLogs__private_IsEnabledFallback @ 14000141c =====

void Feature_Servicing_ApplockerNoisyLogs__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&wil_details_featureDescriptors_a);
  return;
}



===== WPP_SF_ZD @ 140001438 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ZD(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4,
              undefined1 param_5)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  
  if (param_4 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_4;
    if (*param_4 != L'\0') {
      pwVar1 = *(wchar_t **)(param_4 + 4);
      goto LAB_140001465;
    }
  }
  pwVar1 = L"NULL";
LAB_140001465:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,2,pwVar1,wVar2,&param_5,4,0);
  return;
}



===== WPP_SF_qDDZcZ @ 1400014cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDDZcZ(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  undefined1 param_5,undefined1 param_6,wchar_t *param_7,undefined1 param_8,
                  wchar_t *param_9)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t wVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  wchar_t *pwVar6;
  undefined8 local_res20;
  
  pwVar5 = L"NULL";
  if (param_9 == (wchar_t *)0x0) {
    wVar3 = L'\b';
  }
  else {
    wVar3 = *param_9;
    if (*param_9 != L'\0') {
      pwVar6 = *(wchar_t **)(param_9 + 4);
      goto LAB_140001522;
    }
  }
  pwVar6 = L"NULL";
LAB_140001522:
  pwVar2 = param_9;
  if (param_9 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  if (param_7 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *param_7;
    if (*param_7 != L'\0') {
      pwVar5 = *(wchar_t **)(param_7 + 4);
    }
  }
  pwVar4 = param_7;
  if (param_7 == (wchar_t *)0x0) {
    pwVar4 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_e716c585d1643cef6ac097e6d79a981c_Traceguids,10,&local_res20,8,
             &param_5,4,&param_6,4,pwVar4,2,pwVar5,wVar1,&param_8,1,pwVar2,2,pwVar6,wVar3,0);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140001620 =====

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
LAB_140001835:
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
LAB_140001703:
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
      if (param_3 == 4) goto LAB_140001835;
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
        goto LAB_140001703;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140001928 =====

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
      goto LAB_1400019f9;
    }
    if (param_3 == 2) {
      uVar3 = (uVar2 ^ 1) * 4 + 1;
      goto LAB_1400019f9;
    }
    if (param_3 == 3) {
      uVar3 = (uVar2 ^ 1) * 4 + 2;
      goto LAB_1400019f9;
    }
    if (param_3 == 4) {
      uVar3 = (uVar2 ^ 1) * 4 + 3;
      goto LAB_1400019f9;
    }
    if (param_3 == 5) {
      uVar3 = (uVar2 ^ 1) * 2 + 8;
      goto LAB_1400019f9;
    }
    if (param_3 == 6) {
      uVar3 = (uVar2 ^ 1) * 2 + 9;
      goto LAB_1400019f9;
    }
    bVar4 = (char)param_3 + 0x9c;
    if (bVar4 < 0x32) {
      uVar3 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar4;
      goto LAB_1400019f9;
    }
  }
  uVar3 = 0xff;
LAB_1400019f9:
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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140001a54 =====

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



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140001b3c =====

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
LAB_140001bef:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_140001c1d;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_140001bef;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_140001c1d:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140001da8 =====

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



===== wil_details_IsEnabledFallback @ 140001e0c =====

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



===== Feature_Servicing_ApplockerPickBestClaim__private_IsEnabledDeviceUsageNoInline @ 140001ea8 =====

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



===== Feature_Servicing_ApplockerPickBestClaim__private_IsEnabledFallback @ 140001ee0 =====

void Feature_Servicing_ApplockerPickBestClaim__private_IsEnabledFallback
               (ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_Servicing_ApplockerPickBestClaim__private_descriptor);
  return;
}



===== RtlStringCbPrintfW @ 140001efc =====

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



===== SmartlockerGetSubSessionID @ 140001f78 =====

undefined8 SmartlockerGetSubSessionID(undefined8 param_1,undefined8 *param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  uint local_res20 [2];
  longlong local_28;
  longlong local_20;
  longlong local_18 [2];
  
  local_28 = 0;
  local_20 = 0;
  local_res20[0] = 0;
  local_18[0] = 0;
  uVar2 = PsGetProcessId();
  AiOpenTokenByProcessId(uVar2,&local_28);
  uVar2 = SmartlockerOriginClaimProcessTokenCheck
                    (local_28,'\0',(undefined1 *)0x0,local_res20,&local_20,local_18);
  if (((int)uVar2 < 0) && (((int)uVar2 != -0x3fffffff || (local_20 == 0)))) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined8 *)(local_20 + 0x28);
    uVar1 = *(uint *)(local_20 + 8);
    *param_2 = *(undefined8 *)(local_20 + 0x20);
    param_2[1] = uVar2;
    uVar2 = 1;
    if (((uVar1 & 0xfffffffa) == 0) && (uVar1 != 5)) {
      *param_3 = 1;
    }
  }
  if (local_18[0] != 0) {
    ExFreePoolWithTag(local_18[0],0x41746d73);
  }
  if (local_28 != 0) {
    ZwClose();
  }
  return uVar2;
}



===== SmartlockerGetValidEA @ 140002060 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SmartlockerGetValidEA
              (undefined8 param_1,longlong param_2,uint *param_3,longlong *param_4,
              undefined8 *param_5)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  longlong lVar8;
  uint *puVar9;
  undefined1 auStack_178 [32];
  undefined4 *local_158;
  undefined4 local_150;
  undefined8 local_148;
  undefined1 local_140;
  undefined4 *local_138;
  undefined4 *local_128;
  undefined4 local_120 [2];
  longlong local_118;
  longlong local_110;
  longlong *local_108;
  uint *local_100;
  undefined8 *local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined4 local_c8 [28];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_178;
  *param_4 = 0;
  local_128 = local_c8;
  *param_3 = 0;
  lVar8 = 0;
  local_f8 = param_5;
  uVar4 = 0;
  puVar7 = (uint *)0x0;
  *param_5 = 0;
  puVar9 = (uint *)0x0;
  local_120[0] = 0;
  local_118 = 0;
  local_f0 = 0;
  local_e0 = 0;
  local_d8 = 0;
  local_110 = param_2;
  local_108 = param_4;
  local_100 = param_3;
  local_e8 = param_1;
  puVar3 = (uint *)AiAlloc(0x308);
  if (puVar3 == (uint *)0x0) {
    return -0x3fffffe9;
  }
  AiAddEaToQueryBuffer("$Kernel.Smartlocker.OriginClaim",&local_118,local_c8,(longlong *)&local_128)
  ;
  AiAddEaToQueryBuffer("$Kernel.Smartlocker.Hash",&local_118,local_128,(longlong *)&local_128);
  AiAddEaToQueryBuffer
            ("$Kernel.Purge.Smartlocker.Valid",&local_118,local_128,(longlong *)&local_128);
  local_138 = local_120;
  local_140 = 0;
  local_158 = local_c8;
  local_148 = 0;
  local_150 = 0x70;
  iVar1 = FsRtlQueryKernelEaFile(param_1,puVar3,0x308,0);
  if (iVar1 < 0) goto LAB_1400022dd;
  puVar6 = puVar3;
  do {
    iVar2 = _stricmp((char *)(puVar6 + 2),"$Kernel.Smartlocker.OriginClaim");
    if (iVar2 == 0) {
      uVar4 = (uint)*(ushort *)((longlong)puVar6 + 6);
      if (uVar4 < 0x40) {
        lVar8 = 0;
        uVar4 = 0;
      }
      else {
        lVar8 = (ulonglong)*(byte *)((longlong)puVar6 + 5) + 9 + (longlong)puVar6;
      }
    }
    else {
      iVar2 = _stricmp((char *)(puVar6 + 2),"$Kernel.Smartlocker.Hash");
      if (iVar2 == 0) {
        uVar5 = *(byte *)((longlong)puVar6 + 5) + 9 + (uint)*(ushort *)((longlong)puVar6 + 6);
        if (((0x2b < uVar5) && (uVar5 == puVar6[10] + 0x2c)) && (puVar6[9] == 0x31484d53)) {
          puVar7 = puVar6;
        }
      }
      else {
        iVar2 = _stricmp((char *)(puVar6 + 2),"$Kernel.Purge.Smartlocker.Valid");
        if (((iVar2 == 0) &&
            ((uint)*(ushort *)((longlong)puVar6 + 6) + (uint)*(byte *)((longlong)puVar6 + 5) == 0x23
            )) && (puVar6[10] == 0x31564d53)) {
          puVar9 = puVar6;
        }
      }
    }
  } while ((*puVar6 != 0) &&
          (puVar6 = (uint *)((longlong)puVar6 + (ulonglong)*puVar6), puVar6 != (uint *)0x0));
  if (lVar8 != 0) {
    if (puVar9 != (uint *)0x0) {
      *local_108 = lVar8;
      *local_100 = uVar4;
      *local_f8 = puVar3;
      puVar3 = (uint *)0x0;
      if ((puVar7 == (uint *)0x0) && (*(int *)(lVar8 + 8) != 2)) {
        AiSmartHashImageFile((longlong)&local_f0,local_110,0);
      }
      goto LAB_1400022dd;
    }
    if (puVar7 != (uint *)0x0) {
      iVar1 = AiSmartHashImageFile((longlong)&local_f0,local_110,(longlong)puVar7);
      if (-1 < iVar1) {
        *local_108 = lVar8;
        *local_100 = uVar4;
        *local_f8 = puVar3;
        puVar3 = (uint *)0x0;
      }
      goto LAB_1400022dd;
    }
  }
  iVar1 = -0x3ffffddb;
LAB_1400022dd:
  AiFree(puVar3);
  return iVar1;
}



===== SrpGetPluginPolicy @ 140002310 =====

undefined8
SrpGetPluginPolicy(longlong param_1,longlong *param_2,undefined8 param_3,longlong *param_4,
                  undefined4 *param_5)

{
  longlong lVar1;
  undefined8 uVar2;
  uint uVar3;
  longlong *plVar4;
  
  uVar3 = 0;
  if ((-1 < *(int *)(param_1 + 0xd0)) && (lVar1 = *(longlong *)(param_1 + 0xd8), lVar1 != 0)) {
    plVar4 = (longlong *)((ulonglong)*(uint *)(lVar1 + 8) + lVar1);
    if (*(uint *)(lVar1 + 0xc) != 0) {
      do {
        if ((*plVar4 == 0x4e8001e33b207045) && (plVar4[1] == 0x36f6d035fb531a99)) {
          uVar2 = SrppGetPluginPolicy(param_1,param_2,(longlong)plVar4,param_4,param_5);
          return uVar2;
        }
        uVar3 = uVar3 + 1;
        plVar4 = (longlong *)((longlong)plVar4 + 0x24);
      } while (uVar3 < *(uint *)(lVar1 + 0xc));
    }
  }
  return 0xc0000225;
}



===== SrppGetPluginPolicy @ 14000238c =====

undefined8
SrppGetPluginPolicy(longlong param_1,longlong *param_2,longlong param_3,longlong *param_4,
                   undefined4 *param_5)

{
  undefined8 *puVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  longlong lVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong *plVar10;
  longlong lVar11;
  
  if ((-1 < *(int *)(param_1 + 0xd0)) && (lVar3 = *(longlong *)(param_1 + 0xd8), lVar3 != 0)) {
    uVar7 = 0;
    uVar2 = *(uint *)(lVar3 + 0x18);
    plVar10 = (longlong *)
              ((ulonglong)*(uint *)(lVar3 + 0x10) +
              (ulonglong)*(uint *)(param_3 + 0x1c) * 0x1c + lVar3);
    if (*(uint *)(param_3 + 0x20) != 0) {
      do {
        if ((*plVar10 == *param_2) && (plVar10[1] == param_2[1])) {
          if (*(uint *)(plVar10 + 3) != 0) {
            lVar6 = AiAlloc((ulonglong)*(uint *)(plVar10 + 3) << 5);
            if (lVar6 == 0) {
              return 0xc0000017;
            }
            uVar7 = 0;
            if ((int)plVar10[3] != 0) {
              do {
                uVar8 = *(int *)((longlong)plVar10 + 0x14) + uVar7;
                lVar11 = (ulonglong)uVar7 * 0x20;
                uVar9 = (ulonglong)uVar7;
                uVar7 = uVar7 + 1;
                *(undefined8 *)(lVar11 + 0x18 + lVar6) =
                     *(undefined8 *)(*(longlong *)(param_1 + 0xe0) + 0x28 + (ulonglong)uVar8 * 0x30)
                ;
                puVar1 = (undefined8 *)
                         ((ulonglong)uVar2 + lVar3 +
                         (*(uint *)((longlong)plVar10 + 0x14) + uVar9) * 0x10);
                uVar4 = *puVar1;
                uVar5 = puVar1[1];
                *(undefined4 *)(lVar11 + 0x10 + lVar6) = 0;
                *(undefined4 *)(lVar11 + 0x14 + lVar6) = 0;
                *(undefined8 *)(lVar11 + lVar6) = uVar4;
                ((undefined8 *)(lVar11 + lVar6))[1] = uVar5;
              } while (uVar7 < *(uint *)(plVar10 + 3));
            }
            *param_4 = lVar6;
            *param_5 = (int)plVar10[3];
          }
          return 0;
        }
        uVar7 = uVar7 + 1;
        plVar10 = (longlong *)((longlong)plVar10 + 0x1c);
      } while (uVar7 < *(uint *)(param_3 + 0x20));
    }
  }
  return 0xc0000225;
}



===== RtlStringCchPrintfW @ 1400024b4 =====

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



===== WPP_SF_Z @ 140002530 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Z(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  
  if (param_4 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_4;
    if (*param_4 != L'\0') {
      pwVar1 = *(wchar_t **)(param_4 + 4);
      goto LAB_14000255d;
    }
  }
  pwVar1 = L"NULL";
LAB_14000255d:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,2,pwVar1,wVar2,0);
  return;
}



===== WPP_SF_ZZ @ 1400025b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ZZ(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4,
              wchar_t *param_5)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  wchar_t *pwVar3;
  wchar_t wVar4;
  
  pwVar3 = L"NULL";
  wVar2 = L'\b';
  if (param_5 == (wchar_t *)0x0) {
    wVar4 = L'\b';
  }
  else {
    wVar4 = *param_5;
    if (*param_5 != L'\0') {
      pwVar1 = *(wchar_t **)(param_5 + 4);
      goto LAB_1400025fd;
    }
  }
  pwVar1 = L"NULL";
LAB_1400025fd:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  if ((param_4 != (wchar_t *)0x0) && (wVar2 = *param_4, *param_4 != L'\0')) {
    pwVar3 = *(wchar_t **)(param_4 + 4);
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,param_4,2,pwVar3,wVar2,param_5,2,pwVar1,wVar4,0);
  return;
}



===== WPP_SF_DD @ 140002690 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ba82aeedd69c3fe8448d5535e4644288_Traceguids,0xc,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_ZDD @ 1400026e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ZDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4,
               undefined1 param_5,undefined1 param_6)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  
  if (param_4 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *param_4;
    if (*param_4 != L'\0') {
      pwVar2 = *(wchar_t **)(param_4 + 4);
      goto LAB_140002711;
    }
  }
  pwVar2 = L"NULL";
LAB_140002711:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ba82aeedd69c3fe8448d5535e4644288_Traceguids,param_2,param_4,2,pwVar2,
             wVar1,&param_5,4,&param_6,4,0);
  return;
}



===== AiQueryPerformanceCounter @ 140002790 =====

undefined8 AiQueryPerformanceCounter(undefined8 *param_1,char param_2)

{
  undefined8 uVar1;
  
  if (param_2 == '\0') {
    if (param_1 != (undefined8 *)0x0) {
      *param_1 = 1;
    }
    uVar1 = 0;
  }
  else {
    uVar1 = KeQueryPerformanceCounter();
  }
  return uVar1;
}



===== AiResetPerfTimeCounter @ 1400027c8 =====

undefined8 AiResetPerfTimeCounter(undefined8 *param_1)

{
  undefined8 uVar1;
  
  LOCK();
  uVar1 = param_1[1];
  param_1[1] = 0;
  UNLOCK();
  LOCK();
  *param_1 = 0;
  UNLOCK();
  return uVar1;
}



===== AiUpdatePerfTime @ 1400027dc =====

longlong AiUpdatePerfTime(longlong *param_1,longlong param_2,char param_3)

{
  longlong lVar1;
  longlong local_res20;
  
  if (param_3 == '\0') {
    local_res20 = 0;
  }
  else {
    local_res20 = 0;
    lVar1 = KeQueryPerformanceCounter(&local_res20);
    local_res20 = ((lVar1 - param_2) * 1000000) / local_res20;
    if (param_1 != (longlong *)0x0) {
      LOCK();
      *param_1 = *param_1 + local_res20;
      UNLOCK();
      LOCK();
      param_1[1] = param_1[1] + 1;
      UNLOCK();
    }
  }
  return local_res20;
}



===== AiGetPublisherCache @ 140002840 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int AiGetPublisherCache(undefined8 param_1,undefined8 param_2,longlong param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_a8 [32];
  undefined4 *local_88;
  undefined4 local_80;
  undefined8 local_78;
  undefined1 local_70;
  uint *local_68;
  uint local_58 [2];
  longlong local_50;
  undefined4 local_48 [10];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_a8;
  local_58[0] = 0;
  local_50 = 0;
  AiAddEaToQueryBuffer("$KERNEL.PURGE.APPID.SIGNERINFO",&local_50,local_48,&local_50);
  local_68 = local_58;
  local_70 = 0;
  local_88 = local_48;
  local_78 = 0;
  local_80 = 0x27;
  iVar1 = FsRtlQueryKernelEaFile(param_1,param_3,0x1000,0);
  if (-1 < iVar1) {
    uVar2 = *(byte *)(param_3 + 5) + 9 + (uint)*(ushort *)(param_3 + 6);
    if ((((uVar2 < local_58[0]) || (uVar2 < 0x30)) || (*(int *)(param_3 + 0x28) != 0x33444941)) ||
       ((*(uint *)(param_3 + 0x2c) & 0xfffffffe) != 0)) {
      iVar1 = -0x3ffff6f5;
    }
    else {
      *param_4 = local_58[0];
    }
  }
  return iVar1;
}



===== AipCertDeleteRoutine @ 140002930 =====

void AipCertDeleteRoutine(longlong param_1)

{
  AipFreeCert(param_1);
  return;
}



===== AiGetOriginalFileName @ 140002948 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int AiGetOriginalFileName(undefined8 param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined1 auStack_58 [32];
  undefined8 *local_38;
  int local_30 [6];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_38 = (undefined8 *)0x0;
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[4] = 0;
  local_30[5] = 0;
  local_30[2] = 1;
  local_30[3] = 0;
  iVar3 = AipAllocateImageContext(param_1,param_1,0,&local_38);
  puVar2 = local_38;
  if (-1 < iVar3) {
    iVar3 = AipCollectImageProperties(local_38,local_30,0,(longlong *)0x0);
    if (-1 < iVar3) {
      uVar1 = puVar2[0x33];
      *param_2 = puVar2[0x32];
      param_2[1] = uVar1;
      puVar2[0x32] = 0;
      puVar2[0x33] = 0;
    }
  }
  AipFreeImageContext((longlong)puVar2);
  return iVar3;
}



===== RtlStringCbPrintfA @ 1400029fc =====

undefined8 RtlStringCbPrintfA(char *param_1,longlong param_2,char *param_3,undefined8 param_4)

{
  ulonglong _Count;
  int iVar1;
  undefined8 uVar2;
  undefined8 local_res20;
  
  if (param_2 - 1U < 0x7fffffff) {
    _Count = param_2 - 1;
    uVar2 = 0;
    local_res20 = param_4;
    iVar1 = _vsnprintf(param_1,_Count,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      param_1[_Count] = '\0';
      uVar2 = 0x80000005;
    }
    else if ((longlong)iVar1 == _Count) {
      param_1[_Count] = '\0';
    }
  }
  else {
    uVar2 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = '\0';
    }
  }
  return uVar2;
}



===== WPP_SF_DDDD @ 140002a70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_613678cfb9bc3eb3d7e100c284ea9323_Traceguids,param_2,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_s @ 140002ae0 =====

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
            (param_1,0x2b,&WPP_613678cfb9bc3eb3d7e100c284ea9323_Traceguids,0xb,param_4,lVar2,0);
  return;
}



===== AipkFreeAppxInMemoryCache @ 140002b4c =====

void AipkFreeAppxInMemoryCache(void)

{
  void *pvVar1;
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
  if (AipAppxInMemoryCacheInitialized != '\0') {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(&AipAppxInMemoryCache,0);
    if (DAT_1400184b8 != 0) {
      RtlInitEnumerationHashTable(DAT_1400184b8,&local_38);
      while( true ) {
        pvVar1 = (void *)RtlEnumerateEntryHashTable(DAT_1400184b8,&local_38);
        if (pvVar1 == (void *)0x0) break;
        RtlRemoveEntryHashTable(DAT_1400184b8,pvVar1,0);
        AiFree(pvVar1);
      }
      RtlEndEnumerationHashTable(DAT_1400184b8,&local_38);
      RtlDeleteHashTable(DAT_1400184b8);
      DAT_1400184b8 = 0;
    }
    ExReleasePushLockExclusiveEx(&AipAppxInMemoryCache,0);
    KeLeaveCriticalRegion();
  }
  return;
}



===== AppModelPolicy_Kernel_GetPolicy @ 140002c54 =====

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
    puVar3 = &DAT_14000c1e8;
  }
  else if ((local_res20 & 8) == 0) {
    if ((uVar2 >> 0x10 & 1) == 0) {
      if ((uVar2 >> 0xe & 1) == 0) {
        if ((uVar2 & 4) == 0) {
          if ((uVar2 >> 10 & 1) == 0) {
            if ((uVar2 >> 0xb & 1) == 0) {
              if ((uVar2 & 0x40) == 0) {
                if ((uVar2 & 8) == 0) {
                  puVar3 = &DAT_14000c208;
                  if ((uVar2 >> 0x12 & 1) == 0) {
                    puVar3 = &DAT_14000c1e0;
                  }
                }
                else {
                  puVar3 = &DAT_14000c1ec;
                }
              }
              else {
                puVar3 = &DAT_14000c1f0;
              }
            }
            else {
              puVar3 = &DAT_14000c1f8;
            }
          }
          else {
            puVar3 = &DAT_14000c1f4;
          }
        }
        else {
          puVar3 = &DAT_14000c1e4;
        }
      }
      else {
        puVar3 = &DAT_14000c204;
      }
    }
    else {
      puVar3 = &DAT_14000c1fc;
    }
  }
  else {
    puVar3 = &DAT_14000c200;
  }
  *param_3 = *puVar3;
  Feature_PackagedComElevationSupport__private_IsEnabledNoReportingNoInline();
  return iVar1;
}



===== Feature_PackagedComElevationSupport__private_IsEnabledFallback @ 140002d78 =====

void Feature_PackagedComElevationSupport__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_PackagedComElevationSupport__private_descriptor);
  return;
}



===== Feature_PackagedComElevationSupport__private_IsEnabledNoReportingNoInline @ 140002d94 =====

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



===== AiRegCreateKey @ 140002dcc =====

void AiRegCreateKey(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38 = 0x30;
  local_20 = 0x240;
  local_18 = 0;
  uStack_10 = 0;
  local_30 = param_1;
  local_28 = param_2;
  ZwCreateKey(param_4,0xf003f,&local_38,0,0,0,0);
  return;
}



===== AiRegReadBinaryValue @ 140002e30 =====

int AiRegReadBinaryValue
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4,
              undefined8 *param_5)

{
  undefined4 uVar1;
  ulonglong uVar2;
  int iVar3;
  void *pvVar4;
  void *_Dst;
  undefined8 local_res18;
  longlong local_18 [2];
  
  local_18[0] = 0;
  local_res18 = CONCAT44((int)((ulonglong)param_3 >> 0x20),0x810);
  pvVar4 = (void *)0x0;
  iVar3 = AiRegOpenKey(param_1,param_2,0x20019,local_18);
  if (-1 < iVar3) {
    do {
      uVar2 = local_res18;
      uVar1 = (undefined4)local_res18;
      AiFree(pvVar4);
      pvVar4 = (void *)AiAlloc(uVar2 & 0xffffffff);
      if (pvVar4 == (void *)0x0) goto LAB_140002f19;
      iVar3 = ZwQueryValueKey(local_18[0],&DAT_140008670,2,pvVar4,uVar1,&local_res18);
    } while (iVar3 == -0x7ffffffb);
    if (-1 < iVar3) {
      if (*(int *)((longlong)pvVar4 + 4) == 3) {
        if (*(uint *)((longlong)pvVar4 + 8) == 0) {
          iVar3 = -0x3ffffddb;
        }
        else {
          _Dst = (void *)AiAlloc((ulonglong)*(uint *)((longlong)pvVar4 + 8));
          if (_Dst == (void *)0x0) {
LAB_140002f19:
            iVar3 = -0x3fffffe9;
          }
          else {
            memmove(_Dst,(void *)((longlong)pvVar4 + 0xc),(ulonglong)*(uint *)((longlong)pvVar4 + 8)
                   );
            *param_5 = _Dst;
            *param_4 = *(undefined4 *)((longlong)pvVar4 + 8);
          }
        }
      }
      else {
        iVar3 = -0x3fffffdc;
      }
    }
  }
  AiFree(pvVar4);
  if (local_18[0] != 0) {
    ZwClose();
  }
  return iVar3;
}



===== AiRegReadQwordValue @ 140002f5c =====

int AiRegReadQwordValue(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4
                       )

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  uint local_18 [2];
  longlong local_10;
  
  local_10 = 0;
  local_18[0] = 0x30;
  pvVar3 = (void *)0x0;
  iVar2 = AiRegOpenKey(param_1,param_2,0x20019,&local_10);
  if (-1 < iVar2) {
    do {
      uVar1 = local_18[0];
      AiFree(pvVar3);
      pvVar3 = (void *)AiAlloc((ulonglong)uVar1);
      if (pvVar3 == (void *)0x0) {
        iVar2 = -0x3fffffe9;
        goto LAB_14000300d;
      }
      iVar2 = ZwQueryValueKey(local_10,param_3,2,pvVar3,uVar1,local_18);
    } while (iVar2 == -0x7ffffffb);
    if (-1 < iVar2) {
      if ((*(int *)((longlong)pvVar3 + 4) == 0xb) && (*(int *)((longlong)pvVar3 + 8) == 8)) {
        *param_4 = *(undefined8 *)((longlong)pvVar3 + 0xc);
      }
      else {
        iVar2 = -0x3fffffdc;
      }
    }
  }
LAB_14000300d:
  AiFree(pvVar3);
  if (local_10 != 0) {
    ZwClose();
  }
  return iVar2;
}



===== AiSetAttributes @ 14000304c =====

void AiSetAttributes(uint *param_1,uint param_2,char param_3)

{
  *param_1 = *param_1 | (-(uint)(param_3 != '\0') & 7) + 0x19 & param_2;
  return;
}



===== WPP_SF_d @ 140003064 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_d(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_0961c2f37d1b3ad2f2ca69bd50809778_Traceguids,param_2,local_res20,4,0);
  return;
}



===== AiGetHashInfoFromCache @ 1400030ac =====

undefined8 AiGetHashInfoFromCache(longlong param_1,uint param_2,void *param_3,uint *param_4)

{
  uint uVar1;
  uint *puVar2;
  ulonglong uVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  
  if ((0x37 < param_2) && (*(int *)(param_1 + 0x28) == 0x31444941)) {
    uVar3 = 0;
    iVar4 = 0;
    uVar5 = 0;
    lVar6 = 3;
    puVar2 = param_4;
    do {
      uVar1 = *(uint *)((param_1 - (longlong)param_4) + 0x2c + (longlong)puVar2);
      iVar4 = iVar4 + uVar1;
      *puVar2 = uVar1;
      if (0x20 < uVar1) {
        return 0xfffffffe;
      }
      uVar5 = uVar5 + 1;
      puVar2 = puVar2 + 1;
    } while (uVar5 < 3);
    if (param_2 == iVar4 + 0x38U) {
      do {
        memmove(param_3,(void *)(uVar3 + 0x38 + param_1),(ulonglong)*param_4);
        uVar3 = (ulonglong)((int)uVar3 + *param_4);
        param_3 = (void *)((longlong)param_3 + 0x20);
        param_4 = param_4 + 1;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
      return 0;
    }
  }
  return 0xfffffffe;
}



===== AiSetHashInfoInCache @ 140003164 =====

void AiSetHashInfoInCache(undefined8 param_1,uint *param_2,void *param_3)

{
  char *pcVar1;
  undefined8 *puVar2;
  uint *puVar3;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  longlong lVar8;
  
  uVar4 = 0;
  puVar2 = (undefined8 *)0x0;
  uVar7 = 0;
  lVar8 = 3;
  puVar3 = param_2;
  uVar6 = 0;
  do {
    uVar5 = *puVar3 + uVar6;
    if (uVar5 < uVar6) goto LAB_140003274;
    uVar7 = uVar7 + 1;
    puVar3 = puVar3 + 1;
    uVar6 = uVar5;
  } while (uVar7 < 3);
  uVar6 = uVar5 + 0x38;
  if ((uVar5 <= uVar6) && (uVar6 < 0x161)) {
    puVar2 = (undefined8 *)AiAlloc((ulonglong)uVar6);
    if (puVar2 != (undefined8 *)0x0) {
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      puVar2[4] = 0;
      puVar2[5] = 0;
      puVar2[6] = 0;
      *(undefined4 *)(puVar2 + 7) = 0;
      *(undefined1 *)((longlong)puVar2 + 5) = 0x1c;
      *(short *)((longlong)puVar2 + 6) = (short)uVar6 + -0x25;
      pcVar1 = (char *)(puVar2 + 1);
      pcVar1[0] = '$';
      pcVar1[1] = 'K';
      pcVar1[2] = 'E';
      pcVar1[3] = 'R';
      pcVar1[4] = 'N';
      pcVar1[5] = 'E';
      pcVar1[6] = 'L';
      pcVar1[7] = '.';
      pcVar1 = (char *)(puVar2 + 2);
      pcVar1[0] = 'P';
      pcVar1[1] = 'U';
      pcVar1[2] = 'R';
      pcVar1[3] = 'G';
      pcVar1[4] = 'E';
      pcVar1[5] = '.';
      pcVar1[6] = 'A';
      pcVar1[7] = 'P';
      puVar2[3] = 0x485341482e444950;
      *(undefined4 *)(puVar2 + 4) = 0x4f464e49;
      *(undefined1 *)((longlong)puVar2 + 0x24) = 0;
      *(undefined4 *)(puVar2 + 5) = 0x31444941;
      *(undefined8 *)((longlong)puVar2 + 0x2c) = *(undefined8 *)param_2;
      *(uint *)((longlong)puVar2 + 0x34) = param_2[2];
      do {
        memmove((void *)(uVar4 + 0x38 + (longlong)puVar2),param_3,(ulonglong)*param_2);
        uVar4 = (ulonglong)((int)uVar4 + *param_2);
        param_3 = (void *)((longlong)param_3 + 0x20);
        param_2 = param_2 + 1;
        lVar8 = lVar8 + -1;
      } while (lVar8 != 0);
      AiSetCacheEaFile(param_1,(longlong)puVar2);
    }
  }
LAB_140003274:
  AiFree(puVar2);
  return;
}



===== AipQueryFileHandle @ 1400032b0 =====

void AipQueryFileHandle(undefined8 param_1,undefined8 param_2)

{
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  ZwQueryInformationFile(0,&local_18,param_2,0x18,5);
  return;
}



===== AipReadFileHandle @ 1400032f0 =====

ulonglong AipReadFileHandle(undefined8 param_1,undefined8 param_2,undefined4 param_3,
                           undefined8 param_4)

{
  ulonglong uVar1;
  ulonglong local_18 [2];
  
  local_18[0] = 0;
  local_18[1] = 0;
  uVar1 = ZwReadFile(0,0,0,0,local_18,param_4,param_3,param_2,0);
  if ((int)uVar1 == 0x103) {
    ZwWaitForSingleObject(param_1,0,0);
    uVar1 = local_18[0] & 0xffffffff;
  }
  return uVar1;
}



===== AppHashComputeFileHashes @ 14000335c =====

void AppHashComputeFileHashes(undefined8 param_1,longlong param_2,void *param_3,longlong param_4)

{
  AppHashComputeFileHashesInternal
            (param_1,&PTR_AipQueryFileHandle_140008120,param_2,param_3,param_4);
  return;
}



===== AppHashComputeFileHashesInternal @ 140003384 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS AppHashComputeFileHashesInternal
                   (undefined8 param_1,undefined8 *param_2,longlong param_3,void *param_4,
                   longlong param_5)

{
  ushort uVar1;
  NTSTATUS NVar2;
  longlong lVar3;
  longlong lVar4;
  BCRYPT_HASH_HANDLE *ppvVar5;
  undefined4 *puVar6;
  ulonglong uVar7;
  longlong lVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined1 auStack_f8 [32];
  NTSTATUS local_d8;
  longlong local_d0;
  void *local_c8;
  longlong local_c0;
  undefined8 *local_b8;
  undefined8 local_b0;
  BCRYPT_HASH_HANDLE local_a8 [2];
  undefined4 uStack_98;
  ushort auStack_94 [2];
  longlong alStack_90 [9];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_f8;
  NVar2 = 0;
  local_d0 = param_5;
  local_c8 = param_4;
  local_c0 = param_3;
  local_b8 = param_2;
  local_b0 = param_1;
  memset(local_a8,0,0x60);
  memset(param_4,0,0x60);
  puVar6 = &DAT_14000c550;
  uVar7 = 0;
  lVar4 = 3;
  uVar10 = 0;
  lVar8 = 0;
  lVar3 = local_d0;
  do {
    if (*(int *)(lVar8 + param_3) == 0) {
      uVar9 = 0;
    }
    else {
      ppvVar5 = local_a8 + uVar7 * 4;
      NVar2 = AppHashInitHash((BCRYPT_HANDLE)(&AppHashAlgHandle)[(int)puVar6[-1]],ppvVar5);
      local_d8 = NVar2;
      if (NVar2 < 0) {
        AppHashDestroyHash(ppvVar5);
        goto LAB_1400034c5;
      }
      uVar1 = auStack_94[uVar7 * 0x10];
      if (0x20 < uVar1) {
        AppHashDestroyHash(ppvVar5);
        local_d8 = -0x3fffffdd;
        goto LAB_1400034c5;
      }
      *(undefined4 *)(local_a8 + uVar7 * 4 + 2) = *puVar6;
      alStack_90[uVar7 * 4] = (longlong)(uVar10 * 0x20 + (longlong)local_c8);
      uVar7 = (ulonglong)((int)uVar7 + 1);
      uVar9 = (uint)uVar1;
      lVar3 = local_d0;
      param_3 = local_c0;
    }
    *(uint *)(lVar8 + lVar3) = uVar9;
    uVar9 = (int)uVar10 + 1;
    uVar10 = (ulonglong)uVar9;
    lVar8 = lVar8 + 4;
    puVar6 = puVar6 + 3;
  } while (uVar9 < 3);
  local_d8 = NVar2;
  if (-1 < NVar2) {
    local_d8 = AppHashComputeImageHashInternal(local_b0,local_b8,(uint)uVar7,local_a8);
  }
LAB_1400034c5:
  ppvVar5 = local_a8;
  do {
    AppHashDestroyHash(ppvVar5);
    ppvVar5 = ppvVar5 + 4;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  return local_d8;
}



===== AiVerifyFile @ 140003534 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint AiVerifyFile(undefined8 param_1,undefined4 param_2,longlong param_3,undefined8 *param_4)

{
  uint uVar1;
  undefined8 uVar2;
  undefined1 auStack_148 [32];
  undefined8 local_128;
  undefined4 local_120;
  uint *local_118;
  longlong local_110;
  longlong local_108;
  longlong local_100;
  longlong local_f8;
  longlong local_f0;
  longlong local_e8;
  undefined8 *local_e0;
  uint local_d8 [2];
  undefined8 *local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  _RPC_ASYNC_STATE local_a8;
  
  local_a8.Reserved[2] = __security_cookie ^ (ulonglong)auStack_148;
  local_d8[0] = 0xc0000001;
  local_d0 = param_4;
  memset(&local_a8,0,0x58);
  local_c8 = 0;
  uStack_c0 = 0;
  local_b8 = 0;
  *param_4 = 0;
  uVar2 = AipInitRpc(&local_a8,(PFN_RPCNOTIFICATION_ROUTINE)&local_c8);
  uVar1 = (uint)uVar2;
  if (-1 < (int)(uint)uVar2) {
    local_e8 = param_3 + 0x28;
    local_f0 = param_3 + 0x20;
    local_f8 = param_3 + 0x18;
    local_100 = param_3 + 0x10;
    local_108 = param_3 + 8;
    local_118 = local_d8;
    local_128 = param_1;
    local_120 = param_2;
    local_110 = param_3;
    local_e0 = param_4;
    Ndr64AsyncClientCall((MIDL_STUBLESS_PROXY_INFO *)&PTR_PTR_140008aa0,0,(void *)0x0);
    uVar1 = AipCompleteRpc(0,&local_a8,&local_c8);
    if (-1 < (int)uVar1) {
      uVar1 = local_d8[0];
    }
  }
  if (((int)uVar1 < 0) && ((void *)*param_4 != (void *)0x0)) {
    AiFree((void *)*param_4);
    *param_4 = 0;
  }
  return uVar1;
}



===== ClientAppIDRpcVerifyPackageMoniker @ 140003694 =====

void ClientAppIDRpcVerifyPackageMoniker(undefined8 param_1)

{
  Ndr64AsyncClientCall((MIDL_STUBLESS_PROXY_INFO *)&PTR_PTR_140008aa0,1,(void *)0x0);
  return;
}



===== SymCryptFatalEnvWindowsKernelmodeWin8_1nLater @ 14000370c =====

void SymCryptFatalEnvWindowsKernelmodeWin8_1nLater(undefined4 param_1)

{
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0x171,param_1,0,0,0);
}



===== SymCryptDetectCpuFeaturesByCpuid @ 140003738 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00014000385a) */
/* WARNING: Removing unreachable block (ram,0x00014000382c) */
/* WARNING: Removing unreachable block (ram,0x00014000380b) */
/* WARNING: Removing unreachable block (ram,0x0001400037d2) */
/* WARNING: Removing unreachable block (ram,0x000140003773) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SymCryptDetectCpuFeaturesByCpuid(void)

{
  byte bVar1;
  uint *puVar2;
  uint *puVar3;
  longlong lVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  byte in_XCR0;
  uint local_28 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)local_28;
  uVar8 = 0;
  pbVar9 = &DAT_14000ca02;
  g_SymCryptCpuFeaturesNotPresent = 0xffffc020;
  uVar11 = 0;
  puVar2 = (uint *)cpuid_basic_info(0);
  local_28[0] = *puVar2;
  local_28[1] = puVar2[1];
  local_28[2] = puVar2[3];
  local_28[3] = puVar2[2];
  do {
    bVar1 = pbVar9[-2];
    uVar10 = (uint)bVar1;
    if (uVar10 != uVar8) {
      if (uVar10 == 0) {
        puVar3 = (uint *)cpuid_basic_info(0);
      }
      else if (uVar10 == 1) {
        puVar3 = (uint *)cpuid_Version_info(1);
      }
      else if (uVar10 == 2) {
        puVar3 = (uint *)cpuid_cache_tlb_info(2);
      }
      else if (uVar10 == 3) {
        puVar3 = (uint *)cpuid_serial_info(3);
      }
      else if (uVar10 == 4) {
        puVar3 = (uint *)cpuid_Deterministic_Cache_Parameters_info(4);
      }
      else if (uVar10 == 5) {
        puVar3 = (uint *)cpuid_MONITOR_MWAIT_Features_info(5);
      }
      else if (uVar10 == 6) {
        puVar3 = (uint *)cpuid_Thermal_Power_Management_info(6);
      }
      else if (uVar10 == 7) {
        puVar3 = (uint *)cpuid_Extended_Feature_Enumeration_info(7);
      }
      else if (uVar10 == 9) {
        puVar3 = (uint *)cpuid_Direct_Cache_Access_info(9);
      }
      else if (uVar10 == 10) {
        puVar3 = (uint *)cpuid_Architectural_Performance_Monitoring_info(10);
      }
      else if (uVar10 == 0xb) {
        puVar3 = (uint *)cpuid_Extended_Topology_info(0xb);
      }
      else if (uVar10 == 0xd) {
        puVar3 = (uint *)cpuid_Processor_Extended_States_info(0xd);
      }
      else if (uVar10 == 0xf) {
        puVar3 = (uint *)cpuid_Quality_of_Service_info(0xf);
      }
      else if (uVar10 == 0x80000002) {
        puVar3 = (uint *)cpuid_brand_part1_info(0x80000002);
      }
      else if (uVar10 == 0x80000003) {
        puVar3 = (uint *)cpuid_brand_part2_info(0x80000003);
      }
      else if (uVar10 == 0x80000004) {
        puVar3 = (uint *)cpuid_brand_part3_info(0x80000004);
      }
      else {
        puVar3 = (uint *)cpuid(uVar10);
      }
      local_28[0] = *puVar3;
      local_28[1] = puVar3[1];
      local_28[2] = puVar3[3];
      local_28[3] = puVar3[2];
      uVar8 = (uint)bVar1;
    }
    if (((int)*puVar2 < (int)(uint)bVar1) || ((local_28[pbVar9[-1]] >> (*pbVar9 & 0x1f) & 1) == 0))
    {
      g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | *(uint *)(pbVar9 + 2);
    }
    uVar11 = uVar11 + 1;
    pbVar9 = pbVar9 + 8;
  } while (uVar11 < 0x14);
  lVar4 = cpuid_Version_info(1);
  if ((*(uint *)(lVar4 + 0xc) >> 0x1b & 1) == 0) {
LAB_1400037f8:
    g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | 0x10;
  }
  else {
    uVar7 = xinuse(0);
    bVar1 = in_XCR0 & (byte)uVar7;
    if ((bVar1 & 6) != 6) goto LAB_1400037f8;
    if ((bVar1 & 0xe0) == 0xe0) goto LAB_140003801;
  }
  g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | 0x1000;
LAB_140003801:
  if ((g_SymCryptCpuFeaturesNotPresent & 4) == 0) {
    lVar4 = cpuid_basic_info(0);
    if (((*(int *)(lVar4 + 4) == 0x68747541) && (*(int *)(lVar4 + 0xc) == 0x444d4163)) &&
       (*(int *)(lVar4 + 8) == 0x69746e65)) {
      piVar5 = (int *)cpuid_Version_info(1);
      uVar8 = *piVar5 >> 8 & 0xf;
      if ((uVar8 < 0xf) || ((*piVar5 >> 0x14 & 0xffU) + uVar8 < 0x15)) {
        g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | 4;
      }
    }
  }
  puVar6 = (undefined4 *)cpuid_Version_info(1);
  _g_SymCryptCpuid1 = *puVar6;
  _DAT_140018574 = puVar6[1];
  _DAT_140018578 = puVar6[3];
  _DAT_14001857c = puVar6[2];
  return;
}



===== EdpPluginAction @ 14000389c =====

ulonglong EdpPluginAction(longlong param_1,undefined8 param_2,ulonglong param_3,ushort *param_4,
                         uint param_5,char param_6,int param_7)

{
  longlong *plVar1;
  bool bVar2;
  short *psVar3;
  char cVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  short **ppsVar9;
  uint uVar10;
  short *psVar11;
  uint uVar12;
  short *local_58;
  short *local_50;
  longlong local_48 [4];
  
  uVar7 = (ulonglong)param_5;
  ppsVar9 = &local_58;
  local_58 = (short *)0x0;
  bVar2 = false;
  uVar6 = SrpCreateEnterpriseContext(param_3,param_5,param_4,ppsVar9);
  psVar11 = local_58;
  uVar8 = uVar6 & 0xffffffff;
  if ((int)uVar6 < 0) goto LAB_140003a53;
  plVar1 = (longlong *)(param_1 + 0x30);
  if (param_7 != 0) {
    local_48[3] = *plVar1;
    local_50 = (short *)0x0;
    local_48[2] = 0;
    if (local_48[3] == 0) {
      local_48[3] = -6;
    }
    local_48[0] = 0;
    local_48[1] = 0;
    uVar5 = GetEnterpriseContext(local_48,(longlong *)&local_50);
    psVar3 = local_50;
    uVar8 = (ulonglong)uVar5;
    if ((int)uVar5 < 0) goto LAB_140003a53;
    bVar2 = true;
    if ((*(byte *)(local_50 + 4) & 1) != 0) {
      param_6 = '\0';
      uVar5 = SrpGetExemptEnterpriseIdsPresent(*plVar1,&param_6);
      uVar8 = (ulonglong)uVar5;
      if ((int)uVar5 < 0) goto LAB_140003a53;
      if (param_6 != '\0') {
        *(ulonglong *)(psVar3 + 4) = *(ulonglong *)(psVar3 + 4) | 0x20;
      }
    }
    if (*psVar11 == *psVar3) {
      if (*(ulonglong *)(psVar11 + 4) == *(ulonglong *)(psVar3 + 4)) {
        if ((*(ulonglong *)(psVar11 + 4) & 0x20) == 0) {
          uVar5 = *(uint *)(psVar11 + 2);
          if (uVar5 != *(uint *)(psVar3 + 2)) goto LAB_1400039e6;
          uVar10 = 0;
          if (uVar5 != 0) {
            do {
              uVar6 = 0;
              do {
                uVar12 = (uint)uVar6;
                cVar4 = RtlEqualUnicodeString
                                  (psVar11 + ((ulonglong)uVar10 + 1) * 8,psVar3 + (uVar6 + 1) * 8,0)
                ;
                if (cVar4 != '\0') break;
                uVar12 = uVar12 + 1;
                uVar6 = (ulonglong)uVar12;
              } while (uVar12 < uVar5);
              psVar11 = local_58;
              if (uVar12 == uVar5) goto LAB_1400039e6;
              uVar10 = uVar10 + 1;
            } while (uVar10 < uVar5);
          }
        }
        bVar2 = false;
      }
    }
LAB_1400039e6:
    uVar7 = 0;
    ExFreePoolWithTag(psVar3);
  }
  if (param_7 == 2) {
    uVar5 = SrpDeleteEnterpriseContextToken(*plVar1);
  }
  else {
    uVar5 = SrpSetEnterpriseContextToken
                      (*plVar1,uVar7,EdppSingleInstanceAttributes,ppsVar9,(longlong)psVar11,0);
  }
  uVar8 = (ulonglong)uVar5;
  if ((-1 < (int)uVar5) && ((param_7 == 0 || (bVar2)))) {
    uVar5 = NikEdpNotifyProcessTokenChange0(*(undefined8 *)(param_1 + 8),param_7 != 0);
    uVar8 = (ulonglong)uVar5;
  }
LAB_140003a53:
  if (psVar11 != (short *)0x0) {
    ExFreePoolWithTag(psVar11,0);
  }
  return uVar8;
}



===== EdppIsAppxBroker @ 140003a90 =====

void EdppIsAppxBroker(longlong param_1,byte *param_2)

{
  undefined8 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined8 **)(param_1 + 0x38);
  if (*(int *)(puVar1 + 1) < 0) {
    iVar2 = AipGetPackageClaim(*puVar1,(undefined8 *)((longlong)puVar1 + 0xc));
    *(int *)(puVar1 + 1) = iVar2;
    if (iVar2 < 0) {
      return;
    }
  }
  *param_2 = (byte)(*(uint *)((longlong)puVar1 + 0xc) >> 6) & 1;
  return;
}



===== EdppClearToken @ 140003ae4 =====

void EdppClearToken(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  char in_stack_ffffffffffffff80;
  undefined1 local_68 [8];
  undefined8 local_60;
  undefined8 local_38;
  
  uVar1 = 0;
  memset(local_68,0,0x60);
  local_60 = param_2;
  local_38 = param_1;
  EdpPluginAction((longlong)local_68,uVar1,0,(ushort *)0x0,0,in_stack_ffffffffffffff80,2);
  return;
}



===== EdppIsActive @ 140003b48 =====

undefined8 EdppIsActive(int *param_1,int param_2,undefined8 *param_3)

{
  if (param_2 != 4) {
    return 0xc000000d;
  }
  LOCK();
  if (DAT_14001854c == 0) {
    DAT_14001854c = 0;
  }
  UNLOCK();
  *param_1 = DAT_14001854c;
  *param_3 = 4;
  return 0;
}



===== EdpPluginEvaluate @ 140003b74 =====

int EdpPluginEvaluate(uint *param_1,uint *param_2,ulonglong *param_3,undefined8 *param_4,
                     uint *param_5)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  uint *puVar3;
  byte bVar4;
  undefined2 *puVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  undefined8 uVar9;
  undefined2 *puVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  byte *pbVar13;
  uint **ppuVar14;
  undefined2 *puVar15;
  byte bVar16;
  uint **ppuVar17;
  byte local_res8 [8];
  uint **local_res10;
  ulonglong *local_res18;
  undefined8 *local_res20;
  byte local_88;
  byte local_87;
  byte local_86;
  byte local_85;
  uint local_84;
  uint local_80 [2];
  ushort *local_78;
  undefined2 *local_70;
  longlong local_68 [5];
  
  puVar3 = param_5;
  *param_3 = 0;
  *param_2 = 0xc0000001;
  local_80[0] = 0xc0000001;
  local_80[1] = 0;
  local_68[3] = *(longlong *)(param_1 + 0xc);
  local_85 = 0;
  local_res8[0] = 0;
  if (local_68[3] == 0) {
    local_68[3] = -6;
  }
  local_86 = 0;
  local_88 = 0;
  iVar8 = 0;
  local_87 = 0;
  *param_4 = 0;
  *param_5 = 0;
  puVar15 = (undefined2 *)0x0;
  local_68[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_84 = 0;
  local_70 = (undefined2 *)0x0;
  local_78 = (ushort *)0x0;
  local_res10 = (uint **)param_2;
  local_res18 = param_3;
  local_res20 = param_4;
  uVar7 = QueryAttributes(local_68,4,(longlong *)&local_70);
  puVar5 = local_70;
  param_5._0_4_ = uVar7;
  if ((int)uVar7 < 0) {
    puVar10 = local_70;
    if (local_70 != (undefined2 *)0x0) goto LAB_140003cb6;
  }
  else {
    GetPointersOfAttributesValues
              ((longlong)local_70,(undefined8 *)0x0,(undefined8 *)0x0,(undefined4 *)0x0,
               (undefined8 *)0x0,&local_78);
    puVar10 = (undefined2 *)0x0;
    if (local_78 == (ushort *)0x0) {
LAB_140003c85:
      puVar15 = puVar10;
      puVar10 = puVar15;
    }
    else {
      uVar9 = CalcEnterpriseIdsBufferSize(1,local_78,&local_84);
      param_5._0_4_ = (uint)uVar9;
      puVar10 = (undefined2 *)EnterpriseContextLibMemAlloc((ulonglong)local_84);
      if (puVar10 != (undefined2 *)0x0) {
        CopyEnterpriseId(puVar10,puVar10 + 8,(short *)local_78);
        goto LAB_140003c85;
      }
      param_5._0_4_ = 0xc0000017;
    }
    if (puVar5 != (undefined2 *)0x0) {
      ExFreePoolWithTag(puVar5,0);
    }
    if (((int)(uint)param_5 < 0) && (puVar10 != (undefined2 *)0x0)) {
LAB_140003cb6:
      ExFreePoolWithTag(puVar10,0);
    }
  }
  puVar1 = local_res20;
  ppuVar14 = local_res10;
  cVar6 = EdppPolicyOverride((longlong *)param_1,(undefined4 *)local_res10,param_3,local_res20,
                             puVar3);
  if (cVar6 == '\0') {
    iVar8 = EdppIsApplicationClaimSet(0,(longlong)param_1,local_res8);
    if (-1 < iVar8) {
      pbVar13 = &local_87;
      iVar8 = EdppServiceExempt((longlong)param_1,(char *)pbVar13);
      bVar4 = local_87;
      if (-1 < iVar8) {
        if (local_87 == 0) {
          pbVar13 = &local_86;
          uVar12 = EdppPolicyExempt((longlong *)param_1,(char *)pbVar13,&local_88,puVar1,puVar3);
          iVar8 = (int)uVar12;
          if (iVar8 < 0) goto LAB_140003ec4;
          bVar16 = local_86;
        }
        else {
          bVar16 = 1;
        }
        ppuVar14 = (uint **)CONCAT71((int7)((ulonglong)pbVar13 >> 8),local_88);
        if (((local_res8[0] != 0) && (bVar16 != 0)) && (local_88 == 0)) {
          bVar16 = bVar16 & -(bVar4 != 0);
        }
        if (puVar15 == (undefined2 *)0x0) {
          if (bVar16 != 0) {
            uVar12 = *param_3;
            uVar11 = uVar12 | 1;
            *param_3 = uVar11;
            if (local_88 != 0) {
              uVar11 = uVar12 | 0x21;
              *param_3 = uVar11;
            }
            if (bVar4 != 0) {
              *param_3 = uVar11 | 0x10;
            }
            goto LAB_140003d9b;
          }
          if (local_res8[0] != 0) {
            *param_3 = *param_3 | 2;
            ppuVar14 = (uint **)param_1;
            iVar8 = EdppIsApplicationClaimSet(1,(longlong)param_1,&local_85);
            if (iVar8 < 0) {
              return iVar8;
            }
            if (local_85 != 0) {
              *param_3 = *param_3 | 8;
              goto LAB_140003d9b;
            }
          }
          goto LAB_140003e27;
        }
        *param_3 = 0;
LAB_140003d9b:
        if (bVar16 != 0) goto LAB_140003f48;
        if (puVar15 == (undefined2 *)0x0) {
LAB_140003e27:
          uVar7 = 0;
          param_5._0_4_ = (uint)param_5 & 0xffffff00;
          cVar6 = '\0';
          if ((*(char *)(*(longlong *)param_1 + 1) != '\0') && (local_res8[0] == 0)) {
            ppuVar14 = &param_5;
            iVar8 = SrpIsApplicationAutoProtectionAllowed
                              (*(longlong *)(param_1 + 8),(byte *)ppuVar14);
            if (iVar8 < 0) goto LAB_140003ec4;
            cVar6 = (char)param_5;
            if ((((char)param_5 == '\0') &&
                (ppuVar14 = *(uint ***)(param_1 + 0x12), *ppuVar14 == (uint *)0x4896ef1a58125a50))
               && (ppuVar14[1] == (uint *)0x6ccab39ac6d657ba)) {
              ppuVar14 = &param_5;
              uVar9 = EdppIsAppxLineOfBusiness((longlong)param_1,(undefined1 *)ppuVar14);
              iVar8 = (int)uVar9;
              if (iVar8 < 0) goto LAB_140003ec4;
              cVar6 = (char)param_5;
            }
          }
          puVar1 = local_res20;
          if (((*(char *)(*(longlong *)param_1 + 1) == '\0') || (cVar6 != '\0')) ||
             (local_res8[0] != 0)) {
            ppuVar14 = (uint **)0x0;
            uVar12 = EdppEvaluatePolicies((longlong *)param_1,0,local_80,local_res20,puVar3);
            iVar8 = (int)uVar12;
            *(uint *)local_res10 = local_80[0];
            if (iVar8 < 0) goto LAB_140003ec4;
          }
          puVar2 = local_res20;
          if (((puVar15 != (undefined2 *)0x0) && (-1 < (int)*(uint *)local_res10)) &&
             (ppuVar17 = (uint **)*puVar1, *puVar3 != 0)) {
            do {
              ppuVar14 = ppuVar17;
              cVar6 = RtlEqualUnicodeString(puVar15,ppuVar17,1);
              if (cVar6 != '\0') {
                *puVar2 = ppuVar17;
                *puVar3 = 1;
              }
              uVar7 = uVar7 + 1;
              ppuVar17 = ppuVar17 + 2;
              param_3 = local_res18;
            } while (uVar7 < *puVar3);
          }
          if (((*puVar3 == 0) && (*param_3 == 0)) &&
             (uVar9 = EdppIsDisallowedExempt((longlong)param_1), (char)uVar9 != '\0')) {
            *param_3 = 0x11;
          }
          else {
            uVar9 = AiResultIsExplicitDeny((int *)local_80);
            if ((char)uVar9 != '\0') {
              *param_3 = *param_3 | 0x40;
            }
          }
          goto LAB_140003f48;
        }
        ppuVar14 = (uint **)&EdppPersonalName;
        cVar6 = RtlEqualUnicodeString(puVar15,&EdppPersonalName,1);
        if (cVar6 == '\0') goto LAB_140003e27;
        ppuVar14 = (uint **)&EdppPersonalName;
        cVar6 = RtlEqualUnicodeString(puVar15,&EdppPersonalName,1);
        if (cVar6 != '\0') {
          *param_3 = *param_3 | 0x40;
        }
        goto LAB_140003f4d;
      }
    }
LAB_140003ec4:
    if (puVar15 == (undefined2 *)0x0) {
      return iVar8;
    }
  }
  else {
LAB_140003f48:
    if (puVar15 == (undefined2 *)0x0) {
      return iVar8;
    }
LAB_140003f4d:
    iVar8 = EdppRemoveIntentEnterpriseIdToken(*(longlong *)(param_1 + 0xc),ppuVar14);
  }
  ExFreePoolWithTag(puVar15,0);
  return iVar8;
}



===== WpcPluginNotifyRoutine @ 140003fa0 =====

undefined8
WpcPluginNotifyRoutine
          (longlong *param_1,char *param_2,longlong param_3,undefined8 param_4,undefined8 param_5,
          longlong param_6,undefined8 param_7,longlong *param_8,uint *param_9)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  char local_res10 [8];
  
  *param_9 = 0;
  lVar2 = *param_1 + -0x4896ef1a58125a50;
  if (lVar2 == 0) {
    lVar2 = param_1[1] + -0x6ccab39ac6d657ba;
  }
  uVar5 = 0;
  uVar4 = (uint)param_2;
  if (uVar4 != 0) {
    do {
      uVar3 = AiEvaluateAppLockerPolicyClass
                        (param_1,param_2,(ulonglong)uVar5 * 0x20 + param_3,param_6,param_9);
      if ((-1 < (int)uVar3) && ((int)*param_9 < 0)) {
        if (lVar2 != 0) {
LAB_140004045:
          *param_9 = 0xc0000488;
          return 0;
        }
        uVar3 = AiResultIsExplicitDeny((int *)param_9);
        local_res10[0] = (char)uVar3;
        if (local_res10[0] != '\0') goto LAB_140004045;
        param_2 = local_res10;
        param_1 = param_8;
        iVar1 = AiIsAppxInbox(param_8,param_2);
        if ((iVar1 < 0) || (local_res10[0] == '\0')) goto LAB_140004045;
        *param_9 = 0;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar4);
  }
  return 0;
}



===== CalcEnterpriseIdsBufferSize @ 140004068 =====

undefined8 CalcEnterpriseIdsBufferSize(uint param_1,ushort *param_2,undefined4 *param_3)

{
  ushort uVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  
  *param_3 = 0;
  if ((param_1 == 0) || (param_2 == (ushort *)0x0)) {
    uVar2 = 0;
  }
  else {
    uVar5 = (ulonglong)param_1 * 0x10;
    if (uVar5 < 0x100000000) {
      uVar4 = 0;
      if (param_1 != 0) {
        do {
          uVar1 = *param_2 + 2;
          if ((uVar1 < *param_2) || (uVar3 = (uint)uVar1 + (uint)uVar5, uVar3 < (uint)uVar5))
          goto LAB_1400040c3;
          uVar4 = uVar4 + 1;
          param_2 = param_2 + 8;
          uVar5 = (ulonglong)uVar3;
        } while (uVar4 < param_1);
      }
      *param_3 = (int)uVar5;
      uVar2 = 0;
    }
    else {
LAB_1400040c3:
      uVar2 = 0xc0000095;
    }
  }
  return uVar2;
}



===== CopyEnterpriseId @ 1400040dc =====

ushort CopyEnterpriseId(undefined2 *param_1,void *param_2,short *param_3)

{
  ushort uVar1;
  
  uVar1 = *param_3 + 2;
  memset(param_2,0,(ulonglong)uVar1);
  param_1[1] = uVar1;
  *param_1 = 0;
  *(void **)(param_1 + 4) = param_2;
  RtlCopyUnicodeString(param_1,param_3);
  return uVar1;
}



===== CreateAttributesFromContext @ 140004150 =====

/* WARNING: Removing unreachable block (ram,0x0001400043ec) */

undefined4
CreateAttributesFromContext
          (longlong param_1,char param_2,char param_3,longlong param_4,undefined8 *param_5)

{
  ulonglong uVar1;
  ulonglong *puVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined8 *puVar8;
  longlong lVar9;
  undefined4 uVar10;
  ulonglong uVar11;
  uint uVar12;
  
  puVar2 = (ulonglong *)0x0;
  uVar1 = *(ulonglong *)(param_1 + 8);
  uVar12 = *(uint *)(param_1 + 4);
  uVar11 = (ulonglong)uVar12;
  *param_5 = 0;
  plVar4 = (longlong *)0x0;
  lVar3 = 0;
  if ((uVar1 & 0xffffffffffffff5f) != 0) {
    puVar2 = (ulonglong *)EnterpriseContextLibMemAllocPaged(8,param_3);
    if (puVar2 == (ulonglong *)0x0) {
      return 0xc0000017;
    }
    *puVar2 = *(ulonglong *)(param_1 + 8) & 0xffffffffffffff5f;
  }
  if (uVar12 == 0) {
    lVar3 = 0;
LAB_140004255:
    plVar4 = (longlong *)0x0;
    if (param_2 == '\0') {
      plVar4 = (longlong *)EnterpriseContextLibMemAllocPaged(8,param_3);
      if (plVar4 == (longlong *)0x0) goto LAB_140004208;
      if (param_4 == 0) {
        *plVar4 = 1;
        if (*(char *)(param_1 + 8) < '\0') {
          *plVar4 = 3;
        }
      }
      else {
        *plVar4 = param_4;
      }
    }
    lVar9 = EnterpriseContextLibMemAllocPaged(0xa0,param_3);
    if (lVar9 != 0) {
      RtlInitUnicodeString(lVar9,L"EDP://PolicyFlags");
      *(undefined4 *)(lVar9 + 0x10) = 2;
      *(undefined4 *)(lVar9 + 0x14) = 0x41;
      *(ulonglong **)(lVar9 + 0x20) = puVar2;
      *(uint *)(lVar9 + 0x18) = (uint)(puVar2 != (ulonglong *)0x0);
      RtlInitUnicodeString(lVar9 + 0x28,L"EDP://EnterpriseIds");
      *(undefined4 *)(lVar9 + 0x38) = 3;
      *(undefined4 *)(lVar9 + 0x3c) = 0x43;
      if ((*(byte *)(param_1 + 8) & 0x20) == 0) {
        lVar5 = lVar3;
        uVar7 = uVar12;
      }
      else {
        lVar5 = 0;
        uVar7 = 0;
      }
      *(uint *)(lVar9 + 0x40) = uVar7;
      *(longlong *)(lVar9 + 0x48) = lVar5;
      RtlInitUnicodeString(lVar9 + 0x50,L"EDP://ExemptEnterpriseIds");
      *(undefined4 *)(lVar9 + 0x60) = 3;
      *(undefined4 *)(lVar9 + 100) = 0x43;
      if ((*(byte *)(param_1 + 8) & 0x20) == 0) {
        lVar5 = 0;
        uVar12 = 0;
      }
      else {
        lVar5 = lVar3;
      }
      *(uint *)(lVar9 + 0x68) = uVar12;
      *(longlong *)(lVar9 + 0x70) = lVar5;
      RtlInitUnicodeString(lVar9 + 0x78,L"EDP://EvaluationFlags");
      *(undefined4 *)(lVar9 + 0x88) = 2;
      *(undefined4 *)(lVar9 + 0x8c) = 0x41;
      *(longlong **)(lVar9 + 0x98) = plVar4;
      *(uint *)(lVar9 + 0x90) = (uint)(plVar4 != (longlong *)0x0);
      puVar6 = (undefined4 *)EnterpriseContextLibMemAllocPaged(0x10,param_3);
      if (puVar6 != (undefined4 *)0x0) {
        *puVar6 = 1;
        puVar6[1] = 4;
        *(longlong *)(puVar6 + 2) = lVar9;
        *param_5 = puVar6;
        return 0;
      }
      uVar10 = 0xc0000017;
      ExFreePoolWithTag(lVar9,0);
      goto LAB_14000440e;
    }
  }
  else {
    if (0xffffffff < uVar11 * 0x10) {
      uVar10 = 0xc0000095;
      goto LAB_14000440e;
    }
    lVar3 = EnterpriseContextLibMemAllocPaged(uVar11 * 0x10 & 0xffffffff,param_3);
    if (lVar3 != 0) {
      if (uVar12 != 0) {
        puVar8 = (undefined8 *)(param_1 + 0x18);
        lVar9 = lVar3 - param_1;
        do {
          *(undefined2 *)((longlong)puVar8 + lVar9 + -0x16) = *(undefined2 *)((longlong)puVar8 + -6)
          ;
          *(undefined2 *)((longlong)puVar8 + lVar9 + -0x18) = *(undefined2 *)(puVar8 + -1);
          *(undefined8 *)((longlong)puVar8 + lVar9 + -0x10) = *puVar8;
          puVar8 = puVar8 + 2;
          uVar11 = uVar11 - 1;
        } while (uVar11 != 0);
      }
      goto LAB_140004255;
    }
  }
LAB_140004208:
  uVar10 = 0xc0000017;
LAB_14000440e:
  if (puVar2 != (ulonglong *)0x0) {
    ExFreePoolWithTag(puVar2,0);
  }
  if (plVar4 != (longlong *)0x0) {
    ExFreePoolWithTag(plVar4,0);
  }
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0);
  }
  return uVar10;
}



===== CreateAttributesFromIntentEnterpriseId @ 140004470 =====

undefined4 CreateAttributesFromIntentEnterpriseId(undefined2 *param_1,undefined8 *param_2)

{
  undefined2 *puVar1;
  longlong lVar2;
  undefined4 *puVar3;
  
  *param_2 = 0;
  if (param_1 == (undefined2 *)0x0) {
    puVar1 = (undefined2 *)0x0;
  }
  else {
    puVar1 = (undefined2 *)EnterpriseContextLibMemAlloc(0x10);
    if (puVar1 == (undefined2 *)0x0) {
      return 0xc0000017;
    }
    puVar1[1] = param_1[1];
    *puVar1 = *param_1;
    *(undefined8 *)(puVar1 + 4) = *(undefined8 *)(param_1 + 4);
  }
  lVar2 = EnterpriseContextLibMemAlloc(0x28);
  if (lVar2 != 0) {
    RtlInitUnicodeString(lVar2,L"PEDP://IntentEnterpriseId");
    *(undefined4 *)(lVar2 + 0x10) = 3;
    *(undefined4 *)(lVar2 + 0x14) = 0x42;
    *(undefined2 **)(lVar2 + 0x20) = puVar1;
    *(uint *)(lVar2 + 0x18) = (uint)(puVar1 != (undefined2 *)0x0);
    puVar3 = (undefined4 *)EnterpriseContextLibMemAlloc(0x10);
    if (puVar3 != (undefined4 *)0x0) {
      *(longlong *)(puVar3 + 2) = lVar2;
      *puVar3 = 1;
      puVar3[1] = 1;
      *param_2 = puVar3;
      return 0;
    }
    ExFreePoolWithTag(lVar2,0);
  }
  if (puVar1 != (undefined2 *)0x0) {
    ExFreePoolWithTag(puVar1,0);
  }
  return 0xc0000017;
}



===== DeinitSubjectWithTokenPointer @ 140004590 =====

void DeinitSubjectWithTokenPointer(undefined8 *param_1)

{
  if (param_1[1] != 0) {
    *param_1 = 0;
    SeReleaseSubjectContext();
    ExFreePoolWithTag(param_1[1],0);
    param_1[1] = 0;
  }
  return;
}



===== DeleteAttributes @ 1400045d8 =====

void DeleteAttributes(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  
  if (param_1 != 0) {
    uVar3 = 0;
    if (*(int *)(param_1 + 4) != 0) {
      do {
        lVar1 = *(longlong *)(*(longlong *)(param_1 + 8) + 0x20 + uVar3 * 0x28);
        if (lVar1 != 0) {
          ExFreePoolWithTag(lVar1,0);
        }
        uVar2 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < *(uint *)(param_1 + 4));
    }
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 8),0);
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== EnterpriseContextLibMemAlloc @ 140004658 =====

void EnterpriseContextLibMemAlloc(undefined8 param_1)

{
  byte bVar1;
  
  bVar1 = KeGetCurrentIrql();
  EnterpriseContextLibMemAllocPaged(param_1,bVar1 < 2);
  return;
}



===== EnterpriseContextLibMemAllocPaged @ 140004688 =====

void EnterpriseContextLibMemAllocPaged(undefined8 param_1,char param_2)

{
  ExAllocatePool2((-(uint)(param_2 != '\0') & 0xc0) + 0x42,param_1,0x74436e45);
  return;
}



===== EnterpriseContextLibMemFree @ 1400046c0 =====

void EnterpriseContextLibMemFree(undefined8 param_1)

{
  ExFreePoolWithTag(param_1,0);
  return;
}



===== GetEnterpriseContext @ 1400046e0 =====

int GetEnterpriseContext(longlong *param_1,longlong *param_2)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  uint local_res10 [2];
  longlong local_res18;
  ushort *local_res20;
  ulonglong local_48;
  longlong local_40;
  undefined8 local_38 [2];
  
  local_48 = 0;
  lVar3 = 0;
  local_res10[0] = 0;
  local_40 = 0;
  local_res20 = (ushort *)0x0;
  local_res18 = 0;
  if (param_2 == (longlong *)0x0) {
    return -0x3ffffff3;
  }
  *param_2 = 0;
  iVar1 = QueryFlags(param_1,&local_48,(undefined8 *)0x0);
  if ((-1 < iVar1) && (iVar1 = QueryFlags(param_1,(undefined8 *)0x0,local_38), -1 < iVar1)) {
    iVar1 = QueryEnterpriseIds(param_1,local_res10,&local_40,&local_res20);
    if (-1 < iVar1) {
      uVar2 = SrpCreateEnterpriseContext(local_48,local_res10[0],local_res20,&local_res18);
      iVar1 = (int)uVar2;
      lVar3 = local_res18;
      if (-1 < iVar1) {
        *param_2 = local_res18;
      }
    }
    if (local_40 != 0) {
      ExFreePoolWithTag(local_40,0);
    }
    if (-1 < iVar1) {
      return iVar1;
    }
  }
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0);
  }
  return iVar1;
}



===== GetPointersOfAttributesValues @ 1400047c8 =====

void GetPointersOfAttributesValues
               (longlong param_1,undefined8 *param_2,undefined8 *param_3,undefined4 *param_4,
               undefined8 *param_5,undefined8 *param_6)

{
  ushort uVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  if (param_5 != (undefined8 *)0x0) {
    *param_5 = 0;
  }
  if (param_6 != (undefined8 *)0x0) {
    *param_6 = 0;
  }
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = 0;
  }
  if (((((param_3 != (undefined8 *)0x0) || (param_4 != (undefined4 *)0x0)) ||
       (param_5 != (undefined8 *)0x0)) ||
      ((param_6 != (undefined8 *)0x0 || (param_2 != (undefined8 *)0x0)))) &&
     ((param_1 != 0 && (uVar5 = 0, *(int *)(param_1 + 4) != 0)))) {
    do {
      lVar2 = *(longlong *)(param_1 + 8);
      if ((*(int *)(lVar2 + 0x18 + uVar5 * 0x28) != 0) &&
         (*(longlong *)(lVar2 + 0x20 + uVar5 * 0x28) != 0)) {
        if ((param_3 == (undefined8 *)0x0) ||
           ((uVar1 = *(ushort *)(lVar2 + uVar5 * 0x28), (uVar1 & 0xfffe) != 0x22 ||
            (uVar3 = RtlCompareMemory(*(undefined8 *)(lVar2 + 8 + uVar5 * 0x28),L"EDP://PolicyFlags"
                                      ,uVar1), uVar3 != *(ushort *)(lVar2 + uVar5 * 0x28))))) {
          if (((param_2 == (undefined8 *)0x0) ||
              (uVar1 = *(ushort *)(lVar2 + uVar5 * 0x28), (uVar1 & 0xfffe) != 0x2a)) ||
             (uVar3 = RtlCompareMemory(*(undefined8 *)(lVar2 + 8 + uVar5 * 0x28),
                                       L"EDP://EvaluationFlags",uVar1),
             uVar3 != *(ushort *)(lVar2 + uVar5 * 0x28))) {
            if (((param_4 == (undefined4 *)0x0) && (param_5 == (undefined8 *)0x0)) ||
               ((uVar1 = *(ushort *)(lVar2 + uVar5 * 0x28), (uVar1 & 0xfffe) != 0x26 ||
                (uVar3 = RtlCompareMemory(*(undefined8 *)(lVar2 + 8 + uVar5 * 0x28),
                                          L"EDP://EnterpriseIds",uVar1),
                uVar3 != *(ushort *)(lVar2 + uVar5 * 0x28))))) {
              if (((param_6 != (undefined8 *)0x0) &&
                  (uVar1 = *(ushort *)(lVar2 + uVar5 * 0x28), (uVar1 & 0xfffe) == 0x32)) &&
                 (uVar3 = RtlCompareMemory(*(undefined8 *)(lVar2 + 8 + uVar5 * 0x28),
                                           L"PEDP://IntentEnterpriseId",uVar1),
                 uVar3 == *(ushort *)(lVar2 + uVar5 * 0x28))) {
                *param_6 = *(undefined8 *)(lVar2 + 0x20 + uVar5 * 0x28);
              }
            }
            else {
              if (param_4 != (undefined4 *)0x0) {
                *param_4 = *(undefined4 *)(lVar2 + 0x18 + uVar5 * 0x28);
              }
              if (param_5 != (undefined8 *)0x0) {
                *param_5 = *(undefined8 *)(lVar2 + 0x20 + uVar5 * 0x28);
              }
            }
          }
          else {
            *param_2 = *(undefined8 *)(lVar2 + 0x20 + uVar5 * 0x28);
          }
        }
        else {
          *param_3 = *(undefined8 *)(lVar2 + 0x20 + uVar5 * 0x28);
        }
      }
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
    } while (uVar4 < *(uint *)(param_1 + 4));
  }
  return;
}



===== InitSubjectByTokenHandle @ 140004a00 =====

void InitSubjectByTokenHandle(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  lVar1 = -6;
  if (param_1 != 0) {
    lVar1 = param_1;
  }
  param_2[3] = lVar1;
  return;
}



===== InitSubjectByTokenPointer @ 140004a28 =====

undefined8 InitSubjectByTokenPointer(longlong *param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  
  if (param_1 == (longlong *)0x0) {
    plVar1 = (longlong *)EnterpriseContextLibMemAlloc(0x20);
    if (plVar1 == (longlong *)0x0) {
      return 0xc0000017;
    }
    SeCaptureSubjectContext(plVar1);
    param_1 = plVar1;
  }
  else {
    plVar1 = (longlong *)0x0;
  }
  param_2[1] = (longlong)plVar1;
  lVar2 = *param_1;
  if (lVar2 == 0) {
    lVar2 = param_1[2];
  }
  param_2[3] = 0;
  param_2[2] = 0;
  *param_2 = lVar2;
  return 0;
}



===== IsContextAllowed @ 140004a9c =====

void IsContextAllowed(undefined8 param_1,ulonglong param_2,uint param_3,longlong param_4,
                     undefined1 *param_5)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  
  *param_5 = 0;
  if ((param_2 & 1) == 0) {
    if ((param_4 != 0) && (uVar3 = 0, param_3 != 0)) {
      do {
        iVar1 = RtlCompareUnicodeString(param_1,uVar3 * 0x10 + param_4,0);
        if (iVar1 == 0) goto LAB_140004afe;
        uVar2 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < param_3);
    }
  }
  else {
LAB_140004afe:
    *param_5 = 1;
  }
  return;
}



===== IsEnterpriseAllowed @ 140004b24 =====

int IsEnterpriseAllowed(longlong *param_1,longlong param_2,undefined8 param_3,undefined1 *param_4)

{
  int iVar1;
  longlong lVar2;
  longlong local_res10;
  uint local_res18 [4];
  undefined8 local_48;
  longlong local_40;
  ulonglong local_38 [2];
  
  local_38[0] = 0;
  lVar2 = 0;
  local_40 = 0;
  local_48 = 0;
  local_res18[0] = 0;
  local_res10 = 0;
  if ((param_2 == 0) || (param_4 == (undefined1 *)0x0)) {
    return -0x3ffffff3;
  }
  *param_4 = 0;
  iVar1 = QueryFlags(param_1,(undefined8 *)0x0,&local_48);
  if (-1 < iVar1) {
    if (((byte)local_48 & 3) == 1) {
      iVar1 = QueryFlags(param_1,local_38,(undefined8 *)0x0);
      if (iVar1 < 0) {
        return iVar1;
      }
      iVar1 = QueryEnterpriseIds(param_1,local_res18,&local_res10,&local_40);
      if (-1 < iVar1) {
        IsContextAllowed(param_2,local_38[0],local_res18[0],local_40,param_4);
      }
      lVar2 = local_res10;
    }
    else {
      *param_4 = 1;
    }
    if (lVar2 != 0) {
      ExFreePoolWithTag(lVar2,0);
    }
  }
  return iVar1;
}



===== QueryAttributes @ 140004c1c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int QueryAttributes(longlong *param_1,uint param_2,longlong *param_3)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  bool bVar5;
  undefined1 auStack_b8 [32];
  uint local_98;
  uint *local_90;
  uint local_88 [4];
  undefined1 local_78 [64];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_b8;
  memset(local_78,0,0x40);
  lVar2 = 0;
  local_88[0] = 0;
  *param_3 = 0;
  uVar3 = 0x10;
  bVar5 = (param_2 & 1) != 0;
  if (bVar5) {
    uVar3 = 100;
    RtlInitUnicodeString(local_78,L"EDP://PolicyFlags");
  }
  uVar4 = (ulonglong)bVar5;
  if ((param_2 & 2) != 0) {
    uVar3 = uVar3 + 0x98;
    RtlInitUnicodeString(local_78 + uVar4 * 0x10,L"EDP://EnterpriseIds");
    uVar4 = (ulonglong)(bVar5 + 1);
  }
  if ((param_2 & 4) != 0) {
    uVar3 = uVar3 + 0x98;
    RtlInitUnicodeString(local_78 + uVar4 * 0x10,L"PEDP://IntentEnterpriseId");
    uVar4 = (ulonglong)((int)uVar4 + 1);
  }
  if ((param_2 & 8) != 0) {
    uVar3 = uVar3 + 0x54;
    RtlInitUnicodeString(local_78 + uVar4 * 0x10,L"EDP://EvaluationFlags");
    uVar4 = (ulonglong)((int)uVar4 + 1);
  }
  if ((param_2 & 0x10) != 0) {
    RtlInitUnicodeString(local_78 + uVar4 * 0x10,L"EDP://ExemptEnterpriseIds");
    uVar4 = (ulonglong)((int)uVar4 + 1);
    uVar3 = uVar3 + 0x98;
  }
  while( true ) {
    if (lVar2 != 0) {
      ExFreePoolWithTag(lVar2,0);
    }
    lVar2 = EnterpriseContextLibMemAlloc((ulonglong)uVar3);
    if (lVar2 == 0) {
      return -0x3fffffe9;
    }
    local_90 = local_88;
    local_98 = uVar3;
    if (*param_1 == 0) {
      if (param_1[3] == 0) {
        iVar1 = SeQuerySecurityAttributesTokenAccessInformation(param_1[2],local_78,uVar4,lVar2);
      }
      else {
        iVar1 = ZwQuerySecurityAttributesToken();
      }
    }
    else {
      iVar1 = SeQuerySecurityAttributesToken();
    }
    if (iVar1 != -0x3fffffdd) break;
    if (local_88[0] <= uVar3) goto LAB_140004e06;
    uVar3 = local_88[0];
  }
  if (iVar1 == -0x3ffffddb) {
    ExFreePoolWithTag(lVar2,0);
    *param_3 = 0;
    return 0;
  }
  if (-1 < iVar1) {
    *param_3 = lVar2;
    return iVar1;
  }
LAB_140004e06:
  ExFreePoolWithTag(lVar2,0);
  return iVar1;
}



===== QueryEnterpriseIds @ 140004e50 =====

int QueryEnterpriseIds(longlong *param_1,undefined4 *param_2,longlong *param_3,undefined8 *param_4)

{
  longlong lVar1;
  int iVar2;
  longlong local_res10;
  
  *param_2 = 0;
  *param_3 = 0;
  local_res10 = 0;
  *param_4 = 0;
  iVar2 = QueryAttributes(param_1,2,&local_res10);
  lVar1 = local_res10;
  if (iVar2 < 0) {
    if (local_res10 != 0) {
      ExFreePoolWithTag(local_res10,0);
    }
  }
  else {
    GetPointersOfAttributesValues
              (local_res10,(undefined8 *)0x0,(undefined8 *)0x0,param_2,param_4,(undefined8 *)0x0);
    *param_3 = lVar1;
  }
  return iVar2;
}



===== QueryFlags @ 140004ef0 =====

int QueryFlags(longlong *param_1,undefined8 *param_2,undefined8 *param_3)

{
  int iVar1;
  uint uVar2;
  longlong local_res10;
  undefined8 *local_res18;
  undefined8 *local_res20;
  
  local_res10 = 0;
  local_res18 = (undefined8 *)0x0;
  local_res20 = (undefined8 *)0x0;
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = 0;
  }
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
  }
  uVar2 = -(uint)(param_3 != (undefined8 *)0x0) & 8;
  iVar1 = QueryAttributes(param_1,param_2 != (undefined8 *)0x0 | uVar2,&local_res10);
  if (-1 < iVar1) {
    GetPointersOfAttributesValues
              (local_res10,(undefined8 *)(-(ulonglong)(uVar2 != 0) & (ulonglong)&local_res20),
               (undefined8 *)(-(ulonglong)(param_2 != (undefined8 *)0x0) & (ulonglong)&local_res18),
               (undefined4 *)0x0,(undefined8 *)0x0,(undefined8 *)0x0);
    if ((param_2 != (undefined8 *)0x0) && (local_res18 != (undefined8 *)0x0)) {
      *param_2 = *local_res18;
    }
    if ((param_3 != (undefined8 *)0x0) && (local_res20 != (undefined8 *)0x0)) {
      *param_3 = *local_res20;
    }
  }
  if (local_res10 != 0) {
    ExFreePoolWithTag(local_res10,0);
  }
  return iVar1;
}



===== SrpCreateEnterpriseContext @ 140004ff0 =====

ulonglong SrpCreateEnterpriseContext
                    (ulonglong param_1,uint param_2,ushort *param_3,undefined8 *param_4)

{
  ushort uVar1;
  ulonglong uVar2;
  undefined4 *_Dst;
  undefined6 extraout_var;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  void *pvVar6;
  ulonglong uVar7;
  undefined4 *puVar8;
  uint local_38 [4];
  
  lVar4 = 0;
  uVar5 = (ulonglong)param_2;
  local_38[0] = 0;
  if ((param_4 == (undefined8 *)0x0) ||
     (((param_2 != 0 && (param_3 == (ushort *)0x0)) || ((param_1 & 0xffffffffffffff00) != 0)))) {
    uVar7 = 0xc000000d;
  }
  else {
    if (((param_2 == 0) && ((param_1 & 1) == 0)) && ((param_1 & 10) != 0)) {
      param_1 = param_1 & 0xfffffffffffffff5;
    }
    *param_4 = 0;
    uVar2 = CalcEnterpriseIdsBufferSize(param_2,param_3,local_38);
    uVar7 = uVar2 & 0xffffffff;
    if (-1 < (int)uVar2) {
      uVar3 = local_38[0] + 0x20;
      if (uVar3 < local_38[0]) {
        uVar7 = 0xc0000095;
      }
      else {
        uVar7 = 0;
        if (param_2 != 0) {
          uVar3 = local_38[0] + 0x10;
        }
        _Dst = (undefined4 *)ExAllocatePool2(0x42,uVar3,0x74436e45);
        if (_Dst == (undefined4 *)0x0) {
          uVar7 = 0xc0000017;
        }
        else {
          memset(_Dst,0,(ulonglong)uVar3);
          *(ulonglong *)(_Dst + 2) = param_1;
          puVar8 = _Dst + 4;
          *_Dst = 1;
          pvVar6 = (void *)((ulonglong)(param_2 << 4) + (longlong)puVar8);
          _Dst[1] = param_2;
          if (param_2 != 0) {
            do {
              uVar1 = CopyEnterpriseId((undefined2 *)puVar8,pvVar6,(short *)(param_3 + lVar4 * 8));
              puVar8 = puVar8 + 4;
              pvVar6 = (void *)((longlong)pvVar6 + (CONCAT62(extraout_var,uVar1) & 0xffffffff));
              lVar4 = lVar4 + 1;
              uVar5 = uVar5 - 1;
            } while (uVar5 != 0);
          }
          *param_4 = _Dst;
        }
      }
    }
  }
  return uVar7;
}



===== SrpDeleteEnterpriseContext @ 140005150 =====

void SrpDeleteEnterpriseContext(longlong param_1)

{
  if (param_1 != 0) {
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== SrpDeleteEnterpriseContextToken @ 140005174 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SrpDeleteEnterpriseContextToken(longlong param_1)

{
  char cVar1;
  longlong lVar2;
  int iVar3;
  undefined1 auStackY_88 [32];
  longlong local_40 [7];
  
  cVar1 = EdppSingleInstanceAttributes;
  local_40[5] = __security_cookie ^ (ulonglong)auStackY_88;
  local_40[0] = 0;
  local_40[1] = 0;
  local_40[2] = 0;
  local_40[3] = 0;
  local_40[4] = 0;
  if (param_1 == 0) {
    iVar3 = -0x3ffffff3;
  }
  else {
    iVar3 = CreateAttributesFromContext
                      ((longlong)(local_40 + 1),'\x01',EdppSingleInstanceAttributes == '\0',0,
                       local_40);
    lVar2 = local_40[0];
    if (-1 < iVar3) {
      iVar3 = SeSetSecurityAttributesTokenEx(param_1,0,0,cVar1);
    }
    DeleteAttributes(lVar2);
  }
  return iVar3;
}



===== SrpGetEnterpriseContextToken @ 140005260 =====

void SrpGetEnterpriseContextToken(longlong param_1,longlong *param_2)

{
  longlong local_28 [5];
  
  local_28[2] = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[3] = -6;
  if (param_1 != 0) {
    local_28[3] = param_1;
  }
  GetEnterpriseContext(local_28,param_2);
  return;
}



===== SrpGetEvaluationFlagsToken @ 14000529c =====

int SrpGetEvaluationFlagsToken(longlong param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 local_res8 [4];
  longlong local_28 [4];
  
  local_28[2] = 0;
  local_28[3] = -6;
  if (param_1 != 0) {
    local_28[3] = param_1;
  }
  local_res8[0] = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  if (param_2 == (undefined8 *)0x0) {
    iVar1 = -0x3ffffff3;
  }
  else {
    *param_2 = 0;
    iVar1 = QueryFlags(local_28,(undefined8 *)0x0,local_res8);
    if (-1 < iVar1) {
      *param_2 = local_res8[0];
    }
  }
  return iVar1;
}



===== SrpGetPolicyFlags @ 140005308 =====

ulonglong SrpGetPolicyFlags(longlong *param_1,undefined8 *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 local_res18 [2];
  longlong local_28 [4];
  
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  uVar2 = InitSubjectByTokenPointer(param_1,local_28);
  if (-1 < (int)uVar2) {
    local_res18[0] = 0;
    if (param_2 == (undefined8 *)0x0) {
      uVar1 = 0xc000000d;
    }
    else {
      *param_2 = 0;
      uVar1 = QueryFlags(local_28,local_res18,(undefined8 *)0x0);
      if (-1 < (int)uVar1) {
        *param_2 = local_res18[0];
      }
    }
    DeinitSubjectWithTokenPointer(local_28);
    uVar2 = (ulonglong)uVar1;
  }
  return uVar2;
}



===== SrpIsEnterpriseAllowed @ 140005384 =====

void SrpIsEnterpriseAllowed(longlong *param_1,longlong param_2,undefined8 param_3)

{
  SrpIsEnterpriseAllowedInternal(param_1,param_2,param_3,(undefined1 *)param_3);
  return;
}



===== SrpIsEnterpriseAllowedInternal @ 14000539c =====

ulonglong SrpIsEnterpriseAllowedInternal
                    (longlong *param_1,longlong param_2,undefined8 param_3,undefined1 *param_4)

{
  uint uVar1;
  ulonglong uVar2;
  longlong local_28 [4];
  
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  uVar2 = InitSubjectByTokenPointer(param_1,local_28);
  if (-1 < (int)uVar2) {
    uVar1 = IsEnterpriseAllowed(local_28,param_2,param_3,param_4);
    DeinitSubjectWithTokenPointer(local_28);
    uVar2 = (ulonglong)uVar1;
  }
  return uVar2;
}



===== SrpIsEnterpriseExempt @ 1400053f8 =====

ulonglong SrpIsEnterpriseExempt(longlong *param_1,undefined1 *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong local_res18 [2];
  longlong local_28 [4];
  
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  uVar2 = InitSubjectByTokenPointer(param_1,local_28);
  if (-1 < (int)uVar2) {
    local_res18[0] = 0;
    if (param_2 == (undefined1 *)0x0) {
      uVar1 = 0xc000000d;
    }
    else {
      *param_2 = 0;
      uVar1 = QueryFlags(local_28,local_res18,(undefined8 *)0x0);
      if ((-1 < (int)uVar1) && ((local_res18[0] & 1) != 0)) {
        *param_2 = 1;
      }
    }
    DeinitSubjectWithTokenPointer(local_28);
    uVar2 = (ulonglong)uVar1;
  }
  return uVar2;
}



===== SrpSetEnterpriseContextToken @ 140005474 =====

int SrpSetEnterpriseContextToken
              (longlong param_1,undefined8 param_2,char param_3,undefined8 param_4,longlong param_5,
              longlong param_6)

{
  longlong lVar1;
  int iVar2;
  longlong local_res10 [2];
  undefined1 local_res20 [8];
  
  local_res10[0] = 0;
  local_res20[0] = 0;
  if (((param_1 == 0) || (param_5 == 0)) ||
     ((*(ulonglong *)(param_5 + 8) & 0xffffffffffffff00) != 0)) {
    iVar2 = -0x3ffffff3;
  }
  else {
    iVar2 = CreateAttributesFromContext(param_5,'\0',param_3 == '\0',param_6,local_res10);
    lVar1 = local_res10[0];
    if (-1 < iVar2) {
      iVar2 = SeSetSecurityAttributesTokenEx
                        (param_1,0,0,param_3,&SrpReplaceOperations,local_res10[0],local_res20);
    }
    DeleteAttributes(lVar1);
  }
  return iVar2;
}



===== SrpSetIntentEnterpriseIdToken @ 14000553c =====

int SrpSetIntentEnterpriseIdToken(longlong param_1,undefined8 param_2,undefined2 *param_3)

{
  int iVar1;
  longlong local_res8;
  undefined4 local_res10 [2];
  
  local_res8 = 0;
  local_res10[0] = 4;
  if (param_1 == 0) {
    iVar1 = -0x3ffffff3;
  }
  else {
    iVar1 = CreateAttributesFromIntentEnterpriseId(param_3,&local_res8);
    if (-1 < iVar1) {
      iVar1 = SeSetSecurityAttributesToken(param_1,0,local_res10,local_res8);
    }
    DeleteAttributes(local_res8);
  }
  return iVar1;
}



===== EdppCreateFileObject @ 1400055b4 =====

/* long __cdecl EdppCreateFileObject(unsigned short const * __ptr64,struct _OBJECT_ATTRIBUTES *
   __ptr64,struct _UNICODE_STRING * __ptr64 * __ptr64) */

long __cdecl
EdppCreateFileObject(ushort *param_1,_OBJECT_ATTRIBUTES *param_2,_UNICODE_STRING **param_3)

{
  ushort uVar1;
  wchar_t *_Dst;
  _UNICODE_STRING *p_Var2;
  long lVar3;
  longlong lVar4;
  ulonglong _Size;
  
  lVar3 = 0;
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (param_1[lVar4] != 0);
  uVar1 = ((short)lVar4 + 1) * 2;
  _Size = (ulonglong)(ushort)(uVar1 + 0x18);
  _Dst = (wchar_t *)EdpAuditLibMemAlloc(_Size);
  if (_Dst == (wchar_t *)0x0) {
    lVar3 = -0x3fffffe9;
  }
  else {
    p_Var2 = (_UNICODE_STRING *)EdpAuditLibMemAlloc(0x10);
    memset(_Dst,0,_Size);
    builtin_wcsncpy(_Dst,L"\\DosDevices\\",0xc);
    memmove(_Dst + 0xc,param_1,(ulonglong)uVar1);
    RtlInitUnicodeString(p_Var2,_Dst);
    *(undefined4 *)param_2 = 0x30;
    *(undefined8 *)(param_2 + 8) = 0;
    *(undefined4 *)(param_2 + 0x18) = 0x200;
    *(_UNICODE_STRING **)(param_2 + 0x10) = p_Var2;
    *(undefined8 *)(param_2 + 0x20) = 0;
    *(undefined8 *)(param_2 + 0x28) = 0;
    *param_3 = p_Var2;
  }
  return lVar3;
}



===== CreateFqbnString @ 1400056ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int CreateFqbnString(undefined8 *param_1,undefined8 *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  int iVar3;
  undefined2 *_Dst;
  ushort uVar4;
  undefined1 auStack_88 [32];
  ushort local_68 [4];
  undefined8 *local_60;
  int local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  undefined4 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_88;
  local_58 = *(int *)(param_1 + 1);
  uStack_54 = *(undefined4 *)((longlong)param_1 + 0xc);
  uStack_50 = *(undefined4 *)(param_1 + 2);
  uStack_4c = *(undefined4 *)((longlong)param_1 + 0x14);
  uVar2 = *param_1;
  local_48 = 0;
  local_40 = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  uVar4 = (ushort)(local_58 + 0x32U);
  if ((uVar4 < (ushort)local_58) || (uVar1 = (local_58 + 0x32U & 0xffff) + 0x10, uVar1 < 0x10)) {
    iVar3 = -0x3fffff6b;
  }
  else {
    _Dst = (undefined2 *)ExAllocatePool2(0x42,uVar1,0x41706445);
    if (_Dst == (undefined2 *)0x0) {
      iVar3 = -0x3fffffe9;
    }
    else {
      memset(_Dst,0,(ulonglong)uVar1);
      _Dst[1] = uVar4;
      *(undefined2 **)(_Dst + 4) = _Dst + 8;
      *_Dst = 0;
      local_60 = &local_48;
      local_68[0] = 0;
      local_68[1] = 0xc;
      iVar3 = RtlAppendUnicodeStringToString(_Dst,&local_58);
      if ((-1 < iVar3) && (iVar3 = RtlAppendUnicodeToString(_Dst,L"\\"), -1 < iVar3)) {
        UShortToUnicodeString((ushort)((ulonglong)uVar2 >> 0x30),local_68);
        iVar3 = RtlAppendUnicodeStringToString(_Dst,local_68);
        if ((-1 < iVar3) && (iVar3 = RtlAppendUnicodeToString(_Dst,L"."), -1 < iVar3)) {
          UShortToUnicodeString((ushort)((ulonglong)uVar2 >> 0x20),local_68);
          iVar3 = RtlAppendUnicodeStringToString(_Dst,local_68);
          if ((-1 < iVar3) && (iVar3 = RtlAppendUnicodeToString(_Dst,L"."), -1 < iVar3)) {
            UShortToUnicodeString((ushort)((ulonglong)uVar2 >> 0x10),local_68);
            iVar3 = RtlAppendUnicodeStringToString(_Dst,local_68);
            if ((-1 < iVar3) && (iVar3 = RtlAppendUnicodeToString(_Dst,L"."), -1 < iVar3)) {
              UShortToUnicodeString((ushort)uVar2,local_68);
              iVar3 = RtlAppendUnicodeStringToString(_Dst,local_68);
              if (-1 < iVar3) {
                *param_2 = _Dst;
                return iVar3;
              }
            }
          }
        }
      }
      ExFreePoolWithTag(_Dst,0);
    }
  }
  return iVar3;
}



===== GetAttribute @ 1400058f0 =====

int GetAttribute(longlong *param_1,longlong param_2,ushort param_3,undefined8 *param_4,
                undefined8 *param_5)

{
  longlong lVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  ushort *puVar7;
  undefined8 uVar8;
  ushort uVar9;
  undefined4 local_res10 [4];
  undefined8 *local_res20;
  wchar_t *local_58;
  ulonglong local_50;
  ushort *local_48;
  
  if ((param_2 == 0) || (4 < param_3)) {
    return -0x3ffffff3;
  }
  if (param_4 != (undefined8 *)0x0) {
    *param_4 = 0;
  }
  local_res10[0] = 0x80;
  if (1 < (ushort)(param_3 - 3)) {
    local_res10[0] = 0x100;
  }
  local_res20 = param_4;
  lVar6 = ExAllocatePool2(0x42,local_res10[0],0x41706445);
  while( true ) {
    if (lVar6 == 0) {
      return -0x3fffffe9;
    }
    if (*param_1 == 0) {
      if (param_1[2] == 0) {
        iVar3 = ZwQuerySecurityAttributesToken
                          (param_1[3],param_2,1,lVar6,local_res10[0],local_res10);
      }
      else {
        iVar3 = SeQuerySecurityAttributesTokenAccessInformation();
      }
    }
    else {
      iVar3 = SeQuerySecurityAttributesToken(*param_1,param_2,1,lVar6,local_res10[0]);
    }
    if (-1 < iVar3) break;
    if (iVar3 == -0x3ffffddb) {
      iVar3 = 0;
      goto LAB_140005cba;
    }
    if (iVar3 != -0x3fffffdd) goto LAB_140005cba;
    ExFreePoolWithTag(lVar6,0);
    lVar6 = ExAllocatePool2(0x42,local_res10[0],0x41706445);
  }
  if (((*(int *)(lVar6 + 4) == 0) || (lVar1 = *(longlong *)(lVar6 + 8), *(int *)(lVar1 + 0x18) == 0)
      ) || (puVar2 = *(ushort **)(lVar1 + 0x20), puVar2 == (ushort *)0x0)) goto LAB_140005cba;
  if (param_3 == 0) {
    if ((param_4 != (undefined8 *)0x0) && (*(short *)(lVar1 + 0x10) == 3)) {
      uVar9 = *puVar2 + 2;
      if ((uVar9 < *puVar2) || (uVar4 = uVar9 + 0x10, uVar4 < 0x10)) {
LAB_140005cae:
        iVar3 = -0x3fffff6b;
        goto LAB_140005cba;
      }
      puVar7 = (ushort *)ExAllocatePool2(0x42,uVar4,0x41706445);
      if (puVar7 == (ushort *)0x0) {
LAB_140005abd:
        iVar3 = -0x3fffffe9;
        goto LAB_140005cba;
      }
      uVar9 = *puVar2;
      memset(puVar7 + 8,0,(ulonglong)(ushort)(uVar9 + 2));
      puVar7[1] = uVar9 + 2;
      *puVar7 = 0;
      *(ushort **)(puVar7 + 4) = puVar7 + 8;
      RtlCopyUnicodeString(puVar7,puVar2);
LAB_140005b05:
      iVar3 = 0;
      *param_4 = puVar7;
      goto LAB_140005cba;
    }
  }
  else if (param_3 == 1) {
    if ((param_4 != (undefined8 *)0x0) && (*(short *)(lVar1 + 0x10) == 4)) {
      iVar3 = CreateFqbnString((undefined8 *)puVar2,param_4);
      goto LAB_140005cba;
    }
  }
  else if (param_3 == 3) {
    if ((*(short *)(lVar1 + 0x10) == 2) && (param_5 != (undefined8 *)0x0)) {
      uVar8 = *(undefined8 *)puVar2;
LAB_140005b5e:
      *param_5 = uVar8;
      goto LAB_140005cba;
    }
  }
  else if (param_3 == 4) {
    if ((*(short *)(lVar1 + 0x10) == 2) && (param_5 != (undefined8 *)0x0)) {
      uVar8 = *(undefined8 *)(puVar2 + 4);
      goto LAB_140005b5e;
    }
  }
  else {
    if (param_3 != 2) goto LAB_140005cba;
    if ((*(short *)(lVar1 + 0x10) == 0x10) && (param_4 != (undefined8 *)0x0)) {
      if ((0xffff < *(uint *)(puVar2 + 4)) ||
         (uVar4 = (*(uint *)(puVar2 + 4) & 0xffff) * 4, 0xffff < uVar4)) goto LAB_140005cae;
      uVar9 = (ushort)(uVar4 + 2);
      if (((uVar9 < (ushort)uVar4) || ((ushort)(uVar4 + 4) < uVar9)) ||
         (uVar5 = (uVar4 + 4 & 0xffff) + 0x10, uVar5 < 0x10)) goto LAB_140005cae;
      puVar7 = (ushort *)ExAllocatePool2(0x42,uVar5,0x41706445);
      local_48 = puVar7;
      if (puVar7 == (ushort *)0x0) goto LAB_140005abd;
      local_58 = (wchar_t *)(puVar7 + 8);
      puVar7[1] = uVar9;
      uVar5 = uVar4 + 2 & 0xffff;
      *(wchar_t **)(puVar7 + 4) = local_58;
      *puVar7 = (ushort)uVar4;
      memset(local_58,0,(ulonglong)uVar5);
      uVar4 = 0;
      local_50 = (ulonglong)uVar5;
      if (*(int *)(puVar2 + 4) != 0) {
        do {
          RtlStringCbPrintfExW
                    (local_58,local_50,&local_58,(longlong *)&local_50,0,L"%02x",
                     *(char *)((ulonglong)uVar4 + *(longlong *)puVar2));
          uVar4 = uVar4 + 1;
        } while (uVar4 < *(uint *)(puVar2 + 4));
        puVar7 = local_48;
        param_4 = local_res20;
      }
      goto LAB_140005b05;
    }
  }
  iVar3 = -0x3ffffff3;
LAB_140005cba:
  if (lVar6 == 0) {
    return iVar3;
  }
  ExFreePoolWithTag(lVar6,0);
  return iVar3;
}



===== RtlStringCbPrintfExW @ 140005d00 =====

int RtlStringCbPrintfExW
              (wchar_t *param_1,ulonglong param_2,undefined8 *param_3,longlong *param_4,uint param_5
              ,wchar_t *param_6,char param_7)

{
  int iVar1;
  ulonglong _Count;
  ulonglong uVar2;
  int iVar3;
  ulonglong uVar4;
  wchar_t *pwVar5;
  
  uVar4 = param_2 >> 1;
  iVar3 = 0;
  if ((param_5 & 0x100) == 0) {
    iVar3 = 0;
    if (0x7ffffffe < uVar4 - 1) {
      iVar3 = -0x3ffffff3;
    }
  }
  else if (((param_1 == (wchar_t *)0x0) && (uVar4 != 0)) || (0x7fffffff < uVar4)) {
    iVar3 = -0x3ffffff3;
  }
  if (iVar3 < 0) {
    if (uVar4 == 0) {
      return iVar3;
    }
    *param_1 = L'\0';
    return iVar3;
  }
  if (((param_5 & 0x100) != 0) && (param_6 == (wchar_t *)0x0)) {
    param_6 = L"";
  }
  iVar3 = 0;
  uVar2 = uVar4;
  pwVar5 = param_1;
  if ((param_5 & 0xffffe000) == 0) {
    if (uVar4 == 0) {
      if (*param_6 == L'\0') goto LAB_140005e31;
      iVar3 = (-(uint)(param_1 != (wchar_t *)0x0) & 0xbffffff8) + 0xc000000d;
    }
    else {
      _Count = uVar4 - 1;
      iVar1 = _vsnwprintf(param_1,_Count,param_6,&param_7);
      if (iVar1 < 0) {
LAB_140005eb5:
        iVar3 = -0x7ffffffb;
LAB_140005eba:
        param_1[_Count] = L'\0';
      }
      else {
        uVar2 = (ulonglong)iVar1;
        if (_Count < uVar2) goto LAB_140005eb5;
        if (uVar2 == _Count) goto LAB_140005eba;
        _Count = uVar2;
      }
      uVar2 = uVar4 - _Count;
      pwVar5 = param_1 + _Count;
      if (-1 < iVar3) {
        if (((param_5 >> 9 & 1) != 0) &&
           (uVar4 = (ulonglong)((uint)param_2 & 1) + uVar2 * 2, 2 < uVar4)) {
          memset(pwVar5 + 1,param_5 & 0xff,uVar4 - 2);
        }
        goto LAB_140005e31;
      }
    }
  }
  else {
    iVar3 = -0x3ffffff3;
    if (uVar4 != 0) {
      *param_1 = L'\0';
    }
  }
  if (((param_5 & 0x1c00) != 0) && (param_2 != 0)) {
    if ((uVar4 != 0) && ((param_5 >> 0xc & 1) != 0)) {
      *param_1 = L'\0';
      uVar2 = uVar4;
      pwVar5 = param_1;
    }
    if ((param_5 >> 10 & 1) == 0) {
LAB_140005dfb:
      if (uVar4 == 0) goto LAB_140005e11;
    }
    else {
      memset(param_1,param_5 & 0xff,param_2);
      if ((char)param_5 == '\0') {
        uVar2 = uVar4;
        pwVar5 = param_1;
        goto LAB_140005dfb;
      }
      if (uVar4 == 0) goto LAB_140005e11;
      uVar2 = 1;
      pwVar5 = param_1 + (uVar4 - 1);
      *pwVar5 = L'\0';
    }
    if ((param_5 >> 0xb & 1) != 0) {
      *param_1 = L'\0';
      uVar2 = uVar4;
      pwVar5 = param_1;
    }
  }
LAB_140005e11:
  if (((iVar3 + 0x80000000U & 0x80000000) == 0) && (iVar3 != -0x7ffffffb)) {
    return iVar3;
  }
LAB_140005e31:
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = pwVar5;
  }
  if (param_4 != (longlong *)0x0) {
    *param_4 = uVar2 * 2 + (ulonglong)((uint)param_2 & 1);
  }
  return iVar3;
}



===== SrpGetAttributeFromToken @ 140005f48 =====

void SrpGetAttributeFromToken
               (longlong param_1,longlong param_2,ushort param_3,undefined8 *param_4,
               undefined8 *param_5)

{
  longlong local_28 [5];
  
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = -6;
  if (param_1 != 0) {
    local_28[3] = param_1;
  }
  GetAttribute(local_28,param_2,param_3,param_4,param_5);
  return;
}



===== SrpSetAttributeOnToken @ 140005f90 =====

undefined4
SrpSetAttributeOnToken
          (longlong param_1,undefined2 *param_2,short param_3,longlong param_4,undefined1 param_5)

{
  undefined2 *puVar1;
  undefined4 *puVar2;
  undefined4 unaff_EBX;
  undefined4 local_res8 [2];
  
  local_res8[0] = 4;
  puVar2 = (undefined4 *)0x0;
  if (param_1 == 0) {
    return unaff_EBX;
  }
  if (param_2 == (undefined2 *)0x0) {
    return unaff_EBX;
  }
  puVar1 = (undefined2 *)ExAllocatePool2(0x42,0x28,0x41706445);
  if (puVar1 == (undefined2 *)0x0) {
    return unaff_EBX;
  }
  *(undefined8 *)(puVar1 + 4) = *(undefined8 *)(param_2 + 4);
  *puVar1 = *param_2;
  puVar1[1] = param_2[1];
  if (param_3 == 0) {
    if (param_4 == 0) goto LAB_1400060b5;
    *(undefined4 *)(puVar1 + 10) = 0x43;
    *(undefined4 *)(puVar1 + 8) = 3;
    *(longlong *)(puVar1 + 0x10) = param_4;
LAB_140006065:
    *(undefined4 *)(puVar1 + 0xc) = 1;
  }
  else if (param_3 == 3) {
    *(undefined4 *)(puVar1 + 10) = 0x41;
    *(undefined1 **)(puVar1 + 0x10) = &param_5;
    *(undefined4 *)(puVar1 + 8) = 2;
    goto LAB_140006065;
  }
  puVar2 = (undefined4 *)ExAllocatePool2(0x42,0x10,0x41706445);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = 1;
    puVar2[1] = 1;
    *(undefined2 **)(puVar2 + 2) = puVar1;
    SeSetSecurityAttributesToken(param_1,0,local_res8,puVar2);
  }
LAB_1400060b5:
  ExFreePoolWithTag(puVar1,0);
  if (puVar2 != (undefined4 *)0x0) {
    ExFreePoolWithTag(puVar2,0);
  }
  return unaff_EBX;
}



===== UShortToUnicodeString @ 140006104 =====

void UShortToUnicodeString(ushort param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  
  *param_2 = 0;
  iVar2 = 0;
  if (param_1 == 0) {
    iVar2 = 1;
    **(undefined2 **)(param_2 + 4) = 0x30;
    *param_2 = *param_2 + 2;
  }
  else {
    uVar1 = param_1;
    do {
      iVar2 = iVar2 + 1;
      uVar1 = uVar1 / 10;
    } while (uVar1 != 0);
    do {
      *(ushort *)
       (*(longlong *)(param_2 + 4) + -2 + ((longlong)iVar2 - (ulonglong)(*param_2 >> 1)) * 2) =
           param_1 % 10 + 0x30;
      *param_2 = *param_2 + 2;
      param_1 = param_1 / 10;
    } while (param_1 != 0);
  }
  *(undefined2 *)(*(longlong *)(param_2 + 4) + (longlong)iVar2 * 2) = 0;
  return;
}



===== SrpGetAppUniqueIdFromToken @ 1400061c4 =====

ulonglong SrpGetAppUniqueIdFromToken(longlong param_1,longlong *param_2)

{
  ulonglong uVar1;
  undefined8 local_38;
  wchar_t *local_30;
  undefined8 local_28;
  wchar_t *local_20;
  undefined8 local_18;
  wchar_t *local_10;
  
  local_38 = 0x1a0018;
  local_30 = L"APPID://FQBN";
  local_20 = L"APPID://PATH";
  local_10 = L"APPID://SHA256HASH";
  local_28 = 0x1a0018;
  local_18 = 0x260024;
  if (param_2 == (longlong *)0x0) {
    uVar1 = 0xc000000d;
  }
  else {
    uVar1 = SrpGetAttributeFromToken(param_1,(longlong)&local_38,1,param_2,(undefined8 *)0x0);
    if ((-1 < (int)uVar1) && (*param_2 == 0)) {
      uVar1 = SrpGetAttributeFromToken(param_1,(longlong)&local_28,0,param_2,(undefined8 *)0x0);
      if ((-1 < (int)uVar1) && (*param_2 == 0)) {
        uVar1 = SrpGetAttributeFromToken(param_1,(longlong)&local_18,2,param_2,(undefined8 *)0x0);
        if ((-1 < (int)uVar1) && (uVar1 = uVar1 & 0xffffffff, *param_2 == 0)) {
          uVar1 = 0xc0000225;
        }
      }
    }
  }
  return uVar1;
}



===== SrpGetProcessUniqueIdFromToken @ 1400062a8 =====

void SrpGetProcessUniqueIdFromToken(longlong param_1,undefined8 *param_2)

{
  undefined8 local_18;
  wchar_t *local_10;
  
  local_10 = L"TSA://ProcUnique";
  local_18 = 0x220020;
  SrpGetAttributeFromToken(param_1,(longlong)&local_18,4,(undefined8 *)0x0,param_2);
  return;
}



===== SrpSetInheritedAppUniqueIdOnToken @ 1400062e4 =====

void SrpSetInheritedAppUniqueIdOnToken(longlong param_1,longlong param_2)

{
  SrpSetAttributeOnToken(param_1,(undefined2 *)&InheritedAppUniqueId,0,param_2,0);
  return;
}



===== SrpSetInheritedProcessUniqueIdOnToken @ 14000630c =====

void SrpSetInheritedProcessUniqueIdOnToken(longlong param_1,undefined1 param_2)

{
  SrpSetAttributeOnToken(param_1,(undefined2 *)&InheritedProcessUniqueId,3,0,param_2);
  return;
}



===== _guard_check_icall @ 140006340 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140006358 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000637c =====

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



===== __GSHandlerCheck_SEH @ 1400063e4 =====

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



===== __cpu_features_init @ 140006480 =====

/* WARNING: Removing unreachable block (ram,0x0001400064ea) */
/* WARNING: Removing unreachable block (ram,0x000140006499) */
/* WARNING: Removing unreachable block (ram,0x00014000648a) */

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



===== __security_check_cookie @ 140006550 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140006590 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1400065c0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001400065c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1400065f0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 140006620 =====

int __cdecl memcmp(void *_Buf1,void *_Buf2,size_t _Size)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  bool bVar5;
  
  lVar3 = (longlong)_Buf2 - (longlong)_Buf1;
  if (7 < _Size) {
    for (; ((ulonglong)_Buf1 & 7) != 0; _Buf1 = (void *)((longlong)_Buf1 + 1)) {
      bVar5 = (byte)*(ulonglong *)_Buf1 < *(byte *)((longlong)_Buf1 + lVar3);
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_140006663;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_1400066d4;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_1400066d0:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1400066d4;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_1400066cc:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1400066d0;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1400066cc;
          }
          _Buf1 = (void *)((longlong)_Buf1 + 0x20);
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
        _Size = _Size & 0x1f;
      }
      uVar4 = _Size >> 3;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) {
LAB_1400066d4:
            uVar4 = *(ulonglong *)(lVar3 + (longlong)_Buf1);
            uVar1 = (uint)((uVar2 >> 0x38 | (uVar2 & 0xff000000000000) >> 0x28 |
                            (uVar2 & 0xff0000000000) >> 0x18 | (uVar2 & 0xff00000000) >> 8 |
                            (uVar2 & 0xff000000) << 8 | (uVar2 & 0xff0000) << 0x18 |
                            (uVar2 & 0xff00) << 0x28 | uVar2 << 0x38) <
                          (uVar4 >> 0x38 | (uVar4 & 0xff000000000000) >> 0x28 |
                           (uVar4 & 0xff0000000000) >> 0x18 | (uVar4 & 0xff00000000) >> 8 |
                           (uVar4 & 0xff000000) << 8 | (uVar4 & 0xff0000) << 0x18 |
                           (uVar4 & 0xff00) << 0x28 | uVar4 << 0x38));
            return (1 - uVar1) - (uint)(uVar1 != 0);
          }
          _Buf1 = (void *)((longlong)_Buf1 + 8);
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
        _Size = _Size & 7;
      }
    }
  }
  while( true ) {
    if (_Size == 0) {
      return 0;
    }
    bVar5 = (byte)*(ulonglong *)_Buf1 < *(byte *)((longlong)_Buf1 + lVar3);
    if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) break;
    _Buf1 = (void *)((longlong)_Buf1 + 1);
    _Size = _Size - 1;
  }
LAB_140006663:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 140006740 =====

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



===== memset @ 140006a40 =====

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



===== __memset_repmovs @ 140006b80 =====

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



===== __memset_query @ 140006c00 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140006c80 =====

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



===== __memset_spec_ermsb_repmovsb @ 140006dc0 =====

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



===== __memset_spec_plain @ 140006e40 =====

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



===== AiVerifyFile$filt$0 @ 140006f3d =====

void AiVerifyFile_filt_0(undefined8 *param_1)

{
  I_RpcExceptionFilter(*(ulong *)*param_1);
  return;
}



===== AiEvaluateAppLockerPolicyClass @ 14001e008 =====

undefined8
AiEvaluateAppLockerPolicyClass
          (undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4,uint *param_5)

{
  undefined8 uVar1;
  
  if (param_3 == 0) {
    uVar1 = 0xc00000f1;
  }
  else if (param_4 == 0) {
    uVar1 = 0xc00000f2;
  }
  else if (param_5 == (uint *)0x0) {
    uVar1 = 0xc00000f3;
  }
  else {
    SrppPluginAccessCheck(param_4,*(longlong *)(param_3 + 0x18),param_5);
    uVar1 = 0;
  }
  return uVar1;
}



===== AiResultIsExplicitDeny @ 14001e054 =====

undefined8 AiResultIsExplicitDeny(int *param_1)

{
  ulonglong in_RAX;
  undefined1 uVar1;
  
  uVar1 = 0;
  if ((*param_1 != 0) &&
     (in_RAX = (ulonglong)(param_1[1] & 0xff0000U), (param_1[1] & 0xff0000U) == 0x20000)) {
    uVar1 = 1;
  }
  return CONCAT71((int7)(in_RAX >> 8),uVar1);
}



===== AipCleanupPluginsCallback @ 14001e080 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AipCleanupPluginsCallback(longlong param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 local_res8 [4];
  
  local_res8[0] = *param_2;
  if (*(code **)(param_1 + 0x40) != (code *)0x0) {
    iVar1 = (**(code **)(param_1 + 0x40))(local_res8);
    if (-1 < iVar1) {
      *param_2 = 0;
    }
  }
  return;
}



===== AipForEachPlugin @ 14001e0bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 AipForEachPlugin(undefined *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  do {
    uVar1 = (*(code *)param_1)(&DAT_140008000 + uVar3 * 0x48,&DAT_140018318 + uVar3 * 8,param_2);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    uVar2 = (int)uVar3 + 1;
    uVar3 = (ulonglong)uVar2;
  } while (uVar2 < 4);
  return 0;
}



===== AiAddProcToOriginList @ 14001e130 =====

undefined8 AiAddProcToOriginList(undefined8 param_1,void *param_2,uint param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  puVar1 = (undefined8 *)AipAllocTrackOriginProcess(param_1,param_2,param_3);
  if (puVar1 == (undefined8 *)0x0) {
    uVar2 = 0xc0000017;
  }
  else {
    ExEnterCriticalRegionAndAcquireResourceExclusive(&DAT_1400188a0);
    AipAddProcToOriginListLocked(puVar1);
    ExReleaseResourceAndLeaveCriticalRegion(&DAT_1400188a0);
    uVar2 = 0;
  }
  return uVar2;
}



===== AiAddProcToTrackedList @ 14001e188 =====

undefined8 AiAddProcToTrackedList(undefined8 param_1)

{
  code *pcVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar2 = (undefined8 *)ExAllocatePool2(0x102,0x28,0x44497041);
  if (puVar2 == (undefined8 *)0x0) {
    uVar3 = 0xc0000017;
  }
  else {
    puVar2[2] = param_1;
    ExAcquireResourceExclusiveLite(&DAT_1400188a0,1);
    puVar5 = auStack_28;
    puVar4 = &DAT_140018870;
    if ((undefined8 *)*DAT_140018878 != &DAT_140018870) {
      puVar4 = (undefined8 *)0x3;
      pcVar1 = (code *)swi(0x29);
      DAT_140018878 = (undefined8 *)(*pcVar1)();
      puVar5 = auStack_20;
    }
    *puVar2 = puVar4;
    puVar2[1] = DAT_140018878;
    *DAT_140018878 = puVar2;
    if ((DAT_140018908 == (undefined8 *)0x0) && ((undefined8 **)DAT_140018860 != &DAT_140018860)) {
      LOCK();
      DAT_140018908 = &DAT_140018860;
      UNLOCK();
    }
    *(undefined8 *)(puVar5 + -8) = 0x14001e233;
    DAT_140018878 = puVar2;
    ExReleaseResourceLite(&DAT_1400188a0);
    uVar3 = 0;
  }
  return uVar3;
}



===== AiAddProcToTrackedSessionList @ 14001e24c =====

undefined8 AiAddProcToTrackedSessionList(undefined8 param_1,int param_2,longlong param_3)

{
  code *pcVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined4 in_register_00000014;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined8 uVar8;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  puVar3 = (undefined8 *)0x0;
  uVar8 = 0;
  ExAcquireResourceExclusiveLite
            (&DAT_1400188a0,CONCAT71((int7)(CONCAT44(in_register_00000014,param_2) >> 8),1));
  puVar5 = auStack_38;
  puVar6 = auStack_38;
  puVar7 = auStack_38;
  puVar4 = DAT_140018880;
  if ((undefined8 **)DAT_140018880 != &DAT_140018880) {
    do {
      iVar2 = memcmp((void *)(param_3 + 0x20),(void *)(puVar4[4] + 0x20),0x10);
      if (iVar2 == 0) {
        puVar3 = (undefined8 *)ExAllocatePool2(0x102,0x28,0x44497041);
        if (puVar3 == (undefined8 *)0x0) {
LAB_14001e2ed:
          uVar8 = 0xc0000017;
          puVar7 = auStack_38;
          goto LAB_14001e367;
        }
        puVar3[2] = param_1;
        puVar3[3] = puVar4[4];
        *(undefined4 *)(puVar3 + 4) = *(undefined4 *)(puVar4 + 5);
        if (param_2 != 0) {
          puVar4 = (undefined8 *)
                   AipAllocTrackOriginProcess(param_1,(void *)puVar4[4],*(uint *)(puVar4 + 5));
          if (puVar4 == (undefined8 *)0x0) goto LAB_14001e2ed;
          AipAddProcToOriginListLocked(puVar4);
        }
        puVar4 = &DAT_140018890;
        if ((undefined8 *)*DAT_140018898 != &DAT_140018890) {
          puVar4 = (undefined8 *)0x3;
          pcVar1 = (code *)swi(0x29);
          DAT_140018898 = (undefined8 *)(*pcVar1)();
          puVar5 = auStack_30;
        }
        *puVar3 = puVar4;
        puVar3[1] = DAT_140018898;
        *DAT_140018898 = puVar3;
        puVar6 = puVar5;
        DAT_140018898 = puVar3;
        if (DAT_140018910 == (undefined8 *)0x0) {
          LOCK();
          DAT_140018910 = &DAT_140018880;
          UNLOCK();
        }
        break;
      }
      puVar4 = (undefined8 *)*puVar4;
    } while ((undefined8 **)puVar4 != &DAT_140018880);
    puVar3 = (undefined8 *)0x0;
    uVar8 = 0;
    puVar7 = puVar6;
  }
LAB_14001e367:
  *(undefined8 *)(puVar7 + -8) = 0x14001e375;
  ExReleaseResourceLite(&DAT_1400188a0);
  if (puVar3 != (undefined8 *)0x0) {
    *(undefined8 *)(puVar7 + -8) = 0x14001e38b;
    ExFreePoolWithTag(puVar3,0);
  }
  return uVar8;
}



===== AiAddSessionToOriginList @ 14001e3b8 =====

undefined8 AiAddSessionToOriginList(undefined8 param_1,void *param_2,uint param_3)

{
  code *pcVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined1 *puVar6;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  ExAcquireResourceExclusiveLite(&DAT_1400188a0,1);
  puVar6 = auStack_38;
  uVar5 = 0;
  puVar3 = DAT_140018880;
  do {
    if ((undefined8 **)puVar3 == &DAT_140018880) {
      puVar3 = (undefined8 *)AipAllocTrackOriginProcess(param_1,param_2,param_3);
      if (puVar3 == (undefined8 *)0x0) {
        uVar5 = 0xc0000017;
        puVar6 = auStack_38;
      }
      else {
        puVar4 = DAT_140018888;
        if ((undefined8 **)*DAT_140018888 != &DAT_140018880) {
          puVar4 = (undefined8 *)0x3;
          pcVar1 = (code *)swi(0x29);
          puVar3 = (undefined8 *)(*pcVar1)();
          puVar6 = auStack_30;
        }
        *puVar3 = &DAT_140018880;
        puVar3[1] = puVar4;
        *puVar4 = puVar3;
        if ((DAT_140018910 == (undefined8 *)0x0) && ((undefined8 **)DAT_140018890 != &DAT_140018890)
           ) {
          LOCK();
          DAT_140018910 = &DAT_140018880;
          UNLOCK();
        }
        DAT_140018888 = puVar3;
        if (DAT_140018918 == (undefined8 *)0x0) {
          LOCK();
          DAT_140018918 = &DAT_140018880;
          UNLOCK();
        }
      }
LAB_14001e49e:
      *(undefined8 *)(puVar6 + -8) = 0x14001e4ac;
      ExReleaseResourceLite(&DAT_1400188a0);
      return uVar5;
    }
    iVar2 = memcmp((void *)((longlong)param_2 + 0x20),(void *)(puVar3[4] + 0x20),0x10);
    if (iVar2 == 0) {
      *(int *)((longlong)puVar3 + 0x2c) = *(int *)((longlong)puVar3 + 0x2c) + 1;
      puVar6 = auStack_38;
      goto LAB_14001e49e;
    }
    puVar3 = (undefined8 *)*puVar3;
  } while( true );
}



===== AiAddUninstallStringToUninstallStringEaData @ 14001e4dc =====

ulonglong AiAddUninstallStringToUninstallStringEaData
                    (ushort *param_1,void *param_2,uint param_3,undefined8 *param_4,uint *param_5)

{
  ulonglong uVar1;
  void *_Dst;
  uint uVar2;
  char local_res10 [8];
  ulonglong local_38;
  longlong lStack_30;
  
  lStack_30 = (longlong)param_2 + 0x28;
  local_res10[0] = '\0';
  local_38 = (ulonglong)
             CONCAT22(*(undefined2 *)((longlong)param_2 + 0x24),
                      *(undefined2 *)((longlong)param_2 + 0x24));
  uVar1 = AiIsStringNoQuotePrefixedByDelimitedUninstallString(param_1,&local_38,local_res10);
  if (-1 < (int)uVar1) {
    if (local_res10[0] == '\0') {
      uVar2 = *param_1 + 2 + param_3;
      _Dst = (void *)AiAlloc((ulonglong)uVar2);
      if (_Dst == (void *)0x0) {
        uVar1 = 0xc0000017;
      }
      else {
        memmove(_Dst,param_2,(ulonglong)param_3);
        *(undefined2 *)((ulonglong)param_3 + (longlong)_Dst) = 0;
        memmove((void *)((ulonglong)(param_3 + 2) + (longlong)_Dst),*(void **)(param_1 + 4),
                (ulonglong)*param_1);
        *param_4 = _Dst;
        *param_5 = uVar2;
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0xc0000718;
    }
  }
  return uVar1;
}



===== AiAllocUninstallStringData @ 14001e5c0 =====

longlong AiAllocUninstallStringData(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = ExAllocatePool2(0x102,0x30,0x44497041);
  if (lVar2 != 0) {
    iVar1 = RtlDuplicateUnicodeString(1,param_1,lVar2 + 0x10);
    if (-1 < iVar1) {
      iVar1 = RtlDuplicateUnicodeString(1,param_2,lVar2 + 0x20);
      if (-1 < iVar1) {
        *(longlong *)(lVar2 + 8) = lVar2;
        *(longlong *)lVar2 = lVar2;
        return lVar2;
      }
      RtlFreeUnicodeString(lVar2 + 0x10);
    }
    ExFreePoolWithTag(lVar2,0);
  }
  return 0;
}



===== AiAllocUninstallStringEaData @ 14001e680 =====

undefined8
AiAllocUninstallStringEaData(ushort *param_1,longlong param_2,undefined8 *param_3,uint *param_4)

{
  ushort uVar1;
  undefined4 *_Dst;
  undefined8 uVar2;
  uint uVar3;
  
  uVar3 = *param_1 + 0x2c;
  _Dst = (undefined4 *)AiAlloc((ulonglong)uVar3);
  if (_Dst == (undefined4 *)0x0) {
    uVar2 = 0xc0000017;
  }
  else {
    memset(_Dst,0,(ulonglong)uVar3);
    *_Dst = 1;
    uVar2 = *(undefined8 *)(param_2 + 0x18);
    *(undefined8 *)(_Dst + 1) = *(undefined8 *)(param_2 + 0x10);
    *(undefined8 *)(_Dst + 3) = uVar2;
    uVar2 = *(undefined8 *)(param_2 + 0x28);
    *(undefined8 *)(_Dst + 5) = *(undefined8 *)(param_2 + 0x20);
    *(undefined8 *)(_Dst + 7) = uVar2;
    memmove(_Dst + 10,*(void **)(param_1 + 4),(ulonglong)*param_1);
    uVar1 = *param_1;
    *param_3 = _Dst;
    *param_4 = uVar3;
    *(undefined2 *)((longlong)_Dst + (ulonglong)(uVar1 >> 1) * 2 + 0x28) = 10;
    _Dst[9] = (uint)*param_1;
    uVar2 = 0;
  }
  return uVar2;
}



===== AiCopyUnicodeStringWithoutQuotations @ 14001e744 =====

undefined8 AiCopyUnicodeStringWithoutQuotations(ushort *param_1,short *param_2)

{
  short *psVar1;
  short *psVar2;
  undefined8 uVar3;
  short *psVar4;
  short sVar5;
  short *psVar6;
  
  sVar5 = 0;
  psVar2 = (short *)AiAlloc((ulonglong)*param_1);
  if (psVar2 == (short *)0x0) {
    uVar3 = 0xc0000017;
  }
  else {
    psVar4 = *(short **)(param_1 + 4);
    psVar1 = psVar4 + (*param_1 >> 1);
    psVar6 = psVar2;
    for (; psVar4 < psVar1; psVar4 = psVar4 + 1) {
      if (*psVar4 != 0x22) {
        *psVar6 = *psVar4;
        psVar6 = psVar6 + 1;
        sVar5 = sVar5 + 2;
      }
    }
    *(short **)(param_2 + 4) = psVar2;
    *param_2 = sVar5;
    param_2[1] = *param_1;
    uVar3 = 0;
  }
  return uVar3;
}



===== AiEnsureServiceRunning @ 14001e7cc =====

void AiEnsureServiceRunning(char param_1)

{
  int iVar1;
  undefined4 local_res10 [2];
  longlong local_res18 [2];
  undefined8 local_58;
  undefined8 local_50;
  wchar_t *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 *local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined8 uStack_18;
  
  local_res18[1] = 0;
  local_res18[0] = 0;
  local_58 = 0xffffffffff676980;
  local_50 = 0x520050;
  local_48 = L"\\BaseNamedObjects\\SC_AutoStartPhase1Done";
  if (DAT_140018858 == 0) {
    local_24 = 0;
    local_30 = &local_50;
    local_38 = 0;
    local_40 = 0x30;
    local_20 = 0;
    uStack_18 = 0;
    local_28 = 0x200;
    iVar1 = ZwOpenEvent(local_res18,1,&local_40);
    if (-1 < iVar1) {
      if (local_res18[0] == 0) {
        return;
      }
      iVar1 = ZwWaitForSingleObject(local_res18[0],1,local_res18 + 1);
      if (((iVar1 == 0) && (AiLogTriggerServiceStartEvent(), param_1 != '\0')) &&
         (iVar1 = ZwWaitForSingleObject(DAT_140018240,1,&local_58), iVar1 < 0)) {
        local_res10[0] = 0;
        ZwSetEvent(DAT_140018240,local_res10);
      }
    }
    if (local_res18[0] != 0) {
      ZwClose();
    }
  }
  return;
}



===== AiGetUninstallStringEa @ 14001e8e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int AiGetUninstallStringEa(undefined8 param_1,longlong *param_2,uint *param_3,longlong *param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined1 auStack_e8 [32];
  undefined4 *local_c8;
  undefined4 local_c0;
  undefined8 local_b8;
  undefined1 local_b0;
  uint *local_a8;
  uint local_98 [2];
  longlong local_90;
  longlong local_88;
  undefined4 local_80 [12];
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStack_e8;
  local_98[0] = 0;
  lVar5 = 0;
  local_90 = 0;
  uVar7 = 0x264;
  bVar1 = false;
  AiAddEaToQueryBuffer("$Kernel.Smartlocker.UninstallStrings",&local_90,local_80,&local_88);
  *param_4 = 0;
LAB_14001e94e:
  do {
    if (lVar5 != 0) {
      ExFreePoolWithTag(lVar5,0);
    }
    lVar5 = AiAlloc(uVar7);
    if (lVar5 == 0) {
      return -0x3fffffe9;
    }
    local_a8 = local_98;
    local_b0 = 0;
    local_c8 = local_80;
    local_b8 = 0;
    local_c0 = 0x2c;
    iVar2 = FsRtlQueryKernelEaFile(param_1,lVar5,uVar7,0);
    if (iVar2 < 0) goto LAB_14001ea48;
    iVar3 = _stricmp((char *)(lVar5 + 8),"$Kernel.Smartlocker.UninstallStrings");
    if (iVar3 == 0) {
      if ((0x2b < *(ushort *)(lVar5 + 6)) && (0x87 < local_98[0])) {
        lVar6 = (ulonglong)*(byte *)(lVar5 + 5) + 9 + lVar5;
        uVar4 = *(int *)(lVar6 + 0x24) + 0x5a;
        if (uVar4 < 0x5c) {
          iVar2 = -0x3fffff6b;
          goto LAB_14001ea48;
        }
        if (uVar4 <= (uint)uVar7) {
          *param_2 = lVar6;
          iVar2 = 0;
          *param_3 = (uint)*(ushort *)(lVar5 + 6);
          *param_4 = lVar5;
          goto LAB_14001ea5d;
        }
        if (bVar1) {
          iVar2 = -0x3fffffdd;
          goto LAB_14001ea48;
        }
        bVar1 = true;
        uVar7 = (ulonglong)uVar4;
        goto LAB_14001e94e;
      }
      *param_2 = 0;
      iVar2 = -0x3ffffddb;
      *param_3 = 0;
    }
    if (!bVar1) {
LAB_14001ea48:
      ExFreePoolWithTag(lVar5,0);
      if (-1 < iVar2) {
LAB_14001ea5d:
        if ((*param_2 == 0) || (*param_3 == 0)) {
          iVar2 = -0x3ffffddb;
        }
      }
      return iVar2;
    }
  } while( true );
}



===== AiIsStringNoQuotePrefixedByDelimitedUninstallString @ 14001eaa4 =====

ulonglong AiIsStringNoQuotePrefixedByDelimitedUninstallString
                    (ushort *param_1,undefined8 *param_2,char *param_3)

{
  undefined1 auVar1 [16];
  char cVar2;
  ushort uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  char cVar6;
  ushort local_res10 [4];
  undefined8 local_78;
  longlong lStack_70;
  ushort local_68;
  undefined6 uStack_66;
  longlong lStack_60;
  undefined1 local_58 [16];
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  longlong lStack_30;
  
  lStack_60 = param_2[1];
  local_68 = (ushort)*param_2;
  uStack_66 = (undefined6)((ulonglong)*param_2 >> 0x10);
  cVar6 = '\0';
  local_58 = ZEXT816(0);
  local_38 = 0;
  lStack_30 = 0;
  local_48 = 0;
  lStack_40 = 0;
  uVar4 = AiCopyUnicodeStringWithoutQuotations(param_1,(short *)&local_38);
  uVar5 = uVar4 & 0xffffffff;
  if (-1 < (int)uVar4) {
    do {
      if (local_68 == 0) break;
      local_res10[0] = 0;
      local_78 = 0;
      lStack_70 = 0;
      uVar4 = AiRtlFindCharInUnicodeString
                        (0,&local_68,(ushort *)&DAT_140008248,(short *)local_res10);
      uVar5 = uVar4 & 0xffffffff;
      if ((int)uVar4 == -0x3ffffddb) {
        local_58._2_6_ = uStack_66;
        local_58._0_2_ = local_68;
        local_58._8_8_ = lStack_60;
        local_68 = (ushort)local_78;
        lStack_60 = lStack_70;
        uStack_66 = local_78._2_6_;
      }
      else {
        if (-1 < (int)uVar4) {
          auVar1._2_6_ = uStack_66;
          auVar1._0_2_ = local_68;
          auVar1._8_8_ = lStack_60;
          local_58._2_14_ = auVar1._2_14_;
          local_58._0_2_ = local_res10[0] - 2;
          lStack_70 = lStack_60 + (ulonglong)(local_res10[0] >> 1) * 2;
          local_78._0_4_ = CONCAT22((short)uStack_66 - local_res10[0],local_68 - local_res10[0]);
          if ((ushort)(local_68 - local_res10[0]) != 0) {
            uVar4 = AiRtlFindCharInUnicodeString
                              (2,(ushort *)&local_78,(ushort *)&DAT_140008248,(short *)local_res10);
            uVar5 = uVar4 & 0xffffffff;
            if ((int)uVar4 < 0) {
              local_78 = local_78 & 0xffffffffffff0000;
              uVar5 = 0;
            }
            else {
              uVar3 = local_res10[0] - 2;
              local_78._0_4_ = CONCAT22(local_78._2_2_ - uVar3,(ushort)local_78 - uVar3);
              lStack_70 = lStack_70 + (ulonglong)(uVar3 >> 1) * 2;
            }
          }
          local_68 = (ushort)local_78;
          uStack_66 = (undefined6)(local_78 >> 0x10);
          lStack_60 = lStack_70;
        }
        if ((int)uVar5 < 0) goto LAB_14001ec64;
      }
      uVar4 = AiCopyUnicodeStringWithoutQuotations((ushort *)local_58,(short *)&local_48);
      uVar5 = uVar4 & 0xffffffff;
      if ((int)uVar4 < 0) goto LAB_14001ec64;
      cVar2 = RtlPrefixUnicodeString(&local_48,&local_38,1);
      if (cVar2 != '\0') {
        cVar6 = '\x01';
      }
      if (lStack_40 != 0) {
        ExFreePoolWithTag(lStack_40,0);
      }
    } while (cVar6 == '\0');
    *param_3 = cVar6;
    uVar5 = 0;
  }
LAB_14001ec64:
  if (lStack_30 != 0) {
    ExFreePoolWithTag(lStack_30,0);
  }
  return uVar5;
}



===== AiOpenFile @ 14001eca0 =====

int AiOpenFile(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  uint uVar2;
  undefined8 local_res8;
  undefined8 local_res18 [2];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res8 = 0;
  local_2c = 0;
  local_40 = 0;
  local_48 = 0x30;
  uVar2 = 0;
  local_30 = 0x240;
  local_58 = 0;
  uStack_50 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_res18[0] = 0xffffffffff676980;
  local_38 = param_1;
  do {
    iVar1 = ZwOpenFile(&local_res8,0x100018,&local_48,&local_58,7,0x20);
    if (iVar1 != -0x3fffffbd) break;
    KeDelayExecutionThread(0,0,local_res18);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 10);
  if (-1 < iVar1) {
    *param_2 = local_res8;
  }
  return iVar1;
}



===== AiParseAndTagUninstallerFromUninstallString @ 14001ed64 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AiParseAndTagUninstallerFromUninstallString(longlong param_1,longlong param_2)

{
  short *psVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  short *psVar5;
  ulonglong uVar6;
  ushort uVar7;
  void *pvVar8;
  longlong lVar9;
  uint uVar10;
  undefined8 uVar11;
  longlong lVar12;
  longlong lVar13;
  undefined4 uVar14;
  undefined1 auStackY_178 [32];
  ushort local_148 [2];
  uint local_144 [3];
  undefined8 local_138;
  undefined8 uStack_130;
  uint local_128 [2];
  void *local_120;
  wchar_t local_118;
  short sStack_116;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  longlong local_108;
  longlong local_100;
  ulonglong local_f8;
  short *psStack_f0;
  longlong local_e8;
  void *local_e0;
  longlong local_d8;
  ushort *local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  uint local_b0;
  undefined4 local_ac;
  uint *local_a8;
  undefined8 local_a0;
  short *local_98;
  uint local_90;
  undefined4 local_8c;
  uint *local_88;
  undefined8 local_80;
  undefined8 local_78;
  uint local_70;
  undefined4 local_6c;
  longlong local_68;
  undefined8 local_60;
  longlong local_58;
  undefined8 local_50;
  void **local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_178;
  local_108 = 0;
  lVar9 = -1;
  local_148[0] = 0;
  local_138 = 0;
  uStack_130 = (short *)0x0;
  pvVar8 = (void *)0x0;
  uVar10 = *(uint *)(param_1 + 0x10);
  uStack_114 = *(undefined4 *)(param_1 + 0x14);
  uStack_110 = *(undefined4 *)(param_1 + 0x18);
  uStack_10c = *(undefined4 *)(param_1 + 0x1c);
  psVar1 = *(short **)(param_1 + 0x18);
  local_100 = -1;
  local_e0 = (void *)0x0;
  uVar6 = (ulonglong)uVar10;
  lVar13 = 0;
  local_120 = (void *)0x0;
  lVar12 = 0;
  local_128[0] = 0;
  local_144[0] = 0;
  iVar3 = 0;
  local_118 = (wchar_t)uVar10;
  sStack_116 = (short)(uVar10 >> 0x10);
  psVar5 = (short *)0x0;
  local_f8 = 0;
  psStack_f0 = (short *)0x0;
  local_d8 = param_1;
  if ((ushort)local_118 < 4) goto LAB_14001f065;
  while (uVar7 = (ushort)uVar6, *(short *)((longlong)psVar1 + ((uVar6 & 0xfffe) - 2)) == 0) {
    local_118 = uVar7 + L'\xfffe';
    uVar6 = (ulonglong)(ushort)local_118;
  }
  if (uVar7 < 4) goto LAB_14001f065;
  if (*psVar1 == 0x22) {
    uStack_130 = psVar1 + 1;
    local_138 = (ulonglong)CONCAT22(sStack_116 + -2,uVar7 - 2);
    uVar4 = AiRtlFindCharInUnicodeString
                      (0,(ushort *)&local_138,(ushort *)&DAT_140008238,(short *)local_148);
    iVar3 = (int)uVar4;
    if (iVar3 < 0) goto LAB_14001f065;
LAB_14001eeba:
    local_138 = CONCAT62(local_138._2_6_,local_148[0] - 2);
  }
  else {
    cVar2 = RtlSuffixUnicodeString
                      (&DAT_140008228,&local_118,CONCAT71((int7)((ulonglong)psVar1 >> 8),1));
    if (cVar2 == '\0') {
      uVar4 = AiRtlFindCharInUnicodeString
                        (0,(ushort *)&local_118,(ushort *)&DAT_140008218,(short *)local_148);
      if (-1 < (int)uVar4) {
        local_138 = CONCAT44(uStack_114,CONCAT22(sStack_116,local_118));
        uStack_130 = (short *)CONCAT44(uStack_10c,uStack_110);
        goto LAB_14001eeba;
      }
      if ((int)uVar4 == -0x3ffffddb) goto LAB_14001eed1;
    }
    else {
LAB_14001eed1:
      local_138 = CONCAT44(uStack_114,CONCAT22(sStack_116,local_118));
      uStack_130 = (short *)CONCAT44(uStack_10c,uStack_110);
    }
  }
  cVar2 = RtlPrefixUnicodeString(&DAT_140008208,&local_138);
  if (cVar2 == '\0') {
    cVar2 = RtlPrefixUnicodeString(&DAT_1400081e8,&local_138);
    if (cVar2 != '\0') {
      uVar10 = 0x440042;
      uVar14 = 0x40009540;
      goto LAB_14001ef2a;
    }
    uVar10 = (uint)(ushort)local_138;
    psVar5 = (short *)AiAlloc((ulonglong)(uVar10 + 0x18));
    if (psVar5 == (short *)0x0) {
      iVar3 = -0x3fffffe9;
      goto LAB_14001f065;
    }
    uVar6 = local_f8 >> 0x20;
    local_f8._0_4_ = (uVar10 + 0x18) * 0x10000;
    local_f8 = CONCAT44((int)uVar6,(int)local_f8);
    psStack_f0 = psVar5;
    RtlCopyUnicodeString(&local_f8,&DAT_1400081c8);
    RtlAppendUnicodeStringToString(&local_f8,&local_138);
    local_138 = local_f8;
    uStack_130 = psStack_f0;
  }
  else {
    uVar10 = 0x420040;
    uVar14 = 0x400094d0;
LAB_14001ef2a:
    local_138 = (ulonglong)uVar10;
    uStack_130 = (short *)CONCAT44(1,uVar14);
  }
  iVar3 = AiOpenFile(&local_138,&local_100);
  lVar9 = local_100;
  if (-1 < iVar3) {
    local_e8 = 0;
    iVar3 = ObReferenceObjectByHandle(local_100,1);
    lVar12 = local_e8;
    if (-1 < iVar3) {
      iVar3 = AiGetUninstallStringEa(local_e8,(longlong *)&local_e0,local_128,&local_108);
      if (iVar3 < 0) {
        uVar4 = AiAllocUninstallStringEaData((ushort *)&local_118,param_2,&local_120,local_144);
        iVar3 = (int)uVar4;
      }
      else {
        uVar6 = AiAddUninstallStringToUninstallStringEaData
                          ((ushort *)&local_118,local_e0,local_128[0],&local_120,local_144);
        iVar3 = (int)uVar6;
      }
      pvVar8 = local_120;
      if (-1 < iVar3) {
        iVar3 = AiSetUninstallStringEa(lVar12,local_120,local_144[0]);
      }
      lVar13 = local_108;
    }
  }
LAB_14001f065:
  uVar4 = DAT_140018718;
  local_120 = (void *)CONCAT44(local_120._4_4_,iVar3);
  cVar2 = EtwEventEnabled(DAT_140018718,&AppIdRegisterUninstallerEvent);
  uVar11 = 0;
  if (cVar2 != '\0') {
    local_148[0] = (ushort)local_118 >> 1;
    local_c8 = local_148;
    local_b8 = CONCAT44(uStack_10c,uStack_110);
    local_b0 = (uint)(ushort)local_118;
    local_128[0] = CONCAT22(local_128[0]._2_2_,(ushort)local_138 >> 1);
    local_a8 = local_128;
    local_98 = uStack_130;
    local_90 = (uint)(ushort)local_138;
    local_144[0] = CONCAT22(local_144[0]._2_2_,*(ushort *)(local_d8 + 0x20) >> 1);
    local_88 = local_144;
    local_78 = *(undefined8 *)(local_d8 + 0x28);
    local_68 = param_2 + 0x10;
    local_58 = param_2 + 0x20;
    local_48 = &local_120;
    local_70 = (uint)*(ushort *)(local_d8 + 0x20);
    local_c0 = 2;
    local_ac = 0;
    local_a0 = 2;
    local_8c = 0;
    local_80 = 2;
    local_6c = 0;
    local_60 = 0x10;
    local_50 = 0x10;
    local_40 = 4;
    iVar3 = EtwWrite(uVar4,&AppIdRegisterUninstallerEvent,0,9);
    if (((iVar3 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_ZDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,uVar11,&local_118,(char)local_120,
                 (char)iVar3);
    }
  }
  if (psVar5 != (short *)0x0) {
    ExFreePoolWithTag(psVar5,0);
  }
  if (lVar12 != 0) {
    ObfDereferenceObject(lVar12);
  }
  if (lVar9 != -1) {
    ZwClose(lVar9);
  }
  if (lVar13 != 0) {
    ExFreePoolWithTag(lVar13,0);
  }
  if (pvVar8 != (void *)0x0) {
    ExFreePoolWithTag(pvVar8,0);
  }
  return;
}



===== AiReferenceProcOriginList @ 14001f25c =====

undefined8 AiReferenceProcOriginList(longlong param_1,void *param_2,uint param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  puVar2 = (undefined8 *)AipAllocTrackOriginProcess(param_1,param_2,param_3);
  if (puVar2 == (undefined8 *)0x0) {
    return 0xc0000017;
  }
  ExEnterCriticalRegionAndAcquireResourceExclusive(&DAT_1400188a0);
  if ((undefined8 **)DAT_140018860 == &DAT_140018860) {
LAB_14001f2c5:
    AipAddProcToOriginListLocked(puVar2);
    puVar2 = (undefined8 *)0x0;
  }
  else {
    puVar3 = DAT_140018860;
    if (DAT_140018860[2] != param_1) {
      do {
        puVar1 = (undefined8 *)*puVar3;
        if ((undefined8 **)puVar1 == &DAT_140018860) break;
        puVar3 = puVar1;
      } while (puVar1[2] != param_1);
      if (puVar3[2] != param_1) goto LAB_14001f2c5;
    }
    *(int *)((longlong)puVar3 + 0x2c) = *(int *)((longlong)puVar3 + 0x2c) + 1;
  }
  ExReleaseResourceAndLeaveCriticalRegion(&DAT_1400188a0);
  if (puVar2 != (undefined8 *)0x0) {
    ExFreePoolWithTag(puVar2,0);
  }
  return 0;
}



===== AiReleaseOriginProcessData @ 14001f310 =====

void AiReleaseOriginProcessData(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined1 *puVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (param_1 != 0) {
    puVar7 = auStack_28;
    LOCK();
    piVar1 = (int *)(param_1 + 0x18);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      while (plVar3 = *(longlong **)(param_1 + 0x30), plVar3 != (longlong *)(param_1 + 0x30)) {
        lVar4 = *plVar3;
        if (((longlong *)*(longlong *)(lVar4 + 8) != plVar3) ||
           (plVar5 = (longlong *)plVar3[1], (longlong *)*plVar5 != plVar3)) {
          pcVar6 = (code *)swi(0x29);
          (*pcVar6)(3);
          puVar7 = auStack_20;
          break;
        }
        *plVar5 = lVar4;
        *(longlong **)(lVar4 + 8) = plVar5;
        RtlFreeUnicodeString(plVar3 + 2);
        RtlFreeUnicodeString(plVar3 + 4);
        ExFreePoolWithTag(plVar3);
      }
      *(undefined8 *)(puVar7 + -8) = 0x14001f3a3;
      ExFreePoolWithTag(param_1,0);
    }
  }
  return;
}



===== AiRemoveProcFromTracking @ 14001f3c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AiRemoveProcFromTracking(longlong ******param_1,undefined8 param_2)

{
  int *piVar1;
  longlong *******ppppppplVar2;
  longlong ******pppppplVar3;
  longlong ******pppppplVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  longlong lVar7;
  code *pcVar8;
  ulonglong uVar9;
  longlong lVar10;
  int iVar11;
  undefined8 uVar12;
  undefined8 *puVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *******ppppppplVar16;
  undefined1 auStack_98 [32];
  char local_78 [4];
  int local_74;
  longlong *******local_70;
  longlong *******local_68;
  ulonglong local_60 [2];
  longlong local_50;
  longlong lStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_98;
  local_60[0] = 0;
  local_74 = 0;
  local_78[0] = '\0';
  ppppppplVar16 = (longlong *******)0x0;
  plVar14 = (longlong *)0x0;
  local_50 = 0;
  lStack_48 = 0;
  iVar11 = AiGetTokens(param_2,local_60,(ulonglong *)0x0);
  uVar9 = local_60[0];
  if (iVar11 < 0) {
    return;
  }
  iVar11 = AiIsTokenSandBoxed((char)local_60[0],local_78);
  if (uVar9 != 0) {
    ZwClose(uVar9);
  }
  if (iVar11 < 0) {
    return;
  }
  if (local_78[0] != '\0') {
    return;
  }
  ExEnterCriticalRegionAndAcquireResourceShared(&DAT_1400188a0);
  ppppppplVar2 = DAT_140018860;
  if ((longlong ********)DAT_140018860 == &DAT_140018860) {
LAB_14001f4a5:
    for (plVar14 = DAT_140018870; (longlong **)plVar14 != &DAT_140018870;
        plVar14 = (longlong *)*plVar14) {
      if (param_1 == (longlong ******)plVar14[2]) goto LAB_14001f4bf;
    }
    plVar14 = (longlong *)0x0;
  }
  else {
    do {
      ppppppplVar16 = ppppppplVar2;
      if (param_1 == ppppppplVar16[2]) break;
      ppppppplVar2 = (longlong *******)*ppppppplVar16;
    } while ((longlong ********)*ppppppplVar16 != &DAT_140018860);
    if (param_1 != ppppppplVar16[2]) {
      ppppppplVar16 = (longlong *******)0x0;
      goto LAB_14001f4a5;
    }
    if (ppppppplVar16 == (longlong *******)0x0) goto LAB_14001f4a5;
  }
LAB_14001f4bf:
  ExReleaseResourceLite(&DAT_1400188a0);
  if (ppppppplVar16 == (longlong *******)0x0) {
    if (plVar14 != (longlong *)0x0) {
      ExAcquireResourceExclusiveLite(&DAT_1400188a0,1);
      lVar7 = *plVar14;
      if ((*(longlong **)(lVar7 + 8) != plVar14) ||
         (plVar15 = (longlong *)plVar14[1], (longlong *)*plVar15 != plVar14)) {
LAB_14001f81b:
        pcVar8 = (code *)swi(0x29);
        (*pcVar8)(3);
        pcVar8 = (code *)swi(3);
        (*pcVar8)();
        return;
      }
      *plVar15 = lVar7;
      *(longlong **)(lVar7 + 8) = plVar15;
      if ((DAT_140018908 != 0) && ((longlong **)DAT_140018870 == &DAT_140018870)) {
        LOCK();
        DAT_140018908 = 0;
        UNLOCK();
      }
      ExReleaseResourceLite(&DAT_1400188a0);
      ExFreePoolWithTag(plVar14,0);
    }
  }
  else {
    local_68 = (longlong *******)&local_70;
    local_70 = (longlong *******)&local_70;
    ExAcquireResourceExclusiveLite(&DAT_1400188a0,1);
    do {
      ppppppplVar2 = (longlong *******)*ppppppplVar16;
      if (param_1 == ppppppplVar16[2]) {
        if (((longlong *******)ppppppplVar2[1] != ppppppplVar16) ||
           (pppppplVar3 = ppppppplVar16[1], (longlong *******)*pppppplVar3 != ppppppplVar16))
        goto LAB_14001f81b;
        *pppppplVar3 = (longlong *****)ppppppplVar2;
        ppppppplVar2[1] = pppppplVar3;
        if ((longlong ********)*local_68 != &local_70) goto LAB_14001f81b;
        ppppppplVar16[1] = (longlong ******)local_68;
        *ppppppplVar16 = (longlong ******)&local_70;
        *local_68 = (longlong ******)ppppppplVar16;
        local_68 = ppppppplVar16;
      }
      ppppppplVar16 = ppppppplVar2;
    } while ((longlong ********)ppppppplVar2 != &DAT_140018860);
    if ((DAT_140018908 != 0) && ((longlong ********)DAT_140018860 == &DAT_140018860)) {
      LOCK();
      DAT_140018908 = 0;
      UNLOCK();
    }
    ExReleaseResourceLite(&DAT_1400188a0);
    do {
      pppppplVar3 = *local_70;
      if (((longlong *******)pppppplVar3[1] != local_70) ||
         (pppppplVar4 = local_70[1], (longlong *******)*pppppplVar4 != local_70))
      goto LAB_14001f81b;
      *pppppplVar4 = (longlong *****)pppppplVar3;
      pppppplVar3[1] = (longlong *****)pppppplVar4;
      AiReleaseOriginProcessData((longlong)local_70);
    } while ((longlong ********)local_70 != &local_70);
  }
  uVar12 = SmartlockerGetSubSessionID(param_1,&local_50,&local_74);
  if ((int)uVar12 == 0) goto LAB_14001f79b;
  ExAcquireResourceExclusiveLite(&DAT_1400188a0,1);
  if ((longlong **)DAT_140018880 != &DAT_140018880) {
    plVar14 = DAT_140018880;
    if (local_74 == 0) {
      puVar13 = DAT_140018890;
      if ((undefined8 **)DAT_140018890 != &DAT_140018890) {
        do {
          puVar5 = (undefined8 *)*puVar13;
          if (param_1 == (longlong ******)puVar13[2]) {
            if (((undefined8 *)puVar5[1] != puVar13) ||
               (puVar6 = (undefined8 *)puVar13[1], (undefined8 *)*puVar6 != puVar13))
            goto LAB_14001f81b;
            *puVar6 = puVar5;
            puVar5[1] = puVar6;
            ExFreePoolWithTag(puVar13,0);
            break;
          }
          puVar13 = puVar5;
        } while ((undefined8 **)puVar5 != &DAT_140018890);
      }
    }
    else {
      do {
        iVar11 = memcmp(&local_50,(void *)(plVar14[4] + 0x20),0x10);
        lVar10 = lStack_48;
        lVar7 = local_50;
        if (iVar11 == 0) {
          piVar1 = (int *)((longlong)plVar14 + 0x2c);
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            puVar13 = DAT_140018890;
            if ((undefined8 **)DAT_140018890 == &DAT_140018890) goto LAB_14001f704;
            goto LAB_14001f6bd;
          }
          break;
        }
        plVar14 = (longlong *)*plVar14;
      } while ((longlong **)plVar14 != &DAT_140018880);
    }
    goto LAB_14001f74a;
  }
  goto LAB_14001f788;
LAB_14001f6bd:
  do {
    puVar5 = (undefined8 *)*puVar13;
    if ((lVar7 == *(longlong *)(puVar13[3] + 0x20)) && (lVar10 == *(longlong *)(puVar13[3] + 0x28)))
    {
      if (((undefined8 *)puVar5[1] != puVar13) ||
         (puVar6 = (undefined8 *)puVar13[1], (undefined8 *)*puVar6 != puVar13)) goto LAB_14001f81b;
      *puVar6 = puVar5;
      puVar5[1] = puVar6;
      ExFreePoolWithTag(puVar13,0);
    }
    puVar13 = puVar5;
  } while ((undefined8 **)puVar5 != &DAT_140018890);
LAB_14001f704:
  for (plVar15 = (longlong *)plVar14[6]; plVar15 != plVar14 + 6; plVar15 = (longlong *)*plVar15) {
    AiParseAndTagUninstallerFromUninstallString((longlong)plVar15,plVar14[4]);
  }
  lVar7 = *plVar14;
  if ((*(longlong **)(lVar7 + 8) != plVar14) ||
     (plVar15 = (longlong *)plVar14[1], (longlong *)*plVar15 != plVar14)) goto LAB_14001f81b;
  *plVar15 = lVar7;
  *(longlong **)(lVar7 + 8) = plVar15;
  AiReleaseOriginProcessData((longlong)plVar14);
LAB_14001f74a:
  if ((DAT_140018910 != 0) &&
     (((undefined8 **)DAT_140018890 == &DAT_140018890 ||
      ((longlong **)DAT_140018880 == &DAT_140018880)))) {
    LOCK();
    DAT_140018910 = 0;
    UNLOCK();
  }
  if ((DAT_140018918 != 0) && ((longlong **)DAT_140018880 == &DAT_140018880)) {
    LOCK();
    DAT_140018918 = 0;
    UNLOCK();
  }
LAB_14001f788:
  ExReleaseResourceLite(&DAT_1400188a0);
LAB_14001f79b:
  KeLeaveCriticalRegion();
  return;
}



===== AiRtlFindCharInUnicodeString @ 14001f828 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 AiRtlFindCharInUnicodeString(uint param_1,ushort *param_2,ushort *param_3,short *param_4)

{
  short *psVar1;
  short sVar2;
  short sVar3;
  undefined8 uVar4;
  ushort uVar5;
  ushort uVar6;
  ulonglong uVar7;
  short *psVar8;
  ushort uVar9;
  short *psVar10;
  undefined1 auStack_c8 [32];
  uint local_a8;
  ulonglong local_a0;
  ushort *local_98;
  short *local_90;
  short local_88 [32];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_c8;
  if (param_4 != (short *)0x0) {
    *param_4 = 0;
  }
  if (((param_1 & 0xfffffff8) != 0) || (param_4 == (short *)0x0)) {
    return 0xc000000d;
  }
  local_98 = param_2;
  local_90 = param_4;
  uVar4 = RtlValidateUnicodeString(0);
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  uVar4 = RtlValidateUnicodeString(0,param_3);
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  psVar1 = *(short **)(param_3 + 4);
  psVar8 = *(short **)(param_2 + 4);
  uVar6 = *param_2 >> 1;
  uVar9 = *param_3 >> 1;
  local_a8 = param_1 & 1;
  if (local_a8 != 0) {
    psVar8 = psVar8 + ((ulonglong)uVar6 - 1);
  }
  local_a0 = (ulonglong)local_a8 ^ 1;
  if ((param_1 & 4) != 0) {
    if (0x20 < uVar9) {
      if (uVar6 == 0) {
        return 0xc0000225;
      }
      do {
        sVar2 = RtlDowncaseUnicodeChar(*psVar8);
        uVar5 = 0;
        if ((param_1 & 2) == 0) {
          do {
            sVar3 = RtlDowncaseUnicodeChar(psVar1[uVar5]);
            if (sVar2 == sVar3) break;
            uVar5 = uVar5 + 1;
          } while (uVar5 < uVar9);
          if (uVar5 != uVar9) goto LAB_14001fa4f;
        }
        else {
          do {
            sVar3 = RtlDowncaseUnicodeChar(psVar1[uVar5]);
            if (sVar2 == sVar3) break;
            uVar5 = uVar5 + 1;
          } while (uVar5 < uVar9);
          if (uVar5 == uVar9) goto LAB_14001fa4f;
        }
        psVar8 = psVar8 + local_a0 * 2 + -1;
        uVar6 = uVar6 - 1;
        if (uVar6 == 0) {
          return 0xc0000225;
        }
      } while( true );
    }
    if (uVar9 != 0) {
      uVar7 = (ulonglong)uVar9;
      psVar10 = local_88;
      do {
        sVar2 = RtlDowncaseUnicodeChar
                          (*(undefined2 *)
                            ((longlong)psVar10 + ((longlong)psVar1 - (longlong)local_88)));
        *psVar10 = sVar2;
        psVar10 = psVar10 + 1;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
    }
    uVar7 = local_a0;
    if (uVar6 == 0) {
      return 0xc0000225;
    }
    do {
      sVar2 = RtlDowncaseUnicodeChar(*psVar8);
      if ((param_1 & 2) == 0) {
        uVar5 = 0;
        if (uVar9 != 0) {
          do {
            if (sVar2 == local_88[uVar5]) break;
            uVar5 = uVar5 + 1;
          } while (uVar5 < uVar9);
        }
        if (uVar5 != uVar9) goto LAB_14001fa4f;
      }
      else {
        uVar5 = 0;
        if (uVar9 != 0) {
          do {
            if (sVar2 == local_88[uVar5]) break;
            uVar5 = uVar5 + 1;
          } while (uVar5 < uVar9);
        }
        if (uVar5 == uVar9) goto LAB_14001fa4f;
      }
      psVar8 = psVar8 + uVar7 * 2 + -1;
      uVar6 = uVar6 - 1;
      if (uVar6 == 0) {
        return 0xc0000225;
      }
    } while( true );
  }
  if (uVar9 == 1) {
    if (uVar6 == 0) {
      return 0xc0000225;
    }
    if ((param_1 & 2) == 0) {
      while (*psVar8 != *psVar1) {
        psVar8 = psVar8 + local_a0 * 2 + -1;
        uVar6 = uVar6 - 1;
        if (uVar6 == 0) {
          return 0xc0000225;
        }
      }
    }
    else {
      while (*psVar8 == *psVar1) {
        psVar8 = psVar8 + local_a0 * 2 + -1;
        uVar6 = uVar6 - 1;
        if (uVar6 == 0) {
          return 0xc0000225;
        }
      }
    }
  }
  else {
    if (uVar6 == 0) {
      return 0xc0000225;
    }
    do {
      uVar5 = 0;
      if ((param_1 & 2) == 0) {
        if (uVar9 != 0) {
          do {
            if (*psVar8 == psVar1[uVar5]) break;
            uVar5 = uVar5 + 1;
          } while (uVar5 < uVar9);
        }
        if (uVar5 != uVar9) break;
      }
      else {
        if (uVar9 != 0) {
          do {
            if (*psVar8 == psVar1[uVar5]) break;
            uVar5 = uVar5 + 1;
          } while (uVar5 < uVar9);
        }
        if (uVar5 == uVar9) break;
      }
      psVar8 = psVar8 + local_a0 * 2 + -1;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
LAB_14001fa4f:
    if (uVar6 == 0) {
      return 0xc0000225;
    }
  }
  sVar2 = uVar6 * 2 + -2;
  if (local_a8 == 0) {
    sVar2 = *local_98 - sVar2;
  }
  *local_90 = sVar2;
  return 0;
}



===== AiSetUninstallStringEa @ 14001fbe0 =====

undefined4 AiSetUninstallStringEa(undefined8 param_1,void *param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)AiAlloc((ulonglong)(param_3 + 0x2d));
  if (puVar2 == (undefined4 *)0x0) {
    uVar1 = 0xc0000017;
  }
  else {
    *puVar2 = 0;
    *(undefined2 *)(puVar2 + 1) = 0x2400;
    *(short *)((longlong)puVar2 + 6) = (short)param_3;
    builtin_strncpy((char *)(puVar2 + 2),"$Kernel.",8);
    builtin_strncpy((char *)(puVar2 + 4),"Smartloc",8);
    builtin_strncpy((char *)(puVar2 + 6),"ker.Unin",8);
    builtin_strncpy((char *)(puVar2 + 8),"stallStr",8);
    puVar2[10] = 0x73676e69;
    *(undefined1 *)(puVar2 + 0xb) = 0;
    memmove((void *)((longlong)puVar2 + 0x2d),param_2,(ulonglong)param_3);
    uVar1 = FsRtlSetKernelEaFile
                      (param_1,puVar2,
                       (uint)*(ushort *)((longlong)puVar2 + 6) + *(byte *)((longlong)puVar2 + 5) + 9
                      );
    ExFreePoolWithTag(puVar2,0);
  }
  return uVar1;
}



===== AiUnreferenceProcOriginList @ 14001fcac =====

void AiUnreferenceProcOriginList(longlong param_1)

{
  int *piVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong *plVar5;
  undefined1 *puVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  plVar5 = (longlong *)0x0;
  ExEnterCriticalRegionAndAcquireResourceExclusive(&DAT_1400188a0);
  plVar3 = DAT_140018860;
  puVar6 = auStack_28;
  if ((longlong **)DAT_140018860 != &DAT_140018860) {
    do {
      plVar5 = plVar3;
      if (param_1 == plVar5[2]) break;
      plVar3 = (longlong *)*plVar5;
    } while ((longlong **)*plVar5 != &DAT_140018860);
    puVar6 = auStack_28;
    if (param_1 == plVar5[2]) {
      piVar1 = (int *)((longlong)plVar5 + 0x2c);
      *piVar1 = *piVar1 + -1;
      puVar6 = auStack_28;
      if (*piVar1 == 0) {
        lVar2 = *plVar5;
        if ((*(longlong **)(lVar2 + 8) == plVar5) &&
           (plVar3 = (longlong *)plVar5[1], (longlong *)*plVar3 == plVar5)) {
          *plVar3 = lVar2;
          *(longlong **)(lVar2 + 8) = plVar3;
          puVar6 = auStack_28;
          if ((DAT_140018908 != 0) &&
             (puVar6 = auStack_28, (longlong **)DAT_140018860 == &DAT_140018860)) {
            LOCK();
            DAT_140018908 = 0;
            UNLOCK();
            puVar6 = auStack_28;
          }
          goto LAB_14001fd45;
        }
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        puVar6 = auStack_20;
      }
    }
    plVar5 = (longlong *)0x0;
  }
LAB_14001fd45:
  *(undefined8 *)(puVar6 + -8) = 0x14001fd53;
  ExReleaseResourceAndLeaveCriticalRegion(&DAT_1400188a0);
  *(undefined8 *)(puVar6 + -8) = 0x14001fd60;
  AiReleaseOriginProcessData((longlong)plVar5);
  return;
}



===== AipAddProcToOriginListLocked @ 14001fd78 =====

undefined8 * AipAddProcToOriginListLocked(undefined8 *param_1)

{
  code *pcVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  puVar2 = &DAT_140018860;
  if ((undefined8 *)*DAT_140018868 != &DAT_140018860) {
    param_1 = (undefined8 *)0x3;
    pcVar1 = (code *)swi(0x29);
    puVar2 = (undefined8 *)(*pcVar1)();
  }
  *param_1 = puVar2;
  param_1[1] = DAT_140018868;
  *DAT_140018868 = param_1;
  DAT_140018868 = param_1;
  puVar3 = puVar2;
  if ((DAT_140018908 == (undefined8 *)0x0) && ((undefined8 **)DAT_140018870 != &DAT_140018870)) {
    LOCK();
    UNLOCK();
    puVar3 = (undefined8 *)0x0;
    DAT_140018908 = puVar2;
  }
  return puVar3;
}



===== AipAllocTrackOriginProcess @ 14001fdcc =====

longlong AipAllocTrackOriginProcess(undefined8 param_1,void *param_2,uint param_3)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar2 = AiAlloc((ulonglong)param_3 + 0x40);
  if (lVar2 != 0) {
    *(undefined8 *)(lVar2 + 0x10) = param_1;
    *(undefined4 *)(lVar2 + 0x18) = 1;
    *(void **)(lVar2 + 0x20) = (void *)(lVar2 + 0x40);
    *(undefined4 *)(lVar2 + 0x2c) = 1;
    *(uint *)(lVar2 + 0x28) = param_3;
    memmove((void *)(lVar2 + 0x40),param_2,(ulonglong)param_3);
    lVar1 = lVar2 + 0x30;
    *(longlong *)(lVar2 + 0x38) = lVar1;
    *(longlong *)lVar1 = lVar1;
  }
  return lVar2;
}



===== AipCleanupDispatch @ 14001fe60 =====

undefined8 AipCleanupDispatch(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
            &WPP_4bc66d74a05f389d64780558abe6f77a_Traceguids);
  }
  if (g_AppId == param_1) {
    uVar1 = AiServiceStopped(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30));
    if (-1 < (int)uVar1) {
      DAT_140018858 = 0;
    }
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== AipCloseDispatch @ 14001ff00 =====

undefined8 AipCloseDispatch(undefined8 param_1,longlong param_2)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
            &WPP_4bc66d74a05f389d64780558abe6f77a_Traceguids);
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== AipCreateDispatch @ 14001ff70 =====

undefined8 AipCreateDispatch(undefined8 param_1,longlong param_2)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
            &WPP_4bc66d74a05f389d64780558abe6f77a_Traceguids);
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== AipDeviceIoControlDispatch @ 14001ffe0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int AipDeviceIoControlDispatch(longlong param_1,longlong param_2)

{
  ulonglong *puVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  char cVar5;
  int iVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined2 uVar9;
  longlong lVar10;
  undefined1 auStackY_d8 [32];
  undefined8 local_a8;
  undefined1 local_98 [16];
  longlong local_88;
  int local_80;
  undefined8 local_78;
  undefined4 local_70;
  undefined8 local_68;
  undefined4 local_60;
  ulonglong *local_58;
  int local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_d8;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
            &WPP_4bc66d74a05f389d64780558abe6f77a_Traceguids);
  }
  lVar2 = *(longlong *)(param_2 + 0xb8);
  puVar1 = (ulonglong *)(param_2 + 0x38);
  *puVar1 = 0;
  iVar6 = *(int *)(lVar2 + 0x18);
  if (g_AppId != param_1) {
    if (DAT_140018708 != param_1) {
      memset(local_98,0,0x50);
      local_78 = *(undefined8 *)(param_2 + 0x18);
      local_70 = *(undefined4 *)(lVar2 + 0x10);
      local_50 = 0;
      local_60 = *(undefined4 *)(lVar2 + 8);
      local_88 = param_1;
      local_80 = iVar6;
      local_68 = local_78;
      local_58 = puVar1;
      uVar7 = AipForEachPlugin(AipPluginInvokeIoctlCallback,local_98);
      iVar6 = -0x3ffffff0;
      if (local_50 != 0) {
        iVar6 = (int)uVar7;
      }
      goto LAB_140020637;
    }
    if (iVar6 == 0x225804) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                &WPP_4bc66d74a05f389d64780558abe6f77a_Traceguids);
      }
      uVar8 = SrpVerifyDll(*(ulonglong **)(param_2 + 0x18),*(uint *)(lVar2 + 0x10),
                           (uint *)*(ulonglong **)(param_2 + 0x18),
                           (wchar_t *)(ulonglong)*(uint *)(lVar2 + 8),
                           *(undefined1 *)(param_2 + 0x40),(longlong *)puVar1);
      iVar6 = (int)uVar8;
      goto LAB_140020637;
    }
    if (iVar6 == 0x225818) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                &WPP_4bc66d74a05f389d64780558abe6f77a_Traceguids);
      }
      uVar8 = SrpInheritOrigin(*(undefined8 **)(param_2 + 0x18),*(uint *)(lVar2 + 0x10));
      iVar6 = (int)uVar8;
      goto LAB_140020637;
    }
    if (iVar6 == 0x22581c) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                &WPP_4bc66d74a05f389d64780558abe6f77a_Traceguids);
      }
      uVar8 = SrpOpenTrackInstallIoctl();
      iVar6 = (int)uVar8;
      goto LAB_140020637;
    }
    if (iVar6 == 0x225820) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
                &WPP_4bc66d74a05f389d64780558abe6f77a_Traceguids);
      }
      local_a8 = 0;
      iVar6 = ObReferenceObjectByHandle
                        (0xffffffffffffffff,0x1fffff,*(undefined8 *)PsProcessType_exref,0);
      uVar8 = local_a8;
      if (-1 < iVar6) {
        AiUnreferenceProcOriginList(local_a8);
        ObfDereferenceObject(uVar8);
      }
      goto LAB_140020637;
    }
    if (iVar6 == 0x229800) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                &WPP_4bc66d74a05f389d64780558abe6f77a_Traceguids);
      }
      uVar8 = SrpUpdatePolicy();
      iVar6 = (int)uVar8;
      goto LAB_140020637;
    }
    if (iVar6 == 0x229808) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                &WPP_4bc66d74a05f389d64780558abe6f77a_Traceguids);
      }
      iVar6 = SrpGetHitCount(*(wchar_t **)(param_2 + 0x18),*(uint *)(lVar2 + 0x10),
                             (longlong)*(wchar_t **)(param_2 + 0x18),*(uint *)(lVar2 + 8),puVar1);
      goto LAB_140020637;
    }
    if (iVar6 == 0x22980c) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                &WPP_4bc66d74a05f389d64780558abe6f77a_Traceguids);
      }
      uVar8 = AipTransactionBegin(*(ulonglong **)(param_2 + 0x18),*(int *)(lVar2 + 0x10),
                                  *(ulonglong **)(param_2 + 0x18),*(int *)(lVar2 + 8),puVar1);
      iVar6 = (int)uVar8;
      goto LAB_140020637;
    }
    if (iVar6 == 0x229810) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                &WPP_4bc66d74a05f389d64780558abe6f77a_Traceguids);
      }
      plVar4 = *(longlong **)(param_2 + 0x18);
      if (*(int *)(lVar2 + 0x10) != 0x10) goto LAB_140020156;
      ExEnterCriticalRegionAndAcquireResourceExclusive(&DAT_1400183e0);
      lVar2 = DAT_140018448;
      lVar10 = 0;
      if ((*plVar4 == DAT_140018450) && (plVar4[1] == DAT_140018458)) {
        DAT_140018448 = 0;
        DAT_140018450 = 0;
        DAT_140018458 = 0;
        lVar10 = lVar2;
      }
      ExReleaseResourceAndLeaveCriticalRegion(&DAT_1400183e0);
      if (lVar10 == 0) {
        iVar6 = -0x3ffffdee;
        goto LAB_140020637;
      }
      ReplacePolicyRef(lVar10);
    }
    else {
      if (iVar6 != 0x229814) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
          uVar9 = 0x26;
          goto LAB_1400200b8;
        }
        goto LAB_1400200f8;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                &WPP_4bc66d74a05f389d64780558abe6f77a_Traceguids);
      }
      SrpPolicyTransactionRollback();
    }
LAB_1400201ac:
    iVar6 = 0;
    goto LAB_140020637;
  }
  if (iVar6 == 0x22a000) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
              &WPP_4bc66d74a05f389d64780558abe6f77a_Traceguids);
    }
    iVar6 = AiReloadCertificate(*(ushort **)(param_2 + 0x18),*(uint *)(lVar2 + 0x10));
    goto LAB_140020637;
  }
  if (iVar6 == 0x22a008) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
              &WPP_4bc66d74a05f389d64780558abe6f77a_Traceguids);
    }
    iVar6 = AiServiceStarted(*(undefined8 *)(lVar2 + 0x30));
    if (-1 < iVar6) {
      DAT_140018858 = *(undefined8 *)(lVar2 + 0x30);
    }
    local_a8 = (ulonglong)local_a8._4_4_ << 0x20;
    ZwSetEvent(DAT_140018240,&local_a8);
    goto LAB_140020637;
  }
  if (iVar6 == 0x22a00c) {
    local_a8 = local_a8 & 0xffffffff00000000;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
              &WPP_4bc66d74a05f389d64780558abe6f77a_Traceguids);
    }
    uVar8 = AiServiceStopped(*(longlong *)(lVar2 + 0x30));
    iVar6 = (int)uVar8;
    if (-1 < iVar6) {
      DAT_140018858 = 0;
    }
    ZwResetEvent(DAT_140018240,&local_a8);
    goto LAB_140020637;
  }
  if (iVar6 == 0x22a010) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
              &WPP_4bc66d74a05f389d64780558abe6f77a_Traceguids);
    }
    uVar7 = AipReadConfigOptions();
    iVar6 = (int)uVar7;
    goto LAB_140020637;
  }
  if (iVar6 == 0x22a014) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
              &WPP_4bc66d74a05f389d64780558abe6f77a_Traceguids);
    }
    cVar5 = ExGetPreviousMode();
    if (cVar5 == '\0') {
      if (*(int *)(lVar2 + 8) == 0x30) {
        puVar3 = *(undefined8 **)(param_2 + 0x18);
        *puVar3 = &DAT_1400188a0;
        puVar3[1] = &DAT_140018908;
        puVar3[2] = &DAT_140018910;
        puVar3[3] = &DAT_140018918;
        puVar3[4] = AiReleaseOriginProcessData;
        puVar3[5] = AiAllocUninstallStringData;
        *puVar1 = 0x30;
        goto LAB_1400201ac;
      }
LAB_140020156:
      iVar6 = -0x3ffffff3;
      goto LAB_140020637;
    }
  }
  else if (iVar6 == 0x22a018) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
              &WPP_4bc66d74a05f389d64780558abe6f77a_Traceguids);
    }
    cVar5 = ExGetPreviousMode();
    if (cVar5 == '\0') {
      if (*(int *)(lVar2 + 0x10) == 0x20) {
        iVar6 = AipSmartHashImageFile(*(longlong *)(param_2 + 0x18),0,0,0);
        goto LAB_140020637;
      }
      goto LAB_140020156;
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) {
    uVar9 = 0x1c;
LAB_1400200b8:
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
             &WPP_4bc66d74a05f389d64780558abe6f77a_Traceguids,iVar6);
  }
LAB_1400200f8:
  iVar6 = -0x3ffffff0;
LAB_140020637:
  *(int *)(param_2 + 0x30) = iVar6;
  IofCompleteRequest(param_2,0);
  return iVar6;
}



===== AipPluginInvokeIoctlCallback @ 140020680 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 AipPluginInvokeIoctlCallback(longlong param_1,longlong *param_2,longlong param_3)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if ((*param_2 == *(longlong *)(param_3 + 0x10)) && (*(code **)(param_1 + 0x30) != (code *)0x0)) {
    uVar1 = (**(code **)(param_1 + 0x30))
                      (*(longlong *)(param_3 + 0x10),*(undefined4 *)(param_3 + 0x18),
                       *(undefined8 *)(param_3 + 0x20),*(undefined4 *)(param_3 + 0x28),
                       *(undefined8 *)(param_3 + 0x30),*(undefined4 *)(param_3 + 0x38),
                       *(undefined8 *)(param_3 + 0x40));
    *(undefined4 *)(param_3 + 0x48) = 1;
  }
  return uVar1;
}



===== AipReadConfigOptions @ 1400206e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 AipReadConfigOptions(void)

{
  undefined8 uVar1;
  undefined1 auStack_1b8 [32];
  undefined8 local_198;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 local_168;
  undefined4 local_160;
  wchar_t *local_158;
  undefined8 *local_150;
  undefined4 local_148;
  undefined *local_140;
  undefined4 local_138;
  undefined8 local_130;
  undefined4 local_128;
  wchar_t *local_120;
  longlong local_118;
  undefined4 local_110;
  undefined *local_108;
  undefined4 local_100;
  undefined8 local_f8;
  undefined4 local_f0;
  wchar_t *local_e8;
  longlong local_e0;
  undefined4 local_d8;
  undefined *local_d0;
  undefined4 local_c8;
  undefined8 local_c0;
  undefined4 local_b8;
  wchar_t *local_b0;
  undefined8 *local_a8;
  undefined4 local_a0;
  undefined *local_98;
  undefined4 local_90;
  undefined8 local_88;
  undefined4 local_80;
  wchar_t *local_78;
  longlong local_70;
  undefined4 local_68;
  undefined *local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_1b8;
  local_140 = &DAT_140018190;
  local_178 = 0;
  local_160 = 0x120;
  local_148 = 0x4000004;
  local_138 = 4;
  local_158 = L"EnablePath";
  local_150 = &local_188;
  local_128 = 0x120;
  local_120 = L"EnableFqbn";
  local_118 = (longlong)&local_188 + 4;
  local_e8 = L"EnableSha256FlatHash";
  local_e0 = (longlong)&uStack_180 + 4;
  local_b0 = L"EnableSha1Hash";
  local_a8 = &local_178;
  local_78 = L"EnableSha256Hash";
  local_70 = (longlong)&local_178 + 4;
  local_110 = 0x4000004;
  local_108 = &DAT_140018190;
  local_100 = 4;
  local_f0 = 0x120;
  local_d8 = 0x4000004;
  local_d0 = &DAT_140018190;
  local_c8 = 4;
  local_b8 = 0x120;
  local_a0 = 0x4000004;
  local_98 = &DAT_140018190;
  local_90 = 4;
  local_80 = 0x120;
  local_68 = 0x4000004;
  local_60 = &DAT_140018190;
  local_58 = 4;
  local_188 = 0;
  uStack_180 = 0;
  local_168 = 0;
  local_130 = 0;
  local_f8 = 0;
  local_c0 = 0;
  local_88 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  local_198 = 0;
  uVar1 = RtlQueryRegistryValuesEx
                    (0,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\AppID\\",
                     &local_168,0);
  if (-1 < (int)uVar1) {
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&DAT_1400187c0,1);
    _DAT_140018828 = (undefined4)local_188;
    uRam000000014001882c = local_188._4_4_;
    uRam0000000140018830 = (undefined4)uStack_180;
    uRam0000000140018834 = uStack_180._4_4_;
    DAT_140018838 = local_178;
    ExReleaseResourceLite(&DAT_1400187c0);
    KeLeaveCriticalRegion();
    if (local_188._4_4_ - 1U < 0xfffffffe) {
      AiLogTriggerServiceStartEvent();
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== AipTrackListCleanup @ 1400208d8 =====

void AipTrackListCleanup(void)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong *plVar4;
  
  while (plVar4 = DAT_140018860, (longlong **)DAT_140018860 != &DAT_140018860) {
    lVar1 = *DAT_140018860;
    if ((*(longlong **)(lVar1 + 8) != DAT_140018860) ||
       (plVar2 = (longlong *)DAT_140018860[1], (longlong *)*plVar2 != DAT_140018860))
    goto LAB_1400209ca;
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    AiReleaseOriginProcessData((longlong)plVar4);
  }
  while (plVar4 = DAT_140018870, (longlong **)DAT_140018870 != &DAT_140018870) {
    lVar1 = *DAT_140018870;
    if ((*(longlong **)(lVar1 + 8) != DAT_140018870) ||
       (plVar2 = (longlong *)DAT_140018870[1], (longlong *)*plVar2 != DAT_140018870))
    goto LAB_1400209ca;
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    ExFreePoolWithTag(plVar4,0);
  }
  while (plVar4 = DAT_140018880, (longlong **)DAT_140018880 != &DAT_140018880) {
    lVar1 = *DAT_140018880;
    if ((*(longlong **)(lVar1 + 8) != DAT_140018880) ||
       (plVar2 = (longlong *)DAT_140018880[1], (longlong *)*plVar2 != DAT_140018880))
    goto LAB_1400209ca;
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    AiReleaseOriginProcessData((longlong)plVar4);
  }
  while( true ) {
    plVar4 = DAT_140018890;
    if ((longlong **)DAT_140018890 == &DAT_140018890) {
      return;
    }
    lVar1 = *DAT_140018890;
    if ((*(longlong **)(lVar1 + 8) != DAT_140018890) ||
       (plVar2 = (longlong *)DAT_140018890[1], (longlong *)*plVar2 != DAT_140018890)) break;
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    ExFreePoolWithTag(plVar4,0);
  }
LAB_1400209ca:
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  return;
}



===== AipTransactionBegin @ 1400209e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong AipTransactionBegin(ulonglong *param_1,int param_2,undefined8 *param_3,int param_4,
                             undefined8 *param_5)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined1 auStack_1b8 [32];
  undefined8 local_198 [24];
  undefined1 local_d8 [176];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_1b8;
  memset(local_198,0,0x168);
  if (((param_2 != 8) || (param_4 != 0x10)) || (0x7fffffffffffffff < *param_1)) {
    return 0xc000000d;
  }
  uVar2 = SrpCreatePluginFileName(*param_1,local_d8);
  uVar3 = uVar2 & 0xffffffff;
  if (-1 < (int)uVar2) {
    uVar1 = SrpReadPolicy(local_198);
    uVar3 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      uVar1 = SrpPolicyTransactionBegin(local_198,param_3);
      if ((int)uVar1 < 0) {
        return (ulonglong)uVar1;
      }
      *param_5 = 0x10;
      return (ulonglong)uVar1;
    }
  }
  SrpFreeGlobalPolicy((longlong)local_198);
  return uVar3;
}



===== AipUnload @ 140020ad0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void AipUnload(void)

{
  bool bVar1;
  bool bVar2;
  undefined8 uVar3;
  undefined *puVar4;
  ulonglong uVar5;
  undefined8 in_R9;
  undefined1 auStackY_a8 [32];
  ulonglong local_78;
  ulonglong local_70 [2];
  wchar_t *local_60;
  ulonglong local_58 [4];
  ulonglong *local_38;
  undefined8 local_30;
  ulonglong *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_70[1] = 0x140012;
  local_60 = L"\\??\\AppID";
  bVar2 = true;
  if (DAT_1400187ac != 0) {
    PsSetCreateProcessNotifyRoutineEx(AiProcessNotifyRoutine);
    DAT_1400187ac = 0;
  }
  if (DAT_140018240 != 0) {
    ZwClose();
  }
  if (DAT_1400187a8 != 0) {
    IoDeleteSymbolicLink(local_70 + 1);
    DAT_1400187a8 = 0;
  }
  if (g_AppId != 0) {
    IoDeleteDevice();
    g_AppId = 0;
  }
  if ((DAT_140018648 != 0) && (4 < DAT_140018000)) {
    if (((_DAT_140018010 & 0x200000000000) == 0) ||
       (bVar1 = true, (DAT_140018018 & 0x200000000000) != DAT_140018018)) {
      bVar1 = false;
    }
    if (bVar1) {
      local_78 = AiPerfStats / DAT_140018648;
      local_30 = 8;
      local_38 = &local_78;
      local_28 = local_70;
      local_70[0] = DAT_140018648;
      local_20 = 8;
      _tlgWriteTransfer_EtwWriteTransfer
                (DAT_140018018,&DAT_140014e05,DAT_140018648,in_R9,4,local_70 + 3);
    }
  }
  uVar5 = DAT_140018658;
  if ((DAT_140018658 != 0) && (4 < DAT_140018000)) {
    if (((_DAT_140018010 & 0x200000000000) == 0) ||
       (bVar1 = true, (DAT_140018018 & 0x200000000000) != DAT_140018018)) {
      bVar1 = false;
    }
    if (bVar1) {
      local_70[0] = DAT_140018650 / DAT_140018658;
      local_30 = 8;
      local_38 = local_70;
      local_28 = &local_78;
      local_78 = DAT_140018658;
      local_20 = 8;
      _tlgWriteTransfer_EtwWriteTransfer
                (DAT_140018018,&DAT_140014db3,DAT_140018658,in_R9,4,local_70 + 3);
    }
  }
  SrpCleanup();
  uVar3 = 0;
  AiServiceStopped(0);
  AiFreeLib();
  if (4 < DAT_140018000) {
    if (((_DAT_140018010 & 0x400000000000) == 0) ||
       ((DAT_140018018 & 0x400000000000) != DAT_140018018)) {
      bVar2 = false;
    }
    if (bVar2) {
      _tlgWriteTransfer_EtwWriteTransfer(uVar3,&DAT_140014d91,uVar5,in_R9,2,local_70 + 3);
    }
  }
  uVar3 = DAT_140018020;
  DAT_140018020 = 0;
  DAT_140018000 = 0;
  EtwUnregister(uVar3);
  if (DAT_140018920 != '\0') {
    ExEnterCriticalRegionAndAcquireResourceExclusive(&DAT_1400188a0);
    DAT_140018918 = 0;
    DAT_140018908 = 0;
    DAT_140018910 = 0;
    AipTrackListCleanup();
    ExReleaseResourceAndLeaveCriticalRegion(&DAT_1400188a0);
    ExDeleteResourceLite(&DAT_1400188a0);
    DAT_140018920 = '\0';
  }
  if (DAT_1400187b0 != 0) {
    ExDeleteResourceLite(&DAT_1400187c0);
    DAT_1400187b0 = 0;
  }
  if (DAT_1400187b8 != 0) {
    EtwUnregister();
    DAT_1400187b8 = 0;
  }
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar4 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; puVar4 != (undefined *)0x0; puVar4 = *(undefined **)(puVar4 + 0x10)) {
        if (*(longlong *)(puVar4 + 0x38) != 0) {
          (*pfnEtwUnregister)();
          *(undefined8 *)(puVar4 + 0x38) = 0;
        }
      }
    }
    else if (WPPTraceSuite == 2) {
      IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
    }
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
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



===== WppInitKm @ 140020ea0 =====

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



===== WppLoadTracingSupport @ 140020f30 =====

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



===== WppTraceCallback @ 140021080 =====

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



===== _tlgEnableCallback @ 140021310 =====

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



===== wil_details_EvaluateFeatureDependencies @ 14002138c =====

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
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x0001400213c7;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_140021441:
  while( true ) {
    if (&UNK_1400172df < ppuVar3) {
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
      if (&UNK_1400172df < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x0001400213c7:
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
      if (&UNK_1400172df < ppuVar2) goto LAB_140021441;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_140021441;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14002147c =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_140021514;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_140021514;
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
LAB_140021514:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140021560 =====

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
              if (&UNK_1400172df < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 1400215e0 =====

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
    if (*ppuVar3 != (undefined *)0x0) goto LAB_1400216dd;
  }
LAB_1400216e6:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_1400216dd:
  if (ppuVar3 == (undefined **)0x0) goto LAB_1400216e6;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_1400216ae:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_1400216ae;
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
    if (&UNK_1400172df < ppuVar3) goto LAB_1400216e6;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1400216dd;
}



===== AiProcessNotifyRoutine @ 140021710 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void AiProcessNotifyRoutine(longlong ******param_1,undefined8 param_2,longlong param_3)

{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined *puVar6;
  longlong lVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  undefined1 auStackY_118 [32];
  wchar_t *local_c8;
  ulonglong local_c0;
  ulonglong local_b8 [2];
  undefined8 local_a8 [4];
  ulonglong *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  ulonglong *local_78;
  int local_70 [2];
  ulonglong *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  ulonglong *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_118;
  local_c8 = (wchar_t *)0x0;
  uVar9 = 0;
  if (param_3 == 0) {
    AiRemoveProcFromTracking(param_1,param_2);
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      puVar6 = &DAT_140008258;
      if (*(undefined **)(param_3 + 0x38) != (undefined *)0x0) {
        puVar6 = *(undefined **)(param_3 + 0x38);
      }
      WPP_SF_qDDZcZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar6,WPP_GLOBAL_Control,param_1,
                    (char)param_2,(char)*(undefined4 *)(param_3 + 0x10),
                    *(wchar_t **)(param_3 + 0x30),
                    (-((*(uint *)(param_3 + 8) & 1) != 0) & 0xbU) + 0x4e,(wchar_t *)puVar6);
    }
    lVar4 = AiQueryPerformanceCounter((undefined8 *)0x0,'\x01');
    if ((*(uint *)(param_3 + 8) & 1) == 0) {
      iVar3 = SeLocateProcessImageName(param_1,&local_c8);
      *(int *)(param_3 + 0x40) = iVar3;
      if (iVar3 < 0) goto LAB_1400219e4;
      uVar9 = *(undefined8 *)(param_3 + 0x30);
      *(wchar_t **)(param_3 + 0x30) = local_c8;
    }
    else {
      local_c8 = *(wchar_t **)(param_3 + 0x30);
    }
    lVar7 = *(longlong *)(param_3 + 0x28);
    uVar5 = AipCreateProcessNotifyRoutine(param_2,local_c8,lVar7,(longlong)param_1,param_3);
    uVar8 = CONCAT71((int7)((ulonglong)lVar7 >> 8),1);
    *(int *)(param_3 + 0x40) = (int)uVar5;
    uVar5 = AiUpdatePerfTime((longlong *)&AiPerfStats,lVar4,'\x01');
    if (500000 < uVar5) {
      uVar2 = AiGetFileNameFromPath((ushort *)local_c8);
      uVar8 = (ulonglong)uVar2;
      if (4 < DAT_140018000) {
        if (((_DAT_140018010 & 0x200000000000) == 0) ||
           ((DAT_140018018 & 0x200000000000) != DAT_140018018)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (bVar1) {
          local_7c = 0;
          local_70[1] = 0;
          local_5c = 0;
          local_4c = 0;
          local_80 = 2;
          local_60 = 8;
          local_50 = 8;
          local_78 = (ulonglong *)
                     (*(longlong *)(local_c8 + 4) + (((ushort)*local_c8 >> 1) - uVar8) * 2);
          local_88 = (ulonglong *)local_70;
          local_70[0] = (uint)uVar2 + (uint)uVar2;
          local_68 = &local_c0;
          local_b8[0] = (ulonglong)*(int *)(param_3 + 0x40);
          local_58 = local_b8;
          local_c0 = uVar5;
          _tlgWriteTransfer_EtwWriteTransfer(local_78,&DAT_140014f14,uVar8,param_1,6,local_a8);
        }
      }
    }
    if (49999 < DAT_140018648) {
      if (4 < DAT_140018000) {
        if (((_DAT_140018010 & 0x200000000000) == 0) ||
           ((DAT_140018018 & 0x200000000000) != DAT_140018018)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (bVar1) {
          local_7c = 0;
          local_70[1] = 0;
          local_b8[0] = AiPerfStats / DAT_140018648;
          local_80 = 8;
          local_88 = local_b8;
          local_78 = &local_c0;
          local_c0 = DAT_140018648;
          local_70[0] = 8;
          _tlgWriteTransfer_EtwWriteTransfer(DAT_140018648,&DAT_140014ebf,uVar8,param_1,4,local_a8);
        }
      }
      AiResetPerfTimeCounter(&AiPerfStats);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_e716c585d1643cef6ac097e6d79a981c_Traceguids);
    }
  }
LAB_1400219e4:
  if ((local_c8 != (wchar_t *)0x0) && ((*(uint *)(param_3 + 8) & 1) == 0)) {
    *(undefined8 *)(param_3 + 0x30) = uVar9;
    ExFreePoolWithTag(local_c8,0);
  }
  return;
}



===== AipCreateProcessNotifyRoutine @ 140021a2c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong AipCreateProcessNotifyRoutine
                    (undefined8 param_1,wchar_t *param_2,longlong param_3,longlong param_4,
                    undefined8 param_5)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  char cVar4;
  uint uVar5;
  ulonglong uVar6;
  wchar_t *pwVar7;
  longlong lVar8;
  undefined8 uVar9;
  longlong lVar10;
  undefined *puVar11;
  wchar_t *pwVar12;
  wchar_t *pwVar13;
  wchar_t **ppwVar14;
  wchar_t *pwVar15;
  wchar_t *pwVar16;
  undefined1 auStackY_178 [32];
  char local_118;
  byte local_117;
  byte local_116;
  char local_115;
  char local_114 [4];
  longlong local_110;
  wchar_t *local_108;
  undefined8 local_100;
  wchar_t *local_f8;
  wchar_t *local_f0;
  longlong local_e8;
  longlong local_e0;
  wchar_t local_d8 [4];
  longlong lStack_d0;
  ulonglong local_c8;
  longlong lStack_c0;
  longlong local_b8;
  undefined4 local_b0;
  undefined8 local_ac;
  undefined4 local_a4;
  undefined8 local_98 [4];
  longlong *local_78;
  undefined8 local_70;
  byte *local_68;
  undefined8 local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_178;
  local_f0 = (wchar_t *)0x0;
  local_110 = 0;
  local_116 = 0;
  local_114[0] = '\0';
  local_108 = (wchar_t *)0x0;
  pwVar15 = (wchar_t *)0x0;
  local_115 = '\0';
  local_d8[0] = L'\0';
  local_d8[1] = L'\0';
  local_d8[2] = L'\0';
  local_d8[3] = L'\0';
  lStack_d0 = 0;
  local_118 = '\0';
  local_c8 = 0;
  lStack_c0 = 0;
  local_100 = param_1;
  local_f8 = param_2;
  local_e8 = param_4;
  local_e0 = param_3;
  uVar6 = RtlRunOnceExecuteOnce(&AipInitRunOnceState,AipInitRunOnce,0,0);
  if ((int)uVar6 < 0) {
    return uVar6;
  }
  pwVar7 = (wchar_t *)SrpGetPolicy();
  if (pwVar7 == (wchar_t *)0x0) {
    return 0xc0000364;
  }
  lVar8 = AiQueryPerformanceCounter((undefined8 *)0x0,'\0');
  pwVar16 = local_d8;
  uVar5 = AiCapturePackageMoniker(param_4,&local_116,(longlong)local_114,pwVar16);
  ppwVar14 = (wchar_t **)0x0;
  AiUpdatePerfTime((longlong *)&DAT_1400186f0,lVar8,'\0');
  bVar2 = local_116;
  pwVar13 = (wchar_t *)0x0;
  if (-1 < (int)uVar5) {
    if (((local_116 != 0) && ((char)pwVar7[0x9a] == '\0')) &&
       ((*(int *)(pwVar7 + 0x40) < 0 || (*(int *)(*(longlong *)(pwVar7 + 0x44) + 0xc) == 0)))) {
      uVar6 = Feature_Servicing_ApplockerNoisyLogs__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar6 == 0) {
        uVar9 = SrpIsOnlySmartAppControlEnabledForPolicyType((longlong)pwVar7,0);
        cVar3 = (char)uVar9;
      }
      else {
        cVar3 = SrpIsOnlySmartLockerEnabledForPolicyType((longlong)pwVar7,0);
      }
      if (cVar3 != '\0') {
        uVar5 = 0;
        goto LAB_140021d92;
      }
    }
    ppwVar14 = &local_108;
    uVar5 = AiGetTokens(local_100,(ulonglong *)&local_f0,(ulonglong *)ppwVar14);
    pwVar15 = local_f0;
    if ((((-1 < (int)uVar5) &&
         (uVar5 = AiIsTokenSandBoxed((char)local_f0,&local_115), -1 < (int)uVar5)) &&
        (local_115 == '\0')) && (uVar5 = SrpIsTokenService(pwVar15,&local_118), -1 < (int)uVar5)) {
      lVar8 = AiQueryPerformanceCounter((undefined8 *)0x0,'\0');
      uVar5 = AiOpenImageFile(param_2,local_e0,&local_110);
      ppwVar14 = (wchar_t **)0x0;
      AiUpdatePerfTime((longlong *)&DAT_140018660,lVar8,'\0');
      pwVar13 = local_108;
      cVar3 = local_118;
      if (-1 < (int)uVar5) {
        if (bVar2 == 0) {
          pwVar16 = (wchar_t *)CONCAT71((int7)((ulonglong)pwVar16 >> 8),1);
          ppwVar14 = (wchar_t **)0x0;
          uVar6 = SrpServiceBypass((longlong)pwVar7,local_118,0,'\x01');
          if ((char)uVar6 != '\0') goto LAB_140021d92;
          uVar6 = Feature_Servicing_ApplockerNoisyLogs__private_IsEnabledDeviceUsageNoInline();
          if ((int)uVar6 == 0) {
            uVar9 = SrpIsOnlySmartAppControlEnabledForPolicyType((longlong)pwVar7,0);
            cVar4 = (char)uVar9;
          }
          else {
            cVar4 = SrpIsOnlySmartLockerEnabledForPolicyType((longlong)pwVar7,0);
          }
          if (cVar4 == '\0') {
            pwVar16 = pwVar13;
            AiSetAttributesExe((longlong)pwVar7,local_110,(longlong)pwVar15,(longlong)pwVar13,cVar3)
            ;
          }
        }
        else {
          pwVar16 = pwVar15;
          AiSetAttributesAppx(local_110,(ushort *)local_d8,local_114[0],(longlong)pwVar15,
                              (longlong)local_108,&local_c8);
          cVar4 = '\0';
        }
        lVar8 = local_e8;
        local_ac = 0;
        local_a4 = 0;
        ppwVar14 = (wchar_t **)0x44497041;
        local_b8 = local_e8;
        local_b0 = 0xc0000001;
        lVar10 = ExAllocatePool2();
        if (lVar10 == 0) {
          uVar5 = 0xc0000017;
        }
        else {
          *(undefined8 *)(lVar10 + 0x38) = param_5;
          *(undefined8 *)(lVar10 + 0x28) = local_100;
          *(longlong **)(lVar10 + 0x40) = &local_b8;
          *(longlong *)(lVar10 + 0x20) = lVar8;
          *(wchar_t **)(lVar10 + 0x30) = pwVar13;
          lVar8 = AiQueryPerformanceCounter((undefined8 *)0x0,'\0');
          pwVar16 = (wchar_t *)CONCAT71((int7)((ulonglong)pwVar16 >> 8),cVar4);
          pwVar12 = local_f8;
          if (bVar2 != 0) {
            pwVar12 = (wchar_t *)0x0;
          }
          uVar5 = SrpVerifyProcess((longlong)pwVar13,(longlong)pwVar15,pwVar7,cVar4,pwVar12,
                                   (char)local_100,(uint)bVar2,
                                   (wchar_t *)(-(ulonglong)(bVar2 != 0) & (ulonglong)&local_c8),
                                   lVar10,local_118,local_e0,local_110);
          ppwVar14 = (wchar_t **)0x0;
          AiUpdatePerfTime((longlong *)&DAT_1400186e0,lVar8,'\0');
          ExFreePoolWithTag(lVar10,0);
        }
        param_2 = local_f8;
        goto LAB_140021d92;
      }
    }
    pwVar13 = local_108;
  }
LAB_140021d92:
  AiCleanTokens((longlong)pwVar15,(longlong)pwVar13);
  if (local_110 != 0) {
    ZwClose();
  }
  if (((uVar5 + 0x80000000 & 0x80000000) == 0) && (uVar5 != 0xc0000364)) {
    puVar11 = WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      puVar11 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      ppwVar14 = (wchar_t **)&WPP_e716c585d1643cef6ac097e6d79a981c_Traceguids;
      pwVar13 = (wchar_t *)0xc;
      pwVar16 = param_2;
      WPP_SF_ZD(puVar11,0xc,&WPP_e716c585d1643cef6ac097e6d79a981c_Traceguids,param_2,(char)uVar5);
    }
    if (4 < DAT_140018000) {
      pwVar13 = (wchar_t *)0x200000000000;
      if (((_DAT_140018010 & 0x200000000000) == 0) ||
         (bVar1 = true, (DAT_140018018 & 0x200000000000) != DAT_140018018)) {
        bVar1 = false;
      }
      if (bVar1) {
        local_e8 = (longlong)(int)uVar5;
        pwVar13 = L"Ћ";
        local_78 = &local_e8;
        local_68 = &local_117;
        local_70 = 8;
        local_117 = bVar2;
        local_60 = 1;
        _tlgWriteTransfer_EtwWriteTransfer(puVar11,&DAT_140014e86,ppwVar14,pwVar16,4,local_98);
      }
    }
    pwVar15 = local_d8;
    if (bVar2 == 0) {
      pwVar15 = param_2;
    }
    AiLogFileAndStatusEvent(DAT_1400187b8,pwVar13,pwVar15,uVar5);
  }
  if (lStack_d0 != 0) {
    ExFreePoolWithTag(lStack_d0,0);
  }
  if (lStack_c0 != 0) {
    ExFreePoolWithTag(lStack_c0,0);
  }
  if ((int)uVar5 < 0) {
    uVar5 = uVar5 & -(uint)(*(char *)((ulonglong)(-(uint)(bVar2 != 0) & 0x30) + 0x105 +
                                     (longlong)pwVar7) != '\0');
  }
  ReleasePolicyRef((int *)(pwVar7 + -4));
  return (ulonglong)uVar5;
}



===== AipInitRunOnce @ 140021f20 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint AipInitRunOnce(void)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  wchar_t local_68 [4];
  wchar_t *local_60;
  wchar_t local_58 [4];
  wchar_t *local_50;
  wchar_t local_48 [4];
  wchar_t *local_40;
  wchar_t local_38 [4];
  wchar_t *local_30;
  wchar_t local_28 [4];
  wchar_t *local_20;
  wchar_t local_18 [4];
  undefined8 uStack_10;
  
  local_48[0] = L'\x12';
  local_48[1] = L'\x14';
  local_48[2] = L'\0';
  local_48[3] = L'\0';
  local_40 = L"%OSDRIVE%";
  local_58[0] = L'\x10';
  local_58[1] = L'\x12';
  local_58[2] = L'\0';
  local_58[3] = L'\0';
  local_50 = L"%WINDIR%";
  local_68[0] = L'\x14';
  local_68[1] = L'\x16';
  local_68[2] = L'\0';
  local_68[3] = L'\0';
  local_60 = L"%SYSTEM32%";
  local_38[0] = L'\"';
  local_38[1] = L'$';
  local_38[2] = L'\0';
  local_38[3] = L'\0';
  local_30 = L"%WINDIR%\\System32";
  local_28[0] = L'\"';
  local_28[1] = L'$';
  local_28[2] = L'\0';
  local_28[3] = L'\0';
  local_20 = L"%WINDIR%\\SysWOW64";
  local_18[0] = L'\0';
  local_18[1] = L'\0';
  local_18[2] = L'\0';
  local_18[3] = L'\0';
  uStack_10 = 0;
  memset(&AipPathMacroList,0,0x48);
  _DAT_1400185e0 = &DAT_1400185d8;
  DAT_1400185d8 = &DAT_1400185d8;
  AipPathMacroListInitialized = 1;
  DAT_1400185a4 = 1;
  uVar2 = RtlGetNtSystemRoot();
  RtlInitUnicodeString(local_18,uVar2);
  uVar1 = AipAddPathMacro(local_68 + 8,local_18,0xc);
  if (-1 < (int)uVar1) {
    DAT_1400185b0 = uStack_10;
    _DAT_1400185a8 = CONCAT62(local_18._2_6_,4);
    uVar1 = AipConvertToNtPath((ulonglong *)&DAT_1400185a8,(ulonglong *)&DAT_1400185b8);
    if (-1 < (int)uVar1) {
      uVar1 = AipAddPathMacro(local_68 + 0x10,(wchar_t *)&DAT_1400185b8,0xc);
      if (-1 < (int)uVar1) {
        uVar1 = AipAddPathMacro(local_68,local_68 + 0x18,8);
        if (-1 < (int)uVar1) {
          if (DAT_1400185a4 != 0) {
            uVar1 = AipAddPathMacro(local_68,local_68 + 0x20,8);
            if ((int)uVar1 < 0) goto LAB_1400220a4;
          }
          uVar2 = AipExpandPathMacros();
          uVar1 = (uint)uVar2;
          if (-1 < (int)uVar1) {
            uVar3 = AiInitializeSoftwarePathMacroList();
            uVar1 = (uint)uVar3;
            if (-1 < (int)uVar1) {
              uVar1 = AiInitializeLastWriteTime();
              if (-1 < (int)uVar1) {
                uVar3 = SrpUpdatePolicy();
                uVar1 = (uint)uVar3;
              }
            }
          }
        }
      }
    }
  }
LAB_1400220a4:
  return ~uVar1 >> 0x1f;
}



===== AiIsAppxInbox @ 1400220bc =====

int AiIsAppxInbox(undefined8 *param_1,undefined1 *param_2)

{
  int iVar1;
  undefined1 uVar2;
  
  iVar1 = *(int *)(param_1 + 1);
  uVar2 = 0;
  if (iVar1 < 0) {
    iVar1 = AipGetPackageClaim(*param_1,(undefined8 *)((longlong)param_1 + 0xc));
    *(int *)(param_1 + 1) = iVar1;
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  if (((*(uint *)(param_1 + 2) & 0xff) == 2) ||
     ((AiEnablePublisherId != '\0' && ((*(uint *)(param_1 + 2) & 0xff) == 0)))) {
    uVar2 = 1;
  }
  *param_2 = uVar2;
  return iVar1;
}



===== AipGetPackageClaim @ 140022128 =====

undefined4 AipGetPackageClaim(undefined8 param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  
  *param_2 = 0;
  lVar2 = PsReferencePrimaryToken();
  if (lVar2 == 0) {
    uVar1 = 0xc000000d;
  }
  else {
    uVar1 = RtlQueryPackageClaims(lVar2,0,0,0,0,0,param_2,0);
    ObfDereferenceObject(lVar2);
  }
  return uVar1;
}



===== PluginInvokeCallback @ 1400221b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int PluginInvokeCallback(longlong *param_1,undefined8 param_2,longlong *param_3)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 auStackY_c8 [32];
  longlong local_78 [2];
  undefined8 local_68 [4];
  longlong local_48;
  undefined8 local_40;
  longlong local_38;
  undefined8 local_30;
  longlong *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  if ((*param_1 == *(longlong *)*param_3) && (param_1[1] == ((longlong *)*param_3)[1])) {
    lVar4 = param_3[4];
    lVar3 = param_3[1];
    iVar2 = (*(code *)param_1[5])(lVar3,(int)param_3[2],param_3[3]);
    local_78[0] = (longlong)iVar2;
    if (iVar2 < 0) {
      if (4 < DAT_140018000) {
        if (((_DAT_140018010 & 0x200000000000) == 0) ||
           (bVar1 = true, (DAT_140018018 & 0x200000000000) != DAT_140018018)) {
          bVar1 = false;
        }
        if (bVar1) {
          local_48 = *param_3;
          local_38 = param_3[1];
          local_28 = local_78;
          local_40 = 0x10;
          local_30 = 0x10;
          local_20 = 8;
          _tlgWriteTransfer_EtwWriteTransfer(lVar3,&DAT_140015070,0x200000000000,lVar4,5,local_68);
        }
      }
    }
    else {
      iVar2 = *(int *)param_3[9];
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



===== SmartlockerAddChildProcToTrackedListIfParentPresent @ 140022304 =====

ulonglong SmartlockerAddChildProcToTrackedListIfParentPresent(undefined8 param_1)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  longlong local_res10;
  
  local_res10 = 0;
  uVar2 = ObReferenceObjectByHandle
                    (0xffffffffffffffff,0x1fffff,*(undefined8 *)PsProcessType_exref,0,&local_res10,0
                    );
  uVar3 = (ulonglong)uVar2;
  if (-1 < (int)uVar2) {
    uVar3 = 0;
    ExAcquireResourceSharedLite(&DAT_1400188a0,1);
    lVar1 = local_res10;
    for (puVar4 = DAT_140018870; (undefined8 **)puVar4 != &DAT_140018870;
        puVar4 = (undefined8 *)*puVar4) {
      if (local_res10 == puVar4[2]) goto LAB_140022391;
    }
    puVar4 = (undefined8 *)0x0;
LAB_140022391:
    ExReleaseResourceLite(&DAT_1400188a0);
    if (puVar4 != (undefined8 *)0x0) {
      uVar3 = AiAddProcToTrackedList(param_1);
      uVar3 = uVar3 & 0xffffffff;
    }
    ObfDereferenceObject(lVar1);
  }
  return uVar3;
}



===== SmartlockerCheckEA @ 1400223e0 =====

int SmartlockerCheckEA(longlong param_1,longlong param_2,undefined8 param_3,longlong param_4,
                      uint *param_5,longlong *param_6,undefined8 *param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  uint uVar5;
  int iVar6;
  uint local_28 [2];
  longlong local_20;
  
  local_20 = 0;
  local_28[0] = 0;
  iVar2 = SmartlockerGetValidEA(param_3,param_4,local_28,&local_20,param_7);
  lVar4 = local_20;
  uVar5 = local_28[0];
  if (iVar2 < 0) {
    return iVar2;
  }
  if (local_20 == 0) {
    return iVar2;
  }
  if (*(uint *)(local_20 + 0x34) < DAT_140018744) {
    iVar6 = -0x3fffffff;
    goto LAB_1400224de;
  }
  iVar2 = *(int *)(local_20 + 8);
  iVar1 = *(int *)(local_20 + 0xc);
  if (iVar2 == 0) {
LAB_14002248f:
    *(undefined4 *)(local_20 + 8) = 2;
    *(int *)(local_20 + 0xc) = *(int *)(local_20 + 0xc) + 1;
LAB_140022499:
    iVar6 = 0;
  }
  else {
    if (iVar2 == 1) {
      *(undefined4 *)(local_20 + 8) = 0;
      *(undefined4 *)(local_20 + 0xc) = 0;
      goto LAB_140022499;
    }
    if (iVar2 == 2) {
      *(int *)(local_20 + 0xc) = iVar1 + 1;
    }
    else if ((iVar2 == 3) || (iVar2 == 4)) goto LAB_14002248f;
    iVar6 = -0x3fffffff;
  }
  iVar3 = SmartlockerTagProcessToken(param_1,local_28[0],local_20);
  if (iVar3 < 0) {
    lVar4 = 0;
    uVar5 = 0;
    iVar6 = iVar3;
  }
  if ((param_2 != param_1) && (iVar3 = SmartlockerTagProcessToken(param_2,uVar5,lVar4), iVar3 < 0))
  {
    lVar4 = 0;
    iVar6 = iVar3;
    uVar5 = 0;
  }
  local_28[0] = uVar5;
  if (lVar4 != 0) {
    *(int *)(lVar4 + 8) = iVar2;
    *(int *)(lVar4 + 0xc) = iVar1;
  }
LAB_1400224de:
  *param_5 = local_28[0];
  *param_6 = lVar4;
  return iVar6;
}



===== SmartlockerCheckUninstallStringEA @ 14002253c =====

int SmartlockerCheckUninstallStringEA
              (longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4,uint *param_5
              ,longlong *param_6)

{
  byte bVar1;
  longlong lVar2;
  int iVar3;
  ushort *puVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  wchar_t *pwVar7;
  longlong lVar8;
  byte *pbVar9;
  uint uVar10;
  byte local_68 [4];
  uint local_64;
  uint local_60;
  uint local_5c;
  longlong local_58;
  longlong local_50;
  longlong local_48;
  wchar_t local_40;
  undefined1 auStack_3e [6];
  longlong lStack_38;
  
  local_50 = 0;
  local_5c = 0;
  local_48 = 0;
  puVar4 = (ushort *)0x0;
  local_64 = 0;
  lVar8 = 0;
  local_68[0] = 0;
  uVar10 = 0;
  local_58 = 0;
  _local_40 = 0;
  lStack_38 = 0;
  local_60 = 0;
  iVar3 = AiGetUninstallStringEa(param_4,&local_50,&local_5c,&local_48);
  lVar2 = local_50;
  if (-1 < iVar3) {
    if ((local_50 == 0) || (local_5c == 0)) {
      iVar3 = -0x3ffffddb;
    }
    else {
      iVar3 = PsQueryProcessCommandLine(param_3,0,0,0,&local_64);
      if (iVar3 == -0x3ffffffc) {
        puVar4 = (ushort *)AiAlloc((ulonglong)local_64);
        if (puVar4 == (ushort *)0x0) {
          iVar3 = -0x3fffffe9;
        }
        else {
          iVar3 = PsQueryProcessCommandLine(param_3,puVar4,local_64,0,&local_64);
          if (-1 < iVar3) {
            lStack_38 = lVar2 + 0x28;
            pbVar9 = local_68;
            pwVar7 = &local_40;
            _local_40 = CONCAT62(CONCAT42(auStack_3e._2_4_,*(undefined2 *)(lVar2 + 0x24)),
                                 *(undefined2 *)(lVar2 + 0x24));
            uVar5 = AiIsStringNoQuotePrefixedByDelimitedUninstallString
                              (puVar4,(undefined8 *)pwVar7,(char *)pbVar9);
            bVar1 = local_68[0];
            iVar3 = (int)uVar5;
            if (-1 < iVar3) {
              if (local_68[0] == 0) {
                iVar3 = -0x3fffffff;
              }
              else {
                pwVar7 = (wchar_t *)0x4;
                uVar6 = SmartlockerConstructOriginClaim
                                  (1,4,pbVar9,0,puVar4,(int *)&local_60,&local_58);
                lVar8 = local_58;
                uVar10 = local_60;
                iVar3 = (int)uVar6;
                if (-1 < iVar3) {
                  uVar6 = *(undefined8 *)(lVar2 + 0xc);
                  pwVar7 = (wchar_t *)(ulonglong)local_60;
                  *(undefined8 *)(local_58 + 0x10) = *(undefined8 *)(lVar2 + 4);
                  *(undefined8 *)(local_58 + 0x18) = uVar6;
                  uVar6 = *(undefined8 *)(lVar2 + 0x1c);
                  *(undefined8 *)(local_58 + 0x20) = *(undefined8 *)(lVar2 + 0x14);
                  *(undefined8 *)(local_58 + 0x28) = uVar6;
                  iVar3 = SmartlockerTagProcessToken(param_1,local_60,local_58);
                  if ((-1 < iVar3) && (param_1 != param_2)) {
                    pwVar7 = (wchar_t *)(ulonglong)uVar10;
                    iVar3 = SmartlockerTagProcessToken(param_2,uVar10,lVar8);
                  }
                }
              }
            }
            AiLogCheckCmdlineAgainstUninstallString
                      (DAT_140018718,pwVar7,&local_40,puVar4,bVar1,iVar3);
            goto LAB_14002270a;
          }
        }
      }
      else {
LAB_14002270a:
        if (-1 < iVar3) goto LAB_140022733;
        if (lVar8 != 0) {
          ExFreePoolWithTag(lVar8,0x41746d73);
        }
      }
    }
  }
  lVar8 = 0;
  uVar10 = 0;
LAB_140022733:
  *param_5 = uVar10;
  *param_6 = lVar8;
  if (puVar4 != (ushort *)0x0) {
    ExFreePoolWithTag(puVar4,0);
  }
  if (local_48 != 0) {
    ExFreePoolWithTag(local_48,0);
  }
  return iVar3;
}



===== SmartlockerConstructOriginClaim @ 140022798 =====

undefined8
SmartlockerConstructOriginClaim
          (uint param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,ushort *param_5,
          int *param_6,undefined8 *param_7)

{
  undefined8 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0x40;
  if (param_5 != (ushort *)0x0) {
    iVar3 = *param_5 + 0x40;
  }
  if (param_1 < 2) {
    puVar2 = (undefined4 *)ExAllocatePool2(0x100,iVar3,0x41746d73);
    if (puVar2 == (undefined4 *)0x0) {
      uVar1 = 0xc0000017;
    }
    else {
      *puVar2 = 1;
      puVar2[1] = param_1;
      puVar2[2] = param_2;
      puVar2[3] = 1;
      BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,(PUCHAR)(puVar2 + 4),0x10,2);
      if (param_1 == 0) {
        *(undefined8 *)(puVar2 + 8) = *(undefined8 *)(puVar2 + 4);
        *(undefined8 *)(puVar2 + 10) = *(undefined8 *)(puVar2 + 6);
      }
      else {
        BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,(PUCHAR)(puVar2 + 8),0x10,2);
      }
      puVar2[0xc] = param_4;
      puVar2[0xd] = DAT_140018740;
      if (param_5 == (ushort *)0x0) {
        puVar2[0xe] = 0;
      }
      else {
        puVar2[0xe] = (uint)*param_5;
        memmove(puVar2 + 0xf,*(void **)(param_5 + 4),(ulonglong)*param_5);
      }
      *(undefined2 *)((longlong)puVar2 + (ulonglong)((uint)puVar2[0xe] >> 1) * 2 + 0x3c) = 0;
      *param_6 = iVar3;
      *param_7 = puVar2;
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== SmartlockerManagedInstallerCheck @ 1400228d8 =====

ulonglong SmartlockerManagedInstallerCheck
                    (longlong param_1,longlong param_2,longlong param_3,wchar_t *param_4,
                    undefined1 param_5,int *param_6,longlong *param_7)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  int iVar4;
  ulonglong uVar5;
  wchar_t *pwVar6;
  uint local_res18 [4];
  int local_28 [2];
  longlong local_20;
  
  local_res18[0] = 0;
  lVar3 = 0;
  local_28[0] = 0;
  local_20 = 0;
  pwVar6 = param_4;
  uVar1 = SrppAccessCheck(param_1,(wchar_t *)(param_3 + 0x90),param_4,param_5,'\0',local_res18);
  if (((int)uVar1 < 0) || ((local_res18[0] & 0x10000) == 0)) {
    uVar5 = 0xc0000001;
  }
  else {
    uVar2 = SmartlockerConstructOriginClaim(0,0,pwVar6,0,(ushort *)param_4,local_28,&local_20);
    lVar3 = local_20;
    iVar4 = local_28[0];
    uVar5 = uVar2 & 0xffffffff;
    if (-1 < (int)uVar2) {
      uVar1 = SmartlockerTagProcessToken(param_1,local_28[0],local_20);
      uVar5 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        if (param_2 == param_1) goto LAB_1400229b9;
        uVar1 = SmartlockerTagProcessToken(param_2,iVar4,lVar3);
        uVar5 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) goto LAB_1400229b9;
      }
    }
  }
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0x41746d73);
  }
  lVar3 = 0;
  iVar4 = 0;
LAB_1400229b9:
  *param_6 = iVar4;
  *param_7 = lVar3;
  return uVar5;
}



===== SmartlockerOriginClaimProcessTokenCheck @ 1400229ec =====

undefined8
SmartlockerOriginClaimProcessTokenCheck
          (undefined8 param_1,char param_2,undefined1 *param_3,uint *param_4,longlong *param_5,
          longlong *param_6)

{
  longlong *plVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  undefined8 uVar7;
  uint uVar8;
  uint local_38 [4];
  
  lVar5 = 0;
  local_38[0] = 0;
  uVar8 = 0x146;
  uVar6 = 0x1b4;
  do {
    lVar4 = ExAllocatePool2(0x102,uVar6,0x41746d73);
    if (lVar4 == 0) {
LAB_140022b54:
      uVar7 = 0xc0000001;
LAB_140022b59:
      *param_4 = -(uint)(lVar5 != 0) & uVar8;
      *param_5 = lVar5;
      *param_6 = lVar4;
      return uVar7;
    }
    iVar3 = ZwQuerySecurityAttributesToken(param_1,&DAT_140008338,1,lVar4,uVar6,local_38);
    uVar2 = local_38[0];
    if (iVar3 != -0x3fffffdd) {
      if (-1 < iVar3) {
        uVar7 = 0xc0000001;
        if ((*(int *)(lVar4 + 4) != 0) && (*(short *)(*(longlong *)(lVar4 + 8) + 0x10) == 0x10)) {
          plVar1 = *(longlong **)(*(longlong *)(lVar4 + 8) + 0x20);
          uVar6 = *(uint *)(plVar1 + 1);
          if (0x3f < uVar6) {
            lVar5 = *plVar1;
            if ((*(uint *)(lVar5 + 8) < 2) || (*(uint *)(lVar5 + 8) == 4)) {
              uVar7 = 0;
            }
            uVar8 = uVar6;
            if ((((param_2 != '\0') && (*(int *)(lVar5 + 4) == 0)) &&
                (*(longlong *)(lVar5 + 0x20) == *(longlong *)(lVar5 + 0x10))) &&
               (*(longlong *)(lVar5 + 0x28) == *(longlong *)(lVar5 + 0x18))) {
              if (param_3 != (undefined1 *)0x0) {
                *param_3 = 1;
              }
              BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,(PUCHAR)(lVar5 + 0x20),0x10,2);
              SmartlockerTagProcessToken(param_1,uVar6,lVar5);
            }
          }
        }
        goto LAB_140022b59;
      }
LAB_140022b3e:
      ExFreePoolWithTag(lVar4);
      lVar4 = 0;
      goto LAB_140022b54;
    }
    if (local_38[0] <= uVar6) goto LAB_140022b3e;
    ExFreePoolWithTag(lVar4,0x41746d73);
    uVar6 = uVar2;
  } while( true );
}



===== SmartlockerRegistryDisableOverrideIsSet @ 140022bac =====

undefined8 SmartlockerRegistryDisableOverrideIsSet(void)

{
  int iVar1;
  undefined8 uVar2;
  longlong local_res8;
  undefined8 local_28;
  wchar_t *local_20;
  undefined8 local_18;
  wchar_t *local_10;
  
  local_18 = 0xa600a4;
  local_10 = 
  L"\\REGISTRY\\MACHINE\\System\\CurrentControlSet\\Control\\AppID\\Configuration\\SMARTLOCKER";
  local_28 = 0x120010;
  uVar2 = 0;
  local_20 = L"DISABLED";
  local_res8 = 0;
  iVar1 = AiRegReadQwordValue(0,&local_18,&local_28,&local_res8);
  if ((-1 < iVar1) && (local_res8 != 0)) {
    uVar2 = 1;
  }
  return uVar2;
}



===== SmartlockerSmartScreenRegistryIsEnabled @ 140022c1c =====

undefined8 SmartlockerSmartScreenRegistryIsEnabled(void)

{
  int iVar1;
  undefined8 uVar2;
  longlong local_res8;
  undefined8 local_28;
  wchar_t *local_20;
  undefined8 local_18;
  wchar_t *local_10;
  
  local_18 = 0xa600a4;
  local_10 = 
  L"\\REGISTRY\\MACHINE\\System\\CurrentControlSet\\Control\\AppID\\Configuration\\SMARTLOCKER";
  local_28 = 0x10000e;
  uVar2 = 0;
  local_20 = L"ENABLED";
  local_res8 = 0;
  iVar1 = AiRegReadQwordValue(0,&local_18,&local_28,&local_res8);
  if ((-1 < iVar1) && (local_res8 != 0)) {
    uVar2 = 1;
  }
  return uVar2;
}



===== SmartlockerSmartscreenProcessTokenCheck @ 140022c8c =====

ulonglong SmartlockerSmartscreenProcessTokenCheck
                    (longlong param_1,longlong param_2,int *param_3,longlong *param_4)

{
  undefined8 *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  longlong lVar11;
  undefined8 in_stack_ffffffffffffff48;
  undefined4 uVar12;
  char local_98 [4];
  uint local_94;
  int local_90 [2];
  longlong local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  wchar_t *local_70;
  undefined8 local_68;
  wchar_t *local_60;
  undefined8 local_58;
  wchar_t *local_50;
  ushort local_48 [8];
  
  local_58 = 0x140012;
  local_90[0] = 0;
  local_50 = L"Microsoft";
  local_88 = 0;
  local_60 = L"WindowsLockdownPolicySettings";
  local_94 = 0;
  local_70 = L"ISGSmartscreenTrustSuppressed";
  iVar5 = 0;
  lVar11 = 0;
  local_68 = 0x3c003a;
  local_78 = 0x3c003a;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  local_48[6] = 0;
  local_48[7] = 0;
  local_7c = 0;
  local_98[0] = '\0';
  local_80 = 1;
  uVar6 = 0x28e;
  do {
    uVar12 = (undefined4)((ulonglong)in_stack_ffffffffffffff48 >> 0x20);
    lVar7 = ExAllocatePool2(0x102,uVar6,0x41746d73);
    if (lVar7 == 0) {
LAB_140022eef:
      uVar9 = 0xc0000001;
LAB_140022ef9:
      if (lVar11 != 0) {
        ExFreePoolWithTag(lVar11,0x41746d73);
      }
LAB_140022f12:
      lVar11 = 0;
      iVar5 = 0;
      if (lVar7 != 0) {
LAB_140022f1d:
        ExFreePoolWithTag(lVar7,0x41746d73);
      }
      *param_3 = iVar5;
      *param_4 = lVar11;
      return uVar9;
    }
    puVar10 = (undefined8 *)0x1;
    in_stack_ffffffffffffff48 = CONCAT44(uVar12,uVar6);
    uVar4 = ZwQuerySecurityAttributesToken
                      (param_2,&DAT_140008348,1,lVar7,in_stack_ffffffffffffff48,&local_94);
    uVar3 = local_94;
    uVar9 = (ulonglong)uVar4;
    if (uVar4 != 0xc0000023) {
      if ((int)uVar4 < 0) {
LAB_140022ed3:
        ExFreePoolWithTag(lVar7,0x41746d73);
        lVar7 = 0;
      }
      else if (((*(int *)(lVar7 + 4) != 0) && (*(short *)(*(longlong *)(lVar7 + 8) + 0x10) == 0x10))
              && (puVar1 = *(undefined8 **)(*(longlong *)(lVar7 + 8) + 0x20),
                 *(int *)(puVar1 + 1) == 0x20c)) {
        puVar2 = (uint *)*puVar1;
        if ((((byte)*puVar2 & 0x22) == 2) || ((*puVar2 & 0x58) != 0)) {
          *(undefined2 *)((longlong)puVar2 + 0x20a) = 0;
          RtlInitUnicodeString(local_48);
          if ((*puVar2 & 0x40) == 0) {
            puVar10 = &local_78;
            iVar5 = ZwQuerySecurityPolicy(&local_58,&local_68,puVar10,&local_7c,local_98,&local_80);
            if ((-1 < iVar5) && (local_98[0] != '\0')) {
              uVar9 = 0xc0000001;
              goto LAB_140022f12;
            }
          }
          uVar8 = SmartlockerConstructOriginClaim(1,0,puVar10,*puVar2,local_48,local_90,&local_88);
          lVar11 = local_88;
          iVar5 = local_90[0];
          uVar9 = uVar8 & 0xffffffff;
          if ((int)uVar8 < 0) goto LAB_140022ef9;
          uVar6 = SmartlockerTagProcessToken(param_1,local_90[0],local_88);
          uVar9 = (ulonglong)uVar6;
          if ((int)uVar6 < 0) goto LAB_140022ef9;
          if (param_1 != param_2) {
            uVar6 = SmartlockerTagProcessToken(param_2,iVar5,lVar11);
            uVar9 = (ulonglong)uVar6;
            if ((int)uVar6 < 0) goto LAB_140022ef9;
          }
        }
        if (-1 < (int)uVar9) goto LAB_140022f1d;
        goto LAB_140022ef9;
      }
      goto LAB_140022eef;
    }
    if (local_94 <= uVar6) goto LAB_140022ed3;
    ExFreePoolWithTag(lVar7,0x41746d73);
    uVar6 = uVar3;
  } while( true );
}



===== SmartlockerTagProcessToken @ 140022f64 =====

void SmartlockerTagProcessToken(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  undefined4 local_res10 [6];
  undefined4 local_58;
  undefined4 local_54;
  undefined4 *local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined8 *local_18;
  
  local_50 = &local_38;
  local_3c = 0;
  local_18 = &local_48;
  local_28 = 0x10;
  local_58 = 1;
  local_54 = 1;
  local_20 = 1;
  local_38 = 0x340032;
  uStack_34 = 0;
  uStack_30 = 0x4000aa88;
  uStack_2c = 1;
  local_24 = 0x42;
  local_res10[0] = 4;
  local_48 = param_3;
  local_40 = param_2;
  SeSetSecurityAttributesToken(0x340032,0,local_res10,&local_58);
  return;
}



===== SmartlockerTelemetrizeOriginInfo @ 140022fdc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SmartlockerTelemetrizeOriginInfo
               (undefined8 param_1,wchar_t *param_2,undefined8 param_3,int param_4,uint param_5,
               undefined1 param_6,undefined8 param_7,undefined8 param_8,char param_9,char param_10,
               uint param_11,undefined8 param_12,longlong param_13,char param_14)

{
  short *psVar1;
  ushort uVar2;
  undefined8 *puVar3;
  char cVar4;
  int iVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong lVar8;
  ulonglong uVar9;
  uint uVar10;
  undefined *puVar11;
  undefined1 auStackY_148 [32];
  undefined8 in_stack_fffffffffffffef0;
  int local_e8;
  ulonglong local_e0;
  undefined8 local_d8;
  void *local_d0;
  longlong local_c8;
  ushort local_c0 [4];
  undefined8 uStack_b8;
  wchar_t *local_b0;
  undefined8 local_a8;
  longlong lStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  UCHAR local_70 [16];
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_148;
  local_d8 = 0;
  local_78 = 0;
  local_d0 = (void *)0x0;
  local_c8 = 0;
  local_e0 = 0;
  uVar9 = 0;
  local_c0[0] = 0;
  local_c0[1] = 0;
  local_c0[2] = 0;
  local_c0[3] = 0;
  uStack_b8 = 0;
  local_a8 = 0;
  lStack_a0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_70[0] = '\0';
  local_70[1] = '\0';
  local_70[2] = '\0';
  local_70[3] = '\0';
  local_70[4] = '\0';
  local_70[5] = '\0';
  local_70[6] = '\0';
  local_70[7] = '\0';
  local_70[8] = '\0';
  local_70[9] = '\0';
  local_70[10] = '\0';
  local_70[0xb] = '\0';
  local_70[0xc] = '\0';
  local_70[0xd] = '\0';
  local_70[0xe] = '\0';
  local_70[0xf] = '\0';
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  if (((param_11 & 0xff0000) == 0x10000) || ((param_4 == 0 && (param_10 == '\0')))) {
    local_e8 = 0;
    puVar11 = &AppIdSmartlockerEnforcementStatusSuccess;
  }
  else {
    if (param_14 == '\0') {
      uVar10 = DAT_140018748 & 2;
    }
    else {
      uVar10 = DAT_140018748 & 1;
    }
    if (uVar10 == 0) {
      return;
    }
    puVar11 = &AppIdSmartlockerEnforcementStatusAudit;
    local_e8 = param_4;
    if (param_9 == '\0') {
      puVar11 = &AppIdSmartlockerEnforcementStatusFail;
    }
  }
  local_b0 = param_2;
  BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,local_70,0x10,2);
  uVar6 = PsGetCurrentProcess();
  uVar6 = PsGetProcessImageFileName(uVar6);
  RtlInitAnsiString(local_c0,uVar6);
  PsGetCurrentProcessId();
  ZwQueryInformationFile(param_3,&local_98,&local_88,0x18);
  iVar5 = ZwOpenProcessTokenEx(0xffffffffffffffff,0,0x200,&local_d8);
  if (iVar5 < 0) goto LAB_140023224;
  iVar5 = AiQueryTokenAttributes(local_d8,(longlong *)&local_e0);
  uVar9 = local_e0;
  if (-1 < iVar5) {
    uVar10 = 0;
    lVar7 = *(longlong *)(local_e0 + 8);
    if (*(int *)(local_e0 + 4) != 0) {
      do {
        cVar4 = RtlEqualUnicodeString(lVar7,&DAT_140008328,1);
        if (cVar4 != '\0') {
          if ((*(short *)(lVar7 + 0x10) == 3) && (*(uint *)(lVar7 + 0x18) != 0)) {
            puVar3 = *(undefined8 **)(lVar7 + 0x20);
            uVar10 = 0;
            goto LAB_1400231da;
          }
          break;
        }
        uVar10 = uVar10 + 1;
        lVar7 = lVar7 + 0x28;
      } while (uVar10 < *(uint *)(uVar9 + 4));
    }
  }
  goto LAB_140023213;
  while (uVar10 = uVar10 + 1, uVar10 < *(uint *)(lVar7 + 0x18)) {
LAB_1400231da:
    psVar1 = (short *)(puVar3 + (ulonglong)uVar10 * 2);
    local_a8 = *(undefined8 *)psVar1;
    lStack_a0 = *(longlong *)(psVar1 + 4);
    if ((((short *)puVar3[(ulonglong)uVar10 * 2 + 1] != (short *)0x0) && (*psVar1 != 0)) &&
       (*(short *)puVar3[(ulonglong)uVar10 * 2 + 1] != 0x25)) goto LAB_140023213;
  }
  local_a8 = *puVar3;
  lStack_a0 = puVar3[1];
LAB_140023213:
  ZwClose(local_d8);
LAB_140023224:
  if (lStack_a0 == 0) {
    local_e0 = local_e0 & 0xffffffff00000000;
    RtlUTF8ToUnicodeN(&local_60,0x20,&local_e0,uStack_b8);
  }
  iVar5 = AiQueryTokenAttributes(param_1,&local_c8);
  lVar7 = local_c8;
  if (-1 < iVar5) {
    uVar10 = 0;
    lVar8 = *(longlong *)(local_c8 + 8);
    if (*(int *)(local_c8 + 4) != 0) {
      do {
        cVar4 = RtlEqualUnicodeString(lVar8,&DAT_140008318,1);
        if (((cVar4 == '\0') &&
            (cVar4 = RtlEqualUnicodeString(lVar8,&DAT_140008308,1), cVar4 != '\0')) &&
           ((*(short *)(lVar8 + 0x10) == 4 &&
            ((*(int *)(lVar8 + 0x18) == 1 &&
             (uVar2 = *(ushort *)(*(longlong *)(lVar8 + 0x20) + 8), uVar2 - 1 < 0xffcd)))))) {
          local_d0 = (void *)AiAlloc((ulonglong)(uVar2 + 0x32));
          if (local_d0 == (void *)0x0) goto LAB_1400233e0;
          memmove(local_d0,*(void **)(*(longlong *)(lVar8 + 0x20) + 0x10),
                  (ulonglong)*(ushort *)(*(longlong *)(lVar8 + 0x20) + 8));
          RtlStringCbPrintfW((ushort *)((longlong)local_d0 + (ulonglong)(uVar2 >> 1) * 2),0x32,
                             (ushort *)L"\\%u.%u.%u.%u",**(ulonglong **)(lVar8 + 0x20) >> 0x30);
        }
        uVar10 = uVar10 + 1;
        lVar8 = lVar8 + 0x28;
      } while (uVar10 < *(uint *)(lVar7 + 4));
    }
  }
  if ((param_13 != 0) && (param_5 < 2)) {
    *(int *)(param_13 + 0xc) = *(int *)(param_13 + 0xc) + -1;
  }
  AiLogSmartlockerEnforcementStatusEvent
            (DAT_140018718,puVar11,local_b0,local_c0,(char)local_e8,(char)param_5,param_6,
             in_stack_fffffffffffffef0,&uStack_80,0,param_13 != 0,param_13);
LAB_1400233e0:
  if (uVar9 != 0) {
    ExFreePoolWithTag(uVar9,0);
  }
  if (lVar7 != 0) {
    ExFreePoolWithTag(lVar7,0);
  }
  if (local_d0 != (void *)0x0) {
    ExFreePoolWithTag(local_d0,0);
  }
  return;
}



===== SmartlockerVerifyProcess @ 140023460 =====

int SmartlockerVerifyProcess
              (longlong param_1,longlong param_2,longlong param_3,wchar_t *param_4,
              undefined1 param_5,uint param_6,longlong param_7,uint param_8,longlong param_9,
              longlong param_10,char param_11,char param_12,char param_13)

{
  char cVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong lVar6;
  void *pvVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  uint *puVar11;
  undefined8 in_stack_ffffffffffffff00;
  undefined8 in_stack_ffffffffffffff20;
  uint local_c8;
  char local_c4 [4];
  uint local_c0;
  uint local_bc;
  void *local_b8;
  longlong lStack_b0;
  longlong local_a8;
  void *local_a0;
  longlong lStack_98;
  undefined8 local_90;
  void *local_88;
  longlong lStack_80;
  undefined8 local_78;
  void *local_70;
  void *local_68;
  longlong local_60;
  longlong local_58 [4];
  
  local_b8 = (void *)0x0;
  pvVar7 = (void *)0x0;
  local_c8 = 0;
  uVar9 = 0;
  local_a0 = (void *)0x0;
  uVar8 = 5;
  local_bc = 0;
  local_70 = (void *)0x0;
  local_68 = (void *)0x0;
  local_60 = 0;
  local_88 = (void *)0x0;
  local_c0 = 0;
  local_a8 = 0;
  local_58[0] = 0;
  local_78 = 0;
  local_c4[0] = '\0';
  if ((*(int *)(param_3 + 0xb0) < 0) || (*(int *)(*(longlong *)(param_3 + 0xb8) + 0xc) == 0)) {
LAB_140023519:
    bVar10 = param_12 == '\0';
    lVar6 = param_1;
    while( true ) {
      if (local_a8 != 0) {
        ExFreePoolWithTag(local_a8,0x41746d73);
        local_a8 = 0;
      }
      uVar5 = SmartlockerOriginClaimProcessTokenCheck
                        (lVar6,bVar10,local_c4,&local_c8,(longlong *)&local_b8,&local_a8);
      iVar2 = (int)uVar5;
      if (-1 < iVar2) {
        uVar8 = 2;
        goto LAB_14002377f;
      }
      if ((iVar2 == -0x3fffffff) && (local_b8 != (void *)0x0)) break;
      if (lVar6 == param_2) goto LAB_140023592;
      lVar6 = param_2;
    }
    local_a0 = local_b8;
    local_bc = local_c8;
LAB_140023592:
    if (param_13 != '\0') {
      uVar4 = SmartlockerSmartscreenProcessTokenCheck
                        (param_1,param_2,(int *)&local_c8,(longlong *)&local_b8);
      iVar2 = (int)uVar4;
      if (-1 < iVar2) {
        uVar8 = 1;
        local_70 = local_b8;
        local_c4[0] = '\x01';
        goto LAB_14002377f;
      }
    }
    if (param_12 == '\0') {
      local_90 = 0;
      iVar2 = AiOpenTokenByProcessId((ulonglong)param_6,&local_90);
      if (iVar2 < 0) {
LAB_140023698:
        lVar6 = param_9;
        if (param_7 != 0) {
          iVar2 = SmartlockerCheckUninstallStringEA
                            (param_1,param_2,param_7,param_9,&local_c8,(longlong *)&local_b8);
          if (-1 < iVar2) {
            uVar8 = 8;
            local_68 = local_b8;
            goto LAB_14002377f;
          }
        }
        goto LAB_1400236ec;
      }
      uVar5 = SmartlockerOriginClaimProcessTokenCheck
                        (local_90,'\0',(undefined1 *)0x0,&local_c0,(longlong *)&local_88,&local_60);
      ZwClose(local_90);
      pvVar7 = local_88;
      uVar9 = local_c0;
      if (((int)uVar5 < 0) ||
         ((1 < *(uint *)((longlong)local_88 + 8) && (1 < *(uint *)((longlong)local_88 + 8) - 3))))
      goto LAB_140023698;
      local_b8 = local_88;
      local_c8 = local_c0;
      iVar2 = SmartlockerTagProcessToken(param_2,local_c0,local_88);
      if (iVar2 < 0) goto LAB_140023698;
      uVar8 = 7;
    }
    else {
      lVar6 = param_9;
LAB_1400236ec:
      iVar2 = SmartlockerCheckEA(param_1,param_2,lVar6,param_10,&local_c8,(longlong *)&local_b8,
                                 local_58);
      if ((-1 < iVar2) || ((iVar2 == -0x3fffffff && (local_b8 != (void *)0x0)))) {
        uVar8 = 3;
        goto LAB_14002377f;
      }
      if (local_a0 == (void *)0x0) {
        if (pvVar7 == (void *)0x0) goto LAB_14002377f;
        uVar8 = 7;
        iVar2 = SmartlockerTagProcessToken(param_2,uVar9,pvVar7);
      }
      else {
        uVar8 = 2;
        pvVar7 = local_a0;
        uVar9 = local_bc;
      }
    }
  }
  else {
    uVar4 = SmartlockerManagedInstallerCheck
                      (param_1,param_2,param_3,param_4,param_5,(int *)&local_c8,
                       (longlong *)&local_b8);
    iVar2 = (int)uVar4;
    if (iVar2 < 0) goto LAB_140023519;
    uVar8 = 0;
    local_70 = local_b8;
LAB_14002377f:
    pvVar7 = local_b8;
    uVar9 = local_c8;
  }
  lVar6 = param_9;
  local_bc = 0;
  local_c0 = 0;
  local_c8 = 0;
  local_58[3] = 0;
  puVar11 = &local_c0;
  local_58[1] = 0;
  local_58[2] = 0;
  local_a0 = (void *)0x0;
  lStack_98 = 0;
  local_88 = (void *)0x0;
  lStack_80 = 0;
  local_b8 = (void *)0x0;
  lStack_b0 = 0;
  iVar3 = AiGetFullImagePath(param_10,param_9,local_58 + 1,(ushort *)&local_a0,
                             (undefined4 *)&local_88,&local_bc,puVar11);
  if (((((-1 < iVar3) && ((local_c0 & 4) == 0)) && (local_bc != 2)) &&
      ((local_bc != 0x33 && ((local_c0 & 0x10) == 0)))) &&
     ((iVar3 = AiGetVolumeInfo((wchar_t *)&local_88,*(undefined8 *)(lVar6 + 8),&local_b8,&local_c8),
      -1 < iVar3 && (local_c8 != 1)))) {
    local_78 = local_58[2];
  }
  if (lStack_98 != 0) {
    ExFreePoolWithTag(lStack_98,0);
  }
  if (lStack_80 != 0) {
    ExFreePoolWithTag(lStack_80,0);
  }
  if (lStack_b0 != 0) {
    ExFreePoolWithTag(lStack_b0,0);
  }
  lVar6 = param_7;
  if (param_7 == 0) {
    if (param_12 != '\0') goto LAB_140023b39;
  }
  else {
    if (param_12 != '\0') {
LAB_140023b39:
      cVar1 = *(char *)(param_3 + 0x11d);
      goto LAB_140023a37;
    }
    param_7 = 0;
    iVar3 = SrppPluginAccessCheck(param_1,0x14000a2b0,(uint *)&param_7);
    if (iVar3 == 0) {
      uVar4 = Feature_Servicing_ApplockerPickBestClaim__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar4 != 0) {
        if (((pvVar7 == (void *)0x0) || ((2 < uVar8 && (1 < uVar8 - 7)))) ||
           ((1 < *(uint *)((longlong)pvVar7 + 8) && (1 < *(uint *)((longlong)pvVar7 + 8) - 3)))) {
          if (param_11 != '\0') {
            AiAddProcToTrackedList(lVar6);
          }
        }
        else {
LAB_140023926:
          AiAddProcToOriginList(lVar6,pvVar7,uVar9);
        }
        goto LAB_140023947;
      }
      if (pvVar7 != (void *)0x0) {
        if (((uVar8 < 3) || (uVar8 - 7 < 2)) &&
           ((*(uint *)((longlong)pvVar7 + 8) < 2 || (*(uint *)((longlong)pvVar7 + 8) - 3 < 2))))
        goto LAB_140023926;
        goto LAB_140023947;
      }
      if (param_11 != '\0') {
        AiAddProcToTrackedList(lVar6);
      }
    }
    else {
LAB_140023947:
      if (pvVar7 != (void *)0x0) {
        if (((uVar8 < 3) || (uVar8 - 7 < 2)) &&
           (((*(uint *)((longlong)pvVar7 + 8) < 2 || (*(uint *)((longlong)pvVar7 + 8) - 3 < 2)) &&
            ((*(longlong *)((longlong)pvVar7 + 0x10) != *(longlong *)((longlong)pvVar7 + 0x20) ||
             (*(longlong *)((longlong)pvVar7 + 0x18) != *(longlong *)((longlong)pvVar7 + 0x28)))))))
        {
          AiAddSessionToOriginList(lVar6,pvVar7,uVar9);
        }
        else if ((uVar8 == 3) &&
                ((*(int *)((longlong)pvVar7 + 8) == 0 || (*(int *)((longlong)pvVar7 + 8) == 3)))) {
          AiAddProcToTrackedSessionList(lVar6,(uint)(iVar3 == 0),(longlong)pvVar7);
        }
      }
    }
    SmartlockerAddChildProcToTrackedListIfParentPresent(lVar6);
    if (local_c4[0] != '\0') {
      param_7 = 0;
      lVar6 = param_1;
      iVar3 = SrppPluginAccessCheck(param_1,0x1400096d0,(uint *)&param_7);
      if (iVar3 != 0) {
        param_7 = 0;
        iVar3 = AipAllocateImageContext(lVar6,param_10,0,&param_7);
        lVar6 = param_7;
        if (-1 < iVar3) {
          iVar3 = AipSetEaFromOrigin(*(undefined8 *)(param_7 + 0x10),pvVar7,uVar9);
          if (-1 < iVar3) {
            AipSmartHashImageFile(0,param_10,lVar6,0);
          }
          AipFreeImageContext(lVar6);
        }
      }
    }
  }
  cVar1 = *(char *)(param_3 + 0x105);
LAB_140023a37:
  if ((pvVar7 != (void *)0x0) && (iVar2 == -0x3ffffddb)) {
    iVar2 = -0x3fffffff;
  }
  SmartlockerTelemetrizeOriginInfo
            (param_1,param_4,param_10,iVar2,uVar8,(char)local_78,puVar11,in_stack_ffffffffffffff00,
             cVar1 == '\0',*(char *)(param_3 + 0x14d) == '\0',param_8,in_stack_ffffffffffffff20,
             (longlong)pvVar7,param_12);
  if (local_70 != (void *)0x0) {
    ExFreePoolWithTag(local_70,0x41746d73);
  }
  if (local_68 != (void *)0x0) {
    ExFreePoolWithTag(local_68,0x41746d73);
  }
  if (local_a8 != 0) {
    ExFreePoolWithTag(local_a8,0x41746d73);
  }
  if (local_60 != 0) {
    ExFreePoolWithTag(local_60,0x41746d73);
  }
  if (local_58[0] != 0) {
    ExFreePoolWithTag(local_58[0],0);
  }
  return iVar2;
}



===== SrpAccessCheckCommon @ 140023b50 =====

uint SrpAccessCheckCommon(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  char cVar2;
  uint local_res20 [2];
  undefined4 local_a8 [2];
  longlong local_a0 [4];
  undefined4 *puStack_80;
  uint *local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  longlong *plStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined *local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  longlong local_18;
  undefined8 uStack_10;
  
  local_a8[0] = 0;
  local_a0[0] = 0;
  local_30 = local_30 & 0xffffffff00000000;
  local_68 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_a0[1] = 0;
  local_a0[2] = 0;
  local_60 = 0;
  plStack_58 = (longlong *)0x0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = (undefined *)0x0;
  uStack_38 = 0;
  local_a0[3] = 0;
  puStack_80 = (undefined4 *)0x0;
  local_78 = (uint *)0x0;
  uStack_70 = 0;
  local_res20[0] = ObReferenceObjectByHandle(0,0,0,0,local_a0,0);
  lVar1 = local_a0[0];
  if (-1 < (int)local_res20[0]) {
    uStack_20 = 0;
    uStack_10 = 0;
    local_a0[2] = (ulonglong)*(uint *)(param_2 + 0x10) + param_2;
    uStack_48 = 0;
    local_68 = 0;
    local_40 = &DAT_14000ae70;
    plStack_58 = local_a0 + 1;
    puStack_80 = local_a8;
    local_78 = local_res20;
    local_18 = local_a0[0];
    local_a0[1] = 0x300000010;
    uStack_38 = 0;
    local_30 = 0;
    local_60 = 0x38;
    local_50 = 0x20;
    local_a0[3] = 0x100000028;
    uStack_70 = param_3;
    cVar2 = SeSrpAccessCheck(&local_28,0,&local_60,local_a0 + 3,0,1);
    if ((cVar2 == '\0') && (local_res20[0] == 0xc0000022)) {
      local_res20[0] = -(uint)((*(byte *)(param_2 + 0x18) & 1) != 0) & 0xc0000364;
    }
  }
  if (lVar1 != 0) {
    ObfDereferenceObject(lVar1);
  }
  return local_res20[0];
}



===== SrpCleanup @ 140023cd4 =====

void SrpCleanup(void)

{
  undefined8 local_18;
  wchar_t *local_10;
  
  local_10 = L"\\??\\SrpDevice";
  local_18 = 0x1c001a;
  if (DAT_140018460 != '\0') {
    ReplacePolicyRef(0);
    SrpPolicyTransactionRollback();
    ExDeleteResourceLite(&DAT_1400183e0);
    ExDeleteResourceLite(&DAT_140018370);
    DAT_140018460 = '\0';
  }
  AipForEachPlugin(AipCleanupPluginsCallback,0);
  if (g_Srp != 0) {
    if (DAT_140018710 != 0) {
      IoDeleteSymbolicLink(&local_18);
      DAT_140018710 = 0;
    }
    if (DAT_140018708 != 0) {
      IoDeleteDevice();
      DAT_140018708 = 0;
    }
    if (DAT_140018728 != 0) {
      ExUnregisterCallback();
      DAT_140018728 = 0;
    }
    if (DAT_140018720 != 0) {
      ObfDereferenceObject();
      DAT_140018720 = 0;
    }
    if (DAT_140018718 != 0) {
      EtwUnregister();
      DAT_140018718 = 0;
    }
    g_Srp = 0;
  }
  return;
}



===== SrpComputeCombinedAttributes @ 140023e00 =====

void SrpComputeCombinedAttributes(longlong param_1)

{
  uint *puVar1;
  longlong lVar2;
  uint *puVar3;
  longlong *plVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  uint uVar9;
  uint local_res10;
  longlong *local_res18;
  
  local_res18 = (longlong *)(param_1 + 0x28);
  local_res10 = 0;
  pbVar5 = (byte *)(param_1 + 0x105);
  do {
    uVar6 = 0;
    puVar3 = (uint *)(pbVar5 + -5);
    if (DAT_140018704 != 0) {
      if (((int)local_res18[-1] < 0) || (*(int *)(*local_res18 + 0xc) == 0)) {
        if (local_res10 != 2) goto LAB_140023e73;
        lVar2 = *(longlong *)(param_1 + 0x28);
      }
      else {
        *(undefined4 *)(pbVar5 + -5) = *(undefined4 *)(*local_res18 + 0x1c);
        lVar2 = *local_res18;
      }
      *pbVar5 = *(byte *)(lVar2 + 0x18) & 1;
    }
LAB_140023e73:
    if (((-1 < *(int *)(param_1 + 0xd0)) && (lVar2 = *(longlong *)(param_1 + 0xd8), lVar2 != 0)) &&
       (*(int *)(lVar2 + 0xc) != 0)) {
      puVar1 = (uint *)((ulonglong)*(uint *)(lVar2 + 8) + 0x20 + lVar2);
      do {
        uVar9 = 0;
        plVar4 = (longlong *)
                 ((ulonglong)*(uint *)(lVar2 + 0x10) + (ulonglong)puVar1[-1] * 0x1c + lVar2);
        if (*puVar1 != 0) {
          do {
            if ((*plVar4 == *(longlong *)(param_1 + ((ulonglong)local_res10 + 10) * 0x18)) &&
               (plVar4[1] == *(longlong *)(param_1 + 8 + ((ulonglong)local_res10 + 10) * 0x18))) {
              AiSetAttributes(puVar3,*(uint *)(plVar4 + 2),local_res10 == 2);
              *(undefined1 *)(puVar3 + 1) = 1;
              uVar8 = 0;
              if ((int)plVar4[3] != 0) {
                do {
                  lVar2 = (*(uint *)((longlong)plVar4 + 0x14) + uVar8) * 0x30 +
                          *(longlong *)(param_1 + 0xe0);
                  if ((-1 < *(int *)(lVar2 + 0x20)) &&
                     (*(int *)(*(longlong *)(lVar2 + 0x28) + 0xc) != 0)) {
                    AiSetAttributes((uint *)(pbVar5 + -5),
                                    *(uint *)(*(longlong *)(lVar2 + 0x28) + 0x1c),local_res10 == 2);
                    *pbVar5 = *pbVar5 | *(byte *)(*(longlong *)(lVar2 + 0x28) + 0x18) & 1;
                  }
                  uVar7 = (int)uVar8 + 1;
                  uVar8 = (ulonglong)uVar7;
                } while (uVar7 < *(uint *)(plVar4 + 3));
                puVar3 = (uint *)(pbVar5 + -5);
              }
            }
            uVar9 = uVar9 + 1;
            plVar4 = (longlong *)((longlong)plVar4 + 0x1c);
          } while (uVar9 < *puVar1);
        }
        lVar2 = *(longlong *)(param_1 + 0xd8);
        uVar6 = uVar6 + 1;
        puVar1 = puVar1 + 9;
      } while (uVar6 < *(uint *)(lVar2 + 0xc));
    }
    local_res10 = local_res10 + 1;
    local_res18 = local_res18 + 6;
    pbVar5 = pbVar5 + 0x18;
    if (3 < (int)local_res10) {
      return;
    }
  } while( true );
}



===== SrpGetHitCount @ 140023fc8 =====

undefined4
SrpGetHitCount(wchar_t *param_1,uint param_2,longlong param_3,uint param_4,ulonglong *param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  longlong lVar5;
  uint *puVar6;
  undefined4 uVar7;
  int *piVar8;
  uint uVar9;
  
  uVar9 = 0;
  *param_5 = 0;
  if (((param_2 < 0x24) || (param_4 < 0x24)) || (param_1[3] != L'\0')) {
    return 0xc000000d;
  }
  piVar4 = SrpGetPolicy();
  iVar2 = _wcsicmp(param_1,L"EXE");
  if (iVar2 == 0) {
    lVar5 = *(longlong *)(piVar4 + 10);
LAB_14002406c:
    if (lVar5 != 0) {
      *param_5 = 0x24;
      *(undefined4 *)(param_3 + 0x14) = 0;
      uVar3 = (*(int *)(lVar5 + 0xc) + 2) * 0xc;
      *(uint *)(param_3 + 0x10) = uVar3;
      uVar1 = *(uint *)(lVar5 + 8);
      memset((void *)(param_3 + 0x18),0,(ulonglong)(param_4 - 0x18));
      if (*(int *)(lVar5 + 0xc) != 0) {
        piVar8 = (int *)(param_3 + 0x18);
        puVar6 = (uint *)((ulonglong)uVar1 + 4 + lVar5);
        do {
          if (puVar6[5] != 0) {
            *(int *)(param_3 + 0x14) = *(int *)(param_3 + 0x14) + 1;
            *(int *)(param_3 + 0x10) = *(int *)(param_3 + 0x10) + *puVar6;
            if (*(uint *)(param_3 + 0x10) < param_4) {
              piVar8[2] = puVar6[5];
              piVar8[1] = *puVar6;
              *piVar8 = ((int)param_3 - (int)piVar8) + uVar3;
              memmove((void *)((ulonglong)uVar3 + param_3),(void *)((ulonglong)puVar6[-1] + lVar5),
                      (ulonglong)*puVar6);
              piVar8 = piVar8 + 3;
              uVar3 = uVar3 + *puVar6;
            }
          }
          uVar9 = uVar9 + 1;
          puVar6 = puVar6 + 7;
        } while (uVar9 < *(uint *)(lVar5 + 0xc));
      }
      uVar7 = 0;
      if (*(uint *)(param_3 + 0x10) <= param_4) {
        *param_5 = (ulonglong)*(uint *)(param_3 + 0x10);
      }
      goto LAB_14002412d;
    }
  }
  else {
    iVar2 = _wcsicmp(param_1,L"DLL");
    if (iVar2 == 0) {
      lVar5 = *(longlong *)(piVar4 + 0x16);
      goto LAB_14002406c;
    }
  }
  uVar7 = 0xc000000d;
LAB_14002412d:
  if (piVar4 != (int *)0x0) {
    ReleasePolicyRef(piVar4 + -2);
  }
  return uVar7;
}



===== SrpInheritOrigin @ 140024168 =====

ulonglong SrpInheritOrigin(undefined8 *param_1,uint param_2)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint local_res10 [2];
  longlong local_res18;
  longlong local_res20;
  longlong local_28;
  longlong local_20;
  
  local_res18 = 0;
  local_res20 = 0;
  local_res10[0] = 0;
  local_28 = 0;
  local_20 = 0;
  if ((param_2 < 0x18) || (param_1[2] != 0)) {
    uVar4 = 0xc000000d;
  }
  else {
    uVar3 = SrppOpenKernelTokenHandle(*param_1,8,&local_res18);
    uVar4 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      uVar3 = SrppOpenKernelTokenHandle(param_1[1],0x8c,&local_res20);
      uVar4 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        SmartlockerOriginClaimProcessTokenCheck
                  (local_res18,'\0',(undefined1 *)0x0,local_res10,&local_28,&local_20);
        lVar1 = local_28;
        if (local_28 != 0) {
          BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,(PUCHAR)(local_28 + 0x20),0x10,2);
          uVar2 = SmartlockerTagProcessToken(local_res20,local_res10[0],lVar1);
          uVar4 = (ulonglong)uVar2;
        }
        if (local_20 != 0) {
          ExFreePoolWithTag(local_20,0x41746d73);
        }
      }
    }
    if (local_res18 != 0) {
      ZwClose();
    }
    if (local_res20 != 0) {
      ZwClose();
    }
  }
  return uVar4;
}



===== SrpInvokePlugins @ 14002428c =====

ulonglong SrpInvokePlugins(longlong param_1,int param_2,longlong param_3)

{
  longlong *plVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  uint uVar5;
  undefined4 local_res8 [2];
  ulonglong local_res20;
  longlong local_98 [2];
  longlong local_88;
  longlong *plStack_80;
  undefined4 local_78;
  undefined4 uStack_74;
  longlong lStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong *puStack_40;
  
  if ((-1 < *(int *)(param_1 + 0xd0)) && (lVar2 = *(longlong *)(param_1 + 0xd8), lVar2 != 0)) {
    uVar5 = 0;
    lVar4 = (ulonglong)*(uint *)(lVar2 + 8) + lVar2;
    if (*(int *)(lVar2 + 0xc) != 0) {
      plVar1 = (longlong *)(param_1 + ((longlong)param_2 + 10) * 0x18);
      do {
        local_98[0] = 0;
        local_res8[0] = 0;
        uVar3 = SrppGetPluginPolicy(param_1,plVar1,lVar4,local_98,local_res8);
        lVar2 = local_98[0];
        if ((int)uVar3 < 0) {
          if ((int)uVar3 != -0x3ffffddb) {
            return uVar3;
          }
        }
        else {
          local_res20 = 0;
          local_68 = *(undefined8 *)(param_3 + 0x20);
          uStack_60 = *(undefined8 *)(param_3 + 0x28);
          local_58 = *(undefined8 *)(param_3 + 0x30);
          uStack_50 = *(undefined8 *)(param_3 + 0x38);
          _local_78 = CONCAT44((int)((ulonglong)*(undefined8 *)(param_3 + 0x10) >> 0x20),
                               local_res8[0]);
          puStack_40 = &local_res20;
          local_48 = *(undefined8 *)(param_3 + 0x40);
          lStack_70 = local_98[0];
          local_88 = lVar4;
          plStack_80 = plVar1;
          uVar3 = AipForEachPlugin(PluginInvokeCallback,&local_88);
          if (lVar2 != 0) {
            ExFreePoolWithTag(lVar2,0);
          }
          if ((int)uVar3 < 0) {
            return uVar3 & 0xffffffff;
          }
          if ((int)local_res20 < 0) {
            return local_res20 & 0xffffffff;
          }
        }
        uVar5 = uVar5 + 1;
        lVar4 = lVar4 + 0x24;
      } while (uVar5 < *(uint *)(*(longlong *)(param_1 + 0xd8) + 0xc));
    }
  }
  return 0;
}



===== SrpIsOnlySmartAppControlEnabledForPolicyType @ 1400243f4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SrpIsOnlySmartAppControlEnabledForPolicyType(longlong param_1,int param_2)

{
  bool bVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined1 auStack_68 [32];
  undefined2 local_48;
  undefined2 local_46;
  undefined4 local_44;
  longlong local_40;
  ulonglong local_38 [6];
  
  local_38[4] = __security_cookie ^ (ulonglong)auStack_68;
  lVar3 = (longlong)param_2;
  if ((*(int *)(param_1 + 0xb0) < 0) || (*(int *)(*(longlong *)(param_1 + 0xb8) + 0xc) == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  uVar2 = SmartlockerRegistryDisableOverrideIsSet();
  if ((((int)uVar2 == 0) && (!bVar1)) &&
     (uVar2 = SmartlockerSmartScreenRegistryIsEnabled(), (int)uVar2 != 0)) {
    uVar2 = lVar3 * 6;
    local_40 = *(longlong *)(param_1 + 0x28 + lVar3 * 0x30);
    if ((*(int *)(local_40 + 0xc) == 1) &&
       (uVar2 = lVar3 * 3, *(char *)(param_1 + 0x104 + lVar3 * 0x18) == '\0')) {
      uVar2 = (ulonglong)*(uint *)(local_40 + 8);
      local_48 = *(undefined2 *)(uVar2 + 4 + local_40);
      local_46 = *(undefined2 *)(uVar2 + 4 + local_40);
      local_44 = 0;
      local_40 = (ulonglong)*(uint *)(uVar2 + local_40) + local_40;
      uVar2 = RtlEqualUnicodeString(&DAT_1400082e8,&local_48,0);
      if ((char)uVar2 != '\0') {
        local_38[0] = 0;
        local_38[1] = 0;
        local_38[2] = 0;
        local_38[3] = 0;
        uVar2 = ZwQuerySystemInformation(0xa4,local_38,0x20);
        if ((-1 < (int)uVar2) && ((local_38[0] & 0x1800) != 0)) {
          return CONCAT71((int7)(uVar2 >> 8),1);
        }
      }
    }
  }
  return uVar2 & 0xffffffffffffff00;
}



===== SrpIsOnlySmartLockerEnabledForPolicyType @ 14002452c =====

bool SrpIsOnlySmartLockerEnabledForPolicyType(longlong param_1,int param_2)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  ulonglong uVar6;
  int local_res8 [2];
  undefined8 local_28;
  wchar_t *local_20;
  undefined8 local_18;
  wchar_t *local_10;
  
  if ((*(int *)(param_1 + 0xb0) < 0) || (*(int *)(*(longlong *)(param_1 + 0xb8) + 0xc) == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  lVar5 = param_1;
  uVar4 = SmartlockerRegistryDisableOverrideIsSet();
  if (((int)uVar4 == 0) && (!bVar1)) {
    uVar4 = SmartlockerSmartScreenRegistryIsEnabled();
    if ((int)uVar4 == 0) {
      local_res8[0] = 0;
      local_10 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Srp\\GP\\";
      local_18 = 0x760074;
      local_20 = L"LastSmartlockerEnabled";
      local_28 = 0x2e002c;
      iVar3 = AiRegReadDwordValue(lVar5,&local_18,&local_28,local_res8);
      if (iVar3 < 0) {
        return false;
      }
      if (local_res8[0] == 0) {
        return false;
      }
    }
    lVar5 = *(longlong *)(param_1 + 0x28 + (longlong)param_2 * 0x30);
    if ((*(int *)(lVar5 + 0xc) == 1) &&
       (*(char *)(param_1 + 0x104 + (longlong)param_2 * 0x18) == '\0')) {
      uVar6 = (ulonglong)*(uint *)(lVar5 + 8);
      local_18 = (ulonglong)
                 CONCAT22(*(undefined2 *)(uVar6 + 4 + lVar5),*(undefined2 *)(uVar6 + 4 + lVar5));
      local_10 = (wchar_t *)((ulonglong)*(uint *)(uVar6 + lVar5) + lVar5);
      cVar2 = RtlEqualUnicodeString(&DAT_1400082f8,&local_18,0);
      return cVar2 != '\0';
    }
  }
  return false;
}



===== SrpIsWindowsSigned @ 140024650 =====

undefined1 SrpIsWindowsSigned(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 *puVar3;
  undefined1 uVar4;
  undefined8 local_res10;
  undefined1 local_res18 [8];
  char local_res20 [8];
  undefined4 local_28 [4];
  
  uVar4 = 0;
  local_28[0] = 0;
  local_res18[0] = 0;
  local_res20[0] = '\0';
  local_res10 = param_2;
  iVar1 = ZwGetCachedSigningLevel(param_2,local_28,local_res18,0,0,0);
  if ((iVar1 < 0) || (iVar1 = SeCompareSigningLevels(local_res18[0],0xc), iVar1 == 0)) {
    pcVar2 = local_res20;
    AiSigningLevelCacheExists(param_1,pcVar2);
    if (local_res20[0] != '\0') {
      return 0;
    }
    puVar3 = (undefined4 *)CONCAT71((int7)((ulonglong)pcVar2 >> 8),0xc);
    iVar1 = ZwSetCachedSigningLevel(5,puVar3,&local_res10,1,local_res10);
    if (-1 < iVar1) {
      puVar3 = local_28;
      iVar1 = ZwGetCachedSigningLevel(local_res10,puVar3,local_res18,0,0,0);
      if (-1 < iVar1) {
        puVar3 = (undefined4 *)CONCAT71((int7)((ulonglong)puVar3 >> 8),0xc);
        iVar1 = SeCompareSigningLevels(local_res18[0]);
        if (iVar1 != 0) goto LAB_140024725;
      }
    }
    AiSetSigningLevelCache(param_1,puVar3);
  }
  else {
LAB_140024725:
    uVar4 = 1;
  }
  return uVar4;
}



===== SrpOpenTrackInstallIoctl @ 140024744 =====

ulonglong SrpOpenTrackInstallIoctl(void)

{
  bool bVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  int *piVar5;
  longlong lVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  uint local_res8 [2];
  void *local_res10;
  undefined8 local_res18;
  longlong local_res20;
  ulonglong uVar9;
  longlong local_38 [3];
  
  local_res18 = 0;
  uVar8 = 0xc0000001;
  local_res8[0] = 0;
  bVar1 = false;
  local_res10 = (void *)0x0;
  local_38[0] = 0;
  uVar4 = SmartlockerRegistryDisableOverrideIsSet();
  if ((int)uVar4 == 0) {
    piVar5 = SrpGetPolicy();
    if ((((piVar5 != (int *)0x0) && (-1 < piVar5[0x2c])) &&
        (*(int *)(*(longlong *)(piVar5 + 0x2e) + 0xc) != 0)) ||
       (uVar4 = SmartlockerSmartScreenRegistryIsEnabled(), (int)uVar4 != 0)) {
      bVar1 = true;
    }
    if (piVar5 != (int *)0x0) {
      ReleasePolicyRef(piVar5 + -2);
    }
    if (bVar1) {
      uVar9 = 0;
      local_res20 = 0;
      iVar3 = ObReferenceObjectByHandle
                        (0xffffffffffffffff,0x1fffff,*(undefined8 *)PsProcessType_exref,0,
                         &local_res20,0);
      lVar2 = local_res20;
      if (-1 < iVar3) {
        lVar6 = PsReferencePrimaryToken(local_res20);
        if ((lVar6 != 0) &&
           (iVar3 = ObOpenObjectByPointer
                              (lVar6,0x200,0,8,*(undefined8 *)SeTokenObjectType_exref,
                               uVar9 & 0xffffffffffffff00,&local_res18), -1 < iVar3)) {
          uVar4 = SmartlockerOriginClaimProcessTokenCheck
                            (local_res18,'\0',(undefined1 *)0x0,local_res8,(longlong *)&local_res10,
                             local_38);
          if ((int)uVar4 < 0) {
            if (local_res10 != (void *)0x0) {
              ExEnterCriticalRegionAndAcquireResourceExclusive(&DAT_1400188a0);
              for (puVar7 = DAT_140018890; (undefined8 **)puVar7 != &DAT_140018890;
                  puVar7 = (undefined8 *)*puVar7) {
                if (lVar2 == puVar7[2]) {
                  puVar7 = (undefined8 *)
                           AipAllocTrackOriginProcess(lVar2,(void *)puVar7[3],*(uint *)(puVar7 + 4))
                  ;
                  if (puVar7 != (undefined8 *)0x0) {
                    AipAddProcToOriginListLocked(puVar7);
                    uVar8 = 0;
                  }
                  break;
                }
              }
              ExReleaseResourceAndLeaveCriticalRegion(&DAT_1400188a0);
            }
          }
          else {
            uVar8 = AiReferenceProcOriginList(lVar2,local_res10,local_res8[0]);
            uVar8 = uVar8 & 0xffffffff;
          }
        }
        if (local_38[0] != 0) {
          ExFreePoolWithTag(local_38[0],0);
        }
        ObCloseHandle(local_res18,0);
        if (lVar6 != 0) {
          PsDereferencePrimaryToken(lVar6);
        }
        ObfDereferenceObject(lVar2);
      }
    }
  }
  return uVar8;
}



===== SrpReadPolicy @ 140024964 =====

int SrpReadPolicy(undefined8 *param_1)

{
  undefined8 uVar1;
  int iVar2;
  uint uVar3;
  undefined8 *puVar4;
  int iVar5;
  longlong lVar6;
  
  iVar5 = 0;
  lVar6 = 0;
  param_1[0x1e] = 0x47d4e3e02b64fd0f;
  param_1[0x1f] = 0x49d7ba725903e8a1;
  param_1[0x21] = 0x4b71a17234b165b1;
  param_1[0x22] = 0x7c91549c5732b395;
  param_1[0x24] = 0x4896ef1a58125a50;
  param_1[0x25] = 0x6ccab39ac6d657ba;
  param_1[0x27] = 0x41e8aed364726eb1;
  param_1[0x28] = 0x83b9afb31ce1418c;
  puVar4 = param_1;
  do {
    uVar1 = *(undefined8 *)(&UNK_1400083b8 + lVar6);
    *puVar4 = *(undefined8 *)(&DAT_1400083b0 + lVar6);
    puVar4[1] = uVar1;
    uVar1 = *(undefined8 *)(&UNK_140008378 + lVar6);
    puVar4[2] = *(undefined8 *)(&DAT_140008370 + lVar6);
    puVar4[3] = uVar1;
    AiLogEvent(DAT_140018718,&SrpPolicyLoadStart);
    iVar2 = SrpLoadPolicy((longlong)(param_1 + (longlong)iVar5 * 6));
    if (iVar2 < 0) {
      AiLogEvent(DAT_140018718,&SrpPolicyLoadFailure);
      return iVar2;
    }
    AiLogEvent(DAT_140018718,&SrpPolicyLoadSuccess);
    iVar5 = iVar5 + 1;
    lVar6 = lVar6 + 0x10;
    puVar4 = puVar4 + 6;
  } while (iVar5 < 4);
  iVar5 = SrpLoadPlugins((wchar_t *)(param_1 + 0x18));
  if (-1 < iVar5) {
    SrpComputeCombinedAttributes((longlong)param_1);
    uVar3 = *(uint *)(param_1 + 0x29) | *(uint *)(param_1 + 0x20);
    param_1[0x2a] = 0;
    param_1[0x2b] = 0;
    param_1[0x2c] = 0;
    *(uint *)(param_1 + 0x2a) = uVar3 & 1;
    *(uint *)((longlong)param_1 + 0x15c) = uVar3 >> 1 & 1;
    *(uint *)(param_1 + 0x2c) = uVar3 >> 2 & 1;
    *(uint *)((longlong)param_1 + 0x164) = uVar3 >> 3 & 1;
    *(uint *)((longlong)param_1 + 0x154) = uVar3 >> 4 & 1;
  }
  return iVar5;
}



===== SrpServiceBypass @ 140024ae4 =====

ulonglong SrpServiceBypass(longlong param_1,char param_2,int param_3,char param_4)

{
  uint uVar1;
  ulonglong uVar2;
  bool bVar3;
  
  if (param_4 == '\0') {
    bVar3 = true;
  }
  else {
    bVar3 = *(char *)(param_1 + 0x104 + (longlong)param_3 * 0x18) == '\0';
  }
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0x28 + (longlong)param_3 * 0x30) + 0x18);
  uVar2 = (ulonglong)uVar1;
  if (param_2 == '\0') {
    uVar2 = (ulonglong)uVar1 & 0xffffffffffffff0c;
    if ((char)uVar2 == '\b') goto LAB_140024b22;
  }
  else if ((uVar1 & 0xc) == 0) {
LAB_140024b22:
    return CONCAT71((int7)(uVar2 >> 8),bVar3);
  }
  return uVar2 & 0xffffffffffffff00;
}



===== SrpUpdatePolicy @ 140024b30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SrpUpdatePolicy(void)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined1 auStack_1e8 [32];
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined8 local_1c0;
  wchar_t *local_1b8;
  undefined8 local_1b0;
  wchar_t *local_1a8;
  undefined8 local_1a0;
  wchar_t *local_198;
  undefined8 local_188 [24];
  undefined1 local_c8 [176];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_1e8;
  memset(local_188,0,0x168);
  uVar3 = SrpGetPluginFileName(local_c8);
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  uVar1 = SrpReadPolicy(local_188);
  if (-1 < (int)uVar1) {
    puVar4 = AllocatePolicyRef(local_188);
    if (puVar4 != (undefined4 *)0x0) {
      ReplacePolicyRef(puVar4);
      local_1c8 = 0;
      local_1b8 = 
      L"\\REGISTRY\\MACHINE\\System\\CurrentControlSet\\Control\\AppID\\Configuration\\SMARTLOCKER";
      local_1c4 = 0;
      local_198 = L"TrustedOriginDataId";
      local_1c0 = 0xa600a4;
      local_1a8 = L"CurrentOriginDataId";
      uVar1 = 0;
      local_1a0 = 0x280026;
      local_1b0 = 0x280026;
      iVar2 = AiRegReadDwordValue(puVar4,&local_1c0,&local_1b0,&local_1c8);
      uVar5 = local_1c8;
      if (iVar2 < 0) {
        uVar5 = 0;
      }
      iVar2 = AiRegReadDwordValue(puVar4,&local_1c0,&local_1a0,&local_1c4);
      DAT_140018744 = local_1c4;
      if (iVar2 < 0) {
        DAT_140018744 = 0;
      }
      DAT_140018740 = uVar5;
      CiSetTrustedOriginClaimId();
      goto LAB_140024bae;
    }
    uVar1 = 0xc0000017;
  }
  SrpFreeGlobalPolicy((longlong)local_188);
LAB_140024bae:
  return (ulonglong)uVar1;
}



===== SrpVerifyDll @ 140024c88 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong SrpVerifyDll(ulonglong *param_1,uint param_2,uint *param_3,wchar_t *param_4,
                      undefined1 param_5,longlong *param_6)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  ushort uVar5;
  uint uVar6;
  int iVar7;
  longlong lVar8;
  ulonglong **ppuVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  ulonglong *puVar13;
  undefined *puVar14;
  byte *pbVar15;
  ulonglong uVar16;
  ulonglong **ppuVar17;
  wchar_t *pwVar18;
  bool bVar19;
  undefined1 auStackY_1a8 [32];
  char local_138;
  char local_137;
  char local_136 [6];
  ulonglong local_130;
  uint local_128;
  uint local_124;
  ulonglong *local_120;
  ulonglong *local_118;
  longlong local_110;
  undefined8 local_108;
  void *local_100;
  ulonglong local_f8;
  ulonglong local_f0;
  longlong local_e8;
  ulonglong *local_e0;
  ulonglong local_d8;
  longlong *local_d0;
  uint local_c8;
  uint local_c4;
  undefined4 local_c0;
  uint local_bc;
  uint local_b8;
  uint local_b4;
  ulonglong *local_a8 [4];
  ulonglong **local_88;
  ulonglong local_80;
  ulonglong *local_78;
  ulonglong *local_70;
  ulonglong **local_68;
  undefined8 local_60;
  ulonglong *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1a8;
  local_d0 = param_6;
  local_f8 = 0;
  ppuVar9 = (ulonglong **)0x0;
  local_110 = 0;
  local_e8 = 0;
  local_120 = (ulonglong *)0x0;
  local_108 = (ulonglong *)0x0;
  local_100 = (void *)0x0;
  local_136[0] = '\0';
  local_e0 = (ulonglong *)0x0;
  local_138 = '\0';
  local_137 = '\0';
  local_128 = 0;
  local_124 = 0;
  pwVar18 = param_4;
  local_f0 = PsGetCurrentProcessId();
  bVar3 = true;
  lVar8 = AiQueryPerformanceCounter((undefined8 *)0x0,'\x01');
  ppuVar17 = (ulonglong **)0x0;
  *local_d0 = 0;
  if ((((param_2 < 10) || (uVar5 = (ushort)param_1[1], param_2 != uVar5 + 10)) || ((uVar5 & 1) != 0)
      ) || ((uVar5 == 0 || ((int)param_4 != 4)))) {
    uVar16 = 0xc000000d;
  }
  else {
    *local_d0 = 4;
    uVar5 = (ushort)param_1[1];
    local_130 = *param_1;
    local_108._0_4_ = CONCAT22(uVar5,uVar5);
    local_100 = (void *)AiAlloc((ulonglong)uVar5);
    bVar19 = false;
    if (local_100 == (void *)0x0) {
      uVar16 = 0xc0000017;
    }
    else {
      memmove(local_100,(void *)((longlong)param_1 + 10),(ulonglong)local_108 & 0xffff);
      pwVar18 = (wchar_t *)0x0;
      ppuVar17 = (ulonglong **)0x0;
      puVar14 = &AipInitRunOnceState;
      uVar6 = RtlRunOnceExecuteOnce(&AipInitRunOnceState,AipInitRunOnce,0);
      uVar16 = (ulonglong)uVar6;
      if (-1 < (int)uVar6) {
        ppuVar9 = (ulonglong **)SrpGetPolicy();
        if (ppuVar9 == (ulonglong **)0x0) {
          uVar16 = 0xc0000364;
        }
        else if ((*(int *)(ppuVar9 + 10) < 0) || (*(int *)((longlong)ppuVar9[0xb] + 0xc) == 0)) {
          if (*(char *)((longlong)ppuVar9 + 0x11c) != '\0') goto LAB_140024df6;
LAB_140024e4b:
          *param_3 = 0;
        }
        else {
          bVar19 = true;
LAB_140024df6:
          uVar6 = SrppDuplicateProcessToken(puVar14,&local_120);
          uVar16 = (ulonglong)uVar6;
          if (-1 < (int)uVar6) {
            uVar6 = AiIsTokenSandBoxed((char)local_120,&local_137);
            uVar16 = (ulonglong)uVar6;
            if (((int)uVar6 < 0) || (local_137 != '\0')) {
LAB_140024e6a:
              *param_3 = (uint)uVar16;
            }
            else {
              uVar6 = SrpIsTokenService(local_120,&local_138);
              uVar16 = (ulonglong)uVar6;
              if ((int)uVar6 < 0) {
                *param_3 = uVar6;
              }
              else {
                uVar6 = AiIsTokenRestricted(local_120,local_136);
                uVar16 = (ulonglong)uVar6;
                if ((int)uVar6 < 0) goto LAB_140024e6a;
                if (local_136[0] != '\0') {
                  ppuVar17 = &local_e0;
                  uVar6 = SeGetLogonSessionToken(local_120,0,ppuVar17);
                  uVar16 = (ulonglong)uVar6;
                  if (((uVar6 + 0x80000000 & 0x80000000) == 0) && (uVar6 != 0xc000007c))
                  goto LAB_140024e6a;
                }
                pwVar18 = (wchar_t *)CONCAT71((int7)((ulonglong)pwVar18 >> 8),param_5);
                ppuVar17 = *(ulonglong ***)IoFileObjectType_exref;
                local_d8 = 0;
                uVar6 = ObReferenceObjectByHandle(local_130,0x100001,ppuVar17);
                local_f8 = local_d8;
                uVar16 = (ulonglong)uVar6;
                if (-1 < (int)uVar6) {
                  pwVar18 = (wchar_t *)0x80100000;
                  ppuVar17 = (ulonglong **)0x0;
                  uVar6 = ObOpenObjectByPointer(local_d8,0x200,0);
                  uVar16 = (ulonglong)uVar6;
                  if (uVar6 == 0xc0000022) {
                    pwVar18 = (wchar_t *)&local_110;
                    ppuVar17 = (ulonglong **)0xffffffffffffffff;
                    uVar6 = ZwDuplicateObject(0xffffffffffffffff,local_130,0xffffffffffffffff);
                    uVar16 = (ulonglong)uVar6;
                    if (-1 < (int)uVar6) {
                      pwVar18 = (wchar_t *)0x0;
                      local_130 = 0;
                      ppuVar17 = *(ulonglong ***)IoFileObjectType_exref;
                      uVar6 = ObReferenceObjectByHandle(local_110,0x100001,ppuVar17);
                      uVar16 = (ulonglong)uVar6;
                      if (-1 < (int)uVar6) {
                        if (local_130 != local_f8) {
                          uVar16 = 0xc0000008;
                        }
                        ObfDereferenceObject();
                        goto LAB_140024fd7;
                      }
                    }
                  }
                  else {
LAB_140024fd7:
                    if (-1 < (int)uVar16) {
                      memset(local_a8,0,0x50);
                      pwVar18 = (wchar_t *)CONCAT71((int7)((ulonglong)pwVar18 >> 8),1);
                      ppuVar17 = (ulonglong **)0x0;
                      local_70 = param_1;
                      uVar10 = SrpServiceBypass((longlong)ppuVar9,local_138,1,'\x01');
                      if ((char)uVar10 != '\0') goto LAB_140024e4b;
                      puVar13 = local_120;
                      if (local_e0 != (ulonglong *)0x0) {
                        puVar13 = local_e0;
                      }
                      local_118 = puVar13;
                      uVar10 = Feature_Servicing_ApplockerNoisyLogs__private_IsEnabledDeviceUsageNoInline
                                         ();
                      if (!bVar19) {
LAB_1400250cf:
                        uVar6 = *(uint *)(ppuVar9 + 0x23);
                        ppuVar17 = (ulonglong **)&local_c8;
                        local_c0 = 0;
                        local_c8 = uVar6 & 1;
                        local_bc = uVar6 >> 1 & 1;
                        local_b8 = uVar6 >> 2 & 1;
                        local_b4 = uVar6 >> 3 & 1;
                        local_c4 = uVar6 >> 4 & 1;
                        uVar6 = AiGetFileAttributes((ulonglong)local_c4,local_110,(int *)ppuVar17,
                                                    pwVar18,&local_e8);
                        uVar16 = (ulonglong)uVar6;
                        if (-1 < (int)uVar6) {
                          uVar10 = AiSetTokenAttributes(puVar13,local_e8);
                          uVar16 = uVar10 & 0xffffffff;
                          if (-1 < (int)uVar10) {
                            if ((DAT_140018704 != 0) && (bVar19)) {
                              uVar6 = (uint)ppuVar9[0xb][3] & 0xc;
                              if (local_138 == '\0') {
                                bVar19 = uVar6 == 8;
                              }
                              else {
                                bVar19 = uVar6 == 0;
                              }
                              if (!bVar19) {
                                pwVar18 = (wchar_t *)(local_f0 & 0xffffffff);
                                ppuVar17 = (ulonglong **)&local_108;
                                uVar6 = SrppAccessCheck(puVar13,(wchar_t *)(ppuVar9 + 6),
                                                        (wchar_t *)ppuVar17,(char)local_f0,'\0',
                                                        &local_124);
                                uVar16 = (ulonglong)uVar6;
                                if (((int)uVar6 < 0) && (((uint)ppuVar9[0xb][3] >> 5 & 1) != 0)) {
                                  local_128 = local_124;
                                  if (((local_124 >> 0x11 & 1) == 0) &&
                                     (cVar4 = SrpIsWindowsSigned(local_f8,local_110), cVar4 != '\0')
                                     ) {
                                    uVar16 = 0;
                                    local_128 = 0x10000;
                                  }
                                }
                                else {
                                  local_128 = local_124;
                                }
                              }
                            }
                            goto LAB_14002504f;
                          }
                        }
                        goto LAB_1400252fb;
                      }
                      if ((int)uVar10 == 0) {
                        uVar11 = SrpIsOnlySmartAppControlEnabledForPolicyType((longlong)ppuVar9,1);
                        cVar4 = (char)uVar11;
                      }
                      else {
                        cVar4 = SrpIsOnlySmartLockerEnabledForPolicyType((longlong)ppuVar9,1);
                      }
                      if (cVar4 == '\0') goto LAB_1400250cf;
LAB_14002504f:
                      if ((*(int *)(ppuVar9 + 0x16) < 0) ||
                         (bVar19 = true, *(int *)((longlong)ppuVar9[0x17] + 0xc) == 0)) {
                        bVar19 = false;
                      }
                      uVar11 = SmartlockerSmartScreenRegistryIsEnabled();
                      local_124 = (uint)uVar11;
                      uVar12 = SmartlockerRegistryDisableOverrideIsSet();
                      cVar4 = local_138;
                      bVar2 = false;
                      if (((int)uVar12 == 0) && ((bVar19 || ((char)uVar11 != '\0')))) {
                        bVar2 = true;
                      }
                      if ((DAT_140018704 == 0) || (!bVar2)) {
LAB_1400252b5:
                        if (-1 < (int)uVar16) goto LAB_1400252b9;
                      }
                      else {
                        uVar6 = (uint)ppuVar9[0xb][3] & 0xc;
                        if (local_138 == '\0') {
                          bVar19 = uVar6 == 8;
                        }
                        else {
                          bVar19 = uVar6 == 0;
                        }
                        if (bVar19) goto LAB_1400252b5;
                        local_130 = 0;
                        iVar7 = ObReferenceObjectByHandle(0xffffffffffffffff,0x1000,0,0);
                        pwVar18 = (wchar_t *)&local_108;
                        uVar10 = 0;
                        if (-1 < iVar7) {
                          uVar10 = local_130;
                        }
                        ppuVar17 = ppuVar9;
                        uVar6 = SmartlockerVerifyProcess
                                          ((longlong)local_118,(longlong)local_120,(longlong)ppuVar9
                                           ,pwVar18,(char)local_f0,0,uVar10,local_128,local_f8,
                                           local_110,cVar4,'\x01',(char)local_124);
                        if (uVar10 != 0) {
                          ObfDereferenceObject(uVar10);
                        }
                        if ((((int)uVar6 < 0) || (*(char *)((longlong)ppuVar9 + 0x14d) == '\0')) ||
                           ((local_128 & 0x20000) != 0)) goto LAB_1400252b5;
                        uVar16 = (ulonglong)uVar6;
LAB_1400252b9:
                        if (*(char *)((longlong)ppuVar9 + 0x11c) != '\0') {
                          local_78 = local_118;
                          local_80 = local_f0 & 0xffffffff;
                          ppuVar17 = local_a8;
                          uVar16 = SrpInvokePlugins((longlong)ppuVar9,1,(longlong)local_a8);
                          uVar16 = uVar16 & 0xffffffff;
                        }
                      }
                      *param_3 = (uint)uVar16;
                      if ((uint)uVar16 == 0xc0000364) {
                        uVar16 = 0;
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
LAB_1400252fb:
  uVar10 = CONCAT71((int7)((ulonglong)ppuVar17 >> 8),1);
  puVar13 = (ulonglong *)AiUpdatePerfTime((longlong *)&DAT_140018650,lVar8,'\x01');
  uVar6 = (uint)uVar16;
  if ((puVar13 < (ulonglong *)0x7a121) && (-1 < (int)uVar6)) goto LAB_140025458;
  uVar5 = AiGetFileNameFromPath((ushort *)&local_108);
  uVar10 = (ulonglong)uVar5;
  if ((int)uVar6 < 0) {
    if (DAT_140018000 < 5) goto LAB_140025458;
    if (((_DAT_140018010 & 0x200000000000) == 0) ||
       (bVar19 = true, (DAT_140018018 & 0x200000000000) != DAT_140018018)) {
      bVar19 = false;
    }
    if (!bVar19) goto LAB_140025458;
    pbVar15 = &DAT_140015023;
    lVar8 = ((ushort)(wchar_t)local_108 >> 1) - uVar10;
    uVar1 = uVar6;
  }
  else {
    if (DAT_140018000 < 5) goto LAB_140025458;
    if (((_DAT_140018010 & 0x200000000000) == 0) ||
       (bVar19 = true, (DAT_140018018 & 0x200000000000) != DAT_140018018)) {
      bVar19 = false;
    }
    if (!bVar19) goto LAB_140025458;
    pbVar15 = &DAT_140014fca;
    lVar8 = ((ushort)(wchar_t)local_108 >> 1) - uVar10;
    uVar1 = *param_3;
  }
  local_68 = &local_118;
  local_88 = &local_70;
  local_78 = (ulonglong *)((longlong)local_100 + lVar8 * 2);
  local_130 = (ulonglong)(int)uVar1;
  local_58 = &local_130;
  local_80 = 2;
  local_70 = (ulonglong *)(ulonglong)((uint)uVar5 * 2);
  local_60 = 8;
  local_50 = 8;
  local_118 = puVar13;
  _tlgWriteTransfer_EtwWriteTransfer(local_78,pbVar15,uVar10,pwVar18,6,local_a8);
LAB_140025458:
  if (49999 < DAT_140018658) {
    if (4 < DAT_140018000) {
      if (((_DAT_140018010 & 0x200000000000) == 0) ||
         ((DAT_140018018 & 0x200000000000) != DAT_140018018)) {
        bVar3 = false;
      }
      if (bVar3) {
        local_118 = (ulonglong *)(DAT_140018650 / DAT_140018658);
        local_80 = 8;
        local_88 = &local_118;
        local_78 = &local_130;
        local_130 = DAT_140018658;
        local_70 = (ulonglong *)0x8;
        _tlgWriteTransfer_EtwWriteTransfer(DAT_140018658,&DAT_140014f78,uVar10,pwVar18,4,local_a8);
      }
    }
    AiResetPerfTimeCounter(&DAT_140018650);
  }
  if (local_100 != (void *)0x0) {
    ExFreePoolWithTag(local_100,0);
  }
  if (local_e8 != 0) {
    AipFreeImageContext(local_e8 + -0x298);
  }
  if (local_f8 != 0) {
    ObfDereferenceObject(local_f8);
  }
  if (local_110 != 0) {
    ZwClose();
  }
  if (local_120 != (ulonglong *)0x0) {
    ZwClose();
  }
  if (local_e0 != (ulonglong *)0x0) {
    ZwClose();
  }
  if ((*local_d0 == 4) && (((int)uVar6 < 0 || ((int)*param_3 < 0)))) {
    if (ppuVar9 == (ulonglong **)0x0) {
      return uVar16;
    }
    if (*(char *)((longlong)ppuVar9 + 0x11d) == '\0') {
      *param_3 = 0;
      uVar16 = 0;
    }
  }
  else if (ppuVar9 == (ulonglong **)0x0) {
    return uVar16;
  }
  ReleasePolicyRef((int *)(ppuVar9 + -1));
  return uVar16;
}



===== SrpVerifyProcess @ 1400255e4 =====

uint SrpVerifyProcess(longlong param_1,longlong param_2,wchar_t *param_3,char param_4,
                     wchar_t *param_5,undefined1 param_6,int param_7,wchar_t *param_8,
                     longlong param_9,char param_10,longlong param_11,longlong param_12)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  uint local_res20 [2];
  
  local_res20[0] = 0;
  uVar3 = 0;
  uVar9 = 0;
  if (((param_4 != '\0') || (*(int *)(param_3 + 0x10) < 0)) ||
     (bVar10 = true, *(int *)(*(longlong *)(param_3 + 0x14) + 0xc) == 0)) {
    bVar10 = false;
  }
  if ((*(int *)(param_3 + 0x58) < 0) ||
     (bVar1 = true, *(int *)(*(longlong *)(param_3 + 0x5c) + 0xc) == 0)) {
    bVar1 = false;
  }
  uVar5 = SmartlockerSmartScreenRegistryIsEnabled();
  uVar6 = SmartlockerRegistryDisableOverrideIsSet();
  if (((int)uVar6 != 0) || ((!bVar1 && ((char)uVar5 == '\0')))) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (param_7 != 0) {
    if (DAT_140018704 != 0) {
      if ((*(int *)(param_3 + 0x40) < 0) || (*(int *)(*(longlong *)(param_3 + 0x44) + 0xc) == 0)) {
        if ((bVar10) && ((*(byte *)(*(longlong *)(param_3 + 0x14) + 0x18) & 1) != 0)) {
          EtwWrite(DAT_140018718,&SrpNoAppxRuleConfigured,0,0,0);
          return 0xc0000364;
        }
      }
      else {
        uVar3 = SrppAccessCheck(param_1,param_3 + 0x30,param_8,param_6,(char)param_7,local_res20);
        if ((int)uVar3 < 0) {
          if ((local_res20[0] & 0x20000) != 0) {
            return uVar3;
          }
          local_res20[0] = local_res20[0] & 0xffffff00;
          iVar4 = AiIsAppxInbox(*(undefined8 **)(param_9 + 0x40),(undefined1 *)local_res20);
          if (iVar4 < 0) {
            return uVar3;
          }
          if ((char)local_res20[0] == '\0') {
            return uVar3;
          }
          uVar3 = 0;
        }
      }
    }
    if ((char)param_3[0x9a] == '\0') {
      return uVar3;
    }
    uVar7 = SrpInvokePlugins((longlong)param_3,2,param_9);
    return (uint)uVar7;
  }
  if ((DAT_140018704 != 0) && (bVar10)) {
    uVar8 = *(uint *)(*(longlong *)(param_3 + 0x14) + 0x18) & 0xc;
    if (param_10 == '\0') {
      bVar10 = uVar8 == 8;
    }
    else {
      bVar10 = uVar8 == 0;
    }
    if (!bVar10) {
      uVar3 = SrppAccessCheck(param_1,param_3,param_5,param_6,'\0',local_res20);
      uVar9 = local_res20[0];
      if ((int)uVar3 < 0) {
        if ((((*(uint *)(*(longlong *)(param_3 + 0x14) + 0x18) >> 5 & 1) == 0) ||
            ((local_res20[0] >> 0x11 & 1) != 0)) ||
           (cVar2 = SrpIsWindowsSigned(param_11,param_12), cVar2 == '\0')) goto LAB_14002574a;
        uVar3 = 0;
        uVar9 = 0x10000;
      }
    }
  }
  if ((char)param_3[0x82] != '\0') {
    uVar7 = SrpInvokePlugins((longlong)param_3,0,param_9);
    uVar3 = (uint)uVar7;
  }
LAB_14002574a:
  if (DAT_140018704 == 0) {
    return uVar3;
  }
  if (!bVar1) {
    return uVar3;
  }
  uVar8 = *(uint *)(*(longlong *)(param_3 + 0x14) + 0x18) & 0xc;
  if (param_10 == '\0') {
    bVar10 = uVar8 == 8;
  }
  else {
    bVar10 = uVar8 == 0;
  }
  if (bVar10) {
    return uVar3;
  }
  uVar8 = SmartlockerVerifyProcess
                    (param_1,param_2,(longlong)param_3,param_5,param_6,
                     *(uint *)(*(longlong *)(param_9 + 0x38) + 0x10),*(longlong *)(param_9 + 0x20),
                     uVar9,param_11,param_12,param_10,'\0',(char)uVar5);
  if ((int)uVar8 < 0) {
    return uVar3;
  }
  if (*(char *)((longlong)param_3 + 0x14d) == '\0') {
    return uVar3;
  }
  if ((uVar9 >> 0x11 & 1) == 0) {
    return uVar8;
  }
  return uVar3;
}



===== SrppAccessCheck @ 140025920 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint SrppAccessCheck(undefined8 param_1,wchar_t *param_2,wchar_t *param_3,undefined1 param_4,
                    char param_5,uint *param_6)

{
  uint uVar1;
  undefined1 auStackY_f8 [32];
  undefined1 local_b8 [20];
  uint local_a4;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_f8;
  memset(local_b8,0,0x80);
  uVar1 = SrpAccessCheckCommon(param_1,*(longlong *)(param_2 + 0x14),local_b8);
  SrpDisplayAccessReason
            (DAT_140018718,*(longlong *)(param_2 + 0x14),param_2,local_a4,param_3,param_1,param_4,
             param_5);
  if (param_6 != (uint *)0x0) {
    *param_6 = local_a4;
  }
  return uVar1;
}



===== SrppDuplicateProcessToken @ 1400259f0 =====

int SrppDuplicateProcessToken(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  longlong local_res8;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong uStack_10;
  
  local_res8 = 0;
  local_18 = 0;
  uStack_10 = uStack_10 & 0xffffffff00000000;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  iVar1 = ZwOpenProcessTokenEx(0xffffffffffffffff,0,0x200,&local_res8);
  if (-1 < iVar1) {
    uStack_30 = 0;
    local_28 = 0;
    local_18 = 0;
    uStack_10 = 0;
    local_38 = CONCAT44(local_38._4_4_,0x30);
    uStack_20 = CONCAT44(uStack_20._4_4_,0x200);
    iVar1 = ZwDuplicateToken(local_res8,0,&local_38,0,1,param_2);
  }
  if (local_res8 != 0) {
    ZwClose();
  }
  return iVar1;
}



===== SrppOpenKernelTokenHandle @ 140025ac0 =====

ulonglong SrppOpenKernelTokenHandle(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 local_res20;
  ulonglong uVar4;
  
  uVar4 = 0;
  local_res20 = 0;
  uVar3 = ObReferenceObjectByHandle
                    (param_1,param_2,*(undefined8 *)SeTokenObjectType_exref,1,&local_res20,0);
  uVar1 = local_res20;
  if (-1 < (int)uVar3) {
    uVar2 = ObOpenObjectByPointer
                      (local_res20,0x200,0,0x80000000,*(undefined8 *)SeTokenObjectType_exref,
                       uVar4 & 0xffffffffffffff00,param_3);
    uVar3 = (ulonglong)uVar2;
    ObfDereferenceObject(uVar1);
  }
  return uVar3;
}



===== SrppPluginAccessCheck @ 140025b60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SrppPluginAccessCheck(undefined8 param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  undefined1 auStack_c8 [32];
  undefined1 local_a8 [20];
  uint local_94;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_c8;
  memset(local_a8,0,0x80);
  uVar1 = SrpAccessCheckCommon(param_1,param_2,local_a8);
  param_3[1] = local_94;
  *param_3 = uVar1;
  return;
}



===== SrppPolicyChangeCallback @ 140025be0 =====

void SrppPolicyChangeCallback(undefined8 param_1)

{
  int iVar1;
  undefined8 *puVar2;
  int local_res20 [2];
  int local_48;
  int local_44;
  undefined8 local_40;
  wchar_t *local_38;
  undefined8 local_30;
  wchar_t *local_28;
  undefined8 local_20;
  wchar_t *local_18;
  
  local_res20[0] = 0;
  local_44 = 0;
  local_18 = L"appid-EnableV2";
  local_20 = 0x1e001c;
  local_28 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\AppID\\";
  local_30 = 0x740072;
  local_38 = L"dbc4c77e-cf0a-44d7-8a79-5eb45d64decd";
  local_40 = 0x4a0048;
  iVar1 = AiRegReadDwordValue(param_1,&local_30,&local_40,&local_44);
  if (iVar1 < 0) {
    local_48 = 0;
    local_44 = 4;
    puVar2 = &local_20;
    iVar1 = ZwQueryLicenseValue(puVar2,&local_48,local_res20,4,&local_44);
    if (((iVar1 < 0) || (local_48 != 4)) || (local_44 != 4)) {
      local_res20[0] = 1;
    }
    if (local_res20[0] != 0) {
      AiRegWriteDwordValue(puVar2,&local_30,&local_40,0);
    }
  }
  else {
    local_res20[0] = 1;
  }
  DAT_140018704 = local_res20[0];
  return;
}



===== SrppReadNoPropogtionLogOption @ 140025cc0 =====

void SrppReadNoPropogtionLogOption(undefined8 param_1)

{
  int iVar1;
  undefined4 local_res8 [8];
  undefined8 local_28;
  wchar_t *local_20;
  undefined8 local_18;
  wchar_t *local_10;
  
  local_res8[0] = 0;
  DAT_140018748 = 0;
  local_10 = 
  L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\AppID\\Configuration\\EventSuppression"
  ;
  local_18 = 0xb000ae;
  local_20 = L"NoPropogationLogOption";
  local_28 = 0x2e002c;
  iVar1 = AiRegReadDwordValue(param_1,&local_18,&local_28,local_res8);
  if (-1 < iVar1) {
    DAT_140018748 = local_res8[0];
  }
  return;
}



===== AllocatePolicyRef @ 140025d28 =====

undefined4 * AllocatePolicyRef(undefined8 *param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined4 *puVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  
  puVar3 = (undefined4 *)ExAllocatePool2(0x102,0x170,0x44497041);
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = 1;
    lVar4 = 2;
    puVar2 = (undefined8 *)(puVar3 + 2);
    do {
      puVar6 = param_1;
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
      param_1 = puVar6 + 0x10;
    } while (lVar4 != 0);
    uVar1 = puVar6[0x11];
    puVar5[0x10] = puVar6[0x10];
    puVar5[0x11] = uVar1;
    uVar1 = puVar6[0x13];
    puVar5[0x12] = puVar6[0x12];
    puVar5[0x13] = uVar1;
    uVar1 = puVar6[0x15];
    puVar5[0x14] = puVar6[0x14];
    puVar5[0x15] = uVar1;
    uVar1 = puVar6[0x17];
    puVar5[0x16] = puVar6[0x16];
    puVar5[0x17] = uVar1;
    uVar1 = puVar6[0x19];
    puVar5[0x18] = puVar6[0x18];
    puVar5[0x19] = uVar1;
    uVar1 = puVar6[0x1b];
    puVar5[0x1a] = puVar6[0x1a];
    puVar5[0x1b] = uVar1;
    puVar5[0x1c] = puVar6[0x1c];
  }
  return puVar3;
}



===== ReleasePolicyRef @ 140025dfc =====

void ReleasePolicyRef(int *param_1)

{
  int iVar1;
  
  LOCK();
  iVar1 = *param_1;
  *param_1 = *param_1 + -1;
  UNLOCK();
  if (iVar1 == 1) {
    SrpFreeGlobalPolicy((longlong)(param_1 + 2));
    ExFreePoolWithTag(param_1,0x44497041);
  }
  return;
}



===== ReplacePolicyRef @ 140025e3c =====

void ReplacePolicyRef(undefined8 param_1)

{
  int *piVar1;
  
  ExEnterCriticalRegionAndAcquireResourceExclusive(&DAT_140018370);
  piVar1 = DAT_140018468;
  DAT_140018468 = (int *)param_1;
  ExReleaseResourceAndLeaveCriticalRegion(&DAT_140018370);
  if (piVar1 != (int *)0x0) {
    ReleasePolicyRef(piVar1);
  }
  return;
}



===== SrpFreeGlobalPolicy @ 140025e9c =====

void SrpFreeGlobalPolicy(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  uint uVar4;
  longlong lVar5;
  ulonglong uVar6;
  
  plVar2 = (longlong *)(param_1 + 0x28);
  lVar5 = 4;
  do {
    if (*plVar2 != 0) {
      ExFreePoolWithTag(*plVar2,0);
      *plVar2 = 0;
    }
    plVar2 = plVar2 + 6;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  if (param_1 + 0xc0 != 0) {
    if (*(longlong *)(param_1 + 0xd8) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0xd8),0);
      *(undefined8 *)(param_1 + 0xd8) = 0;
    }
    if (*(longlong *)(param_1 + 0xe0) != 0) {
      uVar6 = 0;
      if (*(int *)(param_1 + 0xe8) != 0) {
        do {
          lVar3 = uVar6 * 0x30;
          RtlFreeUnicodeString(*(longlong *)(param_1 + 0xe0) + 0x10 + lVar3);
          lVar5 = *(longlong *)(param_1 + 0xe0);
          lVar1 = *(longlong *)(lVar3 + 0x28 + lVar5);
          if (lVar1 != 0) {
            ExFreePoolWithTag(lVar1,0);
            *(undefined8 *)(lVar3 + 0x28 + lVar5) = 0;
          }
          uVar4 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar4;
        } while (uVar4 < *(uint *)(param_1 + 0xe8));
      }
      if (*(longlong *)(param_1 + 0xe0) != 0) {
        ExFreePoolWithTag(*(longlong *)(param_1 + 0xe0),0);
      }
      *(undefined8 *)(param_1 + 0xe0) = 0;
      *(undefined4 *)(param_1 + 0xe8) = 0;
    }
    RtlFreeUnicodeString(param_1 + 0xc0);
  }
  return;
}



===== SrpGetPolicy @ 140025fac =====

int * SrpGetPolicy(void)

{
  int *piVar1;
  
  piVar1 = (int *)0x0;
  ExEnterCriticalRegionAndAcquireResourceShared(&DAT_140018370);
  if (DAT_140018468 != (int *)0x0) {
    LOCK();
    *DAT_140018468 = *DAT_140018468 + 1;
    UNLOCK();
    piVar1 = DAT_140018468 + 2;
  }
  ExReleaseResourceAndLeaveCriticalRegion(&DAT_140018370);
  return piVar1;
}



===== SrpPolicyTransactionBegin @ 140026004 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

NTSTATUS SrpPolicyTransactionBegin(undefined8 *param_1,undefined8 *param_2)

{
  NTSTATUS NVar1;
  int *piVar2;
  int *piVar3;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  uStack_20 = 0;
  NVar1 = BCryptGenRandom((BCRYPT_ALG_HANDLE)0x0,(PUCHAR)&local_28,0x10,2);
  if (-1 < NVar1) {
    piVar2 = AllocatePolicyRef(param_1);
    if (piVar2 == (int *)0x0) {
      NVar1 = -0x3fffffe9;
    }
    else {
      ExEnterCriticalRegionAndAcquireResourceExclusive(&DAT_1400183e0);
      piVar3 = piVar2;
      if (DAT_140018448 == (int *)0x0) {
        piVar3 = (int *)0x0;
        DAT_140018450._0_4_ = (undefined4)local_28;
        DAT_140018450._4_4_ = local_28._4_4_;
        DAT_140018458._0_4_ = (undefined4)uStack_20;
        DAT_140018458._4_4_ = uStack_20._4_4_;
        DAT_140018448 = piVar2;
      }
      ExReleaseResourceAndLeaveCriticalRegion(&DAT_1400183e0);
      if (piVar3 == (int *)0x0) {
        NVar1 = 0;
        *param_2 = local_28;
        param_2[1] = uStack_20;
      }
      else {
        ReleasePolicyRef(piVar3);
        NVar1 = -0x3fe6ffed;
      }
    }
  }
  return NVar1;
}



===== SrpPolicyTransactionRollback @ 1400260e8 =====

void SrpPolicyTransactionRollback(void)

{
  int *piVar1;
  
  ExEnterCriticalRegionAndAcquireResourceExclusive(&DAT_1400183e0);
  piVar1 = DAT_140018448;
  DAT_140018448 = (int *)0x0;
  DAT_140018450 = 0;
  DAT_140018458 = 0;
  ExReleaseResourceAndLeaveCriticalRegion(&DAT_1400183e0);
  if (piVar1 != (int *)0x0) {
    ReleasePolicyRef(piVar1);
  }
  return;
}



===== AppLockerPluginNotifyRoutine @ 140026150 =====

undefined8
AppLockerPluginNotifyRoutine
          (longlong *param_1,uint param_2,longlong param_3,undefined8 param_4,undefined8 param_5,
          longlong param_6,longlong param_7,undefined8 *param_8,uint *param_9)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  longlong *plVar4;
  ulonglong uVar5;
  char cVar6;
  bool bVar7;
  char local_58;
  char local_57 [7];
  longlong local_50;
  undefined8 local_48;
  longlong lStack_40;
  wchar_t local_38 [4];
  wchar_t *pwStack_30;
  
  local_50 = 0;
  local_58 = '\0';
  local_38[0] = L'\0';
  local_38[1] = L'\0';
  local_38[2] = L'\0';
  local_38[3] = L'\0';
  pwStack_30 = (wchar_t *)0x0;
  cVar6 = '\0';
  local_48 = 0;
  lStack_40 = 0;
  iVar1 = AiOpenTokenByProcessId(param_5,&local_50);
  if (iVar1 < 0) goto LAB_14002631d;
  pcVar3 = &local_58;
  iVar1 = SrpIsTokenService(local_50,pcVar3);
  if (iVar1 < 0) goto LAB_14002631d;
  if ((*param_1 == 0x4b71a17234b165b1) && (param_1[1] == 0x7c91549c5732b395)) {
    local_48 = CONCAT62(CONCAT42(local_48._4_4_,*(undefined2 *)(param_7 + 8)),
                        *(undefined2 *)(param_7 + 8));
    lStack_40 = param_7 + 10;
    pwStack_30 = L"Dll";
LAB_14002623e:
    local_38[0] = L'\x06';
    local_38[1] = L'\b';
    local_38[2] = L'\0';
    local_38[3] = L'\0';
  }
  else {
    local_48 = **(undefined8 **)(param_7 + 0x30);
    lStack_40 = (*(undefined8 **)(param_7 + 0x30))[1];
    if ((*param_1 != 0x4896ef1a58125a50) || (param_1[1] != 0x6ccab39ac6d657ba)) {
      pwStack_30 = L"Exe";
      goto LAB_14002623e;
    }
    local_38[0] = L'\b';
    local_38[1] = L'\n';
    local_38[2] = L'\0';
    local_38[3] = L'\0';
    pwStack_30 = L"Appx";
    cVar6 = '\x01';
  }
  uVar5 = 0;
  if (param_2 != 0) {
    plVar4 = (longlong *)(param_3 + 0x18);
    do {
      uVar2 = *(uint *)(*plVar4 + 0x18) & 0xc;
      if (local_58 == '\0') {
        bVar7 = uVar2 == 8;
      }
      else {
        bVar7 = uVar2 == 0;
      }
      if (!bVar7) {
        AiEvaluateAppLockerPolicyClass
                  ((ulonglong)uVar2,pcVar3,uVar5 * 0x20 + param_3,param_6,param_9);
        pcVar3 = (char *)*plVar4;
        SrpDisplayAccessReason
                  (DAT_140018718,(longlong)pcVar3,local_38,param_9[1],(wchar_t *)&local_48,param_6,
                   (char)param_5,cVar6);
        if (*param_9 != 0) {
          if ((cVar6 == '\0') || ((param_9[1] & 0xff0000) == 0x20000)) break;
          pcVar3 = local_57;
          local_57[0] = '\0';
          iVar1 = AiIsAppxInbox(param_8,pcVar3);
          if ((iVar1 < 0) || (local_57[0] == '\0')) break;
          *param_9 = 0;
        }
      }
      uVar2 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar2;
      plVar4 = plVar4 + 4;
    } while (uVar2 < param_2);
  }
LAB_14002631d:
  if (local_50 != 0) {
    ZwClose();
  }
  return 0;
}



===== SrpCreatePluginFileName @ 14002635c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SrpCreatePluginFileName(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  ulonglong uVar2;
  undefined1 auStack_248 [32];
  wchar_t local_228 [264];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_248;
  memset(local_228,0,0x208);
  uVar2 = RtlStringCchPrintfW(local_228,0x104,
                              L"\\SystemRoot\\System32\\AppLocker\\plugin.%I64i.Policy",param_1);
  if (-1 < (int)uVar2) {
    cVar1 = RtlCreateUnicodeString(param_2,local_228);
    uVar2 = (ulonglong)(~-(uint)(cVar1 != '\0') & 0xc0000017);
  }
  return uVar2;
}



===== SrpDisplayAccessReason @ 1400263f8 =====

void SrpDisplayAccessReason
               (undefined8 param_1,longlong param_2,wchar_t *param_3,uint param_4,wchar_t *param_5,
               undefined8 param_6,undefined1 param_7,char param_8)

{
  short sVar1;
  uint uVar2;
  undefined *puVar3;
  undefined2 uVar4;
  uint *puVar5;
  short *psVar6;
  undefined *puVar7;
  wchar_t *pwVar8;
  wchar_t *pwVar9;
  wchar_t local_68;
  short sStack_66;
  undefined4 uStack_64;
  longlong lStack_60;
  wchar_t local_58;
  short sStack_56;
  undefined4 uStack_54;
  longlong lStack_50;
  short local_48 [4];
  longlong lStack_40;
  
  _local_58 = 0;
  lStack_50 = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  lStack_40 = 0;
  _local_68 = 0;
  lStack_60 = 0;
  if ((*(byte *)(param_2 + 0x18) & 1) == 0) {
    puVar7 = &SrpProcessAudited;
    puVar3 = &SrpAppxProcessAudited;
  }
  else {
    puVar3 = &SrpAppxProcessDisabled;
    puVar7 = &SrpProcessDisabled;
  }
  if (param_8 != '\0') {
    puVar7 = puVar3;
  }
  if (param_5 == (wchar_t *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) {
      WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_33080b75deef3fb5316bbc69d46312e2_Traceguids,param_3);
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) {
    WPP_SF_ZZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
              &WPP_33080b75deef3fb5316bbc69d46312e2_Traceguids,param_3,param_5);
  }
  uVar2 = param_4 & 0xff0000;
  if (uVar2 < 0x300001) {
    if (uVar2 == 0x300000) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) {
        uVar4 = 0x13;
LAB_1400267fa:
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
                &WPP_33080b75deef3fb5316bbc69d46312e2_Traceguids);
      }
    }
    else {
      if (uVar2 != 0) {
        if (uVar2 == 0x10000) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                    &WPP_33080b75deef3fb5316bbc69d46312e2_Traceguids);
          }
          puVar7 = &SrpProcessAllowed;
          if (param_8 != '\0') {
            puVar7 = &SrpAppxProcessAllowed;
          }
        }
        else {
          if (uVar2 != 0x20000) {
            if (uVar2 == 0x100000) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) {
                uVar4 = 0x11;
                goto LAB_1400267fa;
              }
            }
            else {
              if (uVar2 != 0x200000) goto LAB_140026752;
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) {
                uVar4 = 0x12;
                goto LAB_1400267fa;
              }
            }
            goto LAB_140026806;
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                    &WPP_33080b75deef3fb5316bbc69d46312e2_Traceguids);
          }
        }
        puVar5 = (uint *)((ulonglong)*(uint *)(param_2 + 8) +
                         ((ulonglong)param_4 & 0xffff) * 0x1c + param_2);
        sVar1 = (short)puVar5[3];
        _local_58 = CONCAT22(sVar1,sVar1);
        if (sVar1 == 0) {
          lStack_50 = 0;
        }
        else {
          lStack_50 = (ulonglong)puVar5[2] + param_2;
        }
        if (((lStack_50 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) {
          WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                   &WPP_33080b75deef3fb5316bbc69d46312e2_Traceguids,&local_58);
        }
        sVar1 = (short)puVar5[5];
        _local_68 = CONCAT22(sVar1,sVar1);
        if (sVar1 == 0) {
          lStack_60 = 0;
        }
        else {
          lStack_60 = (ulonglong)puVar5[4] + param_2;
        }
        if (((lStack_60 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) {
          WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                   &WPP_33080b75deef3fb5316bbc69d46312e2_Traceguids,&local_68);
        }
        sVar1 = (short)puVar5[1];
        local_48[1] = sVar1;
        local_48[0] = sVar1;
        if (sVar1 == 0) {
          lStack_40 = 0;
        }
        else {
          lStack_40 = (ulonglong)*puVar5 + param_2;
        }
        LOCK();
        puVar5[6] = puVar5[6] + 1;
        UNLOCK();
        psVar6 = local_48;
        pwVar9 = &local_68;
        pwVar8 = &local_58;
        goto LAB_14002682c;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) {
        uVar4 = 0x10;
        goto LAB_1400267fa;
      }
    }
  }
  else if (uVar2 == 0x400000) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) {
      uVar4 = 0x14;
      goto LAB_1400267fa;
    }
  }
  else if (uVar2 == 0x500000) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) {
      uVar4 = 0x15;
      goto LAB_1400267fa;
    }
  }
  else if (uVar2 == 0x600000) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) {
      uVar4 = 0x16;
      goto LAB_1400267fa;
    }
  }
  else if (uVar2 == 0x700000) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) {
      uVar4 = 0x17;
      goto LAB_1400267fa;
    }
  }
  else if (uVar2 == 0x800000) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) {
      uVar4 = 0x18;
      goto LAB_1400267fa;
    }
  }
  else {
LAB_140026752:
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
               &WPP_33080b75deef3fb5316bbc69d46312e2_Traceguids,param_4);
    }
  }
LAB_140026806:
  psVar6 = (short *)0x0;
  pwVar9 = (wchar_t *)0x0;
  pwVar8 = (wchar_t *)0x0;
LAB_14002682c:
  if (param_8 == '\0') {
    AiLogSrpRuleEvent(param_1,puVar7,(ushort *)param_3,psVar6,(ushort *)pwVar8,(ushort *)pwVar9,
                      param_5,param_6,param_7);
  }
  else {
    AiLogAppxSrpRuleEvent
              (param_1,puVar7,(ushort *)param_3,psVar6,(ushort *)pwVar8,(ushort *)pwVar9,param_5,
               param_6,param_7);
  }
  return;
}



===== SrpFreePlugin @ 14002686c =====

void SrpFreePlugin(longlong param_1,uint param_2)

{
  ulonglong uVar1;
  longlong *plVar2;
  
  if (param_2 != 0) {
    plVar2 = (longlong *)(param_1 + 0x18);
    uVar1 = (ulonglong)param_2;
    do {
      if (*plVar2 != 0) {
        ExFreePoolWithTag(*plVar2,0);
      }
      plVar2 = plVar2 + 4;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  if (param_1 != 0) {
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== SrpGetPluginFileName @ 1400268d8 =====

ulonglong SrpGetPluginFileName(undefined8 param_1)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  longlong lVar5;
  longlong local_res10;
  longlong local_res18;
  undefined8 local_88;
  wchar_t *local_80;
  undefined8 local_78;
  longlong lStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_58 = 0x30;
  local_40 = 0x240;
  local_80 = L"\\SystemRoot\\System32\\Applocker";
  local_48 = &local_88;
  local_res10 = 0;
  local_88 = 0x3e003c;
  local_50 = 0;
  uVar4 = 0x54;
  lVar2 = 0;
  local_78 = 0;
  lStack_70 = 0;
  local_38 = 0;
  uStack_30 = 0;
  uVar1 = ZwOpenFile(&local_res10,0x100001,&local_58,&local_78,7,0x4021);
  uVar3 = (ulonglong)uVar1;
  lVar5 = 0;
  if (-1 < (int)uVar1) {
LAB_14002697d:
    do {
      if (lVar2 == 0) {
LAB_14002699d:
        lVar2 = AiAlloc((ulonglong)uVar4);
        if (lVar2 == 0) {
          uVar3 = 0xc0000017;
          break;
        }
      }
      else if ((int)uVar3 == -0x7ffffffb) {
        ExFreePoolWithTag(lVar2,0);
        uVar4 = uVar4 * 2;
        goto LAB_14002699d;
      }
      uVar1 = ZwQueryDirectoryFile(local_res10,0,0,0,&local_78,lVar2,uVar4,0xc,1,&DAT_140008400,0);
      uVar3 = (ulonglong)uVar1;
      if ((int)uVar1 < 0) {
        if (uVar1 != 0x80000005) {
          if (uVar1 == 0x80000006) goto LAB_140026ab2;
          if (uVar1 != 0xc000000f) goto LAB_140026abf;
        }
      }
      else if (lStack_70 == 0) {
        uVar3 = 0x80000005;
      }
      else {
        if ((*(uint *)(lVar2 + 8) & 0xfffffffe) < 0x1d) goto LAB_14002697d;
        local_res18 = 0;
        local_68 = 0;
        uStack_60 = 0;
        *(undefined2 *)(lVar2 + -2 + (ulonglong)(*(uint *)(lVar2 + 8) >> 1) * 2) = 0;
        RtlInitUnicodeString(&local_68,lVar2 + 0x1a);
        uVar1 = RtlUnicodeStringToInt64(&local_68);
        uVar3 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          if ((-1 < local_res18) && (lVar5 < local_res18)) {
            lVar5 = local_res18;
          }
          goto LAB_14002697d;
        }
      }
      if (((int)uVar3 == -0x7ffffffa) || ((int)uVar3 == -0x3ffffff1)) goto LAB_140026ab2;
    } while( true );
  }
LAB_140026adc:
  if (local_res10 != 0) {
    ZwClose();
  }
  return uVar3;
LAB_140026ab2:
  uVar3 = SrpCreatePluginFileName(lVar5,param_1);
  uVar3 = uVar3 & 0xffffffff;
LAB_140026abf:
  if (lVar2 != 0) {
    ExFreePoolWithTag(lVar2,0);
  }
  goto LAB_140026adc;
}



===== SrpLoadPlugin @ 140026b18 =====

ulonglong SrpLoadPlugin(undefined8 param_1,longlong *param_2,undefined8 *param_3,uint *param_4,
                       uint *param_5)

{
  undefined8 uVar1;
  undefined8 uVar2;
  bool bVar3;
  char cVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong lVar8;
  void *_Dst;
  uint uVar9;
  uint uVar10;
  char cVar11;
  longlong *plVar12;
  longlong *plVar13;
  uint uVar14;
  uint *puVar15;
  void *pvVar16;
  undefined4 *puVar17;
  uint local_c8;
  undefined4 *local_c0;
  uint local_b8;
  uint local_b4;
  longlong local_b0;
  ulonglong local_a8;
  wchar_t *pwStack_a0;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  ulonglong local_70;
  wchar_t *pwStack_68;
  undefined8 local_60;
  longlong lStack_58;
  
  local_b0 = 0;
  puVar17 = (undefined4 *)0x0;
  local_a8 = 0;
  pwStack_a0 = (wchar_t *)0x0;
  *param_5 = 0;
  _Dst = (void *)0x0;
  local_c0 = (undefined4 *)0x0;
  uVar10 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_b8 = 0;
  local_70 = 0;
  pwStack_68 = (wchar_t *)0x0;
  local_c8 = 0;
  local_60 = 0;
  lStack_58 = 0;
  cVar11 = '\0';
  local_90 = 0;
  uStack_88 = 0;
  *param_3 = 0;
  *param_4 = 0;
  uVar6 = SrpGetPluginFileName(&local_90);
  uVar7 = uVar6 & 0xffffffff;
  if ((int)uVar6 < 0) goto LAB_140026e72;
  uVar5 = SrpOpenFile(&local_90,&local_b0);
  uVar7 = (ulonglong)uVar5;
  if ((int)uVar5 < 0) goto LAB_140026e72;
  uVar7 = AiGetPlugins(local_b0,&local_c0);
  puVar17 = local_c0;
  local_b4 = (uint)uVar7;
  uVar7 = uVar7 & 0xffffffff;
  if ((int)local_b4 < 0) goto LAB_140026e72;
  pvVar16 = _Dst;
  uVar5 = uVar10;
  if (local_c0[7] == 0) goto LAB_140026e62;
  uVar14 = 0;
  uVar5 = local_c0[4];
  plVar13 = (longlong *)((ulonglong)(uint)local_c0[2] + (longlong)local_c0);
  if (local_c0[3] != 0) {
    bVar3 = false;
    do {
      if ((*plVar13 == 0x4e8001e33b207045) && (plVar13[1] == 0x36f6d035fb531a99)) {
        uVar9 = 0;
        plVar12 = (longlong *)
                  ((longlong)puVar17 +
                  (ulonglong)*(uint *)((longlong)plVar13 + 0x1c) * 0x1c + (ulonglong)uVar5);
        if (*(uint *)(plVar13 + 4) != 0) {
          do {
            if ((*plVar12 == *param_2) && (plVar12[1] == param_2[1])) {
              *param_5 = 0;
              lVar8 = *plVar12 + -0x4896ef1a58125a50;
              if (lVar8 == 0) {
                lVar8 = plVar12[1] + -0x6ccab39ac6d657ba;
              }
              if (lVar8 == 0) {
                cVar11 = '\x01';
              }
              AiSetAttributes(param_5,*(uint *)(plVar12 + 2),cVar11);
              local_b8 = *(uint *)((longlong)plVar12 + 0x14);
              bVar3 = true;
              local_c8 = *(uint *)(plVar12 + 3);
              uVar10 = local_c8;
              break;
            }
            uVar9 = uVar9 + 1;
            plVar12 = (longlong *)((longlong)plVar12 + 0x1c);
            uVar10 = local_c8;
          } while (uVar9 < *(uint *)(plVar13 + 4));
        }
      }
      uVar14 = uVar14 + 1;
      plVar13 = (longlong *)((longlong)plVar13 + 0x24);
    } while (uVar14 < (uint)puVar17[3]);
    uVar7 = (ulonglong)local_b4;
    if (bVar3) {
      pvVar16 = (void *)0x0;
      uVar5 = 0;
      if (uVar10 == 0) {
LAB_140026e62:
        _Dst = (void *)0x0;
        *param_3 = pvVar16;
        *param_4 = uVar5;
      }
      else {
        _Dst = (void *)AiAlloc((ulonglong)uVar10 << 5);
        if (_Dst != (void *)0x0) {
          memset(_Dst,0,(ulonglong)uVar10 << 5);
          cVar4 = RtlCreateUnicodeString
                            (&local_a8,
                             L"\\SystemRoot\\System32\\AppLocker\\{........-....-....-....-............}.Policy"
                            );
          if (cVar4 != '\0') {
            uVar10 = 0;
            puVar15 = (uint *)((longlong)puVar17 +
                              (ulonglong)(uint)puVar17[6] + (ulonglong)local_b8 * 0x10);
            local_c0 = (undefined4 *)((longlong)_Dst + 0x14);
            do {
              uVar6 = RtlStringCchPrintfW(pwStack_a0,local_a8 >> 0x11 & 0x7fff,
                                          L"\\SystemRoot\\System32\\AppLocker\\{%08x-%04hx-%04hx-%02x%02x-%02x%02x%02x%02x%02x%02x}.Policy"
                                          ,(ulonglong)*puVar15);
              uVar7 = uVar6 & 0xffffffff;
              if ((int)uVar6 < 0) goto LAB_140026e72;
              local_80 = 0;
              local_60 = 0;
              lStack_58 = 0;
              uStack_78 = 0;
              local_70 = local_a8;
              pwStack_68 = pwStack_a0;
              uVar5 = SrpLoadPolicy((longlong)&local_80);
              uVar7 = (ulonglong)uVar5;
              if ((int)uVar5 < 0) goto LAB_140026e72;
              lVar8 = lStack_58;
              AiSetAttributes(param_5,*(uint *)(lStack_58 + 0x1c),cVar11);
              uVar10 = uVar10 + 1;
              *(longlong *)(local_c0 + 1) = lVar8;
              *local_c0 = 1;
              local_c0[-1] = 0;
              uVar1 = *(undefined8 *)puVar15;
              uVar2 = *(undefined8 *)(puVar15 + 2);
              puVar15 = puVar15 + 4;
              *(undefined8 *)(local_c0 + -5) = uVar1;
              *(undefined8 *)(local_c0 + -3) = uVar2;
              local_c0 = local_c0 + 8;
              pvVar16 = _Dst;
              uVar5 = local_c8;
            } while (uVar10 < local_c8);
            goto LAB_140026e62;
          }
        }
        uVar7 = 0xc0000017;
      }
      goto LAB_140026e72;
    }
  }
  _Dst = (void *)0x0;
  uVar7 = 0xc0000225;
LAB_140026e72:
  RtlFreeUnicodeString(&local_a8);
  if (local_b0 != 0) {
    ZwClose(local_b0);
  }
  if (puVar17 != (undefined4 *)0x0) {
    ExFreePoolWithTag(puVar17,0);
  }
  if (_Dst != (void *)0x0) {
    SrpFreePlugin((longlong)_Dst,local_c8);
  }
  RtlFreeUnicodeString(&local_90);
  return uVar7;
}



===== SrpLoadPlugins @ 140026ef4 =====

int SrpLoadPlugins(wchar_t *param_1)

{
  wchar_t *pwVar1;
  char cVar2;
  int iVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  void *_Dst;
  undefined8 uVar6;
  longlong lVar7;
  uint *puVar8;
  uint uVar9;
  longlong local_res8;
  longlong local_res10;
  undefined8 local_48;
  longlong lStack_40;
  
  local_res8 = 0;
  param_1[8] = L'\0';
  param_1[9] = L'\0';
  local_48 = 0;
  lStack_40 = 0;
  iVar3 = SrpOpenFile(param_1,&local_res8);
  if (iVar3 < 0) {
    if (iVar3 != -0x3fffffcc) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) {
        WPP_SF_ZD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_33080b75deef3fb5316bbc69d46312e2_Traceguids,param_1,(char)iVar3);
      }
      goto LAB_1400271b4;
    }
    iVar3 = 0;
    puVar4 = (undefined8 *)ExAllocatePool2(0x102,0x20,0x44497041);
    *(undefined8 **)(param_1 + 0xc) = puVar4;
LAB_140026f5a:
    if (puVar4 != (undefined8 *)0x0) {
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[2] = 0;
      puVar4[3] = 0;
      goto LAB_1400271b4;
    }
  }
  else {
    pwVar1 = param_1 + 0xc;
    lVar7 = local_res8;
    uVar5 = AiGetPlugins(local_res8,(undefined8 *)pwVar1);
    iVar3 = (int)uVar5;
    if (iVar3 < 0) {
      *(int *)(param_1 + 8) = iVar3;
      if (iVar3 == -0x3ffffff3) {
        AiRegWriteDwordValue(lVar7,&DAT_140008410,&DAT_140008420,1);
      }
      puVar4 = (undefined8 *)ExAllocatePool2(0x102,0x20,0x44497041);
      *(undefined8 **)pwVar1 = puVar4;
      goto LAB_140026f5a;
    }
    lVar7 = *(longlong *)pwVar1;
    if (*(uint *)(lVar7 + 0x1c) == 0) goto LAB_1400271b4;
    _Dst = (void *)AiAlloc((ulonglong)*(uint *)(lVar7 + 0x1c) * 0x30);
    *(void **)(param_1 + 0x10) = _Dst;
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,(ulonglong)*(uint *)(lVar7 + 0x1c) * 0x30);
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(lVar7 + 0x1c);
      cVar2 = RtlCreateUnicodeString
                        (&local_48,
                         L"\\SystemRoot\\System32\\AppLocker\\{........-....-....-....-............}.Policy"
                        );
      if (cVar2 != '\0') {
        uVar5 = 0;
        puVar8 = (uint *)((ulonglong)*(uint *)(lVar7 + 0x18) + lVar7);
        if (*(int *)(param_1 + 0x14) != 0) {
          do {
            local_res10 = uVar5 * 0x30;
            puVar4 = (undefined8 *)(local_res10 + *(longlong *)(param_1 + 0x10) + 0x10);
            if (lStack_40 == 0) {
              cVar2 = RtlCreateUnicodeString
                                (puVar4,
                                 L"\\SystemRoot\\System32\\AppLocker\\{........-....-....-....-............}.Policy"
                                );
              if (cVar2 == '\0') goto LAB_1400271af;
            }
            else {
              *puVar4 = local_48;
              puVar4[1] = lStack_40;
              local_48 = 0;
              lStack_40 = 0;
            }
            lVar7 = local_res10;
            uVar6 = RtlStringCchPrintfW(*(wchar_t **)
                                         (local_res10 + 0x18 + *(longlong *)(param_1 + 0x10)),
                                        (ulonglong)
                                        (*(ushort *)
                                          (local_res10 + 0x12 + *(longlong *)(param_1 + 0x10)) >> 1)
                                        ,
                                        L"\\SystemRoot\\System32\\AppLocker\\{%08x-%04hx-%04hx-%02x%02x-%02x%02x%02x%02x%02x%02x}.Policy"
                                        ,(ulonglong)*puVar8);
            iVar3 = (int)uVar6;
            if ((iVar3 < 0) ||
               (iVar3 = SrpLoadPolicy(*(longlong *)(param_1 + 0x10) + lVar7), iVar3 < 0)) break;
            uVar9 = (int)uVar5 + 1;
            uVar5 = (ulonglong)uVar9;
            puVar8 = puVar8 + 4;
          } while (uVar9 < *(uint *)(param_1 + 0x14));
        }
        goto LAB_1400271b4;
      }
    }
  }
LAB_1400271af:
  iVar3 = -0x3fffffe9;
LAB_1400271b4:
  RtlFreeUnicodeString(&local_48);
  if (local_res8 != 0) {
    ZwClose();
  }
  return iVar3;
}



===== SrpLoadPolicy @ 140027204 =====

int SrpLoadPolicy(longlong param_1)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong local_res8;
  
  *(undefined4 *)(param_1 + 0x20) = 0;
  local_res8 = 0;
  iVar1 = SrpOpenFile(param_1 + 0x10,&local_res8);
  if (iVar1 < 0) {
    if ((iVar1 != -0x3fffffcc) && (iVar1 != -0x3fffffc6)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) {
        WPP_SF_ZD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                  &WPP_33080b75deef3fb5316bbc69d46312e2_Traceguids,(wchar_t *)(param_1 + 0x10),
                  (char)iVar1);
      }
      goto LAB_1400272fa;
    }
    iVar1 = 0;
  }
  else {
    lVar4 = local_res8;
    uVar2 = AiGetPolicy(local_res8,(undefined8 *)(param_1 + 0x28));
    iVar1 = (int)uVar2;
    if (-1 < iVar1) goto LAB_1400272fa;
    *(int *)(param_1 + 0x20) = iVar1;
    if (iVar1 == -0x3ffffff3) {
      AiRegWriteDwordValue(lVar4,&DAT_140008430,&DAT_140008440,1);
    }
  }
  puVar3 = (undefined8 *)ExAllocatePool2(0x102,0x20,0x44497041);
  *(undefined8 **)(param_1 + 0x28) = puVar3;
  if (puVar3 == (undefined8 *)0x0) {
    iVar1 = -0x3fffffe9;
  }
  else {
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
  }
LAB_1400272fa:
  if (local_res8 != 0) {
    ZwClose(local_res8);
  }
  return iVar1;
}



===== SrpOpenFile @ 140027334 =====

int SrpOpenFile(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  uint uVar2;
  undefined8 local_res8;
  undefined8 local_res18 [2];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res8 = 0;
  local_2c = 0;
  local_40 = 0;
  local_48 = 0x30;
  uVar2 = 0;
  local_30 = 0x240;
  local_58 = 0;
  uStack_50 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_res18[0] = 0xffffffffff676980;
  local_38 = param_1;
  do {
    iVar1 = ZwOpenFile(&local_res8,0x80100000,&local_48,&local_58,1,0x20);
    if (iVar1 != -0x3fffffbd) break;
    KeDelayExecutionThread(0,0,local_res18);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 10);
  if (-1 < iVar1) {
    *param_2 = local_res8;
  }
  return iVar1;
}



===== AiLogAppxSrpRuleEvent @ 1400273f8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AiLogAppxSrpRuleEvent
               (undefined8 param_1,undefined8 param_2,ushort *param_3,short *param_4,ushort *param_5
               ,ushort *param_6,wchar_t *param_7,undefined8 param_8,undefined1 param_9)

{
  ushort uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  wchar_t *_Dst;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  short *psVar8;
  undefined8 *puVar9;
  ushort *puVar10;
  ushort *puVar11;
  wchar_t *pwVar12;
  undefined1 auStack_1a8 [32];
  ushort local_168 [2];
  ushort local_164 [2];
  ushort local_160 [2];
  ushort local_15c [2];
  ushort local_158 [4];
  wchar_t *local_150;
  longlong local_148;
  undefined8 *local_140;
  undefined8 local_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 uStack_120;
  ushort *local_118;
  undefined4 local_110;
  undefined4 local_10c;
  undefined8 local_108;
  uint local_100;
  undefined4 local_fc;
  undefined8 *local_f8;
  undefined8 local_f0;
  ushort *local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  uint local_d0;
  undefined4 local_cc;
  ushort *local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  uint local_b0;
  undefined4 local_ac;
  undefined8 local_a8;
  ulonglong uStack_a0;
  undefined1 *local_98;
  undefined8 uStack_90;
  ushort *local_88;
  undefined8 local_80;
  undefined8 local_78;
  uint local_70;
  undefined4 local_6c;
  ushort *local_68;
  undefined8 local_60;
  wchar_t *local_58;
  ulonglong local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_1a8;
  local_150 = param_7;
  local_164[0] = 0;
  _Dst = (wchar_t *)0x0;
  local_160[0] = 0;
  lVar6 = 0;
  local_15c[0] = 0;
  puVar9 = (undefined8 *)0x0;
  local_158[0] = 0;
  local_168[0] = 0;
  local_148 = 0;
  local_140 = (undefined8 *)0x0;
  local_128 = 0;
  uStack_120 = 0;
  local_138 = param_2;
  local_130 = param_1;
  cVar2 = EtwEventEnabled();
  if (cVar2 != '\0') {
    local_100 = (uint)*param_3;
    local_110 = 2;
    puVar10 = (ushort *)&DAT_1400084e0;
    if (param_5 != (ushort *)0x0) {
      puVar10 = param_5;
    }
    local_a8 = 0;
    uStack_a0 = 0;
    local_98 = (undefined1 *)0x0;
    uStack_90 = 0;
    puVar11 = (ushort *)&DAT_1400084e0;
    if (param_6 != (ushort *)0x0) {
      puVar11 = param_6;
    }
    local_10c = 0;
    local_164[0] = *param_3 >> 1;
    local_118 = local_164;
    local_108 = *(undefined8 *)(param_3 + 4);
    local_fc = 0;
    psVar8 = (short *)&DAT_1400084e0;
    if (param_4 != (short *)0x0) {
      psVar8 = param_4;
    }
    iVar3 = AipGUIDFromString(psVar8);
    pwVar12 = local_150;
    if (iVar3 < 0) {
      local_128 = 0;
      uStack_120 = 0;
    }
    local_f8 = &local_128;
    local_d0 = (uint)*puVar10;
    local_160[0] = *puVar10 >> 1;
    local_e8 = local_160;
    local_d8 = *(undefined8 *)(puVar10 + 4);
    local_15c[0] = *puVar11 >> 1;
    local_c8 = local_15c;
    local_b8 = *(undefined8 *)(puVar11 + 4);
    local_b0 = (uint)*puVar11;
    local_f0 = 0x10;
    local_70 = (uint)(ushort)*local_150;
    local_158[0] = (ushort)*local_150 >> 1;
    local_88 = local_158;
    local_78 = *(undefined8 *)(local_150 + 4);
    local_68 = local_168;
    local_58 = L"-";
    local_e0 = 2;
    local_cc = 0;
    local_c0 = 2;
    local_ac = 0;
    local_80 = 2;
    local_6c = 0;
    local_168[0] = 1;
    local_60 = 2;
    local_50 = 2;
    iVar3 = AiQueryUserSid(param_8,(longlong *)&local_140);
    puVar9 = local_140;
    if (-1 < iVar3) {
      uVar4 = RtlLengthSid(*local_140);
      local_a8 = *puVar9;
      local_98 = &param_9;
      uStack_a0 = (ulonglong)uVar4;
      uStack_90 = 4;
      iVar3 = AiQueryTokenAttributes(param_8,&local_148);
      lVar6 = local_148;
      if (-1 < iVar3) {
        uVar4 = 0;
        lVar7 = *(longlong *)(local_148 + 8);
        if (*(int *)(local_148 + 4) != 0) {
          do {
            cVar2 = RtlEqualUnicodeString(lVar7,&DAT_1400084d0,1);
            if ((((cVar2 != '\0') && (*(short *)(lVar7 + 0x10) == 4)) &&
                (*(int *)(lVar7 + 0x18) == 1)) &&
               (uVar1 = *(ushort *)(*(longlong *)(lVar7 + 0x20) + 8), (ushort)(uVar1 - 1) < 0xffcd))
            {
              local_168[0] = uVar1 >> 1;
              _Dst = (wchar_t *)
                     AiAlloc((ulonglong)*(ushort *)(*(longlong *)(lVar7 + 0x20) + 8) + 0x32);
              if (_Dst == (wchar_t *)0x0) {
                iVar3 = -0x3fffffe9;
                goto LAB_1400277ba;
              }
              memmove(_Dst,*(void **)(*(longlong *)(lVar7 + 0x20) + 0x10),
                      (ulonglong)*(ushort *)(*(longlong *)(lVar7 + 0x20) + 8));
              RtlStringCbPrintfW((ushort *)(_Dst + local_168[0]),0x32,(ushort *)L"\\%u.%u.%u.%02u",
                                 **(ulonglong **)(lVar7 + 0x20) >> 0x30);
              lVar5 = -1;
              do {
                lVar5 = lVar5 + 1;
              } while (_Dst[(ulonglong)local_168[0] + lVar5] != L'\0');
              local_168[0] = local_168[0] + (short)lVar5;
              local_60 = 2;
              local_68 = local_168;
              local_50 = (ulonglong)((uint)local_168[0] * 2);
              local_58 = _Dst;
            }
            uVar4 = uVar4 + 1;
            lVar7 = lVar7 + 0x28;
          } while (uVar4 < *(uint *)(lVar6 + 4));
        }
        iVar3 = EtwWrite(local_130,local_138,0,0xd);
        if (-1 < iVar3) goto LAB_1400277f8;
LAB_1400277ba:
        pwVar12 = local_150;
      }
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) {
      WPP_SF_ZD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                &WPP_ba82aeedd69c3fe8448d5535e4644288_Traceguids,pwVar12,(char)iVar3);
    }
  }
LAB_1400277f8:
  if (puVar9 != (undefined8 *)0x0) {
    ExFreePoolWithTag(puVar9,0);
  }
  if (lVar6 != 0) {
    ExFreePoolWithTag(lVar6,0);
  }
  if (_Dst != (wchar_t *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
  return;
}



===== AiLogCheckCmdlineAgainstUninstallString @ 140027874 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AiLogCheckCmdlineAgainstUninstallString
               (undefined8 param_1,undefined8 param_2,wchar_t *param_3,ushort *param_4,byte param_5,
               undefined4 param_6)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined1 auStackY_c8 [32];
  ushort local_98 [2];
  ushort local_94 [2];
  uint local_90 [2];
  ushort *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  uint local_70;
  undefined4 local_6c;
  ushort *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  uint local_50;
  undefined4 local_4c;
  uint *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_90[0] = (uint)param_5;
  cVar1 = EtwEventEnabled(param_1,&AppIdCheckCmdlineAgainstUninstallStringEvent);
  if (cVar1 != '\0') {
    local_7c = 0;
    local_6c = 0;
    uVar3 = 0;
    local_5c = 0;
    local_4c = 0;
    local_3c = 0;
    local_2c = 0;
    local_98[0] = (ushort)*param_3 >> 1;
    local_88 = local_98;
    local_78 = *(undefined8 *)(param_3 + 4);
    local_70 = (uint)(ushort)*param_3;
    local_80 = 2;
    local_94[0] = *param_4 >> 1;
    local_68 = local_94;
    local_58 = *(undefined8 *)(param_4 + 4);
    local_48 = local_90;
    local_38 = &param_6;
    local_60 = 2;
    local_50 = (uint)*param_4;
    local_40 = 4;
    local_30 = 4;
    iVar2 = EtwWrite(param_1,&AppIdCheckCmdlineAgainstUninstallStringEvent,0,6);
    if (((iVar2 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
      WPP_SF_ZDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,uVar3,param_3,(char)param_6,
                 (char)iVar2);
    }
  }
  return;
}



===== AiLogEvent @ 1400279c4 =====

void AiLogEvent(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = EtwWrite(param_1,param_2,0,0,0);
  if (((iVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_ba82aeedd69c3fe8448d5535e4644288_Traceguids,iVar1);
  }
  return;
}



===== AiLogFileAndStatusEvent @ 140027a24 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AiLogFileAndStatusEvent
               (undefined8 param_1,undefined8 param_2,wchar_t *param_3,undefined4 param_4)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 local_res20 [2];
  undefined1 auStackY_78 [32];
  ushort local_48 [4];
  ushort *local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  uint local_28;
  undefined4 local_24;
  undefined4 *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  local_34 = 0;
  local_24 = 0;
  local_14 = 0;
  local_48[0] = (ushort)*param_3 >> 1;
  local_40 = local_48;
  local_30 = *(undefined8 *)(param_3 + 4);
  uVar2 = 0;
  local_20 = local_res20;
  local_28 = (uint)(ushort)*param_3;
  local_38 = 2;
  local_18 = 4;
  local_res20[0] = param_4;
  iVar1 = EtwWrite(param_1,&AppIdNewProcessFailed,0,3);
  if (((iVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
    WPP_SF_ZDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,uVar2,param_3,(char)local_res20[0],
               (char)iVar1);
  }
  return;
}



===== AiLogSmartlockerEnforcementStatusEvent @ 140027b0c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AiLogSmartlockerEnforcementStatusEvent
               (undefined8 param_1,undefined8 param_2,wchar_t *param_3,ushort *param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined8 param_8,
               undefined8 param_9,undefined1 param_10,byte param_11,longlong param_12)

{
  int iVar1;
  undefined1 auStack_1d8 [32];
  ushort local_1a8 [2];
  ushort local_1a4 [2];
  undefined4 local_1a0;
  ushort local_19c [2];
  ushort local_198 [4];
  undefined2 local_190 [4];
  uint local_188 [2];
  undefined8 local_180;
  undefined8 uStack_178;
  ushort *local_168;
  undefined8 local_160;
  undefined8 local_158;
  uint local_150;
  undefined4 local_14c;
  ushort *local_148;
  undefined8 local_140;
  undefined8 local_138;
  uint local_130;
  undefined4 local_12c;
  undefined1 *local_128;
  undefined8 local_120;
  undefined1 *local_118;
  undefined8 local_110;
  undefined1 *local_108;
  undefined8 local_100;
  undefined1 *local_f8;
  undefined8 local_f0;
  undefined2 *local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  uint *local_c8;
  undefined8 local_c0;
  undefined8 *local_b8;
  undefined8 local_b0;
  undefined8 *local_a8;
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
  ushort *local_48;
  undefined8 local_40;
  wchar_t *local_38;
  ulonglong local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_1d8;
  local_160 = 2;
  local_1a8[0] = 0;
  local_1a0 = 0;
  local_190[0] = 0x10;
  local_19c[0] = (ushort)*param_3 >> 1;
  local_168 = local_19c;
  local_158 = *(undefined8 *)(param_3 + 4);
  local_148 = local_198;
  local_138 = *(undefined8 *)(param_4 + 4);
  local_128 = &param_5;
  local_118 = &param_10;
  local_108 = &param_6;
  local_f8 = &param_7;
  local_e8 = local_190;
  local_d8 = param_9;
  local_c8 = local_188;
  local_150 = (uint)(ushort)*param_3;
  local_198[0] = *param_4;
  local_188[0] = (uint)param_11;
  local_14c = 0;
  local_140 = 2;
  local_130 = (uint)local_198[0];
  local_12c = 0;
  local_120 = 4;
  local_110 = 4;
  local_100 = 4;
  local_f0 = 8;
  local_e0 = 2;
  local_d0 = 0x10;
  local_c0 = 4;
  local_b0 = 0x10;
  local_a0 = 0x10;
  local_90 = 4;
  local_80 = 4;
  local_70 = 4;
  local_60 = 4;
  local_50 = 4;
  local_40 = 2;
  local_180 = 0;
  uStack_178 = 0;
  if (param_11 == 0) {
    local_b8 = &local_180;
    local_30 = 2;
    local_a8 = &local_180;
    local_98 = &local_1a0;
    local_88 = &local_1a0;
    local_78 = &local_1a0;
    local_68 = &local_1a0;
    local_58 = &local_1a0;
    local_48 = local_1a4;
    local_38 = L"-";
  }
  else {
    local_b8 = (undefined8 *)(param_12 + 0x10);
    local_a8 = (undefined8 *)(param_12 + 0x20);
    local_98 = (undefined4 *)(param_12 + 4);
    local_88 = (undefined4 *)(param_12 + 8);
    local_78 = (undefined4 *)(param_12 + 0xc);
    local_68 = (undefined4 *)(param_12 + 0x30);
    local_58 = (undefined4 *)(param_12 + 0x34);
    local_1a8[0] = (ushort)(*(uint *)(param_12 + 0x38) >> 1);
    local_48 = local_1a8;
    local_38 = (wchar_t *)(param_12 + 0x3c);
    local_30 = (ulonglong)*(uint *)(param_12 + 0x38);
  }
  local_1a4[0] = (ushort)(param_11 == 0);
  iVar1 = EtwWrite(param_1,param_2,0,0x14);
  if (((iVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) {
    WPP_SF_ZD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
              &WPP_ba82aeedd69c3fe8448d5535e4644288_Traceguids,param_3,(char)iVar1);
  }
  return;
}



===== AiLogSrpRuleEvent @ 140027dec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AiLogSrpRuleEvent(undefined8 param_1,undefined8 param_2,ushort *param_3,short *param_4,
                      ushort *param_5,ushort *param_6,wchar_t *param_7,undefined8 param_8,
                      undefined1 param_9)

{
  ushort uVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  wchar_t *_Dst;
  longlong lVar5;
  short *psVar6;
  longlong lVar7;
  undefined8 *puVar8;
  ushort *puVar9;
  longlong lVar10;
  uint uVar11;
  ushort *puVar12;
  longlong lVar13;
  undefined1 auStack_228 [32];
  ushort local_1e8 [2];
  ushort local_1e4 [2];
  undefined2 local_1e0 [2];
  ushort local_1dc [2];
  ushort local_1d8 [2];
  ushort local_1d4 [2];
  ushort local_1d0 [4];
  wchar_t *local_1c8;
  longlong local_1c0;
  undefined8 *local_1b8;
  undefined8 local_1b0;
  ushort local_1a8 [4];
  longlong lStack_1a0;
  ushort *local_198;
  short *local_190;
  undefined8 local_188;
  undefined8 local_180;
  undefined8 local_178;
  undefined8 uStack_170;
  ushort *local_168;
  undefined4 local_160;
  undefined4 local_15c;
  undefined8 local_158;
  uint local_150;
  undefined4 local_14c;
  undefined8 *local_148;
  undefined8 local_140;
  ushort *local_138;
  undefined8 local_130;
  undefined8 local_128;
  uint local_120;
  undefined4 local_11c;
  ushort *local_118;
  undefined8 local_110;
  undefined8 local_108;
  uint local_100;
  undefined4 local_fc;
  undefined8 local_f8;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined1 *local_e8;
  undefined8 local_e0;
  ushort *local_d8;
  undefined8 local_d0;
  longlong local_c8;
  uint local_c0;
  undefined4 local_bc;
  undefined2 *local_b8;
  undefined8 local_b0;
  wchar_t *local_a8;
  ulonglong local_a0;
  ushort *local_98;
  undefined8 local_90;
  wchar_t *local_88;
  ulonglong local_80;
  undefined8 *local_78;
  undefined8 local_70;
  ushort *local_68;
  undefined8 local_60;
  longlong local_58;
  uint local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_228;
  local_1c8 = param_7;
  _Dst = (wchar_t *)0x0;
  local_178 = 0;
  uStack_170 = 0;
  local_1dc[0] = 0;
  lVar10 = 0;
  local_1a8[0] = 0;
  local_1a8[1] = 0;
  local_1a8[2] = 0;
  local_1a8[3] = 0;
  lStack_1a0 = 0;
  local_1d8[0] = 0;
  puVar8 = (undefined8 *)0x0;
  local_1d4[0] = 0;
  local_1e4[0] = 0;
  local_1d0[0] = 0;
  local_1e0[0] = 0;
  local_1e8[0] = 0;
  local_1c0 = 0;
  local_1b8 = (undefined8 *)0x0;
  local_1b0 = 0;
  local_198 = param_3;
  local_190 = param_4;
  local_188 = param_2;
  local_180 = param_1;
  cVar2 = EtwEventEnabled();
  if (cVar2 == '\0') {
    lVar13 = lStack_1a0;
    goto LAB_1400283d1;
  }
  uVar4 = AipNtPathToDosPath((ushort *)param_7,local_1a8);
  lVar13 = lStack_1a0;
  iVar3 = (int)uVar4;
  if (-1 < iVar3) {
    puVar9 = (ushort *)&DAT_1400084c0;
    if (param_5 != (ushort *)0x0) {
      puVar9 = param_5;
    }
    puVar12 = (ushort *)&DAT_1400084c0;
    if (param_6 != (ushort *)0x0) {
      puVar12 = param_6;
    }
    memset(&local_168,0,0x120);
    local_15c = 0;
    local_14c = 0;
    local_160 = 2;
    local_150 = (uint)*local_198;
    local_1dc[0] = *local_198 >> 1;
    local_168 = local_1dc;
    local_158 = *(undefined8 *)(local_198 + 4);
    psVar6 = (short *)&DAT_1400084c0;
    if (local_190 != (short *)0x0) {
      psVar6 = local_190;
    }
    iVar3 = AipGUIDFromString(psVar6);
    if (iVar3 < 0) {
      local_178 = 0;
      uStack_170 = 0;
    }
    local_148 = &local_178;
    local_120 = (uint)*puVar9;
    local_1d8[0] = *puVar9 >> 1;
    local_138 = local_1d8;
    local_128 = *(undefined8 *)(puVar9 + 4);
    local_1d4[0] = *puVar12 >> 1;
    local_118 = local_1d4;
    local_11c = 0;
    local_b8 = local_1e0;
    local_100 = (uint)*puVar12;
    local_1e4[0] = local_1a8[0] >> 1;
    local_108 = *(undefined8 *)(puVar12 + 4);
    local_d8 = local_1e4;
    local_1e8[0] = 1;
    local_68 = local_1d0;
    local_98 = local_1e8;
    local_140 = 0x10;
    local_130 = 2;
    local_110 = 2;
    local_fc = 0;
    local_d0 = 2;
    local_c8 = lVar13;
    local_c0 = (uint)local_1a8[0];
    local_bc = 0;
    local_b0 = 2;
    local_a8 = L"-";
    local_a0 = 0;
    local_90 = 2;
    local_88 = L"-";
    local_80 = 2;
    local_60 = 2;
    local_58 = lVar13;
    local_4c = 0;
    local_1d0[0] = local_1e4[0];
    local_50 = local_c0;
    iVar3 = AiQueryUserSid(param_8,(longlong *)&local_1b8);
    if (iVar3 < 0) {
LAB_140028388:
      puVar8 = local_1b8;
    }
    else {
      iVar3 = AiQueryLogonId(param_8,&local_1b0);
      puVar8 = local_1b8;
      if (iVar3 < 0) goto LAB_140028388;
      local_f0 = RtlLengthSid(*local_1b8);
      local_f8 = *puVar8;
      local_e8 = &param_9;
      local_78 = &local_1b0;
      local_ec = 0;
      local_e0 = 4;
      local_70 = 8;
      iVar3 = AiQueryTokenAttributes(param_8,&local_1c0);
      lVar10 = local_1c0;
      if (-1 < iVar3) {
        uVar11 = 0;
        lVar7 = *(longlong *)(local_1c0 + 8);
        if (*(int *)(local_1c0 + 4) != 0) {
          do {
            cVar2 = RtlEqualUnicodeString(lVar7,&DAT_1400084b0,1);
            if (cVar2 == '\0') {
              cVar2 = RtlEqualUnicodeString(lVar7,&DAT_1400084a0,1);
              if (cVar2 == '\0') {
                cVar2 = RtlEqualUnicodeString(lVar7,&DAT_140008490,1);
                if (((cVar2 != '\0') && (*(short *)(lVar7 + 0x10) == 4)) &&
                   (*(int *)(lVar7 + 0x18) == 1)) {
                  uVar1 = *(ushort *)(*(longlong *)(lVar7 + 0x20) + 8);
                  if ((ushort)(uVar1 - 1) < 0xffcd) {
                    local_1e8[0] = uVar1 >> 1;
                    _Dst = (wchar_t *)
                           AiAlloc((ulonglong)*(ushort *)(*(longlong *)(lVar7 + 0x20) + 8) + 0x32);
                    if (_Dst == (wchar_t *)0x0) {
                      iVar3 = -0x3fffffe9;
                      goto LAB_14002838d;
                    }
                    memmove(_Dst,*(void **)(*(longlong *)(lVar7 + 0x20) + 0x10),
                            (ulonglong)*(ushort *)(*(longlong *)(lVar7 + 0x20) + 8));
                    RtlStringCbPrintfW((ushort *)(_Dst + local_1e8[0]),0x32,
                                       (ushort *)L"\\%u.%u.%u.%02u",
                                       **(ulonglong **)(lVar7 + 0x20) >> 0x30);
                    lVar5 = -1;
                    do {
                      lVar5 = lVar5 + 1;
                    } while (_Dst[(ulonglong)local_1e8[0] + lVar5] != L'\0');
                    local_1e8[0] = local_1e8[0] + (short)lVar5;
                    local_90 = 2;
                    local_98 = local_1e8;
                    local_80 = (ulonglong)((uint)local_1e8[0] * 2);
                    local_88 = _Dst;
                  }
                }
              }
              else if ((*(short *)(lVar7 + 0x10) == 0x10) && (*(int *)(lVar7 + 0x18) == 1)) {
                local_1e0[0] = *(undefined2 *)(*(longlong *)(lVar7 + 0x20) + 8);
                local_b8 = local_1e0;
                local_b0 = 2;
                local_a8 = (wchar_t *)**(undefined8 **)(lVar7 + 0x20);
                local_a0 = (ulonglong)*(uint *)(*(undefined8 **)(lVar7 + 0x20) + 1);
              }
            }
            else if ((*(short *)(lVar7 + 0x10) == 3) && (*(int *)(lVar7 + 0x18) != 0)) {
              local_d8 = local_1e4;
              local_d0 = 2;
              local_1e4[0] = **(ushort **)(lVar7 + 0x20) >> 1;
              local_c8 = *(longlong *)(*(ushort **)(lVar7 + 0x20) + 4);
              local_c0 = (uint)**(ushort **)(lVar7 + 0x20);
              local_bc = 0;
            }
            uVar11 = uVar11 + 1;
            lVar7 = lVar7 + 0x28;
          } while (uVar11 < *(uint *)(lVar10 + 4));
        }
        iVar3 = EtwWrite(local_180,local_188,0,0x12);
        if (-1 < iVar3) goto LAB_1400283d1;
      }
    }
LAB_14002838d:
    param_7 = local_1c8;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) != 0)) {
    WPP_SF_ZD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
              &WPP_ba82aeedd69c3fe8448d5535e4644288_Traceguids,param_7,(char)iVar3);
  }
LAB_1400283d1:
  if (puVar8 != (undefined8 *)0x0) {
    ExFreePoolWithTag(puVar8,0);
  }
  if (lVar10 != 0) {
    ExFreePoolWithTag(lVar10,0);
  }
  if (_Dst != (wchar_t *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
  if ((lVar13 != *(longlong *)(local_1c8 + 4)) && (lVar13 != 0)) {
    ExFreePoolWithTag(lVar13,0);
  }
  return;
}



===== AiLogStatusEvent @ 140028468 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AiLogStatusEvent(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_58 [32];
  undefined4 local_28 [2];
  undefined4 *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_20 = local_28;
  local_14 = 0;
  uVar2 = 0;
  local_18 = 4;
  local_28[0] = param_3;
  iVar1 = EtwWrite(param_1,&AppIdDriverFailed,0,1);
  if (((iVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
              (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),uVar2,local_28[0],(char)iVar1);
  }
  return;
}



===== AiLogTriggerServiceStartEvent @ 140028508 =====

void AiLogTriggerServiceStartEvent(void)

{
  int iVar1;
  undefined8 local_res8 [4];
  
  local_res8[0] = 0;
  iVar1 = EtwRegister(&AppIdServiceTriggerEventProviderId,0,0,local_res8);
  if (-1 < iVar1) {
    iVar1 = EtwWrite(local_res8[0],&AppIdStartServiceEvent,0,0,0);
    EtwUnregister(local_res8[0]);
    if (-1 < iVar1) {
      return;
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_ba82aeedd69c3fe8448d5535e4644288_Traceguids,iVar1);
  }
  return;
}



===== AipGUIDFromString @ 1400285b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AipGUIDFromString(short *param_1)

{
  undefined8 *puVar1;
  undefined1 auStack_98 [32];
  undefined8 local_78;
  undefined2 *puStack_70;
  undefined2 local_68;
  undefined8 local_66;
  undefined8 uStack_5e;
  undefined8 local_56;
  undefined8 uStack_4e;
  undefined8 local_46;
  undefined8 uStack_3e;
  undefined8 local_36;
  undefined8 uStack_2e;
  undefined8 local_26;
  undefined2 local_1e;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  if (*param_1 == 0x48) {
    local_68 = 0x7b;
    puVar1 = *(undefined8 **)(param_1 + 4);
    local_66 = *puVar1;
    uStack_5e = puVar1[1];
    local_56 = puVar1[2];
    uStack_4e = puVar1[3];
    local_46 = puVar1[4];
    uStack_3e = puVar1[5];
    local_36 = puVar1[6];
    uStack_2e = puVar1[7];
    local_26 = puVar1[8];
    local_1e = 0x7d;
    puStack_70 = &local_68;
    local_78 = 0x4c004c;
  }
  else {
    local_78 = *(undefined8 *)param_1;
    puStack_70 = *(undefined2 **)(param_1 + 4);
  }
  RtlGUIDFromString(&local_78);
  return;
}



===== AipNtPathToDosPath @ 140028664 =====

undefined8 AipNtPathToDosPath(ushort *param_1,ushort *param_2)

{
  char cVar1;
  short sVar2;
  ushort uVar3;
  void *_Dst;
  undefined8 uVar4;
  ushort *puVar5;
  ushort *puVar6;
  
  puVar5 = &DAT_140008480;
  uVar4 = 0;
  cVar1 = RtlPrefixUnicodeString(&DAT_140008480,param_1,1);
  if (cVar1 == '\0') {
    puVar5 = (ushort *)&DAT_140008460;
    cVar1 = RtlPrefixUnicodeString(&DAT_140008460,param_1,1);
    if (cVar1 == '\0') {
      uVar4 = *(undefined8 *)(param_1 + 4);
      *(undefined8 *)param_2 = *(undefined8 *)param_1;
      *(undefined8 *)(param_2 + 4) = uVar4;
      return 0;
    }
    puVar6 = (ushort *)&DAT_140008450;
    sVar2 = -8;
  }
  else {
    puVar6 = &DAT_140008470;
    sVar2 = -0xc;
  }
  uVar3 = sVar2 + *param_1;
  *param_2 = uVar3;
  param_2[1] = uVar3;
  if (uVar3 == 0) {
    uVar4 = 0xc000000d;
  }
  else {
    _Dst = (void *)AiAlloc((ulonglong)uVar3);
    *(void **)(param_2 + 4) = _Dst;
    if (_Dst == (void *)0x0) {
      uVar4 = 0xc0000017;
    }
    else {
      memmove(_Dst,*(void **)(puVar6 + 4),(ulonglong)*puVar6);
      memmove((void *)((longlong)_Dst + (ulonglong)(*puVar6 >> 1) * 2),
              (void *)(*(longlong *)(param_1 + 4) + (ulonglong)(*puVar5 >> 1) * 2),
              (ulonglong)*param_1 - (ulonglong)*puVar5);
    }
  }
  return uVar4;
}



===== AiAlloc @ 140028770 =====

undefined8 AiAlloc(ulonglong param_1)

{
  undefined8 uVar1;
  
  if (param_1 < 0x100000000) {
    uVar1 = ExAllocatePool2(0x102,param_1,0x44497041);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



===== AiFree @ 1400287b0 =====

void __stdcall AiFree(void *param_1)

{
  if (param_1 != (void *)0x0) {
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== AiFreeLib @ 1400287d4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void AiFreeLib(void)

{
  undefined8 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined8 *puVar4;
  longlong lVar5;
  longlong lVar6;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  AipkFreeAppxInMemoryCache();
  local_34 = 0;
  local_1c = 0;
  if (AipAppxRegCacheInitialized != '\0') {
    local_38 = 0x30;
    local_28 = &DAT_1400086b0;
    local_18 = 0;
    uStack_10 = 0;
    local_30 = 0;
    local_20 = 0x240;
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(&AipAppxRegCache,0);
    if (DAT_1400184a0 != '\0') {
      iVar2 = ZwUnloadKeyEx(&local_38,0);
      if (-1 < iVar2) {
        DAT_1400184a0 = '\0';
      }
    }
    ExReleasePushLockExclusiveEx(&AipAppxRegCache,0);
    KeLeaveCriticalRegion();
  }
  lVar5 = 2;
  if (AppHashAlgInitialized != 0) {
    puVar4 = &AppHashAlgHandle;
    lVar6 = 2;
    do {
      if ((BCRYPT_ALG_HANDLE)*puVar4 != (BCRYPT_ALG_HANDLE)0x0) {
        BCryptCloseAlgorithmProvider((BCRYPT_ALG_HANDLE)*puVar4,0);
        *puVar4 = 0;
      }
      puVar4 = puVar4 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
    AppHashAlgInitialized = 0;
  }
  if (DAT_140018358 != 0) {
    ZwAlertThread();
    ZwWaitForSingleObject(DAT_140018358,0,0);
    ZwClose(DAT_140018358);
  }
  if (DAT_140018350 != 0) {
    ZwClose();
  }
  AiFreeCertStore();
  if (AipPathMacroListInitialized != 0) {
    puVar4 = DAT_1400185d8;
    while ((undefined8 **)puVar4 != &DAT_1400185d8) {
      puVar1 = (undefined8 *)*puVar4;
      if (((*(uint *)(puVar4 + 2) & 1) != 0) && (puVar4[4] != 0)) {
        ExFreePoolWithTag(puVar4[4],0);
      }
      if (((*(uint *)(puVar4 + 2) & 2) != 0) && (puVar4[6] != 0)) {
        ExFreePoolWithTag();
      }
      ExFreePoolWithTag(puVar4);
      puVar4 = puVar1;
    }
    _DAT_1400185e0 = &DAT_1400185d8;
    puVar3 = &DAT_140018058;
    DAT_1400185d8 = &DAT_1400185d8;
    AipPathMacroListInitialized = 0;
    do {
      *puVar3 = 0;
      puVar3 = puVar3 + 8;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    AipPathMacroList = 0;
    if ((DAT_1400185c0 != 0) && (DAT_1400185c0 != DAT_1400185b0)) {
      if (DAT_1400185c0 != 0) {
        ExFreePoolWithTag(DAT_1400185c0,0);
      }
      DAT_1400185c0 = 0;
    }
  }
  return;
}



===== AiInitializeConfiguration @ 140028a30 =====

void AiInitializeConfiguration(undefined8 param_1)

{
  int iVar1;
  int local_res8 [8];
  undefined8 local_38;
  wchar_t *local_30;
  undefined8 local_28;
  wchar_t *local_20;
  undefined8 local_18;
  wchar_t *local_10;
  
  local_res8[0] = 0;
  local_30 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\AppID\\Configuration";
  local_38 = 0x8e008c;
  local_20 = L"UsePublisherId";
  local_28 = 0x1e001c;
  local_10 = L"UseSystemIdentityOnly";
  local_18 = 0x2c002a;
  iVar1 = AiRegReadDwordValue(param_1,&local_38,&local_28,local_res8);
  AiEnablePublisherId = 0;
  if ((-1 < iVar1) && (local_res8[0] == 1)) {
    AiEnablePublisherId = 1;
  }
  iVar1 = AiRegReadDwordValue(param_1,&local_38,&local_18,local_res8);
  if ((-1 < iVar1) && (local_res8[0] == 1)) {
    AiUseSystemAppIdentityOnly = 1;
  }
  return;
}



===== AiReadFile @ 140028ad0 =====

ulonglong AiReadFile(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  ulonglong uVar1;
  undefined8 local_28;
  ulonglong local_20 [3];
  
  local_28 = 0;
  local_20[0] = 0;
  local_20[1] = 0;
  uVar1 = ZwReadFile(0,0,0,0,local_20,param_3,param_4,&local_28,0);
  if ((int)uVar1 == 0x103) {
    ZwWaitForSingleObject(param_1,0,0);
    uVar1 = local_20[0] & 0xffffffff;
  }
  return uVar1;
}



===== AiAllocCertName @ 140028b50 =====

void AiAllocCertName(uint param_1)

{
  AiAlloc((ulonglong)param_1);
  return;
}



===== AiFreeCertStore @ 140028b68 =====

void AiFreeCertStore(void)

{
  ulonglong uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  if (AipCertificateStoreInitialized != 0) {
    puVar4 = AipCertificateStore;
    if (AipCertificateStore != (undefined8 *)0x0) {
      do {
        while ((undefined8 *)*puVar4 != (undefined8 *)0x0) {
          puVar3 = puVar4;
          puVar2 = (undefined8 *)*puVar4;
LAB_140028b9c:
          puVar4 = puVar2;
          *puVar3 = 0;
        }
        puVar3 = puVar4 + 1;
        puVar2 = (undefined8 *)*puVar3;
        if ((undefined8 *)*puVar3 != (undefined8 *)0x0) goto LAB_140028b9c;
        uVar1 = puVar4[2];
        AipCertDeleteRoutine((longlong)puVar4);
        puVar4 = (undefined8 *)(uVar1 & 0xfffffffffffffffc);
      } while (puVar4 != (undefined8 *)0x0);
    }
    AipCertificateStore = (undefined8 *)0x0;
    AipCertificateStoreInitialized = 0;
  }
  return;
}



===== AiGetTrustedPublisherName @ 140028bd8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong AiGetTrustedPublisherName
                    (undefined8 param_1,undefined8 param_2,undefined8 param_3,int param_4,
                    ushort *param_5)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined1 auStackY_208 [32];
  char local_1b8 [8];
  ulonglong local_1b0;
  ulonglong local_1a8;
  undefined4 local_1a0;
  undefined4 local_19c;
  ulonglong local_198 [2];
  undefined8 local_188;
  longlong lStack_180;
  undefined8 local_178;
  longlong lStack_170;
  undefined8 local_168;
  longlong lStack_160;
  int local_158 [4];
  longlong local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  int local_128 [4];
  longlong local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8 [4];
  ulonglong *local_d8;
  undefined8 local_d0;
  ulonglong *local_c8;
  undefined8 local_c0;
  uint *local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  uint local_a0 [2];
  ulonglong *local_98;
  undefined8 local_90;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_208;
  local_19c = 0x40;
  local_198[0] = 0;
  local_1a0 = 0;
  local_158[0] = 0;
  local_158[1] = 0;
  local_158[2] = 0;
  local_158[3] = 0;
  local_148 = 0;
  uStack_140 = 0;
  local_138 = 0;
  uStack_130 = 0;
  local_128[0] = 0;
  local_128[1] = 0;
  local_128[2] = 0;
  local_128[3] = 0;
  local_118 = 0;
  uStack_110 = 0;
  local_108 = 0;
  uStack_100 = 0;
  local_188 = 0;
  lStack_180 = 0;
  local_178 = 0;
  lStack_170 = 0;
  local_168 = 0;
  lStack_160 = 0;
  iVar2 = CiValidateFileObject(param_2,0,0,local_158);
  bVar1 = true;
  if (-1 < iVar2) {
    local_1a8 = local_198[0];
    if (local_198[0] == 0) {
LAB_140028db3:
      local_1a8 = _DAT_fffff78000000014;
    }
    else {
      uVar5 = AipGetTrustedPublisherName(local_128,&local_1a8,0,(undefined4 *)&local_1b0);
      if ((int)uVar5 < 0) {
        local_1b0 = (ulonglong)Feature_Servicing_ApplockerDeadlock_37068202__private_featureState;
        if ((Feature_Servicing_ApplockerDeadlock_37068202__private_featureState & 0x10) == 0) {
          local_1b0 = (ulonglong)
                      (Feature_Servicing_ApplockerDeadlock_37068202__private_featureState | 1);
          wil_details_FeatureReporting_ReportUsageToService(0x140017270,local_1b0,3,1);
          wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath
                    ((uint)local_1b0,3,
                     &Feature_Servicing_ApplockerDeadlock_37068202__private_descriptor);
        }
        if ((((local_128[0] != 0) && (local_118 != 0)) && (*(int *)(local_118 + 0x10) != 0)) &&
           ((*(int *)(local_118 + 0x30) != 0 &&
            (*(longlong *)(*(longlong *)(local_118 + 0x28) + 0x70) != 0)))) {
          iVar2 = CiGetCertPublisherName(*(longlong *)(local_118 + 0x28) + 0x68,AiAllocCertName);
          if (-1 < iVar2) {
            RtlUpcaseUnicodeString(param_5);
            uVar5 = AipGetTrustedPublisherName(local_128,(ulonglong *)0x0,0,(undefined4 *)0x0);
            if ((int)uVar5 < 0) {
              AipAddCertPolicyInfo((longlong)local_128,(longlong)param_5,'\x01');
            }
          }
        }
      }
      if (local_1a8 == 0) goto LAB_140028db3;
    }
    uVar6 = AipGetTrustedPublisherName
                      (local_158,&local_1a8,(longlong)param_5,(undefined4 *)&local_1b0);
    uVar7 = uVar6 & 0xffffffff;
    local_1b0 = (ulonglong)Feature_Servicing_ApplockerDeadlock_37068202__private_featureState;
    if ((Feature_Servicing_ApplockerDeadlock_37068202__private_featureState & 0x10) == 0) {
      local_1b0 = (ulonglong)
                  (Feature_Servicing_ApplockerDeadlock_37068202__private_featureState | 1);
      wil_details_FeatureReporting_ReportUsageToService(0x140017270,local_1b0,3,1);
      wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath
                ((uint)local_1b0,3,&Feature_Servicing_ApplockerDeadlock_37068202__private_descriptor
                );
    }
    if ((int)uVar6 < 0) {
      if (((local_158[0] != 0) && (local_148 != 0)) &&
         ((*(int *)(local_148 + 0x30) != 0 &&
          (*(longlong *)(*(longlong *)(local_148 + 0x28) + 0x70) != 0)))) {
        uVar3 = CiGetCertPublisherName(*(longlong *)(local_148 + 0x28) + 0x68,AiAllocCertName);
        uVar7 = (ulonglong)uVar3;
        if (-1 < (int)uVar3) {
          RtlUpcaseUnicodeString(param_5);
          if (*(int *)(local_148 + 0x10) != 0) {
            uVar5 = AipGetTrustedPublisherName(local_158,(ulonglong *)0x0,0,(undefined4 *)0x0);
            if ((int)uVar5 < 0) {
              AipAddCertPolicyInfo((longlong)local_158,(longlong)param_5,'\0');
            }
          }
          goto LAB_140028eca;
        }
      }
    }
    else {
LAB_140028eca:
      if (param_4 == 0) goto LAB_14002900f;
      AipSetTrustedPublisherNameInCache
                (param_2,(longlong)local_158,(longlong *)local_198,(longlong)local_128,
                 (longlong *)0x0);
      if (-1 < (int)uVar7) goto LAB_14002900f;
    }
  }
  local_1b8[0] = '\0';
  uVar3 = AipGetTrustedPublisherNameFromService
                    (param_1,(longlong)&local_188,(longlong)param_5,local_1b8);
  uVar7 = (ulonglong)uVar3;
  if ((param_4 != 0) && ((-1 < (int)uVar3 || ((local_1b8[0] != '\0' && (uVar3 == 0xfffffffe)))))) {
    uVar4 = AipSetServicePublisherInfoInCache(param_2,(undefined4 *)&local_188);
    if (((int)local_188 == 0) && ((lStack_160 == 0 && (4 < DAT_140018000)))) {
      if (((_DAT_140018010 & 0x400000000000) == 0) ||
         ((DAT_140018018 & 0x400000000000) != DAT_140018018)) {
        bVar1 = false;
      }
      if (bVar1) {
        local_d8 = &local_1a8;
        local_1b0 = CONCAT44(local_1b0._4_4_,uVar4);
        local_c8 = &local_1b0;
        local_1a8 = CONCAT44(local_1a8._4_4_,uVar3);
        local_b8 = local_a0;
        local_a8 = *(undefined8 *)(param_5 + 4);
        local_a0[0] = (uint)*param_5;
        local_98 = local_198 + 1;
        local_d0 = 4;
        local_c0 = 4;
        local_b0 = 2;
        local_a0[1] = 0;
        local_198[1] = 0x2000000;
        local_90 = 8;
        _tlgWriteTransfer_EtwWriteTransfer(param_2,&DAT_1400150c1,4,0x400000000000,7,local_f8);
      }
    }
  }
LAB_14002900f:
  if (lStack_180 != 0) {
    ExFreePoolWithTag(lStack_180,0);
    lStack_180 = 0;
  }
  if (lStack_170 != 0) {
    ExFreePoolWithTag(lStack_170,0);
    lStack_170 = 0;
  }
  local_168 = 0;
  CiFreePolicyInfo(local_158);
  CiFreePolicyInfo(local_128);
  return uVar7;
}



===== AiGetTrustedPublisherNameFromCache @ 14002909c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
AiGetTrustedPublisherNameFromCache
          (longlong param_1,uint param_2,undefined1 *param_3,longlong param_4)

{
  ushort uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined1 auStack_1c8 [32];
  ulonglong local_1a8;
  uint local_1a0 [2];
  longlong local_198;
  uint local_190 [2];
  longlong local_188;
  int local_180 [4];
  undefined4 *local_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  int local_150 [4];
  undefined4 *local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined4 local_118;
  undefined4 local_114;
  uint *local_110;
  undefined4 local_108;
  undefined4 local_a8;
  undefined4 local_a4;
  uint *local_a0;
  undefined4 local_98;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_1c8;
  local_114 = 0;
  local_1a0[1] = 0;
  local_a4 = 0;
  local_190[1] = 0;
  if (((0x47 < param_2) && (*param_3 = 0, *(int *)(param_1 + 0x28) == 0x33444941)) &&
     (param_2 == *(ushort *)(param_1 + 0x30) + 0x48 + (uint)*(ushort *)(param_1 + 0x32))) {
    uVar3 = 0;
    if (*(longlong *)(param_1 + 0x40) != 0) {
      ExAcquirePushLockSharedEx(&DAT_140018348);
      uVar2 = DAT_140018340;
      ExReleasePushLockSharedEx(&DAT_140018348);
      uVar3 = *(ulonglong *)(param_1 + 0x40);
      if (uVar3 < uVar2) {
        return 0xfffffffe;
      }
    }
    uVar1 = *(ushort *)(param_1 + 0x30);
    if (uVar1 != 0) {
      local_140 = &local_118;
      local_150[2] = 0;
      local_150[3] = 0;
      uStack_138 = 0;
      local_150[0] = 0x30;
      local_150[1] = 0;
      local_130 = 0;
      uStack_128 = 0;
      memset(&local_118,0,0x68);
      local_118 = 0x68;
      local_110 = local_1a0;
      local_108 = 1;
      local_198 = param_1 + 0x48;
      local_1a0[0] = (uint)uVar1;
      local_170 = &local_a8;
      local_180[2] = 0;
      local_180[3] = 0;
      local_180[0] = 0x30;
      local_180[1] = 0;
      uStack_168 = 0;
      local_160 = 0;
      uStack_158 = 0;
      memset(&local_a8,0,0x68);
      local_a0 = local_190;
      local_a8 = 0x68;
      local_188 = param_1 + 0x48 + (ulonglong)uVar1;
      local_190[0] = (uint)*(ushort *)(param_1 + 0x32);
      local_1a8 = *(ulonglong *)(param_1 + 0x38);
      local_98 = 1;
      if ((local_1a8 == 0) ||
         (uVar4 = AipGetTrustedPublisherName(local_180,&local_1a8,0,(undefined4 *)0x0),
         (int)uVar4 < 0)) {
        local_1a8 = _DAT_fffff78000000014;
      }
      uVar4 = AipGetTrustedPublisherName(local_150,&local_1a8,param_4,(undefined4 *)0x0);
      if ((int)uVar4 < 0) {
        return uVar4;
      }
      *param_3 = 1;
      return uVar4;
    }
    if (uVar3 != 0) {
      *param_3 = 1;
    }
  }
  return 0xfffffffe;
}



===== AiReloadCertificate @ 1400292a4 =====

int AiReloadCertificate(ushort *param_1,uint param_2)

{
  ushort uVar1;
  undefined8 *puVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  bool bVar8;
  ulonglong local_res18;
  undefined8 local_res20;
  undefined8 local_38;
  ushort *puStack_30;
  
  local_res20 = 0;
  local_38 = 0;
  puStack_30 = (ushort *)0x0;
  if ((((param_2 < 2) || (uVar1 = *param_1, uVar1 == 0)) || ((uVar1 & 1) != 0)) ||
     ((uint)uVar1 != param_2 - 2)) {
    iVar4 = -0x3ffffff3;
  }
  else {
    puStack_30 = param_1 + 1;
    local_38 = (ulonglong)CONCAT22(uVar1,uVar1);
    if ((Feature_Servicing_ApplockerDeadlock_37068202__private_featureState & 0x10) == 0) {
      uVar5 = Feature_Servicing_ApplockerDeadlock_37068202__private_featureState | 1;
      local_res18 = (ulonglong)uVar5;
      wil_details_FeatureReporting_ReportUsageToService(0x140017270,local_res18,3,1);
      wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath
                (uVar5,3,&Feature_Servicing_ApplockerDeadlock_37068202__private_descriptor);
    }
    iVar4 = AiRegOpenKey(0,&DAT_1400085b0,0x20019,&local_res20);
    if (iVar4 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                 &WPP_b7d6d7747cbe39158d21f26ad040a04c_Traceguids,iVar4);
      }
    }
    else {
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(&DAT_1400185f8,0);
      puVar2 = AipCertificateStore;
      puVar7 = (undefined8 *)0x0;
      while (puVar6 = puVar2, puVar6 != (undefined8 *)0x0) {
        puVar7 = puVar6;
        puVar2 = (undefined8 *)*puVar6;
      }
LAB_14002943b:
      if (puVar7 != (undefined8 *)0x0) {
        cVar3 = RtlEqualUnicodeString(&local_38,puVar7 + 3,1);
        if (cVar3 != '\0') {
          RtlAvlRemoveNode(&AipCertificateStore,puVar7);
          AipFreeCert((longlong)puVar7);
          goto LAB_140029460;
        }
        puVar2 = (undefined8 *)puVar7[1];
        puVar6 = puVar7;
        if (puVar2 == (undefined8 *)0x0) {
          do {
            puVar7 = (undefined8 *)(puVar6[2] & 0xfffffffffffffffc);
            if (puVar7 == (undefined8 *)0x0) break;
            bVar8 = (undefined8 *)*puVar7 != puVar6;
            puVar6 = puVar7;
          } while (bVar8);
        }
        else {
          puVar7 = puVar2;
          for (puVar2 = (undefined8 *)*puVar2; puVar2 != (undefined8 *)0x0;
              puVar2 = (undefined8 *)*puVar2) {
            puVar7 = puVar2;
          }
        }
        goto LAB_14002943b;
      }
LAB_140029460:
      if ((Feature_Servicing_ApplockerDeadlock_37068202__private_featureState & 0x10) == 0) {
        uVar5 = Feature_Servicing_ApplockerDeadlock_37068202__private_featureState | 1;
        local_res18 = (ulonglong)uVar5;
        wil_details_FeatureReporting_ReportUsageToService(0x140017270,local_res18,3,1);
        wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath
                  (uVar5,3,&Feature_Servicing_ApplockerDeadlock_37068202__private_descriptor);
      }
      iVar4 = AipAddCertFromCertStore(local_res20,(wchar_t *)&local_38);
      ExReleasePushLockExclusiveEx(&DAT_1400185f8,0);
      KeLeaveCriticalRegion();
    }
  }
  if ((Feature_Servicing_ApplockerDeadlock_37068202__private_featureState & 0x10) == 0) {
    uVar5 = Feature_Servicing_ApplockerDeadlock_37068202__private_featureState | 1;
    local_res18 = (ulonglong)uVar5;
    wil_details_FeatureReporting_ReportUsageToService(0x140017270,local_res18,3,1);
    wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath
              (uVar5,3,&Feature_Servicing_ApplockerDeadlock_37068202__private_descriptor);
  }
  ZwClose(local_res20);
  return iVar4;
}



===== AiServiceStarted @ 140029544 =====

int AiServiceStarted(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&AipServiceContext,0);
  if (DAT_140018608 != 0) {
    iVar2 = -0x3ffffff3;
    goto LAB_1400296c8;
  }
  iVar2 = 0;
  DAT_140018608 = 0;
  iVar1 = RpcBindingCreateW(&DAT_14000c640,&DAT_140008b40,&DAT_14000c978,&DAT_140018608);
  if (iVar1 == 0) {
    iVar1 = RpcBindingBind(0,DAT_140018608,&DAT_140008c20);
    if (iVar1 != 0) goto LAB_1400295db;
  }
  else {
LAB_1400295db:
    iVar2 = -0x3fffffff;
    if (DAT_140018608 != 0) {
      RpcBindingFree((RPC_BINDING_HANDLE *)&DAT_140018608);
      DAT_140018608 = 0;
    }
  }
  if (-1 < iVar2) {
    uVar3 = PsGetCurrentProcessId();
    iVar2 = PsLookupProcessByProcessId(uVar3,&DAT_140018610);
    if (iVar2 < 0) {
      AiRpcDisconnect((RPC_BINDING_HANDLE *)&DAT_140018608);
      DAT_140018608 = 0;
    }
    else {
      iVar2 = ObOpenObjectByPointer
                        (DAT_140018610,0x200,0,0x1fffff,*(undefined8 *)PsProcessType_exref,0,
                         &DAT_140018618);
      if (iVar2 < 0) {
        ObfDereferenceObject(DAT_140018610);
        DAT_140018610 = 0;
        AiRpcDisconnect((RPC_BINDING_HANDLE *)&DAT_140018608);
        DAT_140018608 = 0;
      }
      DAT_140018620 = param_1;
    }
  }
LAB_1400296c8:
  ExReleasePushLockExclusiveEx(&AipServiceContext,0);
  KeLeaveCriticalRegion();
  return iVar2;
}



===== AiServiceStopped @ 140029700 =====

ulonglong AiServiceStopped(longlong param_1)

{
  ulonglong uVar1;
  
  uVar1 = 0;
  if (AipServiceContextInitialized != 0) {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(&AipServiceContext,0);
    if ((param_1 == 0) || (param_1 == DAT_140018620)) {
      DAT_140018620 = 0;
      if (DAT_140018608 != 0) {
        uVar1 = AiRpcDisconnect((RPC_BINDING_HANDLE *)&DAT_140018608);
        DAT_140018608 = 0;
        uVar1 = uVar1 & 0xffffffff;
      }
      if (DAT_140018610 != 0) {
        ObfDereferenceObject();
        DAT_140018610 = 0;
      }
      if (DAT_140018618 != 0) {
        ZwClose();
        DAT_140018618 = 0;
      }
    }
    else {
      uVar1 = 0xc000000d;
    }
    ExReleasePushLockExclusiveEx(&AipServiceContext,0);
    KeLeaveCriticalRegion();
  }
  return uVar1;
}



===== AiSetSigningLevelCache @ 1400297ec =====

undefined4 AiSetSigningLevelCache(undefined8 param_1,undefined8 param_2)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 *puVar4;
  uint local_res10 [2];
  
  local_res10[0] = 0;
  puVar4 = (undefined8 *)AiAlloc(0x1000);
  if (puVar4 == (undefined8 *)0x0) {
    uVar3 = 0xc0000017;
  }
  else {
    iVar2 = AiGetPublisherCache(param_1,param_2,(longlong)puVar4,local_res10);
    if (iVar2 < 0) {
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[2] = 0;
      puVar4[3] = 0;
      puVar4[4] = 0;
      puVar4[5] = 0;
      *(undefined1 *)((longlong)puVar4 + 5) = 0x1e;
      *(undefined2 *)((longlong)puVar4 + 6) = 9;
      pcVar1 = (char *)(puVar4 + 1);
      pcVar1[0] = '$';
      pcVar1[1] = 'K';
      pcVar1[2] = 'E';
      pcVar1[3] = 'R';
      pcVar1[4] = 'N';
      pcVar1[5] = 'E';
      pcVar1[6] = 'L';
      pcVar1[7] = '.';
      pcVar1 = (char *)(puVar4 + 2);
      pcVar1[0] = 'P';
      pcVar1[1] = 'U';
      pcVar1[2] = 'R';
      pcVar1[3] = 'G';
      pcVar1[4] = 'E';
      pcVar1[5] = '.';
      pcVar1[6] = 'A';
      pcVar1[7] = 'P';
      puVar4[3] = 0x4e4749532e444950;
      *(undefined4 *)(puVar4 + 4) = 0x4e495245;
      *(undefined2 *)((longlong)puVar4 + 0x24) = 0x4f46;
      *(undefined1 *)((longlong)puVar4 + 0x26) = 0;
      *(undefined4 *)(puVar4 + 5) = 0x33444941;
    }
    *(uint *)((longlong)puVar4 + 0x2c) = *(uint *)((longlong)puVar4 + 0x2c) | 1;
    uVar3 = FsRtlSetKernelEaFile
                      (param_1,puVar4,
                       (uint)*(ushort *)((longlong)puVar4 + 6) + *(byte *)((longlong)puVar4 + 5) + 9
                      );
    ExFreePoolWithTag(puVar4,0);
  }
  return uVar3;
}



===== AiSigningLevelCacheExists @ 1400298d8 =====

int AiSigningLevelCacheExists(undefined8 param_1,undefined1 *param_2)

{
  int iVar1;
  longlong lVar2;
  undefined1 *puVar3;
  uint local_res10 [2];
  
  local_res10[0] = 0;
  *param_2 = 0;
  puVar3 = param_2;
  lVar2 = AiAlloc(0x1000);
  if (lVar2 == 0) {
    iVar1 = -0x3fffffe9;
  }
  else {
    iVar1 = AiGetPublisherCache(param_1,puVar3,lVar2,local_res10);
    if ((-1 < iVar1) && ((*(uint *)(lVar2 + 0x2c) & 1) != 0)) {
      *param_2 = 1;
    }
    ExFreePoolWithTag(lVar2,0);
  }
  return iVar1;
}



===== AipAddCertFromCertStore @ 14002995c =====

int AipAddCertFromCertStore(undefined8 param_1,wchar_t *param_2)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  void *_Dst;
  longlong lVar6;
  void *pvVar7;
  longlong *plVar8;
  undefined8 uVar9;
  longlong *plVar10;
  uint uVar11;
  uint local_res18 [2];
  longlong local_res20;
  
  local_res20 = 0;
  _Dst = (void *)0x0;
  local_res18[0] = 0;
  iVar3 = AiRegOpenKey(param_1,param_2,0x20019,&local_res20);
  if (iVar3 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) {
      WPP_SF_ZD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_b7d6d7747cbe39158d21f26ad040a04c_Traceguids,param_2,(char)iVar3);
    }
    goto LAB_140029e6e;
  }
  uVar11 = 0x210;
  lVar5 = AiAlloc(0x210);
  if (lVar5 == 0) {
LAB_1400299f2:
    iVar3 = -0x3fffffe9;
    goto LAB_140029e6e;
  }
  _Dst = (void *)ExAllocatePool2(0x102,0x68,0x44497041);
  if (_Dst == (void *)0x0) {
LAB_140029a22:
    iVar3 = -0x3fffffe9;
  }
  else {
    memset(_Dst,0,0x68);
    *(wchar_t *)((longlong)_Dst + 0x1a) = param_2[1];
    lVar6 = AiAlloc((ulonglong)(ushort)param_2[1]);
    *(longlong *)((longlong)_Dst + 0x20) = lVar6;
    if (lVar6 == 0) goto LAB_140029a22;
    RtlCopyUnicodeString((longlong)_Dst + 0x18,param_2);
    iVar3 = ZwQueryValueKey(local_res20,&DAT_1400085a0,2,lVar5,0x210,local_res18);
    if (-1 < iVar3) {
      if ((*(int *)(lVar5 + 4) == 0xb) && (*(int *)(lVar5 + 8) == 8)) {
        *(undefined8 *)((longlong)_Dst + 0x50) = *(undefined8 *)(lVar5 + 0xc);
        iVar3 = ZwQueryValueKey(local_res20,&DAT_140008590,2,lVar5,0x210,local_res18);
        if (-1 < iVar3) {
          if ((*(int *)(lVar5 + 4) != 0xb) || (*(int *)(lVar5 + 8) != 8)) goto LAB_140029e58;
          *(undefined8 *)((longlong)_Dst + 0x48) = *(undefined8 *)(lVar5 + 0xc);
          iVar3 = ZwQueryValueKey(local_res20,&DAT_140008580,2,lVar5,0x210,local_res18);
          if (((-1 < iVar3) && (*(int *)(lVar5 + 4) == 4)) && (*(int *)(lVar5 + 8) == 4)) {
            *(undefined4 *)((longlong)_Dst + 0x58) = *(undefined4 *)(lVar5 + 0xc);
          }
          iVar3 = ZwQueryValueKey(local_res20,&DAT_140008570,2,lVar5,0x210,local_res18);
          if (((-1 < iVar3) && (*(int *)(lVar5 + 4) == 4)) && (*(int *)(lVar5 + 8) == 4)) {
            *(undefined4 *)((longlong)_Dst + 0x5c) = *(undefined4 *)(lVar5 + 0xc);
          }
          iVar3 = ZwQueryValueKey(local_res20,&DAT_140008560,2,lVar5,0x210,local_res18);
          if (((-1 < iVar3) && (*(int *)(lVar5 + 4) == 4)) && (*(int *)(lVar5 + 8) == 4)) {
            *(undefined4 *)((longlong)_Dst + 0x60) = *(undefined4 *)(lVar5 + 0xc);
          }
          iVar3 = ZwQueryValueKey(local_res20,&DAT_140008550,2,lVar5,0x210,local_res18);
          if (iVar3 == -0x7ffffffb) {
            ExFreePoolWithTag(lVar5,0);
            lVar5 = AiAlloc((ulonglong)local_res18[0]);
            uVar11 = local_res18[0];
            if (lVar5 == 0) goto LAB_1400299f2;
            iVar3 = ZwQueryValueKey(local_res20,&DAT_140008550,2,lVar5,local_res18[0],local_res18);
          }
          if (iVar3 < 0) {
            if (iVar3 != -0x3fffffcc) goto LAB_140029e5d;
LAB_140029cee:
            iVar3 = ZwQueryValueKey(local_res20,&DAT_140008540,2,lVar5,uVar11,local_res18);
            if (iVar3 == -0x7ffffffb) {
              ExFreePoolWithTag(lVar5,0);
              lVar5 = AiAlloc((ulonglong)local_res18[0]);
              if (lVar5 == 0) goto LAB_1400299f2;
              iVar3 = ZwQueryValueKey(local_res20,&DAT_140008540,2,lVar5,local_res18[0],local_res18)
              ;
            }
            if (iVar3 < 0) goto LAB_140029e5d;
            if (*(int *)(lVar5 + 4) == 3) {
              *(undefined4 *)((longlong)_Dst + 0x38) = *(undefined4 *)(lVar5 + 8);
              pvVar7 = (void *)AiAlloc((ulonglong)*(uint *)(lVar5 + 8));
              *(void **)((longlong)_Dst + 0x40) = pvVar7;
              if (pvVar7 != (void *)0x0) {
                memmove(pvVar7,(void *)(lVar5 + 0xc),(ulonglong)*(uint *)(lVar5 + 8));
                if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) {
                  WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                           &WPP_b7d6d7747cbe39158d21f26ad040a04c_Traceguids,
                           (wchar_t *)((longlong)_Dst + 0x28));
                }
                uVar9 = 0;
                plVar10 = AipCertificateStore;
                if (AipCertificateStore != (longlong *)0x0) {
                  uVar11 = *(uint *)((longlong)_Dst + 0x38);
                  do {
                    if ((uVar11 < *(uint *)(plVar10 + 7)) ||
                       ((uVar11 <= *(uint *)(plVar10 + 7) &&
                        (iVar4 = memcmp(*(void **)((longlong)_Dst + 0x40),(void *)plVar10[8],
                                        (ulonglong)uVar11), iVar4 < 0)))) {
                      plVar8 = (longlong *)*plVar10;
                      if (plVar8 == (longlong *)0x0) {
                        uVar9 = 0;
                        break;
                      }
                    }
                    else {
                      plVar8 = (longlong *)plVar10[1];
                      if (plVar8 == (longlong *)0x0) goto code_r0x000140029e1e;
                    }
                    plVar10 = plVar8;
                  } while( true );
                }
                goto LAB_140029e33;
              }
              goto LAB_140029a22;
            }
          }
          else if ((*(int *)(lVar5 + 8) - 4U < 0xfffc) && (*(int *)(lVar5 + 4) == 1)) {
            sVar2 = *(short *)(lVar5 + 8);
            psVar1 = (short *)((longlong)_Dst + 0x28);
            *psVar1 = sVar2;
            if (*(short *)((ulonglong)*(uint *)(lVar5 + 8) + 10 + lVar5) == 0) {
              *psVar1 = sVar2 + -2;
            }
            *(undefined2 *)((longlong)_Dst + 0x2a) = *(undefined2 *)(lVar5 + 8);
            pvVar7 = (void *)AiAlloc((ulonglong)*(uint *)(lVar5 + 8));
            *(void **)((longlong)_Dst + 0x30) = pvVar7;
            if (pvVar7 == (void *)0x0) goto LAB_140029a22;
            memmove(pvVar7,(void *)(lVar5 + 0xc),(ulonglong)*(uint *)(lVar5 + 8));
            RtlUpcaseUnicodeString(psVar1,psVar1,0);
            goto LAB_140029cee;
          }
          iVar3 = -0x3ffffff3;
        }
      }
      else {
LAB_140029e58:
        iVar3 = -0x3fffffff;
      }
    }
  }
LAB_140029e5d:
  ExFreePoolWithTag(lVar5,0);
LAB_140029e6e:
  AipFreeCert((longlong)_Dst);
  if (local_res20 != 0) {
    ZwClose();
  }
  return iVar3;
code_r0x000140029e1e:
  uVar9 = 1;
LAB_140029e33:
  RtlAvlInsertNodeEx(&AipCertificateStore,plVar10,uVar9,_Dst);
  _Dst = (void *)0x0;
  goto LAB_140029e5d;
}



===== AipAddCertPolicyInfo @ 140029eac =====

int AipAddCertPolicyInfo(longlong param_1,longlong param_2,char param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  void *_Dst;
  longlong lVar5;
  void *_Dst_00;
  longlong *plVar6;
  longlong *plVar7;
  undefined8 uVar8;
  undefined8 local_res10;
  
  local_res10 = 0;
  if ((param_2 == 0) && (param_3 == '\0')) {
    return -0x3ffffff3;
  }
  _Dst = (void *)ExAllocatePool2(0x102,0x68,0x44497041);
  if (_Dst == (void *)0x0) {
    return -0x3fffffe9;
  }
  memset(_Dst,0,0x68);
  iVar2 = AipAllocCertName(param_1,(longlong)_Dst);
  if (iVar2 < 0) goto LAB_14002a119;
  *(undefined8 *)((longlong)_Dst + 0x50) = *(undefined8 *)(param_1 + 0x28);
  *(undefined8 *)((longlong)_Dst + 0x48) = *(undefined8 *)(param_1 + 0x20);
  uVar3 = 0;
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0x10) + 0x20);
  if (uVar1 != 0) {
    lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18);
    do {
      if (((*(int *)(lVar5 + (ulonglong)uVar3 * 0x10) == 0xc) &&
          (plVar7 = *(longlong **)(lVar5 + 8 + (ulonglong)uVar3 * 0x10),
          *plVar7 == -0x7dfefbfef9d4f5fa)) && ((int)plVar7[1] == 0xd030a37)) {
        *(undefined4 *)((longlong)_Dst + 0x60) = 1;
        break;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  if (param_2 == 0) {
LAB_140029fca:
    uVar1 = **(uint **)(*(longlong *)(param_1 + 0x10) + 8);
    *(uint *)((longlong)_Dst + 0x38) = uVar1;
    _Dst_00 = (void *)AiAlloc((ulonglong)uVar1);
    *(void **)((longlong)_Dst + 0x40) = _Dst_00;
    if (_Dst_00 != (void *)0x0) {
      memmove(_Dst_00,*(void **)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 8) + 8),
              (ulonglong)*(uint *)((longlong)_Dst + 0x38));
      uVar8 = 0x20006;
      iVar2 = AiRegOpenKey(0,&DAT_1400085b0,0x20006,&local_res10);
      if (-1 < iVar2) {
        iVar2 = AipAddCertToCertStore(local_res10,(longlong)_Dst,uVar8);
        ZwClose(local_res10);
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) {
        WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                 &WPP_b7d6d7747cbe39158d21f26ad040a04c_Traceguids,(wchar_t *)((longlong)_Dst + 0x28)
                );
      }
      KeEnterCriticalRegion();
      ExAcquirePushLockExclusiveEx(&DAT_1400185f8,0);
      uVar8 = 0;
      plVar7 = AipCertificateStore;
      if (AipCertificateStore != (longlong *)0x0) {
        uVar1 = *(uint *)((longlong)_Dst + 0x38);
        do {
          if ((uVar1 < *(uint *)(plVar7 + 7)) ||
             ((uVar1 <= *(uint *)(plVar7 + 7) &&
              (iVar4 = memcmp(*(void **)((longlong)_Dst + 0x40),(void *)plVar7[8],(ulonglong)uVar1),
              iVar4 < 0)))) {
            plVar6 = (longlong *)*plVar7;
            if (plVar6 == (longlong *)0x0) {
              uVar8 = 0;
              break;
            }
          }
          else {
            plVar6 = (longlong *)plVar7[1];
            if (plVar6 == (longlong *)0x0) goto code_r0x00014002a0c8;
          }
          plVar7 = plVar6;
        } while( true );
      }
      goto LAB_14002a0dd;
    }
  }
  else {
    *(undefined2 *)((longlong)_Dst + 0x2a) = *(undefined2 *)(param_2 + 2);
    lVar5 = AiAlloc((ulonglong)*(ushort *)(param_2 + 2));
    *(longlong *)((longlong)_Dst + 0x30) = lVar5;
    if (lVar5 != 0) {
      RtlCopyUnicodeString((longlong)_Dst + 0x28,param_2);
      goto LAB_140029fca;
    }
  }
  iVar2 = -0x3fffffe9;
LAB_14002a119:
  AipFreeCert((longlong)_Dst);
  return iVar2;
code_r0x00014002a0c8:
  uVar8 = 1;
LAB_14002a0dd:
  RtlAvlInsertNodeEx(&AipCertificateStore,plVar7,uVar8,_Dst);
  ExReleasePushLockExclusiveEx(&DAT_1400185f8,0);
  KeLeaveCriticalRegion();
  _Dst = (void *)0x0;
  goto LAB_14002a119;
}



===== AipAddCertToCertStore @ 14002a140 =====

int AipAddCertToCertStore(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 local_res10;
  
  local_res10 = 0;
  iVar1 = AiRegCreateKey(param_1,param_2 + 0x18,param_3,&local_res10);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) {
      WPP_SF_ZD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                &WPP_b7d6d7747cbe39158d21f26ad040a04c_Traceguids,(wchar_t *)(param_2 + 0x18),
                (char)iVar1);
    }
  }
  else {
    iVar1 = ZwSetValueKey(local_res10,&DAT_140008530,0,0xb,param_2 + 0x50,8);
    if (-1 < iVar1) {
      iVar1 = ZwSetValueKey(local_res10,&DAT_140008520,0,0xb,param_2 + 0x48,8);
      if (-1 < iVar1) {
        if (*(int *)(param_2 + 0x60) != 0) {
          iVar1 = ZwSetValueKey(local_res10,&DAT_140008510,0,4,(int *)(param_2 + 0x60),4);
          if (iVar1 < 0) goto LAB_14002a2c8;
        }
        if (*(longlong *)(param_2 + 0x30) != 0) {
          iVar1 = ZwSetValueKey(local_res10,&DAT_140008500,0,1,*(longlong *)(param_2 + 0x30),
                                *(undefined2 *)(param_2 + 0x28));
          if (iVar1 < 0) goto LAB_14002a2c8;
        }
        iVar1 = ZwSetValueKey(local_res10,&DAT_1400084f0,0,3,*(undefined8 *)(param_2 + 0x40),
                              *(undefined4 *)(param_2 + 0x38));
      }
    }
  }
LAB_14002a2c8:
  ZwClose(local_res10);
  return iVar1;
}



===== AipAllocCertName @ 14002a2f4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int AipAllocCertName(longlong param_1,longlong param_2)

{
  ULONG cbInput;
  PUCHAR pbInput;
  NTSTATUS NVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ushort uVar5;
  ulonglong uVar6;
  ushort uVar7;
  undefined1 auStack_a8 [32];
  uint local_88;
  uint local_80;
  uint local_78;
  BCRYPT_HASH_HANDLE local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  byte local_48 [24];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_a8;
  local_68 = (BCRYPT_HASH_HANDLE)0x0;
  uStack_60 = 0;
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x28);
  local_58 = 0;
  uStack_50 = 0;
  cbInput = *(ULONG *)(lVar2 + 0x68);
  pbInput = *(PUCHAR *)(lVar2 + 0x70);
  NVar1 = AppHashInitHash(AppHashAlgHandle,&local_68);
  if ((-1 < NVar1) && (NVar1 = BCryptHashData(local_68,pbInput,cbInput,0), -1 < NVar1)) {
    NVar1 = BCryptFinishHash(local_68,local_48,(uint)local_58._4_2_,0);
  }
  AppHashDestroyHash(&local_68);
  if (-1 < NVar1) {
    lVar2 = AiAlloc(0x52);
    *(longlong *)(param_2 + 0x20) = lVar2;
    if (lVar2 == 0) {
      return -0x3fffffe9;
    }
    *(undefined4 *)(param_2 + 0x18) = 0x520000;
    uVar3 = 0;
    uVar7 = 0;
    do {
      uVar6 = (ulonglong)uVar7;
      local_78 = (uint)local_48[uVar3 + 3];
      local_80 = (uint)local_48[uVar6 + 2];
      local_88 = (uint)local_48[uVar6 + 1];
      uVar4 = RtlStringCchPrintfW((wchar_t *)(*(longlong *)(param_2 + 0x20) + uVar6 * 4),
                                  (ulonglong)(*(ushort *)(param_2 + 0x1a) >> 1) + uVar6 * -2,
                                  L"%02hhx%02hhx%02hhx%02hhx",(ulonglong)local_48[uVar6]);
      NVar1 = (NTSTATUS)uVar4;
      if (NVar1 < 0) {
        if (*(longlong *)(param_2 + 0x20) != 0) {
          ExFreePoolWithTag(*(longlong *)(param_2 + 0x20),0);
        }
        *(undefined8 *)(param_2 + 0x20) = 0;
        return NVar1;
      }
      uVar3 = (ulonglong)(ushort)(uVar7 + 4);
      uVar5 = uVar7 + 7;
      uVar7 = uVar7 + 4;
    } while (uVar5 < 0x14);
    *(undefined2 *)(param_2 + 0x18) = 0x50;
  }
  return NVar1;
}



===== AipFreeCert @ 14002a478 =====

void AipFreeCert(longlong param_1)

{
  if (param_1 != 0) {
    if (*(longlong *)(param_1 + 0x20) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x20),0);
    }
    if (*(longlong *)(param_1 + 0x30) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x30),0);
    }
    if (*(longlong *)(param_1 + 0x40) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x40),0);
    }
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== AipGetTrustedPublisherName @ 14002a4e8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
AipGetTrustedPublisherName(int *param_1,ulonglong *param_2,longlong param_3,undefined4 *param_4)

{
  uint uVar1;
  uint *puVar2;
  void *_Buf1;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  bool bVar10;
  
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 1;
  }
  uVar8 = 0xfffffffe;
  if ((((*param_1 != 0) && (lVar5 = *(longlong *)(param_1 + 4), lVar5 != 0)) &&
      (*(int *)(lVar5 + 0x10) != 0)) && (puVar2 = *(uint **)(lVar5 + 8), puVar2 != (uint *)0x0)) {
    _Buf1 = *(void **)(puVar2 + 2);
    uVar1 = *puVar2;
    KeEnterCriticalRegion();
    ExAcquirePushLockSharedEx(&DAT_1400185f8,0);
    puVar7 = (undefined8 *)0x0;
    puVar9 = AipCertificateStore;
    while (puVar9 != (undefined8 *)0x0) {
      if (uVar1 < *(uint *)(puVar9 + 7)) {
LAB_14002a59e:
        puVar9 = (undefined8 *)*puVar9;
      }
      else {
        if (uVar1 <= *(uint *)(puVar9 + 7)) {
          iVar3 = memcmp(_Buf1,(void *)puVar9[8],(ulonglong)uVar1);
          if (-1 < iVar3) {
            if (0 < iVar3) goto LAB_14002a5e2;
            puVar7 = puVar9;
          }
          goto LAB_14002a59e;
        }
LAB_14002a5e2:
        puVar9 = (undefined8 *)puVar9[1];
      }
    }
    if (puVar7 != (undefined8 *)0x0) {
      do {
        if (*(int *)(puVar7 + 0xb) == 0) {
          if (param_4 != (undefined4 *)0x0) {
            *param_4 = 0;
          }
          if (*(int *)((longlong)puVar7 + 0x5c) == 0) {
            if (param_2 != (ulonglong *)0x0) {
              if (*(int *)(puVar7 + 0xc) == 0) {
                uVar4 = *param_2;
              }
              else {
                uVar4 = _DAT_fffff78000000014;
              }
              if ((uVar4 < (ulonglong)puVar7[9]) || ((ulonglong)puVar7[10] < uVar4))
              goto LAB_14002a5f8;
            }
            if (param_3 != 0) {
              if (*(longlong *)(param_3 + 8) == 0) {
LAB_14002a680:
                lVar5 = AiAlloc((ulonglong)*(ushort *)((longlong)puVar7 + 0x2a));
                *(longlong *)(param_3 + 8) = lVar5;
                if (lVar5 == 0) {
                  uVar8 = 0xc0000017;
                  break;
                }
                *(ushort *)(param_3 + 2) = *(ushort *)((longlong)puVar7 + 0x2a);
              }
              else if (*(ushort *)(param_3 + 2) < *(ushort *)((longlong)puVar7 + 0x2a)) {
                ExFreePoolWithTag(*(longlong *)(param_3 + 8),0);
                goto LAB_14002a680;
              }
              RtlCopyUnicodeString(param_3,puVar7 + 5);
            }
            uVar8 = 0;
            break;
          }
        }
LAB_14002a5f8:
        puVar9 = (undefined8 *)puVar7[1];
        puVar6 = puVar7;
        if (puVar9 == (undefined8 *)0x0) {
          do {
            puVar7 = (undefined8 *)(puVar6[2] & 0xfffffffffffffffc);
            if (puVar7 == (undefined8 *)0x0) break;
            bVar10 = (undefined8 *)*puVar7 != puVar6;
            puVar6 = puVar7;
          } while (bVar10);
        }
        else {
          puVar7 = puVar9;
          for (puVar9 = (undefined8 *)*puVar9; puVar9 != (undefined8 *)0x0;
              puVar9 = (undefined8 *)*puVar9) {
            puVar7 = puVar9;
          }
        }
        if (((puVar7 == (undefined8 *)0x0) || (uVar1 < *(uint *)(puVar7 + 7))) ||
           ((*(uint *)(puVar7 + 7) < uVar1 ||
            (iVar3 = memcmp(_Buf1,(void *)puVar7[8],(ulonglong)uVar1), iVar3 != 0)))) break;
      } while( true );
    }
    ExReleasePushLockSharedEx(&DAT_1400185f8,0);
    KeLeaveCriticalRegion();
  }
  return uVar8;
}



===== AipGetTrustedPublisherNameFromService @ 14002a6fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint AipGetTrustedPublisherNameFromService
               (undefined8 param_1,longlong param_2,longlong param_3,undefined1 *param_4)

{
  uint uVar1;
  undefined1 auStack_c8 [32];
  undefined4 local_a8;
  undefined4 local_a0;
  undefined4 local_98;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_c8;
  local_88 = 0;
  local_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  uVar1 = 0xfffffffe;
  local_58 = 0;
  uStack_50 = 0;
  *param_4 = 1;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(&AipServiceContext,0);
  if ((DAT_140018610 == 0) || (DAT_140018608 == 0)) {
    *param_4 = 0;
  }
  else {
    local_98 = 2;
    local_a0 = 0;
    local_a8 = 0;
    uVar1 = ZwDuplicateObject(0xffffffffffffffff,param_1,DAT_140018618,&local_88);
    if (-1 < (int)uVar1) {
      uVar1 = AiVerifyFile(DAT_140018608,(int)local_88,param_2,&local_80);
      if (-1 < (int)uVar1) {
        if (*(longlong *)(param_3 + 8) != 0) {
          ExFreePoolWithTag(*(longlong *)(param_3 + 8),0);
        }
        RtlInitUnicodeString(param_3,local_80);
      }
      KeStackAttachProcess(DAT_140018610,&local_78);
      ObCloseHandle(local_88,1);
      KeUnstackDetachProcess(&local_78);
    }
  }
  ExReleasePushLockSharedEx(&AipServiceContext,0);
  KeLeaveCriticalRegion();
  return uVar1;
}



===== AipSetServicePublisherInfoInCache @ 14002a890 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AipSetServicePublisherInfoInCache(undefined8 param_1,undefined4 *param_2)

{
  undefined1 auStackY_1a8 [32];
  undefined4 local_178;
  undefined4 local_174;
  undefined8 local_170;
  undefined4 local_168;
  undefined4 local_164;
  undefined8 local_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined4 *local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined4 *local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined4 local_f8 [2];
  undefined4 *local_f0;
  undefined4 local_e8;
  undefined4 local_88 [2];
  undefined4 *local_80;
  undefined4 local_78;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_1a8;
  local_174 = 0;
  local_164 = 0;
  local_118 = local_f8;
  uStack_120 = 0;
  local_128 = 0x30;
  uStack_110 = 0;
  local_108 = 0;
  uStack_100 = 0;
  memset(local_f8,0,0x68);
  local_f8[0] = 0x68;
  local_f0 = &local_178;
  local_e8 = 1;
  local_178 = *param_2;
  local_170 = *(undefined8 *)(param_2 + 2);
  local_148 = local_88;
  uStack_150 = 0;
  local_158 = 0x30;
  uStack_140 = 0;
  local_138 = 0;
  uStack_130 = 0;
  memset(local_88,0,0x68);
  local_80 = &local_168;
  local_88[0] = 0x68;
  local_168 = param_2[4];
  local_160 = *(undefined8 *)(param_2 + 6);
  local_78 = 1;
  AipSetTrustedPublisherNameInCache
            (param_1,(longlong)&local_128,(longlong *)(param_2 + 8),(longlong)&local_158,
             (longlong *)(param_2 + 10));
  return;
}



===== AipSetTrustedPublisherNameInCache @ 14002a9d0 =====

undefined4
AipSetTrustedPublisherNameInCache
          (undefined8 param_1,longlong param_2,longlong *param_3,longlong param_4,longlong *param_5)

{
  uint *puVar1;
  undefined4 uVar2;
  void *_Dst;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  uVar3 = **(uint **)(*(longlong *)(param_2 + 0x10) + 8);
  if (((0xffff < uVar3) ||
      ((*param_3 != 0 && (0xffff < **(uint **)(*(longlong *)(param_4 + 0x10) + 8))))) ||
     ((uVar3 == 0 && (*param_5 == 0)))) {
    return 0xc000000d;
  }
  uVar3 = uVar3 + 0x48;
  if (0x47 < uVar3) {
    if ((*param_3 != 0) &&
       (uVar4 = **(int **)(*(longlong *)(param_4 + 0x10) + 8) + uVar3, bVar5 = uVar4 < uVar3,
       uVar3 = uVar4, bVar5)) {
      return 0xc0000095;
    }
    if (uVar3 < 0x1001) {
      _Dst = (void *)AiAlloc((ulonglong)uVar3);
      if (_Dst == (void *)0x0) {
        return 0xc0000017;
      }
      memset(_Dst,0,(ulonglong)uVar3);
      *(undefined1 *)((longlong)_Dst + 5) = 0x1e;
      *(short *)((longlong)_Dst + 6) = (short)uVar3 + -0x27;
      builtin_strncpy((char *)((longlong)_Dst + 8),"$KERNEL.",8);
      builtin_strncpy((char *)((longlong)_Dst + 0x10),"PURGE.AP",8);
      *(undefined8 *)((longlong)_Dst + 0x18) = 0x4e4749532e444950;
      *(undefined4 *)((longlong)_Dst + 0x20) = 0x4e495245;
      *(undefined2 *)((longlong)_Dst + 0x24) = 0x4f46;
      *(undefined1 *)((longlong)_Dst + 0x26) = 0;
      *(undefined4 *)((longlong)_Dst + 0x28) = 0x33444941;
      *(undefined2 *)((longlong)_Dst + 0x30) = **(undefined2 **)(*(longlong *)(param_2 + 0x10) + 8);
      if (*param_3 != 0) {
        *(undefined2 *)((longlong)_Dst + 0x32) =
             **(undefined2 **)(*(longlong *)(param_4 + 0x10) + 8);
      }
      *(longlong *)((longlong)_Dst + 0x38) = *param_3;
      puVar1 = *(uint **)(*(longlong *)(param_2 + 0x10) + 8);
      memmove((void *)((longlong)_Dst + 0x48),*(void **)(puVar1 + 2),(ulonglong)*puVar1);
      if (*(short *)((longlong)_Dst + 0x32) != 0) {
        puVar1 = *(uint **)(*(longlong *)(param_4 + 0x10) + 8);
        memmove((void *)((ulonglong)*(ushort *)((longlong)_Dst + 0x30) + 0x48 + (longlong)_Dst),
                *(void **)(puVar1 + 2),(ulonglong)*puVar1);
      }
      if (param_5 != (longlong *)0x0) {
        *(longlong *)((longlong)_Dst + 0x40) = *param_5;
      }
      uVar2 = FsRtlSetKernelEaFile
                        (param_1,_Dst,
                         (uint)*(byte *)((longlong)_Dst + 5) + *(ushort *)((longlong)_Dst + 6) + 9);
      ExFreePoolWithTag(_Dst,0);
      return uVar2;
    }
  }
  return 0xc0000095;
}



===== AipkVerifyPackageMonikerFromService @ 14002abbc =====

ulonglong AipkVerifyPackageMonikerFromService
                    (ushort *param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4,
                    undefined4 *param_5,undefined8 *param_6)

{
  void *_Dst;
  ulonglong uVar1;
  undefined8 local_28;
  undefined8 local_20;
  
  _Dst = (void *)0x0;
  local_28 = 0;
  local_20 = 0;
  uVar1 = 0xfffffffe;
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(&AipServiceContext,0);
  if ((DAT_140018610 != 0) && (DAT_140018608 != 0)) {
    _Dst = (void *)AiAlloc((ulonglong)*param_1 + 2);
    if (_Dst == (void *)0x0) {
      uVar1 = 0xc0000017;
    }
    else {
      memmove(_Dst,*(void **)(param_1 + 4),(ulonglong)*param_1);
      *(undefined2 *)((longlong)_Dst + (ulonglong)(*param_1 >> 1) * 2) = 0;
      uVar1 = AiVerifyPackageMoniker(DAT_140018608,_Dst,&local_28,&local_20,param_4,param_5,param_6)
      ;
      uVar1 = uVar1 & 0xffffffff;
      RtlInitUnicodeString(param_2,local_28);
      RtlInitUnicodeString(param_3,local_20);
    }
  }
  ExReleasePushLockSharedEx(&AipServiceContext,0);
  KeLeaveCriticalRegion();
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
  return uVar1;
}



===== AiCleanTokens @ 14002ad2c =====

void AiCleanTokens(longlong param_1,longlong param_2)

{
  if (param_1 != 0) {
    ZwClose();
  }
  if ((param_2 != 0) && (param_2 != param_1)) {
    ZwClose(param_2);
  }
  return;
}



===== AiGetTokens @ 14002ad78 =====

int AiGetTokens(undefined8 param_1,ulonglong *param_2,ulonglong *param_3)

{
  int iVar1;
  ulonglong uVar2;
  char local_res20 [8];
  ulonglong local_38;
  undefined4 local_30 [2];
  ulonglong local_28;
  ulonglong local_20;
  
  local_28 = 0;
  local_res20[0] = '\0';
  local_20 = 0;
  iVar1 = AiOpenTokenByProcessId(param_1,&local_28);
  if (iVar1 < 0) goto LAB_14002aeb3;
  if (param_3 != (ulonglong *)0x0) {
    iVar1 = AiIsTokenRestricted(local_28,local_res20);
    if (iVar1 < 0) goto LAB_14002aeb3;
    if (DisableExeLinkedTokenLookup == '\0') {
      local_30[0] = 0;
      local_38 = local_38 & 0xffffffff00000000;
      iVar1 = ZwQueryInformationToken(local_28,0x12,&local_38,4,local_30);
      if (iVar1 < 0) goto LAB_14002aeb3;
      if ((int)local_38 != 2) {
        if (iVar1 < 0) goto LAB_14002aeb3;
        local_30[0] = 0;
        local_38 = 0;
        iVar1 = ZwQueryInformationToken(local_28,0x13,&local_38,8,local_30);
        if (-1 < iVar1) {
          local_20 = local_38;
        }
      }
    }
    if ((((local_res20[0] != '\0') && (iVar1 < 0)) &&
        (iVar1 = SeGetLogonSessionToken(local_28,0,&local_20),
        (iVar1 + 0x80000000U & 0x80000000) == 0)) && (iVar1 != -0x3fffff84)) goto LAB_14002aeb3;
    uVar2 = local_20;
    if (local_20 == 0) {
      uVar2 = local_28;
    }
    else {
      local_20 = 0;
    }
    *param_3 = uVar2;
  }
  iVar1 = 0;
  *param_2 = local_28;
  local_28 = 0;
LAB_14002aeb3:
  AiCleanTokens(local_28,local_20);
  return iVar1;
}



===== AiIsTokenRestricted @ 14002aedc =====

void AiIsTokenRestricted(undefined8 param_1,undefined1 *param_2)

{
  int iVar1;
  int local_res10 [2];
  undefined4 local_res18 [4];
  
  local_res18[0] = 0;
  local_res10[0] = 0;
  *param_2 = 0;
  iVar1 = ZwQueryInformationToken(param_1,0x28,local_res10,4,local_res18);
  if ((-1 < iVar1) && (local_res10[0] != 0)) {
    *param_2 = 1;
  }
  return;
}



===== AiIsTokenSandBoxed @ 14002af34 =====

void AiIsTokenSandBoxed(undefined1 param_1,undefined8 param_2)

{
  int iVar1;
  int local_res18 [2];
  undefined4 local_res20 [2];
  
  local_res20[0] = 0;
  local_res18[0] = 0;
  iVar1 = ZwQueryInformationToken(param_1,0xf,local_res18,4,local_res20);
  if (-1 < iVar1) {
    *(bool *)param_2 = local_res18[0] != 0;
  }
  return;
}



===== AiOpenImageFile @ 14002af88 =====

int AiOpenImageFile(wchar_t *param_1,longlong param_2,longlong *param_3)

{
  int iVar1;
  longlong lVar2;
  longlong local_res20;
  ulonglong in_stack_ffffffffffffff80;
  longlong local_68 [3];
  undefined8 local_50;
  undefined8 uStack_48;
  wchar_t *local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  ulonglong uStack_28;
  
  local_res20 = 0;
  local_30 = 0;
  uStack_28 = uStack_28 & 0xffffffff00000000;
  local_50 = 0;
  uStack_48 = 0;
  lVar2 = 0;
  local_40 = (wchar_t *)0x0;
  uStack_38 = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  iVar1 = ObOpenObjectByPointer
                    (param_2,0x200,0,0x80100000,*(undefined8 *)IoFileObjectType_exref,
                     in_stack_ffffffffffffff80 & 0xffffffffffffff00,param_3);
  if (iVar1 < 0) {
    uStack_48 = 0;
    local_50 = CONCAT44(local_50._4_4_,0x30);
    uStack_38 = CONCAT44(uStack_38._4_4_,0x240);
    local_30 = 0;
    uStack_28 = 0;
    local_40 = param_1;
    iVar1 = ZwOpenFile(&local_res20,0x80100000,&local_50,local_68 + 1,5,0x60);
    if (-1 < iVar1) {
      local_68[0] = 0;
      iVar1 = ObReferenceObjectByHandle
                        (local_res20,0,*(undefined8 *)IoFileObjectType_exref,0,local_68,0);
      lVar2 = local_68[0];
      if (-1 < iVar1) {
        if (*(longlong *)(param_2 + 0x18) == *(longlong *)(local_68[0] + 0x18)) {
          *param_3 = local_res20;
          local_res20 = 0;
          goto LAB_14002b0e5;
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) {
          WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                   &WPP_eb456f0194b1375dfc92b638f91e9c3b_Traceguids,param_1);
        }
        iVar1 = -0x3ffffddb;
      }
    }
  }
LAB_14002b0e5:
  if (local_res20 != 0) {
    ZwClose();
  }
  if (lVar2 != 0) {
    ObfDereferenceObject(lVar2);
  }
  return iVar1;
}



===== AiOpenTokenByProcessId @ 14002b140 =====

int AiOpenTokenByProcessId(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  longlong local_res8;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8 = 0;
  local_1c = 0;
  local_30 = 0;
  local_28 = 0;
  local_40 = 0;
  local_38 = 0x30;
  local_18 = 0;
  uStack_10 = 0;
  local_20 = 0x200;
  local_48 = param_1;
  iVar1 = ZwOpenProcess(&local_res8,0x400,&local_38,&local_48);
  if (-1 < iVar1) {
    iVar1 = ZwOpenProcessTokenEx(local_res8,0,0x200,param_2);
  }
  if (local_res8 != 0) {
    ZwClose();
  }
  return iVar1;
}



===== AiSetAttributesAppx @ 14002b1fc =====

int AiSetAttributesAppx(undefined8 param_1,ushort *param_2,char param_3,longlong param_4,
                       longlong param_5,ulonglong *param_6)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  longlong local_28;
  ulonglong local_20;
  ulonglong uStack_18;
  
  local_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  AiEnsureServiceRunning('\x01');
  iVar2 = AipkGetAppxAttributes(param_2,param_1,param_3,&local_20,&local_28);
  lVar1 = local_28;
  if (-1 < iVar2) {
    if (param_6 == (ulonglong *)0x0) {
      if (uStack_18 != 0) {
        ExFreePoolWithTag(uStack_18,0);
      }
    }
    else {
      *param_6 = local_20;
      param_6[1] = uStack_18;
    }
    uVar3 = AiSetTokenAttributes(param_4,lVar1);
    iVar2 = (int)uVar3;
    if ((-1 < iVar2) && (param_5 != param_4)) {
      uVar3 = AiSetTokenAttributes(param_5,lVar1);
      iVar2 = (int)uVar3;
    }
  }
  if (lVar1 != 0) {
    if (*(longlong *)(lVar1 + -0x30) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar1 + -0x30),0);
    }
    ExFreePoolWithTag(lVar1 + -0x40,0);
  }
  return iVar2;
}



===== AiSetAttributesExe @ 14002b2fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int AiSetAttributesExe(longlong param_1,longlong param_2,longlong param_3,longlong param_4,
                      char param_5)

{
  int iVar1;
  undefined8 uVar2;
  undefined *puVar3;
  longlong lVar4;
  bool bVar5;
  undefined1 auStackY_88 [32];
  longlong local_58;
  int local_50;
  int iStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_88;
  local_58 = 0;
  lVar4 = param_4;
  KeEnterCriticalRegion();
  ExAcquireResourceSharedLite(&DAT_1400187c0);
  local_50 = _DAT_140018828;
  iStack_4c = iRam000000014001882c;
  uStack_48 = uRam0000000140018830;
  iStack_44 = iRam0000000140018834;
  local_40 = DAT_140018838;
  uVar2 = local_40;
  if (_DAT_140018828 == -1) {
    local_50 = *(int *)(param_1 + 0x150);
  }
  if (iRam0000000140018834 == -1) {
    iStack_44 = *(int *)(param_1 + 0x15c);
  }
  local_40._0_4_ = (int)DAT_140018838;
  bVar5 = (int)local_40 == -1;
  local_40 = uVar2;
  if (bVar5) {
    local_40._4_4_ = (int)((ulonglong)DAT_140018838 >> 0x20);
    local_40 = CONCAT44(local_40._4_4_,*(undefined4 *)(param_1 + 0x160));
  }
  if (local_40._4_4_ == -1) {
    local_40 = CONCAT44(*(undefined4 *)(param_1 + 0x164),(int)local_40);
  }
  if (iRam000000014001882c == -1) {
    iStack_4c = *(int *)(param_1 + 0x154);
  }
  puVar3 = &DAT_1400187c0;
  ExReleaseResourceLite();
  KeLeaveCriticalRegion();
  if (iStack_4c != 0) {
    puVar3 = (undefined *)CONCAT71((int7)((ulonglong)puVar3 >> 8),param_5 == '\0');
    AiEnsureServiceRunning(param_5 == '\0');
  }
  iVar1 = AiGetFileAttributes(puVar3,param_2,&local_50,lVar4,&local_58);
  lVar4 = local_58;
  if (-1 < iVar1) {
    uVar2 = AiSetTokenAttributes(param_3,local_58);
    iVar1 = (int)uVar2;
    if ((-1 < iVar1) && (param_4 != param_3)) {
      uVar2 = AiSetTokenAttributes(param_4,lVar4);
      iVar1 = (int)uVar2;
    }
  }
  if (local_58 != 0) {
    AipFreeImageContext(local_58 + -0x298);
  }
  return iVar1;
}



===== AiAddImagePathWithMacro @ 14002b460 =====

undefined4 AiAddImagePathWithMacro(longlong param_1,ushort *param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  short *psVar3;
  undefined8 uVar4;
  char cVar5;
  void *_Dst;
  ushort *puVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  
  if (*param_2 == 0) {
    return 0xc000000d;
  }
  RtlUpcaseUnicodeString(param_2,param_2,0);
  if (*(uint *)(param_1 + 0x74) == *(uint *)(param_1 + 0x78)) {
    uVar9 = (ulonglong)*(uint *)(param_1 + 0x78) * 2;
    if (0xffffffff < uVar9) {
      return 0xc0000095;
    }
    _Dst = (void *)AiAlloc((uVar9 & 0xffffffff) << 4);
    if (_Dst == (void *)0x0) {
      return 0xc0000017;
    }
    memmove(_Dst,*(void **)(param_1 + 0x80),(ulonglong)*(uint *)(param_1 + 0x74) << 4);
    lVar2 = *(longlong *)(param_1 + 0x80);
    if ((lVar2 != param_1 + 0x88) && (lVar2 != 0)) {
      ExFreePoolWithTag(lVar2,0);
    }
    *(int *)(param_1 + 0x78) = (int)uVar9;
    *(void **)(param_1 + 0x80) = _Dst;
  }
  uVar7 = *(uint *)(param_1 + 0x74);
  uVar9 = 0;
  if (uVar7 != 0) {
    do {
      psVar3 = *(short **)(*(longlong *)(param_1 + 0x80) + 8 + uVar9 * 0x10);
      if (**(short **)(param_2 + 4) == 0x25) {
        if (*psVar3 != 0x25) break;
LAB_14002b5d8:
        puVar6 = (ushort *)(*(longlong *)(param_1 + 0x80) + uVar9 * 0x10);
        if (*param_2 < *puVar6) break;
        cVar5 = RtlEqualUnicodeString(param_2,puVar6,0);
        if (cVar5 != '\0') {
          if (*(longlong *)(param_2 + 4) != 0) {
            ExFreePoolWithTag(*(longlong *)(param_2 + 4),0);
          }
          param_2[4] = 0;
          param_2[5] = 0;
          param_2[6] = 0;
          param_2[7] = 0;
          return 0;
        }
      }
      else if (*psVar3 != 0x25) goto LAB_14002b5d8;
      uVar7 = *(uint *)(param_1 + 0x74);
      uVar8 = (int)uVar9 + 1;
      uVar9 = (ulonglong)uVar8;
    } while (uVar8 < uVar7);
  }
  uVar8 = (uint)uVar9;
  if (uVar8 < uVar7) {
    memmove((void *)((ulonglong)(uVar8 + 1) * 0x10 + *(longlong *)(param_1 + 0x80)),
            (void *)(uVar9 * 0x10 + *(longlong *)(param_1 + 0x80)),(ulonglong)(uVar7 - uVar8) << 4);
  }
  uVar4 = *(undefined8 *)(param_2 + 4);
  puVar1 = (undefined8 *)(*(longlong *)(param_1 + 0x80) + uVar9 * 0x10);
  *puVar1 = *(undefined8 *)param_2;
  puVar1[1] = uVar4;
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  param_2[7] = 0;
  *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + 1;
  return 0;
}



===== AiEncodeAttributeString @ 14002b644 =====

undefined8 AiEncodeAttributeString(ushort *param_1,undefined8 param_2,short *param_3)

{
  short *psVar1;
  byte bVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  ushort uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  longlong lVar9;
  
  uVar4 = *param_1;
  uVar6 = uVar4 >> 1;
  uVar7 = 0;
  iVar5 = 0;
  param_3[0] = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  param_3[4] = 0;
  param_3[5] = 0;
  param_3[6] = 0;
  param_3[7] = 0;
  if (uVar6 != 0) {
    psVar1 = *(short **)(param_1 + 4);
    uVar8 = (ulonglong)uVar6;
    do {
      if (((ushort)(*psVar1 - 0x22U) < 0x3b) &&
         ((0x400000020000109U >> ((ulonglong)(ushort)(*psVar1 - 0x22U) & 0x3f) & 1) != 0)) {
        iVar5 = iVar5 + 1;
      }
      psVar1 = psVar1 + 1;
      uVar8 = uVar8 - 1;
    } while (uVar8 != 0);
    if (iVar5 != 0) {
      if ((uint)uVar6 + iVar5 * 2 < 0x7fff) {
        sVar3 = (short)iVar5 * 4 + uVar4;
        *param_3 = sVar3;
        uVar4 = sVar3 + 2;
        param_3[1] = uVar4;
        psVar1 = (short *)AiAlloc((ulonglong)uVar4);
        *(short **)(param_3 + 4) = psVar1;
        if (psVar1 != (short *)0x0) {
          uVar8 = (ulonglong)uVar6;
          lVar9 = 0;
          do {
            uVar4 = *(short *)(lVar9 + *(longlong *)(param_1 + 4)) - 0x22;
            if ((uVar4 < 0x3b) && ((0x400000020000109U >> ((ulonglong)uVar4 & 0x3f) & 1) != 0)) {
              *psVar1 = 0x25;
              uVar4 = *(byte *)(lVar9 + *(longlong *)(param_1 + 4)) & 0xf;
              bVar2 = *(byte *)(lVar9 + *(longlong *)(param_1 + 4)) >> 4;
              psVar1[2] = (-(ushort)((byte)uVar4 < 10) & 0xfff9) + uVar4 + 0x37;
              psVar1[1] = (-(ushort)(bVar2 < 10) & 0xfff9) + 0x37 + (ushort)bVar2;
              psVar1 = psVar1 + 2;
            }
            else {
              *psVar1 = *(short *)(lVar9 + *(longlong *)(param_1 + 4));
            }
            lVar9 = lVar9 + 2;
            psVar1 = psVar1 + 1;
            uVar8 = uVar8 - 1;
          } while (uVar8 != 0);
          *psVar1 = 0;
          return 0;
        }
        uVar7 = 0xc0000017;
      }
      else {
        uVar7 = 0xc0000095;
      }
      if (*(longlong *)(param_3 + 4) != 0) {
        ExFreePoolWithTag(*(longlong *)(param_3 + 4),0);
        param_3[0] = 0;
        param_3[1] = 0;
        param_3[2] = 0;
        param_3[3] = 0;
        param_3[4] = 0;
        param_3[5] = 0;
        param_3[6] = 0;
        param_3[7] = 0;
      }
    }
  }
  return uVar7;
}



===== AiGetFileAttributes @ 14002b7dc =====

int AiGetFileAttributes(undefined8 param_1,longlong param_2,int *param_3,undefined8 param_4,
                       longlong *param_5)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *local_res20;
  
  local_res20 = (undefined8 *)0x0;
  iVar1 = AipAllocateImageContext(param_1,param_2,0,&local_res20);
  puVar2 = local_res20;
  if ((-1 < iVar1) && (iVar1 = AipCollectImageProperties(local_res20,param_3,0,param_5), -1 < iVar1)
     ) {
    if (puVar2[2] != 0) {
      ObfDereferenceObject();
      puVar2[2] = 0;
    }
    puVar2 = (undefined8 *)0x0;
  }
  if (puVar2 != (undefined8 *)0x0) {
    AipFreeImageContext((longlong)puVar2);
  }
  return iVar1;
}



===== AiSmartHashImageFile @ 14002b868 =====

void AiSmartHashImageFile(longlong param_1,longlong param_2,longlong param_3)

{
  AipSmartHashImageFile(param_1,param_2,0,param_3);
  return;
}



===== AipAddFQBNAttribute @ 14002b884 =====

int AipAddFQBNAttribute(longlong param_1)

{
  undefined8 *puVar1;
  void *_Dst;
  int iVar2;
  ulonglong uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x1a4);
  if (iVar5 < 0) {
    iVar2 = 0;
    if (iVar5 != -2) {
      iVar2 = iVar5;
    }
    iVar5 = iVar2;
  }
  else if (*(uint *)(param_1 + 0x29c) < 5) {
    if (*(longlong *)(param_1 + 0x1c8) == 0) {
      iVar2 = *(ushort *)(param_1 + 0x1a8) + 2;
      if (-1 < *(int *)(param_1 + 0x168)) {
        iVar2 = (uint)*(ushort *)(param_1 + 0x180) + (uint)*(ushort *)(param_1 + 400) + iVar2;
      }
      uVar4 = iVar2 + 2;
      if (0xffff < uVar4) {
        return -0x3fffff6b;
      }
      *(short *)(param_1 + 0x1c0) = (short)uVar4;
      *(short *)(param_1 + 0x1c2) = (short)uVar4;
      _Dst = (void *)AiAlloc((ulonglong)uVar4);
      *(void **)(param_1 + 0x1c8) = _Dst;
      if (_Dst == (void *)0x0) {
        return -0x3fffffe9;
      }
      memmove(_Dst,*(void **)(param_1 + 0x1b0),(ulonglong)*(ushort *)(param_1 + 0x1a8));
      uVar4 = *(ushort *)(param_1 + 0x1a8) + 2;
      uVar3 = (ulonglong)uVar4;
      *(undefined2 *)((ulonglong)*(ushort *)(param_1 + 0x1a8) + *(longlong *)(param_1 + 0x1c8)) =
           0x5c;
      if (*(int *)(param_1 + 0x168) < 0) {
        *(undefined2 *)(uVar3 + *(longlong *)(param_1 + 0x1c8)) = 0x5c;
      }
      else {
        if (*(ushort *)(param_1 + 0x180) != 0) {
          memmove((void *)(uVar3 + *(longlong *)(param_1 + 0x1c8)),*(void **)(param_1 + 0x188),
                  (ulonglong)*(ushort *)(param_1 + 0x180));
          uVar3 = (ulonglong)(uVar4 + *(ushort *)(param_1 + 0x180));
        }
        *(undefined2 *)(uVar3 + *(longlong *)(param_1 + 0x1c8)) = 0x5c;
        if (*(ushort *)(param_1 + 400) != 0) {
          memmove((void *)((ulonglong)((int)uVar3 + 2) + *(longlong *)(param_1 + 0x1c8)),
                  *(void **)(param_1 + 0x198),(ulonglong)*(ushort *)(param_1 + 400));
        }
        *(ulonglong *)(param_1 + 0x1b8) =
             CONCAT44(*(undefined4 *)(param_1 + 0x16c),*(undefined4 *)(param_1 + 0x170));
      }
    }
    uVar3 = (ulonglong)*(uint *)(param_1 + 0x29c);
    *(uint *)(param_1 + 0x29c) = *(uint *)(param_1 + 0x29c) + 1;
    *(longlong *)(param_1 + 0x1f0 + uVar3 * 0x28) = param_1 + 0x1b8;
    puVar1 = (undefined8 *)(param_1 + 0x1d0 + uVar3 * 0x28);
    *puVar1 = 0x1a0018;
    puVar1[1] = L"APPID://FQBN";
    *(undefined2 *)(param_1 + 0x1e0 + uVar3 * 0x28) = 4;
    *(undefined4 *)(param_1 + 0x1e8 + uVar3 * 0x28) = 1;
    *(undefined4 *)(param_1 + 0x1e4 + uVar3 * 0x28) = 3;
  }
  else {
    iVar5 = -0x7ffffffb;
  }
  return iVar5;
}



===== AipAddHashAttribute @ 14002ba8c =====

int AipAddHashAttribute(longlong param_1,int param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  int iVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong lVar9;
  int iVar10;
  
  iVar10 = *(int *)(param_1 + 200);
  if (iVar10 < 0) {
    iVar5 = 0;
    if (iVar10 != -2) {
      iVar5 = iVar10;
    }
    iVar10 = iVar5;
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x29c);
    uVar6 = (ulonglong)uVar2;
    if (uVar2 < 5) {
      lVar9 = (longlong)param_2;
      *(uint *)(param_1 + 0x29c) = uVar2 + 1;
      lVar7 = lVar9 * 0x10;
      plVar8 = (longlong *)(param_1 + 0x138 + lVar7);
      *(undefined2 *)(param_1 + 0x1e0 + uVar6 * 0x28) = 0x10;
      *(longlong **)(param_1 + 0x1f0 + uVar6 * 0x28) = plVar8;
      uVar3 = *(undefined8 *)(&DAT_1400085c0 + lVar7);
      uVar4 = *(undefined8 *)(&UNK_1400085c8 + lVar7);
      *(undefined4 *)(param_1 + 0x1e8 + uVar6 * 0x28) = 1;
      puVar1 = (undefined8 *)(param_1 + 0x1d0 + uVar6 * 0x28);
      *puVar1 = uVar3;
      puVar1[1] = uVar4;
      *plVar8 = lVar9 * 0x20 + 0xcc + param_1;
      *(undefined4 *)(param_1 + (lVar9 + 0x14) * 0x10) = *(undefined4 *)(param_1 + 300 + lVar9 * 4);
      *(undefined4 *)(param_1 + 0x1e4 + uVar6 * 0x28) = 1;
    }
    else {
      iVar10 = -0x7ffffffb;
    }
  }
  return iVar10;
}



===== AipAllocateImageContext @ 14002bb54 =====

int AipAllocateImageContext
              (undefined8 param_1,longlong param_2,longlong param_3,undefined8 *param_4)

{
  int iVar1;
  void *_Dst;
  undefined8 local_res8;
  
  iVar1 = 0;
  local_res8 = param_1;
  _Dst = (void *)ExAllocatePool2(0x102,0x2a8,0x44497041);
  if (_Dst == (void *)0x0) {
    iVar1 = -0x3fffffe9;
  }
  else {
    memset(_Dst,0,0x2a8);
    *(longlong *)((longlong)_Dst + 8) = param_2;
    *(undefined4 *)((longlong)_Dst + 200) = 0xffffffff;
    *(undefined4 *)((longlong)_Dst + 0x168) = 0xffffffff;
    *(undefined4 *)((longlong)_Dst + 0x1a4) = 0xffffffff;
    *(longlong *)((longlong)_Dst + 0x80) = (longlong)_Dst + 0x88;
    *(longlong *)((longlong)_Dst + 0x2a0) = (longlong)_Dst + 0x1d0;
    *(undefined4 *)((longlong)_Dst + 0x78) = 4;
    *(undefined2 *)((longlong)_Dst + 0x298) = 1;
    if (param_3 == 0) {
      if (param_2 != 0) {
        local_res8 = 0;
        iVar1 = ObReferenceObjectByHandle
                          (param_2,0,*(undefined8 *)IoFileObjectType_exref,0,&local_res8,0);
        *(undefined8 *)((longlong)_Dst + 0x10) = local_res8;
        if (iVar1 < 0) {
          AipFreeImageContext((longlong)_Dst);
          return iVar1;
        }
      }
    }
    else {
      ObfReferenceObject(param_3);
      *(longlong *)((longlong)_Dst + 0x10) = param_3;
    }
    *param_4 = _Dst;
  }
  return iVar1;
}



===== AipCollectImageProperties @ 14002bc80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int AipCollectImageProperties(undefined8 *param_1,int *param_2,undefined8 param_3,longlong *param_4)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint *puVar6;
  uint uVar7;
  int *piVar8;
  char *pcVar9;
  undefined1 auStackY_f8 [32];
  int local_a8;
  uint local_a4 [3];
  char local_98 [80];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_a8 = 0;
  local_a4[0] = 0;
  if (param_1[1] != 0) {
    lVar3 = AiQueryPerformanceCounter((undefined8 *)0x0,'\0');
    iVar1 = AiGetFullImagePath(param_1[1],param_1[2],param_1 + 3,(ushort *)(param_1 + 6),
                               (undefined4 *)(param_1 + 10),&local_a8,local_a4);
    AiUpdatePerfTime((longlong *)&DAT_140018670,lVar3,'\0');
    if (iVar1 < 0) {
      return iVar1;
    }
    if ((((local_a4[0] & 4) != 0) || (local_a8 == 2)) || (local_a8 == 0x33)) {
      *(undefined4 *)(param_1 + 0xd) = 1;
    }
  }
  uVar7 = local_a4[0];
  lVar3 = 3;
  if (*param_2 != 0) {
    lVar4 = AiQueryPerformanceCounter((undefined8 *)0x0,'\0');
    if ((((uVar7 & 0x10) == 0) && (param_1[0xb] != 0)) &&
       (iVar1 = AiGetVolumeInfo((wchar_t *)(param_1 + 10),*(undefined8 *)(param_1[2] + 8),
                                param_1 + 8,(undefined4 *)((longlong)param_1 + 0x6c)), iVar1 < 0)) {
      return iVar1;
    }
    AiUpdatePerfTime((longlong *)&DAT_140018680,lVar4,'\0');
    lVar4 = AiQueryPerformanceCounter((undefined8 *)0x0,'\0');
    uVar5 = AiInitializeSoftwarePathMacroList();
    if ((int)uVar5 < 0) {
      return (int)uVar5;
    }
    iVar1 = AiConvertFullImagePathToMacroFormat
                      ((longlong)param_1,(ushort *)(param_1 + 6),(ushort *)*param_1,
                       (undefined4 *)(param_1 + 8),(ushort *)(param_1 + 10),*(int *)(param_1 + 0xd),
                       *(int *)((longlong)param_1 + 0x6c));
    if (iVar1 < 0) {
      return iVar1;
    }
    if (param_4 != (longlong *)0x0) {
      uVar7 = *(uint *)((longlong)param_1 + 0x29c);
      uVar5 = (ulonglong)uVar7;
      if (4 < uVar7) {
        return -0x7ffffffb;
      }
      *(uint *)((longlong)param_1 + 0x29c) = uVar7 + 1;
      param_1[uVar5 * 5 + 0x3a] = 0x1a0018;
      (param_1 + uVar5 * 5 + 0x3a)[1] = L"APPID://PATH";
      *(undefined2 *)(param_1 + uVar5 * 5 + 0x3c) = 3;
      *(undefined4 *)(param_1 + uVar5 * 5 + 0x3d) = *(undefined4 *)((longlong)param_1 + 0x74);
      param_1[uVar5 * 5 + 0x3e] = param_1[0x10];
      *(undefined4 *)((longlong)param_1 + uVar5 * 0x28 + 0x1e4) = 3;
    }
    AiUpdatePerfTime((longlong *)&DAT_140018690,lVar4,'\0');
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) &&
       (uVar7 = 0, *(int *)((longlong)param_1 + 0x74) != 0)) {
      do {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
          WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                   &WPP_613678cfb9bc3eb3d7e100c284ea9323_Traceguids,
                   (wchar_t *)((ulonglong)uVar7 * 0x10 + param_1[0x10]));
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(uint *)((longlong)param_1 + 0x74));
    }
  }
  if (param_1[1] == 0) {
    iVar1 = 0;
    *(undefined4 *)(param_1 + 0x19) = 0xfffffffe;
    *(undefined4 *)(param_1 + 0x2d) = 0xfffffffe;
    *(undefined4 *)((longlong)param_1 + 0x1a4) = 0xfffffffe;
    goto LAB_14002c271;
  }
  iVar1 = FsRtlGetFileSize();
  if (iVar1 < 0) {
    return iVar1;
  }
  lVar4 = AiQueryPerformanceCounter((undefined8 *)0x0,'\0');
  AipQueryAttributeCache((longlong)param_1,(longlong)param_2);
  pcVar9 = (char *)0x0;
  AiUpdatePerfTime((longlong *)&DAT_1400186a0,lVar4,'\0');
  if (*(int *)(param_1 + 0x19) < 0) {
    return *(int *)(param_1 + 0x19);
  }
  if (param_4 != (longlong *)0x0) {
    uVar7 = 0;
    piVar8 = param_2 + 3;
    do {
      if ((*piVar8 != 0) && (iVar1 = AipAddHashAttribute((longlong)param_1,uVar7), iVar1 < 0)) {
        return iVar1;
      }
      uVar7 = uVar7 + 1;
      piVar8 = piVar8 + 1;
    } while (uVar7 < 3);
  }
  if ((*(int *)(param_1 + 0x26) == 0x14) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
    uVar7 = 0;
    do {
      pcVar9 = "%2.2x";
      lVar4 = 0x41 - (ulonglong)(uVar7 * 2);
      RtlStringCbPrintfA(local_98 + uVar7 * 2,lVar4,"%2.2x",
                         (ulonglong)*(byte *)((ulonglong)uVar7 + 0xec + (longlong)param_1));
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)(param_1 + 0x26));
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) {
      WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar4,pcVar9,local_98);
    }
  }
  if (param_2[1] == 0) {
LAB_14002c092:
    if (param_2[2] != 0) goto LAB_14002c09c;
  }
  else {
    lVar4 = AiQueryPerformanceCounter((undefined8 *)0x0,'\0');
    if (*(char *)(param_1 + 0x34) == '\0') {
      uVar5 = AiGetTrustedPublisherName
                        (param_1[1],param_1[2],pcVar9,*(int *)(param_1 + 0xe),
                         (ushort *)(param_1 + 0x35));
      *(int *)((longlong)param_1 + 0x1a4) = (int)uVar5;
    }
    AiUpdatePerfTime((longlong *)&DAT_1400186c0,lVar4,'\0');
    iVar2 = *(int *)((longlong)param_1 + 0x1a4);
    if (iVar2 < 0) {
      if (iVar2 != -2) {
        return iVar2;
      }
    }
    else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) {
      WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
               &WPP_613678cfb9bc3eb3d7e100c284ea9323_Traceguids,(wchar_t *)(param_1 + 0x35));
    }
    if ((param_2[1] == 0) || (*(int *)((longlong)param_1 + 0x1a4) < 0)) goto LAB_14002c092;
LAB_14002c09c:
    lVar4 = AiQueryPerformanceCounter((undefined8 *)0x0,'\0');
    if (*(int *)(param_1 + 0x2d) < 0) {
      iVar2 = AiGetImageVersionInfo
                        (param_1[1],*(int *)(param_1 + 0xe),param_1[2],
                         (undefined4 *)((longlong)param_1 + 0x16c),(undefined4 *)(param_1 + 0x2e),
                         (undefined4 *)((longlong)param_1 + 0x174),(undefined4 *)(param_1 + 0x2f),
                         (ushort *)(param_1 + 0x30),(ushort *)(param_1 + 0x32));
      *(int *)(param_1 + 0x2d) = iVar2;
    }
    AiUpdatePerfTime((longlong *)&DAT_1400186b0,lVar4,'\0');
    iVar2 = *(int *)(param_1 + 0x2d);
    if (iVar2 < 0) {
      if (iVar2 != -2) {
        return iVar2;
      }
    }
    else {
      if (((param_1[0x31] != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) {
        WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                 &WPP_613678cfb9bc3eb3d7e100c284ea9323_Traceguids,(wchar_t *)(param_1 + 0x30));
      }
      if (param_1[0x33] != 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_14002c258;
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) {
          WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                   &WPP_613678cfb9bc3eb3d7e100c284ea9323_Traceguids,(wchar_t *)(param_1 + 0x32));
        }
      }
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) {
          uVar7 = *(uint *)(param_1 + 0x2e);
          WPP_SF_DDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,(ulonglong)(uVar7 & 0xffff),
                      *(uint *)((longlong)param_1 + 0x16c) >> 0x10,
                      (char)*(uint *)((longlong)param_1 + 0x16c),(char)(uVar7 >> 0x10),(char)uVar7);
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) {
          uVar7 = *(uint *)(param_1 + 0x2f);
          WPP_SF_DDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,(ulonglong)(uVar7 & 0xffff),
                      *(uint *)((longlong)param_1 + 0x174) >> 0x10,
                      (char)*(uint *)((longlong)param_1 + 0x174),(char)(uVar7 >> 0x10),(char)uVar7);
        }
      }
    }
  }
LAB_14002c258:
  if ((param_4 != (longlong *)0x0) && (param_2[1] != 0)) {
    iVar1 = AipAddFQBNAttribute((longlong)param_1);
  }
  if (iVar1 < 0) {
    return iVar1;
  }
LAB_14002c271:
  if (param_4 != (longlong *)0x0) {
    *param_4 = (longlong)(param_1 + 0x53);
  }
  puVar6 = (uint *)(param_2 + 3);
  param_2[1] = ~*(uint *)((longlong)param_1 + 0x1a4) >> 0x1f;
  do {
    *puVar6 = *puVar6 & ~*(uint *)(param_1 + 0x19) >> 0x1f;
    puVar6 = puVar6 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  return iVar1;
}



===== AipFreeImageContext @ 14002c2e0 =====

void AipFreeImageContext(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  
  if (param_1 != 0) {
    if (*(longlong *)(param_1 + 0x198) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x198),0);
    }
    if (*(longlong *)(param_1 + 0x188) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x188),0);
    }
    uVar3 = 0;
    if (*(int *)(param_1 + 0x74) != 0) {
      do {
        lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x80) + 8 + uVar3 * 0x10);
        if (lVar1 != 0) {
          ExFreePoolWithTag(lVar1,0);
        }
        uVar2 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < *(uint *)(param_1 + 0x74));
    }
    lVar1 = *(longlong *)(param_1 + 0x80);
    if ((lVar1 != param_1 + 0x88) && (lVar1 != 0)) {
      ExFreePoolWithTag(lVar1,0);
    }
    if (*(longlong *)(param_1 + 0x38) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x38),0);
    }
    if (*(longlong *)(param_1 + 0x48) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x48),0);
    }
    if (*(longlong *)(param_1 + 0x58) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x58),0);
    }
    if (*(longlong *)(param_1 + 0x1b0) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x1b0),0);
    }
    if (*(longlong *)(param_1 + 0x1c8) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x1c8),0);
    }
    if (*(longlong *)(param_1 + 0x10) != 0) {
      ObfDereferenceObject();
      *(undefined8 *)(param_1 + 0x10) = 0;
    }
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== AipQueryAttributeCache @ 14002c438 =====

void AipQueryAttributeCache(longlong param_1,longlong param_2)

{
  uint *_Str1;
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint local_res10 [2];
  undefined4 *local_res18;
  longlong local_res20;
  undefined8 in_stack_ffffffffffffff80;
  ulonglong in_stack_ffffffffffffff90;
  undefined8 local_50;
  undefined8 uStack_48;
  
  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffff80 >> 0x20);
  local_res10[0] = 0;
  puVar4 = (uint *)0x0;
  puVar5 = (undefined4 *)0x0;
  bVar1 = false;
  piVar7 = (int *)(param_2 + 0xc);
  uVar9 = 0;
  uVar10 = 0;
  uVar8 = 0;
  do {
    if (*piVar7 != 0) {
      uVar9 = 0x160;
      uVar10 = 0x25;
      bVar1 = true;
      goto LAB_14002c495;
    }
    uVar8 = uVar8 + 1;
    piVar7 = piVar7 + 1;
  } while (uVar8 < 3);
  *(undefined4 *)(param_1 + 200) = 0;
LAB_14002c495:
  if (*(int *)(param_2 + 4) == 0) {
    if (*(int *)(param_2 + 8) != 0) goto LAB_14002c4b6;
  }
  else {
    uVar9 = uVar9 + 0x1000;
    uVar10 = (uVar10 + 3 & 0xfffffffc) + 0x27;
LAB_14002c4b6:
    uVar9 = uVar9 + 0x2000;
    uVar10 = (uVar10 + 3 & 0xfffffffc) + 0x28;
  }
  if (uVar9 == 0) {
    return;
  }
  local_res18 = (undefined4 *)0x0;
  local_50 = 0;
  uStack_48 = 0;
  iVar2 = ZwQueryVolumeInformationFile(*(undefined8 *)(param_1 + 8),&local_50,&local_res18,8,4);
  if ((iVar2 < 0) || (((ulonglong)local_res18 & 0x4001100000000) != 0)) {
    iVar2 = 0;
  }
  else {
    iVar2 = 1;
  }
  *(int *)(param_1 + 0x70) = iVar2;
  if (iVar2 == 0) {
LAB_14002c788:
    if (-1 < *(int *)(param_1 + 200)) {
      piVar7 = (int *)(param_2 + 0xc);
      uVar8 = 0;
      do {
        if ((*(int *)((param_1 - param_2) + 0x120 + (longlong)piVar7) == 0) && (*piVar7 != 0)) {
          *(int *)(param_1 + 200) = -2;
          break;
        }
        uVar8 = uVar8 + 1;
        piVar7 = piVar7 + 1;
      } while (uVar8 < 3);
    }
  }
  else {
    puVar4 = (uint *)AiAlloc((ulonglong)uVar9);
    puVar5 = (undefined4 *)AiAlloc((ulonglong)uVar10);
    if ((puVar4 == (uint *)0x0) || (puVar5 == (undefined4 *)0x0)) {
      *(undefined4 *)(param_1 + 200) = 0xc0000017;
      goto LAB_14002c63c;
    }
    local_res20 = 0;
    local_res18 = puVar5;
    if (bVar1) {
      AiAddEaToQueryBuffer
                ("$KERNEL.PURGE.APPID.HASHINFO",&local_res20,puVar5,(longlong *)&local_res18);
    }
    if (((*(int *)(param_2 + 4) != 0) &&
        (AiAddEaToQueryBuffer
                   ("$KERNEL.PURGE.APPID.SIGNERINFO",&local_res20,local_res18,
                    (longlong *)&local_res18), *(int *)(param_2 + 4) != 0)) ||
       (*(int *)(param_2 + 8) != 0)) {
      AiAddEaToQueryBuffer
                ("$KERNEL.PURGE.APPID.VERSIONINFO",&local_res20,local_res18,(longlong *)&local_res18
                );
    }
    iVar2 = FsRtlQueryKernelEaFile
                      (*(undefined8 *)(param_1 + 0x10),puVar4,uVar9,0,puVar5,CONCAT44(uVar3,uVar10),
                       0,in_stack_ffffffffffffff90 & 0xffffffffffffff00,local_res10);
    if (-1 < iVar2) {
      puVar11 = puVar4;
      do {
        _Str1 = puVar11 + 2;
        local_res10[0] =
             (uint)*(ushort *)((longlong)puVar11 + 6) + *(byte *)((longlong)puVar11 + 5) + 9;
        iVar2 = _stricmp((char *)_Str1,"$KERNEL.PURGE.APPID.HASHINFO");
        if (iVar2 == 0) {
          uVar6 = AiGetHashInfoFromCache
                            ((longlong)puVar11,local_res10[0],(void *)(param_1 + 0xcc),
                             (uint *)(param_1 + 300));
          *(int *)(param_1 + 200) = (int)uVar6;
        }
        else {
          iVar2 = _stricmp((char *)_Str1,"$KERNEL.PURGE.APPID.SIGNERINFO");
          if (iVar2 == 0) {
            uVar6 = AiGetTrustedPublisherNameFromCache
                              ((longlong)puVar11,local_res10[0],(undefined1 *)(param_1 + 0x1a0),
                               param_1 + 0x1a8);
            *(int *)(param_1 + 0x1a4) = (int)uVar6;
          }
          else {
            iVar2 = _stricmp((char *)_Str1,"$KERNEL.PURGE.APPID.VERSIONINFO");
            if (iVar2 == 0) {
              uVar3 = AiGetVersionInfoFromCache
                                ((longlong)puVar11,local_res10[0],(undefined4 *)(param_1 + 0x16c),
                                 (undefined4 *)(param_1 + 0x170),(undefined4 *)(param_1 + 0x174),
                                 (undefined4 *)(param_1 + 0x178),(undefined8 *)(param_1 + 0x180),
                                 (undefined8 *)(param_1 + 400));
              *(undefined4 *)(param_1 + 0x168) = uVar3;
            }
          }
        }
      } while ((*puVar11 != 0) &&
              (puVar11 = (uint *)((longlong)puVar11 + (ulonglong)*puVar11), puVar11 != (uint *)0x0))
      ;
      goto LAB_14002c788;
    }
    *(undefined4 *)(param_1 + 0x70) = 0;
  }
  if (*(int *)(param_1 + 200) < 0) {
    iVar2 = AppHashComputeFileHashes
                      (*(undefined8 *)(param_1 + 8),param_2 + 0xc,(void *)(param_1 + 0xcc),
                       param_1 + 300);
    if ((-1 < iVar2) && (*(int *)(param_1 + 0x70) != 0)) {
      AiSetHashInfoInCache
                (*(undefined8 *)(param_1 + 0x10),(uint *)(param_1 + 300),(void *)(param_1 + 0xcc));
    }
    *(int *)(param_1 + 200) = iVar2;
  }
LAB_14002c63c:
  if (puVar4 != (uint *)0x0) {
    ExFreePoolWithTag(puVar4,0);
  }
  if (puVar5 != (undefined4 *)0x0) {
    ExFreePoolWithTag(puVar5,0);
  }
  return;
}



===== AipSetEaFromOrigin @ 14002c7d8 =====

undefined4 AipSetEaFromOrigin(undefined8 param_1,void *param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_2 == (void *)0x0) {
    uVar1 = 0xc000000d;
  }
  else {
    puVar2 = (undefined4 *)AiAlloc((ulonglong)(param_3 + 0x28));
    if (puVar2 == (undefined4 *)0x0) {
      uVar1 = 0xc0000017;
    }
    else {
      *puVar2 = 0;
      *(undefined2 *)(puVar2 + 1) = 0x1f00;
      *(short *)((longlong)puVar2 + 6) = (short)param_3;
      builtin_strncpy((char *)(puVar2 + 2),"$Kernel.",8);
      builtin_strncpy((char *)(puVar2 + 4),"Smartloc",8);
      builtin_strncpy((char *)(puVar2 + 6),"ker.Orig",8);
      builtin_strncpy((char *)(puVar2 + 8),"inClaim",8);
      memmove(puVar2 + 10,param_2,(ulonglong)param_3);
      uVar1 = FsRtlSetKernelEaFile
                        (param_1,puVar2,
                         (uint)*(byte *)((longlong)puVar2 + 5) +
                         *(ushort *)((longlong)puVar2 + 6) + 9);
      ExFreePoolWithTag(puVar2,0);
    }
  }
  return uVar1;
}



===== AipSmartHashImageFile @ 14002c89c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int AipSmartHashImageFile(longlong param_1,longlong param_2,longlong param_3,longlong param_4)

{
  char *pcVar1;
  void *_Buf1;
  uint uVar2;
  int iVar3;
  undefined8 *puVar4;
  longlong lVar5;
  uint *puVar6;
  undefined1 auStackY_c8 [32];
  longlong local_98;
  longlong local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined4 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_48 = 0;
  local_68 = 0;
  puVar4 = (undefined8 *)0x0;
  local_98 = 0;
  local_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_90 = param_4;
  if (param_3 == 0) {
    if (param_1 == 0) {
      lVar5 = 0;
    }
    else {
      lVar5 = *(longlong *)(param_1 + 8);
    }
    iVar3 = AipAllocateImageContext(param_1,param_2,lVar5,&local_98);
    lVar5 = local_98;
    if (iVar3 < 0) goto LAB_14002cac9;
    param_3 = local_98;
  }
  lVar5 = local_98;
  if ((param_1 == 0) || (*(int *)(param_1 + 0x18) != 2)) {
    uStack_50 = CONCAT44(1,(undefined4)uStack_50);
    _Buf1 = (void *)(param_3 + 0xcc);
    if (param_2 == 0) {
      iVar3 = AppHashComputeFileHashesInternal
                        (param_1,*(undefined8 **)(param_1 + 0x10),(longlong)&uStack_50 + 4,_Buf1,
                         param_3 + 300);
      if (iVar3 < 0) goto LAB_14002c961;
      AiSetHashInfoInCache(*(undefined8 *)(param_3 + 0x10),(uint *)(param_3 + 300),_Buf1);
    }
    else {
      AipQueryAttributeCache(param_3,(longlong)&local_58);
      iVar3 = *(int *)(param_3 + 200);
LAB_14002c961:
      if (iVar3 < 0) goto LAB_14002cac9;
    }
    puVar6 = (uint *)(param_3 + 300);
    if (local_90 != 0) {
      if ((*puVar6 != *(uint *)(local_90 + 0x28)) ||
         (iVar3 = memcmp(_Buf1,(void *)(local_90 + 0x2c),(ulonglong)*(uint *)(local_90 + 0x28)),
         iVar3 != 0)) {
        iVar3 = -0x3ffffbd8;
        goto LAB_14002cac9;
      }
      goto LAB_14002ca6f;
    }
    puVar4 = (undefined8 *)AiAlloc((ulonglong)(*puVar6 + 0x2c));
    if (puVar4 == (undefined8 *)0x0) {
      iVar3 = -0x3fffffe9;
      goto LAB_14002cac9;
    }
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    puVar4[3] = 0;
    puVar4[4] = 0;
    puVar4[5] = 0;
    *(undefined1 *)((longlong)puVar4 + 5) = 0x18;
    *(short *)((longlong)puVar4 + 6) = *(short *)puVar6 + 0xb;
    pcVar1 = (char *)(puVar4 + 1);
    pcVar1[0] = '$';
    pcVar1[1] = 'K';
    pcVar1[2] = 'e';
    pcVar1[3] = 'r';
    pcVar1[4] = 'n';
    pcVar1[5] = 'e';
    pcVar1[6] = 'l';
    pcVar1[7] = '.';
    pcVar1 = (char *)(puVar4 + 2);
    pcVar1[0] = 'S';
    pcVar1[1] = 'm';
    pcVar1[2] = 'a';
    pcVar1[3] = 'r';
    pcVar1[4] = 't';
    pcVar1[5] = 'l';
    pcVar1[6] = 'o';
    pcVar1[7] = 'c';
    puVar4[3] = 0x687361482e72656b;
    *(undefined1 *)(puVar4 + 4) = 0;
    *(undefined4 *)((longlong)puVar4 + 0x24) = 0x31484d53;
    uVar2 = *puVar6;
    *(uint *)(puVar4 + 5) = uVar2;
    memmove((void *)((longlong)puVar4 + 0x2c),_Buf1,(ulonglong)uVar2);
    iVar3 = FsRtlSetKernelEaFile
                      (*(undefined8 *)(param_3 + 0x10),puVar4,
                       (uint)*(ushort *)((longlong)puVar4 + 6) + *(byte *)((longlong)puVar4 + 5) + 9
                      );
    if (-1 < iVar3) goto LAB_14002ca6f;
  }
  else {
LAB_14002ca6f:
    local_88 = CONCAT26(4,CONCAT15(0x1f,(undefined5)local_88));
    uStack_80 = 0x2e6c656e72654b24;
    local_78 = 0x6d532e6567727550;
    local_60 = 0x31564d53;
    uStack_70 = 0x656b636f6c747261;
    local_68 = 0x64696c61562e72;
    iVar3 = FsRtlSetKernelEaFile(*(undefined8 *)(param_3 + 0x10),&local_88,0x2c);
    if (puVar4 == (undefined8 *)0x0) goto LAB_14002cac9;
  }
  ExFreePoolWithTag(puVar4,0);
LAB_14002cac9:
  AipFreeImageContext(lVar5);
  return iVar3;
}



===== AiAddEaToQueryBuffer @ 14002cb04 =====

void AiAddEaToQueryBuffer(void *param_1,longlong *param_2,undefined4 *param_3,longlong *param_4)

{
  int *piVar1;
  ulonglong uVar3;
  ulonglong uVar2;
  
  uVar2 = 0xffffffffffffffff;
  do {
    uVar3 = uVar2;
    uVar2 = uVar3 + 1;
  } while (*(char *)((longlong)param_1 + uVar2) != '\0');
  *param_3 = 0;
  *(char *)(param_3 + 1) = (char)uVar2;
  memmove((void *)((longlong)param_3 + 5),param_1,(uVar2 & 0xffffffff) + 1);
  piVar1 = (int *)*param_2;
  if (piVar1 != (int *)0x0) {
    *piVar1 = (int)param_3 - (int)piVar1;
  }
  *param_4 = (ulonglong)((int)uVar3 + 10U & 0xfffffffc) + (longlong)param_3;
  *param_2 = (longlong)param_3;
  return;
}



===== AiSetCacheEaFile @ 14002cb88 =====

void AiSetCacheEaFile(undefined8 param_1,longlong param_2)

{
  FsRtlSetKernelEaFile(param_1,param_2,(uint)*(ushort *)(param_2 + 6) + *(byte *)(param_2 + 5) + 9);
  return;
}



===== AiConvertFullImagePathToMacroFormat @ 14002cbb4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int AiConvertFullImagePathToMacroFormat
              (longlong param_1,ushort *param_2,ushort *param_3,undefined4 *param_4,ushort *param_5,
              int param_6,int param_7)

{
  undefined1 uVar1;
  int iVar2;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  uint uVar3;
  void *pvVar4;
  ushort *puVar5;
  undefined8 *puVar6;
  uint uVar7;
  undefined1 auStack_b8 [32];
  undefined8 local_98;
  void *pvStack_90;
  ulonglong local_88;
  void *pvStack_80;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_b8;
  pvStack_90 = (void *)0x0;
  local_98 = (ulonglong)param_2[1] << 0x10;
  local_88 = 0;
  pvStack_80 = (void *)0x0;
  pvStack_90 = (void *)AiAlloc((ulonglong)param_2[1]);
  if (pvStack_90 == (void *)0x0) {
LAB_14002cc0b:
    iVar2 = -0x3fffffe9;
  }
  else {
    RtlCopyUnicodeString(&local_98,param_2);
    iVar2 = AiAddImagePathWithMacro(param_1,(ushort *)&local_98);
    if (iVar2 < 0) {
LAB_14002cc3a:
      pvVar4 = pvStack_90;
LAB_14002ceba:
      if (pvVar4 == (void *)0x0) {
        return iVar2;
      }
      ExFreePoolWithTag(pvVar4,0);
      return iVar2;
    }
    if ((param_3 != (ushort *)0x0) && (param_3 != param_2)) {
      local_98._0_4_ = CONCAT22(param_3[1],(ushort)local_98);
      pvStack_90 = (void *)AiAlloc((ulonglong)param_3[1]);
      if (pvStack_90 == (void *)0x0) goto LAB_14002cc0b;
      RtlCopyUnicodeString(&local_98,param_3);
      iVar2 = AiAddImagePathWithMacro(param_1,(ushort *)&local_98);
      if (iVar2 < 0) goto LAB_14002cc3a;
    }
    if ((*(longlong *)(param_5 + 4) != 0) &&
       (uVar1 = AipIsPathMacroPrefix(param_2,param_5), (int)CONCAT71(extraout_var,uVar1) != 0)) {
      local_68 = 0;
      uStack_60 = 0;
      local_58 = 0;
      uStack_50 = 0;
      local_78 = *param_4;
      uStack_74 = param_4[1];
      uStack_70 = param_4[2];
      uStack_6c = param_4[3];
      if (param_6 != 0) {
        RtlInitUnicodeString(&local_68,L"%REMOVABLE%");
      }
      if (param_7 != 0) {
        RtlInitUnicodeString(&local_58,L"%HOT%");
      }
      uVar7 = 0;
      puVar5 = (ushort *)&local_78;
      do {
        if (*(longlong *)(puVar5 + 4) != 0) {
          uVar3 = ((uint)*puVar5 - (uint)*param_5) + (uint)*param_2;
          if (0xfffe < uVar3) {
            return -0x3ffffefa;
          }
          local_98._0_4_ = CONCAT22((short)uVar3,(short)uVar3);
          pvStack_90 = (void *)AiAlloc((ulonglong)(uVar3 & 0xffff));
          if (pvStack_90 == (void *)0x0) goto LAB_14002cc0b;
          memmove(pvStack_90,*(void **)(puVar5 + 4),(ulonglong)*puVar5);
          memmove((void *)((ulonglong)*puVar5 + (longlong)pvStack_90),
                  (void *)(*(longlong *)(param_2 + 4) + (ulonglong)*param_5),
                  (ulonglong)*param_2 - (ulonglong)*param_5);
          iVar2 = AiAddImagePathWithMacro(param_1,(ushort *)&local_98);
          if (iVar2 < 0) goto LAB_14002cc3a;
        }
        uVar7 = uVar7 + 1;
        puVar5 = puVar5 + 8;
      } while (uVar7 < 3);
    }
    for (puVar6 = DAT_1400185d8; (undefined8 **)puVar6 != &DAT_1400185d8;
        puVar6 = (undefined8 *)*puVar6) {
      if ((*(uint *)(puVar6 + 2) & 8) == 0) {
        iVar2 = AipConvertToNtPath(puVar6 + 5,&local_88);
        if (iVar2 < 0) {
          return iVar2;
        }
      }
      else {
        local_88 = puVar6[5];
        pvStack_80 = (void *)puVar6[6];
      }
      uVar1 = AipIsPathMacroPrefix(param_2,(ushort *)&local_88);
      if ((int)CONCAT71(extraout_var_00,uVar1) != 0) {
        uVar7 = ((uint)*(ushort *)(puVar6 + 3) - (uint)(ushort)local_88) + (uint)*param_2;
        if (0xfffe < uVar7) {
          iVar2 = -0x3ffffefa;
          pvVar4 = pvStack_80;
          if (pvStack_80 == (void *)puVar6[6]) {
            return -0x3ffffefa;
          }
          goto LAB_14002ceba;
        }
        local_98._0_4_ = CONCAT22((short)uVar7,(short)uVar7);
        pvStack_90 = (void *)AiAlloc((ulonglong)(uVar7 & 0xffff));
        if (pvStack_90 == (void *)0x0) {
          iVar2 = -0x3fffffe9;
        }
        else {
          memmove(pvStack_90,(void *)puVar6[4],(ulonglong)*(ushort *)(puVar6 + 3));
          memmove((void *)((ulonglong)*(ushort *)(puVar6 + 3) + (longlong)pvStack_90),
                  (void *)((local_88 & 0xffff) + *(longlong *)(param_2 + 4)),
                  (ulonglong)*param_2 - (local_88 & 0xffff));
          iVar2 = AiAddImagePathWithMacro(param_1,(ushort *)&local_98);
          if ((iVar2 < 0) && (pvStack_90 != (void *)0x0)) {
            ExFreePoolWithTag(pvStack_90,0);
          }
        }
      }
      if ((pvStack_80 != (void *)puVar6[6]) && (pvStack_80 != (void *)0x0)) {
        ExFreePoolWithTag(pvStack_80,0);
      }
      if (iVar2 < 0) {
        return iVar2;
      }
    }
  }
  return iVar2;
}



===== AiGetCatalogLastWriteTime @ 14002cef4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int AiGetCatalogLastWriteTime(void)

{
  int iVar1;
  undefined1 auStack_f8 [32];
  undefined8 local_d8;
  undefined4 local_d0;
  undefined4 local_c8;
  undefined4 local_c0;
  undefined4 local_b8;
  undefined8 local_b0;
  undefined4 local_a8;
  longlong local_98 [2];
  wchar_t *local_88;
  longlong local_80 [4];
  longlong *local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_f8;
  local_a8 = 0;
  local_b0 = 0;
  local_80[3] = 0;
  local_80[2] = 0x30;
  local_54 = 0;
  local_98[0] = 0;
  local_20 = 0;
  local_88 = L"\\SystemRoot\\System32\\CatRoot\\{F750E6C3-38EE-11D1-85E5-00C04FC295EE}\\";
  local_60 = local_98 + 1;
  local_b8 = 1;
  local_c0 = 1;
  local_c8 = 7;
  local_98[1] = 0x8a0088;
  local_d0 = 0x80;
  local_d8 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_58 = 0x240;
  local_30 = 0;
  uStack_28 = 0;
  local_80[0] = 0;
  local_80[1] = 0;
  local_50 = 0;
  uStack_48 = 0;
  iVar1 = ZwCreateFile(local_98,0x80,local_98 + 5,local_98 + 3);
  if (-1 < iVar1) {
    local_d8 = CONCAT44(local_d8._4_4_,4);
    local_80[0] = 0;
    local_80[1] = 0;
    iVar1 = ZwQueryInformationFile(local_98[0],local_98 + 3,&local_40,0x28);
    if (-1 < iVar1) {
      DAT_140018340 = local_30;
    }
  }
  if (local_98[0] != 0) {
    ZwClose();
  }
  return iVar1;
}



===== AiGetFileNameFromPath @ 14002d02c =====

ushort AiGetFileNameFromPath(ushort *param_1)

{
  ushort uVar1;
  longlong lVar2;
  wchar_t *_Str;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  ulonglong uVar5;
  ushort uVar6;
  longlong lVar7;
  
  uVar6 = 0;
  if (((param_1 != (ushort *)0x0) && (*param_1 != 0)) && (*(longlong *)(param_1 + 4) != 0)) {
    _Str = (wchar_t *)AiAlloc((ulonglong)*param_1 + 2);
    if (_Str != (wchar_t *)0x0) {
      uVar6 = *param_1;
      uVar5 = (ulonglong)uVar6 + 2 >> 1;
      if (uVar5 - 1 < 0x7fff) {
        if (((((uVar6 & 1) == 0) && (uVar1 = param_1[1], (uVar1 & 1) == 0)) &&
            ((uVar6 <= uVar1 && (uVar1 != 0xffff)))) &&
           ((*(longlong *)(param_1 + 4) != 0 || ((uVar6 == 0 && (uVar1 == 0)))))) {
          lVar2 = *(longlong *)(param_1 + 4);
          lVar7 = (uVar6 >> 1) - uVar5;
          pwVar4 = _Str;
          do {
            if (lVar7 + uVar5 == 0) break;
            *pwVar4 = *(wchar_t *)((lVar2 - (longlong)_Str) + (longlong)pwVar4);
            pwVar4 = pwVar4 + 1;
            uVar5 = uVar5 - 1;
          } while (uVar5 != 0);
          pwVar3 = pwVar4 + -1;
          if (uVar5 != 0) {
            pwVar3 = pwVar4;
          }
          *pwVar3 = L'\0';
          if (uVar5 != 0) {
            uVar6 = *param_1 >> 1;
            pwVar4 = wcsrchr(_Str,L'\\');
            if (pwVar4 != (wchar_t *)0x0) {
              uVar6 = uVar6 - (short)((longlong)pwVar4 + (2 - (longlong)_Str) >> 1);
            }
            ExFreePoolWithTag(_Str,0);
            goto LAB_14002d15d;
          }
        }
        else {
          *_Str = L'\0';
        }
      }
      ExFreePoolWithTag(_Str,0);
    }
    uVar6 = 0;
  }
LAB_14002d15d:
  return uVar6;
}



===== AiGetFullImagePath @ 14002d194 =====

int AiGetFullImagePath(undefined8 param_1,undefined8 param_2,undefined8 *param_3,ushort *param_4,
                      undefined4 *param_5,undefined4 *param_6,undefined4 *param_7)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  uint *puVar4;
  undefined2 *puVar5;
  longlong lVar6;
  longlong local_res18;
  undefined8 local_res20;
  undefined8 local_48;
  undefined8 uStack_40;
  
  local_res18 = 0;
  local_res20 = 0;
  param_4[4] = 0;
  param_4[5] = 0;
  param_4[6] = 0;
  param_4[7] = 0;
  local_48 = 0;
  uStack_40 = 0;
  if (param_5 != (undefined4 *)0x0) {
    *(undefined8 *)(param_5 + 2) = 0;
  }
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
    param_3[1] = 0;
    param_3[2] = 0;
  }
  iVar3 = ZwQueryVolumeInformationFile(0,&local_48,&local_res20,8,4);
  if (iVar3 < 0) goto LAB_14002d418;
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = (undefined4)local_res20;
  }
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = local_res20._4_4_;
  }
  if ((local_res20 & 0x1000000000) == 0) {
    iVar3 = FltGetFileNameInformationUnsafe(param_2,0,0x101,&local_res18);
    if (iVar3 < 0) goto LAB_14002d418;
    uVar2 = *(ushort *)(local_res18 + 10);
    param_4[1] = uVar2;
    lVar6 = AiAlloc((ulonglong)uVar2);
    *(longlong *)(param_4 + 4) = lVar6;
    if (lVar6 != 0) {
      RtlCopyUnicodeString(param_4,local_res18 + 8);
      if (param_5 != (undefined4 *)0x0) {
        uVar2 = *(ushort *)(local_res18 + 0x1a);
        *(ushort *)((longlong)param_5 + 2) = uVar2;
        lVar6 = AiAlloc((ulonglong)uVar2);
        *(longlong *)(param_5 + 2) = lVar6;
        if (lVar6 == 0) {
          iVar3 = -0x3fffffe9;
          if (*(longlong *)(param_4 + 4) != 0) {
            ExFreePoolWithTag(*(longlong *)(param_4 + 4),0);
          }
          param_4[4] = 0;
          param_4[5] = 0;
          param_4[6] = 0;
          param_4[7] = 0;
          goto LAB_14002d418;
        }
        RtlCopyUnicodeString(param_5,local_res18 + 0x18);
      }
      if (param_3 != (undefined8 *)0x0) {
        AipGetImageId(param_1,(wchar_t *)(local_res18 + 0x18),param_3);
      }
      goto LAB_14002d418;
    }
  }
  else {
    puVar4 = (uint *)AiAlloc(0x210);
    if (puVar4 != (uint *)0x0) {
      iVar3 = ZwQueryInformationFile(param_1,&local_48,puVar4,0x210,9);
      if (iVar3 == -0x7ffffffb) {
        uVar1 = *puVar4;
        ExFreePoolWithTag(puVar4,0);
        puVar4 = (uint *)AiAlloc((ulonglong)(uVar1 + 8));
        if (puVar4 == (uint *)0x0) goto LAB_14002d24d;
        iVar3 = ZwQueryInformationFile(param_1,&local_48,puVar4,uVar1 + 8,9);
      }
      if (-1 < iVar3) {
        if (*puVar4 < 0xfffe) {
          uVar2 = (short)*puVar4 + 2;
          *param_4 = uVar2;
          param_4[1] = uVar2;
          puVar5 = (undefined2 *)AiAlloc((ulonglong)uVar2);
          *(undefined2 **)(param_4 + 4) = puVar5;
          if (puVar5 == (undefined2 *)0x0) {
            iVar3 = -0x3fffffe9;
          }
          else {
            *puVar5 = 0x5c;
            memmove((void *)(*(longlong *)(param_4 + 4) + 2),puVar4 + 1,(ulonglong)*puVar4);
            if (param_5 != (undefined4 *)0x0) {
              *param_5 = 0;
              *(undefined8 *)(param_5 + 2) = 0;
            }
          }
        }
        else {
          iVar3 = -0x3fffffff;
        }
        if (puVar4 == (uint *)0x0) goto LAB_14002d418;
      }
      ExFreePoolWithTag(puVar4,0);
      goto LAB_14002d418;
    }
  }
LAB_14002d24d:
  iVar3 = -0x3fffffe9;
LAB_14002d418:
  if (local_res18 != 0) {
    FltReleaseFileNameInformation();
  }
  return iVar3;
}



===== AiGetVolumeInfo @ 14002d450 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int AiGetVolumeInfo(wchar_t *param_1,undefined8 param_2,undefined8 *param_3,undefined4 *param_4)

{
  int iVar1;
  char cVar2;
  int iVar3;
  void *pvVar4;
  longlong lVar5;
  undefined1 auStack_f8 [32];
  longlong local_a8;
  undefined4 local_a0;
  uint uStack_9c;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  wchar_t *local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  ulonglong uStack_58;
  undefined8 local_50;
  undefined4 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_f8;
  param_3[1] = 0;
  local_a8 = 0;
  local_60 = 0;
  uStack_58 = uStack_58 & 0xffffffff00000000;
  local_98 = 0;
  local_50 = 0;
  local_48 = 0;
  iVar3 = 0;
  local_a0 = 0;
  uStack_9c = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_70 = (wchar_t *)0x0;
  uStack_68 = 0;
  local_90 = 0;
  uStack_88 = 0;
  cVar2 = RtlEqualUnicodeString(0,&DAT_1400185b8,1);
  pvVar4 = DAT_1400185b0;
  if (cVar2 == '\0') {
    iVar3 = IoVolumeDeviceToDosName(param_2,param_3);
    if (iVar3 < 0) goto LAB_14002d735;
    local_80 = CONCAT44(local_80._4_4_,0x30);
    uStack_78 = 0;
    uStack_68 = CONCAT44(uStack_68._4_4_,0x240);
    local_60 = 0;
    uStack_58 = 0;
    local_70 = param_1;
    iVar3 = ZwOpenFile(&local_a8,0x100000,&local_80,&local_90);
    if (iVar3 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
        WPP_SF_ZD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                  &WPP_4cd721467131356aabb007ed23ab7199_Traceguids,param_1,(char)iVar3);
      }
      goto LAB_14002d735;
    }
    *param_4 = 0;
    iVar3 = ZwDeviceIoControlFile(local_a8,0,0,0);
    if (-1 < iVar3) {
      if ((local_98._5_1_ == '\0') && (local_98._6_1_ == '\0')) goto LAB_14002d735;
      *param_4 = 1;
      iVar3 = ZwDeviceIoControlFile(local_a8,0,0,0);
      if (-1 < iVar3) {
        if (uStack_9c < 0x28) {
          uStack_9c = 0x28;
        }
        lVar5 = AiAlloc((ulonglong)uStack_9c);
        if (lVar5 != 0) {
          iVar3 = ZwDeviceIoControlFile(local_a8,0,0,0);
          if ((-1 < iVar3) &&
             ((((iVar1 = *(int *)(lVar5 + 0x1c), iVar1 == 1 || (iVar1 == 3)) || (iVar1 == 6)) ||
              ((iVar1 == 8 || (iVar1 == 0xb)))))) {
            *param_4 = 0;
          }
          ExFreePoolWithTag(lVar5,0);
          goto LAB_14002d735;
        }
        goto LAB_14002d509;
      }
    }
    if ((iVar3 != -0x3fffffe9) && (iVar3 != -0x3fffff66)) {
      iVar3 = 0;
    }
  }
  else {
    *param_3 = _DAT_1400185a8;
    param_3[1] = pvVar4;
    pvVar4 = (void *)AiAlloc((ulonglong)*(ushort *)((longlong)param_3 + 2));
    param_3[1] = pvVar4;
    if (pvVar4 != (void *)0x0) {
      memmove(pvVar4,DAT_1400185b0,(ulonglong)*(ushort *)((longlong)param_3 + 2));
      *param_4 = 0;
      goto LAB_14002d735;
    }
LAB_14002d509:
    iVar3 = -0x3fffffe9;
  }
LAB_14002d735:
  if (local_a8 != 0) {
    ZwClose();
  }
  if ((iVar3 < 0) && (param_3[1] != 0)) {
    ExFreePoolWithTag(param_3[1],0);
    param_3[1] = 0;
  }
  return iVar3;
}



===== AiInitializeLastWriteTime @ 14002d790 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void AiInitializeLastWriteTime(void)

{
  int iVar1;
  undefined8 in_stack_ffffffffffffff88;
  undefined4 uVar2;
  undefined8 in_stack_ffffffffffffff90;
  uint uVar3;
  undefined8 local_58;
  wchar_t *local_50;
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
  
  uVar2 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
  uVar3 = (uint)((ulonglong)in_stack_ffffffffffffff90 >> 0x20);
  _DAT_140018348 = 0;
  local_1c = 0;
  local_34 = 0;
  local_50 = L"\\SystemRoot\\System32\\CatRoot\\{F750E6C3-38EE-11D1-85E5-00C04FC295EE}\\";
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0x8a0088;
  iVar1 = AiGetCatalogLastWriteTime();
  if (-1 < iVar1) {
    local_28 = &local_58;
    local_30 = 0;
    local_38 = 0x30;
    local_20 = 0x240;
    local_18 = 0;
    uStack_10 = 0;
    iVar1 = ZwOpenFile(&DAT_140018350,0x80100000,&local_38,&local_48,CONCAT44(uVar2,7),
                       (ulonglong)uVar3 << 0x20);
    if (-1 < iVar1) {
      PsCreateSystemThread(&DAT_140018358,0x1fffff,0,0,0,AipCatalogUpdateThread,0);
    }
  }
  return;
}



===== AiInitializeSoftwarePathMacroList @ 14002d874 =====

ulonglong AiInitializeSoftwarePathMacroList(void)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  undefined **ppuVar5;
  wchar_t local_48 [4];
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  wchar_t local_18 [8];
  
  local_18[0] = L'\0';
  local_18[1] = L'\0';
  local_18[2] = L'\0';
  local_18[3] = L'\0';
  local_18[4] = L'\0';
  local_18[5] = L'\0';
  local_18[6] = L'\0';
  local_18[7] = L'\0';
  local_28 = 0;
  uStack_20 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_48[0] = L'\0';
  local_48[1] = L'\0';
  local_48[2] = L'\0';
  local_48[3] = L'\0';
  lStack_40 = 0;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&DAT_1400185d0,0);
  if (AipPathMacroList == 0) {
    uVar4 = 0;
    ppuVar5 = &PTR_u__Registry_Machi_140018048;
    do {
      if ((*(int *)(ppuVar5 + 2) == 0) &&
         ((*(int *)((longlong)ppuVar5 + 0x14) == 0 || (DAT_1400185a4 != 0)))) {
        RtlInitUnicodeString(&local_28,*ppuVar5);
        RtlInitUnicodeString(&local_38,ppuVar5[1]);
        lStack_40 = 0;
        uVar1 = AiRegReadStringValue(0,&local_28,&local_38,local_48);
        if ((int)uVar1 < 0) {
          uVar3 = 0;
          if (uVar1 != 0xc0000034) {
            uVar3 = (ulonglong)uVar1;
          }
          goto LAB_14002d993;
        }
        RtlInitUnicodeString(local_18,ppuVar5[-1]);
        uVar1 = AipAddPathMacro(local_18,local_48,0xe);
        uVar3 = (ulonglong)uVar1;
        if ((int)uVar1 < 0) {
          if (lStack_40 != 0) {
            ExFreePoolWithTag(lStack_40,0);
          }
          goto LAB_14002d993;
        }
        *(undefined4 *)(ppuVar5 + 2) = 1;
      }
      uVar4 = uVar4 + 1;
      ppuVar5 = ppuVar5 + 4;
    } while (uVar4 < 2);
    uVar2 = AipExpandPathMacros();
    uVar3 = uVar2 & 0xffffffff;
    if (-1 < (int)uVar2) {
      AipPathMacroList = 1;
    }
  }
  else {
    uVar3 = 0;
  }
LAB_14002d993:
  ExReleasePushLockExclusiveEx(&DAT_1400185d0,0);
  KeLeaveCriticalRegion();
  return uVar3;
}



===== AipAddPathMacro @ 14002d9f8 =====

int AipAddPathMacro(wchar_t *param_1,wchar_t *param_2,uint param_3)

{
  longlong lVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char cVar6;
  int iVar7;
  longlong *plVar8;
  undefined8 *puVar9;
  undefined4 in_register_00000084;
  wchar_t local_18 [4];
  longlong lStack_10;
  
  local_18[0] = L'\0';
  local_18[1] = L'\0';
  local_18[2] = L'\0';
  local_18[3] = L'\0';
  lStack_10 = 0;
  iVar7 = 0;
  cVar6 = RtlEqualUnicodeString
                    (0,param_2,CONCAT71((int7)(CONCAT44(in_register_00000084,param_3) >> 8),1));
  if (cVar6 == '\0') {
    plVar8 = (longlong *)ExAllocatePool2(0x102,0x38,0x44497041);
    if (plVar8 == (longlong *)0x0) {
      iVar7 = -0x3fffffe9;
    }
    else {
      if ((param_3 & 8) != 0) {
        iVar7 = AipConvertToNtPath((ulonglong *)param_2,(ulonglong *)local_18);
        if (iVar7 < 0) {
          ExFreePoolWithTag(plVar8,0);
          return iVar7;
        }
        lVar1 = *(longlong *)(param_2 + 4);
        if (lStack_10 != lVar1) {
          if ((param_3 & 2) != 0) {
            if (lVar1 != 0) {
              ExFreePoolWithTag(lVar1,0);
            }
            param_2[4] = L'\0';
            param_2[5] = L'\0';
            param_2[6] = L'\0';
            param_2[7] = L'\0';
          }
          param_3 = param_3 | 2;
          param_2 = local_18;
        }
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) {
        WPP_SF_ZZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                  &WPP_4cd721467131356aabb007ed23ab7199_Traceguids,param_1,param_2);
      }
      *(uint *)(plVar8 + 2) = param_3;
      lVar1 = *(longlong *)(param_1 + 4);
      plVar8[3] = *(longlong *)param_1;
      plVar8[4] = lVar1;
      if ((param_3 & 1) != 0) {
        param_1[4] = L'\0';
        param_1[5] = L'\0';
        param_1[6] = L'\0';
        param_1[7] = L'\0';
      }
      uVar3 = *(undefined4 *)(param_2 + 2);
      uVar4 = *(undefined4 *)(param_2 + 4);
      uVar5 = *(undefined4 *)(param_2 + 6);
      *(undefined4 *)(plVar8 + 5) = *(undefined4 *)param_2;
      *(undefined4 *)((longlong)plVar8 + 0x2c) = uVar3;
      *(undefined4 *)(plVar8 + 6) = uVar4;
      *(undefined4 *)((longlong)plVar8 + 0x34) = uVar5;
      if ((param_3 & 2) != 0) {
        param_2[4] = L'\0';
        param_2[5] = L'\0';
        param_2[6] = L'\0';
        param_2[7] = L'\0';
      }
      puVar9 = &DAT_1400185d8;
      if ((longlong **)DAT_1400185d8[1] != &DAT_1400185d8) {
        puVar9 = (undefined8 *)0x3;
        pcVar2 = (code *)swi(0x29);
        DAT_1400185d8 = (longlong *)(*pcVar2)();
      }
      *plVar8 = (longlong)DAT_1400185d8;
      plVar8[1] = (longlong)puVar9;
      DAT_1400185d8[1] = (longlong)plVar8;
      DAT_1400185d8 = plVar8;
    }
  }
  else {
    iVar7 = -0x3ffffff3;
  }
  return iVar7;
}



===== AipCatalogUpdateThread @ 14002db80 =====

void AipCatalogUpdateThread(void)

{
  int iVar1;
  undefined8 local_18;
  undefined8 uStack_10;
  
  while( true ) {
    local_18 = 0;
    uStack_10 = 0;
    iVar1 = ZwNotifyChangeDirectoryFile(DAT_140018350,0,0,0,&local_18,0,0,0x11,1);
    if (iVar1 < 0) {
      iVar1 = KeDelayExecutionThread(0);
    }
    else {
      iVar1 = ZwWaitForSingleObject(DAT_140018350);
    }
    if (iVar1 == 0x101) break;
    ExAcquirePushLockExclusiveEx(&DAT_140018348);
    AiGetCatalogLastWriteTime();
    ExReleasePushLockExclusiveEx(&DAT_140018348);
  }
  return;
}



===== AipConvertToNtPath @ 14002dc4c =====

int AipConvertToNtPath(ulonglong *param_1,ulonglong *param_2)

{
  ushort uVar1;
  short sVar2;
  ulonglong uVar3;
  wchar_t *pwVar4;
  ushort uVar5;
  int iVar6;
  longlong lVar7;
  uint local_res8 [2];
  longlong local_res18;
  longlong local_res20;
  undefined8 local_78;
  wchar_t *pwStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 *local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong uStack_30;
  
  pwStack_70 = (wchar_t *)0x0;
  uVar1 = (ushort)*param_1;
  local_38 = 0;
  lVar7 = 0;
  uStack_30 = uStack_30 & 0xffffffff00000000;
  local_res18 = 0;
  local_res8[0] = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = (undefined8 *)0x0;
  uStack_40 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (uVar1 < 4) {
    return -0x3ffffff3;
  }
  sVar2 = ((short *)param_1[1])[1];
  if (sVar2 == 0x3a) {
    uVar5 = uVar1 + 8;
    if (uVar5 < uVar1) {
      return -0x3fffff6b;
    }
    local_78._0_4_ = CONCAT22(uVar5,uVar5);
    local_78 = (ulonglong)(uint)local_78;
    pwStack_70 = (wchar_t *)AiAlloc((ulonglong)uVar5);
    if (pwStack_70 == (wchar_t *)0x0) {
      iVar6 = -0x3fffffe9;
      goto LAB_14002df20;
    }
    builtin_wcsncpy(pwStack_70,L"\\??\\",4);
    memmove(pwStack_70 + 4,(void *)param_1[1],(ulonglong)(ushort)*param_1);
  }
  else {
    if ((*(short *)param_1[1] == 0x5c) && (sVar2 == 0x5c)) {
      uVar3 = param_1[1];
      *param_2 = *param_1;
      param_2[1] = uVar3;
      return 0;
    }
    local_78 = *param_1;
    pwStack_70 = (wchar_t *)param_1[1];
  }
  local_48 = &local_78;
  local_58 = CONCAT44(local_58._4_4_,0x30);
  uStack_50 = 0;
  uStack_40 = CONCAT44(uStack_40._4_4_,0x240);
  local_38 = 0;
  uStack_30 = 0;
  iVar6 = ZwOpenFile(&local_res18,0x100080,&local_58,&local_68,7,0x21);
  if (iVar6 < 0) {
LAB_14002ddf3:
    do {
      if (local_res18 != 0) {
        ZwClose();
        local_res18 = 0;
      }
      local_48 = &local_78;
      local_58 = CONCAT44(local_58._4_4_,0x30);
      uStack_50 = 0;
      uStack_40 = CONCAT44(uStack_40._4_4_,0x240);
      local_38 = 0;
      uStack_30 = 0;
      iVar6 = ZwOpenSymbolicLinkObject(&local_res18,1,&local_58);
      pwVar4 = pwStack_70;
      if (iVar6 < 0) {
        iVar6 = 0;
        pwStack_70 = (wchar_t *)0x0;
        *param_2 = local_78;
        param_2[1] = (ulonglong)pwVar4;
        break;
      }
      if (pwStack_70 == (wchar_t *)param_1[1]) {
        local_78._0_4_ = (uint)(ushort)local_78;
        pwStack_70 = (wchar_t *)0x0;
      }
      iVar6 = ZwQuerySymbolicLinkObject(local_res18,&local_78,local_res8);
      if (iVar6 == -0x3fffffdd) {
        if (0xffff < local_res8[0]) {
          iVar6 = -0x3fffffff;
          break;
        }
        if (pwStack_70 != (wchar_t *)0x0) {
          ExFreePoolWithTag(pwStack_70,0);
        }
        local_78._0_4_ = CONCAT22((short)local_res8[0],(ushort)local_78);
        pwStack_70 = (wchar_t *)AiAlloc((ulonglong)(local_res8[0] & 0xffff));
        if (pwStack_70 == (wchar_t *)0x0) {
          iVar6 = -0x3fffffe9;
          break;
        }
        iVar6 = ZwQuerySymbolicLinkObject(local_res18,&local_78,local_res8);
      }
    } while (-1 < iVar6);
  }
  else {
    local_res20 = 0;
    iVar6 = ObReferenceObjectByHandle
                      (local_res18,0,*(undefined8 *)IoFileObjectType_exref,0,&local_res20,0);
    lVar7 = local_res20;
    if ((-1 < iVar6) &&
       (iVar6 = AiGetFullImagePath(local_res18,local_res20,(undefined8 *)0x0,(ushort *)param_2,
                                   (undefined4 *)0x0,(undefined4 *)0x0,(undefined4 *)0x0), iVar6 < 0
       )) goto LAB_14002ddf3;
  }
  if (lVar7 != 0) {
    ObfDereferenceObject(lVar7);
  }
LAB_14002df20:
  if (local_res18 != 0) {
    ZwClose(local_res18);
  }
  if ((pwStack_70 != (wchar_t *)0x0) && (pwStack_70 != (wchar_t *)param_1[1])) {
    ExFreePoolWithTag(pwStack_70,0);
  }
  return iVar6;
}



===== AipExpandPathMacros @ 14002df78 =====

undefined8 AipExpandPathMacros(void)

{
  ushort *puVar1;
  ushort *puVar2;
  bool bVar3;
  undefined1 uVar4;
  undefined7 extraout_var;
  void *_Dst;
  ushort uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined4 local_28;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  puVar6 = DAT_1400185d8;
  do {
    if ((undefined8 **)puVar6 == &DAT_1400185d8) {
      return 0;
    }
    if ((*(uint *)(puVar6 + 2) & 4) == 0) {
      do {
        bVar3 = false;
        puVar7 = DAT_1400185d8;
        if ((undefined8 **)DAT_1400185d8 == &DAT_1400185d8) break;
        do {
          if (puVar7 != puVar6) {
            puVar1 = (ushort *)(puVar7 + 3);
            puVar2 = (ushort *)(puVar6 + 5);
            uVar4 = AipIsPathMacroPrefix(puVar2,puVar1);
            if ((int)CONCAT71(extraout_var,uVar4) != 0) {
              uVar5 = (*(short *)(puVar7 + 5) - *puVar1) + *puVar2;
              local_28 = CONCAT22(uVar5,uVar5);
              _Dst = (void *)AiAlloc((ulonglong)uVar5);
              if (_Dst == (void *)0x0) {
                return 0xc0000017;
              }
              memmove(_Dst,(void *)puVar7[6],(ulonglong)*(ushort *)(puVar7 + 5));
              memmove((void *)((ulonglong)*(ushort *)(puVar7 + 5) + (longlong)_Dst),
                      (void *)((ulonglong)*puVar1 + puVar6[6]),
                      (ulonglong)*puVar2 - (ulonglong)*puVar1);
              if (((*(uint *)(puVar6 + 2) & 2) != 0) && (puVar6[6] != 0)) {
                ExFreePoolWithTag(puVar6[6],0);
              }
              uStack_20 = SUB84(_Dst,0);
              uStack_1c = (undefined4)((ulonglong)_Dst >> 0x20);
              *(uint *)(puVar6 + 2) = *(uint *)(puVar6 + 2) | 2;
              bVar3 = true;
              *(undefined4 *)puVar2 = local_28;
              *(undefined4 *)((longlong)puVar6 + 0x2c) = 0;
              *(undefined4 *)(puVar6 + 6) = uStack_20;
              *(undefined4 *)((longlong)puVar6 + 0x34) = uStack_1c;
            }
          }
          puVar7 = (undefined8 *)*puVar7;
        } while ((undefined8 **)puVar7 != &DAT_1400185d8);
      } while (bVar3);
    }
    puVar6 = (undefined8 *)*puVar6;
  } while( true );
}



===== AipGetImageId @ 14002e0cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int AipGetImageId(undefined8 param_1,wchar_t *param_2,undefined8 *param_3)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined2 uVar4;
  undefined1 auStack_368 [32];
  longlong local_310 [3];
  undefined8 local_2f8;
  undefined8 uStack_2f0;
  wchar_t *local_2e8;
  undefined8 uStack_2e0;
  undefined8 local_2d8;
  ulonglong uStack_2d0;
  longlong local_2c8 [9];
  undefined8 local_280;
  undefined8 local_270;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_368;
  local_310[0] = 0;
  local_2d8 = 0;
  uStack_2d0 = uStack_2d0 & 0xffffffff00000000;
  local_2f8 = 0;
  uStack_2f0 = 0;
  local_2e8 = (wchar_t *)0x0;
  uStack_2e0 = 0;
  local_310[1] = 0;
  local_310[2] = 0;
  memset(local_2c8,0,0x40);
  cVar1 = RtlEqualUnicodeString(param_2,&DAT_1400185b8,1);
  if ((cVar1 == '\0') || (DAT_1400185c8 == 0)) {
    uStack_2f0 = 0;
    local_2f8 = CONCAT44(local_2f8._4_4_,0x30);
    uStack_2e0 = CONCAT44(uStack_2e0._4_4_,0x240);
    local_2d8 = 0;
    uStack_2d0 = 0;
    local_2e8 = param_2;
    iVar2 = ZwOpenFile(local_310,0x80100000,&local_2f8,local_310 + 1);
    if (iVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) goto LAB_14002e2fb;
      uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      uVar4 = 0xc;
    }
    else {
      iVar2 = ZwFsControlFile(local_310[0],0,0,0);
      if (-1 < iVar2) {
        param_3[2] = local_2c8[0];
        if (cVar1 != '\0') {
          DAT_1400185c8 = local_2c8[0];
        }
        goto LAB_14002e29a;
      }
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) goto LAB_14002e2fb;
      uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      uVar4 = 0xd;
    }
    WPP_SF_ZD(uVar3,uVar4,&WPP_4cd721467131356aabb007ed23ab7199_Traceguids,param_2,(char)iVar2);
  }
  else {
    param_3[2] = DAT_1400185c8;
LAB_14002e29a:
    iVar2 = ZwFsControlFile(param_1,0,0,0);
    if (-1 < iVar2) {
      param_3[1] = local_270;
      *param_3 = local_280;
    }
  }
LAB_14002e2fb:
  if (local_310[0] != 0) {
    ZwClose();
  }
  return iVar2;
}



===== AipIsPathMacroPrefix @ 14002e340 =====

undefined1 AipIsPathMacroPrefix(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  undefined1 uVar2;
  ulonglong uVar3;
  
  uVar1 = *param_2;
  uVar3 = (ulonglong)uVar1;
  if (*param_1 < uVar1) {
    uVar2 = 0;
  }
  else {
    if (uVar1 + 1 < (uint)*param_1) {
      uVar1 = *(ushort *)(*(longlong *)(param_1 + 4) + (ulonglong)(uVar1 >> 1) * 2);
      uVar3 = (ulonglong)uVar1;
      if ((uVar1 != 0x5c) && (uVar1 != 0)) {
        return 0;
      }
    }
    uVar2 = RtlPrefixUnicodeString(param_2,param_1,CONCAT71((int7)(uVar3 >> 8),1));
  }
  return uVar2;
}



===== AiCapturePackageMoniker @ 14002e3a4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int AiCapturePackageMoniker(undefined8 param_1,undefined1 *param_2,longlong param_3,short *param_4)

{
  int iVar1;
  undefined8 uVar2;
  void *_Dst;
  char *pcVar3;
  undefined1 *puVar4;
  char *pcVar5;
  undefined1 auStack_198 [32];
  undefined8 local_178;
  undefined8 local_170;
  undefined8 local_168;
  undefined8 local_160;
  char local_158 [4];
  int local_154;
  ulonglong local_150;
  undefined1 local_148 [256];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_198;
  iVar1 = 0;
  local_150 = 0x100;
  local_154 = 0;
  *param_2 = 0;
  param_4[0] = 0;
  param_4[1] = 0;
  param_4[2] = 0;
  param_4[3] = 0;
  param_4[4] = 0;
  param_4[5] = 0;
  param_4[6] = 0;
  param_4[7] = 0;
  local_158[0] = '\0';
  uVar2 = PsReferencePrimaryToken();
  if (AiUseSystemAppIdentityOnly == '\0') {
    pcVar5 = local_158;
    pcVar3 = (char *)0x0;
  }
  else {
    pcVar5 = (char *)0x0;
    pcVar3 = local_158;
  }
  PsQueryProcessAttributesByToken(uVar2,pcVar3,pcVar5);
  if (local_158[0] != '\0') {
    local_160 = 0;
    local_168 = 0;
    puVar4 = local_148;
    local_170 = 0;
    local_178 = 0;
    iVar1 = RtlQueryPackageClaims(uVar2,puVar4,&local_150,0);
    if (-1 < iVar1) {
      iVar1 = AppModelPolicy_Kernel_GetPolicy(uVar2,puVar4,&local_154);
      if (-1 < iVar1) {
        _Dst = (void *)AiAlloc(local_150 & 0xffffffff);
        if (_Dst == (void *)0x0) {
          iVar1 = -0x3fffffe9;
        }
        else {
          memmove(_Dst,local_148,local_150);
          *(void **)(param_4 + 4) = _Dst;
          param_4[1] = (short)local_150;
          *param_4 = (short)local_150 + -2;
          if (param_3 != 0) {
            *(bool *)param_3 = local_154 == 0x350001;
          }
          iVar1 = 0;
          *param_2 = 1;
        }
      }
    }
  }
  ObfDereferenceObject(uVar2);
  return iVar1;
}



===== AipGetPublisherId @ 14002e500 =====

int AipGetPublisherId(ushort *param_1,ulonglong *param_2,undefined8 *param_3,undefined8 param_4)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ulonglong local_res20;
  undefined8 in_stack_ffffffffffffffa8;
  ulonglong local_48;
  ulonglong uStack_40;
  ulonglong local_38;
  longlong lStack_30;
  
  local_res20 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  lStack_30 = 0;
  iVar2 = KappxParsePackageFullNameFromToken
                    (param_1,(short *)&local_48,(short *)&local_38,param_4,in_stack_ffffffffffffffa8
                     ,&local_res20);
  uVar3 = uStack_40;
  if (-1 < iVar2) {
    uVar3 = AiAlloc(local_48 >> 0x10 & 0xffff);
    uStack_40 = uVar3;
    lStack_30 = AiAlloc(local_38 >> 0x10 & 0xffff);
    if ((uVar3 == 0) || (lStack_30 == 0)) {
      iVar2 = -0x3fffffe9;
    }
    else {
      iVar2 = KappxParsePackageFullNameFromToken
                        (param_1,(short *)&local_48,(short *)&local_38,param_4,
                         in_stack_ffffffffffffffa8,&local_res20);
      uVar3 = uStack_40;
      if (-1 < iVar2) {
        uVar4 = AiConvertToTokenAttributes
                          ((ushort *)&local_38,(ushort *)&local_48,(ushort *)0x0,local_res20,param_3
                          );
        iVar2 = (int)uVar4;
        uVar3 = uStack_40;
        if (-1 < iVar2) {
          *param_2 = local_48;
          param_2[1] = uStack_40;
          uVar3 = 0;
        }
      }
    }
  }
  lVar1 = lStack_30;
  if (uVar3 != 0) {
    ExFreePoolWithTag(uVar3,0);
  }
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0);
  }
  return iVar2;
}



===== AipkAddEntryToAppxCache @ 14002e634 =====

undefined4 AipkAddEntryToAppxCache(longlong param_1)

{
  ushort uVar1;
  bool bVar2;
  char cVar3;
  longlong lVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uVar5 = 0;
  bVar2 = false;
  uVar1 = *(ushort *)
           (*(longlong *)(param_1 + 0x28) +
           ((ulonglong)*(ushort *)(param_1 + 0x20) - 2 & 0xfffffffffffffffe));
  uVar6 = (ulonglong)uVar1 + 1;
  if (uVar1 != 0) {
    uVar6 = (ulonglong)uVar1;
  }
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&AipAppxInMemoryCache,0);
  if (DAT_1400184b8 == 0) {
    cVar3 = RtlCreateHashTable(&DAT_1400184b8,0,0);
    if (cVar3 != '\0') goto LAB_14002e6d1;
  }
  else {
LAB_14002e6d1:
    lVar4 = RtlLookupEntryHashTable(DAT_1400184b8,uVar6,&local_38);
    while (lVar4 != 0) {
      cVar3 = RtlEqualUnicodeString(param_1 + 0x20,lVar4 + 0x20,1);
      if (cVar3 != '\0') goto LAB_14002e749;
      lVar4 = RtlGetNextEntryHashTable(DAT_1400184b8,&local_38);
    }
    cVar3 = RtlInsertEntryHashTable(DAT_1400184b8,param_1,uVar6,0);
    if (cVar3 != '\0') {
      bVar2 = true;
      goto LAB_14002e749;
    }
  }
  uVar5 = 0xc000009a;
LAB_14002e749:
  ExReleasePushLockExclusiveEx(&AipAppxInMemoryCache,0);
  KeLeaveCriticalRegion();
  if ((!bVar2) && (param_1 != 0)) {
    ExFreePoolWithTag(param_1,0);
  }
  return uVar5;
}



===== AipkAllocAndFillCacheEntry @ 14002e7a8 =====

undefined8
AipkAllocAndFillCacheEntry
          (undefined8 *param_1,ushort *param_2,ushort *param_3,ushort *param_4,undefined8 param_5,
          uint param_6,void *param_7)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  void *_Dst;
  uint uVar4;
  void *pvVar5;
  undefined8 uVar6;
  int iVar7;
  
  uVar6 = 0;
  iVar7 = (uint)*param_3 + *param_2 + 0xd0 + (*param_2 + 0xd1 & 0xfffffffe);
  uVar4 = (uint)*param_4 + iVar7 + (iVar7 + 1U & 0xfffffffe);
  uVar3 = uVar4;
  if ((param_6 != 0) && (uVar3 = uVar4 + param_6, uVar3 < uVar4)) {
    return 0xc0000095;
  }
  _Dst = (void *)AiAlloc((ulonglong)uVar3);
  if (_Dst == (void *)0x0) {
    uVar6 = 0xc0000017;
  }
  else {
    memset(_Dst,0,(ulonglong)uVar3);
    *(uint *)((longlong)_Dst + 0x18) = uVar3;
    pvVar5 = (void *)((longlong)_Dst + 0x69U & 0xfffffffffffffffe);
    uVar1 = *param_2;
    *(ushort *)((longlong)_Dst + 0x22) = uVar1;
    *(ushort *)((longlong)_Dst + 0x20) = uVar1;
    uVar2 = *param_3;
    *(ushort *)((longlong)_Dst + 0x32) = uVar2;
    *(ushort *)((longlong)_Dst + 0x30) = uVar2;
    uVar2 = *param_4;
    *(ushort *)((longlong)_Dst + 0x42) = uVar2;
    *(ushort *)((longlong)_Dst + 0x40) = uVar2;
    *(undefined8 *)((longlong)_Dst + 0x50) = param_5;
    *(uint *)((longlong)_Dst + 0x58) = param_6;
    memmove(pvVar5,*(void **)(param_2 + 4),(ulonglong)uVar1);
    *(void **)((longlong)_Dst + 0x28) = pvVar5;
    pvVar5 = (void *)((longlong)pvVar5 + (ulonglong)*(ushort *)((longlong)_Dst + 0x20) + 1 &
                     0xfffffffffffffffe);
    memmove(pvVar5,*(void **)(param_3 + 4),(ulonglong)*(ushort *)((longlong)_Dst + 0x30));
    *(void **)((longlong)_Dst + 0x38) = pvVar5;
    pvVar5 = (void *)((longlong)pvVar5 + (ulonglong)*(ushort *)((longlong)_Dst + 0x30) + 1 &
                     0xfffffffffffffffe);
    memmove(pvVar5,*(void **)(param_4 + 4),(ulonglong)*(ushort *)((longlong)_Dst + 0x40));
    *(void **)((longlong)_Dst + 0x48) = pvVar5;
    pvVar5 = (void *)((longlong)pvVar5 + (ulonglong)*(ushort *)((longlong)_Dst + 0x40));
    if (param_6 != 0) {
      memmove(pvVar5,param_7,(ulonglong)param_6);
      *(void **)((longlong)_Dst + 0x60) = pvVar5;
    }
    *param_1 = _Dst;
  }
  return uVar6;
}



===== AipkConstructCacheDacl @ 14002e930 =====

int AipkConstructCacheDacl(longlong *param_1)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  
  iVar1 = RtlLengthSid(&DAT_14000b8c0);
  iVar2 = RtlLengthSid(&DAT_14000b8e0);
  uVar4 = iVar1 + iVar2 + 0x18;
  lVar3 = AiAlloc((ulonglong)uVar4);
  if (lVar3 == 0) {
    iVar1 = -0x3fffffe9;
  }
  else {
    iVar1 = RtlCreateAcl(lVar3,uVar4,2);
    if (((-1 < iVar1) &&
        (iVar1 = RtlAddAccessAllowedAce(lVar3,2,0x10000000,&DAT_14000b8e0), -1 < iVar1)) &&
       (iVar1 = RtlAddAccessAllowedAce(lVar3,2,0x10000000,&DAT_14000b8c0), -1 < iVar1)) {
      *param_1 = lVar3;
      return iVar1;
    }
    ExFreePoolWithTag(lVar3,0);
  }
  return iVar1;
}



===== AipkFindAndReturnEntryFromAppxCache @ 14002ea24 =====

undefined8 AipkFindAndReturnEntryFromAppxCache(ushort *param_1,undefined8 *param_2)

{
  ushort uVar1;
  uint uVar2;
  longlong lVar3;
  char cVar4;
  void *_Src;
  undefined8 *_Dst;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar1 = *param_1;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uVar6 = 0;
  lVar3 = *(longlong *)(param_1 + 4);
  *param_2 = 0;
  uVar1 = *(ushort *)(lVar3 + ((ulonglong)uVar1 - 2 & 0xfffffffffffffffe));
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(&AipAppxInMemoryCache,0);
  if (DAT_1400184b8 != 0) {
    uVar5 = (ulonglong)uVar1 + 1;
    if (uVar1 != 0) {
      uVar5 = (ulonglong)uVar1;
    }
    _Src = (void *)RtlLookupEntryHashTable(DAT_1400184b8,uVar5,&local_28);
    while (_Src != (void *)0x0) {
      cVar4 = RtlEqualUnicodeString(param_1,(longlong)_Src + 0x20,1);
      if (cVar4 != '\0') {
        uVar2 = *(uint *)((longlong)_Src + 0x18);
        *param_2 = 0;
        _Dst = (undefined8 *)AiAlloc((ulonglong)uVar2);
        if (_Dst == (undefined8 *)0x0) {
          uVar6 = 0xc0000017;
        }
        else {
          memmove(_Dst,_Src,(ulonglong)*(uint *)((longlong)_Src + 0x18));
          *param_2 = _Dst;
          *_Dst = 0;
          _Dst[1] = 0;
          _Dst[2] = 0;
          _Dst[5] = (*(longlong *)((longlong)_Src + 0x28) - (longlong)_Src) + (longlong)_Dst;
          _Dst[7] = (*(longlong *)((longlong)_Src + 0x38) - (longlong)_Src) + (longlong)_Dst;
          _Dst[9] = (*(longlong *)((longlong)_Src + 0x48) - (longlong)_Src) + (longlong)_Dst;
          _Dst[0xc] = (*(longlong *)((longlong)_Src + 0x60) - (longlong)_Src) + (longlong)_Dst;
        }
        goto LAB_14002eaf0;
      }
      _Src = (void *)RtlGetNextEntryHashTable(DAT_1400184b8,&local_28);
    }
  }
  uVar6 = 0xc0000225;
LAB_14002eaf0:
  ExReleasePushLockSharedEx(&AipAppxInMemoryCache,0);
  KeLeaveCriticalRegion();
  return uVar6;
}



===== AipkGetAppxAttributes @ 14002eba8 =====

int AipkGetAppxAttributes
              (ushort *param_1,undefined8 param_2,char param_3,ulonglong *param_4,
              undefined8 *param_5)

{
  int iVar1;
  ulonglong uVar2;
  void *_Dst;
  undefined8 uVar3;
  longlong lVar4;
  char local_58 [8];
  longlong local_50;
  undefined8 local_48;
  void *pvStack_40;
  ushort local_38 [4];
  longlong lStack_30;
  
  local_58[0] = '\0';
  local_50 = 0;
  _Dst = (void *)0x0;
  local_48 = 0;
  pvStack_40 = (void *)0x0;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  lStack_30 = 0;
  if (AiEnablePublisherId != '\0') {
    iVar1 = AipGetPublisherId(param_1,param_4,param_5,param_4);
    return iVar1;
  }
  *param_5 = 0;
  uVar2 = AipkGetAppxFqbnAttributes(param_1,'\0',local_58,&local_50);
  lVar4 = local_50;
  iVar1 = (int)uVar2;
  if (iVar1 < 0) {
LAB_14002ed19:
    lVar4 = local_50;
  }
  else {
    if ((*(int *)(local_50 + 0x58) != 0) && (iVar1 = AipkIsCertificateTrusted(local_50), iVar1 < 0))
    {
      if (local_58[0] == '\0') {
        AipkRemoveEntryFromAppxCache(lVar4);
      }
      ExFreePoolWithTag(lVar4,0);
      local_50 = 0;
      uVar2 = AipkGetAppxFqbnAttributes(param_1,'\x01',local_58,&local_50);
      lVar4 = local_50;
      iVar1 = (int)uVar2;
      if (iVar1 < 0) goto LAB_14002ed19;
      iVar1 = AipkIsCertificateTrusted(local_50);
      if (iVar1 < 0) goto LAB_14002ed1d;
    }
    if ((param_3 == '\0') ||
       (iVar1 = AiGetOriginalFileName(param_2,(undefined8 *)local_38), -1 < iVar1)) {
      _Dst = (void *)AiAlloc((ulonglong)*(ushort *)(lVar4 + 0x42));
      if (_Dst == (void *)0x0) {
        iVar1 = -0x3fffffe9;
      }
      else {
        local_48 = CONCAT62(CONCAT42(local_48._4_4_,*(undefined2 *)(lVar4 + 0x42)),
                            *(ushort *)(lVar4 + 0x40));
        pvStack_40 = _Dst;
        memmove(_Dst,*(void **)(lVar4 + 0x48),(ulonglong)*(ushort *)(lVar4 + 0x40));
        uVar3 = AiConvertToTokenAttributes
                          ((ushort *)(lVar4 + 0x30),(ushort *)(lVar4 + 0x40),local_38,
                           *(undefined8 *)(lVar4 + 0x50),param_5);
        iVar1 = (int)uVar3;
        if ((-1 < iVar1) && (local_58[0] != '\0')) {
          AipkAddEntryToAppxCache(lVar4);
          lVar4 = 0;
        }
      }
    }
  }
LAB_14002ed1d:
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0);
  }
  if (lStack_30 != 0) {
    ExFreePoolWithTag(lStack_30,0);
  }
  if (iVar1 < 0) {
    if (_Dst != (void *)0x0) {
      ExFreePoolWithTag(_Dst,0);
    }
  }
  else {
    *param_4 = local_48;
    param_4[1] = (ulonglong)pvStack_40;
  }
  return iVar1;
}



===== AipkGetAppxFqbnAttributes @ 14002ed98 =====

ulonglong AipkGetAppxFqbnAttributes
                    (ushort *param_1,char param_2,undefined1 *param_3,undefined8 *param_4)

{
  char cVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint local_res10 [2];
  undefined8 local_58;
  void *local_50;
  undefined8 local_48;
  ushort local_40 [4];
  longlong lStack_38;
  ushort local_30 [4];
  longlong lStack_28;
  
  local_58 = 0;
  local_48 = 0;
  local_res10[0] = 0;
  local_50 = (void *)0x0;
  *param_4 = 0;
  local_40[0] = 0;
  local_40[1] = 0;
  local_40[2] = 0;
  local_40[3] = 0;
  lStack_38 = 0;
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  lStack_28 = 0;
  if (param_2 == '\0') {
    uVar2 = AipkFindAndReturnEntryFromAppxCache(param_1,&local_58);
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      *param_3 = 1;
      uVar2 = AipkReadRegCache(param_1,&local_58);
      uVar3 = uVar2 & 0xffffffff;
      if ((int)uVar2 < 0) goto LAB_14002ee12;
    }
    else {
      *param_3 = 0;
    }
  }
  else {
LAB_14002ee12:
    *param_3 = 1;
    uVar2 = AipkVerifyPackageMonikerFromService
                      (param_1,local_40,local_30,&local_48,local_res10,&local_50);
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      if ((((int)uVar2 != -0x7ff8fffe) || (lStack_38 == 0)) || (lStack_28 == 0)) goto LAB_14002eea3;
      cVar1 = ExQueryFastCacheDevLicense();
      if (cVar1 == '\0') goto LAB_14002eea3;
      *param_3 = 0;
    }
    uVar2 = AipkAllocAndFillCacheEntry
                      (&local_58,param_1,local_30,local_40,local_48,local_res10[0],local_50);
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) goto LAB_14002eea3;
  }
  *param_4 = local_58;
LAB_14002eea3:
  if (lStack_38 != 0) {
    ExFreePoolWithTag(lStack_38,0);
  }
  if (lStack_28 != 0) {
    ExFreePoolWithTag(lStack_28,0);
  }
  if (local_50 != (void *)0x0) {
    ExFreePoolWithTag(local_50,0);
  }
  return uVar3;
}



===== AipkIsCertificateTrusted @ 14002ef0c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AipkIsCertificateTrusted(longlong param_1)

{
  undefined1 auStack_e8 [32];
  undefined4 local_c8;
  undefined4 local_c4;
  undefined8 local_c0;
  int local_b8 [4];
  undefined4 *local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined4 local_88 [2];
  undefined4 *local_80;
  undefined4 local_78;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_e8;
  local_c4 = 0;
  local_a8 = local_88;
  local_b8[2] = 0;
  local_b8[3] = 0;
  local_b8[0] = 0x30;
  local_b8[1] = 0;
  uStack_a0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  memset(local_88,0,0x68);
  local_80 = &local_c8;
  local_88[0] = 0x68;
  local_c8 = *(undefined4 *)(param_1 + 0x58);
  local_c0 = *(undefined8 *)(param_1 + 0x60);
  local_78 = 1;
  AipGetTrustedPublisherName(local_b8,(ulonglong *)0x0,0,(undefined4 *)0x0);
  return;
}



===== AipkLoadRegCache @ 14002efbc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int AipkLoadRegCache(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  uint uVar6;
  longlong lVar7;
  undefined1 auStack_98 [32];
  int *local_78;
  int local_68 [2];
  longlong local_60;
  longlong local_58 [3];
  undefined8 local_40;
  uint uStack_3c;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_98;
  local_68[0] = 0;
  lVar7 = 0;
  local_60 = 0;
  lVar5 = 0;
  local_58[0] = 0;
  bVar1 = false;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&AipAppxRegCache,0);
  if (DAT_1400184a0 == '\0') {
    uVar6 = 0;
LAB_14002f034:
    do {
      local_78 = (int *)0x0;
      iVar3 = KeExpandKernelStackAndCalloutEx(AipkLoadRegCache_Callout,local_68,0x6000,0);
      iVar4 = local_68[0];
      if (iVar3 < 0) {
LAB_14002f187:
        bVar1 = false;
        goto LAB_14002f18a;
      }
      if (local_68[0] < 0) {
        if (uVar6 != 0) {
          local_68[0] = 0;
          iVar3 = iVar4;
          goto LAB_14002f187;
        }
        ZwDeleteFile(&DAT_140008600);
        uVar6 = 1;
        goto LAB_14002f034;
      }
      bVar1 = true;
      iVar3 = AiRegOpenKey(0,&DAT_1400086b0,0xf003f,&local_60);
      if (iVar3 < 0) goto LAB_14002f18a;
      local_78 = local_68 + 1;
      local_68[1] = 0;
      local_58[1] = 0;
      local_58[2] = 0;
      local_40 = 0;
      uStack_38 = 0;
      local_30 = 0;
      uStack_28 = 0;
      iVar4 = ZwQueryKey(local_60,2,local_58 + 1);
      iVar3 = 0;
      if (iVar4 != -0x7ffffffb) {
        iVar3 = iVar4;
      }
      if (iVar3 < 0) goto LAB_14002f18a;
      bVar2 = true;
      if (uStack_3c < 1000) break;
      ZwClose(local_60);
      local_60 = 0;
      iVar3 = ZwUnloadKeyEx(&DAT_140008630,0);
      if (iVar3 < 0) goto LAB_14002f18a;
      bVar1 = false;
      iVar3 = ZwDeleteFile(&DAT_140008600);
      if (iVar3 < 0) goto LAB_14002f18a;
      uVar6 = uVar6 + 1;
      bVar2 = false;
    } while (uVar6 < 2);
    bVar1 = bVar2;
    lVar5 = ExAllocatePool2(0x102,0x28,0x44497041);
    if (lVar5 == 0) {
      iVar3 = -0x3fffffe9;
    }
    else {
      iVar3 = RtlCreateSecurityDescriptor(lVar5,1);
      if (-1 < iVar3) {
        iVar3 = AipkConstructCacheDacl(local_58);
        lVar7 = local_58[0];
        if (-1 < iVar3) {
          iVar3 = RtlSetDaclSecurityDescriptor(lVar5,1,local_58[0],0);
          if (-1 < iVar3) {
            iVar3 = ZwSetSecurityObject(local_60,4,lVar5);
          }
        }
      }
    }
  }
  else {
    iVar3 = 0;
  }
LAB_14002f18a:
  if (local_60 != 0) {
    ZwClose();
  }
  if (lVar7 != 0) {
    ExFreePoolWithTag(lVar7,0);
  }
  if (lVar5 != 0) {
    ExFreePoolWithTag(lVar5,0);
  }
  if (iVar3 < 0) {
    if (bVar1) {
      ZwUnloadKeyEx(&DAT_140008630,0);
    }
  }
  else {
    DAT_1400184a0 = '\x01';
  }
  ExReleasePushLockExclusiveEx(&AipAppxRegCache,0);
  KeLeaveCriticalRegion();
  return iVar3;
}



===== AipkLoadRegCache_Callout @ 14002f2c0 =====

void AipkLoadRegCache_Callout(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = ZwLoadKeyEx(&DAT_140008630,&DAT_140008600,4,0,0,0,0,0);
  *param_1 = uVar1;
  return;
}



===== AipkReadRegCache @ 14002f310 =====

ulonglong AipkReadRegCache(ushort *param_1,undefined8 *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  void *pvVar3;
  undefined *puVar4;
  uint local_res10 [2];
  longlong local_res18;
  void *local_res20;
  undefined8 local_58;
  ushort local_50 [4];
  longlong lStack_48;
  ushort local_40 [4];
  longlong lStack_38;
  
  local_res18 = 0;
  local_58 = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  lStack_48 = 0;
  pvVar3 = (void *)0x0;
  local_res20 = (void *)0x0;
  local_40[0] = 0;
  local_40[1] = 0;
  local_40[2] = 0;
  local_40[3] = 0;
  lStack_38 = 0;
  local_res10[0] = 0;
  if ((AipAppxRegCacheInitialized != '\0') && (DAT_1400184a0 == '\0')) {
    AipkLoadRegCache();
  }
  *param_2 = 0;
  uVar1 = AiRegOpenKey(0,&DAT_1400086b0,0x20019,&local_res18);
  uVar2 = (ulonglong)uVar1;
  if (-1 < (int)uVar1) {
    uVar1 = AiRegReadStringValue(local_res18,param_1,&DAT_1400086a0,(short *)local_50);
    uVar2 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      uVar1 = AiRegReadStringValue(local_res18,param_1,&DAT_140008690,(short *)local_40);
      uVar2 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        puVar4 = &DAT_140008680;
        uVar1 = AiRegReadQwordValue(local_res18,param_1,&DAT_140008680,&local_58);
        uVar2 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          uVar1 = AiRegReadBinaryValue(local_res18,param_1,puVar4,local_res10,&local_res20);
          pvVar3 = local_res20;
          uVar2 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            uVar2 = AipkAllocAndFillCacheEntry
                              (param_2,param_1,local_50,local_40,local_58,local_res10[0],local_res20
                              );
            uVar2 = uVar2 & 0xffffffff;
          }
        }
      }
    }
  }
  if (local_res18 != 0) {
    ZwClose();
  }
  if ((local_50[0] != 0) && (lStack_48 != 0)) {
    ExFreePoolWithTag(lStack_48,0);
  }
  if ((local_40[0] != 0) && (lStack_38 != 0)) {
    ExFreePoolWithTag(lStack_38,0);
  }
  if (pvVar3 != (void *)0x0) {
    ExFreePoolWithTag(pvVar3,0);
  }
  return uVar2;
}



===== AipkRemoveEntryFromAppxCache @ 14002f4b8 =====

void AipkRemoveEntryFromAppxCache(longlong param_1)

{
  ushort uVar1;
  char cVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  uVar1 = *(ushort *)
           (*(longlong *)(param_1 + 0x28) +
           ((ulonglong)*(ushort *)(param_1 + 0x20) - 2 & 0xfffffffffffffffe));
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&AipAppxInMemoryCache,0);
  if (DAT_1400184b8 != 0) {
    uVar4 = (ulonglong)uVar1 + 1;
    if (uVar1 != 0) {
      uVar4 = (ulonglong)uVar1;
    }
    lVar3 = RtlLookupEntryHashTable(DAT_1400184b8,uVar4,&local_28);
    while (lVar3 != 0) {
      cVar2 = RtlEqualUnicodeString((ushort *)(param_1 + 0x20),lVar3 + 0x20,1);
      if (cVar2 != '\0') {
        RtlRemoveEntryHashTable(DAT_1400184b8,lVar3,0);
        if (lVar3 != 0) {
          ExFreePoolWithTag(lVar3,0);
        }
        break;
      }
      lVar3 = RtlGetNextEntryHashTable(DAT_1400184b8,&local_28);
    }
  }
  ExReleasePushLockExclusiveEx(&AipAppxInMemoryCache,0);
  KeLeaveCriticalRegion();
  return;
}



===== SrpIsSubjectService @ 14002f5d8 =====

int SrpIsSubjectService(undefined8 param_1,char *param_2)

{
  char cVar1;
  int local_res18 [2];
  undefined4 local_res20 [2];
  
  local_res18[0] = 0;
  local_res20[0] = 0;
  cVar1 = SeAccessCheck(&DAT_14000c428,param_1,0,1,0,0,&DAT_14000c4b0,1,local_res20,local_res18);
  if (cVar1 == '\0') {
    if (local_res18[0] != -0x3fffffde) {
      return local_res18[0];
    }
    local_res18[0] = 0;
  }
  *param_2 = cVar1;
  return local_res18[0];
}



===== SrpIsTokenService @ 14002f658 =====

int SrpIsTokenService(undefined8 param_1,char *param_2)

{
  longlong lVar1;
  int iVar2;
  longlong local_res18 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  longlong local_18;
  undefined8 uStack_10;
  
  local_res18[0] = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  iVar2 = ObReferenceObjectByHandle(0,0,0,0,local_res18,0);
  lVar1 = local_res18[0];
  if (-1 < iVar2) {
    uStack_20 = 0;
    uStack_10 = 0;
    local_18 = local_res18[0];
    iVar2 = SrpIsSubjectService(&local_28,param_2);
  }
  if (lVar1 != 0) {
    ObfDereferenceObject(lVar1);
  }
  return iVar2;
}



===== AiRegGetSubkeyName @ 14002f6f8 =====

int AiRegGetSubkeyName(undefined8 param_1,undefined4 param_2,undefined2 *param_3)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  void *_Dst;
  ulonglong uVar4;
  uint local_res20 [2];
  
  lVar3 = 0;
  uVar4 = 0x38;
  local_res20[0] = 0x38;
  while( true ) {
    if (lVar3 != 0) {
      ExFreePoolWithTag(lVar3,0);
    }
    lVar3 = AiAlloc(uVar4);
    if (lVar3 == 0) break;
    iVar2 = ZwEnumerateKey(param_1,param_2,0,lVar3,(int)uVar4,local_res20);
    if (iVar2 != -0x7ffffffb) {
      if (-1 < iVar2) {
        uVar1 = *(uint *)(lVar3 + 0xc);
        if ((uVar1 - 2 < 0xfffe) && ((uVar1 & 1) == 0)) {
          *param_3 = (short)uVar1;
          param_3[1] = (short)uVar1;
          _Dst = (void *)AiAlloc((ulonglong)(uVar1 & 0xffff));
          *(void **)(param_3 + 4) = _Dst;
          if (_Dst == (void *)0x0) {
            iVar2 = -0x3fffffe9;
          }
          else {
            memmove(_Dst,(void *)(lVar3 + 0x10),(ulonglong)(ushort)param_3[1]);
          }
        }
        else {
          iVar2 = -0x3ffffff3;
        }
      }
      ExFreePoolWithTag(lVar3,0);
      return iVar2;
    }
    uVar4 = (ulonglong)local_res20[0];
  }
  return -0x3fffffe9;
}



===== AiRegOpenKey @ 14002f7fc =====

void AiRegOpenKey(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38 = 0x30;
  local_1c = 0;
  local_20 = 0x240;
  local_18 = 0;
  uStack_10 = 0;
  local_30 = param_1;
  local_28 = param_2;
  ZwOpenKey(param_4,param_3,&local_38);
  return;
}



===== AiRegReadDwordValue @ 14002f854 =====

int AiRegReadDwordValue(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4
                       )

{
  undefined4 uVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 local_res8;
  longlong local_18 [2];
  
  local_18[0] = 0;
  local_res8 = CONCAT44((int)((ulonglong)param_1 >> 0x20),0x30);
  lVar3 = 0;
  iVar2 = AiRegOpenKey(0,param_2,0x20019,local_18);
  if (-1 < iVar2) {
    do {
      uVar1 = (undefined4)local_res8;
      uVar4 = local_res8 & 0xffffffff;
      if (lVar3 != 0) {
        ExFreePoolWithTag(lVar3,0);
      }
      lVar3 = AiAlloc(uVar4);
      if (lVar3 == 0) {
        iVar2 = -0x3fffffe9;
        goto LAB_14002f92d;
      }
      iVar2 = ZwQueryValueKey(local_18[0],param_3,2,lVar3,uVar1,&local_res8);
    } while (iVar2 == -0x7ffffffb);
    if (-1 < iVar2) {
      if ((*(int *)(lVar3 + 4) == 4) && (*(int *)(lVar3 + 8) == 4)) {
        *param_4 = *(undefined4 *)(lVar3 + 0xc);
      }
      else {
        iVar2 = -0x3fffffdc;
      }
    }
    ExFreePoolWithTag(lVar3,0);
  }
LAB_14002f92d:
  if (local_18[0] != 0) {
    ZwClose();
  }
  return iVar2;
}



===== AiRegReadStringValue @ 14002f964 =====

int AiRegReadStringValue(undefined8 param_1,undefined8 param_2,undefined8 param_3,short *param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  void *_Dst;
  uint uVar5;
  ulonglong uVar6;
  uint local_28 [2];
  longlong local_20;
  
  local_28[0] = 0x30;
  local_20 = 0;
  lVar4 = 0;
  iVar3 = AiRegOpenKey(param_1,param_2,0x20019,&local_20);
  if (-1 < iVar3) {
    do {
      uVar5 = local_28[0];
      uVar6 = (ulonglong)local_28[0];
      if (lVar4 != 0) {
        ExFreePoolWithTag(lVar4,0);
      }
      lVar4 = AiAlloc(uVar6);
      if (lVar4 == 0) {
        iVar3 = -0x3fffffe9;
        goto LAB_14002fabb;
      }
      iVar3 = ZwQueryValueKey(local_20,param_3,2,lVar4,uVar5,local_28);
    } while (iVar3 == -0x7ffffffb);
    if (-1 < iVar3) {
      iVar2 = *(int *)(lVar4 + 4);
      if ((((iVar2 == 1) || (iVar2 == 7)) && (uVar5 = *(uint *)(lVar4 + 8), uVar5 - 2 < 0xfffe)) &&
         ((uVar5 & 1) == 0)) {
        uVar5 = uVar5 >> 1;
        if ((*(short *)(lVar4 + 0xc + (ulonglong)(uVar5 - 1) * 2) == 0) &&
           (((iVar2 != 7 || (uVar5 == 1)) ||
            (*(short *)(lVar4 + 0xc + (ulonglong)(uVar5 - 2) * 2) == 0)))) {
          *param_4 = *(short *)(lVar4 + 8) + -2;
          uVar1 = *(ushort *)(lVar4 + 8);
          param_4[1] = uVar1;
          _Dst = (void *)AiAlloc((ulonglong)uVar1);
          *(void **)(param_4 + 4) = _Dst;
          if (_Dst == (void *)0x0) {
            iVar3 = -0x3fffffe9;
          }
          else {
            memmove(_Dst,(void *)(lVar4 + 0xc),(ulonglong)(ushort)param_4[1]);
          }
        }
        else {
          iVar3 = -0x3ffff6f5;
        }
      }
      else {
        iVar3 = -0x3fffffdc;
      }
    }
    ExFreePoolWithTag(lVar4,0);
  }
LAB_14002fabb:
  if (local_20 != 0) {
    ZwClose();
  }
  return iVar3;
}



===== AiRegWriteDwordValue @ 14002faf4 =====

int AiRegWriteDwordValue
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  int iVar1;
  longlong local_res8;
  undefined4 local_res20 [2];
  
  local_res8 = 0;
  local_res20[0] = param_4;
  iVar1 = AiRegOpenKey(0,param_2,0x20006,&local_res8);
  if (-1 < iVar1) {
    iVar1 = ZwSetValueKey(local_res8,param_3,0,4,local_res20,4);
  }
  if (local_res8 != 0) {
    ZwClose();
  }
  return iVar1;
}



===== AiQueryLogonId @ 14002fb80 =====

int AiQueryLogonId(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint local_res18 [2];
  
  lVar2 = 0;
  uVar3 = 0x38;
  local_res18[0] = 0x38;
  while( true ) {
    if (lVar2 != 0) {
      ExFreePoolWithTag(lVar2,0);
      uVar3 = (ulonglong)local_res18[0];
    }
    lVar2 = 0;
    if ((int)uVar3 != 0) {
      lVar2 = AiAlloc(uVar3);
      if (lVar2 == 0) {
        return -0x3fffffe9;
      }
      uVar3 = (ulonglong)local_res18[0];
    }
    iVar1 = ZwQueryInformationToken(param_1,0xd,lVar2,uVar3,local_res18);
    if (iVar1 != -0x3fffffdd) break;
    uVar3 = (ulonglong)local_res18[0];
  }
  if (-1 < iVar1) {
    *param_2 = *(undefined8 *)(lVar2 + 0x30);
  }
  if (lVar2 != 0) {
    ExFreePoolWithTag(lVar2,0);
  }
  return iVar1;
}



===== AiQueryTokenAttributes @ 14002fc54 =====

int AiQueryTokenAttributes(undefined8 param_1,longlong *param_2)

{
  int iVar1;
  longlong lVar2;
  uint local_res18 [2];
  
  lVar2 = 0;
  local_res18[0] = 0;
  while( true ) {
    if (lVar2 != 0) {
      ExFreePoolWithTag(lVar2,0);
      lVar2 = 0;
    }
    if ((local_res18[0] != 0) && (lVar2 = AiAlloc((ulonglong)local_res18[0]), lVar2 == 0)) break;
    iVar1 = ZwQuerySecurityAttributesToken(param_1,0,0,lVar2,local_res18[0],local_res18);
    if (iVar1 != -0x3fffffdd) {
      if (iVar1 < 0) {
        if (lVar2 != 0) {
          ExFreePoolWithTag(lVar2,0);
        }
      }
      else {
        *param_2 = lVar2;
      }
      return iVar1;
    }
  }
  return -0x3fffffe9;
}



===== AiQueryUserSid @ 14002fd24 =====

int AiQueryUserSid(undefined8 param_1,longlong *param_2)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint local_res18 [2];
  
  lVar2 = 0;
  uVar3 = 0;
  local_res18[0] = 0;
  while( true ) {
    if (lVar2 != 0) {
      ExFreePoolWithTag(lVar2,0);
      uVar3 = (ulonglong)local_res18[0];
      lVar2 = 0;
    }
    if ((int)uVar3 != 0) {
      lVar2 = AiAlloc(uVar3);
      if (lVar2 == 0) {
        return -0x3fffffe9;
      }
      uVar3 = (ulonglong)local_res18[0];
    }
    iVar1 = ZwQueryInformationToken(param_1,1,lVar2,uVar3,local_res18);
    if (iVar1 != -0x3fffffdd) break;
    uVar3 = (ulonglong)local_res18[0];
  }
  if (iVar1 < 0) {
    if (lVar2 != 0) {
      ExFreePoolWithTag(lVar2,0);
    }
  }
  else {
    *param_2 = lVar2;
  }
  return iVar1;
}



===== AiSetTokenAttributes @ 14002fdf4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 AiSetTokenAttributes(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  if (*(uint *)(param_2 + 4) < 6) {
    local_18 = 4;
    local_28 = 0x400000004;
    uStack_20 = 0x400000004;
    uVar1 = SeSetSecurityAttributesToken(0x400000004,0,&local_28,&AipDefaultAttributes);
    if ((-1 < (int)uVar1) && (*(int *)(param_2 + 4) != 0)) {
      uVar1 = SeSetSecurityAttributesToken(param_1,0,&local_28,param_2);
    }
  }
  else {
    uVar1 = 0xc00000e5;
  }
  return uVar1;
}



===== AiGetPlugins @ 14002fe90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong AiGetPlugins(undefined8 param_1,undefined8 *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  ulonglong uVar6;
  uint uVar7;
  undefined2 uVar8;
  undefined8 *puVar9;
  int *piVar10;
  ulonglong uVar11;
  uint uVar12;
  undefined1 auStack_88 [32];
  undefined4 local_68;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_88;
  local_68 = 5;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  puVar9 = &local_58;
  local_58 = 0;
  uStack_50 = 0;
  uVar3 = ZwQueryInformationFile(0,puVar9,&local_48,0x18);
  uVar12 = 0;
  uVar11 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_0961c2f37d1b3ad2f2ca69bd50809778_Traceguids,uVar3);
    }
  }
  else if ((uStack_40._4_4_ == 0) && (0x1f < (uint)uStack_40)) {
    piVar5 = (int *)AiAlloc(uStack_40 & 0xffffffff);
    if (piVar5 == (int *)0x0) {
      uVar11 = 0xc0000017;
    }
    else {
      uVar6 = AiReadFile(param_1,puVar9,piVar5,(uint)uStack_40);
      uVar11 = uVar6 & 0xffffffff;
      if ((int)uVar6 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                   &WPP_0961c2f37d1b3ad2f2ca69bd50809778_Traceguids,(int)uVar6);
        }
      }
      else {
        if ((*piVar5 == 0x464c7041) && (piVar5[1] == 1)) {
          uVar3 = piVar5[2];
          uVar1 = piVar5[3];
          uVar7 = uVar3 + uVar1 * 0x24;
          if (uVar3 <= uVar7) {
            if (uVar7 <= (uint)uStack_40) {
              uVar7 = piVar5[4];
              uVar2 = piVar5[5];
              uVar4 = uVar2 * 0x1c + uVar7;
              if ((uVar7 <= uVar4) && (uVar4 <= (uint)uStack_40)) {
                uVar4 = piVar5[7] * 0x10 + piVar5[6];
                if (((uint)piVar5[6] <= uVar4) && (uVar4 <= (uint)uStack_40)) {
                  uVar4 = 0;
                  if (uVar1 != 0) {
                    piVar10 = (int *)((ulonglong)uVar3 + 0x18 + (longlong)piVar5);
                    do {
                      uVar3 = *piVar10 + piVar10[-1];
                      if ((((uVar3 < (uint)piVar10[-1]) || ((uint)uStack_40 < uVar3)) ||
                          (uVar3 = piVar10[2] + piVar10[1], uVar3 < (uint)piVar10[1])) ||
                         (uVar2 < uVar3)) {
                        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                           ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) {
                          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                                   uStack_40 & 0xffffffff,uVar4);
                        }
                        goto LAB_140030115;
                      }
                      uVar4 = uVar4 + 1;
                      piVar10 = piVar10 + 9;
                    } while (uVar4 < uVar1);
                  }
                  if (uVar2 != 0) {
                    piVar10 = (int *)((ulonglong)uVar7 + 0x18 + (longlong)piVar5);
                    do {
                      uVar3 = *piVar10 + piVar10[-1];
                      if ((uVar3 < (uint)piVar10[-1]) || ((uint)piVar5[7] < uVar3)) {
                        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                           (-1 < (char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c)))
                        goto LAB_140030115;
                        uVar8 = 0x16;
                        goto LAB_140030105;
                      }
                      uVar12 = uVar12 + 1;
                      piVar10 = piVar10 + 7;
                    } while (uVar12 < uVar2);
                  }
                  *param_2 = piVar5;
                  return uVar11;
                }
              }
            }
          }
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) {
          uVar8 = 0x14;
LAB_140030105:
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,
                  &WPP_0961c2f37d1b3ad2f2ca69bd50809778_Traceguids);
        }
LAB_140030115:
        uVar11 = 0xc000000d;
      }
      ExFreePoolWithTag(piVar5,0);
    }
  }
  else {
    uVar11 = 0xc000000d;
  }
  return uVar11;
}



===== AiGetPolicy @ 14003015c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong AiGetPolicy(undefined8 param_1,undefined8 *param_2)

{
  char *pcVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  ulonglong uVar7;
  uint *puVar8;
  undefined2 uVar9;
  uint uVar10;
  undefined8 *puVar11;
  ulonglong uVar12;
  char *pcVar13;
  uint uVar14;
  undefined1 auStack_88 [32];
  undefined4 local_68;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_88;
  local_68 = 5;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  puVar11 = &local_58;
  local_58 = 0;
  uStack_50 = 0;
  uVar3 = ZwQueryInformationFile(0,puVar11,&local_48,0x18);
  uVar7 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return uVar7;
    }
    if ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_0961c2f37d1b3ad2f2ca69bd50809778_Traceguids,uVar3);
      return uVar7;
    }
    return uVar7;
  }
  if ((uStack_40._4_4_ != 0) || ((uint)uStack_40 < 0x20)) {
    return 0xc000000d;
  }
  piVar6 = (int *)AiAlloc(uStack_40 & 0xffffffff);
  if (piVar6 == (int *)0x0) {
    return 0xc0000017;
  }
  uVar7 = AiReadFile(param_1,puVar11,piVar6,(uint)uStack_40);
  uVar12 = uVar7 & 0xffffffff;
  if ((int)uVar7 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_0961c2f37d1b3ad2f2ca69bd50809778_Traceguids,(int)uVar7);
    }
    goto LAB_14003054c;
  }
  if (((*piVar6 == 0x46507041) && (piVar6[1] == 1)) && (uVar3 = piVar6[5], 0x13 < uVar3)) {
    uVar5 = piVar6[4];
    if (((uVar3 + uVar5 < uVar5) || ((uint)uStack_40 < uVar3 + uVar5)) ||
       (uVar10 = piVar6[3], 0xffff < uVar10)) goto LAB_140030518;
    uVar14 = piVar6[2];
    uVar4 = uVar10 * 0x1c + uVar14;
    if ((uVar4 < uVar14) || ((uint)uStack_40 < uVar4)) goto LAB_140030518;
    puVar8 = (uint *)((ulonglong)uVar14 + (longlong)piVar6);
    uVar14 = 0;
    if (uVar10 != 0) {
      do {
        uVar4 = *puVar8 + puVar8[1];
        pcVar13 = (char *)(ulonglong)uVar4;
        if (((uVar4 < *puVar8) || ((uint)uStack_40 < uVar4)) || (0xffff < puVar8[1])) {
LAB_140030454:
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             (-1 < (char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c))) goto LAB_140030547;
          uVar9 = 0xd;
          goto LAB_14003047b;
        }
        uVar4 = puVar8[2] + puVar8[3];
        pcVar13 = (char *)(ulonglong)uVar4;
        if (((uVar4 < puVar8[2]) || ((uint)uStack_40 < uVar4)) || (0xffff < puVar8[3]))
        goto LAB_140030454;
        uVar4 = puVar8[5] + puVar8[4];
        pcVar13 = (char *)(ulonglong)uVar4;
        if (((uVar4 < puVar8[4]) || ((uint)uStack_40 < uVar4)) || (0xffff < puVar8[5]))
        goto LAB_140030454;
        uVar14 = uVar14 + 1;
        puVar8 = puVar8 + 7;
      } while (uVar14 < uVar10);
    }
    pcVar1 = (char *)((longlong)piVar6 + (ulonglong)uVar5);
    if (((((*pcVar1 == '\x01') && (*(short *)(pcVar1 + 2) == -0x7ffc)) &&
         (*(int *)(pcVar1 + 4) == 0x14)) &&
        ((*(int *)(pcVar1 + 8) == 0 && (*(int *)(pcVar1 + 0xc) == 0)))) &&
       (*(int *)(pcVar1 + 0x10) == 0x20)) {
      if (((0x1f < uVar3) && (*(longlong *)(pcVar1 + 0x14) == 0x500000000000101)) &&
         (*(int *)(pcVar1 + 0x1c) == 0x12)) {
        if ((0x27 < uVar3) && (pcVar1[0x20] == '\x02')) {
          uVar2 = *(ushort *)(pcVar1 + 0x24);
          if (uVar2 == uVar10) {
            pcVar13 = pcVar1 + 0x28;
            uVar14 = 0;
            if (uVar2 != 0) {
              do {
                uVar5 = (int)pcVar13 - (int)pcVar1;
                if ((uVar5 + 4 < uVar5) || (uVar3 < uVar5 + 4)) {
LAB_140030489:
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) {
                    uVar9 = 0x11;
LAB_14003047b:
                    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,pcVar13,uVar14);
                  }
                  goto LAB_140030547;
                }
                uVar10 = uVar5 + *(ushort *)(pcVar13 + 2);
                if ((uVar10 < uVar5) || (uVar3 < uVar10)) goto LAB_140030489;
                uVar14 = uVar14 + 1;
                pcVar13 = pcVar13 + *(ushort *)(pcVar13 + 2);
              } while (uVar14 < uVar2);
            }
            *param_2 = piVar6;
            return uVar12;
          }
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) {
          uVar9 = 0x10;
          goto LAB_140030537;
        }
        goto LAB_140030547;
      }
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         (-1 < (char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c))) goto LAB_140030547;
      uVar9 = 0xf;
      goto LAB_140030537;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) {
      uVar9 = 0xe;
      goto LAB_140030537;
    }
  }
  else {
LAB_140030518:
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) {
      uVar9 = 0xc;
LAB_140030537:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,
              &WPP_0961c2f37d1b3ad2f2ca69bd50809778_Traceguids);
    }
  }
LAB_140030547:
  uVar12 = 0xc000000d;
LAB_14003054c:
  ExFreePoolWithTag(piVar6,0);
  return uVar12;
}



===== AppHashComputeImageHashInternal @ 140030594 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int AppHashComputeImageHashInternal
              (undefined8 param_1,undefined8 *param_2,uint param_3,undefined8 *param_4)

{
  bool bVar1;
  ulonglong *puVar2;
  int iVar3;
  int iVar4;
  ULONG UVar5;
  int *piVar6;
  ulonglong uVar7;
  int *piVar8;
  uint uVar9;
  ushort *puVar10;
  uint uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  int iVar14;
  ulonglong uVar15;
  undefined1 auStackY_f8 [32];
  int local_b8;
  int local_b4;
  ulonglong local_b0;
  undefined8 *local_a8;
  uint local_a0;
  uint local_9c;
  uint local_98;
  undefined8 local_90;
  ulonglong local_88;
  longlong local_80;
  ulonglong *local_78;
  undefined8 *local_70;
  undefined8 local_68;
  UCHAR local_60 [8];
  undefined8 local_58;
  ulonglong uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_b8 = 0;
  local_80 = 0;
  local_78 = (ulonglong *)0x0;
  local_48 = 0;
  local_b4 = 0;
  local_a0 = 0;
  local_98 = 0;
  local_90 = local_90 & 0xffffffff00000000;
  local_60[0] = '\0';
  local_60[1] = '\0';
  local_60[2] = '\0';
  local_60[3] = '\0';
  local_60[4] = '\0';
  local_60[5] = '\0';
  local_60[6] = '\0';
  local_60[7] = '\0';
  local_58 = 0;
  uStack_50 = 0;
  if (param_3 == 0) {
    return 0;
  }
  local_a8 = param_4;
  local_70 = param_2;
  local_68 = param_1;
  iVar3 = (*(code *)*param_2)(0,&local_58);
  uVar7 = uStack_50;
  if (iVar3 < 0) {
    return iVar3;
  }
  local_88 = uStack_50;
  piVar6 = (int *)ExAllocatePool2(0x42,0x10000);
  if (piVar6 == (int *)0x0) {
    return -0x3fffffe9;
  }
  local_b0 = 0;
  uVar12 = 0x10000;
  iVar3 = 0;
  uVar11 = 0;
  if (uVar7 != 0) {
    uVar15 = uVar7;
    do {
      local_9c = (uint)uVar15;
      if (uVar15 < uVar12) {
        uVar12 = uVar15 & 0xffffffff;
      }
      iVar4 = (*(code *)local_70[1])(local_68,&local_b0,uVar12);
      if (iVar4 < 0) goto LAB_140030a5c;
      if (local_b0 == 0) {
        uVar7 = AppHashIsPeImage(piVar6,(uint)uVar12,(uint *)&local_88,&local_b4,(int *)&local_a0,
                                 &local_80,(longlong *)&local_78);
        local_b8 = (int)uVar7;
        if (local_b8 == -0x3fffffdd) {
          uVar12 = (ulonglong)local_a0;
          if (uVar15 < uVar12) {
            uVar12 = (ulonglong)local_9c;
          }
          ExFreePoolWithTag(piVar6,0);
          piVar6 = (int *)ExAllocatePool2(0x42,uVar12,0x48707041);
          if (piVar6 == (int *)0x0) {
            return -0x3fffffe9;
          }
          iVar4 = (*(code *)local_70[1])(local_68,&local_b0,uVar12,piVar6);
          if (iVar4 < 0) goto LAB_140030a61;
          uVar7 = AppHashIsPeImage(piVar6,(uint)uVar12,(uint *)&local_88,&local_b4,(int *)&local_a0,
                                   &local_80,(longlong *)&local_78);
          local_b8 = (int)uVar7;
        }
        puVar2 = local_78;
        uVar7 = local_88;
        if ((local_b4 == 0) && (local_b8 < 0)) goto LAB_140030a5c;
        if (local_b0 != 0) {
LAB_140030921:
          iVar3 = local_b4;
          goto LAB_140030925;
        }
        if (local_b4 == 0) goto LAB_1400308b2;
        if (local_b8 < 0) goto LAB_140030921;
        local_90 = *local_78;
        local_98 = (uint)local_90;
        iVar3 = (int)local_78;
        iVar14 = (int)piVar6;
        if (((((int)(local_90 >> 0x20) != 0) && ((uint)local_90 != 0)) &&
            ((local_90 & 0xffffffff) < local_88)) &&
           (((iVar3 - iVar14) + 8U <= (uint)local_90 &&
            (uVar15 = local_90 & 0xffffffff, (uint)local_90 < (uint)uVar12)))) {
          uVar12 = local_90 & 0xffffffff;
        }
        iVar4 = AppHashHashBytes(param_3,local_a8,1,0,(PUCHAR)piVar6,(ULONG)uVar12);
        if (iVar4 < 0) goto LAB_140030a5c;
        iVar4 = AppHashHashBytes(param_3,local_a8,0,1,(PUCHAR)piVar6,(int)local_80 - iVar14);
        if (((iVar4 < 0) ||
            (iVar4 = AppHashHashBytes(param_3,local_a8,0,1,(PUCHAR)(local_80 + 4),
                                      (iVar3 - (int)local_80) - 4), iVar4 < 0)) ||
           (iVar4 = AppHashHashBytes(param_3,local_a8,0,1,(PUCHAR)(puVar2 + 1),
                                     (iVar14 - iVar3) + -8 + (ULONG)uVar12), iVar4 < 0))
        goto LAB_140030a5c;
        local_90 = CONCAT44(local_90._4_4_,local_90._4_4_);
      }
      else {
LAB_140030925:
        if ((iVar3 == 0) || (-1 < local_b8)) {
LAB_1400308b2:
          iVar3 = 1;
        }
        else {
          iVar3 = 0;
        }
        iVar4 = AppHashHashBytes(param_3,local_a8,1,iVar3,(PUCHAR)piVar6,(ULONG)uVar12);
        if (iVar4 < 0) goto LAB_140030a5c;
      }
      local_b0 = local_b0 + uVar12;
      uVar15 = uVar15 - uVar12;
      iVar3 = local_b4;
    } while (uVar15 != 0);
    uVar11 = local_98;
  }
  uVar12 = 0x10000;
  uVar9 = 0;
  if (param_3 != 0) {
    piVar8 = (int *)(local_a8 + 2);
    do {
      if (*piVar8 != 0) {
        if (((uint)local_90 != 0) && (uVar11 != 0)) {
          uVar15 = (ulonglong)uVar11;
          if (uVar15 < uVar7) {
            uVar13 = uVar7 - uVar15;
            local_b0 = uVar15;
            if (uVar13 != 0) goto LAB_140030958;
          }
        }
        break;
      }
      uVar9 = uVar9 + 1;
      piVar8 = piVar8 + 8;
    } while (uVar9 < param_3);
  }
  goto LAB_1400309c3;
  while( true ) {
    uVar12 = (ulonglong)uVar11;
    local_b0 = local_b0 + uVar11;
    uVar13 = uVar13 - uVar11;
    if (uVar13 == 0) break;
LAB_140030958:
    uVar11 = (uint)uVar13;
    if (uVar12 <= uVar13) {
      uVar11 = (uint)uVar12;
    }
    iVar4 = (*(code *)local_70[1])(local_68,&local_b0,uVar11);
    if ((iVar4 < 0) ||
       (iVar4 = AppHashHashBytes(param_3,local_a8,1,0,(PUCHAR)piVar6,uVar11), iVar4 < 0))
    goto LAB_140030a5c;
  }
LAB_1400309c3:
  if ((((iVar3 != 0) && (local_b8 < 0)) ||
      (UVar5 = ((int)uVar7 + 7U & 0xfffffff8) - (int)uVar7, UVar5 == 0)) ||
     (iVar4 = AppHashHashBytes(param_3,local_a8,0,1,local_60,UVar5), -1 < iVar4)) {
    if ((iVar3 == 0) || (-1 < local_b8)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    iVar4 = 0;
    uVar11 = 0;
    if (param_3 != 0) {
      puVar10 = (ushort *)((longlong)local_a8 + 0x14);
      iVar4 = 0;
      do {
        if (((*(int *)(puVar10 + -2) != 0) || (bVar1)) &&
           (iVar4 = BCryptFinishHash(*(BCRYPT_HASH_HANDLE *)(puVar10 + -10),*(PUCHAR *)(puVar10 + 2)
                                     ,(uint)*puVar10,0), iVar4 < 0)) break;
        uVar11 = uVar11 + 1;
        puVar10 = puVar10 + 0x10;
      } while (uVar11 < param_3);
    }
  }
LAB_140030a5c:
  if (piVar6 != (int *)0x0) {
LAB_140030a61:
    ExFreePoolWithTag(piVar6,0);
  }
  return iVar4;
}



===== AppHashDestroyHash @ 140030aa4 =====

void AppHashDestroyHash(undefined8 *param_1)

{
  if ((BCRYPT_HASH_HANDLE)*param_1 != (BCRYPT_HASH_HANDLE)0x0) {
    BCryptDestroyHash((BCRYPT_HASH_HANDLE)*param_1);
    *param_1 = 0;
  }
  if (param_1[1] != 0) {
    ExFreePoolWithTag(param_1[1],0);
    param_1[1] = 0;
  }
  return;
}



===== AppHashHashBytes @ 140030af0 =====

NTSTATUS AppHashHashBytes(uint param_1,undefined8 *param_2,int param_3,int param_4,PUCHAR param_5,
                         ULONG param_6)

{
  int iVar1;
  NTSTATUS NVar2;
  NTSTATUS NVar3;
  uint uVar4;
  
  NVar3 = 0;
  uVar4 = 0;
  NVar2 = 0;
  if (param_1 != 0) {
    do {
      NVar3 = NVar2;
      iVar1 = param_4;
      if (*(int *)(param_2 + 2) != 0) {
        iVar1 = param_3;
      }
      if ((iVar1 != 0) &&
         (NVar3 = BCryptHashData((BCRYPT_HASH_HANDLE)*param_2,param_5,param_6,0), NVar3 < 0)) {
        return NVar3;
      }
      uVar4 = uVar4 + 1;
      param_2 = param_2 + 4;
      NVar2 = NVar3;
    } while (uVar4 < param_1);
  }
  return NVar3;
}



===== AppHashInitHash @ 140030b7c =====

NTSTATUS AppHashInitHash(BCRYPT_HANDLE param_1,BCRYPT_HASH_HANDLE *param_2)

{
  NTSTATUS NVar1;
  PUCHAR pbHashObject;
  ULONG local_res10 [2];
  ULONG local_res18 [2];
  
  local_res10[0] = 0;
  local_res18[0] = 0;
  *param_2 = (BCRYPT_HASH_HANDLE)0x0;
  param_2[1] = (BCRYPT_HASH_HANDLE)0x0;
  param_2[2] = (BCRYPT_HASH_HANDLE)0x0;
  param_2[3] = (BCRYPT_HASH_HANDLE)0x0;
  NVar1 = BCryptGetProperty(param_1,L"HashDigestLength",(PUCHAR)((longlong)param_2 + 0x14),4,
                            local_res18,0);
  if ((-1 < NVar1) &&
     (NVar1 = BCryptGetProperty(param_1,L"ObjectLength",(PUCHAR)local_res10,4,local_res18,0),
     -1 < NVar1)) {
    pbHashObject = (PUCHAR)ExAllocatePool2(0x102,local_res10[0],0x48707041);
    param_2[1] = pbHashObject;
    if (pbHashObject == (PUCHAR)0x0) {
      NVar1 = -0x3fffffe9;
    }
    else {
      NVar1 = BCryptCreateHash(param_1,param_2,pbHashObject,local_res10[0],(PUCHAR)0x0,0,0);
      if (-1 < NVar1) {
        return NVar1;
      }
    }
  }
  AppHashDestroyHash(param_2);
  return NVar1;
}



===== AppHashIsPeImage @ 140030c8c =====

ulonglong AppHashIsPeImage(int *param_1,uint param_2,uint *param_3,undefined4 *param_4,int *param_5,
                          longlong *param_6,longlong *param_7)

{
  int iVar1;
  int *piVar2;
  longlong lVar3;
  ulonglong uVar4;
  int iVar5;
  uint uVar6;
  uint local_res8 [2];
  longlong local_48 [6];
  
  local_res8[0] = 0;
  local_res8[1] = 0;
  iVar5 = (int)(int *)((ulonglong)param_2 + (longlong)param_1);
  *param_4 = 0;
  *param_5 = 0;
  *param_6 = 0;
  *param_7 = 0;
  if ((uint)(iVar5 - (int)param_1) < 0x40) {
    *param_5 = param_2 + 0x40;
LAB_140030de7:
    uVar4 = 0xc0000023;
  }
  else {
    if ((short)*param_1 == 0x5a4d) {
      piVar2 = (int *)((longlong)param_1[0xf] + (longlong)param_1);
    }
    else {
      piVar2 = param_1;
    }
    if (param_1 <= piVar2) {
      iVar1 = 0xf8;
      if (((int *)((ulonglong)param_2 + (longlong)param_1) <= piVar2) ||
         (uVar6 = iVar5 - (int)piVar2, uVar6 < 0xf8)) {
LAB_140030de1:
        *param_5 = ((int)piVar2 - (int)param_1) + iVar1;
        goto LAB_140030de7;
      }
      if (*piVar2 != 0x4550) {
        return 0;
      }
      if (*(ushort *)(piVar2 + 5) == 0) {
        return 0;
      }
      if ((*(ushort *)(piVar2 + 5) & 7) != 0) {
        return 0;
      }
      if ((short)piVar2[6] == 0x10b) {
        if ((uint)piVar2[0x1d] < 5) {
          return 0;
        }
        lVar3 = 0x98;
      }
      else {
        if ((short)piVar2[6] != 0x20b) {
          return 0;
        }
        iVar1 = 0x108;
        if (uVar6 < 0x108) goto LAB_140030de1;
        if ((uint)piVar2[0x21] < 5) {
          return 0;
        }
        lVar3 = 0xa8;
      }
      *param_4 = 1;
      if (param_3[1] == 0) {
        local_48[0] = 0;
        local_48[1] = 0;
        local_48[2] = 0;
        local_48[3] = 0;
        local_48[4] = 0;
        local_48[5] = 0;
        uVar4 = HashpParsePEHeader(param_1,*param_3,param_2,local_res8,local_48);
        if ((int)uVar4 < 0) {
          return uVar4 & 0xffffffff;
        }
        *param_6 = (longlong)(piVar2 + 0x16);
        *param_7 = lVar3 + (longlong)piVar2;
        return uVar4 & 0xffffffff;
      }
    }
    uVar4 = 0xc0000095;
  }
  return uVar4;
}



===== AiConvertToTokenAttributes @ 140030e14 =====

undefined8
AiConvertToTokenAttributes
          (ushort *param_1,ushort *param_2,ushort *param_3,undefined8 param_4,undefined8 *param_5)

{
  undefined8 *puVar1;
  ushort uVar2;
  bool bVar3;
  undefined8 *_Dst;
  void *_Dst_00;
  undefined8 uVar4;
  int iVar5;
  uint uVar6;
  undefined2 *puVar7;
  
  if ((param_3 == (ushort *)0x0) || (bVar3 = true, *(longlong *)(param_3 + 4) == 0)) {
    bVar3 = false;
  }
  _Dst = (undefined8 *)ExAllocatePool2(0x102,0x50,0x44497041);
  if (_Dst == (undefined8 *)0x0) {
    uVar4 = 0xc0000017;
  }
  else {
    memset(_Dst,0,0x50);
    iVar5 = *param_2 + 4 + (uint)*param_1;
    if (bVar3) {
      uVar6 = iVar5 + (uint)*param_3;
    }
    else {
      uVar6 = iVar5 + 8;
    }
    if (uVar6 < 0x10000) {
      _Dst_00 = (void *)AiAlloc((ulonglong)uVar6);
      if (_Dst_00 != (void *)0x0) {
        memmove(_Dst_00,*(void **)(param_1 + 4),(ulonglong)*param_1);
        uVar2 = *param_1;
        *(undefined2 *)((ulonglong)uVar2 + (longlong)_Dst_00) = 0x5c;
        puVar7 = (undefined2 *)((ulonglong)uVar2 + (longlong)_Dst_00) + 1;
        memmove(puVar7,*(void **)(param_2 + 4),(ulonglong)*param_2);
        puVar7 = (undefined2 *)((longlong)puVar7 + (ulonglong)*param_2);
        *puVar7 = 0x5c;
        if (bVar3) {
          memmove(puVar7 + 1,*(void **)(param_3 + 4),(ulonglong)*param_3);
        }
        else {
          builtin_wcsncpy(puVar7 + 1,L"APPX",4);
        }
        puVar1 = _Dst + 1;
        *(short *)puVar1 = (short)uVar6;
        *(short *)((longlong)_Dst + 10) = (short)uVar6;
        _Dst[2] = _Dst_00;
        *_Dst = param_4;
        RtlUpcaseUnicodeString(puVar1,puVar1,0);
        *(undefined2 *)(_Dst + 5) = 4;
        _Dst[3] = 0x1a0018;
        _Dst[4] = L"APPID://FQBN";
        *(undefined4 *)(_Dst + 6) = 1;
        _Dst[7] = _Dst;
        *(undefined4 *)((longlong)_Dst + 0x2c) = 3;
        _Dst[9] = _Dst + 3;
        *(undefined2 *)(_Dst + 8) = 1;
        *(undefined2 *)((longlong)_Dst + 0x42) = 0;
        *(undefined4 *)((longlong)_Dst + 0x44) = 1;
        *param_5 = _Dst + 8;
        return 0;
      }
      uVar4 = 0xc0000017;
    }
    else {
      uVar4 = 0xc0000095;
    }
    ExFreePoolWithTag(_Dst,0);
  }
  return uVar4;
}



===== AiGetImageVersionInfo @ 140030fdc =====

int AiGetImageVersionInfo
              (longlong param_1,int param_2,undefined8 param_3,undefined4 *param_4,
              undefined4 *param_5,undefined4 *param_6,undefined4 *param_7,ushort *param_8,
              ushort *param_9)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  ushort *puVar5;
  int iVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  void *_Dst;
  ushort *puVar9;
  ushort **ppuVar10;
  longlong lVar11;
  ushort uVar12;
  ushort uVar13;
  uint uVar14;
  int local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  ushort *local_50 [3];
  
  local_50[0] = param_9;
  local_60 = 0;
  uStack_58 = 0;
  local_50[1] = param_8;
  uVar7 = AipGetPeImageVersionInfo
                    (param_1,param_4,param_5,param_6,param_7,(undefined8 *)param_8,
                     (undefined8 *)param_9);
  lVar11 = 2;
  local_68 = (int)uVar7;
  if (local_68 < 0) {
LAB_140031310:
    ppuVar10 = local_50;
    do {
      puVar5 = *ppuVar10;
      if (*(longlong *)(puVar5 + 4) != 0) {
        ExFreePoolWithTag(*(longlong *)(puVar5 + 4),0);
      }
      ppuVar10 = ppuVar10 + 1;
      puVar5[0] = 0;
      puVar5[1] = 0;
      puVar5[2] = 0;
      puVar5[3] = 0;
      puVar5[4] = 0;
      puVar5[5] = 0;
      puVar5[6] = 0;
      puVar5[7] = 0;
      lVar11 = lVar11 + -1;
    } while (lVar11 != 0);
  }
  else {
    uVar14 = 0;
    ppuVar10 = local_50;
    do {
      puVar5 = *ppuVar10;
      if (*puVar5 != 0) {
        uVar12 = *puVar5 >> 1;
        if (uVar12 != 0) {
          do {
            iVar6 = iswspace(*(wint_t *)(*(longlong *)(puVar5 + 4) + -2 + (ulonglong)uVar12 * 2));
            if (iVar6 == 0) break;
            *(undefined2 *)(*(longlong *)(puVar5 + 4) + -2 + (ulonglong)uVar12 * 2) = 0;
            uVar12 = uVar12 - 1;
          } while (uVar12 != 0);
        }
        *puVar5 = uVar12 * 2;
        uVar13 = 0;
        if ((ushort)(uVar12 * 2) != 0) {
          do {
            iVar6 = iswspace(*(wint_t *)(*(longlong *)(puVar5 + 4) + (ulonglong)uVar13 * 2));
            if (iVar6 == 0) break;
            uVar13 = uVar13 + 1;
          } while (uVar13 < *puVar5 >> 1);
          if (uVar13 != 0) {
            if (uVar13 != *puVar5 >> 1) {
              memmove(*(void **)(puVar5 + 4),
                      (void *)((ulonglong)uVar13 * 2 + (longlong)*(void **)(puVar5 + 4)),
                      (ulonglong)*puVar5 + (ulonglong)uVar13 * -2);
            }
            *puVar5 = *puVar5 + uVar13 * -2;
          }
        }
        if (*puVar5 == 0) {
          if (*(longlong *)(puVar5 + 4) != 0) {
            ExFreePoolWithTag();
          }
          puVar5[0] = 0;
          puVar5[1] = 0;
          puVar5[2] = 0;
          puVar5[3] = 0;
          puVar5[4] = 0;
          puVar5[5] = 0;
          puVar5[6] = 0;
          puVar5[7] = 0;
        }
        else {
          puVar9 = puVar5;
          RtlUpcaseUnicodeString(puVar5,puVar5,0);
          uVar8 = AiEncodeAttributeString(puVar5,puVar9,(short *)&local_60);
          local_68 = (int)uVar8;
          if (local_68 < 0) goto LAB_140031310;
          if (uStack_58 != 0) {
            if (*(longlong *)(puVar5 + 4) != 0) {
              ExFreePoolWithTag();
            }
            *(undefined4 *)puVar5 = (undefined4)local_60;
            *(undefined4 *)(puVar5 + 2) = local_60._4_4_;
            *(undefined4 *)(puVar5 + 4) = (undefined4)uStack_58;
            *(undefined4 *)(puVar5 + 6) = uStack_58._4_4_;
          }
        }
      }
      uVar14 = uVar14 + 1;
      ppuVar10 = ppuVar10 + 1;
    } while (uVar14 < 2);
    if (param_2 != 0) {
      uVar1 = *param_4;
      uVar2 = *param_7;
      uVar3 = *param_6;
      uVar4 = *param_5;
      uVar14 = *param_9 + 0x40 + (uint)*param_8;
      if ((uVar14 < 0x2001) && (_Dst = (void *)AiAlloc((ulonglong)uVar14), _Dst != (void *)0x0)) {
        memset(_Dst,0,(ulonglong)uVar14);
        *(undefined1 *)((longlong)_Dst + 5) = 0x1f;
        *(short *)((longlong)_Dst + 6) = (short)uVar14 + -0x28;
        builtin_strncpy((char *)((longlong)_Dst + 8),"$KERNEL.",8);
        builtin_strncpy((char *)((longlong)_Dst + 0x10),"PURGE.AP",8);
        *(undefined4 *)((longlong)_Dst + 0x28) = 0x31444941;
        *(undefined4 *)((longlong)_Dst + 0x2c) = uVar1;
        builtin_strncpy((char *)((longlong)_Dst + 0x18),"PID.VERS",8);
        builtin_strncpy((char *)((longlong)_Dst + 0x20),"IONINFO",8);
        *(undefined4 *)((longlong)_Dst + 0x30) = uVar4;
        *(undefined4 *)((longlong)_Dst + 0x34) = uVar3;
        *(undefined4 *)((longlong)_Dst + 0x38) = uVar2;
        *(ushort *)((longlong)_Dst + 0x3c) = *param_8;
        *(ushort *)((longlong)_Dst + 0x3e) = *param_9;
        if (*param_8 != 0) {
          memmove((void *)((longlong)_Dst + 0x40),*(void **)(param_8 + 4),(ulonglong)*param_8);
        }
        if (*param_9 != 0) {
          memmove((void *)((ulonglong)*param_8 + 0x40 + (longlong)_Dst),*(void **)(param_9 + 4),
                  (ulonglong)*param_9);
        }
        FsRtlSetKernelEaFile
                  (param_3,_Dst,
                   (uint)*(byte *)((longlong)_Dst + 5) + *(ushort *)((longlong)_Dst + 6) + 9);
        ExFreePoolWithTag(_Dst,0);
      }
    }
  }
  return local_68;
}



===== AiGetVersionInfoFromCache @ 140031364 =====

undefined4
AiGetVersionInfoFromCache
          (longlong param_1,uint param_2,undefined4 *param_3,undefined4 *param_4,undefined4 *param_5
          ,undefined4 *param_6,undefined8 *param_7,undefined8 *param_8)

{
  undefined2 uVar1;
  void *pvVar2;
  undefined4 uVar3;
  
  *param_7 = 0;
  param_7[1] = 0;
  *param_8 = 0;
  param_8[1] = 0;
  if ((param_2 < 0x40) || (*(int *)(param_1 + 0x28) != 0x31444941)) {
LAB_1400313a3:
    uVar3 = 0xfffffffe;
    goto LAB_14003147c;
  }
  if (((*(ushort *)(param_1 + 0x3c) & 1) != 0) || ((*(ushort *)(param_1 + 0x3e) & 1) != 0)) {
    uVar3 = 0xc000000d;
    goto LAB_14003147c;
  }
  if (param_2 != *(ushort *)(param_1 + 0x3c) + 0x40 + (uint)*(ushort *)(param_1 + 0x3e))
  goto LAB_1400313a3;
  *param_3 = *(undefined4 *)(param_1 + 0x2c);
  *param_4 = *(undefined4 *)(param_1 + 0x30);
  *param_5 = *(undefined4 *)(param_1 + 0x34);
  *param_6 = *(undefined4 *)(param_1 + 0x38);
  if (*(ushort *)(param_1 + 0x3c) == 0) {
LAB_140031439:
    if (*(ushort *)(param_1 + 0x3e) == 0) {
      return 0;
    }
    pvVar2 = (void *)AiAlloc((ulonglong)*(ushort *)(param_1 + 0x3e));
    param_8[1] = pvVar2;
    if (pvVar2 != (void *)0x0) {
      uVar1 = *(undefined2 *)(param_1 + 0x3e);
      *(undefined2 *)param_8 = uVar1;
      *(undefined2 *)((longlong)param_8 + 2) = uVar1;
      memmove(pvVar2,(void *)((ulonglong)*(ushort *)(param_1 + 0x3c) + 0x40 + param_1),
              (ulonglong)*(ushort *)(param_1 + 0x3e));
      return 0;
    }
  }
  else {
    pvVar2 = (void *)AiAlloc((ulonglong)*(ushort *)(param_1 + 0x3c));
    param_7[1] = pvVar2;
    if (pvVar2 != (void *)0x0) {
      uVar1 = *(undefined2 *)(param_1 + 0x3c);
      *(undefined2 *)param_7 = uVar1;
      *(undefined2 *)((longlong)param_7 + 2) = uVar1;
      memmove(pvVar2,(void *)(param_1 + 0x40),(ulonglong)*(ushort *)(param_1 + 0x3c));
      goto LAB_140031439;
    }
  }
  uVar3 = 0xc0000017;
LAB_14003147c:
  if (param_7[1] != 0) {
    ExFreePoolWithTag(param_7[1],0);
    *param_7 = 0;
    param_7[1] = 0;
  }
  if (param_8[1] != 0) {
    ExFreePoolWithTag(param_8[1],0);
    *param_8 = 0;
    param_8[1] = 0;
  }
  return uVar3;
}



===== AipCheckBlock @ 1400314dc =====

longlong AipCheckBlock(ushort *param_1,uint param_2)

{
  ushort uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  ushort *puVar5;
  longlong lVar6;
  
  lVar6 = 0;
  if (7 < (int)param_2) {
    uVar1 = *param_1;
    if ((7 < uVar1) && (uVar1 <= param_2)) {
      puVar5 = param_1 + 3;
      uVar3 = (ulonglong)uVar1 - 6 >> 1;
      if ((puVar5 != (ushort *)0x0) && (uVar2 = uVar3, uVar3 < 0x80000000)) {
        for (; (uVar2 != 0 && (*puVar5 != 0)); puVar5 = puVar5 + 1) {
          uVar2 = uVar2 - 1;
        }
        if ((uVar2 != 0) &&
           (uVar4 = (((int)uVar3 - (int)uVar2) * 2 + 0xbU & 0xfffffffc) + (uint)param_1[1],
           uVar4 <= uVar1)) {
          uVar4 = uVar4 + 3 & 0xfffffffc;
          if (param_2 < uVar4) {
            uVar4 = param_2;
          }
          lVar6 = (ulonglong)uVar4 + (longlong)param_1;
        }
      }
    }
  }
  return lVar6;
}



===== AipGetPeImageVersionInfo @ 140031578 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong AipGetPeImageVersionInfo
                    (longlong param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                    undefined4 *param_5,undefined8 *param_6,undefined8 *param_7)

{
  ushort *puVar1;
  code *pcVar2;
  uint uVar3;
  short *_Src;
  uint uVar4;
  undefined8 uVar5;
  void *_Dst;
  ulonglong uVar6;
  ulonglong uVar7;
  int iVar8;
  ushort uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined1 auStack_288 [32];
  ushort **local_268;
  ulonglong *local_260;
  undefined8 local_258;
  undefined8 local_250;
  uint local_248;
  int local_244;
  ulonglong local_240;
  ushort *local_238;
  uint local_230;
  ulonglong local_228;
  ushort *local_220;
  ushort *local_218;
  longlong local_210;
  short *local_208;
  longlong local_200;
  ulonglong local_1f8;
  ushort *local_1f0;
  longlong local_1e8;
  ushort *local_1e0;
  longlong local_1d8;
  longlong local_1d0;
  short *local_1c8;
  ulonglong local_1c0;
  undefined8 *local_1b8 [2];
  longlong local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  ushort local_148 [128];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_288;
  local_1a8 = 0;
  uStack_1a0 = 0;
  local_198 = 0;
  uStack_190 = 0;
  local_188 = 0;
  local_220 = (ushort *)0x0;
  local_238 = (ushort *)0x0;
  local_228 = 0;
  local_240 = 0;
  local_208 = (short *)0x0;
  local_180 = 0;
  uStack_178 = 0;
  local_170 = 0;
  uStack_168 = 0;
  local_160 = 0;
  uStack_158 = 0;
  local_244 = 0;
  local_1b8[0] = param_7;
  local_1b8[1] = param_6;
  *param_7 = 0;
  param_7[1] = 0;
  *param_6 = 0;
  param_6[1] = 0;
  uVar4 = SrppMapFileImage(param_1,&local_1a8);
  iVar8 = 0;
  if ((int)uVar4 < 0) goto LAB_140031a86;
  if ((char)local_188 == '\0') {
    KeStackAttachProcess(*(undefined8 *)PsInitialSystemProcess_exref,&local_180);
    local_244 = 1;
  }
  local_250 = 0;
  local_258 = 0;
  local_260 = &local_228;
  local_268 = &local_220;
  local_248 = LdrResSearchResource(uStack_1a0,&DAT_14000c628,3,0x1210);
  if (((((int)local_248 < 0) || (local_228 < 0x5c)) || (local_228 < *local_220)) ||
     (*(int *)(local_220 + 0x14) != -0x110fb43)) {
LAB_140031a6b:
    uVar4 = 0xfffffffe;
LAB_140031a70:
    local_248 = uVar4;
  }
  else {
    *param_2 = *(undefined4 *)(local_220 + 0x18);
    *param_3 = *(undefined4 *)(local_220 + 0x1a);
    *param_4 = *(undefined4 *)(local_220 + 0x1c);
    *param_5 = *(undefined4 *)(local_220 + 0x1e);
    uVar5 = AipQueryValue(local_220,L"\\VarFileInfo\\Translation",(longlong *)&local_238,&local_240)
    ;
    uVar4 = (uint)uVar5;
    local_248 = uVar4;
    if (-1 < (int)uVar4) {
      if ((local_240 < 4) || ((~(uint)local_238 & 1) == 0)) goto LAB_140031a6b;
      local_268 = (ushort **)CONCAT44(local_268._4_4_,(uint)local_238[1]);
      RtlStringCbPrintfW(local_148,0x100,(ushort *)L"\\StringFileInfo\\%04x%04x\\",
                         (ulonglong)*local_238);
      uVar10 = 0xffffffffffffffff;
      do {
        uVar10 = uVar10 + 1;
      } while (local_148[uVar10] != 0);
      local_230 = 0;
      while (uVar3 = local_230, local_230 < 2) {
        if (0xff < (uVar10 & 0xffffffff) * 2) {
          __report_rangecheckfailure();
          pcVar2 = (code *)swi(3);
          uVar10 = (*pcVar2)();
          return uVar10;
        }
        local_148[uVar10 & 0xffffffff] = 0;
        uVar11 = (ulonglong)local_230;
        local_1e8 = 0x80;
        for (local_1f0 = local_148; (local_1e8 != 0 && (*local_1f0 != 0)); local_1f0 = local_1f0 + 1
            ) {
          local_1e8 = local_1e8 + -1;
        }
        iVar8 = 0;
        if (local_1e8 == 0) {
          iVar8 = -0x3ffffff3;
        }
        if (iVar8 < 0) {
          local_238 = (ushort *)0x0;
        }
        else {
          local_238 = (ushort *)(0x80 - local_1e8);
          local_1d0 = 0x7ffffffe;
          local_218 = local_148 + (longlong)local_238;
          local_210 = 0;
          local_1e0 = *(ushort **)(&DAT_1400086f0 + uVar11 * 8);
          for (local_1d8 = 0x80 - (longlong)local_238; local_1d8 != 0; local_1d8 = local_1d8 + -1) {
            if ((local_1d0 == 0) || (*local_1e0 == 0)) {
              if (local_1d8 != 0) goto LAB_1400318db;
              break;
            }
            *local_218 = *local_1e0;
            local_218 = local_218 + 1;
            local_1e0 = local_1e0 + 1;
            local_1d0 = local_1d0 + -1;
            local_210 = local_210 + 1;
          }
          local_218 = local_218 + -1;
          local_210 = local_210 + -1;
LAB_1400318db:
          *local_218 = 0;
        }
        uVar5 = AipQueryValue(local_220,(short *)local_148,(longlong *)&local_208,&local_240);
        _Src = local_208;
        uVar4 = (uint)uVar5;
        if (((int)uVar4 < 0) || (0xfffe < local_240 - 1)) {
          uVar4 = 0;
          local_248 = 0;
          uVar6 = local_240;
        }
        else {
          uVar6 = local_240 & 0xfffffffffffffffe;
          local_248 = uVar4;
          if (uVar6 != 0) {
            local_240 = local_240 >> 1;
            local_200 = 0;
            if ((local_208 == (short *)0x0) || (0x7fffffff < local_240)) {
              iVar8 = -0x3ffffff3;
            }
            else {
              local_1c0 = local_240;
              for (local_1c8 = local_208; (local_1c0 != 0 && (*local_1c8 != 0));
                  local_1c8 = local_1c8 + 1) {
                local_1c0 = local_1c0 - 1;
              }
              iVar8 = 0;
              if (local_1c0 == 0) {
                iVar8 = -0x3ffffff3;
              }
              if (iVar8 < 0) {
                local_200 = 0;
              }
              else {
                local_200 = local_240 - local_1c0;
              }
            }
            if (iVar8 < 0) {
              local_1f8 = 0;
              uVar7 = uVar6;
            }
            else {
              uVar7 = local_200 * 2;
              local_1f8 = uVar7;
              if (uVar7 == 0) goto LAB_140031a5e;
            }
            uVar7 = uVar7 + 2;
            local_240 = uVar7;
            _Dst = (void *)AiAlloc(uVar7);
            puVar1 = (ushort *)local_1b8[uVar11];
            *(void **)(puVar1 + 4) = _Dst;
            if (_Dst == (void *)0x0) {
              uVar4 = 0xc0000017;
              goto LAB_140031a70;
            }
            uVar9 = (short)uVar7 - 2;
            *puVar1 = uVar9;
            puVar1[1] = uVar9;
            memmove(_Dst,_Src,(ulonglong)uVar9);
            *(undefined2 *)(*(longlong *)(puVar1 + 4) + (ulonglong)(*puVar1 >> 1) * 2) = 0;
            uVar6 = local_240;
          }
        }
LAB_140031a5e:
        local_240 = uVar6;
        local_230 = uVar3 + 1;
      }
    }
  }
  iVar8 = local_244;
LAB_140031a86:
  if (iVar8 != 0) {
    KeUnstackDetachProcess(&local_180);
  }
  SrppUnmapFileImage(&local_1a8);
  return (ulonglong)uVar4;
}



===== AipQueryValue @ 140031ae0 =====

undefined8 AipQueryValue(ushort *param_1,short *param_2,longlong *param_3,ulonglong *param_4)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  ushort *puVar5;
  longlong lVar6;
  ulonglong uVar8;
  ulonglong uVar7;
  uint uVar9;
  uint uVar10;
  ushort *puVar11;
  short *psVar12;
  undefined8 local_48;
  short *psStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_48 = 0;
  psStack_40 = (short *)0x0;
  local_38 = 0;
  uStack_30 = 0;
  if (((param_1[2] == 0) && ((ushort)(*param_1 - 8) < 0x7ff9)) && ((*param_1 & 1) == 0)) {
    while( true ) {
      while (psVar12 = param_2, *psVar12 == 0x5c) {
        param_2 = psVar12 + 1;
      }
      puVar5 = (ushort *)AipCheckBlock(param_1,(uint)*param_1);
      if (puVar5 == (ushort *)0x0) break;
      sVar2 = *psVar12;
      param_2 = psVar12;
      if (sVar2 == 0) {
        uVar8 = 0xffffffffffffffff;
        do {
          uVar7 = uVar8 + 1;
          lVar6 = uVar8 + 4;
          uVar8 = uVar7;
        } while (param_1[lVar6] != 0);
        uVar1 = param_1[1];
        uVar9 = (uint)uVar1;
        uVar10 = (int)uVar7 * 2 + 0xbU & 0xfffffffc;
        if ((uVar1 == 0) || ((param_1[2] == 0 && (uVar1 < 2)))) {
          *param_3 = (longlong)(param_1 + (uVar7 & 0xffffffff) + 3);
          *param_4 = 2;
        }
        else {
          if (param_1[2] == 1) {
            uVar4 = *param_1 - uVar10;
            uVar9 = (uint)uVar1 * 2;
            if (uVar4 <= (uint)uVar1 * 2) {
              uVar9 = uVar4;
            }
            uVar9 = uVar9 & 0xfffffffe;
          }
          *param_4 = (ulonglong)uVar9;
          *param_3 = (ulonglong)uVar10 + (longlong)param_1;
        }
        return 0;
      }
      do {
        if (sVar2 == 0x5c) break;
        param_2 = param_2 + 1;
        sVar2 = *param_2;
      } while (sVar2 != 0);
      puVar11 = (ushort *)((ulonglong)*param_1 + (longlong)param_1);
      while( true ) {
        lVar6 = AipCheckBlock(puVar5,(int)puVar11 - (int)puVar5);
        if (lVar6 == 0) {
          return 0xfffffffe;
        }
        RtlInitUnicodeString(&local_38,puVar5 + 3);
        sVar2 = (short)param_2 - (short)psVar12;
        local_48._0_4_ = CONCAT22(sVar2,sVar2);
        psStack_40 = psVar12;
        iVar3 = RtlCompareUnicodeString(&local_48,&local_38,1);
        param_1 = puVar5;
        if (iVar3 == 0) break;
        puVar5 = (ushort *)((longlong)puVar5 + ((ulonglong)*puVar5 + 3 & 0xfffffffffffffffc));
        if (puVar11 <= puVar5) {
          return 0xfffffffe;
        }
      }
    }
  }
  return 0xfffffffe;
}



===== AiRpcDisconnect @ 140031ca8 =====

undefined8 AiRpcDisconnect(RPC_BINDING_HANDLE *param_1)

{
  int iVar1;
  RPC_STATUS RVar2;
  
  iVar1 = RpcBindingUnbind(*param_1);
  if ((iVar1 == 0) && (RVar2 = RpcBindingFree(param_1), RVar2 == 0)) {
    *param_1 = (RPC_BINDING_HANDLE)0x0;
    return 0;
  }
  return 0xc0000001;
}



===== AiVerifyPackageMoniker @ 140031cfc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong AiVerifyPackageMoniker
                    (undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined8 *param_4,
                    undefined8 *param_5,undefined4 *param_6,undefined8 *param_7)

{
  uint uVar1;
  ulonglong uVar2;
  undefined1 auStack_128 [32];
  undefined8 *local_108;
  undefined4 *local_100;
  undefined8 *local_f8;
  undefined8 *local_f0;
  undefined8 *local_e8;
  uint local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  _RPC_ASYNC_STATE local_a8;
  
  local_a8.Reserved[2] = __security_cookie ^ (ulonglong)auStack_128;
  local_d8 = 0xc0000001;
  local_c0 = 0;
  uStack_b8 = 0;
  local_b0 = 0;
  local_d0 = param_2;
  local_c8 = param_1;
  memset(&local_a8,0,0x58);
  *param_3 = 0;
  *param_4 = 0;
  *param_5 = 0;
  *param_6 = 0;
  *param_7 = 0;
  uVar2 = AipInitRpc(&local_a8,(PFN_RPCNOTIFICATION_ROUTINE)&local_c0);
  if (-1 < (int)uVar2) {
    local_f8 = param_7;
    local_100 = param_6;
    local_108 = param_5;
    local_f0 = param_4;
    local_e8 = param_3;
    ClientAppIDRpcVerifyPackageMoniker(&local_a8);
    uVar1 = AipCompleteRpc(0,&local_a8,&local_c0);
    uVar2 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      uVar2 = (ulonglong)local_d8;
    }
  }
  return uVar2;
}



===== AipCompleteRpc @ 140031e18 =====

uint AipCompleteRpc(int param_1,PRPC_ASYNC_STATE param_2,undefined8 param_3)

{
  int iVar1;
  RPC_STATUS RVar2;
  
  if (param_1 == 0) {
    iVar1 = KeWaitForSingleObject(param_3,0,0,0,0);
    if (iVar1 == 0) {
      RVar2 = RpcAsyncCompleteCall(param_2,(void *)0x0);
      return -(uint)(RVar2 != 0) & 0xc0000001;
    }
    RVar2 = RpcAsyncCancelCall(param_2,1);
    if (RVar2 == 0) {
      KeWaitForSingleObject(param_3,0,0,0,0);
    }
  }
  return 0xc0000001;
}



===== AipInitRpc @ 140031eb4 =====

undefined8 AipInitRpc(PRPC_ASYNC_STATE param_1,PFN_RPCNOTIFICATION_ROUTINE param_2)

{
  RPC_STATUS RVar1;
  undefined8 uVar2;
  
  RVar1 = RpcAsyncInitializeHandle(param_1,0x58);
  if (RVar1 == 0) {
    param_1->UserInfo = (void *)0x0;
    param_1->NotificationType = RpcNotificationTypeEvent;
    KeInitializeEvent(param_2,0,0);
    uVar2 = 0;
    (param_1->u).APC.NotificationRoutine = param_2;
  }
  else {
    uVar2 = 0xc0000001;
  }
  return uVar2;
}



===== MIDL_user_allocate @ 140031f20 =====

void * __stdcall MIDL_user_allocate(size_t size)

{
  void *pvVar1;
  
  pvVar1 = (void *)AiAlloc(size);
  return pvVar1;
}



===== EdpPluginNotifyRoutine @ 140031f40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
EdpPluginNotifyRoutine
          (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6,longlong param_7,undefined8 param_8,
          undefined4 *param_9)

{
  code *pcVar1;
  bool bVar2;
  ushort *puVar3;
  wchar_t *pwVar4;
  int iVar5;
  uint uVar6;
  wchar_t *pwVar7;
  longlong lVar8;
  ushort *puVar9;
  undefined8 uVar10;
  uint *puVar11;
  undefined1 *puVar12;
  ushort **ppuVar13;
  undefined1 *puVar14;
  undefined1 auStackY_3d8 [32];
  char in_stack_fffffffffffffc50;
  char local_398 [4];
  uint local_394;
  undefined1 *local_390;
  uint local_388 [2];
  ushort *local_380;
  undefined1 *local_378;
  longlong local_370;
  undefined8 local_368;
  wchar_t *local_360;
  undefined1 *local_358;
  undefined8 local_350;
  short *local_348;
  wchar_t *local_340;
  longlong local_338;
  undefined8 local_330;
  longlong local_328;
  undefined8 local_320;
  undefined8 local_318;
  undefined8 local_310;
  undefined4 local_308;
  undefined8 local_300;
  undefined8 local_2f8;
  undefined8 local_2f0;
  undefined4 *local_2e8;
  short local_2e0 [4];
  longlong lStack_2d8;
  undefined8 local_2c8 [4];
  wchar_t *local_2a8;
  int local_2a0;
  undefined4 local_29c;
  uint *local_298;
  undefined8 local_290;
  undefined8 local_288;
  uint local_280 [2];
  uint *local_278;
  undefined8 local_270;
  wchar_t local_268 [264];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_3d8;
  local_2f0 = param_6;
  local_2f8 = param_8;
  puVar12 = (undefined1 *)0x0;
  local_2e8 = param_9;
  local_378 = (undefined1 *)0x0;
  local_388[0] = 0;
  local_380 = (ushort *)0x0;
  local_370 = 0;
  local_394 = 0;
  local_368 = param_3;
  memset(&local_358,0,0x60);
  local_398[0] = '\0';
  local_2e0[0] = 0;
  local_2e0[1] = 0;
  local_2e0[2] = 0;
  local_2e0[3] = 0;
  lStack_2d8 = 0;
  iVar5 = RtlRunOnceExecuteOnce(&DAT_1400184d8,EdppInitializeCallback,0,0);
  bVar2 = true;
  if (iVar5 < 0) {
    puVar14 = puVar12;
    goto LAB_1400321b9;
  }
  ExAcquirePushLockSharedEx(&EdppRuntimeConfig,0);
  local_390 = &DAT_140018528;
  if (DAT_140018528 == '\0') {
    puVar14 = &DAT_140018528;
    goto LAB_1400321b9;
  }
  if ((DAT_14001852c != 0) && (DAT_140018548 != 0)) {
    if ((*(uint *)(param_7 + 8) & 1) == 0) {
      iVar5 = SeLocateProcessImageName(param_4,&local_340);
      if (iVar5 < 0) goto LAB_1400321a3;
    }
    else {
      local_340 = *(wchar_t **)(param_7 + 0x30);
    }
    iVar5 = AiOpenImageFile(local_340,*(longlong *)(param_7 + 0x28),&local_338);
    if ((-1 < iVar5) && (iVar5 = AiCapturePackageMoniker(param_4,local_398,0,local_2e0), -1 < iVar5)
       ) {
      iVar5 = AiOpenTokenByProcessId(param_5,&local_370);
      puVar14 = local_390;
      if (-1 < iVar5) {
        local_328 = local_370;
        puVar11 = &local_394;
        local_320 = local_2f8;
        local_330 = local_2f0;
        local_318 = *(undefined8 *)(param_7 + 0x28);
        local_300 = local_368;
        local_348 = local_2e0;
        local_358 = local_390;
        local_350 = param_4;
        local_310 = param_1;
        local_308 = param_2;
        iVar5 = EdpPluginEvaluate((uint *)&local_358,puVar11,(ulonglong *)&local_378,&local_380,
                                  local_388);
        puVar12 = local_378;
        uVar6 = local_388[0];
        if (-1 < iVar5) {
          if (((local_388[0] == 0) || (((ulonglong)local_378 & 1) != 0)) &&
             (((ulonglong)local_378 & 2) == 0)) {
            puVar11 = *(uint **)(param_7 + 0x10);
            local_398[0] = '\0';
            EdppSMBFileOverride((longlong *)&local_358,puVar11,local_398);
            if (local_398[0] != '\0') {
              puVar12 = (undefined1 *)((ulonglong)puVar12 | 0x11);
            }
          }
          if (DAT_14001852c == 1) {
            puVar12 = (undefined1 *)((ulonglong)puVar12 | 0x80);
          }
          EdpPluginAction((longlong)&local_358,puVar11,(ulonglong)puVar12,local_380,uVar6,
                          in_stack_fffffffffffffc50,0);
        }
        goto LAB_1400321b9;
      }
    }
  }
LAB_1400321a3:
  puVar14 = local_390;
LAB_1400321b9:
  pwVar4 = local_340;
  pwVar7 = (wchar_t *)0x0;
  if (DAT_140018000 != 0) {
    local_268[0] = L'\0';
    if (((local_340 != (wchar_t *)0x0) && (*(void **)(local_340 + 4) != (void *)0x0)) &&
       ((ushort)*local_340 < 0x208)) {
      memmove(local_268,*(void **)(local_340 + 4),(ulonglong)(ushort)*local_340);
      if (0x207 < ((ulonglong)(ushort)*pwVar4 & 0xfffffffffffffffe)) {
        __report_rangecheckfailure();
        pcVar1 = (code *)swi(3);
        uVar10 = (*pcVar1)();
        return uVar10;
      }
      *(undefined2 *)((longlong)local_268 + ((ulonglong)(ushort)*pwVar4 & 0xfffffffffffffffe)) = 0;
      pwVar7 = wcsrchr(local_268,L'\\');
      if ((pwVar7 != (wchar_t *)0x0) && (*pwVar7 == L'\\')) {
        pwVar7 = pwVar7 + 1;
      }
    }
    if ((local_394 == 0xc0000364) && (((ulonglong)puVar12 & 2) != 0)) {
      local_360 = L"APPID://FQBN";
      ppuVar13 = &local_380;
      local_380 = (ushort *)0x0;
      local_368 = 0x1a0018;
      uVar6 = SrpGetAttributeFromToken(local_328,(longlong)&local_368,1,ppuVar13,(undefined8 *)0x0);
      puVar3 = local_380;
      if (4 < DAT_140018000) {
        if (((_DAT_140018010 & 0x400000000000) == 0) ||
           ((DAT_140018018 & 0x400000000000) != DAT_140018018)) {
          bVar2 = false;
        }
        if (bVar2) {
          local_2a8 = L"NA";
          if (pwVar7 != (wchar_t *)0x0) {
            local_2a8 = pwVar7;
          }
          lVar8 = -1;
          do {
            lVar8 = lVar8 + 1;
          } while (local_2a8[lVar8] != L'\0');
          local_2a0 = (int)lVar8 * 2 + 2;
          local_298 = local_280;
          local_29c = 0;
          puVar9 = (ushort *)&local_368;
          if (local_380 != (ushort *)0x0) {
            puVar9 = local_380;
          }
          local_288 = *(undefined8 *)(puVar9 + 4);
          local_278 = &local_394;
          local_290 = 2;
          local_280[0] = (uint)*puVar9;
          local_280[1] = 0;
          local_270 = 4;
          local_394 = uVar6;
          _tlgWriteTransfer_EtwWriteTransfer
                    ((ulonglong)*puVar9,&DAT_140015120,(ulonglong)uVar6,ppuVar13,6,local_2c8);
        }
      }
      SrpDeleteEnterpriseContext((longlong)puVar3);
    }
  }
  if ((local_340 != (wchar_t *)0x0) && (local_340 != *(wchar_t **)(param_7 + 0x30))) {
    ExFreePoolWithTag(local_340,0);
  }
  if (local_370 != 0) {
    ZwClose();
  }
  if (local_338 != 0) {
    ZwClose();
  }
  if (lStack_2d8 != 0) {
    ExFreePoolWithTag(lStack_2d8,0);
  }
  *local_2e8 = 0;
  if (puVar14 != (undefined1 *)0x0) {
    ExReleasePushLockSharedEx(&EdppRuntimeConfig,0);
  }
  return 0;
}



===== EdppAppEventsPurgeCallback @ 140032430 =====

undefined8 EdppAppEventsPurgeCallback(undefined8 param_1)

{
  uint uVar1;
  int iVar2;
  ushort *local_18 [3];
  
  local_18[0] = (ushort *)0x0;
  uVar1 = EdpGetLogFullPathFromRelativePath(param_1,local_18);
  if ((int)uVar1 < 0) goto LAB_1400324bc;
  ExAcquirePushLockExclusiveEx(&EdppAuditSessionLock,0);
  if (EdppAuditEnabled == '\0') {
LAB_140032476:
    EdppAuditEnabled = '\0';
    EdppDeleteLogFile(local_18[0]);
    if (EdppShuttingDown == '\0') {
      iVar2 = EdppDoWorkAsSystem(EdppEnableAudit);
      if (-1 < iVar2) {
        EdppAuditEnabled = '\x01';
      }
    }
  }
  else {
    iVar2 = EdppDoWorkAsSystem(EdppDisableAudit);
    if (-1 < iVar2) goto LAB_140032476;
  }
  ExReleasePushLockEx(&EdppAuditSessionLock,0);
LAB_1400324bc:
  if (local_18[0] != (ushort *)0x0) {
    ExFreePoolWithTag(local_18[0],0);
  }
  return 0;
}



===== EdppInitializeCallback @ 1400324f0 =====

byte EdppInitializeCallback(undefined8 param_1)

{
  byte bVar1;
  int iVar2;
  int local_res20 [2];
  undefined8 local_28;
  wchar_t *local_20;
  undefined8 local_18;
  wchar_t *local_10;
  
  local_res20[0] = 0;
  local_10 = L"\\REGISTRY\\MACHINE\\System\\CurrentControlSet\\Control\\AppID\\Configuration\\EDP";
  local_18 = 0x960094;
  local_20 = L"EdpDisableAudit";
  local_28 = 0x20001e;
  iVar2 = AiRegReadDwordValue(param_1,&local_18,&local_28,local_res20);
  if ((iVar2 < 0) || (local_res20[0] != 1)) {
    iVar2 = EdppDoWorkAsSystem(EdppEnableAudit);
    EdppAuditEnabled = (byte)((uint)iVar2 >> 0x1f) ^ 1;
    if (EdppAuditEnabled != 0) {
      ExSubscribeWnfStateChange
                (&EdppPurgeWnfEvtHandle,&WNF_EDP_PURGE_APP_LEARNING_EVT,1,0,
                 EdppAppEventsPurgeCallback,0);
    }
    EdpInitPluginRuntimeConfig();
    bVar1 = EdppAuditEnabled;
  }
  else {
    bVar1 = 1;
  }
  return bVar1;
}



===== EdppIsApplicationClaimSet @ 1400325ac =====

int EdppIsApplicationClaimSet(int param_1,longlong param_2,byte *param_3)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  int local_res8 [2];
  undefined4 local_res18 [2];
  longlong local_res20;
  
  lVar2 = 0;
  local_res20 = 0;
  local_res8[0] = 0;
  local_res18[0] = 0;
  *param_3 = 0;
  if (param_1 == 1) {
    iVar1 = 1;
LAB_1400326a0:
    lVar3 = *(longlong *)(param_2 + 0x20);
  }
  else {
    if ((**(longlong **)(param_2 + 0x48) != 0x4896ef1a58125a50) ||
       ((*(longlong **)(param_2 + 0x48))[1] != 0x6ccab39ac6d657ba)) {
      iVar1 = 0;
      goto LAB_1400326a0;
    }
    lVar2 = PsReferencePrimaryToken(*(undefined8 *)(param_2 + 8));
    iVar1 = ObOpenObjectByPointer(lVar2,0x200,0,8,0,0,&local_res20);
    if (iVar1 < 0) goto LAB_1400326ab;
    ZwQueryInformationToken(*(undefined8 *)(param_2 + 0x30),0x1d,local_res8,4,local_res18);
    if (local_res8[0] != 0) {
      RtlCapabilityCheck(local_res20,&enterpriseDataPolicyCapability);
      goto LAB_1400326ab;
    }
    lVar3 = *(longlong *)(param_2 + 0x20);
    iVar1 = 0;
  }
  iVar1 = SrppIsApplicationEDPResourceSetKernel(iVar1,lVar3,param_3);
LAB_1400326ab:
  if (local_res20 != 0) {
    ZwClose();
  }
  if (lVar2 != 0) {
    PsDereferencePrimaryToken(lVar2);
  }
  return iVar1;
}



===== EdppIsAppxLineOfBusiness @ 1400326ec =====

undefined8 EdppIsAppxLineOfBusiness(longlong param_1,undefined1 *param_2)

{
  undefined8 uVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 local_res8;
  
  uVar1 = *(undefined8 *)(param_1 + 8);
  uVar4 = 0;
  local_res8 = 0;
  *param_2 = 0;
  lVar3 = PsReferencePrimaryToken(uVar1);
  if (lVar3 == 0) {
    uVar4 = 0xc000000d;
  }
  else {
    iVar2 = RtlQueryPackageClaims(lVar3,0,0,0,0,0,&local_res8,0);
    ObfDereferenceObject(lVar3);
    if (-1 < iVar2) {
      *param_2 = local_res8._4_1_ == '\x06';
    }
  }
  return uVar4;
}



===== EdppRemoveIntentEnterpriseIdToken @ 140032798 =====

void EdppRemoveIntentEnterpriseIdToken(longlong param_1,undefined8 param_2)

{
  SrpSetIntentEnterpriseIdToken(param_1,param_2,(undefined2 *)0x0);
  return;
}



===== EdppSMBFileOverride @ 1400327b0 =====

int EdppSMBFileOverride(longlong *param_1,undefined8 param_2,undefined1 *param_3)

{
  longlong *plVar1;
  int iVar2;
  ulonglong uVar3;
  char cVar4;
  longlong lVar5;
  char cVar6;
  char local_res8 [16];
  char local_res18 [8];
  char local_res20 [8];
  longlong local_68;
  longlong local_60 [5];
  
  local_68 = 0;
  cVar4 = '\0';
  local_res8[0] = '\0';
  local_res18[0] = '\0';
  lVar5 = 0;
  local_res20[0] = '\0';
  local_60[0] = 0;
  plVar1 = (longlong *)param_1[9];
  local_60[1] = 0;
  local_60[2] = 0;
  *param_3 = 0;
  local_60[3] = 0;
  local_60[4] = 0;
  if ((*plVar1 == DAT_140018198) && (plVar1[1] == DAT_1400181a0)) {
    iVar2 = 0;
  }
  else {
    EdppIsEnterpriseSMBFile(param_1,local_res8);
    iVar2 = PsLookupProcessByProcessId(param_2,&local_68);
    if (-1 < iVar2) {
      SeCaptureSubjectContextEx(0,local_68,local_60 + 1);
      if (local_res8[0] == '\0') {
        SrpIsSubjectService(local_60 + 1,local_res18);
        uVar3 = SrpGetPolicyFlags(local_60 + 1,local_60);
        iVar2 = (int)uVar3;
        lVar5 = local_60[0];
        cVar4 = local_res18[0];
        cVar6 = '\0';
      }
      else {
        iVar2 = SrpIsEnterpriseAllowed(local_60 + 1,*(longlong *)(*param_1 + 0x18),local_res20);
        cVar6 = local_res20[0];
      }
      SeReleaseSubjectContext(local_60 + 1);
      if ((cVar6 != '\0') || ((cVar4 == '\0' && (lVar5 == 0x11)))) {
        *param_3 = 1;
      }
    }
    if (local_68 != 0) {
      ObfDereferenceObject();
    }
  }
  return iVar2;
}



===== EdpInitPluginRuntimeConfig @ 1400328e8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void EdpInitPluginRuntimeConfig(void)

{
  int iVar1;
  size_t sVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  wchar_t *_Src;
  int local_res8 [2];
  uint local_res10 [2];
  uint local_res18 [2];
  longlong local_res20;
  undefined8 local_48;
  wchar_t *local_40;
  undefined8 local_38;
  wchar_t *local_30;
  
  local_48 = 0x960094;
  local_res20 = 0;
  local_40 = L"\\REGISTRY\\MACHINE\\System\\CurrentControlSet\\Control\\AppID\\Configuration\\EDP";
  local_res18[0] = 0;
  local_30 = L"DataContext";
  local_res10[0] = 0;
  pwVar3 = (wchar_t *)0x0;
  local_38 = 0x180016;
  local_res8[0] = 0;
  iVar1 = AiRegReadStringValue(0,&local_48,&local_38,(short *)&DAT_140018530);
  if (-1 < iVar1) {
    pwVar3 = (wchar_t *)0x102;
    _DAT_140018540 = ExAllocatePool2(0x102,0xa0,0x44497041);
    if (_DAT_140018540 != 0) {
      DAT_140018548 = 0;
      for (_Src = DAT_140018538; *_Src != L'\0'; _Src = _Src + sVar2 + 1) {
        pwVar3 = _Src;
        sVar2 = wcsnlen(_Src,0x100);
        if (sVar2 == 0) {
          DAT_140018548 = 0;
          break;
        }
        pwVar3 = (wchar_t *)((ulonglong)DAT_140018548 * 0x10 + _DAT_140018540);
        RtlInitUnicodeString(pwVar3,_Src);
        DAT_140018548 = DAT_140018548 + 1;
      }
    }
  }
  iVar1 = AiRegReadDwordValue(pwVar3,&DAT_140008df0,&DAT_140008e00,local_res8);
  if ((-1 < iVar1) ||
     (iVar1 = AiRegReadDwordValue(pwVar3,&local_48,&DAT_140008e00,local_res8), -1 < iVar1)) {
    DAT_14001852c = local_res8[0];
  }
  iVar1 = AiRegReadDwordValue(pwVar3,&local_48,&DAT_140008de0,local_res8);
  if (-1 < iVar1) {
    DAT_140018529 = local_res8[0] != 0;
  }
  DAT_140018528 = 1;
  SrpLoadPlugin(pwVar3,(longlong *)&AiCategoryExe,&local_res20,local_res10,local_res18);
  DAT_140018550 = local_res10[0];
  lVar4 = local_res20;
  SrpFreePlugin(local_res20,local_res10[0]);
  local_res20 = 0;
  local_res10[0] = 0;
  SrpLoadPlugin(lVar4,(longlong *)&AiCategoryAppx,&local_res20,local_res10,local_res18);
  DAT_140018554 = local_res10[0];
  SrpFreePlugin(local_res20,local_res10[0]);
  return;
}



===== EdpIoctlCallback @ 140032ab0 =====

undefined4
EdpIoctlCallback(undefined8 param_1,int param_2,undefined8 *param_3,uint param_4,int *param_5,
                int param_6,undefined8 *param_7)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined4 local_res10 [6];
  
  if (param_2 != 0x22a080) {
    if (param_2 == 0x22a084) {
      uVar2 = EdppSetIntentToken(param_3,param_4);
      return (int)uVar2;
    }
    if (param_2 == 0x22a088) {
      uVar2 = EdppInheritCallersEnterpriseContext(param_3,param_4);
      return (int)uVar2;
    }
    if (param_2 == 0x22a08c) {
      local_res10[0] = 0;
      AiEnsureServiceRunning('\x01');
      ZwSetEvent(DAT_1400184f8,local_res10);
      return 0;
    }
    if (param_2 != 0x22a090) {
      if (param_2 == 0x22a094) {
        uVar1 = EdppIsActive(param_5,param_6,param_7);
        return (int)uVar1;
      }
      return 0xc000000d;
    }
  }
  uVar2 = EdppEvaluateToken(param_3,param_4,(ulonglong)param_3);
  return (int)uVar2;
}



===== EdpPluginCleanup @ 140032b50 =====

undefined8 EdpPluginCleanup(longlong *param_1)

{
  int iVar1;
  char *pcVar2;
  undefined8 local_18;
  wchar_t *local_10;
  
  local_18 = 0x260024;
  local_10 = L"\\??\\AppidEDPPlugin";
  if (*param_1 != 0) {
    pcVar2 = (char *)(*param_1 + 0x40);
    if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
      IoDeleteSymbolicLink(&local_18);
    }
    IoDeleteDevice(*param_1);
  }
  if (DAT_1400184f0 != 0) {
    ZwAlertThread();
    ZwWaitForSingleObject(DAT_1400184f0,0,0);
    ZwClose(DAT_1400184f0);
  }
  if (DAT_1400184f8 != 0) {
    ZwClose();
  }
  EdppShuttingDown = 1;
  if (EdppPurgeWnfEvtHandle != 0) {
    ExUnsubscribeWnfStateChange();
  }
  ExAcquirePushLockExclusiveEx(&EdppAuditSessionLock,0);
  if (EdppAuditEnabled != '\0') {
    iVar1 = EdppDoWorkAsSystem(EdppDisableAudit);
    if (-1 < iVar1) {
      EdppAuditEnabled = '\0';
    }
  }
  ExReleasePushLockEx(&EdppAuditSessionLock,0);
  EdpFreePluginConfig(&DAT_140018528);
  return 0;
}



===== EdppCaptureProcess @ 140032c80 =====

int EdppCaptureProcess(undefined8 param_1,void *param_2)

{
  int iVar1;
  undefined8 local_res10;
  undefined8 in_stack_ffffffffffffffa8;
  undefined4 uVar2;
  undefined8 in_stack_ffffffffffffffb0;
  undefined4 uVar3;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong uStack_10;
  
  uVar2 = (undefined4)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20);
  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffffb0 >> 0x20);
  local_18 = 0;
  uStack_10 = uStack_10 & 0xffffffff00000000;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 0;
  uStack_40 = 0;
  iVar1 = SeLocateProcessImageName(0,(longlong)param_2 + 0x18);
  if (-1 < iVar1) {
    local_28 = *(undefined8 *)((longlong)param_2 + 0x18);
    uStack_30 = 0;
    local_38 = CONCAT44(local_38._4_4_,0x30);
    local_18 = 0;
    uStack_10 = 0;
    uStack_20 = CONCAT44(uStack_20._4_4_,0x240);
    iVar1 = ZwOpenFile((longlong)param_2 + 0x20,0x80100000,&local_38,&local_48,CONCAT44(uVar2,5),
                       CONCAT44(uVar3,0x60));
    if (-1 < iVar1) {
      local_res10 = 0;
      iVar1 = ObReferenceObjectByHandle
                        (*(undefined8 *)((longlong)param_2 + 0x20),0,
                         *(undefined8 *)IoFileObjectType_exref,0,&local_res10,0);
      *(undefined8 *)((longlong)param_2 + 0x40) = local_res10;
      if (-1 < iVar1) {
        return iVar1;
      }
    }
  }
  EdppCleanupArgs(param_2);
  return iVar1;
}



===== EdppCleanupArgs @ 140032d8c =====

void EdppCleanupArgs(void *param_1)

{
  if (*(longlong *)((longlong)param_1 + 0x18) != 0) {
    ExFreePoolWithTag();
  }
  if (*(longlong *)((longlong)param_1 + 0x20) != 0) {
    ZwClose();
  }
  if (*(longlong *)((longlong)param_1 + 0x40) != 0) {
    ObfDereferenceObject();
  }
  if (*(longlong *)((longlong)param_1 + 0x10) != 0) {
    if (*(longlong *)(*(longlong *)((longlong)param_1 + 0x10) + 8) != 0) {
      ExFreePoolWithTag();
    }
    if (*(longlong *)((longlong)param_1 + 0x10) != 0) {
      ExFreePoolWithTag();
    }
  }
  memset(param_1,0,0x60);
  return;
}



===== EdppEvaluateToken @ 140032e28 =====

ulonglong EdppEvaluateToken(undefined8 *param_1,uint param_2,ulonglong param_3)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong *plVar6;
  ulonglong local_res18;
  int local_res20 [2];
  undefined4 local_38 [2];
  longlong local_30;
  longlong local_28;
  ushort local_20 [12];
  
  lVar5 = 0;
  local_res18 = param_3 & 0xffffffffffffff00;
  local_res20[0] = 0;
  local_30 = 0;
  local_38[0] = 0;
  local_28 = 0;
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  local_20[4] = 0;
  local_20[5] = 0;
  local_20[6] = 0;
  local_20[7] = 0;
  uVar2 = EdppParseEvaluateData(param_1,param_2,0x8c,local_20,&local_30);
  uVar4 = uVar2 & 0xffffffff;
  if (-1 < (int)uVar2) {
    uVar1 = ZwQueryInformationToken(local_30,9,local_res20,4,local_38);
    uVar4 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      if (local_res20[0] == 2) {
        uVar1 = EdppIsCurrentContextAllowed((longlong)local_20,&local_res18);
        uVar4 = (ulonglong)uVar1;
        if ((int)uVar1 < 0) goto LAB_140032f07;
        if ((char)local_res18 != '\0') {
          plVar6 = &local_28;
          uVar3 = 1;
          uVar2 = SrpCreateEnterpriseContext(0,1,local_20,plVar6);
          lVar5 = local_28;
          uVar4 = uVar2 & 0xffffffff;
          if (-1 < (int)uVar2) {
            uVar1 = SrpSetEnterpriseContextToken(local_30,uVar3,'\0',plVar6,local_28,0);
            uVar4 = (ulonglong)uVar1;
          }
          goto LAB_140032f07;
        }
      }
      uVar4 = 0xc0000022;
    }
  }
LAB_140032f07:
  SrpDeleteEnterpriseContext(lVar5);
  if (local_30 != 0) {
    ZwClose();
  }
  return uVar4;
}



===== EdppImpersonateProcess @ 140032f40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EdppImpersonateProcess(longlong param_1)

{
  int iVar1;
  undefined1 auStack_88 [32];
  undefined4 local_68;
  undefined8 *local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_88;
  local_28 = &local_20;
  local_60 = &local_58;
  local_18 = 1;
  local_50 = 0x30;
  local_38 = 0x200;
  local_1c = 2;
  local_68 = 2;
  local_58 = 0;
  local_48 = 0;
  local_40 = 0;
  local_30 = 0;
  local_20 = 0xc;
  iVar1 = ZwDuplicateToken(*(undefined8 *)(param_1 + 0x30),0x8c,&local_50,0);
  if (-1 < iVar1) {
    ZwSetInformationThread(0xfffffffffffffffe,5,&local_58,8);
  }
  return;
}



===== EdppInheritCallersEnterpriseContext @ 140033008 =====

ulonglong EdppInheritCallersEnterpriseContext(undefined8 *param_1,uint param_2)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong *plVar7;
  ulonglong uVar8;
  longlong lVar9;
  longlong lVar10;
  undefined8 uVar11;
  char local_res10 [8];
  char local_res18;
  int local_res20 [2];
  ulonglong in_stack_ffffffffffffff50;
  longlong local_98;
  longlong local_90;
  undefined4 local_88 [2];
  longlong local_80;
  longlong local_78;
  longlong local_70;
  longlong local_68 [6];
  
  local_res10[0] = '\0';
  local_res18 = '\0';
  lVar9 = 0;
  local_78 = 0;
  bVar1 = false;
  local_res20[0] = 0;
  lVar10 = 0;
  local_98 = 0;
  local_90 = 0;
  local_88[0] = 0;
  local_70 = 0;
  local_80 = 0;
  local_68[1] = 0;
  local_68[0] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  local_68[4] = 0;
  local_68[5] = 0;
  if ((param_2 < 0x18) || (1 < (ulonglong)param_1[2])) {
    uVar8 = 0xc000000d;
  }
  else {
    uVar4 = EdppOpenKernelTokenHandle(*param_1,8,&local_98);
    uVar8 = uVar4 & 0xffffffff;
    if (-1 < (int)uVar4) {
      uVar4 = EdppOpenKernelTokenHandle(param_1[1],0x8c,&local_90);
      uVar8 = uVar4 & 0xffffffff;
      if ((int)uVar4 < 0) {
        ZwClose(local_98);
        local_98 = 0;
      }
      else {
        uVar4 = param_1[2];
        uVar3 = ZwQueryInformationToken(local_90,9,local_res20,4,local_88);
        uVar8 = (ulonglong)uVar3;
        if (-1 < (int)uVar3) {
          bVar1 = false;
          if (local_res20[0] == 2) {
            local_68[2] = 0;
            local_68[3] = 0;
            local_68[4] = 0;
            local_68[5] = 0;
            SeCaptureSubjectContext(local_68 + 2);
            bVar1 = true;
            uVar5 = SrpIsEnterpriseExempt(local_68 + 2,local_res10);
            uVar8 = uVar5 & 0xffffffff;
            if ((int)uVar5 < 0) goto LAB_140033298;
            cVar2 = RtlIsSandboxedToken(local_68 + 2,1);
            if ((local_res10[0] != '\0') || (cVar2 == '\0')) {
              lVar6 = local_68[4];
              if (local_68[2] != 0) {
                lVar6 = local_68[2];
              }
              if (lVar6 != 0) {
                uVar11 = 8;
                uVar3 = ObOpenObjectByPointer
                                  (lVar6,0x200,0,8,0,in_stack_ffffffffffffff50 & 0xffffffffffffff00,
                                   &local_70);
                uVar8 = (ulonglong)uVar3;
                if ((int)uVar3 < 0) goto LAB_140033298;
                uVar3 = ZwCompareTokens(local_90,local_70);
                uVar8 = (ulonglong)uVar3;
                if ((int)uVar3 < 0) goto LAB_140033298;
                if (local_res18 != '\0') {
                  uVar3 = SrpGetEnterpriseContextToken(local_98,&local_78);
                  if (-1 < (int)uVar3) {
                    plVar7 = local_68;
                    uVar3 = SrpGetEvaluationFlagsToken(local_98,plVar7);
                    lVar9 = local_78;
                    if (-1 < (int)uVar3) {
                      if (((uVar4 & 1) != 0) && ((*(ulonglong *)(local_78 + 8) & 2) != 0)) {
                        *(ulonglong *)(local_78 + 8) = *(ulonglong *)(local_78 + 8) | 8;
                      }
                      uVar3 = SrpSetEnterpriseContextToken
                                        (local_90,plVar7,'\0',uVar11,local_78,local_68[0]);
                      uVar8 = (ulonglong)uVar3;
                      if (-1 < (int)uVar3) {
                        uVar4 = SrpGetAppUniqueIdFromToken(local_98,&local_80);
                        uVar8 = uVar4 & 0xffffffff;
                        if (-1 < (int)uVar4) {
                          uVar3 = SrpGetProcessUniqueIdFromToken(local_98,local_68 + 1);
                          lVar10 = local_80;
                          uVar8 = (ulonglong)uVar3;
                          if (-1 < (int)uVar3) {
                            if (local_80 != 0) {
                              uVar3 = SrpSetInheritedAppUniqueIdOnToken(local_90,local_80);
                              uVar8 = (ulonglong)uVar3;
                              if ((int)uVar3 < 0) goto LAB_140033298;
                            }
                            uVar3 = SrpSetInheritedProcessUniqueIdOnToken
                                              (local_90,(char)local_68[1]);
                            uVar8 = (ulonglong)uVar3;
                            goto LAB_140033298;
                          }
                        }
                        lVar10 = local_80;
                      }
                      goto LAB_140033298;
                    }
                  }
                  uVar8 = (ulonglong)uVar3;
                  lVar9 = local_78;
                  goto LAB_140033298;
                }
              }
            }
          }
          uVar8 = 0xc0000022;
        }
      }
    }
  }
LAB_140033298:
  SrpDeleteEnterpriseContext(lVar9);
  if (local_70 != 0) {
    ZwClose();
  }
  if (bVar1) {
    SeReleaseSubjectContext(local_68 + 2);
  }
  if (local_98 != 0) {
    ZwClose();
  }
  if (local_90 != 0) {
    ZwClose();
  }
  if (lVar10 != 0) {
    SrpDeleteEnterpriseContext(lVar10);
  }
  return uVar8;
}



===== EdppIsCurrentContextAllowed @ 14003331c =====

undefined4 EdppIsCurrentContextAllowed(longlong param_1,undefined8 param_2)

{
  undefined4 uVar1;
  longlong local_28 [4];
  
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  SeCaptureSubjectContext(local_28);
  uVar1 = SrpIsEnterpriseAllowed(local_28,param_1,param_2);
  SeReleaseSubjectContext(local_28);
  return uVar1;
}



===== EdppOpenKernelTokenHandle @ 140033380 =====

ulonglong EdppOpenKernelTokenHandle(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 local_res20;
  ulonglong uVar5;
  
  uVar5 = 0;
  local_res20 = 0;
  uVar1 = *(undefined8 *)SeTokenObjectType_exref;
  uVar4 = ObReferenceObjectByHandle(param_1,param_2,uVar1,1,&local_res20,0);
  uVar2 = local_res20;
  if (-1 < (int)uVar4) {
    uVar3 = ObOpenObjectByPointer
                      (local_res20,0x200,0,0x80000000,uVar1,uVar5 & 0xffffffffffffff00,param_3);
    uVar4 = (ulonglong)uVar3;
    ObfDereferenceObject(uVar2);
  }
  return uVar4;
}



===== EdppParseEvaluateData @ 140033420 =====

ulonglong EdppParseEvaluateData
                    (undefined8 *param_1,uint param_2,ulonglong param_3,undefined8 param_4,
                    undefined8 param_5)

{
  wchar_t *_Src;
  ulonglong uVar1;
  ulonglong _MaxCount;
  
  if (0xf < param_2) {
    uVar1 = 0;
    _MaxCount = (ulonglong)(param_2 - 8 >> 1);
    _Src = (wchar_t *)(param_1 + 1);
    if (_Src != (wchar_t *)0x0) {
      uVar1 = wcsnlen(_Src,_MaxCount);
    }
    if (uVar1 < _MaxCount) {
      RtlInitUnicodeString(param_4,_Src);
      uVar1 = EdppOpenKernelTokenHandle(*param_1,param_3 & 0xffffffff,param_5);
      return uVar1;
    }
  }
  return 0xc000000d;
}



===== EdppPolicyUpdate @ 1400334bc =====

int EdppPolicyUpdate(char param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined4 local_res10 [2];
  undefined8 local_res18;
  longlong local_res20;
  int local_88 [2];
  longlong lStack_80;
  undefined8 local_78;
  longlong alStack_70 [6];
  undefined4 local_40;
  
  local_res20 = 0;
  local_res10[0] = 0;
  alStack_70[5] = 0;
  local_40 = 0;
  local_res18 = 0;
  uVar5 = 0;
  lVar4 = 0;
  alStack_70[1] = 0;
  alStack_70[2] = 0;
  piVar3 = (int *)0x0;
  bVar1 = false;
  alStack_70[3] = 0;
  alStack_70[4] = 0;
  local_88[0] = 0;
  local_88[1] = 0;
  lStack_80 = 0;
  local_78 = 0;
  alStack_70[0] = 0;
  iVar2 = RtlRunOnceExecuteOnce(&DAT_1400184d8,EdppInitializeCallback,0,0);
  if (-1 < iVar2) {
    if (param_1 == '\0') {
      param_1 = EdppPolicyUpdateRequired();
    }
    piVar3 = SrpGetPolicy();
    if ((piVar3 != (int *)0x0) && (param_1 != '\0')) {
      SrpGetPluginPolicy((longlong)piVar3,(longlong *)&AiCategoryExe,uVar5,&lStack_80,local_88);
      SrpGetPluginPolicy((longlong)piVar3,(longlong *)&AiCategoryAppx,uVar5,alStack_70,
                         (undefined4 *)&local_78);
      if (((DAT_140018528 == '\0') || ((DAT_14001852c == 0 || (DAT_140018548 == 0)))) ||
         (((int)local_78 == 0 && (local_88[0] == 0)))) {
        LOCK();
        DAT_14001854c = 0;
        UNLOCK();
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      while( true ) {
        iVar2 = ZwGetNextProcess(lVar4,0x10000000,0x200,0,&local_res20);
        if (lVar4 != 0) {
          ZwClose(lVar4);
        }
        if (iVar2 < 0) break;
        iVar2 = ZwQueryInformationProcess(local_res20,0,alStack_70 + 1,0x30,local_res10);
        if (-1 < iVar2) {
          iVar2 = PsLookupProcessByProcessId(alStack_70[5],&local_res18);
          if (-1 < iVar2) {
            EdppProcessEnumRoutine(local_res18,alStack_70[5],(longlong)piVar3,local_88);
            ObfDereferenceObject(local_res18);
            local_res18 = 0;
          }
        }
        lVar4 = local_res20;
        local_res20 = 0;
      }
    }
  }
  if (lStack_80 != 0) {
    ExFreePoolWithTag(lStack_80,0);
  }
  if (alStack_70[0] != 0) {
    ExFreePoolWithTag(alStack_70[0],0);
  }
  if (piVar3 != (int *)0x0) {
    ReleasePolicyRef(piVar3 + -2);
  }
  if (bVar1) {
    LOCK();
    DAT_14001854c = 1;
    UNLOCK();
  }
  ZwUpdateWnfStateData(&WNF_ENTR_EVALUATE_EDP_CONFIGURATION_STATE,0,0,0,0,0,0);
  ZwUpdateWnfStateData(&WNF_EDP_ENTERPRISE_CONTEXTS_UPDATED,0,0,0,0,0,0);
  NikEdpNotifyProcessTokenChange0(0,1);
  return iVar2;
}



===== EdppPolicyUpdateRequired @ 140033750 =====

undefined1 EdppPolicyUpdateRequired(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined1 uVar5;
  
  ExAcquirePushLockExclusiveEx(&EdppRuntimeConfig,0);
  iVar3 = DAT_14001852c;
  uVar5 = 1;
  if ((((DAT_140018528 == '\0') || (DAT_14001852c == 0)) || (DAT_140018548 == 0)) ||
     ((DAT_140018554 == 0 && (DAT_140018550 == 0)))) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  EdpFreePluginConfig(&DAT_140018528);
  EdpInitPluginRuntimeConfig();
  iVar4 = DAT_14001852c;
  if (((DAT_140018528 == '\0') || (DAT_14001852c == 0)) ||
     ((DAT_140018548 == 0 || ((DAT_140018554 == 0 && (DAT_140018550 == 0)))))) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  ExReleasePushLockExclusiveEx(&EdppRuntimeConfig,0);
  if (((!bVar1) || (iVar4 == 0)) && ((!bVar2 || (iVar3 == 0)))) {
    uVar5 = 0;
  }
  return uVar5;
}



===== EdppPolicyUpdateSystemThread @ 140033860 =====

void EdppPolicyUpdateSystemThread(void)

{
  int iVar1;
  char cVar2;
  
  cVar2 = '\x01';
  while( true ) {
    EdppPolicyUpdate(cVar2);
    iVar1 = ZwWaitForSingleObject(DAT_1400184f8,1,0);
    if (iVar1 == 0x101) break;
    cVar2 = '\0';
  }
  return;
}



===== EdppProcessEnumRoutine @ 14003389c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int EdppProcessEnumRoutine(undefined8 param_1,ulonglong param_2,longlong param_3,int *param_4)

{
  bool bVar1;
  byte bVar2;
  undefined1 *puVar3;
  ulonglong uVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  uint *puVar8;
  ulonglong uVar9;
  undefined1 *puVar10;
  undefined1 auStackY_148 [32];
  char in_stack_fffffffffffffee0;
  byte local_108;
  char local_107;
  char local_106 [6];
  undefined1 *local_100;
  uint local_f8 [2];
  ulonglong local_f0;
  longlong local_e8;
  ulonglong local_e0;
  int *local_d8;
  ushort *local_d0;
  undefined1 *local_c8;
  undefined8 local_c0;
  ushort *local_b8;
  longlong local_a8;
  ulonglong local_a0;
  undefined1 *local_98;
  undefined8 *local_90;
  undefined8 *local_80;
  int local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_148;
  puVar6 = (undefined8 *)0x0;
  local_f8[1] = 0;
  local_108 = 0;
  local_106[0] = '\0';
  local_107 = '\0';
  bVar1 = false;
  local_100 = (undefined1 *)0x0;
  local_e0 = 0;
  local_e8 = param_3;
  local_d8 = param_4;
  memset(&local_c8,0,0x60);
  local_f8[0] = 0;
  local_f0 = 0;
  puVar10 = (undefined1 *)0x0;
  local_d0 = (ushort *)0x0;
  local_68 = 0;
  uStack_60 = 0;
  if (param_2 < 5) {
    return 0;
  }
  iVar5 = AiGetTokens(param_2,(ulonglong *)&local_100,&local_e0);
  uVar4 = local_e0;
  puVar3 = local_100;
  if (-1 < iVar5) {
    local_b8 = (ushort *)ExAllocatePool2(0x102,0x10,0x44497041);
    if (local_b8 == (ushort *)0x0) {
      iVar5 = -0x3fffffe9;
    }
    else {
      local_b8[0] = 0;
      local_b8[1] = 0;
      local_b8[2] = 0;
      local_b8[3] = 0;
      local_b8[4] = 0;
      local_b8[5] = 0;
      local_b8[6] = 0;
      local_b8[7] = 0;
      iVar5 = AiCapturePackageMoniker(param_1,&local_108,(longlong)local_106,(short *)local_b8);
      if (-1 < iVar5) {
        ExAcquirePushLockSharedEx(&EdppRuntimeConfig,0);
        bVar2 = local_108;
        local_100 = &DAT_140018528;
        if ((((DAT_140018528 == '\0') || (DAT_14001852c == 0)) || (DAT_140018548 == 0)) ||
           ((uVar9 = (ulonglong)local_108, local_d8[4] == 0 &&
            ((local_108 != 0 || (*local_d8 == 0)))))) {
          puVar10 = &DAT_140018528;
          iVar5 = EdppClearToken(puVar3,param_1);
        }
        else {
          iVar5 = AiIsTokenSandBoxed((char)puVar3,&local_107);
          if ((-1 < iVar5) && (local_107 == '\0')) {
            puVar6 = (undefined8 *)ExAllocatePool2(0x102,0x18,0x44497041);
            if (puVar6 == (undefined8 *)0x0) {
              iVar5 = -0x3fffffe9;
            }
            else {
              *(undefined8 *)((longlong)puVar6 + 0xc) = 0;
              *(undefined4 *)((longlong)puVar6 + 0x14) = 0;
              *puVar6 = param_1;
              *(undefined4 *)(puVar6 + 1) = 0xc0000001;
              local_98 = puVar3;
              local_a0 = uVar4;
              local_c0 = param_1;
              local_90 = puVar6;
              iVar5 = EdppImpersonateProcess((longlong)&local_c8);
              if (-1 < iVar5) {
                bVar1 = true;
                iVar5 = EdppCaptureProcess(param_1,&local_c8);
                if (-1 < iVar5) {
                  puVar7 = (undefined8 *)&AiCategoryAppx;
                  if (bVar2 == 0) {
                    puVar7 = (undefined8 *)&AiCategoryExe;
                  }
                  local_68 = *puVar7;
                  uStack_60 = puVar7[1];
                  if (bVar2 == 0) {
                    iVar5 = AiSetAttributesExe(local_e8,local_a8,(longlong)puVar3,uVar4,'\0');
                  }
                  else {
                    in_stack_fffffffffffffee0 = '\0';
                    iVar5 = AiSetAttributesAppx(local_a8,local_b8,local_106[0],(longlong)puVar3,
                                                uVar4,(ulonglong *)0x0);
                  }
                  puVar10 = local_100;
                  if (-1 < iVar5) {
                    local_80 = &local_68;
                    puVar8 = local_f8 + 1;
                    local_78 = local_d8[uVar9 * 4];
                    local_70 = *(undefined8 *)(local_d8 + uVar9 * 4 + 2);
                    local_c8 = local_100;
                    iVar5 = EdpPluginEvaluate((uint *)&local_c8,puVar8,&local_f0,&local_d0,local_f8)
                    ;
                    if (-1 < iVar5) {
                      uVar9 = local_f0;
                      if (DAT_14001852c == 1) {
                        uVar9 = local_f0 | 0x80;
                      }
                      uVar9 = EdpPluginAction((longlong)&local_c8,puVar8,uVar9,local_d0,local_f8[0],
                                              in_stack_fffffffffffffee0,1);
                      iVar5 = (int)uVar9;
                    }
                    local_c8 = (undefined1 *)0x0;
                    goto LAB_140033a58;
                  }
                }
              }
            }
          }
          puVar10 = local_100;
        }
      }
    }
  }
LAB_140033a58:
  AiCleanTokens((longlong)puVar3,uVar4);
  EdppCleanupArgs(&local_c8);
  if (puVar6 != (undefined8 *)0x0) {
    ExFreePoolWithTag(puVar6,0);
  }
  if (puVar10 != (undefined1 *)0x0) {
    ExReleasePushLockSharedEx(&EdppRuntimeConfig,0);
  }
  if (bVar1) {
    local_e8 = 0;
    ZwSetInformationThread(0xfffffffffffffffe,5,&local_e8);
  }
  return iVar5;
}



===== EdppSetIntentToken @ 140033c50 =====

ulonglong EdppSetIntentToken(undefined8 *param_1,uint param_2)

{
  char cVar1;
  uint uVar2;
  ulonglong uVar3;
  char *pcVar4;
  ulonglong uVar5;
  char local_res18 [8];
  longlong local_res20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res20 = 0;
  local_res18[0] = '\0';
  local_18 = 0;
  uStack_10 = 0;
  uVar3 = EdppParseEvaluateData(param_1,param_2,0x88,&local_18,&local_res20);
  uVar5 = uVar3 & 0xffffffff;
  if ((int)uVar3 < 0) goto LAB_140033cd8;
  pcVar4 = "H";
  cVar1 = RtlEqualUnicodeString(&local_18,&EdppPersonalName,0);
  if (cVar1 == '\0') {
    pcVar4 = local_res18;
    uVar2 = EdppIsCurrentContextAllowed((longlong)&local_18,pcVar4);
    uVar5 = (ulonglong)uVar2;
    if ((int)uVar2 < 0) goto LAB_140033cd8;
    if (local_res18[0] == '\0') {
      uVar5 = 0xc0000022;
      goto LAB_140033cd8;
    }
  }
  uVar2 = SrpSetIntentEnterpriseIdToken(local_res20,pcVar4,(undefined2 *)&local_18);
  uVar5 = (ulonglong)uVar2;
LAB_140033cd8:
  if (local_res20 != 0) {
    ZwClose();
  }
  return uVar5;
}



===== EdpFreePluginConfig @ 140033d04 =====

void EdpFreePluginConfig(char *param_1)

{
  if (*param_1 != '\0') {
    if (*(longlong *)(param_1 + 0x10) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x10),0);
    }
    if (*(longlong *)(param_1 + 0x18) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x18),0);
    }
    param_1[0] = '\0';
    param_1[1] = '\0';
    param_1[2] = '\0';
    param_1[3] = '\0';
    param_1[4] = '\0';
    param_1[5] = '\0';
    param_1[6] = '\0';
    param_1[7] = '\0';
    param_1[8] = '\0';
    param_1[9] = '\0';
    param_1[10] = '\0';
    param_1[0xb] = '\0';
    param_1[0xc] = '\0';
    param_1[0xd] = '\0';
    param_1[0xe] = '\0';
    param_1[0xf] = '\0';
    param_1[0x10] = '\0';
    param_1[0x11] = '\0';
    param_1[0x12] = '\0';
    param_1[0x13] = '\0';
    param_1[0x14] = '\0';
    param_1[0x15] = '\0';
    param_1[0x16] = '\0';
    param_1[0x17] = '\0';
    param_1[0x18] = '\0';
    param_1[0x19] = '\0';
    param_1[0x1a] = '\0';
    param_1[0x1b] = '\0';
    param_1[0x1c] = '\0';
    param_1[0x1d] = '\0';
    param_1[0x1e] = '\0';
    param_1[0x1f] = '\0';
    param_1[0x20] = '\0';
    param_1[0x21] = '\0';
    param_1[0x22] = '\0';
    param_1[0x23] = '\0';
    param_1[0x24] = '\0';
    param_1[0x25] = '\0';
    param_1[0x26] = '\0';
    param_1[0x27] = '\0';
  }
  return;
}



===== EdppEvaluatePolicies @ 140033d60 =====

ulonglong EdppEvaluatePolicies
                    (longlong *param_1,undefined8 param_2,uint *param_3,undefined8 *param_4,
                    undefined4 *param_5)

{
  ulonglong uVar1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
  longlong lVar5;
  ulonglong uVar6;
  
  *param_3 = 0xc0000001;
  uVar6 = 0;
  uVar4 = 0;
  param_3[1] = 0;
  uVar3 = param_2;
  if ((int)param_1[10] != 0) {
    do {
      lVar5 = (ulonglong)uVar4 * 0x20 + param_1[0xb];
      uVar2 = *(uint *)(*(longlong *)(lVar5 + 0x18) + 0x18) >> 4 & 1;
      if ((uint)param_2 == uVar2) {
        uVar1 = AiEvaluateAppLockerPolicyClass((ulonglong)uVar2,uVar3,lVar5,param_1[5],param_3);
        uVar6 = uVar1 & 0xffffffff;
        if ((int)uVar1 < 0) {
          return uVar6;
        }
        if (*param_3 != 0) break;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(param_1 + 10));
  }
  if ((param_4 != (undefined8 *)0x0) && (param_5 != (undefined4 *)0x0)) {
    if (*param_3 == 0) {
      lVar5 = *param_1;
      *param_4 = *(undefined8 *)(lVar5 + 0x18);
      *param_5 = *(undefined4 *)(lVar5 + 0x20);
    }
    else {
      *param_4 = 0;
      *param_5 = 0;
    }
  }
  return uVar6;
}



===== EdppIsDisallowedExempt @ 140033e2c =====

undefined8 EdppIsDisallowedExempt(longlong param_1)

{
  int iVar1;
  undefined4 extraout_var;
  undefined8 *puVar2;
  wchar_t *pwVar3;
  int local_res8 [2];
  undefined8 local_28;
  wchar_t *local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_28 = 0x960094;
  local_20 = L"\\REGISTRY\\MACHINE\\System\\CurrentControlSet\\Control\\AppID\\Configuration\\EDP";
  local_18 = 0;
  uStack_10 = 0;
  local_res8[0] = 0;
  if ((**(longlong **)(param_1 + 0x48) != DAT_1400181c8) ||
     (pwVar3 = L"AppxDisallowedIsExempted", (*(longlong **)(param_1 + 0x48))[1] != DAT_1400181d0)) {
    pwVar3 = L"ExeDisallowedIsExempted";
  }
  puVar2 = &local_18;
  RtlInitUnicodeString(puVar2,pwVar3);
  iVar1 = AiRegReadDwordValue(puVar2,&local_28,&local_18,local_res8);
  return CONCAT71((int7)(CONCAT44(extraout_var,iVar1) >> 8),-1 < iVar1 && local_res8[0] == 1);
}



===== EdppIsEnterpriseSMBFile @ 140033ec4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int EdppIsEnterpriseSMBFile(longlong *param_1,undefined1 *param_2)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined1 auStack_328 [32];
  undefined8 *local_308;
  undefined4 local_300;
  undefined8 local_2f8;
  undefined4 local_2f0;
  undefined1 *local_2e8;
  undefined4 local_2e0;
  undefined8 local_2d8;
  undefined1 *local_2d0;
  undefined8 local_2c8;
  ulonglong uStack_2c0;
  undefined1 local_2b8 [4];
  int local_2b4;
  undefined1 local_238 [528];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_328;
  iVar2 = 0;
  local_2c8 = 0;
  uStack_2c0 = 0;
  memset(local_2b8,0,0x74);
  local_2d8 = 0;
  *param_2 = 0;
  if ((*(longlong *)param_1[9] == 0x47d4e3e02b64fd0f) &&
     (((longlong *)param_1[9])[1] == 0x49d7ba725903e8a1)) {
    local_308 = (undefined8 *)CONCAT44(local_308._4_4_,0x37);
    iVar2 = ZwQueryInformationFile(param_1[4],&local_2c8,local_2b8,0x74);
    if ((-1 < iVar2) && (local_2b4 == 0x20000)) {
      local_2e8 = local_238;
      local_2e0 = 0x104;
      local_2f0 = 0;
      local_308 = &local_2c8;
      local_2f8 = 0;
      local_300 = 0x140208;
      local_2c8 = 0;
      uStack_2c0 = 0;
      iVar2 = ZwFsControlFile(param_1[4],0,0,0);
      if (-1 < iVar2) {
        local_2d0 = local_238;
        if (uStack_2c0 < 0x10000) {
          iVar2 = 0;
          local_2d8._0_4_ = CONCAT22((short)uStack_2c0,(short)uStack_2c0);
          uVar5 = 0;
          lVar3 = *param_1;
          if (*(int *)(lVar3 + 0x20) != 0) {
            do {
              cVar1 = RtlEqualUnicodeString(&local_2d8,uVar5 * 0x10 + *(longlong *)(lVar3 + 0x18),0)
              ;
              if (cVar1 != '\0') {
                *param_2 = 1;
                return 0;
              }
              lVar3 = *param_1;
              uVar4 = (int)uVar5 + 1;
              uVar5 = (ulonglong)uVar4;
            } while (uVar4 < *(uint *)(lVar3 + 0x20));
          }
        }
        else {
          iVar2 = -0x3fffff6b;
        }
      }
    }
  }
  return iVar2;
}



===== EdppPolicyExempt @ 14003406c =====

ulonglong EdppPolicyExempt(longlong *param_1,char *param_2,undefined1 *param_3,undefined8 *param_4,
                          undefined4 *param_5)

{
  longlong *plVar1;
  longlong lVar2;
  bool bVar3;
  int iVar4;
  ulonglong uVar5;
  undefined4 extraout_var;
  char *pcVar6;
  undefined4 *puVar7;
  undefined *puVar8;
  undefined1 local_res8 [8];
  byte local_38;
  char local_37;
  char local_36 [2];
  undefined4 local_34;
  uint local_30 [2];
  
  local_30[0] = 0;
  local_30[1] = 0;
  local_res8[0] = 0;
  local_34 = 0;
  local_37 = '\0';
  local_38 = 0;
  local_36[0] = '\0';
  iVar4 = PsIsProtectedProcess(param_1[1]);
  if (iVar4 != 0) {
    uVar5 = 0;
    goto LAB_140034294;
  }
  if ((*(longlong *)param_1[9] == 0x4896ef1a58125a50) &&
     (((longlong *)param_1[9])[1] == 0x6ccab39ac6d657ba)) {
    *param_2 = '\0';
    puVar8 = &DAT_140012ae0;
    uVar5 = EdppIsAppxBroker((longlong)param_1,&local_38);
    if ((int)uVar5 < 0) {
      return uVar5;
    }
    if (local_38 != 0) goto LAB_140034294;
    iVar4 = AiIsAppxInbox((undefined8 *)param_1[7],&local_37);
    if (iVar4 < 0) {
      return CONCAT44(extraout_var,iVar4);
    }
    *param_2 = local_37;
    bVar3 = true;
LAB_140034217:
    if (*param_2 != '\0') goto LAB_14003421c;
    if (bVar3) {
      if (param_1[5] == 0) {
        return 0xc00000f2;
      }
      SrppPluginAccessCheck(param_1[5],0x14000d0c0,local_30);
      if (-1 < (int)local_30[0]) {
        *param_2 = '\x01';
      }
    }
  }
  else {
    plVar1 = param_1 + 4;
    lVar2 = *plVar1;
    *param_2 = '\0';
    puVar8 = &DAT_14000f310;
    iVar4 = ZwGetCachedSigningLevel(lVar2,&local_34,local_res8,0,0,0);
    if ((-1 < iVar4) && (iVar4 = SeCompareSigningLevels(local_res8[0],0xc), iVar4 != 0)) {
      *param_2 = '\x01';
LAB_140034214:
      bVar3 = false;
      goto LAB_140034217;
    }
    pcVar6 = local_36;
    AiSigningLevelCacheExists(param_1[8],pcVar6);
    bVar3 = false;
    if (local_36[0] != '\0') goto LAB_140034217;
    puVar7 = (undefined4 *)CONCAT71((int7)((ulonglong)pcVar6 >> 8),0xc);
    iVar4 = ZwSetCachedSigningLevel(5,puVar7,plVar1,1,*plVar1);
    if (-1 < iVar4) {
      puVar7 = &local_34;
      iVar4 = ZwGetCachedSigningLevel(*plVar1,puVar7,local_res8,0,0,0);
      if (-1 < iVar4) {
        puVar7 = (undefined4 *)CONCAT71((int7)((ulonglong)puVar7 >> 8),0xc);
        iVar4 = SeCompareSigningLevels(local_res8[0]);
        if (iVar4 == 1) {
          *param_2 = '\x01';
        }
      }
    }
    if (*param_2 == '\0') {
      AiSetSigningLevelCache(param_1[8],puVar7);
      goto LAB_140034214;
    }
LAB_14003421c:
    if (param_1[5] == 0) {
      return 0xc00000f2;
    }
    SrppPluginAccessCheck(param_1[5],(longlong)puVar8,local_30);
    if ((int)local_30[0] < 0) {
      *param_2 = '\0';
    }
  }
  uVar5 = EdppEvaluatePolicies(param_1,1,local_30,param_4,param_5);
  if ((int)uVar5 < 0) {
    return uVar5;
  }
  if ((int)local_30[0] < 0) {
    return uVar5;
  }
  *param_3 = 1;
LAB_140034294:
  *param_2 = '\x01';
  return uVar5;
}



===== EdppPolicyOverride @ 1400342bc =====

undefined1
EdppPolicyOverride(longlong *param_1,undefined4 *param_2,undefined8 *param_3,undefined8 *param_4,
                  undefined4 *param_5)

{
  wchar_t wVar1;
  int iVar2;
  size_t sVar3;
  wchar_t *_Str;
  wchar_t *pwVar4;
  undefined4 uVar5;
  wchar_t *pwVar6;
  undefined **ppuVar7;
  wchar_t *_Src;
  uint uVar8;
  longlong lVar9;
  undefined1 local_res8;
  undefined8 local_90;
  wchar_t *local_88;
  undefined8 local_80;
  wchar_t *pwStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  
  local_90 = 0x960094;
  local_res8 = 0;
  local_88 = L"\\REGISTRY\\MACHINE\\System\\CurrentControlSet\\Control\\AppID\\Configuration\\EDP";
  ppuVar7 = &PTR_u_ExeAllow_140008e10;
  local_70 = 0;
  uStack_68 = 0;
  _Str = (wchar_t *)0x0;
  local_80 = 0;
  if ((*(longlong *)param_1[9] == DAT_1400181d8) && (((longlong *)param_1[9])[1] == DAT_1400181e0))
  {
    lVar9 = param_1[2];
  }
  else {
    lVar9 = param_1[3];
  }
  uVar8 = 0;
  do {
    pwStack_78 = (wchar_t *)0x0;
    RtlInitUnicodeString(&local_70,*ppuVar7);
    iVar2 = AiRegReadStringValue(0,&local_90,&local_70,(short *)&local_80);
    pwVar6 = pwStack_78;
    if (-1 < iVar2) {
      wVar1 = *pwStack_78;
      _Src = pwStack_78;
      while (wVar1 != L'\0') {
        sVar3 = wcsnlen(_Src,0x100);
        if (sVar3 == 0) {
          local_res8 = 0;
          goto LAB_140034497;
        }
        local_60 = 0;
        uStack_58 = 0;
        RtlInitUnicodeString(&local_60);
        if (_Str == (wchar_t *)0x0) {
          _Str = (wchar_t *)AiAlloc((ulonglong)*(ushort *)(lVar9 + 2) + 2);
          memset(_Str,0,(ulonglong)*(ushort *)(lVar9 + 2) + 2);
          memmove(_Str,*(void **)(lVar9 + 8),(ulonglong)*(ushort *)(lVar9 + 2));
        }
        pwVar4 = wcsstr(_Str,_Src);
        if (pwVar4 != (wchar_t *)0x0) {
          *param_2 = *(undefined4 *)(ppuVar7 + 1);
          *param_3 = ppuVar7[2];
          if (*(char *)(ppuVar7 + 3) == '\0') {
            uVar5 = 0;
            *param_4 = 0;
          }
          else {
            *param_4 = *(undefined8 *)(*param_1 + 0x18);
            uVar5 = *(undefined4 *)(*param_1 + 0x20);
          }
          local_res8 = 1;
          *param_5 = uVar5;
          goto LAB_140034497;
        }
        _Src = _Src + sVar3 + 1;
        wVar1 = *_Src;
      }
      ExFreePoolWithTag(pwVar6,0);
    }
    pwVar6 = (wchar_t *)0x0;
    ppuVar7 = ppuVar7 + 4;
    pwStack_78 = (wchar_t *)0x0;
    uVar8 = uVar8 + 1;
    if (6 < uVar8) {
LAB_140034497:
      if (pwVar6 != (wchar_t *)0x0) {
        ExFreePoolWithTag(pwVar6,0);
      }
      if (_Str != (wchar_t *)0x0) {
        ExFreePoolWithTag(_Str,0);
      }
      return local_res8;
    }
  } while( true );
}



===== EdppServiceExempt @ 1400344e0 =====

int EdppServiceExempt(longlong param_1,char *param_2)

{
  longlong *plVar1;
  int iVar2;
  
  plVar1 = *(longlong **)(param_1 + 0x48);
  *param_2 = '\0';
  if ((*plVar1 == 0x4896ef1a58125a50) && (plVar1[1] == 0x6ccab39ac6d657ba)) {
    iVar2 = 0;
  }
  else {
    iVar2 = SrpIsTokenService(*(undefined8 *)(param_1 + 0x30),param_2);
  }
  return iVar2;
}



===== WdagPluginNotifyRoutine @ 140034520 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
WdagPluginNotifyRoutine
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong *param_4,
          undefined8 param_5,longlong param_6,undefined8 param_7,undefined8 param_8,
          undefined4 *param_9)

{
  bool bVar1;
  undefined8 uVar2;
  longlong *plVar3;
  undefined1 auStackY_e8 [32];
  undefined4 local_b8;
  int local_b4;
  longlong local_b0;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 local_98;
  undefined8 local_88 [4];
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  int *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_9c = 0;
  plVar3 = &local_b0;
  local_b0 = param_6;
  local_a0 = (undefined4)param_2;
  local_a8 = param_1;
  local_98 = param_3;
  local_b4 = WdagPluginEvaluate(plVar3,param_2,param_3,param_4);
  if (local_b4 < 0) {
    if (DAT_140018000 != 0) {
      if (param_4 == (longlong *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = PsGetProcessId();
        plVar3 = param_4;
      }
      if (4 < DAT_140018000) {
        if (((_DAT_140018010 & 0x400000000000) == 0) ||
           ((DAT_140018018 & 0x400000000000) != DAT_140018018)) {
          bVar1 = false;
        }
        else {
          bVar1 = true;
        }
        if (bVar1) {
          local_5c = 0;
          local_68 = &local_b8;
          local_4c = 0;
          local_3c = 0;
          local_48 = &local_b4;
          local_b8 = (undefined4)uVar2;
          local_60 = 4;
          local_50 = 0x10;
          local_40 = 4;
          local_58 = param_1;
          _tlgWriteTransfer_EtwWriteTransfer(plVar3,&DAT_140015174,uVar2,4,5,local_88);
        }
      }
    }
  }
  *param_9 = 0;
  return 0;
}



===== WdagPluginEvaluate @ 140034664 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int WdagPluginEvaluate(longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  byte *pbVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined1 auStackY_118 [32];
  undefined4 uVar11;
  int local_d4;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined8 local_c0;
  undefined4 *puStack_b8;
  undefined8 local_b0;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 local_98;
  undefined4 local_90;
  undefined8 *local_88;
  undefined8 local_78 [4];
  int *local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_118;
  local_c8 = 4;
  uVar7 = 0;
  local_d0 = 0;
  bVar1 = DAT_140018000 != 0;
  bVar2 = true;
  iVar3 = 0;
  local_b0 = 1;
  uVar10 = 0;
  local_c0 = 0;
  puStack_b8 = (undefined4 *)0x0;
  plVar4 = param_1;
  if ((int)param_1[2] != 0) {
    while( true ) {
      lVar5 = uVar10 * 0x20 + param_1[3];
      if (lVar5 == 0) break;
      plVar4 = (longlong *)*param_1;
      if (plVar4 == (longlong *)0x0) {
        iVar3 = -0x3fffff0e;
        goto LAB_140034800;
      }
      SrppPluginAccessCheck(plVar4,*(longlong *)(lVar5 + 0x18),(uint *)&local_d0);
      uVar7 = local_d0;
      iVar3 = 0;
      if (-1 < (int)local_d0) {
        plVar4 = (longlong *)*param_1;
        puStack_b8 = &local_a8;
        param_4 = 0;
        local_88 = &local_b0;
        uVar8 = 0;
        local_c0 = 0x100000001;
        local_98 = 6;
        local_a8 = 0x3c003a;
        uStack_a4 = 0;
        uStack_a0 = 0x40014618;
        uStack_9c = 1;
        local_90 = 1;
        iVar3 = SeSetSecurityAttributesTokenEx(plVar4,0);
        if (-1 < iVar3) goto LAB_140034770;
        if (!bVar1) {
          return iVar3;
        }
        if (DAT_140018000 < 5) {
          return iVar3;
        }
        if (((_DAT_140018010 & 0x400000000000) == 0) ||
           ((DAT_140018018 & 0x400000000000) != DAT_140018018)) {
          bVar2 = false;
        }
        if (!bVar2) {
          return iVar3;
        }
        pbVar6 = &DAT_1400151be;
        uVar11 = 3;
        goto LAB_140034872;
      }
LAB_140034770:
      uVar9 = (int)uVar10 + 1;
      uVar10 = (ulonglong)uVar9;
      if (*(uint *)(param_1 + 2) <= uVar9) {
        return iVar3;
      }
    }
    iVar3 = -0x3fffff0f;
LAB_140034800:
    if ((bVar1) && (uVar8 = 4, 4 < DAT_140018000)) {
      if (((_DAT_140018010 & 0x400000000000) == 0) ||
         ((DAT_140018018 & 0x400000000000) != DAT_140018018)) {
        bVar2 = false;
      }
      if (bVar2) {
        pbVar6 = &DAT_140015214;
        local_48 = &local_d0;
        local_d0 = CONCAT44(local_d0._4_4_,(int)uVar7);
        uVar11 = 4;
        local_40 = 4;
LAB_140034872:
        local_50 = 4;
        local_58 = &local_d4;
        local_d4 = iVar3;
        _tlgWriteTransfer_EtwWriteTransfer(plVar4,pbVar6,uVar8,param_4,uVar11,local_78);
      }
    }
  }
  return iVar3;
}



===== SrpGetExemptEnterpriseIdsPresent @ 1400348b0 =====

int SrpGetExemptEnterpriseIdsPresent(longlong param_1,undefined1 *param_2)

{
  int iVar1;
  longlong local_res18 [2];
  longlong local_28 [4];
  
  local_res18[0] = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  InitSubjectByTokenHandle(param_1,local_28);
  iVar1 = QueryAttributes(local_28,0x10,local_res18);
  if (local_res18[0] == 0) {
    if (-1 < iVar1) {
      *param_2 = 0;
    }
  }
  else {
    *param_2 = 1;
    EnterpriseContextLibMemFree(local_res18[0]);
  }
  return iVar1;
}



===== KappxParsePackageFullNameFromToken @ 140034920 =====

int KappxParsePackageFullNameFromToken
              (ushort *param_1,short *param_2,short *param_3,undefined8 param_4,undefined8 param_5,
              ulonglong *param_6)

{
  int iVar1;
  void *_Dst;
  undefined8 uVar2;
  ushort uVar3;
  void *pvVar4;
  ushort uVar5;
  short *psVar6;
  uint uVar7;
  
  _Dst = (void *)ExAllocatePool2(0x100,*param_1,0x58707041);
  if (_Dst == (void *)0x0) {
    return -0x3fffffe9;
  }
  memmove(_Dst,*(void **)(param_1 + 4),(ulonglong)*param_1);
  uVar3 = *param_1 >> 1;
  uVar7 = 0;
  pvVar4 = _Dst;
  do {
    uVar5 = 0;
    if (uVar3 != 0) {
      do {
        if (*(short *)((longlong)pvVar4 + (ulonglong)uVar5 * 2) == 0x5f) {
          *(undefined2 *)((longlong)pvVar4 + (ulonglong)uVar5 * 2) = 0;
          break;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar3);
    }
    if ((uVar5 == uVar3) && (uVar7 != 4)) {
      iVar1 = -0x7ffffffb;
      break;
    }
    if (uVar7 == 0) {
      psVar6 = param_2;
LAB_140034a04:
      uVar2 = KappxParseString(pvVar4,uVar5,psVar6);
      iVar1 = (int)uVar2;
LAB_140034a0f:
      if (iVar1 < 0) break;
    }
    else {
      if (uVar7 == 1) {
        uVar2 = KappxParseVersion((longlong)pvVar4,uVar5,param_6);
        iVar1 = (int)uVar2;
        goto LAB_140034a0f;
      }
      if (uVar7 != 2) {
        if (uVar7 == 3) {
          psVar6 = (short *)0x0;
        }
        else {
          if (uVar7 != 4) {
            return -1;
          }
          psVar6 = param_3;
        }
        goto LAB_140034a04;
      }
      iVar1 = 0;
    }
    uVar7 = uVar7 + 1;
    uVar3 = uVar3 + (-1 - uVar5);
    pvVar4 = (void *)((longlong)pvVar4 + (ulonglong)uVar5 * 2 + 2);
  } while (uVar7 < 5);
  ExFreePoolWithTag(_Dst,0x58707041);
  return iVar1;
}



===== KappxParseString @ 140034a84 =====

undefined8 KappxParseString(void *param_1,ushort param_2,short *param_3)

{
  ushort uVar1;
  short sVar2;
  
  if (param_3 != (short *)0x0) {
    sVar2 = param_2 * 2;
    uVar1 = sVar2 + 2;
    if (*(void **)(param_3 + 4) == (void *)0x0) {
      param_3[1] = uVar1;
    }
    else {
      if ((ushort)param_3[1] < uVar1) {
        return 0xc000000d;
      }
      memmove(*(void **)(param_3 + 4),param_1,(ulonglong)param_2 * 2);
      if (uVar1 < 3) {
        sVar2 = 0;
      }
      *(undefined2 *)((ulonglong)param_2 * 2 + *(longlong *)(param_3 + 4)) = 0;
      *param_3 = sVar2;
    }
  }
  return 0;
}



===== KappxParseVersion @ 140034b20 =====

undefined8 KappxParseVersion(longlong param_1,ushort param_2,ulonglong *param_3)

{
  undefined8 uVar1;
  ushort uVar2;
  uint uVar3;
  uint local_res8 [2];
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_res8[0] = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (param_3 == (ulonglong *)0x0) {
    uVar1 = 0;
  }
  else {
    *param_3 = 0;
    uVar3 = 0;
    do {
      uVar2 = 0;
      if (param_2 != 0) {
        do {
          if (*(short *)(param_1 + (ulonglong)uVar2 * 2) == 0x2e) {
            *(undefined2 *)(param_1 + (ulonglong)uVar2 * 2) = 0;
            break;
          }
          uVar2 = uVar2 + 1;
        } while (uVar2 < param_2);
      }
      if ((uVar2 == param_2) && (uVar3 != 3)) {
        return 0x80000005;
      }
      RtlInitUnicodeString(&local_38,param_1);
      uVar1 = RtlUnicodeStringToInteger(&local_38,0,local_res8);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar3 = uVar3 + 1;
      *param_3 = *param_3 << 0x10 | (ulonglong)local_res8[0];
      param_2 = param_2 + (-1 - uVar2);
      param_1 = param_1 + (ulonglong)uVar2 * 2 + 2;
    } while (uVar3 < 4);
  }
  return uVar1;
}



===== EdpAuditLibMemAlloc @ 140034c1c =====

void EdpAuditLibMemAlloc(undefined8 param_1)

{
  ExAllocatePool2(0x100,param_1,0x41706445);
  return;
}



===== EdpGetLogFullPathFromRelativePath @ 140034c48 =====

uint EdpGetLogFullPathFromRelativePath(undefined8 param_1,undefined8 *param_2)

{
  short sVar1;
  longlong lVar2;
  short *psVar3;
  short *psVar4;
  short *psVar5;
  longlong lVar6;
  ulonglong uVar7;
  uint uVar9;
  uint uVar8;
  ulonglong uVar10;
  longlong lVar11;
  
  lVar2 = RtlGetNtSystemRoot();
  lVar6 = -1;
  do {
    lVar6 = lVar6 + 1;
  } while (*(short *)(lVar2 + lVar6 * 2) != 0);
  uVar9 = (uint)(ushort)(((short)lVar6 + 1) * 2);
  uVar8 = uVar9 - 2;
  uVar10 = (ulonglong)(uVar9 - 1) * 2 + 0x4a;
  psVar3 = (short *)ExAllocatePool2(0x100,uVar10,0x41706445);
  if (psVar3 == (short *)0x0) {
    return 0xc0000017;
  }
  uVar10 = uVar10 >> 1;
  if (uVar10 - 1 < 0x7fffffff) {
    if (uVar8 < 0x7fffffff) {
      psVar4 = psVar3;
      uVar7 = uVar10;
      do {
        if (((uVar8 - uVar10) + uVar7 == 0) ||
           (sVar1 = *(short *)((lVar2 - (longlong)psVar3) + (longlong)psVar4), sVar1 == 0)) break;
        *psVar4 = sVar1;
        psVar4 = psVar4 + 1;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
      psVar5 = psVar4 + -1;
      if (uVar7 != 0) {
        psVar5 = psVar4;
      }
      *psVar5 = 0;
      uVar8 = ~-(uint)(uVar7 != 0) & 0x80000005;
      if (-1 < (int)uVar8) {
        psVar4 = psVar3;
        uVar7 = uVar10;
        do {
          if (*psVar4 == 0) break;
          psVar4 = psVar4 + 1;
          uVar7 = uVar7 - 1;
        } while (uVar7 != 0);
        if (uVar7 == 0) {
          uVar8 = 0xc000000d;
        }
        else {
          lVar2 = uVar10 - uVar7;
          psVar4 = psVar3 + lVar2;
          lVar6 = uVar10 - lVar2;
          if (lVar6 != 0) {
            lVar2 = lVar6 + 0x25 + (lVar2 - uVar10);
            lVar11 = (longlong)L"\\security\\EDP\\Logs\\AppLearning_1.etl" - (longlong)psVar4;
            do {
              if ((lVar2 == 0) || (sVar1 = *(short *)(lVar11 + (longlong)psVar4), sVar1 == 0))
              break;
              *psVar4 = sVar1;
              lVar2 = lVar2 + -1;
              psVar4 = psVar4 + 1;
              lVar6 = lVar6 + -1;
            } while (lVar6 != 0);
          }
          psVar5 = psVar4 + -1;
          if (lVar6 != 0) {
            psVar5 = psVar4;
          }
          uVar8 = ~-(uint)(lVar6 != 0) & 0x80000005;
          *psVar5 = 0;
        }
        if (-1 < (int)uVar8) {
          *param_2 = psVar3;
          return uVar8;
        }
      }
      goto LAB_140034ce6;
    }
    *psVar3 = 0;
  }
  uVar8 = 0xc000000d;
LAB_140034ce6:
  ExFreePoolWithTag(psVar3,0);
  return uVar8;
}



===== EdppComposeFullPath @ 140034e08 =====

long EdppComposeFullPath(ushort *param_1,uint param_2,undefined8 *param_3,short *param_4)

{
  ushort uVar1;
  long lVar2;
  void *_Src;
  void *_Dst;
  longlong lVar3;
  ulonglong _Size;
  longlong lVar4;
  
  *param_3 = 0;
  *param_4 = 0;
  _Src = (void *)RtlGetNtSystemRoot();
  lVar4 = -1;
  lVar3 = -1;
  do {
    lVar3 = lVar3 + 1;
  } while (*(short *)((longlong)_Src + lVar3 * 2) != 0);
  uVar1 = (short)lVar3 * 2;
  lVar3 = -1;
  do {
    lVar3 = lVar3 + 1;
  } while (param_1[lVar3] != 0);
  _Size = (ulonglong)(ushort)(((short)lVar3 + 4) * 2 + uVar1);
  _Dst = (void *)ExAllocatePool2(0x100,_Size,0x41706445);
  if (_Dst == (void *)0x0) {
    lVar2 = -0x3fffffe9;
  }
  else {
    memset(_Dst,0,_Size);
    memmove(_Dst,_Src,(ulonglong)uVar1);
    lVar2 = RtlStringCbPrintfW((ushort *)((ulonglong)uVar1 + (longlong)_Dst),_Size - uVar1,param_1,
                               (ulonglong)param_2);
    if (lVar2 < 0) {
      ExFreePoolWithTag(_Dst,0);
    }
    else {
      *param_3 = _Dst;
      do {
        lVar4 = lVar4 + 1;
      } while (*(short *)((longlong)_Dst + lVar4 * 2) != 0);
      *param_4 = ((short)lVar4 + 1) * 2;
    }
  }
  return lVar2;
}



===== EdppCreateBaseLoggerInfo @ 140034f2c =====

undefined8
EdppCreateBaseLoggerInfo
          (undefined8 *param_1,void *param_2,ushort param_3,undefined8 *param_4,uint *param_5)

{
  longlong lVar1;
  uint *puVar2;
  undefined8 uVar3;
  uint uVar4;
  
  *param_4 = 0;
  lVar1 = -1;
  *param_5 = 0;
  do {
    lVar1 = lVar1 + 1;
  } while (*(short *)((longlong)param_2 + lVar1 * 2) != 0);
  uVar4 = param_3 + 0xb7 + (uint)(ushort)(((short)lVar1 + 1) * 2) & 0xfffffff8;
  puVar2 = (uint *)ExAllocatePool2(0x100,uVar4,0x41706445);
  if (puVar2 == (uint *)0x0) {
    uVar3 = 0xc0000017;
  }
  else {
    EdppSetLoggerInfoBaseParameters(param_1,param_2,param_3,puVar2,uVar4);
    uVar3 = 0;
    *param_4 = puVar2;
    *param_5 = uVar4;
  }
  return uVar3;
}



===== EdppCreateOrOpenFileOrDirectory @ 140034ff4 =====

long EdppCreateOrOpenFileOrDirectory(ushort *param_1)

{
  _UNICODE_STRING *p_Var1;
  long lVar2;
  undefined8 *in_stack_00000028;
  _UNICODE_STRING *local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  
  local_58 = (_UNICODE_STRING *)0x0;
  local_40 = 0;
  uStack_38 = 0;
  *in_stack_00000028 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  local_50 = 0;
  uStack_48 = 0;
  lVar2 = EdppCreateFileObject(param_1,(_OBJECT_ATTRIBUTES *)&local_40,&local_58);
  if (-1 < lVar2) {
    lVar2 = ZwCreateFile(in_stack_00000028,0x12019f,&local_40,&local_50,0,6,3,3,0x20,0,0);
  }
  p_Var1 = local_58;
  if (local_58 != (_UNICODE_STRING *)0x0) {
    if (*(longlong *)(local_58 + 8) != 0) {
      ExFreePoolWithTag(*(longlong *)(local_58 + 8),0);
    }
    ExFreePoolWithTag(p_Var1,0);
  }
  return lVar2;
}



===== EdppDeleteLogFile @ 1400350d4 =====

long EdppDeleteLogFile(ushort *param_1)

{
  _UNICODE_STRING *p_Var1;
  long lVar2;
  _UNICODE_STRING *local_res10 [3];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res10[0] = (_UNICODE_STRING *)0x0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  lVar2 = EdppCreateFileObject(param_1,(_OBJECT_ATTRIBUTES *)&local_38,local_res10);
  if (-1 < lVar2) {
    lVar2 = ZwDeleteFile(&local_38);
  }
  p_Var1 = local_res10[0];
  if (local_res10[0] != (_UNICODE_STRING *)0x0) {
    if (*(longlong *)(local_res10[0] + 8) != 0) {
      ExFreePoolWithTag(*(longlong *)(local_res10[0] + 8),0);
    }
    ExFreePoolWithTag(p_Var1,0);
  }
  return lVar2;
}



===== EdppDisableAndStopSession @ 140035160 =====

ulonglong EdppDisableAndStopSession
                    (undefined8 *param_1,void *param_2,undefined8 param_3,longlong param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint local_28 [2];
  uint *local_20;
  
  local_20 = (uint *)0x0;
  local_28[0] = 0;
  local_28[1] = 0;
  uVar4 = EdppCreateBaseLoggerInfo(param_1,param_2,0x800,&local_20,local_28);
  puVar1 = local_20;
  uVar5 = uVar4 & 0xffffffff;
  if (-1 < (int)uVar4) {
    if (param_4 == 0) {
      uVar2 = ZwTraceControl(3,local_20,*local_20,local_20,*local_20,local_28 + 1);
      uVar5 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) goto LAB_140035276;
      param_4 = *(longlong *)(puVar1 + 2);
      EdppSetLoggerInfoBaseParameters(param_1,param_2,0x800,puVar1,local_28[0]);
    }
    uVar2 = EtwEnableTrace(param_3,0,param_4,0,5,0,0,0);
    *(longlong *)(puVar1 + 2) = param_4;
    uVar3 = ZwTraceControl(2,puVar1,*puVar1,puVar1,*puVar1,local_28 + 1);
    uVar5 = (ulonglong)uVar3;
    if ((-1 < (int)uVar3) && ((int)uVar2 < 0)) {
      uVar5 = (ulonglong)uVar2;
    }
  }
LAB_140035276:
  if (puVar1 != (uint *)0x0) {
    ExFreePoolWithTag(puVar1,0);
  }
  return uVar5;
}



===== EdppDisableAudit @ 1400352b0 =====

ulonglong EdppDisableAudit(void)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined **ppuVar3;
  
  uVar2 = 0;
  ppuVar3 = &PTR_u_D425B399_4B71_4151_8DAF_413F92A7_140008f68;
  do {
    uVar1 = EdppDisableAndStopSession((undefined8 *)ppuVar3[-1],*ppuVar3,ppuVar3[3],0);
    if ((int)uVar1 < 0) {
      uVar2 = uVar1 & 0xffffffff;
    }
    ppuVar3 = ppuVar3 + -6;
  } while (0x140008f07 < (longlong)ppuVar3);
  return uVar2;
}



===== EdppDoWorkAsSystem @ 14003530c =====

int EdppDoWorkAsSystem(undefined8 param_1)

{
  int iVar1;
  longlong local_res8;
  undefined8 local_48;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_40 = 0;
  local_34 = 0;
  local_1c = 0;
  local_res8 = 0;
  local_30 = 0;
  local_28 = 0;
  local_3c = 0;
  local_38 = 0x30;
  local_20 = 0x200;
  local_18 = 0;
  uStack_10 = 0;
  local_48 = param_1;
  iVar1 = PsCreateSystemThread(&local_res8,0x1fffff,&local_38,0,0,EdppThreadStart,&local_48);
  if (-1 < iVar1) {
    iVar1 = ZwWaitForSingleObject(local_res8,0,0);
    if (-1 < iVar1) {
      if (iVar1 != 0) {
        iVar1 = -0x3ffff6f5;
      }
      if (local_40 < 0) {
        iVar1 = local_40;
      }
    }
  }
  if (local_res8 != 0) {
    ZwClose();
  }
  return iVar1;
}



===== EdppEnableAudit @ 1400353f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long EdppEnableAudit(void)

{
  long lVar1;
  undefined **ppuVar2;
  int iVar3;
  ulonglong uVar4;
  longlong *plVar5;
  uint uVar6;
  undefined1 auStackY_78 [32];
  longlong local_38 [4];
  
  local_38[3] = __security_cookie ^ (ulonglong)auStackY_78;
  ppuVar2 = &PTR_u__security_EDP_Logs_AuditTCB_meta_140008f18;
  uVar4 = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  iVar3 = 2;
  do {
    uVar6 = 0;
    do {
      uVar6 = uVar6 + 1;
      lVar1 = EdppStartAndEnableSession
                        ((longlong *)ppuVar2[-3],ppuVar2[-2],(ushort *)ppuVar2[-1],
                         (ushort *)*ppuVar2,ppuVar2[1],*(char *)(ppuVar2 + 2),local_38 + uVar4);
      if (lVar1 != -0x3fffffcb) {
        if (lVar1 < 0) goto LAB_1400354a0;
        break;
      }
      EdppDisableAndStopSession((undefined8 *)ppuVar2[-3],ppuVar2[-2],ppuVar2[1],0);
    } while (uVar6 < 2);
    uVar6 = (int)uVar4 + 1;
    uVar4 = (ulonglong)uVar6;
    ppuVar2 = ppuVar2 + 6;
    if (2 < uVar6) {
      if (lVar1 < 0) {
LAB_1400354a0:
        plVar5 = local_38 + 2;
        ppuVar2 = &PTR_u_D425B399_4B71_4151_8DAF_413F92A7_140008f68;
        do {
          if (*plVar5 != 0) {
            EdppDisableAndStopSession((undefined8 *)ppuVar2[-1],*ppuVar2,ppuVar2[3],*plVar5);
            *plVar5 = 0;
          }
          ppuVar2 = ppuVar2 + -6;
          plVar5 = plVar5 + -1;
          iVar3 = iVar3 + -1;
        } while (-1 < iVar3);
      }
      return lVar1;
    }
  } while( true );
}



===== EdppSetLoggerInfoBaseParameters @ 140035508 =====

void EdppSetLoggerInfoBaseParameters
               (undefined8 *param_1,void *param_2,undefined2 param_3,uint *param_4,uint param_5)

{
  ushort uVar1;
  short sVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  longlong lVar5;
  
  lVar5 = -1;
  do {
    lVar5 = lVar5 + 1;
  } while (*(short *)((longlong)param_2 + lVar5 * 2) != 0);
  sVar2 = (short)lVar5 * 2;
  uVar1 = sVar2 + 2;
  memset(param_4,0,(ulonglong)param_5);
  *param_4 = param_5;
  uVar3 = *param_1;
  uVar4 = param_1[1];
  param_4[0xb] = 0x20000;
  *(undefined8 *)(param_4 + 6) = uVar3;
  *(undefined8 *)(param_4 + 8) = uVar4;
  *(ushort *)((longlong)param_4 + 0x92) = uVar1;
  *(short *)(param_4 + 0x24) = sVar2;
  *(uint **)(param_4 + 0x26) = param_4 + 0x2c;
  memmove(param_4 + 0x2c,param_2,(ulonglong)uVar1);
  *(ulonglong *)(param_4 + 0x22) =
       (ulonglong)*(ushort *)((longlong)param_4 + 0x92) + *(longlong *)(param_4 + 0x26);
  *(undefined2 *)((longlong)param_4 + 0x82) = param_3;
  *(undefined2 *)(param_4 + 0x20) = 0;
  return;
}



===== EdppStartAndEnableSession @ 1400355e4 =====

long EdppStartAndEnableSession
               (longlong *param_1,void *param_2,ushort *param_3,ushort *param_4,undefined8 param_5,
               char param_6,longlong *param_7)

{
  undefined4 *puVar1;
  ushort *puVar2;
  int iVar3;
  long lVar4;
  longlong lVar5;
  undefined8 uVar6;
  uint uVar7;
  longlong lVar8;
  bool bVar9;
  undefined4 uVar10;
  undefined8 *in_stack_ffffffffffffff50;
  ushort local_98 [2];
  short local_94 [2];
  uint local_90 [2];
  uint local_88 [2];
  undefined4 local_80 [2];
  undefined4 *local_78;
  longlong local_70;
  ushort *local_68;
  undefined8 local_60;
  ushort *local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  
  lVar8 = 0;
  local_58 = (ushort *)0x0;
  local_98[0] = 0;
  local_78 = (undefined4 *)0x0;
  *param_7 = 0;
  lVar5 = *param_1 + -0x41514b71d425b399;
  local_88[0] = 0;
  local_80[0] = 0;
  if (lVar5 == 0) {
    lVar5 = param_1[1] + 0x3ca1586dc0be5073;
  }
  bVar9 = lVar5 == 0;
  local_94[0] = 0;
  local_70 = 0;
  local_90[0] = 0;
  local_68 = (ushort *)0x0;
  local_60 = 0;
  local_48 = 0;
  uStack_40 = 0;
  uVar7 = 0;
  iVar3 = EdppComposeFullPath(param_4,0,&local_68,local_94);
  puVar2 = local_68;
  if (iVar3 < 0) {
    if (local_70 != 0) {
      ZwClose();
      local_70 = 0;
    }
  }
  else {
    lVar4 = EdppCreateOrOpenFileOrDirectory(local_68);
    lVar8 = local_70;
    if (lVar4 < 0) {
      return lVar4;
    }
    in_stack_ffffffffffffff50 = &local_60;
    iVar3 = ZwReadFile(local_70,0,0,0,&local_48,local_90,4,in_stack_ffffffffffffff50,0);
    if (((iVar3 < 0) || ((int)uStack_40 != 4)) || (0x7f < local_90[0])) {
      iVar3 = 0;
    }
    else {
      uVar7 = local_90[0];
    }
  }
  if (puVar2 != (ushort *)0x0) {
    ExFreePoolWithTag(puVar2,0);
  }
  if (iVar3 < 0) goto LAB_140035971;
  if (bVar9) {
    uVar7 = 1;
  }
  else {
    uVar7 = uVar7 + 1 & 0x7f;
  }
  iVar3 = EdppComposeFullPath(param_3,uVar7,&local_58,(short *)local_98);
  puVar2 = local_58;
  if (-1 < iVar3) {
    uVar6 = EdppCreateBaseLoggerInfo(param_1,param_2,local_98[0],&local_78,local_88);
    puVar1 = local_78;
    iVar3 = (int)uVar6;
    if (-1 < iVar3) {
      if (bVar9) {
        local_78[0x10] = 0x10000005;
        local_78[10] = 2;
      }
      else {
        local_78[0x10] = 0x10000002;
        local_78[10] = 1;
      }
      if (param_6 != '\0') {
        local_78[0x10] = local_78[0x10] | 0x80;
      }
      local_78[0xf] = (-(uint)bVar9 & 7) + 1;
      local_78[0xc] = 8;
      local_78[0x11] = 0;
      *(ushort *)(local_78 + 0x20) = local_98[0] - 2;
      memmove(*(void **)(local_78 + 0x22),puVar2,(ulonglong)local_98[0]);
      iVar3 = ZwTraceControl(1,puVar1,*puVar1,puVar1,*puVar1,local_80);
      if (iVar3 == -0x3ffffff3) {
        if ((!bVar9) || (lVar4 = EdppDeleteLogFile(puVar2), lVar4 < 0)) goto LAB_140035945;
        iVar3 = ZwTraceControl(1,puVar1,*puVar1,puVar1,*puVar1,local_80);
      }
      if (-1 < iVar3) {
        lVar5 = *(longlong *)(puVar1 + 2);
        uVar10 = 0;
        iVar3 = EtwEnableTrace(param_5,0,lVar5,1,5,0,0,
                               (ulonglong)in_stack_ffffffffffffff50 & 0xffffffff00000000);
        if (-1 < iVar3) {
          local_78 = (undefined4 *)0x0;
          local_58 = (ushort *)0x0;
          uStack_50 = 0;
          local_88[0] = uVar7;
          iVar3 = ZwWriteFile(lVar8,0,0,0,&local_58,local_88,CONCAT44(uVar10,4),&local_78,0);
          if (-1 < iVar3) {
            if ((int)uStack_50 == 4) {
              *param_7 = lVar5;
              goto LAB_140035945;
            }
            iVar3 = -0x3fffff68;
          }
        }
        if (lVar5 != 0) {
          EdppDisableAndStopSession(param_1,param_2,param_5,lVar5);
        }
      }
    }
LAB_140035945:
    if (puVar1 != (undefined4 *)0x0) {
      ExFreePoolWithTag(puVar1,0);
    }
  }
  if (puVar2 != (ushort *)0x0) {
    ExFreePoolWithTag(puVar2,0);
  }
LAB_140035971:
  if (lVar8 != 0) {
    ZwClose(lVar8);
  }
  return iVar3;
}



===== EdppThreadStart @ 1400359c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void EdppThreadStart(undefined8 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)*param_1)();
  *(undefined4 *)(param_1 + 1) = uVar1;
  return;
}



===== HashpParsePEHeader @ 1400359e4 =====

undefined8
HashpParsePEHeader(int *param_1,uint param_2,uint param_3,uint *param_4,longlong *param_5)

{
  uint uVar1;
  int *piVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  uint uVar7;
  short sVar8;
  uint uVar9;
  int *piVar10;
  int *piVar11;
  uint uVar12;
  uint *puVar13;
  
  *param_5 = (longlong)param_1;
  *(uint *)(param_5 + 4) = param_2;
  if (param_1 == (int *)0x0) {
    return 0xc000000d;
  }
  if (param_3 <= param_2) {
    param_2 = param_3;
  }
  piVar2 = (int *)((ulonglong)param_2 + (longlong)param_1);
  if (piVar2 < param_1) {
    return 0xc000000d;
  }
  if (param_2 < 0x40) {
    return 0xc000007b;
  }
  if ((short)*param_1 == 0x5a4d) {
    uVar7 = param_1[0xf];
    if (uVar7 == 0) {
      return 0xc000007b;
    }
    if (param_2 < uVar7) {
      return 0xc000007b;
    }
    if (param_2 - uVar7 < 0x109) {
      return 0xc000007b;
    }
    piVar10 = (int *)((ulonglong)uVar7 + (longlong)param_1);
    param_5[1] = (longlong)piVar10;
    if (piVar2 < piVar10 + 0x42) {
      return 0xc000007b;
    }
    if (piVar10 < param_1 + 0x10) {
      return 0xc000007b;
    }
  }
  else {
    if ((short)*param_1 != 0x4550) {
      return 0xc000007b;
    }
    param_5[1] = (longlong)param_1;
    piVar10 = param_1;
  }
  if ((ulonglong)param_2 < (ulonglong)((longlong)piVar10 + (0x108 - (longlong)param_1))) {
    return 0xc000000d;
  }
  if (*piVar10 != 0x4550) {
    return 0xc000007b;
  }
  if (*(ushort *)(piVar10 + 5) == 0) {
    return 0xc000007b;
  }
  if ((*(ushort *)(piVar10 + 5) & 7) != 0) {
    return 0xc000007b;
  }
  sVar8 = (short)piVar10[1];
  if (sVar8 == 0x3a64) {
    sVar8 = 0x14c;
  }
  if (((sVar8 != 0x14c) && (sVar8 != 0x1c0)) && (sVar8 != 0x1c4)) {
    if (sVar8 == 0x200) {
      uVar7 = 0x2000;
      goto LAB_140035b1d;
    }
    if ((sVar8 != -0x799c) && (sVar8 != -0x559c)) {
      return 0xc000007b;
    }
  }
  uVar7 = 0x1000;
LAB_140035b1d:
  *(uint *)(param_5 + 5) = uVar7;
  if (uVar7 < 0x1001) {
    lVar6 = param_5[1];
    if (*(short *)(lVar6 + 0x18) == 0x10b) {
      if (((sVar8 != 0x14c) && (sVar8 != 0x1c0)) && (sVar8 != 0x1c4)) {
        return 0xc000007b;
      }
      puVar13 = (uint *)(lVar6 + 0x98);
    }
    else {
      if (*(short *)(lVar6 + 0x18) != 0x20b) {
        return 0xc000007b;
      }
      if (((sVar8 != 0x200) && (sVar8 != -0x799c)) && (sVar8 != -0x559c)) {
        return 0xc000007b;
      }
      puVar13 = (uint *)(lVar6 + 0xa8);
    }
    uVar7 = *(uint *)(lVar6 + 0x54);
    uVar9 = *(uint *)(lVar6 + 0x38);
    uVar12 = *(uint *)(lVar6 + 0x50);
    uVar4 = *(uint *)(lVar6 + 0x3c);
    *(uint *)((longlong)param_5 + 0x24) = uVar7;
    *(uint *)(param_5 + 2) = uVar9;
    if (((uVar7 != 0) && (uVar7 < *(uint *)(param_5 + 4))) &&
       ((((uVar4 != 0 && (((uVar4 & uVar4 - 1) == 0 && ((uVar9 & uVar9 - 1) == 0)))) &&
         (uVar4 <= uVar9)) && (((uVar4 & 0x1ff) == 0 || (uVar4 == uVar9)))))) {
      lVar6 = param_5[1];
      uVar3 = *(ushort *)(lVar6 + 6);
      piVar11 = (int *)(lVar6 + 0x18 + (ulonglong)*(ushort *)(lVar6 + 0x14));
      *(uint *)((longlong)param_5 + 0x14) = (uint)uVar3;
      param_5[3] = (longlong)piVar11;
      piVar10 = (int *)((ulonglong)((uint)uVar3 * 0x28) + (longlong)piVar11);
      if (((piVar11 <= piVar10) && (piVar10 <= piVar2)) &&
         (((ulonglong)((longlong)piVar10 - *param_5) <= (ulonglong)uVar7 ||
          ((ulonglong)((longlong)piVar10 - *param_5) <= (ulonglong)uVar12)))) {
        uVar9 = (int)piVar10 - (int)*param_5;
        uVar12 = 0;
        uVar7 = uVar9;
        if (uVar3 != 0) {
          do {
            uVar4 = piVar11[(ulonglong)uVar12 * 10 + 5];
            uVar5 = piVar11[(ulonglong)uVar12 * 10 + 4];
            if ((uVar4 != 0) && (uVar4 < uVar9)) {
              return 0xc000007b;
            }
            uVar1 = uVar5 + uVar4;
            if (uVar1 < uVar4) {
              return 0xc000007b;
            }
            if (*(uint *)(param_5 + 4) < uVar1) {
              return 0xc000007b;
            }
            if ((uVar5 != 0) && (uVar7 < uVar1)) {
              uVar7 = uVar1;
            }
            if ((int)param_5[2] + -1 + uVar5 < uVar5) {
              return 0xc000007b;
            }
            uVar12 = uVar12 + 1;
          } while (uVar12 < uVar3);
        }
        uVar9 = *puVar13;
        uVar12 = puVar13[1];
        if ((uVar9 == 0) || (uVar12 == 0)) {
          if (param_4 != (uint *)0x0) {
            param_4[0] = 0;
            param_4[1] = 0;
          }
        }
        else {
          if (uVar9 < uVar7) {
            return 0xc000007b;
          }
          if (*(uint *)(param_5 + 4) < uVar9) {
            return 0xc000007b;
          }
          if (uVar12 + uVar9 != *(uint *)(param_5 + 4)) {
            return 0xc000007b;
          }
          if (uVar12 + uVar9 < uVar9) {
            return 0xc000007b;
          }
          if (uVar9 < *(uint *)((longlong)param_5 + 0x24)) {
            return 0xc000007b;
          }
          if ((uVar9 & 3) != 0) {
            return 0xc000007b;
          }
          if (param_4 != (uint *)0x0) {
            *param_4 = uVar9;
            param_4[1] = uVar12;
          }
        }
        return 0;
      }
    }
  }
  return 0xc000007b;
}



===== SrppMapFileImage @ 140035d3c =====

int SrppMapFileImage(longlong param_1,longlong *param_2)

{
  int iVar1;
  longlong local_res8;
  undefined8 local_res18 [2];
  longlong local_78;
  longlong lStack_70;
  longlong local_68;
  longlong lStack_60;
  undefined1 local_58;
  undefined4 uStack_57;
  undefined2 uStack_53;
  undefined1 uStack_51;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 uStack_28;
  
  local_58 = 1;
  local_4c = 0;
  local_34 = 0;
  local_68 = 0;
  lStack_60 = 0;
  uStack_57 = 0;
  uStack_53 = 0;
  uStack_51 = 0;
  local_res18[0] = 0;
  local_78 = 0;
  lStack_70 = 0;
  if ((param_1 == 0) || (param_2 == (longlong *)0x0)) {
    return -0x3ffffff3;
  }
  *param_2 = 0;
  param_2[1] = 0;
  local_50 = 0x30;
  param_2[2] = 0;
  param_2[3] = 0;
  local_48 = 0;
  param_2[4] = 1;
  local_38 = 0x200;
  local_30 = 0;
  uStack_28 = 0;
  local_40 = 0;
  iVar1 = ZwCreateSection(&local_78,5,&local_50,0,2,0x8000000,param_1);
  if (-1 < iVar1) {
    local_res8 = 0;
    iVar1 = ObReferenceObjectByHandle(local_78,0,0,0,&local_res8,0);
    lStack_60 = local_res8;
    if (-1 < iVar1) {
      iVar1 = MmMapViewInSystemSpace(local_res8,&lStack_70,&local_68);
      if (iVar1 < 0) {
        lStack_70 = 0;
        local_68 = 0;
        iVar1 = MmMapViewOfSection(lStack_60,*(undefined8 *)PsInitialSystemProcess_exref,&lStack_70,
                                   0,0,local_res18,&local_68,2,0,2);
        if (iVar1 < 0) goto LAB_140035ecc;
        local_58 = 0;
      }
      *param_2 = local_78;
      param_2[1] = lStack_70;
      param_2[2] = local_68;
      param_2[3] = lStack_60;
      param_2[4] = CONCAT17(uStack_51,CONCAT25(uStack_53,CONCAT41(uStack_57,local_58)));
      return iVar1;
    }
  }
LAB_140035ecc:
  SrppUnmapFileImage(&local_78);
  return iVar1;
}



===== SrppUnmapFileImage @ 140035ef8 =====

void SrppUnmapFileImage(longlong *param_1)

{
  if (param_1 != (longlong *)0x0) {
    if (param_1[1] != 0) {
      if ((char)param_1[4] == '\0') {
        MmUnmapViewOfSection(*(undefined8 *)PsInitialSystemProcess_exref);
      }
      else {
        MmUnmapViewInSystemSpace(param_1[1]);
      }
    }
    if (param_1[3] != 0) {
      ObfDereferenceObject();
      param_1[3] = 0;
    }
    if (*param_1 != 0) {
      ZwClose();
      *param_1 = 0;
    }
  }
  return;
}



===== SrpIsApplicationAutoProtectionAllowed @ 140035f7c =====

void SrpIsApplicationAutoProtectionAllowed(longlong param_1,byte *param_2)

{
  int iVar1;
  
  iVar1 = SrppIsApplicationEDPResourceSetKernel(2,param_1,param_2);
  if ((-1 < iVar1) && (*param_2 == 0)) {
    SrppIsApplicationEDPResourceSetKernel(3,param_1,param_2);
  }
  return;
}



===== SrppIsApplicationEDPResourceSet @ 140035fc8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SrppIsApplicationEDPResourceSet(int param_1,longlong param_2,undefined8 param_3,byte *param_4)

{
  int iVar1;
  byte bVar2;
  undefined1 auStack_78 [32];
  byte **local_58;
  ulonglong *local_50;
  undefined8 local_48;
  undefined8 local_40;
  ulonglong local_38;
  byte *local_30;
  wchar_t *local_28;
  wchar_t *pwStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  bVar2 = 0;
  local_30 = (byte *)0x0;
  local_38 = 0;
  if (param_1 == 0) {
    local_28 = L"EDPENLIGHTENEDAPPINFOID";
    pwStack_20 = L"MICROSOFTEDPENLIGHTENEDAPPINFO";
  }
  else if (param_1 == 1) {
    local_28 = L"EDPPERMISSIVEAPPINFOID";
    pwStack_20 = L"MICROSOFTEDPPERMISSIVEAPPINFO";
  }
  else {
    if (param_1 == 2) {
      local_28 = L"EDPAUTOPROTECTIONALLOWEDAPPINFOID";
    }
    else {
      if (param_1 != 3) {
        return -0x3ffffff3;
      }
      local_28 = L"AUTOPROTECTIONALLOWEDAPPINFOID";
    }
    pwStack_20 = L"MICROSOFTEDPAUTOPROTECTIONALLOWEDAPPINFO";
  }
  local_18 = 0;
  if (param_2 == 0) {
    return -0x3ffffff3;
  }
  local_40 = 0;
  local_50 = &local_38;
  local_48 = 0;
  local_58 = &local_30;
  iVar1 = LdrResSearchResource(param_2,&local_28,3,0x1210);
  if (iVar1 < 0) {
    if (2 < iVar1 + 0x3fffff77U) {
      return iVar1;
    }
    iVar1 = 0;
  }
  else if (1 < local_38) {
    bVar2 = *local_30 & 1;
  }
  *param_4 = bVar2;
  return iVar1;
}



===== SrppIsApplicationEDPResourceSetKernel @ 1400360fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int SrppIsApplicationEDPResourceSetKernel(int param_1,longlong param_2,byte *param_3)

{
  int iVar1;
  byte *pbVar2;
  bool bVar3;
  undefined1 auStack_a8 [32];
  undefined4 local_88;
  int local_84;
  longlong local_80;
  longlong lStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_a8;
  local_80 = 0;
  lStack_78 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  bVar3 = false;
  local_88 = 0;
  if ((param_2 == 0) || (param_3 == (byte *)0x0)) {
    iVar1 = -0x3ffffff3;
  }
  else {
    *param_3 = 0;
    pbVar2 = param_3;
    iVar1 = SrppMapFileImage(param_2,&local_80);
    if (-1 < iVar1) {
      bVar3 = (char)local_60 == '\0';
      if (bVar3) {
        KeStackAttachProcess(*(undefined8 *)PsInitialSystemProcess_exref,&local_58);
        local_88 = 1;
      }
      iVar1 = SrppIsApplicationEDPResourceSet(param_1,lStack_78,pbVar2,param_3);
      local_84 = iVar1;
    }
    if (bVar3) {
      KeUnstackDetachProcess(&local_58);
    }
    SrppUnmapFileImage(&local_80);
  }
  return iVar1;
}



===== AiVerifyPackageMoniker$filt$0 @ 14003621b =====

void AiVerifyPackageMoniker_filt_0(undefined8 *param_1)

{
  I_RpcExceptionFilter(*(ulong *)*param_1);
  return;
}



===== entry @ 140037010 =====

void entry(undefined *param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 140037044 =====

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



===== AipInitializePluginsCallback @ 140037080 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AipInitializePluginsCallback(longlong param_1,undefined8 *param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 local_18;
  undefined8 local_10;
  
  local_10 = 0;
  if (*(code **)(param_1 + 0x38) != (code *)0x0) {
    local_18 = param_3;
    iVar1 = (**(code **)(param_1 + 0x38))(&local_18);
    if (-1 < iVar1) {
      *param_2 = local_10;
    }
  }
  return;
}



===== DriverEntry @ 1400370c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * DriverEntry(undefined *param_1)

{
  undefined8 uVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  char *pcVar7;
  undefined *puVar8;
  code *pcVar9;
  undefined1 *puVar10;
  undefined8 *puVar11;
  undefined1 *puVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  undefined1 auStack_258 [8];
  undefined1 auStack_250 [60];
  undefined4 local_214;
  undefined8 local_210;
  wchar_t *local_208;
  undefined8 local_1e0;
  wchar_t *local_1d8;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  undefined8 local_1b0;
  ulonglong uStack_1a8;
  undefined4 local_1a0;
  undefined4 uStack_19c;
  undefined4 uStack_198;
  undefined4 uStack_194;
  undefined4 local_188;
  uint local_184;
  uint local_180;
  undefined1 local_68 [32];
  undefined1 *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_258;
  local_210 = 0x1c001a;
  local_1e0 = 0x140012;
  _WPP_MAIN_CB = 0;
  local_208 = L"\\Device\\AppID";
  DAT_140018770 = 0;
  local_1d8 = L"\\??\\AppID";
  bVar2 = true;
  _DAT_140018780 = 0;
  local_1b0 = 0;
  uStack_1a8 = uStack_1a8 & 0xffffffff00000000;
  DAT_140018768 = &WPP_ThisDir_CTLGUID_AppIDLog;
  local_1d0 = 0;
  uStack_1c8 = 0;
  _DAT_140018788 = 1;
  local_1c0 = 0;
  uStack_1b8 = 0;
  WppLoadTracingSupport();
  _DAT_140018780 = 0;
  WppInitKm();
  if ((g_SymCryptFlags & 1) == 0) {
    local_188 = 0x114;
    iVar4 = RtlGetVersion(&local_188);
    if (((iVar4 < 0) || (local_184 < 6)) || ((local_184 == 6 && (local_180 < 3)))) {
      SymCryptFatal(0x6e737276);
      pcVar9 = (code *)swi(3);
      puVar14 = (undefined8 *)(*pcVar9)();
      return puVar14;
    }
    SymCryptDetectCpuFeaturesByCpuid();
    uVar6 = RtlGetEnabledExtendedFeatures(0xffffffffffffffff);
    if ((uVar6 & 4) == 0) {
      g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | 0x10;
    }
    if ((uVar6 & 0xe0) == 0) {
      g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | 0x1000;
    }
    g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent & 0xffffffdf;
    LOCK();
    g_SymCryptFlags = g_SymCryptFlags | 1;
    UNLOCK();
    pcVar7 = "v103.12.0__2026-05-07T00:16:03+00:00_0df2f18_2026-05-07T21:50:22";
    local_214 = 0x67000c;
    cVar3 = 'v';
    while (cVar3 != '\0') {
      pcVar7 = pcVar7 + 1;
      local_214 = CONCAT31(local_214._1_3_,cVar3);
      cVar3 = *pcVar7;
    }
    _g_SymCryptCpuFeaturesPresentCheck = ~g_SymCryptCpuFeaturesNotPresent;
  }
  puVar12 = auStack_258;
  local_1a0 = *(undefined4 *)(PTR_DAT_140018008 + -0x10);
  uStack_19c = *(undefined4 *)(PTR_DAT_140018008 + -0xc);
  uStack_198 = *(undefined4 *)(PTR_DAT_140018008 + -8);
  uStack_194 = *(undefined4 *)(PTR_DAT_140018008 + -4);
  if (DAT_140018020 != 0) {
    pcVar9 = (code *)swi(0x29);
    (*pcVar9)(5);
    puVar12 = auStack_250;
  }
  puVar14 = &DAT_140018020;
  _DAT_140018028 = 0;
  uRam0000000140018030 = 0;
  *(undefined8 *)(puVar12 + -8) = 0x140037274;
  iVar4 = EtwRegister(&local_1a0,_tlgEnableCallback,&DAT_140018000);
  if (iVar4 == 0) {
    puVar14 = (undefined8 *)(ulonglong)*(ushort *)PTR_DAT_140018008;
    *(undefined8 *)(puVar12 + -8) = 0x1400372a7;
    EtwSetInformation(DAT_140018020);
  }
  else if (((iVar4 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    uVar1 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined8 *)(puVar12 + -8) = 0x1400372d5;
    WPP_SF_(uVar1,10,&WPP_4bc66d74a05f389d64780558abe6f77a_Traceguids);
  }
  *(undefined8 *)(puVar12 + -8) = 0x1400372da;
  wil_InitializeFeatureStaging();
  puVar10 = (undefined1 *)0x0;
  puVar13 = (undefined8 *)0x188;
  *(undefined8 *)(puVar12 + -8) = 0x1400372f1;
  memset(&g_AppId,0,0x188);
  *(undefined8 *)(puVar12 + -8) = 0x1400372ff;
  uVar5 = ExInitializeResourceLite(&DAT_1400187c0);
  puVar11 = (undefined8 *)(ulonglong)uVar5;
  if (-1 < (int)uVar5) {
    DAT_1400187b0 = 1;
    *(undefined8 *)(puVar12 + -8) = 0x140037319;
    uVar6 = AipReadConfigOptions();
    puVar11 = (undefined8 *)(uVar6 & 0xffffffff);
    if ((int)uVar6 < 0) goto LAB_140037448;
    *(undefined8 *)(puVar12 + -8) = 0x140037331;
    uVar5 = ExInitializeResourceLite(&DAT_1400188a0);
    puVar11 = (undefined8 *)(ulonglong)uVar5;
    if ((int)uVar5 < 0) goto LAB_140037448;
    DAT_140018920 = 1;
    DAT_140018868 = &DAT_140018860;
    puVar14 = &DAT_1400187b8;
    DAT_140018860 = &DAT_140018860;
    puVar8 = &AppIdEventProviderId;
    puVar13 = (undefined8 *)0x0;
    DAT_140018878 = &DAT_140018870;
    puVar10 = (undefined1 *)0x0;
    DAT_140018870 = &DAT_140018870;
    DAT_140018888 = &DAT_140018880;
    DAT_140018880 = &DAT_140018880;
    DAT_140018898 = &DAT_140018890;
    DAT_140018890 = &DAT_140018890;
    *(undefined8 *)(puVar12 + -8) = 0x1400373b5;
    uVar5 = EtwRegister();
    puVar11 = (undefined8 *)(ulonglong)uVar5;
    if (-1 < (int)uVar5) {
      *(undefined8 *)(puVar12 + -8) = 0x1400373eb;
      uVar5 = AiInitializeLib();
      puVar11 = (undefined8 *)(ulonglong)uVar5;
      if ((int)uVar5 < 0) goto LAB_140037448;
      *(undefined4 *)(puVar12 + 0x40) = 0;
      *(wchar_t **)(puVar12 + 0x70) =
           L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\AppID\\";
      puVar14 = (undefined8 *)(puVar12 + 0x40);
      *(undefined8 *)(puVar12 + 0x68) = 0x740072;
      puVar13 = (undefined8 *)(puVar12 + 0x58);
      *(wchar_t **)(puVar12 + 0x60) = L"DisableExeLinkedTokenLookup";
      puVar10 = puVar12 + 0x68;
      *(undefined8 *)(puVar12 + 0x58) = 0x380036;
      *(undefined8 *)(puVar12 + -8) = 0x140037434;
      iVar4 = AiRegReadDwordValue(puVar8,puVar10,puVar13,(undefined4 *)puVar14);
      if ((iVar4 < 0) || (*(int *)(puVar12 + 0x40) == 0)) goto LAB_140037448;
      DisableExeLinkedTokenLookup = 1;
      goto LAB_14003744c;
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_1400374ba;
    puVar10 = (undefined1 *)0x10;
    goto LAB_1400374ab;
  }
LAB_140037448:
  if (-1 < (int)puVar11) {
LAB_14003744c:
    *(undefined8 *)(puVar12 + -8) = 0x140037454;
    uVar6 = SrpInitialize(param_1);
    puVar11 = (undefined8 *)(uVar6 & 0xffffffff);
    if (-1 < (int)uVar6) {
      *(undefined8 **)(puVar12 + 0x30) = &g_AppId;
      puVar13 = (undefined8 *)(puVar12 + 0x48);
      puVar12[0x28] = 0;
      puVar14 = (undefined8 *)0x22;
      puVar10 = (undefined1 *)0x0;
      *(undefined4 *)(puVar12 + 0x20) = 0x100;
      *(undefined8 *)(puVar12 + -8) = 0x140037483;
      uVar5 = IoCreateDevice(param_1);
      puVar11 = (undefined8 *)(ulonglong)uVar5;
      if ((int)uVar5 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          puVar10 = &DAT_0000000b;
LAB_1400374ab:
          uVar1 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          puVar13 = (undefined8 *)&WPP_4bc66d74a05f389d64780558abe6f77a_Traceguids;
          *(undefined8 *)(puVar12 + -8) = 0x1400374ba;
          puVar14 = puVar11;
          WPP_SF_D(uVar1,(short)puVar10,&WPP_4bc66d74a05f389d64780558abe6f77a_Traceguids,
                   (int)puVar11);
        }
      }
      else {
        puVar13 = (undefined8 *)&DAT_140009640;
        puVar10 = (undefined1 *)0x4;
        *(undefined8 *)(puVar12 + -8) = 0x140037595;
        uVar5 = ObSetSecurityObjectByPointer(g_AppId);
        puVar11 = (undefined8 *)(ulonglong)uVar5;
        if ((int)uVar5 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            puVar10 = (undefined1 *)0xc;
            goto LAB_1400374ab;
          }
        }
        else {
          puVar10 = puVar12 + 0x48;
          *(undefined8 *)(puVar12 + -8) = 0x1400375d7;
          uVar5 = IoCreateSymbolicLink(puVar12 + 0x78);
          puVar11 = (undefined8 *)(ulonglong)uVar5;
          if ((int)uVar5 < 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
              puVar10 = (undefined1 *)0xd;
              goto LAB_1400374ab;
            }
          }
          else {
            DAT_1400187a8 = 1;
            *(code **)(param_1 + 0x68) = AipUnload;
            puVar13 = &local_1d0;
            local_1d0 = CONCAT44(local_1d0._4_4_,0x30);
            *(code **)(param_1 + 0x70) = AipCreateDispatch;
            uStack_1c8 = 0;
            *(code **)(param_1 + 0x80) = AipCloseDispatch;
            uStack_1b8 = CONCAT44(uStack_1b8._4_4_,0x200);
            *(code **)(param_1 + 0xe0) = AipDeviceIoControlDispatch;
            puVar14 = (undefined8 *)0x0;
            local_1c0 = 0;
            puVar10 = (undefined1 *)0x1f0003;
            *(code **)(param_1 + 0x100) = AipCleanupDispatch;
            local_1b0 = 0;
            uStack_1a8 = 0;
            puVar12[0x20] = 0;
            *(undefined8 *)(puVar12 + -8) = 0x14003768b;
            uVar5 = ZwCreateEvent(&DAT_140018240);
            puVar11 = (undefined8 *)(ulonglong)uVar5;
            if ((int)uVar5 < 0) {
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                puVar10 = (undefined1 *)0xe;
                goto LAB_1400374ab;
              }
            }
            else {
              puVar10 = (undefined1 *)0x0;
              pcVar9 = AiProcessNotifyRoutine;
              *(undefined8 *)(puVar12 + -8) = 0x1400376cc;
              uVar5 = PsSetCreateProcessNotifyRoutineEx();
              puVar11 = (undefined8 *)(ulonglong)uVar5;
              if (-1 < (int)uVar5) {
                DAT_1400187ac = 1;
                param_1 = pcVar9;
                goto LAB_1400374d6;
              }
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
                puVar10 = (undefined1 *)0xf;
                goto LAB_1400374ab;
              }
            }
          }
        }
      }
    }
  }
LAB_1400374ba:
  if (DAT_1400187b8 != 0) {
    *(undefined8 *)(puVar12 + -8) = 0x1400374ce;
    puVar13 = puVar11;
    AiLogStatusEvent(DAT_1400187b8,puVar10,(int)puVar11);
  }
  *(undefined8 *)(puVar12 + -8) = 0x1400374d6;
  AipUnload();
LAB_1400374d6:
  if (4 < DAT_140018000) {
    if (((_DAT_140018010 & 0x400000000000) == 0) ||
       ((DAT_140018018 & 0x400000000000) != DAT_140018018)) {
      bVar2 = false;
    }
    if (bVar2) {
      local_48 = puVar12 + 0x40;
      *(int *)(puVar12 + 0x40) = (int)puVar11;
      local_40 = 4;
      *(undefined1 **)(puVar12 + 0x28) = local_68;
      *(undefined4 *)(puVar12 + 0x20) = 3;
      *(undefined8 *)(puVar12 + -8) = 0x140037548;
      _tlgWriteTransfer_EtwWriteTransfer
                (param_1,&DAT_140014e5a,puVar13,puVar14,*(undefined4 *)(puVar12 + 0x20),
                 *(undefined8 **)(puVar12 + 0x28));
    }
  }
  *(undefined8 *)(puVar12 + -8) = 0x140037559;
  return puVar11;
}



===== wil_InitializeFeatureStaging @ 14003771c =====

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
      if (*ppuVar3 != (undefined *)0x0) goto LAB_1400377a3;
    }
LAB_1400377dd:
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
LAB_1400377a3:
  if (ppuVar3 == (undefined **)0x0) goto LAB_1400377dd;
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
    goto LAB_1400377dd;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_1400172df < ppuVar3) goto LAB_1400377dd;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1400377a3;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140037830 =====

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
            if (&UNK_1400172df < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14003791a;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14003791a;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14003791a:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_1400172df < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}



===== SrpInitialize @ 1400379ac =====

ulonglong SrpInitialize(undefined8 param_1)

{
  uint uVar1;
  ulonglong uVar2;
  code *pcVar3;
  undefined2 uVar4;
  ulonglong uVar5;
  undefined8 local_68;
  wchar_t *local_60;
  undefined8 local_58;
  wchar_t *local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 *local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong uStack_10;
  
  local_68 = 0x240022;
  local_58 = 0x1c001a;
  local_60 = L"\\Device\\SrpDevice";
  local_50 = L"\\??\\SrpDevice";
  local_18 = 0;
  uStack_10 = uStack_10 & 0xffffffff00000000;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = (undefined8 *)0x0;
  uStack_20 = 0;
  local_48 = 0;
  uStack_40 = 0;
  memset(&g_Srp,0,0x50);
  g_Srp = 1;
  uVar1 = EtwRegister(&SrpEventProviderId,0,0,&DAT_140018718);
  uVar5 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x200) == 0)) goto LAB_140037a82;
    uVar4 = 10;
  }
  else {
    SrppPolicyChangeCallback(0);
    RtlInitUnicodeString(&local_48,L"\\Callback\\LicensingData");
    uStack_30 = 0;
    local_28 = &local_48;
    local_38 = CONCAT44(local_38._4_4_,0x30);
    uStack_20 = CONCAT44(uStack_20._4_4_,0x50);
    local_18 = 0;
    uStack_10 = 0;
    uVar1 = ExCreateCallback(&DAT_140018720,&local_38,0,1);
    uVar5 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) goto LAB_140037a82;
    DAT_140018728 = ExRegisterCallback(DAT_140018720,SrppPolicyChangeCallback,0);
    if (DAT_140018728 == 0) {
      uVar5 = 0xc0000001;
      goto LAB_140037a82;
    }
    uVar1 = IoCreateDevice(param_1,0,&local_68,0x22,0x100,0,&DAT_140018708);
    uVar5 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140037a82;
      uVar4 = 0xb;
    }
    else {
      uVar1 = ObSetSecurityObjectByPointer(DAT_140018708,4,&DAT_14000aec0);
      uVar5 = (ulonglong)uVar1;
      if ((int)uVar1 < 0) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140037a82;
        uVar4 = 0xc;
      }
      else {
        uVar1 = IoCreateSymbolicLink(&local_58,&local_68);
        uVar5 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          pcVar3 = AipInitializePluginsCallback;
          uVar2 = AipForEachPlugin(AipInitializePluginsCallback,param_1);
          uVar5 = uVar2 & 0xffffffff;
          if (-1 < (int)uVar2) {
            SrppReadNoPropogtionLogOption(pcVar3);
            DAT_140018710 = 1;
            return uVar5;
          }
          goto LAB_140037a82;
        }
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) goto LAB_140037a82;
        uVar4 = 0xd;
      }
    }
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_aad0858379b034ee89b756b7616fecef_Traceguids,(int)uVar5);
LAB_140037a82:
  SrpCleanup();
  return uVar5;
}



===== AiInitializeLib @ 140037c70 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

NTSTATUS AiInitializeLib(void)

{
  NTSTATUS NVar1;
  BCRYPT_ALG_HANDLE *phAlgorithm;
  undefined **ppuVar2;
  uint uVar3;
  ulonglong uVar4;
  
  memset(&AiPerfStats,0,0xc0);
  AppHashAlgInitialized = 1;
  AppHashAlgHandle = 0;
  DAT_140018588 = 0;
  uVar4 = 0;
  ppuVar2 = &PTR_u_SHA1_1400086d0;
  do {
    phAlgorithm = (BCRYPT_ALG_HANDLE *)(&AppHashAlgHandle + uVar4);
    NVar1 = BCryptOpenAlgorithmProvider(phAlgorithm,(LPCWSTR)*ppuVar2,(LPCWSTR)0x0,0);
    if (NVar1 < 0) goto LAB_140037d25;
    uVar3 = (int)uVar4 + 1;
    uVar4 = (ulonglong)uVar3;
    ppuVar2 = ppuVar2 + 1;
  } while (uVar3 < 2);
  if ((-1 < NVar1) && (NVar1 = AiInitializeCertStore(), -1 < NVar1)) {
    DAT_1400184b8 = 0;
    _AipAppxInMemoryCache = 0;
    _DAT_1400184a0 = 0;
    _AipAppxRegCache = 0;
    AipAppxInMemoryCacheInitialized = 1;
    AipAppxRegCacheInitialized = 1;
    AiInitializeConfiguration(phAlgorithm);
    return NVar1;
  }
LAB_140037d25:
  AiFreeLib();
  return NVar1;
}



===== AiInitializeCertStore @ 140037d44 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int AiInitializeCertStore(void)

{
  int iVar1;
  int iVar2;
  longlong local_res8 [4];
  wchar_t local_18 [4];
  void *pvStack_10;
  
  local_res8[0] = 0;
  AipCertificateStore = 0;
  _DAT_1400185f8 = 0;
  local_18[0] = L'\0';
  local_18[1] = L'\0';
  local_18[2] = L'\0';
  local_18[3] = L'\0';
  pvStack_10 = (void *)0x0;
  AipCertificateStoreInitialized = 1;
  if (AipServiceContextInitialized == 0) {
    _AipServiceContext = 0;
    DAT_140018618 = 0;
    DAT_140018620 = 0;
    AipServiceContextInitialized = 1;
    DAT_140018608 = 0;
    DAT_140018610 = 0;
  }
  iVar1 = AiRegOpenKey(0,&DAT_1400085b0,0x20019,local_res8);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0')) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_b7d6d7747cbe39158d21f26ad040a04c_Traceguids,iVar1);
    }
  }
  else {
    iVar1 = 0;
    while( true ) {
      iVar2 = AiRegGetSubkeyName(local_res8[0],iVar1,local_18);
      iVar1 = iVar1 + 1;
      if (iVar2 < 0) break;
      AipAddCertFromCertStore(local_res8[0],local_18);
      AiFree(pvStack_10);
    }
    iVar1 = 0;
    if (iVar2 != -0x7fffffe6) {
      iVar1 = iVar2;
    }
  }
  if (local_res8[0] != 0) {
    ZwClose();
  }
  if (iVar1 < 0) {
    AiFreeCertStore();
  }
  return iVar1;
}



===== EdpPluginInit @ 140037e60 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void EdpPluginInit(undefined8 *param_1)

{
  longlong *plVar1;
  int iVar2;
  undefined8 *puVar3;
  int local_res8 [2];
  undefined8 in_stack_ffffffffffffff68;
  ulonglong uVar4;
  ulonglong in_stack_ffffffffffffff70;
  undefined8 local_78;
  wchar_t *local_70;
  undefined8 local_68;
  wchar_t *local_60;
  undefined8 local_58;
  wchar_t *local_50;
  undefined8 local_48;
  wchar_t *local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_78 = 0x2e002c;
  plVar1 = param_1 + 1;
  _EdppAuditSessionLock = 0;
  local_70 = L"\\Device\\AppidEDPPlugin";
  local_60 = L"\\??\\AppidEDPPlugin";
  local_40 = L"\\REGISTRY\\MACHINE\\System\\CurrentControlSet\\control\\session manager\\kernel";
  local_res8[0] = 0;
  local_50 = L"SeTokenSingletonAttributesConfig";
  local_68 = 0x260024;
  local_48 = 0x940092;
  local_58 = 0x420040;
  local_34 = 0;
  local_1c = 0;
  uVar4 = CONCAT44((int)((ulonglong)in_stack_ffffffffffffff68 >> 0x20),0x100);
  iVar2 = IoCreateDevice(*param_1,1,&local_78,0x22,uVar4,
                         in_stack_ffffffffffffff70 & 0xffffffffffffff00,plVar1);
  if (-1 < iVar2) {
    iVar2 = ObSetSecurityObjectByPointer(*plVar1,4,&DAT_14000cd48);
    if (-1 < iVar2) {
      puVar3 = &local_68;
      iVar2 = IoCreateSymbolicLink(puVar3,&local_78);
      if (-1 < iVar2) {
        *(undefined1 *)(*plVar1 + 0x40) = 1;
        AiRegReadDwordValue(puVar3,&local_48,&local_58,local_res8);
        EdppSingleInstanceAttributes = local_res8[0] != 0;
        _EdppRuntimeConfig = 0;
        local_38 = 0x30;
        local_30 = 0;
        local_20 = 0x240;
        local_28 = 0;
        local_18 = 0;
        uStack_10 = 0;
        iVar2 = ZwCreateEvent(&DAT_1400184f8,0x1f0003,&local_38,1,uVar4 & 0xffffffffffffff00);
        if (-1 < iVar2) {
          PsCreateSystemThread(&DAT_1400184f0,0x1fffff,0,0,0,EdppPolicyUpdateSystemThread,0);
        }
      }
    }
  }
  return;
}


