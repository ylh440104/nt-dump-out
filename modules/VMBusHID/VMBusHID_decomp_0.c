
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



===== BeginShutdown @ 1c0001020 =====

void BeginShutdown(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  code *pcVar6;
  undefined1 uVar7;
  longlong lVar8;
  
  lVar1 = param_1 + 0x28;
  uVar7 = KeAcquireSpinLockRaiseToDpc(lVar1);
  while( true ) {
    lVar8 = IrpQueueRemoveNext(param_1 + 0xc0);
    if (lVar8 == 0) break;
    *(undefined4 *)(lVar8 + 0x30) = 0xc0000056;
    KeReleaseSpinLock(lVar1,uVar7);
    IofCompleteRequest(lVar8,0);
    uVar7 = KeAcquireSpinLockRaiseToDpc(lVar1);
  }
  while( true ) {
    lVar8 = IrpQueueRemoveNext(param_1 + 0x118);
    if (lVar8 == 0) break;
    *(undefined4 *)(lVar8 + 0x30) = 0xc0000056;
    KeReleaseSpinLock(lVar1,uVar7);
    IofCompleteRequest(lVar8,0);
    uVar7 = KeAcquireSpinLockRaiseToDpc(lVar1);
  }
  while( true ) {
    lVar8 = IrpQueueRemoveNext(param_1 + 0x170);
    if (lVar8 == 0) break;
    *(undefined4 *)(lVar8 + 0x30) = 0xc0000056;
    KeReleaseSpinLock(lVar1,uVar7);
    IofCompleteRequest(lVar8,0);
    uVar7 = KeAcquireSpinLockRaiseToDpc(lVar1);
  }
  plVar2 = (longlong *)(param_1 + 0xb0);
  if ((longlong *)*plVar2 != plVar2) {
    plVar3 = *(longlong **)(param_1 + 0xb8);
    do {
      plVar4 = (longlong *)*plVar2;
      if (((longlong *)plVar4[1] != plVar2) ||
         (lVar8 = *plVar4, *(longlong **)(lVar8 + 8) != plVar4)) {
LAB_1c000120c:
        pcVar6 = (code *)swi(0x29);
        (*pcVar6)(3);
        pcVar6 = (code *)swi(3);
        (*pcVar6)();
        return;
      }
      *plVar2 = lVar8;
      *(longlong **)(lVar8 + 8) = plVar2;
      puVar5 = *(undefined8 **)(param_1 + 0xb8);
      if ((longlong *)*puVar5 != plVar2) goto LAB_1c000120c;
      *plVar4 = (longlong)plVar2;
      plVar4[1] = (longlong)puVar5;
      *puVar5 = plVar4;
      *(longlong **)(param_1 + 0xb8) = plVar4;
      KeReleaseSpinLock(lVar1,uVar7);
      IoCancelIrp(plVar4[2]);
      uVar7 = KeAcquireSpinLockRaiseToDpc(lVar1);
    } while (plVar4 != plVar3);
  }
  KeReleaseSpinLock(lVar1,uVar7);
  IoCancelIrp(*(undefined8 *)(*(longlong *)(param_1 + 0xa8) + 0x10));
  return;
}



===== CompleteShutdown @ 1c000121c =====

void CompleteShutdown(longlong param_1)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong lVar3;
  code *pcVar4;
  longlong *plVar5;
  undefined1 *puVar6;
  longlong lVar7;
  undefined4 *puVar8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar6 = auStack_28;
  plVar5 = (longlong *)(param_1 + 0xb0);
  do {
    plVar1 = (longlong *)*plVar5;
    if (plVar1 == plVar5) {
LAB_1c0001261:
      puVar2 = *(undefined8 **)(param_1 + 0xa8);
      if (puVar2 != (undefined8 *)0x0) {
        *(undefined8 *)(puVar6 + -8) = 0x1c0001272;
        FreeIoPackage(puVar2);
        *(undefined8 *)(param_1 + 0xa8) = 0;
      }
      lVar7 = *(longlong *)(param_1 + 0x78);
      if (lVar7 != 0) {
        *(undefined8 *)(puVar6 + -8) = 0x1c000128f;
        ExFreePoolWithTag(lVar7,0x64684d56);
        *(undefined8 *)(param_1 + 0x78) = 0;
      }
      lVar7 = *(longlong *)(param_1 + 0x80);
      if (lVar7 != 0) {
        *(undefined8 *)(puVar6 + -8) = 0x1c00012b1;
        ExFreePoolWithTag(lVar7,0x64684d56);
        *(undefined8 *)(param_1 + 0x80) = 0;
      }
      puVar8 = (undefined4 *)(param_1 + 0x4f0);
      lVar7 = 100;
      plVar5 = (longlong *)(param_1 + 0x1d0);
      do {
        lVar3 = *plVar5;
        if (lVar3 != 0) {
          *(undefined8 *)(puVar6 + -8) = 0x1c00012e5;
          ExFreePoolWithTag(lVar3,0x64684d56);
          *plVar5 = 0;
        }
        *puVar8 = 0;
        plVar5 = plVar5 + 1;
        puVar8 = puVar8 + 1;
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
      return;
    }
    if (((longlong *)plVar1[1] != plVar5) || (lVar7 = *plVar1, *(longlong **)(lVar7 + 8) != plVar1))
    {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      puVar6 = auStack_20;
      goto LAB_1c0001261;
    }
    *plVar5 = lVar7;
    *(longlong **)(lVar7 + 8) = plVar5;
    FreeIoPackage(plVar1);
  } while( true );
}



===== DispatchClose @ 1c0001320 =====

void DispatchClose(longlong param_1,longlong param_2)

{
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  IofCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 8));
  return;
}



===== DispatchInternalIoctl @ 1c0001350 =====

int DispatchInternalIoctl(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter InternalIoctl\n");
  }
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  iVar2 = IoAcquireRemoveLockEx(lVar1 + 8,param_2,"",1,0x20);
  if (iVar2 < 0) {
    if (g_TracingEnabled != '\0') {
      DbgPrint("VMBusHID: InternalIoctl: Failed to acquire remove lock: %x\n\n",iVar2);
    }
    *(int *)(param_2 + 0x30) = iVar2;
    IofCompleteRequest(param_2,0);
    return iVar2;
  }
  if (*(int *)(lVar1 + 0x30) - 5U < 2) {
    iVar2 = -0x3fffffaa;
  }
  else {
    iVar2 = *(int *)(*(longlong *)(param_2 + 0xb8) + 0x18);
    if (iVar2 == 0xb0003) {
      if (g_TracingEnabled != '\0') {
        DbgPrint("VMBusHID: IOCTL_HID_GET_DEVICE_DESCRIPTOR\n");
      }
      iVar2 = GetHidDescriptor(param_1,param_2);
      goto LAB_1c0001515;
    }
    if (iVar2 == 0xb0007) {
      if (g_TracingEnabled != '\0') {
        DbgPrint("VMBusHID: IOCTL_HID_GET_REPORT_DESCRIPTOR\n");
      }
      iVar2 = GetReportDescriptor(param_1,param_2);
      goto LAB_1c0001515;
    }
    if (iVar2 == 0xb000b) {
      if (g_TracingEnabled != '\0') {
        DbgPrint("VMBusHID: IOCTL_HID_READ_REPORT\n");
      }
      uVar3 = ReadReport(param_1,param_2);
      iVar2 = (int)uVar3;
      goto LAB_1c0001515;
    }
    if (iVar2 == 0xb0027) {
      if (g_TracingEnabled != '\0') {
        DbgPrint("VMBusHID: IOCTL_HID_GET_DEVICE_ATTRIBUTES\n");
      }
      iVar2 = GetDeviceAttributes(param_1,param_2);
      goto LAB_1c0001515;
    }
    if (g_TracingEnabled != '\0') {
      DbgPrint("VMBusHID: Unsupported internal IOCTL.\n");
    }
    iVar2 = -0x3fffff45;
  }
  *(int *)(param_2 + 0x30) = iVar2;
  IofCompleteRequest(param_2,0);
LAB_1c0001515:
  IoReleaseRemoveLockEx(lVar1 + 8,param_2,0x20);
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Exit InternalIoctl\n");
  }
  return iVar2;
}



===== DispatchPower @ 1c0001570 =====

ulonglong DispatchPower(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  bool bVar5;
  
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter Power\n");
  }
  uVar3 = IoAcquireRemoveLockEx
                    (*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10) + 8,param_2,"",1,0x20);
  uVar4 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) {
    PoStartNextPowerIrp(param_2);
    if (g_TracingEnabled != '\0') {
      DbgPrint("VMBusHID: Power: Failed to acquire remove lock: %x\n\n",uVar4);
    }
    *(uint *)(param_2 + 0x30) = uVar3;
    IofCompleteRequest(param_2,0);
  }
  else {
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
    lVar2 = *(longlong *)(param_2 + 0xb8);
    *(undefined8 *)(lVar2 + -8) = 0;
    bVar5 = g_TracingEnabled != '\0';
    *(code **)(lVar2 + -0x10) = PowerComplete;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    if (bVar5) {
      DbgPrint("VMBusHID: Exit Power\n");
    }
    uVar4 = PoCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 8),param_2);
  }
  return uVar4;
}



===== PnPStartComplete @ 1c00016b0 =====

undefined8 PnPStartComplete(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter PnPComplete\n");
  }
  if (*(char *)(param_2 + 0x41) != '\0') {
    KeSetEvent(param_3,0,0);
  }
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Exit PnPComplete\n");
  }
  return 0xc0000016;
}



===== PowerComplete @ 1c0001730 =====

int PowerComplete(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_2 + 0x30);
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  if (((-1 < iVar4) && (lVar3 = *(longlong *)(param_2 + 0xb8), *(char *)(lVar3 + 1) == '\x02')) &&
     (*(int *)(lVar3 + 0x10) == 1)) {
    if (*(int *)(lVar3 + 0x18) == 1) {
      if (*(int *)(lVar2 + 0x38) != 1) {
        iVar4 = Startup(param_1);
      }
    }
    else if ((*(int *)(lVar3 + 0x18) == 4) && (*(int *)(lVar2 + 0x38) != 4)) {
      BeginShutdown(lVar2);
      iVar4 = 0;
      *(undefined1 *)(lVar2 + 0x70) = 0;
      *(undefined4 *)(*(longlong *)(lVar2 + 0xa8) + 0x20) = 2;
    }
    PoSetPowerState(param_1,1,*(undefined4 *)(lVar3 + 0x18));
  }
  IoReleaseRemoveLockEx(lVar2 + 8,param_2,0x20);
  return iVar4;
}



===== Startup @ 1c0001814 =====

int Startup(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  
  iVar2 = 0;
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  if (*(char *)(lVar1 + 0x70) == '\0') {
    *(undefined1 *)(lVar1 + 0x70) = 1;
    KeResetEvent(lVar1 + 0x40);
    KeResetEvent(lVar1 + 0x58);
    iVar2 = DoProtocolNegotiation(param_1);
    if (-1 < iVar2) {
      iVar2 = WaitForDeviceInformation(param_1);
    }
  }
  else if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: PnP Stop/Start detected.\n");
  }
  return iVar2;
}



===== GetDeviceAttributes @ 1c00018a8 =====

undefined4 GetDeviceAttributes(longlong param_1,longlong param_2)

{
  undefined4 *puVar1;
  longlong lVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter GetDeviceAttributes\n\n");
  }
  puVar1 = *(undefined4 **)(param_2 + 0x70);
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 0x20) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    uVar3 = 0xc0000023;
  }
  else {
    *(undefined8 *)(param_2 + 0x38) = 0x20;
    *puVar1 = 0x20;
    *(undefined2 *)(puVar1 + 1) = *(undefined2 *)(lVar2 + 0x8c);
    *(undefined2 *)((longlong)puVar1 + 6) = *(undefined2 *)(lVar2 + 0x8e);
    *(undefined2 *)(puVar1 + 2) = *(undefined2 *)(lVar2 + 0x90);
  }
  *(undefined4 *)(param_2 + 0x30) = uVar3;
  IofCompleteRequest(param_2,0);
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Exit GetDeviceAttributes\n\n");
  }
  return uVar3;
}



===== GetHidDescriptor @ 1c0001978 =====

undefined4 GetHidDescriptor(longlong param_1,longlong param_2)

{
  uint uVar1;
  byte *_Src;
  uint uVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter GetHidDescriptor\n\n");
  }
  uVar1 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (uVar1 == 0) {
    uVar4 = 0xc0000023;
    uVar3 = 0;
  }
  else {
    _Src = *(byte **)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10) + 0x78);
    uVar2 = (uint)*_Src;
    if (uVar1 <= uVar2) {
      uVar2 = uVar1;
    }
    uVar3 = (ulonglong)uVar2;
    memcpy(*(void **)(param_2 + 0x70),_Src,(ulonglong)uVar2);
  }
  *(ulonglong *)(param_2 + 0x38) = uVar3;
  *(undefined4 *)(param_2 + 0x30) = uVar4;
  IofCompleteRequest(param_2,0);
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Exit GetHidDescriptor\n\n");
  }
  return uVar4;
}



===== GetReportDescriptor @ 1c0001a38 =====

undefined4 GetReportDescriptor(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter GetReportDescriptor\n\n");
  }
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  uVar1 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (uVar1 == 0) {
    uVar5 = 0xc0000023;
    uVar4 = 0;
  }
  else {
    uVar3 = (uint)*(ushort *)(*(longlong *)(lVar2 + 0x78) + 7);
    if (uVar1 <= uVar3) {
      uVar3 = uVar1;
    }
    uVar4 = (ulonglong)uVar3;
    memcpy(*(void **)(param_2 + 0x70),*(void **)(lVar2 + 0x80),(ulonglong)uVar3);
  }
  *(ulonglong *)(param_2 + 0x38) = uVar4;
  *(undefined4 *)(param_2 + 0x30) = uVar5;
  IofCompleteRequest(param_2,0);
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Exit GetReportDescriptor\n\n");
  }
  return uVar5;
}



===== ReadReport @ 1c0001afc =====

ulonglong ReadReport(longlong param_1,longlong param_2)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  void *_Dst;
  void *_Src;
  bool bVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  uint uVar8;
  
  uVar7 = 0x103;
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter ReadReport\n\n");
  }
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  uVar1 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x28);
  _Dst = *(void **)(param_2 + 0x70);
  bVar4 = false;
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter InputReportCacheRetrieve\n\n");
  }
  uVar2 = *(uint *)(lVar3 + 0x1c8);
  uVar6 = (ulonglong)uVar2;
  if ((*(uint *)(lVar3 + 0x1cc) == uVar2) && (*(int *)(lVar3 + 0x4f0 + uVar6 * 4) == 0)) {
    uVar8 = 0;
  }
  else {
    uVar8 = *(uint *)(lVar3 + 0x4f0 + uVar6 * 4);
    _Src = *(void **)(lVar3 + 0x1d0 + uVar6 * 8);
    if (((uVar8 == 0) || (_Src == (void *)0x0)) && (g_TracingEnabled != '\0')) {
      DbgPrint("VMBusHID: InputReportCacheRetrieve: Inconsistent indexes\n\n");
    }
    if ((_Dst != (void *)0x0) && (uVar8 <= uVar1)) {
      bVar4 = true;
      memcpy(_Dst,_Src,(ulonglong)uVar8);
      ExFreePoolWithTag(_Src,0x64684d56);
      *(undefined8 *)(lVar3 + 0x1d0 + (ulonglong)uVar2 * 8) = 0;
      *(undefined4 *)(lVar3 + 0x4f0 + (ulonglong)uVar2 * 4) = 0;
      *(int *)(lVar3 + 0x1c8) = *(int *)(lVar3 + 0x1c8) + 1;
      if (99 < *(uint *)(lVar3 + 0x1c8)) {
        *(undefined4 *)(lVar3 + 0x1c8) = 0;
      }
    }
  }
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Exit InputReportCacheRetrieve\n\n");
  }
  if ((!bVar4) && (uVar8 == 0)) {
    if (g_TracingEnabled != '\0') {
      DbgPrint("VMBusHID: ReadReport: No cached reports\n\n");
    }
    if (*(int *)(lVar3 + 0x30) - 5U < 2) {
      uVar7 = 0xc0000056;
    }
    else {
      uVar6 = IrpQueueInsert(lVar3 + 0xc0,param_2);
      uVar7 = uVar6 & 0xffffffff;
      if (-1 < (int)uVar6) {
        uVar7 = 0x103;
      }
    }
  }
  KeReleaseSpinLock(lVar3 + 0x28,uVar5);
  if ((int)uVar7 < 0) {
LAB_1c0001d08:
    if ((int)uVar7 == 0x103) goto LAB_1c0001d24;
  }
  else if (bVar4) {
    if (g_TracingEnabled != '\0') {
      DbgPrint("VMBusHID: ReadReport: Success\n\n");
    }
    uVar7 = 0;
    *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar8;
  }
  else {
    if (uVar8 == 0) goto LAB_1c0001d08;
    uVar7 = 0xc0000023;
    *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar8;
  }
  *(int *)(param_2 + 0x30) = (int)uVar7;
  IofCompleteRequest(param_2,0);
LAB_1c0001d24:
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Exit ReadReport\n\n");
  }
  return uVar7;
}



===== OnInitialDeviceInfo @ 1c0001d60 =====

int OnInitialDeviceInfo(longlong *param_1,longlong param_2)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  void *pvVar6;
  char *pcVar7;
  ulonglong _Size;
  bool bVar8;
  undefined1 local_res8 [8];
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_20;
  
  local_res8[0] = 0;
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter OnInitialDeviceInfo\n\n");
  }
  bVar8 = g_TracingEnabled != '\0';
  uVar2 = *(undefined4 *)(param_2 + 0xc);
  uVar3 = *(undefined4 *)(param_2 + 0x10);
  uVar4 = *(undefined4 *)(param_2 + 0x14);
  *(undefined4 *)(param_1 + 0x11) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)((longlong)param_1 + 0x8c) = uVar2;
  *(undefined4 *)(param_1 + 0x12) = uVar3;
  *(undefined4 *)((longlong)param_1 + 0x94) = uVar4;
  uVar2 = *(undefined4 *)(param_2 + 0x1c);
  uVar3 = *(undefined4 *)(param_2 + 0x20);
  uVar4 = *(undefined4 *)(param_2 + 0x24);
  *(undefined4 *)(param_1 + 0x13) = *(undefined4 *)(param_2 + 0x18);
  *(undefined4 *)((longlong)param_1 + 0x9c) = uVar2;
  *(undefined4 *)(param_1 + 0x14) = uVar3;
  *(undefined4 *)((longlong)param_1 + 0xa4) = uVar4;
  if (bVar8) {
    DbgPrint("VMBusHID: \nDevice Attributes:\n\tSize: %d\n\tVendorID: %d\n\tProductID: %d\n\tVersion: %d\n\n\n"
             ,(int)param_1[0x11],*(undefined2 *)((longlong)param_1 + 0x8c),
             *(undefined2 *)((longlong)param_1 + 0x8e),(short)param_1[0x12]);
  }
  _Size = (ulonglong)*(byte *)(param_2 + 0x28);
  pvVar6 = (void *)ExAllocatePool2(0x40,_Size,0x64684d56);
  param_1[0xf] = (longlong)pvVar6;
  if (pvVar6 == (void *)0x0) {
    if (g_TracingEnabled != '\0') {
      pcVar7 = "VMBusHID: OnInitialDeviceInfo: Unable to allocate a HID_DESCRIPTOR\n\n";
LAB_1c0001e23:
      DbgPrint(pcVar7);
    }
  }
  else {
    memcpy(pvVar6,(void *)(param_2 + 0x28),_Size);
    if (g_TracingEnabled != '\0') {
      puVar1 = (undefined1 *)param_1[0xf];
      DbgPrint("VMBusHID: \nHidDescriptor:\n\tLength: %d\n\tType: %d\n\tcdHID: %d\n\tCountry: %d\n\tNumDescr: %d\n\t[0]ReportType: %d\n\n\n"
               ,*puVar1,puVar1[1],*(undefined2 *)(puVar1 + 2),puVar1[4],puVar1[5],puVar1[6]);
    }
    pvVar6 = (void *)ExAllocatePool2(0x40,*(undefined2 *)(param_2 + 0x2f),0x64684d56);
    param_1[0x10] = (longlong)pvVar6;
    if (pvVar6 != (void *)0x0) {
      memcpy(pvVar6,(void *)(param_2 + 0x28 + _Size),(ulonglong)*(ushort *)(param_2 + 0x2f));
      local_28 = 3;
      local_24 = 1;
      local_20 = 0;
      iVar5 = SendVMBusMessage(*param_1,&local_28,9,local_res8);
      if (-1 < iVar5) {
        KeSetEvent(param_1 + 0xb,0,0);
      }
      goto LAB_1c0001f2c;
    }
    if (g_TracingEnabled != '\0') {
      pcVar7 = "VMBusHID: OnInitialDeviceInfo: Unable to allocate a report descriptor\n\n";
      goto LAB_1c0001e23;
    }
  }
  iVar5 = -0x3fffff66;
LAB_1c0001f2c:
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Exit OnInitialDeviceInfo\n\n");
  }
  return iVar5;
}



===== OnInputReport @ 1c0001f70 =====

int OnInputReport(longlong param_1,longlong param_2)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  bool bVar4;
  undefined1 uVar5;
  longlong lVar6;
  ulonglong uVar7;
  void *_Dst;
  int iVar8;
  
  iVar8 = 0;
  bVar4 = false;
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter OnInputReport\n\n");
  }
  do {
    uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x28);
    lVar6 = IrpQueueRemoveNext(param_1 + 0xc0);
    if (lVar6 == 0) {
      iVar8 = 0;
      uVar1 = *(uint *)(param_2 + 4);
      if (g_TracingEnabled != '\0') {
        DbgPrint("VMBusHID: Enter InputReportCacheSave\n\n");
      }
      uVar2 = *(uint *)(param_1 + 0x1cc);
      uVar7 = (ulonglong)*(uint *)(param_1 + 0x1c8);
      if ((uVar2 == *(uint *)(param_1 + 0x1c8)) && (*(int *)(param_1 + 0x4f0 + uVar7 * 4) != 0)) {
        uVar3 = *(undefined8 *)(param_1 + 0x1d0 + uVar7 * 8);
        *(undefined8 *)(param_1 + 0x1d0 + uVar7 * 8) = 0;
        *(undefined4 *)(param_1 + 0x4f0 + uVar7 * 4) = 0;
        ExFreePoolWithTag(uVar3,0x64684d56);
        *(int *)(param_1 + 0x1c8) = *(int *)(param_1 + 0x1c8) + 1;
        if (99 < *(uint *)(param_1 + 0x1c8)) {
          *(undefined4 *)(param_1 + 0x1c8) = 0;
        }
      }
      _Dst = (void *)ExAllocatePool2(0x40,(ulonglong)uVar1,0x64684d56);
      if (_Dst == (void *)0x0) {
        if (g_TracingEnabled != '\0') {
          DbgPrint("VMBusHID: InputReportCacheSave: Unable to allocate report cache space.\n\n");
        }
        iVar8 = -0x3fffff66;
      }
      else {
        memcpy(_Dst,(void *)(param_2 + 8),(ulonglong)uVar1);
        *(void **)(param_1 + 0x1d0 + (ulonglong)uVar2 * 8) = _Dst;
        *(uint *)(param_1 + 0x4f0 + (ulonglong)uVar2 * 4) = uVar1;
        *(int *)(param_1 + 0x1cc) = *(int *)(param_1 + 0x1cc) + 1;
        if (99 < *(uint *)(param_1 + 0x1cc)) {
          *(undefined4 *)(param_1 + 0x1cc) = 0;
        }
      }
      if (g_TracingEnabled != '\0') {
        DbgPrint("VMBusHID: Exit InputReportCacheSave\n\n");
      }
      if ((-1 < iVar8) && (g_TracingEnabled != '\0')) {
        DbgPrint("VMBusHID: OnInputReport: Cached.\n\n");
      }
      bVar4 = true;
    }
    KeReleaseSpinLock(param_1 + 0x28,uVar5);
    if (lVar6 != 0) {
      uVar1 = *(uint *)(*(longlong *)(lVar6 + 0xb8) + 8);
      if (uVar1 < *(uint *)(param_2 + 4)) {
        if (g_TracingEnabled != '\0') {
          DbgPrint("VMBusHID: OnInputReport: IRP Buffer too small.\n\n");
        }
        iVar8 = -0x3fffffdd;
      }
      else {
        if (g_TracingEnabled != '\0') {
          DbgPrint("VMBusHID: OnInputReport: Success.\n\n");
        }
        memcpy(*(void **)(lVar6 + 0x70),(void *)(param_2 + 8),(ulonglong)*(uint *)(param_2 + 4));
        *(ulonglong *)(lVar6 + 0x38) = (ulonglong)uVar1;
        bVar4 = true;
        iVar8 = 0;
      }
      *(int *)(lVar6 + 0x30) = iVar8;
      IofCompleteRequest(lVar6,0);
    }
  } while (!bVar4);
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Exit OnInputReport\n\n");
  }
  return iVar8;
}



===== OnProtocolResponse @ 1c0002220 =====

undefined8 OnProtocolResponse(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter OnProtocolResponse\n\n");
  }
  if (*(char *)(param_2 + 0xc) == '\0') {
    if (g_TracingEnabled != '\0') {
      DbgPrint("VMBusHID: The protocol request was not approved for version %d.%d!!!\n\n",
               *(undefined2 *)(param_2 + 10),*(undefined2 *)(param_2 + 8));
    }
    *(undefined1 *)(param_1 + 0x71) = 0;
    KeSetEvent(param_1 + 0x40,0,0);
    uVar1 = 0xc0000001;
  }
  else {
    if (g_TracingEnabled != '\0') {
      DbgPrint("VMBusHID: The protocol request was approved for version %d.%d.\n\n",
               *(undefined2 *)(param_2 + 10),*(undefined2 *)(param_2 + 8));
    }
    *(undefined1 *)(param_1 + 0x71) = 1;
    KeSetEvent(param_1 + 0x40,0,0);
  }
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Exit OnProtocolResponse\n\n");
  }
  return uVar1;
}



===== CsqAcquireLock @ 1c0002320 =====

void CsqAcquireLock(longlong param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  bool bVar2;
  
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter CsqAcquireLock\n\n");
  }
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x50);
  bVar2 = g_TracingEnabled != '\0';
  *param_2 = uVar1;
  if (bVar2) {
    DbgPrint("VMBusHID: Exit CsqAcquireLock\n\n");
  }
  return;
}



===== CsqCompleteCanceledIrp @ 1c0002390 =====

void CsqCompleteCanceledIrp(undefined8 param_1,longlong param_2)

{
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter CsqCompleteCanceledIrp\n\n");
  }
  if (*(longlong *)(param_2 + 0x78) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x78),0x64684d56);
    *(undefined8 *)(param_2 + 0x78) = 0;
  }
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  IofCompleteRequest(param_2,0);
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Exit CsqCompleteCanceledIrp\n\n");
  }
  return;
}



===== CsqInsertIrp @ 1c0002420 =====

void CsqInsertIrp(longlong param_1,longlong param_2)

{
  code *pcVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined1 *puVar5;
  bool bVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter CsqInsertIrp\n\n");
  }
  puVar5 = auStack_28;
  lVar3 = param_1 + 0x40;
  plVar4 = *(longlong **)(param_1 + 0x48);
  plVar2 = (longlong *)(param_2 + 0xa8);
  if (*plVar4 != lVar3) {
    lVar3 = 3;
    pcVar1 = (code *)swi(0x29);
    plVar2 = (longlong *)(*pcVar1)();
    puVar5 = auStack_20;
  }
  bVar6 = g_TracingEnabled != '\0';
  *plVar2 = lVar3;
  plVar2[1] = (longlong)plVar4;
  *plVar4 = (longlong)plVar2;
  *(longlong **)(lVar3 + 8) = plVar2;
  if (bVar6) {
    *(undefined8 *)(puVar5 + -8) = 0x1c000248c;
    DbgPrint("VMBusHID: Exit CsqInsertIrp\n\n");
  }
  return;
}



===== CsqPeekNextIrp @ 1c00024b0 =====

longlong CsqPeekNextIrp(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  
  lVar2 = 0;
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter CsqPeekNextIrp\n\n");
  }
  plVar1 = *(longlong **)(param_1 + 0x40);
  if (plVar1 != (longlong *)(param_1 + 0x40)) {
    if (param_2 == 0) {
      lVar2 = (longlong)(plVar1 + -0x15);
    }
    else {
      lVar2 = *(longlong *)(param_2 + 0xa8) + -0xa8;
    }
  }
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Exit CsqPeekNextIrp\n\n");
  }
  return lVar2;
}



===== CsqReleaseLock @ 1c0002540 =====

void CsqReleaseLock(longlong param_1,undefined1 param_2)

{
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter CsqReleaseLock\n\n");
  }
  KeReleaseSpinLock(param_1 + 0x50,param_2);
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Exit CsqReleaseLock\n\n");
  }
  return;
}



===== CsqRemoveIrp @ 1c00025b0 =====

void CsqRemoveIrp(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  bool bVar5;
  
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter CsqRemoveIrp\n\n");
  }
  plVar1 = (longlong *)(param_2 + 0xa8);
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) != plVar1) ||
     (plVar3 = *(longlong **)(param_2 + 0xb0), (longlong *)*plVar3 != plVar1)) {
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  bVar5 = g_TracingEnabled != '\0';
  *plVar3 = lVar2;
  *(longlong **)(lVar2 + 8) = plVar3;
  if (bVar5) {
    DbgPrint("VMBusHID: Exit CsqRemoveIrp\n\n");
  }
  return;
}



===== IrpQueueInsert @ 1c0002628 =====

undefined8 IrpQueueInsert(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter IrpQueueInsert\n\n");
  }
  lVar1 = ExAllocatePool2(0x40,0x18,0x64684d56);
  if (lVar1 == 0) {
    if (g_TracingEnabled != '\0') {
      DbgPrint("VMBusHID: IrpQueueInsert: Unable to allocate context.\n\n");
    }
    uVar2 = 0xc000009a;
  }
  else {
    *(longlong *)(param_2 + 0x78) = lVar1;
    IoCsqInsertIrp(param_1,param_2,lVar1);
  }
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Exit IrpQueueInsert\n\n");
  }
  return uVar2;
}



===== IrpQueueRemoveNext @ 1c00026ec =====

longlong IrpQueueRemoveNext(undefined8 param_1)

{
  longlong lVar1;
  
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter IrpQueueRemoveNext\n\n");
  }
  lVar1 = IoCsqRemoveNextIrp(param_1,0);
  if (lVar1 != 0) {
    ExFreePoolWithTag(*(undefined8 *)(lVar1 + 0x78),0x64684d56);
    *(undefined8 *)(lVar1 + 0x78) = 0;
  }
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Exit IrpQueueRemoveNext\n\n");
  }
  return lVar1;
}



===== AllocateIoPackage @ 1c0002770 =====

undefined8 * AllocateIoPackage(longlong param_1,undefined8 param_2,char param_3,uint param_4)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter AllocateIoPackage\n\n");
  }
  puVar1 = (undefined8 *)ExAllocatePool2(0x40,(ulonglong)param_4 + 0x27,0x64684d56);
  if (puVar1 == (undefined8 *)0x0) {
    if (g_TracingEnabled == '\0') {
      return (undefined8 *)0x0;
    }
    DbgPrint("VMBusHID: AllocateIoPackage: Unable to allocate an IO_PACKAGE\n\n");
  }
  else {
    uVar2 = InitializeIoPackage(param_1,param_2,param_3,param_4,(longlong)puVar1);
    if ((int)uVar2 < 0) {
      FreeIoPackage(puVar1);
      puVar1 = (undefined8 *)0x0;
    }
  }
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Exit AllocateIoPackage\n\n");
  }
  return puVar1;
}



===== FreeIoPackage @ 1c0002858 =====

void FreeIoPackage(undefined8 *param_1)

{
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter FreeIoPackage\n\n");
  }
  if (param_1 != (undefined8 *)0x0) {
    if (g_TracingEnabled != '\0') {
      DbgPrint("VMBusHID: Enter ClearIoPackage\n\n");
    }
    if (param_1[3] != 0) {
      IoFreeMdl();
    }
    if (param_1[2] != 0) {
      IoFreeIrp();
    }
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    if (g_TracingEnabled != '\0') {
      DbgPrint("VMBusHID: Exit ClearIoPackage\n\n");
    }
    ExFreePoolWithTag(param_1,0x64684d56);
  }
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Exit FreeIoPackage\n\n");
  }
  return;
}



===== GetVMBusMessage @ 1c0002934 =====

int GetVMBusMessage(longlong param_1)

{
  ulonglong uVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined1 uVar7;
  int iVar8;
  char *pcVar9;
  
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter GetVMBusMessage\n\n");
  }
  lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  while( true ) {
    iVar8 = 0;
    memset((void *)(*(longlong *)(lVar4 + 0xa8) + 0x24),0,0x240);
    uVar7 = KeAcquireSpinLockRaiseToDpc(lVar4 + 0x28);
    if (*(int *)(lVar4 + 0x30) - 5U < 2) {
      iVar8 = -0x3fffffaa;
    }
    else {
      LOCK();
      *(undefined4 *)(*(longlong *)(lVar4 + 0xa8) + 0x20) = 1;
      UNLOCK();
      IoReuseIrp(*(undefined8 *)(*(longlong *)(lVar4 + 0xa8) + 0x10),0);
      lVar5 = *(longlong *)(*(longlong *)(lVar4 + 0xa8) + 0x18);
      if ((*(byte *)(lVar5 + 10) & 0x20) != 0) {
        MmUnmapLockedPages(*(undefined8 *)(lVar5 + 0x18),lVar5);
      }
      puVar6 = *(undefined8 **)(*(longlong *)(lVar4 + 0xa8) + 0x18);
      uVar1 = *(longlong *)(lVar4 + 0xa8) + 0x24;
      *puVar6 = 0;
      *(ushort *)(puVar6 + 1) = (((ushort)(((ushort)uVar1 & 0xfff) + 0x123f) >> 0xc) + 6) * 8;
      *(undefined2 *)((longlong)puVar6 + 10) = 0;
      *(uint *)((longlong)puVar6 + 0x2c) = (uint)uVar1 & 0xfff;
      puVar6[4] = uVar1 & 0xfffffffffffff000;
      *(undefined4 *)(puVar6 + 5) = 0x240;
      MmBuildMdlForNonPagedPool(*(undefined8 *)(*(longlong *)(lVar4 + 0xa8) + 0x18));
      *(undefined8 *)(*(longlong *)(*(longlong *)(lVar4 + 0xa8) + 0x10) + 8) =
           *(undefined8 *)(*(longlong *)(lVar4 + 0xa8) + 0x18);
      lVar5 = *(longlong *)(*(longlong *)(*(longlong *)(lVar4 + 0xa8) + 0x10) + 0xb8);
      *(undefined1 *)(lVar5 + -0x48) = 3;
      *(undefined4 *)(lVar5 + -0x40) = 0x240;
    }
    KeReleaseSpinLock(lVar4 + 0x28,uVar7);
    if (iVar8 < 0) goto LAB_1c0002c03;
    iVar8 = IoAcquireRemoveLockEx
                      (lVar4 + 8,*(undefined8 *)(*(longlong *)(lVar4 + 0xa8) + 0x10),"",1,0x20);
    if (iVar8 < 0) break;
    iVar8 = IoSetCompletionRoutineEx
                      (param_1,*(undefined8 *)(*(longlong *)(lVar4 + 0xa8) + 0x10),
                       OnReceiveVMBusMessage,param_1,1,1,1);
    if (iVar8 < 0) {
      if (g_TracingEnabled == '\0') {
        return iVar8;
      }
      pcVar9 = "VMBusHID: GetVMBusMessage: Unable to set completion routine: %x\n\n";
      goto LAB_1c0002bf5;
    }
    iVar8 = IofCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 8));
    if (iVar8 < 0) {
      if (g_TracingEnabled == '\0') {
        return iVar8;
      }
      pcVar9 = "VMBusHID: GetVMBusMessage: IoCallDriver Failed: %x\n\n";
      goto LAB_1c0002bf5;
    }
    LOCK();
    piVar2 = (int *)(*(longlong *)(lVar4 + 0xa8) + 0x20);
    iVar3 = *piVar2;
    *piVar2 = 2;
    UNLOCK();
    if (iVar3 != 3) {
      if (g_TracingEnabled != '\0') {
        DbgPrint("VMBusHID: GetVMBusMessage: IoCallDriver async return\n\n");
LAB_1c0002c03:
        if (g_TracingEnabled != '\0') {
          DbgPrint("VMBusHID: Exit GetVMBusMessage\n\n");
        }
      }
      return iVar8;
    }
    if (g_TracingEnabled != '\0') {
      DbgPrint("VMBusHID: GetVMBusMessage: IoCallDriver sync return with %x\n\n");
    }
  }
  if (g_TracingEnabled == '\0') {
    return iVar8;
  }
  pcVar9 = "VMBusHID: GetVMBusMessage: Unable to acquire remove lock: %x\n\n";
LAB_1c0002bf5:
  DbgPrint(pcVar9,iVar8);
  goto LAB_1c0002c03;
}



===== InitializeIoPackage @ 1c0002c44 =====

undefined8
InitializeIoPackage(longlong param_1,undefined8 param_2,char param_3,undefined4 param_4,
                   longlong param_5)

{
  longlong lVar1;
  char *pcVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter InitializeIoPackage\n\n");
  }
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 8);
  lVar1 = IoAllocateIrp(CONCAT71((int7)((ulonglong)lVar1 >> 8),*(undefined1 *)(lVar1 + 0x4c)),0);
  *(longlong *)(param_5 + 0x10) = lVar1;
  if (lVar1 == 0) {
    if (g_TracingEnabled != '\0') {
      pcVar2 = "VMBusHID: InitializeIoPackage: Unable to allocate an IRP.\n\n";
LAB_1c0002cbb:
      DbgPrint(pcVar2);
    }
  }
  else {
    lVar1 = *(longlong *)(lVar1 + 0xb8);
    *(undefined8 *)(lVar1 + -0x10) = param_2;
    *(longlong *)(lVar1 + -8) = param_1;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    lVar1 = *(longlong *)(*(longlong *)(param_5 + 0x10) + 0xb8);
    *(char *)(lVar1 + -0x48) = '\x04' - (param_3 != '\0');
    *(undefined4 *)(lVar1 + -0x40) = param_4;
    lVar1 = IoAllocateMdl(param_5 + 0x24,param_4,0,0,*(undefined8 *)(param_5 + 0x10));
    *(longlong *)(param_5 + 0x18) = lVar1;
    if (lVar1 != 0) {
      MmBuildMdlForNonPagedPool(lVar1);
      goto LAB_1c0002d43;
    }
    if (g_TracingEnabled != '\0') {
      pcVar2 = "VMBusHID: InitializeIoPackage: Unable to allocate a MDL.\n\n";
      goto LAB_1c0002cbb;
    }
  }
  uVar3 = 0xc000009a;
LAB_1c0002d43:
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Exit InitializeIoPackage\n\n");
  }
  return uVar3;
}



===== OnReceiveVMBusMessage @ 1c0002d90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 OnReceiveVMBusMessage(undefined8 param_1,longlong param_2,longlong param_3)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  uint *puVar5;
  char *pcVar6;
  bool bVar7;
  
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter OnReceiveVMBusMessage\n\n");
  }
  lVar2 = *(longlong *)(param_2 + 8);
  lVar3 = *(longlong *)(*(longlong *)(param_3 + 0x40) + 0x10);
  if ((*(byte *)(lVar2 + 10) & 5) == 0) {
    puVar5 = (uint *)MmMapLockedPagesSpecifyCache(lVar2,0,1,0,0,ExDefaultMdlProtection | 0x40000020)
    ;
  }
  else {
    puVar5 = *(uint **)(lVar2 + 0x18);
  }
  if (puVar5 == (uint *)0x0) {
    if (g_TracingEnabled != '\0') {
      DbgPrint("VMBusHID: OnReceiveVMBusMessage: Unable to retrieve payload.\n\n");
    }
    goto LAB_1c0002f08;
  }
  iVar4 = *(int *)(param_2 + 0x30);
  if (iVar4 < 0) {
    if (g_TracingEnabled != '\0') {
      pcVar6 = "VMBusHID: OnReceiveVMBusMessage: IRP Failed: %x\n\n";
LAB_1c0002e49:
      DbgPrint(pcVar6,iVar4);
    }
  }
  else if (*(longlong *)(param_2 + 0x38) == 0) {
    if (g_TracingEnabled != '\0') {
      pcVar6 = "VMBusHID: OnReceiveVMBusMessage: IRP zero length read.\n\n";
LAB_1c0002ed3:
      DbgPrint(pcVar6);
    }
  }
  else if (*(char *)(param_2 + 0x44) == '\0') {
    if ((*puVar5 < 5) &&
       (*(code **)(&InputMessageHandlers + (longlong)(int)*puVar5 * 8) != (code *)0x0)) {
      iVar4 = (**(code **)(&InputMessageHandlers + (longlong)(int)*puVar5 * 8))(lVar3);
      if ((iVar4 < 0) && (g_TracingEnabled != '\0')) {
        pcVar6 = "VMBusHID: OnReceiveVMBusMessage: Callback routine failed: %x\n\n";
        goto LAB_1c0002e49;
      }
    }
    else if (g_TracingEnabled != '\0') {
      pcVar6 = "VMBusHID: OnReceiveVMBusMessage: Invalid header type received\n\n";
      goto LAB_1c0002ed3;
    }
  }
  else if (g_TracingEnabled != '\0') {
    pcVar6 = "VMBusHID: OnReceiveVMBusMessage: IRP Cancelled\n\n";
    goto LAB_1c0002ed3;
  }
  piVar1 = (int *)(*(longlong *)(lVar3 + 0xa8) + 0x20);
  LOCK();
  bVar7 = *piVar1 == 1;
  if (bVar7) {
    *piVar1 = 3;
  }
  UNLOCK();
  if ((!bVar7) && (1 < *(int *)(lVar3 + 0x30) - 5U)) {
    GetVMBusMessage(param_3);
  }
LAB_1c0002f08:
  IoReleaseRemoveLockEx(lVar3 + 8,param_2,0x20);
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Exit OnReceiveVMBusMessage\n\n");
  }
  return 0xc0000016;
}



===== OnSentVMBusMessage @ 1c0002f60 =====

undefined8 OnSentVMBusMessage(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  bool bVar5;
  undefined1 uVar6;
  longlong lVar7;
  undefined8 uVar8;
  longlong *plVar9;
  
  plVar9 = (longlong *)0x0;
  bVar5 = false;
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter OnSentVMBusMessage\n\n");
  }
  lVar7 = *(longlong *)(param_2 + 8);
  lVar1 = *(longlong *)(*(longlong *)(param_3 + 0x40) + 0x10);
  if ((*(byte *)(lVar7 + 10) & 5) == 0) {
    lVar7 = MmMapLockedPagesSpecifyCache(lVar7,0,1,0,0,ExDefaultMdlProtection | 0x40000020);
  }
  else {
    lVar7 = *(longlong *)(lVar7 + 0x18);
  }
  if (lVar7 == 0) {
    if (g_TracingEnabled == '\0') goto LAB_1c00030ab;
    DbgPrint("VMBusHID: OnSentVMBusMessage: Unable to retrieve payload.\n\n");
  }
  else {
    plVar9 = (longlong *)(lVar7 + -0x24);
    uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x28);
    if (*(int *)(lVar1 + 0x30) - 5U < 2) {
      bVar5 = true;
    }
    else {
      lVar2 = *plVar9;
      if ((*(longlong **)(lVar2 + 8) != plVar9) ||
         (plVar3 = *(longlong **)(lVar7 + -0x1c), (longlong *)*plVar3 != plVar9)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3,uVar6);
        pcVar4 = (code *)swi(3);
        uVar8 = (*pcVar4)();
        return uVar8;
      }
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      bVar5 = false;
    }
    KeReleaseSpinLock(lVar1 + 0x28);
  }
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Exit OnSentVMBusMessage\n\n");
  }
  if ((plVar9 != (longlong *)0x0) && (!bVar5)) {
    if ((*(char *)(lVar1 + 0x71) == '\0') && (*(int *)(param_2 + 0x30) < 0)) {
      KeSetEvent(lVar1 + 0x40,0,0);
    }
    FreeIoPackage(plVar9);
  }
LAB_1c00030ab:
  IoReleaseRemoveLockEx(lVar1 + 8,param_2,0x20);
  return 0xc0000016;
}



===== SendVMBusMessage @ 1c00030f4 =====

int SendVMBusMessage(longlong param_1,void *param_2,uint param_3,undefined1 *param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  code *pcVar3;
  undefined1 uVar4;
  int iVar5;
  longlong *plVar6;
  char *pcVar7;
  longlong *plVar8;
  longlong lVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  undefined4 local_48;
  
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter SendVMBusMessage\n\n");
  }
  lVar1 = *(longlong *)(param_1 + 0x40);
  *param_4 = 0;
  lVar1 = *(longlong *)(lVar1 + 0x10);
  plVar6 = AllocateIoPackage(param_1,OnSentVMBusMessage,'\0',param_3);
  puVar11 = auStack_68;
  if (plVar6 == (longlong *)0x0) {
    iVar5 = -0x3fffff66;
    goto LAB_1c00032f2;
  }
  local_48 = 0x20;
  iVar5 = IoAcquireRemoveLockEx(lVar1 + 8,plVar6[2],"",1);
  puVar11 = auStack_68;
  if (iVar5 < 0) {
    if (g_TracingEnabled != '\0') {
      pcVar7 = "VMBusHID: SendVMBusMessage: Unable to acquire remove lock: %x\n\n";
      puVar11 = auStack_68;
LAB_1c000329a:
      *(undefined8 *)(puVar11 + -8) = 0x1c00032a3;
      DbgPrint(pcVar7,iVar5);
    }
  }
  else {
    memcpy((void *)((longlong)plVar6 + 0x24),param_2,(ulonglong)param_3);
    uVar4 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x28);
    puVar11 = auStack_68;
    puVar10 = auStack_68;
    if (*(int *)(lVar1 + 0x30) - 5U < 2) {
      iVar5 = -0x3fffffaa;
    }
    else {
      plVar8 = (longlong *)(lVar1 + 0xb0);
      lVar9 = *plVar8;
      if (*(longlong **)(lVar9 + 8) != plVar8) {
        plVar8 = (longlong *)0x3;
        pcVar3 = (code *)swi(0x29);
        uVar4 = (*pcVar3)();
        puVar10 = auStack_60;
      }
      *plVar6 = lVar9;
      plVar6[1] = (longlong)plVar8;
      *(longlong **)(lVar9 + 8) = plVar6;
      *plVar8 = (longlong)plVar6;
      puVar11 = puVar10;
    }
    *(undefined8 *)(puVar11 + -8) = 0x1c000321a;
    KeReleaseSpinLock(lVar1 + 0x28,uVar4);
    lVar9 = plVar6[2];
    if (iVar5 == -0x3fffffaa) {
      *(undefined8 *)(puVar11 + -8) = 0x1c0003239;
      IoReleaseRemoveLockEx(lVar1 + 8,lVar9,0x20);
      iVar5 = -0x3fffffaa;
      if (g_TracingEnabled != '\0') {
        *(undefined8 *)(puVar11 + -8) = 0x1c0003255;
        DbgPrint("VMBusHID: SendVMBusMessage: In Shutdown\n\n");
      }
    }
    else {
      puVar11[0x30] = 1;
      puVar11[0x28] = 1;
      puVar11[0x20] = 1;
      *(undefined8 *)(puVar11 + -8) = 0x1c000327f;
      iVar5 = IoSetCompletionRoutineEx(param_1,lVar9,OnSentVMBusMessage,param_1);
      if (-1 < iVar5) {
        lVar1 = plVar6[2];
        uVar2 = *(undefined8 *)(*(longlong *)(param_1 + 0x40) + 8);
        *(undefined8 *)(puVar11 + -8) = 0x1c00032c5;
        iVar5 = IofCallDriver(uVar2,lVar1);
        *param_4 = 1;
        if (iVar5 < 0) {
          if (g_TracingEnabled == '\0') {
            return iVar5;
          }
          *(undefined8 *)(puVar11 + -8) = 0x1c00032ed;
          DbgPrint("VMBusHID: SendVMBusMessage: IoCallDriver failed: %x\n\n",iVar5);
        }
        goto LAB_1c00032f2;
      }
      if (g_TracingEnabled != '\0') {
        pcVar7 = "VMBusHID: SendVMBusMessage: Unable to set completion routine: %x\n\n";
        goto LAB_1c000329a;
      }
    }
  }
  *(undefined8 *)(puVar11 + -8) = 0x1c00032b0;
  FreeIoPackage(plVar6);
LAB_1c00032f2:
  if (g_TracingEnabled != '\0') {
    *(undefined8 *)(puVar11 + -8) = 0x1c0003309;
    DbgPrint("VMBusHID: Exit SendVMBusMessage\n\n");
  }
  return iVar5;
}



===== _guard_check_icall @ 1c0003340 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0003358 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000337c =====

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



===== __cpu_features_init @ 1c00033f0 =====

/* WARNING: Removing unreachable block (ram,0x0001c000345a) */
/* WARNING: Removing unreachable block (ram,0x0001c0003409) */
/* WARNING: Removing unreachable block (ram,0x0001c00033fa) */

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



===== __security_check_cookie @ 1c00034c0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0003500 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0003530 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0003530. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0003560 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c00035c0 =====

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



===== memset @ 1c00038c0 =====

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



===== __memset_repmovs @ 1c0003a00 =====

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



===== __memset_query @ 1c0003a80 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0003b00 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0003c40 =====

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



===== __memset_spec_plain @ 1c0003cc0 =====

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



===== AddDevice @ 1c000a010 =====

int AddDevice(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  int iVar3;
  undefined8 *puVar4;
  
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter AddDevice\n");
  }
  plVar2 = *(longlong **)(*(longlong *)(param_2 + 0x40) + 0x10);
  *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) | 0x2000;
  memset(plVar2 + 1,0,0x678);
  *plVar2 = param_2;
  IoInitializeRemoveLockEx(plVar2 + 1,0x64684d56,0,100,0x20);
  KeInitializeEvent(plVar2 + 8,0,0);
  KeInitializeEvent(plVar2 + 0xb,0,0);
  plVar1 = plVar2 + 0x16;
  plVar2[0x17] = (longlong)plVar1;
  *plVar1 = (longlong)plVar1;
  KeInitializeSpinLock(plVar2 + 5);
  iVar3 = IrpQueueInitialize((longlong)(plVar2 + 0x18));
  if (-1 < iVar3) {
    iVar3 = IrpQueueInitialize((longlong)(plVar2 + 0x23));
    if (-1 < iVar3) {
      iVar3 = IrpQueueInitialize((longlong)(plVar2 + 0x2e));
      if (-1 < iVar3) {
        puVar4 = AllocateIoPackage(param_2,OnReceiveVMBusMessage,'\x01',0x240);
        plVar2[0x15] = (longlong)puVar4;
        if (puVar4 == (undefined8 *)0x0) {
          iVar3 = -0x3fffff66;
        }
        else {
          *(undefined4 *)(puVar4 + 4) = 2;
          *(undefined4 *)(plVar2 + 6) = 0;
          *(undefined4 *)((longlong)plVar2 + 0x34) = 0;
          *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) & 0xffffff7f;
        }
      }
    }
  }
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Exit AddDevice\n");
  }
  return iVar3;
}



===== DispatchPnP @ 1c000a180 =====

int DispatchPnP(longlong param_1,longlong param_2)

{
  longlong lVar1;
  char cVar2;
  longlong lVar3;
  undefined8 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 in_stack_ffffffffffffffb8;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter PnP\n");
  }
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  lVar1 = lVar3 + 8;
  iVar5 = IoAcquireRemoveLockEx(lVar1,param_2,"",1,CONCAT44(uVar6,0x20));
  if (iVar5 < 0) {
    if (g_TracingEnabled != '\0') {
      DbgPrint("VMBusHID: PnP: Failed to acquire remove lock: %x\n\n",iVar5);
    }
    *(int *)(param_2 + 0x30) = iVar5;
    IofCompleteRequest(param_2,0);
    return iVar5;
  }
  cVar2 = *(char *)(*(longlong *)(param_2 + 0xb8) + 1);
  if (cVar2 == '\0') {
    KeInitializeEvent(&local_28,0,0);
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
    iVar5 = IoSetCompletionRoutineEx(param_1,param_2,PnPStartComplete,&local_28,1,1,1);
    if (iVar5 < 0) {
      if (g_TracingEnabled != '\0') {
        DbgPrint("VMBusHID: DispatchPnP: Unable to set completion routine: %x\n\n",iVar5);
      }
    }
    else {
      iVar5 = IofCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 8),param_2);
      if (iVar5 == 0x103) {
        KeWaitForSingleObject(&local_28,0,0,0,0);
        iVar5 = *(int *)(param_2 + 0x30);
      }
      if ((-1 < iVar5) && (iVar5 = Startup(param_1), -1 < iVar5)) {
        *(undefined4 *)(lVar3 + 0x34) = *(undefined4 *)(lVar3 + 0x30);
        *(undefined4 *)(lVar3 + 0x30) = 1;
      }
    }
    *(int *)(param_2 + 0x30) = iVar5;
    IofCompleteRequest(param_2,0);
    IoReleaseRemoveLockEx(lVar1,param_2,0x20);
    if (g_TracingEnabled == '\0') {
      return iVar5;
    }
    DbgPrint("VMBusHID: Exit PnP StartDevice\n");
    return iVar5;
  }
  if (cVar2 == '\x01') {
    uVar6 = *(undefined4 *)(lVar3 + 0x30);
    *(undefined4 *)(lVar3 + 0x30) = 4;
LAB_1c000a347:
    *(undefined4 *)(lVar3 + 0x34) = uVar6;
  }
  else {
    if (cVar2 == '\x02') {
      *(undefined4 *)(lVar3 + 0x34) = *(undefined4 *)(lVar3 + 0x30);
      *(undefined4 *)(lVar3 + 0x30) = 6;
      BeginShutdown(lVar3);
      IoReleaseRemoveLockAndWaitEx(lVar1,param_2,0x20);
      *(undefined4 *)(param_2 + 0x30) = 0;
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      iVar5 = IofCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 8),param_2);
      CompleteShutdown(lVar3);
      if (g_TracingEnabled != '\0') {
        DbgPrint("VMBusHID: Exit PnP RemoveDevice\n");
      }
      return iVar5;
    }
    if (cVar2 != '\x03') {
      if (cVar2 == '\x04') {
        uVar6 = *(undefined4 *)(lVar3 + 0x30);
        *(undefined4 *)(lVar3 + 0x30) = 3;
      }
      else {
        if (cVar2 != '\x05') {
          if (cVar2 == '\x06') goto LAB_1c000a294;
          if (cVar2 != '\x17') {
            uVar6 = *(undefined4 *)(param_2 + 0x30);
            goto LAB_1c000a34c;
          }
          *(undefined4 *)(lVar3 + 0x34) = *(undefined4 *)(lVar3 + 0x30);
          *(undefined4 *)(lVar3 + 0x30) = 5;
          BeginShutdown(lVar3);
          goto LAB_1c000a34a;
        }
        uVar6 = *(undefined4 *)(lVar3 + 0x30);
        *(undefined4 *)(lVar3 + 0x30) = 2;
      }
      goto LAB_1c000a347;
    }
LAB_1c000a294:
    *(undefined4 *)(lVar3 + 0x30) = *(undefined4 *)(lVar3 + 0x34);
  }
LAB_1c000a34a:
  uVar6 = 0;
LAB_1c000a34c:
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  *(undefined4 *)(param_2 + 0x30) = uVar6;
  iVar5 = IofCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 8),param_2);
  IoReleaseRemoveLockEx(lVar1,param_2,0x20);
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Exit PnP\n");
  }
  return iVar5;
}



===== Unload @ 1c000a510 =====

void Unload(void)

{
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter Unload\n");
  }
  return;
}



===== DoProtocolNegotiation @ 1c000a53c =====

int DoProtocolNegotiation(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  undefined1 local_res8 [8];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_res8[0] = 0;
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter DoProtocolNego\n\n");
  }
  local_18 = 0;
  local_14 = 4;
  local_10 = 0x20000;
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10);
  *(undefined1 *)(lVar1 + 0x71) = 0;
  iVar2 = SendVMBusMessage(param_1,&local_18,0xc,local_res8);
  if ((-1 < iVar2) && (iVar2 = GetVMBusMessage(param_1), -1 < iVar2)) {
    iVar2 = KeWaitForSingleObject(lVar1 + 0x40,0,0,0,0);
    if (iVar2 < 0) {
      if (g_TracingEnabled == '\0') {
        return iVar2;
      }
      DbgPrint("VMBusHID: Failed waiting for protocol negotiation to complete: %x\n\n",iVar2);
    }
    else if (*(char *)(lVar1 + 0x71) == '\0') {
      if (g_TracingEnabled != '\0') {
        DbgPrint("VMBusHID: Protocol negotiation failed\n\n");
      }
      iVar2 = -0x3fffffff;
    }
  }
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Exit DoProtocolNego\n\n");
  }
  return iVar2;
}



===== WaitForDeviceInformation @ 1c000a668 =====

int WaitForDeviceInformation(longlong param_1)

{
  int iVar1;
  
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter WaitForDeviceInfo\n\n");
  }
  iVar1 = KeWaitForSingleObject(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10) + 0x58,0,0,0,0);
  if (iVar1 < 0) {
    if (g_TracingEnabled == '\0') {
      return iVar1;
    }
    DbgPrint("VMBusHID: Failed waiting for device information packet: %x\n\n",iVar1);
  }
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Exit WaitForDeviceInfo\n\n");
  }
  return iVar1;
}



===== IrpQueueInitialize @ 1c000a704 =====

int IrpQueueInitialize(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Enter IrpQueueInitialize\n\n");
  }
  if (param_1 == 0) {
    if (g_TracingEnabled != '\0') {
      DbgPrint("VMBusHID: IrpQueueInitialize: NULL pointer passed in.\n\n");
    }
    iVar2 = -0x3ffffff3;
  }
  else {
    KeInitializeSpinLock(param_1 + 0x50);
    lVar1 = param_1 + 0x40;
    *(longlong *)(param_1 + 0x48) = lVar1;
    *(longlong *)lVar1 = lVar1;
    iVar2 = IoCsqInitialize(param_1,CsqInsertIrp,CsqRemoveIrp,CsqPeekNextIrp,CsqAcquireLock,
                            CsqReleaseLock,CsqCompleteCanceledIrp);
    if (iVar2 < 0) {
      if (g_TracingEnabled == '\0') {
        return iVar2;
      }
      DbgPrint("VMBusHID: IrpQueueInitialize: Error while initializing CSQ: %x\n\n",iVar2);
    }
  }
  if (g_TracingEnabled != '\0') {
    DbgPrint("VMBusHID: Exit IrpQueueInitialize\n\n");
  }
  return iVar2;
}



===== entry @ 1c000b010 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c000b044 =====

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



===== DriverEntry @ 1c000b078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int DriverEntry(longlong param_1,undefined8 param_2)

{
  int iVar1;
  undefined1 auStack_188 [32];
  ulonglong local_168;
  longlong local_160;
  undefined8 local_158;
  undefined4 local_150;
  undefined1 local_14c;
  undefined2 local_14b;
  undefined1 local_149;
  undefined4 local_148;
  uint local_144;
  uint local_140;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_188;
  local_168 = (ulonglong)(uint)local_168;
  memset(&local_144,0,0x110);
  local_148 = 0x114;
  iVar1 = RtlGetVersion(&local_148);
  if ((-1 < iVar1) && ((6 < local_144 || ((local_144 == 6 && (1 < local_140)))))) {
    ExDefaultMdlProtection = 0x40000000;
  }
  *(code **)(param_1 + 0x68) = Unload;
  *(code **)(*(longlong *)(param_1 + 0x30) + 8) = AddDevice;
  *(code **)(param_1 + 0xe8) = DispatchInternalIoctl;
  local_168 = 1;
  *(code **)(param_1 + 0x128) = DispatchClose;
  *(code **)(param_1 + 0x148) = DispatchPnP;
  *(code **)(param_1 + 0x120) = DispatchPower;
  *(code **)(param_1 + 0x70) = DispatchClose;
  *(code **)(param_1 + 0x80) = DispatchClose;
  local_14b = 0;
  local_149 = 0;
  local_150 = 0x680;
  local_14c = 0;
  local_160 = param_1;
  local_158 = param_2;
  iVar1 = HidRegisterMinidriver(&local_168);
  if ((iVar1 < 0) && (g_TracingEnabled != '\0')) {
    DbgPrint("VMBusHID: DriverEntry: Register failed with %x\n\n",iVar1);
  }
  return iVar1;
}


