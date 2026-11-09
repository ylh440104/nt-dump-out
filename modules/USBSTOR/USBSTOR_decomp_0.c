
===== USBSTOR_TimeoutDpc @ 140001010 =====

void USBSTOR_TimeoutDpc(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 in_stack_ffffffffffffffc8;
  undefined4 uVar6;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);
  lVar1 = *(longlong *)(param_2 + 0x40);
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  bVar2 = false;
  KeAcquireInStackQueuedSpinLockAtDpcLevel(lVar1 + 0x90,&local_28);
  uVar3 = *(uint *)(lVar1 + 0x80);
  if ((uVar3 & 8) == 0) {
    if ((uVar3 & 2) == 0) {
      if ((uVar3 & 0x20) == 0) goto LAB_140001072;
      uVar3 = uVar3 | 0x40;
      bVar2 = false;
    }
    else {
      uVar3 = uVar3 | 8;
      bVar2 = true;
    }
    *(uint *)(lVar1 + 0x80) = uVar3;
  }
LAB_140001072:
  KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_28);
  if (bVar2) {
    iVar4 = IoAcquireRemoveLockEx
                      (lVar1 + 0x728,USBSTOR_ResetDeviceWorkItem,"",1,CONCAT44(uVar6,0x20));
    if (-1 < iVar4) {
      uVar5 = 0;
      USBSTOR_LogEntry(0x524d4954,param_2,0,0);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xab,
                &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
      }
      USBSTOR_QueueWorkItem
                (param_2,*(longlong *)(lVar1 + 0x170),USBSTOR_ResetDeviceWorkItem,uVar5,0,
                 *(char *)(lVar1 + 0x754) == '\0');
    }
  }
  return;
}



===== USBD_QueryUsbCapability @ 140001148 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int USBD_QueryUsbCapability(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  char *pcVar4;
  undefined1 auStack_68 [48];
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  cVar1 = KeGetCurrentIrql();
  if (cVar1 == '\0') {
    if (param_1 != 0) {
      if (*(int *)(param_1 + 0xd8) == -1) {
        if (g_EnableDbgPrints == '\0') {
          return -0x3ffffffe;
        }
        pcVar4 = 
        "Could not exchange an interface with the Underlying USB core stack, querrying for capability is not possible\n"
        ;
      }
      else {
        if (*(int *)(param_1 + 0xd8) != 0x600) {
          local_30 = *(undefined8 *)(param_1 + 0x30);
          local_28 = 0x4f299bd08a2f776c;
          uStack_20 = 0xc7d44688a3c77197;
          local_38 = 0x280001;
          local_18 = 0;
          iVar2 = USBDInternal_BuildandSendIoctlSynchronously
                            (*(undefined8 *)(param_1 + 0x38),*(longlong *)(param_1 + 0xd0),param_3,
                             &local_38);
          return iVar2;
        }
        lVar3 = RtlCompareMemory(&GUID_USB_CAPABILITY_DEVICE_CONNECTION_SUPER_SPEED_COMPATIBLE,
                                 &GUID_USB_CAPABILITY_DEVICE_CONNECTION_HIGH_SPEED_COMPATIBLE,0x10);
        if (lVar3 == 0x10) {
          if (*(char *)(param_1 + 0xe0) != '\0') {
            return 0;
          }
          if (g_EnableDbgPrints != '\0') {
            DbgPrintEx(0x4d,3,"Device is not High Speed\n");
          }
          return -0x3fffff45;
        }
        lVar3 = RtlCompareMemory(&GUID_USB_CAPABILITY_DEVICE_CONNECTION_SUPER_SPEED_COMPATIBLE,
                                 &GUID_USB_CAPABILITY_SELECTIVE_SUSPEND,0x10);
        if (lVar3 == 0x10) {
          return 0;
        }
        if (g_EnableDbgPrints == '\0') {
          return -0x3ffffffe;
        }
        pcVar4 = "QueryUsbCapability not supported/implemented by core stack\n";
      }
      DbgPrintEx(0x4d,0,pcVar4);
      return -0x3ffffffe;
    }
    if (g_EnableDbgPrints == '\0') {
      return -0x3ffffff3;
    }
    pcVar4 = "USBDHandle cant be NULL\n";
  }
  else {
    if (g_EnableDbgPrints == '\0') {
      return -0x3ffffff3;
    }
    pcVar4 = "PASSIVE_LEVEL required\n";
  }
  DbgPrintEx(0x4d,0,pcVar4);
  return -0x3ffffff3;
}



===== USBDInternal_BuildandSendIoctlSynchronously @ 1400012ec =====

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
    *(undefined8 *)(lVar3 + 0x18) = 0;
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



===== USBSTOR_SetSrbPending @ 140001450 =====

void USBSTOR_SetSrbPending(longlong param_1,char param_2)

{
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (param_2 == '\0') {
    KeAcquireInStackQueuedSpinLock(param_1 + 0x90,&local_28);
    *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) & 0xffffffdf;
  }
  else {
    KeAcquireInStackQueuedSpinLock();
    *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) | 0x20;
  }
  KeReleaseInStackQueuedSpinLock(&local_28);
  return;
}



===== USBSTOR_IssueInterruptRequest @ 1400014c0 =====

int USBSTOR_IssueInterruptRequest(longlong param_1,longlong param_2)

{
  int iVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6c,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  USBSTOR_LogEntry(0x544e4949,param_1,param_2,0);
  iVar1 = USBSTOR_IssueBulkOrInterruptRequest
                    (param_1,param_2,
                     *(undefined8 *)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x70) + 8),0,2,
                     *(longlong *)(param_1 + 0x40) + 0x4a8,0,USBSTOR_InterruptDataCompletionRoutine,
                     0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6d,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar1);
  }
  USBSTOR_LogEntry(0x746e6969,param_1,param_2,(longlong)iVar1);
  return iVar1;
}



===== USBSTOR_IssueBulkOrInterruptRequest @ 1400015d0 =====

int USBSTOR_IssueBulkOrInterruptRequest
              (longlong param_1,longlong param_2,undefined8 param_3,undefined4 param_4,
              undefined4 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
              undefined8 param_9)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong lVar4;
  bool bVar5;
  int iVar6;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x58,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_48);
    *DAT_14001a1b0 = 0x52494249;
    *(longlong *)(DAT_14001a1b0 + 2) = param_1;
    *(longlong *)(DAT_14001a1b0 + 4) = param_2;
    *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_48);
  }
  lVar2 = *(longlong *)(param_1 + 0x40);
  uVar3 = *(undefined8 *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  *(undefined8 *)(lVar2 + 0x18a) = 0;
  *(undefined8 *)(lVar2 + 0x192) = 0;
  *(undefined8 *)(lVar2 + 0x19a) = 0;
  *(undefined8 *)(lVar2 + 0x1a2) = 0;
  *(undefined8 *)(lVar2 + 0x1aa) = 0;
  *(undefined8 *)(lVar2 + 0x1b2) = 0;
  *(undefined8 *)(lVar2 + 0x1ba) = 0;
  *(undefined8 *)(lVar2 + 0x1c2) = 0;
  *(undefined8 *)(lVar2 + 0x1ca) = 0;
  *(undefined8 *)(lVar2 + 0x1d2) = 0;
  *(undefined8 *)(lVar2 + 0x1da) = 0;
  *(undefined8 *)(lVar2 + 0x1e2) = 0;
  *(undefined8 *)(lVar2 + 0x1ea) = 0;
  *(undefined8 *)(lVar2 + 0x1f2) = 0;
  *(undefined8 *)(lVar2 + 0x1fa) = 0;
  *(undefined4 *)(lVar2 + 0x202) = 0;
  *(undefined2 *)(lVar2 + 0x206) = 0;
  *(undefined4 *)(lVar2 + 0x1ac) = param_5;
  *(undefined8 *)(lVar2 + 0x1b0) = param_6;
  *(undefined8 *)(lVar2 + 0x1b8) = param_7;
  *(undefined4 *)(lVar2 + 0x188) = 0x90080;
  *(undefined8 *)(lVar2 + 0x1a0) = param_3;
  *(undefined4 *)(lVar2 + 0x1a8) = param_4;
  lVar4 = *(longlong *)(param_2 + 0xb8);
  *(undefined4 **)(lVar4 + -0x40) = (undefined4 *)(lVar2 + 0x188);
  *(undefined1 *)(lVar4 + -0x48) = 0xf;
  *(undefined4 *)(lVar4 + -0x30) = 0x220003;
  lVar4 = *(longlong *)(param_2 + 0xb8);
  *(undefined8 *)(lVar4 + -0x10) = param_8;
  *(undefined8 *)(lVar4 + -8) = param_9;
  *(undefined1 *)(lVar4 + -0x45) = 0xe0;
  KeAcquireInStackQueuedSpinLock(lVar2 + 0x90,&local_30);
  uVar1 = *(uint *)(lVar2 + 0x80);
  *(longlong *)(lVar2 + 0x148) = param_2;
  if (((uVar1 & 0x40) == 0) || ((uVar1 & 8) != 0)) {
    bVar5 = false;
  }
  else {
    bVar5 = true;
  }
  *(uint *)(lVar2 + 0x80) = uVar1 & 0xffffffbf | 2;
  KeReleaseInStackQueuedSpinLock(&local_30);
  iVar6 = IofCallDriver(*(undefined8 *)(lVar2 + 0x18),param_2);
  if (bVar5) {
    USBSTOR_LogEntry(0x4f544942,param_1,param_2,uVar3);
    USBSTOR_QueueResetDevice(param_1,uVar3);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x59,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar6);
  }
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_48);
    *DAT_14001a1b0 = 0x72696269;
    *(longlong *)(DAT_14001a1b0 + 2) = param_1;
    *(longlong *)(DAT_14001a1b0 + 4) = param_2;
    *(longlong *)(DAT_14001a1b0 + 6) = (longlong)iVar6;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_48);
  }
  return iVar6;
}



===== USBSTOR_IsDeviceConnected @ 140001960 =====

int USBSTOR_IsDeviceConnected(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  uint local_res8 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_res8[0] = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb4,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar4 = *(longlong *)(lVar1 + 0x18);
  lVar4 = IoAllocateIrp(CONCAT71((int7)((ulonglong)lVar4 >> 8),*(undefined1 *)(lVar4 + 0x4c)),0);
  if (lVar4 == 0) {
    iVar3 = -0x3fffff66;
  }
  else {
    KeInitializeEvent(&local_28,1);
    lVar2 = *(longlong *)(lVar4 + 0xb8);
    *(uint **)(lVar2 + -0x40) = local_res8;
    *(undefined1 *)(lVar2 + -0x48) = 0xf;
    *(undefined4 *)(lVar2 + -0x30) = 0x220013;
    lVar2 = *(longlong *)(lVar4 + 0xb8);
    *(code **)(lVar2 + -0x10) = USBSTOR_SyncCompletionRoutine;
    *(undefined8 **)(lVar2 + -8) = &local_28;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    iVar3 = IofCallDriver(*(undefined8 *)(lVar1 + 0x18),lVar4);
    if (iVar3 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      iVar3 = *(int *)(lVar4 + 0x30);
    }
    IoFreeIrp(lVar4);
    if ((-1 < iVar3) && ((local_res8[0] & 2) == 0)) {
      iVar3 = -0x3fffff40;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb5,
               &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar3);
    }
  }
  return iVar3;
}



===== USBSTOR_FdoStartDevice @ 140001ae0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int USBSTOR_FdoStartDevice(longlong param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  bool bVar5;
  byte bVar6;
  undefined1 uVar7;
  int iVar8;
  int iVar9;
  ulonglong *puVar10;
  code *pcVar11;
  undefined8 *puVar12;
  undefined2 uVar13;
  longlong lVar14;
  undefined8 uVar15;
  ulonglong *puVar16;
  uint uVar17;
  char *pcVar18;
  longlong local_res8;
  undefined8 local_res10;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 local_128;
  undefined4 *local_120;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 uStack_110;
  undefined4 local_10c;
  undefined4 uStack_108;
  undefined4 local_104;
  undefined8 local_100;
  undefined4 *local_f8;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 uStack_e8;
  undefined4 local_e4;
  undefined4 uStack_e0;
  undefined4 local_dc;
  ulonglong local_d8 [2];
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
  code *pcStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  code *local_48;
  
  local_48 = (code *)0x0;
  local_res8 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  pcStack_70 = (code *)0x0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  local_148 = 0;
  uStack_140 = 0;
  local_138 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_148);
    *DAT_14001a1b0 = 0x54525453;
    *(longlong *)(DAT_14001a1b0 + 2) = param_1;
    *(longlong *)(DAT_14001a1b0 + 4) = param_2;
    *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_148);
  }
  lVar2 = *(longlong *)(param_1 + 0x40);
  *(undefined1 *)(lVar2 + 0x749) = 0;
  cVar4 = IoForwardIrpSynchronously(*(undefined8 *)(lVar2 + 0x18),param_2);
  if (cVar4 == '\0') {
    iVar8 = -0x3fffffff;
LAB_140002061:
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar13 = 0x39;
LAB_14000208b:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar13,
              &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
    }
LAB_140001e6b:
    if (*(char *)(lVar2 + 0x78c) == '\0') goto LAB_140001f55;
  }
  else {
    iVar8 = *(int *)(param_2 + 0x30);
    if (iVar8 < 0) goto LAB_140002061;
    local_128 = 1;
    *(undefined4 *)(lVar2 + 0x750) = 0;
    local_f8 = (undefined4 *)(lVar2 + 0x750);
    puVar12 = (undefined8 *)&uStack_110;
    *(undefined4 *)(lVar2 + 0x74c) = 0;
    local_114 = 0;
    uStack_110 = 0;
    local_10c = 0;
    uStack_108 = 0;
    local_104 = 0;
    lVar14 = 2;
    local_100 = 2;
    puVar16 = (ulonglong *)0x0;
    local_ec = 0;
    uStack_e8 = 0;
    local_e4 = 0;
    uStack_e0 = 0;
    local_dc = 0;
    local_120 = (undefined4 *)(lVar2 + 0x74c);
    local_118 = 4;
    local_f0 = 4;
    local_d8[0] = local_d8[0] & 0xffffffff;
    local_c0 = local_c0 & 0xffffffff;
    local_a8 = 0;
    uStack_a0 = 0;
    local_res10 = 0;
    do {
      uVar17 = *(int *)(puVar12 + -3) - 1;
      pcVar18 = (char *)(ulonglong)uVar17;
      if (uVar17 == 0) {
        *puVar12 = L"RootHubConnectedEnStorDevices";
LAB_140001ca5:
        *(undefined4 *)(puVar12 + 1) = 0x4000004;
      }
      else {
        if (uVar17 == 1) {
          *puVar12 = L"DisallowLegacyDiskDevices";
          goto LAB_140001ca5;
        }
        puVar16 = (ulonglong *)0xc000000d;
      }
      puVar12 = puVar12 + 5;
      lVar14 = lVar14 + -1;
    } while (lVar14 != 0);
    uVar15 = 0;
    if (-1 < (int)puVar16) {
      uVar15 = 0xa8;
      puVar16 = (ulonglong *)0x53414d55;
      puVar10 = (ulonglong *)ExAllocatePool2(0x100);
      if (puVar10 != (ulonglong *)0x0) {
        RtlInitUnicodeString
                  (&local_a8,
                   L"\\Registry\\Machine\\Software\\Policies\\Microsoft\\Windows\\EnhancedStorageDevices"
                  );
        local_c8 = &local_a8;
        local_d8[0] = 0x30;
        puVar16 = local_d8;
        local_c0 = 0x240;
        local_d8[1] = 0;
        local_b8 = 0;
        uStack_b0 = 0;
        iVar8 = ZwOpenKey(&local_res10);
        if (-1 < iVar8) {
          puVar10[2] = CONCAT44(local_10c,uStack_110);
          puVar10[3] = (ulonglong)local_120;
          puVar10[5] = (ulonglong)local_120;
          *(undefined4 *)(puVar10 + 6) = local_118;
          *(undefined4 *)(puVar10 + 4) = uStack_108;
          puVar10[9] = CONCAT44(local_e4,uStack_e8);
          puVar10[10] = (ulonglong)local_f8;
          puVar10[0xc] = (ulonglong)local_f8;
          *(undefined4 *)(puVar10 + 0xd) = local_f0;
          *(undefined4 *)(puVar10 + 0xb) = uStack_e0;
          *(undefined4 *)(puVar10 + 1) = 0x120;
          *(undefined4 *)(puVar10 + 8) = 0x120;
          local_98 = 0;
          uStack_90 = 0;
          RtlInitUnicodeString(&local_98,L"RtlQueryRegistryValuesEx");
          pcVar11 = (code *)MmGetSystemRoutineAddress(&local_98);
          if (pcVar11 == (code *)0x0) {
            pcVar11 = RtlQueryRegistryValues_exref;
          }
          pcVar18 = (char *)0x0;
          puVar16 = puVar10;
          (*pcVar11)(0x40000000);
          ZwClose(local_res10);
        }
        uVar15 = 0;
        ExFreePoolWithTag(puVar10);
      }
    }
    bVar5 = USBSTOR_IsDeviceConnectedToRootHub(param_1);
    *(bool *)(lVar2 + 0x74a) = bVar5;
    if (*(longlong *)(lVar2 + 0x6a8) == 0) {
      pcVar18 = (char *)0x0;
      puVar16 = (ulonglong *)0x0;
      uVar15 = 0x200;
      lVar14 = IoAllocateMdl(lVar2 + 0x4a8);
      *(longlong *)(lVar2 + 0x6a8) = lVar14;
      if (lVar14 != 0) {
        MmBuildMdlForNonPagedPool(lVar14);
        goto LAB_1400020f4;
      }
      iVar8 = -0x3fffff66;
      goto LAB_140001e6b;
    }
LAB_1400020f4:
    if (*(longlong *)(lVar2 + 0x170) == 0) {
      lVar14 = IoAllocateWorkItem(param_1);
      *(longlong *)(lVar2 + 0x170) = lVar14;
      if (lVar14 == 0) {
        iVar8 = -0x3fffff66;
        goto LAB_140001e6b;
      }
    }
    if ((*(longlong *)(lVar2 + 0x30) == 0) && (iVar8 = USBSTOR_GetDescriptors(param_1), iVar8 < 0))
    goto LAB_140001e6b;
    USBSTOR_QueryGlobalFdoParams(param_1);
    iVar8 = USBSTOR_SelectConfiguration(param_1);
    if (iVar8 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_140001e6b;
      uVar13 = 0x3a;
      goto LAB_14000208b;
    }
    if (((*(char *)(*(longlong *)(lVar2 + 0x40) + 5) == '\b') &&
        (*(char *)(*(longlong *)(lVar2 + 0x40) + 7) == 'P')) && (*(int *)(lVar2 + 0x78) == 0)) {
      *(undefined4 *)(lVar2 + 0x78) = 1;
    }
    if (*(int *)(lVar2 + 0x78) != 1) {
      *(uint *)(lVar2 + 0x84) = *(uint *)(lVar2 + 0x84) & 0xffffff7f;
    }
    iVar8 = USBSTOR_GetPipes(param_1);
    if (iVar8 < 0) goto LAB_140001e6b;
    cVar4 = USBSTOR_IsDeviceAsyncCapable(lVar2);
    if ((cVar4 != '\0') && (*(longlong *)(lVar2 + 0x178) == 0)) {
      lVar14 = IoAllocateWorkItem(param_1);
      *(longlong *)(lVar2 + 0x178) = lVar14;
      if (lVar14 == 0) {
        iVar8 = -0x3fffff66;
        goto LAB_140001e6b;
      }
    }
    cVar4 = USBSTOR_IsDeviceAsyncCapable(lVar2);
    if (((cVar4 != '\0') || ((*(uint *)(lVar2 + 0x84) & 0x800) != 0)) &&
       (*(longlong *)(lVar2 + 0x180) == 0)) {
      lVar14 = IoAllocateWorkItem(param_1);
      *(longlong *)(lVar2 + 0x180) = lVar14;
      if (lVar14 == 0) {
        iVar8 = -0x3fffff66;
        goto LAB_140001e6b;
      }
    }
    lVar14 = *(longlong *)(lVar2 + 0x30);
    if (((lVar14 != 0) && (*(short *)(lVar14 + 8) == 0x57b)) &&
       ((*(short *)(lVar14 + 10) == 0 && (*(ushort *)(lVar14 + 0xc) < 0x128)))) {
      *(uint *)(lVar2 + 0x84) = *(uint *)(lVar2 + 0x84) | 1;
    }
    if ((*(longlong **)(lVar2 + 0x20) == (longlong *)(lVar2 + 0x20)) &&
       (iVar8 = USBSTOR_EnumerateChildren(param_1,uVar15,(byte *)puVar16), iVar8 < 0)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29])))
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
                 &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar8);
      }
      goto LAB_140001e6b;
    }
    iVar9 = USBSTOR_GetBusInterface(param_1,&local_88);
    if (iVar9 < 0) {
      *(undefined1 *)(lVar2 + 0x715) = 0;
    }
    else {
      uVar7 = (*local_48)(uStack_80);
      *(undefined1 *)(lVar2 + 0x715) = uVar7;
      (*pcStack_70)(uStack_80);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        pcVar18 = "TRUE";
        if (*(char *)(lVar2 + 0x715) == '\0') {
          pcVar18 = "FALSE";
        }
        WPP_SF_s(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,puVar16,pcVar18);
      }
    }
    lVar14 = *(longlong *)(lVar2 + 0x18);
    iVar9 = USBD_CreateHandle(param_1,lVar14,puVar16,pcVar18,&local_res8);
    lVar3 = local_res8;
    if (-1 < iVar9) {
      iVar9 = USBD_QueryUsbCapability(local_res8,lVar14,puVar16);
      lVar14 = local_res8;
      if (-1 < iVar9) {
        *(undefined1 *)(lVar2 + 0x716) = 1;
      }
      *(undefined1 *)(lVar3 + 0xe1) = 1;
      LOCK();
      piVar1 = (int *)(lVar3 + 0xdc);
      iVar9 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar9 < 2) {
        if (*(char *)(lVar3 + 0xe1) == '\0') {
          if (g_EnableDbgPrints != '\0') {
            DbgPrintEx(0x4d,0,
                       "UsbdHandleInfo->PendingDelete should be set here UsbdHandleInfo 0x%p\n",
                       local_res8);
          }
        }
        else {
          if (*(code **)(local_res8 + 0x70) != (code *)0x0) {
            (**(code **)(local_res8 + 0x70))(*(undefined8 *)(local_res8 + 0x30));
          }
          ExFreePoolWithTag(lVar14,*(undefined4 *)(lVar14 + 0x40));
        }
      }
    }
    if ((*(char *)(lVar2 + 0x715) != '\0') || (*(char *)(lVar2 + 0x716) != '\0')) {
      if (*(uint *)(lVar2 + 0x88) < 0x10001) {
        if (((*(char *)(lVar2 + 0x716) == '\0') || ((*(uint *)(lVar2 + 0x84) & 0x200) != 0)) ||
           ((*(char *)(lVar2 + 0x7a9) != '\0' && (*(char *)(lVar2 + 0x748) == '\0')))) {
          if ((*(uint *)(lVar2 + 0x84) & 8) != 0) {
            *(undefined4 *)(lVar2 + 0x718) = 0x20000;
          }
        }
        else {
          *(undefined4 *)(lVar2 + 0x718) = 0x80000;
        }
      }
      else {
        *(uint *)(lVar2 + 0x718) = *(uint *)(lVar2 + 0x88);
      }
      *(uint *)(lVar2 + 0x71c) =
           ((*(uint *)(lVar2 + 0x718) & 0xfff) != 0) + 1 + (*(uint *)(lVar2 + 0x718) >> 0xc);
    }
    cVar4 = USBSTOR_IsDeviceAsyncCapable(lVar2);
    if (cVar4 != '\0') {
      USBSTOR_QueueAsyncNotification(param_1,lVar2);
    }
    if (*(char *)(lVar2 + 0x78c) == '\0') {
      iVar8 = USBSTOR_WmiRegister(lVar2);
      if (iVar8 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
                   &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar8);
        }
        iVar8 = 0;
      }
      goto LAB_140001e6b;
    }
  }
  uVar7 = 0;
  bVar6 = KeGetCurrentIrql();
  if (bVar6 < 2) {
    uVar7 = KfRaiseIrql(2);
  }
  if (*(char *)(param_1 + 0xc0) != '\0') {
    local_148 = 0;
    uStack_140 = 0;
    local_138 = 0;
    if (DAT_14001a1a8 != (undefined4 *)0x0) {
      KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_148);
      *DAT_14001a1b0 = 0x504e5349;
      *(longlong *)(DAT_14001a1b0 + 2) = param_1;
      *(undefined8 *)(DAT_14001a1b0 + 4) = 0;
      *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
      if (DAT_14001a1b0 <= DAT_14001a1a8) {
        DAT_14001a1b0 = DAT_14001a1b8;
      }
      DAT_14001a1b0 = DAT_14001a1b0 + -8;
      KeReleaseInStackQueuedSpinLock(&local_148);
    }
    IoStartNextPacket(param_1,1);
  }
  if (bVar6 < 2) {
    KeLowerIrql(uVar7);
  }
  *(undefined1 *)(lVar2 + 0x78c) = 0;
LAB_140001f55:
  *(int *)(param_2 + 0x30) = iVar8;
  IofCompleteRequest(param_2,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar8);
  }
  local_148 = 0;
  uStack_140 = 0;
  local_138 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_148);
    *DAT_14001a1b0 = 0x74727473;
    *(longlong *)(DAT_14001a1b0 + 2) = (longlong)iVar8;
    *(undefined8 *)(DAT_14001a1b0 + 4) = 0;
    *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_148);
  }
  return iVar8;
}



===== USBSTOR_QueueWorkItem @ 140002618 =====

void USBSTOR_QueueWorkItem
               (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,char param_6)

{
  char cVar1;
  uint uVar2;
  
  if (param_6 == '\0') {
    cVar1 = IoTryQueueWorkItem(param_2,param_3,0,param_5);
    if (cVar1 != '\0') {
      return;
    }
    if ((EmergencyWorkerThread != 0) && (uVar2 = IoSizeofWorkItem(), 0x27 < uVar2)) {
      ObfReferenceObject(param_1);
      *(undefined8 *)(param_2 + 0x18) = param_1;
      *(undefined8 *)(param_2 + 0x10) = param_3;
      *(undefined8 *)(param_2 + 0x20) = param_5;
      *(longlong *)(param_2 + 8) = param_2;
      *(longlong *)param_2 = param_2;
      KeInsertQueue(&EmergencyWorkQueue,param_2);
      return;
    }
  }
  IoQueueWorkItemEx(param_2,param_3,0,param_5);
  return;
}



===== USBSTOR_EnableIdlePower @ 1400026ec =====

undefined4 USBSTOR_EnableIdlePower(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10) + 0x40);
  lVar3 = param_2;
  uVar1 = USBSTOR_IsSelectiveSuspendEnabled(lVar2);
  if ((char)uVar1 == '\0') {
    uVar4 = 0xc00000bb;
  }
  else {
    uVar1 = (ulonglong)*(uint *)(*(longlong *)(lVar3 + 0x18) + 0xc);
    if (uVar1 < 5000) {
      uVar1 = 5000;
    }
    PoFxSetDeviceIdleTimeout(*(undefined8 *)(lVar2 + 0x7b0),uVar1 * 10000);
  }
  *(undefined4 *)(param_2 + 0x30) = uVar4;
  IofCompleteRequest(param_2,0);
  return uVar4;
}



===== USBSTOR_IsSelectiveSuspendEnabled @ 140002770 =====

ulonglong USBSTOR_IsSelectiveSuspendEnabled(longlong param_1)

{
  uint uVar1;
  uint7 uVar3;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)*(byte *)(param_1 + 0x7f9);
  if (*(byte *)(param_1 + 0x7f9) == 0xff) {
    uVar1 = *(uint *)(param_1 + 0x84);
    uVar3 = (uint7)(uint3)(uVar1 >> 8);
    if (((char)uVar1 < '\0') && ((uVar1 >> 10 & 1) == 0)) {
      return CONCAT71(uVar3,1);
    }
    uVar2 = (ulonglong)uVar3 << 8;
  }
  return uVar2;
}



===== USBSTOR_PdoStartDevice @ 14000279c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int USBSTOR_PdoStartDevice(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  int iVar7;
  undefined *puVar8;
  undefined1 auStack_98 [32];
  undefined4 local_78;
  int *local_70;
  int local_68 [2];
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  char local_3c;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  iVar7 = 0;
  local_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x77,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  puVar8 = (undefined *)0x0;
  USBSTOR_LogEntry(0x52545350,param_2,0,0);
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar4 = *(longlong *)(*(longlong *)(lVar1 + 0x10) + 0x40);
  if (((lVar1 != -0x48) && ((*(uint *)(lVar4 + 0x84) & 0x40) == 0)) &&
     (*(char *)(lVar1 + 0x49) < '\0')) {
    *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) | 1;
  }
  UsbQueueUnFreeze(lVar1 + 0x170);
  *(undefined4 *)(lVar1 + 0x28) = 3;
  lVar5 = lVar4;
  uVar3 = USBSTOR_IsSelectiveSuspendEnabled(lVar4);
  if (((char)uVar3 != '\0') && (*(longlong *)(lVar4 + 0x7b0) == 0)) {
    USBSTOR_EnableRuntimePowerManagement(lVar5);
  }
  if (*(longlong *)(lVar1 + 0x2d8) == 0) {
    lVar4 = IoAllocateWorkItem(param_1);
    *(longlong *)(lVar1 + 0x2d8) = lVar4;
    if (lVar4 == 0) {
      iVar7 = -0x3fffff66;
      goto LAB_14000292a;
    }
  }
  *(undefined1 *)(lVar1 + 0x330) = 0;
  puVar8 = (undefined *)0x20019;
  iVar2 = IoOpenDeviceRegistryKey(param_1);
  if (-1 < iVar2) {
    local_68[0] = 0;
    RtlInitUnicodeString(&local_58,L"EnableLogoETW");
    local_70 = local_68;
    puVar8 = (undefined *)0x2;
    local_78 = 0x14;
    iVar2 = ZwQueryValueKey(local_60);
    if ((-1 < iVar2) && (local_68[0] != 0)) {
      *(bool *)(lVar1 + 0x330) = local_3c != '\0';
    }
  }
LAB_14000292a:
  uVar6 = 0;
  *(int *)(param_2 + 0x30) = iVar7;
  IofCompleteRequest(param_2);
  UsbQueueRestart(param_1,uVar6,puVar8);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x78,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar7);
  }
  USBSTOR_LogEntry(0x72747370,(longlong)iVar7,0,0);
  return iVar7;
}



===== USBSTOR_InterruptDataCompletionRoutine @ 1400029c0 =====

undefined4 USBSTOR_InterruptDataCompletionRoutine(longlong param_1,undefined *param_2)

{
  int *piVar1;
  longlong lVar2;
  bool bVar3;
  undefined8 *puVar4;
  int *piVar5;
  int *piVar6;
  longlong lVar7;
  undefined4 uVar8;
  undefined4 local_res8 [2];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  local_res8[0] = 0;
  local_48 = 0;
  piVar6 = (int *)0x0;
  local_58 = 0;
  uStack_50 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6e,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  USBSTOR_LogEntry(0x52434449,param_1,param_2,(longlong)*(int *)(param_2 + 0x30));
  piVar1 = *(int **)(param_1 + 0x40);
  if (*piVar1 == 0x214f4450) {
    piVar5 = *(int **)(*(longlong *)(piVar1 + 4) + 0x40);
    piVar6 = piVar1;
    lVar7 = *(longlong *)(piVar1 + 4);
  }
  else {
    piVar5 = (int *)0x0;
    lVar7 = 0;
    if (*piVar1 == 0x214f4446) {
      piVar5 = piVar1;
      lVar7 = param_1;
    }
  }
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  bVar3 = USBSTOR_CheckRequestTimeOut(lVar7,(longlong)param_2,lVar2,local_res8);
  if (bVar3) {
    USBSTOR_LogEntry(0x31636469,lVar7,param_2,lVar2);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6f,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    }
  }
  else {
    if (*(int *)(param_2 + 0x30) < 0) {
      USBSTOR_LogEntry(0x32636469,(longlong)*(int *)(param_2 + 0x30),(longlong)piVar5[99],0);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x70,
                  &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,*(undefined4 *)(param_2 + 0x30),
                  (char)piVar5[99]);
      }
      *(undefined8 *)(param_2 + 0x38) = 0;
      uVar8 = 0xc0000185;
      *(undefined4 *)(param_2 + 0x30) = 0xc0000185;
      *(undefined1 *)(lVar2 + 3) = 0xe;
      USBSTOR_TranslateCDBComplete(lVar7,(longlong)param_2,lVar2);
      USBSTOR_QueueResetDevice(lVar7,piVar6);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x71,
                &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
      }
    }
    else {
      if ((((short)piVar5[0x12a] == 0) || (*(char *)(lVar2 + 0x48) == '\x12')) ||
         (*(char *)(lVar2 + 0x48) == '\x03')) {
        if ((piVar5[0x21] & 1U) != 0) {
          KeAcquireInStackQueuedSpinLock(piVar5 + 0x24,&local_58);
          piVar5[0x20] = piVar5[0x20] | 4;
          KeReleaseInStackQueuedSpinLock(&local_58);
        }
        *(undefined4 *)(param_2 + 0x30) = 0;
        USBSTOR_TranslateCDBComplete(lVar7,(longlong)param_2,lVar2);
        *(ulonglong *)(param_2 + 0x38) = (ulonglong)*(uint *)(lVar2 + 0x10);
        USBSTOR_LogEntry(0x35636469,lVar7,param_2,lVar2);
        puVar4 = &local_40;
        local_40 = 0;
        uStack_38 = 0;
        local_30 = 0;
        KeAcquireInStackQueuedSpinLock(piVar5 + 0x24);
        piVar5[0x20] = piVar5[0x20] & 0xffffffdf;
        KeReleaseInStackQueuedSpinLock(&local_40);
        UsbStorPumpNextRequest((longlong)piVar6,puVar4,param_2);
        UsbStorStartNextPacket(lVar7);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x72,
                   &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,0);
        }
        return 0;
      }
      *(undefined2 *)(lVar2 + 3) = 0x204;
      *(undefined4 *)(lVar2 + 0x10) = 0;
      if ((((*(uint *)(lVar2 + 0xc) & 0x20) == 0) && (*(char *)(lVar2 + 0xb) != '\0')) &&
         (*(longlong *)(lVar2 + 0x20) != 0)) {
        USBSTOR_LogEntry(0x33636469,lVar7,param_2,lVar2);
        uVar8 = 0xc0000016;
      }
      else {
        USBSTOR_LogEntry(0x34636469,lVar7,param_2,lVar2);
        uVar8 = 0xc0000185;
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000185;
        KeAcquireInStackQueuedSpinLock(piVar5 + 0x24,&local_58);
        piVar5[0x20] = piVar5[0x20] | 4;
        KeReleaseInStackQueuedSpinLock(&local_58);
        USBSTOR_TranslateCDBComplete(lVar7,(longlong)param_2,lVar2);
      }
      USBSTOR_QueueResetPipe(lVar7,piVar6);
    }
    local_res8[0] = uVar8;
  }
  return local_res8[0];
}



===== USBSTOR_ClientCdbCompletion @ 140002d90 =====

int USBSTOR_ClientCdbCompletion(longlong param_1,longlong param_2)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  undefined8 *puVar4;
  int iVar5;
  longlong lVar6;
  undefined *puVar7;
  int *piVar8;
  int *piVar9;
  int local_res8 [2];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  iVar5 = 0;
  local_res8[0] = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  piVar8 = (int *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x60,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  USBSTOR_LogEntry(0x43424443,param_1,param_2,(longlong)*(int *)(param_2 + 0x30));
  piVar1 = *(int **)(param_1 + 0x40);
  if (*piVar1 == 0x214f4450) {
    lVar6 = *(longlong *)(piVar1 + 4);
    piVar8 = piVar1;
    piVar9 = *(int **)(*(longlong *)(piVar1 + 4) + 0x40);
  }
  else {
    lVar6 = 0;
    piVar9 = (int *)0x0;
    if (*piVar1 == 0x214f4446) {
      lVar6 = param_1;
      piVar9 = piVar1;
    }
  }
  puVar7 = *(undefined **)(*(longlong *)(param_2 + 0xb8) + 8);
  bVar2 = USBSTOR_CheckRequestTimeOut(lVar6,param_2,puVar7,local_res8);
  if (bVar2) {
    USBSTOR_LogEntry(0x31626463,lVar6,param_2,puVar7);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x61,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    }
    return local_res8[0];
  }
  if (*(int *)(param_2 + 0x30) < 0) {
    USBSTOR_LogEntry(0x32626463,(longlong)*(int *)(param_2 + 0x30),(longlong)piVar9[99],0);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x62,
                &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,*(undefined4 *)(param_2 + 0x30),
                (char)piVar9[99]);
    }
    if ((piVar9[99] & 0xfffffffU) == 4) {
      *(undefined2 *)(puVar7 + 3) = 0x204;
      *(undefined4 *)(puVar7 + 0x10) = 0;
      if ((((*(uint *)(puVar7 + 0xc) & 0x20) == 0) && (puVar7[0xb] != '\0')) &&
         (*(longlong *)(puVar7 + 0x20) != 0)) {
        USBSTOR_LogEntry(0x33626463,lVar6,param_2,puVar7);
        USBSTOR_IssueRequestSenseCdb(lVar6,param_2,0);
        return -0x3fffffea;
      }
      USBSTOR_LogEntry(0x34626463,lVar6,param_2,puVar7);
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(undefined4 *)(param_2 + 0x30) = 0xc0000185;
      KeAcquireInStackQueuedSpinLock(piVar9 + 0x24,&local_58);
      piVar9[0x20] = piVar9[0x20] | 4;
      KeReleaseInStackQueuedSpinLock(&local_58);
      USBSTOR_TranslateCDBComplete(lVar6,param_2,(longlong)puVar7);
      puVar4 = (undefined8 *)0x0;
      USBSTOR_SetSrbPending((longlong)piVar9,'\0');
      UsbStorPumpNextRequest((longlong)piVar8,puVar4,puVar7);
      UsbStorStartNextPacket(lVar6);
    }
    else {
      USBSTOR_LogEntry(0x35626463,lVar6,param_2,puVar7);
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(undefined4 *)(param_2 + 0x30) = 0xc0000185;
      puVar7[3] = 0xe;
      USBSTOR_TranslateCDBComplete(lVar6,param_2,(longlong)puVar7);
      USBSTOR_QueueResetDevice(lVar6,piVar8);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),99,
                &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
      }
    }
    return -0x3ffffe7b;
  }
  if (*(longlong *)(param_2 + 8) == 0) {
    if (*(longlong *)(piVar9 + 0x1c) == 0) {
      USBSTOR_LogEntry(0x38626463,lVar6,param_2,puVar7);
      *(undefined4 *)(param_2 + 0x30) = 0;
      *(undefined8 *)(param_2 + 0x38) = 0;
      puVar7[3] = 1;
      iVar3 = 0;
      USBSTOR_TranslateCDBComplete(lVar6,param_2,(longlong)puVar7);
      puVar4 = &local_40;
      local_40 = 0;
      uStack_38 = 0;
      local_30 = 0;
      KeAcquireInStackQueuedSpinLock(piVar9 + 0x24);
      piVar9[0x20] = piVar9[0x20] & 0xffffffdf;
      KeReleaseInStackQueuedSpinLock(&local_40);
      UsbStorPumpNextRequest((longlong)piVar8,puVar4,puVar7);
      UsbStorStartNextPacket(lVar6);
      goto LAB_14000316b;
    }
    USBSTOR_LogEntry(0x37626463,lVar6,param_2,puVar7);
    puVar7[3] = 1;
    USBSTOR_IssueInterruptRequest(lVar6,param_2);
  }
  else {
    USBSTOR_LogEntry(0x36626463,lVar6,param_2,puVar7);
    iVar3 = USBSTOR_IssueClientBulkRequest(lVar6,param_2);
    if (iVar3 < 0) {
      *(int *)(param_2 + 0x30) = iVar3;
      *(undefined8 *)(param_2 + 0x38) = 0;
      puVar7[3] = 4;
      USBSTOR_TranslateCDBComplete(lVar6,param_2,(longlong)puVar7);
      USBSTOR_QueueResetDevice(lVar6,piVar8);
      iVar5 = iVar3;
      goto LAB_14000316b;
    }
  }
  iVar5 = -0x3fffffea;
  iVar3 = -0x3fffffea;
LAB_14000316b:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),100,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar3);
  }
  return iVar5;
}



===== USBSTOR_SenseDataCompletionRoutine @ 1400031d0 =====

undefined4 USBSTOR_SenseDataCompletionRoutine(longlong param_1,undefined *param_2,longlong param_3)

{
  int iVar1;
  int *piVar2;
  longlong lVar3;
  uint uVar4;
  bool bVar5;
  undefined4 uVar6;
  int *piVar7;
  int *piVar8;
  longlong lVar9;
  undefined4 local_res8 [2];
  
  piVar8 = (int *)0x0;
  local_res8[0] = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7a,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  USBSTOR_LogEntry(0x52434453,param_1,param_2,(longlong)*(int *)(param_2 + 0x30));
  piVar2 = *(int **)(param_1 + 0x40);
  if (*piVar2 == 0x214f4450) {
    piVar7 = *(int **)(*(longlong *)(piVar2 + 4) + 0x40);
    piVar8 = piVar2;
    lVar9 = *(longlong *)(piVar2 + 4);
  }
  else {
    piVar7 = (int *)0x0;
    lVar9 = 0;
    if (*piVar2 == 0x214f4446) {
      piVar7 = piVar2;
      lVar9 = param_1;
    }
  }
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  bVar5 = USBSTOR_CheckRequestTimeOut(lVar9,(longlong)param_2,lVar3,local_res8);
  if (bVar5) {
    USBSTOR_LogEntry(0x31636473,lVar9,param_2,lVar3);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7b,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    }
  }
  else {
    iVar1 = *(int *)(param_2 + 0x30);
    if (iVar1 < 0) {
      USBSTOR_LogEntry(0x32636473,(longlong)iVar1,(longlong)piVar7[99],0);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7c,
                  &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,*(undefined4 *)(param_2 + 0x30),
                  (char)piVar7[99]);
      }
      *(undefined8 *)(param_2 + 0x38) = 0;
      uVar6 = 0xc0000185;
      *(undefined4 *)(param_2 + 0x30) = 0xc0000185;
      *(undefined1 *)(lVar3 + 3) = 0xe;
      USBSTOR_TranslateCDBComplete(lVar9,(longlong)param_2,lVar3);
      USBSTOR_QueueResetDevice(lVar9,piVar8);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7d,
                &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
      }
    }
    else {
      USBSTOR_LogEntry(0x33636473,(longlong)iVar1,(longlong)piVar7[99],(ulonglong)(uint)piVar7[0x6b]
                      );
      if (param_3 == 0) {
        uVar4 = 0x12;
        if ((uint)piVar7[0x6b] < 0x12) {
          uVar4 = piVar7[0x6b];
        }
        memmove((void *)((longlong)piVar7 + 0x4b6),*(void **)(piVar7 + 0x6c),(ulonglong)uVar4);
        *(char *)(lVar3 + 0xb) = (char)piVar7[0x6b];
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7e,
                   (ulonglong)*(byte *)((longlong)piVar7 + 0x4c2),*(byte *)(piVar7 + 0x12e) & 0xf,
                   *(byte *)((longlong)piVar7 + 0x4c2),*(undefined1 *)((longlong)piVar7 + 0x4c3));
      }
      if (*(longlong *)(piVar7 + 0x1c) == 0) {
        uVar6 = USBSTOR_ProcessRequestSenseCompletion(lVar9,param_2,param_3);
      }
      else {
        USBSTOR_IssueRequestSenseInterruptRequest(lVar9,(longlong)param_2,param_3);
        uVar6 = 0xc0000016;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7f,
                 &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,uVar6);
      }
    }
    local_res8[0] = uVar6;
  }
  return local_res8[0];
}



===== USBSTOR_CheckRequestTimeOut @ 1400034c0 =====

bool USBSTOR_CheckRequestTimeOut
               (longlong param_1,longlong param_2,undefined8 param_3,undefined4 *param_4)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeAcquireInStackQueuedSpinLock(lVar1 + 0x90,&local_28);
  *(uint *)(lVar1 + 0x80) = *(uint *)(lVar1 + 0x80) & 0xfffffffd;
  bVar3 = (*(uint *)(lVar1 + 0x80) & 8) != 0;
  if (bVar3) {
    USBSTOR_LogEntry(0x31545243,param_1,param_2,param_3);
    KeReleaseInStackQueuedSpinLock(&local_28);
    lVar2 = *(longlong *)(lVar1 + 0x490);
    *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8) = lVar2;
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc00000b5;
    *(undefined1 *)(lVar2 + 3) = 9;
    USBSTOR_TranslateCDBComplete(param_1,param_2,lVar2);
    *param_4 = 0xc0000016;
    KeSetEvent(lVar1 + 0x150,0,0);
  }
  else {
    *(undefined8 *)(lVar1 + 0x148) = 0;
    KeReleaseInStackQueuedSpinLock(&local_28);
  }
  return bVar3;
}



===== USBSTOR_ResetDeviceWorkItem @ 1400035e0 =====

void USBSTOR_ResetDeviceWorkItem(undefined8 *param_1,longlong param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  int iVar3;
  undefined8 *puVar4;
  uint uVar5;
  undefined *puVar6;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  USBSTOR_LogEntry(0x57445352,param_1,0,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xac,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  lVar1 = param_1[8];
  iVar3 = 0;
  if (*(longlong *)(lVar1 + 0x148) != 0) {
    USBSTOR_LogEntry(0x31647372,param_1,*(longlong *)(lVar1 + 0x148),0);
    IoCancelIrp(*(undefined8 *)(lVar1 + 0x148));
    KeWaitForSingleObject(lVar1 + 0x150,0,0,0,0);
    USBSTOR_LogEntry(0x32647372,param_1,*(undefined8 *)(lVar1 + 0x148),0);
    if (param_2 == 0) {
      param_2 = *(longlong *)(*(longlong *)(*(longlong *)(lVar1 + 0x148) + 0xb8) + 0x10);
    }
    uVar2 = KfRaiseIrql(2);
    IofCompleteRequest(*(undefined8 *)(lVar1 + 0x148),0);
    KeLowerIrql(uVar2);
    *(undefined8 *)(lVar1 + 0x148) = 0;
  }
  uVar5 = 0;
  do {
    if (2 < uVar5) {
LAB_140003841:
      KeAcquireInStackQueuedSpinLock(lVar1 + 0x90,&local_48);
      *(uint *)(lVar1 + 0x80) = *(uint *)(lVar1 + 0x80) & 0xfffffff7;
      if (iVar3 < 0) {
        USBSTOR_LogEntry(0x34647372,param_1,0,0);
        *(uint *)(lVar1 + 0x80) = *(uint *)(lVar1 + 0x80) | 0x10;
      }
      KeReleaseInStackQueuedSpinLock(&local_48);
      if (*(int *)(lVar1 + 0x78) == 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb0,
                  &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
        }
        *(undefined4 *)(lVar1 + 0x78) = 1;
      }
      local_30 = 0;
      uStack_28 = 0;
      local_20 = 0;
      KeAcquireInStackQueuedSpinLock(lVar1 + 0x90,&local_30);
      *(uint *)(lVar1 + 0x80) = *(uint *)(lVar1 + 0x80) & 0xffffffdf;
      KeReleaseInStackQueuedSpinLock(&local_30);
      if (param_2 != 0) {
        puVar6 = (undefined *)0x0;
        puVar4 = param_1;
        USBSTOR_LogEntry(0x35647372,param_1,0,0);
        UsbStorPumpNextRequest(param_2,puVar4,puVar6);
      }
      UsbStorStartNextPacket((longlong)param_1);
      IoReleaseRemoveLockEx(lVar1 + 0x728,USBSTOR_ResetDeviceWorkItem,0x20);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb1,
                 &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar3);
      }
      return;
    }
    if ((param_2 == 0) || (*(int *)(param_2 + 0x28) != 5)) {
      if ((*(char *)(lVar1 + 0x754) == '\0') &&
         (iVar3 = USBSTOR_IsDeviceConnected((longlong)param_1), iVar3 < 0)) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xae,
                   &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,uVar5);
        }
        goto LAB_140003841;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xaf,
                 &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,uVar5);
      }
      iVar3 = USBSTOR_ResetDevice(param_1,*(undefined1 *)(lVar1 + 0x754));
      if (-1 < iVar3) {
        USBSTOR_LogEntry(0x33647372,param_1,0,0);
        goto LAB_140003841;
      }
    }
    else {
      KeDelayExecutionThread(0,0);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xad,
                 &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,uVar5);
      }
      iVar3 = -0x3fffffff;
    }
    uVar5 = uVar5 + 1;
  } while( true );
}



===== USBSTOR_FdoSetPowerD0Completion @ 1400039b0 =====

int USBSTOR_FdoSetPowerD0Completion(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  char cVar5;
  char *pcVar6;
  undefined *puVar7;
  
  lVar4 = *(longlong *)(param_1 + 0x40);
  iVar2 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  iVar3 = *(int *)(param_2 + 0x30);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar7 = WPP_GLOBAL_Control;
    pcVar6 = PowerDeviceStateString(iVar2);
    WPP_SF_qqsD(*(undefined8 *)(puVar7 + 0x18),0x28,puVar7,param_1,(char)param_2,pcVar6,(char)iVar3)
    ;
  }
  USBSTOR_LogEntry(0x63307366,param_1,(longlong)iVar2,(longlong)iVar3);
  cVar5 = USBSTOR_IsDeviceAsyncCapable(lVar4);
  if (cVar5 != '\0') {
    USBSTOR_QueueAsyncNotification(param_1,lVar4);
  }
  UsbStorStartNextPacket(param_1);
  PoStartNextPowerIrp(param_2);
  return iVar3;
}



===== USBSTOR_IsDeviceAsyncCapable @ 140003a9c =====

undefined1 USBSTOR_IsDeviceAsyncCapable(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = 0;
  if (((*(longlong *)(param_1 + 0x70) != 0) && (*(int *)(param_1 + 0x78) == 1)) &&
     (uVar1 = 0, (*(byte *)(*(longlong *)(param_1 + 0x38) + 7) & 0x20) != 0)) {
    uVar1 = 1;
  }
  return uVar1;
}



===== IsRequestValid @ 140003ad0 =====

char IsRequestValid(longlong param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  bool bVar2;
  uint uVar3;
  undefined8 *puVar4;
  int *piVar5;
  int *piVar6;
  
  piVar6 = *(int **)(param_1 + 0x40);
  piVar5 = (int *)0x0;
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (*piVar6 == 0x214f4450) {
    piVar5 = piVar6;
    piVar6 = *(int **)(*(longlong *)(piVar6 + 4) + 0x40);
  }
  else if (*piVar6 != 0x214f4446) goto LAB_140003c2f;
  uVar3 = *(uint *)(lVar1 + 0xc) & 0xc0;
  if (uVar3 == 0) {
    if ((*(int *)(lVar1 + 0x10) != 0) || (*(longlong *)(lVar1 + 0x18) != 0)) goto LAB_140003c2f;
  }
  else if ((uVar3 == 0xc0) ||
          (((*(uint *)(lVar1 + 0x10) == 0 || ((uint)piVar6[0x1c6] < *(uint *)(lVar1 + 0x10))) ||
           (*(longlong *)(param_2 + 8) == 0)))) goto LAB_140003c2f;
  if (*(char *)(lVar1 + 0x48) == '\x12') {
    if ((*(byte *)(lVar1 + 0x49) & 1) == 0) {
      return '\x01';
    }
    if ((piVar6[0x21] & 0x100U) == 0) {
      if ((*(char *)(lVar1 + 0x4a) != '\0') && (*(char *)(lVar1 + 0x4a) != -0x71)) {
        return '\x01';
      }
      if ((char)piVar6[0x1ea] != '\0') {
        return (char)piVar6[0x1ea];
      }
    }
    puVar4 = *(undefined8 **)(lVar1 + 0x20);
    if (*(byte *)(lVar1 + 0xb) < 0x12) goto LAB_140003c2f;
    *puVar4 = 0;
    puVar4[1] = 0;
    *(undefined2 *)(puVar4 + 2) = 0;
    *(undefined1 *)((longlong)puVar4 + 0xc) = 0x24;
  }
  else {
    if (*(char *)(lVar1 + 0x48) != -0x62) {
      return '\x01';
    }
    if ((*(byte *)(lVar1 + 0x49) & 0x1f) != 0x10) {
      return '\x01';
    }
    if (piVar5 == (int *)0x0) {
      return '\x01';
    }
    bVar2 = USBSTOR_UseReadCapacity16(param_1);
    if (bVar2) {
      return '\x01';
    }
    if ((char)piVar6[0x1ea] != '\0') {
      return (char)piVar6[0x1ea];
    }
    puVar4 = *(undefined8 **)(lVar1 + 0x20);
    if (*(byte *)(lVar1 + 0xb) < 0x12) goto LAB_140003c2f;
    *puVar4 = 0;
    puVar4[1] = 0;
    *(undefined2 *)(puVar4 + 2) = 0;
    *(undefined1 *)((longlong)puVar4 + 0xc) = 0x20;
  }
  *(byte *)((longlong)puVar4 + 2) = *(byte *)((longlong)puVar4 + 2) & 0xf5 | 5;
  *(undefined1 *)((longlong)puVar4 + 7) = 10;
  *(undefined1 *)puVar4 = 0x70;
  *(undefined2 *)(lVar1 + 3) = 0x284;
  *(undefined1 *)(lVar1 + 0xb) = 0x12;
  *(undefined4 *)(lVar1 + 0x10) = 0;
LAB_140003c2f:
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_DDqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),piVar5,param_3,
                  *(undefined4 *)(lVar1 + 0xc),(char)*(undefined4 *)(lVar1 + 0x10),
                  (char)*(undefined8 *)(lVar1 + 0x18),(char)*(undefined8 *)(param_2 + 8));
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
                &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,param_2,(char)lVar1);
    }
  }
  return '\0';
}



===== UsbQueueRestart @ 140003cc8 =====

void UsbQueueRestart(longlong param_1,undefined8 param_2,undefined *param_3)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  puVar4 = &local_28;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  lVar3 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x40);
  KeAcquireInStackQueuedSpinLock(lVar3 + 0x90);
  uVar1 = *(uint *)(lVar3 + 0x80);
  KeReleaseInStackQueuedSpinLock(&local_28);
  if ((uVar1 & 8) == 0) {
    UsbStorPumpNextRequest(lVar2,puVar4,param_3);
  }
  return;
}



===== USBSTOR_PdoQuiesceDevice @ 140003d3c =====

undefined8 USBSTOR_PdoQuiesceDevice(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar3 = *(longlong *)(*(longlong *)(lVar2 + 0x10) + 0x40);
  uVar4 = IoAcquireRemoveLockEx(lVar2 + 0x2e0,USBSTOR_QuiesceDeviceWorkItem,"",1,0x20);
  if (-1 < (int)uVar4) {
    uVar4 = 0;
    USBSTOR_LogEntry(0x44515150,param_1,0,0);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7f,
              &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
    }
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    *(longlong *)(lVar2 + 0x2b0) = lVar2 + 0x170;
    *(longlong *)(lVar2 + 0x2a8) = param_2;
    USBSTOR_QueueWorkItem
              (param_1,*(longlong *)(lVar2 + 0x2d8),USBSTOR_QuiesceDeviceWorkItem,uVar4,
               (longlong *)(lVar2 + 0x2a8),*(char *)(lVar3 + 0x754) == '\0');
    uVar4 = 0x103;
  }
  return uVar4;
}



===== UsbQueueRelease @ 140003e50 =====

longlong * UsbQueueRelease(uint *param_1,undefined8 param_2,undefined *param_3)

{
  uint uVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong local_28 [4];
  
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  plVar2 = (longlong *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    param_3 = &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
            &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
  }
  plVar3 = local_28;
  KeAcquireInStackQueuedSpinLock(param_1 + 0x48);
  *(undefined1 *)(param_1 + 0x4c) = 0;
  if ((int)param_1[0x4b] < (int)param_1[0x4a]) {
    plVar2 = UsbDequeueIrp(param_1,plVar3,param_3);
    if (plVar2 != (longlong *)0x0) {
      uVar1 = param_1[0x4b];
      param_1[0x4b] = uVar1 + 1;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                 &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids,uVar1 + 1);
      }
      USBSTOR_LogEntry(0x736c6552,param_1,plVar2,(longlong)(int)param_1[0x4b]);
    }
  }
  KeReleaseInStackQueuedSpinLock(local_28);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
             &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids,plVar2);
  }
  return plVar2;
}



===== UsbQueueUnFreeze @ 140003f98 =====

void UsbQueueUnFreeze(longlong param_1)

{
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
            &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
  }
  KeAcquireInStackQueuedSpinLock(param_1 + 0x120,&local_28);
  *(undefined1 *)(param_1 + 0x130) = 0;
  KeReleaseInStackQueuedSpinLock(&local_28);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
            &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
  }
  return;
}



===== UsbStorStartNextPacket @ 140004060 =====

void UsbStorStartNextPacket(longlong param_1)

{
  byte bVar1;
  undefined1 uVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar2 = 0;
  bVar1 = KeGetCurrentIrql();
  if (bVar1 < 2) {
    uVar2 = KfRaiseIrql(2);
  }
  if (*(char *)(param_1 + 0xc0) != '\0') {
    local_28 = 0;
    uStack_20 = 0;
    local_18 = 0;
    if (DAT_14001a1a8 != (undefined4 *)0x0) {
      KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_28);
      *DAT_14001a1b0 = 0x504e5349;
      *(longlong *)(DAT_14001a1b0 + 2) = param_1;
      *(undefined8 *)(DAT_14001a1b0 + 4) = 0;
      *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
      if (DAT_14001a1b0 <= DAT_14001a1a8) {
        DAT_14001a1b0 = DAT_14001a1b8;
      }
      DAT_14001a1b0 = DAT_14001a1b0 + -8;
      KeReleaseInStackQueuedSpinLock(&local_28);
    }
    IoStartNextPacket(param_1,1);
  }
  if (bVar1 < 2) {
    KeLowerIrql(uVar2);
  }
  return;
}



===== USBSTOR_ClaimCurrentSrb @ 14000418c =====

bool USBSTOR_ClaimCurrentSrb(longlong param_1)

{
  bool bVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeAcquireInStackQueuedSpinLock(param_1 + 0x90,&local_28);
  bVar1 = (*(uint *)(param_1 + 0x80) & 0x20) == 0;
  if (bVar1) {
    *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) | 0x20;
  }
  KeReleaseInStackQueuedSpinLock(&local_28);
  return bVar1;
}



===== UsbQueueFreeze @ 1400041fc =====

void UsbQueueFreeze(longlong param_1)

{
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
  }
  KeAcquireInStackQueuedSpinLock(param_1 + 0x120,&local_28);
  *(undefined1 *)(param_1 + 0x130) = 1;
  KeReleaseInStackQueuedSpinLock(&local_28);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
            &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
  }
  return;
}



===== UsbQueueFlush @ 1400042c4 =====

void UsbQueueFlush(longlong param_1,uint *param_2,undefined *param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  longlong *plVar3;
  undefined *puVar4;
  longlong ****pppplVar5;
  longlong ****pppplVar6;
  undefined1 *puVar7;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  longlong ****local_38;
  longlong ****local_30;
  longlong ***local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = (longlong ***)0x0;
  uStack_20 = 0;
  local_18 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    param_3 = &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
            &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
  }
  puVar7 = auStack_58;
  local_30 = (longlong ****)&local_38;
  local_38 = (longlong ****)&local_38;
  pppplVar5 = &local_28;
  KeAcquireInStackQueuedSpinLock(param_2 + 0x48);
  *(undefined1 *)(param_2 + 0x4c) = 0;
  while (plVar3 = UsbDequeueIrp(param_2,(longlong *)pppplVar5,param_3), plVar3 != (longlong *)0x0) {
    pppplVar6 = (longlong ****)(plVar3 + 0x15);
    if ((longlong *****)*local_30 != &local_38) goto LAB_140004413;
    plVar3[0x16] = (longlong)local_30;
    pppplVar5 = (longlong ****)&local_38;
    *pppplVar6 = (longlong ***)pppplVar5;
    *local_30 = (longlong ***)pppplVar6;
    local_30 = pppplVar6;
  }
  KeReleaseInStackQueuedSpinLock(&local_28);
  while ((longlong *****)local_38 != &local_38) {
    if (((longlong *****)local_38[1] != &local_38) ||
       (pppplVar5 = (longlong ****)*local_38, (longlong ****)pppplVar5[1] != local_38))
    goto LAB_140004413;
    pppplVar5[1] = (longlong ***)&local_38;
    pppplVar6 = local_38 + -0x15;
    local_38 = pppplVar5;
    UsbCompleteFlushedIrp(param_1,(longlong)pppplVar6);
  }
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return;
  }
  puVar4 = WPP_GLOBAL_Control;
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0) {
    return;
  }
LAB_14000441a:
  if (3 < (byte)puVar4[0x29]) {
    uVar1 = *(undefined8 *)(puVar4 + 0x18);
    *(undefined8 *)(puVar7 + -8) = 0x140004439;
    WPP_SF_(uVar1,0x1e,&WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
  }
  return;
LAB_140004413:
  puVar4 = (undefined *)0x3;
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)();
  puVar7 = auStack_50;
  goto LAB_14000441a;
}



===== USBSTOR_Scsi @ 140004450 =====

ulonglong USBSTOR_Scsi(undefined8 *param_1,undefined *param_2)

{
  uint uVar1;
  int *piVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  code *pcVar6;
  char cVar7;
  undefined1 uVar8;
  bool bVar9;
  byte bVar10;
  char cVar11;
  uint uVar12;
  longlong *plVar13;
  undefined *puVar14;
  undefined2 uVar15;
  IMAGE_DOS_HEADER *pIVar16;
  longlong ****pppplVar17;
  longlong ****pppplVar18;
  undefined8 *puVar19;
  int iVar20;
  ulonglong uVar21;
  undefined1 *puVar22;
  undefined1 *puVar23;
  undefined **ppuVar24;
  undefined **ppuVar25;
  longlong lVar26;
  undefined1 auStackY_98 [8];
  undefined1 auStackY_90 [24];
  longlong ****local_68;
  longlong ****local_60;
  longlong ***local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  uVar21 = 0xc000000d;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  puVar22 = auStackY_98;
  puVar23 = auStackY_98;
  piVar2 = (int *)param_1[8];
  if (*piVar2 != 0x214f4450) {
    local_58 = (longlong ***)0x0;
    uStack_50 = 0;
    lVar26 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
    local_48 = 0;
    bVar10 = *(byte *)(lVar26 + 2);
    if (DAT_14001a1a8 != (undefined4 *)0x0) {
      KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_58);
      *DAT_14001a1b0 = 0x49534353;
      *(undefined8 **)(DAT_14001a1b0 + 2) = param_1;
      *(undefined **)(DAT_14001a1b0 + 4) = param_2;
      *(ulonglong *)(DAT_14001a1b0 + 6) = (ulonglong)bVar10;
      if (DAT_14001a1b0 <= DAT_14001a1a8) {
        DAT_14001a1b0 = DAT_14001a1b8;
      }
      DAT_14001a1b0 = DAT_14001a1b0 + -8;
      KeReleaseInStackQueuedSpinLock(&local_58);
    }
    ppuVar25 = &WPP_GLOBAL_Control;
    if (*(char *)(lVar26 + 2) == '\0') {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        ppuVar25 = (undefined **)&WPP_e947f7dfdc8330b398201c2535585168_Traceguids;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,
                &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
      }
      cVar11 = IsRequestValid((longlong)param_1,(longlong)param_2,ppuVar25);
      if (cVar11 == '\0') goto LAB_140004acd;
      uVar12 = *(uint *)(lVar26 + 0xc);
      if (((uVar12 >> 0x14 & 1) == 0) || (uVar1 = piVar2[0x27], uVar1 == 1)) {
        *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) =
             *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) | 1;
        *(undefined1 *)(lVar26 + 3) = 0;
        USBSTOR_FxPowerReference((longlong)piVar2,lVar26,'\x01');
        IoStartPacket(param_1,param_2,lVar26 + 0x40,USBSTOR_CancelIo);
        uVar21 = 0x103;
        ppuVar25 = &WPP_GLOBAL_Control;
        puVar22 = auStackY_98;
        goto LAB_14000472b;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar15 = 0x46;
LAB_140004fc9:
        WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar15,(ulonglong)uVar1,uVar12,
                   (char)uVar1,*(undefined1 *)(lVar26 + 0x48));
      }
LAB_140004fe0:
      ppuVar25 = &WPP_GLOBAL_Control;
      uVar21 = 0xc0000001;
      *(undefined1 *)(lVar26 + 3) = 0x24;
      puVar23 = auStackY_98;
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,
                &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
      }
      uVar21 = 0xc00000bb;
      ppuVar25 = &WPP_GLOBAL_Control;
      puVar23 = auStackY_98;
    }
    goto LAB_1400049fd;
  }
  ppuVar25 = *(undefined ***)(*(longlong *)(piVar2 + 4) + 0x40);
  lVar3 = *(longlong *)(param_2 + 0xb8);
  lVar26 = *(longlong *)(lVar3 + 8);
  cVar11 = *(char *)((longlong)ppuVar25 + 0x7f9);
  if ((cVar11 == -1) &&
     ((-1 < (char)*(uint *)((longlong)ppuVar25 + 0x84) ||
      (cVar11 = '\x01', (*(uint *)((longlong)ppuVar25 + 0x84) >> 10 & 1) != 0)))) {
    cVar11 = '\0';
  }
  bVar10 = *(byte *)(lVar26 + 2);
  local_58 = (longlong ***)0x0;
  uStack_50 = 0;
  local_48 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_58);
    *DAT_14001a1b0 = 0x49534353;
    *(undefined8 **)(DAT_14001a1b0 + 2) = param_1;
    *(undefined **)(DAT_14001a1b0 + 4) = param_2;
    *(ulonglong *)(DAT_14001a1b0 + 6) = (ulonglong)bVar10;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_58);
  }
  ppuVar24 = &WPP_GLOBAL_Control;
  bVar10 = *(byte *)(lVar26 + 2);
  if (bVar10 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      ppuVar24 = (undefined **)&WPP_e947f7dfdc8330b398201c2535585168_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    }
    cVar7 = IsRequestValid((longlong)param_1,(longlong)param_2,ppuVar24);
    if (cVar7 == '\0') goto LAB_140004acd;
    iVar20 = 0;
    if (1 < piVar2[10] - 7U) {
      uVar12 = *(uint *)(lVar26 + 0xc);
      if ((uVar12 >> 0x14 & 1) != 0) {
        uVar1 = piVar2[0xc];
        if (uVar1 != 1) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar15 = 0x37;
            goto LAB_140004fc9;
          }
          goto LAB_140004fe0;
        }
        if ((char)piVar2[0xa8] != '\0') {
          uVar21 = 0xc0000001;
          *(undefined1 *)(lVar26 + 3) = 5;
          ppuVar25 = &WPP_GLOBAL_Control;
          puVar23 = auStackY_98;
          goto LAB_1400049fd;
        }
      }
      *(undefined1 *)(lVar26 + 3) = 0;
      if (*(char *)(lVar26 + 0x48) == '\x1a') {
        lVar4 = *(longlong *)(*(longlong *)(piVar2 + 4) + 0x40);
        cVar7 = KeGetCurrentIrql();
        if (cVar7 == '\0') {
          USBSTOR_GetWriteProtectSetting(lVar4);
        }
      }
      *(int **)(lVar3 + 0x10) = piVar2;
      if (cVar11 != '\0') {
        if (((*(uint *)(lVar26 + 0xc) & 0x80010) == 0) || ((char)piVar2[0xa8] == '\0')) {
          iVar20 = 0;
          if (*(int *)((longlong)ppuVar25 + 0x9c) == 4) {
            iVar20 = 2;
          }
        }
        else {
          bVar9 = USBSTOR_ClaimCurrentSrb((longlong)ppuVar25);
          if (!bVar9) {
            uVar21 = 0x80000011;
            *(undefined1 *)(lVar26 + 3) = 5;
            ppuVar25 = &WPP_GLOBAL_Control;
            puVar23 = auStackY_98;
            goto LAB_1400049fd;
          }
          iVar20 = 1;
        }
      }
      USBSTOR_FxPowerReference((longlong)ppuVar25,lVar26,'\x01');
      bVar9 = false;
      if (((*(char *)((longlong)ppuVar25 + 0x754) != '\0') &&
          ((*(uint *)(lVar26 + 0xc) & 0x40000000) != 0)) &&
         (bVar10 = KeGetCurrentIrql(), bVar10 < 2)) {
        KeEnterGuardedRegion();
        bVar9 = true;
      }
      uVar21 = (ulonglong)*(uint *)(lVar26 + 0x40);
      puVar14 = param_2;
      uVar12 = UsbQueueInsert((longlong)(piVar2 + 0x5c),(longlong)param_2,*(uint *)(lVar26 + 0x40),
                              iVar20);
      if ((char)uVar12 == '\0') {
        uVar5 = *(undefined8 *)(piVar2 + 4);
        local_58 = (longlong ***)0x0;
        uStack_50 = 0;
        local_48 = 0;
        if (DAT_14001a1a8 != (undefined4 *)0x0) {
          KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_58);
          *DAT_14001a1b0 = 0x50534f49;
          *(undefined8 **)(DAT_14001a1b0 + 2) = param_1;
          *(undefined **)(DAT_14001a1b0 + 4) = param_2;
          *(undefined8 *)(DAT_14001a1b0 + 6) = uVar5;
          if (DAT_14001a1b0 <= DAT_14001a1a8) {
            DAT_14001a1b0 = DAT_14001a1b8;
          }
          DAT_14001a1b0 = DAT_14001a1b0 + -8;
          KeReleaseInStackQueuedSpinLock(&local_58);
        }
        IoStartPacket(*(undefined8 *)(piVar2 + 4),param_2,lVar26 + 0x40,USBSTOR_CancelIo);
      }
      else {
        if (iVar20 == 1) {
          uVar5 = *(undefined8 *)(piVar2 + 4);
          local_58 = (longlong ***)0x0;
          uStack_50 = 0;
          local_48 = 0;
          if (DAT_14001a1a8 != (undefined4 *)0x0) {
            KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_58);
            *DAT_14001a1b0 = 0x32504251;
            *(undefined8 **)(DAT_14001a1b0 + 2) = param_1;
            *(undefined **)(DAT_14001a1b0 + 4) = param_2;
            *(undefined8 *)(DAT_14001a1b0 + 6) = uVar5;
            if (DAT_14001a1b0 <= DAT_14001a1a8) {
              DAT_14001a1b0 = DAT_14001a1b8;
            }
            DAT_14001a1b0 = DAT_14001a1b0 + -8;
            KeReleaseInStackQueuedSpinLock(&local_58);
          }
          *(undefined1 *)(lVar26 + 3) = 5;
          uVar21 = 0x80000011;
          USBSTOR_FxPowerReference((longlong)ppuVar25,lVar26,'\0');
          if (bVar9) {
            KeLeaveGuardedRegion();
          }
          goto LAB_140004acd;
        }
        if (((iVar20 == 2) && (((ulonglong)ppuVar25[0x10] & 0x10) != 0)) &&
           ((piVar2[0xa7] < piVar2[0xa6] && ((char)piVar2[0xa8] == '\0')))) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar14,uVar21,
                       *(undefined8 *)(piVar2 + 4),(char)piVar2 + 'p',(char)param_2);
          }
          puVar19 = param_1;
          puVar14 = param_2;
          USBSTOR_LogEntry(0x49584551,param_1,param_2,*(undefined8 *)(piVar2 + 4));
          UsbStorPumpNextRequest((longlong)piVar2,puVar19,puVar14);
          UsbStorStartNextPacket(*(longlong *)(piVar2 + 4));
        }
      }
      ppuVar25 = &WPP_GLOBAL_Control;
      if (bVar9) {
        KeLeaveGuardedRegion();
      }
      uVar21 = 0x103;
      puVar22 = auStackY_98;
      goto LAB_14000472b;
    }
    uVar21 = 0xc000000e;
    *(undefined1 *)(lVar26 + 3) = 8;
    ppuVar25 = &WPP_GLOBAL_Control;
    puVar23 = auStackY_98;
    goto LAB_1400049fd;
  }
  pIVar16 = &IMAGE_DOS_HEADER_140000000;
  switch(bVar10) {
  case 1:
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    }
    if ((char)piVar2[0x11] == '\0') {
      *(undefined1 *)(piVar2 + 0x11) = 1;
      *(undefined8 **)(lVar26 + 0x18) = param_1;
LAB_1400049dd:
      uVar21 = 0;
      goto LAB_1400049df;
    }
    uVar21 = 0x80000011;
    uVar8 = 5;
    goto LAB_1400049e1;
  default:
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,
               &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,(uint)bVar10);
    }
    uVar21 = 0xc00000bb;
    *(undefined1 *)(lVar26 + 3) = 4;
    ppuVar25 = &WPP_GLOBAL_Control;
    puVar23 = auStackY_98;
    goto LAB_1400049fd;
  case 4:
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      ppuVar24 = (undefined **)&WPP_e947f7dfdc8330b398201c2535585168_Traceguids;
      pIVar16 = (IMAGE_DOS_HEADER *)0x41;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x41,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    }
    plVar13 = UsbQueueRelease((uint *)(piVar2 + 0x5c),pIVar16,(undefined *)ppuVar24);
    if (plVar13 == (longlong *)0x0) {
LAB_140004c32:
      uVar21 = 0;
      *(undefined1 *)(lVar26 + 3) = 1;
    }
    else {
      IoStartPacket(*(undefined8 *)(piVar2 + 4),plVar13,*(longlong *)(plVar13[0x17] + 8) + 0x40,
                    USBSTOR_CancelIo);
      uVar21 = 0;
      *(undefined1 *)(lVar26 + 3) = 1;
    }
    break;
  case 6:
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    }
    *(undefined1 *)(piVar2 + 0x11) = 0;
    uVar21 = 0;
    *(undefined1 *)(lVar26 + 3) = 1;
    break;
  case 8:
switchD_1400048bf_caseD_8:
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 4))
    goto LAB_140004c32;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    uVar21 = 0;
    *(undefined1 *)(lVar26 + 3) = 1;
    break;
  case 0x15:
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    }
    ppuVar24 = &WPP_GLOBAL_Control;
    local_58 = (longlong ***)0x0;
    uStack_50 = 0;
    local_48 = 0;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      ppuVar24 = (undefined **)&WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
              &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
    }
    local_60 = (longlong ****)&local_68;
    local_68 = (longlong ****)&local_68;
    pppplVar17 = &local_58;
    KeAcquireInStackQueuedSpinLock(piVar2 + 0xa4);
    *(undefined1 *)(piVar2 + 0xa8) = 0;
    while (plVar13 = UsbDequeueIrp((uint *)(piVar2 + 0x5c),(longlong *)pppplVar17,
                                   (undefined *)ppuVar24), plVar13 != (longlong *)0x0) {
      pppplVar18 = (longlong ****)(plVar13 + 0x15);
      if ((longlong *****)*local_60 != &local_68) goto LAB_140005222;
      plVar13[0x16] = (longlong)local_60;
      pppplVar17 = (longlong ****)&local_68;
      *pppplVar18 = (longlong ***)pppplVar17;
      *local_60 = (longlong ***)pppplVar18;
      local_60 = pppplVar18;
    }
    KeReleaseInStackQueuedSpinLock(&local_58);
    while ((longlong *****)local_68 != &local_68) {
      if (((longlong *****)local_68[1] != &local_68) ||
         (pppplVar17 = (longlong ****)*local_68, (longlong ****)pppplVar17[1] != local_68))
      goto LAB_140005222;
      pppplVar17[1] = (longlong ***)&local_68;
      pppplVar18 = local_68 + -0x15;
      local_68 = pppplVar17;
      UsbCompleteFlushedIrp((longlong)param_1,(longlong)pppplVar18);
    }
    ppuVar25 = &WPP_GLOBAL_Control;
    puVar23 = auStackY_98;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (puVar14 = WPP_GLOBAL_Control, puVar23 = auStackY_98, puVar22 = auStackY_98,
       (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) goto LAB_140005229;
    goto LAB_14000497b;
  case 0x18:
    if (cVar11 != '\0') {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
                &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
      }
      USBSTOR_LogEntry(0x514c4653,param_1,param_2,(ulonglong)*(byte *)(lVar26 + 2));
      UsbQueueFreeze((longlong)(piVar2 + 0x5c));
      goto LAB_1400049dd;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar15 = 0x3a;
LAB_140004e47:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar15,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    }
LAB_140004e57:
    uVar21 = 0xc00000bb;
    uVar8 = 4;
    goto LAB_1400049e1;
  case 0x19:
    if (cVar11 == '\0') {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
                &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
      }
      *(undefined1 *)(lVar26 + 3) = 4;
      goto switchD_1400048bf_caseD_8;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    }
    puVar19 = param_1;
    puVar14 = param_2;
    USBSTOR_LogEntry(0x51554653,param_1,param_2,(ulonglong)*(byte *)(lVar26 + 2));
    UsbQueueUnFreeze((longlong)(piVar2 + 0x5c));
    if ((piVar2[0x5d] == 0) || (piVar2[0xc] != 1)) goto LAB_140004c32;
    UsbQueueRestart((longlong)param_1,puVar19,puVar14);
    uVar21 = 0;
    *(undefined1 *)(lVar26 + 3) = 1;
    break;
  case 0x1a:
    if (cVar11 == '\0') {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar15 = 0x3c;
        goto LAB_140004e47;
      }
      goto LAB_140004e57;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3b,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    }
    USBSTOR_LogEntry(0x44514653,param_1,param_2,(ulonglong)*(byte *)(lVar26 + 2));
    uVar21 = USBSTOR_PdoQuiesceDevice((longlong)param_1,(longlong)param_2);
    uVar21 = uVar21 & 0xffffffff;
LAB_1400049df:
    uVar8 = 1;
LAB_1400049e1:
    ppuVar25 = &WPP_GLOBAL_Control;
    *(undefined1 *)(lVar26 + 3) = uVar8;
    if ((int)uVar21 == 0x103) goto LAB_14000472b;
    goto LAB_1400049fd;
  }
LAB_140004acd:
  ppuVar25 = &WPP_GLOBAL_Control;
  puVar23 = auStackY_98;
LAB_1400049fd:
  *(int *)(param_2 + 0x30) = (int)uVar21;
  *(undefined8 *)(puVar23 + -8) = 0x140004a0c;
  IofCompleteRequest(param_2,0);
  puVar22 = puVar23;
LAB_14000472b:
  if ((((undefined **)WPP_GLOBAL_Control != ppuVar25) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined8 *)(puVar22 + -8) = 0x140005027;
    WPP_SF_D(uVar5,0x48,&WPP_e947f7dfdc8330b398201c2535585168_Traceguids,(int)uVar21);
  }
  local_58 = (longlong ***)0x0;
  uStack_50 = 0;
  local_48 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    *(undefined8 *)(puVar22 + -8) = 0x14000476a;
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_58);
    *DAT_14001a1b0 = 0x69736373;
    *(longlong *)(DAT_14001a1b0 + 2) = (longlong)(int)uVar21;
    *(undefined8 **)(DAT_14001a1b0 + 4) = param_1;
    *(undefined **)(DAT_14001a1b0 + 6) = param_2;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    *(undefined8 *)(puVar22 + -8) = 0x1400047ca;
    KeReleaseInStackQueuedSpinLock(&local_58);
  }
  return uVar21;
LAB_140005222:
  puVar14 = (undefined *)0x3;
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)();
  puVar22 = auStackY_90;
LAB_140005229:
  puVar23 = puVar22;
  if (3 < (byte)puVar14[0x29]) {
    uVar5 = *(undefined8 *)(puVar14 + 0x18);
    *(undefined8 *)(puVar23 + -8) = 0x140005248;
    WPP_SF_(uVar5,0x1e,&WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
  }
LAB_14000497b:
  uVar21 = 0;
  *(undefined1 *)(lVar26 + 3) = 1;
  goto LAB_1400049fd;
}



===== UsbQueueInsert @ 1400052e0 =====

uint UsbQueueInsert(longlong param_1,longlong param_2,undefined4 param_3,int param_4)

{
  byte *pbVar1;
  longlong *plVar2;
  int *piVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  code *pcVar7;
  bool bVar8;
  uint uVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong lVar12;
  undefined4 uVar13;
  longlong *plVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined **ppuVar18;
  int iVar19;
  uint uVar20;
  undefined1 auStack_78 [8];
  undefined1 auStack_70 [24];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  ppuVar18 = &WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
            &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
  }
  puVar17 = auStack_78;
  puVar16 = auStack_78;
  puVar15 = auStack_78;
  iVar19 = *(int *)(param_1 + 300);
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_40);
    *DAT_14001a1b0 = 0x72736e49;
    *(longlong *)(DAT_14001a1b0 + 2) = param_1;
    *(longlong *)(DAT_14001a1b0 + 4) = param_2;
    *(longlong *)(DAT_14001a1b0 + 6) = (longlong)iVar19;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_40);
  }
  *(undefined4 *)(param_2 + 0x88) = param_3;
  uVar9 = 0;
  uVar20 = 0;
  bVar8 = false;
  KeAcquireInStackQueuedSpinLock(param_1 + 0x120,&local_58);
  if (param_4 == 1) {
    iVar19 = *(int *)(param_1 + 300);
    if (iVar19 < *(int *)(param_1 + 0x128)) {
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      iVar19 = *(int *)(param_1 + 300) + 1;
      *(longlong *)(param_1 + 0x160) = param_2;
      *(int *)(param_1 + 300) = iVar19;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                 &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids,iVar19);
        iVar19 = *(int *)(param_1 + 300);
      }
      uVar13 = 0x50636e49;
      uVar20 = 0;
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
        iVar19 = *(int *)(param_1 + 300);
      }
      uVar20 = 1;
      uVar13 = 0x42736e49;
    }
    USBSTOR_LogEntry(uVar13,param_1,param_2,(longlong)iVar19);
  }
  else {
    if (((param_4 == 2) || (*(int *)(param_1 + 0x128) <= *(int *)(param_1 + 300))) ||
       (*(char *)(param_1 + 0x130) != '\0')) {
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
      }
      plVar2 = (longlong *)(param_2 + 0x78);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
                &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
      }
      uVar9 = 2;
      lVar12 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
      if ((lVar12 != 0) && (lVar12 = *(longlong *)(lVar12 + 0x38), lVar12 != 0)) {
        lVar10 = IoGetSfioStreamIdentifier(*(undefined8 *)(lVar12 + 0xc0),param_1 + 0x100);
        if (lVar10 == 0) {
          uVar9 = IoGetIoPriorityHint(lVar12);
          if (uVar9 < 2) {
            uVar9 = 2;
          }
        }
        else {
          uVar9 = 6;
        }
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
                 &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids,uVar9);
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
                &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
      }
      ppuVar18 = (undefined **)0x0;
      lVar12 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
      if (((lVar12 != 0) && (lVar12 = *(longlong *)(lVar12 + 0x38), lVar12 != 0)) &&
         ((lVar10 = IoGetSfioStreamIdentifier(*(undefined8 *)(lVar12 + 0xc0),param_1 + 0x100),
          lVar10 != 0 &&
          (lVar12 = IoGetSfioStreamIdentifier(*(undefined8 *)(lVar12 + 0xc0),param_1 + 0x100),
          lVar12 != 0)))) {
        ppuVar18 = (undefined **)(lVar12 + 0x18);
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
                 &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids,ppuVar18);
      }
      if (uVar9 < 6) {
        if (uVar9 == 4) {
          PortListInsertRequest((longlong *)(param_1 + 0x20),plVar2);
        }
        else {
          plVar14 = (longlong *)((ulonglong)(uVar9 - 1) * 0x38 + 0x58 + param_1);
          iVar19 = (int)plVar14[6];
          if (iVar19 == 0) {
            plVar11 = (longlong *)*plVar14;
            if (plVar11 != plVar14) {
              do {
                if (*(ulonglong *)(param_2 + 0x88) < (ulonglong)plVar11[2]) break;
                plVar11 = (longlong *)*plVar11;
              } while (plVar11 != plVar14);
            }
            puVar4 = (undefined8 *)plVar11[1];
            if ((longlong *)*puVar4 != plVar11) goto LAB_1400058f9;
            *plVar2 = (longlong)plVar11;
            *(undefined8 **)(param_2 + 0x80) = puVar4;
            *puVar4 = plVar2;
            plVar11[1] = (longlong)plVar2;
            if ((longlong *)plVar14[2] == plVar14) {
              plVar14[2] = *plVar14;
            }
            else if (((ulonglong)plVar14[5] <= *(ulonglong *)(param_2 + 0x88)) &&
                    ((uVar5 = ((longlong *)plVar14[2])[2], *(ulonglong *)(param_2 + 0x88) < uVar5 ||
                     (uVar5 < (ulonglong)plVar14[5])))) {
              plVar14[2] = (longlong)plVar2;
            }
          }
          else if ((iVar19 == 1) || (iVar19 != 2)) {
            puVar4 = (undefined8 *)plVar14[1];
            if ((longlong *)*puVar4 != plVar14) goto LAB_1400058f9;
            *plVar2 = (longlong)plVar14;
            *(undefined8 **)(param_2 + 0x80) = puVar4;
            *puVar4 = plVar2;
            plVar14[1] = (longlong)plVar2;
            plVar14[2] = *plVar14;
          }
          else {
            for (plVar11 = (longlong *)*plVar14; plVar11 != plVar14; plVar11 = (longlong *)*plVar11)
            {
              uVar20 = 0;
              do {
                lVar12 = (ulonglong)(1 - uVar20) * 4;
                if (*(int *)(lVar12 + 0x10 + (longlong)plVar2) !=
                    *(int *)(lVar12 + 0x10 + (longlong)plVar11)) goto LAB_140005b19;
                uVar20 = uVar20 + 1;
              } while (uVar20 < 2);
              if (uVar20 != 2) {
LAB_140005b19:
                lVar12 = (ulonglong)(1 - uVar20) * 4;
                if (*(uint *)(lVar12 + 0x10 + (longlong)plVar2) <=
                    *(uint *)(lVar12 + 0x10 + (longlong)plVar11)) break;
              }
            }
            puVar4 = (undefined8 *)plVar11[1];
            if ((longlong *)*puVar4 != plVar11) {
LAB_1400058f9:
              pcVar7 = (code *)swi(0x29);
              (*pcVar7)(3);
              puVar17 = auStack_70;
              goto LAB_140005900;
            }
            *plVar2 = (longlong)plVar11;
            *(undefined8 **)(param_2 + 0x80) = puVar4;
            *puVar4 = plVar2;
            plVar11[1] = (longlong)plVar2;
            plVar14[2] = *plVar14;
          }
          *(int *)(plVar14 + 3) = (int)plVar14[3] + 1;
          if (plVar14[4] != 0) {
            piVar3 = (int *)(plVar14[4] + 4);
            *piVar3 = *piVar3 + 1;
          }
        }
      }
      else {
        PortListInsertRequest((longlong *)ppuVar18,plVar2);
      }
      LOCK();
      *(code **)(param_2 + 0x68) = UsbCancelIo;
      UNLOCK();
      if (*(char *)(param_2 + 0x44) != '\0') {
        LOCK();
        lVar12 = *(longlong *)(param_2 + 0x68);
        *(longlong *)(param_2 + 0x68) = 0;
        UNLOCK();
        if (lVar12 != 0) {
          UsbRemoveIrp(param_1,param_2);
          bVar8 = true;
        }
      }
      ppuVar18 = &WPP_GLOBAL_Control;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
                &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
      }
      iVar19 = *(int *)(param_1 + 300);
      uVar20 = 1;
      local_30 = 0;
      local_40 = 0;
      uStack_38 = 0;
      if (DAT_14001a1a8 != (undefined4 *)0x0) {
        KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_40);
        *DAT_14001a1b0 = 0x49736e49;
        *(longlong *)(DAT_14001a1b0 + 2) = param_1;
        *(longlong *)(DAT_14001a1b0 + 4) = param_2;
        *(longlong *)(DAT_14001a1b0 + 6) = (longlong)iVar19;
        if (DAT_14001a1b0 <= DAT_14001a1a8) {
          DAT_14001a1b0 = DAT_14001a1b8;
        }
        DAT_14001a1b0 = DAT_14001a1b0 + -8;
        KeReleaseInStackQueuedSpinLock(&local_40);
      }
      KeReleaseInStackQueuedSpinLock(&local_58);
      puVar16 = auStack_78;
      if (bVar8) {
        *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
        *(undefined8 *)(param_2 + 0x38) = 0;
        IofCompleteRequest(param_2,0);
        puVar16 = auStack_78;
      }
      goto LAB_1400057aa;
    }
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    iVar19 = *(int *)(param_1 + 300) + 1;
    *(int *)(param_1 + 300) = iVar19;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
               &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids,iVar19);
    }
    iVar19 = *(int *)(param_1 + 300);
    local_40 = 0;
    uStack_38 = 0;
    local_30 = 0;
    puVar15 = auStack_78;
    if (DAT_14001a1a8 != (undefined4 *)0x0) {
      KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_40);
      *DAT_14001a1b0 = 0x4f636e49;
      *(longlong *)(DAT_14001a1b0 + 2) = param_1;
      *(longlong *)(DAT_14001a1b0 + 4) = param_2;
      *(longlong *)(DAT_14001a1b0 + 6) = (longlong)iVar19;
      uVar20 = 0;
      if (DAT_14001a1b0 <= DAT_14001a1a8) {
LAB_140005900:
        puVar16 = puVar17;
        DAT_14001a1b0 = DAT_14001a1b8;
        uVar20 = uVar9;
      }
      DAT_14001a1b0 = DAT_14001a1b0 + -8;
      *(undefined8 *)(puVar16 + -8) = 0x1400054e7;
      KeReleaseInStackQueuedSpinLock(puVar16 + 0x38);
      puVar15 = puVar16;
    }
  }
  *(undefined8 *)(puVar15 + -8) = 0x1400054f8;
  KeReleaseInStackQueuedSpinLock(puVar15 + 0x20);
  puVar16 = puVar15;
LAB_1400057aa:
  if ((((undefined **)WPP_GLOBAL_Control != ppuVar18) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    uVar6 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined8 *)(puVar16 + -8) = 0x140005832;
    WPP_SF_D(uVar6,0x17,&WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids,uVar20 & 0xff);
  }
  return uVar20 & 0xff;
}



===== UsbDequeueIrp @ 140005bc0 =====

longlong * UsbDequeueIrp(uint *param_1,longlong *param_2,undefined *param_3)

{
  uint *puVar1;
  int *piVar2;
  longlong lVar3;
  code *pcVar4;
  longlong *plVar5;
  longlong *plVar6;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    param_3 = &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids;
    param_2 = (longlong *)0x22;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
            &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
  }
  do {
    plVar5 = (longlong *)0x0;
    if (param_1[1] == 0) break;
    plVar6 = (longlong *)0x0;
    puVar1 = param_1 + 8;
    if ((*(uint **)puVar1 != puVar1) ||
       (PortAvioSchedulerTransferBatch(param_1,param_2,param_3), *(uint **)puVar1 != puVar1)) {
      plVar6 = *(longlong **)(param_1 + 0xc);
      *(longlong *)(param_1 + 0xc) = *plVar6;
      *(longlong *)(param_1 + 0x12) = plVar6[2] + 1;
      lVar3 = *plVar6;
      if ((*(longlong **)(lVar3 + 8) != plVar6) ||
         (plVar5 = (longlong *)plVar6[1], (longlong *)*plVar5 != plVar6)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        pcVar4 = (code *)swi(3);
        plVar5 = (longlong *)(*pcVar4)();
        return plVar5;
      }
      *plVar5 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar5;
      param_1[0xe] = param_1[0xe] - 1;
      if (*(longlong *)(param_1 + 0x10) != 0) {
        piVar2 = (int *)(*(longlong *)(param_1 + 0x10) + 4);
        *piVar2 = *piVar2 + -1;
      }
      if (*(uint **)(param_1 + 0xc) == puVar1) {
        *(longlong *)(param_1 + 0xc) = *(longlong *)puVar1;
      }
    }
    plVar5 = plVar6 + -0xf;
    LOCK();
    lVar3 = plVar6[-2];
    plVar6[-2] = 0;
    UNLOCK();
  } while (lVar3 == 0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
             &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids,plVar5);
  }
  return plVar5;
}



===== USBSTOR_TranslateCDBComplete @ 140005cf0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void USBSTOR_TranslateCDBComplete(longlong param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  byte bVar5;
  undefined1 uVar6;
  bool bVar7;
  undefined4 uVar8;
  longlong lVar9;
  undefined1 *puVar10;
  longlong lVar11;
  undefined4 uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  longlong lVar15;
  undefined1 auStack_c8 [32];
  undefined4 local_a8;
  undefined4 local_a0;
  undefined1 local_98;
  longlong local_90;
  uint local_88;
  longlong local_80;
  undefined1 local_78;
  longlong local_70;
  longlong local_68;
  ulonglong local_58 [4];
  
  local_58[3] = __security_cookie ^ (ulonglong)auStack_c8;
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  KeCancelTimer(lVar1 + 0xc0);
  lVar15 = 0;
  uVar12 = 0xc00000c0;
  if (*(char *)(*(longlong *)(lVar1 + 0x40) + 6) == '\x06') {
    bVar5 = *(byte *)(param_3 + 3) & 0x3f;
    if (bVar5 != 1) {
      switch(bVar5) {
      case 8:
      case 0x11:
      case 0x20:
      case 0x21:
        uVar8 = 0xc00000c0;
        break;
      case 9:
      case 0xb:
      case 0xe:
        uVar8 = 0xc00000b5;
        break;
      case 10:
        uVar8 = 0xc000009d;
        break;
      default:
        uVar8 = 0xc0000185;
        break;
      case 0x12:
        *(undefined4 *)(param_2 + 0x30) = 0x80000005;
        goto LAB_140005d71;
      case 0x15:
      case 0x22:
        uVar8 = 0xc0000010;
      }
      *(undefined4 *)(param_2 + 0x30) = uVar8;
    }
  }
  else if (*(char *)(param_3 + 0x48) != *(char *)(lVar1 + 0x498)) {
    if ((*(char *)(param_3 + 0x48) == 'Z') &&
       (((bVar5 = *(byte *)(param_3 + 3) & 0x3f, bVar5 == 1 || (bVar5 == 0x12)) &&
        (7 < *(uint *)(param_3 + 0x10))))) {
      lVar11 = *(longlong *)(param_2 + 8);
      puVar10 = *(undefined1 **)(param_3 + 0x18);
      if (lVar11 != 0) {
        if ((*(byte *)(lVar11 + 10) & 5) == 0) {
          local_a0 = 0x40000010;
          local_a8 = 0;
          puVar10 = (undefined1 *)MmMapLockedPagesSpecifyCache(lVar11);
        }
        else {
          puVar10 = *(undefined1 **)(lVar11 + 0x18);
        }
        if (puVar10 == (undefined1 *)0x0) {
          *(undefined1 *)(param_3 + 3) = 4;
          goto LAB_14000600f;
        }
      }
      *puVar10 = puVar10[1];
      puVar10[1] = puVar10[2];
      puVar10[2] = puVar10[3];
      puVar10[3] = puVar10[7];
      memmove(puVar10 + 4,puVar10 + 8,(ulonglong)*(uint *)(param_3 + 0x10) - 8);
      *(int *)(param_3 + 0x10) = *(int *)(param_3 + 0x10) + -4;
      uVar6 = 0x12;
      if (*(char *)(param_3 + 3) < '\0') {
        uVar6 = 0x92;
      }
      *(undefined1 *)(param_3 + 3) = uVar6;
    }
LAB_14000600f:
    uVar8 = *(undefined4 *)(lVar1 + 0x49c);
    uVar3 = *(undefined4 *)(lVar1 + 0x4a0);
    uVar4 = *(undefined4 *)(lVar1 + 0x4a4);
    *(undefined4 *)(param_3 + 0x48) = *(undefined4 *)(lVar1 + 0x498);
    *(undefined4 *)(param_3 + 0x4c) = uVar8;
    *(undefined4 *)(param_3 + 0x50) = uVar3;
    *(undefined4 *)(param_3 + 0x54) = uVar4;
  }
LAB_140005d71:
  bVar5 = *(byte *)(param_3 + 3);
  uVar13 = (ulonglong)bVar5;
  if (((bVar5 & 0x3f) != 1) && ((*(uint *)(param_3 + 0xc) & 0x100) == 0)) {
    uVar13 = (ulonglong)(bVar5 | 0x40);
    *(byte *)(param_3 + 3) = bVar5 | 0x40;
    if (lVar2 != 0) {
      uVar13 = lVar2 + 0x170;
      UsbQueueFreeze(uVar13);
    }
  }
  if ((*(uint *)(param_3 + 0xc) & 0x1000000) != 0) {
    USBSTOR_SetModeSenseDataProtect(uVar13,param_2,param_3);
  }
  bVar5 = *(byte *)(param_3 + 3) & 0x3f;
  if (((bVar5 == 1) || (bVar5 == 0x12)) &&
     ((*(char *)(param_3 + 0x48) == '\x12' &&
      (((*(byte *)(param_3 + 0x49) & 1) != 0 && ((*(uint *)(lVar1 + 0x84) & 0x100) == 0)))))) {
    lVar11 = *(longlong *)(param_2 + 8);
    lVar9 = *(longlong *)(param_3 + 0x18);
    if (lVar11 != 0) {
      if ((*(byte *)(lVar11 + 10) & 5) == 0) {
        local_a0 = 0x40000010;
        local_a8 = 0;
        lVar9 = MmMapLockedPagesSpecifyCache();
      }
      else {
        lVar9 = *(longlong *)(lVar11 + 0x18);
      }
    }
    if (lVar9 != 0) {
      uVar13 = 0x24;
      if (*(uint *)(param_3 + 0x10) < 0x24) {
        uVar13 = (ulonglong)*(uint *)(param_3 + 0x10);
      }
      uVar14 = RtlCompareMemory(lVar9);
      if (uVar13 == uVar14) {
        *(uint *)(lVar1 + 0x84) = *(uint *)(lVar1 + 0x84) | 0x100;
      }
    }
  }
  if (((*(uint *)(lVar1 + 0x84) & 0x800) != 0) && ((*(byte *)(param_3 + 3) & 0x3f) == 1)) {
    if (*(char *)(param_3 + 0x48) == '\x1b') {
      if ((*(byte *)(param_3 + 0x4c) & 2) == 0) goto LAB_140005dba;
    }
    else {
      if ((*(char *)(param_3 + 0x48) != '\0') || (*(char *)(lVar2 + 0x30d) != '\0'))
      goto LAB_140005dba;
      *(undefined1 *)(lVar2 + 0x30d) = 1;
    }
    USBSTOR_QueueMediaChangeNotify(param_1,lVar1);
  }
LAB_140005dba:
  bVar5 = *(byte *)(param_3 + 3) & 0x3f;
  if (bVar5 != 1) {
    switch(bVar5) {
    case 8:
    case 0x11:
    case 0x20:
    case 0x21:
      break;
    case 9:
    case 0xb:
    case 0xe:
      uVar12 = 0xc00000b5;
      break;
    case 10:
      uVar12 = 0xc000009d;
      break;
    default:
      uVar12 = 0xc0000185;
      break;
    case 0x12:
      uVar12 = 0x80000005;
      break;
    case 0x15:
    case 0x22:
      uVar12 = 0xc0000010;
    }
    *(undefined4 *)(param_2 + 0x30) = uVar12;
  }
  if (((*(uint *)(param_3 + 0xc) & 0x80010) != 0) &&
     (bVar7 = UsbQueueIsBypassIrp(param_2,lVar2 + 0x170), bVar7)) {
    UsbQueueClearBypassIrp(lVar2 + 0x170);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29]))
       )) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4b,
               &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,*(undefined4 *)(lVar2 + 0x29c));
    }
    USBSTOR_LogEntry(0x42514343,param_1,lVar2 + 0x170,(longlong)*(int *)(lVar2 + 0x29c));
  }
  if ((((Microsoft_Windows_UsbstorEnableBits & 1) != 0) && (lVar2 != 0)) &&
     (*(char *)(lVar2 + 0x330) != '\0')) {
    local_58[0] = 0;
    local_58[1] = 0;
    local_58[2] = 0;
    lVar11 = KeQueryPerformanceCounter(local_58);
    if ((local_58[0] != 0) && (uVar13 = lVar11 - *(longlong *)(lVar2 + 0x328), uVar13 != 0)) {
      uVar14 = (uVar13 % local_58[0]) * 1000;
      lVar15 = (uVar14 / local_58[0] + (uVar13 / local_58[0]) * 1000) * 10000 +
               ((uVar14 % local_58[0]) * 10000) / local_58[0];
    }
    lVar11 = param_2;
    IoGetActivityIdIrp(param_2,local_58 + 1);
    if ((Microsoft_Windows_UsbstorEnableBits & 1) != 0) {
      local_78 = *(undefined1 *)(param_3 + 3);
      local_80 = param_3 + 0x48;
      local_98 = *(undefined1 *)(lVar2 + 0x47);
      local_88 = (uint)*(byte *)(param_3 + 10);
      local_90 = lVar15;
      local_70 = param_2;
      local_68 = param_2;
      McTemplateK0uuuuxqbr5upp_EtwWriteTransfer(lVar11,local_80,local_58 + 1);
    }
  }
  USBSTOR_FxPowerReference(lVar1,param_3,'\0');
  return;
}



===== USBSTOR_FxPowerReference @ 140006280 =====

void USBSTOR_FxPowerReference(longlong param_1,longlong param_2,char param_3)

{
  int *piVar1;
  byte bVar2;
  longlong lVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  if (((*(longlong *)(param_1 + 0x7b0) != 0) && ((*(uint *)(param_2 + 0xc) >> 0x14 & 1) == 0)) &&
     ((*(uint *)(param_2 + 0xc) >> 0xb & 1) == 0)) {
    if (param_3 == '\0') {
      PoFxIdleComponent(*(longlong *)(param_1 + 0x7b0),0,0);
      *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) & 0xfdffffff;
    }
    else {
      PoFxActivateComponent();
      *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) | 0x2000000;
    }
    bVar2 = *(byte *)(param_2 + 0x48);
    local_28 = 0;
    uStack_20 = 0;
    local_18 = 0;
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1e8,&local_28);
    lVar3 = (ulonglong)bVar2 * 0x20;
    if (param_3 == '\0') {
      piVar1 = (int *)(lVar3 + DAT_14001a1d8);
      *piVar1 = *piVar1 + -1;
    }
    else {
      piVar1 = (int *)(lVar3 + DAT_14001a1d8);
      *piVar1 = *piVar1 + 1;
    }
    KeReleaseInStackQueuedSpinLock(&local_28);
  }
  return;
}



===== PortAvioSchedulerTransferBatch @ 140006360 =====

int PortAvioSchedulerTransferBatch(uint *param_1,longlong *param_2,undefined *param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  longlong *plVar5;
  longlong *plVar6;
  uint uVar7;
  int iVar8;
  ulonglong uVar9;
  uint uVar10;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    param_3 = &WPP_256a4584ee4438b757ec1546b7dd7507_Traceguids;
    param_2 = (longlong *)0xa;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_256a4584ee4438b757ec1546b7dd7507_Traceguids);
  }
  if (param_1[1] == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_256a4584ee4438b757ec1546b7dd7507_Traceguids,0);
    }
    return 0;
  }
  uVar7 = *param_1;
  uVar3 = 0;
  if (uVar7 != 0) {
    puVar1 = param_1 + 4;
    uVar3 = 0;
    puVar2 = *(uint **)puVar1;
    while ((puVar2 != puVar1 && (uVar3 < uVar7))) {
      uVar4 = puVar2[4];
      if (uVar7 - uVar3 <= puVar2[4]) {
        uVar4 = uVar7 - uVar3;
      }
      uVar9 = (ulonglong)uVar4;
      uVar10 = 0;
      if (uVar4 != 0) {
        do {
          plVar6 = PortListRemoveNextRequest((longlong *)(puVar2 + 6));
          if (plVar6 == (longlong *)0x0) break;
          PortListInsertRequest((longlong *)(param_1 + 8),plVar6);
          uVar3 = uVar3 + 1;
          uVar10 = uVar10 + 1;
          param_2 = plVar6;
        } while (uVar10 < (uint)uVar9);
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        WPP_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,puVar2,(char)uVar10,
                   (char)puVar2[0xc]);
      }
      puVar2 = *(uint **)puVar2;
    }
    uVar7 = uVar7 - uVar3;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
      param_3 = &WPP_256a4584ee4438b757ec1546b7dd7507_Traceguids;
      WPP_SF_D(*(undefined **)((longlong)WPP_GLOBAL_Control + 0x18),0xc,
               &WPP_256a4584ee4438b757ec1546b7dd7507_Traceguids,uVar3);
    }
    uVar3 = 0;
    if (uVar7 != 0) {
      if (99 < param_1[3]) {
        uVar3 = TransferStarvedRequests((longlong)param_1,uVar7);
        uVar7 = uVar7 - uVar3;
        if (uVar3 != 0) {
          param_1[3] = 0;
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          param_3 = &WPP_256a4584ee4438b757ec1546b7dd7507_Traceguids;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                   &WPP_256a4584ee4438b757ec1546b7dd7507_Traceguids,uVar3);
        }
        uVar3 = 0;
        if (uVar7 == 0) goto LAB_140006448;
      }
      plVar6 = (longlong *)(ulonglong)uVar7;
      uVar4 = TransferNormalRequests((longlong)param_1,uVar7);
      uVar3 = uVar7 - uVar4;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (plVar6 = (longlong *)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
         (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
        param_3 = &WPP_256a4584ee4438b757ec1546b7dd7507_Traceguids;
        plVar6 = (longlong *)0xe;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                 &WPP_256a4584ee4438b757ec1546b7dd7507_Traceguids,uVar4);
      }
      if (uVar3 != 0) {
        puVar2 = *(uint **)puVar1;
        uVar7 = 0;
        while ((puVar2 != puVar1 && (uVar7 < uVar3))) {
          uVar4 = puVar2[4];
          if (uVar3 - uVar7 <= puVar2[4]) {
            uVar4 = uVar3 - uVar7;
          }
          uVar9 = (ulonglong)uVar4;
          uVar10 = 0;
          if (uVar4 != 0) {
            do {
              plVar5 = PortListRemoveNextRequest((longlong *)(puVar2 + 6));
              if (plVar5 == (longlong *)0x0) break;
              PortListInsertRequest((longlong *)(param_1 + 8),plVar5);
              uVar7 = uVar7 + 1;
              uVar10 = uVar10 + 1;
              plVar6 = plVar5;
            } while (uVar10 < (uint)uVar9);
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
            WPP_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),plVar6,param_3,puVar2,(char)uVar10
                       ,(char)puVar2[0xc]);
          }
          puVar2 = *(uint **)puVar2;
        }
        uVar3 = uVar3 - uVar7;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
          WPP_SF_D(*(undefined **)((longlong)WPP_GLOBAL_Control + 0x18),0xf,
                   &WPP_256a4584ee4438b757ec1546b7dd7507_Traceguids,uVar7);
        }
      }
    }
  }
LAB_140006448:
  param_1[3] = param_1[3] + (*param_1 - uVar3);
  iVar8 = *param_1 - uVar3;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_256a4584ee4438b757ec1546b7dd7507_Traceguids,iVar8);
  }
  return iVar8;
}



===== TransferNormalRequests @ 1400066c0 =====

uint TransferNormalRequests(longlong param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  code *pcVar6;
  longlong *plVar7;
  longlong *plVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  longlong *plVar14;
  longlong *plVar15;
  
  uVar11 = 0;
  iVar12 = 3;
  uVar10 = param_2;
  do {
    if (iVar12 < 1) {
      return uVar11;
    }
    plVar8 = (longlong *)(param_1 + 0x20);
    plVar14 = (longlong *)((ulonglong)(iVar12 - 1) * 0x38 + 0x58 + param_1);
    for (uVar9 = 0; ((longlong *)*plVar14 != plVar14 && (uVar9 < uVar10)); uVar9 = uVar9 + 1) {
      plVar15 = (longlong *)plVar14[2];
      plVar14[2] = *plVar15;
      plVar14[5] = plVar15[2] + 1;
      lVar3 = *plVar15;
      if ((*(longlong **)(lVar3 + 8) == plVar15) &&
         (plVar7 = (longlong *)plVar15[1], (longlong *)*plVar7 == plVar15)) {
        *plVar7 = lVar3;
        *(longlong **)(lVar3 + 8) = plVar7;
        *(int *)(plVar14 + 3) = (int)plVar14[3] + -1;
        if (plVar14[4] != 0) {
          piVar1 = (int *)(plVar14[4] + 4);
          *piVar1 = *piVar1 + -1;
        }
        if ((longlong *)plVar14[2] == plVar14) {
          plVar14[2] = *plVar14;
        }
        iVar2 = (int)plVar8[6];
        if (iVar2 == 0) {
          plVar7 = (longlong *)*plVar8;
          if (plVar7 != plVar8) {
            do {
              if ((ulonglong)plVar15[2] < (ulonglong)plVar7[2]) break;
              plVar7 = (longlong *)*plVar7;
            } while (plVar7 != plVar8);
          }
          puVar4 = (undefined8 *)plVar7[1];
          if ((longlong *)*puVar4 != plVar7) goto LAB_140006814;
          *plVar15 = (longlong)plVar7;
          plVar15[1] = (longlong)puVar4;
          *puVar4 = plVar15;
          plVar7[1] = (longlong)plVar15;
          if ((longlong *)plVar8[2] == plVar8) {
            plVar8[2] = *plVar8;
          }
          else if (((ulonglong)plVar8[5] <= (ulonglong)plVar15[2]) &&
                  ((uVar5 = ((longlong *)plVar8[2])[2], (ulonglong)plVar15[2] < uVar5 ||
                   (uVar5 < (ulonglong)plVar8[5])))) goto LAB_14000681b;
        }
        else if ((iVar2 == 1) || (iVar2 != 2)) {
          puVar4 = (undefined8 *)plVar8[1];
          if ((longlong *)*puVar4 != plVar8) goto LAB_140006814;
          *plVar15 = (longlong)plVar8;
          plVar15[1] = (longlong)puVar4;
          *puVar4 = plVar15;
          plVar8[1] = (longlong)plVar15;
          plVar8[2] = *plVar8;
        }
        else {
          for (plVar7 = (longlong *)*plVar8; plVar7 != plVar8; plVar7 = (longlong *)*plVar7) {
            uVar13 = 0;
            do {
              lVar3 = (ulonglong)(1 - uVar13) * 4;
              if (*(int *)(lVar3 + 0x10 + (longlong)plVar15) !=
                  *(int *)(lVar3 + 0x10 + (longlong)plVar7)) goto LAB_140006867;
              uVar13 = uVar13 + 1;
            } while (uVar13 < 2);
            if (uVar13 != 2) {
LAB_140006867:
              lVar3 = (ulonglong)(1 - uVar13) * 4;
              if (*(uint *)(lVar3 + 0x10 + (longlong)plVar15) <=
                  *(uint *)(lVar3 + 0x10 + (longlong)plVar7)) break;
            }
          }
          puVar4 = (undefined8 *)plVar7[1];
          if ((longlong *)*puVar4 != plVar7) goto LAB_140006814;
          *plVar15 = (longlong)plVar7;
          plVar15[1] = (longlong)puVar4;
          *puVar4 = plVar15;
          plVar7[1] = (longlong)plVar15;
          plVar8[2] = *plVar8;
        }
      }
      else {
LAB_140006814:
        pcVar6 = (code *)swi(0x29);
        (*pcVar6)(3);
LAB_14000681b:
        plVar8[2] = (longlong)plVar15;
      }
      *(int *)(plVar8 + 3) = (int)plVar8[3] + 1;
      if (plVar8[4] != 0) {
        piVar1 = (int *)(plVar8[4] + 4);
        *piVar1 = *piVar1 + 1;
      }
    }
    uVar11 = uVar11 + uVar9;
    if (param_2 <= uVar11) {
      return uVar11;
    }
    uVar10 = uVar10 - uVar9;
    iVar12 = iVar12 + -1;
  } while( true );
}



===== UsbStorPumpNextRequest @ 1400068e0 =====

uint * UsbStorPumpNextRequest(longlong param_1,undefined8 *param_2,undefined *param_3)

{
  uint *puVar1;
  longlong lVar2;
  uint *puVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  uint *local_18;
  
  puVar3 = (uint *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_e947f7dfdc8330b398201c2535585168_Traceguids;
    param_2 = (undefined8 *)0xc7;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),199,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  if (param_1 != 0) {
    puVar1 = (uint *)(param_1 + 0x170);
    puVar3 = UsbQueueRemove(puVar1,param_2,param_3);
    local_28 = 0;
    uStack_20 = 0;
    if (puVar3 == (uint *)0x0) {
      local_18 = puVar3;
      if (DAT_14001a1a8 != (undefined4 *)0x0) {
        KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_28);
        *DAT_14001a1b0 = 0x31706d50;
        *(longlong *)(DAT_14001a1b0 + 2) = param_1;
        *(uint **)(DAT_14001a1b0 + 4) = puVar1;
        *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
        if (DAT_14001a1b0 <= DAT_14001a1a8) {
          DAT_14001a1b0 = DAT_14001a1b8;
        }
        DAT_14001a1b0 = DAT_14001a1b0 + -8;
        KeReleaseInStackQueuedSpinLock(&local_28);
      }
    }
    else {
      lVar2 = *(longlong *)(*(longlong *)(puVar3 + 0x2e) + 8);
      local_18 = (uint *)0x0;
      if (DAT_14001a1a8 != (undefined4 *)0x0) {
        param_2 = &local_28;
        KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0);
        *DAT_14001a1b0 = 0x706d7550;
        *(longlong *)(DAT_14001a1b0 + 2) = param_1;
        *(uint **)(DAT_14001a1b0 + 4) = puVar1;
        *(uint **)(DAT_14001a1b0 + 6) = puVar3;
        if (DAT_14001a1b0 <= DAT_14001a1a8) {
          DAT_14001a1b0 = DAT_14001a1b8;
        }
        DAT_14001a1b0 = DAT_14001a1b0 + -8;
        KeReleaseInStackQueuedSpinLock(&local_28);
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_i(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,puVar3);
      }
      IoStartPacket(*(undefined8 *)(param_1 + 0x10),puVar3,lVar2 + 0x40,USBSTOR_CancelIo);
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc9,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  return puVar3;
}



===== UsbQueueRemove @ 140006b60 =====

uint * UsbQueueRemove(uint *param_1,undefined8 param_2,undefined *param_3)

{
  int *piVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  longlong *plVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  longlong *plVar10;
  uint *puVar11;
  uint uVar12;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  longlong local_20 [3];
  
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    param_3 = &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
            &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
  }
  puVar9 = auStack_58;
  puVar8 = auStack_58;
  uVar12 = param_1[0x4b];
  local_28 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_38);
    *DAT_14001a1b0 = 0x766d6552;
    *(uint **)(DAT_14001a1b0 + 2) = param_1;
    *(undefined8 *)(DAT_14001a1b0 + 4) = 0;
    *(longlong *)(DAT_14001a1b0 + 6) = (longlong)(int)uVar12;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_38);
  }
  plVar6 = local_20;
  puVar11 = (uint *)0x0;
  KeAcquireInStackQueuedSpinLock(param_1 + 0x48);
  if ((char)param_1[0x4c] == '\0') {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      param_3 = &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids;
      plVar6 = (longlong *)0x22;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
              &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
    }
    do {
      puVar11 = (uint *)0x0;
      if (param_1[1] == 0) break;
      puVar11 = param_1 + 8;
      plVar10 = (longlong *)0x0;
      if ((*(uint **)puVar11 != puVar11) ||
         (PortAvioSchedulerTransferBatch(param_1,plVar6,param_3), *(uint **)puVar11 != puVar11)) {
        plVar10 = *(longlong **)(param_1 + 0xc);
        *(longlong *)(param_1 + 0xc) = *plVar10;
        *(longlong *)(param_1 + 0x12) = plVar10[2] + 1;
        lVar3 = *plVar10;
        if ((*(longlong **)(lVar3 + 8) != plVar10) ||
           (plVar4 = (longlong *)plVar10[1], (longlong *)*plVar4 != plVar10)) {
          pcVar5 = (code *)swi(0x29);
          (*pcVar5)(3);
          puVar9 = auStack_50;
          goto LAB_140006f84;
        }
        *plVar4 = lVar3;
        *(longlong **)(lVar3 + 8) = plVar4;
        param_1[0xe] = param_1[0xe] - 1;
        if (*(longlong *)(param_1 + 0x10) != 0) {
          piVar1 = (int *)(*(longlong *)(param_1 + 0x10) + 4);
          *piVar1 = *piVar1 + -1;
        }
        if (*(uint **)(param_1 + 0xc) == puVar11) {
          *(longlong *)(param_1 + 0xc) = *(longlong *)puVar11;
        }
      }
      puVar11 = (uint *)(plVar10 + -0xf);
      LOCK();
      lVar3 = plVar10[-2];
      plVar10[-2] = 0;
      UNLOCK();
    } while (lVar3 == 0);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
               &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids,puVar11);
    }
    puVar7 = auStack_58;
    if (puVar11 != (uint *)0x0) goto LAB_140006c9f;
  }
  puVar7 = auStack_58;
  if ((int)param_1[0x4a] <= (int)param_1[0x4b]) {
    uVar12 = param_1[0x4b] - 1;
    param_1[0x4b] = uVar12;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
               &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids,uVar12);
    }
    uVar12 = param_1[0x4b];
    local_38 = 0;
    uStack_30 = 0;
    local_28 = 0;
    puVar7 = auStack_58;
    if (DAT_14001a1a8 != (undefined4 *)0x0) {
      KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_38);
      *DAT_14001a1b0 = 0x4f636544;
      *(uint **)(DAT_14001a1b0 + 2) = param_1;
      *(undefined8 *)(DAT_14001a1b0 + 4) = 0;
      *(longlong *)(DAT_14001a1b0 + 6) = (longlong)(int)uVar12;
      if (DAT_14001a1b0 <= DAT_14001a1a8) {
LAB_140006f84:
        puVar8 = puVar9;
        DAT_14001a1b0 = DAT_14001a1b8;
      }
      DAT_14001a1b0 = DAT_14001a1b0 + -8;
      *(undefined8 *)(puVar8 + -8) = 0x140006e28;
      KeReleaseInStackQueuedSpinLock(puVar8 + 0x20);
      puVar7 = puVar8;
    }
    if ((char)param_1[0x4c] != '\0') {
      *(undefined8 *)(puVar7 + -8) = 0x140006e4d;
      KeSetEvent(param_1 + 0x52,0,0);
      uVar12 = param_1[0x4b];
      *(undefined8 *)(puVar7 + 0x20) = 0;
      *(undefined8 *)(puVar7 + 0x28) = 0;
      *(undefined8 *)(puVar7 + 0x30) = 0;
      if (DAT_14001a1a8 != (undefined4 *)0x0) {
        *(undefined8 *)(puVar7 + -8) = 0x140006e88;
        KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,puVar7 + 0x20);
        *DAT_14001a1b0 = 0x47534551;
        *(uint **)(DAT_14001a1b0 + 2) = param_1;
        *(undefined8 *)(DAT_14001a1b0 + 4) = 0;
        *(longlong *)(DAT_14001a1b0 + 6) = (longlong)(int)uVar12;
        if (DAT_14001a1b0 <= DAT_14001a1a8) {
          DAT_14001a1b0 = DAT_14001a1b8;
        }
        DAT_14001a1b0 = DAT_14001a1b0 + -8;
        *(undefined8 *)(puVar7 + -8) = 0x140006ee6;
        KeReleaseInStackQueuedSpinLock(puVar7 + 0x20);
      }
    }
  }
LAB_140006c9f:
  *(undefined8 *)(puVar7 + -8) = 0x140006cab;
  KeReleaseInStackQueuedSpinLock(puVar7 + 0x38);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined8 *)(puVar7 + -8) = 0x140006d01;
    WPP_SF_q(uVar2,0x1a,&WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids,puVar11);
  }
  return puVar11;
}



===== USBSTOR_ResetPipe @ 140007000 =====

int USBSTOR_ResetPipe(longlong param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa6,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_38);
    *DAT_14001a1b0 = 0x50534552;
    *(longlong *)(DAT_14001a1b0 + 2) = param_1;
    *(undefined8 *)(DAT_14001a1b0 + 4) = param_2;
    *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_38);
  }
  puVar2 = (undefined4 *)ExAllocatePool2(0x40,0x28,0x53414d55);
  if (puVar2 == (undefined4 *)0x0) {
    iVar1 = -0x3fffff66;
  }
  else {
    *puVar2 = 0x1e0028;
    *(undefined8 *)(puVar2 + 6) = param_2;
    iVar1 = USBSTOR_SyncSendUsbRequest(param_1,(longlong)puVar2);
    ExFreePoolWithTag(puVar2,0);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa7,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar1);
  }
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_38);
    *DAT_14001a1b0 = 0x70736572;
    *(longlong *)(DAT_14001a1b0 + 2) = (longlong)iVar1;
    *(undefined8 *)(DAT_14001a1b0 + 4) = 0;
    *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_38);
  }
  return iVar1;
}



===== USBSTOR_StartIo @ 140007260 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void USBSTOR_StartIo(longlong param_1,longlong param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  byte bVar7;
  int iVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  longlong lVar11;
  undefined8 *puVar12;
  undefined *puVar13;
  bool bVar14;
  undefined1 local_res8 [8];
  undefined1 uVar15;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  local_48 = 0;
  local_res8[0] = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_30 = 0;
  local_40 = 0;
  uStack_38 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_40);
    *DAT_14001a1b0 = 0x4f495453;
    *(longlong *)(DAT_14001a1b0 + 2) = param_1;
    *(longlong *)(DAT_14001a1b0 + 4) = param_2;
    *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_40);
  }
  uVar15 = (undefined1)param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,param_1,uVar15);
  }
  pcVar3 = *(char **)(param_2 + 0xb8);
  lVar11 = *(longlong *)(param_1 + 0x40);
  if (*pcVar3 == '\x16') {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4f,
                &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,param_1,uVar15);
    }
    USBSTOR_LogEntry(0x43445046,param_1,param_2,(longlong)*(int *)(pcVar3 + 0x18));
    if ((*(uint *)(param_1 + 0x30) & 0x2000) == 0) {
      puVar12 = *(undefined8 **)(param_2 + 0xb8);
      puVar12[-9] = *puVar12;
      puVar12[-8] = puVar12[1];
      puVar12[-7] = puVar12[2];
      puVar12[-6] = puVar12[3];
      *(undefined4 *)(puVar12 + -5) = *(undefined4 *)(puVar12 + 4);
      *(undefined4 *)((longlong)puVar12 + -0x24) = *(undefined4 *)((longlong)puVar12 + 0x24);
      *(undefined4 *)(puVar12 + -4) = *(undefined4 *)(puVar12 + 5);
      *(undefined4 *)((longlong)puVar12 + -0x1c) = *(undefined4 *)((longlong)puVar12 + 0x2c);
      puVar12[-3] = puVar12[6];
      *(undefined1 *)((longlong)puVar12 + -0x45) = 0;
      lVar4 = *(longlong *)(param_2 + 0xb8);
      iVar8 = *(int *)(lVar11 + 0x788);
      *(code **)(lVar4 + -0x10) = USBSTOR_FdoSetPowerSxCompletion;
      *(longlong *)(lVar4 + -8) = (longlong)iVar8;
      *(undefined1 *)(lVar4 + -0x45) = 0xe0;
      PoCallDriver(*(undefined8 *)(lVar11 + 0x18),param_2);
      return;
    }
    lVar11 = lVar11 + 0xa8;
  }
  else {
    if (*pcVar3 != '\x1b') {
      lVar4 = *(longlong *)(pcVar3 + 0x10);
      IoAcquireCancelSpinLock(local_res8);
      LOCK();
      *(undefined8 *)(param_2 + 0x68) = 0;
      UNLOCK();
      if (*(char *)(param_2 + 0x44) != '\0') {
        KeAcquireInStackQueuedSpinLockAtDpcLevel(lVar11 + 0x90,&local_58);
        uVar2 = *(uint *)(lVar11 + 0x80);
        KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_58);
        IoReleaseCancelSpinLock(local_res8[0]);
        USBSTOR_LogEntry(0x334e4143,param_1,param_2,0);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,
                    &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,param_1,uVar15);
        }
        *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
        puVar13 = (undefined *)0x0;
        *(undefined8 *)(param_2 + 0x38) = 0;
        lVar5 = *(longlong *)(pcVar3 + 8);
        *(undefined1 *)(lVar5 + 3) = 2;
        USBSTOR_FxPowerReference(lVar11,lVar5,'\0');
        puVar12 = (undefined8 *)0x0;
        IofCompleteRequest(param_2);
        if ((uVar2 & 8) == 0) {
          UsbStorPumpNextRequest(lVar4,puVar12,puVar13);
          UsbStorStartNextPacket(param_1);
          return;
        }
        return;
      }
      IoReleaseCancelSpinLock(local_res8[0]);
      lVar5 = *(longlong *)(pcVar3 + 8);
      *(longlong *)(lVar11 + 0x490) = lVar5;
      KeAcquireInStackQueuedSpinLockAtDpcLevel(lVar11 + 0x90);
      uVar2 = *(uint *)(lVar11 + 0x80);
      if ((uVar2 & 0x10) == 0) {
        *(uint *)(lVar11 + 0x80) = uVar2 & 0xffffffbf;
        bVar14 = (uVar2 & 4) != 0;
        if (bVar14) {
          *(uint *)(lVar11 + 0x80) = uVar2 & 0xffffffbb;
        }
        KeReleaseInStackQueuedSpinLockFromDpcLevel();
        uVar2 = *(uint *)(lVar5 + 0x14);
        uVar9 = (ulonglong)uVar2;
        if (uVar2 != 0) {
          if ((*(char *)(lVar5 + 0x48) == '\x1b') && (0x3c < uVar2)) {
            uVar9 = (ulonglong)(uVar2 - 0x13);
          }
          KeSetCoalescableTimer(lVar11 + 0xc0,uVar9 * -10000000,0,500,lVar11 + 0x100);
        }
        *(undefined8 *)(lVar11 + 0x140) = _DAT_fffff78000000014;
        lVar6 = *(longlong *)(param_1 + 0x40);
        if (((*(char *)(lVar5 + 0x48) == '\x1a') && (3 < *(uint *)(lVar5 + 0x10))) &&
           (*(char *)(lVar6 + 0x720) != '\0')) {
          *(uint *)(lVar5 + 0xc) = *(uint *)(lVar5 + 0xc) | 0x1000000;
        }
        if (*(char *)(*(longlong *)(lVar6 + 0x40) + 6) != '\x06') {
          uVar10 = *(undefined8 *)(lVar5 + 0x50);
          *(undefined8 *)(lVar6 + 0x498) = *(undefined8 *)(lVar5 + 0x48);
          *(undefined8 *)(lVar6 + 0x4a0) = uVar10;
          bVar7 = *(byte *)(lVar5 + 10);
          if (bVar7 < 0x10) {
            memset((void *)(lVar5 + 0x48 + (ulonglong)bVar7),0,0x10 - (ulonglong)bVar7);
            bVar7 = 0xc;
          }
          else if (0x10 < bVar7) {
            bVar7 = 0x10;
          }
          *(byte *)(lVar5 + 10) = bVar7;
          cVar1 = *(char *)(lVar5 + 0x48);
          if (cVar1 == '\0') {
            if ((*(uint *)(lVar6 + 0x84) & 4) != 0) {
              *(undefined8 *)(lVar5 + 0x48) = 0;
              *(undefined8 *)(lVar5 + 0x50) = 0;
              *(byte *)(lVar5 + 0x4c) = *(byte *)(lVar5 + 0x4c) | 1;
              *(undefined1 *)(lVar5 + 0x48) = 0x1b;
            }
          }
          else if (cVar1 == '\x15') {
            *(undefined8 *)(lVar5 + 0x48) = 0;
            *(undefined8 *)(lVar5 + 0x50) = 0;
            *(undefined1 *)(lVar5 + 0x48) = 0x55;
            *(undefined1 *)(lVar5 + 0x50) = *(undefined1 *)(lVar5 + 0x4c);
            *(byte *)(lVar5 + 0x49) =
                 (*(byte *)(lVar5 + 0x49) ^ *(byte *)(lVar5 + 0x49)) & 1 ^ *(byte *)(lVar5 + 0x49) |
                 0x10;
          }
          else if (cVar1 == '\x1a') {
            *(undefined8 *)(lVar5 + 0x48) = 0;
            *(undefined8 *)(lVar5 + 0x50) = 0;
            *(undefined1 *)(lVar5 + 0x48) = 0x5a;
            *(byte *)(lVar5 + 0x4a) =
                 (*(byte *)(lVar5 + 0x4a) ^ *(byte *)(lVar5 + 0x4a)) & 0x3f ^
                 *(byte *)(lVar5 + 0x4a);
            *(undefined1 *)(lVar5 + 0x50) = *(undefined1 *)(lVar5 + 0x4c);
          }
        }
        if ((((Microsoft_Windows_UsbstorEnableBits & 1) != 0) && (lVar4 != 0)) &&
           (*(char *)(lVar4 + 0x330) != '\0')) {
          uVar10 = KeQueryPerformanceCounter(0);
          *(undefined8 *)(lVar4 + 0x328) = uVar10;
        }
        if (*(int *)(lVar11 + 0x78) == 1) {
          iVar8 = USBSTOR_CbwTransfer(param_1,param_2);
        }
        else if ((!bVar14) || (*(char *)(lVar5 + 0x48) == '\x03')) {
          iVar8 = USBSTOR_IssueClientCdb(param_1,param_2);
        }
        else {
          iVar8 = USBSTOR_IssueRequestSenseCdb(param_1,param_2,1);
        }
      }
      else {
        KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_58);
        local_40 = 0;
        uStack_38 = 0;
        local_30 = 0;
        if (DAT_14001a1a8 != (undefined4 *)0x0) {
          KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_40);
          *DAT_14001a1b0 = 0x646f6973;
          *(longlong *)(DAT_14001a1b0 + 2) = param_1;
          *(longlong *)(DAT_14001a1b0 + 4) = param_2;
          *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
          if (DAT_14001a1b0 <= DAT_14001a1a8) {
            DAT_14001a1b0 = DAT_14001a1b8;
          }
          DAT_14001a1b0 = DAT_14001a1b0 + -8;
          KeReleaseInStackQueuedSpinLock(&local_40);
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x52,
                    &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,param_1,uVar15);
        }
        *(undefined1 *)(lVar5 + 3) = 8;
        iVar8 = -0x3fffff63;
        *(undefined4 *)(lVar5 + 0x10) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc000009d;
        *(undefined8 *)(param_2 + 0x38) = 0;
        if (((*(uint *)(lVar5 + 0xc) & 0x80010) != 0) &&
           (bVar14 = UsbQueueIsBypassIrp(param_2,lVar4 + 0x170), bVar14)) {
          UsbQueueClearBypassIrp(lVar4 + 0x170);
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0 &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])))) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x53,
                     &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,*(undefined4 *)(lVar4 + 0x29c)
                    );
          }
          USBSTOR_LogEntry(0x31425143,param_1,lVar4 + 0x170,(longlong)*(int *)(lVar4 + 0x29c));
        }
        puVar13 = (undefined *)0x0;
        USBSTOR_FxPowerReference(lVar11,lVar5,'\0');
        puVar12 = (undefined8 *)0x0;
        IofCompleteRequest(param_2);
        UsbStorPumpNextRequest(lVar4,puVar12,puVar13);
        UsbStorStartNextPacket(param_1);
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x55,
                 &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar8);
      }
      local_40 = 0;
      uStack_38 = 0;
      local_30 = 0;
      if (DAT_14001a1a8 == (undefined4 *)0x0) {
        return;
      }
      KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_40);
      *DAT_14001a1b0 = 0x6f697473;
      *(longlong *)(DAT_14001a1b0 + 2) = param_1;
      *(longlong *)(DAT_14001a1b0 + 4) = param_2;
      *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
      if (DAT_14001a1b0 <= DAT_14001a1a8) {
        DAT_14001a1b0 = DAT_14001a1b8;
      }
      DAT_14001a1b0 = DAT_14001a1b0 + -8;
      KeReleaseInStackQueuedSpinLock(&local_40);
      return;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,
                &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,param_1,uVar15);
    }
    USBSTOR_LogEntry(0x50545346,param_1,param_2,0);
    lVar11 = lVar11 + 0x790;
  }
  KeSetEvent(lVar11,0,0);
  return;
}



===== USBSTOR_CbwTransfer @ 140007b70 =====

int USBSTOR_CbwTransfer(longlong param_1,longlong param_2)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  int *piVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  bool bVar11;
  int iVar12;
  byte bVar13;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  bVar13 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x90,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_78);
    *DAT_14001a1b0 = 0x57424349;
    *(longlong *)(DAT_14001a1b0 + 2) = param_1;
    *(longlong *)(DAT_14001a1b0 + 4) = param_2;
    *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_78);
  }
  lVar4 = *(longlong *)(param_1 + 0x40);
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  *(undefined4 *)(lVar4 + 0x6b0) = 0;
  KeAcquireInStackQueuedSpinLock(lVar4 + 0x90,&local_78);
  *(uint *)(lVar4 + 0x80) = *(uint *)(lVar4 + 0x80) | 0x20;
  KeReleaseInStackQueuedSpinLock(&local_78);
  cVar1 = *(char *)(lVar4 + 0x754);
  lVar5 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x28);
  lVar6 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  piVar7 = *(int **)(lVar5 + 0x40);
  iVar12 = *piVar7;
  if (iVar12 == 0x214f4450) {
    bVar13 = *(byte *)((longlong)piVar7 + 0x47);
    iVar12 = 0;
  }
  else if (iVar12 == 0x214f4446) {
    bVar13 = *(byte *)(lVar6 + 7);
    iVar12 = 0;
  }
  else {
    iVar12 = -0x3fffff45;
  }
  if (*(longlong *)(lVar4 + 0x68) == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x91,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    }
    iVar12 = -0x3ffffe7e;
  }
  else if (-1 < iVar12) {
    local_78 = 0;
    uStack_70 = 0;
    local_68 = 0;
    if (DAT_14001a1a8 != (undefined4 *)0x0) {
      KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_78);
      *DAT_14001a1b0 = 0x6c626369;
      *(longlong *)(DAT_14001a1b0 + 2) = param_1;
      *(longlong *)(DAT_14001a1b0 + 4) = lVar5;
      *(ulonglong *)(DAT_14001a1b0 + 6) = (ulonglong)bVar13;
      if (DAT_14001a1b0 <= DAT_14001a1a8) {
        DAT_14001a1b0 = DAT_14001a1b8;
      }
      DAT_14001a1b0 = DAT_14001a1b0 + -8;
      KeReleaseInStackQueuedSpinLock(&local_78);
    }
    *(undefined4 *)(lVar4 + 0x4a8) = 0x43425355;
    *(int *)(lVar4 + 0x4ac) = (int)param_2;
    *(undefined4 *)(lVar4 + 0x4b0) = *(undefined4 *)(lVar6 + 0x10);
    bVar2 = *(byte *)(lVar6 + 0xc);
    *(byte *)(lVar4 + 0x4b5) = bVar13;
    *(byte *)(lVar4 + 0x4b4) = (bVar2 & 0xc0) * '\x02';
    *(undefined1 *)(lVar4 + 0x4b6) = *(undefined1 *)(lVar6 + 10);
    uVar8 = *(undefined8 *)(lVar6 + 0x50);
    *(undefined8 *)(lVar4 + 0x4b7) = *(undefined8 *)(lVar6 + 0x48);
    *(undefined8 *)(lVar4 + 0x4bf) = uVar8;
    uVar8 = *(undefined8 *)(lVar4 + 0x6a8);
    local_60 = 0;
    uStack_58 = 0;
    uVar9 = *(undefined8 *)(*(longlong *)(lVar4 + 0x68) + 8);
    local_50 = 0;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x58,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    }
    local_78 = 0;
    uStack_70 = 0;
    local_68 = 0;
    if (DAT_14001a1a8 != (undefined4 *)0x0) {
      KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_78);
      *DAT_14001a1b0 = 0x52494249;
      *(longlong *)(DAT_14001a1b0 + 2) = param_1;
      *(longlong *)(DAT_14001a1b0 + 4) = param_2;
      *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
      if (DAT_14001a1b0 <= DAT_14001a1a8) {
        DAT_14001a1b0 = DAT_14001a1b8;
      }
      DAT_14001a1b0 = DAT_14001a1b0 + -8;
      KeReleaseInStackQueuedSpinLock(&local_78);
    }
    lVar5 = *(longlong *)(param_1 + 0x40);
    uVar10 = *(undefined8 *)(*(longlong *)(param_2 + 0xb8) + 0x10);
    *(undefined8 *)(lVar5 + 0x18a) = 0;
    *(undefined8 *)(lVar5 + 0x192) = 0;
    *(undefined8 *)(lVar5 + 0x19a) = 0;
    *(undefined8 *)(lVar5 + 0x1a2) = 0;
    *(undefined8 *)(lVar5 + 0x1aa) = 0;
    *(undefined8 *)(lVar5 + 0x1b2) = 0;
    *(undefined8 *)(lVar5 + 0x1ba) = 0;
    *(undefined8 *)(lVar5 + 0x1c2) = 0;
    *(undefined8 *)(lVar5 + 0x1ca) = 0;
    *(undefined8 *)(lVar5 + 0x1d2) = 0;
    *(undefined8 *)(lVar5 + 0x1da) = 0;
    *(undefined8 *)(lVar5 + 0x1e2) = 0;
    *(undefined8 *)(lVar5 + 0x1ea) = 0;
    *(undefined8 *)(lVar5 + 0x1f2) = 0;
    *(undefined8 *)(lVar5 + 0x1fa) = 0;
    *(undefined4 *)(lVar5 + 0x202) = 0;
    *(undefined2 *)(lVar5 + 0x206) = 0;
    *(undefined4 *)(lVar5 + 0x188) = 0x90080;
    *(undefined8 *)(lVar5 + 0x1a0) = uVar9;
    *(uint *)(lVar5 + 0x1a8) = -(uint)(cVar1 != '\0') & 0x10;
    *(undefined4 *)(lVar5 + 0x1ac) = 0x1f;
    *(undefined4 **)(lVar5 + 0x1b0) = (undefined4 *)(lVar4 + 0x4a8);
    *(undefined8 *)(lVar5 + 0x1b8) = uVar8;
    lVar4 = *(longlong *)(param_2 + 0xb8);
    *(undefined4 **)(lVar4 + -0x40) = (undefined4 *)(lVar5 + 0x188);
    *(undefined1 *)(lVar4 + -0x48) = 0xf;
    *(undefined4 *)(lVar4 + -0x30) = 0x220003;
    lVar4 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar4 + -0x10) = USBSTOR_CbwCompletion;
    *(undefined8 *)(lVar4 + -8) = 0;
    *(undefined1 *)(lVar4 + -0x45) = 0xe0;
    KeAcquireInStackQueuedSpinLock(lVar5 + 0x90,&local_60);
    uVar3 = *(uint *)(lVar5 + 0x80);
    *(longlong *)(lVar5 + 0x148) = param_2;
    if (((uVar3 & 0x40) == 0) || ((uVar3 & 8) != 0)) {
      bVar11 = false;
    }
    else {
      bVar11 = true;
    }
    *(uint *)(lVar5 + 0x80) = uVar3 & 0xffffffbf | 2;
    KeReleaseInStackQueuedSpinLock(&local_60);
    iVar12 = IofCallDriver(*(undefined8 *)(lVar5 + 0x18),param_2);
    if (bVar11) {
      USBSTOR_LogEntry(0x4f544942,param_1,param_2,uVar10);
      USBSTOR_QueueResetDevice(param_1,uVar10);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x59,
               &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar12);
    }
    local_48 = 0;
    uStack_40 = 0;
    local_38 = 0;
    if (DAT_14001a1a8 != (undefined4 *)0x0) {
      KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_48);
      *DAT_14001a1b0 = 0x72696269;
      *(longlong *)(DAT_14001a1b0 + 2) = param_1;
      *(longlong *)(DAT_14001a1b0 + 4) = param_2;
      *(longlong *)(DAT_14001a1b0 + 6) = (longlong)iVar12;
      if (DAT_14001a1b0 <= DAT_14001a1a8) {
        DAT_14001a1b0 = DAT_14001a1b8;
      }
      DAT_14001a1b0 = DAT_14001a1b0 + -8;
      KeReleaseInStackQueuedSpinLock(&local_48);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x92,
               &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar12);
    }
    local_48 = 0;
    uStack_40 = 0;
    local_38 = 0;
    if (DAT_14001a1a8 != (undefined4 *)0x0) {
      KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_48);
      *DAT_14001a1b0 = 0x77626369;
      *(longlong *)(DAT_14001a1b0 + 2) = param_1;
      *(longlong *)(DAT_14001a1b0 + 4) = param_2;
      *(longlong *)(DAT_14001a1b0 + 6) = (longlong)iVar12;
      if (DAT_14001a1b0 <= DAT_14001a1a8) {
        DAT_14001a1b0 = DAT_14001a1b8;
      }
      DAT_14001a1b0 = DAT_14001a1b0 + -8;
      KeReleaseInStackQueuedSpinLock(&local_48);
    }
  }
  return iVar12;
}



===== USBSTOR_BulkResetPipeWorkItem @ 140008280 =====

void USBSTOR_BulkResetPipeWorkItem(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  
  local_48 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_58);
    *DAT_14001a1b0 = 0x57505242;
    *(longlong *)(DAT_14001a1b0 + 2) = param_1;
    *(longlong *)(DAT_14001a1b0 + 4) = param_2;
    *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_58);
  }
  lVar1 = *(longlong *)(param_1 + 0x40);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa9,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  uVar2 = *(undefined8 *)(lVar1 + 0x1a0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa6,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_58);
    *DAT_14001a1b0 = 0x50534552;
    *(longlong *)(DAT_14001a1b0 + 2) = param_1;
    *(undefined8 *)(DAT_14001a1b0 + 4) = uVar2;
    *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_58);
  }
  puVar4 = (undefined4 *)ExAllocatePool2(0x40,0x28,0x53414d55);
  if (puVar4 == (undefined4 *)0x0) {
    iVar3 = -0x3fffff66;
  }
  else {
    *puVar4 = 0x1e0028;
    *(undefined8 *)(puVar4 + 6) = uVar2;
    iVar3 = USBSTOR_SyncSendUsbRequest(param_1,(longlong)puVar4);
    ExFreePoolWithTag(puVar4,0);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa7,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar3);
  }
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_40);
    *DAT_14001a1b0 = 0x70736572;
    *(longlong *)(DAT_14001a1b0 + 2) = (longlong)iVar3;
    *(undefined8 *)(DAT_14001a1b0 + 4) = 0;
    *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_40);
  }
  if (param_2 != 0) {
    USBSTOR_CswTransfer(param_1,param_2);
  }
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_40);
    *DAT_14001a1b0 = 0x77707262;
    *(longlong *)(DAT_14001a1b0 + 2) = param_1;
    *(longlong *)(DAT_14001a1b0 + 4) = param_2;
    *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_40);
  }
  IoReleaseRemoveLockEx(lVar1 + 0x728,USBSTOR_BulkResetPipeWorkItem,0x20);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xaa,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  return;
}



===== USBSTOR_SyncSendUsbRequest @ 1400086d0 =====

int USBSTOR_SyncSendUsbRequest(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  int iVar5;
  longlong lVar6;
  undefined8 local_res8;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x99,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  lVar2 = *(longlong *)(param_1 + 0x40);
  KeInitializeEvent(&local_48,1);
  lVar6 = IoAllocateIrp(*(undefined1 *)(*(longlong *)(lVar2 + 0x18) + 0x4c),0);
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_30);
    *DAT_14001a1b0 = 0x52555353;
    *(longlong *)(DAT_14001a1b0 + 2) = param_1;
    *(longlong *)(DAT_14001a1b0 + 4) = lVar6;
    *(longlong *)(DAT_14001a1b0 + 6) = param_2;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_30);
  }
  if (lVar6 == 0) {
    iVar5 = -0x3fffff66;
  }
  else {
    lVar3 = *(longlong *)(lVar6 + 0xb8);
    *(undefined1 *)(lVar3 + -0x48) = 0xf;
    *(undefined4 *)(lVar3 + -0x30) = 0x220003;
    *(longlong *)(lVar3 + -0x40) = param_2;
    lVar3 = *(longlong *)(lVar6 + 0xb8);
    *(code **)(lVar3 + -0x10) = USBSTOR_SyncCompletionRoutine;
    *(undefined8 **)(lVar3 + -8) = &local_48;
    *(undefined1 *)(lVar3 + -0x45) = 0xe0;
    iVar5 = IofCallDriver(*(undefined8 *)(lVar2 + 0x18),lVar6);
    if (iVar5 == 0x103) {
      uVar4 = *(undefined8 *)(lVar2 + 0x18);
      local_30 = 0;
      uStack_28 = 0;
      local_20 = 0;
      if (DAT_14001a1a8 != (undefined4 *)0x0) {
        KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_30);
        *DAT_14001a1b0 = 0x70757373;
        *(undefined8 *)(DAT_14001a1b0 + 2) = uVar4;
        *(longlong *)(DAT_14001a1b0 + 4) = lVar6;
        *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
        if (DAT_14001a1b0 <= DAT_14001a1a8) {
          DAT_14001a1b0 = DAT_14001a1b8;
        }
        DAT_14001a1b0 = DAT_14001a1b0 + -8;
        KeReleaseInStackQueuedSpinLock(&local_30);
      }
      local_res8 = 0xfffffffffd050f80;
      iVar5 = KeWaitForSingleObject(&local_48,0,0,0,&local_res8);
      uVar4 = *(undefined8 *)(lVar2 + 0x18);
      if (iVar5 == 0x102) {
        USBSTOR_LogEntry(0x31747373,uVar4,lVar6,0);
        iVar5 = -0x3fffff4b;
        IoCancelIrp(lVar6);
        KeWaitForSingleObject(&local_48,0,0,0,0);
        USBSTOR_LogEntry(0x32747373,*(undefined8 *)(lVar2 + 0x18),lVar6,0);
      }
      else {
        local_30 = 0;
        uStack_28 = 0;
        local_20 = 0;
        if (DAT_14001a1a8 != (undefined4 *)0x0) {
          KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_30);
          *DAT_14001a1b0 = 0x63757373;
          *(undefined8 *)(DAT_14001a1b0 + 2) = uVar4;
          *(longlong *)(DAT_14001a1b0 + 4) = lVar6;
          *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
          if (DAT_14001a1b0 <= DAT_14001a1a8) {
            DAT_14001a1b0 = DAT_14001a1b8;
          }
          DAT_14001a1b0 = DAT_14001a1b0 + -8;
          KeReleaseInStackQueuedSpinLock(&local_30);
        }
        iVar5 = *(int *)(lVar6 + 0x30);
      }
    }
    IoFreeIrp(lVar6);
    iVar1 = *(int *)(param_2 + 4);
    local_30 = 0;
    uStack_28 = 0;
    local_20 = 0;
    if (DAT_14001a1a8 != (undefined4 *)0x0) {
      KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_30);
      *DAT_14001a1b0 = 0x72757373;
      *(longlong *)(DAT_14001a1b0 + 2) = (longlong)iVar5;
      *(longlong *)(DAT_14001a1b0 + 4) = param_2;
      *(longlong *)(DAT_14001a1b0 + 6) = (longlong)iVar1;
      if (DAT_14001a1b0 <= DAT_14001a1a8) {
        DAT_14001a1b0 = DAT_14001a1b8;
      }
      DAT_14001a1b0 = DAT_14001a1b0 + -8;
      KeReleaseInStackQueuedSpinLock(&local_30);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9a,
               &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar5);
    }
  }
  return iVar5;
}



===== USBSTOR_CswCompletion @ 140008b60 =====

undefined4 USBSTOR_CswCompletion(longlong param_1,longlong param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  longlong lVar4;
  longlong lVar5;
  byte bVar6;
  undefined1 uVar7;
  undefined8 *puVar8;
  longlong lVar9;
  int *piVar10;
  undefined *puVar11;
  undefined *puVar12;
  undefined4 uVar13;
  int *piVar14;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  piVar14 = (int *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa1,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  iVar1 = *(int *)(param_2 + 0x30);
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_48);
    *DAT_14001a1b0 = 0x43575343;
    *(longlong *)(DAT_14001a1b0 + 2) = param_1;
    *(longlong *)(DAT_14001a1b0 + 4) = param_2;
    *(longlong *)(DAT_14001a1b0 + 6) = (longlong)iVar1;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_48);
  }
  piVar3 = *(int **)(param_1 + 0x40);
  if (*piVar3 == 0x214f4450) {
    lVar9 = *(longlong *)(piVar3 + 4);
    piVar10 = *(int **)(*(longlong *)(piVar3 + 4) + 0x40);
    piVar14 = piVar3;
  }
  else {
    lVar9 = 0;
    piVar10 = (int *)0x0;
    if (*piVar3 == 0x214f4446) {
      lVar9 = param_1;
      piVar10 = piVar3;
    }
  }
  lVar4 = *(longlong *)(lVar9 + 0x40);
  lVar5 = *(longlong *)(param_2 + 0xb8);
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  puVar11 = *(undefined **)(lVar5 + 8);
  KeAcquireInStackQueuedSpinLock(lVar4 + 0x90);
  *(uint *)(lVar4 + 0x80) = *(uint *)(lVar4 + 0x80) & 0xfffffffd;
  if ((*(uint *)(lVar4 + 0x80) & 8) == 0) {
    *(undefined8 *)(lVar4 + 0x148) = 0;
    KeReleaseInStackQueuedSpinLock();
    iVar1 = *(int *)(param_2 + 0x30);
    if (iVar1 < 0) {
      iVar2 = piVar10[99];
      local_48 = 0;
      uStack_40 = 0;
      local_38 = 0;
      if (DAT_14001a1a8 != (undefined4 *)0x0) {
        KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_48);
        *DAT_14001a1b0 = 0x32777363;
        *(longlong *)(DAT_14001a1b0 + 2) = (longlong)iVar1;
        *(longlong *)(DAT_14001a1b0 + 4) = (longlong)iVar2;
        *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
        if (DAT_14001a1b0 <= DAT_14001a1a8) {
          DAT_14001a1b0 = DAT_14001a1b8;
        }
        DAT_14001a1b0 = DAT_14001a1b0 + -8;
        KeReleaseInStackQueuedSpinLock(&local_48);
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa3,
                  &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,*(undefined4 *)(param_2 + 0x30),
                  (char)piVar10[99]);
      }
      if (((piVar10[99] & 0xfffffffU) == 4) && ((uint)piVar10[0x1ac] < 2)) {
        piVar10[0x1ac] = piVar10[0x1ac] + 1;
        local_48 = 0;
        uStack_40 = 0;
        local_38 = 0;
        if (DAT_14001a1a8 != (undefined4 *)0x0) {
          KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_48);
          *DAT_14001a1b0 = 0x33777363;
          *(longlong *)(DAT_14001a1b0 + 2) = lVar9;
          *(longlong *)(DAT_14001a1b0 + 4) = param_2;
          *(undefined **)(DAT_14001a1b0 + 6) = puVar11;
          if (DAT_14001a1b0 <= DAT_14001a1a8) {
            DAT_14001a1b0 = DAT_14001a1b8;
          }
          DAT_14001a1b0 = DAT_14001a1b0 + -8;
          KeReleaseInStackQueuedSpinLock(&local_48);
        }
        USBSTOR_BulkQueueResetPipe(lVar9,param_2);
        uVar13 = 0xc0000016;
      }
      else {
        USBSTOR_LogEntry(0x34777363,lVar9,param_2,puVar11);
        lVar4 = *(longlong *)(piVar10 + 0x124);
        *(longlong *)(lVar5 + 8) = lVar4;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000185;
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined1 *)(lVar4 + 3) = 0xe;
        USBSTOR_TranslateCDBComplete(lVar9,param_2,lVar4);
        USBSTOR_QueueResetDevice(lVar9,piVar14);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa4,
                  &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
        }
        uVar13 = 0xc0000185;
      }
    }
    else {
      if ((char)piVar10[0x12d] == '\0') {
        if (puVar11 != *(undefined **)(piVar10 + 0x124)) {
          (*(undefined **)(piVar10 + 0x124))[0xb] = puVar11[0x10];
          puVar11 = *(undefined **)(piVar10 + 0x124);
          *(undefined **)(lVar5 + 8) = puVar11;
          puVar11[3] = puVar11[3] | 0x80;
        }
        *(undefined4 *)(param_2 + 0x30) = 0;
        uVar13 = 0;
        puVar12 = puVar11;
        USBSTOR_TranslateCDBComplete(lVar9,param_2,(longlong)puVar11);
        *(ulonglong *)(param_2 + 0x38) = (ulonglong)*(uint *)(puVar11 + 0x10);
        local_48 = 0;
        uStack_40 = 0;
        local_38 = 0;
        if (DAT_14001a1a8 != (undefined4 *)0x0) {
          KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_48);
          *DAT_14001a1b0 = 0x35777363;
          *(longlong *)(DAT_14001a1b0 + 2) = lVar9;
          *(longlong *)(DAT_14001a1b0 + 4) = param_2;
          *(undefined **)(DAT_14001a1b0 + 6) = puVar11;
          if (DAT_14001a1b0 <= DAT_14001a1a8) {
            DAT_14001a1b0 = DAT_14001a1b8;
          }
          DAT_14001a1b0 = DAT_14001a1b0 + -8;
          KeReleaseInStackQueuedSpinLock(&local_48);
        }
        puVar8 = &local_48;
        local_48 = 0;
        uStack_40 = 0;
        local_38 = 0;
        KeAcquireInStackQueuedSpinLock(piVar10 + 0x24);
        piVar10[0x20] = piVar10[0x20] & 0xffffffdf;
        KeReleaseInStackQueuedSpinLock(&local_48);
        UsbStorPumpNextRequest((longlong)piVar14,puVar8,puVar12);
        uVar7 = 0;
        bVar6 = KeGetCurrentIrql();
        if (bVar6 < 2) {
          uVar7 = KfRaiseIrql(2);
        }
        if (*(char *)(lVar9 + 0xc0) != '\0') {
          local_48 = 0;
          uStack_40 = 0;
          local_38 = 0;
          if (DAT_14001a1a8 != (undefined4 *)0x0) {
            KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_48);
            *DAT_14001a1b0 = 0x504e5349;
            *(longlong *)(DAT_14001a1b0 + 2) = lVar9;
            *(undefined8 *)(DAT_14001a1b0 + 4) = 0;
            *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
            if (DAT_14001a1b0 <= DAT_14001a1a8) {
              DAT_14001a1b0 = DAT_14001a1b8;
            }
            DAT_14001a1b0 = DAT_14001a1b0 + -8;
            KeReleaseInStackQueuedSpinLock(&local_48);
          }
          IoStartNextPacket(lVar9,1);
        }
        if (bVar6 < 2) {
          KeLowerIrql(uVar7);
        }
      }
      else if (((char)piVar10[0x12d] == '\x01') && (puVar11 == *(undefined **)(piVar10 + 0x124))) {
        local_48 = 0;
        uStack_40 = 0;
        local_38 = 0;
        if (DAT_14001a1a8 != (undefined4 *)0x0) {
          KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0);
          *DAT_14001a1b0 = 0x36777363;
          *(longlong *)(DAT_14001a1b0 + 2) = lVar9;
          *(longlong *)(DAT_14001a1b0 + 4) = param_2;
          *(undefined **)(DAT_14001a1b0 + 6) = puVar11;
          if (DAT_14001a1b0 <= DAT_14001a1a8) {
            DAT_14001a1b0 = DAT_14001a1b8;
          }
          DAT_14001a1b0 = DAT_14001a1b0 + -8;
          KeReleaseInStackQueuedSpinLock();
        }
        *(undefined2 *)(puVar11 + 3) = 0x204;
        *(undefined4 *)(puVar11 + 0x10) = 0;
        if ((((*(uint *)(puVar11 + 0xc) & 0x20) == 0) && (puVar11[0xb] != '\0')) &&
           (*(longlong *)(puVar11 + 0x20) != 0)) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (4 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa7,
                    &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
          }
          lVar4 = *(longlong *)(lVar9 + 0x40);
          *(undefined2 **)(*(longlong *)(param_2 + 0xb8) + 8) = (undefined2 *)(lVar4 + 0x6b8);
          memset((void *)(lVar4 + 0x6ba),0,0x56);
          *(undefined2 *)(lVar4 + 0x6b8) = 0x58;
          *(undefined1 *)(lVar4 + 0x6ba) = 0;
          *(undefined1 *)(lVar4 + 0x6c2) = 0xc;
          *(undefined4 *)(lVar4 + 0x6c4) = 0x160;
          *(uint *)(lVar4 + 0x6c8) = (uint)*(byte *)(*(longlong *)(lVar4 + 0x490) + 0xb);
          *(undefined8 *)(lVar4 + 0x6d0) = *(undefined8 *)(*(longlong *)(lVar4 + 0x490) + 0x20);
          *(undefined1 *)(lVar4 + 0x700) = 3;
          *(undefined1 *)(lVar4 + 0x704) = *(undefined1 *)(*(longlong *)(lVar4 + 0x490) + 0xb);
          USBSTOR_CbwTransfer(lVar9,param_2);
          uVar13 = 0xc0000016;
        }
        else {
          uVar13 = 0xc0000185;
          *(undefined8 *)(param_2 + 0x38) = 0;
          *(undefined4 *)(param_2 + 0x30) = 0xc0000185;
          if ((*(uint *)(puVar11 + 0xc) & 0x800) != 0) {
            puVar11[3] = 6;
          }
          USBSTOR_TranslateCDBComplete(lVar9,param_2,(longlong)puVar11);
          puVar8 = &local_48;
          local_48 = 0;
          uStack_40 = 0;
          local_38 = 0;
          KeAcquireInStackQueuedSpinLock(piVar10 + 0x24);
          piVar10[0x20] = piVar10[0x20] & 0xffffffdf;
          KeReleaseInStackQueuedSpinLock(&local_48);
          UsbStorPumpNextRequest((longlong)piVar14,puVar8,puVar11);
          UsbStorStartNextPacket(lVar9);
        }
      }
      else {
        local_48 = 0;
        uStack_40 = 0;
        local_38 = 0;
        if (DAT_14001a1a8 != (undefined4 *)0x0) {
          KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_48);
          *DAT_14001a1b0 = 0x37777363;
          *(longlong *)(DAT_14001a1b0 + 2) = lVar9;
          *(longlong *)(DAT_14001a1b0 + 4) = param_2;
          *(undefined **)(DAT_14001a1b0 + 6) = puVar11;
          if (DAT_14001a1b0 <= DAT_14001a1a8) {
            DAT_14001a1b0 = DAT_14001a1b8;
          }
          DAT_14001a1b0 = DAT_14001a1b0 + -8;
          KeReleaseInStackQueuedSpinLock(&local_48);
        }
        lVar4 = *(longlong *)(piVar10 + 0x124);
        *(longlong *)(lVar5 + 8) = lVar4;
        *(undefined8 *)(param_2 + 0x38) = 0;
        uVar13 = 0xc0000185;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000185;
        *(undefined1 *)(lVar4 + 3) = 0xe;
        USBSTOR_TranslateCDBComplete(lVar9,param_2,lVar4);
        USBSTOR_QueueResetDevice(lVar9,piVar14);
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa6,
                 &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,uVar13);
      }
    }
  }
  else {
    USBSTOR_LogEntry(0x31545243,lVar9,param_2,puVar11);
    KeReleaseInStackQueuedSpinLock(&local_48);
    lVar5 = *(longlong *)(lVar4 + 0x490);
    *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8) = lVar5;
    *(undefined4 *)(param_2 + 0x30) = 0xc00000b5;
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined1 *)(lVar5 + 3) = 9;
    USBSTOR_TranslateCDBComplete(lVar9,param_2,lVar5);
    KeSetEvent(lVar4 + 0x150,0,0);
    local_48 = 0;
    uStack_40 = 0;
    local_38 = 0;
    if (DAT_14001a1a8 != (undefined4 *)0x0) {
      KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_48);
      *DAT_14001a1b0 = 0x31777363;
      *(longlong *)(DAT_14001a1b0 + 2) = lVar9;
      *(longlong *)(DAT_14001a1b0 + 4) = param_2;
      *(undefined **)(DAT_14001a1b0 + 6) = puVar11;
      if (DAT_14001a1b0 <= DAT_14001a1a8) {
        DAT_14001a1b0 = DAT_14001a1b8;
      }
      DAT_14001a1b0 = DAT_14001a1b0 + -8;
      KeReleaseInStackQueuedSpinLock(&local_48);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa2,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    }
    uVar13 = 0xc0000016;
  }
  return uVar13;
}



===== USBSTOR_LogEntry @ 140009650 =====

void USBSTOR_LogEntry(undefined4 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_28);
    *DAT_14001a1b0 = param_1;
    *(undefined8 *)(DAT_14001a1b0 + 2) = param_2;
    *(undefined8 *)(DAT_14001a1b0 + 4) = param_3;
    *(undefined8 *)(DAT_14001a1b0 + 6) = param_4;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_28);
  }
  return;
}



===== USBSTOR_CbwCompletion @ 140009720 =====

int USBSTOR_CbwCompletion(longlong param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  int *piVar6;
  longlong lVar7;
  int *piVar8;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  piVar6 = (int *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x93,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  iVar5 = *(int *)(param_2 + 0x30);
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_48);
    *DAT_14001a1b0 = 0x43574243;
    *(longlong *)(DAT_14001a1b0 + 2) = param_1;
    *(longlong *)(DAT_14001a1b0 + 4) = param_2;
    *(longlong *)(DAT_14001a1b0 + 6) = (longlong)iVar5;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_48);
  }
  piVar1 = *(int **)(param_1 + 0x40);
  if (*piVar1 == 0x214f4450) {
    piVar6 = piVar1;
    lVar7 = *(longlong *)(piVar1 + 4);
    piVar8 = *(int **)(*(longlong *)(piVar1 + 4) + 0x40);
  }
  else {
    lVar7 = 0;
    piVar8 = (int *)0x0;
    if (*piVar1 == 0x214f4446) {
      lVar7 = param_1;
      piVar8 = piVar1;
    }
  }
  lVar2 = *(longlong *)(lVar7 + 0x40);
  lVar3 = *(longlong *)(param_2 + 0xb8);
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  lVar4 = *(longlong *)(lVar3 + 8);
  KeAcquireInStackQueuedSpinLock(lVar2 + 0x90,&local_48);
  *(uint *)(lVar2 + 0x80) = *(uint *)(lVar2 + 0x80) & 0xfffffffd;
  if ((*(uint *)(lVar2 + 0x80) & 8) != 0) {
    USBSTOR_LogEntry(0x31545243,lVar7,param_2,lVar4);
    KeReleaseInStackQueuedSpinLock(&local_48);
    lVar3 = *(longlong *)(lVar2 + 0x490);
    *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8) = lVar3;
    *(undefined4 *)(param_2 + 0x30) = 0xc00000b5;
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined1 *)(lVar3 + 3) = 9;
    USBSTOR_TranslateCDBComplete(lVar7,param_2,lVar3);
    KeSetEvent(lVar2 + 0x150,0,0);
    local_48 = 0;
    uStack_40 = 0;
    local_38 = 0;
    if (DAT_14001a1a8 != (undefined4 *)0x0) {
      KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_48);
      *DAT_14001a1b0 = 0x31776263;
      *(longlong *)(DAT_14001a1b0 + 2) = lVar7;
      *(longlong *)(DAT_14001a1b0 + 4) = param_2;
      *(longlong *)(DAT_14001a1b0 + 6) = lVar4;
      if (DAT_14001a1b0 <= DAT_14001a1a8) {
        DAT_14001a1b0 = DAT_14001a1b8;
      }
      DAT_14001a1b0 = DAT_14001a1b0 + -8;
      KeReleaseInStackQueuedSpinLock(&local_48);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x94,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    }
    return -0x3fffffea;
  }
  *(undefined8 *)(lVar2 + 0x148) = 0;
  KeReleaseInStackQueuedSpinLock(&local_48);
  if (*(int *)(param_2 + 0x30) < 0) {
    USBSTOR_LogEntry(0x32776263,(longlong)*(int *)(param_2 + 0x30),(longlong)piVar8[99],0);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x95,
                &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,*(undefined4 *)(param_2 + 0x30),
                (char)piVar8[99]);
    }
    lVar2 = *(longlong *)(piVar8 + 0x124);
    *(longlong *)(lVar3 + 8) = lVar2;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000185;
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined1 *)(lVar2 + 3) = 0xe;
    USBSTOR_TranslateCDBComplete(lVar7,param_2,lVar2);
    USBSTOR_QueueResetDevice(lVar7,piVar6);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x96,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    }
    return -0x3ffffe7b;
  }
  if (((*(longlong *)(param_2 + 8) == 0) || ((*(uint *)(lVar4 + 0xc) & 0xc0) == 0)) &&
     (lVar4 == *(longlong *)(piVar8 + 0x124))) {
    local_48 = 0;
    uStack_40 = 0;
    local_38 = 0;
    if (DAT_14001a1a8 != (undefined4 *)0x0) {
      KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_48);
      *DAT_14001a1b0 = 0x34776263;
      *(longlong *)(DAT_14001a1b0 + 2) = lVar7;
      *(longlong *)(DAT_14001a1b0 + 4) = param_2;
      *(longlong *)(DAT_14001a1b0 + 6) = lVar4;
      if (DAT_14001a1b0 <= DAT_14001a1a8) {
        DAT_14001a1b0 = DAT_14001a1b8;
      }
      DAT_14001a1b0 = DAT_14001a1b0 + -8;
      KeReleaseInStackQueuedSpinLock(&local_48);
    }
    *(undefined1 *)(lVar4 + 3) = 1;
    USBSTOR_CswTransfer(lVar7,param_2);
  }
  else {
    local_48 = 0;
    uStack_40 = 0;
    local_38 = 0;
    if (DAT_14001a1a8 != (undefined4 *)0x0) {
      KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_48);
      *DAT_14001a1b0 = 0x33776263;
      *(longlong *)(DAT_14001a1b0 + 2) = lVar7;
      *(longlong *)(DAT_14001a1b0 + 4) = param_2;
      *(longlong *)(DAT_14001a1b0 + 6) = lVar4;
      if (DAT_14001a1b0 <= DAT_14001a1a8) {
        DAT_14001a1b0 = DAT_14001a1b8;
      }
      DAT_14001a1b0 = DAT_14001a1b0 + -8;
      KeReleaseInStackQueuedSpinLock(&local_48);
    }
    iVar5 = USBSTOR_DataTransfer(lVar7,param_2);
    if (iVar5 < 0) {
      lVar2 = *(longlong *)(piVar8 + 0x124);
      *(longlong *)(lVar3 + 8) = lVar2;
      *(int *)(param_2 + 0x30) = iVar5;
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(undefined1 *)(lVar2 + 3) = 4;
      USBSTOR_TranslateCDBComplete(lVar7,param_2,lVar2);
      USBSTOR_QueueResetDevice(lVar7,piVar6);
      goto LAB_140009a25;
    }
  }
  iVar5 = -0x3fffffea;
LAB_140009a25:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x97,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar5);
  }
  return iVar5;
}



===== USBSTOR_DataCompletion @ 140009d00 =====

undefined8 USBSTOR_DataCompletion(longlong param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  undefined1 uVar8;
  int *piVar9;
  longlong lVar10;
  int *piVar11;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  piVar11 = (int *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9a,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  iVar1 = *(int *)(param_2 + 0x30);
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_48);
    *DAT_14001a1b0 = 0x43444b42;
    *(longlong *)(DAT_14001a1b0 + 2) = param_1;
    *(longlong *)(DAT_14001a1b0 + 4) = param_2;
    *(longlong *)(DAT_14001a1b0 + 6) = (longlong)iVar1;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_48);
  }
  piVar4 = *(int **)(param_1 + 0x40);
  if (*piVar4 == 0x214f4450) {
    piVar9 = *(int **)(*(longlong *)(piVar4 + 4) + 0x40);
    lVar10 = *(longlong *)(piVar4 + 4);
    piVar11 = piVar4;
  }
  else {
    piVar9 = (int *)0x0;
    lVar10 = 0;
    if (*piVar4 == 0x214f4446) {
      piVar9 = piVar4;
      lVar10 = param_1;
    }
  }
  lVar5 = *(longlong *)(param_2 + 0xb8);
  lVar6 = *(longlong *)(lVar5 + 8);
  if ((lVar6 == *(longlong *)(piVar9 + 0x124)) &&
     (*(longlong *)(piVar9 + 0x6e) != *(longlong *)(param_2 + 8))) {
    IoFreeMdl();
  }
  lVar7 = *(longlong *)(lVar10 + 0x40);
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  KeAcquireInStackQueuedSpinLock(lVar7 + 0x90,&local_48);
  *(uint *)(lVar7 + 0x80) = *(uint *)(lVar7 + 0x80) & 0xfffffffd;
  if ((*(uint *)(lVar7 + 0x80) & 8) == 0) {
    *(undefined8 *)(lVar7 + 0x148) = 0;
    KeReleaseInStackQueuedSpinLock(&local_48);
    iVar1 = *(int *)(param_2 + 0x30);
    if (iVar1 < 0) {
      iVar3 = piVar9[99];
      local_48 = 0;
      uStack_40 = 0;
      local_38 = 0;
      if (DAT_14001a1a8 != (undefined4 *)0x0) {
        KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_48);
        *DAT_14001a1b0 = 0x32646b62;
        *(longlong *)(DAT_14001a1b0 + 2) = (longlong)iVar1;
        *(longlong *)(DAT_14001a1b0 + 4) = (longlong)iVar3;
        *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
        if (DAT_14001a1b0 <= DAT_14001a1a8) {
          DAT_14001a1b0 = DAT_14001a1b8;
        }
        DAT_14001a1b0 = DAT_14001a1b0 + -8;
        KeReleaseInStackQueuedSpinLock(&local_48);
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9c,
                  &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,*(undefined4 *)(param_2 + 0x30),
                  (char)piVar9[99]);
      }
      if ((piVar9[99] & 0xfffffffU) != 4) {
        USBSTOR_LogEntry(0x34646b62,lVar10,param_2,lVar6);
        lVar6 = *(longlong *)(piVar9 + 0x124);
        *(longlong *)(lVar5 + 8) = lVar6;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000185;
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined1 *)(lVar6 + 3) = 0xe;
        USBSTOR_TranslateCDBComplete(lVar10,param_2,lVar6);
        USBSTOR_QueueResetDevice(lVar10,piVar11);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9d,
                  &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
        }
        return 0xc0000185;
      }
      piVar9[0x1ac] = piVar9[0x1ac] + 1;
      *(int *)(lVar6 + 0x10) = piVar9[0x6b];
      uVar8 = 6;
      if ((*(uint *)(lVar6 + 0xc) & 0x800) == 0) {
        uVar8 = 0x12;
      }
      *(undefined1 *)(lVar6 + 3) = uVar8;
      local_48 = 0;
      uStack_40 = 0;
      local_38 = 0;
      if (DAT_14001a1a8 != (undefined4 *)0x0) {
        KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_48);
        *DAT_14001a1b0 = 0x33646b62;
        *(longlong *)(DAT_14001a1b0 + 2) = lVar10;
        *(longlong *)(DAT_14001a1b0 + 4) = param_2;
        *(longlong *)(DAT_14001a1b0 + 6) = lVar6;
        if (DAT_14001a1b0 <= DAT_14001a1a8) {
          DAT_14001a1b0 = DAT_14001a1b8;
        }
        DAT_14001a1b0 = DAT_14001a1b0 + -8;
        KeReleaseInStackQueuedSpinLock(&local_48);
      }
      USBSTOR_BulkQueueResetPipe(lVar10,param_2);
    }
    else {
      uVar8 = 0x12;
      if (*(uint *)(lVar6 + 0x10) <= (uint)piVar9[0x6b]) {
        uVar8 = 1;
      }
      *(undefined1 *)(lVar6 + 3) = uVar8;
      *(int *)(lVar6 + 0x10) = piVar9[0x6b];
      uVar2 = piVar9[0x6b];
      local_48 = 0;
      uStack_40 = 0;
      local_38 = 0;
      if (DAT_14001a1a8 != (undefined4 *)0x0) {
        KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_48);
        *DAT_14001a1b0 = 0x35646b62;
        *(longlong *)(DAT_14001a1b0 + 2) = lVar10;
        *(longlong *)(DAT_14001a1b0 + 4) = param_2;
        *(ulonglong *)(DAT_14001a1b0 + 6) = (ulonglong)uVar2;
        if (DAT_14001a1b0 <= DAT_14001a1a8) {
          DAT_14001a1b0 = DAT_14001a1b8;
        }
        DAT_14001a1b0 = DAT_14001a1b0 + -8;
        KeReleaseInStackQueuedSpinLock(&local_48);
      }
      USBSTOR_CswTransfer(lVar10,param_2);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9e,
                 &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,0xc0000016);
      }
    }
  }
  else {
    USBSTOR_LogEntry(0x31545243,lVar10,param_2,lVar6);
    KeReleaseInStackQueuedSpinLock(&local_48);
    lVar5 = *(longlong *)(lVar7 + 0x490);
    *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8) = lVar5;
    *(undefined4 *)(param_2 + 0x30) = 0xc00000b5;
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined1 *)(lVar5 + 3) = 9;
    USBSTOR_TranslateCDBComplete(lVar10,param_2,lVar5);
    KeSetEvent(lVar7 + 0x150,0,0);
    local_48 = 0;
    uStack_40 = 0;
    local_38 = 0;
    if (DAT_14001a1a8 != (undefined4 *)0x0) {
      KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_48);
      *DAT_14001a1b0 = 0x31646b62;
      *(longlong *)(DAT_14001a1b0 + 2) = lVar10;
      *(longlong *)(DAT_14001a1b0 + 4) = param_2;
      *(longlong *)(DAT_14001a1b0 + 6) = lVar6;
      if (DAT_14001a1b0 <= DAT_14001a1a8) {
        DAT_14001a1b0 = DAT_14001a1b8;
      }
      DAT_14001a1b0 = DAT_14001a1b0 + -8;
      KeReleaseInStackQueuedSpinLock(&local_48);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9b,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    }
  }
  return 0xc0000016;
}



===== USBSTOR_CswTransfer @ 14000a3e0 =====

int USBSTOR_CswTransfer(longlong param_1,longlong param_2)

{
  char cVar1;
  short sVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  longlong lVar6;
  undefined8 uVar7;
  bool bVar8;
  uint uVar9;
  int iVar10;
  undefined4 uVar11;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9f,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_78);
    *DAT_14001a1b0 = 0x57534349;
    *(longlong *)(DAT_14001a1b0 + 2) = param_1;
    *(longlong *)(DAT_14001a1b0 + 4) = param_2;
    *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_78);
  }
  lVar3 = *(longlong *)(param_1 + 0x40);
  local_60 = 0;
  uStack_58 = 0;
  sVar2 = **(short **)(lVar3 + 0x60);
  uVar4 = *(undefined8 *)(*(short **)(lVar3 + 0x60) + 4);
  uVar11 = 0x200;
  if (sVar2 != 0x200) {
    uVar11 = 0xd;
  }
  cVar1 = *(char *)(lVar3 + 0x754);
  uVar9 = 2;
  if (sVar2 != 0x200) {
    uVar9 = 0;
  }
  uVar5 = *(undefined8 *)(lVar3 + 0x6a8);
  local_50 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x58,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_78);
    *DAT_14001a1b0 = 0x52494249;
    *(longlong *)(DAT_14001a1b0 + 2) = param_1;
    *(longlong *)(DAT_14001a1b0 + 4) = param_2;
    *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_78);
  }
  lVar6 = *(longlong *)(param_1 + 0x40);
  uVar7 = *(undefined8 *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  *(undefined8 *)(lVar6 + 0x18a) = 0;
  *(undefined8 *)(lVar6 + 0x192) = 0;
  *(undefined8 *)(lVar6 + 0x19a) = 0;
  *(undefined8 *)(lVar6 + 0x1a2) = 0;
  *(undefined8 *)(lVar6 + 0x1aa) = 0;
  *(undefined8 *)(lVar6 + 0x1b2) = 0;
  *(undefined8 *)(lVar6 + 0x1ba) = 0;
  *(undefined8 *)(lVar6 + 0x1c2) = 0;
  *(undefined8 *)(lVar6 + 0x1ca) = 0;
  *(undefined8 *)(lVar6 + 0x1d2) = 0;
  *(undefined8 *)(lVar6 + 0x1da) = 0;
  *(undefined8 *)(lVar6 + 0x1e2) = 0;
  *(undefined8 *)(lVar6 + 0x1ea) = 0;
  *(undefined8 *)(lVar6 + 0x1f2) = 0;
  *(undefined8 *)(lVar6 + 0x1fa) = 0;
  *(undefined4 *)(lVar6 + 0x202) = 0;
  *(undefined2 *)(lVar6 + 0x206) = 0;
  *(undefined4 *)(lVar6 + 0x188) = 0x90080;
  *(undefined8 *)(lVar6 + 0x1a0) = uVar4;
  *(uint *)(lVar6 + 0x1a8) = -(uint)(cVar1 != '\0') & 0x10 | uVar9;
  *(undefined4 *)(lVar6 + 0x1ac) = uVar11;
  *(longlong *)(lVar6 + 0x1b0) = lVar3 + 0x4a8;
  *(undefined8 *)(lVar6 + 0x1b8) = uVar5;
  lVar3 = *(longlong *)(param_2 + 0xb8);
  *(undefined4 **)(lVar3 + -0x40) = (undefined4 *)(lVar6 + 0x188);
  *(undefined1 *)(lVar3 + -0x48) = 0xf;
  *(undefined4 *)(lVar3 + -0x30) = 0x220003;
  lVar3 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar3 + -0x10) = USBSTOR_CswCompletion;
  *(undefined8 *)(lVar3 + -8) = 0;
  *(undefined1 *)(lVar3 + -0x45) = 0xe0;
  KeAcquireInStackQueuedSpinLock(lVar6 + 0x90,&local_60);
  uVar9 = *(uint *)(lVar6 + 0x80);
  *(longlong *)(lVar6 + 0x148) = param_2;
  if (((uVar9 & 0x40) == 0) || ((uVar9 & 8) != 0)) {
    bVar8 = false;
  }
  else {
    bVar8 = true;
  }
  *(uint *)(lVar6 + 0x80) = uVar9 & 0xffffffbf | 2;
  KeReleaseInStackQueuedSpinLock(&local_60);
  iVar10 = IofCallDriver(*(undefined8 *)(lVar6 + 0x18),param_2);
  if (bVar8) {
    USBSTOR_LogEntry(0x4f544942,param_1,param_2,uVar7);
    USBSTOR_QueueResetDevice(param_1,uVar7);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x59,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar10);
  }
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_48);
    *DAT_14001a1b0 = 0x72696269;
    *(longlong *)(DAT_14001a1b0 + 2) = param_1;
    *(longlong *)(DAT_14001a1b0 + 4) = param_2;
    *(longlong *)(DAT_14001a1b0 + 6) = (longlong)iVar10;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_48);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa0,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar10);
  }
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_48);
    *DAT_14001a1b0 = 0x77736369;
    *(longlong *)(DAT_14001a1b0 + 2) = param_1;
    *(longlong *)(DAT_14001a1b0 + 4) = param_2;
    *(longlong *)(DAT_14001a1b0 + 6) = (longlong)iVar10;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_48);
  }
  return iVar10;
}



===== USBSTOR_DataTransfer @ 14000a980 =====

int USBSTOR_DataTransfer(longlong param_1,longlong param_2)

{
  char cVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  bool bVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  longlong lVar11;
  longlong lVar12;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  iVar10 = -0x3ffffff3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x98,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_88);
    *DAT_14001a1b0 = 0x444b4249;
    *(longlong *)(DAT_14001a1b0 + 2) = param_1;
    *(longlong *)(DAT_14001a1b0 + 4) = param_2;
    *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_88);
  }
  lVar3 = *(longlong *)(param_1 + 0x40);
  lVar4 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  uVar9 = *(uint *)(lVar4 + 0xc) & 0xc0;
  if (uVar9 == 0x40) {
    lVar11 = *(longlong *)(lVar3 + 0x60);
    uVar9 = 3;
  }
  else {
    if (uVar9 != 0x80) {
      return -0x3ffffff3;
    }
    lVar11 = *(longlong *)(lVar3 + 0x68);
    uVar9 = 0;
  }
  uVar5 = *(undefined8 *)(lVar11 + 8);
  cVar1 = *(char *)(lVar3 + 0x754);
  lVar11 = 0;
  lVar12 = 0;
  if (lVar4 == *(longlong *)(lVar3 + 0x490)) {
    lVar11 = *(longlong *)(param_2 + 8);
    lVar3 = lVar11;
    if ((ulonglong)*(uint *)(lVar11 + 0x2c) + *(longlong *)(lVar11 + 0x20) !=
        *(longlong *)(lVar4 + 0x18)) {
      lVar11 = IoAllocateMdl(*(longlong *)(lVar4 + 0x18),*(undefined4 *)(lVar4 + 0x10),0,0,0);
      if (lVar11 == 0) {
        iVar10 = -0x3fffff66;
        goto LAB_14000aad7;
      }
      IoBuildPartialMdl(*(undefined8 *)(param_2 + 8),lVar11,*(undefined8 *)(lVar4 + 0x18),
                        *(undefined4 *)(lVar4 + 0x10));
      lVar3 = lVar11;
    }
  }
  else {
    lVar12 = *(longlong *)(lVar4 + 0x18);
    lVar3 = lVar12;
  }
  if (lVar3 != 0) {
    uVar2 = *(undefined4 *)(lVar4 + 0x10);
    local_60 = 0;
    local_70 = 0;
    uStack_68 = 0;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)((longlong)WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
       (4 < *(byte *)((longlong)WPP_GLOBAL_Control + 0x29))) {
      WPP_SF_(*(undefined **)((longlong)WPP_GLOBAL_Control + 0x18),0x58,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    }
    local_88 = 0;
    uStack_80 = 0;
    local_78 = 0;
    if (DAT_14001a1a8 != (undefined4 *)0x0) {
      KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0);
      *DAT_14001a1b0 = 0x52494249;
      *(longlong *)(DAT_14001a1b0 + 2) = param_1;
      *(longlong *)(DAT_14001a1b0 + 4) = param_2;
      *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
      if (DAT_14001a1b0 <= DAT_14001a1a8) {
        DAT_14001a1b0 = DAT_14001a1b8;
      }
      DAT_14001a1b0 = DAT_14001a1b0 + -8;
      KeReleaseInStackQueuedSpinLock(&local_88);
    }
    lVar3 = *(longlong *)(param_1 + 0x40);
    uVar6 = *(undefined8 *)(*(longlong *)(param_2 + 0xb8) + 0x10);
    memset((void *)(lVar3 + 0x18a),0,0x7e);
    *(undefined4 *)(lVar3 + 0x1ac) = uVar2;
    *(undefined4 *)(lVar3 + 0x188) = 0x90080;
    *(undefined8 *)(lVar3 + 0x1a0) = uVar5;
    *(uint *)(lVar3 + 0x1a8) = uVar9 | -(uint)(cVar1 != '\0') & 0x10;
    *(longlong *)(lVar3 + 0x1b0) = lVar12;
    *(longlong *)(lVar3 + 0x1b8) = lVar11;
    lVar4 = *(longlong *)(param_2 + 0xb8);
    *(undefined1 *)(lVar4 + -0x48) = 0xf;
    *(undefined4 *)(lVar4 + -0x30) = 0x220003;
    *(undefined4 **)(lVar4 + -0x40) = (undefined4 *)(lVar3 + 0x188);
    lVar4 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar4 + -0x10) = USBSTOR_DataCompletion;
    *(undefined8 *)(lVar4 + -8) = 0;
    *(undefined1 *)(lVar4 + -0x45) = 0xe0;
    KeAcquireInStackQueuedSpinLock(lVar3 + 0x90,&local_70);
    uVar9 = *(uint *)(lVar3 + 0x80);
    *(longlong *)(lVar3 + 0x148) = param_2;
    if (((uVar9 & 0x40) == 0) || ((uVar9 & 8) != 0)) {
      bVar7 = false;
    }
    else {
      bVar7 = true;
    }
    *(uint *)(lVar3 + 0x80) = uVar9 & 0xffffffbf | 2;
    KeReleaseInStackQueuedSpinLock(&local_70);
    iVar10 = IofCallDriver(*(undefined8 *)(lVar3 + 0x18),param_2);
    if (bVar7) {
      USBSTOR_LogEntry(0x4f544942,param_1,param_2,uVar6);
      USBSTOR_QueueResetDevice(param_1,uVar6);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x59,
               &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar10);
    }
    local_58 = 0;
    uStack_50 = 0;
    local_48 = 0;
    if (DAT_14001a1a8 != (undefined4 *)0x0) {
      KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_58);
      *DAT_14001a1b0 = 0x72696269;
      *(longlong *)(DAT_14001a1b0 + 2) = param_1;
      *(longlong *)(DAT_14001a1b0 + 4) = param_2;
      *(longlong *)(DAT_14001a1b0 + 6) = (longlong)iVar10;
      if (DAT_14001a1b0 <= DAT_14001a1a8) {
        DAT_14001a1b0 = DAT_14001a1b8;
      }
      DAT_14001a1b0 = DAT_14001a1b0 + -8;
      KeReleaseInStackQueuedSpinLock(&local_58);
    }
    iVar10 = 0;
  }
LAB_14000aad7:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x99,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar10);
  }
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_58);
    *DAT_14001a1b0 = 0x646b6269;
    *(longlong *)(DAT_14001a1b0 + 2) = param_1;
    *(longlong *)(DAT_14001a1b0 + 4) = param_2;
    *(longlong *)(DAT_14001a1b0 + 6) = (longlong)iVar10;
    puVar8 = DAT_14001a1b8;
    if (DAT_14001a1a8 < DAT_14001a1b0) {
      puVar8 = DAT_14001a1b0;
    }
    DAT_14001a1b0 = puVar8 + -8;
    KeReleaseInStackQueuedSpinLock(&local_58);
  }
  return iVar10;
}



===== USBSTOR_QueueResetDevice @ 14000afcc =====

void USBSTOR_QueueResetDevice(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 in_stack_ffffffffffffffc8;
  undefined4 uVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar5 = (undefined4)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  USBSTOR_LogEntry(0x44535251,param_1,0,0);
  lVar2 = *(longlong *)(param_1 + 0x40);
  uVar4 = 1;
  iVar3 = IoAcquireRemoveLockEx(lVar2 + 0x728,USBSTOR_ResetDeviceWorkItem,"",1,CONCAT44(uVar5,0x20))
  ;
  if (-1 < iVar3) {
    KeAcquireInStackQueuedSpinLock(lVar2 + 0x90,&local_28);
    uVar1 = *(uint *)(lVar2 + 0x80);
    if ((uVar1 & 8) == 0) {
      *(uint *)(lVar2 + 0x80) = uVar1 | 8;
      KeReleaseInStackQueuedSpinLock(&local_28);
      USBSTOR_QueueWorkItem
                (param_1,*(longlong *)(lVar2 + 0x170),USBSTOR_ResetDeviceWorkItem,uVar4,param_2,
                 *(char *)(lVar2 + 0x754) == '\0');
    }
    else {
      USBSTOR_LogEntry(0x4453524e,param_1,(ulonglong)uVar1,0);
      KeReleaseInStackQueuedSpinLock(&local_28);
      IoReleaseRemoveLockEx(lVar2 + 0x728,USBSTOR_ResetDeviceWorkItem,0x20);
    }
  }
  return;
}



===== USBSTOR_BulkQueueResetPipe @ 14000b108 =====

void USBSTOR_BulkQueueResetPipe(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_28);
    *DAT_14001a1b0 = 0x50535251;
    *(longlong *)(DAT_14001a1b0 + 2) = param_1;
    *(undefined8 *)(DAT_14001a1b0 + 4) = param_2;
    *(undefined8 *)(DAT_14001a1b0 + 6) = 0;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_28);
  }
  lVar1 = *(longlong *)(param_1 + 0x40);
  iVar4 = IoAcquireRemoveLockEx(lVar1 + 0x728,USBSTOR_BulkResetPipeWorkItem,"",1,0x20);
  if (iVar4 < 0) {
    return;
  }
  lVar2 = *(longlong *)(lVar1 + 0x170);
  if (*(char *)(lVar1 + 0x754) != '\0') {
    cVar3 = IoTryQueueWorkItem(lVar2,USBSTOR_BulkResetPipeWorkItem,0,param_2);
    if (cVar3 != '\0') {
      return;
    }
    if ((EmergencyWorkerThread != 0) && (uVar5 = IoSizeofWorkItem(), 0x27 < uVar5)) {
      ObfReferenceObject(param_1);
      *(longlong *)(lVar2 + 0x18) = param_1;
      *(code **)(lVar2 + 0x10) = USBSTOR_BulkResetPipeWorkItem;
      *(undefined8 *)(lVar2 + 0x20) = param_2;
      *(longlong *)(lVar2 + 8) = lVar2;
      *(longlong *)lVar2 = lVar2;
      KeInsertQueue(&EmergencyWorkQueue,lVar2);
      return;
    }
  }
  IoQueueWorkItemEx(lVar2,USBSTOR_BulkResetPipeWorkItem,0,param_2);
  return;
}



===== USBSTOR_Power @ 14000b2c0 =====

int USBSTOR_Power(longlong param_1,undefined *param_2)

{
  char cVar1;
  int *piVar2;
  longlong lVar3;
  int iVar4;
  char *pcVar5;
  undefined *puVar6;
  undefined *puVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  
  piVar2 = *(int **)(param_1 + 0x40);
  lVar3 = *(longlong *)(param_2 + 0xb8);
  pcVar9 = "PDO";
  pcVar10 = "FDO";
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar6 = param_2;
    puVar7 = WPP_GLOBAL_Control;
    pcVar5 = PowerMinorFunctionString(*(char *)(lVar3 + 1));
    pcVar8 = "FDO";
    if (*piVar2 != 0x214f4446) {
      pcVar8 = pcVar9;
    }
    WPP_SF_sqqs(*(undefined8 *)(puVar7 + 0x18),puVar6,puVar7,pcVar8,(char)param_1,(char)param_2,
                pcVar5);
  }
  USBSTOR_LogEntry(0x52574f50,param_1,param_2,(ulonglong)*(byte *)(lVar3 + 1));
  iVar4 = 0;
  if (((*(char *)(lVar3 + 1) == '\x02') && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)
      ) && (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29])
            ))) {
    puVar6 = WPP_GLOBAL_Control;
    if (*(int *)(lVar3 + 0x10) == 0) {
      pcVar9 = PowerSystemStateString(*(int *)(lVar3 + 0x18));
    }
    else {
      pcVar9 = PowerDeviceStateString(*(int *)(lVar3 + 0x18));
    }
    if (*piVar2 != 0x214f4446) {
      pcVar10 = "PDO";
    }
    WPP_SF_ss(*(undefined8 *)(puVar6 + 0x18),puVar6,pcVar9,pcVar10,pcVar9);
  }
  cVar1 = *(char *)(lVar3 + 1);
  if (*piVar2 == 0x214f4446) {
    if (cVar1 == '\x02') {
      iVar4 = USBSTOR_FdoSetPower(param_1,(longlong)param_2);
    }
    else {
      PoStartNextPowerIrp(param_2);
      param_2[0x43] = param_2[0x43] + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      iVar4 = PoCallDriver(*(undefined8 *)(piVar2 + 6),param_2);
    }
  }
  else if (cVar1 == '\x02') {
    iVar4 = USBSTOR_PdoSetPower(param_1,param_2);
  }
  else {
    if (cVar1 == '\x03') {
      *(undefined4 *)(param_2 + 0x30) = 0;
    }
    else {
      iVar4 = *(int *)(param_2 + 0x30);
    }
    PoStartNextPowerIrp(param_2);
    IofCompleteRequest(param_2,0);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar4);
  }
  USBSTOR_LogEntry(0x72776f70,(longlong)iVar4,0,0);
  return iVar4;
}



===== USBSTOR_InternalCDBCompletionRoutine @ 14000b4c0 =====

undefined8
USBSTOR_InternalCDBCompletionRoutine(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  USBSTOR_LogEntry(0x52434349,param_1,param_2,(longlong)*(int *)(param_2 + 0x30));
  IoFreeIrp(param_2);
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== USBSTOR_PdoSetPower @ 14000b520 =====

int USBSTOR_PdoSetPower(longlong param_1,undefined *param_2)

{
  int iVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  longlong lVar7;
  undefined *puVar8;
  int iVar9;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  iVar3 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  iVar1 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar8 = WPP_GLOBAL_Control;
    if (iVar3 == 0) {
      pcVar5 = PowerSystemStateString(iVar1);
    }
    else {
      pcVar5 = PowerDeviceStateString(iVar1);
    }
    WPP_SF_qs(*(undefined8 *)(puVar8 + 0x18),0x29,puVar8,param_1,pcVar5);
  }
  USBSTOR_LogEntry(0x50534450,param_1,param_2,(longlong)iVar3);
  iVar4 = 0;
  if (iVar3 == 0) {
    iVar3 = *(int *)(lVar2 + 0x30);
    *(int *)(lVar2 + 0x2c) = iVar1;
    iVar9 = 4;
    if (iVar1 == 1) {
      iVar9 = 1;
    }
    if (iVar3 != iVar9) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        puVar8 = WPP_GLOBAL_Control;
        pcVar5 = PowerDeviceStateString(iVar9);
        pcVar6 = PowerDeviceStateString(iVar3);
        WPP_SF_qqss(*(undefined8 *)(puVar8 + 0x18),0x2a,pcVar5,param_1,(char)param_2,pcVar6,pcVar5);
      }
      if (iVar9 < *(int *)(lVar2 + 0x30)) {
        iVar3 = PoRequestPowerIrp();
        iVar4 = 0;
        if (iVar3 < 0) {
          iVar4 = iVar3;
        }
      }
      else {
        *(undefined **)(lVar2 + 0x38) = param_2;
        iVar4 = PoRequestPowerIrp(param_1,2,iVar9,USBSTOR_PdoSetPowerCompletion,0,0);
        if (-1 < iVar4) goto LAB_14000b7e3;
        *(undefined8 *)(lVar2 + 0x38) = 0;
      }
    }
  }
  else if (iVar3 == 1) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      puVar8 = WPP_GLOBAL_Control;
      pcVar5 = PowerDeviceStateString(iVar1);
      pcVar6 = PowerDeviceStateString(*(int *)(lVar2 + 0x30));
      WPP_SF_qqss(*(undefined8 *)(puVar8 + 0x18),0x2b,pcVar5,param_1,(char)param_2,pcVar6,pcVar5);
    }
    iVar3 = *(int *)(lVar2 + 0x30);
    *(int *)(lVar2 + 0x30) = iVar1;
    if (iVar3 == 1) {
      if (1 < iVar1) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
                  &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
        }
        USBSTOR_LogEntry(0x64727770,param_1,param_2,0);
      }
    }
    else if ((1 < iVar3) && (iVar1 == 1)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29])))
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
                &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
      }
      lVar7 = param_1;
      puVar8 = param_2;
      USBSTOR_LogEntry(0x75727770,param_1,param_2,0);
      if (*(char *)(lVar2 + 0x2a0) == '\0') {
        UsbQueueRestart(param_1,lVar7,puVar8);
      }
    }
    PoSetPowerState(param_1,1);
  }
  *(int *)(param_2 + 0x30) = iVar4;
  PoStartNextPowerIrp(param_2);
  IofCompleteRequest(param_2,0);
LAB_14000b7e3:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar4);
  }
  USBSTOR_LogEntry(0x70736470,(longlong)iVar4,0,0);
  return iVar4;
}



===== USBSTOR_FdoSetPower @ 14000b850 =====

int USBSTOR_FdoSetPower(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong lVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  undefined *puVar8;
  int iVar9;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  iVar5 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  iVar1 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar8 = WPP_GLOBAL_Control;
    if (iVar5 == 0) {
      pcVar6 = PowerSystemStateString(iVar1);
    }
    else {
      pcVar6 = PowerDeviceStateString(iVar1);
    }
    WPP_SF_qs(*(undefined8 *)(puVar8 + 0x18),0x20,puVar8,param_1,pcVar6);
  }
  USBSTOR_LogEntry(0x50534446,param_1,param_2,(longlong)iVar5);
  if (iVar5 == 0) {
    iVar5 = *(int *)(lVar2 + 0x9c);
    *(int *)(lVar2 + 0x98) = iVar1;
    iVar9 = 4;
    if (iVar1 == 1) {
      iVar9 = 1;
    }
    if (iVar5 == iVar9) {
      if ((((*(uint *)(param_1 + 0x30) & 0x2000) == 0) && (iVar5 == 4)) && (iVar1 - 4U < 2)) {
        *(longlong *)(lVar2 + 0xa0) = param_2;
        *(undefined4 *)(lVar2 + 0x788) = 1;
        iVar5 = PoRequestPowerIrp(*(undefined8 *)(lVar2 + 0x10),2,1,
                                  USBSTOR_FdoSetPowerD3ToD0Completion,param_1,0);
        goto LAB_14000bc24;
      }
      if (((iVar1 == 1) && (*(longlong *)(lVar2 + 0x7b0) != 0)) &&
         ((PoFxReportDevicePoweredOn(), (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control &&
          (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29]))
          )))) {
        puVar8 = WPP_GLOBAL_Control;
        pcVar6 = PowerDeviceStateString(*(int *)(lVar2 + 0x9c));
        WPP_SF_qs(*(undefined8 *)(puVar8 + 0x18),0x22,puVar8,param_1,pcVar6);
      }
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        puVar8 = WPP_GLOBAL_Control;
        pcVar6 = PowerDeviceStateString(iVar9);
        pcVar7 = PowerDeviceStateString(iVar5);
        WPP_SF_qqss(*(undefined8 *)(puVar8 + 0x18),0x21,pcVar6,param_1,(char)param_2,pcVar7,pcVar6);
      }
      if (*(int *)(lVar2 + 0x9c) <= iVar9) {
        *(longlong *)(lVar2 + 0xa0) = param_2;
        if ((*(uint *)(param_1 + 0x30) & 0x2000) == 0) {
          *(int *)(lVar2 + 0x788) = iVar9;
          USBSTOR_FdoSetPowerSx(param_1);
          iVar5 = 0x103;
        }
        else {
          iVar5 = PoRequestPowerIrp(*(undefined8 *)(lVar2 + 0x10),2,iVar9,
                                    USBSTOR_FdoSetPowerCompletion,param_1,0);
        }
        goto LAB_14000bc24;
      }
      iVar5 = PoRequestPowerIrp(*(undefined8 *)(lVar2 + 0x10),2,iVar9,USBSTOR_FdoSetPowerCompletion,
                                param_1,0);
      if ((iVar5 < 0) && (*(longlong *)(lVar2 + 0x7b0) != 0)) {
        PoFxReportDevicePoweredOn();
      }
    }
  }
  else if (iVar5 == 1) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      puVar8 = WPP_GLOBAL_Control;
      pcVar6 = PowerDeviceStateString(iVar1);
      pcVar7 = PowerDeviceStateString(*(int *)(lVar2 + 0x9c));
      WPP_SF_qqss(*(undefined8 *)(puVar8 + 0x18),0x23,pcVar6,param_1,(char)param_2,pcVar7,pcVar6);
    }
    iVar5 = *(int *)(lVar2 + 0x9c);
    *(int *)(lVar2 + 0x9c) = iVar1;
    if (iVar5 == 1) {
      if ((1 < iVar1) && ((*(uint *)(param_1 + 0x30) & 0x2000) != 0)) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29])
            ))) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                  &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
        }
        USBSTOR_LogEntry(0x44525750,param_1,param_2,0);
        IoStartPacket(param_1,param_2);
        KeWaitForSingleObject(lVar2 + 0xa8,0,0,0,0);
      }
    }
    else if ((1 < iVar5) && (iVar1 == 1)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0 && (3 < (byte)WPP_GLOBAL_Control[0x29])))
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
                &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
      }
      USBSTOR_LogEntry(0x55525750,param_1,param_2,0);
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
      lVar4 = *(longlong *)(param_2 + 0xb8);
      *(undefined8 *)(lVar4 + -8) = 0;
      *(code **)(lVar4 + -0x10) = USBSTOR_FdoSetPowerD0Completion;
      *(undefined1 *)(lVar4 + -0x45) = 0xe0;
      iVar5 = PoCallDriver(*(undefined8 *)(lVar2 + 0x18),param_2);
      goto LAB_14000bc24;
    }
  }
  PoStartNextPowerIrp(param_2);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  iVar5 = PoCallDriver(*(undefined8 *)(lVar2 + 0x18),param_2);
LAB_14000bc24:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar5);
  }
  USBSTOR_LogEntry(0x70736466,(longlong)iVar5,0,0);
  return iVar5;
}



===== UsbQueueFreeStream @ 14000bd3c =====

undefined8 UsbQueueFreeStream(longlong param_1,longlong param_2,longlong *param_3)

{
  longlong lVar1;
  code *pcVar2;
  longlong *plVar3;
  undefined8 uVar4;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
            &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
  }
  plVar3 = *(longlong **)(param_1 + 0x10);
  do {
    if (plVar3 == (longlong *)(param_1 + 0x10)) {
LAB_14000bdc7:
      PortAvioDismissStream((longlong *)(param_1 + 0x100),param_2,(longlong)param_3);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
                &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
      }
      return 0;
    }
    if (plVar3 == param_3) {
      lVar1 = *param_3;
      if ((lVar1 != 0) && (plVar3 = (longlong *)param_3[1], plVar3 != (longlong *)0x0)) {
        if ((*(longlong **)(lVar1 + 8) != param_3) || ((longlong *)*plVar3 != param_3)) {
          pcVar2 = (code *)swi(0x29);
          (*pcVar2)(3);
          pcVar2 = (code *)swi(3);
          uVar4 = (*pcVar2)();
          return uVar4;
        }
        *plVar3 = lVar1;
        *(longlong **)(lVar1 + 8) = plVar3;
      }
      goto LAB_14000bdc7;
    }
    plVar3 = (longlong *)*plVar3;
  } while( true );
}



===== PortAvioDismissStream @ 14000be2c =====

void PortAvioDismissStream(longlong *param_1,longlong param_2,longlong param_3)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  longlong *plVar4;
  longlong *plVar5;
  
  plVar4 = (longlong *)*param_1;
  while( true ) {
    if (plVar4 == param_1) {
      return;
    }
    plVar1 = (longlong *)(param_3 + 0x50);
    if (plVar4 == plVar1) break;
    plVar4 = (longlong *)*plVar4;
  }
  lVar2 = *(longlong *)(param_3 + 0x38);
  plVar4 = (longlong *)(param_3 + 0x18);
  while ((longlong *)*plVar4 != plVar4) {
    plVar5 = PortListRemoveNextRequest(plVar4);
    PortListInsertRequest((longlong *)(lVar2 + 200),plVar5);
  }
  *(int *)((longlong)param_1 + 0x1c) = *(int *)((longlong)param_1 + 0x1c) - *(int *)(param_3 + 0x10)
  ;
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) == plVar1) &&
     (plVar4 = *(longlong **)(param_3 + 0x58), (longlong *)*plVar4 == plVar1)) {
    *plVar4 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar4;
    *(int *)(param_1 + 2) = (int)param_1[2] + -1;
    IoFreeSfioStreamIdentifier(*(undefined8 *)(param_2 + 0xc0),param_1);
    return;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== PortListInsertRequest @ 14000bef0 =====

void PortListInsertRequest(longlong *param_1,longlong *param_2)

{
  int *piVar1;
  longlong lVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  code *pcVar5;
  longlong *plVar6;
  int iVar7;
  uint uVar8;
  longlong *plVar9;
  
  iVar7 = (int)param_1[6];
  plVar9 = param_2;
  if (iVar7 != 0) goto LAB_14000bf81;
  plVar6 = (longlong *)*param_1;
  if (plVar6 != param_1) {
    do {
      if ((ulonglong)param_2[2] < (ulonglong)plVar6[2]) break;
      plVar6 = (longlong *)*plVar6;
    } while (plVar6 != param_1);
  }
  puVar3 = (undefined8 *)plVar6[1];
  if ((longlong *)*puVar3 == plVar6) {
    *param_2 = (longlong)plVar6;
    param_2[1] = (longlong)puVar3;
    *puVar3 = param_2;
    plVar6[1] = (longlong)param_2;
    if ((longlong *)param_1[2] == param_1) {
      param_1[2] = *param_1;
    }
    else if (((ulonglong)param_1[5] <= (ulonglong)param_2[2]) &&
            ((uVar4 = ((longlong *)param_1[2])[2], (ulonglong)param_2[2] < uVar4 ||
             (uVar4 < (ulonglong)param_1[5])))) {
      param_1[2] = (longlong)param_2;
    }
  }
  else {
    do {
      while( true ) {
        iVar7 = 3;
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)();
LAB_14000bf81:
        if ((iVar7 == 1) || (iVar7 != 2)) break;
        for (param_2 = (longlong *)*param_1; param_2 != param_1; param_2 = (longlong *)*param_2) {
          uVar8 = 0;
          do {
            lVar2 = (ulonglong)(1 - uVar8) * 4;
            if (*(int *)(lVar2 + 0x10 + (longlong)plVar9) !=
                *(int *)(lVar2 + 0x10 + (longlong)param_2)) goto LAB_14000bfc6;
            uVar8 = uVar8 + 1;
          } while (uVar8 < 2);
          if (uVar8 != 2) {
LAB_14000bfc6:
            lVar2 = (ulonglong)(1 - uVar8) * 4;
            if (*(uint *)(lVar2 + 0x10 + (longlong)plVar9) <=
                *(uint *)(lVar2 + 0x10 + (longlong)param_2)) break;
          }
        }
        puVar3 = (undefined8 *)param_2[1];
        if ((longlong *)*puVar3 == param_2) {
          *plVar9 = (longlong)param_2;
          plVar9[1] = (longlong)puVar3;
          *puVar3 = plVar9;
          param_2[1] = (longlong)plVar9;
          param_1[2] = *param_1;
          goto LAB_14000bf59;
        }
      }
      puVar3 = (undefined8 *)param_1[1];
    } while ((longlong *)*puVar3 != param_1);
    *param_2 = (longlong)param_1;
    param_2[1] = (longlong)puVar3;
    *puVar3 = plVar9;
    param_1[1] = (longlong)plVar9;
    param_1[2] = *param_1;
  }
LAB_14000bf59:
  *(int *)(param_1 + 3) = (int)param_1[3] + 1;
  if (param_1[4] != 0) {
    piVar1 = (int *)(param_1[4] + 4);
    *piVar1 = *piVar1 + 1;
  }
  return;
}



===== PortListRemoveNextRequest @ 14000c040 =====

longlong * PortListRemoveNextRequest(longlong *param_1)

{
  int *piVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong *plVar5;
  
  if ((longlong *)*param_1 == param_1) {
    plVar5 = (longlong *)0x0;
  }
  else {
    plVar5 = (longlong *)param_1[2];
    param_1[2] = *plVar5;
    param_1[5] = plVar5[2] + 1;
    lVar2 = *plVar5;
    if ((*(longlong **)(lVar2 + 8) != plVar5) ||
       (plVar3 = (longlong *)plVar5[1], (longlong *)*plVar3 != plVar5)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      plVar5 = (longlong *)(*pcVar4)();
      return plVar5;
    }
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    *(int *)(param_1 + 3) = (int)param_1[3] + -1;
    if (param_1[4] != 0) {
      piVar1 = (int *)(param_1[4] + 4);
      *piVar1 = *piVar1 + -1;
    }
    if ((longlong *)param_1[2] == param_1) {
      param_1[2] = *param_1;
    }
  }
  return plVar5;
}



===== UsbGetIrpPriority @ 14000c0b0 =====

uint UsbGetIrpPriority(longlong param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
            &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
  }
  uVar2 = 2;
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  if ((lVar1 != 0) && (lVar1 = *(longlong *)(lVar1 + 0x38), lVar1 != 0)) {
    lVar3 = IoGetSfioStreamIdentifier(*(undefined8 *)(lVar1 + 0xc0),param_1 + 0x100);
    if (lVar3 == 0) {
      uVar2 = IoGetIoPriorityHint(lVar1);
      if (uVar2 < 2) {
        uVar2 = 2;
      }
    }
    else {
      uVar2 = 6;
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
             &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids,uVar2);
  }
  return uVar2;
}



===== UsbGetStreamSubQueue @ 14000c1c0 =====

longlong UsbGetStreamSubQueue(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
            &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
  }
  lVar3 = 0;
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  if ((lVar2 != 0) && (lVar2 = *(longlong *)(lVar2 + 0x38), lVar2 != 0)) {
    lVar1 = IoGetSfioStreamIdentifier(*(undefined8 *)(lVar2 + 0xc0),param_1 + 0x100);
    if (lVar1 != 0) {
      lVar2 = IoGetSfioStreamIdentifier(*(undefined8 *)(lVar2 + 0xc0),param_1 + 0x100);
      if (lVar2 != 0) {
        lVar3 = lVar2 + 0x18;
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
             &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids,lVar3);
  }
  return lVar3;
}



===== TransferStarvedRequests @ 14000c2c8 =====

uint TransferStarvedRequests(longlong param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *(uint *)(param_1 + 8);
  uVar2 = 0;
  uVar4 = 0;
  do {
    if (param_2 <= uVar2) break;
    uVar3 = uVar3 - 1;
    uVar1 = TransferRequestsToQueue
                      ((longlong *)((ulonglong)uVar3 * 0x38 + 0x58 + param_1),
                       (longlong *)(param_1 + 0x20),1);
    uVar2 = uVar2 + uVar1;
    uVar4 = uVar4 + 1;
    if (uVar3 == 0) {
      uVar3 = 3;
    }
  } while (uVar4 < 3);
  *(uint *)(param_1 + 8) = uVar3;
  return uVar2;
}



===== TransferRequestsToQueue @ 14000c350 =====

uint TransferRequestsToQueue(longlong *param_1,longlong *param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  code *pcVar6;
  longlong *plVar7;
  uint uVar8;
  uint uVar9;
  longlong *plVar10;
  
  uVar8 = 0;
  do {
    if (((longlong *)*param_1 == param_1) || (param_3 <= uVar8)) {
      return uVar8;
    }
    plVar10 = (longlong *)param_1[2];
    param_1[2] = *plVar10;
    param_1[5] = plVar10[2] + 1;
    lVar3 = *plVar10;
    if ((*(longlong **)(lVar3 + 8) == plVar10) &&
       (plVar7 = (longlong *)plVar10[1], (longlong *)*plVar7 == plVar10)) {
      *plVar7 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar7;
      *(int *)(param_1 + 3) = (int)param_1[3] + -1;
      if (param_1[4] != 0) {
        piVar1 = (int *)(param_1[4] + 4);
        *piVar1 = *piVar1 + -1;
      }
      if ((longlong *)param_1[2] == param_1) {
        param_1[2] = *param_1;
      }
      iVar2 = (int)param_2[6];
      if (iVar2 == 0) {
        plVar7 = (longlong *)*param_2;
        if (plVar7 != param_2) {
          do {
            if ((ulonglong)plVar10[2] < (ulonglong)plVar7[2]) break;
            plVar7 = (longlong *)*plVar7;
          } while (plVar7 != param_2);
        }
        puVar4 = (undefined8 *)plVar7[1];
        if ((longlong *)*puVar4 != plVar7) goto LAB_14000c456;
        *plVar10 = (longlong)plVar7;
        plVar10[1] = (longlong)puVar4;
        *puVar4 = plVar10;
        plVar7[1] = (longlong)plVar10;
        if ((longlong *)param_2[2] == param_2) {
          param_2[2] = *param_2;
        }
        else if (((ulonglong)param_2[5] <= (ulonglong)plVar10[2]) &&
                ((uVar5 = ((longlong *)param_2[2])[2], (ulonglong)plVar10[2] < uVar5 ||
                 (uVar5 < (ulonglong)param_2[5])))) goto LAB_14000c45d;
      }
      else if ((iVar2 == 1) || (iVar2 != 2)) {
        puVar4 = (undefined8 *)param_2[1];
        if ((longlong *)*puVar4 != param_2) goto LAB_14000c456;
        *plVar10 = (longlong)param_2;
        plVar10[1] = (longlong)puVar4;
        *puVar4 = plVar10;
        param_2[1] = (longlong)plVar10;
        param_2[2] = *param_2;
      }
      else {
        for (plVar7 = (longlong *)*param_2; plVar7 != param_2; plVar7 = (longlong *)*plVar7) {
          uVar9 = 0;
          do {
            lVar3 = (ulonglong)(1 - uVar9) * 4;
            if (*(int *)(lVar3 + 0x10 + (longlong)plVar10) !=
                *(int *)(lVar3 + 0x10 + (longlong)plVar7)) goto LAB_14000c4a9;
            uVar9 = uVar9 + 1;
          } while (uVar9 < 2);
          if (uVar9 != 2) {
LAB_14000c4a9:
            lVar3 = (ulonglong)(1 - uVar9) * 4;
            if (*(uint *)(lVar3 + 0x10 + (longlong)plVar10) <=
                *(uint *)(lVar3 + 0x10 + (longlong)plVar7)) break;
          }
        }
        puVar4 = (undefined8 *)plVar7[1];
        if ((longlong *)*puVar4 != plVar7) goto LAB_14000c456;
        *plVar10 = (longlong)plVar7;
        plVar10[1] = (longlong)puVar4;
        *puVar4 = plVar10;
        plVar7[1] = (longlong)plVar10;
        param_2[2] = *param_2;
      }
    }
    else {
LAB_14000c456:
      pcVar6 = (code *)swi(0x29);
      (*pcVar6)(3);
LAB_14000c45d:
      param_2[2] = (longlong)plVar10;
    }
    *(int *)(param_2 + 3) = (int)param_2[3] + 1;
    if (param_2[4] != 0) {
      piVar1 = (int *)(param_2[4] + 4);
      *piVar1 = *piVar1 + 1;
    }
    uVar8 = uVar8 + 1;
  } while( true );
}



===== PortListRemoveRequest @ 14000c520 =====

void PortListRemoveRequest(undefined8 *param_1,longlong *param_2)

{
  int *piVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  if ((longlong *)param_1[2] == param_2) {
    param_1[2] = *param_2;
    param_1[5] = param_2[2] + 1;
  }
  lVar2 = *param_2;
  if ((*(longlong **)(lVar2 + 8) != param_2) ||
     (plVar3 = (longlong *)param_2[1], (longlong *)*plVar3 != param_2)) {
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  *plVar3 = lVar2;
  *(longlong **)(lVar2 + 8) = plVar3;
  *(int *)(param_1 + 3) = *(int *)(param_1 + 3) + -1;
  if (param_1[4] != 0) {
    piVar1 = (int *)(param_1[4] + 4);
    *piVar1 = *piVar1 + -1;
  }
  if ((undefined8 *)param_1[2] == param_1) {
    param_1[2] = *param_1;
  }
  return;
}



===== PortpCancelRoutine @ 14000c580 =====

void PortpCancelRoutine(undefined8 param_1,longlong param_2)

{
  char *pcVar1;
  longlong lVar2;
  undefined1 local_res10 [8];
  
  local_res10[0] = 0;
  pcVar1 = *(char **)(*(longlong *)(param_2 + 0xb8) + 0x20);
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  if (pcVar1 != (char *)0x0) {
    IoCancelIrp(*(undefined8 *)(pcVar1 + 8));
    IoAcquireCancelSpinLock(local_res10);
    lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x20);
    *(undefined8 *)(*(longlong *)(param_2 + 0xb8) + 0x20) = 0;
    IoReleaseCancelSpinLock(local_res10[0]);
    if (lVar2 == 0) {
      PortpCompleteRequestIrp(param_2,pcVar1);
    }
  }
  return;
}



===== PortpAsyncCompletion @ 14000c620 =====

undefined8 PortpAsyncCompletion(undefined8 param_1,undefined8 param_2,char *param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 local_res18 [16];
  
  lVar2 = *(longlong *)(param_3 + 0x10);
  LOCK();
  lVar1 = *(longlong *)(lVar2 + 0x68);
  *(longlong *)(lVar2 + 0x68) = 0;
  UNLOCK();
  if (lVar1 == 0) {
    local_res18[0] = 0;
    IoAcquireCancelSpinLock(local_res18);
    lVar1 = *(longlong *)(*(longlong *)(lVar2 + 0xb8) + 0x20);
    *(undefined8 *)(*(longlong *)(lVar2 + 0xb8) + 0x20) = 0;
    IoReleaseCancelSpinLock(local_res18[0]);
    if (lVar1 != 0) {
      return 0xc0000016;
    }
  }
  else {
    *(undefined8 *)(*(longlong *)(lVar2 + 0xb8) + 0x20) = 0;
  }
  PortpCompleteRequestIrp(*(longlong *)(param_3 + 0x10),param_3);
  return 0xc0000016;
}



===== PortpCompleteRequestIrp @ 14000c6b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PortpCompleteRequestIrp(longlong param_1,char *param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  short *psVar5;
  longlong lVar6;
  ulonglong *puVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  uint uVar10;
  char cVar11;
  byte bVar12;
  char cVar13;
  uint uVar14;
  ulonglong uVar15;
  void *_Dst;
  uint uVar16;
  byte bVar17;
  ulonglong uVar18;
  ulonglong local_res20;
  ulonglong local_a8;
  ulonglong local_a0;
  ulonglong local_98;
  undefined4 local_90;
  undefined4 uStack_8c;
  uint uStack_88;
  undefined4 uStack_84;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  uint local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  
  lVar2 = *(longlong *)(param_2 + 8);
  cVar13 = *param_2;
  lVar3 = *(longlong *)(param_2 + 0x18);
  lVar4 = *(longlong *)(param_2 + 0x10);
  local_98 = *(ulonglong *)(lVar2 + 0x38);
  uVar16 = *(uint *)(lVar2 + 0x30);
  local_a0 = (ulonglong)uVar16;
  if ((*(int *)(*(longlong *)(param_1 + 0xb8) + 0x18) - 0x4d044U & 0xfffffffb) == 0) {
    PortPassThroughExMarshalResultsFromSrbEx(lVar4,lVar3,cVar13,(int *)&local_a0);
    uVar18 = local_98;
    uVar14 = (uint)local_a0;
    goto LAB_14000c86b;
  }
  psVar5 = *(short **)(lVar4 + 0x18);
  local_50 = 0;
  uStack_4c = 0;
  lVar6 = *(longlong *)(lVar4 + 0xb8);
  uVar18 = 0;
  bVar17 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_70 = 0;
  uStack_68 = 0;
  uVar14 = *(uint *)(lVar6 + 0x10);
  local_60 = 0;
  uStack_5c = 0;
  uStack_58 = 0;
  uStack_54 = 0;
  cVar11 = IoIs32bitProcess(lVar4);
  if (cVar11 == '\0') {
    if (uVar14 < 0x38) {
      uVar14 = 0xc000000d;
      goto LAB_14000c86b;
    }
    if (*psVar5 != 0x38) {
      uVar14 = 0xc0000059;
      goto LAB_14000c86b;
    }
    local_80 = *(ulonglong *)psVar5;
    uStack_78 = *(ulonglong *)(psVar5 + 4);
    local_60 = *(uint *)(psVar5 + 0x10);
    uStack_5c = *(undefined4 *)(psVar5 + 0x12);
    uStack_58 = *(undefined4 *)(psVar5 + 0x14);
    uStack_54 = *(undefined4 *)(psVar5 + 0x16);
    local_90 = (undefined4)*(ulonglong *)(psVar5 + 8);
    uStack_8c = *(undefined4 *)(psVar5 + 10);
    local_a8 = *(ulonglong *)(psVar5 + 8);
    uStack_88 = *(uint *)(psVar5 + 0xc);
    uStack_84 = *(undefined4 *)(psVar5 + 0xe);
    local_a0 = *(ulonglong *)(psVar5 + 0x18);
    local_res20 = *(ulonglong *)(psVar5 + 0xc);
  }
  else {
    if (uVar14 < 0x2c) {
      uVar14 = 0xc000000d;
      goto LAB_14000c86b;
    }
    psVar5 = *(short **)(lVar4 + 0x18);
    if (*psVar5 != 0x2c) {
      uVar14 = 0xc0000059;
      goto LAB_14000c86b;
    }
    local_a8 = *(ulonglong *)(psVar5 + 8);
    local_90 = (undefined4)local_a8;
    uStack_8c = (undefined4)(local_a8 >> 0x20);
    local_80 = *(ulonglong *)psVar5;
    uStack_78 = *(ulonglong *)(psVar5 + 4);
    uStack_88 = *(uint *)(psVar5 + 10);
    local_res20 = (ulonglong)uStack_88;
    local_60 = *(uint *)(psVar5 + 0xc);
    uStack_68._4_4_ = 0;
    uStack_5c = (undefined4)*(undefined8 *)(psVar5 + 0xe);
    uStack_58 = (undefined4)((ulonglong)*(undefined8 *)(psVar5 + 0xe) >> 0x20);
    uStack_54 = (undefined4)*(undefined8 *)(psVar5 + 0x12);
    local_50 = (undefined4)((ulonglong)*(undefined8 *)(psVar5 + 0x12) >> 0x20);
    local_a0 = CONCAT44(uStack_4c,local_50);
    uStack_84 = uStack_68._4_4_;
    uStack_68 = local_res20;
  }
  if (*(int *)(lVar6 + 8) == 0) {
    cVar11 = '\0';
    local_60 = 0;
  }
  else {
    cVar11 = local_80._7_1_;
  }
  uVar10 = local_60;
  uVar14 = *(uint *)(*(longlong *)(lVar4 + 0xb8) + 8);
  local_80._0_3_ = CONCAT12(*(undefined1 *)(lVar3 + 4),(undefined2)local_80);
  bVar12 = *(byte *)(lVar3 + 3);
  if ((char)bVar12 < '\0') {
    if (cVar11 == '\0') {
      bVar17 = *(byte *)(lVar3 + 0xb);
      uVar16 = 0;
      local_80 = CONCAT17(bVar17,(undefined7)local_80);
    }
    else {
      bVar17 = *(byte *)(lVar3 + 0xb);
      local_80 = CONCAT17(bVar17,(undefined7)local_80);
      _Dst = (void *)((ulonglong)local_60 + *(longlong *)(lVar4 + 0x18));
      if ((_Dst != (void *)0x0) && (bVar17 != 0)) {
        memmove(_Dst,*(void **)(lVar3 + 0x20),(ulonglong)bVar17);
        bVar12 = *(byte *)(lVar3 + 3);
      }
      uVar16 = 0;
    }
  }
  else {
    local_80 = local_80 & 0xffffffffffffff;
  }
  uVar8 = uStack_78;
  uVar15 = (ulonglong)uVar14;
  uVar1 = *(uint *)(lVar3 + 0x10);
  uStack_78 = CONCAT44(uVar1,(undefined4)uStack_78);
  uVar9 = uStack_78;
  uVar14 = 0;
  if ((bVar12 & 0x3f) != 0x12) {
    uVar14 = uVar16;
  }
  if (bVar17 == 0) {
    uVar18 = local_80 & 0xffff;
    if (((int)uVar14 < 0) && (*(char *)(lVar3 + 4) != '\0')) {
      uVar14 = 0;
      uVar18 = 3;
    }
  }
  else {
    uVar18 = (ulonglong)(bVar17 + uVar10);
  }
  if ((((cVar13 == '\0') && (uStack_78._0_1_ = (char)uVar8, (char)uStack_78 != '\0')) &&
      (uVar1 != 0)) && (local_res20 != 0)) {
    uVar18 = local_res20 + uVar1;
  }
  puVar7 = *(ulonglong **)(lVar4 + 0x18);
  if (uVar15 <= uVar18) {
    uVar18 = uVar15;
  }
  uStack_78 = uVar9;
  cVar13 = IoIs32bitProcess(lVar4);
  if (cVar13 == '\0') {
    *puVar7 = local_80;
    puVar7[1] = uStack_78;
    puVar7[2] = CONCAT44(uStack_8c,local_90);
    puVar7[3] = CONCAT44(uStack_84,uStack_88);
    puVar7[4] = CONCAT44(uStack_5c,local_60);
    puVar7[5] = CONCAT44(uStack_54,uStack_58);
    puVar7[6] = local_a0;
  }
  else {
    puVar7 = *(ulonglong **)(lVar4 + 0x18);
    *puVar7 = local_80;
    puVar7[1] = uStack_78;
    puVar7[2] = local_a8;
  }
LAB_14000c86b:
  *(uint *)(*(longlong *)(param_2 + 0x10) + 0x30) = uVar14;
  *(ulonglong *)(*(longlong *)(param_2 + 0x10) + 0x38) = uVar18;
  if (*(longlong *)(lVar2 + 8) != 0) {
    MmUnlockPages();
    IoFreeMdl(*(undefined8 *)(lVar2 + 8));
    *(undefined8 *)(lVar2 + 8) = 0;
  }
  IoFreeIrp(lVar2);
  PortPassThroughFreeSrb(*(longlong *)(param_2 + 0x18));
  (**(code **)(param_2 + 0x20))(*(undefined8 *)(param_2 + 0x10),*(undefined8 *)(param_2 + 0x28));
  ExFreePoolWithTag(param_2,0x69506c50);
  return;
}



===== PortPassThroughFreeSrb @ 14000ca74 =====

void PortPassThroughFreeSrb(longlong param_1)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  ulonglong uVar4;
  longlong lVar5;
  ulonglong uVar6;
  uint uVar7;
  uint *puVar8;
  
  if (*(char *)(param_1 + 2) == '(') {
    bVar3 = false;
    lVar5 = 0;
    uVar7 = 0;
    if (*(uint *)(param_1 + 0x38) != 0) {
      puVar8 = (uint *)(param_1 + 0x78);
      do {
        uVar1 = *puVar8;
        uVar4 = (ulonglong)uVar1;
        if ((0x7f < uVar1) &&
           (uVar6 = (ulonglong)*(uint *)(param_1 + 0x10), uVar1 <= *(uint *)(param_1 + 0x10))) {
          iVar2 = *(int *)(uVar4 + param_1);
          if (iVar2 == 0x40) {
            if (uVar4 + 0x28 <= uVar6) {
              lVar5 = *(longlong *)(uVar4 + 0x10 + param_1);
              break;
            }
          }
          else if (iVar2 == 0x41) {
            if (uVar4 + 0x38 <= uVar6) {
              lVar5 = *(longlong *)(uVar4 + 0x10 + param_1);
              bVar3 = true;
            }
          }
          else if ((iVar2 == 0x42) && (uVar4 + 0x28 <= uVar6)) {
            lVar5 = *(longlong *)(uVar4 + 0x18 + param_1);
            break;
          }
          if (bVar3) break;
        }
        uVar7 = uVar7 + 1;
        puVar8 = puVar8 + 1;
      } while (uVar7 < *(uint *)(param_1 + 0x38));
      if (lVar5 != 0) {
        ExFreePoolWithTag(lVar5,0x69506c50);
      }
    }
  }
  else if (*(longlong *)(param_1 + 0x20) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x20),0x69506c50);
    *(undefined8 *)(param_1 + 0x20) = 0;
  }
  ExFreePoolWithTag(param_1,0x69506c50);
  return;
}



===== PortPassThroughExMarshalResultsFromSrbEx @ 14000cb74 =====

void PortPassThroughExMarshalResultsFromSrbEx
               (longlong param_1,longlong param_2,char param_3,int *param_4)

{
  int iVar1;
  longlong lVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  int *piVar6;
  void *_Dst;
  ulonglong uVar7;
  byte bVar8;
  byte bVar9;
  ulonglong uVar10;
  char cVar11;
  int iVar12;
  void *_Src;
  uint uVar13;
  
  lVar2 = *(longlong *)(param_1 + 0x18);
  param_4[2] = 0;
  param_4[3] = 0;
  uVar13 = *(int *)(lVar2 + 8) + 0x3f;
  if (uVar13 < 0x40) {
    iVar3 = -0x3fffff6b;
    goto LAB_14000cd21;
  }
  uVar10 = (ulonglong)uVar13;
  puVar4 = (undefined8 *)ExAllocatePool2(0x40,uVar13,0x69506c50);
  if (puVar4 == (undefined8 *)0x0) {
    iVar3 = -0x3fffff66;
    goto LAB_14000cd21;
  }
  uVar5 = PortPassThroughExNormalize(puVar4,param_1);
  iVar3 = (int)uVar5;
  if (-1 < iVar3) {
    cVar11 = '\0';
    iVar12 = *param_4;
    bVar8 = 0;
    _Src = (void *)0x0;
    uVar13 = *(uint *)(*(longlong *)(param_1 + 0xb8) + 8);
    piVar6 = (int *)((ulonglong)*(uint *)(param_2 + 0x78) + param_2);
    iVar3 = *piVar6;
    if ((iVar3 == 0x40) || (iVar3 == 0x41)) {
      _Src = *(void **)(piVar6 + 4);
LAB_14000cc37:
      cVar11 = (char)piVar6[2];
      bVar8 = *(byte *)((longlong)piVar6 + 9);
    }
    else if (iVar3 == 0x42) {
      _Src = *(void **)(piVar6 + 6);
      goto LAB_14000cc37;
    }
    *(char *)(puVar4 + 2) = cVar11;
    if (*(char *)(param_2 + 3) < '\0') {
      bVar9 = *(byte *)((longlong)puVar4 + 0x11);
      if ((bVar9 != 0) &&
         (_Dst = (void *)((ulonglong)*(uint *)((longlong)puVar4 + 0x1c) +
                         *(longlong *)(param_1 + 0x18)), _Dst != (void *)0x0)) {
        *(byte *)((longlong)puVar4 + 0x11) = bVar8;
        memmove(_Dst,_Src,(ulonglong)bVar8);
        bVar9 = *(byte *)((longlong)puVar4 + 0x11);
      }
      iVar12 = 0;
    }
    else {
      *(undefined1 *)((longlong)puVar4 + 0x11) = 0;
      bVar9 = 0;
    }
    iVar1 = *(int *)(param_2 + 0x3c);
    iVar3 = 0;
    if ((*(byte *)(param_2 + 3) & 0x3f) != 0x12) {
      iVar3 = iVar12;
    }
    if (*(char *)((longlong)puVar4 + 0x12) == '\x01') {
      *(int *)((longlong)puVar4 + 0x24) = iVar1;
    }
    else {
      *(int *)(puVar4 + 4) = iVar1;
      if (((*(char *)((longlong)puVar4 + 0x12) == '\x03') && (iVar1 != 0)) &&
         (*(int *)((longlong)puVar4 + 0x24) != 0)) {
        *(undefined4 *)((longlong)puVar4 + 0x24) =
             *(undefined4 *)((ulonglong)*(uint *)(param_2 + 0x7c) + 8 + param_2);
      }
    }
    if (bVar9 == 0) {
      if ((iVar3 < 0) && (cVar11 != '\0')) {
        iVar3 = 0;
        uVar10 = 8;
      }
    }
    else {
      uVar10 = (ulonglong)(*(int *)((longlong)puVar4 + 0x1c) + (uint)bVar9);
    }
    if ((param_3 == '\0') && (puVar4[6] != 0)) {
      uVar10 = (ulonglong)*(uint *)((longlong)puVar4 + 0x24) + puVar4[6];
    }
    uVar7 = (ulonglong)uVar13;
    if (uVar7 <= uVar10) {
      uVar10 = uVar7;
    }
    *(ulonglong *)(param_4 + 2) = uVar10;
    PortPassThroughExApplyNormalizedRequest(puVar4,param_1);
  }
  ExFreePoolWithTag(puVar4,0x69506c50);
LAB_14000cd21:
  *param_4 = iVar3;
  return;
}



===== PortPassThroughBuildIrpEx @ 14000cd50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong PortPassThroughBuildIrpEx
                   (longlong param_1,longlong param_2,undefined4 param_3,char param_4,char param_5,
                   longlong param_6)

{
  bool bVar1;
  bool bVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 auStack_b8 [32];
  undefined8 local_98;
  undefined1 local_88;
  undefined4 local_84;
  longlong local_80;
  longlong local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_b8;
  local_80 = param_6;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  bVar1 = false;
  local_88 = 0;
  if ((param_5 == '\x01') && (param_6 != 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  local_84 = param_3;
  lVar3 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c),0);
  if (lVar3 != 0) {
    *(void **)(lVar3 + 0x98) = SystemReserved1[0xf];
    *(undefined2 *)(*(longlong *)(lVar3 + 0xb8) + -0x48) = 0x10f;
    if (param_2 == 0) goto LAB_14000cedd;
    local_98 = 0;
    local_78 = lVar3;
    lVar4 = IoAllocateMdl(param_2,local_84,0,0);
    *(longlong *)(lVar3 + 8) = lVar4;
    if (lVar4 != 0) {
      if (((bVar2) && (lVar4 = IoGetRequestorProcess(local_80), lVar4 != 0)) &&
         (lVar5 = IoGetCurrentProcess(), lVar4 != lVar5)) {
        KeStackAttachProcess(lVar4,&local_70);
        bVar1 = true;
        local_88 = 1;
      }
      MmProbeAndLockPages(*(undefined8 *)(lVar3 + 8),param_5,param_4 != '\0');
      if (bVar1) {
        KeUnstackDetachProcess(&local_70);
      }
      goto LAB_14000cedd;
    }
    IoFreeIrp(lVar3);
  }
  lVar3 = 0;
LAB_14000cedd:
  return lVar3;
}



===== USBSTOR_RequestSenseInterruptCompletionRoutine @ 14000cf60 =====

undefined4
USBSTOR_RequestSenseInterruptCompletionRoutine(longlong param_1,undefined *param_2,longlong param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  undefined4 uVar8;
  int *piVar9;
  longlong lVar10;
  int *piVar11;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  piVar11 = (int *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x82,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  iVar1 = *(int *)(param_2 + 0x30);
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_38);
    *DAT_14001a1b0 = 0x43495352;
    *(longlong *)(DAT_14001a1b0 + 2) = param_1;
    *(undefined **)(DAT_14001a1b0 + 4) = param_2;
    *(longlong *)(DAT_14001a1b0 + 6) = (longlong)iVar1;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_38);
  }
  piVar4 = *(int **)(param_1 + 0x40);
  if (*piVar4 == 0x214f4450) {
    piVar9 = *(int **)(*(longlong *)(piVar4 + 4) + 0x40);
    lVar10 = *(longlong *)(piVar4 + 4);
    piVar11 = piVar4;
  }
  else {
    piVar9 = (int *)0x0;
    lVar10 = 0;
    if (*piVar4 == 0x214f4446) {
      piVar9 = piVar4;
      lVar10 = param_1;
    }
  }
  lVar5 = *(longlong *)(lVar10 + 0x40);
  local_38 = 0;
  uStack_30 = 0;
  lVar6 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  local_28 = 0;
  KeAcquireInStackQueuedSpinLock(lVar5 + 0x90,&local_38);
  *(uint *)(lVar5 + 0x80) = *(uint *)(lVar5 + 0x80) & 0xfffffffd;
  if ((*(uint *)(lVar5 + 0x80) & 8) == 0) {
    *(undefined8 *)(lVar5 + 0x148) = 0;
    KeReleaseInStackQueuedSpinLock(&local_38);
    iVar1 = *(int *)(param_2 + 0x30);
    if (iVar1 < 0) {
      USBSTOR_LogEntry(0x32697372,(longlong)iVar1,(longlong)piVar9[99],0);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x84,
                  &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,*(undefined4 *)(param_2 + 0x30),
                  (char)piVar9[99]);
      }
      *(undefined4 *)(param_2 + 0x30) = 0xc0000185;
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(undefined1 *)(lVar6 + 3) = 0xe;
      USBSTOR_TranslateCDBComplete(lVar10,(longlong)param_2,lVar6);
      USBSTOR_QueueResetDevice(lVar10,piVar11);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x85,
                &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
      }
      uVar8 = 0xc0000185;
    }
    else {
      uVar2 = piVar9[0x6b];
      iVar3 = piVar9[99];
      local_38 = 0;
      uStack_30 = 0;
      local_28 = 0;
      if (DAT_14001a1a8 != (undefined4 *)0x0) {
        KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_38);
        *DAT_14001a1b0 = 0x33697372;
        *(longlong *)(DAT_14001a1b0 + 2) = (longlong)iVar1;
        *(longlong *)(DAT_14001a1b0 + 4) = (longlong)iVar3;
        *(ulonglong *)(DAT_14001a1b0 + 6) = (ulonglong)uVar2;
        if (DAT_14001a1b0 <= DAT_14001a1a8) {
          DAT_14001a1b0 = DAT_14001a1b8;
        }
        DAT_14001a1b0 = DAT_14001a1b0 + -8;
        KeReleaseInStackQueuedSpinLock(&local_38);
      }
      uVar8 = USBSTOR_ProcessRequestSenseCompletion(lVar10,param_2,param_3);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x86,
                 &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,uVar8);
      }
    }
  }
  else {
    USBSTOR_LogEntry(0x31545243,lVar10,param_2,lVar6);
    KeReleaseInStackQueuedSpinLock(&local_38);
    lVar7 = *(longlong *)(lVar5 + 0x490);
    *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8) = lVar7;
    *(undefined4 *)(param_2 + 0x30) = 0xc00000b5;
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined1 *)(lVar7 + 3) = 9;
    USBSTOR_TranslateCDBComplete(lVar10,(longlong)param_2,lVar7);
    KeSetEvent(lVar5 + 0x150,0,0);
    USBSTOR_LogEntry(0x31697372,lVar10,param_2,lVar6);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x83,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    }
    uVar8 = 0xc0000016;
  }
  return uVar8;
}



===== PortPassThroughNormalize @ 14000d3c0 =====

undefined8 PortPassThroughNormalize(undefined8 *param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  short *psVar3;
  undefined8 uVar4;
  char cVar5;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  psVar3 = *(short **)(param_2 + 0x18);
  uVar1 = *(uint *)(lVar2 + 0x10);
  cVar5 = IoIs32bitProcess(param_2);
  if (cVar5 == '\0') {
    if (0x37 < uVar1) {
      if (*psVar3 != 0x38) {
        return 0xc0000059;
      }
      uVar4 = *(undefined8 *)(psVar3 + 4);
      *param_1 = *(undefined8 *)psVar3;
      param_1[1] = uVar4;
      uVar4 = *(undefined8 *)(psVar3 + 0xc);
      param_1[2] = *(undefined8 *)(psVar3 + 8);
      param_1[3] = uVar4;
      uVar4 = *(undefined8 *)(psVar3 + 0x14);
      param_1[4] = *(undefined8 *)(psVar3 + 0x10);
      param_1[5] = uVar4;
      param_1[6] = *(undefined8 *)(psVar3 + 0x18);
      goto LAB_14000d43f;
    }
  }
  else if (0x2b < uVar1) {
    psVar3 = *(short **)(param_2 + 0x18);
    if (*psVar3 != 0x2c) {
      return 0xc0000059;
    }
    uVar4 = *(undefined8 *)(psVar3 + 4);
    *param_1 = *(undefined8 *)psVar3;
    param_1[1] = uVar4;
    param_1[2] = *(undefined8 *)(psVar3 + 8);
    uVar4 = *(undefined8 *)(psVar3 + 0x12);
    *(undefined8 *)((longlong)param_1 + 0x24) = *(undefined8 *)(psVar3 + 0xe);
    *(undefined8 *)((longlong)param_1 + 0x2c) = uVar4;
    param_1[3] = (ulonglong)*(uint *)(psVar3 + 10);
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(psVar3 + 0xc);
LAB_14000d43f:
    if (*(int *)(lVar2 + 8) == 0) {
      *(undefined1 *)((longlong)param_1 + 7) = 0;
      *(undefined4 *)(param_1 + 4) = 0;
    }
    return 0;
  }
  return 0xc000000d;
}



===== USBDInternal_BuildAndSendQueryInterfaceSynchronously @ 14000d4d0 =====

int USBDInternal_BuildAndSendQueryInterfaceSynchronously
              (undefined8 param_1,longlong param_2,undefined8 param_3,undefined2 *param_4)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
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
    *(undefined2 **)(lVar1 + -0x30) = param_4;
    *(undefined2 *)(lVar1 + -0x48) = 0x81b;
    *(undefined8 *)(lVar1 + -0x28) = 0;
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



===== USBSTOR_SyncCompletionRoutine @ 14000d660 =====

undefined8 USBSTOR_SyncCompletionRoutine(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  iVar1 = *(int *)(param_2 + 0x30);
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if (DAT_14001a1a8 != (undefined4 *)0x0) {
    KeAcquireInStackQueuedSpinLock(&DAT_14001a1c0,&local_28);
    *DAT_14001a1b0 = 0x20524353;
    *(undefined8 *)(DAT_14001a1b0 + 2) = param_1;
    *(longlong *)(DAT_14001a1b0 + 4) = param_2;
    *(longlong *)(DAT_14001a1b0 + 6) = (longlong)iVar1;
    if (DAT_14001a1b0 <= DAT_14001a1a8) {
      DAT_14001a1b0 = DAT_14001a1b8;
    }
    DAT_14001a1b0 = DAT_14001a1b0 + -8;
    KeReleaseInStackQueuedSpinLock(&local_28);
  }
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== USBSTOR_TranslateSrbStatus @ 14000d750 =====

undefined8 USBSTOR_TranslateSrbStatus(longlong param_1)

{
  switch(*(byte *)(param_1 + 3) & 0x3f) {
  case 8:
  case 0x11:
  case 0x20:
  case 0x21:
    return 0xc00000c0;
  case 9:
  case 0xb:
  case 0xe:
    return 0xc00000b5;
  case 10:
    return 0xc000009d;
  default:
    return 0xc0000185;
  case 0x12:
    return 0x80000005;
  case 0x15:
  case 0x22:
    return 0xc0000010;
  }
}



===== PortpPassThroughZeroUnusedBuffers @ 14000d7b4 =====

void PortpPassThroughZeroUnusedBuffers(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0xb8) + 0x10);
  uVar2 = *(uint *)(*(longlong *)(param_1 + 0xb8) + 8);
  if (uVar1 < uVar2) {
    memset((void *)((ulonglong)uVar1 + *(longlong *)(param_1 + 0x18)),0,(ulonglong)(uVar2 - uVar1));
  }
  return;
}



===== PortpEnableCancel @ 14000d7f0 =====

undefined8 PortpEnableCancel(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  
  if (*(char *)(param_1 + 0x44) != '\0') {
    return 0xc0000120;
  }
  if (*(code **)(param_2 + 0x20) != PortpSyncCompletion) {
    pbVar1 = (byte *)(*(longlong *)(param_1 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  *(longlong *)(*(longlong *)(param_1 + 0xb8) + 0x20) = param_2;
  LOCK();
  *(code **)(param_1 + 0x68) = PortpCancelRoutine;
  UNLOCK();
  return 0x103;
}



===== PortPassThroughFreeIrpEx @ 14000d83c =====

void PortPassThroughFreeIrpEx(longlong param_1)

{
  if (*(longlong *)(param_1 + 8) != 0) {
    MmUnlockPages();
    IoFreeMdl(*(undefined8 *)(param_1 + 8));
    *(undefined8 *)(param_1 + 8) = 0;
  }
  IoFreeIrp(param_1);
  return;
}



===== USBSTOR_FxComponentIdleCallback @ 14000d890 =====

void USBSTOR_FxComponentIdleCallback(longlong param_1)

{
  PoFxCompleteIdleCondition(*(undefined8 *)(param_1 + 0x7b0));
  return;
}



===== WPP_SF_qqss @ 14000d8b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqss(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,char *param_6,char *param_7)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  char *pcVar4;
  char *pcVar5;
  undefined8 local_res20;
  
  if (param_7 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_7[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  pcVar4 = param_7;
  if (param_7 == (char *)0x0) {
    pcVar4 = "NULL";
  }
  lVar1 = -1;
  if (param_6 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    do {
      lVar3 = lVar1;
      lVar1 = lVar3 + 1;
    } while (param_6[lVar1] != '\0');
    lVar3 = lVar3 + 2;
  }
  pcVar5 = param_6;
  if (param_6 == (char *)0x0) {
    pcVar5 = "NULL";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,param_2,&local_res20,8,
             &param_5,8,pcVar5,lVar3,pcVar4,lVar2,0);
  return;
}



===== USBSTOR_IssueClientCdb @ 14000d998 =====

int USBSTOR_IssueClientCdb(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5e,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  USBSTOR_LogEntry(0x42444349,param_1,param_2,0);
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  iVar2 = USBSTOR_IssueControlRequest
                    (param_1,param_2,(uint)*(byte *)(lVar1 + 10),lVar1 + 0x48,
                     USBSTOR_ClientCdbCompletion,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5f,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar2);
  }
  USBSTOR_LogEntry(0x62646369,param_1,param_2,(longlong)iVar2);
  return iVar2;
}



===== USBSTOR_IssueControlRequest @ 14000da94 =====

int USBSTOR_IssueControlRequest
              (longlong param_1,longlong param_2,undefined4 param_3,undefined8 param_4,
              undefined8 param_5,undefined8 param_6)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong lVar4;
  bool bVar5;
  int iVar6;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x56,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  USBSTOR_LogEntry(0x52544349,param_1,param_2,0);
  lVar2 = *(longlong *)(param_1 + 0x40);
  uVar3 = *(undefined8 *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  memset((void *)(lVar2 + 0x18a),0,0x86);
  *(undefined4 *)(lVar2 + 0x188) = 0x1b0088;
  *(undefined4 *)(lVar2 + 0x1ac) = param_3;
  *(undefined8 *)(lVar2 + 0x1b0) = param_4;
  *(ushort *)(lVar2 + 0x20c) = (ushort)*(byte *)(*(longlong *)(lVar2 + 0x58) + 2);
  lVar4 = *(longlong *)(param_2 + 0xb8);
  *(undefined1 *)(lVar4 + -0x48) = 0xf;
  *(undefined4 *)(lVar4 + -0x30) = 0x220003;
  *(undefined4 **)(lVar4 + -0x40) = (undefined4 *)(lVar2 + 0x188);
  lVar4 = *(longlong *)(param_2 + 0xb8);
  *(undefined8 *)(lVar4 + -0x10) = param_5;
  *(undefined8 *)(lVar4 + -8) = param_6;
  *(undefined1 *)(lVar4 + -0x45) = 0xe0;
  KeAcquireInStackQueuedSpinLock(lVar2 + 0x90,&local_48);
  uVar1 = *(uint *)(lVar2 + 0x80);
  *(longlong *)(lVar2 + 0x148) = param_2;
  if (((uVar1 & 0x40) == 0) || ((uVar1 & 8) != 0)) {
    bVar5 = false;
  }
  else {
    bVar5 = true;
  }
  *(uint *)(lVar2 + 0x80) = uVar1 & 0xffffffbf | 2;
  KeReleaseInStackQueuedSpinLock(&local_48);
  iVar6 = IofCallDriver(*(undefined8 *)(lVar2 + 0x18),param_2);
  if (bVar5) {
    USBSTOR_LogEntry(0x4f545243,param_1,param_2,uVar3);
    USBSTOR_QueueResetDevice(param_1,uVar3);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x57,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar6);
  }
  USBSTOR_LogEntry(0x72746369,param_1,param_2,(longlong)iVar6);
  return iVar6;
}



===== USBSTOR_SerialNumberVPDInquiry @ 14000dc8c =====

int USBSTOR_SerialNumberVPDInquiry(longlong param_1)

{
  byte bVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 local_res8 [2];
  undefined8 local_18;
  undefined8 uStack_10;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar4 = ExAllocatePool2(0x40,0xff,0x53414d55);
  if (lVar4 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xbe,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    }
    iVar3 = -0x3fffff66;
  }
  else {
    uStack_10 = 0;
    local_18 = 0xff00800112;
    local_res8[0] = 0xff;
    iVar3 = USBSTOR_IssueInternalCdb(param_1,lVar4,local_res8,&local_18,6,0x14);
    if (-1 < iVar3) {
      bVar1 = *(byte *)(lVar4 + 3);
      uVar5 = (ulonglong)bVar1;
      pcVar7 = (char *)(lVar4 + 4);
      if (0xfa < bVar1) {
        uVar5 = 0xfb;
      }
      for (; (pcVar7 < (char *)(lVar4 + 4 + uVar5) && (*pcVar7 != '\0')); pcVar7 = pcVar7 + 1) {
        if (*pcVar7 != ' ') {
          uVar6 = 0xfb;
          if (bVar1 < 0xfb) {
            uVar6 = (uint)bVar1;
          }
          *(uint *)(lVar2 + 0x40) = uVar6;
          if (*(char *)(lVar4 + 3) != '\0') {
            memmove((void *)(lVar2 + 0x6c),(void *)(lVar4 + 4),(ulonglong)uVar6);
          }
          goto LAB_14000dda8;
        }
      }
      iVar3 = -0x3fffffff;
    }
LAB_14000dda8:
    ExFreePoolWithTag(lVar4,0);
  }
  return iVar3;
}



===== _guard_check_icall @ 14000dde0 =====

void _guard_check_icall(void)

{
  return;
}



===== RtlStringCbPrintfW @ 14000ddec =====

undefined8
RtlStringCbPrintfW(wchar_t *param_1,ulonglong param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  ulonglong uVar2;
  undefined8 local_res20;
  
  uVar2 = param_2 >> 1;
  if (uVar2 - 1 < 0x7fffffff) {
    local_res20 = param_4;
    uVar1 = RtlStringVPrintfWorkerW(param_1,uVar2,param_3,(wchar_t *)param_3,(va_list)&local_res20);
  }
  else {
    uVar1 = 0xc000000d;
    if (uVar2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar1;
}



===== RtlStringCchPrintfW @ 14000de3c =====

undefined8
RtlStringCchPrintfW(wchar_t *param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 local_res20;
  
  if (param_2 - 1U < 0x7fffffff) {
    local_res20 = param_4;
    uVar1 = RtlStringVPrintfWorkerW
                      (param_1,param_2,param_3,(wchar_t *)param_3,(va_list)&local_res20);
  }
  else {
    uVar1 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar1;
}



===== RtlStringVPrintfWorkerW @ 14000de88 =====

undefined8
RtlStringVPrintfWorkerW
          (wchar_t *param_1,longlong param_2,undefined8 param_3,wchar_t *param_4,va_list param_5)

{
  ulonglong _Count;
  int iVar1;
  undefined8 uVar2;
  
  _Count = param_2 - 1;
  uVar2 = 0;
  iVar1 = _vsnwprintf(param_1,_Count,param_4,param_5);
  if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
    param_1[_Count] = L'\0';
    uVar2 = 0x80000005;
  }
  else if ((longlong)iVar1 == _Count) {
    param_1[_Count] = L'\0';
  }
  return uVar2;
}



===== PortpSyncCompletion @ 14000def0 =====

void PortpSyncCompletion(undefined8 param_1,undefined8 param_2)

{
  KeSetEvent(param_2,0,0);
  return;
}



===== PowerDeviceStateString @ 14000df14 =====

char * PowerDeviceStateString(int param_1)

{
  if (param_1 == 0) {
    return "PowerDeviceUnspecified";
  }
  if (param_1 == 1) {
    return "PowerDeviceD0";
  }
  if (param_1 == 2) {
    return "PowerDeviceD1";
  }
  if (param_1 == 3) {
    return "PowerDeviceD2";
  }
  if (param_1 == 4) {
    return "PowerDeviceD3";
  }
  if (param_1 == 5) {
    return "PowerDeviceMaximum";
  }
  return "PowerDevice?????";
}



===== USBSTOR_ResetDevice @ 14000df78 =====

int USBSTOR_ResetDevice(longlong param_1,char param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  undefined4 uVar5;
  bool bVar6;
  undefined4 local_res8 [2];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_res8[0] = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb6,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(longlong *)(lVar1 + 0x758) != 0) {
    LOCK();
    bVar6 = *(int *)(lVar1 + 0x760) == 0;
    if (bVar6) {
      *(int *)(lVar1 + 0x760) = 1;
    }
    UNLOCK();
    if (bVar6) {
      lVar4 = *(longlong *)(lVar1 + 0x758);
      IoReuseIrp(lVar4,0xc0000001);
      if (lVar4 != 0) goto LAB_14000e040;
    }
  }
  lVar4 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(lVar1 + 0x18) >> 8),
                                 *(undefined1 *)(*(longlong *)(lVar1 + 0x18) + 0x4c)),0);
  if (lVar4 == 0) {
    return -0x3fffff66;
  }
LAB_14000e040:
  KeInitializeEvent(&local_38,1,0);
  lVar2 = *(longlong *)(lVar4 + 0xb8);
  *(undefined1 *)(lVar2 + -0x48) = 0xf;
  if (param_2 == '\0') {
    uVar5 = 0x220007;
  }
  else {
    *(undefined4 **)(lVar2 + -0x40) = local_res8;
    uVar5 = 0x220fb3;
  }
  *(undefined4 *)(lVar2 + -0x30) = uVar5;
  lVar2 = *(longlong *)(lVar4 + 0xb8);
  *(code **)(lVar2 + -0x10) = USBSTOR_SyncCompletionRoutine;
  *(undefined8 **)(lVar2 + -8) = &local_38;
  *(undefined1 *)(lVar2 + -0x45) = 0xe0;
  *(int *)(lVar1 + 0x710) = *(int *)(lVar1 + 0x710) + 1;
  iVar3 = IofCallDriver(*(undefined8 *)(lVar1 + 0x18),lVar4);
  if (iVar3 == 0x103) {
    KeWaitForSingleObject(&local_38,0,0,0,0);
    iVar3 = *(int *)(lVar4 + 0x30);
  }
  if (lVar4 == *(longlong *)(lVar1 + 0x758)) {
    *(undefined4 *)(lVar1 + 0x760) = 0;
  }
  else {
    IoFreeIrp(lVar4);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb7,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar3);
  }
  return iVar3;
}



===== USBSTOR_FdoFxPowerCompletion @ 14000e160 =====

void USBSTOR_FdoFxPowerCompletion
               (undefined8 param_1,undefined8 param_2,int param_3,longlong param_4)

{
  USBSTOR_LogEntry(0x63707866,param_1,param_4,(longlong)param_3);
  if (param_3 == 1) {
    USBSTOR_RequestChildPdosFxPowerIrps(param_4,1);
  }
  else if (*(char *)(param_4 + 0x7ab) == '\0') {
    USBSTOR_LogEntry(0x6e707866,param_4,0,0);
    PoFxCompleteDevicePowerNotRequired(*(undefined8 *)(param_4 + 0x7b0));
  }
  else {
    USBSTOR_LogEntry(0x64647866,param_4,(longlong)param_3,0);
    PoFxCompleteDirectedPowerDown(*(undefined8 *)(param_4 + 0x7b0));
    *(undefined1 *)(param_4 + 0x7ab) = 0;
  }
  return;
}



===== USBSTOR_RequestChildPdosFxPowerIrps @ 14000e20c =====

void USBSTOR_RequestChildPdosFxPowerIrps(longlong param_1,ulonglong param_2)

{
  int iVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  
  iVar2 = (int)param_2;
  puVar4 = *(undefined8 **)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x7ac) = 1;
  uVar3 = param_2;
  for (; puVar4 != (undefined8 *)(param_1 + 0x20); puVar4 = (undefined8 *)*puVar4) {
    if (*(int *)(puVar4 + 3) != iVar2) {
      if (puVar4[4] != 0) {
        uVar3 = puVar4[-2];
        USBSTOR_LogEntry(0x78467853,uVar3,puVar4[4],(longlong)iVar2);
      }
      LOCK();
      *(int *)(param_1 + 0x7ac) = *(int *)(param_1 + 0x7ac) + 1;
      UNLOCK();
      uVar3 = CONCAT71((int7)(uVar3 >> 8),2);
      iVar1 = PoRequestPowerIrp(puVar4[-2],uVar3,param_2 & 0xffffffff,USBSTOR_PdoFxPowerCompletion,
                                param_1,0);
      if (iVar1 < 0) {
        LOCK();
        *(int *)(param_1 + 0x7ac) = *(int *)(param_1 + 0x7ac) + -1;
        UNLOCK();
      }
    }
  }
  USBSTOR_PdoFxPowerCompletion(0,CONCAT71((int7)(uVar3 >> 8),2),iVar2,param_1);
  return;
}



===== USBSTOR_PdoFxPowerCompletion @ 14000e2e0 =====

void USBSTOR_PdoFxPowerCompletion
               (undefined8 param_1,undefined8 param_2,int param_3,longlong param_4)

{
  int *piVar1;
  int iVar2;
  
  USBSTOR_LogEntry(0x43786470,param_1,(longlong)param_3,(longlong)*(int *)(param_4 + 0x7ac));
  LOCK();
  piVar1 = (int *)(param_4 + 0x7ac);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    if (param_3 == 1) {
      USBSTOR_LogEntry(0x72707866,param_4,0,0);
      PoFxReportDevicePoweredOn(*(undefined8 *)(param_4 + 0x7b0));
    }
    else {
      USBSTOR_RequestFdoFxPowerIrp(param_4,4);
    }
  }
  return;
}



===== USBSTOR_RequestFdoFxPowerIrp @ 14000e364 =====

void USBSTOR_RequestFdoFxPowerIrp(longlong param_1,undefined4 param_2)

{
  PoRequestPowerIrp(*(undefined8 *)(param_1 + 8),2,param_2,USBSTOR_FdoFxPowerCompletion,param_1,0);
  return;
}



===== RtlUnicodeStringValidateDestWorker @ 14000e39c =====

ulonglong RtlUnicodeStringValidateDestWorker
                    (ushort *param_1,undefined8 *param_2,ulonglong *param_3,ulonglong *param_4)

{
  ulonglong uVar1;
  ushort *puVar2;
  
  *param_2 = 0;
  *param_3 = 0;
  if (param_4 != (ulonglong *)0x0) {
    *param_4 = 0;
  }
  puVar2 = param_1;
  uVar1 = RtlUnicodeStringValidateWorker(param_1);
  if ((-1 < (int)uVar1) && (puVar2 != (ushort *)0x0)) {
    *param_2 = *(undefined8 *)(param_1 + 4);
    *param_3 = (ulonglong)(puVar2[1] >> 1);
    if (param_4 != (ulonglong *)0x0) {
      *param_4 = (ulonglong)(*puVar2 >> 1);
    }
  }
  return uVar1 & 0xffffffff;
}



===== RtlUnicodeStringCat @ 14000e40c =====

ulonglong RtlUnicodeStringCat(ushort *param_1,ushort *param_2)

{
  ulonglong uVar1;
  ushort *puVar2;
  ulonglong uVar3;
  short sVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined2 *puVar8;
  longlong lVar9;
  ulonglong uVar10;
  
  puVar2 = param_1;
  uVar1 = RtlUnicodeStringValidateWorker(param_1);
  if (((int)uVar1 < 0) || (puVar2 == (ushort *)0x0)) {
    lVar5 = 0;
    uVar6 = 0;
    uVar10 = 0;
    if ((int)uVar1 < 0) {
      return uVar1 & 0xffffffff;
    }
  }
  else {
    lVar5 = *(longlong *)(puVar2 + 4);
    uVar6 = (ulonglong)(puVar2[1] >> 1);
    uVar10 = (ulonglong)(*puVar2 >> 1);
  }
  uVar1 = RtlUnicodeStringValidateWorker(param_2);
  if (((int)uVar1 < 0) || (param_2 == (ushort *)0x0)) {
    puVar8 = (undefined2 *)0x0;
    uVar3 = 0;
    if ((int)uVar1 < 0) {
      return uVar1 & 0xffffffff;
    }
  }
  else {
    puVar8 = *(undefined2 **)(param_2 + 4);
    uVar3 = (ulonglong)(*param_2 >> 1);
  }
  sVar4 = 0;
  uVar1 = 0;
  lVar7 = uVar6 - uVar10;
  if (lVar7 != 0) {
    lVar9 = uVar10 * 2 - (longlong)puVar8;
    do {
      if (uVar3 == 0) goto LAB_14000e4c0;
      uVar3 = uVar3 - 1;
      *(undefined2 *)(lVar9 + lVar5 + (longlong)puVar8) = *puVar8;
      sVar4 = sVar4 + 1;
      puVar8 = puVar8 + 1;
      lVar7 = lVar7 + -1;
    } while (lVar7 != 0);
  }
  uVar1 = 0;
  if (uVar3 != 0) {
    uVar1 = 0x80000005;
  }
LAB_14000e4c0:
  *param_1 = ((short)uVar10 + sVar4) * 2;
  return uVar1;
}



===== RtlUnicodeStringValidateWorker @ 14000e4ec =====

undefined8 RtlUnicodeStringValidateWorker(ushort *param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined8 uVar3;
  
  uVar1 = *param_1;
  uVar3 = 0;
  if ((((((uVar1 & 1) != 0) || (uVar2 = param_1[1], (uVar2 & 1) != 0)) || (uVar2 < uVar1)) ||
      (uVar2 == 0xffff)) || ((*(longlong *)(param_1 + 4) == 0 && ((uVar1 != 0 || (uVar2 != 0)))))) {
    uVar3 = 0xc000000d;
  }
  return uVar3;
}



===== USBD_VerifierSettingsCallback @ 14000e540 =====

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



===== UsbQueueIsBypassIrp @ 14000e574 =====

bool UsbQueueIsBypassIrp(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLock(param_2 + 0x120,&local_28);
  lVar1 = *(longlong *)(param_2 + 0x160);
  KeReleaseInStackQueuedSpinLock(&local_28);
  return param_1 == lVar1;
}



===== RtlStringCbPrintfA @ 14000e5dc =====

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



===== USBSTOR_FreeDumpPointers @ 14000e650 =====

int USBSTOR_FreeDumpPointers(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  uint uVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong *plVar9;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd0,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10) + 0x40);
  if (*(char *)(param_2 + 0x40) == '\0') {
    if (0x67 < *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10)) {
      lVar2 = *(longlong *)(param_2 + 0x18);
      lVar7 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(lVar1 + 0x18) >> 8),
                                     *(undefined1 *)(*(longlong *)(lVar1 + 0x18) + 0x4c)),0);
      if (lVar7 != 0) {
        KeInitializeEvent(&local_38,1);
        lVar3 = *(longlong *)(lVar7 + 0xb8);
        *(undefined1 *)(lVar3 + -0x48) = 0xf;
        *(undefined4 *)(lVar3 + -0x30) = 0x491408;
        lVar4 = *(longlong *)(*(longlong *)(lVar2 + 8) + 0x40);
        *(longlong *)(lVar7 + 0x18) = lVar4 + 0xd8;
        *(undefined4 *)(lVar3 + -0x38) = 0x58;
        iVar5 = IoSetCompletionRoutineEx
                          (param_1,lVar7,USBSTOR_SyncCompletionRoutine,&local_38,1,1,1);
        if (-1 < iVar5) {
          iVar5 = IofCallDriver(*(undefined8 *)(lVar1 + 0x18),lVar7);
          if (iVar5 == 0x103) {
            KeWaitForSingleObject(&local_38,0,0,0,0);
            iVar5 = *(int *)(lVar7 + 0x30);
          }
          IoFreeIrp(lVar7);
          plVar9 = *(longlong **)(lVar2 + 0x28);
          if (plVar9 != (longlong *)0x0) {
            if (*plVar9 != 0) {
              ExFreePoolWithTag(*plVar9,0);
            }
            ExFreePoolWithTag(plVar9,0);
          }
          uVar8 = 0;
          plVar9 = (longlong *)(lVar1 + 0x768);
          do {
            if (*plVar9 == lVar4) goto LAB_14000e830;
            uVar6 = (int)uVar8 + 1;
            uVar8 = (ulonglong)uVar6;
            plVar9 = plVar9 + 1;
          } while (uVar6 < 2);
          if (uVar6 != 2) {
LAB_14000e830:
            lVar2 = *(longlong *)(lVar1 + 0x768 + uVar8 * 8);
            if (lVar2 != 0) {
              ExFreePoolWithTag(lVar2,0);
              *(undefined8 *)(lVar1 + 0x768 + uVar8 * 8) = 0;
            }
            lVar2 = *(longlong *)(lVar1 + 0x778 + uVar8 * 8);
            if (lVar2 != 0) {
              ExFreePoolWithTag(lVar2,0);
              *(undefined8 *)(lVar1 + 0x778 + uVar8 * 8) = 0;
            }
          }
          goto LAB_14000e87a;
        }
        IoFreeIrp(lVar7);
      }
      return -0x3fffff66;
    }
    iVar5 = -0x3fffffdd;
  }
  else {
    iVar5 = -0x3ffffff0;
  }
LAB_14000e87a:
  *(int *)(param_2 + 0x30) = iVar5;
  IofCompleteRequest(param_2,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd1,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar5);
  }
  return iVar5;
}



===== USBSTOR_QuiesceDeviceWorkItem @ 14000e8f0 =====

void USBSTOR_QuiesceDeviceWorkItem(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  undefined1 uVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(*(longlong *)(*param_2 + 0xb8) + 8);
  iVar3 = USBSTOR_WaitForQuiesce(param_2[1],*(uint *)(lVar2 + 0x14));
  uVar4 = 9;
  if (iVar3 != 0x102) {
    uVar4 = 1;
  }
  *(undefined1 *)(lVar2 + 3) = uVar4;
  *(int *)(*param_2 + 0x30) = iVar3;
  IofCompleteRequest(*param_2,0);
  IoReleaseRemoveLockEx(lVar1 + 0x2e0,USBSTOR_QuiesceDeviceWorkItem,0x20);
  return;
}



===== USBSTOR_WaitForQuiesce @ 14000e984 =====

int USBSTOR_WaitForQuiesce(longlong param_1,uint param_2)

{
  int iVar1;
  longlong local_res8;
  
  iVar1 = 0;
  USBSTOR_LogEntry(0x51574451,param_1,0,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb2,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  if (*(int *)(param_1 + 0x128) <= *(int *)(param_1 + 300)) {
    local_res8 = (ulonglong)param_2 * -10000000;
    iVar1 = KeWaitForSingleObject(param_1 + 0x148,0,0,0,&local_res8);
    if (iVar1 != 0x102) {
      KeClearEvent(param_1 + 0x148);
    }
  }
  USBSTOR_LogEntry(0x71776471,param_1,(longlong)iVar1,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb3,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar1);
  }
  return iVar1;
}



===== UsbQueueClearBypassIrp @ 14000eaa4 =====

void UsbQueueClearBypassIrp(longlong param_1)

{
  int iVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeAcquireInStackQueuedSpinLock(param_1 + 0x120,&local_28);
  if (*(int *)(param_1 + 4) == 0) {
    iVar1 = *(int *)(param_1 + 300) + -1;
    *(int *)(param_1 + 300) = iVar1;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
               &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids,iVar1);
    }
    USBSTOR_LogEntry(0x49424351,param_1,0,(longlong)*(int *)(param_1 + 300));
  }
  *(undefined8 *)(param_1 + 0x160) = 0;
  KeReleaseInStackQueuedSpinLock(&local_28);
  return;
}



===== USBSTOR_QueryBreakOnDeviceFailure @ 14000eb60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void USBSTOR_QueryBreakOnDeviceFailure(void)

{
  code *pcVar1;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined1 local_78 [8];
  undefined4 local_70;
  wchar_t *local_68;
  undefined *local_60;
  undefined4 local_58;
  undefined *local_50;
  undefined4 local_48;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
            &WPP_aacf58c1c3d036691363e31f780ca4b7_Traceguids);
  }
  memset(local_78,0,0x70);
  local_70 = 0x20;
  local_68 = L"BreakOnUnexpectedDeviceFailure";
  local_58 = 4;
  local_60 = &USBSTOR_DriverGlobals;
  local_50 = &USBSTOR_DriverGlobals;
  local_48 = 4;
  local_88 = 0;
  uStack_80 = 0;
  RtlInitUnicodeString(&local_88,L"RtlQueryRegistryValuesEx");
  pcVar1 = (code *)MmGetSystemRoutineAddress(&local_88);
  if (pcVar1 == (code *)0x0) {
    pcVar1 = RtlQueryRegistryValues_exref;
  }
  (*pcVar1)(2,L"USBSTOR",local_78,0,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
            &WPP_aacf58c1c3d036691363e31f780ca4b7_Traceguids);
  }
  return;
}



===== USBSTOR_IssueClientBulkRequest @ 14000ec7c =====

int USBSTOR_IssueClientBulkRequest(longlong param_1,longlong param_2)

{
  undefined4 *puVar1;
  longlong lVar2;
  undefined8 uVar3;
  uint uVar4;
  longlong lVar5;
  longlong lVar6;
  int iVar7;
  undefined4 uVar8;
  
  iVar7 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x65,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  USBSTOR_LogEntry(0x4b424349,param_1,param_2,0);
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  uVar4 = *(uint *)(lVar2 + 0xc) & 0xc0;
  if (uVar4 == 0x40) {
    lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60);
    uVar8 = 2;
  }
  else {
    if (uVar4 != 0x80) {
      return -0x3ffffff3;
    }
    lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x68);
    uVar8 = 0;
  }
  lVar6 = *(longlong *)(param_2 + 8);
  puVar1 = (undefined4 *)(lVar2 + 0x10);
  uVar3 = *(undefined8 *)(lVar5 + 8);
  if ((ulonglong)*(uint *)(lVar6 + 0x2c) + *(longlong *)(lVar6 + 0x20) ==
      *(longlong *)(lVar2 + 0x18)) {
    if (lVar6 == 0) goto LAB_14000edb9;
  }
  else {
    lVar6 = IoAllocateMdl(*(longlong *)(lVar2 + 0x18),*puVar1,0,0,0);
    if (lVar6 == 0) {
      iVar7 = -0x3fffff66;
      goto LAB_14000edb9;
    }
    IoBuildPartialMdl(*(undefined8 *)(param_2 + 8),lVar6,*(undefined8 *)(lVar2 + 0x18),*puVar1);
  }
  USBSTOR_IssueBulkOrInterruptRequest
            (param_1,param_2,uVar3,uVar8,*puVar1,0,lVar6,USBSTOR_ClientBulkCompletionRoutine,0);
LAB_14000edb9:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x66,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar7);
  }
  USBSTOR_LogEntry(0x6b626369,param_1,param_2,(longlong)iVar7);
  return iVar7;
}



===== USBSTOR_GetDumpPointers @ 14000ee34 =====

int USBSTOR_GetDumpPointers(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 *_Dst;
  undefined8 *puVar2;
  longlong lVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  int iVar8;
  longlong *plVar9;
  undefined2 *puVar10;
  ulonglong uVar11;
  longlong lVar12;
  longlong *plVar13;
  undefined4 *puVar14;
  uint uVar15;
  undefined1 local_88 [4];
  undefined4 local_84;
  undefined1 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined1 *puStack_58;
  undefined8 local_50;
  ulonglong uStack_48;
  
  local_68 = 0;
  plVar13 = (longlong *)0x0;
  local_50 = 0;
  uStack_48 = uStack_48 & 0xffffffff00000000;
  local_78 = 0;
  uStack_70 = 0;
  local_60 = 0;
  puStack_58 = (undefined1 *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xce,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10) + 0x40);
  *(undefined8 *)(param_2 + 0x38) = 0;
  if (*(char *)(param_2 + 0x40) != '\0') {
    iVar8 = -0x3ffffff0;
    goto LAB_14000f1e1;
  }
  if (0x67 < *(uint *)(*(longlong *)(param_2 + 0xb8) + 8)) {
    _Dst = *(undefined4 **)(param_2 + 0x18);
    plVar9 = (longlong *)(lVar1 + 0x768);
    uVar15 = 0;
    do {
      if (*plVar9 == 0) goto LAB_14000ef0a;
      uVar15 = uVar15 + 1;
      plVar9 = plVar9 + 1;
    } while (uVar15 < 2);
    if (uVar15 != 2) {
LAB_14000ef0a:
      puStack_58 = local_88;
      local_60 = 2;
      uStack_48 = 0;
      local_88[0] = *(undefined1 *)(*(longlong *)(lVar1 + 0x60) + 2);
      local_84 = 0x14000;
      local_80 = *(undefined1 *)(*(longlong *)(lVar1 + 0x68) + 2);
      local_7c = 0x14000;
      local_50 = 1;
      puVar10 = (undefined2 *)ExAllocatePool2(0x40,0x130,0x706d64);
      if (puVar10 == (undefined2 *)0x0) {
        iVar8 = -0x3fffff66;
        goto LAB_14000f1e1;
      }
      puVar2 = *(undefined8 **)(lVar1 + 0x60);
      uVar7 = puVar2[1];
      *(undefined8 *)(puVar10 + 0x10) = *puVar2;
      *(undefined8 *)(puVar10 + 0x14) = uVar7;
      *(undefined8 *)(puVar10 + 0x18) = puVar2[2];
      puVar2 = *(undefined8 **)(lVar1 + 0x68);
      uVar7 = puVar2[1];
      *(undefined8 *)(puVar10 + 0x1c) = *puVar2;
      *(undefined8 *)(puVar10 + 0x20) = uVar7;
      *(undefined8 *)(puVar10 + 0x24) = puVar2[2];
      uVar7 = *(undefined8 *)(lVar1 + 400);
      *(undefined8 *)(puVar10 + 0x28) = *(undefined8 *)(lVar1 + 0x188);
      *(undefined8 *)(puVar10 + 0x2c) = uVar7;
      uVar7 = *(undefined8 *)(lVar1 + 0x1a0);
      *(undefined8 *)(puVar10 + 0x30) = *(undefined8 *)(lVar1 + 0x198);
      *(undefined8 *)(puVar10 + 0x34) = uVar7;
      uVar7 = *(undefined8 *)(lVar1 + 0x1b0);
      *(undefined8 *)(puVar10 + 0x38) = *(undefined8 *)(lVar1 + 0x1a8);
      *(undefined8 *)(puVar10 + 0x3c) = uVar7;
      uVar7 = *(undefined8 *)(lVar1 + 0x1c0);
      *(undefined8 *)(puVar10 + 0x40) = *(undefined8 *)(lVar1 + 0x1b8);
      *(undefined8 *)(puVar10 + 0x44) = uVar7;
      uVar7 = *(undefined8 *)(lVar1 + 0x1d0);
      *(undefined8 *)(puVar10 + 0x48) = *(undefined8 *)(lVar1 + 0x1c8);
      *(undefined8 *)(puVar10 + 0x4c) = uVar7;
      uVar4 = *(undefined4 *)(lVar1 + 0x1dc);
      uVar5 = *(undefined4 *)(lVar1 + 0x1e0);
      uVar6 = *(undefined4 *)(lVar1 + 0x1e4);
      *(undefined4 *)(puVar10 + 0x50) = *(undefined4 *)(lVar1 + 0x1d8);
      *(undefined4 *)(puVar10 + 0x52) = uVar4;
      *(undefined4 *)(puVar10 + 0x54) = uVar5;
      *(undefined4 *)(puVar10 + 0x56) = uVar6;
      uVar7 = *(undefined8 *)(lVar1 + 0x1f0);
      *(undefined8 *)(puVar10 + 0x58) = *(undefined8 *)(lVar1 + 0x1e8);
      *(undefined8 *)(puVar10 + 0x5c) = uVar7;
      uVar4 = *(undefined4 *)(lVar1 + 0x1fc);
      uVar5 = *(undefined4 *)(lVar1 + 0x200);
      uVar6 = *(undefined4 *)(lVar1 + 0x204);
      *(undefined4 *)(puVar10 + 0x60) = *(undefined4 *)(lVar1 + 0x1f8);
      *(undefined4 *)(puVar10 + 0x62) = uVar4;
      *(undefined4 *)(puVar10 + 100) = uVar5;
      *(undefined4 *)(puVar10 + 0x66) = uVar6;
      *(undefined8 *)(puVar10 + 0x68) = *(undefined8 *)(lVar1 + 0x208);
      *puVar10 = 0x130;
      *(undefined4 *)(puVar10 + 0x94) = 0x1f;
      *(undefined1 *)(puVar10 + 0x96) = 0;
      uVar11 = (ulonglong)uVar15;
      *(undefined2 **)(lVar1 + 0x768 + uVar11 * 8) = puVar10;
      lVar12 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(lVar1 + 0x18) >> 8),
                                      *(undefined1 *)(*(longlong *)(lVar1 + 0x18) + 0x4c)),0);
      if (lVar12 == 0) {
LAB_14000f17d:
        iVar8 = -0x3fffff66;
      }
      else {
        KeInitializeEvent(&local_78,1);
        lVar3 = *(longlong *)(lVar12 + 0xb8);
        *(undefined1 *)(lVar3 + -0x48) = 0xf;
        *(undefined4 *)(lVar3 + -0x30) = 0x491404;
        *(undefined4 *)(lVar3 + -0x38) = 0x20;
        *(undefined4 *)(lVar3 + -0x40) = 0x58;
        *(undefined8 **)(lVar12 + 0x18) = &local_60;
        *(undefined2 **)(lVar12 + 0x70) = puVar10 + 0x6c;
        iVar8 = IoSetCompletionRoutineEx
                          (param_1,lVar12,USBSTOR_SyncCompletionRoutine,&local_78,1,1,1);
        if (-1 < iVar8) {
          iVar8 = IofCallDriver(*(undefined8 *)(lVar1 + 0x18),lVar12);
          if (iVar8 == 0x103) {
            KeWaitForSingleObject(&local_78,0,0,0,0);
            iVar8 = *(int *)(lVar12 + 0x30);
          }
          if (-1 < iVar8) {
            IoFreeIrp(lVar12);
            lVar12 = 0;
            if (((*(longlong *)(puVar10 + 0x8c) != 0) && (*(longlong *)(puVar10 + 0x90) != 0)) &&
               ((plVar13 = USBSTOR_DeviceBuildDumpDriverList(), plVar13 != (longlong *)0x0 &&
                (puVar14 = (undefined4 *)ExAllocatePool2(0x40,0x98,0x706d64),
                puVar14 != (undefined4 *)0x0)))) {
              *puVar14 = 0x98;
              puVar14[2] = 0xf;
              puVar14[6] = 0x14000;
              *(undefined2 **)(puVar14 + 0x10) = puVar10;
              *(undefined4 **)(lVar1 + 0x778 + uVar11 * 8) = puVar14;
              memset(_Dst,0,0x68);
              *_Dst = 3;
              _Dst[1] = 0x68;
              *(undefined4 **)(_Dst + 2) = puVar14;
              *(undefined1 *)(_Dst + 7) = 1;
              *(longlong **)(_Dst + 10) = plVar13;
              _Dst[0xf] = 0x14000;
              if (*(char *)(puVar10 + 0x96) == '\x01') {
                _Dst[0xc] = _Dst[0xc] | 4;
              }
              *(undefined8 *)(param_2 + 0x38) = 0x68;
              *(int *)(param_2 + 0x30) = iVar8;
              IofCompleteRequest(param_2,0);
              if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                return iVar8;
              }
              if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
                return iVar8;
              }
              if ((byte)WPP_GLOBAL_Control[0x29] < 5) {
                return iVar8;
              }
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xcf,
                       &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar8);
              return iVar8;
            }
            goto LAB_14000f17d;
          }
        }
      }
      ExFreePoolWithTag(puVar10,0);
      *(undefined8 *)(lVar1 + 0x768 + uVar11 * 8) = 0;
      if (lVar12 != 0) {
        IoFreeIrp(lVar12);
      }
      if (plVar13 != (longlong *)0x0) {
        if (*plVar13 != 0) {
          ExFreePoolWithTag(*plVar13,0);
        }
        ExFreePoolWithTag(plVar13,0);
      }
      goto LAB_14000f1e1;
    }
  }
  iVar8 = -0x3fffffdd;
LAB_14000f1e1:
  *(int *)(param_2 + 0x30) = iVar8;
  IofCompleteRequest(param_2,0);
  return iVar8;
}



===== USBSTOR_PdoSetPowerCompletion @ 14000f2e0 =====

void USBSTOR_PdoSetPowerCompletion(longlong param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  char *pcVar5;
  undefined *puVar6;
  int *in_stack_00000028;
  
  lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x38);
  *(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x38) = 0;
  iVar2 = *(int *)(*(longlong *)(lVar4 + 0xb8) + 0x18);
  iVar3 = *in_stack_00000028;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar6 = WPP_GLOBAL_Control;
    pcVar5 = PowerSystemStateString(iVar2);
    WPP_SF_qqsD(*(undefined8 *)(puVar6 + 0x18),0x2f,puVar6,param_1,(char)lVar4,pcVar5,(char)iVar3);
  }
  USBSTOR_LogEntry(0x63707370,param_1,(longlong)iVar2,(longlong)iVar3);
  pbVar1 = (byte *)(*(longlong *)(lVar4 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
  *(undefined4 *)(lVar4 + 0x30) = 0;
  PoStartNextPowerIrp(lVar4);
  IofCompleteRequest(lVar4,0);
  return;
}



===== USBD_SyncCompletionRoutine @ 14000f3c0 =====

undefined8 USBD_SyncCompletionRoutine(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== RtlStringCopyWorkerW @ 14000f3ec =====

uint RtlStringCopyWorkerW(short *param_1,longlong param_2)

{
  short sVar1;
  longlong lVar2;
  longlong lVar3;
  short *psVar4;
  
  if (param_2 != 0) {
    lVar2 = 0x7ffffffe;
    lVar3 = (longlong)L"\\Parameters" - (longlong)param_1;
    do {
      if ((lVar2 == 0) || (sVar1 = *(short *)(lVar3 + (longlong)param_1), sVar1 == 0)) break;
      *param_1 = sVar1;
      lVar2 = lVar2 + -1;
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  psVar4 = param_1 + -1;
  if (param_2 != 0) {
    psVar4 = param_1;
  }
  *psVar4 = 0;
  return ~-(uint)(param_2 != 0) & 0x80000005;
}



===== USBSTOR_FxDevicePowerRequiredCallback @ 14000f450 =====

void USBSTOR_FxDevicePowerRequiredCallback(longlong param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb4,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  USBSTOR_LogEntry(0x52507846,param_1,(ulonglong)*(byte *)(param_1 + 0x7aa),0);
  if (*(char *)(param_1 + 0x7aa) == '\0') {
    PoFxReportDevicePoweredOn(*(undefined8 *)(param_1 + 0x7b0));
  }
  else {
    USBSTOR_RequestFdoFxPowerIrp(param_1,1);
    *(undefined1 *)(param_1 + 0x7aa) = 0;
  }
  return;
}



===== USBSTOR_FxDirectedPowerUpCallback @ 14000f4f0 =====

void USBSTOR_FxDirectedPowerUpCallback(longlong param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb6,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  USBSTOR_LogEntry(0x55447846,param_1,0,0);
  if (*(char *)(param_1 + 0x7aa) != '\0') {
    USBSTOR_RequestFdoFxPowerIrp(param_1,1);
    *(undefined1 *)(param_1 + 0x7aa) = 0;
  }
  return;
}



===== UsbCompleteFlushedIrp @ 14000f56c =====

void UsbCompleteFlushedIrp(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
            &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
  }
  lVar2 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  if ((*(uint *)(lVar2 + 0xc) & 0x2000000) != 0) {
    USBSTOR_FxPowerReference(*(longlong *)(*(longlong *)(lVar1 + 0x10) + 0x40),lVar2,'\0');
  }
  *(undefined1 *)(lVar2 + 3) = 0x16;
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc0000001;
  IofCompleteRequest(param_2,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
            &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
  }
  return;
}



===== USBDInternal_BuildServicePath @ 14000f650 =====

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
      _Dst = (short *)ExAllocatePoolWithTag(DAT_14001a200,uVar1,0x53414d55);
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
          ExFreePoolWithTag(_Dst,0x53414d55);
          _Dst = (short *)0x0;
        }
        else {
          uVar4 = 0;
        }
      }
      goto LAB_14000f794;
    }
  }
  if (g_EnableDbgPrints != '\0') {
    DbgPrintEx(0x4d,0,"Unexpected Driver name, Drvobj 0x%p\n",lVar3);
  }
  uVar4 = 0xc00000e5;
LAB_14000f794:
  *param_2 = _Dst;
  return uVar4;
}



===== RtlStringCbCatW @ 14000f7bc =====

uint RtlStringCbCatW(short *param_1,ulonglong param_2)

{
  uint uVar1;
  short *psVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  uVar3 = param_2 >> 1;
  if (uVar3 - 1 < 0x7fffffff) {
    psVar2 = param_1;
    uVar4 = uVar3;
    do {
      if (*psVar2 == 0) break;
      psVar2 = psVar2 + 1;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
    if (uVar4 == 0) {
      uVar1 = 0xc000000d;
    }
    else {
      uVar1 = RtlStringCopyWorkerW(param_1 + (uVar3 - uVar4),uVar3 - (uVar3 - uVar4));
    }
  }
  else {
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== USBSTOR_ClientBulkCompletionRoutine @ 14000f830 =====

undefined4 USBSTOR_ClientBulkCompletionRoutine(longlong param_1,longlong param_2)

{
  int *piVar1;
  undefined *puVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined *puVar7;
  int *piVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined4 local_res8 [2];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  uVar4 = 0;
  local_res8[0] = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  piVar8 = (int *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x67,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  USBSTOR_LogEntry(0x434b4243,param_1,param_2,(longlong)*(int *)(param_2 + 0x30));
  piVar1 = *(int **)(param_1 + 0x40);
  if (*piVar1 == 0x214f4450) {
    lVar6 = *(longlong *)(piVar1 + 4);
    piVar8 = piVar1;
    piVar9 = *(int **)(*(longlong *)(piVar1 + 4) + 0x40);
  }
  else {
    lVar6 = 0;
    piVar9 = (int *)0x0;
    if (*piVar1 == 0x214f4446) {
      lVar6 = param_1;
      piVar9 = piVar1;
    }
  }
  puVar2 = *(undefined **)(*(longlong *)(param_2 + 0xb8) + 8);
  if (*(longlong *)(piVar9 + 0x6e) != *(longlong *)(param_2 + 8)) {
    IoFreeMdl();
  }
  bVar3 = USBSTOR_CheckRequestTimeOut(lVar6,param_2,puVar2,local_res8);
  if (bVar3) {
    USBSTOR_LogEntry(0x316b6263,lVar6,param_2,puVar2);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x68,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    }
    uVar4 = local_res8[0];
  }
  else if (*(int *)(param_2 + 0x30) < 0) {
    USBSTOR_LogEntry(0x326b6263,(longlong)*(int *)(param_2 + 0x30),(longlong)piVar9[99],0);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x69,
                &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,*(undefined4 *)(param_2 + 0x30),
                (char)piVar9[99]);
    }
    if ((piVar9[99] & 0xfffffffU) == 4) {
      *(undefined2 *)(puVar2 + 3) = 0x204;
      *(int *)(puVar2 + 0x10) = piVar9[0x6b];
      if ((((*(uint *)(puVar2 + 0xc) & 0x20) == 0) && (puVar2[0xb] != '\0')) &&
         (*(longlong *)(puVar2 + 0x20) != 0)) {
        USBSTOR_LogEntry(0x336b6263,lVar6,param_2,puVar2);
        uVar4 = 0xc0000016;
      }
      else {
        USBSTOR_LogEntry(0x346b6263,lVar6,param_2,puVar2);
        uVar4 = 0xc0000185;
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000185;
        KeAcquireInStackQueuedSpinLock(piVar9 + 0x24,&local_48);
        piVar9[0x20] = piVar9[0x20] | 4;
        KeReleaseInStackQueuedSpinLock(&local_48);
        USBSTOR_TranslateCDBComplete(lVar6,param_2,(longlong)puVar2);
      }
      USBSTOR_QueueResetPipe(lVar6,piVar8);
    }
    else {
      USBSTOR_LogEntry(0x356b6263,lVar6,param_2,puVar2);
      *(undefined8 *)(param_2 + 0x38) = 0;
      uVar4 = 0xc0000185;
      *(undefined4 *)(param_2 + 0x30) = 0xc0000185;
      puVar2[3] = 0xe;
      USBSTOR_TranslateCDBComplete(lVar6,param_2,(longlong)puVar2);
      USBSTOR_QueueResetDevice(lVar6,piVar8);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6a,
                &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
      }
    }
  }
  else {
    puVar2[3] = (-((uint)piVar9[0x6b] < *(uint *)(puVar2 + 0x10)) & 0x11U) + 1;
    *(int *)(puVar2 + 0x10) = piVar9[0x6b];
    if (*(longlong *)(piVar9 + 0x1c) == 0) {
      USBSTOR_LogEntry(0x376b6263,lVar6,param_2,(ulonglong)(uint)piVar9[0x6b]);
      *(undefined4 *)(param_2 + 0x30) = 0;
      uVar10 = 0;
      puVar7 = puVar2;
      USBSTOR_TranslateCDBComplete(lVar6,param_2,(longlong)puVar2);
      puVar5 = (undefined8 *)0x0;
      *(ulonglong *)(param_2 + 0x38) = (ulonglong)*(uint *)(puVar2 + 0x10);
      USBSTOR_SetSrbPending((longlong)piVar9,'\0');
      UsbStorPumpNextRequest((longlong)piVar8,puVar5,puVar7);
      UsbStorStartNextPacket(lVar6);
    }
    else {
      USBSTOR_LogEntry(0x366b6263,lVar6,param_2,(ulonglong)(uint)piVar9[0x6b]);
      USBSTOR_IssueInterruptRequest(lVar6,param_2);
      uVar10 = 0xc0000016;
      uVar4 = 0xc0000016;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6b,
               &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,uVar10);
    }
  }
  return uVar4;
}



===== UsbRemoveIrp @ 14000fbf4 =====

byte UsbRemoveIrp(longlong param_1,longlong param_2)

{
  byte bVar1;
  uint uVar2;
  longlong *plVar3;
  longlong *plVar4;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
            &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
  }
  plVar4 = (longlong *)(param_2 + 0x78);
  uVar2 = UsbGetIrpPriority(param_1,param_2);
  plVar3 = (longlong *)UsbGetStreamSubQueue(param_1,param_2);
  bVar1 = PortListSearchAndRemoveRequest((longlong *)(param_1 + 0x20),plVar4);
  if (bVar1 == 0) {
    if (uVar2 < 6) {
      plVar3 = (longlong *)((ulonglong)(uVar2 - 1) * 0x38 + 0x58 + param_1);
    }
    bVar1 = PortListSearchAndRemoveRequest(plVar3,plVar4);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
             &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids,(uint)bVar1);
  }
  return bVar1;
}



===== PortListSearchAndRemoveRequest @ 14000fcf0 =====

undefined1 PortListSearchAndRemoveRequest(longlong *param_1,longlong *param_2)

{
  longlong *plVar1;
  undefined1 uVar2;
  
  plVar1 = (longlong *)*param_1;
  while( true ) {
    if (plVar1 == param_1) {
      return 0;
    }
    if (plVar1 == param_2) break;
    plVar1 = (longlong *)*plVar1;
  }
  uVar2 = 1;
  PortListRemoveRequest(param_1,param_2);
  return uVar2;
}



===== USBSTOR_ProcessRequestSenseCompletion @ 14000fd20 =====

undefined4
USBSTOR_ProcessRequestSenseCompletion(longlong param_1,undefined *param_2,longlong param_3)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined8 *puVar6;
  undefined1 uVar7;
  
  USBSTOR_LogEntry(0x43535250,param_1,param_2,0);
  uVar7 = 1;
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  lVar4 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (param_3 == 1) {
    USBSTOR_LogEntry(0x31737270,param_1,param_2,lVar4);
    if (((*(byte *)(lVar2 + 0x4b8) & 0xf) == 6) && (*(char *)(lVar2 + 0x4c2) == ')')) {
      *(undefined1 *)(lVar2 + 0x714) = 1;
    }
    USBSTOR_IssueClientCdb(param_1,(longlong)param_2);
    return 0xc0000016;
  }
  *(byte *)(lVar4 + 3) = *(byte *)(lVar4 + 3) | 0x80;
  USBSTOR_TranslateCDBComplete(param_1,(longlong)param_2,lVar4);
  uVar1 = *(undefined4 *)(param_2 + 0x30);
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)*(uint *)(lVar4 + 0x10);
  if ((*(byte *)(lVar2 + 0x4b8) & 0xf) == 6) {
    if (((*(char *)(lVar2 + 0x4c2) == '(') && (*(char *)(lVar2 + 0x714) == '\0')) &&
       ((*(uint *)(lVar2 + 0x84) & 2) != 0)) {
      USBSTOR_LogEntry(0x32737270,param_1,param_2,lVar4);
      USBSTOR_QueueResetDevice(param_1,lVar3);
      return uVar1;
    }
    if (*(char *)(lVar2 + 0x4c2) == ')') {
      uVar5 = 0x33737270;
      goto LAB_14000fe39;
    }
  }
  uVar7 = 0;
  uVar5 = 0x34737270;
LAB_14000fe39:
  USBSTOR_LogEntry(uVar5,param_1,param_2,lVar4);
  puVar6 = (undefined8 *)0x0;
  *(undefined1 *)(lVar2 + 0x714) = uVar7;
  USBSTOR_SetSrbPending(lVar2,'\0');
  UsbStorPumpNextRequest(lVar3,puVar6,param_2);
  UsbStorStartNextPacket(param_1);
  return uVar1;
}



===== PortListInitialize @ 14000fe90 =====

void PortListInitialize(longlong param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 0x18) = 0;
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(longlong *)(param_1 + 8) = param_1;
  *(longlong *)param_1 = param_1;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(longlong *)(param_1 + 0x10) = param_1;
  *(undefined8 *)(param_1 + 0x20) = param_2;
  return;
}



===== USBSTOR_FdoSetPowerCompletion @ 14000fec0 =====

void USBSTOR_FdoSetPowerCompletion
               (undefined8 param_1,undefined8 param_2,int param_3,longlong param_4)

{
  byte *pbVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *puVar4;
  
  lVar2 = *(longlong *)(param_4 + 0x40);
  if (param_3 == 1) {
    if (*(longlong *)(lVar2 + 0x7b0) != 0) {
      USBSTOR_LogEntry(0x72707866,lVar2,0,0);
      PoFxReportDevicePoweredOn(*(undefined8 *)(lVar2 + 0x7b0));
    }
  }
  else {
    lVar3 = *(longlong *)(lVar2 + 0xa0);
    *(undefined8 *)(lVar2 + 0xa0) = 0;
    PoStartNextPowerIrp(lVar3);
    if ((*(uint *)(param_4 + 0x30) & 0x2000) == 0) {
      IofCompleteRequest(lVar3,0);
    }
    else {
      puVar4 = *(undefined8 **)(lVar3 + 0xb8);
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
      pbVar1 = (byte *)(*(longlong *)(lVar3 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      PoCallDriver(*(undefined8 *)(lVar2 + 0x18),lVar3);
    }
  }
  return;
}



===== USBSTOR_IssueRequestSenseInterruptRequest @ 14000ffb0 =====

int USBSTOR_IssueRequestSenseInterruptRequest(longlong param_1,longlong param_2,undefined8 param_3)

{
  int iVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x80,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  USBSTOR_LogEntry(0x49535249,param_1,param_2,0);
  iVar1 = USBSTOR_IssueBulkOrInterruptRequest
                    (param_1,param_2,
                     *(undefined8 *)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x70) + 8),0,2,
                     *(longlong *)(param_1 + 0x40) + 0x4a8,0,
                     USBSTOR_RequestSenseInterruptCompletionRoutine,param_3);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x81,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar1);
  }
  USBSTOR_LogEntry(0x69737269,param_1,param_2,(longlong)iVar1);
  return iVar1;
}



===== USBSTOR_CancelInterruptIrp @ 1400100c0 =====

void USBSTOR_CancelInterruptIrp(longlong param_1)

{
  undefined4 uVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeAcquireInStackQueuedSpinLock(param_1 + 0x90,&local_28);
  uVar1 = *(undefined4 *)(param_1 + 0x80);
  KeReleaseInStackQueuedSpinLock(&local_28);
  if ((char)uVar1 < '\0') {
    IoCancelIrp(*(undefined8 *)(param_1 + 0x168));
  }
  return;
}



===== USBD_CreateHandle @ 140010134 =====

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
    if (DAT_14001a204 == '\0') {
      DAT_14001a200 = 0;
      memset(&local_164,0,0x118);
      local_168 = 0x11c;
      iVar5 = RtlGetVersion(&local_168);
      if ((-1 < iVar5) && ((6 < local_164 || ((local_164 == 6 && (1 < local_160)))))) {
        DAT_14001a200 = 0x200;
      }
    }
    DAT_14001a204 = '\x01';
    if (param_1 == 0) {
      if (g_EnableDbgPrints != '\0') {
        pcVar6 = "DeviceObject cannot be NULL\n";
LAB_140010240:
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
        _Dst = (undefined4 *)ExAllocatePoolWithTag(DAT_14001a200,0xe8,0x53414d55);
        if (_Dst == (undefined4 *)0x0) {
          if (g_EnableDbgPrints != '\0') {
            DbgPrintEx(0x4d,0,"Allocation Failed\n");
          }
          iVar5 = -0x3fffff66;
          goto LAB_140010533;
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
        _Dst[0x10] = 0x53414d55;
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
          if (-1 < iVar5) goto LAB_140010364;
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
LAB_140010364:
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
LAB_140010406:
          *param_5 = _Dst;
          return iVar5;
        }
        if (-1 < iVar5) goto LAB_140010406;
        if ((bVar2) && (*(code **)(_Dst + 0x1c) != (code *)0x0)) {
          (**(code **)(_Dst + 0x1c))(*(undefined8 *)(_Dst + 0xc));
        }
        ExFreePoolWithTag(_Dst,0x53414d55);
        goto LAB_140010533;
      }
      if (g_EnableDbgPrints != '\0') {
        pcVar6 = "TargetDeviceObject cannot be NULL\n";
        goto LAB_140010240;
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
LAB_140010533:
  *param_5 = 0;
  return iVar5;
}



===== PortPassThroughExNormalize @ 140010544 =====

undefined8 PortPassThroughExNormalize(undefined8 *param_1,longlong param_2)

{
  void *_Src;
  undefined8 *puVar1;
  undefined8 uVar2;
  char cVar3;
  undefined8 uVar4;
  
  _Src = *(void **)(param_2 + 0x18);
  uVar4 = 0;
  cVar3 = IoIs32bitProcess(param_2);
  puVar1 = *(undefined8 **)(param_2 + 0x18);
  if (cVar3 == '\0') {
    if (*(int *)(puVar1 + 1) + 0x3fU < 0x40) {
      uVar4 = 0xc0000095;
    }
    else {
      memmove(param_1,_Src,(ulonglong)(*(int *)(puVar1 + 1) + 0x3fU));
    }
  }
  else {
    uVar2 = puVar1[1];
    *param_1 = *puVar1;
    param_1[1] = uVar2;
    uVar2 = puVar1[3];
    param_1[2] = puVar1[2];
    param_1[3] = uVar2;
    param_1[4] = puVar1[4];
    memmove(param_1 + 7,puVar1 + 6,(ulonglong)*(uint *)(puVar1 + 1));
    param_1[5] = (ulonglong)*(uint *)(puVar1 + 5);
    param_1[6] = (ulonglong)*(uint *)((longlong)puVar1 + 0x2c);
  }
  return uVar4;
}



===== USBSTOR_FdoSetPowerSx @ 1400105f4 =====

void USBSTOR_FdoSetPowerSx(longlong param_1)

{
  byte *pbVar1;
  longlong lVar2;
  undefined4 local_res8 [2];
  
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0xa0);
  pbVar1 = (byte *)(*(longlong *)(lVar2 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb2,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  USBSTOR_LogEntry(0x42445750,param_1,lVar2,0);
  local_res8[0] = 0;
  IoStartPacket(param_1,lVar2,local_res8,0);
  return;
}



===== PortPassThroughExApplyNormalizedRequest @ 140010690 =====

void PortPassThroughExApplyNormalizedRequest(undefined8 *param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  char cVar3;
  
  puVar1 = *(undefined8 **)(param_2 + 0x18);
  cVar3 = IoIs32bitProcess(param_2);
  uVar2 = param_1[1];
  if (cVar3 == '\0') {
    *puVar1 = *param_1;
    puVar1[1] = uVar2;
    uVar2 = param_1[3];
    puVar1[2] = param_1[2];
    puVar1[3] = uVar2;
    uVar2 = param_1[5];
    puVar1[4] = param_1[4];
    puVar1[5] = uVar2;
    uVar2 = param_1[7];
    puVar1[6] = param_1[6];
    puVar1[7] = uVar2;
  }
  else {
    puVar1 = *(undefined8 **)(param_2 + 0x18);
    *puVar1 = *param_1;
    puVar1[1] = uVar2;
    uVar2 = param_1[3];
    puVar1[2] = param_1[2];
    puVar1[3] = uVar2;
    puVar1[4] = param_1[4];
  }
  return;
}



===== WPP_SF_DDD @ 14001070c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_e947f7dfdc8330b398201c2535585168_Traceguids,param_2,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qqq @ 140010770 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_e947f7dfdc8330b398201c2535585168_Traceguids,0x38,&local_res20,8,
             &param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_qq @ 1400107d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,0);
  return;
}



===== WPP_SF_D @ 140010824 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== McGenEventUnregister_EtwUnregister @ 140010868 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (USBSTOR_DIAG_TRACE_PROVIDER_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    USBSTOR_DIAG_TRACE_PROVIDER_Context = 0;
  }
  return uVar1;
}



===== WPP_SF_ @ 14001089c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== PortAvioAdmissionControllerInit @ 1400108c8 =====

undefined8 PortAvioAdmissionControllerInit(longlong param_1)

{
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x18) = 0x96;
  *(longlong *)(param_1 + 8) = param_1;
  *(longlong *)param_1 = param_1;
  return 0;
}



===== USBSTOR_PreInitializeEmergencyWorkerThread @ 1400108ec =====

void USBSTOR_PreInitializeEmergencyWorkerThread(void)

{
  KeInitializeEvent(&EmergencyWorkerThreadEvent,1,1);
  return;
}



===== McGenEventRegister_EtwRegister @ 140010918 =====

void McGenEventRegister_EtwRegister(void)

{
  if (USBSTOR_DIAG_TRACE_PROVIDER_Context == 0) {
    EtwRegister(&USBSTOR_DIAG_TRACE_PROVIDER,McGenControlCallbackV2,
                &USBSTOR_DIAG_TRACE_PROVIDER_Context,&USBSTOR_DIAG_TRACE_PROVIDER_Context);
  }
  return;
}



===== __report_gsfailure @ 140010970 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 14001097d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014001097d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== DumpPreInitialize @ 140010990 =====

void DumpPreInitialize(void)

{
                    /* 0x10990  1  DumpPreInitialize */
  DAT_14001a158 = 1;
  wil_InitializeFeatureStaging();
  return;
}



===== DumpUninitialize @ 1400109b0 =====

void DumpUninitialize(void)

{
                    /* 0x109b0  2  DumpUninitialize */
  wil_UninitializeFeatureStaging();
  return;
}



===== McGenControlCallbackV2 @ 1400109d0 =====

void McGenControlCallbackV2
               (undefined8 param_1,int param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  if (param_7 != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(ushort *)(param_7 + 0x2a) != 0) {
        memset(*(void **)(param_7 + 0x30),0,
               (longlong)((int)(*(ushort *)(param_7 + 0x2a) - 1) / 0x20 + 1) << 2);
      }
    }
    else if (param_2 == 1) {
      *(undefined1 *)(param_7 + 0x28) = param_3;
      uVar6 = 0;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          uVar2 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + uVar6 * 8);
          if (((*(byte *)(param_7 + 0x28) < *(byte *)(uVar6 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar2 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar2) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar2) != *(ulonglong *)(param_7 + 0x18))))))) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
          uVar4 = 1 << ((byte)uVar6 & 0x1f);
          puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (uVar6 >> 5) * 4);
          uVar5 = *puVar1;
          if (bVar3) {
            uVar4 = uVar4 | uVar5;
          }
          else {
            uVar4 = ~uVar4 & uVar5;
          }
          *puVar1 = uVar4;
          uVar5 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar5;
        } while (uVar5 < *(ushort *)(param_7 + 0x2a));
      }
    }
  }
  return;
}



===== RtlUnicodeStringCatString @ 140010ae0 =====

ulonglong RtlUnicodeStringCatString(ushort *param_1,short *param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  short sVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong local_res18;
  ulonglong local_res20;
  longlong local_18 [2];
  
  local_18[0] = 0;
  local_res18 = 0;
  local_res20 = 0;
  uVar1 = RtlUnicodeStringValidateDestWorker(param_1,local_18,&local_res18,&local_res20);
  if ((int)uVar1 < 0) {
    return uVar1 & 0xffffffff;
  }
  lVar5 = 0x7fff;
  uVar1 = 0;
  sVar3 = 0;
  lVar4 = local_res18 - local_res20;
  if (lVar4 != 0) {
    lVar2 = local_res20 * 2 - (longlong)param_2;
    do {
      if (lVar5 == 0) goto LAB_140010b79;
      if (*param_2 == 0) break;
      *(short *)(lVar2 + local_18[0] + (longlong)param_2) = *param_2;
      lVar5 = lVar5 + -1;
      param_2 = param_2 + 1;
      sVar3 = sVar3 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    if ((lVar4 != 0) || (lVar5 == 0)) goto LAB_140010b79;
  }
  uVar1 = 0;
  if (*param_2 != 0) {
    uVar1 = 0x80000005;
  }
LAB_140010b79:
  *param_1 = (sVar3 + (short)local_res20) * 2;
  return uVar1;
}



===== USBSTOR_FdoSetPowerD3ToD0Completion @ 140010ba0 =====

void USBSTOR_FdoSetPowerD3ToD0Completion
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
               int *param_5)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb3,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  USBSTOR_LogEntry(0x30443344,param_4,param_1,(longlong)*param_5);
  USBSTOR_FdoSetPowerSx(param_4);
  return;
}



===== USBSTOR_FdoSetPowerSxCompletion @ 140010c20 =====

int USBSTOR_FdoSetPowerSxCompletion(longlong param_1,longlong param_2,undefined4 param_3)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb1,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  USBSTOR_LogEntry(0x43535346,param_1,param_2,0);
  iVar2 = PoRequestPowerIrp(*(undefined8 *)(lVar1 + 0x10),2,param_3,USBSTOR_FdoSetPowerCompletion,
                            param_1,0);
  if (iVar2 < 0) {
    *(int *)(param_2 + 0x30) = iVar2;
    IofCompleteRequest(param_2,0);
  }
  else {
    iVar2 = -0x3fffffea;
  }
  return iVar2;
}



===== USBSTOR_FxComponentIdleStateCallback @ 140010cf0 =====

void USBSTOR_FxComponentIdleStateCallback(longlong param_1)

{
  PoFxCompleteIdleState(*(undefined8 *)(param_1 + 0x7b0));
  return;
}



===== USBSTOR_FxDevicePowerNotRequiredCallback @ 140010d20 =====

void USBSTOR_FxDevicePowerNotRequiredCallback(longlong param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb5,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  USBSTOR_LogEntry(0x4e507846,param_1,0,0);
  USBSTOR_RequestChildPdosFxPowerIrps(param_1,4);
  *(undefined1 *)(param_1 + 0x7aa) = 1;
  return;
}



===== USBSTOR_FxDirectedPowerDownCallback @ 140010da0 =====

void USBSTOR_FxDirectedPowerDownCallback(longlong param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb7,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  USBSTOR_LogEntry(0x44447846,param_1,0,0);
  USBSTOR_RequestChildPdosFxPowerIrps(param_1,4);
  *(undefined2 *)(param_1 + 0x7aa) = 0x101;
  return;
}



===== USBSTOR_FxPowerControlCallback @ 140010e20 =====

undefined8 USBSTOR_FxPowerControlCallback(void)

{
  return 0xc0000002;
}



===== USBSTOR_PowerActiveIdle @ 140010e30 =====

undefined4 USBSTOR_PowerActiveIdle(longlong param_1,longlong param_2,char param_3)

{
  longlong lVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  lVar1 = *(longlong *)
           (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10) + 0x40) + 0x7b0);
  if (lVar1 == 0) {
    uVar2 = 0xc00000bb;
  }
  else if (param_3 == '\0') {
    PoFxIdleComponent(lVar1,0,0);
  }
  else {
    PoFxActivateComponent(lVar1,0,0);
  }
  *(undefined4 *)(param_2 + 0x30) = uVar2;
  IofCompleteRequest(param_2,0);
  return uVar2;
}



===== WPP_SF_DD @ 140010eb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,0);
  return;
}



===== WPP_SF_Dq @ 140010f00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,0x4f,local_res20,4,
             &param_5,8,0);
  return;
}



===== WPP_SF_Ds @ 140010f5c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Ds(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              char *param_5)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 local_res20 [2];
  
  if (param_5 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_5[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_5 == (char *)0x0) {
    param_5 = "NULL";
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,0xad,local_res20,4,
             param_5,lVar2,0);
  return;
}



===== WPP_SF_S @ 140010fe8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_S(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4)

{
  longlong lVar1;
  
  if (param_4 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,param_2,param_4,lVar1,0);
  return;
}



===== WPP_SF_dD @ 14001105c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,param_2,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_q @ 1400110b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== WPP_SF_qqsD @ 1400110f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqsD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,char *param_6,undefined1 param_7)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined8 local_res20;
  
  if (param_6 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_6[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  pcVar3 = param_6;
  if (param_6 == (char *)0x0) {
    pcVar3 = "NULL";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,param_2,&local_res20,8,
             &param_5,8,pcVar3,lVar2,&param_7,4,0);
  return;
}



===== WPP_SF_qs @ 1400111b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qs(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              char *param_5)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 local_res20;
  
  if (param_5 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_5[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  if (param_5 == (char *)0x0) {
    param_5 = "NULL";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,param_2,&local_res20,8,
             param_5,lVar2,0);
  return;
}



===== WPP_SF_s @ 140011238 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_s(undefined8 param_1,undefined2 param_2,undefined8 param_3,char *param_4)

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
            (param_1,0x2b,&WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,param_2,param_4,lVar2,0);
  return;
}



===== WPP_SF_sqqs @ 1400112a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_sqqs(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,
                undefined1 param_5,undefined1 param_6,char *param_7)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  char *pcVar4;
  
  if (param_7 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_7[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  pcVar4 = param_7;
  if (param_7 == (char *)0x0) {
    pcVar4 = "NULL";
  }
  lVar2 = -1;
  if (param_4 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (param_4[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,0x1d,param_4,lVar1,
             &param_5,8,&param_6,8,pcVar4,lVar3,0);
  return;
}



===== WPP_SF_ss @ 14001136c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ss(undefined8 param_1,undefined8 param_2,undefined8 param_3,char *param_4,char *param_5)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  if (param_5 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    lVar2 = -1;
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (param_5[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (param_5 == (char *)0x0) {
    param_5 = "NULL";
  }
  lVar2 = -1;
  if (param_4 == (char *)0x0) {
    lVar1 = 5;
  }
  else {
    do {
      lVar1 = lVar2;
      lVar2 = lVar1 + 1;
    } while (param_4[lVar2] != '\0');
    lVar1 = lVar1 + 2;
  }
  if (param_4 == (char *)0x0) {
    param_4 = "NULL";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,0x1e,param_4,lVar1,
             param_5,lVar3,0);
  return;
}



===== WppClassicProviderCallback @ 140011410 =====

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



===== wil_details_FeatureDescriptors_SkipPadding @ 140011444 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_1400196ef < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 140011470 =====

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



===== wil_details_RecordFeatureUsageReporting @ 1400115d0 =====

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



===== McGenEventWrite_EtwWriteTransfer @ 140011654 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_14001a028;
  uVar2 = 0;
  if (DAT_14001a028 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_14001a028;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(USBSTOR_DIAG_TRACE_PROVIDER_Context,&EventLogoPerformanceMeasurement,param_3,0,
                   0xb,param_5);
  return;
}



===== McTemplateK0uuuuxqbr5upp_EtwWriteTransfer @ 1400116bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0uuuuxqbr5upp_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000058;
  undefined1 uStack0000000000000060;
  undefined1 uStack0000000000000068;
  undefined1 auStackY_118 [32];
  undefined1 local_e8 [8];
  undefined1 local_e0 [8];
  undefined1 local_d8 [16];
  undefined8 local_c8 [2];
  undefined1 *local_b8;
  undefined8 local_b0;
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  undefined1 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined4 local_4c;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_118;
  local_b0 = 1;
  local_b8 = local_e8;
  local_d8[0] = 0;
  local_a8 = local_e0;
  local_98 = local_d8;
  local_88 = &uStack0000000000000038;
  local_78 = &uStack0000000000000040;
  local_68 = &uStack0000000000000048;
  local_48 = &uStack0000000000000058;
  local_38 = &uStack0000000000000060;
  local_28 = &uStack0000000000000068;
  local_e0[0] = 0;
  local_e8[0] = 0;
  local_a0 = 1;
  local_90 = 1;
  local_80 = 1;
  local_70 = 8;
  local_60 = 4;
  local_4c = 0;
  local_40 = 1;
  local_30 = 8;
  local_20 = 8;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,0,local_c8);
  return;
}



===== USBSTOR_AllocBcStream @ 1400117c4 =====

int USBSTOR_AllocBcStream(longlong param_1,longlong param_2)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong *local_res8;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar4 = *(longlong *)(param_1 + 0x40);
  local_18 = 0;
  iVar2 = -0x3ffffff0;
  local_28 = 0;
  uStack_20 = 0;
  if (*(longlong *)(param_2 + 0xb8) == 0) {
    iVar2 = -0x3fffffff;
  }
  else {
    if (*(char *)(*(longlong *)(param_2 + 0xb8) + 1) == '\x04') {
      bVar1 = USBSTOR_IsAvioEnabledDevice(lVar4);
      if (bVar1) {
        local_res8 = (longlong *)0x0;
        KeAcquireInStackQueuedSpinLock(lVar4 + 0x290,&local_28);
        iVar2 = PortAvioAllocateBcStream
                          ((undefined8 *)(lVar4 + 0x270),lVar4 + 0x170,param_2,&local_res8);
        if (-1 < iVar2) {
          uVar3 = UsbQueueAllocateStream(lVar4 + 0x170,local_res8);
          iVar2 = (int)uVar3;
        }
        KeReleaseInStackQueuedSpinLock(&local_28);
      }
    }
    else {
      iVar2 = -0x3fffffde;
    }
    *(int *)(param_2 + 0x30) = iVar2;
    IofCompleteRequest(param_2,0);
  }
  return iVar2;
}



===== USBSTOR_AsyncNotifyInterruptPipeCompletion @ 1400118b0 =====

undefined8
USBSTOR_AsyncNotifyInterruptPipeCompletion(longlong param_1,longlong param_2,longlong param_3)

{
  int *piVar1;
  longlong lVar2;
  int *piVar3;
  longlong lVar4;
  undefined4 local_res8 [2];
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5c,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  USBSTOR_LogEntry(0x43494e41,param_1,param_2,(longlong)*(int *)(param_2 + 0x30));
  if (param_1 != 0) {
    param_3 = param_1;
  }
  piVar1 = *(int **)(param_3 + 0x40);
  if (*piVar1 == 0x214f4450) {
    piVar3 = *(int **)(*(longlong *)(piVar1 + 4) + 0x40);
    lVar4 = *(longlong *)(piVar1 + 4);
  }
  else {
    piVar3 = (int *)0x0;
    lVar4 = 0;
    if (*piVar1 == 0x214f4446) {
      piVar3 = piVar1;
      lVar4 = param_3;
    }
  }
  piVar3[0x20] = piVar3[0x20] & 0xffffff7f;
  if (((*(int *)(param_2 + 0x30) != -0x3ffffff2) && (*(int *)(param_2 + 0x30) != -0x3ffffee0)) &&
     (local_res8[0] = 0x49425355, 3 < (uint)piVar3[0x8d])) {
    lVar2 = RtlCompareMemory(*(undefined8 *)(piVar3 + 0x8e),local_res8,4);
    if (lVar2 == 4) {
      USBSTOR_QueueMediaChangeNotify(param_3,(longlong)piVar3);
      USBSTOR_QueueAsyncNotification(param_3,(longlong)piVar3);
    }
  }
  USBSTOR_LogEntry(0x63696e61,lVar4,param_2,0);
  IoReleaseRemoveLockEx(piVar3 + 0x1ca,param_2,0x20);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5d,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  return 0xc0000016;
}



===== USBSTOR_AsyncNotifyWorkItem @ 140011a30 =====

void USBSTOR_AsyncNotifyWorkItem(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  
  USBSTOR_LogEntry(0x49574e41,param_1,0,0);
  lVar1 = *(longlong *)(param_1 + 0x40);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8e,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  iVar2 = USBSTOR_IssueAsyncNotificationRequest(param_1);
  USBSTOR_LogEntry(0x69776e61,param_1,(longlong)iVar2,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8f,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  IoReleaseRemoveLockEx(lVar1 + 0x728,USBSTOR_AsyncNotifyWorkItem,0x20);
  return;
}



===== USBSTOR_CancelIo @ 140011b10 =====

void USBSTOR_CancelIo(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  undefined8 *puVar4;
  undefined *puVar5;
  
  if (*(longlong *)(param_1 + 0x20) == param_2) {
    IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
    USBSTOR_LogEntry(0x314e4143,param_1,param_2,0);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    }
  }
  else {
    cVar3 = KeRemoveEntryDeviceQueue(param_1 + 0xa0,param_2 + 0x78);
    if (cVar3 == '\0') {
      IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
    }
    else {
      IoReleaseCancelSpinLock();
      USBSTOR_LogEntry(0x324e4143,param_1,param_2,0);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,
                &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
      }
      *(undefined8 *)(param_2 + 0x38) = 0;
      puVar5 = (undefined *)0x0;
      lVar1 = *(longlong *)(param_2 + 0xb8);
      *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
      lVar2 = *(longlong *)(lVar1 + 8);
      *(undefined1 *)(lVar2 + 3) = 2;
      lVar1 = *(longlong *)(lVar1 + 0x10);
      USBSTOR_FxPowerReference(*(longlong *)(*(longlong *)(lVar1 + 0x10) + 0x40),lVar2,'\0');
      puVar4 = (undefined8 *)0x0;
      IofCompleteRequest(param_2);
      UsbStorPumpNextRequest(lVar1,puVar4,puVar5);
    }
  }
  return;
}



===== USBSTOR_DeviceBuildDumpDriverList @ 140011c6c =====

undefined8 * USBSTOR_DeviceBuildDumpDriverList(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 in_R9;
  
  puVar1 = (undefined8 *)ExAllocatePool2(0x40,0x48,0x706d64);
  if (puVar1 != (undefined8 *)0x0) {
    puVar2 = (undefined8 *)ExAllocatePool2(0x40,0x48,0x706d64);
    if (puVar2 == (undefined8 *)0x0) {
      ExFreePoolWithTag(puVar1,0);
      puVar1 = (undefined8 *)0x0;
    }
    else {
      RtlStringCbPrintfW((wchar_t *)(puVar1 + 1),0x1e,L"diskdump.sys",in_R9);
      RtlStringCbPrintfW((wchar_t *)((longlong)puVar1 + 0x26),0x1e,L"storport.sys",in_R9);
      *puVar1 = puVar2;
      RtlStringCbPrintfW((wchar_t *)(puVar2 + 1),0x1e,L"dmpusbstor.sys",in_R9);
      *puVar2 = 0;
    }
  }
  return puVar1;
}



===== USBSTOR_FreeBcStream @ 140011d30 =====

undefined4 USBSTOR_FreeBcStream(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  undefined4 uVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_18 = 0;
  uVar3 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (*(longlong *)(param_2 + 0xb8) == 0) {
    uVar3 = 0xc0000001;
  }
  else {
    if (*(char *)(*(longlong *)(param_2 + 0xb8) + 1) == '\x04') {
      KeAcquireInStackQueuedSpinLock(lVar1 + 0x290,&local_28);
      plVar2 = (longlong *)IoGetSfioStreamIdentifier(*(undefined8 *)(param_2 + 0xc0),lVar1 + 0x270);
      if (plVar2 != (longlong *)0x0) {
        UsbQueueFreeStream(lVar1 + 0x170,param_2,plVar2);
      }
      KeReleaseInStackQueuedSpinLock(&local_28);
    }
    else {
      uVar3 = 0xc0000022;
    }
    *(undefined4 *)(param_2 + 0x30) = uVar3;
    IofCompleteRequest(param_2,0);
  }
  return uVar3;
}



===== USBSTOR_IsAvioEnabledDevice @ 140011e00 =====

bool USBSTOR_IsAvioEnabledDevice(longlong param_1)

{
  if ((*(byte *)(param_1 + 0x48) & 0x1f) == 0) {
    return -1 < *(char *)(param_1 + 0x49);
  }
  return false;
}



===== USBSTOR_IssueAsyncNotificationRequest @ 140011e1c =====

int USBSTOR_IssueAsyncNotificationRequest(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  
  lVar5 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5a,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x40);
  if ((*(uint *)(lVar1 + 0x80) & 0x80) == 0) {
    lVar5 = *(longlong *)(lVar1 + 0x168);
    if (lVar5 == 0) {
      lVar5 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(lVar1 + 0x18) >> 8),
                                     *(undefined1 *)(*(longlong *)(lVar1 + 0x18) + 0x4c)),0);
      *(longlong *)(lVar1 + 0x168) = lVar5;
      if (lVar5 == 0) {
        iVar4 = -0x3fffff66;
        goto LAB_140011fbf;
      }
    }
    else {
      IoReuseIrp(lVar5,0xc0000001);
    }
    USBSTOR_LogEntry(0x544e4941,param_1,lVar5,0);
    iVar4 = IoAcquireRemoveLockEx(lVar1 + 0x728,lVar5,"",1,0x20);
    if (-1 < iVar4) {
      memset((void *)(lVar1 + 0x212),0,0x7e);
      *(undefined4 *)(lVar1 + 0x210) = 0x90080;
      uVar2 = *(undefined8 *)(*(longlong *)(lVar1 + 0x70) + 8);
      *(undefined8 *)(lVar1 + 0x240) = 0;
      *(undefined8 *)(lVar1 + 0x228) = uVar2;
      *(longlong *)(lVar1 + 0x238) = lVar1 + 0x290;
      *(undefined4 *)(lVar1 + 0x230) = 3;
      *(undefined4 *)(lVar1 + 0x234) = 0x200;
      lVar3 = *(longlong *)(lVar5 + 0xb8);
      *(undefined4 **)(lVar3 + -0x40) = (undefined4 *)(lVar1 + 0x210);
      *(undefined1 *)(lVar3 + -0x48) = 0xf;
      *(undefined4 *)(lVar3 + -0x30) = 0x220003;
      *(undefined8 *)(lVar3 + -0x20) = *(undefined8 *)(lVar1 + 0x18);
      *(uint *)(lVar1 + 0x80) = *(uint *)(lVar1 + 0x80) | 0x80;
      iVar4 = IoSetCompletionRoutineEx
                        (param_1,lVar5,USBSTOR_AsyncNotifyInterruptPipeCompletion,param_1,1,1,1);
      if (iVar4 < 0) {
        lVar3 = *(longlong *)(lVar5 + 0xb8);
        *(code **)(lVar3 + -0x10) = USBSTOR_AsyncNotifyInterruptPipeCompletion;
        *(longlong *)(lVar3 + -8) = param_1;
        *(undefined1 *)(lVar3 + -0x45) = 0xe0;
      }
      iVar4 = IofCallDriver(*(undefined8 *)(lVar1 + 0x18),lVar5);
    }
  }
  else {
    iVar4 = -0x3fffffff;
  }
LAB_140011fbf:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5b,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar4);
  }
  USBSTOR_LogEntry(0x746e6961,param_1,lVar5,(longlong)iVar4);
  return iVar4;
}



===== USBSTOR_IssueRequestSenseBulkRequest @ 140012058 =====

void USBSTOR_IssueRequestSenseBulkRequest(longlong param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  uint uVar3;
  longlong lVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar4 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  uVar2 = *(undefined8 *)(*(longlong *)(lVar1 + 0x60) + 8);
  if (param_3 == 0) {
    uVar3 = (uint)*(byte *)(lVar4 + 0xb);
    lVar4 = *(longlong *)(lVar4 + 0x20);
  }
  else {
    uVar3 = 0x12;
    lVar4 = lVar1 + 0x4b6;
  }
  *(undefined8 *)(lVar1 + 0x4b6) = 0;
  *(undefined8 *)(lVar1 + 0x4be) = 0;
  *(undefined2 *)(lVar1 + 0x4c6) = 0;
  USBSTOR_IssueBulkOrInterruptRequest
            (param_1,param_2,uVar2,2,uVar3,lVar4,0,USBSTOR_SenseDataCompletionRoutine,param_3);
  return;
}



===== USBSTOR_IssueRequestSenseCdb @ 1400120e4 =====

int USBSTOR_IssueRequestSenseCdb(longlong param_1,longlong param_2,longlong param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  int iVar5;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x73,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  lVar2 = *(longlong *)(param_1 + 0x40);
  puVar1 = (undefined8 *)(lVar2 + 0x4aa);
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  *puVar1 = 0;
  *(undefined4 *)(lVar2 + 0x4b2) = 0;
  *(undefined1 *)puVar1 = 3;
  if (param_3 == 0) {
    uVar4 = *(undefined1 *)(lVar3 + 0xb);
  }
  else {
    uVar4 = 0x12;
  }
  *(undefined1 *)(lVar2 + 0x4ae) = uVar4;
  iVar5 = USBSTOR_IssueControlRequest
                    (param_1,param_2,0xc,puVar1,USBSTOR_RequestSenseCdbCompletion,param_3);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x74,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar5);
  }
  return iVar5;
}



===== USBSTOR_MediaChangeNotifyWorkItem @ 1400121e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void USBSTOR_MediaChangeNotifyWorkItem(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  int iVar4;
  undefined8 *puVar5;
  longlong lVar6;
  longlong lVar7;
  undefined4 uVar8;
  byte bVar9;
  undefined8 *puVar10;
  ulonglong uVar11;
  undefined1 auStack_88 [32];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  ulonglong uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_88;
  local_48 = 0;
  puVar10 = (undefined8 *)0x0;
  local_40 = 0;
  uStack_38 = 0;
  iVar4 = -0x3ffffff3;
  local_58 = 0;
  uStack_50 = 0;
  USBSTOR_LogEntry(0x574e434d,param_1,0,0);
  lVar1 = *(longlong *)(param_1 + 0x40);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x89,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  if ((*(uint *)(lVar1 + 0x84) & 0x800) == 0) {
    bVar9 = *(byte *)(lVar1 + 0x295);
    if ((bVar9 & 0xf0) != 0x10) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8a,
                 &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,(uint)(bVar9 >> 4));
      }
      uVar8 = 0x304e434d;
      bVar9 = *(byte *)(lVar1 + 0x295) >> 4;
      goto LAB_1400122e8;
    }
    bVar9 = bVar9 & 0xf;
    if (bVar9 <= *(byte *)(lVar1 + 0x748)) goto LAB_14001228b;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8b,
                &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,(uint)bVar9,
                *(byte *)(lVar1 + 0x748));
    }
    uVar11 = (ulonglong)*(byte *)(lVar1 + 0x748);
    uVar8 = 0x314e434d;
  }
  else {
    bVar9 = 0;
LAB_14001228b:
    for (puVar5 = *(undefined8 **)(lVar1 + 0x20); puVar5 != (undefined8 *)(lVar1 + 0x20);
        puVar5 = (undefined8 *)*puVar5) {
      puVar10 = puVar5 + -3;
      if (bVar9 == *(byte *)((longlong)puVar5 + 0x2f)) goto LAB_14001239f;
    }
    if (bVar9 == *(byte *)((longlong)puVar10 + 0x47)) {
LAB_14001239f:
      uStack_38 = uStack_38 | 1;
      local_40 = 0x1000000001;
      lVar6 = IoGetAttachedDeviceReference(puVar10[1]);
      lVar7 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(lVar1 + 0x18) >> 8),
                                     *(undefined1 *)(*(longlong *)(lVar1 + 0x18) + 0x4c)),0);
      iVar4 = -0x3ffffff3;
      if (lVar7 != 0) {
        KeInitializeEvent(&local_58,1);
        lVar2 = *(longlong *)(lVar7 + 0xb8);
        *(undefined1 *)(lVar2 + -0x48) = 0xe;
        uVar3 = puVar10[1];
        *(undefined4 *)(lVar2 + -0x40) = 0;
        *(undefined8 *)(lVar2 + -0x20) = uVar3;
        *(undefined4 *)(lVar2 + -0x30) = 0x2d1c90;
        *(undefined4 *)(lVar2 + -0x38) = 0x10;
        *(undefined8 **)(lVar7 + 0x18) = &local_40;
        lVar2 = *(longlong *)(lVar7 + 0xb8);
        *(code **)(lVar2 + -0x10) = USBSTOR_SyncCompletionRoutine;
        *(undefined8 **)(lVar2 + -8) = &local_58;
        *(undefined1 *)(lVar2 + -0x45) = 0xe0;
        iVar4 = IofCallDriver(lVar6,lVar7);
        if (iVar4 == 0x103) {
          KeWaitForSingleObject(&local_58,0,0);
        }
      }
      if (lVar6 != 0) {
        ObfDereferenceObject(lVar6);
      }
      if (lVar7 != 0) {
        IoFreeIrp(lVar7);
      }
      goto LAB_1400124b1;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8c,
               &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,(uint)bVar9);
    }
    uVar8 = 0x324e434d;
LAB_1400122e8:
    uVar11 = 0;
  }
  USBSTOR_LogEntry(uVar8,param_1,(ulonglong)bVar9,uVar11);
LAB_1400124b1:
  USBSTOR_LogEntry(0x776e636d,param_1,(longlong)iVar4,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8d,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  IoReleaseRemoveLockEx(lVar1 + 0x728,USBSTOR_MediaChangeNotifyWorkItem,0x20);
  return;
}



===== USBSTOR_QueueAsyncNotification @ 140012544 =====

void USBSTOR_QueueAsyncNotification(undefined8 param_1,longlong param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 in_stack_ffffffffffffffe8;
  undefined4 uVar3;
  
  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffffe8 >> 0x20);
  USBSTOR_LogEntry(0x494e4151,param_1,0,0);
  uVar2 = 1;
  iVar1 = IoAcquireRemoveLockEx
                    (param_2 + 0x728,USBSTOR_AsyncNotifyWorkItem,"",1,CONCAT44(uVar3,0x20));
  if ((-1 < iVar1) && (-1 < (char)*(undefined4 *)(param_2 + 0x80))) {
    USBSTOR_QueueWorkItem
              (param_1,*(longlong *)(param_2 + 0x178),USBSTOR_AsyncNotifyWorkItem,uVar2,param_2,
               *(char *)(param_2 + 0x754) == '\0');
  }
  return;
}



===== USBSTOR_QueueMediaChangeNotify @ 1400125e0 =====

void USBSTOR_QueueMediaChangeNotify(undefined8 param_1,longlong param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 in_stack_ffffffffffffffe8;
  undefined4 uVar3;
  
  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffffe8 >> 0x20);
  USBSTOR_LogEntry(0x494e4151,param_1,0,0);
  uVar2 = 1;
  iVar1 = IoAcquireRemoveLockEx
                    (param_2 + 0x728,USBSTOR_MediaChangeNotifyWorkItem,"",1,CONCAT44(uVar3,0x20));
  if (-1 < iVar1) {
    USBSTOR_QueueWorkItem
              (param_1,*(longlong *)(param_2 + 0x180),USBSTOR_MediaChangeNotifyWorkItem,uVar2,
               param_2,*(char *)(param_2 + 0x754) == '\0');
  }
  return;
}



===== USBSTOR_QueueResetPipe @ 140012674 =====

void USBSTOR_QueueResetPipe(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 in_stack_ffffffffffffffe8;
  undefined4 uVar4;
  
  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffffe8 >> 0x20);
  USBSTOR_LogEntry(0x50535251,param_1,0,0);
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar3 = 1;
  iVar2 = IoAcquireRemoveLockEx(lVar1 + 0x728,USBSTOR_ResetPipeWorkItem,"",1,CONCAT44(uVar4,0x20));
  if (-1 < iVar2) {
    USBSTOR_QueueWorkItem
              (param_1,*(longlong *)(lVar1 + 0x170),USBSTOR_ResetPipeWorkItem,uVar3,param_2,
               *(char *)(lVar1 + 0x754) == '\0');
  }
  return;
}



===== USBSTOR_RequestSenseCdbCompletion @ 140012720 =====

undefined4 USBSTOR_RequestSenseCdbCompletion(longlong param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  int *piVar2;
  longlong lVar3;
  bool bVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  longlong lVar8;
  undefined4 local_res8 [2];
  
  piVar6 = (int *)0x0;
  local_res8[0] = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x75,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  USBSTOR_LogEntry(0x43435352,param_1,param_2,(longlong)*(int *)(param_2 + 0x30));
  piVar2 = *(int **)(param_1 + 0x40);
  if (*piVar2 == 0x214f4450) {
    piVar6 = piVar2;
    piVar7 = *(int **)(*(longlong *)(piVar2 + 4) + 0x40);
    lVar8 = *(longlong *)(piVar2 + 4);
  }
  else {
    piVar7 = (int *)0x0;
    lVar8 = 0;
    if (*piVar2 == 0x214f4446) {
      piVar7 = piVar2;
      lVar8 = param_1;
    }
  }
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  bVar4 = USBSTOR_CheckRequestTimeOut(lVar8,param_2,lVar3,local_res8);
  if (bVar4) {
    USBSTOR_LogEntry(0x31637372,lVar8,param_2,lVar3);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x76,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    }
  }
  else {
    iVar1 = *(int *)(param_2 + 0x30);
    if (iVar1 < 0) {
      USBSTOR_LogEntry(0x32637372,(longlong)iVar1,(longlong)piVar7[99],0);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x77,
                  &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,*(undefined4 *)(param_2 + 0x30),
                  (char)piVar7[99]);
      }
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(undefined4 *)(param_2 + 0x30) = 0xc0000185;
      *(undefined1 *)(lVar3 + 3) = 0xe;
      USBSTOR_TranslateCDBComplete(lVar8,param_2,lVar3);
      USBSTOR_QueueResetDevice(lVar8,piVar6);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x78,
                &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
      }
      local_res8[0] = 0xc0000185;
    }
    else {
      USBSTOR_LogEntry(0x33637372,(longlong)iVar1,(longlong)piVar7[99],0);
      uVar5 = USBSTOR_IssueRequestSenseBulkRequest(lVar8,param_2,param_3);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x79,
                 &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,uVar5);
      }
      local_res8[0] = 0xc0000016;
    }
  }
  return local_res8[0];
}



===== USBSTOR_ResetPipeWorkItem @ 140012960 =====

void USBSTOR_ResetPipeWorkItem(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined *puVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  puVar4 = (undefined *)0x0;
  USBSTOR_LogEntry(0x57505352,param_1,0,0);
  lVar2 = *(longlong *)(param_1 + 0x40);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar4 = &WPP_e947f7dfdc8330b398201c2535585168_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x87,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  USBSTOR_ResetPipe(param_1,*(undefined8 *)(*(longlong *)(lVar2 + 0x60) + 8));
  USBSTOR_ResetPipe(param_1,*(undefined8 *)(*(longlong *)(lVar2 + 0x68) + 8));
  puVar3 = &local_28;
  KeAcquireInStackQueuedSpinLock(lVar2 + 0x90);
  uVar1 = *(uint *)(lVar2 + 0x80);
  KeReleaseInStackQueuedSpinLock(&local_28);
  if ((uVar1 & 4) == 0) {
    USBSTOR_IssueRequestSenseCdb(param_1,*(longlong *)(param_1 + 0x20),0);
  }
  else {
    if (param_2 != 0) {
      UsbStorPumpNextRequest(param_2,puVar3,puVar4);
    }
    UsbStorStartNextPacket(param_1);
  }
  USBSTOR_LogEntry(0x77707372,param_1,0,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x88,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  IoReleaseRemoveLockEx(lVar2 + 0x728,USBSTOR_ResetPipeWorkItem,0x20);
  return;
}



===== USBSTOR_SetModeSenseDataProtect @ 140012ad8 =====

void USBSTOR_SetModeSenseDataProtect(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte bVar1;
  longlong lVar2;
  undefined4 *puVar3;
  
  *(uint *)(param_3 + 0xc) = *(uint *)(param_3 + 0xc) & 0xfeffffff;
  lVar2 = *(longlong *)(param_2 + 8);
  if ((*(byte *)(lVar2 + 10) & 5) == 0) {
    puVar3 = (undefined4 *)MmMapLockedPagesSpecifyCache(lVar2,0,1,0,0,0x40000020);
  }
  else {
    puVar3 = *(undefined4 **)(lVar2 + 0x18);
  }
  if (puVar3 != (undefined4 *)0x0) {
    *(byte *)((longlong)puVar3 + 2) = *(byte *)((longlong)puVar3 + 2) | 0x80;
    bVar1 = *(byte *)(param_3 + 3);
    if ((((bVar1 != 1) && ((bVar1 & 0x40) == 0)) && ((bVar1 & 0x3f) != 0x12)) &&
       ((*(char *)(param_3 + 4) == '\0' || ((char)bVar1 < '\0')))) {
      *puVar3 = 0x800003;
      *(undefined2 *)(param_3 + 3) = 1;
      *(undefined4 *)(param_3 + 0x10) = 4;
    }
  }
  return;
}



===== WPP_SF_DDqq @ 140012b68 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDqq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_e947f7dfdc8330b398201c2535585168_Traceguids,0x33,local_res20,4,
             &param_5,4,&param_6,8,&param_7,8,0);
  return;
}



===== WPP_SF_dDD @ 140012bdc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_e947f7dfdc8330b398201c2535585168_Traceguids,0xb9,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_dDDdd @ 140012c40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dDDdd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_e947f7dfdc8330b398201c2535585168_Traceguids,0xc3,local_res20,4,
             &param_5,4,&param_6,4,&param_7,4,&param_8,4,0);
  return;
}



===== WPP_SF_i @ 140012cc4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_i(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_e947f7dfdc8330b398201c2535585168_Traceguids,200,&local_res20,8,0);
  return;
}



===== PnPMinorFunctionString @ 140012d10 =====

char * PnPMinorFunctionString(byte param_1)

{
  if (param_1 < 0xc) {
    if (param_1 == 0xb) {
      return "IRP_MN_QUERY_RESOURCE_REQUIREMENTS";
    }
    if (param_1 < 6) {
      if (param_1 == 5) {
        return "IRP_MN_QUERY_STOP_DEVICE";
      }
      if (param_1 == 0) {
        return "IRP_MN_START_DEVICE";
      }
      if (param_1 == 1) {
        return "IRP_MN_QUERY_REMOVE_DEVICE";
      }
      if (param_1 == 2) {
        return "IRP_MN_REMOVE_DEVICE";
      }
      if (param_1 == 3) {
        return "IRP_MN_CANCEL_REMOVE_DEVICE";
      }
      if (param_1 == 4) {
        return "IRP_MN_STOP_DEVICE";
      }
    }
    else {
      if (param_1 == 6) {
        return "IRP_MN_CANCEL_STOP_DEVICE";
      }
      if (param_1 == 7) {
        return "IRP_MN_QUERY_DEVICE_RELATIONS";
      }
      if (param_1 == 8) {
        return "IRP_MN_QUERY_INTERFACE";
      }
      if (param_1 == 9) {
        return "IRP_MN_QUERY_CAPABILITIES";
      }
      if (param_1 == 10) {
        return "IRP_MN_QUERY_RESOURCES";
      }
    }
  }
  else if (param_1 < 0x13) {
    if (param_1 == 0x12) {
      return "IRP_MN_SET_LOCK";
    }
    if (param_1 == 0xc) {
      return "IRP_MN_QUERY_DEVICE_TEXT";
    }
    if (param_1 == 0xd) {
      return "IRP_MN_FILTER_RESOURCE_REQUIREMENTS";
    }
    if (param_1 == 0xf) {
      return "IRP_MN_READ_CONFIG";
    }
    if (param_1 == 0x10) {
      return "IRP_MN_WRITE_CONFIG";
    }
    if (param_1 == 0x11) {
      return "IRP_MN_EJECT";
    }
  }
  else {
    if (param_1 == 0x13) {
      return "IRP_MN_QUERY_ID";
    }
    if (param_1 == 0x14) {
      return "IRP_MN_QUERY_PNP_DEVICE_STATE";
    }
    if (param_1 == 0x15) {
      return "IRP_MN_QUERY_BUS_INFORMATION";
    }
    if (param_1 == 0x16) {
      return "IRP_MN_DEVICE_USAGE_NOTIFICATION";
    }
    if (param_1 == 0x17) {
      return "IRP_MN_SURPRISE_REMOVAL";
    }
  }
  return "IRP_MN_?????";
}



===== PowerMinorFunctionString @ 140012e7c =====

char * PowerMinorFunctionString(char param_1)

{
  if (param_1 == '\0') {
    return "IRP_MN_WAIT_WAKE";
  }
  if (param_1 == '\x01') {
    return "IRP_MN_POWER_SEQUENCE";
  }
  if (param_1 == '\x02') {
    return "IRP_MN_SET_POWER";
  }
  if (param_1 == '\x03') {
    return "IRP_MN_QUERY_POWER";
  }
  return "IRP_MN_?????";
}



===== PowerSystemStateString @ 140012ec8 =====

char * PowerSystemStateString(int param_1)

{
  if (param_1 == 0) {
    return "PowerSystemUnspecified";
  }
  if (param_1 == 1) {
    return "PowerSystemWorking";
  }
  if (param_1 == 2) {
    return "PowerSystemSleeping1";
  }
  if (param_1 == 3) {
    return "PowerSystemSleeping2";
  }
  if (param_1 == 4) {
    return "PowerSystemSleeping3";
  }
  if (param_1 == 5) {
    return "PowerSystemHibernate";
  }
  if (param_1 == 6) {
    return "PowerSystemShutdown";
  }
  if (param_1 == 7) {
    return "PowerSystemMaximum";
  }
  return "PowerSystem?????";
}



===== Feature_3194461498__private_IsEnabledDeviceUsageNoInline @ 140012f48 =====

ulonglong Feature_3194461498__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_3194461498__private_featureState;
  if ((Feature_3194461498__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3194461498__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3194461498__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3194461498__private_IsEnabledFallback @ 140012f80 =====

void Feature_3194461498__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 140012f98 =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 140013070 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 140013154 =====

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
LAB_1400132ac:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_14001329f:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_1400132ac;
      if (uVar5 == 5) goto LAB_14001329f;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 1400132d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (undefined8 param_1,undefined8 param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  uint uVar4;
  uint local_res18 [4];
  
  uVar4 = (uint)param_2 & 1;
  uVar3 = (ulonglong)param_3;
  local_res18[0] = param_3;
  uVar2 = wil_details_MapReportingKind(param_3,uVar4);
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,(ulonglong)uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x3bbc7f1,&Feature_3194461498_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140013350 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (undefined8 param_1,undefined8 param_2,ulonglong param_3)

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
                     (local_50,(uint *)&Feature_3194461498__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (0x3bbc7f1,param_3 & 0xffffffff,1,&Feature_3194461498__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),0x3bbc7f1);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 14001343c =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 14001354c =====

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
  if ((Feature_3194461498__private_featureState & 2) != 0) {
    uVar1 = Feature_3194461498__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_3194461498__private_featureState;
      if (bVar3) {
        Feature_3194461498__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_3194461498__private_featureState;
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



===== wil_details_GetCurrentFeatureEnabledState @ 1400135a0 =====

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



===== wil_details_IsEnabledFallback @ 140013700 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_3194461498__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_3194461498__private_featureState,(ulonglong)param_1,
                             0x1400196b8);
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



===== wil_details_MapReportingKind @ 140013790 =====

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



===== USBSTOR_InitializeEmergencyWorkerThread @ 140013830 =====

int USBSTOR_InitializeEmergencyWorkerThread(void)

{
  int iVar1;
  undefined8 local_res8;
  longlong local_res10;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong uStack_10;
  
  iVar1 = 0;
  local_18 = 0;
  local_res8 = 0;
  uStack_10 = uStack_10 & 0xffffffff00000000;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeWaitForSingleObject(&EmergencyWorkerThreadEvent,0,0,0,0);
  if (EmergencyWorkerThread == 0) {
    KeInitializeQueue(&EmergencyWorkQueue,0);
    uStack_30 = 0;
    local_28 = 0;
    local_38 = CONCAT44(local_38._4_4_,0x30);
    uStack_20 = CONCAT44(uStack_20._4_4_,0x200);
    local_18 = 0;
    uStack_10 = 0;
    iVar1 = PsCreateSystemThread(&local_res8,0,&local_38,0,0,USBSTOR_WorkerStart,0);
    if (-1 < iVar1) {
      local_res10 = 0;
      iVar1 = ObReferenceObjectByHandle(local_res8,0x1fffff,0,0,&local_res10,0);
      EmergencyWorkerThread = local_res10;
      ZwClose(local_res8);
    }
  }
  KeSetEvent(&EmergencyWorkerThreadEvent,0,0);
  return iVar1;
}



===== USBSTOR_WorkerStart @ 140013970 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void USBSTOR_WorkerStart(void)

{
  undefined8 uVar1;
  code *pcVar2;
  undefined8 *puVar3;
  
  do {
    do {
      puVar3 = (undefined8 *)KeRemoveQueue(&EmergencyWorkQueue,0,0);
    } while (puVar3 == (undefined8 *)0x80);
    uVar1 = puVar3[3];
    pcVar2 = (code *)puVar3[2];
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    IoInitializeWorkItem(uVar1,puVar3);
    (*pcVar2)(uVar1);
    ObfDereferenceObject(uVar1);
  } while( true );
}



===== UsbCancelIo @ 140013a00 =====

void UsbCancelIo(longlong param_1,longlong param_2)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
            &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
  }
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  UsbQueueRemoveIrp(*(longlong *)(param_1 + 0x40) + 0x170,param_2);
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  IofCompleteRequest(param_2,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
            &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
  }
  return;
}



===== UsbQueueAllocateStream @ 140013ad0 =====

undefined8 UsbQueueAllocateStream(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
            &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
  }
  uVar4 = 0xc000009a;
  if (*(uint *)(param_2 + 2) <= (uint)(*(int *)(param_1 + 0x114) - *(int *)(param_1 + 0x11c))) {
    *(uint *)(param_1 + 0x11c) = *(int *)(param_1 + 0x11c) + *(uint *)(param_2 + 2);
    plVar2 = param_2 + 10;
    plVar1 = *(longlong **)(param_1 + 0x108);
    if (*plVar1 == param_1 + 0x100) {
      *plVar2 = param_1 + 0x100;
      uVar4 = 0;
      param_2[0xb] = (longlong)plVar1;
      *plVar1 = (longlong)plVar2;
      *(longlong **)(param_1 + 0x108) = plVar2;
      *(int *)(param_1 + 0x110) = *(int *)(param_1 + 0x110) + 1;
      plVar2 = *(longlong **)(param_1 + 0x18);
      if (*plVar2 == param_1 + 0x10) {
        *param_2 = param_1 + 0x10;
        param_2[1] = (longlong)plVar2;
        *plVar2 = (longlong)param_2;
        *(longlong **)(param_1 + 0x18) = param_2;
        goto LAB_140013b7e;
      }
    }
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    pcVar3 = (code *)swi(3);
    uVar4 = (*pcVar3)();
    return uVar4;
  }
LAB_140013b7e:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
             &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids,(int)uVar4);
  }
  return uVar4;
}



===== UsbQueueRemoveIrp @ 140013bd8 =====

byte UsbQueueRemoveIrp(longlong param_1,longlong param_2)

{
  byte bVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
            &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
  }
  KeAcquireInStackQueuedSpinLock(param_1 + 0x120,&local_28);
  bVar1 = UsbRemoveIrp(param_1,param_2);
  KeReleaseInStackQueuedSpinLock(&local_28);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
             &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids,(uint)bVar1);
  }
  return bVar1;
}



===== USBDInternal_QueryUsbVerifierSettings @ 140013cb4 =====

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
    if (-1 < (int)uVar4) goto LAB_140013d93;
  }
  else {
    iVar3 = (*pcVar5)(*(undefined8 *)(param_1 + 8),0,1,0,&local_res10);
    lVar8 = 0;
    if (iVar3 < 0) {
      if (g_EnableDbgPrints != '\0') {
        DbgPrintEx(0x4d,0,"IoOpenDriverRegistryKey failed with 0x%x\n",iVar3);
      }
      goto LAB_140013ff3;
    }
LAB_140013d93:
    _Dst = (undefined8 *)ExAllocatePoolWithTag(DAT_14001a200,0x1c0,0x53414d55);
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
      ExFreePoolWithTag(_Dst,0x53414d55);
    }
  }
  if (lVar8 != 0) {
    ExFreePoolWithTag(lVar8,0x53414d55);
  }
LAB_140013ff3:
  if (local_res10 != 0) {
    ZwClose();
  }
  return;
}



===== PortAvioAllocateBcStream @ 140014028 =====

int PortAvioAllocateBcStream
              (undefined8 *param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  longlong lVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined8 *puVar5;
  void *pvVar6;
  void *local_res18 [2];
  
  pvVar6 = (void *)0x0;
  local_res18[0] = (void *)0x0;
  if (((0x17 < *(uint *)(*(longlong *)(param_3 + 0xb8) + 0x10)) &&
      (0xf < *(uint *)(*(longlong *)(param_3 + 0xb8) + 8))) &&
     (piVar2 = *(int **)(param_3 + 0x18), *piVar2 == 1)) {
    if ((*(uint *)(param_1 + 3) <= (uint)piVar2[2]) &&
       (iVar3 = (int)((ulonglong)(uint)piVar2[1] /
                     ((ulonglong)(uint)piVar2[2] / (ulonglong)*(uint *)(param_1 + 3))), iVar3 != 0))
    {
      iVar4 = IoAllocateSfioStreamIdentifier
                        (*(undefined8 *)(param_3 + 0xc0),0x68,param_1,local_res18);
      if (iVar4 == -0x3fffffdf) {
        local_res18[0] = (void *)IoGetSfioStreamIdentifier(*(undefined8 *)(param_3 + 0xc0));
        iVar4 = 0;
      }
      else {
        pvVar6 = local_res18[0];
        if (iVar4 < 0) goto LAB_140014171;
      }
      pvVar6 = local_res18[0];
      for (puVar5 = (undefined8 *)*param_1; puVar5 != param_1; puVar5 = (undefined8 *)*puVar5) {
        if (puVar5 == (undefined8 *)((longlong)local_res18[0] + 0x50)) {
          iVar4 = -0x3fffffdf;
          goto LAB_140014171;
        }
      }
      memset(local_res18[0],0,0x68);
      lVar1 = (longlong)pvVar6 + 0x18;
      *(longlong *)((longlong)pvVar6 + 0x20) = lVar1;
      *(longlong *)lVar1 = lVar1;
      *(undefined8 *)((longlong)pvVar6 + 0x40) = 0;
      *(undefined4 *)((longlong)pvVar6 + 0x48) = 0;
      *(longlong *)((longlong)pvVar6 + 0x28) = lVar1;
      *(undefined8 *)((longlong)pvVar6 + 0x38) = param_2;
      *(undefined4 *)((longlong)pvVar6 + 0x48) = 1;
      *(int *)((longlong)pvVar6 + 0x10) = iVar3;
      puVar5 = *(undefined8 **)(param_3 + 0x18);
      *puVar5 = 0x10000;
      *(int *)(puVar5 + 1) = *(int *)((longlong)local_res18[0] + 0x10) * 2;
      *(undefined8 *)(param_3 + 0x38) = 0x10;
      pvVar6 = local_res18[0];
      goto LAB_140014171;
    }
  }
  iVar4 = -0x3ffffff3;
LAB_140014171:
  *param_4 = pvVar6;
  return iVar4;
}



===== WPP_SF_qDD @ 140014194 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_256a4584ee4438b757ec1546b7dd7507_Traceguids,0x11,&local_res20,8,
             &param_5,4,&param_6,4,0);
  return;
}



===== __GSHandlerCheck @ 140014208 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14001422c =====

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



===== __GSHandlerCheck_SEH @ 140014294 =====

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



===== __cpu_features_init @ 140014330 =====

/* WARNING: Removing unreachable block (ram,0x00014001439a) */
/* WARNING: Removing unreachable block (ram,0x000140014349) */
/* WARNING: Removing unreachable block (ram,0x00014001433a) */

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



===== __security_check_cookie @ 140014400 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140014440 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140014470 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140014470. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1400144a0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140014500 =====

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



===== memset @ 140014800 =====

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



===== __memset_repmovs @ 140014940 =====

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



===== __memset_query @ 1400149c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140014a40 =====

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



===== __memset_spec_ermsb_repmovsb @ 140014b80 =====

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



===== __memset_spec_plain @ 140014c00 =====

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



===== USBSTOR_PdoQueryStopRemoveDevice @ 14001f008 =====

uint USBSTOR_PdoQueryStopRemoveDevice(longlong param_1,longlong param_2)

{
  uint uVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x97,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  USBSTOR_LogEntry(0x44535150,param_1,param_2,0);
  uVar1 = ~-(uint)((*(uint *)(param_1 + 0x30) & 0x2000) != 0) & 0xc0000001;
  *(uint *)(param_2 + 0x30) = uVar1;
  IofCompleteRequest(param_2,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x98,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,uVar1);
  }
  USBSTOR_LogEntry(0x64737170,(longlong)(int)uVar1,0,0);
  return uVar1;
}



===== USBSTOR_WmiRegister @ 14001f0ec =====

void USBSTOR_WmiRegister(longlong param_1)

{
  int iVar1;
  
  *(undefined8 *)(param_1 + 0x7e0) = 0;
  *(undefined8 *)(param_1 + 0x7e8) = 0;
  *(undefined8 *)(param_1 + 0x7f0) = 0;
  *(undefined **)(param_1 + 0x7c0) = &USBSTOR_WmiGuidList;
  *(code **)(param_1 + 0x7c8) = USBSTOR_QueryWmiRegInfo;
  *(code **)(param_1 + 2000) = USBSTOR_QueryWmiDataBlock;
  *(code **)(param_1 + 0x7d8) = USBSTOR_SetWmiDataBlock;
  *(undefined4 *)(param_1 + 0x7b8) = 2;
  iVar1 = IoWMIRegistrationControl(*(undefined8 *)(param_1 + 8),1);
  if (-1 < iVar1) {
    *(undefined1 *)(param_1 + 0x7f8) = 1;
  }
  return;
}



===== USBSTOR_WmiDeregister @ 14001f17c =====

void USBSTOR_WmiDeregister(longlong param_1)

{
  if (*(char *)(param_1 + 0x7f8) != '\0') {
    IoWMIRegistrationControl(*(undefined8 *)(param_1 + 8),2);
    *(undefined1 *)(param_1 + 0x7f8) = 0;
  }
  return;
}



===== USBSTOR_PdoQueryCompatibleIds @ 14001f1b8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int USBSTOR_PdoQueryCompatibleIds(longlong param_1,ulonglong *param_2)

{
  longlong lVar1;
  int iVar2;
  char *pcVar3;
  undefined1 auStack_88 [32];
  char *local_68;
  char *local_60;
  char *local_58;
  char *local_50;
  undefined8 uStack_48;
  char local_40 [32];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_88;
  local_68 = local_40;
  local_60 = "USBSTOR\\RAW";
  local_50 = (char *)0x0;
  uStack_48 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x88,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x40);
  pcVar3 = USBSTOR_PdoDeviceTypeString(param_1);
  RtlStringCbPrintfA(local_40,0x1e,"USBSTOR\\%s",pcVar3);
  if (*(char *)(lVar1 + 0x46) == '\0') {
    local_58 = USBSTOR_PdoGenericTypeString(param_1);
  }
  else {
    local_58 = "Disk1667";
    local_50 = USBSTOR_PdoGenericTypeString(param_1);
  }
  iVar2 = USBSTOR_StringArrayToMultiSz(param_2,(longlong *)&local_68);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x89,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar2);
  }
  return iVar2;
}



===== USBSTOR_PdoGenericTypeString @ 14001f2e4 =====

char * USBSTOR_PdoGenericTypeString(longlong param_1)

{
  byte bVar1;
  char *pcVar2;
  byte bVar3;
  
  bVar1 = *(byte *)(*(longlong *)(param_1 + 0x40) + 0x48);
  bVar3 = bVar1 & 0x1f;
  if ((bVar1 & 0x1f) == 0) {
    pcVar2 = "GenSFloppy";
    if (*(char *)(*(longlong *)(param_1 + 0x40) + 0x45) == '\0') {
      pcVar2 = "GenDisk";
    }
    return pcVar2;
  }
  if (bVar3 == 1) {
    return "GenSequential";
  }
  if (bVar3 == 4) {
    return "GenWorm";
  }
  if (bVar3 == 5) {
    return "GenCdRom";
  }
  if (bVar3 == 7) {
    return "GenOptical";
  }
  if (bVar3 == 8) {
    return "GenChanger";
  }
  return "UsbstorOther";
}



===== WppLoadTracingSupport @ 14001f360 =====

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



===== USBSTOR_GetPipes @ 14001f4a4 =====

int USBSTOR_GetPipes(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  int iVar6;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0)) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x53,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  USBSTOR_LogEntry(0x50495047,param_1,0,0);
  lVar2 = *(longlong *)(param_1 + 0x40);
  uVar5 = 0;
  lVar3 = *(longlong *)(lVar2 + 0x58);
  *(undefined8 *)(lVar2 + 0x60) = 0;
  *(undefined8 *)(lVar2 + 0x68) = 0;
  *(undefined8 *)(lVar2 + 0x70) = 0;
  if (*(int *)(lVar3 + 0x10) != 0) {
    do {
      lVar1 = lVar3 + (uVar5 + 1) * 0x18;
      if (*(int *)(lVar1 + 4) == 2) {
        if (*(char *)(lVar1 + 2) < '\0') {
          if (*(longlong *)(lVar2 + 0x60) == 0) {
            *(longlong *)(lVar2 + 0x60) = lVar1;
          }
        }
        else if (*(longlong *)(lVar2 + 0x68) == 0) {
          *(longlong *)(lVar2 + 0x68) = lVar1;
        }
      }
      else if (((*(int *)(lVar1 + 4) == 3) && (*(char *)(lVar1 + 2) < '\0')) &&
              ((*(longlong *)(lVar2 + 0x70) == 0 && (*(int *)(lVar2 + 0x78) - 1U < 2)))) {
        *(longlong *)(lVar2 + 0x70) = lVar1;
      }
      uVar4 = (int)uVar5 + 1;
      uVar5 = (ulonglong)uVar4;
    } while (uVar4 < *(uint *)(lVar3 + 0x10));
  }
  iVar6 = 0;
  if (*(longlong *)(lVar2 + 0x60) == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x54,
              &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
    }
    iVar6 = -0x3ffffe7e;
  }
  if (*(longlong *)(lVar2 + 0x68) == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x55,
              &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
    }
    iVar6 = -0x3ffffe7e;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0)) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x56,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar6);
  }
  USBSTOR_LogEntry(0x70697067,(longlong)iVar6,*(undefined8 *)(lVar2 + 0x60),
                   *(undefined8 *)(lVar2 + 0x68));
  return iVar6;
}



===== UsbQueueInitialize @ 14001f658 =====

void UsbQueueInitialize(undefined8 *param_1)

{
  undefined8 *puVar1;
  longlong lVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
            &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
  }
  KeInitializeSpinLock(param_1 + 0x24);
  param_1[0x25] = 1;
  *(undefined1 *)(param_1 + 0x26) = 0;
  param_1[0x2c] = 0;
  *param_1 = 0x14;
  lVar2 = 3;
  puVar1 = param_1 + 2;
  param_1[1] = 3;
  param_1[3] = puVar1;
  *puVar1 = puVar1;
  PortListInitialize((longlong)(param_1 + 4),param_1);
  puVar1 = param_1 + 0xb;
  do {
    PortListInitialize((longlong)puVar1,param_1);
    puVar1 = puVar1 + 7;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  UsbQueueSfioInitialize((longlong)param_1);
  KeInitializeEvent(param_1 + 0x29,0,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
  }
  return;
}



===== UsbQueueSfioInitialize @ 14001f764 =====

void UsbQueueSfioInitialize(longlong param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
            &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
  }
  PortAvioAdmissionControllerInit(param_1 + 0x100);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
            &WPP_7ff7ab8186473176ecd1ebe60dfe9527_Traceguids);
  }
  return;
}



===== USBSTOR_QueryWmiRegInfo @ 14001f800 =====

undefined8
USBSTOR_QueryWmiRegInfo
          (longlong param_1,undefined4 *param_2,undefined8 param_3,undefined8 *param_4,
          undefined8 param_5,undefined8 *param_6)

{
  *param_6 = *(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x10);
  *param_2 = 0x20;
  *param_4 = &DAT_14001a1c8;
  return 0;
}



===== WppInitKm @ 14001f82c =====

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



===== USBSTOR_DetectPortableWorkspace @ 14001f8bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong USBSTOR_DetectPortableWorkspace(undefined8 param_1)

{
  int iVar1;
  ulonglong uVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined1 auStack_118 [32];
  undefined8 local_f8;
  char local_e8;
  char local_e7 [3];
  int local_e4;
  int local_e0 [2];
  undefined8 local_d8 [2];
  undefined1 local_c8 [8];
  undefined4 local_c0;
  wchar_t *local_b8;
  int *local_b0;
  undefined4 local_a8;
  undefined4 local_88;
  wchar_t *local_80;
  int *local_78;
  undefined4 local_70;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_118;
  local_d8[0] = 0;
  local_e8 = '\0';
  local_e7[0] = '\0';
  uVar2 = RtlCheckPortableOperatingSystem(&local_e8);
  if ((int)uVar2 == -0x3ffffddb) {
    uVar2 = USBSTOR_InRootContainer(param_1,local_e7);
    iVar1 = (int)uVar2;
    if (iVar1 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          (uVar2 = (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
          (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
      goto LAB_14001f999;
      uVar4 = 0xaf;
    }
    else {
      local_e8 = local_e7[0] == '\0';
      uVar2 = RtlSetPortableOperatingSystem();
      iVar1 = (int)uVar2;
      if (((-1 < iVar1) || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0 || ((byte)WPP_GLOBAL_Control[0x29] < 2)))
         ) goto LAB_14001f999;
      uVar4 = 0xae;
    }
    uVar2 = WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
                     &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar1);
  }
LAB_14001f999:
  if (local_e8 != '\0') {
    local_e4 = 0;
    local_e0[0] = 1;
    memset(local_c8,0,0xa8);
    local_f8 = 0;
    local_b8 = L"Hibernate";
    local_b0 = &local_e4;
    local_c0 = 0x120;
    local_80 = L"Sleep";
    local_78 = local_e0;
    local_a8 = 0x4000000;
    local_88 = 0x120;
    local_70 = 0x4000000;
    RtlQueryRegistryValuesEx
              (0,
               L"\\Registry\\Machine\\System\\CurrentControlSet\\Policies\\Microsoft\\PortableOperatingSystem"
               ,local_c8,0);
    uVar2 = (ulonglong)(uint)-local_e0[0];
    bVar3 = ~-(local_e0[0] != 0) & 7U | ~-(local_e4 != 0) & 8U;
    if (bVar3 != 0) {
      uVar2 = PoDisableSleepStates(3,bVar3,local_d8);
      if ((((int)uVar2 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29])))
         ) {
        uVar2 = WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb0,
                         &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,(int)uVar2);
      }
    }
  }
  return uVar2;
}



===== USBSTOR_FdoCancelStopRemoveDevice @ 14001fabc =====

int USBSTOR_FdoCancelStopRemoveDevice(longlong param_1,longlong param_2)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x65,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  USBSTOR_LogEntry(0x44525343,param_1,param_2,0);
  lVar1 = *(longlong *)(param_1 + 0x40);
  *(undefined4 *)(param_2 + 0x30) = 0;
  cVar2 = IoForwardIrpSynchronously(*(undefined8 *)(lVar1 + 0x18),param_2);
  if (cVar2 == '\0') {
    iVar3 = -0x3fffffff;
  }
  else {
    iVar3 = *(int *)(param_2 + 0x30);
    if (-1 < iVar3) goto LAB_14001fb75;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x66,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
LAB_14001fb75:
  IofCompleteRequest(param_2,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x67,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar3);
  }
  USBSTOR_LogEntry(0x64727363,(longlong)iVar3,0,0);
  return iVar3;
}



===== USBSTOR_FdoDeviceUsageNotification @ 14001fbe4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int USBSTOR_FdoDeviceUsageNotification(longlong param_1,longlong param_2)

{
  char *pcVar1;
  char cVar2;
  longlong lVar3;
  longlong lVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  longlong lVar11;
  undefined2 uVar12;
  uint uVar13;
  short sVar14;
  bool bVar15;
  undefined1 auStack_1e8 [32];
  uint *local_1c8;
  undefined4 local_1c0;
  undefined1 local_1b8;
  char local_1a8;
  char local_1a7 [3];
  uint local_1a4 [3];
  longlong local_198;
  longlong lStack_190;
  undefined8 local_188;
  longlong local_180 [4];
  ushort local_160 [8];
  undefined8 local_150;
  undefined8 uStack_148;
  ushort local_140 [8];
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined1 local_118 [8];
  undefined4 local_110;
  wchar_t *local_108;
  uint *local_100;
  undefined4 local_f8;
  uint *local_f0;
  undefined4 local_e8;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined8 local_a0;
  undefined4 local_98;
  undefined4 local_94;
  undefined8 local_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined8 local_80;
  undefined4 local_78;
  undefined4 local_74;
  wchar_t local_70 [24];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_1e8;
  lVar3 = *(longlong *)(param_1 + 0x40);
  local_1a8 = '\0';
  local_188 = 0;
  local_180[3] = 0;
  local_1a4[1] = 0;
  local_1a4[0] = 0;
  local_160[0] = 0;
  local_160[1] = 0;
  local_160[2] = 0;
  local_160[3] = 0;
  local_160[4] = 0;
  local_160[5] = 0;
  local_160[6] = 0;
  local_160[7] = 0;
  local_1a7[0] = '\0';
  local_150 = 0;
  uStack_148 = 0;
  local_180[0] = 0;
  local_140[0] = 0;
  local_140[1] = 0;
  local_140[2] = 0;
  local_140[3] = 0;
  local_140[4] = 0;
  local_140[5] = 0;
  local_140[6] = 0;
  local_140[7] = 0;
  local_198 = 0;
  lStack_190 = 0;
  local_180[1] = 0;
  local_180[2] = 0;
  iVar8 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x10);
  cVar2 = *(char *)(*(longlong *)(param_2 + 0xb8) + 8);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6e,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  USBSTOR_LogEntry(0x4e554446,param_1,param_2,0);
  if ((*(char *)(lVar3 + 0x715) == '\0') && (iVar8 - 1U < 4)) {
    iVar6 = -0x3fffff45;
    *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
    goto LAB_140020501;
  }
  if ((cVar2 == '\0') || (iVar8 != 3)) {
    if (iVar8 == 4) {
      cVar5 = '\0';
      puVar9 = *(undefined8 **)(lVar3 + 0x20);
      do {
        if (puVar9 == (undefined8 *)(lVar3 + 0x20)) break;
        pcVar1 = (char *)((longlong)puVar9 + 0x31);
        puVar9 = (undefined8 *)*puVar9;
        cVar5 = -(*pcVar1 >> 7);
      } while (cVar5 == '\0');
      iVar6 = RtlCheckPortableOperatingSystem(&local_1a8);
      if (((-1 < iVar6) && (local_1a8 == '\0')) || (cVar5 == '\x01')) {
        RtlSetPortableOperatingSystem(0);
        if (*(int *)(lVar3 + 0x7c) == 0) {
          iVar6 = IoOpenDeviceRegistryKey(*(undefined8 *)(lVar3 + 0x10),2,0x1f0000);
          if (iVar6 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6f,
                      &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
            }
          }
          else {
            local_1c8 = local_1a4 + 1;
            local_1a4[1] = 1;
            local_1c0 = 4;
            iVar6 = RtlWriteRegistryValue(0x40000000,local_188,L"NonRemovable");
            if (((iVar6 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
               (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 &&
                (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x70,
                      &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
            }
            ZwClose(local_188);
          }
        }
        uVar10 = USBSTOR_InRootContainer(*(undefined8 *)(lVar3 + 0x10),local_1a7);
        if ((-1 < (int)uVar10) && (local_1a7[0] == '\0')) {
          RtlInitUnicodeString(&local_198,0);
          RtlInitUnicodeString(local_160,L"DeviceOverrides\\");
          RtlInitUnicodeString(&local_150,L"\\LocationPaths");
          RtlInitUnicodeString(local_140,L"\\*");
          local_70[0x10] = L'\0';
          local_70[0x11] = L'\0';
          local_70[0x12] = L'\0';
          local_70[0x13] = L'\0';
          local_70[0] = L'\0';
          local_70[1] = L'\0';
          local_70[2] = L'\0';
          local_70[3] = L'\0';
          local_70[4] = L'\0';
          local_70[5] = L'\0';
          local_70[6] = L'\0';
          local_70[7] = L'\0';
          local_70[0x14] = L'\0';
          local_70[0x15] = L'\0';
          local_70[8] = L'\0';
          local_70[9] = L'\0';
          local_70[10] = L'\0';
          local_70[0xb] = L'\0';
          local_70[0xc] = L'\0';
          local_70[0xd] = L'\0';
          local_70[0xe] = L'\0';
          local_70[0xf] = L'\0';
          local_1c8 = (uint *)CONCAT44(local_1c8._4_4_,
                                       (uint)*(ushort *)(*(longlong *)(lVar3 + 0x30) + 10));
          iVar6 = swprintf_s(local_70,0x16,L"USB#VID_%04x&PID_%04x");
          if (iVar6 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar12 = 0x73;
              goto LAB_1400200c0;
            }
          }
          else {
            sVar14 = (short)iVar6 * 2 + local_140[1] + local_150._2_2_ + local_160[1];
            lStack_190 = ExAllocatePool2(0x100,sVar14,0x53414d55);
            if (lStack_190 == 0) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar12 = 0x71;
                goto LAB_1400200c0;
              }
            }
            else {
              local_198 = (ulonglong)CONCAT42((int)((ulonglong)local_198 >> 0x20),sVar14) << 0x10;
              RtlUnicodeStringCat((ushort *)&local_198,local_160);
              RtlCreateRegistryKey(2,lStack_190);
              RtlUnicodeStringCatString((ushort *)&local_198,local_70);
              RtlCreateRegistryKey(2,lStack_190);
              RtlUnicodeStringCat((ushort *)&local_198,(ushort *)&local_150);
              RtlCreateRegistryKey(2,lStack_190);
              RtlUnicodeStringCat((ushort *)&local_198,local_140);
              RtlCreateRegistryKey(2,lStack_190);
              local_1c0 = 4;
              local_1c8 = local_1a4 + 1;
              local_1a4[1] = 0;
              iVar6 = RtlWriteRegistryValue(2,lStack_190,L"Removable");
              ExFreePoolWithTag(lStack_190,0x53414d55);
              if (((iVar6 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
                 (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 &&
                  (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
                uVar12 = 0x72;
LAB_1400200c0:
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar12,
                        &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
              }
            }
          }
        }
        if ((*(uint *)(lVar3 + 0x84) & 0x40) == 0) {
          local_1c8 = (uint *)CONCAT44(local_1c8._4_4_,
                                       (uint)*(ushort *)(*(longlong *)(lVar3 + 0x30) + 10));
          iVar6 = swprintf_s(local_70,0x16,L"usbstor\\%04X%04X");
          if (-1 < iVar6) {
            memset(local_118,0,0x70);
            local_110 = 0x120;
            local_108 = L"DeviceHackFlags";
            local_f8 = 0x4000004;
            local_100 = local_1a4;
            local_e8 = 4;
            local_f0 = local_1a4;
            local_1c8 = (uint *)0x0;
            iVar6 = RtlQueryRegistryValuesEx(2,local_70,local_118);
            if (iVar6 < 0) {
              local_1a4[0] = 0x40;
            }
            else {
              local_1a4[0] = local_1a4[0] | 0x40;
            }
            local_1c8 = (uint *)local_180;
            iVar6 = USBSTOR_GetStateSeparationLocation();
            lVar11 = local_180[0];
            uVar13 = local_1a4[0];
            if (-1 < iVar6) {
              local_1a4[0] = 0;
              local_1c8 = (uint *)0x0;
              iVar6 = RtlQueryRegistryValuesEx(0,local_180[0],local_118,0);
              if (-1 < iVar6) {
                uVar13 = uVar13 | local_1a4[0];
              }
              local_1c0 = 4;
              local_1c8 = local_1a4;
              local_1a4[0] = uVar13;
              iVar6 = RtlWriteRegistryValue(0,lVar11,L"DeviceHackFlags");
              if ((((iVar6 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x74,
                        &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
              }
            }
            if (lVar11 != 0) {
              ExFreePoolWithTag(lVar11,0);
            }
          }
          if (((iVar6 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
             (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x75,
                    &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
          }
        }
      }
    }
  }
  else if (((*(char *)(lVar3 + 0x74a) == '\0') && (*(char *)(lVar3 + 0x715) != '\0')) &&
          (*(char *)(lVar3 + 0x716) == '\0')) {
    *(uint *)(lVar3 + 0x84) = *(uint *)(lVar3 + 0x84) & 0xffffff7f;
  }
  cVar5 = IoForwardIrpSynchronously(*(undefined8 *)(lVar3 + 0x18),param_2);
  if (cVar5 == '\0') {
    iVar6 = -0x3fffffff;
  }
  else {
    iVar6 = *(int *)(param_2 + 0x30);
  }
  if ((iVar8 - 1U < 3) && (-1 < iVar6)) {
    if ((*(uint *)(*(longlong *)(lVar3 + 0x18) + 0x30) & 0x2000) == 0) {
      uVar13 = *(uint *)(param_1 + 0x30) & 0xffffdfff;
    }
    else {
      uVar13 = *(uint *)(param_1 + 0x30) | 0x2000;
    }
    *(uint *)(param_1 + 0x30) = uVar13;
  }
  local_180[2] = *(undefined8 *)(lVar3 + 0x18);
  local_180[3] = 0x10;
  if ((iVar8 != 1) || (local_180[1] = 0x3a, (*(uint *)(param_1 + 0x30) & 0x2000) != 0)) {
    local_180[1] = 0x3b;
  }
  local_1c8 = (uint *)((ulonglong)local_1c8 & 0xffffffff00000000);
  ZwPowerInformation(0x57,local_180 + 1);
  iVar7 = RtlCheckRegistryKey(2,L"MiniNT");
  if (-1 < iVar7) goto LAB_140020501;
  if (iVar8 == 1) {
    if (cVar2 == '\0') goto LAB_140020501;
    if (iVar6 < 0) goto LAB_140020377;
  }
  else {
LAB_140020377:
    if (iVar8 != 4) goto LAB_140020501;
  }
  local_130 = 0;
  uStack_128 = 0;
  local_120 = 0;
  *(undefined1 *)(lVar3 + 0x754) = 1;
  USBSTOR_InitializeEmergencyWorkerThread();
  lVar11 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c),0);
  LOCK();
  bVar15 = *(longlong *)(lVar3 + 0x758) == 0;
  if (bVar15) {
    *(longlong *)(lVar3 + 0x758) = lVar11;
  }
  UNLOCK();
  if ((!bVar15) && (lVar11 != 0)) {
    IoFreeIrp();
  }
  if ((*(char *)(lVar3 + 0x755) == '\0') &&
     (lVar11 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(lVar3 + 0x18) >> 8),
                                      *(undefined1 *)(*(longlong *)(lVar3 + 0x18) + 0x4c)),0),
     lVar11 != 0)) {
    local_88 = *(undefined4 *)(lVar3 + 0x718);
    local_a0 = 0;
    local_84 = 0;
    local_74 = 0;
    local_a8 = 1;
    local_a4 = 0x38;
    local_98 = 0x1000;
    local_94 = 2;
    local_90 = *(undefined8 *)(*(longlong *)(lVar3 + 0x60) + 8);
    local_80 = *(undefined8 *)(*(longlong *)(lVar3 + 0x68) + 8);
    local_78 = local_88;
    KeInitializeEvent(&local_130,1,0);
    lVar4 = *(longlong *)(lVar11 + 0xb8);
    local_1b8 = 1;
    local_1c0 = CONCAT31(local_1c0._1_3_,1);
    local_1c8 = (uint *)CONCAT71(local_1c8._1_7_,1);
    *(undefined4 **)(lVar4 + -0x40) = &local_a8;
    *(undefined1 *)(lVar4 + -0x48) = 0xf;
    *(undefined4 *)(lVar4 + -0x30) = 0x49140f;
    iVar8 = IoSetCompletionRoutineEx(param_1,lVar11);
    if (-1 < iVar8) {
      iVar8 = IofCallDriver(*(undefined8 *)(lVar3 + 0x18),lVar11);
      if (iVar8 == 0x103) {
        local_1c8 = (uint *)0x0;
        KeWaitForSingleObject(&local_130,0);
      }
      if (-1 < *(int *)(lVar11 + 0x30)) {
        *(undefined1 *)(lVar3 + 0x755) = 1;
      }
    }
    IoFreeIrp(lVar11);
  }
LAB_140020501:
  IofCompleteRequest(param_2,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x76,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar6);
  }
  USBSTOR_LogEntry(0x6e756466,(longlong)iVar6,0,0);
  return iVar6;
}



===== USBSTOR_FdoQueryStopRemoveDevice @ 140020590 =====

int USBSTOR_FdoQueryStopRemoveDevice(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),99,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  USBSTOR_LogEntry(0x44525351,param_1,param_2,0);
  lVar1 = *(longlong *)(param_1 + 0x40);
  if ((*(uint *)(param_1 + 0x30) & 0x2000) == 0) {
    iVar2 = -0x3fffffff;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000001;
    IofCompleteRequest(param_2,0);
  }
  else {
    *(undefined4 *)(param_2 + 0x30) = 0;
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    iVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 0x18),param_2);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),100,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar2);
  }
  USBSTOR_LogEntry(0x64727371,(longlong)iVar2,0,0);
  return iVar2;
}



===== USBSTOR_FdoStopDevice @ 140020698 =====

int USBSTOR_FdoStopDevice(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5f,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  USBSTOR_LogEntry(0x504f5453,param_1,param_2,0);
  lVar1 = *(longlong *)(param_1 + 0x40);
  USBSTOR_CancelInterruptIrp(lVar1);
  *(undefined1 *)(lVar1 + 0x78c) = 1;
  IoStartPacket(param_1,param_2);
  KeWaitForSingleObject(lVar1 + 0x790,0,0,0,0);
  USBSTOR_WmiDeregister(lVar1);
  USBSTOR_UnConfigure(param_1);
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  iVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 0x18),param_2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x60,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar2);
  }
  USBSTOR_LogEntry(0x706f7473,(longlong)iVar2,0,0);
  return iVar2;
}



===== USBSTOR_InRootContainer @ 1400207e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 USBSTOR_InRootContainer(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined1 auStack_268 [32];
  undefined4 *local_248;
  undefined4 local_238 [2];
  undefined8 local_230;
  wchar_t *local_228;
  undefined1 local_218 [8];
  undefined4 local_210;
  wchar_t *local_208;
  undefined8 *local_200;
  undefined4 local_1f8;
  wchar_t local_168 [80];
  wchar_t local_c8 [80];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_268;
  local_230 = 0x9a0000;
  local_238[0] = 0;
  memset(local_218,0,0xa8);
  local_210 = 0x124;
  local_1f8 = 0x1000000;
  local_208 = L"ContainerID";
  local_200 = &local_230;
  local_248 = (undefined4 *)0x0;
  local_228 = local_168;
  iVar1 = RtlQueryRegistryValuesEx
                    (0,L"\\Registry\\Machine\\System\\CurrentControlSet\\Enum\\HTREE\\ROOT\\0",
                     local_218,0);
  if (-1 < iVar1) {
    local_248 = local_238;
    iVar1 = IoGetDeviceProperty(param_1,0x16,0x9a,local_c8);
    if (-1 < iVar1) {
      iVar1 = _wcsnicmp(local_c8,local_168,0x4d);
      *(bool *)param_2 = iVar1 == 0;
      return 0;
    }
  }
  return 0xc0000225;
}



===== USBSTOR_PdoDeviceUsageNotification @ 14002091c =====

int USBSTOR_PdoDeviceUsageNotification(longlong param_1,longlong param_2)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  uint uVar7;
  longlong lVar8;
  longlong lVar9;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  puVar3 = *(undefined1 **)(param_2 + 0xb8);
  lVar4 = *(longlong *)(param_1 + 0x40);
  iVar2 = *(int *)(puVar3 + 0x10);
  cVar1 = puVar3[8];
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x93,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  USBSTOR_LogEntry(0x4e554450,param_1,param_2,0);
  if (3 < iVar2 - 1U) {
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    iVar6 = IofCallDriver(*(undefined8 *)(lVar4 + 0x10),param_2);
    goto LAB_140020b5e;
  }
  if ((*(char *)(lVar4 + 0x46) == '\0') || (cVar1 == '\0')) {
    lVar8 = IoGetAttachedDevice(*(undefined8 *)(lVar4 + 0x10));
    lVar9 = IoAllocateIrp(*(undefined1 *)(lVar8 + 0x4c),0);
    if (lVar9 == 0) {
      iVar6 = -0x3fffff66;
    }
    else {
      *(undefined4 *)(lVar9 + 0x30) = 0xc00000bb;
      local_38 = 0;
      local_48 = 0;
      uStack_40 = 0;
      KeInitializeEvent(&local_48,0);
      lVar5 = *(longlong *)(lVar9 + 0xb8);
      *(code **)(lVar5 + -0x10) = USBSTOR_SyncCompletionRoutine;
      *(undefined8 **)(lVar5 + -8) = &local_48;
      *(undefined1 *)(lVar5 + -0x45) = 0xe0;
      lVar5 = *(longlong *)(lVar9 + 0xb8);
      *(undefined1 *)(lVar5 + -0x48) = *puVar3;
      *(undefined1 *)(lVar5 + -0x47) = puVar3[1];
      *(undefined8 *)(lVar5 + -0x18) = *(undefined8 *)(puVar3 + 0x30);
      *(char *)(lVar5 + -0x40) = cVar1;
      *(int *)(lVar5 + -0x38) = iVar2;
      iVar6 = IofCallDriver(lVar8,lVar9);
      if (iVar6 == 0x103) {
        KeWaitForSingleObject(&local_48,5,0,0,0);
      }
      iVar6 = *(int *)(lVar9 + 0x30);
      IoFreeIrp(lVar9);
      if ((-1 < iVar6) && (iVar2 < 4)) {
        if (cVar1 == '\0') {
          LOCK();
          *(int *)(lVar4 + 800) = *(int *)(lVar4 + 800) + -1;
          UNLOCK();
        }
        else {
          LOCK();
          *(int *)(lVar4 + 800) = *(int *)(lVar4 + 800) + 1;
          UNLOCK();
        }
        if (*(int *)(lVar4 + 800) == 0) {
          uVar7 = *(uint *)(param_1 + 0x30) | 0x2000;
        }
        else {
          uVar7 = *(uint *)(param_1 + 0x30) & 0xffffdfff;
        }
        *(uint *)(param_1 + 0x30) = uVar7;
        goto LAB_140020a05;
      }
    }
    if (iVar2 == 4) {
      USBSTOR_DetectPortableWorkspace(param_1);
    }
  }
  else {
    iVar6 = -0x3fffff45;
  }
LAB_140020a05:
  *(int *)(param_2 + 0x30) = iVar6;
  IofCompleteRequest(param_2,0);
  IoInvalidateDeviceState(param_1);
LAB_140020b5e:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x94,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar6);
  }
  USBSTOR_LogEntry(0x6e756470,(longlong)iVar6,0,0);
  return iVar6;
}



===== USBSTOR_PdoStopDevice @ 140020bcc =====

undefined8 USBSTOR_PdoStopDevice(longlong param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7d,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar2 = USBSTOR_IsSelectiveSuspendEnabled(*(longlong *)(*(longlong *)(lVar1 + 0x10) + 0x40));
  if ((char)uVar2 != '\0') {
    PoRegisterDeviceForIdleDetection(param_1);
  }
  UsbQueueFreeze(lVar1 + 0x170);
  *(undefined4 *)(lVar1 + 0x28) = 5;
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7e,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,0);
  }
  USBSTOR_LogEntry(0x70747370,0,0,0);
  return 0;
}



===== USBSTOR_SetWmiDataBlock @ 140020ce0 =====

void USBSTOR_SetWmiDataBlock
               (longlong param_1,undefined8 param_2,int param_3,undefined8 param_4,int param_5,
               char *param_6)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_res8;
  uint local_res18 [2];
  uint *in_stack_ffffffffffffffa8;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_res8 = 0;
  local_res18[0] = 0;
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_28 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (param_3 != 1) {
    uVar4 = 0xc0000295;
    goto LAB_140020e51;
  }
  if (param_5 == 0) {
    uVar4 = 0xc0000023;
    goto LAB_140020e51;
  }
  local_res18[0] = (uint)(*param_6 != '\0');
  lVar2 = *(longlong *)(lVar1 + 0x7b0);
  if (*param_6 == '\0') {
    if (lVar2 != 0) {
      PoFxUnregisterDevice(lVar2);
      *(undefined8 *)(lVar1 + 0x7b0) = 0;
    }
LAB_140020dc8:
    iVar3 = IoOpenDeviceRegistryKey(*(undefined8 *)(lVar1 + 0x10),1,0x20006,&local_res8);
    if (-1 < iVar3) {
      RtlInitUnicodeString(&local_48,L"EnableSelectiveSuspend");
      in_stack_ffffffffffffffa8 = local_res18;
      iVar3 = ZwSetValueKey(local_res8,&local_48,0,4,in_stack_ffffffffffffffa8,4);
      if (-1 < iVar3) {
        *(bool *)(lVar1 + 0x7f9) = local_res18[0] != 0;
      }
      ZwClose(local_res8);
    }
  }
  else {
    if (lVar2 != 0) goto LAB_140020dc8;
    KeAcquireInStackQueuedSpinLock(lVar1 + 0x90,&local_38);
    iVar3 = *(int *)(lVar1 + 0x80);
    KeReleaseInStackQueuedSpinLock(&local_38);
    if (iVar3 != 0) {
      uVar4 = 0x80000011;
      goto LAB_140020e51;
    }
    iVar3 = USBSTOR_EnableRuntimePowerManagement(lVar1);
    if (-1 < iVar3) goto LAB_140020dc8;
  }
  uVar4 = 0;
LAB_140020e51:
  WmiCompleteRequest(param_1,param_2,uVar4,0,
                     (ulonglong)in_stack_ffffffffffffffa8 & 0xffffffffffffff00);
  return;
}



===== USBSTOR_UnConfigure @ 140020e88 =====

int USBSTOR_UnConfigure(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa4,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  USBSTOR_LogEntry(0x4e4f4355,param_1,0,0);
  lVar1 = *(longlong *)(param_1 + 0x40);
  puVar3 = (undefined4 *)ExAllocatePool2(0x40,0x28);
  if (puVar3 == (undefined4 *)0x0) {
    iVar2 = -0x3fffff66;
  }
  else {
    *puVar3 = 0x28;
    *(undefined8 *)(puVar3 + 6) = 0;
    iVar2 = USBSTOR_SyncSendUsbRequest(param_1,(longlong)puVar3);
    ExFreePoolWithTag(puVar3,0);
    *(undefined8 *)(lVar1 + 0x50) = 0;
    if (*(longlong *)(lVar1 + 0x58) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar1 + 0x58),0);
      *(undefined8 *)(lVar1 + 0x58) = 0;
    }
    *(undefined8 *)(lVar1 + 0x60) = 0;
    *(undefined8 *)(lVar1 + 0x68) = 0;
    *(undefined8 *)(lVar1 + 0x70) = 0;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa5,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar2);
  }
  USBSTOR_LogEntry(0x6e6f6375,(longlong)iVar2,0,0);
  return iVar2;
}



===== WppTraceCallback @ 140020fe0 =====

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



===== wil_UninitializeFeatureStaging @ 140021268 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 1400212c0 =====

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
      goto LAB_14002131d;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_14002131d;
    }
  }
  uVar1 = 0x206;
LAB_14002131d:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 140021328 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  undefined **ppuVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  bool bVar6;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)&wil_details_featureDescriptors_a)
  ;
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
  ppuVar2 = &wil_details_featureDescriptors_a;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar2);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    ppuVar2 = (undefined **)(plVar1 + 7);
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1400213e0 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 140021418 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_14002149a;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14002149a;
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
LAB_14002149a:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 1400214f0 =====

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
      ppuVar3 = &wil_details_featureDescriptors_a;
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140021550 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14002156c =====

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
  ppuVar3 = &wil_details_featureDescriptors_a;
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



===== USBSTOR_EjectMedia @ 140021620 =====

undefined4 USBSTOR_EjectMedia(longlong param_1,undefined8 param_2,undefined *param_3)

{
  undefined4 uVar1;
  int local_res10 [6];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res10[0] = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_e947f7dfdc8330b398201c2535585168_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc5,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  uStack_10 = 0;
  local_18 = 0x20000011b;
  uVar1 = USBSTOR_IssueInternalCdbToLun(param_1,0,param_3,0,local_res10,&local_18,6,10);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc6,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,uVar1);
  }
  return uVar1;
}



===== USBSTOR_GetBcProperties @ 140021700 =====

undefined4 USBSTOR_GetBcProperties(longlong param_1,longlong param_2)

{
  bool bVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 uVar5;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  uVar5 = 0xc0000010;
  lVar4 = param_2;
  bVar1 = USBSTOR_IsAvioEnabledDevice(lVar3);
  if (bVar1) {
    uVar2 = PortAvioGetBcProperties(lVar3 + 0x270,lVar4);
    uVar5 = (undefined4)uVar2;
  }
  *(undefined4 *)(param_2 + 0x30) = uVar5;
  IofCompleteRequest(param_2,0);
  return uVar5;
}



===== USBSTOR_GetDeviceSerialNumber @ 140021758 =====

int USBSTOR_GetDeviceSerialNumber(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte bVar8;
  
  iVar3 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xbf,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(*(longlong *)(lVar1 + 0x10) + 0x40);
  if ((*(uint *)(lVar2 + 0x84) & 0x100) == 0) {
    iVar3 = USBSTOR_SerialNumberVPDInquiry(param_1);
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    else if ((*(uint *)(lVar2 + 0x84) & 0x100) == 0) goto LAB_14002185f;
  }
  pbVar7 = *(byte **)(lVar2 + 0x48);
  pbVar6 = (byte *)(lVar1 + 0x6c);
  if ((pbVar7 != (byte *)0x0) && (3 < *pbVar7)) {
    bVar5 = (byte)((longlong)(int)(*pbVar7 - 2) / 2);
    bVar8 = bVar5 - 1;
    if (*(char *)(lVar2 + 0x748) == '\0') {
      bVar8 = bVar5;
    }
    bVar5 = 0;
    if (bVar8 != 0) {
      do {
        pbVar7 = pbVar7 + 2;
        bVar5 = bVar5 + 1;
        *pbVar6 = *pbVar7;
        pbVar6 = pbVar6 + 1;
      } while (bVar5 < bVar8);
    }
    if (*(char *)(lVar2 + 0x748) == '\0') {
      uVar4 = (uint)bVar5;
    }
    else {
      *pbVar6 = (-(*(byte *)(lVar1 + 0x47) < 10) & 0xefU) + 0x41 + *(byte *)(lVar1 + 0x47);
      uVar4 = bVar5 + 1;
    }
    *(uint *)(lVar1 + 0x40) = uVar4;
  }
LAB_14002185f:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc0,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar3);
  }
  return iVar3;
}



===== USBSTOR_ScsiCapabilities @ 1400218b4 =====

undefined4 USBSTOR_ScsiCapabilities(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xca,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  uVar1 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  uVar5 = (ulonglong)uVar1;
  if (uVar1 < 0x18) {
    uVar4 = 0xc0000023;
  }
  else {
    uVar5 = 0x18;
    uVar4 = 0;
    lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10) + 0x40);
    puVar3 = *(undefined8 **)(param_2 + 0x18);
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    *(undefined4 *)puVar3 = 0x18;
    *(undefined4 *)((longlong)puVar3 + 4) = *(undefined4 *)(lVar2 + 0x718);
    *(undefined4 *)(puVar3 + 1) = *(undefined4 *)(lVar2 + 0x71c);
  }
  *(ulonglong *)(param_2 + 0x38) = uVar5;
  *(undefined4 *)(param_2 + 0x30) = uVar4;
  IofCompleteRequest(param_2,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xcb,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,uVar4);
  }
  return uVar4;
}



===== USBSTOR_ReadWrite @ 1400219c0 =====

undefined8 USBSTOR_ReadWrite(undefined8 param_1,longlong param_2)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
            &WPP_83961903f8913993eee34094953b83c3_Traceguids);
  }
  USBSTOR_LogEntry(0x20205752,param_1,param_2,0);
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
  IofCompleteRequest(param_2,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_83961903f8913993eee34094953b83c3_Traceguids,0xc000000d);
  }
  USBSTOR_LogEntry(0x20207772,0xffffffffc000000d,0,0);
  return 0xc000000d;
}



===== USBSTOR_LogInit @ 140021aa0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void USBSTOR_LogInit(void)

{
  KeInitializeSpinLock(&DAT_14001a1c0);
  DAT_14001a1a8 = ExAllocatePool2(0x40,0x8000,0x53414d55);
  if (DAT_14001a1a8 != 0) {
    DAT_14001a1b8 = DAT_14001a1a8 + 0x8000;
    DAT_14001a1b0 = DAT_14001a1a8 + 0x7fe0;
  }
  KeInitializeSpinLock(&DAT_14001a1e8);
  DAT_14001a1d8 = ExAllocatePool2(0x40,0x2000,0x53414d55);
  if (DAT_14001a1d8 != 0) {
    _DAT_14001a1e0 = DAT_14001a1d8 + 0x2000;
  }
  return;
}



===== USBSTOR_1667DetermineAllocationLength @ 140021b50 =====

void USBSTOR_1667DetermineAllocationLength(char param_1,uint param_2,uint *param_3,uint *param_4)

{
  if (param_1 == '\0') {
    if (param_4 != (uint *)0x0) {
      *param_4 = param_2;
    }
  }
  else {
    param_2 = param_2 + 0x1ff >> 9;
    if (param_4 != (uint *)0x0) {
      *param_4 = param_2 << 9;
    }
  }
  if (param_3 != (uint *)0x0) {
    *param_3 = param_2;
  }
  return;
}



===== USBSTOR_1667DetermineInc512Support @ 140021b84 =====

void USBSTOR_1667DetermineInc512Support
               (longlong param_1,byte param_2,undefined1 *param_3,undefined1 *param_4)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  uint uVar4;
  
  uVar3 = 1;
  cVar1 = USBSTOR_1667SendZeroLengthSPINCommand
                    (param_1,param_2,CONCAT71((int7)((ulonglong)param_3 >> 8),1));
  uVar4 = (uint)param_2;
  if (cVar1 == '\0') {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
               &WPP_882c5dbd4c393422b71f4ab343c3933e_Traceguids,uVar4);
    }
    uVar2 = 0;
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
               &WPP_882c5dbd4c393422b71f4ab343c3933e_Traceguids,uVar4);
    }
    uVar2 = 1;
  }
  *param_4 = uVar2;
  cVar1 = USBSTOR_1667SendZeroLengthSPINCommand(param_1,param_2,0);
  if (cVar1 == '\0') {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
               &WPP_882c5dbd4c393422b71f4ab343c3933e_Traceguids,uVar4);
    }
    uVar3 = 0;
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
             &WPP_882c5dbd4c393422b71f4ab343c3933e_Traceguids,uVar4);
  }
  *param_3 = uVar3;
  return;
}



===== USBSTOR_1667SendSecurityProtocolIn @ 140021cd0 =====

int USBSTOR_1667SendSecurityProtocolIn
              (longlong param_1,undefined1 param_2,char param_3,undefined8 param_4,
              undefined8 param_5,uint *param_6,undefined8 param_7)

{
  int iVar1;
  ulonglong uVar2;
  undefined2 uVar3;
  uint uVar4;
  uint *puVar5;
  uint local_res20 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res20[0] = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_882c5dbd4c393422b71f4ab343c3933e_Traceguids);
  }
  uVar4 = *param_6;
  *param_6 = 0;
  if ((param_3 != '\0') && ((uVar4 & 0x1ff) != 0)) {
    iVar1 = -0x3fffffdd;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3fffffdd;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_882c5dbd4c393422b71f4ab343c3933e_Traceguids);
    }
    goto LAB_140021e7d;
  }
  puVar5 = local_res20;
  uStack_20 = 0;
  local_28 = (ulonglong)CONCAT14(param_3 << 7,0xa2);
  USBSTOR_1667SetAllocationLength(param_3,uVar4,puVar5,(undefined1 *)((longlong)&local_28 + 6));
  if (uVar4 < local_res20[0]) {
    iVar1 = -0x3fffffdd;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3fffffdd;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_140021e7d;
    uVar3 = 0xc;
  }
  else {
    iVar1 = USBSTOR_IssueInternalCdbToLun
                      (param_1,param_2,puVar5,param_7,(int *)local_res20,&local_28,0xc,10);
    if (-1 < iVar1) {
      uVar2 = Feature_3194461498__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar2 != 0) {
        uVar4 = local_res20[0];
      }
      *param_6 = uVar4;
      goto LAB_140021e7d;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_140021e7d;
    uVar3 = 0xd;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
          &WPP_882c5dbd4c393422b71f4ab343c3933e_Traceguids);
LAB_140021e7d:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_882c5dbd4c393422b71f4ab343c3933e_Traceguids,iVar1);
  }
  return iVar1;
}



===== USBSTOR_1667SendZeroLengthSPINCommand @ 140021ed4 =====

undefined1
USBSTOR_1667SendZeroLengthSPINCommand(longlong param_1,undefined1 param_2,undefined8 param_3)

{
  int iVar1;
  undefined1 uVar2;
  ulonglong uVar3;
  int local_res18 [4];
  undefined4 local_18;
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined2 uStack_12;
  undefined2 uStack_10;
  undefined6 uStack_e;
  
  uVar2 = 0;
  local_res18[0] = 0;
  uStack_13 = 0;
  uStack_e = 0;
  local_18 = 0xa2;
  uVar3 = CONCAT71((int7)((ulonglong)param_3 >> 8),-((char)param_3 != '\0')) & 0xffffffffffffff80;
  uStack_12 = 0;
  uStack_10 = 0;
  uStack_14 = (undefined1)uVar3;
  iVar1 = USBSTOR_IssueInternalCdbToLun(param_1,param_2,uVar3,0,local_res18,&local_18,0xc,10);
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
              &WPP_882c5dbd4c393422b71f4ab343c3933e_Traceguids);
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



===== USBSTOR_1667SetAllocationLength @ 140021f88 =====

void USBSTOR_1667SetAllocationLength(char param_1,uint param_2,uint *param_3,undefined1 *param_4)

{
  uint local_res20 [2];
  
  local_res20[0] = 0;
  USBSTOR_1667DetermineAllocationLength(param_1,param_2,local_res20,param_3);
  *param_4 = (char)(local_res20[0] >> 0x18);
  param_4[1] = (char)(local_res20[0] >> 0x10);
  param_4[2] = (char)(local_res20[0] >> 8);
  param_4[3] = (char)local_res20[0];
  return;
}



===== USBSTOR_Is1667 @ 140021fd0 =====

/* WARNING: Removing unreachable block (ram,0x0001400222fa) */

undefined1 USBSTOR_Is1667(longlong param_1,undefined1 param_2,char param_3)

{
  int iVar1;
  longlong lVar2;
  ulonglong uVar3;
  byte bVar4;
  undefined2 uVar5;
  uint uVar6;
  uint *puVar7;
  undefined1 uVar8;
  uint local_res20 [2];
  undefined8 in_stack_ffffffffffffffa8;
  
  local_res20[0] = 0;
  uVar8 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
            &WPP_882c5dbd4c393422b71f4ab343c3933e_Traceguids);
  }
  iVar1 = 0;
  puVar7 = local_res20;
  USBSTOR_1667DetermineAllocationLength(param_3,8,(uint *)0x0,puVar7);
  lVar2 = ExAllocatePool2(iVar1 + 0x40,local_res20[0],0x53414d55);
  if (lVar2 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
              &WPP_882c5dbd4c393422b71f4ab343c3933e_Traceguids);
    }
    iVar1 = -0x3fffff66;
    goto LAB_14002232c;
  }
  iVar1 = USBSTOR_1667SendSecurityProtocolIn
                    (param_1,param_2,param_3,puVar7,in_stack_ffffffffffffffa8,local_res20,lVar2);
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
              &WPP_882c5dbd4c393422b71f4ab343c3933e_Traceguids);
    }
LAB_140022301:
    ExFreePoolWithTag(lVar2,0);
    lVar2 = 0;
LAB_1400222eb:
    if (lVar2 == 0) goto LAB_14002232c;
  }
  else {
    uVar3 = Feature_3194461498__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar3 != 0) && (local_res20[0] < 8)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29])))
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                &WPP_882c5dbd4c393422b71f4ab343c3933e_Traceguids);
      }
      iVar1 = -0x3fffff64;
      goto LAB_140022301;
    }
    uVar6 = CONCAT11(*(undefined1 *)(lVar2 + 6),*(undefined1 *)(lVar2 + 7)) + 8;
    if (uVar6 <= local_res20[0]) {
      iVar1 = 0;
LAB_140022246:
      uVar6 = local_res20[0];
      uVar3 = Feature_3194461498__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar3 == 0) {
LAB_1400222cb:
        uVar3 = 0;
        if (*(byte *)(lVar2 + 7) != 0) {
          do {
            if (*(char *)(uVar3 + 8 + lVar2) == -0x12) {
              uVar8 = 1;
              break;
            }
            bVar4 = (char)uVar3 + 1;
            uVar3 = (ulonglong)bVar4;
          } while (bVar4 < *(byte *)(lVar2 + 7));
        }
      }
      else {
        if (uVar6 < 8) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar5 = 0x23;
LAB_140022279:
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
                    &WPP_882c5dbd4c393422b71f4ab343c3933e_Traceguids);
          }
        }
        else {
          if (CONCAT11(*(undefined1 *)(lVar2 + 6),*(undefined1 *)(lVar2 + 7)) + 8 <= uVar6)
          goto LAB_1400222cb;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar5 = 0x24;
            goto LAB_140022279;
          }
        }
        iVar1 = -0x3fffff64;
      }
      goto LAB_1400222eb;
    }
    ExFreePoolWithTag(lVar2,0);
    puVar7 = local_res20;
    iVar1 = 0;
    USBSTOR_1667DetermineAllocationLength(param_3,uVar6,(uint *)0x0,puVar7);
    lVar2 = ExAllocatePool2(iVar1 + 0x40,local_res20[0],0x53414d55);
    if (lVar2 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                &WPP_882c5dbd4c393422b71f4ab343c3933e_Traceguids);
      }
      iVar1 = -0x3fffff66;
      goto LAB_14002232c;
    }
    iVar1 = USBSTOR_1667SendSecurityProtocolIn
                      (param_1,param_2,param_3,puVar7,in_stack_ffffffffffffffa8,local_res20,lVar2);
    if (-1 < iVar1) goto LAB_140022246;
  }
  ExFreePoolWithTag(lVar2,0);
LAB_14002232c:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
             &WPP_882c5dbd4c393422b71f4ab343c3933e_Traceguids,iVar1);
  }
  return uVar8;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 140022388 =====

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



===== USBSTOR_GetStateSeparationLocation @ 140022454 =====

int USBSTOR_GetStateSeparationLocation(void)

{
  int iVar1;
  longlong lVar2;
  wchar_t *_Dst;
  undefined2 uVar3;
  uint uVar4;
  ulonglong in_RDX;
  int in_R9D;
  ulonglong local_res10;
  undefined8 *in_stack_00000028;
  
  local_res10 = in_RDX & 0xffffffff00000000;
  _Dst = (wchar_t *)0x0;
  iVar1 = RtlGetPersistedStateLocation
                    (L"USBStor",0,
                     L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\usbstor",0,0,0,
                     &local_res10);
  if (-1 < iVar1) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_8c8e2bcf66043dde3d33f256d9bd74b7_Traceguids);
    }
    return -0x3fffffff;
  }
  if (iVar1 != -0x7ffffffb) {
    return iVar1;
  }
  lVar2 = ExAllocatePool2(0x100,local_res10 & 0xffffffff,0x53414d55);
  if (lVar2 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_8c8e2bcf66043dde3d33f256d9bd74b7_Traceguids);
    }
    return -0x3fffff66;
  }
  iVar1 = RtlGetPersistedStateLocation
                    (L"USBStor",0,
                     L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\usbstor",0,lVar2,
                     (int)local_res10,0);
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_140022696;
    uVar3 = 0xc;
  }
  else {
    uVar4 = (int)local_res10 + 2 + in_R9D;
    _Dst = (wchar_t *)ExAllocatePool2(0x100,uVar4,0x53414d55);
    if (_Dst == (wchar_t *)0x0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                &WPP_8c8e2bcf66043dde3d33f256d9bd74b7_Traceguids);
      }
      iVar1 = -0x3fffff66;
      goto LAB_140022696;
    }
    iVar1 = swprintf_s(_Dst,(ulonglong)(uVar4 >> 1),L"%s\\%s");
    if (-1 < iVar1) {
      *in_stack_00000028 = _Dst;
      _Dst = (wchar_t *)0x0;
      goto LAB_140022696;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_140022696;
    uVar3 = 0xe;
  }
  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
          &WPP_8c8e2bcf66043dde3d33f256d9bd74b7_Traceguids);
LAB_140022696:
  ExFreePoolWithTag(lVar2,0);
  if (_Dst != (wchar_t *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
  return iVar1;
}



===== PortAvioGetBcProperties @ 1400226dc =====

undefined8 PortAvioGetBcProperties(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  
  uVar5 = 0;
  puVar4 = (undefined8 *)0x0;
  if (0x1f < *(uint *)(*(longlong *)(param_2 + 0xb8) + 8)) {
    puVar4 = *(undefined8 **)(param_2 + 0x18);
  }
  if (puVar4 == (undefined8 *)0x0) {
    uVar2 = 0xc000000d;
  }
  else {
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    puVar4[3] = 0;
    *(undefined4 *)((longlong)puVar4 + 4) = *(undefined4 *)(param_1 + 0x18);
    *(undefined4 *)puVar4 = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(puVar4 + 2) = 10;
    puVar4[1] = 0x10000;
    lVar3 = IoGetSfioStreamIdentifier(*(undefined8 *)(param_2 + 0xc0),param_1);
    if (lVar3 == 0) {
      iVar1 = 0;
    }
    else {
      uVar5 = 0x10000;
      iVar1 = *(int *)(lVar3 + 0x10) * 2;
    }
    *(int *)((longlong)puVar4 + 0x14) = iVar1;
    uVar2 = 0;
    puVar4[3] = uVar5;
    *(undefined8 *)(param_2 + 0x38) = 0x20;
  }
  return uVar2;
}



===== USBSTOR_DeviceControl @ 140022790 =====

ulonglong USBSTOR_DeviceControl(longlong param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  if (**(int **)(param_1 + 0x40) == 0x214f4450) {
    lVar1 = *(longlong *)(*(longlong *)(*(int **)(param_1 + 0x40) + 4) + 0x40);
    uVar2 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x18);
    if (uVar2 == 0x4d014) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
      }
      uVar3 = USBSTOR_SendPassThrough(param_1,param_2,'\x01');
      uVar3 = uVar3 & 0xffffffff;
      goto LAB_1400227fe;
    }
    if (uVar2 == 0x2d1400) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
      }
      uVar2 = USBSTOR_QueryProperty(param_1,param_2);
      uVar3 = (ulonglong)uVar2;
      goto LAB_1400227fe;
    }
    if (uVar2 < 0x2d1c81) {
      if (uVar2 == 0x2d1c80) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                  &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
        }
        uVar2 = USBSTOR_EnableIdlePower(param_1,param_2);
        uVar3 = (ulonglong)uVar2;
        goto LAB_1400227fe;
      }
      if (uVar2 < 0x41025) {
        if (uVar2 == 0x41024) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                    &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
          }
          uVar2 = USBSTOR_FreeDumpPointers(param_1,param_2);
          uVar3 = (ulonglong)uVar2;
          goto LAB_1400227fe;
        }
        if (uVar2 == 0x41010) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                    &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
          }
          uVar2 = USBSTOR_ScsiCapabilities(param_1,param_2);
          uVar3 = (ulonglong)uVar2;
          goto LAB_1400227fe;
        }
        if (uVar2 == 0x41018) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                    &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
          }
          uVar2 = USBSTOR_ScsiAddress(param_1,param_2);
          uVar3 = (ulonglong)uVar2;
          goto LAB_1400227fe;
        }
        if (uVar2 == 0x41020) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                    &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
          }
          uVar2 = USBSTOR_GetDumpPointers(param_1,param_2);
          uVar3 = (ulonglong)uVar2;
          goto LAB_1400227fe;
        }
      }
      else {
        if (uVar2 == 0x4d004) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                    &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
          }
          uVar3 = USBSTOR_SendPassThrough(param_1,param_2,'\0');
          uVar3 = uVar3 & 0xffffffff;
          goto LAB_1400227fe;
        }
        if (uVar2 == 0x2d0c10) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                    &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
          }
          *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
          *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
          uVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 0x18),param_2);
          uVar3 = (ulonglong)uVar2;
          goto LAB_1400227fe;
        }
      }
    }
    else {
      if (uVar2 == 0x2d1c88) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                  &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
        }
        uVar2 = USBSTOR_PowerActiveIdle(param_1,param_2,'\x01');
        uVar3 = (ulonglong)uVar2;
        goto LAB_1400227fe;
      }
      if (uVar2 == 0x2d1c8c) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                  &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
        }
        uVar2 = USBSTOR_PowerActiveIdle(param_1,param_2,'\0');
        uVar3 = (ulonglong)uVar2;
        goto LAB_1400227fe;
      }
      if (uVar2 == 0x2d5800) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                  &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
        }
        uVar2 = USBSTOR_GetBcProperties(param_1,param_2);
        uVar3 = (ulonglong)uVar2;
        goto LAB_1400227fe;
      }
      if (uVar2 == 0x2dd804) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                  &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
        }
        uVar2 = USBSTOR_AllocBcStream(param_1,param_2);
        uVar3 = (ulonglong)uVar2;
        goto LAB_1400227fe;
      }
      if (uVar2 == 0x2dd808) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                  &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
        }
        uVar2 = USBSTOR_FreeBcStream(param_1,param_2);
        uVar3 = (ulonglong)uVar2;
        goto LAB_1400227fe;
      }
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (2 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
               &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,uVar2);
    }
  }
  else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  uVar3 = 0xc00000bb;
  *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
  IofCompleteRequest(param_2,0);
LAB_1400227fe:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,(int)uVar3);
  }
  return uVar3;
}



===== USBSTOR_SendPassThrough @ 140022d80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong USBSTOR_SendPassThrough(longlong param_1,longlong param_2,char param_3)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined2 *_Dst;
  longlong lVar7;
  char *pcVar8;
  char cVar9;
  uint uVar10;
  undefined4 uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  undefined1 auStackY_f8 [32];
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  uint local_90;
  longlong local_88;
  ushort local_80;
  undefined1 uStack_7e;
  undefined1 uStack_7d;
  undefined1 uStack_7c;
  undefined1 uStack_7b;
  byte bStack_7a;
  byte bStack_79;
  undefined4 uStack_78;
  undefined2 uStack_74;
  undefined1 uStack_72;
  undefined1 uStack_71;
  int iStack_70;
  undefined4 uStack_6c;
  ulonglong uStack_68;
  uint local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_f8;
  local_88 = param_1;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  local_a8 = 0;
  uStack_a0 = 0;
  lVar6 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10) + 0x40);
  uVar4 = *(uint *)(lVar6 + 0x718);
  local_90 = *(uint *)(lVar6 + 0x71c);
  local_98 = 0;
  KeInitializeEvent(&local_a8,0,0);
  local_50 = 0;
  local_80 = 0;
  uStack_7e = 0;
  uStack_7d = 0;
  uStack_7c = 0;
  uStack_7b = 0;
  bStack_7a = 0;
  bStack_79 = 0;
  uStack_78 = 0;
  uStack_74 = 0;
  uStack_72 = 0;
  uStack_71 = 0;
  iStack_70 = 0;
  uStack_6c = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_5c = 0;
  uStack_58 = 0;
  uStack_54 = 0;
  uVar5 = PortPassThroughNormalize((undefined8 *)&local_80,param_2);
  uVar13 = uStack_68;
  uVar12 = uVar5 & 0xffffffff;
  uVar2 = CONCAT13(uStack_71,CONCAT12(uStack_72,uStack_74));
  cVar9 = (char)uStack_78;
  if (-1 < (int)uVar5) {
    uVar5 = (ulonglong)*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10);
    uVar1 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
    if ((bStack_7a < 0x11) &&
       ((bStack_79 == 0 ||
        ((((uVar10 = bStack_79 + local_60, local_60 <= uVar10 && (local_80 <= local_60)) &&
          ((((param_3 != '\0' || (uVar2 == 0)) || ((local_60 < uStack_68 && (uVar10 <= uStack_68))))
           && (local_60 <= uVar1)))) && (uVar10 <= uVar1)))))) {
      if (param_3 == '\0') {
        if ((((local_80 <= uStack_68) || (uVar2 == 0)) &&
            (((cVar9 == '\x01' || (uVar2 == 0)) ||
             ((uStack_68 <= uVar5 && (uVar2 + uStack_68 <= uVar5)))))) &&
           ((cVar9 == '\0' ||
            ((uVar2 == 0 || ((uStack_68 <= uVar1 && (uVar2 + uStack_68 <= (ulonglong)uVar1))))))))
        goto LAB_140023135;
      }
      else if ((uStack_68 != 0) || (uVar2 == 0)) {
LAB_140023135:
        if (iStack_70 - 1U < 0x1a5e0) {
          if (((char)uStack_5c == '\x18') || ((byte)((char)uStack_5c - 0x39U) < 2)) {
            uVar12 = 0xc0000010;
            *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
            PortpSyncCompletion(param_2,&local_a8);
            goto LAB_140023088;
          }
          uVar12 = 0;
          PortpPassThroughZeroUnusedBuffers(param_2);
          if (uVar2 == 0) {
            uVar5 = 0;
          }
          else if (param_3 == '\0') {
            uVar5 = *(longlong *)(param_2 + 0x18) + uVar13;
          }
          else {
            uVar5 = uVar13;
          }
          if (((uVar5 & *(uint *)(param_1 + 0x98)) == 0) &&
             ((uVar2 == 0 ||
              (((uint)((ulonglong)((uint)uVar5 & 0xfff) + (ulonglong)uVar2 + 0xfff >> 0xc) <=
                local_90 && (uVar2 <= uVar4)))))) {
            cVar9 = (char)uStack_78;
            goto LAB_1400231b9;
          }
        }
      }
    }
    uVar12 = 0xc000000d;
    *(undefined4 *)(param_2 + 0x30) = 0xc000000d;
    PortpSyncCompletion(param_2,&local_a8);
    goto LAB_140023088;
  }
LAB_1400231b9:
  if ((int)uVar12 < 0) {
LAB_140023244:
    *(int *)(param_2 + 0x30) = (int)uVar12;
    PortpSyncCompletion(param_2,&local_a8);
    if ((int)uVar12 != 0x103) goto LAB_140023088;
LAB_140023065:
    KeWaitForSingleObject(&local_a8,0,0,0);
    uVar12 = (ulonglong)*(uint *)(param_2 + 0x30);
  }
  else {
    if (uVar2 == 0) {
      uVar13 = 0;
      if (param_3 == '\0') goto LAB_1400231d6;
LAB_140022eae:
      cVar3 = *(char *)(param_2 + 0x40);
    }
    else {
      if (param_3 != '\0') goto LAB_140022eae;
      uVar13 = uVar13 + *(longlong *)(param_2 + 0x18);
LAB_1400231d6:
      cVar3 = '\0';
    }
    lVar6 = PortPassThroughBuildIrpEx(param_1,uVar13,uVar2,cVar9 != '\0',cVar3,param_2);
    if (lVar6 != 0) {
      lVar7 = 0;
      _Dst = (undefined2 *)ExAllocatePool2(0x40,0x58,0x69506c50);
      if (_Dst != (undefined2 *)0x0) {
        if ((bStack_79 == 0) || (lVar7 = ExAllocatePool2(0x48,bStack_79,0x69506c50), lVar7 != 0)) {
          memset(_Dst,0,0x58);
          *(undefined1 *)((longlong)_Dst + 5) = uStack_7d;
          *(undefined1 *)(_Dst + 3) = uStack_7c;
          *(undefined1 *)((longlong)_Dst + 7) = uStack_7b;
          *(byte *)((longlong)_Dst + 0xb) = bStack_79;
          *_Dst = 0x58;
          *(byte *)(_Dst + 5) = bStack_7a;
          if (uVar2 == 0) {
            uVar4 = 0;
          }
          else if ((char)uStack_78 == '\0') {
            uVar4 = 0x80;
          }
          else if ((char)uStack_78 == '\x01') {
            uVar4 = 0x40;
          }
          else {
            uVar4 = 0xc0;
          }
          if (lVar7 == 0) {
            uVar4 = uVar4 | 0x20;
          }
          *(uint *)(_Dst + 6) = uVar4 | 0x100;
          *(int *)(_Dst + 10) = iStack_70;
          *(uint *)(_Dst + 8) = uVar2;
          *(ulonglong *)(_Dst + 0xc) = uVar13;
          *(longlong *)(_Dst + 0x10) = lVar7;
          memmove(_Dst + 0x24,&uStack_5c,(ulonglong)bStack_7a);
          *(undefined2 **)(*(longlong *)(lVar6 + 0xb8) + -0x40) = _Dst;
          *(longlong *)(_Dst + 0x18) = lVar6;
          pcVar8 = (char *)ExAllocatePool2(0x40,0x30,0x69506c50);
          if (pcVar8 == (char *)0x0) {
            uVar12 = 0xc000009a;
LAB_14002335b:
            PortPassThroughFreeIrpEx(lVar6);
            PortPassThroughFreeSrb((longlong)_Dst);
            if (pcVar8 != (char *)0x0) {
              ExFreePoolWithTag(pcVar8,0x69506c50);
            }
            goto LAB_140023244;
          }
          *(undefined2 **)(pcVar8 + 0x18) = _Dst;
          *(longlong *)(pcVar8 + 8) = lVar6;
          *pcVar8 = param_3;
          *(longlong *)(pcVar8 + 0x10) = param_2;
          *(code **)(pcVar8 + 0x20) = PortpSyncCompletion;
          *(undefined8 **)(pcVar8 + 0x28) = &local_a8;
          lVar7 = *(longlong *)(lVar6 + 0xb8);
          *(code **)(lVar7 + -0x10) = PortpAsyncCompletion;
          *(char **)(lVar7 + -8) = pcVar8;
          *(undefined1 *)(lVar7 + -0x45) = 0xe0;
          uVar13 = PortpEnableCancel(param_2,(longlong)pcVar8);
          uVar12 = uVar13 & 0xffffffff;
          if ((int)uVar13 != 0x103) goto LAB_14002335b;
          IofCallDriver(local_88,lVar6);
          goto LAB_140023065;
        }
        ExFreePoolWithTag(_Dst,0x69506c50);
      }
      PortPassThroughFreeIrpEx(lVar6);
    }
    uVar12 = 0xc000009a;
    *(undefined4 *)(param_2 + 0x30) = 0xc000009a;
    PortpSyncCompletion(param_2,&local_a8);
  }
LAB_140023088:
  uVar11 = (undefined4)uVar12;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,uVar11);
  }
  *(undefined4 *)(param_2 + 0x30) = uVar11;
  IofCompleteRequest(param_2,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,uVar11);
  }
  return uVar12;
}



===== USBSTOR_QueryProperty @ 1400233f0 =====

int USBSTOR_QueryProperty(longlong param_1,longlong param_2)

{
  uint *puVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  uint uVar5;
  uint local_res10 [2];
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  puVar1 = *(uint **)(param_2 + 0x18);
  local_res10[0] = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0xc) {
    iVar2 = -0x3ffffff3;
    uVar3 = 0;
    goto LAB_14002343b;
  }
  uVar5 = *puVar1;
  if (uVar5 == 0) {
    uVar5 = puVar1[1];
    if (uVar5 == 0) {
      uVar4 = USBSTOR_BuildDeviceDescriptor(param_1,puVar1,local_res10);
      iVar2 = (int)uVar4;
      goto LAB_140023497;
    }
  }
  else if (uVar5 == 1) {
    uVar5 = puVar1[1];
    if (uVar5 == 0) {
      uVar4 = USBSTOR_BuildAdapterDescriptor(param_1,puVar1,local_res10);
      iVar2 = (int)uVar4;
      uVar3 = (ulonglong)local_res10[0];
      goto LAB_14002343b;
    }
  }
  else if (uVar5 == 5) {
    uVar5 = puVar1[1];
    if (uVar5 == 0) {
      iVar2 = USBSTOR_BuildMiniportDescriptor(0,puVar1,local_res10);
LAB_140023497:
      uVar3 = (ulonglong)local_res10[0];
      goto LAB_14002343b;
    }
  }
  else if (uVar5 == 6) {
    uVar5 = puVar1[1];
    if (uVar5 == 0) {
      iVar2 = USBSTOR_BuildAlignmentDescriptor(param_1,puVar1,local_res10);
      goto LAB_140023497;
    }
  }
  else {
    if (uVar5 != 0xc) {
      iVar2 = -0x3fffff11;
      uVar3 = 0;
      goto LAB_14002343b;
    }
    uVar5 = puVar1[1];
    if (uVar5 == 0) {
      uVar4 = USBSTOR_BuildPowerDescriptor(param_1,puVar1,local_res10);
      iVar2 = (int)uVar4;
      goto LAB_140023497;
    }
  }
  iVar2 = 0;
  uVar3 = 0;
  if (uVar5 != 1) {
    iVar2 = -0x3fffff10;
  }
LAB_14002343b:
  *(int *)(param_2 + 0x30) = iVar2;
  *(ulonglong *)(param_2 + 0x38) = uVar3;
  IofCompleteRequest(param_2,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar2);
  }
  return iVar2;
}



===== USBSTOR_BuildDeviceDescriptor @ 1400235a0 =====

undefined8 USBSTOR_BuildDeviceDescriptor(longlong param_1,void *param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  size_t sVar7;
  undefined4 local_58;
  int local_54;
  byte local_50;
  byte local_4f;
  byte local_4e;
  undefined8 local_4d;
  undefined8 uStack_45;
  undefined1 local_3d;
  undefined4 local_3c;
  undefined8 local_38;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  uVar1 = *param_3;
  lVar3 = *(longlong *)(param_1 + 0x40);
  memset(param_2,0,(ulonglong)uVar1);
  local_3d = 0;
  local_38 = 0;
  local_58 = 0x28;
  local_54 = 0x67;
  local_4d = 0;
  uStack_45 = 0;
  if (*(int *)(lVar3 + 0x40) != 0) {
    local_54 = *(int *)(lVar3 + 0x40) + 0x68;
  }
  local_50 = *(byte *)(lVar3 + 0x48) & 0x1f;
  local_3c = 7;
  local_4f = *(byte *)(lVar3 + 0x49) & 0x7f;
  local_4e = *(byte *)(lVar3 + 0x49) >> 7;
  uVar4 = 0x24;
  if ((int)uVar1 < 0x24) {
    uVar4 = uVar1;
  }
  memmove(param_2,&local_58,(longlong)(int)uVar4);
  uVar4 = uVar1 - 0x24;
  if (0 < (int)uVar4) {
    sVar7 = (size_t)uVar4;
    if (0x23 < (int)uVar4) {
      sVar7 = 0x24;
    }
    *(int *)((longlong)param_2 + 0x20) = (int)sVar7;
    memmove((void *)((longlong)param_2 + 0x24),(void *)(lVar3 + 0x48),sVar7);
    iVar6 = uVar1 - 0x48;
    if (0 < iVar6) {
      sVar7 = 8;
      if ((ulonglong)(longlong)iVar6 < 8) {
        sVar7 = (longlong)iVar6;
      }
      memmove((void *)((longlong)param_2 + 0x48),(void *)(lVar3 + 0x50),sVar7);
      iVar6 = uVar1 - 0x51;
      if (-1 < iVar6) {
        *(undefined4 *)((longlong)param_2 + 0xc) = 0x48;
      }
      if (0 < iVar6) {
        sVar7 = 0x10;
        if ((ulonglong)(longlong)iVar6 < 0x10) {
          sVar7 = (longlong)iVar6;
        }
        memmove((void *)((longlong)param_2 + 0x51),(void *)(lVar3 + 0x58),sVar7);
        iVar6 = uVar1 - 0x62;
        if (-1 < iVar6) {
          *(undefined4 *)((longlong)param_2 + 0x10) = 0x51;
        }
        if (0 < iVar6) {
          sVar7 = 4;
          if ((ulonglong)(longlong)iVar6 < 4) {
            sVar7 = (longlong)iVar6;
          }
          memmove((void *)((longlong)param_2 + 0x62),(void *)(lVar3 + 0x68),sVar7);
          iVar6 = uVar1 - 0x67;
          if (-1 < iVar6) {
            *(undefined4 *)((longlong)param_2 + 0x14) = 0x62;
          }
          *(undefined4 *)((longlong)param_2 + 0x18) = 0;
          if (0 < iVar6) {
            iVar2 = *(int *)(lVar3 + 0x40);
            if (iVar2 == 0) {
              *param_3 = 0x67;
            }
            else {
              iVar5 = iVar6;
              if (iVar2 <= iVar6) {
                iVar5 = iVar2;
              }
              memmove((void *)((longlong)param_2 + 0x67),(void *)(lVar3 + 0x6c),(longlong)iVar5);
              iVar6 = iVar6 + (-1 - *(int *)(lVar3 + 0x40));
              if (-1 < iVar6) {
                *(int *)((longlong)param_2 + 0x18) =
                     (int)(void *)((longlong)param_2 + 0x67) - (int)param_2;
                *param_3 = uVar1 - iVar6;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}



===== USBSTOR_ScsiAddress @ 1400237dc =====

undefined4 USBSTOR_ScsiAddress(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xcc,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  uVar3 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (uVar3 < 8) {
    uVar4 = 0xc0000023;
  }
  else {
    lVar1 = *(longlong *)(param_1 + 0x40);
    puVar2 = *(undefined8 **)(param_2 + 0x18);
    uVar3 = 8;
    uVar4 = 0;
    *puVar2 = 0;
    *(undefined4 *)puVar2 = 8;
    *(undefined1 *)((longlong)puVar2 + 7) = *(undefined1 *)(lVar1 + 0x47);
  }
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar3;
  *(undefined4 *)(param_2 + 0x30) = uVar4;
  IofCompleteRequest(param_2,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xcd,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,uVar4);
  }
  return uVar4;
}



===== USBSTOR_BuildAdapterDescriptor @ 1400238d4 =====

undefined8 USBSTOR_BuildAdapterDescriptor(longlong param_1,undefined4 *param_2,uint *param_3)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined1 local_20;
  undefined1 local_1f;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  
  local_34 = 0;
  local_1f = 0;
  local_1a = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  uVar1 = *param_3;
  lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10) + 0x40);
  if (uVar1 < 8) {
    *param_3 = 0x20;
    uVar3 = 0xc0000023;
  }
  else {
    uVar4 = 0x1e;
    if (uVar1 < 0x1e) {
      *param_2 = 0x20;
      param_2[1] = 0x20;
      *param_3 = 8;
    }
    else {
      if (uVar1 < 0x20) {
        local_38 = 0x1e;
        local_34 = 0x1e;
      }
      else {
        local_38 = 0x20;
        uVar4 = 0x20;
        local_34 = 0x20;
      }
      local_30 = *(undefined4 *)(lVar2 + 0x718);
      local_2c = *(undefined4 *)(lVar2 + 0x71c);
      local_1e = 2;
      local_28 = 0;
      local_20 = 7;
      if (*(char *)(lVar2 + 0x715) == '\0') {
        local_1e = 1;
      }
      *param_3 = uVar4;
      local_1c = 0;
      memmove(param_2,&local_38,(ulonglong)uVar4);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                 &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,0);
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}



===== USBSTOR_Create @ 140023a30 =====

undefined8 USBSTOR_Create(undefined8 param_1,longlong param_2)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_83961903f8913993eee34094953b83c3_Traceguids);
  }
  USBSTOR_LogEntry(0x41455243,param_1,param_2,0);
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
            &WPP_83961903f8913993eee34094953b83c3_Traceguids);
  }
  USBSTOR_LogEntry(0x61657263,0,0,0);
  return 0;
}



===== USBSTOR_Close @ 140023b10 =====

undefined8 USBSTOR_Close(undefined8 param_1,longlong param_2)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
            &WPP_83961903f8913993eee34094953b83c3_Traceguids);
  }
  USBSTOR_LogEntry(0x534f4c43,param_1,param_2,0);
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
            &WPP_83961903f8913993eee34094953b83c3_Traceguids);
  }
  USBSTOR_LogEntry(0x736f6c63,0,0,0);
  return 0;
}



===== USBSTOR_PdoQueryHardwareIds @ 140023be8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int USBSTOR_PdoQueryHardwareIds
              (longlong param_1,ulonglong *param_2,undefined8 param_3,char *param_4)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  undefined8 uVar7;
  longlong lVar8;
  ulonglong uVar9;
  longlong *plVar10;
  ulonglong uVar11;
  char *pcVar12;
  longlong lVar13;
  uint uVar14;
  undefined1 auStack_158 [48];
  ulonglong *local_128;
  longlong local_118 [10];
  char local_c8 [127];
  undefined1 local_49;
  ulonglong local_48 [2];
  
  local_48[0] = __security_cookie ^ (ulonglong)auStack_158;
  uVar11 = 0;
  local_128 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x86,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x40);
  memset(local_118,0,0x48);
  pcVar4 = USBSTOR_PdoDeviceTypeString(param_1);
  pcVar5 = USBSTOR_PdoGenericTypeString(param_1);
  uVar14 = 0;
  do {
    if (7 < uVar14) {
      iVar3 = USBSTOR_StringArrayToMultiSz(local_128,local_118);
LAB_140024002:
      if ((int)uVar11 != 0) {
        plVar10 = local_118;
        do {
          if (*plVar10 != 0) {
            ExFreePoolWithTag(*plVar10,0);
          }
          plVar10 = plVar10 + 1;
          uVar11 = uVar11 - 1;
        } while (uVar11 != 0);
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x87,
                 &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar3);
      }
      return iVar3;
    }
    memset(local_c8,0,0x80);
    if (uVar14 == 0) {
      uVar7 = 0x80;
      RtlStringCbPrintfA(local_c8,0x80,"USBSTOR\\%s",pcVar4);
      AppendField((longlong)local_c8,uVar7,lVar1 + 0x50,8);
      AppendField((longlong)local_c8,uVar7,lVar1 + 0x58,0x10);
      lVar13 = lVar1 + 0x68;
      param_4 = (char *)0x4;
LAB_140023f42:
      AppendField((longlong)local_c8,uVar7,lVar13,(uint)param_4);
LAB_140023f4b:
      lVar13 = -1;
      do {
        lVar8 = lVar13;
        lVar13 = lVar8 + 1;
      } while (local_c8[lVar8 + 1] != '\0');
      if (lVar8 + 1 != 0) {
        uVar9 = lVar8 + 2;
        pcVar12 = (char *)ExAllocatePool2(0x100,uVar9,0x53414d55);
        local_118[uVar11] = (longlong)pcVar12;
        if (pcVar12 == (char *)0x0) {
          iVar3 = -0x3fffff66;
          goto LAB_140024002;
        }
        if (uVar9 != 0) {
          pcVar6 = pcVar12;
          if (uVar9 < 0x80000000) {
            lVar8 = 0x7ffffffe - uVar9;
            lVar13 = -(longlong)pcVar12;
            do {
              if ((lVar8 + uVar9 == 0) || (pcVar12[(longlong)(local_c8 + lVar13)] == '\0')) break;
              *pcVar12 = pcVar12[(longlong)(local_c8 + lVar13)];
              pcVar12 = pcVar12 + 1;
              uVar9 = uVar9 - 1;
            } while (uVar9 != 0);
            pcVar6 = pcVar12 + -1;
            if (uVar9 != 0) {
              pcVar6 = pcVar12;
            }
          }
          *pcVar6 = '\0';
        }
        uVar11 = (ulonglong)((int)uVar11 + 1);
      }
    }
    else {
      if (uVar14 == 1) {
        uVar7 = 0x80;
        RtlStringCbPrintfA(local_c8,0x80,"USBSTOR\\%s",pcVar4);
        AppendField((longlong)local_c8,uVar7,lVar1 + 0x50,8);
        lVar13 = lVar1 + 0x58;
        param_4 = (char *)0x10;
        goto LAB_140023f42;
      }
      if (uVar14 == 2) {
        uVar7 = 0x80;
        RtlStringCbPrintfA(local_c8,0x80,"USBSTOR\\%s",pcVar4);
        lVar13 = lVar1 + 0x50;
        param_4 = (char *)0x8;
        goto LAB_140023f42;
      }
      if (uVar14 == 3) {
        RtlStringCbPrintfA(local_c8,0x80,"USBSTOR\\",param_4);
LAB_140023d30:
        uVar9 = 8;
        if (lVar1 + 0x50 != 0) {
          local_49 = 0;
          lVar13 = -1;
          do {
            lVar8 = lVar13;
            lVar13 = lVar8 + 1;
          } while (local_c8[lVar8 + 1] != '\0');
          pcVar12 = local_c8 + lVar8 + 1;
          if ((ulonglong)((longlong)local_48 - (longlong)pcVar12) < 9) {
            uVar9 = (ulonglong)(uint)((int)local_48 - (int)pcVar12);
          }
          param_4 = (char *)((ulonglong)param_4 & 0xffffffffffffff00);
          if ((int)uVar9 != 0) {
            lVar13 = (lVar1 + 0x50) - (longlong)pcVar12;
            do {
              if ((char)param_4 == '\0') {
                cVar2 = pcVar12[lVar13];
                if (cVar2 == '\0') {
                  param_4 = (char *)CONCAT71((int7)((ulonglong)param_4 >> 8),1);
                  goto LAB_140023d91;
                }
                if (cVar2 == ' ') {
                  cVar2 = '_';
                }
              }
              else {
LAB_140023d91:
                cVar2 = '_';
              }
              *pcVar12 = cVar2;
              pcVar12 = pcVar12 + 1;
              uVar9 = uVar9 - 1;
            } while (uVar9 != 0);
          }
        }
        uVar9 = 0x10;
        if (lVar1 + 0x58 != 0) {
          local_49 = 0;
          lVar13 = -1;
          do {
            lVar8 = lVar13;
            lVar13 = lVar8 + 1;
          } while (local_c8[lVar8 + 1] != '\0');
          pcVar12 = local_c8 + lVar8 + 1;
          if ((ulonglong)((longlong)local_48 - (longlong)pcVar12) < 0x11) {
            uVar9 = (ulonglong)(uint)((int)local_48 - (int)pcVar12);
          }
          param_4 = (char *)((ulonglong)param_4 & 0xffffffffffffff00);
          if ((int)uVar9 != 0) {
            lVar13 = (lVar1 + 0x58) - (longlong)pcVar12;
            do {
              if ((char)param_4 == '\0') {
                cVar2 = pcVar12[lVar13];
                if (cVar2 == '\0') {
                  param_4 = (char *)CONCAT71((int7)((ulonglong)param_4 >> 8),1);
                  goto LAB_140023dfb;
                }
                if (cVar2 == ' ') {
                  cVar2 = '_';
                }
              }
              else {
LAB_140023dfb:
                cVar2 = '_';
              }
              *pcVar12 = cVar2;
              pcVar12 = pcVar12 + 1;
              uVar9 = uVar9 - 1;
            } while (uVar9 != 0);
          }
        }
        uVar9 = 1;
        if (lVar1 + 0x68 != 0) {
          local_49 = 0;
          lVar13 = -1;
          do {
            lVar8 = lVar13;
            lVar13 = lVar8 + 1;
          } while (local_c8[lVar8 + 1] != '\0');
          pcVar12 = local_c8 + lVar8 + 1;
          if ((ulonglong)((longlong)local_48 - (longlong)pcVar12) < 2) {
            uVar9 = (ulonglong)(uint)((int)local_48 - (int)pcVar12);
          }
          param_4 = (char *)((ulonglong)param_4 & 0xffffffffffffff00);
          if ((int)uVar9 != 0) {
            lVar13 = (lVar1 + 0x68) - (longlong)pcVar12;
            do {
              if ((char)param_4 == '\0') {
                cVar2 = pcVar12[lVar13];
                if (cVar2 == '\0') {
                  param_4 = (char *)CONCAT71((int7)((ulonglong)param_4 >> 8),1);
                  goto LAB_140023e69;
                }
                if (cVar2 == ' ') {
                  cVar2 = '_';
                }
              }
              else {
LAB_140023e69:
                cVar2 = '_';
              }
              *pcVar12 = cVar2;
              pcVar12 = pcVar12 + 1;
              uVar9 = uVar9 - 1;
            } while (uVar9 != 0);
          }
        }
        goto LAB_140023f4b;
      }
      if (uVar14 == 4) goto LAB_140023d30;
      if (uVar14 != 5) {
        if (uVar14 == 6) {
          pcVar12 = "USBSTOR\\%s";
          param_4 = pcVar5;
LAB_140023d08:
          RtlStringCbPrintfA(local_c8,0x80,pcVar12,param_4);
        }
        else if (uVar14 == 7) {
          pcVar12 = "%s";
          param_4 = pcVar5;
          goto LAB_140023d08;
        }
        goto LAB_140023f4b;
      }
      if (*(char *)(lVar1 + 0x46) != '\0') {
        pcVar12 = "%s1667";
        param_4 = pcVar4;
        goto LAB_140023d08;
      }
    }
    uVar14 = uVar14 + 1;
  } while( true );
}



===== USBSTOR_Pnp @ 1400240a0 =====

uint USBSTOR_Pnp(longlong param_1,undefined *param_2)

{
  byte bVar1;
  int *piVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  undefined8 uVar6;
  char *pcVar7;
  undefined *puVar8;
  
  piVar2 = *(int **)(param_1 + 0x40);
  lVar3 = *(longlong *)(param_2 + 0xb8);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar8 = WPP_GLOBAL_Control;
    pcVar7 = PnPMinorFunctionString(*(byte *)(lVar3 + 1));
    WPP_SF_s(*(undefined8 *)(puVar8 + 0x18),0x32,puVar8,pcVar7);
  }
  USBSTOR_LogEntry(0x20504e50,param_1,param_2,(ulonglong)*(byte *)(lVar3 + 1));
  lVar4 = *(longlong *)(param_1 + 0x40);
  bVar1 = *(byte *)(lVar3 + 1);
  if (*piVar2 == 0x214f4446) {
    if (bVar1 == 9) {
      uVar5 = USBSTOR_FdoQueryCapabilities(param_1,(longlong)param_2);
    }
    else if (bVar1 == 7) {
      uVar5 = USBSTOR_FdoQueryDeviceRelations(param_1,(longlong)param_2);
    }
    else {
      switch(bVar1) {
      case 0:
        uVar5 = USBSTOR_FdoStartDevice(param_1,(longlong)param_2);
        break;
      case 1:
      case 5:
        uVar5 = USBSTOR_FdoQueryStopRemoveDevice(param_1,(longlong)param_2);
        break;
      case 2:
        uVar5 = USBSTOR_FdoRemoveDevice(param_1,(longlong)param_2);
        break;
      case 3:
      case 6:
        uVar5 = USBSTOR_FdoCancelStopRemoveDevice(param_1,(longlong)param_2);
        break;
      case 4:
        uVar5 = USBSTOR_FdoStopDevice(param_1,(longlong)param_2);
        break;
      case 0x16:
        uVar5 = USBSTOR_FdoDeviceUsageNotification(param_1,(longlong)param_2);
        break;
      case 0x17:
        *(undefined4 *)(param_2 + 0x30) = 0;
      default:
        param_2[0x43] = param_2[0x43] + '\x01';
        *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
        uVar5 = IofCallDriver(*(undefined8 *)(lVar4 + 0x18),param_2);
      }
    }
    goto LAB_14002411b;
  }
  if (bVar1 == 0) {
    uVar5 = USBSTOR_PdoStartDevice(param_1,(longlong)param_2);
    goto LAB_14002411b;
  }
  if (bVar1 == 7) {
    uVar5 = USBSTOR_PdoQueryDeviceRelations(param_1,(longlong)param_2);
    goto LAB_14002411b;
  }
  switch(bVar1) {
  case 1:
  case 5:
    uVar5 = USBSTOR_PdoQueryStopRemoveDevice(param_1,(longlong)param_2);
    break;
  case 2:
    if (*(int *)(lVar4 + 0x28) != 8) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
                &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
      }
      puVar8 = param_2;
      USBSTOR_LogEntry(0x20564452,param_1,param_2,0);
      UsbQueueFlush(param_1,(uint *)(lVar4 + 0x170),puVar8);
      uVar6 = USBSTOR_PdoRemoveDevice(param_1,(longlong)param_2,puVar8);
      uVar5 = (uint)uVar6;
      break;
    }
    goto LAB_140024276;
  case 4:
    uVar6 = USBSTOR_PdoStopDevice(param_1,(longlong)param_2);
    uVar5 = (uint)uVar6;
    break;
  default:
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (2 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      puVar8 = WPP_GLOBAL_Control;
      pcVar7 = PnPMinorFunctionString(bVar1);
      WPP_SF_s(*(undefined8 *)(puVar8 + 0x18),0x36,puVar8,pcVar7);
    }
    uVar5 = *(uint *)(param_2 + 0x30);
    goto LAB_14002427d;
  case 9:
    uVar5 = USBSTOR_PdoQueryCapabilities(param_1,(longlong)param_2);
    break;
  case 0xc:
    uVar5 = USBSTOR_PdoQueryDeviceText(param_1,(longlong)param_2);
    break;
  case 0x13:
    uVar5 = USBSTOR_PdoQueryID(param_1,(longlong)param_2);
    break;
  case 0x14:
    uVar6 = USBSTOR_PdoQueryPnpDeviceState(param_1,(longlong)param_2);
    uVar5 = (uint)uVar6;
    break;
  case 0x16:
    uVar5 = USBSTOR_PdoDeviceUsageNotification(param_1,(longlong)param_2);
    break;
  case 0x17:
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
              &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
    }
    puVar8 = param_2;
    USBSTOR_LogEntry(0x56445253,param_1,param_2,0);
    UsbQueueFlush(param_1,(uint *)(lVar4 + 0x170),puVar8);
    *(undefined4 *)(lVar4 + 0x28) = 7;
  case 3:
  case 6:
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      puVar8 = WPP_GLOBAL_Control;
      pcVar7 = PnPMinorFunctionString(*(byte *)(lVar3 + 1));
      WPP_SF_s(*(undefined8 *)(puVar8 + 0x18),0x35,puVar8,pcVar7);
    }
    goto LAB_140024276;
  case 0x19:
    *(undefined4 *)(lVar4 + 0x28) = 2;
LAB_140024276:
    uVar5 = 0;
    *(undefined4 *)(param_2 + 0x30) = 0;
LAB_14002427d:
    IofCompleteRequest(param_2,0);
  }
LAB_14002411b:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,uVar5);
  }
  USBSTOR_LogEntry(0x20706e70,(longlong)(int)uVar5,0,0);
  return uVar5;
}



===== USBSTOR_PdoQueryDeviceRelations @ 1400244c0 =====

int USBSTOR_PdoQueryDeviceRelations(undefined8 param_1,longlong param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(longlong *)(param_2 + 0xb8) + 8);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8e,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar2);
  }
  USBSTOR_LogEntry(0x52445150,param_1,param_2,(longlong)iVar2);
  if (iVar2 == 4) {
    puVar1 = (undefined4 *)ExAllocatePool2(0x100,0x10);
    if (puVar1 == (undefined4 *)0x0) {
      iVar2 = -0x3fffff66;
      *(undefined8 *)(param_2 + 0x38) = 0;
    }
    else {
      *puVar1 = 1;
      *(undefined8 *)(puVar1 + 2) = param_1;
      ObfReferenceObject(param_1);
      iVar2 = 0;
      *(undefined4 **)(param_2 + 0x38) = puVar1;
    }
    *(int *)(param_2 + 0x30) = iVar2;
  }
  else {
    iVar2 = *(int *)(param_2 + 0x30);
  }
  IofCompleteRequest(param_2,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8f,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar2);
  }
  USBSTOR_LogEntry(0x72647170,(longlong)iVar2,0,0);
  return iVar2;
}



===== USBSTOR_FdoQueryCapabilities @ 14002462c =====

int USBSTOR_FdoQueryCapabilities(longlong param_1,longlong param_2)

{
  uint *puVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  int iVar5;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6b,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  USBSTOR_LogEntry(0x50435146,param_1,param_2,0);
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  cVar4 = IoForwardIrpSynchronously(*(undefined8 *)(lVar2 + 0x18),param_2);
  if (cVar4 == '\0') {
    iVar5 = -0x3fffffff;
  }
  else {
    iVar5 = *(int *)(param_2 + 0x30);
    if (-1 < iVar5) {
      if (*(int *)(lVar2 + 0x7c) != 0) {
        puVar1 = (uint *)(lVar3 + 4);
        *puVar1 = *puVar1 & 0xffffffef;
      }
      puVar1 = (uint *)(lVar3 + 4);
      *puVar1 = *puVar1 | 0x200;
      goto LAB_140024704;
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6c,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
LAB_140024704:
  IofCompleteRequest(param_2,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6d,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar5);
  }
  USBSTOR_LogEntry(0x70637166,(longlong)iVar5,0,0);
  return iVar5;
}



===== USBSTOR_FdoQueryDeviceRelations @ 140024780 =====

int USBSTOR_FdoQueryDeviceRelations(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  uint *puVar3;
  int iVar4;
  longlong *plVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  ulonglong uVar11;
  uint uVar12;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  iVar4 = *(int *)(*(longlong *)(param_2 + 0xb8) + 8);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x68,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar4);
  }
  USBSTOR_LogEntry(0x52445146,param_1,param_2,(longlong)iVar4);
  if (iVar4 == 0) {
    plVar1 = (longlong *)(lVar2 + 0x20);
    plVar5 = (longlong *)*plVar1;
    if (plVar5 != plVar1) {
      uVar10 = 0;
      uVar11 = 0;
      do {
        uVar9 = uVar11;
        plVar5 = (longlong *)*plVar5;
        uVar8 = (int)uVar9 + 1;
        uVar11 = (ulonglong)uVar8;
      } while (plVar5 != plVar1);
      puVar3 = *(uint **)(param_2 + 0x38);
      if (puVar3 == (uint *)0x0) {
        puVar6 = (uint *)ExAllocatePool2(0x100,uVar9 * 8 + 0x10);
        uVar12 = 0;
      }
      else {
        uVar12 = *puVar3;
        puVar6 = (uint *)ExAllocatePool2(0x100,(ulonglong)((uVar12 - 1) + uVar8) * 8 + 0x10);
        if ((puVar6 != (uint *)0x0) && (uVar12 != 0)) {
          uVar11 = (ulonglong)uVar12;
          puVar7 = puVar6;
          do {
            puVar7 = puVar7 + 2;
            *(undefined8 *)puVar7 =
                 *(undefined8 *)(((longlong)puVar3 - (longlong)puVar6) + (longlong)puVar7);
            uVar11 = uVar11 - 1;
            uVar10 = uVar12;
          } while (uVar11 != 0);
        }
        ExFreePoolWithTag(puVar3,0);
      }
      if (puVar6 == (uint *)0x0) {
        iVar4 = -0x3fffff66;
        puVar6 = (uint *)0x0;
      }
      else {
        *puVar6 = uVar12 + uVar8;
        plVar5 = (longlong *)*plVar1;
        while ((plVar5 != plVar1 && (uVar10 < uVar12 + uVar8))) {
          uVar11 = (ulonglong)uVar10;
          uVar10 = uVar10 + 1;
          *(longlong *)(puVar6 + uVar11 * 2 + 2) = plVar5[-2];
          ObfReferenceObject(plVar5[-2]);
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])))) {
            WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x69,
                     &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,plVar5[-2]);
          }
          plVar5 = (longlong *)*plVar5;
        }
        iVar4 = 0;
      }
      *(int *)(param_2 + 0x30) = iVar4;
      *(uint **)(param_2 + 0x38) = puVar6;
      if (iVar4 < 0) {
        IofCompleteRequest(param_2,0);
        goto LAB_140024838;
      }
    }
  }
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  iVar4 = IofCallDriver(*(undefined8 *)(lVar2 + 0x18),param_2);
LAB_140024838:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6a,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar4);
  }
  USBSTOR_LogEntry(0x72647166,(longlong)iVar4,0,0);
  return iVar4;
}



===== USBSTOR_PdoQueryID @ 1400249f8 =====

int USBSTOR_PdoQueryID(longlong param_1,longlong param_2)

{
  longlong lVar1;
  bool bVar2;
  int iVar3;
  ulonglong uVar4;
  ushort *puVar5;
  ushort *puVar6;
  ushort uVar7;
  longlong lVar8;
  char *pcVar9;
  ulonglong local_18;
  ushort *puStack_10;
  
  local_18 = 0;
  puStack_10 = (ushort *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x80,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  pcVar9 = (char *)0x0;
  lVar8 = param_2;
  USBSTOR_LogEntry(0x44495150,param_1,param_2,0);
  lVar1 = *(longlong *)(param_2 + 0xb8);
  RtlInitUnicodeString(&local_18,0);
  iVar3 = *(int *)(lVar1 + 8);
  if (iVar3 == 0) {
    uVar4 = USBSTOR_PdoQueryDeviceId(param_1,&local_18);
    iVar3 = (int)uVar4;
LAB_140024b5f:
    bVar2 = false;
LAB_140024b62:
    if ((-1 < iVar3) && (puStack_10 != (ushort *)0x0)) {
      uVar7 = *puStack_10;
      puVar6 = puStack_10;
      while (uVar7 != 0) {
        do {
          puVar5 = puVar6;
          if (((uVar7 < 0x21) || (0x7f < uVar7)) || (uVar7 == 0x2c)) {
            *puVar5 = 0x5f;
          }
          puVar6 = puVar5 + 1;
          uVar7 = *puVar6;
        } while (uVar7 != 0);
        uVar7 = 0;
        if (bVar2) {
          puVar6 = puVar5 + 2;
          uVar7 = *puVar6;
        }
      }
      *(ushort **)(param_2 + 0x38) = puStack_10;
      goto LAB_140024aad;
    }
  }
  else {
    if (iVar3 == 1) {
      iVar3 = USBSTOR_PdoQueryHardwareIds(param_1,&local_18,lVar8,pcVar9);
LAB_140024b3f:
      bVar2 = true;
      goto LAB_140024b62;
    }
    if (iVar3 == 2) {
      iVar3 = USBSTOR_PdoQueryCompatibleIds(param_1,&local_18);
      goto LAB_140024b3f;
    }
    if (iVar3 == 3) {
      iVar3 = USBSTOR_PdoBusQueryInstanceId(param_1,(short *)&local_18);
      goto LAB_140024b5f;
    }
    iVar3 = -0x3fffff45;
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
LAB_140024aad:
  *(int *)(param_2 + 0x30) = iVar3;
  IofCompleteRequest(param_2,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x81,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar3);
  }
  USBSTOR_LogEntry(0x64697170,(longlong)iVar3,0,0);
  return iVar3;
}



===== USBSTOR_PdoQueryDeviceId @ 140024bcc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong USBSTOR_PdoQueryDeviceId(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  char cVar2;
  char *pcVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar7;
  longlong lVar6;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  char *pcVar11;
  uint uVar12;
  undefined1 auStack_f8 [32];
  undefined8 local_d8;
  undefined8 uStack_d0;
  char local_c8 [128];
  ulonglong local_48 [2];
  
  local_48[0] = __security_cookie ^ (ulonglong)auStack_f8;
  local_d8 = 0;
  uStack_d0 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x84,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x40);
  memset(local_c8,0,0x80);
  pcVar3 = USBSTOR_PdoDeviceTypeString(param_1);
  uVar4 = RtlStringCbPrintfA(local_c8,0x80,"USBSTOR\\%s",pcVar3);
  if ((int)uVar4 == 0) {
    lVar5 = -1;
    do {
      lVar6 = lVar5;
      lVar5 = lVar6 + 1;
    } while (local_c8[lVar6 + 1] != '\0');
    uVar10 = 0x80 - (int)(lVar6 + 1);
    pcVar3 = local_c8 + lVar6 + 1;
    for (uVar9 = 0; uVar9 < 3; uVar9 = uVar9 + 1) {
      pcVar11 = (char *)0x0;
      lVar5 = 0;
      uVar8 = 0;
      if (uVar9 == 0) {
        uVar4 = 8;
        pcVar11 = "Ven";
        lVar5 = 0x50;
LAB_140024ce3:
        lVar5 = lVar5 + lVar1;
        do {
          uVar8 = (uint)uVar4;
          uVar12 = uVar8 - 1;
          uVar4 = (ulonglong)uVar12;
          if ((*(char *)(uVar4 + lVar5) != ' ') && (*(char *)(uVar4 + lVar5) != '\0')) break;
          uVar8 = 0;
        } while (uVar12 != 0);
      }
      else {
        if (uVar9 == 1) {
          uVar4 = 0x10;
          pcVar11 = "Prod";
          lVar5 = 0x58;
          goto LAB_140024ce3;
        }
        if (uVar9 == 2) {
          uVar4 = 4;
          lVar5 = 0x68;
          pcVar11 = "Rev";
          goto LAB_140024ce3;
        }
      }
      uVar4 = RtlStringCbPrintfA(pcVar3,(longlong)local_48 - (longlong)pcVar3,"&%s_",pcVar11);
      if ((int)uVar4 != 0) {
        return uVar4;
      }
      lVar6 = -1;
      do {
        lVar7 = lVar6;
        lVar6 = lVar7 + 1;
      } while (pcVar11[lVar6] != '\0');
      pcVar3 = pcVar3 + lVar7 + 3;
      uVar10 = uVar10 + (-2 - (int)lVar6);
      for (uVar4 = 0; (uint)uVar4 < uVar8; uVar4 = (ulonglong)((uint)uVar4 + 1)) {
        if (uVar10 < 2) {
          return 0xc000009a;
        }
        cVar2 = '_';
        if (*(char *)(uVar4 + lVar5) != ' ') {
          cVar2 = *(char *)(uVar4 + lVar5);
        }
        uVar10 = uVar10 - 1;
        *pcVar3 = cVar2;
        pcVar3 = pcVar3 + 1;
      }
    }
    RtlInitAnsiString(&local_d8,local_c8);
    uVar9 = RtlAnsiStringToUnicodeString(param_2,&local_d8,1);
    uVar4 = (ulonglong)uVar9;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x85,
               &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,uVar9);
    }
  }
  return uVar4;
}



===== USBSTOR_PdoDeviceTypeString @ 140024e1c =====

char * USBSTOR_PdoDeviceTypeString(longlong param_1)

{
  byte bVar1;
  char *pcVar2;
  byte bVar3;
  
  bVar1 = *(byte *)(*(longlong *)(param_1 + 0x40) + 0x48);
  bVar3 = bVar1 & 0x1f;
  if ((bVar1 & 0x1f) == 0) {
    pcVar2 = "SFloppy";
    if (*(char *)(*(longlong *)(param_1 + 0x40) + 0x45) == '\0') {
      pcVar2 = "Disk";
    }
    return pcVar2;
  }
  if (bVar3 == 1) {
    return "Sequential";
  }
  if (bVar3 == 4) {
    return "Worm";
  }
  if (bVar3 == 5) {
    return "CdRom";
  }
  if (bVar3 == 7) {
    return "Optical";
  }
  if (bVar3 == 8) {
    return "Changer";
  }
  return "Other";
}



===== USBSTOR_PdoQueryCapabilities @ 140024e98 =====

int USBSTOR_PdoQueryCapabilities(longlong param_1,longlong param_2)

{
  uint *puVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  int iVar5;
  
  lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10) + 0x40);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x90,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  USBSTOR_LogEntry(0x50435150,param_1,param_2,0);
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  cVar4 = IoForwardIrpSynchronously(*(undefined8 *)(lVar2 + 0x18),param_2);
  if (cVar4 == '\0') {
    iVar5 = -0x3fffffff;
  }
  else {
    iVar5 = *(int *)(param_2 + 0x30);
    if (-1 < iVar5) {
      if (*(longlong *)(lVar2 + 0x48) == 0) {
        puVar1 = (uint *)(lVar3 + 4);
        *puVar1 = *puVar1 & 0xffffffbf;
      }
      puVar1 = (uint *)(lVar3 + 4);
      *puVar1 = *puVar1 & 0xfffffcef;
      goto LAB_140024f7b;
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x91,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
LAB_140024f7b:
  IofCompleteRequest(param_2,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x92,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar5);
  }
  USBSTOR_LogEntry(0x70637170,(longlong)iVar5,0,0);
  return iVar5;
}



===== USBSTOR_StringArrayToMultiSz @ 140024ff4 =====

int USBSTOR_StringArrayToMultiSz(ulonglong *param_1,longlong *param_2)

{
  short sVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  byte bVar5;
  undefined8 local_38;
  ulonglong uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_28 = 0;
  uStack_20 = 0;
  local_38 = 0;
  uStack_30 = 0;
  iVar2 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x82,
              &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,param_1,(char)param_2);
  }
  RtlInitUnicodeString(param_1,0);
  bVar5 = 0;
  lVar4 = *param_2;
  while (lVar4 != 0) {
    RtlInitAnsiString(&local_28,lVar4);
    sVar1 = RtlxAnsiStringToUnicodeSize(&local_28);
    *(short *)param_1 = (short)*param_1 + sVar1;
    bVar5 = bVar5 + 1;
    lVar4 = param_2[bVar5];
  }
  sVar1 = (short)*param_1 + 2;
  *(short *)((longlong)param_1 + 2) = sVar1;
  uVar3 = ExAllocatePool2(0x100,sVar1,0x53414d55);
  param_1[1] = uVar3;
  if (uVar3 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    local_38 = *param_1;
    uStack_30 = param_1[1];
    bVar5 = 0;
    lVar4 = *param_2;
    while (lVar4 != 0) {
      RtlInitAnsiString(&local_28,lVar4);
      iVar2 = RtlAnsiStringToUnicodeString(&local_38,&local_28,0);
      if (iVar2 < 0) break;
      uVar3 = local_38 & 0xffff;
      sVar1 = local_38._2_2_ + (-2 - (short)local_38);
      local_38._0_4_ = CONCAT22(sVar1,(short)local_38);
      uStack_30 = uStack_30 + uVar3 + 2;
      bVar5 = bVar5 + 1;
      lVar4 = param_2[bVar5];
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x83,
              &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
    }
  }
  return iVar2;
}



===== USBSTOR_PdoQueryPnpDeviceState @ 1400251a0 =====

undefined8 USBSTOR_PdoQueryPnpDeviceState(longlong param_1,longlong param_2)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x95,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  USBSTOR_LogEntry(0x53445150,param_1,param_2,0);
  if ((*(uint *)(param_1 + 0x30) & 0x2000) == 0) {
    *(ulonglong *)(param_2 + 0x38) = *(ulonglong *)(param_2 + 0x38) | 0x20;
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x96,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,0);
  }
  USBSTOR_LogEntry(0x73647170,0,0,0);
  return 0;
}



===== USBSTOR_AddDevice @ 140025280 =====

undefined8 USBSTOR_AddDevice(undefined8 param_1,undefined8 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  USBSTOR_LogEntry(0x44444441,param_1,param_2,0);
  uVar3 = IoCreateDevice(param_1,0x800,0,0x2a,0x180,0,local_res18);
  if (-1 < (int)uVar3) {
    IoSetStartIoAttributes(local_res18[0]);
    puVar2 = *(undefined4 **)(local_res18[0] + 0x40);
    memset(puVar2 + 1,0,0x7fc);
    *puVar2 = 0x214f4446;
    *(longlong *)(puVar2 + 2) = local_res18[0];
    *(undefined8 *)(puVar2 + 4) = param_2;
    uVar3 = IoAttachDeviceToDeviceStack(local_res18[0],param_2);
    *(undefined8 *)(puVar2 + 6) = uVar3;
    puVar1 = puVar2 + 8;
    *(undefined4 **)(puVar2 + 10) = puVar1;
    *(undefined4 **)puVar1 = puVar1;
    IoInitializeRemoveLockEx(puVar2 + 0x1ca,0x53627355,10,0xfffffff,0x20);
    puVar2[0x26] = 1;
    puVar2[0x27] = 1;
    puVar2[0x1c6] = 0x10000;
    puVar2[0x1c7] = 0x11;
    KeInitializeEvent(puVar2 + 0x2a,1,0);
    KeInitializeSpinLock(puVar2 + 0x24);
    KeInitializeEvent(puVar2 + 0x54,1,0);
    KeInitializeEvent(puVar2 + 0x1e4,1,0);
    KeInitializeTimer(puVar2 + 0x30);
    KeInitializeDpc(puVar2 + 0x40,USBSTOR_TimeoutDpc,local_res18[0]);
    USBSTOR_QueryFdoParams(local_res18[0]);
    USBSTOR_GetWriteProtectSetting((longlong)puVar2);
    *(undefined1 *)(puVar2 + 0x1c5) = 1;
    *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) | 0x10;
    *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) | 0x2000;
    *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) & 0xffffff7f;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
              &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
    }
    USBSTOR_LogEntry(0x64646461,local_res18[0],puVar2,*(undefined8 *)(puVar2 + 6));
    if (*(longlong *)(puVar2 + 6) == 0) {
      if (local_res18[0] != 0) {
        IoDeleteDevice();
      }
      uVar3 = 0xc0000001;
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}



===== USBSTOR_QueryFdoParams @ 140025518 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void USBSTOR_QueryFdoParams(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  undefined1 uVar3;
  undefined1 auStack_138 [32];
  undefined8 local_118;
  int *local_110;
  uint local_108;
  undefined4 local_104;
  undefined8 local_100;
  int local_f8 [2];
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined1 local_d8 [8];
  undefined4 local_d0;
  wchar_t *local_c8;
  uint *local_c0;
  undefined4 local_b8;
  uint *local_b0;
  undefined4 local_a8;
  undefined4 local_98;
  wchar_t *local_90;
  undefined4 *local_88;
  undefined4 local_80;
  undefined4 *local_78;
  undefined4 local_70;
  undefined1 local_28 [12];
  char local_1c;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_138;
  local_100 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0)) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_108 = 0;
  local_104 = 0;
  iVar2 = IoOpenDeviceRegistryKey(*(undefined8 *)(lVar1 + 0x10),2,0x1f0000,&local_100);
  if (-1 < iVar2) {
    memset(local_d8,0,0xa8);
    local_118 = 0;
    local_c8 = L"DriverFlags";
    local_a8 = 4;
    local_b8 = 0x4000004;
    local_c0 = &local_108;
    local_d0 = 0x120;
    local_b0 = &local_108;
    local_98 = 0x120;
    local_90 = L"NonRemovable";
    local_88 = &local_104;
    local_78 = &local_104;
    local_80 = 0x4000004;
    local_70 = 4;
    RtlQueryRegistryValuesEx(0x40000000,local_100,local_d8,0);
    ZwClose(local_100);
  }
  if (3 < local_108) {
    local_108 = 0;
  }
  *(uint *)(lVar1 + 0x78) = local_108;
  *(undefined4 *)(lVar1 + 0x7c) = local_104;
  iVar2 = IoOpenDeviceRegistryKey(*(undefined8 *)(lVar1 + 0x10),1,0x20019,&local_100);
  if (-1 < iVar2) {
    local_f8[0] = 0;
    RtlInitUnicodeString(&local_f0,L"EnableSelectiveSuspend");
    local_110 = local_f8;
    local_118 = CONCAT44(local_118._4_4_,0x14);
    iVar2 = ZwQueryValueKey(local_100,&local_f0,2,local_28);
    if ((iVar2 < 0) || (local_f8[0] == 0)) {
      uVar3 = 0xff;
    }
    else {
      uVar3 = local_1c != '\0';
    }
    *(undefined1 *)(lVar1 + 0x7f9) = uVar3;
    ZwClose(local_100);
  }
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,local_108);
    }
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                 &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,local_104);
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
      }
    }
  }
  return;
}



===== USBSTOR_GetWriteProtectSetting @ 1400257f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void USBSTOR_GetWriteProtectSetting(longlong param_1)

{
  int iVar1;
  undefined1 auStack_1e8 [32];
  undefined8 local_1c8;
  int local_1b8 [4];
  undefined1 local_1a8 [8];
  undefined4 local_1a0;
  wchar_t *local_198;
  int *local_190;
  undefined4 local_188;
  undefined8 local_180;
  undefined4 local_178;
  undefined4 local_138;
  undefined1 local_134 [278];
  char local_1e;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_1e8;
  memset(local_134,0,0x118);
  local_138 = 0x11c;
  local_1b8[0] = 0;
  iVar1 = RtlGetVersion(&local_138);
  if ((-1 < iVar1) && (local_1e == '\x01')) {
    memset(local_1a8,0,0x70);
    local_1a0 = 0x124;
    local_198 = L"WriteProtect";
    local_190 = local_1b8;
    local_188 = 0x4000004;
    local_180 = 0;
    local_178 = 0;
    local_1c8 = 0;
    RtlQueryRegistryValuesEx
              (0,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\StorageDevicePolicies",
               local_1a8,0);
  }
  *(bool *)(param_1 + 0x720) = local_1b8[0] != 0;
  return;
}



===== USBSTOR_EnumerateChildren @ 1400258f8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int USBSTOR_EnumerateChildren(longlong param_1,undefined8 param_2,byte *param_3)

{
  int *piVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  ulonglong uVar5;
  byte bVar6;
  char cVar7;
  byte bVar8;
  undefined1 auStackY_98 [32];
  byte local_58;
  char local_57;
  char local_56;
  byte local_55;
  char local_54 [4];
  uint local_50 [4];
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_98;
  piVar1 = *(int **)(param_1 + 0x40);
  bVar8 = 0;
  local_40 = 0x4610460;
  iVar4 = 0;
  local_3c = 0x4630462;
  local_58 = 0;
  if ((*(char *)(*(longlong *)(piVar1 + 0x10) + 5) == '\b') &&
     (*(char *)(*(longlong *)(piVar1 + 0x10) + 7) == 'P')) {
    iVar4 = USBSTOR_GetMaxLun(param_1,&local_58);
    bVar8 = local_58;
    if (-1 < iVar4) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        param_3 = &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5b,
                 &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,(uint)local_58);
      }
      if (*(longlong *)(piVar1 + 0x12) == 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          param_3 = &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5c,
                  &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
        }
        bVar8 = 0;
      }
    }
  }
  *(byte *)(piVar1 + 0x1d2) = bVar8;
  bVar6 = 0;
  do {
    if (bVar8 < bVar6) {
      return iVar4;
    }
    local_50[2] = 0;
    local_50[1] = 0;
    local_50[0] = 0;
    cVar7 = '\0';
    local_56 = '\0';
    local_55 = 0;
    local_54[0] = '\0';
    local_54[1] = 0;
    local_58 = 0;
    local_57 = '\0';
    if ((piVar1[0x1d3] == 0) || (*(char *)((longlong)piVar1 + 0x74a) != '\0')) {
      if ((*piVar1 == 0x214f4446) && ((piVar1[0x21] & 0x30000000U) != 0)) {
        bVar2 = ~(byte)((uint)piVar1[0x21] >> 0x1d) & 1;
      }
      else {
        param_3 = &local_58;
        uVar5 = USBSTOR_IsWellImplementedACT(param_1,bVar6,param_3,&local_57,(longlong)&local_40,4);
        bVar2 = (byte)uVar5;
      }
      *(byte *)(piVar1 + 0x1ea) = bVar2;
      if (bVar2 != 0) {
        if ((local_58 == 0) || (cVar3 = '\0', local_57 != '\0')) {
          param_3 = &local_55;
          USBSTOR_1667DetermineInc512Support(param_1,bVar6,param_3,&local_56);
          if ((local_56 == '\0') || (cVar3 = local_56, local_55 == 0)) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              param_3 = &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids;
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5d,
                      &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
            }
            goto LAB_140025af9;
          }
        }
        param_3 = (byte *)CONCAT71((int7)((ulonglong)param_3 >> 8),cVar3);
        cVar3 = USBSTOR_Is1667(param_1,bVar6,cVar3);
        if (cVar3 != '\0') {
          cVar7 = '\x01';
        }
      }
    }
LAB_140025af9:
    param_3 = (byte *)CONCAT71((int7)((ulonglong)param_3 >> 8),cVar7);
    uVar5 = USBSTOR_CreateChildPDO
                      (param_1,bVar6,cVar7,local_54,local_54 + 1,(int *)(local_50 + 2),
                       (int *)(local_50 + 1),local_50);
    iVar4 = (int)uVar5;
    if (local_54[0] != '\0') {
      *(undefined1 *)((longlong)piVar1 + 0x7a9) = 1;
    }
    if (iVar4 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar4;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0) {
        return iVar4;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return iVar4;
      }
      WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5e,param_3,(uint)bVar6,(char)uVar5);
      return iVar4;
    }
    bVar6 = bVar6 + 1;
  } while( true );
}



===== USBSTOR_IsFloppyDevice @ 140025bb0 =====

undefined1 USBSTOR_IsFloppyDevice(longlong param_1,int *param_2,int *param_3)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  int *piVar5;
  uint uVar6;
  longlong lVar7;
  undefined4 uVar8;
  byte *pbVar9;
  undefined8 uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint local_res8 [2];
  int *local_res10;
  undefined8 local_48;
  undefined2 local_40;
  
  local_res10 = param_2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc1,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  uVar8 = 0;
  uVar10 = 0x53414d55;
  local_res8[0] = 0xfc;
  lVar4 = ExAllocatePool2(0x40);
  if (lVar4 != 0) {
    local_48 = 0x23;
    local_40 = 0xfc;
    iVar3 = USBSTOR_IssueInternalCdbToLun
                      (param_1,0,uVar10,lVar4,(int *)local_res8,&local_48,10,0x14);
    uVar6 = local_res8[0];
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc2,1,iVar3,(char)local_res8[0],
                 *(undefined1 *)(lVar4 + 3));
    }
    piVar2 = local_res10;
    if (((-1 < iVar3) && (3 < uVar6)) &&
       ((bVar1 = *(byte *)(lVar4 + 3), bVar1 != 0 && ((bVar1 & 7) == 0)))) {
      uVar6 = uVar6 - 4;
      uVar13 = 0;
      uVar12 = uVar6 >> 3;
      if (bVar1 <= uVar6) {
        uVar12 = (uint)(bVar1 >> 3);
      }
      if (uVar12 != 0) {
        pbVar9 = (byte *)(lVar4 + 5);
        do {
          iVar3 = (uint)pbVar9[-1] * 0x1000000 + (uint)pbVar9[1] * 0x100 + (uint)*pbVar9 * 0x10000 +
                  (uint)pbVar9[2];
          iVar11 = (uint)pbVar9[4] * 0x10000 + (uint)pbVar9[5] * 0x100 + (uint)pbVar9[6];
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar6 = pbVar9[3] >> 1 & 1;
            WPP_SF_dDDdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar6,1,uVar13,
                         (char)iVar3,(char)iVar11,(char)uVar6,pbVar9[3] & 1);
          }
          lVar7 = 7;
          *piVar2 = iVar3;
          *param_3 = iVar11;
          piVar5 = &DAT_14001a094;
          do {
            if ((iVar3 == piVar5[-1]) && (iVar11 == *piVar5)) {
              uVar8 = 1;
            }
            piVar5 = piVar5 + 2;
            lVar7 = lVar7 + -1;
          } while (lVar7 != 0);
          uVar13 = uVar13 + 1;
          pbVar9 = pbVar9 + 8;
        } while (uVar13 < uVar12);
      }
    }
    ExFreePoolWithTag(lVar4,0);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc4,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,uVar8);
  }
  return (char)uVar8;
}



===== USBSTOR_BuildAlignmentDescriptor @ 140025e64 =====

int USBSTOR_BuildAlignmentDescriptor(longlong param_1,void *param_2,uint *param_3)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x40);
  iVar2 = USBSTOR_PopulateAlignmentInfo(param_1);
  if (-1 < iVar2) {
    local_18 = *(undefined4 *)(lVar1 + 0x300);
    local_20 = 0;
    local_1c = 0;
    local_14 = *(undefined4 *)(lVar1 + 0x304);
    local_10 = *(undefined4 *)(lVar1 + 0x308);
    uVar3 = *param_3;
    local_28 = 0x1c;
    local_24 = 0x1c;
    if (0x1c < uVar3) {
      *param_3 = 0x1c;
      uVar3 = 0x1c;
    }
    memmove(param_2,&local_28,(ulonglong)uVar3);
    iVar2 = 0;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar2);
  }
  return iVar2;
}



===== USBSTOR_PopulateAlignmentInfo @ 140025f74 =====

int USBSTOR_PopulateAlignmentInfo(longlong param_1)

{
  longlong lVar1;
  int *piVar2;
  bool bVar3;
  byte bVar4;
  int iVar5;
  longlong lVar6;
  uint uVar7;
  uint uVar8;
  undefined8 uVar9;
  uint uVar10;
  uint local_res8 [2];
  undefined1 local_res10 [8];
  undefined2 local_res18 [4];
  undefined8 local_38;
  undefined8 uStack_30;
  
  iVar5 = 0;
  local_res10[0] = 0;
  local_res8[0] = local_res8[0] & 0xffffff00;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x40);
  piVar2 = *(int **)(*(longlong *)(lVar1 + 0x10) + 0x40);
  if (*(char *)(lVar1 + 0x30c) == '\0') {
    *(undefined4 *)(lVar1 + 0x300) = 0;
    *(undefined4 *)(lVar1 + 0x304) = 0;
    *(undefined4 *)(lVar1 + 0x308) = 0;
    *(undefined1 *)(lVar1 + 0x30c) = 1;
    bVar3 = USBSTOR_UseReadCapacity16(param_1);
    if (!bVar3) {
      if ((*piVar2 == 0x214f4446) && (uVar8 = piVar2[0x21], (uVar8 & 0xc0000000) != 0)) {
        bVar4 = (byte)(uVar8 >> 0x1f) ^ 1;
      }
      else {
        local_res18[0] = 0x4c0;
        USBSTOR_IsWellImplementedACT
                  (param_1,*(undefined1 *)(lVar1 + 0x47),local_res10,(undefined1 *)local_res8,
                   (longlong)local_res18,1);
        bVar4 = (byte)local_res8[0];
      }
      if (bVar4 == 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
                  &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
        }
        goto LAB_14002602e;
      }
    }
    uVar9 = 0x53414d55;
    local_res8[0] = 0x20;
    lVar6 = ExAllocatePool2(0x40,0x20);
    if (lVar6 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
                &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
      }
      iVar5 = -0x3fffff66;
    }
    else {
      local_38 = 0x109e;
      uStack_30 = 0x200000000000;
      iVar5 = USBSTOR_IssueInternalCdbToLun
                        (param_1,*(undefined1 *)(lVar1 + 0x47),uVar9,lVar6,(int *)local_res8,
                         &local_38,0x10,0x14);
      if (-1 < iVar5) {
        uVar7 = 1 << (*(byte *)(lVar6 + 0xd) & 0xf);
        uVar10 = (*(byte *)(lVar6 + 0xe) & 0x3f) * 0x100 + (uint)*(byte *)(lVar6 + 0xf);
        uVar8 = *(uint *)(lVar6 + 8);
        uVar8 = (uVar8 << 0x10 | uVar8 & 0xff00) << 8 | uVar8 >> 8 & 0xff00 |
                (uint)*(byte *)(lVar6 + 0xb);
        if (uVar7 < uVar10) {
          iVar5 = -0x3fffff64;
        }
        else {
          *(uint *)(lVar1 + 0x300) = uVar8;
          *(uint *)(lVar1 + 0x304) = uVar8 * uVar7;
          if (uVar10 == 0) {
            iVar5 = 0;
          }
          else {
            iVar5 = (uVar7 - uVar10) * uVar8;
          }
          *(int *)(lVar1 + 0x308) = iVar5;
          iVar5 = 0;
        }
      }
      ExFreePoolWithTag(lVar6,0);
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    }
    if (((*(int *)(lVar1 + 0x300) != 0) || (*(int *)(lVar1 + 0x304) != 0)) ||
       (*(int *)(lVar1 + 0x308) != 0)) goto LAB_140026233;
LAB_14002602e:
    iVar5 = -0x3fffff45;
  }
LAB_140026233:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar5);
  }
  return iVar5;
}



===== USBSTOR_IsWellImplementedACT @ 140026284 =====

ulonglong USBSTOR_IsWellImplementedACT
                    (longlong param_1,undefined1 param_2,undefined1 *param_3,undefined1 *param_4,
                    longlong param_5,uint param_6)

{
  byte bVar1;
  undefined8 uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  undefined **ppuVar6;
  undefined2 uVar7;
  uint uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  ushort *puVar11;
  ulonglong uVar12;
  uint local_38 [2];
  undefined8 local_30;
  undefined8 uStack_28;
  
  local_38[0] = 0x24;
  lVar5 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
            &WPP_882c5dbd4c393422b71f4ab343c3933e_Traceguids);
  }
  uVar9 = 0x53414d55;
  lVar4 = ExAllocatePool2(0x40,0x24);
  if (lVar4 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar7 = 0x14;
LAB_14002632f:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
              &WPP_882c5dbd4c393422b71f4ab343c3933e_Traceguids);
    }
LAB_14002633f:
    iVar3 = -0x3fffff66;
  }
  else {
    if (param_3 != (undefined1 *)0x0) {
      *param_3 = 0;
    }
    if (param_4 != (undefined1 *)0x0) {
      *param_4 = 0;
    }
    uStack_28 = 0;
    local_30 = 0x2400000012;
    iVar3 = USBSTOR_IssueInternalCdbToLun
                      (param_1,param_2,uVar9,lVar4,(int *)local_38,&local_30,6,0x14);
    if (iVar3 < 0) goto LAB_140026555;
    uVar8 = *(byte *)(lVar4 + 4) + 5;
    if ((0x24 < uVar8) && ((uVar8 & 3) == 0)) {
      uVar10 = 0x53414d55;
      local_38[0] = uVar8;
      lVar5 = ExAllocatePool2(0x40,uVar8);
      uVar9 = local_30;
      if (lVar5 == 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar7 = 0x15;
          goto LAB_14002632f;
        }
        goto LAB_14002633f;
      }
      local_30 = CONCAT71(local_30._1_7_,0x12);
      uVar2 = local_30;
      local_30._5_3_ = SUB83(uVar9,5);
      local_30._0_5_ = CONCAT14((char)uVar8,(int)uVar2);
      iVar3 = USBSTOR_IssueInternalCdbToLun
                        (param_1,param_2,uVar10,lVar5,(int *)local_38,&local_30,6,0x14);
      if (iVar3 < 0) goto LAB_140026555;
      if (0x3a < *(byte *)(lVar4 + 4) + 5) {
        uVar8 = 0x3a;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                  &WPP_882c5dbd4c393422b71f4ab343c3933e_Traceguids);
        }
        if (param_3 != (undefined1 *)0x0) {
          *param_3 = 1;
        }
        puVar11 = (ushort *)(lVar5 + 0x3a);
        if (puVar11 <= (ushort *)(lVar5 + 0x4aU)) {
          bVar1 = *(byte *)(lVar4 + 4);
          do {
            if (bVar1 + 5 <= uVar8 + 1) break;
            for (uVar12 = 0; (uint)uVar12 < param_6; uVar12 = (ulonglong)((uint)uVar12 + 1)) {
              if ((ushort)(*puVar11 << 8 | *puVar11 >> 8) == *(ushort *)(param_5 + uVar12 * 2)) {
                if (param_3 != (undefined1 *)0x0) {
                  *param_4 = 1;
                }
                iVar3 = 0;
                break;
              }
            }
            uVar8 = (uint)(byte)((char)uVar8 + 2);
            puVar11 = puVar11 + 1;
          } while (puVar11 <= (ushort *)(lVar5 + 0x4aU));
        }
        goto LAB_140026555;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                &WPP_882c5dbd4c393422b71f4ab343c3933e_Traceguids);
      }
    }
    iVar3 = -0x3fffffff;
  }
LAB_140026555:
  ppuVar6 = &WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (ppuVar6 = (undefined **)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
      (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    ppuVar6 = (undefined **)
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                       &WPP_882c5dbd4c393422b71f4ab343c3933e_Traceguids,iVar3);
  }
  if (lVar5 != 0) {
    ppuVar6 = (undefined **)ExFreePoolWithTag(lVar5,0);
  }
  if (lVar4 != 0) {
    ppuVar6 = (undefined **)ExFreePoolWithTag(lVar4,0);
  }
  return CONCAT71((int7)((ulonglong)ppuVar6 >> 8),(byte)((uint)iVar3 >> 0x1f)) ^ 1;
}



===== USBSTOR_GetInquiryData @ 1400265e8 =====

int USBSTOR_GetInquiryData(longlong param_1,undefined8 param_2,undefined *param_3)

{
  longlong lVar1;
  int iVar2;
  int local_res18 [4];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res18[0] = (int)param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_e947f7dfdc8330b398201c2535585168_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xbb,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  uStack_10 = 0;
  local_res18[0] = 0x24;
  local_18 = 0x2400000012;
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10) + 0x40);
  iVar2 = USBSTOR_IssueInternalCdbToLun
                    (param_1,0,param_3,*(longlong *)(param_1 + 0x40) + 0x48,local_res18,&local_18,6,
                     0x14);
  if ((-1 < iVar2) && (*(int *)(lVar1 + 0x78) == 0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xbc,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    }
    *(undefined4 *)(lVar1 + 0x78) = 3;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xbd,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,iVar2);
  }
  return iVar2;
}



===== USBSTOR_UseReadCapacity16 @ 140026714 =====

bool USBSTOR_UseReadCapacity16(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  int *piVar3;
  undefined8 uVar4;
  int local_res8 [2];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8[0] = 8;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(int *)(lVar1 + 0x324) == 0xff) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
              &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
    }
    *(undefined4 *)(lVar1 + 0x324) = 1;
    uVar4 = 0x53414d55;
    local_18 = 0;
    uStack_10 = 0;
    piVar3 = (int *)ExAllocatePool2(0x40,8);
    if (piVar3 == (int *)0x0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
                &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
      }
      return false;
    }
    local_18 = CONCAT71(CONCAT61(local_18._2_6_,*(char *)(lVar1 + 0x47) << 5 | local_18._1_1_ & 0x1f
                                ),0x25);
    iVar2 = USBSTOR_IssueInternalCdbToLun
                      (param_1,*(char *)(lVar1 + 0x47),uVar4,piVar3,local_res8,&local_18,10,0x14);
    if ((-1 < iVar2) && (*piVar3 == -1)) {
      *(undefined4 *)(lVar1 + 0x324) = 2;
    }
    ExFreePoolWithTag(piVar3,0);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,*(undefined4 *)(lVar1 + 0x324));
  }
  return *(int *)(lVar1 + 0x324) == 2;
}



===== USBSTOR_IssueInternalCdb @ 1400268d8 =====

void USBSTOR_IssueInternalCdb
               (longlong param_1,undefined8 param_2,undefined8 param_3,void *param_4,byte param_5,
               undefined4 param_6)

{
  USBSTOR_IssueInternalCdbToLun(param_1,0,param_3,param_2,(int *)param_3,param_4,param_5,param_6);
  return;
}



===== USBSTOR_IssueInternalCdbToLun @ 14002690c =====

undefined4
USBSTOR_IssueInternalCdbToLun
          (longlong param_1,undefined1 param_2,undefined8 param_3,undefined8 param_4,int *param_5,
          void *param_6,byte param_7,undefined4 param_8)

{
  longlong lVar1;
  byte bVar2;
  int iVar3;
  undefined2 *_Dst;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  undefined4 uVar7;
  ulonglong _Size;
  uint uVar8;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb8,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  lVar6 = 0;
  uVar7 = 0xc000009a;
  _Dst = (undefined2 *)ExAllocatePool2(0x40,0x58,0x53414d55);
  if (_Dst != (undefined2 *)0x0) {
    lVar4 = ExAllocatePool2(0x40,0x12,0x53414d55);
    if (lVar4 != 0) {
      KeInitializeEvent(&local_58,1,0);
      for (uVar8 = 0; uVar8 < 3; uVar8 = uVar8 + 1) {
        lVar5 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c));
        if (lVar5 == 0) break;
        lVar1 = *(longlong *)(lVar5 + 0xb8);
        *(undefined1 *)(lVar1 + -0x48) = 0xf;
        *(undefined2 **)(lVar1 + -0x40) = _Dst;
        memset(_Dst,0,0x58);
        iVar3 = *param_5;
        *(undefined1 *)((longlong)_Dst + 7) = param_2;
        *_Dst = 0x58;
        _Size = (ulonglong)param_7;
        *(undefined8 *)(_Dst + 0xc) = param_4;
        *(byte *)(_Dst + 5) = param_7;
        *(undefined1 *)((longlong)_Dst + 0xb) = 0x12;
        *(longlong *)(_Dst + 0x10) = lVar4;
        *(int *)(_Dst + 8) = iVar3;
        if (iVar3 == 0) {
          *(undefined4 *)(_Dst + 6) = 0x120;
        }
        else {
          *(undefined4 *)(_Dst + 6) = 0x140;
          if (uVar8 == 0) {
            lVar6 = IoAllocateMdl(param_4,iVar3,0,0,0);
            if (lVar6 == 0) {
              IoFreeIrp(lVar5);
              uVar7 = 0xc000009a;
              goto LAB_140026bcb;
            }
            MmBuildMdlForNonPagedPool(lVar6);
          }
        }
        *(longlong *)(lVar5 + 8) = lVar6;
        *(undefined4 *)(_Dst + 10) = param_8;
        *(longlong *)(_Dst + 0x18) = lVar5;
        memmove(_Dst + 0x24,param_6,_Size);
        KeClearEvent(&local_58);
        lVar1 = *(longlong *)(lVar5 + 0xb8);
        *(code **)(lVar1 + -0x10) = USBSTOR_InternalCDBCompletionRoutine;
        *(undefined8 **)(lVar1 + -8) = &local_58;
        *(undefined1 *)(lVar1 + -0x45) = 0xe0;
        iVar3 = IofCallDriver(param_1);
        if (iVar3 == 0x103) {
          _Size = 0;
          lVar5 = 0;
          KeWaitForSingleObject(&local_58);
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_dDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar5,_Size,uVar8,(char)iVar3,
                     *(undefined1 *)((longlong)_Dst + 3));
        }
        bVar2 = *(byte *)((longlong)_Dst + 3) & 0x3f;
        if ((bVar2 == 1) || (bVar2 == 0x12)) {
          uVar7 = 0;
          *param_5 = *(int *)(_Dst + 8);
          break;
        }
        uVar7 = 0xc0000001;
      }
      if (lVar6 != 0) {
        IoFreeMdl(lVar6);
      }
LAB_140026bcb:
      ExFreePoolWithTag(lVar4,0);
    }
    ExFreePoolWithTag(_Dst,0);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xba,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,uVar7);
  }
  return uVar7;
}



===== USBSTOR_CreateChildPDO @ 140026c48 =====

ulonglong USBSTOR_CreateChildPDO
                    (longlong param_1,byte param_2,char param_3,undefined1 *param_4,
                    undefined1 *param_5,int *param_6,int *param_7,uint *param_8)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined1 uVar5;
  uint uVar6;
  ulonglong uVar7;
  longlong lVar8;
  byte bVar9;
  longlong *plVar10;
  undefined2 uVar11;
  longlong *plVar12;
  undefined1 *puVar13;
  undefined *puVar14;
  longlong local_res8;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  undefined4 local_48;
  undefined1 local_40;
  longlong *local_38;
  
  local_res8 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x57,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,(uint)param_2);
  }
  USBSTOR_LogEntry(0x44504343,param_1,(ulonglong)param_2,0);
  lVar1 = *(longlong *)(param_1 + 0x40);
  *param_4 = 0;
  *param_5 = 0;
  if (*(int *)(lVar1 + 0x750) == 0) {
    if (param_3 != '\0') goto LAB_140026d0e;
LAB_140026d60:
    local_38 = &local_res8;
    local_40 = 0;
    local_48 = 0x180;
    uVar7 = IoCreateDevice(*(undefined8 *)(param_1 + 8),0x338,0,0x2d);
    if (-1 < (int)uVar7) {
      puVar14 = (undefined *)0x334;
      *(undefined1 *)(local_res8 + 0x4c) = *(undefined1 *)(param_1 + 0x4c);
      puVar2 = *(undefined4 **)(local_res8 + 0x40);
      memset(puVar2 + 1,0,0x334);
      puVar13 = auStack_68;
      *puVar2 = 0x214f4450;
      plVar10 = (longlong *)(puVar2 + 6);
      *(longlong *)(puVar2 + 2) = local_res8;
      puVar2[0xb] = 1;
      puVar2[0xc] = 1;
      puVar2[10] = 1;
      lVar8 = lVar1 + 0x20;
      *(longlong *)(puVar2 + 4) = param_1;
      *(char *)((longlong)puVar2 + 0x46) = param_3;
      puVar2[0xc9] = 0xff;
      plVar12 = *(longlong **)(lVar1 + 0x28);
      if (*plVar12 != lVar8) {
        plVar10 = (longlong *)0x3;
        pcVar4 = (code *)swi(0x29);
        lVar8 = (*pcVar4)();
        puVar13 = auStack_60;
      }
      *plVar10 = lVar8;
      plVar10[1] = (longlong)plVar12;
      *plVar12 = (longlong)plVar10;
      *(longlong **)(lVar8 + 8) = plVar10;
      *(uint *)(local_res8 + 0x30) = *(uint *)(local_res8 + 0x30) | 0x10;
      *(uint *)(local_res8 + 0x30) = *(uint *)(local_res8 + 0x30) | 0x2000;
      *(uint *)(local_res8 + 0x30) = *(uint *)(local_res8 + 0x30) & 0xffffff7f;
      *(byte *)((longlong)puVar2 + 0x47) = param_2;
      *(undefined8 *)(puVar13 + -8) = 0x140026e3c;
      UsbQueueInitialize((undefined8 *)(puVar2 + 0x5c));
      *(undefined8 *)(puVar13 + -8) = 0x140026e45;
      uVar6 = USBSTOR_GetInquiryData(local_res8,plVar12,puVar14);
      if (-1 < (int)uVar6) {
        *param_8 = (uint)*(byte *)(puVar2 + 0x13);
        bVar9 = *(byte *)(puVar2 + 0x12) & 0x1f;
        if (bVar9 == 0) {
          *(undefined8 *)(puVar13 + -8) = 0x140026e6f;
          uVar5 = USBSTOR_IsFloppyDevice(local_res8,param_6,param_7);
          *(undefined1 *)((longlong)puVar2 + 0x45) = uVar5;
        }
        else if (((byte)(bVar9 - 4) < 2) || ((byte)(bVar9 - 7) < 2)) {
          *param_4 = 1;
        }
        if ((*(uint *)(lVar1 + 0x84) & 0x40) != 0) {
          *(byte *)((longlong)puVar2 + 0x49) = *(byte *)((longlong)puVar2 + 0x49) & 0x7f;
        }
        if (*(char *)((longlong)puVar2 + 0x49) < '\0') {
          *param_5 = 1;
          *(uint *)(local_res8 + 0x34) = *(uint *)(local_res8 + 0x34) | 1;
        }
        if ((*(uint *)(lVar1 + 0x84) & 0x10) == 0) {
          *(undefined8 *)(puVar13 + -8) = 0x140026ebd;
          USBSTOR_GetDeviceSerialNumber(local_res8);
        }
      }
      *(undefined4 *)(puVar13 + 0x20) = 0x20;
      *(undefined8 *)(puVar13 + -8) = 0x140026ee4;
      IoInitializeRemoveLockEx(puVar2 + 0xb8,0x53627355,10,0xfffffff);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar3 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(undefined8 *)(puVar13 + -8) = 0x140026f23;
        WPP_SF_D(uVar3,0x5a,&WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,uVar6);
      }
      *(undefined8 *)(puVar13 + -8) = 0x140026f37;
      USBSTOR_LogEntry(0x64706363,param_1,local_res8,(longlong)(int)uVar6);
      uVar7 = (ulonglong)uVar6;
    }
  }
  else {
    if (param_3 == '\0') {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar11 = 0x58;
LAB_140026d43:
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,
                 &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,param_1);
      }
    }
    else {
LAB_140026d0e:
      if ((*(int *)(lVar1 + 0x74c) == 0) || (*(char *)(lVar1 + 0x74a) != '\0')) goto LAB_140026d60;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar11 = 0x59;
        goto LAB_140026d43;
      }
    }
    uVar7 = 0xc0000001;
  }
  return uVar7;
}



===== USBSTOR_GetDescriptor @ 140026f60 =====

int USBSTOR_GetDescriptor
              (longlong param_1,undefined8 param_2,char param_3,undefined1 param_4,
              undefined2 param_5,undefined8 param_6,int param_7,longlong *param_8)

{
  int iVar1;
  longlong lVar2;
  undefined4 *puVar3;
  int iVar4;
  bool bVar5;
  
  iVar4 = 2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9b,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  *param_8 = 0;
  lVar2 = ExAllocatePool2(0x40,param_7,0x53414d55);
  *param_8 = lVar2;
  if (lVar2 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    puVar3 = (undefined4 *)ExAllocatePool2(0x40,0x88,0x53414d55);
    if (puVar3 == (undefined4 *)0x0) {
      ExFreePoolWithTag(*param_8,0);
      *param_8 = 0;
      iVar1 = -0x3fffff66;
    }
    else {
      do {
        lVar2 = *param_8;
        *(undefined8 *)(puVar3 + 0xc) = 0;
        *(undefined8 *)(puVar3 + 0xe) = 0;
        *(longlong *)(puVar3 + 10) = lVar2;
        *puVar3 = 0xb0088;
        puVar3[9] = param_7;
        *(char *)((longlong)puVar3 + 0x83) = param_3;
        *(undefined1 *)((longlong)puVar3 + 0x82) = param_4;
        *(undefined2 *)(puVar3 + 0x21) = param_5;
        iVar1 = USBSTOR_SyncSendUsbRequest(param_1,(longlong)puVar3);
        if (-1 < iVar1) {
          if ((param_7 == puVar3[9]) && (param_3 == *(char *)(*param_8 + 1))) break;
          iVar1 = -0x3fffff64;
        }
        bVar5 = iVar4 != 0;
        iVar4 = iVar4 + -1;
      } while (bVar5);
      ExFreePoolWithTag(puVar3,0);
    }
    if (-1 < iVar1) goto LAB_140027072;
  }
  if (*param_8 != 0) {
    ExFreePoolWithTag(*param_8,0);
    *param_8 = 0;
  }
LAB_140027072:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9c,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar1);
  }
  return iVar1;
}



===== AppendField @ 140027154 =====

void AppendField(longlong param_1,undefined8 param_2,longlong param_3,uint param_4)

{
  bool bVar1;
  char cVar2;
  longlong lVar3;
  char *pcVar4;
  ulonglong uVar5;
  
  if ((param_1 != 0) && (param_3 != 0)) {
    *(undefined1 *)(param_1 + 0x7f) = 0;
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while (*(char *)(param_1 + lVar3) != '\0');
    pcVar4 = (char *)(lVar3 + param_1);
    if ((param_1 - (longlong)pcVar4) + 0x80U <= (ulonglong)param_4) {
      param_4 = ((int)param_1 - (int)pcVar4) + 0x80;
    }
    bVar1 = false;
    if (param_4 != 0) {
      uVar5 = (ulonglong)param_4;
      lVar3 = param_3 - (longlong)pcVar4;
      do {
        if (bVar1) {
LAB_1400271c4:
          cVar2 = '_';
        }
        else {
          cVar2 = pcVar4[lVar3];
          if (cVar2 == '\0') {
            bVar1 = true;
            goto LAB_1400271c4;
          }
          if (cVar2 == ' ') {
            cVar2 = '_';
          }
        }
        *pcVar4 = cVar2;
        pcVar4 = pcVar4 + 1;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
  }
  return;
}



===== USBSTOR_QueryGlobalFdoParams @ 1400271dc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void USBSTOR_QueryGlobalFdoParams(longlong param_1)

{
  ushort uVar1;
  ushort uVar2;
  longlong lVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  ulonglong uVar9;
  uint uVar10;
  ulonglong uVar11;
  longlong lVar12;
  undefined1 *puVar13;
  uint uVar14;
  wchar_t *pwVar15;
  undefined1 auStack_188 [32];
  wchar_t **local_168;
  uint local_158;
  int local_154;
  undefined4 local_150;
  uint local_14c;
  uint local_148;
  wchar_t *local_140;
  undefined8 local_138 [2];
  undefined1 local_128 [8];
  undefined4 local_120;
  wchar_t *local_118;
  uint *local_110;
  undefined4 local_108;
  uint *local_100;
  undefined4 local_f8;
  wchar_t local_b8 [32];
  wchar_t local_78 [32];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_188;
  local_158 = 0;
  local_154 = 0;
  uVar7 = 0;
  local_150 = 0;
  local_138[0] = 0;
  local_140 = (wchar_t *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  lVar3 = *(longlong *)(param_1 + 0x40);
  uVar1 = *(ushort *)(*(longlong *)(lVar3 + 0x30) + 8);
  uVar2 = *(ushort *)(*(longlong *)(lVar3 + 0x30) + 10);
  local_148 = (uint)uVar1;
  local_14c = (uint)uVar2;
  local_168._0_4_ = local_14c;
  RtlStringCchPrintfW(local_b8,0x20,L"usbstor\\%04x%04x",(ulonglong)local_148);
  local_168 = (wchar_t **)CONCAT44(local_168._4_4_,(uint)uVar2);
  uVar9 = RtlStringCchPrintfW(local_78,0x20,L"USBSTOR:USB\\VID_%04X&PID_%04X",(ulonglong)uVar1);
  uVar9 = uVar9 & 0xffffffff;
  cVar4 = RtlIsStateSeparationEnabled();
  pwVar15 = (wchar_t *)0x0;
  if (cVar4 != '\0') {
    local_168 = &local_140;
    uVar5 = USBSTOR_GetStateSeparationLocation();
    uVar9 = (ulonglong)uVar5;
    pwVar15 = local_140;
  }
  if (*(int *)(lVar3 + 0x78) == 0) {
    memset(local_128,0,0x70);
    local_120 = 0x120;
    local_118 = L"DriverFlags";
    local_110 = &local_158;
    local_108 = 0x4000004;
    local_100 = &local_158;
    local_f8 = 4;
    local_168 = (wchar_t **)0x0;
    uVar5 = RtlQueryRegistryValuesEx(2,local_b8,local_128,0);
    uVar9 = (ulonglong)uVar5;
    if ((-1 < (int)uVar5) && (local_158 < 4)) {
      *(uint *)(lVar3 + 0x78) = local_158;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
               &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,local_158);
    }
  }
  memset(local_128,0,0x70);
  local_120 = 0x120;
  local_118 = L"DeviceHackFlags";
  uVar14 = 0xf;
  local_110 = (uint *)&local_154;
  local_108 = 0x4000004;
  local_100 = (uint *)&local_154;
  local_f8 = 4;
  uVar5 = 0;
  uVar11 = 0xf;
  while( true ) {
    uVar6 = (uint)uVar9;
    if ((4 < uVar5) || ((int)uVar11 == 0)) goto LAB_140027486;
    local_168 = (wchar_t **)0x0;
    puVar13 = local_128;
    uVar6 = RtlQueryRegistryValuesEx(2);
    uVar9 = (ulonglong)uVar6;
    if (-1 < (int)uVar6) break;
    uVar5 = uVar5 + 1;
    local_b8[uVar11] = L'x';
    uVar11 = (ulonglong)((int)uVar11 - 1);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,puVar13,local_b8);
  }
  *(int *)(lVar3 + 0x84) = local_154;
LAB_140027486:
  uVar5 = 0;
  if (pwVar15 == (wchar_t *)0x0) {
LAB_14002753f:
    if (((int)uVar6 < 0) && (USBSTOR_KseQueryDeviceFlags != (code *)0x0)) {
      uVar6 = (*USBSTOR_KseQueryDeviceFlags)(local_78,L"USBSTOR",local_138);
      if (-1 < (int)uVar6) {
        *(undefined4 *)(lVar3 + 0x84) = (undefined4)local_138[0];
      }
    }
  }
  else {
    lVar12 = -1;
    do {
      lVar12 = lVar12 + 1;
    } while (pwVar15[lVar12] != L'\0');
    uVar10 = (uint)lVar12;
    local_154 = 0;
    while( true ) {
      uVar10 = uVar10 - 1;
      if ((4 < uVar5) || (uVar10 == 0)) goto LAB_140027522;
      local_168 = (wchar_t **)0x0;
      puVar13 = local_128;
      uVar7 = RtlQueryRegistryValuesEx(0,pwVar15,puVar13,0);
      if (-1 < (int)uVar7) break;
      pwVar15[uVar10] = L'x';
      uVar5 = uVar5 + 1;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,puVar13,pwVar15);
    }
    *(int *)(lVar3 + 0x84) = *(int *)(lVar3 + 0x84) + local_154;
LAB_140027522:
    ExFreePoolWithTag(pwVar15);
    if ((int)uVar7 < 0) goto LAB_14002753f;
    uVar6 = uVar7;
  }
  USBSTOR_GlobalSelectiveSuspendSetting(lVar3);
  if (-1 < (int)uVar6) goto LAB_1400275d5;
  lVar12 = *(longlong *)(lVar3 + 0x30);
  if (*(short *)(lVar12 + 8) == 0xbda) {
    if (*(short *)(lVar12 + 10) != 0x307) goto LAB_1400275d5;
    if (*(short *)(lVar12 + 0xc) != 0x129) goto LAB_1400275ab;
  }
  else {
LAB_1400275ab:
    if ((*(short *)(lVar12 + 8) != 0x45e) ||
       ((*(short *)(lVar12 + 10) != 0x90c && (*(short *)(lVar12 + 10) != 0x306))))
    goto LAB_1400275d5;
  }
  *(uint *)(lVar3 + 0x84) = *(uint *)(lVar3 + 0x84) | 0x800;
LAB_1400275d5:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,*(undefined4 *)(lVar3 + 0x84));
  }
  memset(local_128,0,0x70);
  local_118 = L"MaximumTransferLength";
  local_110 = &local_150;
  local_120 = 0x120;
  local_100 = &local_150;
  local_108 = 0x4000004;
  local_168 = (wchar_t **)CONCAT44(local_168._4_4_,local_14c);
  local_f8 = 4;
  RtlStringCchPrintfW(local_b8,0x20,L"usbstor\\%04x%04x",(ulonglong)local_148);
  uVar7 = 0;
  while( true ) {
    if ((4 < uVar7) || (uVar14 == 0)) goto LAB_1400276f6;
    local_168 = (wchar_t **)0x0;
    puVar13 = local_128;
    iVar8 = RtlQueryRegistryValuesEx(2,local_b8);
    if (-1 < iVar8) break;
    uVar9 = (ulonglong)uVar14;
    uVar14 = uVar14 - 1;
    uVar7 = uVar7 + 1;
    local_b8[uVar9] = L'x';
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,puVar13,local_b8);
  }
  *(undefined4 *)(lVar3 + 0x88) = local_150;
LAB_1400276f6:
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
               &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,local_150);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
              &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
    }
  }
  return;
}



===== USBSTOR_GlobalSelectiveSuspendSetting @ 14002778c =====

void USBSTOR_GlobalSelectiveSuspendSetting(longlong param_1)

{
  bool bVar1;
  uint local_res10 [6];
  undefined1 local_78 [8];
  undefined4 local_70;
  wchar_t *local_68;
  uint *local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined4 local_48;
  
  bVar1 = USBSTOR_IsPlatformMobileOrAoac();
  local_res10[0] = (uint)bVar1;
  memset(local_78,0,0x70);
  local_50 = 0;
  local_48 = 0;
  local_68 = L"SelectiveSuspend";
  local_60 = local_res10;
  local_70 = 0x124;
  local_58 = 0x4000004;
  RtlQueryRegistryValuesEx
            (0,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\StorageDevicePolicies",
             local_78,0,0);
  if (local_res10[0] != 0) {
    *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) | 0x80;
  }
  return;
}



===== USBSTOR_IsPlatformMobileOrAoac @ 140027830 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool USBSTOR_IsPlatformMobileOrAoac(void)

{
  int iVar1;
  undefined1 auStack_a8 [32];
  undefined4 local_88;
  char local_78 [4];
  int local_74 [3];
  undefined1 local_68 [30];
  char local_4a;
  char local_49;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  local_74[0] = 0;
  local_78[0] = '\0';
  memset(local_68,0,0x4c);
  local_88 = 4;
  iVar1 = ZwPowerInformation(0x4b,0,0,local_74);
  if ((iVar1 < 0) || ((local_74[0] != 2 && (local_74[0] != 8)))) {
    local_88 = 1;
    iVar1 = ZwPowerInformation(0x42,0,0,local_78);
    if ((iVar1 < 0) || (local_78[0] == '\0')) {
      local_88 = 0x4c;
      iVar1 = ZwPowerInformation(4,0,0,local_68);
      if ((iVar1 < 0) || (local_4a == '\0')) {
        return false;
      }
      return local_49 == '\0';
    }
  }
  return true;
}



===== USBSTOR_PdoBusQueryInstanceId @ 140027920 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 USBSTOR_PdoBusQueryInstanceId(longlong param_1,short *param_2)

{
  ushort uVar1;
  byte *pbVar2;
  short sVar3;
  void *_Dst;
  undefined4 uVar4;
  longlong lVar5;
  undefined1 auStack_268 [32];
  uint local_248;
  wchar_t local_238 [128];
  undefined1 local_138 [256];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_268;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8c,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  lVar5 = *(longlong *)(param_1 + 0x40);
  uVar4 = 0;
  pbVar2 = *(byte **)(*(longlong *)(*(longlong *)(lVar5 + 0x10) + 0x40) + 0x48);
  if (pbVar2 != (byte *)0x0) {
    memset(local_238,0,0x100);
    memset(local_138,0,0x100);
    if (*pbVar2 - 2 < 0x100) {
      memmove(local_138,pbVar2 + 2,(ulonglong)(*pbVar2 - 2));
      local_248 = (uint)*(byte *)(lVar5 + 0x47);
      RtlStringCbPrintfW(local_238,0x80,L"%ws&%01x",local_138);
      lVar5 = -1;
      do {
        lVar5 = lVar5 + 1;
      } while (local_238[lVar5] != L'\0');
      sVar3 = (short)lVar5 * 2;
      uVar1 = sVar3 + 2;
      _Dst = (void *)ExAllocatePool2(0x100,(ulonglong)uVar1,0x53414d55);
      *(void **)(param_2 + 4) = _Dst;
      if (_Dst == (void *)0x0) {
        uVar4 = 0xc000009a;
      }
      else {
        *param_2 = sVar3;
        param_2[1] = uVar1;
        memmove(_Dst,local_238,(ulonglong)uVar1);
      }
    }
    else {
      uVar4 = 0xc0000182;
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8d,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,uVar4);
  }
  return uVar4;
}



===== USBSTOR_SystemControl @ 140027ae0 =====

/* WARNING: Removing unreachable block (ram,0x000140027b9f) */
/* WARNING: Removing unreachable block (ram,0x000140027ba4) */
/* WARNING: Removing unreachable block (ram,0x000140027bc9) */

int USBSTOR_SystemControl(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,(uint)*(byte *)(lVar1 + 1));
  }
  USBSTOR_LogEntry(0x43535953,param_1,param_2,(ulonglong)*(byte *)(lVar1 + 1));
  piVar2 = *(int **)(param_1 + 0x40);
  if (*piVar2 == 0x214f4450) {
    piVar4 = *(int **)(*(longlong *)(piVar2 + 4) + 0x40);
  }
  else {
    piVar4 = (int *)0x0;
    if (*piVar2 == 0x214f4446) {
      piVar4 = piVar2;
    }
  }
  iVar3 = WmiSystemControl(piVar4 + 0x1ee,param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar3);
  }
  USBSTOR_LogEntry(0x63737973,(longlong)iVar3,0,0);
  return iVar3;
}



===== USBSTOR_SelectConfiguration @ 140027c3c =====

int USBSTOR_SelectConfiguration(longlong param_1)

{
  short *_Dst;
  ushort *_Src;
  short sVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  longlong *plVar5;
  short *_Dst_00;
  void *_Dst_01;
  undefined2 uVar6;
  ulonglong _Size;
  short *psVar7;
  int local_res8 [2];
  int local_res10 [2];
  int local_res18 [2];
  longlong local_res20;
  undefined1 uVar8;
  
  local_res20 = 0;
  local_res10[0] = 0;
  local_res18[0] = 0;
  local_res8[0] = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9f,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  USBSTOR_LogEntry(0x4e4f4353,param_1,0,0);
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar3 = *(longlong *)(lVar2 + 0x38);
  plVar5 = (longlong *)ExAllocatePool2(0x100,0x20);
  if (plVar5 == (longlong *)0x0) {
    iVar4 = -0x3fffff66;
  }
  else {
    USBSTOR_AdjustConfigurationDescriptor
              (param_1,*(byte **)(lVar2 + 0x38),&local_res20,local_res10,local_res18,local_res8);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa0,
               &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,local_res8[0]);
    }
    *(longlong *)(lVar2 + 0x40) = local_res20;
    if (local_res20 == 0) {
      iVar4 = -0x3fffffff;
    }
    else {
      *plVar5 = local_res20;
      plVar5[2] = 0;
      *(undefined1 *)(lVar3 + 4) = 1;
      _Dst_00 = (short *)USBD_CreateConfigurationRequestEx(lVar3,plVar5);
      if (_Dst_00 == (short *)0x0) {
        iVar4 = -0x3fffff66;
      }
      else {
        iVar4 = USBSTOR_SyncSendUsbRequest(param_1,(longlong)_Dst_00);
        if (-1 < iVar4) {
          _Dst = _Dst_00 + 0x10;
          _Src = (ushort *)(_Dst_00 + 0x14);
          *(undefined8 *)(lVar2 + 0x50) = *(undefined8 *)_Dst;
          _Dst_01 = (void *)ExAllocatePool2(0x40,*_Src);
          *(void **)(lVar2 + 0x58) = _Dst_01;
          if (_Dst_01 == (void *)0x0) {
            iVar4 = -0x3fffff66;
          }
          else {
            memmove(_Dst_01,_Src,(ulonglong)*_Src);
            memset(_Dst_00,0,(ulonglong)*(uint *)(*(longlong *)(lVar2 + 0x58) + 0x10) * 0x18 + 0x38)
            ;
            sVar1 = *(short *)(*(longlong *)(lVar2 + 0x58) + 0x10);
            _Dst_00[1] = 1;
            *_Dst_00 = sVar1 * 0x18 + 0x38;
            *(undefined8 *)(_Dst_00 + 0xc) = *(undefined8 *)(lVar2 + 0x50);
            _Size = (ulonglong)**(ushort **)(lVar2 + 0x58);
            memmove(_Dst,*(ushort **)(lVar2 + 0x58),_Size);
            iVar4 = 0;
            if (0 < *(int *)(_Dst_00 + 0x18)) {
              psVar7 = _Dst_00 + 0x24;
              do {
                if ((iVar4 == local_res10[0]) || (iVar4 == local_res18[0])) {
                  psVar7[0] = 0;
                  psVar7[1] = 2;
                  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0 &&
                      (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
                    uVar6 = 0xa1;
                    uVar8 = 0;
LAB_140027eb7:
                    WPP_SF_dD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,_Size,iVar4,uVar8);
                  }
                }
                else if (iVar4 == local_res8[0]) {
                  _Size = 2;
                  psVar7[0] = 2;
                  psVar7[1] = 0;
                  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
                     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                    uVar6 = 0xa2;
                    uVar8 = 2;
                    goto LAB_140027eb7;
                  }
                }
                iVar4 = iVar4 + 1;
                psVar7 = psVar7 + 0xc;
              } while (iVar4 < *(int *)(_Dst_00 + 0x18));
            }
            iVar4 = USBSTOR_SyncSendUsbRequest(param_1,(longlong)_Dst_00);
            if (-1 < iVar4) {
              memmove(*(ushort **)(lVar2 + 0x58),_Dst,(ulonglong)**(ushort **)(lVar2 + 0x58));
            }
          }
        }
        ExFreePoolWithTag(_Dst_00,0);
      }
    }
    ExFreePoolWithTag(plVar5,0);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xa3,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar4);
  }
  USBSTOR_LogEntry(0x6e6f6373,(longlong)iVar4,0,0);
  return iVar4;
}



===== USBSTOR_AdjustConfigurationDescriptor @ 140027fa4 =====

void USBSTOR_AdjustConfigurationDescriptor
               (longlong param_1,byte *param_2,undefined8 *param_3,int *param_4,int *param_5,
               int *param_6)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  longlong lVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  
  lVar4 = *(longlong *)(param_1 + 0x40);
  pbVar7 = param_2 + *(ushort *)(param_2 + 2);
  pbVar5 = (byte *)0x0;
  *param_5 = -1;
  *param_4 = -1;
  *param_6 = -1;
  iVar6 = 0;
  do {
    pbVar1 = param_2 + 2;
    if ((pbVar7 <= pbVar1) || (bVar2 = *param_2, pbVar7 < param_2 + bVar2)) goto LAB_14002815c;
    if (param_2[1] == 4) {
      if (bVar2 == 9) {
        if (pbVar5 != (byte *)0x0) goto LAB_14002815c;
        pbVar5 = param_2;
      }
    }
    else if (((param_2[1] == 5) && (bVar2 == 7)) && (pbVar5 != (byte *)0x0)) {
      if ((param_2[3] & 3) == 2) {
        if ((char)*pbVar1 < '\0') {
          if (*param_4 == -1) {
            *param_4 = iVar6;
          }
        }
        else if (*param_5 == -1) {
          *param_5 = iVar6;
        }
LAB_1400280ce:
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,
                    &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,(uint)param_2[2],param_2[3]);
        }
      }
      else {
        if ((((param_2[3] & 3) != 3) || (-1 < (char)*pbVar1)) ||
           ((*param_6 != -1 || (iVar3 = *(int *)(lVar4 + 0x78), 1 < iVar3 - 1U))))
        goto LAB_1400280ce;
        *param_6 = iVar6;
        if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,
                     &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar3);
          }
          goto LAB_1400280ce;
        }
      }
      iVar6 = iVar6 + 1;
    }
    if (*param_2 == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x52,
                &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
      }
LAB_14002815c:
      *param_3 = pbVar5;
      return;
    }
    param_2 = param_2 + *param_2;
  } while( true );
}



===== USBSTOR_GetMaxLun @ 140028184 =====

int USBSTOR_GetMaxLun(longlong param_1,byte *param_2)

{
  byte bVar1;
  longlong lVar2;
  int iVar3;
  undefined4 *_Dst;
  int iVar4;
  bool bVar5;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9d,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  lVar2 = *(longlong *)(param_1 + 0x40);
  *param_2 = 0;
  _Dst = (undefined4 *)ExAllocatePool2(0x40,0x99,0x53414d55);
  if (_Dst == (undefined4 *)0x0) {
    iVar3 = -0x3fffff66;
  }
  else {
    iVar4 = 2;
    do {
      memset(_Dst,0,0x99);
      *_Dst = 0x1b0088;
      _Dst[8] = 1;
      _Dst[9] = 1;
      *(undefined4 **)(_Dst + 10) = _Dst + 0x26;
      *(undefined1 *)((longlong)_Dst + 0x81) = 0xfe;
      *(ushort *)(_Dst + 0x21) = (ushort)*(byte *)(*(longlong *)(lVar2 + 0x58) + 2);
      iVar3 = USBSTOR_SyncSendUsbRequest(param_1,(longlong)_Dst);
      if (iVar3 < 0) {
        if ((_Dst[1] & 0xfffffff) == 4) {
          memset(_Dst,0,0x98);
          *_Dst = 0x120088;
          USBSTOR_SyncSendUsbRequest(param_1,(longlong)_Dst);
        }
      }
      else {
        if (_Dst[9] == 1) {
          bVar1 = *(byte *)(_Dst + 0x26);
          if (bVar1 < 0x10) {
            *param_2 = bVar1;
          }
          else {
            iVar3 = -0x3fffff64;
          }
          break;
        }
        iVar3 = -0x3fffff64;
      }
      bVar5 = iVar4 != 0;
      iVar4 = iVar4 + -1;
    } while (bVar5);
    ExFreePoolWithTag(_Dst,0);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x9e,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar3);
  }
  return iVar3;
}



===== USBSTOR_FdoRemoveDevice @ 140028338 =====

int USBSTOR_FdoRemoveDevice(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 uVar5;
  code *pcVar6;
  int iVar7;
  longlong *plVar8;
  undefined1 *puVar9;
  longlong lVar10;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined4 local_28;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x61,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  USBSTOR_LogEntry(0x564d4552,param_1,param_2,0);
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_28 = 0x20;
  IoAcquireRemoveLockEx(lVar1 + 0x728,param_2);
  USBSTOR_CancelInterruptIrp(lVar1);
  USBSTOR_WmiDeregister(lVar1);
  USBSTOR_LogEntry(0x316d6572,param_1,0,0);
  IoReleaseRemoveLockAndWaitEx(lVar1 + 0x728,param_2);
  USBSTOR_LogEntry(0x326d6572,param_1,0,0);
  puVar9 = auStack_48;
  plVar8 = (longlong *)(lVar1 + 0x20);
  do {
    if ((longlong *)*plVar8 == plVar8) {
LAB_140028469:
      if (*(longlong *)(lVar1 + 0x6a8) != 0) {
        *(undefined8 *)(puVar9 + -8) = 0x14002847c;
        IoFreeMdl();
        *(undefined8 *)(lVar1 + 0x6a8) = 0;
      }
      if (*(longlong *)(lVar1 + 0x170) != 0) {
        *(undefined8 *)(puVar9 + -8) = 0x14002849c;
        IoFreeWorkItem();
        *(undefined8 *)(lVar1 + 0x170) = 0;
      }
      if (*(longlong *)(lVar1 + 0x178) != 0) {
        *(undefined8 *)(puVar9 + -8) = 0x1400284bc;
        IoFreeWorkItem();
        *(undefined8 *)(lVar1 + 0x178) = 0;
      }
      if (*(longlong *)(lVar1 + 0x180) != 0) {
        *(undefined8 *)(puVar9 + -8) = 0x1400284dc;
        IoFreeWorkItem();
        *(undefined8 *)(lVar1 + 0x180) = 0;
      }
      lVar10 = *(longlong *)(lVar1 + 0x30);
      if (lVar10 != 0) {
        *(undefined8 *)(puVar9 + -8) = 0x1400284fb;
        ExFreePoolWithTag(lVar10,0);
      }
      lVar10 = *(longlong *)(lVar1 + 0x38);
      if (lVar10 != 0) {
        *(undefined8 *)(puVar9 + -8) = 0x140028512;
        ExFreePoolWithTag(lVar10,0);
      }
      lVar10 = *(longlong *)(lVar1 + 0x48);
      if (lVar10 != 0) {
        *(undefined8 *)(puVar9 + -8) = 0x140028529;
        ExFreePoolWithTag(lVar10,0);
      }
      lVar10 = *(longlong *)(lVar1 + 0x58);
      if (lVar10 != 0) {
        *(undefined8 *)(puVar9 + -8) = 0x140028540;
        ExFreePoolWithTag(lVar10,0);
      }
      plVar8 = (longlong *)(lVar1 + 0x778);
      lVar10 = 2;
      do {
        lVar4 = plVar8[-2];
        if (lVar4 != 0) {
          *(undefined8 *)(puVar9 + -8) = 0x140028563;
          ExFreePoolWithTag(lVar4,0);
          plVar8[-2] = 0;
        }
        if (*plVar8 != 0) {
          *(undefined8 *)(puVar9 + -8) = 0x14002857e;
          ExFreePoolWithTag();
          *plVar8 = 0;
        }
        plVar8 = plVar8 + 1;
        lVar10 = lVar10 + -1;
      } while (lVar10 != 0);
      if (*(longlong *)(lVar1 + 0x758) != 0) {
        *(undefined8 *)(puVar9 + -8) = 0x1400285a4;
        IoFreeIrp();
        *(undefined8 *)(lVar1 + 0x758) = 0;
      }
      if (*(longlong *)(lVar1 + 0x168) != 0) {
        *(undefined8 *)(puVar9 + -8) = 0x1400285c3;
        IoFreeIrp();
        *(undefined8 *)(lVar1 + 0x168) = 0;
      }
      if (*(longlong *)(lVar1 + 0x7b0) != 0) {
        *(undefined8 *)(puVar9 + -8) = 0x1400285e3;
        PoFxUnregisterDevice();
        *(undefined8 *)(lVar1 + 0x7b0) = 0;
      }
      *(undefined4 *)(param_2 + 0x30) = 0;
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      uVar5 = *(undefined8 *)(lVar1 + 0x18);
      *(undefined8 *)(puVar9 + -8) = 0x14002860d;
      iVar7 = IofCallDriver(uVar5,param_2);
      *(undefined8 *)(puVar9 + -8) = 0x140028628;
      USBSTOR_LogEntry(0x336d6572,param_1,0,0);
      uVar5 = *(undefined8 *)(lVar1 + 0x18);
      *(undefined8 *)(puVar9 + -8) = 0x140028633;
      IoDetachDevice(uVar5);
      *(undefined8 *)(puVar9 + -8) = 0x140028642;
      IoDeleteDevice(param_1);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        *(undefined8 *)(puVar9 + -8) = 0x140028678;
        WPP_SF_D(uVar5,0x62,&WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar7);
      }
      *(undefined8 *)(puVar9 + -8) = 0x14002868b;
      USBSTOR_LogEntry(0x766d6572,(longlong)iVar7,0,0);
      return iVar7;
    }
    puVar2 = *(undefined8 **)(lVar1 + 0x28);
    if (((longlong *)*puVar2 != plVar8) ||
       (plVar3 = (longlong *)puVar2[1], (undefined8 *)*plVar3 != puVar2)) {
      pcVar6 = (code *)swi(0x29);
      (*pcVar6)(3);
      puVar9 = auStack_40;
      goto LAB_140028469;
    }
    *(longlong **)(lVar1 + 0x28) = plVar3;
    *plVar3 = (longlong)plVar8;
    USBSTOR_LogEntry(0x636d6572,param_1,puVar2[-2],0);
    IoDeleteDevice(puVar2[-2]);
  } while( true );
}



===== USBSTOR_GetBusInterface @ 1400286b0 =====

int USBSTOR_GetBusInterface(longlong param_1,void *param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xaa,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x40);
  memset(param_2,0,0x48);
  lVar4 = *(longlong *)(lVar1 + 0x18);
  lVar4 = IoAllocateIrp(CONCAT71((int7)((ulonglong)lVar4 >> 8),*(undefined1 *)(lVar4 + 0x4c)),0);
  if (lVar4 != 0) {
    KeInitializeEvent(&local_38,1,0);
    lVar2 = *(longlong *)(lVar4 + 0xb8);
    *(undefined8 *)(lVar2 + -0x28) = 0;
    *(undefined **)(lVar2 + -0x40) = &USB_BUS_INTERFACE_USBDI_GUID;
    *(undefined2 *)(lVar2 + -0x48) = 0x81b;
    *(void **)(lVar2 + -0x30) = param_2;
    *(undefined4 *)(lVar2 + -0x38) = 0x10048;
    iVar3 = IoSetCompletionRoutineEx(param_1,lVar4,USBSTOR_SyncCompletionRoutine,&local_38,1,1,1);
    if (-1 < iVar3) {
      *(undefined4 *)(lVar4 + 0x30) = 0xc00000bb;
      iVar3 = IofCallDriver(*(undefined8 *)(lVar1 + 0x18),lVar4);
      if (iVar3 == 0x103) {
        KeWaitForSingleObject(&local_38,0,0,0,0);
        iVar3 = *(int *)(lVar4 + 0x30);
      }
      IoFreeIrp(lVar4);
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar3;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return iVar3;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
        return iVar3;
      }
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xab,
               &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar3);
      return iVar3;
    }
    IoFreeIrp(lVar4);
  }
  return -0x3fffff66;
}



===== USBSTOR_BuildMiniportDescriptor @ 140028890 =====

undefined4 USBSTOR_BuildMiniportDescriptor(undefined8 param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  uVar1 = *param_3;
  if (uVar1 < 8) {
    uVar3 = 0xc0000010;
    uVar2 = 0;
  }
  else if (uVar1 < 0x10) {
    *param_2 = 0x18;
    param_2[1] = 0x18;
    uVar3 = 0;
    uVar2 = 8;
  }
  else {
    memset(param_2,0,(ulonglong)uVar1);
    param_2[2] = 5;
    param_2[3] = 0x140100;
    uVar2 = 0x18;
    if (uVar1 < 0x18) {
      uVar2 = 0x10;
    }
    else {
      *(undefined1 *)(param_2 + 4) = 0;
    }
    *param_2 = uVar2;
    param_2[1] = uVar2;
    uVar3 = 0;
  }
  *param_3 = uVar2;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
             &WPP_e947f7dfdc8330b398201c2535585168_Traceguids,uVar3);
  }
  return uVar3;
}



===== USBSTOR_IsDeviceConnectedToRootHub @ 140028990 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool USBSTOR_IsDeviceConnectedToRootHub(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  char *pcVar5;
  undefined8 uVar6;
  bool bVar7;
  undefined1 auStackY_98 [32];
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_98;
  local_48 = 0;
  uStack_40 = 0;
  local_50 = 0;
  iVar3 = -0x3ffffff3;
  local_38 = 0;
  uStack_30 = 0;
  local_60 = 0;
  uStack_58 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xac,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar6 = 0;
  KeInitializeEvent(&local_60,1);
  lVar4 = *(longlong *)(lVar1 + 0x18);
  lVar4 = IoAllocateIrp(CONCAT71((int7)((ulonglong)lVar4 >> 8),*(undefined1 *)(lVar4 + 0x4c)),0);
  if (lVar4 != 0) {
    lVar2 = *(longlong *)(lVar4 + 0xb8);
    *(undefined8 **)(lVar2 + -0x40) = &local_48;
    *(undefined1 *)(lVar2 + -0x48) = 0xf;
    *(undefined4 *)(lVar2 + -0x30) = 0x22043f;
    lVar2 = *(longlong *)(lVar4 + 0xb8);
    *(undefined4 *)(lVar4 + 0x30) = 0xc00000bb;
    *(code **)(lVar2 + -0x10) = USBSTOR_SyncCompletionRoutine;
    *(undefined8 **)(lVar2 + -8) = &local_60;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    iVar3 = IofCallDriver(*(undefined8 *)(lVar1 + 0x18),lVar4);
    if (iVar3 == 0x103) {
      uVar6 = 0;
      iVar3 = KeWaitForSingleObject(&local_60,0,0,0);
      if (iVar3 == 0x102) {
        iVar3 = -0x3fffff4b;
        IoCancelIrp(lVar4);
        uVar6 = 0;
        KeWaitForSingleObject(&local_60,0,0,0);
      }
      else {
        iVar3 = *(int *)(lVar4 + 0x30);
      }
    }
    IoFreeIrp(lVar4);
    if (-1 < iVar3) {
      bVar7 = local_38._2_2_ == 0;
      goto LAB_140028b33;
    }
  }
  bVar7 = false;
LAB_140028b33:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    pcVar5 = "TRUE";
    if (bVar7 == false) {
      pcVar5 = "FALSE";
    }
    WPP_SF_Ds(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pcVar5,uVar6,iVar3,pcVar5);
  }
  return bVar7;
}



===== USBSTOR_BuildPowerDescriptor @ 140028ba8 =====

undefined8 USBSTOR_BuildPowerDescriptor(longlong param_1,void *param_2,uint *param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10) + 0x40);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
            &WPP_e947f7dfdc8330b398201c2535585168_Traceguids);
  }
  uVar6 = 0x14;
  uStack_20._0_3_ = CONCAT12(*(longlong *)(lVar1 + 0x7b0) != 0,(undefined2)uStack_20);
  local_28 = 0x1400000014;
  cVar4 = USBSTOR_IsDeviceAsyncCapable(lVar1);
  uVar2 = uStack_20;
  if ((cVar4 != '\0') || ((*(uint *)(lVar1 + 0x84) & 0x800) != 0)) {
    uStack_20._0_2_ = CONCAT11(1,(undefined1)uStack_20);
    uVar3 = uStack_20;
    uStack_20._6_2_ = SUB82(uVar2,6);
    uStack_20._0_6_ = CONCAT15(1,(int5)uVar3);
  }
  uVar5 = *param_3;
  if (uVar6 < *param_3) {
    *param_3 = uVar6;
    uVar5 = uVar6;
  }
  memmove(param_2,&local_28,(ulonglong)uVar5);
  return 0;
}



===== USBSTOR_EnableRuntimePowerManagement @ 140028c84 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int USBSTOR_EnableRuntimePowerManagement(longlong param_1)

{
  undefined8 *puVar1;
  int iVar2;
  undefined1 auStack_e8 [32];
  undefined4 local_c8 [2];
  undefined8 local_c0;
  code *local_b8;
  code *local_b0;
  code *local_a8;
  code *local_a0;
  code *local_98;
  code *local_90;
  code *local_88;
  code *local_80;
  undefined4 local_78;
  longlong local_70;
  undefined4 local_68;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 *local_40;
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_e8;
  local_14 = 0;
  memset(local_c8,0,0xa0);
  local_28 = 0;
  local_20 = 0;
  puVar1 = (undefined8 *)(param_1 + 0x7b0);
  local_18 = 0xffffffff;
  local_48 = 0;
  local_78 = 0;
  local_b8 = _guard_check_icall;
  local_b0 = USBSTOR_FxComponentIdleCallback;
  local_a8 = USBSTOR_FxComponentIdleStateCallback;
  local_a0 = USBSTOR_FxDevicePowerRequiredCallback;
  local_98 = USBSTOR_FxDevicePowerNotRequiredCallback;
  local_90 = USBSTOR_FxPowerControlCallback;
  local_88 = USBSTOR_FxDirectedPowerUpCallback;
  local_80 = USBSTOR_FxDirectedPowerDownCallback;
  local_40 = &local_28;
  local_68 = 1;
  local_44 = 1;
  local_c8[0] = 3;
  local_c0 = 6;
  local_70 = param_1;
  iVar2 = PoFxRegisterDevice(*(undefined8 *)(param_1 + 8),local_c8,puVar1);
  if (-1 < iVar2) {
    PoFxSetDeviceIdleTimeout(*puVar1,600000000);
    PoFxStartDevicePowerManagement(*puVar1);
  }
  return iVar2;
}



===== USBSTOR_PdoRemoveDevice @ 140028dc8 =====

undefined8 USBSTOR_PdoRemoveDevice(longlong param_1,longlong param_2,undefined *param_3)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  ulonglong uVar4;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x79,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  uVar1 = *(uint *)(*(longlong *)(lVar2 + 0x40) + 0x84);
  uVar4 = (ulonglong)uVar1;
  if ((uVar1 & 0x20) != 0) {
    iVar3 = USBSTOR_IsDeviceConnected(lVar2);
    if ((-1 < iVar3) && (*(char *)(*(longlong *)(param_2 + 0xb8) + 1) != '\0')) {
      iVar3 = USBSTOR_EjectMedia(param_1,uVar4,param_3);
      if (((iVar3 < 0) &&
          (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)))) &&
         (2 < (byte)WPP_GLOBAL_Control[0x29])) {
        param_3 = &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7a,
                 &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar3);
      }
    }
  }
  lVar2 = *(longlong *)(param_1 + 0x40);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7b,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  UsbQueueFlush(param_1,(uint *)(lVar2 + 0x170),param_3);
  *(undefined1 *)(lVar2 + 0x44) = 0;
  *(undefined4 *)(lVar2 + 0x28) = 8;
  if (*(longlong *)(lVar2 + 0x2d8) != 0) {
    IoFreeWorkItem();
    *(undefined8 *)(lVar2 + 0x2d8) = 0;
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x7c,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,0);
  }
  USBSTOR_LogEntry(0x646d7270,0,0,0);
  return 0;
}



===== USBSTOR_PdoQueryDeviceText @ 140028f68 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int USBSTOR_PdoQueryDeviceText(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  int iVar6;
  undefined1 auStack_168 [32];
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined1 local_120 [248];
  ulonglong local_28 [2];
  
  local_28[0] = __security_cookie ^ (ulonglong)auStack_168;
  local_148 = 0;
  uStack_140 = 0;
  local_138 = 0;
  uStack_130 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8a,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  uVar5 = 0;
  USBSTOR_LogEntry(0x54445150,param_1,param_2,0);
  lVar4 = *(longlong *)(param_1 + 0x40);
  if (*(int *)(*(longlong *)(param_2 + 0xb8) + 8) == 0) {
    memset(local_120,0,0xf8);
    iVar6 = 7;
    local_128 = *(undefined8 *)(lVar4 + 0x50);
    pcVar2 = (char *)&local_128;
    for (lVar3 = 7; -1 < lVar3; lVar3 = lVar3 + -1) {
      if ((local_120[lVar3 + -8] & 0xdf) != 0) {
        local_120[(longlong)iVar6 + -7] = 0x20;
        pcVar2 = local_120 + (longlong)iVar6 + -6;
        break;
      }
      iVar6 = iVar6 + -1;
    }
    uVar1 = *(undefined8 *)(lVar4 + 0x60);
    iVar6 = 0xf;
    *(undefined8 *)pcVar2 = *(undefined8 *)(lVar4 + 0x58);
    *(undefined8 *)(pcVar2 + 8) = uVar1;
    for (lVar4 = 0xf; -1 < lVar4; lVar4 = lVar4 + -1) {
      if ((pcVar2[lVar4] & 0xdfU) != 0) {
        pcVar2[(longlong)iVar6 + 1] = ' ';
        pcVar2 = pcVar2 + (longlong)iVar6 + 2;
        break;
      }
      iVar6 = iVar6 + -1;
    }
    RtlStringCbPrintfA(pcVar2,(longlong)local_28 - (longlong)pcVar2,"USB Device",uVar5);
    RtlInitAnsiString(&local_148,&local_128);
    iVar6 = RtlAnsiStringToUnicodeString(&local_138,&local_148);
    uVar5 = 0;
    if (-1 < iVar6) {
      uVar5 = uStack_130;
    }
    *(undefined8 *)(param_2 + 0x38) = uVar5;
  }
  else {
    iVar6 = *(int *)(param_2 + 0x30);
  }
  *(int *)(param_2 + 0x30) = iVar6;
  IofCompleteRequest(param_2,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x8b,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar6);
  }
  USBSTOR_LogEntry(0x74647170,(longlong)iVar6,0,0);
  return iVar6;
}



===== USBSTOR_QueryWmiDataBlock @ 140029160 =====

void USBSTOR_QueryWmiDataBlock
               (longlong param_1,undefined8 param_2,int param_3,undefined8 param_4,
               undefined8 param_5,undefined4 *param_6,int param_7,undefined8 param_8)

{
  ulonglong uVar1;
  undefined4 uVar2;
  
  if ((param_3 == 1) && (uVar2 = 1, param_7 != 0)) {
    uVar1 = USBSTOR_IsSelectiveSuspendEnabled(*(longlong *)(param_1 + 0x40));
    *(bool *)param_8 = (char)uVar1 != '\0';
    *param_6 = uVar2;
  }
  WmiCompleteRequest(param_1);
  return;
}



===== DriverEntry @ 1400291d0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DriverEntry(longlong param_1,short *param_2)

{
  undefined8 uVar1;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  if (DAT_14001a158 == '\0') {
    wil_InitializeFeatureStaging();
  }
  _WPP_MAIN_CB = 0;
  DAT_14001a288 = &WPP_ThisDir_CTLGUID_wppCtlGuid;
  DAT_14001a290 = 0;
  _DAT_14001a2a0 = 0;
  _DAT_14001a2a8 = 1;
  WppLoadTracingSupport();
  _DAT_14001a2a0 = 0;
  WppInitKm();
  USBSTOR_QueryBreakOnDeviceFailure();
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  USBSTOR_LogInit();
  _DAT_14001a1ca = *param_2 + 2;
  _DAT_14001a1c8 = *param_2;
  DAT_14001a1d0 = ExAllocatePool2(0x100,_DAT_14001a1ca,0x53414d55);
  if (DAT_14001a1d0 == 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
    }
    if (DAT_14001a158 == '\0') {
      wil_UninitializeFeatureStaging();
    }
    uVar1 = 0xc000009a;
  }
  else {
    RtlCopyUnicodeString(&DAT_14001a1c8,param_2);
    *(code **)(param_1 + 0x68) = USBSTOR_Unload;
    *(code **)(*(longlong *)(param_1 + 0x30) + 8) = USBSTOR_AddDevice;
    *(code **)(param_1 + 0x70) = USBSTOR_Create;
    *(code **)(param_1 + 0x80) = USBSTOR_Close;
    *(code **)(param_1 + 0x88) = USBSTOR_ReadWrite;
    *(code **)(param_1 + 0x90) = USBSTOR_ReadWrite;
    *(code **)(param_1 + 0xe0) = USBSTOR_DeviceControl;
    *(code **)(param_1 + 0xe8) = USBSTOR_Scsi;
    *(code **)(param_1 + 0x60) = USBSTOR_StartIo;
    *(code **)(param_1 + 0x120) = USBSTOR_Power;
    *(code **)(param_1 + 0x128) = USBSTOR_SystemControl;
    *(code **)(param_1 + 0x148) = USBSTOR_Pnp;
    USBSTOR_PreInitializeEmergencyWorkerThread();
    RtlInitUnicodeString(&local_18,L"KseQueryDeviceFlags");
    USBSTOR_KseQueryDeviceFlags = MmGetSystemRoutineAddress(&local_18);
    McGenEventRegister_EtwRegister();
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
              &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== USBSTOR_GetDescriptors @ 140029440 =====

int USBSTOR_GetDescriptors(longlong param_1)

{
  ushort uVar1;
  longlong lVar2;
  int iVar3;
  undefined2 uVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong local_res8;
  undefined8 in_stack_ffffffffffffffc0;
  
  local_res8 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  lVar5 = param_1;
  USBSTOR_LogEntry(0x43534447,param_1,0,0);
  lVar2 = *(longlong *)(param_1 + 0x40);
  iVar3 = USBSTOR_GetDescriptor(param_1,lVar5,'\x01',0,0,in_stack_ffffffffffffffc0,0x12,&local_res8)
  ;
  if (iVar3 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_1400296a6;
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar4 = 0x40;
LAB_140029509:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
              &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
    }
  }
  else {
    *(longlong *)(lVar2 + 0x30) = local_res8;
    iVar3 = USBSTOR_GetDescriptor(param_1,lVar5,'\x02',0,0,in_stack_ffffffffffffffc0,9,&local_res8);
    if (iVar3 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_1400296a6;
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar4 = 0x41;
        goto LAB_140029509;
      }
    }
    else {
      uVar6 = 0;
      uVar1 = *(ushort *)(local_res8 + 2);
      ExFreePoolWithTag();
      if (uVar1 < 9) {
        iVar3 = -0x3fffff64;
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_1400296a6;
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar4 = 0x42;
          goto LAB_140029509;
        }
      }
      else {
        iVar3 = USBSTOR_GetDescriptor
                          (param_1,uVar6,'\x02',0,0,in_stack_ffffffffffffffc0,(uint)uVar1,
                           &local_res8);
        if (iVar3 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_1400296a6;
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar4 = 0x43;
            goto LAB_140029509;
          }
        }
        else if (uVar1 == *(ushort *)(local_res8 + 2)) {
          *(longlong *)(lVar2 + 0x38) = local_res8;
          if (*(char *)(*(longlong *)(lVar2 + 0x30) + 0x10) != '\0') {
            USBSTOR_GetStringDescriptors(param_1);
          }
        }
        else {
          iVar3 = -0x3fffff64;
          ExFreePoolWithTag(local_res8,0);
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_1400296a6;
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar4 = 0x44;
            goto LAB_140029509;
          }
        }
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,
             &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar3);
  }
LAB_1400296a6:
  USBSTOR_LogEntry(0x63736467,(longlong)iVar3,0,0);
  return iVar3;
}



===== USBSTOR_GetStringDescriptors @ 1400296dc =====

int USBSTOR_GetStringDescriptors(longlong param_1)

{
  byte bVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  undefined2 uVar7;
  undefined8 uVar8;
  byte *pbVar9;
  byte *local_res8;
  undefined8 in_stack_ffffffffffffffc0;
  
  local_res8 = (byte *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0)) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  uVar8 = 0;
  lVar6 = param_1;
  USBSTOR_LogEntry(0x43445347,param_1,0,0);
  lVar2 = *(longlong *)(param_1 + 0x40);
  pbVar9 = (byte *)CONCAT71((int7)((ulonglong)uVar8 >> 8),3);
  iVar3 = USBSTOR_GetDescriptor
                    (param_1,lVar6,'\x03',0,0,in_stack_ffffffffffffffc0,2,(longlong *)&local_res8);
  if (iVar3 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140029a85;
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      lVar6 = 0x47;
LAB_1400297ab:
      pbVar9 = &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(short)lVar6,
               &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,iVar3);
    }
  }
  else {
    lVar6 = 0;
    bVar1 = *local_res8;
    ExFreePoolWithTag();
    if ((bVar1 < 4) || ((bVar1 & 1) != 0)) {
      iVar3 = -0x3fffff64;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140029a85;
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        lVar6 = 0x48;
LAB_140029a4b:
        pbVar9 = &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(short)lVar6,
                 &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids,(uint)bVar1);
      }
    }
    else {
      pbVar9 = (byte *)CONCAT71((int7)((ulonglong)pbVar9 >> 8),3);
      iVar3 = USBSTOR_GetDescriptor
                        (param_1,lVar6,'\x03',0,0,in_stack_ffffffffffffffc0,(uint)bVar1,
                         (longlong *)&local_res8);
      if (iVar3 < 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140029a85;
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          lVar6 = 0x49;
          goto LAB_1400297ab;
        }
      }
      else if (bVar1 == *local_res8) {
        uVar7 = *(undefined2 *)(local_res8 + 2);
        uVar5 = 2;
        uVar4 = (uint)((ulonglong)bVar1 - 2 >> 1);
        if (1 < uVar4) {
          do {
            if (*(short *)(local_res8 + (ulonglong)uVar5 * 2) == 0x409) {
              uVar7 = 0x409;
              break;
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 <= uVar4);
        }
        lVar6 = 0;
        pbVar9 = local_res8;
        ExFreePoolWithTag(local_res8);
        pbVar9 = (byte *)CONCAT71((int7)((ulonglong)pbVar9 >> 8),3);
        iVar3 = USBSTOR_GetDescriptor
                          (param_1,lVar6,'\x03',*(undefined1 *)(*(longlong *)(lVar2 + 0x30) + 0x10),
                           uVar7,in_stack_ffffffffffffffc0,2,(longlong *)&local_res8);
        if (iVar3 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140029a85;
          if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            lVar6 = 0x4b;
            goto LAB_1400297ab;
          }
        }
        else {
          lVar6 = 0;
          bVar1 = *local_res8;
          ExFreePoolWithTag();
          if ((bVar1 < 4) || ((bVar1 & 1) != 0)) {
            iVar3 = -0x3fffff64;
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140029a85;
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              lVar6 = 0x4c;
              goto LAB_140029a4b;
            }
          }
          else {
            pbVar9 = (byte *)CONCAT71((int7)((ulonglong)pbVar9 >> 8),3);
            iVar3 = USBSTOR_GetDescriptor
                              (param_1,lVar6,'\x03',
                               *(undefined1 *)(*(longlong *)(lVar2 + 0x30) + 0x10),uVar7,
                               in_stack_ffffffffffffffc0,(uint)bVar1,(longlong *)&local_res8);
            if (iVar3 < 0) {
              if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140029a85;
              if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                lVar6 = 0x4d;
                goto LAB_1400297ab;
              }
            }
            else if (bVar1 == *local_res8) {
              *(byte **)(lVar2 + 0x48) = local_res8;
            }
            else {
              lVar6 = 0;
              ExFreePoolWithTag();
              if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140029a85;
              if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                lVar6 = 0x4e;
                goto LAB_140029a4b;
              }
            }
          }
        }
      }
      else {
        lVar6 = 0;
        pbVar9 = local_res8;
        ExFreePoolWithTag(local_res8);
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140029a85;
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          lVar6 = 0x4a;
          goto LAB_140029a4b;
        }
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 8 & 1) != 0)) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar6,pbVar9,iVar3,
              (char)*(undefined8 *)(lVar2 + 0x48));
  }
LAB_140029a85:
  USBSTOR_LogEntry(0x63736467,(longlong)iVar3,0,0);
  return iVar3;
}



===== USBSTOR_Unload @ 140029ac0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void USBSTOR_Unload(undefined8 param_1)

{
  longlong lVar1;
  undefined *puVar2;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
            &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
  }
  USBSTOR_LogEntry(0x444c4e55,param_1,0,0);
  lVar1 = DAT_14001a1a8;
  DAT_14001a1a8 = 0;
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0);
  }
  lVar1 = DAT_14001a1d8;
  DAT_14001a1d8 = 0;
  if (lVar1 != 0) {
    ExFreePoolWithTag(lVar1,0);
  }
  McGenEventUnregister_EtwUnregister();
  if (DAT_14001a1d0 != 0) {
    ExFreePoolWithTag(DAT_14001a1d0,0);
    DAT_14001a1d0 = 0;
  }
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
              &WPP_59913c46929e3668b4e32144c6d0c58c_Traceguids);
    }
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      puVar2 = WPP_GLOBAL_Control;
      if (WPPTraceSuite == 4) {
        for (; puVar2 != (undefined *)0x0; puVar2 = *(undefined **)(puVar2 + 0x10)) {
          if (*(longlong *)(puVar2 + 0x38) != 0) {
            (*pfnEtwUnregister)();
            *(undefined8 *)(puVar2 + 0x38) = 0;
          }
        }
      }
      else if (WPPTraceSuite == 2) {
        IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
      }
      WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
    }
  }
  if (DAT_14001a158 == '\0') {
    wil_UninitializeFeatureStaging();
  }
  return;
}



===== entry @ 14002b010 =====

void entry(longlong param_1,short *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14002b044 =====

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



===== wil_InitializeFeatureStaging @ 14002b078 =====

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
    ppuVar4 = &wil_details_featureDescriptors_a;
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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14002b168 =====

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
  ppuVar3 = &wil_details_featureDescriptors_a;
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


