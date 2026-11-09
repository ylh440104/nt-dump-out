
===== DoBuildIo @ 140001000 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 DoBuildIo(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *extraout_RAX;
  undefined8 uVar4;
  longlong extraout_RAX_00;
  ulonglong uVar5;
  longlong lVar6;
  undefined1 uVar7;
  char cVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong lVar11;
  bool bVar12;
  undefined1 auStackY_d8 [32];
  undefined1 local_98;
  undefined1 local_97;
  undefined1 local_96;
  int local_94;
  undefined1 local_90 [8];
  undefined1 local_88 [8];
  char local_80 [8];
  char local_78 [8];
  char acStack_70 [8];
  undefined4 local_68;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  if ((*(char *)(param_1 + 0xd911) != '\0') && (*(char *)(param_2 + 2) != '\x02')) {
    uVar7 = 8;
    if (*(longlong *)(param_1 + 0xeb58) == 0) {
      uVar7 = 0x11;
    }
    *(undefined1 *)(param_2 + 3) = uVar7;
    return 1;
  }
  if ((*(char *)(param_2 + 7) != '\0') ||
     (((*(char *)(param_2 + 5) == '\0' && (*(char *)(param_2 + 2) == '\0')) &&
      (*(char *)((ulonglong)*(byte *)(param_2 + 6) + 0xd30a + param_1) == '\0')))) {
    *(undefined1 *)(param_2 + 3) = 0x20;
    return 1;
  }
  if ((*(char *)(param_1 + 0xd90c) == '\0') && (*(char *)(param_1 + 0xd90f) == '\0')) {
    cVar8 = *(char *)(param_2 + 2);
  }
  else {
    cVar8 = *(char *)(param_2 + 2);
    if (cVar8 == '\x02') {
      bVar12 = *(longlong *)(param_1 + 0x9220) == 0;
    }
    else {
      if (cVar8 == '\x12') goto switchD_1400010ec_caseD_1;
      if (cVar8 == '\x13') goto LAB_1400010c7;
      bVar12 = cVar8 == ' ';
    }
    if (!bVar12) {
      *(undefined1 *)(param_2 + 3) = 5;
      return 1;
    }
  }
LAB_1400010c7:
  *(undefined1 *)(param_2 + 3) = 0;
  switch(cVar8) {
  case '\0':
    break;
  case '\x02':
    uVar5 = MegaSASIoctl(param_1,param_2,3);
    if ((char)uVar5 == '\x01') {
      return 0;
    }
    return 1;
  case '\a':
    *(undefined1 *)(param_1 + 0xd307) = 1;
    StopAllTimerRoutine(param_1);
    if (*(char *)(param_1 + 0x89) == '\0') {
      return 1;
    }
    AbortPendedCommands(param_1);
    *(undefined4 *)(param_1 + 0xd918) = 30000000;
    SendAndWaitDCMD(param_1,0x1101000,3);
    *(undefined4 *)(param_1 + 0xd918) = 30000000;
    SendAndWaitDCMD(param_1,0x1060000,3);
    *(undefined2 *)(param_2 + 3) = 1;
    return 1;
  case '\b':
    if (*(char *)(param_1 + 0x9c) == '\0') {
      return 1;
    }
    plVar10 = (longlong *)(*(longlong *)(param_2 + 0x38) + 0x100U & 0xfffffffffffffeff);
    memset(plVar10 + 1,0,0x5f8);
    *plVar10 = param_2;
    cVar8 = *(char *)(param_1 + 0xd92a);
    *(char *)((longlong)plVar10 + 0x34) = cVar8;
    uVar7 = 8;
    if (cVar8 != '\0') {
      uVar7 = 0xc;
    }
    *(undefined1 *)((longlong)plVar10 + 0x52) = uVar7;
    lVar6 = StorPortGetPhysicalAddress(param_1,param_2,plVar10,local_90);
    plVar10[4] = lVar6 + 0x100;
    *(undefined1 *)(plVar10 + 0x20) = 5;
    *(undefined4 *)(plVar10 + 0x23) = 0x1101000;
    *(undefined1 *)((longlong)plVar10 + 0x102) = 0xff;
    *(undefined1 *)((longlong)plVar10 + 0x11c) = 3;
    return 0;
  case '\x13':
  case ' ':
    InitSRBExtension(param_1,param_2);
    *(bool *)(extraout_RAX_00 + 0xd) = (*(char *)(param_2 + 0x48) - 8U & 0x5f) == 0;
    *(bool *)(extraout_RAX_00 + 0xe) = (*(char *)(param_2 + 0x48) - 10U & 0x5f) == 0;
    *(bool *)(extraout_RAX_00 + 0xc) = (*(char *)(param_2 + 0x48) - 8U & 0x5d) == 0;
    return 0;
  case '\x17':
    return 0;
  case '$':
    if (*(char *)(param_1 + 0x89) == '\0') {
      return 0;
    }
  default:
switchD_1400010ec_caseD_1:
    *(undefined1 *)(param_2 + 3) = 6;
    return 1;
  }
  plVar10 = InitSRBExtension(param_1,param_2);
  *(bool *)((longlong)extraout_RAX + 0xd) = (*(char *)(param_2 + 0x48) - 8U & 0x5f) == 0;
  *(bool *)((longlong)extraout_RAX + 0xe) = (*(char *)(param_2 + 0x48) - 10U & 0x5f) == 0;
  bVar12 = (*(char *)(param_2 + 0x48) - 8U & 0x5d) == 0;
  *(bool *)((longlong)extraout_RAX + 0xc) = bVar12;
  if ((!bVar12) && (*(char *)(param_2 + 5) == '\x01')) {
    if ((*(char *)(param_2 + 0x48) == '\x12') && (*(char *)(param_2 + 6) == -2)) {
      *(bool *)(plVar10 + 0x1c34) = *(char *)((longlong)plVar10 + 0x89) == '\0';
    }
    if (((ushort)*(byte *)(param_2 + 6) == *(ushort *)((longlong)plVar10 + 0xe466)) &&
       (*(char *)(param_2 + 7) == '\0')) {
      if (*(char *)(param_2 + 0x48) == '\x12') {
        memset(*(void **)(param_2 + 0x18),0,(ulonglong)*(uint *)(param_2 + 0x10));
        memset(local_88,0,0x68);
        if ((*(byte *)(param_2 + 0x49) & 1) == 0) {
          local_80[0] = s_RAID_140016018[0];
          local_80[1] = s_RAID_140016018[1];
          local_80[2] = s_RAID_140016018[2];
          local_80[3] = s_RAID_140016018[3];
          local_80[4] = s_RAID_140016018[4];
          local_80[5] = s_RAID_140016018[5];
          local_80[6] = s_RAID_140016018[6];
          local_80[7] = s_RAID_140016018[7];
          local_88[0] = 0x1f;
          local_68 = 0x31303030;
          local_78[0] = s_DummyDevice_140016000[0];
          local_78[1] = s_DummyDevice_140016000[1];
          local_78[2] = s_DummyDevice_140016000[2];
          local_78[3] = s_DummyDevice_140016000[3];
          local_78[4] = s_DummyDevice_140016000[4];
          local_78[5] = s_DummyDevice_140016000[5];
          local_78[6] = s_DummyDevice_140016000[6];
          local_78[7] = s_DummyDevice_140016000[7];
          acStack_70[0] = s_DummyDevice_140016000[8];
          acStack_70[1] = s_DummyDevice_140016000[9];
          acStack_70[2] = s_DummyDevice_140016000[10];
          acStack_70[3] = s_DummyDevice_140016000[0xb];
          acStack_70[4] = s_DummyDevice_140016000[0xc];
          acStack_70[5] = s_DummyDevice_140016000[0xd];
          acStack_70[6] = s_DummyDevice_140016000[0xe];
          acStack_70[7] = s_DummyDevice_140016000[0xf];
          if (*(uint *)(param_2 + 0x10) < 0x68) {
            memmove(*(void **)(param_2 + 0x18),local_88,(ulonglong)*(uint *)(param_2 + 0x10));
            return 1;
          }
          memmove(*(void **)(param_2 + 0x18),local_88,0x68);
          *(undefined4 *)(param_2 + 0x10) = 0x68;
          return 1;
        }
      }
      goto switchD_1400010ec_caseD_1;
    }
    if ((*(char *)((longlong)plVar10 + 0xe8ac) == '\0') && (*(char *)(param_2 + 0x48) == '5')) {
      return 1;
    }
    if (*(char *)(param_2 + 0x48) == -0x6f) {
      return 1;
    }
  }
  if ((*(char *)((longlong)extraout_RAX + 0xc) != '\0') &&
     ((*(uint *)((longlong)plVar10 + 0xe45c) & 0x200) == 0)) {
    *(undefined1 *)((longlong)extraout_RAX + 0x36) = 1;
  }
  *(undefined1 *)(extraout_RAX + 2) = 1;
  uVar4 = MPT_BuildCmd_Scsi((longlong)plVar10,extraout_RAX);
  if ((char)uVar4 != '\0') {
    if (*(char *)((longlong)extraout_RAX + 0x36) != '\x01') {
      if ((((*(uint *)(plVar10 + 0x1b05) < 2) || (*(char *)((longlong)extraout_RAX + 0xc) == '\0'))
          || ((char)extraout_RAX[2] != '\0')) || (*(char *)((longlong)extraout_RAX + 0xa1) != '\0'))
      {
        *(undefined1 *)((longlong)extraout_RAX + 0xf) = 0;
        return 0;
      }
      *(undefined1 *)((longlong)extraout_RAX + 0xf) = 1;
      return 0;
    }
    lVar6 = MakeSRBExtension((longlong)plVar10,(longlong)extraout_RAX);
    if ((char)lVar6 != '\0') {
      *(short *)((longlong)extraout_RAX + 0xa6) = *(short *)((longlong)extraout_RAX + 0x14) + 1;
      if (((char)extraout_RAX[0x10] != '\0') && (*(char *)((longlong)extraout_RAX + 0xd) != '\0')) {
        StreamDetectOnly((longlong)plVar10,extraout_RAX);
      }
      MPT_SendIORequestToFW((longlong)plVar10,extraout_RAX);
      return 2;
    }
    lVar6 = *extraout_RAX;
    lVar2 = extraout_RAX[3];
    if (*(char *)((longlong)plVar10 + 0x91) == '\0') {
      StorPortBusy(plVar10,(int)plVar10[0x1245]);
    }
    else {
      *(undefined1 *)(lVar6 + 4) = 0x28;
    }
    *(undefined1 *)(lVar6 + 3) = 5;
    plVar9 = plVar10 + 0x125c;
    local_94 = 0;
    lVar11 = 0xff;
    do {
      plVar1 = plVar9 + 0x400;
      lVar3 = *plVar9;
      plVar9 = plVar9 + 4;
      local_94 = local_94 + (int)*plVar1 + (int)lVar3;
      lVar11 = lVar11 + -1;
    } while (lVar11 != 0);
    local_97 = *(undefined1 *)(lVar6 + 5);
    local_98 = *(undefined1 *)(lVar6 + 6);
    local_96 = *(undefined1 *)(lVar6 + 0x48);
    if (((char)plVar10[0x1d6a] != '\0') && ((*(uint *)((longlong)plVar10 + 0xeb54) & 0x2a9) != 0)) {
      RttLogEvent((longlong)plVar10,plVar10 + 0x1d60,(int *)(plVar10 + 0x1d63),0x2a9,&local_98,8,
                  (char)lVar2,3);
    }
    StorPortNotification(0,plVar10,lVar6);
  }
  return 2;
}



===== InitSRBExtension @ 1400015a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong * InitSRBExtension(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong *plVar2;
  undefined1 auStack_48 [32];
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_20;
  undefined2 local_18;
  undefined1 local_16;
  longlong *local_10;
  
  local_10 = (longlong *)(__security_cookie ^ (ulonglong)auStack_48);
  plVar2 = (longlong *)(*(longlong *)(param_2 + 0x38) + 0x100U & 0xfffffffffffffeff);
  memset(plVar2 + 1,0,0x1f8);
  *plVar2 = param_2;
  *(undefined1 *)((longlong)plVar2 + 9) = *(undefined1 *)(param_2 + 5);
  *(undefined1 *)(plVar2 + 1) = *(undefined1 *)(param_2 + 6);
  *(undefined1 *)((longlong)plVar2 + 10) = *(undefined1 *)(param_2 + 8);
  *(undefined1 *)((longlong)plVar2 + 0x74) = 0x10;
  *(undefined4 *)(plVar2 + 0xf) = 0x20000;
  *(undefined1 *)((longlong)plVar2 + 0x36) = 0;
  *(undefined1 *)((longlong)plVar2 + 0x34) = 1;
  *(undefined1 *)((longlong)plVar2 + 0x52) = 0x10;
  *(int *)(plVar2 + 0x17) = *(int *)(param_1 + 0xd92c) + -1;
  *(undefined2 *)(plVar2 + 6) = 0xffff;
  local_24 = 0x14;
  local_28 = 2;
  iVar1 = StorPortExtendedFunction(0xf,param_1,param_2,&local_28);
  if (((iVar1 == 0) && (*(char *)(param_1 + 0x89) == '\0')) && (*(char *)(param_1 + 0xd85a) != '\0')
     ) {
    *(undefined1 *)(plVar2 + 3) = local_20;
    *(undefined1 *)((longlong)plVar2 + 0x19) = local_20;
    *(undefined1 *)((longlong)plVar2 + 0xc6) = local_16;
    *(undefined2 *)(plVar2 + 0x19) = local_18;
  }
  return local_10;
}



===== MakeSRBExtension @ 1400016c0 =====

longlong MakeSRBExtension(longlong param_1,longlong param_2)

{
  int *piVar1;
  longlong *plVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  longlong lVar9;
  byte bVar10;
  bool bVar11;
  
  lVar9 = (ulonglong)*(byte *)(param_2 + 0xc6) * 0x240;
  bVar10 = *(byte *)(lVar9 + 0x220 + param_1);
  *(byte *)(lVar9 + 0x220 + param_1) = bVar10 + 1;
  uVar3 = *(ushort *)
           (param_1 + (((ulonglong)*(byte *)(param_2 + 0xc6) + 1) * 0x120 + (ulonglong)bVar10) * 2);
  uVar7 = (ulonglong)uVar3;
  do {
    if (*(longlong *)(uVar7 * 8 + *(longlong *)(param_1 + 0x208)) == 0) {
      plVar2 = (longlong *)(*(longlong *)(param_1 + 0x208) + uVar7 * 8);
      LOCK();
      bVar11 = *plVar2 == 0;
      if (bVar11) {
        *plVar2 = param_2;
      }
      UNLOCK();
      if (bVar11) {
        lVar9 = (ulonglong)*(byte *)(param_2 + 8) * 0x20 + param_1;
        *(int *)(param_2 + 0x14) = (int)uVar7;
        if (*(char *)(param_2 + 9) == '\0') {
          LOCK();
          piVar1 = (int *)(lVar9 + 0x92e0);
          iVar6 = *piVar1;
          *piVar1 = *piVar1 + 1;
          UNLOCK();
          bVar10 = 8;
        }
        else {
          LOCK();
          piVar1 = (int *)(lVar9 + 0xb2e0);
          iVar6 = *piVar1;
          *piVar1 = *piVar1 + 1;
          UNLOCK();
          bVar10 = *(byte *)((ulonglong)*(byte *)(param_2 + 8) + 0xec88 + param_1);
        }
        if (*(char *)(param_1 + 0xeb68) != '\0') {
          uVar7 = (ulonglong)
                  *(byte *)(*(longlong *)
                             (param_1 + 0xebd8 + (ulonglong)*(ushort *)(param_2 + 200) * 8) +
                           (ulonglong)*(byte *)(param_2 + 0xc6));
          if ((uint)bVar10 < iVar6 + 1U) {
            if (*(char *)(uVar7 + 0xec38 + param_1) == '\0') goto LAB_140001857;
            uVar5 = *(uint *)(param_1 + 0x9230 + uVar7 * 8);
            plVar2 = (longlong *)(param_1 + 0x9230 + uVar7 * 8);
            *plVar2 = *plVar2 + 1;
            uVar8 = (ulonglong)(uVar5 >> 4) % (ulonglong)*(byte *)(uVar7 + 0xec38 + param_1);
          }
          else {
            if ((*(uint *)(param_1 + 0xeb78) <= (uint)*(byte *)(param_2 + 0x19)) ||
               (uVar5 = (uint)*(byte *)(uVar7 + 0xec80 + param_1) -
                        (uint)*(byte *)(uVar7 + 0xec38 + param_1), uVar5 == 0)) goto LAB_140001857;
            uVar4 = *(uint *)(param_1 + 0x9270 + uVar7 * 8);
            plVar2 = (longlong *)(param_1 + 0x9270 + uVar7 * 8);
            *plVar2 = *plVar2 + 1;
            uVar8 = (ulonglong)
                    (byte)((char)((uVar4 >> 4) % uVar5) + *(char *)(uVar7 + 0xec38 + param_1));
          }
          *(undefined1 *)(param_2 + 0x18) =
               *(undefined1 *)(*(longlong *)(param_1 + 0xeb98 + uVar7 * 8) + uVar8 * 4);
        }
LAB_140001857:
        *(undefined1 *)(param_2 + 0xa5) = *(undefined1 *)(param_2 + 0x18);
        return 1;
      }
    }
    uVar5 = (int)uVar7 + 1;
    uVar7 = 0;
    if (uVar5 < *(uint *)(param_1 + 0xd804)) {
      uVar7 = (ulonglong)uVar5;
    }
    if ((uint)uVar7 == (uint)uVar3) {
      return (ulonglong)(uint3)(uVar5 >> 8) << 8;
    }
  } while( true );
}



===== MegaSASBuildIo @ 140001870 =====

undefined8 MegaSASBuildIo(longlong param_1,longlong param_2)

{
  int iVar1;
  ulonglong uVar2;
  
  uVar2 = DoBuildIo(param_1,param_2);
  iVar1 = (int)uVar2;
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      if (*(char *)(param_2 + 3) == '\0') {
        *(undefined2 *)(param_2 + 3) = 1;
      }
      uVar2 = StorPortNotification(0,param_1,param_2);
      return uVar2 & 0xffffffffffffff00;
    }
    uVar2 = (ulonglong)(iVar1 - 2U);
    if (iVar1 - 2U == 0) {
      return 0;
    }
  }
  return CONCAT71((int7)(uVar2 >> 8),1);
}



===== StreamDetectOnly @ 1400018e0 =====

void StreamDetectOnly(longlong param_1,longlong *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  byte bVar8;
  ulonglong uVar9;
  int *piVar10;
  uint uVar11;
  longlong lVar12;
  
  bVar8 = *(byte *)(*param_2 + 6);
  lVar12 = (ulonglong)bVar8 * 0xa0;
  piVar10 = (int *)(*(longlong *)(param_1 + 0xd820) + lVar12);
  LOCK();
  iVar1 = *piVar10;
  *piVar10 = *piVar10 + 1;
  UNLOCK();
  iVar2 = piVar10[1];
  while (iVar1 + 1 != iVar2) {
    iVar2 = piVar10[1];
  }
  lVar4 = *(longlong *)(param_1 + 0xd820);
  lVar7 = (ulonglong)bVar8 * 10;
  uVar11 = 0;
  while( true ) {
    uVar9 = (ulonglong)((uint)piVar10[2] >> ((byte)(uVar11 << 2) & 0x3f) & 0xf);
    lVar6 = lVar7 + 2 + uVar9;
    uVar5 = *(ulonglong *)(lVar4 + lVar6 * 0x10);
    if (((uVar5 <= (ulonglong)param_2[7]) && ((ulonglong)param_2[7] <= uVar5 + 0x20)) &&
       (*(char *)(lVar4 + 8 + lVar6 * 0x10) == *(char *)(*param_2 + 0x48))) break;
    bVar8 = (char)uVar11 + 1;
    uVar11 = (uint)bVar8;
    if (7 < bVar8) {
      lVar7 = lVar7 + 2 + uVar9;
      *(undefined1 *)(lVar4 + 8 + lVar7 * 0x10) = *(undefined1 *)(*param_2 + 0x48);
      *(ulonglong *)(lVar4 + lVar7 * 0x10) = (ulonglong)*(uint *)(param_2 + 9) + param_2[7];
      piVar10[2] = piVar10[2] << 4 | (uint)piVar10[2] >> 0x1c;
LAB_1400019c1:
      LOCK();
      piVar10 = (int *)(*(longlong *)(param_1 + 0xd820) + 4 + lVar12);
      *piVar10 = *piVar10 + 1;
      UNLOCK();
      return;
    }
  }
  *(ushort *)((longlong)param_2 + 0x17c) = *(ushort *)((longlong)param_2 + 0x17c) | 0x8000;
  if ((char)uVar11 != '\0') {
    uVar3 = piVar10[2];
    bVar8 = (byte)(uVar11 << 2);
    uVar11 = (1 << (bVar8 & 0x1f)) - 1;
    piVar10[2] = ~(0xf << (bVar8 & 0x1f) | uVar11) & uVar3 | (uVar3 & uVar11) << 4 |
                 uVar3 >> (bVar8 & 0x1f) & 0xf;
  }
  *(ulonglong *)(lVar4 + lVar6 * 0x10) = (ulonglong)*(uint *)(param_2 + 9) + param_2[7];
  goto LAB_1400019c1;
}



===== CompleteScsiRequest @ 140001a50 =====

undefined8
CompleteScsiRequest(longlong param_1,longlong *param_2,char param_3,char param_4,uint param_5,
                   undefined4 param_6,undefined1 param_7)

{
  int *piVar1;
  uint *puVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  longlong lVar7;
  bool bVar8;
  byte bVar9;
  undefined8 uVar10;
  longlong lVar11;
  longlong lVar12;
  byte bVar13;
  uint uVar14;
  uint uVar15;
  longlong lVar16;
  
  lVar7 = *param_2;
  bVar8 = true;
  if ((((param_3 == '\0') && (*(char *)(lVar7 + 0x48) == '\x12')) &&
      (*(char *)(lVar7 + 0x49) == '\0')) &&
     ((*(char *)(lVar7 + 0x4a) == '\0' && (*(char *)(lVar7 + 0x4d) == '\0')))) {
    lVar11 = param_1 + (ulonglong)*(byte *)(lVar7 + 6);
    if (*(char *)(lVar7 + 5) == '\x01') {
      *(byte *)(lVar11 + 0xe1b0) = *(byte *)(lVar11 + 0xe1b0) | 1;
      bVar9 = *(byte *)(lVar7 + 6) >> 5;
      bVar13 = bVar9 + 8;
      if (*(char *)(lVar7 + 5) != '\x01') {
        bVar13 = bVar9;
      }
      puVar2 = (uint *)(param_1 + 0xe804 + (ulonglong)bVar13 * 4);
      *puVar2 = *puVar2 | 1 << (*(byte *)(lVar7 + 6) & 0x1f);
      *(undefined1 *)(param_1 + 0xd8e6) = 1;
    }
    else {
      *(byte *)(lVar11 + 0xe1b0) = *(byte *)(lVar11 + 0xe1b0) | 2;
      if (((**(byte **)(lVar7 + 0x18) & 0x1f) == 0xd) && (*(char *)(param_1 + 0xd300) != '\0')) {
        pbVar3 = (byte *)((ulonglong)*(byte *)(lVar7 + 6) + 0xe1b0 + param_1);
        *pbVar3 = *pbVar3 | 4;
        goto LAB_140001b69;
      }
      puVar2 = (uint *)(param_1 + 0xe7e4 + (ulonglong)(*(byte *)(lVar7 + 6) >> 5) * 4);
      *puVar2 = *puVar2 | 1 << (*(byte *)(lVar7 + 6) & 0x1f);
      *(undefined1 *)(param_1 + 0xd8e4) = 1;
    }
    *(undefined1 *)(param_1 + 0xd8d0) = 1;
  }
LAB_140001b69:
  if (*(char *)((longlong)param_2 + 0xf) != '\0') {
    LOCK();
    piVar1 = (int *)((ulonglong)*(byte *)(lVar7 + 6) * 0x180 + 0x20 +
                    *(longlong *)(param_1 + 0xd818));
    iVar4 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar4 + -1 < 1) {
      lVar11 = 0;
      lVar16 = 8;
      do {
        lVar12 = (ulonglong)*(byte *)(lVar7 + 6) * 0x180 + *(longlong *)(param_1 + 0xd818);
        if (*(longlong *)(lVar12 + 0x30 + lVar11) != 0) {
          *(undefined1 *)(lVar12 + 0x48 + lVar11) = 1;
        }
        lVar11 = lVar11 + 0x28;
        lVar16 = lVar16 + -1;
      } while (lVar16 != 0);
      *(undefined1 *)(param_1 + 0xd830) = 1;
      *(undefined1 *)(param_1 + 0xd8d0) = 1;
    }
  }
  uVar5 = *(uint *)((longlong)param_2 + 0x14);
  lVar7 = *(longlong *)(param_1 + 0x1f8);
  do {
    lVar11 = *param_2;
    if ((((*(char *)((longlong)param_2 + 0xc) == '\0') && (param_3 == '\0')) &&
        (uVar14 = *(uint *)(param_2 + 0xe), uVar14 != 0)) &&
       (uVar6 = *(uint *)(lVar11 + 0x10), uVar6 != uVar14)) {
      uVar15 = uVar6;
      if ((*(char *)(lVar11 + 0x48) == '^') && (uVar6 < uVar14)) {
        *(uint *)(param_2 + 0xe) = uVar6;
        uVar15 = *(uint *)(lVar11 + 0x10);
        uVar14 = uVar6;
      }
      if (uVar14 < uVar15) {
        *(uint *)(lVar11 + 0x10) = uVar14;
      }
      *(undefined1 *)(lVar11 + 3) = 0x12;
    }
    else {
      MapSrbStatus(param_1,param_2,param_3,param_4,(void *)(lVar7 + (ulonglong)uVar5 * 0x12),param_6
                   ,param_7);
    }
    if (bVar8) {
      bVar8 = false;
      *(undefined8 *)(*(longlong *)(param_1 + 0x208) + (ulonglong)param_5 * 8) = 0;
      lVar16 = (ulonglong)*(byte *)((longlong)param_2 + 0xc6) * 0x240;
      bVar13 = *(byte *)(lVar16 + 0x440 + param_1);
      *(byte *)(lVar16 + 0x440 + param_1) = bVar13 + 1;
      lVar16 = 0x92e0;
      *(short *)(param_1 +
                (((ulonglong)*(byte *)((longlong)param_2 + 0xc6) + 1) * 0x120 + (ulonglong)bVar13) *
                2) = (short)param_5;
      if (*(char *)((longlong)param_2 + 9) != '\0') {
        lVar16 = 0xb2e0;
      }
      LOCK();
      piVar1 = (int *)((ulonglong)*(byte *)(param_2 + 1) * 0x20 + lVar16 + param_1);
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (((char)param_2[0x12] != '\0') && ((char)param_2[0x20] == '\x05')) {
        LOCK();
        *(int *)(param_1 + 0x92c0) = *(int *)(param_1 + 0x92c0) + -1;
        UNLOCK();
      }
    }
    param_2 = (longlong *)param_2[0x11];
    uVar10 = StorPortNotification(0,param_1,lVar11);
  } while (param_2 != (longlong *)0x0);
  return CONCAT71((int7)((ulonglong)uVar10 >> 8),1);
}



===== MR_CompleteR1FPWRequest @ 140001d50 =====

ulonglong MR_CompleteR1FPWRequest
                    (longlong param_1,longlong *param_2,ushort param_3,undefined4 param_4)

{
  void *pvVar1;
  longlong lVar2;
  int *piVar3;
  int iVar4;
  undefined1 uVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  byte bVar9;
  uint uVar10;
  longlong lVar11;
  bool bVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  char cVar15;
  longlong lVar16;
  longlong lVar17;
  longlong lVar18;
  longlong lVar19;
  undefined1 local_res8;
  char local_res9;
  char local_resa;
  undefined1 local_resb;
  undefined1 local_resc;
  undefined2 local_resd;
  longlong local_res10;
  uint local_res18;
  
  lVar11 = *param_2;
  bVar12 = true;
  uVar10 = *(uint *)((longlong)param_2 + 0x14);
  local_res10 = (ulonglong)param_3 * 0x100 + *(longlong *)(param_1 + 0xd998);
  local_res18 = *(uint *)(param_2 + 5);
  uVar13 = (ulonglong)local_res18;
  uVar5 = (undefined1)param_2[3];
  cVar6 = *(char *)(local_res10 + 0x77);
  lVar19 = (ulonglong)*(ushort *)(local_res10 + 0x74) * 0x100 + *(longlong *)(param_1 + 0xd998);
  cVar7 = *(char *)(lVar19 + 0x77);
  *(undefined4 *)(param_2 + 0xe) = *(undefined4 *)(local_res10 + 0x1c);
  pvVar1 = (void *)(*(longlong *)(param_1 + 0x1f8) + (ulonglong)uVar10 * 0x12);
  lVar2 = (ulonglong)uVar10 * 8;
  if (*(longlong **)(lVar2 + *(longlong *)(param_1 + 0x208)) == param_2) {
    if (*(longlong **)(uVar13 * 8 + *(longlong *)(param_1 + 0x208)) == param_2) {
      if (*(char *)((longlong)param_2 + 0xf) != '\0') {
        LOCK();
        piVar3 = (int *)((ulonglong)*(byte *)(lVar11 + 6) * 0x180 + 0x20 +
                        *(longlong *)(param_1 + 0xd818));
        iVar4 = *piVar3;
        *piVar3 = *piVar3 + -1;
        UNLOCK();
        if (iVar4 + -1 < 1) {
          lVar17 = 0;
          lVar18 = 8;
          do {
            lVar16 = (ulonglong)*(byte *)(lVar11 + 6) * 0x180 + lVar17;
            if (*(longlong *)(lVar16 + 0x30 + *(longlong *)(param_1 + 0xd818)) != 0) {
              *(undefined1 *)(lVar16 + 0x48 + *(longlong *)(param_1 + 0xd818)) = 1;
            }
            lVar17 = lVar17 + 0x28;
            lVar18 = lVar18 + -1;
          } while (lVar18 != 0);
          *(undefined1 *)(param_1 + 0xd830) = 1;
          *(undefined1 *)(param_1 + 0xd8d0) = 1;
        }
      }
      do {
        lVar11 = *param_2;
        if (cVar6 == '\0') {
          if (cVar7 != '\0') goto LAB_140001eec;
          *(undefined1 *)(lVar11 + 3) = 1;
        }
        else {
          if (cVar6 != 'g') {
LAB_140001eec:
            if (cVar7 != 'g') {
              if (cVar6 == '\0') {
                MapSrbStatus(param_1,param_2,cVar7,*(char *)(lVar19 + 0x76),pvVar1,param_4,uVar5);
              }
              else {
                MapSrbStatus(param_1,param_2,cVar6,*(char *)(local_res10 + 0x76),pvVar1,param_4,
                             uVar5);
              }
              goto LAB_14000203a;
            }
          }
          *(undefined1 *)(lVar11 + 3) = 5;
          cVar15 = '\x05';
          if ((((*(int *)(param_1 + 0xd8d8) != 2) && (*(int *)(param_1 + 0xd8e0) != 2)) &&
              (*(char *)(param_1 + 0xd90f) == '\0')) && (*(char *)(param_1 + 0xd90c) == '\0')) {
            *(undefined1 *)(param_1 + 0xd928) = 0;
            StorPortNotification(6,param_1,ReEnableFastPath);
            *(undefined1 *)(param_1 + 0xd913) = 1;
            cVar15 = *(char *)(lVar11 + 3);
          }
          if (cVar15 != '\x01') {
            cVar8 = *(char *)(lVar11 + 5);
            if (cVar8 == '\0') {
LAB_140001fb0:
              local_res8 = *(undefined1 *)(lVar11 + 6);
              local_resb = *(undefined1 *)(lVar11 + 4);
              local_resc = *(undefined1 *)(lVar11 + 0x48);
              local_resd = 0x67;
              local_res9 = cVar8;
              local_resa = cVar15;
              if ((*(char *)(param_1 + 0xeb50) != '\0') &&
                 ((*(uint *)(param_1 + 0xeb54) & 0x284) != 0)) {
                RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x284,&local_res8,7,
                            uVar5,param_4);
              }
            }
            else if (*(char *)(lVar11 + 0x48) != -0x60) {
              if (*(char *)(lVar11 + 0x48) != '\x12') goto LAB_140001fb0;
            }
          }
        }
LAB_14000203a:
        if (bVar12) {
          *(undefined8 *)(lVar2 + *(longlong *)(param_1 + 0x208)) = 0;
          lVar17 = (ulonglong)*(byte *)((longlong)param_2 + 0xc6) * 0x240;
          bVar9 = *(byte *)(lVar17 + 0x440 + param_1);
          *(byte *)(lVar17 + 0x440 + param_1) = bVar9 + 1;
          *(short *)(param_1 +
                    (((ulonglong)*(byte *)((longlong)param_2 + 0xc6) + 1) * 0x120 + (ulonglong)bVar9
                    ) * 2) = (short)uVar10;
          lVar17 = 0x92e0;
          if (*(char *)((longlong)param_2 + 9) != '\0') {
            lVar17 = 0xb2e0;
          }
          LOCK();
          piVar3 = (int *)((ulonglong)*(byte *)(param_2 + 1) * 0x20 + lVar17 + param_1);
          *piVar3 = *piVar3 + -1;
          UNLOCK();
          if (((char)param_2[0x12] != '\0') && ((char)param_2[0x20] == '\x05')) {
            LOCK();
            *(int *)(param_1 + 0x92c0) = *(int *)(param_1 + 0x92c0) + -1;
            UNLOCK();
          }
          *(undefined8 *)(uVar13 * 8 + *(longlong *)(param_1 + 0x208)) = 0;
          lVar17 = (ulonglong)*(byte *)((longlong)param_2 + 0xc6) * 0x240;
          bVar9 = *(byte *)(lVar17 + 0x440 + param_1);
          *(byte *)(lVar17 + 0x440 + param_1) = bVar9 + 1;
          *(short *)(param_1 +
                    (((ulonglong)*(byte *)((longlong)param_2 + 0xc6) + 1) * 0x120 + (ulonglong)bVar9
                    ) * 2) = (short)local_res18;
          lVar17 = 0x92e0;
          if (*(char *)((longlong)param_2 + 9) != '\0') {
            lVar17 = 0xb2e0;
          }
          LOCK();
          piVar3 = (int *)((ulonglong)*(byte *)(param_2 + 1) * 0x20 + lVar17 + param_1);
          *piVar3 = *piVar3 + -1;
          UNLOCK();
          if (((char)param_2[0x12] != '\0') && ((char)param_2[0x20] == '\x05')) {
            LOCK();
            *(int *)(param_1 + 0x92c0) = *(int *)(param_1 + 0x92c0) + -1;
            UNLOCK();
          }
          bVar12 = false;
        }
        param_2 = (longlong *)param_2[0x11];
        uVar14 = StorPortNotification(0,param_1,lVar11);
      } while (param_2 != (longlong *)0x0);
      uVar13 = CONCAT71((int7)((ulonglong)uVar14 >> 8),1);
    }
    else {
      uVar13 = SetDeadAdapter(param_1,0x28,param_4,uVar5);
      uVar13 = uVar13 & 0xffffffffffffff00;
    }
  }
  else {
    uVar13 = SetDeadAdapter(param_1,0x27,param_4,uVar5);
    uVar13 = uVar13 & 0xffffffffffffff00;
  }
  return uVar13;
}



===== MapSrbStatus @ 1400021b0 =====

void MapSrbStatus(longlong param_1,longlong *param_2,char param_3,char param_4,void *param_5,
                 undefined4 param_6,undefined1 param_7)

{
  longlong lVar1;
  size_t _Size;
  undefined1 local_res10;
  char local_res11;
  char local_res12;
  undefined1 local_res13;
  undefined1 local_res14;
  char local_res15;
  char local_res16;
  byte local_res18;
  undefined1 local_res19;
  
  lVar1 = *param_2;
  switch(param_3) {
  case '\0':
    *(undefined1 *)(lVar1 + 3) = 1;
    local_res12 = '\x01';
    break;
  case '\x01':
  case '\x02':
  case '\x03':
  case '\x04':
  case '\x19':
  case '.':
    *(undefined1 *)(lVar1 + 3) = 6;
    local_res12 = '\x06';
    *(char *)(lVar1 + 4) = param_4;
    break;
  default:
    *(undefined1 *)(lVar1 + 3) = 4;
    goto LAB_14000232f;
  case '\f':
  case '\"':
  case '3':
    *(undefined1 *)(lVar1 + 3) = 8;
    local_res12 = '\b';
    break;
  case '\x18':
    *(undefined2 *)(lVar1 + 3) = 0x204;
    goto LAB_14000232f;
  case '-':
    *(undefined1 *)(lVar1 + 3) = 4;
    *(char *)(lVar1 + 4) = param_4;
    if (((*(char *)(param_1 + 0x89) == '\0') && (param_4 == '\x02')) &&
       (*(void **)(lVar1 + 0x20) != (void *)0x0)) {
      if ((*(uint *)(lVar1 + 0xc) & 0x20) == 0) {
        _Size = (size_t)*(byte *)(lVar1 + 0xb);
        if (0x11 < *(byte *)(lVar1 + 0xb)) {
          _Size = 0x12;
        }
        memmove(*(void **)(lVar1 + 0x20),param_5,_Size);
        *(byte *)(lVar1 + 3) = *(byte *)(lVar1 + 3) | 0x80;
      }
      if (((*(byte *)((longlong)param_5 + 2) & 0xf) == 6) &&
         (*(char *)((longlong)param_5 + 0xc) == ')')) {
        memset((void *)(param_1 + 0xe1b0),0,0x100);
        StorPortNotification(7,param_1);
        StorPortNotification(7,param_1);
      }
    }
    local_res12 = *(char *)(lVar1 + 3);
    break;
  case '/':
    *(undefined2 *)(lVar1 + 3) = 0x1804;
LAB_14000232f:
    local_res12 = '\x04';
    break;
  case 'g':
    *(undefined1 *)(lVar1 + 3) = 5;
    local_res12 = '\x05';
    if ((((*(int *)(param_1 + 0xd8d8) != 2) && (*(int *)(param_1 + 0xd8e0) != 2)) &&
        (*(char *)(param_1 + 0xd90f) == '\0')) && (*(char *)(param_1 + 0xd90c) == '\0')) {
      *(undefined1 *)(param_1 + 0xd928) = 0;
      StorPortNotification(6,param_1,ReEnableFastPath,1000000);
      *(undefined1 *)(param_1 + 0xd913) = 1;
      local_res12 = *(char *)(lVar1 + 3);
    }
  }
  if ((local_res12 != '\x01') &&
     ((local_res11 = *(char *)(lVar1 + 5), local_res11 == '\0' ||
      ((*(char *)(lVar1 + 0x48) != -0x60 && (*(char *)(lVar1 + 0x48) != '\x12')))))) {
    local_res10 = *(undefined1 *)(lVar1 + 6);
    local_res13 = *(undefined1 *)(lVar1 + 4);
    local_res14 = *(undefined1 *)(lVar1 + 0x48);
    local_res15 = param_3;
    local_res16 = param_4;
    if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x284) != 0)) {
      RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x284,&local_res10,7,param_7,
                  param_6);
    }
    if (((param_3 == '-') && (*(char *)(lVar1 + 4) == '\x02')) &&
       (lVar1 = *(longlong *)(lVar1 + 0x20), lVar1 != 0)) {
      local_res19 = *(undefined1 *)(lVar1 + 0xc);
      local_res18 = *(byte *)(lVar1 + 2) & 0xf;
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x285) != 0)) {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x285,&local_res18,2,param_7,
                    param_6);
      }
    }
  }
  return;
}



===== ReEnableFastPath @ 1400024f0 =====

void ReEnableFastPath(longlong param_1)

{
  if (*(char *)(param_1 + 0xd914) != '\0') {
    StorPortNotification(6,param_1,ReEnableFastPath,500000);
  }
  *(undefined1 *)(param_1 + 0xd913) = 0;
  if (((*(char *)(param_1 + 0x89) == '\0') && (*(char *)(param_1 + 0xd912) == '\0')) &&
     (*(int *)(param_1 + 0xe8a8) == 0)) {
    *(undefined1 *)(param_1 + 0xd928) = 1;
  }
  return;
}



===== SetDeviceQueueDepths @ 140002550 =====

void SetDeviceQueueDepths(longlong param_1,undefined4 param_2,undefined1 param_3)

{
  ushort uVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  byte *pbVar5;
  ulonglong uVar6;
  undefined7 uVar7;
  int iVar8;
  byte bVar9;
  uint uVar10;
  ulonglong uVar11;
  undefined4 uVar12;
  longlong lVar13;
  longlong lVar14;
  ulonglong uVar15;
  int iVar16;
  int iVar17;
  char cVar18;
  int iVar19;
  uint uVar20;
  undefined4 local_res20;
  char local_68;
  byte local_67;
  uint local_64;
  uint local_60;
  undefined1 local_5c;
  undefined1 local_5b;
  undefined1 local_5a;
  undefined1 local_59;
  undefined1 local_58;
  undefined1 local_57;
  undefined1 local_50;
  undefined1 local_4f;
  undefined1 local_4e;
  undefined1 local_4d;
  uint local_4c;
  longlong local_48;
  
  local_48 = 0;
  iVar16 = 0;
  iVar17 = 0;
  iVar19 = 0;
  iVar8 = 0;
  uVar4 = 0;
  pbVar5 = (byte *)(param_1 + 0xe1b0);
  lVar13 = 0xff;
  do {
    bVar9 = *pbVar5;
    if (bVar9 != 0) {
      uVar20 = uVar4 + 1;
      if ((bVar9 & 1) == 0) {
        uVar20 = uVar4;
      }
      uVar4 = uVar20;
      iVar2 = iVar8 + 1;
      if ((bVar9 & 0x40) == 0) {
        iVar2 = iVar8;
      }
      iVar8 = iVar2;
      iVar2 = iVar19 + 1;
      if (-1 < (char)bVar9) {
        iVar2 = iVar19;
      }
      iVar19 = iVar2;
      if ((bVar9 & 0x10) == 0) {
        if ((bVar9 & 4) != 0) {
          iVar17 = iVar17 + 1;
        }
      }
      else {
        iVar16 = iVar16 + 1;
      }
    }
    pbVar5 = pbVar5 + 1;
    lVar13 = lVar13 + -1;
  } while (lVar13 != 0);
  uVar20 = iVar16 + iVar19 + iVar8 + uVar4;
  if (uVar20 == 0) {
    return;
  }
  local_5c = (undefined1)uVar20;
  local_5b = (undefined1)uVar4;
  local_5a = (undefined1)iVar8;
  local_59 = (undefined1)iVar19;
  local_58 = (undefined1)iVar17;
  local_57 = (undefined1)iVar16;
  if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x185) != 0)) {
    RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x185,&local_5c,6,param_3,param_2
               );
  }
  iVar2 = *(int *)(param_1 + 0xd804);
  uVar6 = (ulonglong)(uint)(iVar2 + iVar17 * -4) / (ulonglong)uVar20;
  uVar20 = (uint)uVar6;
  if (uVar20 < 0x20) {
    uVar11 = uVar6;
    uVar15 = uVar6;
    uVar4 = uVar20;
    local_res20 = uVar20;
    local_64 = uVar20;
    local_60 = uVar20;
    goto LAB_1400027d0;
  }
  uVar15 = 0x20;
  local_res20 = 0x20;
  if (uVar20 < 0x40) {
    uVar4 = iVar16 + iVar8 + uVar4;
    if (uVar4 == 0) {
LAB_1400026c9:
      uVar11 = 0x14;
      local_64 = 0x14;
    }
    else {
      uVar11 = (ulonglong)(uint)(iVar2 + (iVar19 * 8 + iVar17) * -4) / (ulonglong)uVar4;
      local_64 = (uint)uVar11;
      if (local_64 == 0) goto LAB_1400026c9;
    }
    uVar10 = (uint)uVar11;
    uVar4 = uVar10;
    if (0xfe < uVar10) {
      uVar4 = 0xfe;
    }
    uVar6 = uVar11;
    if (0x40 < uVar10) {
      uVar6 = 0x40;
    }
    local_60 = (uint)uVar6;
joined_r0x000140002766:
    if (uVar10 < 0x81) goto LAB_1400027d0;
  }
  else {
    local_60 = 0x40;
    if (uVar20 < 0x80) {
      if (iVar16 + uVar4 == 0) {
LAB_140002744:
        uVar11 = 0x14;
        local_64 = 0x14;
      }
      else {
        uVar11 = (ulonglong)(uint)(iVar2 + ((iVar19 + iVar8 * 2) * 8 + iVar17) * -4) /
                 (ulonglong)(iVar16 + uVar4);
        local_64 = (uint)uVar11;
        if (local_64 == 0) goto LAB_140002744;
      }
      uVar6 = 0x40;
      uVar10 = (uint)uVar11;
      uVar4 = uVar10;
      if (0xfe < uVar10) {
        uVar4 = 0xfe;
      }
      goto joined_r0x000140002766;
    }
    if (uVar20 < 0xfe) {
      local_64 = 0x80;
      if ((uVar4 == 0) ||
         (uVar4 = (uint)(iVar2 + ((iVar19 + (iVar8 + iVar16 * 2) * 2) * 8 + iVar17) * -4) / uVar4,
         uVar4 == 0)) {
        uVar11 = 0x80;
        uVar4 = 0x14;
        uVar6 = 0x40;
      }
      else {
        uVar11 = 0x80;
        uVar6 = 0x40;
        if (0xfe < uVar4) {
          uVar4 = 0xfe;
        }
      }
      goto LAB_1400027d0;
    }
    uVar6 = 0x40;
    uVar4 = 0xfe;
  }
  uVar11 = 0x80;
  local_64 = 0x80;
LAB_1400027d0:
  local_50 = (undefined1)uVar4;
  local_4f = (undefined1)uVar6;
  local_4e = (undefined1)uVar15;
  local_4d = (undefined1)uVar11;
  local_4c = uVar20;
  if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x186) != 0)) {
    RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x186,&local_50,8,param_3,param_2
               );
  }
  uVar10 = local_res20;
  if (*(char *)(param_1 + 0xe1a1) != '\0') {
    if (*(char *)(param_1 + 0xe1a1) == '\x01') {
      uVar4 = *(uint *)(param_1 + 0xe1a4);
      if (uVar20 <= *(uint *)(param_1 + 0xe1a4)) {
        uVar4 = uVar20;
      }
    }
    else {
      uVar4 = local_res20;
    }
  }
  pbVar5 = (byte *)(param_1 + 0xe1b0);
  cVar18 = '\0';
  do {
    uVar20 = (uint)uVar11;
    if ((*pbVar5 & 1) == 0) goto LAB_140002981;
    lVar13 = *(longlong *)(param_1 + 0xd930 + (ulonglong)(*(int *)(param_1 + 0xd92c) - 1U & 1) * 8);
    uVar7 = (undefined7)((ulonglong)lVar13 >> 8);
    if ((lVar13 == 0) ||
       (uVar1 = *(ushort *)(local_48 + *(longlong *)(lVar13 + 0x40)),
       *(ushort *)(param_1 + 0xe462) <= uVar1)) {
LAB_140002aa3:
      StorPortSetDeviceQueueDepth(param_1,CONCAT71(uVar7,1),cVar18,0,uVar4);
    }
    else {
      lVar14 = (ulonglong)uVar1 * 0x9e0 + *(longlong *)(lVar13 + 0x50);
      uVar1 = *(ushort *)
               ((ulonglong)*(ushort *)(lVar14 + 0xb8) * 0x40 + *(longlong *)(lVar13 + 0x48));
      if (uVar1 == 0xffff) goto LAB_140002aa3;
      if (((*(char *)(*(longlong *)(lVar13 + 0x38) + 3 + (ulonglong)uVar1 * 8) == '\x05') &&
          (0x80 < uVar4)) && (*(char *)(lVar14 + 0x11) == '\x01')) {
        cVar3 = StorPortSetDeviceQueueDepth(param_1,CONCAT71(uVar7,1),cVar18,0,0x80);
        local_res20._0_2_ = CONCAT11((char)uVar4,cVar18);
        if (cVar3 == '\0') {
          if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x196) != 0))
          {
            uVar12 = 0x196;
            goto LAB_140002979;
          }
        }
        else if ((*(char *)(param_1 + 0xeb50) != '\0') &&
                ((*(uint *)(param_1 + 0xeb54) & 0x192) != 0)) {
          uVar12 = 0x192;
LAB_140002979:
          RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),uVar12,
                      (undefined1 *)&local_res20,2,param_3,param_2);
        }
      }
      else {
        cVar3 = StorPortSetDeviceQueueDepth(param_1,CONCAT71(uVar7,1),cVar18,0,uVar4);
        local_res20._0_2_ = CONCAT11((char)uVar4,cVar18);
        if (cVar3 == '\0') {
          if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x194) != 0))
          {
            uVar12 = 0x194;
            goto LAB_140002979;
          }
        }
        else if ((*(char *)(param_1 + 0xeb50) != '\0') &&
                ((*(uint *)(param_1 + 0xeb54) & 0x193) != 0)) {
          uVar12 = 0x193;
          goto LAB_140002979;
        }
      }
LAB_140002981:
      if (*(char *)(param_1 + 0xe1a8) == '\x01') {
        uVar20 = *(uint *)(param_1 + 0xe1ac);
      }
      else {
        bVar9 = *pbVar5;
        if ((char)bVar9 < '\0') {
          uVar20 = uVar10;
        }
        else if ((bVar9 & 0x40) == 0) {
          if ((bVar9 & 0x10) == 0) {
            uVar20 = ((byte)~bVar9 & 4 | 1) << 2;
          }
        }
        else {
          uVar20 = local_60;
        }
      }
      if ((*pbVar5 & 2) != 0) {
        cVar3 = StorPortSetDeviceQueueDepth(param_1,0,cVar18,0,uVar20);
        bVar9 = (byte)uVar20;
        local_68 = cVar18;
        local_67 = bVar9;
        if (cVar3 == '\0') {
          if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x195) != 0))
          {
            RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x195,&local_68,2,param_3
                        ,param_2);
          }
        }
        else {
          if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x191) != 0))
          {
            RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x191,&local_68,2,param_3
                        ,param_2);
          }
          pbVar5[0x100] = bVar9;
        }
      }
      uVar11 = (ulonglong)local_64;
    }
    local_48 = local_48 + 2;
    cVar18 = cVar18 + '\x01';
    pbVar5 = pbVar5 + 1;
    if (cVar18 == -1) {
      return;
    }
  } while( true );
}



===== SetTargetIDBitMaskforTargetProp @ 140002c00 =====

void SetTargetIDBitMaskforTargetProp(longlong param_1,ushort param_2,char param_3)

{
  uint *puVar1;
  byte bVar2;
  byte bVar3;
  
  bVar2 = (byte)(param_2 >> 5);
  bVar3 = bVar2 + 8;
  if (param_3 != '\x01') {
    bVar3 = bVar2;
  }
  puVar1 = (uint *)(param_1 + (ulonglong)bVar3 * 4 + 0xe804);
  *puVar1 = *puVar1 | 1 << ((byte)param_2 & 0x1f);
  return;
}



===== CompleteCTRLPROPQuery @ 140002c40 =====

void CompleteCTRLPROPQuery(longlong param_1,undefined4 param_2,undefined1 param_3)

{
  longlong lVar1;
  undefined1 local_res8;
  byte local_res9;
  byte local_resa;
  
  lVar1 = *(longlong *)(param_1 + 0x188);
  local_res8 = *(undefined1 *)(lVar1 + 0x19);
  *(undefined1 *)(param_1 + 0xd300) = local_res8;
  local_res9 = ~(byte)(*(uint *)(lVar1 + 0x20) >> 10) & 1;
  *(byte *)(param_1 + 0xd301) = local_res9;
  local_resa = *(byte *)(lVar1 + 0x24) >> 4 & 1;
  *(byte *)(param_1 + 0xe472) = local_resa;
  if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x18b) != 0)) {
    RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x18b,&local_res8,3,param_3,
                param_2);
  }
  return;
}



===== CompleteDCMD @ 140002cf0 =====

void CompleteDCMD(longlong param_1,longlong param_2,char param_3,undefined4 param_4,
                 undefined1 param_5)

{
  byte *pbVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  uint *puVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined8 uVar8;
  bool bVar9;
  bool bVar10;
  ushort uVar11;
  ulonglong uVar12;
  byte bVar13;
  byte bVar14;
  uint uVar15;
  int *piVar16;
  undefined4 uVar17;
  bool bVar18;
  undefined4 local_res10;
  short local_res14;
  short local_res16;
  
  uVar15 = *(uint *)(param_2 + 0x18);
  if (*(char *)(param_2 + 2) != '\0') {
    if (uVar15 == 0x1040500) {
      if (*(char *)(param_2 + 2) == '#') {
        *(undefined1 *)(param_1 + 0xd8d2) = 1;
LAB_140002d39:
        *(undefined1 *)(param_1 + 0xd8d0) = 1;
        return;
      }
    }
    else {
      if (uVar15 == 0x2020000) {
        *(undefined1 *)(param_1 + 0xd8e5) = 0;
        uVar12 = 0;
        do {
          bVar13 = 0;
          do {
            if ((*(uint *)(param_1 + 0xe7e4 + uVar12 * 4) >> (bVar13 & 0x1f) & 1) != 0)
            goto LAB_140002d39;
            bVar13 = bVar13 + 1;
          } while (bVar13 < 0x20);
          bVar13 = (char)uVar12 + 1;
          uVar12 = (ulonglong)bVar13;
          if (7 < bVar13) {
            *(undefined1 *)(param_1 + 0xd8e4) = 0;
            return;
          }
        } while( true );
      }
      if (uVar15 == 0x1040300) {
        *(undefined1 *)(param_1 + 0xd306) = 0;
        *(undefined1 *)(param_1 + 0xd8d2) = 1;
        *(undefined1 *)(param_1 + 0xd8d0) = 1;
        return;
      }
      if (uVar15 == 0x200e103) {
        *(undefined1 *)(param_1 + 0xd8e7) = 0;
        uVar12 = 0;
        do {
          bVar13 = 0;
          do {
            if ((*(uint *)(param_1 + 0xe804 + uVar12 * 4) >> (bVar13 & 0x1f) & 1) != 0)
            goto LAB_140002d39;
            bVar13 = bVar13 + 1;
          } while (bVar13 < 0x20);
          bVar13 = (char)uVar12 + 1;
          uVar12 = (ulonglong)bVar13;
          if (0xf < bVar13) {
            *(undefined1 *)(param_1 + 0xd8e6) = 0;
            return;
          }
        } while( true );
      }
      if (uVar15 == 0x1200100) {
        *(undefined1 *)(param_1 + 0xe472) = 0;
        if (*(char *)(param_1 + 0xeb50) == '\0') {
          return;
        }
        if ((*(uint *)(param_1 + 0xeb54) & 0x286) == 0) {
          return;
        }
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x286,(undefined1 *)0x0,0,
                    param_5,param_4);
        return;
      }
      if (((uVar15 == 0x300e101) &&
          (*(undefined1 *)(param_1 + 0xd928) = 0, *(char *)(param_1 + 0xeb50) != '\0')) &&
         ((*(uint *)(param_1 + 0xeb54) & 0x287) != 0)) {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x287,(undefined1 *)0x0,0,
                    param_5,param_4);
      }
    }
    if (*(int *)(param_2 + 0x18) != 0x200e102) {
      return;
    }
    *(undefined1 *)(param_1 + 0xe46c) = 0;
    if (*(char *)(param_1 + 0xeb50) == '\0') {
      return;
    }
    if ((*(uint *)(param_1 + 0xeb54) & 0x288) == 0) {
      return;
    }
    RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x288,(undefined1 *)0x0,0,param_5
                ,param_4);
    return;
  }
  if (0x1200100 < uVar15) {
    if (uVar15 == 0x200e102) {
      *(undefined1 *)(param_1 + 0xd950) = 0;
      if (*(int *)(param_1 + 0xd954) == 0) {
        return;
      }
      *(int *)(param_1 + 0xd954) = *(int *)(param_1 + 0xd954) + 1;
      if (param_3 != '\0') {
        IssueDCMD(param_1,0x200e102,'\0');
        return;
      }
      *(undefined1 *)(param_1 + 0xd8d4) = 1;
LAB_140003a42:
      *(undefined1 *)(param_1 + 0xd8d0) = 1;
      return;
    }
    if (uVar15 == 0x200e103) {
      *(undefined1 *)(param_1 + 0xd8e7) = 0;
      *(undefined4 *)
       ((ulonglong)*(ushort *)(param_1 + 0xe846) * 0x20 + *(longlong *)(param_1 + 0xd988)) =
           **(undefined4 **)(param_1 + 0x1c8);
      *(undefined4 *)
       ((ulonglong)*(ushort *)(param_1 + 0xe846) * 0x20 + 4 + *(longlong *)(param_1 + 0xd988)) =
           *(undefined4 *)(*(longlong *)(param_1 + 0x1c8) + 4);
      local_res14 = **(short **)(param_1 + 0x1c8);
      local_res16 = (*(short **)(param_1 + 0x1c8))[2];
      uVar11 = *(ushort *)(param_1 + 0xe846);
      bVar18 = 0xff < uVar11;
      if (bVar18) {
        uVar11 = uVar11 - 0x100;
      }
      local_res10 = (uint)CONCAT12(bVar18,uVar11);
      if (((local_res14 != 0) && (*(char *)(param_1 + 0xeb50) != '\0')) &&
         ((*(uint *)(param_1 + 0xeb54) & 399) != 0)) {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),399,
                    (undefined1 *)&local_res10,8,param_5,param_4);
      }
      uVar12 = 0;
      do {
        uVar15 = 0;
        do {
          if ((*(uint *)(param_1 + 0xe7e4 + uVar12 * 4) >> (uVar15 & 0x1f) & 1) != 0)
          goto LAB_140003a42;
          bVar13 = (char)uVar15 + 1;
          uVar15 = (uint)bVar13;
        } while (bVar13 < 0x20);
        bVar13 = (char)uVar12 + 1;
        uVar12 = (ulonglong)bVar13;
        if (7 < bVar13) {
          *(undefined1 *)(param_1 + 0xd8e6) = 0;
          return;
        }
      } while( true );
    }
    if (uVar15 == 0x2010100) {
      if (param_3 == '\0') {
        uVar17 = 4;
        if (*(int *)(param_1 + 0xd8d8) != 2) {
          uVar17 = 0;
        }
        *(undefined4 *)(param_1 + 0xd8d8) = uVar17;
        return;
      }
      lVar7 = *(longlong *)(param_1 + 0x160);
      uVar12 = 0;
      *(undefined4 *)(param_1 + 0xd8d8) = 0;
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x18c) != 0)) {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x18c,
                    (undefined1 *)(lVar7 + 4),4,param_5,param_4);
      }
      memset((void *)(param_1 + 0xd40a),0,0x100);
      if (*(int *)(lVar7 + 4) != 0) {
        do {
          uVar11 = *(ushort *)(lVar7 + 8 + uVar12 * 0x18);
          if (uVar11 < 0x100) {
            if (*(char *)(lVar7 + 0xe + uVar12 * 0x18) == '\0') {
              *(undefined1 *)((ulonglong)uVar11 + 0xd60a + param_1) = 1;
            }
            *(undefined1 *)((ulonglong)uVar11 + 0xd40a + param_1) = 1;
          }
          uVar15 = (int)uVar12 + 1;
          uVar12 = (ulonglong)uVar15;
        } while (uVar15 < *(uint *)(lVar7 + 4));
      }
      memmove((void *)(param_1 + 0xd30a),(void *)(param_1 + 0xd40a),0x100);
      memmove((void *)(param_1 + 0xd50a),(void *)(param_1 + 0xd60a),0x100);
      *(undefined1 *)(param_1 + 0xd304) = 1;
      if (*(char *)(param_1 + 0xd8dc) == '\0') {
        memset((void *)(param_1 + 0xe1b0),0,0x100);
        StorPortNotification(7,param_1);
        return;
      }
      *(undefined1 *)(param_1 + 0xd8dc) = 0;
      *(undefined4 *)(param_1 + 0xd8d8) = 1;
      *(undefined1 *)(param_1 + 0xd8d0) = 1;
      return;
    }
    if (uVar15 != 0x2020000) {
      if (uVar15 != 0x300e101) {
        return;
      }
      iVar4 = *(int *)(param_1 + 0xd92c);
      *(undefined1 *)(param_1 + 0xd929) = 0;
      uVar12 = MegaSASValidateAndProcessMapInfo(param_1,param_4,param_5);
      if ((char)uVar12 != '\0') {
        if (iVar4 == 0) {
          return;
        }
        *(int *)(param_1 + 0xd92c) = *(int *)(param_1 + 0xd92c) + 1;
        if (param_3 == '\0') {
          *(undefined1 *)(param_1 + 0xd8d3) = 1;
          *(undefined1 *)(param_1 + 0xd8d0) = 1;
          return;
        }
        IssueDCMD(param_1,0x300e101,'\0');
        *(undefined1 *)(param_1 + 0xd8d0) = 1;
        return;
      }
      *(undefined1 *)(param_1 + 0xd928) = 0;
      *(undefined1 *)(param_1 + 0xd912) = 1;
      if (*(char *)(param_1 + 0xeb50) == '\0') {
        return;
      }
      if ((*(uint *)(param_1 + 0xeb54) & 0x289) == 0) {
        return;
      }
      RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x289,(undefined1 *)0x0,0,
                  param_5,param_4);
      return;
    }
    *(undefined1 *)(param_1 + 0xd8e5) = 0;
    cVar2 = *(char *)(*(longlong *)(param_1 + 0x1b8) + 0x191);
    uVar12 = (ulonglong)*(byte *)(param_1 + 0xe844);
    if (cVar2 == '\x02') {
      pbVar1 = (byte *)(uVar12 + 0xe1b0 + param_1);
      *pbVar1 = *pbVar1 | 0x40;
    }
    else if (cVar2 == '\x03') {
      pbVar1 = (byte *)(uVar12 + 0xe1b0 + param_1);
      *pbVar1 = *pbVar1 | 0x80;
    }
    else {
      lVar7 = uVar12 + param_1;
      if (cVar2 == '\x05') {
        *(byte *)(lVar7 + 0xe1b0) = *(byte *)(lVar7 + 0xe1b0) | 0x10;
        SetTargetIDBitMaskforTargetProp(param_1,(ushort)*(byte *)(param_1 + 0xe844),'\0');
        *(undefined1 *)(param_1 + 0xd8e6) = 1;
        *(undefined1 *)(param_1 + 0xd8d0) = 1;
      }
      else {
        *(byte *)(lVar7 + 0xe1b0) = *(byte *)(lVar7 + 0xe1b0) | 0x20;
      }
    }
    uVar12 = 0;
    do {
      uVar15 = 0;
      do {
        if ((*(uint *)(param_1 + 0xe7e4 + uVar12 * 4) >> (uVar15 & 0x1f) & 1) != 0)
        goto LAB_140003a42;
        bVar13 = (char)uVar15 + 1;
        uVar15 = (uint)bVar13;
      } while (bVar13 < 0x20);
      bVar13 = (char)uVar12 + 1;
      uVar12 = (ulonglong)bVar13;
      if (7 < bVar13) {
        *(undefined1 *)(param_1 + 0xd8e4) = 0;
        return;
      }
    } while( true );
  }
  if (uVar15 == 0x1200100) {
    if (param_3 == '\0') {
      uVar17 = 0;
      if (*(int *)(param_1 + 0xd8ec) == 2) {
        uVar17 = 4;
      }
      *(undefined4 *)(param_1 + 0xd8ec) = uVar17;
      return;
    }
    bVar13 = *(byte *)(*(longlong *)(param_1 + 0x1d8) + 3);
    if (0x3c < bVar13) {
      bVar13 = 0x3c;
    }
    *(byte *)(param_1 + 0xe471) = bVar13;
    return;
  }
  if (uVar15 == 0x1020100) {
    if (param_3 == '\0') {
      uVar17 = 4;
      if (*(int *)(param_1 + 0xd8e0) != 2) {
        uVar17 = 0;
      }
      *(undefined4 *)(param_1 + 0xd8e0) = uVar17;
      return;
    }
    lVar7 = *(longlong *)(param_1 + 0x188);
    *(undefined4 *)(param_1 + 0xd8e0) = 0;
    uVar3 = *(undefined1 *)(lVar7 + 0x19);
    *(undefined1 *)(param_1 + 0xd300) = uVar3;
    bVar14 = ~(byte)(*(uint *)(lVar7 + 0x20) >> 10);
    *(byte *)(param_1 + 0xd301) = bVar14 & 1;
    bVar13 = *(byte *)(lVar7 + 0x24) >> 4;
    *(byte *)(param_1 + 0xe472) = bVar13 & 1;
    local_res10 = CONCAT22(local_res10._2_2_,CONCAT11(bVar14,uVar3)) & 0xffff01ff;
    local_res10 = CONCAT13(local_res10._3_1_,CONCAT12(bVar13,(undefined2)local_res10)) & 0xff01ffff;
    if (*(char *)(param_1 + 0xeb50) == '\0') {
      return;
    }
    if ((*(uint *)(param_1 + 0xeb54) & 0x18b) == 0) {
      return;
    }
    RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x18b,(undefined1 *)&local_res10,
                3,param_5,param_4);
    return;
  }
  if (uVar15 == 0x1040100) {
    puVar6 = *(undefined8 **)(param_1 + 0x1e8);
    uVar8 = puVar6[1];
    *(undefined8 *)(param_1 + 0xd2ec) = *puVar6;
    *(undefined8 *)(param_1 + 0xd2f4) = uVar8;
    *(undefined4 *)(param_1 + 0xd2fc) = *(undefined4 *)(puVar6 + 2);
    return;
  }
  if (uVar15 == 0x1040300) {
    bVar18 = false;
    piVar16 = (int *)(*(longlong *)(param_1 + 0x1a8) + 8);
    local_res10 = local_res10 & 0xffffff00;
    bVar9 = false;
    bVar10 = false;
    iVar4 = *piVar16;
    while (iVar4 != 0) {
      if ((byte)(*(char *)((longlong)piVar16 + 0xf) - 2U) < 3) {
        cVar2 = *(char *)(param_1 + 0xe8d8);
        if (cVar2 == '\x01') {
          uVar17 = 0x4004af00;
        }
        else {
          uVar17 = 0x8004af01;
          if ((cVar2 != '\x02') && (uVar17 = 0x8004af01, cVar2 == '\x03')) {
            uVar17 = 0xc004af02;
          }
        }
        LogSystemEvent(param_1,piVar16[2],uVar17,4,(char *)(piVar16 + 0x20));
      }
      uVar15 = piVar16[2];
      if (0xfc < uVar15) {
        switch(uVar15) {
        case 0x12f:
          bVar10 = true;
          break;
        case 0x152:
switchD_1400033a2_caseD_4:
          bVar9 = true;
          bVar18 = true;
          break;
        case 0x15a:
        case 0x15f:
        case 0x160:
          goto switchD_1400033a2_caseD_51;
        case 0x17e:
          ProcessPerfMetricAEN(param_1,*(char *)((longlong)piVar16 + 0xaa) + -0x30);
        }
        goto switchD_1400033a2_caseD_5;
      }
      if (uVar15 == 0xfc) {
switchD_1400033a2_caseD_51:
        bVar9 = true;
      }
      else {
        switch(uVar15) {
        case 4:
          goto switchD_1400033a2_caseD_4;
        case 0x51:
        case 0x8a:
        case 0x8b:
          goto switchD_1400033a2_caseD_51;
        case 0x5b:
        case 0x70:
        case 0x72:
          local_res10 = CONCAT31(local_res10._1_3_,1);
        }
      }
switchD_1400033a2_caseD_5:
      iVar4 = *piVar16;
      piVar16 = piVar16 + 0x40;
      *(int *)(param_1 + 0xd2ec) = iVar4;
      iVar4 = *piVar16;
    }
    memset((void *)(param_1 + 0xe1b0),0,0x100);
    if (bVar18) {
      StorPortNotification(7,param_1);
    }
    if (bVar9) {
      StorPortNotification(7,param_1,1);
    }
    if ((char)local_res10 != '\0') {
      if (*(int *)(param_1 + 0xd8d8) == 0) {
        *(undefined4 *)(param_1 + 0xd8d8) = 1;
      }
      else {
        *(undefined1 *)(param_1 + 0xd8dc) = 1;
      }
    }
    if ((bVar10) && (*(int *)(param_1 + 0xd8e0) == 0)) {
      *(undefined4 *)(param_1 + 0xd8e0) = 1;
    }
    *(undefined1 *)(param_1 + 0xd306) = 0;
    *(undefined1 *)(param_1 + 0xd8d2) = 1;
LAB_14000315e:
    *(undefined1 *)(param_1 + 0xd8d0) = 1;
    return;
  }
  if (uVar15 != 0x1040500) {
    if (uVar15 == 0x10f0300) {
      *(undefined1 *)(param_1 + 0xe8af) = 0;
      return;
    }
    return;
  }
  puVar5 = *(uint **)(param_1 + 0x170);
  local_res10 = 0;
  *(uint *)(param_1 + 0xd2ec) = *puVar5;
  memmove(&local_res10,puVar5 + 3,4);
  if (*(char *)(param_1 + 0xd758) != '\0') {
    *(undefined4 *)(param_1 + 0xd79c) = *(undefined4 *)(param_1 + 0x74);
    *(uint *)(param_1 + 0xd7a0) = local_res10;
    *(uint *)(param_1 + 0xd7a4) = *puVar5;
    *(uint *)(param_1 + 0xd7a8) = puVar5[2];
    ScsiPortWmiFireLogicalUnitEvent
              (param_1,-1,0,0,(int *)&MegaSASWmiSetupDataGuid,0,0x10,(int *)(param_1 + 0xd75c));
  }
  if ((byte)(local_res10._3_1_ - 2U) < 3) {
    cVar2 = *(char *)(param_1 + 0xe8d8);
    if (cVar2 == '\x01') {
      uVar17 = 0x4004af00;
    }
    else {
      uVar17 = 0x8004af01;
      if ((cVar2 != '\x02') && (uVar17 = 0x8004af01, cVar2 == '\x03')) {
        uVar17 = 0xc004af02;
      }
    }
    LogSystemEvent(param_1,puVar5[2],uVar17,4,(char *)(puVar5 + 0x20));
  }
  *(undefined1 *)(param_1 + 0xd306) = 0;
  *(undefined1 *)(param_1 + 0xd8e8) = 1;
  *(undefined1 *)(param_1 + 0xd8d0) = 1;
  if (*puVar5 < *(uint *)(param_1 + 0xd2fc)) {
    return;
  }
  uVar15 = puVar5[2];
  if (uVar15 < 0xfd) {
    if (uVar15 != 0xfc) {
      switch(uVar15) {
      case 4:
        goto switchD_1400030f9_caseD_4;
      default:
        goto LAB_14000317a;
      case 0x51:
      case 0x8a:
      case 0x8b:
        break;
      case 0x5b:
      case 0x70:
      case 0x72:
        if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x189) != 0)) {
          RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x189,(undefined1 *)0x0,0,
                      param_5,param_4);
        }
        if (*(int *)(param_1 + 0xd8d8) != 0) {
          *(undefined1 *)(param_1 + 0xd8dc) = 1;
          return;
        }
        *(undefined4 *)(param_1 + 0xd8d8) = 1;
        goto LAB_14000315e;
      }
    }
switchD_1400030f9_caseD_51:
    if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x18a) != 0)) {
      RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x18a,(undefined1 *)0x0,0,
                  param_5,param_4);
    }
    memset((void *)(param_1 + 0xe1b0),0,0x100);
    StorPortNotification(7,param_1);
  }
  else {
    switch(uVar15) {
    case 0x12f:
      if (*(int *)(param_1 + 0xd8e0) == 0) {
        *(undefined4 *)(param_1 + 0xd8e0) = 1;
      }
      break;
    case 0x152:
switchD_1400030f9_caseD_4:
      memset((void *)(param_1 + 0xe1b0),0,0x100);
      StorPortNotification(7,param_1);
      StorPortNotification(7,param_1);
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x188) != 0)) {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x188,(undefined1 *)0x0,0,
                    param_5,param_4);
      }
      break;
    case 0x15a:
    case 0x15f:
    case 0x160:
      goto switchD_1400030f9_caseD_51;
    case 0x17e:
      ProcessPerfMetricAEN(param_1,*(char *)((longlong)puVar5 + 0xaa) + -0x30);
    }
  }
LAB_14000317a:
  return;
}



===== CompleteIoctlRequest @ 140003c50 =====

undefined8
CompleteIoctlRequest
          (longlong param_1,longlong *param_2,uint param_3,undefined4 param_4,undefined1 param_5)

{
  int *piVar1;
  char cVar2;
  byte bVar3;
  longlong lVar4;
  undefined8 uVar5;
  longlong lVar6;
  char local_res8;
  byte local_res9;
  byte local_resa;
  
  lVar4 = *param_2;
  local_res8 = *(char *)((longlong)param_2 + 0x102);
  lVar6 = *(longlong *)(lVar4 + 0x18);
  if ((*(char *)(lVar6 + 0x1c) == '\x05') && (*(int *)(lVar6 + 0x34) == 0x200e100)) {
    DoResumeInput(param_1,param_4,param_5);
  }
  if (local_res8 == '\0') {
    if (*(int *)(lVar6 + 0x34) == 0x1020200) {
      cVar2 = *(char *)(lVar6 + 0xd5);
      local_res8 = *(char *)(param_1 + 0xd300);
      if (((cVar2 != *(char *)(param_1 + 0xd300)) &&
          (*(char *)(param_1 + 0xd300) = cVar2, local_res8 = cVar2,
          *(char *)(param_1 + 0xd304) != '\0')) && (*(int *)(param_1 + 0xd8d8) == 0)) {
        *(undefined4 *)(param_1 + 0xd8d8) = 1;
        *(undefined1 *)(param_1 + 0xd8d0) = 1;
      }
      local_res9 = ~(byte)(*(uint *)(lVar6 + 0xdc) >> 10) & 1;
      *(byte *)(param_1 + 0xd301) = local_res9;
      local_resa = *(byte *)(lVar6 + 0xe0) >> 4 & 1;
      *(byte *)(param_1 + 0xe472) = local_resa;
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x18d) != 0)) {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x18d,&local_res8,3,param_5,
                    param_4);
      }
    }
    else if (*(int *)(lVar6 + 0x34) == 0x1170200) {
      ProcessPerfMetricRequest(param_1,(uint *)(lVar6 + 0xbc),*(int *)(lVar4 + 0x10) - 0xbd);
    }
  }
  memmove((void *)(lVar6 + 0x1c),param_2 + 0x20,0x18);
  *(undefined1 *)(lVar4 + 3) = 1;
  *(undefined8 *)(*(longlong *)(param_1 + 0x208) + (ulonglong)param_3 * 8) = 0;
  lVar6 = (ulonglong)*(byte *)((longlong)param_2 + 0xc6) * 0x240;
  bVar3 = *(byte *)(lVar6 + 0x440 + param_1);
  *(byte *)(lVar6 + 0x440 + param_1) = bVar3 + 1;
  *(short *)(param_1 +
            (((ulonglong)*(byte *)((longlong)param_2 + 0xc6) + 1) * 0x120 + (ulonglong)bVar3) * 2) =
       (short)param_3;
  lVar6 = 0x92e0;
  if (*(char *)((longlong)param_2 + 9) != '\0') {
    lVar6 = 0xb2e0;
  }
  LOCK();
  piVar1 = (int *)((ulonglong)*(byte *)(param_2 + 1) * 0x20 + lVar6 + param_1);
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (((char)param_2[0x12] != '\0') && ((char)param_2[0x20] == '\x05')) {
    LOCK();
    *(int *)(param_1 + 0x92c0) = *(int *)(param_1 + 0x92c0) + -1;
    UNLOCK();
  }
  uVar5 = StorPortNotification(0,param_1,lVar4);
  return CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
}



===== CompletePDquery @ 140003e90 =====

void CompletePDquery(longlong param_1,undefined4 param_2,undefined1 param_3)

{
  ushort uVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x160);
  if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x18c) != 0)) {
    RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x18c,(undefined1 *)(lVar2 + 4),4
                ,param_3,param_2);
  }
  memset((void *)(param_1 + 0xd40a),0,0x100);
  uVar4 = 0;
  if (*(int *)(lVar2 + 4) != 0) {
    do {
      uVar1 = *(ushort *)(lVar2 + 8 + uVar4 * 0x18);
      if (uVar1 < 0x100) {
        if (*(char *)(lVar2 + 0xe + uVar4 * 0x18) == '\0') {
          *(undefined1 *)((ulonglong)uVar1 + 0xd60a + param_1) = 1;
        }
        *(undefined1 *)((ulonglong)uVar1 + 0xd40a + param_1) = 1;
      }
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 < *(uint *)(lVar2 + 4));
  }
  memmove((void *)(param_1 + 0xd30a),(void *)(param_1 + 0xd40a),0x100);
  memmove((void *)(param_1 + 0xd50a),(void *)(param_1 + 0xd60a),0x100);
  *(undefined1 *)(param_1 + 0xd304) = 1;
  if (*(char *)(param_1 + 0xd8dc) == '\0') {
    memset((void *)(param_1 + 0xe1b0),0,0x100);
    StorPortNotification(7,param_1);
  }
  else {
    *(undefined4 *)(param_1 + 0xd8d8) = 1;
    *(undefined1 *)(param_1 + 0xd8dc) = 0;
    *(undefined1 *)(param_1 + 0xd8d0) = 1;
  }
  return;
}



===== IssueDCMD @ 140003fe0 =====

void IssueDCMD(longlong param_1,uint param_2,char param_3)

{
  void *pvVar1;
  ushort uVar2;
  void *pvVar3;
  undefined4 uStackX_c;
  
  pvVar1 = SetupDCMD(param_1,param_2,param_3);
  uVar2 = *(short *)((longlong)pvVar1 + 0x14) + 1;
  pvVar3 = (void *)(*(longlong *)(param_1 + 0xd998) + (ulonglong)uVar2 * 0x100);
  if (*(char *)(param_1 + 0xe46e) == '\0') {
    MPT_BuildPassthrough(param_1,pvVar3,*(undefined8 *)((longlong)pvVar1 + 0x20));
    *(ulonglong *)(*(longlong *)(param_1 + 0x80) + 0xc0) =
         (ulonglong)CONCAT42(uStackX_c,uVar2) << 0x10;
    LOCK();
    UNLOCK();
    return;
  }
  MPT_BuildPassthrough(param_1,pvVar3,*(undefined8 *)((longlong)pvVar1 + 0x20));
  *(uint *)(*(longlong *)(param_1 + 0x80) + 200) = (uint)uVar2 << 0x10;
  LOCK();
  UNLOCK();
  return;
}



===== LogSystemEvent @ 140004080 =====

void LogSystemEvent(longlong param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
                   char *param_5)

{
  longlong lVar1;
  undefined4 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  short sVar6;
  
  if (*(char *)(param_1 + 0x89) == '\0') {
    lVar1 = *(longlong *)(param_1 + 0xe8e0);
    uVar4 = 0;
    puVar2 = *(undefined4 **)(lVar1 + 0x10);
    puVar2[1] = param_3;
    *puVar2 = param_2;
    sVar6 = (short)*param_5;
    *(short *)(puVar2 + 4) = sVar6;
    while (sVar6 != 0) {
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
      if (uVar3 == 0x48) {
        *(undefined2 *)(puVar2 + 0x28) = 0;
        break;
      }
      sVar6 = (short)param_5[uVar4];
      *(short *)((longlong)puVar2 + uVar4 * 2 + 0x10) = sVar6;
    }
    *(char *)(puVar2 + 2) = (char)uVar4;
    lVar5 = IncrementWithWrap(param_1,*(ulonglong *)(lVar1 + 0x10));
    *(longlong *)(lVar1 + 0x10) = lVar5;
    if (lVar5 == *(longlong *)(lVar1 + 0x18)) {
      *(undefined1 *)(lVar1 + 0x20) = 1;
      return;
    }
    *(undefined1 *)(param_1 + 0xd8d1) = 1;
  }
  return;
}



===== PrepareAbortFrame @ 140004130 =====

void PrepareAbortFrame(longlong param_1,int param_2)

{
  undefined4 uVar1;
  void *_Dst;
  longlong lVar2;
  
  _Dst = *(void **)(param_1 + 0xb0);
  lVar2 = *(longlong *)(param_1 + 0xb0 + (ulonglong)(param_2 - 1) * 8);
  memset(_Dst,0,0x600);
  *(undefined8 *)((longlong)_Dst + 0x20) = *(undefined8 *)(param_1 + 0x108);
  *(int *)((longlong)_Dst + 0x14) = *(int *)(param_1 + 0xd7fc) + -1;
  *(undefined1 *)((longlong)_Dst + 0x100) = 6;
  uVar1 = *(undefined4 *)(lVar2 + 0x14);
  *(ushort *)((longlong)_Dst + 0x110) = *(ushort *)((longlong)_Dst + 0x110) | 1;
  *(undefined4 *)((longlong)_Dst + 0x118) = uVar1;
  *(undefined1 *)((longlong)_Dst + 0x102) = 0xff;
  *(undefined4 *)((longlong)_Dst + 0x108) = *(undefined4 *)((longlong)_Dst + 0x14);
  *(undefined8 *)((longlong)_Dst + 0x120) = *(undefined8 *)(lVar2 + 0x20);
  *(undefined4 *)(param_1 + 0xd918) = 180000000;
  return;
}



===== SendAndWaitDCMD @ 1400041d0 =====

ulonglong SendAndWaitDCMD(longlong param_1,uint param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  ushort uVar3;
  uint uVar4;
  void *pvVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  void *pvVar8;
  undefined4 uStackX_c;
  
  pvVar5 = SetupDCMD(param_1,param_2,'\0');
  iVar2 = *(int *)((longlong)pvVar5 + 0x118);
  if ((iVar2 != 0x1101000) && (iVar2 != 0x1060000)) {
    LOCK();
    *(int *)(param_1 + 0x92c4) = *(int *)(param_1 + 0x92c4) + 1;
    UNLOCK();
  }
  *(ushort *)((longlong)pvVar5 + 0x110) = *(ushort *)((longlong)pvVar5 + 0x110) | 1;
  *(undefined2 *)((longlong)pvVar5 + 0x112) = 0xb4;
  uVar3 = *(short *)((longlong)pvVar5 + 0x14) + 1;
  pvVar8 = (void *)(*(longlong *)(param_1 + 0xd998) + (ulonglong)uVar3 * 0x100);
  if (*(char *)(param_1 + 0xe46e) == '\0') {
    MPT_BuildPassthrough(param_1,pvVar8,*(undefined8 *)((longlong)pvVar5 + 0x20));
    *(ulonglong *)(*(longlong *)(param_1 + 0x80) + 0xc0) =
         (ulonglong)CONCAT42(uStackX_c,uVar3) << 0x10;
  }
  else {
    MPT_BuildPassthrough(param_1,pvVar8,*(undefined8 *)((longlong)pvVar5 + 0x20));
    *(uint *)(*(longlong *)(param_1 + 0x80) + 200) = (uint)uVar3 << 0x10;
  }
  LOCK();
  UNLOCK();
  cVar1 = *(char *)((longlong)pvVar5 + 0x102);
  while (cVar1 == -1) {
    uVar4 = Fusion_ReadRegister(param_1,*(longlong *)(param_1 + 0x80));
    *(uint *)(param_1 + 0xd2e0) = uVar4;
    uVar6 = (ulonglong)(uVar4 & 0xf0000000);
    if (((uVar4 & 0xf0000000) == 0xf0000000) || (*(int *)(param_1 + 0xd918) < 1))
    goto LAB_1400042fd;
    StorPortStallExecution(1000);
    *(int *)(param_1 + 0xd918) = *(int *)(param_1 + 0xd918) + -1000;
    cVar1 = *(char *)((longlong)pvVar5 + 0x102);
  }
  uVar6 = 0;
  if (cVar1 == '\0') {
    uVar7 = CompleteDCMD(param_1,(longlong)pvVar5 + 0x100,'\x01',param_3,0);
    uVar6 = CONCAT71((int7)((ulonglong)uVar7 >> 8),1);
  }
  else {
LAB_1400042fd:
    if ((*(char *)(param_1 + 0xeb50) != '\0') &&
       (uVar6 = (ulonglong)*(uint *)(param_1 + 0xeb54), (*(uint *)(param_1 + 0xeb54) & 0x2aa) != 0))
    {
      uVar6 = RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x2aa,
                          (undefined1 *)((longlong)pvVar5 + 0x118),4,0,param_3);
    }
    uVar6 = uVar6 & 0xffffffffffffff00;
  }
  return uVar6;
}



===== SetupDCMD @ 140004380 =====

void * SetupDCMD(longlong param_1,uint param_2,char param_3)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  void *_Dst;
  undefined8 *puVar4;
  ushort *_Dst_00;
  longlong lVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  undefined1 uVar9;
  
  uVar6 = 0;
  uVar8 = 0;
  if (param_2 == 0x2010100) {
    iVar7 = 4;
  }
  else if (param_2 == 0x300e101) {
    iVar7 = 3;
  }
  else if (param_2 == 0x1040500) {
    iVar7 = 2;
  }
  else if (param_2 == 0x1040300) {
    iVar7 = 10;
  }
  else if (param_2 == 0x200e102) {
    iVar7 = 6;
  }
  else if (param_2 == 0x1020100) {
    iVar7 = 5;
  }
  else if (param_2 == 0x2020000) {
    iVar7 = 7;
  }
  else if (param_2 == 0x200e103) {
    iVar7 = 9;
  }
  else {
    iVar7 = 1;
    if (param_2 == 0x1200100) {
      iVar7 = 0xb;
    }
  }
  _Dst = *(void **)(param_1 + 0xb0 + (ulonglong)(iVar7 - 1U) * 8);
  memset(_Dst,0,0x600);
  *(undefined8 *)((longlong)_Dst + 0x20) =
       *(undefined8 *)(param_1 + 0x108 + (ulonglong)(iVar7 - 1U) * 8);
  *(int *)((longlong)_Dst + 0x14) = *(int *)(param_1 + 0xd7fc) - iVar7;
  *(undefined1 *)((longlong)_Dst + 0x100) = 5;
  *(uint *)((longlong)_Dst + 0x118) = param_2;
  *(undefined1 *)((longlong)_Dst + 0x102) = 0xff;
  *(undefined4 *)((longlong)_Dst + 0x108) = *(undefined4 *)((longlong)_Dst + 0x14);
  if (param_2 < 0x1101001) {
    if (param_2 == 0x1101000) {
      *(undefined1 *)((longlong)_Dst + 0x11c) = 3;
      goto LAB_14000494d;
    }
    if (param_2 < 0x1040501) {
      if (param_2 == 0x1040500) {
        uVar8 = *(undefined8 *)(param_1 + 0x178);
        uVar6 = 0x100;
        memset(*(void **)(param_1 + 0x170),0,0x100);
        if (*(char *)(param_1 + 0xd305) == '\0') {
          iVar7 = *(int *)(param_1 + 0xd2ec) + 1;
        }
        else {
          iVar7 = *(int *)(param_1 + 0xd2f8);
        }
        *(int *)((longlong)_Dst + 0x11c) = iVar7;
        *(undefined4 *)((longlong)_Dst + 0x120) = *(undefined4 *)(param_1 + 0xd7ac);
        *(undefined1 *)(param_1 + 0xd306) = 1;
      }
      else if (param_2 == 0x1010000) {
        uVar6 = 0x990;
        uVar8 = *(undefined8 *)(param_1 + 0x1a0);
        memset(*(void **)(param_1 + 0x198),0,0x990);
        *(undefined1 *)((longlong)_Dst + 0x11c) = 1;
      }
      else {
        if (param_2 != 0x1020100) {
          if (param_2 == 0x1040300) {
            uVar8 = *(undefined8 *)(param_1 + 0x1b0);
            uVar6 = (uint)*(byte *)(param_1 + 0x180) * 0x100 + 0x108;
            memset(*(void **)(param_1 + 0x1a8),0,(ulonglong)uVar6);
            if (*(char *)(param_1 + 0xd305) == '\0') {
              iVar7 = *(int *)(param_1 + 0xd2ec) + 1;
            }
            else {
              iVar7 = *(int *)(param_1 + 0xd2f8);
            }
            *(int *)((longlong)_Dst + 0x11c) = iVar7;
            *(undefined4 *)((longlong)_Dst + 0x120) = *(undefined4 *)(param_1 + 0xd7ac);
            *(undefined2 *)((longlong)_Dst + 0x124) = 0;
            *(undefined1 *)(param_1 + 0xd306) = 1;
            goto LAB_14000489e;
          }
          goto LAB_1400047ee;
        }
        puVar4 = *(undefined8 **)(param_1 + 0x188);
        uVar8 = *(undefined8 *)(param_1 + 400);
        uVar6 = 0x40;
        *puVar4 = 0;
        puVar4[1] = 0;
        puVar4[2] = 0;
        puVar4[3] = 0;
        puVar4[4] = 0;
        puVar4[5] = 0;
        puVar4[6] = 0;
        puVar4[7] = 0;
      }
    }
    else {
      if (param_2 == 0x1050000) {
        *(undefined1 *)((longlong)_Dst + 0x11c) = 1;
        goto LAB_14000494d;
      }
      if (param_2 == 0x1060000) goto LAB_1400048a2;
      if (param_2 == 0x10f0300) {
        if (*(char *)((longlong)_Dst + 0x11c) == '\x01') {
          *(undefined1 *)(param_1 + 0xe8af) = 1;
        }
        goto LAB_14000494d;
      }
LAB_1400047ee:
      uVar6 = 0x800;
      uVar8 = *(undefined8 *)(param_1 + 0x1f0);
      memset(*(void **)(param_1 + 0x1e8),0,0x800);
    }
  }
  else if (param_2 < 0x200e104) {
    if (param_2 == 0x200e103) {
      uVar6 = 0x200;
      uVar8 = *(undefined8 *)(param_1 + 0x1d0);
      memset(*(void **)(param_1 + 0x1c8),0,0x200);
      if (param_3 == '\x01') {
        *(undefined1 *)((longlong)_Dst + 0x11c) = 0;
        *(undefined2 *)((longlong)_Dst + 0x11e) = *(undefined2 *)(param_1 + 0xe846);
        *(undefined1 *)(param_1 + 0xd8e7) = 1;
      }
      else {
        if (param_3 == '\x02') {
          *(undefined1 *)((longlong)_Dst + 0x11c) = 1;
          *(short *)((longlong)_Dst + 0x11e) = *(short *)(param_1 + 0xe846) + -0x100;
        }
        *(undefined1 *)(param_1 + 0xd8e7) = 1;
      }
    }
    else if (param_2 == 0x1200100) {
      puVar4 = *(undefined8 **)(param_1 + 0x1d8);
      uVar8 = *(undefined8 *)(param_1 + 0x1e0);
      uVar6 = 0x10;
      *puVar4 = 0;
      puVar4[1] = 0;
    }
    else {
      if (param_2 == 0x1200500) {
        uVar6 = *(uint *)(param_1 + 0xeb48);
        uVar2 = *(undefined4 *)(param_1 + 0xeb5c);
        *(undefined4 *)((longlong)_Dst + 0x11c) = *(undefined4 *)(param_1 + 0xeb58);
        *(undefined4 *)((longlong)_Dst + 0x120) = uVar2;
        *(uint *)((longlong)_Dst + 0x124) = (uVar6 & 0x1fffffff) >> 2;
        goto LAB_14000489e;
      }
      if (param_2 != 0x200e102) goto LAB_1400047ee;
      uVar6 = *(uint *)(param_1 + 0xd954);
      if (uVar6 == 0) {
        puVar4 = *(undefined8 **)(param_1 + 0xd958);
        uVar8 = *(undefined8 *)(param_1 + 0xd968);
        *puVar4 = 0;
        puVar4[1] = 0;
      }
      else {
        puVar4 = *(undefined8 **)(param_1 + 0xd958 + (ulonglong)(uVar6 & 1) * 8);
        *puVar4 = 0;
        puVar4[1] = 0;
        uVar8 = *(undefined8 *)(param_1 + 0xd968 + (ulonglong)(uVar6 & 1) * 8);
      }
      *(bool *)((longlong)_Dst + 0x11c) = uVar6 != 0;
      uVar6 = 0x800;
      *(undefined1 *)(param_1 + 0xd950) = 1;
    }
  }
  else if (param_2 == 0x2010100) {
    uVar6 = 0x1808;
    uVar8 = *(undefined8 *)(param_1 + 0x168);
    memset(*(void **)(param_1 + 0x160),0,0x1808);
    *(undefined1 *)((longlong)_Dst + 0x11c) = 5;
  }
  else if (param_2 == 0x2020000) {
    uVar6 = 0x200;
    uVar8 = *(undefined8 *)(param_1 + 0x1c0);
    memset(*(void **)(param_1 + 0x1b8),0,0x200);
    *(undefined1 *)((longlong)_Dst + 0x11c) = *(undefined1 *)(param_1 + 0xe844);
    *(undefined1 *)(param_1 + 0xd8e5) = 1;
  }
  else {
    if (param_2 != 0x300e101) goto LAB_1400047ee;
    uVar3 = *(uint *)(param_1 + 0xd92c);
    uVar9 = 0;
    if (uVar3 == 0) {
      uVar8 = *(undefined8 *)(param_1 + 0xd940);
      memset(*(void **)(param_1 + 0xd930),0,0xa0);
    }
    else {
      _Dst_00 = *(ushort **)(param_1 + 0xd930 + (ulonglong)(uVar3 & 1) * 8);
      lVar5 = *(longlong *)(param_1 + 0xd930 + (ulonglong)(uVar3 - 1 & 1) * 8);
      memset(_Dst_00,0,(ulonglong)*(uint *)(param_1 + 0xd800));
      MegaSASPrepareSyncInfo(param_1,lVar5,_Dst_00);
      uVar9 = *(undefined1 *)(lVar5 + 0x2c);
      uVar8 = *(undefined8 *)(param_1 + 0xd940 + (ulonglong)(uVar3 & 1) * 8);
    }
    uVar6 = *(uint *)(param_1 + 0xd800);
    *(undefined1 *)((longlong)_Dst + 0x11c) = uVar9;
    *(bool *)((longlong)_Dst + 0x11d) = uVar3 != 0;
    *(undefined1 *)(param_1 + 0xd929) = 1;
LAB_14000489e:
    if (uVar6 == 0) {
LAB_1400048a2:
      if (param_2 != 0x300e103) goto LAB_14000494d;
    }
  }
  cVar1 = *(char *)(param_1 + 0xd92a);
  *(int *)((longlong)_Dst + 0x128) = (int)uVar8;
  if (cVar1 == '\0') {
    *(uint *)((longlong)_Dst + 300) = uVar6;
  }
  else {
    *(int *)((longlong)_Dst + 300) = (int)((ulonglong)uVar8 >> 0x20);
    *(uint *)((longlong)_Dst + 0x130) = uVar6;
    *(ushort *)((longlong)_Dst + 0x110) = *(ushort *)((longlong)_Dst + 0x110) | 2;
  }
  *(undefined1 *)((longlong)_Dst + 0x107) = 1;
  *(uint *)((longlong)_Dst + 0x114) = uVar6;
LAB_14000494d:
  *(void **)(*(longlong *)(param_1 + 0x208) + (ulonglong)*(uint *)((longlong)_Dst + 0x14) * 8) =
       _Dst;
  return _Dst;
}



===== WDTSetupAndSendDCMD @ 140004980 =====

void WDTSetupAndSendDCMD(longlong param_1,uint param_2)

{
  ushort uVar1;
  void *pvVar2;
  void *pvVar3;
  undefined4 uStackX_c;
  
  pvVar2 = SetupDCMD(param_1,param_2,'\0');
  if ((*(int *)((longlong)pvVar2 + 0x118) != 0x1101000) &&
     (*(int *)((longlong)pvVar2 + 0x118) != 0x1060000)) {
    LOCK();
    *(int *)(param_1 + 0x92c4) = *(int *)(param_1 + 0x92c4) + 1;
    UNLOCK();
  }
  *(ushort *)((longlong)pvVar2 + 0x110) = *(ushort *)((longlong)pvVar2 + 0x110) | 1;
  *(undefined2 *)((longlong)pvVar2 + 0x112) = 0xb4;
  uVar1 = *(short *)((longlong)pvVar2 + 0x14) + 1;
  pvVar3 = (void *)(*(longlong *)(param_1 + 0xd998) + (ulonglong)uVar1 * 0x100);
  if (*(char *)(param_1 + 0xe46e) == '\0') {
    MPT_BuildPassthrough(param_1,pvVar3,*(undefined8 *)((longlong)pvVar2 + 0x20));
    *(ulonglong *)(*(longlong *)(param_1 + 0x80) + 0xc0) =
         (ulonglong)CONCAT42(uStackX_c,uVar1) << 0x10;
    LOCK();
    UNLOCK();
    return;
  }
  MPT_BuildPassthrough(param_1,pvVar3,*(undefined8 *)((longlong)pvVar2 + 0x20));
  *(uint *)(*(longlong *)(param_1 + 0x80) + 200) = (uint)uVar1 << 0x10;
  LOCK();
  UNLOCK();
  return;
}



===== WaitForCmdStatus @ 140004a50 =====

uint WaitForCmdStatus(longlong param_1,longlong param_2)

{
  char cVar1;
  uint uVar2;
  
  cVar1 = *(char *)(param_2 + 0x102);
  while( true ) {
    if (cVar1 != -1) {
      if (cVar1 == '\0') {
        return 1;
      }
      return 0;
    }
    uVar2 = Fusion_ReadRegister(param_1,*(longlong *)(param_1 + 0x80));
    *(uint *)(param_1 + 0xd2e0) = uVar2;
    if ((uVar2 & 0xf0000000) == 0xf0000000) {
      return 0xf0000000;
    }
    if (*(int *)(param_1 + 0xd918) < 1) break;
    StorPortStallExecution(1000);
    *(int *)(param_1 + 0xd918) = *(int *)(param_1 + 0xd918) + -1000;
    cVar1 = *(char *)(param_2 + 0x102);
  }
  return uVar2 & 0xf0000000;
}



===== MR_GetPhyParams @ 140004ae0 =====

undefined8
MR_GetPhyParams(longlong param_1,longlong param_2,uint param_3,ulonglong param_4,ushort param_5,
               longlong *param_6,undefined2 *param_7,longlong param_8)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  uint uVar8;
  byte bVar9;
  ulonglong uVar10;
  longlong lVar11;
  longlong lVar12;
  longlong lVar13;
  byte local_res8 [8];
  
  uVar7 = (ulonglong)(*(int *)(param_1 + 0xd92c) - 1U & 1);
  lVar5 = *(longlong *)(param_1 + 0xd930 + uVar7 * 8);
  if (*(short *)(lVar5 + 0x2c) != 0) {
    lVar6 = *(longlong *)(lVar5 + 0x50);
    lVar13 = (ulonglong)param_3 * 0x9e0;
    bVar9 = *(byte *)(lVar13 + 0x14 + lVar6);
    uVar7 = 0;
    if (((bVar9 != 0) && (bVar2 = *(byte *)(lVar13 + 0x13 + lVar6), bVar2 != 0)) &&
       (bVar3 = *(byte *)(lVar13 + 0x1c + lVar6), bVar3 != 0)) {
      uVar7 = param_4 / bVar9;
      if (*(char *)(lVar13 + 0x11 + lVar6) == '\x06') {
        uVar8 = (int)(param_4 % (ulonglong)bVar9) - (int)(uVar7 % (ulonglong)bVar2);
        uVar1 = uVar8 + bVar2;
        uVar10 = (ulonglong)(uVar8 & 0xff);
        if (uVar1 < bVar2) {
          uVar10 = (ulonglong)uVar1 & 0xff;
        }
      }
      else {
        uVar10 = (ulonglong)*(byte *)(param_4 % (ulonglong)bVar3 + lVar13 + 0x80 + lVar6);
      }
      bVar9 = (byte)uVar10;
      if (*(char *)(lVar13 + 0x10 + lVar6) == '\x01') {
        local_res8[0] = 0;
        *param_6 = uVar7 << (*(byte *)(lVar13 + 0x12 + lVar6) & 0x3f);
      }
      else {
        uVar7 = MR_GetSpanBlock(lVar5,(ulonglong)param_3,uVar7,param_6,local_res8);
        if ((char)uVar7 == '\0') goto LAB_140004cfa;
      }
      lVar12 = (ulonglong)local_res8[0] * 0x128 + lVar13;
      lVar11 = (ulonglong)*(ushort *)(lVar12 + 0xb8 + *(longlong *)(lVar5 + 0x50)) * 0x20;
      uVar4 = *(ushort *)(*(longlong *)(lVar5 + 0x48) + (lVar11 + uVar10) * 2);
      if (uVar4 == 0xffff) {
        *param_7 = 0xffff;
        if (*(char *)(lVar13 + 0x11 + lVar6) == '\x01') {
          bVar9 = bVar9 + 1;
          uVar4 = *(ushort *)(*(longlong *)(lVar5 + 0x48) + ((ulonglong)bVar9 + lVar11) * 2);
          if (uVar4 != 0xffff) {
            *param_7 = *(undefined2 *)(*(longlong *)(lVar5 + 0x38) + (ulonglong)uVar4 * 8);
          }
        }
      }
      else {
        *param_7 = *(undefined2 *)(*(longlong *)(lVar5 + 0x38) + (ulonglong)uVar4 * 8);
        if ((*(char *)(param_2 + 0x32) != '\0') &&
           (uVar4 = *(ushort *)(*(longlong *)(lVar5 + 0x48) + 2 + (uVar10 + lVar11) * 2),
           uVar4 != 0xffff)) {
          *(undefined2 *)(param_2 + 0x30) =
               *(undefined2 *)(*(longlong *)(lVar5 + 0x38) + (ulonglong)uVar4 * 8);
        }
      }
      *param_6 = *param_6 +
                 *(longlong *)(lVar12 + 0xa8 + *(longlong *)(lVar5 + 0x50)) + (ulonglong)param_5;
      *(byte *)(param_8 + 0x19) = local_res8[0] << 5 | bVar9;
      *(byte *)(param_2 + 0xc4) = bVar9;
      *(byte *)(param_2 + 0xc5) = local_res8[0];
      return CONCAT71((int7)((ulonglong)param_8 >> 8),1);
    }
  }
LAB_140004cfa:
  return uVar7 & 0xffffffffffffff00;
}



===== MR_GetSpanBlock @ 140004d10 =====

ulonglong MR_GetSpanBlock(longlong param_1,ulonglong param_2,ulonglong param_3,longlong *param_4,
                         byte *param_5)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong *puVar3;
  ulonglong uVar4;
  byte bVar5;
  ulonglong *puVar6;
  uint uVar7;
  ulonglong uVar8;
  longlong lVar9;
  
  bVar5 = 0;
  uVar2 = *(ulonglong *)(param_1 + 0x50);
  lVar9 = (param_2 & 0xffffffff) * 0x9e0 + uVar2;
  if (*(byte *)(lVar9 + 0x10) != 0) {
    puVar6 = (ulonglong *)(lVar9 + 200);
    do {
      uVar7 = 0;
      if ((uint)puVar6[-1] != 0) {
        puVar3 = puVar6;
        do {
          uVar1 = (uint)puVar3[3];
          uVar2 = (ulonglong)uVar1;
          if (uVar1 == 0) goto LAB_140004da6;
          if ((*puVar3 <= param_3) && (param_3 <= puVar3[1])) {
            uVar4 = (ulonglong)uVar1;
            uVar8 = param_3 - *puVar3;
            uVar2 = uVar8 / uVar4;
            if (uVar8 % uVar4 == 0) {
              *param_4 = uVar8 / uVar4 + puVar3[2] << (*(byte *)(lVar9 + 0x12) & 0x3f);
              *param_5 = bVar5;
              return CONCAT71((int7)((ulonglong)param_5 >> 8),1);
            }
          }
          uVar7 = uVar7 + 1;
          puVar3 = puVar3 + 4;
        } while (uVar7 < (uint)puVar6[-1]);
      }
      bVar5 = bVar5 + 1;
      puVar6 = puVar6 + 0x25;
    } while (bVar5 < *(byte *)(lVar9 + 0x10));
  }
LAB_140004da6:
  return uVar2 & 0xffffffffffffff00;
}



===== MegaSASBuildRaidContext @ 140004df0 =====

ulonglong MegaSASBuildRaidContext
                    (longlong param_1,longlong *param_2,longlong *param_3,longlong param_4,
                    short *param_5,byte *param_6,longlong *param_7)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  undefined1 uVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  uint uVar10;
  byte bVar11;
  char cVar12;
  ulonglong uVar13;
  uint uVar14;
  ulonglong uVar15;
  longlong lVar16;
  ushort uVar17;
  uint uVar18;
  ulonglong uVar19;
  uint *puVar20;
  byte bVar21;
  byte local_res8;
  byte local_87;
  ushort local_86;
  ushort local_84;
  uint local_80;
  ulonglong local_78;
  uint local_70;
  longlong local_68;
  ulonglong local_60;
  ulonglong local_58;
  ulonglong local_50;
  ulonglong local_48;
  uint *local_40;
  
  uVar15 = param_2[7];
  local_res8 = 1;
  local_48 = (ulonglong)*(byte *)(*param_2 + 6);
  cVar12 = *(char *)((longlong)param_2 + 0xd);
  uVar8 = (ulonglong)(*(uint *)(param_2 + 0x17) & 1);
  local_70 = (uint)*(byte *)(*param_2 + 6);
  lVar5 = *(longlong *)(param_1 + 0xd930 + uVar8 * 8);
  if (*(short *)(lVar5 + 0x2c) == 0) {
LAB_1400054c8:
    return uVar8 & 0xffffffffffffff00;
  }
  uVar2 = *(ushort *)(*(longlong *)(lVar5 + 0x40) + local_48 * 2);
  uVar19 = (ulonglong)uVar2;
  uVar8 = (ulonglong)*(ushort *)(param_1 + 0xe462);
  uVar18 = (uint)uVar2;
  if (*(ushort *)(param_1 + 0xe462) <= uVar18) goto LAB_1400054c8;
  uVar8 = *(ulonglong *)(lVar5 + 0x50);
  local_68 = uVar19 * 0x9e0;
  puVar20 = (uint *)(local_68 + uVar8);
  uVar14 = 1 << (*(byte *)(local_68 + 0x12 + uVar8) & 0x1f);
  if ((char)puVar20[5] == '\0') goto LAB_1400054c8;
  uVar10 = puVar20[0xc];
  uVar8 = (ulonglong)uVar10;
  *(uint *)(param_2 + 0x18) = uVar10;
  if (uVar10 == 0) goto LAB_1400054c8;
  local_86 = (short)uVar14 - 1;
  uVar13 = uVar15 >> (*(byte *)((longlong)puVar20 + 0x12) & 0x3f);
  uVar17 = (ushort)uVar15 & local_86;
  uVar15 = (uVar15 - 1) + (ulonglong)*(uint *)(param_2 + 9);
  local_50 = uVar15 >> (*(byte *)((longlong)puVar20 + 0x12) & 0x3f);
  local_86 = (ushort)uVar15 & local_86;
  local_60 = uVar13 / (byte)puVar20[5];
  bVar21 = ((char)local_50 - (char)uVar13) + 1;
  local_58 = local_50 / (byte)puVar20[5];
  *(byte *)((longlong)param_2 + 0x9f) = bVar21;
  *(undefined1 *)((longlong)param_2 + 0x9d) = *(undefined1 *)((longlong)puVar20 + 0x11);
  *(undefined1 *)((longlong)param_2 + 0x9e) = *(undefined1 *)((longlong)puVar20 + 0x15);
  *(char *)(param_2 + 0x14) = (char)puVar20[4];
  bVar11 = ((char)local_58 - (char)local_60) + 1;
  lVar16 = local_60 << (*(byte *)((longlong)puVar20 + 0x12) & 0x3f);
  if (bVar11 == 1) {
    if (bVar21 == 1) {
      lVar16 = lVar16 + (ulonglong)uVar17;
      uVar14 = *(uint *)(param_2 + 9);
    }
  }
  else {
    uVar10 = uVar14;
    if (uVar13 == (local_60 + 1) * (ulonglong)(byte)puVar20[5] - 1) {
      lVar16 = lVar16 + (ulonglong)uVar17;
      uVar10 = uVar14 - uVar17;
    }
    if (2 < bVar11) {
      uVar10 = uVar10 + (bVar11 - 2 << (*(byte *)((longlong)puVar20 + 0x12) & 0x1f));
    }
    if (local_50 == (byte)puVar20[5] * local_58) {
      uVar14 = uVar10 + local_86 + 1;
    }
    else {
      uVar14 = uVar10 + uVar14;
    }
  }
  *(ushort *)(param_4 + 2) = (ushort)*(byte *)(lVar5 + 0x24);
  *(ushort *)(param_4 + 6) = (ushort)*(byte *)(*param_2 + 6);
  *(longlong *)(param_4 + 8) = lVar16;
  *(uint *)(param_4 + 0x10) = uVar14;
  *(undefined2 *)(param_4 + 0x1a) = *(undefined2 *)((longlong)puVar20 + 0x1e);
  *(ushort *)(param_4 + 4) = *(ushort *)(param_4 + 4) & 0xfffd;
  *param_7 = (longlong)(puVar20 + 9);
  uVar14 = *puVar20;
  if ((uVar14 & 2) != 0) {
    *(undefined1 *)(param_2 + 0x10) = 1;
    uVar14 = *puVar20;
  }
  if ((uVar14 & 1) == 0) {
    *param_6 = 0;
  }
  else if (cVar12 == '\0') {
    if (((uVar14 >> 0x14 & 1) == 0) || ((bVar21 != 1 && ((uVar14 >> 0x16 & 1) == 0)))) {
      bVar11 = 0;
    }
    else {
      bVar11 = 1;
    }
    *param_6 = bVar11;
    if (((*(char *)((longlong)puVar20 + 0x15) == '\x01') &&
        (*(byte *)((longlong)puVar20 + 0x11) < 2)) && (bVar11 != 0)) {
      *param_6 = (byte)(*puVar20 >> 0x1d) & 1;
    }
  }
  else if (((uVar14 >> 0x15 & 1) == 0) || ((bVar21 != 1 && ((uVar14 >> 0x17 & 1) == 0)))) {
    *param_6 = 0;
  }
  else {
    *param_6 = 1;
  }
  if (((*puVar20 >> 0x1b & 1) == 0) || (*(char *)((longlong)puVar20 + 0x1a) != '\x03')) {
    uVar7 = 0;
  }
  else {
    uVar7 = 1;
  }
  *(undefined1 *)(param_2 + 2) = uVar7;
  if (((byte)*puVar20 & 0xf0) == 0x80) {
    *(undefined1 *)((longlong)param_2 + 0x9b) = 1;
  }
  uVar3 = *(ushort *)
           ((ulonglong)*(ushort *)(local_68 + 0xb8 + *(longlong *)(lVar5 + 0x50)) * 0x40 +
           *(longlong *)(lVar5 + 0x48));
  uVar8 = 0xffff;
  if (uVar3 == 0xffff) goto LAB_1400054c8;
  cVar1 = *(char *)(*(longlong *)(lVar5 + 0x38) + 3 + (ulonglong)uVar3 * 8);
  *(char *)((longlong)param_2 + 0xa2) = cVar1;
  if (cVar1 == '\x05') {
    if ((*(longlong *)(param_1 + 0xd988) != 0) &&
       (iVar4 = *(int *)((ulonglong)(local_70 + 0x100) * 0x20 + *(longlong *)(param_1 + 0xd988)),
       iVar4 != 0)) {
      *(int *)(param_2 + 0xf) = iVar4 << 10;
    }
    uVar8 = (ulonglong)*(uint *)(param_2 + 0xf);
    if (*(uint *)(param_2 + 0xf) < *(uint *)((longlong)param_2 + 0x11c)) goto LAB_1400054c8;
  }
  local_84 = uVar17;
  local_80 = uVar18;
  local_78 = uVar13;
  local_40 = puVar20;
  if ((*(char *)((longlong)puVar20 + 0x11) == '\x01') &&
     (*(char *)((longlong)param_2 + 0xe) != '\0')) {
    if (*(char *)((longlong)puVar20 + 0x1a) == '\x03') {
      *(undefined1 *)((longlong)param_2 + 0x32) = 1;
      if (((*(uint *)(param_1 + 0xe45c) >> 10 & 1) != 0) &&
         (0x8000 < *(uint *)((longlong)param_2 + 0x11c))) {
        *param_6 = 0;
        *(undefined1 *)((longlong)param_2 + 0x9a) = 1;
        *(undefined1 *)(local_48 + *(longlong *)(param_1 + 0xe8d0)) =
             *(undefined1 *)(param_1 + 0xe8c8);
      }
      goto LAB_1400051b0;
    }
    if ((byte)puVar20[4] < 2) goto LAB_1400051b0;
    *param_6 = 0;
LAB_14000522b:
    if ((cVar12 != '\0') && (bVar21 != 0)) {
      uVar15 = (ulonglong)bVar21;
      do {
        uVar9 = MR_GetPhyParams(param_1,(longlong)param_2,uVar18,uVar13,uVar17,param_3,param_5,
                                param_4);
        uVar13 = uVar13 + 1;
        local_res8 = (byte)uVar9;
        uVar15 = uVar15 - 1;
      } while (uVar15 != 0);
      uVar19 = (ulonglong)local_80;
      puVar20 = local_40;
      goto LAB_1400052b7;
    }
LAB_1400052c0:
    uVar2 = *(ushort *)(param_4 + 4);
    if (*(char *)((longlong)param_2 + 0xd) == '\0') {
      if ((*(byte *)((longlong)puVar20 + 0x3b) & 6) == 6) {
        uVar17 = uVar2 | 0xf00;
      }
      else {
        uVar17 = uVar2 & 0xf0ff;
        if ((*(byte *)((longlong)puVar20 + 0x3b) & 4) != 0) {
          uVar17 = uVar2 & 0xf1ff | 0x100;
        }
      }
      *(ushort *)(param_4 + 4) = uVar17;
      if ((((*param_6 != 0) && (*(char *)((longlong)puVar20 + 0x15) == '\x01')) &&
          (*(byte *)((longlong)puVar20 + 0x11) < 2)) &&
         ((*(ushort *)(param_4 + 4) = uVar17 | 2, *(char *)((longlong)puVar20 + 0x11) == '\x01' &&
          (*(undefined1 *)(param_4 + 0x18) = 0x60, 0x7fff < *(uint *)((longlong)param_2 + 0x11c)))))
      {
        *(undefined1 *)(param_2 + 0x2f) = 0x70;
      }
    }
    else if ((*(byte *)((longlong)puVar20 + 0x3a) & 6) == 6) {
      *(ushort *)(param_4 + 4) = uVar2 | 0xf00;
    }
    else {
      uVar17 = uVar2 & 0xf0ff;
      if ((*(byte *)((longlong)puVar20 + 0x3a) & 4) != 0) {
        uVar17 = uVar2 & 0xf1ff | 0x100;
      }
      *(ushort *)(param_4 + 4) = uVar17;
    }
  }
  else {
LAB_1400051b0:
    if (*param_6 == 0) goto LAB_14000522b;
    uVar9 = MR_GetPhyParams(param_1,(longlong)param_2,(uint)uVar2,uVar13,uVar17,param_3,param_5,
                            param_4);
    local_res8 = (byte)uVar9;
    if ((*param_5 == -1) ||
       ((*(char *)((longlong)param_2 + 0x32) != '\0' && ((short)param_2[6] == -1)))) {
      *param_6 = 0;
    }
LAB_1400052b7:
    if (local_res8 != 0) goto LAB_1400052c0;
  }
  if (((*(int *)(param_1 + 0xd924) == 2) && (4 < *(byte *)((longlong)puVar20 + 0x11))) &&
     ((*(char *)((longlong)param_2 + 0xe) != '\0' &&
      (lVar5 = *(longlong *)
                (param_1 + 0xd930 + (ulonglong)(*(int *)(param_1 + 0xd92c) - 1U & 1) * 8),
      *(short *)(lVar5 + 0x2c) != 0)))) {
    lVar6 = *(longlong *)(lVar5 + 0x50);
    bVar11 = *(byte *)(local_68 + 0x13 + lVar6);
    lVar16 = local_68 + lVar6;
    bVar21 = *(byte *)(local_68 + 0x14 + lVar6);
    if ((bVar21 != 0) && (bVar11 != 0)) {
      uVar15 = local_78 / bVar21;
      uVar8 = local_78 % (ulonglong)bVar21;
      cVar12 = bVar11 - (char)(uVar15 % (ulonglong)bVar11);
      bVar21 = cVar12 - 1;
      if (*(char *)(lVar16 + 0x10) == '\x01') {
        local_87 = 0;
      }
      else {
        uVar9 = MR_GetSpanBlock(lVar5,uVar19,uVar15,param_3,&local_87);
        if ((char)uVar9 == '\0') goto LAB_1400054be;
      }
      if (*(char *)(lVar16 + 0x11) == '\x06') {
        *(ushort *)(param_4 + 0x14) = (ushort)(byte)(cVar12 - 2) << 5 | (ushort)bVar21;
      }
      else {
        *(ushort *)(param_4 + 0x14) = *(ushort *)(param_4 + 0x14) | (ushort)bVar21 << 5;
      }
      *(byte *)((longlong)param_2 + 0xc5) = local_87;
      *(ushort *)(param_4 + 0x14) = *(ushort *)(param_4 + 0x14) | (short)uVar8 << 10;
      *(ulonglong *)(param_4 + 8) = uVar15;
      *(byte *)(param_4 + 0x19) =
           local_87 << 5 | (byte)(((uint)bVar21 + (int)uVar8 + 1) % (uint)bVar11);
      *(undefined1 *)(param_4 + 0x18) = 0x80;
    }
  }
LAB_1400054be:
  return (ulonglong)local_res8;
}



===== MegaSASCheckBestRaid1Arm @ 1400054f0 =====

byte MegaSASCheckBestRaid1Arm
               (longlong param_1,longlong param_2,longlong param_3,ulonglong param_4,byte param_5,
               ulonglong param_6,uint param_7)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  longlong lVar6;
  byte bVar7;
  ulonglong uVar8;
  longlong lVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  
  lVar1 = *(longlong *)(param_1 + 0xd930 + (ulonglong)(*(int *)(param_1 + 0xd92c) - 1U & 1) * 8);
  if (*(short *)(lVar1 + 0x2c) == 0) {
    return 0;
  }
  lVar6 = (param_4 & 0xffffffff) * 0x9e0;
  lVar9 = (ulonglong)
          *(ushort *)
           ((ulonglong)*(byte *)(param_2 + 0xc5) * 0x128 + lVar6 + 0xb8 +
           *(longlong *)(lVar1 + 0x50)) * 0x20;
  uVar5 = (uint)*(byte *)(lVar6 + 0x13 + *(longlong *)(lVar1 + 0x50));
  uVar11 = (ulonglong)*(ushort *)(*(longlong *)(lVar1 + 0x48) + (lVar9 + (ulonglong)param_5) * 2);
  uVar3 = param_5 - uVar5;
  if (param_5 + 1 < uVar5) {
    uVar3 = (uint)param_5;
  }
  uVar10 = (ulonglong)
           *(ushort *)(*(longlong *)(lVar1 + 0x48) + ((ulonglong)(uVar3 + 1) + lVar9) * 2);
  bVar7 = param_5;
  if (*(short *)(*(longlong *)(lVar1 + 0x38) + uVar10 * 8) != -1) {
    uVar3 = *(uint *)(param_3 + 4 + uVar11 * 4);
    uVar5 = *(uint *)(param_3 + 4 + uVar10 * 4);
    uVar4 = *(ulonglong *)(param_3 + 0x408 + uVar11 * 8);
    uVar2 = *(ulonglong *)(param_3 + 0x408 + uVar10 * 8);
    uVar8 = param_6 - uVar4;
    if (param_6 <= uVar4) {
      uVar8 = uVar4 - param_6;
    }
    uVar4 = param_6 - uVar2;
    if (param_6 <= uVar2) {
      uVar4 = uVar2 - param_6;
    }
    if (uVar4 < uVar8) {
      bVar7 = param_5 ^ 1;
    }
    if (((bVar7 == param_5) && (uVar5 + *(int *)(param_1 + 0x8c) < uVar3)) ||
       ((bVar7 != param_5 && (uVar3 + *(int *)(param_1 + 0x8c) < uVar5)))) {
      bVar7 = bVar7 ^ 1;
    }
  }
  if (bVar7 == param_5) {
    uVar10 = uVar11;
  }
  *(ulonglong *)(param_3 + 0x408 + uVar10 * 8) = (param_6 - 1) + (ulonglong)param_7;
  return bVar7;
}



===== MegaSASPrepareSyncInfo @ 140005680 =====

longlong MegaSASPrepareSyncInfo(undefined8 param_1,longlong param_2,ushort *param_3)

{
  ushort uVar1;
  ulonglong uVar2;
  longlong lVar3;
  byte bVar4;
  
  uVar1 = *(ushort *)(param_2 + 0x2c);
  if (uVar1 == 0) {
    return 0;
  }
  bVar4 = 0;
  if (uVar1 != 0) {
    do {
      uVar2 = (ulonglong)bVar4;
      bVar4 = bVar4 + 1;
      lVar3 = uVar2 * 0x9e0 + *(longlong *)(param_2 + 0x50);
      *param_3 = (ushort)*(byte *)(lVar3 + 0x18);
      param_3[1] = *(ushort *)(lVar3 + 0x1e);
      param_3 = param_3 + 2;
    } while ((ushort)bVar4 < *(ushort *)(param_2 + 0x2c));
  }
  return (ulonglong)uVar1 << 2;
}



===== MegaSASValidateAndProcessMapInfo @ 1400056f0 =====

ulonglong MegaSASValidateAndProcessMapInfo(longlong param_1,undefined4 param_2,undefined1 param_3)

{
  uint *puVar1;
  int iVar2;
  longlong lVar3;
  byte *pbVar4;
  uint uVar5;
  undefined1 *puVar6;
  ulonglong uVar7;
  ushort uVar8;
  int *piVar9;
  longlong lVar10;
  undefined1 *puVar11;
  ulonglong uVar12;
  undefined4 uVar13;
  uint local_res8;
  uint *puVar14;
  uint uVar15;
  
  puVar14 = *(uint **)(param_1 + 0xd930 + (ulonglong)(*(uint *)(param_1 + 0xd92c) & 1) * 8);
  if (*(uint *)(param_1 + 0xd800) < *puVar14) {
    if ((*(char *)(param_1 + 0xeb50) == '\0') || ((*(uint *)(param_1 + 0xeb54) & 0x28b) == 0))
    goto LAB_140005765;
    uVar15 = 4;
    uVar13 = 0x28b;
  }
  else {
    piVar9 = (int *)((ulonglong)puVar14[1] + (longlong)puVar14);
    if ((ulonglong)puVar14[1] == 0x58) {
      puVar6 = (undefined1 *)(ulonglong)puVar14[2];
      puVar11 = (undefined1 *)((longlong)(puVar14 + 0x16) + (longlong)puVar6);
      uVar15 = 0;
      if (puVar14[3] != 0) {
        do {
          iVar2 = *piVar9;
          if (iVar2 == 0) {
            puVar6 = puVar11 + (uint)piVar9[1];
            *(undefined1 **)(puVar14 + 0xe) = puVar6;
          }
          else if (iVar2 == 1) {
            *(undefined1 **)(puVar14 + 0x10) = puVar11 + (uint)piVar9[1];
            puVar6 = (undefined1 *)(ulonglong)*(ushort *)(piVar9 + 3);
            *(ushort *)(param_1 + 0xe462) = *(ushort *)(piVar9 + 3);
          }
          else if (iVar2 == 2) {
            puVar6 = puVar11 + (uint)piVar9[1];
            *(undefined1 **)(puVar14 + 0x12) = puVar6;
          }
          else if (iVar2 == 3) {
            puVar6 = puVar11 + (uint)piVar9[1];
            *(undefined1 **)(puVar14 + 0x14) = puVar6;
          }
          piVar9 = piVar9 + 4;
          uVar15 = uVar15 + 1;
        } while (uVar15 < puVar14[3]);
      }
      if ((short)puVar14[0xb] == 0) {
        *(undefined8 *)(param_1 + 0xd710) = 0;
        *(undefined8 *)(param_1 + 0xd718) = 0;
        *(undefined8 *)(param_1 + 0xd720) = 0;
        *(undefined8 *)(param_1 + 0xd728) = 0;
        *(undefined8 *)(param_1 + 0xd730) = 0;
        *(undefined8 *)(param_1 + 0xd738) = 0;
        *(undefined8 *)(param_1 + 0xd740) = 0;
        *(undefined8 *)(param_1 + 0xd748) = 0;
        return CONCAT71((int7)((ulonglong)puVar6 >> 8),1);
      }
      uVar8 = *(ushort *)(param_1 + 0xe462);
      uVar15 = 0;
      *(undefined1 *)(param_1 + 0xd914) = 1;
      if (uVar8 != 0) {
        do {
          puVar6 = *(undefined1 **)(puVar14 + 0x10);
          uVar12 = (ulonglong)uVar15;
          lVar3 = (longlong)uVar12 >> 3;
          if (*(ushort *)(puVar6 + uVar12 * 2) < uVar8) {
            lVar10 = (ulonglong)*(ushort *)(puVar6 + uVar12 * 2) * 0x9e0;
            uVar7 = *(ulonglong *)(puVar14 + 0x14);
            puVar1 = (uint *)(lVar10 + uVar7);
            if (puVar1 == (uint *)0x0) {
              if ((*(char *)(param_1 + 0xeb50) != '\0') &&
                 (uVar7 = (ulonglong)*(uint *)(param_1 + 0xeb54),
                 (*(uint *)(param_1 + 0xeb54) & 0x292) != 0)) {
                uVar7 = RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x292,
                                    (undefined1 *)0x0,0,param_3,param_2);
                uVar8 = *(ushort *)(param_1 + 0xe462);
              }
              *(ushort *)(param_1 + 0xd308) = uVar8;
              return uVar7 & 0xffffffffffffff00;
            }
            uVar5 = *puVar1;
            if ((uVar5 & 0x800000) != 0) {
              *(undefined1 *)(*(longlong *)(param_1 + 0xd818) + 8 + uVar12 * 0x180) = 1;
              uVar5 = *puVar1;
            }
            if ((uVar5 & 0x400000) != 0) {
              *(undefined1 *)(*(longlong *)(param_1 + 0xd818) + 9 + uVar12 * 0x180) = 1;
            }
            *(undefined1 *)(*(longlong *)(param_1 + 0xd818) + 10 + uVar12 * 0x180) =
                 *(undefined1 *)((longlong)puVar1 + 0x12);
            *(char *)(uVar12 + 0xec88 + param_1) = (char)puVar1[5] << 3;
            if ((((*(char *)((longlong)puVar1 + 0x11) == '\0') && ((char)puVar1[4] == '\x01')) &&
                (*(char *)((longlong)puVar1 + 0x13) == '\x01')) &&
               (*(longlong *)(lVar10 + 0xa8 + *(longlong *)(puVar14 + 0x14)) == 0)) {
              pbVar4 = (byte *)(param_1 + 0xd710 + lVar3);
              *pbVar4 = *pbVar4 | '\x01' << (uVar12 & 7);
            }
            else {
              pbVar4 = (byte *)(param_1 + 0xd710 + lVar3);
              *pbVar4 = *pbVar4 & ~('\x01' << (uVar12 & 7));
            }
            if ((puVar1[8] & 4) == 0) {
              pbVar4 = (byte *)(param_1 + 0xd730 + lVar3);
              *pbVar4 = *pbVar4 & ~('\x01' << (uVar12 & 7));
            }
            else {
              pbVar4 = (byte *)(param_1 + 0xd730 + lVar3);
              *pbVar4 = *pbVar4 | '\x01' << (uVar12 & 7);
            }
            puVar6 = (undefined1 *)(uVar12 * 0xc08 + *(longlong *)(param_1 + 0xd978));
            local_res8 = uVar15;
            if ((*(char *)((longlong)puVar1 + 0x11) == '\x01') &&
               (*(char *)((longlong)puVar1 + 0x1a) == '\x03')) {
              *puVar6 = 1;
            }
            else {
              *puVar6 = 0;
            }
          }
          else {
            pbVar4 = (byte *)(param_1 + 0xd710 + lVar3);
            *pbVar4 = *pbVar4 & ~('\x01' << (uVar12 & 7));
            pbVar4 = (byte *)(param_1 + 0xd730 + lVar3);
            *pbVar4 = *pbVar4 & ~('\x01' << (uVar12 & 7));
          }
          uVar8 = *(ushort *)(param_1 + 0xe462);
          uVar15 = uVar15 + 1;
        } while (uVar15 < uVar8);
      }
      *(undefined1 *)(param_1 + 0xd912) = 0;
      *(short *)(param_1 + 0xd308) = (short)local_res8 + 1;
      if (*(char *)(param_1 + 0xd913) == '\0') {
        *(undefined1 *)(param_1 + 0xd928) = 1;
      }
      *(undefined1 *)(param_1 + 0xd914) = 0;
      return CONCAT71((int7)((ulonglong)puVar6 >> 8),1);
    }
    if ((*(char *)(param_1 + 0xeb50) == '\0') || ((*(uint *)(param_1 + 0xeb54) & 0x28c) == 0))
    goto LAB_140005765;
    uVar15 = 0;
    puVar14 = (uint *)0x0;
    uVar13 = 0x28c;
  }
  RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),uVar13,(undefined1 *)puVar14,uVar15
              ,param_3,param_2);
LAB_140005765:
  *(undefined2 *)(param_1 + 0xd308) = *(undefined2 *)(param_1 + 0xe462);
  return (ulonglong)(byte)((ushort)*(undefined2 *)(param_1 + 0xe462) >> 8) << 8;
}



===== Fusion_CheckInterrupt @ 140005aa0 =====

byte Fusion_CheckInterrupt(longlong param_1)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar4 = 0;
  do {
    uVar1 = *(uint *)(*(longlong *)(param_1 + 0x80) + 0x30);
    iVar4 = iVar4 + 1;
    if (uVar1 != 0) break;
  } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x88));
  bVar3 = (byte)(uVar1 >> 3) & 1;
  if ((uVar1 & 1) != 0) {
    bVar3 = bVar3 | 2;
    *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x30) = 1;
    LOCK();
    UNLOCK();
    do {
      iVar2 = iVar2 + 1;
      if (*(int *)(*(longlong *)(param_1 + 0x80) + 0x30) != 0) {
        return bVar3;
      }
    } while (iVar2 < (int)(uint)*(byte *)(param_1 + 0x88));
  }
  return bVar3;
}



===== Fusion_DisableInterrupt @ 140005b10 =====

void Fusion_DisableInterrupt(longlong param_1)

{
  int iVar1;
  
  *(uint *)(param_1 + 0xd810) = *(uint *)(param_1 + 0xd810) | 8;
  *(undefined1 *)(param_1 + 0xe3b0) = 1;
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x34) = 0xffffffff;
  LOCK();
  UNLOCK();
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
    if (*(int *)(*(longlong *)(param_1 + 0x80) + 0x34) != 0) {
      return;
    }
  } while (iVar1 < (int)(uint)*(byte *)(param_1 + 0x88));
  return;
}



===== Fusion_EnableInterrupt @ 140005b60 =====

void Fusion_EnableInterrupt(longlong param_1)

{
  int iVar1;
  
  *(uint *)(param_1 + 0xd810) = *(uint *)(param_1 + 0xd810) & 0xfffffff7;
  *(undefined1 *)(param_1 + 0xe3b0) = 0;
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x30) = 0xffffffff;
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x34) = 0xfffffff6;
  LOCK();
  UNLOCK();
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
    if (*(int *)(*(longlong *)(param_1 + 0x80) + 0x34) != 0) {
      return;
    }
  } while (iVar1 < (int)(uint)*(byte *)(param_1 + 0x88));
  return;
}



===== Fusion_ReadRegister @ 140005bc0 =====

void Fusion_ReadRegister(longlong param_1,longlong param_2)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
    if (*(int *)(param_2 + 0xb0) != 0) {
      return;
    }
  } while (iVar1 < (int)(uint)*(byte *)(param_1 + 0x88));
  return;
}



===== Fusion_WriteDoorbell @ 140005be0 =====

void Fusion_WriteDoorbell(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  LOCK();
  UNLOCK();
  return;
}



===== CheckFirmwareReady @ 140005bf0 =====

ulonglong CheckFirmwareReady(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  
  uVar1 = Fusion_ReadRegister(param_1,*(longlong *)(param_1 + 0x80));
  *(uint *)(param_1 + 0xd2e0) = uVar1;
  if (uVar1 != *(uint *)(param_1 + 0xd2e4)) {
    *(uint *)(param_1 + 0xd2e4) = uVar1;
    *(undefined1 *)(param_1 + 0xd2e8) = 0;
  }
  uVar1 = uVar1 >> 0x1c;
  if (uVar1 == 0) {
    uVar2 = 0;
    if (*(char *)(param_1 + 0xd90f) == '\0') {
      do {
        if (*(int *)(param_1 + 0xd91c) < 1) break;
        StorPortStallExecution(1000);
        *(int *)(param_1 + 0xd91c) = *(int *)(param_1 + 0xd91c) + -1000;
        uVar2 = Fusion_ReadRegister(param_1,*(longlong *)(param_1 + 0x80));
        *(uint *)(param_1 + 0xd2e0) = (uint)uVar2;
      } while ((uint)uVar2 < 0x10000000);
      *(undefined1 *)(param_1 + 0xeb10) = 1;
    }
  }
  else if (uVar1 == 6) {
    uVar2 = 0;
    if (*(char *)(param_1 + 0xd2e8) == '\0') {
      uVar3 = 0x18;
LAB_140005ca8:
      uVar2 = Fusion_WriteDoorbell(*(undefined4 **)(param_1 + 0x80),uVar3);
      *(undefined1 *)(param_1 + 0xd2e8) = 1;
      return uVar2 & 0xffffffffffffff00;
    }
  }
  else if (uVar1 == 9) {
    uVar2 = 0;
    if (*(char *)(param_1 + 0xd2e8) == '\0') {
      uVar3 = 0x10;
      goto LAB_140005ca8;
    }
  }
  else {
    if (uVar1 == 0xb) {
      *(undefined4 *)(param_1 + 0xd2e4) = 0xff;
      *(undefined1 *)(param_1 + 0xd90e) = 0;
      return 1;
    }
    uVar2 = (ulonglong)(uVar1 - 0xc);
    if ((uVar1 - 0xc == 0) && (*(char *)(param_1 + 0xd2e9) == '\0')) {
      uVar2 = Fusion_WriteDoorbell(*(undefined4 **)(param_1 + 0x80),uVar1 - 5);
      *(undefined1 *)(param_1 + 0xd2e9) = 1;
      return uVar2 & 0xffffffffffffff00;
    }
  }
  return uVar2 & 0xffffffffffffff00;
}



===== InitializeAdapter @ 140005d20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong InitializeAdapter(longlong param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  longlong lVar3;
  undefined2 uVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined4 extraout_var;
  ulonglong uVar7;
  byte bVar8;
  int iVar9;
  longlong lVar10;
  undefined2 uVar11;
  undefined1 *puVar12;
  longlong lVar13;
  longlong lVar14;
  undefined4 uVar15;
  undefined1 auStackY_78 [32];
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  undefined2 local_32;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_78;
  *(undefined1 *)(param_1 + 0xd929) = 0;
  *(undefined8 *)(param_1 + 0xe43c) = 0;
  *(undefined8 *)(param_1 + 0xe448) = 0;
  *(undefined4 *)(param_1 + 0xe444) = 0;
  *(undefined1 *)(param_1 + 0xd306) = 0;
  *(undefined1 *)(param_1 + 0xd950) = 0;
  *(undefined4 *)(param_1 + 0xd918) = 180000000;
  do {
    lVar14 = *(longlong *)(param_1 + 0xb0);
    uVar6 = MPT_InitializeQueues(param_1,lVar14,*(undefined8 **)(param_1 + 0x1e8));
    uVar5 = WaitForCmdStatus(param_1,lVar14);
    uVar7 = CONCAT44(extraout_var,uVar5);
    if ((char)uVar5 == '\0') {
      if ((*(char *)(param_1 + 0xeb50) == '\0') ||
         (uVar7 = (ulonglong)*(uint *)(param_1 + 0xeb54), (*(uint *)(param_1 + 0xeb54) & 0x2a3) == 0
         )) goto LAB_140006590;
      uVar15 = 0x2a3;
      goto LAB_140006567;
    }
  } while ((char)uVar6 == '\0');
  uVar5 = Fusion_ReadRegister(param_1,*(longlong *)(param_1 + 0x80));
  *(uint *)(param_1 + 0xd2e0) = uVar5;
  uVar7 = (ulonglong)(uVar5 & 0xf0000000);
  if ((uVar5 & 0xf0000000) == 0xc0000000) {
    iVar9 = 0;
    do {
      iVar2 = *(int *)(*(longlong *)(param_1 + 0x80) + 0xb4);
      iVar9 = iVar9 + 1;
      if (iVar2 != 0) break;
    } while (iVar9 < (int)(uint)*(byte *)(param_1 + 0x88));
    *(undefined4 *)(param_1 + 0xd918) = 180000000;
    *(byte *)(param_1 + 0xe46e) = (byte)((uint)iVar2 >> 0x18) & 1;
    uVar7 = SendAndWaitDCMD(param_1,0x1010000,param_2);
    if ((char)uVar7 != '\0') {
      lVar14 = *(longlong *)(param_1 + 0x198);
      lVar13 = 0x100;
      bVar8 = (byte)(*(uint *)(lVar14 + 0x7e8) >> 5) & 1;
      *(byte *)(param_1 + 0xe460) = bVar8;
      *(byte *)(param_1 + 0xe45a) = (byte)(*(uint *)(lVar14 + 0x7e8) >> 0x12) & 1;
      *(byte *)(param_1 + 0xe46c) = *(byte *)(lVar14 + 0x7eb) & 1;
      *(byte *)(param_1 + 0xe8ad) = *(byte *)(lVar14 + 0x7fc) >> 6 & 1;
      *(byte *)(param_1 + 0xe46d) = (byte)((uint)*(undefined4 *)(lVar14 + 0x848) >> 8) & 1;
      *(byte *)(param_1 + 0xe46f) = (byte)((ushort)*(undefined2 *)(lVar14 + 0x7fc) >> 0xd) & 1;
      *(byte *)(param_1 + 0xe470) = (byte)(*(uint *)(lVar14 + 0x848) >> 0x11) & 1;
      bVar1 = *(byte *)(lVar14 + 0x53f);
      *(undefined4 *)(param_1 + 0xe468) = 0x1000100;
      *(undefined2 *)(param_1 + 0xe7e0) = 0;
      if (0x40 < bVar1) {
        bVar8 = 1;
      }
      *(byte *)(param_1 + 0xe460) = bVar8;
      *(undefined8 *)(param_1 + 0xe4c0) = 0;
      *(undefined8 *)(param_1 + 0xe4c8) = 0;
      *(undefined8 *)(param_1 + 0xe4d0) = 0;
      *(undefined8 *)(param_1 + 0xe4d8) = 0;
      *(undefined8 *)(param_1 + 0xe4e0) = 0;
      *(undefined8 *)(param_1 + 0xe4e8) = 0;
      *(undefined8 *)(param_1 + 0xe4f0) = 0;
      *(undefined8 *)(param_1 + 0xe4f8) = 0;
      *(undefined8 *)(param_1 + 0xe500) = 0;
      *(undefined8 *)(param_1 + 0xe508) = 0;
      *(undefined8 *)(param_1 + 0xe510) = 0;
      *(undefined8 *)(param_1 + 0xe518) = 0;
      *(undefined8 *)(param_1 + 0xe520) = 0;
      *(undefined8 *)(param_1 + 0xe528) = 0;
      *(undefined8 *)(param_1 + 0xe530) = 0;
      *(undefined8 *)(param_1 + 0xe538) = 0;
      *(undefined8 *)(param_1 + 0xe540) = 0;
      *(undefined8 *)(param_1 + 0xe548) = 0;
      *(undefined8 *)(param_1 + 0xe550) = 0;
      *(undefined8 *)(param_1 + 0xe558) = 0;
      *(undefined8 *)(param_1 + 0xe560) = 0;
      *(undefined8 *)(param_1 + 0xe568) = 0;
      *(undefined8 *)(param_1 + 0xe570) = 0;
      *(undefined8 *)(param_1 + 0xe578) = 0;
      *(undefined8 *)(param_1 + 0xe580) = 0;
      *(undefined8 *)(param_1 + 0xe588) = 0;
      *(undefined8 *)(param_1 + 0xe590) = 0;
      *(undefined8 *)(param_1 + 0xe598) = 0;
      *(undefined8 *)(param_1 + 0xe5a0) = 0;
      *(undefined8 *)(param_1 + 0xe5a8) = 0;
      *(undefined8 *)(param_1 + 0xe5b0) = 0;
      *(undefined8 *)(param_1 + 0xe5b8) = 0;
      *(undefined8 *)(param_1 + 0xe5c0) = 0;
      *(undefined8 *)(param_1 + 0xe5c8) = 0;
      *(undefined8 *)(param_1 + 0xe5d0) = 0;
      *(undefined8 *)(param_1 + 0xe5d8) = 0;
      *(undefined8 *)(param_1 + 0xe5e0) = 0;
      *(undefined8 *)(param_1 + 0xe5e8) = 0;
      *(undefined8 *)(param_1 + 0xe5f0) = 0;
      *(undefined8 *)(param_1 + 0xe5f8) = 0;
      *(undefined8 *)(param_1 + 0xe600) = 0;
      *(undefined8 *)(param_1 + 0xe608) = 0;
      *(undefined8 *)(param_1 + 0xe610) = 0;
      *(undefined8 *)(param_1 + 0xe618) = 0;
      *(undefined8 *)(param_1 + 0xe620) = 0;
      *(undefined8 *)(param_1 + 0xe628) = 0;
      *(undefined8 *)(param_1 + 0xe630) = 0;
      uVar4 = 0xfe;
      *(undefined8 *)(param_1 + 0xe638) = 0;
      uVar11 = 0x100;
      *(undefined8 *)(param_1 + 0xe640) = 0;
      *(undefined8 *)(param_1 + 0xe648) = 0;
      *(undefined8 *)(param_1 + 0xe650) = 0;
      *(undefined8 *)(param_1 + 0xe658) = 0;
      *(undefined8 *)(param_1 + 0xe660) = 0;
      *(undefined8 *)(param_1 + 0xe668) = 0;
      *(undefined8 *)(param_1 + 0xe670) = 0;
      *(undefined8 *)(param_1 + 59000) = 0;
      *(undefined8 *)(param_1 + 0xe680) = 0;
      *(undefined8 *)(param_1 + 0xe688) = 0;
      *(undefined8 *)(param_1 + 0xe690) = 0;
      *(undefined8 *)(param_1 + 0xe698) = 0;
      *(undefined8 *)(param_1 + 0xe6a0) = 0;
      *(undefined8 *)(param_1 + 0xe6a8) = 0;
      *(undefined8 *)(param_1 + 0xe6b0) = 0;
      *(undefined8 *)(param_1 + 0xe6b8) = 0;
      *(undefined8 *)(param_1 + 0xe6c0) = 0;
      *(undefined8 *)(param_1 + 0xe6c8) = 0;
      *(undefined8 *)(param_1 + 0xe6d0) = 0;
      *(undefined8 *)(param_1 + 0xe6d8) = 0;
      *(undefined8 *)(param_1 + 0xe6e0) = 0;
      *(undefined8 *)(param_1 + 0xe6e8) = 0;
      *(undefined8 *)(param_1 + 0xe6f0) = 0;
      *(undefined8 *)(param_1 + 0xe6f8) = 0;
      *(undefined8 *)(param_1 + 0xe700) = 0;
      *(undefined8 *)(param_1 + 0xe708) = 0;
      *(undefined8 *)(param_1 + 0xe710) = 0;
      *(undefined8 *)(param_1 + 0xe718) = 0;
      *(undefined8 *)(param_1 + 0xe720) = 0;
      *(undefined8 *)(param_1 + 0xe728) = 0;
      *(undefined8 *)(param_1 + 0xe730) = 0;
      *(undefined8 *)(param_1 + 0xe738) = 0;
      *(undefined8 *)(param_1 + 0xe740) = 0;
      *(undefined8 *)(param_1 + 0xe748) = 0;
      *(undefined8 *)(param_1 + 0xe750) = 0;
      *(undefined8 *)(param_1 + 0xe758) = 0;
      *(undefined8 *)(param_1 + 0xe760) = 0;
      *(undefined8 *)(param_1 + 0xe768) = 0;
      *(undefined8 *)(param_1 + 0xe770) = 0;
      *(undefined8 *)(param_1 + 0xe778) = 0;
      *(undefined8 *)(param_1 + 0xe780) = 0;
      *(undefined8 *)(param_1 + 0xe788) = 0;
      *(undefined8 *)(param_1 + 0xe790) = 0;
      *(undefined8 *)(param_1 + 0xe798) = 0;
      *(undefined8 *)(param_1 + 0xe7a0) = 0;
      *(undefined8 *)(param_1 + 0xe7a8) = 0;
      *(undefined8 *)(param_1 + 0xe7b0) = 0;
      *(undefined8 *)(param_1 + 0xe7b8) = 0;
      *(undefined8 *)(param_1 + 0xe7c0) = 0;
      *(undefined8 *)(param_1 + 0xe7c8) = 0;
      *(undefined8 *)(param_1 + 0xe7d0) = 0;
      *(undefined8 *)(param_1 + 0xe7d8) = 0;
      if (*(char *)(param_1 + 0xe460) == '\0') {
        uVar4 = 0x40;
        uVar11 = 0x40;
      }
      *(undefined2 *)(param_1 + 0xe466) = uVar4;
      *(undefined2 *)(param_1 + 0xe462) = uVar11;
      *(undefined2 *)(param_1 + 0xe464) = 0x100;
      *(uint *)(param_1 + 0xe438) = ~(*(uint *)(lVar14 + 0x5b0) >> 4) & 1;
      *(undefined4 *)(param_1 + 0xd918) = 180000000;
      SendAndWaitDCMD(param_1,0x2010100,param_2);
      if (*(char *)(param_1 + 0x89) != '\0') {
LAB_140006486:
        local_34 = *(undefined1 *)(param_1 + 0xe46d);
        local_38 = *(undefined1 *)(param_1 + 0xe460);
        local_37 = *(undefined1 *)(param_1 + 0xe45a);
        local_36 = *(undefined1 *)(param_1 + 0xe46c);
        local_35 = *(undefined1 *)(param_1 + 0xe8ad);
        local_33 = *(undefined1 *)(param_1 + 0xe438);
        local_30 = *(undefined2 *)(param_1 + 0xe46a);
        local_32 = *(undefined2 *)(param_1 + 0xe468);
        local_2e = *(undefined2 *)(param_1 + 0xe462);
        local_2c = *(undefined2 *)(param_1 + 0xe464);
        if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x183) != 0)) {
          RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x183,&local_38,0xe,0,
                      param_2);
        }
        return 1;
      }
      if (*(char *)(param_1 + 0xe46c) != '\0') {
        *(undefined4 *)(param_1 + 0xd954) = 0;
        *(undefined4 *)(param_1 + 0xd918) = 180000000;
        uVar7 = SendAndWaitDCMD(param_1,0x200e102,param_2);
        if ((char)uVar7 == '\0') goto LAB_140006590;
        *(undefined4 *)(param_1 + 0xd954) = 1;
        IssueDCMD(param_1,0x200e102,'\0');
      }
      uVar7 = SendAndWaitDCMD(param_1,0x1020100,param_2);
      if ((char)uVar7 != '\0') {
        *(undefined4 *)(param_1 + 0xd918) = 180000000;
        uVar7 = SendAndWaitDCMD(param_1,0x1040100,param_2);
        if ((char)uVar7 != '\0') {
          if ((*(char *)(param_1 + 0xe46d) != '\0') && (*(char *)(param_1 + 0xe472) != '\0')) {
            SendAndWaitDCMD(param_1,0x1200100,param_2);
          }
          SendAndWaitDCMD(param_1,0x1200500,param_2);
          if (*(char *)(param_1 + 0xd928) == '\0') {
            MPT_UpdateReplyQueue(param_1);
          }
          else {
            *(undefined4 *)(param_1 + 0xd92c) = 0;
            *(undefined4 *)(param_1 + 0xd918) = 180000000;
            uVar7 = SendAndWaitDCMD(param_1,0x300e101,param_2);
            if ((char)uVar7 == '\0') goto LAB_140006590;
            MPT_UpdateReplyQueue(param_1);
            *(undefined4 *)(param_1 + 0xd92c) = 1;
            IssueDCMD(param_1,0x300e101,'\0');
            if ((*(char *)(param_1 + 0xeb50) != '\0') &&
               ((*(uint *)(param_1 + 0xeb54) & 0x198) != 0)) {
              RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x198,(undefined1 *)0x0
                          ,0,0,param_2);
            }
          }
          if (*(int *)(param_1 + 0x92c4) < 1) {
            *(undefined1 *)(param_1 + 0xd305) = 1;
            IssueDCMD(param_1,0x1040500,'\0');
            if ((*(char *)(param_1 + 0xeb50) != '\0') &&
               ((*(uint *)(param_1 + 0xeb54) & 0x199) != 0)) {
              RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x199,(undefined1 *)0x0
                          ,0,0,param_2);
            }
            *(undefined1 *)(param_1 + 0xd305) = 0;
            lVar14 = 0;
            lVar10 = 0;
            puVar12 = (undefined1 *)(param_1 + 0xec88);
            do {
              lVar14 = lVar14 + 0x180;
              *(undefined4 *)(*(longlong *)(param_1 + 0xd818) + -0x17c + lVar14) = 0x76543210;
              *(undefined4 *)(*(longlong *)(param_1 + 0xd820) + -0x98 + lVar10 + 0xa0) = 0x76543210;
              *puVar12 = 8;
              lVar3 = *(longlong *)(param_1 + 0xd820);
              *(undefined4 *)(lVar10 + lVar3) = 0;
              *(undefined4 *)(lVar10 + 4 + lVar3) = 1;
              lVar13 = lVar13 + -1;
              lVar10 = lVar10 + 0xa0;
              puVar12 = puVar12 + 1;
            } while (lVar13 != 0);
            *(undefined2 *)(param_1 + 0xd308) = *(undefined2 *)(param_1 + 0xe462);
            goto LAB_140006486;
          }
          uVar7 = SetDeadAdapter(param_1,0x60,param_2,0);
        }
      }
    }
  }
  else if ((*(char *)(param_1 + 0xeb50) != '\0') &&
          (uVar7 = (ulonglong)*(uint *)(param_1 + 0xeb54),
          (*(uint *)(param_1 + 0xeb54) & 0x2a4) != 0)) {
    uVar15 = 0x2a4;
LAB_140006567:
    uVar7 = RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),uVar15,(undefined1 *)0x0,
                        0,0,param_2);
  }
LAB_140006590:
  return uVar7 & 0xffffffffffffff00;
}



===== MegaSASInitialize @ 1400065c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 MegaSASInitialize(longlong param_1)

{
  ulonglong *puVar1;
  int *piVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  byte bVar7;
  ulonglong uVar8;
  longlong lVar9;
  uint uVar10;
  ulonglong uVar11;
  ushort uVar12;
  undefined1 auStackY_78 [32];
  undefined4 local_38 [2];
  ushort local_30 [8];
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_78;
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  local_30[4] = 0;
  local_30[5] = 0;
  local_30[6] = 0;
  local_30[7] = 0;
  if (*(char *)(param_1 + 0x89) != '\0') {
    *(uint *)(param_1 + 0xd810) = *(uint *)(param_1 + 0xd810) & 0xffffffef;
    *(undefined1 *)(param_1 + 0xd910) = 0;
    uVar6 = Fusion_EnableInterrupt(param_1);
    goto LAB_140006a6d;
  }
  if ((*(char *)(param_1 + 0xd858) != '\0') && (*(char *)(param_1 + 0xd85a) != '\0')) {
    iVar4 = StorPortExtendedFunction(0xd,param_1,0,param_1 + 0xd838);
    iVar5 = StorPortExtendedFunction(0xd,param_1,1,param_1 + 0xd838);
    if ((iVar4 == 0) && (iVar5 == 0)) {
LAB_1400066b1:
      if (iVar5 == -0x3efffff9) goto LAB_1400066b9;
    }
    else {
      *(undefined1 *)(param_1 + 0xd85a) = 0;
      *(undefined1 *)(param_1 + 0xeb68) = 0;
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x29d) != 0)) {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x29d,(undefined1 *)0x0,0,0,2
                   );
      }
      if (iVar4 != -0x3efffff9) goto LAB_1400066b1;
LAB_1400066b9:
      *(undefined1 *)(param_1 + 0xd858) = 0;
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x29c) != 0)) {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x29c,(undefined1 *)0x0,0,0,2
                   );
      }
    }
    *(undefined4 *)(param_1 + 0xd864) = 0x28;
    *(undefined4 *)(param_1 + 0xd860) = 5;
    iVar4 = StorPortExtendedFunction(0xe,param_1,1,param_1 + 0xd860);
    if (iVar4 != 0) {
      *(undefined1 *)(param_1 + 0xd85a) = 0;
      *(undefined1 *)(param_1 + 0xeb68) = 0;
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x29e) != 0)) {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x29e,(undefined1 *)0x0,0,0,2
                   );
      }
    }
    if (*(char *)(param_1 + 0xd85a) != '\0') {
      uVar10 = *(uint *)(param_1 + 0xd868) & 1;
      iVar4 = StorPortExtendedFunction(0xd,param_1,0x7f,param_1 + 0xd838);
      if (((((*(uint *)(param_1 + 0xd868) & 0xc) == 0) || (*(char *)(param_1 + 0xeb68) == '\0')) ||
          (*(void **)(param_1 + 0xeb80) == (void *)0x0)) || (iVar4 != 0)) {
        *(undefined1 *)(param_1 + 0xeb68) = 0;
        if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x29f) != 0)) {
          RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x29f,(undefined1 *)0x0,0,0
                      ,2);
        }
      }
      else {
        *(undefined4 *)(param_1 + 0xd870) = 0;
        *(undefined4 *)(param_1 + 0xd874) = 0x7f;
        memset(*(void **)(param_1 + 0xeb80),0,0x800);
        uVar10 = uVar10 | 0xc;
        *(undefined8 *)(param_1 + 0xd880) = *(undefined8 *)(param_1 + 0xeb80);
      }
      *(uint *)(param_1 + 0xd868) = uVar10;
      iVar4 = StorPortExtendedFunction(0xe,param_1,0,param_1 + 0xd860);
      if (iVar4 == 0) {
        if (*(char *)(param_1 + 0xeb68) != '\0') {
          uVar10 = 0;
          lVar9 = 0;
          do {
            uVar8 = 0;
            puVar1 = (ulonglong *)(lVar9 + *(longlong *)(param_1 + 0xeb80));
            if (*(uint *)(param_1 + 0xeb6c) != 0) {
              do {
                if ((*(short *)(uVar8 * 0x38 + 0x10 + *(longlong *)(param_1 + 0xeb88)) ==
                     (short)puVar1[1]) &&
                   ((*puVar1 & *(ulonglong *)(uVar8 * 0x38 + 8 + *(longlong *)(param_1 + 0xeb88)))
                    != 0)) {
                  uVar12 = local_30[uVar8];
                  *(uint *)(*(longlong *)(param_1 + 0xeb98 + uVar8 * 8) + (ulonglong)uVar12 * 4) =
                       uVar10;
                  local_30[uVar8] = uVar12 + 1;
                  break;
                }
                bVar7 = (char)uVar8 + 1;
                uVar8 = (ulonglong)bVar7;
              } while ((uint)bVar7 < *(uint *)(param_1 + 0xeb6c));
            }
            bVar7 = (char)uVar10 + 1;
            uVar10 = (uint)bVar7;
            lVar9 = lVar9 + 0x10;
          } while (bVar7 < 0x80);
          uVar12 = 0;
          if (*(int *)(param_1 + 0xeb6c) != 0) {
            do {
              uVar11 = (ulonglong)uVar12;
              bVar3 = false;
              uVar8 = 0;
              bVar7 = 0;
              piVar2 = *(int **)(param_1 + 0xeb98 + uVar11 * 8);
              iVar4 = *piVar2;
              while ((iVar4 != -0x21524111 && (bVar7 = (byte)uVar8, bVar7 < 0x80))) {
                if ((*(int *)(param_1 + 0xeb78) - 1U < (uint)piVar2[uVar8]) && (!bVar3)) {
                  *(byte *)(uVar11 + 0xec38 + param_1) = bVar7;
                  bVar3 = true;
                  if (bVar7 < 7) {
                    *(undefined1 *)(param_1 + 0xeb68) = 0;
                  }
                }
                bVar7 = bVar7 + 1;
                uVar8 = (ulonglong)bVar7;
                iVar4 = piVar2[uVar8];
              }
              uVar12 = uVar12 + 1;
              *(byte *)(param_1 + 0xec80 + uVar11) = bVar7;
            } while ((uint)uVar12 < *(uint *)(param_1 + 0xeb6c));
          }
          if (*(char *)(param_1 + 0xeb68) != '\0') {
            *(undefined1 *)(param_1 + 0xeb6a) = 1;
          }
        }
      }
      else {
        *(undefined1 *)(param_1 + 0xd85a) = 0;
        if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x2a0) != 0)) {
          RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x2a0,(undefined1 *)0x0,0,0
                      ,2);
        }
      }
    }
  }
  local_38[0] = 0;
  StorPortNotification(0x1000,param_1,InitDPC,local_38);
  uVar6 = StartBGTimer(param_1);
LAB_140006a6d:
  return CONCAT71((int7)((ulonglong)uVar6 >> 8),1);
}



===== TimeForFwareReadyInitWithRetry @ 140006a90 =====

void TimeForFwareReadyInitWithRetry(longlong param_1)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  
  uVar2 = CheckFirmwareReady(param_1);
  if ((char)uVar2 == '\0') {
    if ((-1 < *(int *)(param_1 + 0xd918)) &&
       ((*(uint *)(param_1 + 0xd2e0) & 0xf0000000) != 0xf0000000)) {
      iVar1 = *(int *)(param_1 + 0xd918) + -250000;
      goto LAB_140006af4;
    }
    uVar3 = CheckResetRetries(param_1,2);
    if ((char)uVar3 == '\0') {
      SetDeadAdapter(param_1,0x12,2,0);
      return;
    }
  }
  else {
    uVar2 = InitializeAdapter(param_1,2);
    if ((char)uVar2 != '\0') {
      *(uint *)(param_1 + 0xd810) = *(uint *)(param_1 + 0xd810) & 0xffffffef;
      *(undefined1 *)(param_1 + 0xd910) = 0;
      Fusion_EnableInterrupt(param_1);
      DoResumeInput(param_1,2,0);
      if (*(char *)(param_1 + 0x89) == '\0') {
        iVar1 = StorPortExtendedFunction(0x20,param_1,param_1 + 0xe8b8);
        if (iVar1 == 0) {
          if ((*(char *)(param_1 + 0xeb50) == '\0') ||
             ((*(uint *)(param_1 + 0xeb54) & 0x200089) == 0)) goto LAB_140006c1c;
          uVar4 = 0x200089;
        }
        else {
          *(undefined8 *)(param_1 + 0xe8b8) = 0;
          if ((*(char *)(param_1 + 0xeb50) == '\0') ||
             ((*(uint *)(param_1 + 0xeb54) & 0x200086) == 0)) goto LAB_140006c1c;
          uVar4 = 0x200086;
        }
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),uVar4,(undefined1 *)0x0,0,0,2
                   );
      }
LAB_140006c1c:
      StartBGTimer(param_1);
      return;
    }
    uVar3 = CheckResetRetries(param_1,2);
    if ((char)uVar3 == '\0') {
      SetDeadAdapter(param_1,9,2,0);
      return;
    }
  }
  iVar1 = 600000000;
LAB_140006af4:
  *(int *)(param_1 + 0xd918) = iVar1;
  StorPortNotification(6,param_1,TimeForFwareReadyInitWithRetry,250000);
  return;
}



===== WaitForFwareReadyWithRetry @ 140006c30 =====

undefined8 WaitForFwareReadyWithRetry(longlong param_1)

{
  char cVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  
  *(undefined4 *)(param_1 + 0xd918) = 180000000;
  *(undefined4 *)(param_1 + 0xd91c) = 30000000;
  uVar3 = CheckFirmwareReady(param_1);
  cVar1 = (char)uVar3;
  while( true ) {
    if (cVar1 != '\0') {
      return CONCAT71((int7)(uVar3 >> 8),1);
    }
    if (((*(int *)(param_1 + 0xd918) < 0) ||
        (uVar2 = *(uint *)(param_1 + 0xd2e0) & 0xf0000000, uVar3 = (ulonglong)uVar2,
        uVar2 == 0xf0000000)) || (*(int *)(param_1 + 0xd91c) < 1)) break;
    StorPortStallExecution(1000);
    *(int *)(param_1 + 0xd918) = *(int *)(param_1 + 0xd918) + -1000;
LAB_140006cb4:
    uVar3 = CheckFirmwareReady(param_1);
    cVar1 = (char)uVar3;
  }
  if (*(char *)(param_1 + 0xeb10) == '\0') {
    uVar3 = CheckResetRetries(param_1,2);
    if ((char)uVar3 != '\0') {
      *(undefined4 *)(param_1 + 0xd918) = 180000000;
      goto LAB_140006cb4;
    }
    if ((*(char *)(param_1 + 0xeb50) == '\0') ||
       (uVar3 = (ulonglong)*(uint *)(param_1 + 0xeb54), (*(uint *)(param_1 + 0xeb54) & 0x282) == 0))
    goto LAB_140006d30;
    uVar4 = 0x282;
  }
  else {
    if ((*(char *)(param_1 + 0xeb50) == '\0') ||
       (uVar3 = (ulonglong)*(uint *)(param_1 + 0xeb54), (*(uint *)(param_1 + 0xeb54) & 0x2a1) == 0))
    goto LAB_140006d30;
    uVar4 = 0x2a1;
  }
  uVar3 = RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),uVar4,(undefined1 *)0x0,0,0
                      ,2);
LAB_140006d30:
  return uVar3 & 0xffffffffffffff00;
}



===== WaitForInitializeWithRetry @ 140006d40 =====

undefined8 WaitForInitializeWithRetry(longlong param_1)

{
  char cVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  
  uVar3 = InitializeAdapter(param_1,2);
  cVar1 = (char)uVar3;
  while( true ) {
    if (cVar1 != '\0') {
      return CONCAT71((int7)(uVar3 >> 8),1);
    }
    uVar3 = CheckResetRetries(param_1,2);
    if ((char)uVar3 == '\0') break;
    *(undefined4 *)(param_1 + 0xd918) = 180000000;
    *(undefined4 *)(param_1 + 0xd91c) = 30000000;
    uVar3 = CheckFirmwareReady(param_1);
    cVar1 = (char)uVar3;
    while (cVar1 == '\0') {
      if (((*(int *)(param_1 + 0xd918) < 0) ||
          (uVar2 = *(uint *)(param_1 + 0xd2e0) & 0xf0000000, uVar3 = (ulonglong)uVar2,
          uVar2 == 0xf0000000)) || (*(int *)(param_1 + 0xd91c) < 1)) {
        if (*(char *)(param_1 + 0xeb10) == '\0') {
          uVar3 = CheckResetRetries(param_1,2);
          if ((char)uVar3 != '\0') {
            *(undefined4 *)(param_1 + 0xd918) = 180000000;
            goto LAB_140006df3;
          }
          if ((*(char *)(param_1 + 0xeb50) == '\0') ||
             (uVar3 = (ulonglong)*(uint *)(param_1 + 0xeb54),
             (*(uint *)(param_1 + 0xeb54) & 0x282) == 0)) goto LAB_140006e84;
          uVar4 = 0x282;
        }
        else {
          if ((*(char *)(param_1 + 0xeb50) == '\0') ||
             (uVar3 = (ulonglong)*(uint *)(param_1 + 0xeb54),
             (*(uint *)(param_1 + 0xeb54) & 0x2a1) == 0)) goto LAB_140006e84;
          uVar4 = 0x2a1;
        }
        uVar3 = RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),uVar4,
                            (undefined1 *)0x0,0,0,2);
        goto LAB_140006e84;
      }
      StorPortStallExecution(1000);
      *(int *)(param_1 + 0xd918) = *(int *)(param_1 + 0xd918) + -1000;
LAB_140006df3:
      uVar3 = CheckFirmwareReady(param_1);
      cVar1 = (char)uVar3;
    }
    uVar3 = InitializeAdapter(param_1,2);
    cVar1 = (char)uVar3;
  }
LAB_140006e84:
  return uVar3 & 0xffffffffffffff00;
}



===== AcquireIsrLocks @ 140006e90 =====

void AcquireIsrLocks(longlong param_1,byte param_2,int param_3)

{
  char *pcVar1;
  longlong lVar2;
  byte bVar3;
  ulonglong uVar4;
  bool bVar5;
  
  if (*(char *)(param_1 + 0x89) == '\0') {
    if (param_3 == 5) {
      lVar2 = *(longlong *)(param_1 + 0xeb08);
      if (*(char *)(lVar2 + (ulonglong)param_2) == '\0') {
        do {
          LOCK();
          bVar5 = *(int *)(param_1 + 0xeb04) == 0;
          if (bVar5) {
            *(int *)(param_1 + 0xeb04) = 1;
          }
          UNLOCK();
        } while (!bVar5);
        lVar2 = *(longlong *)(param_1 + 0xeb08);
      }
      pcVar1 = (char *)((ulonglong)param_2 + lVar2);
      *pcVar1 = *pcVar1 + '\x01';
      return;
    }
    if (*(char *)(param_1 + 0xeb00) == '\0') {
      uVar4 = 0;
      if (*(char *)(param_1 + 0xd859) != '\0') {
        do {
          StorPortExtendedFunction(0xb,param_1,uVar4,param_1 + (uVar4 + 0x3a40) * 4);
          bVar3 = (char)uVar4 + 1;
          uVar4 = (ulonglong)bVar3;
        } while (bVar3 < *(byte *)(param_1 + 0xd859));
      }
      *(undefined1 *)(param_1 + 0xeb00) = 1;
    }
  }
  return;
}



===== FinishDeferedWork @ 140006f40 =====

void FinishDeferedWork(undefined8 param_1,longlong param_2)

{
  undefined8 *puVar1;
  uint *puVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  byte bVar6;
  ushort uVar7;
  ulonglong uVar8;
  byte bVar9;
  longlong *plVar10;
  uint uVar11;
  char cVar12;
  bool bVar13;
  undefined4 local_res10 [2];
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  cVar12 = '\0';
  *(undefined1 *)(param_2 + 0xd8d0) = 0;
  if (*(char *)(param_2 + 0xd90e) != '\0') {
    *(undefined2 *)(param_2 + 0xd8d2) = 0;
    *(undefined1 *)(param_2 + 0xd8d1) = 0;
    *(undefined4 *)(param_2 + 0xd8d8) = 0;
    *(undefined4 *)(param_2 + 0xd8e0) = 0;
    *(undefined1 *)(param_2 + 0xd8e4) = 0;
    *(undefined1 *)(param_2 + 0xd8d4) = 0;
    *(undefined1 *)(param_2 + 0xd8e6) = 0;
    *(undefined2 *)(param_2 + 0xd8e8) = 0;
    return;
  }
  local_28 = 0;
  local_20 = 0;
  local_18 = 0;
  local_10 = 0;
  StorPortNotification();
  if (*(char *)(param_2 + 0xd90c) == '\0') {
    if (*(char *)(param_2 + 0xd8d3) != '\0') {
      *(undefined1 *)(param_2 + 0xd8d3) = 0;
      StorPortStallExecution(1000);
      IssueDCMD(param_2,0x300e101,'\0');
    }
    if (*(char *)(param_2 + 0xd8d2) != '\0') {
      *(undefined1 *)(param_2 + 0xd8d2) = 0;
      IssueDCMD(param_2,0x1040500,'\0');
    }
    if (*(char *)(param_2 + 0xd8e8) != '\0') {
      *(undefined1 *)(param_2 + 0xd8e8) = 0;
      IssueDCMD(param_2,0x1040300,'\0');
    }
    if (*(char *)(param_2 + 0xd8d1) != '\0') {
      lVar4 = *(longlong *)(param_2 + 0xe8e0);
      puVar1 = (undefined8 *)(param_2 + 0xe848);
      local_res10[0] = 0;
      while (*(char *)(lVar4 + 0x20) == '\0') {
        lVar5 = *(longlong *)(lVar4 + 0x18);
        if (lVar5 == *(longlong *)(lVar4 + 0x10)) goto LAB_140007198;
        *puVar1 = 0;
        *(undefined8 *)(param_2 + 0xe850) = 0;
        *(undefined8 *)(param_2 + 0xe858) = 0;
        *(undefined8 *)(param_2 + 0xe860) = 0;
        *(undefined8 *)(param_2 + 0xe868) = 0;
        *(undefined8 *)(param_2 + 0xe870) = 0;
        *(undefined8 *)(param_2 + 0xe878) = 0;
        *(undefined8 *)(param_2 + 0xe880) = 0;
        *(undefined8 *)(param_2 + 0xe888) = 0;
        *(undefined4 *)puVar1 = 0x100;
        *(undefined4 *)(param_2 + 0xe84c) = 0x48;
        *(undefined4 *)(param_2 + 0xe870) = 4;
        *(longlong *)(param_2 + 0xe878) = lVar5;
        bVar13 = *(char *)(lVar5 + 8) == '\0';
        if (bVar13) {
          plVar10 = (longlong *)0x0;
        }
        else {
          plVar10 = (longlong *)(param_2 + 0xe898);
          *plVar10 = lVar5 + 0x10;
        }
        *(uint *)(param_2 + 0xe880) = (uint)!bVar13;
        *(longlong **)(param_2 + 0xe888) = plVar10;
        iVar3 = *(int *)(lVar5 + 4);
        if (iVar3 == 0x4004af00) {
          *(undefined4 *)(param_2 + 0xe868) = 0x4004af00;
        }
        else if (iVar3 == -0x7ffb50ff) {
          *(undefined4 *)(param_2 + 0xe868) = 0x8004af01;
        }
        else if (iVar3 == -0x3ffb50fe) {
          *(undefined4 *)(param_2 + 0xe868) = 0xc004af02;
        }
        StorPortExtendedFunction(0x10,param_2,puVar1,local_res10);
        if (*(ulonglong *)(lVar4 + 0x18) < (ulonglong)(*(undefined8 **)(param_2 + 0xe8e0))[1]) {
          *(ulonglong *)(lVar4 + 0x18) = *(ulonglong *)(lVar4 + 0x18) + 0x110;
        }
        else {
          *(undefined8 *)(lVar4 + 0x18) = **(undefined8 **)(param_2 + 0xe8e0);
        }
      }
      *(undefined1 *)(lVar4 + 0x20) = 0;
LAB_140007198:
      *(undefined1 *)(param_2 + 0xd8d1) = 0;
    }
    if (*(int *)(param_2 + 0xd8d8) == 1) {
      *(undefined4 *)(param_2 + 0xd8d8) = 2;
      **(undefined1 **)(param_2 + 0xe480) = 1;
      *(undefined4 *)(*(longlong *)(param_2 + 0xe480) + 4) = 0xb4;
      IssueDCMD(param_2,0x2010100,'\0');
    }
    if (*(int *)(param_2 + 0xd8e0) == 1) {
      *(undefined4 *)(param_2 + 0xd8e0) = 2;
      **(undefined1 **)(param_2 + 0xe478) = 1;
      *(undefined4 *)(*(longlong *)(param_2 + 0xe478) + 4) = 0xb4;
      IssueDCMD(param_2,0x1020100,'\0');
    }
    if (*(int *)(param_2 + 0xd8ec) == 1) {
      *(undefined4 *)(param_2 + 0xd8ec) = 2;
      **(undefined1 **)(param_2 + 0xe488) = 1;
      *(undefined4 *)(*(longlong *)(param_2 + 0xe488) + 4) = 0xb4;
      IssueDCMD(param_2,0x1200100,'\0');
    }
    if (*(char *)(param_2 + 0xd8f0) == '\x01') {
      *(undefined1 *)(param_2 + 0xd8f0) = 0;
      IssueDCMD(param_2,0x1200500,'\0');
    }
    if ((*(char *)(param_2 + 0xd8e4) != '\0') && (*(char *)(param_2 + 0xd8e5) == '\0')) {
      uVar8 = 0;
      do {
        bVar9 = 0;
        do {
          uVar11 = 1 << (bVar9 & 0x1f);
          if ((*(uint *)(param_2 + 0xe7e4 + uVar8 * 4) & uVar11) != 0) {
            *(byte *)(param_2 + 0xe844) = bVar9 + cVar12;
            IssueDCMD(param_2,0x2020000,'\0');
            puVar2 = (uint *)(param_2 + 0xe7e4 + uVar8 * 4);
            *puVar2 = *puVar2 & ~uVar11;
            goto LAB_1400072f6;
          }
          bVar9 = bVar9 + 1;
        } while (bVar9 < 0x20);
        cVar12 = cVar12 + ' ';
        bVar9 = (char)uVar8 + 1;
        uVar8 = (ulonglong)bVar9;
      } while (bVar9 < 8);
    }
LAB_1400072f6:
    if ((*(char *)(param_2 + 0xd8e6) != '\0') && (*(char *)(param_2 + 0xd8e7) == '\0')) {
      bVar9 = 0;
      do {
        uVar7 = 0;
        do {
          uVar11 = 1 << ((byte)uVar7 & 0x1f);
          if ((*(uint *)(param_2 + 0xe804 + (ulonglong)bVar9 * 4) & uVar11) != 0) {
            *(ushort *)(param_2 + 0xe846) = (ushort)bVar9 * 0x20 + uVar7;
            IssueDCMD(param_2,0x200e103,(7 < bVar9) + '\x01');
            puVar2 = (uint *)(param_2 + 0xe804 + (ulonglong)bVar9 * 4);
            *puVar2 = *puVar2 & ~uVar11;
            goto LAB_140007378;
          }
          bVar6 = (byte)uVar7 + 1;
          uVar7 = (ushort)bVar6;
        } while (bVar6 < 0x20);
        bVar9 = bVar9 + 1;
      } while (bVar9 < 0x10);
    }
LAB_140007378:
    if (*(char *)(param_2 + 0xd8d4) != '\0') {
      *(undefined1 *)(param_2 + 0xd8d4) = 0;
      IssueDCMD(param_2,0x200e102,'\0');
    }
    if (*(longlong *)(param_2 + 0x9220) != 0) {
      TryFlushingIoctl(param_2);
    }
    if (*(char *)(param_2 + 0xd830) != '\0') {
      TryFlushingGroups(param_2);
    }
  }
  if (*(char *)(param_2 + 0xd8e9) != '\0') {
    *(undefined1 *)(param_2 + 0xd8e9) = 0;
    IssueTaskManagement(param_2);
  }
  StorPortNotification(0x1004,param_2,&local_28);
  return;
}



===== IncrementWithWrap @ 140007410 =====

longlong IncrementWithWrap(longlong param_1,ulonglong param_2)

{
  if (param_2 < (ulonglong)(*(longlong **)(param_1 + 0xe8e0))[1]) {
    return param_2 + 0x110;
  }
  return **(longlong **)(param_1 + 0xe8e0);
}



===== InitDPC @ 140007430 =====

undefined8 InitDPC(longlong param_1)

{
  undefined8 uVar1;
  
  *(undefined8 *)(param_1 + 0xd888) = 0;
  *(undefined8 *)(param_1 + 0xd890) = 0;
  *(undefined8 *)(param_1 + 0xd898) = 0;
  *(undefined8 *)(param_1 + 0xd8a0) = 0;
  *(undefined8 *)(param_1 + 0xd8a8) = 0;
  *(undefined8 *)(param_1 + 0xd8b0) = 0;
  *(undefined8 *)(param_1 + 0xd8b8) = 0;
  *(undefined8 *)(param_1 + 0xd8c0) = 0;
  *(undefined8 *)(param_1 + 0xd8c8) = 0;
  StorPortNotification(0x1001,param_1,(undefined8 *)(param_1 + 0xd888),FinishDeferedWork);
  *(uint *)(param_1 + 0xd810) = *(uint *)(param_1 + 0xd810) & 0xffffffef;
  *(undefined1 *)(param_1 + 0xd910) = 0;
  uVar1 = Fusion_EnableInterrupt(param_1);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== LegacyInterrupts @ 1400074a0 =====

undefined8 LegacyInterrupts(longlong param_1)

{
  byte bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  
  if ((*(char *)(param_1 + 0xd858) == '\0') || (*(char *)(param_1 + 0x89) == '\0')) {
    bVar1 = Fusion_CheckInterrupt(param_1);
    if (bVar1 == 0) {
      return CONCAT71(extraout_var,bVar1);
    }
    if (((bVar1 & 2) != 0) && (uVar2 = CheckFirmwareFault(param_1,5,0), (char)uVar2 != '\0')) {
      return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
    }
  }
  uVar2 = MessageInterrupts(param_1,0);
  return uVar2;
}



===== MessageInterrupts @ 140007500 =====

undefined8 MessageInterrupts(longlong param_1,uint param_2)

{
  int *piVar1;
  char cVar2;
  byte bVar3;
  longlong *plVar4;
  ushort uVar5;
  uint *in_RAX;
  undefined8 uVar6;
  int iVar7;
  ushort *puVar8;
  ushort uVar9;
  ulonglong uVar10;
  longlong lVar11;
  int *piVar12;
  uint uVar13;
  longlong lVar14;
  uint *puVar15;
  ushort uVar16;
  undefined1 uVar17;
  short local_res10;
  undefined4 local_res18 [2];
  ushort *local_res20;
  
  uVar17 = (undefined1)param_2;
  if (*(int *)(param_1 + 0xd810) == 0) {
    puVar8 = (ushort *)(((ulonglong)param_2 + 0xd9a) * 0x10 + param_1);
    local_res10 = 0;
    uVar16 = 0;
    uVar10 = (ulonglong)*puVar8;
    in_RAX = *(uint **)(puVar8 + 4);
    puVar15 = in_RAX + uVar10 * 2;
    local_res20 = puVar8;
    if (in_RAX[uVar10 * 2] != 0xffffffff) {
      do {
        uVar5 = (ushort)uVar10;
        if (puVar15[1] == 0xffffffff) break;
        uVar9 = *(ushort *)((longlong)puVar15 + 2);
        uVar13 = uVar9 - 1;
        plVar4 = *(longlong **)((ulonglong)uVar13 * 8 + *(longlong *)(param_1 + 0x208));
        lVar11 = (ulonglong)uVar9 * 0x100 + *(longlong *)(param_1 + 0xd998);
        cVar2 = *(char *)(lVar11 + 3);
        if (cVar2 == '\0') {
          if ((short)((ulonglong)*(undefined8 *)(lVar11 + 0x70) >> 0x20) == 0) {
            if ((((char)((ulonglong)*(undefined8 *)(lVar11 + 0x70) >> 0x38) != '\0') ||
                ((*(char *)(lVar11 + 0x40) - 8U & 0x5d) != 0)) ||
               (*(char *)((longlong)plVar4 + 0x36) != '\x01')) goto LAB_14000766b;
            iVar7 = 2;
          }
          else {
            iVar7 = 3;
          }
        }
        else if (cVar2 == -0xf) {
LAB_14000766b:
          iVar7 = 1;
        }
        else if (cVar2 == '\x01') {
          iVar7 = 5;
        }
        else {
          iVar7 = 0;
          if (cVar2 == -0x10) {
            iVar7 = 4;
          }
        }
        if (iVar7 == 1) {
          piVar12 = (int *)plVar4[0x16];
          if (piVar12 != (int *)0x0) {
            LOCK();
            *piVar12 = *piVar12 + -1;
            UNLOCK();
          }
          *(undefined4 *)(plVar4 + 0xe) = *(undefined4 *)(lVar11 + 0x1c);
          CompleteScsiRequest(param_1,plVar4,*(char *)(lVar11 + 0x77),*(char *)(lVar11 + 0x76),
                              uVar13,5,uVar17);
LAB_14000784c:
          puVar8 = local_res20;
        }
        else {
          if (iVar7 == 2) {
            piVar12 = (int *)plVar4[0x16];
            if (piVar12 != (int *)0x0) {
              LOCK();
              *piVar12 = *piVar12 + -1;
              UNLOCK();
            }
            lVar11 = 0x92e0;
            if (*(char *)((longlong)plVar4 + 9) != '\0') {
              lVar11 = 0xb2e0;
            }
            LOCK();
            piVar12 = (int *)((ulonglong)*(byte *)(plVar4 + 1) * 0x20 + lVar11 + param_1);
            *piVar12 = *piVar12 + -1;
            UNLOCK();
            *(undefined8 *)((ulonglong)uVar13 * 8 + *(longlong *)(param_1 + 0x208)) = 0;
            lVar11 = (ulonglong)*(byte *)((longlong)plVar4 + 0xc6) * 0x240;
            bVar3 = *(byte *)(lVar11 + 0x440 + param_1);
            *(byte *)(lVar11 + 0x440 + param_1) = bVar3 + 1;
            *(short *)(param_1 +
                      (((ulonglong)*(byte *)((longlong)plVar4 + 0xc6) + 1) * 0x120 +
                      (ulonglong)bVar3) * 2) = (short)uVar13;
            StorPortNotification(0,param_1,*plVar4);
            goto LAB_14000784c;
          }
          if (iVar7 == 3) {
            if (*(char *)((longlong)plVar4 + 0x33) != '\0') {
              MR_CompleteR1FPWRequest(param_1,plVar4,uVar9,5);
              goto LAB_14000784c;
            }
            *(undefined1 *)((longlong)plVar4 + 0x33) = 1;
          }
          else {
            if (iVar7 == 4) {
              Process_MfiPthr(param_1,plVar4,lVar11,uVar9,uVar17);
              goto LAB_14000784c;
            }
            if (iVar7 == 5) {
              *(undefined4 *)(plVar4 + 0xe) = *(undefined4 *)(lVar11 + 0x1c);
              _guard_check_icall();
              CompleteScsiRequest(param_1,plVar4,*(char *)(lVar11 + 0x77),*(char *)(lVar11 + 0x76),
                                  uVar13,5,uVar17);
              *(undefined8 *)(param_1 + 0xe4b8) = 0;
              *(undefined4 *)(param_1 + 0xe4b0) = 0;
              DoResumeInput(param_1,5,uVar17);
              puVar8 = local_res20;
              if (*(longlong *)(param_1 + 0xe4c0 + (ulonglong)*(byte *)(param_1 + 0xe7e0) * 8) != 0)
              {
                *(undefined1 *)(param_1 + 0xd8e9) = 1;
                *(undefined1 *)(param_1 + 0xd8d0) = 1;
              }
            }
          }
        }
        uVar16 = uVar16 + 1;
        local_res10 = local_res10 + 1;
        puVar15[0] = 0xffffffff;
        puVar15[1] = 0xffffffff;
        if (100 < uVar16) {
          *puVar8 = uVar5;
          uVar16 = 0;
          uVar13 = (uint)uVar10;
          if ((*(char *)(param_1 + 0x89) == '\0') && (*(char *)(param_1 + 0xd858) != '\0')) {
            if (*(byte *)(param_1 + 0xd859) < 0x11) {
              **(uint **)(param_1 + 0xe3b8) = (param_2 & 0xf) << 0x18 | uVar13;
            }
            else {
              **(uint **)(param_1 + 0xe3b8 + (ulonglong)(param_2 >> 3) * 8) =
                   (param_2 & 7) << 0x18 | uVar13;
            }
          }
          else {
            *(uint *)(*(longlong *)(param_1 + 0x80) + 0x6c) = param_2 << 0x18 | uVar13;
          }
          LOCK();
          UNLOCK();
        }
        uVar9 = uVar5 + 1;
        uVar5 = 0;
        if ((uint)uVar9 < *(uint *)(param_1 + 0xd808)) {
          uVar5 = uVar9;
        }
        uVar10 = (ulonglong)uVar5;
        in_RAX = *(uint **)(puVar8 + 4);
        puVar15 = in_RAX + uVar10 * 2;
      } while (in_RAX[uVar10 * 2] != 0xffffffff);
      if (local_res10 != 0) {
        *puVar8 = uVar5;
        if ((*(char *)(param_1 + 0x89) == '\0') && (*(char *)(param_1 + 0xd858) != '\0')) {
          if (*(byte *)(param_1 + 0xd859) < 0x11) {
            in_RAX = *(uint **)(param_1 + 0xe3b8);
            *in_RAX = (param_2 & 0xf) << 0x18 | (uint)uVar5;
          }
          else {
            in_RAX = *(uint **)(param_1 + 0xe3b8 + (ulonglong)(param_2 >> 3) * 8);
            *in_RAX = (param_2 & 7) << 0x18 | (uint)uVar5;
          }
        }
        else {
          in_RAX = *(uint **)(param_1 + 0x80);
          in_RAX[0x1b] = param_2 << 0x18 | (uint)uVar5;
        }
        LOCK();
        UNLOCK();
        if (*(char *)(param_1 + 0xd90c) != '\0') {
          uVar13 = 0;
          piVar12 = (int *)(param_1 + 0x92e0);
          lVar11 = 0xff;
          do {
            lVar14 = lVar11;
            piVar1 = piVar12 + 0x800;
            iVar7 = *piVar12;
            piVar12 = piVar12 + 8;
            uVar13 = uVar13 + *piVar1 + iVar7;
            lVar11 = lVar14 + -1;
          } while (lVar11 != 0);
          in_RAX = (uint *)(ulonglong)*(uint *)(param_1 + 0x92c0);
          if (uVar13 == *(uint *)(param_1 + 0x92c0)) {
            *(uint *)(param_1 + 0xd80c) = *(uint *)(param_1 + 0xd80c) & 0xfffffffd;
            *(undefined1 *)(param_1 + 0xd90c) = 0;
            in_RAX = (uint *)DoResumeInput(param_1,(int)lVar14 + 4,uVar17);
          }
        }
        if ((*(char *)(param_1 + 0xd8d0) != '\0') && (*(char *)(param_1 + 0x89) == '\0')) {
          local_res18[0] = 0;
          in_RAX = (uint *)StorPortNotification
                                     (0x1002,param_1,param_1 + 0xd888,param_1,param_1,local_res18);
        }
      }
    }
  }
  else if ((*(char *)(param_1 + 0xeb50) != '\0') &&
          (in_RAX = (uint *)(ulonglong)*(uint *)(param_1 + 0xeb54),
          (*(uint *)(param_1 + 0xeb54) & 0x19a) != 0)) {
    uVar6 = RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x19a,(undefined1 *)0x0,0
                        ,uVar17,5);
    return CONCAT71((int7)((ulonglong)uVar6 >> 8),1);
  }
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}



===== Process_MfiPthr @ 140007a60 =====

void Process_MfiPthr(longlong param_1,longlong *param_2,longlong param_3,ushort param_4,
                    undefined1 param_5)

{
  int *piVar1;
  byte bVar2;
  longlong lVar3;
  undefined1 uVar4;
  longlong lVar5;
  
  lVar3 = *param_2;
  if (lVar3 == 0) {
    if (((char)param_2[0x20] == '\x05') && (*(uint *)(param_1 + 0xd804) < (uint)param_4)) {
      CompleteDCMD(param_1,(longlong)(param_2 + 0x20),'\0',5,param_5);
    }
  }
  else {
    if (*(char *)(lVar3 + 2) == '\x02') {
      if (*(int *)((longlong)param_2 + 0x7c) == 0x200) {
        HbaFwReloadFsm(param_1,'\x01',(longlong)(param_2 + 0x20),param_5,param_2,5);
      }
      else {
        CompleteIoctlRequest(param_1,param_2,param_4 - 1,5,param_5);
      }
    }
    if (*(char *)(lVar3 + 2) == '\0') {
      *(undefined4 *)(param_2 + 0xe) = *(undefined4 *)((longlong)param_2 + 0x114);
      CompleteScsiRequest(param_1,param_2,*(char *)(param_3 + 0x77),*(char *)(param_3 + 0x76),
                          param_4 - 1,5,param_5);
    }
    else if (*(char *)(lVar3 + 2) == '\b') {
      if (*(char *)((longlong)param_2 + 0x102) == '\0') {
        *(undefined1 *)(lVar3 + 4) = 0;
        uVar4 = 1;
      }
      else {
        uVar4 = 4;
      }
      *(undefined1 *)(lVar3 + 3) = uVar4;
      *(undefined8 *)(*(longlong *)(param_1 + 0x208) + (ulonglong)(param_4 - 1) * 8) = 0;
      lVar5 = (ulonglong)*(byte *)((longlong)param_2 + 0xc6) * 0x240;
      bVar2 = *(byte *)(lVar5 + 0x440 + param_1);
      *(byte *)(lVar5 + 0x440 + param_1) = bVar2 + 1;
      *(short *)(param_1 +
                (((ulonglong)*(byte *)((longlong)param_2 + 0xc6) + 1) * 0x120 + (ulonglong)bVar2) *
                2) = (short)(param_4 - 1);
      lVar5 = 0x92e0;
      if (*(char *)((longlong)param_2 + 9) != '\0') {
        lVar5 = 0xb2e0;
      }
      LOCK();
      piVar1 = (int *)((ulonglong)*(byte *)(param_2 + 1) * 0x20 + lVar5 + param_1);
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (((char)param_2[0x12] != '\0') && ((char)param_2[0x20] == '\x05')) {
        LOCK();
        *(int *)(param_1 + 0x92c0) = *(int *)(param_1 + 0x92c0) + -1;
        UNLOCK();
      }
      StorPortNotification(0,param_1,lVar3);
    }
  }
  return;
}



===== ReleaseIsrLocks @ 140007c30 =====

ulonglong ReleaseIsrLocks(longlong param_1,byte param_2,int param_3)

{
  char *pcVar1;
  uint uVar2;
  ulonglong in_RAX;
  ulonglong uVar3;
  byte bVar4;
  
  if (*(char *)(param_1 + 0x89) == '\0') {
    if (param_3 == 5) {
      pcVar1 = (char *)(*(longlong *)(param_1 + 0xeb08) + (ulonglong)param_2);
      *pcVar1 = *pcVar1 + -1;
      in_RAX = *(ulonglong *)(param_1 + 0xeb08);
      if (*(char *)(param_2 + in_RAX) == '\0') {
        uVar3 = 1;
        LOCK();
        uVar2 = *(uint *)(param_1 + 0xeb04);
        if (uVar2 == 1) {
          *(uint *)(param_1 + 0xeb04) = 0;
        }
        else {
          uVar3 = (ulonglong)uVar2;
        }
        UNLOCK();
        return uVar3;
      }
    }
    else {
      bVar4 = *(byte *)(param_1 + 0xd859);
      while (bVar4 = bVar4 - 1, bVar4 < 0x80) {
        in_RAX = StorPortExtendedFunction
                           (0xc,param_1,bVar4,
                            *(undefined4 *)(param_1 + 0xe900 + (ulonglong)bVar4 * 4));
      }
      *(undefined1 *)(param_1 + 0xeb00) = 0;
    }
  }
  return in_RAX;
}



===== CopyRTTData @ 140007cc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong CopyRTTData(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  void *pvVar5;
  uint uVar6;
  int *_Src;
  void *_Dst;
  undefined1 auStack_58 [32];
  undefined2 local_38;
  undefined2 local_36;
  undefined4 local_34;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_58;
  lVar2 = *(longlong *)(param_2 + 0x18);
  lVar3 = *(longlong *)(param_1 + 0xeb40);
  if (*(uint *)(param_2 + 0x10) < 200) {
    pvVar5 = (void *)0x0;
    *(undefined1 *)(param_2 + 3) = 6;
    *(undefined4 *)(lVar2 + 0x14) = 1;
  }
  else {
    pvVar5 = (void *)0x0;
    iVar4 = 0;
    if (*(char *)(lVar2 + 0x38) == '\0') {
      *(undefined4 *)(lVar3 + 0x48) = *(undefined4 *)(param_1 + 0xeb4c);
      *(undefined2 *)(lVar3 + 0x10) = *(undefined2 *)(param_1 + 4);
      local_38 = 1;
      local_34 = 4;
      iVar4 = StorPortExtendedFunction(0x29,param_1,&local_38);
      if (iVar4 == 0) {
        *(undefined2 *)(lVar3 + 0x10) = local_36;
      }
      *(undefined4 *)(lVar3 + 100) = 0;
      memmove((void *)(lVar3 + 0x20),"7.717.02.00",0xb);
      memmove((void *)(lVar3 + 0x30),(void *)(*(longlong *)(param_1 + 0x198) + 0x640),0xe);
      pvVar5 = memmove((void *)(lVar2 + 0xbc),*(void **)(param_1 + 0xeb40),0x80);
      *(undefined1 *)(lVar2 + 0x1e) = 0;
    }
    else if (*(char *)(lVar2 + 0x38) == '\x01') {
      _Dst = (void *)(lVar2 + 0xc4);
      if ((*(uint *)(lVar2 + 0xc0) & 1) == 0) {
        _Src = *(int **)(param_1 + 0xeb38);
      }
      else {
        _Src = *(int **)(param_1 + 0xeb28);
        *(int **)(param_1 + 0xeb38) = _Src;
      }
      uVar6 = *(uint *)(lVar2 + 0xbc);
      if ((uint)_Src[1] < uVar6) {
        do {
          if (*_Src == 0) break;
          if (*_Src == 1) {
            _Src = *(int **)(param_1 + 0xeb18);
          }
          else {
            iVar4 = iVar4 + _Src[1];
            memmove(_Dst,_Src,(ulonglong)(uint)_Src[1]);
            _Dst = (void *)((longlong)_Dst + (ulonglong)(uint)_Src[1]);
            _Src = (int *)((longlong)_Src + (ulonglong)(uint)_Src[1]);
          }
          uVar6 = *(uint *)(lVar2 + 0xbc);
        } while ((uint)_Src[1] < uVar6 - iVar4);
      }
      uVar1 = _Src[1];
      pvVar5 = (void *)(ulonglong)uVar1;
      if ((uVar1 < uVar6 - iVar4) && (*_Src == 0)) {
        pvVar5 = memmove(_Dst,_Src,(ulonglong)uVar1);
        *(undefined4 *)(lVar2 + 0xc0) = 2;
        *(undefined8 *)(param_1 + 0xeb38) = 0;
        *(uint *)(lVar2 + 0xbc) = iVar4 + uVar1;
        *(undefined1 *)(lVar2 + 0x1e) = 0;
      }
      else {
        *(int **)(param_1 + 0xeb38) = _Src;
        *(undefined4 *)(lVar2 + 0xc0) = 0;
        *(int *)(lVar2 + 0xbc) = iVar4;
        *(undefined1 *)(lVar2 + 0x1e) = 0;
      }
    }
    else {
      *(undefined1 *)(lVar2 + 0x1e) = 3;
    }
  }
  return (ulonglong)pvVar5 & 0xffffffffffffff00;
}



===== FirmwareIOcall @ 140007ec0 =====

ulonglong FirmwareIOcall(longlong param_1,longlong param_2)

{
  byte *_Dst;
  byte bVar1;
  longlong lVar2;
  longlong *plVar3;
  ulonglong uVar4;
  longlong lVar5;
  char cVar6;
  byte bVar7;
  ulonglong uVar8;
  uint uVar9;
  uint uVar10;
  undefined1 local_res8 [8];
  
  plVar3 = SetPhysAddressFromSRBExt(param_1,param_2);
  lVar2 = *(longlong *)(param_2 + 0x18);
  _Dst = (byte *)(plVar3 + 0x20);
  lVar5 = lVar2 + 0xbc;
  if (*(char *)(param_1 + 0xd911) != '\0') {
    return (ulonglong)plVar3 & 0xffffffffffffff00;
  }
  bVar7 = *(byte *)(lVar2 + 0x1c);
  if ((byte)(bVar7 - 3) < 2) {
    memmove(_Dst,(void *)(lVar2 + 0x1c),0x40);
    *(undefined2 *)(plVar3 + 0x22) = 0;
    plVar3[0x21] = 0;
    plVar3[0xc] = (longlong)(plVar3 + 0x26);
    plVar3[0xb] = (longlong)(plVar3 + 0x26);
    uVar4 = BuildSGLforIOCTL(param_1,plVar3,lVar5,*(uint *)(lVar2 + 0x30));
    if ((char)uVar4 == '\0') goto LAB_140008245;
    *(ushort *)(plVar3 + 0x22) =
         -(ushort)(*(char *)((longlong)plVar3 + 0x34) != '\0') & 2 |
         *(ushort *)(plVar3 + 0x22) & 0xfffd;
    lVar5 = 0;
    *(char *)((longlong)plVar3 + 0x107) = (char)plVar3[10];
    if ((char)plVar3[10] != '\0') {
      lVar5 = MFI_SetFrameCount(param_1,(longlong)plVar3,*(byte *)(lVar2 + 0x1c));
    }
    if (*(char *)(lVar2 + 0x1d) != '\0') {
      lVar5 = StorPortGetPhysicalAddress(param_1,param_2,lVar2 + 0x9c,local_res8);
      if (0 < (int)((ulonglong)lVar5 >> 0x20)) {
        *(ushort *)(plVar3 + 0x22) = *(ushort *)(plVar3 + 0x22) | 4;
      }
      plVar3[0x23] = lVar5;
    }
LAB_1400082ba:
    *(undefined1 *)(plVar3 + 0x12) = 1;
    uVar4 = CONCAT71((int7)((ulonglong)lVar5 >> 8),1);
  }
  else {
    if (bVar7 == 5) {
      memmove(_Dst,(void *)(lVar2 + 0x1c),0x40);
      *(undefined4 *)(plVar3 + 0x23) = *(undefined4 *)(lVar2 + 0x34);
      if ((*(int *)(lVar2 + 0x34) == 0x10f0300) && (*(int *)(lVar2 + 0x38) == 1)) {
        *(undefined1 *)(param_1 + 0xe8af) = 1;
      }
      *(undefined4 *)((longlong)plVar3 + 0x11c) = *(undefined4 *)(lVar2 + 0x38);
      *(undefined4 *)(plVar3 + 0x24) = *(undefined4 *)(lVar2 + 0x3c);
      *(undefined4 *)((longlong)plVar3 + 0x124) = *(undefined4 *)(lVar2 + 0x40);
      *(undefined2 *)(plVar3 + 0x22) = 0;
      *(undefined4 *)(plVar3 + 0x21) = 0;
      plVar3[0xc] = (longlong)(plVar3 + 0x25);
      plVar3[0xb] = (longlong)(plVar3 + 0x25);
      uVar9 = *(uint *)(lVar2 + 0x30);
LAB_1400080af:
      uVar4 = BuildSGLforIOCTL(param_1,plVar3,lVar5,uVar9);
      if ((char)uVar4 != '\0') {
        *(ushort *)(plVar3 + 0x22) =
             -(ushort)(*(char *)((longlong)plVar3 + 0x34) != '\0') & 2 |
             *(ushort *)(plVar3 + 0x22) & 0xfffd;
        lVar5 = 0;
        *(char *)((longlong)plVar3 + 0x107) = (char)plVar3[10];
        if ((char)plVar3[10] != '\0') {
          lVar5 = MFI_SetFrameCount(param_1,(longlong)plVar3,*_Dst);
        }
        goto LAB_1400082ba;
      }
    }
    else if (bVar7 == 7) {
      memmove(_Dst,(void *)(lVar2 + 0x1c),0x38);
      *(undefined2 *)(lVar2 + 0x2c) = 0;
      *(undefined8 *)(lVar2 + 0x24) = 0;
      plVar3[0xc] = (longlong)(plVar3 + 0x24);
      plVar3[0xb] = (longlong)(plVar3 + 0x24);
      uVar4 = BuildSGLforIOCTL(param_1,plVar3,lVar5,*(uint *)(lVar2 + 0x30));
      if ((char)uVar4 != '\0') {
        uVar10 = *(uint *)(lVar2 + 0x30);
        uVar9 = (*(int *)(param_2 + 0x10) - uVar10) - 0xbc;
LAB_1400080a5:
        lVar5 = lVar2 + 0xbc + (ulonglong)uVar10;
        goto LAB_1400080af;
      }
    }
    else if (bVar7 == 8) {
      memmove(_Dst,(void *)(lVar2 + 0x1c),0x40);
      *(undefined2 *)(lVar2 + 0x2c) = 0;
      *(undefined8 *)(lVar2 + 0x24) = 0;
      plVar3[0xc] = (longlong)(plVar3 + 0x26);
      plVar3[0xb] = (longlong)(plVar3 + 0x26);
      uVar10 = (*(int *)(param_2 + 0x10) - *(int *)(lVar2 + 0x30)) - 0xbc;
      uVar4 = BuildSGLforIOCTL(param_1,plVar3,lVar5,uVar10);
      if ((char)uVar4 != '\0') {
        uVar9 = *(uint *)(lVar2 + 0x30);
        goto LAB_1400080a5;
      }
    }
    else {
      if (bVar7 != 9) {
        if (((bVar7 != 10) || (bVar1 = *(byte *)(lVar2 + 0x23), *(char *)(param_1 + 0xe470) == '\0')
            ) || (bVar1 == 0)) goto LAB_1400081f4;
        memmove(_Dst,(void *)(lVar2 + 0x1c),0x80);
        uVar8 = 0;
        plVar3[0x21] = 0;
        plVar3[0xc] = (longlong)(plVar3 + 0x23);
        plVar3[0xb] = (longlong)(plVar3 + 0x23);
        if (bVar1 != 0) {
          do {
            uVar9 = *(uint *)((longlong)plVar3 + uVar8 * 0xc + 0x120);
            uVar4 = BuildSGLforIOCTL(param_1,plVar3,lVar5,uVar9);
            if ((char)uVar4 == '\0') goto LAB_140008245;
            lVar5 = lVar5 + (ulonglong)uVar9;
            bVar7 = (char)uVar8 + 1;
            uVar8 = (ulonglong)bVar7;
          } while (bVar7 < bVar1);
        }
        lVar5 = 0;
        *(ushort *)(plVar3 + 0x22) =
             -(ushort)(*(char *)((longlong)plVar3 + 0x34) != '\0') & 2 |
             *(ushort *)(plVar3 + 0x22) & 0xfffd;
        if ((ushort)bVar1 != *(ushort *)(plVar3 + 10)) {
          uVar4 = *(ulonglong *)(param_2 + 0x18);
          *(undefined1 *)(param_2 + 3) = 6;
          *(undefined4 *)(uVar4 + 0x14) = 1;
          return uVar4 & 0xffffffffffffff00;
        }
        cVar6 = (char)*(ushort *)(plVar3 + 10);
        *(char *)((longlong)plVar3 + 0x107) = cVar6;
        if (cVar6 != '\0') {
          lVar5 = MFI_SetFrameCount(param_1,(longlong)plVar3,*_Dst);
        }
        goto LAB_1400082ba;
      }
      if (*(char *)(param_1 + 0xe46f) == '\0') {
LAB_1400081f4:
        *(undefined1 *)(param_2 + 3) = 6;
        *(undefined4 *)(lVar2 + 0x14) = 1;
        return (ulonglong)(uint3)(bVar7 - 3 >> 8) << 8;
      }
      memmove(_Dst,(void *)(lVar2 + 0x1c),0x28);
      *(undefined2 *)(plVar3 + 0x22) = 0;
      plVar3[0x21] = 0;
      plVar3[0xc] = (longlong)plVar3 + 0x11c;
      plVar3[0xb] = (longlong)plVar3 + 0x11c;
      uVar10 = (*(int *)(param_2 + 0x10) - *(int *)(lVar2 + 0x34)) - 0xbc;
      uVar4 = BuildSGLforIOCTL(param_1,plVar3,lVar5,uVar10);
      if ((char)uVar4 != '\0') {
        uVar9 = *(uint *)(lVar2 + 0x34);
        goto LAB_1400080a5;
      }
    }
LAB_140008245:
    *(undefined1 *)(param_2 + 3) = 0x12;
    uVar4 = uVar4 & 0xffffffffffffff00;
  }
  return uVar4;
}



===== HandleRttRequest @ 1400082e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong HandleRttRequest(longlong param_1,longlong param_2,undefined4 param_3)

{
  uint uVar1;
  longlong lVar2;
  void *pvVar3;
  uint uVar4;
  ulonglong uVar5;
  int iVar6;
  byte bVar7;
  int *_Src;
  void *_Dst;
  undefined1 auStackY_88 [32];
  undefined1 local_48 [8];
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_88;
  lVar2 = *(longlong *)(param_2 + 0x18);
  uVar5 = 0;
  local_40 = *(undefined4 *)(lVar2 + 0x10);
  local_38 = 0;
  local_3c = 0;
  do {
    bVar7 = (byte)uVar5;
    pvVar3 = (void *)0x0;
    if (*(char *)(lVar2 + 4 + uVar5) != RTTRACE_IOCTL_SIG[uVar5]) {
      *(undefined4 *)(param_2 + 0x10) = 0;
      if ((*(char *)(param_1 + 0xeb50) != '\0') &&
         (pvVar3 = (void *)(ulonglong)*(uint *)(param_1 + 0xeb54),
         (*(uint *)(param_1 + 0xeb54) & 0x260) != 0)) {
        pvVar3 = (void *)RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x260,
                                     local_48,0x11,0,param_3);
      }
      break;
    }
    bVar7 = bVar7 + 1;
    uVar5 = (ulonglong)bVar7;
  } while (bVar7 < 8);
  if (bVar7 != 8) goto LAB_14000854c;
  *(undefined4 *)(lVar2 + 0x14) = 0;
  pvVar3 = memmove((void *)(lVar2 + 0x1c),&RttraceRecordVersion,4);
  iVar6 = *(int *)(lVar2 + 0x20);
  if (iVar6 == 1) {
    if (*(uint *)(lVar2 + 0x18) < 0x24) {
LAB_140008508:
      *(undefined4 *)(lVar2 + 0x14) = 2;
      *(undefined4 *)(lVar2 + 0x28) = 2;
      *(undefined1 *)(param_2 + 3) = 1;
      goto LAB_14000854c;
    }
    *(undefined1 *)(lVar2 + 0x3c) = *(undefined1 *)(param_1 + 0xeb50);
    *(undefined4 *)(lVar2 + 0x38) = *(undefined4 *)(param_1 + 0xeb54);
    *(undefined4 *)(lVar2 + 0x34) = *(undefined4 *)(param_1 + 0xeb4c);
    pvVar3 = (void *)(ulonglong)*(uint *)(param_1 + 0xeb48);
    *(uint *)(lVar2 + 0x30) = *(uint *)(param_1 + 0xeb48);
    *(undefined4 *)(lVar2 + 0x2c) = 0xf;
  }
  else if (iVar6 == 2) {
    if (*(uint *)(lVar2 + 0x18) < 0x24) goto LAB_140008508;
    uVar4 = *(uint *)(lVar2 + 0x2c);
    if ((uVar4 & 1) != 0) {
      *(undefined1 *)(param_1 + 0xeb50) = *(undefined1 *)(lVar2 + 0x3c);
      uVar4 = *(uint *)(lVar2 + 0x2c);
    }
    pvVar3 = (void *)(ulonglong)uVar4;
    if ((uVar4 & 2) != 0) {
      pvVar3 = (void *)(ulonglong)*(uint *)(lVar2 + 0x38);
      *(uint *)(param_1 + 0xeb54) = *(uint *)(lVar2 + 0x38);
    }
  }
  else {
    if (iVar6 != 3) {
      *(undefined4 *)(lVar2 + 0x14) = 1;
      *(undefined1 *)(param_2 + 3) = 1;
      goto LAB_14000854c;
    }
    uVar5 = (ulonglong)*(uint *)(lVar2 + 0x2c);
    pvVar3 = (void *)(ulonglong)*(uint *)(lVar2 + 0x18);
    if (pvVar3 < (void *)(uVar5 + 0x14)) {
      *(undefined4 *)(lVar2 + 0x14) = 3;
      *(undefined4 *)(lVar2 + 0x28) = 2;
      *(undefined1 *)(param_2 + 3) = 1;
      goto LAB_14000854c;
    }
    if ((*(uint *)(lVar2 + 0x24) & 1) == 0) {
      _Src = *(int **)(param_1 + 0xeb38);
    }
    else {
      _Src = *(int **)(param_1 + 0xeb28);
      *(int **)(param_1 + 0xeb38) = _Src;
      uVar5 = (ulonglong)*(uint *)(lVar2 + 0x2c);
    }
    _Dst = (void *)(lVar2 + 0x30);
    iVar6 = 0;
    uVar4 = (uint)uVar5;
    if ((uint)_Src[1] < uVar4) {
      do {
        uVar4 = (uint)uVar5;
        if (*_Src == 0) break;
        if (*_Src == 1) {
          _Src = *(int **)(param_1 + 0xeb18);
        }
        else {
          iVar6 = iVar6 + _Src[1];
          memmove(_Dst,_Src,(ulonglong)(uint)_Src[1]);
          _Dst = (void *)((longlong)_Dst + (ulonglong)(uint)_Src[1]);
          _Src = (int *)((longlong)_Src + (ulonglong)(uint)_Src[1]);
        }
        uVar4 = *(uint *)(lVar2 + 0x2c);
        uVar5 = (ulonglong)uVar4;
      } while ((uint)_Src[1] < uVar4 - iVar6);
    }
    uVar1 = _Src[1];
    pvVar3 = (void *)(ulonglong)uVar1;
    if ((uVar1 < uVar4 - iVar6) && (*_Src == 0)) {
      pvVar3 = memmove(_Dst,_Src,(ulonglong)uVar1);
      *(undefined4 *)(lVar2 + 0x24) = 2;
      *(undefined8 *)(param_1 + 0xeb38) = 0;
      *(uint *)(lVar2 + 0x2c) = iVar6 + uVar1;
    }
    else {
      *(int **)(param_1 + 0xeb38) = _Src;
      *(undefined4 *)(lVar2 + 0x24) = 0;
      *(int *)(lVar2 + 0x2c) = iVar6;
    }
  }
  *(undefined4 *)(lVar2 + 0x28) = 0;
LAB_14000854c:
  return (ulonglong)pvVar3 & 0xffffffffffffff00;
}



===== HbaFwUpgrade @ 140008570 =====

void HbaFwUpgrade(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  byte bVar3;
  ulonglong uVar4;
  
  lVar1 = *(longlong *)(param_2 + 0x18);
  *(longlong *)(param_1 + 0xedb8) = param_2;
  plVar2 = SetPhysAddressFromSRBExt(param_1,param_2);
  uVar4 = 0;
  do {
    if ((uint)*(byte *)(lVar1 + 4 + uVar4) != (int)"FIRMWARE"[uVar4]) {
      *(undefined4 *)(param_2 + 0x10) = 0;
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x25c) != 0)) {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x25c,(undefined1 *)0x0,0,0,
                    0x11);
      }
      *(undefined1 *)(param_2 + 3) = 6;
      *(undefined4 *)(lVar1 + 0x14) = 2;
      StorPortNotification(0,param_1,param_2);
      return;
    }
    bVar3 = (char)uVar4 + 1;
    uVar4 = (ulonglong)bVar3;
  } while (bVar3 < 8);
  HbaFwReloadFsm(param_1,'\0',0,0,plVar2,0x11);
  return;
}



===== MegaSASIoctl @ 140008660 =====

ulonglong MegaSASIoctl(longlong param_1,longlong param_2,undefined4 param_3)

{
  undefined1 uVar1;
  char cVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  longlong lVar7;
  uint7 uVar12;
  ulonglong uVar8;
  void *pvVar9;
  longlong *plVar10;
  longlong *plVar11;
  char *_Src;
  uint3 local_res10;
  char cStackX_13;
  
  lVar7 = *(longlong *)(param_2 + 0x18);
  uVar12 = (uint7)((ulonglong)lVar7 >> 8);
  if (*(int *)(lVar7 + 0x10) == 0x1b0780) {
    return CONCAT71(uVar12,1);
  }
  if (*(int *)(lVar7 + 0x10) == -0x7f8d8b8c) {
    uVar8 = HandleRttRequest(param_1,param_2,param_3);
    return uVar8;
  }
  if (*(uint *)(param_2 + 0x10) < 0xbc) {
    *(undefined1 *)(param_2 + 3) = 6;
    *(undefined4 *)(lVar7 + 0x14) = 1;
    return (ulonglong)uVar12 << 8;
  }
  if (((((*(char *)(lVar7 + 4) != 'L') || (*(char *)(lVar7 + 5) != 'S')) ||
       (*(char *)(lVar7 + 6) != 'I')) ||
      ((*(char *)(lVar7 + 7) != 'L' || (*(char *)(lVar7 + 8) != 'O')))) ||
     ((*(char *)(lVar7 + 9) != 'G' ||
      ((*(char *)(lVar7 + 10) != 'I' || (*(char *)(lVar7 + 0xb) != 'C')))))) {
    *(undefined1 *)(param_2 + 3) = 6;
    *(undefined4 *)(lVar7 + 0x14) = 1;
    *(undefined8 *)(lVar7 + 4) = 0;
    return (ulonglong)uVar12 << 8;
  }
  *(undefined8 *)(lVar7 + 4) = 0;
  if ((*(int *)(lVar7 + 0x10) + 0xfff0000U & 0xfffeffff) != 0) {
    uVar8 = FirmwareIOcall(param_1,param_2);
    return uVar8;
  }
  lVar7 = *(longlong *)(param_2 + 0x18);
  uVar4 = *(uint *)(lVar7 + 0x34);
  pvVar9 = (void *)(ulonglong)uVar4;
  if (0xf0020200 < uVar4) {
    if (uVar4 == 0xf0020300) {
      if (0xbf < *(uint *)(param_2 + 0x10)) {
        uVar4 = *(uint *)(param_1 + 0x74);
        *(uint *)(lVar7 + 0xbc) = uVar4;
LAB_140008a1f:
        *(undefined1 *)(lVar7 + 0x1e) = 0;
        return (ulonglong)(uVar4 >> 8) << 8;
      }
    }
    else {
      if (uVar4 == 0xf0020b00) {
        uVar8 = CopyRTTData(param_1,param_2);
        return uVar8;
      }
      if (uVar4 != 0xf0020c00) {
LAB_14000891a:
        uVar8 = FirmwareIOcall(param_1,param_2);
        return uVar8;
      }
      if (199 < *(uint *)(param_2 + 0x10)) {
        if (*(char *)(lVar7 + 0x38) == '\0') {
          *(undefined1 *)(lVar7 + 0xcc) = *(undefined1 *)(param_1 + 0xeb50);
          *(undefined4 *)(lVar7 + 0xc4) = *(undefined4 *)(param_1 + 0xeb54);
          *(undefined4 *)(lVar7 + 0xc0) = *(undefined4 *)(param_1 + 0xeb4c);
          uVar6 = *(undefined4 *)(param_1 + 0xeb48);
          *(undefined4 *)(lVar7 + 200) = 0xf;
          *(undefined4 *)(lVar7 + 0xbc) = uVar6;
          *(undefined1 *)(lVar7 + 0x1e) = 0;
          return (ulonglong)(uint3)((uint)uVar6 >> 8) << 8;
        }
        if (*(char *)(lVar7 + 0x38) != '\x01') {
          *(undefined1 *)(lVar7 + 0x1e) = 3;
          return 0;
        }
        uVar4 = *(uint *)(lVar7 + 200);
        if ((uVar4 & 1) != 0) {
          *(undefined1 *)(param_1 + 0xeb50) = *(undefined1 *)(lVar7 + 0xcc);
          uVar4 = *(uint *)(lVar7 + 200);
        }
        if ((uVar4 & 2) != 0) {
          uVar6 = *(undefined4 *)(lVar7 + 0xc4);
          *(undefined4 *)(param_1 + 0xeb54) = uVar6;
          *(undefined1 *)(lVar7 + 0x1e) = 0;
          return (ulonglong)(uint3)((uint)uVar6 >> 8) << 8;
        }
        goto LAB_140008a1f;
      }
    }
LAB_140008822:
    *(undefined1 *)(param_2 + 3) = 6;
    *(undefined4 *)(lVar7 + 0x14) = 1;
    return (ulonglong)pvVar9 & 0xffffffffffffff00;
  }
  if (uVar4 == 0xf0020200) {
    pvVar9 = (void *)0xf0020200;
    if (*(uint *)(param_2 + 0x10) < 0xc0) goto LAB_140008822;
    if (*(char *)(param_1 + 0xd911) != '\0') goto LAB_1400087de;
    uVar3 = *(ushort *)(param_1 + 0xd7ac);
    cVar2 = *(char *)(lVar7 + 0xbf);
    local_res10 = (uint3)uVar3;
    _local_res10 = CONCAT13(*(char *)(param_1 + 0xd7af),local_res10);
    if (*(ushort *)(lVar7 + 0xbc) != uVar3) {
      _local_res10 = CONCAT22(stack0x00000012,*(ushort *)(lVar7 + 0xbc) | uVar3);
      *(undefined4 *)(param_1 + 0xd7ac) = _local_res10;
      pvVar9 = (void *)CONCAT71((uint7)(uint3)((uint)_local_res10 >> 8),1);
    }
    if (cVar2 < *(char *)(param_1 + 0xd7af)) {
      _local_res10 = CONCAT13(cVar2,local_res10);
      *(undefined4 *)(param_1 + 0xd7ac) = _local_res10;
LAB_1400088ae:
      lVar7 = *(longlong *)(param_1 + 0x110);
      plVar10 = SetPhysAddressFromSRBExt(param_1,param_2);
      plVar11 = plVar10 + 0x20;
      *plVar11 = 0;
      plVar10[0x21] = 0;
      plVar10[0x22] = 0;
      plVar10[0x23] = 0;
      plVar10[0x24] = 0;
      *(undefined1 *)plVar11 = 6;
      iVar5 = *(int *)(param_1 + 0xd7fc);
      plVar10[0x24] = lVar7;
      *(int *)(plVar10 + 0x23) = iVar5 + -2;
      return CONCAT71((int7)((ulonglong)plVar11 >> 8),1);
    }
    if ((char)pvVar9 != '\0') goto LAB_1400088ae;
  }
  else {
    if (uVar4 == 0xf0010100) {
      if (*(uint *)(param_2 + 0x10) < 300) goto LAB_140008822;
      if (*(char *)(param_1 + 0xd911) != '\0') goto LAB_1400087de;
      _Src = s_LSILOGIC_140016040;
    }
    else {
      if (uVar4 != 0xf0010200) {
        if (uVar4 == 0xf0010300) goto LAB_140008822;
        if (uVar4 != 0xf0020100) goto LAB_14000891a;
        uVar1 = *(undefined1 *)(lVar7 + 0x38);
        *(undefined1 *)(lVar7 + 0x1e) = 0;
        if (*(char *)(param_1 + 0xd911) == '\0') {
          memset((void *)(param_1 + 0xe1b0),0,0x100);
          uVar8 = StorPortNotification(7,param_1,uVar1);
          return uVar8 & 0xffffffffffffff00;
        }
        goto LAB_1400087de;
      }
      if (*(uint *)(param_2 + 0x10) < 300) goto LAB_140008822;
      if (*(char *)(param_1 + 0xd911) != '\0') goto LAB_1400087de;
      _Src = (char *)(param_1 + 4);
    }
    pvVar9 = memmove((void *)(lVar7 + 0xbc),_Src,0x70);
  }
  *(undefined1 *)(lVar7 + 0x1e) = 0;
LAB_1400087de:
  return (ulonglong)pvVar9 & 0xffffffffffffff00;
}



===== SetPhysAddressFromSRBExt @ 140008a50 =====

longlong * SetPhysAddressFromSRBExt(longlong param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  undefined1 uVar3;
  longlong *plVar4;
  undefined1 local_res8 [8];
  
  plVar4 = (longlong *)(*(longlong *)(param_2 + 0x38) + 0x100U & 0xfffffffffffffeff);
  memset(plVar4 + 1,0,0x5f8);
  *plVar4 = param_2;
  cVar1 = *(char *)(param_1 + 0xd92a);
  *(char *)((longlong)plVar4 + 0x34) = cVar1;
  uVar3 = 8;
  if (cVar1 != '\0') {
    uVar3 = 0xc;
  }
  *(undefined1 *)((longlong)plVar4 + 0x52) = uVar3;
  lVar2 = StorPortGetPhysicalAddress(param_1,param_2,plVar4,local_res8);
  plVar4[4] = lVar2 + 0x100;
  return plVar4;
}



===== AbortPendedCommands @ 140008ae0 =====

void AbortPendedCommands(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0xb0);
  if (*(char *)(param_1 + 0xd929) != '\0') {
    PrepareAbortFrame(param_1,3);
    if (*(char *)(param_1 + 0xe46e) == '\0') {
      Fusion_FireRequest_MFI(param_1,lVar1);
    }
    else {
      Fusion_FireRequest_MFIAtomic(param_1,lVar1);
    }
    uVar2 = WaitForCmdStatus(param_1,lVar1);
    if ((char)uVar2 == '\0') {
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x80083) != 0)) {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x80083,(undefined1 *)0x0,0,0
                    ,7);
      }
    }
    else {
      *(undefined1 *)(param_1 + 0xd929) = 0;
    }
  }
  if (*(char *)(param_1 + 0xd306) != '\0') {
    PrepareAbortFrame(param_1,2);
    if (*(char *)(param_1 + 0xe46e) == '\0') {
      Fusion_FireRequest_MFI(param_1,lVar1);
    }
    else {
      Fusion_FireRequest_MFIAtomic(param_1,lVar1);
    }
    uVar2 = WaitForCmdStatus(param_1,lVar1);
    if ((char)uVar2 == '\0') {
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x80084) != 0)) {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x80084,(undefined1 *)0x0,0,0
                    ,7);
      }
    }
    else {
      *(undefined1 *)(param_1 + 0xd306) = 0;
    }
  }
  if (*(char *)(param_1 + 0xd950) != '\0') {
    PrepareAbortFrame(param_1,6);
    if (*(char *)(param_1 + 0xe46e) == '\0') {
      Fusion_FireRequest_MFI(param_1,lVar1);
    }
    else {
      Fusion_FireRequest_MFIAtomic(param_1,lVar1);
    }
    uVar2 = WaitForCmdStatus(param_1,lVar1);
    if ((char)uVar2 == '\0') {
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x80085) != 0)) {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x80085,(undefined1 *)0x0,0,0
                    ,7);
        return;
      }
    }
    else {
      *(undefined1 *)(param_1 + 0xd950) = 0;
    }
  }
  return;
}



===== DriverEntry @ 140008cd0 =====

void DriverEntry(undefined8 param_1,undefined8 param_2)

{
  undefined4 local_d8;
  undefined4 local_d4;
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
  
  memset(&local_d8,0,0xd0);
  local_d8 = 0xd0;
  local_d0 = MegaSASInitialize;
  local_80 = 0x1010102;
  local_b8 = MegaSASFindAdapter;
  local_8c = 2;
  local_c8 = MegaSASStartIo;
  local_d4 = 5;
  local_58 = MegaSASBuildIo;
  local_7c = 1;
  local_c0 = LegacyInterrupts;
  local_b0 = MegaSASResetBus;
  local_60 = MegaSASPnPControl;
  local_6e = 4;
  local_7a = 4;
  local_20 = 0x20;
  local_1c = 1;
  local_98 = 0xede0;
  local_90 = 0x700;
  StorPortInitialize(param_1,param_2,&local_d8,0);
  return;
}



===== Fusion_FireRequest_MFI @ 140008dd0 =====

void Fusion_FireRequest_MFI(longlong param_1,longlong param_2)

{
  ushort uVar1;
  undefined4 uStackX_c;
  
  uVar1 = *(short *)(param_2 + 0x14) + 1;
  MPT_BuildPassthrough
            (param_1,(void *)((ulonglong)uVar1 * 0x100 + *(longlong *)(param_1 + 0xd998)),
             *(undefined8 *)(param_2 + 0x20));
  *(ulonglong *)(*(longlong *)(param_1 + 0x80) + 0xc0) =
       (ulonglong)CONCAT42(uStackX_c,uVar1) << 0x10;
  LOCK();
  UNLOCK();
  return;
}



===== Fusion_FireRequest_MFIAtomic @ 140008e30 =====

void Fusion_FireRequest_MFIAtomic(longlong param_1,longlong param_2)

{
  ushort uVar1;
  int local_res8;
  
  uVar1 = *(short *)(param_2 + 0x14) + 1;
  local_res8 = (uint)uVar1 << 0x10;
  MPT_BuildPassthrough
            (param_1,(void *)((ulonglong)uVar1 * 0x100 + *(longlong *)(param_1 + 0xd998)),
             *(undefined8 *)(param_2 + 0x20));
  *(int *)(*(longlong *)(param_1 + 0x80) + 200) = local_res8;
  LOCK();
  UNLOCK();
  return;
}



===== MPT_InitializeQueues @ 140008e90 =====

undefined8 MPT_InitializeQueues(longlong param_1,longlong param_2,undefined8 *param_3)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined1 local_res8 [8];
  longlong local_res10 [2];
  
  uVar6 = 0;
  if (*(char *)(param_1 + 0xd859) != '\0') {
    do {
      *(undefined2 *)(param_1 + (uVar6 + 0xd9a) * 0x10) = 0;
      uVar3 = 0;
      if (*(int *)(param_1 + 0xd808) != 0) {
        do {
          uVar7 = (ulonglong)uVar3;
          uVar3 = uVar3 + 1;
          *(undefined8 *)(*(longlong *)(param_1 + uVar6 * 0x10 + 0xd9a8) + uVar7 * 8) =
               0xffffffffffffffff;
        } while (uVar3 < *(uint *)(param_1 + 0xd808));
      }
      uVar3 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar3;
    } while (uVar3 < *(byte *)(param_1 + 0xd859));
  }
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  param_3[4] = 0;
  param_3[5] = 0;
  param_3[6] = 0;
  param_3[7] = 0;
  param_3[8] = 0;
  *(undefined1 *)((longlong)param_3 + 3) = 2;
  *(undefined1 *)param_3 = 4;
  *(undefined4 *)((longlong)param_3 + 0xc) = 0x3a000206;
  *(undefined1 *)((longlong)param_3 + 0x16) = 0xc;
  if ((*(char *)(param_1 + 0xd858) == '\0') || (bVar1 = *(byte *)(param_1 + 0xd859), bVar1 < 2)) {
    bVar1 = 0;
  }
  *(byte *)((longlong)param_3 + 0x17) = bVar1;
  *(undefined2 *)((longlong)param_3 + 0x1a) = 0x40;
  *(undefined2 *)((longlong)param_3 + 0x1c) = *(undefined2 *)(param_1 + 0xd808);
  *(undefined2 *)((longlong)param_3 + 0x1e) = 0;
  uVar5 = StorPortGetPhysicalAddress(param_1,0,*(undefined8 *)(param_1 + 0xd9a8),local_res8);
  param_3[6] = uVar5;
  uVar5 = StorPortGetPhysicalAddress(param_1,0,*(undefined8 *)(param_1 + 0xd998),local_res8);
  param_3[5] = uVar5;
  *(undefined4 *)(param_3 + 4) = *(undefined4 *)(param_1 + 0x204);
  param_3[7] = 0;
  StorPortQuerySystemTime(local_res10);
  local_res10[0] = (local_res10[0] + -0x19db1ded53e8000) / 10000;
  param_3[8] = local_res10[0];
  uVar5 = StorPortGetPhysicalAddress(param_1,0,param_3,local_res8);
  *(undefined8 *)(param_2 + 0x118) = uVar5;
  uVar5 = StorPortGetPhysicalAddress(param_1,0,*(undefined8 *)(param_1 + 0xa8),local_res8);
  *(undefined8 *)(param_2 + 0x128) = uVar5;
  uVar3 = *(uint *)(param_2 + 0x104);
  uVar4 = uVar3 | 0x52;
  *(undefined1 *)(param_2 + 0x100) = 0;
  *(uint *)(param_2 + 0x104) = uVar4;
  *(undefined4 *)(param_2 + 0x114) = 8;
  if (*(char *)(param_1 + 0xe8a4) != '\0') {
    uVar4 = uVar3 | 0x152;
  }
  *(ushort *)(param_2 + 0x110) = *(ushort *)(param_2 + 0x110) | 1;
  *(uint *)(param_2 + 0x104) = uVar4 | 0x1009;
  uVar3 = *(uint *)(param_1 + 0xe45c) & 0x1fe;
  if (uVar3 == 0) {
    if (*(char *)(param_1 + 0xeb68) == '\0') {
      *(uint *)(param_1 + 0xe45c) = *(uint *)(param_1 + 0xe45c) & 0xfffffe05 | 4;
      goto LAB_14000909e;
    }
    uVar2 = ~(-1 << ((byte)*(undefined4 *)(param_1 + 0xeb6c) & 0x1f));
  }
  else {
    if (uVar3 != 2) goto LAB_14000909e;
    uVar2 = 0xffff;
  }
  *(ushort *)(param_2 + 0x112) = uVar2;
LAB_14000909e:
  *(undefined1 *)(param_2 + 0x102) = 0xff;
  uVar6 = StorPortGetPhysicalAddress(param_1,0,(undefined1 *)(param_2 + 0x100),local_res8);
  *(ulonglong *)(*(longlong *)(param_1 + 0x80) + 0xc0) = uVar6 & 0xffffffffffffff02 | 2;
  LOCK();
  UNLOCK();
  return CONCAT71((int7)((uVar6 & 0xffffffffffffff02) >> 8),1);
}



===== MR_HybridInterruptCoalescing @ 140009100 =====

void MR_HybridInterruptCoalescing(longlong param_1)

{
  char *pcVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  longlong lVar7;
  uint uVar8;
  ushort uVar9;
  ushort uVar10;
  char *pcVar11;
  undefined4 uVar12;
  int local_res8 [2];
  
  uVar10 = 0;
  if (*(short *)(param_1 + 0xeb72) != 0) {
    do {
      iVar4 = StorPortExtendedFunction
                        (0x13,param_1,uVar10,*(longlong *)(param_1 + 0xeb90) + (ulonglong)uVar10 * 8
                        );
      if (iVar4 != 0) {
        *(undefined1 *)(param_1 + 0xeb68) = 0;
        if (*(char *)(param_1 + 0xeb50) == '\0') {
          return;
        }
        if ((*(uint *)(param_1 + 0xeb54) & 0x2a5) == 0) {
          return;
        }
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x2a5,(undefined1 *)0x0,0,0,1
                   );
        return;
      }
      cVar2 = RtlFindMostSignificantBit
                        (*(undefined8 *)((ulonglong)uVar10 * 8 + *(longlong *)(param_1 + 0xeb90)));
      uVar10 = uVar10 + 1;
      *(short *)(param_1 + 0xeb74) = *(short *)(param_1 + 0xeb74) + cVar2 + 1;
    } while (uVar10 < *(ushort *)(param_1 + 0xeb72));
  }
  uVar10 = 0;
  if (*(int *)(param_1 + 0xeb6c) != 0) {
    uVar8 = 0;
    do {
      pcVar11 = (char *)(*(longlong *)(param_1 + 0xeb88) + (ulonglong)uVar10 * 0x38);
      pcVar1 = pcVar11 + 8;
      iVar4 = StorPortExtendedFunction(0x15,param_1,uVar8,pcVar1);
      if (iVar4 != 0) {
        *(undefined1 *)(param_1 + 0xeb68) = 0;
        if (*(char *)(param_1 + 0xeb50) == '\0') {
          return;
        }
        if ((*(uint *)(param_1 + 0xeb54) & 0x2a6) == 0) {
          return;
        }
        uVar12 = 0x2a6;
        goto LAB_1400093d3;
      }
      cVar2 = RtlFindLeastSignificantBit(*(undefined8 *)pcVar1);
      pcVar11[1] = cVar2;
      cVar2 = RtlFindMostSignificantBit(*(undefined8 *)pcVar1);
      pcVar11[2] = cVar2;
      local_res8[0] = (uint)(*(ushort *)(param_1 + 0xeb74) >> 6) * 8 + 0x50;
      *(char *)(param_1 + 0xed92) = pcVar11[2];
      *(undefined2 *)(param_1 + 0xed90) = *(undefined2 *)(pcVar11 + 0x10);
      iVar4 = StorPortExtendedFunction
                        (0x17,param_1,(undefined2 *)(param_1 + 0xed90),3,
                         *(undefined8 *)(param_1 + 0xed88),local_res8);
      if (iVar4 != 0) {
        *(undefined1 *)(param_1 + 0xeb68) = 0;
        if (*(char *)(param_1 + 0xeb50) == '\0') {
          return;
        }
        if ((*(uint *)(param_1 + 0xeb54) & 0x2a7) == 0) {
          return;
        }
        uVar12 = 0x2a7;
        goto LAB_1400093d3;
      }
      uVar9 = 0;
      if (*(short *)(*(longlong *)(param_1 + 0xed88) + 0x1e) != 0) {
        do {
          memmove(pcVar11 + ((ulonglong)
                             *(ushort *)
                              ((ulonglong)uVar9 * 0x10 + 0x28 + *(longlong *)(param_1 + 0xed88)) + 3
                            ) * 8,
                  (void *)(*(longlong *)(param_1 + 0xed88) + 0x20 + (ulonglong)uVar9 * 0x10),8);
          uVar9 = uVar9 + 1;
        } while (uVar9 < *(ushort *)(*(longlong *)(param_1 + 0xed88) + 0x1e));
      }
      cVar2 = *(char *)(param_1 + 0xeb70);
      if ((uVar10 != 0) &&
         (iVar4 = memcmp(pcVar11 + 0x18,
                         (void *)(*(longlong *)(param_1 + 0xeb88) + -0x20 + (ulonglong)uVar10 * 0x38
                                 ),0x20), iVar4 != 0)) {
        cVar2 = cVar2 + '\x01';
        *(char *)(param_1 + 0xeb70) = cVar2;
      }
      *pcVar11 = cVar2;
      lVar7 = *(longlong *)(param_1 + 0xebd8 + (ulonglong)*(ushort *)(pcVar11 + 0x10) * 8);
      uVar6 = (ulonglong)(byte)pcVar11[1];
      if ((byte)pcVar11[1] <= (byte)pcVar11[2]) {
        do {
          uVar9 = (short)uVar6 + 1;
          *(char *)(uVar6 + lVar7) = (char)uVar10;
          uVar6 = (ulonglong)uVar9;
        } while (uVar9 <= (byte)pcVar11[2]);
      }
      uVar10 = uVar10 + 1;
      uVar8 = (uint)uVar10;
    } while (uVar8 < *(uint *)(param_1 + 0xeb6c));
  }
  *(char *)(param_1 + 0xeb70) = *(char *)(param_1 + 0xeb70) + '\x01';
  uVar10 = 0;
  bVar3 = *(byte *)(param_1 + 0xeb70);
  if (*(int *)(param_1 + 0xeb6c) != 0) {
    do {
      lVar7 = 8;
      puVar5 = *(undefined8 **)(param_1 + 0xeb98 + (ulonglong)uVar10 * 8);
      do {
        *puVar5 = 0xdeadbeefdeadbeef;
        puVar5[1] = 0xdeadbeefdeadbeef;
        puVar5[2] = 0xdeadbeefdeadbeef;
        puVar5[3] = 0xdeadbeefdeadbeef;
        puVar5[4] = 0xdeadbeefdeadbeef;
        puVar5[5] = 0xdeadbeefdeadbeef;
        puVar5[6] = 0xdeadbeefdeadbeef;
        puVar5[7] = 0xdeadbeefdeadbeef;
        lVar7 = lVar7 + -1;
        puVar5 = puVar5 + 8;
      } while (lVar7 != 0);
      uVar10 = uVar10 + 1;
    } while ((uint)uVar10 < *(uint *)(param_1 + 0xeb6c));
    bVar3 = *(byte *)(param_1 + 0xeb70);
  }
  if ((((4 < bVar3) || ((uint)*(ushort *)(param_1 + 0xeb74) < *(uint *)(param_1 + 0xeb78))) &&
      (*(undefined1 *)(param_1 + 0xeb68) = 0, *(char *)(param_1 + 0xeb50) != '\0')) &&
     ((*(uint *)(param_1 + 0xeb54) & 0x2a8) != 0)) {
    uVar12 = 0x2a8;
LAB_1400093d3:
    RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),uVar12,(undefined1 *)0x0,0,0,1);
  }
  return;
}



===== MegaSASFindAdapter @ 1400094e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

undefined8
MegaSASFindAdapter(void *param_1,undefined8 param_2,undefined8 param_3,char *param_4,
                  longlong param_5,undefined1 *param_6)

{
  byte *pbVar1;
  ulonglong *puVar2;
  byte bVar3;
  char cVar4;
  undefined1 uVar5;
  ushort uVar6;
  uint uVar7;
  undefined8 uVar8;
  void *_Dst;
  ushort uVar9;
  short sVar10;
  short sVar11;
  char *pcVar12;
  longlong lVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  longlong lVar17;
  longlong *plVar18;
  ulonglong *puVar19;
  ulonglong uVar20;
  ulonglong uVar21;
  undefined4 uVar22;
  longlong lVar23;
  void *_Dst_00;
  ulonglong uVar24;
  ushort uVar25;
  char *pcVar26;
  undefined1 auStackY_1d8 [32];
  undefined1 local_198 [4];
  char local_194;
  uint local_190;
  undefined1 local_18c;
  byte local_18b;
  byte local_18a;
  undefined1 local_188;
  undefined1 local_187;
  undefined1 local_186;
  undefined1 local_185;
  uint local_184;
  undefined1 local_180 [8];
  undefined1 *local_178;
  undefined2 local_168;
  ushort local_166;
  char local_15e;
  byte local_134;
  undefined1 local_12c;
  undefined1 local_68;
  undefined1 local_67;
  undefined1 local_66;
  char local_65;
  ushort local_64;
  ushort local_62;
  undefined4 local_60;
  undefined4 local_5c;
  undefined1 local_58;
  undefined1 local_57;
  undefined1 local_56;
  undefined1 local_55;
  char local_54;
  undefined1 local_53;
  undefined2 local_52;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_1d8;
  local_178 = param_6;
  uVar25 = 0x41;
  *param_6 = 0;
  *(undefined1 *)((longlong)param_1 + 0xd90e) = 0;
  *(undefined1 *)((longlong)param_1 + 0xeb10) = 0;
  if (*(longlong *)((longlong)param_1 + 0x80) != 0) {
    memset(param_1,0,0xede0);
  }
  memset(&local_168,0,0x100);
  StorPortGetBusData(param_1,4,*(undefined4 *)(param_5 + 4),*(undefined4 *)(param_5 + 100));
  uVar9 = 0;
  do {
    lVar17 = (ulonglong)uVar9 * 0x1c;
    if (((uint)local_168 == *(uint *)(&DAT_1400160d8 + lVar17)) &&
       ((uint)local_166 == *(uint *)(&DAT_1400160dc + lVar17))) {
      lVar17 = (ulonglong)uVar9 * 0x1c;
      local_194 = (&DAT_1400160e0)[lVar17];
      *(undefined4 *)((longlong)param_1 + 0xd924) = *(undefined4 *)(&DAT_1400160e4 + lVar17);
      *(short *)((longlong)param_1 + 0xd302) = *(short *)(&DAT_1400160e8 + lVar17) + -1;
      GetRegistrySettings(param_4,(longlong)param_1);
      *(undefined4 *)((longlong)param_1 + 4) = *(undefined4 *)(param_5 + 4);
      *(byte *)((longlong)param_1 + 8) = *(byte *)(param_5 + 100) & 0x1f;
      *(byte *)((longlong)param_1 + 9) = (byte)(*(uint *)(param_5 + 100) >> 5) & 7;
      *(undefined1 *)((longlong)param_1 + 10) = local_12c;
      *(uint *)((longlong)param_1 + 0x54) = (uint)*(byte *)(param_5 + 0x66);
      pcVar12 = (char *)((longlong)&local_168 + (ulonglong)local_134);
      cVar4 = *(char *)((longlong)&local_168 + (ulonglong)local_134 + 1);
      goto joined_r0x0001400096a7;
    }
    uVar9 = uVar9 + 1;
  } while (uVar9 < 0x14);
LAB_1400095e3:
  uVar8 = 0;
LAB_1400095e5:
  *(undefined1 *)((longlong)param_1 + 0xd911) = 1;
  return uVar8;
joined_r0x0001400096a7:
  pcVar26 = (char *)&local_168;
  if (cVar4 == '\0') goto LAB_1400096cc;
  if (*pcVar12 == '\x10') {
    pcVar26 = pcVar12;
    goto LAB_1400096cc;
  }
  pbVar1 = (byte *)(pcVar12 + 1);
  pcVar12 = (char *)((longlong)&local_168 + (ulonglong)*pbVar1);
  cVar4 = *(char *)((longlong)&local_168 + (ulonglong)*pbVar1 + 1);
  goto joined_r0x0001400096a7;
LAB_1400096cc:
  memmove((void *)((longlong)param_1 + 0xc),&local_168,0x40);
  memmove((void *)((longlong)param_1 + 0x4c),pcVar26 + 0xc,4);
  memmove((void *)((longlong)param_1 + 0x50),pcVar26 + 0x12,4);
  lVar17 = StorPortGetDeviceBase(param_1,*(undefined4 *)(param_5 + 8),*(undefined4 *)(param_5 + 4));
  uVar15 = *(uint *)((longlong)param_1 + 0xe45c);
  if (*(int *)((longlong)param_1 + 0xd924) == 2) {
    *(undefined1 *)((longlong)param_1 + 0x88) = 3;
    if (((byte)*(undefined2 *)((longlong)param_1 + 0x50) & 0xf) <
        ((byte)*(undefined4 *)((longlong)param_1 + 0x4c) & 0xf)) {
      uVar14 = uVar15 & 0xfffffdff | 0x400;
      *(uint *)((longlong)param_1 + 0xe45c) = uVar14;
      if ((uVar15 & 0x1fe) == 0x1e) goto LAB_1400097ad;
    }
    else if ((uVar15 & 0x1fe) == 0x1e) {
      uVar15 = uVar15 & 0xfffffe01;
      goto LAB_1400097b6;
    }
  }
  else {
    *(undefined1 *)((longlong)param_1 + 0x88) = 1;
    uVar14 = uVar15 | 0x200;
    if (*(char *)((longlong)param_1 + 0xa6) == '\0') {
      uVar14 = uVar15 & 0xfffffdff;
    }
    uVar14 = uVar14 | 0x400;
LAB_1400097ad:
    uVar15 = uVar14 & 0xfffffe05 | 4;
LAB_1400097b6:
    *(uint *)((longlong)param_1 + 0xe45c) = uVar15;
  }
  if (local_15e == '\a') {
    uVar8 = 10;
LAB_1400097d9:
    StorPortExtendedFunction(0x40,param_1,uVar8);
  }
  else if (local_15e == '\x04') {
    uVar8 = 8;
    goto LAB_1400097d9;
  }
  if (lVar17 != 0) {
    puVar2 = (ulonglong *)((longlong)param_1 + 0xeb18);
    *(longlong *)((longlong)param_1 + 0x80) = lVar17;
    *(undefined1 *)((longlong)param_1 + 0xd85a) = 1;
    RttSetTraceParameters((longlong)puVar2,0x80000,1);
    cVar4 = '\0';
    if (*(char *)((longlong)param_1 + 0x89) != '\0') {
      RttSetTraceParameters((longlong)puVar2,0,0);
      cVar4 = *(char *)((longlong)param_1 + 0x89);
    }
    *(undefined1 *)((longlong)param_1 + 0xa5) = 0;
    *(undefined1 *)((longlong)param_1 + 0xe8af) = 0;
    if ((cVar4 == '\0') && (DAT_140016504 = DAT_140016504 + 1, 0x20 < DAT_140016504))
    goto LAB_1400095e3;
    *(uint *)((longlong)param_1 + 0x74) =
         (*(byte *)((longlong)param_1 + 9) & 7 | *(int *)((longlong)param_1 + 4) << 3) << 5 |
         *(byte *)((longlong)param_1 + 8) & 0x1f;
    Fusion_DisableInterrupt((longlong)param_1);
    *(uint *)((longlong)param_1 + 0xd810) = *(uint *)((longlong)param_1 + 0xd810) | 0x10;
    *(undefined1 *)((longlong)param_1 + 0xd910) = 1;
    *(undefined2 *)((longlong)param_1 + 0xd920) = 0x200;
    *(undefined4 *)((longlong)param_1 + 0xd2e4) = 0xff;
    uVar8 = WaitForFwareReadyWithRetry((longlong)param_1);
    if ((char)uVar8 != '\0') {
      *(uint *)((longlong)param_1 + 0xd7fc) = (*(uint *)((longlong)param_1 + 0xd2e0) & 0xffff) - 3;
      iVar16 = 0;
      do {
        uVar15 = *(uint *)(*(longlong *)((longlong)param_1 + 0x80) + 0xb8);
        iVar16 = iVar16 + 1;
        if (uVar15 != 0) break;
      } while (iVar16 < (int)(uint)*(byte *)((longlong)param_1 + 0x88));
      uVar15 = uVar15 >> 0x10 & 0x1ff;
      *(uint *)((longlong)param_1 + 0xd800) = uVar15 << 0x10;
      if (uVar15 == 0) {
        *(undefined1 *)((longlong)param_1 + 0xd928) = 0;
      }
      if (*(char *)((longlong)param_1 + 0x89) == '\0') {
        uVar5 = 99;
      }
      else {
        *(undefined1 *)((longlong)param_1 + 0xd928) = 0;
        uVar15 = 0x20;
        if (*(uint *)((longlong)param_1 + 0xd7fc) < 0x20) {
          uVar15 = *(uint *)((longlong)param_1 + 0xd7fc);
        }
        *(uint *)((longlong)param_1 + 0xe45c) = *(uint *)((longlong)param_1 + 0xe45c) | 0x200;
        *(uint *)((longlong)param_1 + 0xd7fc) = uVar15;
        uVar5 = 9;
      }
      *(undefined1 *)((longlong)param_1 + 0x180) = uVar5;
      uVar15 = *(uint *)((longlong)param_1 + 0xd7fc);
      if ((uVar15 & 0xf) != 0) {
        uVar15 = uVar15 & 0xfffffff0;
        *(uint *)((longlong)param_1 + 0xd7fc) = uVar15;
      }
      uVar7 = *(uint *)((longlong)param_1 + 0x94);
      uVar14 = uVar15 - 0xb;
      *(uint *)((longlong)param_1 + 0xd804) = uVar14;
      if (0x1a < uVar7) {
        if (uVar7 < uVar14) {
          uVar14 = uVar7;
        }
        *(uint *)((longlong)param_1 + 0xd804) = uVar14;
      }
      *(uint *)((longlong)param_1 + 0xd808) = uVar15 + 0x10;
      if (uVar15 >> 2 < *(uint *)((longlong)param_1 + 0x9228)) {
        *(uint *)((longlong)param_1 + 0x9228) = uVar15 >> 2;
      }
      *(undefined2 *)(param_5 + 0x51) = 0x101;
      *(undefined1 *)(param_5 + 0x53) = 1;
      if (*(char *)(param_5 + 0x90) < '\0') {
        *(undefined1 *)((longlong)param_1 + 0xd92a) = 1;
        *(undefined1 *)(param_5 + 0x90) = 4;
        *(undefined4 *)(param_5 + 0xd8) = 0;
      }
      else {
        *(undefined1 *)((longlong)param_1 + 0xd92a) = 0;
      }
      *(undefined4 *)(param_5 + 0xcc) = *(undefined4 *)((longlong)param_1 + 0xd804);
      *(undefined1 *)((longlong)param_1 + 0xd859) = 1;
      if ((local_194 != '\0') && ((*(uint *)((longlong)param_1 + 0xd2e0) & 0x6000000) != 0)) {
        *(undefined1 *)((longlong)param_1 + 0xd858) = 1;
      }
      iVar16 = 0;
      do {
        uVar15 = *(uint *)(*(longlong *)((longlong)param_1 + 0x80) + 0xb4);
        iVar16 = iVar16 + 1;
        if (uVar15 != 0) break;
      } while (iVar16 < (int)(uint)*(byte *)((longlong)param_1 + 0x88));
      if (*(char *)((longlong)param_1 + 0xd858) == '\0') {
        *(undefined1 *)((longlong)param_1 + 0xd85a) = 0;
      }
      else {
        *(undefined4 *)(param_5 + 0xa0) = 2;
        *(code **)(param_5 + 0x98) = MessageInterrupts;
        if (*(char *)((longlong)param_1 + 0x89) == '\0') {
          plVar18 = (longlong *)((longlong)param_1 + 0xe3b8);
          uVar14 = (uVar15 >> 0xe & 0xff) + 1;
          if (uVar14 < 0x11) {
            *(char *)((longlong)param_1 + 0xd859) = (char)uVar14;
            *plVar18 = *(longlong *)((longlong)param_1 + 0x80) + 0x6c;
            uVar14 = (uint)*(byte *)((longlong)param_1 + 0xd859);
          }
          else {
            lVar17 = 0;
            lVar23 = 0x10;
            do {
              lVar13 = *(longlong *)((longlong)param_1 + 0x80) + 0x30c + lVar17;
              lVar17 = lVar17 + 0x10;
              *plVar18 = lVar13;
              plVar18 = plVar18 + 1;
              lVar23 = lVar23 + -1;
            } while (lVar23 != 0);
            *(char *)((longlong)param_1 + 0xd859) = (char)uVar14;
          }
          bVar3 = *(byte *)((longlong)param_1 + 0x90);
          if ((bVar3 != 0) && (bVar3 < (byte)uVar14)) {
            *(byte *)((longlong)param_1 + 0xd859) = bVar3;
          }
          if (((*(uint *)((longlong)param_1 + 0xe45c) & 0x1fe) == 0) && ((uVar15 >> 0x1a & 1) != 0))
          {
            *(undefined2 *)((longlong)param_1 + 0xeb68) = 0x101;
            iVar16 = StorPortExtendedFunction(0x14,param_1,(longlong)param_1 + 0xeb6c);
            if (iVar16 != 0) {
              *(undefined1 *)((longlong)param_1 + 0xeb68) = 0;
            }
            iVar16 = StorPortExtendedFunction(0x12,param_1,(longlong)param_1 + 0xeb72);
            if (iVar16 != 0) {
              *(undefined1 *)((longlong)param_1 + 0xeb68) = 0;
            }
            if (4 < *(ushort *)((longlong)param_1 + 0xeb72)) {
              *(undefined1 *)((longlong)param_1 + 0xeb68) = 0;
            }
            if (*(uint *)((longlong)param_1 + 0xeb6c) < 9) {
              *(uint *)((longlong)param_1 + 0xeb78) = *(uint *)((longlong)param_1 + 0xeb6c) * 8;
            }
            else {
              *(undefined1 *)((longlong)param_1 + 0xeb68) = 0;
            }
          }
        }
      }
      lVar17 = 0x80;
      *(byte *)((longlong)param_1 + 0xe8ac) = (byte)(uVar15 >> 0x18) & 1;
      cVar4 = *(char *)((longlong)param_1 + 0x89);
      *(undefined4 *)((longlong)param_1 + 0xe4ac) = 0x400;
      if (cVar4 == '\0') {
        sVar10 = 0x80;
        if ((uVar15 >> 0x16 & 1) != 0) {
          sVar10 = 0x200;
        }
        sVar11 = 0x10;
        uVar9 = sVar10 * ((ushort)(uVar15 >> 5) & 0x1f);
        uVar6 = 0x8000;
        *(byte *)((longlong)param_1 + 0xe8a4) = (byte)(uVar15 >> 0x16) & 1;
        uVar25 = (uVar9 >> 4) + 7;
        do {
          if ((uVar25 & uVar6) != 0) {
            uVar25 = uVar6 + 1;
            break;
          }
          uVar6 = uVar6 >> 1;
          sVar11 = sVar11 + -1;
        } while (sVar11 != 0);
        *(int *)(param_5 + 0x8c) = *(int *)(param_5 + 0x8c) + (uVar9 - 0x400);
        cVar4 = *(char *)((longlong)param_1 + 0x89);
        *(uint *)((longlong)param_1 + 0xe4ac) = (uint)uVar9;
      }
      uVar9 = *(ushort *)((longlong)param_1 + 0xd302);
      iVar16 = (uint)uVar9 * 0x15 + 0x72b0 +
               ((uint)*(byte *)((longlong)param_1 + 0x180) * 0x20 +
               *(int *)((longlong)param_1 + 0xd7fc)) * 8;
      if (cVar4 == '\0') {
        iVar16 = iVar16 + 0xfb990 +
                 (uint)*(ushort *)((longlong)param_1 + 0xeb72) * (uVar9 + 8) +
                 *(int *)((longlong)param_1 + 0xeb6c) * (uVar9 + 0x38) + (uint)uVar9 * 0xe1e +
                 *(int *)((longlong)param_1 + 0xeb48);
      }
      local_190 = ((uint)uVar9 +
                  ((uint)*(byte *)((longlong)param_1 + 0xd859) *
                   *(int *)((longlong)param_1 + 0xd808) +
                  (*(int *)((longlong)param_1 + 0xd7fc) + 1) * 0x20) * 4) * 2;
      if (*(char *)((longlong)param_1 + 0xd928) != '\0') {
        local_190 = local_190 + (*(int *)((longlong)param_1 + 0xd800) + (uint)uVar9) * 2;
      }
      local_184 = local_190 + iVar16 + *(int *)((longlong)param_1 + 0xd804) * 0x12;
      *(uint *)(param_5 + 0x1c) = (uint)uVar25;
      *(undefined4 *)(param_5 + 0x18) = 0x3fffff;
      _Dst = (void *)StorPortGetUncachedExtension(param_1,param_5,local_184);
      if (_Dst != (void *)0x0) {
        memset(_Dst,0,(ulonglong)local_184);
        uVar9 = *(ushort *)((longlong)param_1 + 0xd302);
        _Dst_00 = (void *)((longlong)_Dst + (ulonglong)uVar9 & (longlong)(int)~(uint)uVar9);
        *(void **)((longlong)param_1 + 0xa8) = _Dst_00;
        memmove(_Dst_00,"megasas35.sys",0xd);
        *(undefined1 *)(*(longlong *)((longlong)param_1 + 0xa8) + 0xd) = 0x20;
        memmove((void *)(*(longlong *)((longlong)param_1 + 0xa8) + 0xe),"7.717.02.00",0xc);
        *(undefined1 *)(*(longlong *)((longlong)param_1 + 0xa8) + 0x19) = 0;
        uVar21 = (longlong)_Dst +
                 (ulonglong)*(ushort *)((longlong)param_1 + 0xd302) + (ulonglong)(uVar9 + 0x80);
        *(ulonglong *)((longlong)param_1 + 0xeb08) =
             (longlong)(int)~(uint)*(ushort *)((longlong)param_1 + 0xd302) & uVar21;
        lVar23 = 0;
        do {
          *(undefined1 *)(lVar23 + *(longlong *)((longlong)param_1 + 0xeb08)) = 0;
          lVar17 = lVar17 + -1;
          lVar23 = lVar23 + 1;
        } while (lVar17 != 0);
        uVar20 = uVar21 + 0x80 + (ulonglong)*(ushort *)((longlong)param_1 + 0xd302) &
                 (longlong)(int)~(uint)*(ushort *)((longlong)param_1 + 0xd302);
        *(ulonglong *)((longlong)param_1 + 0x160) = uVar20;
        uVar8 = StorPortGetPhysicalAddress(param_1,0,uVar20,local_198);
        *(undefined8 *)((longlong)param_1 + 0x168) = uVar8;
        uVar9 = *(ushort *)((longlong)param_1 + 0xd302);
        lVar17 = uVar21 + 0x1888 + (ulonglong)uVar9;
        uVar21 = (ulonglong)uVar9 + lVar17 & (longlong)(int)~(uint)uVar9;
        *(ulonglong *)((longlong)param_1 + 0x1d8) = uVar21;
        uVar8 = StorPortGetPhysicalAddress(param_1,0,uVar21,local_198);
        *(undefined8 *)((longlong)param_1 + 0x1e0) = uVar8;
        uVar9 = *(ushort *)((longlong)param_1 + 0xd302);
        lVar17 = lVar17 + 0x10 + (ulonglong)uVar9;
        uVar21 = (ulonglong)uVar9 + lVar17 & (longlong)(int)~(uint)uVar9;
        *(ulonglong *)((longlong)param_1 + 0x170) = uVar21;
        uVar8 = StorPortGetPhysicalAddress(param_1,0,uVar21,local_198);
        *(undefined8 *)((longlong)param_1 + 0x178) = uVar8;
        uVar9 = *(ushort *)((longlong)param_1 + 0xd302);
        lVar17 = lVar17 + 0x100 + (ulonglong)uVar9;
        uVar21 = (ulonglong)uVar9 + lVar17 & (longlong)(int)~(uint)uVar9;
        *(ulonglong *)((longlong)param_1 + 0x1a8) = uVar21;
        uVar8 = StorPortGetPhysicalAddress(param_1,0,uVar21,local_198);
        uVar9 = *(ushort *)((longlong)param_1 + 0xd302);
        *(undefined8 *)((longlong)param_1 + 0x1b0) = uVar8;
        lVar17 = lVar17 + (ulonglong)*(byte *)((longlong)param_1 + 0x180) * 0x100 + 0x108 +
                          (ulonglong)uVar9;
        uVar21 = (ulonglong)uVar9 + lVar17 & (longlong)(int)~(uint)uVar9;
        *(ulonglong *)((longlong)param_1 + 0x198) = uVar21;
        uVar8 = StorPortGetPhysicalAddress(param_1,0,uVar21,local_198);
        *(undefined8 *)((longlong)param_1 + 0x1a0) = uVar8;
        uVar9 = *(ushort *)((longlong)param_1 + 0xd302);
        lVar17 = lVar17 + 0x990 + (ulonglong)uVar9;
        uVar21 = (ulonglong)uVar9 + lVar17 & (longlong)(int)~(uint)uVar9;
        *(ulonglong *)((longlong)param_1 + 0x1b8) = uVar21;
        uVar8 = StorPortGetPhysicalAddress(param_1,0,uVar21,local_198);
        *(undefined8 *)((longlong)param_1 + 0x1c0) = uVar8;
        uVar9 = *(ushort *)((longlong)param_1 + 0xd302);
        lVar17 = lVar17 + 0x200 + (ulonglong)uVar9;
        uVar21 = (ulonglong)uVar9 + lVar17 & (longlong)(int)~(uint)uVar9;
        *(ulonglong *)((longlong)param_1 + 0x1c8) = uVar21;
        uVar8 = StorPortGetPhysicalAddress(param_1,0,uVar21,local_198);
        *(undefined8 *)((longlong)param_1 + 0x1d0) = uVar8;
        uVar9 = *(ushort *)((longlong)param_1 + 0xd302);
        lVar17 = lVar17 + 0x200 + (ulonglong)uVar9;
        uVar21 = (ulonglong)uVar9 + lVar17 & (longlong)(int)~(uint)uVar9;
        *(ulonglong *)((longlong)param_1 + 0x1e8) = uVar21;
        uVar8 = StorPortGetPhysicalAddress(param_1,0,uVar21,local_198);
        uVar9 = *(ushort *)((longlong)param_1 + 0xd302);
        *(undefined8 *)((longlong)param_1 + 0x1f0) = uVar8;
        lVar17 = lVar17 + (ulonglong)(uVar9 + 0x800);
        if (*(char *)((longlong)param_1 + 0x89) == '\0') {
          uVar21 = lVar17 + (ulonglong)uVar9 & (longlong)(int)~(uint)uVar9;
          *(ulonglong *)((longlong)param_1 + 0x188) = uVar21;
          uVar8 = StorPortGetPhysicalAddress(param_1,0,uVar21,local_198);
          *(undefined8 *)((longlong)param_1 + 400) = uVar8;
          uVar21 = (ulonglong)*(ushort *)((longlong)param_1 + 0xd302);
          lVar23 = 6;
          uVar20 = (ulonglong)*(ushort *)((longlong)param_1 + 0xd302);
          lVar17 = uVar21 + 0x40 + lVar17;
          puVar19 = (ulonglong *)((longlong)param_1 + 0xe478);
          do {
            *puVar19 = uVar20 + lVar17 & (longlong)(int)~(uint)uVar21;
            uVar9 = *(ushort *)((longlong)param_1 + 0xd302);
            uVar21 = (ulonglong)uVar9;
            lVar17 = lVar17 + 8 + uVar21;
            uVar20 = (ulonglong)(uint)uVar9;
            lVar23 = lVar23 + -1;
            puVar19 = puVar19 + 1;
          } while (lVar23 != 0);
          uVar21 = uVar21 + lVar17 & (longlong)(int)~(uint)uVar9;
          *(ulonglong *)((longlong)param_1 + 0xd958) = uVar21;
          uVar8 = StorPortGetPhysicalAddress(param_1,0,uVar21,local_198);
          *(undefined8 *)((longlong)param_1 + 0xd968) = uVar8;
          uVar9 = *(ushort *)((longlong)param_1 + 0xd302);
          lVar17 = lVar17 + ((ulonglong)uVar9 + 0x10) * 0x100;
          uVar21 = (ulonglong)uVar9 + lVar17 & (longlong)(int)~(uint)uVar9;
          *(ulonglong *)((longlong)param_1 + 0xd960) = uVar21;
          uVar8 = StorPortGetPhysicalAddress(param_1,0,uVar21,local_198);
          *(undefined8 *)((longlong)param_1 + 0xd970) = uVar8;
          uVar9 = *(ushort *)((longlong)param_1 + 0xd302);
          lVar17 = lVar17 + ((ulonglong)uVar9 + 0x10) * 0x100;
          uVar21 = (ulonglong)uVar9 + lVar17 & (longlong)(int)~(uint)uVar9;
          *(ulonglong *)((longlong)param_1 + 0xd978) = uVar21;
          uVar8 = StorPortGetPhysicalAddress(param_1,0,uVar21,local_198);
          *(undefined8 *)((longlong)param_1 + 0xd980) = uVar8;
          uVar9 = *(ushort *)((longlong)param_1 + 0xd302);
          lVar17 = ((ulonglong)uVar9 + 0xc08) * 0x100 + lVar17;
          uVar21 = lVar17 + (ulonglong)uVar9 & (longlong)(int)~(uint)uVar9;
          *(ulonglong *)((longlong)param_1 + 0xd988) = uVar21;
          uVar8 = StorPortGetPhysicalAddress(param_1,0,uVar21,local_198);
          uVar24 = (ulonglong)*(ushort *)((longlong)param_1 + 0xd302);
          *(undefined8 *)((longlong)param_1 + 0xd990) = uVar8;
          uVar21 = (ulonglong)(int)~(uint)*(ushort *)((longlong)param_1 + 0xd302);
          lVar17 = uVar24 * 0x201 + lVar17;
          lVar23 = lVar17 + 0x14020;
          uVar20 = lVar17 + 0x4000U & uVar21;
          lVar17 = (uVar24 + 2) * 0x80 + lVar23;
          *(ulonglong *)((longlong)param_1 + 0xd750) = uVar20;
          *(ulonglong *)((longlong)param_1 + 0xe890) = uVar24 + lVar23 & uVar21;
          StorPortQuerySystemTime(uVar20 + 0x10010);
          uVar9 = *(ushort *)((longlong)param_1 + 0xd302);
          uVar21 = (ulonglong)uVar9;
          uVar24 = (ulonglong)(int)~(uint)uVar9;
          *(ulonglong *)((longlong)param_1 + 0xd818) = uVar21 + lVar17 & uVar24;
          lVar17 = (ulonglong)uVar9 * 0x100 + 0x18000 + lVar17;
          *(ulonglong *)((longlong)param_1 + 0xd820) = uVar21 + lVar17 & uVar24;
          lVar17 = lVar17 + (uVar21 + 0xa0) * 0x100;
          lVar23 = (ulonglong)uVar9 * 0x100 + 0x100 + lVar17;
          uVar20 = uVar21 + lVar23 & uVar24;
          *(ulonglong *)((longlong)param_1 + 0xe8e0) = uVar20;
          *(ulonglong *)((longlong)param_1 + 0xe8d0) = uVar21 + lVar17 & uVar24;
          uVar8 = StorPortGetPhysicalAddress(param_1,0,uVar20,local_198);
          *(undefined8 *)((longlong)param_1 + 0xe8e8) = uVar8;
          uVar9 = *(ushort *)((longlong)param_1 + 0xd302);
          lVar17 = lVar23 + 0x30 + (ulonglong)uVar9;
          uVar21 = (ulonglong)uVar9 + lVar17 & (longlong)(int)~(uint)uVar9;
          *(ulonglong *)((longlong)param_1 + 0xe8f0) = uVar21;
          uVar8 = StorPortGetPhysicalAddress(param_1,0,uVar21,local_198);
          *(undefined8 *)((longlong)param_1 + 0xe8f8) = uVar8;
          lVar17 = lVar17 + ((ulonglong)*(ushort *)((longlong)param_1 + 0xd302) + 0x110) * 0x14;
          **(undefined8 **)((longlong)param_1 + 0xe8e0) =
               *(undefined8 *)((longlong)param_1 + 0xe8f0);
          *(undefined8 *)(*(longlong *)((longlong)param_1 + 0xe8e0) + 0x10) =
               *(undefined8 *)((longlong)param_1 + 0xe8f0);
          *(undefined8 *)(*(longlong *)((longlong)param_1 + 0xe8e0) + 0x18) =
               *(undefined8 *)((longlong)param_1 + 0xe8f0);
          (*(longlong **)((longlong)param_1 + 0xe8e0))[1] =
               **(longlong **)((longlong)param_1 + 0xe8e0) + 0x1430;
          *(undefined8 *)(*(longlong *)((longlong)param_1 + 0xe8e0) + 0x28) = 0x110;
          uVar21 = lVar17 + (ulonglong)*(ushort *)((longlong)param_1 + 0xd302) &
                   (longlong)(int)~(uint)*(ushort *)((longlong)param_1 + 0xd302);
          *puVar2 = uVar21;
          uVar8 = StorPortGetPhysicalAddress(param_1,0,uVar21,local_198);
          uVar9 = *(ushort *)((longlong)param_1 + 0xd302);
          uVar21 = (ulonglong)uVar9;
          *(undefined8 *)((longlong)param_1 + 0xeb58) = uVar8;
          uVar20 = (ulonglong)(uint)uVar9;
          lVar17 = lVar17 + (ulonglong)(*(int *)((longlong)param_1 + 0xeb48) + (uint)uVar9);
          puVar19 = (ulonglong *)((longlong)param_1 + 0xeb98);
          lVar23 = 8;
          do {
            lVar13 = lVar23;
            *puVar19 = uVar20 + lVar17 & (longlong)(int)~(uint)uVar21;
            uVar21 = (ulonglong)*(ushort *)((longlong)param_1 + 0xd302);
            uVar20 = (ulonglong)*(ushort *)((longlong)param_1 + 0xd302);
            lVar17 = lVar17 + (uVar21 + 4) * 0x80;
            lVar23 = lVar13 + -1;
            puVar19 = puVar19 + 1;
          } while (lVar23 != 0);
          uVar24 = (ulonglong)((int)lVar13 + 3);
          puVar19 = (ulonglong *)((longlong)param_1 + 0xebd8);
          do {
            *puVar19 = uVar20 + lVar17 & (longlong)(int)~(uint)uVar21;
            uVar9 = *(ushort *)((longlong)param_1 + 0xd302);
            uVar21 = (ulonglong)uVar9;
            uVar20 = (ulonglong)uVar9;
            lVar17 = lVar17 + uVar21 * 0x40 + 0x40;
            uVar24 = uVar24 - 1;
            puVar19 = puVar19 + 1;
          } while (uVar24 != 0);
          uVar24 = (ulonglong)(int)~(uint)uVar9;
          *(ulonglong *)((longlong)param_1 + 0xeb88) = uVar20 + lVar17 & uVar24;
          lVar17 = lVar17 + (ulonglong)*(uint *)((longlong)param_1 + 0xeb6c) * (uVar20 + 0x38);
          *(ulonglong *)((longlong)param_1 + 0xeb90) = uVar20 + lVar17 & uVar24;
          uVar21 = (ulonglong)*(ushort *)((longlong)param_1 + 0xeb72) * (uVar20 + 8) + uVar20 +
                   lVar17;
          *(ulonglong *)((longlong)param_1 + 0xed88) = uVar21 & uVar24;
          lVar17 = uVar21 + 0x90;
          *(ulonglong *)((longlong)param_1 + 0xeb80) = uVar20 + lVar17 & uVar24;
          lVar17 = lVar17 + (uVar20 + 0x10) * 0x80;
        }
        *(undefined4 *)((longlong)param_1 + 0xeb64) = 1;
        *(undefined4 *)((longlong)param_1 + 0xeb60) = 0;
        RttInitTrace((longlong *)puVar2);
        if ((*(char *)((longlong)param_1 + 0xeb50) != '\0') &&
           ((*(uint *)((longlong)param_1 + 0xeb54) & 2) != 0)) {
          RttLogEvent((longlong)param_1,(longlong)param_1 + 0xeb00,(int *)puVar2,2,(undefined1 *)0x0
                      ,0,0,0);
        }
        uVar21 = (ulonglong)*(ushort *)((longlong)param_1 + 0xd302);
        plVar18 = (longlong *)((longlong)param_1 + 0x108);
        uVar20 = (ulonglong)*(ushort *)((longlong)param_1 + 0xd302);
        lVar23 = 0xb;
        do {
          uVar21 = uVar20 + lVar17 & (longlong)(int)~(uint)uVar21;
          plVar18[-0xb] = uVar21;
          lVar13 = StorPortGetPhysicalAddress(param_1,0,uVar21,local_198);
          *plVar18 = lVar13 + 0x100;
          plVar18 = plVar18 + 1;
          uVar9 = *(ushort *)((longlong)param_1 + 0xd302);
          uVar21 = (ulonglong)uVar9;
          lVar17 = lVar17 + 0x600 + uVar21;
          uVar20 = (ulonglong)(uint)uVar9;
          lVar23 = lVar23 + -1;
        } while (lVar23 != 0);
        *(ulonglong *)((longlong)param_1 + 0x208) = uVar21 + lVar17 & (longlong)(int)~(uint)uVar9;
        lVar17 = lVar17 + uVar20 + (ulonglong)*(uint *)((longlong)param_1 + 0xd7fc) * 8;
        *(longlong *)((longlong)param_1 + 0x1f8) = lVar17;
        uVar8 = StorPortGetPhysicalAddress(param_1,0,lVar17,local_198);
        *(undefined8 *)((longlong)param_1 + 0x200) = uVar8;
        lVar17 = lVar17 + (ulonglong)*(uint *)((longlong)param_1 + 0xd804) * 0x12;
        uVar21 = lVar17 + (ulonglong)*(ushort *)((longlong)param_1 + 0xd302) &
                 (longlong)(int)~(uint)*(ushort *)((longlong)param_1 + 0xd302);
        *(ulonglong *)((longlong)param_1 + 0xd998) = uVar21;
        uVar15 = 0;
        uVar21 = (ulonglong)(*(int *)((longlong)param_1 + 0xd7fc) + 1) * 0x100 + uVar21 +
                 (ulonglong)*(ushort *)((longlong)param_1 + 0xd302) &
                 (longlong)(int)~(uint)*(ushort *)((longlong)param_1 + 0xd302);
        if (*(char *)((longlong)param_1 + 0xd859) != '\0') {
          do {
            uVar20 = (ulonglong)uVar15;
            uVar24 = (ulonglong)uVar15;
            uVar15 = uVar15 + 1;
            *(ulonglong *)((longlong)param_1 + uVar20 * 0x10 + 0xd9a8) = uVar21;
            *(undefined2 *)((longlong)param_1 + (uVar24 + 0xd9a) * 0x10) = 0;
            uVar21 = uVar21 + (uint)(*(int *)((longlong)param_1 + 0xd808) << 3);
          } while (uVar15 < *(byte *)((longlong)param_1 + 0xd859));
        }
        if (*(char *)((longlong)param_1 + 0xd928) != '\0') {
          uVar21 = uVar21 + *(ushort *)((longlong)param_1 + 0xd302) &
                   (longlong)(int)~(uint)*(ushort *)((longlong)param_1 + 0xd302);
          *(ulonglong *)((longlong)param_1 + 0xd930) = uVar21;
          uVar8 = StorPortGetPhysicalAddress(param_1,0,uVar21,local_180);
          *(undefined8 *)((longlong)param_1 + 0xd940) = uVar8;
          uVar21 = (ulonglong)*(uint *)((longlong)param_1 + 0xd800) +
                   uVar21 + *(ushort *)((longlong)param_1 + 0xd302) &
                   (longlong)(int)~(uint)*(ushort *)((longlong)param_1 + 0xd302);
          *(ulonglong *)((longlong)param_1 + 0xd938) = uVar21;
          uVar8 = StorPortGetPhysicalAddress(param_1,0,uVar21,local_180);
          *(undefined8 *)((longlong)param_1 + 0xd948) = uVar8;
          uVar21 = uVar21 + *(uint *)((longlong)param_1 + 0xd800);
        }
        if ((ulonglong)local_190 + lVar17 < uVar21) {
          *(undefined1 *)((longlong)param_1 + 0xd911) = 1;
          if (*(char *)((longlong)param_1 + 0xeb50) == '\0') {
            return 2;
          }
          if ((*(uint *)((longlong)param_1 + 0xeb54) & 0x200087) == 0) {
            return 2;
          }
          uVar22 = 0x200087;
        }
        else {
          if (*(char *)((longlong)param_1 + 0xeb68) != '\0') {
            MR_HybridInterruptCoalescing((longlong)param_1);
          }
          uVar8 = WaitForInitializeWithRetry((longlong)param_1);
          if ((char)uVar8 != '\0') {
            *(uint *)((longlong)param_1 + 0xd7f4) = (uint)uVar25;
            *(uint *)((longlong)param_1 + 0xd7f0) = (uint)uVar25 * 0x1000 + -0x1000;
            uVar15 = *(uint *)((longlong)param_1 + 0xd7f4);
            if ((uint)*(byte *)((longlong)param_1 + 0xd2e2) <= *(uint *)((longlong)param_1 + 0xd7f4)
               ) {
              uVar15 = (uint)*(byte *)((longlong)param_1 + 0xd2e2);
            }
            *(uint *)((longlong)param_1 + 0xd7f8) = uVar15;
            uVar15 = *(uint *)((longlong)param_1 + 0x98);
            if (uVar15 != 0) {
              uVar14 = *(uint *)((longlong)param_1 + 0xd7f4);
              if (uVar15 >> 0xc <= *(uint *)((longlong)param_1 + 0xd7f4)) {
                uVar14 = uVar15 >> 0xc;
              }
              uVar7 = *(uint *)((longlong)param_1 + 0xd7f0);
              if (uVar15 <= uVar14 * 0x1000) {
                uVar7 = uVar15;
              }
              *(uint *)((longlong)param_1 + 0xd7f0) = uVar7;
            }
            *(undefined4 *)(param_5 + 0x18) = *(undefined4 *)((longlong)param_1 + 0xd7f0);
            *(undefined4 *)(param_5 + 0x1c) = *(undefined4 *)((longlong)param_1 + 0xd7f4);
            local_50 = *(undefined4 *)((longlong)param_1 + 0xd804);
            cVar4 = *(char *)((longlong)param_1 + 0xeb50);
            local_58 = *(undefined1 *)((longlong)param_1 + 0xd859);
            local_52 = *(undefined2 *)((longlong)param_1 + 0xd7f4);
            local_4c = *(undefined4 *)((longlong)param_1 + 0xd7f0);
            local_48 = local_184;
            local_57 = *(undefined1 *)((longlong)param_1 + 0xd82c);
            local_56 = *(undefined1 *)((longlong)param_1 + 0xd828);
            local_55 = *(undefined1 *)((longlong)param_1 + 0xd85a);
            local_54 = local_15e;
            local_53 = *(undefined1 *)((longlong)param_1 + 0xd928);
            if ((cVar4 != '\0') && ((*(uint *)((longlong)param_1 + 0xeb54) & 0x200083) != 0)) {
              RttLogEvent((longlong)param_1,(longlong)param_1 + 0xeb00,(int *)puVar2,0x200083,
                          &local_58,0x14,0,0);
              cVar4 = *(char *)((longlong)param_1 + 0xeb50);
            }
            uVar15 = *(uint *)((longlong)param_1 + 0xe45c);
            local_18c = (undefined1)(uVar15 >> 1);
            local_18b = (byte)(uVar15 >> 9) & 1;
            local_18a = (byte)(uVar15 >> 10) & 1;
            if ((cVar4 != '\0') && ((*(uint *)((longlong)param_1 + 0xeb54) & 0x200081) != 0)) {
              RttLogEvent((longlong)param_1,(longlong)param_1 + 0xeb00,(int *)puVar2,0x200081,
                          &local_18c,3,0,0);
              cVar4 = *(char *)((longlong)param_1 + 0xeb50);
            }
            local_188 = *(undefined1 *)((longlong)param_1 + 0xe8ac);
            local_187 = *(undefined1 *)((longlong)param_1 + 0xe8a4);
            local_186 = *(undefined1 *)((longlong)param_1 + 0xeb69);
            local_185 = *(undefined1 *)((longlong)param_1 + 0xeb68);
            if ((cVar4 != '\0') && ((*(uint *)((longlong)param_1 + 0xeb54) & 0x200082) != 0)) {
              RttLogEvent((longlong)param_1,(longlong)param_1 + 0xeb00,(int *)puVar2,0x200082,
                          &local_188,4,0,0);
              cVar4 = *(char *)((longlong)param_1 + 0xeb50);
            }
            local_60 = *(undefined4 *)((longlong)param_1 + 4);
            local_68 = *(undefined1 *)((longlong)param_1 + 8);
            local_5c = *(undefined4 *)((longlong)param_1 + 0x54);
            local_67 = *(undefined1 *)((longlong)param_1 + 9);
            local_66 = *(undefined1 *)((longlong)param_1 + 10);
            local_65 = local_15e;
            local_64 = *(ushort *)((longlong)param_1 + 0x50) & 0xf;
            local_62 = *(ushort *)((longlong)param_1 + 0x4c) & 0xf;
            if ((cVar4 != '\0') && ((*(uint *)((longlong)param_1 + 0xeb54) & 0x20008a) != 0)) {
              RttLogEvent((longlong)param_1,(longlong)param_1 + 0xeb00,(int *)puVar2,0x20008a,
                          &local_68,0x10,0,0);
            }
            *(undefined2 *)(param_5 + 0x48) = 0x702;
            *(undefined1 *)(param_5 + 0x61) = 0xff;
            *(undefined1 *)(param_5 + 0x92) = 8;
            *(undefined4 *)(param_5 + 0x94) = 1;
            local_190 = 0xff000073;
            *(undefined4 *)((longlong)param_1 + 0xd7ac) = 0xff000073;
            *(undefined1 *)(param_5 + 0x93) = 1;
            MegaSASWmiInitialize((longlong)param_1);
            if (*(char *)((longlong)param_1 + 0x89) == '\0') {
              iVar16 = StorPortExtendedFunction(0x20,param_1,(longlong)param_1 + 0xe8b8);
              if (iVar16 == 0) {
                if ((*(char *)((longlong)param_1 + 0xeb50) == '\0') ||
                   ((*(uint *)((longlong)param_1 + 0xeb54) & 0x200085) == 0)) goto LAB_14000a9ed;
                uVar22 = 0x200085;
              }
              else {
                *(undefined8 *)((longlong)param_1 + 0xe8b8) = 0;
                if ((*(char *)((longlong)param_1 + 0xeb50) == '\0') ||
                   ((*(uint *)((longlong)param_1 + 0xeb54) & 0x200084) == 0)) goto LAB_14000a9ed;
                uVar22 = 0x200084;
              }
              RttLogEvent((longlong)param_1,(longlong)param_1 + 0xeb00,(int *)puVar2,uVar22,
                          (undefined1 *)0x0,0,0,0);
            }
LAB_14000a9ed:
            *local_178 = 1;
            return 1;
          }
          *(undefined1 *)((longlong)param_1 + 0xd911) = 1;
          if (*(char *)((longlong)param_1 + 0xeb50) == '\0') {
            return 2;
          }
          if ((*(uint *)((longlong)param_1 + 0xeb54) & 0x200088) == 0) {
            return 2;
          }
          uVar22 = 0x200088;
        }
        RttLogEvent((longlong)param_1,(longlong)param_1 + 0xeb00,(int *)puVar2,uVar22,
                    (undefined1 *)0x0,0,0,0);
        return 2;
      }
    }
  }
  uVar8 = 2;
  goto LAB_1400095e5;
}



===== MegaSASPnPControl @ 14000aa10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 MegaSASPnPControl(longlong param_1,int param_2,uint *param_3)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined1 auStack_48 [32];
  undefined4 local_28;
  undefined1 local_24;
  undefined8 local_23;
  undefined4 local_1b;
  undefined2 local_17;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  uVar4 = 0;
  if (param_2 == 0) {
    if (param_3 != (uint *)0x0) {
      local_28 = 0x10101;
      local_24 = 0;
      local_23 = 0;
      local_1b = 0;
      local_17 = 0;
      uVar5 = 0;
      if (*param_3 != 0) {
        do {
          uVar1 = (int)uVar5 + 1;
          *(undefined1 *)((longlong)param_3 + uVar5 + 4) = auStack_48[uVar5 + 0x20];
          uVar5 = (ulonglong)uVar1;
        } while (uVar1 < *param_3);
      }
    }
  }
  else if (param_2 == 1) {
    DAT_140016504 = DAT_140016504 + -1;
    *(undefined1 *)(param_1 + 0xd2e9) = 0;
    if (*(int *)(param_1 + 0xd924) != 3) {
      StopAllTimerRoutine(param_1);
      if (*(int *)(param_1 + 0xe43c) != 1) {
        Fusion_DisableInterrupt(param_1);
        *(uint *)(param_1 + 0xd810) = *(uint *)(param_1 + 0xd810) | 0x10;
        *(undefined1 *)(param_1 + 0xd910) = 1;
        if (*(char *)(param_1 + 0xd911) == '\0') {
          *(undefined2 *)(param_1 + 0xd920) = 0;
          uVar1 = Fusion_ReadRegister(param_1,*(longlong *)(param_1 + 0x80));
          *(uint *)(param_1 + 0xd2e0) = uVar1;
          if ((uVar1 & 0xf0000000) == 0xc0000000) {
            AbortPendedCommands(param_1);
            *(undefined4 *)(param_1 + 0xd918) = 180000000;
            SendAndWaitDCMD(param_1,0x1101000,7);
            *(undefined4 *)(param_1 + 0xd918) = 180000000;
            uVar1 = 0x1060000;
            if (*(char *)(param_1 + 0xd307) != '\0') {
              uVar1 = 0x1050000;
            }
            SendAndWaitDCMD(param_1,uVar1,7);
          }
        }
      }
    }
  }
  else if (param_2 == 2) {
    Fusion_DisableInterrupt(param_1);
    *(uint *)(param_1 + 0xd810) = *(uint *)(param_1 + 0xd810) | 0x10;
    *(undefined1 *)(param_1 + 0xd910) = 1;
    DoPauseInput(param_1,7,0);
    DAT_140016504 = DAT_140016504 + '\x01';
    lVar2 = 0;
    lVar3 = 0xff;
    *(undefined1 *)(param_1 + 0xd307) = 0;
    *(undefined2 *)(param_1 + 0xd920) = 0x200;
    *(undefined2 *)(param_1 + 0xd2e8) = 0;
    do {
      *(undefined4 *)(lVar2 + 0x92e0 + param_1) = 0;
      *(undefined4 *)(lVar2 + 0xb2e0 + param_1) = 0;
      lVar2 = lVar2 + 0x20;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
    *(undefined8 *)(param_1 + 0xe440) = 0;
    memset(*(void **)(param_1 + 0x208),0,(ulonglong)*(uint *)(param_1 + 0xd804) << 3);
    *(undefined4 *)(param_1 + 0xd918) = 600000000;
    StorPortNotification(6,param_1,TimeForFwareReadyInitWithRetry,250000);
  }
  else {
    uVar4 = 1;
  }
  return uVar4;
}



===== CopyPerfMetricData @ 14000ac30 =====

void CopyPerfMetricData(longlong param_1,longlong param_2)

{
  short *psVar1;
  uint *puVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  size_t _Size;
  byte bVar6;
  
  bVar6 = 0;
  if (*(short *)(param_1 + 0xd308) != 0) {
    do {
      uVar5 = (ulonglong)bVar6;
      lVar3 = uVar5 * 0x78;
      puVar2 = (uint *)(*(longlong *)(param_1 + 0xd750) + 0xc + lVar3);
      *puVar2 = *puVar2 >> 0xb;
      puVar2 = (uint *)(*(longlong *)(param_1 + 0xd750) + 0x10 + lVar3);
      *puVar2 = *puVar2 >> 0xb;
      *(byte *)(*(longlong *)(param_1 + 0xd750) + 4 + lVar3) = bVar6;
      bVar6 = bVar6 + 1;
      lVar4 = param_2 - *(longlong *)(*(longlong *)(param_1 + 0xd750) + 0xf808 + uVar5 * 8);
      lVar4 = SUB168(SEXT816(-0x29406b2a1a85bd43) * SEXT816(lVar4),8) + lVar4;
      psVar1 = (short *)(lVar3 + *(longlong *)(param_1 + 0xd750) + 6);
      *psVar1 = *psVar1 + ((short)(lVar4 >> 0x17) - (short)(lVar4 >> 0x3f));
    } while ((ushort)bVar6 < *(ushort *)(param_1 + 0xd308));
  }
  *(uint *)(*(longlong *)(param_1 + 0xd750) + 0x10018) =
       (uint)((int)param_2 - *(int *)(*(longlong *)(param_1 + 0xd750) + 0x10010)) / 10000000;
  if (*(ushort *)(param_1 + 0xd308) != 0) {
    _Size = (ulonglong)*(ushort *)(param_1 + 0xd308) * 0x78;
    memmove((void *)(*(longlong *)(param_1 + 0xd750) + 0x7804),
            (void *)(*(longlong *)(param_1 + 0xd750) + 4),_Size);
    memset((void *)(*(longlong *)(param_1 + 0xd750) + 4),0,_Size);
  }
  return;
}



===== ProcessPerfMetricAEN @ 14000ad40 =====

void ProcessPerfMetricAEN(longlong param_1,int param_2)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  longlong local_res18 [2];
  
  StorPortQuerySystemTime(local_res18);
  if (param_2 == 0) {
    pcVar1 = *(char **)(param_1 + 0xd750);
    if (*pcVar1 != '\0') {
      CopyPerfMetricData(param_1,local_res18[0]);
      pcVar1 = *(char **)(param_1 + 0xd750);
    }
    *(longlong *)(pcVar1 + 0x10010) = local_res18[0];
    lVar3 = 0x100;
    lVar2 = 0xf808;
    do {
      *(longlong *)(lVar2 + *(longlong *)(param_1 + 0xd750)) = local_res18[0];
      lVar3 = lVar3 + -1;
      lVar2 = lVar2 + 8;
    } while (lVar3 != 0);
    **(undefined1 **)(param_1 + 0xd750) = 1;
  }
  else if ((param_2 == 1) && (**(char **)(param_1 + 0xd750) != '\0')) {
    **(char **)(param_1 + 0xd750) = '\0';
    CopyPerfMetricData(param_1,local_res18[0]);
    return;
  }
  return;
}



===== ProcessPerfMetricRequest @ 14000ae00 =====

void ProcessPerfMetricRequest(longlong param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  uint uVar4;
  
  if (0x183 < param_3) {
    uVar1 = *param_2;
    uVar2 = (ulonglong)uVar1;
    if (0x103 < uVar1) {
      uVar3 = 0x100;
      if (*(ushort *)(param_1 + 0xd308) < 0x101) {
        uVar3 = (uint)*(ushort *)(param_1 + 0xd308);
      }
      uVar3 = uVar3 * 0x78;
      uVar4 = uVar3 + 8;
      if (uVar3 == 0) {
        uVar4 = 0;
      }
      if (param_3 < uVar1 + 8 + uVar3) {
        param_2[0x41] = uVar4;
        param_2[0x42] = *(uint *)(*(longlong *)(param_1 + 0xd750) + 0x10018);
        return;
      }
      *(uint *)((longlong)param_2 + uVar2) = uVar4;
      *(undefined4 *)((longlong)param_2 + uVar2 + 4) =
           *(undefined4 *)(*(longlong *)(param_1 + 0xd750) + 0x10018);
      if (uVar3 != 0) {
        memmove((void *)((longlong)param_2 + uVar2 + 8),
                (void *)(*(longlong *)(param_1 + 0xd750) + 0x7804),(ulonglong)uVar3);
      }
    }
  }
  return;
}



===== UpdateIOMetric @ 14000aec0 =====

void UpdateIOMetric(longlong param_1,byte param_2,char param_3,longlong param_4,int param_5,
                   uint param_6)

{
  char *pcVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  
  if ((*(char *)(param_1 + 0x89) == '\0') &&
     (pcVar1 = *(char **)(param_1 + 0xd750), *pcVar1 != '\0')) {
    uVar5 = (ulonglong)param_2;
    uVar3 = param_4 * (ulonglong)(param_6 >> 9);
    uVar4 = param_5 * (param_6 >> 9);
    if (param_3 == '\0') {
      *(uint *)(pcVar1 + uVar5 * 0x78 + 0x10) = *(int *)(pcVar1 + uVar5 * 0x78 + 0x10) + uVar4;
      lVar6 = 0x2c;
      lVar7 = 0x60;
    }
    else {
      *(uint *)(pcVar1 + uVar5 * 0x78 + 0xc) = *(int *)(pcVar1 + uVar5 * 0x78 + 0xc) + uVar4;
      lVar6 = 0x14;
      lVar7 = 0x44;
    }
    StorPortQuerySystemTime(*(longlong *)(param_1 + 0xd750) + (uVar5 + 0x1f01) * 8);
    if (uVar4 < 2) {
      *(int *)(pcVar1 + lVar6 + uVar5 * 0x78) = *(int *)(pcVar1 + lVar6 + uVar5 * 0x78) + 1;
    }
    else if (uVar4 < 9) {
      *(int *)(pcVar1 + lVar6 + uVar5 * 0x78 + 4) = *(int *)(pcVar1 + lVar6 + uVar5 * 0x78 + 4) + 1;
    }
    else if (uVar4 < 0x21) {
      *(int *)(pcVar1 + lVar6 + uVar5 * 0x78 + 8) = *(int *)(pcVar1 + lVar6 + uVar5 * 0x78 + 8) + 1;
    }
    else if (uVar4 < 0x81) {
      *(int *)(pcVar1 + lVar6 + uVar5 * 0x78 + 0xc) =
           *(int *)(pcVar1 + lVar6 + uVar5 * 0x78 + 0xc) + 1;
    }
    else if (uVar4 < 0x101) {
      *(int *)(pcVar1 + lVar6 + uVar5 * 0x78 + 0x10) =
           *(int *)(pcVar1 + lVar6 + uVar5 * 0x78 + 0x10) + 1;
    }
    else {
      *(int *)(pcVar1 + lVar6 + uVar5 * 0x78 + 0x14) =
           *(int *)(pcVar1 + lVar6 + uVar5 * 0x78 + 0x14) + 1;
    }
    uVar2 = *(ulonglong *)(*(longlong *)(param_1 + 0xd750) + 0xf008 + uVar5 * 8);
    if (uVar2 == uVar3) {
      *(int *)(pcVar1 + lVar7 + uVar5 * 0x78) = *(int *)(pcVar1 + lVar7 + uVar5 * 0x78) + 1;
      return;
    }
    if (uVar2 + 0x80 <= uVar3) {
      *(int *)(pcVar1 + lVar7 + uVar5 * 0x78 + 4) = *(int *)(pcVar1 + lVar7 + uVar5 * 0x78 + 4) + 1;
      return;
    }
    if (uVar2 + 0x400 <= uVar3) {
      *(int *)(pcVar1 + lVar7 + uVar5 * 0x78 + 8) = *(int *)(pcVar1 + lVar7 + uVar5 * 0x78 + 8) + 1;
      return;
    }
    if (uVar2 + 0x8000 <= uVar3) {
      *(int *)(pcVar1 + lVar7 + uVar5 * 0x78 + 0xc) =
           *(int *)(pcVar1 + lVar7 + uVar5 * 0x78 + 0xc) + 1;
      return;
    }
    if (uVar2 + 0x80000 <= uVar3) {
      *(int *)(pcVar1 + lVar7 + uVar5 * 0x78 + 0x10) =
           *(int *)(pcVar1 + lVar7 + uVar5 * 0x78 + 0x10) + 1;
      return;
    }
    if (uVar2 + 0x200000 <= uVar3) {
      *(int *)(pcVar1 + lVar7 + uVar5 * 0x78 + 0x14) =
           *(int *)(pcVar1 + lVar7 + uVar5 * 0x78 + 0x14) + 1;
      return;
    }
    *(int *)(pcVar1 + lVar7 + uVar5 * 0x78 + 0x18) =
         *(int *)(pcVar1 + lVar7 + uVar5 * 0x78 + 0x18) + 1;
  }
  return;
}



===== MFI_BuildFrame_NonRW @ 14000b0b0 =====

undefined8 MFI_BuildFrame_NonRW(longlong param_1,longlong *param_2)

{
  byte *pbVar1;
  int *piVar2;
  longlong lVar3;
  undefined1 uVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  longlong lVar9;
  int *piVar10;
  int iVar11;
  longlong lVar12;
  undefined1 local_res10 [8];
  undefined1 local_res18;
  undefined1 local_res19;
  undefined1 local_res1a;
  int local_res1c;
  
  lVar9 = *param_2;
  pbVar1 = (byte *)(param_2 + 0x20);
  *(undefined1 *)(param_2 + 0x12) = 1;
  iVar11 = 0;
  *(undefined2 *)((longlong)param_2 + 0x101) = 0;
  *(undefined2 *)(param_2 + 0x22) = 0;
  param_2[0x23] = 0;
  param_2[0x21] = 0;
  *(undefined1 *)((longlong)param_2 + 0x103) = 0;
  if (*(char *)(lVar9 + 5) == '\0') {
    *pbVar1 = 4;
    uVar4 = *(undefined1 *)(lVar9 + 7);
  }
  else {
    *pbVar1 = 3;
    uVar4 = 0;
  }
  *(undefined1 *)((longlong)param_2 + 0x105) = uVar4;
  *(undefined1 *)((longlong)param_2 + 0x104) = *(undefined1 *)(lVar9 + 6);
  uVar5 = *(uint *)(lVar9 + 0xc);
  if ((uVar5 & 0xc0) == 0) {
    *(ushort *)(param_2 + 0x22) = *(ushort *)(param_2 + 0x22) & 0xffe7;
    uVar5 = *(uint *)(lVar9 + 0xc);
  }
  if ((char)uVar5 < '\0') {
    *(ushort *)(param_2 + 0x22) = *(ushort *)(param_2 + 0x22) & 0xffef | 8;
    uVar5 = *(uint *)(lVar9 + 0xc);
  }
  if ((uVar5 & 0x40) != 0) {
    *(ushort *)(param_2 + 0x22) = *(ushort *)(param_2 + 0x22) | 0x10;
  }
  param_2[0xc] = (longlong)(param_2 + 0x26);
  param_2[0xb] = (longlong)(param_2 + 0x26);
  if ((*(int *)(lVar9 + 0x10) != 0) &&
     (uVar7 = BuildSGLforSRB(param_1,param_2), (char)uVar7 == '\0')) {
    lVar9 = *param_2;
    lVar3 = param_2[3];
    if (*(char *)(param_1 + 0x91) == '\0') {
      StorPortBusy(param_1,*(undefined4 *)(param_1 + 0x9228));
    }
    else {
      *(undefined1 *)(lVar9 + 4) = 0x28;
    }
    *(undefined1 *)(lVar9 + 3) = 5;
    piVar10 = (int *)(param_1 + 0x92e0);
    lVar12 = 0xff;
    do {
      piVar2 = piVar10 + 0x800;
      iVar6 = *piVar10;
      piVar10 = piVar10 + 8;
      iVar11 = iVar11 + *piVar2 + iVar6;
      lVar12 = lVar12 + -1;
    } while (lVar12 != 0);
    local_res19 = *(undefined1 *)(lVar9 + 5);
    local_res18 = *(undefined1 *)(lVar9 + 6);
    local_res1a = *(undefined1 *)(lVar9 + 0x48);
    local_res1c = iVar11;
    if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x2a9) != 0)) {
      RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x2a9,&local_res18,8,
                  (char)lVar3,3);
    }
    uVar8 = StorPortNotification(0,param_1,lVar9);
    return uVar8 & 0xffffffffffffff00;
  }
  *(char *)((longlong)param_2 + 0x107) = (char)param_2[10];
  if ((char)param_2[10] != '\0') {
    iVar6 = ((uint)*(byte *)((longlong)param_2 + 0x52) * (uint)*(ushort *)(param_2 + 10) +
             *(int *)(&DAT_140016300 + (ulonglong)*pbVar1 * 4) + 0x3f >> 6 & 0xff) - 1;
    iVar11 = 7;
    if (iVar6 < 7) {
      iVar11 = iVar6;
    }
    *(char *)((longlong)param_2 + 0x91) = (char)iVar11;
  }
  *(undefined1 *)((longlong)param_2 + 0x106) = *(undefined1 *)(lVar9 + 10);
  *(undefined4 *)((longlong)param_2 + 0x114) = *(undefined4 *)(lVar9 + 0x10);
  *(ushort *)(param_2 + 0x22) =
       (ushort)(*(byte *)((longlong)param_2 + 0x34) & 1 | 0x10) * 2 |
       *(ushort *)(param_2 + 0x22) & 0xfffd;
  *(undefined2 *)((longlong)param_2 + 0x112) = *(undefined2 *)(lVar9 + 0x14);
  memmove(param_2 + 0x24,(void *)(lVar9 + 0x48),(ulonglong)*(byte *)(lVar9 + 10));
  lVar9 = StorPortGetPhysicalAddress(param_1,lVar9,pbVar1,local_res10);
  param_2[4] = lVar9;
  return CONCAT71((int7)((ulonglong)lVar9 >> 8),1);
}



===== MFI_SendRequestToFW @ 14000b300 =====

void MFI_SendRequestToFW(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  
  lVar1 = *param_2;
  *(undefined4 *)(param_2 + 0x21) = *(undefined4 *)((longlong)param_2 + 0x14);
  *(undefined1 *)((longlong)param_2 + 0x103) = *(undefined1 *)((longlong)param_2 + 0x19);
  if (*(char *)(lVar1 + 2) == '\0') {
    if (*(char *)(lVar1 + 0xb) != '\0') {
      if (0 < *(int *)(param_1 + 0x204)) {
        *(ushort *)(param_2 + 0x22) = *(ushort *)(param_2 + 0x22) | 4;
      }
      param_2[0x23] =
           *(longlong *)(param_1 + 0x200) + (ulonglong)*(uint *)((longlong)param_2 + 0x14) * 0x12;
      bVar3 = 0x12;
      if (*(byte *)(lVar1 + 0xb) < 0x12) {
        bVar3 = *(byte *)(lVar1 + 0xb);
      }
      *(byte *)((longlong)param_2 + 0x101) = bVar3;
    }
    if (*(char *)((longlong)param_2 + 0xf) != '\0') {
      UpdateIOMetric(param_1,*(byte *)(lVar1 + 6),*(char *)((longlong)param_2 + 0xd),param_2[0x24],
                     *(int *)((longlong)param_2 + 0x114),0x200);
      if ((*(char *)((longlong)param_2 + 0x11) != '\0') && (1 < *(byte *)((longlong)param_2 + 0x83))
         ) {
        *(char *)((longlong)param_2 + 0x107) = (char)param_2[10];
        *(int *)((longlong)param_2 + 0x114) = (int)param_2[9];
        iVar2 = ((uint)*(byte *)((longlong)param_2 + 0x52) * (uint)*(ushort *)(param_2 + 10) +
                 *(int *)(&DAT_140016300 + (ulonglong)*(byte *)(param_2 + 0x20) * 4) + 0x3f >> 6 &
                0xff) - 1;
        iVar4 = 7;
        if (iVar2 < 7) {
          iVar4 = iVar2;
        }
        *(char *)((longlong)param_2 + 0x91) = (char)iVar4;
      }
    }
  }
  if (*(char *)(param_1 + 0xe46e) == '\0') {
    *(undefined8 *)(*(longlong *)(param_1 + 0x80) + 0xc0) =
         *(undefined8 *)((longlong)param_2 + 0xa4);
    LOCK();
    UNLOCK();
    return;
  }
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 200) = *(undefined4 *)((longlong)param_2 + 0xa4);
  LOCK();
  UNLOCK();
  return;
}



===== MFI_SetFrameCount @ 14000b450 =====

void MFI_SetFrameCount(undefined8 param_1,longlong param_2,byte param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = ((uint)*(byte *)(param_2 + 0x52) * (uint)*(ushort *)(param_2 + 0x50) +
           *(int *)(&DAT_140016300 + (ulonglong)param_3 * 4) + 0x3f >> 6 & 0xff) - 1;
  iVar2 = 7;
  if (iVar1 < 7) {
    iVar2 = iVar1;
  }
  *(char *)(param_2 + 0x91) = (char)iVar2;
  return;
}



===== GetRegistrySettings @ 14000b490 =====

void GetRegistrySettings(char *param_1,longlong param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  longlong lVar6;
  undefined1 uVar7;
  undefined4 uVar8;
  longlong lVar9;
  char cVar10;
  longlong lVar11;
  undefined **ppuVar12;
  byte *pbVar13;
  bool bVar14;
  
  *(uint *)(param_2 + 0xe45c) = *(uint *)(param_2 + 0xe45c) & 0xfffffe1f | 0x1e;
  if (param_1 == (char *)0x0) {
    *(undefined1 *)(param_2 + 0xd928) = 1;
    *(undefined1 *)(param_2 + 0x9c) = 1;
    return;
  }
  lVar11 = 0x1a;
  ppuVar12 = &regSettings;
  do {
    pcVar5 = strstr(param_1,*ppuVar12);
    if (pcVar5 != (char *)0x0) {
      lVar9 = -1;
      *(undefined1 *)(ppuVar12 + 1) = 1;
      do {
        lVar6 = lVar9 + 1;
        lVar9 = lVar9 + 1;
      } while ((*ppuVar12)[lVar6] != '\0');
      if (pcVar5[lVar9] == '=') {
        lVar9 = -1;
        do {
          lVar6 = lVar9;
          lVar9 = lVar6 + 1;
        } while ((*ppuVar12)[lVar9] != '\0');
        pcVar5 = pcVar5 + lVar6 + 2;
        iVar2 = 0;
        cVar10 = *pcVar5;
        if (cVar10 != '0') goto joined_r0x00014000b5a6;
        if (pcVar5[1] == 'x') {
          pbVar13 = (byte *)(pcVar5 + 2);
          while( true ) {
            for (; bVar1 = *pbVar13, (byte)(bVar1 - 0x30) < 10; pbVar13 = pbVar13 + 1) {
              iVar2 = iVar2 * 0x10 + -0x30 + (int)(char)bVar1;
            }
            if (((char)bVar1 < 'a') && (0x25 < (byte)(bVar1 + 0xbf))) break;
            iVar2 = iVar2 * 0x10 + (int)(char)bVar1;
            if ((bVar1 & 0x20) == 0) {
              iVar2 = iVar2 + -0x37;
              pbVar13 = pbVar13 + 1;
            }
            else {
              iVar2 = iVar2 + -0x57;
              pbVar13 = pbVar13 + 1;
            }
          }
        }
        else {
          do {
            if ('9' < cVar10) break;
            pcVar5 = pcVar5 + 1;
            iVar3 = (int)cVar10;
            cVar10 = *pcVar5;
            iVar2 = iVar3 + iVar2 * 10 + -0x30;
joined_r0x00014000b5a6:
          } while ('/' < cVar10);
        }
        *(int *)((longlong)ppuVar12 + 0xc) = iVar2;
      }
    }
    ppuVar12 = ppuVar12 + 2;
    lVar11 = lVar11 + -1;
    if (lVar11 == 0) {
      if (DAT_140016388 != '\0') {
        *(undefined1 *)(param_2 + 0xd928) = 0;
        *(undefined1 *)(param_2 + 0x89) = 1;
        return;
      }
      bVar14 = DAT_1400163a8 == '\0';
      if (!bVar14) {
        *(undefined4 *)(param_2 + 0xe8a8) = DAT_1400163ac;
      }
      *(bool *)(param_2 + 0xd928) = bVar14;
      if (DAT_1400163d8 != '\0') {
        *(undefined1 *)(param_2 + 0x90) = DAT_1400163dc;
      }
      uVar8 = 4;
      if (DAT_140016338 != '\0') {
        uVar8 = DAT_14001633c;
      }
      *(undefined4 *)(param_2 + 0x8c) = uVar8;
      if (DAT_1400163e8 != '\0') {
        *(undefined1 *)(param_2 + 0x91) = 1;
      }
      iVar2 = 10;
      if ((DAT_140016348 != '\0') && (iVar2 = 10, DAT_14001634c != 0)) {
        iVar2 = DAT_14001634c;
      }
      *(int *)(param_2 + 0x9228) = iVar2;
      if (DAT_1400163b8 != '\0') {
        *(undefined4 *)(param_2 + 0x94) = DAT_1400163bc;
      }
      if (DAT_1400163c8 != '\0') {
        *(undefined4 *)(param_2 + 0x98) = DAT_1400163cc;
      }
      if (DAT_1400163f8 != '\0') {
        *(undefined1 *)(param_2 + 0xd85a) = 0;
      }
      uVar8 = 0x10;
      if (DAT_140016358 != '\0') {
        uVar8 = DAT_14001635c;
      }
      *(undefined4 *)(param_2 + 0xd828) = uVar8;
      uVar8 = 4;
      if (DAT_140016368 != '\0') {
        uVar8 = DAT_14001636c;
      }
      *(undefined4 *)(param_2 + 0xd82c) = uVar8;
      if ((DAT_140016398 != '\0') &&
         (extendedTimeout = DAT_14001639c * 1000000, 179999999 < extendedTimeout - 1U)) {
        extendedTimeout = 180000000;
      }
      *(bool *)(param_2 + 0x9c) = DAT_140016408 != '\0';
      uVar4 = DAT_14001641c;
      if (DAT_140016418 != '\0') {
        *(uint *)(param_2 + 0xe1a4) = DAT_14001641c;
        if (DAT_14001641c == 0) {
          *(undefined4 *)(param_2 + 0xe1a4) = 1;
        }
        else {
          if (0xfe < DAT_14001641c) {
            uVar4 = 0xfe;
          }
          *(uint *)(param_2 + 0xe1a4) = uVar4;
        }
        *(undefined1 *)(param_2 + 0xe1a1) = 1;
        *(undefined1 *)(param_2 + 0x91) = 0;
      }
      uVar4 = DAT_14001642c;
      if (DAT_140016428 != '\0') {
        *(uint *)(param_2 + 0xe1ac) = DAT_14001642c;
        if (DAT_14001642c == 0) {
          *(undefined4 *)(param_2 + 0xe1ac) = 1;
        }
        else {
          if (0xfe < DAT_14001642c) {
            uVar4 = 0xfe;
          }
          *(uint *)(param_2 + 0xe1ac) = uVar4;
        }
        *(undefined1 *)(param_2 + 0xe1a8) = 1;
        *(undefined1 *)(param_2 + 0x91) = 0;
      }
      *(bool *)(param_2 + 0xe458) = DAT_140016438 != '\0';
      *(bool *)(param_2 + 0xa4) = DAT_140016448 != '\0';
      if (DAT_140016468 == '\0') {
        iVar2 = 1000000;
      }
      else {
        iVar2 = DAT_14001646c * 1000000;
      }
      *(int *)(param_2 + 0xd908) = iVar2;
      *(bool *)(param_2 + 0xe8ae) = DAT_140016478 != '\0';
      if (DAT_140016488 == '\0') {
        uVar7 = 4;
      }
      else {
        uVar4 = 4;
        if (DAT_14001648c < 5) {
          uVar4 = DAT_14001648c;
        }
        uVar7 = (undefined1)uVar4;
      }
      *(undefined1 *)(param_2 + 0xe8c8) = uVar7;
      uVar7 = 0;
      if (DAT_140016498 != '\0') {
        uVar7 = DAT_14001649c;
      }
      *(undefined1 *)(param_2 + 0xe8d8) = uVar7;
      if (DAT_1400164a8 != '\0') {
        if ((DAT_1400164ac & 3) != 0) {
          DAT_1400164ac = DAT_1400164ac + (4 - (DAT_1400164ac & 3));
        }
        RttSetTraceParameters(param_2 + 0xeb18,DAT_1400164ac,2);
      }
      if ((DAT_1400164b8 != '\0') && (DAT_1400164bc < 3)) {
        *(uint *)(param_2 + 0xe45c) =
             *(uint *)(param_2 + 0xe45c) ^ (DAT_1400164bc * 2 ^ *(uint *)(param_2 + 0xe45c)) & 0x1fe
        ;
      }
      *(bool *)(param_2 + 0xa6) = DAT_1400164c8 != '\0';
      return;
    }
  } while( true );
}



===== MegaSASBackGroundTimer @ 14000b8d0 =====

void MegaSASBackGroundTimer(longlong param_1)

{
  undefined8 uVar1;
  
  if (**(char **)(param_1 + 0xe478) != '\0') {
    *(undefined4 *)(param_1 + 0xe4a8) = 0x1020100;
    SyncronizeCmdTimeout(param_1,0,0);
  }
  if (**(char **)(param_1 + 0xe480) != '\0') {
    *(undefined4 *)(param_1 + 0xe4a8) = 0x2010100;
    SyncronizeCmdTimeout(param_1,0,0);
  }
  if (**(char **)(param_1 + 0xe488) != '\0') {
    *(undefined4 *)(param_1 + 0xe4a8) = 0x1200100;
    SyncronizeCmdTimeout(param_1,0,0);
  }
  if (**(char **)(param_1 + 0xe490) != '\0') {
    *(undefined4 *)(param_1 + 0xe4a8) = 0x10f0100;
    SyncronizeCmdTimeout(param_1,0,0);
  }
  if (**(char **)(param_1 + 0xe498) != '\0') {
    *(undefined4 *)(param_1 + 0xe4a8) = 0x10f0200;
    SyncronizeCmdTimeout(param_1,0,0);
  }
  if (**(char **)(param_1 + 0xe4a0) != '\0') {
    *(undefined4 *)(param_1 + 0xe4a8) = 0x10f0300;
    SyncronizeCmdTimeout(param_1,0,0);
  }
  if (*(char *)(param_1 + 0xd90c) == '\0') {
    uVar1 = CheckFirmwareFault(param_1,8,0);
    if ((char)uVar1 != '\0') {
      return;
    }
  }
  StartBGTimer(param_1);
  return;
}



===== BuildSGLforIOCTL @ 14000b9e0 =====

longlong BuildSGLforIOCTL(longlong param_1,undefined8 *param_2,longlong param_3,uint param_4)

{
  char cVar1;
  undefined8 uVar2;
  ushort uVar3;
  undefined8 uVar4;
  uint local_res8 [2];
  
  uVar3 = *(ushort *)(param_2 + 10);
  uVar2 = *param_2;
  local_res8[0] = 0;
  if ((uint)uVar3 <= *(uint *)(param_1 + 0xd7f8)) {
    do {
      uVar4 = StorPortGetPhysicalAddress(param_1,uVar2,param_3,local_res8);
      if (param_4 < local_res8[0]) {
        local_res8[0] = param_4;
      }
      cVar1 = *(char *)((longlong)param_2 + 0x34);
      *(int *)param_2[0xc] = (int)uVar4;
      if (cVar1 == '\0') {
        *(uint *)(param_2[0xc] + 4) = local_res8[0];
        param_2[0xc] = param_2[0xc] + 8;
      }
      else {
        *(int *)(param_2[0xc] + 4) = (int)((ulonglong)uVar4 >> 0x20);
        *(uint *)(param_2[0xc] + 8) = local_res8[0];
        param_2[0xc] = param_2[0xc] + 0xc;
      }
      param_3 = param_3 + (ulonglong)local_res8[0];
      uVar3 = *(short *)(param_2 + 10) + 1;
      *(ushort *)(param_2 + 10) = uVar3;
      param_4 = param_4 - local_res8[0];
      if (param_4 == 0) {
        return CONCAT71((uint7)(byte)(uVar3 >> 8),1);
      }
    } while ((uint)uVar3 <= *(uint *)(param_1 + 0xd7f8));
  }
  return (ulonglong)(uVar3 >> 8) << 8;
}



===== BuildSGLforSRB @ 14000bac0 =====

undefined8 BuildSGLforSRB(longlong param_1,longlong *param_2)

{
  uint uVar1;
  uint *puVar2;
  undefined8 uVar3;
  
  puVar2 = (uint *)StorPortGetScatterGatherList(param_1,*param_2);
  if (puVar2 == (uint *)0x0) {
    return 0;
  }
  if (((*(byte *)((longlong)param_2 + 0xa2) < 5) || (*(char *)((longlong)param_2 + 0x35) == '\0'))
     || (((uVar1 = *(uint *)(*param_2 + 0x10), uVar1 < 0x5001 || (*(uint *)(param_2 + 0xf) < uVar1))
         && ((0xfff < uVar1 - 0x4001 || (uVar1 - 0x4000 <= puVar2[6])))))) {
    uVar3 = MPT_BuildIEEESGL(param_1,(longlong)param_2,puVar2);
    return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
  }
  uVar3 = MPT_BuildPrpSGL(param_1,param_2,puVar2);
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== BuildSysPD @ 14000bb60 =====

void BuildSysPD(longlong param_1,longlong *param_2,short *param_3)

{
  int iVar1;
  longlong lVar2;
  ushort uVar3;
  byte bVar4;
  short sVar5;
  undefined8 local_res8;
  
  lVar2 = *param_2;
  bVar4 = 0;
  if ((*(byte *)((ulonglong)*(byte *)(lVar2 + 6) + 0xe1b0 + param_1) & 0x10) != 0) {
    *(undefined1 *)((longlong)param_2 + 0xa2) = 5;
  }
  *(undefined1 *)((longlong)param_2 + 0xa4) = 0xc;
  *(undefined1 *)((longlong)param_3 + 3) = 0;
  uVar3 = param_3[0x30] & 0xfff1U | 1;
  if (*(char *)((longlong)param_2 + 0xc) != '\0') {
    uVar3 = param_3[0x30] & 0xfff2U | 2;
  }
  param_3[0x30] = uVar3;
  iVar1 = *(int *)(param_1 + 0xd954);
  *(undefined1 *)((longlong)param_2 + 0x35) = 1;
  *(int *)((longlong)param_2 + 0xbc) = iVar1 + -1;
  if (*(uint *)(lVar2 + 0x14) < 2) {
    *(undefined4 *)(lVar2 + 0x14) = 2;
  }
  if ((*(char *)(param_1 + 0x89) == '\0') && (*(char *)(param_1 + 0xe46c) != '\0')) {
    local_res8 = *(undefined8 *)
                  (*(longlong *)
                    (param_1 + 0xd958 + (ulonglong)(*(uint *)((longlong)param_2 + 0xbc) & 1) * 8) +
                   8 + (ulonglong)*(byte *)(lVar2 + 6) * 8);
    bVar4 = (byte)((ulonglong)local_res8 >> 0x20) & 1;
  }
  if (((*(char *)(param_1 + 0xe46c) == '\0') ||
      (*(char *)((ulonglong)*(byte *)(lVar2 + 6) + 0xd50a + param_1) == '\0')) ||
     (*(char *)(param_1 + 0x89) != '\0')) {
    *param_3 = -1;
    param_3[0x31] = *(short *)(lVar2 + 0x14);
    sVar5 = *(byte *)(lVar2 + 6) + 0xff;
  }
  else {
    param_3[0x3d] = (short)local_res8;
    *param_3 = (short)((ulonglong)local_res8 >> 0x10);
    param_3[0x31] = *(short *)(lVar2 + 0x14);
    if (*(char *)(param_1 + 0xe8ad) == '\0') {
      sVar5 = *(byte *)(lVar2 + 6) + 0xff;
    }
    else {
      sVar5 = (short)((ulonglong)local_res8 >> 0x30);
    }
    param_3[0x30] = param_3[0x30] & 0xff1fU | 0x10;
  }
  param_3[0x33] = sVar5;
  *(undefined1 *)((longlong)param_3 + 0x35) = *(undefined1 *)(lVar2 + 7);
  *(undefined1 *)(param_3 + 0x1a) = 0;
  *(short *)((longlong)param_2 + 0xaa) = *param_3;
  param_3[0x34] = 0;
  param_3[0x35] = 0;
  param_3[0x36] = 0;
  param_3[0x37] = 0;
  param_3[0x38] = 0;
  param_3[0x39] = 0;
  *(undefined1 *)(param_3 + 0x3c) = 0x10;
  if ((((*(char *)(param_1 + 0xe45a) != '\0') || (bVar4 != 0)) ||
      ((*param_3 == 0 || (*(char *)((ulonglong)*(byte *)(lVar2 + 6) + 0xd50a + param_1) == '\0'))))
     && (*(char *)((longlong)param_2 + 0xc) == '\0')) {
    *(undefined1 *)((longlong)param_2 + 0xa4) = 0;
    *(undefined1 *)((longlong)param_2 + 0x35) = 0;
    *(undefined1 *)((longlong)param_3 + 3) = 0xf1;
    return;
  }
  if (0xff < (ushort)param_3[0x31]) {
    param_3[0x31] = 0xff;
  }
  return;
}



===== BuildWithRaidMapLite @ 14000bd40 =====

void BuildWithRaidMapLite(longlong param_1,longlong *param_2,ushort *param_3)

{
  longlong lVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  undefined1 uVar7;
  ushort uVar8;
  char cVar9;
  uint *puVar10;
  
  lVar5 = *param_2;
  *(undefined1 *)((longlong)param_2 + 0x9c) = 1;
  if (*(char *)(param_1 + 0xd928) != '\0') {
    lVar6 = *(longlong *)(param_1 + 0xd930 + (ulonglong)(*(uint *)(param_2 + 0x17) & 1) * 8);
    uVar8 = *(ushort *)(*(longlong *)(lVar6 + 0x40) + (ulonglong)*(byte *)(param_2 + 1) * 2);
    if (uVar8 < *(ushort *)(param_1 + 0xe462)) {
      puVar10 = (uint *)((ulonglong)uVar8 * 0x9e0 + *(longlong *)(lVar6 + 0x50));
      uVar8 = *(ushort *)((ulonglong)(ushort)puVar10[0x2e] * 0x40 + *(longlong *)(lVar6 + 0x48));
      uVar3 = puVar10[0xc];
      *(uint *)(param_2 + 0x18) = uVar3;
      if (uVar3 != 0) {
        if (((*puVar10 >> 0x1b & 1) == 0) || (*(char *)((longlong)puVar10 + 0x1a) != '\x03')) {
          uVar7 = 0;
        }
        else {
          uVar7 = 1;
        }
        *(undefined1 *)(param_2 + 2) = uVar7;
        uVar3 = *puVar10;
        if (*(char *)((longlong)param_2 + 0xe) == '\0') {
          if (((uVar3 >> 0x15 & 1) == 0) ||
             (((uVar3 >> 0x17 & 1) == 0 &&
              ((ulonglong)param_2[7] >> (*(byte *)((longlong)puVar10 + 0x12) & 0x3f) !=
               (param_2[7] - 1U) + (ulonglong)*(uint *)(param_2 + 9) >>
               (*(byte *)((longlong)puVar10 + 0x12) & 0x3f))))) goto LAB_14000be36;
        }
        else if (((uVar3 >> 0x14 & 1) == 0) ||
                ((((uVar3 >> 0x16 & 1) == 0 &&
                  ((ulonglong)param_2[7] >> (*(byte *)((longlong)puVar10 + 0x12) & 0x3f) !=
                   (param_2[7] - 1U) + (ulonglong)*(uint *)(param_2 + 9) >>
                   (*(byte *)((longlong)puVar10 + 0x12) & 0x3f))) ||
                 ((*(char *)((longlong)puVar10 + 0x15) == '\x01' && ((uVar3 >> 0x1d & 1) == 0))))))
        goto LAB_14000be36;
        if (((byte)uVar3 & 0xf0) == 0x80) {
          *(undefined1 *)((longlong)param_2 + 0x9b) = 1;
        }
        param_3[0x30] = param_3[0x30] & 0xff12 | 0x12;
        *(longlong *)(param_3 + 0x34) = param_2[7];
        *(int *)(param_3 + 0x38) = (int)param_2[9];
        param_3[0x31] = (ushort)*(byte *)(lVar6 + 0x24);
        param_3[0x33] = (ushort)*(byte *)(param_2 + 1);
        param_3[0x3d] = *(ushort *)((longlong)puVar10 + 0x1e);
        lVar1 = (ulonglong)uVar8 * 8;
        *param_3 = *(ushort *)(lVar1 + *(longlong *)(lVar6 + 0x38));
        cVar9 = *(char *)(lVar1 + 3 + *(longlong *)(lVar6 + 0x38));
        *(char *)((longlong)param_2 + 0xa2) = cVar9;
        *(ushort *)((longlong)param_2 + 0xaa) = *param_3;
        param_2[8] = param_2[7];
        *(undefined1 *)((longlong)param_2 + 0xa4) = 0xc;
        *(undefined1 *)((longlong)param_2 + 0x35) = 1;
        if (cVar9 == '\x05') {
          if ((*(longlong *)(param_1 + 0xd988) != 0) &&
             (iVar4 = *(int *)(((ulonglong)*(byte *)(param_2 + 1) + 0x100) * 0x20 +
                              *(longlong *)(param_1 + 0xd988)), iVar4 != 0)) {
            *(int *)(param_2 + 0xf) = iVar4 << 10;
          }
          if ((*(uint *)(param_2 + 0xf) < *(uint *)(lVar5 + 0x10)) && ((puVar10[8] & 4) == 0))
          goto LAB_14000be36;
        }
        if (*(uint *)(lVar5 + 0x14) < 2) {
          *(undefined4 *)(lVar5 + 0x14) = 2;
        }
        if ((char)*(undefined4 *)(lVar5 + 0xc) < '\0') {
          *(undefined1 *)((longlong)param_2 + 0xe) = 1;
          cVar9 = '\x01';
        }
        else {
          cVar9 = *(char *)((longlong)param_2 + 0xe);
        }
        uVar8 = 0;
        bVar2 = *(byte *)((ulonglong)(cVar9 != '\0') + 0x38 + (longlong)puVar10);
        if ((bVar2 & 6) == 6) {
          uVar8 = 0xf00;
        }
        else if ((bVar2 & 4) != 0) {
          uVar8 = 0x100;
        }
        uVar8 = param_3[0x32] & 0xf0ff | uVar8;
        param_3[0x32] = uVar8;
        if (*(char *)((longlong)param_2 + 0xe) == '\0') {
          return;
        }
        if (*(char *)((longlong)puVar10 + 0x15) == '\x01') {
          param_3[0x32] = uVar8 | 2;
          return;
        }
        return;
      }
    }
  }
LAB_14000be36:
  *(undefined1 *)((longlong)param_2 + 0x9c) = 0;
  MPT_BuildLdIO(param_1,param_2,param_3);
  return;
}



===== BuildWithRaidMapRwLD @ 14000c000 =====

void BuildWithRaidMapRwLD(longlong param_1,longlong *param_2,ushort *param_3)

{
  ulonglong uVar1;
  byte local_res8 [8];
  ushort local_res10 [4];
  void *local_res20;
  
  local_res8[0] = 0;
  if ((*(char *)(param_1 + 0xd928) == '\0') ||
     (uVar1 = MegaSASBuildRaidContext
                        (param_1,param_2,param_2 + 8,(longlong)(param_3 + 0x30),(short *)local_res10
                         ,local_res8,(longlong *)&local_res20), (char)uVar1 == '\0')) {
    MPT_BuildLdIO(param_1,param_2,param_3);
    return;
  }
  if (local_res8[0] != 0) {
    *(ushort *)((longlong)param_2 + 0xaa) = local_res10[0];
    *(undefined1 *)((longlong)param_2 + 0xa4) = 0xc;
    *(undefined1 *)((longlong)param_3 + 3) = 0;
    *param_3 = local_res10[0];
    memmove(param_3 + 0x1a,local_res20,8);
    *(undefined1 *)((longlong)param_2 + 0x35) = 1;
    param_3[0x30] = param_3[0x30] & 0xff12 | 0x12;
    return;
  }
  MPT_BuildLdIO(param_1,param_2,param_3);
  if (*(char *)((longlong)param_2 + 0x9a) == '\0') {
    return;
  }
  *(undefined1 *)(param_3 + 0x3c) = 0x70;
  return;
}



===== CDB_SetBlockCnt @ 14000c100 =====

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



===== CDB_SetStartLBA @ 14000c170 =====

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
    if ((param_2 - 10U & 0xfd) == 0) {
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



===== MPT_BuildCmd_Scsi @ 14000c210 =====

ulonglong MPT_BuildCmd_Scsi(longlong param_1,longlong *param_2)

{
  ushort *puVar1;
  int *piVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  longlong lVar6;
  longlong lVar7;
  byte bVar8;
  void *pvVar9;
  uint *puVar10;
  ulonglong uVar11;
  int *piVar12;
  longlong lVar13;
  uint uVar14;
  int iVar15;
  undefined1 local_res10;
  undefined1 local_res11;
  undefined1 local_res12;
  int local_res14;
  
  lVar6 = *param_2;
  puVar1 = (ushort *)(param_2 + 0x20);
  iVar15 = 0;
  bVar3 = *(byte *)(lVar6 + 10);
  iVar5 = *(int *)(lVar6 + 0x10);
  *(undefined4 *)((longlong)param_2 + 0xa4) = 0;
  *(ushort *)((longlong)param_2 + 0x124) = (ushort)bVar3;
  *(undefined1 *)((longlong)param_2 + 0x114) = 0x20;
  *(int *)((longlong)param_2 + 0x11c) = iVar5;
  *(undefined2 *)((longlong)param_2 + 0x164) = 0x10;
  memmove(param_2 + 0x28,(void *)(lVar6 + 0x48),(ulonglong)bVar3);
  if (bVar3 == 6) {
    param_2[7] = (ulonglong)
                 ((uint6)CONCAT21(CONCAT11(*(undefined1 *)(lVar6 + 0x49),
                                           *(undefined1 *)(lVar6 + 0x4a)),
                                  *(undefined1 *)(lVar6 + 0x4b)) & 0x1fffff);
    *(uint *)(param_2 + 9) = (uint)*(byte *)(lVar6 + 0x4c);
  }
  else if (bVar3 == 10) {
    param_2[7] = (ulonglong)
                 CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(lVar6 + 0x4a),
                                            *(undefined1 *)(lVar6 + 0x4b)),
                                   *(undefined1 *)(lVar6 + 0x4c)),*(undefined1 *)(lVar6 + 0x4d));
    *(uint *)(param_2 + 9) =
         (uint)CONCAT11(*(undefined1 *)(lVar6 + 0x4f),*(undefined1 *)(lVar6 + 0x50));
  }
  else if (bVar3 == 0xc) {
    param_2[7] = (ulonglong)
                 CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(lVar6 + 0x4a),
                                            *(undefined1 *)(lVar6 + 0x4b)),
                                   *(undefined1 *)(lVar6 + 0x4c)),*(undefined1 *)(lVar6 + 0x4d));
    *(uint *)(param_2 + 9) =
         CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(lVar6 + 0x4e),*(undefined1 *)(lVar6 + 0x4f)),
                           *(undefined1 *)(lVar6 + 0x50)),*(undefined1 *)(lVar6 + 0x51));
  }
  else if (bVar3 == 0x10) {
    param_2[7] = (((((longlong)
                     (int)((uint)CONCAT21(CONCAT11(*(undefined1 *)(lVar6 + 0x4a),
                                                   *(undefined1 *)(lVar6 + 0x4b)),
                                          *(undefined1 *)(lVar6 + 0x4c)) << 8) |
                    (ulonglong)*(byte *)(lVar6 + 0x4d)) << 8 | (ulonglong)*(byte *)(lVar6 + 0x4e))
                   << 8 | (ulonglong)*(byte *)(lVar6 + 0x4f)) << 8 |
                 (ulonglong)*(byte *)(lVar6 + 0x50)) << 8 | (ulonglong)*(byte *)(lVar6 + 0x51);
    *(uint *)(param_2 + 9) =
         CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(lVar6 + 0x52),*(undefined1 *)(lVar6 + 0x53)),
                           *(undefined1 *)(lVar6 + 0x54)),*(undefined1 *)(lVar6 + 0x55));
  }
  if (*(char *)((longlong)param_2 + 9) == '\x01') {
    if (*(char *)((longlong)param_2 + 0xc) == '\0') {
      bVar3 = *(byte *)(*param_2 + 6);
      if (*(char *)(param_1 + 0xd928) != '\0') {
        lVar7 = *(longlong *)
                 (param_1 + 0xd930 + (ulonglong)(*(int *)(param_1 + 0xd92c) - 1U & 1) * 8);
        uVar4 = *(ushort *)(*(longlong *)(lVar7 + 0x40) + (ulonglong)bVar3 * 2);
        if ((*(short *)(lVar7 + 0x2c) != 0) && (uVar4 < *(ushort *)(param_1 + 0xe462))) {
          lVar13 = (ulonglong)uVar4 * 0x9e0;
          puVar10 = (uint *)(*(longlong *)(lVar7 + 0x50) + lVar13);
          if ((*puVar10 & 0x1000000) != 0) {
            bVar8 = (byte)puVar10[0xb];
            if (bVar8 < 0x14) {
              *(undefined1 *)(puVar10 + 0xb) = 0x14;
              bVar8 = 0x14;
            }
            param_2[0x2d] = 0;
            *(undefined4 *)(param_2 + 0x2e) = 0;
            *(ushort *)((longlong)param_2 + 0x162) = (ushort)bVar8;
            *(ushort *)((longlong)param_2 + 0x166) = (ushort)bVar3;
            uVar4 = *(ushort *)
                     (*(longlong *)(lVar7 + 0x38) +
                     (ulonglong)
                     *(ushort *)
                      ((ulonglong)*(ushort *)(*(longlong *)(lVar7 + 0x50) + 0xb8 + lVar13) * 0x40 +
                      *(longlong *)(lVar7 + 0x48)) * 8);
            *(ushort *)((longlong)param_2 + 0xaa) = uVar4;
            *(undefined1 *)((longlong)param_2 + 0xa4) = 0xc;
            *(ushort *)(param_2 + 0x2c) = *(ushort *)(param_2 + 0x2c) & 0xfff2 | 2;
            *(undefined1 *)((longlong)param_2 + 0x35) = 1;
            pvVar9 = memmove((void *)((longlong)param_2 + 0x134),puVar10 + 9,8);
            *(undefined1 *)((longlong)param_2 + 0x103) = 0;
            *puVar1 = uVar4;
            goto LAB_14000c58f;
          }
        }
      }
      *(undefined1 *)((longlong)param_2 + 0xa4) = 0;
      *(ushort *)(param_2 + 0x2c) = *(ushort *)(param_2 + 0x2c) & 0xfff2 | 2;
      *(undefined1 *)((longlong)param_2 + 0x103) = 0xf1;
      *puVar1 = (ushort)bVar3;
      if (*(ushort *)((longlong)param_2 + 0x162) < 0x14) {
        pvVar9 = (void *)0x0;
        *(ushort *)((longlong)param_2 + 0x166) = (ushort)bVar3;
        *(undefined2 *)((longlong)param_2 + 0x162) = 0x14;
      }
      else {
        uVar4 = *(ushort *)(*param_2 + 0x14);
        pvVar9 = (void *)(ulonglong)uVar4;
        *(ushort *)((longlong)param_2 + 0x162) = uVar4;
        *(ushort *)((longlong)param_2 + 0x166) = (ushort)bVar3;
      }
    }
    else if ((*(byte *)(param_1 + 0xd710 + ((longlong)(ulonglong)*(byte *)(param_2 + 1) >> 3)) >>
              ((ulonglong)*(byte *)(param_2 + 1) & 7) & 1) == 0) {
      pvVar9 = (void *)BuildWithRaidMapRwLD(param_1,param_2,puVar1);
    }
    else {
      pvVar9 = (void *)BuildWithRaidMapLite(param_1,param_2,puVar1);
    }
LAB_14000c58f:
    if ((*(char *)((longlong)param_2 + 0x35) == '\0') ||
       (*(char *)((longlong)param_2 + 0xc) == '\0')) {
      *(undefined1 *)((longlong)param_2 + 0x36) = 0;
    }
    if (iVar5 != 0) {
      *(undefined2 *)(param_2 + 0x22) = 2;
      uVar14 = 0x1000000;
      if ((*(uint *)(lVar6 + 0xc) & 0x80) == 0) {
        uVar14 = 0x2000000;
      }
      *(uint *)((longlong)param_2 + 0x13c) = *(uint *)((longlong)param_2 + 0x13c) | uVar14;
      param_2[0xc] = (longlong)(param_2 + 0x30);
      param_2[0xb] = (longlong)(param_2 + 0x30);
      puVar10 = (uint *)StorPortGetScatterGatherList(param_1,*param_2);
      if (puVar10 == (uint *)0x0) {
        lVar6 = *param_2;
        lVar7 = param_2[3];
        if (*(char *)(param_1 + 0x91) == '\0') {
          StorPortBusy(param_1,*(undefined4 *)(param_1 + 0x9228));
        }
        else {
          *(undefined1 *)(lVar6 + 4) = 0x28;
        }
        *(undefined1 *)(lVar6 + 3) = 5;
        piVar12 = (int *)(param_1 + 0x92e0);
        lVar13 = 0xff;
        do {
          piVar2 = piVar12 + 0x800;
          iVar5 = *piVar12;
          piVar12 = piVar12 + 8;
          iVar15 = iVar15 + *piVar2 + iVar5;
          lVar13 = lVar13 + -1;
        } while (lVar13 != 0);
        local_res11 = *(undefined1 *)(lVar6 + 5);
        local_res10 = *(undefined1 *)(lVar6 + 6);
        local_res12 = *(undefined1 *)(lVar6 + 0x48);
        local_res14 = iVar15;
        if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x2a9) != 0)) {
          RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x2a9,&local_res10,8,
                      (char)lVar7,3);
        }
        pvVar9 = (void *)StorPortNotification(0,param_1,lVar6);
        goto LAB_14000c742;
      }
      if (((*(byte *)((longlong)param_2 + 0xa2) < 5) ||
          (*(char *)((longlong)param_2 + 0x35) == '\0')) ||
         (((uVar14 = *(uint *)(*param_2 + 0x10), uVar14 < 0x5001 ||
           (*(uint *)(param_2 + 0xf) < uVar14)) &&
          ((0xfff < uVar14 - 0x4001 || (uVar14 - 0x4000 <= puVar10[6])))))) {
        MPT_BuildIEEESGL(param_1,(longlong)param_2,puVar10);
      }
      else {
        MPT_BuildPrpSGL(param_1,param_2,puVar10);
      }
      pvVar9 = (void *)(ulonglong)*(ushort *)((longlong)param_2 + 0x17c);
      *(ushort *)((longlong)param_2 + 0x17c) =
           *(ushort *)((longlong)param_2 + 0x17c) ^
           (*(ushort *)(param_2 + 10) ^ *(ushort *)((longlong)param_2 + 0x17c)) & 0xfff;
    }
    uVar11 = CONCAT71((int7)((ulonglong)pvVar9 >> 8),1);
  }
  else {
    if (*(char *)((ulonglong)*(byte *)(param_2 + 1) + 0xd30a + param_1) != '\0') {
      pvVar9 = (void *)BuildSysPD(param_1,param_2,(short *)puVar1);
      goto LAB_14000c58f;
    }
    *(undefined1 *)((longlong)param_2 + 0xa4) = 0;
    pvVar9 = (void *)MFI_BuildFrame_NonRW(param_1,param_2);
    if ((char)pvVar9 != '\0') goto LAB_14000c58f;
LAB_14000c742:
    uVar11 = (ulonglong)pvVar9 & 0xffffffffffffff00;
  }
  return uVar11;
}



===== MPT_BuildIEEESGL @ 14000c750 =====

void MPT_BuildIEEESGL(longlong param_1,longlong param_2,uint *param_3)

{
  ushort uVar1;
  ulonglong uVar2;
  uint uVar3;
  
  *(undefined1 *)(param_2 + 0xa1) = 0;
  uVar3 = 0;
  if (*param_3 == 0) {
    uVar1 = *(ushort *)(param_2 + 0x50);
  }
  else {
    do {
      if (uVar3 == 7) {
        *(longlong *)(param_2 + 0x60) = *(longlong *)(param_2 + 0x60) + 0x10;
        memset(*(void **)(param_2 + 0x60),0,(ulonglong)*(uint *)(param_1 + 0xe4ac));
      }
      uVar2 = (ulonglong)uVar3;
      uVar3 = uVar3 + 1;
      **(undefined8 **)(param_2 + 0x60) = *(undefined8 *)(param_3 + uVar2 * 6 + 4);
      *(uint *)(*(longlong *)(param_2 + 0x60) + 8) = param_3[uVar2 * 6 + 6];
      *(undefined1 *)(*(longlong *)(param_2 + 0x60) + 0xf) = 0;
      *(undefined1 *)(*(longlong *)(param_2 + 0x60) + 0xe) = 0;
      *(undefined2 *)(*(longlong *)(param_2 + 0x60) + 0xc) = 0;
      *(longlong *)(param_2 + 0x60) = *(longlong *)(param_2 + 0x60) + 0x10;
      uVar1 = *(short *)(param_2 + 0x50) + 1;
      *(ushort *)(param_2 + 0x50) = uVar1;
    } while (uVar3 < *param_3);
  }
  if (uVar1 < 8) {
    *(undefined1 *)((*(longlong *)(param_2 + 0x60) - (ulonglong)*(byte *)(param_2 + 0x52)) + 0xf) =
         0x40;
  }
  *(ulonglong *)(param_2 + 0x68) =
       (ulonglong)*(byte *)(param_2 + 0x52) * 7 + *(longlong *)(param_2 + 0x58);
  return;
}



===== MPT_BuildLdIO @ 14000c840 =====

void MPT_BuildLdIO(undefined8 param_1,longlong *param_2,ushort *param_3)

{
  longlong lVar1;
  ushort uVar2;
  
  lVar1 = *param_2;
  CDB_SetStartLBA((longlong)(param_3 + 0x20),*(char *)(lVar1 + 10),param_2[7]);
  *(undefined1 *)((longlong)param_2 + 0xa4) = 0xe;
  *(undefined1 *)((longlong)param_2 + 0x35) = 0;
  *(undefined1 *)((longlong)param_3 + 3) = 0xf1;
  *param_3 = (ushort)*(byte *)(lVar1 + 6);
  if (param_3[0x31] < 0x14) {
    uVar2 = 0x14;
  }
  else {
    uVar2 = *(ushort *)(lVar1 + 0x14);
  }
  param_3[0x31] = uVar2;
  param_3[0x33] = (ushort)*(byte *)(lVar1 + 6);
  param_3[0x30] = param_3[0x30] & 0xff12 | 0x12;
  return;
}



===== MPT_BuildPassthrough @ 14000c8d0 =====

void MPT_BuildPassthrough(undefined8 param_1,void *param_2,undefined8 param_3)

{
  memset(param_2,0,0x100);
  *(undefined2 *)((longlong)param_2 + 2) = 0xf008;
  *(undefined1 *)((longlong)param_2 + 0x14) = 0x20;
  *(undefined8 *)((longlong)param_2 + 0x80) = param_3;
  *(undefined4 *)((longlong)param_2 + 0x8c) = 0x80000000;
  *(undefined4 *)((longlong)param_2 + 0x88) = 0x400;
  *(undefined1 *)((longlong)param_2 + 0xff) = 0;
  return;
}



===== MPT_BuildPrpSGL @ 14000c930 =====

void MPT_BuildPrpSGL(longlong param_1,undefined8 *param_2,uint *param_3)

{
  uint *puVar1;
  longlong *plVar2;
  bool bVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  uint uVar7;
  longlong lVar8;
  uint *_Dst;
  int iVar9;
  ulonglong uVar10;
  undefined1 local_res8 [12];
  uint uStackX_14;
  
  lVar5 = param_2[0xc];
  *(undefined1 *)((longlong)param_2 + 0xa1) = 2;
  lVar4 = StorPortGetPhysicalAddress(param_1,*param_2,param_2,local_res8);
  plVar2 = (longlong *)param_2[0xc];
  _Dst = (uint *)(lVar5 + 0x80);
  lVar8 = lVar4 + 0x200;
  param_2[0xc] = plVar2 + 2;
  memset(_Dst,0,(ulonglong)*(uint *)(param_1 + 0xe4ac));
  puVar1 = (uint *)(lVar5 + 0x88);
  if (((ulonglong)puVar1 & 0xfff) == 0) {
    lVar8 = lVar4 + 0x208;
    _Dst = puVar1;
  }
  iVar9 = 0;
  bVar3 = true;
  uVar10 = 0;
  *(longlong *)param_2[0xc] = lVar8;
  *(undefined1 *)(param_2[0xc] + 0xe) = 0;
  *(undefined1 *)(param_2[0xc] + 0xf) = 0x80;
  *(byte *)(param_2[0xc] + 0xf) = *(byte *)(param_2[0xc] + 0xf) | 8;
  if (*param_3 != 0) {
    do {
      lVar5 = *(longlong *)(param_3 + uVar10 * 6 + 4);
      for (uVar6 = param_3[uVar10 * 6 + 6]; uVar6 != 0; uVar6 = uVar6 - uVar7) {
        uVar7 = 0x1000 - ((uint)lVar5 & 0xfff);
        if (bVar3) {
          *plVar2 = lVar5;
          bVar3 = false;
          *(uint *)(plVar2 + 1) = uVar7;
          *(undefined1 *)((longlong)plVar2 + 0xf) = 0;
        }
        else {
          if (((ulonglong)(_Dst + 2) & 0xfff) == 0) {
            lVar8 = lVar8 + 8;
            *(longlong *)_Dst = lVar8;
            iVar9 = iVar9 + 1;
            _Dst = _Dst + 2;
          }
          uStackX_14 = (uint)((ulonglong)lVar5 >> 0x20);
          lVar8 = lVar8 + 8;
          _Dst[1] = uStackX_14;
          iVar9 = iVar9 + 1;
          *_Dst = (uint)lVar5;
          _Dst = _Dst + 2;
          *(short *)(param_2 + 10) = *(short *)(param_2 + 10) + 1;
        }
        lVar5 = lVar5 + (ulonglong)uVar7;
        if (uVar6 < uVar7) break;
      }
      uVar6 = (int)uVar10 + 1;
      uVar10 = (ulonglong)uVar6;
    } while (uVar6 < *param_3);
  }
  *(int *)(param_2[0xc] + 8) = iVar9 * 8;
  return;
}



===== MPT_BuildTaskMgmt_Scsi @ 14000cab0 =====

undefined8 MPT_BuildTaskMgmt_Scsi(longlong param_1,longlong *param_2)

{
  ushort *_Dst;
  longlong lVar1;
  undefined1 uVar2;
  uint uVar3;
  
  lVar1 = *param_2;
  _Dst = (ushort *)(param_2 + 0x20);
  memset(_Dst,0,0x100);
  *(undefined8 *)((longlong)param_2 + 0xa4) = 0;
  *(undefined1 *)((longlong)param_2 + 0xa4) = 6;
  *(undefined1 *)((longlong)param_2 + 0x103) = 1;
  uVar2 = 5;
  if (*(char *)(lVar1 + 2) != ' ') {
    uVar2 = 3;
  }
  *(undefined1 *)((longlong)param_2 + 0x105) = uVar2;
  *(undefined2 *)(param_2 + 0x26) = 0;
  uVar3 = *(int *)(param_1 + 0xd954) - 1;
  *(uint *)((longlong)param_2 + 0xbc) = uVar3;
  if (*(char *)(lVar1 + 5) == '\x01') {
    *_Dst = (ushort)*(byte *)(lVar1 + 6);
    *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) | 1;
  }
  else if ((((*(char *)(param_1 + 0xe46c) == '\0') && (*(char *)(param_1 + 0xe45a) == '\0')) ||
           (*(char *)((ulonglong)*(byte *)(lVar1 + 6) + 0xd50a + param_1) == '\0')) ||
          (*(char *)(param_1 + 0x89) != '\0')) {
    if (*(char *)(param_1 + 0xd928) == '\0') {
      *_Dst = 0xffff;
    }
    else {
      *_Dst = *(ushort *)
               (*(longlong *)
                 (*(longlong *)(param_1 + 0xd930 + (ulonglong)(*(uint *)(param_2 + 0x17) & 1) * 8) +
                 0x38) + (ulonglong)*(byte *)(lVar1 + 6) * 8);
      *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) | 2;
    }
  }
  else {
    *_Dst = *(ushort *)
             (*(longlong *)(param_1 + 0xd958 + (ulonglong)(uVar3 & 1) * 8) + 10 +
             (ulonglong)*(byte *)(lVar1 + 6) * 8);
    *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) | 2;
  }
  *(undefined1 *)((longlong)param_2 + 0x10d) = *(undefined1 *)(lVar1 + 7);
  *(undefined1 *)((longlong)param_2 + 0x10c) = 0;
  *(ushort *)((longlong)param_2 + 0xaa) = *_Dst;
  return CONCAT71((uint7)(byte)(*_Dst >> 8),1);
}



===== MPT_CheckForFp_Possible @ 14000cbf0 =====

void MPT_CheckForFp_Possible(longlong param_1,longlong *param_2,ushort *param_3,undefined4 param_4)

{
  longlong *plVar1;
  int *piVar2;
  char cVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  ulonglong uVar10;
  bool bVar11;
  
  lVar4 = *param_2;
  lVar6 = param_2[3];
  if ((((*(short *)((longlong)param_2 + 0x17c) < 0) && ((char)param_2[0x10] != '\0')) &&
      (*(char *)((longlong)param_2 + 0xd) != '\0')) &&
     (*(char *)((longlong)param_2 + 0xa1) != '\x02')) {
    MPT_BuildLdIO(param_1,param_2,param_3);
  }
  else if ((((((*(uint *)(param_1 + 0xe45c) & 0x400) != 0) && (*(longlong *)(param_1 + 0xe8d0) != 0)
             ) && ((*(char *)((longlong)param_2 + 0x9d) == '\x01' &&
                   ((*(char *)((longlong)param_2 + 0xe) != '\0' &&
                    (*(char *)((longlong)param_2 + 0x35) != '\0')))))) &&
           ((0x8000 < *(uint *)(param_3 + 0xe) ||
            ('\0' < *(char *)((ulonglong)*(byte *)(lVar4 + 6) + *(longlong *)(param_1 + 0xe8d0))))))
          && (*(char *)((longlong)param_2 + 0xa1) != '\x02')) {
    MPT_BuildLdIO(param_1,param_2,param_3);
    cVar3 = *(char *)((ulonglong)*(byte *)(lVar4 + 6) + *(longlong *)(param_1 + 0xe8d0));
    *(char *)((ulonglong)*(byte *)(lVar4 + 6) + *(longlong *)(param_1 + 0xe8d0)) =
         *(char *)((ulonglong)*(byte *)(lVar4 + 6) + *(longlong *)(param_1 + 0xe8d0)) + -1;
    if (cVar3 < '\0') {
      *(undefined1 *)((ulonglong)*(byte *)(lVar4 + 6) + *(longlong *)(param_1 + 0xe8d0)) = 0;
    }
  }
  if ((*(char *)((longlong)param_2 + 0x32) != '\0') && (*(char *)((longlong)param_2 + 0x35) != '\0')
     ) {
    lVar5 = *param_2;
    uVar9 = *(int *)((longlong)param_2 + 0x14) + 1;
    uVar10 = (ulonglong)uVar9;
    do {
      if (*(longlong *)(uVar10 * 8 + *(longlong *)(param_1 + 0x208)) == 0) {
        plVar1 = (longlong *)(*(longlong *)(param_1 + 0x208) + uVar10 * 8);
        LOCK();
        bVar11 = *plVar1 == 0;
        if (bVar11) {
          *plVar1 = (longlong)param_2;
        }
        UNLOCK();
        if (bVar11) {
          *(int *)(param_2 + 5) = (int)uVar10;
          LOCK();
          piVar2 = (int *)(((ulonglong)*(byte *)(param_2 + 1) + 0x597) * 0x20 + param_1);
          *piVar2 = *piVar2 + 1;
          UNLOCK();
          *(undefined1 *)((longlong)param_2 + 0x12) = 1;
          goto LAB_14000ce4a;
        }
      }
      uVar7 = (int)uVar10 + 1;
      uVar10 = 0;
      if (uVar7 < *(uint *)(param_1 + 0xd804)) {
        uVar10 = (ulonglong)uVar7;
      }
    } while ((uint)uVar10 != uVar9);
    *(undefined1 *)((longlong)param_2 + 0x103) = 0xf1;
    *(ushort *)(param_2 + 0x20) = (ushort)*(byte *)(*param_2 + 6);
    CDB_SetStartLBA((longlong)(param_2 + 0x28),*(char *)(lVar5 + 10),param_2[7]);
    *(undefined1 *)((longlong)param_2 + 0xa4) = 0xe;
    *(undefined1 *)((longlong)param_2 + 0x35) = 0;
    *(ushort *)(param_2 + 0x2c) = *(ushort *)(param_2 + 0x2c) & 0xff12 | 0x12;
    *(undefined1 *)((longlong)param_2 + 0x32) = 0;
    if (*(char *)((longlong)param_2 + 0xa1) == '\x02') {
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x290) != 0)) {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x290,(undefined1 *)0x0,0,
                    (char)lVar6,param_4);
      }
      *(undefined2 *)(param_2 + 10) = 0;
      param_2[0xc] = (longlong)(param_3 + 0x40);
      param_2[0xb] = (longlong)(param_3 + 0x40);
      puVar8 = (uint *)StorPortGetScatterGatherList(param_1,lVar4);
      if (puVar8 == (uint *)0x0) {
        return;
      }
      MPT_BuildIEEESGL(param_1,(longlong)param_2,puVar8);
      param_3[0x3e] = param_3[0x3e] ^ (*(ushort *)(param_2 + 10) ^ param_3[0x3e]) & 0xfff;
    }
    MPT_BuildLdIO(param_1,param_2,param_3);
  }
LAB_14000ce4a:
  if ((*(char *)((longlong)param_2 + 0xc) != '\0') && (*(char *)((longlong)param_2 + 0x35) != '\0'))
  {
    UpdateCDB(param_1,param_2,(longlong)param_3);
  }
  return;
}



===== MPT_RepositionIEEE_SGL @ 14000cea0 =====

void MPT_RepositionIEEE_SGL(undefined8 param_1,undefined8 *param_2,longlong param_3)

{
  byte bVar1;
  ushort uVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined1 local_res10 [8];
  
  uVar2 = *(ushort *)(param_2 + 10);
  if ((*(int *)(param_3 + 0x1c) != 0) && (*(char *)((longlong)param_2 + 0xa1) == '\0')) {
    *(undefined1 *)(param_3 + 0xff) = 0;
    if (uVar2 < 9) {
      if (uVar2 == 8) {
        memmove((void *)param_2[0xd],(void *)(param_3 + 0x100),
                (ulonglong)*(byte *)((longlong)param_2 + 0x52));
        param_2[0xc] = param_2[0xc] - (ulonglong)*(byte *)((longlong)param_2 + 0x52);
      }
    }
    else {
      uVar4 = StorPortGetPhysicalAddress(param_1,*param_2,(void *)(param_3 + 0x100),local_res10);
      puVar3 = (undefined8 *)param_2[0xd];
      *puVar3 = uVar4;
      bVar1 = *(byte *)((longlong)param_2 + 0x52);
      *(undefined4 *)((longlong)puVar3 + 0xc) = 0x80000000;
      *(uint *)(puVar3 + 1) = (uVar2 - 7) * (uint)bVar1;
      if (*(char *)((longlong)param_2 + 0x35) == '\0') {
        *(char *)(param_3 + 2) = (char)(0x100 - (ulonglong)*(byte *)((longlong)param_2 + 0x52) >> 4)
        ;
      }
    }
    *(undefined1 *)((param_2[0xc] - (ulonglong)*(byte *)((longlong)param_2 + 0x52)) + 0xf) = 0x40;
  }
  return;
}



===== MPT_SendIORequestToFW @ 14000cf70 =====

void MPT_SendIORequestToFW(longlong param_1,longlong *param_2)

{
  ushort *_Src;
  undefined4 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined2 uVar4;
  int iVar5;
  byte bVar6;
  
  _Src = (ushort *)(param_2 + 0x20);
  lVar2 = *param_2;
  *(int *)((longlong)param_2 + 0x10c) =
       *(int *)(param_1 + 0x200) + *(int *)((longlong)param_2 + 0x14) * 0x12;
  bVar6 = 0x12;
  if (*(byte *)(lVar2 + 0xb) < 0x12) {
    bVar6 = *(byte *)(lVar2 + 0xb);
  }
  *(byte *)((longlong)param_2 + 0x112) = bVar6;
  if (((*(char *)((longlong)param_2 + 0x9b) == '\0') &&
      (*(char *)((longlong)param_2 + 0x9c) != '\0')) || (*(char *)(lVar2 + 5) == '\0')) {
    *(undefined1 *)(lVar2 + 3) = 1;
    if (7 < *(ushort *)(param_2 + 10)) {
      MPT_RepositionIEEE_SGL(param_1,param_2,(longlong)_Src);
    }
    if (*(char *)((longlong)param_2 + 0x35) != '\0') {
      *(ushort *)((longlong)param_2 + 0x124) = *(ushort *)((longlong)param_2 + 0x124) | 0x4000;
    }
  }
  else {
    if ((*(char *)((longlong)param_2 + 0xf) != '\0') && (**(char **)(param_1 + 0xd750) != '\0')) {
      UpdateIOMetric(param_1,*(byte *)(lVar2 + 6),*(char *)((longlong)param_2 + 0xd),param_2[7],
                     (int)param_2[9],*(uint *)(param_2 + 0x18));
    }
    if ((*(char *)((longlong)param_2 + 0x11) != '\0') && (1 < *(byte *)((longlong)param_2 + 0x83)))
    {
      CDB_SetBlockCnt((longlong)(param_2 + 0x28),*(char *)(lVar2 + 10),
                      (ulonglong)*(uint *)(param_2 + 9));
      *(undefined4 *)((longlong)param_2 + 0x11c) = *(undefined4 *)((longlong)param_2 + 0x4c);
      *(ushort *)((longlong)param_2 + 0x17c) =
           *(ushort *)((longlong)param_2 + 0x17c) ^
           (*(ushort *)(param_2 + 10) ^ *(ushort *)((longlong)param_2 + 0x17c)) & 0xfff;
    }
    if ((*(char *)(lVar2 + 5) == '\x01') && (*(char *)(param_1 + 0x89) == '\0')) {
      if ((*(char *)((longlong)param_2 + 0x11) != '\0') && (1 < *(byte *)((longlong)param_2 + 0x9d))
         ) {
        *(int *)(param_2 + 0x17) = *(int *)(param_1 + 0xd92c) + -1;
        BuildWithRaidMapRwLD(param_1,param_2,_Src);
      }
      if (*(char *)((longlong)param_2 + 0x35) != '\0') {
        MPT_CheckForFp_Possible(param_1,param_2,_Src,4);
      }
      if (*(char *)((longlong)param_2 + 0x103) == '\0') {
        *(ushort *)((longlong)param_2 + 0x124) = *(ushort *)((longlong)param_2 + 0x124) | 0x4000;
        if ((*(char *)((longlong)param_2 + 0xd) != '\0') &&
           (*(char *)((ulonglong)*(byte *)(lVar2 + 6) * 0xc08 + *(longlong *)(param_1 + 0xd978)) !=
            '\0')) {
          MPT_SetBestArm_Pd(param_1,param_2,(short *)_Src,4);
        }
      }
      else if ((((4 < *(byte *)((longlong)param_2 + 0x9d)) &&
                (*(short *)((longlong)param_2 + 0x17c) < 0)) &&
               (*(char *)((longlong)param_2 + 0xe) != '\0')) &&
              ((*(char *)((longlong)param_2 + 0x9e) == '\0' &&
               ((*(ushort *)((longlong)param_2 + 0x164) & 0xf00) == 0xf00)))) {
        *(ushort *)((longlong)param_2 + 0x164) = *(ushort *)((longlong)param_2 + 0x164) & 0xf0ff;
      }
    }
    if (7 < *(ushort *)(param_2 + 10)) {
      MPT_RepositionIEEE_SGL(param_1,param_2,(longlong)_Src);
    }
    *(undefined1 *)(lVar2 + 3) = 1;
    if (*(char *)((longlong)param_2 + 0x12) != '\0') {
      lVar2 = *param_2;
      iVar5 = (int)param_2[5] + 1;
      *(int *)((longlong)param_2 + 0x2c) = iVar5;
      uVar4 = (undefined2)iVar5;
      *(undefined2 *)((longlong)param_2 + 0x174) = uVar4;
      *(undefined2 *)((longlong)param_2 + 0x94) = uVar4;
      *(short *)(param_2 + 0x13) = (short)param_2[6];
      memmove((void *)((ulonglong)*(ushort *)((longlong)param_2 + 0xa6) * 0x100 +
                      *(longlong *)(param_1 + 0xd998)),_Src,0x100);
      *_Src = *(ushort *)(param_2 + 6);
      *(char *)((longlong)param_2 + 0x179) = *(char *)((longlong)param_2 + 0x179) + '\x01';
      *(undefined2 *)((longlong)param_2 + 0x174) = *(undefined2 *)((longlong)param_2 + 0xa6);
      if (*(char *)(lVar2 + 0xb) != '\0') {
        *(int *)((longlong)param_2 + 0x10c) = *(int *)(param_1 + 0x200) + (int)param_2[5] * 0x12;
      }
      memmove((void *)((ulonglong)*(uint *)((longlong)param_2 + 0x2c) * 0x100 +
                      *(longlong *)(param_1 + 0xd998)),_Src,0x100);
      *(char *)((longlong)param_2 + 0x93) = (char)param_2[3];
      *(undefined1 *)((longlong)param_2 + 0x92) = *(undefined1 *)((longlong)param_2 + 0xa4);
      *(undefined2 *)((longlong)param_2 + 0x94) = *(undefined2 *)((longlong)param_2 + 0x2c);
      if (*(char *)(param_1 + 0xe46e) == '\0') {
        uVar3 = *(undefined8 *)((longlong)param_2 + 0x92);
        *(undefined8 *)(*(longlong *)(param_1 + 0x80) + 0xc0) =
             *(undefined8 *)((longlong)param_2 + 0xa4);
        LOCK();
        UNLOCK();
        *(undefined8 *)(*(longlong *)(param_1 + 0x80) + 0xc0) = uVar3;
      }
      else {
        uVar1 = *(undefined4 *)((longlong)param_2 + 0x92);
        *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 200) =
             *(undefined4 *)((longlong)param_2 + 0xa4);
        LOCK();
        UNLOCK();
        *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 200) = uVar1;
      }
      goto LAB_14000d2dc;
    }
  }
  memmove((void *)((ulonglong)*(ushort *)((longlong)param_2 + 0xa6) * 0x100 +
                  *(longlong *)(param_1 + 0xd998)),_Src,0x100);
  if (*(char *)(param_1 + 0xe46e) == '\0') {
    *(undefined8 *)(*(longlong *)(param_1 + 0x80) + 0xc0) =
         *(undefined8 *)((longlong)param_2 + 0xa4);
  }
  else {
    *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 200) = *(undefined4 *)((longlong)param_2 + 0xa4)
    ;
  }
LAB_14000d2dc:
  LOCK();
  UNLOCK();
  return;
}



===== MPT_SendRequestToFW @ 14000d300 =====

void MPT_SendRequestToFW(longlong param_1,longlong *param_2)

{
  char cVar1;
  longlong lVar2;
  ushort uVar3;
  void *_Dst;
  
  uVar3 = *(short *)((longlong)param_2 + 0x14) + 1;
  *(ushort *)((longlong)param_2 + 0xa6) = uVar3;
  cVar1 = *(char *)(*param_2 + 2);
  if (cVar1 == '\0') {
    MPT_SendIORequestToFW(param_1,param_2);
    return;
  }
  lVar2 = *(longlong *)(*param_2 + 0x18);
  if (((cVar1 == '\x02') && (*(char *)(lVar2 + 0x1c) == '\x05')) &&
     (*(int *)(lVar2 + 0x34) == 0x200e100)) {
    DoPauseInput(param_1,4,(char)param_2[3]);
    uVar3 = *(ushort *)((longlong)param_2 + 0xa6);
  }
  lVar2 = param_2[4];
  _Dst = (void *)((ulonglong)uVar3 * 0x100 + *(longlong *)(param_1 + 0xd998));
  memset(_Dst,0,0x100);
  *(undefined2 *)((longlong)_Dst + 2) = 0xf008;
  *(undefined1 *)((longlong)_Dst + 0x14) = 0x20;
  *(undefined4 *)((longlong)_Dst + 0x8c) = 0x80000000;
  *(longlong *)((longlong)_Dst + 0x80) = lVar2;
  *(undefined4 *)((longlong)_Dst + 0x88) = 0x400;
  *(undefined1 *)((longlong)_Dst + 0xff) = 0;
  MFI_SendRequestToFW(param_1,param_2);
  return;
}



===== MPT_SendTaskMgmtToFW @ 14000d3f0 =====

void MPT_SendTaskMgmtToFW(longlong param_1,longlong *param_2)

{
  ushort uVar1;
  undefined2 local_res8;
  undefined1 local_resa;
  undefined1 local_resb;
  
  uVar1 = *(short *)((longlong)param_2 + 0x14) + 1;
  *(ushort *)((longlong)param_2 + 0xa6) = uVar1;
  if ((*(char *)((ulonglong)*(byte *)(*param_2 + 6) + 0xd30a + param_1) != '\0') ||
     (*(char *)(*param_2 + 5) == '\x01')) {
    local_res8 = (undefined2)param_2[0x20];
    local_resa = *(undefined1 *)((longlong)param_2 + 0x103);
    local_resb = *(undefined1 *)((longlong)param_2 + 0x105);
    if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x2008e) != 0)) {
      RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x2008e,
                  (undefined1 *)&local_res8,4,0,4);
      uVar1 = *(ushort *)((longlong)param_2 + 0xa6);
    }
    memmove((void *)((ulonglong)uVar1 * 0x100 + *(longlong *)(param_1 + 0xd998)),param_2 + 0x20,
            0x100);
    if (*(char *)(param_1 + 0xe46e) != '\0') {
      *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 200) =
           *(undefined4 *)((longlong)param_2 + 0xa4);
      LOCK();
      UNLOCK();
      return;
    }
    *(undefined8 *)(*(longlong *)(param_1 + 0x80) + 0xc0) =
         *(undefined8 *)((longlong)param_2 + 0xa4);
    LOCK();
    UNLOCK();
  }
  return;
}



===== MPT_SetBestArm_Pd @ 14000d520 =====

void MPT_SetBestArm_Pd(longlong param_1,longlong *param_2,short *param_3,undefined4 param_4)

{
  int *piVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  longlong lVar5;
  byte bVar6;
  longlong lVar7;
  longlong lVar8;
  
  lVar5 = param_2[3];
  lVar7 = *(longlong *)(param_1 + 0xd930 + (ulonglong)(*(uint *)(param_1 + 0xd92c) - 1 & 1) * 8);
  if (*(short *)(lVar7 + 0x2c) == 0) {
    lVar7 = *(longlong *)(param_1 + 0xd930 + (ulonglong)(*(uint *)(param_1 + 0xd92c) & 1) * 8);
  }
  uVar2 = *(ushort *)(*(longlong *)(lVar7 + 0x40) + (ulonglong)*(byte *)(*param_2 + 6) * 2);
  uVar3 = *(ushort *)
           ((ulonglong)*(byte *)((longlong)param_2 + 0xc5) * 0x128 + (ulonglong)uVar2 * 0x9e0 + 0xb8
           + *(longlong *)(lVar7 + 0x50));
  if (uVar2 < *(ushort *)(param_1 + 0xe462)) {
    lVar8 = (ulonglong)*(byte *)(*param_2 + 6) * 0xc08 + *(longlong *)(param_1 + 0xd978);
    bVar6 = MegaSASCheckBestRaid1Arm
                      (param_1,(longlong)param_2,lVar8,(ulonglong)uVar2,
                       *(byte *)((longlong)param_2 + 0xc4),param_2[8],*(uint *)(param_2 + 9));
    uVar2 = *(ushort *)
             (*(longlong *)(lVar7 + 0x48) + ((ulonglong)uVar3 * 0x20 + (ulonglong)bVar6) * 2);
    if (uVar2 == 0xffff) {
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x291) != 0)) {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x291,(undefined1 *)0x0,0,
                    (char)lVar5,param_4);
      }
    }
    else {
      sVar4 = *(short *)(*(longlong *)(lVar7 + 0x38) + (ulonglong)uVar2 * 8);
      piVar1 = (int *)(lVar8 + 4 + (ulonglong)uVar2 * 4);
      *(undefined1 *)((longlong)param_2 + 0xb) = 1;
      param_2[0x16] = (longlong)piVar1;
      LOCK();
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      if (sVar4 == -1) {
        if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x231) != 0)) {
          RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x231,(undefined1 *)0x0,0,
                      (char)lVar5,param_4);
        }
      }
      else if (*param_3 != sVar4) {
        *(short *)((longlong)param_2 + 0xaa) = sVar4;
        *param_3 = sVar4;
        *(byte *)((longlong)param_2 + 0x179) = *(byte *)((longlong)param_2 + 0x179) | bVar6 != 0;
      }
    }
  }
  return;
}



===== MPT_UpdateReplyQueue @ 14000d720 =====

void MPT_UpdateReplyQueue(longlong param_1)

{
  bool bVar1;
  ushort uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong *plVar5;
  ushort *puVar6;
  int iVar7;
  
  bVar1 = true;
  while( true ) {
    iVar7 = 0;
    if (*(char *)(param_1 + 0xd859) != '\0') {
      puVar6 = (ushort *)(param_1 + 0xd9a0);
      do {
        uVar2 = *puVar6;
        uVar3 = (ulonglong)uVar2;
        plVar5 = (longlong *)(*(longlong *)(puVar6 + 4) + uVar3 * 8);
        lVar4 = *(longlong *)(*(longlong *)(puVar6 + 4) + uVar3 * 8);
        while (lVar4 != -1) {
          LOCK();
          *(int *)(param_1 + 0x92c4) = *(int *)(param_1 + 0x92c4) + -1;
          UNLOCK();
          uVar2 = (short)uVar3 + 1;
          *plVar5 = -1;
          if ((uint)uVar2 < *(uint *)(param_1 + 0xd7fc)) {
            plVar5 = plVar5 + 1;
          }
          else {
            plVar5 = *(longlong **)(puVar6 + 4);
          }
          uVar3 = 0;
          if ((uint)uVar2 < *(uint *)(param_1 + 0xd7fc)) {
            uVar3 = (ulonglong)uVar2;
          }
          uVar2 = (ushort)uVar3;
          lVar4 = *plVar5;
        }
        *puVar6 = uVar2;
        *(uint *)(*(longlong *)(param_1 + 0x80) + 0x6c) = iVar7 << 0x18 | (uint)uVar2;
        LOCK();
        UNLOCK();
        iVar7 = iVar7 + 1;
        puVar6 = puVar6 + 8;
      } while (iVar7 < (int)(uint)*(byte *)(param_1 + 0xd859));
    }
    if ((*(int *)(param_1 + 0x92c4) < 1) || (!bVar1)) break;
    bVar1 = false;
    lVar4 = 100;
    do {
      StorPortStallExecution(1000);
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
  }
  return;
}



===== _guard_check_icall @ 14000d820 =====

void _guard_check_icall(void)

{
  return;
}



===== UpdateCDB @ 14000d830 =====

void UpdateCDB(undefined8 param_1,longlong *param_2,longlong param_3)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  undefined2 uVar8;
  undefined1 uVar9;
  byte bVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  
  lVar4 = *param_2;
  uVar5 = param_2[8];
  lVar6 = param_2[9];
  lVar7 = param_2[0x18];
  bVar10 = *(byte *)(lVar4 + 10);
  uVar12 = (undefined1)((ulonglong)lVar6 >> 8);
  if (*(char *)((longlong)param_2 + 0x9b) == '\0') {
    if ((0xb < bVar10) && (uVar5 < 0x100000000)) {
      if (bVar10 == 0x10) {
        uVar9 = *(undefined1 *)(param_3 + 0x4e);
        uVar11 = *(undefined1 *)(param_3 + 0x4f);
      }
      else {
        uVar9 = *(undefined1 *)(param_3 + 0x4a);
        uVar11 = *(undefined1 *)(param_3 + 0x4b);
      }
      bVar10 = 10;
      *(undefined8 *)(param_3 + 0x40) = 0;
      *(undefined8 *)(param_3 + 0x48) = 0;
      *(undefined8 *)(param_3 + 0x50) = 0;
      *(undefined8 *)(param_3 + 0x58) = 0;
      *(char *)(param_3 + 0x48) = (char)lVar6;
      *(undefined1 *)(param_3 + 0x47) = uVar12;
      *(undefined2 *)(param_3 + 0x24) = 10;
      cVar1 = *(char *)((longlong)param_2 + 0xd);
      *(undefined1 *)(param_3 + 0x41) = *(undefined1 *)(param_3 + 0x41);
      uVar12 = 0x2a;
      if (cVar1 != '\0') {
        uVar12 = 0x28;
      }
      *(undefined1 *)(param_3 + 0x46) = uVar9;
      *(undefined1 *)(param_3 + 0x40) = uVar12;
      *(undefined1 *)(param_3 + 0x49) = uVar11;
    }
  }
  else {
    *(undefined8 *)(param_3 + 0x40) = 0;
    *(undefined8 *)(param_3 + 0x48) = 0;
    *(undefined8 *)(param_3 + 0x50) = 0;
    *(undefined8 *)(param_3 + 0x58) = 0;
    *(undefined1 *)(param_3 + 0x40) = 0x7f;
    *(undefined1 *)(param_3 + 0x47) = 0x18;
    cVar1 = *(char *)((longlong)param_2 + 0xd);
    *(char *)(param_3 + 0x53) = (char)uVar5;
    uVar9 = 0xb;
    if (cVar1 != '\0') {
      uVar9 = 9;
    }
    *(undefined1 *)(param_3 + 0x4a) = 0x20;
    *(undefined1 *)(param_3 + 0x49) = uVar9;
    *(char *)(param_3 + 0x4c) = (char)(uVar5 >> 0x38);
    *(char *)(param_3 + 0x4d) = (char)(uVar5 >> 0x30);
    *(char *)(param_3 + 0x4e) = (char)(uVar5 >> 0x28);
    *(char *)(param_3 + 0x4f) = (char)(uVar5 >> 0x20);
    *(char *)(param_3 + 0x50) = (char)(uVar5 >> 0x18);
    *(char *)(param_3 + 0x51) = (char)(uVar5 >> 0x10);
    *(char *)(param_3 + 0x52) = (char)(uVar5 >> 8);
    *(char *)(param_3 + 0x5c) = (char)((ulonglong)lVar6 >> 0x18);
    *(char *)(param_3 + 0x5d) = (char)((ulonglong)lVar6 >> 0x10);
    *(undefined1 *)(param_3 + 0x5e) = uVar12;
    *(char *)(param_3 + 0x5f) = (char)lVar6;
    uVar3 = *(uint *)(param_2 + 7);
    *(undefined2 *)(param_3 + 0x5a) = 0xffff;
    uVar8 = 0x8743;
    *(uint *)(param_3 + 0x54) =
         ((uVar3 >> 8 & 0xff | uVar3 << 8) << 8 | uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18;
    bVar10 = 0x20;
    if (*(char *)((longlong)param_2 + 0xd) == '\0') {
      uVar8 = 0x8004;
    }
    *(undefined2 *)(param_3 + 0x26) = uVar8;
    *(uint *)(param_3 + 0x3c) = *(uint *)(param_3 + 0x3c) | 0x10000000;
    *(undefined2 *)(param_3 + 0x24) = 0x20;
    *(int *)(param_3 + 0x28) = (int)lVar7;
  }
  bVar2 = *(byte *)(lVar4 + 10);
  if ((bVar2 < 0x10) && (0xffffffff < (ulonglong)param_2[8])) {
    if (bVar2 == 0xc) {
      uVar12 = *(undefined1 *)(param_3 + 0x4a);
      uVar9 = *(undefined1 *)(param_3 + 0x4b);
    }
    else {
      uVar12 = *(undefined1 *)(param_3 + 0x46);
      uVar9 = *(undefined1 *)(param_3 + 0x49);
    }
    bVar10 = 0x10;
    *(undefined8 *)(param_3 + 0x40) = 0;
    *(undefined8 *)(param_3 + 0x48) = 0;
    *(undefined8 *)(param_3 + 0x50) = 0;
    *(undefined8 *)(param_3 + 0x58) = 0;
    lVar4 = param_2[9];
    *(char *)(param_3 + 0x4d) = (char)lVar4;
    *(char *)(param_3 + 0x4c) = (char)((ulonglong)lVar4 >> 8);
    *(char *)(param_3 + 0x4b) = (char)((ulonglong)lVar4 >> 0x10);
    *(char *)(param_3 + 0x4a) = (char)((ulonglong)lVar4 >> 0x18);
    *(undefined2 *)(param_3 + 0x24) = 0x10;
    cVar1 = *(char *)((longlong)param_2 + 0xd);
    *(undefined1 *)(param_3 + 0x41) = *(undefined1 *)(param_3 + 0x41);
    uVar11 = 0x8a;
    if (cVar1 != '\0') {
      uVar11 = 0x88;
    }
    *(undefined1 *)(param_3 + 0x4e) = uVar12;
    *(undefined1 *)(param_3 + 0x40) = uVar11;
    *(undefined1 *)(param_3 + 0x4f) = uVar9;
  }
  CDB_SetStartLBA(param_3 + 0x40,bVar10,param_2[8]);
  return;
}



===== CheckCmdTimeout @ 14000dab0 =====

void CheckCmdTimeout(longlong param_1)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  int *piVar7;
  byte bVar8;
  longlong lVar9;
  int local_res8 [2];
  longlong local_res10;
  
  iVar5 = extendedTimeout;
  local_res8[0] = 0;
  piVar7 = (int *)(param_1 + 0x92e0);
  lVar9 = 0xff;
  do {
    piVar1 = piVar7 + 0x800;
    iVar4 = *piVar7;
    piVar7 = piVar7 + 8;
    local_res8[0] = local_res8[0] + *piVar1 + iVar4;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  if (*(char *)(param_1 + 0xd90c) != '\0') {
    StorPortQuerySystemTime(&local_res10);
    if (local_res10 < (longlong)((ulonglong)(uint)(iVar5 * 10) + *(longlong *)(param_1 + 0xd900))) {
      uVar6 = CheckFirmwareFault(param_1,8,0);
      if ((char)uVar6 != '\0') {
        if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x20086) != 0))
        {
          RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x20086,(undefined1 *)0x0,0
                      ,0,8);
        }
        *(uint *)(param_1 + 0xd810) = *(uint *)(param_1 + 0xd810) | 4;
        *(undefined1 *)(param_1 + 0xd90f) = 1;
        return;
      }
      bVar8 = *(char *)(param_1 + 0xd90d) + 1;
      *(byte *)(param_1 + 0xd90d) = bVar8;
      if (((*(char *)(param_1 + 0xd301) != '\0') && (*(char *)(param_1 + 0xe472) != '\0')) &&
         ((uint)bVar8 == 0xb4 - *(byte *)(param_1 + 0xe471))) {
        Fusion_WriteDoorbell(*(undefined4 **)(param_1 + 0x80),0x100);
      }
      StorPortNotification(6,param_1,CheckCmdTimeout,1000000);
    }
    else {
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x20085) != 0)) {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x20085,
                    (undefined1 *)local_res8,4,0,8);
      }
      *(uint *)(param_1 + 0xd810) = *(uint *)(param_1 + 0xd810) | 4;
      *(undefined1 *)(param_1 + 0xd90f) = 1;
      LOCK();
      puVar2 = (uint *)(param_1 + 0xd80c);
      uVar3 = *puVar2;
      *puVar2 = *puVar2 | 4;
      UNLOCK();
      if ((uVar3 >> 2 & 1) == 0) {
        StartAdapterReset(param_1);
        return;
      }
    }
  }
  return;
}



===== CheckFirmwareFault @ 14000dc80 =====

longlong CheckFirmwareFault(longlong param_1,undefined4 param_2,undefined1 param_3)

{
  uint *puVar1;
  uint uVar2;
  ulonglong in_RAX;
  undefined8 uVar3;
  
  if ((*(char *)(param_1 + 0xd911) == '\0') && (*(char *)(param_1 + 0xd90f) == '\0')) {
    uVar2 = Fusion_ReadRegister(param_1,*(longlong *)(param_1 + 0x80));
    *(uint *)(param_1 + 0xd2e0) = uVar2;
    if (uVar2 < 0x10000000) {
      uVar2 = uVar2 | 0xf0000000;
      *(uint *)(param_1 + 0xd2e0) = uVar2;
    }
    if ((uVar2 & 0xf0000000) != 0xf0000000) {
      return (ulonglong)(uint3)((uVar2 & 0xf0000000) >> 8) << 8;
    }
    in_RAX = 0xf0000000;
    if ((*(char *)(param_1 + 0xeb50) != '\0') &&
       (in_RAX = (ulonglong)*(uint *)(param_1 + 0xeb54), (*(uint *)(param_1 + 0xeb54) & 0x29b) != 0)
       ) {
      in_RAX = RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x29b,
                           (undefined1 *)0x0,0,param_3,param_2);
    }
    *(uint *)(param_1 + 0xd810) = *(uint *)(param_1 + 0xd810) | 4;
    *(undefined1 *)(param_1 + 0xd90f) = 1;
    LOCK();
    puVar1 = (uint *)(param_1 + 0xd80c);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 | 4;
    UNLOCK();
    if ((uVar2 >> 2 & 1) == 0) {
      if (*(char *)(param_1 + 0x89) != '\0') {
        uVar3 = SetDeadAdapter(param_1,0x36,param_2,param_3);
        return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
      }
      if ((*(uint *)(param_1 + 0xd2e0) & 2) == 0) {
        uVar3 = SetDeadAdapter(param_1,0x32,param_2,param_3);
        return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
      }
      if (*(char *)(param_1 + 0xd301) == '\0') {
        uVar3 = SetDeadAdapter(param_1,0x31,param_2,param_3);
        return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
      }
      Fusion_DisableInterrupt(param_1);
      DoPauseInput(param_1,param_2,param_3);
      *(uint *)(param_1 + 0xd80c) = *(uint *)(param_1 + 0xd80c) & 0xfffffffd;
      *(undefined1 *)(param_1 + 0xd90c) = 0;
      in_RAX = StorPortNotification(6,param_1,StartAdapterReset,1000000);
    }
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== CheckResetRetries @ 14000de30 =====

ulonglong CheckResetRetries(longlong param_1,undefined4 param_2)

{
  undefined4 uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  
  *(char *)(param_1 + 0xd920) = *(char *)(param_1 + 0xd920) + '\x01';
  if (*(byte *)(param_1 + 0xd921) < *(byte *)(param_1 + 0xd920)) {
    uVar2 = SetDeadAdapter(param_1,0x35,param_2,0);
    return uVar2 & 0xffffffffffffff00;
  }
  uVar1 = Fusion_ReadRegister(param_1,*(longlong *)(param_1 + 0x80));
  *(undefined4 *)(param_1 + 0xd2e0) = uVar1;
  uVar3 = Fusion_ResetController(param_1,param_2,0);
  if ((char)uVar3 == '\0') {
    uVar2 = SetDeadAdapter(param_1,0x33,param_2,0);
    return uVar2 & 0xffffffffffffff00;
  }
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== CheckTMCmdTimeout @ 14000dec0 =====

void CheckTMCmdTimeout(longlong param_1,undefined4 param_2,undefined1 param_3)

{
  int iVar1;
  longlong local_res8;
  
  DoPauseInput(param_1,param_2,param_3);
  StorPortQuerySystemTime(&local_res8);
  *(longlong *)(param_1 + 0xd900) = local_res8;
  iVar1 = extendedTimeout;
  StorPortQuerySystemTime(&local_res8);
  if (local_res8 < (longlong)((ulonglong)(uint)(iVar1 * 10) + *(longlong *)(param_1 + 0xd900))) {
    StorPortNotification(6,param_1,CheckCmdTimeout,1000000);
  }
  return;
}



===== FreeSRBExtension @ 14000df40 =====

undefined8 FreeSRBExtension(longlong param_1,longlong param_2,uint param_3)

{
  int *piVar1;
  byte bVar2;
  longlong lVar3;
  
  *(undefined8 *)(*(longlong *)(param_1 + 0x208) + (ulonglong)param_3 * 8) = 0;
  lVar3 = (ulonglong)*(byte *)(param_2 + 0xc6) * 0x240;
  bVar2 = *(byte *)(lVar3 + 0x440 + param_1);
  *(byte *)(lVar3 + 0x440 + param_1) = bVar2 + 1;
  *(short *)(param_1 + (((ulonglong)*(byte *)(param_2 + 0xc6) + 1) * 0x120 + (ulonglong)bVar2) * 2)
       = (short)param_3;
  lVar3 = 0x92e0;
  if (*(char *)(param_2 + 9) != '\0') {
    lVar3 = 0xb2e0;
  }
  LOCK();
  piVar1 = (int *)((ulonglong)*(byte *)(param_2 + 8) * 0x20 + lVar3 + param_1);
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if ((*(char *)(param_2 + 0x90) != '\0') && (*(char *)(param_2 + 0x100) == '\x05')) {
    LOCK();
    *(int *)(param_1 + 0x92c0) = *(int *)(param_1 + 0x92c0) + -1;
    UNLOCK();
  }
  return CONCAT71((int7)((ulonglong)(lVar3 + param_1) >> 8),1);
}



===== GetFwOutStandingCmd @ 14000dfd0 =====

int GetFwOutStandingCmd(longlong param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  longlong lVar5;
  
  iVar4 = 0;
  lVar5 = 0xff;
  piVar3 = (int *)(param_1 + 0x92e0);
  do {
    piVar1 = piVar3 + 0x800;
    iVar2 = *piVar3;
    piVar3 = piVar3 + 8;
    iVar4 = iVar4 + *piVar1 + iVar2;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  return iVar4;
}



===== MegaSASResetBus @ 14000e000 =====

undefined8 MegaSASResetBus(longlong param_1)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  int *piVar5;
  longlong lVar6;
  int local_res8;
  undefined1 local_resc;
  undefined1 local_resd;
  undefined1 local_rese;
  undefined8 local_res18 [2];
  
  if (((*(char *)(param_1 + 0xd911) == '\0') && (*(char *)(param_1 + 0xd90f) == '\0')) &&
     (*(char *)(param_1 + 0xd910) == '\0')) {
    uVar3 = CheckFirmwareFault(param_1,6,0);
    if ((char)uVar3 == '\0') {
      iVar2 = GetFwOutStandingCmd(param_1);
      if (iVar2 == 0) {
        if (*(char *)(param_1 + 0x89) == '\0') {
          ReturnReqsToSystem(param_1,'\x01',6);
        }
        DoResumeInput(param_1,6,0);
      }
      else if (*(char *)(param_1 + 0xd90c) == '\0') {
        *(uint *)(param_1 + 0xd80c) = *(uint *)(param_1 + 0xd80c) | 2;
        *(undefined1 *)(param_1 + 0xd90c) = 1;
        DoPauseInput(param_1,6,0);
        StorPortQuerySystemTime(local_res18);
        *(undefined8 *)(param_1 + 0xd900) = local_res18[0];
        *(undefined1 *)(param_1 + 0xd90d) = 0;
        StorPortNotification(6,param_1,CheckCmdTimeout,1000000);
      }
    }
  }
  local_res8 = 0;
  piVar5 = (int *)(param_1 + 0x92e0);
  lVar6 = 0xff;
  do {
    piVar1 = piVar5 + 0x800;
    iVar2 = *piVar5;
    piVar5 = piVar5 + 8;
    local_res8 = local_res8 + *piVar1 + iVar2;
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  local_resc = *(undefined1 *)(param_1 + 0xd90c);
  local_rese = *(undefined1 *)(param_1 + 0xd911);
  local_resd = *(undefined1 *)(param_1 + 0xd90f);
  uVar4 = 0;
  if ((*(char *)(param_1 + 0xeb50) != '\0') &&
     (uVar4 = (ulonglong)*(uint *)(param_1 + 0xeb54), (*(uint *)(param_1 + 0xeb54) & 0x20084) != 0))
  {
    uVar4 = RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x20084,
                        (undefined1 *)&local_res8,8,0,6);
  }
  return CONCAT71((int7)(uVar4 >> 8),1);
}



===== RestartWhenReady @ 14000e190 =====

void RestartWhenReady(longlong param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  longlong local_res8;
  undefined8 local_res10;
  undefined8 local_res18 [2];
  
  if (*(char *)(param_1 + 0xd911) == '\0') {
    uVar1 = CheckFirmwareReady(param_1);
    if ((char)uVar1 == '\0') {
      if ((*(uint *)(param_1 + 0xd2e0) & 0xf0000000) != 0xf0000000) {
        StorPortQuerySystemTime(&local_res8);
        if (local_res8 < *(longlong *)(param_1 + 0xd900) + 3000000000) {
LAB_14000e295:
          StorPortNotification(6,param_1,RestartWhenReady,1000000);
          return;
        }
      }
      uVar2 = CheckResetRetries(param_1,8);
      if ((char)uVar2 != '\0') {
        StorPortQuerySystemTime(&local_res10);
        *(undefined8 *)(param_1 + 0xd900) = local_res10;
        StorPortNotification(6,param_1,RestartWhenReady,1000000);
        return;
      }
    }
    else {
      if (*(char *)(param_1 + 0xe458) == '\0') {
        *(undefined4 *)(param_1 + 0xe43c) = 2;
        *(undefined8 *)(param_1 + 0xe448) = 0;
        WatchDogTimer(param_1);
        return;
      }
      uVar1 = InitializeAdapter(param_1,8);
      if ((char)uVar1 == '\0') {
        uVar2 = CheckResetRetries(param_1,8);
        if ((char)uVar2 != '\0') {
          StorPortQuerySystemTime(local_res18);
          *(undefined8 *)(param_1 + 0xd900) = local_res18[0];
          goto LAB_14000e295;
        }
      }
      else {
        uVar2 = ResubmitPendingReqs(param_1);
        if ((char)uVar2 != '\0') {
          *(uint *)(param_1 + 0xd810) = *(uint *)(param_1 + 0xd810) & 0xfffffffb;
          *(undefined1 *)(param_1 + 0xd90f) = 0;
          LOCK();
          *(uint *)(param_1 + 0xd80c) = *(uint *)(param_1 + 0xd80c) & 0xfffffffb;
          UNLOCK();
          *(uint *)(param_1 + 0xd80c) = *(uint *)(param_1 + 0xd80c) & 0xfffffffd;
          *(uint *)(param_1 + 0xd810) = *(uint *)(param_1 + 0xd810) & 0xffffffef;
          *(undefined1 *)(param_1 + 0xd90c) = 0;
          *(undefined1 *)(param_1 + 0xd910) = 0;
          *(undefined1 *)(param_1 + 0xd920) = 0;
          Fusion_EnableInterrupt(param_1);
          DoResumeInput(param_1,8,0);
          StartBGTimer(param_1);
          return;
        }
      }
    }
  }
  return;
}



===== ResubmitPendingReqs @ 14000e330 =====

undefined8 ResubmitPendingReqs(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  ulonglong in_RAX;
  ulonglong uVar3;
  uint uVar4;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 0xd804) != 0) {
    do {
      in_RAX = uVar3;
      uVar4 = (uint)in_RAX;
      plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x208) + in_RAX * 8);
      if (plVar1 != (longlong *)0x0) {
        lVar2 = *plVar1;
        if (lVar2 == 0) {
          uVar3 = SetDeadAdapter(param_1,0x23,6,0);
LAB_14000e428:
          return uVar3 & 0xffffffffffffff00;
        }
        *(undefined2 *)((longlong)plVar1 + 0x102) = 0xff;
        *(char *)((longlong)plVar1 + 0x53) = *(char *)((longlong)plVar1 + 0x53) + '\x01';
        if (*(byte *)((longlong)plVar1 + 0x53) < 3) {
          in_RAX = *(ulonglong *)(param_1 + 0x80);
          if (*(char *)(param_1 + 0xe46e) == '\0') {
            *(undefined8 *)(in_RAX + 0xc0) = *(undefined8 *)((longlong)plVar1 + 0xa4);
            LOCK();
            UNLOCK();
          }
          else {
            *(undefined4 *)(in_RAX + 200) = *(undefined4 *)((longlong)plVar1 + 0xa4);
            LOCK();
            UNLOCK();
          }
        }
        else {
          *(undefined2 *)(lVar2 + 3) = 1;
          if (*(char *)(lVar2 + 2) == '\x02') {
            *(undefined4 *)(*(longlong *)(lVar2 + 0x18) + 0x14) = 2;
          }
          uVar3 = FreeSRBExtension(param_1,(longlong)plVar1,uVar4);
          if ((char)uVar3 == '\0') goto LAB_14000e428;
          in_RAX = StorPortNotification(0,param_1,lVar2);
        }
      }
      uVar4 = uVar4 + 1;
      uVar3 = (ulonglong)uVar4;
    } while (uVar4 < *(uint *)(param_1 + 0xd804));
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== ReturnReqsToSystem @ 14000e440 =====

ulonglong ReturnReqsToSystem(longlong param_1,char param_2,undefined4 param_3)

{
  uint *puVar1;
  ulonglong in_RAX;
  ulonglong uVar2;
  uint *puVar3;
  longlong *plVar4;
  int iVar5;
  byte bVar6;
  ulonglong uVar7;
  longlong lVar8;
  uint uVar9;
  int iVar10;
  longlong lVar11;
  
  iVar5 = 0;
  uVar9 = 0;
  if (*(longlong *)(param_1 + 0x208) == 0) goto LAB_14000e6d3;
  if ((*(char *)(param_1 + 0x89) == '\0') && (*(longlong *)(param_1 + 0xd818) != 0)) {
    lVar8 = 0;
    do {
      lVar11 = *(longlong *)(param_1 + 0xd818) + lVar8;
      uVar2 = 0;
      do {
        plVar4 = *(longlong **)(lVar11 + 0x30 + uVar2 * 0x28);
        *(undefined8 *)(lVar11 + 0x38 + uVar2 * 0x28) = 0;
        *(undefined8 *)(lVar11 + 0x30 + uVar2 * 0x28) = 0;
        *(undefined1 *)(lVar11 + 0x48 + uVar2 * 0x28) = 0;
        if (plVar4 != (longlong *)0x0) {
          if (*plVar4 == 0) {
            if (param_2 == '\0') goto LAB_14000e6bb;
          }
          else {
            do {
              *(undefined2 *)(*plVar4 + 3) = 0x20b;
              plVar4 = (longlong *)plVar4[0x11];
              StorPortNotification(0,param_1);
            } while (plVar4 != (longlong *)0x0);
          }
        }
        bVar6 = (char)uVar2 + 1;
        uVar2 = (ulonglong)bVar6;
      } while (bVar6 < 8);
      uVar9 = uVar9 + 1;
      lVar8 = lVar8 + 0x180;
    } while (uVar9 < 0x100);
  }
  iVar10 = 0;
  if (*(int *)(param_1 + 0xe4b0) == 0) {
LAB_14000e57a:
    lVar8 = *(longlong *)(param_1 + 0xe4c0 + (ulonglong)*(byte *)(param_1 + 0xe7e0) * 8);
    while (lVar8 != 0) {
      *(undefined1 *)(lVar8 + 3) = 4;
      StorPortNotification(0,param_1,lVar8);
      *(undefined8 *)(param_1 + 0xe4c0 + (ulonglong)*(byte *)(param_1 + 0xe7e0) * 8) = 0;
      *(char *)(param_1 + 0xe7e0) = *(char *)(param_1 + 0xe7e0) + '\x01';
      bVar6 = *(byte *)(param_1 + 0xe7e0);
      if (bVar6 == 100) {
        *(undefined1 *)(param_1 + 0xe7e0) = 0;
        bVar6 = 0;
      }
      lVar8 = *(longlong *)(param_1 + 0xe4c0 + (ulonglong)bVar6 * 8);
    }
    uVar7 = 0;
    if (*(int *)(param_1 + 0xd804) != 0) {
      do {
        plVar4 = *(longlong **)(*(longlong *)(param_1 + 0x208) + uVar7 * 8);
        if (plVar4 != (longlong *)0x0) {
          if (*plVar4 == 0) goto LAB_14000e6bb;
          if ((param_2 == '\0') && (*(char *)(*plVar4 + 2) == '\x02')) {
            iVar10 = iVar10 + 1;
          }
          else {
            if (((*(char *)((longlong)plVar4 + 0x12) != '\0') &&
                (uVar2 = FreeSRBExtension(param_1,(longlong)plVar4,*(uint *)(plVar4 + 5)),
                (char)uVar2 == '\0')) ||
               (uVar2 = FreeSRBExtension(param_1,(longlong)plVar4,*(uint *)((longlong)plVar4 + 0x14)
                                        ), (char)uVar2 == '\0')) goto LAB_14000e6cf;
            do {
              *(undefined2 *)(*plVar4 + 3) = 0x20b;
              plVar4 = (longlong *)plVar4[0x11];
              StorPortNotification(0,param_1);
            } while (plVar4 != (longlong *)0x0);
          }
        }
        uVar9 = (int)uVar7 + 1;
        uVar7 = (ulonglong)uVar9;
      } while (uVar9 < *(uint *)(param_1 + 0xd804));
    }
    puVar3 = (uint *)(param_1 + 0x92e0);
    lVar8 = 0xff;
    do {
      puVar1 = puVar3 + 0x800;
      uVar9 = *puVar3;
      in_RAX = (ulonglong)uVar9;
      puVar3 = puVar3 + 8;
      iVar5 = iVar5 + *puVar1 + uVar9;
      lVar8 = lVar8 + -1;
    } while (lVar8 != 0);
    if (iVar10 == iVar5) {
LAB_14000e6d3:
      return CONCAT71((int7)(in_RAX >> 8),1);
    }
  }
  else {
    lVar8 = *(longlong *)(param_1 + 0xe4b8);
    if ((lVar8 != 0) &&
       (uVar2 = *(longlong *)(lVar8 + 0x38) + 0x100U & 0xfffffffffffffeff, uVar2 != 0)) {
      *(undefined1 *)(lVar8 + 3) = 4;
      uVar2 = FreeSRBExtension(param_1,uVar2,*(uint *)(uVar2 + 0x14));
      if ((char)uVar2 == '\0') goto LAB_14000e6cf;
      StorPortNotification(0,param_1,lVar8);
      *(undefined4 *)(param_1 + 0xe4b0) = 0;
      *(undefined8 *)(param_1 + 0xe4b8) = 0;
      goto LAB_14000e57a;
    }
  }
LAB_14000e6bb:
  uVar2 = SetDeadAdapter(param_1,0x23,param_3,0);
LAB_14000e6cf:
  return uVar2 & 0xffffffffffffff00;
}



===== SetDeadAdapter @ 14000e6f0 =====

void SetDeadAdapter(longlong param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  longlong lVar4;
  undefined4 local_res8;
  int local_resc;
  
  if (*(char *)(param_1 + 0xd911) == '\0') {
    DoPauseInput(param_1,param_3,param_4);
    *(uint *)(param_1 + 0xd80c) = *(uint *)(param_1 + 0xd80c) & 0xfffffffd;
    piVar3 = (int *)(param_1 + 0x92e0);
    *(uint *)(param_1 + 0xd810) = *(uint *)(param_1 + 0xd810) & 0xfffffffb;
    *(undefined1 *)(param_1 + 0xd90c) = 0;
    local_resc = 0;
    *(undefined1 *)(param_1 + 0xd90f) = 0;
    lVar4 = 0xff;
    LOCK();
    *(uint *)(param_1 + 0xd80c) = *(uint *)(param_1 + 0xd80c) & 0xfffffffb;
    UNLOCK();
    *(uint *)(param_1 + 0xd80c) = *(uint *)(param_1 + 0xd80c) | 1;
    *(undefined8 *)(param_1 + 0x9220) = 0;
    *(undefined8 *)(param_1 + 0xedc8) = 0;
    *(undefined1 *)(param_1 + 0xd8d0) = 0;
    *(undefined1 *)(param_1 + 0xd911) = 1;
    do {
      piVar1 = piVar3 + 0x800;
      iVar2 = *piVar3;
      piVar3 = piVar3 + 8;
      local_resc = local_resc + *piVar1 + iVar2;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    local_res8 = param_2;
    if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x20087) != 0)) {
      RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x20087,
                  (undefined1 *)&local_res8,8,param_4,param_3);
    }
    StorPortNotification(6,param_1,RestartWhenReady);
    if (*(longlong *)(param_1 + 0xe8b8) != 0) {
      StorPortExtendedFunction
                (0x21,param_1,*(longlong *)(param_1 + 0xe8b8),MegaSASBackGroundTimer,0,0,0);
      StorPortExtendedFunction(0x22,param_1,*(undefined8 *)(param_1 + 0xe8b8));
      *(undefined8 *)(param_1 + 0xe8b8) = 0;
    }
    Fusion_DisableInterrupt(param_1);
    Fusion_WriteDoorbell(*(undefined4 **)(param_1 + 0x80),0x20);
    ReturnReqsToSystem(param_1,'\x01',param_3);
    memset((void *)(param_1 + 0xe1b0),0,0x100);
    StorPortNotification(7,param_1);
    StorPortNotification(7,param_1);
    DoResumeInput(param_1,param_3,param_4);
    *(undefined1 *)(param_1 + 0xe8af) = 0;
  }
  return;
}



===== StartAdapterReset @ 14000e8e0 =====

void StartAdapterReset(longlong param_1)

{
  undefined8 uVar1;
  undefined8 local_res8 [4];
  
  if (*(char *)(param_1 + 0xd301) == '\0') {
    SetDeadAdapter(param_1,0x31,6,0);
    return;
  }
  uVar1 = ReturnReqsToSystem(param_1,'\0',6);
  if ((char)uVar1 == '\0') {
    return;
  }
  uVar1 = Fusion_ResetController(param_1,6,0);
  if ((char)uVar1 == '\0') {
    SetDeadAdapter(param_1,0x33,6,0);
    return;
  }
  if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x18e) != 0)) {
    RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x18e,(undefined1 *)0x6,0,0,6);
  }
  *(undefined2 *)(param_1 + 0xd920) = 0x200;
  StorPortQuerySystemTime(local_res8);
  *(undefined8 *)(param_1 + 0xd900) = local_res8[0];
  StorPortNotification(6,param_1,RestartWhenReady,1000000);
  return;
}



===== StartBGTimer @ 14000e9e0 =====

void StartBGTimer(longlong param_1)

{
  if (*(longlong *)(param_1 + 0xe8b8) != 0) {
    StorPortExtendedFunction
              (0x21,param_1,*(longlong *)(param_1 + 0xe8b8),MegaSASBackGroundTimer,0,
               *(undefined4 *)(param_1 + 0xd908),0);
  }
  return;
}



===== StopAllTimerRoutine @ 14000ea20 =====

void StopAllTimerRoutine(longlong param_1)

{
  StorPortNotification(6,param_1,RestartWhenReady);
  if (*(longlong *)(param_1 + 0xe8b8) != 0) {
    StorPortExtendedFunction
              (0x21,param_1,*(longlong *)(param_1 + 0xe8b8),MegaSASBackGroundTimer,0,0,0);
    StorPortExtendedFunction(0x22,param_1,*(undefined8 *)(param_1 + 0xe8b8));
    *(undefined8 *)(param_1 + 0xe8b8) = 0;
  }
  return;
}



===== SyncronizeCmdTimeout @ 14000eaa0 =====

undefined8 SyncronizeCmdTimeout(longlong param_1,undefined8 param_2,undefined1 param_3)

{
  uint *puVar1;
  undefined8 *puVar2;
  uint uVar3;
  undefined1 *puVar4;
  byte bVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  undefined4 local_res8 [2];
  
  uVar3 = *(uint *)(param_1 + 0xe4a8);
  puVar4 = (undefined1 *)(ulonglong)uVar3;
  puVar2 = *(undefined8 **)(param_1 + 0xedc8);
  if (uVar3 < 0x10f0301) {
    if (uVar3 == 0x10f0300) {
      puVar6 = *(undefined1 **)(param_1 + 0xe4a0);
      uVar3 = *(uint *)(puVar6 + 4);
      if ((int)uVar3 < 1) {
        *puVar6 = 0;
        if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x2b2) != 0)) {
          uVar7 = 0x2b2;
          goto LAB_14000eb2d;
        }
        goto LAB_14000eb59;
      }
    }
    else if (uVar3 == 0x1020100) {
      if (*(int *)(param_1 + 0xd8e0) == 4) {
        *(undefined4 *)(param_1 + 0xd8e0) = 0;
        **(undefined1 **)(param_1 + 0xe478) = 0;
        puVar4 = (undefined1 *)CompleteCTRLPROPQuery(param_1,8,0);
        if (*(char *)(param_1 + 0xe472) == '\x01') {
          *(undefined4 *)(param_1 + 0xd8ec) = 1;
          *(undefined1 *)(param_1 + 0xd8d0) = 1;
        }
        goto LAB_14000ee1b;
      }
      puVar6 = *(undefined1 **)(param_1 + 0xe478);
      uVar3 = *(uint *)(puVar6 + 4);
      puVar4 = (undefined1 *)(ulonglong)uVar3;
      if ((int)uVar3 < 1) {
        *puVar6 = 0;
        if ((*(char *)(param_1 + 0xeb50) != '\0') &&
           (puVar4 = (undefined1 *)(ulonglong)*(uint *)(param_1 + 0xeb54),
           (*(uint *)(param_1 + 0xeb54) & 0x2ad) != 0)) {
          uVar7 = 0x2ad;
          goto LAB_14000edc3;
        }
        goto LAB_14000edde;
      }
    }
    else if (uVar3 == 0x10f0100) {
      puVar6 = *(undefined1 **)(param_1 + 0xe490);
      uVar3 = *(uint *)(puVar6 + 4);
      if ((int)uVar3 < 1) {
        *puVar6 = 0;
        if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x2b1) != 0)) {
          uVar7 = 0x2b1;
LAB_14000eb2d:
          RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),uVar7,(undefined1 *)0x0,0,
                      param_3,8);
        }
LAB_14000eb59:
        *(undefined4 *)(param_1 + 0xed98) = 0x1c;
        puVar4 = (undefined1 *)HbaFwReloadFsm(param_1,'\x01',0,param_3,puVar2,8);
        *(uint *)(param_1 + 0xd810) = *(uint *)(param_1 + 0xd810) | 4;
        *(undefined1 *)(param_1 + 0xd90f) = 1;
        LOCK();
        puVar1 = (uint *)(param_1 + 0xd80c);
        uVar3 = *puVar1;
        *puVar1 = *puVar1 | 4;
        UNLOCK();
        if ((uVar3 >> 2 & 1) != 0) goto LAB_14000ee1b;
        goto LAB_14000edfa;
      }
    }
    else {
      if (uVar3 != 0x10f0200) goto LAB_14000ee1b;
      puVar6 = *(undefined1 **)(param_1 + 0xe498);
      uVar3 = *(uint *)(puVar6 + 4);
      if ((int)uVar3 < 1) {
        *puVar6 = 0;
        if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x2b0) != 0)) {
          uVar7 = 0x2b0;
          goto LAB_14000eb2d;
        }
        goto LAB_14000eb59;
      }
    }
LAB_14000ec70:
    puVar4 = (undefined1 *)(ulonglong)(uVar3 - 1);
    *(uint *)(puVar6 + 4) = uVar3 - 1;
  }
  else {
    if (uVar3 == 0x1200100) {
      if (*(int *)(param_1 + 0xd8ec) == 4) {
        *(undefined4 *)(param_1 + 0xd8ec) = 0;
        **(undefined1 **)(param_1 + 0xe488) = 0;
        bVar5 = *(byte *)(*(longlong *)(param_1 + 0x1d8) + 3);
        puVar4 = (undefined1 *)0x0;
        if (0x3c < bVar5) {
          bVar5 = 0x3c;
        }
        *(byte *)(param_1 + 0xe471) = bVar5;
        *(undefined1 *)(param_1 + 0xd8f0) = 1;
        *(undefined1 *)(param_1 + 0xd8d0) = 1;
        goto LAB_14000ee1b;
      }
      puVar4 = *(undefined1 **)(param_1 + 0xe488);
      if (0 < *(int *)(puVar4 + 4)) {
        puVar4 = *(undefined1 **)(param_1 + 0xe478);
        *(int *)(puVar4 + 4) = *(int *)(puVar4 + 4) + -1;
        goto LAB_14000ee1b;
      }
      *puVar4 = 0;
      if ((*(char *)(param_1 + 0xeb50) != '\0') &&
         (puVar4 = (undefined1 *)(ulonglong)*(uint *)(param_1 + 0xeb54),
         (*(uint *)(param_1 + 0xeb54) & 0x2af) != 0)) {
        uVar7 = 0x2af;
LAB_14000edc3:
        puVar4 = (undefined1 *)
                 RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),uVar7,
                             (undefined1 *)0x0,0,param_3,8);
      }
    }
    else {
      if (uVar3 != 0x2010100) goto LAB_14000ee1b;
      if (*(int *)(param_1 + 0xd8d8) == 4) {
        *(undefined4 *)(param_1 + 0xd8d8) = 0;
        **(undefined1 **)(param_1 + 0xe480) = 0;
        puVar4 = (undefined1 *)CompletePDquery(param_1,8,0);
        goto LAB_14000ee1b;
      }
      puVar6 = *(undefined1 **)(param_1 + 0xe480);
      uVar3 = *(uint *)(puVar6 + 4);
      puVar4 = (undefined1 *)(ulonglong)uVar3;
      if (0 < (int)uVar3) goto LAB_14000ec70;
      *puVar6 = 0;
      if ((*(char *)(param_1 + 0xeb50) != '\0') &&
         (puVar4 = (undefined1 *)(ulonglong)*(uint *)(param_1 + 0xeb54),
         (*(uint *)(param_1 + 0xeb54) & 0x2ae) != 0)) {
        uVar7 = 0x2ae;
        goto LAB_14000edc3;
      }
    }
LAB_14000edde:
    *(uint *)(param_1 + 0xd810) = *(uint *)(param_1 + 0xd810) | 4;
    *(undefined1 *)(param_1 + 0xd90f) = 1;
    LOCK();
    puVar1 = (uint *)(param_1 + 0xd80c);
    uVar3 = *puVar1;
    *puVar1 = *puVar1 | 4;
    UNLOCK();
    if ((uVar3 >> 2 & 1) != 0) goto LAB_14000ee1b;
    param_3 = 0;
LAB_14000edfa:
    DoPauseInput(param_1,8,param_3);
    puVar4 = (undefined1 *)StartAdapterReset(param_1);
  }
LAB_14000ee1b:
  if ((*(char *)(param_1 + 0xd8d0) != '\0') && (*(char *)(param_1 + 0x89) == '\0')) {
    local_res8[0] = 0;
    puVar4 = (undefined1 *)
             StorPortNotification(0x1002,param_1,param_1 + 0xd888,param_1,param_1,local_res8);
  }
  return CONCAT71((int7)((ulonglong)puVar4 >> 8),1);
}



===== SyncronizeInitializeAdapter @ 14000ee70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SyncronizeInitializeAdapter(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined8 uVar7;
  byte bVar8;
  int iVar9;
  longlong lVar10;
  longlong lVar11;
  undefined1 *puVar12;
  longlong lVar13;
  undefined1 auStackY_98 [32];
  byte local_58 [2];
  char local_56;
  undefined1 local_55;
  undefined8 local_50;
  undefined1 local_48;
  undefined1 local_47;
  undefined1 local_46;
  undefined1 local_45;
  undefined1 local_44;
  undefined1 local_43;
  undefined2 local_42;
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_98;
  lVar13 = 0x100;
LAB_14000eec0:
  uVar6 = *(uint *)(param_1 + 0xe448);
  lVar11 = (longlong)(int)uVar6;
  if (uVar6 - 5 < 2) {
    lVar10 = *(longlong *)(param_1 + 200);
  }
  else if (uVar6 - 0x11 < 2) {
    lVar10 = *(longlong *)(param_1 + 0xc0);
  }
  else if (uVar6 - 0xf < 2) {
    lVar10 = *(longlong *)(param_1 + 0xe8);
  }
  else if (uVar6 - 0xb < 2) {
    lVar10 = *(longlong *)(param_1 + 0xd8);
  }
  else if (uVar6 - 9 < 2) {
    lVar10 = *(longlong *)(param_1 + 0xd0);
  }
  else if (uVar6 - 0x14 < 2) {
    lVar10 = *(longlong *)(param_1 + 0x100);
  }
  else {
    lVar10 = *(longlong *)(param_1 + 0xb0);
  }
  switch(uVar6) {
  case 0:
    *(undefined1 *)(param_1 + 0xd929) = 0;
    *(undefined1 *)(param_1 + 0xd306) = 0;
    *(undefined1 *)(param_1 + 0xd950) = 0;
    if ((*(int *)(param_1 + 0xe8a8) == 0) && (*(char *)(param_1 + 0x89) == '\0')) {
      *(undefined1 *)(param_1 + 0xd928) = 1;
    }
    iVar9 = 0;
    *(undefined2 *)(param_1 + 0xeb68) = 0;
    do {
      iVar1 = *(int *)(*(longlong *)(param_1 + 0x80) + 0xb4);
      iVar9 = iVar9 + 1;
      if (iVar1 != 0) break;
    } while (iVar9 < (int)(uint)*(byte *)(param_1 + 0x88));
    bVar8 = (byte)((uint)iVar1 >> 0x18);
    local_58[0] = bVar8 & 1;
    *(byte *)(param_1 + 0xe8ac) = local_58[0];
    if (*(char *)(param_1 + 0x89) == '\0') {
      *(byte *)(param_1 + 0xeb69) = bVar8 >> 2 & 1;
    }
    local_56 = *(char *)(param_1 + 0xeb69);
    if ((local_56 != '\0') && (*(char *)(param_1 + 0xeb6a) != '\0')) {
      *(undefined1 *)(param_1 + 0xeb68) = 1;
    }
    local_55 = *(undefined1 *)(param_1 + 0xeb68);
    if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 400) != 0)) {
      RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),400,local_58,4,0,6);
    }
    *(undefined8 *)(param_1 + 0xe448) = 3;
    *(undefined4 *)(param_1 + 0xd918) = 180000000;
    goto LAB_14000eec0;
  default:
    goto switchD_14000ef4a_caseD_1;
  case 2:
  case 4:
  case 6:
  case 8:
  case 10:
  case 0xc:
  case 0xe:
  case 0x10:
  case 0x12:
  case 0x15:
  case 0x17:
    if (*(char *)(lVar10 + 0x102) != -1) {
      if ((*(char *)(lVar10 + 0x102) != '\0') &&
         ((0x17 < uVar6 || ((0xa10000U >> (uVar6 & 0x1f) & 1) == 0)))) goto LAB_14000f4a5;
      if (uVar6 == 4) {
        if (*(char *)(param_1 + 0xe459) == '\0') {
          *(undefined4 *)(param_1 + 0xe448) = 3;
          goto LAB_14000eec0;
        }
        uVar6 = Fusion_ReadRegister(param_1,*(longlong *)(param_1 + 0x80));
        *(uint *)(param_1 + 0xd2e0) = uVar6;
        if ((uVar6 & 0xf0000000) != 0xc0000000) {
          *(undefined4 *)(param_1 + 0xe448) = 0x18;
          goto LAB_14000eec0;
        }
      }
      else {
        if (uVar6 == 8) {
          lVar11 = *(longlong *)(param_1 + 0x198);
          bVar8 = (byte)(*(uint *)(lVar11 + 0x7e8) >> 5) & 1;
          *(byte *)(param_1 + 0xe460) = bVar8;
          *(byte *)(param_1 + 0xe46c) = *(byte *)(lVar11 + 0x7eb) & 1;
          *(byte *)(param_1 + 0xe45a) = (byte)(*(uint *)(lVar11 + 0x7e8) >> 0x12) & 1;
          *(byte *)(param_1 + 0xe8ad) = *(byte *)(lVar11 + 0x7fc) >> 6 & 1;
          *(byte *)(param_1 + 0xe46d) = (byte)((uint)*(undefined4 *)(lVar11 + 0x848) >> 8) & 1;
          *(byte *)(param_1 + 0xe46f) = (byte)((ushort)*(undefined2 *)(lVar11 + 0x7fc) >> 0xd) & 1;
          *(byte *)(param_1 + 0xe470) = (byte)(*(uint *)(lVar11 + 0x848) >> 0x11) & 1;
          if (0x40 < *(byte *)(lVar11 + 0x53f)) {
            *(undefined1 *)(param_1 + 0xe460) = 1;
            bVar8 = 1;
          }
          *(undefined4 *)(param_1 + 0xe468) = 0x1000100;
          uVar4 = 0x100;
          if (bVar8 == 0) {
            uVar4 = 0x40;
          }
          *(undefined2 *)(param_1 + 0xe462) = uVar4;
          *(undefined2 *)(param_1 + 0xe464) = 0x100;
          *(uint *)(param_1 + 0xe438) = (byte)~*(byte *)(lVar11 + 0x5b0) >> 4 & 1;
        }
        CompleteDCMD(param_1,lVar10 + 0x100,'\x01',6,0);
      }
      *(undefined4 *)(param_1 + 0xe448) = *(undefined4 *)(param_1 + 0xe44c);
      goto LAB_14000eec0;
    }
    uVar6 = Fusion_ReadRegister(param_1,*(longlong *)(param_1 + 0x80));
    *(uint *)(param_1 + 0xd2e0) = uVar6;
    if ((uVar6 & 0xf0000000) == 0xf0000000) {
      *(undefined4 *)(param_1 + 0xe44c) = *(undefined4 *)(param_1 + 0xe448);
      *(undefined4 *)(param_1 + 0xe448) = 0x18;
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x2ab) != 0)) {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x2ab,(undefined1 *)0x0,0,0,6
                   );
      }
    }
    else {
      if (0 < *(int *)(param_1 + 0xd918)) {
        *(int *)(param_1 + 0xd918) = *(int *)(param_1 + 0xd918) + -10000;
        lVar11 = StorPortNotification(6,param_1,WatchDogTimer,10000);
        goto switchD_14000ef4a_caseD_1;
      }
      *(undefined4 *)(param_1 + 0xe44c) = *(undefined4 *)(param_1 + 0xe448);
      *(undefined4 *)(param_1 + 0xe448) = 0x18;
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x2ac) != 0)) {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x2ac,(undefined1 *)0x0,0,0,6
                   );
      }
    }
    goto LAB_14000eec0;
  case 3:
    uVar7 = MPT_InitializeQueues(param_1,lVar10,*(undefined8 **)(param_1 + 0x1e8));
    *(char *)(param_1 + 0xe459) = (char)uVar7;
    *(undefined4 *)(param_1 + 0xd918) = 180000000;
    *(undefined4 *)(param_1 + 0xe448) = 4;
    *(undefined4 *)(param_1 + 0xe44c) = 7;
    goto LAB_14000eec0;
  case 5:
    *(undefined4 *)(param_1 + 0xe448) = 6;
    *(undefined4 *)(param_1 + 0xe44c) = 0x16;
    WDTSetupAndSendDCMD(param_1,0x2010100);
    goto LAB_14000eec0;
  case 7:
    *(undefined4 *)(param_1 + 0xe448) = 8;
    *(undefined4 *)(param_1 + 0xe44c) = 5;
    WDTSetupAndSendDCMD(param_1,0x1010000);
    goto LAB_14000eec0;
  case 9:
    if (*(char *)(param_1 + 0x89) == '\0') {
      *(undefined4 *)(param_1 + 0xe448) = 10;
      uVar5 = 0x14;
      if (*(char *)(param_1 + 0xe472) == '\0') {
        uVar5 = 0xd;
      }
      *(undefined4 *)(param_1 + 0xe44c) = uVar5;
      WDTSetupAndSendDCMD(param_1,0x1020100);
      goto LAB_14000eec0;
    }
    break;
  case 0xb:
    if (*(char *)(param_1 + 0x89) == '\0') {
      if (*(char *)(param_1 + 0xe46c) != '\0') {
        *(undefined4 *)(param_1 + 0xd954) = 0;
        *(undefined4 *)(param_1 + 0xe448) = 0xc;
        *(undefined4 *)(param_1 + 0xe44c) = 0x13;
        WDTSetupAndSendDCMD(param_1,0x200e102);
      }
      goto LAB_14000eec0;
    }
    break;
  case 0xd:
    if (*(char *)(param_1 + 0x89) == '\0') {
      *(undefined4 *)(param_1 + 0xe448) = 0xe;
      *(undefined4 *)(param_1 + 0xe44c) = 0xf;
      WDTSetupAndSendDCMD(param_1,0x1040100);
      goto LAB_14000eec0;
    }
    break;
  case 0xf:
    *(undefined4 *)(param_1 + 0xe448) = 0x11;
    goto LAB_14000eec0;
  case 0x11:
    if (*(char *)(param_1 + 0x89) == '\0') {
      if (*(char *)(param_1 + 0xd928) == '\0') {
        *(undefined4 *)(param_1 + 0xe448) = 0x13;
      }
      else {
        *(undefined4 *)(param_1 + 0xd92c) = 0;
        uVar5 = 0xb;
        if (*(char *)(param_1 + 0xe46c) == '\0') {
          uVar5 = 0x13;
        }
        *(undefined4 *)(param_1 + 0xe448) = 0x12;
        *(undefined4 *)(param_1 + 0xe44c) = uVar5;
        WDTSetupAndSendDCMD(param_1,0x300e101);
      }
      goto LAB_14000eec0;
    }
    break;
  case 0x13:
    MPT_UpdateReplyQueue(param_1);
    if (*(int *)(param_1 + 0x92c4) < 1) {
      if (*(char *)(param_1 + 0xd928) != '\0') {
        *(undefined4 *)(param_1 + 0xd92c) = 1;
        IssueDCMD(param_1,0x300e101,'\0');
        if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x19b) != 0)) {
          RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x19b,(undefined1 *)0x0,0,0
                      ,6);
        }
      }
      *(undefined1 *)(param_1 + 0xd305) = 0;
      IssueDCMD(param_1,0x1040500,'\0');
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x19c) != 0)) {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x19c,(undefined1 *)0x0,0,0,6
                   );
      }
      if (*(char *)(param_1 + 0xe46c) != '\0') {
        *(undefined4 *)(param_1 + 0xd954) = 1;
        IssueDCMD(param_1,0x200e102,'\0');
      }
      break;
    }
LAB_14000f4a5:
    *(undefined4 *)(param_1 + 0xe448) = 0x18;
    goto LAB_14000eec0;
  case 0x14:
    *(undefined4 *)(param_1 + 0xe448) = 0x15;
    *(undefined4 *)(param_1 + 0xe44c) = 0xd;
    WDTSetupAndSendDCMD(param_1,0x1200100);
    goto LAB_14000eec0;
  case 0x16:
    if (*(char *)(param_1 + 0x89) == '\0') {
      *(undefined4 *)(param_1 + 0xe448) = 0x17;
      *(undefined4 *)(param_1 + 0xe44c) = 9;
      WDTSetupAndSendDCMD(param_1,0x1200500);
      goto LAB_14000eec0;
    }
    break;
  case 0x18:
    if (*(int *)(param_1 + 0xe444) == 6) goto code_r0x00014000f616;
    lVar11 = CheckResetRetries(param_1,6);
    if ((char)lVar11 != '\0') {
      StorPortQuerySystemTime(&local_50);
      *(undefined8 *)(param_1 + 0xd900) = local_50;
      lVar11 = StorPortNotification(6,param_1,RestartWhenReady,1000000);
    }
switchD_14000ef4a_caseD_1:
    return CONCAT71((int7)((ulonglong)lVar11 >> 8),1);
  case 0x19:
    if (*(char *)(param_1 + 0x89) == '\0') {
      memset(*(void **)(param_1 + 0xd978),0,
             ((ulonglong)*(ushort *)(param_1 + 0xd302) + 0xc08) * 0x100);
      if (*(void **)(param_1 + 0xd818) != (void *)0x0) {
        memset(*(void **)(param_1 + 0xd818),0,
               ((ulonglong)*(ushort *)(param_1 + 0xd302) + 0x180) * 0x100);
        lVar10 = 0;
        lVar11 = 0;
        puVar12 = (undefined1 *)(param_1 + 0xec88);
        do {
          lVar11 = lVar11 + 0x180;
          *(undefined4 *)(*(longlong *)(param_1 + 0xd818) + -0x17c + lVar11) = 0x76543210;
          *(undefined4 *)(*(longlong *)(param_1 + 0xd820) + 8 + lVar10) = 0x76543210;
          *puVar12 = 8;
          lVar2 = *(longlong *)(param_1 + 0xd820);
          *(undefined4 *)(lVar10 + lVar2) = 0;
          *(undefined4 *)(lVar10 + 4 + lVar2) = 1;
          lVar10 = lVar10 + 0xa0;
          lVar13 = lVar13 + -1;
          puVar12 = puVar12 + 1;
        } while (lVar13 != 0);
      }
      local_3e = *(undefined2 *)(param_1 + 0xe462);
      *(undefined2 *)(param_1 + 0xd308) = local_3e;
    }
    else {
      local_3e = *(undefined2 *)(param_1 + 0xe462);
    }
    local_44 = *(undefined1 *)(param_1 + 0xe46d);
    local_48 = *(undefined1 *)(param_1 + 0xe460);
    local_47 = *(undefined1 *)(param_1 + 0xe45a);
    local_46 = *(undefined1 *)(param_1 + 0xe46c);
    local_45 = *(undefined1 *)(param_1 + 0xe8ad);
    local_43 = *(undefined1 *)(param_1 + 0xe438);
    local_40 = *(undefined2 *)(param_1 + 0xe46a);
    local_42 = *(undefined2 *)(param_1 + 0xe468);
    local_3c = *(undefined2 *)(param_1 + 0xe464);
    if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x184) != 0)) {
      RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x184,&local_48,0xe,0,6);
    }
    lVar11 = ResubmitPendingReqs(param_1);
    if ((char)lVar11 != '\0') {
      *(uint *)(param_1 + 0xd810) = *(uint *)(param_1 + 0xd810) & 0xffffffeb;
      *(undefined1 *)(param_1 + 0xd90f) = 0;
      LOCK();
      *(uint *)(param_1 + 0xd80c) = *(uint *)(param_1 + 0xd80c) & 0xfffffffb;
      UNLOCK();
      Fusion_EnableInterrupt(param_1);
      *(uint *)(param_1 + 0xd80c) = *(uint *)(param_1 + 0xd80c) & 0xfffffffd;
      *(undefined1 *)(param_1 + 0xd90c) = 0;
      *(undefined1 *)(param_1 + 0xd910) = 0;
      *(undefined1 *)(param_1 + 0xd920) = 0;
      *(undefined4 *)(param_1 + 0xe43c) = 0;
      DoResumeInput(param_1,6,0);
      if (*(char *)(param_1 + 0xd758) != '\0') {
        ScsiPortWmiFireLogicalUnitEvent
                  (param_1,-1,0,0,(int *)&MegaSASWmiSetupDataGuid,0,0x10,(int *)(param_1 + 0xd75c));
      }
      LOCK();
      *(undefined8 *)(param_1 + 0xe8c0) = 0;
      UNLOCK();
      if (*(longlong *)(param_1 + 0xe8b8) != 0) {
        StorPortExtendedFunction(0x21,param_1);
      }
      puVar3 = *(undefined8 **)(param_1 + 0xedc8);
      lVar11 = 0;
      if (puVar3 != (undefined8 *)0x0) {
        lVar11 = HbaFwReloadFsm(param_1,'\x01',(longlong)(puVar3 + 0x20),0,puVar3,6);
      }
    }
    goto switchD_14000ef4a_caseD_1;
  }
  *(undefined4 *)(param_1 + 0xe448) = 0x19;
  goto LAB_14000eec0;
code_r0x00014000f616:
  *(undefined4 *)(param_1 + 0xe448) = 9;
  goto LAB_14000eec0;
}



===== Fusion_ResetController @ 14000f9c0 =====

ulonglong Fusion_ResetController(longlong param_1,undefined4 param_2,undefined1 param_3)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  int iVar4;
  longlong lVar5;
  uint uVar6;
  longlong lVar7;
  longlong lVar8;
  undefined4 uVar9;
  bool bVar10;
  
  *(undefined1 *)(param_1 + 0xd910) = 1;
  *(uint *)(param_1 + 0xd810) = *(uint *)(param_1 + 0xd810) | 0x10;
  lVar5 = 30000;
  *(undefined2 *)(param_1 + 0xd8d2) = 0;
  *(undefined1 *)(param_1 + 0xd8d1) = 0;
  *(undefined1 *)(param_1 + 0xd8e4) = 0;
  *(undefined1 *)(param_1 + 0xd8d4) = 0;
  *(undefined1 *)(param_1 + 0xd90e) = 1;
  *(undefined4 *)(param_1 + 0xd8d8) = 0;
  *(undefined4 *)(param_1 + 0xd8e0) = 0;
  lVar8 = 30000;
  do {
    lVar7 = lVar8;
    StorPortStallExecution(100);
    lVar8 = lVar7 + -1;
  } while (lVar8 != 0);
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 4) = 0;
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 4) = 0xf;
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 4) = 4;
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 4) = 0xb;
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 4) = 2;
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 4) = 7;
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 4) = 0xd;
  LOCK();
  UNLOCK();
  StorPortStallExecution((int)lVar7 + 99);
  uVar6 = 0;
LAB_14000fad0:
  StorPortStallExecution(100);
  iVar4 = 0;
  do {
    uVar1 = *(uint *)(*(longlong *)(param_1 + 0x80) + 8);
    iVar4 = iVar4 + 1;
    if (uVar1 != 0) break;
  } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x88));
  if (-1 < (char)uVar1) goto code_r0x00014000fafd;
  *(uint *)(*(longlong *)(param_1 + 0x80) + 8) = uVar1 | 4;
  LOCK();
  UNLOCK();
  do {
    StorPortStallExecution(100);
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  uVar6 = 0;
  do {
    uVar2 = StorPortStallExecution(1000);
    iVar4 = 0;
    do {
      uVar1 = *(uint *)(*(longlong *)(param_1 + 0x80) + 8);
      iVar4 = iVar4 + 1;
      if (uVar1 != 0) break;
      uVar2 = 0;
    } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x88));
    if ((uVar1 & 4) == 0) {
      *(uint *)(param_1 + 0xd810) = *(uint *)(param_1 + 0xd810) & 0xffffffef;
      *(undefined1 *)(param_1 + 0xd910) = 0;
      return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
    }
    uVar3 = (ulonglong)uVar6;
    bVar10 = uVar6 < 1000;
    uVar6 = uVar6 + 1;
  } while (bVar10);
  if ((*(char *)(param_1 + 0xeb50) == '\0') ||
     (uVar3 = (ulonglong)*(uint *)(param_1 + 0xeb54), (*(uint *)(param_1 + 0xeb54) & 0x28e) == 0))
  goto LAB_14000fbdb;
  uVar9 = 0x28e;
  goto LAB_14000fbb1;
code_r0x00014000fafd:
  uVar3 = (ulonglong)uVar6;
  bVar10 = 99 < uVar6;
  uVar6 = uVar6 + 1;
  if (bVar10) {
    if ((*(char *)(param_1 + 0xeb50) != '\0') &&
       (uVar3 = (ulonglong)*(uint *)(param_1 + 0xeb54), (*(uint *)(param_1 + 0xeb54) & 0x28d) != 0))
    {
      uVar9 = 0x28d;
LAB_14000fbb1:
      uVar3 = RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),uVar9,(undefined1 *)0x0
                          ,0,param_3,param_2);
    }
LAB_14000fbdb:
    return uVar3 & 0xffffffffffffff00;
  }
  goto LAB_14000fad0;
}



===== RttAddRecord @ 14000fc10 =====

void RttAddRecord(int *param_1,undefined4 *param_2,undefined4 param_3,undefined1 *param_4,
                 uint param_5,undefined8 param_6,undefined4 param_7)

{
  undefined1 uVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined4 *puVar4;
  
  lVar2 = *(longlong *)(param_1 + 10);
  *param_2 = param_3;
  param_2[1] = param_5 + 0x14;
  StorPortQuerySystemTime(param_2 + 2);
  param_2[4] = param_7;
  puVar4 = param_2 + 5;
  if (param_5 != 0) {
    uVar3 = (ulonglong)param_5;
    do {
      uVar1 = *param_4;
      param_4 = param_4 + 1;
      *(undefined1 *)puVar4 = uVar1;
      puVar4 = (undefined4 *)((longlong)puVar4 + 1);
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  *puVar4 = 0;
  puVar4[1] = 8;
  param_1[0xd] = param_1[0xd] + 1;
  *(undefined4 **)(param_1 + 6) = puVar4;
  *(int *)(lVar2 + 100) = param_1[4] - *param_1;
  return;
}



===== RttInitTrace @ 14000fcb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void RttInitTrace(longlong *param_1)

{
  undefined4 *puVar1;
  char *pcVar2;
  
  if ((char)param_1[7] != '\0') {
    pcVar2 = (char *)*param_1;
    *(undefined4 *)((longlong)param_1 + 0x3c) = 0x7fbf00;
    param_1[2] = (longlong)pcVar2;
    param_1[3] = (longlong)pcVar2;
    param_1[4] = 0;
    param_1[1] = (longlong)(pcVar2 + *(uint *)(param_1 + 6));
    *(undefined4 *)((longlong)param_1 + 0x34) = 0;
    if (7 < *(uint *)(param_1 + 6)) {
      pcVar2[0] = '\0';
      pcVar2[1] = '\0';
      pcVar2[2] = '\0';
      pcVar2[3] = '\0';
      *(undefined4 *)(param_1[2] + 4) = 8;
      pcVar2 = (char *)*param_1;
    }
    param_1[5] = (longlong)pcVar2;
    pcVar2[0] = 'M';
    pcVar2[1] = 'E';
    pcVar2[2] = 'G';
    pcVar2[3] = 'A';
    pcVar2[4] = 'S';
    pcVar2[5] = 'A';
    pcVar2[6] = 'S';
    pcVar2[7] = '3';
    pcVar2[8] = '5';
    pcVar2[0x40] = '2';
    pcVar2[0x41] = '.';
    pcVar2[0x42] = '1';
    pcVar2[0x43] = '\0';
    pcVar2[0x60] = -0x47;
    pcVar2[0x61] = 'V';
    pcVar2[0x62] = -3;
    pcVar2[99] = '_';
    *(int *)(pcVar2 + 0x44) = (int)param_1[6];
    *(undefined4 *)(pcVar2 + 0x48) = *(undefined4 *)((longlong)param_1 + 0x34);
    pcVar2[0x68] = '\x01';
    pcVar2[0x4c] = '\0';
    pcVar2[0x4d] = -0x41;
    pcVar2[0x4e] = '\x7f';
    pcVar2[0x4f] = '\0';
    puVar1 = (undefined4 *)(*param_1 + 0x80);
    *param_1 = (longlong)puVar1;
    param_1[1] = (ulonglong)*(uint *)(param_1 + 6) + param_1[5];
    param_1[2] = (longlong)puVar1;
    param_1[3] = (longlong)puVar1;
    if (7 < *(uint *)(param_1 + 6)) {
      *puVar1 = 0;
      *(undefined4 *)(param_1[2] + 4) = 8;
    }
  }
  return;
}



===== RttLogEvent @ 14000fdb0 =====

void RttLogEvent(longlong param_1,undefined8 param_2,int *param_3,undefined4 param_4,
                undefined1 *param_5,uint param_6,undefined1 param_7,undefined4 param_8)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0xeb60);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  iVar3 = *(int *)(param_1 + 0xeb64);
  while (iVar2 + 1 != iVar3) {
    iVar3 = *(int *)(param_1 + 0xeb64);
  }
  RttLogEventCore(param_3,param_4,param_5,param_6,param_7,param_8);
  LOCK();
  *(int *)(param_1 + 0xeb64) = *(int *)(param_1 + 0xeb64) + 1;
  UNLOCK();
  return;
}



===== RttLogEventCore @ 14000fe20 =====

void RttLogEventCore(int *param_1,undefined4 param_2,undefined1 *param_3,uint param_4,
                    undefined1 param_5,undefined4 param_6)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  longlong lVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined7 in_stack_ffffffffffffffe1;
  
  uVar7 = param_4 + 0x1c;
  if (uVar7 <= (uint)param_1[0xc]) {
    puVar3 = *(undefined4 **)(param_1 + 4);
    puVar8 = *(undefined4 **)(param_1 + 6);
    puVar2 = puVar3;
    while (puVar8 < puVar2) {
      do {
        if (uVar7 <= (uint)((int)puVar3 - (int)puVar8)) goto LAB_14000fece;
        uVar1 = *(uint *)(*(longlong *)(param_1 + 4) + 4);
        param_1[0xd] = param_1[0xd] + -1;
        piVar6 = (int *)((ulonglong)uVar1 + *(longlong *)(param_1 + 4));
        *(int **)(param_1 + 4) = piVar6;
        puVar3 = (undefined4 *)((ulonglong)piVar6 & 0xffffffff);
      } while (*piVar6 != 1);
      puVar2 = *(undefined4 **)param_1;
      *(undefined4 **)(param_1 + 4) = puVar2;
      puVar3 = (undefined4 *)((ulonglong)puVar2 & 0xffffffff);
    }
    if ((uint)(param_1[2] - (int)puVar8) <= uVar7) {
      *puVar8 = 1;
      *(undefined4 *)(*(longlong *)(param_1 + 6) + 4) = 8;
      if ((uint)(param_1[4] - *param_1) < uVar7) {
        lVar4 = *(longlong *)(param_1 + 4);
        iVar5 = param_1[0xd];
        do {
          iVar5 = iVar5 + -1;
          lVar4 = lVar4 + (ulonglong)*(uint *)(lVar4 + 4);
          param_1[0xd] = iVar5;
          *(longlong *)(param_1 + 4) = lVar4;
        } while ((uint)((int)lVar4 - *param_1) < uVar7);
      }
      puVar8 = *(undefined4 **)param_1;
    }
LAB_14000fece:
    RttAddRecord(param_1,puVar8,param_2,param_3,param_4,CONCAT71(in_stack_ffffffffffffffe1,param_5),
                 param_6);
  }
  return;
}



===== RttSetTraceParameters @ 14000ff10 =====

void RttSetTraceParameters(longlong param_1,int param_2,int param_3)

{
  if (param_3 == 0) {
    *(undefined1 *)(param_1 + 0x38) = 0;
  }
  else if (param_3 == 1) {
    *(undefined1 *)(param_1 + 0x38) = 1;
  }
  if (param_2 != -1) {
    *(int *)(param_1 + 0x30) = param_2;
  }
  return;
}



===== HbaFwReloadFsm @ 14000ff30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HbaFwReloadFsm(longlong param_1,char param_2,longlong param_3,undefined1 param_4,
                   undefined8 *param_5,undefined4 param_6)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  uint *puVar4;
  longlong lVar5;
  undefined4 uVar6;
  undefined1 auStackY_a8 [32];
  undefined4 *puVar7;
  int *piVar8;
  uint uVar9;
  undefined4 local_68;
  uint local_64;
  undefined4 local_60 [2];
  longlong local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined1 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_a8;
  lVar2 = *(longlong *)(param_1 + 0xedb8);
  piVar1 = (int *)(param_1 + 0xed98);
  lVar5 = *(longlong *)(lVar2 + 0x18);
  local_48 = 0;
  local_4c = 0;
  *(undefined8 **)(param_1 + 0xedc8) = param_5;
  local_58 = lVar2;
  if (param_2 == '\0') {
    if (*piVar1 == 0) {
      if ((*(uint *)(lVar5 + 0x28) & 1) != 0) goto LAB_140010000;
      *(undefined4 *)(lVar2 + 0x10) = 0x1c;
      local_48 = 1;
      *(undefined1 *)(lVar2 + 3) = 1;
      local_4c = 2;
      local_50 = *(undefined4 *)(lVar5 + 0x10);
      *(undefined4 *)(lVar5 + 0x14) = 2;
      StorPortNotification(0,param_1,lVar2);
      *(undefined8 *)(param_1 + 0xedb8) = 0;
      *(undefined8 *)(param_1 + 0xedc8) = 0;
    }
    else {
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x26b) != 0)) {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x26b,(undefined1 *)piVar1,
                    0x20,param_4,param_6);
      }
      *(undefined4 *)(lVar2 + 0x10) = 0x1c;
      local_48 = 1;
      *(undefined1 *)(lVar2 + 3) = 1;
      local_4c = 1;
      local_50 = *(undefined4 *)(lVar5 + 0x10);
      *(undefined4 *)(lVar5 + 0x14) = 1;
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x400025) != 0))
      {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x400025,
                    (undefined1 *)&local_58,0x11,param_4,param_6);
      }
      StorPortNotification(0,param_1,lVar2);
      *piVar1 = 0;
      *(undefined8 *)(param_1 + 0xedb8) = 0;
      *(undefined8 *)(param_1 + 0xedc8) = 0;
    }
switchD_140010016_caseD_4:
    return;
  }
  if (*(char *)(param_1 + 0xeb50) == '\0') goto LAB_140010000;
  if ((*(uint *)(param_1 + 0xeb54) & 0x400003) == 0) goto LAB_140010000;
  uVar9 = 0x20;
  uVar6 = 0x400003;
  piVar8 = piVar1;
LAB_14000ffe0:
  RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),uVar6,(undefined1 *)piVar8,uVar9,
              param_4,param_6);
LAB_140010000:
  switch(*piVar1) {
  case 0:
    iVar3 = *(int *)(lVar5 + 0x24);
    if (iVar3 == 1) {
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x400004) != 0))
      {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x400004,(undefined1 *)piVar1
                    ,0x20,param_4,param_6);
      }
      *(undefined1 *)((longlong)param_5 + 0x82) = 1;
      *piVar1 = 1;
    }
    else if (iVar3 == 2) {
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x400005) != 0))
      {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x400005,(undefined1 *)piVar1
                    ,0x20,param_4,param_6);
      }
      *piVar1 = 2;
      *(undefined1 *)((longlong)param_5 + 0x82) = 1;
    }
    else if (iVar3 == 3) {
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x400006) != 0))
      {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x400006,(undefined1 *)piVar1
                    ,0x20,param_4,param_6);
      }
      *piVar1 = 0x10;
      *(undefined1 *)((longlong)param_5 + 0x82) = 1;
    }
    else {
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 599) != 0)) {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),599,
                    (undefined1 *)(lVar5 + 0x1c),0x18,param_4,param_6);
      }
      *(undefined4 *)(lVar2 + 0x10) = 0x1c;
      *(undefined1 *)(lVar2 + 3) = 1;
      *(undefined4 *)(lVar5 + 0x14) = 3;
      *piVar1 = 0x14;
    }
    goto LAB_140010000;
  case 1:
    if (*(uint *)(lVar5 + 0x18) < 0x4c) {
      *(undefined4 *)(lVar2 + 0x10) = 0x1c;
      *(undefined1 *)(lVar2 + 3) = 1;
      *(undefined4 *)(lVar5 + 0x14) = 5;
      *piVar1 = 0x14;
    }
    else {
      *(undefined4 *)(lVar5 + 0x38) = 2;
      *(undefined4 *)(lVar5 + 0x3c) = 0x18;
      *(undefined4 *)(lVar5 + 0x40) = 0xff000101;
      *(undefined4 *)(lVar5 + 0x44) = 0;
      *(undefined4 *)(lVar5 + 0x48) = 4;
      *(undefined4 *)(lVar5 + 0x4c) = 0x80000;
      *(undefined2 *)(lVar5 + 0x50) = 0;
      memmove((void *)(lVar5 + 0x58),(void *)(*(longlong *)(param_1 + 0x198) + 0x640),0xe);
      *(undefined4 *)(lVar5 + 0x52) = 0;
      *(undefined2 *)(lVar5 + 0x56) = 0;
      *(undefined4 *)(lVar2 + 0x10) = 0x4c;
      *(undefined1 *)(lVar2 + 3) = 1;
      *(undefined4 *)(lVar5 + 0x14) = 0;
      *(undefined1 *)((longlong)param_5 + 0x81) = 1;
      *piVar1 = 0x14;
    }
    goto LAB_140010000;
  case 2:
    if (*(uint *)(lVar2 + 0x14) < 0xb4) {
      *(undefined4 *)(lVar2 + 0x14) = 0xb4;
    }
    if (*(uint *)(lVar5 + 0xc) < 0xb4) {
      *(undefined4 *)(lVar5 + 0xc) = 0xb4;
    }
    puVar4 = (uint *)StorPortGetScatterGatherList(param_1,lVar2);
    if (puVar4 == (uint *)0x0) {
      *(undefined4 *)(lVar2 + 0x10) = 0x1c;
      *(undefined1 *)(lVar2 + 3) = 1;
      *(undefined4 *)(lVar5 + 0x14) = 1;
      *piVar1 = 0x14;
      goto LAB_140010000;
    }
    if (*puVar4 <= *(uint *)(param_1 + 0xd7f4)) {
      iVar3 = 3;
      if ((*(uint *)(lVar5 + 0x28) & 4) == 0) {
        iVar3 = 0xd;
      }
      *piVar1 = iVar3;
      goto LAB_140010000;
    }
    *(undefined4 *)(lVar2 + 0x10) = 0x1c;
    *(undefined1 *)(lVar2 + 3) = 1;
    *(undefined4 *)(lVar5 + 0x14) = 1;
    local_68 = *(undefined4 *)(param_1 + 0xd7f4);
    local_64 = *puVar4;
    if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x26d) != 0)) {
      puVar7 = &local_68;
      uVar6 = 0x26d;
      uVar9 = 8;
      goto LAB_140010675;
    }
    break;
  case 3:
    if (((*(int *)(lVar5 + 0x58) == 0x36313533) || (*(int *)(lVar5 + 0x58) == -0x14ffffbe)) ||
       (0xffffff < *(uint *)(lVar5 + 0x54))) {
      *(undefined4 *)(param_1 + 0xedb0) = *(undefined4 *)(lVar5 + 0x54);
      *piVar1 = 0x15;
      goto LAB_140010000;
    }
    *(undefined4 *)(lVar2 + 0x10) = 0x1c;
    *(undefined1 *)(lVar2 + 3) = 1;
    *(undefined4 *)(lVar5 + 0x14) = 7;
    local_60[0] = *(undefined4 *)(lVar5 + 0x58);
    if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x264) != 0)) {
      puVar7 = local_60;
      uVar6 = 0x264;
      uVar9 = 8;
      goto LAB_140010675;
    }
    break;
  default:
    goto switchD_140010016_caseD_4;
  case 0xd:
    if (*(char *)(lVar5 + 0x50) == '\0') {
      *piVar1 = 0x17;
      goto LAB_140010000;
    }
    *(undefined4 *)(lVar2 + 0x10) = 0x1c;
    *(undefined1 *)(lVar2 + 3) = 1;
    *(undefined4 *)(lVar5 + 0x14) = 6;
    if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x25a) != 0)) {
      uVar6 = 0x25a;
      goto LAB_140010661;
    }
    break;
  case 0x10:
    if (*(uint *)(lVar2 + 0x14) < 0xb4) {
      *(undefined4 *)(lVar2 + 0x14) = 0xb4;
    }
    if (*(uint *)(lVar5 + 0xc) < 0xb4) {
      *(undefined4 *)(lVar5 + 0xc) = 0xb4;
    }
    DoPauseInput(param_1,param_6,param_4);
    iVar3 = *(int *)(param_1 + 0xd7fc) + -1;
    *(int *)((longlong)param_5 + 0x14) = iVar3;
    *(undefined1 *)(param_5 + 0x20) = 5;
    *(undefined4 *)(param_5 + 0x23) = 0x10f0300;
    *(undefined1 *)((longlong)param_5 + 0x102) = 0xff;
    *(int *)(param_5 + 0x21) = iVar3;
    *(byte *)((longlong)param_5 + 0x11c) = *(byte *)(*(longlong *)(param_1 + 0x198) + 0x7a6) & 1;
    *(byte *)((longlong)param_5 + 0x11d) =
         (byte)(*(uint *)(*(longlong *)(param_1 + 0x198) + 0x7e8) >> 0xf) & 1;
    *(byte *)((longlong)param_5 + 0x11e) =
         (byte)((ushort)*(undefined2 *)(*(longlong *)(param_1 + 0x198) + 0x7fc) >> 9) & 1;
    *(undefined1 *)(param_1 + 0xedc0) = 1;
    *(undefined8 **)
     (*(longlong *)(param_1 + 0x208) + (ulonglong)*(uint *)((longlong)param_5 + 0x14) * 8) = param_5
    ;
    *(undefined4 *)((longlong)param_5 + 0x7c) = 0x200;
    **(undefined1 **)(param_1 + 0xe4a0) = 1;
    *(undefined4 *)(*(longlong *)(param_1 + 0xe4a0) + 4) = 0xb4;
    if (*(char *)(param_1 + 0xe46e) == '\0') {
      Fusion_FireRequest_MFI(param_1,(longlong)param_5);
      *piVar1 = 0x1a;
      return;
    }
    Fusion_FireRequest_MFIAtomic(param_1,(longlong)param_5);
    *piVar1 = 0x1a;
    return;
  case 0x11:
    *(undefined1 *)(param_1 + 0xedc0) = 0;
    iVar3 = *(int *)(param_1 + 0xd7fc) + -1;
    *(int *)((longlong)param_5 + 0x14) = iVar3;
    *(undefined1 *)(param_5 + 0x20) = 5;
    *(undefined4 *)(param_5 + 0x23) = 0x10f0400;
    *(undefined1 *)((longlong)param_5 + 0x102) = 0xff;
    *(int *)(param_5 + 0x21) = iVar3;
    *(undefined8 **)
     (*(longlong *)(param_1 + 0x208) + (ulonglong)*(uint *)((longlong)param_5 + 0x14) * 8) = param_5
    ;
    *(undefined4 *)((longlong)param_5 + 0x7c) = 0x200;
    if (*(char *)(param_1 + 0xe46e) == '\0') {
      Fusion_FireRequest_MFI(param_1,(longlong)param_5);
      *(undefined4 *)(lVar5 + 0x18) = 0;
      *piVar1 = 0x12;
      return;
    }
    Fusion_FireRequest_MFIAtomic(param_1,(longlong)param_5);
    *(undefined4 *)(lVar5 + 0x18) = 0;
    *piVar1 = 0x12;
    return;
  case 0x12:
    if (param_3 == 0) goto LAB_1400108b4;
    piVar8 = (int *)(param_3 + 2);
    if (*(char *)(param_3 + 2) == '\0') {
      *(undefined1 *)((longlong)param_5 + 0x81) = 1;
      *(undefined4 *)((longlong)param_5 + 0x7c) = 0;
      *piVar1 = 0x14;
    }
    else {
      *piVar1 = 0x14;
      *(undefined4 *)((longlong)param_5 + 0x7c) = 0;
      *(undefined1 *)((longlong)param_5 + 0x81) = 1;
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x296) != 0)) {
        uVar6 = 0x296;
        uVar9 = 1;
        goto LAB_14000ffe0;
      }
    }
    goto LAB_140010000;
  case 0x14:
    local_50 = *(undefined4 *)(lVar5 + 0x10);
    local_4c = *(undefined4 *)(lVar5 + 0x14);
    local_48 = *(undefined1 *)(lVar2 + 3);
    if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x40001e) != 0)) {
      RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x40001e,
                  (undefined1 *)&local_58,0x11,param_4,param_6);
    }
    if (*(char *)((longlong)param_5 + 0x81) != '\0') {
      *(undefined2 *)((longlong)param_5 + 0x81) = 0;
      StorPortNotification(0,param_1,lVar2);
      *(undefined8 *)(param_1 + 0xedc8) = 0;
    }
    *(undefined1 *)(param_1 + 0xedc0) = 0;
    *piVar1 = 0;
    return;
  case 0x15:
    if (*(int *)(param_1 + 0xedb0) != 0) {
      iVar3 = *(int *)(param_1 + 0xd7fc) + -1;
      *(int *)((longlong)param_5 + 0x14) = iVar3;
      *(undefined1 *)(param_5 + 0x20) = 5;
      *(undefined4 *)(param_5 + 0x23) = 0x10f0100;
      *(undefined1 *)((longlong)param_5 + 0x102) = 0xff;
      *(int *)(param_5 + 0x21) = iVar3;
      *(undefined4 *)((longlong)param_5 + 0x11c) = *(undefined4 *)(param_1 + 0xedb0);
      *(undefined8 **)
       (*(longlong *)(param_1 + 0x208) + (ulonglong)*(uint *)((longlong)param_5 + 0x14) * 8) =
           param_5;
      *(undefined4 *)((longlong)param_5 + 0x7c) = 0x200;
      **(undefined1 **)(param_1 + 0xe490) = 1;
      *(undefined4 *)(*(longlong *)(param_1 + 0xe490) + 4) = 0xb4;
      if (*(char *)(param_1 + 0xe46e) == '\0') {
        Fusion_FireRequest_MFI(param_1,(longlong)param_5);
        *piVar1 = 0x16;
        return;
      }
      Fusion_FireRequest_MFIAtomic(param_1,(longlong)param_5);
      *piVar1 = 0x16;
      return;
    }
    *(undefined4 *)(lVar2 + 0x10) = 0x1c;
    *(undefined1 *)(lVar2 + 3) = 1;
    *(undefined4 *)(lVar5 + 0x14) = 7;
    if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x299) != 0)) {
      uVar6 = 0x299;
LAB_140010661:
      uVar9 = 0;
      puVar7 = (undefined4 *)0x0;
LAB_140010675:
      RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),uVar6,(undefined1 *)puVar7,
                  uVar9,param_4,param_6);
    }
    break;
  case 0x16:
    if (param_3 == 0) goto LAB_1400108b4;
    puVar7 = (undefined4 *)(param_3 + 2);
    if (*(char *)(param_3 + 2) == '\0') {
      *(undefined4 *)((longlong)param_5 + 0x7c) = 0;
      *piVar1 = 0xd;
      **(undefined1 **)(param_1 + 0xe490) = 0;
      goto LAB_140010000;
    }
    if (*(char *)(param_3 + 2) == -1) {
      return;
    }
    *(undefined4 *)(lVar2 + 0x10) = 0x1c;
    *(undefined1 *)(lVar2 + 3) = 1;
    *(undefined4 *)(lVar5 + 0x14) = 0x10;
    *(undefined1 *)(param_1 + 0xedae) = 0;
    *(undefined4 *)((longlong)param_5 + 0x7c) = 0;
    **(undefined1 **)(param_1 + 0xe490) = 0;
    if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x293) != 0)) {
      uVar6 = 0x293;
      uVar9 = 1;
      goto LAB_140010675;
    }
    break;
  case 0x17:
    iVar3 = *(int *)(param_1 + 0xd7fc) + -1;
    *(int *)((longlong)param_5 + 0x14) = iVar3;
    *(int *)(param_5 + 0x21) = iVar3;
    *(undefined1 *)(param_5 + 0x20) = 5;
    *(undefined4 *)(param_5 + 0x23) = 0x10f0200;
    *(undefined1 *)((longlong)param_5 + 0x102) = 0xff;
    *(undefined4 *)((longlong)param_5 + 0x11c) = *(undefined4 *)(lVar5 + 0x40);
    *(undefined4 *)((longlong)param_5 + 0x114) = *(undefined4 *)(lVar5 + 0x48);
    param_5[0xc] = param_5 + 0x25;
    param_5[0xb] = param_5 + 0x25;
    lVar5 = BuildSGLforIOCTL(param_1,param_5,lVar5 + 0x58,*(uint *)(lVar5 + 0x48));
    if ((char)lVar5 == '\0') {
      *(undefined1 *)(lVar2 + 3) = 0x12;
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x298) != 0)) {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x298,(undefined1 *)0x0,0,
                    param_4,param_6);
      }
      *piVar1 = 0x14;
      *(undefined1 *)((longlong)param_5 + 0x81) = 1;
      return;
    }
    *(ushort *)(param_5 + 0x22) =
         -(ushort)(*(char *)((longlong)param_5 + 0x34) != '\0') & 2 |
         *(ushort *)(param_5 + 0x22) & 0xfffd;
    *(undefined1 *)((longlong)param_5 + 0x107) = *(undefined1 *)(param_5 + 10);
    *(undefined8 **)
     (*(longlong *)(param_1 + 0x208) + (ulonglong)*(uint *)((longlong)param_5 + 0x14) * 8) = param_5
    ;
    *(undefined4 *)((longlong)param_5 + 0x7c) = 0x200;
    **(undefined1 **)(param_1 + 0xe498) = 1;
    *(undefined4 *)(*(longlong *)(param_1 + 0xe498) + 4) = 0xb4;
    if (*(char *)(param_1 + 0xe46e) == '\0') {
      Fusion_FireRequest_MFI(param_1,(longlong)param_5);
      *piVar1 = 0x18;
      return;
    }
    Fusion_FireRequest_MFIAtomic(param_1,(longlong)param_5);
    *piVar1 = 0x18;
    return;
  case 0x18:
    if (param_3 == 0) goto LAB_1400108b4;
    if (*(char *)(param_3 + 2) == '\0') {
      **(undefined1 **)(param_1 + 0xe498) = 0;
      *(undefined4 *)((longlong)param_5 + 0x7c) = 0;
      *(undefined1 *)((longlong)param_5 + 0x81) = 1;
      *(undefined1 *)(lVar2 + 3) = 1;
      *(undefined4 *)(lVar5 + 0x14) = 0;
      *piVar1 = 0x14;
    }
    else {
      if (*(char *)(param_3 + 2) == -1) {
        return;
      }
      *(undefined4 *)(lVar2 + 0x10) = 0x1c;
      *(undefined1 *)(lVar2 + 3) = 1;
      *(undefined4 *)(lVar5 + 0x14) = 0x10;
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x294) != 0)) {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x294,
                    (undefined1 *)(param_3 + 2),1,param_4,param_6);
      }
      *(undefined1 *)(param_1 + 0xedae) = 0;
      *(undefined4 *)((longlong)param_5 + 0x7c) = 0;
      **(undefined1 **)(param_1 + 0xe498) = 0;
      *(undefined1 *)((longlong)param_5 + 0x81) = 1;
      *piVar1 = 0x14;
    }
    goto LAB_140010000;
  case 0x1a:
    if (param_3 == 0) goto LAB_1400108b4;
    if (*(char *)(param_3 + 2) == '\0') {
      *(undefined4 *)((longlong)param_5 + 0x7c) = 0;
      *(undefined1 *)((longlong)param_5 + 0x81) = 1;
      **(undefined1 **)(param_1 + 0xe4a0) = 0;
      *piVar1 = 0x14;
      *(undefined4 *)(lVar2 + 0x10) = 0;
      *(undefined1 *)(lVar2 + 3) = 1;
      *(undefined4 *)(lVar5 + 0x14) = 0;
      return;
    }
    if (*(char *)(param_3 + 2) == -1) {
      return;
    }
    *(undefined4 *)((longlong)param_5 + 0x7c) = 0;
    **(undefined1 **)(param_1 + 0xe4a0) = 0;
    *(undefined4 *)(lVar2 + 0x10) = 0x1c;
    *(undefined1 *)(lVar2 + 3) = 1;
    *(undefined4 *)(lVar5 + 0x14) = 0x10;
    if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x295) != 0)) {
      RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x295,
                  (undefined1 *)(param_3 + 2),1,param_4,param_6);
    }
    *(undefined1 *)(param_1 + 0xedae) = 0;
    DoResumeInput(param_1,param_6,param_4);
    *piVar1 = 0x11;
    goto LAB_140010000;
  case 0x1c:
    *(undefined1 *)(lVar2 + 3) = 1;
    *(undefined4 *)(lVar5 + 0x14) = 1;
    if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x400081) != 0)) {
      RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x400081,(undefined1 *)0x0,0,
                  param_4,param_6);
    }
    *piVar1 = 0x14;
    *(undefined1 *)((longlong)param_5 + 0x81) = 1;
    goto LAB_140010000;
  }
  *piVar1 = 0x14;
  goto LAB_140010000;
LAB_1400108b4:
  *piVar1 = 0x14;
  *(undefined4 *)((longlong)param_5 + 0x7c) = 0;
  *(undefined1 *)((longlong)param_5 + 0x81) = 1;
  if ((*(char *)(param_1 + 0xeb50) == '\0') || ((*(uint *)(param_1 + 0xeb54) & 0x29a) == 0))
  goto LAB_140010000;
  uVar6 = 0x29a;
  uVar9 = 0;
  piVar8 = (int *)0x0;
  goto LAB_14000ffe0;
}



===== BusyThisRequest @ 140010e40 =====

void BusyThisRequest(longlong param_1,longlong *param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  int *piVar5;
  longlong lVar6;
  undefined1 local_res8;
  undefined1 local_res9;
  undefined1 local_resa;
  int local_resc;
  
  lVar3 = *param_2;
  lVar4 = param_2[3];
  if (*(char *)(param_1 + 0x91) == '\0') {
    StorPortBusy(param_1,*(undefined4 *)(param_1 + 0x9228));
  }
  else {
    *(undefined1 *)(lVar3 + 4) = 0x28;
  }
  *(undefined1 *)(lVar3 + 3) = 5;
  piVar5 = (int *)(param_1 + 0x92e0);
  local_resc = 0;
  lVar6 = 0xff;
  do {
    piVar1 = piVar5 + 0x800;
    iVar2 = *piVar5;
    piVar5 = piVar5 + 8;
    local_resc = local_resc + *piVar1 + iVar2;
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  local_res9 = *(undefined1 *)(lVar3 + 5);
  local_res8 = *(undefined1 *)(lVar3 + 6);
  local_resa = *(undefined1 *)(lVar3 + 0x48);
  if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x2a9) != 0)) {
    RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x2a9,&local_res8,8,(char)lVar4,
                param_3);
  }
  StorPortNotification(0,param_1,lVar3);
  return;
}



===== DidGroupAndNotFull @ 140010f40 =====

ulonglong DidGroupAndNotFull(longlong param_1,longlong *param_2,ulonglong *param_3,longlong param_4,
                            undefined1 *param_5,undefined1 *param_6,undefined1 param_7)

{
  byte *pbVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  ulonglong uVar12;
  uint uVar13;
  
  uVar5 = param_3[1];
  if ((*(char *)((longlong)param_2 + 0xf) == '\0') ||
     (*(uint *)(param_4 + 0x20) < *(uint *)(param_1 + 0xd82c))) {
    *param_3 = (ulonglong)*(uint *)(param_2 + 9) + param_2[7];
    *param_5 = 0;
    return (ulonglong)param_5 & 0xffffffffffffff00;
  }
  uVar13 = *(uint *)(param_2 + 9);
  uVar12 = (ulonglong)uVar13;
  bVar2 = *(byte *)(param_4 + 10);
  if ((uint)(1 << (bVar2 & 0x1f)) <= uVar13) {
    *param_3 = (ulonglong)uVar13 + param_2[7];
    *param_5 = 0;
    return (ulonglong)param_5 & 0xffffffffffffff00;
  }
  uVar6 = param_2[7];
  if (0x3ffff < *(uint *)(*param_2 + 0x10)) {
    *param_3 = uVar6 + uVar12;
    *param_5 = 0;
    return (ulonglong)param_5 & 0xffffffffffffff00;
  }
  if (*param_3 == uVar6) {
    if (uVar5 == 0) {
      *param_3 = uVar6 + uVar12;
      *(undefined1 *)((longlong)param_2 + 0x11) = 1;
      *param_6 = 1;
      *(undefined1 *)((longlong)param_2 + 0x74) = param_7;
      param_3[2] = (ulonglong)param_2;
      param_3[1] = (ulonglong)param_2;
      *(undefined4 *)((longlong)param_2 + 0x4c) = *(undefined4 *)(*param_2 + 0x10);
      *(undefined1 *)((longlong)param_2 + 0x83) = 1;
      uVar12 = *param_3;
      *(undefined1 *)((longlong)param_3 + 0x1f) = 1;
    }
    else {
      if (((((uint)*(ushort *)(param_1 + 0xd7f4) <
             (uint)*(ushort *)(uVar5 + 0x50) + (uint)*(ushort *)(param_2 + 10)) ||
           (*(char *)(uVar5 + 0x19) != *(char *)((longlong)param_2 + 0x19))) ||
          (0x40000 < *(uint *)(*param_2 + 0x10) + *(int *)(uVar5 + 0x4c))) ||
         ((*(ulonglong *)(uVar5 + 0x38) >> (bVar2 & 0x3f) != (uVar6 - 1) + uVar12 >> (bVar2 & 0x3f)
          || (*(char *)(uVar5 + 0xa4) != *(char *)((longlong)param_2 + 0xa4))))) goto LAB_1400111cd;
      *(longlong **)(param_3[2] + 0x88) = param_2;
      *(char *)((longlong)param_3 + 0x1f) = *(char *)((longlong)param_3 + 0x1f) + '\x01';
      param_3[2] = (ulonglong)param_2;
      pbVar1 = (byte *)((*(longlong *)(uVar5 + 0x60) - (ulonglong)*(byte *)(uVar5 + 0x52)) + 0xf);
      *pbVar1 = *pbVar1 & 0xbf;
      uVar13 = (uint)*(ushort *)(param_2 + 10);
      puVar7 = (undefined8 *)param_2[0xd];
      puVar8 = *(undefined8 **)(uVar5 + 0x68);
      puVar11 = (undefined8 *)param_2[0xb];
      puVar10 = *(undefined8 **)(uVar5 + 0x60);
      if (*(ushort *)(param_2 + 10) != 0) {
        do {
          puVar9 = puVar10 + 2;
          if (puVar10 != puVar8) {
            puVar9 = puVar10;
          }
          puVar10 = puVar11 + 2;
          if (puVar11 != puVar7) {
            puVar10 = puVar11;
          }
          *puVar9 = *puVar10;
          puVar11 = puVar10 + 2;
          puVar9[1] = puVar10[1];
          puVar10 = puVar9 + 2;
          uVar13 = uVar13 - 1;
        } while (uVar13 != 0);
      }
      *(undefined8 **)(uVar5 + 0x60) = puVar10;
      *(int *)(uVar5 + 0x48) = *(int *)(uVar5 + 0x48) + (int)param_2[9];
      *(short *)(uVar5 + 0x50) = *(short *)(uVar5 + 0x50) + (short)param_2[10];
      iVar4 = *(int *)(*param_2 + 0x10);
      *(char *)(uVar5 + 0x83) = *(char *)(uVar5 + 0x83) + '\x01';
      *(int *)(uVar5 + 0x4c) = *(int *)(uVar5 + 0x4c) + iVar4;
      *(undefined1 *)((longlong)param_2 + 0x11) = 1;
      *param_6 = 1;
      uVar12 = (ulonglong)*(uint *)(param_2 + 9) + param_2[7];
      *(undefined1 *)((longlong)param_2 + 0x74) = param_7;
      *param_3 = uVar12;
      param_5 = (undefined1 *)0x0;
      if (*(uint *)(param_1 + 0xd828) <= (uint)*(byte *)(uVar5 + 0x83)) goto LAB_1400111d8;
    }
    uVar5 = param_3[1];
    param_5 = (undefined1 *)(*(ulonglong *)(uVar5 + 0x38) >> (*(byte *)(param_4 + 10) & 0x3f));
    if ((param_5 == (undefined1 *)(uVar12 >> (*(byte *)(param_4 + 10) & 0x3f))) &&
       (*(int *)(uVar5 + 0x4c) != 0x40000)) {
      uVar3 = *(ushort *)(param_1 + 0xd7f4);
      param_5 = (undefined1 *)(ulonglong)uVar3;
      if (*(ushort *)(uVar5 + 0x50) != uVar3) {
        return CONCAT71((uint7)(byte)(uVar3 >> 8),1);
      }
    }
  }
  else {
LAB_1400111cd:
    *param_3 = uVar6;
    *param_5 = 1;
  }
LAB_1400111d8:
  return (ulonglong)param_5 & 0xffffffffffffff00;
}



===== DoPauseInput @ 1400111f0 =====

void DoPauseInput(longlong param_1,undefined4 param_2,undefined1 param_3)

{
  if (((*(uint *)(param_1 + 0xe45c) & 1) == 0) && (*(char *)(param_1 + 0x89) == '\0')) {
    *(uint *)(param_1 + 0xe45c) = *(uint *)(param_1 + 0xe45c) | 1;
    StorPortPause(param_1,0xe10);
    if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x111) != 0)) {
      RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x111,(undefined1 *)0x0,0,
                  param_3,param_2);
    }
  }
  return;
}



===== DoResumeInput @ 140011290 =====

void DoResumeInput(longlong param_1,undefined4 param_2,undefined1 param_3)

{
  if (((*(uint *)(param_1 + 0xe45c) & 1) != 0) && (*(char *)(param_1 + 0x89) == '\0')) {
    *(uint *)(param_1 + 0xe45c) = *(uint *)(param_1 + 0xe45c) & 0xfffffffe;
    StorPortResume();
    StorPortReady(param_1);
    if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x112) != 0)) {
      RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x112,(undefined1 *)0x0,0,
                  param_3,param_2);
    }
  }
  return;
}



===== IssueTaskManagement @ 140011330 =====

void IssueTaskManagement(longlong param_1)

{
  longlong lVar1;
  byte bVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined4 uVar7;
  byte bVar8;
  bool bVar9;
  
  bVar2 = *(byte *)(param_1 + 0xe7e0);
  lVar1 = param_1 + (ulonglong)bVar2 * 8;
  lVar6 = *(longlong *)(lVar1 + 0xe4c0);
  if (lVar6 == 0) {
    *(undefined4 *)(param_1 + 0xe4b0) = 0;
    if (*(char *)(param_1 + 0xeb50) == '\0') {
      return;
    }
    if ((*(uint *)(param_1 + 0xeb54) & 0x20088) == 0) {
      return;
    }
    RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x20088,(undefined1 *)0x0,0,0,
                0x12);
    return;
  }
  *(undefined8 *)(lVar1 + 0xe4c0) = 0;
  bVar8 = 0;
  if (bVar2 != 99) {
    bVar8 = bVar2 + 1;
  }
  *(byte *)(param_1 + 0xe7e0) = bVar8;
  plVar5 = (longlong *)(*(longlong *)(lVar6 + 0x38) + 0x100U & 0xfffffffffffffeff);
  if (plVar5 == (longlong *)0x0) {
    SetDeadAdapter(param_1,6,0x12,0);
    return;
  }
  *(undefined1 *)(plVar5 + 3) = 0;
  *(undefined1 *)((longlong)plVar5 + 0xa5) = 0;
  if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x20089) != 0)) {
    RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x20089,(undefined1 *)(lVar6 + 2)
                ,1,0,0x12);
  }
  if (*(char *)(param_1 + 0xd911) == '\0') {
    if (*(char *)(param_1 + 0xd90f) == '\0') {
      if (*(char *)(param_1 + 0xd90c) == '\0') {
        if (*(char *)(param_1 + 0xd910) == '\0') {
          uVar3 = MPT_BuildTaskMgmt_Scsi(param_1,plVar5);
          if ((char)uVar3 == '\0') {
            *(undefined1 *)(lVar6 + 3) = 4;
            StorPortNotification(0,param_1,lVar6);
            return;
          }
          if ((short)plVar5[0x20] != -1) {
            *(longlong *)(param_1 + 0xe4b8) = lVar6;
            *(undefined4 *)(param_1 + 0xe4b0) = 1;
            uVar3 = SendRequestIfNotBusy(param_1,plVar5);
            if ((char)uVar3 == '\0') {
              BusyThisRequest(param_1,plVar5,0x12);
            }
            CheckTMCmdTimeout(param_1,0x12,0);
            return;
          }
          *(undefined1 *)(lVar6 + 3) = 4;
          if ((*(char *)(param_1 + 0xeb50) != '\0') &&
             ((*(uint *)(param_1 + 0xeb54) & 0x20090) != 0)) {
            RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x20090,(undefined1 *)0x0
                        ,0,0,0x12);
          }
          StorPortNotification(0,param_1,lVar6);
          return;
        }
        uVar4 = 4;
        if ((*(char *)(param_1 + 0xeb50) == '\0') || ((*(uint *)(param_1 + 0xeb54) & 0x2008d) == 0))
        goto LAB_140011552;
        uVar7 = 0x2008d;
      }
      else {
        uVar4 = 1;
        if ((*(char *)(param_1 + 0xeb50) == '\0') || ((*(uint *)(param_1 + 0xeb54) & 0x2008c) == 0))
        goto LAB_140011552;
        uVar7 = 0x2008c;
      }
    }
    else {
      uVar4 = 1;
      if ((*(char *)(param_1 + 0xeb50) == '\0') || ((*(uint *)(param_1 + 0xeb54) & 0x2008b) == 0))
      goto LAB_140011552;
      uVar7 = 0x2008b;
    }
  }
  else {
    uVar4 = 4;
    if ((*(char *)(param_1 + 0xeb50) == '\0') || ((*(uint *)(param_1 + 0xeb54) & 0x2008a) == 0))
    goto LAB_140011552;
    uVar7 = 0x2008a;
  }
  RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),uVar7,(undefined1 *)0x0,0,0,0x12);
LAB_140011552:
  do {
    *(undefined1 *)(lVar6 + 3) = uVar4;
    StorPortNotification(0,param_1,lVar6);
    bVar9 = bVar8 != 99;
    lVar6 = *(longlong *)(param_1 + 0xe4c0 + (ulonglong)bVar8 * 8);
    bVar2 = bVar8 + 1;
    bVar8 = 0;
    if (bVar9) {
      bVar8 = bVar2;
    }
    *(byte *)(param_1 + 0xe7e0) = bVar8;
  } while (lVar6 != 0);
  *(undefined4 *)(param_1 + 0xe4b0) = 0;
  return;
}



===== MegaSASStartIo @ 140011680 =====

undefined8 MegaSASStartIo(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  ushort uVar2;
  longlong *plVar3;
  longlong lVar4;
  bool bVar5;
  uint uVar6;
  undefined8 uVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  ulonglong uVar10;
  byte bVar11;
  char cVar12;
  ulonglong uVar13;
  byte bVar14;
  undefined4 uVar15;
  longlong *plVar16;
  byte local_res8;
  byte local_res9;
  byte local_res10;
  byte local_res11;
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  
  plVar16 = (longlong *)(*(longlong *)(param_2 + 0x38) + 0x100U & 0xfffffffffffffeff);
  uVar1 = (undefined1)plVar16[3];
  if (*(char *)(param_1 + 0xe1a0) == '\x01') {
    SetDeviceQueueDepths(param_1,4,uVar1);
    *(undefined1 *)(param_1 + 0xe1a0) = 0;
  }
  switch(*(undefined1 *)(param_2 + 2)) {
  case 0:
    if ((*(char *)((longlong)plVar16 + 0xf) != '\0') &&
       (uVar10 = StreamDetect(param_1,plVar16), (char)uVar10 != '\0')) goto LAB_140011cbf;
    break;
  default:
    goto switchD_1400116f3_caseD_1;
  case 2:
    if (*(int *)(*(longlong *)(param_2 + 0x18) + 0x10) == 0x1b0780) {
      uVar10 = HbaFwUpgrade(param_1,param_2);
      goto LAB_140011cbf;
    }
    break;
  case 8:
    break;
  case 0x13:
  case 0x20:
    if ((*(char *)(param_1 + 0xd90c) != '\0') || (*(char *)(param_1 + 0xd90f) != '\0')) {
      *(undefined1 *)(param_2 + 3) = 1;
      uVar10 = StorPortNotification(0,param_1,param_2);
      if ((*(char *)(param_1 + 0xeb50) != '\0') &&
         (uVar10 = (ulonglong)*(uint *)(param_1 + 0xeb54),
         (*(uint *)(param_1 + 0xeb54) & 0x2008f) != 0)) {
        uVar10 = RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x2008f,
                             (undefined1 *)0x0,0,uVar1,4);
      }
      goto LAB_140011cbf;
    }
    if (*(char *)(param_2 + 5) == '\x01') {
      lVar4 = *(longlong *)(param_1 + 0xd930 + (ulonglong)(*(uint *)(plVar16 + 0x17) & 1) * 8);
      if (lVar4 == 0) goto LAB_140011c47;
      local_res8 = *(byte *)(param_2 + 6);
      uVar10 = *(ulonglong *)(lVar4 + 0x40);
      uVar2 = *(ushort *)(uVar10 + (ulonglong)local_res8 * 2);
      if (uVar2 < *(ushort *)(param_1 + 0xe462)) {
        uVar10 = *(ulonglong *)(lVar4 + 0x50);
        bVar11 = (byte)((uint)*(undefined4 *)((ulonglong)uVar2 * 0x9e0 + uVar10) >> 0x19) & 1;
      }
      else {
        bVar11 = 0;
      }
      local_res9 = bVar11;
      if ((*(char *)(param_1 + 0xeb50) != '\0') &&
         (uVar10 = (ulonglong)*(uint *)(param_1 + 0xeb54),
         (*(uint *)(param_1 + 0xeb54) & 0x20080) != 0)) {
        pbVar8 = &local_res8;
        uVar15 = 0x20080;
LAB_140011a2f:
        uVar10 = RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),uVar15,pbVar8,2,
                             uVar1,4);
      }
LAB_140011a5f:
      if ((bVar11 == 0) || (*(char *)(param_1 + 0xd90f) != '\0')) goto LAB_140011bfb;
      lVar4 = *plVar16;
      *(undefined1 *)(plVar16 + 3) = 0;
      *(undefined1 *)((longlong)plVar16 + 0xa5) = 0;
      if (lVar4 == *(longlong *)(param_1 + 0xe4b8)) goto LAB_140011cbf;
      uVar10 = 0;
      do {
        if (*(longlong *)(param_1 + 0xe4c0 + uVar10 * 8) == lVar4) {
          if ((*(int *)(param_1 + 0xe4b0) != 0) ||
             (*(undefined1 *)(param_1 + 0xd8e9) = 1, *(char *)(param_1 + 0x89) != '\0'))
          goto LAB_140011cbf;
          puVar9 = local_res20;
          local_res20[0] = 0;
          goto LAB_140011b11;
        }
        bVar11 = (char)uVar10 + 1;
        uVar10 = (ulonglong)bVar11;
      } while (bVar11 < 100);
      bVar11 = *(byte *)(param_1 + 0xe7e1);
      if (*(longlong *)(param_1 + 0xe4c0 + (ulonglong)bVar11 * 8) == 0) {
        *(longlong *)(param_1 + 0xe4c0 + (ulonglong)bVar11 * 8) = lVar4;
        uVar10 = 0;
        cVar12 = '\0';
        if (bVar11 != 99) {
          cVar12 = bVar11 + 1;
        }
        *(char *)(param_1 + 0xe7e1) = cVar12;
        if ((*(int *)(param_1 + 0xe4b0) == 0) &&
           (*(undefined1 *)(param_1 + 0xd8e9) = 1, *(char *)(param_1 + 0x89) == '\0')) {
          local_res18[0] = 0;
          puVar9 = local_res18;
LAB_140011b11:
          uVar10 = StorPortNotification(0x1002,param_1,param_1 + 0xd888,param_1,param_1,puVar9);
        }
        goto LAB_140011cbf;
      }
      if (*(char *)(param_1 + 0x91) == '\0') {
        StorPortBusy(param_1,*(undefined4 *)(param_1 + 0x9228));
      }
      else {
        *(undefined1 *)(lVar4 + 4) = 0x28;
      }
      *(undefined1 *)(lVar4 + 3) = 5;
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x20082) != 0)) {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x20082,
                    (undefined1 *)(param_2 + 6),1,uVar1,4);
      }
    }
    else {
      uVar13 = (ulonglong)*(byte *)(param_2 + 6);
      if (*(char *)(uVar13 + 0xd30a + param_1) != '\0') {
        uVar6 = *(int *)(param_1 + 0xd954) - 1;
        uVar10 = (ulonglong)uVar6;
        if (uVar6 != *(uint *)((longlong)plVar16 + 0xbc)) {
          *(uint *)((longlong)plVar16 + 0xbc) = uVar6;
          uVar13 = (ulonglong)*(byte *)(param_2 + 6);
        }
        local_res10 = (byte)uVar13;
        if ((((*(char *)(param_1 + 0xe46c) == '\0') && (*(char *)(param_1 + 0xe45a) == '\0')) ||
            (*(char *)(uVar13 + 0xd50a + param_1) == '\0')) || (*(char *)(param_1 + 0x89) != '\0'))
        {
          bVar11 = 0;
        }
        else {
          uVar10 = *(ulonglong *)(param_1 + 0xd958 + (ulonglong)(uVar6 & 1) * 8);
          bVar11 = *(byte *)(uVar10 + 0xc + uVar13 * 8) & 1;
        }
        local_res11 = bVar11;
        if ((*(char *)(param_1 + 0xeb50) != '\0') &&
           (uVar10 = (ulonglong)*(uint *)(param_1 + 0xeb54),
           (*(uint *)(param_1 + 0xeb54) & 0x20081) != 0)) {
          pbVar8 = &local_res10;
          uVar15 = 0x20081;
          goto LAB_140011a2f;
        }
        goto LAB_140011a5f;
      }
      *(undefined1 *)(param_2 + 3) = 6;
      StorPortNotification(0,param_1,param_2);
LAB_140011bfb:
      if ((*(char *)(param_1 + 0xeb50) != '\0') && ((*(uint *)(param_1 + 0xeb54) & 0x20083) != 0)) {
        RttLogEvent(param_1,param_1 + 0xeb00,(int *)(param_1 + 0xeb18),0x20083,
                    (undefined1 *)(param_2 + 6),1,uVar1,4);
      }
LAB_140011c47:
      *(undefined1 *)(param_2 + 3) = 6;
    }
    goto LAB_140011cb2;
  case 0x17:
    uVar10 = MegaSASWmiSrb(param_1,param_2);
    goto LAB_140011cbf;
  case 0x24:
    if (*(int *)(param_2 + 0x40) - 4U < 3) {
      *(undefined1 *)(param_1 + 0xd307) = 1;
    }
    if (*(int *)(param_2 + 8) == 4) {
      StopAllTimerRoutine(param_1);
      Fusion_DisableInterrupt(param_1);
      *(uint *)(param_1 + 0xd810) = *(uint *)(param_1 + 0xd810) | 0x10;
      *(undefined1 *)(param_1 + 0xd910) = 1;
      *(undefined4 *)(param_1 + 0xe43c) = 1;
      *(longlong *)(param_1 + 0xe450) = param_2;
      uVar10 = WatchDogTimer(param_1);
      goto LAB_140011cbf;
    }
    goto switchD_1400116f3_caseD_1;
  }
  plVar3 = *(longlong **)(param_1 + 0x9220);
  if (plVar3 != (longlong *)0x0) {
    *(undefined8 *)(param_1 + 0x9220) = 0;
    uVar7 = SendRequestIfNotBusy(param_1,plVar3);
    if ((char)uVar7 == '\0') {
      *(longlong **)(param_1 + 0x9220) = plVar3;
    }
  }
  if (*(char *)(param_1 + 0xd830) != '\0') {
    bVar11 = *(byte *)(param_1 + 0xd814);
    bVar5 = true;
    if (*(char *)(param_1 + 0x89) == '\0') {
      do {
        uVar10 = 0;
        do {
          lVar4 = (ulonglong)bVar11 * 0x180 + uVar10 * 0x28;
          if ((((*(char *)(lVar4 + 0x48 + *(longlong *)(param_1 + 0xd818)) != '\0') ||
               (*(int *)((ulonglong)bVar11 * 0x180 + 0x20 + *(longlong *)(param_1 + 0xd818)) == 0))
              && (plVar3 = *(longlong **)(lVar4 + 0x30 + *(longlong *)(param_1 + 0xd818)),
                 plVar3 != (longlong *)0x0)) &&
             (uVar7 = SendRequestIfNotBusy(param_1,plVar3), (char)uVar7 == '\0')) {
            bVar5 = false;
            break;
          }
          bVar14 = (char)uVar10 + 1;
          uVar10 = (ulonglong)bVar14;
        } while (bVar14 < 8);
        bVar14 = bVar11 + 1;
        bVar11 = 0;
        if ((ushort)bVar14 < *(ushort *)(param_1 + 0xd308)) {
          bVar11 = bVar14;
        }
      } while (bVar11 != *(byte *)(param_1 + 0xd814));
      if (bVar5) {
        *(undefined1 *)(param_1 + 0xd830) = 0;
        *(undefined1 *)(param_1 + 0xd814) = 0;
      }
      else {
        *(byte *)(param_1 + 0xd814) = bVar11;
        *(undefined1 *)(param_1 + 0xd8d0) = 1;
      }
    }
  }
  uVar10 = SendRequestIfNotBusy(param_1,plVar16);
  if ((char)uVar10 == '\0') {
    uVar10 = BusyThisRequest(param_1,plVar16,4);
  }
LAB_140011cbf:
  return CONCAT71((int7)(uVar10 >> 8),1);
switchD_1400116f3_caseD_1:
  *(undefined2 *)(param_2 + 3) = 1;
LAB_140011cb2:
  uVar10 = StorPortNotification(0,param_1,param_2);
  goto LAB_140011cbf;
}



===== SendRequestIfNotBusy @ 140011d20 =====

undefined8 SendRequestIfNotBusy(longlong param_1,longlong *param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  uint uVar7;
  int *piVar8;
  longlong lVar9;
  
  lVar4 = *param_2;
  piVar8 = (int *)(param_1 + 0x92e0);
  uVar7 = 0;
  lVar9 = 0xff;
  do {
    piVar1 = piVar8 + 0x800;
    iVar3 = *piVar8;
    piVar8 = piVar8 + 8;
    uVar7 = uVar7 + *piVar1 + iVar3;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  if (((*(uint *)(param_1 + 0xd804) <= uVar7) || (*(char *)(param_1 + 0xd90c) != '\0')) ||
     (*(char *)(param_1 + 0xd90f) != '\0')) {
    cVar2 = *(char *)(lVar4 + 2);
    uVar5 = 0;
    if ((cVar2 != '\x13') && (cVar2 != ' ')) {
      if ((cVar2 == '\x02') && (*(longlong *)(param_1 + 0x9220) == 0)) {
        *(longlong **)(param_1 + 0x9220) = param_2;
        *(undefined1 *)(param_1 + 0xd8d0) = 1;
        return 1;
      }
      goto LAB_140011dcb;
    }
  }
  uVar5 = MakeSRBExtension(param_1,(longlong)param_2);
  if ((char)uVar5 != '\0') {
    if (*(char *)((longlong)param_2 + 0xf) != '\0') {
      LOCK();
      piVar8 = (int *)((ulonglong)*(byte *)(lVar4 + 6) * 0x180 + 0x20 +
                      *(longlong *)(param_1 + 0xd818));
      *piVar8 = *piVar8 + 1;
      UNLOCK();
      if (*(char *)((longlong)param_2 + 0x11) != '\0') {
        lVar9 = (ulonglong)*(byte *)(lVar4 + 6) * 0x180 +
                (ulonglong)*(byte *)((longlong)param_2 + 0x74) * 0x28;
        if (*(longlong **)(lVar9 + 0x30 + *(longlong *)(param_1 + 0xd818)) == param_2) {
          *(undefined8 *)(lVar9 + 0x38 + *(longlong *)(param_1 + 0xd818)) = 0;
          *(undefined8 *)
           ((ulonglong)*(byte *)(lVar4 + 6) * 0x180 +
            (ulonglong)*(byte *)((longlong)param_2 + 0x74) * 0x28 + 0x30 +
           *(longlong *)(param_1 + 0xd818)) = 0;
          *(undefined1 *)
           ((ulonglong)*(byte *)(lVar4 + 6) * 0x180 +
            (ulonglong)*(byte *)((longlong)param_2 + 0x74) * 0x28 + 0x48 +
           *(longlong *)(param_1 + 0xd818)) = 0;
          *(undefined1 *)
           ((ulonglong)*(byte *)(lVar4 + 6) * 0x180 +
            (ulonglong)*(byte *)((longlong)param_2 + 0x74) * 0x28 + 0x47 +
           *(longlong *)(param_1 + 0xd818)) = 0;
        }
      }
    }
    if (((char)param_2[0x12] != '\0') && ((char)param_2[0x20] == '\x05')) {
      LOCK();
      *(int *)(param_1 + 0x92c0) = *(int *)(param_1 + 0x92c0) + 1;
      UNLOCK();
    }
    if ((*(char *)(lVar4 + 2) == '\x13') || (*(char *)(lVar4 + 2) == ' ')) {
      uVar6 = MPT_SendTaskMgmtToFW(param_1,param_2);
      return CONCAT71((int7)((ulonglong)uVar6 >> 8),1);
    }
    uVar6 = MPT_SendRequestToFW(param_1,param_2);
    return CONCAT71((int7)((ulonglong)uVar6 >> 8),1);
  }
LAB_140011dcb:
  return uVar5 & 0xffffffffffffff00;
}



===== StreamDetect @ 140011f10 =====

ulonglong StreamDetect(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  byte bVar7;
  ulonglong *puVar8;
  byte bVar9;
  byte bVar10;
  longlong lVar11;
  longlong lVar12;
  char local_res8 [8];
  char local_res10 [8];
  
  local_res10[0] = '\0';
  local_res8[0] = '\0';
  lVar11 = (ulonglong)*(byte *)(*param_2 + 6) * 0x180;
  lVar12 = *(longlong *)(param_1 + 0xd818) + lVar11;
  uVar4 = 0;
LAB_140011f50:
  bVar10 = (byte)uVar4;
  bVar9 = (byte)(*(uint *)(lVar12 + 4) >> ((byte)(uVar4 << 2) & 0x1f)) & 0xf;
  puVar8 = (ulonglong *)(*(longlong *)(param_1 + 0xd818) + ((ulonglong)bVar9 + 1) * 0x28 + lVar11);
  if ((((ulonglong)param_2[7] < *puVar8) || (*puVar8 + 0x20 < (ulonglong)param_2[7])) ||
     (*(char *)((longlong)puVar8 + 0x1e) != *(char *)(*param_2 + 0x48))) goto LAB_140011f9f;
  *(int *)(puVar8 + 3) = (int)puVar8[3] + 1;
  *(undefined1 *)((longlong)puVar8 + 0x21) = 0;
  *(ushort *)((longlong)param_2 + 0x17c) = *(ushort *)((longlong)param_2 + 0x17c) | 0x8000;
  if (bVar10 != 0) {
    uVar3 = *(uint *)(lVar12 + 4);
    bVar7 = (byte)(uVar4 << 2);
    uVar4 = (1 << (bVar7 & 0x1f)) - 1;
    *(uint *)(lVar12 + 4) =
         ~(0xf << (bVar7 & 0x1f) | uVar4) & uVar3 | (uVar3 & uVar4) << 4 |
         uVar3 >> (bVar7 & 0x1f) & 0xf;
  }
  while (bVar10 = bVar10 + 1, bVar10 < 8) {
    lVar1 = *(longlong *)(param_1 + 0xd818) +
            (ulonglong)(*(uint *)(lVar12 + 4) >> ((bVar10 & 7) << 2) & 0xf) * 0x28;
    if ((*(longlong *)(lVar1 + 0x30 + lVar11) != 0) &&
       (pcVar2 = (char *)(lVar1 + 0x49 + lVar11), *pcVar2 = *pcVar2 + '\x01',
       6 < *(byte *)(lVar1 + 0x49 + lVar11))) {
      *(undefined1 *)(lVar1 + 0x48 + lVar11) = 1;
      *(undefined1 *)(param_1 + 0xd830) = 1;
      *(undefined1 *)(param_1 + 0xd8d0) = 1;
    }
  }
  if (2 < (uint)puVar8[3]) {
    uVar6 = DidGroupAndNotFull(param_1,param_2,puVar8,*(longlong *)(param_1 + 0xd818) + lVar11,
                               local_res10,local_res8,bVar9);
    if ((char)uVar6 != '\0') goto LAB_1400121b2;
    if ((longlong *)puVar8[1] != (longlong *)0x0) {
      *(undefined1 *)(puVar8 + 4) = 1;
      uVar6 = SendRequestIfNotBusy(param_1,(longlong *)puVar8[1]);
      if ((char)uVar6 != '\0') {
        if (local_res8[0] != '\0') goto LAB_1400121b2;
        if (local_res10[0] == '\0') goto LAB_1400121a3;
        uVar6 = DidGroupAndNotFull(param_1,param_2,puVar8,*(longlong *)(param_1 + 0xd818) + lVar11,
                                   local_res10,local_res8,bVar9);
        if ((char)uVar6 != '\0') goto LAB_1400121b2;
      }
      if (local_res8[0] != '\0') {
LAB_1400121b2:
        return CONCAT71((int7)(uVar6 >> 8),1);
      }
    }
  }
  goto LAB_1400121a3;
LAB_140011f9f:
  if ((puVar8[1] != 0) &&
     (*(char *)((longlong)puVar8 + 0x21) = *(char *)((longlong)puVar8 + 0x21) + '\x01',
     6 < *(byte *)((longlong)puVar8 + 0x21))) {
    *(undefined1 *)(puVar8 + 4) = 1;
    *(undefined1 *)(param_1 + 0xd830) = 1;
    *(undefined1 *)(param_1 + 0xd8d0) = 1;
  }
  uVar4 = (uint)(byte)(bVar10 + 1);
  if (7 < (byte)(bVar10 + 1)) goto code_r0x000140011fca;
  goto LAB_140011f50;
code_r0x000140011fca:
  puVar8 = (ulonglong *)
           (lVar11 + ((ulonglong)(*(uint *)(lVar12 + 4) >> 0x1c) + 1) * 0x28 +
           *(longlong *)(param_1 + 0xd818));
  if ((longlong *)puVar8[1] != (longlong *)0x0) {
    *(undefined1 *)(puVar8 + 4) = 1;
    uVar5 = SendRequestIfNotBusy(param_1,(longlong *)puVar8[1]);
    if ((char)uVar5 == '\0') {
LAB_1400121a3:
      uVar6 = (ulonglong)*(uint *)(param_2 + 9) + param_2[7];
      *puVar8 = uVar6;
      goto LAB_140012032;
    }
  }
  *(undefined1 *)((longlong)puVar8 + 0x1f) = 0;
  *(undefined4 *)(puVar8 + 3) = 1;
  *(undefined1 *)((longlong)puVar8 + 0x21) = 0;
  *(undefined1 *)((longlong)puVar8 + 0x1e) = *(undefined1 *)(*param_2 + 0x48);
  *puVar8 = (ulonglong)*(uint *)(param_2 + 9) + param_2[7];
  uVar4 = *(uint *)(lVar12 + 4) << 4 | *(uint *)(lVar12 + 4) >> 0x1c;
  uVar6 = (ulonglong)uVar4;
  *(uint *)(lVar12 + 4) = uVar4;
LAB_140012032:
  return uVar6 & 0xffffffffffffff00;
}



===== SyncronizeProcessShutdown @ 1400121c0 =====

undefined1 SyncronizeProcessShutdown(longlong param_1)

{
  uint uVar1;
  undefined1 uVar2;
  
  uVar1 = *(uint *)(param_1 + 0xe440);
  if ((uVar1 == 2) || (uVar1 < 0xe)) {
                    /* WARNING: Could not recover jumptable at 0x00014001221f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*(code *)(IMAGE_DOS_HEADER_140000000.e_magic +
                      *(uint *)(&DAT_140012678 + (longlong)(int)uVar1 * 4)))
                      (IMAGE_DOS_HEADER_140000000.e_magic +
                       *(uint *)(&DAT_140012678 + (longlong)(int)uVar1 * 4));
    return uVar2;
  }
  return 1;
}



===== TryFlushingGroups @ 1400126b0 =====

void TryFlushingGroups(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  bool bVar3;
  undefined8 uVar4;
  byte bVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  
  uVar7 = (ulonglong)*(byte *)(param_1 + 0xd814);
  bVar3 = true;
  if (*(char *)(param_1 + 0x89) == '\0') {
    do {
      uVar6 = 0;
      do {
        lVar1 = uVar7 * 0x180 + uVar6 * 0x28;
        if ((((*(char *)(lVar1 + 0x48 + *(longlong *)(param_1 + 0xd818)) != '\0') ||
             (*(int *)(uVar7 * 0x180 + 0x20 + *(longlong *)(param_1 + 0xd818)) == 0)) &&
            (plVar2 = *(longlong **)(lVar1 + 0x30 + *(longlong *)(param_1 + 0xd818)),
            plVar2 != (longlong *)0x0)) &&
           (uVar4 = SendRequestIfNotBusy(param_1,plVar2), (char)uVar4 == '\0')) {
          bVar3 = false;
          break;
        }
        bVar5 = (char)uVar6 + 1;
        uVar6 = (ulonglong)bVar5;
      } while (bVar5 < 8);
      bVar5 = (char)uVar7 + 1;
      uVar7 = 0;
      if ((ushort)bVar5 < *(ushort *)(param_1 + 0xd308)) {
        uVar7 = (ulonglong)bVar5;
      }
    } while ((char)uVar7 != *(char *)(param_1 + 0xd814));
    if (bVar3) {
      *(undefined1 *)(param_1 + 0xd830) = 0;
      *(undefined1 *)(param_1 + 0xd814) = 0;
      return;
    }
    *(char *)(param_1 + 0xd814) = (char)uVar7;
    *(undefined1 *)(param_1 + 0xd8d0) = 1;
  }
  return;
}



===== TryFlushingIoctl @ 1400127c0 =====

void TryFlushingIoctl(longlong param_1)

{
  longlong *plVar1;
  undefined8 uVar2;
  
  plVar1 = *(longlong **)(param_1 + 0x9220);
  *(undefined8 *)(param_1 + 0x9220) = 0;
  uVar2 = SendRequestIfNotBusy(param_1,plVar1);
  if ((char)uVar2 == '\0') {
    *(longlong **)(param_1 + 0x9220) = plVar1;
  }
  return;
}



===== WatchDogTimer @ 140012800 =====

void WatchDogTimer(longlong param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xe43c);
  if (iVar1 == 0) {
    StorPortNotification(6,param_1,WatchDogTimer);
    return;
  }
  if (iVar1 == 1) {
    AcquireIsrLocks(param_1,8,0);
    SyncronizeProcessShutdown(param_1);
    ReleaseIsrLocks(param_1,8,0);
    return;
  }
  if (iVar1 == 2) {
    AcquireIsrLocks(param_1,8,0);
    SyncronizeInitializeAdapter(param_1);
    ReleaseIsrLocks(param_1,8,0);
    return;
  }
  return;
}



===== FunctionControl @ 140012890 =====

undefined1
FunctionControl(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4,char param_5
               )

{
  *(bool *)(param_1 + 0xd758) = param_5 != '\0';
  ScsiPortWmiPostProcess(param_2,'\x01',0);
  return 1;
}



===== MegaSASQueryWmiDataBlock @ 1400128c0 =====

ulonglong MegaSASQueryWmiDataBlock
                    (undefined8 param_1,longlong param_2,int param_3,undefined8 param_4,uint param_5
                    ,uint *param_6,uint param_7)

{
  int iVar1;
  ulonglong uVar2;
  char cVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = (ulonglong)param_5;
  cVar3 = '\x04';
  if (param_5 == 1) {
    if (param_3 == 0) {
      uVar5 = 4;
      cVar3 = '\x12';
      if (3 < param_7) {
        cVar3 = '\x01';
      }
    }
    else {
      uVar5 = 0;
    }
    if ((param_6 != (uint *)0x0) && (cVar3 != '\x12')) {
      *param_6 = uVar5;
    }
  }
  else {
    uVar5 = 0;
    if (param_5 != 0) {
      puVar4 = param_6;
      do {
        uVar6 = 0;
        if (param_3 == 0) {
          uVar6 = 4;
        }
        cVar3 = '\x04';
        if (param_3 == 0) {
          cVar3 = '\x12';
        }
        uVar5 = uVar5 + (uVar6 + 7 & 0xfffffff8);
        if (param_6 != (uint *)0x0) {
          *puVar4 = uVar6;
        }
        puVar4 = puVar4 + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    if ((param_6 == (uint *)0x0) || (param_7 < uVar5)) {
      cVar3 = '\x12';
    }
    else {
      uVar5 = 0;
      uVar6 = 0;
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
          uVar5 = uVar5 + (iVar1 + 7U & 0xfffffff8);
          if (cVar3 != '\x01') break;
          uVar6 = uVar6 + 1;
          param_6 = param_6 + 1;
        } while (uVar6 < param_5);
      }
    }
  }
  uVar2 = ScsiPortWmiPostProcess(param_2,cVar3,uVar5);
  return uVar2 & 0xffffffffffffff00;
}



===== MegaSASQueryWmiRegInfo @ 140012a00 =====

undefined8 MegaSASQueryWmiRegInfo(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  *param_3 = L"MofResource";
  return 0x140013901;
}



===== MegaSASWmiInitialize @ 140012a10 =====

void MegaSASWmiInitialize(longlong param_1)

{
  *(undefined4 *)(param_1 + 0xd7b0) = 1;
  *(undefined8 *)(param_1 + 0xd7d8) = 0;
  *(undefined ***)(param_1 + 0xd7b8) = &MegaSASGuidList;
  *(code **)(param_1 + 0xd7c0) = MegaSASQueryWmiRegInfo;
  *(code **)(param_1 + 0xd7c8) = MegaSASQueryWmiDataBlock;
  *(code **)(param_1 + 0xd7e8) = FunctionControl;
  *(undefined8 *)(param_1 + 0xd7d0) = 0;
  *(undefined8 *)(param_1 + 0xd7e0) = 0;
  return;
}



===== MegaSASWmiSrb @ 140012a70 =====

undefined8 MegaSASWmiSrb(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  if ((*(byte *)(param_2 + 9) & 1) == 0) {
    *(undefined4 *)(param_2 + 0x10) = 0;
    *(undefined1 *)(param_2 + 3) = 1;
  }
  else {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    local_10 = 0;
    uVar1 = ScsiPortWmiDispatchFunction
                      ((uint *)(param_1 + 0xd7b0),*(byte *)(param_2 + 4),param_1,(longlong)&local_28
                       ,*(ulonglong **)(param_2 + 0x20),*(uint *)(param_2 + 0x10),
                       *(uint **)(param_2 + 0x18));
    if ((char)uVar1 != '\0') goto LAB_140012afc;
    *(undefined4 *)(param_2 + 0x10) = local_10._4_4_;
    *(undefined1 *)(param_2 + 3) = local_10._1_1_;
  }
  uVar1 = StorPortNotification(0,param_1,param_2);
LAB_140012afc:
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== __security_check_cookie @ 140012b20 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== __report_gsfailure @ 140012b40 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== StorPortGetPhysicalAddress @ 140012b50 =====

void StorPortGetPhysicalAddress(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140012b50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetPhysicalAddress();
  return;
}



===== StorPortBusy @ 140012b5c =====

void StorPortBusy(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140012b5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortBusy();
  return;
}



===== StorPortNotification @ 140012b68 =====

void StorPortNotification(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140012b68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification();
  return;
}



===== StorPortExtendedFunction @ 140012b74 =====

void StorPortExtendedFunction(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140012b74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortExtendedFunction();
  return;
}



===== __GSHandlerCheck @ 140012b80 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140012ba0 =====

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



===== StorPortSetDeviceQueueDepth @ 140012c00 =====

void StorPortSetDeviceQueueDepth(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140012c00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortSetDeviceQueueDepth();
  return;
}



===== StorPortStallExecution @ 140012c0c =====

void StorPortStallExecution(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140012c0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortStallExecution();
  return;
}



===== StorPortInitialize @ 140012c18 =====

void StorPortInitialize(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140012c18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortInitialize();
  return;
}



===== StorPortGetBusData @ 140012c24 =====

void StorPortGetBusData(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140012c24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetBusData();
  return;
}



===== StorPortGetDeviceBase @ 140012c30 =====

void StorPortGetDeviceBase(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140012c30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetDeviceBase();
  return;
}



===== StorPortGetUncachedExtension @ 140012c3c =====

void StorPortGetUncachedExtension(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140012c3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetUncachedExtension();
  return;
}



===== StorPortQuerySystemTime @ 140012c48 =====

void StorPortQuerySystemTime(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140012c48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortQuerySystemTime();
  return;
}



===== memcmp @ 140012c70 =====

int __cdecl memcmp(void *_Buf1,void *_Buf2,size_t _Size)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  bool bVar5;
  
  lVar3 = (longlong)_Buf2 - (longlong)_Buf1;
  if (7 < _Size) {
    for (; ((ulonglong)_Buf1 & 7) != 0; _Buf1 = (void *)((longlong)_Buf1 + 1)) {
      bVar5 = (byte)*(ulonglong *)_Buf1 < *(byte *)((longlong)_Buf1 + lVar3);
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_140012cb3;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_140012d24;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_140012d20:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140012d24;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_140012d1c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140012d20;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140012d1c;
          }
          _Buf1 = (void *)((longlong)_Buf1 + 0x20);
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
        _Size = _Size & 0x1f;
      }
      uVar4 = _Size >> 3;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) {
LAB_140012d24:
            uVar4 = *(ulonglong *)(lVar3 + (longlong)_Buf1);
            uVar1 = (uint)((uVar2 >> 0x38 | (uVar2 & 0xff000000000000) >> 0x28 |
                            (uVar2 & 0xff0000000000) >> 0x18 | (uVar2 & 0xff00000000) >> 8 |
                            (uVar2 & 0xff000000) << 8 | (uVar2 & 0xff0000) << 0x18 |
                            (uVar2 & 0xff00) << 0x28 | uVar2 << 0x38) <
                          (uVar4 >> 0x38 | (uVar4 & 0xff000000000000) >> 0x28 |
                           (uVar4 & 0xff0000000000) >> 0x18 | (uVar4 & 0xff00000000) >> 8 |
                           (uVar4 & 0xff000000) << 8 | (uVar4 & 0xff0000) << 0x18 |
                           (uVar4 & 0xff00) << 0x28 | uVar4 << 0x38));
            return (1 - uVar1) - (uint)(uVar1 != 0);
          }
          _Buf1 = (void *)((longlong)_Buf1 + 8);
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
        _Size = _Size & 7;
      }
    }
  }
  while( true ) {
    if (_Size == 0) {
      return 0;
    }
    bVar5 = (byte)*(ulonglong *)_Buf1 < *(byte *)((longlong)_Buf1 + lVar3);
    if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) break;
    _Buf1 = (void *)((longlong)_Buf1 + 1);
    _Size = _Size - 1;
  }
LAB_140012cb3:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== StorPortGetScatterGatherList @ 140012d37 =====

void StorPortGetScatterGatherList(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140012d37. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortGetScatterGatherList();
  return;
}



===== StorPortPause @ 140012d43 =====

void StorPortPause(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140012d43. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortPause();
  return;
}



===== StorPortResume @ 140012d4f =====

void StorPortResume(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140012d4f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortResume();
  return;
}



===== StorPortReady @ 140012d5b =====

void StorPortReady(void)

{
                    /* WARNING: Could not recover jumptable at 0x000140012d5b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortReady();
  return;
}



===== ScsiPortWmiDispatchFunction @ 140012d68 =====

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



===== ScsiPortWmiFireLogicalUnitEvent @ 140012e08 =====

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
  param_8[6] = iVar1;
  param_8[7] = iVar2;
  param_8[8] = iVar3;
  param_8[9] = iVar4;
  *param_8 = param_7 + 0x40;
  if (param_2 == -1) {
    ScsiPortNotification(8,param_1,param_8,0xff);
  }
  else {
    ScsiPortNotification(8);
  }
  return;
}



===== ScsiPortWmiPostProcess @ 140012e9c =====

void ScsiPortWmiPostProcess(longlong param_1,char param_2,uint param_3)

{
  char cVar1;
  
  cVar1 = ScsiWmipPostProcess(*(char *)(param_1 + 0x18),*(uint **)(param_1 + 0x10),
                              *(uint *)(param_1 + 8),param_3,param_2,(uint *)(param_1 + 0x1c));
  *(char *)(param_1 + 0x19) = cVar1;
  return;
}



===== ScsiWmipFindGuid @ 140012ed0 =====

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



===== ScsiWmipPostProcess @ 140012f30 =====

char ScsiWmipPostProcess(char param_1,uint *param_2,uint param_3,uint param_4,char param_5,
                        uint *param_6)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  uint *puVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  
  uVar7 = 0;
  if (param_1 == '\0') {
    uVar5 = param_2[0xc];
    uVar1 = param_2[0xd];
    uVar6 = (ulonglong)uVar1;
    uVar2 = uVar5 + param_4;
    if (param_5 == '\x01') {
      if (uVar2 <= param_3) {
        if (((0x2f < param_3) && (*param_2 = uVar2, uVar7 = uVar2, (char)param_2[0xb] < '\0')) &&
           (puVar4 = param_2 + 0xf, uVar3 = uVar6, uVar1 != 0)) {
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
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
        }
        goto LAB_140012ff8;
      }
      param_5 = '\x12';
    }
LAB_140012fd6:
    if ((param_5 != '\x12') || (param_3 < 0x38)) goto LAB_140012ff8;
    param_2[0xc] = uVar2;
  }
  else {
    if (param_1 == '\x01') {
      uVar2 = param_2[0xe] + param_4;
      if (param_5 == '\x01') {
        if (0x2f < param_3) {
          *param_2 = uVar2;
          uVar7 = uVar2;
        }
        goto LAB_140012ff8;
      }
      goto LAB_140012fd6;
    }
    if (param_1 != '\t') goto LAB_140012ff8;
    uVar5 = param_2[0xf] + param_4;
    if (param_5 == '\x01') {
      if (0x47 < param_3) {
        *param_2 = uVar5;
        param_2[0x10] = param_4;
        uVar7 = uVar5;
      }
      goto LAB_140012ff8;
    }
    if ((param_5 != '\x12') || (param_3 < 0x38)) goto LAB_140012ff8;
    param_2[0xc] = uVar5;
  }
  *param_2 = 0x38;
  param_2[0xb] = 0x20;
  param_5 = '\x01';
  uVar7 = 0x38;
LAB_140012ff8:
  *param_6 = uVar7;
  return param_5;
}



===== ScsiWmipProcessRequest @ 140013080 =====

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
  longlong lVar12;
  int *piVar13;
  uint *puVar14;
  uint uVar15;
  int iVar16;
  undefined8 uVar17;
  ushort uVar18;
  uint local_res10 [2];
  uint uVar19;
  undefined8 uVar20;
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
LAB_140013177:
      *param_8 = 0;
      cVar5 = '\x04';
      goto LAB_140013491;
    }
    if (((byte)(param_2 - 1) < 3) || (param_2 == 9)) {
      uVar6 = param_7[0xd];
      if (((char)param_7[0xb] < '\0') && (local_38[0] <= uVar6)) goto LAB_140013177;
    }
    else {
      uVar6 = 0;
    }
  }
  if (param_2 < 6) {
    if (param_2 != 5) {
      if (param_2 == 0) {
        if (param_6 < 0x48) goto LAB_1400131bc;
        param_7[0xb] = param_7[0xb] & 0xffffffef;
        uVar6 = local_38[0] * 8 + 0x40;
        param_7[0xd] = local_38[0];
        param_7[0xc] = uVar6;
        if (param_6 < uVar6) {
          lVar12 = 0;
          iVar16 = 0;
        }
        else {
          puVar14 = param_7 + 0xf;
          lVar12 = (ulonglong)uVar6 + (longlong)param_7;
          iVar16 = param_6 - uVar6;
        }
        uVar6 = 0;
        uVar19 = local_38[0];
      }
      else {
        if (param_2 != 1) {
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
              uVar17 = 0;
              goto LAB_1400134b8;
            }
            goto LAB_1400134cb;
          }
LAB_1400131bc:
          cVar5 = '\x04';
          goto LAB_1400134cd;
        }
        if (param_6 < 0x40) {
          if (param_6 < 4) {
            *(undefined1 *)param_7 = 8;
            return '\x12';
          }
          *param_7 = 0x40;
          return '\x12';
        }
        puVar14 = param_7 + 0xf;
        iVar16 = param_6 - param_7[0xe];
        lVar12 = (longlong)param_7 + (ulonglong)param_7[0xe];
        uVar19 = 1;
      }
      pcVar8 = *(code **)(param_1 + 6);
LAB_14001329c:
      cVar5 = (*pcVar8)(param_3,param_4,local_res10[0],uVar6,uVar19,puVar14,iVar16,lVar12);
      return cVar5;
    }
    pcVar8 = *(code **)(param_1 + 0xe);
    if (pcVar8 != (code *)0x0) {
      uVar20 = 0;
      uVar17 = 0;
      goto LAB_1400134bc;
    }
  }
  else if (param_2 == 6) {
    pcVar8 = *(code **)(param_1 + 0xe);
    if (pcVar8 != (code *)0x0) {
      uVar17 = 1;
LAB_1400134b8:
      uVar20 = 1;
LAB_1400134bc:
      cVar5 = (*pcVar8)(param_3,param_4,local_res10[0],uVar17,uVar20);
      return cVar5;
    }
  }
  else {
    if (param_2 != 7) {
      if (param_2 != 8) {
        if (param_2 == 9) {
          pcVar8 = *(code **)(param_1 + 0xc);
          if ((pcVar8 != (code *)0x0) && (0x47 < param_6)) {
            uVar19 = param_7[0xf];
            if (uVar19 <= param_6) {
              lVar12 = (longlong)param_7 + (ulonglong)uVar19;
              iVar16 = param_6 - uVar19;
              puVar14 = (uint *)(ulonglong)param_7[0x10];
              uVar19 = param_7[0xe];
              goto LAB_14001329c;
            }
          }
          cVar5 = '\x04';
          goto LAB_1400134cd;
        }
        goto LAB_1400131bc;
      }
      cVar5 = (**(code **)(param_1 + 4))(param_3,param_4,&param_9);
      if (cVar5 == '\x01') {
        uVar19 = *param_1;
        uVar7 = (ulonglong)uVar19;
        lVar12 = *(longlong *)(param_1 + 2);
        uVar15 = uVar19 * 0x20 + 0x18;
        uVar6 = uVar19 * 0x20 + 0x34;
        if (param_9 == (short *)0x0) {
          uVar18 = 0;
        }
        else {
          uVar18 = 0;
          sVar2 = *param_9;
          while (sVar2 != 0) {
            uVar18 = uVar18 + 1;
            sVar2 = param_9[uVar18];
          }
          uVar18 = uVar18 * 2;
        }
        uVar9 = uVar18 + uVar6;
        if ((uVar9 < uVar6) || (uVar1 = uVar9 + 2, uVar1 < uVar9)) {
          cVar5 = '\x04';
          goto LAB_140013484;
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
          param_7[4] = uVar19;
          if (uVar19 != 0) {
            piVar13 = (int *)(lVar12 + 8);
            puVar10 = (ulonglong *)(param_7 + 0xc);
            do {
              uVar3 = (*(ulonglong **)(piVar13 + -2))[1];
              puVar10[-3] = **(ulonglong **)(piVar13 + -2);
              puVar10[-2] = uVar3;
              if (*piVar13 == -1) {
                *(int *)(puVar10 + -1) = piVar13[1];
                iVar16 = 0;
                *puVar10 = 0;
              }
              else {
                *(uint *)(puVar10 + -1) = piVar13[1] | 8;
                *puVar10 = (ulonglong)uVar15;
                iVar16 = *piVar13;
              }
              *(int *)((longlong)puVar10 + -4) = iVar16;
              piVar13 = piVar13 + 4;
              puVar10 = puVar10 + 4;
              uVar7 = uVar7 - 1;
            } while (uVar7 != 0);
          }
          puVar11 = (undefined2 *)((ulonglong)uVar15 + (longlong)param_7);
          *puVar11 = 0x1a;
          memmove(puVar11 + 1,L"ScsiMiniPort",0x1a);
          *(ushort *)((ulonglong)uVar6 + (longlong)param_7) = uVar18;
          memmove((ushort *)((ulonglong)uVar6 + (longlong)param_7) + 1,param_9,(ulonglong)uVar18);
          param_6 = uVar1;
        }
      }
      else {
LAB_140013484:
        param_6 = 0;
      }
      *param_8 = param_6;
LAB_140013491:
      psVar4[0] = 1;
      psVar4[1] = 0;
      return cVar5;
    }
    pcVar8 = *(code **)(param_1 + 0xe);
    if (pcVar8 != (code *)0x0) {
      uVar20 = 0;
      uVar17 = 1;
      goto LAB_1400134bc;
    }
  }
LAB_1400134cb:
  cVar5 = '\x01';
LAB_1400134cd:
  psVar4[0] = 1;
  psVar4[1] = 0;
  return cVar5;
}



===== strstr @ 1400134ef =====

char * __cdecl strstr(char *_Str,char *_SubStr)

{
  char *pcVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400134ef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pcVar1 = strstr(_Str,_SubStr);
  return pcVar1;
}



===== _guard_dispatch_icall @ 140013510 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140013510. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== memmove @ 140013540 =====

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
          puVar10 = (undefined8 *)((longlong)puVar9 + (uVar11 - 0x10));
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
          *(undefined1 *)puVar9 = *(undefined1 *)((longlong)puVar9 + uVar11);
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
            puVar9 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x10));
            uVar4 = puVar9[1];
            puVar1 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x20));
            uVar5 = *puVar1;
            uVar6 = puVar1[1];
            puVar10[-2] = *puVar9;
            puVar10[-1] = uVar4;
            puVar10[-4] = uVar5;
            puVar10[-3] = uVar6;
            puVar9 = puVar10 + -8;
            puVar1 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x30));
            uVar4 = puVar1[1];
            uVar5 = *(undefined8 *)((longlong)puVar9 + uVar11);
            uVar6 = ((undefined8 *)((longlong)puVar9 + uVar11))[1];
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
        if (uVar12 == 0) goto LAB_1400136f7;
      }
      _Size = _Size & 0x1f;
      puVar10 = puVar9;
      do {
        puVar1 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x10));
        uVar4 = puVar1[1];
        puVar9 = (undefined8 *)((longlong)puVar10 + (uVar11 - 0x20));
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
LAB_1400136f7:
    for (uVar12 = _Size >> 3; uVar12 != 0; uVar12 = uVar12 - 1) {
      puVar10 = (undefined8 *)((longlong)puVar9 + (uVar11 - 8));
      puVar9 = puVar9 + -1;
      *puVar9 = *puVar10;
    }
    for (uVar12 = _Size & 7; uVar12 != 0; uVar12 = uVar12 - 1) {
      puVar3 = (undefined1 *)((longlong)puVar9 + (uVar11 - 1));
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
        *(undefined1 *)puVar9 = *(undefined1 *)((longlong)puVar9 + uVar11);
      }
    }
    else {
      uVar8 = -(int)_Dst & 0xf;
      if (uVar8 != 0) {
        _Size = _Size - uVar8;
        uVar4 = ((undefined8 *)((longlong)_Dst + uVar11))[1];
        *(undefined8 *)_Dst = *(undefined8 *)((longlong)_Dst + uVar11);
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
          uVar4 = ((undefined8 *)((longlong)puVar10 + uVar11))[1];
          puVar9 = (undefined8 *)((longlong)puVar10 + uVar11 + 0x10);
          uVar5 = *puVar9;
          uVar6 = puVar9[1];
          *puVar10 = *(undefined8 *)((longlong)puVar10 + uVar11);
          puVar10[1] = uVar4;
          puVar10[2] = uVar5;
          puVar10[3] = uVar6;
          puVar9 = puVar10 + 8;
          puVar1 = (undefined8 *)((longlong)puVar10 + uVar11 + 0x20);
          uVar4 = puVar1[1];
          puVar2 = (undefined8 *)((longlong)puVar10 + uVar11 + 0x30);
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
      if (uVar12 == 0) goto LAB_140013552;
    }
    _Size = _Size & 0x1f;
    puVar10 = puVar9;
    do {
      uVar4 = ((undefined8 *)((longlong)puVar10 + uVar11))[1];
      puVar9 = (undefined8 *)((longlong)puVar10 + uVar11 + 0x10);
      uVar5 = *puVar9;
      uVar6 = puVar9[1];
      puVar9 = puVar10 + 4;
      *puVar10 = *(undefined8 *)((longlong)puVar10 + uVar11);
      puVar10[1] = uVar4;
      puVar10[2] = uVar5;
      puVar10[3] = uVar6;
      uVar12 = uVar12 - 1;
      puVar10 = puVar9;
    } while (uVar12 != 0);
  }
LAB_140013552:
  for (uVar12 = _Size >> 3; uVar12 != 0; uVar12 = uVar12 - 1) {
    *puVar9 = *(undefined8 *)((longlong)puVar9 + uVar11);
    puVar9 = puVar9 + 1;
  }
  for (uVar12 = _Size & 7; uVar12 != 0; uVar12 = uVar12 - 1) {
    *(undefined1 *)puVar9 = *(undefined1 *)((longlong)puVar9 + uVar11);
    puVar9 = (undefined8 *)((longlong)puVar9 + 1);
  }
  return _Dst;
}



===== memset @ 140013880 =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  if (_Size < 8) {
    for (uVar4 = _Size & 7; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(char *)((longlong)_Dst + (uVar4 - 1)) = (char)_Val;
    }
    return _Dst;
  }
  lVar3 = ((ulonglong)(uint)_Val & 0xff) * 0x101010101010101;
  if (_Size < 0x4f) {
    uVar4 = _Size & 0xfffffffffffffff8;
    do {
      *(longlong *)((longlong)_Dst + (uVar4 - 8)) = lVar3;
      uVar4 = uVar4 - 8;
    } while (uVar4 != 0);
    if ((_Size & 7) != 0) {
      *(longlong *)((longlong)_Dst + (_Size & 7) + ((_Size & 0xfffffffffffffff8) - 8)) = lVar3;
    }
    return _Dst;
  }
  *(longlong *)_Dst = lVar3;
  *(longlong *)((longlong)_Dst + 8) = lVar3;
  plVar1 = (longlong *)((longlong)_Dst + 0x10U & 0xfffffffffffffff0);
  uVar4 = (longlong)_Dst + (_Size - (longlong)plVar1);
  uVar5 = uVar4 >> 7;
  plVar2 = plVar1;
  if (uVar5 != 0) {
    do {
      *plVar2 = lVar3;
      plVar2[1] = lVar3;
      plVar2[2] = lVar3;
      plVar2[3] = lVar3;
      plVar1 = plVar2 + 0x10;
      plVar2[4] = lVar3;
      plVar2[5] = lVar3;
      plVar2[6] = lVar3;
      plVar2[7] = lVar3;
      uVar5 = uVar5 - 1;
      plVar2[8] = lVar3;
      plVar2[9] = lVar3;
      plVar2[10] = lVar3;
      plVar2[0xb] = lVar3;
      plVar2[0xc] = lVar3;
      plVar2[0xd] = lVar3;
      plVar2[0xe] = lVar3;
      plVar2[0xf] = lVar3;
      plVar2 = plVar1;
    } while (uVar5 != 0);
    uVar4 = uVar4 & 0x7f;
  }
  for (uVar5 = uVar4 >> 4; uVar5 != 0; uVar5 = uVar5 - 1) {
    *plVar1 = lVar3;
    plVar1[1] = lVar3;
    plVar1 = plVar1 + 2;
  }
  if ((uVar4 & 0xf) != 0) {
    plVar1 = (longlong *)((longlong)plVar1 + ((uVar4 & 0xf) - 0x10));
    *plVar1 = lVar3;
    plVar1[1] = lVar3;
  }
  return _Dst;
}



===== entry @ 140018000 =====

void entry(undefined8 param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14001802c =====

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


