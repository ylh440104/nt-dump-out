
===== _tlgWriteTransfer_EtwWriteTransfer @ 1c0001008 =====

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



===== __report_gsfailure @ 1c00010c0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== IntelPmtpEvtDeviceIoControl @ 1c00010d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void IntelPmtpEvtDeviceIoControl
               (undefined8 param_1,undefined8 param_2,ulonglong param_3,void **param_4,int param_5)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  undefined *_Size;
  undefined1 auStackY_d8 [32];
  int local_98;
  uint local_94;
  void *local_90;
  undefined8 local_88 [4];
  int *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  uint *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_90 = (void *)0x0;
  if ((IntelPmtpDiagTraceHandleInitialized != '\0') && (5 < DAT_1c0007028)) {
    local_5c = 0;
    local_68 = &local_98;
    local_98 = param_5;
    local_60 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005a06,param_3,param_4,3,local_88);
  }
  uVar4 = 0;
  uVar2 = (**(code **)(WdfFunctions_01023 + 0x4e8))(WdfDriverGlobals,param_1);
  _Size = PTR__WDF_INTELPMTP_DEVICE_EXTENSION_TYPE_INFO_1c0007018;
  lVar3 = (**(code **)(WdfFunctions_01023 + 0x650))(WdfDriverGlobals,uVar2);
  if (param_5 == -0x6666999c) {
    uVar2 = (**(code **)(WdfFunctions_01023 + 0x8e8))(WdfDriverGlobals,param_2);
    if ((PfnIoValidateDeviceIoControlAccess == (code *)0x0) ||
       (iVar1 = (*PfnIoValidateDeviceIoControlAccess)(uVar2,1), -1 < iVar1)) {
      if (*(longlong *)(lVar3 + 0x68) == 0) {
        iVar1 = -0x3ffffe7c;
      }
      else {
        param_4 = &local_90;
        _Size = (undefined *)0x4;
        iVar1 = (**(code **)(WdfFunctions_01023 + 0x870))(WdfDriverGlobals,param_2);
        if (iVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            param_4 = (void **)0x11;
            WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,_Size,0x11,
                              &WPP_f84f8971834f360366e1ee7734d3dbd7_Traceguids,(char)iVar1);
          }
        }
        else {
          uVar5 = *(int *)((longlong)*(void **)(lVar3 + 0x68) + 8) * 0x20 + 0x10;
          uVar4 = uVar5;
          if (param_3 <= uVar5) {
            uVar4 = (uint)param_3;
          }
          _Size = (undefined *)(ulonglong)uVar4;
          memcpy(local_90,*(void **)(lVar3 + 0x68),(size_t)_Size);
          *(uint *)((longlong)local_90 + 4) = uVar5;
          if (uVar4 < uVar5) {
            iVar1 = -0x3fffffdd;
          }
          else {
            iVar1 = 0;
          }
        }
      }
    }
  }
  else {
    iVar1 = -0x3ffffff0;
  }
  if ((IntelPmtpDiagTraceHandleInitialized != '\0') && (5 < DAT_1c0007028)) {
    local_5c = 0;
    local_68 = &local_98;
    local_4c = 0;
    local_58 = &local_94;
    local_60 = 4;
    local_50 = 4;
    local_98 = iVar1;
    local_94 = uVar4;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c00059cc,_Size,param_4,4,local_88);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  (**(code **)(WdfFunctions_01023 + 0x848))(WdfDriverGlobals,param_2,iVar1,uVar4);
  return;
}



===== WPP_RECORDER_SF_D @ 1c0001388 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_D(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,param_5,param_4,&param_6,4,0);
  return;
}



===== WPP_RECORDER_SF_DD @ 1c0001438 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f84f8971834f360366e1ee7734d3dbd7_Traceguids,0x12,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_f84f8971834f360366e1ee7734d3dbd7_Traceguids,0x12,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== WppClassicProviderCallback @ 1c0001510 =====

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



===== _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertDiagTrackProv @ 1c000156c =====

void _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertDiagTrackProv(void)

{
  return;
}



===== wil_details_RecordCachedUsage @ 1c0001578 =====

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



===== wil_details_RecordFeatureUsageReporting @ 1c00016d0 =====

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



===== IntelPmtSamplerEvtProcessQueryInterfaceRequest @ 1c0001760 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
IntelPmtSamplerEvtProcessQueryInterfaceRequest
          (undefined8 param_1,longlong *param_2,ushort *param_3,undefined8 param_4)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  ushort *puVar4;
  undefined1 auStackY_a8 [32];
  undefined4 local_68 [2];
  ushort *local_60;
  undefined8 local_58 [4];
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ushort **local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  puVar4 = param_3;
  if (((*param_2 == 0x43dd30c2f03df99a) && (param_2[1] == -0x2db3d36257b1cb6f)) && (0x67 < *param_3)
     ) {
    if (param_3[1] == 1) {
      if (IntelPmtpSamplerTables == (undefined4 *)0x0) {
        uVar3 = 0xc0000184;
      }
      else {
        puVar4 = (ushort *)PTR__WDF_INTELPMTP_DEVICE_EXTENSION_TYPE_INFO_1c0007018;
        uVar2 = (**(code **)(WdfFunctions_01023 + 0x650))(WdfDriverGlobals,param_1);
        *(undefined8 *)(param_3 + 4) = uVar2;
        uVar3 = 0;
        uVar1 = *IntelPmtpSamplerTables;
        *(code **)(param_3 + 8) = IntelPmtpSamplerReferenceInterface;
        *(code **)(param_3 + 0xc) = IntelPmtpSamplerDereferenceInterface;
        *(code **)(param_3 + 0x10) = IntelPmtpSamplerQueryMetadata;
        *(code **)(param_3 + 0x14) = IntelPmtpSamplerStart;
        *(code **)(param_3 + 0x18) = IntelPmtpSamplerStop;
        *(undefined4 *)(param_3 + 0x1c) = uVar1;
      }
    }
    else {
      uVar3 = 0xc000000d;
    }
  }
  else {
    uVar3 = 0xc00000bb;
  }
  if ((IntelPmtpDiagTraceHandleInitialized != '\0') && (5 < DAT_1c0007028)) {
    local_2c = 0;
    local_38 = local_68;
    local_1c = 0;
    local_28 = &local_60;
    local_30 = 4;
    local_20 = 8;
    local_68[0] = uVar3;
    local_60 = param_3;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005e08,puVar4,param_4,4,local_58);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return uVar3;
}



===== IntelPmtpSamplerDereferenceInterface @ 1c0001910 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IntelPmtpSamplerDereferenceInterface(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = (**(code **)(WdfFunctions_01023 + 0x660))(WdfDriverGlobals,param_1);
  (**(code **)(WdfFunctions_01023 + 0x670))
            (WdfDriverGlobals,uVar1,0x706d742d,0x76a,
             "onecore\\base\\power\\intel\\intelpmt\\pmtsampler.c");
  return;
}



===== IntelPmtpSamplerReferenceInterface @ 1c0001980 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IntelPmtpSamplerReferenceInterface(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = (**(code **)(WdfFunctions_01023 + 0x660))(WdfDriverGlobals,param_1);
  (**(code **)(WdfFunctions_01023 + 0x668))
            (WdfDriverGlobals,uVar1,0x706d742b,0x74b,
             "onecore\\base\\power\\intel\\intelpmt\\pmtsampler.c");
  return;
}



===== IntelPmtpSamplingTimerCallback @ 1c00019f0 =====

void IntelPmtpSamplingTimerCallback(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  if (param_2 != 0) {
    uVar2 = *(uint *)(param_2 + 0x50);
    do {
      LOCK();
      uVar1 = *(uint *)(param_2 + 0x50);
      bVar3 = uVar2 == uVar1;
      if (bVar3) {
        *(uint *)(param_2 + 0x50) = uVar2 | 1;
      }
      else {
        uVar2 = uVar1;
      }
      UNLOCK();
    } while (!bVar3);
    if (uVar2 == 0) {
      ExQueueWorkItem(param_2 + 0x58,1);
    }
  }
  return;
}



===== WPP_RECORDER_SF_ @ 1c0001a30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,param_4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,param_4,0);
  return;
}



===== WPP_RECORDER_SF_Dd @ 1c0001ab8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Dd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,param_4,&param_6,4,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,param_4,&param_6,4,
                  &param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_DdI @ 1c0001b88 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DdI(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,0x1f,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,0x1f,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,8,0);
  return;
}



===== WPP_RECORDER_SF_Ddd @ 1c0001c7c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Ddd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,0x2a,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,0x2a,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_DddDD @ 1c0001d68 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DddDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,0x14,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,0x14,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_Ddq @ 1c0001e98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Ddq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,0x2f,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,0x2f,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,8,0);
  return;
}



===== WPP_RECORDER_SF_Dq @ 1c0001f8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Dq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,0x30,&uStack0000000000000030,4,
               &uStack0000000000000038,8,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,0x30,
                  &uStack0000000000000030,4,&uStack0000000000000038,8,0);
  return;
}



===== WPP_RECORDER_SF_d @ 1c0002060 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_d(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,param_4,&param_6,4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,&WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,param_4,
                  &param_6,4,0);
  return;
}



===== WPP_RECORDER_SF_dD @ 1c0002114 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,0x13,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,0x13,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_dd @ 1c00021e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,param_4,&param_6,4,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,param_4,&param_6,4,
                  &param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_ddD @ 1c00022b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ddD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,0xd,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,0xd,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_ddd @ 1c00023a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ddd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined4 local_18 [2];
  undefined4 local_10 [2];
  
  local_18[0] = 3600000;
  local_10[0] = 1000;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,0x19,&uStack0000000000000030,4,
               local_10,4,local_18,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,0x19,
                  &uStack0000000000000030,4,local_10,4,local_18,4,0);
  return;
}



===== WPP_RECORDER_SF_i @ 1c0002498 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_i(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,param_4,&param_6,8,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,param_4,&param_6,8,0)
  ;
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 1c0002544 =====

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
LAB_1c000274d:
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
LAB_1c000261f:
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
      if (param_3 == 4) goto LAB_1c000274d;
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
        goto LAB_1c000261f;
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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 1c0002838 =====

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
                     (local_50,(uint *)&Feature_SamplerSupportADLN__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (0x27a7f21,param_3,1,&Feature_SamplerSupportADLN__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)param_3,0x27a7f21);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 1c0002924 =====

void wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath(undefined8 param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 3) {
    uVar1 = 0x10;
  }
  else {
    if (param_2 != 4) {
      return;
    }
    uVar1 = 0x20;
  }
  LOCK();
  UNLOCK();
  Feature_SamplerSupportADLN__private_featureState._0_4_ =
       (uint)Feature_SamplerSupportADLN__private_featureState | uVar1;
  return;
}



===== FxStubDriverUnloadCommon @ 1c000294c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0007158 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_1c0007158 + 0x50);
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_1c00029a5:
      if (ppvVar1 == (void **)0x0) goto LAB_1c00029fb;
      if (ppvVar2 <= ppvVar1) goto LAB_1c0002a13;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if ((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) goto LAB_1c00029a5;
LAB_1c00029fb:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_1c0002a13:
  WdfVersionUnbind(&DAT_1c0007400,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 1c0002a50 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2,param_3,param_4);
  return;
}



===== FxDriverEntryWorker @ 1c0002a84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(_WDF_BIND_INFO *param_1,undefined8 param_2,undefined8 param_3,
                       undefined8 param_4)

{
  int iVar1;
  int iVar2;
  _WDF_BIND_INFO *p_Var3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if (param_1 == (_WDF_BIND_INFO *)0x0) {
    iVar1 = DriverEntry(0,param_2,param_3,param_4);
  }
  else {
    _DAT_1c0007400 = 0x2080000;
    _DAT_1c0007408 = &DAT_1c00071f0;
    RtlCopyUnicodeString(&DAT_1c0007400);
    puVar5 = &WdfDriverGlobals;
    puVar4 = &WdfBindInfo;
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_1c0007400);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2,puVar4,puVar5);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1c00073f8 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_1c0007400);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0007158 != &__KMDF_CLASS_BIND_START) {
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



===== FxStubDriverUnload @ 1c0002c10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1c00073f8 != (code *)0x0) && (DAT_1c00073f8 != FxStubDriverUnload)) {
    (*DAT_1c00073f8)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 1c0002c44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0002c69) */
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
    if ((void **)0x1c000714f < ppvVar2) break;
    if (((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_1c0007158 = (undefined *)ppvVar2;
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



===== FxStubInitTypes @ 1c0002dcc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0002de9) */
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
    if ((void **)0x1c000716f < ppvVar2) break;
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



===== MicrosoftTelemetryAssertTriggeredArgsMsgKM @ 1c0002e94 =====

void MicrosoftTelemetryAssertTriggeredArgsMsgKM
               (char *param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  ulonglong unaff_retaddr;
  
  MicrosoftTelemetryAssertTriggeredWorker(unaff_retaddr,1,param_1,param_2,param_3,param_4);
  return;
}



===== MicrosoftTelemetryAssertTriggeredWorker @ 1c0002ec8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c0003094) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MicrosoftTelemetryAssertTriggeredWorker
               (ulonglong param_1,undefined8 param_2,char *param_3,undefined4 param_4,
               undefined4 param_5,char *param_6)

{
  code *pcVar1;
  bool bVar2;
  undefined1 uVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  ulonglong *puVar8;
  ulonglong *puVar9;
  longlong lVar10;
  ulonglong *puVar11;
  undefined8 *puVar12;
  longlong lVar13;
  undefined1 *puVar14;
  char *pcVar15;
  undefined8 uVar16;
  ulonglong uVar17;
  undefined8 uVar18;
  uint uVar19;
  undefined1 auStack_1a8 [8];
  undefined1 auStack_1a0 [116];
  undefined4 local_12c;
  char *local_128;
  undefined4 local_120 [2];
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
  undefined8 local_b0;
  char **local_a8;
  undefined8 local_a0;
  char **local_98;
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
  
  puVar14 = auStack_1a8;
  local_38 = __security_cookie ^ (ulonglong)auStack_1a8;
  uVar19 = 0;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) goto LAB_1c00034fc;
  local_12c = param_4;
  local_128 = param_3;
  uVar3 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
  puVar14 = auStack_1a8;
  for (puVar9 = g_MicrosoftTelemetryAssertsTriggeredList;
      (ulonglong **)puVar9 != &g_MicrosoftTelemetryAssertsTriggeredList;
      puVar9 = (ulonglong *)*puVar9) {
    puVar8 = puVar9 + -4;
    if (*puVar8 == param_1) goto LAB_1c0003018;
  }
  puVar8 = (ulonglong *)ExAllocatePool2(0x42,0x30,0x74727341);
  lVar13 = _DAT_fffff78000000320;
  puVar14 = auStack_1a8;
  if (puVar8 != (ulonglong *)0x0) {
    *puVar8 = param_1;
    uVar6 = KeQueryTimeIncrement();
    puVar14 = auStack_1a8;
    puVar8[2] = 0;
    *(undefined4 *)(puVar8 + 3) = 0;
    puVar12 = &g_MicrosoftTelemetryAssertsTriggeredList;
    puVar8[1] = (longlong)((ulonglong)uVar6 * lVar13) / 10000 - 0xea61;
    puVar9 = puVar8 + 4;
    puVar11 = g_MicrosoftTelemetryAssertsTriggeredList;
    if ((ulonglong **)g_MicrosoftTelemetryAssertsTriggeredList[1] !=
        &g_MicrosoftTelemetryAssertsTriggeredList) {
      puVar11 = (ulonglong *)0x3;
      pcVar1 = (code *)swi(0x29);
      puVar9 = (ulonglong *)(*pcVar1)();
      puVar14 = auStack_1a0;
    }
    *puVar9 = (ulonglong)puVar11;
    puVar9[1] = (ulonglong)puVar12;
    puVar11[1] = (ulonglong)puVar9;
    g_MicrosoftTelemetryAssertsTriggeredList = puVar9;
LAB_1c0003018:
    *(int *)(puVar8 + 2) = (int)puVar8[2] + 1;
    *(int *)((longlong)puVar8 + 0x14) = *(int *)((longlong)puVar8 + 0x14) + 1;
    lVar13 = _DAT_fffff78000000320;
    *(undefined8 *)(puVar14 + -8) = 0x1c0003028;
    uVar6 = KeQueryTimeIncrement();
    uVar17 = (longlong)((ulonglong)uVar6 * lVar13) / 10000;
    if (60000 < uVar17 - puVar8[1]) {
      *(dword *)(puVar14 + 0x50) = 0xe22c4b63;
      uVar16 = 0x20b;
      if ((0x1bfffffff < param_1) && (param_1 < 0x1c0013001)) {
        uVar19 = (int)param_1 + 0x40000000;
      }
      *(int *)(puVar14 + 0x74) = (int)puVar8[2];
      *(undefined4 *)(puVar14 + 0x78) = *(undefined4 *)((longlong)puVar8 + 0x14);
      puVar8[1] = uVar17;
      *(int *)(puVar14 + 0x70) = (int)puVar8[3];
      *(undefined8 *)(puVar14 + -8) = 0x1c00030e1;
      KeReleaseSpinLock(&g_AssertSpinLock);
      uVar18 = 0x400000000000;
      pcVar15 = (char *)0x0;
      if (local_128 != (char *)0x0) {
        pcVar15 = local_128;
      }
      lVar13 = -1;
      if (DAT_1c000a040 < 6) {
LAB_1c00032be:
        uVar6 = *(uint *)(puVar14 + 0x50);
      }
      else {
        if (((_DAT_1c000a050 & 0x400000000000) == 0) ||
           (bVar2 = true, (DAT_1c000a058 & 0x400000000000) != DAT_1c000a058)) {
          bVar2 = false;
        }
        if (!bVar2) goto LAB_1c00032be;
        uVar6 = *(uint *)(puVar14 + 0x50);
        local_f8 = local_120;
        local_e8 = puVar14 + 0x54;
        local_d8 = puVar14 + 0x58;
        local_c8 = puVar14 + 0x5c;
        *(undefined4 *)(puVar14 + 0x60) = *(undefined4 *)(puVar14 + 0x74);
        local_a8 = (char **)(puVar14 + 0x60);
        local_128 = (char *)CONCAT44(local_128._4_4_,*(undefined4 *)(puVar14 + 0x78));
        local_98 = &local_128;
        local_120[0] = 10;
        local_f0 = 4;
        *(uint *)(puVar14 + 0x54) = uVar19;
        local_e0 = 4;
        *(uint *)(puVar14 + 0x58) = uVar6;
        local_d0 = 4;
        *(dword *)(puVar14 + 0x5c) = 0x13000;
        local_c0 = 4;
        local_b8 = "<unknown>";
        local_b0 = 10;
        local_a0 = 4;
        local_90 = 4;
        *(undefined8 *)(puVar14 + -8) = 0x1c00031db;
        bVar4 = KeGetCurrentIrql();
        local_80 = 4;
        *(uint *)(puVar14 + 100) = (uint)bVar4;
        local_88 = puVar14 + 100;
        if (pcVar15 == (char *)0x0) {
          local_78 = "";
          local_70 = 1;
        }
        else {
          lVar10 = -1;
          do {
            lVar10 = lVar10 + 1;
          } while (pcVar15[lVar10] != '\0');
          local_70 = (int)lVar10 + 1;
          local_78 = pcVar15;
        }
        *(undefined4 *)(puVar14 + 0x68) = *(undefined4 *)(puVar14 + 0x7c);
        local_68 = puVar14 + 0x68;
        *(undefined4 *)(puVar14 + 0x6c) = param_5;
        local_58 = puVar14 + 0x6c;
        if (param_6 == (char *)0x0) {
          param_6 = "<unknown>";
        }
        local_6c = 0;
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
        *(undefined1 **)(puVar14 + 0x28) = local_118;
        *(undefined4 *)(puVar14 + 0x20) = 0xe;
        local_3c = 0;
        *(undefined8 *)(puVar14 + -8) = 0x1c00032bc;
        local_48 = param_6;
        _tlgWriteTransfer_EtwWriteTransfer
                  (0x1c000a040,&DAT_1c0005f7d,uVar16,uVar18,*(undefined4 *)(puVar14 + 0x20),
                   *(undefined8 **)(puVar14 + 0x28));
      }
      if ((DAT_1c000a078 == 0) || (*(int *)(puVar14 + 0x70) != 0)) goto LAB_1c00034fc;
      *(undefined8 *)(puVar14 + -8) = 0x1c00032e4;
      cVar5 = KeGetCurrentIrql();
      if (cVar5 != '\0') goto LAB_1c00034fc;
      *(undefined4 *)(puVar14 + 0x40) = 0;
      uVar16 = 0;
      *(undefined8 *)(puVar14 + 0x38) = 0;
      *(undefined8 *)(puVar14 + 0x30) = 0;
      *(undefined8 *)(puVar14 + 0x28) = 0x13000;
      *(ulonglong *)(puVar14 + 0x20) = (ulonglong)uVar6;
      uVar17 = (ulonglong)uVar19;
      *(undefined8 *)(puVar14 + -8) = 0x1c0003328;
      iVar7 = DbgkWerCaptureLiveKernelDump(L"TELASSERT",0x1d1);
      if (5 < DAT_1c000a040) {
        if (((_DAT_1c000a050 & 0x400000000000) == 0) ||
           (bVar2 = true, (DAT_1c000a058 & 0x400000000000) != DAT_1c000a058)) {
          bVar2 = false;
        }
        if (bVar2) {
          local_f0 = 4;
          local_f8 = (undefined4 *)(puVar14 + 0x70);
          local_e8 = puVar14 + 0x6c;
          *(undefined4 *)(puVar14 + 0x68) = *(undefined4 *)(puVar14 + 0x50);
          local_d8 = puVar14 + 0x68;
          local_c8 = puVar14 + 100;
          local_b8 = "<unknown>";
          local_128 = (char *)CONCAT44(local_128._4_4_,*(undefined4 *)(puVar14 + 0x74));
          local_a8 = &local_128;
          *(undefined4 *)(puVar14 + 0x60) = *(undefined4 *)(puVar14 + 0x78);
          local_98 = (char **)(puVar14 + 0x60);
          local_88 = puVar14 + 0x5c;
          *(undefined4 *)(puVar14 + 0x70) = 10;
          *(uint *)(puVar14 + 0x6c) = uVar19;
          local_e0 = 4;
          local_d0 = 4;
          *(dword *)(puVar14 + 100) = 0x13000;
          local_c0 = 4;
          local_b0 = 10;
          local_a0 = 4;
          local_90 = 4;
          *(int *)(puVar14 + 0x5c) = iVar7;
          local_80 = 4;
          if (pcVar15 == (char *)0x0) {
            pcVar15 = "";
            local_70 = 1;
          }
          else {
            do {
              lVar13 = lVar13 + 1;
            } while (pcVar15[lVar13] != '\0');
            local_70 = (int)lVar13 + 1;
          }
          *(undefined4 *)(puVar14 + 0x58) = *(undefined4 *)(puVar14 + 0x7c);
          local_68 = puVar14 + 0x58;
          *(undefined4 *)(puVar14 + 0x54) = param_5;
          local_58 = puVar14 + 0x54;
          *(undefined1 **)(puVar14 + 0x28) = local_118;
          *(undefined4 *)(puVar14 + 0x20) = 0xd;
          local_6c = 0;
          local_60 = 4;
          local_50 = 4;
          *(undefined8 *)(puVar14 + -8) = 0x1c00034a3;
          local_78 = pcVar15;
          _tlgWriteTransfer_EtwWriteTransfer
                    (0x1c000a040,&DAT_1c0006027,uVar17,uVar16,*(undefined4 *)(puVar14 + 0x20),
                     *(undefined8 **)(puVar14 + 0x28));
        }
      }
      if (iVar7 != 0) goto LAB_1c00034fc;
      *(undefined8 *)(puVar14 + -8) = 0x1c00034b5;
      uVar3 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
      puVar9 = g_MicrosoftTelemetryAssertsTriggeredList;
      if ((ulonglong **)g_MicrosoftTelemetryAssertsTriggeredList !=
          &g_MicrosoftTelemetryAssertsTriggeredList) {
        do {
          if (puVar9[-4] == param_1) {
            *(int *)(puVar9 + -1) = (int)puVar9[-1] + 1;
            break;
          }
          puVar9 = (ulonglong *)*puVar9;
        } while ((ulonglong **)puVar9 != &g_MicrosoftTelemetryAssertsTriggeredList);
      }
    }
  }
  *(undefined8 *)(puVar14 + -8) = 0x1c00034f7;
  KeReleaseSpinLock(&g_AssertSpinLock,uVar3);
LAB_1c00034fc:
  *(undefined8 *)(puVar14 + -8) = 0x1c0003508;
  return;
}



===== _guard_check_icall @ 1c0003540 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0003558 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000357c =====

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



===== __cpu_features_init @ 1c00035f0 =====

/* WARNING: Removing unreachable block (ram,0x0001c000365a) */
/* WARNING: Removing unreachable block (ram,0x0001c0003609) */
/* WARNING: Removing unreachable block (ram,0x0001c00035fa) */

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



===== __security_check_cookie @ 1c00036c0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0003700 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0003730 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0003730. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0003760 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c00037c0 =====

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



===== memset @ 1c0003ac0 =====

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



===== __memset_repmovs @ 1c0003c00 =====

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



===== __memset_query @ 1c0003c80 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0003d00 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0003e40 =====

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



===== __memset_spec_plain @ 1c0003ec0 =====

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



===== IntelPmtpEvtDeviceAdd @ 1c000b010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int IntelPmtpEvtDeviceAdd(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined2 uVar4;
  undefined8 local_res10;
  undefined8 local_res18 [2];
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined *local_118;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined1 local_fb;
  code *local_d8;
  undefined4 local_a8;
  undefined4 local_a4;
  code *local_80;
  code *local_78;
  
  local_res18[0] = 0;
  local_118 = (undefined *)((ulonglong)local_118 & 0xffffffff00000000);
  local_a4 = 0;
  local_148 = 0;
  uStack_140 = 0;
  local_138 = 0;
  uStack_130 = 0;
  local_128 = 0;
  uStack_120 = 0;
  local_res10 = param_2;
  memset(&local_a8,0,0x8c);
  memset(&local_108,0,0x60);
  puVar3 = (undefined8 *)&IntelPmtpNtDeviceName;
  iVar1 = (**(code **)(WdfFunctions_01023 + 0x218))(WdfDriverGlobals,param_2);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar4 = 0xb;
  }
  else {
    puVar3 = (undefined8 *)&SDDL_DEVOBJ_KERNEL_ONLY;
    iVar1 = (**(code **)(WdfFunctions_01023 + 0x220))(WdfDriverGlobals);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      uVar4 = 0xc;
    }
    else {
      memset(&local_a8,0,0x90);
      local_80 = IntelPmtpEvtDevicePrepareHardware;
      local_78 = IntelPmtpEvtDeviceReleaseHardware;
      local_a8 = 0x90;
      (**(code **)(WdfFunctions_01023 + 0x1b8))(WdfDriverGlobals,local_res10,&local_a8);
      puVar3 = &local_148;
      local_118 = PTR__WDF_INTELPMTP_DEVICE_EXTENSION_TYPE_INFO_1c0007018;
      local_138 = 0;
      uStack_140 = 0;
      local_148 = 0x38;
      local_128 = 0;
      uStack_120 = 0;
      uStack_130 = 0x200000001;
      iVar1 = (**(code **)(WdfFunctions_01023 + 600))
                        (WdfDriverGlobals,&local_res10,puVar3,local_res18);
      if (iVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar1;
        }
        uVar4 = 0xd;
      }
      else {
        (**(code **)(WdfFunctions_01023 + 0x260))(WdfDriverGlobals,local_res18[0],0);
        puVar2 = (undefined8 *)
                 (**(code **)(WdfFunctions_01023 + 0x650))
                           (WdfDriverGlobals,local_res18[0],
                            PTR__WDF_INTELPMTP_DEVICE_EXTENSION_TYPE_INFO_1c0007018);
        memset(puVar2,0,0x78);
        *puVar2 = local_res18[0];
        puVar3 = (undefined8 *)&local_108;
        puVar2 = puVar2 + 1;
        local_d8 = IntelPmtpEvtDeviceIoControl;
        local_108 = 0x60;
        local_100 = 2;
        local_fb = 1;
        local_104 = 1;
        iVar1 = (**(code **)(WdfFunctions_01023 + 0x4c0))
                          (WdfDriverGlobals,local_res18[0],puVar3,0,puVar2);
        if (iVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return iVar1;
          }
          uVar4 = 0xe;
        }
        else {
          puVar3 = (undefined8 *)&GUID_INTEL_PLATFORM_MONITORING_INTERFACE;
          iVar1 = (**(code **)(WdfFunctions_01023 + 0x268))
                            (WdfDriverGlobals,local_res18[0],
                             &GUID_INTEL_PLATFORM_MONITORING_INTERFACE,0);
          if (-1 < iVar1) {
            puVar3 = (undefined8 *)&GUID_INTEL_PLATFORM_MONITORING_INTERFACE;
            (**(code **)(WdfFunctions_01023 + 0x270))
                      (WdfDriverGlobals,local_res18[0],&GUID_INTEL_PLATFORM_MONITORING_INTERFACE,0,
                       (ulonglong)puVar2 & 0xffffffffffffff00);
            iVar1 = 0;
            goto LAB_1c000b345;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return iVar1;
          }
          uVar4 = 0xf;
        }
      }
    }
  }
  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar3,uVar4,
                    &WPP_f84f8971834f360366e1ee7734d3dbd7_Traceguids,(char)iVar1);
LAB_1c000b345:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar3,0x10,
                      &WPP_f84f8971834f360366e1ee7734d3dbd7_Traceguids,(char)iVar1);
  }
  return iVar1;
}



===== IntelPmtpEvtDevicePrepareHardware @ 1c000b390 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint IntelPmtpEvtDevicePrepareHardware(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  char *pcVar5;
  ulonglong uVar6;
  undefined1 auStackY_168 [32];
  uint local_138;
  undefined4 local_134;
  undefined8 local_130;
  ushort *puStack_128;
  undefined8 *local_120;
  undefined8 uStack_118;
  code *local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  ushort local_f8 [56];
  undefined8 local_88 [4];
  uint *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_168;
  memset(local_f8,0,0x68);
  local_110 = (code *)0x0;
  uStack_108 = (ulonglong)uStack_108._4_4_ << 0x20;
  local_130 = 0;
  puStack_128 = (ushort *)0x0;
  local_120 = (undefined8 *)0x0;
  uStack_118 = 0;
  pcVar5 = PTR__WDF_INTELPMTP_DEVICE_EXTENSION_TYPE_INFO_1c0007018;
  piVar3 = (int *)(**(code **)(WdfFunctions_01023 + 0x650))(WdfDriverGlobals,param_1);
  uVar2 = (**(code **)(WdfFunctions_01023 + 0x980))(WdfDriverGlobals,param_3);
  piVar3[6] = 0;
  uVar4 = 0;
  if (uVar2 != 0) {
    do {
      pcVar5 = (char *)(**(code **)(WdfFunctions_01023 + 0x988))(WdfDriverGlobals,param_3,uVar4);
      if (pcVar5 == (char *)0x0) goto LAB_1c000b615;
      if (*pcVar5 == '\x03') {
        uVar1 = piVar3[6];
        uVar6 = (ulonglong)uVar1;
        *(undefined8 *)(piVar3 + uVar6 * 2 + 8) = *(undefined8 *)(pcVar5 + 4);
        piVar3[uVar6 + 0x14] = *(int *)(pcVar5 + 0xc);
        piVar3[6] = piVar3[6] + 1;
        if ((IntelPmtpDiagTraceHandleInitialized != '\0') && (5 < DAT_1c0007028)) {
          local_5c = 0;
          local_68 = &local_138;
          local_4c = 0;
          local_3c = 0;
          local_100 = *(undefined8 *)(pcVar5 + 4);
          local_58 = &local_100;
          local_134 = *(undefined4 *)(pcVar5 + 0xc);
          local_48 = &local_134;
          local_60 = 4;
          local_50 = 8;
          local_40 = 4;
          local_138 = uVar1;
          _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005a56,pcVar5,uVar6,5,local_88);
        }
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar2);
  }
  if (((piVar3[6] == 0) || (*(longlong *)(piVar3 + 8) == 0)) || (piVar3[0x14] == 0)) {
LAB_1c000b615:
    uVar2 = 0xc0000182;
  }
  else {
    uVar2 = IntelPmtpPciQueryDiscoveryTables(piVar3);
    if (-1 < (int)uVar2) {
      if (IntelPmtpSamplerInitFailed == '\0') {
        local_f8[0] = 0x68;
        puStack_128 = local_f8;
        local_130 = 0x30;
        uStack_118 = 0;
        local_120 = &GUID_INTEL_PMT_SAMPLER_INTERFACE;
        local_110 = IntelPmtSamplerEvtProcessQueryInterfaceRequest;
        uStack_108 = 1;
        uVar2 = (**(code **)(WdfFunctions_01023 + 0x720))
                          (WdfDriverGlobals,*(undefined8 *)piVar3,&local_130);
        if ((int)uVar2 < 0) {
          pcVar5 = (char *)(ulonglong)uVar2;
          MicrosoftTelemetryAssertTriggeredArgsMsgKM
                    ("IntelPmtpEvtDevicePrepareHardware",(uint)local_f8[0],uVar2,
                     "Failed to add sampler PNP interface: 0x%08X.");
          goto LAB_1c000b61a;
        }
      }
      pcVar5 = &GUID_INTEL_PLATFORM_MONITORING_INTERFACE;
      (**(code **)(WdfFunctions_01023 + 0x270))
                (WdfDriverGlobals,param_1,&GUID_INTEL_PLATFORM_MONITORING_INTERFACE,0);
      uVar2 = 0;
    }
  }
LAB_1c000b61a:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,pcVar5,0x13,
                      &WPP_f84f8971834f360366e1ee7734d3dbd7_Traceguids,(char)uVar2);
  }
  return uVar2;
}



===== IntelPmtpEvtDeviceReleaseHardware @ 1c000b680 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void IntelPmtpEvtDeviceReleaseHardware
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined *puVar3;
  char *pcVar4;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  if ((IntelPmtpDiagTraceHandleInitialized != '\0') && (5 < DAT_1c0007028)) {
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005a90,param_3,param_4,2,local_38);
  }
  lVar1 = (**(code **)(WdfFunctions_01023 + 0x650))
                    (WdfDriverGlobals,param_1,
                     PTR__WDF_INTELPMTP_DEVICE_EXTENSION_TYPE_INFO_1c0007018);
  puVar3 = &GUID_INTEL_PLATFORM_MONITORING_INTERFACE;
  pcVar4 = (char *)0x0;
  uVar2 = WdfDriverGlobals;
  (**(code **)(WdfFunctions_01023 + 0x270))();
  IntelPmtpSamplerUninit(uVar2,param_1,(ulonglong)puVar3,pcVar4);
  if (*(longlong *)(lVar1 + 0x68) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x68),0x544d505f);
    *(undefined8 *)(lVar1 + 0x68) = 0;
  }
  *(undefined4 *)(lVar1 + 0x18) = 0;
  *(undefined8 *)(lVar1 + 0x20) = 0;
  *(undefined8 *)(lVar1 + 0x28) = 0;
  *(undefined8 *)(lVar1 + 0x30) = 0;
  *(undefined8 *)(lVar1 + 0x38) = 0;
  *(undefined8 *)(lVar1 + 0x40) = 0;
  *(undefined8 *)(lVar1 + 0x48) = 0;
  *(undefined8 *)(lVar1 + 0x50) = 0;
  *(undefined8 *)(lVar1 + 0x58) = 0;
  *(undefined8 *)(lVar1 + 0x60) = 0;
  return;
}



===== IntelPmtpEvtDriverUnload @ 1c000b790 =====

void IntelPmtpEvtDriverUnload(void)

{
  undefined8 uVar1;
  
  uVar1 = DAT_1c0007048;
  if (IntelPmtpDiagTraceHandleInitialized != '\0') {
    DAT_1c0007048 = 0;
    IntelPmtpDiagTraceHandleInitialized = '\0';
    DAT_1c0007028 = 0;
    EtwUnregister(uVar1);
  }
  return;
}



===== TraceLoggingRegister_EtwRegister_EtwSetInformation @ 1c000b7d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int TraceLoggingRegister_EtwRegister_EtwSetInformation(void)

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
  
  puVar4 = auStack_48;
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = *(undefined4 *)(PTR_DAT_1c0007030 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_1c0007030 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_1c0007030 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_1c0007030 + -4);
  if (DAT_1c0007048 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  _DAT_1c0007050 = 0;
  uRam00000001c0007058 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x1c000b833;
  iVar3 = EtwRegister(puVar4 + 0x20,_tlgEnableCallback,&DAT_1c0007028,&DAT_1c0007048);
  if (iVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_1c0007030;
    *(undefined8 *)(puVar4 + -8) = 0x1c000b85a;
    EtwSetInformation(DAT_1c0007048,2,PTR_DAT_1c0007030,uVar1);
  }
  *(undefined8 *)(puVar4 + -8) = 0x1c000b86e;
  return iVar3;
}



===== WppCleanupKm @ 1c000b87c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppCleanupKm(undefined8 param_1)

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
    WppAutoLogStop(WPP_GLOBAL_Control,param_1);
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
    WPP_RECORDER_INITIALIZED = (undefined *)&WPP_RECORDER_INITIALIZED;
  }
  return;
}



===== WppInitKm @ 1c000b92c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined *puVar2;
  
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if (WPPTraceSuite == 4) {
      puVar2 = &WPP_MAIN_CB;
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
    WppAutoLogStart(WPP_GLOBAL_Control,param_1,param_2);
    WPP_RECORDER_INITIALIZED = &WPP_MAIN_CB;
  }
  return;
}



===== WppLoadTracingSupport @ 1c000ba08 =====

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



===== WppTraceCallback @ 1c000bb50 =====

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
        memcpy((ushort *)((ulonglong)uVar11 + (longlong)param_4) + 1,*(void **)(puVar3 + 4),
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



===== _tlgEnableCallback @ 1c000bde0 =====

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



===== wil_details_EvaluateFeatureDependencies @ 1c000be5c =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar4 = (undefined *)0x0;
  ppuVar3 = &Feature_SamplerSupportADLN__private_descriptor;
  ppuVar2 = &Feature_SamplerSupportADLN__private_descriptor;
  do {
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x0001c000be97;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_1c000bf11:
  while( true ) {
    if (&UNK_1c0006bdf < ppuVar3) {
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
      if (&UNK_1c0006bdf < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x0001c000be97:
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
      if (&UNK_1c0006bdf < ppuVar2) goto LAB_1c000bf11;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_1c000bf11;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1c000bf4c =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_1c000bfe4;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_1c000bfe4;
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
LAB_1c000bfe4:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 1c000c030 =====

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
      for (ppuVar2 = &Feature_SamplerSupportADLN__private_descriptor;
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
              if (&UNK_1c0006bdf < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 1c000c0b0 =====

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
  for (ppuVar3 = &Feature_SamplerSupportADLN__private_descriptor;
      ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
    if (*ppuVar3 != (undefined *)0x0) goto LAB_1c000c1ad;
  }
LAB_1c000c1b6:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_1c000c1ad:
  if (ppuVar3 == (undefined **)0x0) goto LAB_1c000c1b6;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_1c000c17e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_1c000c17e;
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
    if (&UNK_1c0006bdf < ppuVar3) goto LAB_1c000c1b6;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1c000c1ad;
}



===== IntelPmtpPciParseExtendedCapability @ 1c000c1dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int IntelPmtpPciParseExtendedCapability(longlong param_1,short *param_2,uint param_3,int *param_4)

{
  int iVar1;
  undefined8 *puVar2;
  uint *puVar3;
  undefined1 auStackY_168 [32];
  uint local_138;
  uint local_134;
  uint local_130;
  uint local_12c;
  uint local_128;
  uint local_124;
  uint local_120;
  uint local_11c;
  uint local_118;
  uint local_114;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8 [4];
  uint *local_d8;
  undefined8 local_d0;
  uint *local_c8;
  undefined8 local_c0;
  uint *local_b8;
  undefined8 local_b0;
  uint *local_a8;
  undefined8 local_a0;
  uint *local_98;
  undefined8 local_90;
  uint *local_88;
  undefined8 local_80;
  uint *local_78;
  undefined8 local_70;
  uint *local_68;
  undefined8 local_60;
  uint *local_58;
  undefined8 local_50;
  uint *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_168;
  puVar3 = (uint *)(ulonglong)param_3;
  local_110 = 0;
  local_108 = 0;
  uStack_100 = 0;
  if (*param_2 == 0x23) {
    iVar1 = (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 8),0,&local_110,param_3);
    if (iVar1 != 8) {
      return -0x3fffff45;
    }
    if (local_110._4_2_ == -0x7f7a) {
      puVar2 = &local_108;
      iVar1 = (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 8),0);
      if (iVar1 != 0x10) {
        return -0x3fffff45;
      }
      if ((IntelPmtpDiagTraceHandleInitialized != '\0') && (5 < DAT_1c0007028)) {
        local_138 = (uint)(ushort)local_108;
        local_d8 = &local_138;
        local_134 = local_108._2_2_ & 0xf;
        local_d0 = 4;
        local_c8 = &local_134;
        local_130 = (uint)local_108._4_2_;
        local_b8 = &local_130;
        local_12c = local_108._6_2_ & 0xf;
        local_a8 = &local_12c;
        local_98 = &local_128;
        local_128 = (uint)(local_108._6_2_ >> 4);
        local_124 = (uint)uStack_100 & 0xffff;
        local_88 = &local_124;
        local_120 = (uint)uStack_100 >> 0x10 & 0xff;
        local_78 = &local_120;
        local_68 = &local_11c;
        local_11c = (uint)uStack_100 >> 0x18;
        local_118 = uStack_100._4_4_ & 7;
        local_114 = uStack_100._4_4_ >> 3;
        local_58 = &local_118;
        local_48 = &local_114;
        local_c0 = 4;
        local_b0 = 4;
        local_a0 = 4;
        local_90 = 4;
        local_80 = 4;
        local_70 = 4;
        local_60 = 4;
        local_50 = 4;
        local_40 = 4;
        _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005b78,puVar2,puVar3,0xc,local_f8);
      }
      if ((short)uStack_100 == 2) {
        iVar1 = IntelPmtpPciParseTelemetrySpaceCapability((longlong)&local_108,(longlong)param_4);
        return iVar1;
      }
      if ((short)uStack_100 == 3) {
        iVar1 = IntelPmtpPciParseWatcherSpaceCapability((longlong)&local_108,param_4,puVar2,puVar3);
        if (-1 < iVar1) {
          return iVar1;
        }
        IntelPmtpSamplerInitFailed = 1;
        MicrosoftTelemetryAssertTriggeredArgsMsgKM
                  ("IntelPmtpPciParseExtendedCapability",iVar1,(uint)uStack_100 >> 0x10 & 0xff,
                   "Failed to initialized sampler");
      }
    }
  }
  return 0;
}



===== IntelPmtpPciParseTelemetrySpaceCapability @ 1c000c450 =====

int IntelPmtpPciParseTelemetrySpaceCapability(longlong param_1,longlong param_2)

{
  uint *puVar1;
  byte bVar2;
  longlong lVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  longlong lVar7;
  uint *puVar8;
  uint uVar9;
  uint *puVar10;
  ulonglong uVar11;
  
  bVar2 = *(byte *)(param_1 + 10);
  uVar11 = (ulonglong)bVar2;
  uVar5 = *(uint *)(param_1 + 0xc) & 7;
  if ((uVar5 < 2) && (uVar5 < *(uint *)(param_2 + 0x18))) {
    lVar7 = MmMapIoSpaceEx((ulonglong)(*(uint *)(param_1 + 0xc) >> 3) +
                           *(longlong *)(param_2 + 0x20 + (ulonglong)uVar5 * 8),
                           (ulonglong)bVar2 << 4);
    if (lVar7 == 0) {
      iVar6 = -0x3fffff66;
    }
    else {
      puVar8 = (uint *)ExAllocatePool2(0x100,(uint)bVar2 * 0x20 + 0x10,0x544d505f);
      if (puVar8 == (uint *)0x0) {
        iVar6 = -0x3fffff66;
      }
      else {
        *(undefined2 *)puVar8 = 0;
        puVar8[2] = (uint)bVar2;
        if (bVar2 != 0) {
          puVar10 = (uint *)(lVar7 + 0xc);
          puVar4 = puVar8;
          do {
            puVar4[4] = 1;
            puVar4[5] = puVar10[-3] >> 4 & 0xf;
            uVar9 = puVar10[-3] >> 0xc & 0xffff;
            puVar4[8] = uVar9;
            if (*(uint *)(param_2 + 0x70) < uVar9) {
              *(uint *)(param_2 + 0x70) = uVar9;
            }
            puVar4[9] = puVar10[-2];
            puVar4[10] = *puVar10;
            lVar3 = *(longlong *)(param_2 + 0x20 + (ulonglong)uVar5 * 8);
            *(longlong *)(puVar4 + 6) = lVar3;
            puVar1 = puVar10 + -1;
            puVar10 = puVar10 + 4;
            *(ulonglong *)(puVar4 + 6) = (ulonglong)*puVar1 + lVar3;
            uVar11 = uVar11 - 1;
            puVar4 = puVar4 + 8;
          } while (uVar11 != 0);
        }
        *(uint **)(param_2 + 0x68) = puVar8;
        iVar6 = IntelPmtpSamplerInitInstances(param_2);
        if (iVar6 == -0x3fffff5d) {
          iVar6 = 0;
        }
      }
      MmUnmapIoSpace(lVar7,(ulonglong)bVar2 << 4);
    }
  }
  else {
    iVar6 = -0x3fffff45;
  }
  return iVar6;
}



===== IntelPmtpPciParseWatcherSpaceCapability @ 1c000c5b4 =====

int IntelPmtpPciParseWatcherSpaceCapability
              (longlong param_1,int *param_2,undefined8 param_3,uint *param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  longlong *plVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  ulonglong uVar9;
  
  bVar1 = *(byte *)(param_1 + 10);
  uVar9 = (ulonglong)bVar1;
  uVar2 = *(uint *)(param_1 + 0xc) & 7;
  if ((uVar2 < 2) && (uVar2 < (uint)param_2[6])) {
    puVar4 = (uint *)MmMapIoSpaceEx((ulonglong)(*(uint *)(param_1 + 0xc) >> 3) +
                                    *(longlong *)(param_2 + (ulonglong)uVar2 * 2 + 8),
                                    (ulonglong)bVar1 << 4);
    if (puVar4 == (uint *)0x0) {
      iVar3 = -0x3fffff66;
    }
    else {
      puVar7 = (uint *)0x544d505f;
      plVar5 = (longlong *)ExAllocatePool2(0x100,(uint)bVar1 * 0x20 + 0xc);
      if (plVar5 == (longlong *)0x0) {
        iVar3 = -0x3fffff66;
      }
      else {
        *(uint *)(plVar5 + 1) = (uint)bVar1;
        *plVar5 = *(longlong *)(param_2 + (ulonglong)uVar2 * 2 + 8);
        if (bVar1 != 0) {
          puVar6 = (uint *)((longlong)plVar5 + 0x14);
          puVar8 = puVar4;
          do {
            puVar6[-2] = 1;
            puVar6[-1] = *puVar8 & 0xf;
            *puVar6 = *puVar8 >> 4 & 0xf;
            puVar6[1] = *puVar8 >> 0xc & 0xffff;
            puVar6[3] = *puVar8 >> 0x1d & 1;
            puVar7 = puVar8 + 4;
            puVar6[2] = *puVar8 >> 0x1c & 1;
            puVar6[4] = puVar8[1];
            puVar6[5] = puVar8[2];
            uVar9 = uVar9 - 1;
            param_4 = (uint *)0x0;
            puVar6 = puVar6 + 8;
            puVar8 = puVar7;
          } while (uVar9 != 0);
        }
        iVar3 = IntelPmtpSamplerInit(plVar5,param_2,(ulonglong)puVar7,param_4);
        ExFreePoolWithTag(plVar5,0x544d505f);
      }
      MmUnmapIoSpace(puVar4,(ulonglong)bVar1 << 4);
    }
  }
  else {
    iVar3 = -0x3fffff45;
  }
  return iVar3;
}



===== IntelPmtpPciQueryDiscoveryTables @ 1c000c728 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int IntelPmtpPciQueryDiscoveryTables(int *param_1)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined *puVar5;
  int *piVar6;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined1 local_48 [8];
  undefined8 local_40;
  code *local_30;
  
  memset(local_48,0,0x40);
  local_58 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  uVar3 = (**(code **)(WdfFunctions_01023 + 0xf8))(WdfDriverGlobals,*(undefined8 *)param_1);
  lVar4 = IoGetAttachedDeviceReference(uVar3);
  KeInitializeEvent(&local_68,0,0);
  piVar6 = (int *)0x0;
  puVar5 = (undefined *)IoBuildSynchronousFsdRequest(0x1b,lVar4,0,0,0,&local_68,&local_78);
  if (puVar5 == (undefined *)0x0) {
    iVar2 = -0x3fffff66;
  }
  else {
    lVar1 = *(longlong *)(puVar5 + 0xb8);
    *(undefined **)(lVar1 + -0x40) = &GUID_BUS_INTERFACE_STANDARD;
    *(undefined1 **)(lVar1 + -0x30) = local_48;
    *(undefined1 *)(lVar1 + -0x47) = 8;
    *(undefined4 *)(lVar1 + -0x38) = 0x10040;
    *(undefined4 *)(puVar5 + 0x30) = 0xc00000bb;
    iVar2 = IofCallDriver(lVar4);
    if (iVar2 == 0x103) {
      piVar6 = (int *)0x0;
      puVar5 = (undefined *)0x0;
      KeWaitForSingleObject(&local_68,0,0,0,0);
      iVar2 = (int)local_78;
    }
  }
  if (lVar4 != 0) {
    ObfDereferenceObject(lVar4);
  }
  if (-1 < iVar2) {
    iVar2 = IntelPmtpPciWalkExtendedCapabilities((longlong)local_48,puVar5,param_1,piVar6);
    (*local_30)(local_40);
  }
  return iVar2;
}



===== IntelPmtpPciWalkCapabilities @ 1c000c8a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
IntelPmtpPciWalkCapabilities
          (longlong param_1,undefined8 param_2,undefined1 *param_3,undefined8 param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined2 *puVar5;
  ulonglong uVar6;
  undefined1 auStackY_d8 [32];
  undefined2 local_a8;
  undefined1 local_a4 [4];
  undefined4 local_a0 [2];
  undefined2 local_98 [3];
  byte local_92;
  byte local_64;
  undefined8 local_58 [4];
  undefined4 *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_a8 = 0;
  uVar4 = 0x40;
  memset(local_98,0,0x40);
  if ((IntelPmtpDiagTraceHandleInitialized != '\0') && (5 < DAT_1c0007028)) {
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005ae6,uVar4,param_4,2,local_58);
  }
  puVar5 = local_98;
  uVar6 = 0;
  iVar1 = (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 8),0);
  if (((iVar1 == 0x40) && ((local_92 & 0x10) != 0)) && (local_64 != 0)) {
    uVar2 = (uint)local_64;
    do {
      if (((uVar2 & 3) != 0) || (0xfd < uVar2)) goto LAB_1c000c93e;
      puVar5 = &local_a8;
      uVar6 = (ulonglong)uVar2;
      iVar1 = (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 8),0);
      if (iVar1 != 2) goto LAB_1c000c93e;
      if ((IntelPmtpDiagTraceHandleInitialized != '\0') && (5 < DAT_1c0007028)) {
        local_a4[0] = (char)local_a8;
        local_38 = (undefined4 *)local_a4;
        local_30 = 1;
        _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005c0d,puVar5,uVar6,3,local_58);
      }
      uVar2 = (uint)local_a8._1_1_;
      if ((char)local_a8 == '\x10') {
        *param_3 = 1;
      }
    } while (uVar2 != 0);
    uVar3 = 0;
  }
  else {
LAB_1c000c93e:
    uVar3 = 0xc00000bb;
  }
  if ((IntelPmtpDiagTraceHandleInitialized != '\0') && (5 < DAT_1c0007028)) {
    local_38 = local_a0;
    local_30 = 4;
    local_a0[0] = uVar3;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005ab6,puVar5,uVar6,3,local_58);
  }
  return uVar3;
}



===== IntelPmtpPciWalkExtendedCapabilities @ 1c000ca5c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int IntelPmtpPciWalkExtendedCapabilities
              (longlong param_1,undefined *param_2,int *param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  undefined1 auStackY_98 [32];
  char local_68 [4];
  uint local_64;
  int local_60 [2];
  undefined8 local_58 [4];
  int *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_98;
  local_64 = 0;
  if ((IntelPmtpDiagTraceHandleInitialized != '\0') && (5 < DAT_1c0007028)) {
    param_2 = &DAT_1c0005b47;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005b47,param_3,param_4,2,local_58);
  }
  puVar4 = (uint *)local_68;
  local_68[0] = '\0';
  iVar2 = IntelPmtpPciWalkCapabilities(param_1,param_2,(undefined1 *)puVar4,param_4);
  if (-1 < iVar2) {
    if (local_68[0] == '\0') {
LAB_1c000cb3a:
      iVar2 = -0x3fffff45;
    }
    else {
      uVar3 = 0x100;
      do {
        if (((uVar3 & 3) != 0) || (uVar3 < 0x100)) goto LAB_1c000cb3a;
        puVar4 = &local_64;
        param_4 = (int *)(ulonglong)uVar3;
        iVar2 = (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 8),0);
        if (iVar2 != 4) goto LAB_1c000cb3a;
        uVar1 = local_64 >> 0x14;
        puVar4 = (uint *)(ulonglong)uVar3;
        param_4 = param_3;
        iVar2 = IntelPmtpPciParseExtendedCapability(param_1,(short *)&local_64,uVar3,param_3);
        if (iVar2 < 0) goto LAB_1c000cb3f;
        uVar3 = uVar1;
      } while (uVar1 != 0);
      iVar2 = 0;
    }
  }
LAB_1c000cb3f:
  if ((IntelPmtpDiagTraceHandleInitialized != '\0') && (5 < DAT_1c0007028)) {
    local_2c = 0;
    local_38 = local_60;
    local_30 = 4;
    local_60[0] = iVar2;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005b0f,puVar4,param_4,3,local_58);
  }
  return iVar2;
}



===== IntelPmtpSamplerAcquireLock @ 1c000cbb8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IntelPmtpSamplerAcquireLock(undefined8 *param_1)

{
  (**(code **)(WdfFunctions_01023 + 0x9c8))(WdfDriverGlobals,*param_1,0);
  param_1[1] = SystemReserved1[0xf];
  return;
}



===== IntelPmtpSamplerArmSamplingTimer @ 1c000cbfc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
IntelPmtpSamplerArmSamplingTimer
          (ulonglong param_1,ulonglong param_2,longlong param_3,undefined8 *param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 auStackY_d8 [32];
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90 [2];
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78 [4];
  undefined4 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_d8;
  uVar4 = 0xffffffff;
  local_88 = 0;
  uStack_80 = 0;
  uVar2 = param_2;
  if (param_1 == 0) {
    uVar3 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000ccfa;
    param_4 = (undefined8 *)0x27;
  }
  else {
    if (*(char *)(param_1 + 0x7c) == '\0') {
      uVar4 = *(undefined4 *)(param_1 + 0x10);
      lVar1 = *(longlong *)(param_1 + 0x80);
      if (lVar1 == 0) {
        param_3 = 8;
        uVar2 = param_1;
        lVar1 = ExAllocateTimer(IntelPmtpSamplingTimerCallback);
        if (lVar1 == 0) {
          uVar3 = 0xc000009a;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c000ccfa;
          param_4 = (undefined8 *)0x29;
          goto LAB_1c000cc55;
        }
        *(longlong *)(param_1 + 0x80) = lVar1;
      }
      uStack_80 = 0xffffffffffffffff;
      param_4 = &local_88;
      param_3 = (param_2 & 0xffffffff) * 10000;
      ExSetTimer(lVar1,(param_2 & 0xffffffff) * -10000);
      *(undefined1 *)(param_1 + 0x7c) = 1;
      uVar3 = 0;
      goto LAB_1c000ccfa;
    }
    uVar3 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000ccfa;
    param_4 = (undefined8 *)0x28;
  }
LAB_1c000cc55:
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,param_3,(short)param_4);
LAB_1c000ccfa:
  if ((IntelPmtpDiagTraceHandleInitialized != '\0') && (5 < DAT_1c0007028)) {
    local_4c = 0;
    local_58 = &local_98;
    local_3c = 0;
    local_2c = 0;
    local_48 = &local_94;
    local_38 = local_90;
    local_50 = 4;
    local_40 = 4;
    local_30 = 4;
    local_98 = uVar3;
    local_94 = uVar4;
    local_90[0] = (int)param_2;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005db7,param_3,param_4,5,local_78);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_Ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return uVar3;
}



===== IntelPmtpSamplerDisarmSamplingTimer @ 1c000cdc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
IntelPmtpSamplerDisarmSamplingTimer
          (longlong param_1,undefined *param_2,undefined8 param_3,ulonglong param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 auStackY_a8 [32];
  undefined4 in_stack_ffffffffffffff78;
  undefined4 in_stack_ffffffffffffff7c;
  undefined4 local_68;
  undefined4 local_64 [3];
  undefined8 local_58 [4];
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  uVar2 = 0xffffffff;
  if (param_1 == 0) {
    uVar1 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000ce54;
    uVar3 = 0x2b;
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x10);
    if (*(longlong *)(param_1 + 0x80) != 0) {
      if (*(char *)(param_1 + 0x7c) != '\0') {
        param_2 = (undefined *)0x0;
        ExCancelTimer();
        *(undefined1 *)(param_1 + 0x7c) = 0;
      }
      uVar1 = 0;
      goto LAB_1c000ce54;
    }
    uVar1 = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000ce54;
    uVar3 = 0x2c;
  }
  param_4 = (ulonglong)uVar3;
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,(short)uVar3);
LAB_1c000ce54:
  if ((IntelPmtpDiagTraceHandleInitialized != '\0') && (5 < DAT_1c0007028)) {
    local_2c = 0;
    local_38 = &local_68;
    local_1c = 0;
    param_2 = &DAT_1c0005e62;
    local_28 = local_64;
    local_30 = 4;
    in_stack_ffffffffffffff78 = 4;
    local_20 = 4;
    local_68 = uVar1;
    local_64[0] = uVar2;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005e62,param_3,param_4,4,local_58);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x2d,
                       CONCAT44(in_stack_ffffffffffffff7c,in_stack_ffffffffffffff78),(char)uVar1,
                       (char)uVar2);
  }
  return uVar1;
}



===== IntelPmtpSamplerInit @ 1c000cf18 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int IntelPmtpSamplerInit(longlong *param_1,int *param_2,ulonglong param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined1 auStackY_d8 [32];
  undefined4 in_stack_ffffffffffffff48;
  undefined4 in_stack_ffffffffffffff4c;
  int local_98;
  uint local_94;
  uint local_90 [2];
  undefined8 local_88 [4];
  int *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  uint *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  uint *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_d8;
  uVar1 = *(uint *)(param_1 + 1);
  uVar6 = 0;
  piVar4 = param_2;
  if (uVar1 != 0) {
    piVar4 = (int *)((longlong)param_1 + 0x14);
    uVar9 = (ulonglong)uVar1;
    do {
      uVar8 = uVar9;
      iVar2 = *piVar4;
      piVar4 = piVar4 + 8;
      uVar5 = uVar6 + 1;
      if (iVar2 != 1) {
        uVar5 = uVar6;
      }
      uVar6 = uVar5;
      uVar9 = uVar8 - 1;
    } while (uVar9 != 0);
    param_3 = 0;
    if (uVar6 != 0) {
      param_3 = 0x544d505f;
      puVar3 = (uint *)ExAllocatePool2((int)uVar8 + 0x3f);
      if (puVar3 == (uint *)0x0) {
        iVar2 = -0x3fffff66;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          param_4 = (uint *)&DAT_0000000b;
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_3,0xb,
                            CONCAT44(in_stack_ffffffffffffff4c,in_stack_ffffffffffffff48),
                            (char)uVar6 * -0x60 + '\x10');
        }
      }
      else {
        uVar5 = 0;
        *puVar3 = uVar6;
        param_3 = 0;
        if (uVar6 != 0) {
          param_4 = puVar3 + 0xc;
          do {
            param_4[-4] = (uint)param_3;
            if (uVar5 < uVar1) {
              piVar4 = (int *)((ulonglong)uVar5 * 0x20 + 0x14 + (longlong)param_1);
              do {
                if (*piVar4 == 1) goto LAB_1c000d0e0;
                uVar5 = uVar5 + 1;
                piVar4 = piVar4 + 8;
              } while (uVar5 < uVar1);
            }
            if (uVar5 == uVar1) {
              iVar2 = -0x3ffffddb;
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                param_4 = (uint *)0xc;
                WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_3,0xc,
                                  CONCAT44(in_stack_ffffffffffffff4c,in_stack_ffffffffffffff48),
                                  (char)param_3);
              }
              ExFreePoolWithTag(puVar3,0x544d505f);
              goto LAB_1c000cfea;
            }
LAB_1c000d0e0:
            uVar7 = (uint)param_3 + 1;
            param_3 = (ulonglong)uVar7;
            *(longlong *)(param_4 + -2) = *param_1;
            uVar9 = (ulonglong)uVar5;
            uVar5 = uVar5 + 1;
            *(ulonglong *)param_4 = (ulonglong)*(uint *)(param_1 + uVar9 * 4 + 5) + *param_1;
            *(ulonglong *)(param_4 + 4) = (ulonglong)*(uint *)(param_1 + uVar9 * 4 + 3) << 2;
            param_4 = param_4 + 0x28;
          } while (uVar7 < uVar6);
        }
        IntelPmtpSamplerTables = puVar3;
        iVar2 = IntelPmtpSamplerInitInstances((longlong)param_2);
        if (iVar2 == -0x3fffff5d) {
          iVar2 = 0;
        }
      }
      goto LAB_1c000cfea;
    }
  }
  iVar2 = -0x3ffffddb;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    param_4 = (uint *)0xa;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),piVar4,param_3,10);
  }
LAB_1c000cfea:
  if ((IntelPmtpDiagTraceHandleInitialized != '\0') && (5 < DAT_1c0007028)) {
    local_5c = 0;
    local_68 = &local_98;
    local_4c = 0;
    local_3c = 0;
    local_58 = &local_94;
    local_48 = local_90;
    local_60 = 4;
    local_50 = 4;
    local_40 = 4;
    local_98 = iVar2;
    local_94 = uVar1;
    local_90[0] = uVar6;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005f29,param_3,param_4,5,local_88);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_ddD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return iVar2;
}



===== IntelPmtpSamplerInitInstances @ 1c000d1bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c000d2a3) */
/* WARNING: Removing unreachable block (ram,0x0001c000d248) */

int IntelPmtpSamplerInitInstances(longlong param_1)

{
  uint uVar1;
  uint *puVar2;
  undefined **ppuVar3;
  bool bVar4;
  int iVar5;
  undefined7 extraout_var;
  ulonglong *puVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  undefined8 uVar10;
  longlong lVar11;
  uint uVar12;
  longlong lVar13;
  undefined **ppuVar14;
  longlong lVar15;
  uint uVar16;
  uint uVar17;
  undefined **ppuVar18;
  char *pcVar19;
  uint uVar20;
  uint uVar21;
  ulonglong uVar22;
  undefined1 auStackY_178 [32];
  undefined4 *in_stack_fffffffffffffea8;
  uint local_128;
  undefined8 local_120;
  uint local_118;
  longlong local_110;
  longlong local_108;
  undefined8 uStack_100;
  undefined4 local_f8 [2];
  int local_f0;
  uint local_ec;
  uint local_e8;
  uint local_e4;
  uint *local_e0;
  uint *local_d8 [2];
  undefined8 local_c8 [4];
  int *local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  uint *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  uint *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  uint *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  longlong *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  uint **local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_178;
  uVar20 = 0;
  local_118 = 0;
  ppuVar18 = &WPP_RECORDER_INITIALIZED;
  uVar16 = 0xffffffff;
  lVar7 = 0;
  uVar17 = 0xffffffff;
  uVar21 = 0xffffffff;
  local_128 = 0xffffffff;
  local_108 = 0;
  uStack_100 = 0;
  iVar5 = -0x3fffff45;
  local_110 = param_1;
  if ((IntelPmtpSamplerTables == (uint *)0x0) || (*(longlong *)(param_1 + 0x68) == 0)) {
    iVar5 = -0x3fffff5d;
    goto LAB_1c000d628;
  }
  puVar2 = (uint *)cpuid_basic_info(0);
  local_108 = (ulonglong)puVar2[1] << 0x20;
  uStack_100 = CONCAT44(puVar2[2],puVar2[3]);
  if (*puVar2 < 4) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,&WPP_RECORDER_INITIALIZED,0xe,
                        in_stack_fffffffffffffea8,(char)*puVar2);
    }
    local_128 = 0xffffffff;
    ppuVar3 = (undefined **)0xffffffff;
LAB_1c000d281:
    ppuVar18 = ppuVar3;
    lVar7 = 0;
    uVar21 = (uint)ppuVar18;
    MicrosoftTelemetryAssertTriggeredArgsMsgKM
              ("IntelPmtpSamplerInitInstances",uVar16,uVar21,
               "The driver is running on an unsupported platform.");
    uVar17 = local_128;
  }
  else {
    puVar2 = (uint *)cpuid_Version_info(1);
    uVar17 = *puVar2;
    local_108 = (ulonglong)puVar2[1] << 0x20;
    uVar16 = uVar17 >> 8 & 0xf;
    uVar21 = uVar17 >> 4 & 0xf;
    uStack_100 = CONCAT44(puVar2[2],puVar2[3]);
    if (uVar16 == 0xf) {
      uVar16 = (uVar17 >> 0x14 & 0xff) + 0xf;
LAB_1c000d2dc:
      uVar17 = uVar17 >> 0xc & 0xf0;
      uVar21 = uVar21 | uVar17;
    }
    else if (uVar16 == 6) goto LAB_1c000d2dc;
    ppuVar18 = (undefined **)(ulonglong)uVar17;
    if (((uint)Feature_SamplerSupportADLN__private_featureState & 0x10) == 0) {
      uVar22 = (ulonglong)((uint)Feature_SamplerSupportADLN__private_featureState | 1);
      local_120 = (ulonglong)((uint)Feature_SamplerSupportADLN__private_featureState | 1);
      ppuVar18 = (undefined **)0x2;
      local_f8[0] = 3;
      bVar4 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar22,local_120,2);
      if (((int)CONCAT71(extraout_var,bVar4) != 0) &&
         (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
        in_stack_fffffffffffffea8 = local_f8;
        ppuVar18 = (undefined **)0x0;
        uVar22 = 0x27a7f21;
        (*g_wil_details_pfnFeatureLoggingHook)
                  (0x27a7f21,&Feature_SamplerSupportADLN_logged_traits,0,1);
      }
      wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath(uVar22,3);
    }
    puVar2 = IntelPmtpSamplerTables;
    ppuVar3 = (undefined **)(ulonglong)uVar21;
    if ((uVar16 == 6) && (uVar21 - 0x8c < 2)) {
      uVar20 = *(int *)(local_110 + 0x70) + 0x7fU >> 7;
      if ((uVar20 != 5) && (uVar20 != 8)) goto LAB_1c000d281;
      IntelPmtpSamplerTables[1] = uVar20;
    }
    else {
      IntelPmtpSamplerTables[1] = 8;
    }
    local_118 = *puVar2;
    puVar2[2] = 0x10;
    uVar1 = puVar2[1];
    local_128 = 0;
    uVar17 = 0;
    if (local_118 != 0) {
      lVar15 = 0;
      do {
        puVar2 = IntelPmtpSamplerTables;
        ppuVar18 = (undefined **)0x4;
        local_e0 = IntelPmtpSamplerTables;
        uVar10 = *(undefined8 *)(lVar15 + 0x40 + (longlong)IntelPmtpSamplerTables);
        puVar6 = (ulonglong *)
                 MmMapIoSpaceEx(*(undefined8 *)(lVar15 + 0x30 + (longlong)IntelPmtpSamplerTables));
        if (puVar6 == (ulonglong *)0x0) {
          iVar5 = -0x3fffff66;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar10,ppuVar18,0x10,
                              in_stack_fffffffffffffea8,
                              (char)*(undefined8 *)(lVar15 + 0x30 + (longlong)local_e0));
          }
          goto LAB_1c000d8d2;
        }
        *(ulonglong **)(lVar15 + 0x38 + (longlong)puVar2) = puVar6;
        local_120._4_4_ = (uint)(*puVar6 >> 0x20);
        lVar13 = (*puVar6 & 0xffffffff) + *(longlong *)(lVar15 + 0x28 + (longlong)puVar2);
        uVar17 = local_120._4_4_ >> 10 & 0xf;
        *(uint *)(lVar15 + 0x24 + (longlong)puVar2) = uVar17;
        if (uVar17 == 0) {
          *(undefined4 *)(lVar15 + 0x24 + (longlong)puVar2) = 1;
          if ((uVar16 != 6) || (1 < uVar21 - 0x8c)) {
            pcVar19 = "Invalid sampler set count readout, 0 is TGL only.";
            uVar17 = 1;
            goto LAB_1c000d47d;
          }
        }
        else if (uVar17 != 5) {
          pcVar19 = "Invalid sampler set count readout.";
LAB_1c000d47d:
          MicrosoftTelemetryAssertTriggeredArgsMsgKM
                    ("IntelPmtpSamplerInitInstances",uVar21,uVar17,pcVar19);
        }
        ppuVar18 = (undefined **)0x544d505f;
        lVar11 = (ulonglong)*(uint *)(lVar15 + 0x24 + (longlong)puVar2) * 0x18;
        lVar7 = ExAllocatePool2(0x40);
        uVar17 = local_128;
        if (lVar7 == 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar11,ppuVar18,0x11);
          }
LAB_1c000d61f:
          iVar5 = -0x3fffff66;
          goto LAB_1c000d628;
        }
        ppuVar18 = (undefined **)0x2;
        lVar8 = (ulonglong)(local_120._4_4_ & 0x3ff) << 2;
        lVar11 = lVar8;
        lVar9 = MmMapIoSpaceEx(lVar13);
        if (lVar9 == 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar11,ppuVar18,0x12,
                              in_stack_fffffffffffffea8,(char)lVar13);
          }
          goto LAB_1c000d61f;
        }
        if (*(int *)(lVar15 + 0x24 + (longlong)puVar2) != 0) {
          lVar13 = lVar9;
          uVar22 = 0;
          do {
            uVar12 = (int)uVar22 + 1;
            *(longlong *)(lVar7 + uVar22 * 0x18) = lVar13;
            *(longlong *)(lVar7 + 8 + uVar22 * 0x18) = lVar13 + 8;
            lVar13 = lVar13 + 8 + (ulonglong)uVar1 * 8;
            *(longlong *)(lVar7 + 0x10 + uVar22 * 0x18) = lVar13;
            lVar13 = lVar13 + 0x80;
            uVar22 = (ulonglong)uVar12;
          } while (uVar12 < *(uint *)(lVar15 + 0x24 + (longlong)puVar2));
        }
        *(longlong *)(lVar15 + 0x58 + (longlong)puVar2) = lVar8;
        ppuVar14 = (undefined **)((longlong)puVar2 + lVar15 + 0x10);
        *(longlong *)(lVar15 + 0x50 + (longlong)puVar2) = lVar7;
        *(longlong *)(lVar15 + 0x48 + (longlong)puVar2) = lVar9;
        ppuVar18 = ppuVar14;
        iVar5 = (**(code **)(WdfFunctions_01023 + 0x9c0))(WdfDriverGlobals,0);
        if (iVar5 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          }
          lVar7 = 0;
          if (iVar5 != -0x3fffff45) goto LAB_1c000d628;
          goto LAB_1c000d281;
        }
        *(undefined8 *)(lVar15 + 0x68 + (longlong)local_e0) = 0;
        *(undefined ***)(lVar15 + 0x80 + (longlong)local_e0) = ppuVar14;
        local_128 = local_128 + 1;
        *(code **)(lVar15 + 0x78 + (longlong)local_e0) = IntelpmtpSamplerUpdateWorker;
        lVar15 = lVar15 + 0xa0;
        uVar17 = local_128;
      } while (local_128 < local_118);
    }
    local_128 = uVar17;
    iVar5 = 0;
LAB_1c000d8d2:
    lVar7 = 0;
    uVar17 = local_128;
  }
LAB_1c000d628:
  lVar15 = local_110;
  if ((IntelPmtpDiagTraceHandleInitialized != '\0') && (5 < DAT_1c0007028)) {
    local_9c = 0;
    local_a8 = &local_f0;
    local_8c = 0;
    local_7c = 0;
    local_6c = 0;
    local_5c = 0;
    local_4c = 0;
    local_3c = 0;
    local_98 = &local_ec;
    local_88 = &local_e8;
    local_78 = &local_e4;
    local_68 = &local_110;
    local_d8[0] = IntelPmtpSamplerTables;
    local_58 = local_d8;
    local_108 = *(longlong *)(local_110 + 0x68);
    local_48 = &local_108;
    local_a0 = 4;
    local_90 = 4;
    local_80 = 4;
    local_70 = 4;
    local_110 = CONCAT44(local_110._4_4_,uVar20);
    local_60 = 4;
    local_50 = 8;
    local_40 = 8;
    local_f0 = iVar5;
    local_ec = uVar17;
    local_e8 = uVar16;
    local_e4 = uVar21;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005d04,ppuVar18,lVar15,9,local_c8);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_DddDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  lVar15 = 0;
  if (lVar7 != 0) {
    ExFreePoolWithTag(lVar7,0x544d505f);
  }
  if (((iVar5 < 0) && (iVar5 != -0x3fffff5d)) && (IntelPmtpSamplerTables != (uint *)0x0)) {
    if (local_118 != 0) {
      uVar22 = (ulonglong)local_118;
      do {
        puVar2 = IntelPmtpSamplerTables;
        lVar7 = *(longlong *)(lVar15 + 0x38 + (longlong)IntelPmtpSamplerTables);
        if (lVar7 != 0) {
          MmUnmapIoSpace(lVar7,*(undefined8 *)(lVar15 + 0x40 + (longlong)IntelPmtpSamplerTables));
          *(undefined8 *)(lVar15 + 0x38 + (longlong)puVar2) = 0;
          *(undefined8 *)(lVar15 + 0x40 + (longlong)puVar2) = 0;
        }
        lVar7 = *(longlong *)(lVar15 + 0x50 + (longlong)puVar2);
        if (lVar7 != 0) {
          ExFreePoolWithTag(lVar7,0x544d505f);
          *(undefined8 *)(lVar15 + 0x50 + (longlong)puVar2) = 0;
        }
        lVar7 = *(longlong *)(lVar15 + 0x48 + (longlong)puVar2);
        if (lVar7 != 0) {
          MmUnmapIoSpace(lVar7,*(undefined8 *)(lVar15 + 0x58 + (longlong)puVar2));
          *(undefined8 *)(lVar15 + 0x48 + (longlong)puVar2) = 0;
          *(undefined8 *)(lVar15 + 0x58 + (longlong)puVar2) = 0;
        }
        lVar15 = lVar15 + 0xa0;
        uVar22 = uVar22 - 1;
      } while (uVar22 != 0);
    }
    ExFreePoolWithTag(IntelPmtpSamplerTables,0x544d505f);
    IntelPmtpSamplerTables = (uint *)0x0;
  }
  return iVar5;
}



===== IntelPmtpSamplerQueryMetadata @ 1c000d8f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
IntelPmtpSamplerQueryMetadata(uint param_1,ushort *param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 uVar4;
  undefined1 auStackY_d8 [32];
  undefined4 local_98;
  uint local_94;
  ushort *local_90;
  undefined8 local_88 [4];
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  uint *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ushort **local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  puVar3 = IntelPmtpSamplerTables;
  local_38 = __security_cookie ^ (ulonglong)auStackY_d8;
  if ((((param_2 == (ushort *)0x0) || (*param_2 < 0x68)) || (param_2[1] != 1)) ||
     (*IntelPmtpSamplerTables <= param_1)) {
    uVar4 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      param_4 = 0x2e;
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_3,0x2e,
                        &WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,0xd);
    }
  }
  else {
    uVar1 = IntelPmtpSamplerTables[1];
    uVar2 = IntelPmtpSamplerTables[2];
    IntelPmtpSamplerAcquireLock
              ((undefined8 *)(IntelPmtpSamplerTables + (ulonglong)param_1 * 0x28 + 4));
    *(uint *)(param_2 + 0x20) = puVar3[(ulonglong)param_1 * 0x28 + 9];
    *(uint *)(param_2 + 0x22) = uVar1;
    *(uint *)(param_2 + 0x24) = uVar2;
    uVar4 = 0;
    *(bool *)(param_2 + 0x1e) = puVar3[(ulonglong)param_1 * 0x28 + 0x22] == 0;
    IntelPmtpSamplerReleaseLock((undefined8 *)(puVar3 + (ulonglong)param_1 * 0x28 + 4));
  }
  if ((IntelPmtpDiagTraceHandleInitialized != '\0') && (5 < DAT_1c0007028)) {
    local_5c = 0;
    local_68 = &local_98;
    local_4c = 0;
    local_3c = 0;
    local_58 = &local_94;
    local_48 = &local_90;
    local_60 = 4;
    local_50 = 4;
    local_40 = 8;
    local_98 = uVar4;
    local_94 = param_1;
    local_90 = param_2;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005c39,param_3,param_4,5,local_88);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_Ddq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return uVar4;
}



===== IntelPmtpSamplerReleaseLock @ 1c000da94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IntelPmtpSamplerReleaseLock(undefined8 *param_1)

{
  param_1[1] = 0;
  (**(code **)(WdfFunctions_01023 + 0x9d0))(WdfDriverGlobals,*param_1);
  return;
}



===== IntelPmtpSamplerStart @ 1c000dad0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong IntelPmtpSamplerStart(uint param_1,ushort *param_2,longlong *param_3,char *param_4)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong *plVar4;
  longlong lVar5;
  uint *puVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint *puVar9;
  uint uVar10;
  longlong *plVar11;
  undefined1 auStackY_e8 [32];
  undefined8 in_stack_ffffffffffffff38;
  uint uVar12;
  uint local_a8;
  uint local_a4;
  longlong *local_a0;
  undefined8 local_98 [4];
  uint *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  uint *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong **local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_e8;
  plVar11 = (longlong *)0x0;
  local_a8 = param_1;
  local_a0 = param_3;
  if ((((param_2 == (ushort *)0x0) || (*param_2 < 0x68)) || (param_2[1] != 1)) ||
     (*IntelPmtpSamplerTables <= param_1)) {
    uVar8 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      param_4 = (char *)0x16;
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_3,0x16,
                        &WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,0xd);
    }
    goto LAB_1c000de3e;
  }
  uVar1 = IntelPmtpSamplerTables[2];
  uVar12 = IntelPmtpSamplerTables[1];
  puVar9 = IntelPmtpSamplerTables + (ulonglong)param_1 * 0x28 + 4;
  if (puVar9 == (uint *)0x0) {
    uVar8 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      param_4 = (char *)0x17;
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),IntelPmtpSamplerTables,param_3,
                       0x17);
    }
  }
  else {
    puVar6 = IntelPmtpSamplerTables;
    IntelPmtpSamplerAcquireLock((undefined8 *)puVar9);
    if (puVar9[0x1e] == 0) {
      plVar4 = (longlong *)(ulonglong)*(uint *)(param_2 + 0x2c);
      if (*(uint *)(param_2 + 0x2c) - 1000 < 0x36ea99) {
        uVar10 = *(uint *)(param_2 + 0x22);
        if (uVar10 == uVar12) {
          if (*(longlong *)(param_2 + 0x30) == 0) {
            uVar8 = 0xc000000d;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              param_4 = (char *)0x1b;
              plVar4 = plVar11;
LAB_1c000dc36:
              WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,param_3,
                               (short)param_4);
              plVar11 = plVar4;
            }
          }
          else if (*(longlong *)(param_2 + 0x28) == 0) {
            uVar8 = 0xc000000d;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              param_4 = (char *)0x1c;
              plVar4 = plVar11;
              goto LAB_1c000dc36;
            }
          }
          else {
            if (*(longlong *)(puVar9 + 0x22) != 0) {
              param_4 = "The shared memory should have been cleaned up whenthis sampler is stopped."
              ;
              MicrosoftTelemetryAssertTriggeredArgsMsgKM
                        ("IntelPmtpSamplerStart",puVar9[4],puVar9[0x22],
                         "The shared memory should have been cleaned up whenthis sampler is stopped."
                        );
            }
            lVar5 = 0x40;
            param_3 = (longlong *)0x544d505f;
            local_a4 = (uVar1 + 3 + uVar12) * puVar9[5] * 8;
            puVar6 = (uint *)(ulonglong)local_a4;
            lVar2 = ExAllocatePool2();
            plVar11 = plVar4;
            if (lVar2 == 0) {
              uVar8 = 0xc000009a;
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                param_4 = (char *)0x1d;
                goto LAB_1c000dc36;
              }
            }
            else {
              uVar10 = 0;
              lVar7 = lVar2;
              if (puVar9[5] != 0) {
                do {
                  uVar10 = uVar10 + 1;
                  lVar5 = lVar7 + 0x18 + (ulonglong)uVar12 * 8;
                  *(longlong *)(lVar7 + 8) = lVar7 + 0x18;
                  *(longlong *)(lVar7 + 0x10) = lVar5;
                  lVar7 = lVar5 + (ulonglong)uVar1 * 8;
                } while (uVar10 < puVar9[5]);
              }
              param_4 = (char *)(ulonglong)*(uint *)(param_2 + 0x22);
              param_3 = (longlong *)(ulonglong)*(uint *)(param_2 + 0x2c);
              uVar3 = IntelPmtpSamplerStartStopCPUSampling
                                (lVar5,*(longlong *)(puVar9 + 10),*(uint *)(param_2 + 0x2c),
                                 *(uint *)(param_2 + 0x22),*(undefined8 **)(param_2 + 0x30),'\x01');
              uVar8 = uVar3 & 0xffffffff;
              if ((int)uVar3 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  param_4 = (char *)0x1e;
                  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_3,0x1e,
                                    &WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,(char)uVar3);
                }
              }
              else {
                puVar6 = puVar9;
                uVar1 = IntelPmtpSamplerArmSamplingTimer
                                  ((ulonglong)puVar9,(ulonglong)*(uint *)(param_2 + 0x2c),
                                   (longlong)param_3,(undefined8 *)param_4);
                uVar8 = (ulonglong)uVar1;
                if (-1 < (int)uVar1) {
                  puVar9[0x24] = local_a4;
                  *(longlong *)(puVar9 + 0x22) = lVar2;
                  *(undefined8 *)(puVar9 + 0x26) = *(undefined8 *)(param_2 + 0x28);
                  puVar9[0x1e] = 1;
                  *local_a0 = lVar2;
                  goto LAB_1c000de06;
                }
                param_4 = (char *)0x0;
                param_3 = (longlong *)0x0;
                IntelPmtpSamplerStartStopCPUSampling
                          (puVar6,*(longlong *)(puVar9 + 10),0,0,(undefined8 *)0x0,'\0');
              }
              ExFreePoolWithTag(lVar2,0x544d505f);
            }
          }
        }
        else {
          uVar8 = 0xc000000d;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            param_4 = (char *)0x1a;
            goto LAB_1c000dbc2;
          }
        }
      }
      else {
        uVar8 = 0xc000000d;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
      }
    }
    else {
      uVar8 = 0xc0000010;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        param_4 = (char *)0x18;
        uVar10 = puVar9[4];
        uVar12 = puVar9[0x1e];
LAB_1c000dbc2:
        WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar6,param_3,(short)param_4,
                           in_stack_ffffffffffffff38,(char)uVar10,(char)uVar12);
      }
    }
LAB_1c000de06:
    IntelPmtpSamplerReleaseLock((undefined8 *)puVar9);
  }
  param_1 = local_a8;
LAB_1c000de3e:
  if ((IntelPmtpDiagTraceHandleInitialized != '\0') && (5 < DAT_1c0007028)) {
    local_6c = 0;
    local_78 = &local_a4;
    local_5c = 0;
    local_4c = 0;
    local_68 = &local_a8;
    local_58 = &local_a0;
    local_70 = 4;
    local_60 = 4;
    local_50 = 8;
    local_a8 = param_1;
    local_a4 = (uint)uVar8;
    local_a0 = plVar11;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005eaa,param_3,param_4,5,local_98);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_DdI(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return uVar8;
}



===== IntelPmtpSamplerStartStopCPUSampling @ 1c000df0c =====

undefined8
IntelPmtpSamplerStartStopCPUSampling
          (undefined8 param_1,longlong param_2,undefined4 param_3,uint param_4,undefined8 *param_5,
          char param_6)

{
  int iVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  uint local_res8;
  
  uVar2 = 0;
  if (param_2 == 0) {
    uVar2 = 0xc000000d;
  }
  else {
    if (param_6 == '\0') {
      local_res8 = 0;
    }
    else {
      *(undefined4 *)(param_2 + 0xc) = param_3;
      LOCK();
      UNLOCK();
      if (param_4 != 0) {
        puVar4 = (undefined8 *)(param_2 + 0x10);
        uVar5 = (ulonglong)param_4;
        do {
          *puVar4 = *param_5;
          LOCK();
          UNLOCK();
          puVar4 = puVar4 + 1;
          param_5 = param_5 + 1;
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
      local_res8 = 1;
    }
    local_res8 = local_res8 | 0x80000000;
    *(uint *)(param_2 + 8) = local_res8;
    LOCK();
    UNLOCK();
    iVar3 = 0;
    do {
      iVar1 = *(int *)(param_2 + 8);
      if (iVar3 == 10000) {
        MicrosoftTelemetryAssertTriggeredArgsMsgKM
                  ("IntelPmtpSamplerStartStopCPUSampling",10000,10,
                   "Timeout due to hardware not responding.");
        return 0x102;
      }
      KeStallExecutionProcessor(10);
      iVar3 = iVar3 + 1;
    } while (iVar1 < 0);
  }
  return uVar2;
}



===== IntelPmtpSamplerStop @ 1c000e020 =====

ulonglong IntelPmtpSamplerStop(ulonglong param_1,undefined *param_2,ulonglong param_3,char *param_4)

{
  ulonglong uVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)(IntelPmtpSamplerTables + 0x10 + (param_1 & 0xffffffff) * 0xa0);
  if ((puVar2 == (undefined8 *)0x0) || (param_2 == (undefined *)0x0)) {
    uVar1 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x20);
    }
  }
  else {
    IntelPmtpSamplerAcquireLock(puVar2);
    uVar1 = IntelPmtpSamplerStopUnsafe((longlong)puVar2,param_2,param_3,param_4);
    uVar1 = uVar1 & 0xffffffff;
    IntelPmtpSamplerReleaseLock(puVar2);
  }
  return uVar1;
}



===== IntelPmtpSamplerStopUnsafe @ 1c000e0ac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong IntelPmtpSamplerStopUnsafe
                    (longlong param_1,undefined *param_2,ulonglong param_3,char *param_4)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined1 auStackY_a8 [32];
  undefined *in_stack_ffffffffffffff78;
  undefined4 local_68;
  uint local_64 [3];
  undefined8 local_58 [4];
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  uint *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  uVar4 = 0xffffffff;
  if (param_1 == 0) {
    uVar5 = 0xc000000d;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000e227;
    param_4 = (char *)0x21;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x78);
    param_3 = (ulonglong)uVar1;
    uVar4 = *(uint *)(param_1 + 0x10);
    if (uVar1 != 1) {
      uVar5 = 0xc0000010;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        param_4 = (char *)0x22;
        WPP_RECORDER_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x22,
                           in_stack_ffffffffffffff78,(char)uVar4,(char)uVar1);
      }
      goto LAB_1c000e227;
    }
    if (*(undefined **)(param_1 + 0x88) == param_2) {
      if ((*(undefined **)(param_1 + 0x88) == (undefined *)0x0) || (param_2 == (undefined *)0x0)) {
        param_4 = "These fields should be initialized by start command.";
        param_2 = (undefined *)(ulonglong)uVar4;
        MicrosoftTelemetryAssertTriggeredArgsMsgKM
                  ("IntelPmtpSamplerStopUnsafe",uVar4,1,
                   "These fields should be initialized by start command.");
      }
      lVar3 = param_1;
      IntelPmtpSamplerDisarmSamplingTimer(param_1,param_2,param_3,(ulonglong)param_4);
      param_2 = *(undefined **)(param_1 + 0x28);
      param_4 = (char *)0x0;
      param_3 = 0;
      in_stack_ffffffffffffff78 = (undefined *)0x0;
      uVar2 = IntelPmtpSamplerStartStopCPUSampling
                        (lVar3,(longlong)param_2,0,0,(undefined8 *)0x0,'\0');
      uVar5 = uVar2 & 0xffffffff;
      if ((int)uVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          param_4 = (char *)0x24;
          param_2 = (undefined *)CONCAT71((int7)((ulonglong)param_2 >> 8),2);
          in_stack_ffffffffffffff78 = &WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids;
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_3,0x24,
                            &WPP_ecbba9db8a1d367e4837e4665b308a62_Traceguids,(char)uVar2);
        }
      }
      else {
        if (*(longlong *)(param_1 + 0x88) != 0) {
          param_2 = (undefined *)0x544d505f;
          ExFreePoolWithTag();
          *(undefined8 *)(param_1 + 0x88) = 0;
        }
        *(undefined8 *)(param_1 + 0x98) = 0;
        *(undefined4 *)(param_1 + 0x78) = 0;
      }
      goto LAB_1c000e227;
    }
    uVar5 = 0xc0000022;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000e227;
    param_4 = (char *)0x23;
  }
  WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,(short)param_4);
LAB_1c000e227:
  if ((IntelPmtpDiagTraceHandleInitialized != '\0') && (5 < DAT_1c0007028)) {
    local_2c = 0;
    local_38 = &local_68;
    local_1c = 0;
    param_2 = &DAT_1c0005cc5;
    local_28 = local_64;
    local_30 = 4;
    in_stack_ffffffffffffff78 =
         (undefined *)CONCAT44((int)((ulonglong)in_stack_ffffffffffffff78 >> 0x20),4);
    local_20 = 4;
    local_68 = (int)uVar5;
    local_64[0] = uVar4;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005cc5,param_3,param_4,4,local_58);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x25,
                       in_stack_ffffffffffffff78,(char)uVar5,(char)uVar4);
  }
  return uVar5;
}



===== IntelPmtpSamplerUninit @ 1c000e2f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void IntelPmtpSamplerUninit(undefined8 param_1,undefined8 param_2,ulonglong param_3,char *param_4)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  longlong lVar3;
  uint uVar4;
  undefined1 auStackY_78 [32];
  undefined4 in_stack_ffffffffffffffa8;
  undefined4 in_stack_ffffffffffffffac;
  uint local_48 [2];
  undefined8 local_40 [4];
  uint *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  uVar4 = 0;
  if (IntelPmtpSamplerTables != (uint *)0x0) {
    uVar4 = *IntelPmtpSamplerTables;
    if (uVar4 != 0) {
      lVar3 = 0;
      uVar2 = (ulonglong)uVar4;
      do {
        puVar1 = (undefined8 *)((longlong)IntelPmtpSamplerTables + lVar3 + 0x10);
        if (puVar1 != (undefined8 *)0x0) {
          IntelPmtpSamplerAcquireLock(puVar1);
          IntelPmtpSamplerStopUnsafe((longlong)puVar1,(undefined *)puVar1[0x11],param_3,param_4);
          if (puVar1[0x10] != 0) {
            param_4 = (char *)0x0;
            param_3 = 0;
            ExDeleteTimer(puVar1[0x10],1);
            puVar1[0x10] = 0;
          }
          if (puVar1[0x11] != 0) {
            ExFreePoolWithTag(puVar1[0x11],0x544d505f);
            puVar1[0x11] = 0;
          }
          if (puVar1[5] != 0) {
            MmUnmapIoSpace(puVar1[5],puVar1[6]);
            puVar1[5] = 0;
          }
          if (puVar1[8] != 0) {
            ExFreePoolWithTag(puVar1[8],0x544d505f);
            puVar1[8] = 0;
          }
          if (puVar1[7] != 0) {
            MmUnmapIoSpace(puVar1[7],puVar1[9]);
            puVar1[7] = 0;
          }
          IntelPmtpSamplerReleaseLock(puVar1);
        }
        lVar3 = lVar3 + 0xa0;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    ExFreePoolWithTag(IntelPmtpSamplerTables,0x544d505f);
    IntelPmtpSamplerTables = (uint *)0x0;
  }
  if ((IntelPmtpDiagTraceHandleInitialized != '\0') && (5 < DAT_1c0007028)) {
    local_14 = 0;
    local_20 = local_48;
    in_stack_ffffffffffffffa8 = 3;
    local_18 = 4;
    local_48[0] = uVar4;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005ef4,param_3,param_4,3,local_40);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0x15,
                      CONCAT44(in_stack_ffffffffffffffac,in_stack_ffffffffffffffa8),(char)uVar4);
  }
  return;
}



===== IntelpmtpSamplerUpdateWorker @ 1c000e4f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void IntelpmtpSamplerUpdateWorker
               (undefined8 *param_1,undefined8 param_2,ulonglong param_3,longlong param_4)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  longlong lVar8;
  ulonglong uVar9;
  undefined1 auStackY_a8 [32];
  undefined4 in_stack_ffffffffffffff78;
  undefined4 in_stack_ffffffffffffff7c;
  undefined4 local_70 [2];
  undefined8 local_68 [4];
  undefined4 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_a8;
  uVar6 = 0xffffffff;
  if (IntelPmtpSamplerTables != 0) {
    uVar1 = *(uint *)(IntelPmtpSamplerTables + 8);
    uVar2 = *(uint *)(IntelPmtpSamplerTables + 4);
    if (param_1 != (undefined8 *)0x0) {
      IntelPmtpSamplerAcquireLock(param_1);
      uVar6 = *(undefined4 *)(param_1 + 2);
      if (*(int *)(param_1 + 0xf) == 1) {
        puVar5 = (undefined8 *)param_1[0x11];
        param_3 = 0;
        if (*(int *)((longlong)param_1 + 0x14) != 0) {
          do {
            lVar3 = param_1[8];
            *puVar5 = **(undefined8 **)(lVar3 + param_3 * 0x18);
            if (uVar2 != 0) {
              param_4 = 0;
              lVar8 = 0;
              uVar9 = (ulonglong)uVar2;
              do {
                puVar4 = (undefined8 *)(*(longlong *)(lVar3 + 8 + param_3 * 0x18) + lVar8);
                lVar8 = lVar8 + 8;
                *(undefined8 *)(param_4 + puVar5[1]) = *puVar4;
                param_4 = param_4 + 8;
                uVar9 = uVar9 - 1;
              } while (uVar9 != 0);
            }
            if (uVar1 != 0) {
              param_4 = 0;
              lVar8 = 0;
              uVar9 = (ulonglong)uVar1;
              do {
                puVar4 = (undefined8 *)(*(longlong *)(lVar3 + 0x10 + param_3 * 0x18) + lVar8);
                lVar8 = lVar8 + 8;
                *(undefined8 *)(param_4 + puVar5[2]) = *puVar4;
                param_4 = param_4 + 8;
                uVar9 = uVar9 - 1;
              } while (uVar9 != 0);
            }
            uVar7 = (int)param_3 + 1;
            param_3 = (ulonglong)uVar7;
            puVar5 = (undefined8 *)(puVar5[2] + (ulonglong)uVar1 * 8);
          } while (uVar7 < *(uint *)((longlong)param_1 + 0x14));
        }
        if ((code *)param_1[0x13] != (code *)0x0) {
          (*(code *)param_1[0x13])(*(undefined4 *)(param_1 + 2));
        }
      }
      LOCK();
      *(undefined4 *)(param_1 + 10) = 0;
      UNLOCK();
      IntelPmtpSamplerReleaseLock(param_1);
    }
  }
  if ((IntelPmtpDiagTraceHandleInitialized != '\0') && (5 < DAT_1c0007028)) {
    local_3c = 0;
    local_48 = local_70;
    in_stack_ffffffffffffff78 = 3;
    local_40 = 4;
    local_70[0] = uVar6;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005c8d,param_3,param_4,3,local_68);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0x26,
                      CONCAT44(in_stack_ffffffffffffff7c,in_stack_ffffffffffffff78),(char)uVar6);
  }
  return;
}



===== __security_init_cookie @ 1c000f008 =====

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



===== DriverEntry @ 1c000f03c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong *puVar2;
  undefined1 auStackY_f8 [32];
  int local_b8 [2];
  ulonglong local_b0;
  code *local_a8;
  code *local_a0;
  ulonglong local_98;
  ulonglong local_90 [11];
  int *local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_90[0] = (ulonglong)(uint)local_90[0];
  local_b0 = (ulonglong)(uint)local_b0;
  local_98 = local_98 & 0xffffffff00000000;
  wil_InitializeFeatureStaging();
  _WPP_MAIN_CB = 0;
  DAT_1c0007468 = &WPP_ThisDir_CTLGUID_IntelPMTWPPTrace;
  DAT_1c0007470 = 0;
  _DAT_1c0007480 = 0;
  _DAT_1c0007488 = 1;
  _DAT_1c00074a0 = 0;
  _DAT_1c00074a8 = 0;
  WppLoadTracingSupport();
  _DAT_1c0007480 = 0;
  WppInitKm(param_1,param_2);
  iVar1 = TraceLoggingRegister_EtwRegister_EtwSetInformation();
  if (-1 < iVar1) {
    IntelPmtpDiagTraceHandleInitialized = '\x01';
  }
  if (5 < DAT_1c0007028) {
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005a3a,param_3,param_4,2,local_90 + 7);
  }
  local_b0 = 0x20;
  local_90[2] = 0;
  local_98 = 0;
  local_a8 = IntelPmtpEvtDeviceAdd;
  local_90[1] = 0;
  local_90[0] = 0x38;
  local_a0 = IntelPmtpEvtDriverUnload;
  puVar2 = local_90;
  local_90[6] = 0;
  local_90[4] = 0;
  local_90[5] = 0;
  local_90[3] = 0x100000002;
  iVar1 = (**(code **)(WdfFunctions_01023 + 0x3a0))(WdfDriverGlobals,param_1);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      puVar2 = (ulonglong *)0xa;
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_2,10,
                        &WPP_f84f8971834f360366e1ee7734d3dbd7_Traceguids,(char)iVar1);
    }
  }
  else {
    iVar1 = 0;
  }
  if ((IntelPmtpDiagTraceHandleInitialized != '\0') && (5 < DAT_1c0007028)) {
    local_38 = local_b8;
    local_30 = 4;
    local_b8[0] = iVar1;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c0007028,&DAT_1c0005991,param_2,puVar2,3,local_90 + 7);
  }
  if (iVar1 < 0) {
    WppCleanupKm(param_1);
  }
  return iVar1;
}



===== wil_InitializeFeatureStaging @ 1c000f244 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
    for (ppuVar3 = &Feature_SamplerSupportADLN__private_descriptor;
        ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
      if (*ppuVar3 != (undefined *)0x0) goto LAB_1c000f2cb;
    }
LAB_1c000f305:
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
LAB_1c000f2cb:
  if (ppuVar3 == (undefined **)0x0) goto LAB_1c000f305;
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
      _g_wil_details_featureChangeNotification = 0;
    }
    goto LAB_1c000f305;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_1c0006bdf < ppuVar3) goto LAB_1c000f305;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1c000f2cb;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 1c000f358 =====

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
  ppuVar4 = &Feature_SamplerSupportADLN__private_descriptor;
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
            if (&UNK_1c0006bdf < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_1c000f442;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_1c000f442;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_1c000f442:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_1c0006bdf < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


