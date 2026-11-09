
===== QueryUSBStackAndDeviceCapabilities @ 140001008 =====

void QueryUSBStackAndDeviceCapabilities(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  short local_res8 [4];
  undefined4 local_res10 [2];
  
  lVar2 = *(longlong *)(param_1 + 0x548);
  if (lVar2 == 0) {
    return;
  }
  if (*(uint *)(lVar2 + 0xd8) < 0x602) {
    if (*(uint *)(lVar2 + 0xd8) < 0x600) {
      return;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x558) = 1;
    iVar1 = USBD_QueryUsbCapability
                      (lVar2,(undefined8 *)&GUID_USB_CAPABILITY_FUNCTION_SUSPEND,0,0,
                       (undefined4 *)0x0);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),4,1,0x4e,
                          &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)iVar1);
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x55a) = 1;
    }
    iVar1 = USBD_QueryUsbCapability
                      (*(longlong *)(param_1 + 0x548),
                       (undefined8 *)&GUID_USB_CAPABILITY_MICROSOFT_MAUSBHOST,0,0,(undefined4 *)0x0)
    ;
    if (-1 < iVar1) {
      *(undefined1 *)(param_1 + 0x55c) = 1;
    }
    iVar1 = USBD_QueryUsbCapability
                      (*(longlong *)(param_1 + 0x548),
                       (undefined8 *)&GUID_USB_CAPABILITY_DEVICE_CONNECTION_SUPER_SPEED_COMPATIBLE,0
                       ,0,(undefined4 *)0x0);
    lVar2 = *(longlong *)(param_1 + 0x548);
    if (-1 < iVar1) {
      local_res8[0] = 0;
      local_res10[0] = 0;
      iVar1 = USBD_QueryUsbCapability
                        (lVar2,(undefined8 *)&GUID_USB_CAPABILITY_STATIC_STREAMS,2,
                         (longlong)local_res8,local_res10);
      if ((-1 < iVar1) && (local_res8[0] != 0)) {
        return;
      }
      goto LAB_1400010d3;
    }
  }
  iVar1 = USBD_QueryUsbCapability
                    (lVar2,(undefined8 *)
                           &GUID_USB_CAPABILITY_DEVICE_CONNECTION_HIGH_SPEED_COMPATIBLE,0,0,
                     (undefined4 *)0x0);
  if (-1 < iVar1) {
    return;
  }
LAB_1400010d3:
  *(undefined1 *)(param_1 + 0x55b) = 1;
  return;
}



===== USBD_QueryUsbCapability @ 140001184 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int USBD_QueryUsbCapability
              (longlong param_1,undefined8 *param_2,int param_3,longlong param_4,undefined4 *param_5
              )

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  char *pcVar4;
  undefined1 auStack_88 [48];
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  int local_38;
  undefined4 local_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_88;
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  cVar1 = KeGetCurrentIrql();
  if (cVar1 == '\0') {
    if (param_1 == 0) {
      if (g_EnableDbgPrints == '\0') {
        return -0x3ffffff3;
      }
      pcVar4 = "USBDHandle cant be NULL\n";
    }
    else {
      if (param_2 != (undefined8 *)0x0) {
        if (param_3 == 0) {
          if (param_4 != 0) {
            if (g_EnableDbgPrints == '\0') {
              return -0x3ffffff3;
            }
            pcVar4 = "OutputBuffer must be NULL if OutputBufferLength is zero\n";
            goto LAB_1400012aa;
          }
        }
        else if (param_4 == 0) {
          if (g_EnableDbgPrints == '\0') {
            return -0x3ffffff3;
          }
          pcVar4 = "OutputBuffer cant be NULL if OutputBufferLength is not zero\n";
          goto LAB_1400012aa;
        }
        if (*(int *)(param_1 + 0xd8) == -1) {
          if (g_EnableDbgPrints == '\0') {
            return -0x3ffffffe;
          }
          pcVar4 = 
          "Could not exchange an interface with the Underlying USB core stack, querrying for capability is not possible\n"
          ;
LAB_140001326:
          DbgPrintEx(0x4d,0,pcVar4);
          return -0x3ffffffe;
        }
        if (*(int *)(param_1 + 0xd8) != 0x600) {
          local_48 = *param_2;
          uStack_40 = param_2[1];
          local_50 = *(undefined8 *)(param_1 + 0x30);
          local_58 = 0x280001;
          local_34 = 0;
          local_38 = param_3;
          iVar2 = USBDInternal_BuildandSendIoctlSynchronously
                            (*(undefined8 *)(param_1 + 0x38),*(longlong *)(param_1 + 0xd0),param_4,
                             &local_58);
          if (iVar2 < 0) {
            return iVar2;
          }
          if (param_5 == (undefined4 *)0x0) {
            return iVar2;
          }
          *param_5 = local_34;
          return iVar2;
        }
        lVar3 = RtlCompareMemory(param_2,&
                                         GUID_USB_CAPABILITY_DEVICE_CONNECTION_HIGH_SPEED_COMPATIBLE
                                 ,0x10);
        if (lVar3 == 0x10) {
          if (param_4 == 0) {
            if (*(char *)(param_1 + 0xe0) != '\0') {
              return 0;
            }
            if (g_EnableDbgPrints != '\0') {
              DbgPrintEx(0x4d,3,"Device is not High Speed\n");
            }
            return -0x3fffff45;
          }
          if (g_EnableDbgPrints == '\0') {
            return -0x3ffffff3;
          }
          pcVar4 = 
          "OutputBuffer must be NULL for GUID_USB_CAPABILITY_DEVICE_CONNECTION_HIGH_SPEED_COMPATIBLE\n"
          ;
        }
        else {
          lVar3 = RtlCompareMemory(param_2,&GUID_USB_CAPABILITY_SELECTIVE_SUSPEND,0x10);
          if (lVar3 != 0x10) {
            if (g_EnableDbgPrints == '\0') {
              return -0x3ffffffe;
            }
            pcVar4 = "QueryUsbCapability not supported/implemented by core stack\n";
            goto LAB_140001326;
          }
          if (param_4 == 0) {
            return 0;
          }
          if (g_EnableDbgPrints == '\0') {
            return -0x3ffffff3;
          }
          pcVar4 = "OutputBuffer must be NULL for GUID_USB_CAPABILITY_SELECTIVE_SUSPEND\n";
        }
        DbgPrintEx(0x4d,0,pcVar4);
        return -0x3ffffff3;
      }
      if (g_EnableDbgPrints == '\0') {
        return -0x3ffffff3;
      }
      pcVar4 = "CapabilityType cant be NULL\n";
    }
  }
  else {
    if (g_EnableDbgPrints == '\0') {
      return -0x3ffffff3;
    }
    pcVar4 = "PASSIVE_LEVEL required\n";
  }
LAB_1400012aa:
  DbgPrintEx(0x4d,0,pcVar4);
  return -0x3ffffff3;
}



===== USBDInternal_BuildandSendIoctlSynchronously @ 140001434 =====

int USBDInternal_BuildandSendIoctlSynchronously
              (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

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
  KeInitializeEvent(&local_28,0,0);
  lVar3 = IoAllocateIrp(*(undefined1 *)(param_2 + 0x4c),0);
  if (lVar3 == 0) {
    if (g_EnableDbgPrints != '\0') {
      DbgPrintEx(0x4d,0,"Failed to allocate Irp for Target Device Object 0x%p\n",param_2);
    }
    iVar2 = -0x3fffff66;
  }
  else {
    *(undefined8 *)(lVar3 + 0x18) = param_3;
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(undefined8 *)(lVar1 + -0x40) = param_4;
    *(undefined1 *)(lVar1 + -0x48) = 0xf;
    *(undefined4 *)(lVar1 + -0x30) = 0x49104b;
    iVar2 = IoSetCompletionRoutineEx(param_1,lVar3,USBD_SyncCompletionRoutine,&local_28,1,1,1);
    if (iVar2 < 0) {
      lVar1 = *(longlong *)(lVar3 + 0xb8);
      *(code **)(lVar1 + -0x10) = USBD_SyncCompletionRoutine;
      *(undefined8 **)(lVar1 + -8) = &local_28;
      *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    }
    iVar2 = IofCallDriver(param_2,lVar3);
    if (iVar2 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      iVar2 = *(int *)(lVar3 + 0x30);
    }
    IoFreeIrp(lVar3);
  }
  return iVar2;
}



===== PrepareParentFDOForRemove @ 1400015a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PrepareParentFDOForRemove(longlong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  longlong lVar5;
  undefined1 uVar6;
  longlong lVar7;
  
  iVar2 = *(int *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0xc) = 7;
  lVar7 = param_2;
  KeCancelTimer(param_1 + 0x3e0);
  TerminateIdleTimer(param_1);
  CancelFdoIdleIrp(param_1,CONCAT71((int7)((ulonglong)lVar7 >> 8),1));
  CancelParentWaitWake(param_1);
  USBC_UnregisterWmi(param_1);
  if (*(char *)(param_1 + 0x559) != '\0') {
    UnregisterCompositeDevice(param_1);
  }
  if ((*(uint *)(param_1 + 0x4d4) & 2) != 0) {
    *(uint *)(param_1 + 0x4d4) = *(uint *)(param_1 + 0x4d4) & 0xfffffffd;
    (**(code **)(param_1 + 0x4f8))(*(undefined8 *)(param_1 + 0x4e8));
  }
  if (1 < iVar2 - 7U) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),4,2,0x23,
                       &WPP_93f6b87810f63f9db566694056813e32_Traceguids);
    }
    IoReleaseRemoveLockAndWaitEx(param_1 + 200,param_2,0x20);
    UsbcReleaseRemoveLock(param_1,param_2);
  }
  lVar7 = param_1 + 0x248;
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar7);
  if (*(undefined4 **)(param_1 + 0x80) != (undefined4 *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),4,2,0x24,
                        &WPP_93f6b87810f63f9db566694056813e32_Traceguids,
                        (char)**(undefined4 **)(param_1 + 0x80));
    }
    while( true ) {
      iVar2 = **(int **)(param_1 + 0x80);
      if (iVar2 == 0) break;
      **(int **)(param_1 + 0x80) = iVar2 + -1;
      puVar4 = *(uint **)(param_1 + 0x80);
      uVar3 = *puVar4;
      lVar5 = *(longlong *)(puVar4 + (ulonglong)uVar3 * 2 + 2);
      (puVar4 + (ulonglong)uVar3 * 2 + 2)[0] = 0;
      (puVar4 + (ulonglong)uVar3 * 2 + 2)[1] = 0;
      lVar5 = *(longlong *)(lVar5 + 0x40);
      KeReleaseSpinLock(lVar7,CONCAT71((int7)((ulonglong)puVar4 >> 8),uVar6));
      FreeFunctionPDOResources(lVar5 + 8);
      uVar6 = KeAcquireSpinLockRaiseToDpc(lVar7);
    }
  }
  KeReleaseSpinLock(lVar7,uVar6);
  lVar7 = *(longlong *)(param_1 + 0x548);
  if (lVar7 != 0) {
    *(undefined1 *)(lVar7 + 0xe1) = 1;
    LOCK();
    piVar1 = (int *)(lVar7 + 0xdc);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 < 2) {
      if (*(char *)(lVar7 + 0xe1) == '\0') {
        if (g_EnableDbgPrints != '\0') {
          DbgPrintEx(0x4d,0,"UsbdHandleInfo->PendingDelete should be set here UsbdHandleInfo 0x%p\n"
                     ,lVar7);
        }
      }
      else {
        if (*(code **)(lVar7 + 0x70) != (code *)0x0) {
          (**(code **)(lVar7 + 0x70))(*(undefined8 *)(lVar7 + 0x30));
        }
        ExFreePoolWithTag(lVar7,*(undefined4 *)(lVar7 + 0x40));
      }
    }
    *(undefined8 *)(param_1 + 0x548) = 0;
  }
  return;
}



===== CancelParentWaitWake @ 140001818 =====

void CancelParentWaitWake(longlong param_1)

{
  int iVar1;
  
  LOCK();
  iVar1 = *(int *)(param_1 + 0x188);
  *(int *)(param_1 + 0x188) = 1;
  UNLOCK();
  CancelParentWaitWakeArg(param_1,iVar1);
  return;
}



===== WPP_RECORDER_SF_d @ 140001838 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_d(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar1 * 0x50))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar1 * 0x50),0x2b,param_5,param_4,
               &param_6,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,4,0);
  return;
}



===== USBD_AssignUrbToIoStackLocation @ 140001938 =====

void USBD_AssignUrbToIoStackLocation(longlong param_1,longlong param_2,undefined8 param_3)

{
  if (*(int *)(param_1 + 0xd8) - 0x602U < 0xfffff9fd) {
    *(undefined8 *)(param_2 + 0x30) = param_3;
  }
  *(undefined8 *)(param_2 + 8) = param_3;
  return;
}



===== SendSetFeatureControlRequestForFunctionSuspend @ 140001960 =====

void SendSetFeatureControlRequestForFunctionSuspend
               (longlong param_1,longlong param_2,longlong param_3,int param_4)

{
  byte *pbVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  
  uVar4 = UsbcAcquireRemoveLock(param_1,0x52465752,SendSetFeatureControlRequestForFunctionSuspend);
  uVar5 = 0;
  if ((int)uVar4 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0x5a,
                     &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids);
    return;
  }
  lVar2 = *(longlong *)(param_2 + 0x180);
  lVar3 = *(longlong *)(lVar2 + 0x48);
  InitializeFunctionSuspendControlRequest(param_1,param_2,param_4);
  SetCompletionRoutine
            (*(undefined8 *)(param_2 + 0x188),*(undefined8 *)(param_1 + 0x20),lVar3,
             CompletionForSuspendControlRequest,param_2);
  if (param_4 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar6 = 0x5b;
LAB_140001a01:
      WPP_RECORDER_SF_qq(*(undefined8 *)(param_2 + 0x188),4,3,uVar6,
                         &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                         (char)*(undefined8 *)(param_2 + 0xe0),(char)lVar3);
    }
  }
  else {
    if (param_4 != 1) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qq(*(undefined8 *)(param_2 + 0x188),4,3,0x5d,
                           &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                           (char)*(undefined8 *)(param_2 + 0xe0),(char)lVar3);
      }
      goto LAB_140001a35;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar6 = 0x5c;
      goto LAB_140001a01;
    }
  }
  uVar5 = 1;
LAB_140001a35:
  *(undefined1 *)(lVar2 + 0x3b) = uVar5;
  *(undefined1 *)(lVar2 + 0x3a) = 1;
  *(longlong *)(lVar2 + 0x60) = param_3;
  pbVar1 = (byte *)(*(longlong *)(param_3 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
  IofCallDriver(*(undefined8 *)(param_1 + 0x28),lVar3);
  return;
}



===== InitializeFunctionSuspendControlRequest @ 140001b2c =====

void InitializeFunctionSuspendControlRequest(longlong param_1,longlong param_2,int param_3)

{
  undefined4 *puVar1;
  longlong lVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  
  uVar4 = 1;
  puVar1 = *(undefined4 **)(*(longlong *)(param_2 + 0x180) + 0x40);
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0x180) + 0x48);
  *(undefined1 *)((longlong)puVar1 + 0x81) = 3;
  *(undefined2 *)((longlong)puVar1 + 0x82) = 0;
  *(byte *)(puVar1 + 0x20) = *(byte *)(puVar1 + 0x20) & 0x1c | 1;
  *(undefined1 *)(puVar1 + 0x21) = *(undefined1 *)(param_2 + 8);
  if (param_3 != 0) {
    uVar4 = 0;
    if (param_3 == 1) {
      uVar4 = 3;
    }
  }
  *(undefined1 *)((longlong)puVar1 + 0x85) = uVar4;
  *(undefined2 *)((longlong)puVar1 + 0x86) = 0;
  *puVar1 = 0x320088;
  *(undefined8 *)(puVar1 + 8) = 10;
  *(undefined8 *)(puVar1 + 10) = 0;
  *(undefined8 *)(puVar1 + 0xc) = 0;
  puVar1[0xe] = 5000;
  lVar2 = *(longlong *)(lVar2 + 0xb8);
  puVar3 = (undefined1 *)(lVar2 + -0x48);
  *(undefined4 *)(lVar2 + -0x30) = 0x220003;
  *puVar3 = 0xf;
  USBD_AssignUrbToIoStackLocation(*(longlong *)(param_1 + 0x548),(longlong)puVar3,puVar1);
  return;
}



===== CallbackFdoDeviceSetDx @ 140001c00 =====

void CallbackFdoDeviceSetDx
               (longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
               undefined4 *param_5)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(lVar1 + 0x568),4,3,0x25,
                      &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                      (char)*(undefined8 *)(lVar1 + 0x28));
  }
  PoStartNextPowerIrp(param_4);
  *(undefined4 *)(param_4 + 0x30) = *param_5;
  IofCompleteRequest(param_4,0);
  UsbcReleaseRemoveLock(lVar1 + 8,param_4);
  IoReleaseRemoveLockEx(lVar1 + 0xd0,param_4,0x20);
  return;
}



===== ProcessWakeNotificationWorker @ 140001cc0 =====

void ProcessWakeNotificationWorker(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  
  lVar1 = *(longlong *)(param_2 + 0xe8);
  lVar2 = *(longlong *)(param_2 + 0x180);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    param_3 = 3;
    WPP_RECORDER_SF_q(*(undefined8 *)(param_2 + 0x188),5,3,0x4b,
                      &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                      (char)*(undefined8 *)(param_2 + 0xe0));
  }
  uVar4 = KeAcquireSpinLockRaiseToDpc(lVar2);
  lVar3 = *(longlong *)(lVar2 + 0x30);
  *(undefined1 *)(lVar2 + 0x38) = 0;
  if (lVar3 == 0) {
    KeReleaseSpinLock(lVar2,uVar4);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      param_3 = 3;
      WPP_RECORDER_SF_q(*(undefined8 *)(param_2 + 0x188),4,3,0x4d,
                        &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                        (char)*(undefined8 *)(param_2 + 0xe0));
    }
    CompletePdoWaitWakeIrp(param_2,*(undefined4 *)(*(longlong *)(lVar2 + 0x28) + 0x30),param_3);
    CompleteFunctionIdleIrp(param_2,0);
    SetPdoIdle(lVar1,param_2,2,0,'\x01');
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(param_2 + 0x188),4,3,0x4c,
                         &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                         (char)*(undefined8 *)(param_2 + 0xe0),(char)lVar3);
    }
    *(undefined8 *)(lVar2 + 0x30) = 0;
    KeReleaseSpinLock(lVar2,uVar4);
    IofCompleteRequest(lVar3,0);
    UsbcReleaseRemoveLock(lVar1,lVar3);
    IoReleaseRemoveLockEx(lVar1 + 200,lVar3,0x20);
  }
  UsbcReleaseRemoveLock(lVar1,0x140010310);
  IoReleaseRemoveLockEx(lVar1 + 200,SendRemoteWakeNotificationIrp,0x20);
  return;
}



===== SubmitParentWaitWakeIrp @ 140001ec8 =====

void SubmitParentWaitWakeIrp(longlong param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0xb4);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x560),4,3,0x1c,
                      &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                      (char)*(undefined8 *)(param_1 + 0x20));
  }
  PoRequestPowerIrp(*(undefined8 *)(param_1 + 0x28),0,uVar1,CallbackFdoWaitWake,param_1,0);
  return;
}



===== PoCallbackIdleSetDx @ 140001f60 =====

void PoCallbackIdleSetDx(longlong param_1,undefined8 param_2,undefined1 param_3,undefined8 param_4)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_L(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x568),4,3,0x24,
                      &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,param_3);
  }
  KeSetEvent(param_4,0,0);
  return;
}



===== PrepareRemoteWakeNotificationIrp @ 140001fcc =====

ulonglong PrepareRemoteWakeNotificationIrp(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  uVar5 = UsbcAcquireRemoveLock(param_1,0x524e5752,SendRemoteWakeNotificationIrp);
  uVar6 = uVar5 & 0xffffffff;
  if ((int)uVar5 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0x51,
                        &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,(char)uVar5);
    }
  }
  else {
    lVar1 = *(longlong *)(param_2 + 0x180);
    lVar2 = *(longlong *)(lVar1 + 0x28);
    uVar4 = KeAcquireSpinLockRaiseToDpc(lVar1);
    *(undefined1 *)(lVar1 + 0x38) = 1;
    KeReleaseSpinLock(lVar1,uVar4);
    IoReuseIrp(lVar2,0);
    *(undefined4 *)(lVar1 + 0x10) = 0x180000;
    *(undefined8 *)(lVar1 + 0x18) = *(undefined8 *)(param_2 + 0x178);
    *(undefined4 *)(lVar1 + 0x20) = *(undefined4 *)(param_2 + 8);
    lVar3 = *(longlong *)(lVar2 + 0xb8);
    *(undefined1 *)(lVar3 + -0x48) = 0xf;
    *(undefined4 *)(lVar3 + -0x30) = 0x49000b;
    *(undefined4 **)(lVar3 + -0x40) = (undefined4 *)(lVar1 + 0x10);
    SetCompletionRoutine
              (*(undefined8 *)(param_2 + 0x188),*(undefined8 *)(param_1 + 0x20),lVar2,
               CompletionRemoteWakeNotication,param_2);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(param_2 + 0x188),4,3,0x52,
                         &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                         (char)*(undefined8 *)(param_2 + 0xe0),(char)lVar2);
    }
    uVar6 = 0;
  }
  return uVar6;
}



===== CancelRemoteWakeNotificationIrp @ 14000213c =====

void CancelRemoteWakeNotificationIrp(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x180);
  uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1);
  if (*(char *)(lVar1 + 0x38) == '\0') {
    KeReleaseSpinLock(lVar1,uVar2);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqd(*(undefined8 *)(param_1 + 0x188),4,3,0x4a,
                          &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,(char)param_2,
                          (char)*(undefined8 *)(param_1 + 0xe0),
                          (char)*(undefined4 *)(param_2 + 0x30));
    }
    IofCompleteRequest(param_2,0);
    UsbcReleaseRemoveLock(*(longlong *)(param_1 + 0xe8),param_2);
    IoReleaseRemoveLockEx(*(longlong *)(param_1 + 0xe8) + 200,param_2,0x20);
  }
  else {
    *(longlong *)(lVar1 + 0x30) = param_2;
    KeReleaseSpinLock();
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(param_1 + 0x188),4,3,0x49,
                         &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                         (char)*(undefined8 *)(param_1 + 0xe0),(char)*(undefined8 *)(lVar1 + 0x28));
    }
    IoCancelIrp(*(undefined8 *)(lVar1 + 0x28));
  }
  return;
}



===== WPP_RECORDER_SF_L @ 140002294 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_L(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar1 * 0x50))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar1 * 0x50),0x2b,param_5,param_4,
               &param_6,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,4,0);
  return;
}



===== WPP_RECORDER_SF_qL @ 140002390 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qL(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar1 * 0x50))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar1 * 0x50),0x2b,param_5,param_4,
               &param_6,8,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,4,0);
  return;
}



===== LockSendSetFeatureControlRequestForFunctionSuspend @ 1400024c4 =====

void LockSendSetFeatureControlRequestForFunctionSuspend
               (longlong param_1,longlong param_2,longlong param_3,int param_4)

{
  longlong lVar1;
  code *pcVar2;
  undefined1 uVar3;
  int iVar4;
  longlong *plVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong *plVar8;
  undefined1 *puVar9;
  undefined8 local_res10;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  undefined8 *local_38;
  
  local_res10 = 0;
  lVar1 = param_2 + 0x1c0;
  uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
  local_38 = &local_res10;
  iVar4 = KeWaitForSingleObject(param_2 + 0x1a8,0,0,0);
  if (iVar4 == 0) {
    KeReleaseSpinLock(lVar1,uVar3);
    SendSetFeatureControlRequestForFunctionSuspend(param_1,param_2,param_3,param_4);
    KeSetEvent(param_2 + 0x1a8,0,0);
  }
  else {
    uVar6 = 0x100;
    if (ExDefaultNonPagedPoolType == 0x200) {
      uVar6 = 0x40;
    }
    plVar5 = (longlong *)ExAllocatePool2(uVar6,0x20,0x43627355);
    puVar9 = auStack_58;
    if (plVar5 == (longlong *)0x0) {
      PoStartNextPowerIrp(param_3);
      *(undefined4 *)(param_3 + 0x30) = 0;
      KeReleaseSpinLock(lVar1,uVar3);
      IofCompleteRequest(param_3,0);
      uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
      UsbcReleaseRemoveLock(param_1,param_3);
      IoReleaseRemoveLockEx(param_1 + 200,param_3,0x20);
      puVar9 = auStack_58;
    }
    else {
      *(int *)(plVar5 + 1) = param_4;
      lVar7 = param_2 + 0x1c8;
      *plVar5 = param_3;
      plVar5 = plVar5 + 2;
      plVar8 = *(longlong **)(param_2 + 0x1d0);
      if (*plVar8 != lVar7) {
        lVar7 = 3;
        pcVar2 = (code *)swi(0x29);
        plVar5 = (longlong *)(*pcVar2)();
        puVar9 = auStack_50;
      }
      *plVar5 = lVar7;
      plVar5[1] = (longlong)plVar8;
      *plVar8 = (longlong)plVar5;
      *(longlong **)(lVar7 + 8) = plVar5;
    }
    *(undefined8 *)(puVar9 + -8) = 0x14000264d;
    KeReleaseSpinLock(lVar1,uVar3);
  }
  return;
}



===== WPP_RECORDER_SF_qdd @ 140002670 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qdd(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar1 * 0x50))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar1 * 0x50),0x2b,param_5,param_4,
               &param_6,8,&param_7,4,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,4,&param_8,4,0);
  return;
}



===== CancelParentWaitWakeArg @ 1400027c0 =====

void CancelParentWaitWakeArg(longlong param_1,int param_2)

{
  int iVar1;
  longlong lVar2;
  
  if (param_2 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x560),4,3,0x20,
                        &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                        (char)*(undefined8 *)(param_1 + 0x20));
    }
  }
  else {
    LOCK();
    lVar2 = *(longlong *)(param_1 + 0x178);
    *(longlong *)(param_1 + 0x178) = 0;
    UNLOCK();
    if (lVar2 != 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qq(*(undefined8 *)(param_1 + 0x560),4,3,0x1f,
                           &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                           (char)*(undefined8 *)(param_1 + 0x20),(char)lVar2);
      }
      IoCancelIrp(lVar2);
      LOCK();
      iVar1 = *(int *)(param_1 + 0x18c);
      *(int *)(param_1 + 0x18c) = 1;
      UNLOCK();
      if (iVar1 != 0) {
        IofCompleteRequest(lVar2,0);
      }
    }
  }
  return;
}



===== CompletePdoWaitWakeIrp @ 1400028a8 =====

void CompletePdoWaitWakeIrp(longlong param_1,undefined4 param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 in_stack_ffffffffffffffc8;
  
  lVar1 = *(longlong *)(param_1 + 0xe8);
  lVar3 = param_1;
  lVar2 = IoCsqRemoveNextIrp(param_1 + 0x20);
  if (lVar2 != 0) {
    *(undefined4 *)(lVar2 + 0x30) = param_2;
    if (*(char *)(lVar1 + 0x55a) == '\0') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqqd
                  (*(undefined8 *)(lVar1 + 0x560),lVar3,param_3,0x15,in_stack_ffffffffffffffc8,
                   (char)*(undefined8 *)(lVar1 + 0x20),(char)lVar2,
                   (char)*(undefined8 *)(param_1 + 0xe0),(char)param_2);
      }
      IofCompleteRequest(lVar2,0);
      UsbcReleaseRemoveLock(lVar1,lVar2);
      IoReleaseRemoveLockEx(lVar1 + 200,lVar2,0x20);
    }
    else {
      CancelRemoteWakeNotificationIrp(param_1,lVar2);
    }
    CheckParentWaitWake(*(longlong *)(param_1 + 0xe8));
  }
  return;
}



===== WaitWakeCancelComplete @ 1400029b0 =====

void WaitWakeCancelComplete(longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 200);
  CheckParentWaitWake(lVar1);
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  if (*(char *)(lVar1 + 0x55a) == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(param_1 + 0x168),4,3,10,
                         &WPP_c22e0bd291983066d7104eda50c0b1f9_Traceguids,
                         (char)*(undefined8 *)(param_1 + 0xc0),(char)param_2);
    }
    IofCompleteRequest(param_2,0);
    UsbcReleaseRemoveLock(lVar1,param_2);
    IoReleaseRemoveLockEx(lVar1 + 200,param_2,0x20);
  }
  else {
    CancelRemoteWakeNotificationIrp(param_1 + -0x20,param_2);
  }
  return;
}



===== CallbackFdoWaitWake @ 140002a90 =====

void CallbackFdoWaitWake(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
                        uint *param_5)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  longlong ****pppplVar5;
  
  uVar2 = *param_5;
  if ((-1 < (int)uVar2) && (*(int *)(param_4 + 4) != 1)) {
    param_3 = 0;
    uVar2 = FdoSendSetPowerRequest(1,(undefined *)0x0,0,param_4);
    if ((uVar2 == 0x103) || (uVar2 == 0x80000011)) {
      uVar1 = KeAcquireSpinLockRaiseToDpc(param_4 + 0x158);
      iVar3 = KeReadStateEvent(param_4 + 0x138);
      if (iVar3 == 0) {
        *(uint *)(param_4 + 0x4d4) = *(uint *)(param_4 + 0x4d4) | 8;
      }
      KeReleaseSpinLock(param_4 + 0x158,uVar1);
      if (iVar3 == 0) {
        return;
      }
      param_3 = 0;
      uVar4 = AllocateWorker(param_4,WaitWakeFinishCompletionWorker,0);
      uVar2 = (uint)uVar4;
      if (-1 < (int)uVar2) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return;
        }
        WPP_RECORDER_SF_q(*(undefined8 *)(param_4 + 0x560),4,3,0x1a,
                          &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                          (char)*(undefined8 *)(param_4 + 0x20));
        return;
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      param_3 = 8;
      WPP_RECORDER_SF_q(*(undefined8 *)(param_4 + 0x560),2,8,0x1b,
                        &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                        (char)*(undefined8 *)(param_4 + 0x20));
    }
  }
  if (*(char *)(param_4 + 0x55a) == '\0') {
    pppplVar5 = (longlong ****)(ulonglong)uVar2;
  }
  else {
    if (*(int *)(param_4 + 0x240) != 2) {
      FinishWaitWakeCompletionForFunctionSuspend(param_4);
      return;
    }
    pppplVar5 = (longlong ****)0xc0000120;
  }
  CompleteAllPdoWaitWakeIrps(param_4,pppplVar5,param_3);
  return;
}



===== ParentIdleNotificationCallback @ 140002c30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ParentIdleNotificationCallback(longlong param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  bool bVar5;
  undefined1 uVar6;
  int iVar7;
  int iVar8;
  undefined2 uVar9;
  uint uVar10;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  bVar5 = true;
  puVar1 = (undefined8 *)(param_1 + 0x560);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*puVar1,4,7,0x25,&WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,
                      (char)*(undefined8 *)(param_1 + 0x20));
  }
  lVar2 = param_1 + 0x2b8;
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar2);
  if ((*(int *)(param_1 + 0x358) - 1U & 0xfffffffd) != 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(*puVar1,4,7,0x26,&WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,
                        (char)*(int *)(param_1 + 0x358));
    }
LAB_140002e6d:
    KeReleaseSpinLock(lVar2,uVar6);
    return;
  }
  if (*(int *)(param_1 + 0x2b0) != 1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*puVar1,4,7,0x27,&WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids);
    }
    goto LAB_140002e6d;
  }
  ChangeIdleState(param_1,4,'\0');
  for (uVar10 = 0; uVar10 < **(uint **)(param_1 + 0x80); uVar10 = uVar10 + 1) {
    lVar4 = *(longlong *)
             (*(longlong *)(*(uint **)(param_1 + 0x80) + (ulonglong)uVar10 * 2 + 2) + 0x40);
    if ((*(uint *)(lVar4 + 0x130) & 0x17) == 0) {
      bVar5 = false;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x560),4,7,0x28,
                          &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,
                          (char)*(undefined8 *)(lVar4 + 0xe8));
      }
      goto LAB_140002d62;
    }
    if (*(longlong *)(lVar4 + 0x128) == 0) {
      if ((*(char *)(param_1 + 0x55a) != '\0') &&
         (*(char *)(*(longlong *)(lVar4 + 0x188) + 0x3b) == '\0')) {
        KeReleaseSpinLock(lVar2,uVar6);
        LockSyncSendSetFeatureControlRequestForFunctionSuspend(param_1,lVar4 + 8,0);
        uVar6 = KeAcquireSpinLockRaiseToDpc(lVar2);
        if (*(int *)(param_1 + 0x2b0) != 4) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar9 = 0x2d;
            goto LAB_1400030db;
          }
          goto LAB_140003057;
        }
      }
    }
    else {
      lVar3 = lVar4 + 0xd0;
      puVar1 = *(undefined8 **)(*(longlong *)(*(longlong *)(lVar4 + 0x128) + 0xb8) + 0x20);
      KeClearEvent(lVar3);
      KeReleaseSpinLock(lVar2,uVar6);
      if (*(char *)(param_1 + 0x55a) == '\0') {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qq(*(undefined8 *)(param_1 + 0x560),4,8,0x29,
                             &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,(char)puVar1,
                             (char)*puVar1);
        }
        (*(code *)*puVar1)(puVar1[1]);
      }
      uVar6 = KeAcquireSpinLockRaiseToDpc(lVar2);
      if (((*(char *)(lVar4 + 0x135) != '\0') && (*(longlong *)(lVar4 + 0x128) != 0)) &&
         (*(char *)(*(longlong *)(lVar4 + 0x128) + 0x44) != '\0')) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x560),4,7,0x2a,
                            &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,(char)(lVar4 + 8));
        }
        KeSetEvent(lVar3,0,0);
        bVar5 = false;
        goto LAB_140002d62;
      }
      KeSetEvent(lVar3,0);
      if (*(int *)(param_1 + 0x2b0) != 4) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar9 = 0x2b;
LAB_1400030db:
          WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),4,7,uVar9,
                           &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids);
        }
LAB_140003057:
        bVar5 = false;
        goto LAB_140002d62;
      }
    }
  }
  ChangeIdleState(param_1,5,'\0');
LAB_140002d62:
  KeReleaseSpinLock(lVar2);
  if (bVar5) {
    KeInitializeEvent(&local_48,0,0);
    if (*(char *)(param_1 + 0x1ba) == '\x01') {
      iVar7 = DeriveParentIdlePowerStateFromChildrenIdleState(param_1);
    }
    else {
      iVar7 = 4 - (uint)(*(char *)(param_1 + 0x1b8) != '\0');
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(*(undefined8 *)(param_1 + 0x560),4,7,0x2e,
                        &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,(char)iVar7);
    }
    iVar8 = FdoSendSetPowerRequest(iVar7,PoCallbackIdleSetDx,&local_48,param_1);
    if (iVar8 == 0x103) {
      WaitForSignal(&local_48,"parentDxEvent (waiting for device to enter Dx)",
                    *(undefined8 *)(param_1 + 0x560));
      ChangeIdleState(param_1,1,'\x01');
      return;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qL(*(undefined8 *)(param_1 + 0x560),2,8,0x2f,
                         &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,
                         (char)*(undefined8 *)(param_1 + 0x20),(char)iVar7);
    }
    ChangeIdleState(param_1,1,'\x01');
  }
  else {
    if (*(char *)(param_1 + 0x55a) != '\0') goto LAB_140002e54;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),4,7,0x30,
                       &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids);
    }
  }
  CompleteAllFunctionIdleIrps(param_1,0xc0000120);
LAB_140002e54:
  CancelFdoIdleIrp(param_1,0);
  return;
}



===== DeriveParentIdlePowerStateFromChildrenIdleState @ 140003180 =====

int DeriveParentIdlePowerStateFromChildrenIdleState(longlong param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  
  puVar1 = *(uint **)(param_1 + 0x80);
  uVar5 = 0;
  iVar3 = 4;
  if (*puVar1 != 0) {
    do {
      iVar2 = *(int *)(*(longlong *)(*(longlong *)(puVar1 + uVar5 * 2 + 2) + 0x40) + 0x18);
      if (iVar2 == 1) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x560),4,7,0x45,
                            &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,
                            (char)*(undefined8 *)(param_1 + 0x20));
          puVar1 = *(uint **)(param_1 + 0x80);
        }
        iVar2 = 3;
      }
      if (iVar3 <= iVar2) {
        iVar2 = iVar3;
      }
      iVar3 = iVar2;
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
    } while (uVar4 < *puVar1);
  }
  return iVar3;
}



===== WPP_RECORDER_SF_qq @ 14000322c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qq(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar1 * 0x50))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar1 * 0x50),0x2b,param_5,param_4,
               &param_6,8,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,8,0);
  return;
}



===== DispatchPdoWaitWake @ 140003358 =====

ulonglong DispatchPdoWaitWake(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  undefined1 uVar6;
  
  lVar2 = *(longlong *)(param_1 + 0xe8);
  uVar6 = (undefined1)param_2;
  if (*(int *)(param_1 + 0x14) == 8) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc0000184;
    }
    uVar5 = 0x36;
  }
  else {
    if ((*(char *)(lVar2 + 0x55a) == '\0') ||
       (*(char *)(*(longlong *)(param_1 + 0x180) + 0x39) != '\0')) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qq(*(undefined8 *)(lVar2 + 0x560),4,3,0x38,
                           &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                           (char)*(undefined8 *)(param_1 + 0xe0),uVar6);
      }
      lVar1 = lVar2 + 400;
      uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
      if (*(longlong **)(param_1 + 0x60) != (longlong *)(param_1 + 0x60)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qqd(*(undefined8 *)(lVar2 + 0x560),2,3,0x3a,
                              &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                              (char)*(undefined8 *)(param_1 + 0xe0),uVar6,0x11);
        }
        KeReleaseSpinLock(lVar1,uVar3);
        return 0x80000011;
      }
      KeReleaseSpinLock(lVar1,uVar3);
      if (*(char *)(lVar2 + 0x55a) != '\0') {
        uVar4 = PrepareRemoteWakeNotificationIrp(lVar2,param_1);
        if ((int)uVar4 < 0) {
          return uVar4 & 0xffffffff;
        }
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(lVar2 + 0x560),4,3,0x39,
                         &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids);
      }
      IoCsqInsertIrp(param_1 + 0x20,param_2,0);
      if (*(char *)(lVar2 + 0x55a) != '\0') {
        IofCallDriver(*(undefined8 *)(lVar2 + 0x28),
                      *(undefined8 *)(*(longlong *)(param_1 + 0x180) + 0x28));
      }
      CheckParentWaitWake(lVar2);
      return 0x103;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc0000184;
    }
    uVar5 = 0x37;
  }
  WPP_RECORDER_SF_qqd(*(undefined8 *)(lVar2 + 0x560),2,8,uVar5,
                      &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                      (char)*(undefined8 *)(param_1 + 0xe0),uVar6,0x84);
  return 0xc0000184;
}



===== CompleteAllPdoWaitWakeIrps @ 1400035c8 =====

void CompleteAllPdoWaitWakeIrps(longlong param_1,longlong ****param_2,undefined8 param_3)

{
  longlong *****ppppplVar1;
  longlong ****pppplVar2;
  code *pcVar3;
  bool bVar4;
  undefined1 uVar5;
  longlong lVar6;
  longlong *****ppppplVar7;
  ulonglong uVar8;
  uint *puVar9;
  longlong *****ppppplVar10;
  longlong *****ppppplVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined **ppuVar14;
  uint uVar15;
  longlong *****ppppplVar16;
  longlong lVar17;
  longlong lVar18;
  undefined1 auStackY_88 [8];
  undefined1 auStackY_80 [24];
  undefined *in_stack_ffffffffffffff98;
  longlong *****local_38;
  longlong *****local_30;
  
  puVar13 = auStackY_88;
  local_30 = (longlong *****)&local_38;
  puVar9 = *(uint **)(param_1 + 0x80);
  lVar17 = 0;
  bVar4 = false;
  local_38 = (longlong *****)&local_38;
  lVar18 = 0;
  ppppplVar16 = (longlong *****)0x0;
  ppppplVar10 = (longlong *****)param_2;
  if (*puVar9 != 0) {
    do {
      ppuVar14 = (undefined **)
                 (*(longlong *)(*(longlong *)(puVar9 + (longlong)ppppplVar16 * 2 + 2) + 0x40) + 8);
      ppppplVar10 = (longlong *****)ppuVar14;
      lVar6 = IoCsqRemoveNextIrp(*(longlong *)
                                  (*(longlong *)(puVar9 + (longlong)ppppplVar16 * 2 + 2) + 0x40) +
                                 0x28,ppuVar14);
      if (lVar6 != 0) {
        *(undefined ***)(lVar6 + 0x78) = ppuVar14;
        ppppplVar10 = (longlong *****)&local_38;
        ppppplVar7 = (longlong *****)(lVar6 + 0xa8);
        if ((longlong *****)*local_30 != ppppplVar10) goto LAB_1400038ce;
        *(longlong ******)(lVar6 + 0xb0) = local_30;
        ppppplVar10 = (longlong *****)&local_38;
        *ppppplVar7 = (longlong ****)ppppplVar10;
        *local_30 = (longlong ****)ppppplVar7;
        local_30 = ppppplVar7;
      }
      puVar9 = *(uint **)(param_1 + 0x80);
      uVar15 = (int)ppppplVar16 + 1;
      ppppplVar16 = (longlong *****)(ulonglong)uVar15;
    } while (uVar15 < *puVar9);
  }
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 400);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    ppppplVar10 = (longlong *****)CONCAT71((int7)((ulonglong)ppppplVar10 >> 8),4);
    in_stack_ffffffffffffff98 = &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids;
    param_3 = 3;
    WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x560),4,3,0x16,
                      &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                      (char)*(undefined8 *)(param_1 + 0x20));
  }
  lVar6 = *(longlong *)(param_1 + 0x180);
  *(undefined1 *)(param_1 + 0x1b8) = 0;
  if (lVar6 != 0) {
    *(undefined8 *)(param_1 + 0x180) = 0;
    lVar17 = lVar6;
  }
  ppppplVar10 = (longlong *****)CONCAT71((int7)((ulonglong)ppppplVar10 >> 8),uVar5);
  LOCK();
  *(undefined4 *)(param_1 + 0x188) = 0;
  UNLOCK();
  LOCK();
  *(undefined4 *)(param_1 + 0x18c) = 0;
  UNLOCK();
  KeReleaseSpinLock(param_1 + 400);
  ppuVar14 = &WPP_RECORDER_INITIALIZED;
  while (ppppplVar16 = local_38, (longlong ******)local_38 != &local_38) {
    if (((longlong ******)local_38[1] != &local_38) ||
       (ppppplVar7 = (longlong *****)*local_38, (longlong *****)ppppplVar7[1] != local_38))
    goto LAB_1400038ce;
    ppppplVar11 = local_38 + -0x15;
    ppppplVar7[1] = (longlong ****)&local_38;
    ppppplVar1 = local_38 + -0xf;
    local_38 = ppppplVar7;
    *(int *)ppppplVar1 = (int)param_2;
    pppplVar2 = ppppplVar16[-6];
    ppppplVar16[-6] = (longlong ****)0x0;
    if (*(char *)(param_1 + 0x55a) == '\0') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqqd
                  (*(undefined8 *)(param_1 + 0x560),ppppplVar10,param_3,0x17,
                   in_stack_ffffffffffffff98,(char)*(undefined8 *)(param_1 + 0x20),(char)ppppplVar11
                   ,(char)pppplVar2[0x1c],(char)param_2);
      }
      IofCompleteRequest(ppppplVar11,0);
      UsbcReleaseRemoveLock(param_1,(longlong)ppppplVar11);
      param_3 = 0x20;
      IoReleaseRemoveLockEx(param_1 + 200);
      ppppplVar10 = ppppplVar11;
    }
    else {
      CancelRemoteWakeNotificationIrp((longlong)pppplVar2,(longlong)ppppplVar11);
      ppppplVar10 = ppppplVar11;
    }
  }
  ppppplVar16 = (longlong *****)(param_1 + 0x158);
  uVar5 = KeAcquireSpinLockRaiseToDpc(ppppplVar16);
  KeSetEvent(param_1 + 0x1a0,0,0);
  uVar15 = *(uint *)(param_1 + 0x4d4);
  puVar12 = auStackY_88;
  if ((uVar15 & 0x20) == 0) goto LAB_140003736;
LAB_1400038d5:
  lVar18 = *(longlong *)(param_1 + 0x4d8);
  uVar15 = uVar15 & 0xffffffdf;
  *(undefined8 *)(param_1 + 0x4d8) = 0;
  bVar4 = true;
  *(uint *)(param_1 + 0x4d4) = uVar15;
  puVar12 = puVar13;
LAB_140003736:
  *(undefined8 *)(puVar12 + -8) = 0x140003743;
  KeReleaseSpinLock(ppppplVar16,CONCAT31((int3)(uVar15 >> 8),uVar5));
  if (bVar4) {
    *(undefined8 *)(puVar12 + -8) = 0x1400038a6;
    uVar8 = AllocateWorker(param_1,IdleFinishCompletionWorker,lVar18);
    if ((int)uVar8 < 0) {
      *(undefined8 *)(puVar12 + -8) = 0x1400038b9;
      IdleFinishCompletionWorker(param_1,lVar18);
    }
  }
  *(undefined8 *)(puVar12 + -8) = 0x140003759;
  CheckParentWaitWake(param_1);
  if (lVar17 != 0) {
    *(undefined8 *)(puVar12 + -8) = 0x140003769;
    UsbcReleaseRemoveLock(param_1,lVar17);
    *(undefined8 *)(puVar12 + -8) = 0x140003780;
    IoReleaseRemoveLockEx(param_1 + 200,lVar17,0x20);
  }
  return;
LAB_1400038ce:
  uVar15 = (uint)ppppplVar10;
  uVar5 = SUB81(ppuVar14,0);
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  puVar13 = auStackY_80;
  goto LAB_1400038d5;
}



===== CheckParentWaitWake @ 1400038fc =====

void CheckParentWaitWake(longlong param_1)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  undefined1 uVar4;
  uint uVar5;
  undefined8 in_R8;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_R8 = 3;
    WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x560),4,3,0x21,
                      &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                      (char)*(undefined8 *)(param_1 + 0x20));
  }
  lVar1 = param_1 + 400;
  uVar4 = KeAcquireSpinLockRaiseToDpc(lVar1);
  iVar3 = *(int *)(param_1 + 0x198);
  cVar2 = *(char *)(param_1 + 0x1b8);
  if (iVar3 == 0) {
    if (cVar2 != '\0') {
      LOCK();
      iVar3 = *(int *)(param_1 + 0x188);
      *(int *)(param_1 + 0x188) = 1;
      UNLOCK();
      KeReleaseSpinLock(lVar1,uVar4);
      CancelParentWaitWakeArg(param_1,iVar3);
      return;
    }
  }
  else if (cVar2 == '\0') {
    *(undefined1 *)(param_1 + 0x1b8) = 1;
    KeReleaseSpinLock(lVar1,CONCAT31((int3)((uint)iVar3 >> 8),uVar4));
    uVar5 = SubmitParentWaitWakeIrp(param_1);
    if ((int)uVar5 < 0) {
      CompleteAllPdoWaitWakeIrps(param_1,(longlong ****)(ulonglong)uVar5,in_R8);
      return;
    }
    return;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qdd(*(undefined8 *)(param_1 + 0x560),4,3,0x22,
                        &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                        (char)*(undefined8 *)(param_1 + 0x20),cVar2,(char)iVar3);
  }
  KeReleaseSpinLock(lVar1,uVar4);
  return;
}



===== WPP_RECORDER_SF_q @ 140003a78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_q(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar1 * 0x50))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar1 * 0x50),0x2b,param_5,param_4,
               &param_6,8,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,0);
  return;
}



===== ResumeIdleTimerWorker @ 140003b80 =====

void ResumeIdleTimerWorker(longlong param_1)

{
  int iVar1;
  
  AcquireMutex(param_1 + 0x388,"idleTimerStateMutex",*(undefined8 *)(param_1 + 0x560));
  iVar1 = *(int *)(param_1 + 0x358);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qL(*(undefined8 *)(param_1 + 0x560),4,7,0x3e,
                       &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,
                       (char)*(undefined8 *)(param_1 + 0x20),(char)iVar1);
  }
  *(undefined1 *)(param_1 + 0x35c) = 1;
  if (iVar1 == 3) {
    *(undefined4 *)(param_1 + 0x358) = 1;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qLL(*(undefined8 *)(param_1 + 0x560),4,7,0x3f,
                          &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,
                          (char)*(undefined8 *)(param_1 + 0x20),3,1);
    }
    StartIdleTimer(param_1,'\x01');
  }
  KeReleaseMutex(param_1 + 0x388,0);
  return;
}



===== WPP_RECORDER_SF_qccccqd @ 140003c9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qccccqd
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10,undefined1 param_11,undefined1 param_12)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,param_4,&param_6,8,&param_7,1,
               &param_8,1,&param_9,1,&param_10,1,&param_11,8,&param_12,4,0);
  }
  WppAutoLogTrace(param_1,4,7,&WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,param_4,&param_6,8,
                  &param_7,1,&param_8,1,&param_9,1,&param_10,1,&param_11,8,&param_12,4,0);
  return;
}



===== CompleteAllFunctionIdleIrps @ 140003e40 =====

void CompleteAllFunctionIdleIrps(longlong param_1,undefined4 param_2)

{
  longlong ****pppplVar1;
  longlong ****pppplVar2;
  code *pcVar3;
  longlong lVar4;
  longlong ****pppplVar5;
  uint *puVar6;
  uint uVar7;
  ulonglong uVar8;
  longlong ****local_28;
  longlong ****local_20;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x560),4,7,0x22,
                      &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,
                      (char)*(undefined8 *)(param_1 + 0x20));
  }
  puVar6 = *(uint **)(param_1 + 0x80);
  local_20 = (longlong ****)&local_28;
  uVar8 = 0;
  local_28 = (longlong ****)&local_28;
  if (*puVar6 != 0) {
    do {
      lVar4 = IoCsqRemoveNextIrp(*(longlong *)(*(longlong *)(puVar6 + uVar8 * 2 + 2) + 0x40) + 0x80)
      ;
      if (lVar4 != 0) {
        pppplVar5 = (longlong ****)(lVar4 + 0xa8);
        if ((longlong *****)*local_20 != &local_28) goto LAB_140003fd9;
        *(longlong *****)(lVar4 + 0xb0) = local_20;
        *pppplVar5 = (longlong ***)&local_28;
        *local_20 = (longlong ***)pppplVar5;
        local_20 = pppplVar5;
      }
      puVar6 = *(uint **)(param_1 + 0x80);
      uVar7 = (int)uVar8 + 1;
      uVar8 = (ulonglong)uVar7;
    } while (uVar7 < *puVar6);
  }
  while( true ) {
    if ((longlong *****)local_28 == &local_28) {
      return;
    }
    if (((longlong *****)local_28[1] != &local_28) ||
       (pppplVar5 = (longlong ****)*local_28, (longlong ****)pppplVar5[1] != local_28)) break;
    pppplVar2 = local_28 + -0x15;
    pppplVar5[1] = (longlong ***)&local_28;
    pppplVar1 = local_28 + -0xf;
    local_28 = pppplVar5;
    *(undefined4 *)pppplVar1 = param_2;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(param_1 + 0x560),4,7,0x23,
                         &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,(char)pppplVar2,
                         (char)param_2);
    }
    IofCompleteRequest(pppplVar2,0);
    UsbcReleaseRemoveLock(param_1,(longlong)pppplVar2);
    IoReleaseRemoveLockEx(param_1 + 200,pppplVar2,0x20);
  }
LAB_140003fd9:
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== DispatchPdoIdleNotificationRequest @ 140003fe8 =====

ulonglong DispatchPdoIdleNotificationRequest(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined1 uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined1 uVar9;
  
  lVar4 = *(longlong *)(param_1 + 0xe8);
  puVar1 = (undefined8 *)(lVar4 + 0x560);
  puVar2 = (undefined8 *)(param_1 + 0xe0);
  uVar9 = (undefined1)param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qq(*puVar1,4,7,0x17,&WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,
                       (char)*puVar2,uVar9);
  }
  plVar5 = *(longlong **)(*(longlong *)(param_2 + 0xb8) + 0x20);
  if (plVar5 == (longlong *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*puVar1,4,7,0x18,&WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,uVar9);
    }
LAB_1400040e0:
    uVar7 = 0xc0000258;
  }
  else {
    if (*plVar5 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qq(*puVar1,4,7,0x19,&WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,
                           (char)*puVar2,uVar9);
      }
      goto LAB_1400040e0;
    }
    lVar3 = lVar4 + 0x2b8;
    uVar6 = KeAcquireSpinLockRaiseToDpc(lVar3);
    if ((*(longlong **)(param_1 + 0xb8) == (longlong *)(param_1 + 0xb8)) &&
       (*(char *)(param_1 + 0x76) == '\0')) {
      *(undefined1 *)(param_1 + 0x76) = 1;
      KeReleaseSpinLock(lVar3);
      if (*(char *)(lVar4 + 0x55a) == '\0') {
        IoCsqInsertIrp(param_1 + 0x78,param_2,0);
        uVar7 = 0x103;
        uVar8 = ResumeIdleTimer(lVar4);
        if (-1 < (int)uVar8) {
          return 0x103;
        }
        CompleteFunctionIdleIrp(param_1,(int)uVar8);
      }
      else {
        uVar7 = QueueIdleCallbackWorkItemForFunctionSuspend(param_1,lVar4,param_2);
        uVar7 = uVar7 & 0xffffffff;
      }
      if ((int)uVar7 == 0x103) {
        return uVar7;
      }
    }
    else {
      KeReleaseSpinLock(lVar3,uVar6);
      uVar7 = 0x80000011;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000410b;
      WPP_RECORDER_SF_qqd(*puVar1,2,7,0x1a,&WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,
                          (char)*puVar2,uVar9,0x11);
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqD(*(undefined8 *)(lVar4 + 0x560));
  }
LAB_14000410b:
  UsbcCompleteIrp(lVar4,(int)uVar7,param_2);
  return uVar7;
}



===== QueueIdleCallbackWorkItemForFunctionSuspend @ 14000424c =====

ulonglong QueueIdleCallbackWorkItemForFunctionSuspend
                    (longlong param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  uVar2 = UsbcAcquireRemoveLock(param_2,0x6b726f57,PdoInvokeIdleCallbackWorker);
  uVar3 = uVar2 & 0xffffffff;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(param_2 + 0x560),2,8,0x43,
                       &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids);
    }
  }
  else {
    *(longlong *)(param_3 + 0x78) = param_1;
    pbVar1 = (byte *)(*(longlong *)(param_3 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    IoQueueWorkItem(*(undefined8 *)(*(longlong *)(param_1 + 0x180) + 8),PdoInvokeIdleCallbackWorker,
                    1,param_3);
    uVar3 = 0x103;
  }
  return uVar3;
}



===== ResumeIdleTimer @ 140004314 =====

ulonglong ResumeIdleTimer(longlong param_1)

{
  bool bVar1;
  undefined1 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  bVar1 = true;
  if (*(char *)(param_1 + 0x568) == '\x01') {
    uVar4 = 0xc0000001;
  }
  else {
    uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x2b8);
    for (uVar4 = 0; (uint)uVar4 < **(uint **)(param_1 + 0x80); uVar4 = (ulonglong)((uint)uVar4 + 1))
    {
      if ((*(uint *)(*(longlong *)(*(longlong *)(*(uint **)(param_1 + 0x80) + uVar4 * 2 + 2) + 0x40)
                    + 0x130) & 0x17) == 0) {
        bVar1 = false;
        break;
      }
    }
    KeReleaseSpinLock(param_1 + 0x2b8,uVar2);
    if (bVar1) {
      uVar3 = AllocateWorkerIfNeeded(param_1,ResumeIdleTimerWorker);
      uVar4 = uVar3 & 0xffffffff;
      if (((int)uVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x560),2,7,0x40,
                          &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,
                          (char)*(undefined8 *)(param_1 + 0x20));
      }
    }
    else {
      uVar4 = 0;
    }
  }
  return uVar4;
}



===== DispatchPdoSetPower_SetParentD0Completion @ 140004410 =====

void DispatchPdoSetPower_SetParentD0Completion(longlong param_1,longlong param_2,int param_3)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_1 + 0xe8);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  if ((param_3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_qq(*(undefined8 *)(lVar1 + 0x560),4,3,0x3e,
                       &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                       (char)*(undefined8 *)(param_1 + 0xe0),(char)param_2);
  }
  *(undefined4 *)(param_1 + 0x10) = 1;
  PoSetPowerState(*(undefined8 *)(param_1 + 0xe0),*(undefined4 *)(lVar2 + 0x10),
                  *(undefined4 *)(lVar2 + 0x18));
  CompleteFunctionIdleIrp(param_1,0);
  if (*(char *)(lVar1 + 0x55a) == '\0') {
    PoStartNextPowerIrp(param_2);
    *(undefined4 *)(param_2 + 0x30) = 0;
    IofCompleteRequest(param_2,0);
    UsbcReleaseRemoveLock(lVar1,param_2);
    IoReleaseRemoveLockEx(lVar1 + 200,param_2,0x20);
  }
  else {
    LockSendSetFeatureControlRequestForFunctionSuspend(lVar1,param_1,param_2,2);
  }
  return;
}



===== PdoIdleInsertIrp @ 140004540 =====

void PdoIdleInsertIrp(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  code *pcVar2;
  longlong *plVar3;
  
  SetPdoIdle(*(longlong *)(param_1 + 0x70),param_1 + -0x78,3,1,'\0');
  *(longlong *)(param_1 + 0xa8) = param_2;
  plVar3 = (longlong *)(param_2 + 0xa8);
  *(undefined1 *)(param_1 + -2) = 0;
  plVar1 = *(longlong **)(param_1 + 0x48);
  if (*plVar1 == param_1 + 0x40) {
    *plVar3 = param_1 + 0x40;
    *(longlong **)(param_2 + 0xb0) = plVar1;
    *plVar1 = (longlong)plVar3;
    *(longlong **)(param_1 + 0x48) = plVar3;
    return;
  }
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)(3);
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}



===== PdoIdleRemoveIrp @ 1400045c0 =====

void PdoIdleRemoveIrp(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong *plVar5;
  
  plVar5 = (longlong *)(param_2 + 0xa8);
  lVar1 = *(longlong *)(param_1 + 0x70);
  lVar2 = *plVar5;
  if ((*(longlong **)(lVar2 + 8) == plVar5) &&
     (plVar3 = *(longlong **)(param_2 + 0xb0), (longlong *)*plVar3 == plVar5)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    SetPdoIdle(lVar1,param_1 + -0x78,3,0,'\0');
    *(undefined8 *)(param_1 + 0xa8) = 0;
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== DispatchPdoSetPower @ 140004624 =====

ulonglong DispatchPdoSetPower(longlong param_1,longlong param_2,undefined8 param_3)

{
  byte *pbVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  bool bVar5;
  char cVar6;
  undefined1 uVar7;
  ulonglong uVar8;
  longlong lVar9;
  uint uVar10;
  undefined8 in_stack_ffffffffffffffb8;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  lVar3 = *(longlong *)(param_1 + 0xe8);
  uVar7 = (undefined1)param_2;
  if (*(int *)(lVar2 + 0x10) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqL(*(undefined8 *)(lVar3 + 0x560),param_2,param_3,0x3f,
                          in_stack_ffffffffffffffb8,(char)*(undefined8 *)(param_1 + 0xe0),uVar7,
                          (char)*(undefined4 *)(lVar2 + 0x18));
    }
LAB_140004720:
    uVar8 = 0;
  }
  else {
    if (*(int *)(lVar2 + 0x10) != 1) {
      return (ulonglong)*(uint *)(param_2 + 0x30);
    }
    uVar10 = *(uint *)(lVar2 + 0x18);
    if (uVar10 == 1) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qq(*(undefined8 *)(lVar3 + 0x560),4,3,0x40,
                           &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                           (char)*(undefined8 *)(param_1 + 0xe0),uVar7);
      }
      SetPdoIdle(lVar3,param_1,2,0,'\x01');
      if ((*(char *)(lVar3 + 0x55a) != '\0') &&
         (lVar9 = IoCsqRemoveNextIrp(param_1 + 0x20), lVar9 != 0)) {
        CancelRemoteWakeNotificationIrp(param_1,lVar9);
      }
      uVar8 = ParentSetD0(lVar3,0,param_1,param_2,DispatchPdoSetPower_SetParentD0Completion);
      if ((int)uVar8 == 0x103) {
        return uVar8 & 0xffffffff;
      }
      if (((int)uVar8 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_SF_qq(*(undefined8 *)(lVar3 + 0x560),4,3,0x41,
                           &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                           (char)*(undefined8 *)(param_1 + 0xe0),uVar7);
      }
      *(undefined4 *)(param_1 + 0x10) = 1;
      PoSetPowerState(*(undefined8 *)(param_1 + 0xe0),*(undefined4 *)(lVar2 + 0x10),
                      *(undefined4 *)(lVar2 + 0x18));
      CompleteFunctionIdleIrp(param_1,0);
      if (*(char *)(lVar3 + 0x55a) == '\0') goto LAB_140004720;
      uVar10 = 2;
    }
    else {
      if (((uVar10 != 2) && (uVar10 != 3)) && (uVar10 != 4)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qd(*(undefined8 *)(lVar3 + 0x560),4,3,0x45,
                             &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                             (char)*(undefined8 *)(param_1 + 0xe0),(char)uVar10);
        }
        return (ulonglong)*(uint *)(param_2 + 0x30);
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqL(*(undefined8 *)(lVar3 + 0x560),(ulonglong)uVar10,param_3,0x42,
                            in_stack_ffffffffffffffb8,(char)*(undefined8 *)(param_1 + 0xe0),uVar7,
                            (char)uVar10);
      }
      if (((*(int *)(lVar2 + 0x18) == 4) && (*(char *)(param_1 + 0x74) == '\0')) &&
         (CompletePdoWaitWakeIrp(param_1,0xc00002d3,param_3), *(char *)(param_1 + 0x12e) == '\0')) {
        CompleteFunctionIdleIrp(param_1,0xc00002d3);
      }
      *(undefined4 *)(param_1 + 0x70) = 1;
      if (*(int *)(param_1 + 0x10) != 1) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qL(*(undefined8 *)(lVar3 + 0x560),4,3,0x43,
                             &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                             (char)*(undefined8 *)(param_1 + 0xe0),(char)*(int *)(param_1 + 0x10));
        }
        goto LAB_140004720;
      }
      *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(lVar2 + 0x18);
      if (*(int *)(lVar2 + 0x20) - 2U < 5) {
        bVar5 = true;
      }
      else {
        bVar5 = false;
        if (((*(char *)(param_1 + 300) == '\0') &&
            (uVar8 = AllocateWorker(lVar3,SetSelectiveSuspendRegistryFlag,param_1), (int)uVar8 < 0))
           && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          WPP_RECORDER_SF_(*(undefined8 *)(lVar3 + 0x560),4,3,0x44,
                           &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids);
          bVar5 = false;
        }
      }
      PoSetPowerState(*(undefined8 *)(param_1 + 0xe0),*(undefined4 *)(lVar2 + 0x10),
                      *(undefined4 *)(lVar2 + 0x18));
      if (*(char *)(lVar3 + 0x55a) == '\0') {
        cVar6 = SetPdoIdle(lVar3,param_1,2,1,'\x01');
        if (bVar5) {
          return 0;
        }
        if (cVar6 == '\0') {
          return 0;
        }
        ResumeIdleTimer(lVar3);
        return 0;
      }
      uVar7 = KeAcquireSpinLockRaiseToDpc(lVar3 + 400);
      plVar4 = *(longlong **)(param_1 + 0x60);
      KeReleaseSpinLock(lVar3 + 400,uVar7);
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      uVar10 = (uint)(plVar4 != (longlong *)(param_1 + 0x60));
    }
    LockSendSetFeatureControlRequestForFunctionSuspend(lVar3,param_1,param_2,uVar10);
    uVar8 = 0x103;
  }
  return uVar8;
}



===== SetPdoIdle @ 140004ab8 =====

undefined1 SetPdoIdle(longlong param_1,longlong param_2,int param_3,byte param_4,char param_5)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined *puVar5;
  undefined1 uVar6;
  uint uVar7;
  
  uVar1 = 0;
  if (param_5 != '\0') {
    uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x2b8);
  }
  uVar3 = *(uint *)(param_2 + 0x128);
  uVar6 = 1;
  uVar7 = uVar3 & 0x17;
  uVar2 = (uint)param_4;
  if (param_3 == 1) {
    uVar2 = (uVar2 << 2 ^ uVar3) & 4;
LAB_140004b73:
    uVar3 = uVar2 ^ uVar3;
    *(uint *)(param_2 + 0x128) = uVar3;
  }
  else {
    if (param_3 == 2) {
      uVar2 = (uVar2 ^ uVar3) & 1;
      goto LAB_140004b73;
    }
    if (param_3 == 3) {
      if ((*(uint *)(param_1 + 0x4d0) & 1) == 0) {
        uVar3 = uVar3 ^ (uVar2 * 2 ^ uVar3) & 2;
      }
      else {
        uVar3 = uVar3 & 0xfffffffd;
      }
      *(uint *)(param_2 + 0x128) = uVar3;
    }
    else if (param_3 == 4) {
      uVar2 = (uVar2 << 4 ^ uVar3) & 0x10;
      goto LAB_140004b73;
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qDL(*(undefined8 *)(param_1 + 0x560));
    uVar3 = *(uint *)(param_2 + 0x128);
  }
  if ((uVar7 != 0) || ((uVar3 & 0x17) == 0)) {
    uVar6 = 0;
  }
  uVar4 = Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline();
  uVar3 = *(uint *)(param_2 + 0x128) & 0x17;
  if ((int)uVar4 == 0) {
    if ((uVar7 != 0) == (uVar3 != 0)) goto LAB_140004c1e;
    puVar5 = *(undefined **)(param_2 + 0x1a0);
  }
  else if (((uVar7 != 0) == (uVar3 != 0)) ||
          (puVar5 = *(undefined **)(param_2 + 0x1a0), puVar5 == (undefined *)0x0))
  goto LAB_140004c1e;
  if (uVar3 == 0) {
    SleepstudyHelper_ComponentActive(puVar5);
  }
  else {
    SleepstudyHelper_ComponentInactive(puVar5);
  }
LAB_140004c1e:
  if (param_5 != '\0') {
    KeReleaseSpinLock(param_1 + 0x2b8,uVar1);
  }
  return uVar6;
}



===== ParentSetD0 @ 140004c68 =====

ulonglong ParentSetD0(longlong param_1,undefined8 param_2,longlong param_3,longlong param_4,
                     undefined8 param_5)

{
  byte *pbVar1;
  longlong *plVar2;
  longlong *plVar3;
  code *pcVar4;
  char cVar5;
  bool bVar6;
  undefined1 uVar7;
  uint uVar8;
  ulonglong uVar9;
  
  cVar5 = (char)param_2;
  uVar9 = 0;
  DisableIdleTimer(param_1,param_2,0x50534430);
  bVar6 = true;
  CancelFdoIdleIrp(param_1,CONCAT71((int7)((ulonglong)param_2 >> 8),1));
  if (*(int *)(param_1 + 4) == 1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x560),4,3,0x3f,
                        &WPP_93f6b87810f63f9db566694056813e32_Traceguids,
                        (char)*(undefined8 *)(param_1 + 0x20));
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x560),4,3,0x3e,
                        &WPP_93f6b87810f63f9db566694056813e32_Traceguids,
                        (char)*(undefined8 *)(param_1 + 0x20));
    }
    uVar8 = FdoSendSetPowerRequest(1,(undefined *)0x0,0,param_1);
    uVar9 = (ulonglong)uVar8;
    if ((uVar8 == 0x103) || (uVar8 == 0x80000011)) {
      if (cVar5 == '\0') {
        uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x158);
        if (*(char *)(param_1 + 0x160) == '\0') {
          uVar9 = (ulonglong)(-(uint)(*(int *)(param_1 + 4) != 1) & 0xc000009c);
        }
        else {
          pbVar1 = (byte *)(*(longlong *)(param_4 + 0xb8) + 3);
          *pbVar1 = *pbVar1 | 1;
          *(undefined8 *)(param_3 + 0x168) = param_5;
          plVar2 = (longlong *)(param_3 + 0x158);
          *(longlong *)(param_3 + 0x150) = param_4;
          plVar3 = *(longlong **)(param_1 + 0x170);
          if (*plVar3 != param_1 + 0x168) {
            pcVar4 = (code *)swi(0x29);
            (*pcVar4)(3);
            pcVar4 = (code *)swi(3);
            uVar9 = (*pcVar4)();
            return uVar9;
          }
          *plVar2 = param_1 + 0x168;
          uVar9 = 0x103;
          *(longlong **)(param_3 + 0x160) = plVar3;
          bVar6 = false;
          *plVar3 = (longlong)plVar2;
          *(longlong **)(param_1 + 0x170) = plVar2;
        }
        KeReleaseSpinLock(param_1 + 0x158,uVar7);
        if (!bVar6) {
          return uVar9;
        }
      }
      else {
        WaitForSignal(param_1 + 0x138,"parentD0Event (waiting for D0 IRP to complete)",
                      *(undefined8 *)(param_1 + 0x560));
        uVar9 = (ulonglong)(-(uint)(*(int *)(param_1 + 4) != 1) & 0xc000009c);
      }
    }
  }
  EnableIdleTimer(param_1,'\x01',0x50534430);
  return uVar9;
}



===== DisableIdleTimer @ 140004e80 =====

void DisableIdleTimer(longlong param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  char *pcVar2;
  undefined8 uVar3;
  undefined1 unaff_retaddr;
  undefined1 uStackX_19;
  undefined1 uStackX_1a;
  undefined1 uStackX_1b;
  undefined8 in_stack_ffffffffffffffb8;
  
  if (*(char *)(param_1 + 0x568) != '\x01') {
    uVar3 = *(undefined8 *)(param_1 + 0x560);
    pcVar2 = "idleTimerStateMutex";
    AcquireMutex(param_1 + 0x388,"idleTimerStateMutex",uVar3);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uStackX_19 = (undefined1)((uint)param_3 >> 8);
      uStackX_1a = (undefined1)((uint)param_3 >> 0x10);
      uStackX_1b = (undefined1)((uint)param_3 >> 0x18);
      WPP_RECORDER_SF_qccccqd
                (*(undefined8 *)(param_1 + 0x560),pcVar2,uVar3,0x3a,in_stack_ffffffffffffffb8,
                 (char)*(undefined8 *)(param_1 + 0x20),uStackX_1b,uStackX_1a,uStackX_19,
                 (char)param_3,unaff_retaddr,(char)*(undefined4 *)(param_1 + 0x380));
    }
    LOCK();
    *(int *)(param_1 + 0x380) = *(int *)(param_1 + 0x380) + 1;
    UNLOCK();
    iVar1 = *(int *)(param_1 + 0x358);
    if ((iVar1 - 1U & 0xfffffffd) == 0) {
      *(undefined4 *)(param_1 + 0x358) = 2;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qLL(*(undefined8 *)(param_1 + 0x560),4,7,0x3b,
                            &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,
                            (char)*(undefined8 *)(param_1 + 0x20),(char)iVar1,2);
      }
      if (iVar1 == 1) {
        StopIdleTimer(param_1);
      }
    }
    KeReleaseMutex(param_1 + 0x388,0);
  }
  return;
}



===== EnableIdleTimer @ 140004fd4 =====

void EnableIdleTimer(longlong param_1,char param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  undefined8 uVar4;
  undefined1 unaff_retaddr;
  undefined1 uStackX_19;
  undefined1 uStackX_1a;
  undefined1 uStackX_1b;
  undefined8 in_stack_ffffffffffffffa8;
  
  if (*(char *)(param_1 + 0x568) == '\x01') {
    return;
  }
  uVar4 = *(undefined8 *)(param_1 + 0x560);
  pcVar3 = "idleTimerStateMutex";
  AcquireMutex(param_1 + 0x388,"idleTimerStateMutex",uVar4);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uStackX_19 = (undefined1)((uint)param_3 >> 8);
    uStackX_1a = (undefined1)((uint)param_3 >> 0x10);
    uStackX_1b = (undefined1)((uint)param_3 >> 0x18);
    WPP_RECORDER_SF_qccccqd
              (*(undefined8 *)(param_1 + 0x560),pcVar3,uVar4,0x38,in_stack_ffffffffffffffa8,
               (char)*(undefined8 *)(param_1 + 0x20),uStackX_1b,uStackX_1a,uStackX_19,(char)param_3,
               unaff_retaddr,(char)*(undefined4 *)(param_1 + 0x380));
  }
  if (param_2 != '\0') {
    LOCK();
    piVar1 = (int *)(param_1 + 0x380);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 != 1) goto LAB_140005043;
  }
  iVar2 = *(int *)(param_1 + 0x358);
  if (iVar2 - 2U < 2) {
    *(undefined4 *)(param_1 + 0x358) = 1;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qLL(*(undefined8 *)(param_1 + 0x560),4,7,0x39,
                          &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,
                          (char)*(undefined8 *)(param_1 + 0x20),(char)iVar2,1);
    }
    StartIdleTimer(param_1,'\0');
  }
LAB_140005043:
  KeReleaseMutex(param_1 + 0x388,0);
  return;
}



===== AcquireMutex @ 140005134 =====

void AcquireMutex(undefined8 param_1,char *param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  void *pvVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined8 local_res20;
  undefined8 *puVar7;
  
  local_res20 = 0xffffffffdc3cba00;
  puVar7 = &local_res20;
  uVar5 = 0;
  uVar2 = 0;
  uVar4 = 0;
  iVar1 = KeWaitForSingleObject();
  while (iVar1 == 0x102) {
    uVar4 = uVar4 + 1;
    uVar6 = (ulonglong)uVar4;
    pvVar3 = SystemReserved1[0xf];
    DbgPrint("\nUSBCCGP Watchdog: Thread 0x%p has waited %d minutes waiting to acquire %s\n",
             SystemReserved1[0xf],uVar6,param_2);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qds(param_3,pvVar3,uVar6,0x3f,puVar7,(char)SystemReserved1[0xf],(char)uVar4,
                          param_2);
    }
    puVar7 = &local_res20;
    uVar5 = 0;
    uVar2 = 0;
    iVar1 = KeWaitForSingleObject(param_1,0,0,0);
  }
  if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_dqs(param_3,uVar2,uVar5,0x40,puVar7,(char)iVar1,(char)SystemReserved1[0xf],
                        param_2);
  }
  return;
}



===== CancelFdoIdleIrp @ 140005258 =====

void CancelFdoIdleIrp(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  uint uVar2;
  undefined1 uVar3;
  char cVar4;
  ulonglong uVar5;
  
  DisableIdleTimer(param_1,param_2,0x50434954);
  lVar1 = param_1 + 0x2b8;
  do {
    uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
    if (*(int *)(param_1 + 0xc) == 7) {
LAB_140005379:
      KeReleaseSpinLock(lVar1,uVar3);
      if (*(longlong *)(param_1 + 0x290) != 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x560),4,7,0x32,
                            &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,
                            (char)*(longlong *)(param_1 + 0x290));
        }
        cVar4 = IoCancelIrp(*(undefined8 *)(param_1 + 0x290));
        if ((cVar4 == '\0') && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)
           ) {
          WPP_RECORDER_SF_qd(*(undefined8 *)(param_1 + 0x560),4,7,0x33,
                             &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,
                             (char)*(undefined8 *)(param_1 + 0x290),0);
        }
      }
      if (((char)param_2 != '\0') && (*(char *)(param_1 + 0x568) == '\0')) {
        WaitForSignal(param_1 + 0x3c0,
                      "idleCompleteEvent (Wait for our IDLE irp to complete and the FDO to return to D0)"
                      ,*(undefined8 *)(param_1 + 0x560));
      }
LAB_1400052dc:
      EnableIdleTimer(param_1,'\x01',0x50434954);
      return;
    }
    uVar2 = *(uint *)(param_1 + 0x2b0);
    uVar5 = (ulonglong)uVar2;
    if (uVar2 == 0) {
LAB_1400052ca:
      KeReleaseSpinLock(lVar1,CONCAT71((int7)(uVar5 >> 8),uVar3));
      goto LAB_1400052dc;
    }
    if (uVar2 == 1) {
LAB_14000536a:
      ChangeIdleState(param_1,2,'\0');
      goto LAB_140005379;
    }
    uVar5 = (ulonglong)(uVar2 - 2);
    if ((uVar2 - 2 == 0) || (uVar5 = (ulonglong)(uVar2 - 3), uVar2 - 3 == 0)) goto LAB_1400052ca;
    if (uVar2 == 4) goto LAB_14000536a;
    if (uVar2 != 5) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_L(*(undefined8 *)(param_1 + 0x560),2,8,0x31,
                          &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,(char)uVar2);
      }
      goto LAB_140005379;
    }
    KeReleaseSpinLock(lVar1,uVar3);
    if (*(char *)(param_1 + 0x568) == '\0') {
      WaitForSignal(param_1 + 0x368,
                    "idleCallbackBusyEvent (waiting for IdleCallback to run to completion)",
                    *(undefined8 *)(param_1 + 0x560));
    }
  } while( true );
}



===== CompleteFunctionIdleIrp @ 140005494 =====

void CompleteFunctionIdleIrp(longlong param_1,undefined4 param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_1 + 0xe8);
  lVar2 = IoCsqRemoveNextIrp(param_1 + 0x78,param_1);
  if (lVar2 != 0) {
    *(undefined4 *)(lVar2 + 0x30) = param_2;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(lVar1 + 0x560),4,7,0x21,
                         &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,(char)lVar2,(char)param_2)
      ;
    }
    IofCompleteRequest(lVar2,0);
    UsbcReleaseRemoveLock(lVar1,lVar2);
    IoReleaseRemoveLockEx(lVar1 + 200,lVar2,0x20);
  }
  return;
}



===== StartIdleTimer @ 14000555c =====

void StartIdleTimer(longlong param_1,char param_2)

{
  uint uVar1;
  longlong lVar2;
  
  uVar1 = *(uint *)(param_1 + 0x360);
  if (param_2 == '\0') {
    lVar2 = (ulonglong)uVar1 * -10000;
  }
  else {
    lVar2 = -1;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),4,7,0x35,
                     &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids);
  }
  KeSetCoalescableTimer(param_1 + 0x2c0,lVar2,uVar1,500,param_1 + 0x318);
  return;
}



===== WPP_RECORDER_SF_qLL @ 140005600 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLL(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar1 * 0x50))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar1 * 0x50),0x2b,param_5,param_4,
               &param_6,8,&param_7,4,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_ @ 14000575c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                     undefined8 param_5)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar1 * 0x50))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar1 * 0x50),0x2b,param_5,param_4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,0);
  return;
}



===== UnblockWorkBlockedOnPendingParentD0 @ 140005840 =====

void UnblockWorkBlockedOnPendingParentD0(longlong param_1)

{
  longlong lVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  longlong ****pppplVar8;
  longlong lVar9;
  undefined8 uVar10;
  bool bVar11;
  
  bVar2 = false;
  bVar3 = false;
  cVar4 = KeGetCurrentIrql();
  lVar9 = 0;
  UnblockAllPendedPdoD0Irps(param_1);
  if (*(int *)(param_1 + 0x240) == 2) {
    puVar7 = *(uint **)(param_1 + 0x80);
    uVar6 = 0;
    if (*puVar7 != 0) {
      do {
        lVar1 = *(longlong *)(*(longlong *)(puVar7 + (ulonglong)uVar6 * 2 + 2) + 0x40);
        if (*(char *)(param_1 + 0x55a) != '\0') {
          *(undefined1 *)(*(longlong *)(lVar1 + 0x188) + 0x3b) = 0;
        }
        if (*(int *)(lVar1 + 0x18) != 1) {
          *(undefined4 *)(lVar1 + 0x78) = 2;
          PoFxNotifySurprisePowerOn();
        }
        puVar7 = *(uint **)(param_1 + 0x80);
        uVar6 = uVar6 + 1;
      } while (uVar6 < *puVar7);
    }
  }
  KeAcquireSpinLockRaiseToDpc(param_1 + 0x158);
  *(undefined4 *)(param_1 + 0x150) = 0;
  uVar10 = 0;
  KeSetEvent(param_1 + 0x138,0);
  uVar6 = *(uint *)(param_1 + 0x4d4);
  if ((uVar6 & 4) != 0) {
    uVar6 = uVar6 & 0xfffffffb;
    *(uint *)(param_1 + 0x4d4) = uVar6;
    if (cVar4 == '\0') {
      bVar2 = true;
    }
    else {
      uVar6 = uVar6 | 1;
      *(uint *)(param_1 + 0x4d4) = uVar6;
    }
  }
  bVar11 = (uVar6 & 8) != 0;
  if (bVar11) {
    uVar6 = uVar6 & 0xfffffff7;
    *(uint *)(param_1 + 0x4d4) = uVar6;
  }
  if ((uVar6 & 0x10) != 0) {
    *(uint *)(param_1 + 0x4d4) = uVar6 & 0xffffffef;
    iVar5 = KeReadStateEvent(param_1 + 0x1a0);
    if (iVar5 == 0) {
      *(uint *)(param_1 + 0x4d4) = *(uint *)(param_1 + 0x4d4) | 0x20;
    }
    else {
      lVar9 = *(longlong *)(param_1 + 0x4d8);
      bVar3 = true;
      *(undefined8 *)(param_1 + 0x4d8) = 0;
    }
  }
  KeReleaseSpinLock(param_1 + 0x158);
  if (bVar2) {
    uVar10 = 0x574f524b;
    EnableIdleTimer(param_1,'\x01',0x574f524b);
  }
  if (bVar11) {
    if (*(char *)(param_1 + 0x55a) == '\0') {
      pppplVar8 = (longlong ****)0x0;
    }
    else {
      if (*(int *)(param_1 + 0x240) != 2) {
        FinishWaitWakeCompletionForFunctionSuspend(param_1);
        goto LAB_14000595f;
      }
      pppplVar8 = (longlong ****)0xc0000120;
    }
    CompleteAllPdoWaitWakeIrps(param_1,pppplVar8,uVar10);
  }
LAB_14000595f:
  if (bVar3) {
    IdleFinishCompletionWorker(param_1,lVar9);
  }
  return;
}



===== UnblockAllPendedPdoD0Irps @ 140005a40 =====

void UnblockAllPendedPdoD0Irps(longlong param_1)

{
  longlong ****pppplVar1;
  longlong ****pppplVar2;
  longlong ***ppplVar3;
  code *pcVar4;
  undefined1 uVar5;
  longlong ****local_18;
  longlong ****local_10;
  
  local_10 = (longlong ****)&local_18;
  local_18 = (longlong ****)&local_18;
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x158);
  *(undefined1 *)(param_1 + 0x160) = 0;
  pppplVar1 = (longlong ****)(param_1 + 0x168);
  while (pppplVar2 = (longlong ****)*pppplVar1, pppplVar2 != pppplVar1) {
    if (((longlong ****)pppplVar2[1] != pppplVar1) ||
       (ppplVar3 = *pppplVar2, (longlong ****)ppplVar3[1] != pppplVar2)) goto LAB_140005b35;
    *pppplVar1 = ppplVar3;
    ppplVar3[1] = (longlong **)pppplVar1;
    if ((longlong *****)*local_10 != &local_18) goto LAB_140005b35;
    pppplVar2[1] = (longlong ***)local_10;
    *pppplVar2 = (longlong ***)&local_18;
    *local_10 = (longlong ***)pppplVar2;
    local_10 = pppplVar2;
  }
  KeReleaseSpinLock(param_1 + 0x158,CONCAT71((int7)((ulonglong)pppplVar1 >> 8),uVar5));
  while( true ) {
    pppplVar1 = local_18;
    if ((longlong *****)local_18 == &local_18) {
      return;
    }
    if (((longlong *****)local_18[1] != &local_18) ||
       (pppplVar2 = (longlong ****)*local_18, (longlong ****)pppplVar2[1] != local_18)) break;
    pppplVar2[1] = (longlong ***)&local_18;
    local_18[1] = (longlong ***)local_18;
    *local_18 = (longlong ***)local_18;
    local_18 = pppplVar2;
    UnblockPendedPdoD0Irp((longlong)(pppplVar1 + -0x2b),param_1);
  }
LAB_140005b35:
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== IdleFinishCompletionWorker @ 140005b50 =====

void IdleFinishCompletionWorker(longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x10);
  if ((*(char *)(param_1 + 0x55a) == '\0') || (*(int *)(param_1 + 0x240) == 2)) {
    CompleteAllFunctionIdleIrps(param_1,*(undefined4 *)(param_2 + 8));
  }
  ChangeIdleState(param_1,0,'\x01');
  ExFreePoolWithTag(param_2,0x43627355);
  KeSetEvent(param_1 + 0x3c0,0,0);
  UsbcReleaseRemoveLock(param_1,lVar1);
  IoReleaseRemoveLockEx(param_1 + 200,lVar1,0x20);
  return;
}



===== CallbackFdoDeviceSetD0 @ 140005c00 =====

void CallbackFdoDeviceSetD0(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar3 = lVar1 + 8;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(lVar1 + 0x568),4,3,0x24,
                      &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                      (char)*(undefined8 *)(lVar1 + 0x28));
  }
  uVar2 = AllocateWorkerIfNeeded(lVar3,UnblockWorkBlockedOnPendingParentD0);
  if ((int)uVar2 < 0) {
    UnblockWorkBlockedOnPendingParentD0(lVar3);
  }
  UsbcReleaseRemoveLock(lVar3,0x14001c2c8);
  IoReleaseRemoveLockEx(lVar1 + 0xd0,&gSetD0Tag,0x20);
  return;
}



===== AllocateWorkerIfNeeded @ 140005cac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong AllocateWorkerIfNeeded(longlong param_1,undefined *param_2)

{
  char cVar1;
  ulonglong uVar2;
  
  uVar2 = 0;
  cVar1 = KeGetCurrentIrql();
  if (cVar1 == '\0') {
    (*(code *)param_2)(param_1,0);
  }
  else {
    uVar2 = AllocateWorker(param_1,param_2,0);
    uVar2 = uVar2 & 0xffffffff;
  }
  return uVar2;
}



===== PdoIdleCancelCompleteWorker @ 140005d10 =====

void PdoIdleCancelCompleteWorker(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  
  lVar1 = param_2[2];
  WaitForSignal(*param_2 + 200,"idleCallbackEvent",*(undefined8 *)(*param_2 + 0x188));
  *(undefined4 *)(lVar1 + 0x30) = 0xc0000120;
  IofCompleteRequest(lVar1,0);
  ExFreePoolWithTag(param_2,0x43627355);
  UsbcReleaseRemoveLock(param_1,lVar1);
  IoReleaseRemoveLockEx(param_1 + 200,lVar1,0x20);
  return;
}



===== UsbcWorkerFunction @ 140005db0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UsbcWorkerFunction(undefined8 param_1,longlong param_2)

{
  (**(code **)(param_2 + 0x10))(*(undefined8 *)(param_2 + 8),*(undefined8 *)(param_2 + 0x20));
  IoFreeWorkItem(*(undefined8 *)(param_2 + 0x18));
  UsbcReleaseRemoveLock(*(longlong *)(param_2 + 8),*(longlong *)(param_2 + 0x10));
  IoReleaseRemoveLockEx(*(longlong *)(param_2 + 8) + 200,*(undefined8 *)(param_2 + 0x10),0x20);
  ExFreePoolWithTag(param_2,0x43627355);
  return;
}



===== CheckParentIdleWorker @ 140005e30 =====

void CheckParentIdleWorker(undefined8 param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined2 uVar7;
  
  lVar6 = param_2;
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x2b8);
  *(undefined1 *)(param_2 + 0x35c) = 0;
  for (uVar4 = 0; (uint)uVar4 < **(uint **)(param_2 + 0x80); uVar4 = (ulonglong)((uint)uVar4 + 1)) {
    lVar6 = *(longlong *)(*(uint **)(param_2 + 0x80) + uVar4 * 2 + 2);
    if ((*(uint *)(*(longlong *)(lVar6 + 0x40) + 0x130) & 0x17) == 0) goto LAB_140005f8a;
  }
  if (*(int *)(param_2 + 0x2b0) == 1) {
LAB_140005f8a:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      iVar3 = *(int *)(param_2 + 0x2b0);
      uVar5 = *(undefined8 *)(param_2 + 0x560);
      uVar7 = 0x16;
LAB_140006089:
      WPP_RECORDER_SF_qL(uVar5,4,7,uVar7,&WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,
                         (char)*(undefined8 *)(param_2 + 0x290),(char)iVar3);
    }
  }
  else {
    puVar1 = (undefined8 *)(param_2 + 0x560);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      lVar6 = CONCAT71((int7)((ulonglong)lVar6 >> 8),4);
      WPP_RECORDER_SF_(*puVar1,4,7,0x13,&WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids);
    }
    if (*(int *)(param_2 + 0x2b0) == 2) {
      uVar5 = CONCAT71((int7)((ulonglong)lVar6 >> 8),uVar2);
      KeReleaseSpinLock(param_2 + 0x2b8);
      DisableIdleTimer(param_2,uVar5,0x50434954);
      if (*(char *)(param_2 + 0x568) == '\0') {
        WaitForSignal(param_2 + 0x3c0,"idleCompleteEvent",*puVar1);
      }
      EnableIdleTimer(param_2,'\x01',0x50434954);
      uVar2 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x2b8);
    }
    iVar3 = *(int *)(param_2 + 0x2b0);
    if (iVar3 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*puVar1,4,7,0x14,&WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids);
      }
      ChangeIdleState(param_2,1,'\0');
      KeResetEvent(param_2 + 0x3c0);
      KeReleaseSpinLock(param_2 + 0x2b8,uVar2);
      if ((*(char *)(param_2 + 0x1ba) == '\x01') || (*(char *)(param_2 + 0x1b8) == '\0')) {
        uVar4 = PretendToSubmitParentIdleIrp(param_2,*(longlong *)(param_2 + 0x290));
        iVar3 = (int)uVar4;
      }
      else {
        uVar4 = SubmitParentIdleIrp(param_2,*(longlong *)(param_2 + 0x290));
        iVar3 = (int)uVar4;
      }
      if (iVar3 < 0) {
        CancelFdoIdleIrp(param_2,0);
        ChangeIdleState(param_2,0,'\x01');
        KeSetEvent(param_2 + 0x3c0,0,0);
      }
      goto LAB_140005fb4;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = *(undefined8 *)(param_2 + 0x560);
      uVar7 = 0x15;
      goto LAB_140006089;
    }
  }
  KeReleaseSpinLock(param_2 + 0x2b8,uVar2);
LAB_140005fb4:
  KeSetEvent(param_2 + 0x300,0,0);
  PauseIdleTimer(param_2);
  LOCK();
  *(undefined4 *)(param_2 + 0x3d8) = 0;
  UNLOCK();
  UsbcReleaseRemoveLock(param_2,0x140005e30);
  IoReleaseRemoveLockEx(param_2 + 200,CheckParentIdleWorker,0x20);
  return;
}



===== USBC_PnpComplete @ 140006190 =====

undefined8 USBC_PnpComplete(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  
  if ((*(char *)(*(longlong *)(param_2 + 0xb8) + 1) == '\x04') && (*(int *)(param_3 + 0xc) == 5)) {
    FreeInterfaceList(param_3,'\0');
    *(undefined4 *)(param_3 + 0xc) = 6;
  }
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  UsbcReleaseRemoveLock(param_3,param_2);
  IoReleaseRemoveLockEx(param_3 + 200,param_2,0x20);
  return 0;
}



===== CompletionFdoDeviceSetPower @ 140006220 =====

undefined8 CompletionFdoDeviceSetPower(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  if (*(int *)(lVar2 + 0x18) == 1) {
    if (*(char *)(param_3 + 0x1b9) != '\0') {
      GetD3ColdLastTransitionStatus(param_3);
    }
    if (*(int *)(param_2 + 0x30) < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(param_3 + 0x560),2,3,0xe,
                           &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                           (char)*(undefined8 *)(param_3 + 0x20),(char)*(int *)(param_2 + 0x30));
      }
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(param_3 + 0x560),4,3,0xd,
                          &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                          (char)*(undefined8 *)(param_3 + 0x20));
      }
      *(undefined4 *)(param_3 + 4) = 1;
      PoSetPowerState(*(undefined8 *)(param_3 + 0x20),*(undefined4 *)(lVar2 + 0x10),
                      *(undefined4 *)(lVar2 + 0x18));
    }
  }
  PoStartNextPowerIrp(param_2);
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  UsbcReleaseRemoveLock(param_3,param_2);
  IoReleaseRemoveLockEx(param_3 + 200,param_2,0x20);
  return 0;
}



===== UsbcReleaseRemoveLock @ 140006390 =====

void UsbcReleaseRemoveLock(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  code *pcVar3;
  undefined8 *puVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLock(param_1 + 0xf8,&local_28);
  puVar4 = *(undefined8 **)(param_1 + 0xe8);
  do {
    if (puVar4 == (undefined8 *)(param_1 + 0xe8)) {
LAB_14000640a:
      KeReleaseInStackQueuedSpinLock(&local_28);
      return;
    }
    puVar1 = (undefined8 *)*puVar4;
    if (puVar4[3] == param_2) {
      if (((undefined8 *)puVar1[1] != puVar4) ||
         (puVar2 = (undefined8 *)puVar4[1], (undefined8 *)*puVar2 != puVar4)) {
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      *puVar2 = puVar1;
      puVar1[1] = puVar2;
      ExFreePoolWithTag(puVar4 + -1,0x43627355);
      goto LAB_14000640a;
    }
    puVar4 = puVar1;
  } while( true );
}



===== GetD3ColdLastTransitionStatus @ 14000643c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GetD3ColdLastTransitionStatus(longlong param_1)

{
  longlong lVar1;
  uint *puVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined4 local_res8 [2];
  
  uVar4 = 0;
  local_res8[0] = 0;
  (**(code **)(param_1 + 0x200))(*(undefined8 *)(param_1 + 0x1c8),local_res8);
  puVar2 = *(uint **)(param_1 + 0x80);
  *(undefined4 *)(param_1 + 0x240) = local_res8[0];
  if (*puVar2 != 0) {
    do {
      lVar1 = uVar4 * 2;
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
      *(undefined4 *)(*(longlong *)(*(longlong *)(puVar2 + lVar1 + 2) + 0x40) + 0x78) =
           local_res8[0];
      puVar2 = *(uint **)(param_1 + 0x80);
    } while (uVar3 < *puVar2);
  }
  return;
}



===== ParentIdleNotificationRequestComplete @ 1400064b0 =====

undefined8
ParentIdleNotificationRequestComplete(undefined8 param_1,longlong param_2,longlong param_3)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  bool bVar3;
  undefined1 uVar4;
  int iVar5;
  longlong lVar6;
  ulonglong uVar7;
  
  bVar3 = false;
  puVar1 = (undefined8 *)(param_3 + 0x560);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*puVar1,4,7,0x1c,&WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,
                       (char)*(undefined8 *)(param_3 + 0x20),(char)*(undefined4 *)(param_2 + 0x30));
  }
  uVar2 = *(undefined4 *)(param_2 + 0x30);
  ChangeIdleState(param_3,3,'\x01');
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_L(*puVar1,4,7,0x1d,&WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,
                      (char)*(undefined4 *)(param_3 + 4));
  }
  iVar5 = FdoSendSetPowerRequest(1,(undefined *)0x0,0,param_3);
  if ((iVar5 != 0x103) && (iVar5 != -0x7fffffef)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*puVar1,2,8,0x1e,&WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,
                        (char)iVar5);
    }
    iVar5 = -0x3fffff66;
    goto LAB_14000672d;
  }
  lVar6 = ExAllocatePool2(0x40,0x18,0x43627355);
  if (lVar6 == 0) {
    iVar5 = -0x3fffff66;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*puVar1,2,8,0x1f,&WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,0x9a);
    }
    goto LAB_14000672d;
  }
  *(undefined4 *)(lVar6 + 8) = uVar2;
  *(longlong *)(lVar6 + 0x10) = param_2;
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_3 + 0x158);
  iVar5 = KeReadStateEvent(param_3 + 0x138);
  if (iVar5 == 0) {
    *(uint *)(param_3 + 0x4d4) = *(uint *)(param_3 + 0x4d4) | 0x10;
LAB_1400065a0:
    *(longlong *)(param_3 + 0x4d8) = lVar6;
    lVar6 = 0;
  }
  else {
    iVar5 = KeReadStateEvent(param_3 + 0x1a0);
    if (iVar5 == 0) {
      *(uint *)(param_3 + 0x4d4) = *(uint *)(param_3 + 0x4d4) | 0x20;
      goto LAB_1400065a0;
    }
    bVar3 = true;
  }
  KeReleaseSpinLock(param_3 + 0x158,uVar4);
  if (!bVar3) {
    return 0xc0000016;
  }
  uVar7 = AllocateWorker(param_3,IdleFinishCompletionWorker,lVar6);
  iVar5 = (int)uVar7;
  if (-1 < iVar5) {
    return 0xc0000016;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(*(undefined8 *)(param_3 + 0x560),2,8,0x20,
                      &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,(char)uVar7);
  }
  ExFreePoolWithTag(lVar6);
LAB_14000672d:
  if ((*(char *)(param_3 + 0x55a) == '\0') || (*(int *)(param_3 + 0x240) == 2)) {
    CompleteAllFunctionIdleIrps(param_3,iVar5);
  }
  ChangeIdleState(param_3,0,'\x01');
  KeSetEvent(param_3 + 0x3c0,0,0);
  UsbcReleaseRemoveLock(param_3,param_2);
  IoReleaseRemoveLockEx(param_3 + 200,param_2,0x20);
  return 0xc0000016;
}



===== ChangeIdleState @ 1400067a0 =====

void ChangeIdleState(longlong param_1,int param_2,char param_3)

{
  undefined1 uVar1;
  
  uVar1 = 0;
  if (param_3 != '\0') {
    uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x2b8);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qLL(*(undefined8 *)(param_1 + 0x560),4,7,0x37,
                        &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,
                        (char)*(undefined8 *)(param_1 + 0x20),(char)*(undefined4 *)(param_1 + 0x2b0)
                        ,(char)param_2);
  }
  if (*(int *)(param_1 + 0x2b0) == 4) {
    if (param_2 == 5) {
      KeResetEvent(param_1 + 0x368);
    }
  }
  else if (*(int *)(param_1 + 0x2b0) == 5) {
    *(int *)(param_1 + 0x2b0) = param_2;
    KeSetEvent(param_1 + 0x368,0,0);
  }
  *(int *)(param_1 + 0x2b0) = param_2;
  if (param_3 != '\0') {
    KeReleaseSpinLock(param_1 + 0x2b8,uVar1);
  }
  return;
}



===== FdoSendSetPowerRequest @ 1400068c0 =====

int FdoSendSetPowerRequest(int param_1,undefined *param_2,undefined8 param_3,longlong param_4)

{
  longlong lVar1;
  bool bVar2;
  undefined1 uVar3;
  int iVar4;
  ulonglong uVar5;
  
  bVar2 = false;
  if (param_1 == 1) {
    lVar1 = param_4 + 0x158;
    uVar3 = KeAcquireSpinLockRaiseToDpc(lVar1);
    if (*(int *)(param_4 + 0x150) != 0) {
      KeReleaseSpinLock(lVar1,uVar3);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(param_4 + 0x560),4,3,0x46,
                          &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                          (char)*(undefined8 *)(param_4 + 0x20));
      }
      return -0x7fffffef;
    }
    *(undefined4 *)(param_4 + 0x150) = 1;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(param_4 + 0x560),4,3,0x47,
                        &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                        (char)*(undefined8 *)(param_4 + 0x20));
    }
    KeResetEvent(param_4 + 0x138);
    *(undefined1 *)(param_4 + 0x160) = 1;
    KeReleaseSpinLock(lVar1,uVar3);
    if (param_2 == (undefined *)0x0) {
      UsbcAcquireRemoveLock(param_4,0x5f776f50,&gSetD0Tag);
      bVar2 = true;
      param_2 = CallbackFdoDeviceSetD0;
    }
  }
  iVar4 = PoRequestPowerIrp(*(undefined8 *)(param_4 + 0x20),2,param_1,param_2,param_3,0);
  if (iVar4 != 0x103) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(param_4 + 0x560),2,8,0x48,
                         &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                         (char)*(undefined8 *)(param_4 + 0x20),(char)iVar4);
    }
    if ((param_1 == 1) &&
       (uVar5 = AllocateWorkerIfNeeded(param_4,UnblockWorkBlockedOnPendingParentD0), (int)uVar5 < 0)
       ) {
      UnblockWorkBlockedOnPendingParentD0(param_4);
    }
    if (bVar2) {
      UsbcReleaseRemoveLock(param_4,0x14001c2c8);
      IoReleaseRemoveLockEx(param_4 + 200,&gSetD0Tag,0x20);
    }
  }
  return iVar4;
}



===== PretendToSubmitParentIdleIrp @ 140006b08 =====

ulonglong PretendToSubmitParentIdleIrp(longlong param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  IoReuseIrp(param_2,0);
  *(longlong *)(param_1 + 0x2a8) = param_1;
  *(undefined8 *)(param_1 + 0x2a0) = ParentIdleNotificationCallback;
  lVar1 = *(longlong *)(param_2 + 0xb8);
  *(undefined8 **)(lVar1 + -0x28) = (undefined8 *)(param_1 + 0x2a0);
  *(undefined1 *)(lVar1 + -0x48) = 0xf;
  *(undefined4 *)(lVar1 + -0x30) = 0x220027;
  *(undefined4 *)(lVar1 + -0x38) = 0x10;
  uVar2 = UsbcAcquireRemoveLock(param_1,0x70495353,param_2);
  uVar3 = uVar2 & 0xffffffff;
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,7,0x10,
                       &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids);
    }
  }
  else {
    SetCompletionRoutine
              (*(undefined8 *)(param_1 + 0x560),*(undefined8 *)(param_1 + 0x20),param_2,
               ParentIdleNotificationRequestComplete,param_1);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x560),4,7,0x11,
                        &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,(char)param_2);
    }
    uVar2 = AllocateWorker(param_1,InvokeParentIdleCallbackWorker,param_2);
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,7,0x12,
                         &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids);
      }
      UsbcReleaseRemoveLock(param_1,param_2);
      IoReleaseRemoveLockEx(param_1 + 200,param_2,0x20);
    }
    else {
      uVar3 = 0x103;
    }
  }
  return uVar3;
}



===== PdoIdleCancelComplete @ 140006cb0 =====

void PdoIdleCancelComplete(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  ulonglong uVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x70);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qq(*(undefined8 *)(param_1 + 0x110),4,7,0xb,
                       &WPP_c22e0bd291983066d7104eda50c0b1f9_Traceguids,
                       (char)*(undefined8 *)(param_1 + 0x68),(char)param_2);
  }
  if ((*(char *)(param_1 + 0xb5) != '\0') &&
     (plVar2 = (longlong *)ExAllocatePool2(0x40,0x18,0x43627355), plVar2 != (longlong *)0x0)) {
    plVar2[2] = param_2;
    *plVar2 = param_1 + -0x78;
    *(undefined4 *)(plVar2 + 1) = 0xc0000120;
    uVar3 = AllocateWorker(lVar1,PdoIdleCancelCompleteWorker,plVar2);
    if (-1 < (int)uVar3) {
      return;
    }
    ExFreePoolWithTag(plVar2,0x43627355);
  }
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  IofCompleteRequest(param_2,0);
  UsbcReleaseRemoveLock(lVar1,param_2);
  IoReleaseRemoveLockEx(lVar1 + 200,param_2,0x20);
  return;
}



===== AllocateWorker @ 140006dec =====

ulonglong AllocateWorker(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  
  puVar1 = (undefined4 *)ExAllocatePool2(0x40,0x28,0x43627355);
  if (puVar1 == (undefined4 *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0x36,
                       &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids);
    }
    return 0xc000009a;
  }
  lVar2 = IoAllocateWorkItem(*(undefined8 *)(param_1 + 0x20));
  if (lVar2 == 0) {
    uVar4 = 0xc000009a;
    ExFreePoolWithTag(puVar1,0x43627355);
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0xc000009a;
    }
    uVar5 = 0x37;
  }
  else {
    *(undefined8 *)(puVar1 + 4) = param_2;
    *(longlong *)(puVar1 + 6) = lVar2;
    *(undefined8 *)(puVar1 + 8) = param_3;
    *(longlong *)(puVar1 + 2) = param_1;
    *puVar1 = 0x6b726f57;
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(param_1 + 0x560),5,3,0x38,
                         &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids,(char)param_2,
                         (char)param_3);
    }
    uVar3 = UsbcAcquireRemoveLock(param_1,0x6b726f57,param_2);
    uVar4 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      IoQueueWorkItem(lVar2,UsbcWorkerFunction,0,puVar1);
      return uVar4;
    }
    ExFreePoolWithTag(puVar1,0x43627355);
    IoFreeWorkItem(lVar2);
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return uVar4;
    }
    uVar5 = 0x39;
  }
  WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,uVar5,
                   &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids);
  return uVar4;
}



===== CheckParentIdleDpc @ 140006ff0 =====

void CheckParentIdleDpc(undefined8 param_1,longlong param_2)

{
  ulonglong uVar1;
  
  if (*(int *)(param_2 + 0x3d8) == 0) {
    KeClearEvent(param_2 + 0x300);
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_(*(undefined8 *)(param_2 + 0x560),5,7,0xb,
                       &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids);
    }
    uVar1 = UsbcAcquireRemoveLock(param_2,0x6b726f57,CheckParentIdleWorker);
    if ((int)uVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(param_2 + 0x560),2,8,0xc,
                         &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids);
      }
      KeSetEvent(param_2 + 0x300,0,0);
    }
    else {
      LOCK();
      *(undefined4 *)(param_2 + 0x3d8) = 1;
      UNLOCK();
      IoQueueWorkItem(*(undefined8 *)(param_2 + 0x288),CheckParentIdleWorker,0,param_2);
    }
  }
  return;
}



===== UsbcAcquireRemoveLock @ 140007110 =====

ulonglong UsbcAcquireRemoveLock(longlong param_1,undefined4 param_2,undefined8 param_3)

{
  longlong *plVar1;
  code *pcVar2;
  uint uVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  longlong *plVar6;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  uVar3 = IoAcquireRemoveLockEx(param_1 + 200,param_3,"",1,0x20);
  if (-1 < (int)uVar3) {
    puVar4 = (undefined4 *)ExAllocatePool2(0x40,0x28,0x43627355);
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = 0x6b636f4c;
      puVar4[6] = param_2;
      *(undefined8 *)(puVar4 + 8) = param_3;
      KeAcquireInStackQueuedSpinLock(param_1 + 0xf8,&local_28);
      plVar6 = (longlong *)(puVar4 + 2);
      plVar1 = *(longlong **)(param_1 + 0xf0);
      if (*plVar1 != param_1 + 0xe8) {
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(3);
        pcVar2 = (code *)swi(3);
        uVar5 = (*pcVar2)();
        return uVar5;
      }
      *(longlong **)(puVar4 + 4) = plVar1;
      *plVar6 = param_1 + 0xe8;
      *plVar1 = (longlong)plVar6;
      *(longlong **)(param_1 + 0xf0) = plVar6;
      KeReleaseInStackQueuedSpinLock(&local_28);
    }
  }
  return (ulonglong)uVar3;
}



===== UsbcForwardIrpWithCompletion @ 140007218 =====

void UsbcForwardIrpWithCompletion
               (longlong param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_3 + 0xb8);
  puVar1[-9] = *puVar1;
  puVar1[-8] = puVar1[1];
  puVar1[-7] = puVar1[2];
  puVar1[-6] = puVar1[3];
  puVar1[-5] = puVar1[4];
  puVar1[-4] = puVar1[5];
  puVar1[-3] = puVar1[6];
  *(undefined1 *)((longlong)puVar1 + -0x45) = 0;
  SetCompletionRoutine(*(undefined8 *)(param_1 + 0x560),param_5,param_3,param_4,param_6);
  IofCallDriver(param_2,param_3);
  return;
}



===== SetCompletionRoutine @ 140007294 =====

void SetCompletionRoutine
               (undefined8 param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
               undefined8 param_5)

{
  longlong lVar1;
  int iVar2;
  
  iVar2 = IoSetCompletionRoutineEx(param_2,param_3,param_4,param_5,1,1,1);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(param_1,3,1,0x3c,&WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids,
                        (char)iVar2);
    }
    lVar1 = *(longlong *)(param_3 + 0xb8);
    *(undefined8 *)(lVar1 + -0x10) = param_4;
    *(undefined8 *)(lVar1 + -8) = param_5;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
  }
  return;
}



===== CompletionPdoSelectInterface @ 140007350 =====

undefined8 CompletionPdoSelectInterface(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 uVar5;
  void *_Dst;
  ushort *_Src;
  undefined2 uVar6;
  longlong *plVar7;
  undefined1 uVar8;
  
  iVar2 = *(int *)(param_2 + 0x30);
  lVar3 = *(longlong *)(param_3 + 0xe8);
  lVar4 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  if (-1 < iVar2) {
    uVar5 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x50);
    plVar7 = *(longlong **)(lVar3 + 0x58);
    if (*(short *)(lVar4 + 2) == 1) {
      _Src = (ushort *)(lVar4 + 0x20);
    }
    else {
      _Src = (ushort *)(lVar4 + 0x30);
    }
    for (; *plVar7 != 0; plVar7 = plVar7 + 2) {
      if (*(char *)(*plVar7 + 2) == (char)_Src[1]) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qd(*(undefined8 *)(param_3 + 0x188),4,1,0x1d,
                             &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,
                             (char)*(undefined8 *)(param_3 + 0xe0),(char)_Src[1]);
        }
        if (plVar7[1] != 0) {
          ExFreePoolWithTag(plVar7[1],0x43627355);
        }
        _Dst = MemDup(_Src,(uint)*_Src);
        plVar7[1] = (longlong)_Dst;
        if (_Dst != (void *)0x0) {
          memmove(_Dst,_Src,(ulonglong)*_Src);
          goto LAB_140007472;
        }
        *(undefined4 *)(param_2 + 0x30) = 0xc000009a;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140007472;
        uVar6 = 0x1e;
        uVar8 = (undefined1)iVar2;
        goto LAB_140007402;
      }
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar8 = (undefined1)_Src[1];
      uVar6 = 0x1f;
LAB_140007402:
      WPP_RECORDER_SF_d(*(undefined8 *)(param_3 + 0x188),2,8,uVar6,
                        &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,uVar8);
    }
LAB_140007472:
    KeReleaseSpinLock(lVar3 + 0x50,uVar5);
  }
  UsbcDecrementPendingCount(lVar3,param_2);
  UsbcReleaseRemoveLock(lVar3,param_2);
  IoReleaseRemoveLockEx(lVar3 + 200,param_2,0x20);
  return 0;
}



===== UsbcDecrementPendingCount @ 140007560 =====

void UsbcDecrementPendingCount(longlong param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong *plVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [40];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  iVar6 = 1;
  local_28 = 0;
  uStack_20 = 0;
  KeAcquireInStackQueuedSpinLock(param_1 + 0x100,&local_28);
  puVar7 = auStack_58;
  plVar5 = *(longlong **)(param_1 + 0x108);
  do {
    if (plVar5 == (longlong *)(param_1 + 0x108)) {
LAB_140007642:
      if (*(char *)(param_1 + 0x568) == (char)iVar6) {
        LOCK();
        piVar1 = (int *)(param_1 + 0x118);
        iVar6 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        iVar6 = iVar6 + -1;
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        *(undefined **)(puVar7 + 0x20) = &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids;
        *(undefined8 *)(puVar7 + -8) = 0x14000768f;
        WPP_RECORDER_SF_(g_RecorderLog,3,8,0x3b,*(undefined8 *)(puVar7 + 0x20));
        *(undefined8 *)(puVar7 + -8) = 0x14000769b;
        KeReleaseInStackQueuedSpinLock(puVar7 + 0x30);
        return;
      }
LAB_1400075f5:
      *(undefined8 *)(puVar7 + -8) = 0x140007601;
      KeReleaseInStackQueuedSpinLock(puVar7 + 0x30);
      if (iVar6 == 0) {
        *(undefined8 *)(puVar7 + -8) = 0x14000761d;
        KeSetEvent(param_1 + 0x120,0,0);
      }
      return;
    }
    if (plVar5[3] == param_2) {
      LOCK();
      piVar1 = (int *)(param_1 + 0x118);
      iVar6 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      lVar2 = *plVar5;
      iVar6 = iVar6 + -1;
      if ((*(longlong **)(lVar2 + 8) == plVar5) &&
         (plVar3 = (longlong *)plVar5[1], (longlong *)*plVar3 == plVar5)) {
        *plVar3 = lVar2;
        *(longlong **)(lVar2 + 8) = plVar3;
        ExFreePoolWithTag(plVar5 + -1,0x43627355);
        puVar7 = auStack_58;
        goto LAB_1400075f5;
      }
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      puVar7 = auStack_50;
      goto LAB_140007642;
    }
    plVar5 = (longlong *)*plVar5;
  } while( true );
}



===== USBC_Dispatch @ 1400076b0 =====

undefined4 USBC_Dispatch(longlong param_1,longlong param_2)

{
  int *piVar1;
  byte bVar2;
  byte bVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 uVar6;
  code *pcVar7;
  bool bVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  ulonglong uVar12;
  undefined *puVar13;
  longlong lVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined **ppuVar17;
  IMAGE_DOS_HEADER *pIVar18;
  uint uVar19;
  uint uVar20;
  longlong lVar21;
  undefined1 auStackY_98 [8];
  undefined1 auStackY_90 [24];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  bVar8 = false;
  lVar4 = *(longlong *)(param_1 + 0x40);
  bVar2 = (*(byte **)(param_2 + 0xb8))[1];
  bVar3 = **(byte **)(param_2 + 0xb8);
  uVar19 = (uint)bVar3;
  if (*(char *)(lVar4 + 4) == '\0') {
    lVar21 = *(longlong *)(lVar4 + 0xf0);
    lVar14 = lVar4 + 8;
    LOCK();
    *(int *)(lVar4 + 0x13c) = *(int *)(lVar4 + 0x13c) + 1;
    UNLOCK();
    if (*(int *)(lVar4 + 0x1c) == 10) {
      LOCK();
      *(int *)(lVar4 + 0x13c) = *(int *)(lVar4 + 0x13c) + -1;
      UNLOCK();
      if ((uVar19 == 0x16) && (bVar2 != 0)) {
        PoStartNextPowerIrp(param_2);
      }
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(undefined4 *)(param_2 + 0x30) = 0xc0000056;
      IofCompleteRequest(param_2,0);
      return 0xc0000056;
    }
    bVar8 = true;
  }
  else {
    lVar21 = lVar4 + 8;
    lVar14 = 0;
  }
  local_48 = 0;
  local_58 = 0;
  uStack_50 = 0;
  iVar9 = IoAcquireRemoveLockEx(lVar21 + 200,param_2,"",1);
  if (iVar9 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(g_RecorderLog,4,1,10,&WPP_b8ba6c0bda43381ffdf12cf14fa10529_Traceguids,
                        (char)param_2);
    }
    if ((uVar19 == 0x16) && (bVar2 != 0)) {
      PoStartNextPowerIrp(param_2);
    }
    uVar10 = 0xc0000056;
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000056;
    IofCompleteRequest(param_2,0);
    puVar15 = auStackY_98;
    goto LAB_140007835;
  }
  pIVar18 = (IMAGE_DOS_HEADER *)0x43627355;
  puVar11 = (undefined4 *)ExAllocatePool2(0x40);
  if (puVar11 == (undefined4 *)0x0) {
LAB_1400077da:
    puVar16 = auStackY_98;
    ppuVar17 = &WPP_RECORDER_INITIALIZED;
    puVar13 = &WPP_b8ba6c0bda43381ffdf12cf14fa10529_Traceguids;
    puVar15 = auStackY_98;
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (puVar15 = auStackY_98, *(short *)(WPP_GLOBAL_Control + 0x48) != 0)) goto LAB_140007985;
  }
  else {
    *puVar11 = 0x6b636f4c;
    puVar11[6] = 0x44707249;
    *(longlong *)(puVar11 + 8) = param_2;
    KeAcquireInStackQueuedSpinLock(lVar21 + 0xf8,&local_58);
    ppuVar17 = (undefined **)(puVar11 + 2);
    plVar5 = *(longlong **)(lVar21 + 0xf0);
    if ((undefined *)*plVar5 == (undefined *)(lVar21 + 0xe8)) {
      *(longlong **)(puVar11 + 4) = plVar5;
      *ppuVar17 = (undefined *)(lVar21 + 0xe8);
      *plVar5 = (longlong)ppuVar17;
      *(undefined ***)(lVar21 + 0xf0) = ppuVar17;
      KeReleaseInStackQueuedSpinLock(&local_58);
      goto LAB_1400077da;
    }
    puVar13 = (undefined *)0x3;
    pcVar7 = (code *)swi(0x29);
    (*pcVar7)();
    puVar16 = auStackY_90;
LAB_140007985:
    *(undefined4 *)(puVar16 + 0x38) = *(undefined4 *)(puVar16 + 0xb0);
    *(uint *)(puVar16 + 0x30) = uVar19;
    *(undefined8 *)(puVar16 + 0x28) = *(undefined8 *)(puVar16 + 0xa0);
    pIVar18 = (IMAGE_DOS_HEADER *)0x9;
    *(undefined **)(puVar16 + 0x20) = puVar13;
    uVar6 = *(undefined8 *)(lVar21 + 0x560);
    *(undefined8 *)(puVar16 + -8) = 0x1400079bf;
    WPP_RECORDER_SF_qdd(uVar6,5,9,0xb,*(undefined8 *)(puVar16 + 0x20),puVar16[0x28],puVar16[0x30],
                        puVar16[0x38]);
    puVar15 = puVar16;
  }
  uVar20 = (uint)bVar3;
  if (uVar19 == 0) {
    *(undefined8 *)(puVar15 + -8) = 0x140007833;
    uVar12 = USBC_Create(lVar4,param_2);
    uVar10 = (undefined4)uVar12;
  }
  else if (uVar20 == 0xf) {
    if (*(char *)(lVar4 + 4) == '\0') {
      *(undefined8 *)(puVar15 + -8) = 0x140007824;
      uVar10 = DispatchPdoInternalDeviceControl(lVar4 + 8,param_2,pIVar18);
    }
    else {
      *(undefined8 *)(puVar15 + -8) = 0x14000792e;
      uVar12 = DispatchFdoInternalDeviceControl(lVar4 + 8,param_2);
      uVar10 = (undefined4)uVar12;
    }
  }
  else if (uVar20 == 2) {
    if (*(char *)(lVar4 + 4) == '\0') {
      lVar4 = *(longlong *)(lVar4 + 0xf0);
      uVar10 = 0xc00000bb;
      *(undefined8 *)(puVar15 + -8) = 0x1400078aa;
      UsbcCompleteIrp(lVar4,0xc00000bb,param_2);
    }
    else {
      uVar6 = *(undefined8 *)(lVar4 + 0x30);
      *(undefined8 *)(puVar15 + -8) = 0x140007888;
      uVar12 = UsbcForwardIrp(lVar4 + 8,uVar6,param_2);
      uVar10 = (undefined4)uVar12;
    }
  }
  else if (uVar20 == 0xe) {
    *(undefined8 *)(puVar15 + -8) = 0x140007910;
    uVar12 = USBC_DeviceControl(lVar4,param_2);
    uVar10 = (undefined4)uVar12;
  }
  else if (uVar20 == 0x16) {
    *(undefined8 *)(puVar15 + -8) = 0x1400078e1;
    uVar10 = USBC_Power(lVar4,param_2,pIVar18);
  }
  else if (uVar20 == 0x17) {
    *(undefined8 *)(puVar15 + -8) = 0x140007922;
    uVar12 = USBC_SystemControl(lVar4,param_2);
    uVar10 = (undefined4)uVar12;
  }
  else if (uVar20 == 0x1b) {
    *(undefined8 *)(puVar15 + -8) = 0x1400078cf;
    uVar10 = USBC_PnP(lVar4,param_2,pIVar18);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != ppuVar17) {
      *(uint *)(puVar15 + 0x28) = uVar20;
      *(undefined **)(puVar15 + 0x20) = &WPP_b8ba6c0bda43381ffdf12cf14fa10529_Traceguids;
      uVar6 = *(undefined8 *)(lVar21 + 0x560);
      *(undefined8 *)(puVar15 + -8) = 0x1400079f6;
      WPP_RECORDER_SF_L(uVar6,2,9,0xc,*(undefined8 *)(puVar15 + 0x20),puVar15[0x28]);
    }
    if (puVar15[0xa8] == '\0') {
      uVar10 = 0xc00000bb;
      *(undefined8 *)(puVar15 + -8) = 0x140007a22;
      UsbcCompleteIrp(lVar21,0xc00000bb,param_2);
    }
    else {
      uVar6 = *(undefined8 *)(lVar21 + 0x28);
      *(undefined8 *)(puVar15 + -8) = 0x140007a0f;
      uVar12 = UsbcForwardIrp(lVar21,uVar6,param_2);
      uVar10 = (undefined4)uVar12;
    }
  }
LAB_140007835:
  if (bVar8) {
    LOCK();
    piVar1 = (int *)(lVar14 + 0x134);
    iVar9 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar9 == 1) {
      *(undefined8 *)(puVar15 + -8) = 0x1400078fb;
      KeSetEvent(lVar14 + 0x138,0,0);
    }
  }
  return uVar10;
}



===== DispatchPdoInternalDeviceControl @ 140007ab0 =====

undefined4 DispatchPdoInternalDeviceControl(longlong param_1,longlong param_2,undefined8 param_3)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  uint uVar7;
  undefined8 in_stack_ffffffffffffffb8;
  undefined1 uVar8;
  undefined1 uVar9;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  iVar1 = *(int *)(param_1 + 0x14);
  uVar5 = 0;
  lVar4 = *(longlong *)(param_1 + 0xe8);
  uVar2 = *(uint *)(lVar3 + 0x18);
  uVar9 = (undefined1)param_2;
  uVar8 = (undefined1)uVar2;
  uVar7 = uVar2;
  if ((iVar1 == 2) || (iVar1 == 9)) {
    if (*(int *)(param_1 + 0x10) != 1) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qLqL
                  (*(undefined8 *)(param_1 + 0x188),param_2,param_3,0x28,in_stack_ffffffffffffffb8,
                   (char)*(undefined8 *)(param_1 + 0xe0),uVar8,uVar9,(char)*(int *)(param_1 + 0x10))
        ;
        uVar7 = *(uint *)(lVar3 + 0x18);
      }
      uVar5 = 0xc00002d3;
      goto LAB_140007ba1;
    }
    if ((*(int *)(lVar4 + 4) != 1) &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_qLqL
                (*(undefined8 *)(param_1 + 0x188),param_2,param_3,0x29,in_stack_ffffffffffffffb8,
                 (char)*(undefined8 *)(param_1 + 0xe0),uVar8,uVar9,(char)*(int *)(lVar4 + 4));
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qLqL
                (*(undefined8 *)(param_1 + 0x188),param_2,param_3,0x27,in_stack_ffffffffffffffb8,
                 (char)*(undefined8 *)(param_1 + 0xe0),uVar8,uVar9,(char)iVar1);
      uVar7 = *(uint *)(lVar3 + 0x18);
    }
    uVar5 = 0xc0000184;
LAB_140007ba1:
    if (uVar7 == 0x220003) {
      if ((*(longlong *)(lVar3 + 8) == 0) || (*(short *)(*(longlong *)(lVar3 + 8) + 2) != 0x36))
      goto LAB_140007bb9;
    }
    else if (uVar7 != 0x49104b) {
LAB_140007bb9:
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqd(*(undefined8 *)(param_1 + 0x188),2,8,0x2a,
                            &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,
                            (char)*(undefined8 *)(param_1 + 0xe0),uVar9,(char)uVar5);
      }
      UsbcCompleteIrp(lVar4,uVar5,param_2);
      return uVar5;
    }
  }
  if (*(longlong *)(param_1 + 0x178) == 0) {
LAB_140007b2c:
    if (uVar2 == 0x220003) {
      uVar6 = DispatchPdoUrb(param_1,param_2);
      return (int)uVar6;
    }
    if (uVar2 < 0x220020) {
      if (uVar2 == 0x22001f) {
        if (*(char *)(lVar4 + 0x568) == '\x01') {
          *(undefined1 *)(param_1 + 0x197) = 1;
          IoInvalidateDeviceState(*(undefined8 *)(param_1 + 0xe0));
          UsbcDbgBreak(*(undefined8 *)(lVar4 + 0x10));
          UsbcCompleteIrp(lVar4,0xc0000001,param_2);
          return 0xc0000001;
        }
        goto LAB_140007e20;
      }
      if (uVar2 == 0x220007) goto LAB_140007da8;
      if ((((uVar2 != 0x22000f) && (uVar2 == 0x220013)) && (*(char *)(param_1 + 0x194) == '\x01'))
         && (*(char *)(param_1 + 0x195) == '\x01')) {
        **(undefined4 **)(lVar3 + 8) = 3;
        UsbcCompleteIrp(lVar4,0,param_2);
        return 0;
      }
    }
    else {
      if (uVar2 == 0x220027) goto LAB_140007b77;
      if (uVar2 == 0x220fb3) {
LAB_140007da8:
        if (*(char *)(lVar4 + 0x568) == '\x01') {
          if ((*(char *)(lVar4 + 0x25c) == '\0') && (*(char *)(param_1 + 0x195) == '\x01')) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x188),4,2,0x2b,
                                &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,
                                (char)*(undefined8 *)(param_1 + 0xe0));
            }
            *(undefined2 *)(param_1 + 0x195) = 0;
            UsbcCompleteIrp(lVar4,uVar5,param_2);
            return uVar5;
          }
          *(undefined1 *)(param_1 + 0x196) = 1;
        }
LAB_140007e20:
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x188),4,2,0x2c,
                            &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,
                            (char)*(undefined8 *)(param_1 + 0xe0));
        }
        uVar6 = UsbcForwardIrp(lVar4,*(undefined8 *)(lVar4 + 0x20),param_2);
        return (int)uVar6;
      }
    }
    uVar6 = UsbcForwardIrp(lVar4,*(undefined8 *)(lVar4 + 0x28),param_2);
    uVar5 = (undefined4)uVar6;
  }
  else {
    if (uVar2 != 0x220027) {
      *(longlong *)(lVar3 + 0x20) = *(longlong *)(param_1 + 0x178);
      goto LAB_140007b2c;
    }
LAB_140007b77:
    uVar6 = DispatchPdoIdleNotificationRequest(param_1,param_2);
    uVar5 = (undefined4)uVar6;
  }
  return uVar5;
}



===== UsbcForwardIrp @ 140007e80 =====

ulonglong UsbcForwardIrp(longlong param_1,undefined8 param_2,longlong param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  code *pcVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  *(char *)(param_3 + 0x43) = *(char *)(param_3 + 0x43) + '\x01';
  *(longlong *)(param_3 + 0xb8) = *(longlong *)(param_3 + 0xb8) + 0x48;
  uVar4 = IofCallDriver(param_2,param_3);
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeAcquireInStackQueuedSpinLock(param_1 + 0xf8,&local_28);
  puVar6 = *(undefined8 **)(param_1 + 0xe8);
  do {
    if (puVar6 == (undefined8 *)(param_1 + 0xe8)) {
LAB_140007f22:
      KeReleaseInStackQueuedSpinLock(&local_28);
      IoReleaseRemoveLockEx(param_1 + 200,param_3,0x20);
      return (ulonglong)uVar4;
    }
    puVar1 = (undefined8 *)*puVar6;
    if (puVar6[3] == param_3) {
      if (((undefined8 *)puVar1[1] != puVar6) ||
         (puVar2 = (undefined8 *)puVar6[1], (undefined8 *)*puVar2 != puVar6)) {
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        pcVar3 = (code *)swi(3);
        uVar5 = (*pcVar3)();
        return uVar5;
      }
      *puVar2 = puVar1;
      puVar1[1] = puVar2;
      ExFreePoolWithTag(puVar6 + -1,0x43627355);
      goto LAB_140007f22;
    }
    puVar6 = puVar1;
  } while( true );
}



===== DispatchPdoUrb @ 140007f80 =====

ulonglong DispatchPdoUrb(longlong param_1,longlong param_2)

{
  int *piVar1;
  byte bVar2;
  ushort uVar3;
  longlong lVar4;
  ushort *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  longlong lVar9;
  byte *pbVar10;
  undefined8 uVar11;
  code *pcVar12;
  undefined4 uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  undefined4 *puVar17;
  longlong *plVar18;
  ulonglong uVar19;
  undefined4 extraout_var;
  uint uVar20;
  longlong *plVar21;
  char cVar22;
  longlong lVar23;
  uint *puVar24;
  undefined1 *puVar25;
  uint uVar26;
  undefined8 unaff_R12;
  undefined8 unaff_R13;
  undefined1 auStackY_88 [8];
  undefined1 auStackY_80 [24];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  lVar4 = *(longlong *)(param_1 + 0xe8);
  puVar5 = *(ushort **)(*(longlong *)(param_2 + 0xb8) + 8);
  if (puVar5 == (ushort *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x188),2,8,0x20,
                        &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,
                        (char)*(undefined8 *)(param_1 + 0xe0));
    }
    UsbcCompleteIrp(lVar4,0xc000000d,param_2);
    return 0xc000000d;
  }
  uVar3 = puVar5[1];
  if (((*(char *)(param_1 + 0x194) == '\x01') && (*(char *)(param_1 + 0x195) == '\x01')) &&
     (1 < (ushort)(uVar3 - 0x35))) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x188),3,8,0x21,
                        &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,
                        (char)*(undefined8 *)(param_1 + 0xe0));
    }
    puVar5[2] = 0x11;
    puVar5[3] = 0xc000;
    UsbcCompleteIrp(lVar4,0xc0000001,param_2);
    return 0xc0000001;
  }
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  KeAcquireInStackQueuedSpinLock(lVar4 + 0x100,&local_48);
  if (*(int *)(lVar4 + 0xc) - 5U < 2) {
    KeReleaseInStackQueuedSpinLock(&local_48);
    uVar20 = 0xc0000184;
LAB_1400086b5:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(param_1 + 0x188),2,8,0x22,
                         &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,
                         (char)*(undefined8 *)(param_1 + 0xe0),(char)*(undefined4 *)(lVar4 + 0xc));
    }
    UsbcCompleteIrp(lVar4,uVar20,param_2);
    return (ulonglong)uVar20;
  }
  puVar17 = (undefined4 *)ExAllocatePool2(0x40,0x28,0x43627355);
  puVar25 = auStackY_88;
  if (puVar17 == (undefined4 *)0x0) {
    puVar25 = auStackY_88;
    if (*(char *)(lVar4 + 0x568) == '\0') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(g_RecorderLog,2,8,0x3a,&WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids);
      }
      KeReleaseInStackQueuedSpinLock(&local_48);
      uVar20 = 0xc000009a;
      goto LAB_1400086b5;
    }
  }
  else {
    *puVar17 = 0x6b636f4c;
    lVar23 = lVar4 + 0x108;
    puVar17[6] = 0x50555242;
    *(longlong *)(puVar17 + 8) = param_2;
    plVar18 = (longlong *)(puVar17 + 2);
    plVar21 = *(longlong **)(lVar4 + 0x110);
    if (*plVar21 != lVar23) {
      lVar23 = 3;
      pcVar12 = (code *)swi(0x29);
      plVar18 = (longlong *)(*pcVar12)();
      puVar25 = auStackY_80;
    }
    *plVar18 = lVar23;
    plVar18[1] = (longlong)plVar21;
    *plVar21 = (longlong)plVar18;
    *(longlong **)(lVar23 + 8) = plVar18;
  }
  LOCK();
  piVar1 = (int *)(lVar4 + 0x118);
  iVar16 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  if (iVar16 == 0) {
    *(undefined8 *)(puVar25 + -8) = 0x1400081a6;
    KeResetEvent(lVar4 + 0x120);
  }
  *(undefined8 *)(puVar25 + -8) = 0x1400081b7;
  KeReleaseInStackQueuedSpinLock(puVar25 + 0x40);
  if (uVar3 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar6 = *(undefined8 *)(param_1 + 0xe0);
      uVar7 = *(undefined8 *)(param_1 + 0x188);
      *(ushort **)(puVar25 + 0x30) = puVar5;
      *(undefined8 *)(puVar25 + 0x28) = uVar6;
      *(undefined **)(puVar25 + 0x20) = &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids;
      *(undefined8 *)(puVar25 + -8) = 0x140008690;
      WPP_RECORDER_SF_qq(uVar7,4,1,0x23,*(undefined8 *)(puVar25 + 0x20),puVar25[0x28],puVar25[0x30])
      ;
    }
    *(undefined8 *)(puVar25 + -8) = 0x14000869b;
    iVar16 = DispatchPdoUrbSelectConfiguration(param_1,param_2);
    return CONCAT44(extraout_var,iVar16);
  }
  uVar20 = (uint)uVar3;
  if (uVar20 == 1) {
LAB_14000844c:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar6 = *(undefined8 *)(param_1 + 0xe0);
      uVar7 = *(undefined8 *)(param_1 + 0x188);
      *(ushort **)(puVar25 + 0x30) = puVar5;
      *(undefined8 *)(puVar25 + 0x28) = uVar6;
      *(undefined **)(puVar25 + 0x20) = &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids;
      *(undefined8 *)(puVar25 + -8) = 0x140008491;
      WPP_RECORDER_SF_qq(uVar7,4,1,0x25,*(undefined8 *)(puVar25 + 0x20),puVar25[0x28],puVar25[0x30])
      ;
    }
    if (uVar3 != 1) {
      cVar22 = (char)puVar5[0x19];
    }
    else {
      cVar22 = (char)puVar5[0x11];
    }
    uVar20 = *(uint *)(param_1 + 0xc);
    lVar23 = 0x20;
    if (uVar3 != 1) {
      lVar23 = 0x30;
    }
    plVar21 = *(longlong **)(*(longlong *)(param_1 + 0xf0) + 8);
    uVar14 = 0;
    if (uVar20 != 0) {
      *(undefined8 *)(puVar25 + 0xa0) = unaff_R12;
      *(undefined8 *)(puVar25 + 0xa8) = unaff_R13;
      do {
        puVar8 = (undefined8 *)*plVar21;
        lVar9 = puVar8[1];
        if (*(char *)(lVar9 + 2) == cVar22) {
          uVar20 = *(uint *)(lVar9 + 0x10);
          *(undefined8 *)(puVar25 + -8) = 0x140008508;
          uVar19 = Feature_2793828664__private_IsEnabledDeviceUsageNoInline();
          if ((int)uVar19 != 0) {
            uVar14 = 0;
            uVar26 = 0;
            uVar15 = (uint)*(ushort *)(lVar23 + (longlong)puVar5);
            if (0x17 < uVar15) {
              uVar14 = (uVar15 - 0x18) / 0x18;
            }
            uVar15 = 0x38;
            if (*(short *)(puVar25 + 0x90) != 1) {
              uVar15 = 0x48;
            }
            if (uVar15 <= *puVar5) {
              uVar26 = (*puVar5 - uVar15) / 0x18;
            }
            if (uVar20 <= uVar14) {
              uVar14 = uVar20;
            }
            uVar20 = uVar14;
            if (uVar26 < uVar14) {
              uVar20 = uVar26;
            }
          }
          uVar14 = 0;
          if (uVar20 != 0) {
            puVar24 = (uint *)((ushort *)(lVar23 + (longlong)puVar5) + 0x16);
            do {
              pbVar10 = (byte *)*puVar8;
              *(undefined4 *)(puVar25 + 0x90) = 0;
              *(undefined8 *)(puVar25 + -8) = 0x14000859e;
              uVar19 = GetEndpointPriority(param_1,pbVar10,uVar14,(undefined4 *)(puVar25 + 0x90));
              if (-1 < (int)uVar19) {
                iVar16 = *(int *)(puVar25 + 0x90);
                if (iVar16 == 1) {
                  *puVar24 = *puVar24 | 0x10;
                }
                else if (iVar16 == 2) {
                  *puVar24 = *puVar24 | 0x20;
                }
                else if (iVar16 == 3) {
                  *puVar24 = *puVar24 | 0x30;
                }
              }
              uVar14 = uVar14 + 1;
              puVar24 = puVar24 + 6;
            } while (uVar14 < uVar20);
          }
          break;
        }
        uVar14 = uVar14 + 1;
        plVar21 = plVar21 + 1;
      } while (uVar14 < uVar20);
    }
    puVar8 = *(undefined8 **)(param_2 + 0xb8);
    uVar6 = *(undefined8 *)(param_1 + 0xe0);
    uVar7 = *(undefined8 *)(lVar4 + 0x28);
    *(longlong *)(puVar25 + 0x20) = param_1;
    puVar8[-9] = *puVar8;
    puVar8[-8] = puVar8[1];
    puVar8[-7] = puVar8[2];
    puVar8[-6] = puVar8[3];
    puVar8[-5] = puVar8[4];
    puVar8[-4] = puVar8[5];
    puVar8[-3] = puVar8[6];
    *(undefined1 *)((longlong)puVar8 + -0x45) = 0;
    uVar11 = *(undefined8 *)(lVar4 + 0x560);
    *(undefined8 *)(puVar25 + -8) = 0x140008632;
    SetCompletionRoutine
              (uVar11,uVar6,param_2,CompletionPdoSelectInterface,*(undefined8 *)(puVar25 + 0x20));
    *(undefined8 *)(puVar25 + -8) = 0x14000863f;
    uVar19 = IofCallDriver(uVar7,param_2);
    return uVar19;
  }
  if (uVar20 != 0xb) {
    if (uVar20 != 0x3b) {
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        uVar6 = *(undefined8 *)(param_1 + 0x188);
        *(uint *)(puVar25 + 0x28) = uVar20;
        *(undefined **)(puVar25 + 0x20) = &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids;
        *(undefined8 *)(puVar25 + -8) = 0x140008223;
        WPP_RECORDER_SF_L(uVar6,5,4,0x26,*(undefined8 *)(puVar25 + 0x20),puVar25[0x28]);
      }
      uVar6 = *(undefined8 *)(lVar4 + 0x28);
      *(undefined8 *)(puVar25 + -8) = 0x140008232;
      uVar19 = UsbcForwardIrp(lVar4,uVar6,param_2);
      *(undefined8 *)(puVar25 + -8) = 0x14000823f;
      UsbcDecrementPendingCount(lVar4,param_2);
      return uVar19 & 0xffffffff;
    }
    goto LAB_14000844c;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar6 = *(undefined8 *)(param_1 + 0xe0);
    uVar7 = *(undefined8 *)(param_1 + 0x188);
    *(ushort **)(puVar25 + 0x30) = puVar5;
    *(undefined8 *)(puVar25 + 0x28) = uVar6;
    *(undefined **)(puVar25 + 0x20) = &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids;
    *(undefined8 *)(puVar25 + -8) = 0x140008299;
    WPP_RECORDER_SF_qq(uVar7,5,1,0x24,*(undefined8 *)(puVar25 + 0x20),puVar25[0x28],puVar25[0x30]);
  }
  lVar4 = *(longlong *)(param_1 + 0xe8);
  lVar23 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  bVar2 = *(byte *)(lVar23 + 0x83);
  if (bVar2 == 1) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar6 = *(undefined8 *)(lVar4 + 0x560);
      *(undefined8 *)(puVar25 + 0x28) = *(undefined8 *)(param_1 + 0xe0);
      *(undefined **)(puVar25 + 0x20) = &WPP_fc1b814fd1aa3eaffd95e56bc3961d1e_Traceguids;
      *(undefined8 *)(puVar25 + -8) = 0x1400083f4;
      WPP_RECORDER_SF_q(uVar6,4,1,0x1b,*(undefined8 *)(puVar25 + 0x20),puVar25[0x28]);
    }
    if (*(uint *)(lVar23 + 0x24) < 0x12) {
      uVar19 = 0xc0000206;
      uVar13 = 0x80000000;
    }
    else {
      puVar8 = *(undefined8 **)(lVar23 + 0x28);
      uVar13 = 0;
      uVar6 = *(undefined8 *)(param_1 + 0x108);
      uVar19 = 0;
      *puVar8 = *(undefined8 *)(param_1 + 0x100);
      puVar8[1] = uVar6;
      *(undefined2 *)(puVar8 + 2) = *(undefined2 *)(param_1 + 0x110);
    }
    *(undefined4 *)(lVar23 + 0x24) = 0x12;
  }
  else {
    if (bVar2 != 2) {
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        uVar6 = *(undefined8 *)(param_1 + 0xe0);
        uVar7 = *(undefined8 *)(lVar4 + 0x560);
        *(uint *)(puVar25 + 0x30) = (uint)bVar2;
        *(undefined8 *)(puVar25 + 0x28) = uVar6;
        *(undefined **)(puVar25 + 0x20) = &WPP_fc1b814fd1aa3eaffd95e56bc3961d1e_Traceguids;
        *(undefined8 *)(puVar25 + -8) = 0x14000830d;
        WPP_RECORDER_SF_qd(uVar7,5,1,0x1d,*(undefined8 *)(puVar25 + 0x20),puVar25[0x28],
                           puVar25[0x30]);
      }
      lVar23 = *(longlong *)(param_1 + 0xe8);
      uVar6 = *(undefined8 *)(lVar23 + 0x28);
      *(undefined8 *)(puVar25 + -8) = 0x140008320;
      uVar19 = UsbcForwardIrp(lVar23,uVar6,param_2);
      *(undefined8 *)(puVar25 + -8) = 0x14000832d;
      UsbcDecrementPendingCount(lVar4,param_2);
      return uVar19 & 0xffffffff;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar6 = *(undefined8 *)(lVar4 + 0x560);
      *(undefined8 *)(puVar25 + 0x28) = *(undefined8 *)(param_1 + 0xe0);
      *(undefined **)(puVar25 + 0x20) = &WPP_fc1b814fd1aa3eaffd95e56bc3961d1e_Traceguids;
      *(undefined8 *)(puVar25 + -8) = 0x14000836d;
      WPP_RECORDER_SF_q(uVar6,4,1,0x1c,*(undefined8 *)(puVar25 + 0x20),puVar25[0x28]);
    }
    uVar20 = *(uint *)(lVar23 + 0x24);
    pbVar10 = *(byte **)(lVar23 + 0x28);
    *(undefined8 *)(puVar25 + -8) = 0x140008381;
    uVar19 = BuildFunctionConfigurationDescriptor(param_1,pbVar10,uVar20,(uint *)(lVar23 + 0x24));
    iVar16 = (int)uVar19;
    uVar19 = uVar19 & 0xffffffff;
    if (iVar16 == -0x80000000) goto LAB_14000842d;
    if (iVar16 == -0x3ffffff3) {
      *(undefined4 *)(lVar23 + 4) = 0x80000300;
      goto LAB_14000842d;
    }
    if (iVar16 != 0) {
      uVar13 = 0x40000000;
      if (iVar16 != 0x103) {
        uVar13 = 0x80000000;
      }
      *(undefined4 *)(lVar23 + 4) = uVar13;
      goto LAB_14000842d;
    }
    uVar13 = 0;
  }
  *(undefined4 *)(lVar23 + 4) = uVar13;
LAB_14000842d:
  *(undefined8 *)(puVar25 + -8) = 0x14000843a;
  UsbcCompleteIrp(lVar4,(int)uVar19,param_2);
  *(undefined8 *)(puVar25 + -8) = 0x140008445;
  UsbcDecrementPendingCount(lVar4,param_2);
  return uVar19;
}



===== UsbcCompleteIrp @ 140008720 =====

void UsbcCompleteIrp(longlong param_1,undefined4 param_2,longlong param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  code *pcVar3;
  undefined8 *puVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  *(undefined4 *)(param_3 + 0x30) = param_2;
  IofCompleteRequest(param_3,0);
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLock(param_1 + 0xf8,&local_28);
  puVar4 = *(undefined8 **)(param_1 + 0xe8);
  do {
    if (puVar4 == (undefined8 *)(param_1 + 0xe8)) {
LAB_1400087af:
      KeReleaseInStackQueuedSpinLock(&local_28);
      IoReleaseRemoveLockEx(param_1 + 200,param_3,0x20);
      return;
    }
    puVar1 = (undefined8 *)*puVar4;
    if (puVar4[3] == param_3) {
      if (((undefined8 *)puVar1[1] != puVar4) ||
         (puVar2 = (undefined8 *)puVar4[1], (undefined8 *)*puVar2 != puVar4)) {
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      *puVar2 = puVar1;
      puVar1[1] = puVar2;
      ExFreePoolWithTag(puVar4 + -1,0x43627355);
      goto LAB_1400087af;
    }
    puVar4 = puVar1;
  } while( true );
}



===== BuildFunctionConfigurationDescriptor @ 1400087fc =====

undefined8
BuildFunctionConfigurationDescriptor(longlong param_1,byte *param_2,uint param_3,uint *param_4)

{
  byte *pbVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  undefined8 *puVar5;
  byte bVar6;
  byte *pbVar7;
  ulonglong _Size;
  undefined8 *puVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  void *_Dst;
  ushort uVar11;
  ushort uVar12;
  void *local_res8;
  byte *local_48;
  ulonglong uStack_40;
  
  lVar2 = *(longlong *)(param_1 + 0xe8);
  lVar3 = *(longlong *)(param_1 + 0xf0);
  if ((param_3 < 9) || (param_2 == (byte *)0x0)) {
    *param_4 = 0;
    return 0xc0000206;
  }
  puVar8 = *(undefined8 **)(lVar2 + 0x38);
  uVar12 = 9;
  local_48 = (byte *)((ulonglong)*(ushort *)((longlong)puVar8 + 2) + (longlong)puVar8);
  if (*(uint *)(param_1 + 0xc) != 0) {
    puVar5 = *(undefined8 **)(lVar3 + 8);
    uVar10 = (ulonglong)*(uint *)(param_1 + 0xc);
    do {
      pbVar7 = *(byte **)*puVar5;
      pbVar1 = pbVar7 + 2;
      while( true ) {
        bVar6 = *pbVar7;
        if (bVar6 < 2) break;
        if ((pbVar7[1] != 0xb) || ((*(uint *)(lVar2 + 0x4d0) & 2) != 0)) {
          uVar12 = uVar12 + bVar6;
        }
        pbVar7 = pbVar7 + bVar6;
        if ((local_48 <= pbVar7) || ((pbVar7[1] == 4 && (pbVar7[2] != *pbVar1)))) break;
      }
      puVar5 = puVar5 + 1;
      uVar10 = uVar10 - 1;
    } while (uVar10 != 0);
  }
  puVar5 = (undefined8 *)ExAllocatePool2(0x40,uVar12,0x43627355);
  if (puVar5 == (undefined8 *)0x0) {
    uVar9 = 0xc000009a;
  }
  else {
    if (8 < uVar12) {
      _Dst = (void *)((longlong)puVar5 + 9);
      *puVar5 = *puVar8;
      uVar11 = uVar12 - 9;
      *(undefined1 *)(puVar5 + 1) = *(undefined1 *)(puVar8 + 1);
      local_res8 = _Dst;
      for (uVar10 = 0; (uint)uVar10 < *(uint *)(param_1 + 0xc);
          uVar10 = (ulonglong)((uint)uVar10 + 1)) {
        pbVar1 = (byte *)**(undefined8 **)(*(longlong *)(lVar3 + 8) + uVar10 * 8);
        pbVar7 = pbVar1;
        while( true ) {
          bVar6 = *pbVar7;
          _Size = (ulonglong)bVar6;
          if (bVar6 < 2) break;
          if ((pbVar7[1] != 0xb) || ((*(uint *)(lVar2 + 0x4d0) & 2) != 0)) {
            if (uVar11 < bVar6) goto LAB_140008acb;
            memmove(_Dst,pbVar7,_Size);
            _Size = (ulonglong)*pbVar7;
            _Dst = (void *)((longlong)local_res8 + _Size);
            uVar11 = uVar11 - *pbVar7;
            local_res8 = _Dst;
          }
          pbVar7 = pbVar7 + _Size;
          if ((local_48 <= pbVar7) || ((pbVar7[1] == 4 && (pbVar7[2] != pbVar1[2])))) break;
        }
      }
      *(undefined1 *)((longlong)puVar5 + 4) = *(undefined1 *)(param_1 + 0xc);
      *(ushort *)((longlong)puVar5 + 2) = uVar12;
      if (*(char *)(*(longlong *)(param_1 + 0xe8) + 0x55a) != '\0') {
        if (*(char *)(*(longlong *)(param_1 + 0x180) + 0x39) == '\0') {
          bVar6 = *(byte *)((longlong)puVar5 + 7) & 0xdf;
        }
        else {
          bVar6 = *(byte *)((longlong)puVar5 + 7) | 0x20;
        }
        *(byte *)((longlong)puVar5 + 7) = bVar6;
      }
      uVar4 = (uint)uVar12;
      if (param_3 <= uVar12) {
        uVar4 = param_3;
      }
      uVar10 = (ulonglong)uVar4;
      *param_4 = uVar4;
      puVar8 = puVar5;
      memmove(param_2,puVar5,uVar10);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uStack_40 = (ulonglong)(ushort)*param_4;
        local_48 = param_2;
        WPP_RECORDER_SF__HEX_
                  (*(undefined8 *)(lVar2 + 0x560),puVar8,uVar10,0x1a,
                   &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,&local_48);
      }
      uVar9 = 0;
      goto LAB_1400089ba;
    }
LAB_140008acb:
    uVar9 = 0xc000009c;
  }
  *param_4 = 0;
  if (puVar5 == (undefined8 *)0x0) {
    return uVar9;
  }
LAB_1400089ba:
  ExFreePoolWithTag(puVar5,0x43627355);
  return uVar9;
}



===== USBC_Power @ 140008ad8 =====

void USBC_Power(longlong param_1,longlong param_2,undefined8 param_3)

{
  undefined8 in_stack_ffffffffffffffc8;
  
  if (*(char *)(param_1 + 4) == '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qcqLL
                (*(undefined8 *)(param_1 + 400),4,param_3,0xe,in_stack_ffffffffffffffc8,
                 (char)*(undefined8 *)(param_1 + 0xe8),
                 *(undefined1 *)(*(longlong *)(param_2 + 0xb8) + 1),(char)param_2,
                 (char)*(undefined4 *)(param_1 + 0x1c),(char)*(undefined4 *)(param_1 + 0x18));
    }
    DispatchPdoPower(param_1 + 8,param_2);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qcqLL
                (*(undefined8 *)(param_1 + 0x568),4,param_3,0xd,in_stack_ffffffffffffffc8,
                 (char)*(undefined8 *)(param_1 + 0x28),
                 *(undefined1 *)(*(longlong *)(param_2 + 0xb8) + 1),(char)param_2,
                 (char)*(undefined4 *)(param_1 + 0x14),(char)*(undefined4 *)(param_1 + 0xc));
    }
    DispatchFdoPower(param_1 + 8,param_2,param_3);
  }
  return;
}



===== DispatchPdoPower @ 140008bb8 =====

int DispatchPdoPower(longlong param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  ulonglong uVar5;
  undefined2 uVar6;
  undefined8 in_stack_ffffffffffffffd8;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  iVar4 = 0;
  lVar3 = *(longlong *)(param_1 + 0xe8);
  cVar1 = *(char *)(lVar2 + 1);
  if (cVar1 == '\0') {
    uVar5 = DispatchPdoWaitWake(param_1,param_2);
    iVar4 = (int)uVar5;
    goto LAB_140008c02;
  }
  if (cVar1 == '\x01') {
LAB_140008bf0:
    iVar4 = *(int *)(param_2 + 0x30);
  }
  else {
    if (cVar1 == '\x02') {
      uVar5 = DispatchPdoSetPower(param_1,param_2,lVar2);
      iVar4 = (int)uVar5;
      if (iVar4 == 0x103) goto LAB_140008c02;
      goto LAB_140008bf3;
    }
    if (cVar1 != '\x03') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(lVar3 + 0x560),4,3,0x28,
                           &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,(char)param_2,cVar1);
      }
      goto LAB_140008bf0;
    }
    if (*(int *)(lVar2 + 0x10) == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar6 = 0x26;
LAB_140008c5a:
        WPP_RECORDER_SF_qqL(*(undefined8 *)(param_1 + 0x188),1,lVar2,uVar6,in_stack_ffffffffffffffd8
                            ,(char)*(undefined8 *)(param_1 + 0xe0),(char)param_2,
                            (char)*(undefined4 *)(lVar2 + 0x18));
      }
    }
    else if ((*(int *)(lVar2 + 0x10) == 1) &&
            ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      uVar6 = 0x27;
      goto LAB_140008c5a;
    }
  }
LAB_140008bf3:
  PoStartNextPowerIrp(param_2);
LAB_140008c02:
  if (iVar4 != 0x103) {
    *(int *)(param_2 + 0x30) = iVar4;
    IofCompleteRequest(param_2,0);
    UsbcReleaseRemoveLock(lVar3,param_2);
    IoReleaseRemoveLockEx(lVar3 + 200,param_2,0x20);
  }
  return iVar4;
}



===== DispatchFdoPower @ 140008d48 =====

undefined4 DispatchFdoPower(longlong param_1,longlong param_2,undefined8 param_3)

{
  char cVar1;
  longlong lVar2;
  undefined4 uVar3;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    param_3 = 3;
    WPP_RECORDER_SF_qq(*(undefined8 *)(param_1 + 0x560),5,3,10,
                       &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                       (char)*(undefined8 *)(param_1 + 0x20),(char)param_2);
  }
  if (*(int *)(param_1 + 0xc) == 0) {
    PoStartNextPowerIrp(param_2);
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    uVar3 = PoCallDriver(*(undefined8 *)(param_1 + 0x28),param_2);
    UsbcReleaseRemoveLock(param_1,param_2);
    IoReleaseRemoveLockEx(param_1 + 200,param_2,0x20);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(param_1 + 0x560),4,3,0xb,
                         &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                         (char)*(undefined8 *)(param_1 + 0x20),(char)param_2);
    }
  }
  else {
    cVar1 = *(char *)(lVar2 + 1);
    if (cVar1 == '\0') {
      uVar3 = DispatchFdoWaitWake(param_1,param_2);
    }
    else if (cVar1 == '\x02') {
      uVar3 = DispatchFdoSetPower(param_1,param_2,param_3);
    }
    else {
      if (cVar1 != '\x03') {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qd(*(undefined8 *)(param_1 + 0x560),4,3,0xc,
                             &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                             (char)*(undefined8 *)(param_1 + 0x20),cVar1);
        }
        PoStartNextPowerIrp(param_2);
        *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
        *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
        uVar3 = PoCallDriver(*(undefined8 *)(param_1 + 0x28),param_2);
        UsbcReleaseRemoveLock(param_1,param_2);
        IoReleaseRemoveLockEx(param_1 + 200,param_2,0x20);
        return uVar3;
      }
      uVar3 = DispatchFdoQueryPower(param_1,param_2,param_3);
    }
  }
  return uVar3;
}



===== DispatchFdoSetPower @ 140008f50 =====

undefined4 DispatchFdoSetPower(longlong param_1,longlong param_2,undefined8 param_3)

{
  byte *pbVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined8 uVar7;
  longlong lVar8;
  bool bVar9;
  undefined8 in_stack_ffffffffffffffc8;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  uVar5 = 0;
  uVar4 = (undefined1)param_2;
  if (*(int *)(lVar2 + 0x10) == 0) {
    lVar8 = param_2;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqL(*(undefined8 *)(param_1 + 0x560),param_2,param_3,0x30,
                          in_stack_ffffffffffffffc8,(char)*(undefined8 *)(param_1 + 0x20),uVar4,
                          (char)*(undefined4 *)(lVar2 + 0x18));
    }
    if (*(int *)(lVar2 + 0x18) != 1) {
      uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x158);
      uVar6 = *(uint *)(param_1 + 0x4d4);
      if ((uVar6 & 4) != 0) {
        uVar6 = uVar6 & 0xfffffffb | 1;
        *(uint *)(param_1 + 0x4d4) = uVar6;
      }
      bVar9 = (uVar6 & 1) == 0;
      if (bVar9) {
        *(uint *)(param_1 + 0x4d4) = uVar6 | 1;
      }
      uVar7 = CONCAT71((int7)((ulonglong)lVar8 >> 8),uVar4);
      KeReleaseSpinLock(param_1 + 0x158);
      if (bVar9) {
        DisableIdleTimer(param_1,uVar7,0x50535054);
      }
      CancelFdoIdleIrp(param_1,CONCAT71((int7)((ulonglong)uVar7 >> 8),1));
    }
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(lVar2 + 0x18);
    puVar3 = *(undefined8 **)(param_2 + 0xb8);
    puVar3[-9] = *puVar3;
    puVar3[-8] = puVar3[1];
    puVar3[-7] = puVar3[2];
    puVar3[-6] = puVar3[3];
    puVar3[-5] = puVar3[4];
    puVar3[-4] = puVar3[5];
    puVar3[-3] = puVar3[6];
    *(undefined1 *)((longlong)puVar3 + -0x45) = 0;
    SetCompletionRoutine
              (*(undefined8 *)(param_1 + 0x560),*(undefined8 *)(param_1 + 0x20),param_2,
               CompletionFdoSystemSetPower,param_1);
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    PoCallDriver(*(undefined8 *)(param_1 + 0x28),param_2);
    uVar5 = 0x103;
  }
  else if (*(int *)(lVar2 + 0x10) == 1) {
    uVar6 = *(uint *)(lVar2 + 0x18);
    if (uVar6 == 1) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qq(*(undefined8 *)(param_1 + 0x560),2,3,0x31,
                           &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                           (char)*(undefined8 *)(param_1 + 0x20),uVar4);
      }
    }
    else {
      if (uVar6 == 2) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qq(*(undefined8 *)(param_1 + 0x560),2,3,0x32,
                             &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                             (char)*(undefined8 *)(param_1 + 0x20),uVar4);
        }
        PoSetPowerState(*(undefined8 *)(param_1 + 0x20),*(undefined4 *)(lVar2 + 0x10),
                        *(undefined4 *)(lVar2 + 0x18));
        *(undefined4 *)(param_1 + 4) = 2;
      }
      else if (uVar6 == 3) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qq(*(undefined8 *)(param_1 + 0x560),2,3,0x33,
                             &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                             (char)*(undefined8 *)(param_1 + 0x20),uVar4);
        }
        PoSetPowerState(*(undefined8 *)(param_1 + 0x20),*(undefined4 *)(lVar2 + 0x10),
                        *(undefined4 *)(lVar2 + 0x18));
        *(undefined4 *)(param_1 + 4) = 3;
      }
      else if (uVar6 == 4) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qq(*(undefined8 *)(param_1 + 0x560),2,3,0x34,
                             &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                             (char)*(undefined8 *)(param_1 + 0x20),uVar4);
        }
        PoSetPowerState(*(undefined8 *)(param_1 + 0x20),*(undefined4 *)(lVar2 + 0x10),
                        *(undefined4 *)(lVar2 + 0x18));
        *(undefined4 *)(param_1 + 4) = 4;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qqL(*(undefined8 *)(param_1 + 0x560),(ulonglong)uVar6,param_3,0x35,
                              in_stack_ffffffffffffffc8,(char)*(undefined8 *)(param_1 + 0x20),uVar4,
                              (char)uVar6);
        }
        *(undefined4 *)(param_1 + 4) = *(undefined4 *)(lVar2 + 0x18);
      }
      *(undefined4 *)(param_1 + 0x240) = 1;
    }
    puVar3 = *(undefined8 **)(param_2 + 0xb8);
    puVar3[-9] = *puVar3;
    puVar3[-8] = puVar3[1];
    puVar3[-7] = puVar3[2];
    puVar3[-6] = puVar3[3];
    puVar3[-5] = puVar3[4];
    puVar3[-4] = puVar3[5];
    puVar3[-3] = puVar3[6];
    *(undefined1 *)((longlong)puVar3 + -0x45) = 0;
    SetCompletionRoutine
              (*(undefined8 *)(param_1 + 0x560),*(undefined8 *)(param_1 + 0x20),param_2,
               CompletionFdoDeviceSetPower,param_1);
    uVar5 = PoCallDriver(*(undefined8 *)(param_1 + 0x28),param_2);
  }
  return uVar5;
}



===== WPP_RECORDER_SF_qcqLL @ 140009350 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qcqLL
               (undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) &&
     (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_b8ba6c0bda43381ffdf12cf14fa10529_Traceguids,param_4,&param_6,8,&param_7,1,
               &param_8,8,&param_9,4,&param_10,4,0);
  }
  WppAutoLogTrace(param_1,param_2,9,&WPP_b8ba6c0bda43381ffdf12cf14fa10529_Traceguids,param_4,
                  &param_6,8,&param_7,1,&param_8,8,&param_9,4,&param_10,4,0);
  return;
}



===== WPP_RECORDER_SF__HEX_ @ 1400094d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF__HEX_
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined8 *param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,param_6 + 1,2,
               *param_6,(longlong)*(short *)(param_6 + 1),0);
  }
  WppAutoLogTrace(param_1,4,1,param_5,param_4,param_6 + 1,2,*param_6,
                  (longlong)*(short *)(param_6 + 1),0);
  return;
}



===== DispatchPdoUrbSelectConfiguration @ 1400095b8 =====

int DispatchPdoUrbSelectConfiguration(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  ushort uVar2;
  longlong lVar3;
  longlong lVar4;
  ushort *puVar5;
  longlong lVar6;
  undefined8 *puVar7;
  longlong lVar8;
  int iVar9;
  undefined4 uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  undefined1 uVar13;
  uint uVar14;
  ulonglong uVar15;
  byte bVar16;
  ushort uVar17;
  uint *puVar18;
  undefined2 uVar19;
  ushort *_Dst;
  uint local_res8;
  int local_res18 [2];
  uint local_res20;
  undefined *in_stack_ffffffffffffff58;
  
  iVar9 = 0;
  local_res8 = 0;
  lVar3 = *(longlong *)(param_1 + 0xf0);
  lVar4 = *(longlong *)(param_1 + 0xe8);
  puVar5 = *(ushort **)(*(longlong *)(param_2 + 0xb8) + 8);
  if (*(longlong *)(puVar5 + 0xc) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(lVar4 + 0x560),4,1,0xf,
                        &WPP_fc1b814fd1aa3eaffd95e56bc3961d1e_Traceguids,
                        (char)*(undefined8 *)(param_1 + 0xe0));
    }
    goto LAB_1400097f1;
  }
  uVar2 = *puVar5;
  if (0x3f < uVar2) {
    _Dst = puVar5 + 0x14;
    uVar14 = 0;
LAB_14000963f:
    if ((ushort *)((longlong)puVar5 + (ulonglong)uVar2) <= _Dst) goto LAB_1400097e3;
    if ((*_Dst < 0x18) ||
       ((ushort *)((longlong)puVar5 + (ulonglong)uVar2) <
        (ushort *)((ulonglong)*_Dst + (longlong)_Dst))) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar19 = 0x11;
LAB_1400099d2:
        iVar9 = -0x3ffffff3;
        WPP_RECORDER_SF_(*(undefined8 *)(lVar4 + 0x560),2,8,uVar19,
                         &WPP_fc1b814fd1aa3eaffd95e56bc3961d1e_Traceguids);
        goto LAB_1400099f1;
      }
    }
    else {
      lVar6 = *(longlong *)(lVar3 + 8);
      if (lVar6 == 0) goto LAB_1400097e3;
      uVar12 = (ulonglong)*(uint *)(param_1 + 0xc);
      uVar15 = 0;
      while( true ) {
        if (*(uint *)(param_1 + 0xc) <= (uint)uVar15) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14000982d;
          uVar19 = 0x12;
          goto LAB_1400099d2;
        }
        puVar7 = *(undefined8 **)(lVar6 + uVar15 * 8);
        lVar8 = puVar7[1];
        if (*(char *)(lVar8 + 2) == (char)_Dst[1]) break;
        uVar15 = (ulonglong)((uint)uVar15 + 1);
      }
      local_res20 = uVar14 + 1;
      if (*(char *)(lVar8 + 3) != *(char *)((longlong)_Dst + 3)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_DDD(*(undefined8 *)(lVar4 + 0x560));
        }
        uVar17 = _Dst[8] * 0x18 + 0x38;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar1 = (undefined1)_Dst[1];
          uVar19 = 0x14;
          uVar13 = *(undefined1 *)((longlong)_Dst + 3);
          bVar16 = 4;
LAB_14000990e:
          WPP_RECORDER_SF_qqdd
                    (*(undefined8 *)(lVar4 + 0x560),bVar16,uVar12,uVar19,in_stack_ffffffffffffff58,
                     (char)*(undefined8 *)(param_1 + 0xe0),(char)puVar5,uVar13,uVar1);
        }
LAB_140009752:
        local_res18[0] = 0;
        if (local_res8 != 0) {
          uVar14 = 0;
          puVar18 = (uint *)(_Dst + 0x16);
          do {
            local_res18[0] = 0;
            uVar12 = GetEndpointPriority(param_1,(byte *)*puVar7,uVar14,local_res18);
            if (-1 < (int)uVar12) {
              if (local_res18[0] == 1) {
                *puVar18 = *puVar18 | 0x10;
              }
              else if (local_res18[0] == 2) {
                *puVar18 = *puVar18 | 0x20;
              }
              else if (local_res18[0] == 3) {
                *puVar18 = *puVar18 | 0x30;
              }
            }
            uVar14 = uVar14 + 1;
            puVar18 = puVar18 + 6;
          } while (uVar14 < local_res8);
        }
        iVar9 = SendSelectInterfaceUrb(uVar17,_Dst,param_1,(longlong)puVar7);
LAB_14000977d:
        if (*(uint *)(param_1 + 0xc) <= local_res20) goto LAB_1400097e3;
        _Dst = (ushort *)((longlong)_Dst + (ulonglong)*_Dst);
        uVar14 = local_res20;
        goto LAB_14000963f;
      }
      local_res8 = *(uint *)(lVar8 + 0x10);
      uVar14 = (local_res8 + 1) * 0x18;
      if (*_Dst < uVar14) {
        iVar9 = -0x3ffffff3;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000982d;
        WPP_RECORDER_SF_qdd(*(undefined8 *)(lVar4 + 0x560),2,8,0x15,
                            &WPP_fc1b814fd1aa3eaffd95e56bc3961d1e_Traceguids,
                            (char)*(undefined8 *)(param_1 + 0xe0),(char)*_Dst,(char)uVar14);
        goto LAB_1400099f1;
      }
      uVar15 = 0;
      while (uVar14 = (uint)uVar15, uVar14 < local_res8) {
        if ((*(uint *)(_Dst + uVar15 * 0xc + 0x16) & 1) != 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            in_stack_ffffffffffffff58 = &WPP_fc1b814fd1aa3eaffd95e56bc3961d1e_Traceguids;
            uVar12 = 8;
            WPP_RECORDER_SF_L(*(undefined8 *)(lVar4 + 0x560),2,8,0x16,
                              &WPP_fc1b814fd1aa3eaffd95e56bc3961d1e_Traceguids,
                              (char)_Dst[uVar15 * 0xc + 0xc]);
          }
          uVar17 = (short)local_res8 * 0x18 + 0x38;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140009752;
          uVar1 = (undefined1)_Dst[uVar15 * 0xc + 0xd];
          uVar19 = 0x17;
          uVar13 = (undefined1)_Dst[uVar15 * 0xc + 0xc];
          bVar16 = 2;
          goto LAB_14000990e;
        }
        local_res18[0] = 0;
        uVar12 = uVar15;
        uVar11 = GetEndpointPriority(param_1,(byte *)*puVar7,uVar14,local_res18);
        if (-1 < (int)uVar11) {
          uVar17 = (short)local_res8 * 0x18 + 0x38;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            in_stack_ffffffffffffff58 = &WPP_fc1b814fd1aa3eaffd95e56bc3961d1e_Traceguids;
            WPP_RECORDER_SF_qqd(*(undefined8 *)(lVar4 + 0x560),2,1,0x18,
                                &WPP_fc1b814fd1aa3eaffd95e56bc3961d1e_Traceguids,
                                (char)*(undefined8 *)(param_1 + 0xe0),(char)puVar5,
                                (char)_Dst[uVar15 * 0xc + 0xd]);
          }
          goto LAB_140009752;
        }
        iVar9 = 0;
        uVar15 = (ulonglong)(uVar14 + 1);
      }
      uVar17 = *(ushort *)puVar7[1];
      if (uVar17 <= *_Dst) {
        memmove(_Dst,(ushort *)puVar7[1],(ulonglong)uVar17);
        goto LAB_14000977d;
      }
      iVar9 = -0x3ffffff3;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qdd(*(undefined8 *)(lVar4 + 0x560),2,8,0x19,
                            &WPP_fc1b814fd1aa3eaffd95e56bc3961d1e_Traceguids,
                            (char)*(undefined8 *)(param_1 + 0xe0),(char)*_Dst,(char)uVar17);
        goto LAB_1400099f1;
      }
    }
LAB_14000982d:
    iVar9 = -0x3ffffff3;
    goto LAB_140009833;
  }
  iVar9 = -0x3ffffff3;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(lVar4 + 0x560),2,8,0x10,
                       &WPP_fc1b814fd1aa3eaffd95e56bc3961d1e_Traceguids,
                       (char)*(undefined8 *)(param_1 + 0xe0),(char)uVar2);
    goto LAB_1400099f1;
  }
  goto LAB_140009833;
LAB_1400097e3:
  if (iVar9 < 0) {
LAB_1400099f1:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(lVar4 + 0x560),2,8,0x1a,
                         &WPP_fc1b814fd1aa3eaffd95e56bc3961d1e_Traceguids,
                         (char)*(undefined8 *)(param_1 + 0xe0),(char)iVar9);
    }
  }
  else {
LAB_1400097f1:
    *(undefined8 *)(puVar5 + 0x10) = *(undefined8 *)(*(longlong *)(param_1 + 0xe8) + 0x48);
  }
  if (iVar9 == -0x80000000) goto LAB_14000984b;
LAB_140009833:
  if (iVar9 == -0x3ffffff3) {
    puVar5[2] = 0x300;
    puVar5[3] = 0x8000;
  }
  else if (iVar9 == 0) {
    puVar5[2] = 0;
    puVar5[3] = 0;
  }
  else {
    uVar10 = 0x40000000;
    if (iVar9 != 0x103) {
      uVar10 = 0x80000000;
    }
    *(undefined4 *)(puVar5 + 2) = uVar10;
  }
LAB_14000984b:
  UsbcCompleteIrp(*(longlong *)(param_1 + 0xe8),iVar9,param_2);
  UsbcDecrementPendingCount(lVar4,param_2);
  return iVar9;
}



===== DispatchFdoDeviceControl @ 140009bf8 =====

ulonglong DispatchFdoDeviceControl(longlong param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  
  iVar1 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  if ((*(int *)(param_1 + 4) != 1) &&
     (ParentSetD0(param_1,CONCAT71((int7)((ulonglong)param_2 >> 8),1),0,0,0),
     (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_qL(*(undefined8 *)(param_1 + 0x560),2,3,0x3a,
                       &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)param_2,
                       (char)*(undefined4 *)(param_1 + 4));
  }
  if (iVar1 == 0x2d0c10) {
    if (*(char *)(param_1 + 0x250) != '\0') {
      uVar2 = GetMediaSerialNumber(param_1,param_2);
      UsbcCompleteIrp(param_1,uVar2,param_2);
      return (ulonglong)uVar2;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),4,6,0x3b,
                       &WPP_93f6b87810f63f9db566694056813e32_Traceguids);
    }
  }
  uVar3 = UsbcForwardIrp(param_1,*(undefined8 *)(param_1 + 0x28),param_2);
  return uVar3 & 0xffffffff;
}



===== DispatchFdoWaitWake @ 140009d10 =====

undefined4 DispatchFdoWaitWake(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined4 uVar5;
  
  puVar1 = (undefined8 *)(param_1 + 0x20);
  puVar2 = (undefined8 *)(param_1 + 0x560);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qq(*puVar2,4,3,0x1d,&WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                       (char)*puVar1,(char)param_2);
  }
  LOCK();
  *(longlong *)(param_1 + 0x178) = param_2;
  UNLOCK();
  LOCK();
  iVar3 = *(int *)(param_1 + 0x188);
  *(int *)(param_1 + 0x188) = 1;
  UNLOCK();
  if (iVar3 == 0) {
    puVar4 = *(undefined8 **)(param_2 + 0xb8);
    puVar4[-9] = *puVar4;
    puVar4[-8] = puVar4[1];
    puVar4[-7] = puVar4[2];
    puVar4[-6] = puVar4[3];
    puVar4[-5] = puVar4[4];
    puVar4[-4] = puVar4[5];
    puVar4[-3] = puVar4[6];
    *(undefined1 *)((longlong)puVar4 + -0x45) = 0;
    SetCompletionRoutine(*puVar2,*puVar1,param_2,CompletionFdoWaitWake,param_1);
    uVar5 = PoCallDriver(*(undefined8 *)(param_1 + 0x28),param_2);
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*puVar2,4,3,0x1e,&WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                        (char)*puVar1);
    }
    LOCK();
    *(undefined8 *)(param_1 + 0x178) = 0;
    UNLOCK();
    uVar5 = 0xc0000120;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
    *(longlong *)(param_1 + 0x180) = param_2;
    IofCompleteRequest(param_2,0);
  }
  return uVar5;
}



===== GetEndpointPriority @ 140009e7c =====

ulonglong GetEndpointPriority(longlong param_1,byte *param_2,uint param_3,undefined4 *param_4)

{
  ushort uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint local_res8 [2];
  longlong local_28 [2];
  
  local_res8[0] = 0;
  local_28[0] = 0;
  if (*(int *)(param_1 + 0x1e0) != 0) {
    uVar3 = GetBulkEndpointDescriptorAndPosition(param_1,param_2,param_3,local_28,(int *)local_res8)
    ;
    if ((int)uVar3 < 0) {
      return uVar3 & 0xffffffff;
    }
    for (uVar4 = 0; (uint)uVar4 < *(uint *)(param_1 + 0x1e0); uVar4 = (ulonglong)((uint)uVar4 + 1))
    {
      lVar2 = *(longlong *)(param_1 + 0x1d8);
      uVar1 = *(ushort *)(lVar2 + 2 + uVar4 * 0x14);
      if ((((uVar1 == param_2[2]) || (uVar1 == 0xffff)) &&
          ((uVar1 = *(ushort *)(lVar2 + 4 + uVar4 * 0x14), uVar1 == param_2[3] || (uVar1 == 0xffff))
          )) && (((*(int *)(lVar2 + 8 + uVar4 * 0x14) == 0) ==
                  (bool)(*(byte *)(local_28[0] + 2) >> 7) &&
                 (*(ushort *)(lVar2 + 0xc + uVar4 * 0x14) == local_res8[0])))) {
        *param_4 = *(undefined4 *)(lVar2 + 0x10 + uVar4 * 0x14);
        return uVar3 & 0xffffffff;
      }
    }
  }
  return 0xc0000225;
}



===== DispatchFdoInternalDeviceControl @ 140009f7c =====

ulonglong DispatchFdoInternalDeviceControl(longlong param_1,longlong param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulonglong uVar4;
  
  iVar1 = *(int *)(param_1 + 0xc);
  iVar2 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  if ((iVar1 == 2) || (iVar1 == 9)) {
    if (*(int *)(param_1 + 4) == 1) {
      if (((iVar2 != 0x220007) && (iVar2 != 0x22001f)) && (iVar2 != 0x220fb3)) {
LAB_140009fc6:
        uVar4 = UsbcForwardIrp(param_1,*(undefined8 *)(param_1 + 0x28),param_2);
        return uVar4 & 0xffffffff;
      }
      uVar3 = ParentResetOrCyclePort(param_1,param_2,iVar2);
      uVar4 = (ulonglong)uVar3;
      if (uVar3 == 0x80000000) goto LAB_140009fc6;
      if (uVar3 == 0x103) {
        return 0x103;
      }
      goto LAB_14000a004;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qL(*(undefined8 *)(param_1 + 0x560),2,8,0x3d,
                         &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)param_1,
                         (char)*(int *)(param_1 + 4));
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(param_1 + 0x560),2,8,0x3c,
                       &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)param_1,(char)iVar1);
  }
  uVar4 = 0xc00000a3;
LAB_14000a004:
  UsbcCompleteIrp(param_1,(int)uVar4,param_2);
  return uVar4;
}



===== DispatchFdoQueryPower @ 14000a0a4 =====

undefined4 DispatchFdoQueryPower(longlong param_1,longlong param_2,undefined8 param_3)

{
  byte *pbVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined8 uVar7;
  longlong lVar8;
  bool bVar9;
  undefined8 in_stack_ffffffffffffffd8;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  if (*(int *)(lVar2 + 0x10) == 0) {
    lVar8 = param_2;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqL(*(undefined8 *)(param_1 + 0x560),param_2,param_3,0x2d,
                          in_stack_ffffffffffffffd8,(char)*(undefined8 *)(param_1 + 0x20),
                          (char)param_2,(char)*(undefined4 *)(lVar2 + 0x18));
    }
    if (*(int *)(lVar2 + 0x18) != 1) {
      uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x158);
      uVar6 = *(uint *)(param_1 + 0x4d4);
      if ((uVar6 & 4) != 0) {
        uVar6 = uVar6 & 0xfffffffb | 1;
        *(uint *)(param_1 + 0x4d4) = uVar6;
      }
      bVar9 = (uVar6 & 1) == 0;
      if (bVar9) {
        *(uint *)(param_1 + 0x4d4) = uVar6 | 1;
      }
      uVar7 = CONCAT71((int7)((ulonglong)lVar8 >> 8),uVar4);
      KeReleaseSpinLock(param_1 + 0x158);
      if (bVar9) {
        DisableIdleTimer(param_1,uVar7,0x50515054);
      }
      CancelFdoIdleIrp(param_1,CONCAT71((int7)((ulonglong)uVar7 >> 8),1));
    }
    puVar3 = *(undefined8 **)(param_2 + 0xb8);
    puVar3[-9] = *puVar3;
    puVar3[-8] = puVar3[1];
    puVar3[-7] = puVar3[2];
    puVar3[-6] = puVar3[3];
    puVar3[-5] = puVar3[4];
    puVar3[-4] = puVar3[5];
    puVar3[-3] = puVar3[6];
    *(undefined1 *)((longlong)puVar3 + -0x45) = 0;
    SetCompletionRoutine
              (*(undefined8 *)(param_1 + 0x560),*(undefined8 *)(param_1 + 0x20),param_2,
               CompletionFdoSystemQueryPower,param_1);
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    PoCallDriver(*(undefined8 *)(param_1 + 0x28),param_2);
    uVar5 = 0x103;
  }
  else {
    if (*(int *)(lVar2 + 0x10) == 1) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqL(*(undefined8 *)(param_1 + 0x560),param_2,param_3,0x2e,
                            in_stack_ffffffffffffffd8,(char)*(undefined8 *)(param_1 + 0x20),
                            (char)param_2,(char)*(undefined4 *)(lVar2 + 0x18));
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x560),2,8,0x2f,
                        &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                        (char)*(undefined8 *)(param_1 + 0x20));
    }
    PoStartNextPowerIrp(param_2);
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    uVar5 = PoCallDriver(*(undefined8 *)(param_1 + 0x28),param_2);
    UsbcReleaseRemoveLock(param_1,param_2);
    IoReleaseRemoveLockEx(param_1 + 200,param_2,0x20);
  }
  return uVar5;
}



===== WPP_RECORDER_SF_qqL @ 14000a2fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,4,0);
  return;
}



===== ParentResetOrCyclePort @ 14000a410 =====

undefined4 ParentResetOrCyclePort(longlong param_1,longlong param_2,int param_3)

{
  byte *pbVar1;
  longlong ***ppplVar2;
  longlong ***ppplVar3;
  undefined8 *puVar4;
  longlong lVar5;
  longlong ****pppplVar6;
  code *pcVar7;
  bool bVar8;
  undefined1 uVar9;
  undefined4 uVar10;
  ulonglong uVar11;
  uint *puVar12;
  uint uVar13;
  longlong lVar14;
  longlong ****pppplVar15;
  longlong ****pppplVar16;
  char local_res8;
  undefined4 local_res20 [2];
  longlong ****local_48;
  longlong ****local_40;
  
  local_res20[0] = 0;
  local_res8 = '\x01';
  uVar10 = 0xc0000001;
  lVar14 = 0x278;
  if (param_3 != 0x22001f) {
    lVar14 = 0x260;
  }
  pppplVar15 = (longlong ****)(lVar14 + param_1);
  lVar14 = 0x270;
  if (param_3 != 0x22001f) {
    lVar14 = 0x25c;
  }
  uVar9 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x248);
  if (*(char *)(lVar14 + param_1) == '\0') {
    *(undefined1 *)(lVar14 + param_1) = 1;
    bVar8 = true;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0x39,
                       &WPP_93f6b87810f63f9db566694056813e32_Traceguids);
    }
    uVar10 = 0x103;
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    ppplVar2 = (longlong ***)(param_2 + 0xa8);
    ppplVar3 = pppplVar15[1];
    if ((longlong ****)*ppplVar3 != pppplVar15) {
LAB_14000a6fc:
      pcVar7 = (code *)swi(0x29);
      (*pcVar7)(3);
      return uVar10;
    }
    *ppplVar2 = (longlong **)pppplVar15;
    bVar8 = false;
    *(longlong ****)(param_2 + 0xb0) = ppplVar3;
    *ppplVar3 = (longlong **)ppplVar2;
    pppplVar15[1] = ppplVar2;
  }
  KeReleaseSpinLock(param_1 + 0x248,uVar9);
  if (bVar8) {
    puVar4 = *(undefined8 **)(param_2 + 0xb8);
    puVar4[-9] = *puVar4;
    puVar4[-8] = puVar4[1];
    puVar4[-7] = puVar4[2];
    puVar4[-6] = puVar4[3];
    puVar4[-5] = puVar4[4];
    puVar4[-4] = puVar4[5];
    puVar4[-3] = puVar4[6];
    *(undefined1 *)((longlong)puVar4 + -0x45) = 0;
    if (*(char *)(param_1 + 0x568) == '\x01') {
      if (param_3 == 0x220007) {
        lVar5 = *(longlong *)(param_2 + 0xb8);
        *(undefined4 *)(lVar5 + -0x30) = 0x220fb3;
        *(undefined4 **)(lVar5 + -0x40) = local_res20;
      }
      puVar12 = *(uint **)(param_1 + 0x80);
      uVar13 = 0;
      if (*puVar12 != 0) {
        do {
          uVar11 = (ulonglong)uVar13;
          uVar13 = uVar13 + 1;
          *(undefined1 *)(*(longlong *)(*(longlong *)(puVar12 + uVar11 * 2 + 2) + 0x40) + 0x19d) = 1
          ;
          puVar12 = *(uint **)(param_1 + 0x80);
        } while (uVar13 < *puVar12);
      }
      local_res8 = '\0';
    }
    uVar10 = CallNextDriverSync(param_1,param_2,local_res8);
    NotifyPdosOfSurprisePowerOn(param_1,*(char *)(param_1 + 0x55a));
    local_40 = (longlong ****)&local_48;
    local_48 = (longlong ****)&local_48;
    uVar9 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x248);
    *(undefined1 *)(lVar14 + param_1) = 0;
    if (*(char *)(param_1 + 0x568) == '\x01') {
      puVar12 = *(uint **)(param_1 + 0x80);
      uVar13 = 0;
      if (*puVar12 != 0) {
        do {
          if (*(char *)(*(longlong *)(*(longlong *)(puVar12 + (ulonglong)uVar13 * 2 + 2) + 0x40) +
                       0x19e) == '\x01') {
            *(undefined2 *)
             (*(longlong *)(*(longlong *)(puVar12 + (ulonglong)uVar13 * 2 + 2) + 0x40) + 0x19d) = 0;
          }
          puVar12 = *(uint **)(param_1 + 0x80);
          uVar13 = uVar13 + 1;
        } while (uVar13 < *puVar12);
      }
    }
    while (pppplVar6 = (longlong ****)*pppplVar15, pppplVar6 != pppplVar15) {
      if (((longlong ****)pppplVar6[1] != pppplVar15) ||
         (ppplVar2 = *pppplVar6, (longlong ****)ppplVar2[1] != pppplVar6)) goto LAB_14000a6fc;
      *pppplVar15 = ppplVar2;
      ppplVar2[1] = (longlong **)pppplVar15;
      if ((longlong *****)*local_40 != &local_48) goto LAB_14000a6fc;
      pppplVar6[1] = (longlong ***)local_40;
      *pppplVar6 = (longlong ***)&local_48;
      *local_40 = (longlong ***)pppplVar6;
      local_40 = pppplVar6;
    }
    KeReleaseSpinLock(param_1 + 0x248,uVar9);
    while ((longlong *****)local_48 != &local_48) {
      if (((longlong *****)local_48[1] != &local_48) ||
         (pppplVar15 = (longlong ****)*local_48, (longlong ****)pppplVar15[1] != local_48))
      goto LAB_14000a6fc;
      pppplVar15[1] = (longlong ***)&local_48;
      pppplVar16 = local_48 + -0x15;
      pppplVar6 = local_48 + -0xf;
      local_48 = pppplVar15;
      *(undefined4 *)pppplVar6 = uVar10;
      IofCompleteRequest(pppplVar16,0);
      UsbcReleaseRemoveLock(param_1,(longlong)pppplVar16);
      IoReleaseRemoveLockEx(param_1 + 200,pppplVar16,0x20);
    }
  }
  return uVar10;
}



===== SendSelectInterfaceUrb @ 14000a724 =====

int SendSelectInterfaceUrb(ushort param_1,ushort *param_2,longlong param_3,longlong param_4)

{
  ushort uVar1;
  longlong lVar2;
  undefined1 uVar3;
  int iVar4;
  ushort *puVar5;
  ushort *_Src;
  uint uVar6;
  
  lVar2 = *(longlong *)(param_3 + 0xe8);
  puVar5 = (ushort *)ExAllocatePool2(0x40,param_1,0x43627355);
  if (puVar5 == (ushort *)0x0) {
    iVar4 = -0x3fffff66;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(lVar2 + 0x560),2,8,10,
                         &WPP_fc1b814fd1aa3eaffd95e56bc3961d1e_Traceguids,
                         (char)*(undefined8 *)(param_3 + 0xe0),(char)param_1);
    }
  }
  else {
    if (param_1 < 0x38) {
      iVar4 = -0x3ffffff3;
    }
    else {
      *puVar5 = param_1;
      uVar6 = param_1 - 0x20;
      puVar5[1] = 1;
      *(undefined8 *)(puVar5 + 0xc) = *(undefined8 *)(*(longlong *)(param_3 + 0xe8) + 0x48);
      uVar1 = *param_2;
      if (uVar1 < uVar6) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_dd(*(undefined8 *)(lVar2 + 0x560),2,1,0xb,
                             &WPP_fc1b814fd1aa3eaffd95e56bc3961d1e_Traceguids,(char)uVar1,
                             (char)uVar6);
        }
        uVar6 = (uint)*param_2;
      }
      else if ((uVar6 < uVar1) &&
              ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_dd(*(undefined8 *)(lVar2 + 0x560),2,8,0xc,
                           &WPP_fc1b814fd1aa3eaffd95e56bc3961d1e_Traceguids,(char)uVar1,(char)uVar6)
        ;
      }
      memmove(puVar5 + 0x10,param_2,(ulonglong)uVar6);
      iVar4 = SubmitUrb(*(longlong *)(param_3 + 0xe8),puVar5);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqd(*(undefined8 *)(lVar2 + 0x560),4,1,0xd,
                            &WPP_fc1b814fd1aa3eaffd95e56bc3961d1e_Traceguids,
                            (char)*(undefined8 *)(param_3 + 0xe0),(char)puVar5,(char)iVar4);
      }
      if (-1 < iVar4) {
        uVar3 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x50);
        if (*(longlong *)(param_4 + 8) != 0) {
          ExFreePoolWithTag(*(longlong *)(param_4 + 8),0x43627355);
        }
        _Src = MemDup(puVar5 + 0x10,(uint)puVar5[0x10]);
        *(ushort **)(param_4 + 8) = _Src;
        if (_Src == (ushort *)0x0) {
          iVar4 = -0x3fffff66;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_d(*(undefined8 *)(lVar2 + 0x560),2,8,0xe,
                              &WPP_fc1b814fd1aa3eaffd95e56bc3961d1e_Traceguids,0x9a);
          }
        }
        else {
          memmove(param_2,_Src,(ulonglong)*_Src);
        }
        KeReleaseSpinLock(lVar2 + 0x50,uVar3);
      }
    }
    ExFreePoolWithTag(puVar5,0x43627355);
  }
  return iVar4;
}



===== WPP_RECORDER_SF_DDD @ 14000a9ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_DDD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_fc1b814fd1aa3eaffd95e56bc3961d1e_Traceguids,0x13,&uStack0000000000000030,4,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_fc1b814fd1aa3eaffd95e56bc3961d1e_Traceguids,0x13,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== GetStringDescriptor @ 14000aa98 =====

uint GetStringDescriptor(longlong param_1,byte param_2,undefined2 param_3,byte *param_4,uint param_5
                        )

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  undefined2 uVar4;
  uint uVar5;
  undefined2 *local_38 [2];
  
  local_38[0] = (undefined2 *)0x0;
  if (((param_2 == 0) || (param_4 == (byte *)0x0)) || (param_5 < 4)) {
    uVar1 = 0xc000000d;
    goto LAB_14000abce;
  }
  param_4[0] = 0;
  param_4[1] = 3;
  param_4[2] = 0;
  param_4[3] = 0;
  uVar1 = USBD_UrbAllocate(*(longlong *)(param_1 + 0x548),local_38);
  if ((int)uVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000abce;
    uVar4 = 0xd;
    bVar2 = 2;
    uVar3 = 8;
    uVar5 = uVar1;
  }
  else {
    local_38[0][1] = 0xb;
    *local_38[0] = 0x88;
    *(uint *)(local_38[0] + 0x12) = param_5;
    *(undefined8 *)(local_38[0] + 0x18) = 0;
    *(byte **)(local_38[0] + 0x14) = param_4;
    *(undefined1 *)((longlong)local_38[0] + 0x83) = 3;
    *(byte *)(local_38[0] + 0x41) = param_2;
    local_38[0][0x42] = param_3;
    *(undefined8 *)(local_38[0] + 0x1c) = 0;
    uVar1 = SubmitUrb(param_1,local_38[0]);
    if ((int)uVar1 < 0) goto LAB_14000abce;
    if (3 < *param_4) {
      if (*(short *)(param_4 + 2) == 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar4 = 0xf;
LAB_14000ac8e:
          WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),4,2,uVar4,
                            &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids,param_2);
        }
      }
      else {
        if ((*param_4 & 1) == 0) {
          if ((param_4[1] == 3) ||
             (uVar1 = 0xc000009c,
             (undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
          goto LAB_14000abce;
          uVar4 = 0x11;
          goto LAB_14000ac30;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar4 = 0x10;
          goto LAB_14000ac8e;
        }
      }
      uVar1 = 0xc000009c;
      goto LAB_14000abce;
    }
    uVar1 = 0xc000009c;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000abce;
    uVar4 = 0xe;
LAB_14000ac30:
    uVar1 = 0xc000009c;
    uVar3 = 2;
    bVar2 = 4;
    uVar5 = (uint)param_2;
  }
  WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),bVar2,uVar3,uVar4,
                    &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids,(char)uVar5);
LAB_14000abce:
  if (local_38[0] != (undefined2 *)0x0) {
    USBD_UrbFree(*(longlong *)(param_1 + 0x548),(longlong)local_38[0]);
  }
  return uVar1;
}



===== USBD_UrbAllocate @ 14000acd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int USBD_UrbAllocate(longlong param_1,undefined8 *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  void *_Dst;
  char *pcVar4;
  
  if (param_1 == 0) {
    if (g_EnableDbgPrints != '\0') {
      DbgPrintEx(0x4d,0,"USBDHandle cant be NULL\n");
    }
    iVar3 = -0x3ffffff3;
    if (param_2 == (undefined8 *)0x0) {
      return -0x3ffffff3;
    }
    goto LAB_14000aee3;
  }
  if (param_2 == (undefined8 *)0x0) {
    if (g_EnableDbgPrints != '\0') {
      DbgPrintEx(0x4d,0,"Urb cant be NULL\n");
    }
    return -0x3ffffff3;
  }
  if (*(char *)(param_1 + 0xe1) == '\0') {
    if (0 < *(int *)(param_1 + 0xdc)) {
      LOCK();
      *(int *)(param_1 + 0xdc) = *(int *)(param_1 + 0xdc) + 1;
      UNLOCK();
      if (*(code **)(param_1 + 0x78) == (code *)0x0) {
        _Dst = (void *)ExAllocatePoolWithTag(DAT_14001c42c,0x98,*(undefined4 *)(param_1 + 0x40));
        *param_2 = _Dst;
        if (_Dst == (void *)0x0) {
          if (g_EnableDbgPrints != '\0') {
            DbgPrintEx(0x4d,0,"Insufficient Memory to allocate URB\n");
          }
          iVar3 = -0x3fffff66;
        }
        else {
          memset(_Dst,0,0x98);
          iVar3 = 0;
        }
      }
      else {
        iVar3 = (**(code **)(param_1 + 0x78))(*(undefined8 *)(param_1 + 0x30));
      }
      if (-1 < iVar3) {
        return iVar3;
      }
      LOCK();
      piVar1 = (int *)(param_1 + 0xdc);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar2 < 2) {
        if (*(char *)(param_1 + 0xe1) == '\0') {
          if (g_EnableDbgPrints != '\0') {
            DbgPrintEx(0x4d,0,
                       "UsbdHandleInfo->PendingDelete should be set here UsbdHandleInfo 0x%p\n",
                       param_1);
          }
        }
        else {
          if (*(code **)(param_1 + 0x70) != (code *)0x0) {
            (**(code **)(param_1 + 0x70))(*(undefined8 *)(param_1 + 0x30));
          }
          ExFreePoolWithTag(param_1,*(undefined4 *)(param_1 + 0x40));
        }
      }
      goto LAB_14000aee3;
    }
    if (g_EnableDbgPrints != '\0') {
      pcVar4 = "UsbdHandleInfo->ReferenceCount must be 1 or higher 0x%p\n";
      goto LAB_14000ae0f;
    }
  }
  else if (g_EnableDbgPrints != '\0') {
    pcVar4 = "UsbdHandleInfo->PendingDelete is set, UsbdHandleInfo 0x%p\n";
LAB_14000ae0f:
    DbgPrintEx(0x4d,0,pcVar4,param_1);
  }
  iVar3 = -0x3ffffe7c;
  if (g_EnableDbgPrints != '\0') {
    DbgPrintEx(0x4d,0,"USBDInternal_ReferenceHandle failed %x\n",0xc0000184);
  }
LAB_14000aee3:
  *param_2 = 0;
  return iVar3;
}



===== USBD_UrbFree @ 14000aef4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void USBD_UrbFree(longlong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_2 == 0) {
    if (g_EnableDbgPrints == '\0') {
      return;
    }
    pcVar3 = "Urb cant be NULL\n";
  }
  else {
    if (param_1 != 0) {
      if (*(code **)(param_1 + 0x98) == (code *)0x0) {
        ExFreePoolWithTag(param_2,*(undefined4 *)(param_1 + 0x40));
      }
      else {
        (**(code **)(param_1 + 0x98))(param_2);
      }
      LOCK();
      piVar1 = (int *)(param_1 + 0xdc);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (1 < iVar2) {
        return;
      }
      if (*(char *)(param_1 + 0xe1) != '\0') {
        if (*(code **)(param_1 + 0x70) != (code *)0x0) {
          (**(code **)(param_1 + 0x70))(*(undefined8 *)(param_1 + 0x30));
        }
        ExFreePoolWithTag(param_1,*(undefined4 *)(param_1 + 0x40));
        return;
      }
      if (g_EnableDbgPrints == '\0') {
        return;
      }
      DbgPrintEx(0x4d,0,"UsbdHandleInfo->PendingDelete should be set here UsbdHandleInfo 0x%p\n",
                 param_1);
      return;
    }
    if (g_EnableDbgPrints == '\0') {
      return;
    }
    pcVar3 = "USBDHandle cant be NULL\n";
  }
  DbgPrintEx(0x4d,0,pcVar3);
  return;
}



===== SubmitUrb @ 14000aff0 =====

undefined4 SubmitUrb(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  longlong lVar3;
  char in_stack_00000030;
  
  lVar3 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x28) >> 8),
                                 *(undefined1 *)(*(longlong *)(param_1 + 0x28) + 0x4c)),0);
  if (lVar3 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(undefined1 *)(lVar1 + -0x48) = 0xf;
    *(undefined4 *)(lVar1 + -0x30) = 0x220003;
    if ((in_stack_00000030 != '\0') &&
       (*(int *)(*(longlong *)(param_1 + 0x548) + 0xd8) - 0x602U < 0xfffff9fd)) {
      *(undefined8 *)(lVar1 + -0x18) = param_2;
    }
    *(undefined8 *)(lVar1 + -0x40) = param_2;
    uVar2 = CallNextDriverSync(param_1,lVar3,'\x01');
    IoFreeIrp(lVar3);
  }
  return uVar2;
}



===== WPP_RECORDER_SF_qqdd @ 14000b0a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqdd
               (undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_fc1b814fd1aa3eaffd95e56bc3961d1e_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,&WPP_fc1b814fd1aa3eaffd95e56bc3961d1e_Traceguids,param_4,
                  &param_6,8,&param_7,8,&param_8,4,&param_9,4,0);
  return;
}



===== UsbcDereferencePdo @ 14000b1d0 =====

void UsbcDereferencePdo(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x134);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    KeSetEvent(param_1 + 0x138,0,0);
  }
  return;
}



===== WPP_RECORDER_SF_qDL @ 14000b20c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qDL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,0x36,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,7,&WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,0x36,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_qd @ 14000b318 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qd(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar1 * 0x50))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar1 * 0x50),0x2b,param_5,param_4,
               &param_6,8,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,4,0);
  return;
}



===== RtlStringCchCopyW @ 14000b444 =====

uint RtlStringCchCopyW(short *param_1,longlong param_2,longlong param_3)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  longlong lVar4;
  longlong lVar5;
  
  if (param_2 - 1U < 0x7fffffff) {
    lVar4 = 0x7ffffffe - param_2;
    lVar5 = param_3 - (longlong)param_1;
    do {
      if ((lVar4 + param_2 == 0) || (sVar1 = *(short *)(lVar5 + (longlong)param_1), sVar1 == 0))
      break;
      *param_1 = sVar1;
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
    psVar3 = param_1 + -1;
    if (param_2 != 0) {
      psVar3 = param_1;
    }
    *psVar3 = 0;
    uVar2 = ~-(uint)(param_2 != 0) & 0x80000005;
  }
  else {
    uVar2 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = 0;
      return 0xc000000d;
    }
  }
  return uVar2;
}



===== WStrLen @ 14000b4b8 =====

int WStrLen(short *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 == (short *)0x0) {
    return 0;
  }
  for (; *param_1 != 0; param_1 = param_1 + 1) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}



===== PnpLocationInterfaceGetLocationStrings @ 14000b4e0 =====

ulonglong PnpLocationInterfaceGetLocationStrings(longlong param_1,undefined8 *param_2)

{
  wchar_t *pwVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong local_res8;
  ulonglong local_res10;
  
  *param_2 = 0;
  uVar3 = 0xc;
  local_res10 = 0;
  local_res8 = 0xc;
  if (*(int *)(param_1 + 8) == 0) {
    uVar3 = 0x16;
    local_res8 = 0x16;
  }
  uVar2 = 0x100;
  if (ExDefaultNonPagedPoolType == 1) {
    uVar2 = 0x40;
  }
  pwVar1 = (wchar_t *)ExAllocatePool2(uVar2,uVar3 * 2,0x43627355);
  if (pwVar1 == (wchar_t *)0x0) {
    return 0xc000009a;
  }
  uVar3 = RtlStringCchPrintfExW
                    (pwVar1,uVar3,&local_res10,&local_res8,0x200,L"USBMI(%d)",
                     (char)*(undefined4 *)(param_1 + 8));
  uVar4 = uVar3 & 0xffffffff;
  if ((int)uVar3 < 0) {
LAB_14000b5e9:
    ExFreePoolWithTag(pwVar1,0x43627355);
  }
  else {
    if (*(int *)(param_1 + 8) == 0) {
      uVar3 = RtlStringCchPrintfExW
                        ((wchar_t *)(local_res10 + 2),local_res8 - 1,(ulonglong *)0x0,&local_res8,
                         0x200,L"USB(%d)",
                         (char)*(undefined4 *)(*(longlong *)(param_1 + 0xe8) + 0x90));
      uVar4 = uVar3 & 0xffffffff;
      if ((int)uVar3 < 0) goto LAB_14000b5e9;
    }
    *param_2 = pwVar1;
  }
  return uVar4;
}



===== RtlStringCchPrintfExW @ 14000b608 =====

ulonglong RtlStringCchPrintfExW
                    (wchar_t *param_1,ulonglong param_2,ulonglong *param_3,ulonglong *param_4,
                    uint param_5,wchar_t *param_6,char param_7)

{
  wchar_t *pwVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong *puVar5;
  wchar_t *local_58;
  ulonglong local_50 [2];
  
  puVar5 = param_3;
  uVar3 = RtlStringExValidateDestW((longlong)param_1,param_2,param_3,param_5);
  if ((int)uVar3 < 0) {
    if (param_2 == 0) {
      return uVar3 & 0xffffffff;
    }
    *param_1 = L'\0';
    return uVar3 & 0xffffffff;
  }
  if (((param_5 >> 8 & 1) != 0) && (param_6 == (wchar_t *)0x0)) {
    param_6 = L"";
  }
  uVar3 = 0;
  local_50[0] = param_2;
  local_58 = param_1;
  if ((param_5 & 0xffffe000) == 0) {
    if (param_2 == 0) {
      if (*param_6 == L'\0') goto LAB_14000b6c4;
      uVar3 = (ulonglong)((-(uint)(param_1 != (wchar_t *)0x0) & 0xbffffff8) + 0xc000000d);
    }
    else {
      local_50[0] = 0;
      puVar5 = local_50;
      local_58 = (wchar_t *)0x0;
      uVar2 = RtlStringVPrintfWorkerW(param_1,param_2,puVar5,param_6,&param_7);
      uVar3 = (ulonglong)uVar2;
      uVar4 = param_2 - local_50[0];
      pwVar1 = param_1 + local_50[0];
      local_58 = pwVar1;
      local_50[0] = uVar4;
      if (-1 < (int)uVar2) {
        if (((param_5 >> 9 & 1) != 0) && (1 < uVar4)) {
          RtlStringExHandleFillBehindNullW((longlong)pwVar1,uVar4 * 2,param_5);
          local_50[0] = uVar4;
          local_58 = pwVar1;
        }
        goto LAB_14000b6c4;
      }
    }
  }
  else {
    uVar3 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = L'\0';
    }
  }
  if (((param_5 & 0x1c00) != 0) && (param_2 != 0)) {
    RtlStringExHandleOtherFlagsW(param_1,param_2 * 2,puVar5,&local_58,local_50,param_5);
  }
  if ((((int)uVar3 + 0x80000000U & 0x80000000) == 0) && ((int)uVar3 != -0x7ffffffb)) {
    return uVar3;
  }
LAB_14000b6c4:
  if (param_3 != (ulonglong *)0x0) {
    *param_3 = (ulonglong)local_58;
  }
  if (param_4 != (ulonglong *)0x0) {
    *param_4 = local_50[0];
  }
  return uVar3;
}



===== RtlStringCchCopyExW @ 14000b7b0 =====

ulonglong RtlStringCchCopyExW(short *param_1,ulonglong param_2,short *param_3,undefined8 *param_4)

{
  short sVar1;
  short *psVar2;
  ulonglong uVar3;
  short *psVar4;
  longlong lVar5;
  longlong lVar6;
  
  lVar6 = 0;
  uVar3 = RtlStringExValidateDestW((longlong)param_1,param_2,param_3,0);
  if ((int)uVar3 < 0) {
    if (param_2 != 0) {
      *param_1 = 0;
    }
  }
  else {
    uVar3 = 0;
    if (param_2 == 0) {
      if (*param_3 != 0) {
        if (param_1 == (short *)0x0) {
          return 0xc000000d;
        }
        uVar3 = 0x80000005;
      }
    }
    else {
      lVar5 = 0x7ffffffe - param_2;
      psVar4 = param_1;
      do {
        if ((lVar5 + param_2 == 0) ||
           (sVar1 = *(short *)(((longlong)param_3 - (longlong)param_1) + (longlong)psVar4),
           sVar1 == 0)) break;
        *psVar4 = sVar1;
        lVar6 = lVar6 + 1;
        psVar4 = psVar4 + 1;
        param_2 = param_2 - 1;
      } while (param_2 != 0);
      lVar5 = lVar6 + -1;
      psVar2 = psVar4 + -1;
      if (param_2 != 0) {
        lVar5 = lVar6;
        psVar2 = psVar4;
      }
      *psVar2 = 0;
      param_1 = param_1 + lVar5;
      uVar3 = (ulonglong)(~-(uint)(param_2 != 0) & 0x80000005);
    }
    if (param_4 != (undefined8 *)0x0) {
      *param_4 = param_1;
    }
  }
  return uVar3;
}



===== RtlStringExValidateDestW @ 14000b874 =====

undefined8
RtlStringExValidateDestW(longlong param_1,ulonglong param_2,undefined8 param_3,uint param_4)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if ((param_4 >> 8 & 1) == 0) {
    uVar1 = 0;
    if (0x7ffffffe < param_2 - 1) {
      uVar1 = 0xc000000d;
    }
  }
  else if (((param_1 == 0) && (param_2 != 0)) || (0x7fffffff < param_2)) {
    return 0xc000000d;
  }
  return uVar1;
}



===== RtlStringCchPrintfW @ 14000b8b4 =====

undefined4
RtlStringCchPrintfW(wchar_t *param_1,longlong param_2,wchar_t *param_3,undefined8 param_4)

{
  undefined4 uVar1;
  undefined8 local_res20;
  
  if (param_2 - 1U < 0x7fffffff) {
    local_res20 = param_4;
    uVar1 = RtlStringVPrintfWorkerW(param_1,param_2,(ulonglong *)0x0,param_3,(va_list)&local_res20);
  }
  else {
    uVar1 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar1;
}



===== RtlStringVPrintfWorkerW @ 14000b900 =====

undefined4
RtlStringVPrintfWorkerW
          (wchar_t *param_1,longlong param_2,ulonglong *param_3,wchar_t *param_4,va_list param_5)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong _Count;
  undefined4 uVar3;
  
  _Count = param_2 - 1;
  uVar3 = 0;
  iVar1 = _vsnwprintf(param_1,_Count,param_4,param_5);
  if (iVar1 < 0) {
LAB_14000b955:
    uVar3 = 0x80000005;
  }
  else {
    uVar2 = (ulonglong)iVar1;
    if (uVar2 != _Count) {
      if (uVar2 <= _Count) {
        _Count = uVar2;
        goto LAB_14000b95f;
      }
      goto LAB_14000b955;
    }
  }
  param_1[_Count] = L'\0';
LAB_14000b95f:
  if (param_3 != (ulonglong *)0x0) {
    *param_3 = _Count;
  }
  return uVar3;
}



===== RtlStringExHandleFillBehindNullW @ 14000b990 =====

undefined8 RtlStringExHandleFillBehindNullW(longlong param_1,ulonglong param_2,uint param_3)

{
  if (2 < param_2) {
    memset((void *)(param_1 + 2),param_3 & 0xff,param_2 - 2);
  }
  return 0;
}



===== USBD_ValidateConfigurationDescriptorInternal @ 14000b9bc =====

int USBD_ValidateConfigurationDescriptorInternal
              (ushort *param_1,uint param_2,ushort param_3,longlong *param_4)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  longlong lVar4;
  ushort *puVar5;
  int iVar6;
  ushort *puVar7;
  ulonglong uVar8;
  ushort *puVar9;
  ushort local_res8;
  char cStack0000000000000028;
  
  puVar9 = (ushort *)0x0;
  local_res8 = 0;
  iVar6 = 0;
  cStack0000000000000028 = '\x01';
  if (((param_1 == (ushort *)0x0) || (param_2 < 9)) || (param_4 == (longlong *)0x0)) {
    return -0x3fffd000;
  }
  if ((byte)*param_1 < 9) {
    iVar6 = -0x3fefffff;
  }
  else if (*(char *)((longlong)param_1 + 1) == '\x02') {
    puVar7 = param_1 + 1;
    if ((param_2 < *puVar7) || (*puVar7 < (ushort)(((byte)param_1[2] + 1) * 9))) {
      iVar6 = -0x3feffffa;
      param_1 = puVar7;
    }
    else {
      if ((param_3 < 2) || ((byte)param_1[2] == 0)) goto LAB_14000bc5f;
      pbVar3 = (byte *)ExAllocatePool2(0x40,0x204,0x43627355);
      if (pbVar3 == (byte *)0x0) {
        iVar6 = -0x3ffff000;
      }
      else {
        lVar4 = ExAllocatePool2(0x40,0x100,0x43627355);
        if (lVar4 == 0) {
          iVar6 = -0x3ffff000;
LAB_14000bd4c:
          puVar7 = param_1;
        }
        else {
          puVar5 = (ushort *)((ulonglong)*puVar7 + (longlong)param_1);
          for (puVar7 = (ushort *)((longlong)param_1 + 9); puVar7 < puVar5;
              puVar7 = (ushort *)((longlong)puVar7 + (ulonglong)(byte)*puVar7)) {
            if ((ulonglong)((longlong)puVar5 - (longlong)puVar7) < 2) {
              iVar6 = -0x3ff00000;
              goto LAB_14000bd76;
            }
            bVar2 = (byte)*puVar7;
            if (puVar5 < (ushort *)((longlong)puVar7 + (ulonglong)bVar2)) {
LAB_14000bd71:
              iVar6 = -0x3fefffff;
LAB_14000bd76:
              goto LAB_14000bc23;
            }
            bVar1 = *(byte *)((longlong)puVar7 + 1);
            if (bVar1 == 4) {
              if ((bVar2 < 9) || ((bVar2 != 9 && (2 < param_3)))) goto LAB_14000bd71;
              bVar2 = (byte)puVar7[1];
              uVar8 = (ulonglong)bVar2;
              bVar1 = *(byte *)((longlong)puVar7 + 3);
              if (cStack0000000000000028 != '\0') {
                if (bVar1 == 0) {
                  *pbVar3 = bVar2;
                  local_res8 = local_res8 + 1;
                  pbVar3[1] = 0;
                  pbVar3[2] = 1;
                  pbVar3[0x202] = (byte)puVar7[2];
                  pbVar3[0x203] = 0;
                  *(undefined1 *)(uVar8 + lVar4) = 1;
                  cStack0000000000000028 = '\0';
                  goto LAB_14000bb08;
                }
LAB_14000bdb5:
                iVar6 = -0x3feffffd;
                puVar7 = (ushort *)((longlong)puVar7 + 3);
                goto LAB_14000bc23;
              }
              if (bVar2 == *pbVar3) {
                uVar8 = (ulonglong)bVar1;
                if ((pbVar3[(ulonglong)bVar1 + 2] == 1) || ((bVar1 <= pbVar3[1] && (2 < param_3))))
                goto LAB_14000bdb5;
              }
              else {
                if ((*(char *)(uVar8 + lVar4) == '\x01') || ((bVar2 < *pbVar3 && (2 < param_3)))) {
                  iVar6 = -0x3feffffd;
                  puVar7 = puVar7 + 1;
                  goto LAB_14000bc23;
                }
                if (bVar1 != 0) goto LAB_14000bdb5;
                local_res8 = local_res8 + 1;
                *(undefined1 *)(uVar8 + lVar4) = 1;
                *pbVar3 = bVar2;
                memset(pbVar3 + 2,0,0x100);
                uVar8 = 0;
              }
              if ((pbVar3[0x203] != pbVar3[0x202]) && (2 < param_3)) {
                iVar6 = -0x3feffff8;
                goto LAB_14000bd76;
              }
              memset(pbVar3 + 0x102,0,0x100);
              pbVar3[0x203] = 0;
              pbVar3[0x202] = (byte)puVar7[2];
              pbVar3[uVar8 + 2] = 1;
              pbVar3[1] = bVar1;
            }
            else if (bVar1 == 5) {
              if ((bVar2 < 7) || ((bVar2 != 7 && (2 < param_3)))) goto LAB_14000bd71;
              if (cStack0000000000000028 != '\0') {
                iVar6 = -0x3feffffc;
                goto LAB_14000bd76;
              }
              if (pbVar3[(ulonglong)(byte)puVar7[1] + 0x102] != 0) {
                iVar6 = -0x3feffff7;
                puVar7 = puVar7 + 1;
                goto LAB_14000bc23;
              }
              pbVar3[(ulonglong)(byte)puVar7[1] + 0x102] = 1;
              pbVar3[0x203] = pbVar3[0x203] + 1;
            }
            else if ((bVar1 == 0xb) &&
                    ((((bVar2 != 8 ||
                       (bVar2 = *(byte *)((longlong)puVar7 + 3),
                       0x100 < (uint)(byte)puVar7[1] + (uint)bVar2)) || ((byte)param_1[2] < bVar2))
                     || (bVar2 == 0)))) {
              iVar6 = -0x3feffffb;
              goto LAB_14000bd76;
            }
LAB_14000bb08:
            if ((byte)*puVar7 == 0) break;
          }
          puVar7 = (ushort *)0x0;
          if (local_res8 != (byte)param_1[2]) {
            iVar6 = -0x3feffff9;
            goto LAB_14000bd4c;
          }
        }
LAB_14000bc23:
        param_1 = puVar7;
        ExFreePoolWithTag(pbVar3,0);
        if (lVar4 != 0) {
          ExFreePoolWithTag(lVar4,0);
        }
        if (-1 < iVar6) {
          goto LAB_14000bc5f;
        }
      }
    }
  }
  else {
    iVar6 = -0x3feffffe;
    param_1 = (ushort *)((longlong)param_1 + 1);
  }
  puVar9 = param_1;
LAB_14000bc5f:
  *param_4 = (longlong)puVar9;
  return iVar6;
}



===== PdoIdleAcquireLock @ 14000be20 =====

void PdoIdleAcquireLock(longlong param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0x70) + 0x2b8);
  *param_2 = uVar1;
  return;
}



===== CompletionFdoSystemQueryPower @ 14000be50 =====

undefined8 CompletionFdoSystemQueryPower(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  longlong lVar2;
  undefined1 uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined2 uVar6;
  uint uVar7;
  undefined4 uVar8;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  if (*(int *)(param_2 + 0x30) < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qLd(*(undefined8 *)(param_3 + 0x560));
    }
LAB_14000bf66:
    iVar4 = *(int *)(param_2 + 0x30);
  }
  else {
    uVar8 = 1;
    if (*(char *)(param_2 + 0x41) != '\0') {
      pbVar1 = (byte *)(lVar2 + 3);
      *pbVar1 = *pbVar1 | 1;
    }
    uVar7 = *(uint *)(lVar2 + 0x18);
    if (uVar7 == 1) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar3 = (undefined1)*(undefined8 *)(param_3 + 0x20);
        uVar6 = 0x2b;
        uVar8 = 1;
        uVar7 = 1;
LAB_14000bfe9:
        WPP_RECORDER_SF_qLL(*(undefined8 *)(param_3 + 0x560),4,3,uVar6,
                            &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,uVar3,(char)uVar7,
                            (char)uVar8);
      }
    }
    else {
      if ((((uVar7 != 2) && (uVar7 != 3)) && (uVar7 != 4)) && ((uVar7 != 5 && (uVar7 != 6))))
      goto LAB_14000bf66;
      uVar5 = MapSystemStateToDeviceState(param_3,uVar7);
      uVar8 = (undefined4)uVar5;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar6 = 0x2a;
        uVar3 = (undefined1)*(undefined8 *)(param_3 + 0x20);
        goto LAB_14000bfe9;
      }
    }
    iVar4 = PoRequestPowerIrp(*(undefined8 *)(param_3 + 0x20),3,uVar8,CallbackFdoDeviceQueryPower,
                              param_2,0);
    if (iVar4 == 0x103) {
      return 0xc0000016;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(param_3 + 0x560),2,8,0x2c,
                         &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                         (char)*(undefined8 *)(param_3 + 0x20),(char)iVar4);
    }
  }
  *(int *)(param_2 + 0x30) = iVar4;
  PoStartNextPowerIrp(param_2);
  IofCompleteRequest(param_2,0);
  UsbcReleaseRemoveLock(param_3,param_2);
  IoReleaseRemoveLockEx(param_3 + 200,param_2,0x20);
  return 0xc0000016;
}



===== CompletionFdoSystemSetPower @ 14000c060 =====

undefined8 CompletionFdoSystemSetPower(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  longlong lVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  uint uVar7;
  bool bVar8;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  bVar8 = false;
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(lVar2 + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  if (*(int *)(param_2 + 0x30) < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(param_3 + 0x560),2,8,0xf,
                         &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                         (char)*(undefined8 *)(param_3 + 0x20),(char)*(int *)(param_2 + 0x30));
    }
  }
  else {
    uVar7 = *(uint *)(lVar2 + 0x18);
    if (uVar7 == 1) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qLL(*(undefined8 *)(param_3 + 0x560),4,3,0x12,
                            &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                            (char)*(undefined8 *)(param_3 + 0x20),1,1);
      }
      iVar4 = FdoSendSetPowerRequest(1,(undefined *)0x0,0,param_3);
      if ((iVar4 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(param_3 + 0x560),2,8,0x13,
                           &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                           (char)*(undefined8 *)(param_3 + 0x20),(char)iVar4);
      }
      iVar4 = *(int *)(param_2 + 0x30);
      uVar3 = KeAcquireSpinLockRaiseToDpc(param_3 + 0x158);
      if ((*(uint *)(param_3 + 0x4d4) & 1) != 0) {
        iVar5 = KeReadStateEvent(param_3 + 0x138);
        uVar7 = *(uint *)(param_3 + 0x4d4) & 0xfffffffe;
        bVar8 = iVar5 != 0;
        if (!bVar8) {
          uVar7 = uVar7 | 4;
        }
        *(uint *)(param_3 + 0x4d4) = uVar7;
      }
      KeReleaseSpinLock(param_3 + 0x158,uVar3);
      if (bVar8) {
        AllocateWorker(param_3,IdleTimerEnableWorker,0);
      }
      goto LAB_14000c1c9;
    }
    if ((((uVar7 == 2) || (uVar7 == 3)) || (uVar7 == 4)) || ((uVar7 == 5 || (uVar7 == 6)))) {
      uVar6 = MapSystemStateToDeviceState(param_3,uVar7);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qLL(*(undefined8 *)(param_3 + 0x560),4,3,0x10,
                            &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                            (char)*(undefined8 *)(param_3 + 0x20),(char)uVar7,(char)uVar6);
      }
      iVar4 = FdoSendSetPowerRequest((int)uVar6,CallbackFdoDeviceSetDx,param_2,param_3);
      if (iVar4 == 0x103) {
        return 0xc0000016;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qd(*(undefined8 *)(param_3 + 0x560),2,8,0x11,
                           &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                           (char)*(undefined8 *)(param_3 + 0x20),(char)iVar4);
      }
      goto LAB_14000c1c9;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qL(*(undefined8 *)(param_3 + 0x560),2,8,0x14,
                         &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                         (char)*(undefined8 *)(param_3 + 0x20),(char)uVar7);
    }
  }
  iVar4 = *(int *)(param_2 + 0x30);
LAB_14000c1c9:
  PoStartNextPowerIrp(param_2);
  *(int *)(param_2 + 0x30) = iVar4;
  IofCompleteRequest(param_2,0);
  UsbcReleaseRemoveLock(param_3,param_2);
  IoReleaseRemoveLockEx(param_3 + 200,param_2,0x20);
  return 0xc0000016;
}



===== MapSystemStateToDeviceState @ 14000c3c4 =====

undefined8 MapSystemStateToDeviceState(longlong param_1,uint param_2)

{
  undefined1 uVar1;
  undefined8 uVar2;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 400);
  if (((*(char *)(param_1 + 0x1b8) == '\0') || (6 < param_2)) ||
     (uVar2 = 3, 3 < *(int *)(param_1 + 0x98 + (longlong)(int)param_2 * 4))) {
    uVar2 = 4;
  }
  KeReleaseSpinLock(param_1 + 400,uVar1);
  return uVar2;
}



===== USBD_SyncCompletionRoutine @ 14000c440 =====

undefined8 USBD_SyncCompletionRoutine(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== WPP_RECORDER_SF_dd @ 14000c46c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dd(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar1 * 0x50))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar1 * 0x50),0x2b,param_5,param_4,
               &param_6,4,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,4,&param_7,4,0);
  return;
}



===== CompletionFdoWaitWake @ 14000c5a0 =====

undefined8 CompletionFdoWaitWake(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  int iVar2;
  longlong lVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  
  uVar5 = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqd(*(undefined8 *)(param_3 + 0x560),4,3,0x23,
                        &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                        (char)*(undefined8 *)(param_3 + 0x20),(char)param_2,
                        (char)*(undefined4 *)(param_2 + 0x30));
  }
  LOCK();
  lVar3 = *(longlong *)(param_3 + 0x178);
  *(longlong *)(param_3 + 0x178) = 0;
  UNLOCK();
  if (lVar3 == 0) {
    LOCK();
    iVar2 = *(int *)(param_3 + 0x18c);
    *(int *)(param_3 + 0x18c) = 1;
    UNLOCK();
    uVar5 = 0;
    if (iVar2 == 0) {
      uVar5 = 0xc0000016;
    }
  }
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  *(longlong *)(param_3 + 0x180) = param_2;
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_3 + 0x158);
  KeResetEvent(param_3 + 0x1a0);
  KeReleaseSpinLock(param_3 + 0x158,uVar4);
  return uVar5;
}



===== WPP_RECORDER_SF_qqd @ 14000c6a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqd(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar1 * 0x50))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar1 * 0x50),0x2b,param_5,param_4,
               &param_6,8,&param_7,8,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,&param_7,8,&param_8,4,0);
  return;
}



===== BuildSelectConfigUrb @ 14000c804 =====

short * BuildSelectConfigUrb(longlong param_1,longlong param_2,longlong param_3,ushort param_4)

{
  byte bVar1;
  longlong lVar2;
  short *psVar3;
  ushort *puVar4;
  ulonglong uVar5;
  ushort uVar6;
  ushort *puVar7;
  ushort uVar8;
  ulonglong uVar9;
  ushort uVar10;
  uint uVar11;
  
  psVar3 = (short *)0x0;
  uVar8 = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),4,1,0x31,
                     &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids);
  }
  uVar9 = 0x28;
  uVar6 = 0;
  while( true ) {
    if (param_4 <= uVar6) {
      if (uVar8 == *(byte *)(param_2 + 4)) {
        psVar3 = (short *)ExAllocatePool2(0x40,uVar9,0x43627355);
        if (psVar3 != (short *)0x0) {
          puVar7 = (ushort *)(psVar3 + 0x14);
          for (uVar8 = 0; uVar8 < param_4; uVar8 = uVar8 + 1) {
            lVar2 = *(longlong *)(param_3 + (ulonglong)uVar8 * 0x10);
            bVar1 = *(byte *)(lVar2 + 4);
            uVar6 = (bVar1 + 1) * 0x18;
            if (uVar9 + (longlong)psVar3 < (ulonglong)uVar6 + (longlong)puVar7) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0x34,
                                 &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids);
              }
              ExFreePoolWithTag(psVar3,0x43627355);
              return (short *)0x0;
            }
            *(undefined1 *)(puVar7 + 1) = *(undefined1 *)(lVar2 + 2);
            *(undefined1 *)((longlong)puVar7 + 3) = *(undefined1 *)(lVar2 + 3);
            uVar11 = (uint)bVar1;
            *(uint *)(puVar7 + 8) = uVar11;
            if (uVar11 != 0) {
              puVar4 = puVar7 + 0x16;
              uVar5 = (ulonglong)uVar11;
              do {
                puVar4[-2] = 0xffff;
                puVar4[-1] = 0xffff;
                puVar4[0] = 0;
                puVar4[1] = 0;
                puVar4 = puVar4 + 0xc;
                uVar5 = uVar5 - 1;
              } while (uVar5 != 0);
            }
            *puVar7 = uVar6;
            puVar7 = (ushort *)((longlong)puVar7 + (ulonglong)uVar6);
          }
          *psVar3 = (short)uVar9;
          psVar3[1] = 0;
          *(longlong *)(psVar3 + 0xc) = param_2;
        }
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0x33,
                         &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids);
      }
      return psVar3;
    }
    uVar10 = (*(byte *)(*(longlong *)(param_3 + (ulonglong)uVar6 * 0x10) + 4) + 1) * 0x18;
    if ((int)(0xffff - (uint)uVar10) < (int)uVar9) break;
    uVar9 = (ulonglong)(ushort)((short)uVar9 + uVar10);
    *(undefined8 *)(param_3 + 8 + (ulonglong)uVar6 * 0x10) = 0;
    uVar8 = uVar8 + 1;
    uVar6 = uVar6 + 1;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0x32,
                     &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids);
  }
  return (short *)0x0;
}



===== InvokeParentIdleCallbackWorker @ 14000ca90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void InvokeParentIdleCallbackWorker(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined1 local_res10 [24];
  
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + -0x48;
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + -1;
  local_res10[0] = 0;
  puVar1 = *(undefined8 **)(*(longlong *)(param_2 + 0xb8) + 0x20);
  (*(code *)*puVar1)(puVar1[1]);
  IoAcquireCancelSpinLock(local_res10);
  if (*(char *)(param_2 + 0x44) == '\0') {
    LOCK();
    *(code **)(param_2 + 0x68) = ParentIdleCancelRoutine;
    UNLOCK();
    IoReleaseCancelSpinLock(local_res10[0]);
  }
  else {
    *(undefined1 *)(param_2 + 0x45) = local_res10[0];
    ParentIdleCancelRoutine(*(undefined8 *)(param_1 + 0x20),param_2);
  }
  return;
}



===== ParentIdleCancelRoutine @ 14000cb20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ParentIdleCancelRoutine(undefined8 param_1,longlong param_2)

{
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  (**(code **)(*(longlong *)(param_2 + 0xb8) + 0x38))
            (param_1,param_2,*(undefined8 *)(*(longlong *)(param_2 + 0xb8) + 0x40));
  return;
}



===== PdoIdlePeekNextIrp @ 14000cb80 =====

undefined8 * PdoIdlePeekNextIrp(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  if (param_2 == 0) {
    puVar2 = *(undefined8 **)(param_1 + 0x40);
  }
  else {
    puVar2 = *(undefined8 **)(param_2 + 0xa8);
  }
  puVar1 = puVar2 + -0x15;
  if (puVar2 == (undefined8 *)(param_1 + 0x40)) {
    puVar1 = (undefined8 *)0x0;
  }
  return puVar1;
}



===== PdoIdleReleaseLock @ 14000cbb0 =====

void PdoIdleReleaseLock(longlong param_1)

{
  KeReleaseSpinLock(*(longlong *)(param_1 + 0x70) + 0x2b8);
  return;
}



===== RtlStringCopyWorkerW @ 14000cbd8 =====

uint RtlStringCopyWorkerW(short *param_1,longlong param_2,longlong *param_3,longlong param_4)

{
  short sVar1;
  longlong lVar2;
  short *psVar3;
  longlong lVar4;
  longlong lVar5;
  
  lVar5 = 0;
  if (param_2 != 0) {
    lVar2 = 0x7ffffffe;
    lVar4 = param_4 - (longlong)param_1;
    do {
      if ((lVar2 == 0) || (sVar1 = *(short *)(lVar4 + (longlong)param_1), sVar1 == 0)) break;
      *param_1 = sVar1;
      lVar2 = lVar2 + -1;
      param_1 = param_1 + 1;
      lVar5 = lVar5 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  psVar3 = param_1 + -1;
  if (param_2 != 0) {
    psVar3 = param_1;
  }
  *psVar3 = 0;
  if (param_3 != (longlong *)0x0) {
    lVar2 = lVar5 + -1;
    if (param_2 != 0) {
      lVar2 = lVar5;
    }
    *param_3 = lVar2;
  }
  return ~-(uint)(param_2 != 0) & 0x80000005;
}



===== USBD_CreateHandle @ 14000cc54 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int USBD_CreateHandle(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
                     undefined8 *param_5)

{
  undefined4 *puVar1;
  bool bVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  undefined4 *_Dst;
  char *pcVar6;
  bool bVar7;
  undefined1 auStack_1e8 [32];
  int local_1c8;
  undefined4 local_1b8 [2];
  undefined8 local_1b0;
  code *local_1a0;
  code *local_178;
  undefined4 local_168;
  uint local_164;
  uint local_160;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_1e8;
  uVar4 = 0;
  bVar2 = false;
  cVar3 = KeGetCurrentIrql();
  if (cVar3 == '\0') {
    if (DAT_14001c430 == '\0') {
      DAT_14001c42c = 0;
      memset(&local_164,0,0x118);
      local_168 = 0x11c;
      iVar5 = RtlGetVersion(&local_168);
      if ((-1 < iVar5) && ((6 < local_164 || ((local_164 == 6 && (1 < local_160)))))) {
        DAT_14001c42c = 0x200;
      }
    }
    DAT_14001c430 = '\x01';
    if (param_1 == 0) {
      if (g_EnableDbgPrints != '\0') {
        pcVar6 = "DeviceObject cannot be NULL\n";
LAB_14000cd60:
        DbgPrintEx(0x4d,0,pcVar6);
      }
    }
    else {
      if (param_2 != 0) {
        if (param_5 == (undefined8 *)0x0) {
          if (g_EnableDbgPrints != '\0') {
            DbgPrintEx(0x4d,0,"USBDHandle cannot be NULL\n");
          }
          return -0x3ffffff3;
        }
        _Dst = (undefined4 *)ExAllocatePoolWithTag(DAT_14001c42c,0xe8,0x43627355);
        if (_Dst == (undefined4 *)0x0) {
          if (g_EnableDbgPrints != '\0') {
            DbgPrintEx(0x4d,0,"Allocation Failed\n");
          }
          iVar5 = -0x3fffff66;
          goto LAB_14000d053;
        }
        memset(_Dst,0,0xe8);
        puVar1 = _Dst + 2;
        USBDInternal_QueryUsbVerifierSettings(param_1,(longlong)puVar1);
        *_Dst = 0x44425355;
        *(undefined2 *)((longlong)_Dst + 10) = 0x603;
        _Dst[0x36] = 0x603;
        *(undefined2 *)puVar1 = 200;
        _Dst[10] = 0x602;
        *(longlong *)(_Dst + 0xe) = param_1;
        _Dst[0x10] = 0x43627355;
        *(undefined4 **)(_Dst + 0x12) = _Dst;
        *(longlong *)(_Dst + 0x34) = param_2;
        _Dst[0x37] = 1;
        iVar5 = USBDInternal_BuildAndSendQueryInterfaceSynchronously
                          (param_1,param_2,&GUID_USBD_INTERFACE,(undefined2 *)puVar1);
        if (iVar5 < 0) {
          if (g_EnableDbgPrints != '\0') {
            local_1c8 = iVar5;
            DbgPrintEx(0x4d,3,
                       "Core stack (TargetDevieObject 0x%p) failed USBD_INTERFACE_VERSION_603, 0x%x\n"
                       ,param_2);
          }
          *(undefined2 *)(_Dst + 2) = 0x98;
          *(undefined2 *)((longlong)_Dst + 10) = 0x602;
          _Dst[0x36] = 0x602;
          iVar5 = USBDInternal_BuildAndSendQueryInterfaceSynchronously
                            (param_1,param_2,&GUID_USBD_INTERFACE,(undefined2 *)(_Dst + 2));
          if (-1 < iVar5) goto LAB_14000ce84;
          bVar7 = g_EnableDbgPrints != '\0';
          _Dst[0x36] = 0x600;
          if (bVar7) {
            local_1c8 = iVar5;
            DbgPrintEx(0x4d,3,
                       "Core stack (TargetDevieObject 0x%p) failed USBD_INTERFACE_VERSION_602, 0x%x\n"
                       ,param_2);
          }
          iVar5 = 0;
        }
        else {
          _Dst[0x36] = (uint)*(ushort *)((longlong)_Dst + 10);
LAB_14000ce84:
          bVar2 = true;
        }
        if (g_EnableDbgPrints != '\0') {
          DbgPrintEx(0x4d,3,"USBD_CreateHandle Successful: usbdHandleInfo 0x%p\n",_Dst);
        }
        if (_Dst[0x36] == 0x600) {
          memset(local_1b8,0,0x48);
          local_1b8[0] = 0x10048;
          iVar5 = USBDInternal_BuildAndSendQueryInterfaceSynchronously
                            (param_1,param_2,&USB_BUS_INTERFACE_USBDI_GUID,(undefined2 *)local_1b8);
          if (iVar5 < 0) {
            if (g_EnableDbgPrints != '\0') {
              local_1c8 = iVar5;
              DbgPrintEx(0x4d,0,
                         "Core stack (TargetDevieObject 0x%p) failed query to USB_BUS_INTERFACE_USBDI_GUID : USB_BUSIF_USBDI_VERSION_1, 0x%x\n"
                         ,param_2);
            }
            _Dst[0x36] = 0xffffffff;
            iVar5 = 0;
          }
          else {
            if (local_178 != (code *)0x0) {
              uVar4 = (*local_178)(local_1b0);
            }
            *(undefined1 *)(_Dst + 0x38) = uVar4;
            (*local_1a0)(local_1b0);
          }
LAB_14000cf26:
          *param_5 = _Dst;
          return iVar5;
        }
        if (-1 < iVar5) goto LAB_14000cf26;
        if ((bVar2) && (*(code **)(_Dst + 0x1c) != (code *)0x0)) {
          (**(code **)(_Dst + 0x1c))(*(undefined8 *)(_Dst + 0xc));
        }
        ExFreePoolWithTag(_Dst,0x43627355);
        goto LAB_14000d053;
      }
      if (g_EnableDbgPrints != '\0') {
        pcVar6 = "TargetDeviceObject cannot be NULL\n";
        goto LAB_14000cd60;
      }
    }
    iVar5 = -0x3ffffff3;
  }
  else {
    if (g_EnableDbgPrints != '\0') {
      DbgPrintEx(0x4d,0,"Irql Too High\n");
    }
    iVar5 = -0x3ffffeb8;
  }
  if (param_5 == (undefined8 *)0x0) {
    return iVar5;
  }
LAB_14000d053:
  *param_5 = 0;
  return iVar5;
}



===== USBDInternal_BuildAndSendQueryInterfaceSynchronously @ 14000d064 =====

int USBDInternal_BuildAndSendQueryInterfaceSynchronously
              (undefined8 param_1,longlong param_2,undefined8 param_3,undefined2 *param_4)

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
  KeInitializeEvent(&local_28,0,0);
  lVar3 = IoAllocateIrp(*(undefined1 *)(param_2 + 0x4c),0);
  if (lVar3 == 0) {
    if (g_EnableDbgPrints != '\0') {
      DbgPrintEx(0x4d,0,"Failed to allocate Query Interface Irp for Target Device Ojbect 0x%p\n",
                 param_2);
    }
    iVar2 = -0x3fffff66;
  }
  else {
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(undefined8 *)(lVar1 + -0x28) = 0;
    *(undefined2 **)(lVar1 + -0x30) = param_4;
    *(undefined2 *)(lVar1 + -0x48) = 0x81b;
    *(undefined8 *)(lVar1 + -0x40) = param_3;
    *(undefined2 *)(lVar1 + -0x38) = *param_4;
    *(undefined2 *)(lVar1 + -0x36) = param_4[1];
    iVar2 = IoSetCompletionRoutineEx(param_1,lVar3,USBD_SyncCompletionRoutine,&local_28,1,1,1);
    if (iVar2 < 0) {
      lVar1 = *(longlong *)(lVar3 + 0xb8);
      *(code **)(lVar1 + -0x10) = USBD_SyncCompletionRoutine;
      *(undefined8 **)(lVar1 + -8) = &local_28;
      *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    }
    *(undefined4 *)(lVar3 + 0x30) = 0xc00000bb;
    iVar2 = IofCallDriver(param_2,lVar3);
    if (iVar2 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      iVar2 = *(int *)(lVar3 + 0x30);
    }
    IoFreeIrp(lVar3);
  }
  return iVar2;
}



===== USBDInternal_QueryUsbVerifierSettings @ 14000d1ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void USBDInternal_QueryUsbVerifierSettings(longlong param_1,longlong param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  undefined8 *_Dst;
  code *pcVar6;
  longlong lVar7;
  longlong lVar8;
  longlong local_res8;
  longlong local_res10;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  puVar1 = (undefined4 *)(param_2 + 0x48);
  local_res10 = 0;
  local_res8 = 0;
  local_48 = 0;
  uStack_40 = 0;
  uVar2 = MmIsDriverVerifying(*(undefined8 *)(param_1 + 8));
  *puVar1 = uVar2;
  RtlInitUnicodeString(&local_48,L"IoOpenDriverRegistryKey");
  pcVar5 = (code *)MmGetSystemRoutineAddress(&local_48);
  if (pcVar5 == (code *)0x0) {
    uVar4 = USBDInternal_BuildServicePath(param_1,&local_res8);
    lVar8 = local_res8;
    if (-1 < (int)uVar4) goto LAB_14000d2cb;
  }
  else {
    iVar3 = (*pcVar5)(*(undefined8 *)(param_1 + 8),0,1,0,&local_res10);
    lVar8 = 0;
    if (iVar3 < 0) {
      if (g_EnableDbgPrints != '\0') {
        DbgPrintEx(0x4d,0,"IoOpenDriverRegistryKey failed with 0x%x\n",iVar3);
      }
      goto LAB_14000d52b;
    }
LAB_14000d2cb:
    _Dst = (undefined8 *)ExAllocatePoolWithTag(DAT_14001c42c,0x1c0,0x43627355);
    if (_Dst == (undefined8 *)0x0) {
      if (g_EnableDbgPrints != '\0') {
        DbgPrintEx(0x4d,0,"ExAllocatePoolWithTag for USBDInternal_QueryUsbVerifierSettings failed\n"
                  );
      }
    }
    else {
      memset(_Dst,0,0x1c0);
      _Dst[3] = puVar1;
      *_Dst = USBD_VerifierSettingsCallback;
      _Dst[2] = L"UsbVerifierEnabled";
      *(undefined4 *)(_Dst + 4) = 4;
      *(undefined4 *)(_Dst + 6) = 4;
      _Dst[5] = puVar1;
      _Dst[9] = L"UsbVerifierFailRegistration";
      _Dst[10] = param_2 + 0x4c;
      _Dst[0xc] = param_2 + 0x4c;
      _Dst[7] = USBD_VerifierSettingsCallback;
      *(undefined4 *)(_Dst + 0xb) = 4;
      *(undefined4 *)(_Dst + 0xd) = 4;
      _Dst[0x10] = L"UsbVerifierFailChainedMdlSupport";
      _Dst[0x11] = param_2 + 0x50;
      _Dst[0x13] = param_2 + 0x50;
      _Dst[0xe] = USBD_VerifierSettingsCallback;
      *(undefined4 *)(_Dst + 0x12) = 4;
      *(undefined4 *)(_Dst + 0x14) = 4;
      _Dst[0x17] = L"UsbVerifierFailStaticStreamSupport";
      _Dst[0x18] = param_2 + 0x54;
      _Dst[0x1a] = param_2 + 0x54;
      _Dst[0x15] = USBD_VerifierSettingsCallback;
      *(undefined4 *)(_Dst + 0x19) = 4;
      *(undefined4 *)(_Dst + 0x1b) = 4;
      _Dst[0x1e] = L"UsbVerifierStaticStreamCountOverride";
      _Dst[0x1f] = param_2 + 0x58;
      _Dst[0x21] = param_2 + 0x58;
      _Dst[0x1c] = USBD_VerifierSettingsCallback;
      *(undefined4 *)(_Dst + 0x20) = 4;
      *(undefined4 *)(_Dst + 0x22) = 4;
      _Dst[0x25] = L"UsbVerifierFailEnableStaticStreams";
      _Dst[0x26] = param_2 + 0x5c;
      _Dst[0x28] = param_2 + 0x5c;
      _Dst[0x23] = USBD_VerifierSettingsCallback;
      *(undefined4 *)(_Dst + 0x27) = 4;
      *(undefined4 *)(_Dst + 0x29) = 4;
      _Dst[0x2c] = L"UsbVerifierFailSecureTransferSupport";
      _Dst[0x2a] = USBD_VerifierSettingsCallback;
      *(undefined4 *)(_Dst + 0x2e) = 4;
      *(undefined4 *)(_Dst + 0x30) = 4;
      _Dst[0x2d] = param_2 + 0xa0;
      _Dst[0x2f] = param_2 + 0xa0;
      lVar7 = lVar8;
      if (pcVar5 != (code *)0x0) {
        lVar7 = local_res10;
      }
      local_38 = 0;
      uStack_30 = 0;
      RtlInitUnicodeString(&local_38,L"RtlQueryRegistryValuesEx");
      pcVar6 = (code *)MmGetSystemRoutineAddress(&local_38);
      if (pcVar6 == (code *)0x0) {
        pcVar6 = RtlQueryRegistryValues_exref;
      }
      iVar3 = (*pcVar6)((-(uint)(pcVar5 != (code *)0x0) & 0x3fffffff) + 1,lVar7,_Dst,0,0);
      if ((iVar3 < 0) && (g_EnableDbgPrints != '\0')) {
        DbgPrintEx(0x4d,0,"RtlQueryRegistrySettings failed, ignoring this error0x%x\n",iVar3);
      }
      ExFreePoolWithTag(_Dst,0x43627355);
    }
  }
  if (lVar8 != 0) {
    ExFreePoolWithTag(lVar8,0x43627355);
  }
LAB_14000d52b:
  if (local_res10 != 0) {
    ZwClose();
  }
  return;
}



===== USBDInternal_BuildServicePath @ 14000d560 =====

uint USBDInternal_BuildServicePath(longlong param_1,undefined8 *param_2)

{
  uint uVar1;
  ushort uVar2;
  longlong lVar3;
  uint uVar4;
  longlong lVar5;
  short *_Dst;
  
  lVar3 = *(longlong *)(param_1 + 8);
  _Dst = (short *)0x0;
  if (0x10 < *(ushort *)(lVar3 + 0x38)) {
    lVar5 = RtlCompareMemory(*(undefined8 *)(lVar3 + 0x40),L"\\Driver\\",0x10);
    if (lVar5 == 0x10) {
      lVar5 = *(longlong *)(lVar3 + 0x40);
      uVar2 = *(ushort *)(lVar3 + 0x38);
      uVar1 = uVar2 + 8;
      _Dst = (short *)ExAllocatePoolWithTag(DAT_14001c42c,uVar1,0x43627355);
      if (_Dst == (short *)0x0) {
        uVar4 = 0xc000009a;
        if (g_EnableDbgPrints != '\0') {
          DbgPrintEx(0x4d,0,"Couldnt allocate servicePath of size %d\n",uVar1);
        }
      }
      else {
        memset(_Dst,0,(ulonglong)uVar1);
        memmove(_Dst,(void *)(lVar5 + 0x10),(ulonglong)(uVar2 - 0x10));
        uVar4 = RtlStringCbCatW(_Dst,(ulonglong)uVar1);
        if ((int)uVar4 < 0) {
          if (g_EnableDbgPrints != '\0') {
            DbgPrintEx(0x4d,0,"RtlStringCchCatW failed with status 0x%x",uVar4);
          }
          ExFreePoolWithTag(_Dst,0x43627355);
          _Dst = (short *)0x0;
        }
        else {
          uVar4 = 0;
        }
      }
      goto LAB_14000d6a4;
    }
  }
  if (g_EnableDbgPrints != '\0') {
    DbgPrintEx(0x4d,0,"Unexpected Driver name, Drvobj 0x%p\n",lVar3);
  }
  uVar4 = 0xc00000e5;
LAB_14000d6a4:
  *param_2 = _Dst;
  return uVar4;
}



===== MemDup @ 14000d6cc =====

void * MemDup(void *param_1,uint param_2)

{
  void *_Dst;
  
  _Dst = (void *)ExAllocatePool2(0x40,param_2,0x43627355);
  if (_Dst == (void *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(g_RecorderLog,2,8,0x35,&WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids,
                        (char)param_2);
    }
  }
  else {
    memmove(_Dst,param_1,(ulonglong)param_2);
  }
  return _Dst;
}



===== WaitWakeAcquireLock @ 14000d770 =====

void WaitWakeAcquireLock(longlong param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 200) + 400);
  *param_2 = uVar1;
  return;
}



===== QuerySelectiveSuspendRegistryFlag @ 14000d7a4 =====

void QuerySelectiveSuspendRegistryFlag(longlong param_1)

{
  undefined8 uVar1;
  int iVar2;
  int local_res8 [2];
  int local_res10 [2];
  uint in_stack_ffffffffffffffd8;
  uint uVar3;
  
  uVar1 = *(undefined8 *)(param_1 + 0xe0);
  uVar3 = in_stack_ffffffffffffffd8 & 0xffffff00;
  local_res10[0] = 0;
  local_res8[0] = 0;
  iVar2 = GetPdoRegistryParameter
                    (uVar1,L"DeviceSelectiveSuspended",(void *)0x0,0,(undefined4 *)0x0,
                     (undefined4 *)0x0,uVar3);
  if (((-1 < iVar2) &&
      (*(undefined1 *)(param_1 + 300) = 1,
      (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x188),5,1,0x3b,
                     &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids);
  }
  iVar2 = GetPdoRegistryParameter
                    (uVar1,L"SelSuspCancelBehavior",local_res10,4,local_res8,(undefined4 *)0x0,
                     uVar3 & 0xffffff00);
  if (((-1 < iVar2) && (local_res8[0] == 4)) &&
     ((local_res10[0] != 0 &&
      (*(undefined1 *)(param_1 + 0x12d) = 0,
      (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)))) {
    WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x188),4,1,0x3c,
                     &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids);
  }
  return;
}



===== CleanFunctionList @ 14000d8c8 =====

void CleanFunctionList(longlong param_1,uint param_2)

{
  longlong *plVar1;
  ulonglong uVar2;
  
  if (param_1 != 0) {
    if (param_2 != 0) {
      plVar1 = (longlong *)(param_1 + 0x30);
      uVar2 = (ulonglong)param_2;
      do {
        if (plVar1[-5] != 0) {
          ExFreePoolWithTag(plVar1[-5],0x43627355);
        }
        if (*plVar1 != 0) {
          ExFreePoolWithTag(*plVar1,0);
        }
        if (plVar1[-2] != 0) {
          ExFreePoolWithTag();
        }
        if (plVar1[2] != 0) {
          ExFreePoolWithTag();
        }
        plVar1 = plVar1 + 0xb;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    ExFreePoolWithTag(param_1,0x43627355);
  }
  return;
}



===== InitializeFunctionAssoc @ 14000d984 =====

undefined8 InitializeFunctionAssoc(longlong param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong *plVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  lVar4 = 0;
  *(char *)((longlong)param_2 + 5) = (char)param_3;
  *(char *)((longlong)param_2 + 6) = (char)param_4;
  *(undefined8 *)(param_2 + 4) = 0;
  *(undefined8 *)(param_2 + 0x12) = 0;
  *param_2 = 0x636e7546;
  RtlInitUnicodeString(param_2 + 10,0);
  RtlInitUnicodeString(param_2 + 6,0);
  RtlInitUnicodeString(param_2 + 0xe,0);
  uVar5 = (ulonglong)param_4;
  lVar1 = ExAllocatePool2(0x40,(ulonglong)param_4 * 8,0x43627355);
  *(longlong *)(param_2 + 2) = lVar1;
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    plVar3 = *(longlong **)(param_1 + 0x58);
    while ((plVar3 != (longlong *)0x0 && (*(byte *)(*plVar3 + 2) != param_3))) {
      plVar3 = plVar3 + 2;
    }
    if (param_4 != 0) {
      do {
        *(longlong **)(lVar4 + *(longlong *)(param_2 + 2)) = plVar3;
        plVar3 = plVar3 + 2;
        lVar4 = lVar4 + 8;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== QueryAllowIdleIrpInD3RegistryFlag @ 14000da80 =====

void QueryAllowIdleIrpInD3RegistryFlag(longlong param_1)

{
  int iVar1;
  int local_res8 [2];
  int local_res10 [2];
  uint in_stack_ffffffffffffffe8;
  
  local_res10[0] = 0;
  local_res8[0] = 0;
  iVar1 = GetPdoRegistryParameter
                    (*(undefined8 *)(param_1 + 0xe0),L"AllowIdleIrpInD3",local_res10,4,local_res8,
                     (undefined4 *)0x0,in_stack_ffffffffffffffe8 & 0xffffff00);
  if ((((-1 < iVar1) && (local_res8[0] == 4)) && (local_res10[0] != 0)) &&
     ((*(undefined1 *)(param_1 + 0x12e) = 1,
      (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED &&
      (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)))) {
    WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x188),5,1,0x3d,
                     &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids);
  }
  return;
}



===== UnblockPendedPdoD0Irp @ 14000db34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void UnblockPendedPdoD0Irp(longlong param_1,longlong param_2)

{
  int iVar1;
  code *pcVar2;
  undefined8 uVar3;
  char cVar4;
  
  pcVar2 = *(code **)(param_1 + 0x168);
  *(undefined8 *)(param_1 + 0x168) = 0;
  uVar3 = *(undefined8 *)(param_1 + 0x150);
  *(undefined8 *)(param_1 + 0x150) = 0;
  iVar1 = *(int *)(param_2 + 4);
  cVar4 = KeGetCurrentIrql();
  if (cVar4 == '\0') {
    EnableIdleTimer(param_2,'\x01',0x50534430);
  }
  (*pcVar2)(param_1,uVar3,-(uint)(iVar1 != 1) & 0xc000009c);
  return;
}



===== CheckIppUsbAltIndex @ 14000dbd4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 CheckIppUsbAltIndex(ushort param_1,ushort param_2,byte param_3)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined4 uVar4;
  undefined1 auStack_2f8 [32];
  undefined8 local_2d8;
  undefined8 local_2d0;
  undefined4 *local_2c8;
  undefined4 local_2b8;
  undefined4 local_2b4;
  longlong local_2b0;
  undefined8 local_2a8;
  undefined8 uStack_2a0;
  undefined8 *local_298;
  undefined8 uStack_290;
  undefined8 local_288;
  ulonglong uStack_280;
  undefined8 local_278;
  undefined8 uStack_270;
  undefined8 local_268;
  undefined8 uStack_260;
  wchar_t local_258 [16];
  wchar_t local_238 [264];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_2f8;
  local_2b0 = 0;
  local_2b8 = 0;
  local_2b4 = 0;
  local_288 = 0;
  uVar4 = 0;
  uStack_280 = uStack_280 & 0xffffffff00000000;
  lVar3 = 0;
  local_2d8 = CONCAT44(local_2d8._4_4_,(uint)param_2);
  local_278 = 0;
  uStack_270 = 0;
  local_268 = 0;
  uStack_260 = 0;
  local_2a8 = 0;
  uStack_2a0 = 0;
  local_298 = (undefined8 *)0x0;
  uStack_290 = 0;
  uVar2 = RtlStringCbPrintfW(local_238,0x208,
                             L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Print\\Monitors\\USB Monitor\\IppUsbAltIndex\\VID_%04X&PID_%04X"
                             ,(ulonglong)param_1);
  if (-1 < (int)uVar2) {
    uVar2 = RtlStringCbPrintfW(local_258,0x20,L"%d",(ulonglong)param_3);
    if (-1 < (int)uVar2) {
      local_2b8 = 0x14;
      lVar3 = ExAllocatePool2(0x100,0x14,0x43627355);
      if (lVar3 != 0) {
        RtlInitUnicodeString(&local_278,local_238);
        RtlInitUnicodeString(&local_268,local_258);
        uStack_2a0 = 0;
        local_298 = &local_278;
        local_2c8 = &local_2b4;
        local_2a8 = CONCAT44(local_2a8._4_4_,0x30);
        local_2d0 = (undefined4 *)((ulonglong)local_2d0._4_4_ << 0x20);
        local_2d8 = 0;
        uStack_290 = CONCAT44(uStack_290._4_4_,0x240);
        local_288 = 0;
        uStack_280 = 0;
        iVar1 = ZwCreateKey(&local_2b0,0xf003f,&local_2a8,0);
        if (-1 < iVar1) {
          local_2d0 = &local_2b8;
          local_2d8 = CONCAT44(local_2d8._4_4_,local_2b8);
          iVar1 = ZwQueryValueKey(local_2b0,&local_268,2,lVar3);
          if ((-1 < iVar1) && (uVar4 = 0, *(int *)(lVar3 + 0xc) != 0)) {
            uVar4 = 1;
          }
        }
      }
    }
  }
  if (local_2b0 != 0) {
    ZwClose();
  }
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0);
  }
  return uVar4;
}



===== RtlStringCbPrintfW @ 14000ddbc =====

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



===== WaitWakeReleaseLock @ 14000de40 =====

void WaitWakeReleaseLock(longlong param_1)

{
  KeReleaseSpinLock(*(longlong *)(param_1 + 200) + 400);
  return;
}



===== WPP_RECORDER_SF_qsd @ 14000de6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qsd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,char *param_7,undefined1 param_8)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  char *pcVar4;
  
  pcVar4 = param_7;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    if (param_7 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar3 = -1;
      do {
        lVar2 = lVar3;
        lVar3 = lVar2 + 1;
      } while (param_7[lVar3] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar1 = param_7;
    if (param_7 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,param_4,&param_6,8,pcVar1,lVar2,
               &param_8,4,0);
  }
  lVar2 = -1;
  if (pcVar4 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (pcVar4[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (pcVar4 == (char *)0x0) {
    pcVar4 = "NULL";
  }
  WppAutoLogTrace(param_1,4,3,&WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,param_4,&param_6,8,
                  pcVar4,lVar3,&param_8,4,0);
  return;
}



===== CallbackFdoDeviceQueryPower @ 14000e000 =====

void CallbackFdoDeviceQueryPower
               (longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
               undefined4 *param_5)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  PoStartNextPowerIrp(param_4);
  *(undefined4 *)(param_4 + 0x30) = *param_5;
  IofCompleteRequest(param_4,0);
  UsbcReleaseRemoveLock(lVar1 + 8,param_4);
  IoReleaseRemoveLockEx(lVar1 + 0xd0,param_4,0x20);
  return;
}



===== UsbcGetTopologyAddress @ 14000e078 =====

ulonglong UsbcGetTopologyAddress(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong local_38 [6];
  
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  local_38[4] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  KeInitializeEvent(local_38 + 2,0,0);
  lVar1 = IoBuildDeviceIoControlRequest
                    (0x22043f,*(undefined8 *)(param_1 + 0x28),0,0,0,0,1,local_38 + 2,local_38);
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    *(undefined8 **)(*(longlong *)(lVar1 + 0xb8) + -0x40) = param_2;
    uVar2 = IofCallDriver(*(undefined8 *)(param_1 + 0x28),lVar1);
    if ((int)uVar2 == 0x103) {
      WaitForSignal(local_38 + 2,
                    "event (waiting for IOCTL_INTERNAL_USB_GET_TOPOLOGY_ADDRESS to complete)",
                    *(undefined8 *)(param_1 + 0x560));
      uVar2 = local_38[0] & 0xffffffff;
    }
  }
  return uVar2;
}



===== WPP_RECORDER_SF_qs @ 14000e168 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qs(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,char *param_7)

{
  char *pcVar1;
  char *pcVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  
  pcVar2 = param_7;
  uVar3 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar3 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar3 * 0x50))) {
    if (param_7 == (char *)0x0) {
      lVar4 = 5;
    }
    else {
      lVar5 = -1;
      do {
        lVar4 = lVar5;
        lVar5 = lVar4 + 1;
      } while (param_7[lVar5] != '\0');
      lVar4 = lVar4 + 2;
    }
    pcVar1 = param_7;
    if (param_7 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar3 * 0x50),0x2b,param_5,param_4,
               &param_6,8,pcVar1,lVar4,0);
  }
  lVar4 = -1;
  if (pcVar2 == (char *)0x0) {
    lVar5 = 5;
  }
  else {
    do {
      lVar5 = lVar4;
      lVar4 = lVar5 + 1;
    } while (pcVar2[lVar4] != '\0');
    lVar5 = lVar5 + 2;
  }
  if (pcVar2 == (char *)0x0) {
    pcVar2 = "NULL";
  }
  WppAutoLogTrace(param_1,param_2,param_3,param_5,param_4,&param_6,8,pcVar2,lVar5,0);
  return;
}



===== NotifyPdosOfSurprisePowerOn @ 14000e2fc =====

void NotifyPdosOfSurprisePowerOn(longlong param_1,char param_2)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  uint *puVar4;
  
  puVar4 = *(uint **)(param_1 + 0x80);
  uVar3 = 0;
  if (*puVar4 != 0) {
    do {
      lVar1 = *(longlong *)(*(longlong *)(puVar4 + uVar3 * 2 + 2) + 0x40);
      if (*(char *)(param_1 + 0x55a) != '\0') {
        *(undefined1 *)(*(longlong *)(lVar1 + 0x188) + 0x3b) = 0;
      }
      if (*(int *)(lVar1 + 0x18) != 1) {
        *(undefined4 *)(lVar1 + 0x78) = 2;
        PoFxNotifySurprisePowerOn();
        if (param_2 != '\0') {
          CompletePdoWaitWakeIrp(lVar1 + 8,0xc0000120,puVar4);
          CompleteFunctionIdleIrp(lVar1 + 8,0xc0000120);
        }
      }
      puVar4 = *(uint **)(param_1 + 0x80);
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < *puVar4);
  }
  return;
}



===== FreeInterfaceList @ 14000e3ac =====

void FreeInterfaceList(longlong param_1,char param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  uint uVar4;
  ulonglong uVar5;
  
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x50);
  if (*(longlong *)(param_1 + 0x58) != 0) {
    uVar5 = 0;
    if (*(char *)(*(longlong *)(param_1 + 0x30) + 4) != '\0') {
      do {
        lVar1 = *(longlong *)(param_1 + 0x58);
        lVar2 = *(longlong *)(lVar1 + 8 + uVar5 * 0x10);
        if (lVar2 != 0) {
          ExFreePoolWithTag(lVar2,0x43627355);
          *(undefined8 *)(lVar1 + 8 + uVar5 * 0x10) = 0;
        }
        uVar4 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar4;
      } while (uVar4 < *(byte *)(*(longlong *)(param_1 + 0x30) + 4));
    }
    if (param_2 != '\0') {
      ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x58),0x43627355);
      *(undefined8 *)(param_1 + 0x58) = 0;
    }
  }
  KeReleaseSpinLock(param_1 + 0x50,uVar3);
  return;
}



===== WaitWakeInsertIrp @ 14000e490 =====

void WaitWakeInsertIrp(longlong param_1,longlong param_2)

{
  int *piVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong *plVar4;
  
  plVar4 = (longlong *)(param_2 + 0xa8);
  piVar1 = (int *)(*(longlong *)(param_1 + 200) + 0x198);
  *piVar1 = *piVar1 + 1;
  plVar2 = *(longlong **)(param_1 + 0x48);
  if (*plVar2 == param_1 + 0x40) {
    *plVar4 = param_1 + 0x40;
    *(longlong **)(param_2 + 0xb0) = plVar2;
    *plVar2 = (longlong)plVar4;
    *(longlong **)(param_1 + 0x48) = plVar4;
    return;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== RtlStringCchCopyA @ 14000e4d0 =====

uint RtlStringCchCopyA(char *param_1,undefined8 param_2,longlong param_3)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar2 = 0x10;
  lVar3 = param_3 - (longlong)param_1;
  do {
    if ((lVar2 == -0x7fffffee) || (param_1[lVar3] == '\0')) break;
    *param_1 = param_1[lVar3];
    param_1 = param_1 + 1;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  pcVar1 = param_1 + -1;
  if (lVar2 != 0) {
    pcVar1 = param_1;
  }
  *pcVar1 = '\0';
  return ~-(uint)(lVar2 != 0) & 0x80000005;
}



===== WaitWakeRemoveIrp @ 14000e520 =====

void WaitWakeRemoveIrp(longlong param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong *plVar5;
  
  plVar5 = (longlong *)(param_2 + 0xa8);
  piVar1 = (int *)(*(longlong *)(param_1 + 200) + 0x198);
  *piVar1 = *piVar1 + -1;
  lVar2 = *plVar5;
  if ((*(longlong **)(lVar2 + 8) == plVar5) &&
     (plVar3 = *(longlong **)(param_2 + 0xb0), (longlong *)*plVar3 == plVar5)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== CompletionForSuspendControlRequest @ 14000e560 =====

undefined8 CompletionForSuspendControlRequest(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  bool bVar5;
  char cVar6;
  
  lVar1 = *(longlong *)(param_3 + 0x180);
  lVar2 = *(longlong *)(param_3 + 0xe8);
  *(undefined1 *)(lVar1 + 0x3a) = 0;
  *(undefined4 *)(lVar1 + 0x58) = *(undefined4 *)(param_2 + 0x30);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(param_3 + 0x188),4,3,0x53,
                       &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                       (char)*(undefined8 *)(param_3 + 0xe0),(char)*(undefined4 *)(param_2 + 0x30));
  }
  lVar3 = *(longlong *)(lVar1 + 0x60);
  lVar4 = *(longlong *)(lVar3 + 0xb8);
  if ((*(int *)(param_2 + 0x30) < 0) && (*(int *)(lVar4 + 0x18) != 1)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(param_3 + 0x188),2,3,0x54,
                         &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                         (char)*(undefined8 *)(param_3 + 0xe0),(char)*(undefined8 *)(lVar1 + 0x28));
    }
    IoCancelIrp(*(undefined8 *)(lVar1 + 0x28));
  }
  IoReuseIrp(param_2,0);
  UsbcReleaseRemoveLock(lVar2,0x140001960);
  IoReleaseRemoveLockEx(lVar2 + 200,SendSetFeatureControlRequestForFunctionSuspend,0x20);
  if (*(int *)(lVar4 + 0x18) == 1) {
    cVar6 = '\0';
    bVar5 = false;
  }
  else {
    cVar6 = SetPdoIdle(lVar2,param_3,2,1,'\x01');
    bVar5 = *(int *)(lVar4 + 0x20) - 2U < 5;
  }
  *(undefined8 *)(lVar1 + 0x60) = 0;
  KeSetEvent(param_3 + 0x1a8,0,0);
  PoStartNextPowerIrp(lVar3);
  *(undefined4 *)(lVar3 + 0x30) = 0;
  IofCompleteRequest(lVar3,0);
  UsbcReleaseRemoveLock(lVar2,lVar3);
  IoReleaseRemoveLockEx(lVar2 + 200,lVar3,0x20);
  if ((cVar6 != '\0') && (!bVar5)) {
    ResumeIdleTimer(lVar2);
  }
  return 0xc0000016;
}



===== ValidateAndPopulateEndpointPriorities @ 14000e798 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ValidateAndPopulateEndpointPriorities(longlong param_1,wchar_t *param_2,uint param_3)

{
  longlong lVar1;
  char cVar2;
  short sVar3;
  uint uVar4;
  undefined4 uVar5;
  wchar_t *pwVar6;
  undefined8 *puVar7;
  uint *puVar8;
  undefined8 uVar9;
  undefined2 **ppuVar10;
  undefined7 uVar11;
  undefined2 uVar12;
  ulonglong uVar13;
  longlong lVar14;
  uint uVar15;
  ulonglong uVar16;
  undefined2 *puVar17;
  undefined1 auStackY_168 [32];
  undefined8 in_stack_fffffffffffffeb8;
  undefined8 local_138;
  wchar_t *pwStack_130;
  undefined8 local_128;
  longlong local_120;
  longlong local_118;
  uint local_110;
  uint local_10c;
  undefined2 *local_108;
  undefined2 *local_100;
  undefined2 *local_f8;
  undefined2 *local_f0;
  wchar_t *local_e8 [6];
  wchar_t local_b8 [56];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_168;
  local_128._0_4_ = 0;
  pwStack_130 = local_b8;
  local_118 = 0;
  local_e8[0] = (wchar_t *)0x0;
  local_e8[1] = (wchar_t *)0x0;
  uVar16 = 0;
  local_e8[2] = (wchar_t *)0x0;
  local_e8[3] = (wchar_t *)0x0;
  local_128._4_4_ = 0;
  local_e8[4] = (wchar_t *)0x0;
  local_e8[5] = (wchar_t *)0x0;
  local_10c = 0;
  uVar13 = (ulonglong)(param_3 >> 1);
  local_138 = 0x640000;
  for (pwVar6 = param_2; uVar15 = local_10c, *pwVar6 != L'\0'; pwVar6 = pwVar6 + local_118 + 1) {
    if (0x7fffffff < uVar13) {
      uVar4 = 0xc000000d;
LAB_14000e89a:
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x188),2,8,0xe,
                        &WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,(char)uVar4);
      return;
    }
    uVar4 = RtlStringLengthWorkerW(pwVar6,uVar13,&local_118);
    if ((int)uVar4 < 0) goto LAB_14000e89a;
    local_10c = uVar15 + 1;
    if (uVar13 - local_118 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return;
      }
      uVar12 = 0xf;
      goto LAB_14000e86f;
    }
    uVar13 = (uVar13 - local_118) - 1;
  }
  if (local_10c == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar12 = 0x10;
  }
  else {
    if (*(longlong *)(param_1 + 0x1d8) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x1d8),0x43627355);
      *(undefined4 *)(param_1 + 0x1e0) = 0;
    }
    local_118 = ExAllocatePool2(0x40,(ulonglong)uVar15 * 0x14,0x43627355);
    if (local_118 != 0) {
      local_110 = 0;
LAB_14000e97a:
      if (uVar15 <= local_110) {
        if ((int)uVar16 == 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            sVar3 = (short)uVar16 + 0x24;
LAB_14000f0ae:
            WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x188),2,8,sVar3,
                             &WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids);
          }
LAB_14000f0cf:
          ExFreePoolWithTag(local_118,0x43627355);
        }
        else {
          *(longlong *)(param_1 + 0x1d8) = local_118;
          *(int *)(param_1 + 0x1e0) = (int)uVar16;
        }
        return;
      }
      local_e8[0] = param_2;
      for (uVar15 = 1; uVar15 < 6; uVar15 = uVar15 + 1) {
        pwVar6 = wcschr(param_2,L',');
        if (pwVar6 == (wchar_t *)0x0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14000f0cf;
          sVar3 = 0x12;
          goto LAB_14000f0ae;
        }
        param_2 = pwVar6 + 1;
        *pwVar6 = L'\0';
        local_e8[uVar15] = param_2;
      }
      pwVar6 = wcschr(param_2,L'\0');
      local_138 = 0;
      pwStack_130 = (wchar_t *)0x0;
      param_2 = pwVar6 + 1;
      if (local_e8[0] != (wchar_t *)0x0) {
        local_120 = 0;
        pwVar6 = local_e8[0];
        uVar15 = RtlStringLengthWorkerW(local_e8[0],0x7fff,&local_120);
        if (-1 < (int)uVar15) {
          local_138._0_4_ = CONCAT22((short)local_120 * 2 + 2,(short)local_120 * 2);
          pwStack_130 = pwVar6;
          goto LAB_14000ea27;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar12 = 0x13;
          goto LAB_14000efc9;
        }
        goto LAB_14000f0cf;
      }
LAB_14000ea27:
      cVar2 = RtlEqualUnicodeString(&g_WildcardString,&local_138,0);
      if (cVar2 != '\x01') {
        uVar15 = RtlUnicodeStringToInteger(&local_138,0,&local_128);
        if ((int)uVar15 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar12 = 0x14;
            goto LAB_14000efc9;
          }
        }
        else {
          if ((uint)local_128 - 1 < 0xff) {
            puVar17 = (undefined2 *)(uVar16 * 0x14 + local_118);
            *puVar17 = (short)(uint)local_128;
            goto LAB_14000eab4;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar12 = 0x15;
            uVar15 = (uint)local_128;
LAB_14000f025:
            WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x188),2,8,uVar12,
                              &WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,(char)uVar15);
          }
        }
        goto LAB_14000f0cf;
      }
      puVar17 = (undefined2 *)(uVar16 * 0x14 + local_118);
      *puVar17 = 0xffff;
LAB_14000eab4:
      pwVar6 = local_e8[1];
      lVar1 = local_118;
      lVar14 = uVar16 * 0x14;
      uVar15 = 0;
      local_138 = 0;
      pwStack_130 = (wchar_t *)0x0;
      if (local_e8[1] == (wchar_t *)0x0) {
LAB_14000eb1f:
        local_f0 = puVar17;
        if ((int)uVar15 < 0) {
          local_108 = puVar17;
          local_100 = puVar17;
          local_f8 = puVar17;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar12 = 0x16;
            goto LAB_14000efc9;
          }
          goto LAB_14000f0cf;
        }
      }
      else {
        local_120 = 0;
        uVar15 = RtlStringLengthWorkerW(local_e8[1],0x7fff,&local_120);
        if ((int)uVar15 < 0) goto LAB_14000eb1f;
        pwStack_130 = pwVar6;
        local_138._0_4_ = CONCAT22((short)local_120 * 2 + 2,(short)local_120 * 2);
        local_f0 = (undefined2 *)(lVar14 + lVar1);
      }
      puVar17 = local_f0;
      local_108 = local_f0;
      local_100 = local_f0;
      local_f8 = local_f0;
      cVar2 = RtlEqualUnicodeString(&g_WildcardString,&local_138,0);
      if (cVar2 == '\x01') {
        sVar3 = -1;
      }
      else {
        uVar15 = RtlUnicodeStringToInteger(&local_138,0,&local_128);
        if ((int)uVar15 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar12 = 0x17;
            goto LAB_14000efc9;
          }
          goto LAB_14000f0cf;
        }
        if (0xff < (int)(uint)local_128) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar12 = 0x18;
            uVar15 = (uint)local_128;
            goto LAB_14000f025;
          }
          goto LAB_14000f0cf;
        }
        sVar3 = (ushort)*(byte *)(*(longlong *)(param_1 + 0xf0) + 5) + (short)(uint)local_128;
      }
      puVar17[1] = sVar3;
      local_138 = 0;
      pwStack_130 = (wchar_t *)0x0;
      if (local_e8[2] != (wchar_t *)0x0) {
        local_120 = 0;
        pwVar6 = local_e8[2];
        uVar15 = RtlStringLengthWorkerW(local_e8[2],0x7fff,&local_120);
        if ((int)uVar15 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar12 = 0x19;
            goto LAB_14000efc9;
          }
          goto LAB_14000f0cf;
        }
        local_138._0_4_ = CONCAT22((short)local_120 * 2 + 2,(short)local_120 * 2);
        pwStack_130 = pwVar6;
      }
      puVar8 = (uint *)0x0;
      cVar2 = RtlEqualUnicodeString(&g_WildcardString,&local_138,0);
      if (cVar2 == '\x01') {
        puVar17[1] = 0xffff;
LAB_14000ec51:
        local_138 = 0;
        pwStack_130 = (wchar_t *)0x0;
        if (local_e8[3] != (wchar_t *)0x0) {
          puVar8 = (uint *)&local_120;
          local_120 = 0;
          pwVar6 = local_e8[3];
          uVar15 = RtlStringLengthWorkerW(local_e8[3],0x7fff,(longlong *)puVar8);
          if ((int)uVar15 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar12 = 0x1c;
              goto LAB_14000efc9;
            }
            goto LAB_14000f0cf;
          }
          local_138._0_4_ = CONCAT22((short)local_120 * 2 + 2,(short)local_120 * 2);
          pwStack_130 = pwVar6;
        }
        uVar9 = CONCAT71((int7)((ulonglong)puVar8 >> 8),1);
        cVar2 = RtlEqualUnicodeString(&g_BulkIn,&local_138,uVar9);
        if (cVar2 != '\x01') {
          uVar9 = CONCAT71((int7)((ulonglong)uVar9 >> 8),1);
          cVar2 = RtlEqualUnicodeString(&g_BulkOut,&local_138,uVar9);
          if (cVar2 == '\x01') {
            uVar5 = 1;
            goto LAB_14000ecf0;
          }
          uVar9 = CONCAT71((int7)((ulonglong)uVar9 >> 8),1);
          puVar7 = &local_138;
          cVar2 = RtlEqualUnicodeString(&g_InterruptIn);
          if (cVar2 == '\x01') {
LAB_14000eefa:
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_14000ef24;
            uVar12 = 0x1e;
LAB_14000ef09:
            WPP_RECORDER_SF_S(*(undefined8 *)(param_1 + 0x188),puVar7,uVar9,uVar12,
                              in_stack_fffffffffffffeb8,pwStack_130);
          }
          else {
            uVar9 = CONCAT71((int7)((ulonglong)uVar9 >> 8),1);
            puVar7 = &local_138;
            cVar2 = RtlEqualUnicodeString(&g_InterruptOut);
            if (cVar2 == '\x01') goto LAB_14000eefa;
            uVar9 = CONCAT71((int7)((ulonglong)uVar9 >> 8),1);
            puVar7 = &local_138;
            cVar2 = RtlEqualUnicodeString(&g_IsochronousIn);
            if (cVar2 == '\x01') goto LAB_14000eefa;
            uVar9 = CONCAT71((int7)((ulonglong)uVar9 >> 8),1);
            puVar7 = &local_138;
            cVar2 = RtlEqualUnicodeString(&g_IsochronousOut);
            if (cVar2 == '\x01') goto LAB_14000eefa;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar12 = 0x1d;
              goto LAB_14000ef09;
            }
          }
LAB_14000ef24:
          uVar16 = (ulonglong)local_128._4_4_;
          local_110 = local_110 + 1;
          uVar15 = local_10c;
          goto LAB_14000e97a;
        }
        uVar5 = 0;
LAB_14000ecf0:
        *(undefined4 *)(local_108 + 4) = uVar5;
        local_138 = 0;
        pwStack_130 = (wchar_t *)0x0;
        if (local_e8[4] != (wchar_t *)0x0) {
          local_108 = (undefined2 *)0x0;
          pwVar6 = local_e8[4];
          uVar15 = RtlStringLengthWorkerW(local_e8[4],0x7fff,(longlong *)&local_108);
          if ((int)uVar15 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar12 = 0x1f;
              goto LAB_14000efc9;
            }
            goto LAB_14000f0cf;
          }
          local_138._0_4_ = CONCAT22((short)local_108 * 2 + 2,(short)local_108 * 2);
          pwStack_130 = pwVar6;
        }
        ppuVar10 = (undefined2 **)&local_128;
        uVar15 = RtlUnicodeStringToInteger(&local_138,0,ppuVar10);
        if (-1 < (int)uVar15) {
          if (0xf < (uint)local_128) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar12 = 0x21;
              uVar15 = (uint)local_128;
              goto LAB_14000efc9;
            }
            goto LAB_14000f0cf;
          }
          local_100[6] = (short)(uint)local_128;
          local_138 = 0;
          pwStack_130 = (wchar_t *)0x0;
          if (local_e8[5] != (wchar_t *)0x0) {
            ppuVar10 = &local_100;
            local_100 = (undefined2 *)0x0;
            pwVar6 = local_e8[5];
            uVar15 = RtlStringLengthWorkerW(local_e8[5],0x7fff,(longlong *)ppuVar10);
            if ((int)uVar15 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                uVar12 = 0x22;
                goto LAB_14000efc9;
              }
              goto LAB_14000f0cf;
            }
            local_138._0_4_ = CONCAT22((short)local_100 * 2 + 2,(short)local_100 * 2);
            pwStack_130 = pwVar6;
          }
          uVar11 = (undefined7)((ulonglong)ppuVar10 >> 8);
          cVar2 = RtlEqualUnicodeString(&g_Video);
          if (cVar2 == '\x01') {
            *(undefined4 *)(local_f8 + 8) = 1;
          }
          else {
            cVar2 = RtlEqualUnicodeString(&g_Voice);
            if (cVar2 == '\x01') {
              *(undefined4 *)(puVar17 + 8) = 2;
            }
            else {
              uVar9 = CONCAT71(uVar11,1);
              puVar7 = &local_138;
              cVar2 = RtlEqualUnicodeString(&g_Interactive);
              if (cVar2 != '\x01') {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar12 = 0x23;
                  goto LAB_14000ef09;
                }
                goto LAB_14000ef24;
              }
              *(undefined4 *)(local_f0 + 8) = 3;
            }
          }
          local_128._4_4_ = local_128._4_4_ + 1;
          goto LAB_14000ef24;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14000f0cf;
        uVar12 = 0x20;
      }
      else {
        puVar8 = (uint *)&local_128;
        uVar15 = RtlUnicodeStringToInteger(&local_138,0,puVar8);
        if ((int)uVar15 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14000f0cf;
          uVar12 = 0x1a;
        }
        else {
          if ((uint)local_128 < 0x100) {
            puVar17[2] = (short)(uint)local_128;
            goto LAB_14000ec51;
          }
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14000f0cf;
          uVar12 = 0x1b;
          uVar15 = (uint)local_128;
        }
      }
LAB_14000efc9:
      goto LAB_14000f025;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar12 = 0x11;
    local_118 = 0;
  }
LAB_14000e86f:
  WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x188),2,8,uVar12,
                   &WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids);
  return;
}



===== AllocateIdleIrp @ 14000f128 =====

undefined8 AllocateIdleIrp(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  lVar1 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x28) >> 8),
                                 *(undefined1 *)(*(longlong *)(param_1 + 0x28) + 0x4c)),0);
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0x42,
                        &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,0x9a);
    }
  }
  else {
    LOCK();
    *(longlong *)(param_1 + 0x290) = lVar1;
    UNLOCK();
  }
  return uVar2;
}



===== ResetPdoExtension @ 14000f1b0 =====

void ResetPdoExtension(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x2b8);
  *(undefined4 *)(param_2 + 0x128) = 0;
  KeReleaseSpinLock(param_1 + 0x2b8,uVar1);
  *(undefined4 *)(param_2 + 0x10) = 1;
  return;
}



===== WPP_RECORDER_SF_qc @ 14000f204 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qc(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
     (param_2 <= *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,param_4,&param_6,8,&param_7,1,0);
  }
  WppAutoLogTrace(param_1,param_2,2,&WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,param_4,
                  &param_6,8,&param_7,1,0);
  return;
}



===== WPP_RECORDER_SF_qcqd @ 14000f2f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qcqd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,0xd,&uStack0000000000000030,8,
               &uStack0000000000000038,1,&uStack0000000000000040,8,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,4,9,&WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,0xd,
                  &uStack0000000000000030,8,&uStack0000000000000038,1,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,0);
  return;
}



===== ValidateUSBInterfaceAssociationDescriptor @ 14000f440 =====

ulonglong ValidateUSBInterfaceAssociationDescriptor(char *param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  ulonglong uVar3;
  ushort uVar4;
  ushort uVar5;
  ulonglong uVar6;
  
  uVar3 = 0;
  if (*param_1 == '\b') {
    bVar1 = param_1[3];
    uVar3 = 0;
    while (uVar4 = (ushort)*(byte *)(*(longlong *)(param_2 + 0x38) + 4), (ushort)uVar3 < uVar4) {
      uVar6 = (ulonglong)((int)uVar3 + 1);
      lVar2 = *(longlong *)(*(longlong *)(param_2 + 0x58) + uVar3 * 0x10);
      if (*(byte *)(lVar2 + 2) == param_1[2]) {
        uVar5 = 1;
        if (bVar1 < 2) goto LAB_14000f4fb;
        goto LAB_14000f4ce;
      }
      uVar3 = uVar6 & 0xffff;
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar3 = WPP_RECORDER_SF_d(*(undefined8 *)(param_2 + 0x560),2,8,0x30,
                              &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids,*param_1);
  }
  return uVar3 & 0xffffffffffffff00;
  while( true ) {
    uVar5 = uVar5 + 1;
    uVar6 = (ulonglong)(ushort)((ushort)uVar6 + 1);
    if (bVar1 <= uVar5) break;
LAB_14000f4ce:
    if ((uVar4 <= (ushort)uVar6) ||
       (lVar2 = *(longlong *)(*(longlong *)(param_2 + 0x58) + (uVar6 & 0xffff) * 0x10),
       (uint)*(byte *)(lVar2 + 2) != (uint)uVar5 + (uint)(byte)param_1[2])) break;
  }
LAB_14000f4fb:
  return CONCAT71((int7)((ulonglong)lVar2 >> 8),uVar5 == bVar1);
}



===== WPP_RECORDER_SF_i @ 14000f540 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_i(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (1 < *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar1 * 0x50))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar1 * 0x50),0x2b,
               &WPP_93f6b87810f63f9db566694056813e32_Traceguids,param_4,&param_6,8,0);
  }
  WppAutoLogTrace(param_1,2,param_3,&WPP_93f6b87810f63f9db566694056813e32_Traceguids,param_4,
                  &param_6,8,0);
  return;
}



===== USBD_VerifierSettingsCallback @ 14000f640 =====

undefined8
USBD_VerifierSettingsCallback
          (undefined8 param_1,int param_2,undefined4 *param_3,int param_4,undefined8 param_5,
          undefined4 *param_6)

{
  if (param_2 != 4) {
    return 0xc000000d;
  }
  if (param_4 != 4) {
    return 0xc00000e5;
  }
  if (param_6 != param_3) {
    *param_6 = *param_3;
  }
  return 0;
}



===== PdoStartTimeoutDpc @ 14000f680 =====

void PdoStartTimeoutDpc(undefined8 param_1,longlong param_2)

{
  undefined1 uVar1;
  uint *puVar2;
  uint uVar3;
  ulonglong uVar4;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x2b8);
  puVar2 = *(uint **)(param_2 + 0x80);
  uVar4 = 0;
  if (*puVar2 != 0) {
    do {
      if ((*(uint *)(*(longlong *)(*(longlong *)(puVar2 + uVar4 * 2 + 2) + 0x40) + 0x130) & 8) != 0)
      {
        SetPdoIdle(param_2,*(longlong *)(*(longlong *)(puVar2 + uVar4 * 2 + 2) + 0x40) + 8,4,1,'\0')
        ;
      }
      puVar2 = *(uint **)(param_2 + 0x80);
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 < *puVar2);
  }
  KeReleaseSpinLock(param_2 + 0x2b8,uVar1);
  ResumeIdleTimer(param_2);
  return;
}



===== SubmitParentIdleIrp @ 14000f730 =====

ulonglong SubmitParentIdleIrp(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  ulonglong uVar3;
  
  IoReuseIrp(param_2,0);
  *(longlong *)(param_1 + 0x2a8) = param_1;
  *(undefined8 *)(param_1 + 0x2a0) = ParentIdleNotificationCallback;
  lVar1 = *(longlong *)(param_2 + 0xb8);
  *(undefined8 **)(lVar1 + -0x28) = (undefined8 *)(param_1 + 0x2a0);
  *(undefined1 *)(lVar1 + -0x48) = 0xf;
  *(undefined4 *)(lVar1 + -0x30) = 0x220027;
  *(undefined4 *)(lVar1 + -0x38) = 0x10;
  uVar3 = UsbcAcquireRemoveLock(param_1,0x70495353,param_2);
  if ((int)uVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,7,0xd,
                       &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids);
    }
  }
  else {
    SetCompletionRoutine
              (*(undefined8 *)(param_1 + 0x560),*(undefined8 *)(param_1 + 0x20),param_2,
               ParentIdleNotificationRequestComplete,param_1);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x560),4,7,0xe,
                        &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,(char)param_2);
    }
    uVar2 = IofCallDriver(*(undefined8 *)(param_1 + 0x28),param_2);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(param_1 + 0x560),4,7,0xf,
                         &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,(char)param_2,uVar2);
    }
  }
  return uVar3 & 0xffffffff;
}



===== WPP_RECORDER_SF_qS @ 14000f8a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qS(undefined8 param_1)

{
  longlong lVar1;
  wchar_t *pwVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 uStack0000000000000030;
  wchar_t *in_stack_00000038;
  
  lVar4 = -1;
  lVar3 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    if (in_stack_00000038 == (wchar_t *)0x0) {
      lVar1 = 10;
    }
    else {
      lVar1 = -1;
      do {
        lVar1 = lVar1 + 1;
      } while (in_stack_00000038[lVar1] != L'\0');
      lVar1 = lVar1 * 2 + 2;
    }
    pwVar2 = in_stack_00000038;
    if (in_stack_00000038 == (wchar_t *)0x0) {
      pwVar2 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,0x39,&uStack0000000000000030,8,
               pwVar2,lVar1,0);
  }
  if (in_stack_00000038 != (wchar_t *)0x0) {
    do {
      lVar4 = lVar4 + 1;
    } while (in_stack_00000038[lVar4] != L'\0');
    lVar3 = lVar4 * 2 + 2;
  }
  if (in_stack_00000038 == (wchar_t *)0x0) {
    in_stack_00000038 = L"NULL";
  }
  WppAutoLogTrace(param_1,4,1,&WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,0x39,
                  &uStack0000000000000030,8,in_stack_00000038,lVar3,0);
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 14000f9fc =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14001b727 < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== RtlStringCchPrintfA @ 14000fa28 =====

undefined8 RtlStringCchPrintfA(char *param_1,longlong param_2,char *param_3,undefined8 param_4)

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



===== WPP_RECORDER_SF_dq @ 14000fa9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,0x30,&uStack0000000000000030,4,
               &uStack0000000000000038,8,0);
  }
  WppAutoLogTrace(param_1,4,2,&WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,0x30,
                  &uStack0000000000000030,4,&uStack0000000000000038,8,0);
  return;
}



===== D3ColdSupportFunctionInterfaceDereference @ 14000fb70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void D3ColdSupportFunctionInterfaceDereference(longlong param_1)

{
  (**(code **)(*(longlong *)(param_1 + 0xe8) + 0x1d8))
            (*(undefined8 *)(*(longlong *)(param_1 + 0xe8) + 0x1c8));
  return;
}



===== WPP_RECORDER_SF_qqD @ 14000fb9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqD(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,0x1b,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,4,7,&WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,0x1b,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,0);
  return;
}



===== USBD_BuildRegisterCompositeDevice @ 14000fc90 =====

void USBD_BuildRegisterCompositeDevice
               (longlong param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  *(undefined8 *)(param_4 + 1) = 0;
  param_4[3] = 0;
  *param_4 = 0x180100;
  param_4[4] = param_2;
  param_4[5] = param_3;
  *(undefined8 *)(param_4 + 2) = *(undefined8 *)(param_1 + 0x30);
  return;
}



===== CompletionRemoteWakeNotication @ 14000fcc0 =====

undefined8 CompletionRemoteWakeNotication(undefined8 param_1,longlong param_2,longlong param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_3 + 0x180);
  puVar1 = (undefined8 *)(param_3 + 0xe0);
  puVar2 = (undefined8 *)(param_3 + 0x188);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqd(*puVar2,4,3,0x4e,&WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                        (char)*puVar1,(char)param_2,(char)*(undefined4 *)(param_2 + 0x30));
  }
  if (*(char *)(lVar3 + 0x3a) != '\0') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*puVar2,2,3,0x4f,&WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                         (char)*puVar1,(char)*(undefined8 *)(lVar3 + 0x48));
    }
    IoCancelIrp(*(undefined8 *)(lVar3 + 0x48));
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*puVar2,4,3,0x50,&WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                      (char)*puVar1);
  }
  IoQueueWorkItem(*(undefined8 *)(lVar3 + 0x50),ProcessWakeNotificationWorker,1,param_3);
  return 0xc0000016;
}



===== RecordStartFailData @ 14000fdec =====

void RecordStartFailData(longlong param_1,uint param_2,uint param_3,uint param_4,uint param_5,
                        void *param_6,uint param_7)

{
  uint uVar1;
  int iVar2;
  uint *_Dst;
  uint *_Src;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  
  uVar5 = param_7 + 0x24;
  if ((uVar5 & 7) != 0) {
    uVar5 = uVar5 + (8 - (uVar5 & 7));
  }
  if (*(int **)(param_1 + 0x480) == (int *)0x0) {
    iVar2 = 0x10;
  }
  else {
    iVar2 = **(int **)(param_1 + 0x480);
  }
  uVar1 = iVar2 + uVar5;
  if (0x33 < uVar1) {
    _Dst = (uint *)ExAllocatePool2(0x40,uVar1,0x43627355);
    if (_Dst != (uint *)0x0) {
      memset(_Dst,0,(ulonglong)uVar1);
      _Src = *(uint **)(param_1 + 0x480);
      puVar4 = _Dst + 4;
      if (_Src == (uint *)0x0) {
        uVar3 = uVar1 - 0x10;
      }
      else {
        uVar3 = uVar1;
        if (*_Src <= uVar1) {
          memmove(_Dst,_Src,(ulonglong)*_Src);
          _Src = *(uint **)(param_1 + 0x480);
          uVar3 = uVar1 - *_Src;
          puVar4 = (uint *)((longlong)_Dst + (ulonglong)*_Src);
        }
        ExFreePoolWithTag(_Src,0x43627355);
        *(undefined8 *)(param_1 + 0x480) = 0;
      }
      _Dst[3] = 0;
      *_Dst = uVar1;
      _Dst[1] = param_2;
      _Dst[2] = param_3;
      if (uVar3 < 0x24) {
        *(undefined8 *)(param_1 + 0x480) = 0;
        ExFreePoolWithTag(_Dst,0x43627355);
      }
      else {
        *puVar4 = 0x43727245;
        *(undefined8 *)(puVar4 + 2) = *(undefined8 *)(param_1 + 0x20);
        puVar4[4] = param_4;
        puVar4[5] = param_5;
        puVar4[6] = param_2;
        puVar4[7] = param_7;
        puVar4[1] = uVar5;
        if ((param_6 != (void *)0x0) && (param_7 <= uVar3 - 0x24)) {
          memmove(puVar4 + 8,param_6,(ulonglong)param_7);
        }
        *(uint **)(param_1 + 0x480) = _Dst;
      }
    }
  }
  return;
}



===== USBD_ValidateExtendedConfigurationDescriptor @ 14000ff80 =====

undefined8
USBD_ValidateExtendedConfigurationDescriptor
          (uint *param_1,uint param_2,longlong param_3,uint param_4)

{
  ushort uVar1;
  bool bVar2;
  longlong lVar3;
  byte bVar4;
  byte *pbVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  ushort uVar9;
  byte *pbVar10;
  uint *puVar11;
  uint uVar12;
  int iVar13;
  
  uVar8 = 0;
  uVar9 = 0;
  if (((param_1 == (uint *)0x0) || (param_2 < 0x10)) || (param_3 == 0)) {
    return 0xc000000d;
  }
  uVar1 = *(ushort *)(param_3 + 2);
  if (uVar1 < 9) {
    return 0xc000000d;
  }
  if (param_4 <= uVar1 && uVar1 != param_4) {
    return 0xc000000d;
  }
  lVar3 = ExAllocatePool2(0x40,0x100,0x43627355);
  if (lVar3 == 0) {
    return 0xc000009a;
  }
  uVar12 = (uint)*(byte *)(param_3 + 4);
  pbVar10 = (byte *)((ulonglong)*(ushort *)(param_3 + 2) + param_3);
  iVar13 = 0;
  for (pbVar5 = (byte *)(param_3 + 9); pbVar5 < pbVar10; pbVar5 = pbVar5 + *pbVar5) {
    if (pbVar10 < pbVar5 + *pbVar5) goto LAB_140010192;
    if (pbVar5[1] == 0xb) {
      *(undefined1 *)((ulonglong)pbVar5[2] + lVar3) = 1;
      for (uVar6 = 1; uVar6 < pbVar5[3]; uVar6 = uVar6 + 1) {
        if (0xff < pbVar5[2] + uVar6) goto LAB_140010192;
        *(undefined1 *)((ulonglong)(pbVar5[2] + uVar6) + lVar3) = 2;
      }
      iVar13 = iVar13 + 1;
      uVar12 = uVar12 - pbVar5[3];
    }
    if ((pbVar5[1] == 4) && (*(char *)((ulonglong)pbVar5[2] + lVar3) == '\0')) {
      *(undefined1 *)((ulonglong)pbVar5[2] + lVar3) = 1;
    }
    if (*pbVar5 == 0) break;
  }
  uVar6 = *param_1;
  if (((uVar6 - 0x10 < 0x1801) && (uVar6 <= param_2)) &&
     ((*(short *)((longlong)param_1 + 6) == 4 &&
      (((uint)(byte)param_1[2] <= iVar13 + uVar12 && ((uint)(byte)param_1[2] * 0x18 + 0x10 <= uVar6)
       ))))) {
    for (puVar11 = param_1 + 4; puVar11 < (uint *)((longlong)param_1 + (ulonglong)uVar6);
        puVar11 = puVar11 + 6) {
      bVar4 = (byte)*puVar11;
      if ((0x100 < bVar4) ||
         ((*(char *)((ulonglong)bVar4 + lVar3) != '\x01' && (1 < iVar13 + uVar12))))
      goto LAB_140010192;
      *(undefined1 *)((ulonglong)bVar4 + lVar3) = 3;
      bVar2 = false;
      for (uVar7 = 0; (uint)uVar7 < 8; uVar7 = (ulonglong)((uint)uVar7 + 1)) {
        bVar4 = *(byte *)(uVar7 + 2 + (longlong)puVar11);
        if (bVar4 == 0) {
          bVar2 = true;
        }
        else if (((bVar2) || (bVar4 = bVar4 - 0x30, 0x2f < bVar4)) ||
                ((0x87fffffe03ffU >> ((ulonglong)bVar4 & 0x3f) & 1) == 0)) goto LAB_140010192;
      }
      bVar2 = false;
      for (uVar7 = 0; (uint)uVar7 < 8; uVar7 = (ulonglong)((uint)uVar7 + 1)) {
        bVar4 = *(byte *)(uVar7 + 10 + (longlong)puVar11);
        if (bVar4 == 0) {
          bVar2 = true;
        }
        else if (((bVar2) || (bVar4 = bVar4 - 0x30, 0x2f < bVar4)) ||
                ((0x87fffffe03ffU >> ((ulonglong)bVar4 & 0x3f) & 1) == 0)) goto LAB_140010192;
      }
      uVar9 = uVar9 + 1;
    }
    if (uVar9 == (byte)param_1[2]) goto LAB_140010197;
  }
LAB_140010192:
  uVar8 = 0xc000000d;
LAB_140010197:
  ExFreePoolWithTag(lVar3,0);
  return uVar8;
}



===== GetControllerSuffix @ 1400101d4 =====

ulonglong GetControllerSuffix(short *param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  *param_1 = 0;
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xe8) + 0x28);
  lVar3 = IoAllocateIrp(CONCAT71((int7)((ulonglong)lVar3 >> 8),*(undefined1 *)(lVar3 + 0x4c)),0);
  if (lVar3 == 0) {
    uVar4 = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar4 = WPP_RECORDER_SF_(*(undefined8 *)(*(longlong *)(param_2 + 0xe8) + 0x560),2,8,0x43,
                               &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids);
    }
  }
  else {
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(undefined1 *)(lVar1 + -0x48) = 0xf;
    *(undefined4 *)(lVar1 + -0x30) = 0x220fbb;
    *(short **)(lVar1 + -0x40) = param_1;
    iVar2 = CallNextDriverSync(*(longlong *)(param_2 + 0xe8),lVar3,'\0');
    if ((iVar2 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_d(*(undefined8 *)(*(longlong *)(param_2 + 0xe8) + 0x560),2,8,0x42,
                        &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids,(char)iVar2);
    }
    uVar4 = IoFreeIrp(lVar3);
    if (*param_1 != 0) {
      return CONCAT71((int7)(uVar4 >> 8),1);
    }
  }
  return uVar4 & 0xffffffffffffff00;
}



===== _guard_check_icall @ 140010300 =====

void _guard_check_icall(void)

{
  return;
}



===== SendRemoteWakeNotificationIrp @ 140010310 =====

void SendRemoteWakeNotificationIrp(longlong param_1,longlong param_2)

{
  IofCallDriver(*(undefined8 *)(param_1 + 0x28),
                *(undefined8 *)(*(longlong *)(param_2 + 0x180) + 0x28));
  return;
}



===== RtlStringCbPrintfExW @ 14001033c =====

int RtlStringCbPrintfExW
              (wchar_t *param_1,ulonglong param_2,ulonglong *param_3,longlong *param_4,uint param_5,
              wchar_t *param_6,char param_7)

{
  ulonglong uVar1;
  int iVar2;
  ulonglong uVar3;
  ulonglong *puVar4;
  wchar_t *pwVar5;
  wchar_t *local_58;
  ulonglong local_50 [2];
  
  uVar3 = param_2 >> 1;
  iVar2 = 0;
  if ((param_5 & 0x100) == 0) {
    iVar2 = 0;
    if (0x7ffffffe < uVar3 - 1) {
      iVar2 = -0x3ffffff3;
    }
  }
  else if (((param_1 == (wchar_t *)0x0) && (uVar3 != 0)) || (0x7fffffff < uVar3)) {
    iVar2 = -0x3ffffff3;
  }
  if (iVar2 < 0) {
    if (uVar3 == 0) {
      return iVar2;
    }
    *param_1 = L'\0';
    return iVar2;
  }
  if (((param_5 & 0x100) != 0) && (param_6 == (wchar_t *)0x0)) {
    param_6 = L"";
  }
  iVar2 = 0;
  puVar4 = param_3;
  local_50[0] = uVar3;
  if ((param_5 & 0xffffe000) == 0) {
    if (uVar3 == 0) {
      pwVar5 = param_1;
      if (*param_6 == L'\0') goto LAB_14001042c;
      iVar2 = (-(uint)(param_1 != (wchar_t *)0x0) & 0xbffffff8) + 0xc000000d;
      local_58 = param_1;
    }
    else {
      local_50[0] = 0;
      puVar4 = local_50;
      local_58 = (wchar_t *)0x0;
      iVar2 = RtlStringVPrintfWorkerW(param_1,uVar3,puVar4,param_6,&param_7);
      uVar3 = uVar3 - local_50[0];
      pwVar5 = param_1 + local_50[0];
      local_58 = pwVar5;
      local_50[0] = uVar3;
      if (-1 < iVar2) {
        if (((param_5 >> 9 & 1) != 0) &&
           (uVar1 = (ulonglong)((uint)param_2 & 1) + uVar3 * 2, 2 < uVar1)) {
          memset(pwVar5 + 1,param_5 & 0xff,uVar1 - 2);
        }
        goto LAB_14001042c;
      }
    }
  }
  else {
    iVar2 = -0x3ffffff3;
    local_58 = param_1;
    if (uVar3 != 0) {
      *param_1 = L'\0';
      local_58 = param_1;
    }
  }
  if (((param_5 & 0x1c00) != 0) && (param_2 != 0)) {
    RtlStringExHandleOtherFlagsW(param_1,param_2,puVar4,&local_58,local_50,param_5);
  }
  uVar3 = local_50[0];
  pwVar5 = local_58;
  if (((iVar2 + 0x80000000U & 0x80000000) == 0) && (iVar2 != -0x7ffffffb)) {
    return iVar2;
  }
LAB_14001042c:
  if (param_3 != (ulonglong *)0x0) {
    *param_3 = (ulonglong)pwVar5;
  }
  if (param_4 != (longlong *)0x0) {
    *param_4 = (ulonglong)((uint)param_2 & 1) + uVar3 * 2;
  }
  return iVar2;
}



===== WPP_RECORDER_SF_dqs @ 140010508 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dqs(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,char *param_8)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  char *pcVar4;
  
  pcVar4 = param_8;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (1 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    if (param_8 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (param_8[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = param_8;
    if (param_8 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids,param_4,&param_6,4,&param_7,8,pcVar1
               ,lVar3,0);
  }
  lVar3 = -1;
  if (pcVar4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (pcVar4[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (pcVar4 == (char *)0x0) {
    pcVar4 = "NULL";
  }
  WppAutoLogTrace(param_1,2,1,&WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids,param_4,&param_6,4,
                  &param_7,8,pcVar4,lVar2,0);
  return;
}



===== WPP_RECORDER_SF_Dd @ 14001067c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Dd(undefined8 param_1,undefined8 param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4) >> (param_3 - 1 & 0x1f)
       & 1) != 0) && (1 < *(byte *)(WPP_GLOBAL_Control + 0x29 + uVar1 * 0x50))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18 + uVar1 * 0x50),0x2b,param_5,param_4,
               &param_6,4,&param_7,4,0);
  }
  WppAutoLogTrace(param_1,2,param_3,param_5,param_4,&param_6,4,&param_7,4,0);
  return;
}



===== GetBulkEndpointDescriptorAndPosition @ 1400107a8 =====

undefined8
GetBulkEndpointDescriptorAndPosition
          (longlong param_1,byte *param_2,uint param_3,undefined8 *param_4,int *param_5)

{
  byte *pbVar1;
  longlong lVar2;
  byte *pbVar3;
  undefined8 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  uVar4 = 0;
  iVar7 = 0;
  iVar5 = 0;
  pbVar3 = (byte *)0x0;
  pbVar1 = param_2 + 4;
  for (uVar6 = 0; uVar6 < *pbVar1; uVar6 = uVar6 + 1) {
    lVar2 = *(longlong *)(*(longlong *)(param_1 + 0xe8) + 0x38);
    pbVar3 = (byte *)USBD_ParseDescriptors(lVar2,*(undefined2 *)(lVar2 + 2),param_2,5);
    if (pbVar3 == (byte *)0x0) goto LAB_140010834;
    if (param_3 == uVar6) break;
    if ((pbVar3[3] & 3) == 2) {
      if ((char)pbVar3[2] < '\0') {
        iVar7 = iVar7 + 1;
      }
      else {
        iVar5 = iVar5 + 1;
      }
    }
    param_2 = pbVar3 + *pbVar3;
  }
  if ((pbVar3[3] & 3) == 2) {
    if (-1 < (char)pbVar3[2]) {
      iVar7 = iVar5;
    }
    *param_5 = iVar7;
    *param_4 = pbVar3;
  }
  else {
LAB_140010834:
    uVar4 = 0xc0000225;
  }
  return uVar4;
}



===== ReportStartFailData @ 14001087c =====

void ReportStartFailData(longlong param_1)

{
  uint uVar1;
  int iVar2;
  void *_Dst;
  longlong lVar3;
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
  if (*(uint **)(param_1 + 0x480) != (uint *)0x0) {
    uVar1 = **(uint **)(param_1 + 0x480);
    _Dst = (void *)ExAllocatePool2(0x40,uVar1,0x43627355);
    if (_Dst != (void *)0x0) {
      memmove(_Dst,*(void **)(param_1 + 0x480),(ulonglong)uVar1);
      KeInitializeEvent(&local_28,0,0);
      lVar3 = IoBuildDeviceIoControlRequest
                        (0x22002b,*(undefined8 *)(param_1 + 0x28),0,0,0,0,1,&local_28,&local_38);
      if (lVar3 != 0) {
        *(void **)(*(longlong *)(lVar3 + 0xb8) + -0x40) = _Dst;
        iVar2 = IofCallDriver(*(undefined8 *)(param_1 + 0x28),lVar3);
        if (iVar2 == 0x103) {
          WaitForSignal(&local_28,
                        "event (waiting for IOCTL_INTERNAL_USB_RECORD_FAILURE to complete)",
                        *(undefined8 *)(param_1 + 0x560));
        }
      }
      ExFreePoolWithTag(_Dst,0x43627355);
    }
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 1400109b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (longlong param_1,undefined8 param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  undefined7 extraout_var;
  uint uVar3;
  int local_res18 [4];
  
  uVar3 = (uint)param_2 & 1;
  local_res18[0] = param_3;
  uVar2 = wil_details_MapReportingKind(param_3,uVar3);
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(param_1,param_2,(ulonglong)uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (*(undefined4 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0,uVar3,local_res18,0
               ,0,1);
  }
  return;
}



===== GetInterfaceList @ 140010a3c =====

longlong GetInterfaceList(longlong param_1,void *param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  uint uVar7;
  uint uVar8;
  
  if (*(byte *)((longlong)param_2 + 4) == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0xd,
                       &WPP_93f6b87810f63f9db566694056813e32_Traceguids);
    }
    uVar8 = 9;
    uVar3 = 0xa0000006;
    uVar4 = 0xc000009c;
    uVar7 = 0x30624e49;
  }
  else {
    lVar1 = ExAllocatePool2(0x40,((ulonglong)*(byte *)((longlong)param_2 + 4) + 1) * 0x10);
    if (lVar1 != 0) {
      uVar4 = 0;
      uVar5 = 0;
      uVar6 = uVar5;
      if (*(char *)((longlong)param_2 + 4) != '\0') {
        do {
          lVar2 = USBD_ParseConfigurationDescriptorEx
                            (param_2,param_2,uVar4,0,0xffffffff,0xffffffff,0xffffffff);
          uVar5 = uVar6;
          if (lVar2 != 0) {
            if (((ulonglong)*(ushort *)((longlong)param_2 + 2) - lVar2) + (longlong)param_2 < 9) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,10,
                                 &WPP_93f6b87810f63f9db566694056813e32_Traceguids);
              }
            }
            else {
              *(undefined8 *)(lVar1 + 8 + uVar6 * 0x10) = 0;
              uVar5 = (ulonglong)((int)uVar6 + 1);
              *(longlong *)(lVar1 + uVar6 * 0x10) = lVar2;
            }
          }
          uVar4 = uVar4 + 1;
          if (0x100 < uVar4) {
            ExFreePoolWithTag(lVar1,0x43627355);
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0xb,
                               &WPP_93f6b87810f63f9db566694056813e32_Traceguids);
            }
            RecordStartFailData(param_1,0xc000009c,0,0xa0000006,0x494e544f,param_2,9);
            return 0;
          }
          uVar6 = uVar5;
        } while ((uint)uVar5 < (uint)*(byte *)((longlong)param_2 + 4));
      }
      *(undefined8 *)(lVar1 + uVar5 * 0x10) = 0;
      *(undefined8 *)(lVar1 + 8 + uVar5 * 0x10) = 0;
      return lVar1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0xc,
                       &WPP_93f6b87810f63f9db566694056813e32_Traceguids);
    }
    uVar8 = 0;
    uVar3 = 0xa0000005;
    param_2 = (void *)0x0;
    uVar4 = 0xc000009a;
    uVar7 = 0x494e544c;
  }
  RecordStartFailData(param_1,uVar4,0,uVar3,uVar7,param_2,uVar8);
  return 0;
}



===== GetFunctionMsOs20VendorRevision @ 140010ca4 =====

ulonglong GetFunctionMsOs20VendorRevision(longlong param_1,undefined2 *param_2)

{
  ulonglong uVar1;
  undefined **ppuVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  ulonglong local_res8;
  
  ppuVar2 = *(undefined ***)(param_1 + 0xe8);
  if ((ppuVar2[0x8d] != (undefined *)0x0) &&
     (ppuVar2 = (undefined **)GetFunctionMsOs20FunctionSubset(param_1), ppuVar2 != (undefined **)0x0
     )) {
    uVar4 = (ulonglong)*(ushort *)((longlong)ppuVar2 + 6) + (longlong)ppuVar2;
    uVar1 = (ulonglong)*(ushort *)ppuVar2 + (longlong)ppuVar2;
    do {
      if (uVar1 == 0) goto LAB_140010d11;
      local_res8 = uVar1;
      if (*(short *)(uVar1 + 2) == 8) {
        uVar3 = Feature_1916511546__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar3 == 0) || (uVar1 + 6 <= uVar4)) {
          uVar5 = *(undefined2 *)(uVar1 + 4);
          *param_2 = uVar5;
          return CONCAT71((uint7)(byte)((ushort)uVar5 >> 8),1);
        }
        ppuVar2 = &WPP_RECORDER_INITIALIZED;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140010d11;
        uVar5 = 0x50;
        goto LAB_140010d3d;
      }
      ppuVar2 = (undefined **)GetNextMsOs20Descriptor(uVar4,&local_res8);
      uVar1 = local_res8;
    } while ((char)ppuVar2 != '\0');
    ppuVar2 = &WPP_RECORDER_INITIALIZED;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = 0x51;
LAB_140010d3d:
      ppuVar2 = (undefined **)
                WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x188),2,8,uVar5,
                                 &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids);
    }
  }
LAB_140010d11:
  return (ulonglong)ppuVar2 & 0xffffffffffffff00;
}



===== GetNextMsOs20Descriptor @ 140010d98 =====

longlong GetNextMsOs20Descriptor(ulonglong param_1,ulonglong *param_2)

{
  short sVar1;
  ushort uVar2;
  short *psVar3;
  undefined1 uVar4;
  undefined **ppuVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined1 uVar8;
  undefined2 uVar9;
  
  psVar3 = (short *)*param_2;
  sVar1 = *psVar3;
  if (sVar1 == 0) {
LAB_140010ef9:
    *param_2 = 0;
    lVar6 = (ulonglong)(byte)((ushort)sVar1 >> 8) << 8;
  }
  else {
    uVar8 = 1;
    if (psVar3[1] == 2) {
      if ((sVar1 != 8) || (psVar3[3] == 0)) goto LAB_140010ef9;
      ppuVar5 = (undefined **)Feature_1916511546__private_IsEnabledDeviceUsageNoInline();
      if (((int)ppuVar5 != 0) && (uVar2 = psVar3[3], uVar2 < 0xc)) {
        ppuVar5 = &WPP_RECORDER_INITIALIZED;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar9 = 0x48;
LAB_140010e1b:
          uVar8 = 0xc;
LAB_140010eb6:
          ppuVar5 = (undefined **)
                    WPP_RECORDER_SF_dd(g_RecorderLog,3,8,uVar9,
                                       &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,(char)uVar2,
                                       uVar8);
        }
        goto LAB_140010ed0;
      }
LAB_140010e74:
      uVar7 = (ulonglong)(ushort)psVar3[3] + (longlong)psVar3;
LAB_140010ee4:
      uVar4 = 1;
      if (uVar7 == param_1) goto LAB_140010ed3;
      if ((param_1 < uVar7) || (param_1 < uVar7 + 4)) goto LAB_140010ed0;
      *param_2 = uVar7;
    }
    else {
      if (psVar3[1] == 1) {
        if ((sVar1 != 8) || (psVar3[3] == 0)) goto LAB_140010ef9;
        ppuVar5 = (undefined **)Feature_1916511546__private_IsEnabledDeviceUsageNoInline();
        if (((int)ppuVar5 == 0) || (uVar2 = psVar3[3], 0xb < uVar2)) goto LAB_140010e74;
        ppuVar5 = &WPP_RECORDER_INITIALIZED;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar9 = 0x49;
          goto LAB_140010e1b;
        }
      }
      else {
        uVar7 = Feature_1916511546__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar7 == 0) || (uVar2 = *(ushort *)*param_2, 3 < uVar2)) {
          ppuVar5 = (undefined **)*param_2;
          uVar7 = (ulonglong)*(ushort *)ppuVar5 + (longlong)ppuVar5;
          goto LAB_140010ee4;
        }
        ppuVar5 = &WPP_RECORDER_INITIALIZED;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar8 = 4;
          uVar9 = 0x4a;
          goto LAB_140010eb6;
        }
      }
LAB_140010ed0:
      uVar4 = 0;
LAB_140010ed3:
      uVar8 = uVar4;
      *param_2 = 0;
    }
    lVar6 = CONCAT71((int7)((ulonglong)ppuVar5 >> 8),uVar8);
  }
  return lVar6;
}



===== ParseUSBInterfaceAssociationDescriptors @ 140010f20 =====

uint ParseUSBInterfaceAssociationDescriptors(longlong param_1,longlong *param_2,int *param_3)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte bVar9;
  byte *pbVar10;
  int iVar11;
  undefined2 uVar12;
  uint uVar13;
  byte bVar14;
  int iVar15;
  ulonglong uVar16;
  byte *pbVar17;
  undefined4 *puVar18;
  byte bVar19;
  byte local_res8;
  ushort local_res20;
  uint uVar20;
  void *pvVar21;
  longlong local_78;
  
  pbVar10 = *(byte **)(param_1 + 0x38);
  iVar11 = 0;
  local_res20 = 0;
  uVar4 = 0;
  local_78 = 0;
  uVar3 = 0;
  bVar2 = false;
  bVar14 = pbVar10[4];
  pbVar17 = pbVar10 + *(ushort *)(pbVar10 + 2);
  bVar19 = 0;
  bVar9 = bVar14;
  for (pbVar7 = pbVar10; pbVar7 < pbVar17; pbVar7 = pbVar7 + *pbVar7) {
    if (pbVar7[1] == 0xb) {
      bVar1 = pbVar7[3];
      if (bVar9 < bVar1) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_dd(*(undefined8 *)(param_1 + 0x560),2,8,0x22,
                             &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids,bVar1,bVar9);
        }
        pvVar21 = *(void **)(param_1 + 0x30);
        uVar3 = (uint)*(ushort *)((longlong)pvVar21 + 2);
        uVar20 = 0x49414431;
        goto LAB_14001176f;
      }
      bVar19 = bVar19 + 1;
      bVar2 = true;
      bVar9 = bVar9 - bVar1;
    }
    if (*pbVar7 == 0) break;
  }
  bVar19 = bVar19 + bVar9;
  if (!bVar2) goto LAB_140011782;
  if (((bVar14 < bVar19) || (bVar19 == 0)) || (bVar14 < bVar9)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0x23,
                       &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids);
    }
    pvVar21 = *(void **)(param_1 + 0x30);
    uVar3 = (uint)*(ushort *)((longlong)pvVar21 + 2);
    uVar20 = 0x49414432;
LAB_14001176f:
    uVar4 = 0xc000009c;
    uVar13 = 0xa0000007;
  }
  else {
    local_78 = ExAllocatePool2(0x40,(ulonglong)bVar19 * 0x58,0x43627355);
    if (local_78 != 0) {
      uVar16 = 0;
      iVar15 = 0;
      local_res8 = 0;
      if (pbVar10 < pbVar17) {
        do {
          if (pbVar10[1] == 0xb) {
            uVar5 = ValidateUSBInterfaceAssociationDescriptor((char *)pbVar10,param_1);
            if ((char)uVar5 == '\0') {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0x25,
                                 &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids);
              }
              pvVar21 = *(void **)(param_1 + 0x30);
              uVar3 = (uint)*(ushort *)((longlong)pvVar21 + 2);
              uVar20 = 0x49414433;
            }
            else {
              uVar5 = Feature_3635125563__private_IsEnabledDeviceUsageNoInline();
              bVar14 = (byte)uVar3;
              if ((int)uVar5 == 0) {
                if ((bVar19 < bVar14) || ((int)uVar16 < (int)(bVar19 - uVar3))) goto LAB_140011195;
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar12 = 0x27;
                  goto LAB_140011138;
                }
              }
              else {
                if ((bVar14 <= bVar19) && ((int)uVar16 < (int)(bVar19 - uVar3))) {
LAB_140011195:
                  if (local_res8 == 0) {
                    if (((*(char *)(param_1 + 0x55c) == '\0') || (pbVar10[4] != 1)) ||
                       (pbVar10[6] != 0)) {
                      puVar18 = (undefined4 *)(uVar16 * 0x58 + local_78);
                      uVar6 = InitializeFunctionAssoc
                                        (param_1,puVar18,(uint)pbVar10[2],(uint)pbVar10[3]);
                      uVar4 = (uint)uVar6;
                      if ((int)uVar4 < 0) {
                        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                          WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0x29,
                                           &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids);
                        }
                        uVar20 = 0x50494132;
                        goto LAB_1400110b2;
                      }
                      bVar14 = (char)uVar16 + 1;
                      uVar16 = (ulonglong)bVar14;
                      *(byte **)(puVar18 + 4) = pbVar10;
                      *(byte *)(puVar18 + 1) = bVar14;
                    }
                    else {
                      uVar3 = (uint)(byte)(bVar14 + 1);
                    }
                    local_res8 = pbVar10[3];
                    local_res20 = (ushort)pbVar10[2];
                    goto LAB_14001121e;
                  }
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0x28,
                                     &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids);
                  }
                  pvVar21 = *(void **)(param_1 + 0x30);
                  uVar3 = (uint)*(ushort *)((longlong)pvVar21 + 2);
                  uVar20 = 0x49414435;
                  goto LAB_14001176f;
                }
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  uVar12 = 0x26;
LAB_140011138:
                  WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,uVar12,
                                   &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids);
                }
              }
              pvVar21 = *(void **)(param_1 + 0x30);
              uVar3 = (uint)*(ushort *)((longlong)pvVar21 + 2);
              uVar20 = 0x49414434;
            }
            goto LAB_14001176f;
          }
LAB_14001121e:
          pbVar7 = pbVar10;
          if ((pbVar10[1] == 4) && (pbVar10[3] == 0)) {
            if (local_res8 == 0) {
              bVar14 = (byte)uVar3;
              if ((pbVar10[5] != 0xd) &&
                 (((*(char *)(param_1 + 0x55c) == '\0' || (pbVar10[5] != 1)) || (pbVar10[7] != 0))))
              {
                uVar4 = 1;
                uVar5 = Feature_3635125563__private_IsEnabledDeviceUsageNoInline();
                if ((int)uVar5 == 0) {
                  if ((bVar19 < bVar14) || ((int)uVar16 < (int)(bVar19 - uVar3)))
                  goto LAB_140011327;
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    uVar12 = 0x2c;
                    goto LAB_1400112ca;
                  }
                }
                else {
                  if ((bVar14 <= bVar19) && ((int)uVar16 < (int)(bVar19 - uVar3))) {
LAB_140011327:
                    if ((pbVar10[5] == 1) && ((pbVar10[6] == 1 && (pbVar10[7] == 0)))) {
                      for (pbVar8 = pbVar10 + *pbVar10;
                          ((pbVar8 + 2 < pbVar17 && (pbVar8[1] != 0xb)) &&
                          ((pbVar8[1] != 4 || ((pbVar17 <= pbVar8 + 9 || (pbVar8[3] != 0))))));
                          pbVar8 = pbVar8 + *pbVar8) {
                      }
                      if (((((pbVar8 + 9 < pbVar17) && (pbVar8[1] == 4)) && (pbVar8[5] == 1)) &&
                          ((pbVar8[6] == 3 && (pbVar8[7] == 0)))) && (pbVar8[3] == 0)) {
                        uVar3 = (uint)(byte)(bVar14 + 1);
                        uVar4 = 2;
                        pbVar7 = pbVar8 + ((ulonglong)*pbVar8 - (ulonglong)*pbVar10);
                      }
                    }
                    puVar18 = (undefined4 *)(uVar16 * 0x58 + local_78);
                    uVar6 = InitializeFunctionAssoc(param_1,puVar18,(uint)pbVar10[2],uVar4);
                    uVar4 = (uint)uVar6;
                    if (-1 < (int)uVar4) {
                      bVar14 = (char)uVar16 + 1;
                      uVar16 = (ulonglong)bVar14;
                      *(byte *)(puVar18 + 1) = bVar14;
                      goto LAB_1400113e1;
                    }
                    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0x2d,
                                       &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids);
                    }
                    uVar20 = 0x50494133;
                    goto LAB_1400110b2;
                  }
                  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                    uVar12 = 0x2b;
LAB_1400112ca:
                    WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,uVar12,
                                     &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids);
                  }
                }
                pvVar21 = *(void **)(param_1 + 0x30);
                uVar3 = (uint)*(ushort *)((longlong)pvVar21 + 2);
                uVar20 = 0x49414437;
                goto LAB_14001176f;
              }
              uVar3 = (uint)(byte)(bVar14 + 1);
            }
            else {
              if (pbVar10[2] != local_res20) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0x2a,
                                   &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids);
                }
                RecordStartFailData(param_1,uVar4,0,0xa0000007,0x49414436,*(void **)(param_1 + 0x30)
                                    ,(uint)*(ushort *)((longlong)*(void **)(param_1 + 0x30) + 2));
                uVar4 = 0xc000009c;
                goto LAB_140011782;
              }
              local_res20 = local_res20 + 1;
              local_res8 = local_res8 - 1;
            }
          }
LAB_1400113e1:
          iVar15 = (int)uVar16;
        } while ((*pbVar10 != 0) && (pbVar10 = pbVar7 + *pbVar10, pbVar10 < pbVar17));
        if (local_res8 != 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0x2e,
                             &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids);
          }
          pvVar21 = *(void **)(param_1 + 0x30);
          uVar3 = (uint)*(ushort *)((longlong)pvVar21 + 2);
          uVar20 = 0x49414438;
          goto LAB_14001176f;
        }
      }
      if (iVar15 == bVar19 - uVar3) {
        if (-1 < (int)uVar4) {
          if ((byte)uVar3 < bVar19) {
            iVar11 = bVar19 - uVar3;
          }
          *param_3 = iVar11;
          *param_2 = local_78;
          return uVar4;
        }
        goto LAB_140011782;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_dd(*(undefined8 *)(param_1 + 0x560),2,8,0x2f,
                           &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids,(char)(bVar19 - uVar3),
                           (char)iVar15);
      }
      pvVar21 = *(void **)(param_1 + 0x30);
      uVar3 = (uint)*(ushort *)((longlong)pvVar21 + 2);
      uVar20 = 0x49414439;
      goto LAB_14001176f;
    }
    uVar4 = 0xc000009a;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0x24,
                       &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids);
    }
    uVar20 = 0x50494131;
LAB_1400110b2:
    uVar3 = 0;
    pvVar21 = (void *)0x0;
    uVar13 = 0xa0000005;
  }
  RecordStartFailData(param_1,uVar4,0,uVar13,uVar20,pvVar21,uVar3);
LAB_140011782:
  *param_3 = 0;
  *param_2 = 0;
  if (local_78 != 0) {
    CleanFunctionList(local_78,(uint)bVar19);
  }
  return uVar4;
}



===== SleepstudyHelper_ComponentActive @ 1400117c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SleepstudyHelper_ComponentActive(undefined *param_1)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  
  uVar3 = Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    iVar1 = 0;
    if (param_1 != &SleepstudyHelperUnsupportedHandle) {
      if (DAT_14001c510 == (code *)0x0) {
        iVar2 = -0x3fffff45;
      }
      else {
        iVar2 = (*DAT_14001c510)(param_1);
      }
      iVar1 = 0;
      if (iVar2 != -0x3fffff45) {
        iVar1 = iVar2;
      }
    }
  }
  else if (DAT_14001c510 == (code *)0x0) {
    iVar1 = -0x3fffff45;
  }
  else {
    iVar1 = (*DAT_14001c510)(param_1);
  }
  return iVar1;
}



===== SleepstudyHelper_ComponentInactive @ 140011850 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SleepstudyHelper_ComponentInactive(undefined *param_1)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  
  uVar3 = Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    iVar1 = 0;
    if (param_1 != &SleepstudyHelperUnsupportedHandle) {
      if (DAT_14001c518 == (code *)0x0) {
        iVar2 = -0x3fffff45;
      }
      else {
        iVar2 = (*DAT_14001c518)(param_1);
      }
      iVar1 = 0;
      if (iVar2 != -0x3fffff45) {
        iVar1 = iVar2;
      }
    }
  }
  else if (DAT_14001c518 == (code *)0x0) {
    iVar1 = -0x3fffff45;
  }
  else {
    iVar1 = (*DAT_14001c518)(param_1);
  }
  return iVar1;
}



===== WPP_RECORDER_SF_qLqL @ 1400118d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLqL
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (1 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,8,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,2,8,&WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,param_4,&param_6,8,
                  &param_7,4,&param_8,8,&param_9,4,0);
  return;
}



===== wil_details_FeatureReporting_IncrementUsageInCache @ 1400119f0 =====

void wil_details_FeatureReporting_IncrementUsageInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_1;
  do {
    uVar3 = uVar1;
    param_4[1] = 0;
    uVar1 = uVar3 | 1;
    if ((uVar3 >> 0xe & 1) != (uint)(param_2 == 4)) {
      uVar4 = uVar3 >> 5 & 0x1ff;
      if (uVar4 != 0) {
        param_4[1] = uVar4;
        param_4[2] = ~-(uint)(param_2 != 0) & 4;
        uVar1 = uVar3 & 0xffffc01f | 1;
      }
      uVar4 = 0;
      if (param_2 == 4) {
        uVar4 = 0x4000;
      }
      uVar1 = uVar4 | uVar1 & 0xffffbfff;
    }
    uVar2 = uVar1 >> 5 & 0x1ff;
    uVar4 = uVar2 + 1;
    if ((0x1ff < uVar4) || (uVar4 < uVar2)) {
      uVar4 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar2;
    }
    LOCK();
    uVar2 = *param_1;
    if (uVar3 == uVar2) {
      *param_1 = (uVar4 << 5 ^ uVar1) & 0x3fe0 ^ uVar1;
      uVar1 = uVar3;
    }
    else {
      uVar1 = uVar2;
    }
    UNLOCK();
  } while (uVar3 != uVar2);
  param_4[4] = 0;
  *param_4 = ~uVar3 & 1;
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140011ad4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,ulonglong param_3)

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
              (*(undefined4 *)(param_1 + 0x18),param_3 & 0xffffffff,1,*(undefined8 *)(param_1 + 8));
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_68._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_68;
    local_68 = (ulonglong)(uint6)local_68;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_68 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_68);
  }
  return (int)local_38 == 0;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140011bc4 =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,undefined8 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  uVar5 = (uint)param_3;
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  if (uVar5 == 0) {
LAB_140011d1c:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_140011d0f:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_140011d1c;
      if (uVar5 == 5) goto LAB_140011d0f;
      if ((uVar5 != 6) && (uVar5 != 7)) {
        uVar6 = uVar5 - 0x140;
        if ((int)uVar6 < 0x40) {
          uVar2 = param_2[1];
          do {
            if (((uVar2 & 0x10) == 0) || ((uVar2 >> 5 & 0x3f) != uVar6)) {
              uVar4 = 0;
            }
            else {
              uVar4 = 1;
            }
            param_1[4] = uVar4;
            LOCK();
            uVar4 = param_2[1];
            bVar7 = uVar2 == uVar4;
            if (bVar7) {
              param_2[1] = (uVar6 * 0x20 ^ uVar2) & 0x7e0 ^ uVar2 | 0x10;
            }
            else {
              uVar2 = uVar4;
            }
            UNLOCK();
          } while (!bVar7);
          if (param_1[4] != 0) {
            return param_1;
          }
        }
        param_1[2] = uVar5;
        param_1[1] = 1;
        param_1[3] = param_4;
        return param_1;
      }
    }
    uVar6 = 0;
    if (uVar5 == 2) {
      uVar6 = 2;
    }
    else if (uVar5 == 3) {
      uVar6 = 8;
    }
    else if (uVar5 == 6) {
      uVar6 = 4;
    }
    else if (uVar5 == 7) {
      uVar6 = 0x10;
    }
    uVar2 = 1;
    uVar5 = *param_2;
    do {
      uVar3 = uVar5;
      uVar5 = uVar6 | uVar3;
      param_1[4] = (uint)(uVar5 == uVar3);
      uVar4 = uVar5 | 1;
      if (uVar5 == uVar3) {
        uVar4 = uVar5;
      }
      LOCK();
      uVar1 = *param_2;
      if (uVar3 == uVar1) {
        *param_2 = uVar4;
        uVar5 = uVar3;
      }
      else {
        uVar5 = uVar1;
      }
      UNLOCK();
    } while (uVar3 != uVar1);
    if (((uVar4 & 1) == 0) || ((uVar3 & 1) != 0)) {
      uVar2 = 0;
    }
    *param_1 = uVar2;
  }
  return param_1;
}



===== RtlStringLengthWorkerW @ 140011d44 =====

uint RtlStringLengthWorkerW(short *param_1,longlong param_2,longlong *param_3)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = param_2;
  for (; (lVar2 != 0 && (*param_1 != 0)); param_1 = param_1 + 1) {
    lVar2 = lVar2 + -1;
  }
  uVar1 = ~-(uint)(lVar2 != 0) & 0xc000000d;
  if (param_3 != (longlong *)0x0) {
    if (lVar2 != 0) {
      *param_3 = param_2 - lVar2;
      return uVar1;
    }
    *param_3 = 0;
  }
  return uVar1;
}



===== QueryEndpointPriorities @ 140011d8c =====

void QueryEndpointPriorities(longlong param_1)

{
  undefined8 uVar1;
  int iVar2;
  wchar_t *pwVar3;
  undefined8 uVar4;
  uint local_res8 [2];
  int local_res10 [2];
  uint in_stack_ffffffffffffffe8;
  uint uVar5;
  
  local_res8[0] = 0;
  local_res10[0] = 0;
  uVar1 = *(undefined8 *)(param_1 + 0xe0);
  uVar5 = in_stack_ffffffffffffffe8 & 0xffffff00;
  iVar2 = GetPdoRegistryParameter
                    (uVar1,L"EndpointPriorities",(void *)0x0,0,local_res10,local_res8,uVar5);
  if (((-1 < iVar2) && (local_res10[0] == 7)) && (local_res8[0] != 0)) {
    uVar4 = 0x100;
    if (ExDefaultNonPagedPoolType == 1) {
      uVar4 = 0x40;
    }
    pwVar3 = (wchar_t *)ExAllocatePool2(uVar4,local_res8[0],0x43627355);
    if (pwVar3 != (wchar_t *)0x0) {
      iVar2 = GetPdoRegistryParameter
                        (uVar1,L"EndpointPriorities",pwVar3,local_res8[0],local_res10,local_res8,
                         uVar5 & 0xffffff00);
      if (((-1 < iVar2) && (local_res10[0] == 7)) && (local_res8[0] != 0)) {
        ValidateAndPopulateEndpointPriorities(param_1,pwVar3,local_res8[0]);
      }
      ExFreePoolWithTag(pwVar3,0x43627355);
    }
  }
  return;
}



===== wil_details_MapReportingKind @ 140011ea8 =====

uint wil_details_MapReportingKind(int param_1,int param_2)

{
  byte bVar1;
  
  if (param_1 != 0) {
    if (param_1 == 1) {
      return ~-(uint)(param_2 != 0) & 4;
    }
    if (param_1 == 2) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 5;
    }
    if (param_1 == 3) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 6;
    }
    if (param_1 == 4) {
      return (-(uint)(param_2 != 0) & 0xfffffffc) + 7;
    }
    if (param_1 == 5) {
      return (-(uint)(param_2 != 0) & 0xfffffffe) + 10;
    }
    if (param_1 == 6) {
      return (-(uint)(param_2 != 0) & 0xfffffffe) + 0xb;
    }
    bVar1 = (char)param_1 + 0x9c;
    if (bVar1 < 0x32) {
      return (-(uint)(param_2 != 0) & 0xffffffce) + 0x96 + (uint)bVar1;
    }
  }
  return 0xff;
}



===== __report_gsfailure @ 140011f50 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 140011f5d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140011f5d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline @ 140011f70 =====

ulonglong Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_SPR_HardenInClient__private_featureState;
  if ((Feature_SPR_HardenInClient__private_featureState & 0x10) == 0) {
    uVar1 = Feature_SPR_HardenInClient__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_SPR_HardenInClient__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_SPR_HardenInClient__private_IsEnabledFallback @ 140011fa8 =====

void Feature_SPR_HardenInClient__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_SPR_HardenInClient__private_descriptor);
  return;
}



===== GetConfigValue @ 140011fd0 =====

undefined8
GetConfigValue(undefined8 param_1,int param_2,void *param_3,uint param_4,undefined8 param_5,
              undefined8 *param_6)

{
  void *_Dst;
  undefined8 uVar1;
  
  if (param_2 == 1) {
    if (param_4 != 0) {
      uVar1 = 0x100;
      if (ExDefaultNonPagedPoolType == 1) {
        uVar1 = 0x40;
      }
      _Dst = (void *)ExAllocatePool2(uVar1,param_4,0x43627355);
      if (_Dst == (void *)0x0) {
        return 0xc000009a;
      }
      memset(_Dst,0,(ulonglong)param_4);
      memmove(_Dst,param_3,(ulonglong)param_4);
      *param_6 = _Dst;
      return 0;
    }
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(g_RecorderLog,2,8,10,&WPP_c8c0b630977f39a4a91a92e2db87f7d2_Traceguids,
                      (char)param_2);
  }
  return 0xc000000d;
}



===== WppClassicProviderCallback @ 1400120b0 =====

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



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 14001210c =====

void wil_details_FeatureReporting_IncrementOpportunityInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_1;
  do {
    uVar4 = uVar1;
    param_4[1] = 0;
    uVar1 = uVar4 | 1;
    if ((uVar4 >> 0x16 & 1) != (uint)(param_2 == 5)) {
      uVar3 = uVar4 >> 0xf & 0x7f;
      if (uVar3 != 0) {
        param_4[1] = uVar3;
        uVar3 = 5;
        if (param_2 != 1) {
          uVar3 = 1;
        }
        uVar1 = uVar4 & 0xffc07fff | 1;
        param_4[2] = uVar3;
      }
      uVar3 = 0;
      if (param_2 == 5) {
        uVar3 = 0x400000;
      }
      uVar1 = uVar3 | uVar1 & 0xffbfffff;
    }
    uVar2 = uVar1 >> 0xf & 0x7f;
    uVar3 = uVar2 + 1;
    if ((0x7f < uVar3) || (uVar3 < uVar2)) {
      uVar3 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar2;
    }
    LOCK();
    uVar2 = *param_1;
    if (uVar4 == uVar2) {
      *param_1 = (uVar3 << 0xf ^ uVar1) & 0x3f8000 ^ uVar1;
      uVar1 = uVar4;
    }
    else {
      uVar1 = uVar2;
    }
    UNLOCK();
  } while (uVar4 != uVar2);
  param_4[4] = 0;
  *param_4 = ~uVar4 & 1;
  return;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1400121e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                    (uint *param_1,ulonglong param_2,longlong param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  uint local_res8 [2];
  undefined8 local_res10;
  
  iVar1 = 0;
  local_res8[0] = 0;
  local_res10 = param_2;
  if (g_wil_details_ensureSubscribedToFeatureConfigurationChanges != (code *)0x0) {
    iVar1 = (*g_wil_details_ensureSubscribedToFeatureConfigurationChanges)();
  }
  uVar2 = wil_details_GetCurrentFeatureEnabledState(param_3,local_res8);
  if (*(char *)(param_3 + 0x1c) == '\0') {
    local_res8[0] = local_res8[0] & -(uint)(iVar1 != 0);
  }
  uVar3 = param_2 & 0xffffffff;
  while( true ) {
    uVar5 = (uint)uVar3;
    local_res10 = CONCAT44(local_res10._4_4_,uVar5);
    if ((local_res8[0] != 0) && (local_res10 = CONCAT44(local_res10._4_4_,uVar5), (uVar3 & 2) == 0))
    {
      uVar4 = uVar5 & 0xfffff63e | uVar2 & 0x9c1;
      uVar5 = uVar4 | 2;
      local_res10 = CONCAT44(local_res10._4_4_,uVar4) | 2;
    }
    if ((param_2 & 4) == 0) {
      uVar4 = uVar2 & 0x400 | uVar5 & 0xfffffbff;
      uVar5 = uVar4 | 4;
      local_res10 = CONCAT44(local_res10._4_4_,uVar4) | 4;
    }
    uVar3 = param_2 & 0xffffffff;
    LOCK();
    uVar4 = *param_1;
    bVar6 = (uint)param_2 == uVar4;
    if (bVar6) {
      *param_1 = uVar5;
    }
    else {
      uVar3 = (ulonglong)uVar4;
    }
    UNLOCK();
    if (bVar6) break;
    param_2 = uVar3;
  }
  if (((param_2 & 4) == 0) &&
     (g_wil_details_subscribeFeatureStateCacheToConfigurationChanges != (code *)0x0)) {
    (*g_wil_details_subscribeFeatureStateCacheToConfigurationChanges)
              (param_1,*(undefined1 *)(param_3 + 0x1c),iVar1);
  }
  if (local_res8[0] == 0) {
    local_res10 = CONCAT44(local_res10._4_4_,uVar2 & 0x9c1 | uVar5 & 0xfffff63e);
  }
  return local_res10;
}



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 1400122f4 =====

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



===== wil_details_GetCurrentFeatureEnabledState @ 140012358 =====

uint wil_details_GetCurrentFeatureEnabledState(longlong param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar7;
  longlong *plVar8;
  uint local_res8;
  ulonglong local_res10;
  uint local_28 [8];
  
  cVar1 = *(char *)(param_1 + 0x1c);
  uVar2 = *(undefined4 *)(param_1 + 0x18);
  *param_2 = 1;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  uVar5 = wil_RtlStagingConfig_QueryFeatureState(local_28,uVar2,(uint)((byte)(cVar1 - 2U) < 2));
  uVar4 = -(uint)((int)uVar5 != 0) & local_28[0] & 3;
  if (uVar4 == 0) {
    uVar7 = -(uint)(*(char *)(param_1 + 0x1f) != '\0') & 0x40;
  }
  else {
    uVar7 = 0;
    if (local_28[0] == 2) {
      uVar7 = 0x40;
    }
  }
  local_res8 = uVar7 >> 6 ^
               (uVar4 << 7 | -(uint)(local_28[5] != 0) & 0x800 | -(uint)(local_28[4] != 0) & 0x400 |
               uVar7);
  if ((uVar7 != 0) && (plVar8 = *(longlong **)(param_1 + 0x20), plVar8 != (longlong *)0x0)) {
    do {
      puVar3 = (undefined8 *)*plVar8;
      if (puVar3 == (undefined8 *)0x0) {
        return local_res8;
      }
      if ((*(char *)((longlong)puVar3 + 0x1e) == '\0') &&
         (*(char *)((longlong)puVar3 + 0x1d) == '\0')) {
        uVar7 = *(uint *)*puVar3;
        local_res10 = (ulonglong)uVar7;
        if ((uVar7 & 2) == 0) {
          uVar6 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            ((uint *)*puVar3,local_res10,(longlong)puVar3);
          uVar7 = (uint)uVar6;
        }
        uVar4 = local_res8 & 0xfffffffe;
        local_res8 = (uint)((uVar7 & local_res8 & 1) != 0);
      }
      else {
        if (((local_res8 & 1) == 0) || (*(char *)((longlong)puVar3 + 0x1f) == '\0')) {
          uVar4 = 0;
        }
        else {
          uVar4 = 1;
        }
        local_res8 = local_res8 & 0xfffffffe;
      }
      local_res8 = local_res8 | uVar4;
      plVar8 = plVar8 + 1;
    } while ((local_res8 & 1) != 0);
  }
  return local_res8;
}



===== wil_details_IsEnabledFallback @ 1400124b8 =====

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



===== wil_details_RecordCachedUsage @ 14001254c =====

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



===== wil_details_RecordFeatureUsageReporting @ 1400126a0 =====

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



===== Feature_1916511546__private_IsEnabledDeviceUsageNoInline @ 140012724 =====

ulonglong Feature_1916511546__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_1916511546__private_featureState;
  if ((Feature_1916511546__private_featureState & 0x10) == 0) {
    uVar1 = Feature_1916511546__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_1916511546__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_1916511546__private_IsEnabledFallback @ 14001275c =====

void Feature_1916511546__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_1916511546__private_descriptor);
  return;
}



===== ParentCloseConfiguration @ 140012778 =====

void ParentCloseConfiguration(longlong param_1)

{
  int iVar1;
  undefined2 *local_res8;
  
  local_res8 = (undefined2 *)0x0;
  iVar1 = USBD_UrbAllocate(*(longlong *)(param_1 + 0x548),&local_res8);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0x11,
                        &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)iVar1);
    }
  }
  else {
    *local_res8 = 0x58;
    local_res8[1] = 0;
    *(undefined8 *)(local_res8 + 0xc) = 0;
    iVar1 = SubmitUrb(param_1,local_res8);
    if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0x12,
                        &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)iVar1);
    }
    USBD_UrbFree(*(longlong *)(param_1 + 0x548),(longlong)local_res8);
  }
  return;
}



===== WPP_RECORDER_SF_dD @ 14001286c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dD(undefined8 param_1)

{
  undefined1 uStack0000000000000038;
  undefined4 local_18 [4];
  
  local_18[0] = 3;
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (1 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_93f6b87810f63f9db566694056813e32_Traceguids,0x1e,local_18,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,2,8,&WPP_93f6b87810f63f9db566694056813e32_Traceguids,0x1e,local_18,4,
                  &uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_ddd @ 140012940 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_ddd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (1 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_5,param_4,&param_6,4,&param_7,4
               ,&param_8,4,0);
  }
  WppAutoLogTrace(param_1,2,8,param_5,param_4,&param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== AppendPdoIdsReverse @ 140012a30 =====

void * AppendPdoIdsReverse(short *param_1,ushort *param_2)

{
  uint uVar1;
  int iVar2;
  void *_Dst;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = CalculateMultiStringLength(param_1);
  uVar1 = (iVar2 + 1) * 2;
  uVar5 = *param_2 + 2 + uVar1;
  uVar4 = uVar5 >> 1;
  uVar3 = 0x100;
  if (ExDefaultNonPagedPoolType == 1) {
    uVar3 = 0x40;
  }
  _Dst = (void *)ExAllocatePool2(uVar3,uVar5,0x43627355);
  if (_Dst != (void *)0x0) {
    memmove((void *)((longlong)_Dst + (ulonglong)(uVar4 - (iVar2 + 1)) * 2),param_1,(ulonglong)uVar1
           );
    memmove(_Dst,*(void **)(param_2 + 4),(ulonglong)*param_2);
    *(undefined2 *)((longlong)_Dst + (ulonglong)(uVar4 - 1) * 2) = 0;
    *(undefined2 *)((longlong)_Dst + (ulonglong)(uVar4 - 2) * 2) = 0;
  }
  return _Dst;
}



===== D3ColdSupportFunctionInterfaceReference @ 140012b10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void D3ColdSupportFunctionInterfaceReference(longlong param_1)

{
  (**(code **)(*(longlong *)(param_1 + 0xe8) + 0x1d0))
            (*(undefined8 *)(*(longlong *)(param_1 + 0xe8) + 0x1c8));
  return;
}



===== D3ColdSupportInterfaceFunctionGetLastTransitionStatus @ 140012b40 =====

void D3ColdSupportInterfaceFunctionGetLastTransitionStatus(longlong param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x70);
  *param_2 = uVar1;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qL(*(undefined8 *)(param_1 + 0x188),5,3,0x5e,
                       &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,
                       (char)*(undefined8 *)(param_1 + 0xe0),(char)uVar1);
  }
  return;
}



===== Feature_2793828664__private_IsEnabledDeviceUsageNoInline @ 140012bac =====

ulonglong Feature_2793828664__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_2793828664__private_featureState;
  if ((Feature_2793828664__private_featureState & 0x10) == 0) {
    uVar1 = Feature_2793828664__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_2793828664__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_2793828664__private_IsEnabledFallback @ 140012be4 =====

void Feature_2793828664__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_2793828664__private_descriptor);
  return;
}



===== Feature_WinUsb_Print__private_IsEnabledDeviceUsageNoInline @ 140012c00 =====

ulonglong Feature_WinUsb_Print__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_WinUsb_Print__private_featureState;
  if ((Feature_WinUsb_Print__private_featureState & 0x10) == 0) {
    uVar1 = Feature_WinUsb_Print__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_WinUsb_Print__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_WinUsb_Print__private_IsEnabledFallback @ 140012c38 =====

void Feature_WinUsb_Print__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_WinUsb_Print__private_descriptor);
  return;
}



===== RtlStringCbLengthW @ 140012c54 =====

uint RtlStringCbLengthW(short *param_1,ulonglong param_2,longlong *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  uVar4 = param_2 >> 1;
  uVar2 = 0;
  if ((param_1 == (short *)0x0) || (uVar1 = uVar4, 0x7fffffff < uVar4)) {
    uVar3 = 0xc000000d;
  }
  else {
    for (; (uVar1 != 0 && (*param_1 != 0)); param_1 = param_1 + 1) {
      uVar1 = uVar1 - 1;
    }
    uVar3 = ~-(uint)(uVar1 != 0) & 0xc000000d;
    uVar2 = -(ulonglong)(uVar1 != 0) & uVar4 - uVar1;
  }
  if (param_3 != (longlong *)0x0) {
    if ((int)uVar3 < 0) {
      *param_3 = 0;
    }
    else {
      *param_3 = uVar2 * 2;
    }
  }
  return uVar3;
}



===== RtlStringExHandleOtherFlagsW @ 140012cc8 =====

undefined8
RtlStringExHandleOtherFlagsW
          (undefined2 *param_1,ulonglong param_2,undefined8 param_3,undefined8 *param_4,
          ulonglong *param_5,uint param_6)

{
  ulonglong uVar1;
  
  uVar1 = param_2 >> 1;
  if ((uVar1 != 0) && ((param_6 & 0x1000) != 0)) {
    *param_4 = param_1;
    *param_5 = uVar1;
    *param_1 = 0;
  }
  if ((param_6 & 0x400) != 0) {
    memset(param_1,param_6 & 0xff,param_2);
    if ((char)param_6 != '\0') {
      if (uVar1 == 0) {
        return 0;
      }
      *param_5 = 1;
      *param_4 = param_1 + (uVar1 - 1);
      param_1[uVar1 - 1] = 0;
      goto LAB_140012d33;
    }
    *param_4 = param_1;
    *param_5 = uVar1;
  }
  if (uVar1 == 0) {
    return 0;
  }
LAB_140012d33:
  if ((param_6 & 0x800) != 0) {
    *param_4 = param_1;
    *param_5 = uVar1;
    *param_1 = 0;
  }
  return 0;
}



===== RtlUnicodeStringPrintf @ 140012d88 =====

undefined8
RtlUnicodeStringPrintf(ushort *param_1,wchar_t *param_2,undefined8 param_3,undefined8 param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong _Count;
  undefined8 local_res18;
  undefined8 local_res20;
  
  uVar1 = *param_1;
  if ((((((uVar1 & 1) == 0) && (uVar2 = param_1[1], (uVar2 & 1) == 0)) && (uVar1 <= uVar2)) &&
      (uVar2 != 0xffff)) &&
     ((uVar5 = 0, *(longlong *)(param_1 + 4) != 0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
    _Count = (ulonglong)(param_1[1] >> 1);
    local_res18 = param_3;
    local_res20 = param_4;
    iVar3 = _vsnwprintf(*(wchar_t **)(param_1 + 4),_Count,param_2,(va_list)&local_res18);
    if ((iVar3 < 0) || (uVar4 = (longlong)iVar3, _Count < (ulonglong)(longlong)iVar3)) {
      uVar5 = 0x80000005;
      uVar4 = _Count;
    }
    *param_1 = (short)uVar4 * 2;
  }
  else {
    uVar5 = 0xc000000d;
  }
  return uVar5;
}



===== WPP_RECORDER_SF_sd @ 140012e28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sd(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  char *in_stack_00000030;
  undefined4 local_18 [4];
  
  local_18[0] = 0xc000009a;
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (1 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    if (in_stack_00000030 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (in_stack_00000030[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = in_stack_00000030;
    if (in_stack_00000030 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,0x19,pcVar1,lVar3,local_18,4,0);
  }
  lVar3 = -1;
  if (in_stack_00000030 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (in_stack_00000030[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (in_stack_00000030 == (char *)0x0) {
    in_stack_00000030 = "NULL";
  }
  WppAutoLogTrace(param_1,2,8,&WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,0x19,
                  in_stack_00000030,lVar2,local_18,4,0);
  return;
}



===== WPP_RECORDER_SF_sq @ 140012f70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_sq(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  char *in_stack_00000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    if (in_stack_00000030 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (in_stack_00000030[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = in_stack_00000030;
    if (in_stack_00000030 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,0x18,pcVar1,lVar3,
               &uStack0000000000000038,8,0);
  }
  lVar3 = -1;
  if (in_stack_00000030 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (in_stack_00000030[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (in_stack_00000030 == (char *)0x0) {
    in_stack_00000030 = "NULL";
  }
  WppAutoLogTrace(param_1,4,2,&WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,0x18,
                  in_stack_00000030,lVar2,&uStack0000000000000038,8,0);
  return;
}



===== HandleFdoStop @ 1400130b4 =====

undefined8 HandleFdoStop(longlong param_1,longlong param_2)

{
  bool bVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLock(param_1 + 0x100,&local_28);
  bVar1 = *(int *)(param_1 + 0xc) == 4;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0xc) = 5;
  }
  KeReleaseInStackQueuedSpinLock(&local_28);
  if (bVar1) {
    CancelParentWaitWake(param_1);
    WaitForSignal(param_1 + 0x120,"stopEvent (wait for all I/O to complete)",
                  *(undefined8 *)(param_1 + 0x560));
    ParentCloseConfiguration(param_1);
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  return 0;
}



===== WPP_RECORDER_SF_S @ 140013164 =====

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
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (1 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
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
               &WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,param_4,pwVar2,lVar1,0);
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
  WppAutoLogTrace(param_1,2,8,&WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,param_4,param_6,lVar3
                  ,0);
  return;
}



===== WPP_RECORDER_SF_dqd @ 14001328c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_dqd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (1 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,0x2b,&uStack0000000000000030,4,
               &uStack0000000000000038,8,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,2,8,&WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,0x2b,
                  &uStack0000000000000030,4,&uStack0000000000000038,8,&uStack0000000000000040,4,0);
  return;
}



===== GetChannelDescForInterface @ 140013380 =====

byte * GetChannelDescForInterface(longlong param_1)

{
  byte bVar1;
  byte *pbVar2;
  longlong lVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  
  lVar3 = *(longlong *)(param_1 + 0x30);
  pbVar6 = (byte *)((ulonglong)*(ushort *)(lVar3 + 2) + lVar3);
  pbVar2 = (byte *)USBD_ParseConfigurationDescriptorEx
                             (lVar3,lVar3,0xffffffff,0,0xd,0xffffffff,0xffffffff);
  if (pbVar2 == (byte *)0x0) {
    return (byte *)0x0;
  }
  while( true ) {
    if (pbVar6 < pbVar2) {
      return (byte *)0x0;
    }
    if (0xffff < (longlong)pbVar6 - (longlong)pbVar2) {
      return (byte *)0x0;
    }
    if ((ulonglong)((longlong)pbVar6 - (longlong)pbVar2) < 2) {
      return (byte *)0x0;
    }
    bVar1 = *pbVar2;
    if (pbVar2[1] == 0x22) break;
    if (bVar1 == 0) {
      return (byte *)0x0;
    }
    if (pbVar2 + bVar1 < pbVar2) {
      return (byte *)0x0;
    }
    pbVar2 = pbVar2 + bVar1;
  }
  if (6 < bVar1) {
    pbVar5 = pbVar2 + bVar1;
    if (pbVar2 + bVar1 < pbVar2) {
      pbVar5 = pbVar6;
    }
    if (pbVar5 <= pbVar6) {
      pbVar6 = pbVar5;
    }
    if (6 < (ulonglong)((longlong)pbVar6 - (longlong)pbVar2)) {
      if ((uint)((int)pbVar6 - (int)pbVar2) < 8) {
        return pbVar2;
      }
      pbVar4 = pbVar2 + 7;
      pbVar5 = pbVar2 + 9;
      for (lVar3 = (longlong)pbVar6 - (longlong)pbVar4;
          ((pbVar4 <= pbVar6 && (lVar3 < 0x10000)) && (lVar3 != 0)); lVar3 = lVar3 + -2) {
        if ((pbVar4 != (byte *)0x0) && (*pbVar4 == 1)) {
          return pbVar2;
        }
        if (pbVar5 < pbVar4) break;
        pbVar4 = pbVar4 + 2;
        pbVar5 = pbVar5 + 2;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0x10,
                         &WPP_e6d2562f3eed34437ee263ed282fdffa_Traceguids);
      }
      return (byte *)0x0;
    }
  }
  return (byte *)0x0;
}



===== GetMediaSerialNumber @ 1400134e4 =====

uint GetMediaSerialNumber(longlong param_1,longlong param_2)

{
  longlong lVar1;
  uint *puVar2;
  uint uVar3;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),4,5,0xe,
                     &WPP_e6d2562f3eed34437ee263ed282fdffa_Traceguids);
  }
  puVar2 = *(uint **)(param_2 + 0x18);
  if ((puVar2 == (uint *)0x0) || (uVar3 = *(uint *)(lVar1 + 8), uVar3 < 0x14)) {
    uVar3 = 0xc0000206;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(param_1 + 0x560),2,8,0xf,
                         &WPP_e6d2562f3eed34437ee263ed282fdffa_Traceguids,(char)param_2,6);
    }
  }
  else {
    uVar3 = GetUniqueIdFromCSInterface(param_1,puVar2,uVar3 - 0x14);
    *(ulonglong *)(param_2 + 0x38) = (ulonglong)(*puVar2 + 0x10);
  }
  return uVar3;
}



===== GetUniqueIdFromCSInterface @ 1400135cc =====

uint GetUniqueIdFromCSInterface(longlong param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  void *_Src;
  uint uVar2;
  void *pvVar3;
  uint uVar4;
  ulonglong _Size;
  undefined2 *local_res10;
  uint *local_38;
  ulonglong uStack_30;
  
  uVar2 = 0;
  uVar4 = 0;
  _Src = (void *)ExAllocatePool2(0x40,0x100,0x43627355);
  if (_Src == (void *)0x0) {
    uVar1 = 0xc000009a;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0xd,
                        &WPP_e6d2562f3eed34437ee263ed282fdffa_Traceguids,0x9a);
    }
  }
  else {
    local_res10 = (undefined2 *)0x0;
    uVar1 = USBD_UrbAllocate(*(longlong *)(param_1 + 0x548),&local_res10);
    if ((int)uVar1 < 0) {
      uVar4 = 0;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0xc,
                          &WPP_e6d2562f3eed34437ee263ed282fdffa_Traceguids,(char)uVar1);
      }
    }
    else {
      *local_res10 = 0x88;
      local_res10[1] = 0x1b;
      *(undefined4 *)(local_res10 + 0x10) = 1;
      *(undefined4 *)(local_res10 + 0x12) = 0x100;
      *(void **)(local_res10 + 0x14) = _Src;
      *(undefined1 *)((longlong)local_res10 + 0x81) = 0x80;
      local_res10[0x41] = 0;
      local_res10[0x42] = *(short *)(param_1 + 600) << 8 | *(ushort *)(param_1 + 0x254);
      uVar1 = SubmitUrb(param_1,local_res10);
      if ((int)uVar1 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0xb,
                            &WPP_e6d2562f3eed34437ee263ed282fdffa_Traceguids,(char)uVar1);
        }
      }
      else {
        uVar2 = *(uint *)(local_res10 + 0x12);
        if (0x100 < uVar2) {
          uVar2 = 0x100;
        }
        if (param_3 < uVar2) {
          uVar2 = param_3;
        }
        _Size = (ulonglong)uVar2;
        pvVar3 = _Src;
        memmove(param_2 + 4,_Src,_Size);
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uStack_30 = (ulonglong)(ushort)uVar2;
          local_38 = param_2 + 4;
          WPP_RECORDER_SF__HEX_
                    (*(undefined8 *)(param_1 + 0x560),pvVar3,_Size,10,
                     &WPP_e6d2562f3eed34437ee263ed282fdffa_Traceguids,&local_38);
        }
      }
      USBD_UrbFree(*(longlong *)(param_1 + 0x548),(longlong)local_res10);
      uVar4 = uVar2;
    }
    ExFreePoolWithTag(_Src,0x43627355);
  }
  *param_2 = uVar4;
  param_2[1] = uVar1;
  return uVar1;
}



===== InitCSInfo @ 140013834 =====

void InitCSInfo(longlong param_1,undefined4 param_2)

{
  byte *pbVar1;
  
  pbVar1 = GetChannelDescForInterface(param_1);
  if (pbVar1 != (byte *)0x0) {
    *(uint *)(param_1 + 600) = (uint)pbVar1[2];
    *(undefined4 *)(param_1 + 0x254) = param_2;
    *(undefined1 *)(param_1 + 0x250) = 1;
  }
  return;
}



===== CalculateMultiStringLength @ 140013878 =====

int CalculateMultiStringLength(short *param_1)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  iVar2 = 0;
  if (*param_1 != 0) {
    do {
      iVar1 = WStrLen(param_1);
      iVar2 = iVar2 + iVar1 + 1U;
      param_1 = param_1 + (iVar1 + 1U);
    } while (*param_1 != (short)uVar3);
  }
  return iVar2;
}



===== CleanFunctionDescriptorArray @ 1400138b4 =====

void CleanFunctionDescriptorArray(longlong param_1,uint param_2)

{
  ulonglong uVar1;
  longlong *plVar2;
  
  uVar1 = (ulonglong)param_2 / 0x50;
  if ((int)uVar1 != 0) {
    plVar2 = (longlong *)(param_1 + 0x18);
    do {
      if (plVar2[-2] != 0) {
        ExFreePoolWithTag(plVar2[-2],0);
      }
      if (*plVar2 != 0) {
        ExFreePoolWithTag();
      }
      if (plVar2[2] != 0) {
        ExFreePoolWithTag();
      }
      if (plVar2[4] != 0) {
        ExFreePoolWithTag();
      }
      plVar2 = plVar2 + 10;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== Feature_3635125563__private_IsEnabledDeviceUsageNoInline @ 140013970 =====

ulonglong Feature_3635125563__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_3635125563__private_featureState;
  if ((Feature_3635125563__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3635125563__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3635125563__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3635125563__private_IsEnabledFallback @ 1400139a8 =====

void Feature_3635125563__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3635125563__private_descriptor);
  return;
}



===== IsProtectedPrintEnabled @ 1400139c4 =====

undefined4 IsProtectedPrintEnabled(void)

{
  int iVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 local_res8 [2];
  undefined8 local_res10;
  undefined8 local_68;
  undefined8 uStack_60;
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
  
  uVar3 = 0;
  local_44 = 0;
  local_2c = 0;
  local_res10 = 0;
  local_res8[0] = 0x14;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  lVar2 = ExAllocatePool2(0x100,0x14,0x43627355);
  if (lVar2 != 0) {
    RtlInitUnicodeString
              (&local_68,
               L"\\Registry\\Machine\\Software\\Policies\\Microsoft\\Windows NT\\Printers\\WPP");
    RtlInitUnicodeString(&local_58,L"WindowsProtectedPrintMode");
    local_38 = &local_68;
    local_48 = 0x30;
    local_40 = 0;
    local_30 = 0x240;
    local_28 = 0;
    uStack_20 = 0;
    iVar1 = ZwOpenKey(&local_res10,1,&local_48);
    if (-1 < iVar1) {
      iVar1 = ZwQueryValueKey(local_res10,&local_58,2,lVar2,local_res8[0],local_res8);
      if ((-1 < iVar1) && (uVar3 = 0, *(int *)(lVar2 + 0xc) != 0)) {
        uVar3 = 1;
      }
      ZwClose(local_res10);
    }
    ExFreePoolWithTag(lVar2,0);
  }
  return uVar3;
}



===== ResetDevice @ 140013af8 =====

ulonglong ResetDevice(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  ulonglong local_38 [6];
  
  local_38[4] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  KeInitializeEvent(local_38 + 2,0,0);
  lVar2 = IoBuildDeviceIoControlRequest
                    (0x220007,*(undefined8 *)(param_1 + 0x28),0,0,0,0,1,local_38 + 2,local_38);
  if (lVar2 == 0) {
    local_38[0] = 0xc000009a;
  }
  else {
    iVar1 = IofCallDriver(*(undefined8 *)(param_1 + 0x28),lVar2);
    if (iVar1 == 0x103) {
      WaitForSignal(local_38 + 2,"event (waiting for IOCTL_INTERNAL_USB_RESET_PORT to complete)",
                    *(undefined8 *)(param_1 + 0x560));
    }
    local_38[0] = local_38[0] & 0xffffffff;
  }
  return local_38[0];
}



===== USBD_InstallExtPropDescSections @ 140013bc4 =====

ulonglong USBD_InstallExtPropDescSections(longlong param_1,undefined8 *param_2,uint param_3)

{
  ushort uVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  uint *puVar6;
  undefined8 local_res10;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res10 = 0;
  if ((param_2 != (undefined8 *)0x0) && (param_1 != 0)) {
    uVar1 = *(ushort *)(param_2 + 1);
    local_28 = *param_2;
    uVar5 = (uint)local_28;
    if (uVar1 == 0) {
      return 0;
    }
    if ((9 < uVar5) && (uVar5 <= param_3)) {
      uVar3 = IoOpenDeviceRegistryKey(uVar5,1,0x1f0000,&local_res10);
      uVar4 = uVar3 & 0xffffffff;
      if ((int)uVar3 < 0) {
        return uVar3;
      }
      puVar6 = (uint *)((longlong)param_2 + 10);
      for (uVar5 = 0; uVar5 < uVar1; uVar5 = uVar5 + 1) {
        local_28 = 0;
        uStack_20 = 0;
        uVar2 = puVar6[2];
        RtlInitUnicodeString(&local_28,(longlong)puVar6 + 10);
        uVar2 = ZwSetValueKey(local_res10,&local_28,0,puVar6[1],
                              (ulonglong)(ushort)uVar2 + 0xe + (longlong)puVar6,
                              *(undefined4 *)((ulonglong)(ushort)uVar2 + 10 + (longlong)puVar6));
        uVar4 = (ulonglong)uVar2;
        if ((int)uVar2 < 0) break;
        puVar6 = (uint *)((longlong)puVar6 + (ulonglong)*puVar6);
      }
      ZwClose(local_res10);
      return uVar4;
    }
  }
  return 0xc000000d;
}



===== USBD_ValidateExtendedPropertyDescriptor @ 140013ce8 =====

undefined8 USBD_ValidateExtendedPropertyDescriptor(uint *param_1,uint param_2)

{
  uint *puVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = 0;
  if ((9 < param_2) && (param_1 != (uint *)0x0)) {
    uVar4 = *param_1;
    if ((uVar4 <= param_2) && ((uVar4 - 10 < 0xff7 && (*(short *)((longlong)param_1 + 6) == 5)))) {
      uVar2 = (ushort)param_1[2];
      if (uVar2 == 0) {
        return 0;
      }
      puVar1 = (uint *)((longlong)param_1 + (ulonglong)uVar4);
      for (puVar5 = (uint *)((longlong)param_1 + 10); puVar5 < puVar1;
          puVar5 = (uint *)((longlong)puVar5 + (ulonglong)uVar4)) {
        if (puVar1 < (uint *)((longlong)puVar5 + 0xeU)) {
          return 0xc000000d;
        }
        uVar4 = *puVar5;
        if (0x7fffffff < uVar4) {
          return 0xc000000d;
        }
        if ((longlong)puVar1 - (longlong)puVar5 < (longlong)(int)uVar4) {
          return 0xc000000d;
        }
        if (uVar4 < 0xe) {
          return 0xc000000d;
        }
        if (6 < puVar5[1] - 1) {
          return 0xc000000d;
        }
        uVar3 = (ushort)puVar5[2];
        if (uVar4 < uVar3 + 0xe) {
          return 0xc000000d;
        }
        if (uVar3 == 0) {
          return 0xc000000d;
        }
        if ((uVar3 & 1) != 0) {
          return 0xc000000d;
        }
        if (*(short *)((longlong)puVar5 + 10) == 0) {
          return 0xc000000d;
        }
        if (*(short *)((longlong)puVar5 + (ulonglong)(uVar3 >> 1) * 2 + 8) != 0) {
          return 0xc000000d;
        }
        uVar6 = *(uint *)((ulonglong)uVar3 + 10 + (longlong)puVar5);
        if (~(uint)uVar3 < uVar6) {
          return 0xc000000d;
        }
        uVar6 = uVar6 + uVar3;
        if (~uVar6 < 0xe) {
          return 0xc000000d;
        }
        if (uVar4 < uVar6 + 0xe) {
          return 0xc000000d;
        }
        uVar7 = uVar7 + 1;
        if (uVar7 == uVar2) {
          return 0;
        }
      }
      if (uVar7 == uVar2) {
        return 0;
      }
    }
  }
  return 0xc000000d;
}



===== UsbcDbgBreak @ 140013e0c =====

void UsbcDbgBreak(undefined8 param_1)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qs(g_RecorderLog,2,1,0x41,&WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids,
                       (char)param_1,
                       "Client driver sent IOCTL_INTERNAL_USB_CYCLE_PORT, not supported by CCGP in boot path"
                      );
  }
  DbgPrint("0x%p UsbcDbgBreak called due to %s. For more details run: !rcdrlogdump usbccgp\n",
           param_1,
           "Client driver sent IOCTL_INTERNAL_USB_CYCLE_PORT, not supported by CCGP in boot path");
  iVar3 = MmIsDriverVerifying(param_1);
  if (iVar3 != 0) {
    cVar2 = KdRefreshDebuggerNotPresent();
    if (cVar2 == '\0') {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  return;
}



===== WPP_RECORDER_SF_qds @ 140013eac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qds(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,char *param_8)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  char *pcVar4;
  
  pcVar4 = param_8;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (1 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    if (param_8 == (char *)0x0) {
      lVar3 = 5;
    }
    else {
      lVar2 = -1;
      do {
        lVar3 = lVar2;
        lVar2 = lVar3 + 1;
      } while (param_8[lVar2] != '\0');
      lVar3 = lVar3 + 2;
    }
    pcVar1 = param_8;
    if (param_8 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids,param_4,&param_6,8,&param_7,4,pcVar1
               ,lVar3,0);
  }
  lVar3 = -1;
  if (pcVar4 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    do {
      lVar2 = lVar3;
      lVar3 = lVar2 + 1;
    } while (pcVar4[lVar3] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (pcVar4 == (char *)0x0) {
    pcVar4 = "NULL";
  }
  WppAutoLogTrace(param_1,2,1,&WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids,param_4,&param_6,8,
                  &param_7,4,pcVar4,lVar2,0);
  return;
}



===== FinishWaitWakeCompletionForFunctionSuspend @ 140014020 =====

void FinishWaitWakeCompletionForFunctionSuspend(longlong param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  ulonglong uVar3;
  uint uVar4;
  longlong lVar5;
  longlong lVar6;
  bool bVar7;
  
  lVar5 = 0;
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 400);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x560),4,3,0x18,
                      &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                      (char)*(undefined8 *)(param_1 + 0x20));
  }
  lVar1 = *(longlong *)(param_1 + 0x180);
  *(undefined1 *)(param_1 + 0x1b8) = 0;
  lVar6 = 0;
  if (lVar1 != 0) {
    *(undefined8 *)(param_1 + 0x180) = 0;
    lVar6 = lVar1;
  }
  LOCK();
  *(undefined4 *)(param_1 + 0x188) = 0;
  UNLOCK();
  LOCK();
  *(undefined4 *)(param_1 + 0x18c) = 0;
  UNLOCK();
  KeReleaseSpinLock(param_1 + 400,uVar2);
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x158);
  KeSetEvent(param_1 + 0x1a0,0,0);
  uVar4 = *(uint *)(param_1 + 0x4d4);
  bVar7 = (uVar4 & 0x20) != 0;
  if (bVar7) {
    lVar5 = *(longlong *)(param_1 + 0x4d8);
    uVar4 = uVar4 & 0xffffffdf;
    *(undefined8 *)(param_1 + 0x4d8) = 0;
    *(uint *)(param_1 + 0x4d4) = uVar4;
  }
  KeReleaseSpinLock(param_1 + 0x158,CONCAT31((int3)(uVar4 >> 8),uVar2));
  if (bVar7) {
    uVar3 = AllocateWorker(param_1,IdleFinishCompletionWorker,lVar5);
    if ((int)uVar3 < 0) {
      IdleFinishCompletionWorker(param_1,lVar5);
    }
  }
  CheckParentWaitWake(param_1);
  if (lVar6 != 0) {
    UsbcReleaseRemoveLock(param_1,lVar6);
    IoReleaseRemoveLockEx(param_1 + 200,lVar6,0x20);
  }
  return;
}



===== IdleTimerEnableWorker @ 1400141c0 =====

void IdleTimerEnableWorker(longlong param_1)

{
  EnableIdleTimer(param_1,'\x01',0x574f524b);
  return;
}



===== LockSyncSendSetFeatureControlRequestForFunctionSuspend @ 1400141e0 =====

uint LockSyncSendSetFeatureControlRequestForFunctionSuspend
               (longlong param_1,longlong param_2,int param_3)

{
  longlong *plVar1;
  int *piVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong lVar5;
  code *pcVar6;
  undefined1 uVar7;
  uint uVar8;
  int iVar9;
  undefined1 *puVar10;
  uint uVar11;
  undefined1 auStackY_68 [8];
  undefined1 auStackY_60 [24];
  
  uVar8 = KeWaitForSingleObject(param_2 + 0x1a8,0,0,0);
  if (uVar8 == 0) {
    uVar8 = SyncSendSetFeatureControlRequestForFunctionSuspend(param_1,param_2,param_3);
    uVar7 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x1c0);
    puVar10 = auStackY_68;
    plVar3 = (longlong *)(param_2 + 0x1c8);
    uVar11 = ~uVar8 >> 0x1f;
    while( true ) {
      plVar4 = (longlong *)*plVar3;
      if (plVar4 == plVar3) break;
      if (((longlong *)plVar4[1] != plVar3) ||
         (lVar5 = *plVar4, (longlong *)*(longlong *)(lVar5 + 8) != plVar4)) {
        pcVar6 = (code *)swi(0x29);
        (*pcVar6)(3);
        puVar10 = auStackY_60;
        break;
      }
      plVar1 = plVar4 + -2;
      *plVar3 = lVar5;
      *(longlong **)(lVar5 + 8) = plVar3;
      KeReleaseSpinLock(param_2 + 0x1c0,uVar7);
      piVar2 = (int *)(plVar4 + -1);
      if ((uVar11 == 0) || (*piVar2 != param_3)) {
        iVar9 = SyncSendSetFeatureControlRequestForFunctionSuspend(param_1,param_2,*piVar2);
        if (iVar9 < 0) {
          if (*(int *)(*(longlong *)(*plVar1 + 0xb8) + 0x18) != 1) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qq(*(undefined8 *)(param_2 + 0x188),2,3,0x55,
                                 &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                                 (char)*(undefined8 *)(param_2 + 0xe0),
                                 (char)*(undefined8 *)(*(longlong *)(param_2 + 0x180) + 0x28));
            }
            IoCancelIrp(*(undefined8 *)(*(longlong *)(param_2 + 0x180) + 0x28));
          }
        }
        else {
          param_3 = *piVar2;
          uVar11 = 1;
        }
      }
      PoStartNextPowerIrp(*plVar1);
      *(undefined4 *)(*plVar1 + 0x30) = 0;
      IofCompleteRequest(*plVar1,0);
      UsbcReleaseRemoveLock(param_1,*plVar1);
      IoReleaseRemoveLockEx(param_1 + 200,*plVar1);
      ExFreePoolWithTag(plVar1);
      uVar7 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x1c0);
    }
    *(undefined8 *)(puVar10 + -8) = 0x1400143e4;
    KeSetEvent(param_2 + 0x1a8,0,0);
    *(undefined8 *)(puVar10 + -8) = 0x1400143fa;
    KeReleaseSpinLock(param_2 + 0x1c0,uVar7);
  }
  return uVar8;
}



===== SetSelectiveSuspendRegistryFlag @ 140014430 =====

void SetSelectiveSuspendRegistryFlag(undefined8 param_1,longlong param_2)

{
  undefined4 local_res10 [6];
  
  local_res10[0] = 1;
  SetPdoRegistryParameter
            (*(undefined8 *)(param_2 + 0xe0),L"DeviceSelectiveSuspended",local_res10,4,4);
  return;
}



===== SyncSendSetFeatureControlRequestForFunctionSuspend @ 14001446c =====

undefined4
SyncSendSetFeatureControlRequestForFunctionSuspend(longlong param_1,longlong param_2,int param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  undefined2 uVar5;
  
  lVar1 = *(longlong *)(param_2 + 0x180);
  lVar2 = *(longlong *)(lVar1 + 0x48);
  InitializeFunctionSuspendControlRequest(param_1,param_2,param_3);
  if (param_3 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = 0x56;
LAB_1400144dc:
      WPP_RECORDER_SF_qq(*(undefined8 *)(param_2 + 0x188),4,3,uVar5,
                         &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                         (char)*(undefined8 *)(param_2 + 0xe0),(char)lVar2);
    }
  }
  else {
    if (param_3 != 1) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qq(*(undefined8 *)(param_2 + 0x188),4,3,0x58,
                           &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                           (char)*(undefined8 *)(param_2 + 0xe0),(char)lVar2);
      }
      uVar3 = 0;
      goto LAB_140014551;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = 0x57;
      goto LAB_1400144dc;
    }
  }
  uVar3 = 1;
LAB_140014551:
  *(undefined1 *)(lVar1 + 0x3b) = uVar3;
  *(undefined1 *)(lVar1 + 0x3a) = 1;
  uVar4 = CallNextDriverSync(param_1,lVar2,'\x01');
  *(undefined4 *)(lVar1 + 0x58) = uVar4;
  *(undefined1 *)(lVar1 + 0x3a) = 0;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(param_2 + 0x188),4,3,0x59,
                       &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                       (char)*(undefined8 *)(param_2 + 0xe0),(char)uVar4);
  }
  IoReuseIrp(lVar2,0);
  return uVar4;
}



===== WPP_RECORDER_SF_qLd @ 1400145e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((char)*(undefined4 *)(WPP_GLOBAL_Control + 0x2c) < '\0') &&
     (1 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,0x29,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,4,0);
  }
  WppAutoLogTrace(param_1,2,8,&WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,0x29,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,4,0);
  return;
}



===== WPP_RECORDER_SF_qqqd @ 1400146d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqqd
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,8,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,8,&param_9,4,0);
  return;
}



===== WaitWakeFinishCompletionWorker @ 1400147f0 =====

void WaitWakeFinishCompletionWorker(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong ****pppplVar1;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    param_3 = 3;
    WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x560),4,3,0x19,
                      &WPP_6d8a51a08a9b3edb1d37cbc5358a5e6d_Traceguids,
                      (char)*(undefined8 *)(param_1 + 0x20));
  }
  if (*(char *)(param_1 + 0x55a) == '\0') {
    pppplVar1 = (longlong ****)0x0;
  }
  else {
    if (*(int *)(param_1 + 0x240) != 2) {
      FinishWaitWakeCompletionForFunctionSuspend(param_1);
      return;
    }
    pppplVar1 = (longlong ****)0xc0000120;
  }
  CompleteAllPdoWaitWakeIrps(param_1,pppplVar1,param_3);
  return;
}



===== RtlStringVPrintfWorkerW @ 140014870 =====

undefined4
RtlStringVPrintfWorkerW
          (wchar_t *param_1,longlong param_2,ulonglong *param_3,wchar_t *param_4,va_list param_5)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong _Count;
  undefined4 uVar3;
  
  _Count = param_2 - 1;
  uVar3 = 0;
  iVar1 = _vsnwprintf(param_1,_Count,param_4,param_5);
  if (iVar1 < 0) {
LAB_1400148c5:
    uVar3 = 0x80000005;
  }
  else {
    uVar2 = (ulonglong)iVar1;
    if (_Count < uVar2) goto LAB_1400148c5;
    if (uVar2 != _Count) {
      _Count = uVar2;
      goto LAB_1400148cf;
    }
  }
  param_1[_Count] = L'\0';
LAB_1400148cf:
  if (param_3 != (ulonglong *)0x0) {
    *param_3 = _Count;
  }
  return uVar3;
}



===== WPP_RECORDER_SF_SD @ 1400148fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_SD(void)

{
  undefined8 uVar1;
  undefined1 uStack0000000000000038;
  
  uVar1 = g_RecorderLog;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (3 < *(byte *)(WPP_GLOBAL_Control + 0x29))) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_250a8722b9c73d5bc894b816de363468_Traceguids,10,L"CdcFlags",0x12,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(uVar1,4,1,&WPP_250a8722b9c73d5bc894b816de363468_Traceguids,10,L"CdcFlags",0x12,
                  &uStack0000000000000038,4,0);
  return;
}



===== RtlStringCbCatW @ 1400149d8 =====

uint RtlStringCbCatW(short *param_1,ulonglong param_2)

{
  short sVar1;
  short *psVar2;
  short *psVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong lVar8;
  
  uVar6 = param_2 >> 1;
  if (uVar6 - 1 < 0x7fffffff) {
    psVar2 = param_1;
    uVar5 = uVar6;
    do {
      if (*psVar2 == 0) break;
      psVar2 = psVar2 + 1;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
    if (uVar5 != 0) {
      lVar7 = uVar6 - uVar5;
      psVar2 = param_1 + lVar7;
      lVar4 = uVar6 - lVar7;
      if (lVar4 != 0) {
        lVar7 = (lVar7 - uVar6) + 0x7ffffffe + lVar4;
        lVar8 = (longlong)L"\\Parameters" - (longlong)psVar2;
        do {
          if ((lVar7 == 0) || (sVar1 = *(short *)(lVar8 + (longlong)psVar2), sVar1 == 0)) break;
          *psVar2 = sVar1;
          lVar7 = lVar7 + -1;
          psVar2 = psVar2 + 1;
          lVar4 = lVar4 + -1;
        } while (lVar4 != 0);
      }
      psVar3 = psVar2 + -1;
      if (lVar4 != 0) {
        psVar3 = psVar2;
      }
      *psVar3 = 0;
      return ~-(uint)(lVar4 != 0) & 0x80000005;
    }
  }
  return 0xc000000d;
}



===== SleepstudyHelper_UnregisterComponent @ 140014a9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SleepstudyHelper_UnregisterComponent(undefined *param_1)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  
  uVar3 = Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    iVar1 = 0;
    if (param_1 != &SleepstudyHelperUnsupportedHandle) {
      if (DAT_14001c508 == (code *)0x0) {
        iVar2 = -0x3fffff45;
      }
      else {
        iVar2 = (*DAT_14001c508)(param_1);
      }
      iVar1 = 0;
      if (iVar2 != -0x3fffff45) {
        iVar1 = iVar2;
      }
    }
  }
  else if (DAT_14001c508 == (code *)0x0) {
    iVar1 = -0x3fffff45;
  }
  else {
    iVar1 = (*DAT_14001c508)(param_1);
  }
  return iVar1;
}



===== __GSHandlerCheck @ 140014b28 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140014b4c =====

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



===== __cpu_features_init @ 140014bc0 =====

/* WARNING: Removing unreachable block (ram,0x000140014c2a) */
/* WARNING: Removing unreachable block (ram,0x000140014bd9) */
/* WARNING: Removing unreachable block (ram,0x000140014bca) */

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



===== __security_check_cookie @ 140014c90 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140014cd0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140014d00 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140014d00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140014d30 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140014d80 =====

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



===== memset @ 140015080 =====

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



===== __memset_repmovs @ 1400151c0 =====

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



===== __memset_query @ 140015240 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1400152c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 140015400 =====

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



===== __memset_spec_plain @ 140015480 =====

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



===== FindMidiInterfaceDescriptor @ 140022008 =====

byte * FindMidiInterfaceDescriptor
                 (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  pbVar1 = (byte *)USBD_ParseConfigurationDescriptorEx
                             (param_1,param_2,0xffffffff,0xffffffff,1,3,0xffffffff);
  while( true ) {
    if (pbVar1 == (byte *)0x0) {
      return (byte *)0x0;
    }
    pbVar3 = pbVar1 + *pbVar1;
    if (pbVar3 < pbVar1) break;
    pbVar2 = (byte *)USBD_ParseConfigurationDescriptorEx
                               (param_1,pbVar3,0xffffffff,0xffffffff,1,3,0xffffffff);
    pbVar3 = (byte *)USBD_ParseDescriptors(param_1,*(undefined2 *)(param_1 + 2),pbVar3,0x24);
    if (((pbVar3 == (byte *)0x0) ||
        (((pbVar2 != (byte *)0x0 && (pbVar2 < pbVar3)) || (*pbVar3 < 7)))) || (pbVar3[2] != 1)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return (byte *)0x0;
      }
      WPP_RECORDER_SF_q(param_4,2,8,0x13,&WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,
                        (char)pbVar1);
      return (byte *)0x0;
    }
    if (pbVar3[4] == 2) {
      return pbVar1;
    }
    pbVar1 = pbVar2;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
    return (byte *)0x0;
  }
  WPP_RECORDER_SF_qd(param_4,2,8,0x12,&WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,(char)pbVar1,
                     *pbVar1);
  return (byte *)0x0;
}



===== WppCleanupKm @ 140022184 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppCleanupKm(undefined8 param_1)

{
  undefined8 *puVar1;
  
  if ((undefined8 **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar1 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; puVar1 != (undefined8 *)0x0; puVar1 = (undefined8 *)puVar1[2]) {
        if (puVar1[7] != 0) {
          (*pfnEtwUnregister)();
          puVar1[7] = 0;
        }
      }
    }
    else if (WPPTraceSuite == 2) {
      IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
    }
    WppAutoLogStop(WPP_GLOBAL_Control,param_1);
    WPP_GLOBAL_Control = &WPP_GLOBAL_Control;
    WPP_RECORDER_INITIALIZED = (undefined *)&WPP_RECORDER_INITIALIZED;
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140022234 =====

uint wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
               (uint *param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if ((uVar1 >> 9 & 1) != 0) {
    uVar1 = wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState
                      (param_1,uVar1,param_2);
  }
  return uVar1;
}



===== CdcBuildCompatibleIDs @ 14002226c =====

int CdcBuildCompatibleIDs
              (wchar_t *param_1,undefined8 param_2,short *param_3,longlong param_4,int param_5)

{
  wchar_t *pwVar1;
  int iVar2;
  ulonglong uVar3;
  wchar_t *local_res8 [2];
  ulonglong local_38 [2];
  
  local_38[0] = 0x400;
  if (param_5 == 0) {
    return -0x3fffff1b;
  }
  local_res8[0] = param_1;
  if ((param_5 == 1) || (param_5 == 2)) {
    iVar2 = RtlStringCbPrintfExW
                      (param_1,0x400,(ulonglong *)local_res8,(longlong *)local_38,0,
                       L"USB\\Class_%02x&SubClass_%02x&Prot_%02x",*(char *)(param_4 + 5));
  }
  else if (param_5 == 3) {
    iVar2 = RtlStringCbPrintfExW
                      (param_1,0x400,(ulonglong *)local_res8,(longlong *)local_38,0,
                       L"USB\\Class_%02x&SubClass_Modem&Prot_%02x",*(char *)(param_4 + 5));
  }
  else {
    if (param_5 != 4) {
      return -0x3fffff1b;
    }
    iVar2 = RtlStringCbPrintfExW
                      (param_1,0x400,(ulonglong *)local_res8,(longlong *)local_38,0,
                       L"USB\\Class_%02x&WPD_OBEX",*(char *)(param_4 + 5));
  }
  if (iVar2 < 0) {
    return iVar2;
  }
  if (local_38[0] < 3) {
    return -0x7ffffffb;
  }
  uVar3 = local_38[0] - 2;
  *local_res8[0] = L'\0';
  pwVar1 = local_res8[0] + 1;
  if ((param_5 == 1) || (param_5 == 2)) {
    local_res8[0] = pwVar1;
    local_38[0] = uVar3;
    iVar2 = RtlStringCbPrintfExW
                      (pwVar1,uVar3,(ulonglong *)local_res8,(longlong *)local_38,0,
                       L"USB\\Class_%02x&SubClass_%02x",*(char *)(param_4 + 5));
  }
  else {
    if (param_5 != 3) goto LAB_14002241c;
    local_res8[0] = pwVar1;
    local_38[0] = uVar3;
    iVar2 = RtlStringCbPrintfExW
                      (pwVar1,uVar3,(ulonglong *)local_res8,(longlong *)local_38,0,
                       L"USB\\Class_%02x&SubClass_Modem",*(char *)(param_4 + 5));
  }
  if (iVar2 < 0) {
    return iVar2;
  }
LAB_14002241c:
  if (2 < local_38[0]) {
    uVar3 = local_38[0] - 2;
    *local_res8[0] = L'\0';
    pwVar1 = local_res8[0] + 1;
    if ((((param_5 == 1) || (param_5 == 2)) || (param_5 == 3)) || (param_5 == 4)) {
      local_res8[0] = pwVar1;
      local_38[0] = uVar3;
      iVar2 = RtlStringCbPrintfExW
                        (pwVar1,uVar3,(ulonglong *)local_res8,(longlong *)local_38,0,
                         L"USB\\Class_%02x",*(char *)(param_4 + 5));
      if (iVar2 < 0) {
        return iVar2;
      }
    }
    if (4 < local_38[0]) {
      local_res8[0][0] = L'\0';
      local_res8[0][1] = L'\0';
      *param_3 = 0x400 - ((short)local_38[0] + -4);
      return iVar2;
    }
  }
  return -0x7ffffffb;
}



===== WppTraceCallback @ 1400224d0 =====

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



===== wil_RtlStagingConfig_QueryFeatureState @ 140022758 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 wil_RtlStagingConfig_QueryFeatureState(uint *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  uint local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  local_20 = 0;
  local_18 = 0;
  iVar1 = RtlQueryFeatureConfiguration(param_2,param_3 == 0,&local_28,&local_20);
  if (iVar1 == 0) {
    *param_1 = local_20._4_4_ >> 4 & 3;
    *(byte *)(param_1 + 1) = (byte)((ulonglong)local_20 >> 0x28) & 0x3f;
    param_1[3] = local_18;
    param_1[2] = local_20._4_4_ >> 0xe & 3;
    param_1[5] = local_20._4_4_ >> 6 & 1;
    param_1[4] = local_20._4_4_ >> 7 & 1;
  }
  else {
    if (iVar1 != 0x117) {
      return 0;
    }
    param_1[4] = local_20._4_4_ >> 7 & 1;
  }
  return 1;
}



===== wil_UninitializeFeatureStaging @ 140022824 =====

void wil_UninitializeFeatureStaging(void)

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
  return;
}



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 14002287c =====

void wil_details_BuildFeatureStateCacheFromQueryResults(int param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  
  if ((param_1 == -0x7fffffde) || (param_1 == -0x3ffffddb)) {
    param_3[0] = 0;
    param_3[1] = 0;
  }
  else {
    param_3[0] = 0;
    param_3[1] = 0;
    if (param_1 == 0) {
      uVar1 = ((*(uint *)(param_2 + 4) & 0x40) << 2 | *(uint *)(param_2 + 4) & 0xb0) << 3 | 0x206;
      goto LAB_1400228d9;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_1400228d9;
    }
  }
  uVar1 = 0x206;
LAB_1400228d9:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 1400228e4 =====

uint wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState
               (uint *param_1,uint param_2,longlong param_3)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  longlong *plVar4;
  uint uVar5;
  bool bVar6;
  
  uVar5 = param_2 >> 6 & 1;
  if ((uVar5 != 0) && (plVar4 = *(longlong **)(param_3 + 0x20), plVar4 != (longlong *)0x0)) {
    do {
      while( true ) {
        puVar1 = (undefined8 *)*plVar4;
        if (puVar1 == (undefined8 *)0x0) goto LAB_140022966;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_140022966;
        }
        uVar5 = 1;
        plVar4 = plVar4 + 1;
      }
      uVar2 = wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
                        ((uint *)*puVar1,(longlong)puVar1);
      if ((uVar5 == 0) || ((uVar2 & 1) == 0)) {
        uVar5 = 0;
      }
      else {
        uVar5 = 1;
      }
      plVar4 = plVar4 + 1;
    } while (uVar5 != 0);
  }
LAB_140022966:
  do {
    uVar2 = param_2 & 0xffffffce;
    if ((param_2 & 1) == uVar5) {
      uVar2 = param_2 & 0xfffffffe;
    }
    uVar3 = uVar2 & 0xfffffdff | uVar5;
    LOCK();
    uVar2 = *param_1;
    bVar6 = param_2 == uVar2;
    if (bVar6) {
      *param_1 = uVar3;
    }
    else {
      param_2 = uVar2;
    }
    UNLOCK();
  } while (!bVar6);
  return uVar3;
}



===== wil_details_OnFeatureUsageProviderFlushNotification @ 1400229b0 =====

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  
  iVar1 = g_wil_details_featureUsageCached;
  if (param_1 == 1) {
    LOCK();
    g_wil_details_featureUsageCached = 0;
    UNLOCK();
    if (iVar1 != 0) {
      ppuVar3 = &Feature_SPR_HardenInClient__private_descriptor;
      while (plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3),
            plVar2 != (longlong *)0x0) {
        if ((*(uint *)plVar2[1] & 1) != 0) {
          wil_details_RecordCachedUsage((int)plVar2[3],(uint *)plVar2[1]);
        }
        ppuVar3 = (undefined **)(plVar2 + 7);
      }
    }
  }
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140022a10 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 140022a2c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_UpdateFeatureConfiguredStates(void)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  undefined1 auStack_58 [32];
  uint local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  ppuVar3 = &Feature_SPR_HardenInClient__private_descriptor;
  while( true ) {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3);
    if (plVar2 == (longlong *)0x0) break;
    if (((*(char *)((longlong)plVar2 + 0x1d) == '\0') &&
        (*(char *)((longlong)plVar2 + 0x1e) == '\0')) &&
       (*(char *)((longlong)plVar2 + 0x1c) == '\0')) {
      local_30 = 0;
      local_28 = 0;
      local_20 = 0;
      iVar1 = RtlQueryFeatureConfiguration((int)plVar2[3],1,&local_30,&local_28);
      local_38[0] = 0;
      local_38[1] = 0;
      wil_details_BuildFeatureStateCacheFromQueryResults(iVar1,(longlong)&local_28,local_38);
      LOCK();
      *(uint *)*plVar2 = *(uint *)*plVar2 ^ (*(uint *)*plVar2 ^ local_38[0]) & 0xf80;
      UNLOCK();
    }
    ppuVar3 = (undefined **)(plVar2 + 7);
  }
  return;
}



===== USBC_SetContentId @ 140022ae0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void USBC_SetContentId(longlong param_1,longlong param_2,undefined4 *param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x28) + 0x40);
  if (*(char *)(lVar1 + 4) == '\0') {
    uVar2 = *(undefined8 *)(*(longlong *)(lVar1 + 0xf0) + 0x20);
  }
  else {
    uVar2 = *(undefined8 *)(lVar1 + 0x30);
  }
  (**(code **)(param_2 + 0x38))(*param_3,uVar2,*(undefined8 *)(param_2 + 0x18));
  return;
}



===== ParentFindAltConfiguration @ 140022b2c =====

int ParentFindAltConfiguration(longlong param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 local_res8 [2];
  int local_res18 [2];
  uint in_stack_ffffffffffffffe8;
  
  local_res18[0] = 0;
  local_res8[0] = 0;
  iVar2 = GetPdoRegistryParameter
                    (*(undefined8 *)(param_1 + 0x18),L"AltConfigurationValue",local_res8,4,
                     local_res18,(undefined4 *)0x0,in_stack_ffffffffffffffe8 & 0xffffff00);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,1,0x45,
                        &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)iVar2);
    }
  }
  else {
    bVar1 = (byte)local_res8[0];
    if (((local_res18[0] == 4) && (bVar1 != *param_2)) && (bVar1 < *(byte *)(param_1 + 0x71))) {
      *param_2 = bVar1;
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0x46,
                          &WPP_93f6b87810f63f9db566694056813e32_Traceguids,bVar1);
      }
      iVar2 = -0x3ffffff3;
    }
  }
  return iVar2;
}



===== AppendPdoIds @ 140022c28 =====

void * AppendPdoIds(short *param_1,ushort *param_2)

{
  uint uVar1;
  void *_Dst;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = CalculateMultiStringLength(param_1);
  uVar4 = *param_2 + 2 + uVar1 * 2;
  uVar3 = uVar4 >> 1;
  uVar2 = 0x100;
  if (ExDefaultNonPagedPoolType == 1) {
    uVar2 = 0x40;
  }
  _Dst = (void *)ExAllocatePool2(uVar2,uVar4,0x43627355);
  if (_Dst != (void *)0x0) {
    memmove(_Dst,param_1,(ulonglong)(uVar1 * 2));
    memmove((void *)((longlong)_Dst + (ulonglong)uVar1 * 2),*(void **)(param_2 + 4),
            (ulonglong)*param_2);
    *(undefined2 *)((longlong)_Dst + (ulonglong)(uVar3 - 1) * 2) = 0;
    *(undefined2 *)((longlong)_Dst + (ulonglong)(uVar3 - 2) * 2) = 0;
  }
  return _Dst;
}



===== D3ColdSupportInterfaceFunctionGetD3ColdCapability @ 140022d00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
D3ColdSupportInterfaceFunctionGetD3ColdCapability(longlong param_1,char *param_2,undefined8 param_3)

{
  undefined4 uVar1;
  char *pcVar2;
  undefined8 in_stack_ffffffffffffffd8;
  
  uVar1 = (**(code **)(*(longlong *)(param_1 + 0xe8) + 0x1f0))
                    (*(undefined8 *)(*(longlong *)(param_1 + 0xe8) + 0x1c8));
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    pcVar2 = "TRUE";
    if (*param_2 == '\0') {
      pcVar2 = "FALSE";
    }
    WPP_RECORDER_SF_qsd(*(undefined8 *)(param_1 + 0x188),pcVar2,param_3,0x5c,
                        in_stack_ffffffffffffffd8,(char)*(undefined8 *)(param_1 + 0xe0),pcVar2,
                        (char)uVar1);
  }
  return uVar1;
}



===== D3ColdSupportInterfaceFunctionSetD3ColdSupport @ 140022da0 =====

void D3ColdSupportInterfaceFunctionSetD3ColdSupport(longlong param_1,undefined1 param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0xe8) + 0x208;
  AcquireMutex(lVar1,"D3ColdStateMutex",*(undefined8 *)(*(longlong *)(param_1 + 0xe8) + 0x560));
  *(undefined1 *)(param_1 + 0x75) = param_2;
  ChangeParentD3ColdStateLocked(*(longlong *)(param_1 + 0xe8));
  KeReleaseMutex(lVar1,0);
  return;
}



===== InstallMsOs20RegistryValues @ 140022e14 =====

int InstallMsOs20RegistryValues(longlong param_1)

{
  ulonglong uVar1;
  int iVar2;
  ushort *puVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ushort uVar8;
  undefined2 uVar9;
  ulonglong local_res10;
  
  puVar3 = GetFunctionMsOs20FunctionSubset(param_1);
  if (puVar3 != (ushort *)0x0) {
    uVar7 = (ulonglong)puVar3[3] + (longlong)puVar3;
    local_res10 = (ulonglong)*puVar3 + (longlong)puVar3;
    do {
      uVar1 = local_res10;
      if (*(short *)(local_res10 + 2) == 4) {
        uVar4 = Feature_1916511546__private_IsEnabledDeviceUsageNoInline();
        uVar6 = (ulonglong)*(ushort *)(uVar1 + 6);
        if ((int)uVar4 == 0) {
          uVar8 = *(ushort *)(uVar6 + 8 + uVar1);
        }
        else {
          if (uVar7 < uVar6 + 10 + uVar1) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return 0;
            }
            uVar9 = 0x4b;
LAB_140022f10:
            WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x188),2,8,uVar9,
                             &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids);
            return 0;
          }
          uVar8 = *(ushort *)(uVar6 + 8 + uVar1);
          if (uVar7 < uVar6 + 10 + (ulonglong)uVar8 + uVar1) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return 0;
            }
            uVar9 = 0x4c;
            goto LAB_140022f10;
          }
        }
        iVar2 = SetPdoRegistryParameter
                          (*(undefined8 *)(param_1 + 0xe0),uVar1 + 8,uVar6 + 10 + uVar1,(uint)uVar8,
                           (uint)*(ushort *)(uVar1 + 4));
        if (iVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x188),2,8,0x4d,
                              &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,(char)iVar2);
          }
          return iVar2;
        }
      }
      uVar5 = GetNextMsOs20Descriptor(uVar7,&local_res10);
      if ((char)uVar5 == '\0') {
        return -0x3fffffff;
      }
    } while (local_res10 != 0);
  }
  return 0;
}



===== IsMSOSCompatibleIDFlagSet @ 140022f84 =====

byte IsMSOSCompatibleIDFlagSet(longlong param_1)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  int local_res8 [2];
  undefined4 local_res10 [2];
  undefined4 in_stack_ffffffffffffffe8;
  
  local_res8[0] = 0;
  local_res10[0] = 0;
  iVar1 = GetPdoRegistryParameter
                    (*(undefined8 *)(*(longlong *)(param_1 + 0xe8) + 0x18),L"EnumeratorFlag",
                     local_res10,4,local_res8,(undefined4 *)0x0,
                     CONCAT31((int3)((uint)in_stack_ffffffffffffffe8 >> 8),1));
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    uVar2 = 2;
    uVar3 = 0x46;
  }
  else {
    if (local_res8[0] == 4) {
      return (byte)local_res10[0] & 1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    uVar3 = 0x47;
    uVar2 = 8;
    iVar1 = local_res8[0];
  }
  WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x188),2,uVar2,uVar3,
                    &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,(char)iVar1);
  return 0;
}



===== PrependMSOSCompatibleIDs @ 140023050 =====

short * PrependMSOSCompatibleIDs(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  short *psVar3;
  uint uVar4;
  uint local_res8 [2];
  char *local_res10;
  char *local_res18 [2];
  
  lVar1 = *(longlong *)(param_1 + 0xf0);
  local_res18[0] = (char *)0x0;
  local_res10 = (char *)0x0;
  local_res8[0] = 0;
  GetFunctionMSOSCompatibleIDs(param_1,(longlong *)local_res18,(longlong *)&local_res10);
  if (*(longlong *)(lVar1 + 0x30) == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (uint)*(ushort *)(lVar1 + 0x28);
  }
  psVar3 = BuildMSOSCompatibleIDs(local_res18[0],local_res10,uVar4,(int *)local_res8);
  uVar2 = local_res8[0];
  if (psVar3 != (short *)0x0) {
    if (*(void **)(lVar1 + 0x30) != (void *)0x0) {
      memmove(psVar3 + (local_res8[0] >> 1),*(void **)(lVar1 + 0x30),
              (ulonglong)*(ushort *)(lVar1 + 0x28));
    }
    psVar3[uVar4 + uVar2 >> 1] = 0;
  }
  return psVar3;
}



===== HandleFdoDeviceUsageNotification @ 1400230f0 =====

uint HandleFdoDeviceUsageNotification(longlong param_1,longlong param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  cVar1 = IoForwardIrpSynchronously(*(undefined8 *)(param_1 + 0x28));
  if (cVar1 != '\0') {
    if (iVar2 - 1U < 3) {
      uVar3 = *(uint *)(*(longlong *)(param_1 + 0x20) + 0x30);
      if ((*(uint *)(*(longlong *)(param_1 + 0x28) + 0x30) & 0x2000) == 0) {
        uVar3 = uVar3 & 0xffffdfff;
      }
      else {
        uVar3 = uVar3 | 0x2000;
      }
      *(uint *)(*(longlong *)(param_1 + 0x20) + 0x30) = uVar3;
    }
    iVar2 = RtlCheckRegistryKey(2,L"MiniNT");
    if ((iVar2 < 0) && (*(char *)(param_1 + 0x568) == '\0')) {
      *(undefined1 *)(param_1 + 0x568) = 1;
      TerminateIdleTimer(param_1);
      KeFlushQueuedDpcs();
      WaitForSignal(param_1 + 0x300,"noIdleDpcPendingEvent (wait for DPC to complete)",
                    *(undefined8 *)(param_1 + 0x560));
      WaitForSignal(param_1 + 0x368,
                    "idleCallbackBusyEvent (waiting for IdleCallback to run to completion)",
                    *(undefined8 *)(param_1 + 0x560));
      WaitForSignal(param_1 + 0x3c0,"idleCompleteEvent",*(undefined8 *)(param_1 + 0x560));
    }
  }
  return ~-(uint)(cVar1 != '\0') & 0xc0000001;
}



===== HandlePdoDeviceUsageNotification @ 140023204 =====

int HandlePdoDeviceUsageNotification(longlong param_1,longlong param_2)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  longlong lVar9;
  longlong lVar10;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  puVar3 = *(undefined1 **)(param_2 + 0xb8);
  lVar4 = *(longlong *)(param_1 + 0xe0);
  iVar2 = *(int *)(puVar3 + 0x10);
  cVar1 = puVar3[8];
  if (iVar2 - 1U < 4) {
    lVar9 = IoGetAttachedDevice(*(undefined8 *)(*(longlong *)(param_1 + 0xe8) + 0x20));
    lVar10 = IoAllocateIrp(*(undefined1 *)(lVar9 + 0x4c),0);
    if (lVar10 == 0) {
      iVar6 = -0x3fffff66;
    }
    else {
      *(undefined4 *)(lVar10 + 0x30) = 0xc00000bb;
      local_38 = 0;
      local_48 = 0;
      uStack_40 = 0;
      KeInitializeEvent(&local_48,0,0);
      lVar5 = *(longlong *)(lVar10 + 0xb8);
      *(code **)(lVar5 + -0x10) = USBD_SyncCompletionRoutine;
      *(undefined8 **)(lVar5 + -8) = &local_48;
      *(undefined1 *)(lVar5 + -0x45) = 0xe0;
      lVar5 = *(longlong *)(lVar10 + 0xb8);
      *(undefined1 *)(lVar5 + -0x48) = *puVar3;
      *(undefined1 *)(lVar5 + -0x47) = puVar3[1];
      *(undefined8 *)(lVar5 + -0x18) = *(undefined8 *)(puVar3 + 0x30);
      *(char *)(lVar5 + -0x40) = cVar1;
      *(int *)(lVar5 + -0x38) = iVar2;
      iVar6 = IofCallDriver(lVar9,lVar10);
      if (iVar6 == 0x103) {
        KeWaitForSingleObject(&local_48,5,0,0,0);
      }
      iVar6 = *(int *)(lVar10 + 0x30);
      IoFreeIrp(lVar10);
      if (-1 < iVar6) {
        if (iVar2 < 4) {
          if (cVar1 == '\0') {
            LOCK();
            *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + -1;
            UNLOCK();
          }
          else {
            LOCK();
            *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 1;
            UNLOCK();
          }
          uVar7 = *(uint *)(lVar4 + 0x30);
          if (*(int *)(param_1 + 400) == 0) {
            uVar7 = uVar7 | 0x2000;
          }
          else {
            uVar7 = uVar7 & 0xffffdfff;
          }
          *(uint *)(lVar4 + 0x30) = uVar7;
        }
        iVar8 = RtlCheckRegistryKey(2,L"MiniNT");
        if ((iVar8 < 0) && (iVar2 == 4)) {
          *(undefined1 *)(param_1 + 0x194) = 1;
        }
      }
    }
    *(int *)(param_2 + 0x30) = iVar6;
    IofCompleteRequest(param_2,0);
  }
  else {
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(undefined1 **)(param_2 + 0xb8) = puVar3 + 0x48;
    iVar6 = IofCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0xe8) + 0x20));
  }
  return iVar6;
}



===== CheckOptInWinUsbPrint @ 140023408 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint CheckOptInWinUsbPrint(ushort param_1,ushort param_2)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined1 auStack_d8 [32];
  uint local_b8;
  uint *local_b0;
  uint local_a8 [2];
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 *local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  ulonglong uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  wchar_t local_48 [20];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_d8;
  local_78 = 0;
  uVar2 = 0;
  uStack_70 = uStack_70 & 0xffffffff00000000;
  local_a0 = 0;
  local_a8[0] = 0x14;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = (undefined8 *)0x0;
  uStack_80 = 0;
  lVar3 = ExAllocatePool2(0x100,0x14,0x43627355);
  if (lVar3 != 0) {
    RtlInitUnicodeString
              (&local_68,
               L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Print\\Monitors\\WinUsbMon\\OptInModels"
              );
    local_b8 = (uint)param_2;
    uVar4 = RtlStringCbPrintfW(local_48,0x24,L"VID_%04X&PID_%04X",(ulonglong)param_1);
    if (-1 < (int)uVar4) {
      RtlInitUnicodeString(&local_58,local_48);
      local_88 = &local_68;
      local_98 = CONCAT44(local_98._4_4_,0x30);
      uStack_90 = 0;
      uStack_80 = CONCAT44(uStack_80._4_4_,0x240);
      local_78 = 0;
      uStack_70 = 0;
      iVar1 = ZwOpenKey(&local_a0,1,&local_98);
      if (-1 < iVar1) {
        local_b0 = local_a8;
        local_b8 = local_a8[0];
        uVar2 = ZwQueryValueKey(local_a0,&local_58,2,lVar3);
        ZwClose(local_a0);
        uVar2 = ~uVar2 >> 0x1f;
      }
    }
    ExFreePoolWithTag(lVar3,0);
  }
  return uVar2;
}



===== USBC_QueryWmiDataBlock @ 140023590 =====

void USBC_QueryWmiDataBlock(longlong param_1,undefined8 param_2,int param_3)

{
  undefined4 uVar1;
  ulonglong uVar2;
  uint local_res18 [4];
  uint in_stack_00000038;
  undefined4 *in_stack_00000040;
  
  local_res18[0] = 0;
  if (param_3 == 0) {
    uVar2 = GetParentNodeInfo(param_1,in_stack_00000040,in_stack_00000038,local_res18);
    uVar1 = (undefined4)uVar2;
  }
  else {
    uVar1 = 0xc0000295;
  }
  WmiCompleteRequest(param_1,param_2,uVar1,local_res18[0],0);
  return;
}



===== ProcessCallbackData @ 1400235fc =====

undefined8
ProcessCallbackData(longlong param_1,longlong *param_2,uint *param_3,longlong param_4,uint param_5)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  longlong lVar7;
  undefined8 uVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong lVar11;
  uint uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  uint uVar15;
  
  uVar8 = 0;
  uVar15 = (uint)((ulonglong)param_5 / 0x50);
  lVar7 = ExAllocatePool2(0x40,((ulonglong)param_5 / 0x50) * 0x58,0x43627355);
  if (lVar7 == 0) {
    uVar8 = 0xc000009a;
  }
  else {
    for (uVar14 = 0; (uint)uVar14 < uVar15; uVar14 = (ulonglong)((uint)uVar14 + 1)) {
      lVar9 = ExAllocatePool2(0x40);
      lVar11 = uVar14 * 0x58;
      *(longlong *)(lVar11 + 8 + lVar7) = lVar9;
      if (lVar9 == 0) {
        uVar8 = 0xc000009a;
        CleanFunctionList(lVar7,uVar15);
        *param_2 = 0;
        *param_3 = 0;
        goto LAB_1400237d8;
      }
      *(undefined1 *)(lVar11 + 6 + lVar7) = *(undefined1 *)(param_4 + 1 + uVar14 * 0x50);
      *(char *)(lVar11 + 4 + lVar7) = (char)uVar14;
      *(undefined4 *)(lVar11 + lVar7) = 0x636e7546;
      *(undefined1 *)(lVar11 + 5 + lVar7) =
           *(undefined1 *)(**(longlong **)(param_4 + 8 + uVar14 * 0x50) + 2);
      if ((*(uint *)(param_4 + 0x40 + uVar14 * 0x50) & 1) != 0) {
        puVar1 = (uint *)(lVar11 + 0x50 + lVar7);
        *puVar1 = *puVar1 | 1;
      }
      uVar13 = 0;
      if (*(char *)(param_4 + 1 + uVar14 * 0x50) != '\0') {
        do {
          for (plVar10 = *(longlong **)(param_1 + 0x58); plVar10 != (longlong *)0x0;
              plVar10 = plVar10 + 2) {
            if (*(char *)(*plVar10 + 2) ==
                *(char *)(*(longlong *)(*(longlong *)(param_4 + 8 + uVar14 * 0x50) + uVar13 * 8) + 2
                         )) {
              *(longlong **)(*(longlong *)(lVar11 + 8 + lVar7) + uVar13 * 8) = plVar10;
              break;
            }
          }
          uVar12 = (int)uVar13 + 1;
          uVar13 = (ulonglong)uVar12;
        } while (uVar12 < *(byte *)(param_4 + 1 + uVar14 * 0x50));
      }
      if (*(longlong *)(param_4 + 8 + uVar14 * 0x50) != 0) {
        ExFreePoolWithTag();
        *(undefined8 *)(param_4 + 8 + uVar14 * 0x50) = 0;
      }
      if (*(longlong *)(param_4 + 0x18 + uVar14 * 0x50) != 0) {
        puVar2 = (undefined4 *)(param_4 + 0x10 + uVar14 * 0x50);
        uVar4 = puVar2[1];
        uVar5 = puVar2[2];
        uVar6 = puVar2[3];
        puVar3 = (undefined4 *)(lVar11 + 0x18 + lVar7);
        *puVar3 = *puVar2;
        puVar3[1] = uVar4;
        puVar3[2] = uVar5;
        puVar3[3] = uVar6;
      }
      if (*(longlong *)(param_4 + 0x28 + uVar14 * 0x50) != 0) {
        puVar2 = (undefined4 *)(param_4 + 0x20 + uVar14 * 0x50);
        uVar4 = puVar2[1];
        uVar5 = puVar2[2];
        uVar6 = puVar2[3];
        puVar3 = (undefined4 *)(lVar11 + 0x28 + lVar7);
        *puVar3 = *puVar2;
        puVar3[1] = uVar4;
        puVar3[2] = uVar5;
        puVar3[3] = uVar6;
      }
      if (*(longlong *)(param_4 + 0x38 + uVar14 * 0x50) != 0) {
        puVar2 = (undefined4 *)(param_4 + 0x30 + uVar14 * 0x50);
        uVar4 = puVar2[1];
        uVar5 = puVar2[2];
        uVar6 = puVar2[3];
        puVar3 = (undefined4 *)(lVar11 + 0x38 + lVar7);
        *puVar3 = *puVar2;
        puVar3[1] = uVar4;
        puVar3[2] = uVar5;
        puVar3[3] = uVar6;
      }
    }
    *param_3 = uVar15;
    *param_2 = lVar7;
    if (param_4 != 0) {
      ExFreePoolWithTag(param_4,0);
    }
  }
LAB_1400237d8:
  return uVar8;
}



===== ProcessFunctionDescriptors @ 1400237f4 =====

ulonglong ProcessFunctionDescriptors
                    (longlong param_1,ulonglong param_2,uint param_3,longlong *param_4,uint *param_5
                    )

{
  longlong lVar1;
  longlong *plVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  *param_4 = 0;
  lVar1 = *(longlong *)(param_1 + 0x38);
  plVar2 = *(longlong **)(param_1 + 0x58);
  *param_5 = 0;
  uVar3 = ValidateCallbackData(plVar2,lVar1,param_2,param_3);
  uVar4 = uVar3 & 0xffffffff;
  if ((int)(uint)uVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,10,
                        &WPP_e8749e7517b2302104950dba271a6a56_Traceguids,(char)uVar3);
    }
    RecordStartFailData(param_1,(uint)uVar3,0,0xa0000009,0x464c4342,*(void **)(param_1 + 0x30),
                        (uint)*(ushort *)((longlong)*(void **)(param_1 + 0x30) + 2));
  }
  else {
    uVar3 = ProcessCallbackData(param_1,param_4,param_5,param_2,param_3);
    uVar4 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      return uVar4;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0xb,
                        &WPP_e8749e7517b2302104950dba271a6a56_Traceguids,(char)uVar3);
    }
  }
  CleanFunctionDescriptorArray(param_2,param_3);
  return uVar4;
}



===== ValidateCallbackData @ 140023928 =====

ulonglong ValidateCallbackData(longlong *param_1,longlong param_2,ulonglong param_3,uint param_4)

{
  ulonglong uVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  longlong *plVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar4 = 0;
  uVar9 = 0;
  if ((((param_3 == 0) || (param_2 == 0)) || (param_1 == (longlong *)0x0)) || (param_4 == 0)) {
LAB_140023a4c:
    uVar7 = 0xc000000d;
  }
  else {
    uVar7 = param_3;
    while (uVar7 < param_4 + param_3) {
      uVar1 = uVar7 + 0x50;
      if ((param_4 + param_3 < uVar1) || (bVar2 = *(byte *)(uVar7 + 1), bVar2 == 0))
      goto LAB_140023a4c;
      uVar9 = uVar9 + bVar2;
      if (*(byte *)(param_2 + 4) < uVar9) goto LAB_140023a4c;
      for (uVar8 = 0; uVar8 < bVar2; uVar8 = uVar8 + 1) {
        plVar5 = param_1;
        while( true ) {
          if (*plVar5 == 0) goto LAB_140023a4c;
          if (*plVar5 == *(longlong *)(*(longlong *)(uVar7 + 8) + (ulonglong)uVar8 * 8)) break;
          plVar5 = plVar5 + 2;
        }
      }
      if (*(longlong *)(uVar7 + 0x18) != 0) {
        uVar6 = ValidateUnicodeMultiString((ushort *)(uVar7 + 0x10));
        uVar4 = (uint)uVar6;
        if ((int)uVar4 < 0) {
          return uVar6;
        }
      }
      if (*(longlong *)(uVar7 + 0x28) != 0) {
        uVar6 = ValidateUnicodeMultiString((ushort *)(uVar7 + 0x20));
        uVar4 = (uint)uVar6;
        if ((int)uVar4 < 0) {
          return uVar6;
        }
      }
      if (*(longlong *)(uVar7 + 0x38) != 0) {
        uVar3 = *(ushort *)(uVar7 + 0x30);
        if ((((*(ushort *)(uVar7 + 0x32) & 1) != 0) || ((uVar3 & 1) != 0)) ||
           ((uVar3 == 0 ||
            (((ulonglong)*(ushort *)(uVar7 + 0x32) < (ulonglong)uVar3 + 2 ||
             (*(short *)(*(longlong *)(uVar7 + 0x38) + (ulonglong)(uVar3 >> 1) * 2) != 0))))))
        goto LAB_140023a4c;
      }
      uVar7 = uVar1;
    }
    uVar7 = (ulonglong)uVar4;
  }
  return uVar7;
}



===== ValidateUnicodeMultiString @ 140023a74 =====

undefined8 ValidateUnicodeMultiString(ushort *param_1)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = param_1[1];
  if ((uVar1 & 1) == 0) {
    uVar2 = *param_1;
    if (((((uVar2 & 1) == 0) && (uVar1 != 0)) && (uVar2 != 0)) &&
       ((ulonglong)uVar2 + 2 <= (ulonglong)uVar1)) {
      if ((*(short *)(*(longlong *)(param_1 + 4) + (ulonglong)(uVar2 >> 1) * 2) == 0) &&
         (*(short *)(*(longlong *)(param_1 + 4) + (ulonglong)((uVar2 >> 1) - 1) * 2) == 0)) {
        return 0;
      }
    }
  }
  return 0xc000000d;
}



===== BuildIds @ 140023ac4 =====

int BuildIds(longlong param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  wchar_t *pwVar2;
  undefined8 uVar3;
  wchar_t *pwVar4;
  ushort local_res20 [4];
  
  uVar3 = 0x400;
  pwVar2 = (wchar_t *)ExAllocatePool2(0x100,0x400,0x43627355);
  if (pwVar2 == (wchar_t *)0x0) {
    iVar1 = -0x3fffff66;
  }
  else {
    local_res20[0] = 0;
    iVar1 = CdcBuildHardwareIDs(pwVar2,uVar3,(short *)local_res20,param_1,
                                *(undefined8 *)(param_2 + 0x20),*(int *)(param_2 + 0x2c));
    if (-1 < iVar1) {
      pwVar4 = pwVar2;
      uVar3 = DuplicateUnicodeToString((short *)(param_3 + 0x10),pwVar2,local_res20[0]);
      iVar1 = (int)uVar3;
      if (-1 < iVar1) {
        local_res20[0] = 0;
        iVar1 = CdcBuildCompatibleIDs
                          (pwVar2,pwVar4,(short *)local_res20,*(longlong *)(param_2 + 0x20),
                           *(int *)(param_2 + 0x2c));
        if (-1 < iVar1) {
          uVar3 = DuplicateUnicodeToString((short *)(param_3 + 0x20),pwVar2,local_res20[0]);
          iVar1 = (int)uVar3;
          if (-1 < iVar1) {
            RtlInitUnicodeString(param_3 + 0x30,0);
          }
        }
      }
    }
    ExFreePoolWithTag(pwVar2,0);
  }
  return iVar1;
}



===== BuildInterfaceList @ 140023bd0 =====

ulonglong BuildInterfaceList(longlong param_1,longlong *param_2)

{
  byte bVar1;
  short sVar2;
  longlong *plVar3;
  code *pcVar4;
  short sVar5;
  byte *pbVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  uint uVar10;
  uint uVar11;
  
  sVar2 = *(short *)(param_1 + 2);
  uVar10 = 0;
  DestroyInterfaceList(param_2);
  pbVar6 = (byte *)USBD_ParseDescriptors(param_1,sVar2,param_1,4);
  if (pbVar6 != (byte *)0x0) {
    do {
      uVar11 = 0;
      if ((int)uVar10 < 0) goto LAB_140023e05;
      if (pbVar6[3] == 0) {
        puVar7 = (undefined8 *)ExAllocatePool2(0x100,0x30,0x43627355);
        if (puVar7 == (undefined8 *)0x0) {
          uVar10 = 0xc000009a;
        }
        else {
          puVar8 = puVar7 + 2;
          uVar10 = 0;
          puVar7[3] = puVar8;
          *puVar8 = puVar8;
          puVar7[4] = pbVar6;
          *(undefined2 *)(puVar7 + 5) = 0;
          *(undefined4 *)((longlong)puVar7 + 0x2c) = 0;
          plVar3 = (longlong *)param_2[1];
          bVar1 = pbVar6[2];
          if ((longlong *)*plVar3 != param_2) {
            pcVar4 = (code *)swi(0x29);
            (*pcVar4)(3);
            pcVar4 = (code *)swi(3);
            uVar9 = (*pcVar4)();
            return uVar9;
          }
          *puVar7 = param_2;
          puVar7[1] = plVar3;
          *plVar3 = (longlong)puVar7;
          param_2[1] = (longlong)puVar7;
          do {
            pbVar6 = (byte *)USBD_ParseDescriptors(param_1,sVar2,pbVar6 + *pbVar6,4);
            if (pbVar6 == (byte *)0x0) goto LAB_140023d98;
            if (*pbVar6 < 9) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_dd(g_RecorderLog,2,8,0xc,
                                   &WPP_250a8722b9c73d5bc894b816de363468_Traceguids,bVar1,*pbVar6);
              }
              goto LAB_140023df3;
            }
            if (pbVar6[2] != bVar1) break;
            if ((uint)pbVar6[3] == uVar11 + 1) {
              uVar11 = (uint)(byte)((char)uVar11 + 1);
            }
            else {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_dd(g_RecorderLog,2,8,0xb,
                                   &WPP_250a8722b9c73d5bc894b816de363468_Traceguids,pbVar6[2],
                                   pbVar6[3]);
              }
              uVar10 = 0xc000000d;
            }
          } while (-1 < (int)uVar10);
          if (-1 < (int)uVar10) {
LAB_140023d98:
            if (pbVar6 == (byte *)0x0) {
              sVar5 = ((short)param_1 - *(short *)(puVar7 + 4)) + sVar2;
            }
            else {
              sVar5 = (short)pbVar6 - *(short *)(puVar7 + 4);
            }
            *(short *)(puVar7 + 5) = sVar5;
          }
        }
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_dd(g_RecorderLog,2,8,0xd,&WPP_250a8722b9c73d5bc894b816de363468_Traceguids,
                             pbVar6[2],pbVar6[3]);
        }
LAB_140023df3:
        uVar10 = 0xc000000d;
      }
    } while (pbVar6 != (byte *)0x0);
    if ((int)uVar10 < 0) {
LAB_140023e05:
      DestroyInterfaceList(param_2);
    }
  }
  return (ulonglong)uVar10;
}



===== CdcBuildHardwareIDs @ 140023e3c =====

int CdcBuildHardwareIDs(wchar_t *param_1,undefined8 param_2,short *param_3,longlong param_4,
                       undefined8 param_5,int param_6)

{
  char cVar1;
  int iVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  ulonglong uVar5;
  ulonglong local_res8;
  wchar_t *local_38 [2];
  
  local_res8 = 0x400;
  local_38[0] = param_1;
  if (param_6 == 0) {
    iVar2 = -0x3fffff1b;
    local_res8 = 0x400;
  }
  else {
    if (param_6 == 1) {
      pwVar3 = L"USB\\Vid_%04x&Pid_%04x&Rev_%04x&MI_%02x";
LAB_140023f29:
      iVar2 = RtlStringCbPrintfExW
                        (param_1,0x400,(ulonglong *)local_38,(longlong *)&local_res8,0,pwVar3,
                         (char)*(undefined2 *)(param_4 + 8));
    }
    else {
      if (param_6 != 2) {
        if (param_6 == 3) {
          pwVar3 = L"USB\\Vid_%04x&Pid_%04x&Rev_%04x&Cdc_Modem&MI_%02x";
        }
        else {
          if (param_6 != 4) {
            return -0x3fffff1b;
          }
          pwVar3 = L"USB\\Vid_%04x&Pid_%04x&Rev_%04x&WPD_OBEX&MI_%02x";
        }
        goto LAB_140023f29;
      }
      iVar2 = RtlStringCbPrintfExW
                        (param_1,0x400,(ulonglong *)local_38,(longlong *)&local_res8,0,
                         L"USB\\Vid_%04x&Pid_%04x&Rev_%04x&Cdc_%02x&MI_%02x",
                         (char)*(undefined2 *)(param_4 + 8));
    }
  }
  if (iVar2 < 0) {
    return iVar2;
  }
  if (local_res8 < 3) {
    return -0x7ffffffb;
  }
  uVar5 = local_res8 - 2;
  *local_38[0] = L'\0';
  pwVar3 = local_38[0] + 1;
  if (param_6 == 1) {
    pwVar4 = L"USB\\Vid_%04x&Pid_%04x&MI_%02x";
LAB_14002404d:
    cVar1 = (char)*(undefined2 *)(param_4 + 8);
LAB_14002405d:
    local_res8 = uVar5;
    local_38[0] = pwVar3;
    iVar2 = RtlStringCbPrintfExW
                      (pwVar3,uVar5,(ulonglong *)local_38,(longlong *)&local_res8,0,pwVar4,cVar1);
LAB_14002407a:
    if (iVar2 < 0) {
      return iVar2;
    }
  }
  else {
    if (param_6 == 2) {
      local_res8 = uVar5;
      local_38[0] = pwVar3;
      iVar2 = RtlStringCbPrintfExW
                        (pwVar3,uVar5,(ulonglong *)local_38,(longlong *)&local_res8,0,
                         L"USB\\Vid_%04x&Pid_%04x&Rev_%04x&Cdc_%02x",
                         (char)*(undefined2 *)(param_4 + 8));
      goto LAB_14002407a;
    }
    if (param_6 == 3) {
      pwVar4 = L"USB\\Vid_%04x&Pid_%04x&Rev_%04x&Cdc_Modem";
      goto LAB_14002404d;
    }
    if (param_6 == 4) {
      cVar1 = (char)*(undefined2 *)(param_4 + 8);
      pwVar4 = L"USB\\Vid_%04x&Pid_%04x&Rev_%04x&WPD_OBEX";
      goto LAB_14002405d;
    }
  }
  if (local_res8 < 3) {
    return -0x7ffffffb;
  }
  uVar5 = local_res8 - 2;
  *local_38[0] = L'\0';
  pwVar3 = local_38[0] + 1;
  if (param_6 == 2) {
    local_res8 = uVar5;
    local_38[0] = pwVar3;
    iVar2 = RtlStringCbPrintfExW
                      (pwVar3,uVar5,(ulonglong *)local_38,(longlong *)&local_res8,0,
                       L"USB\\Vid_%04x&Pid_%04x&Cdc_%02x&MI_%02x",(char)*(undefined2 *)(param_4 + 8)
                      );
LAB_14002416f:
    if (iVar2 < 0) {
      return iVar2;
    }
  }
  else {
    if (param_6 == 3) {
      cVar1 = (char)*(undefined2 *)(param_4 + 8);
      pwVar4 = L"USB\\Vid_%04x&Pid_%04x&Cdc_Modem&MI_%02x";
LAB_1400240e9:
      local_res8 = uVar5;
      local_38[0] = pwVar3;
      iVar2 = RtlStringCbPrintfExW
                        (pwVar3,uVar5,(ulonglong *)local_38,(longlong *)&local_res8,0,pwVar4,cVar1);
      goto LAB_14002416f;
    }
    if (param_6 == 4) {
      cVar1 = (char)*(undefined2 *)(param_4 + 8);
      pwVar4 = L"USB\\Vid_%04x&Pid_%04x&WPD_OBEX&MI_%02x";
      goto LAB_1400240e9;
    }
  }
  if (local_res8 < 3) {
    return -0x7ffffffb;
  }
  uVar5 = local_res8 - 2;
  *local_38[0] = L'\0';
  pwVar3 = local_38[0] + 1;
  if (param_6 == 2) {
    local_res8 = uVar5;
    local_38[0] = pwVar3;
    iVar2 = RtlStringCbPrintfExW
                      (pwVar3,uVar5,(ulonglong *)local_38,(longlong *)&local_res8,0,
                       L"USB\\Vid_%04x&Pid_%04x&Cdc_%02x",(char)*(undefined2 *)(param_4 + 8));
  }
  else {
    if (param_6 == 3) {
      cVar1 = (char)*(undefined2 *)(param_4 + 8);
      pwVar4 = L"USB\\Vid_%04x&Pid_%04x&Cdc_Modem";
    }
    else {
      if (param_6 != 4) goto LAB_140024254;
      cVar1 = (char)*(undefined2 *)(param_4 + 8);
      pwVar4 = L"USB\\Vid_%04x&Pid_%04x&WPD_OBEX";
    }
    local_res8 = uVar5;
    local_38[0] = pwVar3;
    iVar2 = RtlStringCbPrintfExW
                      (pwVar3,uVar5,(ulonglong *)local_38,(longlong *)&local_res8,0,pwVar4,cVar1);
  }
  if (iVar2 < 0) {
    return iVar2;
  }
LAB_140024254:
  if (local_res8 < 5) {
    return -0x7ffffffb;
  }
  local_38[0][0] = L'\0';
  local_38[0][1] = L'\0';
  *param_3 = 0x400 - ((short)local_res8 + -4);
  return iVar2;
}



===== CdcCallback @ 1400242a0 =====

int CdcCallback(longlong param_1,longlong param_2,undefined8 *param_3,int *param_4,
               undefined8 param_5,undefined8 param_6)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  ulonglong uVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte local_38 [4];
  uint local_34;
  longlong *****local_30;
  longlong *****local_28;
  
  local_34 = 0;
  iVar3 = GetCdcFlags(param_6,&local_34);
  if (iVar3 < 0) {
    return iVar3;
  }
  local_28 = (longlong *****)&local_30;
  local_30 = (longlong *****)&local_30;
  uVar4 = BuildInterfaceList(param_2,(longlong *)&local_30);
  if ((int)uVar4 < 0) {
    return (int)uVar4;
  }
  uVar4 = GroupInterfacesByFunction((longlong ****)&local_30,(ulonglong)local_34);
  iVar3 = (int)uVar4;
  if (-1 < iVar3) {
    bVar1 = CountNonLeafNodes(&local_30);
    if (bVar1 == 0) {
      *param_3 = 0;
      *param_4 = 0;
    }
    else {
      pbVar5 = (byte *)ExAllocatePool2(0x40,(ulonglong)bVar1 * 0x50,0x43627355);
      if (pbVar5 == (byte *)0x0) {
        iVar3 = -0x3fffff66;
      }
      else {
        bVar2 = 0;
        pbVar6 = pbVar5;
        if (bVar1 != 0) {
          do {
            *pbVar6 = bVar2;
            bVar2 = bVar2 + 1;
            pbVar6 = pbVar6 + 0x50;
          } while (bVar2 < bVar1);
        }
        local_38[0] = 0;
        iVar3 = PopulateFunctionDescriptorArray(param_1,&local_30,bVar1,pbVar5,local_38);
        uVar4 = (ulonglong)local_38[0];
        if (-1 < iVar3) {
          if (local_38[0] == bVar1) {
            *param_3 = pbVar5;
            *param_4 = (uint)bVar1 * 0x50;
            goto LAB_1400243f7;
          }
          iVar3 = -0x3fffff1b;
        }
        if (local_38[0] != 0) {
          pbVar6 = pbVar5;
          do {
            DestroyFunctionDescriptorElement(pbVar6);
            pbVar6 = pbVar6 + 0x50;
            uVar4 = uVar4 - 1;
          } while (uVar4 != 0);
        }
        ExFreePoolWithTag(pbVar5,0);
      }
    }
  }
LAB_1400243f7:
  DestroyInterfaceList((longlong *)&local_30);
  return iVar3;
}



===== CheckForWmCdcModemFunction @ 140024428 =====

undefined8 CheckForWmCdcModemFunction(longlong param_1,undefined1 *param_2)

{
  longlong lVar1;
  char cVar2;
  byte *pbVar3;
  byte *pbVar4;
  longlong *plVar5;
  undefined8 uVar6;
  char cVar7;
  byte bVar8;
  
  lVar1 = *(longlong *)(param_1 + 0x20);
  uVar6 = 0;
  *param_2 = 0;
  if ((*(char *)(lVar1 + 6) == '\x02') && (*(char *)(lVar1 + 4) == '\x01')) {
    pbVar3 = (byte *)USBD_ParseDescriptors(lVar1,*(undefined2 *)(param_1 + 0x28),lVar1,5);
    if ((pbVar3 == (byte *)0x0) || (*pbVar3 < 7)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(g_RecorderLog,2,8,0x11,&WPP_250a8722b9c73d5bc894b816de363468_Traceguids,
                          *(undefined1 *)(lVar1 + 2));
      }
      uVar6 = 0xc000000d;
    }
    else if (((pbVar3[3] & 3) == 3) && ((char)pbVar3[2] < '\0')) {
      plVar5 = (longlong *)(param_1 + 0x10);
      cVar2 = CountListEntries(plVar5);
      if (cVar2 == '\x01') {
        lVar1 = *plVar5;
        pbVar3 = *(byte **)(lVar1 + 0x20);
        if ((pbVar3[5] == 10) && (pbVar3[4] == 2)) {
          cVar2 = '\0';
          cVar7 = '\0';
          pbVar4 = pbVar3;
          for (bVar8 = 0; uVar6 = 0, bVar8 < pbVar3[4]; bVar8 = bVar8 + 1) {
            pbVar4 = (byte *)USBD_ParseDescriptors(pbVar3,*(undefined2 *)(lVar1 + 0x28),pbVar4,5);
            if ((pbVar4 == (byte *)0x0) || (*pbVar4 < 7)) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_d(g_RecorderLog,2,8,0x10,
                                  &WPP_250a8722b9c73d5bc894b816de363468_Traceguids,pbVar3[2]);
              }
              uVar6 = 0xc000000d;
              break;
            }
            if ((pbVar4[3] & 3) == 2) {
              if ((char)pbVar4[2] < '\0') {
                cVar2 = cVar2 + '\x01';
              }
              else {
                cVar7 = cVar7 + '\x01';
              }
            }
            pbVar4 = pbVar4 + *pbVar4;
          }
          if ((cVar2 == '\x01') && (cVar7 == '\x01')) {
            *param_2 = 1;
          }
        }
      }
    }
  }
  return uVar6;
}



===== CountListEntries @ 1400245f4 =====

char CountListEntries(undefined8 *param_1)

{
  char cVar1;
  undefined8 *puVar2;
  
  cVar1 = '\0';
  for (puVar2 = (undefined8 *)*param_1; puVar2 != param_1; puVar2 = (undefined8 *)*puVar2) {
    cVar1 = cVar1 + '\x01';
  }
  return cVar1;
}



===== CountNonLeafNodes @ 140024610 =====

char CountNonLeafNodes(undefined8 *param_1)

{
  undefined8 *puVar1;
  char cVar2;
  char cVar3;
  
  cVar3 = '\0';
  for (puVar1 = (undefined8 *)*param_1; puVar1 != param_1; puVar1 = (undefined8 *)*puVar1) {
    if ((*(char *)(puVar1[4] + 5) == '\x02') && (*(char *)(puVar1[4] + 6) == '\b')) {
      cVar2 = cVar3 + '\x01';
      if (*(int *)((longlong)puVar1 + 0x2c) == 0) {
        cVar2 = cVar3;
      }
      cVar3 = CountNonLeafNodes(puVar1 + 2);
      cVar3 = cVar2 + cVar3;
    }
    else {
      cVar3 = cVar3 + '\x01';
    }
  }
  return cVar3;
}



===== DestroyFunctionDescriptorElement @ 140024680 =====

void DestroyFunctionDescriptorElement(void *param_1)

{
  if (*(longlong *)((longlong)param_1 + 8) != 0) {
    ExFreePoolWithTag();
  }
  if (*(longlong *)((longlong)param_1 + 0x18) != 0) {
    ExFreePoolWithTag();
  }
  if (*(longlong *)((longlong)param_1 + 0x28) != 0) {
    ExFreePoolWithTag();
  }
  if (*(longlong *)((longlong)param_1 + 0x38) != 0) {
    ExFreePoolWithTag();
  }
  memset(param_1,0,0x50);
  return;
}



===== DestroyInterfaceList @ 140024700 =====

void DestroyInterfaceList(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  
  while( true ) {
    plVar1 = (longlong *)*param_1;
    if (plVar1 == param_1) {
      return;
    }
    if (((longlong *)plVar1[1] != param_1) || (lVar2 = *plVar1, *(longlong **)(lVar2 + 8) != plVar1)
       ) break;
    *param_1 = lVar2;
    *(longlong **)(lVar2 + 8) = param_1;
    DestroyInterfaceList(plVar1 + 2);
    ExFreePoolWithTag(plVar1,0);
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  return;
}



===== DuplicateUnicodeToString @ 140024760 =====

undefined8 DuplicateUnicodeToString(short *param_1,void *param_2,ushort param_3)

{
  void *_Dst;
  undefined8 uVar1;
  
  uVar1 = 0;
  if (*(longlong *)(param_1 + 4) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 4),0);
    RtlInitUnicodeString(param_1,0);
  }
  _Dst = (void *)ExAllocatePool2(0x40,(ulonglong)param_3,0x43627355);
  *(void **)(param_1 + 4) = _Dst;
  if (_Dst == (void *)0x0) {
    uVar1 = 0xc000009a;
  }
  else {
    memmove(_Dst,param_2,(ulonglong)param_3);
    param_1[1] = param_3;
    *param_1 = param_3 - 2;
  }
  return uVar1;
}



===== FindInterfaceByClass @ 140024814 =====

undefined8 * FindInterfaceByClass(undefined8 *param_1,undefined8 param_2,char param_3)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)*param_1;
  while( true ) {
    if (puVar1 == param_1) {
      return (undefined8 *)0x0;
    }
    if ((*(char *)(puVar1[4] + 5) == '\x02') && (*(char *)(puVar1[4] + 6) == param_3)) break;
    puVar1 = (undefined8 *)*puVar1;
  }
  return puVar1;
}



===== GetCdcFlags @ 140024844 =====

int GetCdcFlags(undefined8 param_1,undefined4 *param_2)

{
  int iVar1;
  longlong lVar2;
  int local_res10 [2];
  undefined8 local_res18 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  
  *param_2 = 0;
  local_res18[0] = 0;
  iVar1 = IoOpenDeviceRegistryKey(param_1,2,0xf003f,local_res18);
  if (-1 < iVar1) {
    local_res10[0] = 0;
    local_28 = 0;
    uStack_20 = 0;
    RtlInitUnicodeString(&local_28,L"CdcFlags");
    iVar1 = ZwQueryValueKey(local_res18[0],&local_28,2,0,0,local_res10);
    if ((iVar1 == -0x3fffffcc) || (local_res10[0] == 0)) {
      iVar1 = 0;
    }
    else {
      lVar2 = ExAllocatePool2(0x100,local_res10[0],0x43627355);
      if (lVar2 != 0) {
        iVar1 = ZwQueryValueKey(local_res18[0],&local_28,2,lVar2,local_res10[0],local_res10);
        if ((-1 < iVar1) && (*(int *)(lVar2 + 8) == 4)) {
          *param_2 = *(undefined4 *)(lVar2 + 0xc);
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_SD();
          }
        }
        ExFreePoolWithTag(lVar2,0);
      }
    }
    ZwClose(local_res18[0]);
  }
  return iVar1;
}



===== GroupInterfacesByFunction @ 14002499c =====

ulonglong GroupInterfacesByFunction(longlong ****param_1,ulonglong param_2)

{
  longlong ****pppplVar1;
  longlong ****pppplVar2;
  longlong *****ppppplVar3;
  code *pcVar4;
  longlong *****ppppplVar5;
  longlong *****ppppplVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong *****local_18;
  longlong *****local_10;
  
  local_10 = (longlong *****)&local_18;
  local_18 = (longlong *****)&local_18;
  uVar9 = 0;
  uVar7 = param_2;
  do {
    ppppplVar6 = (longlong *****)FindInterfaceByClass(param_1,uVar7,'\b');
    if (ppppplVar6 == (longlong *****)0x0) goto LAB_140024a4b;
    pppplVar1 = *ppppplVar6;
    ppppplVar5 = local_18;
    if (((longlong *****)pppplVar1[1] != ppppplVar6) ||
       (pppplVar2 = ppppplVar6[1], (longlong *****)*pppplVar2 != ppppplVar6)) goto LAB_140024ae3;
    *pppplVar2 = (longlong ***)pppplVar1;
    pppplVar1[1] = (longlong ***)pppplVar2;
    if ((longlong ******)*local_10 != &local_18) goto LAB_140024ae3;
    ppppplVar6[1] = (longlong ****)local_10;
    *ppppplVar6 = (longlong ****)&local_18;
    *local_10 = (longlong ****)ppppplVar6;
    local_10 = ppppplVar6;
    uVar7 = GroupSubordinateInterfaces((longlong *)param_1,(longlong)ppppplVar6,(uint)param_2);
    uVar9 = uVar7 & 0xffffffff;
    if ((int)uVar7 < 0) break;
    uVar7 = param_2 & 0xffffffff;
    uVar8 = GroupInterfacesByFunction((longlong ****)(ppppplVar6 + 2),param_2 & 0xffffffff);
    uVar9 = uVar8 & 0xffffffff;
  } while (-1 < (int)uVar8);
  goto LAB_140024a9e;
  while( true ) {
    ppppplVar5 = local_18;
    if ((ppppplVar6[1] != param_1) ||
       (pppplVar1 = *ppppplVar6, (longlong *****)pppplVar1[1] != ppppplVar6)) goto LAB_140024ae3;
    *param_1 = (longlong ***)pppplVar1;
    pppplVar1[1] = (longlong ***)param_1;
    if ((longlong ******)*local_10 != &local_18) goto LAB_140024ae3;
    ppppplVar6[1] = (longlong ****)local_10;
    *ppppplVar6 = (longlong ****)&local_18;
    *local_10 = (longlong ****)ppppplVar6;
    local_10 = ppppplVar6;
    uVar7 = GroupSubordinateInterfaces((longlong *)param_1,(longlong)ppppplVar6,(uint)param_2);
    uVar9 = uVar7 & 0xffffffff;
    if ((int)uVar7 < 0) break;
LAB_140024a4b:
    ppppplVar6 = (longlong *****)*param_1;
    if (ppppplVar6 == (longlong *****)param_1) break;
  }
LAB_140024a9e:
  do {
    ppppplVar6 = local_18;
    if ((longlong ******)local_18 == &local_18) goto LAB_140024aea;
    ppppplVar5 = local_18;
    if (((longlong ******)local_18[1] != &local_18) ||
       (ppppplVar3 = (longlong *****)*local_18, (longlong *****)ppppplVar3[1] != local_18)) break;
    ppppplVar3[1] = (longlong ****)&local_18;
    pppplVar1 = (longlong ****)param_1[1];
    ppppplVar5 = ppppplVar3;
    if ((longlong ****)*pppplVar1 != param_1) break;
    *local_18 = param_1;
    local_18 = ppppplVar3;
    ppppplVar6[1] = pppplVar1;
    *pppplVar1 = (longlong ***)ppppplVar6;
    param_1[1] = (longlong ***)ppppplVar6;
  } while( true );
LAB_140024ae3:
  local_18 = ppppplVar5;
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
LAB_140024aea:
  return uVar9 & 0xffffffff;
}



===== GroupSubordinateInterfaces @ 140024b0c =====

ulonglong GroupSubordinateInterfaces(longlong *param_1,longlong param_2,uint param_3)

{
  char cVar1;
  char cVar2;
  undefined2 uVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  code *pcVar8;
  ulonglong uVar9;
  longlong *plVar10;
  ulonglong uVar11;
  longlong lVar12;
  byte bVar13;
  char local_res10 [8];
  
  lVar4 = *(longlong *)(param_2 + 0x20);
  uVar11 = 0;
  cVar1 = *(char *)(lVar4 + 5);
  cVar2 = *(char *)(lVar4 + 6);
  if (cVar1 != '\x01') {
    if (cVar1 == '\x02') {
      if ((cVar2 == '\v') && ((param_3 & 1) != 0)) {
        uVar3 = *(undefined2 *)(param_2 + 0x28);
        while( true ) {
          lVar12 = param_2;
          uVar9 = GroupSubordinateInterfacesByUFD(param_1,param_2);
          uVar11 = uVar9 & 0xffffffff;
          if ((int)uVar9 < 0) break;
          plVar10 = FindInterfaceByClass(param_1,lVar12,'\v');
          if (plVar10 == (longlong *)0x0) break;
          lVar12 = *plVar10;
          if ((*(longlong **)(lVar12 + 8) != plVar10) ||
             (plVar5 = (longlong *)plVar10[1], (longlong *)*plVar5 != plVar10)) goto LAB_140024d50;
          *plVar5 = lVar12;
          *(longlong **)(lVar12 + 8) = plVar5;
          plVar5 = *(longlong **)(param_2 + 0x18);
          if (*plVar5 != param_2 + 0x10) goto LAB_140024d50;
          *plVar10 = param_2 + 0x10;
          plVar10[1] = (longlong)plVar5;
          *plVar5 = (longlong)plVar10;
          *(longlong **)(param_2 + 0x18) = plVar10;
          *(longlong *)(param_2 + 0x20) = plVar10[4];
          *(short *)(param_2 + 0x28) = (short)plVar10[5];
        }
        *(longlong *)(param_2 + 0x20) = lVar4;
        *(undefined2 *)(param_2 + 0x28) = uVar3;
        if (-1 < (int)uVar11) {
          *(undefined4 *)(param_2 + 0x2c) = 4;
        }
      }
      else {
        uVar9 = GroupSubordinateInterfacesByUFD(param_1,param_2);
        uVar11 = uVar9 & 0xffffffff;
        if (-1 < (int)uVar9) {
          if (cVar2 == '\x02') {
            local_res10[0] = '\0';
            uVar9 = CheckForWmCdcModemFunction(param_2,local_res10);
            uVar11 = uVar9 & 0xffffffff;
            if (-1 < (int)uVar9) {
              *(uint *)(param_2 + 0x2c) = (local_res10[0] != '\0') + 2;
            }
          }
          else if (cVar2 == '\b') {
            *(uint *)(param_2 + 0x2c) = param_3 & 2;
          }
          else {
            *(undefined4 *)(param_2 + 0x2c) = 2;
          }
        }
      }
      goto LAB_140024b5e;
    }
    if (cVar1 != '\x0e') {
LAB_140024b57:
      *(undefined4 *)(param_2 + 0x2c) = 1;
      goto LAB_140024b5e;
    }
  }
  bVar13 = *(byte *)(lVar4 + 2);
  plVar10 = (longlong *)*param_1;
  while (-1 < (int)uVar11) {
    if (plVar10 == param_1) goto LAB_140024b57;
    plVar5 = (longlong *)*plVar10;
    lVar4 = plVar10[4];
    if ((*(char *)(lVar4 + 5) != cVar1) || (*(char *)(lVar4 + 6) == cVar2)) goto LAB_140024b57;
    if ((uint)*(byte *)(lVar4 + 2) == bVar13 + 1) {
      if (((longlong *)plVar5[1] != plVar10) ||
         (puVar6 = (undefined8 *)plVar10[1], (longlong *)*puVar6 != plVar10)) {
LAB_140024d50:
        pcVar8 = (code *)swi(0x29);
        (*pcVar8)(3);
        pcVar8 = (code *)swi(3);
        uVar11 = (*pcVar8)();
        return uVar11;
      }
      *puVar6 = plVar5;
      plVar5[1] = (longlong)puVar6;
      plVar7 = *(longlong **)(param_2 + 0x18);
      if (*plVar7 != param_2 + 0x10) goto LAB_140024d50;
      *plVar10 = param_2 + 0x10;
      bVar13 = bVar13 + 1;
      plVar10[1] = (longlong)plVar7;
      *plVar7 = (longlong)plVar10;
      *(longlong **)(param_2 + 0x18) = plVar10;
      plVar10 = plVar5;
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(g_RecorderLog,2,8,0x12,&WPP_250a8722b9c73d5bc894b816de363468_Traceguids,
                          bVar13);
      }
      uVar11 = 0xc000000d;
      plVar10 = plVar5;
    }
  }
LAB_140024b5e:
  return uVar11 & 0xffffffff;
}



===== GroupSubordinateInterfacesByUFD @ 140024d60 =====

undefined8 GroupSubordinateInterfacesByUFD(longlong *param_1,longlong param_2)

{
  byte bVar1;
  ushort uVar2;
  byte *pbVar3;
  longlong lVar4;
  code *pcVar5;
  byte *pbVar6;
  undefined8 uVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  longlong *plVar10;
  longlong *plVar11;
  undefined1 auStackY_58 [8];
  undefined1 auStackY_50 [24];
  
  puVar8 = auStackY_58;
  pbVar3 = *(byte **)(param_2 + 0x20);
  uVar2 = *(ushort *)(param_2 + 0x28);
  pbVar9 = pbVar3;
  do {
    pbVar6 = (byte *)USBD_ParseDescriptors(pbVar3,(ulonglong)uVar2,pbVar9,0x24);
    if (pbVar6 == (byte *)0x0) break;
    if ((*pbVar6 < 3) || (pbVar9 = pbVar6 + *pbVar6, pbVar3 + uVar2 < pbVar9)) goto LAB_140024f0f;
  } while (pbVar6[2] != 6);
  uVar7 = 0;
  if (pbVar6 != (byte *)0x0) {
    bVar1 = *pbVar6;
    if (bVar1 < 4) {
LAB_140024ecf:
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        *(uint *)(puVar8 + 0x28) = (uint)*(byte *)(*(longlong *)(param_2 + 0x20) + 2);
        *(undefined **)(puVar8 + 0x20) = &WPP_250a8722b9c73d5bc894b816de363468_Traceguids;
        *(undefined8 *)(puVar8 + -8) = 0x140024f0f;
        WPP_RECORDER_SF_d(g_RecorderLog,2,8,0xf,*(undefined8 *)(puVar8 + 0x20),puVar8[0x28]);
      }
LAB_140024f0f:
      uVar7 = 0xc000000d;
    }
    else {
      uVar7 = 0;
      if ((ulonglong)bVar1 != 4) {
        pbVar9 = pbVar6 + 4;
        do {
          for (plVar11 = (longlong *)*param_1; plVar10 = (longlong *)0x0, plVar11 != param_1;
              plVar11 = (longlong *)*plVar11) {
            if (*(byte *)(plVar11[4] + 2) == *pbVar9) {
              plVar10 = plVar11;
              break;
            }
          }
          if (plVar10 == (longlong *)0x0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_dd(g_RecorderLog,2,8,0xe,
                                 &WPP_250a8722b9c73d5bc894b816de363468_Traceguids,
                                 *(undefined1 *)(*(longlong *)(param_2 + 0x20) + 2),*pbVar9);
            }
            uVar7 = 0xc000000d;
          }
          else if ((*(char *)(plVar10[4] + 5) - 2U & 0xf7) == 0) {
            lVar4 = *plVar10;
            if ((*(longlong **)(lVar4 + 8) == plVar10) &&
               (plVar11 = (longlong *)plVar10[1], (longlong *)*plVar11 == plVar10)) {
              *plVar11 = lVar4;
              *(longlong **)(lVar4 + 8) = plVar11;
              plVar11 = *(longlong **)(param_2 + 0x18);
              if (*plVar11 == param_2 + 0x10) {
                *plVar10 = param_2 + 0x10;
                plVar10[1] = (longlong)plVar11;
                *plVar11 = (longlong)plVar10;
                *(longlong **)(param_2 + 0x18) = plVar10;
                goto LAB_140024eb4;
              }
            }
            pcVar5 = (code *)swi(0x29);
            (*pcVar5)(3);
            puVar8 = auStackY_50;
            goto LAB_140024ecf;
          }
LAB_140024eb4:
          pbVar9 = pbVar9 + 1;
        } while ((ulonglong)((longlong)pbVar9 - (longlong)(pbVar6 + 4)) < (ulonglong)bVar1 - 4);
      }
    }
  }
  return uVar7;
}



===== PopulateFunctionDescriptorArray @ 140024f3c =====

int PopulateFunctionDescriptorArray
              (longlong param_1,undefined8 *param_2,byte param_3,void *param_4,byte *param_5)

{
  int iVar1;
  undefined8 *puVar2;
  byte bVar3;
  undefined8 *puVar4;
  byte local_res10 [8];
  
  puVar4 = (undefined8 *)*param_2;
  iVar1 = 0;
  bVar3 = 0;
LAB_140024f65:
  do {
    if (puVar4 == param_2) goto LAB_140025079;
    if (param_3 <= bVar3) goto LAB_140025070;
    if ((*(char *)(puVar4[4] + 5) == '\x02') && (*(char *)(puVar4[4] + 6) == '\b')) {
      if (*(int *)((longlong)puVar4 + 0x2c) == 0) {
        if (iVar1 < 0) goto LAB_140025065;
      }
      else {
        *(undefined4 *)((longlong)param_4 + 0x40) = 0;
        *(undefined1 *)((longlong)param_4 + 1) = 1;
        puVar2 = (undefined8 *)ExAllocatePool2(0x40,8,0x43627355);
        *(undefined8 **)((longlong)param_4 + 8) = puVar2;
        if (puVar2 == (undefined8 *)0x0) {
          iVar1 = -0x3fffff66;
LAB_140024fe6:
          DestroyFunctionDescriptorElement(param_4);
        }
        else {
          *puVar2 = puVar4[4];
          iVar1 = BuildIds(param_1,(longlong)puVar4,(longlong)param_4);
          if (iVar1 < 0) goto LAB_140024fe6;
        }
        if (iVar1 < 0) goto LAB_140025065;
        param_4 = (void *)((longlong)param_4 + 0x50);
        bVar3 = bVar3 + 1;
      }
      if (bVar3 < param_3) {
        local_res10[0] = 0;
        iVar1 = PopulateFunctionDescriptorArray
                          (param_1,puVar4 + 2,param_3 - bVar3,param_4,local_res10);
        if (-1 < iVar1) {
          param_4 = (void *)((longlong)param_4 + (ulonglong)local_res10[0] * 0x50);
          bVar3 = bVar3 + local_res10[0];
          goto LAB_14002505d;
        }
      }
    }
    else {
      iVar1 = PopulateFunctionDescriptorElement(param_1,(longlong)puVar4,param_4);
      if (-1 < iVar1) {
        param_4 = (void *)((longlong)param_4 + 0x50);
        bVar3 = bVar3 + 1;
LAB_14002505d:
        puVar4 = (undefined8 *)*puVar4;
        goto LAB_140024f65;
      }
    }
LAB_140025065:
    puVar4 = (undefined8 *)*puVar4;
    if (iVar1 < 0) {
LAB_140025070:
      if (-1 < iVar1) {
        if (puVar4 == param_2) {
LAB_140025079:
          if (bVar3 <= param_3) {
            *param_5 = bVar3;
            return iVar1;
          }
        }
        iVar1 = -0x3fffff1b;
      }
      for (; bVar3 != 0; bVar3 = bVar3 - 1) {
        param_4 = (void *)((longlong)param_4 + -0x50);
        DestroyFunctionDescriptorElement(param_4);
      }
      return iVar1;
    }
  } while( true );
}



===== PopulateFunctionDescriptorElement @ 1400250c4 =====

int PopulateFunctionDescriptorElement(longlong param_1,longlong param_2,void *param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  char cVar3;
  int iVar4;
  undefined8 *puVar5;
  void *pvVar6;
  
  puVar1 = (undefined8 *)(param_2 + 0x10);
  pvVar6 = param_3;
  cVar3 = CountListEntries(puVar1);
  *(undefined4 *)((longlong)pvVar6 + 0x40) = 0;
  *(byte *)((longlong)pvVar6 + 1) = cVar3 + 1U;
  puVar5 = (undefined8 *)ExAllocatePool2(0x40,(ulonglong)(byte)(cVar3 + 1U) << 3,0x43627355);
  *(undefined8 **)((longlong)param_3 + 8) = puVar5;
  if (puVar5 == (undefined8 *)0x0) {
    iVar4 = -0x3fffff66;
  }
  else {
    puVar2 = (undefined8 *)*puVar1;
    *puVar5 = *(undefined8 *)(param_2 + 0x20);
    for (; cVar3 != '\0'; cVar3 = cVar3 + -1) {
      puVar5 = puVar5 + 1;
      if (puVar2 == puVar1) goto LAB_140025167;
      *puVar5 = puVar2[4];
      puVar2 = (undefined8 *)*puVar2;
    }
    if (puVar2 == puVar1) {
      iVar4 = BuildIds(param_1,param_2,(longlong)param_3);
    }
    else {
LAB_140025167:
      iVar4 = -0x3fffff1b;
    }
    if (-1 < iVar4) {
      return iVar4;
    }
  }
  DestroyFunctionDescriptorElement(param_3);
  return iVar4;
}



===== SleepstudyHelperInitializeOnce @ 1400251a0 =====

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



===== SleepstudyHelper_Uninitialize @ 140025238 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SleepstudyHelper_Uninitialize(void)

{
  undefined *puVar1;
  ulonglong uVar2;
  
  puVar1 = g_SleepstudyLibraryHandle;
  uVar2 = Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar2 != 0) ||
     ((puVar1 != &SleepstudyHelperUnsupportedHandle && (DAT_14001c4d8 != (code *)0x0)))) {
    (*DAT_14001c4d8)(puVar1);
  }
  return;
}



===== GetMsOsFeatureDescriptor @ 140025280 =====

int GetMsOsFeatureDescriptor
              (longlong param_1,byte param_2,undefined1 param_3,undefined2 param_4,
              undefined8 param_5,undefined4 param_6,undefined4 *param_7)

{
  int iVar1;
  undefined2 *local_res8;
  
  local_res8 = (undefined2 *)0x0;
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = 0;
  }
  iVar1 = USBD_UrbAllocate(*(longlong *)(param_1 + 0x548),&local_res8);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0x13,
                        &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids,(char)iVar1);
    }
  }
  else {
    memset(local_res8,0,0x88);
    local_res8[1] = 0x2a;
    *local_res8 = 0x88;
    *(undefined4 *)(local_res8 + 0x12) = param_6;
    *(undefined8 *)(local_res8 + 0x14) = param_5;
    *(byte *)(local_res8 + 0x40) =
         (*(byte *)(local_res8 + 0x40) ^ param_2) & 0x1f ^ *(byte *)(local_res8 + 0x40);
    *(undefined1 *)(local_res8 + 0x41) = param_3;
    local_res8[0x42] = param_4;
    iVar1 = SubmitUrb(param_1,local_res8);
    if ((-1 < iVar1) && (param_7 != (undefined4 *)0x0)) {
      *param_7 = *(undefined4 *)(local_res8 + 0x12);
    }
    USBD_UrbFree(*(longlong *)(param_1 + 0x548),(longlong)local_res8);
  }
  return iVar1;
}



===== GetFunctionInterfaceListBase @ 1400253d4 =====

longlong * GetFunctionInterfaceListBase(longlong param_1,int param_2,int *param_3)

{
  byte bVar1;
  char cVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  int iVar7;
  ulonglong uVar8;
  uint uVar9;
  ulonglong uVar10;
  longlong *plVar11;
  
  uVar8 = 0xffffffff;
  iVar7 = 0;
  uVar10 = 0;
  uVar9 = 0;
  bVar1 = *(byte *)(*(longlong *)(param_1 + 0x38) + 4);
  if (bVar1 != 1) {
    lVar3 = *(longlong *)(param_1 + 0x58);
    do {
      uVar9 = (uint)uVar10;
      lVar4 = *(longlong *)(lVar3 + uVar10 * 0x10);
      cVar2 = *(char *)(lVar4 + 5);
      if ((cVar2 != '\r') &&
         (((*(char *)(param_1 + 0x55c) == '\0' || (cVar2 != '\x01')) ||
          (*(char *)(lVar4 + 7) != '\0')))) {
        if (iVar7 == param_2) goto LAB_140025484;
        if (cVar2 == '\x01') {
          uVar6 = uVar9;
          if ((uint)uVar8 != 0xffffffff) {
            uVar6 = (uint)uVar8;
          }
          uVar8 = (ulonglong)uVar6;
          lVar4 = *(longlong *)(lVar3 + (ulonglong)(uVar9 + 1) * 0x10);
          if ((*(char *)(lVar4 + 5) != '\x01') ||
             (*(char *)(*(longlong *)(lVar3 + uVar8 * 0x10) + 6) == *(char *)(lVar4 + 6))) {
            iVar7 = iVar7 + 1;
            uVar8 = 0xffffffff;
          }
        }
        else {
          uVar8 = 0xffffffff;
          if (*(char *)(*(longlong *)(lVar3 + (ulonglong)(uVar9 + 1) * 0x10) + 3) == '\0') {
            iVar7 = iVar7 + 1;
          }
        }
      }
      uVar9 = uVar9 + 1;
      uVar10 = (ulonglong)uVar9;
    } while (uVar9 < bVar1 - 1);
  }
  if (iVar7 != param_2) {
    *param_3 = 0;
    return (longlong *)0x0;
  }
LAB_140025484:
  lVar3 = *(longlong *)(param_1 + 0x58);
  plVar11 = (longlong *)((ulonglong)uVar9 * 0x10 + lVar3);
  *param_3 = 1;
  lVar4 = *plVar11;
  if (*(char *)(lVar4 + 5) != '\r') {
    if (*(char *)(lVar4 + 5) != '\x01') {
      return plVar11;
    }
    if ((*(char *)(param_1 + 0x55c) == '\0') || (*(char *)(lVar4 + 7) != '\0')) {
      uVar9 = uVar9 + 1;
      if (bVar1 <= uVar9) {
        return plVar11;
      }
      iVar7 = 1;
      while( true ) {
        lVar5 = *(longlong *)(lVar3 + (ulonglong)uVar9 * 0x10);
        if (*(char *)(lVar5 + 5) != '\x01') {
          return plVar11;
        }
        if (*(char *)(lVar5 + 6) == *(char *)(lVar4 + 6)) break;
        iVar7 = iVar7 + 1;
        uVar9 = uVar9 + 1;
        *param_3 = iVar7;
        if (bVar1 <= uVar9) {
          return plVar11;
        }
      }
      return plVar11;
    }
  }
  return (longlong *)0x0;
}



===== CreateStaticFunctionPDOs @ 14002555c =====

uint CreateStaticFunctionPDOs(longlong param_1)

{
  undefined4 *puVar1;
  byte bVar2;
  char cVar3;
  longlong lVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  byte bVar9;
  undefined1 uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  longlong lVar14;
  longlong lVar15;
  ulonglong uVar16;
  longlong lVar17;
  uint uVar18;
  undefined4 *puVar19;
  undefined2 uVar20;
  uint uVar21;
  ulonglong uVar22;
  uint local_res8;
  code *local_res10;
  undefined8 uVar23;
  undefined4 uVar24;
  code *in_stack_ffffffffffffffc0;
  undefined8 uVar25;
  undefined4 uVar26;
  
  lVar14 = *(longlong *)(param_1 + 0x38);
  local_res8 = 0;
  uVar11 = 0;
  uVar13 = 0;
  uVar18 = 0;
  bVar9 = 0;
  if (*(char *)(lVar14 + 4) != '\0') {
    do {
      lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x58) + (ulonglong)uVar18 * 0x10);
      if (*(char *)(lVar4 + 5) == '\r') {
        bVar9 = *(byte *)(lVar4 + 2);
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          in_stack_ffffffffffffffc0 =
               (code *)CONCAT44((int)((ulonglong)in_stack_ffffffffffffffc0 >> 0x20),(uint)bVar9);
          WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),4,1,10,
                            &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,bVar9);
        }
        InitCSInfo(param_1,(uint)bVar9);
      }
      bVar9 = *(byte *)(lVar14 + 4);
      uVar18 = uVar18 + 1;
    } while (uVar18 < bVar9);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    in_stack_ffffffffffffffc0 = (code *)((ulonglong)in_stack_ffffffffffffffc0 & 0xffffffff00000000);
    WPP_RECORDER_SF_dd(*(undefined8 *)(param_1 + 0x560),4,1,0xb,
                       &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,bVar9,
                       (char)*(undefined4 *)(param_1 + 0x74));
  }
  uVar18 = InvokePdoEnableCallbacks(param_1);
  *(uint *)(param_1 + 0x78) = uVar18;
  lVar14 = ExAllocatePool2(0x40,(ulonglong)uVar18 * 8 + 0x10);
  *(longlong *)(param_1 + 0x80) = lVar14;
  if (lVar14 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0xc,
                        &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,0);
    }
    uVar11 = 0xc000009a;
    RecordStartFailData(param_1,0xc000009a,0,0xa0000005,0x43534631,(void *)0x0,0);
    *(undefined8 *)(param_1 + 0x80) = 0;
  }
  else {
    uVar22 = 0;
    uVar18 = 0;
    if (*(int *)(param_1 + 0x74) != 0) {
      do {
        uVar11 = uVar18;
        local_res10 = (code *)0x0;
        lVar14 = uVar22 * 0x58 + *(longlong *)(param_1 + 0x478);
        if ((*(uint *)(lVar14 + 0x50) & 0x10) == 0) {
          if (*(uint *)(param_1 + 0x78) <= uVar13) {
            uVar11 = 0xc000009c;
            goto LAB_140025c66;
          }
          uVar11 = IoCreateDevice(*(undefined8 *)(param_1 + 0x10),0x578,0,0x22,0x80,
                                  (ulonglong)in_stack_ffffffffffffffc0 & 0xffffffffffffff00,
                                  &local_res10);
          if (((int)uVar11 < 0) || (local_res10 == (code *)0x0)) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0xd,
                                &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,(char)uVar11);
            }
            RecordStartFailData(param_1,uVar11,0,0xa0000005,0x43534632,(void *)0x0,0);
            break;
          }
          puVar5 = *(undefined4 **)(local_res10 + 0x40);
          memset((void *)((longlong)puVar5 + 5),0,0x573);
          *(undefined1 *)(puVar5 + 1) = 0;
          *puVar5 = 0x43627355;
          puVar19 = puVar5 + 2;
          *(uint *)(local_res10 + 0x30) = *(uint *)(local_res10 + 0x30) | 0x2000;
          *puVar19 = 0x436f6450;
          puVar5[3] = (int)uVar22;
          *(code **)(puVar5 + 0x3a) = local_res10;
          *(undefined8 *)(puVar5 + 0x4a) = 0;
          *(undefined1 *)((longlong)puVar5 + 0x7e) = 0;
          *(undefined8 *)(puVar5 + 0x6a) = 0;
          *(longlong *)(puVar5 + 0x3c) = param_1;
          *(longlong *)(puVar5 + 0x3e) = lVar14;
          puVar5[6] = 1;
          puVar5[0x4c] = 8;
          *(bool *)((longlong)puVar5 + 0x135) = *(char *)(param_1 + 0x55a) == '\0';
          *(undefined8 *)(puVar5 + 100) = *(undefined8 *)(param_1 + 0x560);
          puVar1 = puVar5 + 0x58;
          *(undefined8 *)(puVar5 + 0x56) = 0;
          *(undefined8 *)(puVar5 + 0x5c) = 0;
          *(undefined4 **)(puVar5 + 0x5a) = puVar1;
          *(undefined4 **)puVar1 = puVar1;
          puVar5[0x4f] = 1;
          KeInitializeEvent(puVar5 + 0x50,0,0);
          KeInitializeSpinLock(puVar5 + 0x48);
          KeInitializeEvent(puVar5 + 0x6c,1,1);
          KeInitializeSpinLock(puVar5 + 0x72);
          puVar1 = puVar5 + 0x74;
          *(undefined4 **)(puVar5 + 0x76) = puVar1;
          *(undefined4 **)puVar1 = puVar1;
          puVar1 = puVar5 + 0x1a;
          *(undefined4 **)(puVar5 + 0x1c) = puVar1;
          *(undefined4 **)puVar1 = puVar1;
          IoCsqInitialize(puVar5 + 10,WaitWakeInsertIrp,WaitWakeRemoveIrp,PdoIdlePeekNextIrp,
                          WaitWakeAcquireLock,WaitWakeReleaseLock,WaitWakeCancelComplete);
          puVar1 = puVar5 + 0x30;
          *(undefined4 **)(puVar5 + 0x32) = puVar1;
          *(undefined4 **)puVar1 = puVar1;
          uVar26 = 1;
          in_stack_ffffffffffffffc0 = PdoIdleReleaseLock;
          uVar24 = 1;
          IoCsqInitialize(puVar5 + 0x20,PdoIdleInsertIrp,PdoIdleRemoveIrp,PdoIdlePeekNextIrp,
                          PdoIdleAcquireLock,PdoIdleReleaseLock,PdoIdleCancelComplete);
          KeInitializeEvent(puVar5 + 0x34,0);
          bVar9 = *(byte *)(lVar14 + 5);
          puVar5[4] = (uint)bVar9;
          bVar2 = *(byte *)(lVar14 + 6);
          puVar5[5] = (uint)bVar2;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            in_stack_ffffffffffffffc0 =
                 (code *)CONCAT44((int)((ulonglong)in_stack_ffffffffffffffc0 >> 0x20),(uint)bVar2);
            uVar24 = 1;
            WPP_RECORDER_SF_dd(*(undefined8 *)(param_1 + 0x560),4,1,0xe,
                               &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,bVar2,bVar9);
          }
          uVar6 = *(undefined4 *)(param_1 + 100);
          uVar7 = *(undefined4 *)(param_1 + 0x68);
          uVar8 = *(undefined4 *)(param_1 + 0x6c);
          puVar5[0x42] = *(undefined4 *)(param_1 + 0x60);
          puVar5[0x43] = uVar6;
          puVar5[0x44] = uVar7;
          puVar5[0x45] = uVar8;
          *(undefined2 *)(puVar5 + 0x46) = *(undefined2 *)(param_1 + 0x70);
          lVar4 = *(longlong *)**(undefined8 **)(lVar14 + 8);
          lVar15 = *(longlong *)(puVar5 + 0x3c);
          if ((0x200 < *(ushort *)(lVar15 + 0x62)) && ((*(uint *)(lVar15 + 0x4d0) & 0x20) == 0)) {
            uVar25 = CONCAT44(uVar26,0x62);
            in_stack_ffffffffffffffc0 =
                 (code *)CONCAT44((int)((ulonglong)in_stack_ffffffffffffffc0 >> 0x20),6);
            uVar23 = CONCAT44(uVar24,8);
            lVar15 = USBD_ParseConfigurationDescriptorEx
                               (*(undefined8 *)(lVar15 + 0x30),lVar4,*(undefined1 *)(lVar4 + 2),
                                0xffffffff,uVar23,in_stack_ffffffffffffffc0,uVar25);
            uVar24 = (undefined4)((ulonglong)uVar23 >> 0x20);
            uVar26 = (undefined4)((ulonglong)uVar25 >> 0x20);
            if ((lVar15 != 0) && (*(char *)(*(longlong *)(puVar5 + 0x3c) + 0x55b) == '\0')) {
              *(undefined1 *)((longlong)puVar5 + 0x137) = 1;
              *(undefined1 *)((longlong)puVar5 + 0x139) = *(undefined1 *)(lVar15 + 3);
            }
          }
          uVar18 = uVar13;
          if (*(char *)(lVar4 + 5) == -1) {
            in_stack_ffffffffffffffc0 =
                 (code *)CONCAT44((int)((ulonglong)in_stack_ffffffffffffffc0 >> 0x20),1);
            lVar15 = USBD_ParseConfigurationDescriptorEx
                               (*(undefined8 *)(*(longlong *)(puVar5 + 0x3c) + 0x30),lVar4,
                                *(undefined1 *)(lVar4 + 2),0xffffffff,CONCAT44(uVar24,7),
                                in_stack_ffffffffffffffc0,CONCAT44(uVar26,4));
            if (lVar15 != 0) {
              uVar16 = Feature_WinUsb_Print__private_IsEnabledDeviceUsageNoInline();
              lVar17 = *(longlong *)(puVar5 + 0x3c);
              if ((int)uVar16 == 0) {
LAB_140025a8d:
                *(undefined1 *)((longlong)puVar5 + 0x137) = 1;
                iVar12 = CheckIppUsbAltIndex(*(ushort *)(lVar17 + 0x68),*(ushort *)(lVar17 + 0x6a),
                                             *(byte *)(lVar4 + 2));
                if ((iVar12 == 0) && (iVar12 = IsProtectedPrintEnabled(), iVar12 == 0))
                goto LAB_140025ac3;
                *(undefined1 *)(puVar5 + 0x4e) = 1;
                uVar10 = *(undefined1 *)(lVar15 + 3);
              }
              else {
                uVar18 = CheckOptInWinUsbPrint
                                   (*(ushort *)(lVar17 + 0x68),*(ushort *)(lVar17 + 0x6a));
                if (uVar18 == 0) {
                  lVar17 = *(longlong *)(puVar5 + 0x3c);
                  goto LAB_140025a8d;
                }
                uVar10 = *(undefined1 *)(lVar15 + 3);
                *(undefined1 *)(puVar5 + 0x68) = 1;
              }
              *(undefined1 *)((longlong)puVar5 + 0x139) = uVar10;
            }
LAB_140025ac3:
            uVar18 = local_res8;
          }
          uVar16 = Feature_WinUsb_Print__private_IsEnabledDeviceUsageNoInline();
          if ((((int)uVar16 != 0) && (*(char *)(lVar4 + 5) == '\a')) &&
             (uVar13 = CheckOptInWinUsbPrint
                                 (*(ushort *)(*(longlong *)(puVar5 + 0x3c) + 0x68),
                                  *(ushort *)(*(longlong *)(puVar5 + 0x3c) + 0x6a)), uVar13 != 0)) {
            *(undefined1 *)(puVar5 + 0x68) = 1;
          }
          cVar3 = *(char *)(*(longlong *)**(undefined8 **)(lVar14 + 8) + 8);
          if (cVar3 != '\0') {
            *(char *)((longlong)puVar5 + 0x117) = cVar3;
          }
          if ((*(longlong *)(lVar14 + 0x10) != 0) &&
             (cVar3 = *(char *)(*(longlong *)(lVar14 + 0x10) + 7), cVar3 != '\0')) {
            *(char *)((longlong)puVar5 + 0x117) = cVar3;
          }
          uVar13 = uVar18 + 1;
          *(code **)(*(longlong *)(param_1 + 0x80) + 8 + (ulonglong)uVar18 * 8) = local_res10;
          *(code **)(uVar22 * 0x58 + 0x48 + *(longlong *)(param_1 + 0x478)) = local_res10;
          local_res10[0x4c] = (code)(*(char *)(*(longlong *)(param_1 + 0x20) + 0x4c) + '\x01');
          if (*(char *)(param_1 + 0x559) != '\0') {
            SetFunctionHandleData
                      (param_1,(longlong)puVar19,
                       *(undefined8 *)(*(longlong *)(param_1 + 0x550) + uVar22 * 8));
          }
          if (*(char *)(param_1 + 0x55a) != '\0') {
            uVar11 = AllocateResourcesForFunctionSuspend(param_1,(longlong)puVar19);
            if ((int)uVar11 < 0) goto LAB_140025c66;
            uVar16 = IsFunctionRemoteWakeCapable(param_1,(longlong)puVar19);
            *(char *)(*(longlong *)(puVar5 + 0x62) + 0x39) = (char)uVar16;
          }
          local_res8 = uVar13;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            in_stack_ffffffffffffffc0 = local_res10;
            WPP_RECORDER_SF_qd(*(undefined8 *)(param_1 + 0x560),4,1,0xf,
                               &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,(char)local_res10,
                               (char)uVar13);
          }
        }
        uVar21 = (int)uVar22 + 1;
        uVar22 = (ulonglong)uVar21;
        uVar18 = uVar11;
      } while (uVar21 < *(uint *)(param_1 + 0x74));
    }
    if (-1 < (int)uVar11) {
      **(undefined4 **)(param_1 + 0x80) = *(undefined4 *)(param_1 + 0x78);
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return uVar11;
      }
      uVar18 = *(uint *)(param_1 + 0x78);
      uVar20 = 0x10;
      bVar9 = 4;
      uVar13 = 1;
      goto LAB_140025ce7;
    }
  }
LAB_140025c66:
  if (*(longlong *)(param_1 + 0x80) != 0) {
    uVar18 = 0;
    if (*(int *)(param_1 + 0x78) != 0) {
      do {
        lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x80) + 8 + (ulonglong)uVar18 * 8);
        if (lVar14 != 0) {
          FreeResourcesForFunctionSuspend(*(longlong *)(lVar14 + 0x40));
          IoDeleteDevice(lVar14);
        }
        uVar18 = uVar18 + 1;
      } while (uVar18 < *(uint *)(param_1 + 0x78));
    }
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x80),0x43627355);
    *(undefined8 *)(param_1 + 0x80) = 0;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
    return uVar11;
  }
  uVar20 = 0x11;
  bVar9 = 2;
  uVar13 = 8;
  uVar18 = uVar11;
LAB_140025ce7:
  WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),bVar9,uVar13,uVar20,
                    &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,(char)uVar18);
  return uVar11;
}



===== GetMsExtendedConfigDescriptor @ 140025d80 =====

int GetMsExtendedConfigDescriptor(longlong param_1)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined2 uVar7;
  uint local_res8 [2];
  
  local_res8[0] = 0;
  if (*(longlong *)(param_1 + 0x468) != 0) {
    return 0;
  }
  puVar4 = (uint *)0x0;
  puVar3 = (uint *)ExAllocatePool2(0x40);
  if (puVar3 == (uint *)0x0) {
    iVar2 = -0x3fffff66;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0x14,
                       &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids);
    }
    goto LAB_140025e8f;
  }
  iVar2 = GetMsOsFeatureDescriptor(param_1,0,0,4,puVar3,0x10,local_res8);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),4,1,0x15,
                        &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids,(char)iVar2);
    }
  }
  else if ((((local_res8[0] == 0x10) && ((short)puVar3[1] == 0x100)) &&
           (*(short *)((longlong)puVar3 + 6) == 4)) &&
          (((byte)puVar3[2] != 0 && (*puVar3 == (uint)(byte)puVar3[2] * 0x18 + 0x10)))) {
    puVar4 = (uint *)ExAllocatePool2(0x40);
    if (puVar4 == (uint *)0x0) {
      iVar2 = -0x3fffff66;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar7 = 0x17;
LAB_140025fa1:
        WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,uVar7,
                         &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids);
      }
    }
    else {
      iVar2 = GetMsOsFeatureDescriptor(param_1,0,0,4,puVar4,*puVar3,local_res8);
      uVar1 = local_res8[0];
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_L(*(undefined8 *)(param_1 + 0x560),2,8,0x18,
                            &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids,(char)iVar2);
        }
      }
      else {
        if ((local_res8[0] != *puVar3) ||
           (lVar5 = RtlCompareMemory(puVar3,puVar4,0x10), lVar5 != 0x10)) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            uVar7 = 0x19;
            goto LAB_1400260a2;
          }
          goto LAB_1400260c2;
        }
        uVar6 = USBD_ValidateExtendedConfigurationDescriptor
                          (puVar4,uVar1,*(longlong *)(param_1 + 0x38),
                           (uint)*(ushort *)(*(longlong *)(param_1 + 0x38) + 2));
        iVar2 = (int)uVar6;
        if ((iVar2 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
          uVar7 = 0x1a;
          goto LAB_140025fa1;
        }
      }
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar7 = 0x16;
LAB_1400260a2:
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,uVar7,
                       &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids);
    }
LAB_1400260c2:
    iVar2 = -0x3ffffff3;
  }
  ExFreePoolWithTag(puVar3,0x43627355);
  if (-1 < iVar2) {
    *(uint **)(param_1 + 0x460) = puVar4;
    return iVar2;
  }
  if (puVar4 != (uint *)0x0) {
    ExFreePoolWithTag(puVar4,0x43627355);
  }
LAB_140025e8f:
  *(undefined8 *)(param_1 + 0x460) = 0;
  if (iVar2 == -0x3fffff45) {
    iVar2 = 0;
  }
  return iVar2;
}



===== GetMsOs20DescriptorSet @ 1400260ec =====

int GetMsOs20DescriptorSet(longlong param_1)

{
  int iVar1;
  short *psVar2;
  void *_Dst;
  ulonglong uVar3;
  undefined2 uVar4;
  uint local_res10 [2];
  
  local_res10[0] = 0;
  _Dst = (void *)0x0;
  psVar2 = (short *)ExAllocatePool2(0x40);
  if (psVar2 == (short *)0x0) {
    iVar1 = -0x3fffff66;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0x1b,
                       &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids);
    }
    goto LAB_1400263ee;
  }
  psVar2[0] = 0;
  psVar2[1] = 0;
  psVar2[2] = 0;
  psVar2[3] = 0;
  psVar2[4] = 0;
  iVar1 = GetMsOsFeatureDescriptor(param_1,0,0,7,psVar2,10,local_res10);
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),4,1,0x1c,
                        &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids,(char)iVar1);
    }
  }
  else {
    if (((local_res10[0] == 10) && (*psVar2 == 10)) && (psVar2[1] == 0)) {
      uVar3 = Feature_1916511546__private_IsEnabledDeviceUsageNoInline();
      if (((int)uVar3 == 0) || (9 < (ushort)psVar2[4])) {
        _Dst = (void *)ExAllocatePool2(0x40,psVar2[4],0x43627355);
        if (_Dst == (void *)0x0) {
          iVar1 = -0x3fffff66;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0x1f,
                             &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids);
          }
        }
        else {
          memset(_Dst,0,(ulonglong)(ushort)psVar2[4]);
          iVar1 = GetMsOsFeatureDescriptor(param_1,0,0,7,_Dst,(uint)(ushort)psVar2[4],local_res10);
          if (iVar1 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_L(*(undefined8 *)(param_1 + 0x560),2,8,0x20,
                                &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids,(char)iVar1);
            }
          }
          else if (local_res10[0] != (ushort)psVar2[4]) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar4 = 0x21;
              goto LAB_14002637c;
            }
            goto LAB_14002639c;
          }
        }
        goto LAB_1400263a1;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_dd(*(undefined8 *)(param_1 + 0x560),4,1,0x1e,
                           &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids,(char)psVar2[4],10);
      }
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar4 = 0x1d;
LAB_14002637c:
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),4,1,uVar4,
                       &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids);
    }
LAB_14002639c:
    iVar1 = -0x3fffff64;
  }
LAB_1400263a1:
  ExFreePoolWithTag(psVar2,0x43627355);
  if (-1 < iVar1) {
    uVar3 = Feature_1916511546__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar3 != 0) {
      *(uint *)(param_1 + 0x470) = local_res10[0];
    }
    *(void **)(param_1 + 0x468) = _Dst;
    return iVar1;
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0x43627355);
  }
LAB_1400263ee:
  *(undefined8 *)(param_1 + 0x468) = 0;
  uVar3 = Feature_1916511546__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 != 0) {
    *(undefined4 *)(param_1 + 0x470) = 0;
  }
  if (iVar1 == -0x3fffff45) {
    iVar1 = 0;
  }
  return iVar1;
}



===== LegacyGroupInterfaces @ 140026434 =====

ulonglong LegacyGroupInterfaces(longlong param_1,longlong *param_2,uint *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  uint local_res10 [2];
  uint uVar6;
  void *pvVar7;
  uint uVar8;
  
  *param_2 = 0;
  local_res10[0] = 0;
  *param_3 = 0;
  uVar4 = 0;
  while (plVar1 = GetFunctionInterfaceListBase(param_1,uVar4,(int *)local_res10),
        plVar1 != (longlong *)0x0) {
    uVar4 = uVar4 + 1;
  }
  if (uVar4 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0x40,
                       &WPP_93f6b87810f63f9db566694056813e32_Traceguids);
    }
    pvVar7 = *(void **)(param_1 + 0x30);
    uVar5 = 0xa0000006;
    uVar8 = 9;
    uVar4 = 0xc000009c;
    uVar6 = 0x43464c31;
  }
  else {
    lVar2 = ExAllocatePool2(0x40,(ulonglong)uVar4 * 0x58);
    if (lVar2 != 0) {
      uVar5 = 0;
      do {
        if (uVar4 <= uVar5) {
          *param_2 = lVar2;
          *param_3 = uVar4;
          return 0;
        }
        plVar1 = GetFunctionInterfaceListBase(param_1,uVar5,(int *)local_res10);
        if (plVar1 != (longlong *)0x0) {
          uVar3 = InitializeFunctionAssoc
                            (param_1,(undefined4 *)((ulonglong)uVar5 * 0x58 + lVar2),
                             (uint)*(byte *)(*plVar1 + 2),local_res10[0]);
          if ((int)uVar3 < 0) {
            CleanFunctionList(lVar2,uVar4);
            return uVar3 & 0xffffffff;
          }
        }
        *(char *)((ulonglong)uVar5 * 0x58 + 4 + lVar2) = (char)uVar5;
        uVar5 = uVar5 + 1;
      } while( true );
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0x41,
                       &WPP_93f6b87810f63f9db566694056813e32_Traceguids);
    }
    uVar8 = 0;
    uVar5 = 0xa0000005;
    pvVar7 = (void *)0x0;
    uVar4 = 0xc000009a;
    uVar6 = 0x43464c32;
  }
  RecordStartFailData(param_1,uVar4,0,uVar5,uVar6,pvVar7,uVar8);
  return (ulonglong)uVar4;
}



===== ParentFindOriginalConfiguration @ 140026620 =====

undefined8 ParentFindOriginalConfiguration(longlong param_1,undefined1 *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined1 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 local_res8 [2];
  undefined4 local_res10 [2];
  undefined8 local_res18;
  undefined8 in_stack_ffffffffffffffa8;
  undefined8 local_48;
  undefined8 uStack_40;
  
  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20);
  uVar6 = 0;
  local_res18 = 0;
  local_res8[0] = 0;
  iVar8 = 0;
  iVar1 = IoOpenDeviceRegistryKey(*(undefined8 *)(param_1 + 0x18),1,0x1f0000,&local_res18);
  if (-1 < iVar1) {
    local_res10[0] = 0;
    local_48 = 0;
    uStack_40 = 0;
    RtlInitUnicodeString(&local_48,L"OriginalConfigurationValue");
    uVar5 = 0x100;
    if (ExDefaultNonPagedPoolType == 1) {
      uVar5 = 0x40;
    }
    lVar4 = ExAllocatePool2(uVar5,0x10,0x43627355);
    if (lVar4 == 0) {
      iVar1 = -0x3fffff66;
      uVar6 = 0;
    }
    else {
      iVar2 = ZwQueryValueKey(local_res18,&local_48,2,lVar4,CONCAT44(uVar7,0x10),local_res10);
      iVar1 = 0;
      if (iVar2 != -0x7ffffffb) {
        iVar1 = iVar2;
      }
      uVar7 = 0;
      if (-1 < iVar1) {
        uVar3 = *(uint *)(lVar4 + 8);
        if (4 < uVar3) {
          uVar3 = 4;
        }
        memmove(local_res8,(void *)(lVar4 + 0xc),(ulonglong)uVar3);
        iVar8 = *(int *)(lVar4 + 4);
        uVar7 = local_res8[0];
      }
      ExFreePoolWithTag(lVar4,0x43627355);
      uVar6 = (char)uVar7;
    }
    ZwClose(local_res18);
  }
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),3,8,0x47,
                        &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)iVar1);
    }
  }
  else {
    if (iVar8 == 4) goto LAB_140026742;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0x48,
                       &WPP_93f6b87810f63f9db566694056813e32_Traceguids);
    }
  }
  uVar6 = 0;
LAB_140026742:
  *param_2 = uVar6;
  return 0;
}



===== ParentQueryForInterface @ 140026800 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int ParentQueryForInterface(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  ushort *puVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uVar6 = 0x100;
  if (ExDefaultNonPagedPoolType == 1) {
    uVar6 = 0x40;
  }
  puVar3 = (ushort *)ExAllocatePool2(uVar6,0x68,0x43627355);
  if (puVar3 == (ushort *)0x0) {
    iVar2 = -0x3fffff66;
  }
  else {
    lVar4 = IoGetAttachedDeviceReference(*(undefined8 *)(param_1 + 0x20));
    lVar5 = IoAllocateIrp(*(char *)(lVar4 + 0x4c) + '\x01',0);
    if (lVar5 == 0) {
      iVar2 = -0x3fffff66;
    }
    else {
      *(undefined4 *)(lVar5 + 0x30) = 0xc00000bb;
      KeInitializeEvent(&local_38,0,0);
      lVar1 = *(longlong *)(lVar5 + 0xb8);
      *(code **)(lVar1 + -0x10) = USBD_SyncCompletionRoutine;
      *(undefined8 **)(lVar1 + -8) = &local_38;
      *(undefined1 *)(lVar1 + -0x45) = 0xe0;
      lVar1 = *(longlong *)(lVar5 + 0xb8);
      *(undefined8 *)(lVar1 + -0x28) = 0;
      *(undefined **)(lVar1 + -0x40) = &USB_BUS_INTERFACE_USBC_CONFIGURATION_GUID;
      *(undefined2 *)(lVar1 + -0x48) = 0x81b;
      *(ushort **)(lVar1 + -0x30) = puVar3;
      *(undefined4 *)(lVar1 + -0x38) = 0x10068;
      iVar2 = IofCallDriver(lVar4,lVar5);
      if (iVar2 == 0x103) {
        WaitForSignal(&local_38,"event (waiting for query-interface to complete)",
                      *(undefined8 *)(param_1 + 0x560));
        iVar2 = *(int *)(lVar5 + 0x30);
      }
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0x49,
                            &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)iVar2);
        }
      }
      else if ((puVar3[1] == 1) && (0x67 < *puVar3)) {
        uVar6 = *(undefined8 *)(puVar3 + 4);
        *(undefined8 *)(param_1 + 0x4e0) = *(undefined8 *)puVar3;
        *(undefined8 *)(param_1 + 0x4e8) = uVar6;
        uVar6 = *(undefined8 *)(puVar3 + 0xc);
        *(undefined8 *)(param_1 + 0x4f0) = *(undefined8 *)(puVar3 + 8);
        *(undefined8 *)(param_1 + 0x4f8) = uVar6;
        uVar6 = *(undefined8 *)(puVar3 + 0x14);
        *(undefined8 *)(param_1 + 0x500) = *(undefined8 *)(puVar3 + 0x10);
        *(undefined8 *)(param_1 + 0x508) = uVar6;
        uVar6 = *(undefined8 *)(puVar3 + 0x1c);
        *(undefined8 *)(param_1 + 0x510) = *(undefined8 *)(puVar3 + 0x18);
        *(undefined8 *)(param_1 + 0x518) = uVar6;
        uVar6 = *(undefined8 *)(puVar3 + 0x24);
        *(undefined8 *)(param_1 + 0x520) = *(undefined8 *)(puVar3 + 0x20);
        *(undefined8 *)(param_1 + 0x528) = uVar6;
        uVar6 = *(undefined8 *)(puVar3 + 0x2c);
        *(undefined8 *)(param_1 + 0x530) = *(undefined8 *)(puVar3 + 0x28);
        *(undefined8 *)(param_1 + 0x538) = uVar6;
        *(undefined8 *)(param_1 + 0x540) = *(undefined8 *)(puVar3 + 0x30);
        *(uint *)(param_1 + 0x4d4) = *(uint *)(param_1 + 0x4d4) | 2;
      }
      else {
        iVar2 = -0x3ffffff3;
        (**(code **)(puVar3 + 0xc))(*(undefined8 *)(puVar3 + 4));
      }
      IoFreeIrp(lVar5);
    }
    ExFreePoolWithTag(puVar3,0x43627355);
    ObfDereferenceObject(lVar4);
  }
  return iVar2;
}



===== ParentGetD3ColdInterface @ 140026a6c =====

int ParentGetD3ColdInterface(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  KeInitializeEvent(&local_28,0,0);
  uVar3 = IoGetAttachedDeviceReference(*(undefined8 *)(param_1 + 0x20));
  lVar4 = IoBuildSynchronousFsdRequest(0x1b,uVar3,0,0,0,&local_28,&local_38);
  if (lVar4 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    lVar1 = *(longlong *)(lVar4 + 0xb8);
    *(undefined8 *)(lVar4 + 0x38) = 0;
    *(undefined4 *)(lVar4 + 0x30) = 0xc00000bb;
    *(undefined8 *)(lVar1 + -0x28) = 0;
    *(undefined **)(lVar1 + -0x40) = &GUID_D3COLD_SUPPORT_INTERFACE;
    *(longlong *)(lVar1 + -0x30) = param_1 + 0x1c0;
    *(undefined1 *)(lVar1 + -0x47) = 8;
    *(undefined4 *)(lVar1 + -0x38) = 0x10048;
    iVar2 = IofCallDriver(uVar3,lVar4);
    if (iVar2 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      iVar2 = (int)local_38;
    }
  }
  ObfDereferenceObject(uVar3);
  if (-1 < iVar2) {
    *(undefined1 *)(param_1 + 0x1b9) = 1;
  }
  return iVar2;
}



===== CreateFunctionList @ 140026bbc =====

ulonglong CreateFunctionList(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined2 uVar4;
  uint local_res8 [2];
  longlong local_res10;
  
  local_res10 = 0;
  local_res8[0] = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  uVar2 = InvokeDeviceClassCallback(param_1,&local_res10,local_res8);
  uVar3 = uVar2 & 0xffffffff;
  if ((int)uVar2 < 0) {
LAB_140026c6c:
    if ((int)uVar3 < 0) {
      *(undefined8 *)(param_1 + 0x478) = 0;
      *(undefined4 *)(param_1 + 0x74) = 0;
      return uVar3;
    }
  }
  else {
    if ((local_res8[0] == 0) || (local_res10 == 0)) {
      uVar1 = ParseUSBInterfaceAssociationDescriptors(param_1,&local_res10,(int *)local_res8);
      uVar3 = (ulonglong)uVar1;
      if ((int)uVar1 < 0) goto LAB_140026c6c;
      if ((local_res8[0] == 0) || (local_res10 == 0)) {
        uVar2 = LegacyGroupInterfaces(param_1,&local_res10,local_res8);
        uVar3 = uVar2 & 0xffffffff;
        if (((int)uVar2 < 0) ||
           (((local_res8[0] == 0 || (local_res10 == 0)) ||
            ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))))
        goto LAB_140026c6c;
        uVar4 = 0x44;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140026c70;
        uVar4 = 0x43;
      }
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140026c70;
      uVar4 = 0x42;
    }
    WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),4,1,uVar4,
                     &WPP_93f6b87810f63f9db566694056813e32_Traceguids);
  }
LAB_140026c70:
  *(longlong *)(param_1 + 0x478) = local_res10;
  *(uint *)(param_1 + 0x74) = local_res8[0];
  return uVar3;
}



===== InvokeDeviceClassCallback @ 140026cf8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong InvokeDeviceClassCallback(longlong param_1,longlong *param_2,uint *param_3)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  longlong lVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  byte bVar10;
  undefined4 uVar11;
  char cVar12;
  size_t _Size;
  char cVar13;
  undefined2 uVar14;
  int iVar15;
  char cVar16;
  code *pcVar17;
  undefined8 in_stack_ffffffffffffff68;
  undefined4 local_74;
  uint local_70 [2];
  undefined8 local_68;
  ulonglong local_60 [4];
  
  uVar11 = (undefined4)((ulonglong)in_stack_ffffffffffffff68 >> 0x20);
  uVar6 = *(uint *)(param_1 + 0x4d4);
  local_60[0] = 0;
  cVar13 = '\0';
  local_70[0] = 0;
  local_74 = 0;
  *param_2 = 0;
  *param_3 = 0;
  if (((uVar6 & 2) != 0) && (pcVar17 = *(code **)(param_1 + 0x500), pcVar17 != (code *)0x0)) {
LAB_140026f77:
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x560),4,1,0xc,
                        &WPP_e8749e7517b2302104950dba271a6a56_Traceguids,
                        (char)*(undefined8 *)(param_1 + 0x20));
    }
    uVar6 = (*pcVar17)(param_1 + 0x60,*(undefined8 *)(param_1 + 0x38),local_60,local_70,
                       *(undefined8 *)(param_1 + 0x20),*(undefined8 *)(param_1 + 0x18));
    if ((int)uVar6 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),4,1,0xd,
                          &WPP_e8749e7517b2302104950dba271a6a56_Traceguids,(char)uVar6);
      }
      RecordStartFailData(param_1,uVar6,0,0xa000000a,0x464c4342,*(void **)(param_1 + 0x30),
                          (uint)*(ushort *)((longlong)*(void **)(param_1 + 0x30) + 2));
      return (ulonglong)uVar6;
    }
    if ((local_60[0] != 0) && (local_70[0] != 0)) {
      uVar8 = ProcessFunctionDescriptors(param_1,local_60[0],local_70[0],param_2,param_3);
      return uVar8;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    uVar14 = 0xe;
    bVar10 = 2;
    uVar6 = 8;
    goto LAB_14002709b;
  }
  cVar1 = *(char *)(param_1 + 100);
  cVar12 = *(char *)(param_1 + 0x65);
  cVar16 = *(char *)(param_1 + 0x66);
  iVar15 = 0;
  uVar6 = 0;
  local_68 = 0;
  iVar4 = IoOpenDeviceRegistryKey(*(undefined8 *)(param_1 + 0x18),2,0x1f0000,&local_68);
  if (iVar4 < 0) {
LAB_140026e5d:
    bVar3 = false;
    cVar13 = cVar1;
  }
  else {
    local_70[1] = 0;
    local_60[1] = 0;
    local_60[2] = 0;
    RtlInitUnicodeString(local_60 + 1,L"EnumeratorClass");
    uVar9 = 0x100;
    if (ExDefaultNonPagedPoolType == 1) {
      uVar9 = 0x40;
    }
    lVar7 = ExAllocatePool2(uVar9,0x10,0x43627355);
    if (lVar7 == 0) {
      iVar4 = -0x3fffff66;
    }
    else {
      iVar5 = ZwQueryValueKey(local_68,local_60 + 1,2,lVar7,CONCAT44(uVar11,0x10),local_70 + 1);
      iVar4 = 0;
      if (iVar5 != -0x7ffffffb) {
        iVar4 = iVar5;
      }
      uVar11 = 0;
      if (-1 < iVar4) {
        uVar6 = *(uint *)(lVar7 + 8);
        _Size = (size_t)uVar6;
        if (4 < uVar6) {
          _Size = 4;
        }
        memmove(&local_74,(void *)(lVar7 + 0xc),_Size);
        iVar15 = *(int *)(lVar7 + 4);
        uVar11 = local_74;
      }
      cVar13 = (char)uVar11;
      ExFreePoolWithTag(lVar7,0x43627355);
    }
    ZwClose(local_68);
    if (((iVar4 < 0) || (uVar6 < 3)) || (iVar15 != 3)) goto LAB_140026e5d;
    bVar3 = true;
    cVar12 = local_74._1_1_;
    cVar16 = local_74._2_1_;
  }
  bVar2 = false;
  while (!bVar2) {
    if (((bVar3) && (cVar13 == '\x02')) && ((cVar12 == '\0' && (cVar16 == '\0')))) {
      pcVar17 = CdcCallback;
      goto LAB_140026f77;
    }
    bVar2 = true;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
    return 0;
  }
  uVar14 = 0xf;
  bVar10 = 4;
  uVar6 = 1;
LAB_14002709b:
  WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),bVar10,uVar6,uVar14,
                   &WPP_e8749e7517b2302104950dba271a6a56_Traceguids);
  return 0;
}



===== StartParentFdo @ 1400270b8 =====

ulonglong StartParentFdo(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  longlong lVar7;
  short *_Dst;
  ulonglong uVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  ulonglong uVar12;
  undefined8 uVar13;
  byte *pbVar14;
  short *psVar15;
  size_t _Size;
  byte bVar16;
  byte local_res8 [8];
  longlong local_res10;
  uint local_res18 [2];
  undefined4 local_res20 [2];
  ulonglong *in_stack_ffffffffffffff78;
  undefined4 uVar17;
  longlong local_60;
  ulonglong local_58;
  ulonglong local_50 [2];
  
  iVar6 = *(int *)(param_1 + 0xc);
  local_res8[0] = 0;
  uVar5 = 0;
  local_50[0] = 0;
  local_58 = 0;
  local_res18[0] = 0;
  local_res20[0] = 0;
  *(undefined4 *)(param_1 + 0xc) = 1;
  local_res10 = param_2;
  lVar7 = KeQueryUnbiasedInterruptTime();
  _Size = 0x80;
  do {
    uVar17 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);
    uVar13 = 0x100;
    if (ExDefaultNonPagedPoolType == 0x200) {
      uVar13 = 0x40;
    }
    _Dst = (short *)ExAllocatePool2(uVar13,_Size,0x43627355);
    if (_Dst == (short *)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0x28,
                         &WPP_93f6b87810f63f9db566694056813e32_Traceguids);
      }
      uVar8 = 0xc000009a;
      goto LAB_140027241;
    }
    memset(_Dst,0,_Size);
    in_stack_ffffffffffffff78 = (ulonglong *)CONCAT44(uVar17,(int)_Size);
    uVar3 = IoGetDevicePropertyData
                      (*(undefined8 *)(param_1 + 0x18),&DEVPKEY_Device_HardwareIds,0,0,
                       in_stack_ffffffffffffff78,_Dst,local_res18,local_res20);
    uVar8 = (ulonglong)uVar3;
    if (uVar3 != 0xc0000023) {
      uVar5 = 0;
      if (-1 < (int)uVar3) {
        psVar15 = _Dst;
        goto LAB_1400271bc;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0x29,
                          &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)uVar3);
      }
      goto LAB_14002722d;
    }
    _Size = (size_t)local_res18[0];
    uVar5 = uVar5 + 1;
    ExFreePoolWithTag(_Dst,0x43627355);
  } while (uVar5 < 2);
  lVar9 = local_res10;
LAB_140027418:
  lVar10 = KeQueryUnbiasedInterruptTime();
  if (-1 < (int)uVar8) {
LAB_1400274a3:
    *(undefined4 *)(param_1 + 0xc) = 2;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar12 = (ulonglong)(lVar10 - lVar7) / 10000;
      WPP_RECORDER_SF_i(*(undefined8 *)(param_1 + 0x560),uVar12,1,0x34,in_stack_ffffffffffffff78,
                        (char)uVar12);
    }
    USBC_RegisterWmi(param_1);
    goto LAB_14002744e;
  }
LAB_140027432:
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0x33,
                      &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)uVar8);
  }
  *(undefined4 *)(param_1 + 0xc) = 3;
  ReportStartFailData(param_1);
LAB_14002744e:
  UsbcCompleteIrp(param_1,(int)uVar8,lVar9);
  return uVar8;
LAB_1400271bc:
  if (*psVar15 != 0) {
    uVar8 = 0xffffffffffffffff;
    do {
      uVar8 = uVar8 + 1;
    } while (psVar15[uVar8] != 0);
    if (((uint)uVar8 < 6) ||
       (iVar4 = swscanf_s(psVar15 + ((uVar8 & 0xffffffff) - 6),L"&MI_%02x"), iVar4 == 0))
    goto LAB_1400271d8;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0x2a,
                       &WPP_93f6b87810f63f9db566694056813e32_Traceguids);
    }
    uVar8 = 0xc0000001;
LAB_14002722d:
    ExFreePoolWithTag(_Dst,0x43627355);
LAB_140027241:
    KeQueryUnbiasedInterruptTime();
    lVar9 = local_res10;
    goto LAB_140027432;
  }
  goto LAB_140027256;
LAB_1400271d8:
  lVar9 = -1;
  do {
    lVar10 = lVar9;
    lVar9 = lVar10 + 1;
  } while (psVar15[lVar9] != 0);
  psVar15 = psVar15 + lVar10 + 2;
  goto LAB_1400271bc;
LAB_140027256:
  ExFreePoolWithTag(_Dst,0x43627355);
  lVar9 = local_res10;
  puVar1 = *(undefined8 **)(local_res10 + 0xb8);
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
  lVar10 = KeQueryUnbiasedInterruptTime();
  uVar13 = 0;
  uVar3 = CallDriverSync(*(undefined8 *)(param_1 + 0x28),lVar9,'\0',*(undefined8 *)(param_1 + 0x20))
  ;
  uVar8 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0x2b,
                        &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)uVar3);
    }
    RecordStartFailData(param_1,uVar3,0,0xa0000004,0x46535046,(void *)0x0,0);
LAB_14002756d:
    KeQueryUnbiasedInterruptTime();
  }
  else {
    lVar11 = KeQueryUnbiasedInterruptTime();
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar13 = 2;
      uVar12 = (ulonglong)(lVar11 - lVar10) / 10000;
      WPP_RECORDER_SF_i(*(undefined8 *)(param_1 + 0x560),uVar12,2,0x2c,in_stack_ffffffffffffff78,
                        (char)uVar12);
    }
    lVar7 = KeQueryUnbiasedInterruptTime();
    if (iVar6 == 0) {
      QueryUSBStackAndDeviceCapabilities(param_1);
      ParentGetD3ColdInterface(param_1);
      ParentQueryForInterface(param_1);
      uVar13 = ParentFindOriginalConfiguration(param_1,local_res8);
      if ((int)uVar13 < 0) {
        local_res8[0] = 0;
      }
      bVar16 = local_res8[0];
      do {
        *(byte *)(param_1 + 0x40) = bVar16;
        uVar3 = GetDeviceDescriptor(param_1);
        uVar8 = (ulonglong)uVar3;
        if (-1 < (int)uVar3) {
          uVar8 = (ulonglong)*(ushort *)(param_1 + 0x68);
          SetRecorderLogIdentifier
                    (*(undefined8 *)(param_1 + 0x560),*(ushort *)(param_1 + 0x68),
                     *(ushort *)(param_1 + 0x6a));
          uVar3 = GetConfigDescriptor(param_1,CONCAT71((int7)(uVar8 >> 8),bVar16));
          uVar8 = (ulonglong)uVar3;
          if ((int)uVar3 < 0) goto LAB_140027860;
          uVar3 = GetParentFdoCapabilities(param_1);
          uVar8 = (ulonglong)uVar3;
          if ((int)uVar3 < 0) goto LAB_140027860;
          uVar12 = (ulonglong)*(ushort *)(param_1 + 0x6c);
          in_stack_ffffffffffffff78 = local_50;
          USBC_QueryKseDeviceFlags
                    (*(ushort *)(param_1 + 0x68),(ulonglong)*(ushort *)(param_1 + 0x6a),uVar12,
                     &local_58,in_stack_ffffffffffffff78,*(undefined8 *)(param_1 + 0x560));
          if (((local_58 & 0x200000) != 0) || ((local_50[0] & 0x200000) != 0)) {
            *(uint *)(param_1 + 0x4d0) = *(uint *)(param_1 + 0x4d0) | 0x20;
          }
          lVar10 = GetInterfaceList(param_1,*(void **)(param_1 + 0x38));
          *(longlong *)(param_1 + 0x58) = lVar10;
          if (lVar10 == 0) {
            uVar8 = 0xc000009c;
            goto LAB_140027860;
          }
          uVar2 = (ushort)*(byte *)((longlong)*(void **)(param_1 + 0x38) + 4);
          in_stack_ffffffffffffff78 =
               (ulonglong *)CONCAT62((int6)((ulonglong)in_stack_ffffffffffffff78 >> 0x10),uVar2);
          uVar3 = ParentSelectConfiguration(param_1,*(void **)(param_1 + 0x38),uVar12,lVar10,uVar2);
          uVar8 = (ulonglong)uVar3;
          if ((int)uVar3 < 0) {
            pbVar14 = local_res8;
            iVar6 = ParentFindAltConfiguration(param_1,pbVar14);
            bVar16 = local_res8[0];
            if (iVar6 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                in_stack_ffffffffffffff78 =
                     (ulonglong *)&WPP_93f6b87810f63f9db566694056813e32_Traceguids;
                WPP_RECORDER_SF_ddd(*(undefined8 *)(param_1 + 0x560),pbVar14,uVar12,0x2f,
                                    &WPP_93f6b87810f63f9db566694056813e32_Traceguids,local_res8[0],
                                    (char)uVar3,(char)iVar6);
              }
            }
            else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              in_stack_ffffffffffffff78 =
                   (ulonglong *)&WPP_93f6b87810f63f9db566694056813e32_Traceguids;
              WPP_RECORDER_SF_dd(*(undefined8 *)(param_1 + 0x560),4,1,0x2e,
                                 &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)uVar3,
                                 local_res8[0]);
            }
            goto LAB_140027860;
          }
LAB_140027406:
          uVar12 = CreateFunctionList(param_1);
          uVar8 = uVar12 & 0xffffffff;
          if (-1 < (int)uVar12) {
            GetMsOs20DescriptorSet(param_1);
            GetMsExtendedConfigDescriptor(param_1);
            if (*(char *)(param_1 + 0x558) != '\0') {
              RegisterCompositeDevice(param_1);
            }
            uVar5 = CreateStaticFunctionPDOs(param_1);
            uVar8 = (ulonglong)uVar5;
            if (-1 < (int)uVar5) {
              IoInvalidateDeviceRelations(*(undefined8 *)(param_1 + 0x18),0);
              KeSetTimer(param_1 + 0x3e0,0xfffffffffd050f80,param_1 + 0x420);
            }
            CheckParentIdle(param_1);
          }
          goto LAB_140027418;
        }
LAB_140027860:
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          in_stack_ffffffffffffff78 = (ulonglong *)&WPP_93f6b87810f63f9db566694056813e32_Traceguids;
          WPP_RECORDER_SF_dd(*(undefined8 *)(param_1 + 0x560),2,8,0x30,
                             &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)uVar5,
                             (char)uVar8);
        }
        FreeInterfaceList(param_1,'\x01');
        if (*(longlong *)(param_1 + 0x30) != 0) {
          ExFreePoolWithTag(*(longlong *)(param_1 + 0x30),0x43627355);
        }
        *(undefined8 *)(param_1 + 0x30) = 0;
        *(undefined8 *)(param_1 + 0x38) = 0;
        ResetDevice(param_1);
        uVar5 = uVar5 + 1;
        if (-1 < (int)uVar8) goto LAB_140027406;
      } while (uVar5 < 3);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0x31,
                          &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)uVar8);
      }
      DbgPrint("USBCCGP: ERROR: All enumeration attempts failed!! status 0x%x\n",uVar8);
    }
    else {
      if (iVar6 == 2) {
        lVar10 = KeQueryUnbiasedInterruptTime();
        goto LAB_1400274a3;
      }
      if (iVar6 == 6) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          in_stack_ffffffffffffff78 = (ulonglong *)&WPP_93f6b87810f63f9db566694056813e32_Traceguids;
          uVar13 = 2;
          WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),4,2,0x2d,
                           &WPP_93f6b87810f63f9db566694056813e32_Traceguids);
        }
        uVar2 = (ushort)*(byte *)((longlong)*(void **)(param_1 + 0x38) + 4);
        in_stack_ffffffffffffff78 =
             (ulonglong *)CONCAT62((int6)((ulonglong)in_stack_ffffffffffffff78 >> 0x10),uVar2);
        uVar5 = ParentSelectConfiguration
                          (param_1,*(void **)(param_1 + 0x38),uVar13,*(longlong *)(param_1 + 0x58),
                           uVar2);
        *(undefined4 *)(param_1 + 0x188) = 0;
        uVar8 = (ulonglong)uVar5;
        EnableIdleTimer(param_1,'\x01',0x504f5453);
        goto LAB_140027418;
      }
      uVar8 = 0xc0000184;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002756d;
      WPP_RECORDER_SF_L(*(undefined8 *)(param_1 + 0x560),2,8,0x32,
                        &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)iVar6);
    }
    KeQueryUnbiasedInterruptTime();
  }
  goto LAB_140027432;
}



===== GetConfigDescriptor @ 140027928 =====

uint GetConfigDescriptor(longlong param_1,ulonglong param_2)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  undefined1 uVar6;
  char local_res18 [8];
  uint local_res20 [2];
  uint uVar7;
  void *pvVar8;
  uint local_38 [4];
  
  local_38[0] = 0;
  local_res20[0] = 0;
  uVar1 = 0xc0000001;
  local_res18[0] = '\0';
  uVar3 = 1;
  uVar2 = param_2;
  while( true ) {
    if (3 < uVar3) {
      return uVar1;
    }
    uVar6 = (undefined1)param_2;
    uVar2 = CONCAT71((int7)(uVar2 >> 8),uVar6);
    pcVar4 = local_res18;
    uVar1 = TryGetConfigDescriptor(param_1,uVar6,pcVar4,local_38,local_res20);
    if (-1 < (int)uVar1) break;
    if (uVar3 < 3) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_ddd(*(undefined8 *)(param_1 + 0x560),uVar2,pcVar4,0x1d,
                            &WPP_93f6b87810f63f9db566694056813e32_Traceguids,uVar6,(char)uVar1,
                            (char)uVar3);
      }
      local_res18[0] = '\0';
    }
    else {
      if (local_res18[0] == '\0') {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_dd(*(undefined8 *)(param_1 + 0x560),2,8,0x1f,
                             &WPP_93f6b87810f63f9db566694056813e32_Traceguids,3,(char)uVar1);
        }
        uVar5 = 0xa0000001;
        pvVar8 = *(void **)(param_1 + 0x30);
        uVar7 = 0x47434446;
      }
      else {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_dD(*(undefined8 *)(param_1 + 0x560));
        }
        uVar5 = 0xa0000006;
        pvVar8 = *(void **)(param_1 + 0x30);
        uVar7 = 0x43445646;
      }
      uVar2 = (ulonglong)uVar1;
      RecordStartFailData(param_1,uVar1,local_38[0],uVar5,uVar7,pvVar8,local_res20[0]);
    }
    uVar3 = uVar3 + 1;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
    return uVar1;
  }
  WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),4,1,0x1c,
                    &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)uVar3);
  return uVar1;
}



===== SetRecorderLogIdentifier @ 140027ac4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SetRecorderLogIdentifier(undefined8 param_1,ushort param_2,ushort param_3)

{
  undefined1 auStack_58 [32];
  uint local_38;
  char local_28 [16];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_38 = (uint)param_3;
  local_28[0] = '\0';
  local_28[1] = '\0';
  local_28[2] = '\0';
  local_28[3] = '\0';
  local_28[4] = '\0';
  local_28[5] = '\0';
  local_28[6] = '\0';
  local_28[7] = '\0';
  local_28[8] = '\0';
  local_28[9] = '\0';
  local_28[10] = '\0';
  local_28[0xb] = '\0';
  local_28[0xc] = '\0';
  local_28[0xd] = '\0';
  local_28[0xe] = '\0';
  local_28[0xf] = '\0';
  RtlStringCchPrintfA(local_28,0x10,"VEN%04X DEV%04X",(ulonglong)param_2);
  imp_WppRecorderLogSetIdentifier(WPP_GLOBAL_Control,param_1,local_28);
  return;
}



===== USBC_QueryKseDeviceFlags @ 140027b3c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void USBC_QueryKseDeviceFlags
               (ushort param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4,
               undefined8 *param_5,undefined8 param_6)

{
  int iVar1;
  undefined8 uVar2;
  undefined2 uVar3;
  undefined1 auStackY_b8 [32];
  wchar_t local_88 [40];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  *param_4 = 0;
  *param_5 = 0;
  if (g_KseQueryDeviceFlags == (code *)0x0) {
    *param_4 = 0;
    *param_5 = 0;
    return;
  }
  uVar2 = RtlStringCbPrintfW(local_88,0x50,L"USB:USB\\VID_%04X&PID_%04X&REV_%04X",(ulonglong)param_1
                            );
  iVar1 = (int)uVar2;
  if (iVar1 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar3 = 0xc;
  }
  else {
    (*g_KseQueryDeviceFlags)(local_88,L"USB",param_4);
    uVar2 = RtlStringCbPrintfW(local_88,0x50,L"USB:USB\\VID_%04X&PID_%04X",(ulonglong)param_1);
    iVar1 = (int)uVar2;
    if (-1 < iVar1) {
      (*g_KseQueryDeviceFlags)(local_88,L"USB",param_5);
      return;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar3 = 0xd;
  }
  WPP_RECORDER_SF_d(param_6,2,8,uVar3,&WPP_c8c0b630977f39a4a91a92e2db87f7d2_Traceguids,(char)iVar1);
  return;
}



===== GetParentFdoCapabilities @ 140027c94 =====

uint GetParentFdoCapabilities(longlong param_1)

{
  undefined2 *_Dst;
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  
  lVar3 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x28) >> 8),
                                 *(undefined1 *)(*(longlong *)(param_1 + 0x28) + 0x4c)));
  if (lVar3 == 0) {
    uVar2 = 0xc000009a;
    RecordStartFailData(param_1,0xc000009a,0,0xa0000005,0x47504643,(void *)0x0,0);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0x26,
                       &WPP_93f6b87810f63f9db566694056813e32_Traceguids);
    }
  }
  else {
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    _Dst = (undefined2 *)(param_1 + 0x88);
    *(undefined2 *)(lVar1 + -0x48) = 0x91b;
    memset(_Dst,0,0x40);
    *_Dst = 0x40;
    *(undefined4 *)(param_1 + 0x90) = 0xffffffff;
    *(undefined2 *)(param_1 + 0x8a) = 1;
    *(undefined4 *)(param_1 + 0x94) = 0xffffffff;
    *(undefined2 **)(lVar1 + -0x40) = _Dst;
    *(undefined4 *)(lVar3 + 0x30) = 0xc00000bb;
    uVar2 = CallDriverSync(*(undefined8 *)(param_1 + 0x28),lVar3,'\x01',
                           *(undefined8 *)(param_1 + 0x20));
    IoFreeIrp(lVar3);
    if ((int)uVar2 < 0) {
      RecordStartFailData(param_1,uVar2,0,0xa0000003,0x47504643,(void *)0x0,0);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0x27,
                          &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)uVar2);
      }
    }
  }
  return uVar2;
}



===== GetDeviceDescriptor @ 140027e34 =====

uint GetDeviceDescriptor(longlong param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  undefined2 *local_res8;
  
  puVar1 = (undefined8 *)(param_1 + 0x60);
  *puVar1 = 0;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(undefined2 *)(param_1 + 0x70) = 0;
  local_res8 = (undefined2 *)0x0;
  uVar2 = USBD_UrbAllocate(*(longlong *)(param_1 + 0x548),&local_res8);
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0x20,
                        &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)uVar2);
    }
  }
  else {
    local_res8[1] = 0xb;
    *local_res8 = 0x88;
    *(undefined4 *)(local_res8 + 0x12) = 0x12;
    *(undefined8 *)(local_res8 + 0x18) = 0;
    *(undefined8 **)(local_res8 + 0x14) = puVar1;
    *(undefined1 *)((longlong)local_res8 + 0x83) = 1;
    *(undefined1 *)(local_res8 + 0x41) = 0;
    local_res8[0x42] = 0;
    *(undefined8 *)(local_res8 + 0x1c) = 0;
    uVar2 = SubmitUrb(param_1,local_res8);
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0x22,
                          &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)uVar2);
      }
      RecordStartFailData(param_1,uVar2,*(uint *)(local_res8 + 2),0xa0000002,0x47444446,(void *)0x0,
                          0);
    }
    else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qdd(*(undefined8 *)(param_1 + 0x560),4,1,0x21,
                          &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)puVar1,
                          (char)*(undefined4 *)(local_res8 + 0x12),0x12);
    }
    USBD_UrbFree(*(longlong *)(param_1 + 0x548),(longlong)local_res8);
  }
  return uVar2;
}



===== ParentSelectConfiguration @ 140028010 =====

uint ParentSelectConfiguration
               (longlong param_1,void *param_2,undefined8 param_3,longlong param_4,ushort param_5)

{
  ushort uVar1;
  uint uVar2;
  short *psVar3;
  void *_Dst;
  uint uVar4;
  uint uVar5;
  ushort *_Src;
  uint uVar6;
  uint uVar7;
  
  psVar3 = BuildSelectConfigUrb(param_1,(longlong)param_2,param_4,param_5);
  if (psVar3 == (short *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0xe,
                       &WPP_93f6b87810f63f9db566694056813e32_Traceguids);
    }
    uVar2 = 0xc000009a;
    RecordStartFailData(param_1,0xc000009a,0,0xa0000005,0x50534355,(void *)0x0,0);
  }
  else {
    uVar2 = SubmitUrb(param_1,psVar3);
    if ((int)uVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_L(*(undefined8 *)(param_1 + 0x560),2,8,0xf,
                          &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)uVar2);
      }
      uVar5 = 0xa0000008;
      uVar4 = *(uint *)(psVar3 + 2);
      uVar7 = (uint)*(ushort *)((longlong)param_2 + 2);
      uVar6 = 0x50534346;
LAB_140028107:
      RecordStartFailData(param_1,uVar2,uVar4,uVar5,uVar6,param_2,uVar7);
    }
    else {
      _Src = (ushort *)(psVar3 + 0x14);
      *(undefined8 *)(param_1 + 0x48) = *(undefined8 *)(psVar3 + 0x10);
      for (uVar4 = 0; uVar4 < param_5; uVar4 = uVar4 + 1) {
        uVar1 = *_Src;
        _Dst = (void *)ExAllocatePool2(0x40,(ulonglong)uVar1);
        *(void **)(param_4 + 8 + (ulonglong)uVar4 * 0x10) = _Dst;
        if (_Dst == (void *)0x0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0x10,
                             &WPP_93f6b87810f63f9db566694056813e32_Traceguids);
          }
          uVar7 = 0;
          uVar5 = 0xa0000005;
          param_2 = (void *)0x0;
          uVar2 = 0xc000009a;
          uVar4 = 0;
          uVar6 = 0x50534349;
          goto LAB_140028107;
        }
        memmove(_Dst,_Src,(ulonglong)uVar1);
        _Src = (ushort *)((longlong)_Src + (ulonglong)uVar1);
      }
    }
    ExFreePoolWithTag(psVar3,0x43627355);
  }
  return uVar2;
}



===== TerminateIdleTimer @ 140028238 =====

void TerminateIdleTimer(longlong param_1)

{
  undefined4 uVar1;
  
  AcquireMutex(param_1 + 0x388,"idleTimerStateMutex",*(undefined8 *)(param_1 + 0x560));
  uVar1 = *(undefined4 *)(param_1 + 0x358);
  *(undefined4 *)(param_1 + 0x358) = 4;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qLL(*(undefined8 *)(param_1 + 0x560),4,7,0x41,
                        &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,
                        (char)*(undefined8 *)(param_1 + 0x20),(char)uVar1,4);
  }
  StopIdleTimer(param_1);
  KeReleaseMutex(param_1 + 0x388,0);
  return;
}



===== SetFunctionHandleData @ 1400282e0 =====

void SetFunctionHandleData(longlong param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined8 local_18;
  
  local_24 = 0;
  lVar3 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x28) >> 8),
                                 *(undefined1 *)(*(longlong *)(param_1 + 0x28) + 0x4c)),0);
  if (lVar3 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(param_2 + 0x188),2,8,0x3a,
                        &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,0x9a);
    }
  }
  else {
    local_18 = *(undefined8 *)(param_2 + 0xe0);
    local_28 = 0x180100;
    *(undefined4 **)(lVar3 + 0x18) = &local_28;
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(undefined1 *)(lVar1 + -0x48) = 0xf;
    *(undefined4 *)(lVar1 + -0x30) = 0x49104f;
    local_20 = param_3;
    iVar2 = CallDriverSync(*(undefined8 *)(param_1 + 0x28),lVar3,'\0',
                           *(undefined8 *)(param_1 + 0x20));
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(param_2 + 0x188),2,8,0x3b,
                          &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,(char)iVar2);
      }
    }
    else {
      *(undefined8 *)(param_2 + 0x178) = param_3;
    }
    IoFreeIrp(lVar3);
  }
  return;
}



===== UnregisterCompositeDevice @ 140028418 =====

void UnregisterCompositeDevice(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x28) >> 8),
                                 *(undefined1 *)(*(longlong *)(param_1 + 0x28) + 0x4c)),0);
  if (lVar3 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0x4c,
                        &WPP_93f6b87810f63f9db566694056813e32_Traceguids,0x9a);
    }
  }
  else {
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(undefined1 *)(lVar1 + -0x48) = 0xf;
    *(undefined4 *)(lVar1 + -0x30) = 0x490007;
    iVar2 = CallDriverSync(*(undefined8 *)(param_1 + 0x28),lVar3,'\0',
                           *(undefined8 *)(param_1 + 0x20));
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0x4d,
                          &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)iVar2);
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x559) = 0;
    }
    IoFreeIrp(lVar3);
  }
  return;
}



===== PauseIdleTimer @ 140028510 =====

void PauseIdleTimer(longlong param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x568) != '\x01') {
    AcquireMutex(param_1 + 0x388,"idleTimerStateMutex",*(undefined8 *)(param_1 + 0x560));
    iVar1 = *(int *)(param_1 + 0x358);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qL(*(undefined8 *)(param_1 + 0x560),4,7,0x3c,
                         &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,
                         (char)*(undefined8 *)(param_1 + 0x20),(char)iVar1);
    }
    if ((iVar1 == 1) && (*(char *)(param_1 + 0x35c) == '\0')) {
      *(undefined4 *)(param_1 + 0x358) = 3;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qLL(*(undefined8 *)(param_1 + 0x560),4,7,0x3d,
                            &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,
                            (char)*(undefined8 *)(param_1 + 0x20),1,3);
      }
      StopIdleTimer(param_1);
    }
    KeReleaseMutex(param_1 + 0x388,0);
  }
  return;
}



===== CallNextDriverSync @ 140028630 =====

void CallNextDriverSync(longlong param_1,longlong param_2,char param_3)

{
  CallDriverSync(*(undefined8 *)(param_1 + 0x28),param_2,param_3,*(undefined8 *)(param_1 + 0x20));
  return;
}



===== StopIdleTimer @ 140028650 =====

void StopIdleTimer(longlong param_1)

{
  if (*(char *)(param_1 + 0x568) != '\x01') {
    KeCancelTimer(param_1 + 0x2c0);
    KeFlushQueuedDpcs();
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),4,2,0x34,
                       &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids);
    }
    WaitForSignal(param_1 + 0x300,"noIdleDpcPendingEvent (wait for DPC to complete)",
                  *(undefined8 *)(param_1 + 0x560));
  }
  return;
}



===== USBC_PnP @ 1400286f0 =====

void USBC_PnP(longlong param_1,longlong param_2,IMAGE_DOS_HEADER *param_3)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined8 in_stack_ffffffffffffffc8;
  undefined1 uVar4;
  undefined1 uVar5;
  
  cVar1 = *(char *)(*(longlong *)(param_2 + 0xb8) + 1);
  if (*(char *)(param_1 + 4) == '\0') {
    if (cVar1 == '\x16') {
switchD_140028874_caseD_7:
      if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
         (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) goto LAB_1400287cd;
      uVar5 = (undefined1)*(undefined4 *)(param_1 + 0x18);
      uVar3 = 0x11;
      uVar4 = (undefined1)*(undefined4 *)(param_1 + 0x1c);
      bVar2 = 5;
    }
    else {
      param_3 = &IMAGE_DOS_HEADER_140000000;
      switch(cVar1) {
      case '\a':
      case '\b':
      case '\t':
      case '\n':
      case '\v':
      case '\r':
      case '\x15':
      case '\x18':
      case '\x19':
        goto switchD_140028874_caseD_7;
      default:
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1400287cd;
        uVar5 = (undefined1)*(undefined4 *)(param_1 + 0x18);
        uVar3 = 0x12;
        uVar4 = (undefined1)*(undefined4 *)(param_1 + 0x1c);
        bVar2 = 4;
      }
    }
    WPP_RECORDER_SF_qcqLL
              (*(undefined8 *)(param_1 + 400),bVar2,param_3,uVar3,in_stack_ffffffffffffffc8,
               (char)*(undefined8 *)(param_1 + 0xe8),cVar1,(char)param_2,uVar4,uVar5);
LAB_1400287cd:
    DispatchPdoPnp(param_1 + 8,param_2);
    return;
  }
  if (cVar1 == '\x16') {
switchD_14002882d_caseD_7:
    if (((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) ||
       (*(short *)(WPP_GLOBAL_Control + 0x48) == 0)) goto LAB_14002873d;
    uVar5 = (undefined1)*(undefined4 *)(param_1 + 0xc);
    uVar3 = 0xf;
    uVar4 = (undefined1)*(undefined4 *)(param_1 + 0x14);
    bVar2 = 5;
  }
  else {
    param_3 = &IMAGE_DOS_HEADER_140000000;
    switch(cVar1) {
    case '\a':
    case '\b':
    case '\t':
    case '\v':
    case '\r':
    case '\x14':
      goto switchD_14002882d_caseD_7;
    default:
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002873d;
      uVar5 = (undefined1)*(undefined4 *)(param_1 + 0xc);
      uVar3 = 0x10;
      uVar4 = (undefined1)*(undefined4 *)(param_1 + 0x14);
      bVar2 = 4;
    }
  }
  WPP_RECORDER_SF_qcqLL
            (*(undefined8 *)(param_1 + 0x568),bVar2,param_3,uVar3,in_stack_ffffffffffffffc8,
             (char)*(undefined8 *)(param_1 + 0x28),cVar1,(char)param_2,uVar4,uVar5);
LAB_14002873d:
  DispatchFdoPnp(param_1 + 8,param_2,param_3);
  return;
}



===== DispatchFdoPnp @ 1400288c0 =====

ulonglong DispatchFdoPnp(longlong param_1,longlong param_2,undefined8 param_3)

{
  uint *puVar1;
  char cVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  IMAGE_DOS_HEADER *pIVar10;
  longlong lVar11;
  undefined *in_stack_ffffffffffffff98;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  uVar9 = 0;
  cVar2 = *(char *)(lVar3 + 1);
  if (*(int *)(param_1 + 4) != 1) {
    if (cVar2 == '\a') {
      if (*(int *)(lVar3 + 8) == 0) goto LAB_140028acf;
    }
    else if (cVar2 != '\t') {
LAB_140028acf:
      lVar11 = param_2;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        lVar11 = CONCAT71((int7)((ulonglong)param_2 >> 8),4);
        WPP_RECORDER_SF_qc(*(undefined8 *)(param_1 + 0x560),4,param_3,10,in_stack_ffffffffffffff98,
                           (char)*(undefined8 *)(param_1 + 0x20),cVar2);
      }
      in_stack_ffffffffffffff98 = (undefined *)0x0;
      param_3 = 0;
      uVar8 = ParentSetD0(param_1,CONCAT71((int7)((ulonglong)lVar11 >> 8),1),0,0,0);
      if (((int)uVar8 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        in_stack_ffffffffffffff98 = &WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids;
        param_3 = 8;
        WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0xb,
                          &WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,(char)uVar8);
      }
    }
  }
  if (cVar2 == '\t') {
    puVar4 = *(undefined8 **)(param_2 + 0xb8);
    puVar4[-9] = *puVar4;
    puVar4[-8] = puVar4[1];
    puVar4[-7] = puVar4[2];
    puVar4[-6] = puVar4[3];
    puVar4[-5] = puVar4[4];
    puVar4[-4] = puVar4[5];
    puVar4[-3] = puVar4[6];
    *(undefined1 *)((longlong)puVar4 + -0x45) = 0;
    uVar5 = *(undefined8 *)(param_1 + 0x20);
    uVar6 = *(undefined8 *)(param_1 + 0x28);
    local_28 = 0;
    local_38 = 0;
    uStack_30 = 0;
    KeInitializeEvent(&local_38,0,0);
    SetCompletionRoutine(g_RecorderLog,uVar5,param_2,USBD_SyncCompletionRoutine,&local_38);
    uVar7 = IofCallDriver(uVar6,param_2);
    if (uVar7 == 0x103) {
      WaitForSignal(&local_38,"event (waiting for sent irp to complete)",g_RecorderLog);
LAB_1400289ce:
      uVar7 = *(uint *)(param_2 + 0x30);
    }
    else if (-1 < (int)uVar7) goto LAB_1400289ce;
    uVar9 = (ulonglong)uVar7;
    if (-1 < (int)uVar7) {
      puVar1 = (uint *)(*(longlong *)(lVar3 + 8) + 4);
      *puVar1 = *puVar1 | 0x200;
    }
LAB_1400289dc:
    UsbcCompleteIrp(param_1,uVar7,param_2);
    goto LAB_1400289e7;
  }
  if (cVar2 == '\x01') goto LAB_140028a3c;
  pIVar10 = &IMAGE_DOS_HEADER_140000000;
  switch(cVar2) {
  case '\0':
    uVar9 = StartParentFdo(param_1,param_2);
    uVar9 = uVar9 & 0xffffffff;
    goto LAB_1400289e7;
  default:
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_qc(*(undefined8 *)(param_1 + 0x560),5,param_3,0xc,in_stack_ffffffffffffff98,
                         (char)*(undefined8 *)(param_1 + 0x20),cVar2);
    }
    goto LAB_140028a40;
  case '\x02':
    uVar7 = FdoRemoveDevice(param_1,param_2);
    uVar9 = (ulonglong)uVar7;
    goto LAB_1400289e7;
  case '\x04':
    HandleFdoStop(param_1,param_2);
    goto LAB_140028a40;
  case '\x05':
    *(undefined4 *)(param_1 + 0xc) = 4;
    DisableIdleTimer(param_1,&IMAGE_DOS_HEADER_140000000,0x504f5453);
    CancelFdoIdleIrp(param_1,CONCAT71((int7)((ulonglong)pIVar10 >> 8),1));
    break;
  case '\x06':
    if (*(int *)(param_1 + 0xc) == 4) {
      EnableIdleTimer(param_1,'\x01',0x504f5453);
    }
    *(undefined4 *)(param_1 + 0xc) = 2;
    break;
  case '\a':
    uVar9 = QueryParentDeviceRelations(param_1,param_2);
    uVar9 = uVar9 & 0xffffffff;
    goto LAB_1400289e7;
  case '\x16':
    HandleFdoDeviceUsageNotification(param_1,param_2);
    uVar7 = 0;
    goto LAB_1400289dc;
  case '\x17':
    if (*(char *)(param_1 + 0x559) != '\0') {
      UnregisterCompositeDevice(param_1);
    }
  }
LAB_140028a3c:
  *(undefined4 *)(param_2 + 0x30) = 0;
LAB_140028a40:
  uVar7 = UsbcForwardIrpWithCompletion
                    (param_1,*(undefined8 *)(param_1 + 0x28),param_2,USBC_PnpComplete,
                     *(undefined8 *)(param_1 + 0x20),param_1);
  uVar9 = (ulonglong)uVar7;
LAB_1400289e7:
  if (((((cVar2 == '\0') || (cVar2 == '\x02')) || (cVar2 == '\x04')) ||
      ((cVar2 == '\x05' || (cVar2 == '\x06')))) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_qcqd(*(undefined8 *)(param_1 + 0x560));
  }
  return uVar9;
}



===== CallDriverSync @ 140028c84 =====

int CallDriverSync(undefined8 param_1,longlong param_2,char param_3,undefined8 param_4)

{
  char cVar1;
  int iVar2;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  
  local_20 = 0;
  uStack_18 = 0;
  local_10 = 0;
  KeInitializeEvent(&local_20,0,0);
  SetCompletionRoutine(g_RecorderLog,param_4,param_2,USBD_SyncCompletionRoutine,&local_20);
  iVar2 = IofCallDriver(param_1,param_2);
  if (iVar2 == 0x103) {
    if (param_3 == '\0') {
      WaitForSignal(&local_20,"event (waiting for sent irp to complete)",g_RecorderLog);
      goto LAB_140028d58;
    }
    local_28 = 0xfffffffffd050f80;
    iVar2 = KeWaitForSingleObject(&local_20,0,0,0,&local_28);
    if (iVar2 == 0x102) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(g_RecorderLog,2,8,10,&WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids,0x88
                         );
      }
      DbgPrint("USBCCGP: CallDriverSync timed out after %d ms\n",5000);
      cVar1 = IoCancelIrp(param_2);
      if (cVar1 != '\0') {
        iVar2 = -0x3fffffff;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000001;
      }
      WaitForSignal(&local_20,"event (waiting for canceled irp to complete)",g_RecorderLog);
    }
  }
  if (iVar2 < 0) {
    return iVar2;
  }
LAB_140028d58:
  return *(int *)(param_2 + 0x30);
}



===== WaitForSignal @ 140028e04 =====

void WaitForSignal(undefined8 param_1,char *param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  void *pvVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined8 local_res20;
  undefined8 *puVar7;
  
  local_res20 = 0xffffffffdc3cba00;
  puVar7 = &local_res20;
  uVar5 = 0;
  uVar2 = 0;
  uVar4 = 0;
  iVar1 = KeWaitForSingleObject();
  while (iVar1 == 0x102) {
    uVar4 = uVar4 + 1;
    uVar6 = (ulonglong)uVar4;
    pvVar3 = SystemReserved1[0xf];
    DbgPrint("\nUSBCCGP Watchdog: Thread 0x%p has waited %d minutes for %s to be signalled\n",
             SystemReserved1[0xf],uVar6,param_2);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qds(param_3,pvVar3,uVar6,0x3d,puVar7,(char)SystemReserved1[0xf],(char)uVar4,
                          param_2);
    }
    puVar7 = &local_res20;
    uVar5 = 0;
    uVar2 = 0;
    iVar1 = KeWaitForSingleObject(param_1,0,0,0);
  }
  if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_dqs(param_3,uVar2,uVar5,0x3e,puVar7,(char)iVar1,(char)SystemReserved1[0xf],
                        param_2);
  }
  return;
}



===== DispatchPdoPnp @ 140028f20 =====

uint DispatchPdoPnp(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  byte bVar9;
  longlong lVar10;
  uint uVar11;
  undefined2 uVar12;
  char local_res8 [8];
  undefined8 in_stack_ffffffffffffffc8;
  
  lVar3 = *(longlong *)(param_1 + 0xe8);
  uVar4 = 0;
  bVar9 = *(byte *)(*(longlong *)(param_2 + 0xb8) + 1);
  uVar5 = (ulonglong)bVar9;
  uVar11 = (uint)bVar9;
  if (uVar11 < 10) {
    if (uVar11 == 9) {
      uVar6 = QueryFunctionCapabilities(param_1,param_2);
      uVar4 = (uint)uVar6;
      goto LAB_140029335;
    }
    if (bVar9 == 0) {
      lVar10 = param_1;
      ResetPdoExtension(lVar3,param_1);
      CancelFdoIdleIrp(lVar3,CONCAT71((int7)((ulonglong)lVar10 >> 8),1));
      iVar2 = *(int *)(param_1 + 0x14);
      *(int *)(param_1 + 0x18) = iVar2;
      *(undefined4 *)(param_1 + 0x14) = 2;
      if (iVar2 == 0) {
        local_res8[0] = '\0';
        uVar5 = GetD3Policy(*(undefined8 *)(param_1 + 0xe0),local_res8);
        if ((-1 < (int)uVar5) && (local_res8[0] == '\x01')) {
          AcquireMutex(lVar3 + 0x208,"D3ColdStateMutex",*(undefined8 *)(lVar3 + 0x560));
          *(undefined1 *)(param_1 + 0x75) = 1;
          if (*(char *)(lVar3 + 0x1b9) != '\0') {
            ChangeParentD3ColdStateLocked(lVar3);
          }
          KeReleaseMutex(lVar3 + 0x208,0);
        }
      }
      if ((*(char *)(lVar3 + 0x55a) != '\0') &&
         (*(char *)(*(longlong *)(param_1 + 0x180) + 0x3b) != '\0')) {
        LockSyncSendSetFeatureControlRequestForFunctionSuspend(lVar3,param_1,2);
      }
      uVar4 = 0;
      goto LAB_140029335;
    }
    if (uVar11 == 1) goto LAB_140029335;
    uVar5 = (ulonglong)(uVar11 - 2);
    if (uVar11 - 2 == 0) {
      lVar10 = param_2;
      if (*(undefined **)(param_1 + 0x1a0) != (undefined *)0x0) {
        SleepstudyHelper_UnregisterComponent(*(undefined **)(param_1 + 0x1a0));
        *(undefined8 *)(param_1 + 0x1a0) = 0;
      }
      uVar6 = PdoRemoveDevice(param_1,lVar10,uVar5);
      uVar4 = (uint)uVar6;
      goto LAB_140029335;
    }
    if (uVar11 == 3) goto LAB_140029335;
    if (uVar11 == 4) {
      if (*(int *)(param_1 + 0x14) == 2) {
        *(undefined4 *)(param_1 + 0x18) = 2;
        *(undefined4 *)(param_1 + 0x14) = 6;
      }
      goto LAB_140029335;
    }
    if ((uVar11 == 5) || (uVar11 == 6)) goto LAB_140029335;
    uVar11 = uVar11 - 7;
    if (uVar11 == 0) {
      uVar4 = QueryFunctionDeviceRelations(param_1,param_2);
      goto LAB_140029335;
    }
    if (uVar11 == 1) {
      uVar5 = HandlePdoQueryInterface(param_1,param_2);
      return (uint)uVar5;
    }
LAB_140029123:
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_qc(*(undefined8 *)(param_1 + 0x188),5,(ulonglong)uVar11,0x27,
                         in_stack_ffffffffffffffc8,(char)*(undefined8 *)(param_1 + 0xe0),bVar9);
    }
    uVar4 = *(uint *)(param_2 + 0x30);
    goto LAB_140029335;
  }
  if (uVar11 == 0xb) {
    InstallExtPropDesc(param_1);
    QuerySelectiveSuspendRegistryFlag(param_1);
    QueryAllowIdleIrpInD3RegistryFlag(param_1);
    QueryEndpointPriorities(param_1);
    goto LAB_140029335;
  }
  if (uVar11 == 0xc) {
    uVar4 = GetDeviceText(param_1,param_2);
    goto LAB_140029335;
  }
  if (uVar11 == 0x13) {
    uVar4 = QueryFunctionPdoID(param_1,param_2);
    goto LAB_140029335;
  }
  if (uVar11 == 0x14) {
    if (((*(char *)(lVar3 + 0x568) == '\x01') && (*(char *)(param_1 + 0x197) == '\x01')) ||
       (iVar2 = *(int *)(param_1 + 0x14), iVar2 == 3)) {
      *(ulonglong *)(param_2 + 0x38) = *(ulonglong *)(param_2 + 0x38) | 4;
    }
    else if (iVar2 == 6) {
      *(ulonglong *)(param_2 + 0x38) = *(ulonglong *)(param_2 + 0x38) | 1;
    }
    else if ((iVar2 == 7) || (iVar2 == 8)) {
      *(ulonglong *)(param_2 + 0x38) = *(ulonglong *)(param_2 + 0x38) | 8;
    }
    goto LAB_140029335;
  }
  if (uVar11 == 0x15) {
    uVar6 = 0x100;
    if (ExDefaultNonPagedPoolType == 1) {
      uVar6 = 0x40;
    }
    puVar8 = (undefined8 *)ExAllocatePool2(uVar6,0x18,0x43627355);
    if (puVar8 == (undefined8 *)0x0) {
      uVar4 = 0xc000009a;
      puVar8 = (undefined8 *)0x0;
    }
    else {
      puVar8[2] = 0xf;
      *puVar8 = 0x11d1c85d9d7debbc;
      puVar8[1] = 0x9aa1c3086000b49e;
    }
    *(undefined8 **)(param_2 + 0x38) = puVar8;
    goto LAB_140029335;
  }
  if (uVar11 == 0x16) {
    uVar4 = HandlePdoDeviceUsageNotification(param_1,param_2);
    return uVar4;
  }
  uVar11 = uVar11 - 0x17;
  if (uVar11 == 0) {
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 0x14) = 9;
    goto LAB_140029335;
  }
  if (uVar11 != 2) goto LAB_140029123;
  uVar7 = Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar7 == 0) {
    plVar1 = (longlong *)(param_1 + 0x1a0);
    if (*plVar1 != 0) goto LAB_140029335;
    uVar6 = SleepstudyHelper_RegisterPdoWithParentPdo
                      (uVar5,*(undefined8 *)(lVar3 + 0x18),*(undefined8 *)(param_1 + 0xe0),plVar1);
    uVar4 = (uint)uVar6;
    if (-1 < (int)uVar4) goto LAB_1400291f6;
    *plVar1 = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140029335;
    uVar12 = 0x26;
    bVar9 = 2;
  }
  else {
    if ((g_SleepstudyLibraryHandle == 0) || (plVar1 = (longlong *)(param_1 + 0x1a0), *plVar1 != 0))
    goto LAB_140029335;
    uVar6 = SleepstudyHelper_RegisterPdoWithParentPdo
                      (uVar5,*(undefined8 *)(lVar3 + 0x18),*(undefined8 *)(param_1 + 0xe0),plVar1);
    uVar4 = (uint)uVar6;
    if (-1 < (int)uVar4) {
LAB_1400291f6:
      SleepstudyHelper_ComponentActive(*(undefined **)(param_1 + 0x1a0));
      goto LAB_140029335;
    }
    *plVar1 = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140029335;
    uVar12 = 0x25;
    bVar9 = 3;
  }
  WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x188),bVar9,8,uVar12,
                    &WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,(char)uVar4);
LAB_140029335:
  UsbcCompleteIrp(lVar3,uVar4,param_2);
  return uVar4;
}



===== QueryParentDeviceRelations @ 140029364 =====

ulonglong QueryParentDeviceRelations(longlong param_1,longlong param_2)

{
  uint uVar1;
  uint *puVar2;
  longlong lVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  longlong lVar10;
  uint local_res18;
  
  uVar9 = 0;
  if (*(int *)(*(longlong *)(param_2 + 0xb8) + 8) == 0) {
    if (*(longlong *)(param_1 + 0x80) == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,0x35,
                         &WPP_93f6b87810f63f9db566694056813e32_Traceguids);
      }
      uVar5 = 0xc000009c;
    }
    else {
      puVar2 = *(uint **)(param_2 + 0x38);
      if ((puVar2 != (uint *)0x0) &&
         (uVar9 = *puVar2, (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),4,2,0x36,
                          &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)uVar9);
      }
      uVar1 = **(uint **)(param_1 + 0x80);
      uVar6 = 0x100;
      if (ExDefaultNonPagedPoolType == 1) {
        uVar6 = 0x40;
      }
      puVar4 = (undefined4 *)ExAllocatePool2(uVar6,(uVar1 + uVar9) * 8 + 8,0x43627355);
      if (puVar4 != (undefined4 *)0x0) {
        uVar5 = 0;
        if ((puVar2 != (uint *)0x0) && (uVar9 != 0)) {
          puVar7 = puVar2;
          do {
            puVar7 = puVar7 + 2;
            if (*(longlong *)puVar7 == 0) break;
            *(longlong *)(puVar4 + uVar5 * 2 + 2) = *(longlong *)puVar7;
            uVar8 = (int)uVar5 + 1;
            uVar5 = (ulonglong)uVar8;
          } while (uVar8 < uVar9);
        }
        local_res18 = 0;
        if (uVar1 != 0) {
          lVar10 = 0;
          do {
            lVar3 = *(longlong *)(lVar10 + 8 + *(longlong *)(param_1 + 0x80));
            if (lVar3 == 0) break;
            *(longlong *)(puVar4 + uVar5 * 2 + 2) = lVar3;
            *(uint *)(lVar3 + 0x30) = *(uint *)(lVar3 + 0x30) & 0xffffff7f;
            ObfReferenceObject(*(undefined8 *)(puVar4 + uVar5 * 2 + 2));
            uVar5 = (ulonglong)((int)uVar5 + 1);
            local_res18 = local_res18 + 1;
            lVar10 = lVar10 + 8;
          } while (local_res18 < uVar1);
        }
        *puVar4 = (int)uVar5;
        *(undefined4 **)(param_2 + 0x38) = puVar4;
        if (puVar2 != (uint *)0x0) {
          ExFreePoolWithTag(puVar2,0);
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),4,2,0x37,
                            &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)(uVar1 + uVar9));
        }
        *(undefined4 *)(param_2 + 0x30) = 0;
        uVar6 = *(undefined8 *)(param_1 + 0x28);
        goto LAB_1400294a9;
      }
      uVar5 = 0xc000009a;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_L(*(undefined8 *)(param_1 + 0x560),2,8,0x38,
                        &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)uVar5);
    }
    UsbcCompleteIrp(param_1,(int)uVar5,param_2);
  }
  else {
    uVar6 = *(undefined8 *)(param_1 + 0x28);
LAB_1400294a9:
    uVar5 = UsbcForwardIrp(param_1,uVar6,param_2);
    uVar5 = uVar5 & 0xffffffff;
  }
  return uVar5;
}



===== TryGetConfigDescriptor @ 1400295f8 =====

int TryGetConfigDescriptor
              (longlong param_1,undefined1 param_2,undefined1 *param_3,uint *param_4,uint *param_5)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  ushort uVar6;
  ulonglong uVar7;
  undefined2 uVar8;
  undefined2 *local_res8;
  undefined1 local_res10;
  longlong local_res18;
  longlong local_48;
  ulonglong uStack_40;
  
  local_res8 = (undefined2 *)0x0;
  local_res18 = 0;
  uVar6 = 2;
  lVar4 = 0;
  local_res10 = param_2;
  if (*(longlong *)(param_1 + 0x30) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x30),0x43627355);
    *(undefined8 *)(param_1 + 0x30) = 0;
  }
  lVar5 = *(longlong *)(param_1 + 0x548);
  *param_3 = 0;
  *param_4 = 0;
  *param_5 = 0;
  iVar2 = USBD_UrbAllocate(lVar5,&local_res8);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140029759;
    uVar8 = 0x13;
  }
  else {
    lVar4 = ExAllocatePool2(0x40,9,0x43627355);
    if (lVar4 == 0) {
      iVar2 = -0x3fffff66;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140029759;
      uVar8 = 0x14;
LAB_1400299b4:
      iVar2 = -0x3fffff66;
    }
    else {
      local_res8[1] = 0xb;
      *local_res8 = 0x88;
      *(undefined4 *)(local_res8 + 0x12) = 9;
      *(longlong *)(local_res8 + 0x14) = lVar4;
      *(undefined8 *)(local_res8 + 0x18) = 0;
      *(undefined1 *)((longlong)local_res8 + 0x83) = 2;
      *(undefined1 *)(local_res8 + 0x41) = param_2;
      local_res8[0x42] = 0;
      *(undefined8 *)(local_res8 + 0x1c) = 0;
      iVar2 = SubmitUrb(param_1,local_res8);
      if (iVar2 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_140029759;
        uVar8 = 0x15;
      }
      else {
        uVar1 = *(ushort *)(lVar4 + 2);
        if ((uVar1 < 9) || (*(uint *)(local_res8 + 0x12) < 9)) {
          iVar2 = -0x3fffff64;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140029759;
          uVar8 = 0x16;
        }
        else {
          lVar5 = ExAllocatePool2(0x40,uVar1,0x43627355);
          *(longlong *)(param_1 + 0x30) = lVar5;
          if (lVar5 == 0) {
            iVar2 = -0x3fffff66;
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_140029759;
            uVar8 = 0x17;
            goto LAB_1400299b4;
          }
          uVar3 = (uint)uVar1;
          *param_5 = uVar3;
          local_res8[1] = 0xb;
          *local_res8 = 0x88;
          *(uint *)(local_res8 + 0x12) = uVar3;
          *(undefined8 *)(local_res8 + 0x14) = *(undefined8 *)(param_1 + 0x30);
          *(undefined8 *)(local_res8 + 0x18) = 0;
          *(undefined1 *)((longlong)local_res8 + 0x83) = 2;
          *(undefined1 *)(local_res8 + 0x41) = local_res10;
          local_res8[0x42] = 0;
          *(undefined8 *)(local_res8 + 0x1c) = 0;
          iVar2 = SubmitUrb(param_1,local_res8);
          if (iVar2 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0x18,
                                &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)iVar2);
            }
            *param_4 = *(uint *)(local_res8 + 2);
            goto LAB_140029759;
          }
          if (uVar3 <= *(uint *)(local_res8 + 0x12)) {
            if ((*(uint *)(param_1 + 0x4d0) & 4) == 0) {
              if ((*(uint *)(param_1 + 0x4d0) & 8) != 0) {
                uVar6 = 1;
              }
            }
            else {
              uVar6 = 3;
            }
            uVar7 = (ulonglong)uVar6;
            uVar3 = USBD_ValidateConfigurationDescriptorInternal
                              (*(ushort **)(param_1 + 0x30),uVar3,uVar6,&local_res18);
            *param_4 = uVar3;
            if ((int)uVar3 < 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_Dd(*(undefined8 *)(param_1 + 0x560),(ulonglong)uVar3,8,0x1a,
                                   &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)uVar3,
                                   (char)local_res18 - (char)*(undefined4 *)(param_1 + 0x30));
              }
              iVar2 = -0x3fffff64;
              *param_3 = 1;
            }
            else {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                local_48 = *(longlong *)(param_1 + 0x30);
                uStack_40 = (ulonglong)*(ushort *)(local_48 + 2);
                WPP_RECORDER_SF__HEX_
                          (*(undefined8 *)(param_1 + 0x560),(ulonglong)uVar3,uVar7,0x1b,
                           &WPP_93f6b87810f63f9db566694056813e32_Traceguids,&local_48);
              }
              *(undefined8 *)(param_1 + 0x38) = *(undefined8 *)(param_1 + 0x30);
            }
            goto LAB_140029759;
          }
          iVar2 = -0x3fffff64;
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_140029759;
          uVar8 = 0x19;
        }
      }
    }
  }
  WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,uVar8,
                    &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)iVar2);
LAB_140029759:
  if (local_res8 != (undefined2 *)0x0) {
    USBD_UrbFree(*(longlong *)(param_1 + 0x548),(longlong)local_res8);
  }
  if (lVar4 != 0) {
    ExFreePoolWithTag(lVar4,0x43627355);
  }
  return iVar2;
}



===== FreeFunctionPDOResources @ 140029a90 =====

void FreeFunctionPDOResources(longlong param_1)

{
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qd(*(undefined8 *)(param_1 + 0x188),4,2,0x2d,
                       &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,
                       (char)*(undefined8 *)(param_1 + 0xe0),(char)*(undefined4 *)(param_1 + 4));
  }
  FreeResourcesForFunctionSuspend(param_1);
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x14) = 10;
  UsbcDereferencePdo(param_1);
  WaitForSignal(param_1 + 0x138,"removeEvent",*(undefined8 *)(param_1 + 0x188));
  IoDeleteDevice(*(undefined8 *)(param_1 + 0xe0));
  return;
}



===== FreeResourcesForFunctionSuspend @ 140029b50 =====

void FreeResourcesForFunctionSuspend(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x180);
  if (lVar1 != 0) {
    if (*(longlong *)(lVar1 + 8) != 0) {
      IoFreeWorkItem();
      *(undefined8 *)(lVar1 + 8) = 0;
    }
    if (*(longlong *)(lVar1 + 0x28) != 0) {
      IoFreeIrp();
      *(undefined8 *)(lVar1 + 0x28) = 0;
    }
    if (*(longlong *)(lVar1 + 0x50) != 0) {
      IoFreeWorkItem();
      *(undefined8 *)(lVar1 + 0x50) = 0;
    }
    if (*(longlong *)(lVar1 + 0x48) != 0) {
      IoFreeIrp();
      *(undefined8 *)(lVar1 + 0x48) = 0;
    }
    if (*(longlong *)(lVar1 + 0x40) != 0) {
      USBD_UrbFree(*(longlong *)(*(longlong *)(param_1 + 0xe8) + 0x548),*(longlong *)(lVar1 + 0x40))
      ;
      *(undefined8 *)(lVar1 + 0x40) = 0;
    }
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x180),0x43627355);
    *(undefined8 *)(param_1 + 0x180) = 0;
  }
  return;
}



===== FdoRemoveDevice @ 140029c28 =====

undefined4 FdoRemoveDevice(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qq(*(undefined8 *)(param_1 + 0x560),4,2,0x28,
                       &WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,
                       (char)*(undefined8 *)(param_1 + 0x20),(char)param_2);
  }
  PrepareParentFDOForRemove(param_1,param_2);
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  uVar1 = IofCallDriver(*(undefined8 *)(param_1 + 0x28),param_2);
  IoDetachDevice(*(undefined8 *)(param_1 + 0x28));
  FreeParentFDOResources(param_1);
  return uVar1;
}



===== FreeParentFDOResources @ 140029cdc =====

void FreeParentFDOResources(longlong param_1)

{
  ulonglong uVar1;
  
  *(undefined4 *)(param_1 + 0xc) = 8;
  FreeInterfaceList(param_1,'\x01');
  if (*(longlong *)(param_1 + 0x80) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x80),0x43627355);
  }
  *(undefined8 *)(param_1 + 0x80) = 0;
  if (*(longlong *)(param_1 + 0x30) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x30),0x43627355);
  }
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined1 *)(param_1 + 0x40) = 0;
  if (*(longlong *)(param_1 + 0x460) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x460),0x43627355);
  }
  *(undefined8 *)(param_1 + 0x460) = 0;
  if (*(longlong *)(param_1 + 0x468) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x468),0x43627355);
  }
  *(undefined8 *)(param_1 + 0x468) = 0;
  uVar1 = Feature_1916511546__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar1 != 0) {
    *(undefined4 *)(param_1 + 0x470) = 0;
  }
  if (*(longlong *)(param_1 + 0x478) != 0) {
    CleanFunctionList(*(longlong *)(param_1 + 0x478),*(uint *)(param_1 + 0x74));
  }
  *(undefined8 *)(param_1 + 0x478) = 0;
  if (*(longlong *)(param_1 + 0x290) != 0) {
    IoFreeIrp();
  }
  *(undefined8 *)(param_1 + 0x290) = 0;
  if (*(longlong *)(param_1 + 0x480) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x480),0x43627355);
  }
  *(undefined8 *)(param_1 + 0x480) = 0;
  if (g_RecorderLog != *(longlong *)(param_1 + 0x560)) {
    imp_WppRecorderLogDelete(WPP_GLOBAL_Control);
    *(undefined8 *)(param_1 + 0x560) = 0;
  }
  if (*(longlong *)(param_1 + 0x550) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x550),0x43627355);
    *(undefined8 *)(param_1 + 0x550) = 0;
  }
  if (*(longlong *)(param_1 + 0x288) != 0) {
    IoFreeWorkItem();
    *(undefined8 *)(param_1 + 0x288) = 0;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),4,2,0x25,
                     &WPP_93f6b87810f63f9db566694056813e32_Traceguids);
  }
  IoDeleteDevice(*(undefined8 *)(param_1 + 0x20));
  return;
}



===== RegisterCompositeDevice @ 140029eb8 =====

void RegisterCompositeDevice(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  USBD_BuildRegisterCompositeDevice
            (*(longlong *)(param_1 + 0x548),*(byte *)(param_1 + 0x55a) & 1,
             *(undefined4 *)(param_1 + 0x74),(undefined4 *)&local_28);
  lVar3 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x28) >> 8),
                                 *(undefined1 *)(*(longlong *)(param_1 + 0x28) + 0x4c)),0);
  if (lVar3 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0x4a,
                        &WPP_93f6b87810f63f9db566694056813e32_Traceguids,0x9a);
    }
  }
  else {
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    lVar4 = ExAllocatePool2(0x40,*(int *)(param_1 + 0x74) << 3);
    if (lVar4 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0x4b,
                          &WPP_93f6b87810f63f9db566694056813e32_Traceguids,0x9a);
      }
    }
    else {
      *(undefined1 *)(lVar1 + -0x48) = 0xf;
      *(undefined8 **)(lVar1 + -0x40) = &local_28;
      *(undefined4 *)(lVar1 + -0x30) = 0x490003;
      *(longlong *)(lVar3 + 0x18) = lVar4;
      iVar2 = CallDriverSync(*(undefined8 *)(param_1 + 0x28),lVar3,'\0',
                             *(undefined8 *)(param_1 + 0x20));
      if (iVar2 < 0) {
        ExFreePoolWithTag(lVar4,0x43627355);
      }
      else {
        *(undefined1 *)(param_1 + 0x559) = 1;
        *(longlong *)(param_1 + 0x550) = lVar4;
      }
    }
    IoFreeIrp(lVar3);
  }
  return;
}



===== IsFunctionRemoteWakeCapable @ 14002a04c =====

ulonglong IsFunctionRemoteWakeCapable(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  longlong lVar3;
  undefined4 *puVar4;
  undefined1 uVar5;
  int iVar6;
  undefined4 extraout_var;
  ulonglong uVar7;
  undefined1 *puVar8;
  undefined2 uVar9;
  ushort local_res8 [4];
  
  local_res8[0] = 0;
  puVar1 = (undefined8 *)(param_2 + 0x188);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_q(*puVar1,4,3,0x3c,&WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,
                      (char)*(undefined8 *)(param_2 + 0xe0));
  }
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0x180) + 0x48);
  puVar4 = *(undefined4 **)(*(longlong *)(param_2 + 0x180) + 0x40);
  IoReuseIrp(lVar3);
  *(undefined1 *)((longlong)puVar4 + 0x81) = 0;
  *(undefined2 *)((longlong)puVar4 + 0x82) = 0;
  *(byte *)(puVar4 + 0x20) = *(byte *)(puVar4 + 0x20) & 0x1c | 0x81;
  *(undefined2 *)((longlong)puVar4 + 0x86) = 2;
  *(ushort *)(puVar4 + 0x21) = (ushort)*(byte *)(param_2 + 8);
  *(undefined8 *)(puVar4 + 0xc) = 0;
  *(ushort **)(puVar4 + 10) = local_res8;
  *puVar4 = 0x320088;
  puVar4[8] = 0xb;
  puVar4[9] = 2;
  puVar4[0xe] = 5000;
  puVar8 = (undefined1 *)(*(longlong *)(lVar3 + 0xb8) + -0x48);
  *(undefined4 *)(*(longlong *)(lVar3 + 0xb8) + -0x30) = 0x220003;
  *puVar8 = 0xf;
  USBD_AssignUrbToIoStackLocation(*(longlong *)(param_1 + 0x548),(longlong)puVar8,puVar4);
  iVar6 = CallDriverSync(*(undefined8 *)(param_1 + 0x28),lVar3,'\x01',
                         *(undefined8 *)(param_1 + 0x20));
  uVar7 = CONCAT44(extraout_var,iVar6);
  if ((iVar6 < 0) || (puVar4[1] != 0)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002a213;
    uVar9 = 0x3d;
    uVar5 = (undefined1)*(undefined8 *)(param_2 + 0xe0);
  }
  else {
    uVar2 = puVar4[9];
    uVar7 = (ulonglong)uVar2;
    if (uVar2 != 2) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar7 = WPP_RECORDER_SF_d(*puVar1,2,3,0x3e,&WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,
                                  (char)uVar2);
      }
      goto LAB_14002a213;
    }
    if ((local_res8[0] & 1) != 0) {
      return 1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002a213;
    iVar6 = *(int *)(param_2 + 8);
    uVar9 = 0x3f;
    uVar5 = (undefined1)*(undefined8 *)(param_2 + 0xe0);
  }
  uVar7 = WPP_RECORDER_SF_qd(*puVar1,2,3,uVar9,&WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,
                             uVar5,(char)iVar6);
LAB_14002a213:
  return uVar7 & 0xffffffffffffff00;
}



===== GetPdoRegistryParameter @ 14002a238 =====

int GetPdoRegistryParameter
              (undefined8 param_1,undefined8 param_2,void *param_3,uint param_4,undefined4 *param_5,
              undefined4 *param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  
  local_38 = 0;
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = 0;
  }
  uVar5 = 2;
  if ((char)param_7 == '\0') {
    uVar5 = 1;
  }
  iVar1 = IoOpenDeviceRegistryKey(param_1,uVar5,0x1f0000,&local_38);
  if (-1 < iVar1) {
    param_7 = 0;
    local_30 = 0;
    uStack_28 = 0;
    RtlInitUnicodeString(&local_30,param_2);
    uVar5 = 0x100;
    if (ExDefaultNonPagedPoolType == 1) {
      uVar5 = 0x40;
    }
    lVar4 = ExAllocatePool2(uVar5,param_4 + 0xc,0x43627355);
    if (lVar4 == 0) {
      iVar1 = -0x3fffff66;
    }
    else {
      iVar2 = ZwQueryValueKey(local_38,&local_30,2,lVar4,param_4 + 0xc,&param_7);
      iVar1 = 0;
      if (iVar2 != -0x7ffffffb) {
        iVar1 = iVar2;
      }
      if (-1 < iVar1) {
        if (param_3 != (void *)0x0) {
          uVar3 = *(uint *)(lVar4 + 8);
          if (param_4 < *(uint *)(lVar4 + 8)) {
            uVar3 = param_4;
          }
          memmove(param_3,(void *)(lVar4 + 0xc),(ulonglong)uVar3);
        }
        if (param_5 != (undefined4 *)0x0) {
          *param_5 = *(undefined4 *)(lVar4 + 4);
        }
        if (param_6 != (undefined4 *)0x0) {
          *param_6 = *(undefined4 *)(lVar4 + 8);
        }
      }
      ExFreePoolWithTag(lVar4,0x43627355);
    }
    ZwClose(local_38);
  }
  return iVar1;
}



===== USBC_AddDevice @ 14002a3e0 =====

ulonglong USBC_AddDevice(undefined8 param_1,undefined8 param_2)

{
  undefined4 *puVar1;
  undefined4 *_Dst;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined4 *puVar7;
  undefined2 uVar8;
  undefined8 uVar9;
  longlong local_res18;
  undefined8 in_stack_ffffffffffffffb8;
  undefined4 uVar10;
  ulonglong in_stack_ffffffffffffffc0;
  
  local_res18 = 0;
  uVar6 = CONCAT44((int)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20),0x80);
  puVar7 = (undefined4 *)0x0;
  uVar2 = IoCreateDevice(param_1,0x578,0,0x22,uVar6,in_stack_ffffffffffffffc0 & 0xffffffffffffff00,
                         &local_res18);
  uVar10 = (undefined4)((ulonglong)uVar6 >> 0x20);
  uVar5 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    local_res18 = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002a743;
    uVar8 = 0x10;
    uVar6 = g_RecorderLog;
  }
  else {
    _Dst = *(undefined4 **)(local_res18 + 0x40);
    memset(_Dst,0,0x578);
    *(undefined8 *)(_Dst + 6) = param_1;
    *(undefined1 *)(_Dst + 1) = 1;
    *_Dst = 0x43627355;
    puVar7 = _Dst + 2;
    *puVar7 = 0x436f6446;
    *(undefined8 *)(_Dst + 8) = param_2;
    *(longlong *)(_Dst + 10) = local_res18;
    *(undefined8 *)(_Dst + 4) = 1;
    _Dst[3] = 1;
    AllocateDeviceIFRLog((longlong)puVar7);
    KeInitializeSpinLock(_Dst + 0x94);
    KeInitializeSpinLock(_Dst + 0x66);
    KeInitializeSpinLock(_Dst + 0xb0);
    KeInitializeSpinLock(_Dst + 0x16);
    KeInitializeSpinLock(_Dst + 0x42);
    KeInitializeMutex(_Dst + 0xe4,0);
    KeInitializeMutex(_Dst + 0x84,0);
    puVar1 = _Dst + 0x9a;
    *(undefined4 **)(_Dst + 0x9c) = puVar1;
    *(undefined4 **)puVar1 = puVar1;
    puVar1 = _Dst + 0xa0;
    *(undefined4 **)(_Dst + 0xa2) = puVar1;
    *(undefined4 **)puVar1 = puVar1;
    puVar1 = _Dst + 0x44;
    *(undefined4 **)(_Dst + 0x46) = puVar1;
    *(undefined4 **)puVar1 = puVar1;
    KeInitializeSpinLock(_Dst + 0x58);
    puVar1 = _Dst + 0x5c;
    *(undefined1 *)(_Dst + 0x5a) = 0;
    *(undefined4 **)(_Dst + 0x5e) = puVar1;
    *(undefined4 **)puVar1 = puVar1;
    KeInitializeEvent(_Dst + 0x50,0,1);
    KeInitializeEvent(_Dst + 0x6a,0,1);
    KeInitializeEvent(_Dst + 0xf2,0,1);
    KeInitializeEvent(_Dst + 0x4a,0,1);
    KeInitializeEvent(_Dst + 0xc2,0,1);
    KeInitializeEvent(_Dst + 0xdc,0,1);
    KeInitializeTimer(_Dst + 0xb2);
    KeInitializeDpc(_Dst + 200,CheckParentIdleDpc,puVar7);
    _Dst[3] = 1;
    KeInitializeTimer(_Dst + 0xfa);
    KeInitializeDpc(_Dst + 0x10a,PdoStartTimeoutDpc);
    uVar9 = 0;
    uVar6 = 0;
    IoInitializeRemoveLockEx(_Dst + 0x34,0x43627355,0,0,CONCAT44(uVar10,0x20));
    puVar1 = _Dst + 0x3c;
    *(undefined4 **)(_Dst + 0x3e) = puVar1;
    *(undefined4 **)puVar1 = puVar1;
    KeInitializeSpinLock(_Dst + 0x40);
    lVar4 = IoAttachDeviceToDeviceStack(local_res18,param_2);
    *(longlong *)(_Dst + 0xc) = lVar4;
    if (lVar4 == 0) {
      uVar5 = 0xc000000e;
      goto LAB_14002a743;
    }
    *(uint *)(local_res18 + 0x30) = *(uint *)(local_res18 + 0x30) | *(uint *)(lVar4 + 0x30) & 0x2000
    ;
    uVar5 = AllocateIdleIrp((longlong)puVar7);
    uVar2 = (uint)uVar5;
    uVar5 = uVar5 & 0xffffffff;
    if (-1 < (int)uVar2) {
      lVar4 = IoAllocateWorkItem(*(undefined8 *)(_Dst + 10));
      *(longlong *)(_Dst + 0xa4) = lVar4;
      if (lVar4 != 0) {
        GetCapabilitiesFromRegistry((longlong)puVar7);
        GetIdleTimeoutPeriodFromRegistry((longlong)puVar7);
        iVar3 = USBD_CreateHandle(local_res18,*(longlong *)(_Dst + 0xc),uVar6,uVar9,
                                  (undefined8 *)(_Dst + 0x154));
        if (((iVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
           && (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
          WPP_RECORDER_SF_q(*(undefined8 *)(_Dst + 0x15a),5,1,0x13,
                            &WPP_c8c0b630977f39a4a91a92e2db87f7d2_Traceguids,(char)local_res18);
        }
        *(uint *)(local_res18 + 0x30) = *(uint *)(local_res18 + 0x30) & 0xffffff7f;
        uVar2 = PoDirectedDripsSetDeviceFlags(param_2,6);
        uVar5 = (ulonglong)uVar2;
        if ((int)uVar2 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qd(*(undefined8 *)(_Dst + 0x15a),2,1,0x14,
                               &WPP_c8c0b630977f39a4a91a92e2db87f7d2_Traceguids,(char)local_res18,
                               (char)uVar2);
          }
          uVar5 = 0;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return uVar5;
        }
        WPP_RECORDER_SF_q(*(undefined8 *)(_Dst + 0x15a),4,1,0x15,
                          &WPP_c8c0b630977f39a4a91a92e2db87f7d2_Traceguids,(char)local_res18);
        return uVar5;
      }
      uVar5 = 0xc000009a;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(_Dst + 0x15a),2,8,0x12,
                         &WPP_c8c0b630977f39a4a91a92e2db87f7d2_Traceguids);
      }
      goto LAB_14002a743;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002a743;
    uVar8 = 0x11;
    uVar6 = *(undefined8 *)(_Dst + 0x15a);
  }
  WPP_RECORDER_SF_d(uVar6,2,8,uVar8,&WPP_c8c0b630977f39a4a91a92e2db87f7d2_Traceguids,(char)uVar2);
LAB_14002a743:
  if (local_res18 != 0) {
    if (puVar7 == (undefined4 *)0x0) {
      IoDeleteDevice(local_res18);
    }
    else {
      if (*(longlong *)(puVar7 + 10) != 0) {
        IoDetachDevice();
      }
      FreeParentFDOResources((longlong)puVar7);
    }
  }
  return uVar5;
}



===== AllocateDeviceIFRLog @ 14002a944 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AllocateDeviceIFRLog(longlong param_1)

{
  int iVar1;
  undefined1 auStackY_c8 [32];
  undefined8 local_80;
  undefined8 *puStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined1 local_28 [16];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_50 = 0;
  local_60 = 0x38;
  uStack_38 = 0;
  local_40 = 0;
  puStack_78 = &local_40;
  local_70 = 0;
  uStack_68 = 0;
  uStack_58 = 0xc800000400;
  uStack_48 = 0x1000000000;
  local_30 = 0x200000002;
  local_80 = 0x100000;
  iVar1 = IoGetDeviceProperty(*(undefined8 *)(param_1 + 0x18),5,0x10,local_28);
  if (-1 < iVar1) {
    RtlInitUnicodeString(&local_70,local_28);
    RtlUnicodeStringToAnsiString(&local_80,&local_70,0);
  }
  uStack_58 = 0x33300001000;
  iVar1 = imp_WppRecorderLogCreate(WPP_GLOBAL_Control,&local_60,(longlong *)(param_1 + 0x560));
  if (iVar1 < 0) {
    *(longlong *)(param_1 + 0x560) = g_RecorderLog;
    if ((g_RecorderLog != 0) &&
       ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_qd(g_RecorderLog,2,8,0x16,&WPP_c8c0b630977f39a4a91a92e2db87f7d2_Traceguids,
                         (char)*(undefined8 *)(param_1 + 0x20),(char)iVar1);
    }
  }
  return;
}



===== GetCapabilitiesFromRegistry @ 14002aad4 =====

int GetCapabilitiesFromRegistry(longlong param_1)

{
  undefined4 *_Dst;
  int iVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 uVar5;
  int iVar6;
  int iVar7;
  undefined4 local_res8 [2];
  undefined8 local_res10;
  undefined8 in_stack_ffffffffffffffb8;
  undefined4 uVar8;
  undefined8 local_38;
  undefined8 uStack_30;
  
  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);
  local_res10 = 0;
  _Dst = (undefined4 *)(param_1 + 0x4d0);
  *_Dst = 0;
  iVar6 = 0;
  iVar7 = 0;
  iVar1 = IoOpenDeviceRegistryKey(*(undefined8 *)(param_1 + 0x18),1,0x1f0000,&local_res10);
  if (-1 < iVar1) {
    local_res8[0] = 0;
    local_38 = 0;
    uStack_30 = 0;
    RtlInitUnicodeString(&local_38,L"UsbccgpCapabilities");
    uVar5 = 0x100;
    if (ExDefaultNonPagedPoolType == 1) {
      uVar5 = 0x40;
    }
    lVar4 = ExAllocatePool2(uVar5,0x10,0x43627355);
    if (lVar4 == 0) {
      iVar1 = -0x3fffff66;
    }
    else {
      iVar2 = ZwQueryValueKey(local_res10,&local_38,2,lVar4,CONCAT44(uVar8,0x10),local_res8);
      iVar1 = 0;
      if (iVar2 != -0x7ffffffb) {
        iVar1 = iVar2;
      }
      if (-1 < iVar1) {
        if (_Dst != (undefined4 *)0x0) {
          uVar3 = *(uint *)(lVar4 + 8);
          if (4 < uVar3) {
            uVar3 = 4;
          }
          memmove(_Dst,(void *)(lVar4 + 0xc),(ulonglong)uVar3);
        }
        iVar7 = *(int *)(lVar4 + 4);
        iVar6 = *(int *)(lVar4 + 8);
      }
      ExFreePoolWithTag(lVar4,0x43627355);
    }
    ZwClose(local_res10);
  }
  if (((iVar1 < 0) || (iVar7 != 4)) || (iVar6 != 4)) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),4,1,0xb,
                        &WPP_c8c0b630977f39a4a91a92e2db87f7d2_Traceguids,(char)iVar1);
    }
    *(undefined4 *)(param_1 + 0x4d0) = 0;
  }
  return iVar1;
}



===== GetIdleTimeoutPeriodFromRegistry @ 14002ac90 =====

int GetIdleTimeoutPeriodFromRegistry(longlong param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 uVar5;
  int iVar6;
  undefined2 uVar7;
  int iVar8;
  undefined4 local_res8 [2];
  undefined8 local_res10;
  undefined8 in_stack_ffffffffffffffa8;
  undefined4 uVar9;
  undefined1 uVar10;
  undefined8 local_38;
  undefined8 uStack_30;
  
  uVar9 = (undefined4)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20);
  local_res10 = 0;
  iVar6 = 0;
  iVar8 = 0;
  iVar1 = IoOpenDeviceRegistryKey(*(undefined8 *)(param_1 + 0x18),1,0x1f0000,&local_res10);
  if (-1 < iVar1) {
    local_res8[0] = 0;
    local_38 = 0;
    uStack_30 = 0;
    RtlInitUnicodeString(&local_38,L"IdleTimeoutPeriodInMilliSec");
    uVar5 = 0x100;
    if (ExDefaultNonPagedPoolType == 1) {
      uVar5 = 0x40;
    }
    lVar4 = ExAllocatePool2(uVar5,0x10,0x43627355);
    if (lVar4 == 0) {
      iVar1 = -0x3fffff66;
    }
    else {
      iVar2 = ZwQueryValueKey(local_res10,&local_38,2,lVar4,CONCAT44(uVar9,0x10),local_res8);
      iVar1 = 0;
      if (iVar2 != -0x7ffffffb) {
        iVar1 = iVar2;
      }
      if (-1 < iVar1) {
        if ((void *)(param_1 + 0x360) != (void *)0x0) {
          uVar3 = *(uint *)(lVar4 + 8);
          if (4 < uVar3) {
            uVar3 = 4;
          }
          memmove((void *)(param_1 + 0x360),(void *)(lVar4 + 0xc),(ulonglong)uVar3);
        }
        iVar8 = *(int *)(lVar4 + 4);
        iVar6 = *(int *)(lVar4 + 8);
      }
      ExFreePoolWithTag(lVar4,0x43627355);
    }
    ZwClose(local_res10);
  }
  if (((iVar1 < 0) || (iVar8 != 4)) || (iVar6 != 4)) {
    *(undefined4 *)(param_1 + 0x360) = 1000;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar7 = 0x17;
    uVar10 = 0xe8;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return iVar1;
    }
    uVar10 = (undefined1)*(undefined4 *)(param_1 + 0x360);
    uVar7 = 0x18;
  }
  WPP_RECORDER_SF_qd(*(undefined8 *)(param_1 + 0x560),4,1,uVar7,
                     &WPP_c8c0b630977f39a4a91a92e2db87f7d2_Traceguids,
                     (char)*(undefined8 *)(param_1 + 0x20),uVar10);
  return iVar1;
}



===== GetDeviceText @ 14002ae84 =====

uint GetDeviceText(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  byte bVar4;
  uint uVar5;
  void *pvVar6;
  ulonglong uVar7;
  short *psVar8;
  int iVar9;
  undefined8 uVar10;
  short sVar11;
  undefined2 uVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  byte *pbVar15;
  ulonglong local_res10;
  byte *local_res18;
  longlong local_res20;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  local_res20 = *(longlong *)(param_1 + 0xe8);
  local_res10 = local_res10 & 0xffffffff00000000;
  uVar1 = *(uint *)(lVar2 + 8);
  local_res18 = (byte *)0x0;
  if (uVar1 == 0) {
    lVar3 = *(longlong *)(param_1 + 0xf0);
    if (*(longlong *)(lVar3 + 0x40) != 0) {
      uVar10 = 0x100;
      if (ExDefaultNonPagedPoolType == 1) {
        uVar10 = 0x40;
      }
      pvVar6 = (void *)ExAllocatePool2(uVar10,(ulonglong)*(ushort *)(lVar3 + 0x38) + 2,0x43627355);
      if (pvVar6 == (void *)0x0) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
          return 0xc000009a;
        }
        uVar12 = 0x2e;
        goto LAB_14002b298;
      }
      memmove(pvVar6,*(void **)(lVar3 + 0x40),(ulonglong)*(ushort *)(lVar3 + 0x38));
      *(void **)(param_2 + 0x38) = pvVar6;
      uVar5 = 0;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0;
      }
      WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x188),4,2,0x2d,
                        &WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,
                        (char)*(undefined8 *)(param_1 + 0xe0));
      goto LAB_14002b259;
    }
    if (*(longlong *)(lVar3 + 0x10) == 0) {
LAB_14002af07:
      puVar14 = (undefined8 *)(param_1 + 0x188);
      puVar13 = (undefined8 *)(param_1 + 0xe0);
      bVar4 = *(byte *)(*(longlong *)**(undefined8 **)(lVar3 + 8) + 8);
      if (bVar4 == 0) {
        if (GenericCompositeUSBDeviceString != (short *)0x0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_q(*puVar14,4,2,0x31,&WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,
                              (char)*puVar13);
          }
          iVar9 = 0;
          for (psVar8 = GenericCompositeUSBDeviceString; *psVar8 != 0; psVar8 = psVar8 + 1) {
            iVar9 = iVar9 + 1;
          }
          uVar10 = 0x100;
          if (ExDefaultNonPagedPoolType == 1) {
            uVar10 = 0x40;
          }
          pvVar6 = (void *)ExAllocatePool2(uVar10,(ulonglong)(uint)(iVar9 * 2) + 2,0x43627355);
          if (pvVar6 == (void *)0x0) {
            *(undefined8 *)(param_2 + 0x38) = 0;
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
              return 0xc000009a;
            }
            uVar12 = 0x32;
LAB_14002b298:
            WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x188),2,8,uVar12,
                             &WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids);
            return 0xc000009a;
          }
          memmove(pvVar6,GenericCompositeUSBDeviceString,(ulonglong)(uint)(iVar9 * 2));
          *(void **)(param_2 + 0x38) = pvVar6;
          uVar5 = 0;
          goto LAB_14002b259;
        }
        if (*(char *)(local_res20 + 0x6f) == '\0') {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_q(*puVar14,4,2,0x34,&WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,
                              (char)*puVar13);
          }
          uVar5 = *(uint *)(param_2 + 0x30);
          goto LAB_14002b08f;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_q(*puVar14,4,2,0x33,&WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,
                            (char)*puVar13);
        }
        bVar4 = *(byte *)(local_res20 + 0x6f);
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_dq(*(undefined8 *)(param_1 + 0x188));
      }
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x188),4,2,0x2f,
                          &WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,
                          (char)*(undefined8 *)(param_1 + 0xe0));
      }
      bVar4 = *(byte *)(*(longlong *)(lVar3 + 0x10) + 7);
      if (bVar4 == 0) goto LAB_14002af07;
    }
    sVar11 = *(short *)(lVar2 + 0x12);
    if (sVar11 == 0) {
      sVar11 = 0x409;
    }
    uVar5 = PdoGetStringDescriptor(param_1,bVar4,sVar11,&local_res18,(uint *)&local_res10);
    pbVar15 = local_res18;
    if ((int)uVar5 < 0) {
      *(undefined8 *)(param_2 + 0x38) = 0;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x188),2,8,0x36,
                          &WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,
                          (char)*(undefined8 *)(param_1 + 0xe0));
      }
      goto LAB_14002b097;
    }
    local_res10 = (ulonglong)*local_res18 - 2 >> 1;
    uVar7 = (ulonglong)(uint)((int)local_res10 * 2);
    uVar10 = 0x100;
    if (ExDefaultNonPagedPoolType == 1) {
      uVar10 = 0x40;
    }
    pvVar6 = (void *)ExAllocatePool2(uVar10,uVar7 + 2,0x43627355);
    if (pvVar6 == (void *)0x0) {
      uVar5 = 0xc000009a;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x188),2,8,0x35,
                         &WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids);
      }
      goto LAB_14002b09f;
    }
    memmove(pvVar6,pbVar15 + 2,uVar7);
    *(undefined2 *)((longlong)pvVar6 + (local_res10 & 0xffffffff) * 2) = 0;
    *(void **)(param_2 + 0x38) = pvVar6;
  }
  else {
    if (uVar1 == 1) {
      uVar7 = HandlePdoLocationInformation(param_1,param_2);
      uVar5 = (uint)uVar7;
    }
    else {
      uVar5 = *(uint *)(param_2 + 0x30);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_Dd(*(undefined8 *)(param_1 + 0x188),(ulonglong)uVar1,2,0x37,
                           &WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,(char)uVar1,(char)uVar5)
        ;
      }
    }
LAB_14002b08f:
    if ((int)uVar5 < 0) {
LAB_14002b097:
      pbVar15 = local_res18;
      goto LAB_14002b09f;
    }
LAB_14002b259:
    pbVar15 = local_res18;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qs(*(undefined8 *)(param_1 + 0x188),4,2,0x38,
                       &WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,
                       (char)*(undefined8 *)(param_1 + 0xe0),*(char **)(param_2 + 0x38));
  }
LAB_14002b09f:
  if (pbVar15 != (byte *)0x0) {
    ExFreePoolWithTag(pbVar15,0x43627355);
  }
  return uVar5;
}



===== PdoGetStringDescriptor @ 14002b400 =====

uint PdoGetStringDescriptor
               (longlong param_1,byte param_2,short param_3,undefined8 *param_4,uint *param_5)

{
  uint uVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  undefined2 uVar5;
  
  pbVar2 = (byte *)ExAllocatePool2(0x40,4,0x43627355);
  if (pbVar2 == (byte *)0x0) {
    uVar1 = 0xc000009a;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = 0x2a;
LAB_14002b560:
      uVar1 = 0xc000009a;
      WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x188),2,8,uVar5,
                       &WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids);
    }
  }
  else {
    while (uVar1 = GetStringDescriptor(*(longlong *)(param_1 + 0xe8),param_2,param_3,pbVar2,4),
          (int)uVar1 < 0) {
      if (param_3 == 0x409) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_dqd(*(undefined8 *)(param_1 + 0x188));
        }
        goto LAB_14002b466;
      }
      param_3 = 0x409;
    }
    if (*pbVar2 < 5) {
      uVar1 = 0xc000009c;
    }
    else {
      pbVar3 = (byte *)ExAllocatePool2(0x40,*pbVar2,0x43627355);
      if (pbVar3 == (byte *)0x0) {
        uVar1 = 0xc000009a;
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar5 = 0x2c;
          goto LAB_14002b560;
        }
      }
      else {
        uVar1 = GetStringDescriptor(*(longlong *)(param_1 + 0xe8),param_2,param_3,pbVar3,
                                    (uint)*pbVar2);
        if (-1 < (int)uVar1) {
          if (*pbVar2 == *pbVar3) {
            uVar4 = (uint)*pbVar2;
            goto LAB_14002b46a;
          }
          uVar1 = 0xc000009c;
        }
        ExFreePoolWithTag(pbVar3,0x43627355);
      }
    }
  }
LAB_14002b466:
  uVar4 = 0;
  pbVar3 = (byte *)0x0;
LAB_14002b46a:
  *param_4 = pbVar3;
  *param_5 = uVar4;
  if (pbVar2 != (byte *)0x0) {
    ExFreePoolWithTag(pbVar2,0x43627355);
  }
  return uVar1;
}



===== HandlePdoLocationInformation @ 14002b61c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong HandlePdoLocationInformation(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  wchar_t *_Dst;
  undefined8 uVar2;
  undefined1 auStackY_b8 [32];
  ulonglong local_58 [6];
  
  local_58[4] = __security_cookie ^ (ulonglong)auStackY_b8;
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  uVar1 = UsbcGetTopologyAddress(*(longlong *)(param_1 + 0xe8),local_58);
  if ((int)uVar1 < 0) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(param_1 + 0x188),2,8,0x3a,
                         &WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,
                         (char)*(undefined8 *)(param_1 + 0xe0),(char)uVar1);
    }
  }
  else {
    uVar2 = 0x100;
    if (ExDefaultNonPagedPoolType == 1) {
      uVar2 = 0x40;
    }
    _Dst = (wchar_t *)ExAllocatePool2(uVar2,0x50,0x43627355);
    if (_Dst == (wchar_t *)0x0) {
      *(undefined8 *)(param_2 + 0x38) = 0;
      return 0xc000009a;
    }
    memset(_Dst,0,0x50);
    RtlStringCbPrintfW(_Dst,0x50,L"%4.4x.%4.4x.%4.4x.%3.3d.%3.3d.%3.3d.%3.3d.%3.3d.%3.3d",
                       local_58[0] & 0xffffffff);
    *(wchar_t **)(param_2 + 0x38) = _Dst;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qS(*(undefined8 *)(param_1 + 0x188));
    }
  }
  return uVar1 & 0xffffffff;
}



===== HandlePdoQueryInterface @ 14002b7cc =====

ulonglong HandlePdoQueryInterface(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 *puVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  lVar3 = RtlCompareMemory(*(undefined8 *)(lVar1 + 8),&GUID_D3COLD_SUPPORT_INTERFACE,0x10);
  if (lVar3 == 0x10) {
    if (((*(short *)(lVar1 + 0x10) == 0x48) && (*(short *)(lVar1 + 0x12) == 1)) &&
       (uVar4 = 0, *(char *)(*(longlong *)(param_1 + 0xe8) + 0x1b9) != '\0')) {
      puVar2 = *(undefined4 **)(lVar1 + 0x18);
      *(code **)(puVar2 + 8) = D3ColdSupportInterfaceFunctionSetD3ColdSupport;
      *(code **)(puVar2 + 10) = D3ColdSupportInterfaceFunctionGetIdleWakeInfo;
      *(code **)(puVar2 + 6) = D3ColdSupportFunctionInterfaceDereference;
      *(code **)(puVar2 + 4) = D3ColdSupportFunctionInterfaceReference;
      *(code **)(puVar2 + 0xc) = D3ColdSupportInterfaceFunctionGetD3ColdCapability;
      *(code **)(puVar2 + 0xe) = D3ColdSupportInterfaceFunctionGetBusDriverD3ColdSupport;
      *(code **)(puVar2 + 0x10) = D3ColdSupportInterfaceFunctionGetLastTransitionStatus;
      *puVar2 = 0x10048;
      *(longlong *)(puVar2 + 2) = param_1;
      goto LAB_14002b8b2;
    }
  }
  else {
    lVar3 = RtlCompareMemory(*(undefined8 *)(lVar1 + 8),&GUID_PNP_LOCATION_INTERFACE,0x10);
    if (lVar3 != 0x10) {
      uVar4 = UsbcForwardIrp(*(longlong *)(param_1 + 0xe8),
                             *(undefined8 *)(*(longlong *)(param_1 + 0xe8) + 0x20),param_2);
      return uVar4 & 0xffffffff;
    }
    if ((0x27 < *(ushort *)(lVar1 + 0x10)) && (*(short *)(lVar1 + 0x12) != 0)) {
      puVar2 = *(undefined4 **)(lVar1 + 0x18);
      uVar4 = 0;
      *(code **)(puVar2 + 4) = _guard_check_icall;
      *(code **)(puVar2 + 6) = _guard_check_icall;
      *(code **)(puVar2 + 8) = PnpLocationInterfaceGetLocationStrings;
      *puVar2 = 0x10028;
      *(longlong *)(puVar2 + 2) = param_1;
      goto LAB_14002b8b2;
    }
  }
  uVar4 = (ulonglong)*(uint *)(param_2 + 0x30);
LAB_14002b8b2:
  UsbcCompleteIrp(*(longlong *)(param_1 + 0xe8),(int)uVar4,param_2);
  return uVar4;
}



===== AppendInterfaceNumber @ 14002b948 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

short * AppendInterfaceNumber(short *param_1,uint param_2,int param_3)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  short *psVar6;
  int iVar7;
  ulonglong uVar8;
  uint uVar9;
  wchar_t *pwVar10;
  short *psVar11;
  undefined1 auStackY_a8 [32];
  wchar_t local_68 [16];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_a8;
  iVar4 = 0;
  sVar2 = *param_1;
  psVar6 = param_1;
  while (sVar2 != 0) {
    iVar3 = WStrLen(psVar6);
    iVar7 = iVar4 + 0xf + iVar3;
    iVar4 = iVar7 + 0xe;
    if (param_3 != 1) {
      iVar4 = iVar7;
    }
    psVar6 = psVar6 + (iVar3 + 1);
    sVar2 = *psVar6;
  }
  uVar9 = iVar4 + 1;
  psVar6 = (short *)ExAllocatePool2(0x40,(ulonglong)uVar9 * 2,0x43627355);
  if (psVar6 == (short *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(g_RecorderLog,2,8,0xb,&WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids);
    }
LAB_14002ba8a:
    psVar6 = (short *)0x0;
  }
  else {
    if (param_3 == 1) {
      pwVar10 = L"&MAUSB&MI_%02x";
    }
    else if (param_3 == 2) {
      pwVar10 = L"&PI_%02x";
    }
    else {
      pwVar10 = L"&MI_%02x";
    }
    uVar8 = 0x10;
    RtlStringCchPrintfW(local_68,0x10,pwVar10,(ulonglong)param_2);
    iVar4 = WStrLen(local_68);
    uVar1 = iVar4 + 1;
    psVar11 = psVar6;
    for (; *param_1 != 0; param_1 = param_1 + (uVar5 + 1)) {
      uVar5 = WStrLen(param_1);
      if (uVar9 < iVar4 + 2 + uVar5) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_ddd(g_RecorderLog,uVar8,pwVar10,0xc,
                              &WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids,(char)uVar9,
                              (char)uVar5,(char)uVar1);
        }
        ExFreePoolWithTag(psVar6,0x43627355);
        goto LAB_14002ba8a;
      }
      RtlStringCchCopyW(psVar11,(ulonglong)uVar9,(longlong)param_1);
      uVar8 = (ulonglong)(uVar9 - uVar5);
      pwVar10 = local_68;
      RtlStringCchCopyW(psVar11 + uVar5,uVar8,(longlong)pwVar10);
      uVar9 = (uVar9 - uVar5) - uVar1;
      psVar11 = psVar11 + uVar5 + uVar1;
    }
  }
  return psVar6;
}



===== QueryFunctionDeviceRelations @ 14002bb2c =====

undefined4 QueryFunctionDeviceRelations(longlong param_1,longlong param_2)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  
  if (*(int *)(*(longlong *)(param_2 + 0xb8) + 8) == 4) {
    uVar2 = 0x100;
    if (ExDefaultNonPagedPoolType == 1) {
      uVar2 = 0x40;
    }
    puVar1 = (undefined4 *)ExAllocatePool2(uVar2,0x10,0x43627355);
    uVar3 = 0;
    if (puVar1 == (undefined4 *)0x0) {
      uVar3 = 0xc000009a;
    }
    else {
      ObfReferenceObject(*(undefined8 *)(param_1 + 0xe0));
      *(undefined8 *)(puVar1 + 2) = *(undefined8 *)(param_1 + 0xe0);
      *puVar1 = 1;
      *(undefined4 **)(param_2 + 0x38) = puVar1;
    }
  }
  else {
    uVar3 = *(undefined4 *)(param_2 + 0x30);
  }
  return uVar3;
}



===== QueryFunctionCapabilities @ 14002bbd8 =====

undefined8 QueryFunctionCapabilities(longlong param_1,longlong param_2)

{
  undefined2 *puVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  int iVar6;
  
  puVar1 = *(undefined2 **)(*(longlong *)(param_2 + 0xb8) + 8);
  if (puVar1 == (undefined2 *)0x0) {
    return 0xc000009c;
  }
  *puVar1 = *(undefined2 *)(*(longlong *)(param_1 + 0xe8) + 0x88);
  puVar1[1] = *(undefined2 *)(*(longlong *)(param_1 + 0xe8) + 0x8a);
  uVar3 = (*(uint *)(puVar1 + 2) ^ *(uint *)(*(longlong *)(param_1 + 0xe8) + 0x8c)) & 1 ^
          *(uint *)(puVar1 + 2);
  *(uint *)(puVar1 + 2) = uVar3;
  uVar3 = (uVar3 ^ *(uint *)(*(longlong *)(param_1 + 0xe8) + 0x8c)) & 2 ^ uVar3;
  *(uint *)(puVar1 + 2) = uVar3;
  uVar3 = (uVar3 ^ *(uint *)(*(longlong *)(param_1 + 0xe8) + 0x8c)) & 4 ^ uVar3;
  *(uint *)(puVar1 + 2) = uVar3;
  uVar3 = (uVar3 ^ *(uint *)(*(longlong *)(param_1 + 0xe8) + 0x8c)) & 8 ^ uVar3;
  *(uint *)(puVar1 + 2) = uVar3;
  uVar3 = (uVar3 ^ *(uint *)(*(longlong *)(param_1 + 0xe8) + 0x8c)) & 0x20 ^ uVar3;
  *(uint *)(puVar1 + 2) = uVar3;
  uVar3 = (uVar3 ^ *(uint *)(*(longlong *)(param_1 + 0xe8) + 0x8c)) & 0x80 ^ uVar3;
  *(uint *)(puVar1 + 2) = uVar3;
  uVar3 = (uVar3 ^ *(uint *)(*(longlong *)(param_1 + 0xe8) + 0x8c)) & 0x200 ^ uVar3;
  *(uint *)(puVar1 + 2) = uVar3;
  uVar3 = (uVar3 ^ *(uint *)(*(longlong *)(param_1 + 0xe8) + 0x8c)) & 0x400 ^ uVar3;
  *(uint *)(puVar1 + 2) = uVar3;
  uVar3 = (uVar3 ^ *(uint *)(*(longlong *)(param_1 + 0xe8) + 0x8c)) & 0x800 ^ uVar3;
  *(uint *)(puVar1 + 2) = uVar3;
  uVar3 = (uVar3 ^ *(uint *)(*(longlong *)(param_1 + 0xe8) + 0x8c)) & 0x1000 ^ uVar3;
  *(uint *)(puVar1 + 2) = uVar3;
  uVar3 = (uVar3 ^ *(uint *)(*(longlong *)(param_1 + 0xe8) + 0x8c)) & 0x2000 ^ uVar3;
  *(uint *)(puVar1 + 2) = uVar3;
  uVar3 = (uVar3 ^ *(uint *)(*(longlong *)(param_1 + 0xe8) + 0x8c)) & 0x4000 ^ uVar3;
  *(uint *)(puVar1 + 2) = uVar3;
  uVar3 = (uVar3 ^ *(uint *)(*(longlong *)(param_1 + 0xe8) + 0x8c)) & 0x8000 ^ uVar3;
  *(uint *)(puVar1 + 2) = uVar3;
  uVar3 = (uVar3 ^ *(uint *)(*(longlong *)(param_1 + 0xe8) + 0x8c)) & 0x10000 ^ uVar3;
  *(uint *)(puVar1 + 2) = uVar3;
  uVar3 = (uVar3 ^ *(uint *)(*(longlong *)(param_1 + 0xe8) + 0x8c)) & 0x20000 ^ uVar3;
  *(uint *)(puVar1 + 2) = uVar3;
  uVar4 = uVar3 & 0xfffffeaf;
  *(undefined4 *)(puVar1 + 6) = *(undefined4 *)(*(longlong *)(param_1 + 0xe8) + 0x94);
  lVar5 = *(longlong *)(param_1 + 0xe8);
  uVar2 = *(undefined8 *)(lVar5 + 0xa0);
  *(undefined8 *)(puVar1 + 8) = *(undefined8 *)(lVar5 + 0x98);
  *(undefined8 *)(puVar1 + 0xc) = uVar2;
  *(undefined8 *)(puVar1 + 0x10) = *(undefined8 *)(lVar5 + 0xa8);
  *(undefined4 *)(puVar1 + 0x14) = *(undefined4 *)(lVar5 + 0xb0);
  *(undefined4 *)(puVar1 + 0x16) = *(undefined4 *)(*(longlong *)(param_1 + 0xe8) + 0xb4);
  iVar6 = *(int *)(*(longlong *)(param_1 + 0xe8) + 0xb8);
  *(int *)(puVar1 + 0x18) = iVar6;
  *(undefined4 *)(puVar1 + 0x1a) = *(undefined4 *)(*(longlong *)(param_1 + 0xe8) + 0xbc);
  *(undefined4 *)(puVar1 + 0x1c) = *(undefined4 *)(*(longlong *)(param_1 + 0xe8) + 0xc0);
  *(undefined4 *)(puVar1 + 0x1e) = *(undefined4 *)(*(longlong *)(param_1 + 0xe8) + 0xc4);
  *(uint *)(puVar1 + 2) = uVar4;
  lVar5 = *(longlong *)(param_1 + 0xe8);
  if ((*(char *)(lVar5 + 0x55a) != '\0') &&
     (*(char *)(*(longlong *)(param_1 + 0x180) + 0x39) == '\0')) {
    *(undefined4 *)(puVar1 + 0x18) = 1;
    iVar6 = 1;
    uVar4 = uVar3 & 0xffffc6af | 0x400;
    *(uint *)(puVar1 + 2) = uVar4;
    lVar5 = *(longlong *)(param_1 + 0xe8);
  }
  if (((uVar4 >> 0xd & 1) != 0) || (3 < iVar6)) {
    *(undefined1 *)(param_1 + 0x74) = 1;
  }
  *(int *)(puVar1 + 4) = *(int *)(lVar5 + 0x90) + *(int *)(param_1 + 8);
  return 0;
}



===== BuildCompatibleIDs @ 14002bec0 =====

short * BuildCompatibleIDs(char *param_1,char *param_2,ushort param_3,byte param_4,byte param_5,
                          byte param_6)

{
  short *psVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  short sVar11;
  undefined8 uVar12;
  short *psVar13;
  wchar_t *pwVar14;
  short *psVar15;
  longlong lVar16;
  short *psVar17;
  wchar_t *pwVar18;
  uint local_res20 [2];
  
  local_res20[0] = 0;
  sVar2 = *(short *)(&NibbleW + (ulonglong)(param_3 & 0xf) * 2);
  sVar3 = *(short *)(&NibbleW + (ulonglong)(param_3 >> 4 & 0xf) * 2);
  sVar4 = *(short *)(&NibbleW + (ulonglong)(param_3 >> 8 & 0xf) * 2);
  sVar5 = *(short *)(&NibbleW + (ulonglong)(param_3 >> 0xc) * 2);
  sVar6 = *(short *)(&NibbleW + (ulonglong)(param_4 & 0xf) * 2);
  sVar7 = *(short *)(&NibbleW + (ulonglong)(param_4 >> 4) * 2);
  sVar8 = *(short *)(&NibbleW + (ulonglong)(param_5 & 0xf) * 2);
  sVar9 = *(short *)(&NibbleW + (ulonglong)(param_5 >> 4) * 2);
  sVar10 = *(short *)(&NibbleW + (ulonglong)(param_6 >> 4) * 2);
  sVar11 = *(short *)(&NibbleW + (ulonglong)(param_6 & 0xf) * 2);
  psVar15 = BuildMSOSCompatibleIDs(param_1,param_2,0x17e,(int *)local_res20);
  if (psVar15 != (short *)0x0) {
    psVar1 = psVar15 + (local_res20[0] >> 1);
    lVar16 = 2;
    psVar13 = psVar1;
    pwVar14 = u_USB_COMPAT_VID_nnnn_Class_nn_Sub_14001c080;
    do {
      pwVar18 = pwVar14;
      psVar17 = psVar13;
      uVar12 = *(undefined8 *)(pwVar18 + 4);
      *(undefined8 *)psVar17 = *(undefined8 *)pwVar18;
      *(undefined8 *)(psVar17 + 4) = uVar12;
      uVar12 = *(undefined8 *)(pwVar18 + 0xc);
      *(undefined8 *)(psVar17 + 8) = *(undefined8 *)(pwVar18 + 8);
      *(undefined8 *)(psVar17 + 0xc) = uVar12;
      uVar12 = *(undefined8 *)(pwVar18 + 0x14);
      *(undefined8 *)(psVar17 + 0x10) = *(undefined8 *)(pwVar18 + 0x10);
      *(undefined8 *)(psVar17 + 0x14) = uVar12;
      uVar12 = *(undefined8 *)(pwVar18 + 0x1c);
      *(undefined8 *)(psVar17 + 0x18) = *(undefined8 *)(pwVar18 + 0x18);
      *(undefined8 *)(psVar17 + 0x1c) = uVar12;
      uVar12 = *(undefined8 *)(pwVar18 + 0x24);
      *(undefined8 *)(psVar17 + 0x20) = *(undefined8 *)(pwVar18 + 0x20);
      *(undefined8 *)(psVar17 + 0x24) = uVar12;
      uVar12 = *(undefined8 *)(pwVar18 + 0x2c);
      *(undefined8 *)(psVar17 + 0x28) = *(undefined8 *)(pwVar18 + 0x28);
      *(undefined8 *)(psVar17 + 0x2c) = uVar12;
      uVar12 = *(undefined8 *)(pwVar18 + 0x34);
      *(undefined8 *)(psVar17 + 0x30) = *(undefined8 *)(pwVar18 + 0x30);
      *(undefined8 *)(psVar17 + 0x34) = uVar12;
      uVar12 = *(undefined8 *)(pwVar18 + 0x3c);
      *(undefined8 *)(psVar17 + 0x38) = *(undefined8 *)(pwVar18 + 0x38);
      *(undefined8 *)(psVar17 + 0x3c) = uVar12;
      lVar16 = lVar16 + -1;
      psVar13 = psVar17 + 0x40;
      pwVar14 = pwVar18 + 0x40;
    } while (lVar16 != 0);
    uVar12 = *(undefined8 *)(pwVar18 + 0x44);
    *(undefined8 *)(psVar17 + 0x40) = *(undefined8 *)(pwVar18 + 0x40);
    *(undefined8 *)(psVar17 + 0x44) = uVar12;
    uVar12 = *(undefined8 *)(pwVar18 + 0x4c);
    *(undefined8 *)(psVar17 + 0x48) = *(undefined8 *)(pwVar18 + 0x48);
    *(undefined8 *)(psVar17 + 0x4c) = uVar12;
    uVar12 = *(undefined8 *)(pwVar18 + 0x54);
    *(undefined8 *)(psVar17 + 0x50) = *(undefined8 *)(pwVar18 + 0x50);
    *(undefined8 *)(psVar17 + 0x54) = uVar12;
    uVar12 = *(undefined8 *)(pwVar18 + 0x5c);
    *(undefined8 *)(psVar17 + 0x58) = *(undefined8 *)(pwVar18 + 0x58);
    *(undefined8 *)(psVar17 + 0x5c) = uVar12;
    uVar12 = *(undefined8 *)(pwVar18 + 100);
    *(undefined8 *)(psVar17 + 0x60) = *(undefined8 *)(pwVar18 + 0x60);
    *(undefined8 *)(psVar17 + 100) = uVar12;
    uVar12 = *(undefined8 *)(pwVar18 + 0x6c);
    *(undefined8 *)(psVar17 + 0x68) = *(undefined8 *)(pwVar18 + 0x68);
    *(undefined8 *)(psVar17 + 0x6c) = uVar12;
    uVar12 = *(undefined8 *)(pwVar18 + 0x74);
    *(undefined8 *)(psVar17 + 0x70) = *(undefined8 *)(pwVar18 + 0x70);
    *(undefined8 *)(psVar17 + 0x74) = uVar12;
    *(undefined8 *)(psVar17 + 0x78) = *(undefined8 *)(pwVar18 + 0x78);
    *(undefined4 *)(psVar17 + 0x7c) = *(undefined4 *)(pwVar18 + 0x7c);
    psVar17[0x7e] = pwVar18[0x7e];
    psVar1[0x95] = sVar10;
    psVar1[0x2e] = sVar10;
    psVar1[0x96] = sVar11;
    psVar1[0x2f] = sVar11;
    psVar1[0x69] = sVar5;
    psVar1[0x40] = sVar5;
    psVar1[0xf] = sVar5;
    psVar1[0x6a] = sVar4;
    psVar1[0x41] = sVar4;
    psVar1[0x10] = sVar4;
    psVar1[0x6b] = sVar3;
    psVar1[0x42] = sVar3;
    psVar1[0x11] = sVar3;
    psVar1[0x6c] = sVar2;
    psVar1[0x43] = sVar2;
    psVar1[0x12] = sVar2;
    psVar1[0xbb] = sVar7;
    psVar1[0xa2] = sVar7;
    psVar1[0x81] = sVar7;
    psVar1[0x74] = sVar7;
    psVar1[0x4b] = sVar7;
    psVar1[0x1a] = sVar7;
    psVar1[0xbc] = sVar6;
    psVar1[0xa3] = sVar6;
    psVar1[0x82] = sVar6;
    psVar1[0x75] = sVar6;
    psVar1[0x4c] = sVar6;
    psVar1[0x1b] = sVar6;
    psVar1[0xae] = sVar9;
    psVar1[0x8d] = sVar9;
    psVar1[0x57] = sVar9;
    psVar1[0x26] = sVar9;
    psVar1[0xaf] = sVar8;
    psVar1[0x8e] = sVar8;
    psVar1[0x58] = sVar8;
    psVar1[0x27] = sVar8;
    psVar15[local_res20[0] + 0x17e >> 1] = 0;
  }
  return psVar15;
}



===== BuildMSOSCompatibleIDs @ 14002c190 =====

short * BuildMSOSCompatibleIDs(char *param_1,char *param_2,int param_3,int *param_4)

{
  wchar_t *pwVar1;
  undefined8 uVar2;
  uint uVar3;
  char *pcVar4;
  wchar_t *pwVar5;
  
  pwVar1 = (wchar_t *)0x0;
  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
    if ((param_1 != (char *)0x0) && (*param_1 != '\0')) goto LAB_14002c337;
  }
  else if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    param_3 = param_3 + 0x52;
LAB_14002c337:
    param_3 = param_3 + 0x2a;
  }
  pwVar5 = (wchar_t *)0x0;
  if (param_3 != 0) {
    uVar2 = 0x100;
    if (ExDefaultNonPagedPoolType == 1) {
      uVar2 = 0x40;
    }
    pwVar1 = (wchar_t *)ExAllocatePool2(uVar2,param_3 + 2,0x43627355);
    pwVar5 = pwVar1;
    if (pwVar1 != (wchar_t *)0x0) {
      if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
        if (param_1 == (char *)0x0) goto LAB_14002c20a;
      }
      else {
        if ((param_1 == (char *)0x0) || (*param_1 == '\0')) goto LAB_14002c20a;
        pwVar5 = pwVar1 + 0xc;
        uVar3 = 0;
        builtin_wcsncpy(pwVar1,L"USB\\MS_COMP_",0xc);
        pcVar4 = param_1;
        do {
          if (*pcVar4 == '\0') break;
          *pwVar5 = (short)*pcVar4;
          uVar3 = uVar3 + 1;
          pwVar5 = pwVar5 + 1;
          pcVar4 = pcVar4 + 1;
        } while (uVar3 < 8);
        uVar3 = 0;
        builtin_wcsncpy(pwVar5,L"&MS_SUBCOMP_",0xc);
        pwVar5 = pwVar5 + 0xc;
        do {
          if (*param_2 == '\0') break;
          *pwVar5 = (short)*param_2;
          uVar3 = uVar3 + 1;
          pwVar5 = pwVar5 + 1;
          param_2 = param_2 + 1;
        } while (uVar3 < 8);
        *pwVar5 = L'\0';
        pwVar5 = pwVar5 + 1;
      }
      if (*param_1 != '\0') {
        uVar3 = 0;
        builtin_wcsncpy(pwVar5,L"USB\\MS_COMP_",0xc);
        pwVar5 = pwVar5 + 0xc;
        do {
          if (*param_1 == '\0') break;
          *pwVar5 = (short)*param_1;
          uVar3 = uVar3 + 1;
          pwVar5 = pwVar5 + 1;
          param_1 = param_1 + 1;
        } while (uVar3 < 8);
        *pwVar5 = L'\0';
        pwVar5 = pwVar5 + 1;
      }
    }
  }
LAB_14002c20a:
  if (param_4 != (int *)0x0) {
    *param_4 = (int)pwVar5 - (int)pwVar1;
  }
  return pwVar1;
}



===== GetD3Policy @ 14002c348 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong GetD3Policy(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined1 auStack_c8 [32];
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined4 local_88 [2];
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 *local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  local_44 = 0;
  local_78 = 0;
  local_80 = 0;
  local_88[0] = 0;
  local_5c = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_20 = 0;
  local_30 = 0;
  uStack_28 = 0;
  uVar2 = IoOpenDeviceRegistryKey(0,1,0xf003f,&local_80);
  if (-1 < (int)uVar2) {
    RtlInitUnicodeString(&local_70,L"e5b3b5ac-9725-4f78-963f-03dfb1d828c7");
    local_98 = 0;
    local_a0 = (undefined4 *)((ulonglong)local_a0._4_4_ << 0x20);
    local_a8 = 0;
    local_58 = local_80;
    local_50 = &local_70;
    local_60 = 0x30;
    local_48 = 0x240;
    local_40 = 0;
    uStack_38 = 0;
    uVar1 = ZwCreateKey(&local_78,0xf003f,&local_60,0);
    uVar2 = (ulonglong)uVar1;
    ZwClose(local_80);
    if (-1 < (int)uVar1) {
      RtlInitUnicodeString(&local_70,L"D3ColdSupported");
      local_a0 = local_88;
      local_a8 = CONCAT44(local_a8._4_4_,0x14);
      uVar1 = ZwQueryValueKey(local_78,&local_70,2,&local_30);
      uVar2 = (ulonglong)uVar1;
      ZwClose(local_78);
      if (-1 < (int)uVar1) {
        *(bool *)param_2 = uStack_28._4_4_ != 0;
      }
    }
  }
  return uVar2;
}



===== USBC_DeviceControl @ 14002c4c8 =====

ulonglong USBC_DeviceControl(longlong param_1,longlong param_2)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  lVar3 = param_1 + 8;
  if (*(char *)(param_1 + 4) == '\0') {
    lVar3 = *(longlong *)(param_1 + 0xf0);
  }
  if (*(int *)(*(longlong *)(param_2 + 0xb8) + 0x18) == 0x2f0003) {
    uVar2 = KsPropertyHandleDrmSetContentId(param_2);
    uVar4 = uVar2 & 0xffffffff;
    UsbcCompleteIrp(lVar3,(int)uVar2,param_2);
  }
  else {
    if (*(char *)(param_1 + 4) == '\0') {
      uVar2 = UsbcForwardIrp(lVar3,*(undefined8 *)(lVar3 + 0x20),param_2);
      uVar1 = (uint)uVar2;
    }
    else {
      uVar2 = DispatchFdoDeviceControl(lVar3,param_2);
      uVar1 = (uint)uVar2;
    }
    uVar4 = (ulonglong)uVar1;
  }
  return uVar4;
}



===== KsPropertyHandleDrmSetContentId @ 14002c554 =====

undefined8 KsPropertyHandleDrmSetContentId(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong *plVar7;
  undefined4 *puVar8;
  uint uVar9;
  ulonglong uVar10;
  
  if (*(char *)(param_1 + 0x40) != '\0') {
    return 0xc0000010;
  }
  lVar4 = *(longlong *)(param_1 + 0xb8);
  uVar1 = *(uint *)(lVar4 + 0x10);
  uVar2 = *(uint *)(lVar4 + 8);
  uVar9 = uVar2 + 7 & 0xfffffff8;
  uVar10 = (ulonglong)uVar9;
  puVar8 = *(undefined4 **)(param_1 + 0x18);
  if (puVar8 == (undefined4 *)0x0) {
    if (((uVar1 < 0x18) || (uVar9 < uVar2)) || (uVar9 + uVar1 < uVar9)) {
      return 0xc0000206;
    }
    iVar3 = *(int *)(*(longlong *)(lVar4 + 0x20) + 0x14);
    lVar5 = ExAllocatePoolWithQuotaTag(0x600,uVar9 + uVar1,0x7070534b);
    *(longlong *)(param_1 + 0x18) = lVar5;
    if (lVar5 != 0) {
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x30;
      memmove((void *)(uVar10 + lVar5),*(void **)(lVar4 + 0x20),(ulonglong)uVar1);
      *(int *)(uVar10 + 0x14 + *(longlong *)(param_1 + 0x18)) = iVar3;
      if ((iVar3 == 2) && (uVar2 != 0)) {
        if (*(char *)(param_1 + 0x40) != '\0') {
          ProbeForRead(*(undefined8 *)(param_1 + 0x70),uVar2,1);
        }
        memmove(*(void **)(param_1 + 0x18),*(void **)(param_1 + 0x70),(ulonglong)uVar2);
      }
    }
    puVar8 = *(undefined4 **)(param_1 + 0x18);
    if (puVar8 == (undefined4 *)0x0) {
      return 0xc000009a;
    }
  }
  plVar7 = (longlong *)(uVar10 + (longlong)puVar8);
  if ((*plVar7 == 0x4fac41982f2c8ddd) && (plVar7[1] == 0x6deb705bb6129ba)) {
    if ((int)plVar7[2] == 0) {
      if (*(int *)((longlong)plVar7 + 0x14) == 2) {
        if ((uVar1 < 0x58) || (uVar2 < 0x10)) {
          uVar6 = 0xc0000023;
        }
        else {
          uVar6 = USBC_SetContentId(param_1,(longlong)plVar7,puVar8);
        }
      }
      else {
        uVar6 = 0xc0000002;
      }
    }
    else {
      uVar6 = 0xc0000225;
    }
  }
  else {
    uVar6 = 0xc0000230;
  }
  return uVar6;
}



===== USBC_Create @ 14002c6e8 =====

ulonglong USBC_Create(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  
  if (*(char *)(param_1 + 4) == '\0') {
    uVar1 = 0xc00000bb;
    UsbcCompleteIrp(*(longlong *)(param_1 + 0xf0),0xc00000bb,param_2);
  }
  else {
    uVar1 = UsbcForwardIrp(param_1 + 8,*(undefined8 *)(param_1 + 0x30),param_2);
    uVar1 = uVar1 & 0xffffffff;
  }
  return uVar1;
}



===== InvokePdoEnableCallbacks @ 14002c72c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int InvokePdoEnableCallbacks(longlong param_1)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  undefined1 uVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  code *pcVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  int iVar11;
  bool bVar12;
  
  iVar11 = 0;
  pcVar8 = (code *)0x0;
  if (((*(uint *)(param_1 + 0x4d4) & 2) != 0) && (*(code **)(param_1 + 0x508) != (code *)0x0)) {
    pcVar8 = *(code **)(param_1 + 0x508);
  }
  iVar3 = *(int *)(param_1 + 0x74);
  if (pcVar8 != (code *)0x0) {
    uVar6 = 0;
    bVar12 = iVar3 != 0;
    iVar3 = iVar11;
    if (bVar12) {
      do {
        lVar7 = uVar6 * 0x58 + *(longlong *)(param_1 + 0x478);
        lVar1 = *(longlong *)(lVar7 + 0x10);
        if (lVar1 == 0) {
          lVar1 = *(longlong *)**(undefined8 **)(lVar7 + 8);
          uVar9 = *(undefined1 *)(lVar1 + 5);
          uVar4 = *(undefined1 *)(lVar1 + 6);
          uVar10 = *(undefined1 *)(lVar1 + 7);
        }
        else {
          uVar9 = *(undefined1 *)(lVar1 + 4);
          uVar4 = *(undefined1 *)(lVar1 + 5);
          uVar10 = *(undefined1 *)(lVar1 + 6);
        }
        cVar2 = (*pcVar8)(*(undefined8 *)(param_1 + 0x4e8),*(undefined1 *)(lVar7 + 5),
                          *(undefined1 *)(lVar7 + 6),uVar9,uVar4,uVar10);
        if (cVar2 == '\0') {
          *(uint *)(lVar7 + 0x50) = *(uint *)(lVar7 + 0x50) | 0x10;
        }
        else {
          iVar11 = iVar11 + 1;
        }
        uVar5 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
        iVar3 = iVar11;
      } while (uVar5 < *(uint *)(param_1 + 0x74));
    }
  }
  return iVar3;
}



===== PdoRemoveDevice @ 14002c80c =====

undefined8 PdoRemoveDevice(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0xe8);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    param_3 = 2;
    WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x188),4,2,0x29,
                      &WPP_b3b1f78e430d366987b43aeeb20f80f4_Traceguids,
                      (char)*(undefined8 *)(param_1 + 0xe0));
  }
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x14) = 8;
  CompleteFunctionIdleIrp(param_1,0xc0000120);
  CompletePdoWaitWakeIrp(param_1,0xc0000120,param_3);
  if (*(int *)(param_1 + 0x18) != 9) {
    if (*(char *)(lVar1 + 0x55a) != '\0') {
      LockSyncSendSetFeatureControlRequestForFunctionSuspend(lVar1,param_1,0);
    }
    SetPdoIdle(lVar1,param_1,1,1,'\x01');
    ResumeIdleTimer(lVar1);
  }
  return 0;
}



===== ChangeParentD3ColdStateLocked @ 14002c8e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ChangeParentD3ColdStateLocked(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  char *pcVar3;
  uint uVar4;
  ulonglong uVar5;
  char cVar6;
  
  cVar6 = '\0';
  if (*(char *)(param_1 + 0x1bb) == '\0') {
    *(undefined1 *)(param_1 + 0x1bb) = 1;
    while( true ) {
      uVar5 = 0;
      uVar1 = **(uint **)(param_1 + 0x80);
      if (uVar1 != 0) {
        do {
          lVar2 = *(longlong *)(*(longlong *)(*(uint **)(param_1 + 0x80) + uVar5 * 2 + 2) + 0x40);
          if ((int)uVar5 == 0) {
            cVar6 = *(char *)(lVar2 + 0x7d);
          }
          else if ((cVar6 == '\0') || (*(char *)(lVar2 + 0x7d) == '\0')) {
            cVar6 = '\0';
          }
          else {
            cVar6 = '\x01';
          }
          uVar4 = (int)uVar5 + 1;
          uVar5 = (ulonglong)uVar4;
        } while (uVar4 < uVar1);
      }
      if (cVar6 == *(char *)(param_1 + 0x1ba)) break;
      *(char *)(param_1 + 0x1ba) = cVar6;
      KeReleaseMutex(param_1 + 0x208,0);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        pcVar3 = "Enabling";
        if (cVar6 == '\0') {
          pcVar3 = "Disabling";
        }
        WPP_RECORDER_SF_qs(*(undefined8 *)(param_1 + 0x560),4,1,0x4f,
                           &WPP_93f6b87810f63f9db566694056813e32_Traceguids,(char)param_1,pcVar3);
      }
      (**(code **)(param_1 + 0x1e0))(*(undefined8 *)(param_1 + 0x1c8),cVar6);
      AcquireMutex(param_1 + 0x208,"D3ColdStateMutex",*(undefined8 *)(param_1 + 0x560));
    }
    *(undefined1 *)(param_1 + 0x1bb) = 0;
  }
  return;
}



===== PdoInvokeIdleCallbackWorker @ 14002ca40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdoInvokeIdleCallbackWorker(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  
  lVar1 = *(longlong *)(param_2 + 0x78);
  *(undefined8 *)(param_2 + 0x78) = 0;
  lVar2 = *(longlong *)(lVar1 + 0xe8);
  puVar3 = *(undefined8 **)(*(longlong *)(param_2 + 0xb8) + 0x20);
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qq(*(undefined8 *)(lVar2 + 0x560),4,7,0x44,
                       &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,(char)puVar3,(char)*puVar3);
  }
  (*(code *)*puVar3)(puVar3[1]);
  IoCsqInsertIrp(lVar1 + 0x78,param_2,0);
  UsbcReleaseRemoveLock(lVar2,0x14002ca40);
  IoReleaseRemoveLockEx(lVar2 + 200,PdoInvokeIdleCallbackWorker,0x20);
  return;
}



===== WppInitKm @ 14002cb20 =====

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



===== USBC_RegisterWmi @ 14002cbf8 =====

void USBC_RegisterWmi(longlong param_1)

{
  int iVar1;
  
  if ((*(char *)(param_1 + 0x488) == '\0') && (wmiInit != '\0')) {
    memset((undefined4 *)(param_1 + 0x490),0,0x40);
    *(undefined8 *)(param_1 + 0x4b0) = 0;
    *(undefined8 *)(param_1 + 0x4b8) = 0;
    *(undefined8 *)(param_1 + 0x4c0) = 0;
    *(undefined8 *)(param_1 + 0x4c8) = 0;
    *(undefined ***)(param_1 + 0x498) = &guidList;
    *(code **)(param_1 + 0x4a0) = USBC_QueryWmiRegInfo;
    *(code **)(param_1 + 0x4a8) = USBC_QueryWmiDataBlock;
    *(undefined4 *)(param_1 + 0x490) = 1;
    iVar1 = IoWMIRegistrationControl(*(undefined8 *)(param_1 + 0x20),1);
    if (iVar1 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,10,
                          &WPP_6d0bacebb5b23e7eaf002d06c58cc20e_Traceguids,(char)iVar1);
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x488) = 1;
    }
  }
  return;
}



===== AllocateDriverGlobalIFRLog @ 14002ccd4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AllocateDriverGlobalIFRLog(void)

{
  int iVar1;
  undefined8 *puVar2;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28 [4];
  
  local_28[3] = __security_cookie ^ (ulonglong)auStack_78;
  puVar2 = &local_58;
  local_28[2] = 0;
  uStack_50 = 0x200000002;
  local_58 = 0x10;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28[0] = 0;
  local_28[1] = 0;
  imp_WppRecorderConfigure(WPP_GLOBAL_Control);
  local_38 = 0;
  local_48 = 0x38;
  local_28[0] = local_28[0] & 0xffffffffffffff00;
  uStack_30 = CONCAT44(0x10,(undefined4)uStack_30);
  uStack_30 = uStack_30 & 0xffffffffffffff00;
  local_28[2] = 0x200000002;
  uStack_40 = 0xc800000200;
  RtlStringCchCopyA((char *)local_28,puVar2,0x140017c60);
  iVar1 = imp_WppRecorderLogCreate(WPP_GLOBAL_Control,&local_48,&g_RecorderLog);
  if (iVar1 < 0) {
    g_RecorderLog = 0;
  }
  return;
}



===== D3ColdSupportInterfaceFunctionGetBusDriverD3ColdSupport @ 14002cdd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
D3ColdSupportInterfaceFunctionGetBusDriverD3ColdSupport
          (longlong param_1,char *param_2,undefined8 param_3)

{
  undefined4 uVar1;
  char *pcVar2;
  undefined8 in_stack_ffffffffffffffd8;
  
  uVar1 = (**(code **)(*(longlong *)(param_1 + 0xe8) + 0x1f8))
                    (*(undefined8 *)(*(longlong *)(param_1 + 0xe8) + 0x1c8));
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    pcVar2 = "TRUE";
    if (*param_2 == '\0') {
      pcVar2 = "FALSE";
    }
    WPP_RECORDER_SF_qsd(*(undefined8 *)(param_1 + 0x188),pcVar2,param_3,0x5d,
                        in_stack_ffffffffffffffd8,(char)*(undefined8 *)(param_1 + 0xe0),pcVar2,
                        (char)uVar1);
  }
  return uVar1;
}



===== USBC_SystemControl @ 14002ce68 =====

ulonglong USBC_SystemControl(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  
  if (*(char *)(param_1 + 4) == '\0') {
    uVar1 = 0xc00000bb;
    UsbcCompleteIrp(*(longlong *)(param_1 + 0xf0),0xc00000bb,param_2);
  }
  else {
    uVar1 = USBC_ParentSystemControl(param_1 + 8,param_2);
    uVar1 = uVar1 & 0xffffffff;
  }
  return uVar1;
}



===== USBC_ParentSystemControl @ 14002cea8 =====

ulonglong USBC_ParentSystemControl(longlong param_1,longlong param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  int local_res8 [2];
  
  local_res8[0] = 0;
  if ((*(char *)(param_1 + 0x488) == '\0') || (wmiInit == '\0')) {
    uVar3 = *(undefined8 *)(param_1 + 0x28);
LAB_14002cecf:
    uVar2 = UsbcForwardIrp(param_1,uVar3,param_2);
    uVar2 = uVar2 & 0xffffffff;
  }
  else {
    uVar1 = WmiSystemControl(param_1 + 0x490,*(undefined8 *)(param_1 + 0x20),param_2,local_res8);
    uVar2 = (ulonglong)uVar1;
    if (local_res8[0] != 0) {
      if (local_res8[0] != 1) {
        uVar3 = *(undefined8 *)(param_1 + 0x28);
        goto LAB_14002cecf;
      }
      IofCompleteRequest(param_2,0);
    }
    UsbcReleaseRemoveLock(param_1,param_2);
    IoReleaseRemoveLockEx(param_1 + 200,param_2,0x20);
  }
  return uVar2;
}



===== CheckParentIdle @ 14002cf74 =====

void CheckParentIdle(longlong param_1)

{
  longlong lVar1;
  
  if ((*(uint *)(param_1 + 0x4d0) & 0x10) == 0) {
    lVar1 = param_1 + 0x388;
    AcquireMutex(lVar1,"idleTimerStateMutex",*(undefined8 *)(param_1 + 0x560));
    if (*(int *)(param_1 + 0x358) == 0) {
      *(undefined4 *)(param_1 + 0x358) = 2;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qLL(*(undefined8 *)(param_1 + 0x560),4,7,10,
                            &WPP_1cf86bba40ed35c265a8b44ea34664aa_Traceguids,
                            (char)*(undefined8 *)(param_1 + 0x20),0,2);
      }
      KeReleaseMutex(lVar1);
      EnableIdleTimer(param_1,'\0',0x50435049);
    }
    else {
      KeReleaseMutex(lVar1,0);
    }
  }
  return;
}



===== USBC_UnregisterWmi @ 14002d04c =====

void USBC_UnregisterWmi(longlong param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x488) != '\0') {
    iVar1 = IoWMIRegistrationControl(*(undefined8 *)(param_1 + 0x20),2);
    if ((iVar1 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0xb,
                        &WPP_6d0bacebb5b23e7eaf002d06c58cc20e_Traceguids,(char)iVar1);
    }
    *(undefined1 *)(param_1 + 0x488) = 0;
  }
  return;
}



===== SetPdoRegistryParameter @ 14002d0c8 =====

int SetPdoRegistryParameter
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined4 param_5)

{
  int iVar1;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  
  local_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  RtlInitUnicodeString(&local_20);
  iVar1 = IoOpenDeviceRegistryKey(param_1,1,0x1f0000,&local_28);
  if (-1 < iVar1) {
    iVar1 = ZwSetValueKey(local_28,&local_20,0,param_5,param_3,param_4);
    ZwClose(local_28);
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_d(g_RecorderLog,4,1,0x12,&WPP_f92c053e4bc73e3ba96b7022813d3d4c_Traceguids,
                      (char)iVar1);
  }
  return iVar1;
}



===== USBC_WmiDriverEntry @ 14002d1b0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 USBC_WmiDriverEntry(undefined8 param_1,ushort *param_2)

{
  undefined8 uVar1;
  
  _DAT_14001c562 = *param_2 + 2;
  _wmiRegistryPath = *param_2;
  DAT_14001c568 = (void *)ExAllocatePool2(0x40,_DAT_14001c562,0x43627355);
  if (DAT_14001c568 == (void *)0x0) {
    uVar1 = 0xc000009a;
  }
  else {
    memmove(DAT_14001c568,*(void **)(param_2 + 4),(ulonglong)*param_2);
    uVar1 = 0;
    wmiInit = 1;
  }
  return uVar1;
}



===== GetFunctionMSOSCompatibleIDs @ 14002d224 =====

ulonglong GetFunctionMSOSCompatibleIDs(longlong param_1,longlong *param_2,longlong *param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  
  uVar2 = *(ulonglong *)(param_1 + 0xe8);
  uVar4 = 0;
  *param_2 = 0;
  *param_3 = 0;
  lVar1 = *(longlong *)(uVar2 + 0x460);
  if (*(longlong *)(uVar2 + 0x468) == 0) {
    if (lVar1 != 0) {
      for (; uVar4 < *(byte *)(lVar1 + 8); uVar4 = uVar4 + 1) {
        uVar3 = (ulonglong)uVar4;
        uVar2 = 0;
        if ((uint)*(byte *)(lVar1 + 0x10 + uVar3 * 0x18) == *(uint *)(param_1 + 8)) {
          *param_2 = lVar1 + 0x12 + uVar3 * 0x18;
          *param_3 = lVar1 + 0x1a + uVar3 * 0x18;
          return 1;
        }
      }
    }
    uVar2 = uVar2 & 0xffffffffffffff00;
  }
  else {
    uVar2 = GetFunctionMsOs20CompatibleIDs(param_1,param_2,param_3);
  }
  return uVar2;
}



===== GetFunctionMsOs20CompatibleIDs @ 14002d2a4 =====

ulonglong GetFunctionMsOs20CompatibleIDs(longlong param_1,longlong *param_2,longlong *param_3)

{
  ulonglong uVar1;
  undefined **ppuVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  ulonglong local_res20;
  
  ppuVar2 = (undefined **)GetFunctionMsOs20FunctionSubset(param_1);
  if (ppuVar2 != (undefined **)0x0) {
    uVar4 = (ulonglong)*(ushort *)((longlong)ppuVar2 + 6) + (longlong)ppuVar2;
    uVar1 = (ulonglong)*(ushort *)ppuVar2 + (longlong)ppuVar2;
    do {
      if (uVar1 == 0) goto LAB_14002d300;
      local_res20 = uVar1;
      if (*(short *)(uVar1 + 2) == 3) {
        uVar3 = Feature_1916511546__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar3 == 0) || (uVar1 + 0x14 <= uVar4)) {
          *param_2 = uVar1 + 4;
          *param_3 = uVar1 + 0xc;
          return CONCAT71((int7)(uVar1 + 0xc >> 8),1);
        }
        ppuVar2 = &WPP_RECORDER_INITIALIZED;
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002d300;
        uVar5 = 0x4e;
        goto LAB_14002d32d;
      }
      ppuVar2 = (undefined **)GetNextMsOs20Descriptor(uVar4,&local_res20);
      uVar1 = local_res20;
    } while ((char)ppuVar2 != '\0');
    ppuVar2 = &WPP_RECORDER_INITIALIZED;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar5 = 0x4f;
LAB_14002d32d:
      ppuVar2 = (undefined **)
                WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x188),2,8,uVar5,
                                 &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids);
    }
  }
LAB_14002d300:
  return (ulonglong)ppuVar2 & 0xffffffffffffff00;
}



===== GetParentNodeInfo @ 14002d394 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong GetParentNodeInfo(longlong param_1,undefined4 *param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  longlong lVar6;
  ulonglong uVar7;
  uint uVar8;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_78;
  lVar2 = *(longlong *)(param_1 + 0x40);
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  uVar1 = *(int *)(lVar2 + 0x7c) * 4 + 0x4ae;
  if (param_3 < uVar1) {
    uVar7 = 0xc0000023;
  }
  else {
    memset(param_2,0,(ulonglong)param_3);
    param_2[1] = uVar1;
    *param_2 = 0x5553424e;
    param_2[0x16] = 2;
    uVar5 = UsbcGetTopologyAddress(lVar2 + 8,&local_58);
    uVar7 = 0;
    if ((int)uVar5 < 0) {
      *param_4 = 0;
      return uVar5;
    }
    uVar5 = 0;
    *(undefined8 *)(param_2 + 0x17) = local_58;
    *(undefined8 *)(param_2 + 0x19) = uStack_50;
    *(undefined8 *)(param_2 + 0x1b) = local_48;
    *(undefined8 *)(param_2 + 0x1d) = uStack_40;
    uVar4 = *(undefined8 *)(lVar2 + 0x70);
    *(undefined8 *)(param_2 + 0x1f) = *(undefined8 *)(lVar2 + 0x68);
    *(undefined8 *)(param_2 + 0x21) = uVar4;
    *(undefined2 *)(param_2 + 0x23) = *(undefined2 *)(lVar2 + 0x78);
    puVar3 = *(undefined8 **)(lVar2 + 0x40);
    *(undefined8 *)((longlong)param_2 + 0x8e) = *puVar3;
    *(undefined1 *)((longlong)param_2 + 0x96) = *(undefined1 *)(puVar3 + 1);
    *(undefined1 *)((longlong)param_2 + 0x97) = *(undefined1 *)(*(longlong *)(lVar2 + 0x40) + 5);
    *(undefined1 *)(param_2 + 0x26) = *(undefined1 *)(lVar2 + 0x7c);
    if (*(int *)(lVar2 + 0x7c) != 0) {
      do {
        lVar6 = uVar5 * 0x58 + *(longlong *)(lVar2 + 0x480);
        *(undefined1 *)((longlong)param_2 + uVar5 * 4 + 0x99) = *(undefined1 *)(lVar6 + 4);
        *(undefined1 *)((longlong)param_2 + uVar5 * 4 + 0x9a) = *(undefined1 *)(lVar6 + 5);
        *(undefined1 *)((longlong)param_2 + uVar5 * 4 + 0x9b) = *(undefined1 *)(lVar6 + 6);
        if (*(longlong *)(lVar6 + 0x48) != 0) {
          *(bool *)(param_2 + uVar5 + 0x27) =
               (*(uint *)(*(longlong *)(*(longlong *)(lVar6 + 0x48) + 0x40) + 0x130) & 0x17) != 0;
        }
        uVar8 = (int)uVar5 + 1;
        uVar5 = (ulonglong)uVar8;
      } while (uVar8 < *(uint *)(lVar2 + 0x7c));
    }
  }
  *param_4 = uVar1;
  return uVar7;
}



===== RegQueryGenericCompositeUSBDeviceString @ 14002d4ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RegQueryGenericCompositeUSBDeviceString(void)

{
  code *pcVar1;
  undefined8 local_88;
  undefined8 uStack_80;
  code *local_78;
  undefined4 local_70;
  wchar_t *local_68;
  undefined8 *local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_30;
  
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  local_78 = GetConfigValue;
  local_68 = L"GenericCompositeUSBDeviceString\n";
  local_60 = &GenericCompositeUSBDeviceString;
  local_70 = 4;
  local_88 = 0;
  uStack_80 = 0;
  RtlInitUnicodeString(&local_88,L"RtlQueryRegistryValuesEx");
  pcVar1 = (code *)MmGetSystemRoutineAddress(&local_88);
  if (pcVar1 == (code *)0x0) {
    pcVar1 = RtlQueryRegistryValues_exref;
  }
  (*pcVar1)(2,L"usbflags",&local_78,0,0);
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14002d5a4 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  undefined **ppuVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  bool bVar6;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding
                     ((longlong *)&Feature_SPR_HardenInClient__private_descriptor);
  if (plVar1 != (longlong *)0x0) {
    uVar4 = 0;
    uVar5 = 0x180;
    do {
      uVar3 = *(uint *)*plVar1;
      if ((uVar3 >> 9 & 1) != 0) {
        if (((uint)uVar5 & uVar3) == 0) {
          bVar6 = *(char *)((longlong)plVar1 + 0x1f) != '\0';
        }
        else {
          bVar6 = (uVar3 & (uint)uVar5) == 0x100;
        }
        uVar3 = uVar3 & 0x40 ^ (uint)bVar6 << 6 | (uint)uVar4 & 0xffffffbf;
        uVar4 = (ulonglong)uVar3;
        LOCK();
        *(uint *)*plVar1 = *(uint *)*plVar1 ^ uVar3;
        UNLOCK();
      }
      plVar1 = wil_details_FeatureDescriptors_SkipPadding(plVar1 + 7);
    } while (plVar1 != (longlong *)0x0);
  }
  ppuVar2 = &Feature_SPR_HardenInClient__private_descriptor;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar2);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    ppuVar2 = (undefined **)(plVar1 + 7);
  }
  return;
}



===== WppLoadTracingSupport @ 14002d65c =====

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



===== D3ColdSupportInterfaceFunctionGetIdleWakeInfo @ 14002d7a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
D3ColdSupportInterfaceFunctionGetIdleWakeInfo
          (longlong param_1,undefined1 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if ((*(longlong *)(param_1 + 0x180) == 0) ||
     (*(char *)(*(longlong *)(param_1 + 0x180) + 0x39) != '\0')) {
    uVar1 = (**(code **)(*(longlong *)(param_1 + 0xe8) + 0x1e8))
                      (*(undefined8 *)(*(longlong *)(param_1 + 0xe8) + 0x1c8));
  }
  else {
    *param_3 = 0;
    uVar1 = 0;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qLL(*(undefined8 *)(param_1 + 0x188),5,3,0x5b,
                        &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,
                        (char)*(undefined8 *)(param_1 + 0xe0),(char)*param_3,param_2);
  }
  return uVar1;
}



===== USBC_QueryWmiRegInfo @ 14002d880 =====

undefined8
USBC_QueryWmiRegInfo
          (longlong param_1,undefined4 *param_2,undefined8 param_3,undefined8 *param_4,
          undefined8 param_5,undefined8 *param_6)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  *param_4 = &wmiRegistryPath;
  *param_2 = 0x20;
  *param_6 = *(undefined8 *)(lVar1 + 0x20);
  return 0;
}



===== USBC_WmiUnload @ 14002d8ac =====

void USBC_WmiUnload(void)

{
  if (DAT_14001c568 != 0) {
    ExFreePoolWithTag(DAT_14001c568,0x43627355);
    DAT_14001c568 = 0;
  }
  wmiInit = 0;
  return;
}



===== AllocateResourcesForFunctionSuspend @ 14002d8e8 =====

int AllocateResourcesForFunctionSuspend(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined2 uVar5;
  
  lVar2 = ExAllocatePool2(0x40,0x68,0x43627355);
  if (lVar2 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffff66;
    }
    uVar5 = 0x40;
LAB_14002d976:
    WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x560),2,8,uVar5,
                     &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids);
    return -0x3fffff66;
  }
  *(longlong *)(param_2 + 0x180) = lVar2;
  lVar3 = IoAllocateWorkItem(*(undefined8 *)(param_2 + 0xe0));
  *(longlong *)(lVar2 + 8) = lVar3;
  if (lVar3 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffff66;
    }
    uVar5 = 0x41;
    goto LAB_14002d976;
  }
  lVar3 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x28) >> 8),
                                 *(undefined1 *)(*(longlong *)(param_1 + 0x28) + 0x4c)),0);
  *(longlong *)(lVar2 + 0x28) = lVar3;
  if (lVar3 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffff66;
    }
    uVar5 = 0x42;
  }
  else {
    lVar3 = IoAllocateWorkItem(*(undefined8 *)(param_2 + 0xe0));
    *(longlong *)(lVar2 + 0x50) = lVar3;
    if (lVar3 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return -0x3fffff66;
      }
      uVar4 = *(undefined8 *)(param_1 + 0x560);
      uVar5 = 0x43;
      goto LAB_14002da4b;
    }
    lVar3 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0x28) >> 8),
                                   *(undefined1 *)(*(longlong *)(param_1 + 0x28) + 0x4c)),0);
    *(longlong *)(lVar2 + 0x48) = lVar3;
    if (lVar3 != 0) {
      iVar1 = USBD_UrbAllocate(*(longlong *)(param_1 + 0x548),(undefined8 *)(lVar2 + 0x40));
      if (-1 < iVar1) {
        KeInitializeSpinLock(lVar2);
        *(undefined2 *)(lVar2 + 0x3a) = 0;
        *(undefined1 *)(lVar2 + 0x38) = 0;
        return 0;
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x560),2,8,0x45,
                          &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,(char)iVar1);
      }
      return iVar1;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return -0x3fffff66;
    }
    uVar5 = 0x44;
  }
  uVar4 = *(undefined8 *)(param_2 + 0x188);
LAB_14002da4b:
  WPP_RECORDER_SF_d(uVar4,2,8,uVar5,&WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,0x9a);
  return -0x3fffff66;
}



===== USBC_DriverUnload @ 14002db00 =====

void USBC_DriverUnload(undefined8 param_1)

{
  ulonglong uVar1;
  
  if (GenericCompositeUSBDeviceString != 0) {
    ExFreePoolWithTag(GenericCompositeUSBDeviceString,0);
    GenericCompositeUSBDeviceString = 0;
  }
  uVar1 = Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar1 == 0) {
    SleepstudyHelper_Uninitialize();
  }
  else if (g_SleepstudyLibraryHandle != 0) {
    SleepstudyHelper_Uninitialize();
    g_SleepstudyLibraryHandle = 0;
  }
  USBC_WmiUnload();
  if (g_RecorderLog != 0) {
    imp_WppRecorderLogDelete(WPP_GLOBAL_Control);
    g_RecorderLog = 0;
  }
  wil_UninitializeFeatureStaging();
  WppCleanupKm(param_1);
  return;
}



===== GetFunctionMsOs20FunctionSubset @ 14002db98 =====

ushort * GetFunctionMsOs20FunctionSubset(longlong param_1)

{
  char cVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  ushort *puVar7;
  ushort *puVar8;
  ulonglong uVar9;
  undefined2 uVar10;
  ushort *puVar11;
  ushort *local_res8;
  
  if (*(longlong *)(param_1 + 0x170) == 0) {
    lVar4 = *(longlong *)(*(longlong *)(param_1 + 0xe8) + 0x468);
    uVar5 = Feature_1916511546__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 == 0) {
      uVar5 = (ulonglong)*(ushort *)(lVar4 + 8);
    }
    else {
      uVar2 = *(uint *)(*(longlong *)(param_1 + 0xe8) + 0x470);
      uVar5 = (ulonglong)uVar2;
      if ((*(ushort *)(lVar4 + 8) != uVar2) &&
         ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_dd(*(undefined8 *)(param_1 + 0x188),3,8,0x53,
                           &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,
                           (char)*(ushort *)(lVar4 + 8),(char)uVar2);
      }
    }
    puVar8 = (ushort *)(uVar5 + lVar4);
    local_res8 = *(ushort **)(*(longlong *)(param_1 + 0xe8) + 0x468);
    cVar1 = *(char *)(*(longlong *)(param_1 + 0xe8) + 0x40);
    do {
      puVar7 = local_res8;
      if (local_res8[1] == 1) {
        uVar5 = Feature_1916511546__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar5 != 0) && (puVar8 < puVar7 + 4)) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14002de8e;
          uVar10 = 0x54;
          goto LAB_14002de78;
        }
        if ((char)puVar7[2] == cVar1) {
          puVar11 = (ushort *)((ulonglong)puVar7[3] + (longlong)puVar7);
          uVar5 = Feature_1916511546__private_IsEnabledDeviceUsageNoInline();
          if (((int)uVar5 != 0) && (puVar8 < puVar11)) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x188),3,8,0x55,
                               &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids);
            }
            puVar11 = puVar8;
          }
          puVar8 = puVar11;
          uVar5 = Feature_1916511546__private_IsEnabledDeviceUsageNoInline();
          puVar7 = (ushort *)((ulonglong)*puVar7 + (longlong)puVar7);
          if (((int)uVar5 != 0) && (puVar8 < puVar7 + 2)) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_14002de8e;
            uVar10 = 0x56;
            goto LAB_14002de78;
          }
          local_res8 = puVar7;
          if (puVar7 != (ushort *)0x0) goto LAB_14002ddd9;
          break;
        }
      }
      uVar6 = GetNextMsOs20Descriptor((ulonglong)puVar8,(ulonglong *)&local_res8);
      if ((char)uVar6 == '\0') {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002de8e;
        uVar10 = 0x57;
        goto LAB_14002de78;
      }
    } while (local_res8 != (ushort *)0x0);
    local_res8 = *(ushort **)(*(longlong *)(param_1 + 0xe8) + 0x468);
LAB_14002ddd9:
    do {
      puVar7 = local_res8;
      if (local_res8[1] == 2) {
        uVar5 = Feature_1916511546__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar5 != 0) {
          if (puVar8 < puVar7 + 4) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar10 = 0x58;
LAB_14002de78:
              WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x188),2,8,uVar10,
                               &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids);
            }
            break;
          }
          if ((puVar7[3] < 8) || (puVar8 < (ushort *)((ulonglong)puVar7[3] + (longlong)puVar7))) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              uVar10 = 0x59;
              goto LAB_14002de78;
            }
            break;
          }
        }
        if ((uint)(byte)puVar7[2] == *(uint *)(param_1 + 8)) {
          *(ushort **)(param_1 + 0x170) = puVar7;
          return puVar7;
        }
      }
      uVar6 = GetNextMsOs20Descriptor((ulonglong)puVar8,(ulonglong *)&local_res8);
      if ((char)uVar6 == '\0') {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar10 = 0x5a;
          goto LAB_14002de78;
        }
        break;
      }
    } while (local_res8 != (ushort *)0x0);
LAB_14002de8e:
    puVar8 = (ushort *)0x0;
  }
  else {
    uVar5 = Feature_1916511546__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 != 0) {
      uVar5 = *(ulonglong *)(param_1 + 0x170);
      uVar3 = *(ulonglong *)(*(longlong *)(param_1 + 0xe8) + 0x468);
      uVar9 = *(uint *)(*(longlong *)(param_1 + 0xe8) + 0x470) + uVar3;
      if ((((uVar5 < uVar3) || (uVar9 < uVar5 + 8)) || (*(ushort *)(uVar5 + 6) < 8)) ||
         (uVar9 < *(ushort *)(uVar5 + 6) + uVar5)) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x188),2,8,0x52,
                           &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids);
        }
        *(undefined8 *)(param_1 + 0x170) = 0;
        goto LAB_14002de8e;
      }
    }
    puVar8 = *(ushort **)(param_1 + 0x170);
  }
  return puVar8;
}



===== InstallExtPropDesc @ 14002deb8 =====

void InstallExtPropDesc(longlong param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  int iVar3;
  ulonglong uVar4;
  uint *puVar5;
  uint *puVar6;
  longlong lVar7;
  undefined8 uVar8;
  byte bVar9;
  uint uVar10;
  undefined2 uVar11;
  ushort local_res8 [4];
  uint local_res10 [2];
  uint local_res18 [2];
  uint local_res20 [2];
  undefined1 uVar12;
  uint in_stack_ffffffffffffff98;
  undefined4 local_58 [6];
  
  lVar1 = *(longlong *)(param_1 + 0xe0);
  uVar10 = in_stack_ffffffffffffff98 & 0xffffff00;
  local_res18[0] = 0;
  puVar6 = (uint *)0x0;
  local_res10[0] = 0;
  local_res8[0] = 0;
  local_res20[0] = 0;
  iVar3 = GetPdoRegistryParameter
                    (lVar1,u_RevisionId_14001c2b0,local_res18,4,(undefined4 *)0x0,(undefined4 *)0x0,
                     uVar10);
  if (((((iVar3 + 0x80000000U & 0x80000000) == 0) && (iVar3 != -0x3fffffcc)) &&
      ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x188),5,1,0x2e,
                      &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,(char)iVar3);
  }
  uVar10 = uVar10 & 0xffffff00;
  iVar3 = GetPdoRegistryParameter
                    (lVar1,u_VendorRevision_14001c058,local_res10,4,(undefined4 *)0x0,
                     (undefined4 *)0x0,uVar10);
  if ((((iVar3 + 0x80000000U & 0x80000000) == 0) && (iVar3 != -0x3fffffcc)) &&
     (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED &&
      (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)))) {
    WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x188),5,1,0x2f,
                      &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,(char)iVar3);
  }
  uVar4 = GetFunctionMsOs20VendorRevision(param_1,local_res8);
  if ((((char)uVar4 == '\0') &&
      ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(param_1 + 0x188),5,1,0x30,
                     &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids);
  }
  uVar4 = Feature_WinUsb_Print__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar4 != 0) && (*(char *)(param_1 + 0x198) != '\0')) {
    SetPdoRegistryParameter
              (lVar1,u_DeviceInterfaceGuid_14001c200,u__6AA3BDAC_3C99_4BA3_B2CA_A751DB8_14001c230,
               0x4e,1);
  }
  iVar3 = GetPdoRegistryParameter
                    (lVar1,u_ExtPropDescSemaphore_14001c280,(void *)0x0,0,(undefined4 *)0x0,
                     (undefined4 *)0x0,uVar10 & 0xffffff00);
  if (((-1 < iVar3) && (local_res18[0] == *(ushort *)(*(longlong *)(param_1 + 0xe8) + 0x6c))) &&
     (local_res10[0] == local_res8[0])) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    if (*(short *)(WPP_GLOBAL_Control + 0x48) == 0) {
      return;
    }
    uVar11 = 0x31;
    bVar9 = 5;
    uVar10 = 1;
LAB_14002e0d4:
    WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x188),bVar9,uVar10,uVar11,
                      &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,
                      (char)*(undefined8 *)(param_1 + 0xe0));
    return;
  }
  local_res18[0] = (uint)*(ushort *)(*(longlong *)(param_1 + 0xe8) + 0x6c);
  local_res10[0] = (uint)local_res8[0];
  if (*(longlong *)(*(longlong *)(param_1 + 0xe8) + 0x468) != 0) {
    iVar3 = InstallMsOs20RegistryValues(param_1);
    if (iVar3 < 0) {
      return;
    }
    SetPdoRegistryParameter(lVar1,u_VendorRevision_14001c058,local_res10,4,4);
    SetPdoRegistryParameter(lVar1,u_RevisionId_14001c2b0,local_res18,4,4);
    local_58[0] = 1;
    SetPdoRegistryParameter(lVar1,u_ExtPropDescSemaphore_14001c280,local_58,4,4);
    return;
  }
  SetPdoRegistryParameter(lVar1,u_VendorRevision_14001c058,local_res10,4,4);
  SetPdoRegistryParameter(lVar1,u_RevisionId_14001c2b0,local_res18,4,4);
  local_58[0] = 1;
  SetPdoRegistryParameter(lVar1,u_ExtPropDescSemaphore_14001c280,local_58,4,4);
  puVar5 = (uint *)ExAllocatePool2(0x40,10,0x43627355);
  if (puVar5 == (uint *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return;
    }
    uVar11 = 0x32;
    bVar9 = 2;
    uVar10 = 8;
    goto LAB_14002e0d4;
  }
  iVar3 = GetMsOsFeatureDescriptor
                    (*(longlong *)(param_1 + 0xe8),1,*(undefined1 *)(param_1 + 8),5,puVar5,10,
                     local_res20);
  if (iVar3 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002e43b;
    uVar11 = 0x33;
LAB_14002e256:
    uVar2 = (undefined1)iVar3;
    uVar12 = (undefined1)*(undefined8 *)(param_1 + 0xe0);
LAB_14002e26b:
    WPP_RECORDER_SF_qd(*(undefined8 *)(param_1 + 0x188),2,8,uVar11,
                       &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,uVar12,uVar2);
  }
  else {
    if (((local_res20[0] == 10) && (9 < *puVar5)) &&
       (((short)puVar5[1] == 0x100 &&
        ((*(short *)((longlong)puVar5 + 6) == 5 && ((short)puVar5[2] != 0)))))) {
      puVar6 = (uint *)ExAllocatePool2(0x40,*puVar5,0x43627355);
      if (puVar6 == (uint *)0x0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002e43b;
        uVar12 = (undefined1)*(undefined8 *)(param_1 + 0xe0);
        uVar11 = 0x35;
      }
      else {
        iVar3 = GetMsOsFeatureDescriptor
                          (*(longlong *)(param_1 + 0xe8),1,*(undefined1 *)(param_1 + 8),5,puVar6,
                           *puVar5,local_res20);
        uVar10 = local_res20[0];
        if (iVar3 < 0) {
          if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
          goto LAB_14002e43b;
          uVar11 = 0x36;
          goto LAB_14002e256;
        }
        if ((local_res20[0] == *puVar5) && (lVar7 = RtlCompareMemory(puVar5,puVar6,10), lVar7 == 10)
           ) {
          uVar8 = USBD_ValidateExtendedPropertyDescriptor(puVar6,uVar10);
          iVar3 = (int)uVar8;
          if (iVar3 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED)
            goto LAB_14002e43b;
            uVar11 = 0x38;
          }
          else {
            uVar4 = USBD_InstallExtPropDescSections(lVar1,(undefined8 *)puVar6,*puVar6);
            iVar3 = (int)uVar4;
            if ((-1 < iVar3) ||
               ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED))
            goto LAB_14002e43b;
            uVar11 = 0x39;
          }
          uVar2 = (undefined1)iVar3;
          uVar12 = (undefined1)*(undefined8 *)(param_1 + 0xe0);
          goto LAB_14002e26b;
        }
        if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002e43b;
        uVar12 = (undefined1)*(undefined8 *)(param_1 + 0xe0);
        uVar11 = 0x37;
      }
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_14002e43b;
      uVar12 = (undefined1)*(undefined8 *)(param_1 + 0xe0);
      uVar11 = 0x34;
    }
    WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x188),2,8,uVar11,
                      &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,uVar12);
  }
LAB_14002e43b:
  ExFreePoolWithTag(puVar5,0x43627355);
  if (puVar6 == (uint *)0x0) {
    return;
  }
  ExFreePoolWithTag(puVar6,0x43627355);
  return;
}



===== QueryFunctionPdoID @ 14002e480 =====

uint QueryFunctionPdoID(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  wchar_t *pwVar8;
  short *psVar9;
  byte *pbVar10;
  ulonglong uVar11;
  byte *pbVar12;
  char *pcVar13;
  short *psVar14;
  void *_Dst;
  short *psVar15;
  undefined8 uVar16;
  uint uVar17;
  char **ppcVar18;
  byte bVar19;
  undefined2 uVar20;
  undefined4 unaff_R12D;
  undefined4 uVar21;
  char *pcVar22;
  bool bVar23;
  undefined8 local_res8;
  char *local_res10;
  uint local_res18;
  short *local_res20;
  longlong local_78;
  undefined8 local_70;
  longlong lStack_68;
  undefined8 local_60;
  longlong lStack_58;
  
  lVar1 = *(longlong *)(param_1 + 0xf0);
  bVar23 = false;
  local_78 = 0;
  local_res8 = (char *)(CONCAT44(local_res8._4_4_,unaff_R12D) & 0xffffffffffffff00);
  uVar17 = 1;
  if ((((*(char *)(*(longlong *)(param_1 + 0xe8) + 0x55c) != '\0') &&
       (lVar2 = *(longlong *)(lVar1 + 0x10), lVar2 != 0)) && (*(char *)(lVar2 + 4) == '\x01')) &&
     (*(char *)(lVar2 + 5) == '\0')) {
    bVar23 = *(char *)(lVar2 + 6) == ' ';
    local_res8 = (char *)CONCAT44(local_res8._4_4_,(uint)bVar23);
  }
  puVar3 = *(undefined8 **)(param_2 + 0xb8);
  iVar6 = *(int *)(puVar3 + 1);
  if (iVar6 == 0) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    if ((*(short **)(lVar1 + 0x20) == (short *)0x0) || ((*(uint *)(lVar1 + 0x50) & 1) != 0)) {
      puVar3[-9] = *puVar3;
      puVar3[-8] = puVar3[1];
      puVar3[-7] = puVar3[2];
      puVar3[-6] = puVar3[3];
      puVar3[-5] = puVar3[4];
      puVar3[-4] = puVar3[5];
      puVar3[-3] = puVar3[6];
      *(undefined1 *)((longlong)puVar3 + -0x45) = 0;
      uVar7 = CallDriverSync(*(undefined8 *)(*(longlong *)(param_1 + 0xe8) + 0x20),param_2,'\0',
                             *(undefined8 *)(param_1 + 0xe0));
      if ((int)uVar7 < 0) {
        return uVar7;
      }
      local_res20 = *(short **)(param_2 + 0x38);
      if (local_res20 == (short *)0x0) {
        return uVar7;
      }
      local_res18 = WStrLen(local_res20);
      uVar21 = 0x100;
      if (ExDefaultNonPagedPoolType == 1) {
        uVar21 = 0x40;
      }
      local_res10 = (char *)CONCAT44(local_res10._4_4_,local_res18 + 2);
      local_70 = (ulonglong)(local_res18 + 2);
      local_60 = local_70 * 2;
      psVar14 = (short *)ExAllocatePool2(uVar21,local_60,0x43627355);
      psVar9 = local_res20;
      if (psVar14 == (short *)0x0) {
        uVar7 = 0xc000009a;
      }
      else {
        RtlStringCchCopyExW(psVar14,local_70,local_res20,&local_78);
        if ((undefined2 *)(local_78 + 2) < (undefined2 *)(local_60 + (longlong)psVar14)) {
          *(undefined2 *)(local_78 + 2) = 0;
        }
        else {
          psVar14[(int)local_res10 - 1] = 0;
          psVar14[local_res18] = 0;
        }
        if ((char)local_res8 == '\0') {
          uVar17 = -(uint)(*(char *)(param_1 + 0x130) != '\0') & 2;
        }
        psVar15 = AppendInterfaceNumber(psVar14,*(uint *)(param_1 + 8),uVar17);
        if (psVar15 == (short *)0x0) {
          uVar7 = 0xc000009c;
        }
        else {
          *(short **)(param_2 + 0x38) = psVar15;
        }
        ExFreePoolWithTag(psVar14,0x43627355);
      }
      ExFreePoolWithTag(psVar9,0);
      return uVar7;
    }
    local_res8 = (char *)0x0;
    uVar17 = RtlStringCbLengthW(*(short **)(lVar1 + 0x20),(ulonglong)*(ushort *)(lVar1 + 0x18),
                                &local_res8);
    if ((uVar17 & 0xc0000000) == 0xc0000000) {
      return uVar17;
    }
    if (local_res8 == (char *)0x0) {
      return uVar17;
    }
    uVar21 = 0x100;
    if (ExDefaultNonPagedPoolType == 1) {
      uVar21 = 0x40;
    }
    psVar9 = (short *)ExAllocatePool2(uVar21,(longlong)local_res8 + 4);
    if (psVar9 == (short *)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000009a;
      }
      uVar20 = 0x17;
LAB_14002eb3e:
      WPP_RECORDER_SF_d(*(undefined8 *)(param_1 + 0x188),2,8,uVar20,
                        &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,0x9a);
      return 0xc000009a;
    }
    uVar11 = (longlong)local_res8 + 2U >> 1;
    if (uVar11 != 0) {
      if (uVar11 < 0x80000000) {
        RtlStringCopyWorkerW(psVar9,uVar11,(longlong *)0x0,*(longlong *)(lVar1 + 0x20));
      }
      else {
        *psVar9 = 0;
      }
    }
    *(short **)(param_2 + 0x38) = psVar9;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    uVar20 = 0x16;
LAB_14002eaea:
    WPP_RECORDER_SF_q(*(undefined8 *)(param_1 + 0x188),4,2,uVar20,
                      &WPP_5ea593e3bc6132d88761922c52c886f8_Traceguids,
                      (char)*(undefined8 *)(param_1 + 0xe0));
    return 0;
  }
  if (iVar6 == 1) {
    if ((*(longlong *)(lVar1 + 0x20) == 0) || ((*(uint *)(lVar1 + 0x50) & 1) != 0)) {
      puVar3[-9] = *puVar3;
      puVar3[-8] = puVar3[1];
      puVar3[-7] = puVar3[2];
      puVar3[-6] = puVar3[3];
      puVar3[-5] = puVar3[4];
      puVar3[-4] = puVar3[5];
      puVar3[-3] = puVar3[6];
      *(undefined1 *)((longlong)puVar3 + -0x45) = 0;
      uVar7 = CallDriverSync(*(undefined8 *)(*(longlong *)(param_1 + 0xe8) + 0x20),param_2,'\0',
                             *(undefined8 *)(param_1 + 0xe0));
      if ((int)uVar7 < 0) {
        return uVar7;
      }
      psVar9 = *(short **)(param_2 + 0x38);
      if (!bVar23) {
        uVar17 = -(uint)(*(char *)(param_1 + 0x130) != '\0') & 2;
      }
      psVar15 = AppendInterfaceNumber(psVar9,*(uint *)(param_1 + 8),uVar17);
      psVar14 = psVar15;
      if ((*(longlong *)(lVar1 + 0x20) != 0) && (psVar15 != (short *)0x0)) {
        ExFreePoolWithTag(psVar9,0);
        psVar14 = AppendPdoIds(psVar15,(ushort *)(lVar1 + 0x18));
        psVar9 = psVar15;
      }
      ExFreePoolWithTag(psVar9,0);
      if (psVar14 == (short *)0x0) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        return 0xc0000001;
      }
      *(short **)(param_2 + 0x38) = psVar14;
      return 0;
    }
    uVar16 = 0x100;
    if (ExDefaultNonPagedPoolType == 1) {
      uVar16 = 0x40;
    }
    _Dst = (void *)ExAllocatePool2(uVar16,(ulonglong)*(ushort *)(lVar1 + 0x18) + 2,0x43627355);
    if (_Dst == (void *)0x0) {
      *(undefined8 *)(param_2 + 0x38) = 0;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000009a;
      }
      uVar20 = 0x15;
      goto LAB_14002eb3e;
    }
    memmove(_Dst,*(void **)(lVar1 + 0x20),(ulonglong)*(ushort *)(lVar1 + 0x18));
    *(void **)(param_2 + 0x38) = _Dst;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    uVar20 = 0x14;
    goto LAB_14002eaea;
  }
  if (iVar6 != 2) {
    if (iVar6 != 3) {
      return *(uint *)(param_2 + 0x30);
    }
    pwVar8 = MemDup(L"0000",10);
    if (pwVar8 == (wchar_t *)0x0) {
      uVar17 = 0xc000009a;
      pwVar8 = (wchar_t *)0x0;
    }
    else {
      RtlStringCchPrintfW(pwVar8,5,L"%04x",
                          (ulonglong)
                          ((-(uint)(*(char *)(param_1 + 0x12f) != '\0') & 0xc000) +
                          *(int *)(param_1 + 8)));
      uVar17 = 0;
    }
    *(wchar_t **)(param_2 + 0x38) = pwVar8;
    return uVar17;
  }
  local_res20 = (short *)((ulonglong)local_res20 & 0xffffffff00000000);
  if ((*(longlong *)(lVar1 + 0x30) != 0) && ((*(uint *)(lVar1 + 0x50) & 1) == 0)) {
    bVar4 = IsMSOSCompatibleIDFlagSet(param_1);
    local_res8 = (char *)CONCAT71(local_res8._1_7_,bVar4);
    if (bVar4 == 0) {
      uVar16 = 0x100;
      if (ExDefaultNonPagedPoolType == 1) {
        uVar16 = 0x40;
      }
      psVar9 = (short *)ExAllocatePool2(uVar16,(ulonglong)*(ushort *)(lVar1 + 0x28) + 2,0x43627355);
      if (psVar9 != (short *)0x0) {
        memmove(psVar9,*(void **)(lVar1 + 0x30),(ulonglong)*(ushort *)(lVar1 + 0x28));
        goto LAB_14002e5fe;
      }
    }
    else {
      psVar9 = PrependMSOSCompatibleIDs(param_1);
    }
    if (psVar9 == (short *)0x0) {
      *(undefined8 *)(param_2 + 0x38) = 0;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
        return 0xc000009a;
      }
      WPP_RECORDER_SF_sd(*(undefined8 *)(param_1 + 0x188));
      return 0xc000009a;
    }
LAB_14002e5fe:
    *(short **)(param_2 + 0x38) = psVar9;
    if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) {
      return 0;
    }
    WPP_RECORDER_SF_sq(*(undefined8 *)(param_1 + 0x188));
    return 0;
  }
  pbVar10 = *(byte **)**(undefined8 **)(lVar1 + 8);
  if (pbVar10 == (byte *)0x0) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    return 0xc000009a;
  }
  ppcVar18 = &local_res10;
  local_res8 = (char *)0x0;
  local_res10 = (char *)0x0;
  GetFunctionMSOSCompatibleIDs(param_1,&local_res8,(longlong *)ppcVar18);
  if (*(char *)(param_1 + 0x131) == '\0') {
    if (pbVar10[5] == 1) {
      pbVar12 = FindMidiInterfaceDescriptor
                          (*(longlong *)(*(longlong *)(param_1 + 0xe8) + 0x30),
                           *(undefined8 *)**(undefined8 **)(lVar1 + 8),ppcVar18,
                           *(undefined8 *)(param_1 + 0x188));
      if (pbVar12 != (byte *)0x0) {
        local_res20 = (short *)CONCAT44(local_res20._4_4_,1);
        pbVar10 = pbVar12;
      }
    }
LAB_14002e80e:
    pcVar13 = local_res10;
    pcVar22 = local_res8;
  }
  else {
    pbVar10 = (byte *)USBD_ParseConfigurationDescriptorEx
                                (*(undefined8 *)(*(longlong *)(param_1 + 0xe8) + 0x30),pbVar10,
                                 pbVar10[2],*(char *)(param_1 + 0x131),0xffffffff,0xffffffff,
                                 0xffffffff);
    if (((pbVar10[5] != 7) || (pbVar10[6] != 1)) || (pbVar10[7] != 4)) goto LAB_14002e80e;
    uVar11 = Feature_WinUsb_Print__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar11 == 0) || (*(char *)(param_1 + 0x198) == '\0')) {
      iVar6 = IsProtectedPrintEnabled();
      if (iVar6 == 0) {
        iVar6 = CheckIppUsbAltIndex(*(ushort *)(*(longlong *)(param_1 + 0xe8) + 0x68),
                                    *(ushort *)(*(longlong *)(param_1 + 0xe8) + 0x6a),pbVar10[2]);
        pcVar13 = local_res8;
        if (iVar6 == 0) {
          if (local_res8 != (char *)0x0) {
            pbVar10 = (byte *)USBD_ParseConfigurationDescriptorEx
                                        (*(undefined8 *)(*(longlong *)(param_1 + 0xe8) + 0x30),
                                         *(undefined8 *)**(undefined8 **)(lVar1 + 8),pbVar10[2],0,
                                         0xffffffff,0xffffffff,0xffffffff);
            local_res8 = pcVar13;
            goto LAB_14002e80e;
          }
        }
        else {
          *(undefined1 *)(param_1 + 0x130) = 1;
          local_res8 = (char *)0x0;
        }
        goto LAB_14002e74b;
      }
      *(undefined1 *)(param_1 + 0x130) = 1;
      pcVar13 = (char *)0x0;
      pcVar22 = (char *)0x0;
    }
    else {
      local_res8 = s_WINUSB_14001c050;
LAB_14002e74b:
      pcVar13 = (char *)0x0;
      pcVar22 = local_res8;
    }
  }
  local_res8 = pcVar13;
  uVar11 = Feature_WinUsb_Print__private_IsEnabledDeviceUsageNoInline();
  if ((((int)uVar11 == 0) || (pbVar10[5] != 7)) || (*(char *)(param_1 + 0x198) == '\0')) {
    pcVar13 = local_res8;
  }
  else {
    pcVar22 = s_WINUSB_14001c050;
    pcVar13 = (char *)0x0;
  }
  lVar2 = *(longlong *)(lVar1 + 0x10);
  bVar4 = pbVar10[5];
  bVar5 = pbVar10[6];
  bVar19 = pbVar10[7];
  local_res10 = (char *)CONCAT71(local_res10._1_7_,bVar4);
  local_res8 = (char *)CONCAT71(local_res8._1_7_,bVar5);
  local_res18 = CONCAT31(local_res18._1_3_,bVar19);
  if (lVar2 != 0) {
    if ((int)local_res20 != 0) {
      if ((*(byte *)(lVar2 + 2) <= pbVar10[2]) &&
         ((ushort)pbVar10[2] < (ushort)((ushort)*(byte *)(lVar2 + 3) + (ushort)*(byte *)(lVar2 + 2))
         )) goto LAB_14002e89d;
    }
    bVar4 = *(byte *)(lVar2 + 4);
    bVar5 = *(byte *)(lVar2 + 5);
    bVar19 = *(byte *)(lVar2 + 6);
    local_res10 = (char *)CONCAT71(local_res10._1_7_,bVar4);
    local_res8 = (char *)CONCAT71(local_res8._1_7_,bVar5);
    local_res18 = CONCAT31(local_res18._1_3_,bVar19);
  }
LAB_14002e89d:
  local_res20 = BuildCompatibleIDs(pcVar22,pcVar13,*(ushort *)(*(longlong *)(param_1 + 0xe8) + 0x68)
                                   ,bVar4,bVar5,bVar19);
  uVar16 = 0x100;
  if (ExDefaultNonPagedPoolType == 1) {
    uVar16 = 0x40;
  }
  local_60 = 0;
  lStack_58 = 0;
  local_70 = 0;
  lStack_68 = 0;
  lStack_58 = ExAllocatePool2(uVar16,0x10,0x43627355);
  local_60._0_4_ = CONCAT22(0x10,(short)local_60);
  if (lStack_58 == 0) {
    return 0xc0000001;
  }
  if ((((char)local_res10 == '\x01') && ((local_res18 & 0xdf) == 0)) &&
     (uVar16 = GetControllerSuffix((short *)&local_60,param_1), (char)uVar16 != '\0')) {
    uVar21 = 0x100;
    if (ExDefaultNonPagedPoolType == 1) {
      uVar21 = 0x40;
    }
    lStack_68 = ExAllocatePool2(uVar21,0xc0,0x43627355);
    local_70._0_4_ = CONCAT22(0xc0,(ushort)local_70);
    if ((lStack_58 != 0) &&
       (uVar16 = RtlUnicodeStringPrintf
                           ((ushort *)&local_70,
                            L"USB\\Class_%02X&Subclass_%02X&Prot_%02X&%wZ%cUSB\\Class_%02X&Subclass_%02X&%wZ%cUSB\\Class_%02X&%wZ"
                            ,1,(ulonglong)local_res8 & 0xff), -1 < (int)uVar16)) {
      psVar9 = AppendPdoIdsReverse(local_res20,(ushort *)&local_70);
      ExFreePoolWithTag(local_res20,0x43627355);
      goto LAB_14002e9f7;
    }
  }
  psVar9 = local_res20;
LAB_14002e9f7:
  if (lStack_68 != 0) {
    ExFreePoolWithTag(lStack_68,0x43627355);
  }
  if (lStack_58 != 0) {
    ExFreePoolWithTag(lStack_58,0x43627355);
  }
  psVar14 = psVar9;
  if ((*(longlong *)(lVar1 + 0x30) != 0) && (psVar9 != (short *)0x0)) {
    psVar14 = AppendPdoIds(psVar9,(ushort *)(lVar1 + 0x28));
    ExFreePoolWithTag(psVar9,0x43627355);
  }
  *(short **)(param_2 + 0x38) = psVar14;
  return ~-(uint)(psVar14 != (short *)0x0) & 0xc000009a;
}



===== SleepstudyHelper_Initialize @ 14002eeac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int SleepstudyHelper_Initialize(void)

{
  undefined8 uVar1;
  int iVar2;
  ulonglong uVar3;
  
  uVar1 = g_DriverObject;
  iVar2 = RtlRunOnceExecuteOnce
                    (&SleepstudyHelperInitializeRunOnce,SleepstudyHelperInitializeOnce,0,0);
  uVar3 = Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    if ((iVar2 < 0) || (DAT_14001c4d0 == (code *)0x0)) {
      g_SleepstudyLibraryHandle = &SleepstudyHelperUnsupportedHandle;
      return 0;
    }
  }
  else {
    if (iVar2 < 0) {
      return iVar2;
    }
    if (DAT_14001c4d0 == (code *)0x0) {
      return -0x3fffff45;
    }
  }
  iVar2 = (*DAT_14001c4d0)(&g_SleepstudyLibraryHandle,uVar1);
  return iVar2;
}



===== SleepstudyHelper_RegisterPdoWithParentPdo @ 14002ef48 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
SleepstudyHelper_RegisterPdoWithParentPdo
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  undefined *puVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  
  puVar1 = g_SleepstudyLibraryHandle;
  uVar2 = Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 == 0) {
    if (puVar1 != &SleepstudyHelperUnsupportedHandle) {
      if (DAT_14001c4e8 == (code *)0x0) {
        uVar3 = 0xc00000bb;
      }
      else {
        uVar3 = (*DAT_14001c4e8)(puVar1,param_2,param_3,param_4);
      }
      if ((int)uVar3 != -0x3fffff45) {
        return uVar3;
      }
    }
    *param_4 = &SleepstudyHelperUnsupportedHandle;
    uVar3 = 0;
  }
  else if (DAT_14001c4e8 == (code *)0x0) {
    uVar3 = 0xc00000bb;
  }
  else {
    uVar3 = (*DAT_14001c4e8)(puVar1,param_2,param_3,param_4);
  }
  return uVar3;
}



===== entry @ 14002f010 =====

void entry(longlong param_1,ushort *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14002f044 =====

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



===== wil_InitializeFeatureStaging @ 14002f078 =====

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  longlong *plVar3;
  undefined **ppuVar4;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    ppuVar4 = &Feature_SPR_HardenInClient__private_descriptor;
    while (plVar3 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar4),
          plVar3 != (longlong *)0x0) {
      if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') &&
          (*(char *)((longlong)plVar3 + 0x1e) == '\0')) &&
         (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
        iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                          (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                           &g_wil_details_featureChangeNotification);
        if (iVar2 == 0) {
          bVar1 = true;
        }
        else {
          g_wil_details_featureChangeNotification = 0;
        }
        break;
      }
      ppuVar4 = (undefined **)(plVar3 + 7);
    }
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
}



===== DriverEntry @ 14002f168 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,ushort *param_2)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined1 auStackY_178 [32];
  undefined8 local_148;
  undefined8 uStack_140;
  undefined4 local_138;
  uint local_134;
  uint local_130;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_178;
  local_148 = 0;
  uStack_140 = 0;
  memset(&local_134,0,0x110);
  local_138 = 0x114;
  iVar1 = RtlGetVersion(&local_138);
  if ((-1 < iVar1) && ((6 < local_134 || ((local_134 == 6 && (1 < local_130)))))) {
    ExDefaultNonPagedPoolType = 0x200;
  }
  *(code **)(param_1 + 0x120) = USBC_Dispatch;
  *(code **)(param_1 + 0x148) = USBC_Dispatch;
  *(code **)(param_1 + 0xe8) = USBC_Dispatch;
  *(code **)(param_1 + 0x128) = USBC_Dispatch;
  *(code **)(param_1 + 0xe0) = USBC_Dispatch;
  *(code **)(param_1 + 0x80) = USBC_Dispatch;
  *(code **)(param_1 + 0x70) = USBC_Dispatch;
  *(code **)(param_1 + 0x68) = USBC_DriverUnload;
  *(code **)(*(longlong *)(param_1 + 0x30) + 8) = USBC_AddDevice;
  RegQueryGenericCompositeUSBDeviceString();
  wil_InitializeFeatureStaging();
  _WPP_MAIN_CB = 0;
  DAT_14001c588 = &WPP_ThisDir_CTLGUID_USBCCGP;
  DAT_14001c590 = 0;
  _DAT_14001c5a0 = 0;
  _DAT_14001c5a8 = 1;
  _DAT_14001c5c0 = 0;
  _DAT_14001c5c8 = 0;
  WppLoadTracingSupport();
  _DAT_14001c5a0 = 0;
  lVar3 = param_1;
  WppInitKm(param_1,param_2);
  AllocateDriverGlobalIFRLog();
  USBC_WmiDriverEntry(lVar3,param_2);
  RtlInitUnicodeString(&local_148,L"KseQueryDeviceFlags");
  g_KseQueryDeviceFlags = MmGetSystemRoutineAddress(&local_148);
  g_DriverObject = param_1;
  iVar1 = SleepstudyHelper_Initialize();
  if (iVar1 < 0) {
    uVar2 = Feature_SPR_HardenInClient__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar2 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(g_RecorderLog,2,8,0xf,&WPP_c8c0b630977f39a4a91a92e2db87f7d2_Traceguids,
                          (char)iVar1);
      }
      USBC_WmiUnload();
      if (g_RecorderLog != 0) {
        imp_WppRecorderLogDelete(WPP_GLOBAL_Control);
        g_RecorderLog = 0;
      }
      WppCleanupKm(g_DriverObject);
      if (GenericCompositeUSBDeviceString != 0) {
        ExFreePoolWithTag(GenericCompositeUSBDeviceString,0);
        GenericCompositeUSBDeviceString = 0;
      }
      wil_UninitializeFeatureStaging();
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(g_RecorderLog,3,8,0xe,&WPP_c8c0b630977f39a4a91a92e2db87f7d2_Traceguids,
                          (char)iVar1);
      }
      iVar1 = 0;
    }
  }
  return iVar1;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14002f3f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  int iVar1;
  longlong *plVar2;
  undefined **ppuVar3;
  undefined8 uVar4;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  ppuVar3 = &Feature_SPR_HardenInClient__private_descriptor;
  do {
    plVar2 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar3);
    if (plVar2 == (longlong *)0x0) {
      return;
    }
    local_30 = 0;
    local_38 = 0;
    local_28 = 0;
    local_20 = 0;
    if ((*(char *)((longlong)plVar2 + 0x1d) == '\0') && (*(char *)((longlong)plVar2 + 0x1e) == '\0')
       ) {
      iVar1 = RtlQueryFeatureConfiguration
                        ((int)plVar2[3],1 < (byte)(*(char *)((longlong)plVar2 + 0x1c) - 2U),
                         &local_30,&local_28);
      if (iVar1 == -0x7fffffde) {
        local_38 = 0x206;
        uVar4 = 0x206;
        do {
          *(undefined8 *)*plVar2 = uVar4;
          plVar2 = wil_details_FeatureDescriptors_SkipPadding(plVar2 + 7);
        } while (plVar2 != (longlong *)0x0);
        return;
      }
    }
    else {
      iVar1 = -0x3ffffddb;
    }
    wil_details_BuildFeatureStateCacheFromQueryResults(iVar1,(longlong)&local_28,(uint *)&local_38);
    ppuVar3 = (undefined **)(plVar2 + 7);
    *(undefined8 *)*plVar2 = local_38;
  } while( true );
}


