
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



===== RtlCopyFromUser @ 140001038 =====

/* WARNING: Removing unreachable block (ram,0x00014000105c) */

void RtlCopyFromUser(void *param_1,void *param_2,size_t param_3)

{
  if (param_3 != 0) {
    ProbeForRead(param_2,param_3,1);
    RtlpCopyDeviceMemory(param_1,param_2,param_3);
  }
  return;
}



===== _guard_check_icall @ 1400010b0 =====

void _guard_check_icall(void)

{
  return;
}



===== ProbeForRead @ 1400010c6 =====

void ProbeForRead(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001400010c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ProbeForRead();
  return;
}



===== __cpu_features_init @ 1400010e0 =====

/* WARNING: Removing unreachable block (ram,0x00014000114a) */
/* WARNING: Removing unreachable block (ram,0x0001400010f9) */
/* WARNING: Removing unreachable block (ram,0x0001400010ea) */

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



===== WPP_RECORDER_SF_D @ 1400011a8 =====

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



===== WPP_RECORDER_SF_q @ 140001258 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_q(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,8,0);
  }
  WppAutoLogTrace(param_1,param_2,1,param_5,param_4,&param_6,8,0);
  return;
}



===== WPP_RECORDER_SF_qL @ 140001308 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qL(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,8,&param_7,4
               ,0);
  }
  WppAutoLogTrace(param_1,param_2,1,param_5,param_4,&param_6,8,&param_7,4,0);
  return;
}



===== WppClassicProviderCallback @ 1400013f0 =====

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



===== wil_details_RecordCachedUsage @ 14000144c =====

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



===== wil_details_RecordFeatureUsageReporting @ 1400015a0 =====

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



===== FDO_CreateVhfDevice @ 140001624 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint FDO_CreateVhfDevice(longlong param_1,undefined8 param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  char cVar3;
  char cVar4;
  ushort uVar5;
  uint uVar6;
  longlong lVar7;
  undefined1 *puVar8;
  longlong *plVar9;
  longlong *plVar10;
  undefined1 *puVar11;
  ushort *puVar12;
  undefined2 uVar13;
  ushort *local_res20;
  undefined1 auStackY_78 [8];
  undefined1 auStackY_70 [24];
  ulonglong local_38;
  ulonglong *local_30;
  
  local_38 = 0;
  local_res20 = (ushort *)0x0;
  local_30 = (ulonglong *)0x0;
  puVar12 = (ushort *)0x48;
  uVar6 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0x48,&local_res20);
  if (uVar6 == 0xc0000023) {
    puVar12 = (ushort *)0x38;
    uVar6 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0x38,&local_res20);
    if ((int)uVar6 < 0) {
      if (uVar6 == 0xc0000023) {
        puVar12 = (ushort *)0x28;
        uVar6 = (**(code **)(WdfFunctions_01015 + 0x868))
                          (WdfDriverGlobals,param_2,0x28,&local_res20);
        if (-1 < (int)uVar6) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar13 = 0x16;
            goto LAB_1400016e8;
          }
          goto LAB_1400016ff;
        }
      }
LAB_1400017ad:
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar6;
      }
      uVar13 = 0x17;
      goto LAB_1400017d2;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar13 = 0x15;
LAB_1400016e8:
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,puVar12,uVar13,
                       &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids);
    }
  }
  else if ((int)uVar6 < 0) goto LAB_1400017ad;
LAB_1400016ff:
  puVar11 = auStackY_78;
  puVar12 = (ushort *)0x10;
  uVar6 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0x10,&local_30);
  if ((int)uVar6 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar6;
    }
    uVar13 = 0x18;
  }
  else {
    lVar7 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
    if (lVar7 != 0) {
      puVar8 = (undefined1 *)
               (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,lVar7,PTR__WDF_FDO_FILEOBJECT_CONTEXT_TYPE_INFO_14000c090
                         );
      *puVar8 = 1;
    }
    cVar3 = (**(code **)(WdfFunctions_01015 + 0x818))(WdfDriverGlobals,param_2);
    cVar4 = (**(code **)(WdfFunctions_01015 + 0x8c0))(WdfDriverGlobals,param_2);
    puVar12 = local_res20;
    uVar6 = PDO_CreateDevice(*(undefined8 *)(param_1 + 8),lVar7,local_res20,0,cVar4,cVar3,&local_38)
    ;
    if (-1 < (int)uVar6) {
      plVar9 = (longlong *)
               (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,local_38,PTR__WDF_PDO_CONTEXT_TYPE_INFO_14000c040);
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
      lVar7 = param_1 + 0x28;
      plVar10 = *(longlong **)(param_1 + 0x30);
      if (*plVar10 != lVar7) {
        pcVar2 = (code *)swi(0x29);
        plVar10 = (longlong *)(*pcVar2)(3);
        puVar11 = auStackY_70;
      }
      *plVar9 = lVar7;
      plVar9[1] = (longlong)plVar10;
      *plVar10 = (longlong)plVar9;
      *(longlong **)(lVar7 + 8) = plVar9;
      uVar1 = *(undefined8 *)(param_1 + 0x20);
      pcVar2 = *(code **)(WdfFunctions_01015 + 0x9e8);
      *(undefined8 *)(puVar11 + -8) = 0x140001944;
      (*pcVar2)(WdfDriverGlobals,uVar1);
      *local_30 = local_38;
      *(undefined8 *)(puVar11 + -8) = 0x140001958;
      uVar5 = PDO_GetMaxReportBufferLength(local_38);
      *(ushort *)(local_30 + 1) = uVar5;
      pcVar2 = *(code **)(WdfFunctions_01015 + 0x898);
      *(undefined8 *)(puVar11 + -8) = 0x140001983;
      (*pcVar2)(WdfDriverGlobals,param_2,0x10);
      return 0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar6;
    }
    uVar13 = 0x19;
  }
LAB_1400017d2:
  WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar12,uVar13,
                     &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,(char)param_2,(char)uVar6);
  return uVar6;
}



===== FDO_DeleteVhfDevice @ 1400019a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong FDO_DeleteVhfDevice(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  longlong *plVar7;
  longlong lVar8;
  longlong *local_res18;
  longlong local_res20;
  undefined8 uVar9;
  undefined1 uVar10;
  
  local_res18 = (longlong *)0x0;
  uVar6 = 8;
  local_res20 = 0;
  uVar9 = 0;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,8,&local_res18);
  uVar5 = (ulonglong)uVar1;
  uVar10 = (undefined1)param_2;
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar6,0x1a,
                          &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,
                          (char)*(undefined8 *)(param_1 + 8),uVar10,(char)uVar1);
    }
  }
  else {
    plVar7 = &local_res20;
    lVar4 = *local_res18;
    uVar2 = FDO_GetPdoFromVhfiHandle(param_1,lVar4,plVar7);
    uVar5 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqid
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar4,plVar7,0x1b,
                   &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,
                   (char)*(undefined8 *)(param_1 + 8),uVar10,(char)*local_res18,(char)uVar2);
      }
    }
    else {
      (**(code **)(WdfFunctions_01015 + 0x430))(WdfDriverGlobals,*(undefined8 *)(param_1 + 8));
      lVar4 = local_res20;
      lVar3 = 0;
      do {
        lVar8 = lVar3;
        lVar3 = (**(code **)(WdfFunctions_01015 + 0x438))
                          (WdfDriverGlobals,*(undefined8 *)(param_1 + 8),lVar8,5);
        if (lVar3 == 0) goto LAB_140001b85;
      } while (lVar3 != lVar4);
      uVar1 = (**(code **)(WdfFunctions_01015 + 0x6d8))(WdfDriverGlobals,lVar4);
      uVar5 = (ulonglong)uVar1;
      if (((int)uVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_SF_qqqd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,lVar8,0x1c,uVar9,
                   (char)*(undefined8 *)(param_1 + 8),uVar10,(char)lVar4,(char)uVar1);
      }
LAB_140001b85:
      (**(code **)(WdfFunctions_01015 + 0x440))(WdfDriverGlobals,*(undefined8 *)(param_1 + 8));
      if ((lVar3 == 0) &&
         (uVar5 = 0xc000000e, (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_SF_qqqd
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,lVar8,0x1d,uVar9,
                   (char)*(undefined8 *)(param_1 + 8),uVar10,(char)lVar4,0xe);
      }
    }
  }
  return uVar5;
}



===== FDO_EvtDeviceCleanupCallback @ 140001c00 =====

void FDO_EvtDeviceCleanupCallback(undefined1 param_1,undefined8 param_2,undefined8 param_3)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0x14,
                      &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,param_1);
  }
  return;
}



===== FDO_EvtIoDeviceControl @ 140001c50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FDO_EvtIoDeviceControl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               int param_5)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined *puVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined1 auStackY_98 [32];
  undefined *in_stack_ffffffffffffff88;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_98;
  local_48 = 0;
  uStack_40 = 0;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  uVar7 = uVar3;
  puVar5 = PTR__WDF_FDO_CONTEXT_TYPE_INFO_14000c0e0;
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  uVar8 = (undefined1)uVar3;
  uVar9 = (undefined1)param_2;
  uVar10 = (undefined1)param_5;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,puVar5,0x1e,
                        in_stack_ffffffffffffff88,uVar8,uVar9,uVar10);
  }
  if ((param_5 == 0xb0324) || (param_5 == 0xb0329)) {
LAB_140001e97:
    iVar2 = -0x3fffff1b;
  }
  else {
    uVar7 = 4;
    if (param_5 == 0xb032d) {
      uVar7 = param_2;
      uVar6 = PDO_ReadReportNotify(lVar4,param_2);
      iVar2 = (int)uVar6;
    }
    else {
      if (param_5 == 0xb0331) goto LAB_140001e97;
      if (param_5 == 0xb0336) {
        puVar5 = (undefined *)0x0;
        uVar7 = param_2;
        uVar6 = PDO_PullRequestNotify(lVar4,param_2,'\0');
        iVar2 = (int)uVar6;
      }
      else {
        if (param_5 == 0xb0339) goto LAB_140001e97;
        if (param_5 == 0xb033c) {
          uVar7 = param_2;
          uVar6 = PDO_DeviceResetComplete(lVar4,param_2);
          iVar2 = (int)uVar6;
        }
        else if (((param_5 == 0xb0340) || (param_5 == 0xb0344)) && (*(char *)(lVar4 + 4) != '\0')) {
          if (param_5 == 0xb0340) {
            uVar7 = param_2;
            iVar2 = PDO_QueryPowerState(lVar4,param_2);
          }
          else {
            if (param_5 != 0xb0344) goto LAB_140001d7d;
            uVar7 = param_2;
            iVar2 = PDO_IndicateWakeStatus(lVar4,param_2);
          }
        }
        else {
LAB_140001d7d:
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            in_stack_ffffffffffffff88 = &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids;
            WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar5,0x1f,
                              &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,uVar10);
          }
          uStack_40 = 0;
          local_48 = 0x800000010;
          puVar5 = (undefined *)(**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,uVar3);
          uVar7 = param_2;
          cVar1 = (**(code **)(WdfFunctions_01015 + 0x7e8))
                            (WdfDriverGlobals,param_2,puVar5,&local_48);
          if (cVar1 == '\0') {
            uVar7 = param_2;
            iVar2 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_2);
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_140001ecd;
            uVar7 = CONCAT71((int7)((ulonglong)uVar7 >> 8),2);
            in_stack_ffffffffffffff88 = &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids;
            WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar5,0x20,
                                &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,uVar8,uVar9,
                                (char)iVar2);
          }
          else {
            iVar2 = 0x103;
          }
        }
      }
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqLd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,puVar5,0x21,
               in_stack_ffffffffffffff88,uVar8,uVar9,uVar10,(char)iVar2);
  }
LAB_140001ecd:
  if (iVar2 != 0x103) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar2);
  }
  return;
}



===== FDO_EvtIoInCallerContext @ 140001f20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FDO_EvtIoInCallerContext(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  int *piVar4;
  ulonglong uVar5;
  code *pcVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  undefined1 auStackY_a8 [32];
  undefined8 in_stack_ffffffffffffff78;
  undefined1 uVar10;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_a8;
  piVar4 = (int *)(**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,param_1,PTR__WDF_FDO_CONTEXT_TYPE_INFO_14000c0e0);
  puVar9 = &local_58;
  local_38 = 0;
  uStack_50 = 0;
  local_58 = 0x28;
  local_48 = 0;
  uStack_40 = 0;
  uVar7 = param_2;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals);
  iVar1 = (int)uStack_40;
  if (local_58._4_4_ != 0xe) goto LAB_14000214d;
  uVar10 = (undefined1)uStack_40;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,puVar9,0x22,
                        in_stack_ffffffffffffff78,(char)param_1,(char)param_2,uVar10);
  }
  if ((((iVar1 == 0xb0322) || (iVar1 == 0xb0324)) || (iVar1 == 0xb0329)) ||
     (((iVar1 == 0xb032d || (iVar1 == 0xb0331)) || ((iVar1 == 0xb0336 || (iVar1 == 0xb0339)))))) {
    uVar7 = param_2;
    uVar5 = FDO_ValidateRequest(piVar4,param_2);
    uVar8 = uVar5 & 0xffffffff;
    if (-1 < (int)uVar5) goto LAB_14000202a;
LAB_140002098:
    if ((int)uVar8 == 0x103) {
LAB_14000214d:
      uVar3 = (**(code **)(WdfFunctions_01015 + 0x2d8))(WdfDriverGlobals,param_1,param_2);
      uVar8 = (ulonglong)uVar3;
      if (-1 < (int)uVar3) {
        return;
      }
      pcVar6 = *(code **)(WdfFunctions_01015 + 0x838);
      goto LAB_140002182;
    }
  }
  else {
LAB_14000202a:
    if (iVar1 != 0xb0322) {
      if (iVar1 == 0xb0324) {
        cVar2 = KeGetCurrentIrql();
        if (cVar2 != '\0') {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            KeGetCurrentIrql();
            WPP_RECORDER_SF_Lc(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          }
          uVar8 = 0xc000000d;
          goto LAB_140002098;
        }
        uVar7 = param_2;
        uVar3 = FDO_CreateVhfDevice((longlong)piVar4,param_2);
LAB_140002096:
        uVar8 = (ulonglong)uVar3;
        goto LAB_140002098;
      }
      if (iVar1 == 0xb0329) {
        uVar7 = param_2;
        uVar5 = FDO_DeleteVhfDevice((longlong)piVar4,param_2);
        uVar3 = (uint)uVar5;
        goto LAB_140002096;
      }
      if (iVar1 != 0xb032d) {
        if (iVar1 == 0xb0331) {
          uVar7 = param_2;
          uVar5 = PDO_ReadReportComplete((longlong)piVar4,param_2);
          uVar3 = (uint)uVar5;
        }
        else if (iVar1 == 0xb0336) {
          puVar9 = (undefined8 *)CONCAT71((int7)((ulonglong)puVar9 >> 8),1);
          uVar7 = param_2;
          uVar5 = PDO_PullRequestNotify((longlong)piVar4,param_2,'\x01');
          uVar3 = (uint)uVar5;
        }
        else {
          if (iVar1 != 0xb0339) goto LAB_14000214d;
          uVar7 = param_2;
          uVar5 = PDO_PullRequestComplete((longlong)piVar4,param_2);
          uVar3 = (uint)uVar5;
        }
        goto LAB_140002096;
      }
      goto LAB_14000214d;
    }
    uVar8 = 0xc0000002;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqLd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,puVar9,0x24,
               in_stack_ffffffffffffff78,(char)param_1,(char)param_2,uVar10,(char)uVar8);
  }
  pcVar6 = *(code **)(WdfFunctions_01015 + 0x838);
LAB_140002182:
  (*pcVar6)(WdfDriverGlobals,param_2,uVar8);
  return;
}



===== FDO_GetPdoFromVhfiHandle @ 1400021bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 FDO_GetPdoFromVhfiHandle(longlong param_1,longlong param_2,longlong *param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  uVar2 = 0xc000000d;
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
  puVar1 = *(undefined8 **)(param_1 + 0x28);
  do {
    if (puVar1 == (undefined8 *)(param_1 + 0x28)) {
LAB_14000221b:
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
      return uVar2;
    }
    if (puVar1[2] == param_2) {
      *param_3 = param_2;
      uVar2 = 0;
      goto LAB_14000221b;
    }
    puVar1 = (undefined8 *)*puVar1;
  } while( true );
}



===== FDO_ValidateRequest @ 140002258 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 FDO_ValidateRequest(int *param_1,undefined8 param_2)

{
  char cVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  if (*param_1 == 0) {
    cVar1 = (**(code **)(WdfFunctions_01015 + 0x8c0))(WdfDriverGlobals);
    if (cVar1 == '\x01') {
      lVar2 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_2);
      if ((lVar2 != 0) &&
         (uVar3 = 0xc0000022, (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_SF_qqqdLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
    }
  }
  return uVar3;
}



===== WPP_RECORDER_SF_ @ 140002318 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                     undefined8 param_5)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,param_5,param_4,0);
  return;
}



===== WPP_RECORDER_SF_Lc @ 1400023a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Lc(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,0x23,&uStack0000000000000030,4,
               &uStack0000000000000038,1,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,0x23,
                  &uStack0000000000000030,4,&uStack0000000000000038,1,0);
  return;
}



===== WPP_RECORDER_SF_qq @ 14000247c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qq(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,8,&param_7,8
               ,0);
  }
  WppAutoLogTrace(param_1,param_2,1,param_5,param_4,&param_6,8,&param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_qqL @ 140002558 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qqLd @ 140002650 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqLd
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_qqc @ 140002768 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqc(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,0x27,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,1,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,0x27,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,1,0);
  return;
}



===== WPP_RECORDER_SF_qqd @ 14000285c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqd(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,8,&param_7,8
               ,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,param_5,param_4,&param_6,8,&param_7,8,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qqdDDLd @ 140002960 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqdDDLd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined4 local_18 [4];
  
  local_18[0] = 0xc0000022;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,0xb,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,local_18,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,0xb,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  local_18,4,0);
  return;
}



===== WPP_RECORDER_SF_qqid @ 140002ae0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqid
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,8,&param_7,8
               ,&param_8,8,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,2,1,param_5,param_4,&param_6,8,&param_7,8,&param_8,8,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_qqq @ 140002bf8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,8,&param_7,8
               ,&param_8,8,0);
  }
  WppAutoLogTrace(param_1,4,1,param_5,param_4,&param_6,8,&param_7,8,&param_8,8,0);
  return;
}



===== WPP_RECORDER_SF_qqqd @ 140002ce8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqqd
               (undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,8,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,&WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,param_4,
                  &param_6,8,&param_7,8,&param_8,8,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_qqqdLd @ 140002e08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqqdLd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined4 local_18 [4];
  
  local_18[0] = 0xc0000022;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,10,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,&uStack0000000000000048,4,
               &uStack0000000000000050,4,local_18,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,10,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,local_18,4,0);
  return;
}



===== Feature_VHFUMA01__private_IsEnabledDeviceUsageNoInline @ 140002f68 =====

ulonglong Feature_VHFUMA01__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_VHFUMA01__private_featureState;
  if ((Feature_VHFUMA01__private_featureState & 0x10) == 0) {
    uVar1 = Feature_VHFUMA01__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_VHFUMA01__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_VHFUMA01__private_IsEnabledFallback @ 140002fa0 =====

void Feature_VHFUMA01__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== PDO_DeviceResetComplete @ 140002fb8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong PDO_DeviceResetComplete(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  longlong *plVar8;
  undefined8 *puVar9;
  longlong *local_res18;
  undefined8 local_res20;
  longlong local_18 [2];
  
  local_res18 = (longlong *)0x0;
  local_res20 = 0;
  uVar7 = 8;
  local_18[0] = 0;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,8,&local_res18,0);
  uVar6 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar7,0x47,
                         &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)param_2,(char)uVar3)
      ;
    }
  }
  else {
    plVar8 = local_18;
    lVar5 = *local_res18;
    uVar4 = FDO_GetPdoFromVhfiHandle(param_1,lVar5,plVar8);
    lVar1 = local_18[0];
    uVar6 = uVar4 & 0xffffffff;
    if ((int)uVar4 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqid
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar5,plVar8,0x48,
                   &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,
                   (char)*(undefined8 *)(param_1 + 8),(char)param_2,(char)*local_res18,(char)uVar4);
      }
    }
    else {
      lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,local_18[0],PTR__WDF_PDO_CONTEXT_TYPE_INFO_14000c040);
      puVar9 = &local_res20;
      uVar3 = (**(code **)(WdfFunctions_01015 + 0x4f0))
                        (WdfDriverGlobals,*(undefined8 *)(lVar5 + 0x28));
      uVar6 = (ulonglong)uVar3;
      if ((int)uVar3 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar9,0x49,
                            &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)uVar3);
        }
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar2 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,local_res20);
          WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar9,0x4a,
                             &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)lVar1,uVar2);
        }
        (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,local_res20,0);
      }
    }
  }
  return uVar6;
}



===== PDO_EvtDeviceCleanupCallback @ 140003210 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PDO_EvtDeviceCleanupCallback(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong *plVar1;
  code *pcVar2;
  undefined1 uVar3;
  int iVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined *puVar9;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0x28,
                      &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)param_1);
  }
  plVar5 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PDO_CONTEXT_TYPE_INFO_14000c040);
  lVar7 = 0;
  uVar3 = KeAcquireSpinLockRaiseToDpc(plVar5 + 0x1c);
  *(undefined1 *)(plVar5 + 0x1d) = uVar3;
  *(undefined1 *)((longlong)plVar5 + 0xe9) = 1;
  if (plVar5[0x20] != 0) {
    iVar4 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals);
    if (-1 < iVar4) {
      lVar7 = plVar5[0x20];
      plVar5[0x20] = 0;
    }
  }
  KeReleaseSpinLock(plVar5 + 0x1c,(char)plVar5[0x1d]);
  if (lVar7 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,lVar7,0xc00000c0);
  }
  lVar7 = 0;
  uVar3 = KeAcquireSpinLockRaiseToDpc(plVar5 + 0x23);
  *(undefined1 *)(plVar5 + 0x24) = uVar3;
  *(undefined1 *)((longlong)plVar5 + 0x121) = 1;
  if (plVar5[0x26] != 0) {
    iVar4 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals);
    if (-1 < iVar4) {
      lVar7 = plVar5[0x26];
      plVar5[0x26] = 0;
    }
  }
  KeReleaseSpinLock(plVar5 + 0x23,(char)plVar5[0x24]);
  if (lVar7 != 0) {
    lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,lVar7,PTR__WDF_FDO_REQUEST_CONTEXT_TYPE_INFO_14000c0b8);
    if ((lVar6 != 0) && (*(longlong *)(lVar6 + 8) != 0)) {
      MmUnlockPages();
      IoFreeMdl(*(undefined8 *)(lVar6 + 8));
      *(undefined8 *)(lVar6 + 8) = 0;
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,lVar7,0xc00000c0);
  }
  puVar9 = PTR__WDF_FDO_CONTEXT_TYPE_INFO_14000c0e0;
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,plVar5[3]);
  uVar8 = *(undefined8 *)(lVar7 + 0x20);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals);
  if ((longlong *)*plVar5 != plVar5) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,puVar9,0x32,
                          &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,(char)plVar5[2],
                          (char)plVar5,(char)*(undefined8 *)(lVar7 + 8));
    }
    lVar6 = *plVar5;
    if ((*(longlong **)(lVar6 + 8) != plVar5) ||
       (plVar1 = (longlong *)plVar5[1], (longlong *)*plVar1 != plVar5)) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    *plVar1 = lVar6;
    *(longlong **)(lVar6 + 8) = plVar1;
    plVar5[1] = (longlong)plVar5;
    *plVar5 = (longlong)plVar5;
  }
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar7 + 0x20));
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar9,0x29,
                      &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)param_1);
  }
  return;
}



===== PDO_EvtDeviceD0Entry @ 140003540 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 PDO_EvtDeviceD0Entry(undefined8 param_1,undefined1 param_2)

{
  longlong lVar1;
  undefined *puVar2;
  
  puVar2 = PTR__WDF_PDO_CONTEXT_TYPE_INFO_14000c040;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar2,0x2d,
                       &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)param_1,param_2);
  }
  *(undefined4 *)(lVar1 + 0x140) = 1;
  return 0;
}



===== PDO_EvtDeviceD0Exit @ 1400035e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 PDO_EvtDeviceD0Exit(undefined8 param_1,undefined4 param_2)

{
  longlong lVar1;
  undefined *puVar2;
  
  puVar2 = PTR__WDF_PDO_CONTEXT_TYPE_INFO_14000c040;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar2,0x2e,
                       &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)param_1,(char)param_2)
    ;
  }
  *(undefined4 *)(lVar1 + 0x140) = param_2;
  return 0;
}



===== PDO_EvtDeviceDestroyCallback @ 140003680 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PDO_EvtDeviceDestroyCallback(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined *puVar2;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0x2a,
                      &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)param_1);
  }
  puVar2 = PTR__WDF_PDO_CONTEXT_TYPE_INFO_14000c040;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if (*(longlong *)(lVar1 + 0xd8) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0xd8),0x44464856);
  }
  if (*(longlong *)(lVar1 + 0x58) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x58),0x44464856);
  }
  if (*(char *)(lVar1 + 0xc0) != '\0') {
    HidP_FreeCollectionDescription(lVar1 + 0x80);
  }
  if (*(longlong *)(lVar1 + 0x68) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 0x68),0);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar2,0x2b,
                      &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)param_1);
  }
  return;
}



===== PDO_EvtDeviceDisableWakeAtBus @ 1400037b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PDO_EvtDeviceDisableWakeAtBus(undefined8 param_1)

{
  longlong lVar1;
  undefined *puVar2;
  
  puVar2 = PTR__WDF_PDO_CONTEXT_TYPE_INFO_14000c040;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar2,0x30,
                       &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,
                       (char)*(undefined8 *)(lVar1 + 0x18),(char)param_1);
  }
  *(undefined1 *)(lVar1 + 0x144) = 0;
  return;
}



===== PDO_EvtDeviceEnableWakeAtBus @ 140003840 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 PDO_EvtDeviceEnableWakeAtBus(undefined8 param_1,undefined1 param_2)

{
  longlong lVar1;
  undefined *puVar2;
  
  puVar2 = PTR__WDF_PDO_CONTEXT_TYPE_INFO_14000c040;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar2,0x2f,
                        &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,
                        (char)*(undefined8 *)(lVar1 + 0x18),(char)param_1,param_2);
  }
  *(undefined1 *)(lVar1 + 0x144) = 1;
  return 0;
}



===== PDO_EvtQueueInternalDeviceControl @ 1400038f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PDO_EvtQueueInternalDeviceControl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               uint param_5)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined *puVar5;
  
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar4,PTR__WDF_PDO_CONTEXT_TYPE_INFO_14000c040);
  uVar4 = *(undefined8 *)(lVar2 + 0x18);
  puVar5 = PTR__WDF_FDO_CONTEXT_TYPE_INFO_14000c0e0;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,puVar5,0x3b,
                      &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)param_5);
  }
  if (param_5 < 0xb002c) {
    if (param_5 == 0xb002b) {
      if (*(char *)(lVar3 + 4) == '\0') goto LAB_140003afe;
      iVar1 = PDO_ProcessIdleNotificationRequest(lVar2,param_2);
    }
    else if (param_5 == 0xb0003) {
      iVar1 = PDO_GetHidDescriptor(lVar2,param_2);
    }
    else if (param_5 == 0xb0007) {
      iVar1 = PDO_GetReportDescriptor(lVar2,param_2);
    }
    else if (param_5 == 0xb000b) {
      iVar1 = ReadReportLoop_ProcessHidClientRequest((ulonglong *)(lVar2 + 200),param_2);
    }
    else {
      if (param_5 == 0xb000f) goto LAB_140003b39;
      if (param_5 == 0xb0013) {
        uVar4 = PDO_GetString(4,param_2,puVar5);
        iVar1 = (int)uVar4;
      }
      else {
        if (((param_5 == 0xb001f) || (param_5 == 0xb0023)) || (param_5 != 0xb0027))
        goto LAB_140003afe;
        iVar1 = PDO_GetDeviceAttributes(lVar2,param_2);
      }
    }
  }
  else if ((param_5 == 0xb0191) || (param_5 == 0xb0192)) {
LAB_140003b39:
    iVar1 = PullRequestLoop_ProcessHidClientRequest
                      ((longlong *)(lVar2 + 0x108),param_2,(ulonglong)param_5);
  }
  else {
    if ((param_5 != 0xb0195) && (param_5 != 0xb019a)) {
      if (param_5 == 0xb01a2) goto LAB_140003b39;
      if ((param_5 != 0xb01e2) && (param_5 == 0xb0233)) {
        uVar4 = *(undefined8 *)(lVar2 + 0x28);
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x8c8))(WdfDriverGlobals,param_2);
        if (iVar1 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140003b6e;
          WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar4,0x36,
                            &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)iVar1);
        }
        else {
          iVar1 = 0x103;
        }
        goto LAB_140003b4d;
      }
    }
LAB_140003afe:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    iVar1 = -0x3fffff45;
  }
LAB_140003b4d:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_Ld(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
LAB_140003b6e:
  if (iVar1 != 0x103) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  }
  return;
}



===== PDO_EvtQueueIoStop @ 140003bc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140003c2e) */
/* WARNING: Removing unreachable block (ram,0x000140003c3c) */
/* WARNING: Removing unreachable block (ram,0x000140003c42) */
/* WARNING: Removing unreachable block (ram,0x000140003c72) */

void PDO_EvtQueueIoStop(undefined8 param_1,undefined8 param_2,uint param_3)

{
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals);
  return;
}



===== PDO_GetDeviceAttributes @ 140003ce8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PDO_GetDeviceAttributes(longlong param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 *local_res18 [2];
  
  local_res18[0] = (undefined4 *)0x0;
  uVar2 = 0x20;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0x20,local_res18,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar2,0x33,
                         &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)param_2,(char)iVar1)
      ;
    }
  }
  else {
    *local_res18[0] = 0x20;
    *(undefined2 *)(local_res18[0] + 1) = *(undefined2 *)(param_1 + 0x38);
    *(undefined2 *)((longlong)local_res18[0] + 6) = *(undefined2 *)(param_1 + 0x3a);
    *(undefined2 *)(local_res18[0] + 2) = *(undefined2 *)(param_1 + 0x3c);
    (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,0x20);
  }
  return iVar1;
}



===== PDO_GetHidDescriptor @ 140003de4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PDO_GetHidDescriptor(longlong param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 *local_res18 [2];
  
  local_res18[0] = (undefined1 *)0x0;
  uVar2 = 9;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,9,local_res18,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar2,0x34,
                         &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)param_2,(char)iVar1)
      ;
    }
  }
  else {
    *local_res18[0] = 9;
    local_res18[0][1] = 0x21;
    *(undefined2 *)(local_res18[0] + 2) = 1;
    local_res18[0][4] = 0;
    local_res18[0][5] = 1;
    local_res18[0][6] = 0x22;
    *(undefined2 *)(local_res18[0] + 7) = *(undefined2 *)(param_1 + 0x54);
    (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,9);
  }
  return iVar1;
}



===== PDO_GetMaxInputReportLength @ 140003ef4 =====

void PDO_GetMaxInputReportLength(longlong param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  ulonglong uVar4;
  
  if (*(uint *)(param_1 + 0x98) != 0) {
    uVar4 = (ulonglong)*(uint *)(param_1 + 0x98);
    puVar3 = (ushort *)(*(longlong *)(param_1 + 0x90) + 2);
    uVar1 = 0;
    do {
      uVar2 = *puVar3;
      puVar3 = puVar3 + 4;
      if (uVar2 <= uVar1) {
        uVar2 = uVar1;
      }
      uVar4 = uVar4 - 1;
      uVar1 = uVar2;
    } while (uVar4 != 0);
  }
  return;
}



===== PDO_GetMaxReportBufferLength @ 140003f30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ushort PDO_GetMaxReportBufferLength(undefined8 param_1)

{
  ushort uVar1;
  longlong lVar2;
  ushort uVar3;
  ushort *puVar4;
  ushort uVar5;
  ulonglong uVar6;
  
  uVar5 = 0;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_PDO_CONTEXT_TYPE_INFO_14000c040);
  if (*(uint *)(lVar2 + 0x98) != 0) {
    uVar6 = (ulonglong)*(uint *)(lVar2 + 0x98);
    puVar4 = (ushort *)(*(longlong *)(lVar2 + 0x90) + 4);
    do {
      uVar1 = puVar4[-1];
      if (puVar4[-1] <= uVar5) {
        uVar1 = uVar5;
      }
      uVar3 = *puVar4;
      if (*puVar4 <= uVar1) {
        uVar3 = uVar1;
      }
      uVar5 = puVar4[1];
      if (puVar4[1] <= uVar3) {
        uVar5 = uVar3;
      }
      uVar6 = uVar6 - 1;
      puVar4 = puVar4 + 4;
    } while (uVar6 != 0);
  }
  return uVar5;
}



===== PDO_GetReportDescriptor @ 140003fb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PDO_GetReportDescriptor(longlong param_1,undefined8 param_2)

{
  ushort uVar1;
  int iVar2;
  ulonglong uVar3;
  void *local_res8;
  
  uVar1 = *(ushort *)(param_1 + 0x54);
  local_res8 = (void *)0x0;
  uVar3 = (ulonglong)uVar1;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,uVar3,&local_res8,0);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar3,0x35,
                        &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)iVar2);
    }
  }
  else {
    memcpy(local_res8,*(void **)(param_1 + 0x58),(ulonglong)uVar1);
    (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,(ulonglong)uVar1);
  }
  return iVar2;
}



===== PDO_GetString @ 14000408c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 PDO_GetString(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  ulonglong _Size;
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  wchar_t *_Src;
  undefined8 uVar4;
  longlong lVar5;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals);
  uVar1 = *(uint *)(*(longlong *)(lVar2 + 0xb8) + 0x20);
  uVar3 = uVar1 & 0xffff;
  if (uVar3 == 0xe) {
    _Src = L"Microsoft";
  }
  else if (uVar3 == 0xf) {
    _Src = L"HID VHF Driver";
  }
  else {
    if (uVar3 != 0x10) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_3,0x31,
                          &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)uVar1);
      }
      return 0xc000000d;
    }
    _Src = L"1.0";
  }
  lVar5 = -1;
  uVar4 = 0;
  do {
    lVar5 = lVar5 + 1;
  } while (_Src[lVar5] != L'\0');
  _Size = lVar5 * 2 + 2;
  if (*(uint *)(*(longlong *)(lVar2 + 0xb8) + 8) < _Size) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_PP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    uVar4 = 0xc0000023;
  }
  else {
    memcpy(*(void **)(lVar2 + 0x70),_Src,_Size);
    *(ulonglong *)(lVar2 + 0x38) = _Size;
  }
  return uVar4;
}



===== PDO_IdleCallbackWorkitem @ 1400041b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PDO_IdleCallbackWorkitem(undefined8 param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined2 uVar4;
  undefined8 *local_res10;
  undefined1 uVar5;
  undefined1 uVar6;
  int iVar7;
  
  local_res10 = (undefined8 *)0x0;
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,
                      PTR__WDF_PDO_IDLE_CALLBACK_WORKITEM_CONTEXT_TYPE_INFO_14000c018);
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*puVar1,PTR__WDF_PDO_CONTEXT_TYPE_INFO_14000c040);
  uVar3 = 0x10;
  iVar7 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,puVar1[1],0x10,&local_res10,0);
  if (iVar7 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar6 = (undefined1)puVar1[1];
      uVar4 = 0x37;
      uVar5 = (undefined1)*puVar1;
LAB_14000430f:
      WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar3,uVar4,
                          &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,uVar5,uVar6,(char)iVar7);
    }
  }
  else if ((code *)*local_res10 == (code *)0x0) {
    iVar7 = -0x3ffffff3;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar4 = 0x38;
      iVar7 = -0x3ffffff3;
LAB_1400042fe:
      uVar6 = (undefined1)puVar1[1];
      uVar5 = (undefined1)*puVar1;
      goto LAB_14000430f;
    }
  }
  else {
    (*(code *)*local_res10)(local_res10[1]);
    uVar3 = *(undefined8 *)(lVar2 + 0x30);
    iVar7 = (**(code **)(WdfFunctions_01015 + 0x8c8))(WdfDriverGlobals,puVar1[1]);
    if (-1 < iVar7) goto LAB_14000434e;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar4 = 0x39;
      goto LAB_1400042fe;
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,puVar1[1],iVar7);
LAB_14000434e:
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_1);
  return;
}



===== PDO_IndicateWakeStatus @ 140004388 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PDO_IndicateWakeStatus(longlong param_1,undefined8 param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  int iVar3;
  undefined8 uVar4;
  undefined2 uVar5;
  longlong local_res18;
  
  local_res18 = 0;
  uVar4 = 0x10;
  iVar3 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0x10,&local_res18,0);
  if (iVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar3;
    }
    WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar4,0x4f,
                       &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)param_2,(char)iVar3);
    return iVar3;
  }
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
  plVar1 = (longlong *)(param_1 + 0x28);
  plVar2 = (longlong *)*plVar1;
  if (plVar2 == plVar1) {
    iVar3 = -0x3fffffff;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140004528;
    uVar5 = 0x50;
  }
  else {
    if ((longlong *)*plVar2 == plVar1) {
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x2b0))
                        (WdfDriverGlobals,plVar2[2],*(undefined4 *)(local_res18 + 8));
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqqdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      goto LAB_140004528;
    }
    iVar3 = -0x3fffffff;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140004528;
    uVar5 = 0x51;
  }
  iVar3 = -0x3fffffff;
  WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar4,uVar5,
                     &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)param_2,1);
LAB_140004528:
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
  return iVar3;
}



===== PDO_ProcessIdleNotificationRequest @ 140004564 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PDO_ProcessIdleNotificationRequest(longlong param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 *puVar2;
  undefined4 *puVar3;
  undefined8 local_res8;
  undefined8 local_58;
  code *pcStack_50;
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
  
  local_res8 = 0;
  puVar3 = &local_40;
  local_2c = 0;
  local_18 = 0;
  local_10 = PTR__WDF_PDO_IDLE_CALLBACK_WORKITEM_CONTEXT_TYPE_INFO_14000c018;
  local_20 = *(undefined8 *)(param_1 + 0x10);
  local_28 = 1;
  pcStack_50 = PDO_IdleCallbackWorkitem;
  local_24 = 1;
  local_48 = 1;
  local_3c = 0;
  uStack_34 = 0;
  local_40 = 0x38;
  local_58 = 0x18;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0xbd8))(WdfDriverGlobals,&local_58,puVar3,&local_res8);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar3,0x3a,
                          &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,
                          (char)*(undefined8 *)(param_1 + 0x10),(char)param_2,(char)iVar1);
    }
  }
  else {
    puVar2 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,local_res8,
                        PTR__WDF_PDO_IDLE_CALLBACK_WORKITEM_CONTEXT_TYPE_INFO_14000c018);
    *puVar2 = *(undefined8 *)(param_1 + 0x10);
    puVar2[1] = param_2;
    (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,local_res8);
    iVar1 = 0x103;
  }
  return iVar1;
}



===== PDO_PullRequestComplete @ 1400046cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong PDO_PullRequestComplete(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong *plVar6;
  longlong *local_res18;
  longlong local_res20;
  
  local_res18 = (longlong *)0x0;
  uVar5 = 0x28;
  local_res20 = 0;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0x28,&local_res18,0);
  uVar4 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar5,0x45,
                         &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)param_2,(char)uVar1)
      ;
    }
  }
  else {
    plVar6 = &local_res20;
    lVar3 = *local_res18;
    uVar2 = FDO_GetPdoFromVhfiHandle(param_1,lVar3,plVar6);
    uVar4 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqid
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar3,plVar6,0x46,
                   &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,
                   (char)*(undefined8 *)(param_1 + 8),(char)param_2,(char)*local_res18,(char)uVar2);
      }
    }
    else {
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,local_res20,PTR__WDF_PDO_CONTEXT_TYPE_INFO_14000c040);
      uVar1 = PullRequestLoop_ProcessCompletion(lVar3 + 0x108,param_2,(longlong)local_res18);
      uVar4 = (ulonglong)uVar1;
    }
  }
  return uVar4;
}



===== PDO_PullRequestNotify @ 140004824 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong PDO_PullRequestNotify(longlong param_1,undefined8 param_2,char param_3)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong *plVar6;
  longlong *local_res20;
  longlong local_18 [2];
  
  local_res20 = (longlong *)0x0;
  local_18[0] = 0;
  uVar5 = 8;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,8,&local_res20,0);
  uVar4 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar5,0x43,
                         &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)param_2,(char)uVar1)
      ;
    }
  }
  else {
    plVar6 = local_18;
    lVar3 = *local_res20;
    uVar2 = FDO_GetPdoFromVhfiHandle(param_1,lVar3,plVar6);
    uVar4 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqid
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar3,plVar6,0x44,
                   &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,
                   (char)*(undefined8 *)(param_1 + 8),(char)param_2,(char)*local_res20,(char)uVar2);
      }
    }
    else {
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,local_18[0],PTR__WDF_PDO_CONTEXT_TYPE_INFO_14000c040);
      uVar1 = PullRequestLoop_ProcessNotifyRequest((undefined8 *)(lVar3 + 0x108),param_2,param_3);
      uVar4 = (ulonglong)uVar1;
    }
  }
  return uVar4;
}



===== PDO_QueryPowerState @ 140004994 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PDO_QueryPowerState(longlong param_1,undefined8 param_2)

{
  longlong *plVar1;
  int iVar2;
  longlong *plVar3;
  int iVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  int *local_res18;
  
  local_res18 = (int *)0x0;
  uVar5 = 8;
  iVar4 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,8,&local_res18,0);
  if (iVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar4;
    }
    WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar5,0x4b,
                       &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)param_2,(char)iVar4);
    return iVar4;
  }
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
  plVar1 = (longlong *)(param_1 + 0x28);
  plVar3 = (longlong *)*plVar1;
  if (plVar3 == plVar1) {
    iVar4 = -0x3fffffff;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140004b80;
    uVar6 = 0x4c;
  }
  else {
    if ((longlong *)*plVar3 == plVar1) {
      iVar2 = *(int *)(plVar3 + 0x28);
      if ((((iVar2 == 0) || (iVar2 == 1)) || (iVar2 == 2)) || ((iVar2 == 3 || (iVar2 == 4)))) {
        *local_res18 = iVar2;
      }
      else if (iVar2 == 5) {
        *local_res18 = 4;
      }
      else {
        *local_res18 = 0;
      }
      *(undefined1 *)(local_res18 + 1) = *(undefined1 *)((longlong)plVar3 + 0x144);
      (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,8);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqqLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      goto LAB_140004b80;
    }
    iVar4 = -0x3fffffff;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140004b80;
    uVar6 = 0x4d;
  }
  iVar4 = -0x3fffffff;
  WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar5,uVar6,
                     &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)param_2,1);
LAB_140004b80:
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
  return iVar4;
}



===== PDO_ReadReportComplete @ 140004bbc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong PDO_ReadReportComplete(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong *plVar6;
  longlong *local_res18;
  longlong local_res20;
  
  local_res18 = (longlong *)0x0;
  uVar5 = 0x18;
  local_res20 = 0;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,0x18,&local_res18,0);
  uVar4 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar5,0x41,
                         &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)param_2,(char)uVar1)
      ;
    }
  }
  else {
    plVar6 = &local_res20;
    lVar3 = *local_res18;
    uVar2 = FDO_GetPdoFromVhfiHandle(param_1,lVar3,plVar6);
    uVar4 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqid
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar3,plVar6,0x42,
                   &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,
                   (char)*(undefined8 *)(param_1 + 8),(char)param_2,(char)*local_res18,(char)uVar2);
      }
    }
    else {
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,local_res20,PTR__WDF_PDO_CONTEXT_TYPE_INFO_14000c040);
      uVar4 = ReadReportLoop_ProcessCompletion
                        ((undefined8 *)(lVar3 + 200),param_2,(longlong)local_res18);
      uVar4 = uVar4 & 0xffffffff;
    }
  }
  return uVar4;
}



===== PDO_ReadReportNotify @ 140004d14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong PDO_ReadReportNotify(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong *plVar6;
  longlong *local_res18;
  longlong local_res20;
  
  local_res18 = (longlong *)0x0;
  uVar5 = 8;
  local_res20 = 0;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_2,8,&local_res18,0);
  uVar4 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar5,0x3f,
                         &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)param_2,(char)uVar1)
      ;
    }
  }
  else {
    plVar6 = &local_res20;
    lVar3 = *local_res18;
    uVar2 = FDO_GetPdoFromVhfiHandle(param_1,lVar3,plVar6);
    uVar4 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqid
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar3,plVar6,0x40,
                   &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,
                   (char)*(undefined8 *)(param_1 + 8),(char)param_2,(char)*local_res18,(char)uVar2);
      }
    }
    else {
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,local_res20,PTR__WDF_PDO_CONTEXT_TYPE_INFO_14000c040);
      uVar1 = ReadReportLoop_ProcessNotifyRequest(lVar3 + 200,param_2);
      uVar4 = (ulonglong)uVar1;
    }
  }
  return uVar4;
}



===== RtlStringCchPrintfW @ 140004e68 =====

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



===== RtlUnicodeStringInit @ 140004ee4 =====

uint RtlUnicodeStringInit(short *param_1,short *param_2)

{
  short sVar1;
  short *psVar2;
  uint uVar3;
  longlong lVar4;
  
  uVar3 = 0;
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  if (param_2 != (short *)0x0) {
    lVar4 = 0x7fff;
    psVar2 = param_2;
    do {
      if (*psVar2 == 0) break;
      psVar2 = psVar2 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    uVar3 = ~-(uint)(lVar4 != 0) & 0xc000000d;
    if (lVar4 != 0) {
      if (param_1 == (short *)0x0) {
        return 0xc000000d;
      }
      sVar1 = (0x7fff - (short)lVar4) * 2;
      *(short **)(param_1 + 4) = param_2;
      *param_1 = sVar1;
      param_1[1] = sVar1 + 2;
    }
  }
  return uVar3;
}



===== WPP_RECORDER_SF_L @ 140004f64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_L(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,4,0);
  }
  WppAutoLogTrace(param_1,4,1,param_5,param_4,&param_6,4,0);
  return;
}



===== WPP_RECORDER_SF_Ld @ 14000500c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Ld(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,0x3d,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,0x3d,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_PP @ 1400050dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_PP(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,0x32,&uStack0000000000000030,8,
               &uStack0000000000000038,8,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,0x32,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,0);
  return;
}



===== WPP_RECORDER_SF_S @ 1400051ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_S(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,wchar_t *param_6)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar4 = -1;
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (param_6 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (param_6[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = param_6;
    if (param_6 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,param_4,pwVar2,lVar1,0);
  }
  if (param_6 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (param_6[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,4,1,&WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,param_4,param_6,lVar3
                  ,0);
  return;
}



===== WPP_RECORDER_SF_Sd @ 1400052d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Sd(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  wchar_t *in_stack_00000030;
  undefined1 uStack0000000000000038;
  
  lVar4 = -1;
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000030 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000030[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000030;
    if (in_stack_00000030 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,0xf,pwVar2,lVar1,
               &uStack0000000000000038,4,0);
  }
  if (in_stack_00000030 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (in_stack_00000030[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    in_stack_00000030 = L"NULL";
  }
  WppAutoLogTrace(param_1,2,1,&WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,0xf,in_stack_00000030
                  ,lVar3,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_qqqL @ 140005428 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqqL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,0x3c,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,0x3c,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_qqqLd @ 14000553c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqqLd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,0x4e,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,&uStack0000000000000048,4,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,0x4e,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_qqqdd @ 140005678 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqqdd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,0x52,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,&uStack0000000000000048,4,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,0x52,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 1400057b4 =====

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
LAB_1400059bd:
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
LAB_14000588f:
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
      if (param_3 == 4) goto LAB_1400059bd;
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
        goto LAB_14000588f;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140005aa8 =====

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
      goto LAB_140005b6b;
    }
    if (param_3 == 2) {
      uVar2 = (uVar4 ^ 1) * 4 + 1;
      uVar3 = 0;
      goto LAB_140005b6b;
    }
    if (param_3 == 3) {
      uVar2 = (uVar4 ^ 1) * 4 + 2;
      uVar3 = 0;
      goto LAB_140005b6b;
    }
    if (param_3 == 4) {
      uVar2 = (uVar4 ^ 1) * 4 + 3;
      uVar3 = 0;
      goto LAB_140005b6b;
    }
    uVar2 = param_3 - 5;
    uVar3 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      uVar2 = (uVar4 ^ 1) * 2 + 8;
      goto LAB_140005b6b;
    }
    if (uVar2 == 1) {
      uVar2 = (uVar4 ^ 1) * 2 + 9;
      goto LAB_140005b6b;
    }
    bVar5 = (char)param_3 + 0x9c;
    if (bVar5 < 0x32) {
      uVar2 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar5;
      goto LAB_140005b6b;
    }
  }
  uVar2 = 0xff;
LAB_140005b6b:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x35cd1ef,&Feature_ValAccTest_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140005bc4 =====

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
                     (local_50,(uint *)&Feature_VHFUMA01__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)(0x35cd1ef,param_3,1,&Feature_VHFUMA01__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)param_3,0x35cd1ef);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140005cb0 =====

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
LAB_140005d63:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_140005d91;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_140005d63;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_140005d91:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140005f1c =====

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
  if ((Feature_VHFUMA01__private_featureState & 2) != 0) {
    uVar1 = Feature_VHFUMA01__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_VHFUMA01__private_featureState;
      if (bVar3) {
        Feature_VHFUMA01__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_VHFUMA01__private_featureState;
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



===== wil_details_IsEnabledFallback @ 140005f70 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_VHFUMA01__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_VHFUMA01__private_featureState,(ulonglong)param_1,0x14000b4a8)
    ;
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



===== PullRequestLoop_CompleteNotifyRequestLocked @ 140006000 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PullRequestLoop_CompleteNotifyRequestLocked(undefined8 *param_1)

{
  int iVar1;
  longlong lVar2;
  byte bVar3;
  int iVar4;
  longlong lVar5;
  longlong *plVar6;
  code *pcVar7;
  undefined2 uVar8;
  longlong lVar9;
  int iVar10;
  longlong local_res8;
  undefined8 *local_res10;
  
  local_res10 = (undefined8 *)0x0;
  lVar5 = 0;
  local_res8 = 0;
  lVar9 = 0;
  lVar2 = 0;
  iVar4 = 0;
  iVar10 = 0;
  if (param_1[5] == 0) goto LAB_140006213;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals);
  if (iVar1 < 0) goto LAB_140006213;
  plVar6 = &local_res8;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x4f0))(WdfDriverGlobals,*param_1);
  if (iVar1 < 0) {
    if ((iVar1 == -0x7fffffe6) || (iVar1 == -0x3fdffdfd)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar8 = 0x19;
        bVar3 = 3;
        goto LAB_1400061c0;
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar8 = 0x18;
      bVar3 = 2;
LAB_1400061c0:
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar3,plVar6,uVar8,
                        &WPP_f36996ce8f28378ed55beb61f79ee128_Traceguids,(char)iVar1);
    }
  }
  else {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1[5],PTR__WDF_FDO_REQUEST_CONTEXT_TYPE_INFO_14000c0b8)
    ;
    (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_1[5],0x20,&local_res10,0);
    PullRequestLoop_InitializeNotifyOutput
              (local_res8,*(void **)(lVar2 + 0x10),*(uint *)(lVar2 + 0x18),local_res10);
    pcVar7 = PullRequestLoop_EvtHidPullRequestCancel;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0xc48))(WdfDriverGlobals,local_res8);
    if (-1 < iVar1) {
      lVar5 = param_1[5];
      param_1[5] = 0;
      param_1[4] = local_res8;
      goto LAB_140006213;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,pcVar7,0x17,
                         &WPP_f36996ce8f28378ed55beb61f79ee128_Traceguids,(char)local_res8,
                         (char)iVar1);
    }
    lVar9 = local_res8;
    iVar10 = iVar1;
  }
  iVar1 = (**(code **)(WdfFunctions_01015 + 0xc48))
                    (WdfDriverGlobals,param_1[5],PullRequestLoop_EvtNotifyRequestCancel);
  if (iVar1 < 0) {
    lVar5 = param_1[5];
    param_1[5] = 0;
    iVar4 = iVar1;
  }
LAB_140006213:
  KeReleaseSpinLock(param_1 + 2,*(undefined1 *)(param_1 + 3));
  if (lVar5 != 0) {
    if ((lVar2 != 0) && (*(longlong *)(lVar2 + 8) != 0)) {
      MmUnlockPages();
      IoFreeMdl(*(undefined8 *)(lVar2 + 8));
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,lVar5,iVar4);
  }
  if (lVar9 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,lVar9,iVar10);
  }
  return;
}



===== PullRequestLoop_EvtHidPullRequestCancel @ 1400062c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PullRequestLoop_EvtHidPullRequestCancel(undefined8 param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  longlong *plVar3;
  undefined *puVar4;
  
  puVar4 = PTR__WDF_PDO_REQUEST_CONTEXT_TYPE_INFO_14000c068;
  plVar3 = (longlong *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  lVar1 = *plVar3;
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x10);
  *(undefined8 *)(lVar1 + 0x20) = 0;
  *(undefined1 *)(lVar1 + 0x18) = uVar2;
  KeReleaseSpinLock(lVar1 + 0x10,uVar2);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar4,0x1c,
                      &WPP_f36996ce8f28378ed55beb61f79ee128_Traceguids,(char)param_1);
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,0xc0000120);
  return;
}



===== PullRequestLoop_EvtHidPullRequestQueueIoStop @ 1400063a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PullRequestLoop_EvtHidPullRequestQueueIoStop(undefined8 param_1,longlong param_2,int param_3)

{
  bool bVar1;
  undefined1 uVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined *puVar6;
  
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  puVar6 = PTR__WDF_PDO_CONTEXT_TYPE_INFO_14000c040;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar4);
  if (param_3 == 2) {
    uVar2 = KeAcquireSpinLockRaiseToDpc(lVar5 + 0x118);
    *(undefined1 *)(lVar5 + 0x120) = uVar2;
    bVar1 = false;
    if (param_2 == *(longlong *)(lVar5 + 0x128)) {
      *(undefined8 *)(lVar5 + 0x128) = 0;
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals,param_2);
      bVar1 = false;
      if (-1 < iVar3) {
        bVar1 = true;
      }
    }
    KeReleaseSpinLock(lVar5 + 0x118,*(undefined1 *)(lVar5 + 0x120));
    if (bVar1) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar6,0x1a,
                           &WPP_f36996ce8f28378ed55beb61f79ee128_Traceguids,(char)param_2,0xc0);
      }
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc00000c0);
      return;
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  (**(code **)(WdfFunctions_01015 + 0x8e0))(WdfDriverGlobals,param_2,0);
  return;
}



===== PullRequestLoop_EvtNotifyRequestCancel @ 140006560 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PullRequestLoop_EvtNotifyRequestCancel(undefined8 param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  longlong *plVar3;
  undefined *puVar4;
  
  puVar4 = PTR__WDF_FDO_REQUEST_CONTEXT_TYPE_INFO_14000c0b8;
  plVar3 = (longlong *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  lVar1 = *plVar3;
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x10);
  *(undefined8 *)(lVar1 + 0x28) = 0;
  *(undefined1 *)(lVar1 + 0x18) = uVar2;
  KeReleaseSpinLock(lVar1 + 0x10,uVar2);
  if (plVar3[1] != 0) {
    MmUnlockPages();
    IoFreeMdl(plVar3[1]);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar4,0x10,
                      &WPP_f36996ce8f28378ed55beb61f79ee128_Traceguids,(char)param_1);
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,0xc0000120);
  return;
}



===== PullRequestLoop_HidPullRequestQueueReadyNotification @ 140006670 =====

void PullRequestLoop_HidPullRequestQueueReadyNotification(undefined8 param_1,undefined8 *param_2)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_2 + 2);
  *(undefined1 *)(param_2 + 3) = uVar1;
  PullRequestLoop_CompleteNotifyRequestLocked(param_2);
  return;
}



===== PullRequestLoop_Initialize @ 1400066a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PullRequestLoop_Initialize
              (undefined8 *param_1,undefined8 param_2,undefined4 param_3,undefined2 param_4)

{
  int iVar1;
  code *pcVar2;
  undefined2 uVar3;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  code *local_30;
  
  *(undefined4 *)(param_1 + 1) = param_3;
  *(undefined2 *)((longlong)param_1 + 0xc) = param_4;
  KeInitializeSpinLock(param_1 + 2);
  if ((*(uint *)(param_1 + 1) & 0x1e) == 0) {
    iVar1 = 0;
  }
  else {
    memset(&local_68,0,0x60);
    local_30 = PullRequestLoop_EvtHidPullRequestQueueIoStop;
    pcVar2 = (code *)&local_68;
    local_68 = 0x60;
    local_60 = 2;
    local_64 = 3;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x4c0))(WdfDriverGlobals,param_2,pcVar2,0,param_1);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      uVar3 = 10;
    }
    else {
      pcVar2 = PullRequestLoop_HidPullRequestQueueReadyNotification;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x530))
                        (WdfDriverGlobals,*param_1,
                         PullRequestLoop_HidPullRequestQueueReadyNotification,param_1);
      if (-1 < iVar1) {
        return iVar1;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      uVar3 = 0xb;
    }
    WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pcVar2,uVar3,
                       &WPP_f36996ce8f28378ed55beb61f79ee128_Traceguids,(char)param_2,(char)iVar1);
  }
  return iVar1;
}



===== PullRequestLoop_InitializeNotifyOutput @ 1400067e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PullRequestLoop_InitializeNotifyOutput
               (undefined8 param_1,void *param_2,uint param_3,undefined8 *param_4)

{
  uint uVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  
  plVar4 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_PDO_REQUEST_CONTEXT_TYPE_INFO_14000c068);
  *param_4 = param_1;
  *(int *)(param_4 + 1) = (int)plVar4[1];
  puVar3 = (undefined8 *)plVar4[2];
  *(undefined1 *)(param_4 + 2) = *(undefined1 *)((longlong)puVar3 + 0xc);
  uVar1 = *(uint *)(puVar3 + 1);
  *(uint *)((longlong)param_4 + 0x14) = uVar1;
  iVar2 = (int)plVar4[1];
  if (iVar2 == 2) {
LAB_140006872:
    if (*(uint *)(puVar3 + 1) <= param_3) {
      memcpy(param_2,(void *)*puVar3,(ulonglong)*(uint *)(puVar3 + 1));
    }
  }
  else {
    if (iVar2 != 4) {
      if (iVar2 == 8) goto LAB_140006872;
      if (iVar2 != 0x10) {
        return;
      }
    }
    if (*(ushort *)(*plVar4 + 0xc) < uVar1) {
      *(uint *)((longlong)param_4 + 0x14) = (uint)*(ushort *)(*plVar4 + 0xc);
    }
  }
  return;
}



===== PullRequestLoop_ProcessCompletion @ 1400068a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PullRequestLoop_ProcessCompletion(longlong param_1,undefined8 param_2,longlong param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  char cVar4;
  int iVar5;
  longlong lVar6;
  ulonglong uVar7;
  void *_Src;
  undefined4 uVar8;
  longlong lVar9;
  
  lVar9 = 0;
  uVar8 = 0;
  lVar1 = param_1 + 0x10;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
  *(undefined1 *)(param_1 + 0x18) = uVar3;
  lVar6 = *(longlong *)(param_1 + 0x20);
  if (*(longlong *)(param_3 + 8) != lVar6) {
    KeReleaseSpinLock(lVar1,CONCAT71((int7)((ulonglong)lVar6 >> 8),uVar3));
    iVar5 = -0x3ffffff0;
    goto LAB_140006a94;
  }
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,lVar6,PTR__WDF_PDO_REQUEST_CONTEXT_TYPE_INFO_14000c068);
  KeReleaseSpinLock(lVar1,*(undefined1 *)(param_1 + 0x18));
  iVar5 = *(int *)(lVar6 + 8);
  if (iVar5 == 2) {
LAB_140006a5e:
    uVar8 = *(undefined4 *)(*(longlong *)(lVar6 + 0x10) + 8);
LAB_140006a65:
    uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
    *(undefined1 *)(param_1 + 0x18) = uVar3;
    lVar9 = *(longlong *)(param_1 + 0x20);
    *(undefined8 *)(param_1 + 0x20) = 0;
    KeReleaseSpinLock(lVar1,uVar3);
    iVar5 = 0;
  }
  else {
    if (iVar5 == 4) {
LAB_140006966:
      puVar2 = *(undefined8 **)(lVar6 + 0x10);
      if (*(uint *)(param_3 + 0x14) <= *(uint *)(puVar2 + 1)) {
        cVar4 = (**(code **)(WdfFunctions_01015 + 0x818))(WdfDriverGlobals,param_2);
        if (cVar4 == '\0') {
          _Src = *(void **)(param_3 + 0x18);
        }
        else {
          _Src = (void *)(ulonglong)*(uint *)(param_3 + 0x18);
        }
        uVar7 = Feature_VHFUMA01__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar7 == 0) {
          (**(code **)(WdfFunctions_01015 + 0x8c0))(WdfDriverGlobals,param_2);
          memcpy((void *)*puVar2,_Src,(ulonglong)*(uint *)(param_3 + 0x14));
        }
        else {
          cVar4 = (**(code **)(WdfFunctions_01015 + 0x8c0))(WdfDriverGlobals,param_2);
          if (cVar4 == '\0') {
            RtlpCopyDeviceMemory((void *)*puVar2,_Src,(ulonglong)*(uint *)(param_3 + 0x14));
          }
          else {
            RtlCopyFromUser((void *)*puVar2,_Src,(ulonglong)*(uint *)(param_3 + 0x14));
          }
        }
        uVar8 = *(undefined4 *)(param_3 + 0x14);
        goto LAB_140006a65;
      }
    }
    else {
      if (iVar5 == 8) goto LAB_140006a5e;
      if (iVar5 == 0x10) goto LAB_140006966;
    }
    iVar5 = -0x3ffffff3;
  }
LAB_140006a94:
  if ((lVar9 != 0) &&
     (iVar5 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals,lVar9), -1 < iVar5)) {
    (**(code **)(WdfFunctions_01015 + 0x848))
              (WdfDriverGlobals,lVar9,*(undefined4 *)(param_3 + 0x20),uVar8);
  }
  return iVar5;
}



===== PullRequestLoop_ProcessHidClientRequest @ 140006afc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PullRequestLoop_ProcessHidClientRequest(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  uint uVar3;
  undefined2 uVar4;
  undefined1 auStackY_88 [32];
  undefined1 uVar5;
  int iVar6;
  undefined8 local_48;
  ulonglong uStack_40;
  ulonglong local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_88;
  local_28 = 0;
  iVar6 = (int)param_3;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (iVar6 == 0xb000f) {
    uVar3 = 2;
  }
  else if (iVar6 == 0xb0191) {
    uVar3 = 8;
  }
  else if (iVar6 == 0xb0192) {
    uVar3 = 4;
  }
  else {
    if (iVar6 != 0xb01a2) {
      return -0x3fffff45;
    }
    uVar3 = 0x10;
  }
  uVar5 = (undefined1)param_2;
  if ((*(uint *)(param_1 + 1) & uVar3) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_3,0x11,
                         &WPP_f36996ce8f28378ed55beb61f79ee128_Traceguids,uVar5,(char)param_3);
    }
    return -0x3fffff45;
  }
  puVar2 = &local_48;
  local_48 = 0x28;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals);
  if (uVar3 == 2) {
LAB_140006c50:
    if (local_38 < 0x10) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3fffffdd;
      }
      uVar4 = 0x13;
      iVar6 = -0x3fffffdd;
      goto LAB_140006c7d;
    }
  }
  else if (uVar3 == 4) {
LAB_140006bfc:
    if (uStack_40 < 0x10) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3fffffdd;
      }
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar2,0x12,
                        &WPP_f36996ce8f28378ed55beb61f79ee128_Traceguids,0x23);
      return -0x3fffffdd;
    }
  }
  else {
    if (uVar3 == 8) goto LAB_140006c50;
    if (uVar3 == 0x10) goto LAB_140006bfc;
  }
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
  lVar1 = *(longlong *)(lVar1 + 0x70);
  if (lVar1 == 0) {
    iVar6 = -0x3ffffff0;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3ffffff0;
    }
    uVar4 = 0x14;
  }
  else {
    puVar2 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,param_2,PTR__WDF_PDO_REQUEST_CONTEXT_TYPE_INFO_14000c068);
    *puVar2 = param_1;
    *(uint *)(puVar2 + 1) = uVar3;
    puVar2[2] = lVar1;
    puVar2 = (undefined8 *)*param_1;
    iVar6 = (**(code **)(WdfFunctions_01015 + 0x8c8))(WdfDriverGlobals,param_2);
    if (-1 < iVar6) {
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar2,0x16,
                          &WPP_f36996ce8f28378ed55beb61f79ee128_Traceguids,uVar5);
      }
      return 0x103;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar6;
    }
    uVar4 = 0x15;
  }
LAB_140006c7d:
  WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar2,uVar4,
                     &WPP_f36996ce8f28378ed55beb61f79ee128_Traceguids,uVar5,(char)iVar6);
  return iVar6;
}



===== PullRequestLoop_ProcessNotifyRequest @ 140006dcc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int PullRequestLoop_ProcessNotifyRequest(undefined8 *param_1,undefined8 param_2,char param_3)

{
  bool bVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  undefined8 *puVar5;
  longlong lVar6;
  longlong lVar7;
  ulonglong uVar8;
  byte bVar9;
  undefined8 *puVar10;
  code *pcVar11;
  undefined2 uVar12;
  ulonglong uVar13;
  undefined8 in_stack_ffffffffffffff90;
  undefined4 uVar14;
  undefined8 local_48;
  undefined8 *local_40;
  longlong local_38;
  
  uVar14 = (undefined4)((ulonglong)in_stack_ffffffffffffff90 >> 0x20);
  local_40 = (undefined8 *)0x0;
  lVar6 = 0;
  bVar1 = false;
  local_48 = 0;
  puVar5 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_2,PTR__WDF_FDO_REQUEST_CONTEXT_TYPE_INFO_14000c0b8);
  pcVar11 = (code *)0x20;
  iVar4 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0x20,&local_40,0);
  puVar10 = local_40;
  if (iVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000717a;
    uVar12 = 0xc;
    bVar9 = 2;
    bVar1 = false;
LAB_140006e6b:
    WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar9,pcVar11,uVar12,
                       &WPP_f36996ce8f28378ed55beb61f79ee128_Traceguids,(char)param_2,(char)iVar4);
  }
  else {
    if (param_3 == '\0') {
      lVar6 = puVar5[1];
    }
    else {
      if (*(uint *)((longlong)local_40 + 0x14) < (uint)*(ushort *)((longlong)param_1 + 0xc)) {
        iVar4 = -0x3fffffdd;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qDDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
        goto LAB_14000717a;
      }
      cVar2 = (**(code **)(WdfFunctions_01015 + 0x8c0))(WdfDriverGlobals,param_2);
      if (cVar2 == '\x01') {
        cVar2 = (**(code **)(WdfFunctions_01015 + 0x818))(WdfDriverGlobals,param_2);
        if (cVar2 == '\0') {
          uVar8 = puVar10[3];
        }
        else {
          uVar8 = (ulonglong)*(uint *)(puVar10 + 3);
        }
        uVar13 = 0;
        lVar6 = IoAllocateMdl(uVar8,*(undefined4 *)((longlong)puVar10 + 0x14),0,0,0);
        local_38 = lVar6;
        if (lVar6 != 0) {
          MmProbeAndLockPages(lVar6,1);
          if ((*(byte *)(lVar6 + 10) & 5) == 0) {
            lVar7 = MmMapLockedPagesSpecifyCache
                              (lVar6,0,1,0,uVar13 & 0xffffffff00000000,CONCAT44(uVar14,0x40000010));
          }
          else {
            lVar7 = *(longlong *)(lVar6 + 0x18);
          }
          if (lVar7 != 0) goto LAB_140006fec;
        }
        iVar4 = -0x3fffff66;
        goto LAB_14000717a;
      }
      lVar7 = puVar10[3];
LAB_140006fec:
      *puVar5 = param_1;
      puVar5[1] = lVar6;
      puVar5[2] = lVar7;
      *(undefined4 *)(puVar5 + 3) = *(undefined4 *)((longlong)puVar10 + 0x14);
    }
    uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 2);
    *(undefined1 *)(param_1 + 3) = uVar3;
    bVar1 = true;
    while( true ) {
      puVar10 = &local_48;
      iVar4 = (**(code **)(WdfFunctions_01015 + 0x4f0))(WdfDriverGlobals,*param_1);
      if (iVar4 < 0) break;
      iVar4 = (**(code **)(WdfFunctions_01015 + 0xc48))
                        (WdfDriverGlobals,local_48,PullRequestLoop_EvtHidPullRequestCancel);
      if (-1 < iVar4) {
        param_1[4] = local_48;
        PullRequestLoop_InitializeNotifyOutput
                  (local_48,(void *)puVar5[2],*(uint *)(puVar5 + 3),local_40);
        goto LAB_14000717a;
      }
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,local_48,0xc0000120);
      local_48 = 0;
    }
    if ((iVar4 != -0x7fffffe6) && (iVar4 != -0x3fdffdfd)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar10,0xe,
                          &WPP_f36996ce8f28378ed55beb61f79ee128_Traceguids,(char)iVar4);
      }
      goto LAB_14000717a;
    }
    if (*(char *)((longlong)param_1 + 0x19) != '\0') {
      iVar4 = -0x3fffff40;
      goto LAB_14000717a;
    }
    if (param_3 == '\0') {
      pcVar11 = PullRequestLoop_EvtNotifyRequestCancel;
      iVar4 = (**(code **)(WdfFunctions_01015 + 0xc48))(WdfDriverGlobals,param_2);
      if (iVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000717a;
        uVar12 = 0xf;
        bVar9 = 4;
        goto LAB_140006e6b;
      }
      param_1[5] = param_2;
    }
    iVar4 = 0x103;
  }
LAB_14000717a:
  if (bVar1) {
    KeReleaseSpinLock(param_1 + 2,*(undefined1 *)(param_1 + 3));
  }
  if ((iVar4 != 0x103) && (lVar6 != 0)) {
    MmUnlockPages(lVar6);
    IoFreeMdl(lVar6);
  }
  return iVar4;
}



===== WPP_RECORDER_SF_qD @ 1400071e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f36996ce8f28378ed55beb61f79ee128_Traceguids,0x1b,&uStack0000000000000030,8,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_f36996ce8f28378ed55beb61f79ee128_Traceguids,0x1b,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_qDDd @ 1400072b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDDd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined4 local_18 [4];
  
  local_18[0] = 0xc0000023;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f36996ce8f28378ed55beb61f79ee128_Traceguids,0xd,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,local_18,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_f36996ce8f28378ed55beb61f79ee128_Traceguids,0xd,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  local_18,4,0);
  return;
}



===== ReadReportLoop_CompleteLocked @ 1400073d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ReadReportLoop_CompleteLocked(undefined8 *param_1)

{
  int iVar1;
  undefined8 *puVar2;
  uint uVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong local_res8;
  
  plVar5 = &local_res8;
  local_res8 = 0;
  uVar3 = 0;
  lVar4 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x4f0))(WdfDriverGlobals,*param_1);
  if (-1 < iVar1) {
    uVar3 = *(uint *)(param_1 + 6);
    puVar2 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,local_res8,PTR__WDF_PDO_REQUEST_CONTEXT_TYPE_INFO_14000c068
                       );
    memcpy((void *)*puVar2,(void *)param_1[5],(ulonglong)uVar3);
    plVar5 = (longlong *)(ulonglong)uVar3;
    (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,local_res8);
    param_1[5] = 0;
    if (param_1[7] != 0) {
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals);
      if (-1 < iVar1) {
        lVar4 = param_1[7];
        param_1[7] = 0;
      }
    }
  }
  KeReleaseSpinLock(param_1 + 3,*(undefined1 *)(param_1 + 4));
  if (local_res8 != 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),local_res8,plVar5,0x12,
                        &WPP_048ee849bf123881ed4e7e767abd50df_Traceguids,(char)uVar3);
    }
    plVar5 = (longlong *)0x0;
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,local_res8);
  }
  if (lVar4 != 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,plVar5,0x13,
                       &WPP_048ee849bf123881ed4e7e767abd50df_Traceguids);
    }
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,lVar4,0);
  }
  return;
}



===== ReadReportLoop_EvtNotifyRequestCancel @ 140007590 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ReadReportLoop_EvtNotifyRequestCancel(undefined8 param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  longlong *plVar3;
  
  plVar3 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_FDO_REQUEST_CONTEXT_TYPE_INFO_14000c0b8);
  lVar1 = *plVar3;
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x18);
  *(undefined8 *)(lVar1 + 0x38) = 0;
  *(undefined1 *)(lVar1 + 0x20) = uVar2;
  KeReleaseSpinLock(lVar1 + 0x18,uVar2);
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,0xc0000120);
  return;
}



===== ReadReportLoop_HidClientReportReadyNotification @ 140007630 =====

void ReadReportLoop_HidClientReportReadyNotification(undefined8 param_1,undefined8 *param_2)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_2 + 3);
  *(undefined1 *)(param_2 + 4) = uVar1;
  if (param_2[5] == 0) {
    KeReleaseSpinLock(param_2 + 3,uVar1);
  }
  else {
    ReadReportLoop_CompleteLocked(param_2);
  }
  return;
}



===== ReadReportLoop_Initialize @ 140007688 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ReadReportLoop_Initialize(undefined8 *param_1,undefined8 param_2,undefined2 param_3)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined2 uVar5;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined1 local_5c [84];
  
  *(undefined2 *)(param_1 + 1) = param_3;
  uVar3 = 0x44464856;
  lVar2 = ExAllocatePool2(0x40);
  param_1[2] = lVar2;
  if (lVar2 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar3,10,
                        &WPP_048ee849bf123881ed4e7e767abd50df_Traceguids,(char)param_2);
    }
    iVar1 = -0x3fffff66;
  }
  else {
    KeInitializeSpinLock(param_1 + 3);
    memset(local_5c,0,0x54);
    pcVar4 = (code *)&local_68;
    local_68 = 0x60;
    local_60 = 2;
    local_64 = 3;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x4c0))(WdfDriverGlobals,param_2,pcVar4,0,param_1);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      uVar5 = 0xb;
    }
    else {
      pcVar4 = ReadReportLoop_HidClientReportReadyNotification;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x530))
                        (WdfDriverGlobals,*param_1,ReadReportLoop_HidClientReportReadyNotification,
                         param_1);
      if (-1 < iVar1) {
        return iVar1;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar1;
      }
      uVar5 = 0xc;
    }
    WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pcVar4,uVar5,
                       &WPP_048ee849bf123881ed4e7e767abd50df_Traceguids,(char)param_2,(char)iVar1);
  }
  return iVar1;
}



===== ReadReportLoop_ProcessCompletion @ 140007814 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 ReadReportLoop_ProcessCompletion(undefined8 *param_1,undefined8 param_2,longlong param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  uint uVar3;
  bool bVar4;
  undefined1 uVar5;
  char cVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  void *_Src;
  
  puVar1 = param_1 + 3;
  uVar5 = KeAcquireSpinLockRaiseToDpc(puVar1);
  puVar2 = param_1 + 4;
  *(undefined1 *)puVar2 = uVar5;
  bVar4 = true;
  if (*(char *)((longlong)param_1 + 0x21) == '\0') {
    if ((uint)*(ushort *)(param_1 + 1) < *(uint *)(param_3 + 0xc)) {
      uVar8 = 0xc000000d;
    }
    else {
      KeReleaseSpinLock(puVar1,uVar5);
      bVar4 = false;
      cVar6 = (**(code **)(WdfFunctions_01015 + 0x818))(WdfDriverGlobals,param_2);
      if (cVar6 == '\0') {
        _Src = *(void **)(param_3 + 0x10);
      }
      else {
        _Src = (void *)(ulonglong)*(uint *)(param_3 + 0x10);
      }
      uVar3 = *(uint *)(param_3 + 0xc);
      uVar7 = Feature_VHFUMA01__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar7 == 0) {
        (**(code **)(WdfFunctions_01015 + 0x8c0))(WdfDriverGlobals,param_2);
        uVar7 = (ulonglong)uVar3;
        memcpy((void *)param_1[2],_Src,uVar7);
      }
      else {
        cVar6 = (**(code **)(WdfFunctions_01015 + 0x8c0))(WdfDriverGlobals,param_2);
        uVar7 = (ulonglong)uVar3;
        if (cVar6 == '\0') {
          RtlpCopyDeviceMemory((void *)param_1[2],_Src,uVar7);
        }
        else {
          RtlCopyFromUser((void *)param_1[2],_Src,uVar7);
        }
      }
      uVar5 = KeAcquireSpinLockRaiseToDpc(puVar1);
      *(undefined1 *)puVar2 = uVar5;
      if ((param_1[5] != 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
         ) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,uVar7,0x11,
                         &WPP_048ee849bf123881ed4e7e767abd50df_Traceguids);
      }
      param_1[5] = param_1[2];
      *(uint *)(param_1 + 6) = uVar3;
      ReadReportLoop_CompleteLocked(param_1);
      uVar8 = 0;
    }
  }
  else {
    uVar8 = 0xc00000c0;
  }
  if (bVar4) {
    KeReleaseSpinLock(puVar1,*(undefined1 *)puVar2);
  }
  return uVar8;
}



===== ReadReportLoop_ProcessHidClientRequest @ 140007a00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ReadReportLoop_ProcessHidClientRequest(ulonglong *param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  undefined8 local_res8;
  undefined8 local_res18 [2];
  
  uVar4 = (ulonglong)(ushort)param_1[1];
  local_res18[0] = 0;
  local_res8 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))
                    (WdfDriverGlobals,param_2,uVar4,local_res18,&local_res8);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar5 = 0xd;
  }
  else {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_2,PTR__WDF_PDO_REQUEST_CONTEXT_TYPE_INFO_14000c068);
    *(undefined8 *)(lVar2 + 8) = local_res8;
    puVar3 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,param_2,PTR__WDF_PDO_REQUEST_CONTEXT_TYPE_INFO_14000c068);
    *puVar3 = local_res18[0];
    uVar4 = *param_1;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x8c8))(WdfDriverGlobals,param_2);
    if (-1 < iVar1) {
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar4,0xf,
                          &WPP_048ee849bf123881ed4e7e767abd50df_Traceguids,(char)param_2);
      }
      return 0x103;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar5 = 0xe;
  }
  WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar4,uVar5,
                     &WPP_048ee849bf123881ed4e7e767abd50df_Traceguids,(char)param_2,(char)iVar1);
  return iVar1;
}



===== ReadReportLoop_ProcessNotifyRequest @ 140007b88 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ReadReportLoop_ProcessNotifyRequest(longlong param_1,undefined8 param_2)

{
  undefined1 uVar1;
  int iVar2;
  longlong *plVar3;
  code *pcVar4;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  *(undefined1 *)(param_1 + 0x20) = uVar1;
  if (*(char *)(param_1 + 0x21) == '\0') {
    if (*(longlong *)(param_1 + 0x28) == 0) {
      iVar2 = 0;
    }
    else {
      plVar3 = (longlong *)
               (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,param_2,PTR__WDF_FDO_REQUEST_CONTEXT_TYPE_INFO_14000c0b8)
      ;
      pcVar4 = ReadReportLoop_EvtNotifyRequestCancel;
      *plVar3 = param_1;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0xc48))(WdfDriverGlobals,param_2);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,pcVar4,0x10,
                             &WPP_048ee849bf123881ed4e7e767abd50df_Traceguids,(char)param_2,
                             (char)iVar2);
        }
      }
      else {
        *(undefined8 *)(param_1 + 0x38) = param_2;
        iVar2 = 0x103;
      }
    }
  }
  else {
    iVar2 = -0x3fffff40;
  }
  KeReleaseSpinLock(param_1 + 0x18,*(undefined1 *)(param_1 + 0x20));
  return iVar2;
}



===== FxStubDriverUnloadCommon @ 140007ca0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14000c1d8 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_14000c1d8 + 0x50);
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_140007cf9:
      if (ppvVar1 == (void **)0x0) goto LAB_140007d4f;
      if (ppvVar2 <= ppvVar1) goto LAB_140007d67;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if ((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) goto LAB_140007cf9;
LAB_140007d4f:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_140007d67:
  WdfVersionUnbind(&DAT_14000c4e0,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 140007da0 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2,undefined8 param_3)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2,param_3);
  return;
}



===== FxDriverEntryWorker @ 140007dd4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(_WDF_BIND_INFO *param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  int iVar2;
  _WDF_BIND_INFO *p_Var3;
  undefined *puVar4;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if (param_1 == (_WDF_BIND_INFO *)0x0) {
    iVar1 = DriverEntry(0,param_2,param_3);
  }
  else {
    _DAT_14000c4e0 = 0x2080000;
    _DAT_14000c4e8 = &DAT_14000c2d0;
    RtlCopyUnicodeString(&DAT_14000c4e0);
    puVar4 = &WdfBindInfo;
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_14000c4e0,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2,puVar4);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_14000c4d8 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_14000c4e0);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14000c1d8 != &__KMDF_CLASS_BIND_START) {
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



===== FxStubDriverUnload @ 140007f60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_14000c4d8 != (code *)0x0) && (DAT_14000c4d8 != FxStubDriverUnload)) {
    (*DAT_14000c4d8)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 140007f94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140007fb9) */
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
    if ((void **)0x14000c1cf < ppvVar2) break;
    if (((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_14000c1d8 = (undefined *)ppvVar2;
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



===== FxStubInitTypes @ 14000811c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140008139) */
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
    if ((void **)0x14000c1ef < ppvVar2) break;
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



===== __GSHandlerCheck @ 1400081e8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000820c =====

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



===== __GSHandlerCheck_SEH @ 140008274 =====

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



===== __security_check_cookie @ 140008310 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== RtlpCopyDeviceMemory @ 140008340 =====

void * __cdecl RtlpCopyDeviceMemory(void *_Dst,void *_Src,size_t _Size)

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



===== RtlMoveVolatileMemory @ 140008350 =====

void * __cdecl RtlMoveVolatileMemory(void *_Dst,void *_Src,size_t _Size)

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



===== RtlSetVolatileMemory @ 140008360 =====

void * __cdecl RtlSetVolatileMemory(void *_Dst,int _Val,size_t _Size)

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



===== _guard_dispatch_icall @ 140008390 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140008390. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1400083c0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1400083f0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 140008440 =====

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



===== memset @ 140008740 =====

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



===== __memset_repmovs @ 140008880 =====

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



===== __memset_query @ 140008900 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140008980 =====

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



===== __memset_spec_ermsb_repmovsb @ 140008ac0 =====

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



===== __memset_spec_plain @ 140008b40 =====

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



===== memset$thunk$772440563353939046 @ 140009030 =====

void * __cdecl memset_thunk_772440563353939046(void *_Dst,int _Val,size_t _Size)

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



===== DriverUnload @ 14000f010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DriverUnload(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0xd,
                      &WPP_c80eb013c9163779bb42e4a544ffd5bb_Traceguids,(char)uVar1);
  }
  WppCleanupKm(uVar1);
  return;
}



===== WppCleanupKm @ 14000f0d0 =====

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



===== WppInitKm @ 14000f180 =====

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



===== WppLoadTracingSupport @ 14000f25c =====

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



===== WppTraceCallback @ 14000f3a0 =====

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



===== wil_details_EvaluateFeatureDependencies @ 14000f628 =====

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
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x00014000f663;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_14000f6dd:
  while( true ) {
    if (&UNK_14000b69f < ppuVar3) {
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
      if (&UNK_14000b69f < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x00014000f663:
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
      if (&UNK_14000b69f < ppuVar2) goto LAB_14000f6dd;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_14000f6dd;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14000f718 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_14000f7b0;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_14000f7b0;
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
LAB_14000f7b0:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14000f800 =====

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
              if (&UNK_14000b69f < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14000f880 =====

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
    if (*ppuVar3 != (undefined *)0x0) goto LAB_14000f97d;
  }
LAB_14000f986:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14000f97d:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14000f986;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14000f94e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14000f94e;
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
    if (&UNK_14000b69f < ppuVar3) goto LAB_14000f986;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14000f97d;
}



===== FDO_EvtDeviceAdd @ 14000f9b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int FDO_EvtDeviceAdd(undefined8 param_1,undefined8 param_2)

{
  uint *puVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  undefined *puVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  ulonglong *puVar9;
  undefined2 uVar10;
  undefined8 local_res10;
  undefined8 local_res18 [2];
  undefined1 uVar11;
  undefined4 local_168;
  undefined4 local_164;
  code *local_160;
  code *local_158;
  undefined8 local_150;
  undefined4 local_148;
  undefined4 local_144;
  ulonglong local_140;
  code *pcStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined *local_110;
  ulonglong local_108 [6];
  undefined *local_d8;
  ulonglong local_d0 [6];
  undefined *local_a0;
  undefined8 local_98;
  undefined4 local_90;
  undefined1 local_8b;
  code *local_70;
  undefined4 local_48;
  
  puVar8 = (undefined8 *)0x60;
  local_res10 = param_2;
  memset(&local_98,0,0x60);
  local_140 = (ulonglong)(uint)local_140;
  local_res18[0] = 0;
  local_164 = 0;
  local_108[0] = (ulonglong)(uint)local_108[0];
  local_d0[0] = (ulonglong)(uint)local_d0[0];
  puVar6 = &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids;
  uVar11 = (undefined1)param_1;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    puVar6 = (undefined *)((longlong)L"WmiQueryTraceInformation" + 0x25);
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar8,0xd,
                      &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,uVar11);
    param_2 = local_res10;
  }
  uVar3 = FDO_GetVhfMode(param_2,puVar6,puVar8);
  if (uVar3 < 2) {
    (**(code **)(WdfFunctions_01015 + 0x408))(WdfDriverGlobals,local_res10);
  }
  uVar2 = FDO_GetIdleSupported(local_res10);
  local_110 = PTR__WDF_FDO_CONTEXT_TYPE_INFO_14000c0e0;
  pcStack_138 = FDO_EvtDeviceCleanupCallback;
  local_108[2] = 0;
  local_d8 = PTR__WDF_FDO_REQUEST_CONTEXT_TYPE_INFO_14000c0b8;
  local_108[1] = 0;
  local_140 = 0x38;
  local_130 = 0;
  local_120 = 0;
  uStack_118 = 0;
  uStack_128 = 0x100000001;
  local_108[4] = 0;
  local_108[5] = 0;
  local_108[0] = 0x38;
  local_108[3] = 0x100000001;
  (**(code **)(WdfFunctions_01015 + 0x240))(WdfDriverGlobals,local_res10,local_108);
  (**(code **)(WdfFunctions_01015 + 0x250))(WdfDriverGlobals,local_res10,FDO_EvtIoInCallerContext);
  local_d0[2] = 0;
  local_a0 = PTR__WDF_FDO_FILEOBJECT_CONTEXT_TYPE_INFO_14000c090;
  local_d0[3] = 0x100000001;
  local_168 = 0x28;
  local_150 = 0;
  local_d0[1] = 0;
  local_d0[0] = 0x38;
  local_d0[4] = 0;
  local_d0[5] = 0;
  if (uVar3 - 1 < 2) {
    local_160 = FDO_EvtWdfDeviceFileCreate;
    local_148 = 2;
    if (uVar3 == 1) {
      local_148 = 0;
    }
  }
  else {
    local_160 = (code *)0x0;
    local_148 = 2;
  }
  local_158 = FDO_EvtFileClose;
  local_144 = 0x80000004;
  (**(code **)(WdfFunctions_01015 + 0x238))(WdfDriverGlobals,local_res10,&local_168,local_d0);
  puVar9 = &local_140;
  iVar4 = (**(code **)(WdfFunctions_01015 + 600))(WdfDriverGlobals,&local_res10,puVar9,local_res18);
  if (iVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar4;
    }
    uVar10 = 0xe;
  }
  else {
    puVar5 = (uint *)(**(code **)(WdfFunctions_01015 + 0x650))
                               (WdfDriverGlobals,local_res18[0],
                                PTR__WDF_FDO_CONTEXT_TYPE_INFO_14000c0e0);
    *(undefined8 *)(puVar5 + 2) = local_res18[0];
    puVar1 = puVar5 + 10;
    *(undefined1 *)(puVar5 + 1) = uVar2;
    *puVar5 = uVar3;
    puVar9 = (ulonglong *)(puVar5 + 8);
    *(uint **)(puVar5 + 0xc) = puVar1;
    *(uint **)puVar1 = puVar1;
    local_110 = (undefined *)0x0;
    local_130 = 0;
    uStack_118 = 0;
    local_120 = local_res18[0];
    pcStack_138 = (code *)0x0;
    local_140 = 0x38;
    uStack_128 = 0x100000001;
    iVar4 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,&local_140);
    if (iVar4 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar4;
      }
      uVar10 = 0xf;
    }
    else {
      local_48 = 0xffffffff;
      puVar5 = puVar5 + 4;
      local_70 = FDO_EvtIoDeviceControl;
      puVar9 = &local_98;
      local_98._0_4_ = 0x60;
      local_90 = 2;
      local_8b = 1;
      local_98._4_4_ = 2;
      uVar7 = local_res18[0];
      iVar4 = (**(code **)(WdfFunctions_01015 + 0x4c0))(WdfDriverGlobals,local_res18[0],puVar9,0);
      if (iVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar4;
        }
        uVar10 = 0x10;
      }
      else {
        if (uVar3 != 2) {
LAB_14000fe30:
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return iVar4;
          }
          WPP_RECORDER_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,puVar9,0x13,puVar5,
                              uVar11,(char)local_res18[0],(char)uVar3);
          return iVar4;
        }
        puVar9 = (ulonglong *)&GUID_VHF_AS_FUNCTION_DRIVER;
        uVar7 = local_res18[0];
        iVar4 = (**(code **)(WdfFunctions_01015 + 0x268))
                          (WdfDriverGlobals,local_res18[0],&GUID_VHF_AS_FUNCTION_DRIVER,0);
        if (-1 < iVar4) goto LAB_14000fe30;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar4;
        }
        uVar10 = 0x11;
      }
    }
    param_1 = local_res18[0];
  }
  WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar9,uVar10,
                     &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,(char)param_1,(char)iVar4);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar9,0x12,
                       &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,uVar11,(char)iVar4);
  }
  return iVar4;
}



===== FDO_EvtFileClose @ 14000fe90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FDO_EvtFileClose(longlong param_1)

{
  int iVar1;
  char *pcVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  undefined *puVar7;
  
  pcVar2 = (char *)(**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,param_1,
                              PTR__WDF_FDO_FILEOBJECT_CONTEXT_TYPE_INFO_14000c090);
  if (*pcVar2 != '\0') {
    uVar3 = (**(code **)(WdfFunctions_01015 + 0x458))(WdfDriverGlobals,param_1);
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar3,PTR__WDF_FDO_CONTEXT_TYPE_INFO_14000c0e0);
    (**(code **)(WdfFunctions_01015 + 0x430))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 8));
    lVar5 = 0;
    while( true ) {
      lVar5 = (**(code **)(WdfFunctions_01015 + 0x438))
                        (WdfDriverGlobals,*(undefined8 *)(lVar4 + 8),lVar5,5);
      if (lVar5 == 0) break;
      puVar7 = PTR__WDF_PDO_CONTEXT_TYPE_INFO_14000c040;
      lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,lVar5);
      if (param_1 == *(longlong *)(lVar6 + 0x138)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar7,0x30,
                             &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,(char)param_1,
                             (char)lVar5);
        }
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x6d8))(WdfDriverGlobals,lVar5);
        if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar7,0x31,
                             &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,(char)lVar5,
                             (char)iVar1);
        }
      }
    }
    (**(code **)(WdfFunctions_01015 + 0x440))(WdfDriverGlobals,*(undefined8 *)(lVar4 + 8));
  }
  return;
}



===== FDO_EvtWdfDeviceFileCreate @ 140010070 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FDO_EvtWdfDeviceFileCreate(undefined8 param_1,undefined8 param_2,undefined1 param_3)

{
  int *piVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined8 in_stack_ffffffffffffffb8;
  
  uVar3 = 0;
  puVar4 = PTR__WDF_FDO_CONTEXT_TYPE_INFO_14000c0e0;
  piVar1 = (int *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  if (*piVar1 == 1) {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
    if ((*(char *)(lVar2 + 0x40) == '\x01') ||
       ((*(byte *)(*(longlong *)(lVar2 + 0xb8) + 2) & 1) != 0)) {
      puVar4 = (undefined *)(ulonglong)*(uint *)(lVar2 + 0x10);
      if ((*(uint *)(lVar2 + 0x10) >> 0x16 & 1) == 0) {
        uVar3 = 0xc0000022;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qqdDDLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
        goto LAB_140010189;
      }
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqqd
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar4,0xc,in_stack_ffffffffffffffb8,
               (char)param_1,(char)param_2,param_3,0);
  }
LAB_140010189:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,uVar3);
  return;
}



===== FDO_GetIdleSupported @ 1400101cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 FDO_GetIdleSupported(undefined8 param_1)

{
  int iVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined8 *puVar4;
  undefined2 uVar5;
  undefined1 auStackY_a8 [32];
  int local_68 [2];
  ulonglong local_60;
  longlong local_58;
  undefined8 local_50;
  wchar_t *local_48;
  wchar_t local_40 [16];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_68[0] = 0;
  local_60 = 0;
  local_58 = 0;
  puVar4 = (undefined8 *)0x1;
  builtin_wcsncpy(local_40,L"IdleSupported",0xe);
  local_48 = local_40;
  uVar3 = 0;
  local_50 = 0x1c001a;
  iVar1 = (**(code **)(WdfFunctions_01015 + 1000))(WdfDriverGlobals,param_1,1,0x20019);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14001037b;
    uVar5 = 0x2c;
    bVar2 = 2;
  }
  else {
    puVar4 = &local_50;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))(WdfDriverGlobals,local_58,puVar4,local_68);
    if (-1 < iVar1) {
      if (local_68[0] != 0) {
        puVar4 = (undefined8 *)0x8;
        local_60 = CONCAT44(local_60._4_4_,8);
        uVar3 = 1;
        iVar1 = ZwQuerySystemInformation(0x67,&local_60,8,0);
        if (((iVar1 < 0) || ((local_60 & 0x200000000) == 0)) &&
           (uVar3 = 0, (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,puVar4,0x2e,
                             &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,
                             (char)*WdfDriverGlobals,(char)param_1);
        }
      }
      goto LAB_14001037b;
    }
    if ((iVar1 == -0x3fffffcc) ||
       ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) goto LAB_14001037b;
    uVar5 = 0x2d;
    bVar2 = 3;
  }
  WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar2,puVar4,uVar5,
                     &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,(char)*WdfDriverGlobals,
                     (char)iVar1);
LAB_14001037b:
  if (local_58 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar4,0x2f,
                        &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,(char)*WdfDriverGlobals,
                        (char)param_1,uVar3);
  }
  return uVar3;
}



===== FDO_GetVhfMode @ 140010410 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FDO_GetVhfMode(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined1 auStackY_88 [32];
  undefined *in_stack_ffffffffffffff98;
  uint local_48 [2];
  longlong local_40;
  undefined8 local_38;
  wchar_t *local_30;
  wchar_t local_28 [8];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48[0] = 0;
  local_30 = local_28;
  local_40 = 0;
  builtin_wcsncpy(local_28,L"VhfMode",8);
  local_38 = 0x10000e;
  uVar4 = 0;
  bVar1 = FDO_IsFunctionDriverOptInPresent(param_1);
  if (bVar1) {
    uVar4 = 2;
    goto LAB_140010590;
  }
  param_3 = (undefined8 *)0x1;
  in_stack_ffffffffffffff98 = (undefined *)0x0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 1000))(WdfDriverGlobals,param_1,1,0x20019);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140010590;
    uVar5 = 0x28;
    bVar3 = 2;
  }
  else {
    param_3 = &local_38;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x780))(WdfDriverGlobals,local_40,param_3,local_48);
    if (-1 < iVar2) {
      if (local_48[0] < 3) {
        uVar4 = local_48[0];
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        in_stack_ffffffffffffff98 = &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids;
        WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,param_3,0x2a,
                           &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,(char)*WdfDriverGlobals,
                           (char)local_48[0]);
      }
      goto LAB_140010590;
    }
    if ((iVar2 == -0x3fffffcc) ||
       ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) goto LAB_140010590;
    uVar5 = 0x29;
    bVar3 = 3;
  }
  in_stack_ffffffffffffff98 = &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids;
  WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar3,param_3,uVar5,
                     &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,(char)*WdfDriverGlobals,
                     (char)iVar2);
LAB_140010590:
  if (local_40 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),*WdfDriverGlobals,param_3,0x2b,
                        in_stack_ffffffffffffff98,(char)*WdfDriverGlobals,(char)param_1,(char)uVar4)
    ;
  }
  return uVar4;
}



===== FDO_IsDuplicatePDO @ 140010618 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 FDO_IsDuplicatePDO(undefined8 param_1,wchar_t *param_2,ushort param_3)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  
  uVar4 = 0;
  (**(code **)(WdfFunctions_01015 + 0x430))(WdfDriverGlobals,param_1);
  lVar3 = 0;
  do {
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x438))(WdfDriverGlobals,param_1,lVar3,5);
    if (lVar3 == 0) goto LAB_1400106d5;
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,lVar3,PTR__WDF_PDO_CONTEXT_TYPE_INFO_14000c040);
  } while ((*(ushort *)(lVar2 + 0x60) != param_3) ||
          (iVar1 = _wcsnicmp(param_2,*(wchar_t **)(lVar2 + 0x68),(ulonglong)param_3), iVar1 != 0));
  uVar4 = 1;
LAB_1400106d5:
  (**(code **)(WdfFunctions_01015 + 0x440))(WdfDriverGlobals,param_1);
  return uVar4;
}



===== FDO_IsFunctionDriverOptInPresent @ 140010718 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FDO_IsFunctionDriverOptInPresent(undefined8 param_1)

{
  int iVar1;
  byte bVar2;
  undefined8 *puVar3;
  undefined2 uVar4;
  bool bVar5;
  undefined1 auStackY_a8 [32];
  int local_68 [2];
  longlong local_60;
  undefined8 local_58;
  wchar_t *local_50;
  wchar_t local_48 [20];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_68[0] = 0;
  local_60 = 0;
  local_50 = local_48;
  builtin_wcsncpy(local_48,L"FunctionDriverOp",0x10);
  puVar3 = (undefined8 *)0x1;
  bVar5 = false;
  builtin_wcsncpy(local_48 + 0x10,L"tIn",4);
  local_58 = 0x280026;
  iVar1 = (**(code **)(WdfFunctions_01015 + 1000))(WdfDriverGlobals,param_1,1,0x20019);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140010850;
    uVar4 = 0x25;
    bVar2 = 2;
  }
  else {
    puVar3 = &local_58;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x780))(WdfDriverGlobals,local_60,puVar3,local_68);
    if (-1 < iVar1) {
      bVar5 = local_68[0] != 0;
      goto LAB_140010850;
    }
    if ((iVar1 == -0x3fffffcc) ||
       ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)) goto LAB_140010850;
    uVar4 = 0x26;
    bVar2 = 3;
  }
  WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar2,puVar3,uVar4,
                     &WPP_7239fe49e07c3f43551e44488ee0f0b8_Traceguids,(char)*WdfDriverGlobals,
                     (char)iVar1);
LAB_140010850:
  if (local_60 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqc(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return bVar5;
}



===== PDO_CreateDevice @ 1400108d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint PDO_CreateDevice(undefined8 param_1,undefined8 param_2,ushort *param_3,ulonglong param_4,
                     char param_5,char param_6,ulonglong *param_7)

{
  wchar_t wVar1;
  void *_Dst;
  bool bVar2;
  char cVar3;
  ushort uVar4;
  ushort uVar5;
  uint uVar6;
  longlong lVar7;
  wchar_t *pwVar8;
  wchar_t *pwVar9;
  longlong lVar10;
  undefined8 uVar11;
  ulonglong *puVar12;
  wchar_t *pwVar13;
  undefined8 *puVar14;
  ulonglong uVar15;
  undefined8 uVar16;
  ulonglong _Size;
  undefined4 *puVar17;
  undefined2 uVar18;
  wchar_t *pwVar19;
  undefined1 auStackY_448 [32];
  undefined8 in_stack_fffffffffffffbd8;
  undefined1 uVar20;
  ushort local_404;
  ulonglong *local_3f8;
  ushort local_3f0;
  longlong local_3e8;
  wchar_t *local_3e0;
  ulonglong *local_3d8;
  wchar_t *local_3d0;
  wchar_t *local_3c8;
  undefined8 local_3c0;
  wchar_t *local_3b8;
  ulonglong local_3b0;
  wchar_t *local_3a8;
  ulonglong local_3a0 [2];
  wchar_t *local_390;
  longlong local_388;
  longlong local_380;
  undefined8 local_378;
  undefined8 local_370;
  wchar_t *pwStack_368;
  ulonglong local_360;
  wchar_t *local_358;
  undefined8 local_350;
  wchar_t *local_348;
  wchar_t *local_340;
  ulonglong local_338;
  longlong local_330;
  ulonglong *local_328;
  ulonglong local_320 [8];
  undefined8 local_2e0;
  ulonglong local_2d8;
  code *pcStack_2d0;
  code *local_2c8;
  undefined8 uStack_2c0;
  undefined8 local_2b8;
  undefined8 uStack_2b0;
  undefined8 local_2a8;
  undefined4 local_298;
  undefined8 local_294;
  undefined1 local_28c;
  undefined1 local_28b;
  code *local_268;
  code *local_260;
  undefined4 local_248;
  ushort local_236;
  undefined8 local_228;
  undefined8 uStack_220;
  undefined8 local_218;
  undefined8 uStack_210;
  undefined8 local_208;
  code *pcStack_200;
  code *local_1f8;
  undefined4 local_1f0;
  undefined4 local_1e8;
  undefined4 local_1e4;
  code *local_1e0;
  code *local_1d0;
  code *local_188;
  undefined4 local_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 local_148;
  undefined4 uStack_144;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined8 local_10c;
  undefined8 uStack_104;
  undefined8 local_fc;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  wchar_t local_d8 [24];
  wchar_t local_a8 [24];
  wchar_t local_78 [28];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_448;
  local_328 = param_7;
  local_320[0] = 0;
  local_320[1] = 0;
  local_370 = 0;
  pwStack_368 = (wchar_t *)0x0;
  local_3a0[0] = 0;
  local_3a0[1] = 0;
  local_3c0 = param_1;
  local_3b0 = param_4;
  local_378 = param_2;
  memset(&local_298,0,0x60);
  local_3d8 = (ulonglong *)0x0;
  local_2d8 = 0;
  pcStack_2d0 = (code *)0x0;
  local_2c8 = (code *)0x0;
  uStack_2c0 = 0;
  local_2b8 = 0;
  uStack_2b0 = 0;
  local_2a8 = (undefined *)((ulonglong)local_2a8._4_4_ << 0x20);
  local_320[2] = 0;
  local_320[3] = 0;
  local_320[4] = 0;
  local_320[5] = 0;
  local_320[6] = 0;
  local_320[7] = 0;
  local_2e0 = (undefined *)((ulonglong)local_2e0._4_4_ << 0x20);
  local_1e4 = 0;
  memset(&local_1e8,0,0x8c);
  local_158 = 0;
  uStack_154 = 0;
  uStack_150 = 0;
  uStack_14c = 0;
  local_148 = 0;
  uStack_144 = 0;
  uStack_140 = 0;
  local_138 = 0;
  uStack_130 = 0;
  local_228 = 0;
  uStack_220 = 0;
  local_218 = 0;
  uStack_210 = 0;
  local_208 = 0;
  pcStack_200 = (code *)0x0;
  local_1f8 = (code *)0x0;
  local_1f0 = 0;
  builtin_wcsncpy(local_78,L"VHF\\HID_DEVICE_SYSTEM_VHF",0x1a);
  local_78[0x1a] = 0;
  local_350 = 0x360034;
  local_348 = local_78;
  builtin_wcsncpy(local_a8,L"HID_DEVICE_SYSTEM_VHF",0x16);
  local_360 = 0x2c002a;
  local_358 = local_a8;
  builtin_wcsncpy(local_d8,L"VHF\\VID_%04X&PID_%04X",0x16);
  local_236 = 0x2c;
  local_3f8 = (ulonglong *)0x0;
  pwVar9 = (wchar_t *)0x0;
  local_3e0 = (wchar_t *)0x0;
  local_404 = 0;
  pwVar19 = (wchar_t *)0x0;
  local_3c8 = (wchar_t *)0x0;
  local_3a8 = (wchar_t *)0x0;
  uVar5 = 0;
  local_3f0 = 0;
  pwVar8 = (wchar_t *)0x0;
  local_3b8 = (wchar_t *)0x0;
  bVar2 = false;
  puVar12 = (ulonglong *)PTR__WDF_FDO_CONTEXT_TYPE_INFO_14000c0e0;
  lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  local_380 = lVar7;
  local_3e8 = (**(code **)(WdfFunctions_01015 + 0x690))(WdfDriverGlobals);
  if (local_3e8 == 0) {
    uVar6 = 0xc000009a;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar18 = 10;
      uVar6 = 0xc000009a;
LAB_140010bbf:
      uVar20 = (undefined1)uVar6;
LAB_140010bc6:
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar12,uVar18,
                        &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,uVar20);
    }
  }
  else {
    memset(&local_1e8,0,0x90);
    local_1e8 = 0x90;
    local_188 = PDO_EvtDeviceSurpriseRemoval;
    if (*(char *)(lVar7 + 4) != '\0') {
      local_1e0 = PDO_EvtDeviceD0Entry;
      local_1d0 = PDO_EvtDeviceD0Exit;
    }
    (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,local_3e8,&local_1e8);
    if (*(char *)(lVar7 + 4) != '\0') {
      memset(&local_228,0,0x40);
      local_228 = CONCAT44(local_228._4_4_,0x40);
      pcStack_200 = PDO_EvtDeviceEnableWakeAtBus;
      local_1f8 = PDO_EvtDeviceDisableWakeAtBus;
      (**(code **)(WdfFunctions_01015 + 0x698))(WdfDriverGlobals,local_3e8,&local_228);
    }
    puVar12 = &local_360;
    uVar6 = (**(code **)(WdfFunctions_01015 + 0x6b0))(WdfDriverGlobals,local_3e8);
    if ((int)uVar6 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar18 = 0xb;
        goto LAB_140010bbf;
      }
    }
    else {
      if (param_6 == '\0') {
        local_3d8 = *(ulonglong **)(param_3 + 0x10);
      }
      else {
        local_3d8 = (ulonglong *)(ulonglong)*(uint *)(param_3 + 0x10);
      }
      if (((param_5 == '\x01') && (param_3[0xe] != 0)) &&
         ((puVar12 = (ulonglong *)((longlong)local_3d8 + (ulonglong)param_3[0xe]),
          *(ulonglong **)MmUserProbeAddress_exref < puVar12 || (puVar12 < local_3d8)))) {
        pwVar9 = local_3e0;
        pwVar8 = local_3b8;
        pwVar19 = local_3c8;
        uVar5 = local_3f0;
        uVar4 = local_236;
      }
      else {
        uVar4 = 0x2c;
      }
      if (0x47 < local_3b0) {
        if (param_6 == '\0') {
          pwVar8 = *(wchar_t **)(param_3 + 0x20);
        }
        else {
          pwVar8 = (wchar_t *)(ulonglong)*(uint *)(param_3 + 0x20);
        }
        uVar5 = param_3[0x1c];
        local_3f0 = uVar5;
        local_3b8 = pwVar8;
      }
      if ((uVar5 == 0) || (pwVar8 == (wchar_t *)0x0)) {
        if (*param_3 != 0) {
          uVar16 = 0x44464856;
          pwVar8 = (wchar_t *)ExAllocatePool2(0x40,uVar4);
          local_3a8 = pwVar8;
          if (pwVar8 == (wchar_t *)0x0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar16,0x11,
                               &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids);
            }
            uVar6 = 0xc000009a;
          }
          else {
            uVar16 = CONCAT44((int)((ulonglong)in_stack_fffffffffffffbd8 >> 0x20),(uint)param_3[1]);
            pwVar13 = local_d8;
            RtlStringCchPrintfW(pwVar8,(ulonglong)(uVar4 >> 1),pwVar13,(ulonglong)*param_3);
            uVar6 = RtlUnicodeStringInit((short *)local_3a0,pwVar8);
            if ((int)uVar6 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pwVar13,0x12,
                                  &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)uVar6);
              }
            }
            else {
              puVar12 = local_3a0;
              lVar7 = local_3e8;
              uVar6 = (**(code **)(WdfFunctions_01015 + 0x6b0))(WdfDriverGlobals);
              if (-1 < (int)uVar6) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar7,puVar12,0x14,
                                    uVar16,pwVar8);
                }
                ExFreePoolWithTag(pwVar8,0);
                local_3a8 = (wchar_t *)0x0;
                goto LAB_140011194;
              }
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar12,0x13,
                                  &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)uVar6);
              }
            }
          }
          goto LAB_140011cfa;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,puVar12,0x15,
                           &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids);
        }
      }
      else {
        if (param_5 == '\x01') {
          if (((ulonglong)pwVar8 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
            ExRaiseDatatypeMisalignment();
          }
          if ((wchar_t *)((ulonglong)uVar5 + (longlong)pwVar8) <=
              *(wchar_t **)MmUserProbeAddress_exref) {
            if (pwVar8 <= (wchar_t *)((ulonglong)uVar5 + (longlong)pwVar8)) goto LAB_140010e27;
          }
          pwVar9 = local_3e0;
          pwVar8 = local_3b8;
          pwVar19 = local_3c8;
        }
LAB_140010e27:
        local_3d0 = pwVar8;
        while ((local_3d0 < (wchar_t *)((ulonglong)local_3f0 + (longlong)pwVar8) &&
               (*local_3d0 != L'\0'))) {
          uVar6 = RtlUnicodeStringInit((short *)local_3a0,local_3d0);
          if ((int)uVar6 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar12,0xc,
                                &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)uVar6);
            }
            goto LAB_140011cfa;
          }
          if (!bVar2) {
            puVar12 = local_3a0;
            lVar7 = local_3e8;
            uVar6 = (**(code **)(WdfFunctions_01015 + 0x6a0))(WdfDriverGlobals);
            if ((int)uVar6 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar12,0xd,
                                  &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)uVar6);
              }
              goto LAB_140011cfa;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar7,puVar12,0xe,
                                in_stack_fffffffffffffbd8,local_3d0);
            }
            bVar2 = true;
          }
          puVar12 = local_3a0;
          lVar7 = local_3e8;
          uVar6 = (**(code **)(WdfFunctions_01015 + 0x6b0))(WdfDriverGlobals);
          pwVar13 = local_3d0;
          if ((int)uVar6 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_Sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
            }
            goto LAB_140011cfa;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar7,puVar12,0x10,
                              in_stack_fffffffffffffbd8,local_3d0);
          }
          local_3d0 = (wchar_t *)((longlong)pwVar13 + (local_3a0[0] >> 0x10 & 0xffff));
        }
      }
LAB_140011194:
      if (!bVar2) {
        puVar14 = &local_350;
        uVar6 = (**(code **)(WdfFunctions_01015 + 0x6a0))(WdfDriverGlobals,local_3e8);
        if ((int)uVar6 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar14,0x16,
                              &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)uVar6);
          }
          goto LAB_140011cfa;
        }
      }
      if (0x37 < local_3b0) {
        if (param_6 == '\0') {
          pwVar19 = *(wchar_t **)(param_3 + 0x18);
        }
        else {
          pwVar19 = (wchar_t *)(ulonglong)*(uint *)(param_3 + 0x18);
        }
        local_404 = param_3[0x14];
        local_3c8 = pwVar19;
      }
      if ((local_404 == 0) || (pwVar19 == (wchar_t *)0x0)) {
        uVar15 = (ulonglong)param_3[0xe];
        uVar6 = PDO_GenerateInstanceId(local_3c0,local_3d8,param_3[0xe],(longlong)&local_370);
        if ((int)uVar6 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar15,0x1a,
                              &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)uVar6);
          }
        }
        else {
          local_3e0 = pwStack_368;
          local_404 = local_370._2_2_;
          pwVar9 = pwStack_368;
LAB_1400114e9:
          puVar12 = &local_370;
          uVar6 = (**(code **)(WdfFunctions_01015 + 0x6a8))(WdfDriverGlobals,local_3e8);
          if ((int)uVar6 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar18 = 0x1b;
LAB_140011529:
              uVar20 = (undefined1)uVar6;
              goto LAB_140010bc6;
            }
          }
          else {
            lVar7 = *(longlong *)(param_3 + 4);
            if (lVar7 == 0) {
              lVar7 = *(longlong *)(param_3 + 8);
            }
            if (lVar7 == 0) {
LAB_1400115ea:
              local_2d8 = 0x38;
              local_2b8 = 0;
              uStack_2b0 = 0;
              uStack_2c0 = 0x100000001;
              local_2a8 = PTR__WDF_PDO_CONTEXT_TYPE_INFO_14000c040;
              pcStack_2d0 = PDO_EvtDeviceCleanupCallback;
              local_2c8 = PDO_EvtDeviceDestroyCallback;
              local_320[3] = 0;
              local_320[4] = 0;
              local_320[6] = 0;
              local_320[7] = 0;
              local_320[2] = 0x38;
              local_320[5] = 0x100000001;
              local_2e0 = PTR__WDF_PDO_REQUEST_CONTEXT_TYPE_INFO_14000c068;
              (**(code **)(WdfFunctions_01015 + 0x240))(WdfDriverGlobals,local_3e8,local_320 + 2);
              puVar12 = &local_2d8;
              uVar6 = (**(code **)(WdfFunctions_01015 + 600))
                                (WdfDriverGlobals,&local_3e8,puVar12,&local_3f8);
              if ((int)uVar6 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar18 = 0x1e;
                  goto LAB_140011529;
                }
              }
              else {
                local_158 = 0x30;
                uStack_154 = 2;
                uStack_150 = 2;
                uStack_14c = 2;
                local_148 = 2;
                local_138 = 0x200000002;
                uStack_130 = 0xffffffffffffffff;
                uStack_144 = 0;
                uStack_140 = 0x100000002;
                (**(code **)(WdfFunctions_01015 + 0x298))(WdfDriverGlobals,local_3f8,&local_158);
                if (*(char *)(local_380 + 4) != '\0') {
                  memset(&local_128,0,0x50);
                  local_128 = 0x50;
                  local_124 = 2;
                  local_120 = 2;
                  local_11c = 2;
                  local_118 = 2;
                  local_114 = 2;
                  local_10c = 0x500000005;
                  uStack_104 = 0x500000005;
                  local_fc = 0x500000005;
                  local_f4 = 5;
                  local_e8 = 0xffffffff;
                  local_e4 = 0xffffffff;
                  local_e0 = 0xffffffff;
                  local_dc = 5;
                  local_110 = 1;
                  local_f0 = 4;
                  local_ec = 1;
                  (**(code **)(WdfFunctions_01015 + 0x2a0))(WdfDriverGlobals,local_3f8,&local_128);
                }
                lVar7 = (**(code **)(WdfFunctions_01015 + 0x650))
                                  (WdfDriverGlobals,local_3f8,
                                   PTR__WDF_PDO_CONTEXT_TYPE_INFO_14000c040);
                *(longlong *)(lVar7 + 8) = lVar7;
                *(longlong *)lVar7 = lVar7;
                *(ulonglong **)(lVar7 + 0x10) = local_3f8;
                *(undefined8 *)(lVar7 + 0x18) = local_3c0;
                *(undefined8 *)(lVar7 + 0x138) = local_378;
                *(undefined4 *)(lVar7 + 0x140) = 0;
                *(undefined1 *)(lVar7 + 0x144) = 0;
                uVar15 = local_3b0;
                if (0x47 < local_3b0) {
                  uVar15 = 0x48;
                }
                memcpy((void *)(lVar7 + 0x38),param_3,uVar15);
                uVar16 = 0x44464856;
                lVar10 = ExAllocatePool2(0x40,*(undefined2 *)(lVar7 + 0x54));
                *(longlong *)(lVar7 + 0x58) = lVar10;
                if (lVar10 == 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar16,0x1f,
                                     &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids);
                  }
                  uVar6 = 0xc000009a;
                  goto LAB_140011cfe;
                }
                uVar15 = Feature_VHFUMA01__private_IsEnabledDeviceUsageNoInline();
                _Dst = *(void **)(lVar7 + 0x58);
                _Size = (ulonglong)param_3[0xe];
                if ((int)uVar15 == 0) {
                  memcpy(_Dst,local_3d8,_Size);
                }
                else if (param_5 == '\0') {
                  RtlpCopyDeviceMemory(_Dst,local_3d8,_Size);
                }
                else {
                  RtlCopyFromUser(_Dst,local_3d8,_Size);
                }
                *(wchar_t **)(lVar7 + 0x68) = pwVar9;
                *(ushort *)(lVar7 + 0x60) = local_404;
                pwVar9 = (wchar_t *)0x0;
                puVar17 = (undefined4 *)0x200;
                uVar6 = HidP_GetCollectionDescription
                                  (*(undefined8 *)(lVar7 + 0x58),*(undefined2 *)(lVar7 + 0x54),0x200
                                   ,lVar7 + 0x80);
                if ((int)uVar6 < 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    uVar18 = 0x20;
LAB_1400119db:
                    WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar17,uVar18,
                                       &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,
                                       (char)local_3f8,(char)uVar6);
                  }
                }
                else {
                  *(undefined1 *)(lVar7 + 0xc0) = 1;
                  memset(&local_298,0,0x60);
                  lVar10 = local_380;
                  local_298 = 0x60;
                  local_28b = 1;
                  local_294 = 0x200000002;
                  local_248 = 0xffffffff;
                  local_268 = PDO_EvtQueueInternalDeviceControl;
                  if (*(char *)(local_380 + 4) != '\0') {
                    local_260 = PDO_EvtQueueIoStop;
                  }
                  puVar17 = &local_298;
                  uVar6 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                                    (WdfDriverGlobals,local_3f8,puVar17,0);
                  if ((int)uVar6 < 0) {
                    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                      uVar18 = 0x21;
                      goto LAB_1400119db;
                    }
                  }
                  else {
                    memset(&local_28c,0,0x54);
                    local_298 = 0x60;
                    local_294 = 3;
                    puVar17 = &local_298;
                    uVar6 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                                      (WdfDriverGlobals,local_3f8,puVar17,0);
                    if ((int)uVar6 < 0) {
                      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                        uVar18 = 0x22;
                        goto LAB_1400119db;
                      }
                    }
                    else {
                      if (*(char *)(lVar10 + 4) != '\0') {
                        memset(&local_28c,0,0x54);
                        local_298 = 0x60;
                        local_294 = 3;
                        puVar17 = &local_298;
                        uVar6 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                                          (WdfDriverGlobals,local_3f8,puVar17,0);
                        if ((int)uVar6 < 0) {
                          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                            uVar18 = 0x23;
                            goto LAB_1400119db;
                          }
                          goto LAB_140011cfa;
                        }
                      }
                      uVar5 = PDO_GetMaxInputReportLength(lVar7);
                      puVar17 = (undefined4 *)(ulonglong)uVar5;
                      uVar6 = ReadReportLoop_Initialize((undefined8 *)(lVar7 + 200),local_3f8,uVar5)
                      ;
                      if ((int)uVar6 < 0) {
                        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                          uVar18 = 0x24;
                          goto LAB_1400119db;
                        }
                      }
                      else {
                        uVar5 = PDO_GetMaxReportBufferLength(local_3f8);
                        puVar17 = (undefined4 *)(ulonglong)*(uint *)(lVar7 + 0x50);
                        uVar6 = PullRequestLoop_Initialize
                                          ((undefined8 *)(lVar7 + 0x108),local_3f8,
                                           *(uint *)(lVar7 + 0x50),uVar5);
                        uVar16 = local_3c0;
                        if ((int)uVar6 < 0) {
                          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                            uVar18 = 0x25;
                            goto LAB_1400119db;
                          }
                        }
                        else {
                          uVar11 = local_3c0;
                          puVar12 = local_3f8;
                          uVar6 = (**(code **)(WdfFunctions_01015 + 0x428))(WdfDriverGlobals);
                          if ((int)uVar6 < 0) {
                            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
                            {
                              uVar18 = 0x26;
                              goto LAB_140011529;
                            }
                          }
                          else {
                            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
                            {
                              WPP_RECORDER_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar11,
                                                  puVar12,0x27,
                                                  &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,
                                                  (char)uVar16,(char)local_3f8,(char)local_378);
                            }
                            *local_328 = (ulonglong)local_3f8;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else {
              uVar6 = RtlStringFromGUID(param_3 + 4,local_320);
              if ((int)uVar6 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar18 = 0x1c;
                  goto LAB_140011529;
                }
              }
              else {
                puVar12 = local_320;
                uVar6 = (**(code **)(WdfFunctions_01015 + 0xc38))(WdfDriverGlobals,local_3e8);
                RtlFreeUnicodeString(local_320);
                if (-1 < (int)uVar6) goto LAB_1400115ea;
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar18 = 0x1d;
                  uVar20 = (undefined1)uVar6;
                  goto LAB_140010bc6;
                }
              }
            }
          }
        }
      }
      else {
        if (param_5 == '\x01') {
          if (((ulonglong)pwVar19 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
            ExRaiseDatatypeMisalignment();
          }
          if ((wchar_t *)((ulonglong)local_404 + (longlong)pwVar19) <=
              *(wchar_t **)MmUserProbeAddress_exref) {
            if (pwVar19 <= (wchar_t *)((ulonglong)local_404 + (longlong)pwVar19))
            goto LAB_1400112d8;
          }
          pwVar9 = local_3e0;
          pwVar19 = local_3c8;
        }
LAB_1400112d8:
        uVar15 = (ulonglong)local_404;
        cVar3 = FDO_IsDuplicatePDO(local_3c0,pwVar19,local_404);
        if (cVar3 == '\0') {
          uVar15 = 0x44464856;
          pwVar9 = (wchar_t *)ExAllocatePool2(0x40,local_404);
          local_3e0 = pwVar9;
          if (pwVar9 == (wchar_t *)0x0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar15,0x18,
                               &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids);
            }
            uVar6 = 0xc000009a;
          }
          else {
            if ((ulonglong)(local_404 >> 1) != 0) {
              local_330 = 0x7ffffffe;
              local_388 = 0;
              local_390 = pwVar9;
              local_340 = pwVar19;
              for (local_338 = (ulonglong)(local_404 >> 1); local_338 != 0;
                  local_338 = local_338 - 1) {
                if (local_330 == 0) {
LAB_14001140b:
                  if (local_338 != 0) goto LAB_140011427;
                  break;
                }
                wVar1 = *local_340;
                uVar15 = (ulonglong)(ushort)wVar1;
                if (wVar1 == L'\0') goto LAB_14001140b;
                *local_390 = wVar1;
                local_390 = local_390 + 1;
                local_340 = local_340 + 1;
                local_330 = local_330 + -1;
                local_388 = local_388 + 1;
              }
              local_390 = local_390 + -1;
              local_388 = local_388 + -1;
LAB_140011427:
              *local_390 = L'\0';
            }
            uVar6 = RtlUnicodeStringInit((short *)&local_370,pwVar9);
            if (-1 < (int)uVar6) goto LAB_1400114e9;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar15,0x19,
                                &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)uVar6);
            }
          }
        }
        else {
          uVar6 = 0xc000000d;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar15,0x17,
                             &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids);
          }
        }
      }
    }
  }
LAB_140011cfa:
  if (-1 < (int)uVar6) {
    return uVar6;
  }
LAB_140011cfe:
  if (local_3e8 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x1b0))(WdfDriverGlobals);
  }
  if (local_3f8 != (ulonglong *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  if (pwVar9 != (wchar_t *)0x0) {
    ExFreePoolWithTag(pwVar9,0);
  }
  if (local_3a8 != (wchar_t *)0x0) {
    ExFreePoolWithTag(local_3a8,0);
  }
  return uVar6;
}



===== PDO_EvtDeviceSurpriseRemoval @ 140011db0 =====

void PDO_EvtDeviceSurpriseRemoval(undefined1 param_1,undefined8 param_2,undefined8 param_3)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0x2c,
                      &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,param_1);
  }
  return;
}



===== PDO_GenerateInstanceId @ 140011dfc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int PDO_GenerateInstanceId(undefined8 param_1,undefined8 param_2,ushort param_3,longlong param_4)

{
  char cVar1;
  int iVar2;
  ulonglong uVar3;
  undefined2 uVar4;
  undefined1 auStackY_68 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_68;
  uVar3 = (ulonglong)param_3;
  local_38 = 0;
  uStack_30 = 0;
  iVar2 = RtlGenerateClass5Guid(&GUID_VHF_INSTANCE_ID_NAMESPACE,param_2,uVar3,&local_38);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    uVar4 = 0x53;
  }
  else {
    iVar2 = RtlStringFromGUID(&local_38,param_4);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar2;
      }
      uVar4 = 0x54;
    }
    else {
      uVar3 = (ulonglong)*(ushort *)(param_4 + 2);
      cVar1 = FDO_IsDuplicatePDO(param_1,*(wchar_t **)(param_4 + 8),*(ushort *)(param_4 + 2));
      if (cVar1 == '\0') {
        return iVar2;
      }
      RtlFreeUnicodeString(param_4);
      iVar2 = ExUuidCreate(&local_38);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar2;
        }
        uVar4 = 0x55;
      }
      else {
        iVar2 = RtlStringFromGUID(&local_38,param_4);
        if (-1 < iVar2) {
          return iVar2;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar2;
        }
        uVar4 = 0x56;
      }
    }
  }
  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar3,uVar4,
                    &WPP_c2938109c1c0302ea7b4e4c7ac799cde_Traceguids,(char)iVar2);
  return iVar2;
}



===== __security_init_cookie @ 140012008 =====

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



===== DriverEntry @ 14001203c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined1 auStackY_a8 [32];
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_a8;
  _DAT_14000c528 = 1;
  local_40 = 0;
  uStack_38 = 0;
  _WPP_MAIN_CB = 0;
  DAT_14000c508 = &WPP_ThisDir_CTLGUID_VHF;
  DAT_14000c510 = 0;
  _DAT_14000c520 = 0;
  _DAT_14000c540 = 0;
  _DAT_14000c548 = 0;
  WppLoadTracingSupport();
  _DAT_14000c520 = 0;
  WppInitKm(param_1,param_2);
  local_40 = CONCAT35(local_40._5_3_,0x100000010);
  uStack_38 = 0x200000001;
  imp_WppRecorderConfigure(WPP_GLOBAL_Control,&local_40);
  wil_InitializeFeatureStaging();
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,10,
                      &WPP_c80eb013c9163779bb42e4a544ffd5bb_Traceguids,(char)param_1);
  }
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))(WdfDriverGlobals,param_1,param_2,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400121f7;
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_2,0xb,
                      &WPP_c80eb013c9163779bb42e4a544ffd5bb_Traceguids,(char)iVar1);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_2,0xc,
                       &WPP_c80eb013c9163779bb42e4a544ffd5bb_Traceguids,(char)param_1,(char)iVar1);
  }
  if (-1 < iVar1) {
    return iVar1;
  }
LAB_1400121f7:
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
  WppCleanupKm(param_1);
  return iVar1;
}



===== wil_InitializeFeatureStaging @ 140012270 =====

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
      if (*ppuVar3 != (undefined *)0x0) goto LAB_1400122f7;
    }
LAB_140012331:
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
LAB_1400122f7:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140012331;
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
    goto LAB_140012331;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_14000b69f < ppuVar3) goto LAB_140012331;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1400122f7;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140012384 =====

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
            if (&UNK_14000b69f < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14001246e;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14001246e;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14001246e:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_14000b69f < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


