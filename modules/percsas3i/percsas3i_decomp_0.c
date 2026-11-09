
===== BuildSGLforIOCTL @ 140001000 =====

longlong BuildSGLforIOCTL(longlong param_1,undefined8 *param_2,longlong param_3,uint param_4)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint local_res8 [2];
  
  uVar2 = *param_2;
  local_res8[0] = 0;
  do {
    if (*(uint *)(param_1 + 0x888) < (uint)*(ushort *)((longlong)param_2 + 0x34)) {
      return (ulonglong)(byte)(*(ushort *)((longlong)param_2 + 0x34) >> 8) << 8;
    }
    uVar3 = StorPortGetPhysicalAddress(param_1,uVar2,param_3,local_res8);
    if (param_4 < local_res8[0]) {
      local_res8[0] = param_4;
    }
    cVar1 = *(char *)((longlong)param_2 + 0x1a);
    *(int *)param_2[8] = (int)uVar3;
    if (cVar1 == '\0') {
      *(uint *)(param_2[8] + 4) = local_res8[0];
      param_2[8] = param_2[8] + 8;
    }
    else {
      *(int *)(param_2[8] + 4) = (int)((ulonglong)uVar3 >> 0x20);
      *(uint *)(param_2[8] + 8) = local_res8[0];
      param_2[8] = param_2[8] + 0xc;
    }
    *(short *)((longlong)param_2 + 0x34) = *(short *)((longlong)param_2 + 0x34) + 1;
    param_3 = param_3 + (ulonglong)local_res8[0];
    param_4 = param_4 - local_res8[0];
  } while (param_4 != 0);
  return CONCAT71((uint7)(uint3)(local_res8[0] >> 8),1);
}



===== BuildSGLforSRB @ 1400010c0 =====

longlong BuildSGLforSRB(longlong param_1,undefined8 *param_2)

{
  char cVar1;
  uint uVar2;
  uint *puVar3;
  ulonglong uVar4;
  uint uVar5;
  
  puVar3 = (uint *)StorPortGetScatterGatherList(param_1,*param_2);
  uVar2 = *puVar3;
  uVar4 = (ulonglong)uVar2;
  if (*(uint *)(param_1 + 0x884) < *(ushort *)((longlong)param_2 + 0x34) + uVar2) {
    return (ulonglong)(uint3)(uVar2 >> 8) << 8;
  }
  uVar5 = 0;
  if (uVar2 != 0) {
    do {
      if (*(char *)(param_1 + 0x6468) == '\0') {
        if (*(char *)((longlong)param_2 + 0x1b) == '\0') {
          cVar1 = *(char *)((longlong)param_2 + 0x1a);
          *(uint *)param_2[8] = puVar3[(ulonglong)uVar5 * 6 + 4];
          if (cVar1 == '\0') {
            uVar4 = (ulonglong)puVar3[(ulonglong)uVar5 * 6 + 6];
            *(uint *)(param_2[8] + 4) = puVar3[(ulonglong)uVar5 * 6 + 6];
            param_2[8] = param_2[8] + 8;
          }
          else {
            *(uint *)(param_2[8] + 4) = puVar3[(ulonglong)uVar5 * 6 + 5];
            uVar4 = (ulonglong)puVar3[(ulonglong)uVar5 * 6 + 6];
            *(uint *)(param_2[8] + 8) = puVar3[(ulonglong)uVar5 * 6 + 6];
            param_2[8] = param_2[8] + 0xc;
          }
        }
        else {
          *(undefined8 *)param_2[8] = *(undefined8 *)(puVar3 + (ulonglong)uVar5 * 6 + 4);
          *(uint *)(param_2[8] + 8) = puVar3[(ulonglong)uVar5 * 6 + 6];
          uVar4 = param_2[8];
          *(undefined4 *)(uVar4 + 0xc) = 0;
          param_2[8] = param_2[8] + 0x10;
        }
      }
      else {
        if (uVar5 == 7) {
          param_2[8] = param_2[8] + 0x10;
        }
        *(undefined8 *)param_2[8] = *(undefined8 *)(puVar3 + (ulonglong)uVar5 * 6 + 4);
        *(uint *)(param_2[8] + 8) = puVar3[(ulonglong)uVar5 * 6 + 6];
        *(undefined1 *)(param_2[8] + 0xf) = 0;
        *(undefined1 *)(param_2[8] + 0xe) = 0;
        uVar4 = param_2[8];
        *(undefined2 *)(uVar4 + 0xc) = 0;
        param_2[8] = param_2[8] + 0x10;
      }
      *(short *)((longlong)param_2 + 0x34) = *(short *)((longlong)param_2 + 0x34) + 1;
      uVar5 = uVar5 + 1;
    } while (uVar5 < *puVar3);
  }
  if (*(char *)(param_1 + 0x6468) != '\0') {
    uVar4 = (ulonglong)*(byte *)((longlong)param_2 + 0x36);
    param_2[9] = uVar4 * 7 + param_2[7];
  }
  return CONCAT71((int7)(uVar4 >> 8),1);
}



===== ClearSRBExtension @ 140001200 =====

longlong * ClearSRBExtension(longlong param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  undefined1 uVar3;
  longlong *plVar4;
  undefined1 local_res8 [8];
  
  plVar4 = (longlong *)
           (*(longlong *)(param_2 + 0x38) + (ulonglong)*(ushort *)(param_1 + 0x1d0) &
           (longlong)(int)~(uint)*(ushort *)(param_1 + 0x1d0));
  MemFastZero(plVar4,0x600);
  *plVar4 = param_2;
  *(undefined1 *)((longlong)plVar4 + 0x1b) = 0;
  cVar1 = *(char *)(param_1 + 0x1d3);
  *(char *)((longlong)plVar4 + 0x1a) = cVar1;
  uVar3 = 8;
  if (cVar1 != '\0') {
    uVar3 = 0xc;
  }
  *(undefined1 *)((longlong)plVar4 + 0x36) = uVar3;
  lVar2 = StorPortGetPhysicalAddress(param_1,param_2,plVar4,local_res8);
  plVar4[2] = lVar2 + 0x100;
  return plVar4;
}



===== DoBuildIo @ 140001290 =====

ulonglong DoBuildIo(int *param_1,longlong param_2)

{
  byte bVar1;
  char cVar2;
  ulonglong uVar3;
  longlong *plVar4;
  longlong *plVar5;
  
  if (((*(char *)(param_2 + 2) == '\0') && (*(char *)(param_2 + 0x48) == -0x60)) &&
     (*(char *)(param_2 + 6) == '\0')) {
    if (*(char *)(param_2 + 5) == '\x01') {
      *(undefined1 *)(param_1 + 0x76) = 0;
    }
    if (*(char *)(param_2 + 5) == '\0') {
      MemFastZero((undefined8 *)((longlong)param_1 + 0x6ab2),0x100);
    }
  }
  uVar3 = CheckForValidIO((longlong)param_1,param_2);
  if ((char)uVar3 == '\0') {
    return uVar3;
  }
  *(undefined1 *)(param_2 + 3) = 0;
  plVar4 = (longlong *)0x0;
  switch(*(undefined1 *)(param_2 + 2)) {
  case 0:
    plVar4 = InitSRBExtension((longlong)param_1,param_2);
    if (*(char *)(param_2 + 5) == '\x01') {
      bVar1 = *(byte *)(param_2 + 6);
      if (((*(byte *)(param_1 + 0x76) <= bVar1) && (bVar1 != 0xff)) &&
         ((*(char *)(param_2 + 0x48) != -0x60 && (*(char *)(param_2 + 0x48) != '\x12')))) {
        *(byte *)(param_1 + 0x76) = bVar1 + 1;
      }
      cVar2 = -2;
      if ((char)param_1[0x1b5c] == '\0') {
        cVar2 = '@';
      }
      if ((*(char *)(param_2 + 6) == cVar2) && (*(char *)(param_2 + 7) == '\0')) {
        uVar3 = ProcessPrivateDevice(param_1,param_2);
        return uVar3 & 0xffffffffffffff00;
      }
      if (*(char *)(param_2 + 0x48) == '5') {
        return 0;
      }
      if (*(char *)(param_2 + 0x48) == -0x6f) {
        return 0;
      }
    }
    uVar3 = SetMessageNumber((longlong)param_1,param_2);
    *(char *)((longlong)plVar4 + 0xc) = (char)uVar3;
    if (*(char *)(param_2 + 5) == '\x01') {
      *(bool *)(plVar4 + 3) = (*(char *)(param_2 + 0x48) - 8U & 0x5f) == 0;
      *(bool *)((longlong)plVar4 + 0x19) = (*(char *)(param_2 + 0x48) - 10U & 0x5f) == 0;
    }
    *(undefined1 *)((longlong)plVar4 + 0x54) = *(undefined1 *)(param_2 + 10);
    if ((char)param_1[0x191a] == '\0') {
      if (((char)plVar4[3] == '\0') && (*(char *)((longlong)plVar4 + 0x19) == '\0')) {
        uVar3 = MFI_BuildFrame_NonRW((longlong)param_1,plVar4);
      }
      else {
        uVar3 = MFI_BuildFrame_RW((longlong)param_1,plVar4);
      }
    }
    else {
      uVar3 = MPT_BuildCmd_Scsi(param_1,plVar4);
    }
    if ((char)uVar3 == '\0') {
      return uVar3;
    }
    if ((uint)param_1[0x1230] < 2) {
      return uVar3;
    }
    if (((char)plVar4[3] == '\0') && (*(char *)((longlong)plVar4 + 0x19) == '\0')) {
      return uVar3;
    }
    if ((char)param_1[0x22] == '\0') {
      *(undefined1 *)((longlong)plVar4 + 0x56) = 1;
      return uVar3;
    }
    return uVar3;
  case 2:
    uVar3 = MegaSASIoctl((longlong)param_1,param_2);
    return uVar3;
  case 7:
    *(undefined1 *)((longlong)param_1 + 0x1d7) = 1;
    if ((char)param_1[0x22] != '\0') {
      AbortPendedCommands((longlong)param_1);
      param_1[0x1916] = 30000000;
      SendAndWaitDCMD(param_1,0x1101000);
      param_1[0x1916] = 30000000;
      SendAndWaitDCMD(param_1,0x1060000);
      *(undefined2 *)(param_2 + 3) = 1;
      uVar3 = StorPortNotification(0,param_1,param_2);
      return uVar3 & 0xffffffffffffff00;
    }
    break;
  case 8:
    if ((char)param_1[0x28] != '\0') {
      plVar5 = ClearSRBExtension((longlong)param_1,param_2);
      plVar4 = plVar5 + 0x20;
      *(undefined1 *)plVar4 = 5;
      *(undefined4 *)(plVar5 + 0x23) = 0x1101000;
      *(undefined1 *)((longlong)plVar5 + 0x102) = 0xff;
      *(undefined1 *)((longlong)plVar5 + 0x11c) = 3;
LAB_1400014c9:
      return CONCAT71((int7)((ulonglong)plVar4 >> 8),1);
    }
    break;
  case 0x17:
    uVar3 = MegaSASWmiSrb((longlong)param_1,param_2);
    return uVar3 & 0xffffffffffffff00;
  case 0x24:
    if ((char)param_1[0x22] == '\0') goto LAB_1400014c9;
  default:
    *(undefined1 *)(param_2 + 3) = 6;
  }
  return 0;
}



===== InitSRBExtension @ 1400015c0 =====

longlong * InitSRBExtension(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  longlong *plVar2;
  char cVar3;
  
  cVar3 = '\0';
  plVar2 = (longlong *)
           (*(longlong *)(param_2 + 0x38) + (ulonglong)*(ushort *)(param_1 + 0x1d0) &
           (longlong)(int)~(uint)*(ushort *)(param_1 + 0x1d0));
  *(undefined4 *)(plVar2 + 1) = 0;
  *(undefined2 *)(plVar2 + 3) = 0;
  *(undefined1 *)((longlong)plVar2 + 0x1c) = 0;
  *(undefined4 *)(plVar2 + 6) = 0;
  plVar2[4] = 0;
  *(undefined2 *)((longlong)plVar2 + 0x34) = 0;
  *(undefined2 *)((longlong)plVar2 + 0x55) = 0;
  *(undefined2 *)(plVar2 + 0xb) = 0;
  plVar2[0xc] = 0;
  *(undefined2 *)(plVar2 + 0xd) = 0;
  plVar2[0xe] = 0;
  *(undefined2 *)(plVar2 + 0xf) = 0;
  *(undefined4 *)((longlong)plVar2 + 0x7c) = 0;
  *(undefined1 *)((longlong)plVar2 + 0xc) = 0;
  *plVar2 = param_2;
  *(undefined4 *)(plVar2 + 10) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(plVar2 + 0x10) = 0x200;
  *(undefined1 *)((longlong)plVar2 + 0x1b) = *(undefined1 *)(param_1 + 0x1d2);
  if ((*(char *)(param_1 + 0x1d2) != '\0') || (*(char *)(param_1 + 0x1d3) != '\0')) {
    cVar3 = '\x01';
  }
  *(char *)((longlong)plVar2 + 0x1a) = cVar3;
  if (*(char *)(param_1 + 0x1d2) == '\0') {
    uVar1 = 8;
    if (cVar3 != '\0') {
      uVar1 = 0xc;
    }
    *(undefined1 *)((longlong)plVar2 + 0x36) = uVar1;
    return plVar2;
  }
  uVar1 = 0xc;
  if (cVar3 != '\0') {
    uVar1 = 0x10;
  }
  *(undefined1 *)((longlong)plVar2 + 0x36) = uVar1;
  return plVar2;
}



===== MegaSASBuildIo @ 140001690 =====

ulonglong MegaSASBuildIo(int *param_1,longlong param_2)

{
  ulonglong uVar1;
  
  uVar1 = DoBuildIo(param_1,param_2);
  if ((char)uVar1 != '\0') {
    return CONCAT71((int7)(uVar1 >> 8),1);
  }
  if (*(char *)(param_2 + 3) == '\0') {
    *(undefined2 *)(param_2 + 3) = 1;
  }
  uVar1 = StorPortNotification(0,param_1,param_2);
  return uVar1 & 0xffffffffffffff00;
}



===== ProcessPrivateDevice @ 1400016e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ProcessPrivateDevice(undefined8 param_1,longlong param_2)

{
  undefined1 auStack_a8 [32];
  byte local_88 [8];
  undefined8 local_80;
  char local_78 [8];
  char acStack_70 [8];
  undefined8 local_68 [10];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  if (*(char *)(param_2 + 0x48) == '\x12') {
    MemFastZero(*(undefined8 **)(param_2 + 0x18),*(uint *)(param_2 + 0x10));
    MemFastZero((undefined8 *)local_88,0x68);
    if ((*(byte *)(param_2 + 0x49) & 1) == 0) {
      local_88[0] = local_88[0] | 0x1f;
      MemFastMove(&local_80,(undefined8 *)s_RAID_14000f000,8);
      local_78[0] = s_DummyDevice_14000f010[0];
      local_78[1] = s_DummyDevice_14000f010[1];
      local_78[2] = s_DummyDevice_14000f010[2];
      local_78[3] = s_DummyDevice_14000f010[3];
      local_78[4] = s_DummyDevice_14000f010[4];
      local_78[5] = s_DummyDevice_14000f010[5];
      local_78[6] = s_DummyDevice_14000f010[6];
      local_78[7] = s_DummyDevice_14000f010[7];
      acStack_70[0] = s_DummyDevice_14000f010[8];
      acStack_70[1] = s_DummyDevice_14000f010[9];
      acStack_70[2] = s_DummyDevice_14000f010[10];
      acStack_70[3] = s_DummyDevice_14000f010[0xb];
      acStack_70[4] = s_DummyDevice_14000f010[0xc];
      acStack_70[5] = s_DummyDevice_14000f010[0xd];
      acStack_70[6] = s_DummyDevice_14000f010[0xe];
      acStack_70[7] = s_DummyDevice_14000f010[0xf];
      MemFastMove(local_68,(undefined8 *)&s_0001,4);
      if (*(uint *)(param_2 + 0x10) < 0x68) {
        MemFastMove(*(undefined8 **)(param_2 + 0x18),(undefined8 *)local_88,
                    *(uint *)(param_2 + 0x10));
      }
      else {
        MemFastMove(*(undefined8 **)(param_2 + 0x18),(undefined8 *)local_88,0x68);
        *(undefined4 *)(param_2 + 0x10) = 0x68;
      }
    }
    else {
      *(undefined1 *)(param_2 + 3) = 6;
    }
  }
  else {
    *(undefined1 *)(param_2 + 3) = 6;
  }
  return;
}



===== SetMessageNumber @ 1400017c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SetMessageNumber(longlong param_1,longlong param_2)

{
  undefined1 auStack_48 [32];
  undefined1 local_28 [4];
  undefined4 local_24;
  byte local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  if ((*(char *)(param_1 + 0x48f0) != '\0') && (*(char *)(param_2 + 2) == '\0')) {
    local_24 = 0x10;
    local_18 = StorPortExtendedFunction(0xf,param_1,param_2,local_28);
    if ((int)local_18 == 0) {
      return (ulonglong)local_20 % (ulonglong)*(byte *)(param_1 + 0x48f1);
    }
  }
  return local_18 & 0xffffffffffffff00;
}



===== CompleteScsiRequest @ 140001850 =====

void CompleteScsiRequest(longlong param_1,longlong *param_2,char param_3,char param_4)

{
  uint *puVar1;
  int *piVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  longlong lVar7;
  longlong lVar8;
  
  lVar8 = *param_2;
  if (*(char *)(lVar8 + 0x48) == '\x12') {
    if (*(char *)(lVar8 + 5) == '\x01') {
      if (((*(char *)(lVar8 + 0x49) == '\0') && (*(char *)(lVar8 + 0x4a) == '\0')) &&
         (*(char *)(lVar8 + 0x4d) == '\0')) {
        if (param_3 == '\0') {
          pbVar3 = (byte *)((ulonglong)*(byte *)(lVar8 + 6) + 0x6ab2 + param_1);
          *pbVar3 = *pbVar3 | 1;
        }
        if (*(char *)(lVar8 + 6) == -3) {
          *(undefined1 *)(param_1 + 0x6aa8) = 1;
        }
      }
    }
    else if ((((*(char *)(lVar8 + 5) == '\0') && (*(char *)(lVar8 + 0x49) == '\0')) &&
             (*(char *)(lVar8 + 0x4a) == '\0')) &&
            ((*(char *)(lVar8 + 0x4d) == '\0' && (param_3 == '\0')))) {
      if (((**(byte **)(lVar8 + 0x18) & 0x1f) == 0xd) && (*(char *)(param_1 + 0x1cc) != '\0')) {
        pbVar3 = (byte *)((ulonglong)*(byte *)(lVar8 + 6) + 0x6ab2 + param_1);
        *pbVar3 = *pbVar3 | 4;
      }
      else {
        puVar1 = (uint *)(param_1 + (ulonglong)(*(byte *)(lVar8 + 6) >> 5) * 4 + 0x6d90);
        *puVar1 = *puVar1 | 1 << (*(byte *)(lVar8 + 6) & 0x1f);
        *(undefined1 *)(param_1 + 0x642c) = 1;
        pbVar3 = (byte *)((ulonglong)*(byte *)(lVar8 + 6) + 0x6ab2 + param_1);
        *pbVar3 = *pbVar3 | 2;
      }
    }
  }
  if (*(char *)((longlong)param_2 + 0x56) != '\0') {
    lVar8 = ((ulonglong)*(byte *)(lVar8 + 6) + 0x23) * 0x40;
    LOCK();
    piVar2 = (int *)(lVar8 + 0x20 + param_1);
    iVar4 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar4 + -1 < 1) {
      *(undefined1 *)(lVar8 + 0x11 + param_1) = 1;
      *(undefined1 *)(param_1 + 0x48c8) = 1;
    }
  }
  uVar5 = *(uint *)(param_2 + 1);
  lVar8 = *(longlong *)(param_1 + 0x168);
  do {
    lVar7 = *param_2;
    if (((((char)param_2[3] == '\0') && (*(char *)((longlong)param_2 + 0x19) == '\0')) &&
        (param_3 == '\0')) &&
       ((uVar6 = *(uint *)(param_2 + 10), uVar6 != 0 && (*(uint *)(lVar7 + 0x10) != uVar6)))) {
      if (uVar6 < *(uint *)(lVar7 + 0x10)) {
        *(uint *)(lVar7 + 0x10) = uVar6;
      }
      *(undefined1 *)(lVar7 + 3) = 0x12;
    }
    else {
      MapSrbStatus(param_1,param_2,param_3,param_4,(undefined8 *)(lVar8 + (ulonglong)uVar5 * 0x12));
    }
    param_2 = (longlong *)param_2[0xc];
    StorPortNotification(0,param_1,lVar7);
  } while (param_2 != (longlong *)0x0);
  return;
}



===== MapSrbStatus @ 140001a00 =====

void MapSrbStatus(longlong param_1,longlong *param_2,undefined1 param_3,char param_4,
                 undefined8 *param_5)

{
  longlong lVar1;
  uint uVar2;
  
  lVar1 = *param_2;
  switch(param_3) {
  case 0:
    *(undefined1 *)(lVar1 + 3) = 1;
    return;
  case 1:
  case 2:
  case 3:
  case 4:
  case 0x19:
  case 0x2e:
    *(undefined1 *)(lVar1 + 3) = 6;
    *(char *)(lVar1 + 4) = param_4;
    return;
  default:
    *(undefined1 *)(lVar1 + 3) = 4;
    return;
  case 0xc:
  case 0x22:
  case 0x33:
    *(undefined1 *)(lVar1 + 3) = 8;
    return;
  case 0x18:
    *(undefined2 *)(lVar1 + 3) = 0x204;
    return;
  case 0x2d:
    break;
  case 0x2f:
    *(undefined2 *)(lVar1 + 3) = 0x1804;
    return;
  case 0x67:
    *(undefined1 *)(lVar1 + 3) = 5;
    *(undefined1 *)(param_1 + 0x646a) = 0;
    return;
  }
  *(undefined1 *)(lVar1 + 3) = 4;
  *(char *)(lVar1 + 4) = param_4;
  if (((*(char *)(param_1 + 0x88) == '\0') && (param_4 == '\x02')) &&
     (*(undefined8 **)(lVar1 + 0x20) != (undefined8 *)0x0)) {
    if ((*(uint *)(lVar1 + 0xc) & 0x20) == 0) {
      uVar2 = (uint)*(byte *)(lVar1 + 0xb);
      if (0x11 < *(byte *)(lVar1 + 0xb)) {
        uVar2 = 0x12;
      }
      MemFastMove(*(undefined8 **)(lVar1 + 0x20),param_5,uVar2);
      *(byte *)(lVar1 + 3) = *(byte *)(lVar1 + 3) | 0x80;
    }
    if (((*(byte *)((longlong)param_5 + 2) & 0xf) == 6) &&
       (*(char *)((longlong)param_5 + 0xc) == ')')) {
      StorPortNotification(7,param_1);
      StorPortNotification(7,param_1);
    }
  }
  return;
}



===== SetDeviceQueueDepths @ 140001bd0 =====

void SetDeviceQueueDepths(longlong param_1)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  byte *pbVar4;
  longlong lVar5;
  char cVar6;
  ulonglong uVar7;
  undefined1 *puVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  byte *pbVar12;
  uint local_res8;
  
  iVar2 = *(int *)(param_1 + 0x6d38);
  pbVar12 = (byte *)(param_1 + 0x6ab2);
  uVar9 = 0;
  iVar11 = 0;
  uVar10 = 0;
  lVar5 = 0xff;
  pbVar4 = pbVar12;
  do {
    bVar1 = *pbVar4;
    if (bVar1 != 0) {
      if ((bVar1 & 1) != 0) {
        uVar9 = uVar9 + 1;
        uVar10 = uVar10 + 1;
      }
      if ((bVar1 & 2) == 0) {
        if ((bVar1 & 4) != 0) {
          iVar11 = iVar11 + 1;
        }
      }
      else {
        uVar9 = uVar9 + 1;
      }
    }
    pbVar4 = pbVar4 + 1;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  if (uVar9 == 0) {
    uVar9 = 1;
  }
  if (uVar10 == 0) {
    uVar10 = 1;
  }
  if (*(int *)(param_1 + 0x894) != 0) {
    local_res8 = (uint)(*(int *)(param_1 + 0x890) + iVar11 * -4) / uVar10;
  }
  if (0xfe < local_res8) {
    local_res8 = 0xfe;
  }
  uVar7 = (ulonglong)(uint)(*(int *)(param_1 + 0x898) + iVar11 * -4) / (ulonglong)uVar9;
  if (0xfe < (uint)uVar7) {
    uVar7 = 0xfe;
  }
  if (*(char *)(param_1 + 0x6aa9) == '\0') {
    *(uint *)(param_1 + 0x6aac) = (uint)uVar7;
    cVar6 = '\0';
    pbVar4 = pbVar12;
    do {
      if ((*pbVar4 & 1) != 0) {
        if (*(int *)(param_1 + 0x894) == 0) {
          uVar9 = (uint)uVar7;
        }
        else {
          uVar9 = local_res8;
        }
        StorPortSetDeviceQueueDepth(param_1,1,cVar6,0,uVar9);
      }
      cVar6 = cVar6 + '\x01';
      pbVar4 = pbVar4 + 1;
    } while (cVar6 != -1);
  }
  else {
    if (*(char *)(param_1 + 0x6aa9) != '\x01') {
      return;
    }
    *(undefined1 *)(param_1 + 0x91) = 0;
    cVar6 = '\0';
    pbVar4 = pbVar12;
    do {
      if ((*pbVar4 & 1) != 0) {
        StorPortSetDeviceQueueDepth(param_1,1,cVar6,0,*(undefined4 *)(param_1 + 0x6aac));
      }
      cVar6 = cVar6 + '\x01';
      pbVar4 = pbVar4 + 1;
    } while (cVar6 != -1);
  }
  if (*(char *)(param_1 + 0x6ab0) == '\0') {
    *(char *)(param_1 + 0x6ab1) = (char)uVar7;
    cVar6 = '\0';
    do {
      uVar9 = (uint)uVar7;
      bVar1 = *pbVar12;
      if ((bVar1 & 2) != 0) {
        if (((iVar2 == 0) && (*(char *)(param_1 + 0x6469) != '\0')) ||
           (*(int *)(param_1 + 0x894) != 0)) {
          if ((char)bVar1 < '\0') {
            if (0x20 < uVar9) {
              uVar9 = 0x20;
            }
            uVar10 = uVar9;
          }
          else if ((((bVar1 & 0x40) != 0) || (uVar10 = 0x14, (bVar1 & 0x20) != 0)) &&
                  (uVar10 = uVar9, 0x40 < uVar9)) {
            uVar10 = 0x40;
          }
        }
        else {
          if (0x20 < uVar9) {
            uVar7 = 0x20;
          }
          uVar10 = (uint)uVar7;
        }
        cVar3 = StorPortSetDeviceQueueDepth(param_1,0,cVar6,0,uVar10);
        if (cVar3 != '\0') {
          pbVar12[0x100] = (byte)uVar7;
        }
        if (((*pbVar12 & 4) != 0) &&
           (cVar3 = StorPortSetDeviceQueueDepth(param_1,0,cVar6,0,4), cVar3 != '\0')) {
          pbVar12[0x100] = 4;
        }
      }
      cVar6 = cVar6 + '\x01';
      pbVar12 = pbVar12 + 1;
    } while (cVar6 != -1);
  }
  else if (*(char *)(param_1 + 0x6ab0) == '\x01') {
    *(undefined1 *)(param_1 + 0x91) = 0;
    puVar8 = (undefined1 *)(param_1 + 0x6bb2);
    cVar6 = '\0';
    do {
      if ((puVar8[-0x100] & 2) == 0) {
        if (((puVar8[-0x100] & 4) != 0) &&
           (cVar3 = StorPortSetDeviceQueueDepth(param_1,0,cVar6,0,4), cVar3 != '\0')) {
          *puVar8 = 4;
        }
      }
      else {
        cVar3 = StorPortSetDeviceQueueDepth(param_1,0,cVar6,0,*(undefined1 *)(param_1 + 0x6ab1));
        if (cVar3 != '\0') {
          *puVar8 = *(undefined1 *)(param_1 + 0x6ab1);
        }
      }
      cVar6 = cVar6 + '\x01';
      puVar8 = puVar8 + 1;
    } while (cVar6 != -1);
  }
  return;
}



===== CompleteDCMD @ 140001ea0 =====

void CompleteDCMD(int *param_1,longlong param_2,char param_3)

{
  byte *pbVar1;
  uint *puVar2;
  undefined8 uVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  byte bVar9;
  int local_res10 [2];
  
  uVar5 = *(uint *)(param_2 + 0x18);
  if (*(char *)(param_2 + 2) != '\0') {
    if ((uVar5 == 0x1040500) && (*(char *)(param_2 + 2) == '#')) {
      *(undefined1 *)((longlong)param_1 + 0x6421) = 1;
      return;
    }
    if (uVar5 == 0x2020000) {
      *(undefined1 *)((longlong)param_1 + 0x642d) = 0;
      uVar8 = 0;
      do {
        bVar9 = 0;
        do {
          if (((uint)param_1[uVar8 + 0x1b64] >> (bVar9 & 0x1f) & 1) != 0) {
            return;
          }
          bVar9 = bVar9 + 1;
        } while (bVar9 < 0x20);
        bVar9 = (char)uVar8 + 1;
        uVar8 = (ulonglong)bVar9;
      } while (bVar9 < 8);
      *(undefined1 *)(param_1 + 0x190b) = 0;
      return;
    }
    if (uVar5 == 0x300e101) {
      StorPortLogError(param_1,0,0xff,0xff,0xff,6,0x50);
      *(undefined1 *)((longlong)param_1 + 0x646a) = 0;
      return;
    }
    return;
  }
  if (uVar5 < 0x2010101) {
    if (uVar5 == 0x2010100) {
      if (param_3 != '\0') {
        param_1[0x1909] = 0;
        CompletePDquery((longlong)param_1);
        return;
      }
      iVar4 = 4;
      if (param_1[0x1909] != 2) {
        iVar4 = 0;
      }
      param_1[0x1909] = iVar4;
      return;
    }
    if (uVar5 == 0x1020100) {
      *(undefined1 *)(param_1 + 0x73) = *(undefined1 *)(*(longlong *)(param_1 + 0x56) + 0x19);
      *(byte *)((longlong)param_1 + 0x1cd) =
           ~(byte)(*(uint *)(*(longlong *)(param_1 + 0x56) + 0x20) >> 10) & 1;
      return;
    }
    if (uVar5 == 0x1040100) {
      puVar7 = *(undefined8 **)(param_1 + 0x56);
      uVar3 = puVar7[1];
      *(undefined8 *)(param_1 + 0x6e) = *puVar7;
      *(undefined8 *)(param_1 + 0x70) = uVar3;
      param_1[0x72] = *(int *)(puVar7 + 2);
      return;
    }
    if (uVar5 == 0x1040500) {
      puVar2 = *(uint **)(param_1 + 0x4a);
      param_1[0x6e] = *puVar2;
      if ((char)param_1[0x1fa] != '\0') {
        local_res10[0] = 0;
        MemFastMove((undefined8 *)local_res10,(undefined8 *)(puVar2 + 3),4);
        param_1[0x20b] = param_1[0x1e];
        param_1[0x20c] = local_res10[0];
        param_1[0x20d] = *puVar2;
        param_1[0x20e] = puVar2[2];
        ScsiPortWmiFireLogicalUnitEvent
                  (param_1,-1,0,0,(int *)&MegaSASWmiSetupDataGuid,0,0x10,param_1 + 0x1fb);
      }
      *(undefined1 *)((longlong)param_1 + 0x1d6) = 0;
      *(undefined1 *)((longlong)param_1 + 0x6421) = 1;
      if ((uint)param_1[0x72] <= *puVar2) {
        uVar5 = puVar2[2];
        if (0x8b < uVar5) {
          switch(uVar5) {
          case 0xfc:
          case 0x15a:
          case 0x15f:
          case 0x160:
            goto switchD_1400020d5_caseD_fc;
          default:
            goto LAB_140002313;
          case 0x152:
            goto switchD_1400020d5_caseD_152;
          case 0x17e:
            ProcessPerfMetricAEN((longlong)param_1,*(char *)((longlong)puVar2 + 0xaa) + -0x30);
            return;
          }
        }
        if (uVar5 < 0x8a) {
          if (uVar5 == 4) {
switchD_1400020d5_caseD_152:
            StorPortNotification(7,param_1);
          }
          else if (uVar5 != 0x51) {
            if (0x17 < uVar5 - 0x5b) {
              return;
            }
            if ((0xa00001U >> (uVar5 - 0x5b & 0x1f) & 1) == 0) {
              return;
            }
            if (param_1[0x1909] == 0) {
              param_1[0x1909] = 1;
              return;
            }
            return;
          }
        }
switchD_1400020d5_caseD_fc:
        StorPortNotification(7,param_1);
        return;
      }
    }
  }
  else if (uVar5 == 0x2020000) {
    *(undefined1 *)((longlong)param_1 + 0x642d) = 0;
    uVar8 = (ulonglong)*(byte *)(param_1 + 0x1b6c);
    if (*(char *)(*(longlong *)(param_1 + 0x52) + 0x191) == '\x02') {
      pbVar1 = (byte *)(uVar8 + 0x6ab2 + (longlong)param_1);
      *pbVar1 = *pbVar1 | 0x40;
    }
    else if (*(char *)(*(longlong *)(param_1 + 0x52) + 0x191) == '\x03') {
      pbVar1 = (byte *)(uVar8 + 0x6ab2 + (longlong)param_1);
      *pbVar1 = *pbVar1 | 0x80;
    }
    else {
      pbVar1 = (byte *)(uVar8 + 0x6ab2 + (longlong)param_1);
      *pbVar1 = *pbVar1 | 0x20;
    }
    uVar8 = 0;
    do {
      uVar5 = 0;
      do {
        if (((uint)param_1[uVar8 + 0x1b64] >> (uVar5 & 0x1f) & 1) != 0) {
          return;
        }
        bVar9 = (char)uVar5 + 1;
        uVar5 = (uint)bVar9;
      } while (bVar9 < 0x20);
      bVar9 = (char)uVar8 + 1;
      uVar8 = (ulonglong)bVar9;
    } while (bVar9 < 8);
    *(undefined1 *)(param_1 + 0x190b) = 0;
  }
  else if (uVar5 == 0x300e101) {
    iVar4 = param_1[0x191b];
    *(undefined1 *)((longlong)param_1 + 0x646b) = 0;
    lVar6 = MegaSASValidateAndProcessMapInfo(param_1);
    if ((char)lVar6 == '\0') {
      StorPortLogError(param_1,0,0xff,0xff,0xff,6,0x51);
      *(undefined1 *)((longlong)param_1 + 0x646a) = 0;
      return;
    }
    if (iVar4 != 0) {
      param_1[0x191b] = param_1[0x191b] + 1;
      if (param_3 == '\0') {
        *(undefined1 *)((longlong)param_1 + 0x6422) = 1;
        return;
      }
      puVar7 = SetupDCMD((longlong)param_1,0x300e101);
                    /* WARNING: Could not recover jumptable at 0x000140002274. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*(longlong *)(param_1 + 0x5e) + 0x58))(param_1,puVar7);
      return;
    }
  }
LAB_140002313:
  return;
}



===== CompleteIoctlRequest @ 1400023c0 =====

void CompleteIoctlRequest(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *param_2;
  lVar2 = *(longlong *)(lVar1 + 0x18);
  if (*(char *)((longlong)param_2 + 0x102) == '\0') {
    if (*(int *)(lVar2 + 0x34) == 0x1020200) {
      if (((*(char *)(lVar2 + 0xd5) != *(char *)(param_1 + 0x1cc)) &&
          (*(char *)(param_1 + 0x1cc) = *(char *)(lVar2 + 0xd5), *(char *)(param_1 + 0x1d4) != '\0')
          ) && (*(int *)(param_1 + 0x6424) == 0)) {
        *(undefined4 *)(param_1 + 0x6424) = 1;
      }
      *(byte *)(param_1 + 0x1cd) = ~(byte)(*(uint *)(lVar2 + 0xdc) >> 10) & 1;
    }
    else if (*(int *)(lVar2 + 0x34) == 0x1170200) {
      ProcessPerfMetricRequest(param_1,(uint *)(lVar2 + 0xbc),*(int *)(lVar1 + 0x10) - 0xbd);
    }
  }
  MemFastMove((undefined8 *)(lVar2 + 0x1c),param_2 + 0x20,0x18);
  *(undefined1 *)(lVar1 + 3) = 1;
  StorPortNotification(0,param_1,lVar1);
  return;
}



===== CompletePDquery @ 1400024a0 =====

void CompletePDquery(longlong param_1)

{
  ushort uVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x118);
  MemFastZero((undefined8 *)(param_1 + 0x2d9),0x100);
  MemFastZero((undefined8 *)(param_1 + 0x4d9),0x100);
  uVar4 = 0;
  if (*(int *)(lVar2 + 4) != 0) {
    do {
      uVar1 = *(ushort *)(lVar2 + 8 + uVar4 * 0x18);
      if (uVar1 < 0x100) {
        if (*(char *)(lVar2 + 0xe + uVar4 * 0x18) == '\0') {
          *(undefined1 *)((ulonglong)uVar1 + 0x6d9 + param_1) = 1;
        }
        *(undefined1 *)((ulonglong)uVar1 + 0x2d9 + param_1) = 1;
        *(undefined1 *)((ulonglong)uVar1 + 0x4d9 + param_1) = 1;
      }
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 < *(uint *)(lVar2 + 4));
  }
  MemFastMove((undefined8 *)(param_1 + 0x1d9),(undefined8 *)(param_1 + 0x2d9),0x100);
  MemFastMove((undefined8 *)(param_1 + 0x3d9),(undefined8 *)(param_1 + 0x4d9),0x100);
  MemFastMove((undefined8 *)(param_1 + 0x5d9),(undefined8 *)(param_1 + 0x6d9),0x100);
  *(undefined1 *)(param_1 + 0x1d4) = 1;
  StorPortNotification(7,param_1);
  return;
}



===== IssueDCMD @ 1400025a0 =====

void IssueDCMD(longlong param_1,uint param_2)

{
  undefined8 *puVar1;
  
  puVar1 = SetupDCMD(param_1,param_2);
                    /* WARNING: Could not recover jumptable at 0x0001400025c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(longlong *)(param_1 + 0x178) + 0x58))(param_1,puVar1);
  return;
}



===== PrepareAbortFrame @ 1400025d0 =====

void PrepareAbortFrame(longlong param_1,int param_2)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  longlong lVar3;
  
  puVar2 = *(undefined8 **)(param_1 + 200);
  lVar3 = *(longlong *)(param_1 + 200 + (ulonglong)(param_2 - 1) * 8);
  MemFastZero(puVar2,0x600);
  puVar2[2] = *(undefined8 *)(param_1 + 0xf0);
  *(int *)(puVar2 + 1) = *(int *)(param_1 + 0x88c) + -1;
  *(undefined1 *)(puVar2 + 0x20) = 6;
  uVar1 = *(undefined4 *)(lVar3 + 8);
  *(ushort *)(puVar2 + 0x22) = *(ushort *)(puVar2 + 0x22) | 1;
  *(undefined4 *)(puVar2 + 0x23) = uVar1;
  *(undefined1 *)((longlong)puVar2 + 0x102) = 0xff;
  *(undefined4 *)(puVar2 + 0x21) = *(undefined4 *)(puVar2 + 1);
  puVar2[0x24] = *(undefined8 *)(lVar3 + 0x10);
  *(undefined4 *)(param_1 + 0x6458) = 180000000;
  return;
}



===== SendAndWaitDCMD @ 140002670 =====

bool SendAndWaitDCMD(int *param_1,uint param_2)

{
  bool bVar1;
  undefined8 *puVar2;
  
  puVar2 = SetupDCMD((longlong)param_1,param_2);
  if ((*(int *)(puVar2 + 0x23) != 0x1101000) && (*(int *)(puVar2 + 0x23) != 0x1060000)) {
    LOCK();
    param_1[0x69] = param_1[0x69] + 1;
    UNLOCK();
  }
  *(ushort *)(puVar2 + 0x22) = *(ushort *)(puVar2 + 0x22) | 1;
  *(undefined2 *)((longlong)puVar2 + 0x112) = 0xb4;
  (**(code **)(*(longlong *)(param_1 + 0x5e) + 0x58))(param_1,puVar2);
  bVar1 = WaitForCmdStatus((longlong)param_1,(longlong)puVar2);
  if (bVar1) {
    CompleteDCMD(param_1,(longlong)(puVar2 + 0x20),'\x01');
    return true;
  }
  return false;
}



===== SetupDCMD @ 140002710 =====

undefined8 * SetupDCMD(longlong param_1,uint param_2)

{
  char cVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined4 uVar6;
  int iVar7;
  undefined1 uVar8;
  undefined8 local_res8;
  
  if (param_2 == 0x2010100) {
    iVar7 = 4;
  }
  else if (param_2 == 0x300e101) {
    iVar7 = 3;
  }
  else if (param_2 == 0x1040500) {
    iVar7 = 2;
  }
  else {
    iVar7 = 1;
    if (param_2 == 0x2020000) {
      iVar7 = 5;
    }
  }
  puVar3 = *(undefined8 **)(param_1 + 200 + (ulonglong)(iVar7 - 1U) * 8);
  MemFastZero(puVar3,0x600);
  puVar3[2] = *(undefined8 *)(param_1 + 0xf0 + (ulonglong)(iVar7 - 1U) * 8);
  *(int *)(puVar3 + 1) = *(int *)(param_1 + 0x88c) - iVar7;
  *(undefined1 *)(puVar3 + 0x20) = 5;
  *(uint *)(puVar3 + 0x23) = param_2;
  *(undefined1 *)((longlong)puVar3 + 0x102) = 0xff;
  *(undefined4 *)(puVar3 + 0x21) = *(undefined4 *)(puVar3 + 1);
  if (param_2 < 0x1101001) {
    if (param_2 == 0x1101000) {
      *(undefined1 *)((longlong)puVar3 + 0x11c) = 3;
      goto LAB_140002a27;
    }
    if (param_2 == 0x1010000) {
      local_res8 = *(undefined8 *)(param_1 + 0x140);
      iVar7 = 0x800;
      MemFastZero(*(undefined8 **)(param_1 + 0x138),0x800);
      *(undefined1 *)((longlong)puVar3 + 0x11c) = 1;
    }
    else if (param_2 == 0x1040500) {
      local_res8 = *(undefined8 *)(param_1 + 0x130);
      iVar7 = 0x100;
      MemFastZero(*(undefined8 **)(param_1 + 0x128),0x100);
      *(int *)(param_1 + 0x1b8) = *(int *)(param_1 + 0x1b8) + 1;
      uVar6 = *(undefined4 *)(param_1 + 0x1b8);
      if (*(char *)(param_1 + 0x1d5) != '\0') {
        uVar6 = *(undefined4 *)(param_1 + 0x1c4);
      }
      *(undefined4 *)((longlong)puVar3 + 0x11c) = uVar6;
      *(undefined4 *)(puVar3 + 0x24) = *(undefined4 *)(param_1 + 0x83c);
      *(undefined1 *)(param_1 + 0x1d6) = 1;
    }
    else {
      if (param_2 == 0x1050000) {
        *(undefined1 *)((longlong)puVar3 + 0x11c) = 1;
        goto LAB_140002a27;
      }
      if (param_2 == 0x1060000) goto LAB_140002a27;
LAB_1400028ba:
      local_res8 = *(undefined8 *)(param_1 + 0x160);
      iVar7 = 0x800;
      MemFastZero(*(undefined8 **)(param_1 + 0x158),0x800);
    }
  }
  else if (param_2 == 0x2010100) {
    local_res8 = *(undefined8 *)(param_1 + 0x120);
    iVar7 = 0x1808;
    MemFastZero(*(undefined8 **)(param_1 + 0x118),0x1808);
    *(undefined1 *)((longlong)puVar3 + 0x11c) = 5;
  }
  else if (param_2 == 0x2020000) {
    local_res8 = *(undefined8 *)(param_1 + 0x150);
    iVar7 = 0x200;
    MemFastZero(*(undefined8 **)(param_1 + 0x148),0x200);
    *(undefined1 *)((longlong)puVar3 + 0x11c) = *(undefined1 *)(param_1 + 0x6db0);
    *(undefined1 *)(param_1 + 0x642d) = 1;
  }
  else {
    if (param_2 != 0x300e101) goto LAB_1400028ba;
    uVar2 = *(uint *)(param_1 + 0x646c);
    uVar8 = 0;
    if (uVar2 == 0) {
      local_res8 = *(undefined8 *)(param_1 + 0x6480);
      MemFastZero(*(undefined8 **)(param_1 + 0x6470),4);
    }
    else {
      puVar4 = *(undefined8 **)(param_1 + 0x6470 + (ulonglong)(uVar2 & 1) * 8);
      lVar5 = *(longlong *)(param_1 + 0x6d78 + (ulonglong)(uVar2 - 1 & 1) * 8);
      MemFastZero(puVar4,*(uint *)(param_1 + 0x6d68));
      MegaSASPrepareSyncInfo(param_1,lVar5,(undefined1 *)puVar4);
      local_res8 = *(undefined8 *)(param_1 + 0x6480 + (ulonglong)(uVar2 & 1) * 8);
      uVar8 = *(undefined1 *)(lVar5 + 0x20);
    }
    iVar7 = *(int *)(param_1 + 28000);
    *(undefined1 *)((longlong)puVar3 + 0x11c) = uVar8;
    *(bool *)((longlong)puVar3 + 0x11d) = uVar2 != 0;
    *(undefined1 *)(param_1 + 0x646b) = 1;
    if (iVar7 == 0) goto LAB_140002a27;
  }
  cVar1 = *(char *)(param_1 + 0x1d3);
  *(int *)(puVar3 + 0x25) = (int)local_res8;
  if (cVar1 == '\0') {
    *(int *)((longlong)puVar3 + 300) = iVar7;
  }
  else {
    *(undefined4 *)((longlong)puVar3 + 300) = local_res8._4_4_;
    *(int *)(puVar3 + 0x26) = iVar7;
    *(ushort *)(puVar3 + 0x22) = *(ushort *)(puVar3 + 0x22) | 2;
  }
  *(undefined1 *)((longlong)puVar3 + 0x107) = 1;
  *(int *)((longlong)puVar3 + 0x114) = iVar7;
LAB_140002a27:
  *(undefined8 **)(*(longlong *)(param_1 + 0x180) + (ulonglong)*(uint *)(puVar3 + 1) * 8) = puVar3;
  return puVar3;
}



===== WDTSetupAndSendDCMD @ 140002a50 =====

void WDTSetupAndSendDCMD(longlong param_1,uint param_2)

{
  undefined8 *puVar1;
  
  puVar1 = SetupDCMD(param_1,param_2);
  if ((*(int *)(puVar1 + 0x23) != 0x1101000) && (*(int *)(puVar1 + 0x23) != 0x1060000)) {
    LOCK();
    *(int *)(param_1 + 0x1a4) = *(int *)(param_1 + 0x1a4) + 1;
    UNLOCK();
  }
  *(ushort *)(puVar1 + 0x22) = *(ushort *)(puVar1 + 0x22) | 1;
  *(undefined2 *)((longlong)puVar1 + 0x112) = 0xb4;
                    /* WARNING: Could not recover jumptable at 0x000140002a9f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(longlong *)(param_1 + 0x178) + 0x58))(param_1);
  return;
}



===== WaitForCmdStatus @ 140002ab0 =====

bool WaitForCmdStatus(longlong param_1,longlong param_2)

{
  char cVar1;
  uint uVar2;
  
  cVar1 = *(char *)(param_2 + 0x102);
  while( true ) {
    if (cVar1 != -1) {
      return *(char *)(param_2 + 0x102) == '\0';
    }
    uVar2 = (**(code **)(*(longlong *)(param_1 + 0x178) + 0x30))(*(undefined8 *)(param_1 + 0x80));
    *(uint *)(param_1 + 0x1ac) = uVar2;
    if (((uVar2 & 0xf0000000) == 0xf0000000) || (*(int *)(param_1 + 0x6458) < 1)) break;
    StorPortStallExecution(1000);
    *(int *)(param_1 + 0x6458) = *(int *)(param_1 + 0x6458) + -1000;
    cVar1 = *(char *)(param_2 + 0x102);
  }
  return false;
}



===== MR_GetPhyParams @ 140002b40 =====

undefined8
MR_GetPhyParams(longlong param_1,uint param_2,ulonglong param_3,ushort param_4,longlong *param_5,
               undefined2 *param_6,longlong param_7,char param_8,longlong param_9)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong lVar6;
  byte bVar7;
  uint uVar8;
  ulonglong uVar9;
  longlong lVar10;
  longlong lVar11;
  byte local_res10 [8];
  
  lVar10 = (ulonglong)param_2 * 0x9e0;
  bVar7 = *(byte *)(param_1 + 0x493c + lVar10);
  bVar1 = *(byte *)(param_1 + 0x493b + lVar10);
  bVar2 = *(byte *)(param_1 + 0x4944 + lVar10);
  if (((bVar7 == 0) || (bVar1 == 0)) || (bVar2 == 0)) {
    uVar5 = 0;
  }
  else {
    uVar4 = param_3 / bVar7;
    if (*(char *)(param_1 + 0x4939 + lVar10) == '\x06') {
      uVar8 = ((uint)bVar1 - (int)(uVar4 % (ulonglong)bVar1)) + (int)(param_3 % (ulonglong)bVar7);
      uVar9 = (ulonglong)uVar8;
      if (bVar1 <= uVar8) {
        uVar9 = (ulonglong)(uVar8 - bVar1);
      }
    }
    else {
      uVar9 = (ulonglong)*(byte *)(param_3 % (ulonglong)bVar2 + lVar10 + 0x49a8 + param_1);
    }
    bVar7 = (byte)uVar9;
    if (*(char *)(param_1 + 0x4938 + lVar10) == '\x01') {
      local_res10[0] = 0;
      *param_5 = uVar4 << (*(byte *)(param_1 + 0x493a + lVar10) & 0x3f);
    }
    else {
      uVar5 = MR_GetSpanBlock(param_1,(ulonglong)param_2,uVar4,param_5,local_res10);
      if ((char)uVar5 == '\0') {
        return uVar5;
      }
    }
    lVar11 = (ulonglong)local_res10[0] * 0x128 + lVar10;
    lVar6 = (ulonglong)*(ushort *)(lVar11 + 0x49e0 + param_1) * 0x20;
    uVar3 = *(ushort *)(param_1 + 0x928 + ((uVar9 & 0xff) + lVar6) * 2);
    if (uVar3 == 0xffff) {
      *param_6 = 0xffff;
      bVar1 = *(byte *)(param_1 + 0x4939 + lVar10);
      if ((bVar1 < 5) || ((param_8 != '\0' && (*(char *)(param_1 + 0x4945 + lVar10) == '\0')))) {
        if (bVar1 == 1) {
          bVar7 = bVar7 + 1;
          uVar3 = *(ushort *)(param_1 + 0x928 + ((ulonglong)bVar7 + lVar6) * 2);
          if (uVar3 != 0xffff) {
            *param_6 = *(undefined2 *)(param_1 + 0x28 + (ulonglong)uVar3 * 8);
          }
        }
      }
      else {
        *(undefined1 *)(param_7 + 4) = 3;
      }
    }
    else {
      *param_6 = *(undefined2 *)(param_1 + 0x28 + (ulonglong)uVar3 * 8);
    }
    *param_5 = *param_5 + *(longlong *)(lVar11 + 0x49d0 + param_1) + (ulonglong)param_4;
    *(byte *)(param_7 + 0x1c) = local_res10[0] << 5 | bVar7;
    *(byte *)(param_9 + 0x92) = bVar7;
    *(byte *)(param_9 + 0x93) = local_res10[0];
    uVar5 = CONCAT71((int7)((ulonglong)param_9 >> 8),1);
  }
  return uVar5;
}



===== MR_GetSpanBlock @ 140002d30 =====

ulonglong MR_GetSpanBlock(longlong param_1,ulonglong param_2,ulonglong param_3,longlong *param_4,
                         byte *param_5)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong *puVar3;
  byte bVar4;
  ulonglong *puVar5;
  uint uVar6;
  ulonglong uVar7;
  longlong lVar8;
  
  uVar2 = param_2 & 0xffffffff;
  bVar4 = 0;
  lVar8 = uVar2 * 0x9e0 + param_1;
  if (*(byte *)(lVar8 + 0x4938) != 0) {
    puVar5 = (ulonglong *)(lVar8 + 0x49f0);
    do {
      uVar6 = 0;
      if ((uint)puVar5[-1] != 0) {
        puVar3 = puVar5;
        do {
          uVar7 = (ulonglong)(uint)puVar3[3];
          if ((uint)puVar3[3] == 0) goto LAB_140002dc2;
          if (((*puVar3 <= param_3) && (param_3 <= puVar3[1])) &&
             (uVar1 = param_3 - *puVar3, uVar2 = uVar1 / uVar7, uVar1 % uVar7 == 0)) {
            *param_4 = (param_3 - *puVar3) / uVar7 + puVar3[2] << (*(byte *)(lVar8 + 0x493a) & 0x3f)
            ;
            *param_5 = bVar4;
            return CONCAT71((int7)((ulonglong)param_5 >> 8),1);
          }
          uVar6 = uVar6 + 1;
          puVar3 = puVar3 + 4;
        } while (uVar6 < (uint)puVar5[-1]);
      }
      bVar4 = bVar4 + 1;
      puVar5 = puVar5 + 0x25;
    } while (bVar4 < *(byte *)(lVar8 + 0x4938));
  }
LAB_140002dc2:
  return uVar2 & 0xffffffffffffff00;
}



===== MR_PopulateDrvRaidMap @ 140002e10 =====

void MR_PopulateDrvRaidMap(longlong param_1)

{
  undefined8 *puVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  longlong lVar8;
  undefined8 *puVar9;
  byte bVar10;
  
  uVar5 = (ulonglong)(*(uint *)(param_1 + 0x646c) & 1);
  puVar1 = *(undefined8 **)(param_1 + 0x6d78 + uVar5 * 8);
  if (*(char *)(param_1 + 0x6d70) != '\0') {
    MemFastMove(puVar1,*(undefined8 **)(param_1 + 0x6470 + uVar5 * 8),*(uint *)(param_1 + 28000));
    *(undefined4 *)puVar1 = 0xa2928;
    return;
  }
  puVar2 = *(undefined4 **)(param_1 + 0x6470 + uVar5 * 8);
  MemFastZero(puVar1,*(uint *)(param_1 + 0x6d6c));
  *(undefined4 *)puVar1 = *puVar2;
  *(undefined2 *)(puVar1 + 4) = *(undefined2 *)(puVar2 + 6);
  lVar8 = 0x80;
  *(undefined1 *)(puVar1 + 3) = *(undefined1 *)(puVar2 + 0x28);
  puVar7 = puVar1 + 0x105;
  do {
    *(undefined1 *)puVar7 =
         *(undefined1 *)((longlong)puVar2 + (0x20 - (longlong)(puVar1 + 0x105)) + (longlong)puVar7);
    puVar7 = (undefined8 *)((longlong)puVar7 + 1);
    lVar8 = lVar8 + -1;
  } while (lVar8 != 0);
  puVar7 = puVar1 + 0x115;
  for (lVar8 = 0x7f; lVar8 != 0; lVar8 = lVar8 + -1) {
    *(undefined1 *)puVar7 = 0xff;
    puVar7 = (undefined8 *)((longlong)puVar7 + 1);
  }
  uVar5 = 0;
  if (*(short *)(puVar1 + 4) != 0) {
    do {
      lVar8 = 0x13;
      puVar7 = (undefined8 *)(puVar2 + uVar5 * 0x278 + 0xa2a);
      puVar4 = puVar1 + uVar5 * 0x13c + 0x925;
      do {
        puVar9 = puVar4;
        puVar6 = puVar7;
        uVar3 = puVar6[1];
        *puVar9 = *puVar6;
        puVar9[1] = uVar3;
        uVar3 = puVar6[3];
        puVar9[2] = puVar6[2];
        puVar9[3] = uVar3;
        uVar3 = puVar6[5];
        puVar9[4] = puVar6[4];
        puVar9[5] = uVar3;
        uVar3 = puVar6[7];
        puVar9[6] = puVar6[6];
        puVar9[7] = uVar3;
        uVar3 = puVar6[9];
        puVar9[8] = puVar6[8];
        puVar9[9] = uVar3;
        uVar3 = puVar6[0xb];
        puVar9[10] = puVar6[10];
        puVar9[0xb] = uVar3;
        uVar3 = puVar6[0xd];
        puVar9[0xc] = puVar6[0xc];
        puVar9[0xd] = uVar3;
        uVar3 = puVar6[0xf];
        puVar9[0xe] = puVar6[0xe];
        puVar9[0xf] = uVar3;
        lVar8 = lVar8 + -1;
        puVar7 = puVar6 + 0x10;
        puVar4 = puVar9 + 0x10;
      } while (lVar8 != 0);
      uVar3 = puVar6[0x11];
      bVar10 = (char)uVar5 + 1;
      uVar5 = (ulonglong)bVar10;
      puVar9[0x10] = puVar6[0x10];
      puVar9[0x11] = uVar3;
      uVar3 = puVar6[0x13];
      puVar9[0x12] = puVar6[0x12];
      puVar9[0x13] = uVar3;
      uVar3 = puVar6[0x15];
      puVar9[0x14] = puVar6[0x14];
      puVar9[0x15] = uVar3;
      uVar3 = puVar6[0x17];
      puVar9[0x16] = puVar6[0x16];
      puVar9[0x17] = uVar3;
      uVar3 = puVar6[0x19];
      puVar9[0x18] = puVar6[0x18];
      puVar9[0x19] = uVar3;
      uVar3 = puVar6[0x1b];
      puVar9[0x1a] = puVar6[0x1a];
      puVar9[0x1b] = uVar3;
    } while ((ushort)bVar10 < *(ushort *)(puVar1 + 4));
  }
  MemFastMove(puVar1 + 0x125,(undefined8 *)(puVar2 + 0x2a),0x2000);
  MemFastMove(puVar1 + 5,(undefined8 *)(puVar2 + 0x82a),0x800);
  return;
}



===== MR_Spanset_GetPhyParams @ 140002fd0 =====

ulonglong MR_Spanset_GetPhyParams
                    (longlong param_1,uint param_2,ulonglong param_3,ushort param_4,
                    longlong *param_5,undefined2 *param_6,longlong param_7,char param_8,
                    longlong param_9,longlong param_10)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong lVar8;
  byte bVar9;
  uint uVar10;
  ulonglong uVar11;
  longlong lVar12;
  
  lVar8 = (ulonglong)param_2 * 0x9e0;
  bVar1 = *(byte *)(param_10 + 0x90);
  if (*(char *)(lVar8 + 0x4939 + param_1) == '\x06') {
    bVar9 = *(byte *)((ulonglong)bVar1 * 0x128 + lVar8 + 0x49e2 + param_1);
    iVar5 = get_arm_from_strip(param_9,param_2,param_3,param_1);
    uVar6 = *(ulonglong *)(param_10 + 0x88) / (ulonglong)bVar9;
    uVar10 = iVar5 + ((uint)bVar9 - (int)(*(ulonglong *)(param_10 + 0x88) % (ulonglong)bVar9));
    if (bVar9 <= uVar10) {
      uVar10 = uVar10 - bVar9;
    }
    uVar11 = (ulonglong)uVar10;
  }
  else {
    uVar10 = get_arm_from_strip(param_9,param_2,param_3,param_1);
    cVar2 = *(char *)(lVar8 + 0x4939 + param_1);
    if (cVar2 == '\0') {
LAB_14000308e:
      bVar9 = *(byte *)((ulonglong)bVar1 * 0x128 + lVar8 + 0x49e2 + param_1);
      uVar6 = 0;
      if (bVar9 == 0) goto LAB_140003199;
      uVar10 = (uint)(param_3 % (ulonglong)bVar9);
LAB_1400030b6:
      uVar10 = uVar10 * 2;
      uVar6 = (ulonglong)uVar10;
    }
    else {
      if (cVar2 == '\x01') goto LAB_1400030b6;
      uVar6 = 0;
      if ((byte)(cVar2 - 5U) < 2) goto LAB_14000308e;
    }
    uVar11 = (ulonglong)uVar10 & 0xff;
  }
  bVar9 = (byte)uVar11;
  if (bVar9 != 0xff) {
    lVar12 = (ulonglong)bVar1 * 0x128 + lVar8;
    lVar7 = (ulonglong)*(ushort *)(lVar12 + 0x49e0 + param_1) * 0x20;
    uVar4 = *(ushort *)(param_1 + 0x928 + ((uVar11 & 0xff) + lVar7) * 2);
    if (uVar4 == 0xffff) {
      *param_6 = 0xffff;
      bVar3 = *(byte *)(lVar8 + 0x4939 + param_1);
      if ((bVar3 < 5) || ((param_8 != '\0' && (*(char *)(lVar8 + 0x4945 + param_1) == '\0')))) {
        if (bVar3 == 1) {
          bVar9 = bVar9 + 1;
          uVar4 = *(ushort *)(param_1 + 0x928 + ((ulonglong)bVar9 + lVar7) * 2);
          if (uVar4 != 0xffff) {
            *param_6 = *(undefined2 *)(param_1 + 0x28 + (ulonglong)uVar4 * 8);
          }
        }
      }
      else {
        *(undefined1 *)(param_7 + 4) = 3;
      }
    }
    else {
      *param_6 = *(undefined2 *)(param_1 + 0x28 + (ulonglong)uVar4 * 8);
    }
    *param_5 = *param_5 + *(longlong *)(lVar12 + 0x49d0 + param_1) + (ulonglong)param_4;
    *(byte *)(param_7 + 0x1c) = bVar1 << 5 | bVar9;
    *(byte *)(param_10 + 0x92) = bVar9;
    *(byte *)(param_10 + 0x93) = bVar1;
    return 1;
  }
LAB_140003199:
  return uVar6 & 0xffffffffffffff00;
}



===== MR_Spanset_GetSpanBlock @ 1400031c0 =====

ulonglong MR_Spanset_GetSpanBlock
                    (longlong param_1,longlong param_2,uint param_3,ulonglong param_4,
                    longlong *param_5,char *param_6,undefined1 *param_7)

{
  longlong lVar1;
  byte bVar2;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  longlong lVar6;
  byte bVar7;
  ulonglong uVar8;
  longlong lVar9;
  ulonglong uVar10;
  ulonglong *puVar11;
  
  uVar10 = (ulonglong)param_3;
  uVar5 = 0;
  lVar1 = uVar10 * 0x9e0 + param_2;
  lVar6 = 0;
  puVar11 = (ulonglong *)(*(longlong *)(param_1 + 0x6498) + 0x38 + uVar10 * 0x2c0);
  do {
    if ((int)puVar11[2] == 0) {
      return 0xff;
    }
    if (param_4 <= *puVar11) {
      bVar2 = *(byte *)(lVar1 + 0x4938);
      uVar8 = 0;
      if (bVar2 != 0) {
        do {
          if (uVar5 + 1 <= *(uint *)(uVar8 * 0x128 + uVar10 * 0x9e0 + 0x49e8 + param_2)) {
            lVar9 = (uVar10 * 0x4f + lVar6) * 0x20 + uVar8 * 0x128 + param_2;
            uVar3 = *(uint *)(lVar9 + 0x4a08);
            if (uVar3 == 0) {
              *param_7 = 1;
              return 0xff;
            }
            uVar4 = *(ulonglong *)(lVar9 + 0x49f0);
            if (((uVar4 <= param_4) && (param_4 <= *(ulonglong *)(lVar9 + 0x49f8))) &&
               ((param_4 - uVar4) % (ulonglong)uVar3 == 0)) {
              *param_5 = (param_4 - uVar4) / (ulonglong)uVar3 + *(longlong *)(lVar9 + 0x4a00) <<
                         (*(byte *)(lVar1 + 0x493a) & 0x3f);
              *param_6 = (char)uVar8;
              return uVar8;
            }
          }
          bVar7 = (char)uVar8 + 1;
          uVar8 = (ulonglong)bVar7;
        } while (bVar7 < bVar2);
      }
    }
    uVar5 = uVar5 + 1;
    lVar6 = lVar6 + 1;
    puVar11 = puVar11 + 0xb;
    if (7 < uVar5) {
      return 0xff;
    }
  } while( true );
}



===== MR_ldBlockSizeGet @ 140003310 =====

int MR_ldBlockSizeGet(ulonglong param_1,longlong param_2,longlong param_3)

{
  byte bVar1;
  int iVar2;
  
  if ((*(char *)(param_3 + 0x88) != '\0') ||
     (bVar1 = *(byte *)((param_1 & 0xffffffff) + 0x828 + param_2),
     *(ushort *)(param_3 + 0x6d88) <= (ushort)bVar1)) {
    return 0x200;
  }
  iVar2 = *(int *)((ulonglong)bVar1 * 0x9e0 + 0x4958 + param_2);
  if (iVar2 == 0) {
    iVar2 = 0x200;
  }
  return iVar2;
}



===== MegaSASBuildRaidContext @ 140003350 =====

ulonglong MegaSASBuildRaidContext
                    (int *param_1,longlong param_2,ulonglong param_3,uint param_4,uint param_5,
                    char param_6,char param_7,longlong *param_8,longlong param_9,short *param_10,
                    char *param_11,undefined1 *param_12,longlong param_13)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  undefined1 uVar4;
  ushort uVar5;
  undefined1 *puVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  longlong lVar9;
  char *pcVar10;
  uint uVar11;
  char cVar12;
  ulonglong uVar13;
  char cVar14;
  longlong lVar15;
  char cVar16;
  ulonglong uVar17;
  longlong lVar18;
  ushort uVar19;
  byte bVar20;
  uint uVar21;
  uint local_res10 [2];
  char local_78 [4];
  undefined4 local_74;
  uint local_70;
  ulonglong local_68;
  uint local_60;
  ulonglong local_58;
  ulonglong local_50;
  ulonglong local_48;
  
  local_res10[0] = local_res10[0] & 0xffffff00;
  local_74 = (undefined4)CONCAT71((int7)(param_3 >> 8),0xff);
  *(undefined2 *)(param_13 + 0x90) = 0xff;
  bVar1 = *(byte *)((ulonglong)param_5 + 0x828 + param_2);
  puVar6 = (undefined1 *)(ulonglong)bVar1;
  if ((uint)*(ushort *)(param_1 + 0x1b62) <= (uint)bVar1) {
    *param_12 = 1;
    puVar6 = param_12;
LAB_1400033b8:
    return (ulonglong)puVar6 & 0xffffffffffffff00;
  }
  lVar15 = (longlong)puVar6 * 0x9e0;
  *param_12 = 0;
  if (*(char *)(lVar15 + 0x493c + param_2) == '\0') {
    if ((*(char *)(lVar15 + 0x49e3 + param_2) == '\0') || (*param_1 == 0)) goto LAB_1400033b8;
    *(undefined1 *)(param_13 + 0x91) = 1;
  }
  bVar2 = *(byte *)(lVar15 + 0x493a + param_2);
  local_70 = 1 << (bVar2 & 0x1f);
  uVar13 = param_3 >> (bVar2 & 0x3f);
  uVar17 = (param_3 - 1) + (ulonglong)param_4;
  uVar19 = (short)local_70 - 1;
  local_60 = (uint)bVar2;
  uVar5 = (ushort)uVar17 & uVar19;
  uVar17 = uVar17 >> (bVar2 & 0x3f);
  cVar16 = (char)uVar17;
  cVar12 = (char)uVar13;
  uVar19 = uVar19 & (ushort)param_3;
  uVar21 = (uint)bVar1;
  local_68 = uVar13;
  local_48 = uVar17;
  if (*(char *)(param_13 + 0x91) == '\0') {
    local_50 = (ulonglong)*(byte *)(lVar15 + 0x493c + param_2);
    uVar7 = uVar13 / local_50;
    local_50 = uVar17 / local_50;
    local_58 = uVar7;
  }
  else {
    uVar7 = get_row_from_strip((longlong)param_1,(uint)bVar1,uVar13,param_2);
    local_58 = uVar7;
    uVar8 = get_row_from_strip((longlong)param_1,uVar21,uVar17,param_2);
    if ((uVar7 == 0xffffffffffffffff) || (uVar8 == 0xffffffffffffffff)) goto LAB_1400039aa;
    local_50 = uVar8;
    if (*(char *)(lVar15 + 0x4938 + param_2) == '\x01') {
      uVar17 = uVar17 & 0xffffffffffffff00;
      local_74 = (undefined4)uVar17;
      *param_8 = uVar7 << ((byte)local_60 & 0x3f);
    }
    else {
      uVar8 = MR_Spanset_GetSpanBlock
                        ((longlong)param_1,param_2,(uint)bVar1,uVar7,param_8,local_78,
                         (undefined1 *)local_res10);
      local_74 = (undefined4)uVar8;
      uVar17 = uVar8 & 0xffffffff;
      if (((char)local_res10[0] == '\x01') || ((char)uVar8 == -1)) goto LAB_1400039aa;
    }
    *(char *)(param_13 + 0x90) = (char)uVar17;
    *(ulonglong *)(param_13 + 0x88) = uVar7;
  }
  uVar11 = local_70;
  bVar2 = *(byte *)(lVar15 + 0x493a + param_2);
  lVar18 = uVar7 << (bVar2 & 0x3f);
  local_res10[0] = (uint)bVar2;
  bVar20 = ((char)local_50 - (char)uVar7) + 1;
  if (bVar20 == 1) {
    if (cVar16 == cVar12) {
      lVar18 = lVar18 + (ulonglong)uVar19;
      uVar11 = param_4;
    }
  }
  else if (*(char *)(param_13 + 0x91) == '\0') {
    uVar13 = (ulonglong)*(byte *)(lVar15 + 0x493c + param_2);
    if (local_68 == (local_58 + 1) * uVar13 - 1) {
      lVar18 = lVar18 + (ulonglong)uVar19;
      uVar11 = local_70 - uVar19;
    }
    if (2 < bVar20) {
      uVar11 = uVar11 + (bVar20 - 2 << (bVar2 & 0x1f));
    }
    if (local_48 == uVar13 * local_50) {
      uVar11 = uVar11 + uVar5 + 1;
    }
    else {
      uVar11 = uVar11 + local_70;
    }
  }
  else {
    lVar9 = get_strip_from_row((longlong)param_1,uVar21,local_58,param_2);
    uVar3 = local_70;
    if (uVar13 == lVar9 + ((ulonglong)
                           *(byte *)((ulonglong)(byte)local_74 * 0x128 + lVar15 + 0x49e3 + param_2)
                          - 1)) {
      lVar18 = lVar18 + (ulonglong)uVar19;
      uVar11 = local_70 - uVar19;
    }
    if (2 < bVar20) {
      uVar11 = uVar11 + (bVar20 - 2 << ((byte)local_res10[0] & 0x1f));
    }
    uVar13 = get_strip_from_row((longlong)param_1,uVar21,local_50,param_2);
    if (local_48 == uVar13) {
      uVar11 = uVar11 + uVar5 + 1;
    }
    else {
      uVar11 = uVar11 + uVar3;
    }
  }
  if (param_7 == '\0') {
    if (param_6 == '\0') goto LAB_14000376b;
    uVar4 = 1;
  }
  else if (param_6 == '\0') {
LAB_14000376b:
    uVar4 = *(undefined1 *)(lVar15 + 0x4943 + param_2);
  }
  else {
    uVar4 = *(undefined1 *)(lVar15 + 0x4945 + param_2);
  }
  cVar14 = '\x01';
  *(undefined1 *)(param_9 + 4) = uVar4;
  *(ushort *)(param_9 + 2) = (ushort)*(byte *)(param_2 + 0x18);
  *(undefined2 *)(param_9 + 6) = *(undefined2 *)(lVar15 + 0x4940 + param_2);
  *(longlong *)(param_9 + 8) = lVar18;
  *(uint *)(param_9 + 0x10) = uVar11;
  *(undefined2 *)(param_9 + 0x1a) = *(undefined2 *)(lVar15 + 0x4946 + param_2);
  uVar5 = *(ushort *)(lVar15 + 0x4940 + param_2);
  uVar8 = (ulonglong)uVar5;
  if (uVar5 != param_5) goto LAB_1400039aa;
  uVar11 = *(uint *)(lVar15 + 0x4928 + param_2);
  pcVar10 = (char *)(ulonglong)uVar11;
  if ((uVar11 & 1) == 0) {
    *param_11 = '\0';
    pcVar10 = param_11;
  }
  else {
    if (param_6 == '\0') {
      if ((uVar11 >> 0x14 & 1) != 0) {
        if (cVar16 != cVar12) {
          uVar13 = (ulonglong)pcVar10 & 0x400000;
          goto LAB_140003803;
        }
        goto LAB_140003808;
      }
LAB_140003805:
      cVar14 = '\0';
    }
    else {
      if ((uVar11 >> 0x15 & 1) == 0) goto LAB_140003805;
      if (cVar16 != cVar12) {
        uVar13 = (ulonglong)pcVar10 & 0x800000;
LAB_140003803:
        if (uVar13 == 0) goto LAB_140003805;
      }
    }
LAB_140003808:
    *param_11 = cVar14;
    if (cVar14 != '\0') {
      if (*(char *)(param_13 + 0x91) == '\0') {
        uVar13 = MR_GetPhyParams(param_2,uVar21,local_68,uVar19,param_8,param_10,param_9,param_7,
                                 param_13);
      }
      else {
        uVar13 = MR_Spanset_GetPhyParams
                           (param_2,(uint)bVar1,local_68,uVar19,param_8,param_10,param_9,param_7,
                            (longlong)param_1,param_13);
      }
      *(undefined1 *)(param_13 + 0x57) = 1;
      if (*param_10 == -1) {
        *param_11 = '\0';
        return uVar13;
      }
      return uVar13;
    }
  }
  *(undefined1 *)(param_13 + 0x57) = 0;
  if ((param_6 != '\0') && (pcVar10 = (char *)0x0, (char)(cVar16 - cVar12) != -1)) {
    if (*(char *)(param_13 + 0x91) == '\0') {
      uVar8 = MR_GetPhyParams(param_2,uVar21,local_68,uVar19,param_8,param_10,param_9,param_7,
                              param_13);
    }
    else {
      uVar8 = MR_Spanset_GetPhyParams
                        (param_2,uVar21,local_68,uVar19,param_8,param_10,param_9,param_7,
                         (longlong)param_1,param_13);
    }
    if ((char)uVar8 == '\0') {
LAB_1400039aa:
      return uVar8 & 0xffffffffffffff00;
    }
    pcVar10 = (char *)0x0;
  }
  return CONCAT71((int7)((ulonglong)pcVar10 >> 8),1);
}



===== MegaSASCheckBestRaid1Arm @ 1400039b0 =====

byte MegaSASCheckBestRaid1Arm
               (longlong param_1,longlong param_2,ulonglong param_3,byte param_4,ulonglong param_5,
               uint param_6,longlong param_7,longlong param_8)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  byte bVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  
  lVar7 = (param_3 & 0xffffffff) * 0x9e0;
  uVar1 = param_4 + 1;
  lVar5 = (ulonglong)
          *(ushort *)((ulonglong)*(byte *)(param_8 + 0x93) * 0x128 + lVar7 + 0x49e0 + param_7) *
          0x20;
  uVar9 = (ulonglong)*(ushort *)(param_7 + 0x928 + (lVar5 + (ulonglong)param_4) * 2);
  uVar3 = (uint)*(byte *)(lVar7 + 0x493b + param_7);
  if (uVar3 <= uVar1) {
    uVar1 = (param_4 - uVar3) + 1;
  }
  uVar3 = *(uint *)(param_1 + 4 + uVar9 * 4);
  uVar8 = (ulonglong)*(ushort *)(param_7 + 0x928 + ((ulonglong)uVar1 + lVar5) * 2);
  uVar1 = *(uint *)(param_1 + 4 + uVar8 * 4);
  uVar6 = *(ulonglong *)(param_1 + 0x408 + uVar9 * 8);
  if (uVar6 < param_5) {
    uVar6 = param_5 - uVar6;
  }
  else {
    uVar6 = uVar6 - param_5;
  }
  uVar2 = *(ulonglong *)(param_1 + 0x408 + uVar8 * 8);
  if (uVar2 < param_5) {
    uVar2 = param_5 - uVar2;
  }
  else {
    uVar2 = uVar2 - param_5;
  }
  bVar4 = param_4;
  if (uVar2 < uVar6) {
    bVar4 = param_4 ^ 1;
  }
  if (((bVar4 == param_4) && (*(int *)(param_2 + 0x8c) + uVar1 < uVar3)) ||
     ((bVar4 != param_4 && (*(int *)(param_2 + 0x8c) + uVar3 < uVar1)))) {
    bVar4 = bVar4 ^ 1;
  }
  if (bVar4 == param_4) {
    uVar8 = uVar9;
  }
  *(ulonglong *)(param_1 + 0x408 + uVar8 * 8) = (param_5 - 1) + (ulonglong)param_6;
  return bVar4;
}



===== MegaSASPrepareSyncInfo @ 140003b00 =====

longlong MegaSASPrepareSyncInfo(undefined8 param_1,longlong param_2,undefined1 *param_3)

{
  ushort uVar1;
  ulonglong uVar2;
  byte bVar3;
  
  uVar1 = *(ushort *)(param_2 + 0x20);
  if (uVar1 == 0) {
    return 0;
  }
  bVar3 = 0;
  if (uVar1 != 0) {
    do {
      uVar2 = (ulonglong)bVar3;
      bVar3 = bVar3 + 1;
      *param_3 = *(undefined1 *)(uVar2 * 0x9e0 + 0x4940 + param_2);
      *(undefined2 *)(param_3 + 2) = *(undefined2 *)(uVar2 * 0x9e0 + 0x4946 + param_2);
      param_3 = param_3 + 4;
    } while ((ushort)bVar3 < *(ushort *)(param_2 + 0x20));
  }
  return (ulonglong)uVar1 << 2;
}



===== MegaSASValidateAndProcessMapInfo @ 140003b70 =====

longlong MegaSASValidateAndProcessMapInfo(int *param_1)

{
  uint *puVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined1 *puVar7;
  uint *puVar8;
  longlong lVar9;
  longlong lVar10;
  
  lVar9 = *(longlong *)(param_1 + 0x1926);
  MR_PopulateDrvRaidMap((longlong)param_1);
  puVar1 = *(uint **)(param_1 + (ulonglong)(param_1[0x191b] & 1) * 2 + 0x1b5e);
  if ((char)param_1[0x1b5c] == '\0') {
    uVar3 = (uint)(ushort)puVar1[8] * 0x9e0 + 0x28a8;
  }
  else {
    uVar3 = param_1[0x1b5b];
  }
  uVar4 = (ulonglong)uVar3;
  if ((short)puVar1[8] != 0) {
    if (*puVar1 != uVar3) {
      return (ulonglong)(uVar3 >> 8) << 8;
    }
    if (*param_1 != 0) {
      mr_update_span_set((longlong)puVar1,lVar9,(longlong)param_1);
    }
    puVar8 = puVar1 + 0x20a;
    lVar9 = 0;
    puVar7 = (undefined1 *)((longlong)param_1 + 0x8f1);
    lVar10 = 0x100;
    do {
      uVar5 = (ulonglong)(byte)*puVar8;
      uVar4 = (ulonglong)*(ushort *)(param_1 + 0x1b62);
      lVar2 = *(longlong *)(param_1 + 0x1924);
      if ((ushort)(byte)*puVar8 < *(ushort *)(param_1 + 0x1b62)) {
        lVar6 = uVar5 * 0x9e0;
        if ((puVar1[uVar5 * 0x278 + 0x124a] & 0x800000) != 0) {
          puVar7[-1] = 1;
        }
        if ((puVar1[uVar5 * 0x278 + 0x124a] & 0x400000) != 0) {
          *puVar7 = 1;
        }
        uVar4 = 0;
        puVar7[1] = *(undefined1 *)(lVar6 + 0x493a + (longlong)puVar1);
        if ((*(char *)(lVar6 + 0x4939 + (longlong)puVar1) == '\x01') &&
           (*(char *)(lVar6 + 0x4942 + (longlong)puVar1) == '\x03')) {
          *(undefined1 *)(lVar2 + lVar9) = 1;
        }
        else {
          *(undefined1 *)(lVar2 + lVar9) = 0;
        }
      }
      puVar7 = puVar7 + 0x40;
      lVar9 = lVar9 + 0xc08;
      puVar8 = (uint *)((longlong)puVar8 + 1);
      lVar10 = lVar10 + -1;
    } while (lVar10 != 0);
    *(undefined1 *)((longlong)param_1 + 0x646a) = 1;
  }
  return CONCAT71((int7)(uVar4 >> 8),1);
}



===== MegaSAS_DoDIF @ 140003cb0 =====

longlong MegaSAS_DoDIF(longlong param_1,ulonglong param_2,longlong param_3)

{
  byte bVar1;
  ulonglong uVar2;
  
  bVar1 = *(byte *)((param_2 & 0xffffffff) + 0x828 + param_3);
  if ((ushort)bVar1 < *(ushort *)(param_1 + 0x6d88)) {
    uVar2 = (ulonglong)*(uint *)((ulonglong)bVar1 * 0x9e0 + 0x4928 + param_3) & 0xfffffffffffffff0;
    return CONCAT71((int7)(uVar2 >> 8),(char)uVar2 == -0x80);
  }
  return (ulonglong)(byte)(*(ushort *)(param_1 + 0x6d88) >> 8) << 8;
}



===== get_arm_from_strip @ 140003ce0 =====

int get_arm_from_strip(longlong param_1,uint param_2,ulonglong param_3,longlong param_4)

{
  byte bVar1;
  ulonglong *puVar2;
  uint *puVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  longlong lVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar10 = 0;
  lVar7 = (ulonglong)param_2 * 0x9e0 + param_4;
  uVar8 = 0;
  puVar2 = (ulonglong *)((ulonglong)param_2 * 0x2c0 + *(longlong *)(param_1 + 0x6498) + 0x28);
  while( true ) {
    if ((int)puVar2[4] == 0) {
      return -1;
    }
    if (param_3 <= *puVar2) break;
    uVar8 = uVar8 + 1;
    puVar2 = puVar2 + 0xb;
    if (7 < uVar8) {
      return -1;
    }
  }
  uVar6 = 0;
  bVar1 = *(byte *)(lVar7 + 0x4938);
  uVar9 = (uint)((param_3 - puVar2[-1]) % (ulonglong)(uint)puVar2[4]);
  if (bVar1 != 0) {
    lVar4 = 0;
    puVar3 = (uint *)(lVar7 + 0x49e8);
    do {
      if (uVar8 + 1 <= *puVar3) {
        uVar5 = (uint)*(byte *)((longlong)puVar2 + lVar4 + 0x18);
        if (uVar9 < uVar5) break;
        uVar6 = uVar5;
      }
      uVar10 = uVar10 + 1;
      lVar4 = lVar4 + 1;
      puVar3 = puVar3 + 0x4a;
    } while (uVar10 < bVar1);
  }
  return uVar9 - uVar6;
}



===== get_row_from_strip @ 140003db0 =====

longlong get_row_from_strip(longlong param_1,uint param_2,ulonglong param_3,longlong param_4)

{
  byte bVar1;
  ulonglong *puVar2;
  uint *puVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = 0;
  lVar5 = (ulonglong)param_2 * 0x9e0 + param_4;
  uVar7 = 0;
  puVar2 = (ulonglong *)((ulonglong)param_2 * 0x2c0 + *(longlong *)(param_1 + 0x6498) + 0x28);
  while( true ) {
    if ((int)puVar2[4] == 0) {
      return -1;
    }
    if (param_3 <= *puVar2) break;
    uVar7 = uVar7 + 1;
    puVar2 = puVar2 + 0xb;
    if (7 < uVar7) {
      return -1;
    }
  }
  iVar4 = 0;
  bVar1 = *(byte *)(lVar5 + 0x4938);
  if (bVar1 != 0) {
    lVar6 = 0;
    puVar3 = (uint *)(lVar5 + 0x49e8);
    do {
      if (uVar7 + 1 <= *puVar3) {
        if ((uint)((param_3 - puVar2[-1]) % (ulonglong)(uint)puVar2[4]) <
            (uint)*(byte *)((longlong)puVar2 + lVar6 + 0x18)) break;
        iVar4 = iVar4 + 1;
      }
      uVar8 = uVar8 + 1;
      lVar6 = lVar6 + 1;
      puVar3 = puVar3 + 0x4a;
    } while (uVar8 < bVar1);
  }
  return (ulonglong)(iVar4 - 1) + puVar2[1] +
         (ulonglong)*(uint *)((longlong)puVar2 + 0x24) *
         ((param_3 - puVar2[-1]) / (ulonglong)(uint)puVar2[4]);
}



===== get_strip_from_row @ 140003e90 =====

longlong get_strip_from_row(longlong param_1,uint param_2,ulonglong param_3,longlong param_4)

{
  byte bVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong *puVar5;
  longlong lVar6;
  uint uVar7;
  ulonglong uVar8;
  longlong lVar9;
  ulonglong uVar10;
  
  uVar3 = 0;
  uVar10 = (ulonglong)param_2;
  lVar4 = 0;
  lVar9 = uVar10 * 0x9e0 + param_4;
  puVar5 = (ulonglong *)(*(longlong *)(param_1 + 0x6498) + 0x38 + uVar10 * 0x2c0);
  do {
    if ((int)puVar5[2] == 0) {
      return -1;
    }
    if (param_3 <= *puVar5) {
      bVar1 = *(byte *)(lVar9 + 0x4938);
      uVar8 = 0;
      if (bVar1 != 0) {
        lVar2 = 0;
        do {
          if (uVar3 + 1 <= *(uint *)(lVar9 + 0x49e8 + lVar2)) {
            lVar6 = (uVar10 * 0x4f + lVar4) * 0x20 + lVar2 + param_4;
            if (*(uint *)(lVar6 + 0x4a08) == 0) break;
            if (((*(ulonglong *)(lVar6 + 0x49f0) <= param_3) &&
                (param_3 <= *(ulonglong *)(lVar6 + 0x49f8))) &&
               ((param_3 - *(ulonglong *)(lVar6 + 0x49f0)) % (ulonglong)*(uint *)(lVar6 + 0x4a08) ==
                0)) {
              return (((param_3 - puVar5[-1]) - *(longlong *)(lVar6 + 0x49f0)) /
                     (ulonglong)*(uint *)(lVar6 + 0x4a08)) * (ulonglong)(uint)puVar5[2] +
                     (ulonglong)*(byte *)(uVar8 + 8 + (longlong)puVar5) + puVar5[-3];
            }
          }
          uVar7 = (int)uVar8 + 1;
          uVar8 = (ulonglong)uVar7;
          lVar2 = lVar2 + 0x128;
        } while (uVar7 < bVar1);
      }
    }
    uVar3 = uVar3 + 1;
    lVar4 = lVar4 + 1;
    puVar5 = puVar5 + 0xb;
    if (7 < uVar3) {
      return -1;
    }
  } while( true );
}



===== mr_update_span_set @ 140003fd0 =====

void mr_update_span_set(longlong param_1,longlong param_2,longlong param_3)

{
  byte bVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  byte bVar5;
  longlong lVar6;
  uint uVar7;
  longlong lVar8;
  byte bVar9;
  ulonglong uVar10;
  longlong *plVar11;
  ulonglong uVar12;
  int iVar13;
  longlong *plVar14;
  byte *local_res20;
  longlong local_48;
  
  local_res20 = (byte *)(param_1 + 0x828);
  local_48 = 0x100;
  do {
    uVar12 = 0;
    bVar1 = *local_res20;
    if ((ushort)bVar1 < *(ushort *)(param_3 + 0x6d88)) {
      lVar8 = (ulonglong)bVar1 * 0x9e0;
      uVar4 = uVar12;
      do {
        bVar5 = *(byte *)(lVar8 + 0x4938 + param_1);
        uVar10 = 0;
        bVar9 = 0;
        iVar13 = (int)uVar4;
        if (bVar5 != 0) {
LAB_140004050:
          bVar9 = (byte)uVar10;
          if (iVar13 + 1U <= *(uint *)(uVar10 * 0x128 + lVar8 + 0x49e8 + param_1))
          goto code_r0x000140004068;
          lVar6 = (ulonglong)bVar1 * 8;
          plVar11 = (longlong *)((lVar6 + uVar12) * 0x58 + param_2);
          uVar7 = 0;
          plVar14 = (longlong *)
                    (param_1 + 0x49f0 + ((ulonglong)bVar1 * 0x4f + uVar12) * 0x20 + uVar10 * 0x128);
          bVar5 = 0;
          *(int *)((longlong)plVar11 + 0x4c) = (int)plVar14[3];
          if (*(char *)(lVar8 + 0x4938 + param_1) != '\0') {
            do {
              lVar3 = (ulonglong)bVar5 * 0x128 + lVar8;
              if (iVar13 + 1U <= *(uint *)(lVar3 + 0x49e8 + param_1)) {
                *(char *)((ulonglong)bVar5 + 0x40 + (longlong)plVar11) = (char)uVar7;
                uVar7 = uVar7 + *(byte *)(lVar3 + 0x49e3 + param_1);
              }
              bVar5 = bVar5 + 1;
            } while (bVar5 < *(byte *)(lVar8 + 0x4938 + param_1));
          }
          *(uint *)(plVar11 + 9) = uVar7;
          uVar2 = *(uint *)(plVar14 + 3);
          if (uVar2 != 0) {
            uVar4 = ((plVar14[1] - *plVar14) + (ulonglong)uVar2) / (ulonglong)uVar2;
            uVar10 = (ulonglong)uVar7;
            if (iVar13 == 0) {
              *plVar11 = 0;
              bVar5 = *(byte *)(lVar8 + 0x493a + param_1);
              plVar11[3] = uVar4 - 1;
              plVar11[1] = (uVar4 << (bVar5 & 0x3f)) * uVar10 + -1;
              plVar11[2] = 0;
              plVar11[4] = 0;
              plVar11[6] = 0;
              plVar11[5] = uVar10 * uVar4 + -1;
              plVar11[7] = *(uint *)(plVar14 + 3) * uVar4 + -1;
            }
            else {
              lVar3 = ((ulonglong)(iVar13 - 1) + lVar6) * 0x58 + param_2;
              lVar6 = *(longlong *)(lVar3 + 8) + 1;
              *plVar11 = lVar6;
              plVar11[1] = (uVar4 << (*(byte *)(lVar8 + 0x493a + param_1) & 0x3f)) * uVar10 + -1 +
                           lVar6;
              lVar6 = *(longlong *)(lVar3 + 0x18);
              plVar11[2] = lVar6 + 1;
              plVar11[3] = lVar6 + uVar4;
              lVar6 = *(longlong *)(lVar3 + 0x28);
              plVar11[4] = lVar6 + 1;
              plVar11[5] = lVar6 + uVar10 * uVar4;
              lVar6 = *(longlong *)(lVar3 + 0x38) + 1;
              plVar11[6] = lVar6;
              plVar11[7] = *(uint *)(plVar14 + 3) * uVar4 + -1 + lVar6;
            }
          }
        }
LAB_1400041f5:
        if (bVar9 == *(byte *)(lVar8 + 0x4938 + param_1)) break;
        uVar4 = (ulonglong)(iVar13 + 1U);
        uVar12 = uVar12 + 1;
      } while (iVar13 + 1U < 8);
    }
    local_res20 = local_res20 + 1;
    local_48 = local_48 + -1;
    if (local_48 == 0) {
      return;
    }
  } while( true );
code_r0x000140004068:
  bVar9 = bVar9 + 1;
  uVar10 = (ulonglong)bVar9;
  if (bVar5 <= bVar9) goto LAB_1400041f5;
  goto LAB_140004050;
}



===== PPC_FireCmd @ 1400042e0 =====

void PPC_FireCmd(longlong param_1,undefined8 param_2,byte param_3)

{
  uint local_res10;
  undefined4 uStackX_14;
  
  local_res10 = (uint)param_2;
  uStackX_14 = (undefined4)((ulonglong)param_2 >> 0x20);
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0xc4) = uStackX_14;
  LOCK();
  UNLOCK();
  *(uint *)(*(longlong *)(param_1 + 0x80) + 0xc0) = local_res10 | (uint)param_3 * 2 | 1;
  LOCK();
  UNLOCK();
  return;
}



===== Fusion_FireCmd @ 140004430 =====

void Fusion_FireCmd(longlong param_1,undefined8 param_2)

{
  *(int *)(*(longlong *)(param_1 + 0x80) + 0xc0) = (int)param_2;
  LOCK();
  UNLOCK();
  *(int *)(*(longlong *)(param_1 + 0x80) + 0xc4) = (int)((ulonglong)param_2 >> 0x20);
  LOCK();
  UNLOCK();
  return;
}



===== Fusion_FireRequest_MFI @ 140004470 =====

void Fusion_FireRequest_MFI(longlong param_1,longlong param_2)

{
  ushort uVar1;
  int local_res8;
  
  uVar1 = *(short *)(param_2 + 8) + 1;
  local_res8 = (uint)uVar1 << 0x10;
  MPT_BuildPassthrough
            (param_1,(undefined8 *)((ulonglong)uVar1 * 0x100 + *(longlong *)(param_1 + 0x64a0)),
             *(undefined8 *)(param_2 + 0x10));
  *(int *)(*(longlong *)(param_1 + 0x80) + 0xc0) = local_res8;
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0xc4) = 0;
  LOCK();
  UNLOCK();
  return;
}



===== Xscale_DisableInterrupt @ 1400046c0 =====

undefined4 Xscale_DisableInterrupt(longlong param_1)

{
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x34) = 0x1f;
  LOCK();
  UNLOCK();
  return *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x34);
}



===== CheckFirmwareReady @ 140004760 =====

ulonglong CheckFirmwareReady(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  uint local_res8 [8];
  
  uVar1 = (**(code **)(*(longlong *)(param_1 + 0x178) + 0x30))(*(undefined8 *)(param_1 + 0x80));
  *(uint *)(param_1 + 0x1ac) = uVar1;
  if (uVar1 != *(uint *)(param_1 + 0x1b0)) {
    *(uint *)(param_1 + 0x1b0) = uVar1;
    *(undefined1 *)(param_1 + 0x1b4) = 0;
  }
  uVar1 = uVar1 >> 0x1c;
  if (uVar1 == 6) {
    uVar2 = 0;
    if (*(char *)(param_1 + 0x1b4) != '\0') goto LAB_14000486d;
    MemFastZero((undefined8 *)local_res8,4);
    local_res8[0] = local_res8[0] | 0x18;
  }
  else {
    if (uVar1 != 9) {
      if (uVar1 == 0xb) {
        *(undefined4 *)(param_1 + 0x1b0) = 0xff;
        *(undefined1 *)(param_1 + 0x6451) = 0;
        return 1;
      }
      uVar2 = (ulonglong)(uVar1 - 0xc);
      if ((uVar1 - 0xc == 0) && (*(char *)(param_1 + 0x1b5) == '\0')) {
        MemFastZero((undefined8 *)local_res8,uVar1 - 8);
        local_res8[0] = local_res8[0] | 7;
        uVar2 = (**(code **)(*(longlong *)(param_1 + 0x178) + 0x40))
                          (*(undefined8 *)(param_1 + 0x80));
        *(undefined1 *)(param_1 + 0x1b5) = 1;
        return uVar2 & 0xffffffffffffff00;
      }
      goto LAB_14000486d;
    }
    uVar2 = 0;
    if (*(char *)(param_1 + 0x1b4) != '\0') goto LAB_14000486d;
    MemFastZero((undefined8 *)local_res8,4);
    local_res8[0] = local_res8[0] | 0x10;
  }
  uVar2 = (**(code **)(*(longlong *)(param_1 + 0x178) + 0x40))(*(undefined8 *)(param_1 + 0x80));
  *(undefined1 *)(param_1 + 0x1b4) = 1;
LAB_14000486d:
  return uVar2 & 0xffffffffffffff00;
}



===== InitializeAdapter @ 140004880 =====

ulonglong InitializeAdapter(uint *param_1)

{
  byte bVar1;
  longlong lVar2;
  char cVar3;
  bool bVar4;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 extraout_var_01;
  undefined7 extraout_var_02;
  undefined7 extraout_var_03;
  ulonglong uVar5;
  byte bVar6;
  undefined4 *puVar7;
  uint uVar8;
  
  *(undefined1 *)((longlong)param_1 + 0x646b) = 0;
  *(undefined1 *)((longlong)param_1 + 0x1d6) = 0;
  param_1[0x1b4f] = 0;
  param_1[0x1b50] = 0;
  param_1[0x1b52] = 0;
  param_1[0x1b53] = 0;
  param_1[0x1b51] = 0;
  if ((char)param_1[0x191a] == '\0') {
    uVar8 = 0;
    if (*(char *)((longlong)param_1 + 0x48f1) != '\0') {
      do {
        uVar5 = (ulonglong)uVar8;
        uVar8 = uVar8 + 1;
        puVar7 = (undefined4 *)(uVar5 * 0x10 + *(longlong *)(param_1 + 0x1918));
        puVar7[1] = *puVar7;
      } while (uVar8 < *(byte *)((longlong)param_1 + 0x48f1));
    }
    *(undefined1 *)((longlong)param_1 + 0x645f) = 0;
  }
  param_1[0x1916] = 60000000;
  do {
    lVar2 = *(longlong *)(param_1 + 0x32);
    cVar3 = (*(code *)**(undefined8 **)(param_1 + 0x5e))
                      (param_1,lVar2,*(undefined8 *)(param_1 + 0x56));
    bVar4 = WaitForCmdStatus((longlong)param_1,lVar2);
    uVar5 = CONCAT71(extraout_var,bVar4);
    if (!bVar4) goto LAB_140004ae3;
  } while (cVar3 == '\0');
  uVar8 = (**(code **)(*(longlong *)(param_1 + 0x5e) + 0x30))(*(undefined8 *)(param_1 + 0x20));
  param_1[0x6b] = uVar8;
  uVar5 = (ulonglong)(uVar8 & 0xf0000000);
  if ((uVar8 & 0xf0000000) == 0xc0000000) {
    param_1[0x1916] = 60000000;
    bVar4 = SendAndWaitDCMD((int *)param_1,0x1010000);
    uVar5 = CONCAT71(extraout_var_00,bVar4);
    if (bVar4) {
      lVar2 = *(longlong *)(param_1 + 0x4e);
      bVar6 = (byte)(*(uint *)(lVar2 + 0x7e8) >> 5) & 1;
      *(byte *)(param_1 + 0x1b5c) = bVar6;
      *param_1 = *(uint *)(lVar2 + 0x7a4) >> 0x14 & 1;
      bVar1 = *(byte *)(lVar2 + 0x53f);
      param_1[0x1b63] = 0x1000100;
      if (0x40 < bVar1) {
        bVar6 = 1;
      }
      *(byte *)(param_1 + 0x1b5c) = bVar6;
      if (bVar6 == 0) {
        uVar8 = param_1[0x1b59];
      }
      else {
        uVar8 = param_1[0x1b5a];
      }
      param_1[7000] = uVar8;
      if (bVar6 == 0) {
        param_1[0x1b62] = 0x1000040;
      }
      else {
        param_1[0x1b62] = 0x1000100;
      }
      bVar1 = *(byte *)(lVar2 + 0x5b0);
      param_1[0x1916] = 60000000;
      param_1[0x1b4e] = (byte)~bVar1 >> 4 & 1;
      SendAndWaitDCMD((int *)param_1,0x2010100);
      if ((char)param_1[0x22] != '\0') {
LAB_140004b3a:
        MemFastZero((undefined8 *)(param_1 + 0x230),0x4000);
        return 1;
      }
      param_1[0x1916] = 60000000;
      bVar4 = SendAndWaitDCMD((int *)param_1,0x1020100);
      uVar5 = CONCAT71(extraout_var_01,bVar4);
      if (bVar4) {
        param_1[0x1916] = 60000000;
        bVar4 = SendAndWaitDCMD((int *)param_1,0x1040100);
        uVar5 = CONCAT71(extraout_var_02,bVar4);
        if (bVar4) {
          if ((char)param_1[0x191a] != '\0') {
            if (*(char *)((longlong)param_1 + 0x646a) == '\0') {
              MPT_UpdateReplyQueue((longlong)param_1);
            }
            else {
              param_1[0x191b] = 0;
              param_1[0x1916] = 60000000;
              bVar4 = SendAndWaitDCMD((int *)param_1,0x300e101);
              uVar5 = CONCAT71(extraout_var_03,bVar4);
              if (!bVar4) goto LAB_140004ae3;
              MPT_UpdateReplyQueue((longlong)param_1);
              param_1[0x191b] = 1;
              IssueDCMD((longlong)param_1,0x300e101);
            }
            if (0 < (int)param_1[0x69]) {
              uVar5 = SetDeadAdapter((longlong)param_1,100);
              goto LAB_140004ae3;
            }
          }
          *(undefined1 *)((longlong)param_1 + 0x1d5) = 1;
          IssueDCMD((longlong)param_1,0x1040500);
          *(undefined1 *)((longlong)param_1 + 0x1d5) = 0;
          if ((char)param_1[0x22] == '\0') {
            MemFastZero(*(undefined8 **)(param_1 + 0x1924),((ushort)param_1[0x74] + 0xc08) * 0x100);
          }
          goto LAB_140004b3a;
        }
      }
    }
  }
LAB_140004ae3:
  return uVar5 & 0xffffffffffffff00;
}



===== MegaSASInitialize @ 140004b60 =====

undefined8 MegaSASInitialize(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 local_res8 [2];
  
  if (*(char *)(param_1 + 0x88) != '\0') {
    *(undefined1 *)(param_1 + 0x6453) = 0;
    uVar2 = (**(code **)(*(longlong *)(param_1 + 0x178) + 0x20))();
    return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
  }
  if ((*(char *)(param_1 + 0x48f0) != '\0') && (*(char *)(param_1 + 0x48f2) != '\0')) {
    iVar1 = StorPortExtendedFunction(0xd,param_1,0,param_1 + 0x48d0);
    if (iVar1 != 0) {
      *(undefined1 *)(param_1 + 0x48f2) = 0;
    }
    *(undefined4 *)(param_1 + 0x48fc) = 0x28;
    *(undefined4 *)(param_1 + 0x48f8) = 4;
    iVar1 = StorPortExtendedFunction(0xe,param_1,1,param_1 + 0x48f8);
    if (iVar1 != 0) {
      *(undefined1 *)(param_1 + 0x48f2) = 0;
    }
    if (*(char *)(param_1 + 0x48f2) != '\0') {
      *(uint *)(param_1 + 0x4900) = *(uint *)(param_1 + 0x4900) & 1;
      iVar1 = StorPortExtendedFunction(0xe,param_1,0,param_1 + 0x48f8);
      if (iVar1 != 0) {
        *(undefined1 *)(param_1 + 0x48f2) = 0;
      }
    }
  }
  local_res8[0] = 0;
  uVar2 = StorPortNotification(0x1000,param_1,InitDPC,local_res8);
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== TimeForFwareReadyInitWithRetry @ 140004c70 =====

void TimeForFwareReadyInitWithRetry(uint *param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  
  uVar1 = CheckFirmwareReady((longlong)param_1);
  if ((char)uVar1 == '\0') {
    if ((-1 < (int)param_1[0x1916]) && ((param_1[0x6b] & 0xf0000000) != 0xf0000000)) {
      param_1[0x1916] = param_1[0x1916] - 250000;
      goto LAB_140004cd4;
    }
    uVar2 = CheckResetRetries((longlong)param_1);
    if ((char)uVar2 == '\0') {
      SetDeadAdapter((longlong)param_1,0x12);
      return;
    }
  }
  else {
    uVar1 = InitializeAdapter(param_1);
    if ((char)uVar1 != '\0') {
      *(undefined1 *)((longlong)param_1 + 0x6453) = 0;
      (**(code **)(*(longlong *)(param_1 + 0x5e) + 0x20))();
      DoResumeInput((longlong)param_1);
      return;
    }
    uVar2 = CheckResetRetries((longlong)param_1);
    if ((char)uVar2 == '\0') {
      SetDeadAdapter((longlong)param_1,9);
      return;
    }
  }
  param_1[0x1916] = 600000000;
LAB_140004cd4:
  StorPortNotification(6,param_1,TimeForFwareReadyInitWithRetry,250000);
  return;
}



===== WaitForFwareReadyWithRetry @ 140004d40 =====

ulonglong WaitForFwareReadyWithRetry(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  uint local_res8 [2];
  uint local_res10 [2];
  uint local_res18 [4];
  
  *(undefined4 *)(param_1 + 0x6458) = 600000000;
  do {
    uVar1 = (**(code **)(*(longlong *)(param_1 + 0x178) + 0x30))(*(undefined8 *)(param_1 + 0x80));
    *(uint *)(param_1 + 0x1ac) = uVar1;
    if (uVar1 != *(uint *)(param_1 + 0x1b0)) {
      *(uint *)(param_1 + 0x1b0) = uVar1;
      *(undefined1 *)(param_1 + 0x1b4) = 0;
    }
    uVar1 = uVar1 >> 0x1c;
    if (uVar1 == 6) {
      if (*(char *)(param_1 + 0x1b4) == '\0') {
        MemFastZero((undefined8 *)local_res18,4);
        local_res18[0] = local_res18[0] | 0x18;
LAB_140004e32:
        (**(code **)(*(longlong *)(param_1 + 0x178) + 0x40))(*(undefined8 *)(param_1 + 0x80));
        *(undefined1 *)(param_1 + 0x1b4) = 1;
      }
    }
    else if (uVar1 == 9) {
      if (*(char *)(param_1 + 0x1b4) == '\0') {
        MemFastZero((undefined8 *)local_res10,4);
        local_res10[0] = local_res10[0] | 0x10;
        goto LAB_140004e32;
      }
    }
    else {
      if (uVar1 == 0xb) {
        *(undefined4 *)(param_1 + 0x1b0) = 0xff;
        *(undefined1 *)(param_1 + 0x6451) = 0;
        return 1;
      }
      if ((uVar1 == 0xc) && (*(char *)(param_1 + 0x1b5) == '\0')) {
        MemFastZero((undefined8 *)local_res8,4);
        local_res8[0] = local_res8[0] | 7;
        (**(code **)(*(longlong *)(param_1 + 0x178) + 0x40))(*(undefined8 *)(param_1 + 0x80));
        *(undefined1 *)(param_1 + 0x1b5) = 1;
      }
    }
    if ((*(int *)(param_1 + 0x6458) < 0) ||
       ((*(uint *)(param_1 + 0x1ac) & 0xf0000000) == 0xf0000000)) {
      uVar2 = CheckResetRetries(param_1);
      if ((char)uVar2 == '\0') {
        return uVar2 & 0xffffffffffffff00;
      }
      *(undefined4 *)(param_1 + 0x6458) = 600000000;
    }
    else {
      StorPortStallExecution(1000);
      *(int *)(param_1 + 0x6458) = *(int *)(param_1 + 0x6458) + -1000;
    }
  } while( true );
}



===== WaitForInitializeWithRetry @ 140004ec0 =====

undefined8 WaitForInitializeWithRetry(uint *param_1)

{
  char cVar1;
  ulonglong uVar2;
  
  uVar2 = InitializeAdapter(param_1);
  cVar1 = (char)uVar2;
  while( true ) {
    if (cVar1 != '\0') {
      return CONCAT71((int7)(uVar2 >> 8),1);
    }
    uVar2 = CheckResetRetries((longlong)param_1);
    if (((char)uVar2 == '\0') ||
       (uVar2 = WaitForFwareReadyWithRetry((longlong)param_1), (char)uVar2 == '\0')) break;
    uVar2 = InitializeAdapter(param_1);
    cVar1 = (char)uVar2;
  }
  return uVar2 & 0xffffffffffffff00;
}



===== FinishDeferedWork @ 140004f10 =====

void FinishDeferedWork(undefined8 param_1,longlong param_2)

{
  uint *puVar1;
  byte bVar2;
  uint uVar3;
  char cVar4;
  ulonglong uVar5;
  undefined8 local_28 [4];
  
  cVar4 = '\0';
  *(undefined4 *)(param_2 + 0x6440) = 0;
  if (*(char *)(param_2 + 0x6451) != '\0') {
    *(undefined2 *)(param_2 + 0x6420) = 0;
    *(undefined1 *)(param_2 + 0x6422) = 0;
    *(undefined8 *)(param_2 + 0x6424) = 0;
    *(undefined1 *)(param_2 + 0x642c) = 0;
    return;
  }
  MemFastZero(local_28,0x20);
  StorPortNotification(0x1003,param_2,2,0,local_28);
  if (*(char *)(param_2 + 0x6422) != '\0') {
    *(undefined1 *)(param_2 + 0x6422) = 0;
    IssueDCMD(param_2,0x300e101);
  }
  if (*(char *)(param_2 + 0x6421) != '\0') {
    *(undefined1 *)(param_2 + 0x6421) = 0;
    IssueDCMD(param_2,0x1040500);
  }
  if (*(int *)(param_2 + 0x6424) == 1) {
    *(undefined4 *)(param_2 + 0x6424) = 2;
    IssueDCMD(param_2,0x2010100);
  }
  if (*(int *)(param_2 + 0x6424) == 4) {
    *(undefined4 *)(param_2 + 0x6424) = 0;
    CompletePDquery(param_2);
  }
  if ((*(char *)(param_2 + 0x642c) != '\0') && (*(char *)(param_2 + 0x642d) == '\0')) {
    uVar5 = 0;
    do {
      bVar2 = 0;
      do {
        uVar3 = 1 << (bVar2 & 0x1f);
        if ((uVar3 & *(uint *)(param_2 + 0x6d90 + uVar5 * 4)) != 0) {
          *(byte *)(param_2 + 0x6db0) = bVar2 + cVar4;
          IssueDCMD(param_2,0x2020000);
          puVar1 = (uint *)(param_2 + 0x6d90 + uVar5 * 4);
          *puVar1 = *puVar1 & ~uVar3;
          goto LAB_140005069;
        }
        bVar2 = bVar2 + 1;
      } while (bVar2 < 0x20);
      cVar4 = cVar4 + ' ';
      bVar2 = (char)uVar5 + 1;
      uVar5 = (ulonglong)bVar2;
    } while (bVar2 < 8);
  }
LAB_140005069:
  if (*(longlong *)(param_2 + 400) != 0) {
    TryFlushingIoctl(param_2);
  }
  if (*(char *)(param_2 + 0x48c8) != '\0') {
    TryFlushingGroups(param_2);
  }
  StorPortNotification(0x1004,param_2,local_28);
  return;
}



===== HandleResponses @ 1400050b0 =====

void HandleResponses(longlong param_1,ulonglong param_2)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined4 local_res8 [2];
  
  cVar3 = (**(code **)(*(longlong *)(param_1 + 0x178) + 0x10))();
  if (cVar3 != '\0') {
    if (*(char *)(param_1 + 0x6450) != '\0') {
      if (*(int *)(param_1 + 0x1a0) == 0) {
        *(undefined1 *)(param_1 + 0x6450) = 0;
        DoResumeInput(param_1);
      }
      if (*(char *)(param_1 + 0x6450) != '\0') {
        return;
      }
    }
    if ((*(char *)(param_1 + 0x88) == '\0') &&
       ((((*(longlong *)(param_1 + 400) != 0 || (*(char *)(param_1 + 0x48c8) != '\0')) ||
         (*(char *)(param_1 + 0x6421) != '\0')) ||
        (((*(char *)(param_1 + 0x6422) != '\0' || ((*(uint *)(param_1 + 0x6424) & 5) != 0)) ||
         (*(char *)(param_1 + 0x642c) != '\0')))))) {
      LOCK();
      piVar1 = (int *)(param_1 + 0x6440);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      if (iVar2 == 0) {
        local_res8[0] = 0;
        StorPortNotification
                  (0x1002,param_1,param_1 + ((param_2 & 0xffffffff) + 0x104) * 0x48,param_1,param_1,
                   local_res8);
      }
    }
  }
  return;
}



===== InitDPC @ 1400051a0 =====

undefined8 InitDPC(longlong param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  longlong lVar3;
  
  puVar2 = (undefined8 *)(param_1 + 0x4920);
  MemFastZero(puVar2,0x1b00);
  if (*(char *)(param_1 + 0x6469) == '\0') {
    lVar3 = 0x10;
    do {
      StorPortNotification(0x1001,param_1,puVar2,FinishDeferedWork);
      puVar2 = puVar2 + 9;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
  }
  else {
    lVar3 = 0x60;
    do {
      StorPortNotification(0x1001,param_1,puVar2,FinishDeferedWork);
      puVar2 = puVar2 + 9;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
  }
  *(undefined1 *)(param_1 + 0x6453) = 0;
  uVar1 = (**(code **)(*(longlong *)(param_1 + 0x178) + 0x20))(param_1);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== LegacyInterrupts @ 140005260 =====

undefined1 LegacyInterrupts(longlong param_1)

{
  byte bVar1;
  undefined8 uVar2;
  
  if ((*(char *)(param_1 + 0x48f0) == '\0') || (*(char *)(param_1 + 0x88) == '\0')) {
    bVar1 = (**(code **)(*(longlong *)(param_1 + 0x178) + 0x18))();
    if (bVar1 == 0) {
      return 0;
    }
    if ((*(char *)(param_1 + 0x6453) == '\0') && (*(char *)(param_1 + 0x6452) == '\0')) {
      if (((bVar1 & 2) != 0) && (uVar2 = CheckFirmwareFault(param_1), (char)uVar2 != '\0')) {
        return 1;
      }
      HandleResponses(param_1,0);
    }
  }
  else if (((*(char *)(param_1 + 0x6453) == '\0') && (*(char *)(param_1 + 0x6452) == '\0')) &&
          (*(char *)(param_1 + 0x6cb2) == '\0')) {
    HandleResponses(param_1,0);
    return 1;
  }
  return 1;
}



===== MessageInterrupts @ 1400052f0 =====

undefined1 MessageInterrupts(longlong param_1,byte param_2)

{
  if (((*(char *)(param_1 + 0x6453) == '\0') && (*(char *)(param_1 + 0x6452) == '\0')) &&
     (*(char *)(param_1 + 0x6cb2) == '\0')) {
    HandleResponses(param_1,(ulonglong)param_2);
  }
  return 1;
}



===== FirmwareIOcall @ 140005320 =====

ulonglong FirmwareIOcall(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  char cVar2;
  longlong lVar3;
  longlong *plVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint uVar7;
  undefined1 local_res18 [16];
  
  plVar4 = ClearSRBExtension(param_1,param_2);
  lVar3 = *(longlong *)(param_2 + 0x18);
  pbVar1 = (byte *)(plVar4 + 0x20);
  cVar2 = *(char *)(lVar3 + 0x1c);
  if ((byte)(cVar2 - 3U) < 2) {
    MemFastMove((undefined8 *)pbVar1,(undefined8 *)(lVar3 + 0x1c),0x40);
    *(undefined2 *)(plVar4 + 0x22) = 0;
    plVar4[0x21] = 0;
    plVar4[8] = (longlong)(plVar4 + 0x26);
    plVar4[7] = (longlong)(plVar4 + 0x26);
    uVar5 = BuildSGLforIOCTL(param_1,plVar4,lVar3 + 0xbc,*(uint *)(lVar3 + 0x30));
    if ((char)uVar5 == '\0') goto LAB_1400053c5;
    *(ushort *)(plVar4 + 0x22) =
         (ushort)(*(char *)((longlong)plVar4 + 0x1a) != '\0') * 2 |
         *(ushort *)(plVar4 + 0x22) & 0xfffd;
    lVar6 = 0;
    *(char *)((longlong)plVar4 + 0x107) = *(char *)((longlong)plVar4 + 0x34);
    if (*(char *)((longlong)plVar4 + 0x34) != '\0') {
      lVar6 = MFI_SetFrameCount(param_1,(longlong)plVar4,*(byte *)(lVar3 + 0x1c));
    }
    if (*(char *)(lVar3 + 0x1d) != '\0') {
      lVar6 = StorPortGetPhysicalAddress(param_1,param_2,lVar3 + 0x9c,local_res18);
      if (0 < (int)((ulonglong)lVar6 >> 0x20)) {
        *(ushort *)(plVar4 + 0x22) = *(ushort *)(plVar4 + 0x22) | 4;
      }
      plVar4[0x23] = lVar6;
    }
LAB_1400055ac:
    *(undefined1 *)(plVar4 + 0xd) = 1;
    uVar5 = CONCAT71((int7)((ulonglong)lVar6 >> 8),1);
  }
  else {
    if (cVar2 == '\x05') {
      MemFastMove((undefined8 *)pbVar1,(undefined8 *)(lVar3 + 0x1c),0x40);
      lVar6 = lVar3 + 0xbc;
      *(undefined4 *)(plVar4 + 0x23) = *(undefined4 *)(lVar3 + 0x34);
      *(undefined4 *)((longlong)plVar4 + 0x11c) = *(undefined4 *)(lVar3 + 0x38);
      *(undefined4 *)(plVar4 + 0x24) = *(undefined4 *)(lVar3 + 0x3c);
      *(undefined4 *)((longlong)plVar4 + 0x124) = *(undefined4 *)(lVar3 + 0x40);
      *(undefined2 *)(plVar4 + 0x22) = 0;
      *(undefined4 *)(plVar4 + 0x21) = 0;
      plVar4[8] = (longlong)(plVar4 + 0x25);
      plVar4[7] = (longlong)(plVar4 + 0x25);
LAB_1400053ae:
      uVar7 = *(uint *)(lVar3 + 0x30);
LAB_1400053b2:
      uVar5 = BuildSGLforIOCTL(param_1,plVar4,lVar6,uVar7);
      if ((char)uVar5 != '\0') {
        *(ushort *)(plVar4 + 0x22) =
             (ushort)(*(char *)((longlong)plVar4 + 0x1a) != '\0') * 2 |
             *(ushort *)(plVar4 + 0x22) & 0xfffd;
        lVar6 = 0;
        *(char *)((longlong)plVar4 + 0x107) = *(char *)((longlong)plVar4 + 0x34);
        if (*(char *)((longlong)plVar4 + 0x34) != '\0') {
          lVar6 = MFI_SetFrameCount(param_1,(longlong)plVar4,*pbVar1);
        }
        goto LAB_1400055ac;
      }
    }
    else if (cVar2 == '\a') {
      MemFastMove((undefined8 *)pbVar1,(undefined8 *)(lVar3 + 0x1c),0x38);
      *(undefined2 *)(lVar3 + 0x2c) = 0;
      *(undefined8 *)(lVar3 + 0x24) = 0;
      plVar4[8] = (longlong)(plVar4 + 0x24);
      plVar4[7] = (longlong)(plVar4 + 0x24);
      uVar5 = BuildSGLforIOCTL(param_1,plVar4,lVar3 + 0xbc,*(uint *)(lVar3 + 0x30));
      if ((char)uVar5 != '\0') {
        lVar6 = lVar3 + 0xbc + (ulonglong)*(uint *)(lVar3 + 0x30);
        uVar7 = (*(int *)(param_2 + 0x10) - *(uint *)(lVar3 + 0x30)) - 0xbc;
        goto LAB_1400053b2;
      }
    }
    else {
      if (cVar2 != '\b') {
        *(undefined1 *)(param_2 + 3) = 6;
        *(undefined4 *)(lVar3 + 0x14) = 1;
        return 0;
      }
      MemFastMove((undefined8 *)pbVar1,(undefined8 *)(lVar3 + 0x1c),0x40);
      *(undefined2 *)(lVar3 + 0x2c) = 0;
      *(undefined8 *)(lVar3 + 0x24) = 0;
      plVar4[8] = (longlong)(plVar4 + 0x26);
      plVar4[7] = (longlong)(plVar4 + 0x26);
      uVar7 = (*(int *)(param_2 + 0x10) - *(int *)(lVar3 + 0x30)) - 0xbc;
      uVar5 = BuildSGLforIOCTL(param_1,plVar4,lVar3 + 0xbc,uVar7);
      if ((char)uVar5 != '\0') {
        lVar6 = (ulonglong)uVar7 + 0xbc + lVar3;
        goto LAB_1400053ae;
      }
    }
LAB_1400053c5:
    *(undefined1 *)(param_2 + 3) = 0x12;
    uVar5 = uVar5 & 0xffffffffffffff00;
  }
  return uVar5;
}



===== MaskInformation @ 1400055d0 =====

ulonglong MaskInformation(longlong param_1,longlong param_2)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  longlong lVar4;
  ushort uVar5;
  ulonglong in_RAX;
  ulonglong uVar6;
  longlong *plVar7;
  undefined8 uVar8;
  undefined4 local_res10;
  
  lVar4 = *(longlong *)(param_2 + 0x18);
  if (*(uint *)(param_2 + 0x10) < 0xc0) {
    *(undefined1 *)(param_2 + 3) = 6;
    *(undefined4 *)(lVar4 + 0x14) = 1;
    return in_RAX & 0xffffffffffffff00;
  }
  uVar2 = *(ushort *)(param_1 + 0x83c);
  cVar1 = *(char *)(lVar4 + 0xbf);
  uVar5 = *(ushort *)(lVar4 + 0xbc) ^ uVar2;
  uVar6 = (ulonglong)uVar5;
  local_res10._0_3_ = (uint3)uVar2;
  local_res10 = CONCAT13(*(char *)(param_1 + 0x83f),(uint3)local_res10);
  if (uVar5 != 0) {
    local_res10 = CONCAT22(local_res10._2_2_,uVar2 | *(ushort *)(lVar4 + 0xbc));
    uVar6 = (ulonglong)local_res10;
    *(uint *)(param_1 + 0x83c) = local_res10;
  }
  if (cVar1 < *(char *)(param_1 + 0x83f)) {
    local_res10 = CONCAT13(cVar1,(uint3)local_res10);
    *(uint *)(param_1 + 0x83c) = local_res10;
  }
  else if (uVar5 == 0) {
    *(undefined1 *)(lVar4 + 0x1e) = 0;
    return uVar6 & 0xffffffffffffff00;
  }
  lVar4 = *(longlong *)(param_1 + 0xf8);
  plVar7 = ClearSRBExtension(param_1,param_2);
  uVar8 = MemFastZero(plVar7 + 0x20,0x28);
  *(undefined1 *)(plVar7 + 0x20) = 6;
  iVar3 = *(int *)(param_1 + 0x88c);
  plVar7[0x24] = lVar4;
  *(int *)(plVar7 + 0x23) = iVar3 + -2;
  return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
}



===== MegaSASIoctl @ 1400056e0 =====

ulonglong MegaSASIoctl(longlong param_1,longlong param_2)

{
  uint uVar1;
  undefined4 uVar2;
  longlong lVar3;
  ulonglong in_RAX;
  ulonglong uVar4;
  
  lVar3 = *(longlong *)(param_2 + 0x18);
  if (*(uint *)(param_2 + 0x10) < 0xbc) {
    *(undefined1 *)(param_2 + 3) = 6;
    *(undefined4 *)(lVar3 + 0x14) = 1;
    return in_RAX & 0xffffffffffffff00;
  }
  if (((((*(char *)(lVar3 + 4) != 'L') || (*(char *)(lVar3 + 5) != 'S')) ||
       (*(char *)(lVar3 + 6) != 'I')) ||
      ((*(char *)(lVar3 + 7) != 'L' || (*(char *)(lVar3 + 8) != 'O')))) ||
     ((*(char *)(lVar3 + 9) != 'G' ||
      ((*(char *)(lVar3 + 10) != 'I' || (*(char *)(lVar3 + 0xb) != 'C')))))) {
    *(undefined1 *)(param_2 + 3) = 6;
    *(undefined4 *)(lVar3 + 0x14) = 1;
    uVar4 = MemFastZero((undefined8 *)(lVar3 + 4),8);
    return uVar4 & 0xffffffffffffff00;
  }
  MemFastZero((undefined8 *)(lVar3 + 4),8);
  if ((*(int *)(lVar3 + 0x10) + 0xfff0000U & 0xfffeffff) != 0) {
LAB_140005881:
    uVar4 = FirmwareIOcall(param_1,param_2);
    return uVar4;
  }
  lVar3 = *(longlong *)(param_2 + 0x18);
  uVar1 = *(uint *)(lVar3 + 0x34);
  if (uVar1 < 0xf0020101) {
    if (uVar1 == 0xf0020100) {
      *(undefined1 *)(lVar3 + 0x1e) = 0;
      uVar4 = StorPortNotification(7,param_1,*(undefined1 *)(lVar3 + 0x38));
      return uVar4 & 0xffffffffffffff00;
    }
    if (uVar1 == 0xf0010100) {
      if (299 < *(uint *)(param_2 + 0x10)) {
        uVar4 = MemFastMove((undefined8 *)(lVar3 + 0xbc),(undefined8 *)s_LSILOGIC_14000f030,0x70);
        *(undefined1 *)(lVar3 + 0x1e) = 0;
        return uVar4 & 0xffffffffffffff00;
      }
    }
    else if (uVar1 == 0xf0010200) {
      if (299 < *(uint *)(param_2 + 0x10)) {
        uVar4 = MemFastMove((undefined8 *)(lVar3 + 0xbc),(undefined8 *)(param_1 + 8),0x70);
        *(undefined1 *)(lVar3 + 0x1e) = 0;
        return uVar4 & 0xffffffffffffff00;
      }
    }
    else if (uVar1 != 0xf0010300) goto LAB_140005881;
  }
  else {
    if (uVar1 == 0xf0020200) {
      uVar4 = MaskInformation(param_1,param_2);
      return uVar4;
    }
    if (uVar1 != 0xf0020300) goto LAB_140005881;
    if (0xbf < *(uint *)(param_2 + 0x10)) {
      uVar2 = *(undefined4 *)(param_1 + 0x78);
      *(undefined4 *)(lVar3 + 0xbc) = uVar2;
      *(undefined1 *)(lVar3 + 0x1e) = 0;
      return (ulonglong)(uint3)((uint)uVar2 >> 8) << 8;
    }
  }
  *(undefined1 *)(param_2 + 3) = 6;
  *(undefined4 *)(lVar3 + 0x14) = 1;
  return (ulonglong)(uint3)(uVar1 >> 8) << 8;
}



===== AbortPendedCommands @ 140005910 =====

void AbortPendedCommands(longlong param_1)

{
  longlong lVar1;
  bool bVar2;
  
  lVar1 = *(longlong *)(param_1 + 200);
  if (*(char *)(param_1 + 0x646b) != '\0') {
    PrepareAbortFrame(param_1,3);
    (**(code **)(*(longlong *)(param_1 + 0x178) + 0x58))(param_1,lVar1);
    bVar2 = WaitForCmdStatus(param_1,lVar1);
    if (bVar2) {
      *(undefined1 *)(param_1 + 0x646b) = 0;
    }
    else {
      StorPortLogError(param_1,0,0xff,0xff,0xff,6,0x13);
    }
  }
  if (*(char *)(param_1 + 0x1d6) != '\0') {
    PrepareAbortFrame(param_1,2);
    (**(code **)(*(longlong *)(param_1 + 0x178) + 0x58))(param_1,lVar1);
    bVar2 = WaitForCmdStatus(param_1,lVar1);
    if (!bVar2) {
      StorPortLogError(param_1,0,0xff,0xff,0xff,6,0x13);
      return;
    }
    *(undefined1 *)(param_1 + 0x1d6) = 0;
  }
  return;
}



===== DriverEntry @ 140005a00 =====

void DriverEntry(undefined8 param_1,undefined8 param_2)

{
  undefined8 local_d8;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  code *local_b8;
  code *local_b0;
  undefined4 local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_80;
  undefined1 local_7c;
  undefined2 local_7a;
  undefined2 local_6e;
  code *local_60;
  code *local_58;
  undefined4 local_20;
  undefined4 local_1c;
  
  MemFastZero(&local_d8,0xd0);
  local_d8._0_4_ = 0xd0;
  local_d0 = MegaSASInitialize;
  local_80 = 0x1010102;
  local_b8 = MegaSASFindAdapter;
  local_8c = 2;
  local_c8 = MegaSASStartIo;
  local_d8._4_4_ = 5;
  local_58 = MegaSASBuildIo;
  local_7c = 1;
  local_c0 = LegacyInterrupts;
  local_b0 = MegaSASResetBus;
  local_60 = MegaSASPnPControl;
  local_6e = 4;
  local_7a = 4;
  local_20 = 0x20;
  local_1c = 1;
  local_98 = 0x6dc0;
  local_90 = 0x700;
  StorPortInitialize(param_1,param_2,&local_d8,0);
  return;
}



===== MegaSASFindAdapter @ 140005b00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
MegaSASFindAdapter(uint *param_1,undefined8 param_2,undefined8 param_3,char *param_4,
                  longlong param_5,undefined1 *param_6)

{
  undefined **ppuVar1;
  ushort uVar2;
  char cVar3;
  ushort uVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  short sVar9;
  uint uVar10;
  longlong lVar11;
  ulonglong uVar12;
  byte bVar13;
  longlong lVar14;
  int iVar15;
  ulonglong uVar16;
  uint *puVar17;
  undefined8 *puVar18;
  ulonglong *puVar19;
  uint uVar20;
  longlong lVar21;
  ushort uVar22;
  undefined1 auStack_1a8 [32];
  ushort *local_188;
  uint local_180;
  undefined4 local_178;
  uint local_168;
  undefined1 local_164 [4];
  uint local_160;
  undefined1 *local_158;
  ushort local_148;
  ushort local_146;
  undefined8 auStack_144 [6];
  byte local_114;
  undefined1 local_10c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_1a8;
  local_168 = 0;
  local_158 = param_6;
  local_160 = 0;
  uVar22 = 0x41;
  *param_6 = 0;
  *(undefined1 *)((longlong)param_1 + 0x6451) = 0;
  if (*(longlong *)(param_1 + 0x20) != 0) {
    MemFastZero((undefined8 *)param_1,0x6dc0);
  }
  MemFastZero((undefined8 *)&local_148,0x100);
  local_188 = &local_148;
  local_180 = 0x100;
  StorPortGetBusData(param_1,4,*(undefined4 *)(param_5 + 4),*(undefined4 *)(param_5 + 100));
  uVar6 = 0;
  while (((uint)local_148 != (&DAT_14000f2e8)[uVar6 * 8] ||
         ((uint)local_146 != (&DAT_14000f2ec)[uVar6 * 8]))) {
    bVar13 = (char)uVar6 + 1;
    uVar6 = (ulonglong)bVar13;
    if (0xc < bVar13) {
      local_178 = 0x10;
      local_180 = 6;
      local_188 = (ushort *)CONCAT71(local_188._1_7_,0xff);
      StorPortLogError(param_1,0,0xff);
      *(undefined1 *)(param_1 + 0x1915) = 1;
      return 0;
    }
  }
  lVar11 = uVar6 * 0x20;
  lVar21 = 0;
  bVar13 = *(byte *)(lVar11 + 0x14000f2f8);
  *(undefined1 *)((longlong)param_1 + 0x6469) = *(undefined1 *)(lVar11 + 0x14000f2fa);
  *(undefined1 *)((longlong)param_1 + 0x1cf) = *(undefined1 *)(lVar11 + 0x14000f2f9);
  *(short *)(param_1 + 0x74) = *(short *)(lVar11 + 0x14000f2fc) + -1;
  ppuVar1 = *(undefined ***)(lVar11 + 0x14000f2f0);
  *(undefined ***)(param_1 + 0x5e) = ppuVar1;
  *(bool *)(param_1 + 0x191a) = ppuVar1 == &PTR_MPT_InitializeQueues_14000f270;
  if ((*(char *)(*(longlong *)(param_5 + 0x38) + 0xc) == '\0') &&
     (*(char *)(*(longlong *)(param_5 + 0x38) + 0x1c) != '\0')) {
    lVar21 = 1;
  }
  param_1[2] = *(uint *)(param_5 + 4);
  *(byte *)(param_1 + 3) = *(byte *)(param_5 + 100) & 0x1f;
  *(byte *)((longlong)param_1 + 0xd) = (byte)(*(uint *)(param_5 + 100) >> 5) & 7;
  *(undefined1 *)((longlong)param_1 + 0xe) = local_10c;
  param_1[0x16] = (uint)*(byte *)(param_5 + 0x66);
  MemFastMove((undefined8 *)(param_1 + 4),(undefined8 *)&local_148,0x40);
  MemFastMove((undefined8 *)(param_1 + 0x14),
              (undefined8 *)((longlong)auStack_144 + ((ulonglong)local_114 - 4)),8);
  MemFastMove((undefined8 *)(param_1 + 0x15),
              (undefined8 *)((longlong)auStack_144 + (ulonglong)local_114),4);
  local_180 = local_180 & 0xffffff00;
  local_188 = (ushort *)CONCAT44(local_188._4_4_,0x2000);
  lVar11 = StorPortGetDeviceBase
                     (param_1,*(undefined4 *)(param_5 + 8),*(undefined4 *)(param_5 + 4),
                      *(undefined8 *)(lVar21 * 0x10 + *(longlong *)(param_5 + 0x38)));
  if (lVar11 == 0) {
    local_178 = 1;
    local_180 = 6;
    local_188 = (ushort *)CONCAT71(local_188._1_7_,0xff);
    StorPortLogError(param_1,0,0xff);
    *(undefined1 *)(param_1 + 0x1915) = 1;
    return 2;
  }
  *(longlong *)(param_1 + 0x20) = lVar11;
  *(undefined1 *)((longlong)param_1 + 0x48f2) = 1;
  GetRegistrySettings(param_4,(longlong)param_1);
  if (param_1[0x23] == 0) {
    param_1[0x23] = 4;
  }
  if (((char)param_1[0x22] == '\0') && (DAT_14000f634 = DAT_14000f634 + 1, 0x20 < DAT_14000f634)) {
    local_178 = 10;
    local_180 = 6;
    local_188 = (ushort *)CONCAT71(local_188._1_7_,0xff);
    StorPortLogError(param_1,0,0xff);
    *(undefined1 *)(param_1 + 0x1915) = 1;
    return 0;
  }
  *(undefined1 *)((longlong)param_1 + 0x6453) = 1;
  param_1[0x1e] =
       (*(byte *)((longlong)param_1 + 0xd) & 7 | param_1[2] << 3) << 5 | (byte)param_1[3] & 0x1f;
  (**(code **)(*(longlong *)(param_1 + 0x5e) + 0x28))(param_1);
  *(undefined2 *)(param_1 + 0x1917) = 0x200;
  param_1[0x6c] = 0xff;
  uVar6 = WaitForFwareReadyWithRetry((longlong)param_1);
  if ((char)uVar6 == '\0') {
    local_178 = 0x12;
    goto LAB_14000660f;
  }
  param_1[0x224] = param_1[0x6b] & 0xffff;
  uVar10 = *(uint *)(*(longlong *)(param_1 + 0x20) + 0xb8) & 0xffff;
  if (*(char *)((longlong)param_1 + 0xba) != '\0') {
    uVar10 = 0;
  }
  uVar20 = param_1[0x224];
  param_1[0x225] = uVar10;
  uVar5 = uVar20;
  if (uVar20 < uVar10) {
    uVar5 = uVar10;
  }
  param_1[0x223] = uVar5;
  param_1[0x224] = uVar20 - 2;
  if ((char)param_1[0x22] != '\0') {
    *(undefined1 *)((longlong)param_1 + 0x646a) = 0;
    uVar10 = 0x10;
    if (uVar5 < 0x10) {
      uVar10 = uVar5;
    }
    param_1[0x223] = uVar10;
  }
  if (((char)param_1[0x191a] != '\0') && ((param_1[0x223] & 0xf) != 0)) {
    param_1[0x223] = param_1[0x223] & 0xfffffff0;
  }
  uVar10 = param_1[0x26];
  uVar5 = param_1[0x223] - 5;
  param_1[0x226] = uVar5;
  if (0x14 < uVar10) {
    if (uVar10 < uVar5) {
      uVar5 = uVar10;
    }
    param_1[0x226] = uVar5;
  }
  uVar10 = param_1[0x25];
  param_1[0x227] = param_1[0x223] + 0x10;
  param_1[0x66] = 10;
  if (uVar10 != 0) {
    uVar5 = param_1[0x66];
    if (uVar10 <= uVar20 - 2 >> 2) {
      uVar5 = uVar10;
    }
    param_1[0x66] = uVar5;
  }
  *(undefined2 *)(param_5 + 0x51) = 0x101;
  *(undefined1 *)(param_5 + 0x53) = 1;
  if (*(char *)(param_5 + 0x90) < '\0') {
    *(undefined1 *)((longlong)param_1 + 0x1d3) = 1;
    *(undefined1 *)(param_5 + 0x90) = 1;
  }
  else {
    *(undefined1 *)((longlong)param_1 + 0x1d3) = 0;
  }
  if ((local_146 == 0x5d) || (param_1[0x225] != 0)) {
    if (param_1[0x226] < 0x3e9) {
      *(undefined4 *)(param_5 + 0xcc) = 1000;
      *(undefined1 *)((longlong)param_1 + 0x91) = 0;
    }
    else {
      *(uint *)(param_5 + 0xcc) = param_1[0x226];
    }
  }
  *(undefined1 *)((longlong)param_1 + 0x48f1) = 1;
  if ((bVar13 != 0) && ((param_1[0x6b] & 0x6000000) != 0)) {
    *(undefined1 *)(param_1 + 0x123c) = 1;
  }
  if (((char)param_1[0x22] == '\0') &&
     (cVar3 = RtlIsNtDdiVersionAvailable(0x6000000), cVar3 == '\0')) {
    *(undefined1 *)(param_1 + 0x123c) = 0;
    *(undefined1 *)((longlong)param_1 + 0x48f2) = 0;
  }
  uVar10 = *(uint *)(*(longlong *)(param_1 + 0x20) + 0xb4);
  if ((char)param_1[0x123c] == '\0') {
    *(undefined1 *)((longlong)param_1 + 0x48f2) = 0;
  }
  else {
    *(undefined4 *)(param_5 + 0xa0) = 2;
    *(code **)(param_5 + 0x98) = MessageInterrupts;
    if ((char)param_1[0x22] == '\0') {
      *(byte *)((longlong)param_1 + 0x48f1) = bVar13;
      if (*(char *)((longlong)param_1 + 0x6469) == '\0') {
        if (((char)param_1[0x191a] != '\0') && (uVar20 = (uVar10 & 0x1f) + 1, uVar20 < bVar13)) {
          *(char *)((longlong)param_1 + 0x48f1) = (char)uVar20;
        }
      }
      else {
        lVar11 = 0x10;
        *(longlong *)(param_1 + 0x1b2e) = *(longlong *)(param_1 + 0x20) + 0x6c;
        uVar20 = (uVar10 >> 0xe & 0xff) + 1;
        lVar21 = 0xf;
        puVar17 = param_1 + 0x1b30;
        do {
          lVar14 = *(longlong *)(param_1 + 0x20) + 0x30c + lVar11;
          lVar11 = lVar11 + 0x10;
          *(longlong *)puVar17 = lVar14;
          lVar21 = lVar21 + -1;
          puVar17 = puVar17 + 2;
        } while (lVar21 != 0);
        if (uVar20 < *(byte *)((longlong)param_1 + 0x48f1)) {
          *(char *)((longlong)param_1 + 0x48f1) = (char)uVar20;
        }
      }
      bVar13 = (byte)param_1[0x24];
      if ((bVar13 != 0) && (bVar13 < *(byte *)((longlong)param_1 + 0x48f1))) {
        *(byte *)((longlong)param_1 + 0x48f1) = bVar13;
      }
    }
  }
  if (((char)param_1[0x191a] != '\0') && ((char)param_1[0x22] == '\0')) {
    sVar9 = 0x80;
    uVar20 = uVar10 >> 0x16 & 1;
    if (uVar20 != 0) {
      sVar9 = 0x200;
    }
    uVar2 = ((ushort)(uVar10 >> 5) & 0x1f) * sVar9;
    cVar3 = '\x10';
    *(bool *)((longlong)param_1 + 0x6db1) = uVar20 != 0;
    uVar4 = 0x8000;
    uVar22 = (uVar2 >> 4) + 7;
    do {
      if ((uVar22 & uVar4) != 0) {
        uVar22 = uVar4 + 1;
        break;
      }
      uVar4 = uVar4 >> 1;
      cVar3 = cVar3 + -1;
    } while (cVar3 != '\0');
    *(int *)(param_5 + 0x8c) = *(int *)(param_5 + 0x8c) + (uVar2 - 0x400);
  }
  uVar2 = (ushort)param_1[0x74];
  iVar15 = (uint)uVar2 * 0xb + (param_1[0x223] + 0x931) * 8;
  if ((char)param_1[0x22] == '\0') {
    iVar15 = iVar15 + (uint)uVar2 * 0x201 + 0xfc820;
  }
  uVar10 = param_1[0x226];
  if ((char)param_1[0x191a] == '\0') {
    local_168 = uVar2 + 0x100 +
                ((uint)uVar2 + (param_1[0x223] + 4) * 4) *
                (uint)*(byte *)((longlong)param_1 + 0x48f1);
    uVar20 = local_160;
  }
  else {
    uVar20 = MPT_GetMemLenToAlloc((longlong)param_1);
  }
  uVar5 = (uint)uVar22;
  if ((char)param_1[0x191a] == '\0') {
    uVar5 = (uint)*(byte *)((longlong)param_1 + 0x1ae);
  }
  *(uint *)(param_5 + 0x1c) = uVar5;
  uVar10 = iVar15 + uVar10 * 0x12 + uVar20 + local_168;
  *(undefined4 *)(param_5 + 0x18) = 0x3fffff;
  puVar7 = (undefined8 *)StorPortGetUncachedExtension(param_1,param_5,uVar10);
  if (puVar7 == (undefined8 *)0x0) {
    local_178 = 2;
    goto LAB_14000660f;
  }
  MemFastZero(puVar7,uVar10);
  uVar6 = (ulonglong)(ushort)param_1[0x74];
  puVar18 = (undefined8 *)((longlong)puVar7 + uVar6 & (longlong)(int)~(uint)(ushort)param_1[0x74]);
  *(undefined8 **)(param_1 + 0x30) = puVar18;
  MemFastMove(puVar18,(undefined8 *)"PercSas3.sys",0xc);
  *(undefined1 *)(*(longlong *)(param_1 + 0x30) + 0xc) = 0x20;
  MemFastMove((undefined8 *)(*(longlong *)(param_1 + 0x30) + 0xd),(undefined8 *)&s_6_604_06_00,0xc);
  *(undefined1 *)(*(longlong *)(param_1 + 0x30) + 0x18) = 0;
  uVar16 = (longlong)puVar7 + (ulonglong)(ushort)param_1[0x74] + uVar6 + 0x80 &
           (longlong)(int)~(uint)(ushort)param_1[0x74];
  *(ulonglong *)(param_1 + 0x46) = uVar16;
  uVar8 = StorPortGetPhysicalAddress(param_1,0,uVar16,local_164);
  *(undefined8 *)(param_1 + 0x48) = uVar8;
  uVar2 = (ushort)param_1[0x74];
  lVar11 = (ulonglong)uVar2 + uVar6 + 0x1888;
  uVar6 = (longlong)puVar7 + (ulonglong)uVar2 + lVar11 & (longlong)(int)~(uint)uVar2;
  *(ulonglong *)(param_1 + 0x4a) = uVar6;
  uVar8 = StorPortGetPhysicalAddress(param_1,0,uVar6,local_164);
  *(undefined8 *)(param_1 + 0x4c) = uVar8;
  uVar2 = (ushort)param_1[0x74];
  lVar11 = (ulonglong)uVar2 + lVar11 + 0x100;
  uVar6 = (longlong)puVar7 + (ulonglong)uVar2 + lVar11 & (longlong)(int)~(uint)uVar2;
  *(ulonglong *)(param_1 + 0x4e) = uVar6;
  uVar8 = StorPortGetPhysicalAddress(param_1,0,uVar6,local_164);
  *(undefined8 *)(param_1 + 0x50) = uVar8;
  uVar2 = (ushort)param_1[0x74];
  lVar11 = (ulonglong)uVar2 + lVar11 + 0x800;
  uVar6 = (longlong)puVar7 + (ulonglong)uVar2 + lVar11 & (longlong)(int)~(uint)uVar2;
  *(ulonglong *)(param_1 + 0x52) = uVar6;
  uVar8 = StorPortGetPhysicalAddress(param_1,0,uVar6,local_164);
  *(undefined8 *)(param_1 + 0x54) = uVar8;
  uVar2 = (ushort)param_1[0x74];
  lVar11 = (ulonglong)uVar2 + lVar11 + 0x200;
  uVar6 = (longlong)puVar7 + (ulonglong)uVar2 + lVar11 & (longlong)(int)~(uint)uVar2;
  *(ulonglong *)(param_1 + 0x56) = uVar6;
  uVar8 = StorPortGetPhysicalAddress(param_1,0,uVar6,local_164);
  uVar2 = (ushort)param_1[0x74];
  uVar6 = (ulonglong)uVar2;
  lVar11 = (longlong)puVar7 + uVar6 + lVar11 + 0x800;
  *(undefined8 *)(param_1 + 0x58) = uVar8;
  uVar16 = (ulonglong)(uint)uVar2;
  if ((char)param_1[0x22] == '\0') {
    uVar6 = (ulonglong)(int)~(uint)uVar2;
    uVar12 = uVar16 * 0x101 + 0xc0800 + lVar11;
    *(ulonglong *)(param_1 + 0x1924) = lVar11 + uVar16 & uVar6;
    uVar6 = uVar12 & uVar6;
    lVar21 = uVar12 + 0x10020;
    *(ulonglong *)(param_1 + 0x1f8) = uVar6;
    StorPortQuerySystemTime(uVar6 + 0x10010);
    uVar2 = (ushort)param_1[0x74];
    uVar6 = (ulonglong)uVar2;
    uVar16 = (ulonglong)uVar2;
    lVar11 = lVar21 + (uVar6 + 0x2c0) * 0x100;
    *(ulonglong *)(param_1 + 0x1926) = lVar21 + uVar6 & (longlong)(int)~(uint)uVar2;
  }
  puVar17 = param_1 + 0x3c;
  lVar21 = 5;
  do {
    uVar6 = uVar16 + lVar11 & (longlong)(int)~(uint)uVar6;
    *(ulonglong *)(puVar17 + -10) = uVar6;
    lVar14 = StorPortGetPhysicalAddress(param_1,0,uVar6,local_164);
    *(longlong *)puVar17 = lVar14 + 0x100;
    puVar17 = puVar17 + 2;
    uVar6 = (ulonglong)(ushort)param_1[0x74];
    lVar11 = lVar11 + 0x600 + uVar6;
    uVar16 = (ulonglong)(ushort)param_1[0x74];
    lVar21 = lVar21 + -1;
  } while (lVar21 != 0);
  uVar2 = (ushort)param_1[0x74];
  *(ulonglong *)(param_1 + 0x60) = lVar11 + (ulonglong)uVar2 & (longlong)(int)~(uint)uVar2;
  lVar11 = lVar11 + (ulonglong)uVar2 + (ulonglong)param_1[0x223] * 8;
  *(longlong *)(param_1 + 0x5a) = lVar11;
  uVar8 = StorPortGetPhysicalAddress(param_1,0,lVar11,local_164);
  *(undefined8 *)(param_1 + 0x5c) = uVar8;
  lVar11 = lVar11 + (ulonglong)param_1[0x226] * 0x12;
  if ((char)param_1[0x191a] == '\0') {
    uVar2 = (ushort)param_1[0x74];
    uVar16 = (ulonglong)uVar2;
    bVar13 = 0;
    uVar12 = lVar11 + uVar16 & (longlong)(int)~(uint)uVar2;
    *(ulonglong *)(param_1 + 0x1918) = uVar12;
    uVar6 = lVar11 + (ulonglong)*(byte *)((longlong)param_1 + 0x48f1) * 0x10 + uVar16;
    if (*(byte *)((longlong)param_1 + 0x48f1) != 0) {
      puVar19 = (ulonglong *)(uVar12 + 8);
      do {
        bVar13 = bVar13 + 1;
        *puVar19 = uVar6 + uVar2 & (longlong)(int)~(uint)uVar16;
        uVar2 = (ushort)param_1[0x74];
        uVar16 = (ulonglong)uVar2;
        uVar6 = uVar6 + uVar16 + (ulonglong)param_1[0x223] * 4;
        puVar19 = puVar19 + 2;
      } while (bVar13 < *(byte *)((longlong)param_1 + 0x48f1));
    }
    if ((ulonglong)local_168 + lVar11 < uVar6) {
LAB_140006587:
      local_178 = 0x11;
      goto LAB_14000660f;
    }
  }
  else {
    uVar8 = MPT_InitMessageMem((longlong)param_1,lVar11,(ulonglong)uVar20);
    if ((char)uVar8 == '\0') goto LAB_140006587;
  }
  uVar10 = 0x10;
  if (param_1[0x2a] != 0) {
    uVar10 = param_1[0x2a];
  }
  param_1[0x1230] = uVar10;
  uVar10 = param_1[0x29];
  if (uVar10 == 0) {
    uVar20 = 4;
    if (*(char *)((longlong)param_1 + 0x6469) != '\0') {
      uVar20 = 1;
    }
    param_1[0x1231] = uVar20;
  }
  else {
    param_1[0x1231] = uVar10;
  }
  if (uVar10 == 0) {
    param_1[0x2c] = 0x10;
  }
  else {
    param_1[0x2c] = param_1[0x2b];
  }
  uVar8 = WaitForInitializeWithRetry(param_1);
  if ((char)uVar8 == '\0') {
    local_178 = 9;
LAB_14000660f:
    local_180 = 6;
    local_188 = (ushort *)CONCAT71(local_188._1_7_,0xff);
    StorPortLogError(param_1,0,0xff);
    *(undefined1 *)(param_1 + 0x1915) = 1;
    return 2;
  }
  if ((char)param_1[0x191a] != '\0') {
    *(undefined1 *)((longlong)param_1 + 0x1d2) = 1;
    param_1[0x221] = (uint)uVar22;
    param_1[0x220] = (uint)uVar22 * 0x1000 - 0x1000;
    uVar10 = (uint)*(byte *)((longlong)param_1 + 0x1ae);
    if ((uint)uVar22 < (uint)*(byte *)((longlong)param_1 + 0x1ae)) {
      uVar10 = (uint)uVar22;
    }
    goto LAB_1400066ff;
  }
  if ((param_1[0x6b] >> 0x1a & 1) != 0) {
    *(undefined1 *)((longlong)param_1 + 0x1d2) = 1;
  }
  if ((param_1[0x6b] >> 0x19 & 1) != 0) {
    *(undefined1 *)((longlong)param_1 + 0x1ce) = 1;
  }
  bVar13 = *(byte *)((longlong)param_1 + 0x1ae);
  if (*(char *)((longlong)param_1 + 0x1d2) == '\0') {
    if (*(char *)((longlong)param_1 + 0x1d3) == '\0') {
      if (bVar13 < 0x79) goto LAB_1400066ec;
      uVar10 = 0x78;
    }
    else if (bVar13 < 0x51) {
LAB_1400066ec:
      uVar10 = (uint)bVar13;
    }
    else {
      uVar10 = 0x50;
    }
    param_1[0x220] = 0x80000;
  }
  else if (bVar13 < 0x3d) {
    uVar10 = (uint)bVar13;
    param_1[0x220] = 0x20000;
  }
  else {
    uVar10 = 0x3c;
    param_1[0x220] = 0x20000;
  }
  param_1[0x221] = uVar10;
LAB_1400066ff:
  uVar20 = param_1[0x27];
  param_1[0x222] = uVar10;
  if (uVar20 != 0) {
    uVar10 = uVar20 >> 0xc;
    if (param_1[0x221] < uVar20 >> 0xc) {
      uVar10 = param_1[0x221];
    }
    uVar5 = param_1[0x220];
    if (uVar20 <= uVar10 * 0x1000) {
      uVar5 = uVar20;
    }
    param_1[0x220] = uVar5;
  }
  *(uint *)(param_5 + 0x18) = param_1[0x220];
  *(uint *)(param_5 + 0x1c) = param_1[0x221];
  *(undefined2 *)(param_5 + 0x48) = 0x702;
  *(undefined1 *)(param_5 + 0x61) = 0xff;
  *(undefined1 *)(param_5 + 0x92) = 8;
  *(undefined4 *)(param_5 + 0x94) = 1;
  if ((char)param_1[0x22] == '\0') {
    local_168 = 0xfe000072;
    param_1[0x20f] = 0xfe000072;
    *(undefined1 *)(param_5 + 0x93) = 1;
    MegaSASWmiInitialize((longlong)param_1);
  }
  *local_158 = 1;
  return 1;
}



===== MegaSASPnPControl @ 1400067b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 MegaSASPnPControl(int *param_1,int param_2,uint *param_3)

{
  bool bVar1;
  undefined8 uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined1 auStack_68 [32];
  undefined1 local_48;
  undefined4 local_40;
  undefined4 local_38;
  undefined4 local_28;
  undefined1 local_24;
  undefined8 local_23;
  undefined4 local_1b;
  undefined1 local_17;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  uVar2 = 0;
  if (param_2 == 0) {
    if (param_3 != (uint *)0x0) {
      local_28 = 0x10101;
      local_24 = 0;
      local_23 = 0;
      local_1b = 0;
      local_17 = 0;
      uVar4 = 0;
      if (*param_3 != 0) {
        do {
          uVar3 = (int)uVar4 + 1;
          *(undefined1 *)((longlong)param_3 + uVar4 + 4) =
               *(undefined1 *)((longlong)&local_28 + uVar4);
          uVar4 = (ulonglong)uVar3;
        } while (uVar3 < *param_3);
      }
    }
  }
  else if (param_2 == 1) {
    DAT_14000f634 = DAT_14000f634 + -1;
    *(undefined1 *)((longlong)param_1 + 0x1b5) = 0;
    if (param_1[0x1b4f] != 1) {
      *(undefined1 *)((longlong)param_1 + 0x6453) = 1;
      (**(code **)(*(longlong *)(param_1 + 0x5e) + 0x28))();
      if ((char)param_1[0x1915] == '\0') {
        *(undefined2 *)(param_1 + 0x1917) = 0;
        AbortPendedCommands((longlong)param_1);
        param_1[0x1916] = 180000000;
        bVar1 = SendAndWaitDCMD(param_1,0x1101000);
        if (!bVar1) {
          local_38 = 0x13;
          local_40 = 6;
          local_48 = 0xff;
          StorPortLogError(param_1,0,0xff);
        }
        param_1[0x1916] = 180000000;
        uVar3 = 0x1060000;
        if (*(char *)((longlong)param_1 + 0x1d7) != '\0') {
          uVar3 = 0x1050000;
        }
        bVar1 = SendAndWaitDCMD(param_1,uVar3);
        if (!bVar1) {
          local_38 = 0x13;
          local_40 = 6;
          local_48 = 0xff;
          StorPortLogError(param_1,0,0xff);
        }
      }
    }
  }
  else if (param_2 == 2) {
    *(undefined1 *)((longlong)param_1 + 0x6453) = 1;
    (**(code **)(*(longlong *)(param_1 + 0x5e) + 0x28))();
    DoPauseInput((longlong)param_1);
    DAT_14000f634 = DAT_14000f634 + '\x01';
    *(undefined1 *)((longlong)param_1 + 0x1d7) = 0;
    *(undefined2 *)(param_1 + 0x1917) = 0x200;
    *(undefined2 *)(param_1 + 0x6d) = 0;
    param_1[0x68] = 0;
    MemFastZero(*(undefined8 **)(param_1 + 0x60),param_1[0x226] << 3);
    param_1[0x1916] = 600000000;
    StorPortNotification(6,param_1,TimeForFwareReadyInitWithRetry,250000);
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



===== CopyPerfMetricData @ 1400069a0 =====

ulonglong CopyPerfMetricData(longlong param_1,longlong param_2)

{
  short *psVar1;
  longlong lVar2;
  uint *puVar3;
  byte bVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint uVar7;
  longlong lVar8;
  longlong lVar9;
  byte bVar10;
  
  bVar4 = *(byte *)(param_1 + 0x1d8);
  bVar10 = 0;
  if (bVar4 != 0) {
    lVar9 = 0;
    lVar8 = 0xf808;
    do {
      puVar3 = (uint *)(*(longlong *)(param_1 + 0x7e0) + 0xc + lVar9);
      *puVar3 = *puVar3 >> 0xb;
      puVar3 = (uint *)(*(longlong *)(param_1 + 0x7e0) + 0x10 + lVar9);
      *puVar3 = *puVar3 >> 0xb;
      *(byte *)(*(longlong *)(param_1 + 0x7e0) + 4 + lVar9) = bVar10;
      bVar10 = bVar10 + 1;
      lVar6 = param_2 - *(longlong *)(lVar8 + *(longlong *)(param_1 + 0x7e0));
      lVar2 = lVar9 + *(longlong *)(param_1 + 0x7e0);
      lVar9 = lVar9 + 0x78;
      lVar6 = SUB168(SEXT816(-0x29406b2a1a85bd43) * SEXT816(lVar6),8) + lVar6;
      psVar1 = (short *)(lVar2 + 6);
      *psVar1 = *psVar1 + ((short)(lVar6 >> 0x17) - (short)(lVar6 >> 0x3f));
      lVar8 = lVar8 + 8;
    } while (bVar10 < bVar4);
  }
  uVar7 = (int)param_2 - *(int *)(*(longlong *)(param_1 + 0x7e0) + 0x10010);
  uVar5 = (ulonglong)uVar7 * 0x6b5fca6b & 0xffffffff;
  *(uint *)(*(longlong *)(param_1 + 0x7e0) + 0x10018) = uVar7 / 10000000;
  if (*(char *)(param_1 + 0x1d8) != '\0') {
    MemFastMove((undefined8 *)(*(longlong *)(param_1 + 0x7e0) + 0x7804),
                (undefined8 *)(*(longlong *)(param_1 + 0x7e0) + 4),(uint)bVar4 * 0x78);
    uVar5 = MemFastZero((undefined8 *)(*(longlong *)(param_1 + 0x7e0) + 4),(uint)bVar4 * 0x78);
  }
  return uVar5;
}



===== ProcessPerfMetricAEN @ 140006ac0 =====

void ProcessPerfMetricAEN(longlong param_1,int param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong local_res18 [2];
  
  StorPortQuerySystemTime(local_res18);
  if (param_2 == 0) {
    if (**(char **)(param_1 + 0x7e0) != '\0') {
      CopyPerfMetricData(param_1,local_res18[0]);
    }
    lVar2 = 0x100;
    *(longlong *)(*(longlong *)(param_1 + 0x7e0) + 0x10010) = local_res18[0];
    lVar1 = 0xf808;
    do {
      *(longlong *)(lVar1 + *(longlong *)(param_1 + 0x7e0)) = local_res18[0];
      lVar2 = lVar2 + -1;
      lVar1 = lVar1 + 8;
    } while (lVar2 != 0);
    **(undefined1 **)(param_1 + 0x7e0) = 1;
  }
  else if ((param_2 == 1) && (**(char **)(param_1 + 0x7e0) != '\0')) {
    **(char **)(param_1 + 0x7e0) = '\0';
    CopyPerfMetricData(param_1,local_res18[0]);
    return;
  }
  return;
}



===== ProcessPerfMetricRequest @ 140006b80 =====

void ProcessPerfMetricRequest(longlong param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint7 uVar5;
  
  uVar5 = (uint7)(uint3)(param_3 >> 8);
  if (param_3 < 0x184) {
    StorPortLogError(param_1,0,0xff,CONCAT71(uVar5,0xff),0xff,6,0x40);
    return;
  }
  uVar1 = *param_2;
  uVar3 = (ulonglong)uVar1;
  if (uVar1 < 0x104) {
    StorPortLogError(param_1,0,0xff,CONCAT71(uVar5,0xff),0xff,6,0x41);
    return;
  }
  uVar4 = (uint)*(byte *)(param_1 + 0x1d8);
  if (0x100 < *(byte *)(param_1 + 0x1d8)) {
    uVar4 = 0x100;
  }
  uVar4 = uVar4 * 0x78;
  if (uVar4 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = uVar4 + 8;
  }
  if (param_3 < uVar1 + 8 + uVar4) {
    param_2[0x41] = uVar2;
    param_2[0x42] = *(uint *)(*(longlong *)(param_1 + 0x7e0) + 0x10018);
    return;
  }
  *(uint *)((longlong)param_2 + uVar3) = uVar2;
  *(undefined4 *)((longlong)param_2 + uVar3 + 4) =
       *(undefined4 *)(*(longlong *)(param_1 + 0x7e0) + 0x10018);
  if (uVar4 == 0) {
    return;
  }
  MemFastMove((undefined8 *)((longlong)param_2 + uVar3 + 8),
              (undefined8 *)(*(longlong *)(param_1 + 0x7e0) + 0x7804),uVar4);
  return;
}



===== UpdateIOMetric @ 140006c80 =====

void UpdateIOMetric(longlong param_1,byte param_2,char param_3,longlong param_4,int param_5,
                   uint param_6)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  longlong lVar4;
  int *piVar5;
  uint uVar6;
  ulonglong uVar7;
  int *piVar8;
  ulonglong uVar9;
  
  if ((*(char *)(param_1 + 0x88) == '\0') && (pcVar3 = *(char **)(param_1 + 0x7e0), *pcVar3 != '\0')
     ) {
    uVar7 = param_4 * (ulonglong)(param_6 >> 9);
    uVar6 = param_5 * (param_6 >> 9);
    uVar9 = (ulonglong)param_2;
    lVar4 = uVar9 * 0x78;
    if (param_3 == '\0') {
      pcVar1 = pcVar3 + 0x2c;
      pcVar2 = pcVar3 + 0x60;
      *(uint *)(pcVar3 + lVar4 + 0x10) = *(int *)(pcVar3 + lVar4 + 0x10) + uVar6;
    }
    else {
      pcVar1 = pcVar3 + 0x14;
      pcVar2 = pcVar3 + 0x44;
      *(uint *)(pcVar3 + lVar4 + 0xc) = *(int *)(pcVar3 + lVar4 + 0xc) + uVar6;
    }
    piVar8 = (int *)(pcVar1 + lVar4);
    piVar5 = (int *)(pcVar2 + lVar4);
    StorPortQuerySystemTime(*(longlong *)(param_1 + 0x7e0) + 0xf808 + uVar9 * 8);
    if (uVar6 < 2) {
      *piVar8 = *piVar8 + 1;
    }
    else if (uVar6 < 9) {
      piVar8[1] = piVar8[1] + 1;
    }
    else if (uVar6 < 0x21) {
      piVar8[2] = piVar8[2] + 1;
    }
    else if (uVar6 < 0x81) {
      piVar8[3] = piVar8[3] + 1;
    }
    else if (uVar6 < 0x101) {
      piVar8[4] = piVar8[4] + 1;
    }
    else {
      piVar8[5] = piVar8[5] + 1;
    }
    uVar9 = *(ulonglong *)(*(longlong *)(param_1 + 0x7e0) + 0xf008 + uVar9 * 8);
    if (uVar9 == uVar7) {
      *piVar5 = *piVar5 + 1;
      return;
    }
    if (uVar9 + 0x80 <= uVar7) {
      piVar5[1] = piVar5[1] + 1;
      return;
    }
    if (uVar9 + 0x400 <= uVar7) {
      piVar5[2] = piVar5[2] + 1;
      return;
    }
    if (uVar9 + 0x8000 <= uVar7) {
      piVar5[3] = piVar5[3] + 1;
      return;
    }
    if (uVar9 + 0x80000 <= uVar7) {
      piVar5[4] = piVar5[4] + 1;
      return;
    }
    if (uVar9 + 0x200000 <= uVar7) {
      piVar5[5] = piVar5[5] + 1;
      return;
    }
    piVar5[6] = piVar5[6] + 1;
  }
  return;
}



===== MFI_BuildFrame_NonRW @ 140006e30 =====

longlong MFI_BuildFrame_NonRW(longlong param_1,longlong *param_2)

{
  byte *pbVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  int iVar7;
  undefined1 local_res10 [8];
  
  lVar6 = *param_2;
  pbVar1 = (byte *)(param_2 + 0x20);
  *(undefined1 *)(param_2 + 0xd) = 1;
  *(undefined2 *)((longlong)param_2 + 0x101) = 0;
  param_2[0x21] = 0;
  *(undefined4 *)(param_2 + 0x21) = 0;
  *(undefined2 *)(param_2 + 0x22) = 0;
  param_2[0x23] = 0;
  *(undefined1 *)((longlong)param_2 + 0x103) = 0;
  if (*(char *)(lVar6 + 5) == '\0') {
    *pbVar1 = 4;
    *(undefined1 *)((longlong)param_2 + 0x105) = *(undefined1 *)(lVar6 + 7);
  }
  else {
    *pbVar1 = 3;
    *(undefined1 *)((longlong)param_2 + 0x105) = 0;
  }
  *(undefined1 *)((longlong)param_2 + 0x104) = *(undefined1 *)(lVar6 + 6);
  if ((*(uint *)(lVar6 + 0xc) & 0xc0) == 0) {
    *(undefined2 *)(param_2 + 0x22) = 0;
  }
  if ((char)*(undefined4 *)(lVar6 + 0xc) < '\0') {
    *(undefined2 *)(param_2 + 0x22) = 8;
  }
  if ((*(uint *)(lVar6 + 0xc) & 0x40) != 0) {
    *(ushort *)(param_2 + 0x22) = *(ushort *)(param_2 + 0x22) | 0x10;
  }
  param_2[8] = (longlong)(param_2 + 0x26);
  param_2[7] = (longlong)(param_2 + 0x26);
  if ((*(int *)(lVar6 + 0x10) != 0) &&
     (lVar5 = BuildSGLforSRB(param_1,param_2), (char)lVar5 == '\0')) {
    *(undefined1 *)(lVar6 + 3) = 4;
    return lVar5;
  }
  *(char *)((longlong)param_2 + 0x107) = *(char *)((longlong)param_2 + 0x34);
  if (*(char *)((longlong)param_2 + 0x34) != '\0') {
    iVar4 = ((uint)*(byte *)((longlong)param_2 + 0x36) * (uint)*(ushort *)((longlong)param_2 + 0x34)
             + *(int *)(&DAT_14000f490 + (ulonglong)*pbVar1 * 4) + 0x3f >> 6 & 0xff) - 1;
    iVar7 = 7;
    if (iVar4 < 7) {
      iVar7 = iVar4;
    }
    *(char *)((longlong)param_2 + 0x69) = (char)iVar7;
  }
  *(undefined1 *)((longlong)param_2 + 0x106) = *(undefined1 *)((longlong)param_2 + 0x54);
  *(undefined4 *)((longlong)param_2 + 0x114) = *(undefined4 *)(lVar6 + 0x10);
  uVar2 = *(ushort *)(param_2 + 0x22);
  uVar3 = (ushort)(*(byte *)((longlong)param_2 + 0x1a) & 1) * 2;
  *(ushort *)(param_2 + 0x22) = uVar3 | uVar2 & 0xfffd;
  *(ushort *)(param_2 + 0x22) =
       (ushort)(*(byte *)(param_1 + 0x1d2) & 1) << 5 | uVar3 | uVar2 & 0xffdd;
  *(undefined2 *)((longlong)param_2 + 0x112) = *(undefined2 *)(lVar6 + 0x14);
  MemFastMove(param_2 + 0x24,(undefined8 *)(lVar6 + 0x48),(uint)*(byte *)((longlong)param_2 + 0x54))
  ;
  lVar6 = StorPortGetPhysicalAddress(param_1,lVar6,pbVar1,local_res10);
  param_2[2] = lVar6;
  return CONCAT71((int7)((ulonglong)lVar6 >> 8),1);
}



===== MFI_BuildFrame_RW @ 140006fc0 =====

longlong MFI_BuildFrame_RW(longlong param_1,longlong *param_2)

{
  byte *pbVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  int iVar7;
  undefined1 uVar8;
  undefined1 local_res10 [8];
  
  lVar6 = *param_2;
  pbVar1 = (byte *)(param_2 + 0x20);
  *(undefined1 *)(param_2 + 0xd) = 1;
  uVar8 = 0;
  param_2[0x21] = 0;
  *(undefined4 *)(param_2 + 0x21) = 0;
  *(undefined2 *)((longlong)param_2 + 0x101) = 0;
  *(undefined2 *)(param_2 + 0x22) = 0;
  param_2[0x23] = 0;
  *(undefined1 *)((longlong)param_2 + 0x103) = 0;
  *pbVar1 = ((char)param_2[3] == '\0') + 1;
  *(undefined1 *)((longlong)param_2 + 0x104) = *(undefined1 *)(lVar6 + 6);
  if ((*(uint *)(lVar6 + 0xc) & 0xc0) == 0) {
    *(undefined2 *)(param_2 + 0x22) = 0;
  }
  if ((char)*(undefined4 *)(lVar6 + 0xc) < '\0') {
    *(undefined2 *)(param_2 + 0x22) = 8;
  }
  if ((*(uint *)(lVar6 + 0xc) & 0x40) != 0) {
    *(ushort *)(param_2 + 0x22) = *(ushort *)(param_2 + 0x22) | 0x10;
  }
  param_2[8] = (longlong)(param_2 + 0x25);
  param_2[7] = (longlong)(param_2 + 0x25);
  if (*(int *)(lVar6 + 0x10) != 0) {
    lVar5 = BuildSGLforSRB(param_1,param_2);
    if ((char)lVar5 == '\0') {
      *(undefined1 *)(lVar6 + 3) = 4;
      return lVar5;
    }
  }
  *(char *)((longlong)param_2 + 0x107) = *(char *)((longlong)param_2 + 0x34);
  if (*(char *)((longlong)param_2 + 0x34) != '\0') {
    iVar4 = ((uint)*(byte *)((longlong)param_2 + 0x36) * (uint)*(ushort *)((longlong)param_2 + 0x34)
             + *(int *)(&DAT_14000f490 + (ulonglong)*pbVar1 * 4) + 0x3f >> 6 & 0xff) - 1;
    iVar7 = 7;
    if (iVar4 < 7) {
      iVar7 = iVar4;
    }
    *(char *)((longlong)param_2 + 0x69) = (char)iVar7;
  }
  CDB_GetInfo(lVar6 + 0x48,*(char *)((longlong)param_2 + 0x54),(ulonglong *)(param_2 + 4),
              (uint *)(param_2 + 6));
  param_2[0x24] = param_2[4];
  *(int *)((longlong)param_2 + 0x114) = (int)param_2[6];
  uVar2 = *(ushort *)(param_2 + 0x22);
  uVar3 = (ushort)(*(byte *)((longlong)param_2 + 0x1a) & 1) * 2;
  *(ushort *)(param_2 + 0x22) = uVar3 | uVar2 & 0xfffd;
  *(ushort *)(param_2 + 0x22) =
       (ushort)(*(byte *)(param_1 + 0x1d2) & 1) << 5 | uVar3 | uVar2 & 0xffdd;
  if (*(char *)((longlong)param_2 + 0x54) != '\x06') {
    uVar8 = *(undefined1 *)(lVar6 + 0x49);
  }
  *(undefined1 *)((longlong)param_2 + 0x105) = uVar8;
  *(undefined2 *)((longlong)param_2 + 0x112) = *(undefined2 *)(lVar6 + 0x14);
  lVar6 = StorPortGetPhysicalAddress(param_1,lVar6,pbVar1,local_res10);
  param_2[2] = lVar6;
  return CONCAT71((int7)((ulonglong)lVar6 >> 8),1);
}



===== MFI_CompleteRequests @ 140007160 =====

undefined8 MFI_CompleteRequests(int *param_1,ulonglong param_2)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  int *piVar8;
  
  piVar8 = (int *)((param_2 & 0xffffffff) * 0x10 + *(longlong *)(param_1 + 0x1918));
  if (piVar8[1] == *piVar8) {
    (**(code **)(*(longlong *)(param_1 + 0x5e) + 0x18))();
    uVar7 = CheckFirmwareFault((longlong)param_1);
    if ((char)uVar7 == '\0') {
      return CONCAT71((int7)(uVar7 >> 8),1);
    }
  }
  else {
    while( true ) {
      iVar2 = *(int *)(*(longlong *)(piVar8 + 2) + (ulonglong)(uint)piVar8[1] * 4);
      uVar6 = piVar8[1] + 1;
      piVar8[1] = uVar6;
      if ((uint)param_1[0x223] <= uVar6) {
        uVar6 = 0;
      }
      piVar8[1] = uVar6;
      if (0x3ff < iVar2) break;
      lVar3 = *(longlong *)(param_1 + 0x60);
      plVar4 = *(longlong **)(lVar3 + (longlong)iVar2 * 8);
      if (plVar4 == (longlong *)0x0) {
        uVar7 = SetDeadAdapter((longlong)param_1,6);
        return uVar7 & 0xffffffffffffff00;
      }
      lVar5 = *plVar4;
      if (lVar5 == 0) {
        if (((char)plVar4[0x20] != '\x05') || (*(uint *)(plVar4 + 0x21) < (uint)param_1[0x226])) {
          uVar7 = SetDeadAdapter((longlong)param_1,7);
          return uVar7 & 0xffffffffffffff00;
        }
        CompleteDCMD(param_1,(longlong)(plVar4 + 0x20),'\0');
      }
      else {
        uVar6 = *(uint *)(plVar4 + 1);
        if (*(longlong **)(lVar3 + (ulonglong)uVar6 * 8) != plVar4) {
          uVar7 = SetDeadAdapter((longlong)param_1,0x21);
          return uVar7 & 0xffffffffffffff00;
        }
        *(undefined8 *)(lVar3 + (ulonglong)uVar6 * 8) = 0;
        param_1[0x62] = uVar6;
        LOCK();
        param_1[0x68] = param_1[0x68] + -1;
        UNLOCK();
        if (param_1[0x225] != 0) {
          LOCK();
          param_1[0x6a] = param_1[0x6a] + -1;
          UNLOCK();
        }
        if ((param_1[0x68] < 0) || ((param_1[0x225] != 0 && (param_1[0x6a] < 0)))) {
          uVar7 = SetDeadAdapter((longlong)param_1,0x25);
          return uVar7 & 0xffffffffffffff00;
        }
        cVar1 = *(char *)(lVar5 + 2);
        if (cVar1 == '\0') {
          *(undefined4 *)(plVar4 + 10) = *(undefined4 *)((longlong)plVar4 + 0x114);
          CompleteScsiRequest((longlong)param_1,plVar4,*(char *)((longlong)plVar4 + 0x102),
                              *(char *)((longlong)plVar4 + 0x103));
        }
        else if (cVar1 == '\b') {
          if (*(char *)((longlong)plVar4 + 0x102) == '\0') {
            *(undefined2 *)(lVar5 + 3) = 1;
            StorPortNotification(0,param_1);
          }
          else {
            *(undefined1 *)(lVar5 + 3) = 4;
            StorPortNotification(0,param_1);
          }
        }
        else if (cVar1 == '\x02') {
          CompleteIoctlRequest((longlong)param_1,plVar4);
        }
      }
      if (piVar8[1] == *piVar8) {
        return CONCAT71((uint7)(uint3)((uint)*piVar8 >> 8),1);
      }
    }
    uVar7 = SetDeadAdapter((longlong)param_1,0x22);
  }
  return uVar7 & 0xffffffffffffff00;
}



===== MFI_InitializeQueue @ 1400073b0 =====

bool MFI_InitializeQueue(longlong param_1,longlong param_2,uint *param_3)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined1 local_res8 [8];
  
  puVar1 = (undefined8 *)(param_2 + 0x100);
  MemFastZero(puVar1,0x40);
  MemFastZero((undefined8 *)param_3,0x40);
  uVar3 = *(uint *)(param_1 + 0x88c);
  *param_3 = *param_3 & 0xfffffffd;
  param_3[1] = uVar3;
  uVar4 = StorPortGetPhysicalAddress
                    (param_1,0,
                     *(undefined8 *)
                      (*(longlong *)(param_1 + 0x6460) + 8 +
                      (ulonglong)*(byte *)(param_1 + 0x645f) * 0x10),local_res8);
  if (0 < (int)((ulonglong)uVar4 >> 0x20)) {
    *param_3 = *param_3 | 1;
  }
  *(undefined8 *)(param_3 + 2) = uVar4;
  uVar4 = StorPortGetPhysicalAddress
                    (param_1,0,
                     (ulonglong)*(byte *)(param_1 + 0x645f) * 0x10 + *(longlong *)(param_1 + 0x6460)
                     ,local_res8);
  if (0 < (int)((ulonglong)uVar4 >> 0x20)) {
    *param_3 = *param_3 | 1;
  }
  *(undefined8 *)(param_3 + 4) = uVar4;
  uVar4 = StorPortGetPhysicalAddress
                    (param_1,0,
                     *(longlong *)(param_1 + 0x6460) + 4 +
                     (ulonglong)*(byte *)(param_1 + 0x645f) * 0x10,local_res8);
  if (0 < (int)((ulonglong)uVar4 >> 0x20)) {
    *param_3 = *param_3 | 1;
  }
  *(undefined8 *)(param_3 + 6) = uVar4;
  uVar4 = StorPortGetPhysicalAddress(param_1,0,param_3,local_res8);
  *(undefined8 *)(param_2 + 0x118) = uVar4;
  uVar4 = StorPortGetPhysicalAddress(param_1,0,*(undefined8 *)(param_1 + 0xc0),local_res8);
  *(undefined8 *)(param_2 + 0x128) = uVar4;
  *(undefined1 *)puVar1 = 0;
  *(undefined4 *)(param_2 + 0x114) = 0x40;
  *(undefined1 *)(param_2 + 0x103) = *(undefined1 *)(param_1 + 0x645f);
  uVar2 = *(undefined1 *)(param_1 + 0x645f);
  *(ushort *)(param_2 + 0x110) = *(ushort *)(param_2 + 0x110) | 1;
  *(undefined1 *)(param_2 + 0x10d) = uVar2;
  *(undefined1 *)(param_2 + 0x102) = 0xff;
  uVar4 = StorPortGetPhysicalAddress(param_1,0,puVar1,local_res8);
  (**(code **)(*(longlong *)(param_1 + 0x178) + 0x60))(param_1,uVar4,0);
  *(char *)(param_1 + 0x645f) = *(char *)(param_1 + 0x645f) + '\x01';
  return *(byte *)(param_1 + 0x48f1) <= *(byte *)(param_1 + 0x645f);
}



===== MFI_SendRequestToFW @ 140007540 =====

void MFI_SendRequestToFW(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  
  lVar1 = *param_2;
  *(int *)(param_2 + 0x21) = (int)param_2[1];
  if (*(char *)(param_1 + 0x1ce) == '\0') {
    *(undefined1 *)((longlong)param_2 + 0x103) = *(undefined1 *)((longlong)param_2 + 0xc);
  }
  else {
    *(undefined1 *)((longlong)param_2 + 0x10d) = *(undefined1 *)((longlong)param_2 + 0xc);
  }
  if (*(char *)(lVar1 + 2) == '\0') {
    if (*(char *)(lVar1 + 0xb) != '\0') {
      if (0 < *(int *)(param_1 + 0x174)) {
        *(ushort *)(param_2 + 0x22) = *(ushort *)(param_2 + 0x22) | 4;
      }
      param_2[0x23] = *(longlong *)(param_1 + 0x170) + (ulonglong)*(uint *)(param_2 + 1) * 0x12;
      bVar2 = *(byte *)(lVar1 + 0xb);
      if (0x11 < bVar2) {
        bVar2 = 0x12;
      }
      *(byte *)((longlong)param_2 + 0x101) = bVar2;
    }
    if (*(char *)((longlong)param_2 + 0x56) != '\0') {
      UpdateIOMetric(param_1,*(byte *)(lVar1 + 6),(char)param_2[3],param_2[0x24],
                     *(int *)((longlong)param_2 + 0x114),0x200);
      if (((char)param_2[0xb] != '\0') && (1 < *(byte *)((longlong)param_2 + 0x59))) {
        *(undefined1 *)((longlong)param_2 + 0x107) = *(undefined1 *)((longlong)param_2 + 0x34);
        *(int *)((longlong)param_2 + 0x114) = (int)param_2[6];
        iVar3 = ((uint)*(byte *)((longlong)param_2 + 0x36) *
                 (uint)*(ushort *)((longlong)param_2 + 0x34) +
                 *(int *)(&DAT_14000f490 + (ulonglong)*(byte *)(param_2 + 0x20) * 4) + 0x3f >> 6 &
                0xff) - 1;
        iVar4 = 7;
        if (iVar3 < 7) {
          iVar4 = iVar3;
        }
        *(char *)((longlong)param_2 + 0x69) = (char)iVar4;
      }
    }
  }
                    /* WARNING: Could not recover jumptable at 0x000140007663. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(longlong *)(param_1 + 0x178) + 0x50))(param_1,param_2);
  return;
}



===== MFI_SetFrameCount @ 140007670 =====

void MFI_SetFrameCount(undefined8 param_1,longlong param_2,byte param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = ((uint)*(byte *)(param_2 + 0x36) * (uint)*(ushort *)(param_2 + 0x34) +
           *(int *)(&DAT_14000f490 + (ulonglong)param_3 * 4) + 0x3f >> 6 & 0xff) - 1;
  iVar2 = 7;
  if (iVar1 < 7) {
    iVar2 = iVar1;
  }
  *(char *)(param_2 + 0x69) = (char)iVar2;
  return;
}



===== CDB_GetInfo @ 1400076b0 =====

void CDB_GetInfo(longlong param_1,char param_2,ulonglong *param_3,uint *param_4)

{
  if (param_2 == '\x06') {
    *param_3 = (ulonglong)
               ((uint6)CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 1),*(undefined1 *)(param_1 + 2)),
                                *(undefined1 *)(param_1 + 3)) & 0x1fffff);
    *param_4 = (uint)*(byte *)(param_1 + 4);
  }
  else {
    if (param_2 == '\n') {
      *param_3 = (ulonglong)
                 CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 2),
                                            *(undefined1 *)(param_1 + 3)),
                                   *(undefined1 *)(param_1 + 4)),*(undefined1 *)(param_1 + 5));
      *param_4 = (uint)CONCAT11(*(undefined1 *)(param_1 + 7),*(undefined1 *)(param_1 + 8));
      return;
    }
    if (param_2 == '\f') {
      *param_3 = (ulonglong)
                 CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 2),
                                            *(undefined1 *)(param_1 + 3)),
                                   *(undefined1 *)(param_1 + 4)),*(undefined1 *)(param_1 + 5));
      *param_4 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 6),
                                            *(undefined1 *)(param_1 + 7)),
                                   *(undefined1 *)(param_1 + 8)),*(undefined1 *)(param_1 + 9));
      return;
    }
    if (param_2 == '\x10') {
      *param_3 = (((((longlong)
                     (int)((uint)CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 2),
                                                   *(undefined1 *)(param_1 + 3)),
                                          *(undefined1 *)(param_1 + 4)) << 8) |
                    (ulonglong)*(byte *)(param_1 + 5)) << 8 | (ulonglong)*(byte *)(param_1 + 6)) <<
                   8 | (ulonglong)*(byte *)(param_1 + 7)) << 8 | (ulonglong)*(byte *)(param_1 + 8))
                 << 8 | (ulonglong)*(byte *)(param_1 + 9);
      *param_4 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 10),
                                            *(undefined1 *)(param_1 + 0xb)),
                                   *(undefined1 *)(param_1 + 0xc)),*(undefined1 *)(param_1 + 0xd));
      return;
    }
  }
  return;
}



===== CDB_SetBlockCnt @ 140007810 =====

void CDB_SetBlockCnt(longlong param_1,char param_2,undefined8 param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  
  uVar2 = (undefined1)param_3;
  if (param_2 == '\x06') {
    *(undefined1 *)(param_1 + 4) = uVar2;
  }
  else {
    uVar3 = (undefined1)((ulonglong)param_3 >> 8);
    if (param_2 == '\n') {
      *(undefined1 *)(param_1 + 8) = uVar2;
      *(undefined1 *)(param_1 + 7) = uVar3;
      return;
    }
    uVar1 = (undefined1)((ulonglong)param_3 >> 0x10);
    uVar4 = (undefined1)((ulonglong)param_3 >> 0x18);
    if (param_2 == '\f') {
      *(undefined1 *)(param_1 + 9) = uVar2;
      *(undefined1 *)(param_1 + 8) = uVar3;
      *(undefined1 *)(param_1 + 6) = uVar4;
      *(undefined1 *)(param_1 + 7) = uVar1;
      return;
    }
    if (param_2 == '\x10') {
      *(undefined1 *)(param_1 + 0xd) = uVar2;
      *(undefined1 *)(param_1 + 0xc) = uVar3;
      *(undefined1 *)(param_1 + 10) = uVar4;
      *(undefined1 *)(param_1 + 0xb) = uVar1;
      return;
    }
  }
  return;
}



===== CDB_SetStartLBA @ 140007880 =====

void CDB_SetStartLBA(longlong param_1,char param_2,undefined8 param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  byte bVar4;
  undefined1 uVar3;
  
  uVar3 = (undefined1)param_3;
  uVar1 = (undefined1)((ulonglong)param_3 >> 8);
  bVar4 = (byte)((ulonglong)param_3 >> 0x10);
  if (param_2 == '\x06') {
    *(undefined1 *)(param_1 + 3) = uVar3;
    *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) ^ (bVar4 ^ *(byte *)(param_1 + 1)) & 0x1f;
    *(undefined1 *)(param_1 + 2) = uVar1;
  }
  else {
    uVar2 = (undefined1)((ulonglong)param_3 >> 0x18);
    if ((param_2 == '\n') || (param_2 == '\f')) {
      *(undefined1 *)(param_1 + 5) = uVar3;
      *(undefined1 *)(param_1 + 4) = uVar1;
      *(undefined1 *)(param_1 + 2) = uVar2;
      *(byte *)(param_1 + 3) = bVar4;
      return;
    }
    if (param_2 == '\x10') {
      *(undefined1 *)(param_1 + 9) = uVar3;
      *(undefined1 *)(param_1 + 8) = uVar1;
      *(byte *)(param_1 + 7) = bVar4;
      *(undefined1 *)(param_1 + 6) = uVar2;
      *(char *)(param_1 + 5) = (char)((ulonglong)param_3 >> 0x20);
      *(char *)(param_1 + 4) = (char)((ulonglong)param_3 >> 0x28);
      *(char *)(param_1 + 2) = (char)((ulonglong)param_3 >> 0x38);
      *(char *)(param_1 + 3) = (char)((ulonglong)param_3 >> 0x30);
      return;
    }
  }
  return;
}



===== GetRegistrySettings @ 140007930 =====

void GetRegistrySettings(char *param_1,longlong param_2)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == (char *)0x0) {
    if (*(char *)(param_2 + 0x6468) != '\0') {
      *(undefined1 *)(param_2 + 0x646a) = 1;
    }
    *(undefined1 *)(param_2 + 0xa0) = 1;
    return;
  }
  ParseArgumentString(param_1);
  if (DAT_14000f518 != '\0') {
    *(undefined1 *)(param_2 + 0x88) = 1;
    return;
  }
  if (*(char *)(param_2 + 0x6468) != '\0') {
    *(bool *)(param_2 + 0x646a) = DAT_14000f538 == '\0';
    if (DAT_14000f568 != '\0') {
      *(undefined1 *)(param_2 + 0x90) = DAT_14000f56c;
    }
    if (DAT_14000f4c8 != '\0') {
      *(undefined4 *)(param_2 + 0x8c) = DAT_14000f4cc;
    }
  }
  if (DAT_14000f578 != '\0') {
    *(undefined1 *)(param_2 + 0x91) = 1;
  }
  if (DAT_14000f4d8 != '\0') {
    *(undefined4 *)(param_2 + 0x94) = DAT_14000f4dc;
  }
  if (DAT_14000f548 != '\0') {
    *(undefined4 *)(param_2 + 0x98) = DAT_14000f54c;
  }
  if (DAT_14000f558 != '\0') {
    *(undefined4 *)(param_2 + 0x9c) = DAT_14000f55c;
  }
  if (DAT_14000f588 != '\0') {
    *(undefined1 *)(param_2 + 0x48f2) = 0;
  }
  if (DAT_14000f4e8 != '\0') {
    *(undefined4 *)(param_2 + 0xa8) = DAT_14000f4ec;
  }
  if (DAT_14000f4f8 != '\0') {
    *(undefined4 *)(param_2 + 0xa4) = DAT_14000f4fc;
  }
  if ((DAT_14000f528 != '\0') &&
     (extendedTimeout = DAT_14000f52c * 1000000, 179999999 < extendedTimeout - 1U)) {
    extendedTimeout = 180000000;
  }
  *(bool *)(param_2 + 0xa0) = DAT_14000f598 != '\0';
  if (DAT_14000f5a8 != '\0') {
    *(int *)(param_2 + 0x6aac) = DAT_14000f5ac;
    iVar1 = DAT_14000f5ac;
    bVar2 = DAT_14000f5ac == 0;
    *(undefined1 *)(param_2 + 0x6aa9) = 1;
    if (bVar2) {
      iVar1 = 1;
    }
    *(int *)(param_2 + 0x6aac) = iVar1;
  }
  if (DAT_14000f5b8 != '\0') {
    if (0x20 < DAT_14000f5bc) {
      DAT_14000f5bc = 0x20;
      *(undefined1 *)(param_2 + 0x6ab1) = 0x20;
    }
    *(undefined1 *)(param_2 + 0x6ab0) = 1;
  }
  *(bool *)(param_2 + 0x6d58) = DAT_14000f5c8 != '\0';
  *(bool *)(param_2 + 0xb8) = DAT_14000f5d8 != '\0';
  if (DAT_14000f5e8 == '\0') {
    *(undefined1 *)(param_2 + 0xb9) = 0;
  }
  else {
    *(undefined1 *)(param_2 + 0xb9) = 1;
    *(undefined1 *)(param_2 + 0x6aa9) = 1;
  }
  *(bool *)(param_2 + 0xba) = DAT_14000f5f8 != '\0';
  return;
}



===== MemFastMove @ 140007b30 =====

void MemFastMove(undefined8 *param_1,undefined8 *param_2,uint param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  uint uVar3;
  
  for (uVar3 = param_3 >> 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    uVar1 = *param_2;
    param_2 = param_2 + 1;
    *param_1 = uVar1;
    param_1 = param_1 + 1;
  }
  uVar3 = param_3 & 7;
  if (uVar3 != 0) {
    lVar2 = (longlong)param_1 - (longlong)param_2;
    do {
      *(undefined1 *)(lVar2 + (longlong)param_2) = *(undefined1 *)param_2;
      param_2 = (undefined8 *)((longlong)param_2 + 1);
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  return;
}



===== MemFastZero @ 140007b80 =====

void MemFastZero(undefined8 *param_1,uint param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  
  uVar1 = param_2 >> 3;
  if (uVar1 != 0) {
    puVar3 = param_1;
    for (uVar2 = (ulonglong)uVar1; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    param_1 = param_1 + uVar1;
  }
  if ((param_2 & 7) != 0) {
    for (uVar2 = (ulonglong)(param_2 & 7); uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)param_1 = 0;
      param_1 = (undefined8 *)((longlong)param_1 + 1);
    }
  }
  return;
}



===== ParseArgumentString @ 140007bc0 =====

void ParseArgumentString(char *param_1)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  longlong lVar5;
  longlong lVar6;
  undefined **ppuVar7;
  longlong lVar8;
  byte *pbVar9;
  
  ppuVar7 = &regSettings;
  lVar8 = 0x14;
  do {
    pcVar4 = strstr(param_1,*ppuVar7);
    if (pcVar4 != (char *)0x0) {
      lVar6 = -1;
      *(undefined1 *)(ppuVar7 + 1) = 1;
      do {
        lVar5 = lVar6 + 1;
        lVar6 = lVar6 + 1;
      } while ((*ppuVar7)[lVar5] != '\0');
      if (pcVar4[lVar6] == '=') {
        lVar6 = -1;
        do {
          lVar5 = lVar6;
          lVar6 = lVar5 + 1;
        } while ((*ppuVar7)[lVar6] != '\0');
        pcVar4 = pcVar4 + lVar5 + 2;
        iVar3 = 0;
        cVar1 = *pcVar4;
        if ((cVar1 == '0') && (pcVar4[1] == 'x')) {
          pbVar9 = (byte *)(pcVar4 + 2);
          while( true ) {
            for (; bVar2 = *pbVar9, (byte)(bVar2 - 0x30) < 10; pbVar9 = pbVar9 + 1) {
              iVar3 = iVar3 * 0x10 + -0x30 + (int)(char)bVar2;
            }
            if ((char)bVar2 < 'A') break;
            if ((bVar2 & 0x20) == 0) {
              iVar3 = iVar3 * 0x10 + -0x37 + (int)(char)bVar2;
              pbVar9 = pbVar9 + 1;
            }
            else {
              iVar3 = iVar3 * 0x10 + -0x57 + (int)(char)bVar2;
              pbVar9 = pbVar9 + 1;
            }
          }
        }
        else {
          while (('/' < cVar1 && (cVar1 < ':'))) {
            pcVar4 = pcVar4 + 1;
            iVar3 = (int)cVar1 + iVar3 * 10 + -0x30;
            cVar1 = *pcVar4;
          }
        }
        *(int *)((longlong)ppuVar7 + 0xc) = iVar3;
      }
    }
    ppuVar7 = ppuVar7 + 2;
    lVar8 = lVar8 + -1;
  } while (lVar8 != 0);
  return;
}



===== BuildSysPD @ 140007ce0 =====

void BuildSysPD(longlong param_1,longlong *param_2,undefined2 *param_3)

{
  longlong lVar1;
  undefined2 uVar2;
  uint uVar3;
  
  lVar1 = *param_2;
  *(undefined1 *)((longlong)param_2 + 0x94) = 0xc;
  *(undefined1 *)((longlong)param_2 + 0x55) = 1;
  *(undefined1 *)((longlong)param_3 + 3) = 0;
  *(undefined1 *)(param_2 + 0xf) = *(undefined1 *)(param_1 + 0x646a);
  uVar3 = *(int *)(param_1 + 0x646c) - 1;
  *(uint *)((longlong)param_2 + 0x7c) = uVar3;
  if (*(int *)(param_1 + 0x894) != 0) {
    *(undefined1 *)((longlong)param_2 + 0x1c) = 1;
  }
  if ((char)param_2[0xf] == '\0') {
    *param_3 = 0xffff;
    uVar2 = 0x14;
  }
  else {
    *param_3 = *(undefined2 *)
                (*(longlong *)(param_1 + 0x6d78 + (ulonglong)(uVar3 & 1) * 8) + 0x28 +
                (ulonglong)*(byte *)(lVar1 + 6) * 8);
    uVar2 = *(undefined2 *)(lVar1 + 0x14);
  }
  param_3[0x31] = uVar2;
  *(undefined1 *)(param_3 + 0x32) = 0;
  param_3[0x33] = (ushort)*(byte *)(lVar1 + 6);
  *(undefined1 *)((longlong)param_3 + 0x35) = *(undefined1 *)(lVar1 + 7);
  *(undefined1 *)(param_3 + 0x1a) = 0;
  *(undefined2 *)((longlong)param_2 + 0x9a) = *param_3;
  *(undefined8 *)(param_3 + 0x34) = 0;
  *(undefined4 *)(param_3 + 0x38) = 0;
  *(undefined1 *)(param_3 + 0x3c) = 0x10;
  if (*(char *)(param_1 + 0x6469) != '\0') {
    param_3[0x12] = param_3[0x12] | 0x4000;
    *(undefined2 *)((longlong)param_2 + 0x9a) = *param_3;
  }
  return;
}



===== BuildWithRaidMap @ 140007db0 =====

ulonglong BuildWithRaidMap(int *param_1,longlong *param_2,ushort *param_3,longlong param_4)

{
  ushort *puVar1;
  ulonglong *puVar2;
  byte bVar3;
  byte bVar4;
  undefined1 uVar5;
  longlong lVar6;
  undefined1 uVar7;
  ushort uVar8;
  ulonglong uVar9;
  undefined1 uVar10;
  char local_res10 [8];
  char local_37 [3];
  ushort local_34 [6];
  
  bVar3 = *(byte *)(*param_2 + 6);
  local_res10[0] = '\0';
  local_37[0] = '\0';
  if ((char)param_2[0xf] != '\0') {
    puVar1 = param_3 + 0x30;
    puVar2 = (ulonglong *)(param_2 + 5);
    uVar9 = MegaSASBuildRaidContext
                      (param_1,param_4,param_2[4],*(uint *)(param_2 + 6),(uint)bVar3,
                       (char)param_2[3],*(char *)((longlong)param_1 + 0x6469),(longlong *)puVar2,
                       (longlong)puVar1,(short *)local_34,local_res10,local_37,(longlong)param_2);
    if ((char)uVar9 != '\0') {
      bVar4 = *(byte *)((longlong)param_2 + 0x54);
      if (local_res10[0] == '\0') {
        CDB_SetStartLBA((longlong)(param_3 + 0x20),bVar4,param_2[4]);
        *(undefined1 *)((longlong)param_2 + 0x94) = 0xe;
        uVar9 = 0;
        *param_3 = (ushort)bVar3;
        *(undefined1 *)((longlong)param_3 + 3) = 0xf1;
        if (*(char *)((longlong)param_1 + 0x6469) != '\0') {
          *puVar1 = *puVar1 & 0xff12 | 0x12;
          uVar9 = (ulonglong)*(byte *)((longlong)param_2 + 0x94);
          if ((char)param_3[0x32] == '\0') {
            uVar9 = 4;
          }
          *(char *)((longlong)param_2 + 0x94) = (char)uVar9;
          *(byte *)(param_3 + 0x32) = (byte)param_3[0x32] | 8;
        }
      }
      else {
        if ((bVar4 < 0x10) && (0xffffffff < *puVar2)) {
          if (bVar4 == 0xc) {
            uVar10 = (undefined1)param_3[0x25];
            uVar7 = *(undefined1 *)((longlong)param_3 + 0x4b);
          }
          else {
            uVar10 = (undefined1)param_3[0x23];
            uVar7 = *(undefined1 *)((longlong)param_3 + 0x49);
          }
          uVar5 = *(undefined1 *)((longlong)param_3 + 0x41);
          MemFastZero((undefined8 *)(param_3 + 0x20),0x20);
          CDB_SetBlockCnt((longlong)(param_3 + 0x20),'\x10',(ulonglong)*(uint *)(param_2 + 6));
          CDB_SetStartLBA((longlong)(param_3 + 0x20),'\x10',*puVar2);
          *(undefined1 *)((longlong)param_2 + 0x54) = 0x10;
          param_3[0x12] = 0x10;
          lVar6 = param_2[3];
          *(undefined1 *)(param_3 + 0x27) = uVar10;
          uVar10 = 0x8a;
          if ((char)lVar6 != '\0') {
            uVar10 = 0x88;
          }
          *(undefined1 *)(param_3 + 0x20) = uVar10;
          *(undefined1 *)((longlong)param_3 + 0x4f) = uVar7;
          *(undefined1 *)((longlong)param_3 + 0x41) = uVar5;
        }
        else {
          CDB_SetStartLBA((longlong)(param_3 + 0x20),bVar4,*puVar2);
        }
        uVar9 = (ulonglong)local_34[0];
        *(ushort *)((longlong)param_2 + 0x9a) = local_34[0];
        *(undefined1 *)((longlong)param_2 + 0x94) = 0xc;
        *(undefined1 *)((longlong)param_3 + 3) = 0;
        *param_3 = local_34[0];
        *(undefined1 *)((longlong)param_2 + 0x55) = 1;
        if (*(char *)((longlong)param_1 + 0x6469) != '\0') {
          *puVar1 = *puVar1 & 0xff12 | 0x12;
          uVar9 = (ulonglong)*(byte *)((longlong)param_2 + 0x94);
          if ((char)param_3[0x32] == '\0') {
            uVar9 = 4;
          }
          *(char *)((longlong)param_2 + 0x94) = (char)uVar9;
          *(byte *)(param_3 + 0x32) = (byte)param_3[0x32] | 0x88;
        }
      }
      goto LAB_140007eb3;
    }
  }
  CDB_SetStartLBA((longlong)(param_3 + 0x20),*(char *)((longlong)param_2 + 0x54),param_2[4]);
  *(undefined1 *)((longlong)param_2 + 0x94) = 0xe;
  uVar9 = 0;
  *param_3 = (ushort)bVar3;
  param_3[0x31] = 0x14;
  param_3[0x33] = (ushort)bVar3;
  *(undefined1 *)((longlong)param_3 + 3) = 0xf1;
  *(undefined1 *)(param_3 + 0x32) = 0;
  if (*(char *)((longlong)param_1 + 0x6469) != '\0') {
    uVar8 = param_3[0x30] & 0xfff2 | 2;
    uVar9 = (ulonglong)uVar8;
    param_3[0x30] = uVar8;
    *(undefined1 *)((longlong)param_2 + 0x94) = 4;
  }
  *(undefined1 *)((longlong)param_2 + 0x79) = 1;
  if (local_37[0] == '\0') {
    return uVar9 & 0xffffffffffffff00;
  }
LAB_140007eb3:
  return CONCAT71((int7)(uVar9 >> 8),1);
}



===== MPT_BuildCmd_Scsi @ 140008060 =====

longlong MPT_BuildCmd_Scsi(int *param_1,longlong *param_2)

{
  ushort *puVar1;
  byte bVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong lVar6;
  undefined1 uVar7;
  
  lVar6 = *param_2;
  puVar1 = (ushort *)(param_2 + 0x20);
  MemFastZero((undefined8 *)puVar1,0x80);
  *(undefined8 *)((longlong)param_2 + 0x94) = 0;
  MemFastMove(param_2 + 0x28,(undefined8 *)(lVar6 + 0x48),(uint)*(byte *)((longlong)param_2 + 0x54))
  ;
  *(ushort *)((longlong)param_2 + 0x124) = (ushort)*(byte *)((longlong)param_2 + 0x54);
  CDB_GetInfo(lVar6 + 0x48,*(char *)((longlong)param_2 + 0x54),(ulonglong *)(param_2 + 4),
              (uint *)(param_2 + 6));
  if (*(char *)(lVar6 + 5) == '\x01') {
    if (((char)param_2[3] == '\0') && (*(char *)((longlong)param_2 + 0x19) == '\0')) {
      *(undefined1 *)((longlong)param_2 + 0x94) = 0;
      *(undefined1 *)((longlong)param_2 + 0x103) = 0xf1;
      bVar2 = *(byte *)(*param_2 + 6);
      *(undefined2 *)((longlong)param_2 + 0x162) = 0x14;
      *puVar1 = (ushort)bVar2;
      *(undefined1 *)((longlong)param_2 + 0x164) = 0;
      *(ushort *)((longlong)param_2 + 0x166) = (ushort)*(byte *)(*param_2 + 6);
    }
    else {
      uVar7 = *(undefined1 *)((longlong)param_1 + 0x646a);
      *(undefined1 *)(param_2 + 0xf) = uVar7;
      if ((char)param_1[0x22] != '\0') {
        uVar7 = 0;
      }
      *(undefined1 *)(param_2 + 0xf) = uVar7;
      iVar3 = param_1[0x191b];
      *(uint *)((longlong)param_2 + 0x7c) = iVar3 - 1U;
      iVar3 = MR_ldBlockSizeGet((ulonglong)*(byte *)(lVar6 + 6),
                                *(longlong *)(param_1 + (ulonglong)(iVar3 - 1U & 1) * 2 + 0x1b5e),
                                (longlong)param_1);
      *(int *)(param_2 + 0x10) = iVar3;
      BuildWithRaidMap(param_1,param_2,puVar1,
                       *(longlong *)
                        (param_1 + (ulonglong)(*(uint *)((longlong)param_2 + 0x7c) & 1) * 2 + 0x1b5e
                        ));
    }
  }
  else {
    if (*(char *)((ulonglong)*(byte *)(lVar6 + 6) + 0x3d9 + (longlong)param_1) == '\0') {
      *(undefined1 *)((longlong)param_2 + 0x94) = 0;
      lVar6 = MFI_BuildFrame_NonRW((longlong)param_1,param_2);
      return lVar6;
    }
    BuildSysPD((longlong)param_1,param_2,puVar1);
  }
  *(undefined1 *)((longlong)param_2 + 0x114) = 0x20;
  *(undefined4 *)((longlong)param_2 + 0x11c) = *(undefined4 *)(lVar6 + 0x10);
  *(ushort *)((longlong)param_2 + 0x124) = (ushort)*(byte *)((longlong)param_2 + 0x54);
  if (*(int *)(lVar6 + 0x10) != 0) {
    *(undefined2 *)(param_2 + 0x22) = 2;
    if ((char)*(undefined4 *)(lVar6 + 0xc) < '\0') {
      *(uint *)((longlong)param_2 + 0x13c) = *(uint *)((longlong)param_2 + 0x13c) | 0x1000000;
    }
    else {
      *(uint *)((longlong)param_2 + 0x13c) = *(uint *)((longlong)param_2 + 0x13c) | 0x2000000;
    }
    plVar4 = param_2 + 0x30;
    if ((char)param_1[0x191a] == '\0') {
      plVar4 = param_2 + 0x40;
    }
    param_2[7] = (longlong)plVar4;
    param_2[8] = (longlong)plVar4;
    lVar5 = BuildSGLforSRB((longlong)param_1,param_2);
    if ((char)lVar5 == '\0') {
      *(undefined1 *)(lVar6 + 3) = 4;
      return lVar5;
    }
    *(undefined1 *)((longlong)param_2 + 0x179) = *(undefined1 *)((longlong)param_2 + 0x34);
    *(undefined1 *)((longlong)param_2 + 0x17e) = *(undefined1 *)((longlong)param_2 + 0x35);
  }
  return 1;
}



===== MPT_BuildPassthrough @ 140008250 =====

void MPT_BuildPassthrough(longlong param_1,undefined8 *param_2,undefined8 param_3)

{
  MemFastZero(param_2,0x100);
  *(undefined2 *)((longlong)param_2 + 2) = 0xf008;
  *(undefined1 *)((longlong)param_2 + 0x14) = 0x20;
  param_2[0x10] = param_3;
  *(undefined4 *)((longlong)param_2 + 0x8c) = 0x83000000;
  *(undefined4 *)(param_2 + 0x11) = 0x400;
  if (*(char *)(param_1 + 0x6469) != '\0') {
    *(undefined1 *)((longlong)param_2 + 0xff) = 0;
  }
  return;
}



===== MPT_CompleteRequests @ 1400082c0 =====

undefined8 MPT_CompleteRequests(int *param_1,uint param_2)

{
  char cVar1;
  ushort uVar2;
  uint uVar3;
  longlong *plVar4;
  longlong lVar5;
  int *piVar6;
  bool bVar7;
  ulonglong uVar8;
  uint *puVar9;
  longlong lVar10;
  int *piVar11;
  char cVar12;
  char cVar13;
  ushort *puVar14;
  
  bVar7 = false;
  puVar14 = (ushort *)(param_1 + (ulonglong)param_2 * 4 + 0x192a);
  piVar11 = (int *)(*(longlong *)(puVar14 + 4) + (ulonglong)*puVar14 * 8);
  if (*(int *)(*(longlong *)(puVar14 + 4) + (ulonglong)*puVar14 * 8) == -1) {
LAB_140008597:
    (**(code **)(*(longlong *)(param_1 + 0x5e) + 0x18))(param_1);
    puVar9 = (uint *)CheckFirmwareFault((longlong)param_1);
    if ((char)puVar9 != '\0') {
      return (ulonglong)puVar9 & 0xffffffffffffff00;
    }
  }
  else {
    do {
      if (piVar11[1] == -1) {
        if (!bVar7) goto LAB_140008597;
        break;
      }
      uVar2 = *(ushort *)((longlong)piVar11 + 2);
      bVar7 = true;
      piVar11[0] = -1;
      piVar11[1] = -1;
      *puVar14 = *puVar14 + 1;
      if ((uint)*puVar14 < (uint)param_1[0x227]) {
        piVar11 = piVar11 + 2;
      }
      else {
        piVar11 = *(int **)(puVar14 + 4);
        *puVar14 = 0;
      }
      if ((uVar2 == 0) || ((uint)param_1[0x227] < (uint)uVar2)) {
        uVar8 = SetDeadAdapter((longlong)param_1,0x22);
        return uVar8 & 0xffffffffffffff00;
      }
      plVar4 = *(longlong **)(*(longlong *)(param_1 + 0x60) + (longlong)(int)(uVar2 - 1) * 8);
      if (plVar4 == (longlong *)0x0) {
        uVar8 = SetDeadAdapter((longlong)param_1,6);
        return uVar8 & 0xffffffffffffff00;
      }
      lVar5 = *plVar4;
      if (lVar5 == 0) {
        if (((char)plVar4[0x20] != '\x05') || ((uint)uVar2 <= (uint)param_1[0x226])) {
          uVar8 = SetDeadAdapter((longlong)param_1,7);
          return uVar8 & 0xffffffffffffff00;
        }
        CompleteDCMD(param_1,(longlong)(plVar4 + 0x20),'\0');
      }
      else {
        uVar3 = *(uint *)(plVar4 + 1);
        cVar1 = *(char *)((longlong)plVar4 + 0x1c);
        lVar10 = (ulonglong)uVar2 * 0x100 + *(longlong *)(param_1 + 0x1928);
        if ((*(char *)(lVar10 + 3) == '\0') || (*(char *)(lVar10 + 3) == -0xf)) {
          piVar6 = (int *)plVar4[0xe];
          if (piVar6 != (int *)0x0) {
            LOCK();
            *piVar6 = *piVar6 + -1;
            UNLOCK();
          }
          *(undefined4 *)(plVar4 + 10) = *(undefined4 *)(lVar10 + 0x1c);
          cVar13 = *(char *)(lVar10 + 0x76);
          cVar12 = *(char *)(lVar10 + 0x77);
LAB_140008457:
          CompleteScsiRequest((longlong)param_1,plVar4,cVar12,cVar13);
        }
        else {
          cVar13 = *(char *)(lVar5 + 2);
          if (cVar13 == '\0') {
            *(undefined4 *)(plVar4 + 10) = *(undefined4 *)((longlong)plVar4 + 0x114);
            cVar13 = *(char *)((longlong)plVar4 + 0x103);
            cVar12 = *(char *)((longlong)plVar4 + 0x102);
            goto LAB_140008457;
          }
          if (cVar13 == '\b') {
            if (*(char *)((longlong)plVar4 + 0x102) == '\0') {
              *(undefined2 *)(lVar5 + 3) = 1;
              StorPortNotification(0,param_1);
            }
            else {
              *(undefined1 *)(lVar5 + 3) = 4;
              StorPortNotification(0,param_1);
            }
          }
          else if (cVar13 == '\x02') {
            CompleteIoctlRequest((longlong)param_1,plVar4);
          }
        }
        if (*(longlong **)(*(longlong *)(param_1 + 0x60) + (ulonglong)uVar3 * 8) != plVar4) {
          uVar8 = SetDeadAdapter((longlong)param_1,0x21);
          return uVar8 & 0xffffffffffffff00;
        }
        *(undefined8 *)(*(longlong *)(param_1 + 0x60) + (ulonglong)uVar3 * 8) = 0;
        param_1[0x62] = uVar3;
        LOCK();
        param_1[0x68] = param_1[0x68] + -1;
        UNLOCK();
        if ((cVar1 == '\0') && (param_1[0x225] != 0)) {
          LOCK();
          param_1[0x6a] = param_1[0x6a] + -1;
          UNLOCK();
        }
        if ((param_1[0x68] < 0) || ((param_1[0x225] != 0 && (param_1[0x6a] < 0)))) {
          uVar8 = SetDeadAdapter((longlong)param_1,0x25);
          return uVar8 & 0xffffffffffffff00;
        }
      }
    } while (*piVar11 != -1);
    if ((((char)param_1[0x22] == '\0') && (*(char *)((longlong)param_1 + 0x6469) != '\0')) &&
       ((char)param_1[0x123c] != '\0')) {
      puVar9 = *(uint **)((longlong)param_1 + ((ulonglong)param_2 & 0xfffffffffffffff8) + 0x6cb8);
      *puVar9 = (param_2 & 7) << 0x18 | (uint)*puVar14;
    }
    else {
      puVar9 = *(uint **)(param_1 + 0x20);
      puVar9[0x1b] = param_2 << 0x18 | (uint)*puVar14;
    }
    LOCK();
    UNLOCK();
  }
  return CONCAT71((int7)((ulonglong)puVar9 >> 8),1);
}



===== MPT_GetMemLenToAlloc @ 1400085c0 =====

int MPT_GetMemLenToAlloc(longlong param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x6d64) = 0x2a0a8;
  *(undefined4 *)(param_1 + 0x6d68) = 0xa2928;
  *(undefined4 *)(param_1 + 0x6d6c) = 0xa2928;
  *(undefined4 *)(param_1 + 0x6d5c) = 0xa2928;
  iVar1 = ((uint)*(ushort *)(param_1 + 0x1d0) +
          ((uint)*(byte *)(param_1 + 0x48f1) * *(int *)(param_1 + 0x89c) +
          (*(int *)(param_1 + 0x88c) + 1) * 0x20) * 4) * 2;
  if (*(char *)(param_1 + 0x646a) != '\0') {
    iVar1 = iVar1 + (uint)*(ushort *)(param_1 + 0x1d0) * 2 + 0x2de5f0;
  }
  return iVar1;
}



===== MPT_InitMessageMem @ 140008630 =====

undefined8 MPT_InitMessageMem(longlong param_1,longlong param_2,ulonglong param_3)

{
  ushort uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  undefined1 local_res18 [8];
  
  uVar1 = *(ushort *)(param_1 + 0x1d0);
  uVar3 = (ulonglong)uVar1 + param_2 & (longlong)(int)~(uint)uVar1;
  *(ulonglong *)(param_1 + 0x64a0) = uVar3;
  uVar5 = 0;
  uVar3 = (ulonglong)(*(int *)(param_1 + 0x88c) + 1) * 0x100 + (ulonglong)uVar1 + uVar3 &
          (longlong)(int)~(uint)uVar1;
  if (*(char *)(param_1 + 0x48f1) != '\0') {
    do {
      uVar4 = (ulonglong)uVar5;
      uVar5 = uVar5 + 1;
      *(undefined2 *)(param_1 + 0x64a8 + uVar4 * 0x10) = 0;
      *(ulonglong *)(param_1 + (uVar4 + 0x64b) * 0x10) = uVar3;
      uVar3 = uVar3 + (uint)(*(int *)(param_1 + 0x89c) << 3);
    } while (uVar5 < *(byte *)(param_1 + 0x48f1));
  }
  if (*(char *)(param_1 + 0x646a) != '\0') {
    uVar3 = uVar3 + *(ushort *)(param_1 + 0x1d0) &
            (longlong)(int)~(uint)*(ushort *)(param_1 + 0x1d0);
    *(ulonglong *)(param_1 + 0x6470) = uVar3;
    uVar2 = StorPortGetPhysicalAddress(param_1,0,uVar3,local_res18);
    *(undefined8 *)(param_1 + 0x6480) = uVar2;
    uVar3 = *(uint *)(param_1 + 0x6d68) + uVar3 + (ulonglong)*(ushort *)(param_1 + 0x1d0) &
            (longlong)(int)~(uint)*(ushort *)(param_1 + 0x1d0);
    *(ulonglong *)(param_1 + 0x6d78) = uVar3;
    uVar3 = *(uint *)(param_1 + 0x6d6c) + uVar3 + (ulonglong)*(ushort *)(param_1 + 0x1d0) &
            (longlong)(int)~(uint)*(ushort *)(param_1 + 0x1d0);
    *(ulonglong *)(param_1 + 0x6478) = uVar3;
    uVar2 = StorPortGetPhysicalAddress(param_1,0,uVar3,local_res18);
    *(undefined8 *)(param_1 + 0x6488) = uVar2;
    uVar3 = *(uint *)(param_1 + 0x6d68) + uVar3 + (ulonglong)*(ushort *)(param_1 + 0x1d0) &
            (longlong)(int)~(uint)*(ushort *)(param_1 + 0x1d0);
    *(ulonglong *)(param_1 + 0x6d80) = uVar3;
    uVar3 = uVar3 + *(uint *)(param_1 + 0x6d6c);
  }
  uVar4 = param_2 + (param_3 & 0xffffffff);
  return CONCAT71((int7)(uVar4 >> 8),uVar3 <= uVar4);
}



===== MPT_InitializeQueues @ 1400087c0 =====

undefined8 MPT_InitializeQueues(longlong param_1,longlong param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  uint uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined1 local_res8 [8];
  ulonglong local_res10;
  ulonglong local_res18 [2];
  
  puVar1 = (undefined8 *)(param_2 + 0x100);
  uVar4 = 0;
  if (*(char *)(param_1 + 0x48f1) != '\0') {
    do {
      *(undefined2 *)(param_1 + 0x64a8 + uVar4 * 0x10) = 0;
      uVar2 = 0;
      if (*(int *)(param_1 + 0x89c) != 0) {
        do {
          uVar5 = (ulonglong)uVar2;
          uVar2 = uVar2 + 1;
          *(undefined8 *)(*(longlong *)(param_1 + (uVar4 + 0x64b) * 0x10) + uVar5 * 8) =
               0xffffffffffffffff;
        } while (uVar2 < *(uint *)(param_1 + 0x89c));
      }
      uVar2 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar2;
    } while (uVar2 < *(byte *)(param_1 + 0x48f1));
  }
  MemFastZero(puVar1,0x40);
  MemFastZero(param_3,0x48);
  *(undefined1 *)((longlong)param_3 + 3) = 2;
  *(undefined1 *)param_3 = 4;
  *(undefined4 *)((longlong)param_3 + 0xc) = 0x10000200;
  if ((*(char *)(param_1 + 0x48f0) == '\0') || (*(byte *)(param_1 + 0x48f1) < 2)) {
    *(undefined1 *)((longlong)param_3 + 0x17) = 0;
  }
  else {
    *(byte *)((longlong)param_3 + 0x17) = *(byte *)(param_1 + 0x48f1);
  }
  *(undefined2 *)((longlong)param_3 + 0x1a) = 0x40;
  *(undefined2 *)((longlong)param_3 + 0x1c) = *(undefined2 *)(param_1 + 0x89c);
  *(undefined2 *)((longlong)param_3 + 0x1e) = 0;
  uVar3 = StorPortGetPhysicalAddress(param_1,0,*(undefined8 *)(param_1 + 0x64b0),local_res8);
  param_3[6] = uVar3;
  uVar3 = StorPortGetPhysicalAddress(param_1,0,*(undefined8 *)(param_1 + 0x64a0),local_res8);
  param_3[5] = uVar3;
  *(undefined4 *)(param_3 + 4) = *(undefined4 *)(param_1 + 0x174);
  param_3[7] = 0;
  StorPortQuerySystemTime(local_res18);
  local_res18[0] = (longlong)(local_res18[0] + 0xfe624e212ac18000) / 10000;
  if (((local_res18[0] >> 0x20 & 0xfffffff0) != 0) || (uVar3 = 0, (int)local_res18[0] != 0)) {
    uVar3 = 1;
  }
  param_3[8] = uVar3;
  uVar3 = StorPortGetPhysicalAddress(param_1,0,param_3,local_res8);
  *(undefined8 *)(param_2 + 0x118) = uVar3;
  uVar3 = StorPortGetPhysicalAddress(param_1,0,*(undefined8 *)(param_1 + 0xc0),local_res8);
  *(undefined8 *)(param_2 + 0x128) = uVar3;
  *(undefined1 *)puVar1 = 0;
  *(undefined4 *)(param_2 + 0x114) = 8;
  if (*(char *)(param_1 + 0x6469) != '\0') {
    uVar2 = *(uint *)(param_2 + 0x104);
    *(uint *)(param_2 + 0x104) = uVar2 | 0x12;
    if (*(char *)(param_1 + 0x6db1) != '\0') {
      *(uint *)(param_2 + 0x104) = uVar2 | 0x112;
    }
    if (*(int *)(param_1 + 0x894) != 0) {
      *(uint *)(param_2 + 0x104) = *(uint *)(param_2 + 0x104) | 0x80;
    }
  }
  if (*(char *)(param_1 + 0x6468) != '\0') {
    *(uint *)(param_2 + 0x104) = *(uint *)(param_2 + 0x104) | 8;
  }
  *(ushort *)(param_2 + 0x110) = *(ushort *)(param_2 + 0x110) | 1;
  *(undefined1 *)(param_2 + 0x102) = 0xff;
  uVar4 = StorPortGetPhysicalAddress(param_1,0,puVar1,local_res8);
  local_res10 = uVar4 & 0xffffffffffffff02 | 2;
  uVar3 = Fusion_FireCmd(param_1,local_res10);
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== MPT_SendRequestToFW @ 140008a00 =====

void MPT_SendRequestToFW(int *param_1,longlong *param_2)

{
  ushort *puVar1;
  int *piVar2;
  ushort uVar3;
  longlong lVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  ushort uVar10;
  char *pcVar11;
  undefined8 *puVar12;
  char cVar13;
  undefined1 local_res10 [8];
  
  lVar4 = *param_2;
  uVar10 = (short)param_2[1] + 1;
  *(ushort *)((longlong)param_2 + 0x96) = uVar10;
  if ((*(char *)(lVar4 + 2) != '\0') ||
     ((*(char *)(lVar4 + 5) != '\x01' &&
      (*(char *)((ulonglong)*(byte *)(lVar4 + 6) + 0x3d9 + (longlong)param_1) == '\0')))) {
    lVar4 = param_2[2];
    puVar12 = (undefined8 *)((ulonglong)uVar10 * 0x100 + *(longlong *)(param_1 + 0x1928));
    MemFastZero(puVar12,0x100);
    *(undefined2 *)((longlong)puVar12 + 2) = 0xf008;
    *(undefined1 *)((longlong)puVar12 + 0x14) = 0x20;
    *(undefined4 *)((longlong)puVar12 + 0x8c) = 0x83000000;
    puVar12[0x10] = lVar4;
    *(undefined4 *)(puVar12 + 0x11) = 0x400;
    if (*(char *)((longlong)param_1 + 0x6469) != '\0') {
      *(undefined1 *)((longlong)puVar12 + 0xff) = 0;
    }
    MFI_SendRequestToFW((longlong)param_1,param_2);
    return;
  }
  cVar13 = *(char *)((longlong)param_1 + 0x6469);
  puVar1 = (ushort *)(param_2 + 0x20);
  if (*(char *)(lVar4 + 0xb) != '\0') {
    *(int *)((longlong)param_2 + 0x10c) = param_1[0x5c] + (int)param_2[1] * 0x12;
    bVar5 = *(byte *)(lVar4 + 0xb);
    if (0x11 < bVar5) {
      bVar5 = 0x12;
    }
    *(byte *)((longlong)param_2 + 0x112) = bVar5;
  }
  if (*(int *)(lVar4 + 0x10) != 0) {
    uVar10 = *(ushort *)((longlong)param_2 + 0x34);
    if (uVar10 < 9) {
      if (uVar10 == 8) {
        MemFastMove((undefined8 *)param_2[9],param_2 + 0x40,
                    (uint)*(byte *)((longlong)param_2 + 0x36));
        param_2[8] = param_2[8] - (ulonglong)*(byte *)((longlong)param_2 + 0x36);
        goto LAB_140008b07;
      }
    }
    else {
      uVar8 = StorPortGetPhysicalAddress(param_1,lVar4,param_2 + 0x40,local_res10);
      puVar12 = (undefined8 *)param_2[9];
      *puVar12 = uVar8;
      bVar5 = *(byte *)((longlong)param_2 + 0x36);
      *(undefined4 *)((longlong)puVar12 + 0xc) = 0x80000000;
      *(uint *)(puVar12 + 1) = (uVar10 - 7) * (uint)bVar5;
      *(char *)((longlong)param_2 + 0x102) =
           (char)(0x100 - (ulonglong)*(byte *)((longlong)param_2 + 0x36) >> 4);
LAB_140008b07:
      cVar13 = '\0';
    }
    if (*(char *)((longlong)param_1 + 0x6469) != '\0') {
      *(undefined1 *)((param_2[8] - (ulonglong)*(byte *)((longlong)param_2 + 0x36)) + 0xf) = 0x40;
    }
  }
  if (*(char *)((longlong)param_2 + 0x56) != '\0') {
    UpdateIOMetric((longlong)param_1,*(byte *)(lVar4 + 6),(char)param_2[3],param_2[4],
                   (int)param_2[6],*(uint *)(param_2 + 0x10));
  }
  if (((char)param_2[0xb] != '\0') && (1 < *(byte *)((longlong)param_2 + 0x59))) {
    CDB_SetBlockCnt((longlong)(param_2 + 0x28),*(char *)((longlong)param_2 + 0x54),
                    (ulonglong)*(uint *)(param_2 + 6));
    *(int *)((longlong)param_2 + 0x11c) = (int)param_2[0x10] * (int)param_2[6];
    *(undefined1 *)((longlong)param_2 + 0x179) = *(undefined1 *)((longlong)param_2 + 0x34);
    *(undefined1 *)((longlong)param_2 + 0x17e) = *(undefined1 *)((longlong)param_2 + 0x35);
  }
  if ((*(char *)(lVar4 + 5) != '\x01') || ((char)param_1[0x22] != '\0')) {
    if ((*(char *)((ulonglong)*(byte *)(lVar4 + 6) + 0x3d9 + (longlong)param_1) != '\0') &&
       (((char)param_2[0xf] != '\0' &&
        (uVar6 = param_1[0x191b] - 1, uVar6 != *(uint *)((longlong)param_2 + 0x7c))))) {
      *(uint *)((longlong)param_2 + 0x7c) = uVar6;
      uVar10 = *(ushort *)
                (*(longlong *)(param_1 + (ulonglong)(uVar6 & 1) * 2 + 0x1b5e) + 0x28 +
                (ulonglong)*(byte *)(lVar4 + 6) * 8);
      *puVar1 = uVar10;
      *(ushort *)((longlong)param_2 + 0x9a) = uVar10;
      *(undefined2 *)((longlong)param_2 + 0x162) = *(undefined2 *)(lVar4 + 0x14);
    }
    goto LAB_140008d81;
  }
  if (((char)param_2[0xf] != '\0') &&
     (((uVar6 = param_1[0x191b] - 1, (char)param_2[0xb] != '\0' ||
       (*(char *)((longlong)param_2 + 0x79) != '\0')) ||
      (uVar6 != *(uint *)((longlong)param_2 + 0x7c))))) {
    *(uint *)((longlong)param_2 + 0x7c) = uVar6;
    iVar7 = MR_ldBlockSizeGet((ulonglong)*(byte *)(lVar4 + 6),
                              *(longlong *)(param_1 + (ulonglong)(uVar6 & 1) * 2 + 0x1b5e),
                              (longlong)param_1);
    *(int *)(param_2 + 0x10) = iVar7;
    uVar9 = BuildWithRaidMap(param_1,param_2,puVar1,
                             *(longlong *)(param_1 + (ulonglong)(uVar6 & 1) * 2 + 0x1b5e));
    if ((char)uVar9 == '\0') {
      StorPortLogError(param_1,0,0xff,0xff,0xff,6,0x52);
    }
  }
  if (*(char *)((longlong)param_2 + 0x103) != '\0') goto LAB_140008d81;
  if ((char)param_2[3] == '\0') {
LAB_140008d1f:
    if (*(char *)((longlong)param_2 + 0x19) == '\0') goto LAB_140008d81;
  }
  else {
    uVar9 = (ulonglong)*(byte *)(lVar4 + 6);
    pcVar11 = (char *)(uVar9 * 0xc08 + *(longlong *)(param_1 + 0x1924));
    if (*pcVar11 != '\0') {
      lVar4 = *(longlong *)
               (param_1 + (ulonglong)(*(uint *)((longlong)param_2 + 0x7c) & 1) * 2 + 0x1b5e);
      uVar10 = *(ushort *)
                ((ulonglong)*(byte *)((longlong)param_2 + 0x93) * 0x128 + 0x49e0 +
                lVar4 + (ulonglong)*(byte *)(lVar4 + 0x828 + uVar9) * 0x9e0);
      bVar5 = MegaSASCheckBestRaid1Arm
                        ((longlong)pcVar11,(longlong)param_1,uVar9,
                         *(byte *)((longlong)param_2 + 0x92),param_2[5],*(uint *)(param_2 + 6),lVar4
                         ,(longlong)param_2);
      uVar10 = *(ushort *)
                (*(longlong *)
                  (param_1 + (ulonglong)(*(uint *)((longlong)param_2 + 0x7c) & 1) * 2 + 0x1b5e) +
                 0x928 + ((ulonglong)uVar10 * 0x20 + (ulonglong)bVar5) * 2);
      if (uVar10 != 0xffff) {
        uVar3 = *(ushort *)
                 (*(longlong *)
                   (param_1 + (ulonglong)(*(uint *)((longlong)param_2 + 0x7c) & 1) * 2 + 0x1b5e) +
                  0x28 + (ulonglong)uVar10 * 8);
        piVar2 = (int *)(pcVar11 + (ulonglong)uVar10 * 4 + 4);
        param_2[0xe] = (longlong)piVar2;
        LOCK();
        *piVar2 = *piVar2 + 1;
        UNLOCK();
        if (*puVar1 != uVar3) {
          *(ushort *)((longlong)param_2 + 0x9a) = uVar3;
          *puVar1 = uVar3;
          *(byte *)((longlong)param_2 + 0x17c) = *(byte *)((longlong)param_2 + 0x17c) | bVar5 != 0;
        }
      }
    }
    if ((char)param_2[3] == '\0') goto LAB_140008d1f;
  }
  UpdateCDB((longlong)param_1,param_2,(longlong)puVar1);
LAB_140008d81:
  if ((*(char *)((longlong)param_1 + 0x6469) != '\0') &&
     (*(char *)((longlong)param_2 + 0x103) == '\0')) {
    *(undefined1 *)((longlong)param_2 + 0x102) = 0;
    *(ushort *)((longlong)param_2 + 0x124) = *(ushort *)((longlong)param_2 + 0x124) | 0x4000;
  }
  if (*(ushort *)((longlong)param_2 + 0x34) < 8) {
    iVar7 = (uint)*(byte *)((longlong)param_2 + 0x36) * (uint)*(ushort *)((longlong)param_2 + 0x34);
  }
  else {
    iVar7 = (uint)*(byte *)((longlong)param_2 + 0x36) << 3;
  }
  MemFastMove((undefined8 *)
              ((ulonglong)*(ushort *)((longlong)param_2 + 0x96) * 0x100 +
              *(longlong *)(param_1 + 0x1928)),(undefined8 *)puVar1,iVar7 + 0x80);
  if (cVar13 != '\0') {
    *(undefined1 *)
     ((ulonglong)*(ushort *)((longlong)param_2 + 0x96) * 0x100 + 0xff +
     *(longlong *)(param_1 + 0x1928)) = 0;
  }
                    /* WARNING: Could not recover jumptable at 0x000140008e1d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(longlong *)(param_1 + 0x5e) + 0x50))(param_1,param_2);
  return;
}



===== MPT_UpdateReplyQueue @ 140008e90 =====

void MPT_UpdateReplyQueue(longlong param_1)

{
  longlong lVar1;
  bool bVar2;
  longlong *plVar3;
  ushort uVar4;
  uint uVar5;
  ulonglong uVar6;
  ushort *puVar7;
  int iVar8;
  
  bVar2 = true;
  while( true ) {
    iVar8 = 0;
    if (*(char *)(param_1 + 0x48f1) != '\0') {
      puVar7 = (ushort *)(param_1 + 0x64a8);
      do {
        uVar6 = (ulonglong)*puVar7;
        uVar5 = (uint)*puVar7;
        plVar3 = (longlong *)(*(longlong *)(puVar7 + 4) + uVar6 * 8);
        lVar1 = *(longlong *)(*(longlong *)(puVar7 + 4) + uVar6 * 8);
        while (lVar1 != -1) {
          LOCK();
          *(int *)(param_1 + 0x1a4) = *(int *)(param_1 + 0x1a4) + -1;
          UNLOCK();
          uVar4 = (short)uVar6 + 1;
          uVar6 = (ulonglong)uVar4;
          *plVar3 = -1;
          if ((uint)uVar4 < *(uint *)(param_1 + 0x88c)) {
            plVar3 = plVar3 + 1;
          }
          else {
            plVar3 = *(longlong **)(puVar7 + 4);
            uVar6 = 0;
          }
          uVar5 = (uint)uVar6;
          lVar1 = *plVar3;
        }
        *puVar7 = (ushort)uVar5;
        *(uint *)(*(longlong *)(param_1 + 0x80) + 0x6c) = iVar8 << 0x18 | uVar5;
        LOCK();
        UNLOCK();
        iVar8 = iVar8 + 1;
        puVar7 = puVar7 + 8;
      } while (iVar8 < (int)(uint)*(byte *)(param_1 + 0x48f1));
    }
    if ((*(int *)(param_1 + 0x1a4) < 1) || (!bVar2)) break;
    bVar2 = false;
    StorPortStallExecution(1000);
  }
  return;
}



===== UpdateCDB @ 140008f60 =====

void UpdateCDB(longlong param_1,longlong *param_2,longlong param_3)

{
  undefined1 uVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined2 uVar5;
  longlong lVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  
  uVar3 = param_2[5];
  uVar2 = *(uint *)(param_2 + 6);
  lVar4 = param_2[0x10];
  lVar6 = MegaSAS_DoDIF(param_1,(ulonglong)*(byte *)(*param_2 + 6),
                        *(longlong *)
                         (param_1 + 0x6d78 +
                         (ulonglong)(*(uint *)((longlong)param_2 + 0x7c) & 1) * 8));
  if ((char)lVar6 == '\0') {
    if (((0xb < *(byte *)((longlong)param_2 + 0x54)) && (uVar3 < 0x100000000)) && (uVar2 < 0x10000))
    {
      if (*(byte *)((longlong)param_2 + 0x54) == 0x10) {
        uVar7 = *(undefined1 *)(param_3 + 0x4e);
        uVar8 = *(undefined1 *)(param_3 + 0x4f);
      }
      else {
        uVar7 = *(undefined1 *)(param_3 + 0x4a);
        uVar8 = *(undefined1 *)(param_3 + 0x4b);
      }
      uVar1 = *(undefined1 *)(param_3 + 0x41);
      MemFastZero((undefined8 *)(param_3 + 0x40),0x20);
      CDB_SetBlockCnt(param_3 + 0x40,'\n',(ulonglong)uVar2);
      CDB_SetStartLBA(param_3 + 0x40,'\n',uVar3);
      *(undefined1 *)((longlong)param_2 + 0x54) = 10;
      *(undefined2 *)(param_3 + 0x24) = 10;
      lVar4 = param_2[3];
      *(undefined1 *)(param_3 + 0x49) = uVar8;
      uVar8 = 0x2a;
      if ((char)lVar4 != '\0') {
        uVar8 = 0x28;
      }
      *(undefined1 *)(param_3 + 0x40) = uVar8;
      *(undefined1 *)(param_3 + 0x41) = uVar1;
      *(undefined1 *)(param_3 + 0x46) = uVar7;
    }
  }
  else {
    MemFastZero((undefined8 *)(param_3 + 0x40),0x20);
    *(undefined1 *)(param_3 + 0x40) = 0x7f;
    *(undefined1 *)(param_3 + 0x47) = 0x18;
    lVar6 = param_2[3];
    *(undefined1 *)(param_3 + 0x4a) = 0x20;
    uVar7 = 0xb;
    if ((char)lVar6 != '\0') {
      uVar7 = 9;
    }
    *(char *)(param_3 + 0x53) = (char)uVar3;
    *(undefined1 *)(param_3 + 0x49) = uVar7;
    *(char *)(param_3 + 0x4c) = (char)(uVar3 >> 0x38);
    *(char *)(param_3 + 0x4d) = (char)(uVar3 >> 0x30);
    *(char *)(param_3 + 0x4e) = (char)(uVar3 >> 0x28);
    *(char *)(param_3 + 0x4f) = (char)(uVar3 >> 0x20);
    *(char *)(param_3 + 0x50) = (char)(uVar3 >> 0x18);
    *(char *)(param_3 + 0x51) = (char)(uVar3 >> 0x10);
    *(char *)(param_3 + 0x52) = (char)(uVar3 >> 8);
    *(char *)(param_3 + 0x5c) = (char)(uVar2 >> 0x18);
    *(char *)(param_3 + 0x5d) = (char)(uVar2 >> 0x10);
    *(char *)(param_3 + 0x5f) = (char)uVar2;
    *(char *)(param_3 + 0x5e) = (char)(uVar2 >> 8);
    uVar5 = 0x8703;
    *(uint *)(param_3 + 0x54) =
         (((int)param_2[4] << 8 | (uint)*(byte *)((longlong)param_2 + 0x21)) << 8 |
         (uint)*(byte *)((longlong)param_2 + 0x22)) << 8 | (uint)*(byte *)((longlong)param_2 + 0x23)
    ;
    *(undefined2 *)(param_3 + 0x5a) = 0xffff;
    if ((char)param_2[3] == '\0') {
      uVar5 = 0x8004;
    }
    *(uint *)(param_3 + 0x3c) = *(uint *)(param_3 + 0x3c) | 0x10000000;
    *(undefined2 *)(param_3 + 0x26) = uVar5;
    *(int *)(param_3 + 0x28) = (int)lVar4;
    *(undefined1 *)((longlong)param_2 + 0x54) = 0x20;
    *(undefined2 *)(param_3 + 0x24) = 0x20;
  }
  return;
}



===== CheckCmdTimeout @ 140009170 =====

void CheckCmdTimeout(longlong param_1)

{
  int iVar1;
  longlong local_res8;
  
  iVar1 = extendedTimeout;
  if (*(char *)(param_1 + 0x6450) == '\0') {
    return;
  }
  StorPortQuerySystemTime(&local_res8);
  if (local_res8 < (longlong)((ulonglong)(uint)(iVar1 * 10) + *(longlong *)(param_1 + 0x6448))) {
    StorPortNotification(6,param_1,CheckCmdTimeout,1000000);
    return;
  }
  *(undefined1 *)(param_1 + 0x6452) = 1;
  StartAdapterReset(param_1);
  return;
}



===== CheckFirmwareFault @ 1400091f0 =====

longlong CheckFirmwareFault(longlong param_1)

{
  uint uVar1;
  undefined8 in_RAX;
  undefined8 uVar2;
  
  if (*(char *)(param_1 + 0x6454) == '\0') {
    uVar1 = (**(code **)(*(longlong *)(param_1 + 0x178) + 0x30))(*(undefined8 *)(param_1 + 0x80));
    *(uint *)(param_1 + 0x1ac) = uVar1;
    if (uVar1 < 0x10000000) {
      *(uint *)(param_1 + 0x1ac) = uVar1 | 0xf0000000;
    }
    uVar1 = *(uint *)(param_1 + 0x1ac) & 0xf0000000;
    if (uVar1 != 0xf0000000) {
      return (ulonglong)(uint3)(uVar1 >> 8) << 8;
    }
    if (*(char *)(param_1 + 0x88) != '\0') {
      uVar2 = SetDeadAdapter(param_1,0x36);
      return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
    }
    if ((*(uint *)(param_1 + 0x1ac) & 2) == 0) {
      uVar2 = SetDeadAdapter(param_1,0x32);
      return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
    }
    if (*(char *)(param_1 + 0x1cd) == '\0') {
      uVar2 = SetDeadAdapter(param_1,0x31);
      return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
    }
    StorPortLogError(param_1,0,0xff,0xff,0xff,6,3);
    (**(code **)(*(longlong *)(param_1 + 0x178) + 0x28))(param_1);
    DoPauseInput(param_1);
    *(undefined1 *)(param_1 + 0x6450) = 0;
    *(undefined1 *)(param_1 + 0x6452) = 1;
    in_RAX = StorPortNotification(6,param_1,StartAdapterReset,1000000);
  }
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}



===== CheckResetRetries @ 140009310 =====

ulonglong CheckResetRetries(longlong param_1)

{
  undefined4 uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  
  *(char *)(param_1 + 0x645c) = *(char *)(param_1 + 0x645c) + '\x01';
  if (*(byte *)(param_1 + 0x645d) < *(byte *)(param_1 + 0x645c)) {
    uVar2 = SetDeadAdapter(param_1,0x35);
    return uVar2 & 0xffffffffffffff00;
  }
  uVar1 = (**(code **)(*(longlong *)(param_1 + 0x178) + 0x30))(*(undefined8 *)(param_1 + 0x80));
  *(undefined4 *)(param_1 + 0x1ac) = uVar1;
  uVar3 = (**(code **)(*(longlong *)(param_1 + 0x178) + 0x48))(param_1);
  if ((char)uVar3 == '\0') {
    uVar2 = SetDeadAdapter(param_1,0x33);
    return uVar2 & 0xffffffffffffff00;
  }
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== MegaSASResetBus @ 140009390 =====

undefined8 MegaSASResetBus(longlong param_1)

{
  ulonglong in_RAX;
  undefined8 uVar1;
  undefined8 local_res8 [4];
  
  if (((*(char *)(param_1 + 0x6454) == '\0') && (*(char *)(param_1 + 0x6452) == '\0')) &&
     (*(char *)(param_1 + 0x6453) == '\0')) {
    in_RAX = CheckFirmwareFault(param_1);
    if ((char)in_RAX == '\0') {
      in_RAX = (ulonglong)*(uint *)(param_1 + 0x1a0);
      if (*(uint *)(param_1 + 0x1a0) == 0) {
        if (*(char *)(param_1 + 0x88) == '\0') {
          ReturnReqsToSystem(param_1,'\x01');
        }
        uVar1 = DoResumeInput(param_1);
        return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
      }
      if (*(char *)(param_1 + 0x6450) == '\0') {
        *(undefined1 *)(param_1 + 0x6450) = 1;
        DoPauseInput(param_1);
        StorPortQuerySystemTime(local_res8);
        *(undefined8 *)(param_1 + 0x6448) = local_res8[0];
        in_RAX = StorPortNotification(6,param_1,CheckCmdTimeout,1000000);
      }
    }
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== RestartWhenReady @ 140009450 =====

void RestartWhenReady(uint *param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  longlong local_res8 [4];
  undefined4 uVar3;
  
  if ((char)param_1[0x1915] == '\0') {
    uVar1 = CheckFirmwareReady((longlong)param_1);
    if ((char)uVar1 == '\0') {
      if ((param_1[0x6b] & 0xf0000000) == 0xf0000000) {
        uVar3 = 3;
      }
      else {
        StorPortQuerySystemTime(local_res8);
        if (local_res8[0] < *(longlong *)(param_1 + 0x1912) + 3000000000) goto LAB_1400094fb;
        uVar3 = 0x34;
      }
      StorPortLogError(param_1,0,0xff,0xff,0xff,6,uVar3);
    }
    else {
      if ((char)param_1[0x1b56] == '\0') {
        param_1[0x1b4f] = 2;
        param_1[0x1b52] = 0;
        param_1[0x1b53] = 0;
        WatchDogTimer((longlong)param_1);
        return;
      }
      uVar1 = InitializeAdapter(param_1);
      if ((char)uVar1 != '\0') {
        uVar2 = ResubmitPendingReqs((longlong)param_1);
        if ((char)uVar2 == '\0') {
          return;
        }
        *(undefined2 *)((longlong)param_1 + 0x6452) = 0;
        *(undefined1 *)(param_1 + 0x1914) = 0;
        *(undefined1 *)(param_1 + 0x1917) = 0;
        (**(code **)(*(longlong *)(param_1 + 0x5e) + 0x20))(param_1);
        DoResumeInput((longlong)param_1);
        return;
      }
    }
    uVar2 = CheckResetRetries((longlong)param_1);
    if ((char)uVar2 != '\0') {
      StorPortQuerySystemTime(local_res8);
      *(longlong *)(param_1 + 0x1912) = local_res8[0];
LAB_1400094fb:
      StorPortNotification(6,param_1,RestartWhenReady,1000000);
      return;
    }
  }
  return;
}



===== ResubmitPendingReqs @ 140009590 =====

undefined8 ResubmitPendingReqs(longlong param_1)

{
  longlong *plVar1;
  ulonglong in_RAX;
  ulonglong uVar2;
  int iVar3;
  uint uVar4;
  uint local_res8 [2];
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0x898) != 0) {
    do {
      in_RAX = uVar2;
      iVar3 = (int)in_RAX;
      plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x180) + in_RAX * 8);
      if (plVar1 != (longlong *)0x0) {
        if (*plVar1 == 0) {
          if (*(char *)(param_1 + 0x6454) == '\0') {
            MemFastZero((undefined8 *)local_res8,4);
            local_res8[0] = local_res8[0] | 0x20;
            *(undefined1 *)(param_1 + 0x6450) = 0;
            *(undefined1 *)(param_1 + 0x6452) = 0;
            *(undefined8 *)(param_1 + 400) = 0;
            *(undefined1 *)(param_1 + 0x6454) = 1;
            StorPortLogError(param_1,0,0xff,0xff,0xff,6,0x23);
            StorPortNotification(6,param_1,RestartWhenReady);
            (**(code **)(*(longlong *)(param_1 + 0x178) + 0x28))(param_1);
            (**(code **)(*(longlong *)(param_1 + 0x178) + 0x40))
                      (*(undefined8 *)(param_1 + 0x80),local_res8[0]);
            ReturnReqsToSystem(param_1,'\x01');
            StorPortNotification(7,param_1);
            StorPortNotification(7,param_1);
            uVar2 = DoResumeInput(param_1);
            return uVar2 & 0xffffffffffffff00;
          }
          uVar2 = StorPortLogError(param_1,0,0xff,0xff,0xff,6,0x23);
          return uVar2 & 0xffffffffffffff00;
        }
        *(undefined2 *)((longlong)plVar1 + 0x102) = 0xff;
        in_RAX = (**(code **)(*(longlong *)(param_1 + 0x178) + 0x50))(param_1);
      }
      uVar4 = iVar3 + 1;
      uVar2 = (ulonglong)uVar4;
    } while (uVar4 < *(uint *)(param_1 + 0x898));
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== ReturnReqsToSystem @ 140009710 =====

ulonglong ReturnReqsToSystem(longlong param_1,char param_2)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined1 uVar5;
  longlong *plVar6;
  longlong *plVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  
  plVar6 = (longlong *)(param_1 + 0x8c0);
  iVar8 = 0;
  uVar10 = 0;
  do {
    plVar7 = (longlong *)*plVar6;
    plVar6[1] = 0;
    *plVar6 = 0;
    *(undefined1 *)((longlong)plVar6 + 0x11) = 0;
    if (plVar7 != (longlong *)0x0) {
      if (*plVar7 == 0) {
        if (param_2 == '\0') goto LAB_14000976d;
      }
      else {
        uVar5 = 0xb;
        if (param_2 != '\0') {
          uVar5 = 0x11;
        }
        do {
          lVar3 = *plVar7;
          *(undefined1 *)(lVar3 + 3) = uVar5;
          *(undefined1 *)(lVar3 + 4) = 2;
          plVar7 = (longlong *)plVar7[0xc];
          StorPortNotification(0,param_1);
        } while (plVar7 != (longlong *)0x0);
      }
    }
    uVar10 = uVar10 + 1;
    plVar6 = plVar6 + 8;
  } while (uVar10 < 0x100);
  uVar10 = 0;
  iVar9 = 0;
  if (*(int *)(param_1 + 0x898) != 0) {
    do {
      lVar3 = *(longlong *)(param_1 + 0x180);
      plVar6 = *(longlong **)(lVar3 + (ulonglong)uVar10 * 8);
      iVar8 = iVar9;
      if (plVar6 != (longlong *)0x0) {
        if (*plVar6 == 0) goto LAB_14000976d;
        if ((param_2 == '\0') && (*(char *)(*plVar6 + 2) == '\x02')) {
          iVar8 = iVar9 + 1;
        }
        else {
          uVar2 = *(uint *)(plVar6 + 1);
          cVar1 = *(char *)((longlong)plVar6 + 0x1c);
          if (*(longlong **)(lVar3 + (ulonglong)uVar2 * 8) != plVar6) {
            uVar4 = SetDeadAdapter(param_1,0x21);
            return uVar4 & 0xffffffffffffff00;
          }
          *(undefined8 *)(lVar3 + (ulonglong)uVar2 * 8) = 0;
          *(uint *)(param_1 + 0x188) = uVar2;
          LOCK();
          *(int *)(param_1 + 0x1a0) = *(int *)(param_1 + 0x1a0) + -1;
          UNLOCK();
          if ((cVar1 == '\0') && (*(int *)(param_1 + 0x894) != 0)) {
            LOCK();
            *(int *)(param_1 + 0x1a8) = *(int *)(param_1 + 0x1a8) + -1;
            UNLOCK();
          }
          if ((*(int *)(param_1 + 0x1a0) < 0) ||
             ((*(int *)(param_1 + 0x894) != 0 && (*(int *)(param_1 + 0x1a8) < 0)))) {
            uVar4 = SetDeadAdapter(param_1,0x25);
            return uVar4 & 0xffffffffffffff00;
          }
          uVar5 = 0xb;
          if (param_2 != '\0') {
            uVar5 = 0x11;
          }
          do {
            lVar3 = *plVar6;
            *(undefined1 *)(lVar3 + 3) = uVar5;
            *(undefined1 *)(lVar3 + 4) = 2;
            plVar6 = (longlong *)plVar6[0xc];
            StorPortNotification(0,param_1);
          } while (plVar6 != (longlong *)0x0);
        }
      }
      uVar10 = uVar10 + 1;
      iVar9 = iVar8;
    } while (uVar10 < *(uint *)(param_1 + 0x898));
  }
  if (iVar8 == *(int *)(param_1 + 0x1a0)) {
    uVar4 = CONCAT71((uint7)(uint3)((uint)*(int *)(param_1 + 0x1a0) >> 8),1);
  }
  else {
LAB_14000976d:
    uVar4 = SetDeadAdapter(param_1,0x23);
    uVar4 = uVar4 & 0xffffffffffffff00;
  }
  return uVar4;
}



===== SetDeadAdapter @ 140009910 =====

void SetDeadAdapter(longlong param_1,undefined4 param_2)

{
  uint local_res8 [2];
  
  if (*(char *)(param_1 + 0x6454) == '\0') {
    MemFastZero((undefined8 *)local_res8,4);
    local_res8[0] = local_res8[0] | 0x20;
    *(undefined1 *)(param_1 + 0x6450) = 0;
    *(undefined1 *)(param_1 + 0x6452) = 0;
    *(undefined8 *)(param_1 + 400) = 0;
    *(undefined1 *)(param_1 + 0x6454) = 1;
    StorPortLogError(param_1,0,0xff,0xff,0xff,6,param_2);
    StorPortNotification(6,param_1,RestartWhenReady);
    (**(code **)(*(longlong *)(param_1 + 0x178) + 0x28))(param_1);
    (**(code **)(*(longlong *)(param_1 + 0x178) + 0x40))
              (*(undefined8 *)(param_1 + 0x80),local_res8[0]);
    ReturnReqsToSystem(param_1,'\x01');
    StorPortNotification(7,param_1);
    StorPortNotification(7,param_1);
    DoResumeInput(param_1);
    return;
  }
  StorPortLogError(param_1,0,0xff,0xff,0xff,6,param_2);
  return;
}



===== StartAdapterReset @ 140009a30 =====

void StartAdapterReset(longlong param_1)

{
  char cVar1;
  ulonglong uVar2;
  undefined8 local_res8 [4];
  
  uVar2 = ReturnReqsToSystem(param_1,'\0');
  if ((char)uVar2 == '\0') {
    return;
  }
  StorPortLogError(param_1,0,0xff,0xff,0xff,6,0x30);
  cVar1 = (**(code **)(*(longlong *)(param_1 + 0x178) + 0x48))(param_1);
  if (cVar1 == '\0') {
    SetDeadAdapter(param_1,0x33);
    return;
  }
  *(undefined2 *)(param_1 + 0x645c) = 0x200;
  StorPortQuerySystemTime(local_res8);
  *(undefined8 *)(param_1 + 0x6448) = local_res8[0];
  StorPortNotification(6,param_1,RestartWhenReady,1000000);
  return;
}



===== SyncronizeInitializeAdapter @ 140009ae0 =====

undefined8 SyncronizeInitializeAdapter(uint *param_1)

{
  byte bVar1;
  longlong lVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined8 uVar5;
  byte bVar6;
  ulonglong uVar7;
  undefined4 *puVar8;
  longlong lVar9;
  undefined8 local_res8;
  
  do {
    uVar4 = param_1[0x1b52];
    if (uVar4 - 3 < 2) {
      lVar9 = *(longlong *)(param_1 + 0x38);
    }
    else if (uVar4 - 0xb < 2) {
      lVar9 = *(longlong *)(param_1 + 0x36);
    }
    else {
      lVar9 = *(longlong *)(param_1 + 0x32);
    }
    switch(uVar4) {
    case 0:
      *(undefined1 *)((longlong)param_1 + 0x646b) = 0;
      *(undefined1 *)((longlong)param_1 + 0x1d6) = 0;
      param_1[0x1b53] = 0;
      if ((char)param_1[0x191a] == '\0') {
        uVar4 = 0;
        if (*(char *)((longlong)param_1 + 0x48f1) != '\0') {
          do {
            uVar7 = (ulonglong)uVar4;
            uVar4 = uVar4 + 1;
            puVar8 = (undefined4 *)(uVar7 * 0x10 + *(longlong *)(param_1 + 0x1918));
            puVar8[1] = *puVar8;
          } while (uVar4 < *(byte *)((longlong)param_1 + 0x48f1));
        }
        *(undefined1 *)((longlong)param_1 + 0x645f) = 0;
      }
      param_1[0x1b52] = 1;
      break;
    case 1:
      uVar3 = (*(code *)**(undefined8 **)(param_1 + 0x5e))(param_1,lVar9);
      *(undefined1 *)((longlong)param_1 + 0x6d59) = uVar3;
      param_1[0x1916] = 60000000;
      param_1[0x1b52] = 2;
      param_1[0x1b53] = 5;
      break;
    case 2:
    case 4:
    case 6:
    case 8:
    case 10:
    case 0xc:
      if (*(char *)(lVar9 + 0x102) != -1) {
        if (*(char *)(lVar9 + 0x102) != '\0') {
          StorPortLogError(param_1,0,0xff,CONCAT71((int7)((ulonglong)lVar9 >> 8),0xff),0xff,6,0x13);
          param_1[0x1b52] = 0xe;
          break;
        }
        if (uVar4 == 2) {
          if (*(char *)((longlong)param_1 + 0x6d59) == '\0') {
            param_1[0x1b52] = 1;
            break;
          }
          uVar4 = (**(code **)(*(longlong *)(param_1 + 0x5e) + 0x30))
                            (*(undefined8 *)(param_1 + 0x20));
          param_1[0x6b] = uVar4;
          if ((uVar4 & 0xf0000000) != 0xc0000000) {
            param_1[0x1b52] = 0xe;
            break;
          }
        }
        else {
          if (uVar4 == 6) {
            lVar2 = *(longlong *)(param_1 + 0x4e);
            bVar6 = (byte)(*(uint *)(lVar2 + 0x7e8) >> 5) & 1;
            *(byte *)(param_1 + 0x1b5c) = bVar6;
            *param_1 = *(uint *)(lVar2 + 0x7a4) >> 0x14 & 1;
            bVar1 = *(byte *)(lVar2 + 0x53f);
            param_1[0x1b63] = 0x1000100;
            if (0x40 < bVar1) {
              bVar6 = 1;
            }
            *(byte *)(param_1 + 0x1b5c) = bVar6;
            if (bVar6 == 0) {
              uVar4 = param_1[0x1b59];
            }
            else {
              uVar4 = param_1[0x1b5a];
            }
            param_1[7000] = uVar4;
            if (bVar6 == 0) {
              param_1[0x1b62] = 0x1000040;
            }
            else {
              param_1[0x1b62] = 0x1000100;
            }
            param_1[0x1b4e] = (byte)~*(byte *)(lVar2 + 0x5b0) >> 4 & 1;
          }
          CompleteDCMD((int *)param_1,lVar9 + 0x100,'\x01');
        }
        param_1[0x1b52] = param_1[0x1b53];
        break;
      }
      uVar4 = (**(code **)(*(longlong *)(param_1 + 0x5e) + 0x30))(*(undefined8 *)(param_1 + 0x20));
      param_1[0x6b] = uVar4;
      if (((uVar4 & 0xf0000000) != 0xf0000000) && (0 < (int)param_1[0x1916])) {
        param_1[0x1916] = param_1[0x1916] - 10000;
        StorPortNotification(6,param_1,WatchDogTimer,10000);
        return 1;
      }
      StorPortLogError(param_1,0,0xff,0xff,0xff,6,0x13);
      param_1[0x1b53] = param_1[0x1b52];
      param_1[0x1b52] = 0xe;
      break;
    case 3:
      param_1[0x1b52] = 4;
      param_1[0x1b53] = 7;
      WDTSetupAndSendDCMD((longlong)param_1,0x2010100);
      break;
    case 5:
      param_1[0x1b52] = 6;
      param_1[0x1b53] = 3;
      WDTSetupAndSendDCMD((longlong)param_1,0x1010000);
      break;
    case 7:
      if ((char)param_1[0x22] == '\0') {
        param_1[0x1b52] = 8;
        param_1[0x1b53] = 9;
        WDTSetupAndSendDCMD((longlong)param_1,0x1020100);
      }
      else {
        param_1[0x1b52] = 0xf;
      }
      break;
    case 9:
      if ((char)param_1[0x22] == '\0') {
        param_1[0x1b52] = 10;
        param_1[0x1b53] = 0xb;
        WDTSetupAndSendDCMD((longlong)param_1,0x1040100);
      }
      else {
        param_1[0x1b52] = 0xf;
      }
      break;
    case 0xb:
      if ((char)param_1[0x22] == '\0') {
        if (((char)param_1[0x191a] == '\0') || (*(char *)((longlong)param_1 + 0x646a) == '\0')) {
          param_1[0x1b52] = 0xd;
        }
        else {
          param_1[0x191b] = 0;
          param_1[0x1b52] = 0xc;
          param_1[0x1b53] = 0xd;
          WDTSetupAndSendDCMD((longlong)param_1,0x300e101);
        }
      }
      else {
        param_1[0x1b52] = 0xf;
      }
      break;
    case 0xd:
      if ((char)param_1[0x191a] != '\0') {
        MPT_UpdateReplyQueue((longlong)param_1);
        if (0 < (int)param_1[0x69]) {
          param_1[0x1b52] = 0xe;
          StorPortLogError(param_1,0,0xff,0xff,0xff,6,100);
          break;
        }
        if (*(char *)((longlong)param_1 + 0x646a) != '\0') {
          param_1[0x191b] = 1;
          IssueDCMD((longlong)param_1,0x300e101);
        }
      }
      *(undefined1 *)((longlong)param_1 + 0x1d5) = 0;
      IssueDCMD((longlong)param_1,0x1040500);
      param_1[0x1b52] = 0xf;
      break;
    case 0xe:
      if (param_1[0x1b51] != 4) {
        uVar5 = CheckResetRetries((longlong)param_1);
        if ((char)uVar5 != '\0') {
          StorPortQuerySystemTime(&local_res8);
          *(undefined8 *)(param_1 + 0x1912) = local_res8;
          StorPortNotification(6,param_1,RestartWhenReady,1000000);
        }
switchD_140009b54_default:
        return 1;
      }
      param_1[0x1b52] = 7;
      break;
    case 0xf:
      if ((char)param_1[0x22] == '\0') {
        MemFastZero(*(undefined8 **)(param_1 + 0x1924),((ushort)param_1[0x74] + 0xc08) * 0x100);
      }
      MemFastZero((undefined8 *)(param_1 + 0x230),0x4000);
      uVar5 = ResubmitPendingReqs((longlong)param_1);
      if ((char)uVar5 != '\0') {
        *(undefined1 *)((longlong)param_1 + 0x6452) = 0;
        (**(code **)(*(longlong *)(param_1 + 0x5e) + 0x20))(param_1);
        *(undefined1 *)(param_1 + 0x1914) = 0;
        *(undefined1 *)((longlong)param_1 + 0x6453) = 0;
        *(undefined1 *)(param_1 + 0x1917) = 0;
        param_1[0x1b4f] = 0;
        DoResumeInput((longlong)param_1);
        if ((char)param_1[0x1fa] != '\0') {
          ScsiPortWmiFireLogicalUnitEvent
                    (param_1,-1,0,0,(int *)&MegaSASWmiSetupDataGuid,0,0x10,(int *)(param_1 + 0x1fb))
          ;
        }
      }
    default:
      goto switchD_140009b54_default;
    }
  } while( true );
}



===== PPC_ResetController @ 14000a110 =====

ulonglong PPC_ResetController(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  char cVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  bool bVar8;
  
  *(undefined1 *)(param_1 + 0x6453) = 1;
  *(undefined1 *)(param_1 + 0x6451) = 1;
  *(undefined2 *)(param_1 + 0x6420) = 0;
  *(undefined1 *)(param_1 + 0x6422) = 0;
  *(undefined1 *)(param_1 + 0x642c) = 0;
  lVar7 = 30000;
  *(undefined8 *)(param_1 + 0x6424) = 0;
  do {
    StorPortStallExecution(100);
    lVar7 = lVar7 + -1;
  } while (lVar7 != 0);
  bVar8 = *(char *)(param_1 + 0x1cf) == '\0';
  lVar7 = 8;
  if (bVar8) {
    lVar7 = 0xf8;
  }
  lVar5 = 4;
  if (bVar8) {
    lVar5 = 0xfc;
  }
  *(undefined4 *)(lVar5 + *(longlong *)(param_1 + 0x80)) = 0;
  LOCK();
  UNLOCK();
  if (*(char *)(param_1 + 0x6468) != '\0') {
    *(undefined4 *)(lVar5 + *(longlong *)(param_1 + 0x80)) = 0xf;
    LOCK();
    UNLOCK();
  }
  *(undefined4 *)(lVar5 + *(longlong *)(param_1 + 0x80)) = 4;
  LOCK();
  UNLOCK();
  *(undefined4 *)(lVar5 + *(longlong *)(param_1 + 0x80)) = 0xb;
  LOCK();
  UNLOCK();
  *(undefined4 *)(lVar5 + *(longlong *)(param_1 + 0x80)) = 2;
  LOCK();
  UNLOCK();
  *(undefined4 *)(lVar5 + *(longlong *)(param_1 + 0x80)) = 7;
  LOCK();
  UNLOCK();
  *(undefined4 *)(lVar5 + *(longlong *)(param_1 + 0x80)) = 0xd;
  LOCK();
  UNLOCK();
  StorPortStallExecution(100);
  StorPortStallExecution(100);
  uVar1 = *(uint *)(lVar7 + *(longlong *)(param_1 + 0x80));
  cVar4 = (char)uVar1;
  uVar2 = 0;
  while (-1 < cVar4) {
    uVar3 = (ulonglong)uVar2;
    if (99 < uVar2) goto LAB_14000a2f9;
    StorPortStallExecution(100);
    uVar1 = *(uint *)(lVar7 + *(longlong *)(param_1 + 0x80));
    uVar2 = uVar2 + 1;
    cVar4 = (char)uVar1;
  }
  *(uint *)(lVar7 + *(longlong *)(param_1 + 0x80)) = uVar1 | 4;
  LOCK();
  UNLOCK();
  lVar5 = 30000;
  do {
    lVar6 = lVar5;
    StorPortStallExecution(100);
    lVar5 = lVar6 + -1;
  } while (lVar5 != 0);
  StorPortStallExecution((int)lVar6 + 99);
  lVar5 = *(longlong *)(param_1 + 0x80);
  uVar1 = *(uint *)(lVar7 + lVar5);
  uVar3 = 0;
  while( true ) {
    if ((uVar1 & 4) == 0) {
      *(undefined1 *)(param_1 + 0x6453) = 0;
      return CONCAT71((int7)((ulonglong)lVar5 >> 8),1);
    }
    if (999 < (uint)uVar3) break;
    StorPortStallExecution(100);
    lVar5 = *(longlong *)(param_1 + 0x80);
    uVar1 = *(uint *)(lVar7 + lVar5);
    uVar3 = (ulonglong)((uint)uVar3 + 1);
  }
LAB_14000a2f9:
  return uVar3 & 0xffffffffffffff00;
}



===== Xscale_ResetController @ 14000a300 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong Xscale_ResetController(longlong param_1)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 local_158 [32];
  uint *local_138;
  undefined4 local_130;
  undefined4 local_128;
  undefined8 local_118 [12];
  int local_b2 [7];
  uint local_94 [31];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)local_158;
  MemFastZero(local_118,0x100);
  uVar2 = (**(code **)(*(longlong *)(param_1 + 0x178) + 0x30))(*(undefined8 *)(param_1 + 0x80));
  *(uint *)(param_1 + 0x1ac) = (uint)uVar2;
  if ((((uint)uVar2 & 0xf0000000) == 0xf0000000) && ((uVar2 & 1) == 0)) {
    uVar2 = uVar2 & 0xffffffffffffff00;
  }
  else {
    *(undefined1 *)(param_1 + 0x6453) = 1;
    *(undefined4 *)(*(longlong *)(param_1 + 0x6460) + 4) = 0xdeaddead;
    *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x20) = 0x40;
    LOCK();
    UNLOCK();
    lVar3 = 30000;
    do {
      lVar4 = lVar3;
      StorPortStallExecution(100);
      lVar3 = lVar4 + -1;
    } while (lVar3 != 0);
    local_138 = (uint *)local_118;
    iVar1 = (int)lVar4;
    local_130 = 0x100;
    StorPortGetBusData(param_1,iVar1 + 3,*(undefined4 *)(param_1 + 8),
                       *(undefined4 *)(param_1 + 0x7c));
    uVar2 = (ulonglong)local_94[0];
    if ((local_94[0] & 2) != 0) {
      local_94[0] = local_94[0] & 0xfffffffd;
      local_138 = local_94;
      local_128 = 4;
      local_130 = 0x84;
      StorPortSetBusDataByOffset
                (param_1,iVar1 + 3,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x7c));
      lVar3 = 20000;
      do {
        lVar4 = lVar3;
        StorPortStallExecution(100);
        lVar3 = lVar4 + -1;
      } while (lVar3 != 0);
      local_138 = (uint *)local_118;
      iVar1 = (int)lVar4;
      local_130 = 0x100;
      uVar2 = StorPortGetBusData(param_1,iVar1 + 3,*(undefined4 *)(param_1 + 8),
                                 *(undefined4 *)(param_1 + 0x7c));
      if (local_b2[0] == 0xdddd) {
        local_138 = (uint *)local_b2;
        local_128 = 4;
        local_130 = 0x66;
        local_b2[0] = 0;
        uVar2 = StorPortSetBusDataByOffset
                          (param_1,iVar1 + 3,*(undefined4 *)(param_1 + 8),
                           *(undefined4 *)(param_1 + 0x7c));
      }
    }
    uVar2 = CONCAT71((int7)(uVar2 >> 8),1);
    *(undefined1 *)(param_1 + 0x6453) = 0;
  }
  return uVar2;
}



===== BusyThisRequest @ 14000a4d0 =====

void BusyThisRequest(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  
  lVar1 = *param_2;
  if (*(char *)(param_1 + 0x91) == '\0') {
    StorPortBusy(param_1,*(undefined4 *)(param_1 + 0x198));
  }
  else {
    *(undefined1 *)(lVar1 + 4) = 0x28;
  }
  *(undefined1 *)(lVar1 + 3) = 5;
  StorPortNotification(0,param_1,lVar1);
  return;
}



===== CheckForValidIO @ 14000a520 =====

ulonglong CheckForValidIO(longlong param_1,longlong param_2)

{
  byte bVar1;
  uint uVar2;
  ulonglong in_RAX;
  ulonglong uVar3;
  
  if (*(char *)(param_1 + 0x6454) != '\0') {
    *(undefined1 *)(param_2 + 3) = 0x11;
    return in_RAX & 0xffffffffffffff00;
  }
  if (((*(byte *)(param_2 + 6) == 0xff) || (*(char *)(param_2 + 7) != '\0')) ||
     ((*(char *)(param_2 + 5) == '\0' &&
      ((*(char *)(param_2 + 2) == '\0' &&
       (*(char *)((ulonglong)*(byte *)(param_2 + 6) + 0x1d9 + param_1) == '\0')))))) {
    *(undefined1 *)(param_2 + 3) = 0x20;
    return 0;
  }
  uVar3 = 0;
  if ((*(char *)(param_1 + 0x6450) == '\0') && (*(char *)(param_1 + 0x6452) == '\0')) {
    return 1;
  }
  bVar1 = *(byte *)(param_2 + 2);
  if (bVar1 == 2) {
    if (*(longlong *)(param_1 + 400) == 0) {
      return 1;
    }
  }
  else {
    uVar2 = bVar1 - 0x12;
    uVar3 = (ulonglong)uVar2;
    if (((byte)uVar2 < 2) || (bVar1 == 0x20)) {
      *(undefined1 *)(param_2 + 3) = 6;
      return (ulonglong)(uint3)(uVar2 >> 8) << 8;
    }
  }
  *(undefined1 *)(param_2 + 3) = 5;
  return uVar3 & 0xffffffffffffff00;
}



===== DidGroupAndNotFull @ 14000a5b0 =====

ulonglong DidGroupAndNotFull(longlong param_1,longlong *param_2,longlong *param_3,undefined8 param_4
                            )

{
  longlong *plVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  longlong lVar4;
  bool bVar5;
  uint uVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  
  plVar1 = (longlong *)*param_3;
  bVar5 = true;
  if (((param_3[5] != param_2[4]) || (*(uint *)(param_3 + 4) < *(uint *)(param_1 + 0x48c4))) ||
     (0xffff < (uint)((int)param_2[0x10] * (int)param_2[6]))) {
    bVar5 = false;
  }
  if (plVar1 == (longlong *)0x0) {
    uVar8 = (ulonglong)*(uint *)(param_2 + 6) + param_2[4];
    param_3[5] = uVar8;
    if (bVar5) {
      *(undefined1 *)(param_2 + 0xb) = 1;
      param_3[1] = (longlong)param_2;
      *param_3 = (longlong)param_2;
      *(undefined1 *)((longlong)param_2 + 0x59) = 1;
      *(undefined1 *)(param_3 + 2) = 1;
LAB_14000a79c:
      return CONCAT71((int7)(uVar8 >> 8),1);
    }
  }
  else {
    if (((bVar5) &&
        ((uint)*(ushort *)((longlong)plVar1 + 0x34) + (uint)*(ushort *)((longlong)param_2 + 0x34) <=
         (uint)*(ushort *)(param_1 + 0x884))) &&
       ((*(char *)(*param_2 + 0x48) == *(char *)(*plVar1 + 0x48) &&
        (*(char *)((longlong)plVar1 + 0xc) == *(char *)((longlong)param_2 + 0xc))))) {
      if ((ulonglong)plVar1[4] >> (*(byte *)((longlong)param_3 + 0x32) & 0x3f) ==
          param_2[4] + -1 + (ulonglong)*(uint *)(param_2 + 6) >>
          (*(byte *)((longlong)param_3 + 0x32) & 0x3f)) {
        if ((*(char *)(param_1 + 0xb8) != '\0') &&
           (uVar6 = ((int)plVar1[6] + *(uint *)(param_2 + 6)) * (int)param_2[0x10], 0xffff < uVar6))
        {
          *(bool *)param_4 = param_3[5] == param_2[4];
          return (ulonglong)(uVar6 & 0xffffff00);
        }
        *(longlong **)(param_3[1] + 0x60) = param_2;
        *(char *)(param_3 + 2) = (char)param_3[2] + '\x01';
        param_3[1] = (longlong)param_2;
        if (*(char *)(param_1 + 0x6468) == '\0') {
          MemFastMove((undefined8 *)plVar1[8],(undefined8 *)param_2[7],
                      (uint)*(byte *)((longlong)param_2 + 0x36) *
                      (uint)*(ushort *)((longlong)param_2 + 0x34));
          plVar1[8] = plVar1[8] +
                      (ulonglong)*(byte *)((longlong)param_2 + 0x36) *
                      (ulonglong)*(ushort *)((longlong)param_2 + 0x34);
        }
        else {
          uVar6 = (uint)*(ushort *)((longlong)param_2 + 0x34);
          puVar2 = (undefined8 *)param_2[9];
          puVar3 = (undefined8 *)plVar1[9];
          puVar10 = (undefined8 *)param_2[7];
          puVar7 = (undefined8 *)plVar1[8];
          if (*(ushort *)((longlong)param_2 + 0x34) != 0) {
            do {
              puVar9 = puVar7 + 2;
              if (puVar7 != puVar3) {
                puVar9 = puVar7;
              }
              puVar7 = puVar10 + 2;
              if (puVar10 != puVar2) {
                puVar7 = puVar10;
              }
              puVar10 = puVar7 + 2;
              *puVar9 = *puVar7;
              puVar9[1] = puVar7[1];
              puVar7 = puVar9 + 2;
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          plVar1[8] = (longlong)puVar7;
        }
        *(int *)(plVar1 + 6) = (int)plVar1[6] + (int)param_2[6];
        *(short *)((longlong)plVar1 + 0x34) =
             *(short *)((longlong)plVar1 + 0x34) + *(short *)((longlong)param_2 + 0x34);
        *(char *)((longlong)plVar1 + 0x59) = *(char *)((longlong)plVar1 + 0x59) + '\x01';
        *(undefined1 *)(param_2 + 0xb) = 1;
        uVar8 = 0;
        if (((uint)*(byte *)((longlong)plVar1 + 0x59) < *(uint *)(param_1 + 0x48c0)) &&
           (*(ushort *)((longlong)plVar1 + 0x34) < 0x41)) {
          uVar8 = (ulonglong)*(uint *)(param_2 + 6) + param_2[4];
          param_3[5] = uVar8;
          goto LAB_14000a79c;
        }
        goto LAB_14000a775;
      }
    }
    lVar4 = param_2[4];
    uVar8 = CONCAT71((int7)((ulonglong)lVar4 >> 8),param_3[5] == lVar4);
    *(bool *)param_4 = param_3[5] == lVar4;
  }
LAB_14000a775:
  return uVar8 & 0xffffffffffffff00;
}



===== DoPauseInput @ 14000a7c0 =====

void DoPauseInput(longlong param_1)

{
  if (*(char *)(param_1 + 0x88) == '\0') {
    StorPortPause(param_1,0xe10);
    return;
  }
  return;
}



===== DoResumeInput @ 14000a7e0 =====

void DoResumeInput(longlong param_1)

{
  if (*(char *)(param_1 + 0x88) == '\0') {
    StorPortResume();
    StorPortReady(param_1);
    return;
  }
  return;
}



===== MakeSRBExtension @ 14000a810 =====

ulonglong MakeSRBExtension(longlong param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  
  uVar2 = (ulonglong)*(uint *)(param_1 + 0x188);
  lVar1 = *(longlong *)(param_1 + 0x180);
  if (*(longlong *)(lVar1 + uVar2 * 8) != 0) {
    do {
      uVar3 = (int)uVar2 + 1;
      uVar2 = 0;
      if (uVar3 < *(uint *)(param_1 + 0x898)) {
        uVar2 = (ulonglong)uVar3;
      }
      if ((uint)uVar2 == *(uint *)(param_1 + 0x188)) {
        uVar2 = SetDeadAdapter(param_1,0x20);
        return uVar2 & 0xffffffffffffff00;
      }
    } while (*(longlong *)(lVar1 + uVar2 * 8) != 0);
  }
  *(longlong *)(lVar1 + uVar2 * 8) = param_2;
  *(int *)(param_2 + 8) = (int)uVar2;
  LOCK();
  *(int *)(param_1 + 0x1a0) = *(int *)(param_1 + 0x1a0) + 1;
  UNLOCK();
  if ((*(char *)(param_2 + 0x1c) == '\0') && (*(int *)(param_1 + 0x894) != 0)) {
    LOCK();
    *(int *)(param_1 + 0x1a8) = *(int *)(param_1 + 0x1a8) + 1;
    UNLOCK();
  }
  return CONCAT71((int7)(uVar2 >> 8),1);
}



===== MegaSASStartIo @ 14000a8a0 =====

undefined8 MegaSASStartIo(longlong param_1,longlong param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  longlong *plVar4;
  longlong *plVar5;
  char local_res8 [8];
  
  plVar4 = (longlong *)
           (*(longlong *)(param_2 + 0x38) + (ulonglong)*(ushort *)(param_1 + 0x1d0) &
           (longlong)(int)~(uint)*(ushort *)(param_1 + 0x1d0));
  if (*(char *)(param_1 + 0x6aa8) == '\x01') {
    SetDeviceQueueDepths(param_1);
    *(undefined1 *)(param_1 + 0x6aa8) = 0;
  }
  uVar2 = CheckForValidIO(param_1,param_2);
  if ((char)uVar2 == '\0') goto LAB_14000ab1f;
  if ((*(uint *)(param_1 + 0x898) <= *(uint *)(param_1 + 0x1a0)) ||
     (((*(int *)(param_1 + 0x894) != 0 && (*(char *)((longlong)plVar4 + 0x1c) == '\0')) &&
      (*(uint *)(param_1 + 0x890) <= *(uint *)(param_1 + 0x1a8))))) {
    *(undefined1 *)(param_1 + 0x91) = 0;
    param_2 = *plVar4;
    StorPortBusy(param_1,*(undefined4 *)(param_1 + 0x198));
    *(undefined1 *)(param_2 + 3) = 5;
    goto LAB_14000ab1f;
  }
  if ((0x24 < *(byte *)(param_2 + 2)) ||
     ((0x1000000105U >> ((ulonglong)*(byte *)(param_2 + 2) & 0x3f) & 1) == 0)) {
LAB_14000ab19:
    *(undefined2 *)(param_2 + 3) = 1;
LAB_14000ab1f:
    uVar3 = StorPortNotification(0,param_1,param_2);
    return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
  }
  if ((*(int *)(param_1 + 0x1a0) == *(int *)(param_1 + 0x898)) ||
     (((*(int *)(param_1 + 0x894) != 0 && (*(char *)((longlong)plVar4 + 0x1c) == '\0')) &&
      (*(uint *)(param_1 + 0x890) <= *(uint *)(param_1 + 0x1a8))))) {
    *(undefined1 *)(param_1 + 0x91) = 0;
    uVar3 = BusyThisRequest(param_1,plVar4);
    return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
  }
  if ((*(char *)(param_2 + 2) == '\0') && (*(char *)(param_1 + 0x6468) != '\0')) {
    *(undefined1 *)((longlong)plVar4 + 0x95) = *(undefined1 *)((longlong)plVar4 + 0xc);
  }
  else if (*(char *)(param_2 + 2) == '$') {
    if (*(int *)(param_2 + 0x40) - 4U < 3) {
      *(undefined1 *)(param_1 + 0x1d7) = 1;
    }
    if (*(int *)(param_2 + 8) == 4) {
      *(undefined1 *)(param_1 + 0x6453) = 1;
      (**(code **)(*(longlong *)(param_1 + 0x178) + 0x28))(param_1);
      *(undefined4 *)(param_1 + 0x6d3c) = 1;
      *(longlong *)(param_1 + 0x6d50) = param_2;
      uVar3 = WatchDogTimer(param_1);
      return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
    }
    goto LAB_14000ab19;
  }
  if ((*(char *)((longlong)plVar4 + 0x56) == '\0') || (*(uint *)(param_1 + 0x48c0) < 2)) {
LAB_14000aa42:
    if (*(longlong *)(param_1 + 400) != 0) {
      TryFlushingIoctl(param_1);
    }
    if (*(char *)(param_1 + 0x48c8) != '\0') {
      TryFlushingGroups(param_1);
    }
    uVar2 = SendRequestIfNotBusy(param_1,plVar4);
    if ((char)uVar2 != '\0') goto LAB_14000aa7f;
  }
  else {
    local_res8[0] = '\0';
    plVar5 = (longlong *)(((ulonglong)*(byte *)(param_2 + 6) + 0x23) * 0x40 + param_1);
    if ((*(char *)((longlong)plVar5 + 0x11) == '\0') || ((longlong *)*plVar5 == (longlong *)0x0)) {
LAB_14000a9ed:
      uVar2 = DidGroupAndNotFull(param_1,plVar4,plVar5,local_res8);
      if ((char)uVar2 != '\0') goto LAB_14000aa7f;
      if ((longlong *)*plVar5 != (longlong *)0x0) {
        lVar1 = plVar4[0xb];
        *(undefined1 *)((longlong)plVar5 + 0x11) = 1;
        uVar2 = SendRequestIfNotBusy(param_1,(longlong *)*plVar5);
        if ((char)lVar1 != '\0') goto LAB_14000aa7f;
        if ((char)uVar2 == '\0') goto LAB_14000aa74;
        if (local_res8[0] != '\0') {
          uVar2 = DidGroupAndNotFull(param_1,plVar4,plVar5,local_res8);
          if ((char)uVar2 != '\0') goto LAB_14000aa7f;
        }
      }
      goto LAB_14000aa42;
    }
    uVar3 = SendRequestIfNotBusy(param_1,(longlong *)*plVar5);
    if ((char)uVar3 != '\0') goto LAB_14000a9ed;
  }
LAB_14000aa74:
  uVar2 = BusyThisRequest(param_1,plVar4);
LAB_14000aa7f:
  return CONCAT71((int7)(uVar2 >> 8),1);
}



===== SendRequestIfNotBusy @ 14000ab60 =====

undefined8 SendRequestIfNotBusy(longlong param_1,longlong *param_2)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  
  uVar2 = (ulonglong)*(uint *)(param_1 + 0x1a0);
  if (((*(uint *)(param_1 + 0x1a0) < *(uint *)(param_1 + 0x898)) &&
      (((*(char *)((longlong)param_2 + 0x1c) != '\0' ||
        (uVar2 = (ulonglong)*(uint *)(param_1 + 0x1a8),
        *(uint *)(param_1 + 0x1a8) < *(uint *)(param_1 + 0x890))) &&
       (*(char *)(param_1 + 0x6450) == '\0')))) && (*(char *)(param_1 + 0x6452) == '\0')) {
    if (*(char *)((longlong)param_2 + 0x56) != '\0') {
      puVar1 = (undefined8 *)(((ulonglong)*(byte *)(*param_2 + 6) + 0x23) * 0x40 + param_1);
      LOCK();
      *(int *)(puVar1 + 4) = *(int *)(puVar1 + 4) + 1;
      UNLOCK();
      if ((char)param_2[0xb] != '\0') {
        puVar1[1] = 0;
        *puVar1 = 0;
        *(undefined1 *)((longlong)puVar1 + 0x11) = 0;
      }
    }
    uVar2 = MakeSRBExtension(param_1,(longlong)param_2);
    if ((char)uVar2 != '\0') {
      uVar3 = (**(code **)(*(longlong *)(param_1 + 0x178) + 8))(param_1,param_2);
      return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
    }
  }
  else if ((*(char *)(*param_2 + 2) == '\x02') && (*(longlong *)(param_1 + 400) == 0)) {
    *(longlong **)(param_1 + 400) = param_2;
    return CONCAT71((int7)(uVar2 >> 8),1);
  }
  return uVar2 & 0xffffffffffffff00;
}



===== SyncronizeProcessShutdown @ 14000ac30 =====

undefined8 SyncronizeProcessShutdown(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  
  uVar2 = *(uint *)(param_1 + 0x6d40);
  lVar1 = *(longlong *)(param_1 + 200);
  do {
    uVar4 = (ulonglong)uVar2;
    if (9 < uVar2) {
LAB_14000af20:
      return CONCAT71((int7)(uVar4 >> 8),1);
    }
    switch(IMAGE_DOS_HEADER_140000000.e_magic +
           (&switchD_14000ac8c::switchdataD_14000af30)[(int)uVar2]) {
    case (char *)0x14000ac8e:
      if (*(char *)(param_1 + 0x646b) == '\0') {
        *(undefined4 *)(param_1 + 0x6d40) = 3;
      }
      else {
        PrepareAbortFrame(param_1,3);
        *(undefined4 *)(param_1 + 0x6d40) = 2;
        *(undefined4 *)(param_1 + 0x6d44) = 3;
LAB_14000ad02:
        (**(code **)(*(longlong *)(param_1 + 0x178) + 0x58))(param_1);
      }
      break;
    case (char *)0x14000acc9:
      if (*(char *)(param_1 + 0x1d6) != '\0') {
        PrepareAbortFrame(param_1,2);
        *(undefined4 *)(param_1 + 0x6d40) = 4;
        *(undefined4 *)(param_1 + 0x6d44) = 5;
        goto LAB_14000ad02;
      }
      *(undefined4 *)(param_1 + 0x6d40) = 5;
      break;
    case (char *)0x14000ad17:
      puVar3 = SetupDCMD(param_1,0x1101000);
      *(ushort *)(puVar3 + 0x22) = *(ushort *)(puVar3 + 0x22) | 1;
      *(undefined2 *)((longlong)puVar3 + 0x112) = 0xb4;
      *(undefined4 *)(param_1 + 0x6d40) = 6;
      *(undefined4 *)(param_1 + 0x6d44) = 7;
      *(undefined4 *)(param_1 + 0x6458) = 180000000;
      (**(code **)(*(longlong *)(param_1 + 0x178) + 0x58))(param_1,puVar3);
      break;
    case (char *)0x14000ad67:
      uVar2 = 0x1060000;
      if (*(char *)(param_1 + 0x1d7) != '\0') {
        uVar2 = 0x1050000;
      }
      puVar3 = SetupDCMD(param_1,uVar2);
      *(ushort *)(puVar3 + 0x22) = *(ushort *)(puVar3 + 0x22) | 1;
      *(undefined2 *)((longlong)puVar3 + 0x112) = 0xb4;
      *(undefined4 *)(param_1 + 0x6d40) = 8;
      *(undefined4 *)(param_1 + 0x6d44) = 9;
      *(undefined4 *)(param_1 + 0x6458) = 180000000;
      (**(code **)(*(longlong *)(param_1 + 0x178) + 0x58))(param_1,puVar3);
      break;
    default:
      if (*(char *)(lVar1 + 0x102) == -1) {
        uVar2 = (**(code **)(*(longlong *)(param_1 + 0x178) + 0x30))
                          (*(undefined8 *)(param_1 + 0x80));
        *(uint *)(param_1 + 0x1ac) = uVar2;
        if ((uVar2 & 0xf0000000) == 0xf0000000) {
          StorPortLogError(param_1,0,0xff,0xff,0xff,6,0x13);
          *(undefined4 *)(param_1 + 0x6d40) = 9;
          break;
        }
        if (0 < *(int *)(param_1 + 0x6458)) {
          *(int *)(param_1 + 0x6458) = *(int *)(param_1 + 0x6458) + -10000;
          uVar4 = StorPortNotification(6,param_1,WatchDogTimer,10000);
          goto LAB_14000af20;
        }
        StorPortLogError(param_1,0,0xff,0xff,0xff,6,0x13);
      }
      else {
        if (*(char *)(lVar1 + 0x102) != '\0') {
          StorPortLogError(param_1,0,0xff,0xff,0xff,6,0x13);
        }
        if (*(int *)(param_1 + 0x6d40) == 2) {
          *(undefined1 *)(param_1 + 0x646b) = 0;
        }
        if (*(int *)(param_1 + 0x6d40) == 4) {
          *(undefined1 *)(param_1 + 0x1d6) = 0;
        }
      }
      *(undefined4 *)(param_1 + 0x6d40) = *(undefined4 *)(param_1 + 0x6d44);
      break;
    case (char *)0x14000aef0:
      *(undefined2 *)(param_1 + 0x645c) = 0;
      *(undefined2 *)(*(longlong *)(param_1 + 0x6d50) + 3) = 1;
      uVar4 = StorPortNotification(0,param_1);
      goto LAB_14000af20;
    }
    uVar2 = *(uint *)(param_1 + 0x6d40);
    lVar1 = *(longlong *)(param_1 + 200);
  } while( true );
}



===== TryFlushingGroups @ 14000af60 =====

void TryFlushingGroups(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  byte bVar5;
  byte bVar6;
  
  bVar5 = *(byte *)(param_1 + 0x8a0);
  do {
    lVar2 = ((ulonglong)bVar5 + 0x23) * 0x40;
    if ((*(char *)(lVar2 + 0x11 + param_1) != '\0') &&
       (plVar1 = *(longlong **)(lVar2 + param_1), plVar1 != (longlong *)0x0)) {
      if (((*(uint *)(param_1 + 0x1a0) < *(uint *)(param_1 + 0x898)) &&
          (((*(char *)((longlong)plVar1 + 0x1c) != '\0' ||
            (*(uint *)(param_1 + 0x1a8) < *(uint *)(param_1 + 0x890))) &&
           (*(char *)(param_1 + 0x6450) == '\0')))) && (*(char *)(param_1 + 0x6452) == '\0')) {
        if (*(char *)((longlong)plVar1 + 0x56) != '\0') {
          puVar3 = (undefined8 *)(((ulonglong)*(byte *)(*plVar1 + 6) + 0x23) * 0x40 + param_1);
          LOCK();
          *(int *)(puVar3 + 4) = *(int *)(puVar3 + 4) + 1;
          UNLOCK();
          if ((char)plVar1[0xb] != '\0') {
            puVar3[1] = 0;
            *puVar3 = 0;
            *(undefined1 *)((longlong)puVar3 + 0x11) = 0;
          }
        }
        uVar4 = MakeSRBExtension(param_1,(longlong)plVar1);
        if ((char)uVar4 == '\0') {
LAB_14000b07e:
          *(byte *)(param_1 + 0x8a0) = bVar5;
          return;
        }
        (**(code **)(*(longlong *)(param_1 + 0x178) + 8))(param_1,plVar1);
      }
      else {
        if ((*(char *)(*plVar1 + 2) != '\x02') || (*(longlong *)(param_1 + 400) != 0))
        goto LAB_14000b07e;
        *(longlong **)(param_1 + 400) = plVar1;
      }
    }
    bVar6 = bVar5 + 1;
    bVar5 = 0;
    if (bVar6 < *(byte *)(param_1 + 0x1d8)) {
      bVar5 = bVar6;
    }
    if (bVar5 == *(byte *)(param_1 + 0x8a0)) {
      *(undefined1 *)(param_1 + 0x48c8) = 0;
      *(undefined1 *)(param_1 + 0x8a0) = 0;
      return;
    }
  } while( true );
}



===== TryFlushingIoctl @ 14000b090 =====

void TryFlushingIoctl(longlong param_1)

{
  longlong *plVar1;
  undefined8 uVar2;
  
  plVar1 = *(longlong **)(param_1 + 400);
  *(undefined8 *)(param_1 + 400) = 0;
  uVar2 = SendRequestIfNotBusy(param_1,plVar1);
  if ((char)uVar2 == '\0') {
    *(longlong **)(param_1 + 400) = plVar1;
  }
  return;
}



===== WatchDogTimer @ 14000b0d0 =====

void WatchDogTimer(longlong param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x6d3c);
  if (iVar1 == 0) {
    StorPortNotification(6,param_1,WatchDogTimer);
    return;
  }
  if (iVar1 == 1) {
    StorPortSynchronizeAccess(param_1,SyncronizeProcessShutdown,0);
    return;
  }
  if (iVar1 == 2) {
    StorPortSynchronizeAccess(param_1,SyncronizeInitializeAdapter,0);
    return;
  }
  return;
}



===== FunctionControl @ 14000b120 =====

undefined1
FunctionControl(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4,char param_5
               )

{
  *(bool *)(param_1 + 0x7e8) = param_5 != '\0';
  ScsiPortWmiPostProcess(param_2,'\x01',0);
  return 1;
}



===== MegaSASQueryWmiDataBlock @ 14000b150 =====

ulonglong MegaSASQueryWmiDataBlock
                    (undefined8 param_1,longlong param_2,int param_3,undefined8 param_4,uint param_5
                    ,uint *param_6,uint param_7)

{
  int iVar1;
  ulonglong uVar2;
  char cVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  
  uVar2 = (ulonglong)param_5;
  cVar3 = '\x04';
  if (param_5 == 1) {
    if (param_3 == 0) {
      uVar6 = 4;
      cVar3 = '\x12';
      if (3 < param_7) {
        cVar3 = '\x01';
      }
    }
    else {
      uVar6 = 0;
    }
    if ((param_6 != (uint *)0x0) && (cVar3 != '\x12')) {
      *param_6 = uVar6;
    }
  }
  else {
    uVar6 = 0;
    if (param_5 != 0) {
      puVar5 = param_6;
      do {
        if (param_3 == 0) {
          uVar4 = 4;
          cVar3 = '\x12';
        }
        else {
          uVar4 = 0;
          cVar3 = '\x04';
        }
        uVar6 = uVar6 + (uVar4 + 7 & 0xfffffff8);
        if (param_6 != (uint *)0x0) {
          *puVar5 = uVar4;
        }
        puVar5 = puVar5 + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    if ((param_6 == (uint *)0x0) || (param_7 < uVar6)) {
      cVar3 = '\x12';
    }
    else {
      uVar6 = 0;
      uVar4 = 0;
      if (param_5 != 0) {
        do {
          if (param_3 == 0) {
            iVar1 = 4;
            cVar3 = '\x12';
            if (3 < *param_6) {
              cVar3 = '\x01';
            }
          }
          else {
            iVar1 = 0;
            cVar3 = '\x04';
          }
          uVar6 = uVar6 + (iVar1 + 7U & 0xfffffff8);
          if (cVar3 != '\x01') break;
          uVar4 = uVar4 + 1;
          param_6 = param_6 + 1;
        } while (uVar4 < param_5);
      }
    }
  }
  uVar2 = ScsiPortWmiPostProcess(param_2,cVar3,uVar6);
  return uVar2 & 0xffffffffffffff00;
}



===== MegaSASWmiInitialize @ 14000b290 =====

void MegaSASWmiInitialize(longlong param_1)

{
  *(undefined4 *)(param_1 + 0x840) = 1;
  *(undefined8 *)(param_1 + 0x868) = 0;
  *(undefined ***)(param_1 + 0x848) = &MegaSASGuidList;
  *(undefined1 **)(param_1 + 0x850) = &MegaSASQueryWmiRegInfo;
  *(code **)(param_1 + 0x858) = MegaSASQueryWmiDataBlock;
  *(code **)(param_1 + 0x878) = FunctionControl;
  *(undefined8 *)(param_1 + 0x860) = 0;
  *(undefined8 *)(param_1 + 0x870) = 0;
  return;
}



===== MegaSASWmiSrb @ 14000b2f0 =====

undefined8 MegaSASWmiSrb(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  undefined8 local_28 [3];
  undefined1 local_f;
  undefined4 local_c;
  
  if ((*(byte *)(param_2 + 9) & 1) == 0) {
    *(undefined4 *)(param_2 + 0x10) = 0;
    *(undefined1 *)(param_2 + 3) = 1;
    return 0;
  }
  MemFastZero(local_28,0x20);
  uVar1 = ScsiPortWmiDispatchFunction
                    ((uint *)(param_1 + 0x840),*(byte *)(param_2 + 4),param_1,(longlong)local_28,
                     *(ulonglong **)(param_2 + 0x20),*(uint *)(param_2 + 0x10),
                     *(uint **)(param_2 + 0x18));
  if ((char)uVar1 == '\0') {
    *(undefined4 *)(param_2 + 0x10) = local_c;
    *(undefined1 *)(param_2 + 3) = local_f;
    return 0;
  }
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== __security_check_cookie @ 14000b3a0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  if ((_StackCookie == __security_cookie) && ((short)(_StackCookie >> 0x30) == 0)) {
    return;
  }
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __GSHandlerCheck @ 14000b3c8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000b3e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong __GSHandlerCheckCommon(undefined8 param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  
  bVar1 = *(byte *)((ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8) +
                    *(longlong *)(param_2 + 8) + 3);
  lVar2 = CONCAT71((int7)((ulonglong)*(longlong *)(param_2 + 0x10) >> 8),bVar1);
  if ((bVar1 & 0xf) != 0) {
    lVar2 = (longlong)(int)(bVar1 & 0xfffffff0);
  }
  return lVar2;
}



===== RtlIsNtDdiVersionAvailable @ 14000b450 =====

void RtlIsNtDdiVersionAvailable(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b450. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlIsNtDdiVersionAvailable();
  return;
}



===== strstr @ 14000b456 =====

char * __cdecl strstr(char *_Str,char *_SubStr)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000b456. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = strstr(_Str,_SubStr);
  return pcVar1;
}



===== StorPortGetScatterGatherList @ 14000b45c =====

void StorPortGetScatterGatherList(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b45c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetScatterGatherList();
  return;
}



===== StorPortGetPhysicalAddress @ 14000b462 =====

void StorPortGetPhysicalAddress(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b462. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetPhysicalAddress();
  return;
}



===== StorPortNotification @ 14000b468 =====

void StorPortNotification(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b468. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification();
  return;
}



===== StorPortExtendedFunction @ 14000b46e =====

void StorPortExtendedFunction(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b46e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortExtendedFunction();
  return;
}



===== StorPortSetDeviceQueueDepth @ 14000b474 =====

void StorPortSetDeviceQueueDepth(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b474. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortSetDeviceQueueDepth();
  return;
}



===== StorPortLogError @ 14000b47a =====

void StorPortLogError(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b47a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortLogError();
  return;
}



===== StorPortStallExecution @ 14000b480 =====

void StorPortStallExecution(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b480. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortStallExecution();
  return;
}



===== StorPortInitialize @ 14000b486 =====

void StorPortInitialize(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b486. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortInitialize();
  return;
}



===== StorPortGetBusData @ 14000b48c =====

void StorPortGetBusData(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b48c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetBusData();
  return;
}



===== StorPortGetDeviceBase @ 14000b492 =====

void StorPortGetDeviceBase(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b492. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetDeviceBase();
  return;
}



===== StorPortGetUncachedExtension @ 14000b498 =====

void StorPortGetUncachedExtension(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b498. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetUncachedExtension();
  return;
}



===== StorPortQuerySystemTime @ 14000b49e =====

void StorPortQuerySystemTime(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b49e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortQuerySystemTime();
  return;
}



===== StorPortSetBusDataByOffset @ 14000b4a4 =====

void StorPortSetBusDataByOffset(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b4a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortSetBusDataByOffset();
  return;
}



===== StorPortPause @ 14000b4aa =====

void StorPortPause(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b4aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortPause();
  return;
}



===== StorPortResume @ 14000b4b0 =====

void StorPortResume(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b4b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortResume();
  return;
}



===== StorPortBusy @ 14000b4b6 =====

void StorPortBusy(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b4b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortBusy();
  return;
}



===== StorPortReady @ 14000b4bc =====

void StorPortReady(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b4bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortReady();
  return;
}



===== StorPortSynchronizeAccess @ 14000b4c2 =====

void StorPortSynchronizeAccess(void)

{
                    /* WARNING: Could not recover jumptable at 0x00014000b4c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortSynchronizeAccess();
  return;
}



===== ScsiPortWmiDispatchFunction @ 14000b4c8 =====

undefined8
ScsiPortWmiDispatchFunction
          (uint *param_1,byte param_2,undefined8 param_3,longlong param_4,ulonglong *param_5,
          uint param_6,uint *param_7)

{
  char cVar1;
  undefined8 in_RAX;
  undefined7 uVar2;
  undefined7 extraout_var;
  uint local_res10 [6];
  int local_18 [4];
  
  local_res10[0] = 0;
  *(undefined4 *)(param_4 + 0x1c) = 0;
  if (param_2 < 10) {
    *(uint **)(param_4 + 0x10) = param_7;
    *(uint *)(param_4 + 8) = param_6;
    *(byte *)(param_4 + 0x18) = param_2;
    cVar1 = ScsiWmipProcessRequest
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7,local_res10,
                       (short *)local_18);
    uVar2 = extraout_var;
    if (local_18[0] == 1) {
      *(char *)(param_4 + 0x19) = cVar1;
      if (cVar1 != '\x01') {
        local_res10[0] = 0;
      }
      *(uint *)(param_4 + 0x1c) = local_res10[0];
    }
  }
  else {
    uVar2 = (undefined7)((ulonglong)in_RAX >> 8);
    cVar1 = '\x04';
    *(undefined1 *)(param_4 + 0x19) = 4;
  }
  return CONCAT71(uVar2,cVar1 == '\0');
}



===== ScsiPortWmiFireLogicalUnitEvent @ 14000b568 =====

void ScsiPortWmiFireLogicalUnitEvent
               (undefined8 param_1,char param_2,undefined8 param_3,undefined8 param_4,int *param_5,
               int param_6,int param_7,int *param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *param_5;
  iVar2 = param_5[1];
  iVar3 = param_5[2];
  iVar4 = param_5[3];
  param_8[3] = 0;
  param_8[0xd] = param_6;
  param_8[0xf] = param_7;
  param_8[0xb] = 0x8a;
  param_8[0xe] = 0x40;
  *param_8 = param_7 + 0x40;
  param_8[6] = iVar1;
  param_8[7] = iVar2;
  param_8[8] = iVar3;
  param_8[9] = iVar4;
  if (param_2 == -1) {
                    /* WARNING: Could not recover jumptable at 0x00014000b5e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    ScsiPortNotification(8,param_1,param_8,0xff);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00014000b5ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ScsiPortNotification(8,param_1,param_8,param_2);
  return;
}



===== ScsiPortWmiPostProcess @ 14000b5e8 =====

void ScsiPortWmiPostProcess(longlong param_1,char param_2,uint param_3)

{
  char cVar1;
  
  cVar1 = ScsiWmipPostProcess(*(char *)(param_1 + 0x18),*(uint **)(param_1 + 0x10),
                              *(uint *)(param_1 + 8),param_3,param_2,(uint *)(param_1 + 0x1c));
  *(char *)(param_1 + 0x19) = cVar1;
  return;
}



===== ScsiWmipFindGuid @ 14000b61c =====

ulonglong ScsiWmipFindGuid(longlong *param_1,uint param_2,ulonglong *param_3,uint *param_4,
                          undefined4 *param_5)

{
  ulonglong in_RAX;
  uint uVar1;
  longlong *plVar2;
  
  uVar1 = 0;
  if (param_2 != 0) {
    plVar2 = param_1;
    do {
      in_RAX = *param_3;
      if ((in_RAX == *(ulonglong *)*plVar2) &&
         (in_RAX = param_3[1], in_RAX == ((ulonglong *)*plVar2)[1])) {
        *param_4 = uVar1;
        *param_5 = (int)param_1[(ulonglong)uVar1 * 2 + 1];
        return CONCAT71((int7)(in_RAX >> 8),1);
      }
      uVar1 = uVar1 + 1;
      plVar2 = plVar2 + 2;
    } while (uVar1 < param_2);
  }
  return in_RAX & 0xffffffffffffff00;
}



===== ScsiWmipPostProcess @ 14000b670 =====

char ScsiWmipPostProcess(char param_1,uint *param_2,uint param_3,uint param_4,char param_5,
                        uint *param_6)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  uVar6 = 0;
  if (param_1 == '\0') {
    uVar5 = param_2[0xc];
    uVar1 = param_2[0xd];
    uVar7 = (ulonglong)uVar1;
    uVar2 = uVar5 + param_4;
    if (param_5 == '\x01') {
      if (uVar2 <= param_3) {
        if (((0x2f < param_3) && (*param_2 = uVar2, uVar6 = uVar2, (char)param_2[0xb] < '\0')) &&
           (puVar4 = param_2 + 0xf, uVar3 = uVar7, uVar1 != 0)) {
          do {
            uVar2 = (int)uVar3 - 1;
            uVar3 = (ulonglong)uVar2;
            if (uVar3 * 8 + 0x48 <= (ulonglong)param_3) {
              param_2[uVar3 * 2 + 0x10] = puVar4[uVar3];
            }
          } while (uVar2 != 0);
          if (uVar1 != 0) {
            uVar3 = 0x48;
            do {
              if (uVar3 <= param_3) {
                *puVar4 = uVar5;
                uVar5 = uVar5 + 7 + puVar4[1] & 0xfffffff8;
              }
              uVar3 = uVar3 + 8;
              puVar4 = puVar4 + 2;
              uVar7 = uVar7 - 1;
            } while (uVar7 != 0);
          }
        }
        goto LAB_14000b738;
      }
      param_5 = '\x12';
    }
LAB_14000b716:
    if ((param_5 != '\x12') || (param_3 < 0x38)) goto LAB_14000b738;
    param_2[0xc] = uVar2;
  }
  else {
    if (param_1 == '\x01') {
      uVar2 = param_2[0xe] + param_4;
      if (param_5 == '\x01') {
        if (0x2f < param_3) {
          *param_2 = uVar2;
          uVar6 = uVar2;
        }
        goto LAB_14000b738;
      }
      goto LAB_14000b716;
    }
    if (param_1 != '\t') goto LAB_14000b738;
    uVar5 = param_2[0xf] + param_4;
    if (param_5 == '\x01') {
      if (0x47 < param_3) {
        *param_2 = uVar5;
        param_2[0x10] = param_4;
        uVar6 = uVar5;
      }
      goto LAB_14000b738;
    }
    if ((param_5 != '\x12') || (param_3 < 0x38)) goto LAB_14000b738;
    param_2[0xc] = uVar5;
  }
  *param_2 = 0x38;
  param_2[0xb] = 0x20;
  param_5 = '\x01';
  uVar6 = 0x38;
LAB_14000b738:
  *param_6 = uVar6;
  return param_5;
}



===== ScsiWmipProcessRequest @ 14000b7c0 =====

char ScsiWmipProcessRequest
               (uint *param_1,byte param_2,undefined8 param_3,undefined8 param_4,ulonglong *param_5,
               uint param_6,uint *param_7,uint *param_8,short *param_9)

{
  uint uVar1;
  short sVar2;
  ulonglong uVar3;
  short *psVar4;
  char cVar5;
  uint uVar6;
  ulonglong uVar7;
  code *pcVar8;
  uint uVar9;
  ulonglong *puVar10;
  undefined2 *puVar11;
  int iVar12;
  longlong lVar13;
  uint *puVar14;
  uint uVar15;
  undefined8 uVar16;
  ushort uVar17;
  uint local_res10 [2];
  uint uVar18;
  undefined8 uVar19;
  uint local_38 [4];
  
  puVar14 = (uint *)0x0;
  local_res10[0] = 0;
  local_38[0] = 0;
  psVar4 = param_9;
  psVar4[0] = 0;
  psVar4[1] = 0;
  uVar6 = 0;
  if (param_2 != 8) {
    uVar7 = ScsiWmipFindGuid(*(longlong **)(param_1 + 2),*param_1,param_5,local_res10,local_38);
    if ((char)uVar7 == '\0') {
LAB_14000b8ba:
      *param_8 = 0;
      cVar5 = '\x04';
      goto LAB_14000bb9f;
    }
    if (((byte)(param_2 - 1) < 3) || (param_2 == 9)) {
      uVar6 = param_7[0xd];
      if (((char)param_7[0xb] < '\0') && (local_38[0] <= uVar6)) goto LAB_14000b8ba;
    }
    else {
      uVar6 = 0;
    }
  }
  if (param_2 < 6) {
    if (param_2 != 5) {
      if (param_2 == 0) {
        if (0x47 < param_6) {
          param_7[0xb] = param_7[0xb] & 0xffffffef;
          uVar6 = local_38[0] * 8 + 0x40;
          param_7[0xd] = local_38[0];
          param_7[0xc] = uVar6;
          if (param_6 < uVar6) {
            lVar13 = 0;
            iVar12 = 0;
          }
          else {
            puVar14 = param_7 + 0xf;
            lVar13 = (ulonglong)uVar6 + (longlong)param_7;
            iVar12 = param_6 - uVar6;
          }
          uVar6 = 0;
          uVar18 = local_38[0];
          goto LAB_14000b9c5;
        }
      }
      else {
        if (param_2 == 1) {
          if (param_6 < 0x40) {
            if (param_6 < 4) {
              *(undefined1 *)param_7 = 8;
              return '\x12';
            }
            *param_7 = 0x40;
            return '\x12';
          }
          iVar12 = param_6 - param_7[0xe];
          lVar13 = (longlong)param_7 + (ulonglong)param_7[0xe];
          puVar14 = param_7 + 0xf;
          uVar18 = 1;
LAB_14000b9c5:
          cVar5 = (**(code **)(param_1 + 6))
                            (param_3,param_4,local_res10[0],uVar6,uVar18,puVar14,iVar12,lVar13);
          return cVar5;
        }
        if (param_2 == 2) {
          if (*(code **)(param_1 + 8) != (code *)0x0) {
            cVar5 = (**(code **)(param_1 + 8))
                              (param_3,param_4,local_res10[0],uVar6,param_7[0xf],
                               (ulonglong)param_7[0xe] + (longlong)param_7);
            return cVar5;
          }
        }
        else if (param_2 == 3) {
          if (*(code **)(param_1 + 10) != (code *)0x0) {
            cVar5 = (**(code **)(param_1 + 10))
                              (param_3,param_4,local_res10[0],uVar6,param_7[0xe],param_7[0x10],
                               (ulonglong)param_7[0xf] + (longlong)param_7);
            return cVar5;
          }
        }
        else if (param_2 == 4) {
          pcVar8 = *(code **)(param_1 + 0xe);
          if (pcVar8 != (code *)0x0) {
            uVar16 = 0;
            goto LAB_14000bbc6;
          }
          goto LAB_14000bbd7;
        }
      }
LAB_14000b8fa:
      cVar5 = '\x04';
      goto LAB_14000bbda;
    }
    pcVar8 = *(code **)(param_1 + 0xe);
    if (pcVar8 != (code *)0x0) {
      uVar19 = 0;
      uVar16 = 0;
      goto LAB_14000bbcb;
    }
  }
  else if (param_2 == 6) {
    pcVar8 = *(code **)(param_1 + 0xe);
    if (pcVar8 != (code *)0x0) {
      uVar16 = 1;
LAB_14000bbc6:
      uVar19 = 1;
LAB_14000bbcb:
      cVar5 = (*pcVar8)(param_3,param_4,local_res10[0],uVar16,uVar19);
      return cVar5;
    }
  }
  else {
    if (param_2 != 7) {
      if (param_2 != 8) {
        if (((param_2 == 9) && (*(code **)(param_1 + 0xc) != (code *)0x0)) && (0x47 < param_6)) {
          uVar18 = param_7[0xf];
          if (uVar18 <= param_6) {
            cVar5 = (**(code **)(param_1 + 0xc))
                              (param_3,param_4,local_res10[0],uVar6,param_7[0xe],param_7[0x10],
                               param_6 - uVar18,(longlong)param_7 + (ulonglong)uVar18);
            return cVar5;
          }
        }
        goto LAB_14000b8fa;
      }
      cVar5 = (**(code **)(param_1 + 4))(param_3,param_4,&param_9);
      if (cVar5 == '\x01') {
        uVar18 = *param_1;
        uVar7 = (ulonglong)uVar18;
        lVar13 = *(longlong *)(param_1 + 2);
        uVar15 = uVar18 * 0x20 + 0x18;
        uVar6 = uVar18 * 0x20 + 0x34;
        if (param_9 == (short *)0x0) {
          uVar17 = 0;
        }
        else {
          uVar17 = 0;
          sVar2 = *param_9;
          while (sVar2 != 0) {
            uVar17 = uVar17 + 1;
            sVar2 = param_9[uVar17];
          }
          uVar17 = uVar17 * 2;
        }
        uVar9 = uVar17 + uVar6;
        if ((uVar9 < uVar6) || (uVar1 = uVar9 + 2, uVar1 < uVar9)) {
          cVar5 = '\x04';
          goto LAB_14000bb94;
        }
        if (param_6 < uVar1) {
          if (param_6 < 4) {
            *(undefined1 *)param_7 = 8;
          }
          else {
            *param_7 = uVar1;
            param_6 = 4;
          }
        }
        else {
          *param_7 = uVar1;
          param_7[1] = 0;
          param_7[2] = 0;
          param_7[3] = uVar6;
          param_7[4] = uVar18;
          if (uVar18 != 0) {
            puVar14 = (uint *)(lVar13 + 0xc);
            puVar10 = (ulonglong *)(param_7 + 0xc);
            do {
              uVar3 = (*(ulonglong **)(puVar14 + -3))[1];
              puVar10[-3] = **(ulonglong **)(puVar14 + -3);
              puVar10[-2] = uVar3;
              if (puVar14[-1] == 0xffffffff) {
                *(uint *)(puVar10 + -1) = *puVar14;
                *puVar10 = 0;
                *(undefined4 *)((longlong)puVar10 + -4) = 0;
              }
              else {
                *(uint *)(puVar10 + -1) = *puVar14 | 8;
                *puVar10 = (ulonglong)uVar15;
                *(uint *)((longlong)puVar10 + -4) = puVar14[-1];
              }
              puVar10 = puVar10 + 4;
              puVar14 = puVar14 + 4;
              uVar7 = uVar7 - 1;
            } while (uVar7 != 0);
          }
          puVar11 = (undefined2 *)((ulonglong)uVar15 + (longlong)param_7);
          *puVar11 = 0x1a;
          memmove(puVar11 + 1,L"ScsiMiniPort",0x1a);
          *(ushort *)((ulonglong)uVar6 + (longlong)param_7) = uVar17;
          memmove((ushort *)((ulonglong)uVar6 + (longlong)param_7) + 1,param_9,(ulonglong)uVar17);
          param_6 = uVar1;
        }
      }
      else {
LAB_14000bb94:
        param_6 = 0;
      }
      *param_8 = param_6;
LAB_14000bb9f:
      psVar4[0] = 1;
      psVar4[1] = 0;
      return cVar5;
    }
    pcVar8 = *(code **)(param_1 + 0xe);
    if (pcVar8 != (code *)0x0) {
      uVar19 = 0;
      uVar16 = 1;
      goto LAB_14000bbcb;
    }
  }
LAB_14000bbd7:
  cVar5 = '\x01';
LAB_14000bbda:
  psVar4[0] = 1;
  psVar4[1] = 0;
  return cVar5;
}



===== _guard_check_icall @ 14000bc00 =====

void _guard_check_icall(void)

{
  return;
}



===== _guard_dispatch_icall @ 14000bc20 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014000bc20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== memset @ 14000bc40 =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  uint uVar1;
  void *pvVar2;
  ulonglong *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  uVar4 = (ulonglong)(uint)_Val;
  pvVar2 = _Dst;
  if (7 < _Size) {
    uVar4 = (ulonglong)(byte)_Val * 0x101010101010101;
    if (0x46 < _Size) {
      uVar1 = -(int)_Dst & 7;
      if (uVar1 != 0) {
        _Size = _Size - uVar1;
        *(ulonglong *)_Dst = uVar4;
      }
      puVar3 = (ulonglong *)((ulonglong)uVar1 + (longlong)_Dst);
      uVar6 = _Size >> 6;
      uVar5 = _Size >> 3 & 7;
      if (uVar5 == 0) goto LAB_14000bd00;
      puVar3 = puVar3 + (uVar5 - 8);
      uVar6 = uVar6 + 1;
      switch(uVar5) {
      case 2:
        goto switchD_14000bcfd_caseD_2;
      case 3:
        goto switchD_14000bcfd_caseD_3;
      case 4:
        goto switchD_14000bcfd_caseD_4;
      case 5:
        goto switchD_14000bcfd_caseD_5;
      case 6:
        goto switchD_14000bcfd_caseD_6;
      case 7:
        goto switchD_14000bcfd_caseD_7;
      }
      while( true ) {
        puVar3[7] = uVar4;
        puVar3 = puVar3 + 8;
        uVar6 = uVar6 - 1;
        if (uVar6 == 0) break;
LAB_14000bd00:
        *puVar3 = uVar4;
switchD_14000bcfd_caseD_7:
        puVar3[1] = uVar4;
switchD_14000bcfd_caseD_6:
        puVar3[2] = uVar4;
switchD_14000bcfd_caseD_5:
        puVar3[3] = uVar4;
switchD_14000bcfd_caseD_4:
        puVar3[4] = uVar4;
switchD_14000bcfd_caseD_3:
        puVar3[5] = uVar4;
switchD_14000bcfd_caseD_2:
        puVar3[6] = uVar4;
      }
      for (uVar5 = _Size & 7; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(char *)((uVar5 - 1) + (longlong)puVar3) = (char)uVar4;
      }
      return _Dst;
    }
    uVar5 = _Size & 0xfffffffffffffff8;
    pvVar2 = (void *)((longlong)_Dst + uVar5);
    do {
      *(ulonglong *)((uVar5 - 8) + (longlong)_Dst) = uVar4;
      uVar5 = uVar5 - 8;
    } while (uVar5 != 0);
  }
  for (uVar5 = _Size & 7; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(char *)((uVar5 - 1) + (longlong)pvVar2) = (char)uVar4;
  }
  return _Dst;
}



===== memmove @ 14000bd40 =====

void * __cdecl memmove(void *_Dst,void *_Src,size_t _Size)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined1 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int iVar7;
  uint uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  
  uVar11 = (longlong)_Src - (longlong)_Dst;
  if (_Src < _Dst) {
    puVar9 = (undefined8 *)((longlong)_Dst + _Size);
    if (0x4e < _Size) {
      if (uVar11 < 0xfffffffffffffff1) {
        uVar12 = (ulonglong)((uint)puVar9 & 0xf);
        if (((ulonglong)puVar9 & 0xf) != 0) {
          _Size = _Size - uVar12;
          uVar12 = -uVar12;
          puVar10 = (undefined8 *)((uVar11 - 0x10) + (longlong)puVar9);
          uVar4 = puVar10[1];
          puVar9[-2] = *puVar10;
          puVar9[-1] = uVar4;
        }
        puVar9 = (undefined8 *)(uVar12 + (longlong)puVar9);
      }
      else {
        while (((ulonglong)puVar9 & 0xf) != 0) {
          puVar9 = (undefined8 *)((longlong)puVar9 + -1);
          _Size = _Size - 1;
          *(undefined1 *)puVar9 = *(undefined1 *)(uVar11 + (longlong)puVar9);
        }
      }
      uVar12 = _Size >> 5;
      if ((0x2000 < uVar12) && (uVar11 < 0xfffffffffffffe01)) {
        do {
          iVar7 = 4;
          do {
            puVar10 = puVar9;
            iVar7 = iVar7 + -1;
            puVar9 = puVar10 + -0x10;
          } while (iVar7 != 0);
          iVar7 = 8;
          puVar10 = puVar10 + 0x30;
          do {
            puVar9 = (undefined8 *)((uVar11 - 0x10) + (longlong)puVar10);
            uVar4 = puVar9[1];
            puVar1 = (undefined8 *)((uVar11 - 0x20) + (longlong)puVar10);
            uVar5 = *puVar1;
            uVar6 = puVar1[1];
            puVar10[-2] = *puVar9;
            puVar10[-1] = uVar4;
            puVar10[-4] = uVar5;
            puVar10[-3] = uVar6;
            puVar9 = puVar10 + -8;
            puVar1 = (undefined8 *)(uVar11 + 0x10 + (longlong)puVar9);
            uVar4 = puVar1[1];
            uVar5 = *(undefined8 *)(uVar11 + (longlong)puVar9);
            uVar6 = ((undefined8 *)(uVar11 + (longlong)puVar9))[1];
            puVar10[-6] = *puVar1;
            puVar10[-5] = uVar4;
            *puVar9 = uVar5;
            puVar10[-7] = uVar6;
            iVar7 = iVar7 + -1;
            puVar10 = puVar9;
          } while (iVar7 != 0);
          _Size = _Size - 0x200;
        } while (0x1ff < _Size);
        LOCK();
        UNLOCK();
        uVar12 = _Size >> 5;
        if (uVar12 == 0) goto LAB_14000bef7;
      }
      _Size = _Size & 0x1f;
      puVar10 = puVar9;
      do {
        puVar1 = (undefined8 *)((uVar11 - 0x10) + (longlong)puVar10);
        uVar4 = puVar1[1];
        puVar9 = (undefined8 *)((uVar11 - 0x20) + (longlong)puVar10);
        uVar5 = *puVar9;
        uVar6 = puVar9[1];
        puVar9 = puVar10 + -4;
        puVar10[-2] = *puVar1;
        puVar10[-1] = uVar4;
        *puVar9 = uVar5;
        puVar10[-3] = uVar6;
        uVar12 = uVar12 - 1;
        puVar10 = puVar9;
      } while (uVar12 != 0);
    }
LAB_14000bef7:
    for (uVar12 = _Size >> 3; uVar12 != 0; uVar12 = uVar12 - 1) {
      puVar10 = (undefined8 *)((uVar11 - 8) + (longlong)puVar9);
      puVar9 = puVar9 + -1;
      *puVar9 = *puVar10;
    }
    for (uVar12 = _Size & 7; uVar12 != 0; uVar12 = uVar12 - 1) {
      puVar3 = (undefined1 *)((uVar11 - 1) + (longlong)puVar9);
      puVar9 = (undefined8 *)((longlong)puVar9 + -1);
      *(undefined1 *)puVar9 = *puVar3;
    }
    return _Dst;
  }
  puVar9 = _Dst;
  if (0x4e < _Size) {
    if (uVar11 < 0x10) {
      for (; ((ulonglong)puVar9 & 0xf) != 0; puVar9 = (undefined8 *)((longlong)puVar9 + 1)) {
        _Size = _Size - 1;
        *(undefined1 *)puVar9 = *(undefined1 *)(uVar11 + (longlong)puVar9);
      }
    }
    else {
      uVar8 = -(int)_Dst & 0xf;
      if (uVar8 != 0) {
        _Size = _Size - uVar8;
        uVar4 = ((undefined8 *)(uVar11 + (longlong)_Dst))[1];
        *(undefined8 *)_Dst = *(undefined8 *)(uVar11 + (longlong)_Dst);
        *(undefined8 *)((longlong)_Dst + 8) = uVar4;
      }
      puVar9 = (undefined8 *)((ulonglong)uVar8 + (longlong)_Dst);
    }
    uVar12 = _Size >> 5;
    if ((0x2000 < uVar12) && (0x1ff < uVar11)) {
      do {
        iVar7 = 4;
        do {
          puVar10 = puVar9;
          iVar7 = iVar7 + -1;
          puVar9 = puVar10 + 0x10;
        } while (iVar7 != 0);
        iVar7 = 8;
        puVar10 = puVar10 + -0x30;
        do {
          uVar4 = ((undefined8 *)(uVar11 + (longlong)puVar10))[1];
          puVar9 = (undefined8 *)(uVar11 + 0x10 + (longlong)puVar10);
          uVar5 = *puVar9;
          uVar6 = puVar9[1];
          *puVar10 = *(undefined8 *)(uVar11 + (longlong)puVar10);
          puVar10[1] = uVar4;
          puVar10[2] = uVar5;
          puVar10[3] = uVar6;
          puVar9 = puVar10 + 8;
          puVar1 = (undefined8 *)((uVar11 - 0x20) + (longlong)puVar9);
          uVar4 = puVar1[1];
          puVar2 = (undefined8 *)((uVar11 - 0x10) + (longlong)puVar9);
          uVar5 = *puVar2;
          uVar6 = puVar2[1];
          puVar10[4] = *puVar1;
          puVar10[5] = uVar4;
          puVar10[6] = uVar5;
          puVar10[7] = uVar6;
          iVar7 = iVar7 + -1;
          puVar10 = puVar9;
        } while (iVar7 != 0);
        _Size = _Size - 0x200;
      } while (0x1ff < _Size);
      LOCK();
      UNLOCK();
      uVar12 = _Size >> 5;
      if (uVar12 == 0) goto LAB_14000bd52;
    }
    _Size = _Size & 0x1f;
    puVar10 = puVar9;
    do {
      uVar4 = ((undefined8 *)(uVar11 + (longlong)puVar10))[1];
      puVar9 = (undefined8 *)(uVar11 + 0x10 + (longlong)puVar10);
      uVar5 = *puVar9;
      uVar6 = puVar9[1];
      puVar9 = puVar10 + 4;
      *puVar10 = *(undefined8 *)(uVar11 + (longlong)puVar10);
      puVar10[1] = uVar4;
      puVar10[2] = uVar5;
      puVar10[3] = uVar6;
      uVar12 = uVar12 - 1;
      puVar10 = puVar9;
    } while (uVar12 != 0);
  }
LAB_14000bd52:
  for (uVar12 = _Size >> 3; uVar12 != 0; uVar12 = uVar12 - 1) {
    *puVar9 = *(undefined8 *)(uVar11 + (longlong)puVar9);
    puVar9 = puVar9 + 1;
  }
  for (uVar12 = _Size & 7; uVar12 != 0; uVar12 = uVar12 - 1) {
    *(undefined1 *)puVar9 = *(undefined1 *)(uVar11 + (longlong)puVar9);
    puVar9 = (undefined8 *)((longlong)puVar9 + 1);
  }
  return _Dst;
}



===== entry @ 140012000 =====

void entry(undefined8 param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14001202c =====

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


