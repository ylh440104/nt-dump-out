
===== _tlgKeywordOn @ 1c0001008 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong _tlgKeywordOn(void)

{
  ulonglong in_RAX;
  
  if (((_DAT_1c000b010 & 0x400000000000) == 0) ||
     (in_RAX = DAT_1c000b018 & 0x400000000000, in_RAX != DAT_1c000b018)) {
    return in_RAX & 0xffffffffffffff00;
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 1c000103c =====

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
  *param_6 = PTR_DAT_1c000b008;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_1c000b008;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_1c000b020,&local_18,0,0,param_5,param_6);
  return;
}



===== KeyboardClassSetLedsComplete @ 1c00010f0 =====

undefined8 KeyboardClassSetLedsComplete(undefined8 param_1,longlong param_2,undefined8 *param_3)

{
  int iVar1;
  longlong lVar2;
  undefined8 in_stack_ffffffffffffffd8;
  
  IoReleaseRemoveLockEx(param_3 + 4,param_2,0x20);
  LOCK();
  lVar2 = param_3[0x2e];
  if (param_2 == lVar2) {
    param_3[0x2e] = 0;
    lVar2 = param_2;
  }
  else {
  }
  UNLOCK();
  if ((lVar2 == 0) || (lVar2 == param_2)) {
    LOCK();
    iVar1 = *(int *)(param_3 + 0x2f);
    *(int *)(param_3 + 0x2f) = 3;
    UNLOCK();
    if (lVar2 != param_2) {
      if (lVar2 != 0) {
        return 0xc0000016;
      }
      if (iVar1 != 2) {
        return 0xc0000016;
      }
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,99,in_stack_ffffffffffffffd8,
                       (char)*param_3,(char)param_2);
  }
  IoFreeIrp(param_2);
  return 0xc0000016;
}



===== KeyboardStartWorker @ 1c00011b0 =====

void KeyboardStartWorker(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  
  lVar1 = param_2[1];
  lVar2 = *(longlong *)(param_1 + 0x40);
  iVar3 = KeyboardStart(param_1,(longlong)param_2);
  *(int *)(lVar1 + 0x30) = iVar3;
  *(undefined8 *)(lVar1 + 0x38) = 0;
  IofCompleteRequest(lVar1,0);
  IoFreeWorkItem(*param_2);
  ExFreePoolWithTag(param_2,0);
  IoReleaseRemoveLockEx(lVar2 + 0x20,KeyboardStartWorker,0x20);
  return;
}



===== KeyboardPnP @ 1c0001240 =====

int KeyboardPnP(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  char cVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  int iVar5;
  longlong *plVar6;
  longlong lVar7;
  undefined8 local_28;
  longlong local_20;
  
  plVar3 = *(longlong **)(param_1 + 0x40);
  lVar7 = *(longlong *)(param_2 + 0xb8);
  if ((char)plVar3[8] == '\0') {
    *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    return -0x3fffff45;
  }
  iVar5 = IoAcquireRemoveLockEx(plVar3 + 4,param_2,"",1,0x20);
  if (iVar5 < 0) {
    *(int *)(param_2 + 0x30) = iVar5;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    return iVar5;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqc(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  cVar2 = *(char *)(lVar7 + 1);
  if (cVar2 == '\x02') {
    KeyboardClassCancelPendingIrpLeds(plVar3);
    KeyboardClassRemoveDevice(plVar3);
    IoReleaseRemoveLockAndWaitEx(plVar3 + 4,param_2,0x20);
    puVar4 = *(undefined8 **)(param_2 + 0xb8);
    puVar4[-9] = *puVar4;
    puVar4[-8] = puVar4[1];
    puVar4[-7] = puVar4[2];
    puVar4[-6] = puVar4[3];
    *(undefined4 *)(puVar4 + -5) = *(undefined4 *)(puVar4 + 4);
    *(undefined4 *)((longlong)puVar4 + -0x24) = *(undefined4 *)((longlong)puVar4 + 0x24);
    *(undefined4 *)(puVar4 + -4) = *(undefined4 *)(puVar4 + 5);
    *(undefined4 *)((longlong)puVar4 + -0x1c) = *(undefined4 *)((longlong)puVar4 + 0x2c);
    puVar4[-3] = puVar4[6];
    *(undefined1 *)((longlong)puVar4 + -0x45) = 0;
    iVar5 = IofCallDriver(plVar3[2],param_2);
    ExAcquireFastMutex(&DAT_1c000b1c0);
    if (Globals != 0) {
      if (DAT_1c000b1b0 < 2) {
        DAT_1c000b1b0 = 0;
        if (DAT_1c000b1a8 != 0) {
          ExFreePoolWithTag(DAT_1c000b1a8,0);
          DAT_1c000b1a8 = 0;
        }
      }
      else {
        *(undefined1 *)(DAT_1c000b1a8 + 0x13 + (ulonglong)*(uint *)((longlong)plVar3 + 0xc4) * 0x18)
             = 1;
        *(undefined8 *)(DAT_1c000b1a8 + (ulonglong)*(uint *)((longlong)plVar3 + 0xc4) * 0x18) = 0;
        *(undefined8 *)(DAT_1c000b1a8 + 8 + (ulonglong)*(uint *)((longlong)plVar3 + 0xc4) * 0x18) =
             0;
      }
    }
    ExReleaseFastMutex(&DAT_1c000b1c0);
    IoDetachDevice(plVar3[2]);
    RtlFreeUnicodeString(plVar3 + 0xb);
    ExFreePoolWithTag(plVar3[0xd],0);
    IoDeleteDevice(param_1);
    return iVar5;
  }
  switch(cVar2) {
  case '\0':
    plVar6 = (longlong *)ExAllocatePool2(0x40,0x10,0x4364624b);
    if (plVar6 != (longlong *)0x0) {
      lVar7 = IoAllocateWorkItem(param_1);
      *plVar6 = lVar7;
      if (lVar7 != 0) {
        plVar6[1] = param_2;
        IoAcquireRemoveLockEx(plVar3 + 4,KeyboardStartWorker,"",1,0x20);
        puVar4 = *(undefined8 **)(param_2 + 0xb8);
        iVar5 = 0x103;
        puVar4[-9] = *puVar4;
        puVar4[-8] = puVar4[1];
        puVar4[-7] = puVar4[2];
        puVar4[-6] = puVar4[3];
        *(undefined4 *)(puVar4 + -5) = *(undefined4 *)(puVar4 + 4);
        *(undefined4 *)((longlong)puVar4 + -0x24) = *(undefined4 *)((longlong)puVar4 + 0x24);
        *(undefined4 *)(puVar4 + -4) = *(undefined4 *)(puVar4 + 5);
        *(undefined4 *)((longlong)puVar4 + -0x1c) = *(undefined4 *)((longlong)puVar4 + 0x2c);
        puVar4[-3] = puVar4[6];
        *(undefined1 *)((longlong)puVar4 + -0x45) = 0;
        lVar7 = *(longlong *)(param_2 + 0xb8);
        *(code **)(lVar7 + -0x10) = KeyboardPnpStartCompletion;
        *(longlong **)(lVar7 + -8) = plVar6;
        *(undefined1 *)(lVar7 + -0x45) = 0xe0;
        pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
        *pbVar1 = *pbVar1 | 1;
        IofCallDriver(plVar3[2],param_2);
        goto LAB_1c000130c;
      }
      ExFreePoolWithTag(plVar6,0);
    }
    KeyboardSendIrpSynchronously(plVar3[2],param_2,'\x01');
    local_28 = 0;
    local_20 = param_2;
    iVar5 = KeyboardStart(param_1,(longlong)&local_28);
    *(int *)(param_2 + 0x30) = iVar5;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    goto LAB_1c000130c;
  case '\x04':
    if (*(char *)((longlong)plVar3 + 0x41) != '\0') {
      ExAcquireFastMutex(&DAT_1c000b1c0);
      if ((Globals == 0) || (DAT_1c000b1b4 < 1)) {
        ExReleaseFastMutex();
      }
      else {
        cVar2 = *(char *)(DAT_1c000b1a8 + 0x10 +
                         (ulonglong)*(uint *)((longlong)plVar3 + 0xc4) * 0x18);
        puVar4 = (undefined8 *)
                 (DAT_1c000b1a8 + (ulonglong)*(uint *)((longlong)plVar3 + 0xc4) * 0x18);
        *(undefined1 *)(puVar4 + 2) = 0;
        ExReleaseFastMutex();
        if (cVar2 != '\0') {
          LOCK();
          lVar7 = plVar3[0x29];
          plVar3[0x29] = 0;
          UNLOCK();
          if (lVar7 != 0) {
            IoUnregisterPlugPlayNotification();
          }
          KbdEnableDisablePort('\0',param_2,plVar3,puVar4);
        }
      }
    }
    *(undefined1 *)((longlong)plVar3 + 0x41) = 0;
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    break;
  case '\x14':
    if (*(char *)((longlong)plVar3 + 0x42) == '\0') {
      *(uint *)(param_2 + 0x38) = *(uint *)(param_2 + 0x38) | 0x20;
      *(undefined4 *)(param_2 + 0x30) = 0;
    }
  default:
    puVar4 = *(undefined8 **)(param_2 + 0xb8);
    puVar4[-9] = *puVar4;
    puVar4[-8] = puVar4[1];
    puVar4[-7] = puVar4[2];
    puVar4[-6] = puVar4[3];
    puVar4[-5] = puVar4[4];
    puVar4[-4] = puVar4[5];
    puVar4[-3] = puVar4[6];
    *(undefined1 *)((longlong)puVar4 + -0x45) = 0;
    break;
  case '\x17':
    KeyboardClassCancelPendingIrpLeds(plVar3);
    *(undefined1 *)((longlong)plVar3 + 0x16b) = 1;
    if (plVar3[0xc] != 0) {
      IoSetDeviceInterfaceState(plVar3 + 0xb,0);
    }
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  }
  iVar5 = IofCallDriver(plVar3[2],param_2);
LAB_1c000130c:
  IoReleaseRemoveLockEx(plVar3 + 4,param_2,0x20);
  return iVar5;
}



===== WPP_RECORDER_SF_qqc @ 1c0001790 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqc(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x57,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,1,0);
  }
  WppAutoLogTrace(param_1,4,6,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x57,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,1,0);
  return;
}



===== KeyboardClassPowerComplete @ 1c00018b0 =====

undefined8 KeyboardClassPowerComplete(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  bool bVar4;
  undefined8 *puVar5;
  int iVar6;
  longlong lVar7;
  undefined8 uVar8;
  undefined8 in_stack_ffffffffffffffc8;
  undefined4 uVar9;
  
  uVar9 = (undefined4)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  puVar3 = *(undefined8 **)(param_1 + 0x40);
  bVar4 = true;
  uVar1 = *(undefined4 *)(lVar2 + 0x18);
  if (*(char *)(lVar2 + 1) == '\0') {
    bVar4 = false;
    if (param_2 == puVar3[0x25]) {
      LOCK();
      iVar6 = *(int *)(puVar3 + 0x28);
      *(int *)(puVar3 + 0x28) = 3;
      UNLOCK();
      if (iVar6 == 1) {
        PoStartNextPowerIrp(param_2);
        return 0xc0000016;
      }
    }
  }
  else if (*(char *)(lVar2 + 1) == '\x02') {
    if (*(int *)(lVar2 + 0x10) == 0) {
      PoSetPowerState(*puVar3,0,uVar1);
      *(undefined4 *)(puVar3 + 0x18) = uVar1;
      iVar6 = PoRequestPowerIrp(*puVar3,2,1,KeyboardClassPoRequestComplete,0,0);
      if (iVar6 < 0) {
        *(int *)(param_2 + 0x30) = iVar6;
      }
    }
    else if (*(int *)(lVar2 + 0x10) == 1) {
      PoSetPowerState(*puVar3,1,uVar1);
      *(undefined4 *)((longlong)puVar3 + 0xbc) = uVar1;
      lVar7 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c),0);
      if (lVar7 != 0) {
        uVar8 = CONCAT44(uVar9,0x20);
        iVar6 = IoAcquireRemoveLockEx(puVar3 + 4,lVar7,"",1);
        if (iVar6 < 0) {
          IoFreeIrp(lVar7);
        }
        else {
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,100,uVar8,
                               (char)param_1,(char)lVar7);
          }
          if (Globals == (undefined8 *)0x0) {
            uVar8 = *(undefined8 *)(lVar2 + 0x30);
            puVar5 = puVar3;
          }
          else {
            uVar8 = *(undefined8 *)
                     (DAT_1c000b1a8 + (ulonglong)*(uint *)((longlong)puVar3 + 0xc4) * 0x18);
            puVar5 = Globals;
          }
          lVar2 = *(longlong *)(lVar7 + 0xb8);
          *(undefined1 *)(lVar2 + -0x48) = 0xf;
          *(undefined4 *)(lVar2 + -0x30) = 0xb0008;
          *(undefined4 *)(lVar2 + -0x38) = 4;
          *(undefined4 *)(lVar2 + -0x40) = 0;
          *(undefined8 *)(lVar2 + -0x18) = uVar8;
          lVar2 = *(longlong *)(lVar7 + 0xb8);
          *(code **)(lVar2 + -0x10) = KeyboardClassSetLedsComplete;
          *(undefined8 **)(lVar2 + -8) = puVar3;
          *(undefined1 *)(lVar2 + -0x45) = 0xe0;
          *(longlong *)(lVar7 + 0x18) = (longlong)puVar5 + 0x9c;
          KeyboardClassCancelPendingIrpLeds(puVar3);
          LOCK();
          puVar3[0x2e] = lVar7;
          UNLOCK();
          LOCK();
          *(undefined4 *)(puVar3 + 0x2f) = 1;
          UNLOCK();
          IofCallDriver(puVar3[2],lVar7);
        }
      }
    }
    PoStartNextPowerIrp(param_2);
    goto LAB_1c0001a54;
  }
  PoStartNextPowerIrp(param_2);
  if (!bVar4) {
    return 0;
  }
LAB_1c0001a54:
  IoReleaseRemoveLockEx(puVar3 + 4,param_2,0x20);
  return 0;
}



===== KeyboardClassCancelPendingIrpLeds @ 1c0001b70 =====

ulonglong KeyboardClassCancelPendingIrpLeds(undefined8 *param_1)

{
  uint uVar1;
  longlong lVar2;
  ulonglong in_RAX;
  ulonglong uVar3;
  undefined8 in_stack_ffffffffffffffd8;
  
  LOCK();
  lVar2 = param_1[0x2e];
  param_1[0x2e] = 0;
  UNLOCK();
  if (lVar2 == 0) {
    uVar3 = in_RAX & 0xffffffffffffff00;
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x59,
                         in_stack_ffffffffffffffd8,(char)*param_1,(char)lVar2);
    }
    IoCancelIrp(lVar2);
    LOCK();
    uVar1 = *(uint *)(param_1 + 0x2f);
    *(uint *)(param_1 + 0x2f) = 2;
    uVar3 = (ulonglong)uVar1;
    UNLOCK();
    if (uVar1 == 3) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x5a,
                           in_stack_ffffffffffffffd8,(char)*param_1,(char)lVar2);
      }
      uVar3 = IoFreeIrp(lVar2);
    }
    uVar3 = CONCAT71((int7)(uVar3 >> 8),1);
  }
  return uVar3;
}



===== KeyboardClassRemoveDevice @ 1c0001c50 =====

void KeyboardClassRemoveDevice(undefined8 *param_1)

{
  int iVar1;
  longlong lVar2;
  undefined1 uVar3;
  undefined8 *puVar4;
  
  LOCK();
  iVar1 = *(int *)(param_1 + 0x28);
  *(int *)(param_1 + 0x28) = 1;
  UNLOCK();
  if (iVar1 == 0) {
    uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 9);
    lVar2 = param_1[0x25];
    if ((lVar2 == 0) || (*(char *)(param_1 + 0x26) != '\0')) {
      KeReleaseSpinLock(param_1 + 9,uVar3);
      LOCK();
      *(undefined4 *)(param_1 + 0x28) = 2;
      UNLOCK();
    }
    else {
      *(undefined1 *)(param_1 + 0x26) = 1;
      KeReleaseSpinLock(param_1 + 9,uVar3);
      IoCancelIrp(lVar2);
      LOCK();
      iVar1 = *(int *)(param_1 + 0x28);
      *(int *)(param_1 + 0x28) = 2;
      UNLOCK();
      if (iVar1 == 3) {
        IofCompleteRequest(lVar2,0);
      }
    }
  }
  puVar4 = (undefined8 *)*param_1;
  IoWMIRegistrationControl(puVar4,2);
  if (*(char *)((longlong)param_1 + 0x41) != '\0') {
    ExAcquireFastMutex(&DAT_1c000b1c0);
    puVar4 = (undefined8 *)&DAT_1c000b1c0;
    if (Globals == 0) {
      ExReleaseFastMutex();
      if ((*(char *)((longlong)param_1 + 0x16b) == '\0') && (param_1[0xc] != 0)) {
        puVar4 = param_1 + 0xb;
        IoSetDeviceInterfaceState(puVar4,0);
      }
    }
    else if (DAT_1c000b1b4 < 1) {
      ExReleaseFastMutex();
    }
    else {
      *(undefined1 *)(DAT_1c000b1a8 + 0x10 + (ulonglong)*(uint *)((longlong)param_1 + 0xc4) * 0x18)
           = 0;
      ExReleaseFastMutex();
      LOCK();
      puVar4 = (undefined8 *)param_1[0x29];
      param_1[0x29] = 0;
      UNLOCK();
      if (puVar4 != (undefined8 *)0x0) {
        IoUnregisterPlugPlayNotification();
      }
    }
  }
  if (*(char *)(param_1 + 8) != '\0') {
    KeyboardClassCleanupQueue(puVar4,(longlong)param_1,(longlong *)0x0);
  }
  return;
}



===== KeyboardClassCleanupQueue @ 1c0001e00 =====

void KeyboardClassCleanupQueue(undefined8 param_1,longlong param_2,longlong *param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 *puVar5;
  byte bVar6;
  longlong *plVar7;
  longlong *plVar8;
  undefined1 *puVar9;
  longlong *plVar10;
  ulonglong uVar11;
  undefined8 uStack_40;
  undefined1 auStack_38 [32];
  undefined8 ***local_18 [2];
  
  local_18[1] = local_18;
  local_18[0] = local_18;
  bVar6 = KeAcquireSpinLockRaiseToDpc(param_2 + 0xa0);
  puVar9 = auStack_38;
  plVar10 = (longlong *)(param_2 + 0xa8);
  uVar11 = (ulonglong)bVar6;
  plVar7 = (longlong *)*plVar10;
  puVar5 = auStack_38;
  if (plVar7 == plVar10) goto LAB_1c0001e72;
  do {
    plVar8 = (longlong *)*plVar7;
    if (param_3 == (longlong *)0x0) goto LAB_1c0001f06;
    if (*(longlong **)(plVar7[2] + 0x30) == param_3) goto LAB_1c0001f06;
LAB_1c0001e6a:
    plVar7 = plVar8;
    puVar5 = puVar9;
  } while (plVar7 != plVar10);
LAB_1c0001e72:
  puVar9 = puVar5;
  plVar8 = (longlong *)(uVar11 & 0xff);
  *(undefined8 *)(puVar9 + -8) = 0x1c0001e84;
  KeReleaseSpinLock(param_2 + 0xa0);
  while( true ) {
    param_3 = *(longlong **)(puVar9 + 0x20);
    if (param_3 == (longlong *)(puVar9 + 0x20)) {
      return;
    }
    if (((undefined1 *)param_3[1] != puVar9 + 0x20) ||
       (lVar1 = *param_3, *(longlong **)(lVar1 + 8) != param_3)) break;
    *(longlong *)(puVar9 + 0x20) = lVar1;
    *(undefined1 **)(lVar1 + 8) = puVar9 + 0x20;
    *(undefined8 *)(puVar9 + -8) = 0x1c0001eca;
    IofCompleteRequest(param_3 + -0x15,0);
    plVar10 = (longlong *)0x20;
    plVar8 = param_3 + -0x15;
    *(undefined8 *)(puVar9 + -8) = 0x1c0001ee7;
    IoReleaseRemoveLockEx(param_2 + 0x20);
  }
  do {
    do {
      plVar7 = (longlong *)0x3;
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)();
      puVar9 = puVar9 + 8;
LAB_1c0001f06:
    } while (((longlong *)plVar8[1] != plVar7) ||
            (puVar2 = (undefined8 *)plVar7[1], (longlong *)*puVar2 != plVar7));
    *puVar2 = plVar8;
    plVar8[1] = (longlong)puVar2;
    LOCK();
    lVar1 = plVar7[-8];
    plVar7[-8] = 0;
    UNLOCK();
    if (lVar1 == 0) {
      plVar7[1] = (longlong)plVar7;
      *plVar7 = (longlong)plVar7;
      goto LAB_1c0001e6a;
    }
    *(undefined4 *)(plVar7 + -0xf) = 0xc0000120;
    plVar7[-0xe] = 0;
    plVar3 = *(longlong **)(puVar9 + 0x28);
  } while ((undefined1 *)*plVar3 != puVar9 + 0x20);
  plVar7[1] = (longlong)plVar3;
  *plVar7 = (longlong)(puVar9 + 0x20);
  *plVar3 = (longlong)plVar7;
  *(longlong **)(puVar9 + 0x28) = plVar7;
  goto LAB_1c0001e6a;
}



===== KeyboardStart @ 1c0001f70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int KeyboardStart(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined8 uVar7;
  undefined1 uVar8;
  char cVar9;
  int iVar10;
  int iVar11;
  undefined1 auStack_98 [32];
  undefined8 local_78;
  undefined8 local_70;
  longlong local_68;
  longlong lStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_98;
  lVar3 = *(longlong *)(param_2 + 8);
  plVar4 = *(longlong **)(param_1 + 0x40);
  iVar11 = *(int *)(lVar3 + 0x30);
  if (-1 < iVar11) {
    *(undefined4 *)(lVar3 + 0x30) = 0xc00000bb;
    uVar5 = *(undefined8 *)(lVar3 + 0x38);
    *(undefined8 *)(lVar3 + 0x38) = 0;
    local_78 = 0x10040;
    local_68 = 0;
    lStack_60 = 0;
    local_58 = 0;
    uStack_50 = 0;
    local_48 = 0;
    uStack_40 = 0;
    local_70 = 0xffffffffffffffff;
    lVar6 = *(longlong *)(lVar3 + 0xb8);
    *(undefined1 *)(lVar6 + -0x47) = 9;
    *(undefined8 **)(lVar6 + -0x40) = &local_78;
    iVar10 = KeyboardSendIrpSynchronously(plVar4[2],lVar3,'\0');
    if ((-1 < iVar10) && (-1 < *(int *)(lVar3 + 0x30))) {
      *(undefined4 *)((longlong)plVar4 + 0x11c) = (undefined4)local_48;
      *(undefined4 *)(plVar4 + 0x24) = uStack_50._4_4_;
      plVar4[0x21] = local_68;
      plVar4[0x22] = lStack_60;
      *(undefined4 *)(plVar4 + 0x23) = (undefined4)local_58;
    }
    *(int *)(lVar3 + 0x30) = iVar11;
    iVar11 = 0;
    *(undefined8 *)(lVar3 + 0x38) = uVar5;
    *(undefined1 *)((longlong)plVar4 + 0x41) = 1;
    if ((*(int *)((longlong)plVar4 + 0x11c) < 2) || ((int)plVar4[0x24] < 2)) {
      *(undefined4 *)(plVar4 + 0x19) = 1;
    }
    else {
      *(undefined4 *)(plVar4 + 0x19) = 2;
      KeyboardClassGetWaitWakeEnableState((longlong)plVar4);
    }
    plVar4[0x1a] = (longlong)&KeyboardClassWmiGuidList;
    plVar4[0x1f] = 0;
    plVar4[0x1b] = (longlong)KeyboardClassQueryWmiRegInfo;
    plVar4[0x1c] = (longlong)KeyboardClassQueryWmiDataBlock;
    plVar4[0x1d] = (longlong)KeyboardClassSetWmiDataBlock;
    plVar4[0x1e] = (longlong)KeyboardClassSetWmiDataItem;
    plVar4[0x20] = 0;
    IoWMIRegistrationControl(*plVar4,1);
    ExAcquireFastMutex(&DAT_1c000b1c0);
    if (Globals == 0) {
      ExReleaseFastMutex();
      iVar11 = IoSetDeviceInterfaceState(plVar4 + 0xb,1);
    }
    else if (DAT_1c000b1b4 < 1) {
      ExReleaseFastMutex();
    }
    else {
      cVar9 = *(char *)(DAT_1c000b1a8 + 0x10 + (ulonglong)*(uint *)((longlong)plVar4 + 0xc4) * 0x18)
      ;
      puVar1 = (undefined8 *)(DAT_1c000b1a8 + (ulonglong)*(uint *)((longlong)plVar4 + 0xc4) * 0x18);
      *(undefined1 *)(puVar1 + 2) = 1;
      ExReleaseFastMutex(&DAT_1c000b1c0);
      if (cVar9 == '\0') {
        iVar11 = KbdEnableDisablePort('\x01',lVar3,plVar4,puVar1);
        if (iVar11 < 0) {
          *(undefined1 *)(puVar1 + 2) = 0;
        }
        else {
          lVar6 = *(longlong *)(lVar3 + 0xb8);
          *(undefined1 *)(lVar6 + -0x48) = 0xf;
          *(undefined4 *)(lVar6 + -0x30) = 0xb0008;
          *(undefined8 *)(lVar6 + -0x18) = *puVar1;
          *(undefined4 *)(lVar6 + -0x40) = 0;
          *(undefined4 *)(lVar6 + -0x38) = 4;
          uVar5 = *(undefined8 *)(lVar3 + 0x38);
          uVar7 = *(undefined8 *)(lVar3 + 0x18);
          uVar2 = *(undefined4 *)(lVar3 + 0x30);
          *(undefined8 *)(lVar3 + 0x38) = 0;
          *(longlong *)(lVar3 + 0x18) = Globals + 0x9c;
          KeyboardSendIrpSynchronously(plVar4[2],lVar3,'\0');
          iVar11 = 0;
          *(undefined4 *)(lVar3 + 0x30) = uVar2;
          *(undefined8 *)(lVar3 + 0x38) = uVar5;
          *(undefined8 *)(lVar3 + 0x18) = uVar7;
        }
      }
    }
    if ((1 < *(int *)((longlong)plVar4 + 0x11c)) && (1 < (int)plVar4[0x24])) {
      uVar8 = KeAcquireSpinLockRaiseToDpc(plVar4 + 9);
      if ((plVar4[0x25] == 0) || ((char)plVar4[0x26] != '\0')) {
        KeReleaseSpinLock(plVar4 + 9,uVar8);
        cVar9 = KeyboardClassCheckWaitWakeEnabled((longlong)plVar4);
        if (cVar9 != '\0') {
          KeyboardClassCreateWaitWakeIrp((longlong)plVar4);
        }
      }
      else {
        KeReleaseSpinLock(plVar4 + 9,uVar8);
      }
    }
  }
  return iVar11;
}



===== KeyboardClassServiceCallback @ 1c00022e0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void KeyboardClassServiceCallback
               (longlong param_1,longlong *param_2,undefined **param_3,int *param_4)

{
  undefined8 *puVar1;
  longlong lVar2;
  void *pvVar3;
  ulonglong uVar4;
  code *pcVar5;
  undefined8 uVar6;
  longlong *plVar7;
  int iVar8;
  ulonglong uVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined1 *puVar13;
  uint uVar14;
  undefined **ppuVar15;
  uint uVar16;
  longlong *plVar17;
  undefined **_Size;
  uint uVar18;
  longlong local_res8;
  undefined8 uStack_a0;
  undefined1 auStack_98 [32];
  undefined8 uStack_78;
  longlong lStack_70;
  uint local_68 [2];
  uint local_60 [2];
  ulonglong local_58;
  int local_50 [2];
  longlong local_48 [2];
  undefined8 ****local_38 [2];
  
  ppuVar15 = &WPP_RECORDER_INITIALIZED;
  _Size = param_3;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    _Size = (undefined **)0x3;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x33);
  }
  puVar13 = auStack_98;
  puVar1 = *(undefined8 **)(param_1 + 0x40);
  uVar18 = 0;
  plVar17 = (longlong *)(ulonglong)(uint)((int)param_3 - (int)param_2);
  *param_4 = 0;
  KeAcquireSpinLockAtDpcLevel(puVar1 + 0x14);
  local_38[1] = local_38;
  plVar10 = puVar1 + 0x15;
  local_38[0] = local_38;
  do {
    plVar11 = (longlong *)0x0;
    do {
      plVar7 = (longlong *)*plVar10;
      if (plVar7 == plVar10) break;
      if (((longlong *)plVar7[1] != plVar10) ||
         (lVar2 = *plVar7, *(longlong **)(lVar2 + 8) != plVar7)) goto LAB_1c0002888;
      *plVar10 = lVar2;
      plVar11 = plVar7 + -0x15;
      *(longlong **)(lVar2 + 8) = plVar10;
      LOCK();
      lVar2 = plVar7[-8];
      plVar7[-8] = 0;
      UNLOCK();
      if (lVar2 == 0) goto LAB_1c000288f;
    } while (plVar11 == (longlong *)0x0);
    uVar16 = (uint)plVar17;
    if (plVar11 == (longlong *)0x0) {
LAB_1c0002467:
      param_2 = (longlong *)((longlong)param_2 + (ulonglong)uVar18);
      uVar16 = uVar16 - uVar18;
      plVar17 = (longlong *)(ulonglong)uVar16;
      if (((undefined **)WPP_RECORDER_INITIALIZED != ppuVar15) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
        *(uint *)(puVar13 + 0x30) = uVar16;
        *(longlong *)(puVar13 + 0x28) = param_1;
        *(undefined8 *)(puVar13 + -8) = 0x1c00025ba;
        WPP_RECORDER_SF_qL(uVar6);
      }
      if (uVar16 != 0) {
        if (((undefined **)WPP_RECORDER_INITIALIZED != ppuVar15) &&
           (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
          iVar8 = *(int *)((longlong)puVar1 + 0x54);
          uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
          *(uint *)(puVar13 + 0x38) = uVar16;
          plVar10 = (longlong *)(ulonglong)(uint)(iVar8 * 0xc);
          *(int *)(puVar13 + 0x30) = *(int *)((longlong)puVar1 + 0x8c) + iVar8 * -0xc;
          *(longlong *)(puVar13 + 0x28) = param_1;
          *(undefined8 *)(puVar13 + -8) = 0x1c0002883;
          WPP_RECORDER_SF_qLL(uVar6,plVar10,_Size,0x37,*(undefined8 *)(puVar13 + 0x20),puVar13[0x28]
                              ,puVar13[0x30],puVar13[0x38]);
        }
        uVar14 = *(uint *)((longlong)puVar1 + 0x8c);
        if (uVar14 < uVar16) {
          uVar16 = uVar14;
        }
        plVar17 = (longlong *)(ulonglong)uVar16;
        uVar14 = (*(int *)(puVar1 + 0xd) - *(int *)(puVar1 + 0xe)) + uVar14;
        if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
           (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
          uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
          *(uint *)(puVar13 + 0x38) = uVar14;
          *(uint *)(puVar13 + 0x30) = uVar16;
          *(longlong *)(puVar13 + 0x28) = param_1;
          *(undefined8 *)(puVar13 + -8) = 0x1c0002802;
          WPP_RECORDER_SF_qLL(uVar6,plVar10,_Size,0x39,*(undefined8 *)(puVar13 + 0x20),puVar13[0x28]
                              ,puVar13[0x30],puVar13[0x38]);
        }
        if (uVar16 < uVar14) {
          uVar14 = uVar16;
        }
        if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
           (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
          uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
          *(undefined8 *)(puVar13 + 0x40) = puVar1[0xe];
          *(longlong **)(puVar13 + 0x38) = param_2;
          *(uint *)(puVar13 + 0x30) = uVar14;
          *(longlong *)(puVar13 + 0x28) = param_1;
          *(undefined8 *)(puVar13 + -8) = 0x1c000283f;
          WPP_RECORDER_SF_qLqq
                    (uVar6,plVar10,_Size,0x3a,*(undefined8 *)(puVar13 + 0x20),puVar13[0x28],
                     puVar13[0x30],puVar13[0x38],puVar13[0x40]);
        }
        pvVar3 = (void *)puVar1[0xe];
        _Size = (undefined **)(ulonglong)uVar14;
        *(undefined8 *)(puVar13 + -8) = 0x1c000272e;
        memcpy(pvVar3,param_2,(size_t)_Size);
        param_2 = (longlong *)((longlong)param_2 + (ulonglong)uVar14);
        uVar4 = puVar1[0xd];
        uVar9 = puVar1[0xe] + (ulonglong)uVar14;
        puVar1[0xe] = uVar9;
        if (*(uint *)((longlong)puVar1 + 0x8c) + uVar4 <= uVar9) {
          puVar1[0xe] = uVar4;
          uVar9 = uVar4;
        }
        uVar14 = uVar16 - uVar14;
        ppuVar15 = (undefined **)(ulonglong)uVar14;
        if (uVar14 != 0) {
          if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
             (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
            *(ulonglong *)(puVar13 + 0x40) = uVar9;
            uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
            *(longlong **)(puVar13 + 0x38) = param_2;
            *(uint *)(puVar13 + 0x30) = uVar14;
            *(longlong *)(puVar13 + 0x28) = param_1;
            *(undefined8 *)(puVar13 + -8) = 0x1c00028e7;
            WPP_RECORDER_SF_qLqq
                      (uVar6,uVar4,_Size,0x3b,*(undefined8 *)(puVar13 + 0x20),puVar13[0x28],
                       puVar13[0x30],puVar13[0x38],puVar13[0x40]);
          }
          pvVar3 = (void *)puVar1[0xe];
          *(undefined8 *)(puVar13 + -8) = 0x1c00028f6;
          _Size = ppuVar15;
          memcpy(pvVar3,param_2,(size_t)ppuVar15);
          puVar1[0xe] = (undefined *)(puVar1[0xe] + (longlong)ppuVar15);
        }
        ppuVar15 = &WPP_RECORDER_INITIALIZED;
        plVar10 = (longlong *)((ulonglong)uVar16 / 0xc);
        *(int *)((longlong)puVar1 + 0x54) = *(int *)((longlong)puVar1 + 0x54) + (int)plVar10;
        iVar8 = *param_4 + (int)plVar10;
        *param_4 = iVar8;
        if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
           (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
          uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
          *(int *)(puVar13 + 0x48) = iVar8;
          *(undefined8 *)(puVar13 + 0x40) = puVar1[0xf];
          *(undefined8 *)(puVar13 + 0x38) = puVar1[0xe];
          *(undefined4 *)(puVar13 + 0x30) = *(undefined4 *)((longlong)puVar1 + 0x54);
          *(longlong *)(puVar13 + 0x28) = param_1;
          *(undefined8 *)(puVar13 + -8) = 0x1c00027cf;
          WPP_RECORDER_SF_qlqqd(uVar6);
        }
      }
      if (*(int *)((longlong)puVar1 + 0x54) != 0) {
        plVar11 = puVar1 + 0x15;
LAB_1c000260f:
        do {
          plVar7 = (longlong *)0x0;
          do {
            plVar12 = (longlong *)*plVar11;
            if (plVar12 == plVar11) break;
            plVar17 = plVar7;
            if (((longlong *)plVar12[1] != plVar11) ||
               (lVar2 = *plVar12, *(longlong **)(lVar2 + 8) != plVar12)) goto LAB_1c0002888;
            *plVar11 = lVar2;
            plVar7 = plVar12 + -0x15;
            *(longlong **)(lVar2 + 8) = plVar11;
            LOCK();
            lVar2 = plVar12[-8];
            plVar12[-8] = 0;
            UNLOCK();
            if (lVar2 == 0) {
              plVar12[1] = (longlong)plVar12;
              *plVar12 = (longlong)plVar12;
              goto LAB_1c000260f;
            }
          } while (plVar7 == (longlong *)0x0);
          plVar17 = plVar7;
          if (plVar7 == (longlong *)0x0) break;
          *(undefined8 *)(puVar13 + -8) = 0x1c0002666;
          plVar10 = plVar7;
          uVar6 = KeyboardClassReadCopyData(puVar1,(longlong)plVar7,_Size);
          *(int *)(plVar7 + 6) = (int)uVar6;
          plVar12 = *(longlong **)(puVar13 + 0x68);
          plVar17 = plVar7 + 0x15;
          if ((undefined1 *)*plVar12 != puVar13 + 0x60) goto LAB_1c0002888;
          plVar7[0x16] = (longlong)plVar12;
          *plVar17 = (longlong)(puVar13 + 0x60);
          *plVar12 = (longlong)plVar17;
          *(longlong **)(puVar13 + 0x68) = plVar17;
        } while (*(int *)((longlong)puVar1 + 0x54) != 0);
      }
      *(undefined8 *)(puVar13 + -8) = 0x1c000249d;
      KeReleaseSpinLockFromDpcLevel(puVar1 + 0x14);
      while( true ) {
        plVar11 = *(longlong **)(puVar13 + 0x60);
        if (plVar11 == (longlong *)(puVar13 + 0x60)) {
          if (((undefined **)WPP_RECORDER_INITIALIZED != ppuVar15) &&
             (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
            uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
            *(undefined8 *)(puVar13 + -8) = 0x1c0002591;
            WPP_RECORDER_SF_(uVar6,5,3,0x3d);
          }
          return;
        }
        if (((undefined1 *)plVar11[1] != puVar13 + 0x60) ||
           (lVar2 = *plVar11, *(longlong **)(lVar2 + 8) != plVar11)) break;
        *(longlong *)(puVar13 + 0x60) = lVar2;
        *(undefined1 **)(lVar2 + 8) = puVar13 + 0x60;
        *(undefined8 *)(puVar13 + -8) = 0x1c0002517;
        IofCompleteRequest(plVar11 + -0x15,6);
        _Size = (undefined **)0x20;
        plVar10 = plVar11 + -0x15;
        *(undefined8 *)(puVar13 + -8) = 0x1c0002534;
        IoReleaseRemoveLockEx(puVar1 + 4);
      }
    }
    else {
      param_1 = plVar11[0x17];
      uVar14 = *(uint *)(param_1 + 8);
      uVar18 = uVar14;
      if (uVar16 < uVar14) {
        uVar18 = uVar16;
      }
      ppuVar15 = (undefined **)(ulonglong)uVar18;
      *param_4 = *param_4 + uVar18 / 0xc;
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
        *(longlong *)(puVar13 + 0x50) = plVar11[3];
        *(longlong **)(puVar13 + 0x48) = param_2;
        *(uint *)(puVar13 + 0x40) = uVar14;
        *(uint *)(puVar13 + 0x38) = uVar16;
        *(longlong **)(puVar13 + 0x30) = plVar11;
        *(undefined8 *)(puVar13 + 0x28) = *(undefined8 *)(puVar13 + 0xa0);
        *(undefined8 *)(puVar13 + -8) = 0x1c0002603;
        WPP_RECORDER_SF_qqLLqq(uVar6);
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        *(uint *)(puVar13 + 0x40) = uVar18;
        *(undefined8 *)(puVar13 + 0x38) = _DAT_fffff78000000014;
        uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
        *(longlong **)(puVar13 + 0x30) = plVar11;
        *(undefined8 *)(puVar13 + 0x28) = *(undefined8 *)(puVar13 + 0xa0);
        *(undefined8 *)(puVar13 + -8) = 0x1c00026d2;
        WPP_RECORDER_SF_qqiL(uVar6);
      }
      pvVar3 = (void *)plVar11[3];
      *(undefined8 *)(puVar13 + -8) = 0x1c000241b;
      plVar10 = param_2;
      _Size = ppuVar15;
      memcpy(pvVar3,param_2,(size_t)ppuVar15);
      *(undefined4 *)(plVar11 + 6) = 0;
      plVar11[7] = (longlong)ppuVar15;
      plVar12 = plVar11 + 0x15;
      *(uint *)(param_1 + 8) = uVar18;
      plVar7 = *(longlong **)(puVar13 + 0x68);
      if ((undefined1 *)*plVar7 == puVar13 + 0x60) {
        param_1 = *(longlong *)(puVar13 + 0xa0);
        *plVar12 = (longlong)(puVar13 + 0x60);
        ppuVar15 = &WPP_RECORDER_INITIALIZED;
        plVar11[0x16] = (longlong)plVar7;
        *plVar7 = (longlong)plVar12;
        *(longlong **)(puVar13 + 0x68) = plVar12;
        goto LAB_1c0002467;
      }
    }
LAB_1c0002888:
    pcVar5 = (code *)swi(0x29);
    plVar7 = (longlong *)(*pcVar5)(3);
    puVar13 = puVar13 + 8;
LAB_1c000288f:
    plVar7[1] = (longlong)plVar7;
    *plVar7 = (longlong)plVar7;
  } while( true );
}



===== KeyboardClassRead @ 1c0002920 =====

ulonglong KeyboardClassRead(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  undefined8 uVar7;
  code *pcVar8;
  bool bVar9;
  undefined1 uVar10;
  uint uVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  char *pcVar17;
  undefined1 auStackY_68 [8];
  undefined1 auStackY_60 [24];
  undefined4 uVar18;
  undefined4 in_stack_ffffffffffffffbc;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x31);
  }
  puVar13 = auStackY_68;
  puVar14 = auStackY_68;
  puVar12 = auStackY_68;
  puVar4 = *(undefined8 **)(param_1 + 0x40);
  uVar11 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (uVar11 == 0) {
    uVar16 = 0;
    *(undefined4 *)(param_2 + 0x30) = 0;
    puVar12 = auStackY_68;
  }
  else {
    if ((ulonglong)uVar11 == ((ulonglong)uVar11 / 0xc) * 0xc) {
      if (*(char *)((longlong)puVar4 + 0x16b) == '\0') {
        if (*(code **)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x20) == DriverEntry) {
          uVar18 = 0x20;
          pcVar17 = "";
          uVar11 = IoAcquireRemoveLockEx(puVar4 + 4,param_2,"",1);
          uVar16 = (ulonglong)uVar11;
          uVar15 = 0x103;
          if (-1 < (int)uVar11) {
            uVar16 = 0x103;
          }
          *(int *)(param_2 + 0x30) = (int)uVar16;
          *(undefined8 *)(param_2 + 0x38) = 0;
          if ((int)uVar16 != 0x103) goto LAB_1c0002ac1;
          bVar9 = false;
          uVar10 = KeAcquireSpinLockRaiseToDpc(puVar4 + 0x14);
          if (*(int *)((longlong)puVar4 + 0x54) != 0) {
            uVar15 = KeyboardClassReadCopyData(puVar4,param_2,pcVar17);
            *(int *)(param_2 + 0x30) = (int)uVar15;
            uVar15 = uVar15 & 0xffffffff;
            KeReleaseSpinLock(puVar4 + 0x14,uVar10);
            goto LAB_1c0002a60;
          }
          puVar5 = (undefined8 *)puVar4[0x16];
          plVar2 = (longlong *)(param_2 + 0xa8);
          if ((undefined8 *)*puVar5 != puVar4 + 0x15) {
LAB_1c0002c2c:
            pcVar8 = (code *)swi(0x29);
            (*pcVar8)(3);
            puVar14 = auStackY_60;
            goto LAB_1c0002c33;
          }
          *plVar2 = (longlong)(puVar4 + 0x15);
          *(undefined8 **)(param_2 + 0xb0) = puVar5;
          *puVar5 = plVar2;
          puVar4[0x16] = plVar2;
          LOCK();
          *(code **)(param_2 + 0x68) = KeyboardClassCancel;
          UNLOCK();
          if (*(char *)(param_2 + 0x44) == '\0') {
LAB_1c0002b1d:
            pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
            *pbVar1 = *pbVar1 | 1;
          }
          else {
            LOCK();
            lVar3 = *(longlong *)(param_2 + 0x68);
            *(longlong *)(param_2 + 0x68) = 0;
            UNLOCK();
            if (lVar3 == 0) {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,3,0x30,
                                   CONCAT44(in_stack_ffffffffffffffbc,uVar18),(char)*puVar4,
                                   (char)param_2);
              }
              goto LAB_1c0002b1d;
            }
            lVar3 = *plVar2;
            if ((*(longlong **)(lVar3 + 8) != plVar2) ||
               (plVar6 = *(longlong **)(param_2 + 0xb0), (longlong *)*plVar6 != plVar2))
            goto LAB_1c0002c2c;
            *plVar6 = lVar3;
            uVar15 = 0xc0000120;
            *(longlong **)(lVar3 + 8) = plVar6;
            *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,3,0x2f,
                                 CONCAT44(in_stack_ffffffffffffffbc,uVar18),(char)*puVar4,
                                 (char)param_2);
            }
            bVar9 = true;
          }
          KeReleaseSpinLock(puVar4 + 0x14,uVar10);
          if (!bVar9) {
            return uVar15;
          }
LAB_1c0002a60:
          IoReleaseRemoveLockEx(puVar4 + 4,param_2,0x20);
          IofCompleteRequest(param_2,0);
          return uVar15;
        }
LAB_1c0002c33:
        uVar16 = 0xc0000061;
        puVar13 = puVar14;
      }
      else {
        uVar16 = 0xc000009d;
        puVar13 = auStackY_68;
      }
    }
    else {
      uVar16 = 0xc0000023;
    }
    *(int *)(param_2 + 0x30) = (int)uVar16;
    puVar12 = puVar13;
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
LAB_1c0002ac1:
  *(undefined8 *)(puVar12 + -8) = 0x1c0002acd;
  IofCompleteRequest(param_2,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar7 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    *(undefined8 *)(puVar12 + -8) = 0x1c0002c64;
    WPP_RECORDER_SF_(uVar7,5,3,0x32);
  }
  return uVar16;
}



===== KeyboardClassReadCopyData @ 1c0002c70 =====

undefined8 KeyboardClassReadCopyData(undefined8 *param_1,longlong param_2,undefined8 param_3)

{
  int *piVar1;
  longlong lVar2;
  uint uVar3;
  void *_Src;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  void *pvVar7;
  undefined8 in_stack_ffffffffffffffa8;
  undefined1 uVar8;
  
  *(int *)(param_1 + 0x17) = *(int *)(param_1 + 0x17) + 1;
  lVar2 = *(longlong *)(param_2 + 0xb8);
  uVar6 = *(uint *)(lVar2 + 8);
  uVar5 = *(int *)((longlong)param_1 + 0x54) * 0xc;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qqLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  if (uVar6 <= uVar5) {
    uVar5 = uVar6;
  }
  uVar3 = (*(int *)((longlong)param_1 + 0x8c) - *(int *)(param_1 + 0xf)) + *(int *)(param_1 + 0xd);
  uVar4 = (ulonglong)uVar3;
  uVar6 = uVar3;
  if (uVar5 < uVar3) {
    uVar6 = uVar5;
  }
  uVar8 = (undefined1)param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar4 = CONCAT71((uint7)(uint3)(uVar3 >> 8),5);
    param_3 = 3;
    WPP_RECORDER_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x2a,
                        in_stack_ffffffffffffffa8,(char)*param_1,uVar8,(char)uVar3);
  }
  pvVar7 = *(void **)(param_2 + 0x18);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qqLqq
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,param_3,0x2b,
               in_stack_ffffffffffffffa8,(char)*param_1,uVar8,(char)uVar6,(char)param_1[0xf],
               (char)pvVar7);
  }
  _Src = (void *)param_1[0xf];
  uVar4 = (ulonglong)uVar6;
  memcpy(pvVar7,_Src,uVar4);
  pvVar7 = (void *)((longlong)pvVar7 + (ulonglong)uVar6);
  uVar3 = uVar5 - uVar6;
  if (uVar3 == 0) {
    param_1[0xf] = param_1[0xf] + (ulonglong)uVar6;
  }
  else {
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_qqLqq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),_Src,uVar4,0x2c,
                 in_stack_ffffffffffffffa8,(char)*param_1,uVar8,(char)uVar3,(char)param_1[0xd],
                 (char)pvVar7);
    }
    memcpy(pvVar7,(void *)param_1[0xd],(ulonglong)uVar3);
    param_1[0xf] = param_1[0xd] + (ulonglong)uVar3;
  }
  piVar1 = (int *)((longlong)param_1 + 0x54);
  *piVar1 = *piVar1 - uVar5 / 0xc;
  if (*piVar1 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,3,0x2d,
                         in_stack_ffffffffffffffa8,(char)*param_1,uVar8);
    }
    *(undefined1 *)((longlong)param_1 + 0x169) = 1;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qqqql(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar5;
  *(uint *)(lVar2 + 8) = uVar5;
  return 0;
}



===== WPP_RECORDER_SF_qq @ 1c0002f10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qq(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,param_4,&param_6,8,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,param_4,
                  &param_6,8,&param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_qqiL @ 1c0003050 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqiL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x35,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x35,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,0);
  return;
}



===== KeyboardClassPower @ 1c00031a0 =====

/* WARNING: Type propagation algorithm not settling */

int KeyboardClassPower(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  bool bVar6;
  bool bVar7;
  undefined1 uVar8;
  char cVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined8 in_stack_ffffffffffffffa8;
  undefined8 uVar13;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  puVar4 = *(undefined8 **)(param_1 + 0x40);
  bVar6 = true;
  iVar11 = *(int *)(lVar3 + 0x10);
  iVar2 = *(int *)(lVar3 + 0x18);
  if ((puVar4 == Globals) || (*(char *)(puVar4 + 8) == '\0')) {
    PoStartNextPowerIrp(param_2);
    *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
    IofCompleteRequest(param_2,0);
    return -0x3fffff45;
  }
  uVar13 = CONCAT44((int)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20),0x20);
  iVar10 = IoAcquireRemoveLockEx(puVar4 + 4,param_2,"",1);
  if (iVar10 < 0) {
    PoStartNextPowerIrp(param_2);
    *(int *)(param_2 + 0x30) = iVar10;
    IofCompleteRequest(param_2,0);
    return iVar10;
  }
  cVar9 = *(char *)(lVar3 + 1);
  if (cVar9 == '\x02') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    uVar12 = (undefined4)((ulonglong)uVar13 >> 0x20);
    if (iVar11 == 0) {
      if (*(int *)(puVar4 + 0x18) < iVar2) {
        iVar11 = IoAcquireRemoveLockEx(puVar4 + 4,param_2,"",1,CONCAT44(uVar12,0x20));
        if (-1 < iVar11) {
          uVar8 = KeAcquireSpinLockRaiseToDpc(puVar4 + 9);
          if ((puVar4[0x25] == 0) || (*(char *)(puVar4 + 0x26) != '\0')) {
            KeReleaseSpinLock(puVar4 + 9,uVar8);
LAB_1c00035e5:
            uVar12 = 4;
          }
          else {
            KeReleaseSpinLock(puVar4 + 9,uVar8);
            if (4 < iVar2) goto LAB_1c00035e5;
            uVar12 = *(undefined4 *)((longlong)puVar4 + (longlong)iVar2 * 4 + 0x108);
          }
          pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
          *pbVar1 = *pbVar1 | 1;
          iVar11 = PoRequestPowerIrp(*puVar4,2,uVar12,KeyboardClassPoRequestComplete,param_2,0);
          if (iVar11 < 0) {
            IoReleaseRemoveLockEx(puVar4 + 4,param_2,0x20);
            PoStartNextPowerIrp(param_2);
            *(int *)(param_2 + 0x30) = iVar11;
            IofCompleteRequest(param_2,0);
            IoReleaseRemoveLockEx(puVar4 + 4,param_2,0x20);
            return 0x103;
          }
          iVar11 = 0x103;
          goto LAB_1c0003396;
        }
        goto LAB_1c000336e;
      }
      if (*(int *)(puVar4 + 0x18) <= iVar2) {
        if (((iVar2 == 1) && (1 < *(int *)((longlong)puVar4 + 0x11c))) &&
           (1 < *(int *)(puVar4 + 0x24))) {
          uVar8 = KeAcquireSpinLockRaiseToDpc(puVar4 + 9);
          if ((puVar4[0x25] == 0) || (*(char *)(puVar4 + 0x26) != '\0')) {
            KeReleaseSpinLock(puVar4 + 9,uVar8);
            cVar9 = KeyboardClassCheckWaitWakeEnabled((longlong)puVar4);
            if (cVar9 != '\0') {
              KeyboardClassCreateWaitWakeIrp((longlong)puVar4);
            }
          }
          else {
            KeReleaseSpinLock(puVar4 + 9,uVar8);
          }
        }
        *(undefined4 *)(param_2 + 0x30) = 0;
        goto LAB_1c00032b6;
      }
      *(undefined4 *)(param_2 + 0x30) = 0;
LAB_1c00033d9:
      IoAcquireRemoveLockEx(puVar4 + 4,param_2,"",1,CONCAT44(uVar12,0x20));
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
      lVar3 = *(longlong *)(param_2 + 0xb8);
      *(code **)(lVar3 + -0x10) = KeyboardClassPowerComplete;
      *(undefined8 *)(lVar3 + -8) = 0;
      *(undefined1 *)(lVar3 + -0x45) = 0xe0;
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      PoCallDriver(puVar4[2],param_2);
      iVar11 = 0x103;
    }
    else {
      if (iVar11 == 1) {
        *(undefined4 *)(param_2 + 0x30) = 0;
        if (*(int *)((longlong)puVar4 + 0xbc) < iVar2) {
          PoSetPowerState(*puVar4,1,iVar2);
          *(int *)((longlong)puVar4 + 0xbc) = iVar2;
        }
        else if (iVar2 < *(int *)((longlong)puVar4 + 0xbc)) goto LAB_1c00033d9;
      }
LAB_1c00032b6:
      PoStartNextPowerIrp(param_2);
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      iVar11 = PoCallDriver(puVar4[2],param_2);
    }
  }
  else {
    if (cVar9 == '\0') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x61,uVar13,(char)param_1,
                           (char)param_2);
      }
      uVar12 = (undefined4)((ulonglong)uVar13 >> 0x20);
      uVar8 = KeAcquireSpinLockRaiseToDpc(puVar4 + 9);
      if (puVar4[0x25] == 0) {
        puVar4[0x25] = param_2;
        *(undefined1 *)(puVar4 + 0x26) = 0;
        LOCK();
        iVar11 = *(int *)(puVar4 + 0x28);
        *(int *)(puVar4 + 0x28) = 0;
        UNLOCK();
        if (iVar11 - 1U < 2) goto LAB_1c0003348;
        iVar11 = 0;
        bVar6 = true;
      }
      else {
        puVar4[0x27] = param_2;
LAB_1c0003348:
        bVar6 = false;
        iVar11 = -0x3ffffe7c;
      }
      KeReleaseSpinLock(puVar4 + 9,uVar8);
      bVar7 = bVar6;
    }
    else {
      if (cVar9 != '\x03') goto LAB_1c00032b6;
      iVar11 = 0;
      if ((iVar2 < 5) && (*(int *)(puVar4 + 0x24) < iVar2)) {
        uVar8 = KeAcquireSpinLockRaiseToDpc(puVar4 + 9);
        uVar12 = (undefined4)((ulonglong)uVar13 >> 0x20);
        if ((puVar4[0x25] == 0) || (*(char *)(puVar4 + 0x26) != '\0')) {
          KeReleaseSpinLock(puVar4 + 9,uVar8);
          goto LAB_1c0003529;
        }
        KeReleaseSpinLock(puVar4 + 9,uVar8);
        iVar11 = -0x3ffffd2d;
        bVar7 = false;
        *(undefined4 *)(param_2 + 0x30) = 0xc00002d3;
      }
      else {
LAB_1c0003529:
        uVar12 = (undefined4)((ulonglong)uVar13 >> 0x20);
        *(undefined4 *)(param_2 + 0x30) = 0;
        bVar7 = false;
      }
    }
    if (-1 < iVar11) {
      if (bVar7) goto LAB_1c00033d9;
      goto LAB_1c00032b6;
    }
LAB_1c000336e:
    *(int *)(param_2 + 0x30) = iVar11;
    PoStartNextPowerIrp(param_2);
    IofCompleteRequest(param_2,0);
  }
  if (!bVar6) {
    return iVar11;
  }
LAB_1c0003396:
  IoReleaseRemoveLockEx(puVar4 + 4,param_2,0x20);
  return iVar11;
}



===== WPP_RECORDER_SF_qqsd @ 1c00037a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqsd(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  char *in_stack_00000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (in_stack_00000040 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar3 = -1;
      do {
        lVar2 = lVar3;
        lVar3 = lVar2 + 1;
      } while (in_stack_00000040[lVar3] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar1 = in_stack_00000040;
    if (in_stack_00000040 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x60,&uStack0000000000000030,8,
               &uStack0000000000000038,8,pcVar1,lVar2,&uStack0000000000000048,4,0);
  }
  lVar2 = -1;
  if (in_stack_00000040 == (char *)0x0) {
    lVar3 = 5;
    in_stack_00000040 = "NULL";
  }
  else {
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (in_stack_00000040[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  WppAutoLogTrace(param_1,4,5,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x60,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,in_stack_00000040,lVar3,
                  &uStack0000000000000048,4,0);
  return;
}



===== KeyboardClassCheckWaitWakeEnabled @ 1c0003960 =====

undefined1 KeyboardClassCheckWaitWakeEnabled(longlong param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x48);
  uVar1 = *(undefined1 *)(param_1 + 0x16a);
  KeReleaseSpinLock(param_1 + 0x48,uVar2);
  return uVar1;
}



===== KeyboardClassCreate @ 1c00039b0 =====

int KeyboardClassCreate(longlong param_1,ulonglong param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  undefined1 *puVar2;
  longlong *plVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  ulonglong uVar7;
  byte bVar8;
  char *pcVar9;
  undefined **ppuVar10;
  uint local_res8;
  undefined4 uVar11;
  undefined4 in_stack_ffffffffffffff8c;
  
  bVar4 = false;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    param_4 = 0x1e;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x1e);
  }
  ppuVar10 = &WPP_RECORDER_INITIALIZED;
  puVar2 = *(undefined1 **)(param_2 + 0xb8);
  plVar3 = *(longlong **)(param_1 + 0x40);
  bVar8 = puVar2[2] & 1;
  if ((((*(char *)(param_2 + 0x40) == '\x01') || (bVar8 != 0)) &&
      (uVar7 = (ulonglong)*(uint *)(*(longlong *)(puVar2 + 8) + 0x10),
      (*(uint *)(*(longlong *)(puVar2 + 8) + 0x10) & 1) != 0)) &&
     ((*(uint *)(puVar2 + 0x10) & 1) == 0)) {
    iVar6 = -0x3fffffde;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqdDdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    if ((*(char *)(param_2 + 0x40) == '\0') && (bVar8 != 0)) {
      KbdClassTraceLoggingDeniedCreateForReadWithSFAC
                ((ulonglong)*(uint *)(*(longlong *)(puVar2 + 8) + 0x10),uVar7,ppuVar10,param_4);
    }
    goto LAB_1c0003b5e;
  }
  uVar11 = 0x20;
  pcVar9 = "";
  uVar7 = param_2;
  iVar6 = IoAcquireRemoveLockEx(plVar3 + 4,param_2,"",1);
  if (iVar6 < 0) goto LAB_1c0003b5e;
  if (((char)plVar3[8] == '\0') || (*(char *)((longlong)plVar3 + 0x41) != '\0')) {
    *(uint *)(puVar2 + 0x10) = *(uint *)(puVar2 + 0x10) & 0xfffffffe;
    if (*plVar3 == plVar3[1]) {
      if (bVar8 == 0) {
        uVar7 = (ulonglong)*(byte *)(param_2 + 0x40);
      }
      else {
        uVar7 = CONCAT71((int7)(uVar7 >> 8),1);
      }
      cVar5 = SeSinglePrivilegeCheck(7);
      if (cVar5 == '\0') {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar7 = *(ulonglong *)(puVar2 + 8);
          WPP_RECORDER_SF_qqDdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
      }
      else {
        bVar8 = KeAcquireSpinLockRaiseToDpc(plVar3 + 0x14);
        *(code **)(*(longlong *)(puVar2 + 0x30) + 0x20) = DriverEntry;
        uVar7 = (ulonglong)bVar8;
        *(int *)(plVar3 + 10) = (int)plVar3[10] + 1;
        KeReleaseSpinLock(plVar3 + 0x14);
      }
    }
    ExAcquireFastMutex(&DAT_1c000b1c0);
    if (Globals == plVar3) {
      DAT_1c000b1b4 = DAT_1c000b1b4 + 1;
      if (DAT_1c000b1b4 == 1) {
        if (DAT_1c000b1b0 != 0) {
          local_res8 = 0;
          bVar4 = false;
          do {
            puVar1 = (undefined8 *)(DAT_1c000b1a8 + (ulonglong)local_res8 * 0x18);
            if (*(char *)(DAT_1c000b1a8 + 0x13 + (ulonglong)local_res8 * 0x18) == '\0') {
              cVar5 = *(char *)(puVar1 + 2);
              *(undefined1 *)(puVar1 + 2) = 1;
              ExReleaseFastMutex(&DAT_1c000b1c0);
              if (cVar5 == '\0') {
                pcVar9 = (char *)puVar1[1];
                uVar7 = param_2;
                iVar6 = KbdEnableDisablePort('\x01',param_2,(longlong *)pcVar9,puVar1);
              }
              if (iVar6 < 0) {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar7,pcVar9,0x22,
                                      CONCAT44(in_stack_ffffffffffffff8c,uVar11),(char)param_1,
                                      (char)param_2,(char)*(undefined8 *)(puVar1[1] + 0x10));
                }
                uVar7 = 0xc0050009;
                pcVar9 = (char *)0x2788;
                uVar11 = 0;
                KeyboardClassLogError(param_1,0xc0050009,0x2788,iVar6,0,(undefined4 *)0x0,*puVar2);
                *(undefined1 *)(puVar1 + 2) = 0;
              }
              else {
                bVar4 = true;
              }
              ExAcquireFastMutex(&DAT_1c000b1c0);
            }
            local_res8 = local_res8 + 1;
          } while (local_res8 < DAT_1c000b1b0);
        }
        ExReleaseFastMutex(&DAT_1c000b1c0);
        if (bVar4) goto LAB_1c0003b42;
      }
      else {
        ExReleaseFastMutex(&DAT_1c000b1c0);
      }
    }
    else {
      ExReleaseFastMutex(&DAT_1c000b1c0);
      if (plVar3[1] != param_1) {
        *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
        *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
        iVar6 = IofCallDriver(plVar3[2]);
        IoReleaseRemoveLockEx(plVar3 + 4,param_2,0x20);
        return iVar6;
      }
      iVar6 = KbdEnableDisablePort('\x01',param_2,plVar3,(undefined8 *)(puVar2 + 0x30));
      if (iVar6 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_qqdq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
      }
      else {
LAB_1c0003b42:
        iVar6 = 0;
      }
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x20,
                         CONCAT44(in_stack_ffffffffffffff8c,uVar11),(char)param_1,(char)param_2);
    }
    iVar6 = -0x3fffffff;
  }
  IoReleaseRemoveLockEx(plVar3 + 4,param_2,0x20);
LAB_1c0003b5e:
  *(int *)(param_2 + 0x30) = iVar6;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x24);
  }
  return iVar6;
}



===== WPP_RECORDER_SF_qqdDdd @ 1c0003f20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqdDdd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined4 local_18 [4];
  
  local_18[0] = 0xc0000022;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x1f,&uStack0000000000000030,8,
               &uStack0000000000000038,8,local_18,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  WppAutoLogTrace(param_1,2,2,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x1f,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,local_18,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  return;
}



===== WPP_RECORDER_SF_qqDdd @ 1c00040e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqDdd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x21,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,3,2,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x21,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== KeyboardClassCleanup @ 1c0004260 =====

undefined8 KeyboardClassCleanup(longlong *param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  undefined8 uVar6;
  code *pcVar7;
  longlong *plVar8;
  undefined1 uVar9;
  undefined *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined8 unaff_RBP;
  undefined8 local_res8;
  undefined8 uStack_60;
  undefined1 auStack_58 [48];
  longlong local_28 [2];
  
  puVar12 = auStack_58;
  puVar11 = auStack_58;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (puVar10 = WPP_GLOBAL_Control, puVar11 = auStack_58, *(short *)(WPP_GLOBAL_Control + 0x48) != 0
     )) goto LAB_1c00043f8;
  while( true ) {
    lVar1 = *(longlong *)(param_2 + 0xb8);
    lVar2 = param_1[8];
    *(undefined8 *)(puVar11 + 0x60) = unaff_RBP;
    param_1 = *(longlong **)(lVar1 + 0x30);
    if ((code *)param_1[4] != DriverEntry) break;
    *(undefined1 **)(puVar11 + 0x38) = puVar11 + 0x30;
    *(undefined1 **)(puVar11 + 0x30) = puVar11 + 0x30;
    *(undefined8 *)(puVar11 + -8) = 0x1c00042e5;
    uVar9 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0xa0);
    plVar3 = *(longlong **)(lVar2 + 0xa8);
    while (plVar8 = plVar3, plVar8 != (longlong *)(lVar2 + 0xa8)) {
      plVar3 = (longlong *)*plVar8;
      if ((param_1 == (longlong *)0x0) || (*(longlong **)(plVar8[2] + 0x30) == param_1)) {
        if (((longlong *)plVar3[1] != plVar8) ||
           (puVar4 = (undefined8 *)plVar8[1], (longlong *)*puVar4 != plVar8)) goto LAB_1c00043f1;
        *puVar4 = plVar3;
        plVar3[1] = (longlong)puVar4;
        LOCK();
        lVar1 = plVar8[-8];
        plVar8[-8] = 0;
        UNLOCK();
        if (lVar1 == 0) {
          plVar8[1] = (longlong)plVar8;
          *plVar8 = (longlong)plVar8;
        }
        else {
          *(undefined4 *)(plVar8 + -0xf) = 0xc0000120;
          plVar8[-0xe] = 0;
          plVar5 = *(longlong **)(puVar11 + 0x38);
          if ((undefined1 *)*plVar5 != puVar11 + 0x30) goto LAB_1c00043f1;
          plVar8[1] = (longlong)plVar5;
          *plVar8 = (longlong)(puVar11 + 0x30);
          *plVar5 = (longlong)plVar8;
          *(longlong **)(puVar11 + 0x38) = plVar8;
        }
      }
    }
    *(undefined8 *)(puVar11 + -8) = 0x1c0004334;
    KeReleaseSpinLock(lVar2 + 0xa0,uVar9);
    while( true ) {
      param_1 = *(longlong **)(puVar11 + 0x30);
      if (param_1 == (longlong *)(puVar11 + 0x30)) goto LAB_1c0004348;
      if (((undefined1 *)param_1[1] != puVar11 + 0x30) ||
         (lVar1 = *param_1, *(longlong **)(lVar1 + 8) != param_1)) break;
      *(longlong *)(puVar11 + 0x30) = lVar1;
      *(undefined1 **)(lVar1 + 8) = puVar11 + 0x30;
      *(undefined8 *)(puVar11 + -8) = 0x1c00043ca;
      IofCompleteRequest(param_1 + -0x15,0);
      *(undefined8 *)(puVar11 + -8) = 0x1c00043e7;
      IoReleaseRemoveLockEx(lVar2 + 0x20,param_1 + -0x15,0x20);
    }
LAB_1c00043f1:
    puVar10 = (undefined *)0x3;
    pcVar7 = (code *)swi(0x29);
    (*pcVar7)();
    puVar12 = puVar11 + 8;
LAB_1c00043f8:
    uVar6 = *(undefined8 *)(puVar10 + 0x40);
    *(undefined8 *)(puVar12 + -8) = 0x1c000440d;
    WPP_RECORDER_SF_(uVar6,5,2,0x12);
    puVar11 = puVar12;
  }
LAB_1c0004348:
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined8 *)(puVar11 + -8) = 0x1c000435c;
  IofCompleteRequest(param_2,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    *(undefined8 *)(puVar11 + -8) = 0x1c0004488;
    WPP_RECORDER_SF_(uVar6,5,2,0x13);
  }
  return 0;
}



===== WPP_RECORDER_SF_qqL @ 1c00044a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqL(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,param_4,
                  &param_6,8,&param_7,8,&param_8,4,0);
  return;
}



===== KeyboardClassClose @ 1c0004620 =====

ulonglong KeyboardClassClose(longlong param_1,ulonglong param_2,longlong *param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  char cVar3;
  longlong *plVar4;
  undefined1 *puVar5;
  bool bVar6;
  byte bVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong *plVar10;
  uint uVar11;
  ulonglong uVar12;
  undefined4 in_stack_ffffffffffffffb8;
  undefined4 in_stack_ffffffffffffffbc;
  
  uVar8 = 0;
  bVar6 = false;
  uVar9 = param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar9 = CONCAT71((int7)(param_2 >> 8),5);
    param_3 = (longlong *)0x2;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x25);
  }
  plVar4 = *(longlong **)(param_1 + 0x40);
  puVar5 = *(undefined1 **)(param_2 + 0xb8);
  if (*plVar4 == plVar4[1]) {
    bVar7 = KeAcquireSpinLockRaiseToDpc(plVar4 + 0x14);
    uVar9 = (ulonglong)bVar7;
    if (*(code **)(*(longlong *)(puVar5 + 0x30) + 0x20) == DriverEntry) {
      *(int *)(plVar4 + 10) = (int)plVar4[10] + -1;
      *(undefined8 *)(*(longlong *)(puVar5 + 0x30) + 0x20) = 0;
    }
    KeReleaseSpinLock(plVar4 + 0x14);
  }
  ExAcquireFastMutex(&DAT_1c000b1c0);
  if (Globals == plVar4) {
    DAT_1c000b1b4 = DAT_1c000b1b4 + -1;
    if ((DAT_1c000b1b4 == 0) && (uVar12 = 0, DAT_1c000b1b0 != 0)) {
      do {
        puVar1 = (undefined8 *)(DAT_1c000b1a8 + uVar12 * 0x18);
        if (*(char *)(DAT_1c000b1a8 + 0x13 + uVar12 * 0x18) == '\0') {
          cVar3 = *(char *)(puVar1 + 2);
          *(undefined1 *)(puVar1 + 2) = 0;
          ExReleaseFastMutex();
          if (cVar3 != '\0') {
            LOCK();
            lVar2 = *(longlong *)(puVar1[1] + 0x148);
            *(longlong *)(puVar1[1] + 0x148) = 0;
            UNLOCK();
            if (lVar2 != 0) {
              IoUnregisterPlugPlayNotification();
            }
            param_3 = (longlong *)puVar1[1];
            uVar9 = param_2;
            uVar8 = KbdEnableDisablePort('\0',param_2,param_3,puVar1);
          }
          if ((int)uVar8 < 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar9,param_3,0x26,
                                  CONCAT44(in_stack_ffffffffffffffbc,in_stack_ffffffffffffffb8),
                                  (char)param_1,(char)param_2,
                                  (char)*(undefined8 *)(puVar1[1] + 0x10));
            }
            uVar9 = 0xc005000a;
            param_3 = (longlong *)0x2788;
            in_stack_ffffffffffffffb8 = 0;
            KeyboardClassLogError(param_1,0xc005000a,0x2788,uVar8,0,(undefined4 *)0x0,0);
          }
          else {
            bVar6 = true;
          }
          ExAcquireFastMutex(&DAT_1c000b1c0);
        }
        uVar11 = (int)uVar12 + 1;
        uVar12 = (ulonglong)uVar11;
      } while (uVar11 < DAT_1c000b1b0);
    }
    ExReleaseFastMutex(&DAT_1c000b1c0);
  }
  else {
    ExReleaseFastMutex();
    if (plVar4[1] != param_1) {
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      uVar9 = IofCallDriver(plVar4[2]);
      return uVar9;
    }
    uVar9 = param_2;
    plVar10 = plVar4;
    uVar8 = KbdEnableDisablePort('\0',param_2,plVar4,(undefined8 *)(puVar5 + 0x30));
    if ((int)uVar8 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar9,plVar10,0x27,
                            CONCAT44(in_stack_ffffffffffffffbc,in_stack_ffffffffffffffb8),
                            (char)param_1,(char)param_2,(char)plVar4[2]);
      }
      KeyboardClassLogError(param_1,0xc005000a,0x2788,uVar8,0,(undefined4 *)0x0,*puVar5);
    }
    else {
      bVar6 = true;
    }
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  uVar11 = 0;
  if (!bVar6) {
    uVar11 = uVar8;
  }
  *(uint *)(param_2 + 0x30) = uVar11;
  IofCompleteRequest(param_2,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x28);
  }
  return (ulonglong)uVar11;
}



===== WPP_RECORDER_SF_qqLd @ 1c0004980 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqLd
               (undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,&param_9,4,0);
  }
  WppAutoLogTrace(param_1,param_2,4,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,param_4,
                  &param_6,8,&param_7,8,&param_8,4,&param_9,4,0);
  return;
}



===== KbdSyncComplete @ 1c0004ae0 =====

undefined8 KbdSyncComplete(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== KeyboardClassWaitWakeComplete @ 1c0004b10 =====

void KeyboardClassWaitWakeComplete(void)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 *in_R9;
  int *in_stack_00000028;
  undefined8 *in_stack_ffffffffffffffd8;
  undefined1 uVar5;
  
  KeAcquireSpinLockRaiseToDpc(in_R9 + 9);
  lVar4 = in_R9[0x27];
  if ((lVar4 == 0) || (in_stack_00000028 != (int *)(lVar4 + 0x30))) {
    lVar2 = in_R9[0x25];
    lVar4 = 0;
    if ((lVar2 != 0) && (in_stack_00000028 == (int *)(lVar2 + 0x30))) {
      in_R9[0x25] = 0;
      *(undefined1 *)(in_R9 + 0x26) = 0;
      lVar4 = lVar2;
    }
  }
  else {
    in_R9[0x27] = 0;
  }
  KeReleaseSpinLock(in_R9 + 9);
  uVar5 = (undefined1)lVar4;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x5c,
                        in_stack_ffffffffffffffd8,(char)*in_R9,uVar5,(char)*in_stack_00000028);
  }
  iVar1 = *in_stack_00000028;
  if (iVar1 != -0x7fffffef) {
    if (iVar1 == 0) {
      in_stack_ffffffffffffffd8 = in_R9;
      PoRequestPowerIrp(in_R9[3],2,1,KeyboardClassWWPowerUpComplete);
    }
    else if ((((iVar1 != -0x3ffffee0) && (iVar1 != -0x3ffffe7c)) && (iVar1 != -0x3ffffd2d)) &&
            (iVar1 != -0x3febffdf)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x5e,
                            in_stack_ffffffffffffffd8,(char)*in_R9,uVar5,(char)iVar1);
      }
      uVar3 = KeyboardToggleWaitWake(in_R9,0);
      if (((int)uVar3 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
      goto LAB_1c0004b99;
    }
  }
  if ((*in_stack_00000028 < 0) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,5,0x5d,
                        in_stack_ffffffffffffffd8,(char)*in_R9,uVar5,(char)*in_stack_00000028);
  }
LAB_1c0004b99:
  IoReleaseRemoveLockEx(in_R9 + 4,lVar4,0x20);
  return;
}



===== WPP_RECORDER_SF_qqd @ 1c0004d60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqd(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,param_4,
                  &param_6,8,&param_7,8,&param_8,4,0);
  return;
}



===== KeyboardClassWWPowerUpComplete @ 1c0004ed0 =====

void KeyboardClassWWPowerUpComplete
               (undefined1 param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined4 in_stack_ffffffffffffffe8;
  undefined4 in_stack_ffffffffffffffec;
  
  if (*(char *)((longlong)param_4 + 0x16a) != '\0') {
    uVar5 = 0x20;
    uVar6 = 0x4364624b;
    puVar2 = (undefined8 *)ExAllocatePool2(0x40);
    if (puVar2 != (undefined8 *)0x0) {
      lVar3 = IoAllocateWorkItem();
      puVar2[2] = lVar3;
      if (lVar3 != 0) {
        puVar2[1] = param_4;
        *puVar2 = 0;
        iVar1 = IoAcquireRemoveLockEx(param_4 + 4,puVar2,"",1,0x20);
        if (iVar1 < 0) {
          IoFreeWorkItem(puVar2[2]);
          ExFreePoolWithTag(puVar2,0);
          return;
        }
        IoQueueWorkItem(puVar2[2],KeyboardClassCreateWaitWakeIrpWorker,1,puVar2);
        return;
      }
      uVar5 = 0;
      ExFreePoolWithTag(puVar2);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar5,uVar6,0x5b,
                        CONCAT44(in_stack_ffffffffffffffec,in_stack_ffffffffffffffe8),param_1);
    }
    puVar4 = (undefined4 *)IoAllocateErrorLogEntry(*param_4,0x30);
    if (puVar4 != (undefined4 *)0x0) {
      puVar4[3] = 0x8005000e;
      *puVar4 = 0;
      *(undefined8 *)(puVar4 + 6) = 0;
      puVar4[4] = 2;
      puVar4[5] = 0xc000009a;
      IoWriteErrorLogEntry(puVar4);
    }
  }
  return;
}



===== KeyboardClassPoRequestComplete @ 1c0005070 =====

void KeyboardClassPoRequestComplete
               (longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  char cVar4;
  int iVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined8 uVar8;
  char *pcVar9;
  undefined4 in_stack_ffffffffffffffd8;
  undefined4 in_stack_ffffffffffffffdc;
  
  puVar2 = *(undefined8 **)(param_1 + 0x40);
  if (param_4 != 0) {
    uVar1 = *(undefined4 *)(*(longlong *)(param_4 + 0xb8) + 0x18);
    PoSetPowerState(*puVar2,0,uVar1);
    *(undefined4 *)(puVar2 + 0x18) = uVar1;
    PoStartNextPowerIrp(param_4);
    *(char *)(param_4 + 0x43) = *(char *)(param_4 + 0x43) + '\x01';
    *(longlong *)(param_4 + 0xb8) = *(longlong *)(param_4 + 0xb8) + 0x48;
    PoCallDriver(puVar2[2],param_4);
    IoReleaseRemoveLockEx(puVar2 + 4,param_4,0x20);
    return;
  }
  if ((1 < *(int *)((longlong)puVar2 + 0x11c)) && (1 < *(int *)(puVar2 + 0x24))) {
    uVar3 = KeAcquireSpinLockRaiseToDpc(puVar2 + 9);
    if ((puVar2[0x25] != 0) && (*(char *)(puVar2 + 0x26) == '\0')) {
      KeReleaseSpinLock(puVar2 + 9,uVar3);
      return;
    }
    KeReleaseSpinLock(puVar2 + 9,uVar3);
    cVar4 = KeyboardClassCheckWaitWakeEnabled((longlong)puVar2);
    if (cVar4 != '\0') {
      uVar8 = 0x20;
      pcVar9 = (char *)0x4364624b;
      puVar6 = (undefined8 *)ExAllocatePool2(0x40);
      if (puVar6 != (undefined8 *)0x0) {
        lVar7 = IoAllocateWorkItem(*puVar2);
        puVar6[2] = lVar7;
        if (lVar7 != 0) {
          puVar6[1] = puVar2;
          *puVar6 = 0;
          pcVar9 = "";
          in_stack_ffffffffffffffd8 = 0x20;
          iVar5 = IoAcquireRemoveLockEx(puVar2 + 4,puVar6,"",1);
          if (-1 < iVar5) {
            IoQueueWorkItem(puVar6[2],KeyboardClassCreateWaitWakeIrpWorker,1,puVar6);
            return;
          }
          IoFreeWorkItem(puVar6[2]);
        }
        uVar8 = 0;
        ExFreePoolWithTag(puVar6);
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,pcVar9,0x62,
                          CONCAT44(in_stack_ffffffffffffffdc,in_stack_ffffffffffffffd8),
                          (char)param_1);
      }
      KeyboardClassLogError(*puVar2,0x8005000e,1,0xc000009a,0,(undefined4 *)0x0,0);
    }
  }
  return;
}



===== KeyboardClassCancel @ 1c00052c0 =====

void KeyboardClassCancel(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0xa0);
  plVar1 = (longlong *)(param_2 + 0xa8);
  lVar3 = *plVar1;
  if ((*(longlong **)(lVar3 + 8) == plVar1) &&
     (plVar4 = *(longlong **)(param_2 + 0xb0), (longlong *)*plVar4 == plVar1)) {
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    KeReleaseSpinLock(lVar2 + 0xa0,uVar6);
    *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
    IofCompleteRequest(param_2,0);
    IoReleaseRemoveLockEx(lVar2 + 0x20,param_2,0x20);
    return;
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



===== WPP_RECORDER_SF_qqdL @ 1c0005380 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqdL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000048;
  undefined4 local_18 [4];
  
  local_18[0] = 0xc0000010;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x19,&uStack0000000000000030,8,
               &uStack0000000000000038,8,local_18,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,2,4,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x19,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,local_18,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_S @ 1c00054c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_S(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,wchar_t *param_6)

{
  longlong lVar1;
  longlong lVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  longlong lVar5;
  
  lVar4 = -1;
  lVar5 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    if (param_6 == (wchar_t *)0x0) {
      lVar2 = 10;
    }
    else {
      lVar2 = -1;
      do {
        lVar1 = lVar2 + 1;
        lVar2 = lVar2 + 1;
      } while (param_6[lVar1] != L'\0');
      lVar2 = lVar2 * 2 + 2;
    }
    pwVar3 = param_6;
    if (param_6 == (wchar_t *)0x0) {
      pwVar3 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,param_4,pwVar3,lVar2,0);
  }
  if (param_6 != (wchar_t *)0x0) {
    do {
      lVar5 = lVar4 + 1;
      lVar4 = lVar4 + 1;
    } while (param_6[lVar5] != L'\0');
    lVar5 = lVar4 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,param_2,1,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,param_4,param_6
                  ,lVar5,0);
  return;
}



===== KbdInitializeDataQueue @ 1c0005600 =====

void KbdInitializeDataQueue(longlong param_1)

{
  undefined1 uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x53);
  }
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xa0);
  *(undefined8 *)(param_1 + 0x70) = *(undefined8 *)(param_1 + 0x68);
  *(undefined8 *)(param_1 + 0x78) = *(undefined8 *)(param_1 + 0x68);
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined1 *)(param_1 + 0x169) = 1;
  KeReleaseSpinLock(param_1 + 0xa0,uVar1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x54);
  }
  return;
}



===== KeyboardPnpStartCompletion @ 1c00056d0 =====

undefined8 KeyboardPnpStartCompletion(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  IoQueueWorkItem(*param_3,KeyboardStartWorker,1,param_3);
  return 0xc0000016;
}



===== RtlUnicodeStringPrintf @ 1c0005710 =====

undefined8
RtlUnicodeStringPrintf(ushort *param_1,wchar_t *param_2,undefined8 param_3,undefined8 param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ulonglong uVar4;
  ulonglong _Count;
  undefined8 uVar5;
  undefined8 local_res18;
  undefined8 local_res20;
  
  uVar1 = *param_1;
  if ((((((uVar1 & 1) != 0) || (uVar2 = param_1[1], (uVar2 & 1) != 0)) || (uVar2 < uVar1)) ||
      (uVar2 == 0xffff)) || ((*(longlong *)(param_1 + 4) == 0 && ((uVar1 != 0 || (uVar2 != 0)))))) {
    return 0xc000000d;
  }
  _Count = (ulonglong)(param_1[1] >> 1);
  uVar5 = 0;
  local_res18 = param_3;
  local_res20 = param_4;
  iVar3 = _vsnwprintf(*(wchar_t **)(param_1 + 4),_Count,param_2,(va_list)&local_res18);
  if ((iVar3 < 0) || (uVar4 = (longlong)iVar3, _Count < (ulonglong)(longlong)iVar3)) {
    uVar5 = 0x80000005;
    uVar4 = _Count;
  }
  *param_1 = (short)uVar4 * 2;
  return uVar5;
}



===== WPP_RECORDER_SF_qqdq @ 1c00057d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqdq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x23,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,8,0);
  }
  WppAutoLogTrace(param_1,2,2,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x23,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,8,0);
  return;
}



===== RtlUnicodeStringValidateDestWorker @ 1c0005900 =====

undefined8
RtlUnicodeStringValidateDestWorker(ushort *param_1,undefined8 *param_2,ulonglong *param_3)

{
  ushort uVar1;
  ushort uVar2;
  
  uVar1 = *param_1;
  *param_2 = 0;
  *param_3 = 0;
  if ((uVar1 & 1) == 0) {
    uVar2 = param_1[1];
    if (((((uVar2 & 1) == 0) && (uVar1 <= uVar2)) && (uVar2 != 0xffff)) &&
       ((*(longlong *)(param_1 + 4) != 0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
      *param_2 = *(undefined8 *)(param_1 + 4);
      *param_3 = (ulonglong)(param_1[1] >> 1);
      return 0;
    }
  }
  return 0xc000000d;
}



===== KeyboardClassLogError @ 1c0005970 =====

void KeyboardClassLogError
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               uint param_5,undefined4 *param_6,undefined1 param_7)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  ulonglong uVar3;
  
  puVar1 = (undefined1 *)IoAllocateErrorLogEntry();
  if (puVar1 != (undefined1 *)0x0) {
    *(undefined4 *)(puVar1 + 0xc) = param_2;
    *(undefined8 *)(puVar1 + 0x18) = 0;
    *(short *)(puVar1 + 2) = (short)param_5 << 2;
    *puVar1 = param_7;
    puVar1[1] = 0;
    *(undefined4 *)(puVar1 + 0x10) = param_3;
    *(undefined4 *)(puVar1 + 0x14) = param_4;
    if (param_5 != 0) {
      uVar3 = (ulonglong)param_5;
      puVar2 = param_6;
      do {
        *(undefined4 *)(puVar1 + (0x28 - (longlong)param_6) + (longlong)puVar2) = *puVar2;
        puVar2 = puVar2 + 1;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    IoWriteErrorLogEntry(puVar1);
  }
  return;
}



===== __report_gsfailure @ 1c0005a30 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== KbdClassTraceLoggingDeniedCreateForReadWithSFAC @ 1c0005a40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void KbdClassTraceLoggingDeniedCreateForReadWithSFAC
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  undefined1 auStackY_78 [32];
  undefined4 local_48 [2];
  undefined8 local_40 [4];
  undefined4 *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  if (5 < DAT_1c000b000) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      local_14 = 0;
      local_20 = local_48;
      local_48[0] = (undefined4)param_1;
      local_18 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_1c00096a1,param_3,param_4,3,local_40);
    }
  }
  return;
}



===== KeyboardCallAllPorts @ 1c0005ac0 =====

undefined4 KeyboardCallAllPorts(undefined8 param_1,longlong param_2,uint *param_3)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  undefined8 *puVar4;
  longlong lVar5;
  longlong lVar6;
  undefined4 uVar7;
  uint uVar8;
  
  uVar2 = param_3[1];
  puVar4 = *(undefined8 **)(param_2 + 0xb8);
  puVar4[-9] = *puVar4;
  puVar4[-8] = puVar4[1];
  puVar4[-7] = puVar4[2];
  puVar4[-6] = puVar4[3];
  *(undefined4 *)(puVar4 + -5) = *(undefined4 *)(puVar4 + 4);
  *(undefined4 *)((longlong)puVar4 + -0x24) = *(undefined4 *)((longlong)puVar4 + 0x24);
  *(undefined4 *)(puVar4 + -4) = *(undefined4 *)(puVar4 + 5);
  *(undefined4 *)((longlong)puVar4 + -0x1c) = *(undefined4 *)((longlong)puVar4 + 0x2c);
  puVar4[-3] = puVar4[6];
  *(undefined1 *)((longlong)puVar4 + -0x45) = 0;
  *(undefined1 *)(puVar4 + -9) = 0xf;
  uVar8 = param_3[1];
  uVar3 = *param_3;
  if (uVar8 < uVar3) {
    do {
      if (((char)param_3[(ulonglong)uVar8 * 6 + 6] != '\0') &&
         (*(char *)((longlong)param_3 + (ulonglong)uVar8 * 0x18 + 0x1b) == '\0')) break;
      uVar8 = uVar8 + 1;
      param_3[1] = uVar8;
    } while (uVar8 < uVar3);
    if (uVar8 < uVar3) {
      lVar5 = *(longlong *)(param_3 + (ulonglong)uVar8 * 6 + 4);
      puVar4[-3] = *(undefined8 *)(param_3 + (ulonglong)uVar8 * 6 + 2);
      param_3[1] = param_3[1] + 1;
      lVar6 = *(longlong *)(param_2 + 0xb8);
      *(code **)(lVar6 + -0x10) = KeyboardCallAllPorts;
      *(uint **)(lVar6 + -8) = param_3;
      *(undefined1 *)(lVar6 + -0x45) = 0xe0;
      uVar7 = IofCallDriver(*(undefined8 *)(lVar5 + 0x10),param_2);
      IoReleaseRemoveLockEx(lVar5 + 0x20,param_2,0x20);
      if (uVar2 == 0) {
        return uVar7;
      }
      return 0xc0000016;
    }
  }
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  IoReleaseRemoveLockEx(Globals + 0x20,param_2,0x20);
  ExFreePoolWithTag(param_3,0);
  return 0;
}



===== KeyboardClassFlush @ 1c0005c20 =====

undefined4 KeyboardClassFlush(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x1c);
  }
  plVar1 = *(longlong **)(param_1 + 0x40);
  if (*plVar1 == plVar1[1]) {
    if (*(code **)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x20) == DriverEntry) {
      KbdInitializeDataQueue((longlong)plVar1);
    }
    else {
      uVar2 = 0xc0000061;
    }
  }
  else {
    uVar2 = 0xc00000bb;
  }
  *(undefined4 *)(param_2 + 0x30) = uVar2;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x1d);
  }
  return uVar2;
}



===== KeyboardClassQueryWmiDataBlock @ 1c0005d20 =====

void KeyboardClassQueryWmiDataBlock
               (longlong param_1,undefined8 param_2,int param_3,int param_4,int param_5,
               undefined4 *param_6,uint param_7,longlong *param_8)

{
  longlong lVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar4 = 0;
  if (param_3 == 0) {
    if ((param_4 != 0) || (param_5 != 1)) {
LAB_1c0005df4:
      uVar5 = 0xc0000010;
      goto LAB_1c0005dfa;
    }
    uVar4 = 8;
    if (param_7 < 8) {
LAB_1c0005dd8:
      uVar5 = 0xc0000023;
      goto LAB_1c0005dfa;
    }
    *param_8 = param_1;
  }
  else {
    if (param_3 != 1) {
      uVar5 = 0xc0000295;
      goto LAB_1c0005dfa;
    }
    if ((param_4 != 0) || (param_5 != 1)) goto LAB_1c0005df4;
    uVar4 = 1;
    if (param_7 == 0) goto LAB_1c0005dd8;
    uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x48);
    if ((*(longlong *)(lVar1 + 0x128) == 0) || (*(char *)(lVar1 + 0x130) != '\0')) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
    KeReleaseSpinLock(lVar1 + 0x48,uVar2);
    *(undefined1 *)param_8 = uVar3;
  }
  uVar5 = 0;
  *param_6 = uVar4;
LAB_1c0005dfa:
  WmiCompleteRequest(param_1,param_2,uVar5,uVar4,0);
  return;
}



===== KeyboardToggleWaitWake @ 1c0005e38 =====

undefined8 KeyboardToggleWaitWake(undefined8 *param_1,undefined1 param_2)

{
  undefined8 *puVar1;
  char cVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  
  puVar1 = param_1 + 4;
  uVar3 = IoAcquireRemoveLockEx(puVar1,KeyboardToggleWaitWakeWorker,"",1,0x20);
  if (-1 < (int)uVar3) {
    lVar4 = ExAllocatePool2(0x40,0x20,0x4364624b);
    if (lVar4 == 0) {
      IoReleaseRemoveLockEx(puVar1,KeyboardToggleWaitWakeWorker,0x20);
    }
    else {
      lVar5 = IoAllocateWorkItem(*param_1);
      *(longlong *)(lVar4 + 0x10) = lVar5;
      if (lVar5 == 0) {
        IoReleaseRemoveLockEx(puVar1,KeyboardToggleWaitWakeWorker,0x20);
        ExFreePoolWithTag(lVar4,0);
        return 0xc000009a;
      }
      *(undefined8 **)(lVar4 + 8) = param_1;
      *(undefined1 *)(lVar4 + 0x18) = param_2;
      cVar2 = KeGetCurrentIrql();
      if (cVar2 == '\0') {
        KeyboardToggleWaitWakeWorker(*param_1,lVar4);
      }
      else {
        IoQueueWorkItem(*(undefined8 *)(lVar4 + 0x10),KeyboardToggleWaitWakeWorker,1,lVar4);
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}



===== KeyboardToggleWaitWakeWorker @ 1c0005f80 =====

void KeyboardToggleWaitWakeWorker(undefined8 param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  bool bVar3;
  undefined1 uVar4;
  int iVar5;
  longlong lVar6;
  bool bVar7;
  uint local_res10 [2];
  undefined8 local_res18;
  undefined8 local_38;
  undefined8 uStack_30;
  
  lVar2 = *(longlong *)(param_2 + 8);
  lVar6 = 0;
  cVar1 = *(char *)(param_2 + 0x18);
  bVar3 = false;
  bVar7 = cVar1 != '\0';
  uVar4 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x48);
  if (bVar7 != (bool)*(char *)(lVar2 + 0x16a)) {
    bVar3 = true;
    if (((*(char *)(lVar2 + 0x16a) != '\0') && (*(longlong *)(lVar2 + 0x128) != 0)) &&
       (*(char *)(lVar2 + 0x130) == '\0')) {
      *(undefined1 *)(lVar2 + 0x130) = 1;
      lVar6 = *(longlong *)(lVar2 + 0x128);
    }
    *(bool *)(lVar2 + 0x16a) = bVar7;
  }
  KeReleaseSpinLock(lVar2 + 0x48,uVar4);
  if (bVar3) {
    local_res18 = 0;
    local_res10[0] = (uint)bVar7;
    local_38 = 0;
    uStack_30 = 0;
    iVar5 = IoOpenDeviceRegistryKey(*(undefined8 *)(lVar2 + 0x18),1,0x1f0000,&local_res18);
    if (-1 < iVar5) {
      RtlInitUnicodeString(&local_38,L"WaitWakeEnabled");
      ZwSetValueKey(local_res18,&local_38,0,4,local_res10,4);
      ZwClose(local_res18);
    }
    if (cVar1 != '\0') {
      KeyboardClassCreateWaitWakeIrp(lVar2);
    }
  }
  if (lVar6 != 0) {
    IoCancelIrp(lVar6);
  }
  IoReleaseRemoveLockEx(lVar2 + 0x20,KeyboardToggleWaitWakeWorker,0x20);
  IoFreeWorkItem(*(undefined8 *)(param_2 + 0x10));
  ExFreePoolWithTag(param_2,0);
  return;
}



===== RtlUnicodeStringCopyString @ 1c000612c =====

ulonglong RtlUnicodeStringCopyString(ushort *param_1)

{
  short sVar1;
  ulonglong uVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  ulonglong local_res10;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  local_res10 = 0;
  uVar2 = RtlUnicodeStringValidateDestWorker(param_1,local_res18,&local_res10);
  if ((int)uVar2 < 0) {
    return uVar2 & 0xffffffff;
  }
  pwVar3 = L"KeyboardClass";
  lVar4 = 0x7fff;
  uVar2 = 0;
  sVar1 = 0;
  if (local_res10 != 0) {
    do {
      if ((lVar4 == 0) || (*pwVar3 == L'\0')) break;
      *(wchar_t *)(local_res18[0] + -0x1c0009358 + (longlong)pwVar3) = *pwVar3;
      lVar4 = lVar4 + -1;
      pwVar3 = pwVar3 + 1;
      sVar1 = sVar1 + 1;
      local_res10 = local_res10 - 1;
    } while (local_res10 != 0);
    if (((local_res10 != 0) || (lVar4 == 0)) || (*pwVar3 == L'\0')) goto LAB_1c00061ba;
  }
  uVar2 = 0x80000005;
LAB_1c00061ba:
  *param_1 = sVar1 * 2;
  return uVar2;
}



===== WPP_RECORDER_SF_ @ 1c00061d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,param_4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,param_4,0
                 );
  return;
}



===== WPP_RECORDER_SF_D @ 1c00062b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_D(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,param_4,&param_6,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,param_4,&param_6,4,0)
  ;
  return;
}



===== WPP_RECORDER_SF_d @ 1c0006360 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_d(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,param_4,&param_6,4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,param_4,
                  &param_6,4,0);
  return;
}



===== WPP_RECORDER_SF_q @ 1c0006414 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_q(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,param_4,&param_6,8,0);
  }
  WppAutoLogTrace(param_1,2,5,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,param_4,&param_6,8,0)
  ;
  return;
}



===== WPP_RECORDER_SF_qL @ 1c00064c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x36,&uStack0000000000000030,8,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,5,3,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x36,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_qLL @ 1c0006594 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,5,3,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,param_4,&param_6,8,
                  &param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qLqq @ 1c000668c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLqq
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,8,&param_9,8,0);
  }
  WppAutoLogTrace(param_1,5,3,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,param_4,&param_6,8,
                  &param_7,4,&param_8,8,&param_9,8,0);
  return;
}



===== WPP_RECORDER_SF_qd @ 1c00067a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x5f,&uStack0000000000000030,8,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,2,5,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x5f,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_qlqqd @ 1c0006878 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qlqqd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x3c,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,8,&uStack0000000000000048,8,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,5,3,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x3c,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,8,
                  &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_qqLL @ 1c00069b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqLL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x29,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,5,3,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x29,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_qqLLqq @ 1c0006acc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqLLqq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x34,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,8,&uStack0000000000000058,8,0);
  }
  WppAutoLogTrace(param_1,5,3,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x34,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,8,&uStack0000000000000058,8,0);
  return;
}



===== WPP_RECORDER_SF_qqLqq @ 1c0006c24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqLqq
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,&param_9,8,&param_10,8,0);
  }
  WppAutoLogTrace(param_1,5,3,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,4,&param_9,8,&param_10,8,0);
  return;
}



===== WPP_RECORDER_SF_qqdd @ 1c0006d60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqdd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x18,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,2,4,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x18,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_qqq @ 1c0006e78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,8,0);
  }
  WppAutoLogTrace(param_1,2,2,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,8,0);
  return;
}



===== WPP_RECORDER_SF_qqqql @ 1c0006f64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqqql(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x2e,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,&uStack0000000000000048,8,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,5,3,&WPP_1b6d0084df9f3ca48f318fdd34bf6db2_Traceguids,0x2e,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,
                  &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  return;
}



===== WppClassicProviderCallback @ 1c00070a0 =====

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



===== _tlgDefineProvider_annotation__Tlgg_TraceLoggingProviderProv @ 1c00070fc =====

void _tlgDefineProvider_annotation__Tlgg_TraceLoggingProviderProv(void)

{
  return;
}



===== _guard_check_icall @ 1c0007110 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0007128 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000714c =====

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



===== __cpu_features_init @ 1c00071c0 =====

/* WARNING: Removing unreachable block (ram,0x0001c000722a) */
/* WARNING: Removing unreachable block (ram,0x0001c00071d9) */
/* WARNING: Removing unreachable block (ram,0x0001c00071ca) */

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



===== __security_check_cookie @ 1c0007290 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c00072d0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0007300 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0007300. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0007330 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0007380 =====

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



===== memset @ 1c0007680 =====

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



===== __memset_repmovs @ 1c00077c0 =====

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



===== __memset_query @ 1c0007840 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c00078c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0007a00 =====

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



===== __memset_spec_plain @ 1c0007a80 =====

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



===== KeyboardClassFindMorePorts @ 1c000e010 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void KeyboardClassFindMorePorts(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  int iVar4;
  ulonglong uVar5;
  wchar_t *pwVar6;
  longlong *plVar7;
  uint uVar8;
  undefined1 auStackY_2c8 [32];
  uint local_288 [2];
  longlong local_280;
  undefined8 local_278;
  longlong lStack_270;
  ushort local_268 [4];
  undefined1 *local_260;
  longlong local_258;
  wchar_t *local_250 [3];
  undefined1 local_238 [512];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_2c8;
  local_268[0] = 0;
  local_268[1] = 0x200;
  local_268[2] = 0;
  local_268[3] = 0;
  local_258 = 0;
  local_288[0] = 0;
  pwVar6 = (wchar_t *)0x0;
  local_280 = 0;
  local_250[0] = (wchar_t *)0x0;
  local_278 = 0;
  lStack_270 = 0;
  memset(local_238,0,0x200);
  local_260 = local_238;
  RtlCopyUnicodeString(local_268,&DAT_1c000b398);
  local_268[0] = local_268[0] - 10;
  RtlAppendUnicodeToString(local_268,L"Port");
  RtlInitUnicodeString(&local_278,0);
  local_278._0_4_ = CONCAT22(local_268[0] + 0x14,(undefined2)local_278);
  lStack_270 = ExAllocatePool2(0x100,local_268[0] + 0x14,0x4364624b);
  if (lStack_270 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x58);
    }
    local_250[0] = (wchar_t *)CONCAT44(local_250[0]._4_4_,(uint)local_278._2_2_);
    KeyboardClassLogError(param_1,0xc0050001,0x2718,0xc0000001,1,(undefined4 *)local_250,0);
  }
  else {
    RtlAppendUnicodeToString(&local_278,L"\\Device\\");
    RtlAppendUnicodeToString(&local_278,local_260);
    RtlAppendUnicodeToString(&local_278,L"0");
    KbdDeterminePortsServiced(local_268,local_288);
    uVar8 = DAT_1c000b1b8;
    if (DAT_1c000b1b8 < DAT_1c000b200) {
      do {
        if (local_288[0] <= uVar8) break;
        *(short *)(lStack_270 + -2 + (local_278 >> 1 & 0x7fff) * 2) = (short)uVar8 + 0x30;
        uVar5 = KbdCreateClassObject(param_1,(longlong *)&DAT_1c000b208,&local_258,local_250,'\x01')
        ;
        if ((int)uVar5 < 0) {
          KeyboardClassLogError(param_1,0xc0050001,0x2718,(int)uVar5,0,(undefined4 *)0x0,0);
          pwVar6 = local_250[0];
        }
        else {
          plVar1 = *(longlong **)(local_258 + 0x40);
          *plVar1 = local_258;
          *(undefined1 *)(plVar1 + 8) = 0;
          iVar4 = IoGetDeviceObjectPointer(&local_278,0x80,&local_280,plVar1 + 2);
          pwVar6 = local_250[0];
          if (iVar4 == 0) {
            *(char *)(local_258 + 0x4c) = *(char *)(plVar1[2] + 0x4c) + '\x01';
            uVar5 = KeyboardAddDeviceEx(plVar1,local_250[0],local_280);
            *(uint *)(local_258 + 0x30) = *(uint *)(local_258 + 0x30) & 0xffffff7f;
            if (pwVar6 != (wchar_t *)0x0) {
              ExFreePoolWithTag(pwVar6,0);
              pwVar6 = (wchar_t *)0x0;
              local_250[0] = (wchar_t *)0x0;
            }
            if ((int)uVar5 < 0) {
              if (Globals == 0) {
                lVar2 = plVar1[0x2c];
                if (lVar2 != 0) {
                  plVar1[0x2c] = 0;
                  local_280 = lVar2;
                }
              }
              else {
                ExAcquireFastMutex(&DAT_1c000b1c0);
                local_280 = *(longlong *)
                             (DAT_1c000b1a8 + (ulonglong)*(uint *)((longlong)plVar1 + 0xc4) * 0x18);
                *(undefined8 *)
                 (DAT_1c000b1a8 + (ulonglong)*(uint *)((longlong)plVar1 + 0xc4) * 0x18) = 0;
                *(undefined1 *)
                 (DAT_1c000b1a8 + 0x13 + (ulonglong)*(uint *)((longlong)plVar1 + 0xc4) * 0x18) = 1;
                *(undefined8 *)
                 (DAT_1c000b1a8 + 8 + (ulonglong)*(uint *)((longlong)plVar1 + 0xc4) * 0x18) = 0;
                ExReleaseFastMutex(&DAT_1c000b1c0);
              }
              if (local_280 != 0) {
                ObfDereferenceObject();
              }
              if (plVar1[0xd] != 0) {
                ExFreePoolWithTag(plVar1[0xd],0);
                plVar1[0xf] = 0;
                plVar1[0xe] = 0;
                plVar1[0xd] = 0;
              }
              IoDeleteDevice(*plVar1);
            }
            else {
              plVar7 = plVar1 + 0x2a;
              if ((undefined8 *)*DAT_1c000b5b0 != &DAT_1c000b5a8) {
                pcVar3 = (code *)swi(0x29);
                (*pcVar3)(3);
                pcVar3 = (code *)swi(3);
                (*pcVar3)();
                return;
              }
              *plVar7 = (longlong)&DAT_1c000b5a8;
              plVar1[0x2b] = (longlong)DAT_1c000b5b0;
              *DAT_1c000b5b0 = (longlong)plVar7;
              DAT_1c000b5b0 = plVar7;
            }
          }
          else {
            if (plVar1[0xd] != 0) {
              ExFreePoolWithTag(plVar1[0xd],0);
              plVar1[0xf] = 0;
              plVar1[0xe] = 0;
              plVar1[0xd] = 0;
            }
            IoDeleteDevice(*plVar1);
            pwVar6 = local_250[0];
          }
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < DAT_1c000b200);
    }
    DAT_1c000b1b8 = uVar8;
  }
  if (lStack_270 != 0) {
    ExFreePoolWithTag(lStack_270,0);
  }
  if (pwVar6 != (wchar_t *)0x0) {
    ExFreePoolWithTag(pwVar6,0);
  }
  return;
}



===== WppLoadTracingSupport @ 1c000e4c0 =====

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



===== KbdDeterminePortsServiced @ 1c000e610 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int KbdDeterminePortsServiced(ushort *param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *puVar3;
  code *pcVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined8 local_18;
  undefined8 uStack_10;
  
  *param_2 = 0;
  if ((ulonglong)*param_1 + 2 <= (ulonglong)param_1[1]) {
    *(undefined2 *)(*(longlong *)(param_1 + 4) + 2 + (ulonglong)(*param_1 >> 1) * 2) = 0;
    puVar3 = (undefined8 *)ExAllocatePool2(0x100,0x70,0x4364624b);
    if (puVar3 != (undefined8 *)0x0) {
      puVar3[2] = 0;
      *puVar3 = KbdDeviceMapQueryCallback;
      uVar1 = *(undefined8 *)(param_1 + 4);
      local_18 = 0;
      uStack_10 = 0;
      RtlInitUnicodeString(&local_18,L"RtlQueryRegistryValuesEx");
      pcVar4 = (code *)MmGetSystemRoutineAddress(&local_18);
      uVar6 = 0;
      if (pcVar4 == (code *)0x0) {
        pcVar4 = RtlQueryRegistryValues_exref;
      }
      puVar5 = puVar3;
      iVar2 = (*pcVar4)(0x80000004,uVar1,puVar3,param_2);
      if ((iVar2 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar5,0x50,uVar6,(char)iVar2
                         );
      }
      ExFreePoolWithTag(puVar3,0);
      return iVar2;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x4f);
    }
  }
  return -0x3fffffff;
}



===== KbdDeviceMapQueryCallback @ 1c000e770 =====

undefined8 KbdDeviceMapQueryCallback(void)

{
  int *in_stack_00000028;
  
  *in_stack_00000028 = *in_stack_00000028 + 1;
  return 0;
}



===== KeyboardClassEnableGlobalPort @ 1c000e784 =====

int KeyboardClassEnableGlobalPort(longlong *param_1,char param_2)

{
  undefined8 *puVar1;
  char cVar2;
  int iVar3;
  ulonglong uVar4;
  
  iVar3 = 0;
  ExAcquireFastMutex(&DAT_1c000b1c0);
  if (DAT_1c000b1b4 < 1) {
    ExReleaseFastMutex(&DAT_1c000b1c0);
  }
  else {
    for (uVar4 = 0; (uint)uVar4 < DAT_1c000b1b0; uVar4 = (ulonglong)((uint)uVar4 + 1)) {
      puVar1 = (undefined8 *)(DAT_1c000b1a8 + uVar4 * 0x18);
      if ((*(char *)((longlong)puVar1 + 0x13) == '\0') && ((longlong *)puVar1[1] == param_1)) {
        if (puVar1 != (undefined8 *)0x0) {
          cVar2 = *(char *)(puVar1 + 2);
          *(char *)(puVar1 + 2) = param_2;
          ExReleaseFastMutex(&DAT_1c000b1c0);
          if (param_2 != cVar2) {
            iVar3 = KbdEnableDisablePort(param_2,0,param_1,puVar1);
          }
          goto LAB_1c000e85a;
        }
        break;
      }
    }
    ExReleaseFastMutex(&DAT_1c000b1c0);
    iVar3 = -0x3ffffff2;
  }
LAB_1c000e85a:
  return iVar3;
}



===== KeyboardClassPlugPlayNotification @ 1c000e880 =====

void KeyboardClassPlugPlayNotification(longlong param_1,longlong *param_2)

{
  char cVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 4) + -0x11d046f0cb3a4006;
  if (lVar2 == 0) {
    lVar2 = *(longlong *)(param_1 + 0xc) + -0x3f05139760008fb0;
  }
  if (lVar2 != 0) {
    lVar2 = *(longlong *)(param_1 + 4) + -0x11d046f0cb3a4008;
    if (lVar2 == 0) {
      lVar2 = *(longlong *)(param_1 + 0xc) + -0x3f05139760008fb0;
    }
    if (lVar2 != 0) {
      lVar2 = *(longlong *)(param_1 + 4) + -0x11d046f0cb3a4007;
      if (lVar2 == 0) {
        lVar2 = *(longlong *)(param_1 + 0xc) + -0x3f05139760008fb0;
      }
      if (lVar2 != 0) {
        return;
      }
      LOCK();
      lVar2 = param_2[0x29];
      param_2[0x29] = 0;
      UNLOCK();
      if (lVar2 == 0) {
        return;
      }
      IoUnregisterPlugPlayNotification();
      cVar1 = '\x01';
      goto LAB_1c000e923;
    }
    LOCK();
    lVar2 = param_2[0x29];
    param_2[0x29] = 0;
    UNLOCK();
    if (lVar2 == 0) {
      return;
    }
    IoUnregisterPlugPlayNotification();
  }
  cVar1 = '\0';
LAB_1c000e923:
  KeyboardClassEnableGlobalPort(param_2,cVar1);
  return;
}



===== KeyboardClassSetWmiDataBlock @ 1c000e940 =====

void KeyboardClassSetWmiDataBlock
               (longlong param_1,undefined8 param_2,int param_3,int param_4,int param_5,
               undefined1 *param_6)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (param_3 == 0) {
    uVar1 = 0xc00002c6;
  }
  else if (param_3 == 1) {
    uVar3 = 1;
    if (param_5 == 0) {
      uVar1 = 0xc0000023;
    }
    else if (param_4 == 0) {
      uVar2 = KeyboardToggleWaitWake(*(undefined8 **)(param_1 + 0x40),*param_6);
      uVar1 = (undefined4)uVar2;
    }
    else {
      uVar1 = 0xc0000010;
    }
  }
  else {
    uVar1 = 0xc0000295;
  }
  WmiCompleteRequest(param_1,param_2,uVar1,uVar3,0);
  return;
}



===== KeyboardClassSetWmiDataItem @ 1c000e9e0 =====

void KeyboardClassSetWmiDataItem
               (longlong param_1,undefined8 param_2,int param_3,int param_4,int param_5,int param_6,
               undefined1 *param_7)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (param_3 == 0) {
    uVar1 = 0xc00002c6;
  }
  else if (param_3 == 1) {
    uVar3 = 1;
    if (param_6 == 0) {
      uVar1 = 0xc0000023;
    }
    else if ((param_5 == 1) && (param_4 == 0)) {
      uVar2 = KeyboardToggleWaitWake(*(undefined8 **)(param_1 + 0x40),*param_7);
      uVar1 = (undefined4)uVar2;
    }
    else {
      uVar1 = 0xc0000010;
    }
  }
  else {
    uVar1 = 0xc0000295;
  }
  WmiCompleteRequest(param_1,param_2,uVar1,uVar3,0);
  return;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 1c000ea78 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(void)

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
  local_28 = *(undefined4 *)(PTR_DAT_1c000b008 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_1c000b008 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_1c000b008 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_1c000b008 + -4);
  if (DAT_1c000b020 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  _DAT_1c000b028 = 0;
  uRam00000001c000b030 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x1c000eadb;
  iVar3 = EtwRegister(puVar4 + 0x20,_tlgEnableCallback,&DAT_1c000b000,&DAT_1c000b020);
  if (iVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_1c000b008;
    *(undefined8 *)(puVar4 + -8) = 0x1c000eb02;
    EtwSetInformation(DAT_1c000b020,2,PTR_DAT_1c000b008,uVar1);
  }
  *(undefined8 *)(puVar4 + -8) = 0x1c000eb16;
  return iVar3;
}



===== WppCleanupKm @ 1c000eb24 =====

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



===== WppInitKm @ 1c000ebd4 =====

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



===== WppTraceCallback @ 1c000ecb0 =====

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



===== KeyboardClassDeviceControl @ 1c000ef40 =====

int KeyboardClassDeviceControl(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  int iVar10;
  uint *puVar11;
  ulonglong uVar12;
  longlong *plVar13;
  undefined8 uVar14;
  uint uVar15;
  ulonglong uVar16;
  uint local_res8;
  undefined4 uVar17;
  undefined4 in_stack_ffffffffffffffac;
  undefined1 uVar18;
  undefined1 uVar19;
  
  bVar9 = false;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x14);
  }
  plVar13 = *(longlong **)(param_1 + 0x40);
  lVar5 = *(longlong *)(param_2 + 0xb8);
  uVar17 = 0x20;
  plVar1 = plVar13 + 4;
  iVar10 = IoAcquireRemoveLockEx(plVar1,param_2,"",1);
  if (iVar10 < 0) {
    *(int *)(param_2 + 0x30) = iVar10;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    return iVar10;
  }
  uVar18 = (undefined1)param_1;
  uVar19 = (undefined1)param_2;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x15,
                        CONCAT44(in_stack_ffffffffffffffac,uVar17),uVar18,uVar19,
                        (char)*(undefined4 *)(lVar5 + 0x18));
  }
  uVar4 = *(uint *)(lVar5 + 0x18);
  if (uVar4 == 0xb0268) {
switchD_1c000f3ff_caseD_b0191:
    if (((char)plVar13[8] != '\0') && (plVar13 != Globals)) {
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
LAB_1c000f012:
      iVar10 = IofCallDriver(plVar13[2],param_2);
      goto LAB_1c000f024;
    }
switchD_1c000f0cf_caseD_b0001:
    iVar10 = -0x3ffffff0;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqdL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
  }
  else {
    if (uVar4 < 0xb0191) {
      if (uVar4 == 0xb0190) goto switchD_1c000f3ff_caseD_b0191;
      switch(uVar4) {
      case 0xb0000:
      case 0xb0020:
      case 0xb0040:
      case 0xb0080:
        goto switchD_1c000f0cf_caseD_b0000;
      default:
        goto switchD_1c000f0cf_caseD_b0001;
      case 0xb0004:
        break;
      case 0xb0008:
        if (*(uint *)(lVar5 + 0x10) < 4) {
          iVar10 = -0x3fffffdd;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qqLd
                      (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,&WPP_RECORDER_INITIALIZED,0x16,
                       CONCAT44(in_stack_ffffffffffffffac,uVar17),uVar18,uVar19,8,0x23);
          }
          goto LAB_1c000f23c;
        }
        *(undefined4 *)((longlong)plVar13 + 0x9c) = **(undefined4 **)(param_2 + 0x18);
      }
      if (DAT_1c000b1fc != 0) {
        bVar9 = true;
      }
    }
    else if (uVar4 < 0xb1001) {
      if (uVar4 != 0xb1000) {
        switch(uVar4) {
        case 0xb0191:
        case 0xb0192:
        case 0xb0193:
        case 0xb0194:
        case 0xb0197:
        case 0xb0198:
        case 0xb019a:
        case 0xb019c:
        case 0xb019e:
        case 0xb01a0:
        case 0xb01a4:
        case 0xb01a8:
        case 0xb01ba:
        case 0xb01be:
        case 0xb01c2:
        case 0xb01e2:
          goto switchD_1c000f3ff_caseD_b0191;
        default:
          goto switchD_1c000f0cf_caseD_b0001;
        case 0xb0200:
          break;
        }
      }
    }
    else if (uVar4 != 0xb1004) {
      if ((uVar4 == 0x294140) || (uVar4 == 0x294144)) goto switchD_1c000f3ff_caseD_b0191;
      goto switchD_1c000f0cf_caseD_b0001;
    }
switchD_1c000f0cf_caseD_b0000:
    uVar16 = 0;
    if (*(uint *)(lVar5 + 0x10) == 0) {
      local_res8 = 0;
    }
    else {
      if (*(uint *)(lVar5 + 0x10) < 2) {
        iVar10 = -0x3fffffdd;
        goto LAB_1c000f23c;
      }
      local_res8 = (uint)**(ushort **)(param_2 + 0x18);
    }
    if (*plVar13 == plVar13[1]) {
      if (plVar13 != Globals) {
        bVar9 = false;
LAB_1c000f13b:
        puVar6 = *(undefined8 **)(param_2 + 0xb8);
        puVar6[-9] = *puVar6;
        puVar6[-8] = puVar6[1];
        puVar6[-7] = puVar6[2];
        puVar6[-6] = puVar6[3];
        *(undefined4 *)(puVar6 + -5) = *(undefined4 *)(puVar6 + 4);
        *(undefined4 *)((longlong)puVar6 + -0x24) = *(undefined4 *)((longlong)puVar6 + 0x24);
        *(undefined4 *)(puVar6 + -4) = *(undefined4 *)(puVar6 + 5);
        *(undefined4 *)((longlong)puVar6 + -0x1c) = *(undefined4 *)((longlong)puVar6 + 0x2c);
        puVar6[-3] = puVar6[6];
        *(undefined1 *)((longlong)puVar6 + -0x45) = 0;
        *(undefined1 *)(*(longlong *)(param_2 + 0xb8) + -0x48) = 0xf;
        if (bVar9) {
          uVar17 = 0x20;
          iVar10 = IoAcquireRemoveLockEx(plVar1,param_2,"",1);
          if ((iVar10 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
          {
            WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,4,0x17,
                                CONCAT44(in_stack_ffffffffffffffac,uVar17),uVar18,uVar19,
                                (char)iVar10);
          }
          ExAcquireFastMutex(&DAT_1c000b1c0);
          puVar11 = (uint *)ExAllocatePool2(0x40,(ulonglong)DAT_1c000b1b0 * 0x18 + 8,0x4364624b);
          if (puVar11 == (uint *)0x0) {
            iVar10 = -0x3fffff66;
            *(undefined8 *)(param_2 + 0x38) = 0;
            *(undefined4 *)(param_2 + 0x30) = 0xc000009a;
            IofCompleteRequest(param_2,0);
          }
          else {
            *puVar11 = DAT_1c000b1b0;
            puVar11[1] = 0;
            if (DAT_1c000b1b0 != 0) {
              do {
                lVar5 = DAT_1c000b1a8;
                puVar2 = (uint *)(DAT_1c000b1a8 + uVar16 * 0x18);
                uVar15 = puVar2[1];
                uVar7 = puVar2[2];
                uVar8 = puVar2[3];
                puVar3 = puVar11 + uVar16 * 6 + 2;
                *puVar3 = *puVar2;
                puVar3[1] = uVar15;
                puVar3[2] = uVar7;
                puVar3[3] = uVar8;
                *(undefined8 *)(puVar11 + uVar16 * 6 + 6) =
                     *(undefined8 *)(lVar5 + 0x10 + uVar16 * 0x18);
                if (((char)puVar11[uVar16 * 6 + 6] != '\0') &&
                   (*(char *)((longlong)puVar11 + uVar16 * 0x18 + 0x1b) == '\0')) {
                  uVar17 = 0x20;
                  iVar10 = IoAcquireRemoveLockEx
                                     (*(longlong *)(puVar11 + uVar16 * 6 + 4) + 0x20,param_2,"",1);
                  if ((iVar10 < 0) &&
                     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
                    WPP_RECORDER_SF_qqdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
                  }
                }
                uVar15 = (int)uVar16 + 1;
                uVar16 = (ulonglong)uVar15;
              } while (uVar15 < DAT_1c000b1b0);
            }
            iVar10 = KeyboardCallAllPorts(param_1,param_2,puVar11);
          }
          ExReleaseFastMutex(&DAT_1c000b1c0);
          goto LAB_1c000f024;
        }
        goto LAB_1c000f012;
      }
      ExAcquireFastMutex(&DAT_1c000b1c0);
      uVar12 = (ulonglong)local_res8;
      if (local_res8 < DAT_1c000b1b0) {
        if (DAT_1c000b1b0 == 0) {
LAB_1c000f44f:
          if ((uint)uVar12 < DAT_1c000b1b0) {
            plVar13 = *(longlong **)(DAT_1c000b1a8 + 8 + uVar12 * 0x18);
            *(undefined8 *)(lVar5 + 0x30) = *(undefined8 *)(DAT_1c000b1a8 + uVar12 * 0x18);
            ExReleaseFastMutex(&DAT_1c000b1c0);
            goto LAB_1c000f13b;
          }
        }
        else {
          if ((*(char *)(DAT_1c000b1a8 + 0x10 + uVar12 * 0x18) == '\0') ||
             (*(char *)(DAT_1c000b1a8 + 0x13 + uVar12 * 0x18) != '\0')) {
            uVar12 = 0;
          }
          uVar15 = (uint)uVar12;
          while (uVar15 < DAT_1c000b1b0) {
            if ((*(char *)(DAT_1c000b1a8 + 0x10 + uVar12 * 0x18) != '\0') &&
               (*(char *)(DAT_1c000b1a8 + 0x13 + uVar12 * 0x18) == '\0')) goto LAB_1c000f44f;
            uVar15 = (int)uVar12 + 1;
            uVar12 = (ulonglong)uVar15;
          }
        }
      }
      ExReleaseFastMutex(&DAT_1c000b1c0);
      iVar10 = -0x3ffffff3;
    }
    else {
      iVar10 = -0x3fffff45;
    }
  }
LAB_1c000f23c:
  *(int *)(param_2 + 0x30) = iVar10;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
LAB_1c000f024:
  uVar14 = 0x20;
  IoReleaseRemoveLockEx(plVar1,param_2);
  if ((((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
      (WPP_RECORDER_SF_qqLd
                 (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,uVar14,0x1a,
                  CONCAT44(in_stack_ffffffffffffffac,uVar17),uVar18,uVar19,(char)uVar4,(char)iVar10)
      , (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x1b);
  }
  return iVar10;
}



===== KbdEnableDisablePort @ 1c000f5e0 =====

int KbdEnableDisablePort(char param_1,longlong param_2,longlong *param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  int iVar5;
  longlong lVar6;
  undefined4 local_res18 [4];
  undefined8 local_58;
  undefined8 local_50;
  longlong local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  local_50 = 0;
  iVar5 = 0;
  local_48 = 0;
  local_58 = 0;
  local_res18[0] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x51);
  }
  if (param_3[1] == *param_3) {
    if ((char)param_3[8] != '\0') {
      puVar1 = *(undefined8 **)(param_2 + 0xb8);
      puVar1[-9] = *puVar1;
      puVar1[-8] = puVar1[1];
      puVar1[-7] = puVar1[2];
      puVar1[-6] = puVar1[3];
      puVar1[-5] = puVar1[4];
      puVar1[-4] = puVar1[5];
      puVar1[-3] = puVar1[6];
      *(undefined1 *)((longlong)puVar1 + -0x45) = 0;
      if ((param_1 == '\0') && (*(char *)(*(longlong *)(param_2 + 0xb8) + -0x48) != '\x02')) {
        *(undefined1 *)(*(longlong *)(param_2 + 0xb8) + -0x48) = 2;
      }
      lVar6 = param_3[2];
      local_30 = 0;
      local_40 = 0;
      uStack_38 = 0;
      KeInitializeEvent(&local_40,1,0);
      lVar2 = *(longlong *)(param_2 + 0xb8);
      *(code **)(lVar2 + -0x10) = KbdSyncComplete;
      *(undefined8 **)(lVar2 + -8) = &local_40;
      *(undefined1 *)(lVar2 + -0x45) = 0xe0;
      IofCallDriver(lVar6,param_2);
      KeWaitForSingleObject(&local_40,0,0,0,0);
      iVar5 = *(int *)(param_2 + 0x30);
      goto LAB_1c000f702;
    }
  }
  else if ((char)param_3[8] != '\0') {
    if (param_1 == '\0') {
      ObfDereferenceObject(*param_4);
      *param_4 = 0;
    }
    else {
      IoGetDeviceProperty(param_3[3],0xb,0,0,local_res18);
      lVar6 = ExAllocatePool2(0x100,local_res18[0],0x4364624b);
      if (lVar6 == 0) {
        return -0x3fffff66;
      }
      IoGetDeviceProperty(param_3[3],0xb,local_res18[0],lVar6,local_res18);
      local_50 = CONCAT62(CONCAT42(local_50._4_4_,(short)local_res18[0]),(short)local_res18[0] + -2)
      ;
      local_48 = lVar6;
      iVar5 = IoGetDeviceObjectPointer(&local_50,0x1f01ff,param_4,&local_58);
      ExFreePoolWithTag(lVar6,0);
      if (-1 < iVar5) {
        if (param_2 != 0) {
          puVar1 = *(undefined8 **)(param_2 + 0xb8);
          puVar1[-9] = *puVar1;
          puVar1[-8] = puVar1[1];
          puVar1[-7] = puVar1[2];
          puVar1[-6] = puVar1[3];
          puVar1[-5] = puVar1[4];
          puVar1[-4] = puVar1[5];
          puVar1[-3] = puVar1[6];
          *(undefined1 *)((longlong)puVar1 + -0x45) = 0;
          lVar6 = *(longlong *)(param_2 + 0xb8);
          *(undefined1 *)(lVar6 + -0x48) = 0xf;
          *(undefined4 *)(lVar6 + -0x40) = 0;
          *(undefined4 *)(lVar6 + -0x38) = 4;
          *(undefined4 *)(lVar6 + -0x30) = 0xb0008;
          *(undefined8 *)(lVar6 + -0x18) = *param_4;
          uVar3 = *(undefined8 *)(param_2 + 0x18);
          *(longlong *)(param_2 + 0x18) = Globals + 0x9c;
          KeyboardSendIrpSynchronously(param_3[2],param_2,'\0');
          *(undefined8 *)(param_2 + 0x18) = uVar3;
        }
        iVar5 = IoRegisterPlugPlayNotification
                          (3,0,*param_4,*(undefined8 *)(*param_3 + 8),
                           KeyboardClassPlugPlayNotification,param_3,param_3 + 0x29);
      }
    }
    goto LAB_1c000f702;
  }
  *(char *)(param_3 + 0x2d) = param_1;
  puVar1 = *(undefined8 **)(param_2 + 0xb8);
  puVar1[-9] = *puVar1;
  puVar1[-8] = puVar1[1];
  puVar1[-7] = puVar1[2];
  puVar1[-6] = puVar1[3];
  puVar1[-5] = puVar1[4];
  puVar1[-4] = puVar1[5];
  puVar1[-3] = puVar1[6];
  *(undefined1 *)((longlong)puVar1 + -0x45) = 0;
  lVar6 = *(longlong *)(param_2 + 0xb8);
  uVar4 = 0xb0803;
  if (param_1 == '\0') {
    uVar4 = 0xb1003;
  }
  *(undefined4 *)(lVar6 + -0x40) = 0;
  *(undefined4 *)(lVar6 + -0x38) = 0;
  *(undefined4 *)(lVar6 + -0x30) = uVar4;
  *(undefined8 *)(lVar6 + -0x28) = 0;
  *(undefined1 *)(lVar6 + -0x48) = 0xf;
  iVar5 = KeyboardSendIrpSynchronously(param_3[2],param_2,'\0');
LAB_1c000f702:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x52);
  }
  return iVar5;
}



===== KeyboardSendIrpSynchronously @ 1c000f9c0 =====

undefined4 KeyboardSendIrpSynchronously(undefined8 param_1,longlong param_2,char param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeInitializeEvent(&local_28,1,0);
  if (param_3 != '\0') {
    puVar2 = *(undefined8 **)(param_2 + 0xb8);
    puVar2[-9] = *puVar2;
    puVar2[-8] = puVar2[1];
    puVar2[-7] = puVar2[2];
    puVar2[-6] = puVar2[3];
    *(undefined4 *)(puVar2 + -5) = *(undefined4 *)(puVar2 + 4);
    *(undefined4 *)((longlong)puVar2 + -0x24) = *(undefined4 *)((longlong)puVar2 + 0x24);
    *(undefined4 *)(puVar2 + -4) = *(undefined4 *)(puVar2 + 5);
    *(undefined4 *)((longlong)puVar2 + -0x1c) = *(undefined4 *)((longlong)puVar2 + 0x2c);
    puVar2[-3] = puVar2[6];
    *(undefined1 *)((longlong)puVar2 + -0x45) = 0;
  }
  lVar1 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar1 + -0x10) = KbdSyncComplete;
  *(undefined8 **)(lVar1 + -8) = &local_28;
  *(undefined1 *)(lVar1 + -0x45) = 0xe0;
  IofCallDriver(param_1,param_2);
  KeWaitForSingleObject(&local_28,0,0,0,0);
  return *(undefined4 *)(param_2 + 0x30);
}



===== KeyboardClassPassThrough @ 1c000fab0 =====

void KeyboardClassPassThrough(longlong param_1,longlong param_2)

{
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  IofCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x10));
  return;
}



===== KeyboardAddDevice @ 1c000fae0 =====

ulonglong KeyboardAddDevice(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  wchar_t *pwVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  int local_res18 [2];
  longlong local_res20;
  undefined8 *puVar9;
  undefined8 local_28;
  wchar_t *local_20;
  
  local_res20 = 0;
  local_20 = (wchar_t *)0x0;
  local_28 = 0;
  local_res18[0] = 0;
  uVar5 = KbdCreateClassObject(param_1,(longlong *)&DAT_1c000b208,&local_res20,&local_20,'\0');
  if (-1 < (int)uVar5) {
    plVar1 = *(longlong **)(local_res20 + 0x40);
    lVar6 = IoAttachDeviceToDeviceStack(local_res20,param_2);
    plVar1[2] = lVar6;
    if (lVar6 == 0) {
      puVar7 = (undefined4 *)IoAllocateErrorLogEntry(param_1,0x30);
      if (puVar7 != (undefined4 *)0x0) {
        puVar7[3] = 0xc005000f;
        *puVar7 = 0;
        *(undefined8 *)(puVar7 + 6) = 0;
        puVar7[4] = 0;
        puVar7[5] = 0xc000009d;
        IoWriteErrorLogEntry(puVar7);
      }
      IoDeleteDevice(local_res20);
      return 0xc000009d;
    }
    plVar1[3] = param_2;
    *(undefined2 *)(plVar1 + 8) = 1;
    *(undefined4 *)((longlong)plVar1 + 0xbc) = 1;
    *(undefined4 *)(plVar1 + 0x18) = 1;
    PoSetPowerState(local_res20,1,1);
    puVar9 = &local_28;
    *(undefined8 *)((longlong)plVar1 + 0x11c) = 0;
    uVar4 = 0;
    *(undefined1 *)((longlong)plVar1 + 0x16a) = 0;
    uVar8 = 0x20019;
    plVar1[0x25] = 0;
    *(undefined1 *)(plVar1 + 0x26) = 0;
    plVar1[0x27] = 0;
    *(undefined4 *)(plVar1 + 0x28) = 0;
    *(undefined1 *)((longlong)plVar1 + 0x42) = 0;
    plVar1[0x2e] = 0;
    *(undefined4 *)(plVar1 + 0x2f) = 0;
    iVar3 = IoOpenDriverRegistryKey(param_1,0);
    if (iVar3 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,uVar8,0xf,puVar9,(char)iVar3)
        ;
      }
    }
    else {
      iVar3 = KeyboardQueryDeviceKey(local_28,L"AllowDisable",local_res18,uVar4);
      if (-1 < iVar3) {
        *(bool *)((longlong)plVar1 + 0x42) = local_res18[0] != 0;
      }
      ZwClose(local_28);
    }
    *(uint *)(local_res20 + 0x30) = *(uint *)(local_res20 + 0x30) | 0x2000;
    *(uint *)(local_res20 + 0x30) = *(uint *)(local_res20 + 0x30) & 0xffffff7f;
    uVar4 = IoRegisterDeviceInterface(param_2,&GUID_DEVINTERFACE_KEYBOARD,0,plVar1 + 0xb);
    pwVar2 = local_20;
    uVar5 = (ulonglong)uVar4;
    if ((int)uVar4 < 0) {
      IoDetachDevice(plVar1[2]);
      plVar1[2] = 0;
      IoDeleteDevice(local_res20);
    }
    else {
      uVar5 = KeyboardAddDeviceEx(plVar1,local_20,0);
      uVar5 = uVar5 & 0xffffffff;
    }
    if (pwVar2 != (wchar_t *)0x0) {
      ExFreePoolWithTag(pwVar2,0);
    }
  }
  return uVar5;
}



===== KbdCreateClassObject @ 1c000fd50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong KbdCreateClassObject
                    (longlong param_1,longlong *param_2,longlong *param_3,undefined8 *param_4,
                    char param_5)

{
  uint *puVar1;
  undefined4 uVar2;
  longlong lVar3;
  short sVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong *plVar7;
  longlong lVar8;
  wchar_t *pwVar9;
  longlong *plVar10;
  ulonglong uVar11;
  undefined2 *puVar12;
  undefined8 uVar13;
  uint uVar14;
  undefined4 uVar15;
  int iVar16;
  undefined1 auStackY_b8 [32];
  undefined4 in_stack_ffffffffffffff68;
  undefined4 uVar17;
  undefined4 in_stack_ffffffffffffff6c;
  undefined8 local_78;
  wchar_t *local_70;
  undefined8 *local_68;
  longlong local_60;
  uint local_58 [4];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_b8;
  plVar10 = (longlong *)0x0;
  local_78 = 0;
  iVar16 = 0;
  local_70 = (wchar_t *)0x0;
  uVar14 = 0;
  uVar15 = 10000;
  local_68 = param_4;
  local_60 = param_1;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x48);
  }
  ExAcquireFastMutex(&DAT_1c000b1c0);
  *param_3 = 0;
  if (Globals == 0) {
    ExReleaseFastMutex();
    sVar4 = DAT_1c000b398 + 0x1e;
    local_78._0_4_ = CONCAT22(sVar4,(ushort)local_78);
    if ((DAT_1c000b1f8 != 0) && (param_5 != '\0')) {
      sVar4 = DAT_1c000b398 + 0x2c;
      local_78._0_4_ = CONCAT22(sVar4,(ushort)local_78);
    }
    local_70 = (wchar_t *)ExAllocatePool2(0x100,sVar4,0x4364624b);
    if (local_70 == (wchar_t *)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x49);
      }
      uVar11 = 0xc0000001;
      iVar16 = -0x3ffaffff;
LAB_1c000fe87:
      local_58[0] = (uint)local_78._2_2_;
      uVar15 = 0x2716;
      uVar14 = 1;
      RtlFreeUnicodeString(&local_78);
      *local_68 = 0;
LAB_1c0010215:
      lVar8 = *param_3;
      if (*param_3 == 0) {
        lVar8 = local_60;
      }
      KeyboardClassLogError(lVar8,iVar16,uVar15,(int)uVar11,uVar14,local_58,0);
      goto LAB_1c0010241;
    }
    do {
      if ((DAT_1c000b1f8 == 0) || (pwVar9 = L"\\Device\\%wZLegacy%d", param_5 == '\0')) {
        pwVar9 = L"\\Device\\%wZ%d";
      }
      uVar6 = (ulonglong)DAT_1c000b11c;
      puVar12 = &DAT_1c000b398;
      DAT_1c000b11c = DAT_1c000b11c + 1;
      uVar6 = RtlUnicodeStringPrintf((ushort *)&local_78,pwVar9,&DAT_1c000b398,uVar6);
      uVar11 = uVar6 & 0xffffffff;
      if ((int)uVar6 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar12,0x4a,
                            CONCAT44(in_stack_ffffffffffffff6c,in_stack_ffffffffffffff68),local_70);
        }
        iVar16 = -0x3ffafff3;
        goto LAB_1c000fe87;
      }
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,puVar12,0x4b,
                          CONCAT44(in_stack_ffffffffffffff6c,in_stack_ffffffffffffff68),local_70);
      }
      in_stack_ffffffffffffff68 = 0;
      uVar5 = IoCreateDevice(local_60,0x180,&local_78,0xb);
    } while (uVar5 == 0xc0000035);
    if ((local_78 & 0xffff) + 2 <= (local_78 >> 0x10 & 0xffff)) {
      uVar6 = local_78 >> 1 & 0x7fff;
      local_70[uVar6 + 1] = L'\0';
      *local_68 = local_70;
      goto LAB_1c001004d;
    }
    uVar11 = 0xc0000001;
    RtlFreeUnicodeString(&local_78);
    *local_68 = 0;
  }
  else {
    ExReleaseFastMutex(&DAT_1c000b1c0);
    uVar6 = 0;
    in_stack_ffffffffffffff68 = 0;
    uVar5 = IoCreateDevice(param_1,0x180,0,0xb);
    *local_68 = 0;
LAB_1c001004d:
    uVar11 = (ulonglong)uVar5;
    if (((int)uVar5 < 0) || (*param_3 == 0)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar6,0x4c,
                          CONCAT44(in_stack_ffffffffffffff6c,in_stack_ffffffffffffff68),local_70);
      }
      iVar16 = -0x3ffafff3;
      local_58[0] = (uint)local_78._2_2_;
      uVar15 = 0x2716;
      uVar14 = 1;
    }
    else {
      puVar1 = (uint *)(*param_3 + 0x30);
      *puVar1 = *puVar1 | 4;
      lVar8 = 3;
      plVar10 = *(longlong **)(*param_3 + 0x40);
      plVar7 = plVar10;
      do {
        lVar3 = param_2[1];
        *plVar7 = *param_2;
        plVar7[1] = lVar3;
        lVar3 = param_2[3];
        plVar7[2] = param_2[2];
        plVar7[3] = lVar3;
        lVar3 = param_2[5];
        plVar7[4] = param_2[4];
        plVar7[5] = lVar3;
        lVar3 = param_2[7];
        plVar7[6] = param_2[6];
        plVar7[7] = lVar3;
        lVar3 = param_2[9];
        plVar7[8] = param_2[8];
        plVar7[9] = lVar3;
        lVar3 = param_2[0xb];
        plVar7[10] = param_2[10];
        plVar7[0xb] = lVar3;
        uVar17 = *(undefined4 *)((longlong)param_2 + 100);
        lVar3 = param_2[0xd];
        uVar2 = *(undefined4 *)((longlong)param_2 + 0x6c);
        *(int *)(plVar7 + 0xc) = (int)param_2[0xc];
        *(undefined4 *)((longlong)plVar7 + 100) = uVar17;
        *(int *)(plVar7 + 0xd) = (int)lVar3;
        *(undefined4 *)((longlong)plVar7 + 0x6c) = uVar2;
        uVar17 = *(undefined4 *)((longlong)param_2 + 0x74);
        lVar3 = param_2[0xf];
        uVar2 = *(undefined4 *)((longlong)param_2 + 0x7c);
        *(int *)(plVar7 + 0xe) = (int)param_2[0xe];
        *(undefined4 *)((longlong)plVar7 + 0x74) = uVar17;
        *(int *)(plVar7 + 0xf) = (int)lVar3;
        *(undefined4 *)((longlong)plVar7 + 0x7c) = uVar2;
        lVar8 = lVar8 + -1;
        plVar7 = plVar7 + 0x10;
        param_2 = param_2 + 0x10;
      } while (lVar8 != 0);
      *plVar10 = *param_3;
      uVar17 = 0x20;
      IoInitializeRemoveLockEx(plVar10 + 4,0x4364624b,0,0);
      KeInitializeSpinLock(plVar10 + 0x14);
      plVar7 = plVar10 + 0x15;
      plVar10[0x16] = (longlong)plVar7;
      uVar13 = 0x4364624b;
      *plVar7 = (longlong)plVar7;
      *(undefined4 *)(plVar10 + 10) = 0;
      lVar8 = ExAllocatePool2(0x40,*(undefined4 *)((longlong)plVar10 + 0x8c));
      plVar10[0xd] = lVar8;
      if (lVar8 == 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar13,0x4d,
                            CONCAT44(in_stack_ffffffffffffff6c,uVar17),(wchar_t *)*local_68);
        }
        uVar11 = 0xc000009a;
        iVar16 = -0x3ffafffe;
        uVar15 = 0x2724;
        RtlFreeUnicodeString(&local_78);
        *local_68 = 0;
        goto LAB_1c0010215;
      }
      KbdInitializeDataQueue((longlong)plVar10);
      uVar14 = 0;
    }
    if (uVar5 == 0) goto LAB_1c0010278;
    RtlFreeUnicodeString(&local_78);
    *local_68 = 0;
    if (iVar16 != 0) goto LAB_1c0010215;
LAB_1c0010241:
    if ((plVar10 != (longlong *)0x0) && (plVar10[0xd] != 0)) {
      ExFreePoolWithTag(plVar10[0xd],0);
      plVar10[0xd] = 0;
    }
  }
  if (*param_3 != 0) {
    IoDeleteDevice();
    *param_3 = 0;
  }
LAB_1c0010278:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x4e);
  }
  return uVar11;
}



===== KeyboardClassGetWaitWakeEnableState @ 1c00102e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong KeyboardClassGetWaitWakeEnableState(longlong param_1)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined1 auStack_1c8 [32];
  undefined4 local_1a8;
  undefined8 local_198;
  int local_190 [2];
  undefined1 local_188 [3];
  char local_185;
  char local_184;
  char local_183;
  undefined4 local_138 [70];
  undefined1 local_1e;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_1c8;
  uVar4 = (uint)&local_198;
  local_198 = 0;
  local_190[0] = 0;
  uVar2 = IoOpenDeviceRegistryKey(*(undefined8 *)(param_1 + 0x18),1,0x1f0000);
  if (-1 < (int)uVar2) {
    iVar1 = KeyboardQueryDeviceKey(local_198,L"WaitWakeEnabled",local_190,uVar4);
    if (-1 < iVar1) {
      *(bool *)(param_1 + 0x16a) = local_190[0] != 0;
      uVar2 = ZwClose(local_198);
      return uVar2;
    }
    uVar2 = ZwClose();
    local_198 = 0;
  }
  if (*(char *)(param_1 + 0x16a) == '\0') {
    memset(local_138,0,0x11c);
    local_138[0] = 0x11c;
    local_1e = 1;
    uVar3 = VerSetConditionMask(0,0x80,1);
    uVar2 = RtlVerifyVersionInfo(local_138,0x80,uVar3);
    if (-1 < (int)uVar2) {
      memset(local_188,0,0x4c);
      uVar4 = 4;
      local_1a8 = 0x4c;
      uVar2 = ZwPowerInformation(4,0,0,local_188);
      if (-1 < (int)uVar2) {
        if (local_183 == '\0') {
          if (local_184 == '\0') {
            uVar2 = (ulonglong)(byte)-local_185;
            uVar4 = -(uint)(local_185 != '\0') & 2;
          }
          else {
            uVar4 = 3;
          }
        }
        if ((int)uVar4 <= *(int *)(param_1 + 0x120)) {
          *(undefined1 *)(param_1 + 0x16a) = 1;
        }
      }
    }
  }
  return uVar2;
}



===== KeyboardQueryDeviceKey @ 1c0010480 =====

int KeyboardQueryDeviceKey(undefined8 param_1,undefined8 param_2,void *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  uint local_res20 [2];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  local_res20[0] = param_4;
  RtlInitUnicodeString(&local_18);
  uVar1 = local_18._2_2_ + 0x18;
  if ((uVar1 < 0x18) || (local_res20[0] = local_18._2_2_ + 0x1c, local_res20[0] < uVar1)) {
    return -0x3fffff6b;
  }
  lVar3 = ExAllocatePool2(0x100,local_res20[0],0x4364624b);
  if (lVar3 == 0) {
    return -0x3fffffe9;
  }
  iVar2 = ZwQueryValueKey(param_1,&local_18,1,lVar3,local_res20[0],local_res20);
  if (-1 < iVar2) {
    if (*(uint *)(lVar3 + 0xc) < 5) {
      memcpy(param_3,(void *)((ulonglong)*(uint *)(lVar3 + 8) + lVar3),
             (ulonglong)*(uint *)(lVar3 + 0xc));
    }
    else {
      iVar2 = -0x3fffffdd;
    }
  }
  ExFreePoolWithTag(lVar3,0);
  return iVar2;
}



===== KeyboardAddDeviceEx @ 1c00105b0 =====

ulonglong KeyboardAddDeviceEx(longlong *param_1,wchar_t *param_2,undefined8 param_3)

{
  char cVar1;
  uint uVar2;
  ulonglong uVar3;
  void *_Dst;
  char cVar4;
  longlong *plVar5;
  wchar_t *pwVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  
  uVar3 = 0;
  KeInitializeSpinLock(param_1 + 9);
  plVar5 = Globals;
  if (DAT_1c000b1f8 != 0) {
    plVar5 = param_1;
  }
  param_1[1] = *plVar5;
  if (Globals != param_1) {
    if (Globals != plVar5) {
      if (param_1 != plVar5) {
        return 0;
      }
      KbdSendConnectRequest((longlong)param_1);
      goto LAB_1c001074e;
    }
    uVar3 = KbdSendConnectRequest((longlong)param_1);
    uVar3 = uVar3 & 0xffffffff;
    ExAcquireFastMutex(&DAT_1c000b1c0);
    uVar7 = 0;
    while (uVar2 = (uint)uVar7, uVar2 < DAT_1c000b1b0) {
      if (*(char *)((longlong)DAT_1c000b1a8 + uVar7 * 0x18 + 0x13) != '\0') {
        *(undefined1 *)((longlong)DAT_1c000b1a8 + uVar7 * 0x18 + 0x13) = 0;
        break;
      }
      uVar7 = (ulonglong)(uVar2 + 1);
    }
    if (uVar2 == DAT_1c000b1b0) {
      _Dst = (void *)ExAllocatePool2(0x40,(ulonglong)(DAT_1c000b1b0 + 1) * 0x18,0x4364624b);
      if (_Dst == (void *)0x0) {
        ExReleaseFastMutex(&DAT_1c000b1c0);
        return 0xc000009a;
      }
      if (DAT_1c000b1b0 != 0) {
        memcpy(_Dst,DAT_1c000b1a8,(ulonglong)DAT_1c000b1b0 * 0x18);
        ExFreePoolWithTag(DAT_1c000b1a8,0);
      }
      DAT_1c000b1b0 = DAT_1c000b1b0 + 1;
      DAT_1c000b1a8 = _Dst;
    }
    *(uint *)((longlong)param_1 + 0xc4) = uVar2;
    *(longlong **)(uVar7 * 0x18 + 8 + (longlong)DAT_1c000b1a8) = param_1;
    *(undefined8 *)(uVar7 * 0x18 + (longlong)DAT_1c000b1a8) = param_3;
    cVar1 = *(char *)(*plVar5 + 0x4c);
    cVar4 = *(char *)(*param_1 + 0x4c);
    if (*(char *)(*param_1 + 0x4c) <= cVar1) {
      cVar4 = cVar1;
    }
    *(char *)(*plVar5 + 0x4c) = cVar4;
    ExReleaseFastMutex(&DAT_1c000b1c0);
  }
  if (param_1 != plVar5) {
    return uVar3;
  }
LAB_1c001074e:
  pwVar6 = param_2;
  uVar8 = DAT_1c000b390;
  uVar2 = RtlWriteRegistryValue(4,DAT_1c000b3a0);
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,pwVar6,0x10,uVar8,param_2);
    }
    KeyboardClassLogError(param_1,0x80050005,0x271e,uVar2,0,(undefined4 *)0x0,0);
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,pwVar6,0x11,uVar8,param_2);
  }
  return (ulonglong)uVar2;
}



===== KbdSendConnectRequest @ 1c0010850 =====

ulonglong KbdSendConnectRequest(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong local_48 [3];
  code *local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_48[0] = 0;
  local_48[1] = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x55);
  }
  KeInitializeEvent(&local_28,0,0);
  local_48[2] = *(undefined8 *)(param_1 + 8);
  local_30 = KeyboardClassServiceCallback;
  lVar1 = IoBuildDeviceIoControlRequest
                    (0xb0203,*(undefined8 *)(param_1 + 0x10),local_48 + 2,0x10,0,0,1,&local_28,
                     local_48);
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    uVar2 = IofCallDriver(*(undefined8 *)(param_1 + 0x10),lVar1);
    if ((int)uVar2 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      uVar2 = local_48[0] & 0xffffffff;
      goto LAB_1c0010968;
    }
  }
  local_48[0] = CONCAT44(local_48[0]._4_4_,(int)uVar2);
LAB_1c0010968:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x56);
    uVar2 = local_48[0] & 0xffffffff;
  }
  return uVar2;
}



===== _tlgEnableCallback @ 1c00109c0 =====

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



===== KeyboardClassSystemControl @ 1c0010a50 =====

int KeyboardClassSystemControl(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  int local_res8 [2];
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_res8[0] = 0;
  iVar2 = IoAcquireRemoveLockEx(lVar1 + 0x20,param_2,"",1,0x20);
  if (iVar2 < 0) {
    *(int *)(param_2 + 0x30) = iVar2;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
  }
  else {
    iVar2 = WmiSystemControl(lVar1 + 200,param_1,param_2,local_res8);
    if (local_res8[0] != 0) {
      if (local_res8[0] == 1) {
        IofCompleteRequest(param_2,0);
      }
      else {
        iVar2 = KeyboardClassPassThrough(param_1,param_2);
      }
    }
    IoReleaseRemoveLockEx(lVar1 + 0x20,param_2,0x20);
  }
  return iVar2;
}



===== KeyboardClassCreateWaitWakeIrpWorker @ 1c0010b50 =====

void KeyboardClassCreateWaitWakeIrpWorker(undefined8 param_1,longlong param_2)

{
  KeyboardClassCreateWaitWakeIrp(*(longlong *)(param_2 + 8));
  IoReleaseRemoveLockEx(*(longlong *)(param_2 + 8) + 0x20,param_2,0x20);
  IoFreeWorkItem(*(undefined8 *)(param_2 + 0x10));
  ExFreePoolWithTag(param_2,0);
  return;
}



===== KeyboardClassCreateWaitWakeIrp @ 1c0010bb0 =====

bool KeyboardClassCreateWaitWakeIrp(longlong param_1)

{
  int iVar1;
  
  iVar1 = PoRequestPowerIrp(*(undefined8 *)(param_1 + 0x18),0,*(undefined4 *)(param_1 + 0x120),
                            KeyboardClassWaitWakeComplete,param_1,0);
  return iVar1 == 0x103;
}



===== KeyboardClassQueryWmiRegInfo @ 1c0010c00 =====

undefined8
KeyboardClassQueryWmiRegInfo
          (longlong param_1,undefined4 *param_2,undefined8 param_3,undefined8 *param_4,
          undefined8 param_5,undefined8 *param_6)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  *param_2 = 0x20;
  *param_4 = &DAT_1c000b388;
  *param_6 = *(undefined8 *)(lVar1 + 0x18);
  return 0;
}



===== entry @ 1c0011010 =====

void entry(longlong param_1,ushort *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c0011044 =====

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



===== DriverEntry @ 1c0011080 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,ushort *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 uVar3;
  code *pcVar4;
  int iVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  longlong *plVar8;
  undefined1 *puVar9;
  wchar_t *pwVar10;
  wchar_t *pwVar11;
  uint uVar12;
  undefined **ppuVar13;
  undefined1 auStackY_2d8 [8];
  undefined1 auStackY_2d0 [24];
  undefined4 in_stack_fffffffffffffd48;
  undefined4 in_stack_fffffffffffffd4c;
  uint local_298 [2];
  longlong local_290;
  ushort local_288;
  ushort uStack_286;
  undefined4 local_284;
  undefined1 *local_280;
  longlong local_278;
  undefined8 local_270;
  longlong lStack_268;
  wchar_t *local_260 [3];
  undefined1 local_248 [512];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_2d8;
  local_290 = 0;
  local_298[0] = 0;
  local_284 = 0;
  local_260[0] = (wchar_t *)0x0;
  _DAT_1c000b168 = 1;
  plVar8 = (longlong *)0x0;
  local_270 = 0;
  lStack_268 = 0;
  pwVar11 = (wchar_t *)0x0;
  local_278 = 0;
  _WPP_MAIN_CB = 0;
  DAT_1c000b148 = &WPP_ThisDir_CTLGUID_KbdClassTraceGuid;
  DAT_1c000b150 = 0;
  _DAT_1c000b160 = 0;
  _DAT_1c000b180 = 0;
  _DAT_1c000b188 = 0;
  WppLoadTracingSupport();
  _DAT_1c000b160 = 0;
  WppInitKm(param_1,param_2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,10);
  }
  TraceLoggingRegisterEx_EtwRegister_EtwSetInformation();
  memset(&Globals,0,0x418);
  _DAT_1c000b1c0 = 1;
  DAT_1c000b5b0 = (longlong *)&DAT_1c000b5a8;
  DAT_1c000b5a8 = &DAT_1c000b5a8;
  _DAT_1c000b1c8 = 0;
  _DAT_1c000b1d0 = 0;
  KeInitializeEvent(&DAT_1c000b1d8,1,0);
  _DAT_1c000b398 = 0x2000000;
  DAT_1c000b3a0 = &DAT_1c000b3a8;
  memset(local_248,0,0x200);
  local_280 = local_248;
  local_288 = 0;
  uStack_286 = 0x200;
  DAT_1c000b388 = *param_2;
  _DAT_1c000b38a = *param_2 + 2;
  DAT_1c000b390 = (void *)ExAllocatePool2(0x40,_DAT_1c000b38a,0x4364624b);
  if (DAT_1c000b390 == (void *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xb);
    }
    local_260[0] = (wchar_t *)CONCAT44(local_260[0]._4_4_,*param_2 + 2);
    KeyboardClassLogError(param_1,0xc0050001,0x2712,0xc0000001,1,(undefined4 *)local_260,0);
    pwVar10 = pwVar11;
  }
  else {
    uVar6 = (ulonglong)*param_2;
    memcpy(DAT_1c000b390,*(void **)(param_2 + 4),uVar6);
    *(undefined2 *)((longlong)DAT_1c000b390 + (ulonglong)(*param_2 >> 1) * 2) = 0;
    KbdConfiguration(param_1);
    if (DAT_1c000b1f8 == 0) {
      in_stack_fffffffffffffd48 = CONCAT31((int3)((uint)in_stack_fffffffffffffd48 >> 8),1);
      uVar6 = KbdCreateClassObject(param_1,(longlong *)&DAT_1c000b208,&local_290,local_260,'\x01');
      plVar8 = (longlong *)(uVar6 & 0xffffffff);
      pwVar10 = local_260[0];
      if ((int)uVar6 < 0) goto LAB_1c00112ad;
      uVar6 = 0;
      plVar8 = *(longlong **)(local_290 + 0x40);
      *plVar8 = local_290;
      Globals = plVar8;
      *(undefined1 *)(plVar8 + 8) = 0;
      KeyboardAddDeviceEx(plVar8,local_260[0],0);
      ExFreePoolWithTag(local_260[0],0);
      local_260[0] = (wchar_t *)0x0;
      *(uint *)(local_290 + 0x30) = *(uint *)(local_290 + 0x30) & 0xffffff7f;
    }
    RtlCopyUnicodeString(&local_288,&DAT_1c000b398);
    local_288 = local_288 - 10;
    RtlAppendUnicodeToString(&local_288,L"Port");
    if ((ulonglong)uStack_286 < (ulonglong)local_288 + 2) {
      plVar8 = (longlong *)0xc0000001;
      pwVar10 = pwVar11;
    }
    else {
      *(undefined2 *)(local_280 + (ulonglong)(local_288 >> 1) * 2 + 2) = 0;
      KbdDeterminePortsServiced(&local_288,local_298);
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,uVar6,0xc,
                          CONCAT44(in_stack_fffffffffffffd4c,in_stack_fffffffffffffd48),
                          (char)local_298[0]);
      }
      RtlInitUnicodeString(&local_270,0);
      local_270._0_4_ = CONCAT22(local_288 + 0x14,(undefined2)local_270);
      lStack_268 = ExAllocatePool2(0x100,local_288 + 0x14,0x4364624b);
      if (lStack_268 == 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xd);
        }
        plVar8 = (longlong *)0xc0000001;
        local_260[0] = (wchar_t *)CONCAT44(local_260[0]._4_4_,(uint)local_270._2_2_);
        KeyboardClassLogError(param_1,0xc0050001,0x2716,0xc0000001,1,(undefined4 *)local_260,0);
        pwVar10 = pwVar11;
      }
      else {
        RtlAppendUnicodeToString(&local_270,L"\\Device\\");
        RtlAppendUnicodeToString(&local_270,local_280);
        RtlAppendUnicodeToString(&local_270,L"0");
        ppuVar13 = (undefined **)0x0;
        if (DAT_1c000b200 != 0) {
          do {
            if (local_298[0] <= (uint)ppuVar13) break;
            *(short *)(lStack_268 + -2 + (local_270 >> 1 & 0x7fff) * 2) = (short)ppuVar13 + 0x30;
            uVar6 = KbdCreateClassObject
                              (param_1,(longlong *)&DAT_1c000b208,&local_290,local_260,'\x01');
            if ((int)uVar6 < 0) {
              KeyboardClassLogError(DriverEntry,0xc0050001,0x2718,(int)uVar6,0,(undefined4 *)0x0,0);
LAB_1c0011653:
              pwVar11 = local_260[0];
            }
            else {
              plVar1 = *(longlong **)(local_290 + 0x40);
              *plVar1 = local_290;
              *(undefined1 *)(plVar1 + 8) = 0;
              *(uint *)(local_290 + 0x30) = *(uint *)(local_290 + 0x30) & 0xffffff7f;
              iVar5 = IoGetDeviceObjectPointer(&local_270,0x80,&local_278,plVar1 + 2);
              pwVar11 = local_260[0];
              if (iVar5 < 0) {
                if (plVar1[0xd] != 0) {
                  ExFreePoolWithTag(plVar1[0xd],0);
                  plVar1[0xf] = 0;
                  plVar1[0xe] = 0;
                  plVar1[0xd] = 0;
                }
                IoDeleteDevice(*plVar1);
                goto LAB_1c0011653;
              }
              *(char *)(local_290 + 0x4c) = *(char *)(plVar1[2] + 0x4c) + '\x01';
              uVar6 = KeyboardAddDeviceEx(plVar1,local_260[0],local_278);
              if (pwVar11 != (wchar_t *)0x0) {
                ExFreePoolWithTag(pwVar11,0);
                pwVar11 = (wchar_t *)0x0;
                local_260[0] = (wchar_t *)0x0;
              }
              if ((int)uVar6 < 0) {
                if (Globals == (longlong *)0x0) {
                  lVar2 = plVar1[0x2c];
                  if (lVar2 != 0) {
                    plVar1[0x2c] = 0;
                    local_278 = lVar2;
                  }
                }
                else {
                  ExAcquireFastMutex(&DAT_1c000b1c0);
                  local_278 = *(longlong *)
                               (DAT_1c000b1a8 + (ulonglong)*(uint *)((longlong)plVar1 + 0xc4) * 0x18
                               );
                  *(undefined8 *)
                   (DAT_1c000b1a8 + (ulonglong)*(uint *)((longlong)plVar1 + 0xc4) * 0x18) = 0;
                  *(undefined1 *)
                   (DAT_1c000b1a8 + 0x13 + (ulonglong)*(uint *)((longlong)plVar1 + 0xc4) * 0x18) = 1
                  ;
                  *(undefined8 *)
                   (DAT_1c000b1a8 + 8 + (ulonglong)*(uint *)((longlong)plVar1 + 0xc4) * 0x18) = 0;
                  ExReleaseFastMutex(&DAT_1c000b1c0);
                }
                if (local_278 != 0) {
                  ObfDereferenceObject();
                }
                if (plVar1[0xd] != 0) {
                  ExFreePoolWithTag(plVar1[0xd],0);
                  plVar1[0xf] = 0;
                  plVar1[0xe] = 0;
                  plVar1[0xd] = 0;
                }
                IoDeleteDevice(*plVar1);
              }
              else {
                plVar8 = plVar1 + 0x2a;
                if ((undefined8 **)*DAT_1c000b5b0 != &DAT_1c000b5a8) {
                  pcVar4 = (code *)swi(0x29);
                  (*pcVar4)(3);
                  puVar9 = auStackY_2d0;
                  goto LAB_1c0011872;
                }
                *plVar8 = (longlong)&DAT_1c000b5a8;
                plVar1[0x2b] = (longlong)DAT_1c000b5b0;
                *DAT_1c000b5b0 = (longlong)plVar8;
                DAT_1c000b5b0 = plVar8;
              }
            }
            uVar12 = (uint)ppuVar13 + 1;
            ppuVar13 = (undefined **)(ulonglong)uVar12;
          } while (uVar12 < DAT_1c000b200);
        }
        plVar8 = (longlong *)0x0;
        for (puVar7 = DAT_1c000b5a8; pwVar10 = pwVar11, (undefined8 **)puVar7 != &DAT_1c000b5a8;
            puVar7 = (undefined8 *)*puVar7) {
          DAT_1c000b1b8 = DAT_1c000b1b8 + 1;
        }
      }
    }
  }
LAB_1c00112ad:
  puVar9 = auStackY_2d8;
  ppuVar13 = &WPP_RECORDER_INITIALIZED;
  if (lStack_268 != 0) {
    ExFreePoolWithTag(lStack_268,0);
  }
  if (pwVar10 != (wchar_t *)0x0) {
    ExFreePoolWithTag(pwVar10,0);
  }
  if ((int)plVar8 < 0) {
LAB_1c0011872:
    iVar5 = (int)plVar8;
    if (DAT_1c000b390 != (void *)0x0) {
      *(undefined8 *)(puVar9 + -8) = 0x1c0011887;
      ExFreePoolWithTag(DAT_1c000b390,0);
      DAT_1c000b390 = (void *)0x0;
    }
    if (DAT_1c000b1a8 != 0) {
      *(undefined8 *)(puVar9 + -8) = 0x1c00118a8;
      ExFreePoolWithTag(DAT_1c000b1a8,0);
      DAT_1c000b1a8 = 0;
    }
    if (Globals != (longlong *)0x0) {
      lVar2 = Globals[0xd];
      if (lVar2 != 0) {
        *(undefined8 *)(puVar9 + -8) = 0x1c00118d2;
        ExFreePoolWithTag(lVar2,0);
        Globals[0xf] = 0;
        Globals[0xe] = 0;
        Globals[0xd] = 0;
      }
      lVar2 = *Globals;
      *(undefined8 *)(puVar9 + -8) = 0x1c0011909;
      IoDeleteDevice(lVar2);
      Globals = (longlong *)0x0;
    }
  }
  else {
    IoRegisterDriverReinitialization(param_1,KeyboardClassFindMorePorts,0);
    iVar5 = 0;
    *(code **)(param_1 + 0x70) = KeyboardClassCreate;
    *(code **)(param_1 + 0x80) = KeyboardClassClose;
    *(code **)(param_1 + 0x88) = KeyboardClassRead;
    *(code **)(param_1 + 0xb8) = KeyboardClassFlush;
    *(code **)(param_1 + 0xe0) = KeyboardClassDeviceControl;
    *(code **)(param_1 + 0xe8) = KeyboardClassPassThrough;
    *(code **)(param_1 + 0x100) = KeyboardClassCleanup;
    *(code **)(param_1 + 0x148) = KeyboardPnP;
    *(code **)(param_1 + 0x120) = KeyboardClassPower;
    *(code **)(param_1 + 0x128) = KeyboardClassSystemControl;
    *(code **)(*(longlong *)(param_1 + 0x30) + 8) = KeyboardAddDevice;
    puVar9 = auStackY_2d8;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != ppuVar13) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    *(undefined8 *)(puVar9 + -8) = 0x1c0011940;
    WPP_RECORDER_SF_(uVar3,5,1,0xe);
  }
  uVar3 = DAT_1c000b020;
  if (iVar5 < 0) {
    DAT_1c000b020 = 0;
    DAT_1c000b000 = 0;
    *(undefined8 *)(puVar9 + -8) = 0x1c0011960;
    EtwUnregister(uVar3);
    *(undefined8 *)(puVar9 + -8) = 0x1c001196d;
    WppCleanupKm(param_1);
  }
  *(undefined8 *)(puVar9 + -8) = 0x1c001197e;
  return iVar5;
}



===== KbdConfiguration @ 1c00119a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KbdConfiguration(undefined8 param_1)

{
  undefined1 uVar1;
  int iVar2;
  longlong lVar3;
  code *pcVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  undefined8 uVar9;
  bool bVar10;
  undefined1 auStackY_108 [32];
  longlong *plVar11;
  int local_d8;
  undefined4 local_d4;
  uint local_d0;
  undefined4 local_cc;
  longlong local_c8 [4];
  undefined8 local_a8 [4];
  int *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  uint *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  wchar_t *local_58;
  uint local_50 [2];
  uint *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  local_c8[0] = 0;
  lVar3 = 0;
  DAT_1c000b294 = 100;
  DAT_1c000b1fc = 0;
  DAT_1c000b200 = 1;
  DAT_1c000b1f8 = 1;
  RtlUnicodeStringCopyString(&DAT_1c000b398);
  plVar11 = local_c8;
  uVar9 = 0;
  lVar6 = 0;
  lVar8 = 0x20019;
  iVar2 = IoOpenDriverRegistryKey();
  if (iVar2 < 0) {
    if (iVar2 != -0x3fffffcc) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0011bf4;
      uVar9 = 0x40;
      lVar6 = CONCAT71((int7)((ulonglong)lVar6 >> 8),2);
LAB_1c0011bb3:
      uVar1 = (undefined1)iVar2;
LAB_1c0011bb7:
      param_1 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_d(param_1,(byte)lVar6,lVar8,(short)uVar9,plVar11,uVar1);
    }
  }
  else {
    lVar7 = 0x150;
    lVar8 = 0x4364624b;
    param_1 = 0x100;
    lVar3 = ExAllocatePool2();
    lVar6 = local_c8[0];
    if (lVar3 == 0) {
      lVar6 = lVar7;
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0011bf4;
      uVar9 = 0x41;
      uVar1 = 1;
      lVar6 = CONCAT71((int7)((ulonglong)lVar7 >> 8),2);
      goto LAB_1c0011bb7;
    }
    *(ushort **)(lVar3 + 0x88) = &DAT_1c000b398;
    *(undefined4 *)(lVar3 + 8) = 0x120;
    *(undefined4 *)(lVar3 + 0x20) = 0x4000004;
    *(wchar_t **)(lVar3 + 0x10) = L"KeyboardDataQueueSize";
    *(undefined4 *)(lVar3 + 0x40) = 0x120;
    *(uint **)(lVar3 + 0x18) = &DAT_1c000b294;
    *(wchar_t **)(lVar3 + 0x48) = L"MaximumPortsServiced";
    *(undefined4 **)(lVar3 + 0x50) = &DAT_1c000b200;
    *(wchar_t **)(lVar3 + 0x80) = L"KeyboardDeviceBaseName";
    *(wchar_t **)(lVar3 + 0xb8) = L"ConnectMultiplePorts";
    *(uint **)(lVar3 + 0xc0) = &DAT_1c000b1f8;
    *(wchar_t **)(lVar3 + 0xf0) = L"SendOutputToAllPorts";
    *(undefined4 *)(lVar3 + 0x58) = 0x4000004;
    *(undefined4 *)(lVar3 + 0x78) = 0x120;
    *(undefined4 *)(lVar3 + 0xb0) = 0x120;
    *(undefined4 *)(lVar3 + 200) = 0x4000004;
    *(undefined4 *)(lVar3 + 0xe8) = 0x120;
    *(undefined4 *)(lVar3 + 0x100) = 0x4000004;
    *(undefined4 **)(lVar3 + 0xf8) = &DAT_1c000b1fc;
    *(undefined4 *)(lVar3 + 0x90) = 0x1000001;
    local_c8[1] = 0;
    local_c8[2] = 0;
    RtlInitUnicodeString(local_c8 + 1,L"RtlQueryRegistryValuesEx");
    pcVar4 = (code *)MmGetSystemRoutineAddress(local_c8 + 1);
    param_1 = 0xc0000000;
    if (pcVar4 == (code *)0x0) {
      pcVar4 = RtlQueryRegistryValues_exref;
    }
    uVar9 = 0;
    plVar11 = (longlong *)0x0;
    lVar8 = lVar3;
    iVar2 = (*pcVar4)();
    if (iVar2 < 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED == &WPP_RECORDER_INITIALIZED) goto LAB_1c0011bf4;
      uVar9 = 0x42;
      lVar6 = CONCAT71((int7)((ulonglong)lVar6 >> 8),3);
      goto LAB_1c0011bb3;
    }
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar9 = 0x43;
    lVar6 = CONCAT71((int7)((ulonglong)lVar6 >> 8),4);
    param_1 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_S(param_1,4,lVar8,0x43,plVar11,DAT_1c000b3a0);
  }
LAB_1c0011bf4:
  if (DAT_1c000b294 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar9 = 0x44;
      param_1 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_D(param_1,lVar6,lVar8,0x44,plVar11,0);
    }
    DAT_1c000b294 = 100;
  }
  if (DAT_1c000b294 < 0x15555556) {
    DAT_1c000b294 = DAT_1c000b294 * 0xc;
  }
  else {
    DAT_1c000b294 = 0x4b0;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar9 = 0x45;
    param_1 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_D(param_1,lVar6,lVar8,0x45,plVar11,(char)DAT_1c000b294);
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar9 = 0x46;
      param_1 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      WPP_RECORDER_SF_d(param_1,4,lVar8,0x46,plVar11,(char)DAT_1c000b200);
    }
  }
  bVar10 = DAT_1c000b1f8 == 0;
  DAT_1c000b1f8 = (uint)bVar10;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar9 = 0x47;
    param_1 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_d(param_1,4,lVar8,0x47,plVar11,bVar10);
  }
  if (5 < DAT_1c000b000) {
    uVar5 = _tlgKeywordOn();
    if ((char)uVar5 != '\0') {
      local_7c = 0;
      local_6c = 0;
      local_5c = 0;
      local_50[1] = 0;
      local_3c = 0;
      local_2c = 0;
      local_d8 = DAT_1c000b294;
      local_88 = &local_d8;
      local_d4 = DAT_1c000b200;
      local_78 = &local_d4;
      local_68 = local_50;
      local_58 = DAT_1c000b3a0;
      local_50[0] = (uint)DAT_1c000b398;
      local_d0 = DAT_1c000b1f8;
      local_48 = &local_d0;
      local_cc = DAT_1c000b1fc;
      local_38 = &local_cc;
      local_80 = 4;
      local_70 = 4;
      local_60 = 2;
      local_40 = 4;
      local_30 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_1c00096dc,lVar8,uVar9,8,local_a8);
    }
  }
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0);
  }
  if (local_c8[0] != 0) {
    ZwClose();
  }
  return;
}


