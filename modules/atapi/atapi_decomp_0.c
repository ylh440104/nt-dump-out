
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



===== AtapiChannelInitialize @ 140001020 =====

undefined8 AtapiChannelInitialize(undefined1 *param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 *puVar2;
  
  *param_1 = *(undefined1 *)(param_2 + 2);
  lVar1 = 2;
  *(undefined4 *)(param_1 + 0x84) = 1;
  puVar2 = (undefined4 *)(param_1 + 0xac);
  do {
    *puVar2 = 3;
    puVar2 = puVar2 + 0xe;
    lVar1 = lVar1 + -1;
  } while (lVar1 != 0);
  *(code **)(param_2 + 8) = AtapiHwInitialize;
  *(code **)(param_2 + 0x10) = AtapiHwBuildIo;
  *(code **)(param_2 + 0x18) = AtapiHwStartIo;
  *(code **)(param_2 + 0x20) = AtapiHwInterrupt;
  *(code **)(param_2 + 0x28) = AtapiHwReset;
  *(code **)(param_2 + 0x30) = AtapiHwControl;
  return 1;
}



===== AtapiCheckStatusAsync @ 1400010a0 =====

undefined8 AtapiCheckStatusAsync(undefined1 *param_1,undefined1 *param_2,undefined *param_3)

{
  uint uVar1;
  char cVar2;
  undefined8 uVar3;
  code *pcVar4;
  
  uVar3 = *(undefined8 *)(param_1 + 0x48);
  do {
    cVar2 = AtaPortReadPortUchar(uVar3);
    param_2 = (undefined1 *)CONCAT71((int7)((ulonglong)param_2 >> 8),cVar2);
    pcVar4 = (code *)param_3;
    if (-1 < cVar2) {
LAB_140001170:
      *(undefined4 *)(param_1 + 0xa4) = 0;
      uVar3 = AtapiSelectDeviceAsync(param_1,param_2,pcVar4);
LAB_14000117f:
      return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
    }
    uVar1 = *(uint *)(param_1 + 0xa4);
    *(uint *)(param_1 + 0xa4) = uVar1 + 1;
    if ((119999 < uVar1) || (cVar2 == -1)) {
      if (param_1[0x9c] != '\0') {
        param_2 = param_1;
        AtaPortNotification(0,param_1,0xff,0);
      }
      pcVar4 = AtapiCheckStatusAsync;
      param_2 = (undefined1 *)CONCAT71((int7)((ulonglong)param_2 >> 8),1);
      AtapiDeviceErrorHistoryLog
                ((longlong)param_1,'\x01',AtapiCheckStatusAsync,5,60000,(undefined1 *)0x0,0);
      goto LAB_140001170;
    }
    if (*(int *)(param_1 + 0x8c) != 1) {
      pcVar4 = AtapiCheckStatusAsync;
      param_2 = param_1;
      uVar3 = AtaPortRequestCallback(0,param_1);
      param_3 = pcVar4;
      if ((char)uVar3 != '\0') goto LAB_14000117f;
    }
    AtaPortStallExecution(500);
    uVar3 = *(undefined8 *)(param_1 + 0x48);
  } while( true );
}



===== AtapiCompleteRequest @ 140001190 =====

char AtapiCompleteRequest(undefined1 *param_1,ushort *param_2,undefined8 param_3,undefined1 param_4)

{
  ushort *puVar1;
  char cVar2;
  undefined1 uVar3;
  uint uVar4;
  ushort *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined7 uVar8;
  
  uVar3 = (undefined1)param_3;
  uVar8 = (undefined7)((ulonglong)param_3 >> 8);
  *(undefined1 *)((longlong)param_2 + 3) = uVar3;
  *(undefined1 *)(param_2 + 2) = param_4;
  *(undefined8 *)(param_1 + 0x70) = 0;
  cVar2 = (char)param_2[1];
  if (cVar2 == '\x02') {
    *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) - *(int *)(param_1 + 0x80);
  }
  else if (cVar2 != '\x01') {
    if (cVar2 == '\a') {
      uVar3 = *(undefined1 *)((longlong)param_2 + 7);
      AtaPortDeviceStateChange(param_1,(char)param_2[3],uVar3,4);
    }
    else {
      param_2[0xc] = 0;
      param_2[0xd] = 0;
    }
  }
  *(undefined8 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  if ((*param_2 >> 9 & 1) == 0) {
LAB_14000125b:
    if (*param_2 != 0x201) {
      uVar4 = *(uint *)(param_2 + 8);
      if ((uVar4 & 0x20) != 0) {
        puVar7 = *(undefined1 **)(param_2 + 0x18);
        puVar6 = puVar7;
        AtapiTaskRegisterSnapshot((longlong)(param_1 + 8),puVar7);
        uVar4 = *(uint *)(param_2 + 8);
        if ((uVar4 & 8) == 0) {
          *(undefined1 *)(param_2 + 5) = 1;
        }
        else {
          *(undefined1 *)(param_2 + 5) = 2;
          uVar3 = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x58));
          AtaPortWritePortUchar
                    (*(undefined8 *)(param_1 + 0x58),
                     CONCAT71((int7)((ulonglong)puVar6 >> 8),uVar3) | 0x80);
          puVar7 = puVar7 + 8;
          AtapiTaskRegisterSnapshot((longlong)(param_1 + 8),puVar7);
          AtaPortWritePortUchar
                    (*(undefined8 *)(param_1 + 0x58),
                     CONCAT71((int7)((ulonglong)puVar7 >> 8),uVar3) & 0xffffffffffffff7f);
          uVar4 = *(uint *)(param_2 + 8);
        }
        *(byte *)(param_2 + 1) = (byte)param_2[1] | 0x10;
      }
      if ((((uVar4 >> 10 & 1) != 0) && (param_1[0xa3] != '\0')) && ((char)param_2[1] == '\x01')) {
        *(undefined1 *)(param_2 + 1) = 0x81;
      }
      goto LAB_14000131c;
    }
  }
  else if (*param_2 != 0x201) {
    if (((((char)param_2[1] == '\x03') && (*(longlong *)(param_2 + 0x18) != 0)) &&
        (*(char *)((longlong)param_2 + 9) != '\0')) &&
       (puVar5 = (ushort *)AtaPortBuildRequestSenseIrb(param_1,param_2), puVar5 != (ushort *)0x0)) {
      *(ushort **)(puVar5 + 0x1c) = param_2;
      AtapiHwStartIo(param_1,puVar5,CONCAT71(uVar8,uVar3));
      return '\0';
    }
    goto LAB_14000125b;
  }
  puVar5 = *(ushort **)(param_2 + 0x1c);
  AtaPortReleaseRequestSenseIrb(param_1,param_2);
  if (cVar2 == '\x01') {
    puVar1 = puVar5 + 1;
    *(byte *)puVar1 = (byte)*puVar1 | 0x20;
  }
  param_2 = puVar5;
LAB_14000131c:
  AtaPortCompleteRequest(param_1,param_2);
  return cVar2;
}



===== AtapiDeviceErrorHistoryLog @ 140001350 =====

void AtapiDeviceErrorHistoryLog
               (longlong param_1,char param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5,undefined1 *param_6,undefined1 param_7)

{
  if (param_2 == '\0') {
    AtaPortQuerySystemTime(param_1 + ((ulonglong)*(byte *)(param_1 + 0x130) * 5 + 0x27) * 8);
    *(undefined8 *)(param_1 + ((ulonglong)*(byte *)(param_1 + 0x130) + 8) * 0x28) = param_3;
    *(undefined4 *)(param_1 + 0x148 + (ulonglong)*(byte *)(param_1 + 0x130) * 0x28) = param_4;
    *(undefined4 *)(param_1 + 0x14c + (ulonglong)*(byte *)(param_1 + 0x130) * 0x28) = param_5;
    *(undefined1 *)(param_1 + 0x158 + (ulonglong)*(byte *)(param_1 + 0x130) * 0x28) = param_7;
    if (param_6 != (undefined1 *)0x0) {
      *(undefined1 *)(param_1 + 0x156 + (ulonglong)*(byte *)(param_1 + 0x130) * 0x28) = param_6[6];
      *(undefined1 *)(param_1 + 0x154 + (ulonglong)*(byte *)(param_1 + 0x130) * 0x28) = param_6[4];
      *(undefined1 *)(param_1 + 0x153 + (ulonglong)*(byte *)(param_1 + 0x130) * 0x28) = param_6[3];
      *(undefined1 *)(param_1 + 0x155 + (ulonglong)*(byte *)(param_1 + 0x130) * 0x28) = param_6[5];
      *(undefined1 *)(param_1 + 0x150 + (ulonglong)*(byte *)(param_1 + 0x130) * 0x28) = *param_6;
      *(undefined1 *)(param_1 + 0x157 + (ulonglong)*(byte *)(param_1 + 0x130) * 0x28) = param_6[7];
      *(undefined1 *)(param_1 + 0x151 + (ulonglong)*(byte *)(param_1 + 0x130) * 0x28) = param_6[1];
      *(undefined1 *)(param_1 + 0x152 + (ulonglong)*(byte *)(param_1 + 0x130) * 0x28) = param_6[2];
    }
    *(char *)(param_1 + 0x130) = *(char *)(param_1 + 0x130) + '\x01';
    if (0x3e < *(byte *)(param_1 + 0x130)) {
      *(undefined1 *)(param_1 + 0x130) = 0;
    }
  }
  else if (param_2 == '\x01') {
    AtaPortQuerySystemTime(param_1 + ((ulonglong)*(byte *)(param_1 + 0xb38) + 0x48) * 0x28);
    *(undefined8 *)(param_1 + 0xb48 + (ulonglong)*(byte *)(param_1 + 0xb38) * 0x28) = param_3;
    *(undefined4 *)(param_1 + 0xb50 + (ulonglong)*(byte *)(param_1 + 0xb38) * 0x28) = param_4;
    *(undefined4 *)(param_1 + 0xb54 + (ulonglong)*(byte *)(param_1 + 0xb38) * 0x28) = param_5;
    *(undefined1 *)(param_1 + 0xb60 + (ulonglong)*(byte *)(param_1 + 0xb38) * 0x28) = param_7;
    if (param_6 != (undefined1 *)0x0) {
      *(undefined1 *)(param_1 + 0xb5e + (ulonglong)*(byte *)(param_1 + 0xb38) * 0x28) = param_6[6];
      *(undefined1 *)(param_1 + 0xb5c + (ulonglong)*(byte *)(param_1 + 0xb38) * 0x28) = param_6[4];
      *(undefined1 *)(param_1 + 0xb5b + (ulonglong)*(byte *)(param_1 + 0xb38) * 0x28) = param_6[3];
      *(undefined1 *)(param_1 + 0xb5d + (ulonglong)*(byte *)(param_1 + 0xb38) * 0x28) = param_6[5];
      *(undefined1 *)(param_1 + 0xb58 + (ulonglong)*(byte *)(param_1 + 0xb38) * 0x28) = *param_6;
      *(undefined1 *)(param_1 + 0xb5f + (ulonglong)*(byte *)(param_1 + 0xb38) * 0x28) = param_6[7];
      *(undefined1 *)(param_1 + 0xb59 + (ulonglong)*(byte *)(param_1 + 0xb38) * 0x28) = param_6[1];
      *(undefined1 *)(param_1 + 0xb5a + (ulonglong)*(byte *)(param_1 + 0xb38) * 0x28) = param_6[2];
    }
    *(char *)(param_1 + 0xb38) = *(char *)(param_1 + 0xb38) + '\x01';
    if (0x3e < *(byte *)(param_1 + 0xb38)) {
      *(undefined1 *)(param_1 + 0xb38) = 0;
    }
  }
  return;
}



===== AtapiDisarmDma @ 140001614 =====

byte AtapiDisarmDma(longlong param_1)

{
  longlong lVar1;
  byte bVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x68);
  bVar2 = AtaPortReadPortUchar(lVar1 + 2);
  AtaPortWritePortUchar(lVar1,0);
  AtaPortWritePortUchar(lVar1 + 2,4);
  *(undefined1 *)(param_1 + 0x9f) = 0;
  return -((bVar2 + 1 & 0x7f) != 0) & bVar2;
}



===== AtapiHandleAtaCommand @ 1400016a0 =====

void AtapiHandleAtaCommand(undefined1 *param_1,short *param_2,undefined8 param_3)

{
  char cVar1;
  undefined8 uVar2;
  undefined7 uVar3;
  
  uVar3 = (undefined7)((ulonglong)param_3 >> 8);
  *(short **)(param_1 + 0x70) = param_2;
  *(undefined8 *)(param_1 + 0x78) = *(undefined8 *)(param_2 + 0x14);
  *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(param_2 + 0xc);
  **(undefined8 **)(param_2 + 0x10) = AtapiHandleAtaCommand;
  if (*param_2 == 0x101) {
    uVar2 = AtapiSendAtaIdentify((longlong)param_1,(longlong)param_2,param_3);
    cVar1 = (char)uVar2;
  }
  else {
    cVar1 = AtapiSendAtaCommand(param_1,(longlong)param_2);
  }
  if (cVar1 != '\0') {
    *(char *)(param_2 + 1) = cVar1;
    AtapiCompleteRequest
              (param_1,(ushort *)param_2,CONCAT71(uVar3,*(undefined1 *)((longlong)param_2 + 3)),
               (char)param_2[2]);
  }
  return;
}



===== AtapiHandleMiniportCommand @ 140001718 =====

char AtapiHandleMiniportCommand(longlong param_1,short *param_2)

{
  short sVar1;
  longlong lVar2;
  ushort *puVar3;
  char cVar4;
  ulonglong uVar5;
  
  sVar1 = *param_2;
  if ((sVar1 == 0x401) || (sVar1 == 0x402)) {
    cVar4 = '\x01';
  }
  else {
    if (sVar1 == 0x403) {
      if (*(int *)(param_2 + 0x26) == 1) {
        uVar5 = AtapiTargetPowerUp(param_1,(longlong)param_2);
        cVar4 = (char)uVar5;
      }
      else {
        uVar5 = AtapiTargetPowerDown(param_1,(longlong)param_2);
        cVar4 = (char)uVar5;
      }
    }
    else {
      if (sVar1 != 0x404) {
        if (sVar1 == 0x405) {
          cVar4 = '\x01';
          if (((0x1b < *(uint *)(param_2 + 0xc)) &&
              (lVar2 = *(longlong *)(param_2 + 0x14), *(char *)(lVar2 + 4) == 'A')) &&
             (*(int *)(lVar2 + 0x10) == 1)) {
            *(undefined4 *)(lVar2 + 0x14) = 1;
          }
        }
        else {
          cVar4 = '\x04';
        }
        goto LAB_1400017cd;
      }
      puVar3 = *(ushort **)(param_1 + 0x70);
      cVar4 = '\x04';
      if ((puVar3 != (ushort *)0x0) && (*puVar3 == 0x101)) {
        *(undefined1 *)(puVar3 + 1) = 5;
        AtapiCompleteRequest
                  ((undefined1 *)param_1,puVar3,(ulonglong)*(byte *)((longlong)puVar3 + 3),
                   (char)puVar3[2]);
        cVar4 = '\x01';
      }
    }
    if (cVar4 == '\0') {
      return '\0';
    }
  }
LAB_1400017cd:
  *(char *)(param_2 + 1) = cVar4;
  AtaPortCompleteRequest(param_1,param_2);
  return cVar4;
}



===== AtapiHwBuildIo @ 140001800 =====

undefined8 AtapiHwBuildIo(longlong param_1,ushort *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  
  if (((*(uint *)(param_1 + 0x88) & 8) != 0) && ((*(uint *)(param_2 + 0xc) & 3) != 0)) {
    if ((*param_2 >> 9 & 1) == 0) {
      *(undefined1 *)(param_2 + 1) = 4;
    }
    else {
      *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) & 0xfffffffd;
    }
  }
  uVar2 = (ulonglong)*(uint *)(param_1 + 0x88);
  if ((*(uint *)(param_1 + 0x88) & 0x10) != 0) {
    uVar1 = *(uint *)(param_2 + 0xc);
    uVar2 = (ulonglong)uVar1;
    if ((0x2000 < uVar1) && (uVar1 = (uVar1 & 0x1fff) - 1, uVar2 = (ulonglong)uVar1, uVar1 < 0x1ff))
    {
      if ((*param_2 >> 9 & 1) == 0) {
        *(undefined1 *)(param_2 + 1) = 4;
      }
      else {
        *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) & 0xfffffffd;
      }
    }
  }
  return CONCAT71((int7)(uVar2 >> 8),1);
}



===== AtapiHwControl @ 140001870 =====

ulonglong AtapiHwControl(byte *param_1,int param_2,longlong param_3)

{
  ulonglong in_RAX;
  undefined8 uVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  if (param_2 == 0) {
    uVar2 = AtapiTranslateResources(param_1,*(uint **)(param_3 + 0x10));
    if ((char)uVar2 != '\0') {
      AtaPortWritePortUchar(*(undefined8 *)(param_1 + 0x58),0);
      param_1[0x98] = 0;
      param_1[0x99] = 0x10;
      param_1[0x9a] = 0;
      param_1[0x9b] = 0;
      lVar3 = AtaPortGetUnCachedExtension(param_1,0x1000,0x1000);
      *(longlong *)(param_1 + 0x90) = lVar3;
      uVar2 = 0;
      if (lVar3 != 0) {
        *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_3 + 0x20);
        in_RAX = (ulonglong)*(uint *)(param_3 + 8);
        *(uint *)(param_1 + 0x8c) = *(uint *)(param_3 + 8);
        *(undefined2 *)(param_3 + 0x18) = 0x101;
        param_1[0xa3] = 0;
        goto LAB_140001915;
      }
    }
    uVar2 = uVar2 & 0xffffffffffffff00;
  }
  else {
    if (param_2 == 1) {
      param_1[0x90] = 0;
      param_1[0x91] = 0;
      param_1[0x92] = 0;
      param_1[0x93] = 0;
      param_1[0x94] = 0;
      param_1[0x95] = 0;
      param_1[0x96] = 0;
      param_1[0x97] = 0;
      param_1[0x98] = 0;
      param_1[0x99] = 0;
      param_1[0x9a] = 0;
      param_1[0x9b] = 0;
    }
    else if (param_2 == 2) {
      uVar1 = AtapiHwReset(param_1);
      return uVar1;
    }
LAB_140001915:
    uVar2 = CONCAT71((int7)(in_RAX >> 8),1);
  }
  return uVar2;
}



===== AtapiHwInitialize @ 140001930 =====

undefined8 AtapiHwInitialize(longlong param_1,longlong param_2,ulonglong param_3)

{
  byte bVar1;
  undefined8 uVar2;
  
  AtapiInitializeDevice(param_1,param_2,param_3);
  bVar1 = *(byte *)(param_2 + 8);
  uVar2 = AtaPortCopyMemory(((ulonglong)bVar1 + 3) * 0x38 + param_1,param_2,0x38);
  *(undefined1 *)((ulonglong)bVar1 + 0xa1 + param_1) = 0;
  *(undefined1 *)(param_1 + 0x9c) = 1;
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== AtapiHwInterrupt @ 1400019a0 =====

byte AtapiHwInterrupt(undefined1 *param_1)

{
  ushort *puVar1;
  byte bVar2;
  undefined7 uVar5;
  undefined8 uVar3;
  undefined1 *puVar4;
  byte local_res8 [8];
  
  bVar2 = 0;
  if (*(longlong *)(param_1 + 0x68) != 0) {
    bVar2 = AtaPortReadPortUchar(*(longlong *)(param_1 + 0x68) + 2);
    bVar2 = -((bVar2 + 1 & 0x7f) != 0) & bVar2;
    if ((bVar2 & 4) == 0) {
      if (param_1[0x9f] != '\0') {
        return 0;
      }
    }
    else if (param_1[0x9f] == '\0') {
      AtaPortWritePortUchar(*(longlong *)(param_1 + 0x68) + 2,4);
    }
    else {
      AtapiDisarmDma((longlong)param_1);
    }
  }
  puVar1 = *(ushort **)(param_1 + 0x70);
  if (puVar1 == (ushort *)0x0) {
    AtaPortReadPortUchar();
    return bVar2 & 4;
  }
  local_res8[0] = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x48));
  if ((param_1[0x9e] != '\0') && ((char)local_res8[0] < '\0')) {
    return 0;
  }
  uVar3 = 0;
  WaitOnBusyUntil((longlong)(param_1 + 8),(char *)local_res8,0x14,(longlong)param_1,(char)puVar1[3],
                  AtapiHwInterrupt,(undefined1 *)(puVar1 + 0x24));
  uVar5 = (undefined7)((ulonglong)uVar3 >> 8);
  if ((char)local_res8[0] < '\0') {
    if (*(int *)(param_1 + 0x8c) == 1) {
      return 0;
    }
    *(undefined1 *)(puVar1 + 1) = 6;
    uVar3 = CONCAT71(uVar5,local_res8[0]);
    bVar2 = local_res8[0];
  }
  else {
    if ((local_res8[0] & 1) == 0) {
      AtapiProcessInterrupt(param_1,puVar1,CONCAT71(uVar5,bVar2),local_res8[0]);
      return 1;
    }
    bVar2 = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x18));
    puVar4 = param_1;
    WaitOnDrq((longlong)(param_1 + 8),local_res8,(longlong)param_1,(char)puVar1[3],AtapiHwInterrupt,
              (undefined1 *)(puVar1 + 0x24));
    uVar3 = CONCAT71((int7)((ulonglong)puVar4 >> 8),local_res8[0]);
    *(undefined1 *)(puVar1 + 1) = 3;
  }
  AtapiCompleteRequest(param_1,puVar1,uVar3,bVar2);
  return 1;
}



===== AtapiHwReset @ 140001b40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 AtapiHwReset(undefined1 *param_1)

{
  undefined8 uVar1;
  ushort *puVar2;
  undefined1 *puVar3;
  undefined *puVar4;
  undefined1 auStack_48 [32];
  undefined4 local_28;
  undefined1 local_24;
  undefined1 local_23;
  undefined2 local_22;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_23 = *param_1;
  local_22 = 0xffff;
  uVar1 = 0;
  local_20 = 0;
  local_28 = 8;
  local_24 = 0xff;
  local_1c = 1;
  AtaPortEtwTraceLog(5,&local_28);
  if (param_1[0x9f] != '\0') {
    AtaPortReadPortUchar(*(longlong *)(param_1 + 0x68) + 2);
    AtapiDisarmDma((longlong)param_1);
  }
  puVar2 = *(ushort **)(param_1 + 0x70);
  if (puVar2 != (ushort *)0x0) {
    *(undefined1 *)(puVar2 + 1) = 5;
    uVar1 = 0;
    AtapiCompleteRequest(param_1,puVar2,0,0);
  }
  puVar4 = (undefined *)CONCAT71((int7)((ulonglong)uVar1 >> 8),0xff);
  puVar3 = (undefined1 *)CONCAT71((int7)((ulonglong)puVar2 >> 8),0xff);
  AtaPortCompleteAllActiveRequests(param_1,puVar3,puVar4,5);
  AtapiIssueSoftReset((longlong)param_1);
  if (param_1[0x9d] == '\0') {
    puVar4 = (undefined *)CONCAT71((int7)((ulonglong)puVar4 >> 8),0xff);
    param_1[0x9d] = 1;
    puVar3 = (undefined1 *)CONCAT71((int7)((ulonglong)puVar3 >> 8),0xff);
    AtaPortDeviceStateChange(param_1,puVar3,puVar4,0xb4);
  }
  *(undefined4 *)(param_1 + 0xa4) = 0;
  uVar1 = AtapiCheckStatusAsync(param_1,puVar3,puVar4);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== AtapiHwStartIo @ 140001c50 =====

undefined8 AtapiHwStartIo(undefined1 *param_1,ushort *param_2,undefined8 param_3)

{
  char cVar1;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 extraout_var_01;
  undefined7 extraout_var_02;
  undefined7 uVar2;
  undefined7 uVar3;
  
  uVar3 = (undefined7)((ulonglong)param_3 >> 8);
  if ((*param_2 >> 9 & 1) == 0) {
    if ((*param_2 >> 8 & 1) == 0) {
      AtapiHandleMiniportCommand((longlong)param_1,(short *)param_2);
      uVar2 = extraout_var_02;
    }
    else {
      AtapiHandleAtaCommand(param_1,(short *)param_2,param_3);
      uVar2 = extraout_var_01;
    }
  }
  else {
    *(ushort **)(param_1 + 0x70) = param_2;
    *(undefined8 *)(param_1 + 0x78) = *(undefined8 *)(param_2 + 0x14);
    *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(param_2 + 0xc);
    cVar1 = AtapiSendAtapiCommand((longlong)param_1,(longlong)param_2);
    uVar2 = extraout_var;
    if (cVar1 != '\0') {
      *(char *)(param_2 + 1) = cVar1;
      AtapiCompleteRequest
                (param_1,param_2,CONCAT71(uVar3,*(undefined1 *)((longlong)param_2 + 3)),
                 (char)param_2[2]);
      uVar2 = extraout_var_00;
    }
  }
  return CONCAT71(uVar2,1);
}



===== AtapiInitializeDevice @ 140001cc8 =====

char AtapiInitializeDevice(longlong param_1,longlong param_2,ulonglong param_3)

{
  undefined3 uVar1;
  uint uVar2;
  char cVar3;
  byte bVar4;
  uint uVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined8 local_res10;
  
  if (*(int *)(param_2 + 4) == 3) {
    return '\x01';
  }
  cVar3 = '\x01';
  uVar5 = *(uint *)(param_2 + 0x30) & 0x1f;
  if (uVar5 == 0) {
LAB_140001d25:
    uVar5 = *(uint *)(param_2 + 0x30) & 0x7fffffe0;
    if (uVar5 != 0) {
      uVar2 = 0;
      do {
        uVar7 = uVar2;
        uVar5 = uVar5 >> 1;
        param_3 = (ulonglong)uVar7;
        uVar2 = uVar7 + 1;
      } while (uVar5 != 0);
      if (4 < uVar7) {
        cVar3 = (char)uVar7;
        uVar1 = (undefined3)(uVar7 >> 8);
        if (uVar7 < 0xb) {
          if (uVar7 < 8) {
            param_3 = (ulonglong)CONCAT31(uVar1,cVar3 + -5) | 0x10;
          }
          else {
            param_3 = (ulonglong)CONCAT31(uVar1,cVar3 + -8) | 0x20;
          }
        }
        else {
          param_3 = (ulonglong)CONCAT31(uVar1,cVar3 + -0xb) | 0x40;
        }
        uVar6 = AtapiSetTransferMode(param_1,*(byte *)(param_2 + 8),param_3);
        cVar3 = (char)uVar6;
      }
    }
  }
  else {
    uVar2 = 0;
    do {
      uVar7 = uVar2;
      uVar5 = uVar5 >> 1;
      param_3 = (ulonglong)uVar7;
      uVar2 = uVar7 + 1;
    } while (uVar5 != 0);
    if (uVar7 < 3) goto LAB_140001d25;
    param_3 = (ulonglong)uVar7 | 8;
    uVar6 = AtapiSetTransferMode(param_1,*(byte *)(param_2 + 8),param_3);
    cVar3 = (char)uVar6;
    if (cVar3 != '\0') goto LAB_140001d25;
  }
  if (cVar3 == '\0') {
    *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) & 0x1f;
  }
  if ((*(byte *)(param_2 + 0xc) & 4) != 0) {
    if (*(char *)(param_1 + 0x129) == '\0') {
      param_3 = CONCAT71((int7)(param_3 >> 8),*(byte *)(param_2 + 8));
      local_res10._0_6_ = CONCAT15((*(byte *)(param_2 + 8) & 1 | 0xfa) << 4,0x95);
      local_res10._0_7_ = CONCAT16(0xef,(undefined6)local_res10);
      local_res10 = (ulonglong)(uint7)local_res10;
      bVar4 = AtapiSendInternalAtaCommand(param_1,(undefined1 *)&local_res10,param_3);
      if ((bVar4 & 1) == 0) {
        cVar3 = '\x01';
        goto LAB_140001de1;
      }
      AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x18));
    }
    cVar3 = '\0';
    *(ushort *)(param_2 + 0xc) = *(ushort *)(param_2 + 0xc) & 0xfffb;
  }
LAB_140001de1:
  if (*(int *)(param_2 + 4) != 1) {
    return cVar3;
  }
  if (*(char *)(param_1 + 0x129) == '\0') {
    if (*(int *)(param_2 + 0x10) != 1) goto LAB_140001e41;
    param_3 = CONCAT71((int7)(param_3 >> 8),*(byte *)(param_2 + 8));
    local_res10._0_5_ = (uint5)*(byte *)(param_2 + 0x1c) << 8;
    local_res10._0_6_ =
         CONCAT15((*(byte *)(param_2 + 8) & 1 | 0xfa) << 4 | *(char *)(param_2 + 0x1a) - 1U,
                  (int5)local_res10);
    local_res10._0_7_ = CONCAT16(0x91,(undefined6)local_res10);
    local_res10 = (ulonglong)(uint7)local_res10;
    bVar4 = AtapiSendInternalAtaCommand(param_1,(undefined1 *)&local_res10,param_3);
    if ((bVar4 & 0x81) == 0) goto LAB_140001e41;
  }
  *(undefined4 *)(param_2 + 4) = 3;
LAB_140001e41:
  if (*(char *)(param_1 + 0x129) == '\0') {
    local_res10._0_5_ = (uint5)*(byte *)(param_2 + 0xb) << 8;
    local_res10._0_6_ = CONCAT15((*(byte *)(param_2 + 8) & 1 | 0xfa) << 4,(int5)local_res10);
    local_res10._0_7_ = CONCAT16(0xc6,(undefined6)local_res10);
    local_res10 = (ulonglong)(uint7)local_res10;
    bVar4 = AtapiSendInternalAtaCommand
                      (param_1,(undefined1 *)&local_res10,
                       CONCAT71((int7)(param_3 >> 8),*(byte *)(param_2 + 8)));
    if ((bVar4 & 1) == 0) {
      return '\x01';
    }
  }
  *(undefined1 *)(param_2 + 0xb) = 0;
  return '\0';
}



===== AtapiIssueSoftReset @ 140001eb0 =====

void AtapiIssueSoftReset(longlong param_1)

{
  AtaPortWritePortUchar(*(undefined8 *)(param_1 + 0x40),0xa0);
  AtaPortWritePortUchar(*(undefined8 *)(param_1 + 0x58));
  AtaPortStallExecution(10);
  AtaPortWritePortUchar(*(undefined8 *)(param_1 + 0x58));
  AtaPortStallExecution(2000);
  AtapiDeviceErrorHistoryLog(param_1,'\0',AtapiIssueSoftReset,0,2,(undefined1 *)0x0,0);
  AtapiDeviceErrorHistoryLog(param_1,'\x01',AtapiIssueSoftReset,0,2,(undefined1 *)0x0,0);
  return;
}



===== AtapiNoDeviceConnected @ 140001f6c =====

bool AtapiNoDeviceConnected(longlong param_1,char *param_2,char param_3,char param_4)

{
  char cVar1;
  char cVar2;
  int iVar3;
  bool bVar4;
  
  cVar2 = *param_2;
  bVar4 = false;
  if (cVar2 == -1) {
    bVar4 = true;
  }
  else if ((cVar2 == '\x7f') || ((param_3 != '\0' && (cVar2 == '\0')))) {
    iVar3 = 0;
    bVar4 = true;
    do {
      AtaPortStallExecution(5000);
      cVar1 = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x48));
      *param_2 = cVar1;
      if (cVar1 != cVar2) break;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
    if ((param_3 == '\0') || (cVar1 != '\0')) {
      bVar4 = cVar1 == '\x7f';
    }
    else {
      cVar2 = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x20));
      cVar1 = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x28));
      if ((cVar2 == '\x01') && (cVar1 == '\x01')) {
        bVar4 = false;
      }
      *(bool *)(param_1 + 0xa3) = bVar4;
      if ((bVar4 != false) && (param_4 != '\0')) {
        bVar4 = false;
      }
    }
  }
  return bVar4;
}



===== AtapiProcessInterrupt @ 140002070 =====

void AtapiProcessInterrupt(undefined1 *param_1,ushort *param_2,ulonglong param_3,byte param_4)

{
  uint uVar1;
  longlong lVar2;
  uint3 uVar3;
  byte bVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  ushort uVar8;
  longlong lVar9;
  uint uVar10;
  ulonglong uVar11;
  char cVar12;
  uint uVar13;
  undefined1 *puVar14;
  int iVar15;
  byte local_res8 [8];
  
  uVar7 = 0;
  cVar12 = '\0';
  if ((*param_2 & 0x200) == 0) {
    uVar10 = *(uint *)(param_2 + 8);
    if (((uVar10 & 2) == 0) && ((param_4 & 8) != 0)) {
      if ((uVar10 & 0x40) == 0) {
        if ((char)uVar10 < '\0') {
          uVar8 = 0;
        }
        else {
          uVar8 = 0x8000;
        }
      }
      else {
        uVar8 = 2;
      }
      goto LAB_140002147;
    }
LAB_1400022e0:
    if ((*(uint *)(param_2 + 8) & 2) == 0) {
      cVar12 = (*(int *)(param_1 + 0x80) != 0) + '\x01';
      goto LAB_14000232c;
    }
    *(undefined8 *)(param_1 + 0x78) = 0;
    *(undefined4 *)(param_1 + 0x80) = 0;
    if ((param_3 & 2) == 0) {
      if (((param_3 & 1) == 0) ||
         (((*param_2 >> 8 & 1) != 0 && ((*(uint *)(param_1 + 0x88) & 4) != 0)))) {
        cVar12 = '\x01';
      }
      else {
        cVar12 = '\x02';
      }
      goto LAB_14000232c;
    }
  }
  else {
    bVar4 = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x20));
    bVar4 = bVar4 & 3;
    uVar8 = (ushort)bVar4;
    if (bVar4 == 0) {
      if (((param_4 & 8) == 0) || (-1 < (char)*(undefined4 *)(param_2 + 8))) goto LAB_1400020f9;
    }
    else if ((bVar4 == 2) && (((param_4 & 8) == 0 || ((*(uint *)(param_2 + 8) & 0x40) == 0)))) {
LAB_1400020f9:
      uVar8 = 0x8000;
    }
    param_3 = param_3 & 0xff;
LAB_140002147:
    if (uVar8 == 1) {
      AtaPortWritePortBufferUshort(*(undefined8 *)(param_1 + 0x10),param_2 + 0x24,6);
      uVar10 = *(uint *)(param_2 + 8);
      *(uint *)(param_2 + 8) = uVar10 & 0xfffeffff;
      if ((uVar10 & 2) == 0) {
        return;
      }
      uVar3 = (uint3)(uVar10 >> 8);
      uVar11 = CONCAT71((uint7)uVar3,9);
      if ((uVar10 & 0x40) == 0) {
        uVar11 = (ulonglong)CONCAT31(uVar3,1);
      }
      AtaPortWritePortUchar(*(undefined8 *)(param_1 + 0x68),uVar11);
      param_1[0x9f] = 1;
      return;
    }
    if (uVar8 == 3) goto LAB_1400022e0;
    if (((uVar8 & 0xfffd) == 0) && (uVar10 = *(uint *)(param_2 + 8), (uVar10 & 2) == 0)) {
      lVar2 = *(longlong *)(param_1 + 0x78);
      uVar1 = *(uint *)(param_1 + 0x80);
      if ((*param_2 & 0x200) == 0) {
        lVar9 = ((ulonglong)(byte)param_2[3] + 3) * 0x38;
        uVar13 = *(uint *)(param_1 + lVar9 + 0x20);
        if ((param_1[lVar9 + 0xb] != 0) && ((uVar10 & 0x10) != 0)) {
          uVar13 = uVar13 * (byte)param_1[lVar9 + 0xb];
        }
        if (uVar13 == 0) {
          uVar13 = 0x200;
        }
      }
      else {
        uVar5 = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x30));
        uVar6 = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x38));
        uVar10 = *(uint *)(param_2 + 8);
        uVar13 = (uint)CONCAT11(uVar6,uVar5);
      }
      if (uVar1 < uVar13) {
        uVar13 = uVar1;
      }
      if ((uVar10 & 0x40) == 0) {
        AtaPortWritePortBufferUshort(*(undefined8 *)(param_1 + 0x10),lVar2,uVar13 >> 1);
        if ((uVar13 & 1) != 0) {
          AtaPortWritePortUchar
                    (*(undefined8 *)(param_1 + 0x10),
                     *(undefined1 *)((ulonglong)(uVar13 - 1) + lVar2));
        }
        iVar15 = uVar1 - uVar13;
      }
      else {
        AtaPortReadPortBufferUshort();
        if ((uVar13 & 1) != 0) {
          uVar5 = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x10));
          *(undefined1 *)((ulonglong)(uVar13 - 1) + lVar2) = uVar5;
        }
        iVar15 = uVar1 - uVar13;
        if (((*param_2 >> 9 & 1) == 0) && (iVar15 == 0)) {
          cVar12 = '\x01';
        }
      }
      *(int *)(param_1 + 0x80) = iVar15;
      *(ulonglong *)(param_1 + 0x78) = (ulonglong)uVar13 + lVar2;
      if (cVar12 == '\0') {
        return;
      }
      goto LAB_14000232c;
    }
  }
  cVar12 = '\x03';
LAB_14000232c:
  local_res8[0] = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x48));
  puVar14 = param_1;
  WaitOnDrq((longlong)(param_1 + 8),local_res8,(longlong)param_1,(char)param_2[3],
            AtapiProcessInterrupt,(undefined1 *)(param_2 + 0x24));
  if ((local_res8[0] & 1) != 0) {
    uVar7 = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x18));
  }
  *(char *)(param_2 + 1) = cVar12;
  AtapiCompleteRequest
            (param_1,param_2,CONCAT71((int7)((ulonglong)puVar14 >> 8),local_res8[0]),uVar7);
  return;
}



===== AtapiProgramTaskFile @ 1400023b8 =====

void AtapiProgramTaskFile(longlong param_1,undefined1 *param_2,char param_3)

{
  if (param_3 != '\0') {
    AtaPortWritePortUchar(*(undefined8 *)(param_1 + 0x38),param_2[5]);
  }
  AtaPortWritePortUchar(*(undefined8 *)(param_1 + 0x10),*param_2);
  AtaPortWritePortUchar(*(undefined8 *)(param_1 + 0x18),param_2[1]);
  AtaPortWritePortUchar(*(undefined8 *)(param_1 + 0x20),param_2[2]);
  AtaPortWritePortUchar(*(undefined8 *)(param_1 + 0x28),param_2[3]);
  AtaPortWritePortUchar(*(undefined8 *)(param_1 + 0x30),param_2[4]);
  if (param_3 != '\0') {
    AtaPortWritePortUchar(*(undefined8 *)(param_1 + 0x40),param_2[6]);
  }
  return;
}



===== AtapiReInitDevices @ 140002480 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AtapiReInitDevices(undefined1 *param_1)

{
  byte bVar1;
  undefined1 auStack_48 [32];
  undefined4 local_28;
  undefined1 local_24;
  undefined1 local_23;
  undefined2 local_22;
  undefined4 local_20;
  uint local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  if (param_1[0x9c] != '\0') {
    while( true ) {
      bVar1 = param_1[0x128];
      if (1 < bVar1) break;
      if (param_1[0x12a] != '\0') goto LAB_1400024ea;
      if (*(int *)(param_1 + (ulonglong)bVar1 * 0x38 + 0xac) != 3) {
        AtapiSetPioTransferModeAsync((longlong)param_1,(ulonglong)bVar1);
        return;
      }
      param_1[0x128] = bVar1 + 1;
    }
  }
  if (param_1[0x12a] != '\0') {
LAB_1400024ea:
    AtaPortNotification(0,param_1,0xff,0);
  }
  local_23 = *param_1;
  local_22 = 0xffff;
  local_28 = 8;
  local_1c = (uint)(param_1[0x12a] == '\0');
  local_24 = 0xff;
  local_20 = 0;
  AtaPortEtwTraceLog(6,&local_28);
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined2 *)(param_1 + 0x128) = 0;
  *(undefined8 *)(param_1 + 0x118) = 0;
  *(undefined8 *)(param_1 + 0x120) = 0;
  param_1[0x12a] = 0;
  if (param_1[0x9d] == '\0') {
    param_1[0x9d] = 1;
  }
  else {
    param_1[0x9d] = 0;
  }
  AtaPortDeviceStateChange(param_1,0xff,0xff,0);
  return;
}



===== AtapiResetAtapiDevices @ 1400025c0 =====

void AtapiResetAtapiDevices(undefined1 *param_1,undefined8 param_2,undefined8 param_3)

{
  byte bVar1;
  int6 local_res8;
  undefined2 uStackX_e;
  
  bVar1 = param_1[0x128];
  while( true ) {
    if (1 < bVar1) {
      *(undefined4 *)(param_1 + 0xa4) = 0;
      *(code **)(param_1 + 0x120) = AtapiReInitDevices;
      param_1[0x128] = 0;
      AtapiReInitDevices(param_1);
      return;
    }
    if (*(int *)(param_1 + (ulonglong)bVar1 * 0x38 + 0xac) == 2) break;
    bVar1 = bVar1 + 1;
    param_1[0x128] = bVar1;
  }
  _local_res8 = CONCAT26(8,(uint6)(byte)((bVar1 & 1 | 0xfa) << 4) << 0x28);
  AtapiSendInternalAtaCommandAsync
            ((longlong)param_1,(undefined1 *)&local_res8,
             CONCAT71((int7)((ulonglong)param_3 >> 8),bVar1));
  *(undefined4 *)(param_1 + 0x118) = 1;
  *(code **)(param_1 + 0x120) = AtapiResetAtapiDevices;
  *(undefined4 *)(param_1 + 0x11c) = 10000;
  AtapiWaitStatusAsync((longlong)param_1);
  return;
}



===== AtapiSelectDeviceAsync @ 140002680 =====

undefined8 AtapiSelectDeviceAsync(undefined1 *param_1,undefined1 *param_2,undefined *param_3)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  undefined8 uVar4;
  undefined7 uVar5;
  code *pcVar6;
  
  iVar1 = *(int *)(param_1 + 0xac);
  pcVar6 = (code *)param_3;
  do {
    uVar5 = (undefined7)((ulonglong)param_2 >> 8);
    if ((iVar1 != 3) || (*(int *)(param_1 + 0xe4) == 3)) {
      param_2 = (undefined1 *)CONCAT71(uVar5,0xa0);
      AtaPortWritePortUchar(*(undefined8 *)(param_1 + 0x40));
LAB_140002799:
      AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x48));
LAB_1400027a9:
      *(undefined4 *)(param_1 + 0xa4) = 0;
      *(code **)(param_1 + 0x120) = AtapiResetAtapiDevices;
      *(undefined2 *)(param_1 + 0x128) = 0x100;
      uVar4 = AtapiResetAtapiDevices(param_1,param_2,pcVar6);
LAB_1400027cf:
      return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
    }
    uVar4 = CONCAT71(uVar5,0xb0);
    AtaPortWritePortUchar(*(undefined8 *)(param_1 + 0x40),uVar4);
    AtaPortStallExecution(10);
    uVar4 = CONCAT71((int7)((ulonglong)uVar4 >> 8),0xaa);
    AtaPortWritePortUchar(*(undefined8 *)(param_1 + 0x20),uVar4);
    param_2 = (undefined1 *)CONCAT71((int7)((ulonglong)uVar4 >> 8),0x55);
    AtaPortWritePortUchar(*(undefined8 *)(param_1 + 0x28));
    AtaPortStallExecution(0x14);
    cVar3 = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x20));
    if ((cVar3 == -0x56) &&
       (cVar3 = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x28)), cVar3 == 'U'))
    goto LAB_140002799;
    uVar2 = *(uint *)(param_1 + 0xa4);
    *(uint *)(param_1 + 0xa4) = uVar2 + 1;
    if (59999 < uVar2) {
      if (param_1[0x9c] != '\0') {
        param_2 = param_1;
        AtaPortNotification(1,param_1);
      }
      pcVar6 = AtapiSelectDeviceAsync;
      param_2 = (undefined1 *)CONCAT71((int7)((ulonglong)param_2 >> 8),1);
      AtapiDeviceErrorHistoryLog
                ((longlong)param_1,'\x01',AtapiSelectDeviceAsync,6,30000,(undefined1 *)0x0,0);
      goto LAB_1400027a9;
    }
    if (*(int *)(param_1 + 0x8c) != 1) {
      pcVar6 = AtapiSelectDeviceAsync;
      param_2 = param_1;
      uVar4 = AtaPortRequestCallback(0,param_1);
      if ((char)uVar4 != '\0') goto LAB_1400027cf;
    }
    AtaPortStallExecution(500);
    iVar1 = *(int *)(param_1 + 0xac);
  } while( true );
}



===== AtapiSendAtaCommand @ 140002830 =====

char AtapiSendAtaCommand(undefined1 *param_1,longlong param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  byte bVar3;
  uint uVar4;
  longlong lVar5;
  uint3 uVar6;
  bool bVar7;
  char cVar8;
  undefined1 uVar9;
  longlong lVar10;
  ulonglong uVar11;
  uint uVar12;
  uint uVar13;
  byte local_res8 [8];
  
  puVar1 = param_1 + 8;
  uVar11 = CONCAT71((int7)((ulonglong)param_2 >> 8),*(undefined1 *)(param_2 + 6)) &
           0xffffffffffffff01;
  AtaPortWritePortUchar
            (*(undefined8 *)(param_1 + 0x40),
             CONCAT71((int7)(uVar11 >> 8),((byte)uVar11 | 0xfa) << 4));
  local_res8[0] = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x48));
  bVar7 = AtapiNoDeviceConnected
                    ((longlong)param_1,(char *)local_res8,*(char *)(param_2 + 6) == '\x01',
                     (byte)(*(uint *)(param_2 + 0x10) >> 10) & 1);
  if (bVar7) {
    *(byte *)(param_2 + 3) = local_res8[0];
LAB_1400028b6:
    cVar8 = '\x06';
  }
  else {
    puVar2 = (undefined1 *)(param_2 + 0x48);
    WaitOnBusyUntil((longlong)puVar1,(char *)local_res8,10,(longlong)param_1,*(char *)(param_2 + 6),
                    AtapiSendAtaCommand,puVar2);
    if ((char)local_res8[0] < '\0') {
      *(byte *)(param_2 + 3) = local_res8[0];
      bVar3 = param_1[(ulonglong)*(byte *)(param_2 + 6) + 0xa1];
      param_1[(ulonglong)*(byte *)(param_2 + 6) + 0xa1] = bVar3 + 1;
    }
    else {
      if ((((*(uint *)(param_2 + 0x10) & 1) == 0) || ((local_res8[0] & 0x40) != 0)) ||
         (uVar11 = (ulonglong)*(byte *)(param_2 + 6), *(int *)(param_1 + uVar11 * 0x38 + 0xac) != 1)
         ) {
        if ((*(uint *)(param_2 + 0x10) & 2) != 0) {
          AtapiSetupPrdTable((longlong)param_1,param_2);
        }
        if ((*(uint *)(param_2 + 0x10) & 8) != 0) {
          AtapiProgramTaskFile((longlong)puVar1,(undefined1 *)(param_2 + 0x50),'\0');
        }
        AtapiProgramTaskFile((longlong)puVar1,puVar2,'\x01');
        uVar12 = *(uint *)(param_2 + 0x10);
        if ((uVar12 & 2) != 0) {
          uVar6 = (uint3)(uVar12 >> 8);
          uVar11 = CONCAT71((uint7)uVar6,9);
          if ((uVar12 & 0x40) == 0) {
            uVar11 = (ulonglong)CONCAT31(uVar6,1);
          }
          AtaPortWritePortUchar(*(undefined8 *)(param_1 + 0x68),uVar11);
          param_1[0x9f] = 1;
          return '\0';
        }
        if (-1 < (char)uVar12) {
          return '\0';
        }
        lVar5 = *(longlong *)(param_1 + 0x78);
        uVar4 = *(uint *)(param_1 + 0x80);
        lVar10 = ((ulonglong)*(byte *)(param_2 + 6) + 3) * 0x38;
        uVar13 = *(uint *)(param_1 + lVar10 + 0x20);
        if ((param_1[lVar10 + 0xb] != 0) && ((uVar12 & 0x10) != 0)) {
          uVar13 = uVar13 * (byte)param_1[lVar10 + 0xb];
        }
        if (uVar13 == 0) {
          uVar13 = 0x200;
        }
        uVar12 = uVar4;
        if (uVar13 <= uVar4) {
          uVar12 = uVar13;
        }
        local_res8[0] = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x48));
        WaitOnBusyUntil((longlong)puVar1,(char *)local_res8,500,(longlong)param_1,
                        *(char *)(param_2 + 6),AtapiSendAtaCommand,puVar2);
        bVar3 = local_res8[0];
        if (-1 < (char)local_res8[0]) {
          if ((local_res8[0] & 1) != 0) {
            uVar9 = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x18));
            *(undefined1 *)(param_2 + 4) = uVar9;
            *(byte *)(param_2 + 3) = bVar3;
            return '\x03';
          }
          WaitForDrqUntil((longlong)puVar1,local_res8,200,(longlong)param_1,*(char *)(param_2 + 6),
                          AtapiSendAtaCommand,puVar2);
          if ((local_res8[0] & 8) != 0) {
            AtaPortWritePortBufferUshort(*(undefined8 *)(param_1 + 0x10),lVar5,uVar12 >> 1);
            if ((uVar12 & 1) != 0) {
              AtaPortWritePortUchar
                        (*(undefined8 *)(param_1 + 0x10),
                         *(undefined1 *)((ulonglong)(uVar12 - 1) + lVar5));
            }
            *(ulonglong *)(param_1 + 0x78) = (ulonglong)uVar12 + lVar5;
            *(uint *)(param_1 + 0x80) = uVar4 - uVar12;
            return '\0';
          }
        }
        bVar3 = local_res8[0];
        AtapiHwReset(param_1);
        *(byte *)(param_2 + 3) = bVar3;
        goto LAB_1400028b6;
      }
      *(byte *)(param_2 + 3) = local_res8[0];
      bVar3 = param_1[uVar11 + 0xa1];
      param_1[uVar11 + 0xa1] = bVar3 + 1;
    }
    cVar8 = (bVar3 < 6) + '\x06';
  }
  return cVar8;
}



===== AtapiSendAtaIdentify @ 140002b30 =====

undefined8 AtapiSendAtaIdentify(longlong param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined1 *puVar2;
  undefined7 extraout_var;
  undefined8 uVar3;
  ulonglong uVar4;
  bool bVar5;
  byte local_res8 [8];
  
  lVar1 = param_1 + 8;
  uVar4 = CONCAT71((int7)((ulonglong)param_2 >> 8),*(undefined1 *)(param_2 + 6)) &
          0xffffffffffffff01;
  AtaPortWritePortUchar
            (*(undefined8 *)(param_1 + 0x40),CONCAT71((int7)(uVar4 >> 8),((byte)uVar4 | 0xfa) << 4))
  ;
  local_res8[0] = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x48));
  puVar2 = (undefined1 *)(param_2 + 0x48);
  if (*(int *)(param_1 + 0x8c) - 1U < 2) {
    param_3 = 800;
    WaitOnBusyUntil(lVar1,(char *)local_res8,800,param_1,*(char *)(param_2 + 6),AtapiSendAtaIdentify
                    ,puVar2);
  }
  bVar5 = *(char *)(param_2 + 6) == '\x01';
  uVar3 = CONCAT71((int7)((ulonglong)param_3 >> 8),bVar5);
  bVar5 = AtapiNoDeviceConnected
                    (param_1,(char *)local_res8,bVar5,(byte)(*(uint *)(param_2 + 0x10) >> 10) & 1);
  uVar4 = CONCAT71(extraout_var,bVar5);
  if (bVar5) {
    uVar3 = CONCAT71(extraout_var,5);
  }
  else {
    if (-1 < (char)local_res8[0]) {
      uVar4 = (ulonglong)*(uint *)(param_2 + 0x10);
      if ((*(uint *)(param_2 + 0x10) & 1) == 0) {
LAB_140002c26:
        uVar4 = AtapiProgramTaskFile(lVar1,puVar2,'\x01');
        return uVar4 & 0xffffffffffffff00;
      }
      if (*(char *)(param_1 + 0x9c) == '\0') {
        uVar4 = WaitForDrdyUntil(lVar1,local_res8,uVar3,param_1,*(char *)(param_2 + 6),
                                 AtapiSendAtaIdentify,puVar2);
      }
      if ((local_res8[0] & 0x40) != 0) goto LAB_140002c26;
    }
    uVar3 = CONCAT71((int7)(uVar4 >> 8),6);
  }
  *(byte *)(param_2 + 3) = local_res8[0];
  return uVar3;
}



===== AtapiSendAtapiCommand @ 140002c60 =====

char AtapiSendAtapiCommand(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined1 *puVar2;
  byte bVar3;
  char cVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined2 uVar7;
  byte local_res8 [8];
  
  lVar1 = param_1 + 8;
  uVar5 = CONCAT71((int7)((ulonglong)param_2 >> 8),*(undefined1 *)(param_2 + 6)) &
          0xffffffffffffff01;
  AtaPortWritePortUchar
            (*(undefined8 *)(param_1 + 0x40),CONCAT71((int7)(uVar5 >> 8),((byte)uVar5 | 0xfa) << 4))
  ;
  local_res8[0] = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x48));
  puVar2 = (undefined1 *)(param_2 + 0x48);
  WaitOnBusyUntil(lVar1,(char *)local_res8,10,param_1,*(char *)(param_2 + 6),AtapiSendAtapiCommand,
                  puVar2);
  if ((char)local_res8[0] < '\0') {
    *(byte *)(param_2 + 3) = local_res8[0];
    bVar3 = *(byte *)((ulonglong)*(byte *)(param_2 + 6) + 0xa1 + param_1);
    *(byte *)((ulonglong)*(byte *)(param_2 + 6) + 0xa1 + param_1) = bVar3 + 1;
    cVar4 = (bVar3 < 6) + '\x06';
  }
  else {
    if ((*(uint *)(param_2 + 0x10) & 2) != 0) {
      AtapiSetupPrdTable(param_1,param_2);
    }
    if (*(uint *)(param_2 + 0x18) < 0x10000) {
      uVar7 = *(undefined2 *)(param_2 + 0x18);
    }
    else {
      uVar7 = 0xfffe;
    }
    AtaPortWritePortUchar(*(undefined8 *)(param_1 + 0x30),(char)uVar7);
    AtaPortWritePortUchar(*(undefined8 *)(param_1 + 0x38),(char)((ushort)uVar7 >> 8));
    AtaPortWritePortUchar(*(undefined8 *)(param_1 + 0x18),(*(uint *)(param_2 + 0x10) & 2) != 0);
    if ((*(byte *)((ulonglong)*(byte *)(param_2 + 6) * 0x38 + 0xb4 + param_1) & 2) == 0) {
      AtaPortWritePortUchar(*(undefined8 *)(param_1 + 0x48),0xa0);
      local_res8[0] = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x48));
      WaitOnBusyUntil(lVar1,(char *)local_res8,100,param_1,*(char *)(param_2 + 6),
                      AtapiSendAtapiCommand,puVar2);
      WaitForDrqUntil(lVar1,local_res8,10,param_1,*(char *)(param_2 + 6),AtapiSendAtapiCommand,
                      puVar2);
      if ((local_res8[0] & 8) == 0) {
        *(byte *)(param_2 + 3) = local_res8[0];
        return '\x06';
      }
      AtaPortWritePortBufferUshort(*(undefined8 *)(param_1 + 0x10),puVar2,6);
      if ((*(uint *)(param_2 + 0x10) & 2) != 0) {
        uVar6 = 9;
        if ((*(uint *)(param_2 + 0x10) & 0x40) == 0) {
          uVar6 = 1;
        }
        AtaPortWritePortUchar(*(undefined8 *)(param_1 + 0x68),uVar6);
        *(undefined1 *)(param_1 + 0x9f) = 1;
      }
    }
    else {
      *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 0x10000;
      AtaPortWritePortUchar(*(undefined8 *)(param_1 + 0x48));
    }
    cVar4 = '\0';
  }
  return cVar4;
}



===== AtapiSendInternalAtaCommand @ 140002e90 =====

byte AtapiSendInternalAtaCommand(longlong param_1,undefined1 *param_2,ulonglong param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  char cVar3;
  ulonglong uVar4;
  byte local_res18 [16];
  
  uVar4 = param_3 & 0xff;
  cVar3 = (char)param_3;
  lVar1 = param_1 + 8;
  uVar2 = CONCAT71((int7)((ulonglong)param_2 >> 8),cVar3) & 0xffffffffffffff01;
  AtaPortWritePortUchar
            (*(undefined8 *)(param_1 + 0x40),CONCAT71((int7)(uVar2 >> 8),((byte)uVar2 | 0xfa) << 4))
  ;
  local_res18[0] = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x48));
  if (*(int *)(uVar4 * 0x38 + 0xac + param_1) == 1) {
    WaitForDrdyUntil(lVar1,local_res18,param_3,param_1,cVar3,AtapiSendInternalAtaCommand,param_2);
  }
  AtapiProgramTaskFile(lVar1,param_2,'\x01');
  local_res18[0] = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x48));
  WaitOnBusyUntil(lVar1,(char *)local_res18,1000,param_1,cVar3,AtapiSendInternalAtaCommand,param_2);
  return local_res18[0];
}



===== AtapiSendInternalAtaCommandAsync @ 140002f80 =====

void AtapiSendInternalAtaCommandAsync(longlong param_1,undefined1 *param_2,ulonglong param_3)

{
  ulonglong uVar1;
  char cVar2;
  char cVar3;
  undefined7 uVar4;
  byte local_res18 [8];
  
  cVar2 = (char)param_3;
  uVar4 = (undefined7)(param_3 >> 8);
  uVar1 = CONCAT71((int7)((ulonglong)param_2 >> 8),cVar2) & 0xffffffffffffff01;
  cVar3 = cVar2;
  AtaPortWritePortUchar
            (*(undefined8 *)(param_1 + 0x40),CONCAT71((int7)(uVar1 >> 8),((byte)uVar1 | 0xfa) << 4))
  ;
  local_res18[0] = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x48));
  if (*(int *)((param_3 & 0xff) * 0x38 + 0xac + param_1) == 1) {
    WaitForDrdyUntil(param_1 + 8,local_res18,CONCAT71(uVar4,cVar3),param_1,cVar2,
                     AtapiSendInternalAtaCommandAsync,param_2);
  }
  AtapiProgramTaskFile(param_1 + 8,param_2,'\x01');
  return;
}



===== AtapiSetBlockSizeAsync @ 140003030 =====

void AtapiSetBlockSizeAsync(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  byte bVar1;
  undefined8 local_res8;
  
  bVar1 = *(byte *)(param_1 + 0x128);
  if (*(int *)((ulonglong)bVar1 * 0x38 + 0xac + param_1) == 1) {
    *(undefined1 *)(param_1 + 0x12a) = 0;
    local_res8 = (ulonglong)
                 CONCAT16(0xc6,CONCAT15((bVar1 & 1 | 0xfa) << 4,
                                        (uint5)*(byte *)((ulonglong)bVar1 * 0x38 + 0xb3 + param_1)
                                        << 8));
    AtapiSendInternalAtaCommandAsync
              (param_1,(undefined1 *)&local_res8,CONCAT71((int7)((ulonglong)param_3 >> 8),bVar1));
    *(undefined4 *)(param_1 + 0x118) = 1;
    *(code **)(param_1 + 0x120) = AtapiReInitDevices;
    *(undefined4 *)(param_1 + 0x11c) = 10000;
    AtapiWaitStatusAsync(param_1);
  }
  else {
    *(byte *)(param_1 + 0x128) = bVar1 + 1;
    AtapiReInitDevices((undefined1 *)param_1);
  }
  return;
}



===== AtapiSetDmaTransferModeAsync @ 1400030e0 =====

void AtapiSetDmaTransferModeAsync(longlong param_1,ulonglong param_2)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 local_res8;
  
  bVar1 = *(byte *)(param_1 + 0x128);
  uVar4 = *(uint *)((ulonglong)bVar1 * 0x38 + 0xd8 + param_1) & 0x7fffffe0;
  if (uVar4 != 0) {
    param_2 = 0;
    do {
      uVar6 = param_2;
      uVar4 = uVar4 >> 1;
      uVar5 = (uint)uVar6;
      param_2 = (ulonglong)(uVar5 + 1);
    } while (uVar4 != 0);
    if (4 < uVar5) {
      cVar2 = (char)uVar6;
      if (uVar5 < 0xb) {
        if (uVar5 < 8) {
          bVar3 = cVar2 - 5U | 0x10;
        }
        else {
          bVar3 = cVar2 - 8U | 0x20;
        }
      }
      else {
        bVar3 = cVar2 - 0xbU | 0x40;
      }
      local_res8 = CONCAT71((uint7)bVar3,3);
      local_res8._0_5_ = (uint5)(ushort)local_res8;
      local_res8 = (ulonglong)CONCAT16(0xef,CONCAT15((bVar1 & 1 | 0xfa) << 4,(uint5)local_res8));
      AtapiSendInternalAtaCommandAsync(param_1,(undefined1 *)&local_res8,(ulonglong)bVar1);
      *(undefined4 *)(param_1 + 0x118) = 1;
      *(code **)(param_1 + 0x120) = AtapiSetMediaStatusNotificationAsync;
      *(undefined4 *)(param_1 + 0x11c) = 10000;
      AtapiWaitStatusAsync(param_1);
      return;
    }
  }
  AtapiSetMediaStatusNotificationAsync(param_1,param_2);
  return;
}



===== AtapiSetMediaStatusNotificationAsync @ 1400031b0 =====

void AtapiSetMediaStatusNotificationAsync(longlong param_1,undefined8 param_2)

{
  byte bVar1;
  undefined5 local_res8;
  char cStackX_d;
  undefined2 uStackX_e;
  
  bVar1 = *(byte *)(param_1 + 0x128);
  if ((*(byte *)((ulonglong)bVar1 * 0x38 + 0xb4 + param_1) & 4) == 0) {
    AtapiSetupGeometryAsync(param_1,param_2);
  }
  else {
    *(undefined1 *)(param_1 + 0x12a) = 0;
    _local_res8 = CONCAT26(0xef,CONCAT15((bVar1 & 1 | 0xfa) << 4,0x95));
    AtapiSendInternalAtaCommandAsync(param_1,(undefined1 *)&local_res8,(ulonglong)bVar1);
    *(undefined4 *)(param_1 + 0x118) = 1;
    *(code **)(param_1 + 0x120) = AtapiSetupGeometryAsync;
    *(undefined4 *)(param_1 + 0x11c) = 10000;
    AtapiWaitStatusAsync(param_1);
  }
  return;
}



===== AtapiSetPioTransferModeAsync @ 140003250 =====

void AtapiSetPioTransferModeAsync(longlong param_1,ulonglong param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined8 local_res8;
  
  bVar1 = *(byte *)(param_1 + 0x128);
  uVar4 = *(uint *)((ulonglong)bVar1 * 0x38 + 0xd8 + param_1) & 0x1f;
  if (uVar4 != 0) {
    uVar2 = 0;
    do {
      uVar3 = uVar2;
      param_2 = (ulonglong)uVar3;
      uVar4 = uVar4 >> 1;
      uVar2 = uVar3 + 1;
    } while (uVar4 != 0);
    if (2 < uVar3) {
      local_res8 = CONCAT71((uint7)(byte)((byte)uVar3 | 8),3);
      local_res8 = (ulonglong)
                   CONCAT16(0xef,CONCAT15((bVar1 & 1 | 0xfa) << 4,(undefined5)local_res8));
      AtapiSendInternalAtaCommandAsync(param_1,(undefined1 *)&local_res8,(ulonglong)bVar1);
      *(undefined4 *)(param_1 + 0x118) = 1;
      *(code **)(param_1 + 0x120) = AtapiSetDmaTransferModeAsync;
      *(undefined4 *)(param_1 + 0x11c) = 10000;
      AtapiWaitStatusAsync(param_1);
      return;
    }
  }
  AtapiSetDmaTransferModeAsync(param_1,param_2);
  return;
}



===== AtapiSetTransferMode @ 140003304 =====

undefined8 AtapiSetTransferMode(longlong param_1,byte param_2,undefined8 param_3)

{
  byte bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  undefined8 local_res8;
  
  uVar2 = 0;
  if (*(char *)(param_1 + 0x129) == '\0') {
    local_res8 = CONCAT71((uint7)param_3 & 0xff,3);
    local_res8 = (ulonglong)
                 CONCAT16(0xef,CONCAT15((param_2 & 1 | 0xfa) << 4,(undefined5)local_res8));
    bVar1 = AtapiSendInternalAtaCommand
                      (param_1,(undefined1 *)&local_res8,
                       CONCAT71((int7)((ulonglong)param_3 >> 8),param_2));
    uVar2 = CONCAT71(extraout_var,(bVar1 & 0x81) == 0);
  }
  return uVar2;
}



===== AtapiSetupGeometryAsync @ 140003360 =====

void AtapiSetupGeometryAsync(longlong param_1,undefined8 param_2)

{
  char cVar1;
  byte bVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 local_res8;
  
  uVar4 = (ulonglong)*(byte *)(param_1 + 0x128);
  lVar3 = uVar4 * 0x38;
  if ((*(int *)(lVar3 + 0xac + param_1) == 1) && (*(int *)(lVar3 + 0xb8 + param_1) == 1)) {
    cVar1 = *(char *)(lVar3 + 0xc2 + param_1);
    bVar2 = *(byte *)(lVar3 + 0xc4 + param_1);
    *(undefined1 *)(param_1 + 0x12a) = 0;
    local_res8 = (ulonglong)
                 CONCAT16(0x91,CONCAT15((*(byte *)(param_1 + 0x128) & 1 | 0xfa) << 4 | cVar1 - 1U,
                                        (uint5)bVar2 << 8));
    AtapiSendInternalAtaCommandAsync(param_1,(undefined1 *)&local_res8,uVar4);
    *(undefined4 *)(param_1 + 0x118) = 1;
    *(code **)(param_1 + 0x120) = AtapiSetBlockSizeAsync;
    *(undefined4 *)(param_1 + 0x11c) = 10000;
    AtapiWaitStatusAsync(param_1);
  }
  else {
    AtapiSetBlockSizeAsync(param_1,param_2,uVar4);
  }
  return;
}



===== AtapiSetupPrdTable @ 140003418 =====

void AtapiSetupPrdTable(longlong param_1,longlong param_2)

{
  uint *puVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint *puVar7;
  undefined8 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  ulonglong uVar13;
  
  lVar2 = *(longlong *)(param_2 + 0x20);
  puVar7 = (uint *)AtaPortGetScatterGatherList();
  uVar11 = 0;
  uVar10 = 0;
  if (*puVar7 != 0) {
    do {
      uVar5 = AtaPortConvertPhysicalAddressToUlong
                        (*(undefined8 *)(puVar7 + (ulonglong)uVar11 * 6 + 4));
      for (uVar12 = puVar7[(ulonglong)uVar11 * 6 + 6]; uVar12 != 0; uVar12 = uVar12 - uVar4) {
        uVar13 = (ulonglong)uVar10;
        uVar9 = 0x10000 - (uVar5 & 0xffff);
        if (uVar12 <= uVar9) {
          uVar9 = uVar12;
        }
        *(uint *)(lVar2 + uVar13 * 8) = uVar5;
        if (uVar9 == 0x10000) {
          uVar9 = 0;
          uVar4 = 0x10000;
        }
        else {
          uVar9 = ~*(uint *)(param_1 + 0x84) & uVar9;
          uVar4 = uVar9;
        }
        *(short *)(lVar2 + 4 + uVar13 * 8) = (short)uVar9;
        uVar5 = uVar5 + uVar4;
        puVar1 = (uint *)(lVar2 + 4 + uVar13 * 8);
        *puVar1 = *puVar1 & 0xffff;
        uVar10 = uVar10 + 1;
      }
      uVar11 = uVar11 + 1;
    } while (uVar11 < *puVar7);
  }
  puVar7 = (uint *)(lVar2 + 4 + (ulonglong)(uVar10 - 1) * 8);
  *puVar7 = *puVar7 | 0x80000000;
  lVar3 = *(longlong *)(param_1 + 0x68);
  AtaPortWritePortUchar(lVar3,0);
  AtaPortWritePortUchar(lVar3 + 2,6);
  uVar8 = AtaPortGetPhysicalAddress(param_1,param_2,lVar2,0);
  uVar6 = AtaPortConvertPhysicalAddressToUlong(uVar8);
  AtaPortWritePortUlong(lVar3 + 4,uVar6);
  return;
}



===== AtapiTargetPowerDown @ 140003560 =====

ulonglong AtapiTargetPowerDown(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  byte local_res8 [8];
  
  lVar2 = (ulonglong)*(byte *)(param_2 + 6) * 0x38;
  if (*(int *)(lVar2 + 0xac + param_1) == 1) {
    *(longlong *)(param_1 + 0x70) = param_2;
    uVar1 = CONCAT71((int7)((ulonglong)param_2 >> 8),*(undefined1 *)(param_2 + 6)) &
            0xffffffffffffff01;
    AtaPortWritePortUchar
              (*(undefined8 *)(param_1 + 0x40),
               CONCAT71((int7)(uVar1 >> 8),((byte)uVar1 | 0xfa) << 4));
    local_res8[0] = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x48));
    WaitForDrdyUntil(param_1 + 8,local_res8,lVar2,param_1,*(char *)(param_2 + 6),
                     AtapiTargetPowerDown,(undefined1 *)(param_2 + 0x48));
    uVar1 = AtaPortWritePortUchar(*(undefined8 *)(param_1 + 0x48),0xe0);
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



===== AtapiTargetPowerUp @ 140003620 =====

ulonglong AtapiTargetPowerUp(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  byte local_res8 [8];
  
  lVar2 = (ulonglong)*(byte *)(param_2 + 6) * 0x38;
  if (*(int *)(lVar2 + 0xac + param_1) == 1) {
    *(longlong *)(param_1 + 0x70) = param_2;
    uVar1 = CONCAT71((int7)((ulonglong)param_2 >> 8),*(undefined1 *)(param_2 + 6)) &
            0xffffffffffffff01;
    AtaPortWritePortUchar
              (*(undefined8 *)(param_1 + 0x40),
               CONCAT71((int7)(uVar1 >> 8),((byte)uVar1 | 0xfa) << 4));
    local_res8[0] = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x48));
    WaitForDrdyUntil(param_1 + 8,local_res8,lVar2,param_1,*(char *)(param_2 + 6),AtapiTargetPowerUp,
                     (undefined1 *)(param_2 + 0x48));
    uVar1 = AtaPortWritePortUchar(*(undefined8 *)(param_1 + 0x48),0xe1);
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



===== AtapiTaskRegisterSnapshot @ 1400036d8 =====

void AtapiTaskRegisterSnapshot(longlong param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  uVar1 = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x10));
  *param_2 = uVar1;
  uVar1 = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x18));
  param_2[1] = uVar1;
  uVar1 = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x20));
  param_2[2] = uVar1;
  uVar1 = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x28));
  param_2[3] = uVar1;
  uVar1 = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x30));
  param_2[4] = uVar1;
  uVar1 = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x38));
  param_2[5] = uVar1;
  uVar1 = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x40));
  param_2[6] = uVar1;
  return;
}



===== AtapiTranslateResources @ 140003780 =====

ulonglong AtapiTranslateResources(byte *param_1,uint *param_2)

{
  uint uVar1;
  longlong lVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  int iVar11;
  ulonglong uVar12;
  longlong local_res20;
  
  lVar2 = *(longlong *)(param_2 + 2);
  lVar10 = 0;
  bVar5 = false;
  lVar8 = 0;
  local_res20 = 0;
  lVar9 = 0;
  bVar6 = false;
  bVar4 = false;
  bVar3 = false;
  uVar12 = 0;
  if (*param_2 != 0) {
    do {
      uVar1 = *(uint *)(lVar2 + 0x10 + uVar12 * 0x18);
      iVar11 = (int)uVar12;
      if ((uVar1 != 8) || (bVar3)) {
        if (((uVar1 == 1) || (uVar1 == 4)) && (!bVar4)) {
          lVar9 = AtaPortGetDeviceBase(param_1,*(undefined8 *)(lVar2 + uVar12 * 0x18),uVar1);
          if (((lVar9 - 0x376U & 0xffffffffffffff7f) == 0) || (iVar11 == (uint)*param_1 * 2 + 1)) {
            bVar4 = true;
          }
          goto LAB_14000381d;
        }
        if ((0xf < uVar1) && (!bVar5)) {
          iVar7 = AtaPortGetParentBusType(param_1);
          if (iVar7 == 1) {
            if ((!bVar3) && (!bVar4)) {
              lVar8 = AtaPortGetDeviceBase
                                (param_1,*(undefined8 *)(lVar2 + uVar12 * 0x18),
                                 *(undefined4 *)(lVar2 + 0x10 + uVar12 * 0x18));
              bVar3 = true;
              bVar4 = true;
              lVar9 = lVar8 + -4 + (ulonglong)*(uint *)(lVar2 + 0x10 + uVar12 * 0x18);
            }
            goto LAB_14000381d;
          }
          lVar10 = AtaPortGetDeviceBase
                             (param_1,*(undefined8 *)(lVar2 + uVar12 * 0x18),
                              *(undefined4 *)(lVar2 + 0x10 + uVar12 * 0x18));
          bVar5 = true;
          bVar6 = true;
          local_res20 = lVar10;
        }
      }
      else {
        lVar8 = AtaPortGetDeviceBase(param_1,*(undefined8 *)(lVar2 + uVar12 * 0x18),8);
        if (((lVar8 - 0x170U & 0xffffffffffffff7f) == 0) || (iVar11 == (uint)*param_1 * 2)) {
          bVar3 = true;
        }
LAB_14000381d:
        lVar10 = local_res20;
        bVar5 = bVar6;
      }
      uVar12 = (ulonglong)(iVar11 + 1U);
    } while (iVar11 + 1U < *param_2);
    if (bVar5) {
      param_2 = (uint *)(lVar10 + (ulonglong)*param_1 * 8);
      *(uint **)(param_1 + 0x68) = param_2;
    }
    if ((bVar3) && (bVar4)) {
      if (param_1 + 8 != (byte *)0x0) {
        *(longlong *)(param_1 + 8) = lVar8;
        *(longlong *)(param_1 + 0x18) = lVar8 + 1;
        *(longlong *)(param_1 + 0x20) = lVar8 + 2;
        *(longlong *)(param_1 + 0x28) = lVar8 + 3;
        *(longlong *)(param_1 + 0x30) = lVar8 + 4;
        *(longlong *)(param_1 + 0x38) = lVar8 + 5;
        *(longlong *)(param_1 + 0x40) = lVar8 + 6;
        param_2 = (uint *)(lVar8 + 7);
        *(uint **)(param_1 + 0x48) = param_2;
        *(longlong *)(param_1 + 0x10) = lVar8;
      }
      if (param_1 + 0x50 != (byte *)0x0) {
        param_2 = (uint *)(lVar9 - 0x376);
        *(longlong *)(param_1 + 0x50) = lVar9;
        if (((ulonglong)param_2 & 0xffffffffffffff7f) == 0) {
          *(longlong *)(param_1 + 0x58) = lVar9;
          *(longlong *)(param_1 + 0x60) = lVar9 + 1;
        }
        else {
          *(longlong *)(param_1 + 0x58) = lVar9 + 2;
          param_2 = (uint *)(lVar9 + 3);
          *(uint **)(param_1 + 0x60) = param_2;
        }
      }
      param_1[0x9e] = (lVar8 - 0x170U & 0xffffffffffffff7f) != 0;
      return CONCAT71((int7)((ulonglong)param_2 >> 8),1);
    }
  }
  return (ulonglong)param_2 & 0xffffffffffffff00;
}



===== AtapiWaitStatusAsync @ 140003a40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AtapiWaitStatusAsync(longlong param_1)

{
  uint *puVar1;
  ushort *puVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  bool bVar6;
  byte bVar7;
  byte bVar8;
  char cVar9;
  
  bVar6 = false;
  while( true ) {
    bVar7 = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x48));
    uVar3 = *(uint *)(param_1 + 0x118);
    if (uVar3 == 1) break;
    if (uVar3 == 2) {
      bVar8 = bVar7 >> 3;
LAB_140003aa0:
      bVar8 = ~bVar8;
    }
    else {
      if (uVar3 == 3) {
        bVar8 = bVar7 >> 6;
        goto LAB_140003aa0;
      }
      if (uVar3 != 4) goto LAB_140003b4c;
      bVar8 = bVar7 >> 3;
    }
    if ((bVar8 & 1) == 0) goto LAB_140003b4c;
LAB_140003ab7:
    uVar4 = *(uint *)(param_1 + 0xa4);
    *(uint *)(param_1 + 0xa4) = uVar4 + 1;
    if (((uint)(*(int *)(param_1 + 0x11c) * 2) <= uVar4) || (bVar7 == 0xff)) {
      bVar6 = true;
      AtapiDeviceErrorHistoryLog
                (param_1,'\x01',*(undefined8 *)(param_1 + 0x120),uVar3 | 0x1000,
                 *(int *)(param_1 + 0x11c),(undefined1 *)0x0,bVar7);
      goto LAB_140003b4c;
    }
    if ((*(int *)(param_1 + 0x8c) != 1) &&
       (cVar9 = AtaPortRequestCallback(0,param_1,AtapiWaitStatusAsync,500), cVar9 != '\0')) {
      return;
    }
    AtaPortStallExecution(500);
  }
  if ((char)bVar7 < '\0') goto LAB_140003ab7;
LAB_140003b4c:
  pcVar5 = *(code **)(param_1 + 0x120);
  if ((pcVar5 != AtapiResetAtapiDevices) && (pcVar5 != AtapiReInitDevices)) {
    if (pcVar5 == AtapiSetPioTransferModeAsync) {
      if ((bVar6) || ((bVar7 & 1) != 0)) {
        *(undefined1 *)(param_1 + 0x12a) = 1;
        puVar1 = (uint *)((ulonglong)*(byte *)(param_1 + 0x128) * 0x38 + 0xd8 + param_1);
        *puVar1 = *puVar1 & 0x1f;
        *(code **)(param_1 + 0x120) = AtapiSetMediaStatusNotificationAsync;
      }
      goto LAB_140003ca0;
    }
    if (pcVar5 == AtapiSetDmaTransferModeAsync) {
      if ((bVar6) || ((bVar7 & 1) != 0)) {
        *(undefined1 *)(param_1 + 0x12a) = 1;
        puVar1 = (uint *)((ulonglong)*(byte *)(param_1 + 0x128) * 0x38 + 0xd8 + param_1);
        *puVar1 = *puVar1 & 0x1f;
      }
      goto LAB_140003ca0;
    }
    if (pcVar5 == AtapiSetMediaStatusNotificationAsync) {
      if ((bVar6) || ((bVar7 & 1) != 0)) {
        *(undefined1 *)(param_1 + 0x12a) = 1;
        puVar2 = (ushort *)((ulonglong)*(byte *)(param_1 + 0x128) * 0x38 + 0xb4 + param_1);
        *puVar2 = *puVar2 & 0xfffb;
      }
      goto LAB_140003ca0;
    }
    if (pcVar5 == AtapiSetupGeometryAsync) {
      if ((bVar6) || ((bVar7 & 1) != 0)) {
        *(undefined1 *)(param_1 + 0x12a) = 1;
        *(undefined4 *)((ulonglong)*(byte *)(param_1 + 0x128) * 0x38 + 0xac + param_1) = 3;
      }
      goto LAB_140003ca0;
    }
    if (pcVar5 != AtapiSetBlockSizeAsync) goto LAB_140003ca0;
    if ((bVar6) || ((bVar7 & 1) != 0)) {
      *(undefined1 *)(param_1 + 0x12a) = 1;
      *(undefined1 *)((ulonglong)*(byte *)(param_1 + 0x128) * 0x38 + 0xb3 + param_1) = 0;
      goto LAB_140003ca0;
    }
  }
  *(char *)(param_1 + 0x128) = *(char *)(param_1 + 0x128) + '\x01';
LAB_140003ca0:
  *(undefined4 *)(param_1 + 0xa4) = 0;
  (**(code **)(param_1 + 0x120))(param_1);
  return;
}



===== DriverEntry @ 140003cd0 =====

void DriverEntry(undefined8 param_1,undefined8 param_2)

{
  AtaPortInitialize(param_1,param_2,AtapiChannelInitialize,0x1540);
  return;
}



===== WaitForDrdyUntil @ 140003cfc =====

void WaitForDrdyUntil(longlong param_1,byte *param_2,undefined8 param_3,longlong param_4,
                     char param_5,undefined8 param_6,undefined1 *param_7)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *param_2;
  for (iVar2 = 10000; ((bVar1 & 0x40) == 0 && (iVar2 != 0)); iVar2 = iVar2 + -1) {
    AtaPortStallExecution(10);
    bVar1 = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x40));
    *param_2 = bVar1;
  }
  if ((bVar1 & 0x40) == 0) {
    AtapiDeviceErrorHistoryLog(param_4,param_5,param_6,3,100,param_7,bVar1);
  }
  return;
}



===== WaitForDrqUntil @ 140003da0 =====

void WaitForDrqUntil(longlong param_1,byte *param_2,int param_3,longlong param_4,char param_5,
                    undefined8 param_6,undefined1 *param_7)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *param_2;
  for (iVar2 = param_3 * 100; ((bVar1 & 8) == 0 && (iVar2 != 0)); iVar2 = iVar2 + -1) {
    AtaPortStallExecution(10);
    bVar1 = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x40));
    *param_2 = bVar1;
  }
  if ((bVar1 & 8) == 0) {
    AtapiDeviceErrorHistoryLog(param_4,param_5,param_6,2,param_3,param_7,bVar1);
  }
  return;
}



===== WaitOnBusyUntil @ 140003e4c =====

void WaitOnBusyUntil(longlong param_1,char *param_2,int param_3,longlong param_4,char param_5,
                    undefined8 param_6,undefined1 *param_7)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *param_2;
  for (iVar2 = param_3 * 100; (cVar1 < '\0' && (iVar2 != 0)); iVar2 = iVar2 + -1) {
    AtaPortStallExecution(10);
    cVar1 = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x40));
    *param_2 = cVar1;
  }
  if (cVar1 < '\0') {
    AtapiDeviceErrorHistoryLog(param_4,param_5,param_6,1,param_3,param_7,cVar1);
  }
  return;
}



===== WaitOnDrq @ 140003ef8 =====

void WaitOnDrq(longlong param_1,byte *param_2,longlong param_3,char param_4,undefined8 param_5,
              undefined1 *param_6)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = *param_2;
  for (uVar2 = 0; ((bVar1 & 8) != 0 && (uVar2 < 1000)); uVar2 = uVar2 - 1) {
    AtaPortStallExecution(10);
    bVar1 = AtaPortReadPortUchar(*(undefined8 *)(param_1 + 0x40));
    *param_2 = bVar1;
  }
  if ((bVar1 & 8) != 0) {
    AtapiDeviceErrorHistoryLog(param_3,param_4,param_5,4,10,param_6,bVar1);
  }
  return;
}



===== _guard_check_icall @ 140003fb0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140003fc8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140003fec =====

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



===== __security_check_cookie @ 140004060 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1400040a0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1400040d0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001400040d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140004100 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== entry @ 14000a010 =====

void entry(undefined8 param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14000a044 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __security_init_cookie(void)

{
  code *pcVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  undefined7 uVar6;
  byte *pbVar7;
  byte in_DL;
  char in_DH;
  byte unaff_BL;
  undefined7 unaff_00000019;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    pbVar7 = (byte *)0x6;
    pcVar1 = (code *)swi(0x29);
    pbVar5 = (byte *)(*pcVar1)();
    bVar3 = (byte)pbVar5;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + bVar3;
    bVar4 = *pbVar5;
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 + in_DL + CARRY1(bVar4,bVar3);
    *pbVar5 = *pbVar5 + bVar3;
    *pbVar5 = *pbVar5 & in_DL;
    bVar4 = *pbVar5;
    *pbVar5 = *pbVar5 + bVar3;
    bVar2 = bRam00000016a0000010;
    uVar6 = (undefined7)((ulonglong)pbVar5 >> 8);
    pbVar5 = (byte *)CONCAT71(uVar6,bRam00000016a0000010);
    *pbVar5 = (*pbVar5 - bRam00000016a0000010) - CARRY1(bVar4,bVar3);
    pbVar5[0x18] = pbVar5[0x18] + in_DH;
    *pbVar5 = *pbVar5 + bVar2;
    *pbVar7 = *pbVar7 ^ unaff_BL;
    bVar4 = *pbVar5;
    *pbVar5 = *pbVar5 + bVar2;
    bVar4 = cRam5000001b40000019 - CARRY1(bVar4,bVar2);
    pbVar5 = (byte *)CONCAT71(uVar6,bVar4);
    pbVar5[0x7000001e] = pbVar5[0x7000001e] + in_DH;
    *pbVar5 = *pbVar5 & bVar4;
    pbVar5[-0x3fffffdc] = pbVar5[-0x3fffffdc] + bVar4;
    pbVar5 = (byte *)(ulonglong)((uint)pbVar5 & 0x26800000);
    *pbVar5 = *pbVar5;
    bVar4 = (byte)((ulonglong)pbVar7 >> 8);
    *pbVar5 = *pbVar5 ^ bVar4;
    *pbVar5 = *pbVar5;
    *(byte *)CONCAT71(unaff_00000019,unaff_BL) = *(byte *)CONCAT71(unaff_00000019,unaff_BL) ^ bVar4;
    *pbVar5 = *pbVar5;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  ___security_cookie_complement = ~__security_cookie;
  return;
}


