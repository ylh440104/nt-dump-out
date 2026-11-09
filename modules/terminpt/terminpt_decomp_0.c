
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



===== PtPnPComplete @ 1c0001020 =====

undefined8 PtPnPComplete(undefined1 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 in_stack_ffffffffffffffe0;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x12,
                      &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids);
  }
  uVar2 = 0;
  uVar1 = 0;
  KeSetEvent(param_3);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar1,uVar2,0x13,
                       &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids,in_stack_ffffffffffffffe0,
                       param_1);
  }
  return 0xc0000016;
}



===== PtPower @ 1c00010d0 =====

int PtPower(longlong param_1,undefined *param_2,undefined8 param_3)

{
  longlong *plVar1;
  byte bVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 *puVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  code *pcVar9;
  ulonglong uVar10;
  char *pcVar11;
  undefined2 uVar12;
  undefined8 in_stack_ffffffffffffffc0;
  
  bVar6 = true;
  bVar7 = false;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x21,
                      &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids);
  }
  lVar3 = *(longlong *)(param_1 + 0x40);
  pcVar11 = "";
  pcVar9 = PtPower;
  iVar8 = IoAcquireRemoveLockEx(lVar3 + 0x18,PtPower,"",1,0x20);
  if (iVar8 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar9,pcVar11,0x22,
                        &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids);
    }
  }
  else {
    bVar7 = true;
    if (*(int *)(param_1 + 0x48) != 0x38) {
      plVar1 = (longlong *)(param_2 + 0xb8);
      lVar4 = *plVar1;
      bVar2 = *(byte *)(lVar4 + 1);
      uVar10 = (ulonglong)bVar2;
      if (bVar2 == 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar12 = 0x24;
LAB_1c000140a:
          WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar10,pcVar11,uVar12,
                            &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids);
        }
LAB_1c0001426:
        PoStartNextPowerIrp(param_2);
        param_2[0x43] = param_2[0x43] + '\x01';
        *plVar1 = *plVar1 + 0x48;
      }
      else {
        if (bVar2 == 1) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar12 = 0x25;
            goto LAB_1c000140a;
          }
          goto LAB_1c0001426;
        }
        if (bVar2 != 2) {
          if (bVar2 == 3) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar12 = 0x2c;
              goto LAB_1c000140a;
            }
          }
          else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar10,pcVar11,0x2d,
                               &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids,
                               in_stack_ffffffffffffffc0,bVar2);
          }
          goto LAB_1c0001426;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pcVar11,0x26,
                            &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids);
        }
        if (*(int *)(lVar4 + 0x10) != 1) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar12 = 0x27;
            goto LAB_1c000140a;
          }
          goto LAB_1c0001426;
        }
        iVar8 = *(int *)(lVar4 + 0x18);
        if (iVar8 == *(int *)(lVar3 + 0x38)) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar12 = 0x28;
            goto LAB_1c000140a;
          }
          goto LAB_1c0001426;
        }
        if (iVar8 == 1) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar10,pcVar11,0x29,
                              &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids);
          }
          puVar5 = (undefined8 *)*plVar1;
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
          lVar4 = *plVar1;
          *(undefined8 *)(lVar4 + -8) = 0;
          bVar6 = false;
          *(code **)(lVar4 + -0x10) = PtPowerUpToD0Complete;
          *(undefined1 *)(lVar4 + -0x45) = 0xe0;
        }
        else if (((iVar8 == 2) || (iVar8 == 3)) || (iVar8 == 4)) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar10,pcVar11,0x2a,
                              &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids);
          }
          pcVar11 = (char *)(ulonglong)*(uint *)(lVar4 + 0x18);
          PoSetPowerState(param_1,*(undefined4 *)(lVar4 + 0x10));
          *(undefined4 *)(lVar3 + 0x38) = *(undefined4 *)(lVar4 + 0x18);
          *(undefined4 *)(lVar3 + 0x3c) = *(undefined4 *)(lVar4 + 0x20);
        }
        else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar10,pcVar11,0x2b,
                            &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids);
        }
        if (bVar6) goto LAB_1c0001426;
      }
      iVar8 = PoCallDriver(*(undefined8 *)(lVar3 + 8));
      goto LAB_1c0001454;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar9,pcVar11,0x23,
                        &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids);
    }
    iVar8 = -0x3ffffff0;
  }
  PoStartNextPowerIrp(param_2);
  pcVar9 = (code *)0x0;
  *(int *)(param_2 + 0x30) = iVar8;
  IofCompleteRequest(param_2);
  param_2 = pcVar9;
  bVar6 = bVar7;
LAB_1c0001454:
  if (bVar6) {
    pcVar11 = (char *)0x20;
    pcVar9 = PtPower;
    IoReleaseRemoveLockEx(lVar3 + 0x18);
    param_2 = pcVar9;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,pcVar11,0x2e,
                        &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids,in_stack_ffffffffffffffc0,
                        (char)param_1,(char)iVar8);
  }
  return iVar8;
}



===== PtPowerUpToD0Complete @ 1c00014d0 =====

undefined8 PtPowerUpToD0Complete(longlong param_1,longlong param_2,undefined8 param_3)

{
  byte *pbVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  
  lVar4 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x2f,
                      &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids);
  }
  puVar3 = *(undefined8 **)(param_1 + 0x40);
  if (-1 < *(int *)(param_2 + 0x30)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar4,param_3,0x30,
                        &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids);
    }
    lVar4 = *(longlong *)(param_2 + 0xb8);
    uVar2 = *(undefined4 *)(lVar4 + 0x18);
    *(undefined4 *)((longlong)puVar3 + 0x3c) = 0;
    *(undefined4 *)(puVar3 + 7) = uVar2;
    PoSetPowerState(*puVar3,*(undefined4 *)(lVar4 + 0x10),*(undefined4 *)(lVar4 + 0x18));
  }
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  PoStartNextPowerIrp(param_2);
  IoReleaseRemoveLockEx(puVar3 + 3,PtPower,0x20);
  return 0;
}



===== PtPrepareSessionDevice @ 1c00015d0 =====

int PtPrepareSessionDevice(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  int local_res8 [2];
  undefined4 local_res10 [2];
  undefined4 local_res18 [2];
  int *piVar4;
  
  local_res8[0] = 0;
  local_res18[0] = 0;
  local_res10[0] = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x31,
                      &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids);
  }
  puVar2 = (undefined8 *)&P_DEVPKEY_Device_SessionId;
  uVar3 = 0;
  piVar4 = local_res8;
  iVar1 = IoGetDevicePropertyData
                    (param_1[2],&P_DEVPKEY_Device_SessionId,0,0,4,piVar4,local_res18,local_res10);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar2,uVar3,0x32,
                       &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids,piVar4,(char)iVar1);
  }
  if ((-1 < iVar1) &&
     (puVar2 = param_1, iVar1 = TiAddDeviceToSession(local_res8[0],param_1,uVar3), iVar1 < 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar2,uVar3,0x33,
                      &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar2,uVar3,0x34,
                        &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids,piVar4,(char)*param_1,
                        (char)iVar1);
  }
  return iVar1;
}



===== PtReleaseSessionDevice @ 1c0001710 =====

void PtReleaseSessionDevice(undefined8 *param_1,longlong param_2,undefined8 param_3)

{
  TiRemoveDeviceFromSession(param_1,param_2,param_3);
  return;
}



===== WPP_RECORDER_SF_s @ 1c0001728 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_s(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5)

{
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
    (*pfnWppTraceMessage)(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4," ",2,0);
  }
  WppAutoLogTrace(param_1,0,1,param_5,param_4," ",2,0);
  return;
}



===== WPP_RECORDER_SF_sd @ 1c00017cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined8 param_6,undefined1 param_7)

{
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4," ",2,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,0,1,param_5,param_4," ",2,&param_7,4,0);
  return;
}



===== WPP_RECORDER_SF_sDd @ 1c00018a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4," ",2,&param_7,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,0,1,param_5,param_4," ",2,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_sq @ 1c0001998 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined8 param_6,undefined1 param_7)

{
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4," ",2,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,0,1,param_5,param_4," ",2,&param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_sqd @ 1c0001a6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sqd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4," ",2,&param_7,8,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,0,1,param_5,param_4," ",2,&param_7,8,&param_8,4,0);
  return;
}



===== CancelIndicatorIrp @ 1c0001b70 =====

void CancelIndicatorIrp(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  undefined1 uVar3;
  
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  if ((lVar1 != 0) && (plVar2 = *(longlong **)(lVar1 + 0x20), plVar2 != (longlong *)0x0)) {
    lVar1 = *(longlong *)(*plVar2 + 0x40);
    uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0xe8);
    if (param_2 == *(longlong *)(lVar1 + 0xe0)) {
      *(undefined8 *)(lVar1 + 0xe0) = 0;
    }
    KeReleaseSpinLock(lVar1 + 0xe8,uVar3);
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  IofCompleteRequest(param_2,0);
  return;
}



===== PtClose @ 1c0001c20 =====

undefined8 PtClose(longlong param_1,longlong param_2,undefined8 param_3)

{
  int *piVar1;
  undefined8 uVar2;
  undefined8 in_stack_ffffffffffffffe0;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0xe,
                      &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids);
  }
  uVar2 = 0;
  LOCK();
  piVar1 = (int *)(*(longlong *)(param_1 + 0x40) + 0x40);
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,param_3,0xf,
                       &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids,in_stack_ffffffffffffffe0,
                       (char)param_1);
  }
  return 0;
}



===== PtInternalDeviceControl @ 1c0001ce0 =====

int PtInternalDeviceControl(longlong param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  uint uVar2;
  undefined2 *puVar3;
  undefined4 *puVar4;
  undefined1 uVar5;
  int iVar6;
  longlong lVar7;
  code *pcVar8;
  int iVar9;
  longlong lVar10;
  char *pcVar11;
  undefined8 uVar12;
  undefined2 uVar13;
  undefined8 in_stack_ffffffffffffffc0;
  undefined1 uVar14;
  
  lVar7 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x16,
                      &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids);
  }
  uVar14 = (undefined1)param_1;
  if (*(int *)(param_1 + 0x48) == 0x38) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar7,param_3,0x17,
                          &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids,in_stack_ffffffffffffffc0
                          ,uVar14,0x10);
    }
    return -0x3ffffff0;
  }
  iVar9 = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  pcVar11 = "";
  lVar7 = *(longlong *)(param_1 + 0x40);
  pcVar8 = PtInternalDeviceControl;
  iVar6 = IoAcquireRemoveLockEx(lVar7 + 0x18,PtInternalDeviceControl,"",1,0x20);
  if (iVar6 < 0) {
    uVar12 = 0;
    *(int *)(param_2 + 0x30) = iVar6;
    IofCompleteRequest(param_2);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar12,pcVar11,0x18,
                          &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids,in_stack_ffffffffffffffc0
                          ,uVar14,(char)iVar6);
    }
    return iVar6;
  }
  lVar10 = *(longlong *)(param_2 + 0xb8);
  uVar2 = *(uint *)(lVar10 + 0x18);
  if (uVar2 < 0xb0404) {
    if (uVar2 == 0xb0403) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar13 = 0x1c;
LAB_1c0002196:
        WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar8,pcVar11,uVar13,
                          &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids);
      }
LAB_1c00021ab:
      iVar9 = -0x3ffffffe;
      goto LAB_1c0002367;
    }
    if (uVar2 == 0xb0000) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar8,pcVar11,0x21,
                          &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids);
      }
      if (0x1b < *(uint *)(lVar10 + 8)) {
        puVar4 = *(undefined4 **)(param_2 + 0x18);
        *puVar4 = 0x10051;
        puVar4[1] = 0x3000c;
        *(undefined2 *)(puVar4 + 2) = 0x65;
        puVar4[3] = 100;
        puVar4[4] = 0x20000;
        puVar4[5] = 0xfa;
        puVar4[6] = 0x3e8001e;
        *(undefined8 *)(param_2 + 0x38) = 0x1c;
        goto LAB_1c0002367;
      }
    }
    else {
      if (uVar2 == 0xb0004) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0002367;
        uVar13 = 0x26;
LAB_1c00020ea:
        WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar8,pcVar11,uVar13,
                          &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids);
        goto LAB_1c0002367;
      }
      if (uVar2 == 0xb0008) {
        if (3 < *(uint *)(lVar10 + 0x10)) {
          if (*(ushort *)(lVar7 + 0xdc) != ((*(undefined2 **)(param_2 + 0x18))[1] & 0xf)) {
            *(undefined2 *)(lVar7 + 0xda) = **(undefined2 **)(param_2 + 0x18);
            *(ushort *)(lVar7 + 0xdc) = *(ushort *)(*(longlong *)(param_2 + 0x18) + 2) & 0xf;
            if (*(short *)(*(longlong *)(param_2 + 0x18) + 2) < 0) {
              uVar5 = KeAcquireSpinLockRaiseToDpc(lVar7 + 0xe8);
              lVar10 = *(longlong *)(lVar7 + 0xe0);
              pcVar8 = (code *)CONCAT71((int7)((ulonglong)pcVar8 >> 8),uVar5);
              *(undefined1 *)(lVar7 + 0xde) = 1;
              if (lVar10 != 0) {
                LOCK();
                lVar1 = *(longlong *)(lVar10 + 0x68);
                *(longlong *)(lVar10 + 0x68) = 0;
                UNLOCK();
                if (lVar1 == 0) {
                  lVar10 = 0;
                }
                else {
                  puVar3 = *(undefined2 **)(lVar10 + 0x18);
                  *puVar3 = *(undefined2 *)(lVar7 + 0xda);
                  puVar3[2] = *(undefined2 *)(lVar7 + 0xdc);
                  *(undefined4 *)(lVar10 + 0x30) = 0;
                  *(undefined8 *)(lVar7 + 0xe0) = 0;
                  *(undefined1 *)(lVar7 + 0xde) = 0;
                }
              }
              KeReleaseSpinLock(lVar7 + 0xe8);
              if (lVar10 != 0) {
                *(undefined8 *)(lVar10 + 0x38) = 0xc;
                pcVar8 = (code *)0x0;
                IofCompleteRequest(lVar10);
              }
            }
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_1c0002367;
          uVar13 = 0x24;
          goto LAB_1c00020ea;
        }
      }
      else if (uVar2 == 0xb0020) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar8,pcVar11,0x25,
                            &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids);
        }
        if (5 < *(uint *)(lVar10 + 8)) {
          *(undefined4 *)(*(longlong *)(param_2 + 0x18) + 2) = 0xfa001e;
          *(undefined8 *)(param_2 + 0x38) = 6;
          goto LAB_1c0002367;
        }
      }
      else if (uVar2 == 0xb0040) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar8,pcVar11,0x23,
                            &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids);
        }
        if (3 < *(uint *)(lVar10 + 8)) {
          *(undefined2 *)(*(longlong *)(param_2 + 0x18) + 2) = 0;
          **(undefined2 **)(param_2 + 0x18) = 0;
          *(undefined8 *)(param_2 + 0x38) = 4;
          goto LAB_1c0002367;
        }
      }
      else {
        if (uVar2 != 0xb0080) {
          if (uVar2 != 0xb0203) goto LAB_1c00021fa;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar8,pcVar11,0x19,
                              &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids);
          }
          if (*(longlong *)(lVar7 + 0x50) == 0) {
            if (0xf < *(uint *)(lVar10 + 0x10)) {
              LOCK();
              DAT_1c0006170 = DAT_1c0006170 + 1;
              UNLOCK();
              *(undefined1 *)(lVar7 + 0x58) = 1;
              goto LAB_1c0001ef2;
            }
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar13 = 0x1b;
              goto LAB_1c0001ec4;
            }
            goto LAB_1c0001ed9;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar13 = 0x1a;
            goto LAB_1c0001e90;
          }
          goto LAB_1c0001ea5;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar8,pcVar11,0x22,
                            &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids);
        }
        if (0xd < *(uint *)(lVar10 + 8)) {
          puVar3 = *(undefined2 **)(param_2 + 0x18);
          *puVar3 = 3;
          memcpy(puVar3 + 1,&DAT_1c0005190,0xc);
          *(undefined8 *)(param_2 + 0x38) = 0xe;
          goto LAB_1c0002367;
        }
      }
    }
LAB_1c0001f2d:
    iVar9 = -0x3fffffdd;
    goto LAB_1c0002367;
  }
  if (uVar2 == 0xb1004) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar13 = 0x27;
      goto LAB_1c000234d;
    }
  }
  else {
    if (uVar2 != 0xb3fc7) {
      if (uVar2 == 0xb3fcb) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar8,pcVar11,0x2a,
                            &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids);
        }
        iVar9 = -0x3fffff45;
        goto LAB_1c0002367;
      }
      if (uVar2 == 0xf0000) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar8,pcVar11,0x28,
                            &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids);
        }
        if (0xb < *(uint *)(lVar10 + 8)) {
          puVar4 = *(undefined4 **)(param_2 + 0x18);
          *puVar4 = 0x20002;
          *(undefined2 *)(puVar4 + 1) = 0x3c;
          puVar4[2] = 0;
          *(undefined8 *)(param_2 + 0x38) = 0xc;
          goto LAB_1c0002367;
        }
        goto LAB_1c0001f2d;
      }
      if (uVar2 == 0xf0203) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar8,pcVar11,0x1d,
                            &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids);
        }
        if (*(longlong *)(lVar7 + 0x50) == 0) {
          if (0xf < *(uint *)(lVar10 + 0x10)) {
            LOCK();
            DAT_1c0006174 = DAT_1c0006174 + 1;
            UNLOCK();
            *(undefined1 *)(lVar7 + 0x58) = 0;
LAB_1c0001ef2:
            uVar12 = (*(undefined8 **)(lVar10 + 0x20))[1];
            *(undefined8 *)(lVar7 + 0x48) = **(undefined8 **)(lVar10 + 0x20);
            *(undefined8 *)(lVar7 + 0x50) = uVar12;
            goto LAB_1c0002367;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar13 = 0x1f;
LAB_1c0001ec4:
            WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar8,pcVar11,uVar13,
                              &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids);
          }
LAB_1c0001ed9:
          iVar9 = -0x3ffffff3;
          goto LAB_1c0002367;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar13 = 0x1e;
LAB_1c0001e90:
          WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar8,pcVar11,uVar13,
                            &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids);
        }
LAB_1c0001ea5:
        iVar9 = -0x3fffffbd;
        goto LAB_1c0002367;
      }
      if (uVar2 == 0xf0403) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar13 = 0x20;
          goto LAB_1c0002196;
        }
        goto LAB_1c00021ab;
      }
      if (uVar2 != 0xf3fc7) {
LAB_1c00021fa:
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar8,pcVar11,0x2b,
                             &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids,
                             in_stack_ffffffffffffffc0,(char)uVar2);
        }
        goto LAB_1c0002362;
      }
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar13 = 0x29;
LAB_1c000234d:
      WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar8,pcVar11,uVar13,
                        &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids);
    }
  }
LAB_1c0002362:
  iVar9 = -0x3ffffff0;
LAB_1c0002367:
  *(int *)(param_2 + 0x30) = iVar9;
  IofCompleteRequest(param_2,0);
  uVar12 = 0x20;
  pcVar8 = PtInternalDeviceControl;
  IoReleaseRemoveLockEx(lVar7 + 0x18);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar8,uVar12,0x2c,
                        &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids,in_stack_ffffffffffffffc0,
                        uVar14,(char)iVar9);
  }
  return iVar9;
}



===== PtSendCurrentKeyboardIndicators @ 1c00023ec =====

undefined8 PtSendCurrentKeyboardIndicators(longlong param_1,undefined2 *param_2,longlong param_3)

{
  byte *pbVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 uVar6;
  undefined8 uVar7;
  
  lVar5 = *(longlong *)(param_1 + 0x40);
  lVar3 = lVar5 + 0xe8;
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar3);
  uVar7 = 0;
  if (*(char *)(lVar5 + 0xde) == '\0') {
    if (*(longlong *)(lVar5 + 0xe0) == 0) {
      *(longlong *)(lVar5 + 0xe0) = param_3;
      pbVar1 = (byte *)(*(longlong *)(param_3 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      LOCK();
      *(code **)(*(longlong *)(lVar5 + 0xe0) + 0x68) = CancelIndicatorIrp;
      UNLOCK();
      if (*(char *)(param_3 + 0x44) != '\0') {
        LOCK();
        plVar2 = (longlong *)(*(longlong *)(lVar5 + 0xe0) + 0x68);
        lVar4 = *plVar2;
        *plVar2 = 0;
        UNLOCK();
        if (lVar4 != 0) {
          *(undefined8 *)(lVar5 + 0xe0) = 0;
          KeReleaseSpinLock(lVar3,CONCAT71((int7)((ulonglong)lVar4 >> 8),uVar6));
          *(undefined8 *)(param_3 + 0x38) = 0;
          *(undefined4 *)(param_3 + 0x30) = 0xc0000120;
          IofCompleteRequest(param_3,0);
          return 0x103;
        }
      }
      uVar7 = 0x103;
    }
    else {
      uVar7 = 0xc0000021;
    }
  }
  else {
    *param_2 = *(undefined2 *)(lVar5 + 0xda);
    param_2[2] = *(undefined2 *)(lVar5 + 0xdc);
    *(undefined1 *)(lVar5 + 0xde) = 0;
    *(undefined8 *)(param_3 + 0x38) = 0xc;
  }
  KeReleaseSpinLock(lVar3,uVar6);
  return uVar7;
}



===== PtSendCurrentKeyboardInput @ 1c0002520 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PtSendCurrentKeyboardInput(longlong param_1,longlong param_2,ulonglong param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined1 uVar5;
  uint uVar6;
  longlong lVar7;
  int iVar8;
  ulonglong uVar9;
  uint local_res8 [2];
  undefined8 local_res20;
  undefined *in_stack_ffffffffffffffb8;
  undefined8 in_stack_ffffffffffffffc0;
  
  local_res20 = 0;
  lVar7 = param_2;
  uVar9 = param_3;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_ffffffffffffffb8 = &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids;
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x31,
                      &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids);
  }
  lVar2 = *(longlong *)(param_1 + 0x40);
  if (*(int *)(lVar2 + 0x40) != 0) {
    uVar3 = *(undefined8 *)(lVar2 + 0x48);
    pcVar4 = *(code **)(lVar2 + 0x50);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar7,uVar9,0x32,
                         in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,(char)param_3);
    }
    uVar1 = param_2 + (param_3 & 0xffffffff) * 0xc;
    if ((int)param_3 != 0) {
      while( true ) {
        local_res8[0] = 0;
        uVar5 = KfRaiseIrql(2);
        uVar9 = uVar1;
        (*pcVar4)(uVar3,param_2,uVar1,local_res8);
        KeLowerIrql(uVar5);
        uVar6 = (int)uVar1 - (int)param_2;
        lVar7 = SUB168(ZEXT816(0xaaaaaaaaaaaaaaab) * ZEXT416(uVar6),8);
        iVar8 = uVar6 / 0xc - local_res8[0];
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar7,uVar9,0x33,
                              in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,
                              (char)local_res8[0],(char)iVar8);
        }
        if (iVar8 == 0) break;
        local_res20 = 0xffffffffffffd8f0;
        param_2 = param_2 + (ulonglong)local_res8[0] * 0xc;
        KeDelayExecutionThread(0,1,&local_res20);
      }
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar7,uVar9,0x34,
                       &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids,in_stack_ffffffffffffffc0,
                       (char)param_1);
  }
  return;
}



===== PtSendCurrentMouseInput @ 1c00026cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PtSendCurrentMouseInput(longlong param_1,longlong param_2,ulonglong param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined1 uVar5;
  uint uVar6;
  longlong lVar7;
  int iVar8;
  ulonglong uVar9;
  uint local_res8 [2];
  undefined8 local_res20;
  undefined *in_stack_ffffffffffffffb8;
  undefined8 in_stack_ffffffffffffffc0;
  
  local_res20 = 0;
  lVar7 = param_2;
  uVar9 = param_3;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_ffffffffffffffb8 = &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids;
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x35,
                      &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids);
  }
  lVar2 = *(longlong *)(param_1 + 0x40);
  if (*(int *)(lVar2 + 0x40) != 0) {
    uVar3 = *(undefined8 *)(lVar2 + 0x48);
    pcVar4 = *(code **)(lVar2 + 0x50);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sl(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar7,uVar9,0x36,
                         in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,(char)param_3);
    }
    uVar1 = param_2 + (param_3 & 0xffffffff) * 0x18;
    if ((int)param_3 != 0) {
      while( true ) {
        local_res8[0] = 0;
        uVar5 = KfRaiseIrql(2);
        uVar9 = uVar1;
        (*pcVar4)(uVar3,param_2,uVar1,local_res8);
        KeLowerIrql(uVar5);
        uVar6 = (int)uVar1 - (int)param_2;
        lVar7 = SUB168(ZEXT816(0xaaaaaaaaaaaaaaab) * ZEXT416(uVar6),8);
        iVar8 = uVar6 / 0x18 - local_res8[0];
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar7,uVar9,0x37,
                              in_stack_ffffffffffffffb8,in_stack_ffffffffffffffc0,
                              (char)local_res8[0],(char)iVar8);
        }
        if (iVar8 == 0) break;
        local_res20 = 0xffffffffffffd8f0;
        param_2 = param_2 + (ulonglong)local_res8[0] * 0x18;
        KeDelayExecutionThread(0,1,&local_res20);
      }
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar7,uVar9,0x38,
                       &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids,in_stack_ffffffffffffffc0,
                       (char)param_1);
  }
  return;
}



===== WPP_RECORDER_SF_sdd @ 1c0002878 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sdd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined8 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids,param_4," ",2,&param_7,4,&param_8,4,
               0);
  }
  WppAutoLogTrace(param_1,0,1,&WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids,param_4," ",2,
                  &param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_sl @ 1c000296c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sl(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined8 param_6,undefined1 param_7)

{
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids,param_4," ",2,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,0,1,&WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids,param_4," ",2,
                  &param_7,4,0);
  return;
}



===== WppClassicProviderCallback @ 1c0002a40 =====

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



===== TiAddDeviceToSession @ 1c0002a9c =====

undefined4 TiAddDeviceToSession(int param_1,undefined8 *param_2,undefined8 param_3)

{
  int *piVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined8 *puVar5;
  int *piVar6;
  undefined8 *puVar7;
  int *piVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined4 uVar11;
  undefined8 uStackY_60;
  undefined1 auStackY_58 [32];
  undefined8 in_stack_ffffffffffffffd0;
  undefined1 auStack_25 [5];
  undefined1 local_20 [8];
  
  uVar11 = 0;
  puVar7 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x1f,
                      &WPP_f4489e3f527037eb652f42e776eee992_Traceguids);
  }
  puVar9 = auStackY_58;
  TiLock();
  for (puVar5 = DAT_1c00061e8; (undefined8 **)puVar5 != &DAT_1c00061e8;
      puVar5 = (undefined8 *)*puVar5) {
    piVar6 = (int *)(puVar5 + -8);
    if (*piVar6 == param_1) {
      *(int *)(puVar5 + 4) = *(int *)(puVar5 + 4) + 1;
      puVar10 = auStackY_58;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0002be3;
      WPP_RECORDER_SF_sDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      puVar10 = auStackY_58;
      goto LAB_1c0002be3;
    }
  }
  puVar7 = (undefined8 *)0x68;
  param_3 = 0x69547354;
  piVar6 = (int *)ExAllocatePoolWithTag(0x200);
  puVar10 = auStackY_58;
  if (piVar6 == (int *)0x0) goto LAB_1c0002c26;
  *piVar6 = param_1;
  KeInitializeGuardedMutex(piVar6 + 2);
  piVar8 = piVar6 + 0x10;
  puVar10 = auStackY_58;
  if ((undefined8 **)*(undefined8 **)DAT_1c00061f0 != &DAT_1c00061e8) goto LAB_1c0002c1f;
  *(undefined8 ***)piVar8 = &DAT_1c00061e8;
  *(int **)(piVar6 + 0x12) = DAT_1c00061f0;
  *(int **)DAT_1c00061f0 = piVar8;
  piVar1 = piVar6 + 0x14;
  DAT_1c00061f0 = piVar8;
  *(int **)(piVar6 + 0x16) = piVar1;
  *(int **)piVar1 = piVar1;
  piVar6[0x18] = 1;
  puVar10 = auStackY_58;
  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0002be3;
  WPP_RECORDER_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar7,param_3,0x20,
                     &WPP_f4489e3f527037eb652f42e776eee992_Traceguids,in_stack_ffffffffffffffd0,
                     (char)piVar6);
  TiUnlock();
  piVar8 = piVar6;
  while( true ) {
    param_2[0x18] = piVar8;
    *(undefined8 *)(puVar9 + -8) = 0x1c0002c02;
    KeAcquireGuardedMutex(piVar8 + 2);
    puVar2 = *(undefined8 **)(piVar8 + 0x16);
    puVar5 = param_2 + 0x19;
    piVar6 = piVar8 + 0x14;
    puVar10 = puVar9;
    if ((int *)*puVar2 == piVar6) {
      param_2[0x1a] = puVar2;
      *puVar5 = piVar6;
      *puVar2 = puVar5;
      *(undefined8 **)(piVar8 + 0x16) = puVar5;
      *(undefined8 *)(puVar9 + -8) = 0x1c0002cbe;
      KeReleaseGuardedMutex(piVar8 + 2);
      goto LAB_1c0002c54;
    }
LAB_1c0002c1f:
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    puVar10 = puVar10 + 8;
LAB_1c0002c26:
    puVar9 = puVar10;
    puVar10 = puVar9;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) break;
LAB_1c0002be3:
    puVar9 = puVar10;
    *(undefined8 *)(puVar9 + -8) = 0x1c0002be8;
    TiUnlock();
    piVar8 = piVar6;
    if (piVar6 == (int *)0x0) {
LAB_1c0002c4f:
      uVar11 = 0xc000009a;
LAB_1c0002c54:
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar3 = *param_2;
        *(undefined4 *)(puVar9 + 0x38) = uVar11;
        *(undefined8 *)(puVar9 + 0x30) = uVar3;
        *(undefined **)(puVar9 + 0x20) = &WPP_f4489e3f527037eb652f42e776eee992_Traceguids;
        uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
        *(undefined8 *)(puVar9 + -8) = 0x1c0002c84;
        WPP_RECORDER_SF_sqd(uVar3,puVar7,param_3,0x23,*(undefined8 *)(puVar9 + 0x20),
                            *(undefined8 *)(puVar9 + 0x28),puVar9[0x30],puVar9[0x38]);
      }
      return uVar11;
    }
  }
  *(undefined **)(puVar9 + 0x20) = &WPP_f4489e3f527037eb652f42e776eee992_Traceguids;
  uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
  *(undefined8 *)(puVar9 + -8) = 0x1c0002c4a;
  WPP_RECORDER_SF_s(uVar3,puVar7,param_3,0x21,*(undefined8 *)(puVar9 + 0x20));
  *(undefined8 *)(puVar9 + -8) = 0x1c0002c4f;
  TiUnlock();
  goto LAB_1c0002c4f;
}



===== TiLockSession @ 1c0002ccc =====

void TiLockSession(longlong param_1)

{
  KeAcquireGuardedMutex(param_1 + 8);
  return;
}



===== TiRemoveDeviceFromSession @ 1c0002cec =====

void TiRemoveDeviceFromSession(undefined8 *param_1,longlong param_2,undefined8 param_3)

{
  int *piVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  code *pcVar6;
  bool bVar7;
  undefined8 in_stack_ffffffffffffffd0;
  
  lVar3 = param_1[0x18];
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x24,
                      &WPP_f4489e3f527037eb652f42e776eee992_Traceguids);
  }
  if (lVar3 != 0) {
    KeAcquireGuardedMutex(lVar3 + 8);
    if (param_1[0x18] == 0) {
      bVar7 = false;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x26,
                          &WPP_f4489e3f527037eb652f42e776eee992_Traceguids);
      }
    }
    else {
      param_1[0x18] = 0;
      plVar2 = param_1 + 0x19;
      param_2 = *plVar2;
      bVar7 = true;
      if ((*(longlong **)(param_2 + 8) != plVar2) ||
         (plVar4 = (longlong *)param_1[0x1a], (longlong *)*plVar4 != plVar2)) goto LAB_1c0002eac;
      *plVar4 = param_2;
      *(longlong **)(param_2 + 8) = plVar4;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x25,
                           &WPP_f4489e3f527037eb652f42e776eee992_Traceguids,
                           in_stack_ffffffffffffffd0,(char)lVar3);
      }
    }
    KeReleaseGuardedMutex(lVar3 + 8);
    if (bVar7) {
      TiLock();
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x27,
                           &WPP_f4489e3f527037eb652f42e776eee992_Traceguids,
                           in_stack_ffffffffffffffd0,(char)lVar3);
      }
      piVar1 = (int *)(lVar3 + 0x60);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        plVar2 = (longlong *)(lVar3 + 0x40);
        lVar5 = *plVar2;
        if ((*(longlong **)(lVar5 + 8) != plVar2) ||
           (plVar4 = *(longlong **)(lVar3 + 0x48), (longlong *)*plVar4 != plVar2)) {
LAB_1c0002eac:
          pcVar6 = (code *)swi(0x29);
          (*pcVar6)(3);
          pcVar6 = (code *)swi(3);
          (*pcVar6)();
          return;
        }
        *plVar4 = lVar5;
        *(longlong **)(lVar5 + 8) = plVar4;
        param_2 = 0x69547354;
        ExFreePoolWithTag(lVar3);
      }
      TiUnlock();
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x28,
                       &WPP_f4489e3f527037eb652f42e776eee992_Traceguids,in_stack_ffffffffffffffd0,
                       (char)*param_1);
  }
  return;
}



===== TiUnlockSession @ 1c0002ebc =====

void TiUnlockSession(longlong param_1)

{
  KeReleaseGuardedMutex(param_1 + 8);
  return;
}



===== WPP_RECORDER_SF_sDq @ 1c0002edc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sDq(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f4489e3f527037eb652f42e776eee992_Traceguids,0x22," ",2,&uStack0000000000000038,4
               ,&uStack0000000000000040,8,0);
  }
  WppAutoLogTrace(param_1,0,1,&WPP_f4489e3f527037eb652f42e776eee992_Traceguids,0x22," ",2,
                  &uStack0000000000000038,4,&uStack0000000000000040,8,0);
  return;
}



===== _guard_check_icall @ 1c0002fe0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0002ff8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000301c =====

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



===== __cpu_features_init @ 1c0003090 =====

/* WARNING: Removing unreachable block (ram,0x0001c00030fa) */
/* WARNING: Removing unreachable block (ram,0x0001c00030a9) */
/* WARNING: Removing unreachable block (ram,0x0001c000309a) */

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



===== __security_check_cookie @ 1c0003160 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c00031a0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c00031d0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c00031d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0003200 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0003280 =====

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



===== memset @ 1c0003580 =====

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



===== __memset_repmovs @ 1c00036c0 =====

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



===== __memset_query @ 1c0003740 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c00037c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0003900 =====

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



===== __memset_spec_plain @ 1c0003980 =====

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



===== PtAddDevice @ 1c0009010 =====

int PtAddDevice(undefined8 param_1,ulonglong param_2)

{
  longlong *_Dst;
  int iVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined2 uVar7;
  uint local_res18 [4];
  undefined4 uVar9;
  uint *puVar8;
  undefined1 in_stack_ffffffffffffffb0;
  undefined7 in_stack_ffffffffffffffb1;
  longlong local_38 [2];
  
  local_38[0] = 0;
  uVar9 = (undefined4)((ulonglong)local_res18 >> 0x20);
  local_res18[0] = 0;
  uVar6 = 0;
  uVar4 = 0xb;
  iVar1 = IoGetDeviceProperty(param_2);
  iVar2 = 0;
  if (iVar1 != -0x3fffffdd) {
    iVar2 = iVar1;
  }
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar7 = 10;
LAB_1c000926b:
      WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,uVar6,uVar7,
                        &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids);
    }
  }
  else {
    uVar5 = local_res18[0] + 0xf0;
    if (uVar5 < 0xf0) {
      iVar2 = -0x3ffffff3;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar7 = 0xb;
        goto LAB_1c000926b;
      }
    }
    else {
      uVar6 = 0;
      in_stack_ffffffffffffffb0 = 0;
      uVar4 = (ulonglong)uVar5;
      iVar2 = IoCreateDevice(param_1,uVar4,0,0x27,CONCAT44(uVar9,0x100),0,local_38);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar7 = 0xc;
          goto LAB_1c000926b;
        }
      }
      else {
        _Dst = *(longlong **)(local_38[0] + 0x40);
        memset(_Dst,0,(ulonglong)uVar5);
        KeInitializeSpinLock(_Dst + 0x1d);
        uVar6 = (ulonglong)local_res18[0];
        puVar8 = local_res18;
        uVar4 = 0xb;
        iVar2 = IoGetDeviceProperty(param_2,0xb,uVar6,_Dst + 0x1e,puVar8);
        uVar9 = (undefined4)((ulonglong)puVar8 >> 0x20);
        if (iVar2 < 0) {
LAB_1c0009211:
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,uVar6,0xd,
                              &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids);
            if (-1 < iVar2) goto LAB_1c000929a;
          }
        }
        else {
          if (0xffff < local_res18[0]) {
            iVar2 = -0x3ffffe7c;
            goto LAB_1c0009211;
          }
          _Dst[0x16] = (longlong)(_Dst + 0x1e);
          *(short *)(_Dst + 0x15) = (short)local_res18[0] + -2;
          *(short *)((longlong)_Dst + 0xaa) = (short)local_res18[0] + -2;
          uVar4 = param_2;
          lVar3 = IoAttachDeviceToDeviceStack(local_38[0]);
          _Dst[1] = lVar3;
          if (lVar3 != 0) {
            *_Dst = local_38[0];
            uVar6 = 0;
            _Dst[2] = param_2;
            uVar4 = 0x69547354;
            IoInitializeRemoveLockEx(_Dst + 3,0x69547354,0,0x14,CONCAT44(uVar9,0x20));
            *(uint *)(local_38[0] + 0x30) = *(uint *)(local_38[0] + 0x30) | 4;
            *(uint *)(local_38[0] + 0x30) = *(uint *)(local_38[0] + 0x30) & 0xffffff7f;
            goto LAB_1c000929a;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,uVar6,0xe,
                              &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids);
          }
          iVar2 = -0x3ffffff2;
        }
        if ((_Dst != (longlong *)0x0) && (_Dst[1] != 0)) {
          IoDetachDevice(local_38[0]);
        }
      }
    }
  }
  if (local_38[0] != 0) {
    IoDeleteDevice();
    local_38[0] = 0;
  }
LAB_1c000929a:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,uVar6,0xf,
                       &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids,
                       CONCAT71(in_stack_ffffffffffffffb1,in_stack_ffffffffffffffb0),(char)iVar2);
  }
  return iVar2;
}



===== PtPnP @ 1c00092f0 =====

int PtPnP(longlong param_1,undefined *param_2,undefined8 param_3)

{
  byte bVar1;
  undefined8 *puVar2;
  longlong lVar3;
  int iVar4;
  int *piVar5;
  code *pcVar6;
  undefined *puVar7;
  int unaff_EBX;
  char *pcVar8;
  undefined2 uVar9;
  undefined8 in_stack_ffffffffffffffd0;
  
  if (*(int *)(param_1 + 0x48) == 0x38) {
    return unaff_EBX;
  }
  puVar2 = *(undefined8 **)(param_1 + 0x40);
  lVar3 = *(longlong *)(param_2 + 0xb8);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x14,
                       &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids,in_stack_ffffffffffffffd0,
                       *(undefined1 *)(lVar3 + 1));
  }
  pcVar8 = "";
  pcVar6 = PtPnP;
  iVar4 = IoAcquireRemoveLockEx(puVar2 + 3,PtPnP,"",1,0x20);
  if (iVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return unaff_EBX;
    }
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar6,pcVar8,0x15,
                      &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids);
    goto LAB_1c0009453;
  }
  bVar1 = *(byte *)(lVar3 + 1);
  if (bVar1 < 0xb) {
    if (bVar1 == 10) goto LAB_1c000940f;
    puVar7 = param_2;
    if (bVar1 < 6) {
      if (bVar1 == 5) {
LAB_1c00096bf:
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar6,pcVar8,0x1b,
                            &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids);
        }
        iVar4 = PtSendIrpSynchronously(puVar2[1],(longlong)param_2,pcVar8);
        if (-1 < iVar4) {
          TiLockSession(puVar2[0x18]);
          *(byte *)(puVar2 + 0x1b) = *(byte *)(puVar2 + 0x1b) | 2;
          goto LAB_1c000973c;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar9 = 0x1c;
          goto LAB_1c000970b;
        }
      }
      else {
        if (bVar1 != 0) {
          if (bVar1 != 1) {
            if (bVar1 == 2) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar6,pcVar8,0x1f,
                                  &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids);
              }
              pcVar8 = (char *)0x20;
              pcVar6 = PtPnP;
              IoReleaseRemoveLockAndWaitEx(puVar2 + 3);
              if (*(char *)(puVar2 + 0x14) != '\0') {
                pcVar6 = (code *)0x2;
                IoWMIRegistrationControl(*puVar2);
              }
              PtReleaseSessionDevice(puVar2,(longlong)pcVar6,pcVar8);
              piVar5 = &DAT_1c0006170;
              if (*(char *)(puVar2 + 0xb) == '\0') {
                piVar5 = &DAT_1c0006174;
              }
              LOCK();
              *piVar5 = *piVar5 + -1;
              UNLOCK();
              IoDetachDevice(puVar2[1]);
              *(undefined4 *)(param_2 + 0x30) = 0;
              param_2[0x43] = param_2[0x43] + '\x01';
              *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
              iVar4 = IofCallDriver(puVar2[1]);
              IoDeleteDevice(param_1);
              pcVar6 = (code *)param_2;
              goto LAB_1c0009453;
            }
            if (bVar1 == 3) goto LAB_1c000975a;
            goto LAB_1c000940f;
          }
          goto LAB_1c00096bf;
        }
        iVar4 = PtSendIrpSynchronously(puVar2[1],(longlong)param_2,pcVar8);
        if ((iVar4 < 0) || (*(int *)(param_2 + 0x30) < 0)) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar7,pcVar8,0x19,
                                &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids,
                                in_stack_ffffffffffffffd0,(char)*(undefined4 *)(param_2 + 0x30),
                                (char)iVar4);
          }
          iVar4 = *(int *)(param_2 + 0x30);
        }
        else if (*(char *)(puVar2 + 0x17) == '\0') {
          if (puVar2[10] == 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar7,pcVar8,0x17,
                                &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids);
            }
            iVar4 = -0x3ffffe7c;
          }
          else {
            iVar4 = PtInitWmi(puVar2,puVar7,pcVar8);
            if (-1 < iVar4) {
              *(undefined1 *)(puVar2 + 0x14) = 1;
              iVar4 = PtPrepareSessionDevice(puVar2,puVar7,pcVar8);
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar7,pcVar8,0x18,
                                   &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids,
                                   in_stack_ffffffffffffffd0,(char)iVar4);
              }
              if (-1 < iVar4) {
                *(undefined1 *)(puVar2 + 0x17) = 1;
              }
            }
          }
        }
        else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar7,pcVar8,0x16,
                            &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids);
        }
      }
    }
    else {
      if (bVar1 != 6) goto LAB_1c000940f;
LAB_1c000975a:
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar6,pcVar8,0x1d,
                          &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids);
      }
      iVar4 = PtSendIrpSynchronously(puVar2[1],(longlong)param_2,pcVar8);
      if (iVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c00096a1;
        uVar9 = 0x1e;
LAB_1c000970b:
        WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar7,pcVar8,uVar9,
                           &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids,
                           in_stack_ffffffffffffffd0,(char)iVar4);
      }
      else {
        TiLockSession(puVar2[0x18]);
        *(byte *)(puVar2 + 0x1b) = *(byte *)(puVar2 + 0x1b) & 0xfd;
LAB_1c000973c:
        TiUnlockSession(puVar2[0x18]);
      }
    }
LAB_1c00096a1:
    *(undefined8 *)(param_2 + 0x38) = 0;
LAB_1c00096a6:
    *(int *)(param_2 + 0x30) = iVar4;
    IofCompleteRequest(param_2,0);
  }
  else {
    if ((((((bVar1 != 0xb) && (bVar1 != 0xc)) && (bVar1 != 0xd)) &&
         ((bVar1 != 0xf && (bVar1 != 0x10)))) &&
        ((bVar1 != 0x11 && ((bVar1 != 0x12 && (bVar1 != 0x13)))))) && (bVar1 == 0x14)) {
      puVar7 = param_2;
      iVar4 = PtSendIrpSynchronously(puVar2[1],(longlong)param_2,pcVar8);
      if ((iVar4 == -0x3fffff45) || (iVar4 == -0x3ffffff0)) {
        iVar4 = 0;
      }
      else if (iVar4 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar7,pcVar8,0x1a,
                             &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids,
                             in_stack_ffffffffffffffd0,(char)iVar4);
        }
        goto LAB_1c00096a6;
      }
      *(ulonglong *)(param_2 + 0x38) = *(ulonglong *)(param_2 + 0x38) & 0xffffffffffffffdf;
      goto LAB_1c00096a6;
    }
LAB_1c000940f:
    param_2[0x43] = param_2[0x43] + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    iVar4 = IofCallDriver(puVar2[1],param_2);
  }
  pcVar8 = (char *)0x20;
  pcVar6 = PtPnP;
  IoReleaseRemoveLockEx(puVar2 + 3);
LAB_1c0009453:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar6,pcVar8,0x20,
                        &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids,in_stack_ffffffffffffffd0,
                        (char)param_1,(char)iVar4);
  }
  return unaff_EBX;
}



===== PtSendIrpSynchronously @ 1c0009884 =====

int PtSendIrpSynchronously(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 in_stack_ffffffffffffffc0;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x10,
                      &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids);
  }
  uVar4 = 0;
  KeInitializeEvent(&local_28,1);
  puVar1 = *(undefined8 **)(param_2 + 0xb8);
  puVar1[-9] = *puVar1;
  puVar1[-8] = puVar1[1];
  puVar1[-7] = puVar1[2];
  puVar1[-6] = puVar1[3];
  *(undefined4 *)(puVar1 + -5) = *(undefined4 *)(puVar1 + 4);
  *(undefined4 *)((longlong)puVar1 + -0x24) = *(undefined4 *)((longlong)puVar1 + 0x24);
  *(undefined4 *)(puVar1 + -4) = *(undefined4 *)(puVar1 + 5);
  *(undefined4 *)((longlong)puVar1 + -0x1c) = *(undefined4 *)((longlong)puVar1 + 0x2c);
  puVar1[-3] = puVar1[6];
  *(undefined1 *)((longlong)puVar1 + -0x45) = 0;
  lVar3 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar3 + -0x10) = PtPnPComplete;
  *(undefined8 **)(lVar3 + -8) = &local_28;
  *(undefined1 *)(lVar3 + -0x45) = 0xe0;
  lVar3 = param_2;
  iVar2 = IofCallDriver(param_1);
  if (iVar2 == 0x103) {
    uVar4 = 0;
    lVar3 = 0;
    KeWaitForSingleObject(&local_28,0,0,0,0);
    iVar2 = *(int *)(param_2 + 0x30);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar3,uVar4,0x11,
                        &WPP_75fd79d40e58354b8c24f648881272a9_Traceguids,in_stack_ffffffffffffffc0,
                        (char)param_1,(char)iVar2);
  }
  return iVar2;
}



===== PtCreate @ 1c00099e0 =====

int PtCreate(longlong param_1,longlong param_2,undefined8 param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  code *pcVar5;
  char *pcVar6;
  undefined8 in_stack_ffffffffffffffd0;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,10,
                      &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids);
  }
  lVar3 = *(longlong *)(param_1 + 0x40);
  pcVar6 = "";
  pcVar5 = PtCreate;
  iVar4 = IoAcquireRemoveLockEx(lVar3 + 0x18,PtCreate,"",1,0x20);
  if (-1 < iVar4) {
    if (*(longlong *)(lVar3 + 0x50) == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar5,pcVar6,0xb,
                          &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids);
      }
      iVar4 = -0x3ffffe7c;
    }
    else {
      LOCK();
      piVar1 = (int *)(lVar3 + 0x40);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      if ((1 < iVar2 + 1) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar5,pcVar6,0xc,
                          &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids);
      }
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(int *)(param_2 + 0x30) = iVar4;
    IofCompleteRequest(param_2,0);
    pcVar6 = (char *)0x20;
    pcVar5 = PtCreate;
    IoReleaseRemoveLockEx(lVar3 + 0x18);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar5,pcVar6,0xd,
                        &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids,in_stack_ffffffffffffffd0,
                        (char)param_1,(char)iVar4);
  }
  return iVar4;
}



===== PtDeviceControl @ 1c0009b60 =====

int PtDeviceControl(longlong param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  char *pcVar5;
  undefined8 uVar6;
  undefined8 in_stack_ffffffffffffffc0;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x10,
                      &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x40);
  pcVar5 = "";
  pcVar3 = PtDeviceControl;
  iVar2 = IoAcquireRemoveLockEx(lVar1 + 0x18,PtDeviceControl,"",1,0x20);
  iVar4 = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  if (iVar2 < 0) {
    uVar6 = 0;
    *(int *)(param_2 + 0x30) = iVar2;
    IofCompleteRequest(param_2);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar6,pcVar5,0x11,
                          &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids,in_stack_ffffffffffffffc0
                          ,(char)param_1,(char)iVar2);
    }
    return iVar2;
  }
  if ((*(char *)(lVar1 + 0xb8) != '\0') && (*(char *)(lVar1 + 0x58) != '\0')) {
    iVar2 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
    if (iVar2 == 0x294140) {
      if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 4) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar3,pcVar5,0x12,
                            &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids);
        }
        iVar4 = -0x3ffffdfa;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar3,pcVar5,0x13,
                            &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids);
        }
        **(undefined4 **)(param_2 + 0x18) = 0;
      }
      *(undefined8 *)(param_2 + 0x38) = 4;
      goto LAB_1c0009c85;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar3,pcVar5,0x14,
                         &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids,in_stack_ffffffffffffffc0,
                         (char)iVar2);
    }
  }
  iVar4 = -0x3ffffff0;
LAB_1c0009c85:
  *(int *)(param_2 + 0x30) = iVar4;
  IofCompleteRequest(param_2,0);
  uVar6 = 0x20;
  pcVar3 = PtDeviceControl;
  IoReleaseRemoveLockEx(lVar1 + 0x18);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar3,uVar6,0x15,
                        &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids,in_stack_ffffffffffffffc0,
                        (char)param_1,(char)iVar4);
  }
  return iVar4;
}



===== PtInitWmi @ 1c0009d74 =====

undefined4 PtInitWmi(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined **ppuVar2;
  code *pcVar3;
  undefined8 uVar4;
  code *pcVar5;
  undefined8 in_stack_ffffffffffffffe0;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,10,
                      &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids);
  }
  pcVar5 = PtMouseQueryWmiDataBlock;
  ppuVar2 = &KbWmiGuidList;
  if (*(char *)(param_1 + 0xb) == '\0') {
    ppuVar2 = &MouWmiGuidList;
  }
  *(undefined4 *)(param_1 + 0xc) = 1;
  param_1[0xd] = ppuVar2;
  uVar4 = 1;
  pcVar3 = PtKeyboardQueryWmiDataBlock;
  if (*(char *)(param_1 + 0xb) == '\0') {
    pcVar3 = PtMouseQueryWmiDataBlock;
  }
  param_1[0xf] = pcVar3;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0xe] = PtQueryWmiRegInfo;
  param_1[0x10] = PtSetWmiDataBlock;
  param_1[0x11] = PtSetWmiDataItem;
  uVar1 = IoWMIRegistrationControl(*param_1);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,pcVar5,0xb,
                        &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids,in_stack_ffffffffffffffe0,
                        (char)*param_1,(char)uVar1);
  }
  return uVar1;
}



===== PtKeyboardQueryWmiDataBlock @ 1c0009e90 =====

void PtKeyboardQueryWmiDataBlock
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined4 *param_6,uint param_7,undefined4 *param_8)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined2 uVar4;
  undefined *in_stack_ffffffffffffffb8;
  undefined8 in_stack_ffffffffffffffc0;
  
  uVar1 = param_2;
  uVar3 = param_3;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_ffffffffffffffb8 = &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids;
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x15,
                      &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids);
  }
  if ((int)param_3 == 0) {
    if (param_7 < 0x14) {
      uVar2 = 0xc0000023;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0009f96;
      uVar4 = 0x16;
      goto LAB_1c0009f2d;
    }
    *param_8 = 0;
    param_8[1] = 1;
    param_8[2] = 0;
    param_8[3] = 0xc;
    param_8[4] = 3;
    uVar2 = 0;
    *param_6 = 0x14;
  }
  else {
    uVar2 = 0xc0000295;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0009f96;
    uVar4 = 0x17;
LAB_1c0009f2d:
    in_stack_ffffffffffffffb8 = &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids;
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar1,uVar3,uVar4,
                      &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_ffffffffffffffb8 = &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids;
    WPP_RECORDER_SF_sqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar1,uVar3,0x18,
                        &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids,in_stack_ffffffffffffffc0,
                        (char)param_1,(char)uVar2);
  }
LAB_1c0009f96:
  WmiCompleteRequest(param_1,param_2,uVar2,0x14,
                     (ulonglong)in_stack_ffffffffffffffb8 & 0xffffffffffffff00);
  return;
}



===== PtMouseQueryWmiDataBlock @ 1c0009fe0 =====

void PtMouseQueryWmiDataBlock
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined4 *param_6,uint param_7,undefined4 *param_8)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined2 uVar4;
  undefined *in_stack_ffffffffffffffb8;
  undefined8 in_stack_ffffffffffffffc0;
  
  uVar1 = param_2;
  uVar3 = param_3;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_ffffffffffffffb8 = &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids;
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x19,
                      &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids);
  }
  if ((int)param_3 == 0) {
    if (param_7 < 0x14) {
      uVar2 = 0xc0000023;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000a0e0;
      uVar4 = 0x1a;
      goto LAB_1c000a07d;
    }
    *param_8 = 0;
    param_8[1] = 0;
    param_8[2] = 0;
    param_8[3] = 2;
    param_8[4] = 0;
    uVar2 = 0;
    *param_6 = 0x14;
  }
  else {
    uVar2 = 0xc0000295;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000a0e0;
    uVar4 = 0x1b;
LAB_1c000a07d:
    in_stack_ffffffffffffffb8 = &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids;
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar1,uVar3,uVar4,
                      &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_ffffffffffffffb8 = &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids;
    WPP_RECORDER_SF_sqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar1,uVar3,0x1c,
                        &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids,in_stack_ffffffffffffffc0,
                        (char)param_1,(char)uVar2);
  }
LAB_1c000a0e0:
  WmiCompleteRequest(param_1,param_2,uVar2,0x14,
                     (ulonglong)in_stack_ffffffffffffffb8 & 0xffffffffffffff00);
  return;
}



===== PtQueryWmiRegInfo @ 1c000a120 =====

undefined8
PtQueryWmiRegInfo(longlong param_1,undefined4 *param_2,undefined8 param_3,undefined8 *param_4,
                 undefined8 param_5,undefined8 *param_6)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined8 in_stack_ffffffffffffffe0;
  
  puVar2 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x1d,
                      &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x40);
  *param_2 = 0x20;
  *param_4 = &Globals;
  *param_6 = *(undefined8 *)(lVar1 + 0x10);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar2,param_3,0x1e,
                       &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids,in_stack_ffffffffffffffe0,
                       (char)param_1);
  }
  return 0;
}



===== PtSetWmiDataBlock @ 1c000a1e0 =====

void PtSetWmiDataBlock(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined *in_stack_ffffffffffffffd8;
  undefined8 in_stack_ffffffffffffffe0;
  
  uVar1 = param_2;
  uVar3 = param_3;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_ffffffffffffffd8 = &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids;
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x13,
                      &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids);
  }
  iVar2 = (-(uint)((int)param_3 != 0) & 0xffffffcf) + 0xc00002c6;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_ffffffffffffffd8 = &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids;
    WPP_RECORDER_SF_sqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar1,uVar3,0x14,
                        &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids,in_stack_ffffffffffffffe0,
                        (char)param_1,(char)iVar2);
  }
  WmiCompleteRequest(param_1,param_2,iVar2,0,
                     (ulonglong)in_stack_ffffffffffffffd8 & 0xffffffffffffff00);
  return;
}



===== PtSetWmiDataItem @ 1c000a2b0 =====

void PtSetWmiDataItem(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined *in_stack_ffffffffffffffd8;
  undefined8 in_stack_ffffffffffffffe0;
  
  uVar1 = param_2;
  uVar3 = param_3;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_ffffffffffffffd8 = &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids;
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x11,
                      &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids);
  }
  iVar2 = (-(uint)((int)param_3 != 0) & 0xffffffcf) + 0xc00002c6;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_ffffffffffffffd8 = &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids;
    WPP_RECORDER_SF_sqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar1,uVar3,0x12,
                        &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids,in_stack_ffffffffffffffe0,
                        (char)param_1,(char)iVar2);
  }
  WmiCompleteRequest(param_1,param_2,iVar2,0,
                     (ulonglong)in_stack_ffffffffffffffd8 & 0xffffffffffffff00);
  return;
}



===== PtSystemControl @ 1c000a380 =====

int PtSystemControl(longlong param_1,longlong param_2,undefined8 param_3)

{
  int iVar1;
  longlong lVar2;
  code *pcVar3;
  char *pcVar4;
  longlong lVar5;
  undefined2 uVar6;
  int local_res8 [2];
  undefined8 in_stack_ffffffffffffffc0;
  undefined1 uVar7;
  
  local_res8[0] = 0;
  lVar2 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0xc,
                      &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids);
  }
  uVar7 = (undefined1)param_1;
  if (*(int *)(param_1 + 0x48) == 0x38) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar2,param_3,0xd,
                          &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids,in_stack_ffffffffffffffc0
                          ,uVar7,0x10);
    }
    return -0x3ffffff0;
  }
  lVar2 = *(longlong *)(param_1 + 0x40);
  pcVar4 = "";
  iVar1 = IoAcquireRemoveLockEx(lVar2 + 0x18,PtSystemControl,"",1,0x20);
  if (iVar1 < 0) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    pcVar3 = (code *)0x0;
    *(int *)(param_2 + 0x30) = iVar1;
    IofCompleteRequest(param_2);
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar6 = 0xe;
  }
  else {
    lVar5 = param_2;
    iVar1 = WmiSystemControl(lVar2 + 0x60,param_1,param_2,local_res8);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,lVar5,0xf,
                          &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids,in_stack_ffffffffffffffc0
                          ,(char)local_res8[0],(char)iVar1);
    }
    if (local_res8[0] != 0) {
      if (local_res8[0] == 1) {
        IofCompleteRequest(param_2,0);
      }
      else {
        *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
        *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
        iVar1 = IofCallDriver(*(undefined8 *)(lVar2 + 8),param_2);
      }
    }
    pcVar4 = (char *)0x20;
    pcVar3 = PtSystemControl;
    IoReleaseRemoveLockEx(lVar2 + 0x18);
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar6 = 0x10;
  }
  WPP_RECORDER_SF_sqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar3,pcVar4,uVar6,
                      &WPP_75dad5a240733c7ee0bdc334ce996264_Traceguids,in_stack_ffffffffffffffc0,
                      uVar7,(char)iVar1);
  return iVar1;
}



===== TiUnload @ 1c000a580 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TiUnload(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0xf,
                      &WPP_a22c8264ce0a30878b50f65ec3447f16_Traceguids);
  }
  if (DAT_1c0006208 != 0) {
    IoDeleteSymbolicLink(&DAT_1c0006208);
  }
  if (DAT_1c00061f8 != 0) {
    IoDeleteDevice();
    DAT_1c00061f8 = 0;
  }
  if (DAT_1c0006200 != '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x2f,
                        &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids);
    }
    if (DAT_1c0006168 != 0) {
      param_2 = 0;
      ExFreePoolWithTag();
      DAT_1c0006168 = 0;
      _Globals = 0;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x30,
                        &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids);
    }
    DAT_1c0006200 = '\0';
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x10,
                      &WPP_a22c8264ce0a30878b50f65ec3447f16_Traceguids);
  }
  if (DAT_1c0006201 != '\0') {
    WppCleanupKm(param_1);
    DAT_1c0006201 = '\0';
  }
  return;
}



===== WppCleanupKm @ 1c000a6f0 =====

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



===== WppInitKm @ 1c000a7a0 =====

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



===== WppLoadTracingSupport @ 1c000a87c =====

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



===== WppTraceCallback @ 1c000a9c0 =====

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



===== CheckCurrentProcessForServiceSid @ 1c000ac48 =====

int CheckCurrentProcessForServiceSid(undefined8 param_1,undefined1 *param_2,undefined8 param_3)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 local_res10 [8];
  undefined8 in_stack_ffffffffffffffe0;
  
  local_res10[0] = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x29,
                      &WPP_f4489e3f527037eb652f42e776eee992_Traceguids);
  }
  puVar2 = local_res10;
  *param_2 = 0;
  iVar1 = RtlCheckTokenMembership(0);
  if (-1 < iVar1) {
    *param_2 = local_res10[0];
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_1,puVar2,0x2a,
                       &WPP_f4489e3f527037eb652f42e776eee992_Traceguids,in_stack_ffffffffffffffe0,
                       (char)iVar1);
  }
  return iVar1;
}



===== InitializeServiceSid @ 1c000ad04 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void InitializeServiceSid(undefined8 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined1 auStack_38 [32];
  undefined4 local_18;
  undefined2 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  local_14 = 0x500;
  local_18 = 0;
  RtlInitializeSid(param_1,&local_18,6);
  puVar1 = (undefined4 *)RtlSubAuthoritySid(param_1,0);
  *puVar1 = 0x50;
  puVar1 = (undefined4 *)RtlSubAuthoritySid(param_1,1);
  *puVar1 = *param_2;
  puVar1 = (undefined4 *)RtlSubAuthoritySid(param_1,2);
  *puVar1 = param_2[1];
  puVar1 = (undefined4 *)RtlSubAuthoritySid(param_1,3);
  *puVar1 = param_2[2];
  puVar1 = (undefined4 *)RtlSubAuthoritySid(param_1,4);
  *puVar1 = param_2[3];
  puVar1 = (undefined4 *)RtlSubAuthoritySid(param_1,5);
  *puVar1 = param_2[4];
  return;
}



===== IsCallerTermsrvService @ 1c000adfc =====

int IsCallerTermsrvService(undefined1 *param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 in_stack_ffffffffffffffc0;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x2b,
                      &WPP_f4489e3f527037eb652f42e776eee992_Traceguids);
  }
  *param_1 = 0;
  uVar1 = RtlLengthRequiredSid(6);
  uVar4 = (ulonglong)uVar1;
  uVar5 = 0x69547354;
  lVar3 = ExAllocatePoolWithTag(1);
  if (lVar3 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    local_28 = 0x1a963466;
    local_24 = 0x5cf1aab9;
    local_20 = 0xf8123019;
    local_1c = 0x7448ce95;
    local_18 = 0x304efda0;
    InitializeServiceSid(lVar3,&local_28);
    iVar2 = CheckCurrentProcessForServiceSid(lVar3,param_1,uVar5);
    uVar4 = 0x69547354;
    ExFreePoolWithTag(lVar3);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,uVar5,0x2c,
                       &WPP_f4489e3f527037eb652f42e776eee992_Traceguids,in_stack_ffffffffffffffc0,
                       (char)iVar2);
  }
  return iVar2;
}



===== TiClose @ 1c000af20 =====

undefined8 TiClose(longlong param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x14,
                      &WPP_f4489e3f527037eb652f42e776eee992_Traceguids);
  }
  if (*(int *)(param_1 + 0x48) == 0x38) {
    lVar1 = *(longlong *)(param_2 + 0xb8);
    ObfDereferenceObject();
    uVar2 = 0;
    *(undefined8 *)(*(longlong *)(lVar1 + 0x30) + 0x20) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar2,param_3,0x15,
                        &WPP_f4489e3f527037eb652f42e776eee992_Traceguids);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = PtClose(param_1,param_2,param_3);
  }
  return uVar2;
}



===== TiCreate @ 1c000b000 =====

int TiCreate(longlong param_1,longlong param_2,int *param_3)

{
  int *piVar1;
  longlong lVar2;
  undefined8 *puVar3;
  int iVar4;
  int iVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  short *psVar10;
  ushort uVar11;
  short sVar12;
  undefined2 uVar13;
  char local_res8 [8];
  int local_res18 [4];
  undefined8 in_stack_ffffffffffffff90;
  undefined8 local_58;
  short *psStack_50;
  undefined8 local_48;
  short *psStack_40;
  
  local_res18[0] = 0;
  local_58 = 0;
  psStack_50 = (short *)0x0;
  local_res8[0] = '\0';
  local_48 = 0;
  psStack_40 = (short *)0x0;
  lVar7 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,10,
                      &WPP_f4489e3f527037eb652f42e776eee992_Traceguids);
  }
  if (*(int *)(param_1 + 0x48) != 0x38) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar7,param_3,0xb,
                        &WPP_f4489e3f527037eb652f42e776eee992_Traceguids);
    }
    iVar4 = PtCreate(param_1,param_2,param_3);
    return iVar4;
  }
  lVar2 = *(longlong *)(param_2 + 0xb8);
  psVar10 = *(short **)(*(longlong *)(lVar2 + 0x30) + 0x60);
  uVar11 = *(ushort *)(*(longlong *)(lVar2 + 0x30) + 0x58) >> 1;
  iVar4 = IsCallerTermsrvService(local_res8,lVar7,param_3);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar7,param_3,0xc,
                       &WPP_f4489e3f527037eb652f42e776eee992_Traceguids,in_stack_ffffffffffffff90,
                       (char)iVar4);
  }
  if (iVar4 < 0) goto LAB_1c000b344;
  if (local_res8[0] == '\0') {
    iVar4 = -0x3fffffde;
    goto LAB_1c000b344;
  }
  if ((uVar11 == 0) || (*psVar10 != 0x5c)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar13 = 0xd;
LAB_1c000b32a:
      WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar7,param_3,uVar13,
                        &WPP_f4489e3f527037eb652f42e776eee992_Traceguids);
    }
  }
  else {
    param_3 = local_res18;
    sVar12 = uVar11 - 1;
    psVar10 = psVar10 + 1;
    lVar7 = 10;
    local_58 = CONCAT62(CONCAT42(local_58._4_4_,sVar12 * 2),sVar12 * 2);
    psStack_50 = psVar10;
    iVar4 = RtlUnicodeStringToInteger(&local_58);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),lVar7,param_3,0xe,
                         &WPP_f4489e3f527037eb652f42e776eee992_Traceguids,in_stack_ffffffffffffff90,
                         (char)iVar4);
    }
    if (iVar4 < 0) goto LAB_1c000b344;
    for (; sVar12 != 0; sVar12 = sVar12 + -1) {
      if (*psVar10 == 0x5c) {
        local_48._0_4_ = CONCAT22(sVar12 * 2,sVar12 * 2);
        psStack_40 = psVar10;
        KeAcquireGuardedMutex(&DAT_1c00061b0);
        puVar8 = &DAT_1c00061e8;
        puVar6 = DAT_1c00061e8;
        if ((undefined8 **)DAT_1c00061e8 != &DAT_1c00061e8) goto LAB_1c000b1ee;
        goto LAB_1c000b1fe;
      }
      psVar10 = psVar10 + 1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar13 = 0xf;
      goto LAB_1c000b32a;
    }
  }
  iVar4 = -0x3ffffff3;
  goto LAB_1c000b344;
  while (puVar6 = (undefined8 *)*puVar6, (undefined8 **)puVar6 != &DAT_1c00061e8) {
LAB_1c000b1ee:
    piVar1 = (int *)(puVar6 + -8);
    if (*piVar1 == local_res18[0]) {
      TiLockSession((longlong)piVar1);
      puVar3 = (undefined8 *)puVar6[2];
      goto joined_r0x0001c000b251;
    }
  }
LAB_1c000b1fe:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),&DAT_1c00061e8,param_3,0x10,
                      &WPP_f4489e3f527037eb652f42e776eee992_Traceguids);
  }
  iVar4 = -0x3fffff63;
  goto LAB_1c000b227;
joined_r0x0001c000b251:
  if (puVar3 == puVar6 + 2) goto LAB_1c000b287;
  param_3 = (int *)CONCAT71((int7)((ulonglong)param_3 >> 8),1);
  puVar8 = &local_48;
  iVar5 = RtlCompareUnicodeString(puVar3 + -4);
  if (iVar5 == 0) {
    if (*(char *)(puVar3 + 2) != '\x02') {
      *(undefined8 *)(*(longlong *)(lVar2 + 0x30) + 0x18) = 0;
      *(undefined8 **)(*(longlong *)(lVar2 + 0x30) + 0x20) = puVar3 + -0x19;
      ObfReferenceObject(puVar3[-0x19]);
      goto LAB_1c000b2b7;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c000b2b2;
    uVar13 = 0x11;
    goto LAB_1c000b296;
  }
  puVar3 = (undefined8 *)*puVar3;
  goto joined_r0x0001c000b251;
LAB_1c000b287:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar13 = 0x12;
LAB_1c000b296:
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar8,param_3,uVar13,
                      &WPP_f4489e3f527037eb652f42e776eee992_Traceguids);
  }
LAB_1c000b2b2:
  iVar4 = -0x3fffff63;
LAB_1c000b2b7:
  TiUnlockSession((longlong)piVar1);
LAB_1c000b227:
  KeReleaseGuardedMutex(&DAT_1c00061b0);
LAB_1c000b344:
  *(undefined8 *)(param_2 + 0x38) = 0;
  uVar9 = 0;
  *(int *)(param_2 + 0x30) = iVar4;
  IofCompleteRequest(param_2);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar9,param_3,0x13,
                       &WPP_f4489e3f527037eb652f42e776eee992_Traceguids,in_stack_ffffffffffffff90,
                       (char)iVar4);
  }
  return iVar4;
}



===== TiDeviceControl @ 1c000b3b0 =====

int TiDeviceControl(longlong param_1,undefined *param_2,undefined8 param_3)

{
  int iVar1;
  longlong lVar2;
  longlong *plVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  code *pcVar7;
  code *pcVar8;
  char *pcVar9;
  code *pcVar10;
  undefined2 uVar11;
  int local_res8 [2];
  undefined8 local_res10;
  undefined8 local_res18;
  ulonglong uVar12;
  uint in_stack_ffffffffffffff60;
  undefined4 in_stack_ffffffffffffff64;
  undefined8 local_88;
  wchar_t *local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                      &WPP_f4489e3f527037eb652f42e776eee992_Traceguids,param_3,0x16,
                      &WPP_f4489e3f527037eb652f42e776eee992_Traceguids);
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  if (*(int *)(param_1 + 0x48) != 0x38) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),
                        &WPP_f4489e3f527037eb652f42e776eee992_Traceguids,param_3,0x17,
                        &WPP_f4489e3f527037eb652f42e776eee992_Traceguids);
    }
    iVar4 = PtDeviceControl(param_1,(longlong)param_2,param_3);
    return iVar4;
  }
  lVar2 = *(longlong *)(param_2 + 0xb8);
  pcVar9 = "";
  pcVar7 = TiDeviceControl;
  iVar4 = *(int *)(lVar2 + 0x18);
  uVar12 = (ulonglong)*(uint *)(lVar2 + 0x10);
  iVar1 = *(int *)(lVar2 + 8);
  plVar3 = *(longlong **)(*(longlong *)(lVar2 + 0x30) + 0x20);
  iVar5 = IoAcquireRemoveLockEx(plVar3 + 3,TiDeviceControl,"",1,0x20);
  if (iVar5 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar7,pcVar9,0x18,
                        &WPP_f4489e3f527037eb652f42e776eee992_Traceguids);
    }
    iVar4 = -0x3fffff63;
  }
  else {
    TiLockSession(plVar3[0x18]);
    pcVar10 = (code *)0x20;
    pcVar7 = TiDeviceControl;
    IoReleaseRemoveLockEx(plVar3 + 3);
    if (iVar4 == 0x388804) {
      pcVar8 = *(code **)(param_2 + 0x18);
      iVar4 = 0;
      if ((pcVar8 == (code *)0x0) ||
         (pcVar9 = (char *)(uVar12 / 0xc), pcVar7 = (code *)pcVar9, uVar12 != (longlong)pcVar9 * 0xc
         )) {
        pcVar8 = pcVar7;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar11 = 0x19;
LAB_1c000b5e8:
          WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar8,pcVar10,uVar11,
                            &WPP_f4489e3f527037eb652f42e776eee992_Traceguids);
        }
LAB_1c000b5fd:
        iVar4 = -0x3ffffff3;
        pcVar9 = (char *)pcVar10;
      }
      else {
        PtSendCurrentKeyboardInput(*plVar3,(longlong)pcVar8,(ulonglong)pcVar9);
      }
    }
    else if (iVar4 == 0x388808) {
      pcVar8 = *(code **)(param_2 + 0x18);
      iVar4 = 0;
      if ((pcVar8 == (code *)0x0) ||
         (pcVar9 = (char *)(uVar12 / 0x18), pcVar7 = (code *)pcVar9,
         uVar12 != (longlong)pcVar9 * 0x18)) {
        pcVar8 = pcVar7;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar11 = 0x1b;
          goto LAB_1c000b5e8;
        }
        goto LAB_1c000b5fd;
      }
      PtSendCurrentMouseInput(*plVar3,(longlong)pcVar8,(ulonglong)pcVar9);
    }
    else if (iVar4 == 0x38880c) {
      pcVar8 = (code *)local_res8;
      local_res8[0] = 0;
      iVar4 = IoGetRequestorSessionId(param_2);
      pcVar9 = (char *)pcVar10;
      if (-1 < iVar4) {
        if (iVar1 != 8) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar11 = 0x1c;
            goto LAB_1c000b5e8;
          }
          goto LAB_1c000b5fd;
        }
        uVar6 = PsGetCurrentServerSilo();
        iVar4 = PsGetServerSiloServiceSessionId(uVar6);
        if (iVar4 == local_res8[0]) {
          local_res10 = 0;
          local_res18 = 0;
          TiUnlockSession(plVar3[0x18]);
          in_stack_ffffffffffffff60 = in_stack_ffffffffffffff60 & 0xffffff00;
          pcVar9 = (char *)0x0;
          uVar12 = 0;
          pcVar8 = (code *)0x200;
          iVar4 = ObOpenObjectByPointer
                            (plVar3[2],0x200,0,0x80000000,0,in_stack_ffffffffffffff60,&local_res10);
          if (-1 < iVar4) {
            in_stack_ffffffffffffff60 = 0x40001;
            local_88 = 0x20000;
            local_80 = L"";
            pcVar9 = (char *)&local_68;
            local_60 = local_res10;
            local_58 = &local_88;
            local_68 = 0x30;
            pcVar8 = (code *)0x80000000;
            local_78 = 0;
            uStack_70 = 0;
            local_50 = 0;
            local_48 = 0;
            uStack_40 = 0;
            iVar4 = ZwOpenFile(&local_res18,0x80000000,pcVar9,&local_78,uVar12 & 0xffffffff00000000)
            ;
            ZwClose(local_res10);
          }
          TiLockSession(plVar3[0x18]);
          if (iVar4 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar8,pcVar9,0x1d,
                                &WPP_f4489e3f527037eb652f42e776eee992_Traceguids);
            }
          }
          else {
            **(undefined8 **)(param_2 + 0x18) = local_res18;
            *(undefined8 *)(param_2 + 0x38) = 8;
          }
        }
        else {
          iVar4 = -0x3fffffde;
          pcVar9 = (char *)pcVar10;
        }
      }
    }
    else if (iVar4 == 0x388810) {
      pcVar8 = *(code **)(param_2 + 0x18);
      if ((pcVar8 == (code *)0x0) || (iVar1 != 0xc)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar11 = 0x1a;
          goto LAB_1c000b5e8;
        }
        goto LAB_1c000b5fd;
      }
      pcVar9 = param_2;
      uVar6 = PtSendCurrentKeyboardIndicators(*plVar3,(undefined2 *)pcVar8,(longlong)param_2);
      iVar4 = (int)uVar6;
    }
    else {
      iVar4 = -0x3ffffff0;
      pcVar8 = pcVar7;
      pcVar9 = (char *)pcVar10;
    }
    TiUnlockSession(plVar3[0x18]);
    if (iVar4 == 0x103) goto LAB_1c000b55f;
  }
  pcVar8 = (code *)0x0;
  *(int *)(param_2 + 0x30) = iVar4;
  IofCompleteRequest(param_2);
LAB_1c000b55f:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pcVar8,pcVar9,0x1e,
                        &WPP_f4489e3f527037eb652f42e776eee992_Traceguids,
                        CONCAT44(in_stack_ffffffffffffff64,in_stack_ffffffffffffff60),(char)param_1,
                        (char)iVar4);
  }
  return iVar4;
}



===== TiLock @ 1c000b86c =====

void TiLock(void)

{
  KeAcquireGuardedMutex(&DAT_1c00061b0);
  return;
}



===== TiUnlock @ 1c000b890 =====

void TiUnlock(void)

{
  KeReleaseGuardedMutex(&DAT_1c00061b0);
  return;
}



===== entry @ 1c000c010 =====

void entry(longlong param_1,wchar_t *param_2,undefined8 param_3)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2,param_3);
  return;
}



===== __security_init_cookie @ 1c000c044 =====

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
  __security_cookie_complement = ~__security_cookie;
  return;
}



===== PtEntry @ 1c000c078 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 PtEntry(undefined8 param_1,ushort *param_2,undefined8 param_3)

{
  ushort uVar1;
  ushort *puVar2;
  undefined1 uVar3;
  undefined4 unaff_EBX;
  undefined8 in_stack_ffffffffffffffe0;
  
  puVar2 = param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,param_3,0x2d,
                      &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids);
  }
  DAT_1c0006168 = (void *)0x0;
  uVar1 = *param_2 + 2;
  if (uVar1 < *param_2) {
    uVar3 = 0x95;
  }
  else {
    param_3 = 0x69547354;
    puVar2 = (ushort *)(ulonglong)uVar1;
    _Globals = CONCAT22(uVar1,*param_2);
    DAT_1c0006168 = (void *)ExAllocatePoolWithTag(0x200);
    if (DAT_1c0006168 != (void *)0x0) {
      memcpy(DAT_1c0006168,*(void **)(param_2 + 4),(ulonglong)*param_2);
      *(undefined2 *)((longlong)DAT_1c0006168 + (ulonglong)(_Globals >> 0x11) * 2 + -2) = 0;
      _DAT_1c0006178 = 1;
      _DAT_1c0006180 = 0;
      _DAT_1c0006188 = 0;
      KeInitializeEvent(&DAT_1c0006190,1,0);
      return unaff_EBX;
    }
    uVar3 = 0x9a;
  }
  DAT_1c0006168 = (void *)0x0;
  _Globals = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),puVar2,param_3,0x2e,
                       &WPP_0074a5b33ba33355f813c7f04a70aceb_Traceguids,in_stack_ffffffffffffffe0,
                       uVar3);
  }
  return unaff_EBX;
}



===== DriverEntry @ 1c000c1c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,wchar_t *param_2,undefined8 param_3)

{
  int iVar1;
  int extraout_EAX;
  undefined2 *puVar2;
  wchar_t *pwVar3;
  undefined8 *puVar4;
  undefined *in_stack_ffffffffffffffb8;
  undefined1 uVar5;
  undefined7 in_stack_ffffffffffffffc1;
  undefined8 local_28;
  undefined8 uStack_20;
  
  _DAT_1c0006128 = 1;
  _WPP_MAIN_CB = 0;
  local_28 = 0;
  uStack_20 = 0;
  DAT_1c0006110 = 0;
  DAT_1c0006108 = &WPP_ThisDir_CTLGUID_CtlGuid;
  _DAT_1c0006120 = 0;
  _DAT_1c0006140 = 0;
  _DAT_1c0006148 = 0;
  WppLoadTracingSupport();
  _DAT_1c0006120 = 0;
  pwVar3 = param_2;
  WppInitKm(param_1,param_2);
  DAT_1c0006201 = 1;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_ffffffffffffffb8 = &WPP_a22c8264ce0a30878b50f65ec3447f16_Traceguids;
    WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pwVar3,param_3,10,
                      &WPP_a22c8264ce0a30878b50f65ec3447f16_Traceguids);
  }
  memset(&Globals,0,0xb8);
  KeInitializeGuardedMutex(&DAT_1c00061b0);
  DAT_1c00061f0 = &DAT_1c00061e8;
  DAT_1c00061e8 = &DAT_1c00061e8;
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(code **)(param_1 + 0x68) = TiUnload;
  *(code **)(param_1 + 0x70) = TiCreate;
  *(code **)(param_1 + 0x80) = TiClose;
  *(code **)(param_1 + 0xe8) = PtInternalDeviceControl;
  *(code **)(param_1 + 0xe0) = TiDeviceControl;
  *(code **)(param_1 + 0x148) = PtPnP;
  *(code **)(param_1 + 0x120) = PtPower;
  *(code **)(param_1 + 0x128) = PtSystemControl;
  *(code **)(*(longlong *)(param_1 + 0x30) + 8) = PtAddDevice;
  RtlInitUnicodeString(&local_28);
  puVar4 = &local_28;
  uVar5 = 0;
  pwVar3 = (wchar_t *)0x0;
  iVar1 = IoCreateDevice(param_1,0,puVar4,0x38,
                         (ulonglong)in_stack_ffffffffffffffb8 & 0xffffffff00000000,0,&DAT_1c00061f8)
  ;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pwVar3,puVar4,0xb,
                       &WPP_a22c8264ce0a30878b50f65ec3447f16_Traceguids,
                       CONCAT71(in_stack_ffffffffffffffc1,uVar5),(char)iVar1);
  }
  if (-1 < iVar1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pwVar3,puVar4,0xc,
                        &WPP_a22c8264ce0a30878b50f65ec3447f16_Traceguids);
    }
    RtlInitUnicodeString(&DAT_1c0006208,L"\\DosDevices\\TermInptCDO");
    puVar2 = &DAT_1c0006208;
    iVar1 = IoCreateSymbolicLink(&DAT_1c0006208,&local_28);
    if (iVar1 < 0) {
      pwVar3 = L"";
      RtlInitUnicodeString(&DAT_1c0006208);
    }
    else {
      PtEntry(puVar2,(ushort *)param_2,puVar4);
      pwVar3 = param_2;
      iVar1 = extraout_EAX;
      if (-1 < extraout_EAX) {
        DAT_1c0006200 = 1;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          DAT_1c0006200 = 1;
          return extraout_EAX;
        }
        WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),param_2,puVar4,0xd,
                           &WPP_a22c8264ce0a30878b50f65ec3447f16_Traceguids,
                           CONCAT71(in_stack_ffffffffffffffc1,uVar5),(char)extraout_EAX);
        return extraout_EAX;
      }
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_sd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),pwVar3,puVar4,0xe,
                       &WPP_a22c8264ce0a30878b50f65ec3447f16_Traceguids,
                       CONCAT71(in_stack_ffffffffffffffc1,uVar5),(char)iVar1);
  }
  TiUnload(param_1,pwVar3,puVar4);
  return iVar1;
}


