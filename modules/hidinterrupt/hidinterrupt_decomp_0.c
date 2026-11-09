
===== __report_gsfailure @ 1c0001010 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== WPP_RECORDER_SF_D @ 1c0001020 =====

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



===== WPP_RECORDER_SF_q @ 1c00010d0 =====

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



===== WPP_RECORDER_SF_qd @ 1c0001180 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qd(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
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



===== WppClassicProviderCallback @ 1c0001260 =====

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



===== HIDINT_CompleteReadReports @ 1c00012bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HIDINT_CompleteReadReports(longlong param_1,undefined8 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int local_res8 [2];
  undefined8 local_res10;
  
  local_res8[0] = 0;
  local_res10 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x37,
                     &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids);
  }
  cVar3 = '\0';
LAB_1c0001331:
  do {
    LOCK();
    bVar4 = *(int *)(param_1 + 0x4c) == 0;
    if (bVar4) {
      *(int *)(param_1 + 0x4c) = 1;
    }
    UNLOCK();
    if (!bVar4) goto LAB_1c00014cb;
    cVar3 = cVar3 + '\x01';
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x38,
                        &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,cVar3);
    }
    while( true ) {
      (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
      iVar2 = *(int *)(param_1 + 0x3c);
      iVar1 = *(int *)(param_1 + 0x38);
      (**(code **)(WdfFunctions_01015 + 0x488))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
      if (iVar2 == iVar1) break;
      if (*(char *)(param_1 + 0x80) == '\0') {
        param_3 = (int *)&local_res10;
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x4f0))
                          (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10));
        if (iVar2 < 0) break;
        HIDINT_ReadReport(param_1,local_res10);
      }
      else {
        iVar2 = 1;
        if (*(char *)(param_1 + 0x81) == '\0') {
          LOCK();
          iVar1 = *(int *)(param_1 + 0x90);
          if (iVar1 == 1) {
            *(int *)(param_1 + 0x90) = 0;
          }
          else {
            iVar2 = iVar1;
          }
          UNLOCK();
          if (iVar2 == 0) break;
        }
        else {
          LOCK();
          bVar4 = *(int *)(param_1 + 0x90) == 1;
          if (bVar4) {
            *(int *)(param_1 + 0x90) = 1;
          }
          UNLOCK();
          if (!bVar4) break;
        }
        HIDINT_VhfSubmitReadReport(param_1);
      }
    }
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x39,
                        &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,cVar3);
    }
    LOCK();
    if (*(int *)(param_1 + 0x4c) == 1) {
      *(int *)(param_1 + 0x4c) = 0;
    }
    UNLOCK();
    (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
    iVar2 = *(int *)(param_1 + 0x3c);
    iVar1 = *(int *)(param_1 + 0x38);
    (**(code **)(WdfFunctions_01015 + 0x488))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
    if (iVar2 == iVar1) goto LAB_1c00014cb;
    if (*(char *)(param_1 + 0x80) == '\0') {
      param_3 = local_res8;
      (**(code **)(WdfFunctions_01015 + 0x4c8))
                (WdfDriverGlobals,*(undefined8 *)(param_1 + 0x10),param_3,0);
      bVar4 = local_res8[0] == 0;
    }
    else {
      if (*(char *)(param_1 + 0x81) != '\0') {
        LOCK();
        bVar4 = *(int *)(param_1 + 0x90) == 1;
        if (bVar4) {
          *(int *)(param_1 + 0x90) = 1;
        }
        UNLOCK();
        if (!bVar4) goto LAB_1c00014cb;
        goto LAB_1c0001331;
      }
      LOCK();
      bVar4 = *(int *)(param_1 + 0x90) == 0;
      if (bVar4) {
        *(int *)(param_1 + 0x90) = 0;
      }
      UNLOCK();
    }
    if (bVar4) {
LAB_1c00014cb:
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,param_3,0x3a,
                         &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids);
      }
      return;
    }
  } while( true );
}



===== HIDINT_EvtDeviceCleanupCallback @ 1c00015e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HIDINT_EvtDeviceCleanupCallback(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined *puVar7;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0x23,
                      &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,(char)param_1);
  }
  puVar7 = PTR__WDF_HIDINT_DATA_TYPE_INFO_1c0009018;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  uVar4 = 0;
  if (*(int *)(lVar3 + 0x48) != 0) {
    do {
      lVar1 = *(longlong *)(*(longlong *)(lVar3 + 0x40) + uVar4 * 8);
      if (lVar1 != 0) {
        uVar6 = 0;
        if (*(int *)(lVar1 + 0x30) != 0) {
          do {
            lVar2 = *(longlong *)(*(longlong *)(lVar1 + 0x28) + uVar6 * 8);
            if (lVar2 != 0) {
              ExFreePoolWithTag(lVar2,0x746e4948);
            }
            uVar5 = (int)uVar6 + 1;
            uVar6 = (ulonglong)uVar5;
          } while (uVar5 < *(uint *)(lVar1 + 0x30));
        }
        ExFreePoolWithTag(*(undefined8 *)(lVar1 + 0x28),0x746e4948);
        if (*(longlong *)(lVar1 + 0x40) != 0) {
          ExFreePoolWithTag(*(longlong *)(lVar1 + 0x40),0x746e4948);
          *(undefined8 *)(lVar1 + 0x40) = 0;
        }
        if (*(longlong *)(lVar1 + 0x50) != 0) {
          ExFreePoolWithTag(*(longlong *)(lVar1 + 0x50),0x746e4948);
          *(undefined8 *)(lVar1 + 0x50) = 0;
        }
        if (*(longlong *)(lVar1 + 0x60) != 0) {
          ExFreePoolWithTag(*(longlong *)(lVar1 + 0x60),0x746e4948);
          *(undefined8 *)(lVar1 + 0x60) = 0;
        }
        ExFreePoolWithTag(lVar1,0x746e4948);
      }
      uVar5 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar5;
    } while (uVar5 < *(uint *)(lVar3 + 0x48));
  }
  if (*(longlong *)(lVar3 + 0x98) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar3 + 0x98),0x746e4948);
  }
  if (*(longlong *)(lVar3 + 0x40) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar3 + 0x40),0x746e4948);
  }
  if (*(longlong *)(lVar3 + 0x78) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar3 + 0x78),0x746e4948);
  }
  if (*(longlong *)(lVar3 + 0x28) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar3 + 0x28),0x746e4948);
    *(undefined8 *)(lVar3 + 0x28) = 0;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar7,0x24,
                      &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,(char)param_1);
  }
  return;
}



===== HIDINT_EvtInterruptDpc @ 1c0001800 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HIDINT_EvtInterruptDpc(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  int *piVar2;
  
  piVar2 = (int *)PTR__WDF_HIDINT_DATA_TYPE_INFO_1c0009018;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  HIDINT_CompleteReadReports(lVar1,param_2,piVar2);
  return;
}



===== HIDINT_EvtInterruptIsr @ 1c0001840 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 HIDINT_EvtInterruptIsr(undefined8 param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_INTERRUPT_DATA_TYPE_INFO_1c0009040);
  lVar1 = *(longlong *)(lVar1 + 8);
  *(int *)(lVar1 + 0x38) = *(int *)(lVar1 + 0x38) + 1;
  HIDINT_OnControlStateToggle(lVar1);
  if (*(char *)(lVar1 + 0x28) != '\0') {
    HIDINT_OnControlStateToggle(lVar1);
  }
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x470))(WdfDriverGlobals,param_1);
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== HIDINT_EvtVhfGetFeature @ 1c00018c0 =====

void HIDINT_EvtVhfGetFeature
               (longlong param_1,longlong *param_2,undefined8 param_3,undefined8 *param_4)

{
  ulonglong uVar1;
  
  uVar1 = HIDINT_GetSetReport(param_1,0xb0192,param_4);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_4,0x67,
                       &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,(char)param_2,(char)uVar1);
  }
  VhfAsyncOperationComplete(param_2,uVar1 & 0xffffffff,param_4);
  return;
}



===== HIDINT_EvtVhfGetInputReport @ 1c0001940 =====

void HIDINT_EvtVhfGetInputReport
               (longlong param_1,longlong *param_2,undefined8 param_3,undefined8 *param_4)

{
  ulonglong uVar1;
  
  uVar1 = HIDINT_GetSetReport(param_1,0xb01a2,param_4);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_4,0x68,
                       &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,(char)param_2,(char)uVar1);
  }
  VhfAsyncOperationComplete(param_2,uVar1 & 0xffffffff,param_4);
  return;
}



===== HIDINT_EvtVhfReadyForNextReadReport @ 1c00019c0 =====

void HIDINT_EvtVhfReadyForNextReadReport(longlong param_1,undefined8 param_2,int *param_3)

{
  undefined1 uVar1;
  undefined7 uVar2;
  
  uVar1 = (undefined1)param_2;
  uVar2 = (undefined7)((ulonglong)param_2 >> 8);
  LOCK();
  if (*(int *)(param_1 + 0x90) == 0) {
    *(int *)(param_1 + 0x90) = 1;
  }
  UNLOCK();
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar1 = 4;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0x66,
                     &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids);
  }
  HIDINT_CompleteReadReports(param_1,CONCAT71(uVar2,uVar1),param_3);
  return;
}



===== HIDINT_EvtVhfSetFeature @ 1c0001a20 =====

void HIDINT_EvtVhfSetFeature
               (longlong param_1,longlong *param_2,undefined8 param_3,undefined8 *param_4)

{
  ulonglong uVar1;
  
  uVar1 = HIDINT_GetSetReport(param_1,0xb0191,param_4);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_4,0x69,
                       &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,(char)param_2,(char)uVar1);
  }
  VhfAsyncOperationComplete(param_2,uVar1 & 0xffffffff,param_4);
  return;
}



===== HIDINT_GetReportRequest @ 1c0001a98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 HIDINT_GetReportRequest(undefined8 param_1,undefined8 param_2,uint param_3)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined2 uVar6;
  undefined1 auStackY_78 [32];
  undefined8 local_48;
  ulonglong uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_78;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_HIDINT_DATA_TYPE_INFO_1c0009018);
  puVar5 = &local_48;
  local_28 = 0;
  uStack_40 = 0;
  local_48 = 0x28;
  local_38 = 0;
  uStack_30 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2);
  if (uStack_40 < 0x10) {
    uVar1 = 0xc0000023;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0001bb3;
    uVar6 = 0x30;
  }
  else {
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
    puVar5 = *(undefined8 **)(lVar3 + 0x70);
    if (puVar5 != (undefined8 *)0x0) {
      uVar4 = HIDINT_GetSetReport(lVar2,(ulonglong)param_3,puVar5);
      uVar1 = (undefined4)uVar4;
      goto LAB_1c0001bb3;
    }
    uVar1 = 0xc0000010;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0001bb3;
    uVar6 = 0x31;
  }
  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar5,uVar6,
                    &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,(char)uVar1);
LAB_1c0001bb3:
  if (param_3 == 0xb0192) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar1;
    }
    uVar6 = 0x32;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar1;
    }
    uVar6 = 0x33;
  }
  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar5,uVar6,
                    &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,(char)uVar1);
  return uVar1;
}



===== HIDINT_GetSetReport @ 1c0001c24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 HIDINT_GetSetReport(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong lVar2;
  byte bVar3;
  code *pcVar4;
  undefined1 *_Dst;
  int iVar5;
  ulonglong uVar6;
  undefined1 *puVar7;
  byte bVar8;
  undefined2 uVar9;
  uint uVar10;
  ulonglong uVar11;
  undefined *in_stack_ffffffffffffffc8;
  
  uVar11 = 0;
  if (*(uint *)(param_1 + 0x48) != 0) {
    do {
      lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + uVar11 * 8);
      if (*(char *)(lVar1 + 0x68) == *(char *)((longlong)param_3 + 0xc)) {
        if (lVar1 != 0) {
          uVar10 = *(int *)(lVar1 + 0x34) + 1;
          if (*(uint *)(param_3 + 1) < uVar10) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return 0xc0000023;
            }
            WPP_RECORDER_SF_PP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x2b,
                               &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,(char)uVar10,
                               (char)*(uint *)(param_3 + 1));
            return 0xc0000023;
          }
          puVar7 = (undefined1 *)*param_3;
          iVar5 = (int)param_2;
          if (iVar5 == 0xb0191) {
            uVar11 = 0;
            if (*(int *)(lVar1 + 0x30) == 0) goto LAB_1c0001e98;
            goto LAB_1c0001d4e;
          }
          if (iVar5 == 0xb0191) goto LAB_1c0001e98;
          if (iVar5 != 0xb0192) {
            if (iVar5 == 0xb01a2) {
              *puVar7 = *(undefined1 *)((longlong)param_3 + 0xc);
              (**(code **)(WdfFunctions_01015 + 0x9e0))
                        (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x20));
              memcpy(puVar7 + 1,*(void **)(lVar1 + 0x50),(ulonglong)*(uint *)(lVar1 + 0x34));
              (**(code **)(WdfFunctions_01015 + 0x9e8))
                        (WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x20));
              return 0;
            }
            return 0;
          }
          _Dst = puVar7 + 1;
          *puVar7 = *(undefined1 *)((longlong)param_3 + 0xc);
          puVar7 = *(undefined1 **)(lVar1 + 0x60);
          goto LAB_1c0001ea0;
        }
        break;
      }
      uVar10 = (int)uVar11 + 1;
      uVar11 = (ulonglong)uVar10;
    } while (uVar10 < *(uint *)(param_1 + 0x48));
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
    return 0xc0000010;
  }
  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_3,0x2a,
                    &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,
                    *(undefined1 *)((longlong)param_3 + 0xc));
  return 0xc0000010;
LAB_1c0001d4e:
  lVar2 = *(longlong *)(*(longlong *)(lVar1 + 0x28) + uVar11 * 8);
  bVar8 = (byte)*(uint *)(lVar2 + 0x10);
  bVar3 = bVar8 & 7;
  uVar6 = (ulonglong)(*(uint *)(lVar2 + 0x10) >> 3);
  param_3 = (undefined8 *)(CONCAT71((int7)((ulonglong)param_3 >> 8),bVar8) & 0xffffffffffffff07);
  bVar8 = (byte)puVar7[uVar6 + 1] >> bVar3 & 1;
  if (bVar8 != (*(byte *)(uVar6 + *(longlong *)(lVar1 + 0x60)) >> bVar3 & 1)) {
    *(int *)(lVar2 + 0x40) = *(int *)(lVar2 + 0x40) + 1;
    if (*(longlong *)(lVar2 + 0x20) == 0) {
      if (bVar8 == 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar9 = 0x2e;
LAB_1c0001e64:
          in_stack_ffffffffffffffc8 = &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids;
          WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,uVar9,
                             &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,
                             (char)*(undefined2 *)(lVar2 + 0x34),(char)*(undefined2 *)(lVar2 + 0x36)
                            );
        }
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar9 = 0x2f;
        goto LAB_1c0001e64;
      }
    }
    else {
      if (bVar8 == 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0x2c,
                              in_stack_ffffffffffffffc8,(char)*(undefined2 *)(lVar2 + 0x34),
                              (char)*(undefined2 *)(lVar2 + 0x36),
                              (char)*(undefined4 *)(lVar2 + 0x2c));
        }
        pcVar4 = *(code **)(WdfFunctions_01015 + 0xd68);
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0x2d,
                              in_stack_ffffffffffffffc8,(char)*(undefined2 *)(lVar2 + 0x34),
                              (char)*(undefined2 *)(lVar2 + 0x36),
                              (char)*(undefined4 *)(lVar2 + 0x2c));
        }
        pcVar4 = *(code **)(WdfFunctions_01015 + 0xd60);
      }
      (*pcVar4)(WdfDriverGlobals,**(undefined8 **)(lVar2 + 0x20));
    }
  }
  uVar10 = (int)uVar11 + 1;
  uVar11 = (ulonglong)uVar10;
  if (*(uint *)(lVar1 + 0x30) <= uVar10) {
LAB_1c0001e98:
    _Dst = *(undefined1 **)(lVar1 + 0x60);
    puVar7 = puVar7 + 1;
LAB_1c0001ea0:
    memcpy(_Dst,puVar7,(ulonglong)*(uint *)(lVar1 + 0x34));
    return 0;
  }
  goto LAB_1c0001d4e;
}



===== HIDINT_OnControlStateToggle @ 1c0001f34 =====

ulonglong HIDINT_OnControlStateToggle(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong local_res8;
  longlong local_res10;
  
  local_res10 = 0;
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x40);
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x18) + 0x18);
  uVar4 = (ulonglong)(*(uint *)(param_1 + 0x10) >> 3);
  *(byte *)(uVar4 + lVar3) = *(byte *)(uVar4 + lVar3) ^ (byte)(1 << (*(uint *)(param_1 + 0x10) & 7))
  ;
  local_res8 = param_1;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    KeGetCurrentProcessorNumberEx(0);
    WPP_RECORDER_SF_DDDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  if ((*(int *)(lVar1 + 0x38) + 1U) % *(uint *)(lVar1 + 0x34) == *(uint *)(lVar1 + 0x3c)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,lVar3,0x26,
                        &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,
                        (char)*(undefined4 *)(param_1 + 0x2c));
    }
    Queue_DeleteDuplicatePair((longlong *)(lVar1 + 0x28),&local_res10);
    *(int *)(local_res10 + 0x3c) = *(int *)(local_res10 + 0x3c) + 2;
  }
  uVar2 = *(int *)(lVar1 + 0x38) + 1;
  uVar4 = (ulonglong)uVar2 / (ulonglong)*(uint *)(lVar1 + 0x34);
  if (uVar2 % *(uint *)(lVar1 + 0x34) != *(uint *)(lVar1 + 0x3c)) {
    memcpy((void *)((ulonglong)(*(int *)(lVar1 + 0x38) * *(uint *)(lVar1 + 0x30)) +
                   *(longlong *)(lVar1 + 0x28)),&local_res8,(ulonglong)*(uint *)(lVar1 + 0x30));
    uVar2 = *(int *)(lVar1 + 0x38) + 1;
    uVar4 = (ulonglong)uVar2 / (ulonglong)*(uint *)(lVar1 + 0x34);
    *(uint *)(lVar1 + 0x38) = uVar2 % *(uint *)(lVar1 + 0x34);
  }
  return uVar4;
}



===== HIDINT_ReadReport @ 1c00020b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HIDINT_ReadReport(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined1 *puVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined1 *local_res8 [2];
  longlong local_res18 [2];
  
  local_res8[0] = (undefined1 *)0x0;
  local_res18[1] = 0;
  local_res18[0] = 0;
  (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,0,local_res8,local_res18 + 1);
  puVar2 = local_res8[0];
  (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
  Queue_Pop((longlong *)(param_1 + 0x28),local_res18);
  (**(code **)(WdfFunctions_01015 + 0x488))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
  lVar3 = local_res18[0];
  lVar1 = *(longlong *)(local_res18[0] + 0x18);
  *puVar2 = *(undefined1 *)(lVar1 + 0x68);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x20));
  uVar4 = (ulonglong)(*(uint *)(lVar3 + 0x10) >> 3);
  *(byte *)(uVar4 + *(longlong *)(lVar1 + 0x50)) =
       *(byte *)(uVar4 + *(longlong *)(lVar1 + 0x50)) ^ (byte)(1 << (*(uint *)(lVar3 + 0x10) & 7));
  memcpy(puVar2 + 1,*(void **)(lVar1 + 0x50),(ulonglong)*(uint *)(lVar1 + 0x34));
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar1 + 0x20));
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    KeGetCurrentProcessorNumberEx(0);
    WPP_RECORDER_SF_DqDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_2,0,*(int *)(lVar1 + 0x34) + 1);
  return;
}



===== HIDINT_ReadReportReadyNotification @ 1c0002290 =====

void HIDINT_ReadReportReadyNotification(undefined8 param_1,longlong param_2,int *param_3)

{
  HIDINT_CompleteReadReports(param_2,param_2,param_3);
  return;
}



===== HIDINT_ReadReportRequest @ 1c00022a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int HIDINT_ReadReportRequest(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined2 uVar4;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res20 = 0;
  local_res18 = 0;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_HIDINT_DATA_TYPE_INFO_1c0009018);
  uVar3 = (ulonglong)(*(int *)(lVar2 + 0x70) + 1);
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))
                    (WdfDriverGlobals,param_2,uVar3,&local_res20,&local_res18);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar4 = 0x27;
  }
  else {
    uVar3 = *(ulonglong *)(lVar2 + 0x10);
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x8c8))(WdfDriverGlobals,param_2);
    if (-1 < iVar1) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0x103;
      }
      if (*(short *)(WPP_GLOBAL_Control + 0x48) == 0) {
        return 0x103;
      }
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,uVar3,0x29,
                        &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,(char)param_2);
      return 0x103;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar4 = 0x28;
  }
  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar3,uVar4,
                    &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,(char)iVar1);
  return iVar1;
}



===== HIDINT_SetReportRequest @ 1c00023fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 HIDINT_SetReportRequest(undefined8 param_1,undefined8 param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined2 uVar6;
  undefined1 auStackY_78 [32];
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_78;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_HIDINT_DATA_TYPE_INFO_1c0009018);
  puVar5 = &local_48;
  local_28 = 0;
  uStack_40 = 0;
  local_48 = 0x28;
  local_38 = 0;
  uStack_30 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2);
  if (local_38 < 0x10) {
    uVar1 = 0xc0000023;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc0000023;
    }
    uVar6 = 0x34;
  }
  else {
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_2);
    puVar5 = *(undefined8 **)(lVar3 + 0x70);
    if (puVar5 != (undefined8 *)0x0) {
      uVar4 = HIDINT_GetSetReport(lVar2,0xb0191,puVar5);
      uVar1 = (undefined4)uVar4;
      goto LAB_1c0002515;
    }
    uVar1 = 0xc0000010;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc0000010;
    }
    uVar6 = 0x35;
  }
  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar5,uVar6,
                    &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,(char)uVar1);
LAB_1c0002515:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar5,0x36,
                      &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,(char)uVar1);
  }
  return uVar1;
}



===== HIDINT_VhfSubmitReadReport @ 1c0002568 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HIDINT_VhfSubmitReadReport(longlong param_1)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  int iVar6;
  ulonglong uVar7;
  longlong local_res8;
  
  local_res8 = 0;
  (**(code **)(WdfFunctions_01015 + 0x480))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
  Queue_Pop((longlong *)(param_1 + 0x28),&local_res8);
  (**(code **)(WdfFunctions_01015 + 0x488))(WdfDriverGlobals,*(undefined8 *)(param_1 + 0x20));
  lVar4 = local_res8;
  puVar2 = *(undefined1 **)(param_1 + 0x98);
  lVar3 = *(longlong *)(local_res8 + 0x18);
  iVar5 = *(int *)(lVar3 + 0x34);
  uVar1 = *(undefined1 *)(lVar3 + 0x68);
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x20));
  uVar7 = (ulonglong)(*(uint *)(lVar4 + 0x10) >> 3);
  *(byte *)(uVar7 + *(longlong *)(lVar3 + 0x50)) =
       *(byte *)(uVar7 + *(longlong *)(lVar3 + 0x50)) ^ (byte)(1 << (*(uint *)(lVar4 + 0x10) & 7));
  *puVar2 = uVar1;
  uVar7 = (ulonglong)*(uint *)(lVar3 + 0x34);
  memcpy(puVar2 + 1,*(void **)(lVar3 + 0x50),uVar7);
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(lVar3 + 0x20));
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar7 = (ulonglong)*(ushort *)(lVar3 + 0x72);
    WPP_RECORDER_SF_dDDDDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  lVar3 = *(longlong *)(param_1 + 0x88);
  *(undefined8 *)(lVar3 + 0x128) = *(undefined8 *)(lVar3 + 0xa0);
  *(undefined1 *)(lVar3 + 0x130) = uVar1;
  *(int *)(lVar3 + 0x134) = iVar5 + 1;
  *(undefined1 **)(lVar3 + 0x138) = puVar2;
  if ((*(byte *)(lVar3 + 0xac) & 1) == 0) {
    iVar5 = Vhfi_SubmitReadReport(lVar3,lVar3,uVar7);
  }
  else {
    iVar5 = Pump_ClientRequestComplete((longlong *)(lVar3 + 0xb0),lVar3,uVar7);
  }
  iVar6 = 0;
  if (iVar5 != 0x103) {
    iVar6 = iVar5;
  }
  if ((iVar6 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar7,0x65,
                      &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,(char)iVar6);
  }
  return;
}



===== WPP_RECORDER_SF_ @ 1c0002784 =====

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



===== WPP_RECORDER_SF_DD @ 1c0002814 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DD(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,4,&param_7,4
               ,0);
  }
  WppAutoLogTrace(param_1,param_2,1,param_5,param_4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_DDD @ 1c00028f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDD(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,param_4,&param_6,4,&param_7,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,&WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,param_4,
                  &param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_DDDD @ 1c00029e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDDD
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,param_4,&param_6,4,&param_7,4,
               &param_8,4,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,param_4,&param_6,4,
                  &param_7,4,&param_8,4,&param_9,4,0);
  return;
}



===== WPP_RECORDER_SF_DDDDDDD @ 1c0002af4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDDDDDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,0x25,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,0x25,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,0);
  return;
}



===== WPP_RECORDER_SF_DqDDDDD @ 1c0002c5c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DqDDDDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,0x3b,&uStack0000000000000030,4,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,&uStack0000000000000060,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,0x3b,
                  &uStack0000000000000030,4,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,
                  &uStack0000000000000060,4,0);
  return;
}



===== WPP_RECORDER_SF_PP @ 1c0002dd4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_PP(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,8,&param_7,8
               ,0);
  }
  WppAutoLogTrace(param_1,2,1,param_5,param_4,&param_6,8,&param_7,8,0);
  return;
}



===== WPP_RECORDER_SF__guid__guid_ @ 1c0002ea8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF__guid__guid_(undefined8 param_1)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,0x42);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,0x42);
  return;
}



===== WPP_RECORDER_SF_dDDDDD @ 1c0002f84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dDDDDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,100,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,100,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  return;
}



===== WPP_RECORDER_SF_qDd @ 1c00030cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined4 local_18 [4];
  
  local_18[0] = 0xc0000001;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,0x15,&uStack0000000000000030,8,
               &uStack0000000000000038,4,local_18,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,0x15,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,local_18,4,0);
  return;
}



===== WPP_RECORDER_SF_qDq @ 1c00031c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,0x17,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,0x17,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,8,0);
  return;
}



===== WPP_RECORDER_SF_qdD @ 1c00032bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qdD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,0x16,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,0x16,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== HID_GetDeviceAttributes @ 1c00033b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int HID_GetDeviceAttributes(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined2 uVar4;
  undefined8 local_res18 [2];
  
  puVar3 = local_res18;
  local_res18[0] = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x860))(WdfDriverGlobals);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar4 = 0xc;
  }
  else {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
    puVar3 = (undefined8 *)0x0;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x628))
                      (WdfDriverGlobals,local_res18[0],0,lVar2 + 0x50,0x20);
    if (-1 < iVar1) {
      (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,0x20);
      return iVar1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar4 = 0xd;
  }
  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar3,uVar4,
                    &WPP_ba16477440ee33c7f3deac19edc20cbc_Traceguids,(char)iVar1);
  return iVar1;
}



===== HID_GetHidDescriptor @ 1c00034dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int HID_GetHidDescriptor(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined2 uVar4;
  undefined1 auStackY_58 [32];
  undefined8 local_28;
  undefined4 local_20;
  undefined2 local_1c;
  undefined1 local_1a;
  undefined2 local_19;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_58;
  puVar3 = &local_28;
  local_28 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x860))(WdfDriverGlobals);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar4 = 10;
  }
  else {
    local_20 = 0x12109;
    local_1c = 0x100;
    local_1a = 0x22;
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
    puVar3 = (undefined8 *)0x0;
    local_19 = *(undefined2 *)(lVar2 + 0x74);
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x628))(WdfDriverGlobals,local_28,0,&local_20);
    if (-1 < iVar1) {
      (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,9);
      return iVar1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar4 = 0xb;
  }
  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar3,uVar4,
                    &WPP_ba16477440ee33c7f3deac19edc20cbc_Traceguids,(char)iVar1);
  return iVar1;
}



===== HID_GetReportDescriptor @ 1c0003648 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int HID_GetReportDescriptor(undefined8 param_1,undefined8 param_2)

{
  ushort uVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  void *local_res18;
  
  local_res18 = (void *)0x0;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_HIDINT_DATA_TYPE_INFO_1c0009018);
  uVar1 = *(ushort *)(lVar3 + 0x74);
  uVar4 = (ulonglong)uVar1;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_2,uVar4,&local_res18,0);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar4,0xe,
                        &WPP_ba16477440ee33c7f3deac19edc20cbc_Traceguids,(char)iVar2);
    }
  }
  else {
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,param_1,PTR__WDF_HIDINT_DATA_TYPE_INFO_1c0009018);
    memcpy(local_res18,*(void **)(lVar3 + 0x78),(ulonglong)uVar1);
    (**(code **)(WdfFunctions_01015 + 0x898))(WdfDriverGlobals,param_2,(ulonglong)uVar1);
  }
  return iVar2;
}



===== HID_GetString @ 1c0003770 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 HID_GetString(void)

{
  ulonglong _Size;
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  wchar_t *_Src;
  undefined8 uVar5;
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals);
  lVar1 = *(longlong *)(lVar2 + 0xb8);
  uVar4 = *(uint *)(lVar1 + 0x20) & 0xffff;
  if (uVar4 == 0xe) {
    _Src = L"Microsoft";
  }
  else if (uVar4 == 0xf) {
    _Src = L"HID Button over Interrupt Driver";
  }
  else {
    if (uVar4 != 0x10) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,lVar1,0xf,
                          &WPP_ba16477440ee33c7f3deac19edc20cbc_Traceguids,
                          (char)*(uint *)(lVar1 + 0x20));
      }
      return 0xc000000d;
    }
    _Src = L"1.0";
  }
  lVar3 = -1;
  uVar5 = 0;
  do {
    lVar3 = lVar3 + 1;
  } while (_Src[lVar3] != L'\0');
  _Size = lVar3 * 2 + 2;
  if (*(uint *)(lVar1 + 8) < _Size) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_PP(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),_Src,lVar1,0x10,
                         &WPP_ba16477440ee33c7f3deac19edc20cbc_Traceguids,(char)_Size,
                         (char)*(uint *)(lVar1 + 8));
    }
    uVar5 = 0xc0000023;
  }
  else {
    memcpy(*(void **)(lVar2 + 0x70),_Src,_Size);
    *(ulonglong *)(lVar2 + 0x38) = _Size;
  }
  return uVar5;
}



===== HID_InternalDeviceControl @ 1c00038b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HID_InternalDeviceControl
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               uint param_5)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  if (param_5 == 0xb0003) {
    iVar1 = HID_GetHidDescriptor(uVar2,param_2);
  }
  else if (param_5 == 0xb0007) {
    iVar1 = HID_GetReportDescriptor(uVar2,param_2);
  }
  else if (param_5 == 0xb000b) {
    iVar1 = HIDINT_ReadReportRequest(uVar2,param_2);
  }
  else if (param_5 == 0xb0013) {
    uVar2 = HID_GetString();
    iVar1 = (int)uVar2;
  }
  else if (param_5 == 0xb0027) {
    iVar1 = HID_GetDeviceAttributes(uVar2,param_2);
  }
  else if (param_5 == 0xb0191) {
    iVar1 = HIDINT_SetReportRequest(uVar2,param_2);
  }
  else {
    if ((param_5 != 0xb0192) && (param_5 != 0xb01a2)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,(ulonglong)param_5,0x11,
                          &WPP_ba16477440ee33c7f3deac19edc20cbc_Traceguids,(char)param_5);
      }
      iVar1 = -0x3fffff45;
      goto LAB_1c00039b9;
    }
    iVar1 = HIDINT_GetReportRequest(uVar2,param_2,param_5);
  }
  if (iVar1 == 0x103) {
    return;
  }
LAB_1c00039b9:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar1);
  return;
}



===== BitMap_ClearAllBits @ 1c00039e4 =====

void BitMap_ClearAllBits(uint *param_1)

{
  memset(*(void **)(param_1 + 2),0,(ulonglong)*param_1);
  return;
}



===== BitMap_Create @ 1c0003a04 =====

uint BitMap_Create(uint *param_1,uint param_2,int param_3)

{
  void *_Dst;
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_2 + 7;
  uVar1 = 0xffffffff;
  if (param_2 <= uVar2) {
    uVar1 = uVar2;
  }
  uVar1 = uVar1 >> 3;
  if (uVar2 < param_2) {
    uVar1 = 0;
  }
  uVar2 = -(uint)(uVar2 < param_2) & -(uint)(uVar2 < param_2) & 0xc0000095;
  if (-1 < (int)uVar2) {
    _Dst = (void *)ExAllocatePool2(0x40,uVar1,0x746e4948);
    *(void **)(param_1 + 2) = _Dst;
    if (_Dst == (void *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      if (param_3 != 0) {
        memset(_Dst,0xff,(ulonglong)uVar1);
      }
      *param_1 = uVar1;
      uVar2 = 0;
    }
  }
  return uVar2;
}



===== BitMap_SetAllBits @ 1c0003ab8 =====

void BitMap_SetAllBits(uint *param_1)

{
  memset(*(void **)(param_1 + 2),0xff,(ulonglong)*param_1);
  return;
}



===== Queue_Clear @ 1c0003adc =====

void Queue_Clear(longlong param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}



===== Queue_Create @ 1c0003aec =====

undefined8 Queue_Create(longlong *param_1,undefined8 param_2,uint param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  if ((ulonglong)param_3 * 8 < 0x100000000) {
    lVar1 = ExAllocatePool2(0x40,(ulonglong)param_3 * 8 & 0xffffffff,0x746e4948);
    uVar2 = 0;
    *param_1 = lVar1;
    if (lVar1 == 0) {
      uVar2 = 0xc000009a;
    }
    else {
      *(undefined4 *)(param_1 + 1) = 8;
      *(uint *)((longlong)param_1 + 0xc) = param_3;
    }
  }
  else {
    uVar2 = 0xc0000095;
  }
  return uVar2;
}



===== Queue_DeleteDuplicatePair @ 1c0003b68 =====

ulonglong Queue_DeleteDuplicatePair(longlong *param_1,void *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  
  uVar5 = *(uint *)((longlong)param_1 + 0x14);
  uVar3 = *(uint *)(param_1 + 2);
  uVar7 = 0xffffffff;
  uVar6 = 0xffffffff;
  if (uVar5 != uVar3) {
    do {
      uVar8 = (ulonglong)(uVar5 + 1) % (ulonglong)*(uint *)((longlong)param_1 + 0xc);
      if ((uint)uVar8 != uVar3) {
        uVar3 = *(uint *)(param_1 + 1);
        uVar4 = (ulonglong)uVar3;
        do {
          uVar6 = (uint)uVar8;
          uVar2 = RtlCompareMemory((ulonglong)((int)uVar4 * uVar5) + *param_1,
                                   (ulonglong)((int)uVar4 * uVar6) + *param_1,uVar3);
          uVar3 = *(uint *)(param_1 + 1);
          uVar4 = (ulonglong)uVar3;
          if (uVar2 == uVar4) {
            uVar7 = uVar8;
            if (uVar6 != 0xffffffff) goto LAB_1c0003bf8;
            break;
          }
          uVar8 = (ulonglong)(uVar6 + 1) % (ulonglong)*(uint *)((longlong)param_1 + 0xc);
        } while ((int)uVar8 != (int)param_1[2]);
      }
      uVar6 = (uint)uVar7;
      uVar3 = *(uint *)(param_1 + 2);
      uVar5 = (uVar5 + 1) % *(uint *)((longlong)param_1 + 0xc);
    } while (uVar5 != uVar3);
  }
LAB_1c0003bf8:
  memcpy(param_2,(void *)((ulonglong)(*(uint *)(param_1 + 1) * uVar5) + *param_1),
         (ulonglong)*(uint *)(param_1 + 1));
  while( true ) {
    uVar3 = *(uint *)((longlong)param_1 + 0xc);
    uVar5 = (uVar5 + 1) % uVar3;
    if (uVar5 == uVar6) break;
    uVar1 = *(uint *)(param_1 + 1);
    memcpy((void *)((ulonglong)(uVar1 * (((uVar5 - 1) + uVar3) % uVar3)) + *param_1),
           (void *)((ulonglong)(uVar1 * uVar5) + *param_1),(ulonglong)uVar1);
  }
  while( true ) {
    uVar6 = (uVar6 + 1) % uVar3;
    if (uVar6 == *(uint *)(param_1 + 2)) break;
    uVar5 = *(uint *)(param_1 + 1);
    memcpy((void *)((ulonglong)(uVar5 * (((((uVar6 - 1) + uVar3) % uVar3 - 1) + uVar3) % uVar3)) +
                   *param_1),(void *)((ulonglong)(uVar5 * uVar6) + *param_1),(ulonglong)uVar5);
    uVar3 = *(uint *)((longlong)param_1 + 0xc);
  }
  uVar5 = (((*(uint *)(param_1 + 2) - 1) + uVar3) % uVar3 - 1) + uVar3;
  *(uint *)(param_1 + 2) = uVar5 % uVar3;
  return (ulonglong)uVar5 / (ulonglong)uVar3;
}



===== Queue_Pop @ 1c0003cdc =====

undefined8 Queue_Pop(longlong *param_1,void *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = *(int *)((longlong)param_1 + 0x14);
  if (iVar1 == (int)param_1[2]) {
    uVar2 = 0x8000001a;
  }
  else {
    memcpy(param_2,(void *)((ulonglong)(*(uint *)(param_1 + 1) * iVar1) + *param_1),
           (ulonglong)*(uint *)(param_1 + 1));
    uVar2 = 0;
    *(uint *)((longlong)param_1 + 0x14) = (iVar1 + 1U) % *(uint *)((longlong)param_1 + 0xc);
  }
  return uVar2;
}



===== GetObjectTypeName @ 1c0003d30 =====

char * GetObjectTypeName(short param_1)

{
  if (param_1 == 0) {
    return "INTEGER";
  }
  if (param_1 == 1) {
    return "STRING";
  }
  if (param_1 == 2) {
    return "BUFFER";
  }
  if ((param_1 == 3) || (param_1 == 4)) {
    return "PACKAGE";
  }
  return "UNKNOWN";
}



===== WPP_RECORDER_SF_sD @ 1c0003d80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sD(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_fc2dc4c0d6a934c1c5c0f33ba3d3c5c0_Traceguids,0xb,"_DSD",5,&uStack0000000000000038
               ,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_fc2dc4c0d6a934c1c5c0f33ba3d3c5c0_Traceguids,0xb,"_DSD",5,
                  &uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_sd @ 1c0003e58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sd(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_fc2dc4c0d6a934c1c5c0f33ba3d3c5c0_Traceguids,0x11,"_DSD",5,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,2,1,&WPP_fc2dc4c0d6a934c1c5c0f33ba3d3c5c0_Traceguids,0x11,"_DSD",5,
                  &uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_ss @ 1c0003f30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ss(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  char *in_stack_00000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000038 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (in_stack_00000038[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = in_stack_00000038;
    if (in_stack_00000038 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_fc2dc4c0d6a934c1c5c0f33ba3d3c5c0_Traceguids,0x10,"_DSD",5,pcVar1,lVar3,0);
  }
  lVar3 = -1;
  if (in_stack_00000038 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (in_stack_00000038[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (in_stack_00000038 == (char *)0x0) {
    in_stack_00000038 = "NULL";
  }
  WppAutoLogTrace(param_1,2,1,&WPP_fc2dc4c0d6a934c1c5c0f33ba3d3c5c0_Traceguids,0x10,"_DSD",5,
                  in_stack_00000038,lVar2,0);
  return;
}



===== WPP_RECORDER_SF_sss @ 1c000406c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sss(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  char *pcVar5;
  char *in_stack_00000038;
  char *in_stack_00000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    if (in_stack_00000040 == (char *)0x0) {
      lVar4 = 5;
    }
    else {
      lVar3 = -1;
      do {
        lVar4 = lVar3;
        lVar3 = lVar4 + 1;
      } while (in_stack_00000040[lVar3] != '\0');
      lVar4 = lVar4 + 2;
    }
    pcVar5 = in_stack_00000040;
    if (in_stack_00000040 == (char *)0x0) {
      pcVar5 = "NULL";
    }
    if (in_stack_00000038 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (in_stack_00000038[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = in_stack_00000038;
    if (in_stack_00000038 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_fc2dc4c0d6a934c1c5c0f33ba3d3c5c0_Traceguids,0xc,"_DSD",5,pcVar1,lVar3,pcVar5,
               lVar4,0);
  }
  if (in_stack_00000040 == (char *)0x0) {
    lVar4 = 5;
  }
  else {
    lVar3 = -1;
    do {
      lVar4 = lVar3;
      lVar3 = lVar4 + 1;
    } while (in_stack_00000040[lVar3] != '\0');
    lVar4 = lVar4 + 2;
  }
  if (in_stack_00000040 == (char *)0x0) {
    in_stack_00000040 = "NULL";
  }
  lVar3 = -1;
  if (in_stack_00000038 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (in_stack_00000038[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (in_stack_00000038 == (char *)0x0) {
    in_stack_00000038 = "NULL";
  }
  WppAutoLogTrace(param_1,2,1,&WPP_fc2dc4c0d6a934c1c5c0f33ba3d3c5c0_Traceguids,0xc,"_DSD",5,
                  in_stack_00000038,lVar2,in_stack_00000040,lVar4,0);
  return;
}



===== FxStubDriverUnloadCommon @ 1c0004218 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0009198 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_1c0009198 + 0x50);
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_1c0004271:
      if (ppvVar1 == (void **)0x0) goto LAB_1c00042c7;
      if (ppvVar2 <= ppvVar1) goto LAB_1c00042df;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if ((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) goto LAB_1c0004271;
LAB_1c00042c7:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_1c00042df:
  WdfVersionUnbind(&DAT_1c0009410,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 1c0004320 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2,undefined8 param_3)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2,param_3);
  return;
}



===== FxDriverEntryWorker @ 1c0004354 =====

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
    _DAT_1c0009410 = 0x2080000;
    _DAT_1c0009418 = &DAT_1c0009200;
    RtlCopyUnicodeString(&DAT_1c0009410);
    puVar4 = &WdfBindInfo;
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_1c0009410,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2,puVar4);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_1c0009408 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_1c0009410);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_1c0009198 != &__KMDF_CLASS_BIND_START) {
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



===== FxStubDriverUnload @ 1c00044e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_1c0009408 != (code *)0x0) && (DAT_1c0009408 != FxStubDriverUnload)) {
    (*DAT_1c0009408)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 1c0004514 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0004539) */
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
    if ((void **)0x1c000918f < ppvVar2) break;
    if (((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_1c0009198 = (undefined *)ppvVar2;
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



===== FxStubInitTypes @ 1c000469c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c00046b9) */
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
    if ((void **)0x1c00091af < ppvVar2) break;
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



===== VhfAsyncOperationComplete @ 1c0004764 =====

void VhfAsyncOperationComplete(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  
  lVar1 = param_1[0x12];
  param_1[0x14] = param_1[0xf];
  *(uint *)((longlong)param_1 + 0x8c) = (uint)*(ushort *)(param_1 + 0x18);
  param_1[0x12] = param_1[0x19];
  param_1[0x15] = param_1[0x11];
  param_1[0x16] = lVar1;
  *(int *)(param_1 + 0x17) = (int)param_2;
  Pump_ClientRequestComplete(param_1,param_2,param_3);
  return;
}



===== VhfDelete @ 1c00047b4 =====

void VhfDelete(longlong param_1,undefined *param_2,undefined8 param_3)

{
  bool bVar1;
  char cVar2;
  undefined1 uVar3;
  
  bVar1 = false;
  cVar2 = KeGetCurrentIrql();
  if (cVar2 == '\0') {
    bVar1 = true;
    LOCK();
    *(undefined4 *)(param_1 + 0x254) = 1;
    UNLOCK();
  }
  else {
    param_2 = WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar3 = KeGetCurrentIrql();
      WPP_SF_c(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,uVar3);
    }
  }
  if (*(char *)(param_1 + 0xa8) == '\0') {
    Vhfi_Delete(param_1,param_2,param_3);
  }
  else {
    LOCK();
    *(undefined4 *)(param_1 + 0x250) = 2;
    UNLOCK();
    Pump_Stop((longlong *)(param_1 + 0xb0),param_2);
    Pump_Stop((longlong *)(param_1 + 0x140),param_2);
  }
  if (bVar1) {
    KeWaitForSingleObject(param_1 + 0x238,0,0,0,0);
    Vhfi_Cleanup(param_1);
  }
  return;
}



===== VhfStart @ 1c00048a8 =====

undefined8 VhfStart(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17);
  }
  uVar1 = 0;
  if (*(char *)(param_1 + 0xa8) == '\0') {
    if ((*(byte *)(param_1 + 0xac) & 1) != 0) {
      Pump_Start((longlong *)(param_1 + 0xb0));
    }
    if ((*(uint *)(param_1 + 0xac) & 0x1e) != 0) {
      Pump_Start((longlong *)(param_1 + 0x140));
    }
    *(undefined1 *)(param_1 + 0xa8) = 1;
  }
  else {
    uVar1 = 0xc0000184;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,param_3,0xc0000184);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,param_3,uVar1);
  }
  return 0;
}



===== Vhfi_Cleanup @ 1c000499c =====

void Vhfi_Cleanup(longlong param_1)

{
  if (*(longlong *)(param_1 + 200) != 0) {
    IoFreeIrp();
  }
  if (*(longlong *)(param_1 + 0x158) != 0) {
    IoFreeIrp();
  }
  if (*(longlong *)(param_1 + 0x188) != 0) {
    IoFreeMdl();
  }
  if (*(longlong *)(param_1 + 0x208) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x208),0x4b464856);
  }
  if (*(longlong *)(param_1 + 0x220) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x220),0x4b464856);
  }
  if (*(longlong *)(param_1 + 0x230) != 0) {
    IoFreeIrp();
  }
  if (*(longlong *)(param_1 + 0x98) != 0) {
    ObfDereferenceObject();
  }
  ExFreePoolWithTag(param_1,0x4b464856);
  return;
}



===== Vhfi_CleanupOnDeleteComplete @ 1c0004a78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Vhfi_CleanupOnDeleteComplete(longlong param_1)

{
  bool bVar1;
  
  if (*(code **)(param_1 + 0x80) != (code *)0x0) {
    (**(code **)(param_1 + 0x80))(*(undefined8 *)(param_1 + 8));
  }
  LOCK();
  bVar1 = *(int *)(param_1 + 0x254) == 1;
  if (bVar1) {
    *(int *)(param_1 + 0x254) = 0;
  }
  UNLOCK();
  if (bVar1) {
    KeSetEvent(param_1 + 0x238,0,0);
  }
  else {
    Vhfi_Cleanup(param_1);
  }
  return;
}



===== Vhfi_Delete @ 1c0004ae0 =====

void Vhfi_Delete(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x230);
  IoReuseIrp(lVar1,0xc00000bb);
  lVar2 = *(longlong *)(lVar1 + 0xb8);
  *(undefined1 *)(lVar2 + -0x48) = 0xe;
  *(undefined4 *)(lVar2 + -0x30) = 0xb0329;
  *(undefined4 *)(lVar2 + -0x38) = 8;
  *(longlong *)(lVar1 + 0x18) = param_1 + 0x228;
  lVar2 = *(longlong *)(lVar1 + 0xb8);
  *(code **)(lVar2 + -0x10) = Vhfi_DeleteComplete;
  *(longlong *)(lVar2 + -8) = param_1;
  *(undefined1 *)(lVar2 + -0x45) = 0xe0;
  iVar3 = IofCallDriver(*(undefined8 *)(param_1 + 0x98),lVar1);
  if (iVar3 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,param_3,iVar3);
    }
    Vhfi_CleanupOnDeleteComplete(param_1);
  }
  return;
}



===== Vhfi_DeleteComplete @ 1c0004bb0 =====

undefined8 Vhfi_DeleteComplete(undefined8 param_1,longlong param_2,longlong param_3)

{
  if ((((*(int *)(param_2 + 0x30) < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control))
      && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,param_3,*(int *)(param_2 + 0x30));
  }
  Vhfi_CleanupOnDeleteComplete(param_3);
  return 0xc0000016;
}



===== Vhfi_InvokeAsyncOperationCallback @ 1c0004c10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Vhfi_InvokeAsyncOperationCallback(longlong param_1)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = *(int *)(param_1 + 0x1c0);
  if (iVar1 == 2) {
    pcVar2 = *(code **)(param_1 + 0x70);
  }
  else if (iVar1 == 4) {
    pcVar2 = *(code **)(param_1 + 0x60);
  }
  else if (iVar1 == 8) {
    pcVar2 = *(code **)(param_1 + 0x68);
  }
  else {
    if (iVar1 != 0x10) {
      return;
    }
    pcVar2 = *(code **)(param_1 + 0x78);
  }
  *(undefined1 *)(param_1 + 0x21c) = *(undefined1 *)(param_1 + 0x1c8);
  *(undefined4 *)(param_1 + 0x218) = *(undefined4 *)(param_1 + 0x1cc);
  *(undefined8 *)(param_1 + 0x210) = *(undefined8 *)(param_1 + 0x1d0);
  if (*(void **)(param_1 + 0x220) != (void *)0x0) {
    memset(*(void **)(param_1 + 0x220),0,(ulonglong)*(uint *)(param_1 + 0x10));
  }
  (*pcVar2)(*(undefined8 *)(param_1 + 8),param_1 + 0x140,*(undefined8 *)(param_1 + 0x220),
            (undefined8 *)(param_1 + 0x210));
  return;
}



===== Vhfi_InvokeReadyForNextReadReportCallback @ 1c0004ce0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Vhfi_InvokeReadyForNextReadReportCallback(longlong param_1)

{
  (**(code **)(param_1 + 0x58))(*(undefined8 *)(param_1 + 8));
  return;
}



===== Vhfi_SubmitReadReport @ 1c0004d00 =====

int Vhfi_SubmitReadReport(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x18) >> 8),
                                 *(undefined1 *)(*(longlong *)(param_1 + 0x18) + 0x4c)),0);
  if (lVar3 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b);
    }
    iVar2 = -0x3fffff66;
  }
  else {
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(undefined1 *)(lVar1 + -0x48) = 0xe;
    *(undefined4 *)(lVar1 + -0x30) = 0xb0331;
    *(undefined4 *)(lVar1 + -0x38) = 0x18;
    *(longlong *)(lVar3 + 0x18) = param_1 + 0x128;
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(undefined8 *)(lVar1 + -8) = 0;
    *(code **)(lVar1 + -0x10) = Vhfi_SubmitReadReportComplete;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    iVar2 = IofCallDriver(*(undefined8 *)(param_1 + 0x98),lVar3);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,param_3,iVar2);
    }
    if (iVar2 < 0) {
      IoFreeIrp(lVar3);
    }
  }
  return iVar2;
}



===== Vhfi_SubmitReadReportComplete @ 1c0004e10 =====

undefined8 Vhfi_SubmitReadReportComplete(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,param_3,*(undefined4 *)(param_2 + 0x30)
            );
  }
  IoFreeIrp(param_2);
  return 0xc0000016;
}



===== WPP_SF_ @ 1c0004e6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2)

{
  (*pfnWppTraceMessage)(param_1,0x2b,&WPP_c39c93078f9237c833d6826115b1fc67_Traceguids,param_2,0);
  return;
}



===== WPP_SF_c @ 1c0004ea0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_c(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined1 param_4)

{
  undefined1 local_res20 [8];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_c39c93078f9237c833d6826115b1fc67_Traceguids,0x1a,local_res20,1,0);
  return;
}



===== WPP_SF_d @ 1c0004eec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_d(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_c39c93078f9237c833d6826115b1fc67_Traceguids,param_2,local_res20,4,0);
  return;
}



===== Pump_ClientRequestComplete @ 1c0004f34 =====

int Pump_ClientRequestComplete(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  int iVar5;
  
  plVar1 = param_1 + 1;
  uVar4 = KeAcquireSpinLockRaiseToDpc(plVar1);
  *(undefined1 *)(param_1 + 2) = uVar4;
  if (*(int *)((longlong)param_1 + 0x14) == 4) {
    *(undefined4 *)((longlong)param_1 + 0x14) = 5;
    KeReleaseSpinLock(plVar1,uVar4);
    lVar2 = param_1[3];
    IoReuseIrp(lVar2,0xc00000bb);
    lVar3 = *(longlong *)(lVar2 + 0xb8);
    *(undefined1 *)(lVar3 + -0x48) = 0xe;
    *(int *)(lVar3 + -0x30) = (int)param_1[10];
    *(int *)(lVar3 + -0x38) = (int)param_1[0xc];
    *(longlong *)(lVar2 + 0x18) = param_1[0xb];
    lVar3 = *(longlong *)(lVar2 + 0xb8);
    *(code **)(lVar3 + -0x10) = Pump_VhfRequestComplete;
    *(longlong **)(lVar3 + -8) = param_1;
    *(undefined1 *)(lVar3 + -0x45) = 0xe0;
    iVar5 = IofCallDriver(*(undefined8 *)(*param_1 + 0x98),lVar2);
    if (iVar5 < 0) {
      uVar4 = KeAcquireSpinLockRaiseToDpc(plVar1);
      *(undefined4 *)((longlong)param_1 + 0x14) = 1;
      *(undefined1 *)(param_1 + 2) = uVar4;
      KeReleaseSpinLock(plVar1,uVar4);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_Ld(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,param_3,(int)param_1[10],
                  (char)iVar5);
      }
    }
  }
  else {
    iVar5 = -0x3ffffe7c;
    KeReleaseSpinLock();
  }
  return iVar5;
}



===== Pump_PendNotifyToVhf @ 1c000507c =====

void Pump_PendNotifyToVhf(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  int iVar4;
  longlong lVar5;
  
  lVar1 = param_1[3];
  IoReuseIrp(lVar1,0xc00000bb);
  lVar5 = *(longlong *)(lVar1 + 0xb8);
  *(undefined1 *)(lVar5 + -0x48) = 0xe;
  *(int *)(lVar5 + -0x30) = (int)param_1[4];
  *(int *)(lVar5 + -0x38) = (int)param_1[6];
  *(int *)(lVar5 + -0x40) = (int)param_1[8];
  *(longlong *)(lVar1 + 0x18) = param_1[5];
  *(longlong *)(lVar1 + 8) = param_1[9];
  lVar2 = *(longlong *)(lVar1 + 0xb8);
  *(code **)(lVar2 + -0x10) = Pump_VhfNotifyComplete;
  *(longlong **)(lVar2 + -8) = param_1;
  *(undefined1 *)(lVar2 + -0x45) = 0xe0;
  iVar4 = IofCallDriver(*(undefined8 *)(*param_1 + 0x98),lVar1);
  if (iVar4 < 0) {
    uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 1);
    *(undefined4 *)((longlong)param_1 + 0x14) = 1;
    *(undefined1 *)(param_1 + 2) = uVar3;
    KeReleaseSpinLock(param_1 + 1,uVar3);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_Ld(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,lVar5,(int)param_1[4],(char)iVar4);
    }
  }
  return;
}



===== Pump_Start @ 1c000518c =====

void Pump_Start(longlong *param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 1);
  *(undefined4 *)((longlong)param_1 + 0x14) = 3;
  *(undefined1 *)(param_1 + 2) = uVar1;
  KeReleaseSpinLock(param_1 + 1,uVar1);
  Pump_PendNotifyToVhf(param_1);
  return;
}



===== Pump_Stop @ 1c00051e0 =====

void Pump_Stop(longlong *param_1,undefined8 param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  bool bVar4;
  bool bVar5;
  undefined1 uVar6;
  undefined7 uVar7;
  uint uVar8;
  ulonglong uVar9;
  
  uVar7 = (undefined7)((ulonglong)param_2 >> 8);
  bVar5 = false;
  bVar4 = false;
  uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 1);
  uVar8 = *(uint *)((longlong)param_1 + 0x14);
  uVar9 = (ulonglong)uVar8;
  *(undefined1 *)(param_1 + 2) = uVar6;
  if (((uVar8 != 0) && (uVar9 = (ulonglong)(uVar8 - 1), uVar8 - 1 != 0)) &&
     (uVar9 = (ulonglong)(uVar8 - 2), uVar8 - 2 != 0)) {
    if (uVar8 == 3) {
      *(undefined1 *)((longlong)param_1 + 0x11) = 1;
      bVar4 = true;
      uVar9 = 0;
      goto LAB_1c0005249;
    }
    uVar8 = uVar8 - 4;
    uVar9 = (ulonglong)uVar8;
    if ((uVar8 != 0) && (uVar8 == 1)) {
      *(undefined1 *)((longlong)param_1 + 0x11) = 1;
      goto LAB_1c0005249;
    }
  }
  bVar5 = true;
LAB_1c0005249:
  KeReleaseSpinLock(param_1 + 1);
  if (bVar4) {
    IoCancelIrp(param_1[3]);
  }
  if (bVar5) {
    lVar3 = *param_1;
    LOCK();
    piVar1 = (int *)(lVar3 + 0x250);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      Vhfi_Delete(lVar3,CONCAT71(uVar7,uVar6),uVar9);
    }
  }
  return;
}



===== Pump_VhfNotifyComplete @ 1c00052b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 Pump_VhfNotifyComplete(undefined8 param_1,longlong param_2,longlong *param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  bool bVar4;
  undefined1 uVar5;
  longlong lVar6;
  longlong *plVar7;
  
  bVar4 = false;
  lVar6 = param_2;
  plVar7 = param_3;
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_3 + 1);
  *(undefined1 *)(param_3 + 2) = uVar5;
  if (*(char *)((longlong)param_3 + 0x11) == '\0') {
    if (*(int *)(param_2 + 0x30) < 0) {
      *(undefined4 *)((longlong)param_3 + 0x14) = 1;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_Ld(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,plVar7,(int)param_3[4],
                  (char)*(undefined4 *)(param_2 + 0x30));
      }
    }
    else {
      *(undefined4 *)((longlong)param_3 + 0x14) = 4;
      bVar4 = true;
    }
  }
  else {
    lVar3 = *param_3;
    *(undefined4 *)((longlong)param_3 + 0x14) = 2;
    LOCK();
    piVar1 = (int *)(lVar3 + 0x250);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      Vhfi_Delete(lVar3,lVar6,plVar7);
    }
  }
  KeReleaseSpinLock(param_3 + 1,(char)param_3[2]);
  if (bVar4) {
    (*(code *)param_3[0xd])(*param_3);
  }
  return 0xc0000016;
}



===== Pump_VhfRequestComplete @ 1c00053a0 =====

undefined8 Pump_VhfRequestComplete(undefined8 param_1,longlong param_2,longlong *param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  bool bVar4;
  undefined1 uVar5;
  longlong lVar6;
  longlong *plVar7;
  
  bVar4 = false;
  lVar6 = param_2;
  plVar7 = param_3;
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_3 + 1);
  *(undefined1 *)(param_3 + 2) = uVar5;
  if (*(char *)((longlong)param_3 + 0x11) == '\0') {
    if (*(int *)(param_2 + 0x30) < 0) {
      *(undefined4 *)((longlong)param_3 + 0x14) = 1;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_Ld(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,plVar7,(int)param_3[10],
                  (char)*(undefined4 *)(param_2 + 0x30));
      }
    }
    else {
      *(undefined4 *)((longlong)param_3 + 0x14) = 3;
      bVar4 = true;
    }
  }
  else {
    lVar3 = *param_3;
    *(undefined4 *)((longlong)param_3 + 0x14) = 2;
    LOCK();
    piVar1 = (int *)(lVar3 + 0x250);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      Vhfi_Delete(lVar3,lVar6,plVar7);
    }
  }
  KeReleaseSpinLock(param_3 + 1,(char)param_3[2]);
  if (bVar4) {
    Pump_PendNotifyToVhf(param_3);
  }
  return 0xc0000016;
}



===== WPP_SF_Ld @ 1c000548c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Ld(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_533d3f78771f31f4537606060113c633_Traceguids,param_2,local_res20,4,
             &param_5,4,0);
  return;
}



===== _guard_check_icall @ 1c00054f0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0005508 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000552c =====

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



===== __cpu_features_init @ 1c00055a0 =====

/* WARNING: Removing unreachable block (ram,0x0001c000560a) */
/* WARNING: Removing unreachable block (ram,0x0001c00055b9) */
/* WARNING: Removing unreachable block (ram,0x0001c00055aa) */

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



===== __security_check_cookie @ 1c0005670 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c00056b0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c00056e0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c00056e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0005710 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0005780 =====

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



===== memset @ 1c0005a80 =====

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



===== __memset_repmovs @ 1c0005bc0 =====

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



===== __memset_query @ 1c0005c40 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0005cc0 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0005e00 =====

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



===== __memset_spec_plain @ 1c0005e80 =====

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



===== DriverUnload @ 1c000c010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void DriverUnload(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0xd,
                      &WPP_b55d0c434e0b34142fdce029b8a2137d_Traceguids,(char)uVar1);
  }
  WppCleanupKm(uVar1);
  return;
}



===== WppCleanupKm @ 1c000c084 =====

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



===== WppInitKm @ 1c000c134 =====

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



===== WppLoadTracingSupport @ 1c000c210 =====

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



===== WppTraceCallback @ 1c000c360 =====

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



===== HIDINT_EvtDeviceAdd @ 1c000c5f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int HIDINT_EvtDeviceAdd(undefined8 param_1,undefined8 param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  code *pcVar5;
  undefined2 uVar6;
  undefined8 local_res10;
  undefined8 local_res18;
  ulonglong local_158;
  code *pcStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined *local_128;
  undefined8 local_118;
  undefined4 local_110;
  undefined1 local_10b;
  code *local_e8;
  undefined4 local_c8;
  undefined4 local_b8;
  undefined4 local_b4;
  code *local_90;
  code *local_88;
  code *local_80;
  code *local_70;
  
  uVar3 = 0x60;
  local_res10 = param_2;
  memset(&local_118,0,0x60);
  local_148 = 0;
  local_158 = (ulonglong)(uint)local_158;
  local_res18 = 0;
  local_138 = 0;
  uStack_130 = 0;
  local_b4 = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,uVar3,10,
                      &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,uVar1);
    param_2 = local_res10;
  }
  (**(code **)(WdfFunctions_01015 + 0x200))(WdfDriverGlobals,param_2);
  (**(code **)(WdfFunctions_01015 + 0x1c8))(WdfDriverGlobals,local_res10,0);
  memset(&local_b8,0,0x90);
  local_90 = HIDINT_EvtDevicePrepareHardware;
  local_88 = HIDINT_EvtDeviceReleaseHardware;
  local_70 = HIDINT_EvtDeviceSelfManagedIoInit;
  local_80 = HIDINT_EvtDeviceSelfManagedIoCleanup;
  local_b8 = 0x90;
  (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,local_res10,&local_b8);
  local_148 = 0;
  pcVar5 = (code *)&local_158;
  local_158 = 0x38;
  uStack_140 = 0x100000001;
  local_128 = PTR__WDF_HIDINT_DATA_TYPE_INFO_1c0009018;
  pcStack_150 = HIDINT_EvtDeviceCleanupCallback;
  local_138 = 0;
  uStack_130 = 0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 600))(WdfDriverGlobals,&local_res10,pcVar5,&local_res18)
  ;
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar2;
    }
    uVar3 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
    uVar6 = 0xb;
  }
  else {
    uVar3 = local_res18;
    pcVar5 = (code *)PTR__WDF_HIDINT_DATA_TYPE_INFO_1c0009018;
    puVar4 = (undefined8 *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
    *puVar4 = local_res18;
    *(undefined4 *)(puVar4 + 10) = 0x20;
    iVar2 = HIDINT_ParseDeviceSpecificData(local_res18,uVar3,pcVar5);
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar2;
      }
      uVar6 = 0xc;
    }
    else {
      pcVar5 = (code *)(puVar4 + 3);
      local_128 = (undefined *)0x0;
      local_148 = 0;
      uStack_140 = 0x100000001;
      uStack_130 = 0;
      local_138 = local_res18;
      pcStack_150 = (code *)0x0;
      local_158 = 0x38;
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,&local_158);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar2;
        }
        uVar6 = 0xd;
      }
      else {
        if (*(char *)(puVar4 + 0x10) != '\0') {
          iVar2 = HIDINT_VhfInitialize(local_res18);
          goto LAB_1c000ca40;
        }
        pcVar5 = (code *)&local_118;
        local_110 = 0;
        local_118._0_4_ = 0x60;
        local_118._4_4_ = 3;
        iVar2 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                          (WdfDriverGlobals,local_res18,pcVar5,0,puVar4 + 2);
        if (iVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
            return iVar2;
          }
          uVar6 = 0xe;
        }
        else {
          pcVar5 = HIDINT_ReadReportReadyNotification;
          iVar2 = (**(code **)(WdfFunctions_01015 + 0x530))
                            (WdfDriverGlobals,puVar4[2],HIDINT_ReadReportReadyNotification,puVar4);
          if (iVar2 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return iVar2;
            }
            uVar6 = 0xf;
          }
          else {
            memset(&local_118,0,0x60);
            local_c8 = 0xffffffff;
            local_e8 = HID_InternalDeviceControl;
            pcVar5 = (code *)&local_118;
            local_118._0_4_ = 0x60;
            local_110 = 2;
            local_10b = 1;
            local_118._4_4_ = 2;
            iVar2 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                              (WdfDriverGlobals,local_res18,pcVar5,0,puVar4 + 1);
            if (-1 < iVar2) goto LAB_1c000ca40;
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return iVar2;
            }
            uVar6 = 0x10;
          }
        }
      }
    }
    uVar3 = local_res18;
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pcVar5,uVar6,
                     &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,(char)uVar3,(char)iVar2);
LAB_1c000ca40:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar1 = (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,pcVar5,0x11,
                       &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,uVar1,(char)iVar2);
  }
  return iVar2;
}



===== HIDINT_EvtDevicePrepareHardware @ 1c000cac0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int HIDINT_EvtDevicePrepareHardware(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  undefined8 *puVar7;
  char *pcVar8;
  byte bVar9;
  ulonglong uVar10;
  uint uVar11;
  undefined8 *puVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  undefined8 *puVar15;
  undefined2 uVar16;
  undefined8 *puVar17;
  undefined8 local_res20;
  undefined8 *in_stack_fffffffffffffef8;
  undefined1 uVar18;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined *local_b8;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined8 local_a0;
  undefined4 local_98;
  code *local_90;
  code *local_88;
  undefined8 local_68;
  undefined8 local_60;
  undefined4 local_4c;
  
  local_res20 = 0;
  local_b8 = (undefined *)((ulonglong)local_b8 & 0xffffffff00000000);
  local_a4 = 0;
  uVar14 = 100;
  local_e8 = 0;
  uStack_e0 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  memset(&local_a8,0,100);
  uVar18 = (undefined1)param_1;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_fffffffffffffef8 = (undefined8 *)&WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids;
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,uVar14,0x12,
                      &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,uVar18);
  }
  puVar15 = (undefined8 *)PTR__WDF_HIDINT_DATA_TYPE_INFO_1c0009018;
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,param_1);
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x980))(WdfDriverGlobals,param_3);
  if (uVar4 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar16 = 0x13;
      bVar9 = 4;
LAB_1c000cba9:
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),bVar9,puVar15,uVar16,
                        &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,uVar18);
    }
  }
  else {
    puVar15 = (undefined8 *)0x746e4948;
    puVar7 = (undefined8 *)ExAllocatePool2(0x100,(ulonglong)uVar4 << 3);
    if (puVar7 != (undefined8 *)0x0) {
      puVar12 = (undefined8 *)0x0;
      if (uVar4 != 0) {
        puVar17 = puVar7;
        do {
          puVar15 = puVar12;
          pcVar8 = (char *)(**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals);
          if (*pcVar8 != '\x02') {
            iVar5 = -0x3fffffff;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
            }
            goto LAB_1c000ce6a;
          }
          memset(&local_a8,0,0x68);
          local_90 = HIDINT_EvtInterruptIsr;
          local_88 = HIDINT_EvtInterruptDpc;
          local_a8 = 0x68;
          local_98 = 2;
          local_4c = 2;
          local_a0 = *(undefined8 *)(lVar6 + 0x18);
          local_68 = (**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,param_2,puVar12);
          local_60 = (**(code **)(WdfFunctions_01015 + 0x988))(WdfDriverGlobals,param_3,puVar12);
          in_stack_fffffffffffffef8 = &local_res20;
          local_d8 = 0;
          puVar15 = (undefined8 *)&local_a8;
          uStack_d0 = 0x100000001;
          local_b8 = PTR__WDF_INTERRUPT_DATA_TYPE_INFO_1c0009040;
          uStack_e0 = 0;
          local_e8 = 0x38;
          local_c8 = 0;
          uStack_c0 = 0;
          iVar5 = (**(code **)(WdfFunctions_01015 + 0x468))
                            (WdfDriverGlobals,param_1,puVar15,&local_e8);
          if (iVar5 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
            }
            goto LAB_1c000ce6a;
          }
          if (*(longlong *)(lVar6 + 0x20) == 0) {
            *(undefined8 *)(lVar6 + 0x20) = local_res20;
          }
          puVar15 = (undefined8 *)
                    (**(code **)(WdfFunctions_01015 + 0x650))
                              (WdfDriverGlobals,local_res20,
                               PTR__WDF_INTERRUPT_DATA_TYPE_INFO_1c0009040);
          *puVar15 = local_res20;
          *puVar17 = puVar15;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          }
          uVar11 = (int)puVar12 + 1;
          puVar12 = (undefined8 *)(ulonglong)uVar11;
          puVar17 = puVar17 + 1;
        } while (uVar11 < uVar4);
      }
      uVar10 = 0;
      if (*(int *)(lVar6 + 0x48) != 0) {
        do {
          uVar13 = 0;
          lVar1 = *(longlong *)(*(longlong *)(lVar6 + 0x40) + uVar10 * 8);
          if (*(int *)(lVar1 + 0x30) != 0) {
            do {
              lVar2 = *(longlong *)(*(longlong *)(lVar1 + 0x28) + uVar13 * 8);
              uVar11 = *(uint *)(lVar2 + 0x2c);
              puVar15 = (undefined8 *)(ulonglong)uVar11;
              if (uVar11 < uVar4) {
                lVar3 = puVar7[(longlong)puVar15];
                if (*(longlong *)(lVar3 + 8) != 0) {
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar15,0x19,
                                        in_stack_fffffffffffffef8,(char)uVar11,
                                        (char)*(undefined2 *)(lVar2 + 0x34),
                                        (char)*(undefined2 *)(lVar2 + 0x36));
                  }
                  iVar5 = -0x3febfffb;
                  goto LAB_1c000ce6a;
                }
                *(longlong *)(lVar3 + 8) = lVar2;
                *(longlong *)(lVar2 + 0x20) = lVar3;
              }
              else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar15,0x18,
                                    in_stack_fffffffffffffef8,(char)*(undefined2 *)(lVar2 + 0x34),
                                    (char)*(undefined2 *)(lVar2 + 0x36),(char)uVar11);
              }
              uVar11 = (int)uVar13 + 1;
              uVar13 = (ulonglong)uVar11;
            } while (uVar11 < *(uint *)(lVar1 + 0x30));
          }
          uVar11 = (int)uVar10 + 1;
          uVar10 = (ulonglong)uVar11;
        } while (uVar11 < *(uint *)(lVar6 + 0x48));
      }
      puVar15 = puVar7;
      iVar5 = HIDINT_InferOneShotControls(param_1,uVar4,(longlong)puVar7);
      if ((iVar5 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar15,0x1a,
                           &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,uVar18,(char)iVar5);
      }
LAB_1c000ce6a:
      ExFreePoolWithTag(puVar7,0x746e4948);
      goto LAB_1c000ce7e;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar16 = 0x14;
      bVar9 = 2;
      goto LAB_1c000cba9;
    }
  }
  iVar5 = -0x3fffff66;
LAB_1c000ce7e:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar15,0x1b,
                       &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,uVar18,(char)iVar5);
  }
  return iVar5;
}



===== HIDINT_EvtDeviceReleaseHardware @ 1c000cfe0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 HIDINT_EvtDeviceReleaseHardware(undefined1 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined *puVar6;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0x1c,
                      &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,param_1);
  }
  puVar6 = PTR__WDF_HIDINT_DATA_TYPE_INFO_1c0009018;
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  uVar5 = 0;
  *(undefined8 *)(lVar2 + 0x20) = 0;
  if (*(int *)(lVar2 + 0x48) != 0) {
    do {
      lVar1 = *(longlong *)(*(longlong *)(lVar2 + 0x40) + uVar5 * 8);
      if (lVar1 != 0) {
        uVar4 = 0;
        if (*(int *)(lVar1 + 0x30) != 0) {
          do {
            puVar6 = *(undefined **)(*(longlong *)(lVar1 + 0x28) + uVar4 * 8);
            if (puVar6 != (undefined *)0x0) {
              *(undefined8 *)(puVar6 + 0x20) = 0;
            }
            uVar3 = (int)uVar4 + 1;
            uVar4 = (ulonglong)uVar3;
          } while (uVar3 < *(uint *)(lVar1 + 0x30));
        }
        BitMap_ClearAllBits((uint *)(lVar1 + 0x38));
        BitMap_ClearAllBits((uint *)(lVar1 + 0x48));
        BitMap_SetAllBits((uint *)(lVar1 + 0x58));
      }
      uVar3 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar3;
    } while (uVar3 < *(uint *)(lVar2 + 0x48));
  }
  Queue_Clear(lVar2 + 0x28);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar6,0x1d,
                       &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,param_1,0);
  }
  return 0;
}



===== HIDINT_EvtDeviceSelfManagedIoCleanup @ 1c000d110 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void HIDINT_EvtDeviceSelfManagedIoCleanup(undefined *param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined *puVar2;
  undefined1 uVar3;
  
  uVar3 = SUB81(param_1,0);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0x21,
                      &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,uVar3);
  }
  puVar2 = PTR__WDF_HIDINT_DATA_TYPE_INFO_1c0009018;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  if (*(char *)(lVar1 + 0x80) != '\0') {
    VhfDelete(*(longlong *)(lVar1 + 0x88),param_1,puVar2);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar2,0x22,
                      &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,uVar3);
  }
  return;
}



===== HIDINT_EvtDeviceSelfManagedIoInit @ 1c000d1e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong HIDINT_EvtDeviceSelfManagedIoInit
                    (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined *puVar4;
  undefined1 uVar5;
  
  uVar5 = (undefined1)param_1;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0x1e,
                      &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,uVar5);
  }
  puVar4 = PTR__WDF_HIDINT_DATA_TYPE_INFO_1c0009018;
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals);
  if (*(char *)(lVar1 + 0x80) == '\0') {
    uVar3 = 0;
  }
  else {
    uVar2 = VhfStart(*(longlong *)(lVar1 + 0x88),param_1,puVar4);
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar3;
      }
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar4,0x1f,
                         &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,uVar5,(char)uVar2);
    }
    else if (*(char *)(lVar1 + 0x81) != '\0') {
      LOCK();
      if (*(int *)(lVar1 + 0x90) == 0) {
        *(int *)(lVar1 + 0x90) = 1;
      }
      UNLOCK();
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,puVar4,0x20,
                       &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,uVar5,(char)uVar3);
  }
  return uVar3;
}



===== HIDINT_InferOneShotControls @ 1c000d318 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int HIDINT_InferOneShotControls(undefined8 param_1,int param_2,longlong param_3)

{
  longlong lVar1;
  int iVar2;
  byte bVar3;
  byte *pbVar4;
  ushort uVar5;
  longlong *plVar6;
  undefined2 uVar7;
  ulonglong uVar8;
  int local_res20 [2];
  longlong local_18 [2];
  
  local_18[0] = 0;
  local_res20[0] = 0;
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,param_1,PTR__WDF_HIDINT_DATA_TYPE_INFO_1c0009018);
  plVar6 = local_18;
  iVar2 = ACPI_EvaluateMethod(param_1,0x5352435f,plVar6,local_res20);
  lVar1 = local_18[0];
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar7 = 0x5c;
LAB_1c000d4b7:
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,plVar6,uVar7,
                        &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,(char)iVar2);
    }
  }
  else if (local_res20[0] == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,plVar6,0x5d,
                       &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids);
    }
    iVar2 = -0x3ffffddb;
  }
  else if (*(int *)(local_18[0] + 8) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,plVar6,0x5e,
                       &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids);
    }
    iVar2 = -0x3febfff5;
  }
  else {
    if (0x17 < *(ushort *)(local_18[0] + 0xe)) {
      uVar8 = 0;
      pbVar4 = (byte *)(local_18[0] + 0x10);
      do {
        bVar3 = *pbVar4;
        do {
          if ((char)bVar3 < '\0') {
            uVar5 = *(short *)(pbVar4 + 1) + 3;
          }
          else {
            uVar5 = (bVar3 & 7) + 1;
            bVar3 = bVar3 & 0x78;
          }
          plVar6 = (longlong *)(ulonglong)uVar5;
          if (bVar3 == 0x78) goto LAB_1c000d4d9;
          if ((int)uVar8 == param_2) {
            iVar2 = -0x3febfff1;
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_1c000d4d9;
            uVar7 = 0x5f;
            goto LAB_1c000d4b7;
          }
        } while ((bVar3 != 0x8c) || (pbVar4[4] != 0));
        if ((pbVar4[7] & 4) == 0) {
          *(undefined1 *)(*(longlong *)(*(longlong *)(param_3 + uVar8 * 8) + 8) + 0x28) = 1;
        }
        uVar8 = (ulonglong)((int)uVar8 + 1);
        pbVar4 = pbVar4 + (longlong)plVar6;
      } while( true );
    }
    iVar2 = -0x3febfff1;
  }
LAB_1c000d4d9:
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0x746e4948);
  }
  return iVar2;
}



===== HIDINT_ParseDeviceSpecificData @ 1c000d514 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int HIDINT_ParseDeviceSpecificData(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined8 uVar4;
  longlong ***ppplVar5;
  int iVar6;
  ulonglong uVar7;
  short *psVar8;
  ulonglong uVar9;
  longlong ****pppplVar10;
  undefined2 uVar11;
  undefined1 auStackY_a8 [32];
  undefined1 uVar12;
  uint local_68;
  undefined4 local_64;
  longlong ***local_60;
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_48 = 0;
  uStack_40 = 0;
  local_68 = 0;
  local_50 = 4;
  uVar12 = (undefined1)param_1;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,0x3c,
                      &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,uVar12);
  }
  local_60 = (longlong ***)0x0;
  local_58 = (undefined8 *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,param_1,PTR__WDF_HIDINT_DATA_TYPE_INFO_1c0009018);
  pppplVar10 = &local_60;
  iVar6 = ACPI_EvaluateMethod(param_1,0x4453445f,(longlong *)pppplVar10,&local_68);
  ppplVar5 = local_60;
  if (iVar6 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pppplVar10,0x3d,
                        &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,(char)iVar6);
    }
    goto LAB_1c000d97b;
  }
  if (local_68 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pppplVar10,0x3e,
                       &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids);
    }
    iVar6 = -0x3ffffddb;
    goto LAB_1c000d97b;
  }
  if (*(int *)(local_60 + 1) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pppplVar10,0x3f,
                       &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids);
    }
    iVar6 = -0x3febfff5;
    goto LAB_1c000d97b;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,pppplVar10,0x40,
                      &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,uVar12);
  }
  psVar8 = (short *)((longlong)ppplVar5 + 0xc);
  uVar9 = (ulonglong)*(uint *)((longlong)ppplVar5 + 4) + (longlong)psVar8;
  local_68 = 0;
  bVar3 = false;
  if ((longlong)ppplVar5 + 0x13U < uVar9) {
    local_64 = 0x10;
    do {
      pppplVar10 = (longlong ****)0x470d9ce8;
      if ((local_68 & 1) == 0) {
        if (psVar8[1] != (short)local_64) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0x470d9ce8,10,
                               &WPP_fc2dc4c0d6a934c1c5c0f33ba3d3c5c0_Traceguids,0x10,(char)psVar8[1]
                              );
          }
          iVar6 = -0x3febfff8;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pppplVar10,0x41,
                             &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids);
          }
          goto LAB_1c000d97b;
        }
        iVar6 = *(int *)(psVar8 + 2);
        iVar1 = *(int *)(psVar8 + 4);
        local_48 = *(undefined8 *)(psVar8 + 2);
        iVar2 = *(int *)(psVar8 + 6);
        uVar4 = *(undefined8 *)(psVar8 + 6);
        uStack_40._4_4_ = (int)((ulonglong)uVar4 >> 0x20);
        uStack_40 = uVar4;
        if (iVar6 == -0x59429db) {
          if (((iVar1 != 0x470d9ce8) || (iVar2 != -0x354c385e)) || (uStack_40._4_4_ != 0x2e28c436))
          goto LAB_1c000d79e;
          bVar3 = true;
        }
        else if (iVar6 == -0x4f4e74b4) {
          if (((iVar1 != 0x4475893c) || (iVar2 != -0x31f28678)) || (uStack_40._4_4_ != 0x1423e935))
          goto LAB_1c000d79e;
          *(undefined1 *)(local_58 + 0x10) = 1;
        }
        else if (((iVar6 == 0x36f8e4c4) && (iVar1 == 0x472fed5e)) &&
                ((iVar2 == -0x6b1be96b && (uStack_40._4_4_ == 0x5756a8e4)))) {
          *(undefined2 *)(local_58 + 0x10) = 0x101;
        }
        else {
LAB_1c000d79e:
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF__guid__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
          }
        }
      }
      else if (bVar3) {
        if (*psVar8 == 3) {
          pppplVar10 = (longlong ****)(ulonglong)(ushort)psVar8[1];
          uVar9 = HIDINT_ParseHidButtonDeviceDataDescriptor(local_58,psVar8 + 2,pppplVar10);
          iVar6 = (int)uVar9;
        }
        else {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,0x470d9ce8,0x43,
                             &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids);
          }
          iVar6 = -0x3febfff8;
        }
        goto LAB_1c000d97b;
      }
      pppplVar10 = (longlong ****)0x470d9ce8;
      local_68 = local_68 + 1;
      uVar7 = (ulonglong)(ushort)psVar8[1];
      if ((ushort)psVar8[1] < (ushort)local_50) {
        uVar7 = 4;
      }
      psVar8 = (short *)((longlong)psVar8 + uVar7 + 4);
    } while ((longlong)psVar8 + 7U < uVar9);
    if (!bVar3) goto LAB_1c000d942;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar11 = 0x45;
      goto LAB_1c000d95f;
    }
  }
  else {
LAB_1c000d942:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar11 = 0x44;
LAB_1c000d95f:
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pppplVar10,uVar11,
                       &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids);
    }
  }
  iVar6 = -0x3febfff1;
LAB_1c000d97b:
  if (ppplVar5 != (longlong ***)0x0) {
    ExFreePoolWithTag(ppplVar5,0x746e4948);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,pppplVar10,0x46,
                       &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,uVar12,(char)iVar6);
  }
  return iVar6;
}



===== HIDINT_ParseHidButtonDeviceDataDescriptor @ 1c000d9fc =====

ulonglong HIDINT_ParseHidButtonDeviceDataDescriptor
                    (undefined8 *param_1,short *param_2,longlong ****param_3)

{
  longlong ****pppplVar1;
  longlong ***ppplVar2;
  longlong ******pppppplVar3;
  longlong *****ppppplVar4;
  code *pcVar5;
  uint uVar6;
  ulonglong uVar7;
  longlong ****pppplVar8;
  longlong ******pppppplVar9;
  char cVar10;
  undefined2 uVar11;
  ulonglong uVar12;
  char local_res18 [8];
  longlong ****local_48;
  longlong ****local_40;
  longlong ******local_38;
  longlong ******local_30;
  
  cVar10 = '\0';
  local_40 = (longlong ****)&local_48;
  local_res18[0] = '\0';
  uVar12 = ((ulonglong)param_3 & 0xffffffff) + (longlong)param_2;
  local_48 = (longlong ****)&local_48;
  local_30 = (longlong ******)&local_38;
  local_38 = (longlong ******)&local_38;
  for (; (longlong)param_2 + 7U < uVar12; param_2 = (short *)((longlong)param_2 + uVar7 + 4)) {
    if (*param_2 != 3) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_3,0x47,
                          &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,cVar10);
      }
      uVar6 = 0xc0140008;
      goto LAB_1c000db09;
    }
    param_3 = (longlong ****)(ulonglong)(ushort)param_2[1];
    uVar6 = HIDINT_ParseHidButtonInfo
                      ((longlong)param_1,(longlong)(param_2 + 2),(uint)(ushort)param_2[1],
                       (longlong)&local_48,(longlong)&local_38,local_res18);
    if ((int)uVar6 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000db09;
      uVar11 = 0x48;
      goto LAB_1c000dae7;
    }
    uVar7 = (ulonglong)(ushort)param_2[1];
    cVar10 = cVar10 + '\x01';
    if ((ushort)param_2[1] < 4) {
      uVar7 = 4;
    }
  }
  param_3 = (longlong ****)&local_38;
  uVar12 = HIDINT_ProcessHidButtonInfo(param_1,&local_48,param_3);
  uVar6 = (uint)uVar12;
  if ((int)uVar6 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar11 = 0x49;
LAB_1c000dae7:
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_3,uVar11,
                        &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,(char)uVar6);
    }
LAB_1c000db09:
    pppplVar8 = local_48;
    if (&local_48 != (longlong *****)local_48) {
      do {
        pppplVar1 = (longlong ****)*pppplVar8;
        if (((longlong ****)pppplVar1[1] != pppplVar8) ||
           (ppplVar2 = pppplVar8[1], (longlong ****)*ppplVar2 != pppplVar8)) goto LAB_1c000dc26;
        *ppplVar2 = (longlong **)pppplVar1;
        pppplVar1[1] = ppplVar2;
        ExFreePoolWithTag(pppplVar8,0x746e4948);
        pppplVar8 = pppplVar1;
      } while (&local_48 != (longlong *****)pppplVar1);
    }
    pppppplVar9 = local_38;
    if (&local_38 != (longlong *******)local_38) {
      do {
        pppppplVar3 = (longlong ******)*pppppplVar9;
        if (((longlong ******)pppppplVar3[1] != pppppplVar9) ||
           (ppppplVar4 = pppppplVar9[1], (longlong ******)*ppppplVar4 != pppppplVar9)) {
LAB_1c000dc26:
          pcVar5 = (code *)swi(0x29);
          (*pcVar5)(3);
          pcVar5 = (code *)swi(3);
          uVar12 = (*pcVar5)();
          return uVar12;
        }
        *ppppplVar4 = (longlong ****)pppppplVar3;
        pppppplVar3[1] = ppppplVar4;
        ExFreePoolWithTag(pppppplVar9,0x746e4948);
        pppppplVar9 = pppppplVar3;
      } while (&local_38 != (longlong *******)pppppplVar3);
    }
  }
  return (ulonglong)uVar6;
}



===== HIDINT_ParseHidButtonInfo @ 1c000dc34 =====

int HIDINT_ParseHidButtonInfo
              (longlong param_1,longlong param_2,int param_3,longlong param_4,longlong param_5,
              char *param_6)

{
  ushort uVar1;
  code *pcVar2;
  int iVar3;
  ulonglong uVar4;
  longlong *plVar5;
  longlong *plVar6;
  uint uVar7;
  short *psVar8;
  undefined8 uVar9;
  undefined2 uVar10;
  longlong lVar11;
  
  iVar3 = *(int *)(param_2 + 4);
  uVar1 = *(ushort *)(param_2 + 2);
  uVar7 = 4;
  if (3 < uVar1) {
    uVar7 = (uint)uVar1;
  }
  uVar7 = param_3 + (-4 - uVar7);
  uVar4 = 4;
  if (3 < uVar1) {
    uVar4 = (ulonglong)uVar1;
  }
  psVar8 = (short *)(param_2 + 4 + uVar4);
  if (iVar3 == 0) {
    uVar9 = 0x746e4948;
    plVar5 = (longlong *)ExAllocatePool2(0x40);
    if (plVar5 == (longlong *)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3fffff66;
      }
      uVar10 = 0x4d;
      goto LAB_1c000dea5;
    }
    plVar6 = plVar5;
    iVar3 = ACPI_ParseArguments(&CollectionParseTable,4,psVar8,(ulonglong)uVar7,(longlong)plVar5,
                                0x78);
    if (-1 < iVar3) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        psVar8 = (short *)(ulonglong)*(ushort *)(plVar5 + 0xe);
        WPP_RECORDER_SF_DDDD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                   (ulonglong)*(ushort *)((longlong)plVar5 + 0x72),psVar8,0x4f,plVar6,
                   (char)*(ushort *)(plVar5 + 0xe),(char)*(ushort *)((longlong)plVar5 + 0x72),
                   (char)plVar5[0xd],(char)*(undefined4 *)((longlong)plVar5 + 0x6c));
      }
      if ((char)plVar5[0xd] == '\0') {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3febfff8;
        }
        WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,psVar8,0x50,
                           &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,(char)plVar5[0xe],
                           (char)*(undefined2 *)((longlong)plVar5 + 0x72));
        return -0x3febfff8;
      }
      if (*(int *)((longlong)plVar5 + 0x6c) != 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,psVar8,0x51,plVar6,
                              (char)*(int *)((longlong)plVar5 + 0x6c),(char)plVar5[0xe],
                              (char)*(undefined2 *)((longlong)plVar5 + 0x72));
        }
        return -0x3fffff45;
      }
      plVar6 = *(longlong **)(param_4 + 8);
      if (*plVar6 == param_4) goto LAB_1c000e02a;
      goto LAB_1c000e023;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000df2d;
    uVar10 = 0x4e;
  }
  else {
    if (iVar3 != 1) {
      if ((iVar3 != 2) || (*param_6 != '\0')) {
        return -0x3febfff8;
      }
      lVar11 = param_1 + 0x50;
      iVar3 = ACPI_ParseArguments(&DeviceParseTable,3,psVar8,(ulonglong)uVar7,lVar11,0x20);
      if (-1 < iVar3) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,
                              (ulonglong)*(ushort *)(param_1 + 0x54),0x4c,lVar11,
                              (char)*(ushort *)(param_1 + 0x54),
                              (char)*(undefined2 *)(param_1 + 0x56),
                              (char)*(undefined2 *)(param_1 + 0x58));
        }
        *param_6 = '\x01';
        return iVar3;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return iVar3;
      }
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,psVar8,0x4b,
                        &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,(char)iVar3);
      return iVar3;
    }
    param_4 = 0x48;
    uVar9 = 0x746e4948;
    plVar5 = (longlong *)ExAllocatePool2(0x40,0x48);
    if (plVar5 == (longlong *)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3fffff66;
      }
      uVar10 = 0x52;
LAB_1c000dea5:
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar9,uVar10,
                       &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids);
      return -0x3fffff66;
    }
    plVar6 = plVar5;
    iVar3 = ACPI_ParseArguments(&ControlParseTable,4,psVar8,(ulonglong)uVar7,(longlong)plVar5,0x48);
    if (-1 < iVar3) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_DDDD
                  (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                   (ulonglong)*(ushort *)((longlong)plVar5 + 0x34),psVar8,0x54,plVar6,
                   (char)*(ushort *)((longlong)plVar5 + 0x34),
                   (char)*(undefined2 *)((longlong)plVar5 + 0x36),
                   (char)*(undefined4 *)((longlong)plVar5 + 0x2c),(char)plVar5[6]);
      }
      plVar6 = *(longlong **)(param_5 + 8);
      if (*plVar6 == param_5) {
        *plVar5 = param_5;
        plVar5[1] = (longlong)plVar6;
        *plVar6 = (longlong)plVar5;
        *(longlong **)(param_5 + 8) = plVar5;
        return iVar3;
      }
LAB_1c000e023:
      pcVar2 = (code *)swi(0x29);
      plVar6 = (longlong *)(*pcVar2)(3);
LAB_1c000e02a:
      *plVar5 = param_4;
      plVar5[1] = (longlong)plVar6;
      *plVar6 = (longlong)plVar5;
      *(longlong **)(param_4 + 8) = plVar5;
      return iVar3;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000df2d;
    uVar10 = 0x53;
  }
  WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,psVar8,uVar10,
                    &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,(char)iVar3);
LAB_1c000df2d:
  ExFreePoolWithTag(plVar5,0x746e4948);
  return iVar3;
}



===== HIDINT_ProcessHidButtonInfo @ 1c000e05c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong HIDINT_ProcessHidButtonInfo(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  ushort uVar1;
  undefined8 uVar2;
  code *pcVar3;
  undefined1 auVar4 [16];
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  undefined8 *puVar11;
  longlong *plVar12;
  uint uVar13;
  undefined1 *puVar14;
  undefined8 *puVar15;
  uint uVar16;
  undefined8 *puVar17;
  undefined2 uVar18;
  int iVar19;
  int iVar20;
  undefined1 auStackY_a8 [8];
  undefined1 auStackY_a0 [24];
  undefined8 in_stack_ffffffffffffff78;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  puVar14 = auStackY_a8;
  local_38 = local_38 & 0xffffffff00000000;
  puVar11 = (undefined8 *)*param_3;
  iVar19 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  for (; param_3 != puVar11; puVar11 = (undefined8 *)*puVar11) {
    plVar9 = (longlong *)*param_2;
    if (param_2 == plVar9) {
LAB_1c000e0c3:
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc0140005;
      }
      WPP_RECORDER_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_3,0x55,
                          in_stack_ffffffffffffff78,(char)*(undefined4 *)(puVar11 + 6),
                          (char)*(undefined2 *)((longlong)puVar11 + 0x34),
                          (char)*(undefined2 *)((longlong)puVar11 + 0x36));
      return 0xc0140005;
    }
    while ((uint)*(byte *)(plVar9 + 0xd) != *(uint *)(puVar11 + 6)) {
      plVar9 = (longlong *)*plVar9;
      if (param_2 == plVar9) goto LAB_1c000e0c3;
    }
    puVar11[3] = plVar9;
    iVar19 = iVar19 + 1;
    *(int *)(plVar9 + 6) = (int)plVar9[6] + 1;
  }
  iVar20 = 0;
  puVar17 = param_3;
  for (puVar15 = (undefined8 *)*param_2; param_2 != puVar15; puVar15 = (undefined8 *)*puVar15) {
    if (*(uint *)(puVar15 + 6) == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc0140005;
      }
      WPP_RECORDER_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar17,0x56,
                         &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,
                         (char)*(undefined2 *)(puVar15 + 0xe),
                         (char)*(undefined2 *)((longlong)puVar15 + 0x72));
      return 0xc0140005;
    }
    lVar7 = ExAllocatePool2(0x40,(ulonglong)*(uint *)(puVar15 + 6) << 3,0x746e4948);
    puVar15[5] = lVar7;
    if (lVar7 == 0) {
      return 0xc000009a;
    }
    uVar6 = 0;
    plVar9 = (longlong *)*param_3;
    while (plVar12 = plVar9, param_3 != plVar12) {
      plVar9 = (longlong *)*plVar12;
      if ((undefined8 *)plVar12[3] == puVar15) {
        if (((longlong *)plVar9[1] != plVar12) ||
           (plVar10 = (longlong *)plVar12[1], (longlong *)*plVar10 != plVar12)) goto LAB_1c000e493;
        *plVar10 = (longlong)plVar9;
        plVar9[1] = (longlong)plVar10;
        *(int *)(plVar12 + 2) = (int)uVar6;
        *(longlong **)(puVar15[5] + uVar6 * 8) = plVar12;
        uVar6 = (ulonglong)((int)uVar6 + 1);
      }
    }
    uVar5 = *(uint *)(puVar15 + 6) + 7;
    if (uVar5 < *(uint *)(puVar15 + 6)) {
      return 0xc0000095;
    }
    *(uint *)((longlong)puVar15 + 0x34) = uVar5 >> 3;
    puVar11 = puVar15 + 4;
    local_38 = 0;
    local_48 = *param_1;
    local_58 = 0;
    uStack_40 = 0;
    uStack_60 = 0;
    local_68 = 0x38;
    uStack_50 = 0x100000001;
    uVar5 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,&local_68);
    if ((int)uVar5 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return (ulonglong)uVar5;
      }
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar11,0x57,
                         &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,(char)*param_1,(char)uVar5
                        );
      return (ulonglong)uVar5;
    }
    uVar5 = BitMap_Create((uint *)(puVar15 + 7),*(uint *)(puVar15 + 6),0);
    if ((int)uVar5 < 0) {
      return (ulonglong)uVar5;
    }
    uVar5 = BitMap_Create((uint *)(puVar15 + 9),*(uint *)(puVar15 + 6),0);
    if ((int)uVar5 < 0) {
      return (ulonglong)uVar5;
    }
    puVar11 = (undefined8 *)(ulonglong)*(uint *)(puVar15 + 6);
    puVar17 = (undefined8 *)0x1;
    uVar5 = BitMap_Create((uint *)(puVar15 + 0xb),*(uint *)(puVar15 + 6),1);
    if ((int)uVar5 < 0) {
      return (ulonglong)uVar5;
    }
    if (*(uint *)(param_1 + 0xe) < *(uint *)((longlong)puVar15 + 0x34)) {
      *(uint *)(param_1 + 0xe) = *(uint *)((longlong)puVar15 + 0x34);
    }
    *(int *)(puVar15 + 2) = iVar20;
    iVar20 = iVar20 + 1;
    puVar15[3] = param_1;
  }
  *(int *)(param_1 + 9) = iVar20;
  if (iVar20 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar17,0x58,
                       &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids);
    }
    return 0xc0140005;
  }
  uVar6 = Queue_Create(param_1 + 5,puVar11,iVar19 * 4);
  if ((int)uVar6 < 0) {
    return uVar6 & 0xffffffff;
  }
  puVar15 = (undefined8 *)0x746e4948;
  uVar5 = 0x746e4948;
  iVar20 = 0x40;
  plVar9 = (longlong *)0x746e4948;
  lVar7 = ExAllocatePool2(0x40,(ulonglong)*(uint *)(param_1 + 9) << 3);
  param_1[8] = lVar7;
  if (lVar7 == 0) {
    return 0xc000009a;
  }
  uVar6 = 0;
  plVar12 = (longlong *)*param_2;
  while (param_2 != plVar12) {
    plVar9 = (longlong *)*plVar12;
    if (((longlong *)plVar9[1] != plVar12) ||
       (puVar11 = (undefined8 *)plVar12[1], (longlong *)*puVar11 != plVar12)) goto LAB_1c000e493;
    *puVar11 = plVar9;
    plVar9[1] = (longlong)puVar11;
    if ((uint)uVar6 < *(uint *)(param_1 + 9)) {
      *(longlong **)(param_1[8] + uVar6 * 8) = plVar12;
    }
    uVar6 = (ulonglong)((uint)uVar6 + 1);
    plVar12 = plVar9;
  }
  uVar13 = *(uint *)(param_1 + 9);
  plVar12 = (longlong *)param_1[8];
  if ((SUB168(ZEXT816(0xb) * ZEXT416(uVar13),8) == 0) &&
     (plVar10 = (longlong *)(SUB168(ZEXT816(0xb) * ZEXT416(uVar13),0) + 6),
     (longlong *)0x5 < plVar10)) {
    plVar9 = (longlong *)0x0;
    if (uVar13 != 0) {
      do {
        auVar4 = ZEXT816(0x1d) * ZEXT416(*(uint *)(*plVar12 + 0x30));
        if (((auVar4._8_8_ != 0) ||
            (plVar8 = (longlong *)(auVar4._0_8_ + (longlong)plVar10), plVar8 < plVar10)) ||
           ((plVar10 = plVar8, (*(uint *)(*plVar12 + 0x30) & 7) != 0 &&
            (plVar10 = plVar8 + 1, plVar10 < plVar8)))) goto LAB_1c000e543;
        uVar16 = (int)plVar9 + 1;
        plVar9 = (longlong *)(ulonglong)uVar16;
        plVar12 = plVar12 + 1;
      } while (uVar16 < uVar13);
    }
    plVar12 = (longlong *)0xffff;
    uVar13 = 0x746e4948;
    if ((longlong *)0xffff < plVar10) goto LAB_1c000e49a;
    uVar18 = SUB82(plVar10,0);
    puVar14 = auStackY_a8;
    goto LAB_1c000e49c;
  }
LAB_1c000e543:
  uVar6 = 0xc0000095;
  puVar14 = auStackY_a8;
LAB_1c000e548:
  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
    return uVar6;
  }
  uVar18 = 0x59;
LAB_1c000e55e:
  *(undefined **)(puVar14 + 0x20) = &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids;
  uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
  *(undefined8 *)(puVar14 + -8) = 0x1c000e57c;
  WPP_RECORDER_SF_(uVar2,2,plVar9,uVar18,*(undefined8 *)(puVar14 + 0x20));
  return uVar6;
LAB_1c000e493:
  plVar10 = (longlong *)0x3;
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)();
  puVar14 = auStackY_a0;
  uVar13 = (uint)puVar15;
LAB_1c000e49a:
  uVar5 = uVar13;
  uVar18 = SUB82(plVar12,0);
LAB_1c000e49c:
  *(undefined2 *)((longlong)param_1 + 0x74) = uVar18;
  uVar13 = -(uint)(plVar12 < plVar10) & 0xc0000095;
  uVar6 = (ulonglong)uVar13;
  if (-1 < (int)uVar13) {
    uVar18 = *(undefined2 *)((longlong)param_1 + 0x74);
    uVar6 = (ulonglong)uVar5;
    *(undefined8 *)(puVar14 + -8) = 0x1c000e4c3;
    plVar9 = (longlong *)ExAllocatePool2(iVar20,uVar18);
    param_1[0xf] = plVar9;
    if (plVar9 == (longlong *)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        *(undefined **)(puVar14 + 0x20) = &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids;
        uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
        *(undefined8 *)(puVar14 + -8) = 0x1c000e505;
        WPP_RECORDER_SF_(uVar2,2,uVar6,0x5a,*(undefined8 *)(puVar14 + 0x20));
      }
      return 0xc000009a;
    }
    uVar1 = *(ushort *)((longlong)param_1 + 0x74);
    uVar5 = *(uint *)(param_1 + 9);
    plVar12 = (longlong *)param_1[8];
    *(undefined8 *)(puVar14 + -8) = 0x1c000e520;
    uVar5 = HID_GenerateReportDescriptor(plVar12,uVar5,(undefined4 *)plVar9,uVar1);
    if (-1 < (int)uVar5) {
      return (ulonglong)uVar5;
    }
    uVar6 = 0xc00000e5;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc00000e5;
    }
    uVar18 = 0x5b;
    goto LAB_1c000e55e;
  }
  goto LAB_1c000e548;
}



===== HIDINT_VhfInitialize @ 1c000e5a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int HIDINT_VhfInitialize(undefined8 param_1)

{
  undefined2 uVar1;
  undefined8 uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined1 auStackY_118 [32];
  undefined1 uVar8;
  undefined4 local_d8;
  undefined4 local_d4;
  longlong local_d0;
  undefined4 local_c8;
  undefined8 local_c0;
  undefined2 local_b8;
  undefined2 local_b6;
  undefined2 local_b4;
  undefined2 local_90;
  undefined8 local_88;
  code *local_80;
  code *local_78;
  code *local_70;
  undefined8 local_68;
  code *local_60;
  undefined8 local_58;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_118;
  local_d4 = 0;
  uVar7 = 0x94;
  memset(&local_d8,0,0x94);
  uVar8 = (undefined1)param_1;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,uVar7,0x60,
                      &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,uVar8);
  }
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_HIDINT_DATA_TYPE_INFO_1c0009018);
  uVar7 = 0x746e4948;
  lVar5 = ExAllocatePool2(0x40,*(int *)(lVar4 + 0x70) + 1);
  *(longlong *)(lVar4 + 0x98) = lVar5;
  if (lVar5 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar7,0x61,
                        &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,uVar8);
    }
    iVar3 = -0x3fffff66;
  }
  else {
    uVar6 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals);
    uVar2 = *(undefined8 *)(lVar4 + 0x78);
    uVar1 = *(undefined2 *)(lVar4 + 0x74);
    uVar7 = 0x98;
    memset(&local_d8,0,0x98);
    local_d8 = 0x98;
    local_58 = 0;
    local_68 = 0;
    local_c8 = 0xb;
    local_b8 = *(undefined2 *)(lVar4 + 0x54);
    local_b6 = *(undefined2 *)(lVar4 + 0x56);
    local_b4 = *(undefined2 *)(lVar4 + 0x58);
    local_78 = HIDINT_EvtVhfGetFeature;
    local_70 = HIDINT_EvtVhfSetFeature;
    local_60 = HIDINT_EvtVhfGetInputReport;
    local_80 = (code *)0x0;
    if (*(char *)(lVar4 + 0x81) == '\0') {
      local_80 = HIDINT_EvtVhfReadyForNextReadReport;
    }
    local_d0 = lVar4;
    local_c0 = uVar6;
    local_90 = uVar1;
    local_88 = uVar2;
    iVar3 = VhfCreate((undefined8 *)&local_d8,(undefined8 *)(lVar4 + 0x88));
    if (-1 < iVar3) goto LAB_1c000e7ed;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar7,0x62,
                         &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,uVar8,(char)iVar3);
    }
  }
  if (*(longlong *)(lVar4 + 0x98) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar4 + 0x98),0x746e4948);
    *(undefined8 *)(lVar4 + 0x98) = 0;
  }
LAB_1c000e7ed:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,uVar7,99,
                       &WPP_1d9f96fbb85334cdf3da593c16c6b082_Traceguids,uVar8,(char)iVar3);
  }
  return iVar3;
}



===== HID_GenerateReportDescriptor @ 1c000e850 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint HID_GenerateReportDescriptor(longlong *param_1,uint param_2,undefined4 *param_3,ushort param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  longlong lVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  ushort uVar11;
  uint uVar12;
  
  if (param_4 < 6) {
LAB_1c000ea52:
    uVar6 = 0xc0000023;
  }
  else {
    uVar6 = 0;
    *param_3 = HID_TemplateReport;
    uVar11 = param_4 - 6;
    *(undefined2 *)(param_3 + 1) = DAT_1c0009128;
    puVar9 = (undefined8 *)((longlong)param_3 + 6);
    if (param_2 != 0) {
      uVar8 = uVar6;
      do {
        lVar1 = *param_1;
        if (uVar11 < 10) goto LAB_1c000ea52;
        *puVar9 = HID_TemplateApplicationCollectionStart;
        *(undefined2 *)(puVar9 + 1) = DAT_1c0009120;
        uVar11 = uVar11 - 10;
        puVar10 = (undefined8 *)((longlong)puVar9 + 10);
        *(undefined1 *)((longlong)puVar9 + 9) = *(undefined1 *)(lVar1 + 0x68);
        *(undefined2 *)((longlong)puVar9 + 1) = *(undefined2 *)(lVar1 + 0x70);
        *(undefined2 *)((longlong)puVar9 + 4) = *(undefined2 *)(lVar1 + 0x72);
        uVar12 = *(uint *)(lVar1 + 0x30);
        uVar7 = uVar6;
        if (uVar12 != 0) {
          do {
            uVar3 = uRam00000001c0009100;
            uVar2 = uRam00000001c00090d8;
            lVar4 = *(longlong *)(*(longlong *)(lVar1 + 0x28) + (ulonglong)uVar7 * 8);
            if ((*(int *)(lVar4 + 0x10) + 1U == uVar12) && ((uVar12 & 7) != 0)) {
              if (uVar11 < 0x25) goto LAB_1c000ea52;
              *puVar10 = _HID_TemplateLogicalCollectionWithPadding;
              puVar10[1] = uVar2;
              uVar2 = uRam00000001c00090e8;
              puVar10[2] = _DAT_1c00090e0;
              puVar10[3] = uVar2;
              *(undefined4 *)(puVar10 + 4) = DAT_1c00090f0;
              *(undefined1 *)((longlong)puVar10 + 0x24) = DAT_1c00090f4;
              uVar11 = uVar11 - 0x25;
              *(undefined2 *)((longlong)puVar10 + 1) = *(undefined2 *)(lVar1 + 0x70);
              *(undefined2 *)((longlong)puVar10 + 4) = *(undefined2 *)(lVar1 + 0x72);
              *(undefined2 *)((longlong)puVar10 + 9) = *(undefined2 *)(lVar4 + 0x34);
              *(undefined2 *)((longlong)puVar10 + 0xc) = *(undefined2 *)(lVar4 + 0x36);
              cVar5 = '\b' - (*(byte *)(lVar1 + 0x30) & 7);
              *(char *)((longlong)puVar10 + 0x13) = cVar5;
              *(char *)((longlong)puVar10 + 0x21) = cVar5;
              lVar4 = 0x25;
            }
            else {
              if (uVar11 < 0x1d) goto LAB_1c000ea52;
              *puVar10 = _HID_TemplateLogicalCollection;
              puVar10[1] = uVar3;
              puVar10[2] = DAT_1c0009108;
              *(undefined4 *)(puVar10 + 3) = DAT_1c0009110;
              *(undefined1 *)((longlong)puVar10 + 0x1c) = DAT_1c0009114;
              uVar11 = uVar11 - 0x1d;
              *(undefined2 *)((longlong)puVar10 + 1) = *(undefined2 *)(lVar1 + 0x70);
              *(undefined2 *)((longlong)puVar10 + 4) = *(undefined2 *)(lVar1 + 0x72);
              *(undefined2 *)((longlong)puVar10 + 9) = *(undefined2 *)(lVar4 + 0x34);
              *(undefined2 *)((longlong)puVar10 + 0xc) = *(undefined2 *)(lVar4 + 0x36);
              lVar4 = 0x1d;
            }
            uVar12 = *(uint *)(lVar1 + 0x30);
            uVar7 = uVar7 + 1;
            puVar10 = (undefined8 *)((longlong)puVar10 + lVar4);
          } while (uVar7 < uVar12);
        }
        if (uVar11 == 0) goto LAB_1c000ea52;
        *(undefined1 *)puVar10 = 0xc0;
        uVar11 = uVar11 - 1;
        puVar9 = (undefined8 *)((longlong)puVar10 + 1);
        uVar8 = uVar8 + 1;
        param_1 = param_1 + 1;
      } while (uVar8 < param_2);
    }
  }
  return uVar6;
}



===== ACPI_EvaluateMethod @ 1c000ea80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ACPI_EvaluateMethod(undefined8 param_1,undefined4 param_2,longlong *param_3,undefined4 *param_4)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  byte bVar5;
  undefined4 local_68;
  undefined4 local_64;
  longlong local_60 [3];
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  
  local_68 = 0x42696541;
  local_48 = 0;
  local_38 = &local_68;
  local_60[0] = 0;
  local_40 = 1;
  local_30 = 8;
  local_60[1] = 0;
  local_60[2] = 0;
  bVar5 = 0;
  uVar4 = 0x200;
  local_64 = param_2;
  while( true ) {
    lVar2 = ExAllocatePool2(0x100,uVar4,0x746e4948);
    if (lVar2 == 0) {
      return -0x3fffff66;
    }
    local_60[1] = 1;
    local_44 = 0;
    local_60[2] = lVar2;
    local_48 = uVar4;
    uVar3 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_1);
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x5d0))
                      (WdfDriverGlobals,uVar3,0,0x32c004,&local_40,local_60 + 1,0,local_60);
    bVar5 = bVar5 + 1;
    if (iVar1 != -0x7ffffffb) break;
    uVar4 = *(undefined4 *)(lVar2 + 4);
    ExFreePoolWithTag(lVar2,0);
    if (1 < bVar5) {
      return -0x7ffffffb;
    }
  }
  if (-1 < iVar1) {
    if (local_60[0] != 0) {
      *param_3 = lVar2;
      *param_4 = uVar4;
      return iVar1;
    }
    iVar1 = -0x3fffffff;
  }
  ExFreePoolWithTag(lVar2,0x746e4948);
  return iVar1;
}



===== ACPI_ParseArguments @ 1c000ec10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ACPI_ParseArguments(byte *param_1,uint param_2,short *param_3,ulonglong param_4,longlong param_5
                       ,int param_6)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  ulonglong uVar4;
  byte *pbVar5;
  ulonglong uVar6;
  undefined2 uVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  short *psStack0000000000000038;
  
  uVar6 = (ulonglong)param_2;
  uVar9 = 0;
  uVar10 = 0;
  bVar1 = param_1[(ulonglong)(param_2 - 1) * 0x18];
  psStack0000000000000038 = (short *)((param_4 & 0xffffffff) + (longlong)param_3);
  if (param_3 < psStack0000000000000038) {
    do {
      if (bVar1 + 1 <= uVar10) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return -0x3febfff5;
        }
        WPP_RECORDER_SF_sD(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        return -0x3febfff5;
      }
      if (param_2 <= (uint)uVar9) {
LAB_1c000ec99:
        uVar8 = 0;
        if (param_2 == 0) {
          return -0x3febfff8;
        }
        pbVar5 = param_1;
        goto LAB_1c000eca6;
      }
      pbVar5 = param_1 + uVar9 * 0x18;
      while ((*pbVar5 != uVar10 || (*(short *)(pbVar5 + 2) != *param_3))) {
        uVar8 = (int)uVar9 + 1;
        uVar9 = (ulonglong)uVar8;
        pbVar5 = pbVar5 + 0x18;
        if (param_2 <= uVar8) goto LAB_1c000ec99;
      }
      pbVar5 = param_1 + uVar9 * 0x18;
      if (pbVar5 == (byte *)0x0) goto LAB_1c000ec99;
      iVar3 = (**(code **)(pbVar5 + 0x10))
                        (param_3,(ulonglong)*(ushort *)(pbVar5 + 4) + param_5,
                         param_6 - (uint)*(ushort *)(pbVar5 + 4));
      if (iVar3 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return iVar3;
        }
        WPP_RECORDER_SF_ss(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        return iVar3;
      }
      uVar4 = (ulonglong)(ushort)param_3[1];
      uVar10 = uVar10 + 1;
      if ((ushort)param_3[1] < 4) {
        uVar4 = 4;
      }
      param_3 = (short *)((longlong)param_3 + uVar4 + 4);
    } while (param_3 < psStack0000000000000038);
  }
  if (uVar10 == bVar1 + 1) {
    return 0;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  return -0x3febfff5;
  while( true ) {
    uVar8 = uVar8 + 1;
    pbVar5 = pbVar5 + 0x18;
    if (param_2 <= uVar8) break;
LAB_1c000eca6:
    if (*pbVar5 == uVar10) break;
  }
  if (uVar8 < param_2) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      pbVar5 = (byte *)(ulonglong)uVar8;
      GetObjectTypeName(*param_3);
      WPP_RECORDER_SF_sss(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    do {
      if (*param_1 == uVar10) {
        sVar2 = *(short *)(param_1 + 2);
        if (sVar2 == 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar7 = 0xd;
            goto LAB_1c000ee32;
          }
        }
        else if (sVar2 == 1) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar7 = 0xe;
            goto LAB_1c000ee32;
          }
        }
        else if ((sVar2 == 2) &&
                ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar7 = 0xf;
LAB_1c000ee32:
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pbVar5,uVar7,
                           &WPP_fc2dc4c0d6a934c1c5c0f33ba3d3c5c0_Traceguids);
        }
      }
      param_1 = param_1 + 0x18;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  return -0x3febfff8;
}



===== AcpiParseULong @ 1c000eec0 =====

undefined8 AcpiParseULong(longlong param_1,undefined4 *param_2,uint param_3)

{
  if (param_3 < 4) {
    return 0xc000000d;
  }
  *param_2 = *(undefined4 *)(param_1 + 4);
  return 0;
}



===== AcpiParseUShort @ 1c000eee0 =====

uint AcpiParseUShort(longlong param_1,undefined2 *param_2,uint param_3)

{
  uint uVar1;
  undefined2 uVar2;
  
  if (param_3 < 2) {
    return 0xc000000d;
  }
  uVar1 = *(uint *)(param_1 + 4);
  if (uVar1 < 0x10000) {
    uVar2 = (undefined2)uVar1;
  }
  else {
    uVar2 = 0xffff;
  }
  *param_2 = uVar2;
  return -(uint)(0xffff < uVar1) & 0xc0000095;
}



===== VhfCreate @ 1c000ef18 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int VhfCreate(undefined8 *param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  int iVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined2 *puVar8;
  undefined2 uVar9;
  uint uVar10;
  undefined *puVar11;
  undefined2 *puVar12;
  undefined1 auStack_b8 [32];
  undefined8 *local_98;
  undefined4 local_90;
  undefined1 local_88;
  undefined8 *local_80;
  undefined8 *local_78;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  ulonglong uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_b8;
  local_58 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10);
  }
  puVar12 = (undefined2 *)0x4b464856;
  puVar6 = (undefined8 *)ExAllocatePool2(0x40);
  if (puVar6 == (undefined8 *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb);
    }
    iVar5 = -0x3fffff66;
    *param_2 = 0;
    goto LAB_1c000f6ff;
  }
  puVar12 = (undefined2 *)0x0;
  KeInitializeEvent(puVar6 + 0x47);
  uVar4 = param_1[1];
  *puVar6 = *param_1;
  puVar6[1] = uVar4;
  uVar4 = param_1[3];
  puVar6[2] = param_1[2];
  puVar6[3] = uVar4;
  uVar4 = param_1[5];
  puVar6[4] = param_1[4];
  puVar6[5] = uVar4;
  uVar4 = param_1[7];
  puVar6[6] = param_1[6];
  puVar6[7] = uVar4;
  uVar4 = param_1[9];
  puVar6[8] = param_1[8];
  puVar6[9] = uVar4;
  uVar4 = param_1[0xb];
  puVar6[10] = param_1[10];
  puVar6[0xb] = uVar4;
  uVar4 = param_1[0xd];
  puVar6[0xc] = param_1[0xc];
  puVar6[0xd] = uVar4;
  uVar1 = *(undefined4 *)((longlong)param_1 + 0x74);
  uVar2 = *(undefined4 *)(param_1 + 0xf);
  uVar3 = *(undefined4 *)((longlong)param_1 + 0x7c);
  *(undefined4 *)(puVar6 + 0xe) = *(undefined4 *)(param_1 + 0xe);
  *(undefined4 *)((longlong)puVar6 + 0x74) = uVar1;
  *(undefined4 *)(puVar6 + 0xf) = uVar2;
  *(undefined4 *)((longlong)puVar6 + 0x7c) = uVar3;
  uVar1 = *(undefined4 *)((longlong)param_1 + 0x84);
  uVar2 = *(undefined4 *)(param_1 + 0x11);
  uVar3 = *(undefined4 *)((longlong)param_1 + 0x8c);
  *(undefined4 *)(puVar6 + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)((longlong)puVar6 + 0x84) = uVar1;
  *(undefined4 *)(puVar6 + 0x11) = uVar2;
  *(undefined4 *)((longlong)puVar6 + 0x8c) = uVar3;
  puVar6[0x12] = param_1[0x12];
  uVar10 = -(uint)(puVar6[0xf] != 0) & 0x10 | -(uint)(puVar6[0xd] != 0) & 8 |
           -(uint)(puVar6[0xe] != 0) & 2 | -(uint)(puVar6[0xc] != 0) & 4 | (uint)(puVar6[0xb] != 0);
  puVar11 = (undefined *)(ulonglong)uVar10;
  *(uint *)((longlong)puVar6 + 0xac) = *(uint *)((longlong)puVar6 + 0xac) | uVar10;
  lVar7 = IoGetLowerDeviceObject(puVar6[3]);
  puVar6[0x13] = lVar7;
  if (lVar7 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      puVar11 = (undefined *)0xc;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc);
    }
    iVar5 = -0x3ffffff3;
  }
  else {
    puVar12 = (undefined2 *)0x4b464856;
    puVar11 = (undefined *)0x48;
    puVar8 = (undefined2 *)ExAllocatePool2(0x40);
    if (puVar8 == (undefined2 *)0x0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        puVar11 = (undefined *)0xd;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd);
      }
      iVar5 = -0x3fffff66;
    }
    else {
      *puVar8 = *(undefined2 *)(puVar6 + 4);
      puVar8[1] = *(undefined2 *)((longlong)puVar6 + 0x22);
      puVar8[2] = *(undefined2 *)((longlong)puVar6 + 0x24);
      uVar1 = *(undefined4 *)((longlong)puVar6 + 0x2c);
      uVar2 = *(undefined4 *)(puVar6 + 6);
      uVar3 = *(undefined4 *)((longlong)puVar6 + 0x34);
      *(undefined4 *)(puVar8 + 4) = *(undefined4 *)(puVar6 + 5);
      *(undefined4 *)(puVar8 + 6) = uVar1;
      *(undefined4 *)(puVar8 + 8) = uVar2;
      *(undefined4 *)(puVar8 + 10) = uVar3;
      *(undefined8 *)(puVar8 + 0x20) = puVar6[0x12];
      puVar8[0x1c] = *(undefined2 *)(puVar6 + 0x11);
      *(undefined8 *)(puVar8 + 0x18) = puVar6[8];
      puVar8[0x14] = *(undefined2 *)(puVar6 + 7);
      puVar8[0xe] = *(undefined2 *)(puVar6 + 9);
      *(undefined8 *)(puVar8 + 0x10) = puVar6[10];
      *(undefined4 *)(puVar8 + 0xc) = *(undefined4 *)((longlong)puVar6 + 0xac);
      KeInitializeEvent(&local_68,0,0);
      local_78 = &local_50;
      local_80 = &local_68;
      local_88 = 0;
      local_98 = &local_40;
      local_90 = 0x10;
      puVar12 = puVar8;
      lVar7 = IoBuildDeviceIoControlRequest(0xb0324,puVar6[0x13],puVar8,0x48);
      if (lVar7 == 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar9 = 0xe;
          goto LAB_1c000f25a;
        }
        goto LAB_1c000f263;
      }
      *(undefined4 *)(lVar7 + 0x30) = 0xc00000bb;
      *(undefined8 *)(lVar7 + 0x38) = 0;
      iVar5 = IofCallDriver(puVar6[0x13],lVar7);
      if (iVar5 == 0x103) {
        local_98 = (undefined8 *)0x0;
        puVar12 = (undefined2 *)0x0;
        KeWaitForSingleObject(&local_68,0,0,0);
        iVar5 = (int)local_50;
      }
      if (iVar5 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,puVar12,iVar5);
        }
      }
      else {
        puVar6[0x14] = local_40;
        puVar6[0x45] = local_40;
        lVar7 = IoAllocateIrp(CONCAT71((int7)((ulonglong)puVar6[3] >> 8),
                                       *(undefined1 *)(puVar6[3] + 0x4c)),0);
        puVar6[0x46] = lVar7;
        if (lVar7 == 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar9 = 0x10;
            goto LAB_1c000f25a;
          }
          goto LAB_1c000f263;
        }
        if ((*(byte *)((longlong)puVar6 + 0xac) & 1) == 0) {
          *(undefined4 *)((longlong)puVar6 + 0xc4) = 2;
LAB_1c000f471:
          puVar6[0x16] = puVar6;
          if ((*(uint *)((longlong)puVar6 + 0xac) & 0x1e) == 0) {
            *(undefined4 *)((longlong)puVar6 + 0x154) = 2;
LAB_1c000f6d2:
            puVar6[0x28] = puVar6;
          }
          else {
            puVar6[0x36] = local_40;
            puVar12 = (undefined2 *)0x4b464856;
            puVar6[0x3b] = local_40;
            *(undefined2 *)(puVar6 + 0x40) = (undefined2)uStack_38;
            lVar7 = ExAllocatePool2(0x40,uStack_38 & 0xffff);
            puVar6[0x41] = lVar7;
            if (lVar7 == 0) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar9 = 0x12;
LAB_1c000f25a:
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9);
              }
            }
            else {
              if (*(int *)(puVar6 + 2) != 0) {
                puVar12 = (undefined2 *)0x4b464856;
                lVar7 = ExAllocatePool2(0x40,*(int *)(puVar6 + 2));
                puVar6[0x44] = lVar7;
                if (lVar7 == 0) {
                  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                    uVar9 = 0x13;
                    goto LAB_1c000f25a;
                  }
                  goto LAB_1c000f263;
                }
              }
              *(uint *)((longlong)puVar6 + 0x1cc) = (uint)*(ushort *)(puVar6 + 0x40);
              puVar6[0x3a] = puVar6[0x41];
              lVar7 = IoAllocateIrp(CONCAT71((int7)((ulonglong)puVar6[3] >> 8),
                                             *(undefined1 *)(puVar6[3] + 0x4c)),0);
              puVar6[0x2b] = lVar7;
              if (lVar7 != 0) {
                local_98 = (undefined8 *)0x0;
                puVar12 = (undefined2 *)0x0;
                lVar7 = IoAllocateMdl(puVar6 + 0x37,0x20);
                puVar6[0x31] = lVar7;
                if (lVar7 == 0) {
                  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                    uVar9 = 0x15;
                    goto LAB_1c000f3dd;
                  }
                  goto LAB_1c000f3e6;
                }
                MmBuildMdlForNonPagedPool(lVar7);
                KeInitializeSpinLock(puVar6 + 0x29);
                *(undefined4 *)((longlong)puVar6 + 0x154) = 0;
                puVar6[0x35] = Vhfi_InvokeAsyncOperationCallback;
                puVar6[0x2f] = puVar6 + 0x37;
                puVar6[0x33] = puVar6 + 0x3b;
                *(undefined4 *)(puVar6 + 0x2c) = 0xb0336;
                puVar6[0x2d] = puVar6 + 0x36;
                *(undefined4 *)(puVar6 + 0x2e) = 8;
                *(undefined4 *)(puVar6 + 0x30) = 0x20;
                *(undefined4 *)(puVar6 + 0x32) = 0xb0339;
                *(undefined4 *)(puVar6 + 0x34) = 0x28;
                goto LAB_1c000f6d2;
              }
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar9 = 0x14;
                goto LAB_1c000f25a;
              }
            }
LAB_1c000f263:
            iVar5 = -0x3fffff66;
          }
        }
        else {
          puVar6[0x24] = local_40;
          puVar6[0x25] = local_40;
          lVar7 = IoAllocateIrp(CONCAT71((int7)((ulonglong)puVar6[3] >> 8),
                                         *(undefined1 *)(puVar6[3] + 0x4c)),0);
          puVar6[0x19] = lVar7;
          if (lVar7 != 0) {
            KeInitializeSpinLock(puVar6 + 0x17);
            *(undefined4 *)((longlong)puVar6 + 0xc4) = 0;
            puVar6[0x1b] = puVar6 + 0x24;
            puVar6[0x1d] = 0;
            *(undefined4 *)(puVar6 + 0x1e) = 0;
            puVar6[0x1f] = 0;
            puVar6[0x23] = Vhfi_InvokeReadyForNextReadReportCallback;
            *(undefined4 *)(puVar6 + 0x1a) = 0xb032d;
            *(undefined4 *)(puVar6 + 0x1c) = 8;
            *(undefined4 *)(puVar6 + 0x20) = 0xb0331;
            puVar6[0x21] = puVar6 + 0x25;
            *(undefined4 *)(puVar6 + 0x22) = 0x18;
            goto LAB_1c000f471;
          }
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar9 = 0x11;
LAB_1c000f3dd:
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9);
          }
LAB_1c000f3e6:
          iVar5 = -0x3fffff66;
        }
      }
      puVar11 = (undefined *)0x4b464856;
      ExFreePoolWithTag(puVar8);
      if (-1 < iVar5) {
        *param_2 = puVar6;
        goto LAB_1c000f6ff;
      }
    }
  }
  *param_2 = 0;
  if (puVar6[0x14] == 0) {
    Vhfi_Cleanup((longlong)puVar6);
  }
  else {
    VhfDelete((longlong)puVar6,puVar11,puVar12);
  }
LAB_1c000f6ff:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,puVar12,iVar5);
  }
  return iVar5;
}



===== __security_init_cookie @ 1c0010008 =====

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



===== DriverEntry @ 1c001003c =====

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
  _DAT_1c0009448 = 1;
  local_40 = 0;
  uStack_38 = 0;
  _WPP_MAIN_CB = 0;
  DAT_1c0009428 = &WPP_ThisDir_CTLGUID_HIDINTERRUPT;
  DAT_1c0009430 = 0;
  _DAT_1c0009440 = 0;
  _DAT_1c0009460 = 0;
  _DAT_1c0009468 = 0;
  WppLoadTracingSupport();
  _DAT_1c0009440 = 0;
  WppInitKm(param_1,param_2);
  local_40 = CONCAT35(local_40._5_3_,0x100000010);
  uStack_38 = 0x200000002;
  imp_WppRecorderConfigure(WPP_GLOBAL_Control,&local_40);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_3,10,
                      &WPP_b55d0c434e0b34142fdce029b8a2137d_Traceguids,(char)param_1);
  }
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))(WdfDriverGlobals,param_1,param_2,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c00101f2;
    WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,param_2,0xb,
                      &WPP_b55d0c434e0b34142fdce029b8a2137d_Traceguids,(char)iVar1);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,param_2,0xc,
                       &WPP_b55d0c434e0b34142fdce029b8a2137d_Traceguids,(char)param_1,(char)iVar1);
  }
  if (-1 < iVar1) {
    return iVar1;
  }
LAB_1c00101f2:
  WppCleanupKm(param_1);
  return iVar1;
}


