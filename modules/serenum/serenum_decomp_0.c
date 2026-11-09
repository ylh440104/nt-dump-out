
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



===== SerenumCheckEnumerations @ 140001020 =====

int SerenumCheckEnumerations(longlong *param_1)

{
  longlong *plVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  uint uVar7;
  undefined1 local_res8 [8];
  
  local_res8[0] = 1;
  iVar2 = (int)param_1[0x16];
  if (iVar2 == 0) {
    plVar1 = param_1 + 0x17;
    uVar3 = KeAcquireSpinLockRaiseToDpc(plVar1);
    uVar7 = *(uint *)(param_1 + 0x18);
    if (uVar7 == 0) {
      *(undefined4 *)(param_1 + 0x18) = 1;
      KeReleaseSpinLock(plVar1,uVar3);
      iVar4 = SerenumStartProtocolThread(param_1);
    }
    else if (((byte)uVar7 & 5) == 4) {
      *(uint *)(param_1 + 0x18) = uVar7 & 0xfffffffb;
      KeReleaseSpinLock(plVar1,CONCAT31((int3)((uVar7 & 0xfffffffb) >> 8),uVar3));
      lVar5 = IoAllocateIrp(*(char *)(param_1[9] + 0x4c) + '\x01',0);
      if (lVar5 == 0) {
        iVar4 = -0x3fffff66;
      }
      else {
        *(char *)(lVar5 + 0x43) = *(char *)(lVar5 + 0x43) + -1;
        *(longlong *)(lVar5 + 0xb8) = *(longlong *)(lVar5 + 0xb8) + -0x48;
        uVar6 = Serenum_ReenumerateDevices(lVar5,param_1,local_res8);
        iVar4 = (int)uVar6;
        IoFreeIrp(lVar5);
        uVar3 = KeAcquireSpinLockRaiseToDpc(plVar1);
        if (iVar4 == 0) {
          param_1[4] = param_1[5];
          param_1[6] = param_1[7];
          *(undefined1 *)((longlong)param_1 + 0x1a) = *(undefined1 *)((longlong)param_1 + 0x1b);
          *(undefined1 *)((longlong)param_1 + 0x1d) = *(undefined1 *)((longlong)param_1 + 0x1c);
        }
        KeReleaseSpinLock(plVar1,uVar3);
      }
    }
    else {
      if ((uVar7 & 2) != 0) {
        uVar7 = uVar7 & 0xfffffffd;
        param_1[4] = param_1[5];
        param_1[6] = param_1[7];
        *(undefined1 *)((longlong)param_1 + 0x1a) = *(undefined1 *)((longlong)param_1 + 0x1b);
        *(undefined1 *)((longlong)param_1 + 0x1d) = *(undefined1 *)((longlong)param_1 + 0x1c);
        *(uint *)(param_1 + 0x18) = uVar7;
      }
      KeReleaseSpinLock(plVar1,CONCAT31((int3)(uVar7 >> 8),uVar3));
      iVar4 = 0;
    }
  }
  else {
    iVar4 = 0;
    if (iVar2 != -1) {
      *(int *)(param_1 + 0x16) = iVar2 + -1;
    }
  }
  return iVar4;
}



===== SerenumMarkPdoRemoved @ 1400011c0 =====

void SerenumMarkPdoRemoved(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xb8);
  *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 4;
  KeReleaseSpinLock(param_1 + 0xb8,uVar1);
  return;
}



===== SerenumEnumThread @ 140001210 =====

void SerenumEnumThread(longlong *param_1)

{
  undefined1 uVar1;
  longlong lVar2;
  ulonglong uVar3;
  int iVar4;
  char local_res8 [8];
  
  local_res8[0] = '\x01';
  KeSetPriorityThread(SystemReserved1[0xf],0x1f);
  lVar2 = IoAllocateIrp(*(char *)(param_1[9] + 0x4c) + '\x01',0);
  if (lVar2 == 0) {
    iVar4 = -0x3fffff66;
  }
  else {
    *(char *)(lVar2 + 0x43) = *(char *)(lVar2 + 0x43) + -1;
    *(longlong *)(lVar2 + 0xb8) = *(longlong *)(lVar2 + 0xb8) + -0x48;
    uVar3 = Serenum_ReenumerateDevices(lVar2,param_1,local_res8);
    iVar4 = (int)uVar3;
    IoFreeIrp(lVar2);
  }
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x17);
  if ((iVar4 == 0) && (local_res8[0] == '\0')) {
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 2;
  }
  KeReleaseSpinLock(param_1 + 0x17,uVar1);
  if ((iVar4 == 0) && (local_res8[0] == '\0')) {
    IoInvalidateDeviceRelations(param_1[8],0);
  }
  IoQueueWorkItem(param_1[0x1a],SerenumEnumThreadWorkItem,1,param_1);
  PsTerminateSystemThread(0);
  return;
}



===== SerenumEnumThreadWorkItem @ 140001340 =====

void SerenumEnumThreadWorkItem(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_2 + 0xb8);
  lVar1 = *(longlong *)(param_2 + 200);
  if (lVar1 != 0) {
    *(undefined8 *)(param_2 + 200) = 0;
    *(uint *)(param_2 + 0xc0) = *(uint *)(param_2 + 0xc0) & 0xfffffffe;
  }
  uVar2 = *(undefined8 *)(param_2 + 0xd0);
  *(undefined8 *)(param_2 + 0xd0) = 0;
  KeReleaseSpinLock(param_2 + 0xb8,uVar3);
  if (lVar1 != 0) {
    ObfDereferenceObject(lVar1);
  }
  IoFreeWorkItem(uVar2);
  return;
}



===== SerenumStartProtocolThread @ 1400013e8 =====

int SerenumStartProtocolThread(undefined8 *param_1)

{
  undefined1 uVar1;
  int iVar2;
  longlong lVar3;
  undefined8 local_res8;
  undefined8 local_res10;
  
  local_res8 = 0;
  local_res10 = 0;
  lVar3 = IoAllocateWorkItem(*param_1);
  if (lVar3 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    param_1[0x1a] = lVar3;
    iVar2 = PsCreateSystemThread(&local_res8,0x1fffff,0,0,0,SerenumEnumThread,param_1);
    if (iVar2 < 0) {
      param_1[0x1a] = 0;
      IoFreeWorkItem(lVar3);
    }
    else {
      iVar2 = ObReferenceObjectByHandle(local_res8,0x1fffff,0,0,&local_res10,0);
      uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x17);
      if (iVar2 < 0) {
        param_1[0x19] = 0;
        param_1[0x1a] = 0;
      }
      else {
        param_1[0x19] = local_res10;
      }
      KeReleaseSpinLock(param_1 + 0x17,uVar1);
      ZwClose(local_res8);
    }
  }
  return iVar2;
}



===== SerenumWaitForEnumThreadTerminate @ 140001524 =====

void SerenumWaitForEnumThreadTerminate(longlong param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0xb8);
  lVar1 = *(longlong *)(param_1 + 200);
  if (lVar1 != 0) {
    *(undefined8 *)(param_1 + 200) = 0;
    *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) & 0xfffffffe;
  }
  KeReleaseSpinLock(param_1 + 0xb8,uVar2);
  if (lVar1 != 0) {
    KeWaitForSingleObject(lVar1,0,0,0,0);
    ObfDereferenceObject(lVar1);
  }
  return;
}



===== Serenum_EnumComplete @ 1400015c0 =====

undefined8 Serenum_EnumComplete(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  undefined8 uVar1;
  
  if (param_3 == 0) {
    uVar1 = 0xc000000d;
  }
  else {
    KeSetEvent(param_3,0,0);
    uVar1 = 0xc0000016;
  }
  return uVar1;
}



===== Serenum_GetRegistryKeyValue @ 1400015f8 =====

uint Serenum_GetRegistryKeyValue
               (undefined8 param_1,undefined8 param_2,int param_3,void *param_4,uint param_5,
               undefined4 *param_6)

{
  uint uVar1;
  longlong lVar2;
  bool bVar3;
  int local_res18 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_28 = 0;
  uStack_20 = 0;
  uVar1 = 0xc000009a;
  RtlInitUnicodeString(&local_28);
  local_res18[0] = param_5 + 0x18 + param_3;
  lVar2 = ExAllocatePool2(0x100,local_res18[0],0x6d6e6553);
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = 0;
  }
  if (lVar2 != 0) {
    uVar1 = ZwQueryValueKey(param_1,&local_28,1,lVar2,local_res18[0],local_res18);
    if ((-1 < (int)uVar1) && (*(uint *)(lVar2 + 0xc) <= param_5)) {
      memmove(param_4,(void *)((ulonglong)*(uint *)(lVar2 + 8) + lVar2),
              (ulonglong)*(uint *)(lVar2 + 0xc));
      if (param_6 != (undefined4 *)0x0) {
        *param_6 = *(undefined4 *)(lVar2 + 0xc);
      }
    }
    ExFreePoolWithTag(lVar2,0);
    if ((((int)uVar1 < 0) && ((uVar1 & 0xc0000000) != 0xc0000000)) &&
       (bVar3 = uVar1 == 0x80000005, uVar1 = 0xc0000001, bVar3)) {
      uVar1 = 0xc0000023;
    }
  }
  return uVar1;
}



===== Serenum_PDO_EnumMarkMissing @ 14000172c =====

void Serenum_PDO_EnumMarkMissing(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc();
  *(undefined1 *)(param_2 + 0x81) = 0;
  *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 2;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined2 *)(param_1 + 0x1b) = 0;
  KeReleaseSpinLock(param_1 + 0xb8,uVar1);
  return;
}



===== Serenum_CreateClose @ 1400017a0 =====

int Serenum_CreateClose(longlong param_1,longlong param_2)

{
  char *pcVar1;
  undefined8 uVar2;
  int iVar3;
  longlong lVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  pcVar1 = *(char **)(param_2 + 0xb8);
  local_18 = 0;
  lVar4 = *(longlong *)(param_1 + 0x40);
  iVar3 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (*(char *)(lVar4 + 8) == '\0') {
    lVar4 = *(longlong *)(*(longlong *)(lVar4 + 0x18) + 0x40);
  }
  uVar2 = *(undefined8 *)(lVar4 + 0x48);
  if (*pcVar1 == '\0') {
    iVar3 = Serenum_DispatchPassThrough(param_1,param_2);
  }
  else if (*pcVar1 == '\x02') {
    *(undefined8 *)(pcVar1 + -0x48) = *(undefined8 *)pcVar1;
    *(undefined8 *)(pcVar1 + -0x40) = *(undefined8 *)(pcVar1 + 8);
    *(undefined8 *)(pcVar1 + -0x38) = *(undefined8 *)(pcVar1 + 0x10);
    *(undefined8 *)(pcVar1 + -0x30) = *(undefined8 *)(pcVar1 + 0x18);
    *(undefined4 *)(pcVar1 + -0x28) = *(undefined4 *)(pcVar1 + 0x20);
    *(undefined4 *)(pcVar1 + -0x24) = *(undefined4 *)(pcVar1 + 0x24);
    *(undefined4 *)(pcVar1 + -0x20) = *(undefined4 *)(pcVar1 + 0x28);
    *(undefined4 *)(pcVar1 + -0x1c) = *(undefined4 *)(pcVar1 + 0x2c);
    *(undefined8 *)(pcVar1 + -0x18) = *(undefined8 *)(pcVar1 + 0x30);
    pcVar1[-0x45] = '\0';
    KeInitializeEvent(&local_28,1);
    lVar4 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar4 + -0x10) = Serenum_EnumComplete;
    *(undefined8 **)(lVar4 + -8) = &local_28;
    *(undefined1 *)(lVar4 + -0x45) = 0xe0;
    iVar3 = IofCallDriver(uVar2,param_2);
    if (iVar3 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
    }
    iVar3 = *(int *)(param_2 + 0x30);
    IofCompleteRequest(param_2,0);
  }
  return iVar3;
}



===== Serenum_DecIoCount @ 1400018c8 =====

void Serenum_DecIoCount(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x50);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    KeSetEvent(param_1 + 0x58,0,0);
  }
  return;
}



===== Serenum_DispatchPassThrough @ 140001900 =====

int Serenum_DispatchPassThrough(longlong param_1,longlong param_2)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  bVar1 = false;
  if (*(char *)(lVar3 + 8) == '\0') {
    lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x18) + 0x40);
  }
  if (**(char **)(param_2 + 0xb8) == '\0') {
    bVar1 = true;
    iVar2 = KeWaitForSingleObject(lVar3 + 0x88,0,0,0,0);
    if (iVar2 < 0) {
      *(int *)(param_2 + 0x30) = iVar2;
      IofCompleteRequest(param_2,0);
      return iVar2;
    }
  }
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  iVar2 = IofCallDriver(*(undefined8 *)(lVar3 + 0x48),param_2);
  if (bVar1) {
    KeReleaseSemaphore(lVar3 + 0x88,0,1);
  }
  return iVar2;
}



===== Serenum_IncIoCount @ 1400019e4 =====

undefined8 Serenum_IncIoCount(longlong param_1)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  
  LOCK();
  *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;
  UNLOCK();
  if (*(char *)(param_1 + 9) == '\0') {
    uVar3 = 0;
  }
  else {
    LOCK();
    piVar1 = (int *)(param_1 + 0x50);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      KeSetEvent(param_1 + 0x58,0,0);
    }
    uVar3 = 0xc0000056;
  }
  return uVar3;
}



===== Serenum_InitPDO @ 140001a2c =====

void Serenum_InitPDO(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  undefined1 uVar3;
  
  plVar1 = *(longlong **)(param_1 + 0x40);
  if ((*(uint *)(*param_2 + 0x30) & 4) == 0) {
    if ((*(uint *)(*param_2 + 0x30) & 0x10) != 0) {
      *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x10;
    }
  }
  else {
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 4;
  }
  *(char *)(param_1 + 0x4c) = *(char *)(param_1 + 0x4c) + *(char *)(*param_2 + 0x4c);
  *(undefined1 *)(plVar1 + 1) = 0;
  *plVar1 = param_1;
  lVar2 = *param_2;
  *(undefined1 *)((longlong)plVar1 + 9) = 0;
  plVar1[3] = lVar2;
  *(undefined2 *)(plVar1 + 0x10) = 0x100;
  *(undefined4 *)((longlong)plVar1 + 0xc) = *(undefined4 *)((longlong)param_2 + 0xc);
  *(undefined4 *)((longlong)plVar1 + 0x14) = 1;
  *(undefined4 *)(plVar1 + 2) = 1;
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x17);
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) | 2;
  param_2[5] = param_1;
  param_2[7] = (longlong)plVar1;
  *(undefined1 *)((longlong)param_2 + 0x1b) = 1;
  KeReleaseSpinLock(param_2 + 0x17,uVar3);
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xffffff7f | 0x2000;
  return;
}



===== Serenum_InternIoCtl @ 140001b10 =====

int Serenum_InternIoCtl(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(char *)(lVar1 + 8) == '\0') {
    if (*(char *)(lVar1 + 9) == '\0') {
      if (*(int *)(*(longlong *)(param_2 + 0xb8) + 0x18) != 0x370207) goto LAB_140001b31;
      *(undefined1 *)(*(longlong *)(*(longlong *)(lVar1 + 0x18) + 0x40) + 0x1d) = 1;
      Serenum_PDO_EnumMarkMissing
                (*(longlong *)(*(longlong *)(lVar1 + 0x18) + 0x40),*(longlong *)(param_1 + 0x40));
      IoInvalidateDeviceRelations
                (*(undefined8 *)(*(longlong *)(*(longlong *)(lVar1 + 0x18) + 0x40) + 0x40),0);
      iVar2 = 0;
    }
    else {
      iVar2 = -0x3fffffaa;
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(int *)(param_2 + 0x30) = iVar2;
    IofCompleteRequest(param_2,0);
  }
  else {
LAB_140001b31:
    iVar2 = Serenum_DispatchPassThrough(param_1,param_2);
  }
  return iVar2;
}



===== Serenum_IoCtl @ 140001bc0 =====

uint Serenum_IoCtl(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  void *pvVar3;
  uint uVar4;
  undefined8 uVar5;
  uint local_res8 [2];
  undefined8 local_res10;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_res10 = 0;
  local_res8[0] = 0;
  lVar2 = *(longlong *)(param_2 + 0xb8);
  pvVar3 = *(void **)(param_2 + 0x18);
  if (*(char *)(lVar1 + 8) == '\0') {
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = lVar2 + 0x48;
    uVar4 = IofCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x18));
  }
  else {
    uVar5 = Serenum_IncIoCount(lVar1);
    uVar4 = (uint)uVar5;
    if ((int)uVar4 < 0) {
      *(undefined8 *)(param_2 + 0x38) = 0;
    }
    else {
      if (*(int *)(lVar2 + 0x18) != 0x37020c) {
        Serenum_DecIoCount(lVar1);
        uVar4 = Serenum_DispatchPassThrough(param_1,param_2);
        return uVar4;
      }
      uVar4 = IoOpenDeviceRegistryKey(*(undefined8 *)(lVar1 + 0x40),1,0x20000,&local_res10);
      if ((int)uVar4 < 0) {
        *(undefined8 *)(param_2 + 0x38) = 0;
      }
      else {
        uVar4 = Serenum_GetRegistryKeyValue
                          (local_res10,L"PortName",0x12,pvVar3,*(uint *)(lVar2 + 8),local_res8);
        if ((uVar4 == 0xc0000034) || (uVar4 == 0xc000000d)) {
          uVar4 = Serenum_GetRegistryKeyValue
                            (local_res10,L"Identifier",0x16,pvVar3,*(uint *)(lVar2 + 8),local_res8);
        }
        *(ulonglong *)(param_2 + 0x38) = (ulonglong)local_res8[0];
        ZwClose(local_res10);
      }
      Serenum_DecIoCount(lVar1);
    }
    *(uint *)(param_2 + 0x30) = uVar4;
    IofCompleteRequest(param_2,0);
  }
  return uVar4;
}



===== Serenum_FDOPowerComplete @ 140001d40 =====

undefined8 Serenum_FDOPowerComplete(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  undefined8 *puVar3;
  
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  lVar2 = *(longlong *)(param_2 + 0xb8);
  puVar3 = *(undefined8 **)(param_1 + 0x40);
  if ((*(char *)(lVar2 + 1) == '\x02') && (*(int *)(lVar2 + 0x10) == 1)) {
    *(undefined4 *)((longlong)puVar3 + 0x14) = *(undefined4 *)(lVar2 + 0x18);
    PoSetPowerState(*puVar3);
  }
  PoStartNextPowerIrp(param_2);
  Serenum_DecIoCount((longlong)puVar3);
  return 0;
}



===== Serenum_FDO_Power @ 140001dbc =====

ulonglong Serenum_FDO_Power(undefined8 *param_1,longlong param_2)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  bool bVar5;
  uint uVar6;
  ulonglong uVar7;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  bVar5 = false;
  iVar1 = *(int *)(lVar3 + 0x10);
  iVar2 = *(int *)(lVar3 + 0x18);
  uVar7 = Serenum_IncIoCount((longlong)param_1);
  if ((int)uVar7 < 0) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(int *)(param_2 + 0x30) = (int)uVar7;
    PoStartNextPowerIrp(param_2);
    IofCompleteRequest(param_2,0);
    return uVar7 & 0xffffffff;
  }
  if (*(char *)(lVar3 + 1) == '\x02') {
    if (*(char *)((longlong)param_1 + 0x19) == '\x01') {
      if (iVar1 == 1) {
        *(undefined4 *)(param_2 + 0x30) = 0;
        if (*(int *)((longlong)param_1 + 0x14) < iVar2) {
          PoSetPowerState(*param_1,1,iVar2);
          *(int *)((longlong)param_1 + 0x14) = iVar2;
        }
        else {
          bVar5 = false;
          if (iVar2 < *(int *)((longlong)param_1 + 0x14)) {
            bVar5 = true;
          }
        }
      }
      goto LAB_140001e7b;
    }
  }
  else if (*(char *)(lVar3 + 1) != '\x03') goto LAB_140001e7b;
  *(undefined4 *)(param_2 + 0x30) = 0;
LAB_140001e7b:
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
  if (bVar5) {
    Serenum_IncIoCount((longlong)param_1);
    lVar3 = *(longlong *)(param_2 + 0xb8);
    *(undefined8 *)(lVar3 + -8) = 0;
    *(code **)(lVar3 + -0x10) = Serenum_FDOPowerComplete;
    *(undefined1 *)(lVar3 + -0x45) = 0xe0;
  }
  else {
    PoStartNextPowerIrp(param_2);
  }
  uVar6 = PoCallDriver(param_1[9],param_2);
  Serenum_DecIoCount((longlong)param_1);
  return (ulonglong)uVar6;
}



===== Serenum_PDO_Power @ 140001f28 =====

undefined4 Serenum_PDO_Power(undefined8 *param_1,longlong param_2)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  undefined4 uVar4;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  uVar4 = 0;
  cVar1 = *(char *)(lVar3 + 1);
  iVar2 = *(int *)(lVar3 + 0x18);
  if ((cVar1 != '\0') && (cVar1 != '\x01')) {
    if (cVar1 != '\x02') {
      if (cVar1 != '\x03') {
        uVar4 = *(undefined4 *)(param_2 + 0x30);
      }
      goto LAB_140001fa5;
    }
    if (*(int *)(lVar3 + 0x10) == 0) goto LAB_140001fa5;
    if (*(int *)(lVar3 + 0x10) == 1) {
      if ((iVar2 < *(int *)((longlong)param_1 + 0x14)) ||
         (*(int *)((longlong)param_1 + 0x14) < iVar2)) {
        PoSetPowerState(*param_1,1,iVar2);
        *(int *)((longlong)param_1 + 0x14) = iVar2;
      }
      goto LAB_140001fa5;
    }
  }
  uVar4 = 0xc0000002;
LAB_140001fa5:
  *(undefined4 *)(param_2 + 0x30) = uVar4;
  PoStartNextPowerIrp(param_2);
  IofCompleteRequest(param_2,0);
  return uVar4;
}



===== Serenum_Power @ 140001ff0 =====

void Serenum_Power(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0x40);
  if (*(char *)(puVar1 + 1) == '\0') {
    Serenum_PDO_Power(puVar1,param_2);
  }
  else {
    Serenum_FDO_Power(puVar1,param_2);
  }
  return;
}



===== _guard_check_icall @ 140002020 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140002038 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000205c =====

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



===== __cpu_features_init @ 1400020d0 =====

/* WARNING: Removing unreachable block (ram,0x00014000213a) */
/* WARNING: Removing unreachable block (ram,0x0001400020e9) */
/* WARNING: Removing unreachable block (ram,0x0001400020da) */

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



===== __security_check_cookie @ 1400021a0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1400021e0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140002210 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140002210. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140002240 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 1400022c0 =====

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



===== memset @ 1400025c0 =====

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



===== __memset_repmovs @ 140002700 =====

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



===== __memset_query @ 140002780 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140002800 =====

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



===== __memset_spec_ermsb_repmovsb @ 140002940 =====

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



===== __memset_spec_plain @ 1400029c0 =====

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



===== Serenum_AddDevice @ 140008010 =====

ulonglong Serenum_AddDevice(undefined8 param_1,longlong param_2)

{
  longlong *_Dst;
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  int local_res18 [2];
  longlong local_res20;
  undefined8 local_38 [2];
  
  local_res20 = 0;
  local_38[0] = 0;
  local_res18[0] = 0;
  uVar1 = IoCreateDevice(param_1,0xe0,0,0x2a,0,1,&local_res20);
  uVar3 = (ulonglong)uVar1;
  if (-1 < (int)uVar1) {
    _Dst = *(longlong **)(local_res20 + 0x40);
    memset(_Dst,0,0xe0);
    *(undefined1 *)(_Dst + 1) = 1;
    _Dst[4] = 0;
    *(undefined4 *)(_Dst + 0x10) = 0;
    *(undefined4 *)((longlong)_Dst + 0x84) = 0;
    *_Dst = local_res20;
    *(undefined1 *)((longlong)_Dst + 0x1a) = 0;
    *(undefined4 *)((longlong)_Dst + 0x14) = 1;
    *(undefined4 *)(_Dst + 2) = 1;
    *(undefined1 *)((longlong)_Dst + 0x1d) = 0;
    *(undefined1 *)((longlong)_Dst + 9) = 0;
    _Dst[8] = param_2;
    lVar2 = IoAttachDeviceToDeviceStack(local_res20,param_2);
    _Dst[9] = lVar2;
    if (lVar2 == 0) {
      uVar3 = 0xc0000001;
    }
    else {
      if ((*(uint *)(lVar2 + 0x30) & 4) == 0) {
        if ((*(uint *)(lVar2 + 0x30) & 0x10) != 0) {
          *(uint *)(local_res20 + 0x30) = *(uint *)(local_res20 + 0x30) | 0x10;
        }
      }
      else {
        *(uint *)(local_res20 + 0x30) = *(uint *)(local_res20 + 0x30) | 4;
      }
      *(undefined4 *)(_Dst + 10) = 1;
      KeInitializeEvent(_Dst + 0xb,1,0);
      KeInitializeSemaphore(_Dst + 0x11,1,1);
      KeInitializeSpinLock(_Dst + 0x17);
      uVar1 = IoRegisterDeviceInterface
                        (param_2,&GUID_DEVINTERFACE_SERENUM_BUS_ENUMERATOR,0,_Dst + 0xe);
      uVar3 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        uVar3 = IoSetDeviceInterfaceState(_Dst + 0xe,1);
        if ((int)uVar3 < 0) {
          return uVar3;
        }
        uVar1 = IoOpenDeviceRegistryKey(_Dst[8],1,0x20000,local_38);
        uVar3 = (ulonglong)uVar1;
        if (uVar1 == 0) {
          uVar1 = Serenum_GetRegistryKeyValue
                            (local_38[0],L"SkipEnumerations",0x22,_Dst + 0x16,4,local_res18);
          if ((uVar1 != 0) || (local_res18[0] != 4)) {
            *(undefined4 *)(_Dst + 0x16) = 0;
          }
          uVar3 = 0;
          ZwClose(local_38[0]);
        }
        else if ((int)uVar1 < 0) {
          return uVar3;
        }
        *(uint *)(local_res20 + 0x30) = *(uint *)(local_res20 + 0x30) | 0x2000;
        *(uint *)(local_res20 + 0x30) = *(uint *)(local_res20 + 0x30) & 0xffffff7f;
        return uVar3;
      }
      IoDetachDevice(_Dst[9]);
    }
    IoDeleteDevice(local_res20);
  }
  return uVar3;
}



===== Serenum_FDO_PnP @ 140008254 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong Serenum_FDO_PnP(undefined8 param_1,longlong param_2,longlong param_3,longlong *param_4)

{
  longlong *plVar1;
  undefined4 *puVar2;
  char cVar3;
  longlong lVar4;
  uint uVar5;
  int iVar6;
  ulonglong uVar7;
  int *piVar8;
  undefined8 *puVar9;
  code *pcVar10;
  ulonglong uVar11;
  undefined4 local_48 [2];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  
  local_20 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_48[0] = 0;
  uVar7 = Serenum_IncIoCount((longlong)param_4);
  uVar11 = uVar7 & 0xffffffff;
  if ((int)uVar7 < 0) {
    *(int *)(param_2 + 0x30) = (int)uVar7;
    IofCompleteRequest(param_2,0);
    goto LAB_140008793;
  }
  cVar3 = *(char *)(param_3 + 1);
  if (cVar3 == '\0') {
    if (*(char *)((longlong)param_4 + 0x19) == '\0') {
      KeInitializeEvent(&local_30,0,0);
      puVar9 = *(undefined8 **)(param_2 + 0xb8);
      puVar9[-9] = *puVar9;
      puVar9[-8] = puVar9[1];
      puVar9[-7] = puVar9[2];
      puVar9[-6] = puVar9[3];
      *(undefined4 *)(puVar9 + -5) = *(undefined4 *)(puVar9 + 4);
      *(undefined4 *)((longlong)puVar9 + -0x24) = *(undefined4 *)((longlong)puVar9 + 0x24);
      *(undefined4 *)(puVar9 + -4) = *(undefined4 *)(puVar9 + 5);
      *(undefined4 *)((longlong)puVar9 + -0x1c) = *(undefined4 *)((longlong)puVar9 + 0x2c);
      puVar9[-3] = puVar9[6];
      *(undefined1 *)((longlong)puVar9 + -0x45) = 0;
      lVar4 = *(longlong *)(param_2 + 0xb8);
      *(code **)(lVar4 + -0x10) = Serenum_EnumComplete;
      *(undefined8 **)(lVar4 + -8) = &local_30;
      *(undefined1 *)(lVar4 + -0x45) = 0xe0;
      uVar5 = IofCallDriver(param_4[9],param_2);
      if (uVar5 == 0x103) {
        KeWaitForSingleObject(&local_30,0,0,0,0);
        uVar5 = *(uint *)(param_2 + 0x30);
      }
      uVar11 = (ulonglong)uVar5;
      if (-1 < (int)uVar5) {
        puVar9 = (undefined8 *)ExAllocatePool2(0x100,0x70,0x6d6e6553);
        puVar2 = (undefined4 *)((longlong)param_4 + 0xc);
        if (puVar9 == (undefined8 *)0x0) {
          *puVar2 = local_48[0];
        }
        else {
          *puVar9 = 0;
          *(undefined4 *)(puVar9 + 1) = 0x120;
          puVar9[3] = puVar2;
          *(undefined4 *)(puVar9 + 4) = 0x4000004;
          puVar9[2] = L"DebugLevel";
          puVar9[5] = local_48;
          *(undefined4 *)(puVar9 + 6) = 4;
          local_40 = 0;
          uStack_38 = 0;
          RtlInitUnicodeString(&local_40,L"RtlQueryRegistryValuesEx");
          pcVar10 = (code *)MmGetSystemRoutineAddress(&local_40);
          if (pcVar10 == (code *)0x0) {
            pcVar10 = RtlQueryRegistryValues_exref;
          }
          iVar6 = (*pcVar10)(1,L"Serenum",puVar9,0,0);
          if (iVar6 < 0) {
            *puVar2 = local_48[0];
          }
          ExFreePoolWithTag(puVar9,0);
        }
        *(undefined1 *)((longlong)param_4 + 0x19) = 1;
      }
    }
    else {
      uVar11 = 0;
    }
    goto LAB_140008775;
  }
  if (cVar3 == '\x01') {
    SerenumWaitForEnumThreadTerminate((longlong)param_4);
    *(undefined4 *)(param_2 + 0x30) = 0;
    goto LAB_14000848d;
  }
  if (cVar3 == '\x02') {
    SerenumWaitForEnumThreadTerminate((longlong)param_4);
    *(undefined1 *)((longlong)param_4 + 9) = 1;
    IoSetDeviceInterfaceState(param_4 + 0xe,0);
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    *(undefined4 *)(param_2 + 0x30) = 0;
    uVar5 = IofCallDriver(param_4[9],param_2);
    LOCK();
    *(int *)(param_4 + 10) = (int)param_4[10] + -1;
    UNLOCK();
    LOCK();
    plVar1 = param_4 + 10;
    lVar4 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar4 != 1) {
      KeWaitForSingleObject(param_4 + 0xb,0,0,0,0);
    }
    IoDetachDevice(param_4[9]);
    ExFreePoolWithTag(param_4[0xf],0);
    if (param_4[4] != 0) {
      Serenum_PnPRemove(param_4[4],param_4[6]);
      param_4[6] = 0;
      param_4[4] = 0;
      *(undefined1 *)((longlong)param_4 + 0x1a) = 0;
    }
    IoDeleteDevice(param_1);
  }
  else {
    if (cVar3 != '\x04') {
      if (cVar3 == '\x05') {
        if ((param_4[4] != 0) || (uVar11 = 0, (*(uint *)(param_4 + 0x18) & 1) != 0)) {
          uVar11 = 0xc0000001;
        }
        *(int *)(param_2 + 0x30) = (int)uVar11;
        if (-1 < (int)uVar11) goto LAB_14000848d;
LAB_140008778:
        IofCompleteRequest(param_2,0);
      }
      else {
        if (cVar3 == '\x06') goto LAB_1400084b2;
        if (cVar3 == '\a') {
          if (*(int *)(param_3 + 8) == 0) {
            SerenumCheckEnumerations(param_4);
            if (*(uint **)(param_2 + 0x38) == (uint *)0x0) {
              uVar5 = 0;
            }
            else {
              uVar5 = **(uint **)(param_2 + 0x38);
            }
            piVar8 = (int *)ExAllocatePool2(0x40,(*(byte *)((longlong)param_4 + 0x1a) + uVar5) * 8 +
                                                 0x10,0x6d6e6553);
            if (piVar8 == (int *)0x0) {
              uVar11 = 0xc000009a;
              goto LAB_140008775;
            }
            if (uVar5 != 0) {
              memmove(piVar8 + 2,(void *)(*(longlong *)(param_2 + 0x38) + 8),(ulonglong)uVar5 << 3);
            }
            iVar6 = *(byte *)((longlong)param_4 + 0x1a) + uVar5;
            *piVar8 = iVar6;
            if (*(char *)((longlong)param_4 + 0x1a) != '\0') {
              *(longlong *)(piVar8 + (ulonglong)(iVar6 - 1) * 2 + 2) = param_4[4];
              ObfReferenceObject(param_4[4]);
            }
            *(undefined4 *)(param_2 + 0x30) = 0;
            if (*(longlong *)(param_2 + 0x38) != 0) {
              ExFreePoolWithTag(*(longlong *)(param_2 + 0x38),0);
            }
            *(int **)(param_2 + 0x38) = piVar8;
          }
        }
        else if (cVar3 == '\t') {
          KeInitializeEvent(&local_30,0,0);
          puVar9 = *(undefined8 **)(param_2 + 0xb8);
          puVar9[-9] = *puVar9;
          puVar9[-8] = puVar9[1];
          puVar9[-7] = puVar9[2];
          puVar9[-6] = puVar9[3];
          *(undefined4 *)(puVar9 + -5) = *(undefined4 *)(puVar9 + 4);
          *(undefined4 *)((longlong)puVar9 + -0x24) = *(undefined4 *)((longlong)puVar9 + 0x24);
          *(undefined4 *)(puVar9 + -4) = *(undefined4 *)(puVar9 + 5);
          *(undefined4 *)((longlong)puVar9 + -0x1c) = *(undefined4 *)((longlong)puVar9 + 0x2c);
          puVar9[-3] = puVar9[6];
          *(undefined1 *)((longlong)puVar9 + -0x45) = 0;
          lVar4 = *(longlong *)(param_2 + 0xb8);
          *(code **)(lVar4 + -0x10) = Serenum_EnumComplete;
          *(undefined8 **)(lVar4 + -8) = &local_30;
          *(undefined1 *)(lVar4 + -0x45) = 0xe0;
          uVar5 = IofCallDriver(param_4[9],param_2);
          if (uVar5 == 0x103) {
            KeWaitForSingleObject(&local_30,0,0,0,0);
            uVar5 = *(uint *)(param_2 + 0x30);
          }
          uVar11 = (ulonglong)uVar5;
          if (-1 < (int)uVar5) {
            lVar4 = *(longlong *)(param_2 + 0xb8);
            *(undefined4 *)(param_4 + 0x10) = *(undefined4 *)(*(longlong *)(lVar4 + 8) + 0x2c);
            *(undefined4 *)((longlong)param_4 + 0x84) =
                 *(undefined4 *)(*(longlong *)(lVar4 + 8) + 0x30);
          }
LAB_140008775:
          *(int *)(param_2 + 0x30) = (int)uVar11;
          goto LAB_140008778;
        }
LAB_14000848d:
        *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
        *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
        uVar5 = IofCallDriver(param_4[9],param_2);
        uVar11 = (ulonglong)uVar5;
      }
      Serenum_DecIoCount((longlong)param_4);
      goto LAB_140008793;
    }
    SerenumWaitForEnumThreadTerminate((longlong)param_4);
    *(undefined1 *)((longlong)param_4 + 0x19) = 0;
LAB_1400084b2:
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    *(undefined4 *)(param_2 + 0x30) = 0;
    uVar5 = IofCallDriver(param_4[9],param_2);
    Serenum_DecIoCount((longlong)param_4);
  }
  uVar11 = (ulonglong)uVar5;
LAB_140008793:
  return uVar11;
}



===== Serenum_PDO_PnP @ 1400087b8 =====

undefined4 Serenum_PDO_PnP(undefined8 param_1,longlong param_2,longlong param_3,longlong param_4)

{
  ushort *puVar1;
  byte bVar2;
  ushort uVar3;
  void *_Src;
  undefined4 uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  longlong lVar8;
  void *pvVar9;
  undefined4 *puVar10;
  undefined8 local_res10;
  undefined8 local_38;
  longlong lStack_30;
  
  bVar2 = *(byte *)(param_3 + 1);
  uVar4 = *(undefined4 *)(param_2 + 0x30);
  pvVar9 = (void *)0x0;
  if (bVar2 < 7) {
    if (bVar2 != 6) {
      if (bVar2 == 0) {
        if ((*(short *)(param_4 + 0x70) != 0) || (*(short *)(param_4 + 0x60) != 0)) {
          local_res10 = 0;
          local_38 = 0;
          lStack_30 = 0;
          iVar5 = IoOpenDeviceRegistryKey(0,1,0x20000,&local_res10);
          if (iVar5 < 0) goto LAB_140008c35;
          if (*(short *)(param_4 + 0x70) != 0) {
            RtlInitUnicodeString(&local_38,0);
            local_38._0_4_ = CONCAT22(0xe,(undefined2)local_38);
            lStack_30 = ExAllocatePool2(0x100,0xe,0x6d6e6553);
            if (lStack_30 != 0) {
              RtlAppendUnicodeToString(&local_38,L"PnPRev");
              ZwSetValueKey(local_res10,&local_38,0,1,*(undefined8 *)(param_4 + 0x78),
                            *(ushort *)(param_4 + 0x70) + 2);
              ExFreePoolWithTag(lStack_30,0);
            }
          }
          if (*(short *)(param_4 + 0x60) != 0) {
            RtlInitUnicodeString(&local_38,0);
            local_38._0_4_ = CONCAT22(0x1c,(undefined2)local_38);
            lStack_30 = ExAllocatePool2(0x100,0x1c,0x6d6e6553);
            if (lStack_30 != 0) {
              RtlAppendUnicodeToString(&local_38,L"Serial Number");
              ZwSetValueKey(local_res10,&local_38,0,1,*(undefined8 *)(param_4 + 0x68),
                            *(ushort *)(param_4 + 0x60) + 2);
              ExFreePoolWithTag(lStack_30,0);
            }
          }
          ZwClose(local_res10);
        }
        *(undefined1 *)(param_4 + 0x80) = 1;
      }
      else if (bVar2 != 1) {
        if (bVar2 == 2) {
          SerenumMarkPdoRemoved(*(longlong *)(*(longlong *)(param_4 + 0x18) + 0x40));
          if (*(char *)(param_4 + 0x81) == '\0') {
            uVar6 = Serenum_PnPRemove(param_1,param_4);
            uVar4 = (undefined4)uVar6;
            goto LAB_140008c38;
          }
        }
        else if (bVar2 != 3) {
          if (bVar2 == 4) {
            *(undefined1 *)(param_4 + 0x80) = 0;
          }
          else if (bVar2 != 5) goto LAB_140008c38;
        }
      }
    }
  }
  else if (bVar2 == 7) {
    if ((*(int *)(param_3 + 8) != 4) || (*(longlong *)(param_2 + 0x38) != 0)) goto LAB_140008c38;
    puVar10 = (undefined4 *)ExAllocatePool2(0x100,0x10,0x6d6e6553);
    if (puVar10 == (undefined4 *)0x0) goto LAB_140008c11;
    *puVar10 = 1;
    *(undefined8 *)(puVar10 + 2) = param_1;
    ObfReferenceObject(param_1);
    *(undefined4 **)(param_2 + 0x38) = puVar10;
  }
  else {
    if (bVar2 != 9) {
      if (bVar2 == 0xc) {
        if ((*(int *)(param_3 + 8) != 0) || (*(longlong *)(param_4 + 0x58) == 0))
        goto LAB_140008c38;
        pvVar9 = (void *)ExAllocatePool2(0x100,*(undefined2 *)(param_4 + 0x50),0x6d6e6553);
        if (pvVar9 != (void *)0x0) {
          uVar4 = 0;
          memmove(pvVar9,*(void **)(param_4 + 0x58),(ulonglong)*(ushort *)(param_4 + 0x50));
          *(void **)(param_2 + 0x38) = pvVar9;
          goto LAB_140008c38;
        }
      }
      else {
        if (bVar2 == 0x13) {
          iVar5 = *(int *)(param_3 + 8);
          if (((iVar5 != 0) && (iVar5 != 1)) && (iVar5 != 2)) {
            if (iVar5 == 3) {
              uVar4 = 0;
              puVar7 = (undefined8 *)ExAllocatePool2(0x100,10,0x6d6e6553);
              if (puVar7 == (undefined8 *)0x0) {
                uVar4 = 0xc000009a;
              }
              else {
                *puVar7 = 0x30003000300030;
                *(undefined2 *)(puVar7 + 1) = 0;
              }
              *(undefined8 **)(param_2 + 0x38) = puVar7;
            }
            goto LAB_140008c38;
          }
          uVar4 = 0;
          if (iVar5 == 0) {
            lVar8 = 0x40;
LAB_140008af6:
            puVar1 = (ushort *)(param_4 + lVar8);
            if ((puVar1 != (ushort *)0x0) && (_Src = *(void **)(puVar1 + 4), _Src != (void *)0x0)) {
              uVar3 = *puVar1;
              pvVar9 = (void *)ExAllocatePool2(0x100,(ulonglong)uVar3 + 2,0x6d6e6553);
              if (pvVar9 == (void *)0x0) {
                uVar4 = 0xc000009a;
              }
              else {
                memmove(pvVar9,_Src,(ulonglong)uVar3);
              }
            }
          }
          else {
            if (iVar5 == 1) {
              lVar8 = 0x20;
              goto LAB_140008af6;
            }
            if (iVar5 == 2) {
              lVar8 = 0x30;
              goto LAB_140008af6;
            }
          }
          *(void **)(param_2 + 0x38) = pvVar9;
          goto LAB_140008c38;
        }
        if (bVar2 != 0x15) goto LAB_140008c38;
        puVar7 = (undefined8 *)ExAllocatePool2(0x100,0x18,0x6d6e6553);
        if (puVar7 != (undefined8 *)0x0) {
          puVar7[2] = 0xf;
          *puVar7 = 0x11d1894477114a87;
          puVar7[1] = 0x2dbe06c9a00090bd;
          *(undefined8 **)(param_2 + 0x38) = puVar7;
          goto LAB_140008c35;
        }
      }
LAB_140008c11:
      uVar4 = 0xc000009a;
      goto LAB_140008c38;
    }
    puVar10 = *(undefined4 **)(param_3 + 8);
    *puVar10 = 0x10040;
    puVar10[0xb] = *(undefined4 *)(*(longlong *)(*(longlong *)(param_4 + 0x18) + 0x40) + 0x80);
    uVar4 = *(undefined4 *)(*(longlong *)(*(longlong *)(param_4 + 0x18) + 0x40) + 0x84);
    puVar10[1] = puVar10[1] & 0xffffffbf;
    puVar10[0xc] = uVar4;
    *(undefined8 *)(puVar10 + 0xd) = 0;
    puVar10[0xf] = 0;
  }
LAB_140008c35:
  uVar4 = 0;
LAB_140008c38:
  *(undefined4 *)(param_2 + 0x30) = uVar4;
  IofCompleteRequest(param_2,0);
  return uVar4;
}



===== Serenum_PnP @ 140008c70 =====

undefined4 Serenum_PnP(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  
  plVar1 = *(longlong **)(param_1 + 0x40);
  if (*(char *)((longlong)plVar1 + 9) == '\0') {
    if ((char)plVar1[1] == '\0') {
      uVar2 = Serenum_PDO_PnP(param_1,param_2,*(longlong *)(param_2 + 0xb8),(longlong)plVar1);
    }
    else {
      uVar3 = Serenum_FDO_PnP(param_1,param_2,*(longlong *)(param_2 + 0xb8),plVar1);
      uVar2 = (undefined4)uVar3;
    }
  }
  else {
    uVar2 = 0xc000000e;
    *(undefined4 *)(param_2 + 0x30) = 0xc000000e;
    IofCompleteRequest(param_2,0);
  }
  return uVar2;
}



===== Serenum_PnPRemove @ 140008ccc =====

undefined8 Serenum_PnPRemove(undefined8 param_1,longlong param_2)

{
  if ((*(char *)(param_2 + 0x81) == '\0') && (*(char *)(param_2 + 9) == '\0')) {
    *(undefined1 *)(param_2 + 9) = 1;
    RtlFreeUnicodeString(param_2 + 0x20);
    RtlFreeUnicodeString(param_2 + 0x30);
    RtlFreeUnicodeString(param_2 + 0x40);
    IoDeleteDevice(param_1);
  }
  return 0;
}



===== Serenum_DriverUnload @ 140008d50 =====

void Serenum_DriverUnload(void)

{
  return;
}



===== Serenum_GetDevName @ 140008d5c =====

void Serenum_GetDevName(longlong param_1,int param_2,char *param_3,int *param_4)

{
  int iVar1;
  longlong lVar2;
  char cVar3;
  longlong lVar4;
  char *pcVar5;
  int iVar6;
  
  if ((param_3 != (char *)0x0) && (param_1 != 0)) {
    iVar1 = *param_4;
    pcVar5 = param_3;
    iVar6 = iVar1;
    if (iVar1 < param_2) {
      *param_3 = *(char *)(iVar1 + param_1);
      lVar4 = 1;
      pcVar5 = param_3 + 1;
      iVar6 = iVar1 + 1;
      if (iVar6 < param_2) {
        lVar2 = (longlong)iVar6;
        iVar6 = iVar1 + 2;
        *pcVar5 = *(char *)(lVar2 + param_1);
        pcVar5 = param_3 + 2;
        if (iVar6 < param_2) {
          lVar2 = (longlong)iVar6;
          iVar6 = iVar1 + 3;
          *pcVar5 = *(char *)(lVar2 + param_1);
          pcVar5 = param_3 + 3;
          if (iVar6 < param_2) {
            lVar2 = (longlong)iVar6;
            iVar6 = iVar1 + 4;
            cVar3 = *(char *)(lVar2 + param_1);
            iVar1 = Serenum_HToI(cVar3);
            if (-1 < iVar1) {
              *pcVar5 = cVar3;
              pcVar5 = pcVar5 + lVar4;
            }
            if (iVar6 < param_2) {
              lVar2 = (longlong)iVar6;
              iVar6 = iVar6 + (int)lVar4;
              cVar3 = *(char *)(lVar2 + param_1);
              iVar1 = Serenum_HToI(cVar3);
              if (-1 < iVar1) {
                *pcVar5 = cVar3;
                pcVar5 = pcVar5 + lVar4;
              }
              if (iVar6 < param_2) {
                lVar2 = (longlong)iVar6;
                iVar6 = iVar6 + (int)lVar4;
                cVar3 = *(char *)(lVar2 + param_1);
                iVar1 = Serenum_HToI(cVar3);
                if (-1 < iVar1) {
                  *pcVar5 = cVar3;
                  pcVar5 = pcVar5 + lVar4;
                }
                if (iVar6 < param_2) {
                  lVar2 = (longlong)iVar6;
                  iVar6 = iVar6 + (int)lVar4;
                  cVar3 = *(char *)(lVar2 + param_1);
                  iVar1 = Serenum_HToI(cVar3);
                  if (-1 < iVar1) {
                    *pcVar5 = cVar3;
                    pcVar5 = pcVar5 + lVar4;
                  }
                }
              }
            }
          }
        }
      }
    }
    *pcVar5 = '\0';
    *param_4 = iVar6;
  }
  return;
}



===== Serenum_GetDevPnPRev @ 140008e50 =====

undefined8
Serenum_GetDevPnPRev(undefined8 param_1,longlong param_2,int param_3,char *param_4,int *param_5)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  int iVar5;
  char cVar6;
  uint uVar7;
  byte bVar8;
  ulonglong uVar9;
  char cVar10;
  uint uVar11;
  int iVar12;
  
  if ((param_4 != (char *)0x0) && (param_2 != 0)) {
    *param_4 = '\0';
    iVar5 = *param_5;
    if ((iVar5 < param_3) && (cVar6 = *(char *)(iVar5 + param_2), cVar6 != '\0')) {
      iVar5 = iVar5 + 1;
      for (lVar4 = (longlong)iVar5; lVar4 < 0x100; lVar4 = lVar4 + 1) {
        if ((cVar6 == '(') || (cVar6 == '\b')) goto LAB_140008eed;
        if (param_3 <= lVar4) {
          return 0xc0000001;
        }
        cVar6 = *(char *)(lVar4 + param_2);
        iVar5 = iVar5 + 1;
      }
      if ((cVar6 == '(') || (cVar6 == '\b')) {
LAB_140008eed:
        bVar8 = 0x28 - cVar6;
        uVar9 = (ulonglong)bVar8;
        iVar12 = (int)cVar6;
        if (iVar5 + 9 < param_3) {
          lVar4 = (longlong)iVar5;
          iVar3 = iVar5;
          if ((int)*(char *)(lVar4 + 9 + param_2) != 0x29 - (char)bVar8) {
            for (; ((cVar10 = (char)iVar3, iVar3 < 0x100 && ((int)cVar6 != 0x29 - (char)bVar8)) &&
                   (iVar3 < param_3)); iVar3 = iVar3 + 1) {
              cVar6 = *(char *)(iVar3 + param_2);
            }
            if (iVar3 < 3) {
              return 0xc0000001;
            }
            if (param_3 <= iVar3 + -2) {
              return 0xc0000001;
            }
            iVar2 = Serenum_HToI(bVar8 + *(char *)(param_2 + -3 + (longlong)iVar3));
            if (iVar2 < 0) {
              return 0xc0000001;
            }
            iVar3 = Serenum_HToI((char)uVar9 + *(char *)(param_2 + -2 + (longlong)iVar3));
            if (iVar3 < 0) {
              return 0xc0000001;
            }
            if (cVar6 - iVar12 != 1) {
              return 0xc0000001;
            }
            if (cVar10 < '\x03') {
              return 0xc0000001;
            }
            if (param_3 <= cVar10 + -2) {
              return 0xc0000001;
            }
            *(char *)((longlong)cVar10 + -3 + param_2) = ')' - (char)uVar9;
            *(undefined1 *)((longlong)cVar10 + -2 + param_2) = 0;
          }
          if (((iVar5 + 1 < param_3) && (*(char *)(lVar4 + param_2) < '@')) &&
             (cVar6 = *(char *)(lVar4 + 1 + param_2), cVar6 < '@')) {
            uVar7 = ((int)*(char *)(lVar4 + param_2) & 0x3fU) << 6 | (int)cVar6 & 0x3fU;
            uVar11 = uVar7 / 100;
            if (9 < uVar11) {
              *param_4 = (char)(uVar11 / 10) + '0';
              param_4 = param_4 + 1;
            }
            *param_4 = (char)uVar11 + (char)(uVar11 / 10) * -10 + '0';
            param_4[1] = '.';
            param_4[4] = '\0';
            uVar7 = uVar7 % 100;
            cVar6 = (char)(uVar7 / 10);
            param_4[2] = cVar6 + '0';
            param_4[3] = (char)uVar7 + cVar6 * -10 + '0';
            iVar12 = iVar5 + 2;
            while (((iVar12 < 0x100 && ((char)uVar9 != '\0')) && (iVar12 < param_3))) {
              lVar4 = (longlong)iVar12;
              iVar12 = iVar12 + 1;
              pcVar1 = (char *)(lVar4 + param_2);
              *pcVar1 = *pcVar1 + (char)uVar9;
              uVar9 = uVar9 & 0xff;
              if (*(char *)(lVar4 + param_2) == ')') {
                uVar9 = 0;
              }
            }
            *param_5 = iVar5 + 2;
            return 0;
          }
        }
      }
    }
  }
  return 0xc0000001;
}



===== Serenum_HToI @ 1400090ec =====

int Serenum_HToI(char param_1)

{
  if ((byte)(param_1 - 0x30U) < 10) {
    return param_1 + -0x30;
  }
  if ((byte)(param_1 + 0xbfU) < 6) {
    return param_1 + -0x37;
  }
  if ((byte)(param_1 + 0x9fU) < 6) {
    return param_1 + -0x57;
  }
  return -1;
}



===== Serenum_InitMultiString @ 140009124 =====

undefined8
Serenum_InitMultiString(undefined8 param_1,undefined2 *param_2,longlong param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined2 uVar4;
  int iVar5;
  longlong *plVar6;
  longlong local_res18 [2];
  undefined8 local_50;
  undefined2 *puStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  
  plVar6 = local_res18;
  local_40 = 0;
  uStack_38 = 0;
  iVar5 = 0;
  local_50 = 0;
  puStack_48 = (undefined2 *)0x0;
  local_res18[0] = param_3;
  local_res18[1] = param_4;
  if (param_3 != 0) {
    do {
      plVar6 = plVar6 + 1;
      RtlInitAnsiString(&local_40,param_3);
      iVar1 = RtlxAnsiStringToUnicodeSize(&local_40);
      iVar5 = iVar5 + iVar1;
      param_3 = *plVar6;
    } while (param_3 != 0);
  }
  if (iVar5 == 0) {
    RtlInitUnicodeString(param_2,0);
  }
  else {
    uVar4 = (undefined2)(iVar5 + 2);
    param_2[1] = uVar4;
    uVar2 = ExAllocatePool2(0x100,iVar5 + 2,0x6d6e6553);
    *(undefined8 *)(param_2 + 4) = uVar2;
    *param_2 = 0;
    puStack_48 = *(undefined2 **)(param_2 + 4);
    if (puStack_48 == (undefined2 *)0x0) {
      return 0xc000009a;
    }
    local_50._0_4_ = CONCAT22(uVar4,(short)local_50);
    for (plVar6 = local_res18; *plVar6 != 0; plVar6 = plVar6 + 1) {
      RtlInitAnsiString(&local_40,*plVar6);
      RtlAnsiStringToUnicodeString(&local_50,&local_40,0);
      uVar3 = 0;
      if ((local_50 & 0xfffe) != 0) {
        do {
          if ((puStack_48[uVar3] - 0xc & 0xffdf) == 0) {
            puStack_48[uVar3] = 0;
          }
          uVar3 = uVar3 + 1;
        } while (uVar3 < (uint)((local_50 & 0xffff) >> 1));
      }
      puStack_48 = (undefined2 *)((longlong)puStack_48 + (local_50 & 0xfffe) + 2);
      local_50 = (ulonglong)CONCAT42(local_50._4_4_,local_50._2_2_ + (-2 - (short)local_50)) << 0x10
      ;
    }
    *puStack_48 = 0;
    *param_2 = uVar4;
    param_2[1] = uVar4;
  }
  return 0;
}



===== Serenum_ParseData @ 1400092c8 =====

ulonglong Serenum_ParseData(undefined8 param_1,char *param_2,int param_3,undefined2 *param_4,
                           undefined2 *param_5,undefined2 *param_6,undefined2 *param_7,
                           undefined2 *param_8,undefined2 *param_9)

{
  char *pcVar1;
  char *_Str1;
  bool bVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char cVar7;
  uint uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  char *pcVar11;
  ulonglong uVar12;
  longlong lVar13;
  char *pcVar14;
  int iVar15;
  char *pcVar16;
  char cVar17;
  char *pcVar18;
  int local_74;
  char *local_70;
  char *local_60;
  char *local_58;
  char *local_50;
  char *local_48;
  int local_40 [2];
  char *local_38;
  char *local_30;
  
  local_60 = (char *)0x0;
  bVar2 = false;
  local_48 = (char *)ExAllocatePool2(0x100,0x701,0x6d6e6553);
  if (local_48 == (char *)0x0) {
    return 0xc000009a;
  }
  pcVar16 = local_48 + 0x100;
  *local_48 = '\0';
  *pcVar16 = '\0';
  iVar15 = 0;
  local_38 = local_48 + 0x200;
  *local_38 = '\0';
  pcVar1 = local_48 + 0x300;
  *pcVar1 = '\0';
  _Str1 = local_48 + 0x400;
  local_70 = local_48 + 0x500;
  *_Str1 = '\0';
  local_50 = local_48 + 0x601;
  *local_70 = '\0';
  pcVar18 = local_48 + 0x501;
  *local_50 = '\0';
  lVar13 = 0;
  do {
    if (0xff < lVar13) break;
    iVar15 = iVar15 + 1;
    ("SERENUM\\" + lVar13)[(longlong)(local_48 + -0x1400040f8)] = "SERENUM\\"[lVar13];
    lVar3 = lVar13 + 1;
    lVar13 = lVar13 + 1;
  } while ("SERENUM\\"[lVar3] != '\0');
  local_58 = local_38 + iVar15;
  local_30 = pcVar16;
  RtlInitUnicodeString(param_4,0);
  RtlInitUnicodeString(param_5,0);
  RtlInitUnicodeString(param_6,0);
  RtlInitUnicodeString(param_9,0);
  RtlInitUnicodeString(param_8,0);
  pcVar14 = local_70;
  cVar17 = *param_2;
  local_74 = 1;
  lVar13 = 1;
  pcVar11 = local_48;
  do {
    if (((cVar17 - 8U & 0xdf) == 0) || (param_3 <= local_74)) break;
    *pcVar11 = cVar17;
    local_74 = local_74 + 1;
    cVar17 = param_2[lVar13];
    pcVar11 = pcVar11 + 1;
    lVar13 = lVar13 + 1;
  } while (lVar13 < 0x11);
  local_74 = local_74 + -1;
  *pcVar11 = '\0';
  if (local_74 < 0x11) {
    pcVar11 = param_2;
    SerenumScanOtherIdForMouse(param_2,param_3,&local_60,local_40);
    if ((local_60 != (char *)0x0) && ((*local_60 == 'M' || (*local_60 == 'B')))) {
      bVar2 = true;
    }
    uVar12 = Serenum_GetDevPnPRev(pcVar11,(longlong)param_2,param_3,pcVar16,&local_74);
    uVar5 = (uint)uVar12;
    uVar12 = uVar12 & 0xffffffff;
    if (-1 < (int)uVar5) {
      Serenum_GetDevName((longlong)param_2,param_3,local_58,&local_74);
      uVar10 = 0;
      *pcVar1 = '\0';
      iVar15 = local_74;
      if ((((param_2 != (char *)0x0) && (local_74 < param_3)) && (param_2[local_74] == '\\')) &&
         (local_74 + 1 < param_3)) {
        uVar9 = 0;
        iVar15 = local_74 + 2;
        lVar13 = (longlong)iVar15;
        cVar17 = param_2[local_74 + 1];
        pcVar16 = pcVar1;
        do {
          if (((0xff < lVar13) || (cVar17 == '\\')) || ((cVar17 == ')' || (param_3 <= iVar15))))
          break;
          uVar9 = (ulonglong)((int)uVar9 + 1);
          iVar6 = Serenum_HToI(cVar17);
          if (iVar6 < 0) break;
          *pcVar16 = cVar17;
          iVar15 = iVar15 + 1;
          cVar17 = param_2[lVar13];
          pcVar16 = pcVar16 + 1;
          lVar13 = lVar13 + 1;
        } while ((int)uVar9 < 8);
        *pcVar16 = (char)uVar10;
        iVar15 = iVar15 + -1;
      }
      uVar9 = uVar10 & 0xffffffff;
      cVar17 = (char)uVar10;
      if (*pcVar1 == cVar17) {
LAB_1400095a1:
        *_Str1 = cVar17;
        if (((param_2 != (char *)0x0) && (iVar15 < param_3)) &&
           ((param_2[iVar15] == '\\' && (iVar15 + 1 < param_3)))) {
          iVar6 = iVar15 + 2;
          cVar7 = param_2[iVar15 + 1];
          lVar13 = (longlong)iVar6;
          pcVar16 = _Str1;
          for (uVar9 = uVar10 & 0xffffffff;
              (((lVar13 < 0x100 && (cVar7 != '\\')) && (cVar7 != ')')) &&
              ((iVar6 < param_3 && ((int)uVar9 < 0xff)))); uVar9 = (ulonglong)((int)uVar9 + 1)) {
            *pcVar16 = cVar7;
            cVar7 = param_2[lVar13];
            pcVar16 = pcVar16 + 1;
            iVar6 = iVar6 + 1;
            lVar13 = lVar13 + 1;
          }
          *pcVar16 = cVar17;
          iVar15 = iVar6 + -1;
        }
        uVar10 = uVar10 & 0xffffffff;
        if (*_Str1 != cVar17) {
          pcVar16 = _Str1;
          do {
            pcVar16 = pcVar16 + 1;
            uVar8 = (int)uVar10 + 1;
            uVar10 = (ulonglong)uVar8;
          } while (*pcVar16 != cVar17);
          if (0x20 < (int)uVar8) goto LAB_140009597;
        }
        iVar6 = _stricmp(_Str1,"MOUSE");
        if (iVar6 == 0) {
          lVar13 = 0x100;
          pcVar16 = _Str1;
          do {
            if ((lVar13 == -0x7ffffefe) ||
               (pcVar16[(longlong)"SERIAL_MOUSE" - (longlong)_Str1] == '\0')) break;
            *pcVar16 = pcVar16[(longlong)"SERIAL_MOUSE" - (longlong)_Str1];
            pcVar16 = pcVar16 + 1;
            lVar13 = lVar13 + -1;
          } while (lVar13 != 0);
          pcVar14 = pcVar16 + -1;
          if (lVar13 != 0) {
            pcVar14 = pcVar16;
          }
          *pcVar14 = '\0';
        }
        *local_70 = '*';
        if (pcVar18 != (char *)0x0) {
          *pcVar18 = '\0';
          cVar17 = '\0';
          if ((param_2 != (char *)0x0) && (iVar15 < param_3)) {
            cVar17 = '\0';
            if ((param_2[iVar15] == '\\') && (iVar15 + 1 < param_3)) {
              iVar6 = iVar15 + 2;
              lVar13 = (longlong)iVar6;
              cVar17 = param_2[iVar15 + 1];
              iVar15 = 0;
              pcVar16 = pcVar18;
              while ((((lVar13 < 0x100 && (cVar17 != '\\')) && (cVar17 != ')')) &&
                     ((iVar6 < param_3 && (iVar15 < 0xfe))))) {
                *pcVar16 = cVar17;
                pcVar14 = pcVar16 + 1;
                iVar4 = iVar15 + 1;
                if ((cVar17 - 0xcU & 0xdf) == 0) {
                  *pcVar14 = '*';
                  pcVar14 = pcVar16 + 2;
                  iVar4 = iVar15 + 2;
                }
                iVar15 = iVar4;
                cVar17 = param_2[lVar13];
                iVar6 = iVar6 + 1;
                lVar13 = lVar13 + 1;
                pcVar16 = pcVar14;
              }
              *pcVar16 = '\0';
              iVar15 = iVar6 + -1;
              cVar17 = *pcVar18;
            }
          }
          iVar6 = 0;
          if (cVar17 != '\0') {
            pcVar16 = pcVar18;
            do {
              pcVar16 = pcVar16 + 1;
              iVar6 = iVar6 + 1;
            } while (*pcVar16 != '\0');
            if (0x28 < iVar6) goto LAB_140009597;
          }
        }
        *local_50 = '\0';
        if (((param_2 != (char *)0x0) && (iVar15 < param_3)) &&
           ((param_2[iVar15] == '\\' && (iVar15 + 1 < param_3)))) {
          iVar6 = iVar15 + 2;
          cVar17 = param_2[iVar15 + 1];
          lVar13 = (longlong)iVar6;
          pcVar16 = local_50;
          for (iVar15 = 0;
              (((lVar13 < 0x100 && (cVar17 != '\\')) && (cVar17 != ')')) &&
              ((iVar6 < param_3 && (iVar15 < 0xff)))); iVar15 = iVar15 + 1) {
            *pcVar16 = cVar17;
            cVar17 = param_2[lVar13];
            pcVar16 = pcVar16 + 1;
            iVar6 = iVar6 + 1;
            lVar13 = lVar13 + 1;
          }
          *pcVar16 = '\0';
        }
        iVar15 = 0;
        if (*local_50 != '\0') {
          pcVar16 = local_50;
          do {
            pcVar16 = pcVar16 + 1;
            iVar15 = iVar15 + 1;
          } while (*pcVar16 != '\0');
          if (0x28 < iVar15) {
            uVar5 = 0xc0000001;
          }
          uVar12 = (ulonglong)uVar5;
        }
      }
      else {
        pcVar16 = pcVar1;
        do {
          pcVar16 = pcVar16 + 1;
          uVar8 = (int)uVar9 + 1;
          uVar9 = (ulonglong)uVar8;
        } while (*pcVar16 != cVar17);
        if (uVar8 == 0) goto LAB_1400095a1;
        uVar9 = uVar10 & 0xffffffff;
        pcVar16 = pcVar1;
        do {
          pcVar16 = pcVar16 + 1;
          uVar8 = (int)uVar9 + 1;
          uVar9 = (ulonglong)uVar8;
        } while (*pcVar16 != cVar17);
        if (uVar8 == 8) goto LAB_1400095a1;
        *pcVar1 = cVar17;
LAB_140009597:
        uVar12 = 0xc0000001;
      }
      pcVar14 = local_70;
    }
  }
  else {
    uVar12 = 0xc0000001;
  }
  pcVar16 = local_38;
  Serenum_InitMultiString(param_1,param_4,(longlong)local_38,local_58);
  if ((pcVar18 != (char *)0x0) && (iVar15 = 0, *pcVar18 != '\0')) {
    do {
      pcVar18 = pcVar18 + 1;
      iVar15 = iVar15 + 1;
    } while (*pcVar18 != '\0');
    if (0 < iVar15) {
      if (bVar2) {
        Serenum_InitMultiString(param_1,param_5,(longlong)pcVar14,_Str1);
      }
      else {
        Serenum_InitMultiString(param_1,param_5,(longlong)pcVar14,_Str1);
      }
      goto LAB_140009862;
    }
  }
  if (bVar2) {
    Serenum_InitMultiString(param_1,param_5,0x140004248,0);
  }
LAB_140009862:
  Serenum_InitMultiString(param_1,param_6,(longlong)pcVar16,0);
  Serenum_InitMultiString(param_1,param_7,(longlong)local_50,0);
  if ((pcVar1 != (char *)0x0) && (iVar15 = 0, *pcVar1 != '\0')) {
    pcVar18 = pcVar1;
    do {
      pcVar18 = pcVar18 + 1;
      iVar15 = iVar15 + 1;
    } while (*pcVar18 != '\0');
    if (iVar15 != 0) {
      Serenum_InitMultiString(param_1,param_8,(longlong)pcVar1,0);
    }
  }
  if ((local_30 != (char *)0x0) && (iVar15 = 0, *local_30 != '\0')) {
    pcVar18 = local_30;
    do {
      pcVar18 = pcVar18 + 1;
      iVar15 = iVar15 + 1;
    } while (*pcVar18 != '\0');
    if (iVar15 != 0) {
      Serenum_InitMultiString(param_1,param_9,(longlong)local_30,0);
    }
  }
  ExFreePoolWithTag(local_48,0);
  return uVar12;
}



===== SerenumCheckForLegacyDevice @ 14000a008 =====

undefined8
SerenumCheckForLegacyDevice
          (undefined8 param_1,char *param_2,uint param_3,undefined2 *param_4,undefined2 *param_5,
          undefined2 *param_6)

{
  char cVar1;
  undefined8 in_RAX;
  undefined7 uVar2;
  undefined1 uVar3;
  char *pcVar4;
  char *pcVar5;
  
  uVar3 = 0;
  pcVar5 = param_2;
  do {
    if (param_3 == 0) {
LAB_14000a10c:
      return CONCAT71((int7)((ulonglong)in_RAX >> 8),uVar3);
    }
    cVar1 = *pcVar5;
    uVar2 = (undefined7)((ulonglong)in_RAX >> 8);
    in_RAX = CONCAT71(uVar2,cVar1);
    if ((cVar1 == 'M') || (cVar1 == 'B')) {
      if (pcVar5 != (char *)0x0) {
        if (cVar1 == 'M') {
          if ((((longlong)pcVar5 - (longlong)param_2 < 2) || (param_3 < 2)) ||
             (pcVar4 = "*PNP0F08", pcVar5[1] != '3')) {
            pcVar4 = "*PNP0F01";
          }
          uVar3 = 1;
          Serenum_InitMultiString(param_1,param_4,(longlong)pcVar4,0);
          Serenum_InitMultiString(param_1,param_5,0x140004248,0);
          in_RAX = Serenum_InitMultiString(param_1,param_6,0x140004258,0);
        }
        else if (cVar1 == 'B') {
          Serenum_InitMultiString(param_1,param_4,0x140004278,0);
          Serenum_InitMultiString(param_1,param_5,0x140004288,"SERIAL_MOUSE");
          in_RAX = Serenum_InitMultiString(param_1,param_6,0x140004298,0);
          uVar3 = 1;
        }
      }
      goto LAB_14000a10c;
    }
    in_RAX = CONCAT71(uVar2,cVar1 - 8U);
    if ((cVar1 - 8U & 0xdf) == 0) goto LAB_14000a10c;
    pcVar5 = pcVar5 + 1;
    param_3 = param_3 - 1;
  } while( true );
}



===== SerenumDoEnumProtocol @ 14000a120 =====

int SerenumDoEnumProtocol(longlong param_1,longlong *param_2,ushort *param_3,undefined1 *param_4)

{
  undefined8 uVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ushort uVar7;
  ushort local_res10 [4];
  ushort *local_res18;
  undefined2 local_res20;
  undefined1 local_res22;
  uint local_b8 [2];
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  int local_98 [4];
  undefined1 local_88 [72];
  
  uVar1 = *(undefined8 *)(param_1 + 0x48);
  local_a0 = 0;
  local_b8[0] = 0;
  local_98[0] = 0;
  local_98[1] = 0;
  local_98[2] = 0;
  local_98[3] = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_res18 = param_3;
  memset(local_88,0,0x40);
  local_b8[1] = 0;
  local_res20 = 0;
  local_res22 = 0;
  KeInitializeEvent(&local_b0,0,0);
  KeInitializeTimer(local_88);
  *param_2 = 0;
  *param_4 = 0;
  uVar7 = 0;
  lVar4 = ExAllocatePool2(0x40,0x101,0x6d6e6553);
  if (lVar4 == 0) {
    local_res10[0] = uVar7;
    iVar2 = -0x3fffff66;
  }
  else {
    *(undefined1 *)(lVar4 + 0x100) = 0;
    iVar2 = Serenum_IoSyncIoctlEx(0x1b0024,0,uVar1,&local_b0,0,0,0,0);
    if ((((-1 < iVar2) &&
         (iVar2 = Serenum_IoSyncIoctlEx(0x1b0034,0,uVar1,&local_b0,0,0,0,0), -1 < iVar2)) &&
        (iVar2 = Serenum_Wait(local_88,0xffffffffffe17b80), -1 < iVar2)) &&
       (iVar2 = Serenum_IoSyncIoctlEx(0x1b0068,0,uVar1,&local_b0,0,0,local_b8,4), -1 < iVar2)) {
      if ((local_b8[0] & 0x20) == 0) {
        *param_4 = 1;
      }
      local_b8[1] = 0x4b0;
      iVar2 = Serenum_IoSyncIoctlEx(0x1b0004,0,uVar1,&local_b0,local_b8 + 1,4,0,0);
      if (-1 < iVar2) {
        local_res22 = 7;
        iVar2 = Serenum_IoSyncIoctlEx(0x1b000c,0,uVar1,&local_b0,&local_res20,3,0,0);
        uVar3 = 0;
        if (-1 < iVar2) {
          do {
            local_b8[0] = 8;
            iVar2 = Serenum_IoSyncIoctlEx(0x1b004c,0,uVar1,&local_b0,local_b8,4,0,0);
            if ((((iVar2 < 0) ||
                 (iVar2 = Serenum_IoSyncIoctlEx(0x1b0028,0,uVar1,&local_b0,0,0,0,0), iVar2 < 0)) ||
                ((iVar2 = Serenum_IoSyncIoctlEx(0x1b0034,0,uVar1,&local_b0,0,0,0,0), iVar2 < 0 ||
                 ((iVar2 = Serenum_Wait(local_88,0xffffffffffe17b80), iVar2 < 0 ||
                  (iVar2 = Serenum_IoSyncIoctlEx(0x1b0024,0,uVar1,&local_b0,0,0,0,0), iVar2 < 0)))))
                ) || ((uVar3 == 0 && (iVar2 = Serenum_Wait(local_88,0xffffffffffe17b80), iVar2 < 0))
                     )) goto LAB_14000a4ac;
            uVar5 = 0;
            uVar6 = uVar1;
            iVar2 = Serenum_IoSyncIoctlEx(0x1b0030,0,uVar1,&local_b0,0,0,0,0);
            if (iVar2 < 0) goto LAB_14000a4ac;
            local_res10[0] = 0;
            iVar2 = Serenum_ReadSerialPort(lVar4,uVar5,uVar6,local_res10,local_98,param_1);
            uVar7 = local_res10[0];
            if (iVar2 != 0x102) {
              if (iVar2 < 0) goto LAB_14000a4ac;
              break;
            }
            if (local_res10[0] != 0) {
              iVar2 = 0;
              break;
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < 2);
          goto LAB_14000a4c2;
        }
      }
    }
LAB_14000a4ac:
    ExFreePoolWithTag(lVar4,0);
    lVar4 = 0;
    local_res10[0] = uVar7;
  }
LAB_14000a4c2:
  *param_2 = lVar4;
  *local_res18 = local_res10[0];
  return iVar2;
}



===== SerenumScanOtherIdForMouse @ 14000a4ec =====

void SerenumScanOtherIdForMouse(char *param_1,int param_2,undefined8 *param_3,int *param_4)

{
  char cVar1;
  
  *param_3 = param_1;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    cVar1 = *param_1;
    if ((cVar1 == 'M') || (cVar1 == 'B')) goto LAB_14000a521;
    if ((cVar1 - 8U & 0xdf) == 0) break;
    param_1 = param_1 + 1;
    *param_3 = param_1;
  }
  *param_3 = 0;
  param_2 = 0;
LAB_14000a521:
  *param_4 = param_2;
  return;
}



===== SerenumValidateID @ 14000a534 =====

undefined8 SerenumValidateID(longlong param_1)

{
  ushort uVar1;
  uint uVar2;
  ulonglong in_RAX;
  ushort *puVar3;
  
  puVar3 = *(ushort **)(param_1 + 8);
  if (puVar3 == (ushort *)0x0) {
LAB_14000a53d:
    return CONCAT71((int7)(in_RAX >> 8),1);
  }
  do {
    uVar1 = *puVar3;
    if (uVar1 == 0) {
      puVar3 = puVar3 + 1;
      uVar1 = *puVar3;
      if (uVar1 == 0) goto LAB_14000a53d;
    }
    uVar2 = uVar1 - 0x20;
    in_RAX = (ulonglong)uVar2;
    if ((0x5f < (ushort)uVar2) || (uVar1 == 0x2c)) {
      return (ulonglong)(uint3)(uVar2 >> 8) << 8;
    }
    puVar3 = puVar3 + 1;
  } while( true );
}



===== Serenum_IoSyncIoctlEx @ 14000a574 =====

int Serenum_IoSyncIoctlEx
              (undefined4 param_1,undefined1 param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5,undefined4 param_6,undefined8 param_7,undefined4 param_8)

{
  int iVar1;
  longlong lVar2;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  KeClearEvent(param_4);
  lVar2 = IoBuildDeviceIoControlRequest
                    (param_1,param_3,param_5,param_6,param_7,param_8,param_2,param_4,&local_18);
  if (lVar2 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    iVar1 = IofCallDriver(param_3,lVar2);
    if (iVar1 == 0x103) {
      iVar1 = KeWaitForSingleObject(param_4,0,0,0,0);
    }
    if (iVar1 == 0) {
      iVar1 = (int)local_18;
    }
  }
  return iVar1;
}



===== Serenum_IoSyncReqWithIrp @ 14000a65c =====

ulonglong Serenum_IoSyncReqWithIrp
                    (longlong param_1,undefined1 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  
  *(undefined1 *)(*(longlong *)(param_1 + 0xb8) + -0x48) = param_2;
  KeClearEvent(param_3);
  lVar1 = *(longlong *)(param_1 + 0xb8);
  *(code **)(lVar1 + -0x10) = Serenum_EnumComplete;
  *(undefined8 *)(lVar1 + -8) = param_3;
  *(undefined1 *)(lVar1 + -0x45) = 0xe0;
  uVar2 = IofCallDriver(param_4,param_1);
  if ((int)uVar2 == 0x103) {
    uVar2 = KeWaitForSingleObject(param_3,0,0,0,0);
  }
  if ((int)uVar2 == 0) {
    uVar2 = (ulonglong)*(uint *)(param_1 + 0x30);
  }
  return uVar2;
}



===== Serenum_ReadSerialPort @ 14000a6fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int Serenum_ReadSerialPort
              (longlong param_1,undefined8 param_2,undefined8 param_3,ushort *param_4,int *param_5,
              longlong param_6)

{
  int iVar1;
  longlong lVar2;
  undefined1 auStackY_a8 [32];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined4 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_58 = 0;
  local_40 = 0xf0;
  local_48 = 0xffffffff;
  local_44 = 0xffffffff;
  local_50 = 0;
  local_38 = 0;
  local_68 = 0;
  uStack_60 = 0;
  KeInitializeEvent(&local_68,0,0);
  iVar1 = Serenum_IoSyncIoctlEx
                    (0x1b001c,0,*(undefined8 *)(param_6 + 0x48),&local_68,&local_48,0x14,0,0);
  if (-1 < iVar1) {
    *param_4 = 0;
    do {
      KeClearEvent(&local_68);
      lVar2 = IoBuildSynchronousFsdRequest(3,*(undefined8 *)(param_6 + 0x48),param_1);
      if (lVar2 == 0) {
        return -0x3fffff66;
      }
      iVar1 = IofCallDriver(*(undefined8 *)(param_6 + 0x48),lVar2);
      if ((iVar1 == 0x103) && (iVar1 = KeWaitForSingleObject(&local_68,0,0,0), iVar1 == 0)) {
        iVar1 = *param_5;
      }
      if ((iVar1 < 0) || (iVar1 == 0x102)) break;
      *param_4 = *param_4 + (short)param_5[2];
      param_1 = param_1 + (ulonglong)*(ushort *)(param_5 + 2);
    } while (*param_4 < 0x100);
  }
  return iVar1;
}



===== Serenum_ReenumerateDevices @ 14000a88c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong Serenum_ReenumerateDevices(longlong param_1,longlong *param_2,undefined1 *param_3)

{
  longlong *plVar1;
  byte bVar2;
  longlong lVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  uint uVar11;
  char *pcVar12;
  undefined1 auStackY_1f8 [32];
  char local_1a8;
  undefined1 local_1a7;
  longlong local_1a0;
  ushort local_198 [4];
  char *local_190;
  undefined8 local_188;
  longlong lStack_180;
  undefined8 local_178;
  longlong lStack_170;
  undefined8 local_168;
  longlong lStack_160;
  undefined8 local_158;
  longlong lStack_150;
  undefined8 local_148;
  longlong lStack_140;
  undefined8 local_138;
  longlong lStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined1 *local_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined1 local_f8 [64];
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined4 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined4 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined4 local_60;
  wchar_t local_58 [7];
  short sStack_4a;
  undefined2 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_1f8;
  local_118 = 0;
  local_128 = 0;
  uStack_120 = 0;
  local_110 = param_3;
  memset(local_f8,0,0x40);
  local_1a0 = param_2[5];
  plVar1 = param_2 + 0x11;
  lVar3 = param_2[9];
  local_108 = 0;
  uStack_100 = 0;
  local_48 = 0;
  local_188 = 0;
  lStack_180 = 0;
  local_168 = 0;
  lStack_160 = 0;
  local_148 = 0;
  lStack_140 = 0;
  local_1a8 = '\0';
  pcVar12 = (char *)0x0;
  local_198[0] = 0;
  uVar11 = 0;
  local_178 = 0;
  lStack_170 = 0;
  local_190 = (char *)0x0;
  builtin_wcsncpy(local_58,L"\\Serial",7);
  sStack_4a = L'\\';
  local_68 = 0;
  local_60 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_a8 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_90 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_1a7 = 0;
  local_158 = 0;
  lStack_150 = 0;
  local_138 = 0;
  lStack_130 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  uVar7 = KeWaitForSingleObject(plVar1,0,0,0);
  if ((int)uVar7 < 0) {
    return uVar7;
  }
  RtlInitUnicodeString(&local_108);
  bVar2 = *(byte *)(param_2 + 3);
  *(byte *)(param_2 + 3) = bVar2 + 1;
  stack0xffffffffffffffb0 = CONCAT26(bVar2 + 0x30,local_58._8_6_);
  KeInitializeEvent(&local_128,0,0);
  KeInitializeTimer(local_f8);
  RtlInitUnicodeString(&local_188);
  RtlInitUnicodeString(&local_178);
  RtlInitUnicodeString(&local_168);
  RtlInitUnicodeString(&local_158);
  RtlInitUnicodeString(&local_148);
  RtlInitUnicodeString(&local_138);
  if ((*(char *)((longlong)param_2 + 0x1d) != '\0') && (local_1a0 != 0)) {
    Serenum_PDO_EnumMarkMissing((longlong)param_2,*(longlong *)(local_1a0 + 0x40));
    local_1a0 = 0;
  }
  uVar7 = Serenum_IoSyncReqWithIrp(param_1,0,&local_128,lVar3);
  uVar9 = uVar7 & 0xffffffff;
  if ((int)uVar7 < 0) {
LAB_14000aa99:
    KeReleaseSemaphore(plVar1,0,1,0);
    return uVar9;
  }
  iVar5 = Serenum_IoSyncIoctlEx(0x1b000c,1,lVar3,&local_128,0,0,&local_88,0x2c);
  if (iVar5 < 0) {
    uVar6 = Serenum_IoSyncIoctlEx(0x1b0020,0,lVar3,&local_128,0,0,&local_b8,0x14);
    uVar9 = (ulonglong)uVar6;
    if ((int)uVar6 < 0) goto LAB_14000aa99;
    Serenum_IoSyncIoctlEx(0x1b001c,0,lVar3,&local_128,&local_a0,0x14,0,0);
    cVar4 = '\0';
  }
  else {
    cVar4 = '\x01';
  }
  while( true ) {
    if (pcVar12 != (char *)0x0) {
      ExFreePoolWithTag(pcVar12,0);
      local_190 = (char *)0x0;
    }
    uVar6 = SerenumDoEnumProtocol((longlong)param_2,(longlong *)&local_190,local_198,&local_1a8);
    if ((uVar6 == 0) || (uVar11 = uVar11 + 1, 2 < uVar11)) break;
    pcVar12 = local_190;
  }
  puVar10 = &local_b8;
  if (cVar4 != '\0') {
    puVar10 = &local_88;
  }
  Serenum_IoSyncIoctlEx
            ((-(uint)(cVar4 != '\0') & 0xfffffff4) + 0x1b001c,cVar4,lVar3,&local_128,puVar10,
             (-(uint)(cVar4 != '\0') & 0x18) + 0x14,0,0);
  Serenum_IoSyncReqWithIrp(param_1,0x12,&local_128,lVar3);
  Serenum_IoSyncReqWithIrp(param_1,2,&local_128,lVar3);
  pcVar12 = local_190;
  cVar4 = local_1a8;
  if ((int)uVar6 < 0) {
    KeReleaseSemaphore(plVar1,0,1,0);
    if (local_190 != (char *)0x0) {
      ExFreePoolWithTag(local_190,0);
    }
    return (ulonglong)uVar6;
  }
  if (local_198[0] == 0) {
    if (local_190 != (char *)0x0) {
      ExFreePoolWithTag(local_190,0);
    }
    if (local_1a0 != 0) {
      Serenum_PDO_EnumMarkMissing((longlong)param_2,*(longlong *)(local_1a0 + 0x40));
      local_1a0 = 0;
    }
    goto LAB_14000b1f1;
  }
  uVar11 = (uint)local_198[0];
  if (((local_1a8 == '\0') ||
      (uVar8 = SerenumCheckForLegacyDevice
                         (param_2,local_190,uVar11,(undefined2 *)&local_188,(undefined2 *)&local_178
                          ,(undefined2 *)&local_168), (char)uVar8 == '\0')) &&
     (uVar7 = Serenum_ParseData(param_2,pcVar12,uVar11,(undefined2 *)&local_188,
                                (undefined2 *)&local_178,(undefined2 *)&local_168,
                                (undefined2 *)&local_158,(undefined2 *)&local_148,
                                (undefined2 *)&local_138), (int)uVar7 < 0)) {
    if (cVar4 == '\0') {
      if (lStack_180 != 0) {
        ExFreePoolWithTag(lStack_180,0);
      }
      RtlInitUnicodeString(&local_188,0);
      if (lStack_170 != 0) {
        ExFreePoolWithTag(lStack_170,0);
      }
      RtlInitUnicodeString(&local_178,0);
      if (lStack_160 != 0) {
        ExFreePoolWithTag(lStack_160,0);
      }
      RtlInitUnicodeString(&local_168,0);
      if (lStack_150 != 0) {
        ExFreePoolWithTag(lStack_150,0);
      }
      RtlInitUnicodeString(&local_158,0);
      if (lStack_140 != 0) {
        ExFreePoolWithTag(lStack_140,0);
      }
      RtlInitUnicodeString(&local_148,0);
      if (lStack_130 != 0) {
        ExFreePoolWithTag(lStack_130,0);
      }
      RtlInitUnicodeString(&local_138,0);
      uVar8 = SerenumCheckForLegacyDevice
                        (param_2,pcVar12,uVar11,(undefined2 *)&local_188,(undefined2 *)&local_178,
                         (undefined2 *)&local_168);
      if ((char)uVar8 != '\0') goto LAB_14000af78;
    }
    if (local_1a0 != 0) {
      Serenum_PDO_EnumMarkMissing((longlong)param_2,*(longlong *)(local_1a0 + 0x40));
      local_1a0 = 0;
    }
    if (lStack_180 != 0) {
      ExFreePoolWithTag(lStack_180,0);
    }
    RtlInitUnicodeString(&local_188,0);
    if (lStack_170 != 0) {
      ExFreePoolWithTag(lStack_170,0);
    }
    RtlInitUnicodeString(&local_178,0);
    if (lStack_160 != 0) {
      ExFreePoolWithTag(lStack_160,0);
    }
    RtlInitUnicodeString(&local_168,0);
    if (lStack_150 != 0) {
      ExFreePoolWithTag(lStack_150,0);
    }
    RtlInitUnicodeString(&local_158,0);
    if (lStack_140 != 0) {
      ExFreePoolWithTag(lStack_140,0);
    }
    RtlInitUnicodeString(&local_148,0);
    if (lStack_130 != 0) {
      ExFreePoolWithTag(lStack_130,0);
    }
    RtlInitUnicodeString(&local_138,0);
    ExFreePoolWithTag(pcVar12,0);
  }
  else {
LAB_14000af78:
    if (pcVar12 != (char *)0x0) {
      ExFreePoolWithTag(pcVar12,0);
    }
    uVar8 = SerenumValidateID((longlong)&local_188);
    if ((((char)uVar8 == '\0') ||
        (uVar8 = SerenumValidateID((longlong)&local_178), (char)uVar8 == '\0')) ||
       (uVar8 = SerenumValidateID((longlong)&local_168), (char)uVar8 == '\0')) {
      if (local_1a0 != 0) {
        Serenum_PDO_EnumMarkMissing((longlong)param_2,*(longlong *)(local_1a0 + 0x40));
        local_1a0 = 0;
      }
      if (lStack_180 != 0) {
        ExFreePoolWithTag(lStack_180,0);
      }
      RtlInitUnicodeString(&local_188,0);
      if (lStack_170 != 0) {
        ExFreePoolWithTag(lStack_170,0);
      }
      RtlInitUnicodeString(&local_178,0);
      if (lStack_160 != 0) {
        ExFreePoolWithTag(lStack_160,0);
      }
      RtlInitUnicodeString(&local_168,0);
      if (lStack_150 != 0) {
        ExFreePoolWithTag(lStack_150,0);
      }
      RtlInitUnicodeString(&local_158,0);
      if (lStack_140 != 0) {
        ExFreePoolWithTag(lStack_140,0);
      }
      RtlInitUnicodeString(&local_148,0);
      if (lStack_130 != 0) {
        ExFreePoolWithTag(lStack_130,0);
      }
      RtlInitUnicodeString(&local_138,0);
    }
    else {
      if (local_1a0 != 0) {
        lVar3 = *(longlong *)(local_1a0 + 0x40);
        cVar4 = RtlEqualUnicodeString(lVar3 + 0x20,&local_188,0);
        if ((cVar4 == '\0') ||
           (cVar4 = RtlEqualUnicodeString(lVar3 + 0x30,&local_178,0), cVar4 == '\0')) {
          Serenum_PDO_EnumMarkMissing((longlong)param_2,lVar3);
          local_1a0 = 0;
        }
        else {
          local_1a7 = 1;
        }
        if (local_1a0 != 0) goto LAB_14000b1f1;
      }
      uVar11 = IoCreateDevice(*(undefined8 *)(*param_2 + 8),0x88,&local_108);
      if ((int)uVar11 < 0) {
        KeReleaseSemaphore(plVar1,0,1);
        return (ulonglong)uVar11;
      }
      lVar3 = *(longlong *)(local_1a0 + 0x40);
      *(undefined8 *)(lVar3 + 0x20) = local_188;
      *(longlong *)(lVar3 + 0x28) = lStack_180;
      *(undefined8 *)(lVar3 + 0x30) = local_178;
      *(longlong *)(lVar3 + 0x38) = lStack_170;
      *(undefined8 *)(lVar3 + 0x40) = local_168;
      *(longlong *)(lVar3 + 0x48) = lStack_160;
      *(undefined8 *)(lVar3 + 0x50) = local_158;
      *(longlong *)(lVar3 + 0x58) = lStack_150;
      *(undefined8 *)(lVar3 + 0x60) = local_148;
      *(longlong *)(lVar3 + 0x68) = lStack_140;
      *(undefined8 *)(lVar3 + 0x70) = local_138;
      *(longlong *)(lVar3 + 0x78) = lStack_130;
      Serenum_InitPDO(local_1a0,param_2);
    }
  }
LAB_14000b1f1:
  KeReleaseSemaphore(plVar1,0,1);
  *local_110 = local_1a7;
  return 0;
}



===== Serenum_Wait @ 14000b248 =====

void Serenum_Wait(undefined8 param_1,undefined8 param_2)

{
  KeSetTimer(param_1,param_2,0);
  KeWaitForSingleObject(param_1,0,0,0,0);
  return;
}



===== entry @ 14000c010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 14000c044 =====

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



===== DriverEntry @ 14000c078 =====

undefined8 DriverEntry(longlong param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)(param_1 + 0x70);
  for (lVar1 = 0x1b; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = Serenum_DispatchPassThrough;
    puVar2 = puVar2 + 1;
  }
  *(code **)(param_1 + 0x80) = Serenum_CreateClose;
  *(code **)(param_1 + 0x70) = Serenum_CreateClose;
  *(code **)(param_1 + 0x148) = Serenum_PnP;
  *(code **)(param_1 + 0x120) = Serenum_Power;
  *(code **)(param_1 + 0xe0) = Serenum_IoCtl;
  *(code **)(param_1 + 0xe8) = Serenum_InternIoCtl;
  *(code **)(param_1 + 0x68) = Serenum_DriverUnload;
  *(code **)(*(longlong *)(param_1 + 0x30) + 8) = Serenum_AddDevice;
  return 0;
}


