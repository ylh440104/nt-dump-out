
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
  *param_6 = PTR_DAT_140014008;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_140014008;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_140014020,&local_18,0,0,param_5,param_6);
  return;
}



===== _tlgCreate1Sz_char @ 1400010b8 =====

void _tlgCreate1Sz_char(longlong *param_1,char *param_2)

{
  int iVar1;
  longlong lVar2;
  
  if (param_2 == (char *)0x0) {
    param_2 = "";
    iVar1 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_2[lVar2] != '\0');
    iVar1 = (int)lVar2 + 1;
  }
  *(undefined4 *)((longlong)param_1 + 0xc) = 0;
  *param_1 = (longlong)param_2;
  *(int *)(param_1 + 1) = iVar1;
  return;
}



===== _tlgCreate1Sz_wchar_t @ 1400010ec =====

void _tlgCreate1Sz_wchar_t(longlong *param_1,wchar_t *param_2)

{
  int iVar1;
  longlong lVar2;
  
  if (param_2 == (wchar_t *)0x0) {
    param_2 = L"";
    iVar1 = 2;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_2[lVar2] != L'\0');
    iVar1 = (int)lVar2 * 2 + 2;
  }
  *param_1 = (longlong)param_2;
  *(int *)(param_1 + 1) = iVar1;
  *(undefined4 *)((longlong)param_1 + 0xc) = 0;
  return;
}



===== USBPRINT_Write @ 140001130 =====

ulonglong USBPRINT_Write(longlong param_1,wchar_t *param_2,ulonglong param_3,undefined8 param_4)

{
  undefined4 uVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined4 *puVar5;
  undefined8 *puVar6;
  wchar_t *pwVar7;
  uint uVar8;
  
  pwVar7 = param_2;
  uVar4 = USBPRINT_CheckIncrementIoCount(param_1,param_2,param_3,param_4);
  if ((int)uVar4 < 0) {
    *(int *)(param_2 + 0x18) = (int)uVar4;
    param_2[0x1c] = L'\0';
    param_2[0x1d] = L'\0';
    param_2[0x1e] = L'\0';
    param_2[0x1f] = L'\0';
    IofCompleteRequest(param_2,0);
    WriteDbgTraceWarning
              ("USBPRINT_Write",L"USBPRINT_Write returning 0x%x",uVar4 & 0xffffffff,param_4);
    return uVar4 & 0xffffffff;
  }
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar3 = *(longlong *)
           (lVar2 + 0x598 +
           *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0x5c) + 0x30) + 0x20) * 8);
  if (lVar3 == 0) {
    pwVar7 = L"USBPRINT.SYS: failure because pipe is bad";
    WriteDbgTraceWarning
              ("USBPRINT_Write",L"USBPRINT.SYS: failure because pipe is bad",param_3,param_4);
    uVar8 = 0xc0000008;
  }
  else {
    uVar8 = *(uint *)(lVar3 + 4);
    param_3 = (ulonglong)uVar8;
    if ((uVar8 == 2) || (uVar8 == 3)) {
      if (*(longlong *)(param_2 + 4) != 0) {
        uVar1 = *(undefined4 *)(*(longlong *)(param_2 + 4) + 0x28);
        pwVar7 = (wchar_t *)0x80;
        param_3 = 0x50425355;
        puVar5 = (undefined4 *)ExAllocatePool2(0x40);
        if (puVar5 != (undefined4 *)0x0) {
          memset(puVar5 + 1,0,0x7c);
          *puVar5 = 0x90080;
          param_3 = 0x50425355;
          *(undefined8 *)(puVar5 + 6) = *(undefined8 *)(lVar3 + 8);
          puVar5[8] = 2;
          pwVar7 = (wchar_t *)0x18;
          *(undefined8 *)(puVar5 + 0xe) = 0;
          *(undefined8 *)(puVar5 + 0xc) = *(undefined8 *)(param_2 + 4);
          puVar5[9] = uVar1;
          puVar6 = (undefined8 *)ExAllocatePool2(0x40);
          if (puVar6 != (undefined8 *)0x0) {
            *puVar6 = puVar5;
            puVar6[2] = param_1;
            *(undefined1 *)(puVar6 + 1) = 1;
            lVar3 = *(longlong *)(param_2 + 0x5c);
            *(undefined1 *)(lVar3 + -0x48) = 0xf;
            *(undefined4 **)(lVar3 + -0x40) = puVar5;
            *(undefined4 *)(lVar3 + -0x30) = 0x220003;
            lVar3 = *(longlong *)(param_2 + 0x5c);
            *(code **)(lVar3 + -0x10) = USBPRINT_AsyncReadWrite_Complete;
            *(undefined8 **)(lVar3 + -8) = puVar6;
            *(undefined1 *)(lVar3 + -0x45) = 0xe0;
            *(byte *)(*(longlong *)(param_2 + 0x5c) + 3) =
                 *(byte *)(*(longlong *)(param_2 + 0x5c) + 3) | 1;
            IofCallDriver(*(undefined8 *)(lVar2 + 8),param_2);
            uVar8 = 0x103;
            goto LAB_140001351;
          }
          ExFreePool(puVar5);
        }
      }
      uVar8 = 0xc000009a;
    }
    else {
      pwVar7 = L"USBPRINT.SYS: Invalid PipeType 0x%d";
      WriteDbgTraceWarning("USBPRINT_Write",L"USBPRINT.SYS: Invalid PipeType 0x%d",param_3,param_4);
      uVar8 = 0xc000000d;
    }
  }
  USBPRINT_DecrementIoCount(param_1,pwVar7,param_3,param_4);
  *(uint *)(param_2 + 0x18) = uVar8;
  param_2[0x1c] = L'\0';
  param_2[0x1d] = L'\0';
  param_2[0x1e] = L'\0';
  param_2[0x1f] = L'\0';
  IofCompleteRequest(param_2,0);
  WriteDbgTraceInfo("USBPRINT_Write",L"USBPRINT_Write failed 0x%x",(ulonglong)uVar8,param_4);
LAB_140001351:
  return (ulonglong)uVar8;
}



===== USBPRINT_Read @ 140001380 =====

ulonglong USBPRINT_Read(longlong param_1,wchar_t *param_2,ulonglong param_3,undefined8 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined4 *puVar6;
  undefined8 *puVar7;
  wchar_t *pwVar8;
  
  pwVar8 = param_2;
  uVar5 = USBPRINT_CheckIncrementIoCount(param_1,param_2,param_3,param_4);
  if ((int)uVar5 < 0) {
    *(int *)(param_2 + 0x18) = (int)uVar5;
    param_2[0x1c] = L'\0';
    param_2[0x1d] = L'\0';
    param_2[0x1e] = L'\0';
    param_2[0x1f] = L'\0';
    IofCompleteRequest(param_2,0);
    WriteDbgTraceWarning("USBPRINT_Read",L"USBPRINT_Read returning 0x%x",uVar5 & 0xffffffff,param_4)
    ;
    return uVar5 & 0xffffffff;
  }
  lVar3 = *(longlong *)(param_1 + 0x40);
  lVar4 = *(longlong *)
           (lVar3 + 0x5a8 +
           *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0x5c) + 0x30) + 0x20) * 8);
  if (lVar4 == 0) {
    uVar5 = 0xc0000008;
  }
  else {
    uVar1 = *(uint *)(lVar4 + 4);
    param_3 = (ulonglong)uVar1;
    if ((uVar1 == 2) || (uVar1 == 3)) {
      if (*(longlong *)(param_2 + 4) != 0) {
        uVar2 = *(undefined4 *)(*(longlong *)(param_2 + 4) + 0x28);
        pwVar8 = (wchar_t *)0x80;
        param_3 = 0x50425355;
        puVar6 = (undefined4 *)ExAllocatePool2(0x40);
        if (puVar6 != (undefined4 *)0x0) {
          memset(puVar6 + 1,0,0x7c);
          *puVar6 = 0x90080;
          param_3 = 0x50425355;
          *(undefined8 *)(puVar6 + 6) = *(undefined8 *)(lVar4 + 8);
          puVar6[8] = 3;
          pwVar8 = (wchar_t *)0x18;
          *(undefined8 *)(puVar6 + 0xe) = 0;
          *(undefined8 *)(puVar6 + 0xc) = *(undefined8 *)(param_2 + 4);
          puVar6[9] = uVar2;
          puVar7 = (undefined8 *)ExAllocatePool2(0x40);
          if (puVar7 != (undefined8 *)0x0) {
            *puVar7 = puVar6;
            puVar7[2] = param_1;
            *(undefined1 *)(puVar7 + 1) = 0;
            lVar4 = *(longlong *)(param_2 + 0x5c);
            *(undefined1 *)(lVar4 + -0x48) = 0xf;
            *(undefined4 **)(lVar4 + -0x40) = puVar6;
            *(undefined4 *)(lVar4 + -0x30) = 0x220003;
            lVar4 = *(longlong *)(param_2 + 0x5c);
            *(code **)(lVar4 + -0x10) = USBPRINT_AsyncReadWrite_Complete;
            *(undefined8 **)(lVar4 + -8) = puVar7;
            *(undefined1 *)(lVar4 + -0x45) = 0xe0;
            *(byte *)(*(longlong *)(param_2 + 0x5c) + 3) =
                 *(byte *)(*(longlong *)(param_2 + 0x5c) + 3) | 1;
            IofCallDriver(*(undefined8 *)(lVar3 + 8),param_2);
            return 0x103;
          }
          ExFreePool(puVar6);
        }
      }
      uVar5 = 0xc000009a;
    }
    else {
      pwVar8 = L"USBPRINT.SYS: Invalid PipeType 0x%d";
      uVar5 = 0xc000000d;
      WriteDbgTraceWarning("USBPRINT_Read",L"USBPRINT.SYS: Invalid PipeType 0x%d",param_3,param_4);
    }
  }
  USBPRINT_DecrementIoCount(param_1,pwVar8,param_3,param_4);
  *(int *)(param_2 + 0x18) = (int)uVar5;
  param_2[0x1c] = L'\0';
  param_2[0x1d] = L'\0';
  param_2[0x1e] = L'\0';
  param_2[0x1f] = L'\0';
  IofCompleteRequest(param_2,0);
  WriteDbgTraceWarning("USBPRINT_Read",L"USBPRINT_Read failed 0x%x",uVar5,param_4);
  return uVar5;
}



===== USBPRINT_CheckIncrementIoCount @ 1400015d0 =====

undefined8
USBPRINT_CheckIncrementIoCount
          (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  ulonglong uVar4;
  bool bVar5;
  
  pcVar3 = *(char **)(param_1 + 0x40);
  if (*(int *)(pcVar3 + 0x42c) != 0) {
    return 0x80000011;
  }
  if (*pcVar3 == '\x01') {
    return 0xc00000bb;
  }
  if (pcVar3[0x564] == '\0') {
    return 0xc0000056;
  }
  if (*pcVar3 == '\0') {
    LOCK();
    piVar1 = (int *)(pcVar3 + 0x560);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    if (iVar2 == 0) {
      KeClearEvent();
    }
  }
  uVar4 = Feature_3186517304__private_IsEnabledDeviceUsageNoInline();
  if ((char)uVar4 != '\0') {
    LOCK();
    bVar5 = *(int *)(pcVar3 + 0x42c) == 0;
    if (bVar5) {
      *(int *)(pcVar3 + 0x42c) = 0;
    }
    UNLOCK();
    if (!bVar5) {
      USBPRINT_DecrementIoCount(param_1,param_2,param_3,param_4);
      return 0x80000011;
    }
  }
  return 0;
}



===== USBPRINT_ProcessPowerIrp @ 140001690 =====

uint USBPRINT_ProcessPowerIrp
               (longlong param_1,longlong param_2,ulonglong param_3,undefined *param_4)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  longlong lVar5;
  undefined8 *puVar6;
  bool bVar7;
  uint uVar8;
  longlong lVar9;
  code *pcVar10;
  
  pcVar4 = *(char **)(param_1 + 0x40);
  if (*pcVar4 != '\0') {
    uVar8 = USBPRINT_ProcessChildPowerIrp(param_1,param_2,param_3,param_4);
    pcVar10 = (code *)param_4;
    goto LAB_1400017ac;
  }
  uVar8 = 0;
  lVar5 = *(longlong *)(param_2 + 0xb8);
  bVar7 = false;
  LOCK();
  piVar2 = (int *)(pcVar4 + 0x560);
  iVar3 = *piVar2;
  *piVar2 = *piVar2 + 1;
  UNLOCK();
  lVar9 = param_2;
  pcVar10 = (code *)param_4;
  if (iVar3 == 0) {
    KeClearEvent(pcVar4 + 0x548);
    pcVar10 = (code *)param_4;
  }
  if (*(byte *)(lVar5 + 1) == 2) {
    if (*(int *)(lVar5 + 0x10) == 0) {
      WriteDbgTraceInfo("USBPRINT_ProcessFdoPowerIrp",
                        L"USBPRINT.SYS: Set Power, SystemPowerState (%d)",
                        (ulonglong)*(uint *)(lVar5 + 0x18),pcVar10);
      param_3 = (ulonglong)*(uint *)(pcVar4 + (longlong)*(int *)(lVar5 + 0x18) * 4 + 0x508);
      if (*(uint *)(pcVar4 + (longlong)*(int *)(lVar5 + 0x18) * 4 + 0x508) !=
          *(uint *)(pcVar4 + 0x4e0)) {
        *(longlong *)(pcVar4 + 0x540) = param_2;
        pcVar10 = USBPRINT_PoRequestCompletion;
        pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
        *pbVar1 = *pbVar1 | 1;
        PoRequestPowerIrp(*(undefined8 *)(pcVar4 + 0x10),2,param_3,USBPRINT_PoRequestCompletion,
                          param_1,0);
        uVar8 = 0x103;
        goto LAB_1400017ac;
      }
      goto LAB_14000183c;
    }
    if (*(int *)(lVar5 + 0x10) == 1) {
      uVar8 = *(uint *)(lVar5 + 0x18);
      lVar5 = *(longlong *)(param_1 + 0x40);
      if (uVar8 == 1) {
        WriteDbgTraceInfo("USBPRINT_SetDevicePowerState",L"USBPRINT.SYS:  PowerDeviceD0 (ON)",
                          param_3,pcVar10);
        bVar7 = true;
      }
      else if ((uVar8 == 2) || (uVar8 == 3)) {
        WriteDbgTraceInfo("USBPRINT_SetDevicePowerState",
                          L"USBPRINT.SYS:  PowerDeviceD1/D2 (SUSPEND)",param_3,pcVar10);
        *(uint *)(lVar5 + 0x4e0) = uVar8;
      }
      else if (uVar8 == 4) {
        WriteDbgTraceInfo("USBPRINT_SetDevicePowerState",L"USBPRINT.SYS:  PowerDeviceD3 (OFF)",
                          param_3,pcVar10);
        *(undefined4 *)(lVar5 + 0x4e0) = 4;
      }
      else {
        param_3 = (ulonglong)uVar8;
        WriteDbgTraceInfo("USBPRINT_SetDevicePowerState",L"USBPRINT.SYS:  Bogus DeviceState = %x",
                          param_3,pcVar10);
      }
      PoStartNextPowerIrp(param_2);
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
      if (bVar7) {
        lVar5 = *(longlong *)(param_2 + 0xb8);
        *(code **)(lVar5 + -0x10) = USBPRINT_PowerIrp_Complete;
        *(longlong *)(lVar5 + -8) = param_1;
        *(undefined1 *)(lVar5 + -0x45) = 0xe0;
      }
      uVar8 = PoCallDriver(*(undefined8 *)(pcVar4 + 8));
      lVar9 = param_2;
      if (bVar7) goto LAB_1400017ac;
    }
  }
  else {
    param_3 = (ulonglong)*(byte *)(lVar5 + 1);
    WriteDbgTraceWarning
              ("USBPRINT_ProcessFdoPowerIrp",L"USBPRINT.SYS:  UNKNOWN POWER MESSAGE (%x)",param_3,
               pcVar10);
LAB_14000183c:
    PoStartNextPowerIrp(param_2);
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
    uVar8 = PoCallDriver(*(undefined8 *)(pcVar4 + 8));
    lVar9 = param_2;
  }
  USBPRINT_DecrementIoCount(param_1,lVar9,param_3,pcVar10);
LAB_1400017ac:
  if ((int)uVar8 < 0) {
    WriteDbgTraceInfo("USBPRINT_ProcessPowerIrp",L"USBPRINT_ProcessPowerIrp returning 0x%x",
                      (ulonglong)uVar8,pcVar10);
  }
  return uVar8;
}



===== USBPRINT_DecrementIoCount @ 140001960 =====

int USBPRINT_DecrementIoCount
              (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  
  pcVar3 = *(char **)(param_1 + 0x40);
  if (*pcVar3 != '\0') {
    return 0;
  }
  LOCK();
  piVar1 = (int *)(pcVar3 + 0x560);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 + -1 == 0) {
    if (*(int *)(pcVar3 + 0x5bc) == 0) {
      USBPRINT_FdoSubmitIdleRequestIrp(param_1,param_2,param_3,param_4);
    }
    KeSetEvent(pcVar3 + 0x548,1);
  }
  return iVar2 + -1;
}



===== WriteDbgTraceInfo @ 1400019d0 =====

void WriteDbgTraceInfo(char *param_1,wchar_t *param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res18 = param_3;
  local_res20 = param_4;
  cVar1 = KeGetCurrentIrql();
  if ((cVar1 == '\0') && (4 < DAT_140014000)) {
    DbgTraceWorker(1,param_1,param_2,(va_list)&local_res18);
  }
  return;
}



===== USBPRINT_CallUSBD @ 140001a30 =====

uint USBPRINT_CallUSBD(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeInitializeEvent(&local_28,0,0);
  lVar5 = IoAllocateIrp(*(undefined1 *)(*(longlong *)(lVar1 + 8) + 0x4c),0);
  if (lVar5 == 0) {
    uVar3 = 0xc000009a;
  }
  else {
    lVar2 = *(longlong *)(lVar5 + 0xb8);
    *(undefined1 *)(lVar2 + -0x48) = 0xf;
    *(undefined4 *)(lVar2 + -0x30) = 0x220003;
    *(undefined8 *)(lVar2 + -0x40) = param_2;
    lVar2 = *(longlong *)(lVar5 + 0xb8);
    *(code **)(lVar2 + -0x10) = USBPRINT_DeferIrpCompletion;
    *(undefined8 **)(lVar2 + -8) = &local_28;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    uVar3 = IofCallDriver(*(undefined8 *)(lVar1 + 8),lVar5);
    if (uVar3 == 0x103) {
      param_4 = 0;
      iVar4 = KeWaitForSingleObject(&local_28,5,0,0,param_3);
      if (iVar4 == 0x102) {
        WriteDbgTraceInfo("USBPRINT_CallUSBD",L"Call_USBD: Cancelling IRP %X because of timeout",
                          lVar5,param_4);
        IoCancelIrp(lVar5);
        param_4 = 0;
        KeWaitForSingleObject(&local_28,5,0,0,0);
      }
      uVar3 = *(uint *)(lVar5 + 0x30);
    }
    IoFreeIrp(lVar5);
    if (uVar3 != 0) {
      WriteDbgTraceInfo("USBPRINT_CallUSBD",L"USBPRINT.SYS: exit USBPRINT_CallUSBD (%x)",
                        (ulonglong)uVar3,param_4);
    }
  }
  return uVar3;
}



===== IsEnabled @ 140001bb0 =====

undefined8 IsEnabled(undefined8 param_1,byte param_2)

{
  if (param_2 < DAT_140014000) {
    return 1;
  }
  return 0;
}



===== ParPnpGetId @ 140001bd0 =====

ulonglong ParPnpGetId(char *param_1,int param_2,char *param_3,byte *param_4)

{
  ushort uVar1;
  int iVar2;
  ulonglong uVar3;
  byte *_Dst;
  longlong lVar4;
  wchar_t *pwVar5;
  ulonglong uVar6;
  ushort uVar7;
  undefined8 uVar8;
  wchar_t *pwVar9;
  char *pcVar10;
  longlong lVar11;
  undefined4 local_res20;
  byte *local_58;
  byte *local_50;
  longlong local_48 [3];
  wchar_t local_30 [4];
  
  local_res20._2_2_ = (ushort)((ulonglong)param_4 >> 0x10);
  local_res20 = (uint)local_res20._2_2_ << 0x10;
  local_50 = (byte *)0x0;
  local_48[0] = 0;
  local_30[0] = L'\0';
  local_30[1] = L'\0';
  local_30[2] = L'\0';
  local_30[3] = L'\0';
  local_48[1] = 0;
  local_58 = (byte *)0x0;
  local_48[2] = 0;
  memset(param_3,0,0x400);
  iVar2 = strncmp(param_1,"UnknownPrinter",0xf);
  if (iVar2 == 0) {
    uVar3 = RtlStringCbPrintfA(param_3,0x400,"%.20s",param_1);
    return uVar3;
  }
  uVar8 = 0x50425355;
  _Dst = (byte *)ExAllocatePool2(0x40);
  if (_Dst == (byte *)0x0) {
    WriteDbgTraceWarning
              ("ParPnpGetId",L"USBPRINT.SYS: Memory Allocation failed in ParPnpGetId",uVar8,param_4)
    ;
    return 0xc00000a0;
  }
  uVar8 = 0x400;
  memset(_Dst,0,0x400);
  lVar11 = -1;
  lVar4 = -1;
  do {
    lVar4 = lVar4 + 1;
  } while (param_1[lVar4] != '\0');
  iVar2 = (int)lVar4 + 1;
  if (0x400 < iVar2) {
    WriteDbgTraceWarning
              ("ParPnpGetId",L"USBPRINT.SYS: Invalid length 1284 Id - ParPnpGetId",uVar8,param_4);
    uVar6 = 0xc0000004;
    goto LAB_140001eb7;
  }
  memmove(_Dst,param_1,(longlong)iVar2);
  if (param_2 == 0) {
    pwVar9 = (wchar_t *)(local_48 + 3);
    ParPnpFindDeviceIdKeys
              (&local_50,local_48,(undefined8 *)pwVar9,local_48 + 2,local_48 + 1,&local_58,
               (char *)_Dst);
    param_4 = local_50;
    if ((local_50 == (byte *)0x0) || (local_48[0] == 0)) {
      pwVar5 = L"USBPRINT.SYS:ParPnpGetId:BusQueryDeviceID: STATUS_NOT_FOUND for MFG or MDL";
LAB_140001ea6:
      uVar6 = 0xc0000225;
    }
    else {
      pcVar10 = "%s%s";
      uVar3 = RtlStringCbPrintfA(param_3,0x400,"%s%s",local_50);
      uVar6 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) goto LAB_140001eb7;
      pwVar5 = L"USBPRINT.SYS:ParPnpGetId:BusQueryDeviceID: CID too long";
      pwVar9 = (wchar_t *)pcVar10;
    }
  }
  else if (param_2 == 1) {
    lVar4 = -1;
    do {
      lVar4 = lVar4 + 1;
    } while (_Dst[lVar4] != 0);
    GetCheckSum(_Dst,(ushort)lVar4,(ushort *)&local_res20);
    pcVar10 = "%.20s%04X";
    param_4 = _Dst;
    uVar3 = RtlStringCbPrintfA(param_3,0x400,"%.20s%04X",_Dst);
    uVar6 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
LAB_140001d47:
      do {
        lVar11 = lVar11 + 1;
        uVar1 = 0;
      } while (param_3[lVar11] != '\0');
      while ((pcVar10 = param_3, pcVar10 != (char *)0x0 &&
             (uVar7 = uVar1 + 1, uVar1 < (ushort)lVar11))) {
        param_3 = pcVar10 + 1;
        uVar1 = uVar7;
        if (*pcVar10 == ' ') {
          *pcVar10 = '_';
        }
      }
      goto LAB_140001eb7;
    }
    pwVar5 = L"USBPRINT.SYS:ParPnpGetId:BusQueryHardwareIDs: CID too long";
    pwVar9 = (wchar_t *)pcVar10;
  }
  else if (param_2 == 2) {
    pwVar9 = (wchar_t *)(local_48 + 3);
    ParPnpFindDeviceIdKeys
              (&local_50,local_48,(undefined8 *)pwVar9,local_48 + 2,local_48 + 1,&local_58,
               (char *)_Dst);
    param_4 = local_58;
    if (local_58 == (byte *)0x0) {
      pwVar5 = 
      L"USBPRINT.SYS:USBPRINT.SYS:ParPnpGetId:BusQueryCompatibleIDs: STATUS_NOT_FOUND for CID";
      goto LAB_140001ea6;
    }
    pcVar10 = "%s";
    uVar3 = RtlStringCbPrintfA(param_3,0x400,"%s",local_58);
    uVar6 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) goto LAB_140001eb7;
    pwVar5 = L"USBPRINT.SYS:ParPnpGetId:BusQueryCompatibleIDs: CID too long";
    pwVar9 = (wchar_t *)pcVar10;
  }
  else {
    pwVar9 = L"";
    uVar3 = RtlStringCbPrintfA(param_3,0x400,(char *)L"",param_4);
    uVar6 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      if (param_2 == 2) goto LAB_140001eb7;
      goto LAB_140001d47;
    }
    pwVar5 = L"USBPRINT.SYS:ParPnpGetId:default: CID too long";
  }
  WriteDbgTraceWarning("ParPnpGetId",pwVar5,pwVar9,param_4);
LAB_140001eb7:
  ExFreePool(_Dst);
  return uVar6;
}



===== ParPnpFindDeviceIdKeys @ 140001ef0 =====

void ParPnpFindDeviceIdKeys
               (undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
               undefined8 *param_5,undefined8 *param_6,char *param_7)

{
  char cVar1;
  short sVar2;
  longlong lVar3;
  ulonglong uVar4;
  char *pcVar5;
  
  do {
    while( true ) {
      if (param_7 == (char *)0x0) {
        return;
      }
      cVar1 = *param_7;
      while (cVar1 == ' ') {
        param_7 = param_7 + 1;
        cVar1 = *param_7;
      }
      pcVar5 = param_7;
      while( true ) {
        if (*pcVar5 == '\0') {
          return;
        }
        if (*pcVar5 == ':') break;
        pcVar5 = pcVar5 + 1;
      }
      if (pcVar5 == (char *)0x0) {
        return;
      }
      cVar1 = *param_7;
      pcVar5 = pcVar5 + 1;
      sVar2 = (short)pcVar5 - (short)param_7;
      if (cVar1 != 'C') break;
      lVar3 = RtlCompareMemory(param_7,"CLASS",sVar2);
      if ((lVar3 == 5) || (lVar3 = RtlCompareMemory(param_7,"CLS",sVar2), lVar3 == 3)) {
        *param_3 = pcVar5;
        if (pcVar5 == (char *)0x0) {
          return;
        }
        while( true ) {
          if (*pcVar5 == '\0') {
            return;
          }
          param_7 = pcVar5 + 1;
          if (*pcVar5 == ';') break;
          pcVar5 = param_7;
        }
      }
      else {
        uVar4 = RtlCompareMemory(param_7,"COMPATIBLEID",sVar2);
        if ((uVar4 < 6) && (lVar3 = RtlCompareMemory(param_7,"CID",sVar2), lVar3 != 3)) {
          if (pcVar5 == (char *)0x0) {
            return;
          }
          while( true ) {
            if (*pcVar5 == '\0') {
              return;
            }
            param_7 = pcVar5 + 1;
            if (*pcVar5 == ';') break;
            pcVar5 = param_7;
          }
        }
        else {
          *param_6 = pcVar5;
          if (pcVar5 == (char *)0x0) {
            return;
          }
          while( true ) {
            if (*pcVar5 == '\0') {
              return;
            }
            param_7 = pcVar5 + 1;
            if (*pcVar5 == ';') break;
            pcVar5 = param_7;
          }
        }
      }
LAB_14000201a:
      *pcVar5 = '\0';
    }
    if (cVar1 == 'M') {
      uVar4 = RtlCompareMemory(param_7,"MANUFACTURER",sVar2);
      if ((5 < uVar4) || (lVar3 = RtlCompareMemory(param_7,"MFG",sVar2), lVar3 == 3)) {
        *param_1 = pcVar5;
        if (pcVar5 == (char *)0x0) {
          return;
        }
        while( true ) {
          if (*pcVar5 == '\0') {
            return;
          }
          param_7 = pcVar5 + 1;
          if (*pcVar5 == ';') break;
          pcVar5 = param_7;
        }
        goto LAB_14000201a;
      }
      lVar3 = RtlCompareMemory(param_7,"MODEL",sVar2);
      if ((lVar3 == 5) || (lVar3 = RtlCompareMemory(param_7,"MDL",sVar2), lVar3 == 3)) {
        *param_2 = pcVar5;
      }
    }
    else if (cVar1 == 'D') {
      lVar3 = RtlCompareMemory(param_7,"DESCRIPTION",sVar2);
      if ((lVar3 == 0xb) || (lVar3 = RtlCompareMemory(param_7,"DES",sVar2), lVar3 == 3)) {
        *param_4 = pcVar5;
      }
    }
    else {
      if (cVar1 != 'A') {
        if (pcVar5 == (char *)0x0) {
          return;
        }
        while( true ) {
          if (*pcVar5 == '\0') {
            return;
          }
          param_7 = pcVar5 + 1;
          if (*pcVar5 == ';') break;
          pcVar5 = param_7;
        }
        goto LAB_14000201a;
      }
      lVar3 = RtlCompareMemory(param_7,"AUTOMATICID",sVar2);
      if ((lVar3 == 0xb) || (lVar3 = RtlCompareMemory(param_7,"AID",sVar2), lVar3 == 3)) {
        *param_5 = pcVar5;
      }
    }
    param_7 = StringChr(pcVar5,';');
    if (param_7 != (char *)0x0) {
      *param_7 = '\0';
      param_7 = param_7 + 1;
    }
  } while( true );
}



===== RtlStringCbPrintfA @ 140002270 =====

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



===== StringChr @ 140002300 =====

char * StringChr(char *param_1,char param_2)

{
  if (param_1 != (char *)0x0) {
    for (; *param_1 != '\0'; param_1 = param_1 + 1) {
      if (*param_1 == param_2) {
        return param_1;
      }
    }
  }
  return (char *)0x0;
}



===== HPUsbIOCTLVendorGetCommand @ 140002330 =====

ulonglong HPUsbIOCTLVendorGetCommand
                    (longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 *puVar5;
  longlong lVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  longlong lVar10;
  uint uVar11;
  ulonglong uVar12;
  longlong lVar13;
  undefined8 local_res10;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  uVar11 = 0;
  puVar5 = *(undefined1 **)(param_2 + 0x18);
  uVar7 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  if ((puVar5 == (undefined1 *)0x0) || (uVar7 < 3)) {
    uVar12 = 0xc000000d;
  }
  else {
    lVar13 = *(longlong *)(param_1 + 0x40);
    if (*(int *)(lVar13 + 0x424) == 4) {
      lVar13 = *(longlong *)(lVar13 + 0x590);
    }
    else {
      lVar13 = *(longlong *)(lVar13 + 0x588);
    }
    puVar9 = (undefined4 *)ExAllocatePool2(0x40,0x88,0x50425355);
    if (puVar9 == (undefined4 *)0x0) {
      uVar12 = 0xc0000017;
    }
    else {
      uVar1 = puVar5[2];
      uVar2 = *(undefined1 *)(lVar13 + 2);
      uVar3 = puVar5[1];
      uVar4 = *(undefined1 *)(lVar13 + 3);
      *(undefined1 *)((longlong)puVar9 + 0x81) = *puVar5;
      *(ushort *)(puVar9 + 0x21) = CONCAT11(uVar2,uVar4);
      *(ushort *)((longlong)puVar9 + 0x82) = CONCAT11(uVar3,uVar1);
      *puVar9 = 0x180088;
      puVar9[9] = uVar7;
      *(undefined8 *)(puVar9 + 0xc) = 0;
      *(undefined1 **)(puVar9 + 10) = puVar5;
      *(undefined1 *)(puVar9 + 0x20) = 0;
      puVar9[8] = 3;
      *(undefined8 *)(puVar9 + 0xe) = 0;
      lVar13 = *(longlong *)(param_1 + 0x40);
      local_res10 = 0xfffffffffd050f80;
      local_48 = 0;
      uStack_40 = 0;
      local_38 = 0;
      KeInitializeEvent(&local_48,0,0);
      lVar10 = IoAllocateIrp(*(undefined1 *)(*(longlong *)(lVar13 + 8) + 0x4c),0);
      if (lVar10 == 0) {
        uVar12 = 0xc000009a;
      }
      else {
        lVar6 = *(longlong *)(lVar10 + 0xb8);
        *(undefined1 *)(lVar6 + -0x48) = 0xf;
        *(undefined4 *)(lVar6 + -0x30) = 0x220003;
        *(undefined4 **)(lVar6 + -0x40) = puVar9;
        lVar6 = *(longlong *)(lVar10 + 0xb8);
        *(code **)(lVar6 + -0x10) = USBPRINT_DeferIrpCompletion;
        *(undefined8 **)(lVar6 + -8) = &local_48;
        *(undefined1 *)(lVar6 + -0x45) = 0xe0;
        uVar7 = IofCallDriver(*(undefined8 *)(lVar13 + 8),lVar10);
        if (uVar7 == 0x103) {
          param_4 = 0;
          iVar8 = KeWaitForSingleObject(&local_48,5,0,0,&local_res10);
          if (iVar8 == 0x102) {
            WriteDbgTraceInfo("USBPRINT_CallUSBD",L"Call_USBD: Cancelling IRP %X because of timeout"
                              ,lVar10,param_4);
            IoCancelIrp(lVar10);
            param_4 = 0;
            KeWaitForSingleObject(&local_48,5,0,0,0);
          }
          uVar7 = *(uint *)(lVar10 + 0x30);
        }
        uVar12 = (ulonglong)uVar7;
        IoFreeIrp(lVar10);
        if (uVar7 != 0) {
          WriteDbgTraceInfo("USBPRINT_CallUSBD",L"USBPRINT.SYS: exit USBPRINT_CallUSBD (%x)",uVar12,
                            param_4);
        }
        if (-1 < (int)uVar7) {
          uVar11 = puVar9[9];
        }
      }
      ExFreePool(puVar9);
    }
  }
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar11;
  *(int *)(param_2 + 0x30) = (int)uVar12;
  return uVar12;
}



===== USBPRINT_PowerIrp_Complete @ 1400025e0 =====

undefined8
USBPRINT_PowerIrp_Complete(undefined8 param_1,longlong param_2,longlong param_3,longlong param_4)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  char *pcVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  lVar3 = *(longlong *)(param_3 + 0x40);
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x4b8);
  if (*(char *)(param_2 + 0x41) != '\0') {
    param_4 = *(longlong *)(param_2 + 0xb8);
    *(byte *)(param_4 + 3) = *(byte *)(param_4 + 3) | 1;
  }
  *(undefined4 *)(lVar3 + 0x4e0) = 1;
  *(undefined1 *)(lVar3 + 0x4c0) = 0;
  KeReleaseSpinLock(lVar3 + 0x4b8,uVar5);
  uVar7 = 0;
  uVar6 = 1;
  KeSetEvent(lVar3 + 0x4c8);
  *(undefined4 *)(param_2 + 0x30) = 0;
  pcVar4 = *(char **)(param_3 + 0x40);
  if (*pcVar4 == '\0') {
    LOCK();
    piVar1 = (int *)(pcVar4 + 0x560);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      if (*(int *)(pcVar4 + 0x5bc) == 0) {
        USBPRINT_FdoSubmitIdleRequestIrp(param_3,uVar6,uVar7,param_4);
      }
      KeSetEvent(pcVar4 + 0x548,1);
    }
  }
  return 0;
}



===== USBPRINT_IncrementIoCount @ 1400026e0 =====

void USBPRINT_IncrementIoCount(longlong param_1)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  
  pcVar3 = *(char **)(param_1 + 0x40);
  if (*pcVar3 == '\0') {
    LOCK();
    piVar1 = (int *)(pcVar3 + 0x560);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    if (iVar2 == 0) {
      KeClearEvent(pcVar3 + 0x548);
    }
  }
  return;
}



===== USBPRINT_DeferIrpCompletion @ 140002730 =====

undefined8 USBPRINT_DeferIrpCompletion(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,1);
  return 0xc0000016;
}



===== FixupDeviceId @ 140002760 =====

void FixupDeviceId(char *param_1)

{
  char *pcVar1;
  char cVar2;
  
  cVar2 = *param_1;
  while (cVar2 != '\0') {
    if ((0x5e < (byte)(cVar2 - 0x21U)) || (cVar2 == ',')) {
      *param_1 = '_';
    }
    pcVar1 = param_1 + 1;
    param_1 = param_1 + 1;
    cVar2 = *pcVar1;
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140002790 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,uint param_3)

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
                     (local_50,*(uint **)(param_1 + 8),param_3,(uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (*(undefined4 *)(param_1 + 0x18),param_3,1,*(undefined8 *)(param_1 + 8));
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)param_3,*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140002880 =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  switch(param_3) {
  case 0:
  case 4:
    uVar4 = *param_2;
    do {
      uVar2 = uVar4;
      param_1[1] = 0;
      uVar4 = uVar2 | 1;
      if ((uVar2 >> 0xe & 1) != (uint)(param_3 == 4)) {
        uVar5 = uVar2 >> 5 & 0x1ff;
        if (uVar5 != 0) {
          param_1[1] = uVar5;
          uVar5 = 4;
          if (param_3 != 0) {
            uVar5 = 0;
          }
          uVar4 = uVar2 & 0xffffc01f | 1;
          param_1[2] = uVar5;
        }
        uVar5 = 0;
        if (param_3 == 4) {
          uVar5 = 0x4000;
        }
        uVar4 = uVar5 | uVar4 & 0xffffbfff;
      }
      uVar3 = uVar4 >> 5 & 0x1ff;
      uVar5 = uVar3 + 1;
      if ((0x1ff < uVar5) || (uVar5 < uVar3)) {
        uVar5 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar3;
      }
      LOCK();
      uVar3 = *param_2;
      if (uVar2 == uVar3) {
        *param_2 = (uVar5 << 5 ^ uVar4) & 0x3fe0 ^ uVar4;
        uVar4 = uVar2;
      }
      else {
        uVar4 = uVar3;
      }
      UNLOCK();
    } while (uVar2 != uVar3);
    param_1[4] = 0;
    *param_1 = ~uVar2 & 1;
    break;
  case 1:
  case 5:
    uVar4 = *param_2;
    do {
      uVar2 = uVar4;
      param_1[1] = 0;
      uVar4 = uVar2 | 1;
      if ((uVar2 >> 0x16 & 1) != (uint)(param_3 == 5)) {
        uVar5 = uVar2 >> 0xf & 0x7f;
        if (uVar5 != 0) {
          param_1[1] = uVar5;
          uVar5 = 5;
          if (param_3 != 1) {
            uVar5 = 1;
          }
          uVar4 = uVar2 & 0xffc07fff | 1;
          param_1[2] = uVar5;
        }
        uVar5 = 0;
        if (param_3 == 5) {
          uVar5 = 0x400000;
        }
        uVar4 = uVar5 | uVar4 & 0xffbfffff;
      }
      uVar3 = uVar4 >> 0xf & 0x7f;
      uVar5 = uVar3 + 1;
      if ((0x7f < uVar5) || (uVar5 < uVar3)) {
        uVar5 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar3;
      }
      LOCK();
      uVar3 = *param_2;
      if (uVar2 == uVar3) {
        *param_2 = (uVar5 << 0xf ^ uVar4) & 0x3f8000 ^ uVar4;
        uVar4 = uVar2;
      }
      else {
        uVar4 = uVar3;
      }
      UNLOCK();
    } while (uVar2 != uVar3);
    param_1[4] = 0;
    *param_1 = ~uVar2 & 1;
    break;
  case 2:
  case 3:
  case 6:
  case 7:
    uVar4 = 0;
    if (param_3 == 2) {
      uVar4 = 2;
    }
    else if (param_3 == 3) {
      uVar4 = 8;
    }
    else if (param_3 == 6) {
      uVar4 = 4;
    }
    else if (param_3 == 7) {
      uVar4 = 0x10;
    }
    uVar2 = *param_2;
    do {
      uVar3 = uVar2;
      uVar2 = uVar4 | uVar3;
      param_1[4] = (uint)(uVar2 == uVar3);
      uVar5 = uVar2 | 1;
      if (uVar2 == uVar3) {
        uVar5 = uVar2;
      }
      LOCK();
      uVar1 = *param_2;
      if (uVar3 == uVar1) {
        *param_2 = uVar5;
        uVar2 = uVar3;
      }
      else {
        uVar2 = uVar1;
      }
      UNLOCK();
    } while (uVar3 != uVar1);
    if (((uVar5 & 1) == 0) || (uVar4 = 1, (uVar3 & 1) != 0)) {
      uVar4 = 0;
    }
    *param_1 = uVar4;
    break;
  default:
    uVar4 = param_3 - 0x140;
    if ((int)uVar4 < 0x40) {
      uVar2 = param_2[1];
      do {
        if (((uVar2 & 0x10) == 0) || (uVar5 = 1, (uVar2 >> 5 & 0x3f) != uVar4)) {
          uVar5 = 0;
        }
        param_1[4] = uVar5;
        LOCK();
        uVar5 = param_2[1];
        bVar6 = uVar2 == uVar5;
        if (bVar6) {
          param_2[1] = (uVar4 * 0x20 ^ uVar2) & 0x7e0 ^ uVar2 | 0x10;
        }
        else {
          uVar2 = uVar5;
        }
        UNLOCK();
      } while (!bVar6);
      if (param_1[4] != 0) {
        return param_1;
      }
    }
    param_1[2] = param_3;
    param_1[1] = 1;
    param_1[3] = param_4;
  }
  return param_1;
}



===== USBPRINT_CheckConfigs @ 140002b60 =====

void USBPRINT_CheckConfigs(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  *(bool *)(lVar1 + 0x5d4) = (*(byte *)(param_2 + 7) & 0x60) == 0x60;
  lVar2 = USBD_ParseConfigurationDescriptorEx(param_2,param_2,0xffffffff,0xffffffff,7,0xffffffff,4);
  *(bool *)(lVar1 + 0x429) = lVar2 != 0;
  lVar2 = USBD_ParseConfigurationDescriptorEx(param_2,param_2,0xffffffff,0xffffffff,7,0xffffffff,2);
  *(bool *)(lVar1 + 0x428) = lVar2 != 0;
  return;
}



===== USBPRINT_Dispatch @ 140002c10 =====

ulonglong USBPRINT_Dispatch(byte *param_1,wchar_t *param_2,ulonglong param_3,byte *param_4)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  byte bVar4;
  char cVar5;
  char *pcVar6;
  undefined8 uVar7;
  longlong lVar8;
  bool bVar9;
  char ****ppppcVar10;
  uint uVar11;
  undefined8 *puVar12;
  ulonglong uVar13;
  undefined4 *puVar14;
  wchar_t *pwVar15;
  longlong lVar16;
  ulonglong uVar17;
  char *pcVar18;
  char ****ppppcVar19;
  undefined8 uVar20;
  byte *pbVar21;
  char ****local_res10;
  char ****local_res20;
  char ****local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  
  pcVar6 = *(char **)(param_1 + 0x40);
  lVar16 = *(longlong *)(param_2 + 0x5c);
  uVar17 = 0;
  uVar20 = *(undefined8 *)(pcVar6 + 8);
  bVar4 = *(byte *)(lVar16 + 1);
  if (*pcVar6 == '\0') {
    LOCK();
    piVar2 = (int *)(pcVar6 + 0x560);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + 1;
    UNLOCK();
    if (iVar3 == 0) {
      KeClearEvent(pcVar6 + 0x548);
    }
  }
  switch(*(undefined1 *)(lVar16 + 1)) {
  case 0:
    if (*pcVar6 != '\0') goto LAB_140002d74;
    local_68 = 0;
    uStack_60 = 0;
    local_58 = 0;
    WriteDbgTraceInfo("USBPRINT_Dispatch",L"USBPRINT.SYS: IRP_MN_START_DEVICE",param_3,param_4);
    param_3 = 0;
    KeInitializeEvent(&local_68,0);
    puVar12 = *(undefined8 **)(param_2 + 0x5c);
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
    lVar16 = *(longlong *)(param_2 + 0x5c);
    *(code **)(lVar16 + -0x10) = USBPRINT_DeferIrpCompletion;
    *(undefined8 **)(lVar16 + -8) = &local_68;
    *(undefined1 *)(lVar16 + -0x45) = 0xe0;
    pwVar15 = param_2;
    uVar11 = IofCallDriver(uVar20);
    if (uVar11 == 0x103) {
      param_4 = (byte *)0x0;
      param_3 = 0;
      pwVar15 = (wchar_t *)0x5;
      KeWaitForSingleObject(&local_68);
      uVar11 = *(uint *)(param_2 + 0x18);
    }
    uVar17 = (ulonglong)uVar11;
    if (-1 < (int)uVar11) {
      uVar11 = USBPRINT_StartDevice((longlong)param_1,pwVar15,param_3,param_4);
      uVar17 = (ulonglong)uVar11;
      *(uint *)(param_2 + 0x18) = uVar11;
    }
    goto LAB_140002d78;
  case 1:
  case 3:
  case 5:
  case 6:
    cVar5 = *pcVar6;
    param_2[0x18] = L'\0';
    param_2[0x19] = L'\0';
    if (cVar5 != '\0') goto LAB_140002d78;
LAB_140002db5:
    *(char *)((longlong)param_2 + 0x43) = *(char *)((longlong)param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0x5c) = *(longlong *)(param_2 + 0x5c) + 0x48;
LAB_140002dc3:
    uVar11 = IofCallDriver(uVar20);
    uVar17 = (ulonglong)uVar11;
    pwVar15 = param_2;
LAB_140002dd4:
    USBPRINT_DecrementIoCount((longlong)param_1,pwVar15,param_3,param_4);
    goto LAB_1400036e4;
  case 2:
    if (*pcVar6 != '\0') {
      USBPRINT_DecrementIoCount((longlong)param_1,&IMAGE_DOS_HEADER_140000000,param_3,param_4);
      param_2[0x18] = L'\0';
      param_2[0x19] = L'\0';
      break;
    }
    pwVar15 = L"USBPRINT.SYS: IRP_MN_REMOVE_DEVICE";
    WriteDbgTraceInfo("USBPRINT_Dispatch",L"USBPRINT.SYS: IRP_MN_REMOVE_DEVICE",param_3,param_4);
    USBPRINT_DecrementIoCount((longlong)param_1,pwVar15,param_3,param_4);
    pcVar6[0x564] = '\0';
    uVar11 = USBPRINT_StopDevice((longlong)param_1,pwVar15,param_3,param_4);
    uVar17 = (ulonglong)uVar11;
    param_2[0x18] = L'\0';
    param_2[0x19] = L'\0';
    LOCK();
    iVar3 = *(int *)(pcVar6 + 0x20);
    *(int *)(pcVar6 + 0x20) = 0;
    UNLOCK();
    if (iVar3 == 1) {
      uVar7 = *(undefined8 *)(pcVar6 + 0x18);
      pcVar6[0x18] = '\0';
      pcVar6[0x19] = '\0';
      pcVar6[0x1a] = '\0';
      pcVar6[0x1b] = '\0';
      pcVar6[0x1c] = '\0';
      pcVar6[0x1d] = '\0';
      pcVar6[0x1e] = '\0';
      pcVar6[0x1f] = '\0';
      IoDeleteDevice(uVar7);
      WriteDbgTraceInfo("USBPRINT_Dispatch",L"USBPRINT.SYS: Deleted USB child device",param_3,
                        param_4);
    }
    if (-1 < (int)uVar11) {
      puVar12 = *(undefined8 **)(param_2 + 0x5c);
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
      uVar11 = IofCallDriver(uVar20);
      uVar17 = (ulonglong)uVar11;
      uVar11 = USBPRINT_DecrementIoCount((longlong)param_1,param_2,param_3,param_4);
      WriteDbgTraceInfo("USBPRINT_Dispatch",L"USBPRINT.SYS: Pending iocount = %xp",(ulonglong)uVar11
                        ,param_4);
      uVar20 = 0;
      KeWaitForSingleObject(pcVar6 + 0x548,5,0,0,0);
      USBPRINT_RemoveDevice((longlong)param_1);
      WriteDbgTraceInfo("USBPRINT_Dispatch",L"USBPRINT.SYS: Detaching from %p",
                        *(undefined8 *)(pcVar6 + 8),uVar20);
      IoDetachDevice(*(undefined8 *)(pcVar6 + 8));
      WriteDbgTraceInfo("USBPRINT_Dispatch",L"USBPRINT.SYS: Deleting %p",param_1,uVar20);
      IoDeleteDevice(param_1);
      goto LAB_1400036e4;
    }
    goto LAB_1400036e8;
  case 4:
    if (*pcVar6 == '\0') {
      pwVar15 = L"USBPRINT.SYS: IRP_MN_STOP_DEVICE";
      WriteDbgTraceInfo("USBPRINT_Dispatch",L"USBPRINT.SYS: IRP_MN_STOP_DEVICE",param_3,param_4);
LAB_140002da9:
      USBPRINT_StopDevice((longlong)param_1,pwVar15,param_3,param_4);
      param_2[0x18] = L'\0';
      param_2[0x19] = L'\0';
      goto LAB_140002db5;
    }
    goto LAB_140002d74;
  case 7:
    WriteDbgTraceInfo("USBPRINT_Dispatch",L"USBPRINT.SYS: IRP_MN_QUERY_DEVICE_RELATIONS",param_3,
                      param_4);
    pcVar18 = *(char **)(param_1 + 0x40);
    iVar3 = *(int *)(lVar16 + 8);
    bVar9 = false;
    uVar17 = (ulonglong)*(uint *)(param_2 + 0x18);
    if (*pcVar18 == '\0') {
      pwVar15 = L"USBPRINT.SYS: Parent QueryDeviceRelations";
      WriteDbgTraceInfo("QueryDeviceRelations",L"USBPRINT.SYS: Parent QueryDeviceRelations",param_3,
                        param_4);
      if (iVar3 == 0) {
        bVar9 = true;
        param_3 = 0x50425355;
        puVar14 = (undefined4 *)ExAllocatePool2(0x40);
        if (puVar14 != (undefined4 *)0x0) {
          if ((*(int *)(pcVar18 + 0x20) == 0) || (*(longlong *)(pcVar18 + 0x18) == 0)) {
            *(undefined8 *)(puVar14 + 2) = 0;
            *puVar14 = 0;
          }
          else {
            *(longlong *)(puVar14 + 2) = *(longlong *)(pcVar18 + 0x18);
            *puVar14 = 1;
            ObfReferenceObject(*(undefined8 *)(pcVar18 + 0x18));
          }
          param_2[0x18] = L'\0';
          param_2[0x19] = L'\0';
          puVar12 = *(undefined8 **)(param_2 + 0x5c);
          *(undefined4 **)(param_2 + 0x1c) = puVar14;
          puVar12[-9] = *puVar12;
          puVar12[-8] = puVar12[1];
          puVar12[-7] = puVar12[2];
          puVar12[-6] = puVar12[3];
          puVar12[-5] = puVar12[4];
          puVar12[-4] = puVar12[5];
          puVar12[-3] = puVar12[6];
          *(undefined1 *)((longlong)puVar12 + -0x45) = 0;
          uVar20 = *(undefined8 *)(pcVar18 + 8);
          goto LAB_140002dc3;
        }
        uVar17 = 0xc0000017;
        pwVar15 = (wchar_t *)0x0;
        param_2[0x18] = L'\x17';
        param_2[0x19] = L'쀀';
        IofCompleteRequest(param_2);
      }
    }
    else {
      pwVar15 = L"USBPRINT.SYS: Child QueryDeviceRelations";
      WriteDbgTraceInfo("QueryDeviceRelations",L"USBPRINT.SYS: Child QueryDeviceRelations",param_3,
                        param_4);
      if (iVar3 == 4) {
        param_3 = 0x50425355;
        puVar14 = (undefined4 *)ExAllocatePool2(0x40);
        if (puVar14 != (undefined4 *)0x0) {
          *puVar14 = 1;
          *(byte **)(puVar14 + 2) = param_1;
          ObfReferenceObject(param_1);
          uVar20 = 0;
          *(undefined4 **)(param_2 + 0x1c) = puVar14;
          param_2[0x18] = L'\0';
          param_2[0x19] = L'\0';
          IofCompleteRequest(param_2);
          uVar17 = 0;
          USBPRINT_DecrementIoCount((longlong)param_1,uVar20,param_3,param_4);
          goto LAB_1400036e4;
        }
        uVar17 = 0xc0000017;
        param_2[0x18] = L'\x17';
        param_2[0x19] = L'쀀';
        goto LAB_140002d78;
      }
    }
    if (bVar9) goto LAB_140002dd4;
  default:
switchD_140002c91_caseD_8:
    if (*pcVar6 == '\x01') {
      uVar11 = *(uint *)(param_2 + 0x18);
      pwVar15 = (wchar_t *)0x0;
      IofCompleteRequest(param_2);
      param_2 = pwVar15;
    }
    else {
LAB_14000367f:
      *(char *)((longlong)param_2 + 0x43) = *(char *)((longlong)param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0x5c) = *(longlong *)(param_2 + 0x5c) + 0x48;
      uVar11 = IofCallDriver(uVar20);
    }
    uVar17 = (ulonglong)uVar11;
    pcVar6 = *(char **)(param_1 + 0x40);
    if (*pcVar6 == '\0') {
      LOCK();
      piVar2 = (int *)(pcVar6 + 0x560);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        if (*(int *)(pcVar6 + 0x5bc) == 0) {
          USBPRINT_FdoSubmitIdleRequestIrp((longlong)param_1,param_2,param_3,param_4);
        }
        KeSetEvent(pcVar6 + 0x548,1);
      }
    }
    goto LAB_1400036e4;
  case 9:
    if (*pcVar6 == '\0') {
      param_3 = 0;
      local_58 = 0;
      local_68 = 0;
      uStack_60 = 0;
      KeInitializeEvent(&local_68,0);
      puVar12 = *(undefined8 **)(param_2 + 0x5c);
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
      lVar8 = *(longlong *)(param_2 + 0x5c);
      *(code **)(lVar8 + -0x10) = USBPRINT_DeferIrpCompletion;
      *(undefined8 **)(lVar8 + -8) = &local_68;
      *(undefined1 *)(lVar8 + -0x45) = 0xe0;
      uVar11 = IofCallDriver(uVar20);
      if (uVar11 == 0x103) {
        param_4 = (byte *)0x0;
        param_3 = 0;
        KeWaitForSingleObject(&local_68);
        uVar11 = *(uint *)(param_2 + 0x18);
      }
      uVar17 = (ulonglong)uVar11;
      if (-1 < (int)uVar11) {
        puVar1 = (uint *)(*(longlong *)(lVar16 + 8) + 4);
        *puVar1 = *puVar1 | 0x200;
      }
      *(undefined4 *)(pcVar6 + 0x5f0) = *(undefined4 *)(*(longlong *)(lVar16 + 8) + 0x30);
      goto LAB_140002d78;
    }
    puVar1 = (uint *)(*(longlong *)(lVar16 + 8) + 4);
    *puVar1 = *puVar1 | 0x100;
    puVar1 = (uint *)(*(longlong *)(lVar16 + 8) + 4);
    *puVar1 = *puVar1 | 0x200;
    goto LAB_140002d74;
  case 0xb:
    if (*pcVar6 == '\x01') {
      if ((*(byte *)(*(longlong *)(*(longlong *)(pcVar6 + 8) + 0x40) + 0x470) & 2) != 0) {
        WriteDbgTraceInfo("USBPRINT_Dispatch",L"Setting DEVPKEY_Printer_IsFaxDevice (IPP FaxOut)",
                          param_3,param_4);
        param_4 = (byte *)0x0;
        param_3 = 0;
        uVar11 = IoSetDevicePropertyData(param_1);
        if ((int)uVar11 < 0) {
          param_3 = (ulonglong)uVar11;
          WriteDbgTraceWarning
                    ("USBPRINT_Dispatch",L"IoSetDevicePropertyData(IsFaxDevice) failed 0x%x.",
                     param_3,param_4);
        }
      }
      goto switchD_140002c91_caseD_8;
    }
    goto LAB_14000367f;
  case 0xc:
    if (*pcVar6 != '\x01') goto LAB_14000367f;
    lVar8 = *(longlong *)(*(longlong *)(pcVar6 + 8) + 0x40);
    if (*(int *)(lVar16 + 8) != 0) {
      uVar11 = *(uint *)(param_2 + 0x18);
      uVar17 = (ulonglong)uVar11;
      USBPRINT_DecrementIoCount((longlong)param_1,&IMAGE_DOS_HEADER_140000000,param_3,param_4);
      *(uint *)(param_2 + 0x18) = uVar11;
      break;
    }
    uVar13 = Feature_2524085560__private_IsEnabledDeviceUsageNoInline();
    if ((char)uVar13 == '\0') {
      uVar13 = Feature_932690235__private_IsEnabledDeviceUsageNoInline();
      if ((char)uVar13 != '\0') {
        ExAcquireFastMutex(lVar8 + 0x438);
      }
      ppppcVar19 = (char ****)&local_res20;
      local_res20 = (char ****)0x0;
      uVar13 = GetUsbPrinterName(*(longlong *)(pcVar6 + 8),*(void **)(lVar8 + 0x430),ppppcVar19,
                                 param_4);
      ppppcVar10 = local_res20;
      if ((int)uVar13 < 0) {
        WriteDbgTraceWarning
                  ("USBPRINT_Dispatch",
                   L"USBPRINT.SYS: IRP_MN_QUERY_DEVICE_TEXT - GetUsbPrinterName failed.",ppppcVar19,
                   param_4);
        local_68 = 0;
        uStack_60 = 0;
        local_78 = (char ****)0x0;
        uStack_70 = 0;
        RtlInitAnsiString(&local_68,lVar8 + 0x24);
        uVar11 = RtlAnsiStringToUnicodeString(&local_78,&local_68,1);
        ppppcVar19 = (char ****)(lVar8 + 0x24);
        uVar17 = (ulonglong)uVar11;
        pwVar15 = L"USBPRINT.SYS: IRP_MN_QUERY_DEVICE_TEXT, DeviceID=%hs";
        WriteDbgTraceInfo("USBPRINT_Dispatch",
                          L"USBPRINT.SYS: IRP_MN_QUERY_DEVICE_TEXT, DeviceID=%hs",ppppcVar19,param_4
                         );
        if (-1 < (int)uVar11) {
          *(undefined8 *)(param_2 + 0x1c) = uStack_70;
        }
      }
      else {
        pwVar15 = L"USBPRINT.SYS: IRP_MN_QUERY_DEVICE_TEXT: DeviceID=%ws";
        ppppcVar19 = local_res20;
        WriteDbgTraceInfo("USBPRINT_Dispatch",
                          L"USBPRINT.SYS: IRP_MN_QUERY_DEVICE_TEXT: DeviceID=%ws",local_res20,
                          param_4);
        *(char *****)(param_2 + 0x1c) = ppppcVar10;
      }
      uVar13 = Feature_932690235__private_IsEnabledDeviceUsageNoInline();
      if ((char)uVar13 != '\0') {
        ExReleaseFastMutex(lVar8 + 0x438);
      }
LAB_140003331:
      USBPRINT_DecrementIoCount((longlong)param_1,pwVar15,ppppcVar19,param_4);
      *(int *)(param_2 + 0x18) = (int)uVar17;
    }
    else {
      bVar9 = false;
      ppppcVar19 = (char ****)0x50425355;
      local_res20 = (char ****)0x0;
      pcVar18 = (char *)ExAllocatePool2(0x40,0x800);
      local_res10 = (char ****)0x0;
      if (pcVar18 == (char *)0x0) {
        uVar17 = 0xc0000017;
LAB_140003101:
        pwVar15 = L"USBPRINT.SYS: IRP_MN_QUERY_DEVICE_TEXT - GetUsbPrinterName failed.";
        WriteDbgTraceWarning
                  ("USBPRINT_Dispatch",
                   L"USBPRINT.SYS: IRP_MN_QUERY_DEVICE_TEXT - GetUsbPrinterName failed.",ppppcVar19,
                   param_4);
        if (bVar9) {
          local_78 = (char ****)0x0;
          uStack_70 = 0;
          local_68 = 0;
          uStack_60 = 0;
          RtlInitAnsiString(&local_78,local_res10);
          uVar11 = RtlAnsiStringToUnicodeString(&local_68,&local_78,1);
          pwVar15 = L"USBPRINT.SYS: IRP_MN_QUERY_DEVICE_TEXT, DeviceID=%hs";
          uVar17 = (ulonglong)uVar11;
          WriteDbgTraceInfo("USBPRINT_Dispatch",
                            L"USBPRINT.SYS: IRP_MN_QUERY_DEVICE_TEXT, DeviceID=%hs",local_res10,
                            param_4);
          ppppcVar19 = local_res10;
          if (-1 < (int)uVar11) {
            *(undefined8 *)(param_2 + 0x1c) = uStack_60;
          }
        }
        if (pcVar18 == (char *)0x0) goto LAB_140003331;
      }
      else {
        local_res10 = (char ****)(pcVar18 + 0x400);
        ExAcquireFastMutex(lVar8 + 0x438);
        uVar11 = USBPRINT_CopyDeviceIdStringLocked(lVar8,pcVar18 + 0x400,ppppcVar19,param_4);
        ppppcVar19 = (char ****)&local_res20;
        uVar13 = USBPRINT_Copy1284IdLocked(lVar8,pcVar18,ppppcVar19,param_4);
        ExReleaseFastMutex(lVar8 + 0x438);
        if ((int)uVar11 < 0) {
          uVar17 = (ulonglong)uVar11;
        }
        bVar9 = (int)uVar11 >= 0;
        local_78 = (char ****)0x0;
        if ((int)uVar13 < 0) goto LAB_140003101;
        ppppcVar19 = (char ****)&local_78;
        uVar13 = GetUsbPrinterName(*(longlong *)(pcVar6 + 8),local_res20,ppppcVar19,param_4);
        ppppcVar10 = local_78;
        if ((int)uVar13 < 0) goto LAB_140003101;
        pwVar15 = L"USBPRINT.SYS: IRP_MN_QUERY_DEVICE_TEXT: DeviceID=%ws";
        ppppcVar19 = local_78;
        WriteDbgTraceInfo("USBPRINT_Dispatch",
                          L"USBPRINT.SYS: IRP_MN_QUERY_DEVICE_TEXT: DeviceID=%ws",local_78,param_4);
        uVar17 = 0;
        *(char *****)(param_2 + 0x1c) = ppppcVar10;
      }
      ExFreePool(pcVar18);
      USBPRINT_DecrementIoCount((longlong)param_1,pwVar15,ppppcVar19,param_4);
      *(int *)(param_2 + 0x18) = (int)uVar17;
    }
    break;
  case 0x13:
    WriteDbgTraceInfo("USBPRINT_Dispatch",L"USBPRINT.SYS: IRP_MN_QUERY_ID",param_3,param_4);
    if (*pcVar6 != '\x01') goto LAB_14000367f;
    pwVar15 = param_2;
    pbVar21 = param_1;
    uVar13 = ProduceQueriedID(pcVar6,lVar16,(longlong)param_2,param_1);
    uVar17 = uVar13 & 0xffffffff;
    USBPRINT_DecrementIoCount((longlong)param_1,lVar16,pwVar15,pbVar21);
    *(int *)(param_2 + 0x18) = (int)uVar13;
    break;
  case 0x15:
    if (*pcVar6 != '\x01') goto LAB_14000367f;
    uVar20 = 0x50425355;
    puVar12 = (undefined8 *)ExAllocatePool2(0x100,0x18);
    pwVar15 = L"USBPRINT.SYS: IRP_MN_QUERY_BUS_INFORMATION";
    WriteDbgTraceInfo("USBPRINT_Dispatch",L"USBPRINT.SYS: IRP_MN_QUERY_BUS_INFORMATION",uVar20,
                      param_4);
    if (puVar12 == (undefined8 *)0x0) {
      uVar17 = 0xc0000017;
      USBPRINT_DecrementIoCount((longlong)param_1,pwVar15,uVar20,param_4);
      param_2[0x18] = L'\x17';
      param_2[0x19] = L'쀀';
    }
    else {
      puVar12[2] = 0xf;
      *puVar12 = 0x11d54342441ee000;
      puVar12[1] = 0x4d52604fc00084a1;
      *(undefined8 **)(param_2 + 0x1c) = puVar12;
      USBPRINT_DecrementIoCount((longlong)param_1,pwVar15,uVar20,param_4);
      param_2[0x18] = L'\0';
      param_2[0x19] = L'\0';
    }
    break;
  case 0x17:
    if (*pcVar6 == '\0') {
      WriteDbgTraceInfo("USBPRINT_Dispatch",L"USBPRINT.SYS:   Surprise Remove",param_3,param_4);
      pcVar6[0x5f4] = '\x01';
      pcVar18 = pcVar6 + 0x568;
      lVar16 = 2;
      do {
        pwVar15 = (wchar_t *)0x0;
        IoSetDeviceInterfaceState(pcVar18);
        pcVar18 = pcVar18 + 0x10;
        lVar16 = lVar16 + -1;
      } while (lVar16 != 0);
      pcVar6[0x564] = '\0';
      goto LAB_140002da9;
    }
LAB_140002d74:
    param_2[0x18] = L'\0';
    param_2[0x19] = L'\0';
LAB_140002d78:
    uVar20 = 0;
    IofCompleteRequest(param_2);
    USBPRINT_DecrementIoCount((longlong)param_1,uVar20,param_3,param_4);
    goto LAB_1400036e4;
  case 0x19:
    pwVar15 = L"USBPRINT.SYS: IRP_MN_DEVICE_ENUMERATED";
    WriteDbgTraceInfo("USBPRINT_Dispatch",L"USBPRINT.SYS: IRP_MN_DEVICE_ENUMERATED",param_3,param_4)
    ;
    if (*pcVar6 != '\x01') goto LAB_14000367f;
    pbVar21 = param_1;
    uVar13 = SetPortNameAndPrinterName((longlong)pcVar6,(char *)pwVar15,param_3,param_1);
    uVar17 = uVar13 & 0xffffffff;
    USBPRINT_DecrementIoCount((longlong)param_1,pwVar15,param_3,pbVar21);
    *(int *)(param_2 + 0x18) = (int)uVar13;
  }
  IofCompleteRequest(param_2,0);
LAB_1400036e4:
  if ((int)uVar17 < 0) {
LAB_1400036e8:
    WriteDbgTraceInfo("USBPRINT_Dispatch",L"Returning 0x%x for MinorFunction(%d)",uVar17,
                      (ulonglong)bVar4);
  }
  return uVar17;
}



===== USBPRINT_InitDeviceObject @ 140003720 =====

uint USBPRINT_InitDeviceObject
               (longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  longlong lVar7;
  wchar_t *pwVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  undefined8 *puVar11;
  uint local_res8 [2];
  undefined4 local_res10 [2];
  undefined8 local_res18;
  undefined8 in_stack_ffffffffffffff98;
  undefined4 uVar12;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  
  uVar12 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);
  lVar1 = *(longlong *)(param_1 + 0x40);
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x2010;
  local_res18 = 0;
  uVar9 = 0;
  *(longlong *)(lVar1 + 0x10) = param_2;
  *(undefined8 *)(lVar1 + 0x5d8) = 0;
  *(undefined8 *)(lVar1 + 0x5e0) = 0;
  *(undefined8 *)(lVar1 + 0x5e8) = 0;
  *(undefined4 *)(lVar1 + 0x5bc) = 0;
  *(undefined1 *)(lVar1 + 0x4c0) = 0;
  *(undefined4 *)(lVar1 + 0x4e0) = 1;
  KeInitializeEvent(lVar1 + 0x4c8,0);
  KeInitializeSpinLock(lVar1 + 0x4b8);
  *(undefined8 *)(lVar1 + 0x430) = 0;
  *(undefined4 *)(lVar1 + 0x424) = 2;
  *(undefined4 *)(lVar1 + 0x42c) = 0;
  lVar6 = IoAttachDeviceToDeviceStack(param_1,param_2);
  *(longlong *)(lVar1 + 8) = lVar6;
  if (lVar6 == 0) {
    WriteDbgTraceWarning
              ("USBPRINT_InitDeviceObject",L"USBPRINT.SYS:  IoAttachDeviceToDeviceStack failed",
               uVar9,param_4);
    uVar4 = 0xc00002b6;
    goto LAB_140003b56;
  }
  lVar6 = lVar1 + 0x568;
  uVar4 = IoRegisterDeviceInterface(param_2,DAT_140014148,0);
  if ((int)uVar4 < 0) {
    uVar10 = (ulonglong)uVar4;
    pwVar8 = L"USBPRINT.SYS:  IoRegisterDeviceInterface(USB) failed 0x%x";
  }
  else {
    uVar4 = IoOpenDeviceInterfaceRegistryKey(lVar1 + 0x568,0xf003f,&local_res18);
    uVar9 = local_res18;
    if (-1 < (int)uVar4) {
      *(undefined8 *)(lVar1 + 0x5c0) = local_res18;
      uVar10 = 0x50425355;
      local_58 = 0;
      uStack_50 = 0;
      local_res10[0] = 0x14;
      lVar7 = ExAllocatePool2(0x40);
      if (lVar7 == 0) {
        uVar4 = 0xc000009a;
      }
      else {
        RtlInitUnicodeString(&local_58,L"Port Number");
        uVar10 = 2;
        lVar6 = lVar7;
        iVar5 = ZwQueryValueKey(uVar9,&local_58,2,lVar7,CONCAT44(uVar12,local_res10[0]),local_res10)
        ;
        if (iVar5 < 0) {
          WriteDbgTraceInfo("GetPortNumber",L"USBPRINT.SYS: GetPortNumber; ZwQueryValueKey failed",
                            uVar10,lVar6);
          if (iVar5 == -0x7ffffffb) {
            WriteDbgTraceInfo("GetPortNumber",
                              L"USBPRINT.SYS: GetPortNumber zwQueryValueKey returned STATUS_BUFFER_OVERFLOW"
                              ,uVar10,lVar6);
          }
          else if (iVar5 == -0x3ffffff3) {
            WriteDbgTraceInfo("GetPortNumber",
                              L"USBPRINT.SYS: GetPortNumber zwQueryValueKey returned STATUS_INVALID_PARAMETER"
                              ,uVar10,lVar6);
          }
          else {
            pwVar8 = L"USBPRINT.SYS: GetPortNumber zwQueryValueKey returned unkown error";
            if (iVar5 == -0x3fffffcc) {
              pwVar8 = 
              L"USBPRINT.SYS: GetPortNumber zwQueryValueKey returned STATUS_OBJECT_NAME_NOT_FOUND";
            }
            WriteDbgTraceInfo("GetPortNumber",pwVar8,uVar10,lVar6);
          }
LAB_140003994:
          uVar4 = 0;
          if (g_pFreePortList == (uint *)0x0) {
            uVar4 = InitFreePorts();
            if (g_pFreePortList == (uint *)0x0) {
              if (-1 < (int)uVar4) {
                uVar4 = 0xc0000042;
                local_res8[0] = 0;
                goto LAB_140003a07;
              }
            }
            else if (-1 < (int)uVar4) goto LAB_1400039d7;
            local_res8[0] = 0;
          }
          else {
LAB_1400039d7:
            puVar2 = g_pFreePortList;
            local_res8[0] = *g_pFreePortList;
            *g_pFreePortList = *g_pFreePortList + 1;
            if (g_pFreePortList[1] < *puVar2) {
              g_pFreePortList = *(uint **)(g_pFreePortList + 2);
              ExFreePool();
            }
          }
LAB_140003a07:
          if (-1 < (int)uVar4) goto LAB_140003a57;
          WriteDbgTraceInfo("GetPortNumber",
                            L"USBPRINT.SYS: GetPortNumber; failed to allocate new port number",
                            uVar10,lVar6);
        }
        else {
          local_res8[0] = *(uint *)(lVar7 + 0xc);
          if (local_res8[0] == 0) goto LAB_140003994;
          local_48 = 0;
          uStack_40 = 0;
          RtlInitUnicodeString(&local_48,L"RECYCLABLE");
          ZwDeleteValueKey(uVar9,&local_48);
LAB_140003a57:
          lVar6 = 4;
          uVar4 = ZwSetValueKey(uVar9,&local_58,0,4,local_res8,4);
          uVar3 = local_res8[0];
          if (-1 < (int)uVar4) {
            ExFreePool(lVar7);
            *(uint *)(lVar1 + 0x5b8) = uVar3;
            lVar6 = lVar1 + 0x578;
            uVar4 = IoRegisterDeviceInterface(param_2,DAT_140014158,0);
            if ((int)uVar4 < 0) {
              uVar10 = (ulonglong)uVar4;
              pwVar8 = L"USBPRINT.SYS:  IoRegisterDeviceInterface(IPP) failed 0x%x";
            }
            else {
              puVar11 = &local_res18;
              uVar4 = IoOpenDeviceInterfaceRegistryKey(lVar1 + 0x578,0xf003f);
              if (-1 < (int)uVar4) {
                *(undefined8 *)(lVar1 + 0x5c8) = local_res18;
                USBPRINT_QueryCapabilities(param_2,lVar1 + 0x4f8,puVar11,lVar6);
                USBPRINT_IncrementIoCount(param_1);
                return uVar4;
              }
              uVar10 = (ulonglong)uVar4;
              pwVar8 = L"USBPRINT.SYS: IoOpenDeviceInterfaceRegistryKey(IPP) failed 0x%x";
            }
            goto LAB_140003b4a;
          }
          uVar10 = (ulonglong)uVar4;
          WriteDbgTraceInfo("GetPortNumber",
                            L"USBPRINT.SYS: GetPortNumber: ZwSetValueKey failed 0x%x",uVar10,lVar6);
        }
        ExFreePool(lVar7);
      }
      WriteDbgTraceWarning
                ("USBPRINT_InitDeviceObject",L"USBPRINT.SYS: GetPortNumber(USB) failed",uVar10,lVar6
                );
      goto LAB_140003b56;
    }
    uVar10 = (ulonglong)uVar4;
    pwVar8 = L"USBPRINT.SYS: IoOpenDeviceInterfaceRegistryKey(USB) failed 0x%x";
  }
LAB_140003b4a:
  WriteDbgTraceWarning("USBPRINT_InitDeviceObject",pwVar8,uVar10,lVar6);
LAB_140003b56:
  if (*(longlong *)(lVar1 + 8) != 0) {
    IoDetachDevice();
  }
  if (*(short *)(lVar1 + 0x568) != 0) {
    RtlFreeUnicodeString(lVar1 + 0x568);
  }
  if (*(short *)(lVar1 + 0x578) != 0) {
    RtlFreeUnicodeString();
  }
  IoDeleteDevice(param_1);
  return uVar4;
}



===== USBPRINT_ResetPipe @ 140003c00 =====

uint USBPRINT_ResetPipe(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 *puVar3;
  wchar_t *pwVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined8 local_res20;
  
  local_res20 = 0xfffffffffd050f80;
  lVar5 = param_2;
  WriteDbgTraceInfo("USBPRINT_ResetPipe",L"USBPRINT.SYS: Entering Reset Pipe; pipe # %p",param_2,
                    param_4);
  uVar2 = Feature_3186517304__private_IsEnabledDeviceUsageNoInline();
  if (((char)uVar2 != '\0') && (param_2 == 0)) {
    WriteDbgTraceWarning
              ("USBPRINT_ResetPipe",L"USBPRINT.SYS: ResetPipe called with no pipe",lVar5,param_4);
    return 0xc0000008;
  }
  puVar3 = (undefined4 *)ExAllocatePool2(0x40,0x28,0x50425355);
  if (puVar3 == (undefined4 *)0x0) {
    uVar1 = 0xc000009a;
  }
  else {
    *puVar3 = 0x1e0028;
    puVar6 = &local_res20;
    *(undefined8 *)(puVar3 + 6) = *(undefined8 *)(param_2 + 8);
    uVar1 = USBPRINT_CallUSBD(param_1,puVar3,puVar6,param_4);
    pwVar4 = L"USBPRINT.SYS: CallUSBD failed in ResetPipe";
    if (-1 < (int)uVar1) {
      pwVar4 = L"USBPRINT.SYS: CallUSBD Succeeded in ResetPipe";
    }
    WriteDbgTraceInfo("USBPRINT_ResetPipe",pwVar4,puVar6,param_4);
    ExFreePool(puVar3);
  }
  return uVar1;
}



===== USBPRINT_SetDeviceID @ 140003d10 =====

int USBPRINT_SetDeviceID(longlong param_1,void *param_2,char *param_3,byte *param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  
  iVar4 = 0;
  pcVar6 = param_3;
  WriteDbgTraceInfo("USBPRINT_SetDeviceID",L"USBPRINT.SYS: USBPRINT_SetDeviceID enter",param_3,
                    param_4);
  if (param_1 == 0) {
    return -0x3ffffff3;
  }
  uVar5 = (uint)param_3;
  if (0x3ff < uVar5) {
    pcVar6 = (char *)((ulonglong)param_3 & 0xffffffff);
    iVar4 = -0x3ffffff3;
    WriteDbgTraceInfo("USBPRINT_SetDeviceID",
                      L"USBPRINT.SYS: USBPRINT_SetDeviceID failed, invalid input buffer length: %d",
                      pcVar6,param_4);
  }
  uVar2 = Feature_932690235__private_IsEnabledDeviceUsageNoInline();
  if (((char)uVar2 == '\0') &&
     (uVar2 = Feature_2524085560__private_IsEnabledDeviceUsageNoInline(), (char)uVar2 == '\0')) {
    if (iVar4 < 0) goto LAB_140003eea;
    pcVar6 = (char *)0x50425355;
    pcVar3 = (char *)ExAllocatePool2(0x40,uVar5 + 1);
    if (pcVar3 != (char *)0x0) {
      memmove(pcVar3,param_2,(ulonglong)param_3 & 0xffffffff);
      LOCK();
      lVar1 = *(longlong *)(param_1 + 0x430);
      *(longlong *)(param_1 + 0x430) = (longlong)pcVar3;
      UNLOCK();
      if (lVar1 != 0) {
        ExFreePool();
      }
      pcVar6 = (char *)(param_1 + 0x24);
      uVar2 = ParPnpGetId(pcVar3,0,pcVar6,param_4);
      iVar4 = (int)uVar2;
      if (iVar4 < 0) {
        WriteDbgTraceInfo("USBPRINT_SetDeviceID",
                          L"USBPRINT.SYS: USBPRINT_SetDeviceID ParPnpGetId failed, error== 0x%0X",
                          uVar2 & 0xffffffff,param_4);
        pcVar6 = "UnknownPrinter";
        RtlStringCbPrintfA((char *)(param_1 + 0x24),0x400,"UnknownPrinter",param_4);
      }
      goto LAB_140003eea;
    }
  }
  else {
    if (iVar4 < 0) goto LAB_140003eea;
    pcVar6 = (char *)0x50425355;
    pcVar3 = (char *)ExAllocatePool2(0x40,uVar5 + 1);
    if (pcVar3 != (char *)0x0) {
      memmove(pcVar3,param_2,(ulonglong)param_3 & 0xffffffff);
      ExAcquireFastMutex(param_1 + 0x438);
      LOCK();
      lVar1 = *(longlong *)(param_1 + 0x430);
      *(longlong *)(param_1 + 0x430) = (longlong)pcVar3;
      UNLOCK();
      if (lVar1 != 0) {
        ExFreePool();
      }
      pcVar6 = (char *)(param_1 + 0x24);
      uVar2 = ParPnpGetId(pcVar3,0,pcVar6,param_4);
      iVar4 = (int)uVar2;
      if (iVar4 < 0) {
        WriteDbgTraceInfo("USBPRINT_SetDeviceID",
                          L"USBPRINT.SYS: USBPRINT_SetDeviceID ParPnpGetId failed, error== 0x%0X",
                          uVar2 & 0xffffffff,param_4);
        pcVar6 = "UnknownPrinter";
        RtlStringCbPrintfA((char *)(param_1 + 0x24),0x400,"UnknownPrinter",param_4);
        iVar4 = 0;
      }
      ExReleaseFastMutex(param_1 + 0x438);
      goto LAB_140003eea;
    }
  }
  iVar4 = -0x3fffffe9;
LAB_140003eea:
  WriteDbgTraceInfo("USBPRINT_SetDeviceID",L"USBPRINT.SYS: USBPRINT_SetDeviceID exit",pcVar6,param_4
                   );
  return iVar4;
}



===== USBPRINT_StartDevice @ 140003f20 =====

uint USBPRINT_StartDevice(longlong param_1,undefined8 param_2,undefined8 param_3,byte *param_4)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  longlong lVar5;
  byte *pbVar6;
  ulonglong uVar7;
  byte bVar8;
  wchar_t *pwVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 *puVar12;
  byte *_Dst;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined8 local_78;
  undefined8 uStack_70;
  byte local_68 [32];
  undefined8 *local_48;
  undefined4 local_40;
  undefined8 local_3c;
  undefined8 uStack_34;
  undefined4 local_2c;
  
  pcVar1 = *(char **)(param_1 + 0x40);
  uVar11 = 0x50425355;
  local_res8 = 0;
  puVar4 = (undefined4 *)ExAllocatePool2(0x40);
  if (puVar4 == (undefined4 *)0x0) {
    uVar2 = 0xc000009a;
    WriteDbgTraceWarning
              ("USBPRINT_StartDevice",
               L"USBPRINT.SYS: Insufficient resources to allocate urb in StartDevice",uVar11,param_4
              );
  }
  else {
    puVar12 = (undefined8 *)0x50425355;
    lVar5 = ExAllocatePool2(0x40);
    if (lVar5 == 0) {
      pwVar9 = L"USBPRINT.SYS: Insufficient resources to allocate device descriptor in StartDevice";
      uVar2 = 0xc000009a;
      WriteDbgTraceWarning
                ("USBPRINT_StartDevice",
                 L"USBPRINT.SYS: Insufficient resources to allocate device descriptor in StartDevice"
                 ,puVar12,param_4);
    }
    else {
      *puVar4 = 0xb0088;
      puVar12 = &local_res8;
      puVar4[9] = 0x12;
      *(undefined8 *)(puVar4 + 0xc) = 0;
      *(longlong *)(puVar4 + 10) = lVar5;
      *(undefined4 *)((longlong)puVar4 + 0x82) = 0x100;
      *(undefined8 *)(puVar4 + 0xe) = 0;
      local_res8 = 0xfffffffffd050f80;
      uVar2 = USBPRINT_CallUSBD(param_1,puVar4,puVar12,param_4);
      if ((int)uVar2 < 0) {
        pwVar9 = L"USBPRINT.SYS: Get Device Descriptor failed";
        WriteDbgTraceWarning
                  ("USBPRINT_StartDevice",L"USBPRINT.SYS: Get Device Descriptor failed",puVar12,
                   param_4);
        uVar2 = 0xc0000182;
        ExFreePool(lVar5);
      }
      else {
        param_4 = (byte *)(ulonglong)*(ushort *)(lVar5 + 10);
        pwVar9 = L"USBPRINT.SYS: USBPRINT Device Descriptor: VID 0x%x PID 0x%x";
        puVar12 = (undefined8 *)(ulonglong)*(ushort *)(lVar5 + 8);
        WriteDbgTraceInfo("USBPRINT_StartDevice",
                          L"USBPRINT.SYS: USBPRINT Device Descriptor: VID 0x%x PID 0x%x",puVar12,
                          param_4);
        *(longlong *)(pcVar1 + 0x4f0) = lVar5;
      }
    }
    ExFreePool(puVar4);
    if ((-1 < (int)uVar2) &&
       (uVar2 = USBPRINT_ConfigureDevice(param_1,pwVar9,puVar12,param_4), -1 < (int)uVar2)) {
      pwVar9 = (wchar_t *)0x103;
      pcVar1[0x4b2] = '\0';
      _Dst = (byte *)0x50425355;
      pbVar6 = (byte *)ExAllocatePool2(0x40);
      if (pbVar6 != (byte *)0x0) {
        param_4 = (byte *)0x103;
        bVar8 = *(byte *)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x4f0) + 0x10);
        pwVar9 = (wchar_t *)(ulonglong)bVar8;
        _Dst = pbVar6;
        uVar7 = USBPRINT_GetUsbStringDescriptor(param_1,bVar8,pbVar6,0x103);
        if (0 < (int)uVar7) {
          _Dst = (byte *)(pcVar1 + 0x472);
          _Dst[0] = 0;
          _Dst[1] = 0;
          _Dst[2] = 0;
          _Dst[3] = 0;
          _Dst[4] = 0;
          _Dst[5] = 0;
          _Dst[6] = 0;
          _Dst[7] = 0;
          pcVar1[0x47a] = '\0';
          pcVar1[0x47b] = '\0';
          pcVar1[0x47c] = '\0';
          pcVar1[0x47d] = '\0';
          pcVar1[0x47e] = '\0';
          pcVar1[0x47f] = '\0';
          pcVar1[0x480] = '\0';
          pcVar1[0x481] = '\0';
          pcVar1[0x482] = '\0';
          pcVar1[0x483] = '\0';
          pcVar1[0x484] = '\0';
          pcVar1[0x485] = '\0';
          pcVar1[0x486] = '\0';
          pcVar1[0x487] = '\0';
          pcVar1[0x488] = '\0';
          pcVar1[0x489] = '\0';
          pcVar1[0x48a] = '\0';
          pcVar1[0x48b] = '\0';
          pcVar1[0x48c] = '\0';
          pcVar1[0x48d] = '\0';
          pcVar1[0x48e] = '\0';
          pcVar1[0x48f] = '\0';
          pcVar1[0x490] = '\0';
          pcVar1[0x491] = '\0';
          pcVar1[0x492] = '\0';
          pcVar1[0x493] = '\0';
          pcVar1[0x494] = '\0';
          pcVar1[0x495] = '\0';
          pcVar1[0x496] = '\0';
          pcVar1[0x497] = '\0';
          pcVar1[0x498] = '\0';
          pcVar1[0x499] = '\0';
          pcVar1[0x49a] = '\0';
          pcVar1[0x49b] = '\0';
          pcVar1[0x49c] = '\0';
          pcVar1[0x49d] = '\0';
          pcVar1[0x49e] = '\0';
          pcVar1[0x49f] = '\0';
          pcVar1[0x4a0] = '\0';
          pcVar1[0x4a1] = '\0';
          pcVar1[0x4a2] = '\0';
          pcVar1[0x4a3] = '\0';
          pcVar1[0x4a4] = '\0';
          pcVar1[0x4a5] = '\0';
          pcVar1[0x4a6] = '\0';
          pcVar1[0x4a7] = '\0';
          pcVar1[0x4a8] = '\0';
          pcVar1[0x4a9] = '\0';
          pcVar1[0x4aa] = '\0';
          pcVar1[0x4ab] = '\0';
          pcVar1[0x4ac] = '\0';
          pcVar1[0x4ad] = '\0';
          pcVar1[0x4ae] = '\0';
          pcVar1[0x4af] = '\0';
          pcVar1[0x4b0] = '\0';
          pcVar1[0x4b1] = '\0';
          bVar8 = *pbVar6;
          if (bVar8 < 2) {
            _Dst = (byte *)(ulonglong)bVar8;
            pwVar9 = L"USBPRINT.SYS: Got invalid bLength of (%d) for serial number";
            WriteDbgTraceWarning
                      ("USBPRINT_StartDevice",
                       L"USBPRINT.SYS: Got invalid bLength of (%d) for serial number",_Dst,param_4);
            uVar2 = 0xc0000182;
          }
          else {
            if ((ulonglong)bVar8 - 2 < 0x3f) {
              bVar8 = bVar8 - 2;
            }
            else {
              bVar8 = 0x3e;
            }
            memmove(_Dst,pbVar6 + 2,(ulonglong)bVar8);
            pcVar1[0x4b2] = '\x01';
            pwVar9 = L"USBPRINT.SYS: Serial number: %ws";
            WriteDbgTraceInfo("USBPRINT_StartDevice",L"USBPRINT.SYS: Serial number: %ws",_Dst,
                              param_4);
          }
        }
        ExFreePool(pbVar6);
        if ((int)uVar2 < 0) goto LAB_140004354;
      }
      USBPRINT_GetDeviceID(param_1,pwVar9,_Dst,param_4);
      if (pcVar1[0x429] == '\0') {
        WritePortDescription((longlong)pcVar1,0,_Dst,param_4);
        uVar2 = IoSetDeviceInterfaceState(pcVar1 + 0x568);
        if ((int)uVar2 < 0) goto LAB_140004354;
        uVar10 = 0;
        uVar11 = USBPRINT_BuildPipeList(param_1,0,_Dst,param_4);
        uVar2 = (uint)uVar11;
      }
      else {
        WritePortDescription((longlong)pcVar1,1,_Dst,param_4);
        IoSetDeviceInterfaceState(pcVar1 + 0x578);
        if (*(int *)(pcVar1 + 0x424) == 4) {
          uVar10 = 1;
          uVar11 = USBPRINT_BuildPipeList(param_1,1,_Dst,param_4);
          uVar2 = (uint)uVar11;
          if (-1 < (int)uVar2) {
            local_68[0x14] = 0;
            local_68[0x15] = 0;
            local_68[0x16] = 0;
            local_68[0x17] = 0;
            local_68[0x18] = 0;
            local_68[0x19] = 0;
            local_68[0x1a] = 0;
            local_68[0x1b] = 0;
            local_68[0x1c] = 0;
            local_68[0x1d] = 0;
            local_68[0x1e] = 0;
            local_68[0x1f] = 0;
            local_res10 = 0;
            local_3c = 0;
            uStack_34 = 0;
            local_78 = 0;
            uStack_70 = 0;
            RtlInitUnicodeString(&local_78,L"\\SystemRoot\\System32\\DafIppUsb.Dll");
            local_48 = &local_78;
            local_68[0x14] = 0;
            local_68[0x15] = 0;
            local_68[0x16] = 0;
            local_68[0x17] = 0;
            local_68[0x18] = 0;
            local_68[0x19] = 0;
            local_68[0x1a] = 0;
            local_68[0x1b] = 0;
            param_4 = local_68;
            _Dst = local_68 + 0x10;
            local_68[0x1c] = 0;
            local_68[0x1d] = 0;
            local_68[0x1e] = 0;
            local_68[0x1f] = 0;
            uVar10 = 0x80000000;
            local_2c = 0;
            local_68[0x10] = 0x30;
            local_68[0x11] = 0;
            local_68[0x12] = 0;
            local_68[0x13] = 0;
            local_68[0] = 0;
            local_68[1] = 0;
            local_68[2] = 0;
            local_68[3] = 0;
            local_68[4] = 0;
            local_68[5] = 0;
            local_68[6] = 0;
            local_68[7] = 0;
            local_68[8] = 0;
            local_68[9] = 0;
            local_68[10] = 0;
            local_68[0xb] = 0;
            local_68[0xc] = 0;
            local_68[0xd] = 0;
            local_68[0xe] = 0;
            local_68[0xf] = 0;
            local_40 = 0x240;
            local_3c = 0;
            uStack_34 = 0;
            iVar3 = ZwOpenFile(&local_res10);
            if (-1 < iVar3) {
              ZwClose(local_res10);
              param_4 = (byte *)0x0;
              _Dst = (byte *)0x0;
              uVar10 = 0;
              ZwUpdateWnfStateData(&WNF_PDM_IPPUSB_DEVICE_ARRIVAL);
            }
          }
        }
        else {
          uVar10 = 0;
          uVar11 = USBPRINT_BuildPipeList(param_1,0,_Dst,param_4);
          uVar2 = (uint)uVar11;
          *(undefined8 *)(pcVar1 + 0x5b0) = *(undefined8 *)(pcVar1 + 0x5a8);
          *(undefined8 *)(pcVar1 + 0x5a0) = *(undefined8 *)(pcVar1 + 0x598);
        }
        if (pcVar1[0x428] != '\0') {
          uVar11 = 0;
          *(undefined8 *)(pcVar1 + 0x5a8) = *(undefined8 *)(pcVar1 + 0x5b0);
          *(undefined8 *)(pcVar1 + 0x598) = *(undefined8 *)(pcVar1 + 0x5a0);
          WritePortDescription((longlong)pcVar1,0,_Dst,param_4);
          uVar10 = CONCAT71((int7)((ulonglong)uVar11 >> 8),1);
          IoSetDeviceInterfaceState(pcVar1 + 0x568);
        }
      }
      if (-1 < (int)uVar2) {
        if (*pcVar1 == '\0') {
          USBPRINT_FdoSubmitIdleRequestIrp(param_1,uVar10,_Dst,param_4);
          return uVar2;
        }
        return uVar2;
      }
    }
  }
LAB_140004354:
  WriteDbgTraceInfo("USBPRINT_StartDevice",L"USBPRINT.SYS: exit USBPRINT_StartDevice (%x)",
                    (ulonglong)uVar2,param_4);
  return uVar2;
}



===== WritePortDescription @ 140004390 =====

void WritePortDescription(longlong param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong uVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  longlong lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  uint local_res8 [2];
  int local_res10;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  
  local_88 = 0;
  uStack_80 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if (param_2 == 1) {
    uVar8 = *(undefined8 *)(param_1 + 0x5c8);
  }
  else {
    uVar8 = *(undefined8 *)(param_1 + 0x5c0);
  }
  local_res10 = param_2;
  RtlInitUnicodeString(&local_88,L"Port Description");
  uVar2 = Feature_2524085560__private_IsEnabledDeviceUsageNoInline();
  if ((char)uVar2 == '\0') {
    RtlInitAnsiString(&local_a8,param_1 + 0x24);
    uStack_b0 = 0;
    RtlAnsiStringToUnicodeString(&local_b8,&local_a8,1);
    ZwSetValueKey(uVar8,&local_88,0,1,uStack_b0,(ushort)local_b8 + 2);
    RtlFreeUnicodeString(&local_b8);
  }
  else {
    uVar7 = 0x50425355;
    pcVar3 = (char *)ExAllocatePool2(0x40,0x400);
    if (pcVar3 == (char *)0x0) {
      WriteDbgTraceWarning
                ("WritePortDescription",
                 L"USBPRINT.SYS: WritePortDescription; no memory for DeviceIdString snapshot.",uVar7
                 ,param_4);
    }
    else {
      ExAcquireFastMutex(param_1 + 0x438);
      lVar6 = 0x400;
      pcVar5 = pcVar3;
      do {
        if ((lVar6 == -0x7ffffbfe) || (pcVar5[(param_1 - (longlong)pcVar3) + 0x24] == '\0')) break;
        *pcVar5 = pcVar5[(param_1 - (longlong)pcVar3) + 0x24];
        pcVar5 = pcVar5 + 1;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
      pcVar4 = pcVar5 + -1;
      if (lVar6 != 0) {
        pcVar4 = pcVar5;
      }
      iVar1 = -0x7ffffffb;
      if (lVar6 != 0) {
        iVar1 = 0;
      }
      *pcVar4 = '\0';
      if (lVar6 == 0) {
        WriteDbgTraceWarning
                  ("USBPRINT_CopyDeviceIdStringLocked",
                   L"USBPRINT.SYS: DeviceIdString exceeded the writer-enforced MAX_ID_SIZE invariant."
                   ,uVar7,param_4);
        lVar6 = 0x400;
        for (pcVar5 = pcVar3;
            (lVar6 + -1 != 0 && (pcVar5[(param_1 - (longlong)pcVar3) + 0x24] != '\0'));
            pcVar5 = pcVar5 + 1) {
          *pcVar5 = pcVar5[(param_1 - (longlong)pcVar3) + 0x24];
          lVar6 = lVar6 + -1;
        }
        pcVar4 = pcVar5 + -1;
        if (lVar6 != 0) {
          pcVar4 = pcVar5;
        }
        iVar1 = -0x7ffffffb;
        if (lVar6 != 0) {
          iVar1 = 0;
        }
        *pcVar4 = '\0';
      }
      ExReleaseFastMutex(param_1 + 0x438);
      if (-1 < iVar1) {
        RtlInitAnsiString(&local_a8,pcVar3);
        uVar7 = CONCAT71((int7)((ulonglong)uVar7 >> 8),1);
        uStack_b0 = 0;
        iVar1 = RtlAnsiStringToUnicodeString(&local_b8,&local_a8);
        if (iVar1 < 0) {
          WriteDbgTraceWarning
                    ("WritePortDescription",
                     L"USBPRINT.SYS: WritePortDescription; DeviceIdString conversion failed.",uVar7,
                     param_4);
        }
        else {
          ZwSetValueKey(uVar8,&local_88,0,1,uStack_b0,(ushort)local_b8 + 2);
          RtlFreeUnicodeString(&local_b8);
        }
      }
      ExFreePool(pcVar3);
    }
    param_2 = local_res10;
  }
  RtlInitUnicodeString(&local_78,L"USB");
  RtlInitUnicodeString(&local_98,L"Base Name");
  ZwSetValueKey(uVar8,&local_98,0,1,uStack_70,(ushort)local_78 + 2);
  RtlInitUnicodeString(&local_98,L"Port Number");
  ZwSetValueKey(uVar8,&local_98,0,4,param_1 + 0x5b8,4);
  if (*(char *)(param_1 + 0x4b2) != '\0') {
    RtlInitUnicodeString(&local_68,param_1 + 0x472);
    RtlInitUnicodeString(&local_58,L"Serial Number");
    ZwSetValueKey(uVar8,&local_58,0,1,uStack_60,(ushort)local_68 + 2);
  }
  lVar6 = *(longlong *)(param_1 + 0x588 + (longlong)param_2 * 8);
  if (lVar6 != 0) {
    local_res8[0] = (uint)*(byte *)(lVar6 + 2);
    RtlInitUnicodeString(&local_48,L"Interface Number");
    ZwSetValueKey(uVar8,&local_48,0,4,local_res8,4);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 1400047f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (longlong param_1,ulonglong param_2,undefined4 param_3)

{
  bool bVar1;
  undefined7 extraout_var;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  undefined4 local_res18 [4];
  
  uVar2 = (uint)param_2 & 1;
  switch(param_3) {
  case 1:
    uVar4 = (uVar2 ^ 1) << 2;
    break;
  case 2:
    uVar4 = (uVar2 ^ 1) * 4 + 1;
    break;
  case 3:
    uVar4 = (uVar2 ^ 1) * 4 + 2;
    break;
  case 4:
    uVar4 = (uVar2 ^ 1) * 4 + 3;
    break;
  case 5:
    uVar4 = (uVar2 ^ 1) * 2 + 8;
    break;
  case 6:
    uVar4 = (uVar2 ^ 1) * 2 + 9;
    break;
  default:
    bVar5 = (byte)param_3;
    if ((99 < bVar5) && (bVar5 < 0x96)) {
      iVar3 = 100;
      if ((param_2 & 1) == 0) {
        iVar3 = 0x96;
      }
      uVar4 = iVar3 + (uint)(byte)(bVar5 + 0x9c);
      break;
    }
  case 0:
    uVar4 = 0xff;
  }
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(param_1,param_2,uVar4);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (*(undefined4 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0,uVar2,local_res18,0
               ,0,1);
  }
  return;
}



===== USBPRINT_Get1284Id @ 140004910 =====

uint USBPRINT_Get1284Id(longlong param_1,undefined1 *param_2,int param_3,undefined8 param_4)

{
  byte bVar1;
  uint uVar2;
  longlong lVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined8 local_res8;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  if (*(int *)(lVar3 + 0x424) == 4) {
    lVar3 = *(longlong *)(lVar3 + 0x590);
  }
  else {
    lVar3 = *(longlong *)(lVar3 + 0x588);
  }
  bVar1 = *(byte *)(lVar3 + 2);
  uVar6 = 0x50425355;
  puVar4 = (undefined4 *)ExAllocatePool2(0x40);
  if (puVar4 == (undefined4 *)0x0) {
    WriteDbgTraceWarning
              ("USBPRINT_Get1284Id",L"USBPRINT.SYS: Error;  urb allocation failed",uVar6,param_4);
    return 0xffffffff;
  }
  *puVar4 = 0x1b0088;
  puVar4[9] = param_3;
  *(undefined1 **)(puVar4 + 10) = param_2;
  *(undefined8 *)(puVar4 + 0xc) = 0;
  puVar4[0x20] = 0;
  *(undefined8 *)(puVar4 + 0xe) = 0;
  *(ushort *)(puVar4 + 0x21) = (ushort)bVar1 << 8;
  puVar4[8] = 3;
  local_res8 = 0xfffffffffd050f80;
  uVar2 = USBPRINT_CallUSBD(param_1,puVar4,&local_res8,param_4);
  if (((int)uVar2 < 0) || ((uint)puVar4[9] < 3)) {
    WriteDbgTraceWarning
              ("USBPRINT_Get1284Id",L"USBPRINT.SYS: Error;  CallUSBD failed 0x%x",(ulonglong)uVar2,
               param_4);
  }
  else {
    uVar2 = (uint)CONCAT11(*param_2,param_2[1]);
    uVar5 = Feature_352741691__private_IsEnabledDeviceUsageNoInline();
    if (((char)uVar5 != '\0') && ((int)puVar4[9] < (int)uVar2)) {
      uVar2 = puVar4[9];
    }
    if ((0 < (int)uVar2) && ((int)uVar2 < param_3)) {
      param_2[(int)uVar2] = 0;
      goto LAB_140004a15;
    }
  }
  uVar2 = 0xffffffff;
LAB_140004a15:
  ExFreePool(puVar4);
  return uVar2;
}



===== USBPRINT_ProcessIOCTL @ 140004a60 =====

uint * USBPRINT_ProcessIOCTL(longlong param_1,longlong param_2,undefined8 param_3,byte *param_4)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  undefined1 uVar4;
  byte bVar5;
  byte *_Dst;
  char *pcVar6;
  bool bVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined1 *puVar11;
  longlong lVar12;
  undefined4 *puVar13;
  longlong lVar14;
  undefined8 uVar15;
  undefined1 uVar16;
  IMAGE_DOS_HEADER *pIVar17;
  wchar_t *pwVar18;
  uint *puVar19;
  uint *_Size;
  uint *puVar20;
  undefined8 local_res18;
  longlong local_res20;
  uint local_68 [4];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  uVar10 = USBPRINT_CheckIncrementIoCount(param_1,param_2,param_3,param_4);
  if ((int)uVar10 < 0) {
    *(int *)(param_2 + 0x30) = (int)uVar10;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    return (uint *)(uVar10 & 0xffffffff);
  }
  _Size = *(uint **)(param_2 + 0xb8);
  _Dst = *(byte **)(param_2 + 0x18);
  uVar8 = _Size[6];
  uVar9 = _Size[2];
  lVar14 = *(longlong *)(param_1 + 0x40);
  if (uVar8 < 0x220025) {
    if (uVar8 == 0x220024) {
      local_res18 = (ulonglong)local_res18._4_4_ << 0x20;
      WriteDbgTraceInfo("USBPRINT_ProcessIOCTL",L"USBPRINT.SYS: Reset Device Test",_Size,param_4);
      uVar8 = USBPRINT_GetPortStatus(param_1,(uint *)&local_res18);
      puVar19 = (uint *)(ulonglong)uVar8;
      if (((-1 < (int)uVar8) && ((local_res18 & 1) == 0)) && ((local_res18 & 2) != 0)) {
        WriteDbgTraceInfo("USBPRINT_ProcessIOCTL",L"USBPRINT.SYS: Resetting port",_Size,param_4);
        local_58 = 0;
        uStack_50 = 0;
        local_48 = 0;
        local_68[0] = 0;
        local_68[1] = 0;
        local_68[2] = 0;
        local_68[3] = 0;
        WriteDbgTraceInfo("USBPRINT_ResetParentPort",L"USBPRINT.SYS: enter USBPRINT_ResetPort",_Size
                          ,param_4);
        lVar14 = *(longlong *)(param_1 + 0x40);
        KeInitializeEvent(&local_58,0);
        param_4 = (byte *)0x0;
        uVar15 = 0;
        lVar12 = IoBuildDeviceIoControlRequest
                           (0x220007,*(undefined8 *)(lVar14 + 8),0,0,0,0,1,&local_58,local_68);
        if (lVar12 == 0) {
          uVar9 = 0xc0000017;
LAB_140004c92:
          local_68[0] = uVar9;
        }
        else {
          WriteDbgTraceInfo("USBPRINT_ResetParentPort",L"USBPRINT.SYS: calling USBD enable port api"
                            ,uVar15,param_4);
          uVar9 = IofCallDriver(*(undefined8 *)(lVar14 + 8),lVar12);
          uVar10 = (ulonglong)uVar9;
          WriteDbgTraceInfo("USBPRINT_ResetParentPort",
                            L"USBPRINT.SYS: return from IoCallDriver USBD (in reset parent port)%x",
                            uVar10,param_4);
          if (uVar9 != 0x103) goto LAB_140004c92;
          WriteDbgTraceInfo("USBPRINT_ResetParentPort",L"USBPRINT.SYS: Wait for single object",
                            uVar10,param_4);
          param_4 = (byte *)0x0;
          uVar9 = KeWaitForSingleObject(&local_58,5,0,0,0);
          WriteDbgTraceInfo("USBPRINT_ResetParentPort",
                            L"USBPRINT.SYS: Wait for single object, returned %x",(ulonglong)uVar9,
                            param_4);
          uVar9 = local_68[0];
        }
        _Size = (uint *)(ulonglong)uVar9;
        WriteDbgTraceInfo("USBPRINT_ResetParentPort",L"USBPRINT.SYS: USBPRINT_ResetPort (%x)",_Size,
                          param_4);
        *(uint *)(param_2 + 0x30) = uVar8;
        goto LAB_1400055f0;
      }
    }
    else {
      if (uVar8 != 0x16000c) goto switchD_140004d70_caseD_220031;
      if (uVar9 <= uVar9 + 3) {
        uVar9 = uVar9 + 3;
      }
      puVar11 = (undefined1 *)ExAllocatePool2(0x40,uVar9,0x50425355);
      if (puVar11 == (undefined1 *)0x0) {
        puVar19 = (uint *)0xc0000017;
      }
      else {
        uVar10 = (ulonglong)(uVar9 - 1);
        uVar8 = USBPRINT_Get1284Id(param_1,puVar11,uVar9 - 1,param_4);
        if (0 < (int)uVar8) {
          _Size = (uint *)(longlong)(int)(uVar8 - 1);
          *(uint **)(param_2 + 0x38) = _Size;
          puVar11[(int)uVar8] = 0;
          memmove(_Dst,puVar11 + 2,(size_t)_Size);
          puVar19 = (uint *)0x0;
          ExFreePool(puVar11);
          *(undefined4 *)(param_2 + 0x30) = 0;
          goto LAB_1400055f0;
        }
        WriteDbgTraceInfo("USBPRINT_ProcessIOCTL",
                          L"USBPRINT.SYS: Failure in IOCTL_PAR_QUERY_DEVICE_ID",uVar10,param_4);
        puVar19 = (uint *)0xc000009c;
        ExFreePool(puVar11);
      }
      _Size = puVar19;
      WriteDbgTraceInfo("USBPRINT_ProcessIOCTL",L"USBPRINT.SYS: Exit IOCTL_PAR_QUERY_DEVICE_ID 0x%x"
                        ,puVar19,param_4);
    }
    goto LAB_1400055db;
  }
  pIVar17 = &IMAGE_DOS_HEADER_140000000;
  switch(uVar8) {
  case 0x220030:
    if (uVar9 == 0) {
      pwVar18 = L"USBPRINT.SYS: Buffer too small in GET_LPT_STATUS";
LAB_140004ea5:
      WriteDbgTraceWarning("USBPRINT_ProcessIOCTL",pwVar18,_Size,param_4);
      puVar19 = (uint *)0xc0000023;
      goto LAB_1400055e9;
    }
    local_res18 = local_res18 & 0xffffffffffffff00;
    local_68[0] = 0xfd050f80;
    local_68[1] = 0xffffffff;
    if (*(int *)(lVar14 + 0x424) == 4) {
      lVar14 = *(longlong *)(lVar14 + 0x590);
    }
    else {
      lVar14 = *(longlong *)(lVar14 + 0x588);
    }
    bVar5 = *(byte *)(lVar14 + 2);
    _Size = (uint *)0x50425355;
    puVar13 = (undefined4 *)ExAllocatePool2(0x40);
    if (puVar13 != (undefined4 *)0x0) {
      *puVar13 = 0x1b0088;
      puVar13[9] = 1;
      *(undefined8 *)(puVar13 + 0xc) = 0;
      puVar13[0x20] = 0x100;
      *(undefined8 **)(puVar13 + 10) = &local_res18;
      *(ushort *)(puVar13 + 0x21) = (ushort)bVar5;
      puVar13[8] = 3;
      *(undefined8 *)(puVar13 + 0xe) = 0;
      uVar8 = USBPRINT_CallUSBD(param_1,puVar13,local_68,param_4);
      _Size = (uint *)(ulonglong)(uint)puVar13[1];
      WriteDbgTraceInfo("USBPRINT_GetLptStatus",L"USBPRINT.SYS: urb->Hdr.Status=%d",_Size,param_4);
      ExFreePool(puVar13);
      if (-1 < (int)uVar8) {
        WriteDbgTraceInfo("USBPRINT_GetLptStatus",L"USBPRINT.SYS: CallUSBD succeeded",_Size,param_4)
        ;
        puVar19 = (uint *)0x0;
        *_Dst = (byte)local_res18;
        *(undefined8 *)(param_2 + 0x38) = 1;
        *(undefined4 *)(param_2 + 0x30) = 0;
        goto LAB_1400055f0;
      }
      WriteDbgTraceWarning("USBPRINT_GetLptStatus",L"USBPRINT.SYS: CallUSBD failed",_Size,param_4);
    }
    pwVar18 = L"USBPRINT.SYS: Failure in GET_LPT_STATUS";
    goto LAB_140004eea;
  default:
switchD_140004d70_caseD_220031:
    puVar19 = (uint *)0xc0000010;
    goto LAB_1400055e9;
  case 0x220034:
    if (uVar9 == 0) {
      pwVar18 = L"USBPRINT.SYS: Buffer too small in GET_1284_ID";
      goto LAB_140004ea5;
    }
    _Size = (uint *)(ulonglong)uVar9;
    uVar8 = USBPRINT_Get1284Id(param_1,_Dst,uVar9,param_4);
    if (-1 < (int)uVar8) {
      *_Dst = (byte)uVar8;
      puVar19 = (uint *)0x0;
      *(longlong *)(param_2 + 0x38) = (longlong)(int)uVar8;
      *(undefined4 *)(param_2 + 0x30) = 0;
      goto LAB_1400055f0;
    }
    pwVar18 = L"USBPRINT.SYS: Failure in GET_1284_ID";
LAB_140004eea:
    WriteDbgTraceWarning("USBPRINT_ProcessIOCTL",pwVar18,_Size,param_4);
    puVar19 = (uint *)0xc000009c;
    break;
  case 0x220038:
    local_res18 = CONCAT44(local_res18._4_4_,_Size[4]);
    if ((_Dst == (byte *)0x0) || (_Size[4] < 3)) {
LAB_14000510d:
      puVar19 = (uint *)0xc000000d;
      *(undefined8 *)(param_2 + 0x38) = 0;
    }
    else {
      _Size = (uint *)0x50425355;
      puVar13 = (undefined4 *)ExAllocatePool2(0x40);
      if (puVar13 == (undefined4 *)0x0) {
        puVar19 = (uint *)0xc0000017;
        *(undefined8 *)(param_2 + 0x38) = 0;
      }
      else {
        bVar5 = _Dst[1];
        bVar3 = _Dst[2];
        if (*(int *)(lVar14 + 0x424) == 4) {
          lVar14 = *(longlong *)(lVar14 + 0x590);
        }
        else {
          lVar14 = *(longlong *)(lVar14 + 0x588);
        }
        uVar16 = *(undefined1 *)(lVar14 + 2);
        uVar4 = *(undefined1 *)(lVar14 + 3);
        *(byte *)((longlong)puVar13 + 0x81) = *_Dst;
        _Size = local_68;
        *(ushort *)(puVar13 + 0x21) = CONCAT11(uVar16,uVar4);
        *(ushort *)((longlong)puVar13 + 0x82) = CONCAT11(bVar5,bVar3);
        *puVar13 = 0x180088;
        puVar13[9] = (uint)local_res18;
        *(undefined8 *)(puVar13 + 0xc) = 0;
        *(byte **)(puVar13 + 10) = _Dst;
        *(undefined1 *)(puVar13 + 0x20) = 0;
        puVar13[8] = 0;
        *(undefined8 *)(puVar13 + 0xe) = 0;
        local_68[0] = 0xfd050f80;
        local_68[1] = 0xffffffff;
        uVar8 = USBPRINT_CallUSBD(param_1,puVar13,_Size,param_4);
        puVar19 = (uint *)(ulonglong)uVar8;
        ExFreePool(puVar13);
        *(undefined8 *)(param_2 + 0x38) = 0;
      }
    }
    break;
  case 0x22003c:
    uVar10 = HPUsbIOCTLVendorGetCommand(param_1,param_2,_Size,param_4);
    puVar19 = (uint *)(uVar10 & 0xffffffff);
    break;
  case 0x220040:
    WriteDbgTraceInfo("USBPRINT_SoftReset",L"USBPRINT.SYS: enter USBPRINT_SoftReset",_Size,param_4);
    lVar14 = *(longlong *)(param_1 + 0x40);
    if (*(int *)(lVar14 + 0x424) == 4) {
      lVar14 = *(longlong *)(lVar14 + 0x590);
    }
    else {
      lVar14 = *(longlong *)(lVar14 + 0x588);
    }
    bVar5 = *(byte *)(lVar14 + 2);
    _Size = (uint *)0x50425355;
    puVar13 = (undefined4 *)ExAllocatePool2(0x40);
    if (puVar13 == (undefined4 *)0x0) {
      WriteDbgTraceWarning
                ("USBPRINT_SoftReset",L"USBPRINT.SYS: Error;  urb allocation failed",_Size,param_4);
      puVar19 = (uint *)0xc0000017;
      *(undefined8 *)(param_2 + 0x38) = 0;
    }
    else {
      *puVar13 = 0x1b0088;
      _Size = (uint *)&local_res18;
      *(undefined8 *)(puVar13 + 8) = 2;
      *(undefined8 *)(puVar13 + 0xc) = 0;
      *(undefined8 *)(puVar13 + 10) = 0;
      puVar13[0x20] = 0x200;
      *(ushort *)(puVar13 + 0x21) = (ushort)bVar5 << 8;
      *(undefined8 *)(puVar13 + 0xe) = 0;
      local_res18 = 0xfffffffffd050f80;
      uVar8 = USBPRINT_CallUSBD(param_1,puVar13,_Size,param_4);
      puVar19 = (uint *)(ulonglong)uVar8;
      if (((int)uVar8 < 0) || ((uint)puVar13[9] < 3)) {
        WriteDbgTraceWarning
                  ("USBPRINT_SoftReset",L"USBPRINT.SYS: Error;  CallUSBD failed",_Size,param_4);
        ExFreePool(puVar13);
        *(undefined8 *)(param_2 + 0x38) = 0;
      }
      else {
        WriteDbgTraceInfo("USBPRINT_SoftReset",L"USBPRINT.SYS: CallUSBD succeeded",_Size,param_4);
        ExFreePool(puVar13);
        *(undefined8 *)(param_2 + 0x38) = 0;
      }
    }
    break;
  case 0x220044:
    if (uVar9 == 0) {
      pwVar18 = L"USBPRINT.SYS: Buffer too small in GET_PROTOCOL";
      goto LAB_140004ea5;
    }
    puVar19 = (uint *)0x0;
    *_Dst = *(byte *)(lVar14 + 0x424);
    *(undefined8 *)(param_2 + 0x38) = 1;
    break;
  case 0x220048:
    bVar5 = *_Dst;
    puVar20 = (uint *)(ulonglong)bVar5;
    puVar19 = (uint *)0x0;
    if ((bVar5 - 2 & 0xfd) == 0) {
      if (bVar5 == *(byte *)(lVar14 + 0x424)) {
LAB_140005448:
        *(undefined8 *)(param_2 + 0x38) = 1;
        break;
      }
      local_res20 = 0;
      bVar7 = bVar5 != 2;
      puVar19 = (uint *)(ulonglong)bVar7;
      if (bVar5 == 2) {
        if (*(char *)(lVar14 + 0x428) == '\0') {
          puVar19 = (uint *)0xc00000bb;
        }
        else {
LAB_14000534f:
          LOCK();
          iVar2 = *(int *)(lVar14 + 0x42c);
          *(int *)(lVar14 + 0x42c) = 1;
          UNLOCK();
          if (iVar2 != 1) {
            uVar10 = Feature_3186517304__private_IsEnabledDeviceUsageNoInline();
            if (((char)uVar10 == '\0') ||
               (uVar8 = USBPRINT_DrainPipeUsers
                                  (param_1,pIVar17,(undefined8 *)_Size,(ulonglong)param_4),
               uVar8 == 0)) {
              _Size = (uint *)&local_res20;
              uVar8 = USBPRINT_GetUSBConfigs(param_1,pIVar17,(longlong *)_Size,param_4);
              uVar9 = (uint)bVar7;
              if (local_res20 != 0) {
                if (-1 < (int)uVar8) {
                  _Size = puVar19;
                  uVar8 = USBPRINT_SelectInterface(param_1,local_res20,uVar9);
                }
                ExFreePool(local_res20);
              }
              if (-1 < (int)uVar8) {
                uVar15 = USBPRINT_BuildPipeList(param_1,uVar9,_Size,param_4);
                uVar8 = (uint)uVar15;
                if (-1 < (int)uVar8) {
                  lVar12 = 0x5a8;
                  if (bVar5 == 2) {
                    lVar12 = 0x5b0;
                  }
                  *(undefined8 *)(lVar12 + lVar14) =
                       *(undefined8 *)(lVar14 + 0x5a8 + (longlong)puVar19 * 8);
                  lVar12 = 0x598;
                  if (bVar5 == 2) {
                    lVar12 = 0x5a0;
                  }
                  *(undefined8 *)(lVar12 + lVar14) =
                       *(undefined8 *)(lVar14 + 0x598 + (longlong)puVar19 * 8);
                }
              }
            }
            else {
              if (uVar8 == 0x102) {
                uVar8 = 0xc00000b5;
              }
              _Size = (uint *)(ulonglong)uVar8;
              WriteDbgTraceWarning
                        ("USBPrint_SwitchProtocol",
                         L"USBPRINT.SYS: SwitchProtocol aborted, I/O drain failed 0x%x",_Size,
                         param_4);
            }
            puVar19 = (uint *)(ulonglong)uVar8;
            LOCK();
            *(undefined4 *)(lVar14 + 0x42c) = 0;
            UNLOCK();
            if ((int)uVar8 < 0) break;
            goto LAB_140005448;
          }
          puVar19 = (uint *)0x80000011;
        }
      }
      else if (bVar5 == 4) {
        if (*(char *)(lVar14 + 0x429) != '\0') goto LAB_14000534f;
        puVar19 = (uint *)0xc00000bb;
      }
      else {
        puVar19 = (uint *)0xc00000bb;
      }
    }
    else {
      WriteDbgTraceWarning
                ("USBPRINT_ProcessIOCTL",L"USBPRINT.SYS: Invalid protocol %d in SET_PROTOCOL",
                 puVar20,param_4);
      puVar19 = (uint *)0xc000000d;
      _Size = puVar20;
    }
LAB_1400055e9:
    *(int *)(param_2 + 0x30) = (int)puVar19;
    goto LAB_1400055ec;
  case 0x22004c:
    if (uVar9 == 0) {
      pwVar18 = L"USBPRINT.SYS: Buffer too small in GET_INTERFACE_TYPE";
      goto LAB_140004ea5;
    }
    if (*(char *)(lVar14 + 0x428) == '\0') {
      if (*(char *)(lVar14 + 0x429) != '\0') {
        *_Dst = 2;
      }
      *(undefined8 *)(param_2 + 0x38) = 1;
      puVar19 = (uint *)0x0;
    }
    else if (*(char *)(lVar14 + 0x429) == '\0') {
      *_Dst = 1;
      puVar19 = (uint *)0x0;
      *(undefined8 *)(param_2 + 0x38) = 1;
    }
    else {
      *_Dst = 3;
      puVar19 = (uint *)0x0;
      *(undefined8 *)(param_2 + 0x38) = 1;
    }
    break;
  case 0x220050:
    puVar19 = (uint *)0x0;
    if (0x3e6 < *(int *)_Dst - 1U) goto LAB_14000510d;
    *(int *)(lVar14 + 0x5b8) = *(int *)_Dst;
    local_68[0] = 0;
    local_68[1] = 0;
    local_68[2] = 0;
    local_68[3] = 0;
    RtlInitUnicodeString(local_68,L"Port Number");
    param_4 = (byte *)0x4;
    _Size = (uint *)0x0;
    ZwSetValueKey(*(undefined8 *)(lVar14 + 0x5c0));
    *(undefined8 *)(param_2 + 0x38) = 0;
    break;
  case 0x220054:
    puVar19 = (uint *)0x0;
    *(byte *)(lVar14 + 0x470) = *_Dst & 3;
    *(undefined4 *)(param_2 + 0x30) = 0;
    goto LAB_1400055ec;
  case 0x220058:
    _Size = (uint *)(ulonglong)_Size[4];
    uVar8 = USBPRINT_SetDeviceID(lVar14,_Dst,(char *)_Size,param_4);
    puVar19 = (uint *)(ulonglong)uVar8;
    *(undefined8 *)(param_2 + 0x38) = 0;
    break;
  case 0x22005c:
    uVar10 = Feature_2524085560__private_IsEnabledDeviceUsageNoInline();
    if (((char)uVar10 == '\0') &&
       (uVar10 = Feature_932690235__private_IsEnabledDeviceUsageNoInline(), (char)uVar10 != '\0')) {
      ExAcquireFastMutex(lVar14 + 0x438);
      uVar8 = *(byte *)(lVar14 + 0x470) & 1;
      uVar16 = (undefined1)uVar8;
      WritePortDescription(lVar14,uVar8,_Size,param_4);
      ExReleaseFastMutex(lVar14 + 0x438);
      uVar8 = USBPRINT_AddChildDevice(param_1,uVar16);
      puVar19 = (uint *)(ulonglong)uVar8;
      *(undefined8 *)(param_2 + 0x38) = 0;
    }
    else {
      uVar8 = *(byte *)(lVar14 + 0x470) & 1;
      uVar16 = (undefined1)uVar8;
      WritePortDescription(lVar14,uVar8,_Size,param_4);
      uVar8 = USBPRINT_AddChildDevice(param_1,uVar16);
      puVar19 = (uint *)(ulonglong)uVar8;
      *(undefined8 *)(param_2 + 0x38) = 0;
    }
    break;
  case 0x220060:
    local_res18 = (ulonglong)local_res18._4_4_ << 0x20;
    uVar8 = USBPRINT_GetPortStatus(param_1,(uint *)&local_res18);
    puVar19 = (uint *)(ulonglong)uVar8;
    if ((-1 < (int)uVar8) && ((local_res18 & 2) != 0)) {
      uVar10 = Feature_1869851963__private_IsEnabledDeviceUsageNoInline();
      if ((char)uVar10 != '\0') {
        *(undefined1 *)(lVar14 + 0x564) = 0;
      }
      lVar14 = *(longlong *)(param_1 + 0x40);
      local_48 = 0;
      local_58 = 0;
      uStack_50 = 0;
      local_68[0] = 0;
      local_68[1] = 0;
      local_68[2] = 0;
      local_68[3] = 0;
      KeInitializeEvent(&local_58,0,0);
      param_4 = (byte *)0x0;
      lVar12 = IoBuildDeviceIoControlRequest
                         (0x22001f,*(undefined8 *)(lVar14 + 8),0,0,0,0,1,&local_58,local_68);
      if (lVar12 == 0) {
        local_68[0] = 0xc0000017;
        uVar9 = 0xc0000017;
      }
      else {
        uVar9 = IofCallDriver(*(undefined8 *)(lVar14 + 8),lVar12);
        if (uVar9 == 0x103) {
          param_4 = (byte *)0x0;
          KeWaitForSingleObject(&local_58,5,0,0,0);
          uVar9 = local_68[0];
        }
        else {
          local_68[0] = uVar9;
        }
      }
      _Size = (uint *)(ulonglong)uVar9;
      WriteDbgTraceInfo("USBPRINT_CycleParentPort",L"USBPRINT.SYS: USBPRINT_CycleParentPort (%x)",
                        _Size,param_4);
      *(uint *)(param_2 + 0x30) = uVar8;
      goto LAB_1400055f0;
    }
    break;
  case 0x220064:
    if (uVar9 == 0) {
      pwVar18 = L"USBPRINT.SYS: Buffer too small in GET_MFG_MDL_ID";
      goto LAB_140004ea5;
    }
    puVar19 = (uint *)0xc000009c;
    if ((*(char *)(lVar14 + 0x428) == '\0') && (*(char *)(lVar14 + 0x429) != '\0')) {
      _Size = (uint *)&local_res18;
      local_res18 = CONCAT44(local_res18._4_4_,uVar9);
      uVar10 = Make1284IdStringFromUsbStrings(param_1,_Dst,_Size,param_4);
      puVar19 = (uint *)(uVar10 & 0xffffffff);
      if (-1 < (int)uVar10) {
        *(ulonglong *)(param_2 + 0x38) = local_res18 & 0xffffffff;
        *(int *)(param_2 + 0x30) = (int)uVar10;
        goto LAB_1400055f0;
      }
    }
    WriteDbgTraceWarning
              ("USBPRINT_ProcessIOCTL",L"USBPRINT.SYS: Failure in GET_MFG_MDL_ID",_Size,param_4);
  }
LAB_1400055db:
  *(int *)(param_2 + 0x30) = (int)puVar19;
  if ((int)puVar19 < 0) {
LAB_1400055ec:
    *(undefined8 *)(param_2 + 0x38) = 0;
  }
LAB_1400055f0:
  uVar15 = 0;
  IofCompleteRequest(param_2);
  pcVar6 = *(char **)(param_1 + 0x40);
  if (*pcVar6 == '\0') {
    LOCK();
    piVar1 = (int *)(pcVar6 + 0x560);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      if (*(int *)(pcVar6 + 0x5bc) == 0) {
        USBPRINT_FdoSubmitIdleRequestIrp(param_1,uVar15,_Size,param_4);
      }
      KeSetEvent(pcVar6 + 0x548,1);
    }
  }
  return puVar19;
}



===== USBPRINT_AsyncReadWrite_Complete @ 140005680 =====

int USBPRINT_AsyncReadWrite_Complete(longlong param_1,undefined *param_2,wchar_t *param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  char *pcVar5;
  ulonglong uVar6;
  longlong *plVar7;
  longlong lVar8;
  longlong lVar9;
  wchar_t *pwVar10;
  code *pcVar11;
  int iVar12;
  wchar_t *pwVar13;
  longlong *plVar14;
  bool bVar15;
  
  lVar3 = *(longlong *)param_3;
  lVar4 = *(longlong *)(param_3 + 8);
  plVar14 = (longlong *)(ulonglong)*(uint *)(lVar3 + 0x24);
  lVar9 = *(longlong *)(lVar4 + 0x40);
  pwVar10 = (wchar_t *)param_2;
  pwVar13 = param_3;
  if (*(uint *)(lVar3 + 0x24) != 0) {
    pwVar13 = L"Write";
    if ((char)param_3[4] == '\0') {
      pwVar13 = L"Read";
    }
    pwVar10 = L"USBPRINT.SYS:  Async Completion: %ws Length %d, Status 0x%08X";
    WriteDbgTraceInfo("USBPRINT_AsyncReadWrite_Complete",
                      L"USBPRINT.SYS:  Async Completion: %ws Length %d, Status 0x%08X",pwVar13,
                      plVar14);
  }
  iVar12 = *(int *)(lVar3 + 4);
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)*(uint *)(lVar3 + 0x24);
  uVar6 = Feature_3186517304__private_IsEnabledDeviceUsageNoInline();
  if (((((char)uVar6 == '\0') ||
       ((*(int *)(lVar3 + 4) != -0x3fff0000 && (*(int *)(lVar3 + 4) != -0x3fff9000)))) &&
      (iVar12 < 0)) &&
     (((iVar12 != -0x3ffffee0 && (iVar12 != -0x3fffff63)) && (iVar12 != -0x3fffffaa)))) {
    LOCK();
    bVar15 = *(int *)(lVar9 + 0x5d0) == 0;
    if (bVar15) {
      *(int *)(lVar9 + 0x5d0) = 1;
    }
    UNLOCK();
    if (bVar15) {
      pwVar13 = (wchar_t *)0x50425355;
      plVar7 = (longlong *)ExAllocatePool2(0x40);
      if (plVar7 == (longlong *)0x0) {
        pwVar10 = L"USBPRINT.SYS: Unable to allocate WorkItemObj in ReadWrite_Complete";
        WriteDbgTraceWarning
                  ("USBPRINT_AsyncReadWrite_Complete",
                   L"USBPRINT.SYS: Unable to allocate WorkItemObj in ReadWrite_Complete",pwVar13,
                   plVar14);
      }
      else {
        lVar8 = IoAllocateWorkItem(param_1);
        *plVar7 = lVar8;
        if (lVar8 == 0) {
          pwVar10 = L"USBPRINT.SYS: Unable to allocate IoAllocateWorkItem in ReadWrite_Complete";
          WriteDbgTraceWarning
                    ("USBPRINT_AsyncReadWrite_Complete",
                     L"USBPRINT.SYS: Unable to allocate IoAllocateWorkItem in ReadWrite_Complete",
                     pwVar13,plVar14);
          ExFreePool(plVar7);
        }
        else {
          lVar8 = *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x20);
          plVar7[3] = (longlong)param_2;
          plVar7[1] = param_1;
          if ((char)param_3[4] == '\0') {
            lVar9 = *(longlong *)(lVar9 + 0x5a8 + lVar8 * 8);
          }
          else {
            lVar9 = *(longlong *)(lVar9 + 0x598 + lVar8 * 8);
          }
          plVar7[2] = lVar9;
          USBPRINT_IncrementIoCount(lVar4);
          pcVar11 = USBPRINT_ResetWorkItem;
          pwVar13 = (wchar_t *)0x1;
          IoQueueWorkItem(*plVar7);
          iVar12 = -0x3fffffea;
          pwVar10 = (wchar_t *)pcVar11;
          plVar14 = plVar7;
        }
      }
    }
  }
  pcVar5 = *(char **)(lVar4 + 0x40);
  if (*pcVar5 == '\0') {
    LOCK();
    piVar1 = (int *)(pcVar5 + 0x560);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      if (*(int *)(pcVar5 + 0x5bc) == 0) {
        USBPRINT_FdoSubmitIdleRequestIrp(lVar4,pwVar10,pwVar13,plVar14);
      }
      KeSetEvent(pcVar5 + 0x548,1);
    }
  }
  ExFreePool(param_3);
  ExFreePool(lVar3);
  return iVar12;
}



===== USBPRINT_Close @ 1400058c0 =====

undefined8 USBPRINT_Close(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  
  pcVar3 = *(char **)(param_1 + 0x40);
  if (*pcVar3 == '\0') {
    LOCK();
    piVar1 = (int *)(pcVar3 + 0x560);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    if (iVar2 == 0) {
      KeClearEvent(pcVar3 + 0x548);
    }
  }
  lVar4 = *(longlong *)(param_1 + 0x40);
  uVar5 = Feature_1869851963__private_IsEnabledDeviceUsageNoInline();
  if ((char)uVar5 == '\0') {
    piVar1 = (int *)(lVar4 + 0x5bc);
    *piVar1 = *piVar1 + -1;
  }
  else {
    LOCK();
    piVar1 = (int *)(lVar4 + 0x5bc);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
  }
  uVar6 = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2);
  pcVar3 = *(char **)(param_1 + 0x40);
  if (*pcVar3 == '\0') {
    LOCK();
    piVar1 = (int *)(pcVar3 + 0x560);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      if (*(int *)(pcVar3 + 0x5bc) == 0) {
        USBPRINT_FdoSubmitIdleRequestIrp(param_1,uVar6,param_3,param_4);
      }
      KeSetEvent(pcVar3 + 0x548,1);
    }
  }
  return 0;
}



===== USBPRINT_Create @ 1400059a0 =====

/* WARNING: Removing unreachable block (ram,0x000140005a48) */

uint USBPRINT_Create(longlong param_1,longlong param_2,char *param_3,undefined8 param_4)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  longlong lVar4;
  undefined1 uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  uint uVar8;
  
  pcVar3 = *(char **)(param_1 + 0x40);
  uVar8 = 0;
  if (*pcVar3 == '\0') {
    LOCK();
    piVar1 = (int *)(pcVar3 + 0x560);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    if (iVar2 == 0) {
      KeClearEvent(pcVar3 + 0x548);
    }
  }
  pcVar3 = *(char **)(param_1 + 0x40);
  if (*pcVar3 == '\x01') {
    uVar8 = 0xc00000bb;
  }
  else if (pcVar3[0x564] == '\0') {
    uVar8 = 0xc0000056;
  }
  else {
    iVar2 = *(int *)(pcVar3 + 0x424);
    uVar6 = (ulonglong)(iVar2 == 4);
    lVar4 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
    if (iVar2 == 4) {
      if ((*(longlong *)(pcVar3 + 0x5a0) == 0) || (*(longlong *)(pcVar3 + 0x5b0) == 0)) {
        uVar8 = 0xc0000184;
      }
      if ((int)uVar8 < 0) goto LAB_140005b92;
    }
    else if ((*(longlong *)(pcVar3 + uVar6 * 8 + 0x598) == 0) || (iVar2 == 4)) {
      uVar8 = 0xc0000184;
      goto LAB_140005b92;
    }
    uVar5 = KeAcquireSpinLockRaiseToDpc(pcVar3 + 0x4b8);
    if (pcVar3[0x4c0] == '\0') {
      KeClearEvent(pcVar3 + 0x4c8);
      pcVar3[0x4c0] = '\x01';
      KeReleaseSpinLock(pcVar3 + 0x4b8,uVar5);
      PoRequestPowerIrp(*(undefined8 *)(pcVar3 + 0x10),2,1,0,0,0);
      param_4 = 0;
      param_3 = (char *)0x0;
      KeWaitForSingleObject(pcVar3 + 0x4c8);
    }
    else {
      param_3 = pcVar3;
      WriteDbgTraceWarning
                ("USBPRINT_FdoRequestWake",
                 L"USBPRINT: USB Printer (%p) already has D0 irp pending, abort wake",pcVar3,param_4
                );
      KeReleaseSpinLock(pcVar3 + 0x4b8);
    }
    *(ulonglong *)(lVar4 + 0x20) = uVar6;
    *(undefined8 *)(lVar4 + 0x18) = 0;
    uVar6 = Feature_1869851963__private_IsEnabledDeviceUsageNoInline();
    if ((char)uVar6 == '\0') {
      *(int *)(pcVar3 + 0x5bc) = *(int *)(pcVar3 + 0x5bc) + 1;
    }
    else {
      LOCK();
      *(int *)(pcVar3 + 0x5bc) = *(int *)(pcVar3 + 0x5bc) + 1;
      UNLOCK();
    }
  }
LAB_140005b92:
  uVar7 = 0;
  *(uint *)(param_2 + 0x30) = uVar8;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2);
  pcVar3 = *(char **)(param_1 + 0x40);
  if (*pcVar3 == '\0') {
    LOCK();
    piVar1 = (int *)(pcVar3 + 0x560);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      if (*(int *)(pcVar3 + 0x5bc) == 0) {
        USBPRINT_FdoSubmitIdleRequestIrp(param_1,uVar7,param_3,param_4);
      }
      KeSetEvent(pcVar3 + 0x548,1);
    }
  }
  if ((int)uVar8 < 0) {
    WriteDbgTraceInfo("USBPRINT_Create",L"USBPRINT.SYS: exit USBPRINT_Create %x",(ulonglong)uVar8,
                      param_4);
  }
  return uVar8;
}



===== USBPRINT_GetUsbStringDescriptor @ 140005c30 =====

ulonglong USBPRINT_GetUsbStringDescriptor
                    (longlong param_1,undefined1 param_2,byte *param_3,undefined8 param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined8 local_res8;
  
  uVar5 = (undefined4)param_4;
  uVar4 = 0x50425355;
  puVar2 = (undefined4 *)ExAllocatePool2(0x40);
  if (puVar2 == (undefined4 *)0x0) {
    WriteDbgTraceWarning
              ("USBPRINT_GetUsbStringDescriptor",
               L"USBPRINT_GetStringDescriptor: urb allocation failed",uVar4,param_4);
    uVar3 = 0xffffffff;
  }
  else {
    *(undefined8 *)(puVar2 + 0xc) = 0;
    *(undefined8 *)(puVar2 + 0xe) = 0;
    *puVar2 = 0xb0088;
    puVar2[9] = uVar5;
    *(byte **)(puVar2 + 10) = param_3;
    *(undefined1 *)((longlong)puVar2 + 0x83) = 3;
    *(undefined1 *)((longlong)puVar2 + 0x82) = param_2;
    *(undefined2 *)(puVar2 + 0x21) = 0x409;
    local_res8 = 0xfffffffffd050f80;
    uVar1 = USBPRINT_CallUSBD(param_1,puVar2,&local_res8,param_4);
    if (((int)uVar1 < 0) || ((uint)puVar2[9] < 3)) {
      WriteDbgTraceWarning
                ("USBPRINT_GetUsbStringDescriptor",
                 L"USBPRINT_GetStringDescriptor: CallUSBD failed 0x%x",(ulonglong)uVar1,param_4);
      uVar3 = 0xffffffff;
    }
    else {
      uVar3 = (ulonglong)*param_3;
    }
    ExFreePool(puVar2);
  }
  return uVar3;
}



===== WriteDbgTraceWarning @ 140005d40 =====

void WriteDbgTraceWarning(char *param_1,wchar_t *param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  undefined8 uVar2;
  char *pcVar3;
  undefined8 local_res18;
  undefined8 local_res20;
  
  pcVar3 = param_1;
  local_res18 = param_3;
  local_res20 = param_4;
  cVar1 = KeGetCurrentIrql();
  if (cVar1 == '\0') {
    uVar2 = IsEnabled(pcVar3,3);
    if ((char)uVar2 != '\0') {
      DbgTraceWorker(2,param_1,param_2,(va_list)&local_res18);
    }
  }
  return;
}



===== USBPRINT_ResetWorkItem @ 140005da0 =====

void USBPRINT_ResetWorkItem
               (undefined8 param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  WriteDbgTraceInfo("USBPRINT_ResetWorkItem",L"USBPRINT.SYS: Entering USBPRINT_ResetWorkItem",
                    param_3,param_4);
  lVar1 = *(longlong *)(param_2[1] + 0x40);
  USBPRINT_ResetPipe(param_2[1],param_2[2],param_3,param_4);
  uVar3 = 0;
  IofCompleteRequest(param_2[3]);
  IoFreeWorkItem(*param_2);
  lVar2 = param_2[1];
  ExFreePool(param_2);
  LOCK();
  *(undefined4 *)(lVar1 + 0x5d0) = 0;
  UNLOCK();
  USBPRINT_DecrementIoCount(lVar2,uVar3,param_3,param_4);
  return;
}



===== USBPRINT_ProcessChildPowerIrp @ 140005e40 =====

undefined4
USBPRINT_ProcessChildPowerIrp
          (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  wchar_t *pwVar2;
  undefined4 uVar3;
  
  WriteDbgTraceInfo("USBPRINT_ProcessChildPowerIrp",L"USBPRINT.SYS: IRP_MJ_POWER for child PDO",
                    param_3,param_4);
  cVar1 = *(char *)(*(longlong *)(param_2 + 0xb8) + 1);
  if (cVar1 == '\x02') {
    pwVar2 = L"USBPRINT.SYS: IRP_MJ_POWER, IRP_MN_SET_POWER";
  }
  else {
    if (cVar1 != '\x03') {
      uVar3 = *(undefined4 *)(param_2 + 0x30);
      goto LAB_140005e98;
    }
    pwVar2 = L"USBPRINT.SYS: IRP_MJ_POWER, IRP_MN_QUERY_POWER";
  }
  WriteDbgTraceInfo("USBPRINT_ProcessChildPowerIrp",pwVar2,param_3,param_4);
  uVar3 = 0;
LAB_140005e98:
  PoStartNextPowerIrp(param_2);
  *(undefined4 *)(param_2 + 0x30) = uVar3;
  IofCompleteRequest(param_2,0);
  return uVar3;
}



===== wil_details_MapReportingKind @ 140005ed0 =====

int wil_details_MapReportingKind(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  
  if (param_1 != 0) {
    switch(param_1) {
    case 1:
      iVar1 = 0;
      if (param_2 == 0) {
        iVar1 = 4;
      }
      return iVar1;
    case 2:
      iVar1 = 1;
      if (param_2 == 0) {
        iVar1 = 5;
      }
      return iVar1;
    case 3:
      iVar1 = 2;
      if (param_2 == 0) {
        iVar1 = 6;
      }
      return iVar1;
    case 4:
      iVar1 = 3;
      if (param_2 == 0) {
        iVar1 = 7;
      }
      return iVar1;
    case 5:
      iVar1 = 8;
      if (param_2 == 0) {
        iVar1 = 10;
      }
      return iVar1;
    case 6:
      iVar1 = 9;
      if (param_2 == 0) {
        iVar1 = 0xb;
      }
      return iVar1;
    }
    bVar2 = (char)param_1 + 0x9c;
    if (bVar2 < 0x32) {
      iVar1 = 100;
      if (param_2 == 0) {
        iVar1 = 0x96;
      }
      return iVar1 + (uint)bVar2;
    }
  }
  return 0xff;
}



===== USBPRINT_PoRequestCompletion @ 140005f90 =====

void USBPRINT_PoRequestCompletion
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar1 = *(longlong *)(param_4 + 0x40);
  lVar3 = *(longlong *)(lVar1 + 0x540);
  lVar4 = param_4;
  WriteDbgTraceInfo("USBPRINT_PoRequestCompletion",L"USBPRINT_PoRequestCompletion",param_3,param_4);
  PoStartNextPowerIrp(lVar3);
  puVar2 = *(undefined8 **)(lVar3 + 0xb8);
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
  PoCallDriver(*(undefined8 *)(lVar1 + 8));
  USBPRINT_DecrementIoCount(param_4,lVar3,param_3,lVar4);
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 140006030 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_140013c17 < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== __report_gsfailure @ 140006070 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== ClearFreePorts @ 140006080 =====

void ClearFreePorts(void)

{
  if (g_pFreePortList != 0) {
    do {
      g_pFreePortList = *(longlong *)(g_pFreePortList + 8);
      ExFreePool();
    } while (g_pFreePortList != 0);
  }
  return;
}



===== DriverEntry @ 1400060c8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint DriverEntry(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  TraceLoggingRegisterEx_EtwRegister_EtwSetInformation();
  USBPRINT_DriverObject = param_1;
  *(code **)(param_1 + 0x70) = USBPRINT_Create;
  *(code **)(param_1 + 0x80) = USBPRINT_Close;
  *(code **)(param_1 + 0x68) = USBPRINT_Unload;
  *(code **)(param_1 + 0xe0) = USBPRINT_ProcessIOCTL;
  *(code **)(param_1 + 0x90) = USBPRINT_Write;
  *(code **)(param_1 + 0x88) = USBPRINT_Read;
  *(code **)(param_1 + 0x128) = USBPRINT_SystemControl;
  *(code **)(param_1 + 0x148) = USBPRINT_Dispatch;
  *(code **)(param_1 + 0x120) = USBPRINT_ProcessPowerIrp;
  *(code **)(*(longlong *)(param_1 + 0x30) + 8) = USBPRINT_PnPAddDevice;
  WriteDbgTraceInfo("DriverEntry",L"USBPRINT.SYS: entering DriverEntry",param_3,param_4);
  g_pFreePortList = 0;
  DAT_140014148 = &GUID_DEVINTERFACE_USBPRINT;
  DAT_140014158 = &GUID_DEVINTERFACE_IPPUSB_PRINT;
  _g_DevInterfaceInfo = 2;
  _DAT_140014150 = 4;
  uVar3 = Feature_PrintPlatformStabilizationFixes_2502__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 != 0) {
    memset(&g_UsbprintDevices,0,0x80);
  }
  wil_InitializeFeatureStaging();
  uVar2 = InitFreePorts();
  if ((int)uVar2 < 0) {
    ClearFreePorts();
    uVar1 = DAT_140014020;
    DAT_140014020 = 0;
    DAT_140014000 = 0;
    EtwUnregister(uVar1);
  }
  WriteDbgTraceInfo("DriverEntry",L"USBPRINT.SYS: exiting DriverEntry (%x)",(ulonglong)uVar2,param_4
                   );
  return uVar2;
}



===== Feature_2524085560__private_IsEnabledDeviceUsageNoInline @ 140006228 =====

ulonglong Feature_2524085560__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_2524085560__private_featureState;
  if ((Feature_2524085560__private_featureState & 0x10) == 0) {
    uVar1 = Feature_2524085560__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)Feature_2524085560__private_featureState & 0xffffffffffffff01;
  }
  return uVar1;
}



===== Feature_2524085560__private_IsEnabledFallback @ 140006260 =====

void Feature_2524085560__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_2524085560__private_descriptor);
  return;
}



===== Feature_3186517304__private_IsEnabledDeviceUsageNoInline @ 14000627c =====

ulonglong Feature_3186517304__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)(uint)Feature_3186517304__private_featureState;
  if (((uint)Feature_3186517304__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3186517304__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(uint)Feature_3186517304__private_featureState & 0xffffffffffffff01;
  }
  return uVar1;
}



===== Feature_3186517304__private_IsEnabledFallback @ 1400062b4 =====

void Feature_3186517304__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_3186517304__private_descriptor);
  return;
}



===== Feature_932690235__private_IsEnabledDeviceUsageNoInline @ 1400062d0 =====

ulonglong Feature_932690235__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_932690235__private_featureState;
  if ((Feature_932690235__private_featureState & 0x10) == 0) {
    uVar1 = Feature_932690235__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)Feature_932690235__private_featureState & 0xffffffffffffff01;
  }
  return uVar1;
}



===== Feature_932690235__private_IsEnabledFallback @ 140006308 =====

void Feature_932690235__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_932690235__private_descriptor);
  return;
}



===== Feature_PrintPlatformStabilizationFixes_2502__private_IsEnabledDeviceUsageNoInline @ 140006324 =====

ulonglong Feature_PrintPlatformStabilizationFixes_2502__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_PrintPlatformStabilizationFixes_2502__private_featureState;
  if ((Feature_PrintPlatformStabilizationFixes_2502__private_featureState & 0x10) == 0) {
    uVar1 = Feature_PrintPlatformStabilizationFixes_2502__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_PrintPlatformStabilizationFixes_2502__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_PrintPlatformStabilizationFixes_2502__private_IsEnabledFallback @ 14000635c =====

void Feature_PrintPlatformStabilizationFixes_2502__private_IsEnabledFallback
               (ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_PrintPlatformStabilizationFixes_2502__private_descriptor);
  return;
}



===== GetPrinterNameFrom1284Id @ 140006378 =====

ulonglong GetPrinterNameFrom1284Id
                    (void *param_1,char param_2,undefined8 *param_3,undefined8 param_4)

{
  int iVar1;
  char *_Dst;
  longlong lVar2;
  ulonglong uVar3;
  wchar_t *pwVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  wchar_t *pwVar10;
  undefined8 *puVar11;
  longlong local_res8;
  longlong local_res20;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_res8 = 0;
  local_res20 = 0;
  uVar8 = 0xc0000225;
  local_40 = 0;
  local_50 = 0;
  local_58 = 0;
  local_48 = 0;
  if (param_1 == (void *)0x0) {
    WriteDbgTraceWarning("GetPrinterNameFrom1284Id",L"USBPRINT.SYS: No 1284 id",param_3,param_4);
  }
  else {
    lVar6 = -1;
    lVar5 = -1;
    do {
      lVar2 = lVar5;
      lVar5 = lVar2 + 1;
    } while (*(char *)((longlong)param_1 + lVar5) != '\0');
    uVar9 = 0x50425355;
    _Dst = (char *)ExAllocatePool2(0x40,lVar2 + 2);
    if (_Dst == (char *)0x0) {
      WriteDbgTraceWarning
                ("GetPrinterNameFrom1284Id",
                 L"USBPRINT.SYS: Memory Allocation failed in GetPrinterNameFrom1284Id",uVar9,param_4
                );
      return 0xc0000017;
    }
    lVar5 = -1;
    do {
      lVar2 = lVar5;
      lVar5 = lVar2 + 1;
    } while (*(char *)((longlong)param_1 + lVar5) != '\0');
    memmove(_Dst,param_1,lVar2 + 2);
    puVar11 = &local_48;
    ParPnpFindDeviceIdKeys(&local_res8,&local_res20,&local_40,puVar11,&local_50,&local_58,_Dst);
    lVar5 = local_res8;
    if ((local_res8 != 0) && (local_res20 != 0)) {
      lVar2 = -1;
      do {
        lVar2 = lVar2 + 1;
      } while (*(char *)(local_res20 + lVar2) != '\0');
      do {
        lVar6 = lVar6 + 1;
      } while (*(char *)(local_res8 + lVar6) != '\0');
      iVar1 = ((int)lVar2 + (int)lVar6) * 2;
      uVar7 = (ulonglong)(iVar1 + 4);
      uVar3 = Feature_PrintPlatformStabilizationFixes_2502__private_IsEnabledDeviceUsageNoInline();
      if (((int)uVar3 != 0) && (param_2 != '\0')) {
        uVar7 = (ulonglong)(iVar1 + 0x10);
      }
      uVar9 = 0x50425355;
      pwVar4 = (wchar_t *)ExAllocatePool2(0x40,uVar7);
      if (pwVar4 == (wchar_t *)0x0) {
        WriteDbgTraceInfo("GetPrinterNameFrom1284Id",
                          L"GetPrinterNameFrom1284Id: ExAllocatePool2 failed",uVar9,puVar11);
      }
      else {
        uVar8 = Feature_PrintPlatformStabilizationFixes_2502__private_IsEnabledDeviceUsageNoInline()
        ;
        if (((int)uVar8 == 0) || (pwVar10 = L"%hs %hs (FAX)", param_2 == '\0')) {
          pwVar10 = L"%hs %hs";
        }
        uVar3 = RtlStringCbPrintfW(pwVar4,uVar7,pwVar10,lVar5);
        uVar8 = uVar3 & 0xffffffff;
        if ((int)uVar3 < 0) {
          ExFreePool(pwVar4);
          WriteDbgTraceInfo("GetPrinterNameFrom1284Id",
                            L"GetPrinterNameFrom1284Id: RtlStringCbPrintfW failed 0x%x",
                            uVar3 & 0xffffffff,lVar5);
        }
        else {
          WriteDbgTraceInfo("GetPrinterNameFrom1284Id",L"GetPrinterNameFrom1284Id: %ws",pwVar4,lVar5
                           );
          *param_3 = pwVar4;
        }
      }
    }
    ExFreePool(_Dst);
  }
  return uVar8;
}



===== GetPrinterNameFromUsbStrings @ 140006598 =====

ulonglong GetPrinterNameFromUsbStrings
                    (longlong param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  longlong lVar2;
  byte *pbVar3;
  byte *pbVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong lVar8;
  wchar_t *pwVar9;
  undefined8 uVar10;
  byte *pbVar11;
  undefined8 uVar12;
  wchar_t *pwVar13;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  uVar10 = 0x50425355;
  pbVar3 = (byte *)ExAllocatePool2(0x40,0x105);
  if (pbVar3 == (byte *)0x0) {
    pwVar9 = L"USBPRINT.SYS: Memory Allocation failed in GetPrinterNameFromUsbStrings";
  }
  else {
    uVar10 = 0x50425355;
    pbVar4 = (byte *)ExAllocatePool2(0x40,0x105);
    if (pbVar4 != (byte *)0x0) {
      uVar5 = USBPRINT_GetUsbStringDescriptor
                        (param_1,*(undefined1 *)(*(longlong *)(lVar2 + 0x4f0) + 0xe),pbVar3,0x105);
      uVar10 = 0x105;
      pbVar11 = pbVar4;
      uVar6 = USBPRINT_GetUsbStringDescriptor
                        (param_1,*(undefined1 *)(*(longlong *)(lVar2 + 0x4f0) + 0xf),pbVar4,0x105);
      lVar8 = -1;
      if (((int)uVar5 == -1) || ((int)uVar6 == -1)) {
        WriteDbgTraceInfo("GetPrinterNameFromUsbStrings",
                          L"GetPrinterNameFromUsbStrings: Failed to get USB string descriptors",
                          pbVar11,uVar10);
        uVar5 = 0xc0000225;
      }
      else {
        lVar7 = -1;
        do {
          lVar7 = lVar7 + 1;
        } while (*(short *)(pbVar3 + lVar7 * 2 + 2) != 0);
        do {
          lVar8 = lVar8 + 1;
        } while (*(short *)(pbVar4 + lVar8 * 2 + 2) != 0);
        iVar1 = ((int)lVar7 + (int)lVar8) * 2;
        uVar6 = (ulonglong)(iVar1 + 4);
        uVar5 = Feature_PrintPlatformStabilizationFixes_2502__private_IsEnabledDeviceUsageNoInline()
        ;
        if (((int)uVar5 != 0) && ((*(byte *)(lVar2 + 0x470) & 2) != 0)) {
          uVar6 = (ulonglong)(iVar1 + 0x10);
        }
        uVar12 = 0x50425355;
        pwVar9 = (wchar_t *)ExAllocatePool2(0x40,uVar6);
        if (pwVar9 == (wchar_t *)0x0) {
          WriteDbgTraceInfo("GetPrinterNameFromUsbStrings",
                            L"GetPrinterNameFromUsbStrings: ExAllocatePool2 failed",uVar12,uVar10);
          uVar5 = 0xc0000017;
        }
        else {
          uVar5 = Feature_PrintPlatformStabilizationFixes_2502__private_IsEnabledDeviceUsageNoInline
                            ();
          if ((int)uVar5 == 0) {
            pwVar13 = L"%ws %ws";
          }
          else {
            pwVar13 = L"%ws %ws (FAX)";
            if ((*(byte *)(lVar2 + 0x470) & 2) == 0) {
              pwVar13 = L"%ws %ws";
            }
          }
          pbVar11 = pbVar3 + 2;
          uVar6 = RtlStringCbPrintfW(pwVar9,uVar6,pwVar13,pbVar11);
          uVar5 = uVar6 & 0xffffffff;
          if ((int)uVar6 < 0) {
            ExFreePool(pwVar9);
            WriteDbgTraceInfo("GetPrinterNameFromUsbStrings",
                              L"GetPrinterNameFromUsbStrings: RtlStringCbPrintfW failed 0x%x",
                              uVar6 & 0xffffffff,pbVar11);
          }
          else {
            WriteDbgTraceInfo("GetPrinterNameFromUsbStrings",L"GetPrinterNameFromUsbStrings: %ws",
                              pwVar9,pbVar11);
            *param_2 = pwVar9;
          }
        }
      }
      ExFreePool(pbVar3);
      ExFreePool(pbVar4);
      return uVar5;
    }
    ExFreePool(pbVar3);
    pwVar9 = L"USBPRINT.SYS: Memory Allocation failed in GetPrinterNameFromUsbStrings.";
  }
  WriteDbgTraceWarning("GetPrinterNameFromUsbStrings",pwVar9,uVar10,param_4);
  return 0xc0000017;
}



===== GetUsbPrinterName @ 1400067e8 =====

ulonglong GetUsbPrinterName(longlong param_1,void *param_2,undefined8 *param_3,undefined8 param_4)

{
  ulonglong uVar1;
  byte bVar2;
  undefined8 *puVar3;
  
  uVar1 = Feature_PrintPlatformStabilizationFixes_2502__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar1 == 0) {
    bVar2 = 0;
  }
  else {
    bVar2 = *(byte *)(*(longlong *)(param_1 + 0x40) + 0x470) & 2;
  }
  puVar3 = param_3;
  uVar1 = GetPrinterNameFrom1284Id(param_2,bVar2,param_3,param_4);
  if ((int)uVar1 < 0) {
    uVar1 = GetPrinterNameFromUsbStrings(param_1,param_3,puVar3,param_4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



===== InitFreePorts @ 140006850 =====

uint InitFreePorts(void)

{
  longlong lVar1;
  uint uVar2;
  
  while (g_pFreePortList != (undefined4 *)0x0) {
    lVar1 = *(longlong *)((longlong)g_pFreePortList + 8);
    ExFreePool(g_pFreePortList);
    g_pFreePortList = (undefined4 *)lVar1;
  }
  g_pFreePortList = (undefined4 *)ExAllocatePool2(0x40,0x10,0x50425355);
  if (g_pFreePortList == (undefined4 *)0x0) {
    uVar2 = 0xc0000017;
  }
  else {
    *g_pFreePortList = 1;
    g_pFreePortList[1] = 999;
    *(undefined8 *)(g_pFreePortList + 2) = 0;
    uVar2 = LoadPortsUsed(0);
    if (-1 < (int)uVar2) {
      uVar2 = LoadPortsUsed(1);
      return uVar2;
    }
  }
  return uVar2;
}



===== IsProtectedPrintEnabled @ 1400068f8 =====

bool IsProtectedPrintEnabled(void)

{
  int iVar1;
  longlong lVar2;
  bool bVar3;
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
  
  bVar3 = false;
  local_44 = 0;
  local_2c = 0;
  local_res10 = 0;
  local_res8[0] = 0x14;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  lVar2 = ExAllocatePool2(0x100,0x14,0x50425355);
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
      if (-1 < iVar1) {
        bVar3 = *(int *)(lVar2 + 0xc) != 0;
      }
      ZwClose(local_res10);
    }
    ExFreePool(lVar2);
  }
  return bVar3;
}



===== LoadPortsUsed @ 140006a30 =====

uint LoadPortsUsed(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  short **ppsVar8;
  undefined8 *puVar9;
  short *psVar10;
  bool bVar11;
  undefined4 local_res8 [2];
  undefined4 local_res10 [4];
  undefined8 local_res20;
  short *local_78;
  ulonglong local_70 [7];
  
  local_78 = (short *)0x0;
  local_res8[0] = 0;
  local_res10[0] = 0;
  local_res20 = 0;
  ppsVar8 = &local_78;
  uVar7 = 1;
  uVar4 = 0;
  local_70[4] = 0;
  local_70[5] = 0;
  local_70[2] = 0;
  local_70[3] = 0;
  local_70[0] = 0;
  local_70[1] = 0;
  uVar2 = IoGetDeviceInterfaces((&DAT_140014148)[(longlong)param_1 * 2],0);
  if (uVar2 != 0) {
    WriteDbgTraceInfo("LoadPortsUsed",L"USBPRINT.SYS:  IoGetDeviceInterfaces failed",uVar7,ppsVar8);
    return uVar2;
  }
  RtlInitUnicodeString(local_70 + 4,L"Port Number");
  RtlInitUnicodeString(local_70 + 2,L"Base Name");
  psVar10 = local_78;
  puVar5 = (undefined8 *)ExAllocatePool2(0x40,0x18,0x50425355);
  uVar7 = 0x50425355;
  puVar6 = (undefined8 *)ExAllocatePool2(0x40,0x14);
  if ((puVar5 == (undefined8 *)0x0) || (puVar6 == (undefined8 *)0x0)) {
    WriteDbgTraceInfo("LoadPortsUsed",L"USBPRINT.SYS:  Unable to allocate memory",uVar7,ppsVar8);
    uVar4 = 0xc000009a;
    if (puVar5 == (undefined8 *)0x0) goto LAB_140006c97;
  }
  else {
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    *puVar6 = 0;
    puVar6[1] = 0;
    *(undefined4 *)(puVar6 + 2) = 0;
    while ((*psVar10 != 0 && (-1 < (int)uVar4))) {
      RtlInitUnicodeString(local_70,psVar10);
      iVar3 = IoOpenDeviceInterfaceRegistryKey(local_70,0xf003f,&local_res20);
      if (-1 < iVar3) {
        iVar3 = ZwQueryValueKey(local_res20,local_70 + 2,2,puVar5,0x18,local_res8);
        if (iVar3 < 0) {
          bVar11 = iVar3 == -0x3fffffcc;
        }
        else {
          iVar3 = wcscmp(L"USB",(wchar_t *)((longlong)puVar5 + 0xc));
          bVar11 = iVar3 == 0;
        }
        if ((bVar11) &&
           (puVar9 = puVar6,
           iVar3 = ZwQueryValueKey(local_res20,local_70 + 4,2,puVar6,0x14,local_res10), -1 < iVar3))
        {
          uVar2 = *(uint *)((longlong)puVar6 + 0xc);
          uVar7 = local_res20;
          cVar1 = bDeleteIfRecyclable(local_res20);
          if (cVar1 == '\0') {
            uVar4 = bAddPortInUseItem(uVar7,uVar2);
            if ((int)uVar4 < 0) {
              WriteDbgTraceInfo("LoadPortsUsed",
                                L"USBPRINT.SYS:  Unable to add port %u to port list (0x%x)",
                                (ulonglong)uVar2,(ulonglong)uVar4);
            }
          }
          else {
            WriteDbgTraceInfo("LoadPortsUsed",L"USBPRINT.SYS:  Invalid port number %u",
                              (ulonglong)uVar2,puVar9);
          }
        }
        ZwClose(local_res20);
      }
      psVar10 = psVar10 + (local_70[0] >> 1 & 0x7fff) + 1;
    }
  }
  ExFreePool(puVar5);
LAB_140006c97:
  if (puVar6 != (undefined8 *)0x0) {
    ExFreePool(puVar6);
  }
  ExFreePool(local_78);
  return uVar4;
}



===== Make1284IdStringFromUsbStrings @ 140006cec =====

ulonglong Make1284IdStringFromUsbStrings
                    (longlong param_1,undefined1 *param_2,uint *param_3,undefined8 param_4)

{
  byte *pbVar1;
  byte *pbVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  char *_Src;
  longlong lVar7;
  longlong lVar6;
  wchar_t *pwVar8;
  uint uVar9;
  undefined8 uVar10;
  byte *pbVar11;
  undefined8 uVar12;
  
  lVar5 = *(longlong *)(param_1 + 0x40);
  uVar10 = 0x50425355;
  pbVar1 = (byte *)ExAllocatePool2(0x40,0x105);
  if (pbVar1 == (byte *)0x0) {
    pwVar8 = L"USBPRINT.SYS: Memory Allocation failed in Make1284IdStringFromUsbStrings";
  }
  else {
    uVar10 = 0x50425355;
    pbVar2 = (byte *)ExAllocatePool2(0x40,0x105);
    if (pbVar2 != (byte *)0x0) {
      uVar3 = USBPRINT_GetUsbStringDescriptor
                        (param_1,*(undefined1 *)(*(longlong *)(lVar5 + 0x4f0) + 0xe),pbVar1,0x105);
      uVar10 = 0x105;
      pbVar11 = pbVar2;
      uVar4 = USBPRINT_GetUsbStringDescriptor
                        (param_1,*(undefined1 *)(*(longlong *)(lVar5 + 0x4f0) + 0xf),pbVar2,0x105);
      if (((int)uVar3 == -1) || ((int)uVar4 == -1)) {
        WriteDbgTraceInfo("Make1284IdStringFromUsbStrings",
                          L"Make1284IdStringFromUsbStrings: Failed to get USB string descriptors",
                          pbVar11,uVar10);
        uVar3 = 0xc0000225;
      }
      else {
        lVar5 = -1;
        do {
          lVar5 = lVar5 + 1;
          lVar6 = -1;
        } while (*(short *)(pbVar1 + lVar5 * 2 + 2) != 0);
        do {
          lVar7 = lVar6;
          lVar6 = lVar7 + 1;
        } while (*(short *)(pbVar2 + lVar6 * 2 + 2) != 0);
        uVar9 = (int)lVar7 + 0xc + (int)lVar5;
        if (uVar9 < 0x20a) {
          if (*param_3 < uVar9 + 2) {
            WriteDbgTraceWarning
                      ("Make1284IdStringFromUsbStrings",
                       L"USBPRINT.SYS: Output buffer is too small in Make1284IdStringFromUsbStrings"
                       ,pbVar11,uVar10);
            uVar3 = 0xc0000023;
          }
          else {
            uVar12 = 0x50425355;
            _Src = (char *)ExAllocatePool2(0x40,uVar9);
            if (_Src == (char *)0x0) {
              WriteDbgTraceInfo("Make1284IdStringFromUsbStrings",
                                L"Make1284IdStringFromUsbStrings: ExAllocatePool2 failed",uVar12,
                                uVar10);
              uVar3 = 0xc0000017;
            }
            else {
              pbVar11 = pbVar1 + 2;
              uVar4 = RtlStringCbPrintfA(_Src,(ulonglong)uVar9,"MFG:%ws;MDL:%ws;",pbVar11);
              uVar3 = uVar4 & 0xffffffff;
              if ((int)uVar4 < 0) {
                WriteDbgTraceInfo("Make1284IdStringFromUsbStrings",
                                  L"Make1284IdStringFromUsbStrings: RtlStringCbPrintfW failed 0x%x",
                                  uVar4 & 0xffffffff,pbVar11);
              }
              else {
                WriteDbgTraceInfo("Make1284IdStringFromUsbStrings",
                                  L"Make1284IdStringFromUsbStrings: %hs",_Src,pbVar11);
                *param_2 = (char)(uVar9 >> 8);
                param_2[1] = (char)uVar9;
                memmove(param_2 + 2,_Src,(ulonglong)uVar9);
                *param_3 = uVar9 + 2;
              }
              ExFreePool(_Src);
            }
          }
        }
        else {
          WriteDbgTraceInfo("Make1284IdStringFromUsbStrings",
                            L"Make1284IdStringFromUsbStrings: Encountered corrupt USB string descriptor"
                            ,pbVar11,uVar10);
          uVar3 = 0xc000009c;
        }
      }
      ExFreePool(pbVar1);
      ExFreePool(pbVar2);
      return uVar3;
    }
    ExFreePool(pbVar1);
    pwVar8 = L"USBPRINT.SYS: Memory Allocation failed in Make1284IdStringFromUsbStrings.";
  }
  WriteDbgTraceWarning("Make1284IdStringFromUsbStrings",pwVar8,uVar10,param_4);
  return 0xc0000017;
}



===== ProduceQueriedID @ 140006f68 =====

ulonglong ProduceQueriedID(char *param_1,longlong param_2,longlong param_3,byte *param_4)

{
  char *pcVar1;
  short sVar2;
  bool bVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  char *_Dst;
  ulonglong uVar8;
  short *psVar9;
  char *pcVar10;
  longlong lVar11;
  uint uVar12;
  wchar_t *pwVar13;
  char *pcVar14;
  longlong lVar15;
  ulonglong uVar16;
  undefined8 uVar17;
  char **ppcVar18;
  char *pcVar19;
  longlong lVar20;
  longlong lVar21;
  char *local_res8;
  longlong local_res10;
  byte *local_res20;
  char *local_88;
  char *local_80;
  char *local_78;
  longlong local_70;
  undefined8 local_58;
  short *local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  
  local_58 = 0;
  local_48 = 0;
  uStack_40 = 0;
  lVar15 = *(longlong *)(*(longlong *)(param_1 + 8) + 0x40);
  uVar16 = 0;
  local_50 = (short *)0x0;
  local_88 = (char *)0x0;
  local_70 = 0;
  local_res20 = param_4;
  local_res8 = param_1;
  local_res10 = param_2;
  local_80 = (char *)ExAllocatePool2(0x40,0x400,0x50425355);
  uVar17 = 0x50425355;
  _Dst = (char *)ExAllocatePool2(0x40);
  if ((_Dst == (char *)0x0) || (local_80 == (char *)0x0)) {
    WriteDbgTraceWarning
              ("ProduceQueriedID",L"USBPRINT.SYS: BusQueryDeviceIDs; No memory.  Failing",uVar17,
               local_res20);
    uVar16 = 0xc0000017;
    local_88 = (char *)0x0;
    if (_Dst != (char *)0x0) goto LAB_140007102;
  }
  else {
    memset(local_80,0,0x400);
    memset(_Dst,0,0x400);
    uVar8 = Feature_2524085560__private_IsEnabledDeviceUsageNoInline();
    if ((char)uVar8 != '\0') {
      uVar17 = 0x50425355;
      local_88 = (char *)ExAllocatePool2(0x40,0x400);
      if (local_88 == (char *)0x0) {
        uVar16 = 0xc0000017;
      }
      else {
        ExAcquireFastMutex(lVar15 + 0x438);
        uVar5 = USBPRINT_CopyDeviceIdStringLocked(lVar15,local_88,uVar17,local_res20);
        uVar16 = (ulonglong)uVar5;
        ExReleaseFastMutex(lVar15 + 0x438);
        if (-1 < (int)uVar5) {
          local_78 = local_88;
          goto LAB_1400070bc;
        }
      }
      *(undefined8 *)(param_3 + 0x38) = 0;
      ExFreePool(_Dst);
      ExFreePool(local_80);
      if (local_88 == (char *)0x0) {
        return uVar16;
      }
      goto LAB_140007131;
    }
    local_78 = (char *)(lVar15 + 0x24);
LAB_1400070bc:
    ppcVar18 = (char **)0x0;
    iVar6 = *(int *)(param_2 + 8);
    if (*local_78 == '\0') {
      if (iVar6 == 2) {
        if ((*(byte *)(lVar15 + 0x470) & 1) != 0) {
          psVar9 = (short *)ExAllocatePool2(0x40,0x800,0x50425355);
          if (psVar9 == (short *)0x0) goto LAB_1400075c4;
          RtlStringCchCopyW(psVar9);
          *(short **)(param_3 + 0x38) = psVar9;
          uVar16 = 0;
        }
      }
      else {
        uVar16 = 0xc0000225;
      }
      goto LAB_140007102;
    }
    if (iVar6 == 0) {
      pcVar19 = "USBPRINT\\%hs";
      RtlStringCbPrintfA(local_80,0x400,"USBPRINT\\%hs",local_78);
      FixupDeviceId(local_80);
      RtlInitAnsiString(&local_48,local_80);
      uVar17 = CONCAT71((int7)((ulonglong)pcVar19 >> 8),1);
      iVar6 = RtlAnsiStringToUnicodeString(&local_58,&local_48);
      if (-1 < iVar6) {
        *(short **)(param_3 + 0x38) = local_50;
        uVar16 = 0;
        WriteDbgTraceInfo("ProduceQueriedID",L"USBPRINT.SYS:BusQueryDeviceID: %hs",local_80,local_78
                         );
        goto LAB_140007102;
      }
      WriteDbgTraceInfo("ProduceQueriedID",L"USBPRINT.SYS: RtlAnsiStringToUnicodeString failed",
                        uVar17,local_78);
LAB_1400075c4:
      uVar16 = 0xc0000017;
      goto LAB_140007279;
    }
    if (iVar6 == 1) {
      local_res8 = (char *)((ulonglong)local_res8 & 0xffffffffffffff00);
      uVar5 = 1;
      WriteDbgTraceInfo("ProduceQueriedID",L"USBPRINT.SYS: Received BusQueryHardwareIDs message",0,
                        local_res20);
      if ((*(byte *)(lVar15 + 0x470) & 1) == 0) {
        cVar4 = (char)local_res8;
      }
      else {
        cVar4 = '\x01';
        local_res8 = (char *)CONCAT71(local_res8._1_7_,1);
        bVar3 = USBPRINT_PreferIPP();
        uVar5 = (uint)!bVar3;
      }
      bVar3 = IsProtectedPrintEnabled();
      uVar12 = 0;
      if (!bVar3) {
        uVar12 = uVar5;
      }
      pcVar19 = local_80;
      uVar8 = ParPnpGetId(local_78,*(int *)(local_res10 + 8),local_80,local_res20);
      uVar16 = uVar8 & 0xffffffff;
      if ((int)uVar8 < 0) {
        WriteDbgTraceInfo("ProduceQueriedID",
                          L"USBPRINT.SYS: BusQueryHardwareIDs; ParPnpGetID failed",pcVar19,
                          local_res20);
        goto LAB_140007102;
      }
      pcVar19 = (char *)(ulonglong)uVar12;
      uVar5 = uVar12 * 2 + 1;
      if (cVar4 == '\0') {
        uVar5 = uVar12 * 2;
      }
      if (uVar5 == 0) {
        uVar8 = 0;
        pwVar13 = L"USBPRINT.SYS: BusQueryHardwareIDs No HWID\'s to publish";
LAB_14000757a:
        WriteDbgTraceInfo("ProduceQueriedID",pwVar13,pcVar19,local_res20);
        uVar16 = uVar8;
        goto LAB_140007279;
      }
      lVar15 = -1;
      lVar21 = -1;
      do {
        lVar20 = lVar21;
        lVar21 = lVar20 + 1;
      } while (local_80[lVar21] != '\0');
      if (0x400 < (lVar20 + 0x10) * (ulonglong)uVar5) {
        uVar8 = 0xc0000017;
        pwVar13 = L"USBPRINT.SYS: BusQueryHardwareIDs: ID\'s to long.  Failing";
LAB_1400073ee:
        WriteDbgTraceWarning("ProduceQueriedID",pwVar13,pcVar19,local_res20);
        uVar16 = uVar8;
        goto LAB_140007279;
      }
      if ((char)uVar12 == '\0') {
        lVar21 = 0;
      }
      else {
        RtlStringCbPrintfA(_Dst,0x400,"USBPRINT\\%hs",local_80);
        local_70 = -1;
        do {
          local_70 = local_70 + 1;
        } while (_Dst[local_70] != '\0');
        lVar21 = 0x400;
        (_Dst + (int)local_70)[0] = ' ';
        (_Dst + (int)local_70)[1] = '\0';
        pcVar19 = _Dst;
        do {
          if (*pcVar19 == '\0') break;
          pcVar19 = pcVar19 + 1;
          lVar21 = lVar21 + -1;
        } while (lVar21 != 0);
        uVar8 = -(ulonglong)(lVar21 != 0) & 0x400U - lVar21;
        if (lVar21 != 0) {
          RtlStringCopyWorkerA(_Dst + uVar8,0x400 - uVar8,uVar8,(longlong)local_80,0x7ffffffe);
        }
        lVar21 = -1;
        do {
          lVar21 = lVar21 + 1;
        } while (_Dst[lVar21] != '\0');
        (_Dst + (int)lVar21)[0] = ' ';
        (_Dst + (int)lVar21)[1] = '\0';
      }
      iVar6 = (int)lVar21;
      if ((char)local_res8 == '\0') {
        lVar15 = 0;
      }
      else {
        if (iVar6 == 0) {
          local_78 = _Dst;
        }
        else {
          local_78 = _Dst + (longlong)iVar6 + 1;
        }
        RtlStringCbPrintfA(local_78,0x400,"PSA_%hs",local_80);
        do {
          lVar15 = lVar15 + 1;
        } while (local_78[lVar15] != '\0');
        (local_78 + (int)lVar15)[0] = ' ';
        (local_78 + (int)lVar15)[1] = '\0';
      }
      FixupDeviceId(_Dst);
      RtlInitAnsiString(&local_48,_Dst);
      iVar7 = RtlAnsiStringToUnicodeString(&local_58,&local_48,1);
      if (iVar7 < 0) goto LAB_1400075c4;
      if ((char)uVar12 == '\0') {
        psVar9 = local_50;
      }
      else {
        local_50[(int)local_70] = 0;
        local_50[iVar6] = 0;
        psVar9 = local_50 + iVar6 + 1;
      }
      if ((char)local_res8 != '\0') {
        psVar9[(int)lVar15] = 0;
      }
LAB_1400075ff:
      *(short **)(param_3 + 0x38) = local_50;
    }
    else if (iVar6 == 2) {
      WriteDbgTraceInfo("ProduceQueriedID",L"USBPRINT.SYS: Received BusQueryCompatibleIDs message",0
                        ,local_res20);
      uVar8 = Feature_2524085560__private_IsEnabledDeviceUsageNoInline();
      pcVar19 = local_80;
      if ((char)uVar8 == '\0') {
        if (((*(byte *)(lVar15 + 0x470) & 1) == 0) || (*(longlong *)(lVar15 + 0x430) != 0)) {
          if (*(char **)(lVar15 + 0x430) != (char *)0x0) {
            uVar16 = ParPnpGetId(*(char **)(lVar15 + 0x430),*(int *)(local_res10 + 8),local_80,
                                 local_res20);
            goto LAB_140007377;
          }
LAB_140007267:
          WriteDbgTraceInfo("ProduceQueriedID",L"USBPRINT.SYS: BusQueryCompatibleIDs; No 1284 ID",
                            ppcVar18,local_res20);
          goto LAB_140007279;
        }
LAB_140007216:
        psVar9 = (short *)ExAllocatePool2(0x40,0x800,0x50425355);
        if (psVar9 == (short *)0x0) {
          uVar16 = 0xc0000017;
          psVar9 = (short *)0x0;
        }
        else {
          RtlStringCchCopyW(psVar9);
          uVar16 = 0;
        }
        *(short **)(param_3 + 0x38) = psVar9;
      }
      else {
        local_res8 = (char *)0x0;
        pcVar10 = (char *)ExAllocatePool2(0x40,0x400,0x50425355);
        if (pcVar10 == (char *)0x0) {
          uVar16 = 0xc0000017;
        }
        else {
          ExAcquireFastMutex(lVar15 + 0x438);
          ppcVar18 = &local_res8;
          uVar8 = USBPRINT_Copy1284IdLocked(lVar15,pcVar10,ppcVar18,local_res20);
          uVar16 = uVar8 & 0xffffffff;
          ExReleaseFastMutex(lVar15 + 0x438);
          if (-1 < (int)uVar8) {
            if ((*(byte *)(lVar15 + 0x470) & 1) == 0) {
              if (local_res8 == (char *)0x0) {
                ExFreePool(pcVar10);
                goto LAB_140007267;
              }
            }
            else if (local_res8 == (char *)0x0) {
              ExFreePool(pcVar10);
              goto LAB_140007216;
            }
            uVar16 = ParPnpGetId(local_res8,*(int *)(local_res10 + 8),local_80,local_res20);
            ExFreePool(pcVar10);
LAB_140007377:
            uVar8 = uVar16 & 0xffffffff;
            if ((int)uVar16 < 0) {
              if ((int)uVar16 != -0x3ffffddb) {
                pwVar13 = L"USBPRINT.SYS: BusQueryCompatibleIDs; ParPnpGetID failed";
                goto LAB_1400073ee;
              }
              ExFreePool(local_80);
              local_80 = (char *)0x0;
            }
            local_res20 = (byte *)((ulonglong)param_4 & 0xffffffff00000000);
            lVar21 = -1;
            if ((*(byte *)(lVar15 + 0x470) & 1) == 0) {
LAB_1400073fb:
              bVar3 = IsProtectedPrintEnabled();
              pcVar19 = (char *)0x1;
              if (!bVar3) {
                pcVar10 = local_80;
                while( true ) {
                  pcVar19 = (char *)0x1;
                  if (0x3ff < (int)local_res20) break;
                  pcVar14 = pcVar10;
                  if (pcVar10 == (char *)0x0) {
LAB_140007422:
                    WriteDbgTraceInfo("ProduceQueriedID",
                                      L"USBPRINT.SYS: BusQueryCompatibleIDs; GetDelimitedString done"
                                      ,1,local_res20);
                    break;
                  }
                  while( true ) {
                    cVar4 = *pcVar14;
                    pcVar10 = pcVar14;
                    if (cVar4 != ' ') break;
                    pcVar14 = pcVar14 + 1;
                  }
                  while (cVar4 != '\0') {
                    pcVar1 = pcVar10 + 1;
                    if (cVar4 == ',') {
                      *pcVar10 = '\0';
                      pcVar10 = pcVar1;
                      break;
                    }
                    pcVar10 = pcVar1;
                    cVar4 = *pcVar1;
                  }
                  local_res8 = pcVar14;
                  if (pcVar14 == (char *)0x0) goto LAB_140007422;
                  lVar15 = -1;
                  do {
                    lVar15 = lVar15 + 1;
                  } while (pcVar14[lVar15] != '\0');
                  if (lVar15 == 0) goto LAB_140007422;
                  lVar20 = (longlong)(int)local_res20;
                  lVar15 = -1;
                  do {
                    lVar11 = lVar15;
                    lVar15 = lVar11 + 1;
                  } while (pcVar14[lVar15] != '\0');
                  if (0x400 < (ulonglong)(lVar20 + (lVar11 + 0x10) * 2)) {
                    WriteDbgTraceWarning
                              ("ProduceQueriedID",
                               L"USBPRINT.SYS: BusQueryCompatibleIDs; ID\'s to long.  Failing this CID"
                               ,1,local_res20);
                    break;
                  }
                  FixupDeviceId(pcVar14);
                  RtlStringCbPrintfA(_Dst + lVar20,(longlong)(0x400 - (int)local_res20),
                                     "USBPRINT\\1284_CID_%hs ",pcVar14);
                  lVar15 = -1;
                  do {
                    lVar15 = lVar15 + 1;
                  } while (_Dst[lVar15] != '\0');
                  RtlStringCbPrintfA(_Dst + (int)lVar15,(longlong)(0x400 - (int)lVar15),
                                     "1284_CID_%hs ",local_res8);
                  local_res20 = (byte *)0xffffffffffffffff;
                  do {
                    local_res20 = local_res20 + 1;
                  } while (_Dst[(longlong)local_res20] != '\0');
                }
              }
            }
            else {
              pcVar19 = "1284_CID_MS_IPP ";
              RtlStringCbCopyA(_Dst,0x400,"1284_CID_MS_IPP ");
              local_res20 = (byte *)0xffffffffffffffff;
              do {
                local_res20 = local_res20 + 1;
              } while (_Dst[(longlong)local_res20] != '\0');
              bVar3 = USBPRINT_PreferIPP();
              if (!bVar3) goto LAB_1400073fb;
              IsProtectedPrintEnabled();
            }
            iVar6 = (int)local_res20;
            if ((longlong)iVar6 + 0x14U < 0x401) {
              pcVar19 = "CID_MS_GENERICPRINT ";
              RtlStringCbCopyA(_Dst + iVar6,(longlong)(0x400 - iVar6),"CID_MS_GENERICPRINT ");
              uVar16 = 0;
              lVar15 = -1;
              do {
                lVar15 = lVar15 + 1;
              } while (_Dst[lVar15] != '\0');
              do {
                lVar21 = lVar21 + 1;
              } while (_Dst[lVar21] != '\0');
              if (lVar21 == 0) {
                pwVar13 = L"USBPRINT.SYS: BusQueryCompatibleIDs; TempString is NULL";
                goto LAB_14000757a;
              }
              RtlInitAnsiString(&local_48,_Dst);
              uVar17 = CONCAT71((int7)((ulonglong)pcVar19 >> 8),1);
              iVar6 = RtlAnsiStringToUnicodeString(&local_58,&local_48);
              if (-1 < iVar6) {
                sVar2 = *local_50;
                psVar9 = local_50;
                while (sVar2 != 0) {
                  if (sVar2 == 0x20) {
                    *psVar9 = 0;
                  }
                  psVar9 = psVar9 + 1;
                  sVar2 = *psVar9;
                }
                local_50[(int)lVar15] = 0;
                goto LAB_1400075ff;
              }
              WriteDbgTraceWarning
                        ("ProduceQueriedID",L"USBPRINT.SYS: RtlAnsiStringToUnicodeString failed",
                         uVar17,local_res20);
              goto LAB_1400075c4;
            }
            WriteDbgTraceWarning
                      ("ProduceQueriedID",
                       L"USBPRINT.SYS: BusQueryCompatibleIDs; ID\'s too long.  Failing this CID",
                       pcVar19,local_res20);
            uVar16 = uVar8;
            goto LAB_140007102;
          }
          ExFreePool(pcVar10);
        }
LAB_140007279:
        *(undefined8 *)(param_3 + 0x38) = 0;
      }
    }
    else if (iVar6 == 3) {
      uVar16 = (ulonglong)*(uint *)(local_res8 + 0x10);
      RtlStringCbPrintfA(local_80,0x400,"USB%03u",uVar16);
      WriteDbgTraceInfo("ProduceQueriedID",L"USBPRINT.SYS:BusQueryInstanceID: %hs",local_80,uVar16);
      RtlInitAnsiString(&local_48,local_80);
      iVar6 = RtlAnsiStringToUnicodeString(&local_58,&local_48,1);
      if (iVar6 < 0) {
        uVar16 = 0xc0000017;
        *(undefined8 *)(param_3 + 0x38) = 0;
      }
      else {
        uVar16 = 0;
        *(short **)(param_3 + 0x38) = local_50;
      }
    }
    else {
      WriteDbgTraceInfo("ProduceQueriedID",L"USBPRINT.SYS: Received unkown BusQuery message",0,
                        local_res20);
      uVar16 = (ulonglong)*(uint *)(param_3 + 0x30);
    }
LAB_140007102:
    ExFreePool(_Dst);
  }
  if (local_80 != (char *)0x0) {
    ExFreePool(local_80);
  }
  if (local_88 == (char *)0x0) {
    return uVar16;
  }
LAB_140007131:
  ExFreePool(local_88);
  return uVar16;
}



===== RtlStringCbCopyA @ 1400079c0 =====

undefined8 RtlStringCbCopyA(char *param_1,longlong param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  if (param_2 - 1U < 0x7fffffff) {
    uVar1 = RtlStringCopyWorkerA(param_1,param_2,param_3,param_3,0x7ffffffe);
  }
  else {
    uVar1 = 0xc000000d;
    if (param_2 != 0) {
      *param_1 = '\0';
    }
  }
  return uVar1;
}



===== RtlStringCbPrintfW @ 1400079fc =====

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



===== RtlStringCchCopyW @ 140007a78 =====

uint RtlStringCchCopyW(short *param_1)

{
  short sVar1;
  short *psVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar3 = 0x400;
  lVar4 = (longlong)L"1284_CID_MS_IPP" - (longlong)param_1;
  do {
    if ((lVar3 == -0x7ffffbfe) || (sVar1 = *(short *)(lVar4 + (longlong)param_1), sVar1 == 0))
    break;
    *param_1 = sVar1;
    param_1 = param_1 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  psVar2 = param_1 + -1;
  if (lVar3 != 0) {
    psVar2 = param_1;
  }
  *psVar2 = 0;
  return ~-(uint)(lVar3 != 0) & 0x80000005;
}



===== RtlStringCopyWorkerA @ 140007ad0 =====

undefined8
RtlStringCopyWorkerA
          (char *param_1,longlong param_2,undefined8 param_3,longlong param_4,longlong param_5)

{
  undefined8 uVar1;
  longlong lVar2;
  
  uVar1 = 0;
  if (param_2 != 0) {
    lVar2 = param_4 - (longlong)param_1;
    do {
      if (param_5 == 0) goto LAB_140007b0b;
      if (param_1[lVar2] == '\0') break;
      *param_1 = param_1[lVar2];
      param_5 = param_5 + -1;
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
    if (param_2 != 0) goto LAB_140007b0b;
  }
  param_1 = param_1 + -1;
  uVar1 = 0x80000005;
LAB_140007b0b:
  *param_1 = '\0';
  return uVar1;
}



===== SetPortNameAndPrinterName @ 140007b1c =====

ulonglong SetPortNameAndPrinterName
                    (longlong param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  int iVar2;
  wchar_t *_Dst;
  ulonglong uVar3;
  longlong lVar4;
  char *pcVar5;
  longlong lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  wchar_t *pwVar10;
  ulonglong uVar11;
  longlong local_res8;
  char *local_res10;
  undefined8 local_res18;
  undefined8 local_48;
  undefined8 uStack_40;
  
  local_res18 = 0;
  local_48 = 0;
  uStack_40 = 0;
  uVar8 = param_4;
  local_res10 = param_2;
  WriteDbgTraceInfo("SetPortNameAndPrinterName",L"USBPRINT.SYS: Enter: SetPortNameAndPrinterName",
                    param_3,param_4);
  uVar7 = 0x50425355;
  _Dst = (wchar_t *)ExAllocatePool2(0x40,0x800);
  if (_Dst == (wchar_t *)0x0) {
    WriteDbgTraceWarning
              ("SetPortNameAndPrinterName",L"USBPRINT.SYS: SetPortNameAndPrinterName - No memory.",
               uVar7,uVar8);
    return 0xc0000017;
  }
  puVar9 = &local_res18;
  uVar8 = 0xf003f;
  uVar1 = IoOpenDeviceRegistryKey(param_4);
  uVar11 = (ulonglong)uVar1;
  if ((int)uVar1 < 0) {
    WriteDbgTraceWarning
              ("SetPortNameAndPrinterName",
               L"USBPRINT.SYS: SetPortNameAndPrinterName; IoOpenDeviceRegistryKey failed",uVar8,
               puVar9);
    goto LAB_140007e75;
  }
  memset(_Dst,0,0x800);
  pwVar10 = L"USB";
  uVar3 = RtlStringCbPrintfW(_Dst,0x800,L"%ws%03u",L"USB");
  lVar6 = -1;
  uVar11 = uVar3 & 0xffffffff;
  if (-1 < (int)uVar3) {
    RtlInitUnicodeString(&local_48,L"PortName");
    lVar4 = -1;
    do {
      lVar4 = lVar4 + 1;
    } while (_Dst[lVar4] != L'\0');
    pwVar10 = (wchar_t *)0x1;
    uVar8 = 0;
    uVar1 = ZwSetValueKey(local_res18,&local_48,0,1,_Dst,(int)lVar4 * 2 + 2);
    uVar11 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      WriteDbgTraceWarning
                ("SetPortNameAndPrinterName",
                 L"USBPRINT.SYS: SetPortNameAndPrinterName; ZwSetValueKey(PortName) failed",uVar8,
                 pwVar10);
    }
    else {
      WriteDbgTraceInfo("SetPortNameAndPrinterName",
                        L"USBPRINT.SYS: SetPortNameAndPrinterName; ZwSetValueKey(PortName) = %ws",
                        _Dst,pwVar10);
    }
  }
  lVar4 = *(longlong *)(*(longlong *)(param_1 + 8) + 0x40);
  if (lVar4 != 0) {
    uVar3 = Feature_2524085560__private_IsEnabledDeviceUsageNoInline();
    local_res10 = (char *)0x0;
    if ((char)uVar3 == '\0') {
      uVar3 = GetUsbPrinterName(*(longlong *)(param_1 + 8),*(void **)(lVar4 + 0x430),&local_res10,
                                pwVar10);
      if (-1 < (int)uVar3) {
        RtlInitUnicodeString(&local_48,L"PrinterName");
        pcVar5 = local_res10;
        do {
          lVar6 = lVar6 + 1;
        } while (*(short *)(local_res10 + lVar6 * 2) != 0);
        uVar7 = 1;
        uVar8 = 0;
        iVar2 = ZwSetValueKey(local_res18,&local_48,0,1,local_res10,(int)lVar6 * 2 + 2);
        if (iVar2 < 0) {
          WriteDbgTraceWarning
                    ("SetPortNameAndPrinterName",
                     L"USBPRINT.SYS: SetPortNameAndPrinterName; ZwSetValueKey(PrinterName) failed",
                     uVar8,uVar7);
        }
        else {
          WriteDbgTraceInfo("SetPortNameAndPrinterName",
                            L"USBPRINT.SYS: SetPortNameAndPrinterName; ZwSetValueKey(PrinterName) = %ws"
                            ,pcVar5,uVar7);
        }
        goto LAB_140007e48;
      }
    }
    else {
      local_res8 = 0;
      pcVar5 = (char *)ExAllocatePool2(0x40,0x400,0x50425355);
      if (pcVar5 != (char *)0x0) {
        ExAcquireFastMutex(lVar4 + 0x438);
        uVar3 = USBPRINT_Copy1284IdLocked(lVar4,pcVar5,&local_res10,pwVar10);
        ExReleaseFastMutex(lVar4 + 0x438);
        if ((-1 < (int)uVar3) &&
           (uVar3 = GetUsbPrinterName(*(longlong *)(param_1 + 8),local_res10,&local_res8,pwVar10),
           -1 < (int)uVar3)) {
          RtlInitUnicodeString(&local_48,L"PrinterName");
          lVar4 = local_res8;
          do {
            lVar6 = lVar6 + 1;
          } while (*(short *)(local_res8 + lVar6 * 2) != 0);
          uVar7 = 1;
          uVar8 = 0;
          iVar2 = ZwSetValueKey(local_res18,&local_48,0,1,local_res8,(int)lVar6 * 2 + 2);
          if (iVar2 < 0) {
            WriteDbgTraceWarning
                      ("SetPortNameAndPrinterName",
                       L"USBPRINT.SYS: SetPortNameAndPrinterName; ZwSetValueKey(PrinterName) failed"
                       ,uVar8,uVar7);
          }
          else {
            WriteDbgTraceInfo("SetPortNameAndPrinterName",
                              L"USBPRINT.SYS: SetPortNameAndPrinterName; ZwSetValueKey(PrinterName) = %ws"
                              ,lVar4,uVar7);
          }
          ExFreePool(lVar4);
        }
LAB_140007e48:
        ExFreePool(pcVar5);
      }
    }
  }
  ZwClose(local_res18);
LAB_140007e75:
  ExFreePool(_Dst);
  return uVar11;
}



===== USBPRINT_BuildPipeList @ 140007ea8 =====

undefined8
USBPRINT_BuildPipeList(longlong param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  bool bVar4;
  longlong lVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  wchar_t *pwVar9;
  longlong lVar10;
  uint uVar11;
  bool bVar12;
  longlong local_res8;
  longlong local_res18;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_res18 = 0;
  bVar3 = false;
  lVar5 = (longlong)(int)param_2;
  bVar4 = false;
  local_res8 = 0;
  lVar2 = *(longlong *)(lVar1 + 0x588 + lVar5 * 8);
  if (lVar2 == 0) {
    uVar6 = 0xc0000184;
  }
  else {
    bVar12 = (*(char *)(lVar2 + 6) - 2U & 0xfd) == 0;
    uVar8 = 0;
    lVar10 = 0;
    if (*(int *)(lVar2 + 0x10) != 0) {
      do {
        if (*(char *)(lVar2 + 0x1a + uVar8 * 0x18) < '\0') {
          if (bVar12) {
            if (!bVar4) {
              uVar7 = Feature_3186517304__private_IsEnabledDeviceUsageNoInline();
              lVar10 = lVar2 + 0x18 + uVar8 * 0x18;
              if ((char)uVar7 == '\0') {
                *(longlong *)(lVar1 + 0x5a8 + lVar5 * 8) = lVar10;
              }
              else {
                local_res18 = lVar10;
              }
              bVar4 = true;
              goto LAB_140007f94;
            }
            pwVar9 = 
            L"USBPRINT.SYS: Warning!!  Multiple IN pipes detected on printer.  Defaulting to first pipe"
            ;
          }
          else {
            pwVar9 = 
            L"USBPRINT.SYS: Warning!!  unexpected IN pipe (not specified in protocol field)";
          }
LAB_140007f63:
          WriteDbgTraceWarning("USBPRINT_BuildPipeList",pwVar9,param_3,param_4);
        }
        else {
          if (bVar3) {
            pwVar9 = 
            L"USBPRINT.SYS: Warning!!  Multiple OUT pipes detected on printer.  Defaulting to first pipe"
            ;
            goto LAB_140007f63;
          }
          uVar7 = Feature_3186517304__private_IsEnabledDeviceUsageNoInline();
          lVar10 = lVar2 + 0x18 + uVar8 * 0x18;
          if ((char)uVar7 == '\0') {
            *(longlong *)(lVar1 + 0x598 + lVar5 * 8) = lVar10;
          }
          else {
            local_res8 = lVar10;
          }
          bVar3 = true;
        }
LAB_140007f94:
        uVar11 = (int)uVar8 + 1;
        uVar8 = (ulonglong)uVar11;
      } while (uVar11 < *(uint *)(lVar2 + 0x10));
      lVar10 = local_res8;
    }
    if ((bVar12) && (!bVar4)) {
      WriteDbgTraceWarning
                ("USBPRINT_BuildPipeList",
                 L"USBPRINT.SYS: Warning!!  IN pipe was specified in protocol field, but was not found"
                 ,param_3,param_4);
    }
    uVar8 = Feature_3186517304__private_IsEnabledDeviceUsageNoInline();
    if ((char)uVar8 != '\0') {
      *(undefined8 *)(lVar1 + 0x5a8 + lVar5 * 8) = 0;
      *(undefined8 *)(lVar1 + 0x598 + lVar5 * 8) = 0;
      if ((!bVar3) || ((bVar12 && (!bVar4)))) {
        WriteDbgTraceWarning
                  ("USBPRINT_BuildPipeList",
                   L"USBPRINT.SYS: incomplete pipe set for interface %d, pipe cache left unavailable"
                   ,(ulonglong)param_2,param_4);
      }
      else {
        *(longlong *)(lVar1 + 0x5a8 + lVar5 * 8) = local_res18;
        *(longlong *)(lVar1 + 0x598 + lVar5 * 8) = lVar10;
      }
    }
    uVar6 = 0;
  }
  return uVar6;
}



===== USBPRINT_ConfigureDevice @ 14000803c =====

uint USBPRINT_ConfigureDevice
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  uint uVar2;
  longlong *plVar3;
  longlong local_res8;
  
  local_res8 = 0;
  plVar3 = &local_res8;
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar2 = USBPRINT_GetUSBConfigs(param_1,param_2,plVar3,param_4);
  if (local_res8 == 0) {
    WriteDbgTraceWarning
              ("USBPRINT_ConfigureDevice",
               L"USBPRINT.SYS: ConfigureDevice, No Configuration descriptor.",plVar3,param_4);
  }
  else {
    if (-1 < (int)uVar2) {
      USBPRINT_CheckConfigs(param_1,local_res8);
      uVar2 = USBPRINT_SelectInterface(param_1,local_res8,(uint)(*(char *)(lVar1 + 0x429) != '\0'));
    }
    ExFreePool(local_res8);
  }
  if ((int)uVar2 < 0) {
    WriteDbgTraceInfo("USBPRINT_ConfigureDevice",L"USBPRINT.SYS: exit USBPRINT_ConfigureDevice (%x)"
                      ,(ulonglong)uVar2,param_4);
  }
  return uVar2;
}



===== USBPRINT_Copy1284IdLocked @ 1400080f4 =====

ulonglong USBPRINT_Copy1284IdLocked
                    (longlong param_1,char *param_2,undefined8 *param_3,undefined8 param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  uVar2 = 0;
  *param_3 = 0;
  lVar3 = *(longlong *)(param_1 + 0x430);
  if (lVar3 != 0) {
    uVar1 = RtlStringCbCopyA(param_2,0x400,lVar3);
    uVar2 = uVar1 & 0xffffffff;
    if ((int)uVar1 == -0x7ffffffb) {
      WriteDbgTraceWarning
                ("USBPRINT_Copy1284IdLocked",
                 L"USBPRINT.SYS: p1284Id exceeded the writer-enforced MAX_ID_SIZE invariant.",lVar3,
                 param_4);
    }
    else {
      *param_3 = param_2;
    }
  }
  return uVar2;
}



===== USBPRINT_CopyDeviceIdStringLocked @ 140008158 =====

void USBPRINT_CopyDeviceIdStringLocked
               (longlong param_1,char *param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  lVar1 = param_1 + 0x24;
  lVar3 = lVar1;
  uVar2 = RtlStringCbCopyA(param_2,0x400,lVar1);
  if ((int)uVar2 == -0x7ffffffb) {
    WriteDbgTraceWarning
              ("USBPRINT_CopyDeviceIdStringLocked",
               L"USBPRINT.SYS: DeviceIdString exceeded the writer-enforced MAX_ID_SIZE invariant.",
               lVar3,param_4);
    RtlStringCopyWorkerA(param_2,0x400,lVar3,lVar1,0x3ff);
  }
  return;
}



===== USBPRINT_CreateDeviceObject @ 1400081c0 =====

ulonglong USBPRINT_CreateDeviceObject(undefined8 param_1,longlong *param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  
  *param_2 = 0;
  uVar5 = 0x22;
  uVar2 = IoCreateDevice(param_1,0x5f8,0,0x22,0,0,param_2);
  uVar4 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    WriteDbgTraceInfo("USBPRINT_CreateDeviceObject",
                      L"USBPRINT.SYS: exit USBPRINT_CreateDeviceObject (%x)",uVar4,uVar5);
  }
  else {
    puVar1 = *(undefined1 **)(*param_2 + 0x40);
    *puVar1 = 0;
    *(undefined4 *)(puVar1 + 0x5d0) = 0;
    *(undefined4 *)(puVar1 + 0x20) = 0;
    *(undefined8 *)(puVar1 + 0x4f0) = 0;
    *(undefined8 *)(puVar1 + 0x588) = 0;
    *(undefined8 *)(puVar1 + 0x590) = 0;
    *(undefined4 *)(puVar1 + 0x500) = 0xffffffff;
    *(undefined4 *)(puVar1 + 0x504) = 0xffffffff;
    *(undefined4 *)(puVar1 + 0x510) = 4;
    *(undefined4 *)(puVar1 + 0x514) = 4;
    *(undefined4 *)(puVar1 + 0x518) = 4;
    *(undefined4 *)(puVar1 + 0x51c) = 4;
    *(undefined4 *)(puVar1 + 0x520) = 4;
    *(undefined8 *)(puVar1 + 0x4e8) = 0;
    puVar1[0x564] = 1;
    *(undefined4 *)(puVar1 + 0x560) = 0;
    puVar1[0x5f4] = 0;
    *(undefined4 *)(puVar1 + 0x4f8) = 0x10040;
    *(undefined4 *)(puVar1 + 0x50c) = 1;
    KeInitializeEvent(puVar1 + 0x548,0,0);
    uVar3 = Feature_932690235__private_IsEnabledDeviceUsageNoInline();
    if (((char)uVar3 == '\0') &&
       (uVar3 = Feature_2524085560__private_IsEnabledDeviceUsageNoInline(), (char)uVar3 == '\0')) {
      return uVar4;
    }
    *(undefined4 *)(puVar1 + 0x438) = 1;
    *(undefined8 *)(puVar1 + 0x440) = 0;
    *(undefined4 *)(puVar1 + 0x448) = 0;
    KeInitializeEvent(puVar1 + 0x450,1,0);
  }
  return uVar4;
}



===== USBPRINT_DelayIdleRequest @ 140008320 =====

void USBPRINT_DelayIdleRequest
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  USBPRINT_FdoSubmitIdleRequestIrp(*(longlong *)(param_1 + 0x40),param_2,param_3,param_4);
  return;
}



===== USBPRINT_FdoIdleNotificationCallback @ 140008340 =====

void USBPRINT_FdoIdleNotificationCallback
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  
  WriteDbgTraceInfo("USBPRINT_FdoIdleNotificationCallback",L"USB Printer (%p) going idle",param_1,
                    param_4);
  if ((*(char *)(param_1 + 0x564) == '\0') || (*(int *)(param_1 + 0x5bc) != 0)) {
    WriteDbgTraceWarning
              ("USBPRINT_FdoIdleNotificationCallback",
               L"USB Printer (%p) not accepting requests, abort idle",param_1,param_4);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x5f0);
    if (3 < iVar1 - 1U) {
      iVar1 = 4;
    }
    PoRequestPowerIrp(*(undefined8 *)(param_1 + 0x10),2,iVar1,0,0,0);
  }
  return;
}



===== USBPRINT_FdoIdleNotificationRequestComplete @ 1400083d0 =====

undefined8
USBPRINT_FdoIdleNotificationRequestComplete(undefined8 param_1,longlong param_2,longlong param_3)

{
  longlong lVar1;
  longlong lVar2;
  
  WriteDbgTraceInfo("USBPRINT_FdoIdleNotificationRequestComplete",
                    L"Idle notification IRP for USB Printer (%p) completed (%08X)",param_3,
                    (ulonglong)*(uint *)(param_2 + 0x30));
  lVar1 = *(longlong *)(param_3 + 0x5e0);
  lVar2 = *(longlong *)(param_3 + 0x5e8);
  *(undefined8 *)(param_3 + 0x5e0) = 0;
  *(undefined8 *)(param_3 + 0x5e8) = 0;
  *(undefined8 *)(param_3 + 0x5d8) = 0;
  if (lVar1 != 0) {
    ExFreePool();
  }
  if (lVar2 != 0) {
    ExFreePool(lVar2);
  }
  IoFreeIrp(param_2);
  return 0xc0000016;
}



===== USBPRINT_FdoSubmitIdleRequestIrp @ 140008474 =====

undefined8
USBPRINT_FdoSubmitIdleRequestIrp
          (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined8 uVar6;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  WriteDbgTraceInfo("USBPRINT_FdoSubmitIdleRequestIrp",L"USBPRINT_FdoSubmitIdleRequestIrp (%p)",
                    lVar2,param_4);
  uVar6 = 0;
  if (((*(char *)(lVar2 + 0x5d4) == '\0') || (*(longlong *)(lVar2 + 0x5d8) != 0)) ||
     (*(char *)(lVar2 + 0x564) == '\0')) {
    uVar6 = 0;
  }
  else {
    cVar1 = KeGetCurrentIrql();
    if (cVar1 == '\0') {
      puVar3 = (undefined8 *)ExAllocatePool2(0x40,0x10,0x50425355);
      if (puVar3 != (undefined8 *)0x0) {
        puVar4 = (undefined8 *)ExAllocatePool2(0x40,0x10,0x50425355);
        if (puVar4 != (undefined8 *)0x0) {
          puVar4[1] = lVar2;
          *puVar4 = USBPRINT_FdoIdleNotificationCallback;
          *puVar3 = 0;
          puVar3[1] = 0;
          lVar5 = IoAllocateIrp(*(char *)(*(longlong *)(lVar2 + 8) + 0x4c) + '\x01',0);
          *(longlong *)(lVar2 + 0x5d8) = lVar5;
          if (lVar5 != 0) {
            lVar5 = *(longlong *)(lVar5 + 0xb8);
            *(undefined1 *)(lVar5 + -0x48) = 0xf;
            *(undefined4 *)(lVar5 + -0x30) = 0x220027;
            *(undefined4 *)(lVar5 + -0x38) = 0x10;
            *(undefined8 **)(lVar5 + -0x28) = puVar4;
            *(undefined8 **)(lVar2 + 0x5e0) = puVar4;
            *(undefined8 **)(lVar2 + 0x5e8) = puVar3;
            lVar5 = *(longlong *)(*(longlong *)(lVar2 + 0x5d8) + 0xb8);
            *(code **)(lVar5 + -0x10) = USBPRINT_FdoIdleNotificationRequestComplete;
            *(longlong *)(lVar5 + -8) = lVar2;
            *(undefined1 *)(lVar5 + -0x45) = 0xe0;
            uVar6 = IofCallDriver(*(undefined8 *)(lVar2 + 8),*(undefined8 *)(lVar2 + 0x5d8));
            return uVar6;
          }
          ExFreePool(puVar4);
        }
        ExFreePool(puVar3);
      }
      uVar6 = 0xc000009a;
    }
    else {
      lVar2 = IoAllocateWorkItem(param_1);
      if (lVar2 == 0) {
        uVar6 = 0xc000009a;
      }
      else {
        IoQueueWorkItem(lVar2,USBPRINT_DelayIdleRequest,1);
      }
    }
  }
  return uVar6;
}



===== USBPRINT_GetDeviceID @ 140008648 =====

void USBPRINT_GetDeviceID(longlong param_1,undefined8 param_2,undefined8 param_3,byte *param_4)

{
  char *_Src;
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  undefined1 *_Dst;
  ulonglong uVar4;
  void *pvVar5;
  char *pcVar6;
  undefined8 uVar7;
  size_t _Size;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  uVar7 = 0x50425355;
  _Dst = (undefined1 *)ExAllocatePool2(0x40);
  if (_Dst == (undefined1 *)0x0) {
    WriteDbgTraceWarning
              ("USBPRINT_GetDeviceID",L"USBPRINT.SYS: Memory Allocation failed in GetDeviceID",uVar7
               ,param_4);
    uVar4 = Feature_2524085560__private_IsEnabledDeviceUsageNoInline();
    if ((char)uVar4 == '\0') {
      RtlStringCbPrintfA((char *)(lVar2 + 0x24),0x400,"UnknownPrinter",param_4);
      return;
    }
    ExAcquireFastMutex(lVar2 + 0x438);
    RtlStringCbPrintfA((char *)(lVar2 + 0x24),0x400,"UnknownPrinter",param_4);
    ExReleaseFastMutex(lVar2 + 0x438);
    return;
  }
  memset(_Dst,0,0x400);
  uVar7 = 0x3f1;
  uVar3 = USBPRINT_Get1284Id(param_1,_Dst,0x3f1,param_4);
  if (uVar3 == 0xffffffff) {
    WriteDbgTraceWarning("USBPRINT_GetDeviceID",L"USBPRINT.SYS: Get1284Id Failed",uVar7,param_4);
    uVar4 = Feature_2524085560__private_IsEnabledDeviceUsageNoInline();
    if ((char)uVar4 == '\0') {
      RtlStringCbPrintfA((char *)(lVar2 + 0x24),0x400,"UnknownPrinter",param_4);
      goto LAB_140008930;
    }
    ExAcquireFastMutex(lVar2 + 0x438);
    RtlStringCbPrintfA((char *)(lVar2 + 0x24),0x400,"UnknownPrinter",param_4);
  }
  else {
    _Src = _Dst + 2;
    WriteDbgTraceInfo("USBPRINT_GetDeviceID",L"USBPRINT.SYS: 1284 ID == %hs",_Src,param_4);
    _Size = (size_t)(int)(uVar3 - 1);
    uVar4 = Feature_2524085560__private_IsEnabledDeviceUsageNoInline();
    if ((char)uVar4 == '\0') {
      pvVar5 = (void *)ExAllocatePool2(0x40,_Size,0x50425355);
      uVar4 = Feature_932690235__private_IsEnabledDeviceUsageNoInline();
      if ((char)uVar4 != '\0') {
        ExAcquireFastMutex(lVar2 + 0x438);
      }
      if (pvVar5 != (void *)0x0) {
        memmove(pvVar5,_Src,_Size);
        LOCK();
        lVar1 = *(longlong *)(lVar2 + 0x430);
        *(longlong *)(lVar2 + 0x430) = (longlong)pvVar5;
        UNLOCK();
        if (lVar1 != 0) {
          ExFreePool(lVar1);
        }
      }
      pcVar6 = (char *)(lVar2 + 0x24);
      uVar4 = ParPnpGetId(_Src,0,pcVar6,param_4);
      if ((int)uVar4 < 0) {
        WriteDbgTraceWarning
                  ("USBPRINT_GetDeviceID",L"USBPRINT.SYS: ParPnpGetId failed, error== 0x%0X",
                   uVar4 & 0xffffffff,param_4);
        RtlStringCbPrintfA(pcVar6,0x400,"UnknownPrinter",param_4);
      }
      else {
        WriteDbgTraceInfo("USBPRINT_GetDeviceID",L"USBPRINT.SYS: DeviceIdString=%hs",pcVar6,param_4)
        ;
      }
      uVar4 = Feature_932690235__private_IsEnabledDeviceUsageNoInline();
      if ((char)uVar4 == '\0') goto LAB_140008930;
    }
    else {
      pvVar5 = (void *)ExAllocatePool2();
      ExAcquireFastMutex(lVar2 + 0x438);
      if (pvVar5 != (void *)0x0) {
        memmove(pvVar5,_Src,_Size);
        LOCK();
        lVar1 = *(longlong *)(lVar2 + 0x430);
        *(longlong *)(lVar2 + 0x430) = (longlong)pvVar5;
        UNLOCK();
        if (lVar1 != 0) {
          ExFreePool(lVar1);
        }
      }
      pcVar6 = (char *)(lVar2 + 0x24);
      uVar4 = ParPnpGetId(_Src,0,pcVar6,param_4);
      if ((int)uVar4 < 0) {
        WriteDbgTraceWarning
                  ("USBPRINT_GetDeviceID",L"USBPRINT.SYS: ParPnpGetId failed, error== 0x%0X",
                   uVar4 & 0xffffffff,param_4);
        RtlStringCbPrintfA(pcVar6,0x400,"UnknownPrinter",param_4);
      }
      else {
        WriteDbgTraceInfo("USBPRINT_GetDeviceID",L"USBPRINT.SYS: DeviceIdString=%hs",pcVar6,param_4)
        ;
      }
    }
  }
  ExReleaseFastMutex(lVar2 + 0x438);
LAB_140008930:
  ExFreePool(_Dst);
  return;
}



===== USBPRINT_GetUSBConfigs @ 140008964 =====

uint USBPRINT_GetUSBConfigs
               (longlong param_1,undefined8 param_2,longlong *param_3,undefined8 param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  longlong lVar3;
  uint uVar4;
  undefined8 *puVar5;
  int iVar6;
  undefined8 local_res20;
  
  local_res20 = 0xfffffffffd050f80;
  puVar5 = (undefined8 *)0x50425355;
  puVar2 = (undefined4 *)ExAllocatePool2(0x40);
  if (puVar2 == (undefined4 *)0x0) {
    uVar1 = 0xc000009a;
  }
  else {
    uVar4 = 0x109;
    iVar6 = 0;
    while( true ) {
      puVar5 = (undefined8 *)0x50425355;
      lVar3 = ExAllocatePool2(0x40,uVar4);
      if (lVar3 == 0) break;
      puVar5 = &local_res20;
      *puVar2 = 0xb0088;
      puVar2[9] = uVar4;
      *(undefined8 *)(puVar2 + 0xc) = 0;
      *(longlong *)(puVar2 + 10) = lVar3;
      *(undefined4 *)((longlong)puVar2 + 0x82) = 0x200;
      *(undefined8 *)(puVar2 + 0xe) = 0;
      uVar1 = USBPRINT_CallUSBD(param_1,puVar2,puVar5,param_4);
      if ((int)uVar1 < 0) {
        puVar5 = (undefined8 *)(ulonglong)uVar1;
        WriteDbgTraceWarning
                  ("USBPRINT_GetUSBConfigs",
                   L"USBPRINT.SYS: Get Configuration descriptor failed 0x%x",puVar5,param_4);
        ExFreePool(lVar3);
        lVar3 = 0;
        goto LAB_140008ac6;
      }
      if ((puVar2[9] == 0) || (*(ushort *)(lVar3 + 2) <= uVar4)) goto LAB_140008ac6;
      if ((0x6400 < uVar4) || (iVar6 == 10)) {
        WriteDbgTraceWarning
                  ("USBPRINT_GetUSBConfigs",
                   L"USBPRINT.SYS: ConfigureDevice, this device appears to be lying to us about descriptor size"
                   ,puVar5,param_4);
        ExFreePool(lVar3);
        lVar3 = 0;
        uVar1 = 0xc0000182;
        goto LAB_140008ac6;
      }
      uVar4 = (uint)*(ushort *)(lVar3 + 2);
      ExFreePool(lVar3);
      iVar6 = iVar6 + 1;
    }
    uVar1 = 0xc000009a;
    WriteDbgTraceWarning
              ("USBPRINT_GetUSBConfigs",
               L"USBPRINT.SYS: Insufficient resources to allocate configuration descriptor in ConfigureDevice"
               ,puVar5,param_4);
LAB_140008ac6:
    ExFreePool(puVar2);
    if (lVar3 != 0) {
      *param_3 = lVar3;
      goto LAB_140008af7;
    }
  }
  WriteDbgTraceWarning
            ("USBPRINT_GetUSBConfigs",L"USBPRINT.SYS: GetUSBConfigs, No Configuration descriptor.",
             puVar5,param_4);
LAB_140008af7:
  if ((int)uVar1 < 0) {
    WriteDbgTraceInfo("USBPRINT_GetUSBConfigs",L"USBPRINT.SYS: exit USBPRINT_GetUSBConfigs (%x)",
                      (ulonglong)uVar1,param_4);
  }
  return uVar1;
}



===== USBPRINT_PnPAddDevice @ 140008b40 =====

uint USBPRINT_PnPAddDevice
               (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  ulonglong uVar2;
  longlong *plVar3;
  int iVar4;
  wchar_t *pwVar5;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  uVar2 = USBPRINT_CreateDeviceObject(param_1,local_res18);
  uVar1 = (uint)uVar2;
  if (-1 < (int)uVar1) {
    uVar1 = USBPRINT_InitDeviceObject(local_res18[0],param_2,param_3,param_4);
  }
  if (local_res18[0] != 0) {
    *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) & 0xffffff7f;
  }
  uVar2 = Feature_PrintPlatformStabilizationFixes_2502__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 == 0) {
    if (-1 < (int)uVar1) {
      return uVar1;
    }
  }
  else if (-1 < (int)uVar1) {
    iVar4 = 0;
    plVar3 = &g_UsbprintDevices;
    do {
      if (*plVar3 == 0) {
        (&g_UsbprintDevices)[iVar4] = local_res18[0];
        break;
      }
      iVar4 = iVar4 + 1;
      plVar3 = plVar3 + 1;
    } while ((longlong)plVar3 < 0x140014200);
    uVar2 = 0x10;
    if (iVar4 != 0x10) {
      return uVar1;
    }
    pwVar5 = L"USBPRINT.SYS: Can track only %d DEVICE_OBJECTs for surprise unload";
    goto LAB_140008b98;
  }
  uVar2 = (ulonglong)uVar1;
  pwVar5 = L"USBPRINT.SYS: exit USBPRINT_PnPAddDevice (%x)";
LAB_140008b98:
  WriteDbgTraceInfo("USBPRINT_PnPAddDevice",pwVar5,uVar2,param_4);
  return uVar1;
}



===== USBPRINT_PreferIPP @ 140008c04 =====

bool USBPRINT_PreferIPP(void)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  bool bVar4;
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
  
  bVar4 = false;
  local_44 = 0;
  local_2c = 0;
  local_res10 = 0;
  local_res8[0] = 0x14;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  lVar3 = ExAllocatePool2(0x100,0x14,0x50425355);
  bVar1 = false;
  if (lVar3 != 0) {
    RtlInitUnicodeString
              (&local_68,
               L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Print\\Monitors\\USB Monitor"
              );
    RtlInitUnicodeString(&local_58,L"PreferIPP");
    local_38 = &local_68;
    local_48 = 0x30;
    local_40 = 0;
    local_30 = 0x240;
    local_28 = 0;
    uStack_20 = 0;
    iVar2 = ZwOpenKey(&local_res10,1,&local_48);
    if (-1 < iVar2) {
      iVar2 = ZwQueryValueKey(local_res10,&local_58,2,lVar3,local_res8[0],local_res8);
      if (-1 < iVar2) {
        bVar4 = *(int *)(lVar3 + 0xc) != 0;
      }
      ZwClose(local_res10);
    }
    ExFreePool(lVar3);
    bVar1 = bVar4;
  }
  return bVar1;
}



===== USBPRINT_RemoveDevice @ 140008d40 =====

undefined8 USBPRINT_RemoveDevice(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong *plVar7;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  ZwClose(*(undefined8 *)(lVar1 + 0x5c0));
  ZwClose(*(undefined8 *)(lVar1 + 0x5c8));
  lVar5 = 2;
  lVar4 = lVar1 + 0x568;
  lVar6 = 2;
  do {
    if (*(char *)(lVar1 + 0x5f4) == '\0') {
      IoSetDeviceInterfaceState(lVar4,0);
    }
    RtlFreeUnicodeString(lVar4);
    lVar4 = lVar4 + 0x10;
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  uVar2 = Feature_2524085560__private_IsEnabledDeviceUsageNoInline();
  if ((char)uVar2 == '\0') {
    if (*(longlong *)(lVar1 + 0x430) != 0) {
      ExFreePool();
      *(undefined8 *)(lVar1 + 0x430) = 0;
    }
  }
  else {
    ExAcquireFastMutex(lVar1 + 0x438);
    LOCK();
    lVar4 = *(longlong *)(lVar1 + 0x430);
    *(longlong *)(lVar1 + 0x430) = 0;
    UNLOCK();
    ExReleaseFastMutex(lVar1 + 0x438);
    if (lVar4 != 0) {
      ExFreePool(lVar4);
    }
  }
  if (*(longlong *)(lVar1 + 0x4f0) != 0) {
    ExFreePool();
  }
  plVar7 = (longlong *)(lVar1 + 0x588);
  do {
    if (*plVar7 != 0) {
      ExFreePool();
    }
    plVar7 = plVar7 + 1;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  uVar2 = Feature_PrintPlatformStabilizationFixes_2502__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 != 0) {
    iVar3 = 0;
    plVar7 = &g_UsbprintDevices;
    do {
      if (param_1 == *plVar7) {
        (&g_UsbprintDevices)[iVar3] = 0;
        return 0;
      }
      iVar3 = iVar3 + 1;
      plVar7 = plVar7 + 1;
    } while ((longlong)plVar7 < 0x140014200);
  }
  return 0;
}



===== USBPRINT_SelectInterface @ 140008ecc =====

uint USBPRINT_SelectInterface(longlong param_1,undefined8 param_2,int param_3)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  void *_Dst;
  wchar_t *pwVar7;
  int iVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  ushort *_Src;
  longlong lVar11;
  undefined8 local_res20;
  longlong local_58;
  ushort *local_50;
  undefined8 local_48;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar11 = (longlong)param_3;
  local_res20 = 0xfffffffffd050f80;
  lVar4 = 0;
  _Src = (ushort *)0x0;
  iVar8 = 0;
  uVar10 = 0xffffffff;
  uVar5 = 0xffffffff;
  lVar3 = USBD_ParseConfigurationDescriptorEx(param_2);
  if (lVar3 == 0) {
    if (*(int *)(&g_DevInterfaceInfo + lVar11 * 0x10) == 2) {
      WriteDbgTraceWarning
                ("USBPRINT_SelectInterface",
                 L"USBPRINT.SYS: ParseConfigurationDescriptorEx(USB_PRINTER_PROTOCOL_BIDI) failed",
                 uVar5,uVar10);
      uVar5 = 0xffffffff;
      uVar10 = 0xffffffff;
      lVar3 = USBD_ParseConfigurationDescriptorEx
                        (param_2,param_2,0xffffffff,0xffffffff,7,0xffffffff,1);
      if (lVar3 != 0) {
        *(undefined1 *)(lVar1 + 0x538) = 0;
        iVar8 = 1;
        goto LAB_140008fd6;
      }
      WriteDbgTraceWarning
                ("USBPRINT_SelectInterface",
                 L"USBPRINT.SYS:  ParseConfigurationDescriptorEx(USB_PRINTER_PROTOCOL_UNIDIR) failed"
                 ,uVar5,uVar10);
      uVar2 = 0xc0000182;
    }
    else {
      uVar2 = 0xc000000d;
    }
    pwVar7 = L"USBPRINT.SYS: failed to locate apropriate interface";
  }
  else {
    *(undefined1 *)(lVar1 + 0x538) = 1;
    uVar5 = (ulonglong)*(uint *)(&g_DevInterfaceInfo + lVar11 * 0x10);
    WriteDbgTraceInfo("USBPRINT_SelectInterface",
                      L"USBPRINT.SYS: ParseConfigurationDescriptorEx(%d) success",uVar5,uVar10);
    iVar8 = *(int *)(&g_DevInterfaceInfo + lVar11 * 0x10);
LAB_140008fd6:
    local_48 = 0;
    local_58 = lVar3;
    lVar4 = USBD_CreateConfigurationRequestEx(param_2,&local_58);
    if (lVar4 != 0) {
      uVar2 = USBPRINT_CallUSBD(param_1,lVar4,&local_res20,uVar10);
      _Src = local_50;
      goto LAB_140009055;
    }
    uVar2 = 0xc000009a;
    pwVar7 = L"USBPRINT.SYS: CreateConfigurationRequest failed";
  }
  WriteDbgTraceWarning("USBPRINT_SelectInterface",pwVar7,uVar5,uVar10);
LAB_140009055:
  if (-1 < (int)uVar2) {
    uVar5 = Feature_3186517304__private_IsEnabledDeviceUsageNoInline();
    if ((char)uVar5 != '\0') {
      puVar6 = (undefined8 *)(lVar1 + 0x598);
      lVar3 = 2;
      do {
        puVar6[2] = 0;
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
        lVar3 = lVar3 + -1;
      } while (lVar3 != 0);
    }
    *(undefined8 *)(lVar1 + 0x4e8) = *(undefined8 *)(lVar4 + 0x20);
    uVar9 = 0x50425355;
    *(int *)(lVar1 + 0x424) = iVar8;
    _Dst = (void *)ExAllocatePool2(0x40,*_Src);
    if (_Dst == (void *)0x0) {
      uVar2 = 0xc000009a;
      WriteDbgTraceWarning
                ("USBPRINT_SelectInterface",L"USBPRINT.SYS: Alloc failed in SelectInterface",uVar9,
                 uVar10);
      uVar5 = Feature_3186517304__private_IsEnabledDeviceUsageNoInline();
      if ((char)uVar5 != '\0') {
        *(undefined4 *)(lVar1 + 0x424) = 0;
      }
    }
    else {
      memmove(_Dst,_Src,(ulonglong)*_Src);
      lVar3 = 0x588;
      if (iVar8 == 4) {
        lVar3 = 0x590;
      }
      if (*(longlong *)(lVar3 + lVar1) != 0) {
        ExFreePool();
      }
      *(void **)(lVar3 + lVar1) = _Dst;
    }
  }
  if (lVar4 != 0) {
    ExFreePool(lVar4);
  }
  if ((int)uVar2 < 0) {
    WriteDbgTraceInfo("USBPRINT_SelectInterface",L"USBPRINT.SYS: exit USBPRINT_SelectInterface (%x)"
                      ,(ulonglong)uVar2,uVar10);
  }
  return uVar2;
}



===== USBPRINT_StopDevice @ 140009164 =====

undefined4
USBPRINT_StopDevice(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined8 local_res8;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  uVar5 = 0;
  local_res8 = 0xfffffffffd050f80;
  LOCK();
  plVar1 = (longlong *)(lVar3 + 0x5d8);
  lVar2 = *plVar1;
  *plVar1 = 0;
  UNLOCK();
  if (lVar2 != 0) {
    IoCancelIrp();
    *(undefined1 *)(lVar3 + 0x4c0) = 0;
  }
  puVar4 = (undefined4 *)ExAllocatePool2(0x40,0x58,0x50425355);
  if (puVar4 == (undefined4 *)0x0) {
    uVar5 = 0xc000009a;
    WriteDbgTraceInfo("USBPRINT_StopDevice",L"USBPRINT.SYS: exit USBPRINT_StopDevice (%x)",
                      0xc000009a,param_4);
  }
  else {
    *puVar4 = 0x58;
    *(undefined8 *)(puVar4 + 6) = 0;
    USBPRINT_CallUSBD(param_1,puVar4,&local_res8,param_4);
    ExFreePool(puVar4);
  }
  return uVar5;
}



===== USBPRINT_Unload @ 140009230 =====

void USBPRINT_Unload(undefined8 param_1,undefined8 param_2,ulonglong param_3,undefined8 param_4)

{
  undefined8 uVar1;
  ulonglong uVar2;
  longlong *plVar3;
  uint uVar4;
  
  WriteDbgTraceInfo("USBPRINT_Unload",L"USBPRINT.SYS:  enter USBPRINT_Unload",param_3,param_4);
  ClearFreePorts();
  uVar2 = Feature_PrintPlatformStabilizationFixes_2502__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 != 0) {
    uVar4 = 0;
    plVar3 = &g_UsbprintDevices;
    do {
      if (*plVar3 != 0) {
        param_3 = (ulonglong)uVar4;
        WriteDbgTraceInfo("USBPRINT_Unload",L"Calling USBPRINT_RemoveDevice(%d)",param_3,param_4);
        USBPRINT_RemoveDevice((&g_UsbprintDevices)[(int)uVar4]);
        break;
      }
      uVar4 = uVar4 + 1;
      plVar3 = plVar3 + 1;
    } while ((longlong)plVar3 < 0x140014200);
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
  WriteDbgTraceInfo("USBPRINT_Unload",L"USBPRINT.SYS:  exit USBPRINT_Unload",param_3,param_4);
  uVar1 = DAT_140014020;
  DAT_140014020 = 0;
  DAT_140014000 = 0;
  EtwUnregister(uVar1);
  return;
}



===== bAddPortInUseItem @ 140009334 =====

undefined4 bAddPortInUseItem(undefined8 param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  uint *puVar4;
  undefined4 uVar5;
  uint *puVar6;
  
  puVar6 = g_pFreePortList;
  puVar4 = g_pFreePortList;
  do {
    if (g_pFreePortList == (uint *)0x0) {
LAB_140009435:
      uVar5 = 0;
      if (g_pFreePortList == (uint *)0x0) {
        uVar5 = 0xc000000d;
      }
      g_pFreePortList = puVar6;
      return uVar5;
    }
    uVar1 = *g_pFreePortList;
    if ((uVar1 <= param_2) && (uVar2 = g_pFreePortList[1], param_2 <= uVar2)) {
      if (param_2 == uVar1) {
        *g_pFreePortList = uVar1 + 1;
        if (g_pFreePortList[1] < uVar1 + 1) {
          if (g_pFreePortList == puVar6) {
            puVar6 = *(uint **)(g_pFreePortList + 2);
          }
          else {
            *(uint **)(puVar4 + 2) = *(uint **)(g_pFreePortList + 2);
          }
          ExFreePool(g_pFreePortList);
        }
      }
      else if (param_2 == uVar2) {
        g_pFreePortList[1] = uVar2 - 1;
      }
      else {
        piVar3 = (int *)ExAllocatePool2(0x40,0x10,0x50425355);
        if (piVar3 == (int *)0x0) {
          g_pFreePortList = puVar6;
          return 0xc0000017;
        }
        piVar3[1] = g_pFreePortList[1];
        g_pFreePortList[1] = param_2 - 1;
        *piVar3 = param_2 + 1;
        *(undefined8 *)(piVar3 + 2) = *(undefined8 *)(g_pFreePortList + 2);
        *(int **)(g_pFreePortList + 2) = piVar3;
      }
      goto LAB_140009435;
    }
    if (param_2 < uVar1) goto LAB_140009435;
    puVar4 = g_pFreePortList;
    g_pFreePortList = *(uint **)(g_pFreePortList + 2);
  } while( true );
}



===== bDeleteIfRecyclable @ 140009464 =====

undefined1 bDeleteIfRecyclable(undefined8 param_1)

{
  int iVar1;
  undefined1 uVar2;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"recyclable");
  iVar1 = ZwDeleteValueKey(param_1,&local_18);
  uVar2 = 0;
  if (-1 < iVar1) {
    RtlInitUnicodeString(&local_18,L"Port Number");
    iVar1 = ZwDeleteValueKey(param_1,&local_18);
    uVar2 = 0;
    if (-1 < iVar1) {
      uVar2 = 1;
    }
  }
  return uVar2;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1400094f8 =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140009608 =====

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



===== wil_details_GetCurrentFeatureEnabledState @ 14000966c =====

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



===== wil_details_IsEnabledFallback @ 1400097cc =====

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



===== wil_details_RecordCachedUsage @ 140009860 =====

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



===== wil_details_RecordFeatureUsageReporting @ 1400099c0 =====

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



===== Feature_1869851963__private_IsEnabledDeviceUsageNoInline @ 140009a44 =====

ulonglong Feature_1869851963__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_1869851963__private_featureState;
  if ((Feature_1869851963__private_featureState & 0x10) == 0) {
    uVar1 = Feature_1869851963__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)Feature_1869851963__private_featureState & 0xffffffffffffff01;
  }
  return uVar1;
}



===== Feature_1869851963__private_IsEnabledFallback @ 140009a7c =====

void Feature_1869851963__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_1869851963__private_descriptor);
  return;
}



===== Feature_352741691__private_IsEnabledDeviceUsageNoInline @ 140009a98 =====

ulonglong Feature_352741691__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_352741691__private_featureState;
  if ((Feature_352741691__private_featureState & 0x10) == 0) {
    uVar1 = Feature_352741691__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)Feature_352741691__private_featureState & 0xffffffffffffff01;
  }
  return uVar1;
}



===== Feature_352741691__private_IsEnabledFallback @ 140009ad0 =====

void Feature_352741691__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_352741691__private_descriptor);
  return;
}



===== USBPRINT_AbortPipe @ 140009aec =====

void USBPRINT_AbortPipe(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined8 local_res18;
  
  uVar3 = 0x50425355;
  puVar2 = (undefined4 *)ExAllocatePool2(0x40);
  if (puVar2 == (undefined4 *)0x0) {
    WriteDbgTraceWarning
              ("USBPRINT_AbortPipe",L"USBPRINT.SYS: AbortPipe: urb allocation failed",uVar3,param_4)
    ;
  }
  else {
    *puVar2 = 0x20028;
    *(undefined8 *)(puVar2 + 6) = param_2;
    local_res18 = 0xffffffffff676980;
    uVar1 = USBPRINT_CallUSBD(param_1,puVar2,&local_res18,param_4);
    if ((int)uVar1 < 0) {
      WriteDbgTraceWarning
                ("USBPRINT_AbortPipe",L"USBPRINT.SYS: AbortPipe failed 0x%x",(ulonglong)uVar1,
                 param_4);
    }
    ExFreePool(puVar2);
  }
  return;
}



===== USBPRINT_AbortPipes @ 140009ba8 =====

void USBPRINT_AbortPipes(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  uint uVar2;
  longlong *plVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong local_18 [2];
  
  uVar5 = 0;
  local_18[0] = 0;
  local_18[1] = 0;
  plVar7 = (longlong *)(*(longlong *)(param_1 + 0x40) + 0x5a8);
  lVar6 = 2;
  do {
    if (*plVar7 != 0) {
      lVar1 = *(longlong *)(*plVar7 + 8);
      uVar2 = 0;
      uVar4 = (uint)uVar5;
      if (uVar4 != 0) {
        plVar3 = local_18;
        do {
          if (*plVar3 == lVar1) break;
          uVar2 = uVar2 + 1;
          plVar3 = plVar3 + 1;
        } while (uVar2 < uVar4);
      }
      if (uVar2 == uVar4) {
        local_18[uVar5] = lVar1;
        uVar5 = (ulonglong)(uVar4 + 1);
        USBPRINT_AbortPipe(param_1,lVar1,param_3,param_4);
      }
    }
    plVar7 = plVar7 + 1;
    lVar6 = lVar6 + -1;
    if (lVar6 == 0) {
      return;
    }
  } while( true );
}



===== USBPRINT_AddChildDevice @ 140009c38 =====

int USBPRINT_AddChildDevice(longlong param_1,undefined1 param_2)

{
  longlong lVar1;
  undefined1 *puVar2;
  longlong lVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  ulonglong uVar7;
  longlong lVar8;
  wchar_t *pwVar9;
  undefined8 uVar10;
  longlong *plVar11;
  undefined8 uVar12;
  longlong local_res8;
  undefined4 local_res10 [2];
  longlong local_res18 [2];
  
  local_res10[0] = CONCAT31(local_res10[0]._1_3_,param_2);
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_res18[0] = 0;
  LOCK();
  iVar4 = *(int *)(lVar1 + 0x20);
  *(int *)(lVar1 + 0x20) = 1;
  UNLOCK();
  if (iVar4 == 1) {
    return 0;
  }
  uVar12 = 0x16;
  uVar10 = 0;
  iVar4 = IoCreateDevice(USBPRINT_DriverObject,0x18,0,0x16,0x80,1,local_res18);
  if (iVar4 < 0) {
    WriteDbgTraceWarning
              ("USBPRINT_AddChildDevice",
               L"USBPRINT.SYS:  IoCreateDevice failed for USB child device",uVar10,uVar12);
    *(undefined4 *)(lVar1 + 0x20) = 0;
    return iVar4;
  }
  WriteDbgTraceInfo("USBPRINT_AddChildDevice",
                    L"USBPRINT.SYS:  IoCreateDevice succeeded for USB child device",uVar10,uVar12);
  *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) | 0x2000;
  puVar2 = *(undefined1 **)(local_res18[0] + 0x40);
  *(longlong *)(puVar2 + 8) = param_1;
  *(longlong *)(lVar1 + 0x18) = local_res18[0];
  *puVar2 = 1;
  *(undefined4 *)(puVar2 + 0x10) = *(undefined4 *)(lVar1 + 0x5b8);
  IoInvalidateDeviceRelations(*(undefined8 *)(lVar1 + 0x10),0);
  local_res8 = 0;
  uVar7 = Feature_2524085560__private_IsEnabledDeviceUsageNoInline();
  if ((char)uVar7 == '\0') {
    uVar7 = Feature_932690235__private_IsEnabledDeviceUsageNoInline();
    if ((char)uVar7 == '\0') {
      plVar11 = &local_res8;
      uVar7 = GetUsbPrinterName(param_1,*(void **)(lVar1 + 0x430),plVar11,uVar12);
      iVar5 = (int)uVar7;
    }
    else {
      ExAcquireFastMutex(lVar1 + 0x438);
      plVar11 = &local_res8;
      uVar7 = GetUsbPrinterName(param_1,*(void **)(lVar1 + 0x430),plVar11,uVar12);
      iVar5 = (int)uVar7;
      ExReleaseFastMutex(lVar1 + 0x438);
    }
LAB_140009db6:
    if (iVar5 < 0) {
      WriteDbgTraceWarning
                ("USBPRINT_AddChildDevice",
                 L"USBPRINT.SYS: AddChildDevice - GetUsbPrinterName failed.",plVar11,uVar12);
      return iVar4;
    }
  }
  else {
    ExAcquireFastMutex(lVar1 + 0x438);
    plVar11 = &local_res8;
    uVar7 = GetPrinterNameFrom1284Id
                      (*(void **)(lVar1 + 0x430),*(byte *)(lVar1 + 0x470) & 2,plVar11,uVar12);
    ExReleaseFastMutex(lVar1 + 0x438);
    if ((int)uVar7 < 0) {
      uVar7 = GetPrinterNameFromUsbStrings(param_1,&local_res8,plVar11,uVar12);
      iVar5 = (int)uVar7;
      goto LAB_140009db6;
    }
  }
  lVar3 = local_res8;
  WriteDbgTraceInfo("USBPRINT_AddChildDevice",L"USBPRINT.SYS: AddChildDevice - FriendlyName=%ws",
                    local_res8,uVar12);
  lVar8 = -1;
  do {
    lVar8 = lVar8 + 1;
  } while (*(short *)(lVar3 + lVar8 * 2) != 0);
  uVar10 = 0;
  uVar6 = IoSetDevicePropertyData
                    (*(undefined8 *)(lVar1 + 0x10),&DEVPKEY_Device_FriendlyName,0,0,0x12,
                     (int)lVar8 * 2 + 2,lVar3);
  if ((int)uVar6 < 0) {
    pwVar9 = L"USBPRINT.SYS: AddChildDevice - IoSetDevicePropertyData(FriendlyName) failed 0x%x.";
  }
  else {
    uVar10 = 0;
    local_res10[0] = 2;
    uVar6 = IoSetDevicePropertyData
                      (*(undefined8 *)(lVar1 + 0x10),&DEVPKEY_Device_FriendlyNameAttributes,0,0,7,4,
                       local_res10);
    if (-1 < (int)uVar6) goto LAB_140009e7f;
    pwVar9 = 
    L"USBPRINT.SYS: AddChildDevice - IoSetDevicePropertyData(FriendlyNameAttributes) failed 0x%x.";
  }
  WriteDbgTraceWarning("USBPRINT_AddChildDevice",pwVar9,(ulonglong)uVar6,uVar10);
LAB_140009e7f:
  ExFreePool(lVar3);
  return iVar4;
}



===== USBPRINT_DrainPipeUsers @ 140009ed0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint USBPRINT_DrainPipeUsers
               (longlong param_1,undefined8 param_2,undefined8 *param_3,ulonglong param_4)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  char *pcVar4;
  ulonglong uVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  undefined1 auStackY_f8 [32];
  undefined4 uVar9;
  uint local_c8;
  uint local_c4 [3];
  uint local_b8 [2];
  undefined8 local_b0;
  undefined8 local_a8 [4];
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
  
  lVar3 = _DAT_fffff78000000008;
  local_38 = __security_cookie ^ (ulonglong)auStackY_f8;
  lVar2 = *(longlong *)(param_1 + 0x40);
  uVar7 = 0;
  uVar8 = 0;
  local_b0 = 0xfffffffffffe7960;
  do {
    uVar1 = *(uint *)(lVar2 + 0x560);
    if (uVar1 < 3) {
      uVar7 = 0xc0000056;
      if (*(char *)(lVar2 + 0x564) != '\0') {
        uVar7 = 0;
      }
LAB_140009f94:
      uVar5 = _DAT_fffff78000000008 - lVar3;
      if (uVar7 == 0) {
        pcVar4 = (char *)0x4;
        if (DAT_140014000 < 5) {
          return 0;
        }
        local_88 = &local_c8;
        local_78 = local_c4;
        pbVar6 = &DAT_140012a91;
        uVar9 = 4;
        local_c8 = (uint)(uVar5 / 10000);
        local_c4[0] = uVar8;
      }
      else {
        param_4 = (ulonglong)uVar1;
        pcVar4 = "USBPRINT_DrainPipeUsers";
        param_3 = (undefined8 *)(ulonglong)uVar7;
        WriteDbgTraceWarning
                  ("USBPRINT_DrainPipeUsers",
                   L"USBPRINT.SYS: SwitchProtocol drain failed 0x%x, PendingIoCount=%u after %u ms, %u aborts"
                   ,param_3,param_4);
        if (DAT_140014000 < 3) {
          return uVar7;
        }
        local_88 = local_c4;
        pbVar6 = &DAT_140012ace;
        local_78 = &local_c8;
        local_68 = local_c4 + 1;
        local_58 = local_c4 + 2;
        local_48 = local_b8;
        uVar9 = 7;
        local_c4[1] = 2;
        local_60 = 4;
        local_50 = 4;
        local_40 = 4;
        local_c8 = uVar1;
        local_c4[0] = uVar7;
        local_c4[2] = (int)(uVar5 / 10000);
        local_b8[0] = uVar8;
      }
      local_70 = 4;
      local_80 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(pcVar4,pbVar6,param_3,param_4,uVar9,local_a8);
      return uVar7;
    }
    if (99999999 < (ulonglong)(_DAT_fffff78000000008 - lVar3)) {
      uVar7 = 0x102;
      goto LAB_140009f94;
    }
    if (uVar7 == (int)((ulonglong)uVar7 / 10) * 10) {
      USBPRINT_AbortPipes(param_1,(ulonglong)uVar7 / 10,param_3,param_4);
      uVar8 = uVar8 + 1;
    }
    param_3 = &local_b0;
    KeDelayExecutionThread(0,0);
    uVar7 = uVar7 + 1;
  } while( true );
}



===== USBPRINT_GetPortStatus @ 14000a100 =====

uint USBPRINT_GetPortStatus(longlong param_1,uint *param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  *param_2 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_38 = 0;
  uStack_30 = 0;
  KeInitializeEvent(&local_28,0);
  uVar6 = 0;
  uVar5 = 0;
  lVar3 = IoBuildDeviceIoControlRequest
                    (0x220013,*(undefined8 *)(lVar1 + 8),0,0,0,0,1,&local_28,&local_38);
  if (lVar3 == 0) {
    local_38 = CONCAT44(local_38._4_4_,0xc0000017);
    uVar4 = 0xc0000017;
  }
  else {
    *(uint **)(*(longlong *)(lVar3 + 0xb8) + -0x40) = param_2;
    iVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 8),lVar3);
    if (iVar2 == 0x103) {
      uVar6 = 0;
      KeWaitForSingleObject(&local_28,5,0,0,0);
    }
    else {
      local_38 = CONCAT44(local_38._4_4_,iVar2);
      if (iVar2 < 0) {
        WriteDbgTraceWarning
                  ("USBPRINT_GetPortStatus",L"USBPRINT.SYS: IoCallDriver(GET_PORT_STATUS) failed",
                   uVar5,uVar6);
      }
    }
    WriteDbgTraceInfo("USBPRINT_GetPortStatus",L"USBPRINT.SYS: Port status = %x",(ulonglong)*param_2
                      ,uVar6);
    uVar4 = (uint)local_38;
  }
  if ((int)uVar4 < 0) {
    WriteDbgTraceInfo("USBPRINT_GetPortStatus",L"USBPRINT.SYS: USBPRINT_GetPortStatus (%x)",
                      (ulonglong)uVar4,uVar6);
  }
  return uVar4;
}



===== GetCheckSum @ 14000a240 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void GetCheckSum(byte *param_1,ushort param_2,ushort *param_3)

{
  byte bVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ushort uVar4;
  ulonglong uVar5;
  ushort local_58 [32];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)local_58;
  uVar5 = 0;
  uVar4 = 0;
  local_58[0] = 0;
  local_58[1] = 0xc0c1;
  local_58[2] = 0xc181;
  local_58[3] = 0x140;
  local_58[4] = 0xc301;
  local_58[5] = 0x3c0;
  local_58[6] = 0x280;
  local_58[7] = 0xc241;
  local_58[8] = 0xc601;
  local_58[9] = 0x6c0;
  local_58[10] = 0x780;
  local_58[0xb] = 0xc741;
  local_58[0xc] = 0x500;
  local_58[0xd] = 0xc5c1;
  local_58[0xe] = 0xc481;
  local_58[0xf] = 0x440;
  local_58[0x10] = 0;
  local_58[0x11] = 0xcc01;
  local_58[0x12] = 0xd801;
  local_58[0x13] = 0x1400;
  local_58[0x14] = 0xf001;
  local_58[0x15] = 0x3c00;
  local_58[0x16] = 0x2800;
  local_58[0x17] = 0xe401;
  local_58[0x18] = 0xa001;
  local_58[0x19] = 0x6c00;
  local_58[0x1a] = 0x7800;
  local_58[0x1b] = 0xb401;
  local_58[0x1c] = 0x5000;
  local_58[0x1d] = 0x9c01;
  local_58[0x1e] = 0x8801;
  local_58[0x1f] = 0x4600;
  if (param_2 != 0) {
    uVar3 = (ulonglong)param_2;
    do {
      bVar1 = *param_1;
      param_1 = param_1 + 1;
      uVar2 = (ulonglong)bVar1 ^ uVar5 & 0xff;
      uVar4 = (ushort)(uVar5 >> 8) ^ local_58[(uVar2 >> 4) + 0x10] ^ local_58[(uint)uVar2 & 0xf];
      uVar5 = (ulonglong)uVar4;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  *param_3 = uVar4;
  return;
}



===== DbgTraceWorker @ 14000a32c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void DbgTraceWorker(int param_1,char *param_2,wchar_t *param_3,va_list param_4)

{
  undefined8 uVar1;
  wchar_t *pwVar2;
  byte *pbVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  va_list pcVar6;
  undefined1 auStackY_3c8 [32];
  undefined1 local_398 [32];
  longlong local_378 [2];
  longlong local_368 [2];
  wchar_t local_358 [400];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_3c8;
  pwVar2 = local_358;
  pwVar5 = param_3;
  pcVar6 = param_4;
  uVar1 = RtlStringCchVPrintfW(local_358,400,param_3,param_4);
  pwVar4 = (wchar_t *)0x0;
  if ((int)uVar1 < 0) {
    pwVar2 = (wchar_t *)ExAllocatePool2(0x100,0x7800,0x63617254);
    pwVar4 = pwVar2;
    if (pwVar2 != (wchar_t *)0x0) {
      uVar1 = RtlStringCchVPrintfW(pwVar2,0x7800,param_3,param_4);
      pwVar5 = param_3;
      pcVar6 = param_4;
      if ((int)uVar1 < 0) goto LAB_14000a434;
      goto LAB_14000a3b8;
    }
  }
  else {
LAB_14000a3b8:
    if (param_1 == 1) {
      if (4 < DAT_140014000) {
        _tlgCreate1Sz_char(local_378,param_2);
        _tlgCreate1Sz_wchar_t(local_368,pwVar2);
        pbVar3 = &DAT_140012b33;
        goto LAB_14000a418;
      }
    }
    else if ((param_1 == 2) && (3 < DAT_140014000)) {
      _tlgCreate1Sz_char(local_378,param_2);
      _tlgCreate1Sz_wchar_t(local_368,pwVar2);
      pbVar3 = &DAT_140012b60;
LAB_14000a418:
      _tlgWriteTransfer_EtwWriteTransfer(local_398,pbVar3,pwVar5,pcVar6,4,(undefined8 *)local_398);
    }
  }
  if (pwVar4 == (wchar_t *)0x0) {
    return;
  }
LAB_14000a434:
  ExFreePool(pwVar4);
  return;
}



===== RtlStringCchVPrintfW @ 14000a474 =====

undefined8 RtlStringCchVPrintfW(wchar_t *param_1,longlong param_2,wchar_t *param_3,va_list param_4)

{
  ulonglong _Count;
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 - 1U < 0x7fffffff) {
    _Count = param_2 - 1;
    uVar2 = 0;
    iVar1 = _vsnwprintf(param_1,_Count,param_3,param_4);
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



===== _tlgDefineProvider_annotation__TlgUsbprintLoggingProv @ 14000a4f8 =====

void _tlgDefineProvider_annotation__TlgUsbprintLoggingProv(void)

{
  return;
}



===== _guard_check_icall @ 14000a510 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 14000a528 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000a54c =====

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



===== wcscmp @ 14000a5b6 =====

int __cdecl wcscmp(wchar_t *_Str1,wchar_t *_Str2)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000a5b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = wcscmp(_Str1,_Str2);
  return iVar1;
}



===== __cpu_features_init @ 14000a5d0 =====

/* WARNING: Removing unreachable block (ram,0x00014000a63a) */
/* WARNING: Removing unreachable block (ram,0x00014000a5e9) */
/* WARNING: Removing unreachable block (ram,0x00014000a5da) */

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



===== __security_check_cookie @ 14000a6a0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 14000a6e0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 14000a710 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014000a710. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 14000a740 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 14000a7c0 =====

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



===== memset @ 14000aac0 =====

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



===== __memset_repmovs @ 14000ac00 =====

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



===== __memset_query @ 14000ac80 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 14000ad00 =====

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



===== __memset_spec_ermsb_repmovsb @ 14000ae40 =====

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



===== __memset_spec_plain @ 14000aec0 =====

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



===== wil_details_EvaluateFeatureDependencies @ 140017010 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  uint uVar2;
  ulonglong uVar3;
  bool bVar4;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding
                     ((longlong *)&Feature_932690235__private_descriptor);
  if (plVar1 != (longlong *)0x0) {
    uVar3 = 0;
    do {
      uVar2 = *(uint *)*plVar1;
      if ((uVar2 >> 9 & 1) != 0) {
        if ((uVar2 & 0x180) == 0) {
          bVar4 = *(char *)((longlong)plVar1 + 0x1f) != '\0';
        }
        else {
          bVar4 = (uVar2 & 0x180) == 0x100;
        }
        uVar2 = uVar2 & 0x40 ^ (uint)bVar4 << 6 | (uint)uVar3 & 0xffffffbf;
        uVar3 = (ulonglong)uVar2;
        LOCK();
        *(uint *)*plVar1 = *(uint *)*plVar1 ^ uVar2;
        UNLOCK();
      }
      plVar1 = wil_details_FeatureDescriptors_SkipPadding(plVar1 + 7);
    } while (plVar1 != (longlong *)0x0);
  }
  for (plVar1 = wil_details_FeatureDescriptors_SkipPadding
                          ((longlong *)&Feature_932690235__private_descriptor);
      plVar1 != (longlong *)0x0; plVar1 = wil_details_FeatureDescriptors_SkipPadding(plVar1 + 7)) {
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
  }
  return;
}



===== USBPRINT_QueryCapabilities @ 1400170d4 =====

undefined8
USBPRINT_QueryCapabilities
          (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  lVar4 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c),0);
  if (lVar4 == 0) {
    uVar5 = 0xc000009a;
  }
  else {
    lVar1 = *(longlong *)(lVar4 + 0xb8);
    *(undefined4 *)(lVar4 + 0x30) = 0xc00000bb;
    *(undefined2 *)(lVar1 + -0x48) = 0x91b;
    KeInitializeEvent(&local_28,0,0);
    lVar2 = *(longlong *)(lVar4 + 0xb8);
    *(code **)(lVar2 + -0x10) = USBPRINT_DeferIrpCompletion;
    *(undefined8 **)(lVar2 + -8) = &local_28;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    *(undefined8 *)(lVar1 + -0x40) = param_2;
    uVar3 = IofCallDriver(param_1,lVar4);
    if (uVar3 == 0x103) {
      KeWaitForSingleObject(&local_28,5,0,0,0);
    }
    else if ((int)uVar3 < 0) {
      WriteDbgTraceWarning
                ("USBPRINT_QueryCapabilities",L"USBPRINT.SYS:  QueryCapabilities failed 0x%x",
                 (ulonglong)uVar3,param_4);
    }
    IoFreeIrp(lVar4);
    uVar5 = 0;
  }
  return uVar5;
}



===== USBPRINT_SystemControl @ 1400171f0 =====

undefined4
USBPRINT_SystemControl(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  char *pcVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  
  pcVar1 = *(char **)(param_1 + 0x40);
  uVar2 = *(undefined8 *)(pcVar1 + 8);
  USBPRINT_IncrementIoCount(param_1);
  if (*pcVar1 == '\x01') {
    WriteDbgTraceInfo("USBPRINT_SystemControl",L"USBPRINT.SYS: unsupported child SystemControl IRP",
                      param_3,param_4);
    uVar3 = *(undefined4 *)(param_2 + 0x30);
    lVar4 = 0;
    IofCompleteRequest(param_2);
    param_2 = lVar4;
  }
  else {
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    uVar3 = IofCallDriver(uVar2);
  }
  USBPRINT_DecrementIoCount(param_1,param_2,param_3,param_4);
  return uVar3;
}



===== _tlgEnableCallback @ 140017290 =====

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



===== wil_RtlStagingConfig_QueryFeatureState @ 14001730c =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 1400173d8 =====

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
      goto LAB_140017435;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_140017435;
    }
  }
  uVar1 = 0x206;
LAB_140017435:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140017440 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 140017478 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_1400174fa;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_1400174fa;
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
LAB_1400174fa:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140017550 =====

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
      ppuVar3 = &Feature_932690235__private_descriptor;
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 1400175b0 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 1400175cc =====

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
  ppuVar3 = &Feature_932690235__private_descriptor;
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



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 140017680 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(void)

{
  undefined2 uVar1;
  code *pcVar2;
  ulonglong uVar3;
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
  local_28 = *(undefined4 *)(PTR_DAT_140014008 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_140014008 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_140014008 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_140014008 + -4);
  if (DAT_140014020 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  _DAT_140014028 = 0;
  uRam0000000140014030 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x1400176e2;
  uVar3 = EtwRegister(puVar4 + 0x20,_tlgEnableCallback,&DAT_140014000,&DAT_140014020);
  if ((int)uVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_140014008;
    *(undefined8 *)(puVar4 + -8) = 0x140017709;
    EtwSetInformation(DAT_140014020,2,PTR_DAT_140014008,uVar1);
    uVar3 = uVar3 & 0xffffffff;
  }
  *(undefined8 *)(puVar4 + -8) = 0x14001771d;
  return uVar3;
}



===== entry @ 140018010 =====

void entry(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2,param_3,param_4);
  return;
}



===== __security_init_cookie @ 140018044 =====

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



===== wil_InitializeFeatureStaging @ 140018078 =====

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
    ppuVar4 = &Feature_932690235__private_descriptor;
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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140018170 =====

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
  uint uStack_1c;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  ppuVar4 = &Feature_932690235__private_descriptor;
  while (*ppuVar4 == (undefined *)0x0) {
    ppuVar4 = ppuVar4 + 1;
    if (&WilStagingVulcanDumpWorkaround <= ppuVar4) {
      return;
    }
  }
  if (ppuVar4 == (undefined **)0x0) {
    return;
  }
  do {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    if ((*(char *)((longlong)ppuVar4 + 0x1d) == '\0') &&
       (*(char *)((longlong)ppuVar4 + 0x1e) == '\0')) {
      iVar3 = RtlQueryFeatureConfiguration
                        (*(undefined4 *)(ppuVar4 + 3),
                         1 < (byte)(*(char *)((longlong)ppuVar4 + 0x1c) - 2U),&local_28,
                         &stack0xffffffffffffffe0);
      if (iVar3 == -0x7fffffde) {
        do {
          puVar2 = (undefined8 *)*ppuVar4;
          ppuVar4 = ppuVar4 + 7;
          *puVar2 = 0x206;
          if (&UNK_140013c17 < ppuVar4) {
            return;
          }
          while (*ppuVar4 == (undefined *)0x0) {
            ppuVar4 = ppuVar4 + 1;
            if (&UNK_140013c17 < ppuVar4) {
              return;
            }
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_140018278;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((uStack_1c & 0x40) << 2 | uStack_1c & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_140018278;
        local_28 = (ulonglong)((uStack_1c & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_140018278:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    if (&UNK_140013c17 < ppuVar4) {
      return;
    }
    while (*ppuVar4 == (undefined *)0x0) {
      ppuVar4 = ppuVar4 + 1;
      if (&UNK_140013c17 < ppuVar4) {
        return;
      }
    }
    if (ppuVar4 == (undefined **)0x0) {
      return;
    }
  } while( true );
}


