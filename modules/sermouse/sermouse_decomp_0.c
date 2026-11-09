
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



===== SerialMouseCompletionRoutine @ 1c0001020 =====

undefined8 SerialMouseCompletionRoutine(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== SerialMouseHandleStartStopStart @ 1c000104c =====

void SerialMouseHandleStartStopStart(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x198);
  if (*(char *)(param_1 + 0x1bb) != '\0') {
    *(undefined1 *)(param_1 + 0x1bb) = 0;
    IoReuseIrp(*(undefined8 *)(param_1 + 0x78),0);
  }
  KeReleaseSpinLock(param_1 + 0x198,uVar1);
  return;
}



===== SerialMouseStopDevice @ 1c00010c4 =====

void SerialMouseStopDevice(longlong param_1)

{
  undefined1 uVar1;
  char cVar2;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x198);
  *(undefined1 *)(param_1 + 0x1bb) = 1;
  KeReleaseSpinLock(param_1 + 0x198,uVar1);
  if (*(char *)(param_1 + 0x1ba) != '\0') {
    *(undefined1 *)(param_1 + 0x1ba) = 0;
    SerialMouseStopDetection(param_1);
    cVar2 = IoCancelIrp(*(undefined8 *)(param_1 + 0x78));
    if (cVar2 == '\0') {
      KeWaitForSingleObject(param_1 + 0x1a0,0,0,0,0);
    }
  }
  return;
}



===== StartDeviceWorker @ 1c0001160 =====

void StartDeviceWorker(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  uint local_38 [4];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar1 = *param_2;
  if (((*(char *)(lVar1 + 0x1ba) != '\0') && (*(char *)(lVar1 + 0x1b8) == '\0')) &&
     (0 < *(int *)(lVar1 + 0x70))) {
    lVar3 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(lVar1 + 8) >> 8),
                                   *(undefined1 *)(*(longlong *)(lVar1 + 8) + 0x4c)),0);
    if (lVar3 != 0) {
      iVar2 = SerialMouseStartDevice(lVar1,lVar3,'\0');
      if (iVar2 < 0) {
        local_18 = 0;
        local_28 = 0;
        uStack_20 = 0;
        local_38[0] = 0;
        local_38[1] = 0;
        local_38[2] = 0;
        local_38[3] = 0;
        KeInitializeEvent(&local_28,1,0);
        SerialMousepIoSyncIoctl(1,0x370207,*(undefined8 *)(lVar1 + 0x28),&local_28,local_38);
      }
      IoFreeIrp(lVar3);
    }
  }
  IoFreeWorkItem(param_2[1]);
  ExFreePoolWithTag(param_2,0);
  IoReleaseRemoveLockEx(lVar1 + 0x38,lVar1,0x20);
  return;
}



===== CSerHandlerMM @ 1c0001280 =====

undefined8 CSerHandlerMM(undefined8 param_1,longlong param_2,int *param_3,char param_4)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined1 uVar4;
  
  uVar2 = param_3[1];
  uVar3 = (ulonglong)uVar2;
  uVar4 = 0;
  if (param_4 < '\0') {
    if (uVar2 != 0) {
      *param_3 = *param_3 + 1;
      param_3[1] = 0;
      uVar3 = 0;
    }
  }
  else if (uVar2 == 0) {
    *param_3 = *param_3 + 1;
    uVar3 = 0;
    goto LAB_1c0001328;
  }
  *(char *)(uVar3 + 0xc + (longlong)param_3) = param_4;
  uVar2 = param_3[1];
  uVar3 = (ulonglong)uVar2;
  if (uVar2 != 0) {
    uVar1 = uVar2 - 1;
    uVar3 = (ulonglong)uVar1;
    if (uVar1 != 0) {
      if (uVar1 == 1) {
        param_3[1] = 0;
        uVar4 = 1;
        uVar2 = *(byte *)(param_3 + 3) >> 2 & 1;
        *(uint *)(param_2 + 8) = uVar2;
        uVar2 = (*(byte *)(param_3 + 3) & 1) * 2 | uVar2;
        *(uint *)(param_2 + 8) = uVar2;
        *(uint *)(param_2 + 8) = (*(byte *)(param_3 + 3) & 2) * 2 | uVar2;
        uVar1 = -(uint)*(byte *)((longlong)param_3 + 0xd);
        uVar3 = (ulonglong)uVar1;
        uVar2 = (uint)*(byte *)((longlong)param_3 + 0xd);
        if ((*(byte *)(param_3 + 3) & 0x10) == 0) {
          uVar2 = uVar1;
        }
        *(uint *)(param_2 + 0xc) = uVar2;
        uVar2 = -(uint)*(byte *)((longlong)param_3 + 0xe);
        if ((*(byte *)(param_3 + 3) & 8) == 0) {
          uVar2 = (uint)*(byte *)((longlong)param_3 + 0xe);
        }
        *(uint *)(param_2 + 0x10) = uVar2;
      }
      goto LAB_1c0001328;
    }
  }
  param_3[1] = uVar2 + 1;
LAB_1c0001328:
  return CONCAT71((int7)(uVar3 >> 8),uVar4);
}



===== MSerHandlerBP @ 1c0001340 =====

undefined8 MSerHandlerBP(undefined8 param_1,longlong param_2,int *param_3,byte param_4)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined1 uVar4;
  
  uVar3 = param_3[1];
  uVar2 = (ulonglong)uVar3;
  uVar4 = 0;
  if ((param_4 & 0x40) == 0) {
    if (uVar3 == 0) {
      *param_3 = *param_3 + 1;
      uVar2 = 0;
      goto LAB_1c0001400;
    }
  }
  else if (uVar3 != 0) {
    *param_3 = *param_3 + 1;
    param_3[1] = 0;
    uVar2 = 0;
  }
  *(byte *)(uVar2 + 0xc + (longlong)param_3) = param_4;
  uVar3 = param_3[1];
  uVar2 = (ulonglong)uVar3;
  if ((uVar3 != 0) && (uVar2 = (ulonglong)(uVar3 - 1), uVar3 - 1 != 0)) {
    uVar1 = uVar3 - 2;
    uVar2 = (ulonglong)uVar1;
    if (uVar1 != 0) {
      if (uVar1 == 1) {
        param_3[1] = 0;
        uVar3 = *(byte *)(param_3 + 3) >> 5 & 1;
        *(uint *)(param_2 + 8) = uVar3;
        uVar2 = 0;
        *(uint *)(param_2 + 8) = *(byte *)(param_3 + 3) >> 3 & 2 | uVar3;
        if ((*(byte *)((longlong)param_3 + 0xf) & 1) == 0) {
          uVar3 = *(byte *)(param_3 + 3) & 3;
        }
        else {
          uVar3 = *(byte *)(param_3 + 3) | 0xfffffffc;
        }
        *(uint *)(param_2 + 0xc) = (uint)*(byte *)((longlong)param_3 + 0xd) | uVar3 << 6;
        if ((*(byte *)((longlong)param_3 + 0xf) & 2) == 0) {
          uVar3 = *(byte *)(param_3 + 3) & 0xc;
        }
        else {
          uVar3 = *(byte *)(param_3 + 3) & 0xfffffffc | 0xfffffff0;
        }
        uVar4 = 1;
        *(uint *)(param_2 + 0x10) = (uint)*(byte *)((longlong)param_3 + 0xe) | uVar3 << 4;
      }
      goto LAB_1c0001400;
    }
  }
  param_3[1] = uVar3 + 1;
LAB_1c0001400:
  return CONCAT71((int7)(uVar2 >> 8),uVar4);
}



===== MSerHandlerMP @ 1c0001410 =====

undefined8 MSerHandlerMP(undefined8 param_1,longlong param_2,int *param_3,byte param_4)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined1 uVar4;
  
  uVar2 = param_3[1];
  uVar3 = (ulonglong)uVar2;
  uVar4 = 0;
  if ((param_4 & 0x40) == 0) {
    if (uVar2 == 0) {
      *param_3 = *param_3 + 1;
      uVar3 = 0;
      goto LAB_1c00014f7;
    }
  }
  else if (uVar2 != 0) {
    if (uVar2 == 3) {
      if ((param_3[2] & 4U) != 0) {
        param_3[2] = param_3[2] ^ 4;
        goto LAB_1c0001435;
      }
    }
    else {
LAB_1c0001435:
      *param_3 = *param_3 + 1;
    }
    param_3[1] = 0;
    uVar3 = 0;
  }
  *(byte *)(uVar3 + 0xc + (longlong)param_3) = param_4;
  iVar1 = param_3[1];
  if ((iVar1 == 0) || (iVar1 == 1)) {
    uVar3 = 0;
    param_3[1] = iVar1 + 1;
    goto LAB_1c00014f7;
  }
  uVar2 = iVar1 - 2;
  uVar3 = (ulonglong)uVar2;
  if (uVar2 == 0) {
    param_3[1] = 3;
    uVar2 = *(byte *)(param_3 + 3) >> 5 & 1;
    *(uint *)(param_2 + 8) = uVar2;
    uVar2 = *(byte *)(param_3 + 3) >> 3 & 2 | uVar2;
    *(uint *)(param_2 + 8) = uVar2;
    *(uint *)(param_2 + 8) = param_3[2] & 4U | uVar2;
    *(int *)(param_2 + 0xc) =
         (int)(char)((char)param_3[3] << 6 | *(byte *)((longlong)param_3 + 0xd));
    uVar3 = (ulonglong)(uint)(int)(char)*(byte *)((longlong)param_3 + 0xe);
    *(int *)(param_2 + 0x10) =
         (int)(char)((*(byte *)(param_3 + 3) & 0xfc) << 4 | *(byte *)((longlong)param_3 + 0xe));
  }
  else {
    if (uVar2 != 1) goto LAB_1c00014f7;
    uVar2 = (uint)(*(byte *)((longlong)param_3 + 0xf) >> 3) ^ param_3[2];
    uVar3 = (ulonglong)uVar2;
    param_3[1] = 0;
    if ((uVar2 & 4) == 0) goto LAB_1c00014f7;
    *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) ^ 4;
    *(undefined8 *)(param_2 + 0xc) = 0;
  }
  uVar4 = 1;
LAB_1c00014f7:
  return CONCAT71((int7)(uVar3 >> 8),uVar4);
}



===== MSerHandlerZ @ 1c0001510 =====

undefined8 MSerHandlerZ(undefined8 param_1,longlong param_2,int *param_3,byte param_4)

{
  byte bVar1;
  uint uVar2;
  ulonglong uVar3;
  byte bVar4;
  byte bVar5;
  undefined1 uVar6;
  bool bVar7;
  
  uVar2 = param_3[1];
  uVar3 = (ulonglong)uVar2;
  uVar6 = 0;
  if ((param_4 & 0x40) == 0) {
    if (uVar2 == 0) {
      *param_3 = *param_3 + 1;
      uVar3 = 0;
      goto LAB_1c000165c;
    }
  }
  else if (uVar2 != 0) {
    if (uVar2 != 3) {
      *param_3 = *param_3 + 1;
    }
    param_3[1] = 0;
    uVar3 = 0;
  }
  *(byte *)(uVar3 + 0xc + (longlong)param_3) = param_4;
  uVar2 = param_3[1];
  uVar3 = (ulonglong)uVar2;
  if (((uVar2 == 0) || (uVar3 = (ulonglong)(uVar2 - 1), uVar2 - 1 == 0)) ||
     (uVar3 = (ulonglong)(uVar2 - 2), uVar2 - 2 == 0)) {
    param_3[1] = uVar2 + 1;
  }
  else {
    uVar2 = uVar2 - 3;
    uVar3 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      if ((*(byte *)((longlong)param_3 + 0xf) & 0x20) != 0) {
        param_3[1] = 4;
        goto LAB_1c000165c;
      }
      param_3[1] = 0;
      *(undefined1 *)(param_3 + 4) = 0;
    }
    else {
      if (uVar2 != 1) goto LAB_1c000165c;
      param_3[1] = 0;
    }
    *(undefined4 *)(param_2 + 8) = 0;
    uVar6 = 1;
    bVar7 = (*(byte *)(param_3 + 3) & 0x20) != 0;
    if (bVar7) {
      *(undefined4 *)(param_2 + 8) = 1;
    }
    uVar2 = (uint)bVar7;
    if ((*(byte *)(param_3 + 3) & 0x10) != 0) {
      uVar2 = uVar2 | 2;
      *(uint *)(param_2 + 8) = uVar2;
    }
    if ((*(byte *)((longlong)param_3 + 0xf) & 0x10) != 0) {
      *(uint *)(param_2 + 8) = uVar2 | 4;
    }
    *(int *)(param_2 + 0xc) =
         (int)(char)((char)param_3[3] << 6 | *(byte *)((longlong)param_3 + 0xd));
    bVar5 = *(byte *)((longlong)param_3 + 0xe);
    *(int *)(param_2 + 0x10) = (int)(char)((*(byte *)(param_3 + 3) & 0xfc) << 4 | bVar5);
    bVar1 = *(byte *)((longlong)param_3 + 0xf);
    uVar3 = (ulonglong)CONCAT31((int3)((uint)(int)(char)bVar5 >> 8),bVar1);
    bVar5 = bVar1 & 0xf;
    if ((bVar1 & 0x20) == 0) {
      uVar3 = 0;
      bVar4 = bVar5 | 0xf0;
      if ((bVar1 & 8) == 0) {
        bVar4 = bVar5;
      }
    }
    else {
      bVar4 = (char)param_3[4] << 4 | bVar5;
    }
    if (bVar4 == 0) {
      *(undefined2 *)(param_2 + 6) = 0;
    }
    else {
      *(ushort *)(param_2 + 6) = ((short)(char)bVar4 >> 0xf & 0xf0U) - 0x78;
      uVar3 = 0x400;
      *(ushort *)(param_2 + 4) = *(ushort *)(param_2 + 4) | 0x400;
    }
  }
LAB_1c000165c:
  return CONCAT71((int7)(uVar3 >> 8),uVar6);
}



===== SerialMouseFlush @ 1c0001670 =====

ulonglong SerialMouseFlush(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar1 = lVar2 + 0x38;
  uVar4 = IoAcquireRemoveLockEx(lVar1,param_2,"",1,0x20);
  if (-1 < (int)uVar4) {
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    uVar3 = IofCallDriver(*(undefined8 *)(lVar2 + 0x28),param_2);
    uVar4 = (ulonglong)uVar3;
    IoReleaseRemoveLockEx(lVar1,param_2,0x20);
  }
  return uVar4;
}



===== SerialMouseInternalDeviceControl @ 1c0001710 =====

int SerialMouseInternalDeviceControl(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined8 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  iVar9 = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  iVar8 = IoAcquireRemoveLockEx(lVar1 + 0x38,param_2,"",1,0x20);
  if (iVar8 < 0) {
    *(int *)(param_2 + 0x30) = iVar8;
    IofCompleteRequest(param_2,0);
    iVar9 = iVar8;
  }
  else {
    iVar8 = *(int *)(lVar2 + 0x18);
    if (iVar8 == 0xf0000) {
      if (*(uint *)(lVar2 + 8) < 0xc) {
        iVar9 = -0x3fffffdd;
      }
      else {
        puVar4 = *(undefined8 **)(param_2 + 0x18);
        *puVar4 = *(undefined8 *)(lVar1 + 0xd0);
        *(undefined4 *)(puVar4 + 1) = *(undefined4 *)(lVar1 + 0xd8);
        *(undefined8 *)(param_2 + 0x38) = 0xc;
      }
    }
    else if (iVar8 == 0xf0203) {
      if (*(longlong *)(lVar1 + 0x68) == 0) {
        if (*(uint *)(lVar2 + 0x10) < 0x10) {
          iVar9 = -0x3ffffff3;
        }
        else {
          puVar3 = *(undefined4 **)(lVar2 + 0x20);
          uVar5 = puVar3[1];
          uVar6 = puVar3[2];
          uVar7 = puVar3[3];
          *(undefined4 *)(lVar1 + 0x60) = *puVar3;
          *(undefined4 *)(lVar1 + 100) = uVar5;
          *(undefined4 *)(lVar1 + 0x68) = uVar6;
          *(undefined4 *)(lVar1 + 0x6c) = uVar7;
        }
      }
      else {
        iVar9 = -0x3fffffbd;
      }
    }
    else if (iVar8 == 0xf0403) {
      iVar9 = -0x3ffffffe;
    }
    else {
      iVar9 = -0x3fffff45;
      if ((iVar8 != 0xf0803) && (iVar9 = -0x3fffff45, iVar8 != 0xf1003)) {
        iVar9 = -0x3ffffff0;
      }
    }
    *(int *)(param_2 + 0x30) = iVar9;
    IofCompleteRequest(param_2,0);
    IoReleaseRemoveLockEx(lVar1 + 0x38,param_2,0x20);
  }
  return iVar9;
}



===== SerialMouseInitializePort @ 1c0001864 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SerialMouseInitializePort(longlong param_1)

{
  ulonglong uVar1;
  undefined1 auStackY_b8 [32];
  uint local_68 [4];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined8 local_3c;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_48 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  KeInitializeEvent(&local_58,0,0);
  uVar1 = SerialMousepIoSyncIoctlEx
                    (1,0x1b000c,*(undefined8 *)(param_1 + 0x28),&local_58,local_68,0,0,
                     param_1 + 0x168,0x2c);
  if ((int)uVar1 < 0) {
    SerialMousepIoSyncIoctlEx
              (0,0x1b0020,*(undefined8 *)(param_1 + 0x28),&local_58,local_68,0,0,param_1 + 0x168,
               0x14);
    local_20 = 0;
    local_30 = 0;
    uStack_28 = 0;
    SerialMousepIoSyncIoctlEx
              (0,0x1b001c,*(undefined8 *)(param_1 + 0x28),&local_58,local_68,&local_30,0x14,0,0);
    SerialMousepIoSyncIoctlEx
              (0,0x1b0060,*(undefined8 *)(param_1 + 0x28),&local_58,local_68,0,0,param_1 + 0x17c,
               0x10);
    local_40 = 1;
    local_3c = 0x40;
    local_34 = 0;
    SerialMousepIoSyncIoctlEx
              (0,0x1b0064,*(undefined8 *)(param_1 + 0x28),&local_58,local_68,&local_40,0x10,0,0);
  }
  return;
}



===== SerialMouseReadComplete @ 1c0001a30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SerialMouseReadComplete(undefined8 param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  undefined1 uVar4;
  ushort uVar5;
  uint uVar6;
  bool bVar7;
  undefined4 local_res10 [2];
  
  local_res10[0] = 0;
  iVar1 = *(int *)(param_2 + 0x30);
  LOCK();
  bVar7 = *(int *)(param_3 + 0x58) == 1;
  if (bVar7) {
    *(int *)(param_3 + 0x58) = 3;
  }
  UNLOCK();
  if ((iVar1 != -0x3fffffaa) && (iVar1 != -0x3fffff63)) {
    if (iVar1 != -0x3ffffee0) {
      if ((iVar1 == 0) && (*(longlong *)(param_2 + 0x38) != 0)) {
        cVar3 = (**(code **)(param_3 + 0x148))
                          (param_3,param_3 + 0xdc,param_3 + 0x150,*(undefined1 *)(param_3 + 0x1bd),0
                          );
        if (cVar3 != '\0') {
          uVar2 = *(uint *)(param_3 + 0xe4);
          uVar6 = uVar2 ^ *(uint *)(param_3 + 0x158);
          if (uVar6 != 0) {
            if ((uVar6 & 1) != 0) {
              if ((uVar2 & 1) == 0) {
                uVar5 = *(ushort *)(param_3 + 0xe0) | 2;
              }
              else {
                uVar5 = *(ushort *)(param_3 + 0xe0) | 1;
              }
              *(ushort *)(param_3 + 0xe0) = uVar5;
            }
            if ((uVar6 & 2) != 0) {
              if ((uVar2 & 2) == 0) {
                uVar5 = *(ushort *)(param_3 + 0xe0) | 8;
              }
              else {
                uVar5 = *(ushort *)(param_3 + 0xe0) | 4;
              }
              *(ushort *)(param_3 + 0xe0) = uVar5;
            }
            if ((uVar6 & 4) != 0) {
              if ((uVar2 & 4) == 0) {
                uVar5 = *(ushort *)(param_3 + 0xe0) | 0x20;
              }
              else {
                uVar5 = *(ushort *)(param_3 + 0xe0) | 0x10;
              }
              *(ushort *)(param_3 + 0xe0) = uVar5;
            }
            *(uint *)(param_3 + 0x158) = uVar2;
          }
          if (*(int *)(param_3 + 0x70) != 0) {
            uVar4 = KfRaiseIrql(CONCAT71((uint7)(uint3)(uVar6 >> 8),2));
            (**(code **)(param_3 + 0x68))
                      (*(undefined8 *)(param_3 + 0x60),param_3 + 0xdc,param_3 + 0xf4,local_res10);
            KeLowerIrql(uVar4);
          }
          *(undefined4 *)(param_3 + 0xe0) = 0;
        }
      }
      if (bVar7) {
        return 0xc0000016;
      }
      SerialMouseStartRead(param_3);
      return 0xc0000016;
    }
    KeSetEvent(param_3 + 0x1a0,0,0);
  }
  IoReleaseRemoveLockEx(param_3 + 0x38,*(undefined8 *)(param_3 + 0x78),0x20);
  return 0xc0000016;
}



===== SerialMouseReadSerialPort @ 1c0001bd4 =====

int SerialMouseReadSerialPort(longlong param_1,longlong param_2,undefined8 param_3,short *param_4)

{
  ushort uVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  KeInitializeEvent(&local_38,0,0);
  lVar2 = *(longlong *)(param_1 + 0x78);
  *param_4 = 0;
  do {
    KeClearEvent(&local_38);
    IoReuseIrp(lVar2,0);
    lVar3 = *(longlong *)(lVar2 + 0xb8);
    *(longlong *)(lVar2 + 0x18) = param_2;
    *(undefined4 *)(lVar3 + -0x40) = 1;
    *(undefined8 *)(lVar3 + -0x30) = 0;
    *(undefined1 *)(lVar3 + -0x48) = 3;
    lVar3 = *(longlong *)(lVar2 + 0xb8);
    *(code **)(lVar3 + -0x10) = SerialMouseCompletionRoutine;
    *(undefined8 **)(lVar3 + -8) = &local_38;
    *(undefined1 *)(lVar3 + -0x45) = 0xe0;
    iVar4 = IofCallDriver(*(undefined8 *)(param_1 + 0x28),lVar2);
    if ((iVar4 == 0x103) && (iVar4 = KeWaitForSingleObject(&local_38,0,0,0,0), iVar4 == 0)) {
      iVar4 = *(int *)(lVar2 + 0x30);
    }
    if (iVar4 < 0) {
      return iVar4;
    }
    if (iVar4 == 0x102) {
      return iVar4;
    }
    uVar1 = *(ushort *)(lVar2 + 0x38);
    *param_4 = *param_4 + uVar1;
    param_2 = param_2 + (ulonglong)uVar1;
  } while (*param_4 == 0);
  return iVar4;
}



===== SerialMouseRestorePort @ 1c0001d08 =====

void SerialMouseRestorePort(longlong param_1)

{
  ulonglong uVar1;
  uint local_38 [4];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  KeInitializeEvent(&local_28,0,0);
  uVar1 = SerialMousepIoSyncIoctlEx
                    (1,0x1b0010,*(undefined8 *)(param_1 + 0x28),&local_28,local_38,param_1 + 0x168,
                     0x2c,0,0);
  if ((int)uVar1 < 0) {
    SerialMousepIoSyncIoctlEx
              (0,0x1b001c,*(undefined8 *)(param_1 + 0x28),&local_28,local_38,param_1 + 0x168,0x14,0,
               0);
    SerialMousepIoSyncIoctlEx
              (0,0x1b0064,*(undefined8 *)(param_1 + 0x28),&local_28,local_38,param_1 + 0x17c,0x10,0,
               0);
  }
  return;
}



===== SerialMouseSetReadTimeouts @ 1c0001e14 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SerialMouseSetReadTimeouts(longlong param_1,uint param_2)

{
  undefined1 auStackY_a8 [32];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  uint local_40 [4];
  undefined8 local_30;
  ulonglong uStack_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_48 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_40[0] = 0;
  local_40[1] = 0;
  local_40[2] = 0;
  local_40[3] = 0;
  KeInitializeEvent(&local_58,0,0);
  local_20 = 0;
  local_30 = 0;
  uStack_28 = 0;
  if (param_2 != 0) {
    uStack_28 = (ulonglong)param_2;
    local_30 = 0xffffffffffffffff;
  }
  SerialMousepIoSyncIoctlEx
            (0,0x1b001c,*(undefined8 *)(param_1 + 0x28),&local_58,local_40,&local_30,0x14,0,0);
  return;
}



===== SerialMouseStartRead @ 1c0001ee4 =====

undefined8 SerialMouseStartRead(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  char cVar3;
  longlong lVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  
  cVar3 = *(char *)(param_1 + 0x1b8);
  lVar4 = *(longlong *)(param_1 + 0x78);
  while( true ) {
    if (((cVar3 != '\0') || (*(char *)(param_1 + 0x1ba) == '\0')) || (*(int *)(param_1 + 0x70) == 0)
       ) {
      KeSetEvent(param_1 + 0x1a0,0,0);
      IoReleaseRemoveLockEx(param_1 + 0x38,*(undefined8 *)(param_1 + 0x78),0x20);
      return 0xc0000001;
    }
    lVar1 = param_1 + 0x198;
    uVar5 = KeAcquireSpinLockRaiseToDpc(lVar1);
    if (*(char *)(param_1 + 0x1bb) != '\0') {
      KeReleaseSpinLock(lVar1,uVar5);
      KeSetEvent(param_1 + 0x1a0,0,0);
      IoReleaseRemoveLockEx(param_1 + 0x38,*(undefined8 *)(param_1 + 0x78),0x20);
      return 0;
    }
    IoReuseIrp(lVar4,0);
    KeReleaseSpinLock(lVar1,uVar5);
    LOCK();
    *(undefined4 *)(param_1 + 0x58) = 1;
    UNLOCK();
    *(longlong *)(lVar4 + 0x18) = param_1 + 0x1bd;
    lVar1 = *(longlong *)(lVar4 + 0xb8);
    *(undefined8 *)(lVar1 + -0x30) = 0;
    *(undefined4 *)(lVar1 + -0x40) = 1;
    *(undefined1 *)(lVar1 + -0x48) = 3;
    lVar1 = *(longlong *)(lVar4 + 0xb8);
    *(code **)(lVar1 + -0x10) = SerialMouseReadComplete;
    *(longlong *)(lVar1 + -8) = param_1;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    uVar6 = IofCallDriver(*(undefined8 *)(param_1 + 0x28));
    LOCK();
    iVar2 = *(int *)(param_1 + 0x58);
    *(int *)(param_1 + 0x58) = 2;
    UNLOCK();
    if (iVar2 != 3) break;
    cVar3 = *(char *)(param_1 + 0x1b8);
  }
  return uVar6;
}



===== SerialMouseWait @ 1c0002078 =====

void SerialMouseWait(longlong param_1,int param_2)

{
  KeSetTimer(param_1 + 0xf8,(longlong)param_2,0);
  KeWaitForSingleObject(param_1 + 0xf8,0,0,0,0);
  return;
}



===== SerialMouseWriteSerialPort @ 1c00020c4 =====

undefined4
SerialMouseWriteSerialPort
          (longlong param_1,undefined8 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined8 local_res8;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_res8 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeInitializeEvent(&local_28,0,0);
  lVar3 = IoBuildSynchronousFsdRequest
                    (4,*(undefined8 *)(param_1 + 0x28),param_2,param_3,&local_res8,&local_28,param_4
                    );
  if (lVar3 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    iVar1 = IofCallDriver(*(undefined8 *)(param_1 + 0x28),lVar3);
    if (iVar1 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
    }
    uVar2 = *param_4;
  }
  return uVar2;
}



===== SerialMouseSerialMaskEventComplete @ 1c00021b0 =====

undefined8
SerialMouseSerialMaskEventComplete(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  int iVar1;
  longlong lVar2;
  
  if ((*(char *)(param_3 + 0x1b8) == '\0') && (*(char *)(param_3 + 0x1b9) == '\0')) {
    lVar2 = IoAllocateWorkItem(*(undefined8 *)(param_3 + 8));
    if (lVar2 != 0) {
      iVar1 = IoAcquireRemoveLockEx(param_3 + 0x38,lVar2,"",1,0x20);
      if (-1 < iVar1) {
        IoQueueWorkItem(lVar2,SerialMouseSerialMaskEventWorker,1,lVar2);
        goto LAB_1c0002251;
      }
    }
    *(undefined1 *)(param_3 + 0x1bc) = 1;
    IoInvalidateDeviceState(*(undefined8 *)(param_3 + 0x30));
  }
LAB_1c0002251:
  IoReleaseRemoveLockEx(param_3 + 0x38,*(undefined8 *)(param_3 + 0x80),0x20);
  return 0xc0000016;
}



===== SerialMouseFlushReadBuffer @ 1c0002288 =====

void SerialMouseFlushReadBuffer(longlong param_1)

{
  undefined4 local_res8 [8];
  uint local_38 [4];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_res8[0] = 8;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  KeInitializeEvent(&local_28,0,0);
  SerialMousepIoSyncIoctlEx
            (0,0x1b004c,*(undefined8 *)(param_1 + 0x28),&local_28,local_38,local_res8,4,0,0);
  return;
}



===== _guard_check_icall @ 1c0002320 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0002338 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000235c =====

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



===== __cpu_features_init @ 1c00023d0 =====

/* WARNING: Removing unreachable block (ram,0x0001c000243a) */
/* WARNING: Removing unreachable block (ram,0x0001c00023e9) */
/* WARNING: Removing unreachable block (ram,0x0001c00023da) */

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



===== __security_check_cookie @ 1c00024a0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c00024e0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0002510 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0002510. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0002540 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c00025c0 =====

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



===== memset @ 1c00028c0 =====

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



===== __memset_repmovs @ 1c0002a00 =====

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



===== __memset_query @ 1c0002a80 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0002b00 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0002c40 =====

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



===== __memset_spec_plain @ 1c0002cc0 =====

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



===== SerialMouseAddDevice @ 1c0008010 =====

ulonglong SerialMouseAddDevice(undefined8 param_1,undefined8 param_2)

{
  void *_Dst;
  ulonglong uVar1;
  longlong lVar2;
  undefined4 *puVar3;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  uVar1 = IoCreateDevice(param_1,0x1c8,0,0x1a,0,0,local_res18);
  if (-1 < (int)uVar1) {
    _Dst = *(void **)(local_res18[0] + 0x40);
    memset(_Dst,0,0x1c8);
    lVar2 = IoAttachDeviceToDeviceStack(local_res18[0],param_2);
    *(longlong *)((longlong)_Dst + 0x28) = lVar2;
    if (lVar2 == 0) {
      puVar3 = (undefined4 *)IoAllocateErrorLogEntry(param_1,0x30);
      uVar1 = 0xc000009d;
      if (puVar3 != (undefined4 *)0x0) {
        puVar3[3] = 0xc005001c;
        *puVar3 = 0;
        *(undefined8 *)(puVar3 + 6) = 0;
        puVar3[4] = 0;
        puVar3[5] = 0xc000009d;
        IoWriteErrorLogEntry(puVar3);
      }
    }
    else {
      *(undefined8 *)((longlong)_Dst + 0x30) = param_2;
      *(longlong *)((longlong)_Dst + 8) = local_res18[0];
      *(undefined1 *)((longlong)_Dst + 0x1b8) = 0;
      *(undefined2 *)((longlong)_Dst + 0x1ba) = 0;
      *(undefined4 *)((longlong)_Dst + 0x164) = 1;
      *(undefined1 *)((longlong)_Dst + 0x1bf) = 0;
      KeInitializeSpinLock((longlong)_Dst + 0x198);
      KeInitializeEvent((longlong)_Dst + 0x1a0,1,0);
      IoInitializeRemoveLockEx((longlong)_Dst + 0x38,0x7265734d,0,10,0x20);
      lVar2 = IoAllocateIrp(*(undefined1 *)(local_res18[0] + 0x4c),0);
      *(longlong *)((longlong)_Dst + 0x78) = lVar2;
      if (lVar2 != 0) {
        *(undefined ***)((longlong)_Dst + 0x98) = &WmiGuidList;
        *(undefined4 *)((longlong)_Dst + 0x90) = 1;
        *(code **)((longlong)_Dst + 0xa0) = SerialMouseQueryWmiRegInfo;
        *(code **)((longlong)_Dst + 0xa8) = SerialMouseQueryWmiDataBlock;
        *(code **)((longlong)_Dst + 0xb0) = SerialMouseSetWmiDataBlock;
        *(code **)((longlong)_Dst + 0xb8) = SerialMouseSetWmiDataBlock;
        *(undefined8 *)((longlong)_Dst + 0xc0) = 0;
        *(undefined8 *)((longlong)_Dst + 200) = 0;
        IoWMIRegistrationControl(*(undefined8 *)((longlong)_Dst + 8),1);
        KeInitializeTimer((longlong)_Dst + 0xf8);
        *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) & 0xffffff7f;
        *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) | 4;
        *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) | 0x2000;
        return uVar1 & 0xffffffff;
      }
      IoDetachDevice(*(undefined8 *)((longlong)_Dst + 0x28));
      uVar1 = 0xc000009a;
    }
    IoDeleteDevice(local_res18[0]);
  }
  return uVar1;
}



===== SerialMousePnP @ 1c0008270 =====

ulonglong SerialMousePnP(longlong param_1,longlong param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  byte bVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  longlong lVar6;
  undefined8 uVar7;
  uint uVar8;
  int iVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  longlong local_res10;
  
  puVar5 = *(undefined4 **)(param_1 + 0x40);
  lVar6 = *(longlong *)(param_2 + 0xb8);
  local_res10 = 0;
  puVar1 = puVar5 + 0xe;
  uVar8 = IoAcquireRemoveLockEx(puVar1,param_2,"",1,0x20);
  if ((int)uVar8 < 0) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(uint *)(param_2 + 0x30) = uVar8;
    IofCompleteRequest(param_2,0);
    return (ulonglong)uVar8;
  }
  bVar3 = *(byte *)(lVar6 + 1);
  if (bVar3 < 10) {
    if (bVar3 == 9) {
      uVar10 = SerialMouseSendIrpSynchronously(*(undefined8 *)(puVar5 + 10),param_2,'\x01');
      uVar11 = uVar10 & 0xffffffff;
      if (((-1 < (int)uVar10) && (-1 < *(int *)(param_2 + 0x30))) &&
         (lVar6 = *(longlong *)(lVar6 + 8), lVar6 != 0)) {
        *(undefined8 *)(lVar6 + 0x2c) = 0;
        *(uint *)(lVar6 + 4) = *(uint *)(lVar6 + 4) & 0xffffc3ff | 0x200;
        *(undefined4 *)(lVar6 + 0x14) = 1;
        *(undefined4 *)(lVar6 + 0x18) = 4;
        *(undefined4 *)(lVar6 + 0x1c) = 4;
        *(undefined4 *)(lVar6 + 0x20) = 4;
        *(undefined4 *)(lVar6 + 0x24) = 4;
        *(undefined4 *)(lVar6 + 0x28) = 4;
      }
    }
    else {
      if (bVar3 != 0) {
        if (bVar3 != 1) {
          if (bVar3 == 2) {
            *(undefined1 *)(puVar5 + 0x6e) = 1;
            SerialMouseRemoveDevice((longlong)puVar5,param_2);
            *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
            *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
            *(undefined4 *)(param_2 + 0x30) = 0;
            uVar8 = IofCallDriver(*(undefined8 *)(puVar5 + 10),param_2);
            IoReleaseRemoveLockAndWaitEx(puVar1,param_2,0x20);
            IoFreeIrp(*(undefined8 *)(puVar5 + 0x1e));
            *(undefined8 *)(puVar5 + 0x1e) = 0;
            if (*(longlong *)(puVar5 + 0x20) != 0) {
              IoFreeIrp();
              *(undefined8 *)(puVar5 + 0x20) = 0;
            }
            IoDetachDevice(*(undefined8 *)(puVar5 + 10));
            IoDeleteDevice(param_1);
            return (ulonglong)uVar8;
          }
          if ((bVar3 != 3) && (bVar3 == 4)) {
            SerialMouseStopDevice((longlong)puVar5);
            goto LAB_1c000837a;
          }
        }
        goto LAB_1c000831e;
      }
      uVar10 = SerialMouseSendIrpSynchronously(*(undefined8 *)(puVar5 + 10),param_2,'\x01');
      uVar11 = uVar10 & 0xffffffff;
      if ((-1 < (int)uVar10) && (-1 < *(int *)(param_2 + 0x30))) {
        LOCK();
        piVar2 = puVar5 + 0x1c;
        iVar9 = *piVar2;
        *piVar2 = *piVar2 + 1;
        UNLOCK();
        if (iVar9 == 0) {
          uVar4 = *(undefined4 *)(param_2 + 0x30);
          uVar7 = *(undefined8 *)(param_2 + 0x38);
          memset((void *)(*(longlong *)(param_2 + 0xb8) + -0x48),0,0x48);
          uVar10 = SerialMouseSendIrpSynchronously(*(undefined8 *)(puVar5 + 10),param_2,'\0');
          uVar11 = uVar10 & 0xffffffff;
          if (((int)uVar10 < 0) || (*(int *)(param_2 + 0x30) < 0)) goto LAB_1c000850f;
          *(undefined4 *)(param_2 + 0x30) = uVar4;
          *(undefined8 *)(param_2 + 0x38) = uVar7;
        }
        iVar9 = IoOpenDeviceRegistryKey(*(undefined8 *)(puVar5 + 0xc),1,0x20000,&local_res10);
        if (-1 < iVar9) {
          SerialMouseServiceParameters(puVar5,local_res10);
          ZwClose(local_res10);
        }
        SerialMouseHandleStartStopStart((longlong)puVar5);
        uVar8 = SerialMouseInitializeDevice((longlong)puVar5);
        uVar11 = (ulonglong)uVar8;
        LOCK();
        piVar2 = puVar5 + 0x1c;
        iVar9 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (iVar9 == 1) {
          SerialMouseClosePort((longlong)puVar5,param_2);
        }
        else {
          uVar11 = SerialMouseSpinUpRead((longlong)puVar5);
          uVar11 = uVar11 & 0xffffffff;
        }
      }
LAB_1c000850f:
      *(undefined8 *)(param_2 + 0x38) = 0;
LAB_1c0008513:
      *(int *)(param_2 + 0x30) = (int)uVar11;
    }
    IofCompleteRequest(param_2,0);
  }
  else {
    if (((((bVar3 != 10) && (bVar3 != 0xb)) && (bVar3 != 0xf)) &&
        ((bVar3 != 0x10 && (bVar3 != 0x11)))) && ((bVar3 != 0x12 && (bVar3 != 0x13)))) {
      if (bVar3 == 0x14) {
        uVar11 = SerialMouseSendIrpSynchronously(*(undefined8 *)(puVar5 + 10),param_2,'\x01');
        iVar9 = (int)uVar11;
        uVar11 = uVar11 & 0xffffffff;
        if ((iVar9 == -0x3fffff45) || (iVar9 == -0x3ffffff0)) {
          uVar11 = 0;
        }
        else if (iVar9 < 0) goto LAB_1c0008513;
        if (*(char *)(puVar5 + 0x6f) != '\0') {
          *(ulonglong *)(param_2 + 0x38) = *(ulonglong *)(param_2 + 0x38) | 8;
        }
        goto LAB_1c0008513;
      }
      if (bVar3 == 0x17) {
        SerialMouseRemoveDevice((longlong)puVar5,param_2);
LAB_1c000837a:
        *(undefined4 *)(param_2 + 0x30) = 0;
      }
    }
LAB_1c000831e:
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
    uVar8 = IofCallDriver(*(undefined8 *)(puVar5 + 10),param_2);
    uVar11 = (ulonglong)uVar8;
  }
  IoReleaseRemoveLockEx(puVar1,param_2,0x20);
  return uVar11;
}



===== SerialMousePower @ 1c0008620 =====

ulonglong SerialMousePower(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  uint uVar4;
  int iVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong *plVar8;
  undefined8 local_res8;
  undefined8 in_stack_ffffffffffffff78;
  undefined8 uVar9;
  undefined4 uVar10;
  uint local_58 [4];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  lVar7 = *(longlong *)(param_2 + 0xb8);
  lVar2 = *(longlong *)(param_1 + 0x40);
  local_res8 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  iVar5 = *(int *)(lVar7 + 0x10);
  iVar1 = *(int *)(lVar7 + 0x18);
  uVar9 = CONCAT44((int)((ulonglong)in_stack_ffffffffffffff78 >> 0x20),0x20);
  uVar4 = IoAcquireRemoveLockEx(lVar2 + 0x38,param_2,"",1,uVar9);
  uVar10 = (undefined4)((ulonglong)uVar9 >> 0x20);
  if ((int)uVar4 < 0) {
    PoStartNextPowerIrp(param_2);
    *(uint *)(param_2 + 0x30) = uVar4;
    IofCompleteRequest(param_2,0);
    return (ulonglong)uVar4;
  }
  if (((*(char *)(lVar7 + 1) == '\x02') && (iVar5 == 1)) && (iVar1 != *(int *)(lVar2 + 0x164))) {
    if (iVar1 == 1) {
      KeInitializeEvent(&local_48,1);
      *(undefined1 *)(lVar2 + 0x1c0) = 0;
      *(undefined4 *)(lVar2 + 0x164) = *(undefined4 *)(lVar7 + 0x18);
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
      lVar7 = *(longlong *)(param_2 + 0xb8);
      *(code **)(lVar7 + -0x10) = SerialMouseCompletionRoutine;
      *(undefined8 **)(lVar7 + -8) = &local_48;
      *(undefined1 *)(lVar7 + -0x45) = 0xe0;
      uVar4 = PoCallDriver(*(undefined8 *)(lVar2 + 0x28),param_2);
      if (uVar4 == 0x103) {
        uVar10 = 0;
        KeWaitForSingleObject(&local_48,0,0,0,0);
        uVar4 = *(uint *)(param_2 + 0x30);
      }
      if ((-1 < (int)uVar4) && (-1 < *(int *)(param_2 + 0x30))) {
        PoSetPowerState(param_1,1,1);
        iVar5 = IoAcquireRemoveLockEx(lVar2 + 0x38,lVar2,"",1,CONCAT44(uVar10,0x20));
        if (-1 < iVar5) {
          lVar7 = IoAllocateWorkItem(param_1);
          if (lVar7 == 0) {
            IoReleaseRemoveLockEx(lVar2 + 0x38,lVar2,0x20);
          }
          else {
            plVar8 = (longlong *)ExAllocatePool2(0x40,0x10,0x7265734d);
            if (plVar8 == (longlong *)0x0) {
              IoFreeWorkItem(lVar7);
              IoReleaseRemoveLockEx(lVar2 + 0x38,lVar2,0x20);
            }
            else {
              plVar8[1] = lVar7;
              *plVar8 = lVar2;
              IoQueueWorkItem(lVar7,StartDeviceWorker,1,plVar8);
            }
          }
        }
      }
      *(uint *)(param_2 + 0x30) = uVar4;
      IoReleaseRemoveLockEx(lVar2 + 0x38,param_2,0x20);
      PoStartNextPowerIrp(param_2);
      IofCompleteRequest(param_2,0);
      return (ulonglong)uVar4;
    }
    if ((((iVar1 == 2) || (iVar1 == 3)) || (iVar1 == 4)) &&
       (*(undefined1 *)(lVar2 + 0x1c0) = 1, *(char *)(lVar2 + 0x1bf) == '\0')) {
      *(undefined4 *)(lVar2 + 0x164) = *(undefined4 *)(lVar7 + 0x18);
      IoCancelIrp(*(undefined8 *)(lVar2 + 0x78));
      SerialMouseStopDetection(lVar2);
      KeInitializeEvent(&local_48,0,0);
      uVar6 = SerialMousepIoSyncIoctlEx
                        (0,0x1b0034,*(undefined8 *)(lVar2 + 0x28),&local_48,local_58,0,0,0,0);
      if (-1 < (int)uVar6) {
        local_res8 = 0xffffffffffe91ca0;
        KeDelayExecutionThread(0,0,&local_res8);
      }
      PoSetPowerState(param_1,*(undefined4 *)(lVar7 + 0x10),*(undefined4 *)(lVar7 + 0x18));
      IoReleaseRemoveLockEx(lVar2 + 0x38,param_2,0x20);
      puVar3 = *(undefined8 **)(param_2 + 0xb8);
      *(undefined4 *)(param_2 + 0x30) = 0;
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
      PoStartNextPowerIrp(param_2);
      uVar6 = PoCallDriver(*(undefined8 *)(lVar2 + 0x28),param_2);
      return uVar6;
    }
  }
  PoStartNextPowerIrp(param_2);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  uVar4 = PoCallDriver(*(undefined8 *)(lVar2 + 0x28),param_2);
  IoReleaseRemoveLockEx(lVar2 + 0x38,param_2,0x20);
  return (ulonglong)uVar4;
}



===== SerialMouseRemoveDevice @ 1c0008a94 =====

void SerialMouseRemoveDevice(longlong param_1,longlong param_2)

{
  if (*(char *)(param_1 + 0x1b9) == '\0') {
    *(undefined1 *)(param_1 + 0x1b9) = 1;
    IoWMIRegistrationControl(*(undefined8 *)(param_1 + 8),2);
    if ((*(char *)(param_1 + 0x1ba) != '\0') && (0 < *(int *)(param_1 + 0x70))) {
      IoCancelIrp(*(undefined8 *)(param_1 + 0x78));
      SerialMouseStopDetection(param_1);
    }
  }
  if ((*(char *)(param_1 + 0x1b8) != '\0') && (0 < *(int *)(param_1 + 0x70))) {
    *(undefined4 *)(param_1 + 0x70) = 0;
    SerialMouseClosePort(param_1,param_2);
  }
  return;
}



===== SerialMouseSendIrpSynchronously @ 1c0008b20 =====

ulonglong SerialMouseSendIrpSynchronously(undefined8 param_1,longlong param_2,char param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeInitializeEvent(&local_28,1,0);
  if (param_3 != '\0') {
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
  }
  lVar2 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar2 + -0x10) = SerialMouseCompletionRoutine;
  *(undefined8 **)(lVar2 + -8) = &local_28;
  *(undefined1 *)(lVar2 + -0x45) = 0xe0;
  uVar3 = IofCallDriver(param_1,param_2);
  if ((int)uVar3 == 0x103) {
    KeWaitForSingleObject(&local_28,0,0,0,0);
    uVar3 = (ulonglong)*(uint *)(param_2 + 0x30);
  }
  return uVar3;
}



===== CSerDetect @ 1c0008c00 =====

undefined1 CSerDetect(longlong param_1,uint *param_2)

{
  int iVar1;
  ulonglong uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  longlong lVar7;
  undefined1 uVar8;
  undefined4 *puVar9;
  byte local_res8 [8];
  char local_res18 [8];
  uint local_res20 [2];
  uint local_68 [4];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  uVar4 = 0;
  local_res8[0] = 0;
  local_res18[0] = '\0';
  local_res20[0] = 0;
  local_48 = 0;
  uVar8 = 0;
  local_68[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  local_58 = 0;
  uStack_50 = 0;
  KeInitializeEvent(&local_58,0,0);
  SerialMousepIoSyncIoctlEx(0,0x1b0024,*(undefined8 *)(param_1 + 0x28),&local_58,local_68,0,0,0,0);
  SerialMousepIoSyncIoctlEx(0,0x1b0030,*(undefined8 *)(param_1 + 0x28),&local_58,local_68,0,0,0,0);
  uVar2 = SerialMousepIoSyncIoctlEx
                    (0,0x1b0068,*(undefined8 *)(param_1 + 0x28),&local_58,local_68,0,0,local_res20,4
                    );
  iVar5 = 3;
  if ((-1 < (int)uVar2) && (((byte)local_res20[0] & 3) == 3)) {
    SerialMouseWait(param_1,-5000000);
  }
  SerialMouseSetLineCtrl(param_1,&DAT_1c0005001);
  puVar9 = &DAT_1c0004168;
  do {
    SerialMouseSetBaudRate(param_1,*puVar9);
    CSerSetReportRate(param_1,0);
    CSerSetProtocol(param_1);
    local_res20[0] = CONCAT31(local_res20[0]._1_3_,0x73);
    uVar6 = 1;
    local_68[0] = 0;
    local_68[1] = 0;
    local_68[2] = 0;
    local_68[3] = 0;
    SerialMouseWriteSerialPort(param_1,local_res20,1,local_68);
    SerialMouseFlushReadBuffer(param_1);
    SerialMouseSetReadTimeouts(param_1,0x32);
    local_res20[0] = local_res20[0] & 0xffff0000;
    iVar1 = SerialMouseReadSerialPort(param_1,(longlong)local_res18,uVar6,(short *)local_res20);
    if (((-1 < iVar1) && ((short)local_res20[0] == 1)) && (local_res18[0] == 'O')) {
      local_res20[0] = CONCAT31(local_res20[0]._1_3_,0x6b);
      uVar6 = 1;
      local_68[0] = 0;
      local_68[1] = 0;
      local_68[2] = 0;
      local_68[3] = 0;
      uVar8 = 1;
      SerialMouseWriteSerialPort(param_1,local_res20,1,local_68);
      SerialMouseFlushReadBuffer(param_1);
      SerialMouseSetReadTimeouts(param_1,0x32);
      local_res20[0] = local_res20[0] & 0xffff0000;
      iVar1 = SerialMouseReadSerialPort(param_1,(longlong)local_res8,uVar6,(short *)local_res20);
      if ((iVar1 < 0) || ((short)local_res20[0] != 1)) {
        uVar4 = 2;
      }
      else {
        uVar4 = 2;
        local_res8[0] = local_res8[0] & 0xf;
        if ((local_res8[0] == 2) || (local_res8[0] == 3)) {
          uVar4 = (uint)local_res8[0];
        }
      }
      *param_2 = uVar4;
      SerialMouseSetReadTimeouts(param_1,0);
      break;
    }
    uVar4 = uVar4 + 1;
    puVar9 = puVar9 + 1;
  } while (uVar4 < 4);
  CSerSetReportRate(param_1,0);
  puVar3 = &DAT_1c00050c8;
  while (0x4b0 < *puVar3) {
    iVar5 = iVar5 + -1;
    puVar3 = puVar3 + -4;
    if ((longlong)puVar3 < 0x1c0005098) goto LAB_1c0008eb8;
  }
  local_68[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  lVar7 = -1;
  do {
    lVar7 = lVar7 + 1;
  } while ((&PTR_s__n_1c0005090)[(longlong)iVar5 * 2][lVar7] != '\0');
  SerialMouseWriteSerialPort(param_1,(&PTR_s__n_1c0005090)[(longlong)iVar5 * 2],(int)lVar7,local_68)
  ;
  SerialMouseSetBaudRate(param_1,*(undefined4 *)(&DAT_1c0005098 + (longlong)iVar5 * 0x10));
  SerialMouseWait(param_1,-20000);
LAB_1c0008eb8:
  CSerSetReportRate(param_1,0x96);
  return uVar8;
}



===== CSerSetProtocol @ 1c0008ee8 =====

undefined * CSerSetProtocol(longlong param_1)

{
  undefined1 local_res10 [24];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res10[0] = Protocol;
  local_18 = 0;
  uStack_10 = 0;
  SerialMouseWriteSerialPort(param_1,local_res10,1,(undefined4 *)&local_18);
  SerialMouseSetLineCtrl(param_1,&DAT_1c0005001);
  return PTR_CSerHandlerMM_1c0005008;
}



===== CSerSetReportRate @ 1c0008f40 =====

void CSerSetReportRate(longlong param_1,byte param_2)

{
  byte *pbVar1;
  int iVar2;
  undefined1 local_res18 [16];
  undefined8 local_18;
  undefined8 uStack_10;
  
  iVar2 = 8;
  pbVar1 = &DAT_1c0005121;
  do {
    if (*pbVar1 <= param_2) {
      local_18 = 0;
      uStack_10 = 0;
      local_res18[0] = (&DAT_1c0005110)[(longlong)iVar2 * 2];
      SerialMouseWriteSerialPort(param_1,local_res18,1,(undefined4 *)&local_18);
      return;
    }
    iVar2 = iVar2 + -1;
    pbVar1 = pbVar1 + -2;
  } while (0x1c0005110 < (longlong)pbVar1);
  return;
}



===== MSerDetect @ 1c0008fa4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 MSerDetect(longlong param_1)

{
  int iVar1;
  ulonglong uVar2;
  char *pcVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined1 auStackY_1a8 [32];
  short local_158 [4];
  uint local_150 [4];
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  char local_128 [256];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_1a8;
  uVar6 = 0;
  SerialMouseInitializePort(param_1);
  local_130 = 0;
  local_150[0] = 0;
  local_150[1] = 0;
  local_150[2] = 0;
  local_150[3] = 0;
  local_140 = 0;
  uStack_138 = 0;
  KeInitializeEvent(&local_140,0,0);
  uVar2 = SerialMousepIoSyncIoctlEx
                    (0,0x1b0024,*(undefined8 *)(param_1 + 0x28),&local_140,local_150,0,0,0,0);
  if ((-1 < (int)uVar2) &&
     (uVar2 = SerialMousepIoSyncIoctlEx
                        (0,0x1b0034,*(undefined8 *)(param_1 + 0x28),&local_140,local_150,0,0,0,0),
     -1 < (int)uVar2)) {
    SerialMouseWait(param_1,-2000000);
  }
  SerialMouseSetBaudRate(param_1,0x4b0);
  SerialMouseSetLineCtrl(param_1,&DAT_1c0005068);
  SerialMouseFlushReadBuffer(param_1);
  local_130 = 0;
  local_150[0] = 0;
  local_150[1] = 0;
  local_150[2] = 0;
  local_150[3] = 0;
  local_140 = 0;
  uStack_138 = 0;
  KeInitializeEvent(&local_140,0,0);
  uVar7 = *(undefined8 *)(param_1 + 0x28);
  uVar2 = SerialMousepIoSyncIoctlEx(0,0x1b0028,uVar7,&local_140,local_150,0,0,0,0);
  if (-1 < (int)uVar2) {
    uVar7 = *(undefined8 *)(param_1 + 0x28);
    uVar2 = SerialMousepIoSyncIoctlEx(0,0x1b0034,uVar7,&local_140,local_150,0,0,0,0);
    if ((-1 < (int)uVar2) && (iVar1 = SerialMouseWait(param_1,-2000000), -1 < iVar1)) {
      uVar7 = *(undefined8 *)(param_1 + 0x28);
      uVar2 = SerialMousepIoSyncIoctlEx(0,0x1b0024,uVar7,&local_140,local_150,0,0,0,0);
      if ((-1 < (int)uVar2) && (iVar1 = SerialMouseWait(param_1,-2000000), -1 < iVar1)) {
        uVar7 = *(undefined8 *)(param_1 + 0x28);
        SerialMousepIoSyncIoctlEx(0,0x1b0030,uVar7,&local_140,local_150,0,0,0,0);
        SerialMouseWait(param_1,-0x1ab3f0);
      }
    }
  }
  SerialMouseSetReadTimeouts(param_1,200);
  local_158[0] = 0;
  iVar1 = SerialMouseReadSerialPort(param_1,(longlong)local_128,uVar7,local_158);
  if ((-1 < iVar1) && (local_158[0] == 1)) {
    uVar6 = 1;
    SerialMouseSetReadTimeouts(param_1,100);
    do {
      local_158[0] = 0;
      iVar1 = SerialMouseReadSerialPort(param_1,(longlong)(local_128 + uVar6),uVar7,local_158);
      if ((iVar1 < 0) || (local_158[0] != 1)) break;
      uVar6 = uVar6 + 1;
    } while (uVar6 < 0xff);
  }
  uVar4 = 0;
  local_128[uVar6] = '\0';
  if (uVar6 != 0) {
    pcVar3 = local_128;
    do {
      if (*pcVar3 == 'M') {
        if (local_128[uVar4 + 1] == '3') {
          uVar5 = 2;
        }
        else {
          uVar5 = 1;
          if (local_128[uVar4 + 1] == 'Z') {
            uVar5 = 4;
          }
        }
LAB_1c00092a6:
        if (uVar4 < uVar6) {
          SerialMouseSetReadTimeouts(param_1,0);
          return uVar5;
        }
        if (uVar6 == 0) {
          return 0;
        }
        break;
      }
      if (*pcVar3 == 'B') {
        uVar5 = 3;
        goto LAB_1c00092a6;
      }
      uVar4 = uVar4 + 1;
      pcVar3 = pcVar3 + 1;
    } while (uVar4 < uVar6);
    SerialMouseWait(param_1,-5000000);
  }
  return 0;
}



===== SerialMouseClose @ 1c0009300 =====

ulonglong SerialMouseClose(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  
  lVar4 = *(longlong *)(param_1 + 0x40);
  lVar1 = lVar4 + 0x38;
  uVar5 = IoAcquireRemoveLockEx(lVar1,param_2,"",1,0x20);
  if (-1 < (int)uVar5) {
    LOCK();
    piVar2 = (int *)(lVar4 + 0x70);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 == 1) {
      IoCancelIrp(*(undefined8 *)(lVar4 + 0x78));
      SerialMouseStopDetection(lVar4);
      SerialMouseRestorePort(lVar4);
      IoReleaseRemoveLockEx(lVar1,param_2,0x20);
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      uVar6 = IofCallDriver(*(undefined8 *)(lVar4 + 0x28),param_2);
      return uVar6;
    }
    uVar5 = 0;
    IoReleaseRemoveLockEx(lVar1,param_2,0x20);
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(uint *)(param_2 + 0x30) = uVar5;
  IofCompleteRequest(param_2,0);
  return (ulonglong)uVar5;
}



===== SerialMouseCreate @ 1c0009400 =====

int SerialMouseCreate(longlong param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  ulonglong uVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  if (*(short *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x58) == 0) {
    iVar3 = IoAcquireRemoveLockEx(lVar2 + 0x38,param_2,"",1,0x20);
    if (-1 < iVar3) {
      if (*(longlong *)(lVar2 + 0x68) == 0) {
        iVar3 = -0x3fffffff;
      }
      else {
        LOCK();
        piVar1 = (int *)(lVar2 + 0x70);
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + 1;
        UNLOCK();
        if (iVar3 == 0) {
          uVar4 = SerialMouseSendIrpSynchronously(*(undefined8 *)(lVar2 + 0x28),param_2,'\x01');
          iVar3 = (int)uVar4;
          if ((iVar3 < 0) || (*(int *)(param_2 + 0x30) < 0)) {
            LOCK();
            *(int *)(lVar2 + 0x70) = *(int *)(lVar2 + 0x70) + -1;
            UNLOCK();
          }
          else {
            iVar3 = SerialMouseStartDevice(lVar2,param_2,'\x01');
          }
        }
        else {
          iVar3 = 0;
        }
      }
      IoReleaseRemoveLockEx(lVar2 + 0x38,param_2,0x20);
    }
  }
  else {
    iVar3 = -0x3fffffde;
  }
  *(int *)(param_2 + 0x30) = iVar3;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return iVar3;
}



===== SerialMouseClosePort @ 1c0009514 =====

void SerialMouseClosePort(longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  SerialMouseRestorePort(param_1);
  lVar1 = *(longlong *)(param_2 + 0xb8);
  memset((void *)(lVar1 + -0x48),0,0x48);
  *(undefined1 *)(lVar1 + -0x48) = 0x12;
  SerialMouseSendIrpSynchronously(*(undefined8 *)(param_1 + 0x28),param_2,'\0');
  lVar1 = *(longlong *)(param_2 + 0xb8);
  memset((void *)(lVar1 + -0x48),0,0x48);
  *(undefined1 *)(lVar1 + -0x48) = 2;
  SerialMouseSendIrpSynchronously(*(undefined8 *)(param_1 + 0x28),param_2,'\0');
  return;
}



===== SerialMouseInitializeDevice @ 1c0009598 =====

int SerialMouseInitializeDevice(longlong param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_38 [2];
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  uint local_18 [4];
  
  *(undefined1 *)(param_1 + 0x1ba) = 1;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  local_38[0] = 0;
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  KeInitializeEvent(&local_30,0,0);
  SerialMousepIoSyncIoctlEx
            (0,0x1b0044,*(undefined8 *)(param_1 + 0x28),&local_30,local_18,local_38,4,0,0);
  iVar1 = SerialMouseInitializeHardware(param_1);
  if (-1 < iVar1) {
    if (*(short *)(param_1 + 0xd0) == 0) {
      *(undefined2 *)(param_1 + 0xd0) = 4;
    }
    *(undefined1 *)(param_1 + 0x1be) = 1;
    SerialMouseStartDetection(param_1);
  }
  if (iVar1 != 0) {
    *(undefined1 *)(param_1 + 0x1ba) = 0;
    puVar2 = (undefined4 *)IoAllocateErrorLogEntry(*(undefined8 *)(param_1 + 8),0x30);
    if (puVar2 != (undefined4 *)0x0) {
      puVar2[3] = iVar1;
      *puVar2 = 0;
      *(undefined8 *)(puVar2 + 6) = 0;
      puVar2[5] = iVar1;
      IoWriteErrorLogEntry(puVar2);
    }
  }
  return iVar1;
}



===== SerialMouseInitializeHardware @ 1c00096ac =====

int SerialMouseInitializeHardware(longlong param_1)

{
  char cVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  uint local_res8 [2];
  uint local_38 [4];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_res8[0] = 0;
  iVar4 = -0x3fffffff;
  *(undefined8 *)(param_1 + 0x150) = 0;
  *(undefined8 *)(param_1 + 0x158) = 0;
  *(undefined4 *)(param_1 + 0x160) = 0;
  iVar2 = MSerDetect(param_1);
  if (iVar2 == 0) {
    cVar1 = CSerDetect(param_1,local_res8);
    if (cVar1 != '\0') {
      iVar4 = 0;
      puVar3 = CSerSetProtocol(param_1);
      *(undefined **)(param_1 + 0x148) = puVar3;
      uVar5 = local_res8[0];
      goto LAB_1c00097fa;
    }
    *(undefined8 *)(param_1 + 0x148) = 0;
  }
  else {
    iVar4 = 0;
    if (iVar2 == 1) {
      SerialMouseSetLineCtrl(param_1,&DAT_1c0005068);
      *(undefined **)(param_1 + 0x148) = PTR_MSerHandlerMP_1c0005060;
      *(undefined2 *)(param_1 + 0xd0) = 4;
      iVar4 = 0;
    }
    else {
      if (iVar2 == 2) {
        SerialMouseSetLineCtrl(param_1,&DAT_1c0005068);
        *(undefined **)(param_1 + 0x148) = PTR_MSerHandlerMP_1c0005060;
        *(undefined2 *)(param_1 + 0xd0) = 4;
        uVar5 = 3;
        goto LAB_1c00097fa;
      }
      if (iVar2 != 3) {
        uVar5 = 0;
        if (iVar2 == 4) {
          SerialMouseSetLineCtrl(param_1,&DAT_1c0005088);
          *(undefined **)(param_1 + 0x148) = PTR_MSerHandlerZ_1c0005080;
          *(undefined2 *)(param_1 + 0xd0) = 0x40;
          uVar5 = 3;
        }
        goto LAB_1c00097fa;
      }
      SerialMouseSetLineCtrl(param_1,&DAT_1c0005078);
      *(undefined **)(param_1 + 0x148) = PTR_MSerHandlerBP_1c0005070;
      *(undefined2 *)(param_1 + 0xd0) = 0x10;
      iVar4 = 0;
    }
  }
  uVar5 = 2;
LAB_1c00097fa:
  *(short *)(param_1 + 0xd2) = (short)uVar5;
  if (-1 < iVar4) {
    local_res8[0] = 0;
    local_18 = 0;
    local_38[0] = 0;
    local_38[1] = 0;
    local_38[2] = 0;
    local_38[3] = 0;
    local_28 = 0;
    uStack_20 = 0;
    KeInitializeEvent(&local_28,0,0);
    SerialMousepIoSyncIoctlEx
              (0,0x1b009c,*(undefined8 *)(param_1 + 0x28),&local_28,local_38,local_res8,4,0,0);
    SerialMouseFlushReadBuffer(param_1);
  }
  return iVar4;
}



===== SerialMouseServiceParameters @ 1c00098a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SerialMouseServiceParameters(undefined4 *param_1,longlong param_2)

{
  short sVar1;
  int iVar2;
  longlong lVar3;
  short *psVar4;
  longlong lVar5;
  code *pcVar6;
  undefined1 auStack_c8 [32];
  undefined8 local_a8;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90 [2];
  undefined8 local_88;
  longlong lStack_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 local_68;
  undefined8 uStack_60;
  wchar_t local_58 [12];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_c8;
  local_90[0] = 0;
  builtin_wcsncpy(local_58,L"Parameters",0xb);
  local_98 = 2;
  iVar2 = 0;
  local_78 = 2;
  local_94 = 0x28;
  local_74 = 0x28;
  local_88 = 0;
  lStack_80 = 0;
  RtlInitUnicodeString(&local_88,0);
  lVar3 = ExAllocatePool2(0x100,0xe0,0x7265734d);
  if (lVar3 != 0) {
    psVar4 = (short *)IoGetDriverObjectExtension(*(undefined8 *)(*(longlong *)(param_1 + 2) + 8),1);
    if ((psVar4 != (short *)0x0) && (*(longlong *)(psVar4 + 4) != 0)) {
      lVar5 = -1;
      do {
        lVar5 = lVar5 + 1;
      } while (local_58[lVar5] != L'\0');
      sVar1 = ((short)lVar5 + 1) * 2 + *psVar4;
      local_88._0_4_ = CONCAT22(sVar1,(undefined2)local_88);
      lStack_80 = ExAllocatePool2(0x100,sVar1,0x7265734d);
      if (lStack_80 != 0) {
        RtlAppendUnicodeToString(&local_88,*(undefined8 *)(psVar4 + 4));
        RtlAppendUnicodeToString(&local_88,local_58);
        lVar5 = lStack_80;
        if ((local_88 & 0xffff) + 2 <= (local_88 >> 0x10 & 0xffff)) {
          local_68 = 0;
          uStack_60 = 0;
          *(undefined2 *)(lStack_80 + (local_88 >> 1 & 0x7fff) * 2) = 0;
          *(undefined4 *)(lVar3 + 8) = 0x120;
          *(wchar_t **)(lVar3 + 0x10) = L"NumberOfButtons";
          *(undefined4 **)(lVar3 + 0x18) = &local_98;
          *(undefined4 **)(lVar3 + 0x28) = &local_78;
          *(undefined4 *)(lVar3 + 0x20) = 0x4000004;
          *(undefined4 *)(lVar3 + 0x30) = 4;
          *(wchar_t **)(lVar3 + 0x48) = L"SampleRate";
          *(undefined4 **)(lVar3 + 0x50) = &local_94;
          *(undefined4 *)(lVar3 + 0x40) = 0x120;
          *(undefined4 *)(lVar3 + 0x58) = 0x4000004;
          *(undefined4 **)(lVar3 + 0x60) = &local_74;
          *(undefined4 *)(lVar3 + 0x68) = 4;
          RtlInitUnicodeString(&local_68,L"RtlQueryRegistryValuesEx");
          pcVar6 = (code *)MmGetSystemRoutineAddress(&local_68);
          local_a8 = 0;
          if (pcVar6 == (code *)0x0) {
            pcVar6 = RtlQueryRegistryValues_exref;
          }
          iVar2 = (*pcVar6)(0x80000000,lVar5,lVar3,0);
          if (iVar2 < 0) {
            *param_1 = 0;
          }
          goto LAB_1c0009aeb;
        }
      }
      iVar2 = -0x3fffffff;
    }
LAB_1c0009aeb:
    if (param_2 != 0) {
      local_70 = local_98;
      *(wchar_t **)(lVar3 + 0x10) = L"NumberOfButtons";
      *(undefined4 *)(lVar3 + 8) = 0x120;
      *(undefined4 *)(lVar3 + 0x20) = 0x4000004;
      *(undefined4 *)(lVar3 + 0x30) = 4;
      local_6c = local_94;
      *(undefined4 **)(lVar3 + 0x18) = &local_98;
      *(undefined4 **)(lVar3 + 0x28) = &local_70;
      *(undefined4 **)(lVar3 + 0x50) = &local_94;
      *(undefined4 **)(lVar3 + 0x60) = &local_6c;
      *(wchar_t **)(lVar3 + 0x48) = L"SampleRate";
      *(undefined4 *)(lVar3 + 0x40) = 0x120;
      *(undefined4 *)(lVar3 + 0x58) = 0x4000004;
      *(undefined4 *)(lVar3 + 0x68) = 4;
      *(wchar_t **)(lVar3 + 0x80) = L"WaitEventMask";
      *(undefined4 **)(lVar3 + 0x88) = param_1 + 0x4e;
      *(undefined4 **)(lVar3 + 0x98) = local_90;
      *(undefined4 *)(lVar3 + 0x78) = 0x120;
      *(undefined4 *)(lVar3 + 0x90) = 0x4000004;
      *(undefined4 *)(lVar3 + 0xa0) = 4;
      local_68 = 0;
      uStack_60 = 0;
      RtlInitUnicodeString(&local_68,L"RtlQueryRegistryValuesEx");
      pcVar6 = (code *)MmGetSystemRoutineAddress(&local_68);
      local_a8 = 0;
      if (pcVar6 == (code *)0x0) {
        pcVar6 = RtlQueryRegistryValues_exref;
      }
      iVar2 = (*pcVar6)(0x40000000,param_2,lVar3,0);
    }
    if (-1 < iVar2) goto LAB_1c0009bf4;
  }
  param_1[0x4e] = local_90[0];
LAB_1c0009bf4:
  *(undefined2 *)((longlong)param_1 + 0xd2) = (undefined2)local_98;
  *(undefined2 *)(param_1 + 0x35) = (undefined2)local_94;
  if (lStack_80 != 0) {
    ExFreePoolWithTag(lStack_80,0);
  }
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0);
  }
  return;
}



===== SerialMouseSpinUpRead @ 1c0009c68 =====

undefined8 SerialMouseSpinUpRead(longlong param_1)

{
  undefined8 uVar1;
  
  IoAcquireRemoveLockEx(param_1 + 0x38,*(undefined8 *)(param_1 + 0x78),"",1,0x20);
  *(undefined4 *)(param_1 + 0x58) = 2;
  uVar1 = SerialMouseStartRead(param_1);
  if (((int)uVar1 == 0x103) || ((int)uVar1 == 0)) {
    uVar1 = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0x1ba) = 0;
  }
  return uVar1;
}



===== SerialMouseStartDevice @ 1c0009ccc =====

int SerialMouseStartDevice(longlong param_1,longlong param_2,char param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = SerialMouseInitializeDevice(param_1);
  if (-1 < iVar1) {
    uVar2 = SerialMouseSpinUpRead(param_1);
    iVar1 = (int)uVar2;
    if (-1 < iVar1) {
      return iVar1;
    }
  }
  if (param_3 != '\0') {
    SerialMouseClosePort(param_1,param_2);
    LOCK();
    *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + -1;
    UNLOCK();
  }
  return iVar1;
}



===== SerialMouseUnload @ 1c0009d40 =====

void SerialMouseUnload(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = IoGetDriverObjectExtension(param_1,1);
  if ((lVar1 != 0) && (*(longlong *)(lVar1 + 8) != 0)) {
    ExFreePoolWithTag(*(longlong *)(lVar1 + 8),0);
  }
  return;
}



===== SerialMousepIoSyncIoctl @ 1c0009d80 =====

void SerialMousepIoSyncIoctl
               (undefined1 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
               uint *param_5)

{
  SerialMousepIoSyncIoctlEx(param_1,param_2,param_3,param_4,param_5,0,0,0,0);
  return;
}



===== SerialMousepIoSyncIoctlEx @ 1c0009db8 =====

ulonglong SerialMousepIoSyncIoctlEx
                    (undefined1 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
                    uint *param_5,undefined8 param_6,undefined4 param_7,undefined8 param_8,
                    undefined4 param_9)

{
  longlong lVar1;
  ulonglong uVar2;
  
  KeClearEvent(param_4);
  lVar1 = IoBuildDeviceIoControlRequest
                    (param_2,param_3,param_6,param_7,param_8,param_9,param_1,param_4,param_5);
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    uVar2 = IofCallDriver(param_3,lVar1);
    if ((int)uVar2 == 0x103) {
      uVar2 = KeWaitForSingleObject(param_4,0,0,0,0);
      if (-1 < (int)uVar2) {
        uVar2 = (ulonglong)*param_5;
      }
    }
  }
  return uVar2;
}



===== SerialMouseSendWaitMaskIrp @ 1c0009ea4 =====

void SerialMouseSendWaitMaskIrp(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x80);
  *(undefined4 *)(param_1 + 0x88) = 0;
  iVar3 = IoAcquireRemoveLockEx(param_1 + 0x38,lVar1,"",1,0x20);
  if (-1 < iVar3) {
    IoReuseIrp(lVar1,0);
    lVar2 = *(longlong *)(lVar1 + 0xb8);
    *(undefined1 *)(lVar2 + -0x48) = 0xe;
    *(undefined4 *)(lVar2 + -0x30) = 0x1b0048;
    *(undefined4 *)(lVar2 + -0x40) = 4;
    lVar2 = *(longlong *)(lVar1 + 0xb8);
    *(undefined4 **)(lVar1 + 0x18) = (undefined4 *)(param_1 + 0x88);
    *(code **)(lVar2 + -0x10) = SerialMouseSerialMaskEventComplete;
    *(longlong *)(lVar2 + -8) = param_1;
    *(undefined1 *)(lVar2 + -0x45) = 0xe0;
    IofCallDriver(*(undefined8 *)(param_1 + 0x28),lVar1);
  }
  return;
}



===== SerialMouseSerialMaskEventWorker @ 1c0009f70 =====

void SerialMouseSerialMaskEventWorker(longlong param_1,undefined8 param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  int local_res8 [2];
  uint local_38 [4];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  local_res8[0] = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  lVar3 = *(longlong *)(lVar2 + 0x80);
  KeInitializeEvent(&local_28,0,0);
  iVar1 = *(int *)(lVar3 + 0x30);
  if (iVar1 == -0x3ffffee0) {
    if ((*(int *)(lVar2 + 0x164) == 1) || (*(char *)(lVar2 + 0x1c0) != '\0')) goto LAB_1c000a07e;
  }
  else {
    if (iVar1 != 0) goto LAB_1c000a07e;
    SerialMousepIoSyncIoctlEx
              (0,0x1b0068,*(undefined8 *)(lVar2 + 0x28),&local_28,local_38,0,0,local_res8,4);
    if (*(int *)(lVar2 + 0x13c) == local_res8[0]) {
      SerialMouseSendWaitMaskIrp(lVar2);
      goto LAB_1c000a07e;
    }
    SerialMousepIoSyncIoctlEx(1,0x370207,*(undefined8 *)(lVar2 + 0x28),&local_28,local_38,0,0,0,0);
  }
  *(undefined1 *)(lVar2 + 0x1bc) = 1;
LAB_1c000a07e:
  IoReleaseRemoveLockEx(lVar2 + 0x38,param_2,0x20);
  IoFreeWorkItem(param_2);
  return;
}



===== SerialMouseStartDetection @ 1c000a0c4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SerialMouseStartDetection(longlong param_1)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  uint uVar4;
  longlong lVar5;
  undefined1 auStackY_a8 [32];
  uint local_58;
  uint local_54 [3];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  uint local_30 [8];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_30[6] = 0;
  local_54[0] = 0;
  local_38 = 0;
  uVar4 = 0x20;
  local_54[2] = 8;
  local_30[4] = 0x20;
  local_30[5] = 0x10;
  local_54[1] = 0x10;
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  local_48 = 0;
  uStack_40 = 0;
  if (*(int *)(param_1 + 0x138) != -1) {
    KeInitializeEvent(&local_48,0,0);
    local_58 = *(uint *)(param_1 + 0x138);
    if (local_58 == 0) {
      uVar2 = SerialMousepIoSyncIoctlEx
                        (0,0x1b0068,*(undefined8 *)(param_1 + 0x28),&local_48,local_30,0,0,local_54,
                         4);
      if (((int)uVar2 < 0) || (local_54[0] == 0)) {
        *(undefined4 *)(param_1 + 0x13c) = 0;
        goto LAB_1c000a25c;
      }
      local_58 = 0;
      *(uint *)(param_1 + 0x13c) = local_54[0];
      lVar3 = 0;
      lVar5 = 0;
      do {
        if ((local_54[0] & uVar4) != 0) {
          local_58 = local_58 | *(uint *)((longlong)local_54 + lVar3 + 4);
        }
        lVar3 = (lVar5 + 1) * 4;
        uVar4 = local_30[lVar5 + 5];
        lVar5 = lVar5 + 1;
      } while (uVar4 != 0);
    }
    uVar2 = SerialMousepIoSyncIoctlEx
                      (0,0x1b0044,*(undefined8 *)(param_1 + 0x28),&local_48,local_30,&local_58,4,0,0
                      );
    if (-1 < (int)uVar2) {
      if (*(longlong *)(param_1 + 0x80) == 0) {
        lVar3 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 8) >> 8),
                                       *(undefined1 *)(*(longlong *)(param_1 + 8) + 0x4c)),0);
        *(longlong *)(param_1 + 0x80) = lVar3;
        if (lVar3 == 0) goto LAB_1c000a25c;
      }
      iVar1 = SerialMouseSendWaitMaskIrp(param_1);
      if (-1 < iVar1) {
        *(undefined1 *)(param_1 + 0x1be) = 1;
        return;
      }
      IoCancelIrp(*(undefined8 *)(param_1 + 0x80));
    }
  }
LAB_1c000a25c:
  *(undefined1 *)(param_1 + 0x1be) = 0;
  return;
}



===== SerialMouseStopDetection @ 1c000a28c =====

void SerialMouseStopDetection(longlong param_1)

{
  if ((*(char *)(param_1 + 0x1be) != '\0') && (*(char *)(param_1 + 0x1bc) == '\0')) {
    IoCancelIrp(*(undefined8 *)(param_1 + 0x80));
  }
  return;
}



===== SerialMouseQueryWmiDataBlock @ 1c000a2d0 =====

void SerialMouseQueryWmiDataBlock
               (longlong param_1,undefined8 param_2,int param_3,undefined8 param_4,
               undefined8 param_5,undefined4 *param_6,uint param_7,undefined4 *param_8)

{
  ushort uVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  uVar4 = 0;
  if (param_3 == 0) {
    uVar4 = 0x14;
    if (param_7 < 0x14) {
      uVar3 = 0xc0000023;
    }
    else {
      *param_6 = 0x14;
      uVar1 = *(ushort *)(lVar2 + 0xd2);
      *(ulonglong *)param_8 = (ulonglong)*(uint *)(lVar2 + 0xd8) << 0x20;
      *(ulonglong *)(param_8 + 2) = (ulonglong)uVar1 << 0x20;
      param_8[4] = 0;
      uVar3 = 0;
      *param_6 = 0x14;
    }
  }
  else {
    uVar3 = 0xc0000295;
  }
  WmiCompleteRequest(param_1,param_2,uVar3,uVar4,0);
  return;
}



===== SerialMouseQueryWmiRegInfo @ 1c000a370 =====

undefined8
SerialMouseQueryWmiRegInfo
          (longlong param_1,undefined4 *param_2,undefined8 param_3,longlong *param_4,
          undefined8 param_5,undefined8 *param_6)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  *param_2 = 0x20;
  lVar2 = IoGetDriverObjectExtension(*(undefined8 *)(param_1 + 8),1);
  if (lVar2 != 0) {
    *param_4 = lVar2;
  }
  *param_6 = *(undefined8 *)(lVar1 + 0x30);
  return 0;
}



===== SerialMouseSetWmiDataBlock @ 1c000a3d0 =====

void SerialMouseSetWmiDataBlock(undefined8 param_1,undefined8 param_2,int param_3)

{
  WmiCompleteRequest(param_1,param_2,(-(uint)(param_3 != 0) & 0xffffffcf) + 0xc00002c6,0,0);
  return;
}



===== SerialMouseSystemControl @ 1c000a410 =====

undefined4 SerialMouseSystemControl(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  int local_res8 [2];
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_res8[0] = 0;
  uVar2 = WmiSystemControl(lVar1 + 0x90,param_1,param_2,local_res8);
  if (local_res8[0] != 0) {
    if (local_res8[0] == 1) {
      IofCompleteRequest(param_2,0);
    }
    else {
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      uVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 0x28),param_2,local_res8[0] + -2);
    }
  }
  return uVar2;
}



===== SerialMouseSetBaudRate @ 1c000a4ac =====

void SerialMouseSetBaudRate(longlong param_1,undefined4 param_2)

{
  undefined4 local_res10 [6];
  uint local_38 [4];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeInitializeEvent(&local_28,0,0);
  local_res10[0] = param_2;
  SerialMousepIoSyncIoctlEx
            (0,0x1b0004,*(undefined8 *)(param_1 + 0x28),&local_28,local_38,local_res10,4,0,0);
  return;
}



===== SerialMouseSetLineCtrl @ 1c000a54c =====

void SerialMouseSetLineCtrl(longlong param_1,undefined8 param_2)

{
  uint local_38 [4];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeInitializeEvent(&local_28,0,0);
  SerialMousepIoSyncIoctlEx
            (0,0x1b000c,*(undefined8 *)(param_1 + 0x28),&local_28,local_38,param_2,3,0,0);
  return;
}



===== entry @ 1c000b010 =====

void entry(longlong param_1,ushort *param_2)

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

undefined8 DriverEntry(longlong param_1,ushort *param_2)

{
  undefined8 uVar1;
  ushort *local_res8;
  
  local_res8 = (ushort *)0x0;
  IoAllocateDriverObjectExtension(param_1,1,0x10,&local_res8);
  if (local_res8 != (ushort *)0x0) {
    local_res8[1] = *param_2 + 2;
    *local_res8 = *param_2;
    uVar1 = ExAllocatePool2(0x40,local_res8[1],0x7265734d);
    *(undefined8 *)(local_res8 + 4) = uVar1;
    if (*(void **)(local_res8 + 4) == (void *)0x0) {
      *local_res8 = 0;
      local_res8[1] = 0;
    }
    else {
      memcpy(*(void **)(local_res8 + 4),*(void **)(param_2 + 4),(ulonglong)*param_2);
    }
  }
  *(code **)(param_1 + 0x70) = SerialMouseCreate;
  *(code **)(param_1 + 0x80) = SerialMouseClose;
  *(code **)(param_1 + 0xb8) = SerialMouseFlush;
  *(code **)(param_1 + 0xe8) = SerialMouseInternalDeviceControl;
  *(code **)(param_1 + 0x148) = SerialMousePnP;
  *(code **)(param_1 + 0x120) = SerialMousePower;
  *(code **)(param_1 + 0x128) = SerialMouseSystemControl;
  *(code **)(param_1 + 0x68) = SerialMouseUnload;
  *(code **)(*(longlong *)(param_1 + 0x30) + 8) = SerialMouseAddDevice;
  return 0;
}


