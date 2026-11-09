
===== AhciHwEnumerateBus @ 1c0001000 =====

undefined8 AhciHwEnumerateBus(longlong *param_1,undefined1 param_2)

{
  undefined8 uVar1;
  
  uVar1 = AhciEnumerateChannelAsynchronously(param_1,1);
  return uVar1;
}



===== AhciHwReanimateBus @ 1c0001010 =====

void AhciHwReanimateBus(longlong *param_1)

{
  AhciEnumerateChannelAsynchronously(param_1,0);
  return;
}



===== AhciHwResetBus @ 1c0001018 =====

ulonglong AhciHwResetBus(longlong param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  ulonglong local_res8 [4];
  
  StorPortQuerySystemTime(local_res8);
  *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 1;
  *(ulonglong *)(param_1 + 0x48 + (ulonglong)(*(uint *)(param_1 + 0x44) & 7) * 8) = local_res8[0];
  if (*(int *)(param_1 + 0xf4) == 0) {
    *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x8c) + 1;
    pcVar2 = AhciHwEnumerateBus;
    if (*(int *)(param_1 + 0x10) < 0) {
      pcVar2 = AhciHwReanimateBus;
    }
    uVar1 = AhciPortRequestSynchronizedRoutine(param_1,pcVar2);
    local_res8[0] = CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
  }
  else {
    *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;
    local_res8[0] = local_res8[0] & 0xffffffffffffff00;
  }
  return local_res8[0];
}



===== AhciChannelIpm @ 1c0001080 =====

ulonglong AhciChannelIpm(longlong param_1,byte param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  char cVar10;
  
  cVar10 = '\0';
  if (((*(uint *)(param_1 + 0x18f8) >> 0x1a & 1) == 0) || (*(char *)(param_1 + 0x23) != '\0')) {
    uVar6 = (ulonglong)(uint3)(*(uint *)(param_1 + 0x18f8) >> 8) << 8;
  }
  else {
    if ((*(int *)(param_1 + 0xc) != -0x6996feff) &&
       (((piVar4 = *(int **)(param_1 + 0x1a70), piVar4 == (int *)0x0 || (*piVar4 == 0)) ||
        ((*(ushort *)(piVar4 + 0x2c) & 0x200) == 0)))) {
      param_2 = 0;
    }
    uVar2 = *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x18);
    uVar7 = uVar2 & 0xfbffffff;
    uVar3 = *(uint *)(param_1 + 0x18f8);
    uVar8 = *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x2c) & 0xfffff0ff;
    uVar9 = uVar3 >> 0xe & 1;
    if (uVar9 == 0) {
      uVar8 = uVar8 | 0x200;
    }
    uVar5 = uVar3 >> 0xd & 1;
    if (uVar5 == 0) {
      uVar8 = uVar8 | 0x100;
    }
    if (((uVar3 >> 0x1a & 1) != 0) && (param_2 != 0)) {
      if ((uVar5 != 0) && ((param_2 & 1) != 0)) {
        cVar10 = '\x01';
        uVar7 = uVar2 & 0xf3ffffff | 0x4000000;
      }
      if ((uVar9 != 0) && ((param_2 & 2) != 0)) {
        cVar10 = '\x02';
        uVar7 = uVar7 | 0xc000000;
      }
    }
    cVar1 = *(char *)(param_1 + 0x32);
    *(char *)(param_1 + 0x32) = cVar10;
    uVar6 = (ulonglong)(cVar1 != cVar10);
    *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x2c) = uVar8;
    LOCK();
    UNLOCK();
    *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x18) = uVar7;
    LOCK();
    UNLOCK();
  }
  return uVar6;
}



===== AhciEnableDevSlpCompletion @ 1c0001190 =====

undefined1 AhciEnableDevSlpCompletion(longlong param_1,longlong param_2)

{
  if ((*(char *)(param_2 + 2) != '\x05') && (*(char *)(param_2 + 2) == '\x01')) {
    AhciSetDEVSLP(param_1,'\x01');
  }
  return 1;
}



===== AhciChannelIpmCompletion @ 1c00011b0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong AhciChannelIpmCompletion(longlong param_1,undefined2 *param_2)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  ushort *puVar4;
  uint *puVar5;
  longlong lVar6;
  uint uVar7;
  ulonglong in_RAX;
  undefined4 *puVar8;
  ulonglong uVar9;
  uint uVar10;
  longlong lVar11;
  longlong lVar12;
  
  if (*(char *)(param_2 + 1) == '\x05') {
LAB_1c000144e:
    uVar9 = CONCAT71((int7)(in_RAX >> 8),1);
  }
  else {
    if ((((*(char *)(param_1 + 0x24) == '\0') || (*(int *)(param_1 + 0xc) != 0x101)) ||
        ((*(int *)(param_1 + 0x1a58) == 0 &&
         ((*(char *)(param_1 + 0x32) == '\0' && (*(char *)(param_1 + 0x33) != '\0')))))) ||
       (in_RAX = (ulonglong)*(byte *)(param_2 + 3),
       *(char *)(*(longlong *)(param_1 + 0x1a70 + in_RAX * 8) + 0x488) == '\0')) {
      if ((*(int *)(param_1 + 0x1a58) == 0) ||
         (uVar3 = *(ushort *)
                   (*(longlong *)(param_1 + 0x1a70 + (ulonglong)*(byte *)(param_2 + 3) * 8) + 0xb0),
         in_RAX = (ulonglong)uVar3, (uVar3 & 0x4000) == 0)) goto LAB_1c000144e;
      *(undefined1 *)(param_2 + 0x35) = 0xef;
      lVar12 = (ulonglong)*(byte *)((longlong)param_2 + 0xb) * 0x38 + param_1;
      *param_2 = 0x100;
      param_2[0x32] = 0x710;
      *(undefined8 *)(param_2 + 0x18) = 0;
      *(undefined1 *)(param_2 + 1) = 0;
    }
    else {
      *(undefined1 *)(param_2 + 0x35) = 0xef;
      *param_2 = 0x100;
      lVar12 = (ulonglong)*(byte *)((longlong)param_2 + 0xb) * 0x38 + param_1;
      cVar1 = *(char *)(param_1 + 0x33);
      *(undefined1 *)((longlong)param_2 + 0x65) = 9;
      *(undefined1 *)(param_2 + 1) = 0;
      *(byte *)(param_2 + 0x32) = (-(cVar1 != '\0') & 0x80U) + 0x90;
      if (*(char *)(param_1 + 0x33) == '\0') {
        *(undefined8 *)(param_2 + 0x18) = 0;
        AhciSetDEVSLP(param_1,'\0');
      }
      else {
        *(code **)(param_2 + 0x18) = AhciEnableDevSlpCompletion;
      }
    }
    IRBtoATA_CFIS(param_1,(uint *)(lVar12 + 0x2a8));
    puVar4 = *(ushort **)(lVar12 + 0x2b0);
    puVar5 = *(uint **)(lVar12 + 0x2b8);
    *puVar5 = 0;
    *(undefined2 *)((longlong)puVar5 + 2) = 0;
    uVar7 = *puVar5 & 0xffffffe5 | 5;
    *puVar5 = uVar7;
    uVar7 = (*puVar4 >> 4 ^ uVar7) & 0x20 ^ uVar7;
    *puVar5 = uVar7;
    uVar7 = (*(uint *)(puVar4 + 8) >> 1 ^ uVar7) & 0x40 ^ uVar7;
    *puVar5 = uVar7;
    *puVar5 = ((uint)(byte)puVar4[3] << 0xc ^ uVar7) & 0xf000 ^ uVar7;
    puVar5[1] = 0;
    puVar5[4] = 0;
    puVar5[5] = 0;
    puVar5[6] = 0;
    puVar5[7] = 0;
    lVar6 = *(longlong *)(param_1 + -0x98);
    lVar11 = (ulonglong)*(byte *)(lVar12 + 0x2d0) * 0x38;
    uVar7 = *(uint *)(lVar11 + 0x2a8 + param_1);
    bVar2 = *(byte *)(lVar11 + 0x2d1 + param_1);
    uVar10 = 1 << (*(byte *)(lVar12 + 0x2d0) & 0x1f);
    if ((*(char *)(param_1 + 0x1f) != '\0') && (*(byte *)(param_1 + 0x1b) != bVar2)) {
      *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x40) = (bVar2 & 0xf) << 8 | 1;
      LOCK();
      UNLOCK();
      *(byte *)(param_1 + 0x1b) = bVar2;
    }
    if ((uVar7 & 0x20000) != 0) {
      *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x34) = uVar10;
      LOCK();
      UNLOCK();
      *(uint *)(param_1 + 0x128) = *(uint *)(param_1 + 0x128) | uVar10;
      puVar5 = (uint *)(param_1 + 0x174 + (ulonglong)bVar2 * 4);
      *puVar5 = *puVar5 | uVar10;
      *(byte *)(param_1 + 0x1a) = bVar2;
    }
    if ((((g_bIsKernCZBP != '\0') && (*(int *)(param_1 + 0xf4) == 0)) &&
        (((byte)*(undefined4 *)(param_1 + 0x10) & 6) == 2)) && (*(char *)(param_1 + -8) == '\x01'))
    {
      LOCK();
      _g_lOutstandingIO = _g_lOutstandingIO | 1;
      UNLOCK();
    }
    *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x38) = uVar10;
    LOCK();
    UNLOCK();
    *(uint *)(param_1 + 0x124) = *(uint *)(param_1 + 0x124) | uVar10;
    puVar8 = (undefined4 *)(ulonglong)bVar2;
    puVar5 = (uint *)(param_1 + 0x138 + (longlong)puVar8 * 4);
    *puVar5 = *puVar5 | uVar10;
    if (((g_bIsKernCZBP != '\0') && (*(int *)(param_1 + 0xf4) == 0)) &&
       ((puVar8 = (undefined4 *)((ulonglong)*(uint *)(param_1 + 0x10) & 0xffffffffffffff06),
        (char)puVar8 == '\x02' && (*(char *)(param_1 + -8) == '\x01')))) {
      puVar8 = &g_lPHYClock;
      LOCK();
      uVar7 = g_lPHYClock >> 0x1c;
      g_lPHYClock = g_lPHYClock | 0x10000000;
      UNLOCK();
      if ((uVar7 & 1) == 0) {
        puVar8 = (undefined4 *)
                 StorPortSetBusDataByOffset
                           (lVar6,4,*(undefined4 *)(lVar6 + 0x24),*(undefined4 *)(lVar6 + 0x84),
                            &g_lPHYClock,0x84,4);
      }
    }
    uVar9 = (ulonglong)puVar8 & 0xffffffffffffff00;
  }
  return uVar9;
}



===== Irb2Slot @ 1c0001460 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char Irb2Slot(longlong param_1,ushort *param_2,undefined8 param_3)

{
  int *piVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong lVar4;
  ushort *puVar5;
  uint *puVar6;
  ushort uVar7;
  byte bVar8;
  char cVar9;
  uint uVar10;
  uint *puVar11;
  ulonglong uVar12;
  
  piVar1 = *(int **)(param_1 + 0x1a70 + (ulonglong)(byte)param_2[3] * 8);
  if ((piVar1 == (int *)0x0) || (*piVar1 == 0)) {
    *(undefined1 *)(param_2 + 1) = 6;
    AhciPortCompleteRequest(param_1,param_2);
    return -6;
  }
  if ((char)param_2[1] != '\0') {
    AhciPortCompleteRequest(param_1,param_2);
    return -(char)param_2[1];
  }
  puVar11 = GetSlot(param_1);
  if (puVar11 == (uint *)0x0) {
    _DAT_1c0011444 = _DAT_1c0011444 + 1;
    return ' ';
  }
  *(ushort **)(puVar11 + 2) = param_2;
  *(char *)((longlong)puVar11 + 0x29) = (char)param_2[3];
  *(char *)((longlong)param_2 + 0xb) = (char)puVar11[10];
  if ((*param_2 & 0x100) == 0) {
    if ((*param_2 & 0x200) != 0) {
      lVar2 = *(longlong *)(puVar11 + 2);
      param_3 = 0x10;
      puVar3 = *(undefined8 **)(puVar11 + 6);
      *puVar11 = 0;
      lVar4 = *(longlong *)(param_1 + 0x1a70 + (ulonglong)*(byte *)(lVar2 + 6) * 8);
      *puVar3 = 0;
      puVar3[1] = 0;
      *(undefined4 *)(puVar3 + 2) = 0;
      memcpy(puVar3 + 8,(void *)(lVar2 + 100),0x10);
      *(byte *)((longlong)puVar3 + 1) = *(byte *)((longlong)puVar3 + 1) | 0x80;
      *(undefined1 *)puVar3 = 0x27;
      *(undefined1 *)((longlong)puVar3 + 2) = 0xa0;
      *(byte *)((longlong)puVar3 + 1) =
           *(byte *)((longlong)puVar3 + 1) ^
           (*(byte *)((longlong)puVar3 + 1) ^ *(byte *)(lVar2 + 6)) & 0xf;
      if ((*(byte *)(lVar4 + 0x32d) & 0xf0) == 0) {
        bVar8 = 0;
      }
      else {
        bVar8 = (byte)(*(uint *)(lVar2 + 0x10) >> 1) & 1;
      }
      *(byte *)((longlong)puVar3 + 3) = bVar8;
      *(undefined1 *)((longlong)puVar3 + 5) = *(undefined1 *)(lVar2 + 0x18);
      *(char *)((longlong)puVar3 + 6) = (char)((uint)*(undefined4 *)(lVar2 + 0x18) >> 8);
      goto LAB_1c0001597;
    }
LAB_1c000169b:
    *(undefined1 *)(param_2 + 1) = 4;
    ReleaseSlottedCommand(param_1,puVar11);
    cVar9 = -4;
  }
  else {
    *puVar11 = *(uint *)(param_2 + 8);
    IRBtoATA_CFIS(param_1,puVar11);
LAB_1c0001597:
    puVar5 = *(ushort **)(puVar11 + 2);
    if ((*(uint *)(puVar5 + 8) & 0xc0) == 0) {
      puVar6 = *(uint **)(puVar11 + 4);
      *puVar6 = 0;
      *(undefined2 *)((longlong)puVar6 + 2) = 0;
      uVar10 = *puVar6 & 0xffffffe5 | 5;
      *puVar6 = uVar10;
      uVar10 = (*puVar5 >> 4 ^ uVar10) & 0x20 ^ uVar10;
      *puVar6 = uVar10;
      uVar10 = (*(uint *)(puVar5 + 8) >> 1 ^ uVar10) & 0x40 ^ uVar10;
      *puVar6 = uVar10;
      uVar7 = puVar5[3];
      puVar6[1] = 0;
      *puVar6 = ((uint)(byte)uVar7 << 0xc ^ uVar10) & 0xf000 ^ uVar10;
      puVar6[4] = 0;
      puVar6[5] = 0;
      puVar6[6] = 0;
      puVar6[7] = 0;
    }
    else {
      uVar12 = IRBtoPRDT(param_1,(longlong)puVar11,param_3,(ulonglong)puVar5);
      if ((int)uVar12 == 0) goto LAB_1c000169b;
      puVar5 = *(ushort **)(puVar11 + 2);
      puVar6 = *(uint **)(puVar11 + 4);
      *puVar6 = 0;
      *(short *)((longlong)puVar6 + 2) = (short)uVar12;
      uVar10 = *puVar6 & 0xffffffe5 | 5;
      *puVar6 = uVar10;
      uVar10 = (*puVar5 >> 4 ^ uVar10) & 0x20 ^ uVar10;
      *puVar6 = uVar10;
      uVar10 = (*(uint *)(puVar5 + 8) >> 1 ^ uVar10) & 0x40 ^ uVar10;
      *puVar6 = uVar10;
      uVar7 = puVar5[3];
      puVar6[1] = 0;
      *puVar6 = ((uint)(byte)uVar7 << 0xc ^ uVar10) & 0xf000 ^ uVar10;
      puVar6[4] = 0;
      puVar6[5] = 0;
      puVar6[6] = 0;
      puVar6[7] = 0;
    }
    *(char *)((ulonglong)*(uint *)(param_1 + 0x18cc) + 0x18a8 + param_1) = (char)puVar11[10];
    *(uint *)(param_1 + 0x18cc) = *(int *)(param_1 + 0x18cc) + 1U & 0x1f;
    LOCK();
    *(int *)(param_1 + 0x18d0) = *(int *)(param_1 + 0x18d0) + 1;
    UNLOCK();
    cVar9 = (char)puVar11[10];
  }
  return cVar9;
}



===== Actuate @ 1c00016e0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char Actuate(longlong param_1)

{
  uint *puVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  uint uVar7;
  longlong lVar8;
  char cVar9;
  
  cVar9 = '\0';
  iVar4 = *(int *)(param_1 + 0x18d0);
  while (iVar4 != 0) {
    lVar6 = *(longlong *)(param_1 + -0x98);
    bVar2 = *(byte *)((ulonglong)*(uint *)(param_1 + 0x18c8) + 0x18a8 + param_1);
    lVar8 = (ulonglong)bVar2 * 0x38;
    uVar5 = *(uint *)(lVar8 + 0x2a8 + param_1);
    bVar3 = *(byte *)(lVar8 + 0x2d1 + param_1);
    uVar7 = 1 << (bVar2 & 0x1f);
    if ((*(char *)(param_1 + 0x1f) != '\0') && (*(byte *)(param_1 + 0x1b) != bVar3)) {
      *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x40) = (bVar3 & 0xf) << 8 | 1;
      LOCK();
      UNLOCK();
      *(byte *)(param_1 + 0x1b) = bVar3;
    }
    if ((uVar5 & 0x20000) != 0) {
      *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x34) = uVar7;
      LOCK();
      UNLOCK();
      *(uint *)(param_1 + 0x128) = *(uint *)(param_1 + 0x128) | uVar7;
      puVar1 = (uint *)(param_1 + 0x174 + (ulonglong)bVar3 * 4);
      *puVar1 = *puVar1 | uVar7;
      *(byte *)(param_1 + 0x1a) = bVar3;
    }
    if ((((g_bIsKernCZBP != '\0') && (*(int *)(param_1 + 0xf4) == 0)) &&
        (((byte)*(undefined4 *)(param_1 + 0x10) & 6) == 2)) && (*(char *)(param_1 + -8) == '\x01'))
    {
      LOCK();
      _g_lOutstandingIO = _g_lOutstandingIO | 1;
      UNLOCK();
    }
    *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x38) = uVar7;
    LOCK();
    UNLOCK();
    *(uint *)(param_1 + 0x124) = *(uint *)(param_1 + 0x124) | uVar7;
    puVar1 = (uint *)(param_1 + 0x138 + (ulonglong)bVar3 * 4);
    *puVar1 = *puVar1 | uVar7;
    if (((g_bIsKernCZBP != '\0') && (*(int *)(param_1 + 0xf4) == 0)) &&
       ((((byte)*(undefined4 *)(param_1 + 0x10) & 6) == 2 && (*(char *)(param_1 + -8) == '\x01'))))
    {
      LOCK();
      uVar5 = g_lPHYClock >> 0x1c;
      g_lPHYClock = g_lPHYClock | 0x10000000;
      UNLOCK();
      if ((uVar5 & 1) == 0) {
        StorPortSetBusDataByOffset
                  (lVar6,4,*(undefined4 *)(lVar6 + 0x24),*(undefined4 *)(lVar6 + 0x84),&g_lPHYClock,
                   0x84,4);
      }
    }
    cVar9 = cVar9 + '\x01';
    *(uint *)(param_1 + 0x18c8) = *(int *)(param_1 + 0x18c8) + 1U & 0x1f;
    LOCK();
    *(int *)(param_1 + 0x18d0) = *(int *)(param_1 + 0x18d0) + -1;
    UNLOCK();
    iVar4 = *(int *)(param_1 + 0x18d0);
  }
  return cVar9;
}



===== PresetDeviceFeature @ 1c0001874 =====

void PresetDeviceFeature(longlong param_1,byte param_2,undefined1 param_3,undefined1 param_4,
                        undefined1 param_5)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  byte *pbVar4;
  ulonglong uVar5;
  
  lVar2 = *(longlong *)(param_1 + 0x1a70 + (ulonglong)param_2 * 8);
  uVar1 = *(uint *)(lVar2 + 0x370);
  iVar3 = 0x1f;
  if (uVar1 != 0) {
    for (; uVar1 >> iVar3 == 0; iVar3 = iVar3 + -1) {
    }
  }
  if (uVar1 != 0) {
    uVar5 = (ulonglong)(iVar3 + 1U);
    if (0xf < iVar3 + 1U) {
      return;
    }
  }
  else {
    uVar5 = 0;
  }
  pbVar4 = (byte *)(lVar2 + 0x370 + ((longlong)(int)(uint)uVar5 >> 3));
  *pbVar4 = *pbVar4 | '\x01' << ((uint)uVar5 & 7);
  *(undefined8 *)(lVar2 + 0x378 + uVar5 * 8) = 0;
  *(undefined1 *)(lVar2 + 0x37e + uVar5 * 8) = param_3;
  *(undefined1 *)(lVar2 + 0x378 + uVar5 * 8) = param_4;
  *(undefined1 *)(lVar2 + 0x379 + uVar5 * 8) = param_5;
  return;
}



===== AhciHwPresetComplete @ 1c00018c4 =====

void AhciHwPresetComplete(longlong param_1,longlong param_2)

{
  byte bVar1;
  char cVar2;
  longlong lVar3;
  longlong lVar4;
  byte *pbVar5;
  ulonglong uVar6;
  
  bVar1 = *(byte *)(param_2 + 0x2b);
  uVar6 = (ulonglong)bVar1;
  lVar3 = *(longlong *)(param_2 + 8);
  lVar4 = *(longlong *)(param_1 + 0x1a70 + (ulonglong)*(byte *)(lVar3 + 6) * 8);
  pbVar5 = (byte *)(lVar4 + 0x370 + ((longlong)(int)(uint)bVar1 >> 3));
  *pbVar5 = *pbVar5 & ~('\x01' << (bVar1 & 7));
  if ((*(char *)(lVar4 + 0x37e + uVar6 * 8) == -0x11) &&
     ((*(char *)(lVar4 + 0x378 + uVar6 * 8) - 0x10U & 0x7f) == 0)) {
    cVar2 = *(char *)(lVar4 + 0x379 + uVar6 * 8);
    if (cVar2 == '\t') {
      if ((((*(char *)(lVar3 + 2) == '\x01') && (*(char *)(param_1 + 0x24) != '\0')) &&
          (*(char *)(param_1 + 0x33) != '\0')) &&
         ((*(char *)(lVar4 + 0x488) != '\0' && (*(int *)(param_1 + 0xc) == 0x101)))) {
        AhciSetDEVSLP(param_1,*(char *)(param_1 + 0x33));
      }
    }
    else if (cVar2 == '\n') {
      if (*(char *)(lVar3 + 2) != '\x01') {
        *(undefined1 *)(lVar4 + 0x495) = 0;
        return;
      }
      if (((*(int *)(param_1 + 0xc) == 0x101) && (*(char *)(lVar4 + 0x494) != '\0')) &&
         (*(char *)(lVar4 + 0x495) == '\0')) {
        *(undefined1 *)(lVar4 + 0x495) = 1;
        return;
      }
    }
  }
  return;
}



===== AhciHwPresetFeatures @ 1c000198c =====

ulonglong AhciHwPresetFeatures(longlong param_1,byte param_2)

{
  ushort *puVar1;
  int *piVar2;
  byte *pbVar3;
  char cVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  int *piVar7;
  undefined1 uVar8;
  
  piVar2 = *(int **)(param_1 + 0x1a70 + (ulonglong)param_2 * 8);
  puVar1 = (ushort *)(piVar2 + 6);
  if (puVar1 == (ushort *)0x0) {
    return (ulonglong)param_2;
  }
  cVar4 = *(char *)((longlong)piVar2 + 0x32d);
  uVar5 = 0xef;
  piVar7 = piVar2;
  PresetDeviceFeature(param_1,param_2,0xef,0x66,0);
  if (cVar4 != '\0') {
    PresetDeviceFeature(param_1,param_2,uVar5,3,cVar4);
  }
  if ((*(byte *)(piVar2 + 0x2d) & 0x40) != 0) {
    PresetDeviceFeature(param_1,param_2,0xef,0x10,6);
  }
  if (((*puVar1 & 0x8000) == 0) && ((*(byte *)(piVar2 + 0x2d) & 4) != 0)) {
    PresetDeviceFeature(param_1,param_2,0xef,0x10,2);
  }
  pbVar3 = (byte *)(param_1 + 0x1a58 + ((longlong)(int)(uint)param_2 >> 3));
  *pbVar3 = *pbVar3 & ~('\x01' << (param_2 & 7));
  if ((*(byte *)(piVar2 + 0x2d) & 8) != 0) {
    uVar5 = 0xef;
    uVar8 = 3;
    if (*(char *)((longlong)piVar7 + 0x32e) == '\0') {
      uVar6 = 0x90;
    }
    else {
      uVar6 = 0x10;
      PresetDeviceFeature(param_1,param_2,0xef,0x10,3);
      pbVar3 = (byte *)(param_1 + 0x1a58 + ((longlong)(int)(uint)param_2 >> 3));
      *pbVar3 = *pbVar3 | '\x01' << (param_2 & 7);
      if ((*(ushort *)(piVar2 + 0x2c) & 0x4000) == 0) goto LAB_1c0001aa1;
      uVar8 = 7;
    }
    PresetDeviceFeature(param_1,param_2,uVar5,uVar6,uVar8);
  }
LAB_1c0001aa1:
  if (((*(byte *)(piVar2 + 0x2f) & 0x20) != 0) && (*(char *)((longlong)piVar7 + 0x487) != '\0')) {
    PresetDeviceFeature(param_1,param_2,0xef,
                        (-(*(char *)((longlong)piVar7 + 0x486) != '\0') & 0x80U) + 0x82,0);
    *(undefined1 *)((longlong)piVar7 + 0x47f) = *(undefined1 *)((longlong)piVar7 + 0x486);
  }
  if ((*(byte *)(piVar2 + 0x2f) & 2) != 0) {
    PresetDeviceFeature(param_1,param_2,0xf5,0,0);
  }
  if ((*puVar1 & 0x8000) != 0) {
    if (((*(char *)(param_1 + 0x2e) != '\0') || ((*(byte *)(piVar2 + 0x2d) & 0x20) == 0)) ||
       (cVar4 = '\x01', *(char *)(param_1 + 0x2d) == '\0')) {
      cVar4 = '\0';
    }
    *(char *)((longlong)piVar7 + 0x47d) = cVar4;
    if (cVar4 != '\0') {
      PresetDeviceFeature(param_1,param_2,0xef,0x10,5);
    }
  }
  if (((char)piVar7[0xca] == ')') || ((char)piVar7[0xca] == -0x3c)) {
    PresetDeviceFeature(param_1,param_2,0xc6,0,*(undefined1 *)((longlong)piVar2 + 0x76));
  }
  if (*piVar7 == -0x14ebfeff) {
    uVar5 = 0xa0;
    PresetDeviceFeature(param_1,param_2,0xa0,0,0);
    PresetDeviceFeature(param_1,param_2,uVar5,3,0);
  }
  if (*(int *)(param_1 + 0xc) == 0x101) {
    if (((*(char *)(param_1 + 0x24) != '\0') && (*(char *)(param_1 + 0x33) != '\0')) &&
       ((char)piVar7[0x122] != '\0')) {
      PresetDeviceFeature(param_1,param_2,0xef,0x10,9);
    }
    if (((*(int *)(param_1 + 0xc) == 0x101) && ((char)piVar7[0x125] != '\0')) &&
       (*(char *)((longlong)piVar7 + 0x495) == '\0')) {
      PresetDeviceFeature(param_1,param_2,0xef,0x10,10);
    }
  }
  piVar7[0xdc] = piVar7[0xdc] | piVar7[0xdd];
  return (ulonglong)(uint)piVar7[0xdd];
}



===== PresetCommand @ 1c0001c30 =====

int PresetCommand(longlong param_1,ulonglong param_2,uint param_3)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  undefined1 *_Dst;
  uint *puVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  byte bVar9;
  
  uVar7 = (ulonglong)param_3;
  lVar3 = *(longlong *)(param_1 + 0x1a70 + (param_2 & 0xff) * 8);
  if (((((*(uint *)(param_1 + 0x10) & 1) == 0) ||
       (uVar2 = *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x28), ((uVar2 >> 8 | uVar2) & 0xf) == 0
       )) || (((byte)uVar2 & 0xf) == 4)) ||
     (uVar8 = uVar7, puVar5 = GetSlot(param_1), puVar5 == (undefined4 *)0x0)) {
    return 0;
  }
  _Dst = *(undefined1 **)(puVar5 + 6);
  puVar4 = *(uint **)(puVar5 + 4);
  puVar6 = (undefined2 *)(param_1 + 0x9a8 + (ulonglong)*(byte *)(puVar5 + 10) * 0x78);
  *puVar6 = 0x10;
  *(undefined4 *)(puVar6 + 0xc) = 0;
  *(undefined1 *)(puVar6 + 1) = 0;
  *(undefined1 *)((longlong)puVar6 + 5) = *(undefined1 *)(param_1 + 8);
  bVar9 = (byte)param_2;
  *(byte *)(puVar6 + 3) = bVar9;
  *(undefined2 **)(puVar5 + 2) = puVar6;
  *(byte *)((longlong)puVar5 + 0x29) = bVar9;
  *(undefined8 *)(puVar5 + 0xc) = 0;
  *(char *)((longlong)puVar5 + 0x2b) = (char)uVar8;
  memset(_Dst,0,0x80);
  _Dst[1] = _Dst[1] | 0x80;
  *_Dst = 0x27;
  _Dst[2] = *(undefined1 *)(lVar3 + 0x37e + uVar7 * 8);
  _Dst[1] = _Dst[1] ^ (_Dst[1] ^ bVar9) & 0xf;
  _Dst[3] = *(undefined1 *)(lVar3 + 0x378 + uVar7 * 8);
  _Dst[0xc] = *(undefined1 *)(lVar3 + 0x379 + uVar7 * 8);
  *puVar4 = 5;
  cVar1 = _Dst[2];
  puVar4[1] = 0;
  *puVar4 = ((uint)(cVar1 == -0x60) | ((uint)param_2 & 0xf) << 7) << 5 | 5;
  if (cVar1 == -0x60) {
    if (_Dst[3] == '\x03') {
      *(undefined4 *)(puVar6 + 0xc) = 0x14;
      *(undefined2 *)((longlong)puVar6 + 0x65) = 0;
      *(undefined1 *)((longlong)puVar6 + 0x67) = 0;
      *(undefined1 *)(puVar6 + 0x32) = 3;
      *(undefined1 *)((longlong)puVar6 + 0x69) = 0;
      *(undefined1 *)(puVar6 + 0x34) = *(undefined1 *)(puVar6 + 0xc);
      memcpy(_Dst + 0x40,puVar6 + 0x32,0x10);
      *(undefined4 *)(_Dst + 0x80) = *(undefined4 *)(param_1 + 0x1910);
      if (*(int *)(param_1 + 0x18f8) < 0) {
        *(undefined4 *)(_Dst + 0x84) = *(undefined4 *)(param_1 + 0x1914);
      }
      *(uint *)(_Dst + 0x8c) =
           *(uint *)(_Dst + 0x8c) ^
           (*(int *)(puVar6 + 0xc) - 1U ^ *(uint *)(_Dst + 0x8c)) & 0x3fffff;
      *(undefined2 *)((longlong)puVar4 + 2) = 1;
      puVar4[2] = puVar5[8];
      puVar4[3] = puVar5[9];
      _Dst[4] = 0;
      _Dst[5] = *(undefined1 *)(puVar6 + 0xc);
      _Dst[6] = (char)((uint)*(undefined4 *)(puVar6 + 0xc) >> 8);
      _Dst[7] = 0;
    }
    else {
      *(undefined4 *)(puVar6 + 0x32) = 0;
      puVar6[0x34] = 0;
    }
    _Dst[3] = (*(byte *)(lVar3 + 0x32d) & 0xf0) != 0;
  }
  puVar4[4] = 0;
  puVar4[5] = 0;
  puVar4[6] = 0;
  puVar4[7] = 0;
  *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x18cc) + 0x18a8 + param_1) =
       *(undefined1 *)(puVar5 + 10);
  *(uint *)(param_1 + 0x18cc) = *(int *)(param_1 + 0x18cc) + 1U & 0x1f;
  LOCK();
  *(int *)(param_1 + 0x18d0) = *(int *)(param_1 + 0x18d0) + 1;
  UNLOCK();
  return 1 << (*(byte *)(puVar5 + 10) & 0x1f);
}



===== ReadLogExt @ 1c0001e7c =====

undefined4 ReadLogExt(longlong param_1,byte param_2)

{
  uint uVar1;
  undefined1 *_Dst;
  uint *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined2 *puVar5;
  
  if (*(char *)(param_1 + 0x1a30) == '\0') {
    if ((*(uint *)(param_1 + 0x10) & 1) == 0) {
      uVar3 = 0xffffffff;
    }
    else {
      uVar1 = *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x28);
      if ((((uVar1 >> 8 | uVar1) & 0xf) == 0) || (((byte)uVar1 & 0xf) == 4)) {
        uVar3 = 0xfffffffe;
      }
      else {
        puVar4 = GetSlot(param_1);
        if (puVar4 == (undefined4 *)0x0) {
          uVar3 = 0xfffffffd;
        }
        else {
          *(undefined1 *)(param_1 + 0x1a30) = 1;
          puVar5 = (undefined2 *)(param_1 + 0x9a8 + (ulonglong)*(byte *)(puVar4 + 10) * 0x78);
          *puVar5 = 0x11;
          *(undefined1 *)(puVar5 + 1) = 0;
          *(byte *)(puVar5 + 3) = param_2;
          *(undefined4 *)(puVar5 + 0xc) = 0x200;
          _Dst = *(undefined1 **)(puVar4 + 6);
          puVar2 = *(uint **)(puVar4 + 4);
          memset(_Dst,0,0x80);
          *(undefined4 *)(_Dst + 0x80) = *(undefined4 *)(param_1 + 0x1910);
          if (*(int *)(param_1 + 0x18f8) < 0) {
            *(undefined4 *)(_Dst + 0x84) = *(undefined4 *)(param_1 + 0x1914);
          }
          *(uint *)(_Dst + 0x8c) =
               *(uint *)(_Dst + 0x8c) ^
               (*(int *)(puVar5 + 0xc) - 1U ^ *(uint *)(_Dst + 0x8c)) & 0x3fffff;
          *_Dst = 0x27;
          _Dst[2] = 0x2f;
          _Dst[0xc] = 1;
          _Dst[1] = _Dst[1] & 0xf0 | param_2 & 0xf | 0x80;
          _Dst[4] = 0x10;
          *(undefined8 *)(puVar4 + 0xc) = 0;
          *(undefined2 **)(puVar4 + 2) = puVar5;
          *(byte *)((longlong)puVar4 + 0x29) = param_2;
          *puVar2 = 0;
          puVar2[1] = 0;
          *(undefined2 *)((longlong)puVar2 + 2) = 1;
          *puVar2 = (param_2 & 0xf) << 0xc | *puVar2 & 0xffff0fe5 | 5;
          puVar2[4] = 0;
          puVar2[5] = 0;
          puVar2[6] = 0;
          puVar2[7] = 0;
          *(undefined1 *)((ulonglong)*(uint *)(param_1 + 0x18cc) + 0x18a8 + param_1) =
               *(undefined1 *)(puVar4 + 10);
          *(uint *)(param_1 + 0x18cc) = *(int *)(param_1 + 0x18cc) + 1U & 0x1f;
          LOCK();
          *(int *)(param_1 + 0x18d0) = *(int *)(param_1 + 0x18d0) + 1;
          UNLOCK();
          Actuate(param_1);
          uVar3 = 1;
        }
      }
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



===== DepleteWorkerDispatch @ 1c0002040 =====

ulonglong DepleteWorkerDispatch(longlong param_1)

{
  longlong lVar1;
  ushort *puVar2;
  byte *pbVar3;
  ulonglong uVar4;
  char cVar5;
  uint uVar6;
  undefined7 extraout_var;
  ulonglong uVar7;
  byte bVar8;
  ulonglong uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  uint local_res8;
  uint local_res10;
  int local_res18;
  int local_res20 [2];
  int local_58;
  int local_54;
  uint local_50;
  uint local_4c;
  
  local_54 = *(int *)(param_1 + 0x128);
  uVar9 = (ulonglong)*(byte *)(param_1 + 0x18d8);
  uVar6 = (uint)*(byte *)(param_1 + 0x1a);
  local_res20[0] = *(int *)(param_1 + 0x124);
  uVar11 = *(uint *)(param_1 + 0x1a44);
  uVar12 = 0;
  if (uVar11 != 0) {
    for (; (uVar11 >> uVar12 & 1) == 0; uVar12 = uVar12 + 1) {
    }
  }
  local_res18 = 0;
  uVar7 = (ulonglong)(uVar12 & 0xff);
  local_res10 = (uint)*(byte *)(param_1 + 0x1a);
  if (uVar11 != 0) {
    uVar9 = (ulonglong)(uVar12 & 0xff);
  }
  bVar8 = (byte)uVar9;
  LOCK();
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xffffffef;
  UNLOCK();
  if ((*(uint *)(param_1 + 0x10) >> 3 & 1) == 0) {
    uVar4 = 0;
    iVar10 = 0;
    if (*(int *)(param_1 + 0x18d4) != 0) {
      while( true ) {
        uVar7 = uVar4;
        bVar8 = (byte)uVar9;
        uVar11 = (uint)uVar7;
        if (*(byte *)(param_1 + 0x2c) <= uVar11) break;
        cVar5 = '\0';
        lVar1 = *(longlong *)(param_1 + 0x1a70 + uVar9 * 8);
        uVar12 = (uint)uVar9;
        if ((lVar1 != 0) && ((*(uint *)(lVar1 + 0x218) & 1) == 0)) {
          local_res8 = *(uint *)(param_1 + 0x174 + uVar9 * 4);
          local_58 = *(int *)(param_1 + 0x138 + uVar9 * 4);
          local_50 = local_res8;
          if (*(int *)(lVar1 + 0x21c) != 0) {
            do {
              local_4c = *(uint *)(lVar1 + 0x224);
              uVar7 = (ulonglong)local_4c;
              puVar2 = *(ushort **)(lVar1 + 0x228 + uVar7 * 8);
              uVar13 = *(uint *)(puVar2 + 8) & 0x20000;
              if (local_res8 == 0) {
                if ((local_58 != 0) && (uVar13 != 0)) break;
              }
              else if (uVar13 == 0) break;
              if ((*(int *)(param_1 + 0xc) == -0x6996feff) && (*(char *)(param_1 + 0x1f) == '\0')) {
                if (local_54 == 0) {
                  if (local_res20[0] == 0) goto LAB_1c000219a;
                  bVar14 = uVar13 == 0;
                }
                else {
                  if (uVar13 == 0) goto LAB_1c0002246;
                  bVar14 = uVar6 == uVar12;
                }
                if (!bVar14) goto LAB_1c0002246;
              }
LAB_1c000219a:
              cVar5 = Irb2Slot(param_1,puVar2,(ulonglong)local_res8);
              uVar7 = CONCAT71(extraout_var,cVar5);
              if (cVar5 == ' ') goto LAB_1c0002246;
              if (-1 < cVar5) {
                local_res18 = local_res18 + 1;
                uVar6 = (uint)cVar5;
                pbVar3 = (byte *)((longlong)local_res20 + ((longlong)(int)uVar6 >> 3));
                *pbVar3 = *pbVar3 | '\x01' << (uVar6 & 7);
                pbVar3 = (byte *)((longlong)local_res20 + ((longlong)(int)uVar6 >> 3) + -0x78);
                *pbVar3 = *pbVar3 | '\x01' << (uVar6 & 7);
                if (uVar13 != 0) {
                  pbVar3 = (byte *)((longlong)local_res20 + ((longlong)(int)uVar6 >> 3) + -0x74);
                  *pbVar3 = *pbVar3 | '\x01' << (uVar6 & 7);
                  pbVar3 = (byte *)((longlong)&local_50 + ((longlong)(int)uVar6 >> 3));
                  *pbVar3 = *pbVar3 | '\x01' << (uVar6 & 7);
                  local_res8 = local_50;
                  local_res10 = uVar12;
                }
              }
              *(int *)(lVar1 + 0x21c) = *(int *)(lVar1 + 0x21c) + -1;
              uVar6 = local_4c + 1 & 0x1f;
              uVar7 = (ulonglong)uVar6;
              *(uint *)(lVar1 + 0x224) = uVar6;
              *(int *)(param_1 + 0x18d4) = *(int *)(param_1 + 0x18d4) + -1;
              *(uint *)(param_1 + 0x1a44) = *(uint *)(param_1 + 0x1a44) & ~(1 << (bVar8 & 0x1f));
              uVar6 = local_res10;
            } while (*(int *)(lVar1 + 0x21c) != 0);
            if (cVar5 == ' ') break;
          }
        }
        uVar7 = (ulonglong)(uVar12 + 1) / (ulonglong)(longlong)(int)(uint)*(byte *)(param_1 + 0x2c);
        uVar9 = (ulonglong)(uVar12 + 1) % (ulonglong)(longlong)(int)(uint)*(byte *)(param_1 + 0x2c);
        bVar8 = (byte)uVar9;
        uVar4 = (ulonglong)(uVar11 + 1);
        if (*(int *)(param_1 + 0x18d4) == 0) break;
      }
LAB_1c0002246:
      iVar10 = local_res18;
    }
    *(byte *)(param_1 + 0x18d8) = bVar8;
    if (iVar10 != 0) {
      uVar7 = AhciPortRequestSynchronizedRoutine(param_1,Actuate);
    }
  }
  return uVar7;
}



===== AtaStandbyImmediate @ 1c0002280 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong AtaStandbyImmediate(longlong param_1,undefined2 *param_2)

{
  byte bVar1;
  ushort *puVar2;
  uint *puVar3;
  longlong lVar4;
  ushort uVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  longlong lVar9;
  longlong lVar10;
  
  *(undefined1 *)(param_2 + 0x35) = 0xe0;
  lVar10 = (ulonglong)*(byte *)((longlong)param_2 + 0xb) * 0x38 + param_1;
  *param_2 = 0x100;
  *(undefined8 *)(param_2 + 0x18) = 0;
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(undefined1 *)(param_2 + 1) = 0;
  *(undefined4 *)(param_2 + 0x30) = 5;
  IRBtoATA_CFIS(param_1,(uint *)(lVar10 + 0x2a8));
  puVar2 = *(ushort **)(lVar10 + 0x2b0);
  puVar3 = *(uint **)(lVar10 + 0x2b8);
  *puVar3 = 0;
  *(undefined2 *)((longlong)puVar3 + 2) = 0;
  uVar6 = *puVar3 & 0xffffffe5 | 5;
  *puVar3 = uVar6;
  uVar6 = (*puVar2 >> 4 ^ uVar6) & 0x20 ^ uVar6;
  *puVar3 = uVar6;
  uVar6 = (*(uint *)(puVar2 + 8) >> 1 ^ uVar6) & 0x40 ^ uVar6;
  *puVar3 = uVar6;
  uVar5 = puVar2[3];
  puVar3[1] = 0;
  *puVar3 = ((uint)(byte)uVar5 << 0xc ^ uVar6) & 0xf000 ^ uVar6;
  puVar3[4] = 0;
  puVar3[5] = 0;
  puVar3[6] = 0;
  puVar3[7] = 0;
  lVar4 = *(longlong *)(param_1 + -0x98);
  lVar9 = (ulonglong)*(byte *)(lVar10 + 0x2d0) * 0x38;
  uVar6 = *(uint *)(lVar9 + 0x2a8 + param_1);
  bVar1 = *(byte *)(lVar9 + 0x2d1 + param_1);
  uVar8 = 1 << (*(byte *)(lVar10 + 0x2d0) & 0x1f);
  if ((*(char *)(param_1 + 0x1f) != '\0') && (*(byte *)(param_1 + 0x1b) != bVar1)) {
    *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x40) = (bVar1 & 0xf) << 8 | 1;
    LOCK();
    UNLOCK();
    *(byte *)(param_1 + 0x1b) = bVar1;
  }
  if ((uVar6 & 0x20000) != 0) {
    *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x34) = uVar8;
    LOCK();
    UNLOCK();
    *(uint *)(param_1 + 0x128) = *(uint *)(param_1 + 0x128) | uVar8;
    puVar3 = (uint *)(param_1 + 0x174 + (ulonglong)bVar1 * 4);
    *puVar3 = *puVar3 | uVar8;
    *(byte *)(param_1 + 0x1a) = bVar1;
  }
  if ((((g_bIsKernCZBP != '\0') && (*(int *)(param_1 + 0xf4) == 0)) &&
      (((byte)*(undefined4 *)(param_1 + 0x10) & 6) == 2)) && (*(char *)(param_1 + -8) == '\x01')) {
    LOCK();
    _g_lOutstandingIO = _g_lOutstandingIO | 1;
    UNLOCK();
  }
  *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x38) = uVar8;
  LOCK();
  UNLOCK();
  *(uint *)(param_1 + 0x124) = *(uint *)(param_1 + 0x124) | uVar8;
  puVar7 = (undefined4 *)(ulonglong)bVar1;
  puVar3 = (uint *)(param_1 + 0x138 + (longlong)puVar7 * 4);
  *puVar3 = *puVar3 | uVar8;
  if (((g_bIsKernCZBP != '\0') && (*(int *)(param_1 + 0xf4) == 0)) &&
     ((puVar7 = (undefined4 *)((ulonglong)*(uint *)(param_1 + 0x10) & 0xffffffffffffff06),
      (char)puVar7 == '\x02' && (*(char *)(param_1 + -8) == '\x01')))) {
    puVar7 = &g_lPHYClock;
    LOCK();
    uVar6 = g_lPHYClock >> 0x1c;
    g_lPHYClock = g_lPHYClock | 0x10000000;
    UNLOCK();
    if ((uVar6 & 1) == 0) {
      puVar7 = (undefined4 *)
               StorPortSetBusDataByOffset
                         (lVar4,4,*(undefined4 *)(lVar4 + 0x24),*(undefined4 *)(lVar4 + 0x84),
                          &g_lPHYClock,0x84,4);
    }
  }
  return (ulonglong)puVar7 & 0xffffffffffffff00;
}



===== AtaGtf @ 1c0002464 =====

undefined8 AtaGtf(longlong param_1,undefined2 *param_2)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  uint uVar4;
  byte *pbVar5;
  
  lVar2 = *(longlong *)(param_1 + 0x1a70 + (ulonglong)*(byte *)(param_2 + 3) * 8);
  uVar1 = *(uint *)(lVar2 + 0x370);
  uVar4 = 0;
  if (uVar1 != 0) {
    for (; (uVar1 >> uVar4 & 1) == 0; uVar4 = uVar4 + 1) {
    }
  }
  if (uVar1 != 0) {
    pbVar5 = (byte *)(lVar2 + 0x370 + ((longlong)(int)uVar4 >> 3));
    *pbVar5 = *pbVar5 & ~('\x01' << (uVar4 & 7));
    *(undefined4 *)(param_2 + 0x30) = 5;
    *param_2 = 0x100;
    uVar3 = *(undefined8 *)(lVar2 + 0x378 + (ulonglong)uVar4 * 8);
    *(undefined4 *)(param_2 + 0xc) = 0;
    *(undefined8 *)(param_2 + 0x32) = uVar3;
    *(undefined1 *)(param_2 + 1) = 0;
    *(ulonglong *)(param_2 + 0x18) = -(ulonglong)(*(int *)(lVar2 + 0x370) != 0) & 0x1c00024d0;
    return 0x1c0002401;
  }
  return 0;
}



===== AtaGtfCompletion @ 1c00024d0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong AtaGtfCompletion(longlong param_1,undefined2 *param_2)

{
  byte bVar1;
  ushort *puVar2;
  uint *puVar3;
  longlong lVar4;
  ushort uVar5;
  uint uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined4 *puVar9;
  uint uVar10;
  longlong lVar11;
  longlong lVar12;
  
  uVar7 = AtaGtf(param_1,param_2);
  if ((char)uVar7 == '\0') {
    uVar8 = CONCAT71((int7)((ulonglong)uVar7 >> 8),1);
  }
  else {
    lVar12 = (ulonglong)*(byte *)((longlong)param_2 + 0xb) * 0x38 + param_1;
    IRBtoATA_CFIS(param_1,(uint *)(lVar12 + 0x2a8));
    puVar2 = *(ushort **)(lVar12 + 0x2b0);
    puVar3 = *(uint **)(lVar12 + 0x2b8);
    *puVar3 = 0;
    *(undefined2 *)((longlong)puVar3 + 2) = 0;
    uVar6 = *puVar3 & 0xffffffe5 | 5;
    *puVar3 = uVar6;
    uVar6 = (*puVar2 >> 4 ^ uVar6) & 0x20 ^ uVar6;
    *puVar3 = uVar6;
    uVar6 = (*(uint *)(puVar2 + 8) >> 1 ^ uVar6) & 0x40 ^ uVar6;
    *puVar3 = uVar6;
    uVar5 = puVar2[3];
    puVar3[1] = 0;
    *puVar3 = ((uint)(byte)uVar5 << 0xc ^ uVar6) & 0xf000 ^ uVar6;
    puVar3[4] = 0;
    puVar3[5] = 0;
    puVar3[6] = 0;
    puVar3[7] = 0;
    lVar4 = *(longlong *)(param_1 + -0x98);
    lVar11 = (ulonglong)*(byte *)(lVar12 + 0x2d0) * 0x38;
    uVar6 = *(uint *)(lVar11 + 0x2a8 + param_1);
    bVar1 = *(byte *)(lVar11 + 0x2d1 + param_1);
    uVar10 = 1 << (*(byte *)(lVar12 + 0x2d0) & 0x1f);
    if ((*(char *)(param_1 + 0x1f) != '\0') && (*(byte *)(param_1 + 0x1b) != bVar1)) {
      *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x40) = (bVar1 & 0xf) << 8 | 1;
      LOCK();
      UNLOCK();
      *(byte *)(param_1 + 0x1b) = bVar1;
    }
    if ((uVar6 & 0x20000) != 0) {
      *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x34) = uVar10;
      LOCK();
      UNLOCK();
      *(uint *)(param_1 + 0x128) = *(uint *)(param_1 + 0x128) | uVar10;
      puVar3 = (uint *)(param_1 + 0x174 + (ulonglong)bVar1 * 4);
      *puVar3 = *puVar3 | uVar10;
      *(byte *)(param_1 + 0x1a) = bVar1;
    }
    if ((((g_bIsKernCZBP != '\0') && (*(int *)(param_1 + 0xf4) == 0)) &&
        (((byte)*(undefined4 *)(param_1 + 0x10) & 6) == 2)) && (*(char *)(param_1 + -8) == '\x01'))
    {
      LOCK();
      _g_lOutstandingIO = _g_lOutstandingIO | 1;
      UNLOCK();
    }
    *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x38) = uVar10;
    LOCK();
    UNLOCK();
    *(uint *)(param_1 + 0x124) = *(uint *)(param_1 + 0x124) | uVar10;
    puVar9 = (undefined4 *)(ulonglong)bVar1;
    puVar3 = (uint *)(param_1 + 0x138 + (longlong)puVar9 * 4);
    *puVar3 = *puVar3 | uVar10;
    if (((g_bIsKernCZBP != '\0') && (*(int *)(param_1 + 0xf4) == 0)) &&
       ((puVar9 = (undefined4 *)((ulonglong)*(uint *)(param_1 + 0x10) & 0xffffffffffffff06),
        (char)puVar9 == '\x02' && (*(char *)(param_1 + -8) == '\x01')))) {
      puVar9 = &g_lPHYClock;
      LOCK();
      uVar6 = g_lPHYClock >> 0x1c;
      g_lPHYClock = g_lPHYClock | 0x10000000;
      UNLOCK();
      if ((uVar6 & 1) == 0) {
        puVar9 = (undefined4 *)
                 StorPortSetBusDataByOffset
                           (lVar4,4,*(undefined4 *)(lVar4 + 0x24),*(undefined4 *)(lVar4 + 0x84),
                            &g_lPHYClock,0x84,4);
      }
    }
    uVar8 = (ulonglong)puVar9 & 0xffffffffffffff00;
  }
  return uVar8;
}



===== Lba28CompletionRoutine @ 1c00026b0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
Lba28CompletionRoutine(longlong param_1,longlong param_2,undefined8 param_3,ulonglong param_4)

{
  byte bVar1;
  ushort *puVar2;
  uint *puVar3;
  ushort uVar4;
  uint uVar5;
  ulonglong in_RAX;
  longlong lVar6;
  ulonglong uVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  longlong lVar11;
  longlong lVar12;
  undefined1 uStackX_11;
  undefined1 uStackX_19;
  undefined1 uStackX_1a;
  undefined1 uStackX_1b;
  undefined1 uStackX_1c;
  undefined1 uStackX_1d;
  
  if (*(char *)(param_2 + 2) == '\x01') {
    uVar5 = *(uint *)(param_2 + 0x20);
    uVar7 = (ulonglong)uVar5;
    *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + *(int *)(param_2 + 0x18);
    lVar12 = (ulonglong)*(byte *)(param_2 + 0xb) * 0x38 + param_1;
    uVar10 = *(uint *)(param_2 + 0xc);
    in_RAX = (ulonglong)uVar10;
    uVar9 = uVar5 - uVar10;
    if (uVar9 != 0) {
      *(undefined1 *)(param_2 + 2) = 0;
      if (0x20000 < uVar9) {
        uVar9 = 0x20000;
      }
      lVar6 = (ulonglong)(uVar10 >> 9) + *(longlong *)(param_2 + 0x28);
      *(uint *)(param_2 + 0x18) = uVar9;
      *(char *)(param_2 + 0x66) = (char)lVar6;
      uStackX_19 = (undefined1)((ulonglong)lVar6 >> 8);
      *(undefined1 *)(param_2 + 0x67) = uStackX_19;
      uStackX_1a = (undefined1)((ulonglong)lVar6 >> 0x10);
      *(undefined1 *)(param_2 + 0x68) = uStackX_1a;
      uStackX_1b = (undefined1)((ulonglong)lVar6 >> 0x18);
      *(undefined1 *)(param_2 + 0x6e) = uStackX_1b;
      uStackX_1c = (undefined1)((ulonglong)lVar6 >> 0x20);
      *(undefined1 *)(param_2 + 0x6f) = uStackX_1c;
      uStackX_1d = (undefined1)((ulonglong)lVar6 >> 0x28);
      *(undefined1 *)(param_2 + 0x70) = uStackX_1d;
      uStackX_11 = (undefined1)((uVar9 >> 9) >> 8);
      *(char *)(param_2 + 0x65) = (char)(uVar9 >> 9);
      *(undefined1 *)(param_2 + 0x6d) = uStackX_11;
      *(undefined1 *)(param_2 + 100) = 0;
      *(undefined1 *)(param_2 + 0x69) = 0;
      *(undefined1 *)(param_2 + 0x6c) = 0;
      *(undefined1 *)(param_2 + 0x71) = 0;
      IRBtoATA_CFIS(param_1,(uint *)(lVar12 + 0x2a8));
      uVar7 = IRBtoPRDT(param_1,lVar12 + 0x2a8,uVar7,param_4);
      puVar2 = *(ushort **)(lVar12 + 0x2b0);
      puVar3 = *(uint **)(lVar12 + 0x2b8);
      *puVar3 = 0;
      *(short *)((longlong)puVar3 + 2) = (short)uVar7;
      uVar5 = *puVar3 & 0xffffffe5 | 5;
      *puVar3 = uVar5;
      uVar5 = (*puVar2 >> 4 ^ uVar5) & 0x20 ^ uVar5;
      *puVar3 = uVar5;
      uVar5 = (*(uint *)(puVar2 + 8) >> 1 ^ uVar5) & 0x40 ^ uVar5;
      *puVar3 = uVar5;
      uVar4 = puVar2[3];
      puVar3[1] = 0;
      *puVar3 = ((uint)(byte)uVar4 << 0xc ^ uVar5) & 0xf000 ^ uVar5;
      puVar3[4] = 0;
      puVar3[5] = 0;
      puVar3[6] = 0;
      puVar3[7] = 0;
      lVar6 = *(longlong *)(param_1 + -0x98);
      lVar11 = (ulonglong)*(byte *)(lVar12 + 0x2d0) * 0x38;
      uVar5 = *(uint *)(lVar11 + 0x2a8 + param_1);
      bVar1 = *(byte *)(lVar11 + 0x2d1 + param_1);
      uVar10 = 1 << (*(byte *)(lVar12 + 0x2d0) & 0x1f);
      if ((*(char *)(param_1 + 0x1f) != '\0') && (*(byte *)(param_1 + 0x1b) != bVar1)) {
        *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x40) = (bVar1 & 0xf) << 8 | 1;
        LOCK();
        UNLOCK();
        *(byte *)(param_1 + 0x1b) = bVar1;
      }
      if ((uVar5 & 0x20000) != 0) {
        *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x34) = uVar10;
        LOCK();
        UNLOCK();
        *(uint *)(param_1 + 0x128) = *(uint *)(param_1 + 0x128) | uVar10;
        puVar3 = (uint *)(param_1 + 0x174 + (ulonglong)bVar1 * 4);
        *puVar3 = *puVar3 | uVar10;
        *(byte *)(param_1 + 0x1a) = bVar1;
      }
      if ((((g_bIsKernCZBP != '\0') && (*(int *)(param_1 + 0xf4) == 0)) &&
          (((byte)*(undefined4 *)(param_1 + 0x10) & 6) == 2)) && (*(char *)(param_1 + -8) == '\x01')
         ) {
        LOCK();
        _g_lOutstandingIO = _g_lOutstandingIO | 1;
        UNLOCK();
      }
      *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x38) = uVar10;
      LOCK();
      UNLOCK();
      *(uint *)(param_1 + 0x124) = *(uint *)(param_1 + 0x124) | uVar10;
      puVar8 = (undefined4 *)(ulonglong)bVar1;
      puVar3 = (uint *)(param_1 + 0x138 + (longlong)puVar8 * 4);
      *puVar3 = *puVar3 | uVar10;
      if (((g_bIsKernCZBP != '\0') && (*(int *)(param_1 + 0xf4) == 0)) &&
         ((puVar8 = (undefined4 *)((ulonglong)*(uint *)(param_1 + 0x10) & 0xffffffffffffff06),
          (char)puVar8 == '\x02' && (*(char *)(param_1 + -8) == '\x01')))) {
        puVar8 = &g_lPHYClock;
        LOCK();
        uVar5 = g_lPHYClock >> 0x1c;
        g_lPHYClock = g_lPHYClock | 0x10000000;
        UNLOCK();
        if ((uVar5 & 1) == 0) {
          puVar8 = (undefined4 *)
                   StorPortSetBusDataByOffset
                             (lVar6,4,*(undefined4 *)(lVar6 + 0x24),*(undefined4 *)(lVar6 + 0x84),
                              &g_lPHYClock,0x84,4);
        }
      }
      return (ulonglong)puVar8 & 0xffffffffffffff00;
    }
    *(uint *)(param_2 + 0x18) = uVar5;
    *(undefined8 *)(param_2 + 0x30) = 0;
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== AhciHwStartIo @ 1c0002910 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 AhciHwStartIo(longlong param_1,ushort *param_2)

{
  uint *puVar1;
  byte bVar2;
  ushort uVar3;
  int *piVar4;
  byte *pbVar5;
  byte bVar6;
  undefined1 uVar7;
  char cVar8;
  int iVar9;
  uint uVar10;
  code *pcVar11;
  ulonglong uVar12;
  undefined8 uVar13;
  undefined7 extraout_var;
  ulonglong uVar14;
  byte bVar15;
  ushort *puVar16;
  int iVar17;
  ulonglong uVar18;
  byte bVar19;
  bool bVar20;
  bool bVar21;
  undefined8 local_res8;
  undefined8 local_res10;
  undefined8 local_res18;
  
  bVar6 = (byte)param_2[3];
  uVar14 = (ulonglong)bVar6;
  iVar17 = 0;
  uVar18 = (ulonglong)bVar6;
  piVar4 = *(int **)(param_1 + 0x1a70 + uVar14 * 8);
  if ((piVar4 == (int *)0x0) || ((*(uint *)(param_1 + 0x10) & 1) == 0)) {
    *(undefined1 *)(param_2 + 1) = 6;
  }
  else {
    uVar3 = *param_2;
    uVar10 = 0x20000;
    puVar16 = param_2;
    if (uVar3 == 0x102) {
      local_res8._0_4_ = CONCAT13((char)param_2[0x37],*(undefined3 *)(param_2 + 0x33));
      local_res8 = (ulonglong)
                   CONCAT15((char)param_2[0x38],
                            CONCAT14(*(undefined1 *)((longlong)param_2 + 0x6f),
                                     (undefined4)local_res8));
      *(ulonglong *)(param_2 + 0x14) = local_res8;
      if (local_res8 <= *(ulonglong *)(piVar4 + 4)) {
        *(char *)(param_2 + 0x35) = (char)piVar4[0xca];
        if ((char)piVar4[0x11f] != '\0') {
          *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) | 0x20000;
          *(undefined1 *)(param_2 + 0x35) = 0x60;
        }
        *(longlong *)(piVar4 + 0xce) = *(longlong *)(piVar4 + 0xce) + 1;
LAB_1c0002a59:
        if ((*(char *)((longlong)piVar4 + 0x47b) == '\0') && (0x20000 < *(uint *)(param_2 + 0xc))) {
          *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0xc);
          *(code **)(param_2 + 0x18) = Lba28CompletionRoutine;
          param_2[0xc] = 0;
          param_2[0xd] = 2;
          *(ulonglong *)(param_2 + 0x14) = local_res8;
          *(undefined1 *)((longlong)param_2 + 0x65) = 0;
        }
        goto LAB_1c0002e5c;
      }
    }
    else {
      if (uVar3 != 0x103) {
        puVar16 = (ushort *)0x104;
        if (uVar3 == 0x104) {
          if (((short)piVar4[0x11e] == 0x104) ||
             (((((short)piVar4[0x11e] == 0x100 && (*(char *)((longlong)piVar4 + 0x47a) == -0x20)) ||
               (*(char *)((longlong)piVar4 + 0x47e) == '\0')) ||
              (*(char *)((longlong)piVar4 + 0x47f) == '\0')))) goto LAB_1c0002afe;
          puVar16 = (ushort *)0x101;
          if ((*piVar4 == 0x101) && (*(char *)((longlong)piVar4 + 0x32b) != '\0')) {
            *(char *)(param_2 + 0x35) = *(char *)((longlong)piVar4 + 0x32b);
          }
          else {
            *(undefined1 *)(param_2 + 4) = 10;
            *param_2 = 0x200;
            *(undefined1 *)(param_2 + 0x32) = 0x35;
          }
          *(longlong *)(piVar4 + 0xd4) = *(longlong *)(piVar4 + 0xd4) + 1;
        }
        else {
          if (uVar3 != 0x111) {
            if (uVar3 == 0x113) {
              piVar4[0x86] = piVar4[0x86] & 0xfffffffe;
              LOCK();
              puVar1 = (uint *)(param_1 + 0x10);
              uVar10 = *puVar1;
              *puVar1 = *puVar1 | 0x10;
              UNLOCK();
              if ((uVar10 >> 4 & 1) == 0) {
                ChannelWorkerDpcRoutine(param_1,(undefined *)0x104);
              }
            }
            else {
              if (uVar3 != 0x115) {
                if (uVar3 == 0x901) {
                  *(undefined1 *)(param_2 + 0x35) = 0xec;
                  pcVar11 = AtaInquiryCompetion;
                }
                else {
                  if (uVar3 != 0x117) {
                    if (uVar3 == 0x11a) {
                      puVar16 = param_2;
                      iVar17 = 0;
                      uVar10 = 0x20000;
                      uVar13 = AtaGtf(param_1,param_2);
                      if ((char)uVar13 == '\0') {
                        *(undefined1 *)(param_2 + 1) = 1;
                        param_2 = puVar16;
                        goto LAB_1c0002faf;
                      }
                    }
                    else if (uVar3 == 0x402) {
                      puVar16 = (ushort *)0x101;
                      if (*(int *)(param_2 + 8) == 0) {
                        if (*piVar4 != 0x101) goto LAB_1c0002e3f;
LAB_1c0002e31:
                        *(undefined1 *)(param_2 + 0x35) = 0xe0;
                        *param_2 = 0x100;
                      }
                      else {
                        if (*piVar4 != 0x101) {
LAB_1c0002e3f:
                          *(undefined1 *)(param_2 + 4) = 6;
                          *param_2 = 0x200;
                          param_2[0x32] = 0x11b;
LAB_1c0002e51:
                          pcVar11 = AtaStandbyImmediate;
                          goto LAB_1c0002e58;
                        }
                        if (((*(byte *)(piVar4 + 0x2d) & 0x40) == 0) ||
                           (((byte)(&AmdSataSWSP)[(longlong)(int)*(uint *)(param_1 + 8) >> 3] >>
                             (*(uint *)(param_1 + 8) & 7) & 1) != 0)) {
                          if (((byte)(&AmdSataSI)[(longlong)(int)*(uint *)(param_1 + 8) >> 3] >>
                               (*(uint *)(param_1 + 8) & 7) & 1) != 0) goto LAB_1c0002e31;
                        }
                        else {
                          *(undefined1 *)(param_2 + 0x35) = 0xef;
                          *param_2 = 0x100;
                          param_2[0x32] = 0x690;
                          if (((byte)(&AmdSataSI)[(longlong)(int)*(uint *)(param_1 + 8) >> 3] >>
                               (*(uint *)(param_1 + 8) & 7) & 1) != 0) goto LAB_1c0002e51;
                        }
                      }
                    }
                    goto LAB_1c0002e5c;
                  }
                  bVar2 = *(byte *)((longlong)param_2 + 0x65);
                  bVar21 = false;
                  uVar3 = param_2[0x35];
                  uVar10 = *(uint *)(param_1 + 0x18f8);
                  bVar19 = (byte)param_2[0x32] | bVar2;
                  if ((((uVar10 >> 0x1a & 1) == 0) || (*piVar4 == 0)) ||
                     (*(char *)(param_1 + 0x23) != '\0')) {
                    bVar21 = false;
                  }
                  else {
                    if ((((piVar4 == (int *)0xffffffffffffff50) ||
                         ((*(byte *)(piVar4 + 0x2d) & 8) == 0)) || (bVar19 == 0)) ||
                       (((bVar15 = bVar19, (uVar10 >> 0xe & 1) == 0 || ((bVar19 & 1) == 0)) &&
                        (((uVar10 >> 0xd & 1) == 0 || ((bVar19 & 2) == 0)))))) {
                      bVar15 = 0;
                    }
                    *(byte *)((longlong)piVar4 + 0x32e) = bVar15;
                    uVar10 = (uint)bVar6;
                    if (bVar15 == 0) {
                      pbVar5 = (byte *)(param_1 + 0x1a58 + ((longlong)(int)uVar10 >> 3));
                      bVar6 = *pbVar5;
                      *pbVar5 = *pbVar5 & ~('\x01' << (uVar10 & 7));
                      bVar21 = (bVar6 >> (uVar10 & 7) & 1) != 0;
                    }
                    else {
                      pbVar5 = (byte *)(param_1 + 0x1a58 + ((longlong)(int)uVar10 >> 3));
                      bVar6 = *pbVar5;
                      *pbVar5 = *pbVar5 | '\x01' << (uVar10 & 7);
                      if ((bVar6 >> (uVar10 & 7) & 1) == 0) {
                        bVar21 = true;
                      }
                    }
                  }
                  uVar12 = AhciChannelIpm(param_1,(byte)uVar3 | bVar2);
                  cVar8 = (char)uVar12;
                  uVar14 = CONCAT71((int7)(uVar14 >> 8),cVar8);
                  puVar16 = (ushort *)0x101;
                  if ((((*(char *)(param_1 + 0x24) == '\0') || (*(char *)(param_1 + 0x23) != '\0'))
                      || (*(int *)(param_1 + 0xc) != 0x101)) ||
                     (*(char *)(*(longlong *)(param_1 + 0x1a70) + 0x488) == '\0')) {
                    bVar20 = false;
                  }
                  else {
                    *(byte *)(param_1 + 0x33) = bVar2;
                    bVar20 = ((byte)*(undefined4 *)(*(longlong *)(param_1 + 0x18f0) + 0x44) & 1) !=
                             bVar2;
                  }
                  param_2[0x32] = 0;
                  *(undefined1 *)(param_2 + 0x35) = 0;
                  param_2[0x30] = 5;
                  param_2[0x31] = 0;
                  if (bVar21) {
                    *(undefined1 *)(param_2 + 0x35) = 0xef;
                    *param_2 = 0x100;
                    *(undefined1 *)((longlong)param_2 + 0x65) = 3;
                    *(byte *)(param_2 + 0x32) = (-(bVar19 != 0) & 0x80U) + 0x90;
                  }
                  else if ((*piVar4 == -0x14ebfeff) && (cVar8 != '\0')) {
                    *(undefined1 *)(param_2 + 4) = 6;
                    *param_2 = 0x200;
                    *(undefined1 *)(param_2 + 0x32) = 0;
                  }
                  else {
                    if ((*piVar4 != 0x101) || ((!bVar20 && (cVar8 == '\0')))) {
                      *(undefined1 *)(param_2 + 1) = 1;
                      AhciPortCompleteRequest(param_1,param_2);
                      return 1;
                    }
                    *param_2 = 0x100;
                    *(undefined1 *)(param_2 + 0x35) = *(undefined1 *)((longlong)piVar4 + 0x32b);
                  }
                  pcVar11 = AhciChannelIpmCompletion;
                }
LAB_1c0002e58:
                iVar17 = 0;
                uVar10 = 0x20000;
                *(code **)(param_2 + 0x18) = pcVar11;
                goto LAB_1c0002e5c;
              }
              if ((*(uint *)(param_1 + 300) & ~*(uint *)(param_1 + 0x1ec)) == 0) {
                AhciPortRequestSynchronizedRoutine(param_1,AhciHwReanimateBus);
              }
            }
LAB_1c0002afe:
            *(undefined1 *)(param_2 + 1) = 1;
            goto LAB_1c0002faf;
          }
          local_res18 = (ulonglong)
                        CONCAT15((char)param_2[0x38],
                                 CONCAT14(*(undefined1 *)((longlong)param_2 + 0x6f),
                                          CONCAT13((char)param_2[0x37],
                                                   *(undefined3 *)(param_2 + 0x33))));
          *(ulonglong *)(param_2 + 0x14) = local_res18;
          if (*(ulonglong *)(piVar4 + 4) < local_res18) {
            *(undefined1 *)(param_2 + 1) = 4;
            goto LAB_1c0002faf;
          }
          *(char *)(param_2 + 0x35) = (char)piVar4[0xcb];
          if ((*(char *)((longlong)piVar4 + 0x47b) == '\0') && (0x20000 < *(uint *)(param_2 + 0xc)))
          {
            *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0xc);
            pcVar11 = Lba28CompletionRoutine;
            param_2[0xc] = 0;
            param_2[0xd] = 2;
            *(ulonglong *)(param_2 + 0x14) = local_res18;
            *(undefined1 *)((longlong)param_2 + 0x65) = 0;
            goto LAB_1c0002e58;
          }
        }
LAB_1c0002e5c:
        iVar9 = *(int *)(param_1 + 0x22c + uVar18 * 4) + 1;
        *(int *)(param_1 + 0x22c + uVar18 * 4) = iVar9;
        if ((*(int *)(param_1 + 0x1f0 + uVar18 * 4) != iVar17) &&
           (0x20 < iVar9 - *(int *)(param_1 + 0x268 + uVar18 * 4))) {
          *(int *)(param_1 + 0x1f0 + uVar18 * 4) = iVar17;
        }
        *(ushort *)(piVar4 + 0x11e) = *param_2;
        *(char *)((longlong)piVar4 + 0x47a) = (char)param_2[0x35];
        if (*(int *)(param_1 + 0x18d4) == iVar17) {
          puVar16 = (ushort *)(ulonglong)(byte)param_2[3];
          uVar10 = *(uint *)(param_2 + 8) & uVar10;
          if (*(int *)(param_1 + 0x174 + (longlong)puVar16 * 4) == iVar17) {
            if ((*(int *)(param_1 + 0x138 + (longlong)puVar16 * 4) != iVar17) && (uVar10 != 0))
            goto LAB_1c0002f3f;
            bVar21 = true;
          }
          else {
            bVar21 = uVar10 != 0;
          }
          if (bVar21) {
            if ((*(int *)(param_1 + 0xc) == -0x6996feff) &&
               (*(char *)(param_1 + 0x1f) == (char)iVar17)) {
              if (*(int *)(param_1 + 0x128) == iVar17) {
                if ((*(int *)(param_1 + 0x124) == iVar17) || (uVar10 == 0)) {
                  bVar21 = true;
                  goto LAB_1c0002f13;
                }
              }
              else if (uVar10 != 0) {
                bVar21 = *(byte *)(param_1 + 0x1a) == (byte)param_2[3];
LAB_1c0002f13:
                if (bVar21) goto LAB_1c0002f17;
              }
            }
            else {
LAB_1c0002f17:
              puVar16 = param_2;
              cVar8 = Irb2Slot(param_1,param_2,uVar14);
              uVar14 = CONCAT71(extraout_var,cVar8);
              if (cVar8 < '\0') goto LAB_1c0002fb4;
              if (cVar8 < ' ') {
                uVar14 = AhciPortRequestSynchronizedRoutine(param_1,Actuate);
                goto LAB_1c0002fb4;
              }
            }
          }
        }
LAB_1c0002f3f:
        if (piVar4[0x87] != 0x20) {
          iVar17 = piVar4[0x88];
          *(ushort **)(piVar4 + (longlong)iVar17 * 2 + 0x8a) = param_2;
          uVar10 = iVar17 + 1U & 0x8000001f;
          if ((int)uVar10 < 0) {
            uVar10 = (uVar10 - 1 | 0xffffffe0) + 1;
          }
          piVar4[0x87] = piVar4[0x87] + 1;
          piVar4[0x88] = uVar10;
          *(int *)(param_1 + 0x18d4) = *(int *)(param_1 + 0x18d4) + 1;
          uVar14 = (ulonglong)*(uint *)(param_1 + 0x18d4);
          if (*(uint *)(param_1 + 0x18d4) == 1) {
            LOCK();
            puVar1 = (uint *)(param_1 + 0x10);
            uVar10 = *puVar1;
            *puVar1 = *puVar1 | 0x10;
            UNLOCK();
            if ((uVar10 >> 4 & 1) == 0) {
              uVar14 = ChannelWorkerDpcRoutine(param_1,(undefined *)puVar16);
            }
          }
          goto LAB_1c0002fb4;
        }
        _DAT_1c0011440 = _DAT_1c0011440 + 1;
        *(undefined1 *)(param_2 + 1) = 7;
        goto LAB_1c0002faf;
      }
      local_res10 = (ulonglong)
                    CONCAT15((char)param_2[0x38],
                             CONCAT14(*(undefined1 *)((longlong)param_2 + 0x6f),
                                      CONCAT13((char)param_2[0x37],*(undefined3 *)(param_2 + 0x33)))
                            );
      *(ulonglong *)(param_2 + 0x14) = local_res10;
      if (local_res10 <= *(ulonglong *)(piVar4 + 4)) {
        *(longlong *)(piVar4 + 0xd0) = *(longlong *)(piVar4 + 0xd0) + 1;
        *(ulonglong *)(piVar4 + 0xd2) =
             *(longlong *)(piVar4 + 0xd2) + (ulonglong)(byte)param_2[0x35];
        if ((char)param_2[0x35] == '\0') {
          uVar7 = *(undefined1 *)((longlong)piVar4 + 0x329);
        }
        else {
          uVar7 = *(undefined1 *)((longlong)piVar4 + 0x32a);
          *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) | 0x10000;
        }
        *(undefined1 *)(param_2 + 0x35) = uVar7;
        local_res8 = local_res10;
        if ((char)piVar4[0x11f] != '\0') {
          *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) | 0x20000;
          *(undefined1 *)(param_2 + 0x35) = 0x61;
        }
        goto LAB_1c0002a59;
      }
    }
    *(undefined1 *)(param_2 + 1) = 4;
  }
LAB_1c0002faf:
  uVar14 = AhciPortCompleteRequest(param_1,param_2);
LAB_1c0002fb4:
  return CONCAT71((int7)(uVar14 >> 8),1);
}



===== AhciCheckAllPortsSlotIdle @ 1c0002fcc =====

undefined8 AhciCheckAllPortsSlotIdle(longlong param_1)

{
  uint *puVar1;
  longlong lVar2;
  
  lVar2 = 0;
  puVar1 = (uint *)(param_1 + 0x490);
  while (((char)puVar1[-6] == '\0' ||
         (((*puVar1 & 4) == 0 &&
          (((puVar1[0x39] != 0 || (((byte)*puVar1 & 6) != 2)) || (puVar1[0x47] == 0))))))) {
    lVar2 = lVar2 + 1;
    puVar1 = puVar1 + 0x6e2;
    if (1 < lVar2) {
      return 1;
    }
  }
  return 0;
}



===== AhciHwChannelInterrupt @ 1c000301c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong AhciHwChannelInterrupt(longlong param_1)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  byte *pbVar4;
  uint *puVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  uint local_res8 [2];
  uint local_res10;
  
  *(int *)(param_1 + 0xe8) = *(int *)(param_1 + 0xe8) + 1;
  puVar5 = (uint *)(*(longlong *)(param_1 + 0x18f0) + 0x10);
  uVar10 = *puVar5;
  if (uVar10 == 0) {
LAB_1c000306e:
    return (ulonglong)puVar5 & 0xffffffffffffff00;
  }
  *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x10) = uVar10;
  LOCK();
  UNLOCK();
  *(int *)(param_1 + 0xf0) = *(int *)(param_1 + 0xf0) + 1;
  puVar5 = (uint *)(ulonglong)*(uint *)(param_1 + 0x10);
  lVar3 = *(longlong *)(param_1 + -0x98);
  if ((*(uint *)(param_1 + 0x10) & 1) == 0) {
    *(int *)(param_1 + 0xec) = *(int *)(param_1 + 0xec) + 1;
    goto LAB_1c000306e;
  }
  uVar10 = uVar10 & (*(uint *)(param_1 + 0x34) | 0xf);
  AhciCompleteIssuedIRBs(param_1);
  if ((((g_bIsKernCZBP != '\0') && (*(int *)(param_1 + 0xf4) == 0)) &&
      (((byte)*(undefined4 *)(param_1 + 0x10) & 6) == 2)) &&
     ((*(char *)(param_1 + -8) == '\x01' &&
      (uVar6 = AhciCheckAllPortsSlotIdle(lVar3), (char)uVar6 != '\0')))) {
    LOCK();
    _g_lOutstandingIO = _g_lOutstandingIO & 0xfffffffe;
    UNLOCK();
    StorPortExtendedFunction
              (0x21,lVar3,*(undefined8 *)(lVar3 + 0x3e0),ChannelTurnOffPHYClockTimerRoutine,param_1,
               80000,80000);
  }
  if (((uVar10 & 8) != 0) &&
     ((*(int *)(param_1 + 0xc) == -0x14ebfeff || (*(int *)(param_1 + 0xc) == -0x6996feff)))) {
    local_res8[0] = *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x3c);
    if (local_res8[0] != 0) {
      *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x3c) = local_res8[0];
      LOCK();
      UNLOCK();
      if (*(int *)(param_1 + 0xc) == -0x14ebfeff) {
        AhciPortAsyncNotificationDetected(param_1,0);
      }
      else if (*(int *)(param_1 + 0xc) == -0x6996feff) {
        if ((local_res8[0] & 0x8000) == 0) {
          while( true ) {
            uVar8 = 0;
            if (local_res8[0] != 0) {
              for (; (local_res8[0] >> uVar8 & 1) == 0; uVar8 = uVar8 + 1) {
              }
            }
            local_res10 = uVar8;
            if (local_res8[0] == 0) break;
            lVar3 = *(longlong *)(param_1 + 0x1a70 + (ulonglong)uVar8 * 8);
            pbVar4 = (byte *)((longlong)local_res8 + ((longlong)(int)uVar8 >> 3));
            *pbVar4 = *pbVar4 & ~('\x01' << (uVar8 & 7));
            if (lVar3 == 0) {
              LOCK();
              *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x800000;
              UNLOCK();
            }
            else {
              AhciPortAsyncNotificationDetected(param_1,(char)uVar8);
            }
          }
        }
        else {
          LOCK();
          *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x100080;
          UNLOCK();
        }
      }
    }
  }
  uVar8 = *(uint *)(param_1 + 0x1a48);
  uVar1 = *(uint *)(param_1 + 0x1a4c);
  uVar9 = (ulonglong)uVar1;
  if (uVar8 != (uVar8 & uVar1)) {
    *(uint *)(param_1 + 0x1a4c) = uVar8 | uVar1;
    LOCK();
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x1004;
    UNLOCK();
  }
  if ((uVar10 & 0xfbffffe0) == 0) {
    if ((uVar10 & 0x4000010) != 0) {
      *(undefined4 *)(*(longlong *)(param_1 + 0x18f0) + 0x30) = 0xffffffff;
      LOCK();
      UNLOCK();
      *(int *)(param_1 + 0x1a68) = *(int *)(param_1 + 0x1a68) + 1;
      if (((*(char *)(param_1 + 0x1f) != '\0') && ((uVar10 >> 0x1a & 1) != 0)) &&
         (uVar8 = *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x40), (uVar8 & 4) != 0)) {
        *(uint *)(param_1 + 0x1a40) = uVar8;
        LOCK();
        *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x400000;
        UNLOCK();
      }
    }
    uVar7 = (ulonglong)*(uint *)(param_1 + 0x10);
    if ((*(uint *)(param_1 + 0x10) & 0xffff004) != 0) goto LAB_1c000333b;
    if (*(int *)(param_1 + 0x18d4) == 0) goto LAB_1c000322c;
    LOCK();
    puVar5 = (uint *)(param_1 + 0x10);
    uVar10 = *puVar5;
    *puVar5 = *puVar5 | 0x10;
    UNLOCK();
    if ((uVar10 >> 4 & 1) != 0) goto LAB_1c000322c;
  }
  else {
    iVar2 = *(int *)(*(longlong *)(param_1 + 0x18f0) + 0x30);
    *(int *)(param_1 + 0x1a38) = iVar2;
    *(int *)(*(longlong *)(param_1 + 0x18f0) + 0x30) = iVar2;
    LOCK();
    UNLOCK();
    uVar8 = (uint)(iVar2 != 0);
    *(int *)(param_1 + 0x1a68) = *(int *)(param_1 + 0x1a68) + uVar8;
    if ((uVar10 & (~((uVar8 - (iVar2 != 0)) - (uint)(*(char *)(param_1 + 0x1f) != '\0')) & 0x1000000
                  | 0x38000000)) == 0) {
      uVar8 = uVar10 >> 0x1e & 1;
      if (uVar8 != 0) {
        *(undefined4 *)(param_1 + 0x1a3c) = *(undefined4 *)(*(longlong *)(param_1 + 0x18f0) + 0x20);
      }
      if (*(char *)(param_1 + 0x1f) == '\0') {
        LOCK();
        *(uint *)(param_1 + 0x10) =
             *(uint *)(param_1 + 0x10) | (-(uint)(uVar8 != 0) & 0x100000) + 0x100000;
        UNLOCK();
      }
      else {
        uVar8 = *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x40);
        if ((uVar8 & 4) == 0) goto LAB_1c00032c7;
        *(uint *)(param_1 + 0x1a40) = uVar8;
        LOCK();
        *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x400000;
        UNLOCK();
      }
    }
    else {
LAB_1c00032c7:
      LOCK();
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x100000;
      UNLOCK();
    }
    uVar9 = 0x100040;
    if (((char)uVar10 < '\0') &&
       ((*(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x18) >> 0x13 & 1) != 0)) {
      LOCK();
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x100040;
      UNLOCK();
    }
    if ((int)uVar10 < 0) {
      LOCK();
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x100040;
      UNLOCK();
    }
    if ((uVar10 & 0x40) != 0) {
      LOCK();
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x100040;
      UNLOCK();
      *(int *)(param_1 + 0xe0) = *(int *)(param_1 + 0xe0) + 1;
    }
    if ((uVar10 >> 0x16 & 1) != 0) {
      uVar8 = *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x28) >> 8 & 0xf;
      if (((uVar8 - 1 & 0xfffffffa) != 0) || (uVar8 == 5)) {
        LOCK();
        *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x100040;
        UNLOCK();
      }
      *(int *)(param_1 + 0xe4) = *(int *)(param_1 + 0xe4) + 1;
    }
LAB_1c000333b:
    uVar8 = *(uint *)(param_1 + 0x10);
    uVar7 = (ulonglong)uVar8;
    if (((uVar8 & 0xff00000) == 0) &&
       (((uVar8 & 0xff000) == 0 ||
        (uVar7 = (ulonglong)~*(uint *)(param_1 + 0x1ec),
        (*(uint *)(param_1 + 300) & ~*(uint *)(param_1 + 0x1ec)) != 0)))) goto LAB_1c000322c;
    LOCK();
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 4;
    UNLOCK();
    *(uint *)(param_1 + 0x1a34) = uVar10;
  }
  uVar7 = AhciPortRequestWorkerRoutine(param_1,uVar9);
LAB_1c000322c:
  return CONCAT71((int7)(uVar7 >> 8),1);
}



===== AhciHwIRQ @ 1c0003374 =====

ulonglong AhciHwIRQ(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  byte *pbVar4;
  uint uVar5;
  byte bVar6;
  uint *puVar7;
  ulonglong uVar8;
  bool bVar9;
  uint local_res8 [2];
  uint local_res10;
  uint local_res18 [4];
  
  puVar7 = (uint *)(*(longlong *)(param_1 + 8) + 8);
  uVar1 = *puVar7;
  if (uVar1 == 0) {
    uVar8 = (ulonglong)puVar7 & 0xffffffffffffff00;
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x38);
    local_res8[0] = uVar1;
    if (uVar2 != 0) {
      pbVar4 = (byte *)((longlong)local_res8 + ((longlong)(int)*(uint *)(param_1 + 0x44) >> 3));
      uVar5 = *(uint *)(param_1 + 0x44) & 7;
      bVar6 = *pbVar4;
      *pbVar4 = *pbVar4 & ~('\x01' << uVar5);
      if ((bVar6 >> uVar5 & 1) != 0) {
        uVar5 = 0;
        bVar9 = uVar2 != 0;
        if (bVar9) {
          for (; (uVar2 >> uVar5 & 1) == 0; uVar5 = uVar5 + 1) {
          }
        }
        local_res18[0] = uVar2;
        local_res10 = uVar5;
        while (bVar9) {
          pbVar4 = (byte *)((longlong)local_res18 + ((longlong)(int)uVar5 >> 3));
          *pbVar4 = *pbVar4 & ~('\x01' << (uVar5 & 7));
          AhciHwChannelInterrupt(*(longlong *)(param_1 + 0x60 + (ulonglong)uVar5 * 8));
          uVar5 = 0;
          bVar9 = local_res18[0] != 0;
          if (bVar9) {
            for (; (local_res18[0] >> uVar5 & 1) == 0; uVar5 = uVar5 + 1) {
            }
          }
        }
      }
    }
    local_res8[0] = local_res8[0] & *(uint *)(param_1 + 0x30);
    if (local_res8[0] != 0) {
      uVar2 = 0;
      bVar9 = local_res8[0] != 0;
      if (bVar9) {
        for (; (local_res8[0] >> uVar2 & 1) == 0; uVar2 = uVar2 + 1) {
        }
      }
      local_res10 = uVar2;
      while (bVar9) {
        pbVar4 = (byte *)((longlong)local_res8 + ((longlong)(int)uVar2 >> 3));
        *pbVar4 = *pbVar4 & ~('\x01' << (uVar2 & 7));
        AhciHwChannelInterrupt(*(longlong *)(param_1 + 0x60 + (ulonglong)uVar2 * 8));
        uVar2 = 0;
        bVar9 = local_res8[0] != 0;
        if (bVar9) {
          for (; (local_res8[0] >> uVar2 & 1) == 0; uVar2 = uVar2 + 1) {
          }
        }
      }
    }
    lVar3 = *(longlong *)(param_1 + 8);
    *(uint *)(lVar3 + 8) = uVar1;
    LOCK();
    UNLOCK();
    uVar8 = CONCAT71((int7)((ulonglong)lVar3 >> 8),1);
  }
  return uVar8;
}



===== FixIdeTaskFile @ 1c0003414 =====

void FixIdeTaskFile(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  uint uVar3;
  longlong lVar4;
  
  if ((*(uint *)(param_1 + 0x1a34) & 0x40000001) == 0x40000001) {
    uVar3 = 0;
    if (*(char *)(param_1 + 0x1f) != '\0') {
      uVar3 = (uint)*(byte *)(param_2 + 6);
    }
    lVar1 = *(longlong *)(param_1 + 0x1a20);
    lVar4 = (longlong)(int)uVar3 * 0x100;
    *(undefined1 *)(param_2 + 0x6a) = *(undefined1 *)(lVar4 + 0x42 + lVar1);
    *(undefined1 *)(param_2 + 100) = *(undefined1 *)(lVar4 + 0x43 + lVar1);
    *(undefined1 *)(param_2 + 0x68) = *(undefined1 *)(lVar4 + 0x46 + lVar1);
    *(undefined1 *)(param_2 + 0x67) = *(undefined1 *)(lVar4 + 0x45 + lVar1);
    *(undefined1 *)(param_2 + 0x69) = *(undefined1 *)(lVar4 + 0x47 + lVar1);
    *(undefined1 *)(param_2 + 0x65) = *(undefined1 *)(lVar4 + 0x4c + lVar1);
    *(undefined1 *)(param_2 + 0x66) = *(undefined1 *)(lVar4 + 0x44 + lVar1);
    if ((*(uint *)(param_2 + 0x10) & 8) == 0) goto LAB_1c0003569;
    *(undefined1 *)(param_2 + 0x72) = *(undefined1 *)(lVar4 + 0x42 + lVar1);
    *(undefined1 *)(param_2 + 0x6c) = *(undefined1 *)(lVar4 + 0x43 + lVar1);
    *(undefined1 *)(param_2 + 0x70) = *(undefined1 *)(lVar4 + 0x4a + lVar1);
    *(undefined1 *)(param_2 + 0x6f) = *(undefined1 *)(lVar4 + 0x49 + lVar1);
    *(undefined1 *)(param_2 + 0x71) = *(undefined1 *)(lVar4 + 0x47 + lVar1);
    *(undefined1 *)(param_2 + 0x6d) = *(undefined1 *)(lVar4 + 0x4d + lVar1);
    uVar2 = *(undefined1 *)(lVar4 + 0x48 + lVar1);
  }
  else {
    if ((*(uint *)(param_1 + 0x1a34) & 0x40000002) != 0x40000002) {
      return;
    }
    uVar3 = 0;
    if (*(char *)(param_1 + 0x1f) != '\0') {
      uVar3 = (uint)*(byte *)(param_2 + 6);
    }
    lVar1 = *(longlong *)(param_1 + 0x1a20);
    lVar4 = (longlong)(int)uVar3 * 0x100;
    *(undefined1 *)(param_2 + 0x6a) = *(undefined1 *)(lVar4 + 0x22 + lVar1);
    *(undefined1 *)(param_2 + 100) = *(undefined1 *)(lVar4 + 0x23 + lVar1);
    *(undefined1 *)(param_2 + 0x68) = *(undefined1 *)(lVar4 + 0x26 + lVar1);
    *(undefined1 *)(param_2 + 0x67) = *(undefined1 *)(lVar4 + 0x25 + lVar1);
    *(undefined1 *)(param_2 + 0x69) = *(undefined1 *)(lVar4 + 0x27 + lVar1);
    *(undefined1 *)(param_2 + 0x65) = *(undefined1 *)(lVar4 + 0x2c + lVar1);
    *(undefined1 *)(param_2 + 0x66) = *(undefined1 *)(lVar4 + 0x24 + lVar1);
    if ((*(uint *)(param_2 + 0x10) & 8) == 0) goto LAB_1c0003569;
    *(undefined1 *)(param_2 + 0x72) = *(undefined1 *)(lVar4 + 0x22 + lVar1);
    *(undefined1 *)(param_2 + 0x6c) = *(undefined1 *)(lVar4 + 0x23 + lVar1);
    *(undefined1 *)(param_2 + 0x70) = *(undefined1 *)(lVar4 + 0x2a + lVar1);
    *(undefined1 *)(param_2 + 0x6f) = *(undefined1 *)(lVar4 + 0x29 + lVar1);
    *(undefined1 *)(param_2 + 0x71) = *(undefined1 *)(lVar4 + 0x27 + lVar1);
    *(undefined1 *)(param_2 + 0x6d) = *(undefined1 *)(lVar4 + 0x2d + lVar1);
    uVar2 = *(undefined1 *)(lVar4 + 0x28 + lVar1);
  }
  *(undefined1 *)(param_2 + 0x6e) = uVar2;
LAB_1c0003569:
  *(undefined1 *)(param_2 + 2) = 0x13;
  return;
}



===== AhciChannelError @ 1c0003570 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AhciChannelError(longlong *param_1,ushort *param_2,ushort *param_3)

{
  uint *puVar1;
  byte bVar2;
  ushort uVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  byte *pbVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  longlong lVar15;
  undefined *puVar16;
  longlong *plVar17;
  longlong *plVar18;
  undefined8 uVar19;
  ushort *puVar20;
  uint uVar21;
  ulonglong uVar22;
  ushort *puVar23;
  uint uVar24;
  longlong *plVar25;
  undefined4 uVar26;
  ulonglong uVar27;
  int iVar28;
  uint uVar29;
  byte bVar30;
  bool bVar31;
  undefined1 local_78 [32];
  uint local_58;
  uint local_54 [2];
  uint local_4c;
  uint local_48;
  ushort *local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)local_78;
  uVar21 = *(uint *)((longlong)param_1 + 0x1a34);
  uVar24 = 0;
  local_40 = (ushort *)0x0;
  iVar13 = 0;
  iVar14 = 0;
  iVar28 = 0;
  uStack_38 = (ulonglong)*(byte *)(param_1 + 1);
  uVar22 = uStack_38;
  LOCK();
  *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) & 0xffffffef;
  UNLOCK();
  LOCK();
  puVar1 = (uint *)(param_1 + 2);
  uVar12 = *puVar1;
  *puVar1 = *puVar1 & 0xffefffff;
  UNLOCK();
  uStack_38._0_4_ = (uint)*(byte *)(param_1 + 1);
  if ((uVar12 >> 0x14 & 1) != 0) {
    puVar1 = (uint *)(param_1 + 2);
    uVar12 = *puVar1;
    *puVar1 = *puVar1 & 0xffffff7f;
    puVar1 = (uint *)(param_1 + 2);
    bVar31 = (*puVar1 >> 6 & 1) != 0;
    *puVar1 = *puVar1 & 0xffffffbf;
    *(undefined1 *)((longlong)param_1 + 0x105) = 1;
    *(bool *)((longlong)param_1 + 0x103) = bVar31;
    uStack_38 = (ulonglong)CONCAT14(-((uVar12 >> 7 & 1) != 0) & 2U | bVar31,(uint)uStack_38) |
                0x9000000000;
    AhciPortLogError((longlong)param_1,(longlong *)&local_40);
    uVar26 = 0x90;
LAB_1c000360a:
    FireHbaNotification(*param_1,4,(int)param_1[1],uVar26);
    uVar22 = uStack_38;
LAB_1c000400f:
    uStack_38 = uVar22;
    AhciEnumerateChannelAsynchronously(param_1,0);
    return;
  }
  LOCK();
  puVar1 = (uint *)(param_1 + 2);
  uVar12 = *puVar1;
  *puVar1 = *puVar1 & 0xffdfffff;
  UNLOCK();
  uStack_38 = uVar22;
  if ((uVar12 >> 0x15 & 1) == 0) {
    LOCK();
    puVar1 = (uint *)(param_1 + 2);
    uVar12 = *puVar1;
    *puVar1 = *puVar1 & 0xffbfffff;
    UNLOCK();
    if ((uVar12 >> 0x16 & 1) != 0) {
      bVar2 = *(byte *)((longlong)param_1 + 0x1a42);
      bVar30 = bVar2 & 0xf;
      uVar27 = (ulonglong)bVar30;
      lVar15 = param_1[uVar27 + 0x34e];
      uVar12 = (uint)bVar30;
      if (lVar15 == 0) {
        pbVar11 = (byte *)((longlong)param_1 + ((longlong)(int)uVar12 >> 3) + 0x1a4c);
        *pbVar11 = *pbVar11 | '\x01' << (uVar12 & 7);
      }
      else {
        pbVar11 = (byte *)((longlong)param_1 + ((longlong)(int)(uint)bVar30 >> 3) + 0x1a4c);
        *pbVar11 = *pbVar11 & ~('\x01' << (bVar30 & 7));
      }
      if (((char)*(uint *)(param_1[0x31e] + 0x20) < '\0') ||
         ((*(uint *)(param_1[0x31e] + 0x20) & 8) != 0)) {
LAB_1c0003ac4:
        pbVar11 = (byte *)((longlong)param_1 + ((longlong)(int)uVar12 >> 3) + 0x1a4c);
        *pbVar11 = *pbVar11 | '\x01' << (uVar12 & 7);
      }
      else if (*(int *)((longlong)param_1 + uVar27 * 4 + 0x174) == 0) {
        if (*(int *)((longlong)param_1 + uVar27 * 4 + 0x138) == 0) {
          iVar28 = 1;
          goto LAB_1c0003ac4;
        }
        iVar14 = 1;
      }
      else {
        iVar13 = 1;
      }
      *(int *)(param_1 + 7) = (int)param_1[7] + iVar14;
      *(int *)((longlong)param_1 + 0x3c) = *(int *)((longlong)param_1 + 0x3c) + iVar13;
      *(int *)(param_1 + 8) = (int)param_1[8] + iVar28;
      if (iVar28 != 0) goto LAB_1c000400f;
      uVar29 = (uint)bVar30;
      if ((*(byte *)((longlong)param_1 + ((longlong)(int)uVar29 >> 3) + 0x1a4c) >> (uVar29 & 7) & 1)
          == 0) {
        *(longlong *)(lVar15 + 0x360) = *(longlong *)(lVar15 + 0x360) + (longlong)iVar14;
        *(longlong *)(lVar15 + 0x358) = *(longlong *)(lVar15 + 0x358) + (longlong)iVar13;
        if (iVar13 == 0) {
          local_58 = *(uint *)((longlong)param_1 + 300);
          uVar21 = 0;
          bVar31 = local_58 == 0;
          if (!bVar31) {
            for (; (local_58 >> uVar21 & 1) == 0; uVar21 = uVar21 + 1) {
            }
          }
LAB_1c0003bca:
          local_4c = uVar21;
          puVar23 = (ushort *)0x0;
          if (!bVar31) {
            local_78[((longlong)(int)uVar21 >> 3) + 0x20] =
                 local_78[((longlong)(int)uVar21 >> 3) + 0x20] & ~('\x01' << (uVar21 & 7));
            puVar23 = (ushort *)(param_1 + (ulonglong)uVar21 * 7 + 0x55);
            if (bVar30 != *(byte *)((longlong)puVar23 + 0x29)) goto code_r0x0001c0003bc6;
            local_4c = 0;
            if (local_58 != 0) {
              for (; (local_58 >> local_4c & 1) == 0; local_4c = local_4c + 1) {
              }
            }
            if (local_58 != 0) {
              do {
                local_78[((longlong)(int)local_4c >> 3) + 0x20] =
                     local_78[((longlong)(int)local_4c >> 3) + 0x20] & ~('\x01' << (local_4c & 7));
                param_3 = (ushort *)(param_1 + (ulonglong)local_4c * 7 + 0x55);
                if ((bVar30 == *(byte *)((longlong)param_3 + 0x29)) &&
                   (*(int *)(param_3 + 0x16) - *(int *)(puVar23 + 0x16) < 0)) {
                  puVar23 = param_3;
                }
                local_4c = 0;
                if (local_58 != 0) {
                  for (; (local_58 >> local_4c & 1) == 0; local_4c = local_4c + 1) {
                  }
                }
              } while (local_58 != 0);
            }
          }
          puVar20 = *(ushort **)(puVar23 + 4);
          pbVar11 = (byte *)((longlong)param_1 +
                            ((longlong)(int)(uint)(byte)puVar23[0x14] >> 3) + 0x124);
          *pbVar11 = *pbVar11 & ~('\x01' << ((byte)puVar23[0x14] & 7));
          pbVar11 = (byte *)((longlong)param_1 +
                            ((longlong)(int)(uint)(byte)puVar23[0x14] >> 3) + uVar27 * 4 + 0x138);
          *pbVar11 = *pbVar11 & ~('\x01' << ((byte)puVar23[0x14] & 7));
          pbVar11 = (byte *)((longlong)param_1 +
                            ((longlong)(int)(uint)(byte)puVar23[0x14] >> 3) + uVar27 * 4 + 0x1b0);
          *pbVar11 = *pbVar11 & ~('\x01' << ((byte)puVar23[0x14] & 7));
          *(undefined1 *)((longlong)puVar20 + 3) = *(undefined1 *)(param_1[0x31e] + 0x20);
          *(undefined1 *)(puVar20 + 2) = *(undefined1 *)(param_1[0x31e] + 0x21);
          uVar3 = *puVar20;
          *(undefined1 *)(puVar20 + 1) = 3;
          if (uVar3 < 0x100) {
            if (uVar3 == 0x10) {
              AhciHwPresetComplete((longlong)param_1,(longlong)puVar23);
              puVar23[8] = 0;
              puVar23[9] = 0;
              puVar23[10] = 0;
              puVar23[0xb] = 0;
              puVar23[0x18] = 0;
              puVar23[0x19] = 0;
              puVar23[0x1a] = 0;
              puVar23[0x1b] = 0;
              puVar23[4] = 0;
              puVar23[5] = 0;
              puVar23[6] = 0;
              puVar23[7] = 0;
              puVar23[0] = 0;
              puVar23[1] = 0;
              puVar23[0x14] = 0;
              puVar23[0x15] = 0;
              uVar22 = (longlong)puVar23 + (-0x2a8 - (longlong)param_1);
              auVar8._8_8_ = 0;
              auVar8._0_8_ = uVar22;
              lVar15 = SUB168(ZEXT816(0x2492492492492493) * auVar8,8);
              LOCK();
              uVar12 = (uint)((uVar22 - lVar15 >> 1) + lVar15 >> 5);
              pbVar11 = (byte *)((longlong)param_1 + ((longlong)(int)uVar12 >> 3) + 300);
              *pbVar11 = *pbVar11 & ~('\x01' << (uVar12 & 7));
              UNLOCK();
              DeslotDeviceSlots((longlong)param_1,bVar30);
              *(uint *)(param_1[0x31e] + 0x40) = *(uint *)(param_1[0x31e] + 0x40) | 2;
              LOCK();
              UNLOCK();
              do {
                StorPortStallExecution(10);
                uVar24 = uVar24 + 1;
                if ((*(uint *)(param_1[0x31e] + 0x40) & 2) == 0) break;
              } while (uVar24 < 100);
              lVar15 = 0;
              StartStopDMAs(param_1,0);
              goto LAB_1c00037e5;
            }
            if (uVar3 == 0x11) {
              *(undefined1 *)(param_1 + 0x346) = 0;
              pbVar11 = (byte *)((longlong)param_1 + ((longlong)(int)uVar29 >> 3) + 0x1a4c);
              *pbVar11 = *pbVar11 | '\x01' << (uVar29 & 7);
            }
            puVar23[8] = 0;
            puVar23[9] = 0;
            puVar23[10] = 0;
            puVar23[0xb] = 0;
            puVar23[0x18] = 0;
            puVar23[0x19] = 0;
            puVar23[0x1a] = 0;
            puVar23[0x1b] = 0;
            puVar23[4] = 0;
            puVar23[5] = 0;
            puVar23[6] = 0;
            puVar23[7] = 0;
            puVar23[0] = 0;
            puVar23[1] = 0;
            puVar23[0x14] = 0;
            puVar23[0x15] = 0;
            uVar22 = (longlong)puVar23 + (-0x2a8 - (longlong)param_1);
            auVar9._8_8_ = 0;
            auVar9._0_8_ = uVar22;
            lVar15 = SUB168(ZEXT816(0x2492492492492493) * auVar9,8);
            param_2 = (ushort *)
                      (CONCAT71(SUB167(ZEXT816(0x2492492492492493) * auVar9,9),bVar2) &
                      0xffffffffffffff0f);
            LOCK();
            uVar21 = (uint)((uVar22 - lVar15 >> 1) + lVar15 >> 5);
            pbVar11 = (byte *)((longlong)param_1 + ((longlong)(int)uVar21 >> 3) + 300);
            *pbVar11 = *pbVar11 & ~('\x01' << (uVar21 & 7));
            UNLOCK();
            DeslotDeviceSlots((longlong)param_1,bVar30);
            *(uint *)(param_1[0x31e] + 0x40) = *(uint *)(param_1[0x31e] + 0x40) | 2;
            LOCK();
            UNLOCK();
            uVar21 = 0;
            while( true ) {
              StorPortStallExecution(10);
              uVar21 = uVar21 + 1;
              if ((*(uint *)(param_1[0x31e] + 0x40) & 2) == 0) break;
              if (99 < uVar21) break;
            }
          }
          else if (uVar3 == 0x200) {
            param_2 = AhciPortBuildRequestSenseIrb(0x200,puVar20);
            if (param_2 != (ushort *)0x0) {
              puVar23[8] = 0;
              puVar23[9] = 0;
              puVar23[10] = 0;
              puVar23[0xb] = 0;
              puVar23[0x18] = 0;
              puVar23[0x19] = 0;
              puVar23[0x1a] = 0;
              puVar23[0x1b] = 0;
              puVar23[4] = 0;
              puVar23[5] = 0;
              puVar23[6] = 0;
              puVar23[7] = 0;
              puVar23[0] = 0;
              puVar23[1] = 0;
              puVar23[0x14] = 0;
              puVar23[0x15] = 0;
              uVar22 = (longlong)puVar23 + (-0x2a8 - (longlong)param_1);
              auVar10._8_8_ = 0;
              auVar10._0_8_ = uVar22;
              lVar15 = SUB168(ZEXT816(0x2492492492492493) * auVar10,8);
              LOCK();
              uVar21 = (uint)((uVar22 - lVar15 >> 1) + lVar15 >> 5);
              pbVar11 = (byte *)((longlong)param_1 + ((longlong)(int)uVar21 >> 3) + 300);
              *pbVar11 = *pbVar11 & ~('\x01' << (uVar21 & 7));
              UNLOCK();
              DeslotDeviceSlots((longlong)param_1,bVar30);
              *(uint *)(param_1[0x31e] + 0x40) = *(uint *)(param_1[0x31e] + 0x40) | 2;
              LOCK();
              UNLOCK();
              uVar21 = 0;
              do {
                StorPortStallExecution(10);
                uVar21 = uVar21 + 1;
                if ((*(uint *)(param_1[0x31e] + 0x40) & 2) == 0) break;
              } while (uVar21 < 100);
              Irb2Slot((longlong)param_1,param_2,param_3);
              Actuate((longlong)param_1);
              goto LAB_1c0003f78;
            }
            *(byte *)(puVar20 + 1) = (byte)puVar20[1] & 0xdf;
            ReleaseSlottedCommand((longlong)param_1,(undefined4 *)puVar23);
            param_2 = (ushort *)
                      (CONCAT71((int7)((ulonglong)puVar23 >> 8),bVar2) & 0xffffffffffffff0f);
            DeslotDeviceSlots((longlong)param_1,bVar30);
            *(uint *)(param_1[0x31e] + 0x40) = *(uint *)(param_1[0x31e] + 0x40) | 2;
            LOCK();
            UNLOCK();
            uVar21 = 0;
            do {
              StorPortStallExecution(10);
              uVar21 = uVar21 + 1;
              if ((*(uint *)(param_1[0x31e] + 0x40) & 2) == 0) break;
            } while (uVar21 < 100);
          }
          else {
            param_2 = puVar20;
            if (uVar3 == 0x201) goto LAB_1c0003ed6;
            if ((int)param_1[2] < 0) {
              *(undefined1 *)(puVar20 + 1) = 0;
              uVar22 = uStack_38;
              goto LAB_1c000400f;
            }
            *(int *)(puVar20 + 0x30) = *(int *)(puVar20 + 0x30) + 1;
            if (*(uint *)(puVar20 + 0x30) < 6) {
              *(undefined1 *)(puVar20 + 1) = 0;
              puVar23 = puVar20;
            }
            else {
              FixIdeTaskFile((longlong)param_1,(longlong)puVar20);
              *(longlong *)(lVar15 + 0x360) = *(longlong *)(lVar15 + 0x360) + 1;
              uStack_38._0_5_ = CONCAT14(0xb1,(uint)uStack_38);
              local_40 = puVar20;
              AhciPortLogError((longlong)param_1,(longlong *)&local_40);
              ReleaseSlottedCommand((longlong)param_1,(undefined4 *)puVar23);
            }
            param_2 = (ushort *)
                      (CONCAT71((int7)((ulonglong)puVar23 >> 8),bVar2) & 0xffffffffffffff0f);
            DeslotDeviceSlots((longlong)param_1,bVar30);
            *(uint *)(param_1[0x31e] + 0x40) = *(uint *)(param_1[0x31e] + 0x40) | 2;
            LOCK();
            UNLOCK();
            uVar21 = 0;
            while( true ) {
              StorPortStallExecution(10);
              uVar21 = uVar21 + 1;
              if ((*(uint *)(param_1[0x31e] + 0x40) & 2) == 0) break;
              if (99 < uVar21) break;
            }
          }
        }
        else {
          uStack_38._0_5_ = CONCAT14(0xc1,(uint)uStack_38);
          uStack_38 = (ulonglong)(uint5)uStack_38;
          AhciPortLogError((longlong)param_1,(longlong *)&local_40);
          param_2 = (ushort *)0x4;
          FireHbaNotification(*param_1,4,(int)param_1[1],0xc1);
          if ((uVar21 >> 0x1e & 1) != 0) {
            uVar22 = CONCAT71((int7)((ulonglong)param_2 >> 8),bVar2) & 0xffffffffffffff0f;
            DeslotDeviceSlots((longlong)param_1,bVar30);
            *(uint *)(param_1[0x31e] + 0x40) = *(uint *)(param_1[0x31e] + 0x40) | 2;
            LOCK();
            UNLOCK();
            uVar21 = 0;
            do {
              StorPortStallExecution(10);
              uVar21 = uVar21 + 1;
              if ((*(uint *)(param_1[0x31e] + 0x40) & 2) == 0) break;
            } while (uVar21 < 100);
            param_2 = (ushort *)(CONCAT71((int7)(uVar22 >> 8),bVar2) & 0xffffffffffffff0f);
            iVar13 = ReadLogExt((longlong)param_1,bVar30);
            if (iVar13 != 0) goto LAB_1c0003f78;
          }
LAB_1c0003ed6:
          pbVar11 = (byte *)((longlong)param_1 + ((longlong)(int)uVar12 >> 3) + 0x1a4c);
          *pbVar11 = *pbVar11 | '\x01' << (uVar12 & 7);
        }
LAB_1c0003f78:
        pbVar11 = (byte *)((longlong)param_1 + ((longlong)(int)uVar12 >> 3) + 0x1a50);
        *pbVar11 = *pbVar11 | '\x01' << (uVar12 & 7);
        *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) | 8;
        uVar22 = uStack_38;
      }
      uStack_38 = uVar22;
      if ((((*(byte *)((longlong)param_1 + ((longlong)(int)uVar29 >> 3) + 0x1a4c) >> (uVar29 & 7) &
            1) == 0) &&
          ((*(byte *)((longlong)param_1 + ((longlong)(int)uVar29 >> 3) + 0x1a50) >> (uVar29 & 7) & 1
           ) == 0)) && ((*(uint *)(param_1 + 2) >> 0xc & 1) == 0)) goto LAB_1c00038f4;
      *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) | 0x1000;
      uVar22 = uStack_38;
    }
    uStack_38 = uVar22;
    uVar22 = uStack_38;
    if ((*(uint *)(param_1 + 2) >> 0xc & 1) == 0) {
      puVar1 = (uint *)(param_1 + 2);
      uVar12 = *puVar1;
      *puVar1 = *puVar1 & 0xff7fffff;
      if ((uVar12 >> 0x17 & 1) != 0) {
        *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) | 0x2000;
      }
      if ((*(uint *)(param_1 + 2) >> 0xd & 1) == 0) {
        return;
      }
      if ((*(uint *)((longlong)param_1 + 300) & ~*(uint *)((longlong)param_1 + 0x1ec)) != 0) {
        return;
      }
      *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) & 0xffffdfff;
      goto LAB_1c000400f;
    }
    if ((*(uint *)((longlong)param_1 + 300) & ~*(uint *)((longlong)param_1 + 0x1ec)) != 0) {
      return;
    }
    *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) & 0xffffefff;
    plVar17 = (longlong *)0x0;
    if (*(int *)((longlong)param_1 + 0x1a4c) != 0) goto LAB_1c000400f;
    *(undefined4 *)(param_1 + 0x34a) = 0;
    StartStopDMAs(param_1,0);
  }
  else {
    StartStopDMAs(param_1,0);
    LOCK();
    *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) & 0xffbfffff;
    UNLOCK();
    if (((char)*(uint *)(param_1[0x31e] + 0x20) < '\0') ||
       ((*(uint *)(param_1[0x31e] + 0x20) & 8) != 0)) {
      uStack_38._0_5_ = CONCAT14(0xa1,(uint)uStack_38);
      AhciPortLogError((longlong)param_1,(longlong *)&local_40);
      uVar26 = 0xa1;
      goto LAB_1c000360a;
    }
    uVar12 = *(uint *)((longlong)param_1 + 300);
    if (uVar12 == 0) {
LAB_1c000366a:
      iVar28 = 1;
      iVar13 = 0;
LAB_1c000369f:
      iVar14 = 0;
    }
    else {
      if ((*(int *)((longlong)param_1 + 0x124) == 0) || ((int)param_1[0x25] != 0)) {
        if (((int)param_1[0x25] != *(int *)((longlong)param_1 + 0x124)) &&
           (*(char *)((longlong)param_1 + 0x1f) != '\0')) goto LAB_1c000366a;
        iVar13 = 1;
        goto LAB_1c000369f;
      }
      iVar14 = 1;
    }
    *(int *)(param_1 + 7) = (int)param_1[7] + iVar14;
    *(int *)((longlong)param_1 + 0x3c) = *(int *)((longlong)param_1 + 0x3c) + iVar13;
    *(int *)(param_1 + 8) = (int)param_1[8] + iVar28;
    if (iVar14 == 0) {
      if (iVar13 != 0) {
        bVar2 = *(byte *)((longlong)param_1 + 0x1a);
        uVar22 = uStack_38;
        if (param_1[(ulonglong)bVar2 + 0x34e] == 0) goto LAB_1c000400f;
        plVar17 = (longlong *)(param_1[(ulonglong)bVar2 + 0x34e] + 0x358);
        *plVar17 = *plVar17 + 1;
        uStack_38._0_5_ = CONCAT14(0xc1,(uint)uStack_38);
        AhciPortLogError((longlong)param_1,(longlong *)&local_40);
        uVar19 = 0;
        FireHbaNotification(*param_1,4,(int)param_1[1],0xc1);
        if ((uVar21 >> 0x1e & 1) != 0) {
          DeslotChannelSlots((longlong)param_1);
          uVar19 = CONCAT71((int7)((ulonglong)uVar19 >> 8),1);
          StartStopDMAs(param_1,(uint)uVar19);
          param_2 = (ushort *)CONCAT71((int7)((ulonglong)uVar19 >> 8),bVar2);
          iVar13 = ReadLogExt((longlong)param_1,bVar2);
          if (0 < iVar13) goto LAB_1c00038f4;
          pbVar11 = (byte *)((longlong)param_1 + ((longlong)(int)(uint)bVar2 >> 3) + 0x1a4c);
          *pbVar11 = *pbVar11 | '\x01' << (bVar2 & 7);
          uVar22 = uStack_38;
          goto LAB_1c000400f;
        }
LAB_1c000384b:
        pbVar11 = (byte *)((longlong)param_1 + ((longlong)(int)(uint)bVar2 >> 3) + 0x1a4c);
        *pbVar11 = *pbVar11 | '\x01' << (bVar2 & 7);
        uVar22 = uStack_38;
        goto LAB_1c000400f;
      }
      uStack_38._0_5_ = CONCAT14(0xd1,(uint)uStack_38);
      AhciPortLogError((longlong)param_1,(longlong *)&local_40);
      uVar26 = 0xd1;
      goto LAB_1c000360a;
    }
    uVar21 = 0;
    if (uVar12 != 0) {
      for (; (uVar12 >> uVar21 & 1) == 0; uVar21 = uVar21 + 1) {
      }
    }
    plVar25 = (longlong *)0x0;
    local_54[0] = uVar12;
    local_48 = uVar21;
    if (uVar12 != 0) {
      pbVar11 = (byte *)((longlong)local_54 + ((longlong)(int)uVar21 >> 3));
      *pbVar11 = *pbVar11 & ~('\x01' << (uVar21 & 7));
      plVar25 = param_1 + (ulonglong)uVar21 * 7 + 0x55;
      local_48 = 0;
      if (local_54[0] != 0) {
        for (; (local_54[0] >> local_48 & 1) == 0; local_48 = local_48 + 1) {
        }
      }
      if (local_54[0] != 0) {
        do {
          pbVar11 = (byte *)((longlong)local_54 + ((longlong)(int)local_48 >> 3));
          *pbVar11 = *pbVar11 & ~('\x01' << (local_48 & 7));
          if (*(int *)((longlong)(param_1 + (ulonglong)local_48 * 7 + 0x55) + 0x2c) -
              *(int *)((longlong)plVar25 + 0x2c) < 0) {
            plVar25 = param_1 + (ulonglong)local_48 * 7 + 0x55;
          }
          local_48 = 0;
          if (local_54[0] != 0) {
            for (; (local_54[0] >> local_48 & 1) == 0; local_48 = local_48 + 1) {
            }
          }
        } while (local_54[0] != 0);
      }
    }
    bVar2 = *(byte *)(plVar25 + 5);
    plVar17 = (longlong *)(ulonglong)bVar2;
    plVar18 = param_1 + (longlong)plVar17 * 7 + 0x55;
    bVar30 = *(byte *)((longlong)plVar18 + 0x29);
    puVar23 = (ushort *)plVar18[1];
    lVar15 = param_1[(ulonglong)bVar30 + 0x34e];
    uVar22 = uStack_38;
    if (lVar15 == 0) goto LAB_1c000400f;
    uVar12 = (uint)bVar2;
    pbVar11 = (byte *)((longlong)param_1 + ((longlong)(int)uVar12 >> 3) + 0x124);
    *pbVar11 = *pbVar11 & ~('\x01' << (uVar12 & 7));
    pbVar11 = (byte *)((longlong)param_1 +
                      ((longlong)(int)uVar12 >> 3) + (ulonglong)bVar30 * 4 + 0x138);
    *pbVar11 = *pbVar11 & ~('\x01' << (uVar12 & 7));
    pbVar11 = (byte *)((longlong)param_1 +
                      ((longlong)(int)(uint)bVar2 >> 3) + (ulonglong)bVar30 * 4 + 0x1b0);
    *pbVar11 = *pbVar11 & ~('\x01' << (bVar2 & 7));
    *(undefined1 *)((longlong)puVar23 + 3) = *(undefined1 *)(param_1[0x31e] + 0x20);
    *(undefined1 *)(puVar23 + 2) = *(undefined1 *)(param_1[0x31e] + 0x21);
    uVar3 = *puVar23;
    *(undefined1 *)(puVar23 + 1) = 3;
    if (uVar3 < 0x100) {
      if (uVar3 == 0x10) {
        AhciHwPresetComplete((longlong)param_1,(longlong)plVar18);
        plVar18[2] = 0;
        plVar18[6] = 0;
        plVar18[1] = 0;
        *(undefined4 *)plVar18 = 0;
        *(undefined4 *)(plVar18 + 5) = 0;
        uVar22 = (longlong)plVar18 + (-0x2a8 - (longlong)param_1);
        auVar4._8_8_ = 0;
        auVar4._0_8_ = uVar22;
        lVar15 = SUB168(ZEXT816(0x2492492492492493) * auVar4,8);
        LOCK();
        uVar12 = (uint)((uVar22 - lVar15 >> 1) + lVar15 >> 5);
        pbVar11 = (byte *)((longlong)param_1 + ((longlong)(int)uVar12 >> 3) + 300);
        *pbVar11 = *pbVar11 & ~('\x01' << (uVar12 & 7));
        UNLOCK();
        DeslotChannelSlots((longlong)param_1);
LAB_1c00037e5:
        puVar16 = (undefined *)CONCAT71((int7)((ulonglong)lVar15 >> 8),1);
        StartStopDMAs(param_1,(uint)puVar16);
        AhciReInitializeChannelTargets((longlong)param_1,puVar16);
        return;
      }
      plVar18[2] = 0;
      plVar18[6] = 0;
      plVar18[1] = 0;
      *(undefined4 *)plVar18 = 0;
      *(undefined4 *)(plVar18 + 5) = 0;
      uVar22 = (longlong)plVar18 + (-0x2a8 - (longlong)param_1);
      if (uVar3 == 0x11) {
        auVar5._8_8_ = 0;
        auVar5._0_8_ = uVar22;
        lVar15 = SUB168(ZEXT816(0x2492492492492493) * auVar5,8);
        LOCK();
        uVar12 = (uint)((uVar22 - lVar15 >> 1) + lVar15 >> 5);
        pbVar11 = (byte *)((longlong)param_1 + ((longlong)(int)uVar12 >> 3) + 300);
        *pbVar11 = *pbVar11 & ~('\x01' << (uVar12 & 7));
        UNLOCK();
        *(undefined1 *)(param_1 + 0x346) = 0;
        bVar2 = (byte)puVar23[3];
        goto LAB_1c000384b;
      }
      auVar6._8_8_ = 0;
      auVar6._0_8_ = uVar22;
      plVar17 = SUB168(ZEXT816(0x2492492492492493) * auVar6,8);
      LOCK();
      uVar12 = (uint)((uVar22 - (longlong)plVar17 >> 1) + (longlong)plVar17 >> 5);
      pbVar11 = (byte *)((longlong)param_1 + ((longlong)(int)uVar12 >> 3) + 300);
      *pbVar11 = *pbVar11 & ~('\x01' << (uVar12 & 7));
      UNLOCK();
    }
    else {
      if (uVar3 == 0x200) {
        param_2 = AhciPortBuildRequestSenseIrb(0x200,puVar23);
        if (param_2 != (ushort *)0x0) {
          plVar18[2] = 0;
          plVar18[6] = 0;
          plVar18[1] = 0;
          *(undefined4 *)plVar18 = 0;
          *(undefined4 *)(plVar18 + 5) = 0;
          uVar22 = (longlong)plVar18 + (-0x2a8 - (longlong)param_1);
          auVar7._8_8_ = 0;
          auVar7._0_8_ = uVar22;
          lVar15 = SUB168(ZEXT816(0x2492492492492493) * auVar7,8);
          LOCK();
          uVar12 = (uint)((uVar22 - lVar15 >> 1) + lVar15 >> 5);
          pbVar11 = (byte *)((longlong)param_1 + ((longlong)(int)uVar12 >> 3) + 300);
          *pbVar11 = *pbVar11 & ~('\x01' << (uVar12 & 7));
          UNLOCK();
          DeslotChannelSlots((longlong)param_1);
          StartStopDMAs(param_1,(uint)CONCAT71((int7)((ulonglong)lVar15 >> 8),1));
          Irb2Slot((longlong)param_1,param_2,plVar25);
          Actuate((longlong)param_1);
          goto LAB_1c00038f4;
        }
        *(byte *)(puVar23 + 1) = (byte)puVar23[1] & 0xdf;
      }
      else {
        if (uVar3 == 0x201) goto LAB_1c000400f;
        if ((int)param_1[2] < 0) {
          *(undefined1 *)(puVar23 + 1) = 0;
          goto LAB_1c000400f;
        }
        *(int *)(puVar23 + 0x30) = *(int *)(puVar23 + 0x30) + 1;
        if (*(uint *)(puVar23 + 0x30) < 6) {
          *(undefined1 *)(puVar23 + 1) = 0;
          goto LAB_1c0003970;
        }
        FixIdeTaskFile((longlong)param_1,(longlong)puVar23);
        *(longlong *)(lVar15 + 0x360) = *(longlong *)(lVar15 + 0x360) + 1;
        uStack_38._0_5_ = CONCAT14(0xb1,(uint)uStack_38);
        local_40 = puVar23;
        AhciPortLogError((longlong)param_1,(longlong *)&local_40);
      }
      ReleaseSlottedCommand((longlong)param_1,(undefined4 *)plVar18);
      plVar17 = plVar18;
    }
LAB_1c0003970:
    DeslotChannelSlots((longlong)param_1);
  }
  param_2 = (ushort *)CONCAT71((int7)((ulonglong)plVar17 >> 8),1);
  StartStopDMAs(param_1,(uint)param_2);
LAB_1c00038f4:
  *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) | 0x20;
  AhciPortRequestWorkerRoutine((longlong)param_1,(ulonglong)param_2);
  return;
code_r0x0001c0003bc6:
  uVar21 = 0;
  bVar31 = local_58 == 0;
  if (!bVar31) {
    for (; (local_58 >> uVar21 & 1) == 0; uVar21 = uVar21 + 1) {
    }
  }
  goto LAB_1c0003bca;
}



===== ChannelWorkerDpcRoutine @ 1c0004040 =====

void ChannelWorkerDpcRoutine(longlong param_1,undefined *param_2)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  byte bVar4;
  
  if ((*(uint *)(param_1 + 0x10) & 0xffff000) == 0) {
    LOCK();
    puVar1 = (uint *)(param_1 + 0x10);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 & 0xffffffdf;
    UNLOCK();
    if ((uVar2 >> 5 & 1) == 0) {
      LOCK();
      puVar1 = (uint *)(param_1 + 0x10);
      uVar2 = *puVar1;
      *puVar1 = *puVar1 & 0xffffffef;
      UNLOCK();
      if ((uVar2 >> 4 & 1) == 0) {
        return;
      }
    }
    else {
      LOCK();
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffff3;
      UNLOCK();
      lVar3 = *(longlong *)(param_1 + -0x98);
      bVar4 = 0;
      if (*(char *)(lVar3 + 0x1d) != '\0') {
        do {
          StorPortResumeDevice(lVar3,*(undefined1 *)(param_1 + -0x8c),bVar4,0);
          bVar4 = bVar4 + 1;
        } while (bVar4 < *(byte *)(lVar3 + 0x1d));
      }
    }
    DepleteWorkerDispatch(param_1);
  }
  else {
    LOCK();
    puVar1 = (uint *)(param_1 + 0x10);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 & 0xfeffffff;
    UNLOCK();
    if ((uVar2 >> 0x18 & 1) == 0) {
      AhciPortRequestSynchronizedRoutine(param_1,AhciChannelError);
    }
    else if (*(int *)(param_1 + 0xf4) == 0xa000) {
      AhciReInitializeChannelTargets(param_1,param_2);
    }
  }
  return;
}



===== ChannelTurnOffPHYClockTimerRoutine @ 1c00040f0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ChannelTurnOffPHYClockTimerRoutine(longlong param_1,longlong param_2)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 in_stack_ffffffffffffffe0;
  undefined4 uVar3;
  undefined8 in_stack_ffffffffffffffe8;
  undefined4 uVar4;
  
  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffffe0 >> 0x20);
  uVar4 = (undefined4)((ulonglong)in_stack_ffffffffffffffe8 >> 0x20);
  if ((((g_bIsKernCZBP != '\0') && (*(int *)(param_2 + 0xf4) == 0)) &&
      (((byte)*(undefined4 *)(param_2 + 0x10) & 6) == 2)) && (*(char *)(param_2 + -8) == '\x01')) {
    uVar2 = AhciCheckAllPortsSlotIdle(param_1);
    if ((char)uVar2 != '\0') {
      LOCK();
      uVar1 = _g_lOutstandingIO & 1;
      _g_lOutstandingIO = _g_lOutstandingIO & 0xfffffffe;
      UNLOCK();
      if (uVar1 == 0) {
        LOCK();
        uVar1 = g_lPHYClock >> 0x1c;
        g_lPHYClock = g_lPHYClock & 0xefffffff;
        UNLOCK();
        if ((uVar1 & 1) == 0) {
          return;
        }
        StorPortSetBusDataByOffset
                  (param_1,4,*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x84),
                   &g_lPHYClock,CONCAT44(uVar3,0x84),CONCAT44(uVar4,4));
        return;
      }
    }
    StorPortExtendedFunction
              (0x21,param_1,*(undefined8 *)(param_1 + 0x3e0),ChannelTurnOffPHYClockTimerRoutine,
               param_2,80000,80000);
  }
  return;
}



===== AhciAdapterStart @ 1c00041ac =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong AhciAdapterStart(undefined4 *param_1,short *param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  undefined1 uVar5;
  ulonglong in_RAX;
  ulonglong uVar6;
  byte bVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  byte bVar11;
  bool bVar12;
  uint local_res8 [2];
  uint local_res10;
  
  bVar11 = 0x20;
  _ahci_controller_ext = param_1;
  if (*param_2 == 0x20) {
    uVar8 = **(uint **)(param_2 + 0xc);
    if (uVar8 != 0) {
      lVar2 = *(longlong *)(*(uint **)(param_2 + 0xc) + 2);
      local_res10 = 0;
      do {
        in_RAX = (ulonglong)local_res10;
        if (((*(char *)(lVar2 + 0x14 + in_RAX * 0x18) != '\0') &&
            (*(longlong *)(lVar2 + in_RAX * 0x18) != 0)) &&
           (0x17f < *(uint *)(lVar2 + 0x10 + in_RAX * 0x18))) {
          uVar8 = *(uint *)(lVar2 + 0x10 + (ulonglong)local_res10 * 0x18);
          in_RAX = (ulonglong)uVar8;
          if (*(longlong *)(param_1 + -0x3736) == 0) {
            in_RAX = StorPortGetDeviceBase
                               (param_1 + -0x380a,5,param_1[-0x3801],
                                *(undefined8 *)(lVar2 + (ulonglong)local_res10 * 0x18),uVar8,0);
            *(ulonglong *)(param_1 + -0x3736) = in_RAX;
          }
          puVar3 = *(undefined4 **)(param_1 + -0x3736);
          *(undefined4 **)(param_1 + 2) = puVar3;
          if (puVar3 != (undefined4 *)0x0) {
            if (*(int *)(param_2 + 2) != 1) goto LAB_1c00042ad;
            puVar3[1] = 1;
            LOCK();
            UNLOCK();
            iVar9 = 0;
            goto LAB_1c0004291;
          }
          break;
        }
        local_res10 = local_res10 + 1;
      } while (local_res10 < uVar8);
    }
  }
  goto LAB_1c0004218;
  while (iVar9 < 1000) {
LAB_1c0004291:
    StorPortStallExecution(1000);
    iVar9 = iVar9 + 1;
    if ((puVar3[1] & 1) == 0) break;
  }
LAB_1c00042ad:
  uVar10 = 0x80000000;
  puVar3[1] = 0x80000000;
  LOCK();
  UNLOCK();
  uVar8 = puVar3[4];
  in_RAX = (ulonglong)uVar8;
  param_1[5] = uVar8;
  if (uVar8 != 0) {
    param_1[9] = *puVar3;
    param_1[10] = puVar3[9];
    param_1[0xb] = puVar3[1];
    if ((char)param_1[9] < '\0') {
      uVar8 = puVar3[5];
      param_1[0x11] = uVar8 >> 3 & 0x1f;
      uVar8 = param_1[0x12] & 0xffffff06 | uVar8 & 0xf8;
      param_1[0x12] = uVar8;
      puVar3[5] = uVar8;
      LOCK();
      UNLOCK();
      puVar3[6] = 0;
      LOCK();
      UNLOCK();
      param_1[0xe] = 0;
    }
    else {
      param_1[0xd] = 0;
      param_1[0x11] = 0x20;
    }
    InitEnclosureManagement((longlong)param_1);
    uVar8 = puVar3[3];
    local_res8[0] = uVar8;
    local_res10 = 0;
    bVar12 = uVar8 == 0;
    if (!bVar12) {
      for (; (uVar8 >> local_res10 & 1) == 0; local_res10 = local_res10 + 1) {
      }
    }
    while( true ) {
      uVar6 = (ulonglong)local_res10;
      if (bVar12) break;
      pbVar4 = (byte *)((longlong)local_res8 + ((longlong)(int)local_res10 >> 3));
      *pbVar4 = *pbVar4 & ~('\x01' << (local_res10 & 7));
      puVar3[uVar6 * 0x20 + 0x45] = 0;
      LOCK();
      UNLOCK();
      puVar3[uVar6 * 0x20 + 0x4c] = 0;
      LOCK();
      UNLOCK();
      puVar3[uVar6 * 0x20 + 0x44] = 0xffffffff;
      LOCK();
      UNLOCK();
      local_res10 = 0;
      bVar12 = local_res8[0] == 0;
      if (!bVar12) {
        for (; (local_res8[0] >> local_res10 & 1) == 0; local_res10 = local_res10 + 1) {
        }
      }
    }
    param_1[0xc] = uVar8;
    if ((*(int *)(param_2 + 2) != 0) || (uVar5 = 1, (param_1[9] & 0x30000) != 0x30000)) {
      uVar5 = 0;
    }
    *(undefined1 *)((longlong)param_1 + 0x5e) = uVar5;
    do {
      if ((uVar8 & uVar10) != 0) break;
      uVar10 = uVar10 >> 1;
      bVar11 = bVar11 - 1;
    } while (uVar10 != 0);
    bVar7 = *(byte *)(param_2 + 1);
    if (bVar11 <= *(byte *)(param_2 + 1)) {
      bVar7 = bVar11;
    }
    *(byte *)(param_2 + 1) = bVar7;
    uVar1 = puVar3[2];
    puVar3[2] = uVar1;
    LOCK();
    UNLOCK();
    puVar3[1] = 0x80000002;
    iVar9 = AmdSataSgl;
    LOCK();
    UNLOCK();
    *(int *)(param_2 + 4) = AmdSataSgl;
    *(int *)(param_2 + 6) = iVar9 << 0xc;
    *(undefined1 *)((longlong)param_2 + 0x11) = 1;
    *(undefined1 *)((longlong)param_2 + 0x13) = 1;
    *(byte *)(param_2 + 9) = (byte)((uint)param_1[9] >> 0x1f);
    *param_1 = 0x49434841;
    return CONCAT71((uint7)(uint3)((uint)uVar1 >> 8),1);
  }
LAB_1c0004218:
  return in_RAX & 0xffffffffffffff00;
}



===== AhciChannelStart @ 1c0004408 =====

ulonglong AhciChannelStart(longlong *param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4
                          )

{
  char cVar1;
  undefined1 uVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  uint uVar8;
  
  lVar6 = *param_1;
  cVar1 = *(char *)(lVar6 + 0x5e);
  uVar8 = AmdSataSgl * 0x10 + 0x10fU & 0xffffff80;
  if (*(char *)((longlong)param_1 + 0x23) == '\0') {
    if ((((*(uint *)(lVar6 + 0x24) & 0x20) != 0) &&
        ((*(uint *)(param_1[0x31e] + 0x18) >> 0x15 & 1) != 0)) ||
       (uVar2 = 0, (*(uint *)(param_1[0x31e] + 0x18) >> 0x12 & 1) != 0)) {
      uVar2 = 1;
    }
    *(undefined1 *)((longlong)param_1 + 0x23) = uVar2;
  }
  *(undefined1 *)((longlong)param_1 + 0x24) = 0;
  if ((*(uint *)(lVar6 + 0x28) & 8) != 0) {
    *(byte *)((longlong)param_1 + 0x24) = (byte)(*(uint *)(param_1[0x31e] + 0x44) >> 1) & 1;
  }
  *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) & 0xf;
  uVar3 = *(uint *)(param_1 + 2);
  *(uint *)(param_1 + 2) = (uint)*(byte *)(lVar6 + 0xa3) << 0x1f | uVar3 & 0x7fffffff;
  uVar4 = (ulonglong)CONCAT31((int3)((uVar3 & 0x7fffffff) >> 8),*(undefined1 *)(lVar6 + 0xa4));
  lVar5 = param_1[-0x13];
  *(undefined1 *)((longlong)param_1 + 0x25) = *(undefined1 *)(lVar6 + 0xa4);
  lVar6 = *(longlong *)(lVar5 + 0x358);
  if (lVar6 == 0) {
    lVar6 = 0;
  }
  else {
    if ((*(uint *)(lVar5 + 0x18) >> 2 & 1) == 0) {
      uVar3 = *(int *)(lVar5 + 0x360) * *(int *)((longlong)param_1 + -0x8c);
      uVar4 = (ulonglong)uVar3;
      lVar6 = lVar6 + (ulonglong)uVar3;
    }
    uVar3 = 0;
    if (*(int *)(lVar5 + 0x360) != 0) {
      do {
        uVar4 = (ulonglong)uVar3;
        uVar3 = uVar3 + 1;
        *(undefined1 *)(uVar4 + lVar6) = 0;
      } while (uVar3 < *(uint *)(lVar5 + 0x360));
    }
  }
  if (lVar6 != 0) {
    if (cVar1 == '\0') {
      uVar4 = AhciPortGetPhysicalAddress((longlong)param_1,0,lVar6,param_4);
      if ((uVar4 != 0) && ((uVar4 & 0x3ff) == 0)) {
        param_1[0x323] = lVar6;
        param_1[800] = uVar4;
        *(int *)param_1[0x31e] = (int)uVar4;
        LOCK();
        UNLOCK();
        *(int *)(param_1[0x31e] + 4) = (int)(uVar4 >> 0x20);
        LOCK();
        UNLOCK();
        uVar4 = AhciPortGetPhysicalAddress((longlong)param_1,0,lVar6 + 0x400,param_4);
        if ((uVar4 != 0) && ((char)uVar4 == '\0')) {
          param_1[0x344] = lVar6 + 0x400;
          param_1[0x321] = uVar4;
          *(int *)(param_1[0x31e] + 8) = (int)uVar4;
          LOCK();
          UNLOCK();
          *(int *)(param_1[0x31e] + 0xc) = (int)(uVar4 >> 0x20);
          LOCK();
          UNLOCK();
          lVar6 = lVar6 + 0x500;
LAB_1c0004661:
          if ((int)param_1[5] != 0) {
            uVar7 = 0;
            uVar4 = 0;
            do {
              param_1[uVar4 + 0x324] = uVar7 + lVar6;
              lVar5 = AhciPortGetPhysicalAddress((longlong)param_1,0,uVar7 + lVar6,param_4);
              uVar3 = (int)uVar4 + 1;
              uVar7 = (ulonglong)((int)uVar7 + uVar8);
              param_1[uVar4 * 7 + 0x59] = lVar5;
              uVar4 = (ulonglong)uVar3;
            } while (uVar3 < *(uint *)(param_1 + 5));
          }
          lVar6 = lVar6 + (ulonglong)((int)param_1[5] * uVar8);
          param_1[0x345] = lVar6;
          lVar6 = AhciPortGetPhysicalAddress((longlong)param_1,0,lVar6,param_4);
          *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) | 1;
          param_1[0x322] = lVar6;
          *(undefined4 *)((longlong)param_1 + 0x134) = 0;
          *(undefined8 *)((longlong)param_1 + 0x124) = 0;
          *(undefined1 *)(param_1 + 3) = 0;
          *(undefined4 *)((longlong)param_1 + 300) = 0;
          *(undefined2 *)((longlong)param_1 + 0x21) = 0;
          *(undefined4 *)((longlong)param_1 + 0xf4) = 0;
          *(undefined4 *)(param_1[0x31e] + 0x14) = 0;
          LOCK();
          UNLOCK();
          StartStopDMAs(param_1,0);
          *(undefined4 *)(param_1[0x31e] + 0x18) = 0;
          LOCK();
          UNLOCK();
          *(undefined4 *)(param_1[0x31e] + 0x30) = 0xffffffff;
          LOCK();
          UNLOCK();
          *(undefined4 *)(param_1[0x31e] + 0x10) = 0xffffffff;
          LOCK();
          UNLOCK();
          *(int *)param_1[0x31d] = 1 << ((byte)param_1[1] & 0x1f);
          LOCK();
          UNLOCK();
          uVar8 = *(uint *)(param_1[0x31e] + 0x18) & 0xffffa000;
          *(uint *)((longlong)param_1 + 0x34) =
               ((uint)(*(char *)((longlong)param_1 + 0x23) != '\0') << 0xb | uVar8) << 0xb |
               *(uint *)(param_1 + 799) >> 0x15 & 0x80 |
               *(uint *)(param_1[0x31e] + 0x14) & 0x23fff00 | 0x7d00005f;
          return CONCAT71((uint7)(uint3)(uVar8 >> 8),1);
        }
      }
    }
    else {
      uVar4 = AhciPortGetPhysicalAddress((longlong)param_1,0,lVar6,param_4);
      if ((uVar4 != 0) && ((uVar4 & 0xfff) == 0)) {
        param_1[0x344] = lVar6;
        param_1[0x321] = uVar4;
        *(int *)(param_1[0x31e] + 8) = (int)uVar4;
        LOCK();
        UNLOCK();
        *(int *)(param_1[0x31e] + 0xc) = (int)(uVar4 >> 0x20);
        LOCK();
        UNLOCK();
        uVar4 = AhciPortGetPhysicalAddress((longlong)param_1,0,lVar6 + 0x1000,param_4);
        if ((uVar4 != 0) && ((uVar4 & 0x3ff) == 0)) {
          param_1[0x323] = lVar6 + 0x1000;
          param_1[800] = uVar4;
          *(int *)param_1[0x31e] = (int)uVar4;
          LOCK();
          UNLOCK();
          *(int *)(param_1[0x31e] + 4) = (int)(uVar4 >> 0x20);
          LOCK();
          UNLOCK();
          lVar6 = lVar6 + 0x1400;
          goto LAB_1c0004661;
        }
      }
    }
  }
  return uVar4 & 0xffffffffffffff00;
}



===== DeslotChannelSlots @ 1c00047b8 =====

void DeslotChannelSlots(longlong param_1)

{
  undefined1 auVar1 [16];
  byte *pbVar2;
  uint uVar3;
  undefined4 *puVar4;
  longlong lVar5;
  undefined4 *puVar6;
  ulonglong uVar7;
  uint local_res8 [2];
  uint local_res10;
  
  while( true ) {
    local_res8[0] = *(uint *)(param_1 + 300);
    uVar3 = 0;
    if (local_res8[0] != 0) {
      for (; (local_res8[0] >> uVar3 & 1) == 0; uVar3 = uVar3 + 1) {
      }
    }
    if (local_res8[0] == 0) break;
    pbVar2 = (byte *)((longlong)local_res8 + ((longlong)(int)uVar3 >> 3));
    *pbVar2 = *pbVar2 & ~('\x01' << (uVar3 & 7));
    puVar6 = (undefined4 *)(param_1 + 0x2a8 + (ulonglong)uVar3 * 0x38);
    local_res10 = 0;
    if (local_res8[0] != 0) {
      for (; (local_res8[0] >> local_res10 & 1) == 0; local_res10 = local_res10 + 1) {
      }
    }
    if (local_res8[0] != 0) {
      do {
        pbVar2 = (byte *)((longlong)local_res8 + ((longlong)(int)local_res10 >> 3));
        *pbVar2 = *pbVar2 & ~('\x01' << (local_res10 & 7));
        puVar4 = (undefined4 *)(param_1 + 0x2a8 + (ulonglong)local_res10 * 0x38);
        if (0 < (int)(puVar4[0xb] - puVar6[0xb])) {
          puVar6 = puVar4;
        }
        local_res10 = 0;
        if (local_res8[0] != 0) {
          for (; (local_res8[0] >> local_res10 & 1) == 0; local_res10 = local_res10 + 1) {
          }
        }
      } while (local_res8[0] != 0);
    }
    if (puVar6 == (undefined4 *)0x0) break;
    if (0xff < **(ushort **)(puVar6 + 2)) {
      lVar5 = *(longlong *)(param_1 + 0x1a70 + (ulonglong)*(byte *)((longlong)puVar6 + 0x29) * 8);
      uVar3 = *(int *)(lVar5 + 0x224) - 1U & 0x1f;
      *(ushort **)(lVar5 + 0x228 + (ulonglong)uVar3 * 8) = *(ushort **)(puVar6 + 2);
      *(int *)(lVar5 + 0x21c) = *(int *)(lVar5 + 0x21c) + 1;
      *(uint *)(lVar5 + 0x224) = uVar3;
      *(int *)(param_1 + 0x18d4) = *(int *)(param_1 + 0x18d4) + 1;
    }
    *(undefined8 *)(puVar6 + 4) = 0;
    *(undefined8 *)(puVar6 + 0xc) = 0;
    *(undefined8 *)(puVar6 + 2) = 0;
    *puVar6 = 0;
    puVar6[10] = 0;
    uVar7 = (longlong)puVar6 + (-0x2a8 - param_1);
    auVar1._8_8_ = 0;
    auVar1._0_8_ = uVar7;
    lVar5 = SUB168(ZEXT816(0x2492492492492493) * auVar1,8);
    LOCK();
    uVar3 = (uint)((uVar7 - lVar5 >> 1) + lVar5 >> 5);
    pbVar2 = (byte *)(param_1 + 300 + ((longlong)(int)uVar3 >> 3));
    *pbVar2 = *pbVar2 & ~('\x01' << (uVar3 & 7));
    UNLOCK();
  }
  *(undefined8 *)(param_1 + 0x128) = 0;
  lVar5 = 0xf;
  *(undefined1 *)(param_1 + 0x18) = 0;
  *(undefined8 *)(param_1 + 0x18cc) = 0;
  *(undefined4 *)(param_1 + 0x18c8) = 0;
  *(undefined4 *)(param_1 + 0x124) = 0;
  puVar6 = (undefined4 *)(param_1 + 0x174);
  do {
    puVar6[0xf] = 0;
    *puVar6 = 0;
    puVar6[-0xf] = 0;
    puVar6 = puVar6 + 1;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  return;
}



===== DeslotDeviceSlots @ 1c0004900 =====

void DeslotDeviceSlots(longlong param_1,byte param_2)

{
  uint *puVar1;
  byte bVar2;
  longlong lVar3;
  undefined1 auVar4 [16];
  byte *pbVar5;
  uint uVar6;
  longlong lVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  bool bVar12;
  uint local_res8 [2];
  uint local_res10 [2];
  uint local_res18;
  
  local_res8[0] = 0xffffffff;
  uVar11 = (ulonglong)param_2;
  lVar3 = *(longlong *)(param_1 + 0x1a70 + (ulonglong)param_2 * 8);
  while( true ) {
    local_res10[0] = *(uint *)(param_1 + 300);
    uVar6 = 0;
    bVar12 = local_res10[0] == 0;
    if (!bVar12) {
      for (; (local_res10[0] >> uVar6 & 1) == 0; uVar6 = uVar6 + 1) {
      }
    }
    while( true ) {
      if (bVar12) goto LAB_1c0004a2d;
      pbVar5 = (byte *)((longlong)local_res10 + ((longlong)(int)uVar6 >> 3));
      *pbVar5 = *pbVar5 & ~('\x01' << (uVar6 & 7));
      puVar9 = (undefined4 *)(param_1 + 0x2a8 + (ulonglong)uVar6 * 0x38);
      if (param_2 == *(byte *)((longlong)puVar9 + 0x29)) break;
      uVar6 = 0;
      bVar12 = local_res10[0] == 0;
      if (!bVar12) {
        for (; (local_res10[0] >> uVar6 & 1) == 0; uVar6 = uVar6 + 1) {
        }
      }
    }
    uVar6 = 0;
    if (local_res10[0] != 0) {
      for (; (local_res10[0] >> uVar6 & 1) == 0; uVar6 = uVar6 + 1) {
      }
    }
    local_res18 = uVar6;
    if (local_res10[0] != 0) {
      do {
        pbVar5 = (byte *)((longlong)local_res10 + ((longlong)(int)uVar6 >> 3));
        *pbVar5 = *pbVar5 & ~('\x01' << (uVar6 & 7));
        puVar8 = (undefined4 *)(param_1 + 0x2a8 + (ulonglong)uVar6 * 0x38);
        if ((param_2 == *(byte *)((longlong)puVar8 + 0x29)) &&
           (0 < (int)(puVar8[0xb] - puVar9[0xb]))) {
          puVar9 = puVar8;
        }
        uVar6 = 0;
        if (local_res10[0] != 0) {
          for (; (local_res10[0] >> uVar6 & 1) == 0; uVar6 = uVar6 + 1) {
          }
        }
      } while (local_res10[0] != 0);
      local_res18 = uVar6;
    }
    if (puVar9 == (undefined4 *)0x0) break;
    if (0xff < **(ushort **)(puVar9 + 2)) {
      uVar6 = *(int *)(lVar3 + 0x224) - 1U & 0x1f;
      *(ushort **)(lVar3 + 0x228 + (ulonglong)uVar6 * 8) = *(ushort **)(puVar9 + 2);
      *(int *)(lVar3 + 0x21c) = *(int *)(lVar3 + 0x21c) + 1;
      *(uint *)(lVar3 + 0x224) = uVar6;
      *(int *)(param_1 + 0x18d4) = *(int *)(param_1 + 0x18d4) + 1;
    }
    bVar2 = *(byte *)(puVar9 + 10);
    puVar9[10] = 0;
    *(undefined8 *)(puVar9 + 4) = 0;
    *(undefined8 *)(puVar9 + 0xc) = 0;
    *(undefined8 *)(puVar9 + 2) = 0;
    *puVar9 = 0;
    pbVar5 = (byte *)((longlong)local_res8 + ((longlong)(int)(uint)bVar2 >> 3));
    *pbVar5 = *pbVar5 & ~('\x01' << (bVar2 & 7));
    uVar10 = (longlong)puVar9 + (-0x2a8 - param_1);
    auVar4._8_8_ = 0;
    auVar4._0_8_ = uVar10;
    lVar7 = SUB168(ZEXT816(0x2492492492492493) * auVar4,8);
    LOCK();
    uVar6 = (uint)((uVar10 - lVar7 >> 1) + lVar7 >> 5);
    pbVar5 = (byte *)(param_1 + 300 + ((longlong)(int)uVar6 >> 3));
    *pbVar5 = *pbVar5 & ~('\x01' << (uVar6 & 7));
    UNLOCK();
  }
LAB_1c0004a2d:
  *(uint *)(param_1 + 0x128) = *(uint *)(param_1 + 0x128) & local_res8[0];
  *(uint *)(param_1 + 0x124) = *(uint *)(param_1 + 0x124) & local_res8[0];
  puVar1 = (uint *)(param_1 + 0x174 + uVar11 * 4);
  *puVar1 = *puVar1 & local_res8[0];
  puVar1 = (uint *)(param_1 + 0x138 + uVar11 * 4);
  *puVar1 = *puVar1 & local_res8[0];
  puVar1 = (uint *)(param_1 + 0x1b0 + uVar11 * 4);
  *puVar1 = *puVar1 & local_res8[0];
  return;
}



===== ReleaseSlottedCommand @ 1c0004a60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 ReleaseSlottedCommand(longlong param_1,undefined4 *param_2)

{
  ushort *puVar1;
  undefined1 auVar2 [16];
  byte *pbVar3;
  undefined8 uVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  
  puVar1 = *(ushort **)(param_2 + 2);
  if (*puVar1 == 0x201) {
    puVar1[8] = 0;
    puVar1[9] = 0;
    if ((char)puVar1[1] == '\x01') {
      *(char *)((longlong)puVar1 + 9) = (char)puVar1[0xc];
      *(undefined1 *)(puVar1 + 1) = 0x23;
    }
    else {
      *(undefined1 *)(puVar1 + 1) = 3;
    }
  }
  if ((*(code **)(puVar1 + 0x18) == (code *)0x0) ||
     (uVar4 = (**(code **)(puVar1 + 0x18))(param_1,puVar1), (char)uVar4 != '\0')) {
    AhciPortCompleteRequest(param_1,puVar1);
    *(undefined8 *)(param_2 + 4) = 0;
    *(undefined8 *)(param_2 + 0xc) = 0;
    *(undefined8 *)(param_2 + 2) = 0;
    *param_2 = 0;
    param_2[10] = 0;
    uVar7 = (longlong)param_2 + (-0x2a8 - param_1);
    auVar2._8_8_ = 0;
    auVar2._0_8_ = uVar7;
    lVar5 = SUB168(ZEXT816(0x2492492492492493) * auVar2,8);
    LOCK();
    uVar6 = (uint)((uVar7 - lVar5 >> 1) + lVar5 >> 5);
    pbVar3 = (byte *)(param_1 + 300 + ((longlong)(int)uVar6 >> 3));
    *pbVar3 = *pbVar3 & ~('\x01' << (uVar6 & 7));
    UNLOCK();
    return SUB168(ZEXT816(0x2492492492492493) * auVar2,0);
  }
  return uVar4;
}



===== GetSlot @ 1c0004b10 =====

undefined4 * GetSlot(longlong param_1)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 *puVar3;
  uint uVar4;
  longlong lVar5;
  uint uVar6;
  
  uVar6 = (uint)*(byte *)(param_1 + 0x19);
  uVar4 = (uint)*(byte *)(param_1 + 0x18);
  do {
    LOCK();
    pbVar1 = (byte *)(param_1 + 300 + ((longlong)(int)uVar4 >> 3));
    bVar2 = *pbVar1;
    *pbVar1 = *pbVar1 | '\x01' << (uVar4 & 7);
    UNLOCK();
    if ((bVar2 >> (uVar4 & 7) & 1) == 0) {
      *(char *)(param_1 + 0x18) =
           (char)((ulonglong)(uVar4 + 1) % (ulonglong)(longlong)(int)(uint)*(byte *)(param_1 + 0x19)
                 );
      lVar5 = (ulonglong)uVar4 * 0x20 + *(longlong *)(param_1 + 0x1918);
      puVar3 = (undefined4 *)((ulonglong)uVar4 * 0x38 + 0x2a8 + param_1);
      *(longlong *)(puVar3 + 4) = lVar5;
      *(undefined8 *)(puVar3 + 6) = *(undefined8 *)(param_1 + 0x1920 + (ulonglong)uVar4 * 8);
      *(undefined4 *)(lVar5 + 8) = puVar3[8];
      *(undefined4 *)(*(longlong *)(puVar3 + 4) + 0xc) = puVar3[9];
      *puVar3 = 0;
      *(undefined1 *)((longlong)puVar3 + 0x2a) = 1;
      *(char *)(puVar3 + 10) = (char)uVar4;
      puVar3[0xb] = *(undefined4 *)(param_1 + 0x134);
      *(int *)(param_1 + 0x134) = *(int *)(param_1 + 0x134) + 1;
      return puVar3;
    }
    uVar4 = (uint)((ulonglong)(uVar4 + 1) %
                  (ulonglong)(longlong)(int)(uint)*(byte *)(param_1 + 0x19));
    uVar6 = uVar6 - 1;
  } while (uVar6 != 0);
  return (undefined4 *)0x0;
}



===== IRBtoATA_CFIS @ 1c0004bac =====

undefined8 IRBtoATA_CFIS(longlong param_1,uint *param_2)

{
  byte bVar1;
  longlong lVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  
  lVar2 = *(longlong *)(param_2 + 2);
  puVar3 = *(undefined8 **)(param_2 + 6);
  *puVar3 = 0;
  puVar3[1] = 0;
  *(undefined4 *)(puVar3 + 2) = 0;
  *(byte *)((longlong)puVar3 + 1) = *(byte *)((longlong)puVar3 + 1) | 0x80;
  *(undefined1 *)puVar3 = 0x27;
  *(undefined1 *)((longlong)puVar3 + 2) = *(undefined1 *)(lVar2 + 0x6a);
  bVar1 = *(byte *)(lVar2 + 6);
  *(undefined1 *)((longlong)puVar3 + 7) = 0x40;
  *(byte *)((longlong)puVar3 + 1) =
       *(byte *)((longlong)puVar3 + 1) ^ (*(byte *)((longlong)puVar3 + 1) ^ bVar1) & 0xf;
  if ((*(uint *)(lVar2 + 0x10) & 0x20000) == 0) {
    *(byte *)((longlong)puVar3 + 7) = *(byte *)(lVar2 + 0x6e) & 0xf | 0x40;
    *(undefined1 *)((longlong)puVar3 + 3) = *(undefined1 *)(lVar2 + 100);
    *(undefined1 *)((longlong)puVar3 + 0xb) = *(undefined1 *)(lVar2 + 0x6c);
    *(undefined1 *)((longlong)puVar3 + 0xc) = *(undefined1 *)(lVar2 + 0x65);
    *(undefined1 *)((longlong)puVar3 + 0xd) = *(undefined1 *)(lVar2 + 0x6d);
  }
  else {
    *(undefined1 *)((longlong)puVar3 + 3) = *(undefined1 *)(lVar2 + 0x65);
    *(undefined1 *)((longlong)puVar3 + 0xb) = *(undefined1 *)(lVar2 + 0x6d);
    *(char *)((longlong)puVar3 + 0xc) = (char)param_2[10] << 3;
    *(byte *)((longlong)puVar3 + 0xd) = (byte)(*(uint *)(lVar2 + 0x10) >> 2) & 0x80;
    *(byte *)((longlong)puVar3 + 7) = (byte)(*param_2 >> 9) & 0xc0 | 0x40;
  }
  *(undefined1 *)((longlong)puVar3 + 4) = *(undefined1 *)(lVar2 + 0x66);
  *(undefined1 *)(puVar3 + 1) = *(undefined1 *)(lVar2 + 0x6e);
  *(undefined1 *)((longlong)puVar3 + 5) = *(undefined1 *)(lVar2 + 0x67);
  *(undefined1 *)((longlong)puVar3 + 9) = *(undefined1 *)(lVar2 + 0x6f);
  *(undefined1 *)((longlong)puVar3 + 6) = *(undefined1 *)(lVar2 + 0x68);
  *(undefined1 *)((longlong)puVar3 + 10) = *(undefined1 *)(lVar2 + 0x70);
  uVar4 = (ulonglong)*(uint *)(param_1 + 0x10);
  if (((((int)*(uint *)(param_1 + 0x10) < 0) && (*(int *)(param_1 + 0xc) == 0x101)) &&
      (*param_2 != 0)) && (AmdSataHints != '\0')) {
    uVar4 = (ulonglong)*(byte *)(lVar2 + 6);
    lVar2 = *(longlong *)(param_1 + 0x1a70 + uVar4 * 8);
    if ((*(char *)(lVar2 + 0x494) != '\0') && (*(char *)(lVar2 + 0x495) != '\0')) {
      uVar4 = 0;
      *(byte *)((longlong)puVar3 + 0x12) =
           *(byte *)(lVar2 + 0x496) & 0xf | *(byte *)((longlong)puVar3 + 0x12) & 0xf0 | 0x20;
    }
  }
  return CONCAT71((int7)(uVar4 >> 8),1);
}



===== IRBtoPRDT @ 1c0004cdc =====

ulonglong IRBtoPRDT(longlong param_1,longlong param_2,undefined8 param_3,ulonglong param_4)

{
  ushort uVar1;
  ushort *puVar2;
  longlong lVar3;
  uint *puVar4;
  uint uVar5;
  undefined8 uVar6;
  longlong lVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  uint uVar11;
  uint uVar12;
  ulonglong uVar13;
  uint uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  undefined8 local_res10;
  
  puVar2 = *(ushort **)(param_2 + 8);
  lVar3 = *(longlong *)(param_2 + 0x18);
  uVar1 = *puVar2;
  if (uVar1 == 0x201) {
LAB_1c0004e79:
    if (0xff < uVar1) {
      uVar6 = AhciPortGetPhysicalAddress
                        (param_1,(longlong)puVar2,*(longlong *)(puVar2 + 0x1c),param_4);
      goto LAB_1c0004e94;
    }
  }
  else if (0xff < uVar1) {
    if (uVar1 < 0x901) {
      uVar9 = *(uint *)(puVar2 + 6);
      uVar10 = 0;
      uVar14 = *(uint *)(puVar2 + 0xc);
      uVar15 = 0;
      if (*(longlong *)(puVar2 + 0x28) == 0) {
        if (puVar2 + -0x1c == (ushort *)0x0) {
          uVar6 = 0;
        }
        else {
          uVar6 = *(undefined8 *)(puVar2 + -0x1c);
        }
        uVar6 = StorPortGetScatterGatherList(*(undefined8 *)(param_1 + -0x98),uVar6);
        *(undefined8 *)(puVar2 + 0x28) = uVar6;
      }
      uVar5 = AmdSataChunk;
      puVar4 = *(uint **)(puVar2 + 0x28);
      if ((puVar4 != (uint *)0x0) && (uVar14 != 0)) {
        uVar13 = (ulonglong)AmdSataChunk;
        uVar16 = uVar15;
        do {
          if (*puVar4 <= (uint)uVar10) {
            return uVar16;
          }
          uVar12 = puVar4[uVar10 * 6 + 4];
          uVar8 = puVar4[uVar10 * 6 + 6];
          local_res10 = CONCAT44(puVar4[uVar10 * 6 + 5],uVar12);
          if (uVar9 == 0) {
LAB_1c0004dcc:
            uVar11 = uVar14;
            if (uVar8 < uVar14) {
              uVar11 = uVar8;
            }
            uVar14 = uVar14 - uVar11;
            if (((uVar12 & 1) != 0) || ((uVar11 & 1) != 0)) {
              return 0;
            }
            if (uVar5 < uVar11) {
              lVar7 = local_res10;
              uVar15 = uVar16;
              local_res10._0_4_ = uVar12;
              do {
                uVar11 = uVar11 - uVar5;
                uVar16 = (ulonglong)((int)uVar15 + 1);
                *(uint *)(lVar3 + (uVar15 + 8) * 0x10) = (uint)local_res10;
                local_res10 = lVar7 + uVar13;
                *(int *)(lVar3 + 0x84 + uVar15 * 0x10) = (int)((ulonglong)lVar7 >> 0x20);
                *(uint *)(lVar3 + 0x8c + uVar15 * 0x10) = uVar5 - 1;
                lVar7 = local_res10;
                uVar15 = uVar16;
                uVar12 = (uint)local_res10;
              } while (uVar5 < uVar11);
            }
            uVar15 = uVar16;
            if (uVar11 != 0) {
              uVar15 = (ulonglong)((int)uVar16 + 1);
              *(uint *)(lVar3 + (uVar16 + 8) * 0x10) = uVar12;
              *(int *)(lVar3 + 0x84 + uVar16 * 0x10) = (int)((ulonglong)local_res10 >> 0x20);
              *(uint *)(lVar3 + 0x8c + uVar16 * 0x10) = uVar11 - 1;
            }
          }
          else {
            if (uVar9 < uVar8) {
              uVar8 = uVar8 - uVar9;
              local_res10 = local_res10 + (ulonglong)uVar9;
              uVar9 = 0;
              uVar12 = (uint)local_res10;
              goto LAB_1c0004dcc;
            }
            uVar9 = uVar9 - uVar8;
            uVar15 = uVar16;
          }
          uVar10 = (ulonglong)((uint)uVar10 + 1);
          uVar16 = uVar15;
        } while (uVar14 != 0);
      }
      return uVar15;
    }
    goto LAB_1c0004e79;
  }
  uVar6 = *(undefined8 *)(param_1 + 0x1910);
LAB_1c0004e94:
  *(int *)(lVar3 + 0x80) = (int)uVar6;
  *(int *)(lVar3 + 0x84) = (int)((ulonglong)uVar6 >> 0x20);
  *(uint *)(puVar2 + 0xc) = *(uint *)(puVar2 + 0xc) & 0xfffffffe;
  *(uint *)(lVar3 + 0x8c) =
       *(int *)(puVar2 + 0xc) - 1U & 0x3fffff | *(uint *)(lVar3 + 0x8c) & 0x7fc00000;
  return 1;
}



===== ParseIdentificationData @ 1c0004ee4 =====

undefined8 ParseIdentificationData(ushort *param_1,longlong param_2)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  byte bVar4;
  
  bVar4 = 0;
  if ((((char)param_1[0x58] == '\0') || ((param_1[0x35] & 4) == 0)) ||
     (*(char *)(param_2 + 0x332) != '\0')) {
    bVar1 = (byte)param_1[0x3f];
    if ((bVar1 == 0) || (*(char *)(param_2 + 0x332) != '\0')) {
      if (((char)param_1[0x40] == '\0') || ((param_1[0x35] & 2) == 0)) {
        return 0;
      }
      if ((((*(byte *)(param_2 + 0x332) & 1) != 0) && ((*param_1 & 0x8000) == 0)) &&
         ((char)param_1[0x2f] != '\0')) {
        bVar4 = 1;
      }
      bVar1 = (byte)param_1[0x40];
      bVar2 = 3;
      while (bVar1 = bVar1 >> 1, bVar1 != 0) {
        bVar2 = bVar2 + 1;
      }
      *(byte *)(param_2 + 0x32d) = bVar2 | 8;
      if (((param_1[0x53] & 0x400) == 0) || ((param_1[0x56] & 0x400) == 0)) {
        *(byte *)(param_2 + 0x328) = (-(bVar4 != 0) & 0xa4U) + 0x20;
        cVar3 = (-(bVar4 != 0) & 0x95U) + 0x30;
        *(char *)(param_2 + 0x329) = cVar3;
        *(char *)(param_2 + 0x32a) = cVar3;
        *(byte *)(param_2 + 0x32b) = -((param_1[0x53] & 0x1000) != 0) & 0xe7;
        goto LAB_1c00050a7;
      }
      *(byte *)(param_2 + 0x328) = (-(bVar4 != 0) & 5U) + 0x24;
      *(byte *)(param_2 + 0x329) = (-(bVar4 != 0) & 5U) + 0x34;
      bVar4 = (-(bVar4 != 0) & 0x9aU) + 0x34;
      goto LAB_1c0005021;
    }
    while (bVar1 = bVar1 >> 1, bVar1 != 0) {
      bVar4 = bVar4 + 1;
    }
    bVar4 = bVar4 | 0x20;
  }
  else {
    bVar1 = (byte)param_1[0x58];
    while (bVar1 = bVar1 >> 1, bVar1 != 0) {
      bVar4 = bVar4 + 1;
    }
    bVar4 = bVar4 | 0x40;
  }
  *(byte *)(param_2 + 0x32d) = bVar4;
  if (((param_1[0x53] & 0x400) == 0) || ((param_1[0x56] & 0x400) == 0)) {
    *(undefined4 *)(param_2 + 0x328) = 0xe7cacac8;
LAB_1c00050a7:
    *(undefined1 *)(param_2 + 0x32c) = 0x40;
    return 1;
  }
  *(undefined2 *)(param_2 + 0x328) = 0x3525;
  bVar4 = ((byte)param_1[0x54] >> 6 & 1) << 3 | 0x35;
LAB_1c0005021:
  *(byte *)(param_2 + 0x32a) = bVar4;
  if ((param_1[0x53] & 0x2000) == 0) {
    bVar4 = -((param_1[0x53] & 0x1000) != 0) & 0xe7;
  }
  else {
    bVar4 = 0xea;
  }
  *(byte *)(param_2 + 0x32b) = bVar4;
  *(undefined1 *)(param_2 + 0x32c) = 0x42;
  return 1;
}



===== WaitOnCI @ 1c00050b8 =====

int WaitOnCI(longlong param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  do {
    StorPortStallExecution(100);
    iVar1 = *(int *)(*(longlong *)(param_1 + 0x18f0) + 0x38);
    uVar2 = *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x10);
    uVar4 = uVar4 + 1;
    if ((iVar1 == 0) || (4 < uVar4)) break;
  } while ((uVar2 & 0xfffffff0) == 0);
  iVar3 = -(uint)((uVar2 & 0xfffffff0) != 0);
  if (iVar1 == 0) {
    iVar3 = uVar4 * 100;
  }
  return iVar3;
}



===== synchroexec @ 1c000511c =====

int synchroexec(longlong param_1,ulonglong param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  *(undefined4 *)(*(longlong *)(param_1 + 0x18f0) + 0x30) = 0xffffffff;
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)(param_1 + 0x18f0) + 0x10) = 0xffffffff;
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)(param_1 + 0x18f0) + 0x38) = 1;
  LOCK();
  UNLOCK();
  uVar3 = 0;
  do {
    StorPortStallExecution(100);
    iVar1 = *(int *)(*(longlong *)(param_1 + 0x18f0) + 0x38);
    uVar3 = uVar3 + 1;
    if ((iVar1 == 0) || ((uint)((param_2 & 0xffffffff) / 100) <= uVar3)) break;
  } while ((*(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x10) & 0xfffffff0) == 0);
  iVar2 = 0;
  if (iVar1 == 0) {
    iVar2 = uVar3 * 100;
  }
  return iVar2;
}



===== AhciPortIdentify @ 1c00051d0 =====

void AhciPortIdentify(longlong param_1,int param_2,byte param_3)

{
  undefined1 *_Dst;
  uint *puVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  uint uVar4;
  uint *puVar5;
  
  _Dst = *(undefined1 **)(param_1 + 0x1920);
  puVar1 = *(uint **)(param_1 + 0x1918);
  *(undefined2 *)(param_1 + 0x9a8) = 0x13;
  *(undefined4 *)(param_1 + 0x9c0) = 0x200;
  *(undefined8 *)(param_1 + 0x2d8) = 0;
  *(byte *)(param_1 + 0x2d1) = param_3;
  *(undefined2 **)(param_1 + 0x2b0) = (undefined2 *)(param_1 + 0x9a8);
  *(uint **)(param_1 + 0x2b8) = puVar1;
  *(undefined1 **)(param_1 + 0x2c0) = _Dst;
  *(undefined1 *)(param_1 + 0x2d0) = 0;
  memset(_Dst,0,0x80);
  *_Dst = 0x27;
  uVar3 = 0xa1;
  if (param_2 == 0x101) {
    uVar3 = 0xec;
  }
  _Dst[2] = uVar3;
  _Dst[1] = _Dst[1] & 0xf0 | param_3 & 0xf | 0x80;
  *(undefined4 *)(_Dst + 0x80) = *(undefined4 *)(param_1 + 0x1910);
  if (*(int *)(param_1 + 0x18f8) < 0) {
    *(undefined4 *)(_Dst + 0x84) = *(undefined4 *)(param_1 + 0x1914);
  }
  *(uint *)(_Dst + 0x8c) =
       *(uint *)(_Dst + 0x8c) ^ (*(int *)(param_1 + 0x9c0) - 1U ^ *(uint *)(_Dst + 0x8c)) & 0x3fffff
  ;
  uVar4 = 0;
  puVar5 = puVar1;
  do {
    *puVar5 = 0;
    uVar4 = uVar4 + 1;
    puVar5 = puVar5 + 1;
  } while (uVar4 < 8);
  *puVar1 = (param_3 & 0xf) << 0xc | *puVar1 & 0xffff0fe5 | 5;
  *(undefined2 *)((longlong)puVar1 + 2) = 1;
  uVar2 = *(undefined8 *)(param_1 + 0x2c8);
  puVar1[2] = (uint)uVar2;
  puVar1[3] = (uint)((ulonglong)uVar2 >> 0x20);
  synchroexec(param_1,1000000);
  return;
}



===== ReadLogExt30 @ 1c0005328 =====

void ReadLogExt30(longlong param_1)

{
  undefined1 *_Dst;
  uint *puVar1;
  undefined8 uVar2;
  uint uVar3;
  uint *puVar4;
  
  _Dst = *(undefined1 **)(param_1 + 0x1920);
  puVar1 = *(uint **)(param_1 + 0x1918);
  *(undefined2 *)(param_1 + 0x9a8) = 0x11;
  *(undefined4 *)(param_1 + 0x9c0) = 0x200;
  *(undefined8 *)(param_1 + 0x2d8) = 0;
  *(undefined2 **)(param_1 + 0x2b0) = (undefined2 *)(param_1 + 0x9a8);
  *(uint **)(param_1 + 0x2b8) = puVar1;
  *(undefined1 **)(param_1 + 0x2c0) = _Dst;
  *(undefined2 *)(param_1 + 0x2d0) = 0;
  memset(_Dst,0,0x80);
  *_Dst = 0x27;
  _Dst[2] = 0x2f;
  _Dst[1] = _Dst[1] & 0xf0 | 0x80;
  _Dst[0xc] = 1;
  *(undefined2 *)(_Dst + 4) = 0x830;
  *(undefined4 *)(_Dst + 0x80) = *(undefined4 *)(param_1 + 0x1910);
  if (*(int *)(param_1 + 0x18f8) < 0) {
    *(undefined4 *)(_Dst + 0x84) = *(undefined4 *)(param_1 + 0x1914);
  }
  *(uint *)(_Dst + 0x8c) =
       *(uint *)(_Dst + 0x8c) ^ (*(int *)(param_1 + 0x9c0) - 1U ^ *(uint *)(_Dst + 0x8c)) & 0x3fffff
  ;
  uVar3 = 0;
  puVar4 = puVar1;
  do {
    *puVar4 = 0;
    uVar3 = uVar3 + 1;
    puVar4 = puVar4 + 1;
  } while (uVar3 < 8);
  *puVar1 = *puVar1 & 0xffff0fe5 | 5;
  *(undefined2 *)((longlong)puVar1 + 2) = 1;
  uVar2 = *(undefined8 *)(param_1 + 0x2c8);
  puVar1[2] = (uint)uVar2;
  puVar1[3] = (uint)((ulonglong)uVar2 >> 0x20);
  synchroexec(param_1,1000000);
  return;
}



===== ReadLogExt14 @ 1c0005454 =====

void ReadLogExt14(longlong param_1)

{
  undefined1 *_Dst;
  uint *puVar1;
  undefined8 uVar2;
  uint uVar3;
  uint *puVar4;
  
  _Dst = *(undefined1 **)(param_1 + 0x1920);
  puVar1 = *(uint **)(param_1 + 0x1918);
  *(undefined2 *)(param_1 + 0x9a8) = 0x11;
  *(undefined4 *)(param_1 + 0x9c0) = 0x200;
  *(undefined8 *)(param_1 + 0x2d8) = 0;
  *(undefined2 **)(param_1 + 0x2b0) = (undefined2 *)(param_1 + 0x9a8);
  *(uint **)(param_1 + 0x2b8) = puVar1;
  *(undefined1 **)(param_1 + 0x2c0) = _Dst;
  *(undefined2 *)(param_1 + 0x2d0) = 0;
  memset(_Dst,0,0x80);
  *_Dst = 0x27;
  _Dst[2] = 0x2f;
  _Dst[1] = _Dst[1] & 0xf0 | 0x80;
  _Dst[0xc] = 1;
  *(undefined2 *)(_Dst + 4) = 0x14;
  *(undefined4 *)(_Dst + 0x80) = *(undefined4 *)(param_1 + 0x1910);
  if (*(int *)(param_1 + 0x18f8) < 0) {
    *(undefined4 *)(_Dst + 0x84) = *(undefined4 *)(param_1 + 0x1914);
  }
  *(uint *)(_Dst + 0x8c) =
       *(uint *)(_Dst + 0x8c) ^ (*(int *)(param_1 + 0x9c0) - 1U ^ *(uint *)(_Dst + 0x8c)) & 0x3fffff
  ;
  uVar3 = 0;
  puVar4 = puVar1;
  do {
    *puVar4 = 0;
    uVar3 = uVar3 + 1;
    puVar4 = puVar4 + 1;
  } while (uVar3 < 8);
  *puVar1 = *puVar1 & 0xffff0fe5 | 5;
  *(undefined2 *)((longlong)puVar1 + 2) = 1;
  uVar2 = *(undefined8 *)(param_1 + 0x2c8);
  puVar1[2] = (uint)uVar2;
  puVar1[3] = (uint)((ulonglong)uVar2 >> 0x20);
  synchroexec(param_1,1000000);
  return;
}



===== AhciHwDeviceSleep @ 1c0005580 =====

ulonglong AhciHwDeviceSleep(longlong param_1)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong in_RAX;
  ulonglong uVar4;
  uint uVar5;
  
  if (*(char *)(param_1 + 0x24) != '\0') {
    lVar2 = *(longlong *)(param_1 + 0x1a70);
    in_RAX = 0x100;
    if ((((*(ushort *)(lVar2 + 0xb4) & 0x100) != 0) &&
        (in_RAX = CONCAT71(1,*(char *)(lVar2 + 0xb2)), *(char *)(lVar2 + 0xb2) < '\0')) &&
       ((*(ushort *)(lVar2 + 0xb4) & 0x40) != 0)) {
      *(undefined4 *)(lVar2 + 0x490) = 10;
      *(undefined4 *)(lVar2 + 0x48c) = 0x14;
      uVar4 = ReadLogExt30(param_1);
      if ((int)uVar4 != 0) {
        lVar3 = *(longlong *)(param_1 + 0x1a28);
        uVar4 = CONCAT71((int7)(uVar4 >> 8),*(char *)(lVar3 + 0x37));
        if (*(char *)(lVar3 + 0x37) < '\0') {
          bVar1 = *(byte *)(lVar3 + 0x31);
          uVar4 = (ulonglong)bVar1;
          uVar5 = *(byte *)(lVar3 + 0x30) & 0x1f;
          if ((*(byte *)(lVar3 + 0x30) & 0x1f) == 0) {
            uVar5 = *(uint *)(lVar2 + 0x490);
          }
          *(uint *)(lVar2 + 0x490) = uVar5;
          if (bVar1 == 0) {
            uVar4 = (ulonglong)*(uint *)(lVar2 + 0x48c);
          }
          *(int *)(lVar2 + 0x48c) = (int)uVar4;
        }
      }
      return CONCAT71((int7)(uVar4 >> 8),1);
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== AhciPortInitialize @ 1c0005628 =====

ulonglong AhciPortInitialize(longlong param_1,byte param_2)

{
  ushort *puVar1;
  byte bVar2;
  ulonglong uVar3;
  byte bVar4;
  uint uVar5;
  longlong lVar6;
  byte bVar7;
  ulonglong uVar8;
  bool bVar9;
  
  puVar1 = *(ushort **)(param_1 + 0x1a28);
  uVar8 = 0;
  lVar6 = *(longlong *)(param_1 + 0x1a70 + (ulonglong)param_2 * 8);
  bVar2 = ((*(byte *)(param_1 + 0x1a5c + ((longlong)(int)(uint)param_2 >> 3)) >> (param_2 & 7) & 1)
          != 0) * '\x02';
  *(byte *)(lVar6 + 0x332) = bVar2;
  uVar5 = (uint)param_2;
  bVar2 = (*(byte *)(param_1 + 0x1a60 + ((longlong)(int)uVar5 >> 3)) >> (uVar5 & 7) & 1) != 0 |
          bVar2;
  *(byte *)(lVar6 + 0x332) = bVar2;
  if (bVar2 == 0) {
    bVar9 = (*(byte *)(param_1 + 0x1a64 + ((longlong)(int)uVar5 >> 3)) >> (uVar5 & 7) & 1) != 0;
  }
  else {
    bVar9 = true;
  }
  *(bool *)(lVar6 + 0x331) = bVar9;
  *(undefined2 *)(lVar6 + 0x478) = 0;
  *(undefined1 *)(lVar6 + 0x333) = *(undefined1 *)(param_1 + 0x23);
  uVar3 = ParseIdentificationData(puVar1,lVar6);
  if ((int)uVar3 != 0) {
    if (((puVar1[0x53] & 0x400) == 0) || ((puVar1[0x56] & 0x400) == 0)) {
      uVar3 = (ulonglong)(*(int *)(puVar1 + 0x3c) - 1);
    }
    else {
      uVar3 = *(longlong *)(puVar1 + 100) - 1;
    }
    *(ulonglong *)(lVar6 + 0x10) = uVar3;
    bVar2 = *(byte *)(param_1 + 0x19);
    bVar7 = (byte)uVar8;
    if ((((bVar2 == 1) || ((*(uint *)(param_1 + 0x18f8) & 0x40000000) == 0)) ||
        (*(byte *)(param_1 + 0x1c) != bVar7)) || (*(byte *)(lVar6 + 0x331) != bVar7)) {
      *(byte *)(lVar6 + 0x47c) = bVar7;
    }
    else {
      if ((*(byte *)((longlong)puVar1 + 0x99) & 1) == 0) {
        bVar4 = bVar7;
      }
      else {
        bVar4 = ((byte)puVar1[0x4b] & 0x1f) + 1;
      }
      uVar3 = (ulonglong)bVar2;
      if (bVar4 < bVar2) {
        uVar3 = uVar8 & 0xffffffff;
      }
      *(char *)(lVar6 + 0x47c) = (char)uVar3;
    }
    if (*(byte *)(lVar6 + 0x484) == bVar7) {
      uVar5 = *(uint *)(param_1 + 8);
      uVar3 = (ulonglong)
              CONCAT31((int3)(uVar5 >> 8),
                       ((byte)(&AmdSataFua)[(longlong)(int)uVar5 >> 3] >> (uVar5 & 7) & 1) != 0);
    }
    else {
      uVar3 = CONCAT71((int7)(uVar3 >> 8),*(undefined1 *)(lVar6 + 0x483));
    }
    *(int *)(lVar6 + 0x370) = (int)uVar8;
    uVar8 = 1;
    *(char *)(lVar6 + 0x482) = (char)uVar3;
  }
  return CONCAT71((int7)(uVar3 >> 8),(char)uVar8);
}



===== initresetfis @ 1c000578c =====

void initresetfis(longlong param_1,undefined8 param_2,byte param_3,byte param_4)

{
  uint *puVar1;
  undefined1 *_Dst;
  undefined8 uVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar1 = *(uint **)(param_1 + 0x1918);
  _Dst = *(undefined1 **)(param_1 + 0x1920);
  *(undefined2 *)(param_1 + 0x9a8) = 0x12;
  *(undefined8 *)(param_1 + 0x2d8) = 0;
  *(byte *)(param_1 + 0x2d1) = param_3;
  *(undefined2 **)(param_1 + 0x2b0) = (undefined2 *)(param_1 + 0x9a8);
  *(uint **)(param_1 + 0x2b8) = puVar1;
  *(undefined1 **)(param_1 + 0x2c0) = _Dst;
  *(undefined1 *)(param_1 + 0x2d0) = 0;
  memset(_Dst,0,0x80);
  *_Dst = 0x27;
  _Dst[0xf] = _Dst[0xf] ^ (param_4 << 2 ^ _Dst[0xf]) & 4;
  _Dst[1] = _Dst[1] ^ (_Dst[1] ^ param_3) & 0xf;
  uVar3 = 0;
  puVar4 = puVar1;
  do {
    *puVar4 = 0;
    uVar3 = uVar3 + 1;
    puVar4 = puVar4 + 1;
  } while (uVar3 < 8);
  *puVar1 = *puVar1 & 0xffff0ae5 | (param_4 & 1) << 8 | ((param_3 & 0xf) << 2 | param_4 & 1) << 10 |
            5;
  uVar2 = *(undefined8 *)(param_1 + 0x2c8);
  puVar1[2] = (uint)uVar2;
  puVar1[3] = (uint)((ulonglong)uVar2 >> 0x20);
  *(undefined4 *)(*(longlong *)(param_1 + 0x18f0) + 0x30) = 0xffffffff;
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)(param_1 + 0x18f0) + 0x10) = 0xffffffff;
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)(param_1 + 0x18f0) + 0x38) = 1;
  LOCK();
  UNLOCK();
  return;
}



===== AhciSwPortReset @ 1c00058b8 =====

undefined8 AhciSwPortReset(longlong *param_1,undefined8 param_2,int *param_3)

{
  char cVar1;
  longlong lVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  uint uVar7;
  int iVar8;
  
  iVar4 = (int)param_1[0x1f];
  bVar3 = (byte)param_2;
  iVar8 = 0;
  if (iVar4 == 0x100) {
    cVar1 = *(char *)((longlong)param_1 + 0x103);
    *(undefined1 *)((longlong)param_1 + 0x103) = 0;
    uVar6 = 0;
    *(uint *)(param_1 + 0x21) = ((-(uint)(cVar1 != '\0') & 4) + 1) * AmdSataResetFis1 * 1000;
    iVar4 = StartStopDMAs(param_1,0);
    if (iVar4 == 0) {
      return 0;
    }
    if (((char)*(uint *)(param_1[0x31e] + 0x20) < '\0') ||
       ((*(uint *)(param_1[0x31e] + 0x20) & 8) != 0)) {
      if ((*(byte *)((longlong)param_1 + 0x18fb) & 1) == 0) {
        return 0;
      }
      *(uint *)(param_1[0x31e] + 0x18) = *(uint *)(param_1[0x31e] + 0x18) | 8;
      LOCK();
      UNLOCK();
      uVar7 = 0;
      do {
        StorPortStallExecution(10);
        uVar7 = uVar7 + 1;
        if ((*(uint *)(param_1[0x31e] + 0x18) & 8) == 0) break;
      } while (uVar7 < 100000);
      uVar5 = 0;
      if ((*(uint *)(param_1[0x31e] + 0x18) & 8) == 0) {
        uVar5 = uVar7;
      }
      if ((int)uVar5 < 1) {
        return 0;
      }
    }
    *(undefined4 *)(param_1[0x31e] + 0x30) = 0xffffffff;
    LOCK();
    UNLOCK();
    param_2 = CONCAT71((int7)((ulonglong)uVar6 >> 8),1);
    iVar4 = StartStopDMAs(param_1,(uint)param_2);
    if (iVar4 == 0) {
      return 0;
    }
    initresetfis((longlong)param_1,param_2,bVar3,1);
    *(undefined4 *)(param_1 + 0x22) = 0;
    *(undefined4 *)(param_1 + 0x1f) = 0x200;
LAB_1c0005a05:
    iVar4 = WaitOnCI((longlong)param_1);
    if (iVar4 < 1) goto LAB_1c0005a11;
    StorPortStallExecution(1000);
    initresetfis((longlong)param_1,param_2,bVar3,0);
    iVar4 = AmdSataWaitSign;
    *(undefined4 *)(param_1 + 0x22) = 0;
    if (bVar3 == 0xf) {
      iVar4 = AmdSataWaitPmSign;
    }
    *(undefined4 *)(param_1 + 0x1f) = 0x300;
    *(int *)(param_1 + 0x21) = iVar4 * 1000000;
  }
  else {
    if (iVar4 == 0x200) goto LAB_1c0005a05;
    if (iVar4 != 0x300) {
      return 0;
    }
  }
  iVar4 = WaitOnCI((longlong)param_1);
  if (0 < iVar4) {
    lVar2 = param_1[0x344];
    if ((((*(char *)(lVar2 + 0x43) == '\x01') && (bVar3 != 0xf)) ||
        ((*(char *)(lVar2 + 0x43) == '\0' && (bVar3 == 0xf)))) &&
       ((((iVar8 = CONCAT31(*(undefined3 *)(lVar2 + 0x44),*(undefined1 *)(lVar2 + 0x4c)),
          iVar8 != 0x101 && (iVar8 != -0x14ebfeff)) && (iVar8 != -0x6996feff)) &&
        (iVar8 != -0x3cc3feff)))) {
      iVar8 = 0;
    }
    *param_3 = iVar8;
    return 1;
  }
LAB_1c0005a11:
  if ((iVar4 == 0) && ((int)param_1[0x22] + 500U < *(uint *)(param_1 + 0x21))) {
    *(int *)(param_1 + 0x22) = (int)param_1[0x22] + 0x18894;
    return 100000;
  }
  return 0;
}



===== AhciPortMultiplierRead @ 1c0005b08 =====

longlong AhciPortMultiplierRead
                   (longlong param_1,undefined1 param_2,undefined2 param_3,undefined1 *param_4)

{
  undefined1 *_Dst;
  uint *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  int iVar4;
  undefined4 extraout_var;
  uint7 uVar6;
  longlong lVar5;
  uint uVar7;
  uint *puVar8;
  undefined1 uStackX_19;
  
  _Dst = *(undefined1 **)(param_1 + 0x1920);
  puVar1 = *(uint **)(param_1 + 0x1918);
  *(undefined2 *)(param_1 + 0x9a8) = 0x14;
  *(undefined8 *)(param_1 + 0x2d8) = 0;
  *(undefined1 *)(param_1 + 0x2d1) = param_2;
  *(undefined2 **)(param_1 + 0x2b0) = (undefined2 *)(param_1 + 0x9a8);
  *(uint **)(param_1 + 0x2b8) = puVar1;
  *(undefined1 **)(param_1 + 0x2c0) = _Dst;
  *(undefined1 *)(param_1 + 0x2d0) = 0;
  memset(_Dst,0,0x80);
  uStackX_19 = (undefined1)((ushort)param_3 >> 8);
  _Dst[1] = _Dst[1] | 0x8f;
  _Dst[0xb] = uStackX_19;
  uVar7 = 0;
  *_Dst = 0x27;
  _Dst[2] = 0xe4;
  _Dst[7] = param_2;
  _Dst[3] = (char)param_3;
  puVar8 = puVar1;
  do {
    *puVar8 = 0;
    uVar7 = uVar7 + 1;
    puVar8 = puVar8 + 1;
  } while (uVar7 < 8);
  *puVar1 = *puVar1 & 0xffffffe5 | 0xf005;
  uVar2 = *(undefined8 *)(param_1 + 0x2c8);
  puVar1[2] = (uint)uVar2;
  puVar1[3] = (uint)((ulonglong)uVar2 >> 0x20);
  iVar4 = synchroexec(param_1,10000);
  uVar6 = (uint7)(CONCAT44(extraout_var,iVar4) >> 8);
  if ((iVar4 == 0) || (lVar3 = *(longlong *)(param_1 + 0x1a20), *(char *)(lVar3 + 0x43) != '\0')) {
    lVar5 = (ulonglong)uVar6 << 8;
  }
  else {
    lVar5 = CONCAT71(uVar6,1);
    *param_4 = *(undefined1 *)(lVar3 + 0x4c);
    param_4[1] = *(undefined1 *)(lVar3 + 0x44);
    param_4[2] = *(undefined1 *)(lVar3 + 0x45);
    param_4[3] = *(undefined1 *)(lVar3 + 0x46);
  }
  return lVar5;
}



===== AhciPortMultiplierWrite @ 1c0005c20 =====

longlong AhciPortMultiplierWrite
                   (longlong param_1,undefined1 param_2,undefined2 param_3,undefined4 param_4)

{
  undefined1 *_Dst;
  uint *puVar1;
  undefined8 uVar2;
  int iVar3;
  undefined4 extraout_var;
  uint7 uVar5;
  longlong lVar4;
  uint uVar6;
  uint *puVar7;
  undefined1 uStackX_19;
  undefined1 uStackX_21;
  undefined1 uStackX_22;
  undefined1 uStackX_23;
  
  _Dst = *(undefined1 **)(param_1 + 0x1920);
  puVar1 = *(uint **)(param_1 + 0x1918);
  *(undefined2 *)(param_1 + 0x9a8) = 0x15;
  *(undefined8 *)(param_1 + 0x2d8) = 0;
  *(undefined1 *)(param_1 + 0x2d1) = param_2;
  *(undefined2 **)(param_1 + 0x2b0) = (undefined2 *)(param_1 + 0x9a8);
  *(uint **)(param_1 + 0x2b8) = puVar1;
  *(undefined1 **)(param_1 + 0x2c0) = _Dst;
  *(undefined1 *)(param_1 + 0x2d0) = 0;
  memset(_Dst,0,0x80);
  uStackX_19 = (undefined1)((ushort)param_3 >> 8);
  _Dst[1] = _Dst[1] | 0x8f;
  _Dst[0xb] = uStackX_19;
  uVar6 = 0;
  uStackX_21 = (undefined1)((uint)param_4 >> 8);
  _Dst[4] = uStackX_21;
  uStackX_22 = (undefined1)((uint)param_4 >> 0x10);
  _Dst[5] = uStackX_22;
  uStackX_23 = (undefined1)((uint)param_4 >> 0x18);
  _Dst[6] = uStackX_23;
  *_Dst = 0x27;
  _Dst[2] = 0xe8;
  _Dst[7] = param_2;
  _Dst[3] = (char)param_3;
  _Dst[0xc] = (char)param_4;
  puVar7 = puVar1;
  do {
    *puVar7 = 0;
    uVar6 = uVar6 + 1;
    puVar7 = puVar7 + 1;
  } while (uVar6 < 8);
  *puVar1 = *puVar1 & 0xffffffe5 | 0xf005;
  uVar2 = *(undefined8 *)(param_1 + 0x2c8);
  puVar1[2] = (uint)uVar2;
  puVar1[3] = (uint)((ulonglong)uVar2 >> 0x20);
  iVar3 = synchroexec(param_1,10000);
  uVar5 = (uint7)(CONCAT44(extraout_var,iVar3) >> 8);
  if ((iVar3 == 0) || (*(char *)(*(longlong *)(param_1 + 0x1a20) + 0x43) != '\0')) {
    lVar4 = (ulonglong)uVar5 << 8;
  }
  else {
    lVar4 = CONCAT71(uVar5,1);
  }
  return lVar4;
}



===== AhciChannelHotplugTimerCallback @ 1c0005d40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 AhciChannelHotplugTimerCallback(longlong *param_1)

{
  uint *puVar1;
  uint *puVar2;
  undefined2 uVar3;
  uint uVar4;
  int *piVar5;
  _AHCI_CONTROLLER_EXTENSION *p_Var6;
  byte *pbVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  bool bVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint *puVar14;
  ulonglong uVar15;
  longlong lVar16;
  longlong lVar17;
  undefined8 uVar18;
  undefined4 *puVar19;
  byte bVar20;
  uint uVar21;
  byte *pbVar22;
  undefined7 uVar25;
  void *pvVar23;
  void *pvVar24;
  byte bVar26;
  _AHCI_CONTROLLER_EXTENSION _Var27;
  uint uVar28;
  uint *puVar29;
  longlong *plVar30;
  char cVar31;
  longlong *plVar32;
  longlong lVar33;
  undefined1 local_b8 [32];
  undefined4 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined4 *local_80;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  undefined4 local_60;
  byte local_5c [21];
  int local_47;
  char local_43;
  char cStack_42;
  char local_41;
  undefined1 local_40;
  undefined8 local_3f;
  int local_37;
  undefined2 local_33;
  undefined1 local_31;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)local_b8;
  local_78 = 0;
  uVar28 = local_70;
  do {
    uVar9 = 0;
    uVar11 = 0;
    uVar12 = *(uint *)((longlong)param_1 + 0xf4);
    bVar20 = *(byte *)((longlong)param_1 + 0xfd);
    pbVar22 = (byte *)0x850;
    bVar26 = 0;
    if (uVar12 < 0x501) {
      if (uVar12 != 0x500) {
        if (0x113 < uVar12) {
          if (uVar12 == 0x200) {
            iVar13 = (-(uint)(*(char *)((longlong)param_1 + 0x102) != '\0') & 0xffffff00) + 0x400;
LAB_1c00064a5:
            *(int *)((longlong)param_1 + 0xf4) = iVar13;
            goto LAB_1c0006f2e;
          }
          if (uVar12 == 0x300) {
            *(undefined4 *)(param_1 + 0x1f) = 0x100;
            *(undefined4 *)((longlong)param_1 + 0xf4) = 0x301;
          }
          else if (uVar12 != 0x301) {
            if (uVar12 == 0x400) {
              *(undefined4 *)(param_1 + 0x1f) = 0x100;
              *(undefined4 *)((longlong)param_1 + 0xf4) = 0x401;
LAB_1c0006fbf:
              local_78 = 0;
              uVar18 = AhciSwPortReset(param_1,0,(int *)&local_78);
              uVar28 = (uint)uVar18;
              if (((uVar28 == 0) || (local_78 == 0)) &&
                 (uVar12 = *(uint *)((longlong)param_1 + 0x10c),
                 *(uint *)((longlong)param_1 + 0x10c) = uVar12 + 1, uVar12 < 500)) {
                return 100000;
              }
              if (1 < uVar28) {
                return 100000;
              }
              if ((uVar28 == 0) || (local_78 == 0)) {
                *(undefined4 *)((longlong)param_1 + 0xf4) = 0x100;
                return 100000;
              }
              *(undefined4 *)((longlong)param_1 + 0xf4) = 0x500;
              *(undefined1 *)((longlong)param_1 + 0xfd) = 0;
              *(uint *)((longlong)param_1 + 0x11c) = local_78;
              return 100000;
            }
            if (uVar12 == 0x401) goto LAB_1c0006fbf;
            goto LAB_1c0006f2e;
          }
          local_78 = 0;
          pbVar22 = (byte *)0x80f;
          uVar18 = AhciSwPortReset(param_1,0x80f,(int *)&local_78);
          uVar12 = (uint)uVar18;
          if (uVar12 == 0) {
            if ((*(uint *)(param_1[0x31e] + 0x10) >> 0x17 & 1) != 0) {
              *(undefined4 *)(param_1 + 0x1f) = 0x100;
              pbVar22 = (byte *)0x0;
              uVar18 = AhciSwPortReset(param_1,0,(int *)&local_78);
              uVar12 = (uint)uVar18;
              goto LAB_1c0006431;
            }
          }
          else {
LAB_1c0006431:
            if (1 < uVar12) {
              return 100000;
            }
            if (uVar12 != 0) {
              if (local_78 == 0x96690101) {
                *(undefined4 *)((longlong)param_1 + 0xc) = 0x96690101;
                *(undefined4 *)((longlong)param_1 + 0xf4) = 0x800;
                *(undefined1 *)((longlong)param_1 + 0xfd) = 0;
              }
              else {
                *(undefined4 *)((longlong)param_1 + 0xf4) = 0x400;
              }
              goto LAB_1c0006f2e;
            }
          }
          *(char *)((longlong)param_1 + 0x102) =
               *(char *)((longlong)param_1 + 0x102) - (*(char *)((longlong)param_1 + 0x102) != '\0')
          ;
          goto LAB_1c0006286;
        }
        if (uVar12 == 0x113) {
          uVar12 = *(uint *)(param_1[0x31e] + 0x20);
          if ((uVar12 & 1) == 0) {
            uVar11 = *(uint *)(param_1[0x31e] + 0x28);
            if (*(char *)((longlong)param_1 + 0x102) == '\0') {
              uVar21 = uVar11 & 0xf;
              pbVar22 = (byte *)(ulonglong)uVar21;
              if (((char)uVar21 == '\x03') && (((char)uVar12 < '\0' || ((uVar12 & 8) != 0)))) {
                uVar12 = *(uint *)(param_1 + 0x21);
                pbVar22 = (byte *)(ulonglong)uVar12;
                *(uint *)(param_1 + 0x21) = uVar12 + 1;
                if (uVar12 < 3000) {
                  return 100000;
                }
              }
            }
            else {
              g_bIsPMAttached = 1;
            }
            if (((byte)uVar11 & 0xf) == 3) {
              *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) | 2;
              *(undefined4 *)((longlong)param_1 + 0xf4) = 0x200;
            }
            else {
              *(undefined4 *)((longlong)param_1 + 0xf4) = 0x100;
            }
            goto LAB_1c0006f2e;
          }
          goto LAB_1c0006286;
        }
        if (uVar12 == 0) {
          return 0;
        }
        if (uVar12 == 0x10) {
          *(int *)(param_1 + 0x12) = (int)param_1[0x12] + 1;
          StorPortQuerySystemTime(param_1 + (ulonglong)(*(uint *)(param_1 + 0x12) & 7) + 0x13);
          LOCK();
          *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) & 0xf000000f;
          UNLOCK();
          if (*(char *)((longlong)param_1 + 0x104) == '\0') {
            uVar28 = *(uint *)((longlong)param_1 + 0x1a54);
            local_68 = uVar28;
            if (*(int *)((longlong)param_1 + 300) != 0) {
              DeslotChannelSlots((longlong)param_1);
            }
            if (*(int *)((longlong)param_1 + 0x1a34) != 0) {
              *(uint *)((longlong)param_1 + 0x1a4c) = uVar28;
            }
            *(uint *)((longlong)param_1 + 0x1a4c) =
                 *(uint *)((longlong)param_1 + 0x1a4c) & ~*(uint *)(param_1 + 0x349);
            while( true ) {
              uVar12 = *(uint *)((longlong)param_1 + 0x1a4c);
              uVar11 = 0;
              if (uVar12 != 0) {
                for (; (uVar12 >> uVar11 & 1) == 0; uVar11 = uVar11 + 1) {
                }
              }
              uVar15 = (ulonglong)uVar11;
              if (uVar12 == 0) break;
              pbVar22 = (byte *)((longlong)param_1 + ((longlong)(int)uVar11 >> 3) + 0x1a4c);
              *pbVar22 = *pbVar22 & ~('\x01' << (uVar11 & 7));
              iVar13 = *(int *)((longlong)param_1 + (uVar15 & 0xff) * 4 + 0x1f0);
              *(int *)((longlong)param_1 + (uVar15 & 0xff) * 4 + 0x1f0) = iVar13 + 1;
              if (iVar13 == 0) {
                *(undefined4 *)((longlong)param_1 + uVar15 * 4 + 0x268) =
                     *(undefined4 *)((longlong)param_1 + uVar15 * 4 + 0x22c);
              }
            }
            while( true ) {
              uVar12 = *(uint *)(param_1 + 0x349);
              uVar11 = 0;
              if (uVar12 != 0) {
                for (; (uVar12 >> uVar11 & 1) == 0; uVar11 = uVar11 + 1) {
                }
              }
              uVar15 = (ulonglong)uVar11;
              if (uVar12 == 0) break;
              pbVar22 = (byte *)((longlong)param_1 + ((longlong)(int)uVar11 >> 3) + 0x1a48);
              *pbVar22 = *pbVar22 & ~('\x01' << (uVar11 & 7));
              *(undefined1 *)((longlong)param_1 + 0x105) = 1;
              iVar13 = *(int *)((longlong)param_1 + (uVar15 & 0xff) * 4 + 0x1f0);
              *(int *)((longlong)param_1 + (uVar15 & 0xff) * 4 + 0x1f0) = iVar13 + 1;
              if (iVar13 == 0) {
                *(undefined4 *)((longlong)param_1 + uVar15 * 4 + 0x268) =
                     *(undefined4 *)((longlong)param_1 + uVar15 * 4 + 0x22c);
              }
            }
            uVar12 = 0;
            if (uVar28 != 0) {
              for (; (uVar28 >> uVar12 & 1) == 0; uVar12 = uVar12 + 1) {
              }
            }
            local_64 = uVar12;
            if (uVar28 != 0) {
              do {
                local_5c[((longlong)(int)uVar12 >> 3) + -0xc] =
                     local_5c[((longlong)(int)uVar12 >> 3) + -0xc] & ~('\x01' << (uVar12 & 7));
                if (5 < *(uint *)((longlong)param_1 + (ulonglong)(uVar12 & 0xff) * 4 + 0x1f0)) {
                  AhciAbortDeviceQueue((longlong)param_1,(byte)uVar12,5);
                  *(undefined4 *)((longlong)param_1 + (ulonglong)(uVar12 & 0xff) * 4 + 0x1f0) = 0;
                }
                uVar12 = 0;
                if (local_68 != 0) {
                  for (; (local_68 >> uVar12 & 1) == 0; uVar12 = uVar12 + 1) {
                  }
                }
              } while (local_68 != 0);
              local_64 = uVar12;
            }
          }
          else {
            AhciFailIRBs((longlong)param_1,5);
          }
          *(undefined8 *)((longlong)param_1 + 0x1a44) = 0;
          *(undefined8 *)((longlong)param_1 + 0x1a4c) = 0;
          *(undefined4 *)((longlong)param_1 + 0x1ec) = 0;
          *(undefined2 *)(param_1 + 0x346) = 0;
          *(undefined4 *)((longlong)param_1 + 0x1a34) = 0;
          *(undefined4 *)((longlong)param_1 + 0x134) = 0;
          *(undefined1 *)((longlong)param_1 + 0x21) = 0;
          *(undefined1 *)((longlong)param_1 + 0xfc) = 0;
          uVar28 = *(uint *)(param_1[0x31e] + 0x18);
          if (*(char *)((longlong)param_1 + 0x23) == '\0') {
            if ((((*(uint *)(*param_1 + 0x24) & 0x20) != 0) && ((uVar28 >> 0x15 & 1) != 0)) ||
               (uVar8 = uVar9, (uVar28 >> 0x12 & 1) != 0)) {
              uVar8 = 1;
            }
            *(undefined1 *)((longlong)param_1 + 0x23) = uVar8;
          }
          *(uint *)((longlong)param_1 + 0x34) =
               ((uint)(*(char *)((longlong)param_1 + 0x23) != '\0') << 0xb |
               *(uint *)(param_1[0x31e] + 0x18) & 0xffffa000) << 0xb |
               *(uint *)(param_1 + 799) >> 0x15 & 0x80 |
               *(uint *)(param_1[0x31e] + 0x14) & 0x23fff00 | 0x7d00005f;
          if (*(char *)((longlong)param_1 + 0x24) != '\0') {
            *(uint *)(param_1[0x31e] + 0x44) = *(uint *)(param_1[0x31e] + 0x44) & 0xfffffffe;
            LOCK();
            UNLOCK();
          }
          if (*(char *)((longlong)param_1 + 0x1d) == '\0') {
            if (*(char *)((longlong)param_1 + 0x23) != '\0') {
              bVar26 = -((*(uint *)(*param_1 + 0x24) & 0x20000) != 0) & 3;
            }
            *(byte *)((longlong)param_1 + 0x102) = bVar26;
          }
          else {
            *(undefined1 *)((longlong)param_1 + 0x102) = 0;
          }
          if ((*(char *)(*param_1 + 0x5e) == '\0') || (uVar8 = 1, (uVar28 >> 0x16 & 1) == 0)) {
            uVar8 = uVar9;
          }
          *(undefined1 *)(param_1 + 4) = uVar8;
          *(undefined4 *)((longlong)param_1 + 0xf4) = 0x100;
          if (((((byte)(&AmdSataCOMRESET)[(longlong)(int)*(uint *)(param_1 + 1) >> 3] >>
                 (*(uint *)(param_1 + 1) & 7) & 1) != 0) ||
              (*(char *)((longlong)param_1 + 0x105) != '\0')) ||
             (*(char *)((longlong)param_1 + 0x23) != '\0')) {
            uVar9 = 1;
          }
          *(undefined1 *)((longlong)param_1 + 0x105) = uVar9;
          *(undefined4 *)((longlong)param_1 + 0x114) = AmdSataDET1;
          *(undefined4 *)(param_1 + 0x23) = AmdSataDET3;
LAB_1c00060c4:
          *(undefined1 *)((longlong)param_1 + 0x2c) = 1;
          *(undefined1 *)((longlong)param_1 + 0x1f) = 0;
          *(undefined1 *)(param_1 + 0x31b) = 0;
          *(undefined1 *)((longlong)param_1 + 0x1b) = 0;
          *(undefined4 *)(param_1 + 0x34b) = 0;
          *(undefined4 *)(param_1[0x31e] + 0x18) = 0x10000000;
          LOCK();
          UNLOCK();
          if ((char)param_1[4] != '\0') {
            *(undefined4 *)(param_1[0x31e] + 0x40) = 0;
            LOCK();
            UNLOCK();
          }
          uVar28 = (*(byte *)((longlong)param_1 + 0x2f) & 0xf | 0x30) << 4;
          *(uint *)(param_1[0x31e] + 0x2c) = uVar28;
          LOCK();
          UNLOCK();
          *(undefined1 *)(param_1 + 0x20) = 0;
          *(undefined2 *)((longlong)param_1 + 0xfd) = 0;
          local_6c = *(uint *)(*(longlong *)(*param_1 + 8) + 0xc);
          if (AmdSataPI != 0) {
            local_6c = local_6c & AmdSataPI;
          }
          pbVar22 = (byte *)(ulonglong)local_6c;
          uVar12 = (uint)((local_5c[((longlong)(int)*(uint *)(param_1 + 1) >> 3) + -0x10] >>
                           (*(uint *)(param_1 + 1) & 7) & 1) != 0);
          *(uint *)((longlong)param_1 + 0x14) = uVar12;
          if (uVar12 == 0) {
            *(undefined4 *)((longlong)param_1 + 0xf4) = 0x8100;
            return 100000;
          }
          local_70 = uVar28;
          if (*(char *)((longlong)param_1 + 0x105) == '\0') {
            *(undefined4 *)(param_1 + 0x21) = *(undefined4 *)((longlong)param_1 + 0x114);
            *(undefined1 *)((longlong)param_1 + 0x105) = 1;
            *(undefined4 *)((longlong)param_1 + 0xf4) = 0x110;
            goto LAB_1c0006f2e;
          }
          if (((*(char *)((longlong)param_1 + 0xfc) != '\0') && ((*(uint *)(param_1 + 2) & 2) == 0))
             || (bVar20 = *(char *)((longlong)param_1 + 0xfc) + 1,
                *(byte *)((longlong)param_1 + 0xfc) = bVar20, 3 < bVar20)) goto LAB_1c00061c1;
          if ((*(uint *)(param_1 + 799) & 0x8000000) != 0) {
            *(undefined4 *)(param_1[0x31e] + 0x18) = 0x10000002;
            LOCK();
            UNLOCK();
          }
          uVar28 = (*(byte *)((longlong)param_1 + 0x2f) & 0xf) << 4;
          *(uint *)(param_1[0x31e] + 0x2c) = uVar28 | 0x301;
          LOCK();
          UNLOCK();
          StorPortStallExecution(1000);
          uVar28 = uVar28 | 0x300;
          *(uint *)(param_1[0x31e] + 0x2c) = uVar28;
          LOCK();
          UNLOCK();
          param_1[0x21] = 0;
          *(undefined4 *)((longlong)param_1 + 0xf4) = 0x110;
          local_70 = uVar28;
          StorPortStallExecution();
LAB_1c0006254:
          uVar12 = *(uint *)(param_1[0x31e] + 0x28) & 0xf;
          if ((uVar12 == 0) &&
             (uVar11 = *(uint *)(param_1 + 0x21), *(uint *)(param_1 + 0x21) = uVar11 + 1,
             uVar11 < *(uint *)((longlong)param_1 + 0x114))) {
            return 100000;
          }
          if (uVar12 == 0) goto LAB_1c0006286;
          param_1[0x21] = 0;
          *(undefined4 *)((longlong)param_1 + 0xf4) = 0x111;
        }
        else {
          if (uVar12 == 0x100) goto LAB_1c00060c4;
          if (uVar12 == 0x110) goto LAB_1c0006254;
          if (uVar12 != 0x111) {
            if (uVar12 == 0x112) goto LAB_1c0006f51;
            goto LAB_1c0006f2e;
          }
        }
        uVar12 = *(uint *)(param_1[0x31e] + 0x28) & 0xf;
        if (uVar12 != 3) {
          uVar11 = *(uint *)(param_1 + 0x21);
          *(uint *)(param_1 + 0x21) = uVar11 + 1;
          if (uVar11 < *(uint *)(param_1 + 0x23)) {
            return 100000;
          }
          if (uVar12 != 3) {
            if ((*(uint *)(param_1 + 799) & 0x8000000) != 0) {
              *(uint *)(param_1[0x31e] + 0x18) = *(uint *)(param_1[0x31e] + 0x18) & 0xfffffffd;
              LOCK();
              UNLOCK();
            }
            goto LAB_1c0006286;
          }
        }
        *(undefined4 *)((longlong)param_1 + 0xf4) = 0x112;
LAB_1c0006f51:
        *(uint *)(param_1[0x31e] + 0x18) = *(uint *)(param_1[0x31e] + 0x18) | 0x10;
        LOCK();
        UNLOCK();
        *(undefined4 *)(param_1[0x31e] + 0x30) = 0xffffffff;
        LOCK();
        UNLOCK();
        param_1[0x21] = 0;
        *(undefined4 *)((longlong)param_1 + 0xf4) = 0x113;
        return 100000;
      }
      uVar12 = *(uint *)((longlong)param_1 + 0x11c);
      local_78 = uVar12;
      if ((uVar12 == 0x101) || (uVar12 == 0xeb140101)) {
        pbVar22 = (byte *)(ulonglong)uVar12;
        iVar13 = AhciPortIdentify((longlong)param_1,uVar12,bVar20);
        if (iVar13 != 0) {
          puVar14 = (uint *)param_1[(ulonglong)bVar20 + 0x34e];
          if (puVar14 == (uint *)0x0) {
            puVar14 = (uint *)AhciPortAllocatePool((longlong)param_1);
            if (puVar14 == (uint *)0x0) goto LAB_1c0006286;
            pbVar22 = (byte *)0x0;
            memset(puVar14,0,0x498);
            param_1[(ulonglong)bVar20 + 0x34e] = (longlong)puVar14;
          }
          pbVar22 = (byte *)CONCAT71((int7)((ulonglong)pbVar22 >> 8),bVar20);
          uVar15 = AhciPortInitialize((longlong)param_1,bVar20);
          if ((char)uVar15 != '\0') {
            if (*puVar14 == uVar12) {
              pbVar22 = (byte *)param_1[0x345];
              puVar1 = puVar14 + 6;
              iVar13 = 0x18;
              puVar29 = puVar1;
              do {
                uVar11 = *puVar29;
                puVar2 = (uint *)(((longlong)pbVar22 - (longlong)puVar1) + (longlong)puVar29);
                puVar29 = puVar29 + 1;
                if (uVar11 != *puVar2) break;
                iVar13 = iVar13 + -1;
              } while (iVar13 != 0);
              if (iVar13 != 0) goto LAB_1c00065a2;
              memcpy(puVar1,pbVar22,0x200);
              pbVar22 = (byte *)0x0;
              AhciHwPresetFeatures((longlong)param_1,0);
              puVar14[0x86] = puVar14[0x86] & 0xfffffffe;
              *(char *)((longlong)param_1 + 0xfe) = *(char *)((longlong)param_1 + 0xfe) + '\x01';
LAB_1c0006782:
              *(undefined4 *)((longlong)param_1 + 0xf4) = 0x8000;
              goto LAB_1c0006f2e;
            }
LAB_1c00065a2:
            pvVar23 = (void *)param_1[0x345];
            if ((*(byte *)((longlong)pvVar23 + 0x100) & 4) == 0) {
              if (*puVar14 != 0) {
                AhciAbortDeviceQueue((longlong)param_1,bVar20,6);
                *puVar14 = 0;
                *(char *)(param_1 + 0x20) = (char)param_1[0x20] + '\x01';
              }
              *(uint *)((longlong)param_1 + 0xc) = uVar12;
              bVar10 = AmdSataAcpiIde == 0;
              *(bool *)((longlong)param_1 + 0x2d) = uVar12 == 0xeb140101;
              *puVar14 = uVar12;
              uVar11 = *(uint *)(param_1 + 1);
              if (bVar10) {
                uVar11 = uVar11 << 0x10 | 0xffff;
              }
              puVar14[1] = uVar11;
              memcpy(puVar14 + 6,pvVar23,0x200);
              if (((*(ushort *)((longlong)pvVar23 + 0xa6) & 0x400) == 0) ||
                 (uVar9 = 1, (*(ushort *)((longlong)pvVar23 + 0xac) & 0x400) == 0)) {
                uVar9 = 0;
              }
              *(undefined1 *)((longlong)puVar14 + 0x47b) = uVar9;
              *(byte *)((longlong)puVar14 + 0x47e) = *(byte *)((longlong)pvVar23 + 0xa4) >> 5 & 1;
              *(byte *)((longlong)puVar14 + 0x47f) = *(byte *)((longlong)pvVar23 + 0xaa) >> 5 & 1;
              *(byte *)(puVar14 + 0x120) = *(byte *)((longlong)pvVar23 + 0xa8) >> 6 & 1;
              *(byte *)(puVar14 + 0x125) =
                   (byte)((ushort)*(undefined2 *)((longlong)pvVar23 + 0x9c) >> 9) & 1;
              uVar3 = *(undefined2 *)((longlong)pvVar23 + 0x9e);
              *(undefined1 *)((longlong)puVar14 + 0x32e) = 0;
              *(byte *)((longlong)puVar14 + 0x495) = (byte)((ushort)uVar3 >> 9) & 1;
              pbVar22 = (byte *)((longlong)param_1 + ((longlong)(int)(uint)bVar20 >> 3) + 0x1a54);
              *pbVar22 = *pbVar22 | '\x01' << (bVar20 & 7);
              puVar14[0x86] = 0;
              puVar14[0x87] = 0;
              puVar14[0x88] = 0;
              puVar14[0x89] = 0;
              *(undefined4 *)((longlong)param_1 + (ulonglong)bVar20 * 4 + 0x1f0) = 0;
              *(undefined4 *)((longlong)param_1 + (ulonglong)bVar20 * 4 + 0x268) = 0;
              uVar18 = AhciHwDeviceSleep((longlong)param_1);
              *(char *)(puVar14 + 0x122) = (char)uVar18;
              lVar33 = param_1[0x34e];
              if ((*(char *)(lVar33 + 0x494) != '\0') && (*(char *)(lVar33 + 0x495) != '\0')) {
                *(undefined1 *)(lVar33 + 0x496) = 1;
                iVar13 = ReadLogExt14((longlong)param_1);
                if ((iVar13 != 0) && (bVar20 = *(byte *)(param_1[0x345] + 7) & 0xf, bVar20 != 0)) {
                  *(byte *)(lVar33 + 0x496) = bVar20;
                }
              }
              pbVar22 = (byte *)0x0;
              AhciHwPresetFeatures((longlong)param_1,0);
              *(char *)((longlong)param_1 + 0xfe) = *(char *)((longlong)param_1 + 0xfe) + '\x01';
              *(char *)(param_1 + 0x20) = (char)param_1[0x20] + '\x01';
              if ((dlad != 0) && (uVar12 == 0xeb140101)) {
                *(uint *)(param_1[0x31e] + 0x18) =
                     *(uint *)(param_1[0x31e] + 0x18) & 0xfdffffff | 0x1000000;
                LOCK();
                UNLOCK();
              }
              goto LAB_1c0006782;
            }
LAB_1c00061c1:
            *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) & 0xfffffffd;
LAB_1c00061c6:
            *(undefined4 *)((longlong)param_1 + 0xf4) = 0x8100;
            goto LAB_1c0006f2e;
          }
        }
      }
      goto LAB_1c0006286;
    }
    if (uVar12 < 0x851) {
      if (uVar12 == 0x850) {
        pbVar22 = (byte *)CONCAT71(8,bVar20);
        AhciPortMultiplierWrite((longlong)param_1,bVar20,1,0xffffffff);
        *(undefined4 *)(param_1 + 0x1f) = 0x100;
        *(undefined4 *)((longlong)param_1 + 0xf4) = 0x851;
        goto LAB_1c0006b0a;
      }
      if (uVar12 == 0x800) {
        *(uint *)(param_1[0x31e] + 0x18) = *(uint *)(param_1[0x31e] + 0x18) | 0x20000;
        LOCK();
        UNLOCK();
        pbVar22 = (byte *)0x80f;
        lVar33 = AhciPortMultiplierRead((longlong)param_1,0xf,2,local_5c + 4);
        if ((char)lVar33 != '\0') {
          bVar26 = local_5c[4];
          if ((bVar26 & 0xf) < 2) goto LAB_1c00061c6;
          pbVar22 = (byte *)CONCAT71((int7)((ulonglong)pbVar22 >> 8),0xf);
          lVar33 = AhciPortMultiplierRead((longlong)param_1,0xf,0x40,(undefined1 *)(param_1 + 0x24))
          ;
          if ((char)lVar33 != '\0') {
            bVar26 = bVar26 & 0xf;
            *(byte *)((longlong)param_1 + 0xff) = bVar26;
            if (0xe < bVar26) {
              bVar26 = 0xf;
            }
            *(byte *)((longlong)param_1 + 0x2c) = bVar26;
            *(undefined1 *)((longlong)param_1 + 0x2d) = 0;
            if (((*(uint *)(param_1 + 799) & 0x20000000) != 0) &&
               ((*(byte *)(param_1 + 0x24) & 8) != 0)) {
              uVar25 = (undefined7)((ulonglong)pbVar22 >> 8);
              AhciPortMultiplierWrite((longlong)param_1,0xf,0x21,0x400ffff);
              pbVar22 = (byte *)CONCAT71(uVar25,0xf);
              AhciPortMultiplierWrite((longlong)param_1,0xf,0x60,8);
              *(undefined1 *)((longlong)param_1 + 0x2d) = 1;
            }
            *(undefined4 *)((longlong)param_1 + 0xf4) = 0x801;
            goto LAB_1c0006a15;
          }
        }
        goto LAB_1c0006286;
      }
      if (uVar12 == 0x801) {
LAB_1c0006a15:
        *(undefined1 *)((longlong)param_1 + 0x101) = 0;
        *(undefined4 *)((longlong)param_1 + 0xf4) = 0x810;
LAB_1c0006a27:
        uVar25 = (undefined7)((ulonglong)pbVar22 >> 8);
        lVar33 = AhciPortMultiplierWrite((longlong)param_1,bVar20,1,0xffffffff);
        uVar12 = (*(uint *)((longlong)param_1 + 0x1a6c) >> (bVar20 * '\x02' & 0x1f) & 3) << 4;
        lVar16 = AhciPortMultiplierWrite((longlong)param_1,bVar20,2,uVar12 | 0x301);
        StorPortStallExecution(1000);
        pbVar22 = (byte *)CONCAT71(uVar25,bVar20);
        lVar17 = AhciPortMultiplierWrite((longlong)param_1,bVar20,2,uVar12);
        if ((byte)((byte)lVar33 & (byte)lVar16 & (byte)lVar17) != 0) {
          *(undefined4 *)((longlong)param_1 + 0xf4) = 0x803;
          return 100000;
        }
        goto LAB_1c0006286;
      }
      if (uVar12 == 0x803) {
        pbVar22 = (byte *)0x80f;
        lVar33 = AhciPortMultiplierRead((longlong)param_1,0xf,0x20,local_5c);
        if ((char)lVar33 == '\0') goto LAB_1c0006286;
        if ((local_5c[(longlong)(int)(uint)bVar20 >> 3] >> (bVar20 & 7) & 1) != 0) {
          param_1[0x21] = 0;
          *(undefined4 *)((longlong)param_1 + 0xf4) = 0x811;
          goto LAB_1c0006851;
        }
        *(undefined4 *)((longlong)param_1 + 0xf4) = 0x8e0;
      }
      else {
        if (uVar12 == 0x810) goto LAB_1c0006a27;
        if (uVar12 != 0x811) {
          if (uVar12 == 0x820) {
            if (((*(uint *)(param_1[0x31e] + 0x10) >> 0x17 & 1) == 0) &&
               (uVar12 = *(uint *)(param_1 + 0x21), *(uint *)(param_1 + 0x21) = uVar12 + 1,
               uVar12 < 300)) {
              return 100000;
            }
            *(undefined4 *)((longlong)param_1 + 0xf4) = 0x850;
          }
          goto LAB_1c0006f2e;
        }
LAB_1c0006851:
        local_74 = 0;
        pbVar22 = (byte *)CONCAT71((int7)((ulonglong)pbVar22 >> 8),bVar20);
        uVar15 = AhciPortMultiplierRead((longlong)param_1,bVar20,0,(undefined1 *)&local_74);
        if ((uVar15 & 0xff) == 0) goto LAB_1c0006286;
        uVar12 = local_74 & 0xf;
        pbVar22 = (byte *)(ulonglong)uVar12;
        if (uVar12 == 3) {
LAB_1c00068a0:
          if ((local_74 & 0xf0) != 0) {
            *(undefined4 *)((longlong)param_1 + 0xf4) = 0x820;
            pbVar22 = (byte *)(ulonglong)bVar20;
            lVar33 = AhciPortMultiplierWrite((longlong)param_1,bVar20,1,0xffffffff);
            iVar13 = (-(uint)((char)lVar33 != '\0') & 0x720) + 0x100;
            goto LAB_1c00064a5;
          }
        }
        else {
          uVar11 = *(uint *)(param_1 + 0x21);
          *(uint *)(param_1 + 0x21) = uVar11 + 1;
          if (uVar11 < *(uint *)(param_1 + 0x23)) {
            return 100000;
          }
          if (uVar12 == 3) goto LAB_1c00068a0;
        }
        if ((uVar12 != 1) ||
           (bVar26 = *(byte *)((longlong)param_1 + 0x101),
           *(byte *)((longlong)param_1 + 0x101) = bVar26 + 1, 2 < bVar26)) goto LAB_1c0006ca8;
        pbVar22 = (byte *)(ulonglong)bVar20;
        AhciPortMultiplierWrite((longlong)param_1,bVar20,1,0xffffffff);
        param_1[0x21] = 0;
        *(undefined4 *)((longlong)param_1 + 0xf4) = 0x811;
      }
    }
    else {
      if (uVar12 == 0x851) {
LAB_1c0006b0a:
        local_78 = 0;
        pbVar22 = (byte *)CONCAT71((int7)((ulonglong)pbVar22 >> 8),bVar20);
        uVar18 = AhciSwPortReset(param_1,pbVar22,(int *)&local_78);
        uVar12 = local_78;
        uVar11 = (uint)uVar18;
        if (1 < uVar11) {
          return 100000;
        }
        *(undefined4 *)((longlong)param_1 + 0xf4) = 0x870;
        if (uVar11 == 0) {
LAB_1c0006e31:
          piVar5 = (int *)param_1[(ulonglong)bVar20 + 0x34e];
          if (piVar5 != (int *)0x0) {
            pbVar22 = (byte *)((longlong)param_1 + ((longlong)(int)(uint)bVar20 >> 3) + 0x1a58);
            *pbVar22 = *pbVar22 & ~('\x01' << (bVar20 & 7));
            pbVar22 = (byte *)((longlong)param_1 + ((longlong)(int)(uint)bVar20 >> 3) + 0x1a54);
            *pbVar22 = *pbVar22 & ~('\x01' << (bVar20 & 7));
            if (*piVar5 != 0) {
              AhciAbortDeviceQueue((longlong)param_1,bVar20,6);
              *piVar5 = 0;
              *(char *)(param_1 + 0x20) = (char)param_1[0x20] + '\x01';
            }
            pbVar22 = (byte *)param_1[-0x13];
            if (((*(uint *)(pbVar22 + 0x18) >> 2 & 1) != 0) ||
               (iVar13 = StorPortExtendedFunction(1), iVar13 == 0)) {
              param_1[(ulonglong)bVar20 + 0x34e] = 0;
            }
          }
        }
        else {
          if (local_78 != 0) {
            pbVar22 = (byte *)(ulonglong)local_78;
            iVar13 = AhciPortIdentify((longlong)param_1,local_78,bVar20);
            uVar11 = (uint)(iVar13 != 0);
            if (iVar13 == 0) goto LAB_1c0006e31;
            pbVar22 = (byte *)CONCAT71((int7)((ulonglong)pbVar22 >> 8),bVar20);
            lVar33 = AhciPortMultiplierWrite((longlong)param_1,bVar20,1,0xffffffff);
            uVar11 = (uint)lVar33 & 0xff;
          }
          if ((uVar11 == 0) || (uVar12 == 0)) goto LAB_1c0006e31;
          puVar14 = (uint *)param_1[(ulonglong)bVar20 + 0x34e];
          if (puVar14 == (uint *)0x0) {
            puVar14 = (uint *)AhciPortAllocatePool((longlong)param_1);
            if (puVar14 != (uint *)0x0) {
              pbVar22 = (byte *)0x0;
              memset(puVar14,0,0x498);
              param_1[(ulonglong)bVar20 + 0x34e] = (longlong)puVar14;
              goto LAB_1c0006bc8;
            }
          }
          else {
LAB_1c0006bc8:
            pbVar22 = (byte *)CONCAT71((int7)((ulonglong)pbVar22 >> 8),bVar20);
            uVar15 = AhciPortInitialize((longlong)param_1,bVar20);
            if ((char)uVar15 != '\0') {
              uVar21 = *puVar14;
              pbVar22 = (byte *)(ulonglong)uVar21;
              if (uVar21 == uVar12) {
                pvVar23 = (void *)param_1[0x345];
                puVar1 = puVar14 + 6;
                iVar13 = 0x18;
                puVar29 = puVar1;
                do {
                  uVar4 = *puVar29;
                  puVar2 = (uint *)(((longlong)pvVar23 - (longlong)puVar1) + (longlong)puVar29);
                  puVar29 = puVar29 + 1;
                  if (uVar4 != *puVar2) break;
                  iVar13 = iVar13 + -1;
                } while (iVar13 != 0);
                if (iVar13 == 0) {
                  memcpy(puVar1,pvVar23,0x200);
                  pbVar22 = (byte *)CONCAT71((int7)((ulonglong)pvVar23 >> 8),bVar20);
                  AhciHwPresetFeatures((longlong)param_1,bVar20);
                  puVar14[0x86] = puVar14[0x86] & 0xfffffffe;
                  *(char *)((longlong)param_1 + 0xfe) = *(char *)((longlong)param_1 + 0xfe) + '\x01'
                  ;
                  goto LAB_1c0006ea0;
                }
              }
              pvVar23 = (void *)param_1[0x345];
              if ((*(byte *)((longlong)pvVar23 + 0x100) & 4) != 0) goto LAB_1c00061c1;
              if (uVar21 != 0) {
                AhciAbortDeviceQueue((longlong)param_1,bVar20,6);
                *puVar14 = 0;
                *(char *)(param_1 + 0x20) = (char)param_1[0x20] + '\x01';
              }
              bVar10 = AmdSataAcpiIde == 0;
              *puVar14 = uVar12;
              if (bVar10) {
                uVar12 = (int)param_1[1] << 0x10 | (uint)bVar20;
              }
              else {
                uVar12 = 0xffffffff;
              }
              puVar14[1] = uVar12;
              pvVar24 = pvVar23;
              memcpy(puVar14 + 6,pvVar23,0x200);
              if (((*(ushort *)((longlong)pvVar23 + 0xa6) & 0x400) == 0) ||
                 ((*(ushort *)((longlong)pvVar23 + 0xac) & 0x400) == 0)) {
                uVar9 = 0;
              }
              else {
                uVar9 = 1;
              }
              *(undefined1 *)((longlong)puVar14 + 0x47b) = uVar9;
              pbVar22 = (byte *)CONCAT71((int7)((ulonglong)pvVar24 >> 8),bVar20);
              *(byte *)((longlong)puVar14 + 0x47e) = *(byte *)((longlong)pvVar23 + 0xa4) >> 5 & 1;
              *(byte *)((longlong)puVar14 + 0x47f) = *(byte *)((longlong)pvVar23 + 0xaa) >> 5 & 1;
              bVar26 = *(byte *)((longlong)pvVar23 + 0xa8);
              *(undefined1 *)((longlong)puVar14 + 0x32e) = 0;
              *(byte *)(puVar14 + 0x120) = bVar26 >> 6 & 1;
              pbVar7 = (byte *)((longlong)param_1 + ((longlong)(int)(uint)bVar20 >> 3) + 0x1a54);
              *pbVar7 = *pbVar7 | '\x01' << (bVar20 & 7);
              puVar14[0x86] = 0;
              puVar14[0x87] = 0;
              puVar14[0x88] = 0;
              puVar14[0x89] = 0;
              *(undefined4 *)((longlong)param_1 + (ulonglong)bVar20 * 4 + 0x1f0) = 0;
              *(undefined4 *)((longlong)param_1 + (ulonglong)bVar20 * 4 + 0x268) = 0;
              AhciHwPresetFeatures((longlong)param_1,bVar20);
              *(char *)((longlong)param_1 + 0xfe) = *(char *)((longlong)param_1 + 0xfe) + '\x01';
              *(char *)(param_1 + 0x20) = (char)param_1[0x20] + '\x01';
            }
          }
        }
LAB_1c0006ea0:
        if (uVar11 == 0) {
          pbVar22 = (byte *)0x0;
          iVar13 = StartStopDMAs(param_1,0);
          if (iVar13 != 0) {
            *(undefined4 *)(param_1[0x31e] + 0x30) = 0xffffffff;
            LOCK();
            UNLOCK();
            pbVar22 = (byte *)CONCAT71((int7)((ulonglong)pbVar22 >> 8),1);
            iVar13 = StartStopDMAs(param_1,(uint)pbVar22);
            if (iVar13 != 0) goto LAB_1c0006edb;
          }
LAB_1c0006286:
          *(undefined4 *)((longlong)param_1 + 0xf4) = 0x100;
          goto LAB_1c0006f2e;
        }
LAB_1c0006edb:
        *(undefined4 *)((longlong)param_1 + 0xf4) = 0x8f0;
      }
      else {
        if (uVar12 == 0x870) goto LAB_1c0006e31;
        if (uVar12 == 0x8e0) {
LAB_1c0006ca8:
          piVar5 = (int *)param_1[(ulonglong)bVar20 + 0x34e];
          if (piVar5 != (int *)0x0) {
            pbVar22 = (byte *)((longlong)param_1 + ((longlong)(int)(uint)bVar20 >> 3) + 0x1a58);
            *pbVar22 = *pbVar22 & ~('\x01' << (bVar20 & 7));
            pbVar22 = (byte *)((longlong)param_1 + ((longlong)(int)(uint)bVar20 >> 3) + 0x1a54);
            *pbVar22 = *pbVar22 & ~('\x01' << (bVar20 & 7));
            if (*piVar5 != 0) {
              AhciAbortDeviceQueue((longlong)param_1,bVar20,6);
              *piVar5 = 0;
              *(char *)(param_1 + 0x20) = (char)param_1[0x20] + '\x01';
            }
            pbVar22 = (byte *)param_1[-0x13];
            if (((*(uint *)(pbVar22 + 0x18) >> 2 & 1) != 0) ||
               (iVar13 = StorPortExtendedFunction(), iVar13 == 0)) {
              param_1[(ulonglong)bVar20 + 0x34e] = 0;
            }
          }
          *(undefined4 *)((longlong)param_1 + 0xf4) = 0x8f0;
          goto LAB_1c0006f2e;
        }
        if (uVar12 != 0x8f0) {
          if (uVar12 == 0xa000) {
            plVar32 = param_1 + 0x21;
            *(int *)plVar32 = (int)*plVar32 + -1;
            if ((int)*plVar32 == 0) {
              *(undefined4 *)((longlong)param_1 + 0xf4) = 0;
              LOCK();
              *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) | 0x100000;
              UNLOCK();
              AhciPortRequestWorkerRoutine((longlong)param_1,0x850);
              return 0;
            }
            return 100000;
          }
          goto LAB_1c0006f2e;
        }
      }
      bVar26 = *(byte *)((longlong)param_1 + 0xff);
      if (0xe < bVar26) {
        bVar26 = 0xf;
      }
      if ((byte)(bVar20 + 1) < bVar26) {
        *(byte *)((longlong)param_1 + 0xfd) = bVar20 + 1;
        *(undefined4 *)((longlong)param_1 + 0xf4) = 0x801;
      }
      else {
        *(undefined4 *)((longlong)param_1 + 0xf4) = 0x8000;
      }
    }
LAB_1c0006f2e:
    if ((*(uint *)((longlong)param_1 + 0xf4) & 0x8000) != 0) {
      if (*(int *)((longlong)param_1 + 0xf4) == 0x8100) {
        cVar31 = '\0';
        plVar32 = param_1 + 0x34e;
        uVar28 = 0;
        plVar30 = param_1 + 0x3e;
        do {
          piVar5 = (int *)*plVar32;
          bVar20 = (byte)uVar28;
          if (piVar5 != (int *)0x0) {
            if ((*(char *)((longlong)piVar5 + 0x497) == '\0') ||
               (*(int *)((longlong)param_1 + 0x14) != 1)) {
              if (*piVar5 != 0) {
                AhciAbortDeviceQueue((longlong)param_1,bVar20,6);
                *piVar5 = 0;
              }
              pbVar22 = (byte *)((longlong)param_1 + ((longlong)(int)uVar28 >> 3) + 0x1a54);
              *pbVar22 = *pbVar22 & ~('\x01' << (uVar28 & 7));
              pbVar22 = (byte *)param_1[-0x13];
              if (((*(uint *)(pbVar22 + 0x18) >> 2 & 1) != 0) ||
                 (iVar13 = StorPortExtendedFunction(1,pbVar22,piVar5), iVar13 == 0)) {
                *plVar32 = 0;
              }
              cVar31 = cVar31 + '\x01';
            }
            else if (*piVar5 != 0) {
              *(undefined4 *)plVar30 = 0;
              pbVar22 = (byte *)CONCAT71((int7)((ulonglong)pbVar22 >> 8),bVar20);
              AhciAbortDeviceQueue((longlong)param_1,bVar20,5);
            }
          }
          uVar28 = (uint)(byte)(bVar20 + 1);
          plVar30 = (longlong *)((longlong)plVar30 + 4);
          plVar32 = plVar32 + 1;
        } while ((byte)(bVar20 + 1) < 0xf);
        if (*(int *)((longlong)param_1 + 0x1a54) == 0) {
          *(undefined4 *)((longlong)param_1 + 0xc) = 0;
        }
        uVar28 = local_70;
        if (cVar31 != '\0') {
          *(char *)(param_1 + 0x20) = (char)param_1[0x20] + '\x01';
        }
      }
      lVar33 = 0xf;
      if (*(int *)((longlong)param_1 + 0x14) != 0) {
        *(undefined4 *)(param_1[0x31e] + 0x3c) = 0xffffffff;
        LOCK();
        UNLOCK();
        if ((*(int *)((longlong)param_1 + 0xc) == -0x6996feff) && ((char)param_1[4] != '\0')) {
          *(undefined1 *)((longlong)param_1 + 0x1f) = *(undefined1 *)((longlong)param_1 + 0x1e);
        }
        AhciChannelIpm((longlong)param_1,*(byte *)((longlong)param_1 + 0x32));
        StartStopDMAs(param_1,0);
        *(undefined4 *)((longlong)param_1 + 300) = 0;
        puVar19 = (undefined4 *)((longlong)param_1 + 0x174);
        *(undefined4 *)(param_1 + 0x31a) = 0;
        *(undefined4 *)((longlong)param_1 + 0x18cc) = 0;
        *(undefined4 *)(param_1 + 0x319) = 0;
        *(undefined4 *)(param_1 + 0x25) = 0;
        *(undefined4 *)((longlong)param_1 + 0x124) = 0;
        *(undefined1 *)(param_1 + 3) = 0;
        do {
          puVar19[0xf] = 0;
          *puVar19 = 0;
          puVar19[-0xf] = 0;
          puVar19 = puVar19 + 1;
          lVar33 = lVar33 + -1;
        } while (lVar33 != 0);
        iVar13 = *(int *)((longlong)param_1 + 0xc);
        if ((iVar13 != 0) && ((char)param_1[799] < '\0')) {
          lVar33 = *param_1;
          uVar12 = *(uint *)(param_1 + 1);
          if ((((*(byte *)(lVar33 + 0x34 + ((longlong)(int)uVar12 >> 3)) >> (uVar12 & 7) & 1) != 0)
              && (((*(byte *)(lVar33 + 0x3c + ((longlong)(int)uVar12 >> 3)) >> (uVar12 & 7) & 1) !=
                   0 || (iVar13 != -0x14ebfeff)))) &&
             (((*(byte *)(lVar33 + 0x40 + ((longlong)(int)uVar12 >> 3)) >> (uVar12 & 7) & 1) != 0 ||
              (iVar13 != -0x6996feff)))) {
            *(uint *)((longlong)param_1 + 0x34) = *(uint *)((longlong)param_1 + 0x34) & 0xfffffff0;
            *(undefined1 *)((longlong)param_1 + 0x21) = 1;
          }
        }
        pbVar22 = (byte *)CONCAT71((uint7)(uint3)((uint)iVar13 >> 8),1);
        StartStopDMAs(param_1,(uint)pbVar22);
        *(undefined4 *)(param_1[0x31e] + 0x30) = 0xffffffff;
        LOCK();
        UNLOCK();
        *(undefined4 *)(param_1[0x31e] + 0x10) = 0xffffffff;
        LOCK();
        UNLOCK();
        *(undefined4 *)(param_1[0x31e] + 0x14) = *(undefined4 *)((longlong)param_1 + 0x34);
        LOCK();
        UNLOCK();
      }
      pbVar7 = &Boot + ((longlong)(int)*(uint *)(param_1 + 1) >> 3);
      uVar12 = *(uint *)(param_1 + 1) & 7;
      bVar20 = *pbVar7;
      *pbVar7 = *pbVar7 & ~('\x01' << uVar12);
      if (((bVar20 >> uVar12 & 1) == 0) && ((char)param_1[0x20] != '\0')) {
        pbVar22 = (byte *)param_1[-0x13];
        local_80 = &local_60;
        local_88 = 0;
        local_90 = 0;
        local_98 = 0;
        local_60 = 0xc1000002;
        StorPortNotification(0x1005,pbVar22,4,param_1 + -0x11);
      }
      StorPortQuerySystemTime(param_1 + 0x1b);
      *(undefined4 *)((longlong)param_1 + 0x114) = 0;
      *(undefined4 *)(param_1 + 0x23) = 0;
      p_Var6 = (_AHCI_CONTROLLER_EXTENSION *)*param_1;
      lVar33 = param_1[1];
      *(undefined1 *)((longlong)param_1 + 0x103) = 0;
      *(undefined1 *)((longlong)param_1 + 0x105) = 0;
      if ((*(uint *)(p_Var6 + 0x24) & 0x40) != 0) {
        uVar12 = 1 << ((byte)lVar33 & 0x1f);
        if (*(int *)((longlong)param_1 + 0xc) == 0) {
          *(uint *)(p_Var6 + 0x58) = *(uint *)(p_Var6 + 0x58) & ~uVar12;
        }
        else {
          *(uint *)(p_Var6 + 0x58) = *(uint *)(p_Var6 + 0x58) | uVar12;
        }
        _Var27 = (_AHCI_CONTROLLER_EXTENSION)((byte)lVar33 >> 2);
        if (p_Var6[0x5c] != _Var27) {
          p_Var6[0x5c] = _Var27;
          local_33 = 0;
          local_31 = 0;
          local_40 = 0;
          local_3f = 0x100c0824003000c;
          local_37 = (uint)((byte)_Var27 & 1 | 0x20) << 0x18;
          memcpy(*(void **)(p_Var6 + 0x50),&local_40,0x10);
          lVar33 = *(longlong *)(p_Var6 + 8);
          for (iVar13 = 10;
              (uVar12 = *(uint *)(lVar33 + 0x20), (uVar12 & 0x100) != 0 && (iVar13 != 0));
              iVar13 = iVar13 + -1) {
            StorPortStallExecution(100);
          }
          *(uint *)(lVar33 + 0x20) = uVar12 | 0x100;
          LOCK();
          UNLOCK();
          if (((byte)(1 << ((byte)_Var27 & 0x1f)) & (byte)p_Var6[0x5d]) == 0) {
            SgpioEnableInitiator(p_Var6);
            p_Var6[0x5d] = (_AHCI_CONTROLLER_EXTENSION)
                           ((byte)p_Var6[0x5d] | (byte)(1 << ((byte)_Var27 & 0x1f)));
          }
        }
        uVar12 = *(uint *)(p_Var6 + 0x58) >> (((byte)p_Var6[0x5c] & 7) << 2);
        local_5c[0xc] = 0;
        local_5c[0xd] = 0xc;
        local_5c[0xe] = 0;
        local_5c[0xf] = 3;
        local_5c[0x10] = 0x40;
        local_5c[0x11] = 0x82;
        local_5c[0x12] = 3;
        local_5c[0x13] = 0;
        local_5c[0x14] = 1;
        local_47 = (uint)(byte)((-((uVar12 & 8) != 0) & 5U) * ' ') << 0x18;
        _local_43 = CONCAT11((-((uVar12 & 2) != 0) & 5U) << 5,(-((uVar12 & 4) != 0) & 5U) * ' ');
        pbVar22 = local_5c + 0xc;
        local_41 = (-((uVar12 & 1) != 0) & 5U) << 5;
        memcpy(*(void **)(p_Var6 + 0x50),pbVar22,0x10);
        lVar33 = *(longlong *)(p_Var6 + 8);
        for (iVar13 = 10;
            (uVar12 = *(uint *)(lVar33 + 0x20), (uVar12 & 0x100) != 0 && (iVar13 != 0));
            iVar13 = iVar13 + -1) {
          StorPortStallExecution(100);
        }
        *(uint *)(lVar33 + 0x20) = uVar12 | 0x100;
        LOCK();
        UNLOCK();
      }
      if ((int)param_1[2] < 0) {
        LOCK();
        *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) | 0x20;
        UNLOCK();
        ChannelWorkerDpcRoutine((longlong)param_1,pbVar22);
      }
      else {
        bVar10 = AhciReInitializeChannelTargets((longlong)param_1,pbVar22);
        if (!bVar10) {
          iVar13 = (uint)*(byte *)((longlong)param_1 + 0xfe) * AmdSataWatchBusy;
          *(undefined4 *)((longlong)param_1 + 0xf4) = 0xa000;
          *(int *)(param_1 + 0x21) = iVar13;
          return 100000;
        }
        if (*(char *)((longlong)param_1 + 0x23) == '\0') {
          *(uint *)(param_1[0x31e] + 0x2c) = uVar28 & 0xfffffff4 | 4;
          LOCK();
          UNLOCK();
        }
      }
      *(undefined4 *)((longlong)param_1 + 0xf4) = 0;
      return 0;
    }
  } while( true );
}



===== AhciEnumerateChannelAsynchronously @ 1c0007530 =====

ulonglong AhciEnumerateChannelAsynchronously(longlong *param_1,undefined1 param_2)

{
  uint uVar1;
  void *pvVar2;
  byte *pbVar3;
  byte bVar4;
  int iVar5;
  ulonglong uVar6;
  code *pcVar7;
  code *extraout_RAX;
  undefined4 extraout_var;
  
  uVar1 = *(uint *)((longlong)param_1 + 0xf4);
  uVar6 = (ulonglong)uVar1;
  if ((uVar1 == 0) || (uVar1 == 0xa000)) {
    *(undefined1 *)((longlong)param_1 + 0x104) = param_2;
    *(undefined4 *)((longlong)param_1 + 0xf4) = 0x10;
    FireHbaNotification(*param_1,2,(int)param_1[1],*(undefined4 *)((longlong)param_1 + 0x1a34));
    LOCK();
    *(uint *)(param_1 + 2) = *(uint *)(param_1 + 2) | 4;
    UNLOCK();
    *(undefined4 *)(param_1[0x31e] + 0x14) = 0;
    LOCK();
    UNLOCK();
    *(undefined4 *)(param_1[0x31e] + 0x10) = 0xffffffff;
    LOCK();
    UNLOCK();
    StartStopDMAs(param_1,0);
    pvVar2 = (void *)param_1[-0x13];
    if (((int)param_1[-3] == 0) || ((int)param_1[-3] != *(int *)((longlong)param_1 + -0xc))) {
      if ((*(int *)((longlong)pvVar2 + 0x184) < 2) && (*(int *)((longlong)pvVar2 + 0x188) != 1)) {
        iVar5 = *(int *)((longlong)pvVar2 + 0x3b8);
        pcVar7 = AhciChannelHotplugTimerCallback;
        param_1[-5] = (longlong)AhciChannelHotplugTimerCallback;
        LOCK();
        pbVar3 = (byte *)((longlong)pvVar2 + ((longlong)(int)*(uint *)(param_1 + 1) >> 3) + 0x3b8);
        uVar1 = *(uint *)(param_1 + 1) & 7;
        bVar4 = *pbVar3;
        *pbVar3 = *pbVar3 | '\x01' << uVar1;
        UNLOCK();
        if (((bVar4 >> uVar1 & 1) == 0) && (iVar5 == 0)) {
          *(code **)((longlong)pvVar2 + 0x368) = HwStorTimer;
          HwStorTimer(pvVar2);
          pcVar7 = extraout_RAX;
        }
        return CONCAT71((int7)((ulonglong)pcVar7 >> 8),1);
      }
      *(undefined4 *)((longlong)pvVar2 + 0x3b8) = 0;
    }
    else {
      pbVar3 = (byte *)((longlong)pvVar2 +
                       ((longlong)(int)*(uint *)((longlong)param_1 + -0x8c) >> 3) + 0x3b8);
      *pbVar3 = *pbVar3 & ~('\x01' << (*(uint *)((longlong)param_1 + -0x8c) & 7));
    }
    iVar5 = AhciFailIRBs((longlong)param_1,7);
    uVar6 = CONCAT44(extraout_var,iVar5);
  }
  return uVar6 & 0xffffffffffffff00;
}



===== AhciSetDEVSLP @ 1c0007634 =====

void AhciSetDEVSLP(longlong param_1,char param_2)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  
  lVar2 = *(longlong *)(param_1 + 0x1a70);
  if (*(char *)(param_1 + 0x24) != '\0') {
    uVar1 = *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x44);
    uVar3 = uVar1 & 0xfffffffe;
    if (((*(int *)(param_1 + 0xc) == 0x101) && (*(char *)(lVar2 + 0x488) != '\0')) &&
       (param_2 != '\0')) {
      uVar3 = AmdSataDevSlp / ((uVar1 >> 0x19 & 0xf) + 1);
      if (0x3ff < uVar3) {
        uVar3 = 0x3ff;
      }
      uVar3 = ((*(uint *)(lVar2 + 0x490) & 0x1f | (uVar3 & 0x3ff) << 5) << 8 |
              *(uint *)(lVar2 + 0x48c) & 0xff) << 2 | uVar1 & 0xfe000002 | 1;
      *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x18) =
           *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x18) | 0xc000000;
      LOCK();
      UNLOCK();
    }
    *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x44) = uVar3;
    LOCK();
    UNLOCK();
  }
  return;
}



===== AhciReInitializeChannelTargets @ 1c00076fc =====

bool AhciReInitializeChannelTargets(longlong param_1,undefined *param_2)

{
  int *piVar1;
  byte *pbVar2;
  uint uVar3;
  code *pcVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  ulonglong uVar8;
  bool bVar9;
  uint local_res8 [2];
  uint local_res10;
  
  uVar8 = 0;
  pcVar4 = (code *)param_2;
  do {
    bVar7 = (byte)uVar8;
    piVar1 = *(int **)(param_1 + 0x1a70 + uVar8 * 8);
    if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
      local_res8[0] = piVar1[0xdc];
      uVar5 = 0;
      if (local_res8[0] != 0) {
        uVar6 = 0;
        if (local_res8[0] != 0) {
          for (; (local_res8[0] >> uVar6 & 1) == 0; uVar6 = uVar6 + 1) {
          }
        }
        local_res10 = uVar6;
        if (local_res8[0] != 0) {
          do {
            pcVar4 = (code *)CONCAT71((int7)((ulonglong)pcVar4 >> 8),bVar7);
            uVar3 = PresetCommand(param_1,(ulonglong)pcVar4,uVar6);
            if (uVar3 == 0) break;
            uVar5 = uVar5 | uVar3;
            pbVar2 = (byte *)((longlong)local_res8 + ((longlong)(int)uVar6 >> 3));
            *pbVar2 = *pbVar2 & ~('\x01' << (uVar6 & 7));
            uVar6 = 0;
            if (local_res8[0] != 0) {
              for (; (local_res8[0] >> uVar6 & 1) == 0; uVar6 = uVar6 + 1) {
              }
            }
          } while (local_res8[0] != 0);
          local_res10 = uVar6;
        }
        pcVar4 = Actuate;
        AhciPortRequestSynchronizedRoutine(param_1,Actuate);
        if (uVar5 != 0) break;
      }
    }
    bVar7 = bVar7 + 1;
    uVar8 = (ulonglong)bVar7;
  } while (bVar7 < *(byte *)(param_1 + 0x2c));
  bVar9 = bVar7 == *(byte *)(param_1 + 0x2c);
  if (bVar9) {
    *(undefined4 *)(param_1 + 0xf4) = 0;
    LOCK();
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x20;
    UNLOCK();
    AhciPortRequestWorkerRoutine(param_1,(ulonglong)pcVar4);
  }
  return bVar9;
}



===== StartStopDMAs @ 1c00077b0 =====

int StartStopDMAs(longlong *param_1,uint param_2)

{
  longlong lVar1;
  longlong lVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  int local_res8 [2];
  int local_res10 [2];
  
  iVar5 = 0;
  uVar4 = *(uint *)(param_1[0x31e] + 0x18);
  if ((char)param_2 == '\0') {
    if (*(char *)((longlong)param_1 + 0x22) == '\0') goto LAB_1c0007868;
    lVar1 = *param_1;
    lVar2 = *(longlong *)(lVar1 + 8);
    local_res10[0] = *(int *)(lVar2 + 0x18);
    pbVar3 = (byte *)((longlong)local_res10 + ((longlong)(int)*(uint *)(param_1 + 1) >> 3));
    *pbVar3 = *pbVar3 & ~('\x01' << (*(uint *)(param_1 + 1) & 7));
    *(int *)(lVar2 + 0x18) = local_res10[0];
    LOCK();
    UNLOCK();
    StorPortStallExecution(1000);
    *(int *)(lVar1 + 0x38) = local_res10[0];
    *(undefined1 *)((longlong)param_1 + 0x22) = 0;
    if (local_res10[0] != 0) goto LAB_1c0007868;
    *(uint *)(lVar1 + 0x48) = *(uint *)(lVar1 + 0x48) & 0xfffffffe;
    *(undefined4 *)(lVar2 + 0x14) = *(undefined4 *)(lVar1 + 0x48);
  }
  else {
    if (*(char *)((longlong)param_1 + 0x1f) != '\0') {
      *(uint *)(param_1[0x31e] + 0x40) = *(uint *)(param_1[0x31e] + 0x40) | 1;
      LOCK();
      UNLOCK();
    }
    uVar4 = uVar4 | 0x10;
    *(uint *)(param_1[0x31e] + 0x18) = uVar4;
  }
  LOCK();
  UNLOCK();
LAB_1c0007868:
  *(uint *)(param_1[0x31e] + 0x18) = (param_2 & 0xff ^ uVar4) & 1 ^ uVar4;
  LOCK();
  UNLOCK();
  do {
    StorPortStallExecution(100);
    iVar5 = iVar5 + 1;
    if ((*(uint *)(param_1[0x31e] + 0x18) >> 0xf & 1) == (param_2 & 0xff)) break;
  } while (iVar5 < 1000);
  if ((char)param_2 == '\0') {
    *(uint *)(param_1[0x31e] + 0x18) = *(uint *)(param_1[0x31e] + 0x18) & 0xffffffef;
    LOCK();
    UNLOCK();
    if (*(char *)((longlong)param_1 + 0x1f) != '\0') {
      *(uint *)(param_1[0x31e] + 0x40) = *(uint *)(param_1[0x31e] + 0x40) & 0xfffffffe;
      LOCK();
      UNLOCK();
    }
  }
  else if (*(char *)((longlong)param_1 + 0x21) != '\0') {
    lVar1 = *param_1;
    lVar2 = *(longlong *)(lVar1 + 8);
    local_res8[0] = *(int *)(lVar2 + 0x18);
    if (*(int *)(lVar2 + 0x18) == 0) {
      *(uint *)(lVar1 + 0x48) = *(uint *)(lVar1 + 0x48) | 1;
      *(undefined4 *)(lVar2 + 0x14) = *(undefined4 *)(lVar1 + 0x48);
      LOCK();
      UNLOCK();
    }
    pbVar3 = (byte *)((longlong)local_res8 + ((longlong)(int)*(uint *)(param_1 + 1) >> 3));
    *pbVar3 = *pbVar3 | '\x01' << (*(uint *)(param_1 + 1) & 7);
    *(int *)(lVar1 + 0x38) = local_res8[0];
    *(int *)(lVar2 + 0x18) = local_res8[0];
    LOCK();
    UNLOCK();
    StorPortStallExecution(1000);
    *(undefined1 *)((longlong)param_1 + 0x22) = 1;
  }
  return iVar5 % 1000;
}



===== AtaInquiryCompetion @ 1c0007980 =====

undefined8 AtaInquiryCompetion(longlong param_1,longlong param_2)

{
  void *_Src;
  longlong lVar1;
  ulonglong in_RAX;
  
  if (*(char *)(param_2 + 2) == '\x01') {
    _Src = *(void **)(param_2 + 0x38);
    lVar1 = *(longlong *)(param_1 + 0x1a70 + (ulonglong)*(byte *)(param_2 + 6) * 8);
    memcpy((void *)(lVar1 + 0x18),_Src,0x200);
    if (((*(ushort *)((longlong)_Src + 0xa6) & 0x400) == 0) ||
       ((*(ushort *)((longlong)_Src + 0xac) & 0x400) == 0)) {
      in_RAX = (ulonglong)(*(int *)((longlong)_Src + 0x78) - 1);
    }
    else {
      in_RAX = *(longlong *)((longlong)_Src + 200) - 1;
    }
    *(ulonglong *)(lVar1 + 0x10) = in_RAX;
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== AhciCompleteIssuedIRBs @ 1c0007a00 =====

int AhciCompleteIssuedIRBs(longlong param_1)

{
  byte bVar1;
  ushort uVar2;
  ushort *puVar3;
  undefined1 auVar4 [16];
  byte *pbVar5;
  uint uVar6;
  longlong lVar7;
  longlong lVar8;
  undefined4 *puVar9;
  ulonglong uVar10;
  int iVar11;
  bool bVar12;
  uint local_res8 [2];
  uint local_res10;
  
  iVar11 = 0;
  local_res8[0] =
       ~(*(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x34) |
        *(uint *)(*(longlong *)(param_1 + 0x18f0) + 0x38)) & *(uint *)(param_1 + 0x124);
  uVar6 = 0;
  bVar12 = local_res8[0] == 0;
  if (!bVar12) {
    for (; (local_res8[0] >> uVar6 & 1) == 0; uVar6 = uVar6 + 1) {
    }
  }
  do {
    local_res10 = uVar6;
    if (bVar12) {
      return iVar11;
    }
    pbVar5 = (byte *)((longlong)local_res8 + ((longlong)(int)uVar6 >> 3));
    *pbVar5 = *pbVar5 & ~('\x01' << (uVar6 & 7));
    puVar9 = (undefined4 *)(param_1 + 0x2a8 + (ulonglong)uVar6 * 0x38);
    puVar3 = *(ushort **)(puVar9 + 2);
    bVar1 = *(byte *)((longlong)puVar9 + 0x29);
    pbVar5 = (byte *)(param_1 + 0x128 + ((longlong)(int)uVar6 >> 3));
    *pbVar5 = *pbVar5 & ~('\x01' << (uVar6 & 7));
    pbVar5 = (byte *)(param_1 + 0x124 + ((longlong)(int)uVar6 >> 3));
    *pbVar5 = *pbVar5 & ~('\x01' << (uVar6 & 7));
    pbVar5 = (byte *)(param_1 + 0x174 + (ulonglong)*(byte *)((longlong)puVar9 + 0x29) * 4 +
                     ((longlong)(int)uVar6 >> 3));
    *pbVar5 = *pbVar5 & ~('\x01' << (uVar6 & 7));
    pbVar5 = (byte *)(param_1 + 0x138 + (ulonglong)*(byte *)((longlong)puVar9 + 0x29) * 4 +
                     ((longlong)(int)uVar6 >> 3));
    *pbVar5 = *pbVar5 & ~('\x01' << (uVar6 & 7));
    pbVar5 = (byte *)(param_1 + 0x1b0 + (ulonglong)*(byte *)((longlong)puVar9 + 0x29) * 4 +
                     ((longlong)(int)uVar6 >> 3));
    *pbVar5 = *pbVar5 & ~('\x01' << (uVar6 & 7));
    uVar2 = *puVar3;
    if ((((uVar2 == 0x201) || (uVar2 == 0x105)) || ((byte)((char)puVar3[0x35] + 0xa0U) < 2)) ||
       (*(int *)(*(longlong *)(puVar9 + 4) + 4) == *(int *)(puVar3 + 0xc))) {
      *(undefined1 *)(puVar3 + 1) = 1;
    }
    else {
      *(int *)(puVar3 + 0xc) = *(int *)(*(longlong *)(puVar9 + 4) + 4);
      *(undefined1 *)(puVar3 + 1) = 2;
    }
    if (uVar2 < 0x100) {
      lVar7 = *(longlong *)(param_1 + 0x1a70 + (ulonglong)bVar1 * 8);
      if (uVar2 == 0x11) {
        if (((**(byte **)(param_1 + 0x1a28) & 0xc0) == 0) && (*(int *)(lVar7 + 0x21c) != 0)) {
          uVar6 = *(uint *)(lVar7 + 0x224);
          do {
            lVar8 = *(longlong *)(lVar7 + 0x228 + (ulonglong)uVar6 * 8);
            if (*(byte *)(lVar8 + 0xb) == (**(byte **)(param_1 + 0x1a28) & 0x1f)) {
              *(int *)(lVar8 + 0x60) = *(int *)(lVar8 + 0x60) + 1;
              if (5 < *(uint *)(lVar8 + 0x60)) {
                *(undefined1 *)(lVar8 + 2) = 3;
              }
              break;
            }
            uVar6 = uVar6 + 1 & 0x1f;
          } while (uVar6 != *(uint *)(lVar7 + 0x220));
        }
        *(undefined1 *)(param_1 + 0x1a30) = 0;
        *(uint *)(lVar7 + 0x218) = *(uint *)(lVar7 + 0x218) & 0xfffffffe;
      }
      else if ((uVar2 == 0x10) &&
              (AhciHwPresetComplete(param_1,(longlong)puVar9), *(int *)(param_1 + 0x124) == 0)) {
        LOCK();
        *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x1000000;
        UNLOCK();
      }
      *(undefined8 *)(puVar9 + 4) = 0;
      *(undefined8 *)(puVar9 + 0xc) = 0;
      *(undefined8 *)(puVar9 + 2) = 0;
      *puVar9 = 0;
      puVar9[10] = 0;
      uVar10 = (longlong)puVar9 + (-0x2a8 - param_1);
      auVar4._8_8_ = 0;
      auVar4._0_8_ = uVar10;
      lVar7 = SUB168(ZEXT816(0x2492492492492493) * auVar4,8);
      LOCK();
      uVar6 = (uint)((uVar10 - lVar7 >> 1) + lVar7 >> 5);
      pbVar5 = (byte *)(param_1 + 300 + ((longlong)(int)uVar6 >> 3));
      *pbVar5 = *pbVar5 & ~('\x01' << (uVar6 & 7));
      UNLOCK();
    }
    else {
      iVar11 = iVar11 + 1;
      if (*(longlong *)(puVar3 + 0x20) != 0) {
        lVar7 = *(longlong *)(param_1 + 0x1a20);
        lVar8 = (longlong)(int)(-(uint)(*(char *)(param_1 + 0x1f) != '\0') & (uint)bVar1) * 0x100;
        *(undefined1 *)(puVar3 + 0x35) = *(undefined1 *)(lVar8 + 0x42 + lVar7);
        *(undefined1 *)(puVar3 + 0x32) = *(undefined1 *)(lVar8 + 0x43 + lVar7);
        *(undefined1 *)(puVar3 + 0x34) = *(undefined1 *)(lVar8 + 0x46 + lVar7);
        *(undefined1 *)((longlong)puVar3 + 0x67) = *(undefined1 *)(lVar8 + 0x45 + lVar7);
        *(undefined1 *)((longlong)puVar3 + 0x69) = *(undefined1 *)(lVar8 + 0x47 + lVar7);
        *(undefined1 *)((longlong)puVar3 + 0x65) = *(undefined1 *)(lVar8 + 0x4c + lVar7);
        *(undefined1 *)(puVar3 + 0x33) = *(undefined1 *)(lVar8 + 0x44 + lVar7);
        if ((*(uint *)(*(longlong *)(puVar9 + 2) + 0x10) & 8) != 0) {
          *(undefined1 *)(puVar3 + 0x39) = *(undefined1 *)(lVar8 + 0x42 + lVar7);
          *(undefined1 *)(puVar3 + 0x36) = *(undefined1 *)(lVar8 + 0x43 + lVar7);
          *(undefined1 *)(puVar3 + 0x38) = *(undefined1 *)(lVar8 + 0x4a + lVar7);
          *(undefined1 *)((longlong)puVar3 + 0x6f) = *(undefined1 *)(lVar8 + 0x49 + lVar7);
          *(undefined1 *)((longlong)puVar3 + 0x71) = *(undefined1 *)(lVar8 + 0x47 + lVar7);
          *(undefined1 *)((longlong)puVar3 + 0x6d) = *(undefined1 *)(lVar8 + 0x4d + lVar7);
          *(undefined1 *)(puVar3 + 0x37) = *(undefined1 *)(lVar8 + 0x48 + lVar7);
        }
        *(byte *)(puVar3 + 1) = (byte)puVar3[1] | 0x10;
      }
      ReleaseSlottedCommand(param_1,puVar9);
    }
    uVar6 = 0;
    bVar12 = local_res8[0] == 0;
    if (!bVar12) {
      for (; (local_res8[0] >> uVar6 & 1) == 0; uVar6 = uVar6 + 1) {
      }
    }
  } while( true );
}



===== AhciAbortDeviceQueue @ 1c0007ca4 =====

int AhciAbortDeviceQueue(longlong param_1,byte param_2,undefined1 param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  ushort *puVar5;
  
  lVar4 = *(longlong *)(param_1 + 0x1a70 + (ulonglong)param_2 * 8);
  iVar1 = *(int *)(lVar4 + 0x21c);
  iVar3 = iVar1;
  while (iVar3 != 0) {
    uVar2 = *(uint *)(lVar4 + 0x224);
    puVar5 = *(ushort **)(lVar4 + 0x228 + (ulonglong)uVar2 * 8);
    *(undefined1 *)(puVar5 + 1) = param_3;
    AhciPortCompleteRequest(param_1,puVar5);
    *(int *)(lVar4 + 0x21c) = *(int *)(lVar4 + 0x21c) + -1;
    *(uint *)(lVar4 + 0x224) = uVar2 + 1 & 0x1f;
    *(int *)(param_1 + 0x18d4) = *(int *)(param_1 + 0x18d4) + -1;
    iVar3 = *(int *)(lVar4 + 0x21c);
  }
  return iVar1;
}



===== AhciFailIRBs @ 1c0007d28 =====

int AhciFailIRBs(longlong param_1,undefined1 param_2)

{
  int iVar1;
  ushort *puVar2;
  uint uVar3;
  undefined1 auVar4 [16];
  byte *pbVar5;
  longlong lVar6;
  longlong *plVar7;
  byte bVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  ulonglong uVar12;
  
  uVar10 = *(uint *)(param_1 + 300);
  iVar9 = 0;
  while( true ) {
    uVar3 = 0;
    if (uVar10 != 0) {
      for (; (uVar10 >> uVar3 & 1) == 0; uVar3 = uVar3 + 1) {
      }
    }
    if (uVar10 == 0) break;
    puVar11 = (undefined4 *)(param_1 + 0x2a8 + (ulonglong)uVar3 * 0x38);
    puVar2 = *(ushort **)(puVar11 + 2);
    *(undefined1 *)(puVar2 + 1) = param_2;
    if (*puVar2 < 0x100) {
      *(undefined8 *)(puVar11 + 4) = 0;
      *(undefined8 *)(puVar11 + 0xc) = 0;
      *(undefined8 *)(puVar11 + 2) = 0;
      *puVar11 = 0;
      puVar11[10] = 0;
      uVar12 = (longlong)puVar11 + (-0x2a8 - param_1);
      auVar4._8_8_ = 0;
      auVar4._0_8_ = uVar12;
      lVar6 = SUB168(ZEXT816(0x2492492492492493) * auVar4,8);
      LOCK();
      uVar10 = (uint)((uVar12 - lVar6 >> 1) + lVar6 >> 5);
      pbVar5 = (byte *)(param_1 + 300 + ((longlong)(int)uVar10 >> 3));
      *pbVar5 = *pbVar5 & ~('\x01' << (uVar10 & 7));
      UNLOCK();
    }
    else {
      iVar9 = iVar9 + 1;
      ReleaseSlottedCommand(param_1,puVar11);
    }
    uVar10 = *(uint *)(param_1 + 300);
  }
  *(undefined8 *)(param_1 + 0x128) = 0;
  puVar11 = (undefined4 *)(param_1 + 0x174);
  *(undefined1 *)(param_1 + 0x18) = 0;
  lVar6 = 0xf;
  *(undefined8 *)(param_1 + 0x18cc) = 0;
  *(undefined4 *)(param_1 + 0x18c8) = 0;
  *(undefined4 *)(param_1 + 0x124) = 0;
  do {
    puVar11[0xf] = 0;
    *puVar11 = 0;
    puVar11[-0xf] = 0;
    puVar11 = puVar11 + 1;
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  iVar1 = *(int *)(param_1 + 0x18d4);
  plVar7 = (longlong *)(param_1 + 0x1a70);
  bVar8 = 0;
  do {
    if (*plVar7 != 0) {
      AhciAbortDeviceQueue(param_1,bVar8,param_2);
    }
    bVar8 = bVar8 + 1;
    plVar7 = plVar7 + 1;
  } while (bVar8 < 0xf);
  return iVar9 + iVar1;
}



===== StartIoWmiSrb @ 1c0007e64 =====

bool StartIoWmiSrb(longlong param_1,longlong param_2)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  char cVar4;
  uint *puVar5;
  uint local_res10 [2];
  int local_res18 [2];
  longlong local_38;
  ulonglong local_30;
  uint *local_28;
  undefined8 local_20;
  
  local_30 = 0;
  local_28 = (uint *)0x0;
  bVar1 = *(byte *)(param_2 + 4);
  local_res10[0] = 0;
  local_38 = param_2;
  if (bVar1 < 10) {
    local_30 = (ulonglong)*(uint *)(param_2 + 0x10);
    local_20 = (ulonglong)bVar1;
    puVar5 = (uint *)(param_1 + 0x140);
    if ((*(byte *)(param_2 + 9) & 1) != 0) {
      puVar5 = (uint *)(param_1 + 0x100);
    }
    local_28 = *(uint **)(param_2 + 0x18);
    cVar2 = ScsiWmipProcessRequest
                      (puVar5,bVar1,param_1,&local_38,*(longlong **)(param_2 + 0x20),
                       *(uint *)(param_2 + 0x10),*(uint **)(param_2 + 0x18),local_res10,local_res18)
    ;
    if (local_res18[0] == 1) {
      local_20._0_2_ = CONCAT11(cVar2,(undefined1)local_20);
      uVar3 = local_res10[0];
      if (cVar2 != '\x01') {
        uVar3 = 0;
      }
      local_20 = CONCAT44(uVar3,(undefined4)local_20);
      cVar4 = cVar2;
    }
    else {
      uVar3 = local_20._4_4_;
      cVar4 = local_20._1_1_;
    }
  }
  else {
    cVar2 = '\x04';
    local_20 = 0x400;
    uVar3 = 0;
    cVar4 = '\x04';
  }
  *(char *)(param_2 + 3) = cVar4;
  *(uint *)(param_2 + 0x10) = uVar3;
  StorPortNotification(0,param_1,param_2);
  return cVar2 == '\0';
}



===== FireHbaNotification @ 1c0007f68 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FireHbaNotification(longlong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined1 auStack_c8 [56];
  undefined1 *local_90;
  undefined1 local_88;
  undefined1 local_87 [63];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_c8;
  bVar1 = *(char *)(param_1 + 0xa0) != '\0';
  if (bVar1) {
    local_88 = 0;
    memset(local_87,0,0x4b);
    local_90 = &local_88;
    local_48 = param_2;
    local_44 = param_3;
    local_40 = param_4;
    ScsiPortWmiFireLogicalUnitEvent(param_1 + -0xe028);
  }
  return bVar1;
}



===== HwStorWmiQueryReginfo @ 1c0008000 =====

undefined8 HwStorWmiQueryReginfo(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  *param_3 = L"AmdSataMof";
  return 0x1c000f601;
}



===== HwStorWmiQueryDataBlock @ 1c0008010 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char HwStorWmiQueryDataBlock
               (longlong param_1,longlong *param_2,int param_3,undefined8 param_4,undefined8 param_5
               ,uint *param_6,uint param_7,undefined8 *param_8)

{
  int iVar1;
  longlong lVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  ulonglong uVar7;
  ushort *puVar8;
  char cVar9;
  uint uVar10;
  longlong lVar11;
  uint uVar12;
  undefined8 *puVar13;
  uint uVar14;
  undefined1 auStack_88 [32];
  byte local_68;
  longlong local_60;
  undefined1 local_58;
  undefined7 uStack_57;
  undefined1 uStack_50;
  undefined7 uStack_4f;
  undefined1 uStack_48;
  undefined4 uStack_47;
  undefined2 uStack_43;
  undefined1 uStack_41;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_88;
  lVar11 = *(longlong *)(param_1 + 0x228);
  uVar10 = 0;
  lVar2 = *param_2;
  local_60 = lVar11;
  if ((*(byte *)(lVar2 + 9) & 1) == 0) {
    if (param_3 != 0) goto LAB_1c00084f7;
    uVar10 = 0x28;
    if ((0x27 < param_7) && (param_6 != (uint *)0x0)) {
      lVar11 = *(longlong *)
                (param_1 + 0x368 +
                ((ulonglong)*(byte *)(lVar2 + 5) * 0x371 + (ulonglong)*(byte *)(lVar2 + 6)) * 8);
      *param_8 = *(undefined8 *)(lVar11 + 0x338);
      param_8[1] = *(undefined8 *)(lVar11 + 0x340);
      param_8[2] = *(undefined8 *)(lVar11 + 0x348);
      param_8[3] = *(undefined8 *)(lVar11 + 0x350);
      param_8[4] = *(longlong *)(lVar11 + 0x368) + *(longlong *)(lVar11 + 0x360) +
                   *(longlong *)(lVar11 + 0x358);
      goto LAB_1c0008568;
    }
  }
  else if (param_3 == 0) {
    uVar10 = 0x1d;
    if ((0x1c < param_7) && (param_6 != (uint *)0x0)) {
      *(undefined4 *)param_8 = *(undefined4 *)(lVar11 + 0x14);
      *(byte *)((longlong)param_8 + 4) = (byte)((uint)*(undefined4 *)(lVar11 + 0x24) >> 0x1e) & 1;
      *(byte *)((longlong)param_8 + 5) = (byte)((uint)*(undefined4 *)(lVar11 + 0x24) >> 0x1d) & 1;
      *(byte *)((longlong)param_8 + 6) = *(byte *)(lVar11 + 0x27) & 1;
      *(byte *)((longlong)param_8 + 7) = (byte)((uint)*(undefined4 *)(lVar11 + 0x24) >> 0x1b) & 1;
      *(byte *)(param_8 + 1) = (byte)((uint)*(undefined4 *)(lVar11 + 0x24) >> 0x1a) & 1;
      *(byte *)((longlong)param_8 + 9) = (byte)(*(uint *)(lVar11 + 0x24) >> 0x11) & 1;
      *(byte *)((longlong)param_8 + 10) = *(byte *)(lVar11 + 0x26) & 1;
      *(byte *)((longlong)param_8 + 0xb) = (byte)(*(uint *)(lVar11 + 0x24) >> 0xe) & 1;
      *(byte *)((longlong)param_8 + 0xc) = (byte)(*(uint *)(lVar11 + 0x24) >> 0xd) & 1;
      *(byte *)((longlong)param_8 + 0xd) = (byte)(*(uint *)(lVar11 + 0x28) >> 2) & 1;
      *(byte *)((longlong)param_8 + 0xe) = (byte)(*(uint *)(lVar11 + 0x24) >> 5) & 1;
      *(uint *)(param_8 + 2) = (*(uint *)(lVar11 + 0x24) >> 8 & 0x1f) + 1;
      *(uint *)((longlong)param_8 + 0x14) = (*(uint *)(lVar11 + 0x24) & 0x1f) + 1;
      *(byte *)(param_8 + 3) = (byte)(*(uint *)(lVar11 + 0x24) >> 6) & 1;
      *(byte *)((longlong)param_8 + 0x19) = (byte)(*(uint *)(lVar11 + 0x28) >> 1) & 1;
      *(byte *)((longlong)param_8 + 0x1a) = (byte)(*(uint *)(lVar11 + 0x28) >> 3) & 1;
      *(byte *)((longlong)param_8 + 0x1b) = (byte)(*(uint *)(lVar11 + 0x28) >> 4) & 1;
      *(byte *)((longlong)param_8 + 0x1c) = (byte)(*(uint *)(lVar11 + 0x28) >> 5) & 1;
LAB_1c0008568:
      *param_6 = uVar10;
LAB_1c000856b:
      cVar9 = '\x01';
      goto LAB_1c0008572;
    }
  }
  else {
    if (param_3 != 1) {
      if (param_3 == 2) {
        if ((char)param_2[3] == '\0') {
          lVar2 = param_2[2];
          iVar5 = (*(uint *)(lVar11 + 0x24) & 0x1f) + 1;
          if (-1 < (char)*(undefined4 *)(lVar2 + 0x2c)) {
            uVar14 = *(uint *)(param_2 + 1);
            iVar1 = iVar5 * 8 + 0x3c;
            *(int *)(lVar2 + 0x38) = iVar1;
            *(int *)(lVar2 + 0x34) = iVar5;
            uVar4 = iVar1 + iVar5 * 4 + 7U & 0xfffffff8;
            *(uint *)(lVar2 + 0x30) = uVar4;
            uVar10 = uVar4;
            if (uVar4 < 0x48) {
              uVar10 = 0x48;
            }
            if (uVar14 < uVar4) {
              uVar14 = 0;
            }
            else {
              uVar14 = uVar14 - uVar4;
              memset((void *)(lVar2 + 0x3c),0,(ulonglong)(uVar4 - 0x3c));
            }
            local_68 = 0;
            cVar9 = '\x01';
            if ((*(uint *)(lVar11 + 0x24) & 0x1f) != 0xffffffff) {
              uVar7 = 0;
              do {
                lVar11 = (ulonglong)local_68 * 0x1b88;
                puVar6 = (undefined4 *)0x0;
                local_58 = 0;
                uStack_57 = 0;
                uStack_50 = 0;
                uStack_4f = 0;
                uStack_48 = 0;
                uStack_47 = 0;
                uStack_43 = 0;
                uStack_41 = 0;
                if (((char)param_2[3] == '\0') &&
                   (lVar2 = param_2[2], -1 < (char)*(undefined4 *)(lVar2 + 0x2c))) {
                  uVar12 = uVar10 + 7 & 0xfffffff8;
                  uVar4 = (uVar12 - uVar10) + 0x24;
                  uVar10 = uVar10 + uVar4;
                  if (uVar14 < uVar4) {
                    uVar14 = 0;
                  }
                  else {
                    iVar5 = *(int *)(lVar2 + 0x30);
                    uVar14 = uVar14 - uVar4;
                    *(undefined4 *)(lVar2 + 0x40 + uVar7 * 8) = 0x24;
                    *(uint *)(lVar2 + 0x3c + uVar7 * 8) = iVar5 + uVar12;
                    puVar6 = (undefined4 *)
                             ((ulonglong)uVar12 + (ulonglong)*(uint *)(lVar2 + 0x30) + lVar2);
                  }
                  if ((puVar6 == (undefined4 *)0x0) || (uVar14 < 0x24)) goto LAB_1c0008188;
                }
                else {
LAB_1c0008188:
                  cVar9 = '\x12';
                }
                if (cVar9 != '\x12') {
                  *puVar6 = *(undefined4 *)(lVar11 + 0x48c + param_1);
                  *(undefined1 *)(puVar6 + 1) = *(undefined1 *)(lVar11 + 0x4ac + param_1);
                  *(undefined1 *)((longlong)puVar6 + 5) = *(undefined1 *)(lVar11 + 0x49f + param_1);
                  *(undefined1 *)((longlong)puVar6 + 6) = *(undefined1 *)(lVar11 + 0x499 + param_1);
                  *(undefined1 *)((longlong)puVar6 + 7) = *(undefined1 *)(lVar11 + 0x4b2 + param_1);
                  puVar6[2] = *(undefined4 *)(lVar11 + 0x1ed8 + param_1);
                  puVar6[3] = *(undefined4 *)(lVar11 + 0x4b8 + param_1);
                  puVar6[4] = *(undefined4 *)(lVar11 + 0x4bc + param_1);
                  puVar6[5] = *(undefined4 *)(lVar11 + 0x4c0 + param_1);
                  puVar6[6] = *(undefined4 *)(lVar11 + 0x570 + param_1);
                  puVar6[7] = *(undefined4 *)(lVar11 + 0x568 + param_1);
                  puVar6[8] = *(undefined4 *)(lVar11 + 0x5b4 + param_1);
                }
                uVar4 = uVar10;
                if (((char)param_2[3] == '\0') &&
                   (lVar11 = param_2[2], -1 < (char)*(undefined4 *)(lVar11 + 0x2c))) {
                  uVar4 = uVar10 + 0x18;
                  if (uVar14 < 0x18) {
                    uVar14 = 0;
                    goto LAB_1c0008267;
                  }
                  uVar14 = uVar14 - 0x18;
                  *(uint *)((ulonglong)*(uint *)(lVar11 + 0x38) + lVar11 + (ulonglong)local_68 * 4)
                       = *(int *)(lVar11 + 0x30) + uVar10;
                  puVar13 = (undefined8 *)
                            ((ulonglong)uVar10 + (ulonglong)*(uint *)(lVar11 + 0x30) + lVar11);
                  uVar10 = uVar4;
                }
                else {
LAB_1c0008267:
                  puVar13 = (undefined8 *)0x0;
                  uVar10 = uVar4;
                }
                if ((puVar13 == (undefined8 *)0x0) || (uVar14 < 0x18)) {
                  cVar9 = '\x12';
                }
                if (cVar9 != '\x12') {
                  GetChannelInstanceName((undefined2 *)&local_58,local_68);
                  *puVar13 = CONCAT71(uStack_57,local_58);
                  puVar13[1] = CONCAT71(uStack_4f,uStack_50);
                  puVar13[2] = CONCAT17(uStack_41,CONCAT25(uStack_43,CONCAT41(uStack_47,uStack_48)))
                  ;
                }
                local_68 = local_68 + 1;
                uVar7 = (ulonglong)local_68;
              } while ((uint)local_68 < (*(uint *)(local_60 + 0x24) & 0x1f) + 1);
            }
            goto LAB_1c0008572;
          }
        }
        else if ((char)param_2[3] == '\x01') {
          lVar11 = param_2[2];
          if ((char)*(undefined4 *)(lVar11 + 0x2c) < '\0') {
            puVar8 = (ushort *)0x0;
          }
          else {
            puVar8 = (ushort *)((ulonglong)*(uint *)(lVar11 + 0x30) + lVar11);
          }
          if ((puVar8 == (ushort *)0x0) || (*puVar8 < 0x14)) {
            bVar3 = 0xff;
          }
          else {
            bVar3 = (char)puVar8[10] + (char)puVar8[9] * -6 & 0xf;
          }
          if (bVar3 < *(byte *)(param_1 + 0x1c)) {
            uVar10 = 0x24;
            if (param_7 < 0x24) goto LAB_1c0008570;
            lVar11 = (ulonglong)bVar3 * 0x1b88;
            *(undefined4 *)param_8 = *(undefined4 *)(lVar11 + 0x48c + param_1);
            *(undefined1 *)((longlong)param_8 + 4) = *(undefined1 *)(lVar11 + 0x4ac + param_1);
            *(undefined1 *)((longlong)param_8 + 5) = *(undefined1 *)(lVar11 + 0x49f + param_1);
            *(undefined1 *)((longlong)param_8 + 6) = *(undefined1 *)(lVar11 + 0x499 + param_1);
            *(undefined1 *)((longlong)param_8 + 7) = *(undefined1 *)(lVar11 + 0x4b2 + param_1);
            *(undefined4 *)(param_8 + 1) = *(undefined4 *)(lVar11 + 0x1ed8 + param_1);
            *(undefined4 *)((longlong)param_8 + 0xc) = *(undefined4 *)(lVar11 + 0x4b8 + param_1);
            *(undefined4 *)(param_8 + 2) = *(undefined4 *)(lVar11 + 0x4bc + param_1);
            *(undefined4 *)((longlong)param_8 + 0x14) = *(undefined4 *)(lVar11 + 0x4c0 + param_1);
            *(undefined4 *)(param_8 + 3) = *(undefined4 *)(lVar11 + 0x570 + param_1);
            *(undefined4 *)((longlong)param_8 + 0x1c) = *(undefined4 *)(lVar11 + 0x568 + param_1);
            *(undefined4 *)(param_8 + 4) = *(undefined4 *)(lVar11 + 0x5b4 + param_1);
            *param_6 = 0x24;
            goto LAB_1c000856b;
          }
        }
      }
LAB_1c00084f7:
      cVar9 = '\x04';
      goto LAB_1c0008572;
    }
    uVar10 = 0xc;
    if ((0xb < param_7) && (param_6 != (uint *)0x0)) {
      *(undefined4 *)param_8 = atapt;
      goto LAB_1c0008568;
    }
  }
LAB_1c0008570:
  cVar9 = '\x12';
LAB_1c0008572:
  ScsiPortWmiPostProcess((longlong)param_2,cVar9,uVar10);
  return cVar9;
}



===== HwStorWmiSetDataBlock @ 1c00085b0 =====

char HwStorWmiSetDataBlock
               (longlong param_1,longlong *param_2,int param_3,undefined8 param_4,uint param_5,
               undefined4 *param_6)

{
  uint uVar1;
  byte bVar2;
  ushort *puVar3;
  longlong lVar4;
  char cVar5;
  uint uVar6;
  
  uVar6 = 0;
  cVar5 = '\x01';
  if (((*(byte *)(*param_2 + 9) & 1) != 0) && (param_3 != 0)) {
    if (param_3 == 1) {
      uVar6 = 0xc;
      uVar1 = 0xc;
      if (0xb < param_5) {
        atapt = *param_6;
        goto LAB_1c00086ad;
      }
LAB_1c00086a7:
      uVar6 = uVar1;
      cVar5 = '\x12';
      goto LAB_1c00086ad;
    }
    if (param_3 != 2) goto LAB_1c00086ab;
    uVar6 = 0x24;
    uVar1 = uVar6;
    if (param_5 < 0x24) goto LAB_1c00086a7;
    if (((byte)((char)param_2[3] - 1U) < 3) || ((char)param_2[3] == '\t')) {
      lVar4 = param_2[2];
      if ((char)*(undefined4 *)(lVar4 + 0x2c) < '\0') {
        puVar3 = (ushort *)0x0;
      }
      else {
        puVar3 = (ushort *)((ulonglong)*(uint *)(lVar4 + 0x30) + lVar4);
      }
      if ((puVar3 == (ushort *)0x0) || (*puVar3 < 0x14)) goto LAB_1c0008641;
      bVar2 = (char)puVar3[10] + (char)puVar3[9] * -6 & 0xf;
    }
    else {
LAB_1c0008641:
      bVar2 = 0xff;
    }
    if (bVar2 < *(byte *)(param_1 + 0x1c)) {
      lVar4 = (ulonglong)bVar2 * 0x1b88;
      *(undefined4 *)(lVar4 + 0x4b8 + param_1) = param_6[3];
      *(undefined4 *)(lVar4 + 0x4bc + param_1) = param_6[4];
      *(undefined4 *)(lVar4 + 0x4c0 + param_1) = param_6[5];
      *(undefined4 *)(lVar4 + 0x570 + param_1) = param_6[6];
      *(undefined4 *)(lVar4 + 0x568 + param_1) = param_6[7];
      goto LAB_1c00086ad;
    }
  }
LAB_1c00086ab:
  cVar5 = '\x04';
LAB_1c00086ad:
  ScsiPortWmiPostProcess((longlong)param_2,cVar5,uVar6);
  return cVar5;
}



===== HwStorWmiSetDataItem @ 1c00086d0 =====

char HwStorWmiSetDataItem
               (longlong param_1,longlong *param_2,int param_3,undefined8 param_4,int param_5,
               uint param_6,undefined4 *param_7)

{
  byte bVar1;
  ushort *puVar2;
  longlong lVar3;
  char cVar4;
  uint uVar5;
  
  puVar2 = (ushort *)0x0;
  uVar5 = 0;
  if (((*(byte *)(*param_2 + 9) & 1) == 0) || (param_3 == 0)) {
LAB_1c0008868:
    cVar4 = '\x04';
    goto LAB_1c000886d;
  }
  if (param_3 == 1) {
    cVar4 = '\x04';
    if (param_5 != 1) {
      if ((param_5 == 2) || (param_5 == 3)) {
        uVar5 = 4;
        cVar4 = (-(param_6 < 4) & 0x11U) + 1;
      }
      goto LAB_1c000886d;
    }
    if (param_6 < 4) goto LAB_1c0008864;
    atapt = *param_7;
  }
  else {
    if (param_3 != 2) goto LAB_1c0008868;
    if (((byte)((char)param_2[3] - 1U) < 3) || ((char)param_2[3] == '\t')) {
      lVar3 = param_2[2];
      if (-1 < (char)*(undefined4 *)(lVar3 + 0x2c)) {
        puVar2 = (ushort *)((ulonglong)*(uint *)(lVar3 + 0x30) + lVar3);
      }
      if ((puVar2 == (ushort *)0x0) || (*puVar2 < 0x14)) goto LAB_1c0008754;
      bVar1 = (char)puVar2[10] + (char)puVar2[9] * -6 & 0xf;
    }
    else {
LAB_1c0008754:
      bVar1 = 0xff;
    }
    cVar4 = '\x04';
    if (*(byte *)(param_1 + 0x1c) <= bVar1) goto LAB_1c000886d;
    lVar3 = (ulonglong)bVar1 * 0x1b88;
    if (param_5 == 7) {
      if (param_6 < 4) {
LAB_1c0008864:
        uVar5 = 4;
        cVar4 = '\x12';
        goto LAB_1c000886d;
      }
      *(undefined4 *)(lVar3 + 0x4b8 + param_1) = *param_7;
    }
    else if (param_5 == 8) {
      if (param_6 < 4) goto LAB_1c0008864;
      *(undefined4 *)(lVar3 + 0x4bc + param_1) = *param_7;
    }
    else if (param_5 == 9) {
      if (param_6 < 4) goto LAB_1c0008864;
      *(undefined4 *)(lVar3 + 0x4c0 + param_1) = *param_7;
    }
    else if (param_5 == 10) {
      if (param_6 < 4) goto LAB_1c0008864;
      *(undefined4 *)(lVar3 + 0x570 + param_1) = *param_7;
    }
    else {
      if (param_5 != 0xb) goto LAB_1c000886d;
      if (param_6 < 4) goto LAB_1c0008864;
      *(undefined4 *)(lVar3 + 0x568 + param_1) = *param_7;
    }
  }
  uVar5 = 4;
  cVar4 = '\x01';
LAB_1c000886d:
  ScsiPortWmiPostProcess((longlong)param_2,cVar4,uVar5);
  return cVar4;
}



===== HwStorWmiFunctionControl @ 1c0008890 =====

char HwStorWmiFunctionControl
               (longlong param_1,longlong *param_2,int param_3,int param_4,undefined1 param_5)

{
  longlong lVar1;
  char cVar2;
  
  lVar1 = *param_2;
  cVar2 = '\x01';
  if ((*(byte *)(lVar1 + 9) & 1) == 0) {
    if ((param_4 == 0) && (param_3 == 1)) {
      *(undefined1 *)
       (*(longlong *)
         (param_1 + 0x1ef0 +
         ((ulonglong)*(byte *)(lVar1 + 5) * 0x371 + (ulonglong)*(byte *)(lVar1 + 6)) * 8) + 0x485) =
           param_5;
      goto LAB_1c00088b8;
    }
  }
  else if ((param_4 == 0) && (param_3 == 3)) {
    *(undefined1 *)(*(longlong *)(param_1 + 0x228) + 0xa0) = param_5;
    goto LAB_1c00088b8;
  }
  cVar2 = '\x04';
LAB_1c00088b8:
  ScsiPortWmiPostProcess((longlong)param_2,cVar2,0);
  return cVar2;
}



===== GetChannelInstanceName @ 1c0008920 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 GetChannelInstanceName(undefined2 *param_1,byte param_2)

{
  void *pvVar1;
  undefined8 uVar2;
  undefined1 auStack_48 [32];
  undefined1 local_28;
  undefined8 local_27;
  ulonglong local_1f;
  undefined4 local_17;
  undefined1 local_13;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  if (param_2 < 100) {
    local_28 = 0;
    local_27 = 0;
    local_1f = 0;
    local_17 = 0;
    local_13 = 0;
    memcpy(&local_28,L"Channel#00",0x16);
    local_1f = CONCAT17(param_2 / 10,(undefined7)local_1f) | 0x3000000000000000;
    local_17 = CONCAT22(local_17._2_2_,CONCAT11(param_2 % 10,(undefined1)local_17)) | 0x3000;
    pvVar1 = memcpy(param_1 + 1,&local_28,0x16);
    uVar2 = CONCAT71((int7)((ulonglong)pvVar1 >> 8),1);
    *param_1 = 0x16;
  }
  else {
    uVar2 = CONCAT71((int7)(local_10 >> 8),4);
  }
  return uVar2;
}



===== AhciPortChannelStart @ 1c00089d8 =====

/* unsigned char __cdecl AhciPortChannelStart(struct _IDE_CHANNEL * __ptr64) */

uchar __cdecl AhciPortChannelStart(_IDE_CHANNEL *param_1)

{
  longlong lVar1;
  byte *pbVar2;
  ulonglong uVar3;
  undefined8 in_RDX;
  undefined8 in_R8;
  ulonglong in_R9;
  
  lVar1 = *(longlong *)param_1;
  uVar3 = AhciChannelStart((longlong *)(param_1 + 0x98),in_RDX,in_R8,in_R9);
  *(undefined4 *)(param_1 + 0x8c) = 0;
  param_1[0x90] = SUB81(uVar3,0);
  if (param_1[0xbb] != (_IDE_CHANNEL)0x0) {
    pbVar2 = (byte *)(lVar1 + 0x3c4 + ((longlong)(int)*(uint *)(param_1 + 0xc) >> 3));
    *pbVar2 = *pbVar2 | '\x01' << (*(uint *)(param_1 + 0xc) & 7);
  }
  pbVar2 = (byte *)(lVar1 + 0x3c8 + ((longlong)(int)*(uint *)(param_1 + 0xc) >> 3));
  *pbVar2 = *pbVar2 | '\x01' << (*(uint *)(param_1 + 0xc) & 7);
  return (uchar)SUB81(uVar3,0);
}



===== AhciPortChannelStop @ 1c0008a30 =====

/* void __cdecl AhciPortChannelStop(struct _IDE_CHANNEL * __ptr64) */

void __cdecl AhciPortChannelStop(_IDE_CHANNEL *param_1)

{
  *(undefined4 *)(*(longlong *)(param_1 + 0x1988) + 0x14) = 0;
  LOCK();
  UNLOCK();
  StartStopDMAs((longlong *)(param_1 + 0x98),0);
  **(undefined4 **)(param_1 + 0x1988) = 0;
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)(param_1 + 0x1988) + 4) = 0;
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)(param_1 + 0x1988) + 8) = 0;
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)(param_1 + 0x1988) + 0xc) = 0;
  LOCK();
  UNLOCK();
  *(uint *)(param_1 + 0xa8) = *(uint *)(param_1 + 0xa8) & 0xfffffffe;
  *(undefined8 *)(param_1 + 0x19b0) = 0;
  *(undefined8 *)(param_1 + 0x1998) = 0;
  *(undefined8 *)(param_1 + 0x1ab8) = 0;
  *(undefined8 *)(param_1 + 0x19a0) = 0;
  param_1[0x90] = (_IDE_CHANNEL)0x0;
  return;
}



===== FormatAtaId @ 1c0008ad4 =====

/* void __cdecl FormatAtaId(unsigned char * __ptr64,unsigned char * __ptr64,unsigned long) */

void __cdecl FormatAtaId(uchar *param_1,uchar *param_2,ulong param_3)

{
  byte bVar1;
  uchar uVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  uint uVar9;
  
  bVar3 = false;
  uVar8 = 0;
  *param_1 = '\0';
  if (param_3 != 0) {
    lVar6 = (longlong)param_1 - (longlong)param_2;
    uVar8 = (ulonglong)param_3;
    uVar7 = (ulonglong)param_3;
    do {
      if (bVar3) {
LAB_1c0008b04:
        param_2[lVar6] = 0x20;
      }
      else {
        bVar1 = *param_2;
        if (bVar1 == 0) {
          bVar3 = true;
          goto LAB_1c0008b04;
        }
        if (((bVar1 < 0x21) || (0x7f < bVar1)) || (bVar1 == 0x2c)) goto LAB_1c0008b04;
        param_2[lVar6] = bVar1;
      }
      param_2 = param_2 + 1;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  param_1[uVar8] = '\0';
  if (param_3 != 0) {
    uVar8 = 0;
    if (param_3 != 1) {
      do {
        uVar2 = param_1[uVar8];
        uVar4 = (int)uVar8 + 1;
        param_1[uVar8] = param_1[uVar4];
        uVar9 = (int)uVar8 + 2;
        uVar8 = (ulonglong)uVar9;
        param_1[uVar4] = uVar2;
      } while (uVar9 < param_3 - 1);
    }
  }
  if (1 < param_3 + 1) {
    param_1[param_3] = '\0';
    iVar5 = param_3 - 1;
    lVar6 = (longlong)iVar5;
    if (-1 < iVar5) {
      do {
        if (param_1[lVar6] != ' ') break;
        iVar5 = iVar5 + -1;
        lVar6 = lVar6 + -1;
      } while (-1 < lVar6);
    }
    param_1[(longlong)iVar5 + 1] = '\0';
  }
  return;
}



===== HwStorFindAdapter @ 1c0008ba0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* unsigned long __cdecl HwStorFindAdapter(void * __ptr64,void * __ptr64,void * __ptr64,char *
   __ptr64,struct _PORT_CONFIGURATION_INFORMATION * __ptr64,unsigned char * __ptr64) */

ulong __cdecl
HwStorFindAdapter(void *param_1,void *param_2,void *param_3,char *param_4,
                 _PORT_CONFIGURATION_INFORMATION *param_5,uchar *param_6)

{
  undefined8 *puVar1;
  ushort uVar2;
  undefined4 *puVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  _PORT_CONFIGURATION_INFORMATION _Var10;
  uint uVar11;
  ulong uVar12;
  uint *puVar13;
  ulonglong uVar14;
  longlong lVar15;
  char cVar16;
  byte bVar17;
  char *pcVar18;
  int iVar19;
  longlong *plVar20;
  char cVar21;
  uint uVar22;
  byte bVar23;
  uint uVar24;
  bool bVar25;
  undefined1 auStack_138 [32];
  uint *local_118;
  uint *local_110;
  undefined4 local_108;
  uint local_f8;
  int local_f4;
  uint local_f0;
  ulong local_ec;
  uint local_e8 [2];
  _PORT_CONFIGURATION_INFORMATION *local_e0;
  undefined4 local_d8;
  undefined8 local_d4;
  undefined4 local_c8;
  undefined1 local_c4 [128];
  uint local_44;
  int local_38 [2];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_138;
  uVar12 = 1;
  local_e0 = param_5;
  local_ec = 1;
  StorPortQuerySystemTime((longlong)param_1 + 400);
  if (param_4 == (char *)0x0) {
LAB_1c0008c95:
    uVar22 = 0;
  }
  else {
    pcVar18 = "ntldr=1";
    cVar16 = 'n';
    do {
      cVar21 = (param_4 + -0x1c000f6c0)[(longlong)pcVar18];
      if ((byte)(cVar16 + 0xbfU) < 0x1a) {
        cVar16 = cVar16 + ' ';
      }
      if ((byte)(cVar21 + 0xbfU) < 0x1a) {
        cVar21 = cVar21 + ' ';
      }
      if (cVar16 != cVar21) {
        pcVar18 = "dump=1";
        cVar16 = 'd';
        goto LAB_1c0008c63;
      }
      pcVar18 = pcVar18 + 1;
      cVar16 = *pcVar18;
    } while (cVar16 != '\0');
    uVar22 = 2;
  }
  goto LAB_1c0008c98;
LAB_1c0008c63:
  do {
    cVar21 = (param_4 + -0x1c000f6d0)[(longlong)pcVar18];
    if ((byte)(cVar16 + 0xbfU) < 0x1a) {
      cVar16 = cVar16 + ' ';
    }
    if ((byte)(cVar21 + 0xbfU) < 0x1a) {
      cVar21 = cVar21 + ' ';
    }
    if (cVar16 != cVar21) goto LAB_1c0008c95;
    pcVar18 = pcVar18 + 1;
    cVar16 = *pcVar18;
  } while (cVar16 != '\0');
  uVar22 = 4;
LAB_1c0008c98:
  *(uint *)((longlong)param_1 + 0x18) = uVar22;
  if (uVar22 >> 2 == 0) {
    local_f8 = 0x100;
    puVar13 = (uint *)StorPortAllocateRegistryBuffer(param_1,&local_f8);
    if (puVar13 == (uint *)0x0) goto LAB_1c0009b91;
    if (0xff < local_f8) {
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,Param1,0,4);
      if (((cVar16 != '\0') && (local_f8 == 4)) && (*puVar13 != 0xffffffff)) {
        *puVar13 = *puVar13 + 1;
      }
      local_110 = (uint *)CONCAT44(local_110._4_4_,4);
      local_118 = puVar13;
      StorPortRegistryWrite(param_1,Param1,0,4);
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,Param2,1,4);
      if (((cVar16 == '\0') || (local_f8 != 4)) ||
         (_AmdSataFua = *puVar13, _AmdSataFua == 0xffffffff)) {
        _AmdSataFua = 0;
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,Param3,1,4);
      if (((cVar16 == '\0') || (local_f8 != 4)) || (uVar22 = *puVar13, uVar22 == 0xffffffff)) {
        uVar22 = 0;
      }
      AmdSataChunk = uVar22 & 0x3ff000;
      local_f8 = 4;
      local_110 = &local_f8;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,Param4,1,4);
      if (((cVar16 == '\0') || (local_f8 != 4)) ||
         (AmdSataHIPM = *puVar13, AmdSataHIPM == 0xffffffff)) {
        AmdSataHIPM = 0xffffffff;
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,Param5,1,4);
      if (((cVar16 == '\0') || (local_f8 != 4)) ||
         (AmdSataDIPM = *puVar13, AmdSataDIPM == 0xffffffff)) {
        AmdSataDIPM = 0xffffffff;
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,Param6,1,4);
      if (((cVar16 == '\0') || (local_f8 != 4)) || (hhdd = *puVar13, hhdd == 0xffffffff)) {
        hhdd = 1;
      }
      local_110 = &local_f8;
      local_f8 = 4;
      AmdSataHhdd = hhdd;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,Param7,1,4);
      if (((cVar16 == '\0') || (local_f8 != 4)) || (AmdSataWMI = *puVar13, AmdSataWMI == 0xffffffff)
         ) {
        AmdSataWMI = 0;
      }
      local_110 = &local_f8;
      local_f8 = 4;
      wmi = AmdSataWMI;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,Param8,1,4);
      if (((cVar16 == '\0') || (local_f8 != 4)) ||
         (AmdSataQueueDepth = *puVar13, AmdSataQueueDepth == 0xffffffff)) {
        AmdSataQueueDepth = 0x20;
      }
      else if (0x20 < AmdSataQueueDepth) {
        AmdSataQueueDepth = 0x20;
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,Param9,1,4);
      if (((cVar16 == '\0') || (local_f8 != 4)) ||
         (AmdSataNumberOfSlots = *puVar13, AmdSataNumberOfSlots == 0xffffffff)) {
        AmdSataNumberOfSlots = 0x20;
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,ParamA,1,4);
      if (((cVar16 == '\0') || (local_f8 != 4)) ||
         (AmdSataNCQDisabled = *puVar13, AmdSataNCQDisabled == 0xffffffff)) {
        AmdSataNCQDisabled = 0;
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,ParamB,1,4);
      if (((cVar16 == '\0') || (local_f8 != 4)) ||
         (AmdSataPMDisabled = *puVar13, AmdSataPMDisabled == 0xffffffff)) {
        AmdSataPMDisabled = 0;
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,ParamC,1,4);
      if (((cVar16 == '\0') || (local_f8 != 4)) ||
         (AmdSataHalfDuplex = *puVar13, AmdSataHalfDuplex == 0xffffffff)) {
        AmdSataHalfDuplex = 0;
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,ParamE,1,4);
      if (((cVar16 == '\0') || (local_f8 != 4)) ||
         (AmdSataFBSDisabled = *puVar13, AmdSataFBSDisabled == 0xffffffff)) {
        AmdSataFBSDisabled = 0;
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,ParamH,1,4);
      if (((cVar16 == '\0') || (local_f8 != 4)) ||
         (AmdSataANDisabled = *puVar13, AmdSataANDisabled == 0xffffffff)) {
        AmdSataANDisabled = 0;
      }
      local_110 = &local_f8;
      local_f8 = 0x10;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,ParamI,1,3);
      if ((cVar16 == '\0') || (local_f8 != 0x10)) {
        _AmdSataDeviceFpdmaDisable = 0;
        _DAT_1c00114e8 = 0;
      }
      else {
        _AmdSataDeviceFpdmaDisable = *(undefined8 *)puVar13;
        _DAT_1c00114e8 = *(undefined8 *)(puVar13 + 2);
      }
      local_110 = &local_f8;
      local_f8 = 0x10;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,ParamQ,1,3);
      if ((cVar16 == '\0') || (local_f8 != 0x10)) {
        _AmdSataDevicePio = 0;
        _DAT_1c0011518 = 0;
      }
      else {
        _AmdSataDevicePio = *(undefined8 *)puVar13;
        _DAT_1c0011518 = *(undefined8 *)(puVar13 + 2);
      }
      local_110 = &local_f8;
      local_f8 = 0x10;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,ParamR,1,3);
      if ((cVar16 == '\0') || (local_f8 != 0x10)) {
        _AmdSataDevicePioMultiple = 0;
        _DAT_1c0011490 = 0;
      }
      else {
        _AmdSataDevicePioMultiple = *(undefined8 *)puVar13;
        _DAT_1c0011490 = *(undefined8 *)(puVar13 + 2);
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,ParamJ,1,4);
      if (((cVar16 == '\0') || (local_f8 != 4)) ||
         (AmdSataChannelSpd = *puVar13, AmdSataChannelSpd == 0xffffffff)) {
        AmdSataChannelSpd = 0;
      }
      local_110 = &local_f8;
      local_f8 = 0x20;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,ParamK,1,3);
      if ((cVar16 == '\0') || (local_f8 != 0x20)) {
        _AmdSataDeviceSpd = 0;
        _DAT_1c00114c8 = 0;
        _DAT_1c00114d0 = 0;
        _DAT_1c00114d8 = 0;
      }
      else {
        _AmdSataDeviceSpd = *(undefined8 *)puVar13;
        _DAT_1c00114c8 = *(undefined8 *)(puVar13 + 2);
        _DAT_1c00114d0 = *(undefined8 *)(puVar13 + 4);
        _DAT_1c00114d8 = *(undefined8 *)(puVar13 + 6);
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,ParamS,1,4);
      if (((cVar16 == '\0') || (local_f8 != 4)) ||
         (AmdSataExternal = *puVar13, AmdSataExternal == 0xffffffff)) {
        AmdSataExternal = 0;
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,ParamV,1,4);
      if (((cVar16 == '\0') || (local_f8 != 4)) ||
         (AmdSataInternal = *puVar13, AmdSataInternal == 0xffffffff)) {
        AmdSataInternal = 0;
      }
      local_f8 = 4;
      AmdSataExternal = AmdSataExternal & ~AmdSataInternal;
      local_110 = &local_f8;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,ParamL,1,4);
      if (((cVar16 == '\0') || (local_f8 != 4)) || (AmdSataCCC = *puVar13, AmdSataCCC == 0xffffffff)
         ) {
        AmdSataCCC = 0;
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,ParamM,1,4);
      if (((cVar16 == '\0') || (local_f8 != 4)) ||
         (AmdSataCCCTV = *puVar13, AmdSataCCCTV == 0xffffffff)) {
LAB_1c00094a1:
        AmdSataCCCTV = 1;
      }
      else if (0xfffe < AmdSataCCCTV - 1) {
        AmdSataCCC = 0;
        goto LAB_1c00094a1;
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,ParamN,1,4);
      if (((cVar16 == '\0') || (local_f8 != 4)) ||
         (AmdSataCCCCC = *puVar13, AmdSataCCCCC == 0xffffffff)) {
        AmdSataCCCCC = 1;
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,ParamO,1,4);
      if (((cVar16 == '\0') || (local_f8 != 4)) ||
         (AmdSataCCCODD = *puVar13, AmdSataCCCODD == 0xffffffff)) {
        AmdSataCCCODD = 0;
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,ParamP,1,4);
      if (((cVar16 == '\0') || (local_f8 != 4)) ||
         (AmdSataCCCPM = *puVar13, AmdSataCCCPM == 0xffffffff)) {
        AmdSataCCCPM = 0;
      }
      if ((AmdSataCCCTV == 1) && (AmdSataCCCCC == 1)) {
        AmdSataCCC = 0;
      }
      if (AmdSataCCC == 0) {
LAB_1c00095d2:
        AmdSataCCCTV = 1;
        AmdSataCCCCC = 1;
        AmdSataCCC = 0;
      }
      else {
        if ((1 < AmdSataCCCTV) && (AmdSataCCCCC == 1)) {
          AmdSataCCCCC = 0;
        }
        if ((0xff < AmdSataCCCCC) || (0xfffe < AmdSataCCCTV - 1)) goto LAB_1c00095d2;
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,ParamT,1,4);
      if (((cVar16 != '\0') && (local_f8 == 4)) && (*puVar13 != 0xffffffff)) {
        AmdSataReDPC = *puVar13;
      }
      local_110 = &local_f8;
      local_f8 = 4;
      redpc = AmdSataReDPC;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,ParamU,1,4);
      if (((cVar16 != '\0') && (local_f8 == 4)) && (*puVar13 != 0xffffffff)) {
        AmdSataDLAD = *puVar13;
      }
      local_110 = &local_f8;
      local_f8 = 4;
      dlad = AmdSataDLAD;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,ParamX,1,4);
      if (((cVar16 != '\0') && (local_f8 == 4)) && (*puVar13 != 0xffffffff)) {
        AmdSataGpioCfg1 = *puVar13;
      }
      local_110 = &local_f8;
      local_f8 = 4;
      GpioCfg1 = AmdSataGpioCfg1;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,Param12,1,4);
      if ((cVar16 != '\0') && (local_f8 == 4)) {
        uVar22 = *puVar13;
        if ((uVar22 != 0xffffffff) && (uVar22 != 0)) {
          AmdSataDET1 = uVar22;
        }
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,Param10,1,4);
      if ((cVar16 != '\0') && (local_f8 == 4)) {
        uVar22 = *puVar13;
        if ((uVar22 != 0xffffffff) && (uVar22 != 0)) {
          AmdSataDET3 = uVar22;
        }
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,Param13,1,4);
      if ((cVar16 != '\0') && (local_f8 == 4)) {
        uVar22 = *puVar13;
        if ((uVar22 != 0xffffffff) && (uVar22 != 0)) {
          AmdSataWatchBusy = uVar22;
        }
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,Param14,1,4);
      if ((((cVar16 != '\0') && (local_f8 == 4)) && (uVar22 = *puVar13, uVar22 != 0xffffffff)) &&
         (AmdSataSgl = uVar22 & ~(uVar22 - 1), 0x3ff < AmdSataSgl - 1)) {
        AmdSataSgl = 0x20;
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,Param15,1,4);
      if ((cVar16 != '\0') && (local_f8 == 4)) {
        if (*puVar13 != 0xffffffff) {
          _AmdSataSWSP = *puVar13;
        }
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,Param16,1,4);
      if ((cVar16 != '\0') && (local_f8 == 4)) {
        if (*puVar13 != 0xffffffff) {
          AmdSataPnp = *puVar13;
        }
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,Param17,1,4);
      if ((cVar16 != '\0') && (local_f8 == 4)) {
        if (*puVar13 != 0xffffffff) {
          _AmdSataShafran = *puVar13;
        }
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,Param18,1,4);
      if ((cVar16 != '\0') && (local_f8 == 4)) {
        if (*puVar13 != 0xffffffff) {
          _AmdSataSI = *puVar13;
        }
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,Param19,1,4);
      if ((cVar16 != '\0') && (local_f8 == 4)) {
        if (*puVar13 != 0xffffffff) {
          AmdSataPI = *puVar13;
        }
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,Param1C,1,4);
      if ((cVar16 != '\0') && (local_f8 == 4)) {
        if (*puVar13 != 0xffffffff) {
          _AmdSataCOMRESET = *puVar13;
        }
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,Param1D,1,4);
      if (((cVar16 != '\0') && (local_f8 == 4)) && (*puVar13 != 0xffffffff)) {
        AmdSataWaitPmSign = *puVar13;
      }
      if (0x1d < AmdSataWaitPmSign - 1) {
        AmdSataWaitPmSign = 0x1e;
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,Param1F,1,4);
      if (((cVar16 != '\0') && (local_f8 == 4)) && (*puVar13 != 0xffffffff)) {
        AmdSataWaitSign = *puVar13;
      }
      if (0x1d < AmdSataWaitSign - 1) {
        AmdSataWaitSign = 1;
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,Param20,1,4);
      if ((cVar16 != '\0') && (local_f8 == 4)) {
        if (*puVar13 != 0xffffffff) {
          AmdSataAcpiIde = *puVar13;
        }
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,Param21,1,4);
      if ((cVar16 != '\0') && (local_f8 == 4)) {
        if (*puVar13 != 0xffffffff) {
          AmdSataResetFis1 = *puVar13;
        }
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,Param22,1,4);
      if ((cVar16 != '\0') && (local_f8 == 4)) {
        if (*puVar13 != 0xffffffff) {
          _AmdSataResetFis2 = *puVar13;
        }
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,Param23,1,4);
      if ((cVar16 != '\0') && (local_f8 == 4)) {
        uVar22 = *puVar13;
        if (uVar22 != 0xffffffff) {
          if (0x3fff < uVar22) {
            uVar22 = 0x3fff;
          }
          AmdSataDevSlp = uVar22;
        }
      }
      local_110 = &local_f8;
      local_f8 = 4;
      local_118 = puVar13;
      cVar16 = StorPortRegistryRead(param_1,Param24,1,4);
      if (((cVar16 != '\0') && (local_f8 == 4)) && (*puVar13 != 0xffffffff)) {
        AmdSataHints = *puVar13 != 0;
      }
    }
    StorPortFreeRegistryBuffer(param_1,puVar13);
LAB_1c0009b91:
    local_118 = (uint *)&local_f4;
    local_110._0_4_ = 4;
    local_f4 = 0;
    StorPortGetBusData(param_1,4,*(undefined4 *)(param_5 + 4),*(undefined4 *)(param_5 + 100));
    local_d4 = 0;
    local_118 = &local_d8;
    local_110._0_4_ = 0xc;
    local_d8 = 0;
    StorPortGetBusData(param_1,4,*(undefined4 *)((longlong)param_1 + 0x24),
                       *(undefined4 *)((longlong)param_1 + 0x84));
    if ((local_d4._4_1_ - 0x39 & 0xffffffef) == 0) {
      local_c8 = 0;
      memset(local_c4,0,0x84);
      local_118 = &local_c8;
      local_110._0_4_ = 0x88;
      StorPortGetBusData(param_1,4,*(undefined4 *)(param_5 + 4),*(undefined4 *)(param_5 + 100));
      local_108 = 4;
      LOCK();
      g_lPHYClock = local_44 | 0x40000000;
      UNLOCK();
      local_110._0_4_ = 0x84;
      local_118 = &g_lPHYClock;
      StorPortSetBusDataByOffset
                (param_1,4,*(undefined4 *)(param_5 + 4),*(undefined4 *)(param_5 + 100));
      g_bIsKernCZBP = '\x01';
    }
    uVar9 = *(undefined8 *)(param_5 + 8);
    puVar1 = (undefined8 *)((longlong)param_1 + 0x20);
    *puVar1 = *(undefined8 *)param_5;
    *(undefined8 *)((longlong)param_1 + 0x28) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x18);
    *(undefined8 *)((longlong)param_1 + 0x30) = *(undefined8 *)(param_5 + 0x10);
    *(undefined8 *)((longlong)param_1 + 0x38) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x28);
    *(undefined8 *)((longlong)param_1 + 0x40) = *(undefined8 *)(param_5 + 0x20);
    *(undefined8 *)((longlong)param_1 + 0x48) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x38);
    *(undefined8 *)((longlong)param_1 + 0x50) = *(undefined8 *)(param_5 + 0x30);
    *(undefined8 *)((longlong)param_1 + 0x58) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x48);
    *(undefined8 *)((longlong)param_1 + 0x60) = *(undefined8 *)(param_5 + 0x40);
    *(undefined8 *)((longlong)param_1 + 0x68) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x58);
    *(undefined8 *)((longlong)param_1 + 0x70) = *(undefined8 *)(param_5 + 0x50);
    *(undefined8 *)((longlong)param_1 + 0x78) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x68);
    *(undefined8 *)((longlong)param_1 + 0x80) = *(undefined8 *)(param_5 + 0x60);
    *(undefined8 *)((longlong)param_1 + 0x88) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x78);
    *(undefined8 *)((longlong)param_1 + 0x90) = *(undefined8 *)(param_5 + 0x70);
    *(undefined8 *)((longlong)param_1 + 0x98) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x88);
    *(undefined8 *)((longlong)param_1 + 0xa0) = *(undefined8 *)(param_5 + 0x80);
    *(undefined8 *)((longlong)param_1 + 0xa8) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x98);
    *(undefined8 *)((longlong)param_1 + 0xb0) = *(undefined8 *)(param_5 + 0x90);
    *(undefined8 *)((longlong)param_1 + 0xb8) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0xa8);
    *(undefined8 *)((longlong)param_1 + 0xc0) = *(undefined8 *)(param_5 + 0xa0);
    *(undefined8 *)((longlong)param_1 + 200) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0xb8);
    *(undefined8 *)((longlong)param_1 + 0xd0) = *(undefined8 *)(param_5 + 0xb0);
    *(undefined8 *)((longlong)param_1 + 0xd8) = uVar9;
    uVar5 = *(undefined4 *)(param_5 + 0xc4);
    uVar6 = *(undefined4 *)(param_5 + 200);
    uVar7 = *(undefined4 *)(param_5 + 0xcc);
    *(undefined4 *)((longlong)param_1 + 0xe0) = *(undefined4 *)(param_5 + 0xc0);
    *(undefined4 *)((longlong)param_1 + 0xe4) = uVar5;
    *(undefined4 *)((longlong)param_1 + 0xe8) = uVar6;
    *(undefined4 *)((longlong)param_1 + 0xec) = uVar7;
    uVar5 = *(undefined4 *)(param_5 + 0xd0);
    uVar6 = *(undefined4 *)(param_5 + 0xd4);
    uVar7 = *(undefined4 *)(param_5 + 0xd8);
    uVar8 = *(undefined4 *)(param_5 + 0xdc);
    *(undefined4 *)((longlong)param_1 + 0x188) = 2;
    *(longlong *)((longlong)param_1 + 0x228) = (longlong)param_1 + 0xe028;
    *(undefined4 *)((longlong)param_1 + 0xf0) = uVar5;
    *(undefined4 *)((longlong)param_1 + 0xf4) = uVar6;
    *(undefined4 *)((longlong)param_1 + 0xf8) = uVar7;
    *(undefined4 *)((longlong)param_1 + 0xfc) = uVar8;
    if (*(longlong *)((longlong)param_1 + 0x350) != 0) {
      StorPortFreeDeviceBase(param_1);
    }
    *(undefined8 *)((longlong)param_1 + 0x350) = 0;
    *(short *)((longlong)param_1 + 0x230) = 0x20;
    *(undefined1 *)((longlong)param_1 + 0x232) = 8;
    *(undefined4 **)((longlong)param_1 + 0x248) = (undefined4 *)((longlong)param_1 + 0x250);
    uVar14 = 0;
    *(uint *)((longlong)param_1 + 0x234) =
         (uint)((*(uint *)((longlong)param_1 + 0x18) >> 2 & 1) != 0);
    *(longlong *)((longlong)param_1 + 600) = (longlong)param_1 + 0x260;
    if (*(int *)(param_5 + 0x34) != 0) {
      do {
        *(undefined8 *)(*(longlong *)((longlong)param_1 + 600) + 8 + uVar14 * 0x18) =
             *(undefined8 *)(*(longlong *)(param_5 + 0x38) + uVar14 * 0x10);
        *(undefined8 *)(*(longlong *)((longlong)param_1 + 600) + uVar14 * 0x18) =
             *(undefined8 *)(*(longlong *)(param_5 + 0x38) + uVar14 * 0x10);
        *(undefined4 *)(*(longlong *)((longlong)param_1 + 600) + 0x10 + uVar14 * 0x18) =
             *(undefined4 *)(*(longlong *)(param_5 + 0x38) + 8 + uVar14 * 0x10);
        *(undefined1 *)(*(longlong *)((longlong)param_1 + 600) + 0x14 + uVar14 * 0x18) =
             *(undefined1 *)(*(longlong *)(param_5 + 0x38) + 0xc + uVar14 * 0x10);
        *(char *)(*(longlong *)((longlong)param_1 + 600) + 0x15 + uVar14 * 0x18) = (char)uVar14;
        uVar22 = (int)uVar14 + 1;
        uVar14 = (ulonglong)uVar22;
      } while (uVar22 < *(uint *)(param_5 + 0x34));
    }
    *(undefined4 *)((longlong)param_1 + 0x250) = *(undefined4 *)(param_5 + 0x34);
    puVar3 = *(undefined4 **)((longlong)param_1 + 0x228);
    puVar3[4] = local_f4;
    *(bool *)((longlong)puVar3 + 0xa3) = (*(uint *)((longlong)param_1 + 0x18) >> 2 & 1) != 0;
    *(undefined1 *)(puVar3 + 0x29) = AmdSataHints;
    puVar3[0xd] = AmdSataCCC;
    puVar3[0xf] = AmdSataCCCODD;
    puVar3[0x10] = AmdSataCCCPM;
    *(short *)((longlong)puVar3 + 0x4a) = (short)AmdSataCCCTV;
    *(undefined1 *)((longlong)puVar3 + 0x49) = (undefined1)AmdSataCCCCC;
    uVar14 = AhciAdapterStart(puVar3,(short *)((longlong)param_1 + 0x230));
    if (((char)uVar14 == '\0') || (*(char *)((longlong)param_1 + 0x232) == '\0')) {
      uVar12 = 2;
      local_ec = 2;
    }
    if ((AmdSataPI == 0) ||
       (_Var10 = *(_PORT_CONFIGURATION_INFORMATION *)((longlong)param_1 + 0x232), 8 < (byte)_Var10))
    {
      _Var10 = (_PORT_CONFIGURATION_INFORMATION)0x8;
    }
    bVar25 = AmdSataChunk == 0;
    *(_PORT_CONFIGURATION_INFORMATION *)((longlong)param_1 + 0x1c) = _Var10;
    *(undefined2 *)((longlong)param_1 + 0x1d) = 0x10f;
    param_5[0x48] = _Var10;
    param_5[0x61] = *(_PORT_CONFIGURATION_INFORMATION *)((longlong)param_1 + 0x1d);
    param_5[0x92] = *(_PORT_CONFIGURATION_INFORMATION *)((longlong)param_1 + 0x1e);
    *(undefined2 *)(param_5 + 0x51) = 0x101;
    param_5[0x53] = (_PORT_CONFIGURATION_INFORMATION)0x1;
    uVar22 = *(uint *)((longlong)param_1 + 0x23c);
    *(uint *)(param_5 + 0x18) = uVar22;
    if ((bVar25) && (AmdSataChunk = 0x10000, local_f4 != 0x43801002)) {
      AmdSataChunk = uVar22;
    }
    MSISingle = 0;
    *(int *)(param_5 + 0x1c) = *(int *)((longlong)param_1 + 0x238) + 1;
    param_5[0x90] = *(_PORT_CONFIGURATION_INFORMATION *)((longlong)param_1 + 0x242);
    param_5[0x93] = wmi._0_1_;
    *(code **)(param_5 + 0x98) = HwMSInterruptRoutine;
    *(undefined4 *)(param_5 + 0x28) = 2;
    *(undefined4 *)(param_5 + 0x30) = 1;
    *(undefined4 *)(param_5 + 0xc0) = 0x10000;
    iVar19 = puVar3[0xd];
    *(undefined4 *)(param_5 + 200) = 1;
    *(undefined4 *)(param_5 + 0xd8) = 0;
    *(uint *)(param_5 + 0xa0) = 2 - (uint)(iVar19 != 0);
    MSIEnabled = (ulong)(*(int *)(param_5 + 0x14) == 1);
    *(uint *)(param_5 + 0x94) = (uint)(AmdSataHalfDuplex == 0);
    *(undefined4 *)((longlong)param_1 + 0x220) = 0;
    uVar9 = *(undefined8 *)(param_5 + 8);
    *puVar1 = *(undefined8 *)param_5;
    *(undefined8 *)((longlong)param_1 + 0x28) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x18);
    *(undefined8 *)((longlong)param_1 + 0x30) = *(undefined8 *)(param_5 + 0x10);
    *(undefined8 *)((longlong)param_1 + 0x38) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x28);
    *(undefined8 *)((longlong)param_1 + 0x40) = *(undefined8 *)(param_5 + 0x20);
    *(undefined8 *)((longlong)param_1 + 0x48) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x38);
    *(undefined8 *)((longlong)param_1 + 0x50) = *(undefined8 *)(param_5 + 0x30);
    *(undefined8 *)((longlong)param_1 + 0x58) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x48);
    *(undefined8 *)((longlong)param_1 + 0x60) = *(undefined8 *)(param_5 + 0x40);
    *(undefined8 *)((longlong)param_1 + 0x68) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x58);
    *(undefined8 *)((longlong)param_1 + 0x70) = *(undefined8 *)(param_5 + 0x50);
    *(undefined8 *)((longlong)param_1 + 0x78) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x68);
    *(undefined8 *)((longlong)param_1 + 0x80) = *(undefined8 *)(param_5 + 0x60);
    *(undefined8 *)((longlong)param_1 + 0x88) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x78);
    *(undefined8 *)((longlong)param_1 + 0x90) = *(undefined8 *)(param_5 + 0x70);
    *(undefined8 *)((longlong)param_1 + 0x98) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x88);
    *(undefined8 *)((longlong)param_1 + 0xa0) = *(undefined8 *)(param_5 + 0x80);
    *(undefined8 *)((longlong)param_1 + 0xa8) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x98);
    *(undefined8 *)((longlong)param_1 + 0xb0) = *(undefined8 *)(param_5 + 0x90);
    *(undefined8 *)((longlong)param_1 + 0xb8) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0xa8);
    *(undefined8 *)((longlong)param_1 + 0xc0) = *(undefined8 *)(param_5 + 0xa0);
    *(undefined8 *)((longlong)param_1 + 200) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0xb8);
    *(undefined8 *)((longlong)param_1 + 0xd0) = *(undefined8 *)(param_5 + 0xb0);
    *(undefined8 *)((longlong)param_1 + 0xd8) = uVar9;
    uVar5 = *(undefined4 *)(param_5 + 0xc4);
    uVar6 = *(undefined4 *)(param_5 + 200);
    uVar7 = *(undefined4 *)(param_5 + 0xcc);
    *(undefined4 *)((longlong)param_1 + 0xe0) = *(undefined4 *)(param_5 + 0xc0);
    *(undefined4 *)((longlong)param_1 + 0xe4) = uVar5;
    *(undefined4 *)((longlong)param_1 + 0xe8) = uVar6;
    *(undefined4 *)((longlong)param_1 + 0xec) = uVar7;
    uVar5 = *(undefined4 *)(param_5 + 0xd4);
    uVar6 = *(undefined4 *)(param_5 + 0xd8);
    uVar7 = *(undefined4 *)(param_5 + 0xdc);
    *(undefined4 *)((longlong)param_1 + 0xf0) = *(undefined4 *)(param_5 + 0xd0);
    *(undefined4 *)((longlong)param_1 + 0xf4) = uVar5;
    *(undefined4 *)((longlong)param_1 + 0xf8) = uVar6;
    *(undefined4 *)((longlong)param_1 + 0xfc) = uVar7;
    if ((*(uint *)((longlong)param_1 + 0x18) >> 2 & 1) == 0) {
      StorPortNotification(0x1001,param_1,(longlong)param_1 + 0x370);
    }
    if (uVar12 == 1) {
      uVar22 = ((uint)puVar3[9] >> 8 & 0x1f) + 1;
      if (*(longlong *)((longlong)param_1 + 0x358) == 0) {
        uVar11 = 1;
        uVar24 = ((-(uint)(*(char *)((longlong)puVar3 + 0x5e) != '\0') & 0xf) + 1) * 0x100 +
                 (AmdSataSgl * 0x10 + 0x10f & 0xffffff80) * uVar22 + 0x15ff & 0xfffff000;
        if ((*(uint *)((longlong)param_1 + 0x18) >> 2 & 1) == 0) {
          uVar11 = (uint)*(byte *)((longlong)param_1 + 0x1c);
        }
        iVar19 = uVar24 * uVar11;
        lVar15 = StorPortGetUncachedExtension(param_1,puVar1,iVar19 + 0xfff);
        *(uint *)((longlong)param_1 + 0x360) = uVar24;
        *(int *)((longlong)param_1 + 0x364) = iVar19;
        *(ulonglong *)((longlong)param_1 + 0x358) = lVar15 + 0xfffU & 0xfffffffffffff000;
      }
      bVar23 = 0;
      if (*(char *)((longlong)param_1 + 0x1c) != '\0') {
        do {
          lVar15 = (ulonglong)bVar23 * 0x1b88;
          uVar14 = (ulonglong)bVar23;
          *(void **)(lVar15 + 1000 + (longlong)param_1) = param_1;
          *(uint *)(lVar15 + 0x3f4 + (longlong)param_1) = (uint)bVar23;
          *(undefined4 *)(lVar15 + 0x3f8 + (longlong)param_1) = 1;
          *(undefined4 *)(lVar15 + 0x3fc + (longlong)param_1) = 4;
          *(byte *)(lVar15 + 0x400 + (longlong)param_1) = bVar23;
          *(undefined2 *)(lVar15 + 0x401 + (longlong)param_1) = 0;
          *(undefined1 *)(lVar15 + 0x403 + (longlong)param_1) = 0;
          if ((*(uint *)((longlong)param_1 + 0x18) >> 2 & 1) == 0) {
            StorPortNotification(0x1001,param_1,(longlong)param_1 + lVar15 + 0x410);
          }
          plVar20 = (longlong *)(lVar15 + 0x480 + (longlong)param_1);
          memset(plVar20,0,0x1af0);
          bVar25 = AmdSataQueueDepth < uVar22;
          *(uint *)(plVar20 + 1) = (uint)bVar23;
          uVar11 = uVar22;
          if (bVar25) {
            uVar11 = AmdSataQueueDepth;
          }
          *(char *)((longlong)plVar20 + 0x19) = (char)uVar11;
          bVar17 = bVar23 * '\x02';
          *(uint *)(plVar20 + 5) = uVar22;
          uVar11 = (uint)bVar23;
          *(bool *)((longlong)plVar20 + 0x1c) =
               (*(byte *)((longlong)&AmdSataNCQDisabled + ((longlong)(int)uVar11 >> 3)) >>
                (uVar11 & 7) & 1) != 0;
          *(bool *)((longlong)plVar20 + 0x1d) =
               (*(byte *)((longlong)&AmdSataPMDisabled + ((longlong)(int)uVar11 >> 3)) >>
                (uVar11 & 7) & 1) != 0;
          *(bool *)((longlong)plVar20 + 0x1e) =
               (*(byte *)((longlong)&AmdSataFBSDisabled + ((longlong)(int)uVar11 >> 3)) >>
                (uVar11 & 7) & 1) == 0;
          *(bool *)((longlong)plVar20 + 0x2e) =
               (*(byte *)((longlong)&AmdSataANDisabled + ((longlong)(int)uVar11 >> 3)) >>
                (uVar11 & 7) & 1) != 0;
          *(bool *)((longlong)plVar20 + 0x23) =
               (*(byte *)((longlong)&AmdSataExternal + ((longlong)(int)(uint)bVar23 >> 3)) >>
                (bVar23 & 7) & 1) != 0;
          uVar11 = AmdSataHIPM >> (bVar17 & 0x1f);
          *(undefined1 *)((longlong)plVar20 + 0x32) = 0;
          *(byte *)(plVar20 + 6) = (byte)uVar11 & 3;
          *(byte *)((longlong)plVar20 + 0x31) = (byte)(AmdSataDIPM >> (bVar17 & 0x1f)) & 3;
          uVar2 = *(ushort *)(&AmdSataDevicePio + uVar14 * 2);
          *(uint *)((longlong)plVar20 + 0x1a5c) = (uint)uVar2;
          *(uint *)((longlong)plVar20 + 0x1a64) =
               (uint)(*(ushort *)(&AmdSataDeviceFpdmaDisable + uVar14 * 2) | uVar2);
          *(uint *)(plVar20 + 0x34c) = (uint)*(ushort *)(&AmdSataDevicePioMultiple + uVar14 * 2);
          *(byte *)((longlong)plVar20 + 0x2f) = (byte)(AmdSataChannelSpd >> (bVar17 & 0x1f)) & 3;
          *(undefined4 *)((longlong)plVar20 + 0x1a6c) =
               *(undefined4 *)(&AmdSataDeviceSpd + uVar14 * 4);
          lVar15 = *(longlong *)((longlong)param_1 + 0x228);
          lVar4 = *(longlong *)(lVar15 + 8);
          *(longlong **)(lVar15 + 0x60 + uVar14 * 8) = plVar20;
          *(uint *)(plVar20 + 2) = *(uint *)(plVar20 + 2) & 0xfffffffe;
          *plVar20 = lVar15;
          *(undefined4 *)(plVar20 + 799) = *(undefined4 *)(lVar15 + 0x24);
          *(undefined4 *)((longlong)plVar20 + 0x18fc) = *(undefined4 *)(lVar15 + 0x28);
          *(undefined8 *)((longlong)plVar20 + 0x124) = 0;
          *(undefined1 *)(plVar20 + 3) = 0;
          plVar20[0x31e] = ((ulonglong)*(uint *)(plVar20 + 1) + 2) * 0x80 + lVar4;
          plVar20[0x31d] = lVar4 + 8;
          lVar15 = 0x20;
          *(undefined4 *)((longlong)plVar20 + 300) = 0;
          plVar20 = plVar20 + 0x56;
          do {
            *plVar20 = 0;
            plVar20 = plVar20 + 7;
            lVar15 = lVar15 + -1;
          } while (lVar15 != 0);
          bVar23 = bVar23 + 1;
        } while (bVar23 < *(byte *)((longlong)param_1 + 0x1c));
        param_5 = local_e0;
      }
      uVar14 = 0;
      if (*(char *)((longlong)param_1 + 0x1c) != '\0') {
        do {
          uVar22 = (uint)uVar14;
          lVar15 = uVar14 * 0x1b88;
          if (*(int *)(lVar15 + 0x3f0 + (longlong)param_1) == 1) {
LAB_1c000a323:
            AhciPortChannelStart((_IDE_CHANNEL *)((longlong)param_1 + lVar15 + 1000));
          }
          else {
            local_f0 = *(uint *)(*(longlong *)(*(longlong *)((longlong)param_1 + 0x228) + 8) + 0xc);
            if (AmdSataPI != 0) {
              local_f0 = local_f0 & AmdSataPI;
            }
            uVar11 = (uint)((*(byte *)((longlong)local_e8 + ((longlong)(int)uVar22 >> 3) + -8) >>
                             (uVar22 & 7) & 1) != 0);
            *(uint *)(lVar15 + 0x3f0 + (longlong)param_1) = uVar11;
            if (uVar11 == 1) goto LAB_1c000a323;
          }
          uVar14 = (ulonglong)(uVar22 + 1);
        } while (uVar22 + 1 < (uint)*(byte *)((longlong)param_1 + 0x1c));
      }
      uVar12 = local_ec;
    }
    if ((*(uint *)((longlong)param_1 + 0x18) >> 2 & 1) == 0) {
      bVar25 = g_bIsKernCZBP != '\0';
      *(uint *)((longlong)param_1 + 0x3d0) = AmdSataPMDisabled;
      *(uint *)((longlong)param_1 + 0x3d4) = AmdSataChannelSpd;
      *(ulong *)((longlong)param_1 + 0x3d8) = AmdSataNCQDisabled;
      if (((bVar25) && (*(longlong *)((longlong)param_1 + 0x3e0) == 0)) &&
         (iVar19 = StorPortExtendedFunction(0x20,param_1), iVar19 != 0)) goto LAB_1c000a3a7;
    }
    _Boot = 0xff;
    local_118 = (uint *)((longlong)param_1 + 0x10);
    uVar9 = *(undefined8 *)(param_5 + 8);
    *puVar1 = *(undefined8 *)param_5;
    *(undefined8 *)((longlong)param_1 + 0x28) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x18);
    *(undefined8 *)((longlong)param_1 + 0x30) = *(undefined8 *)(param_5 + 0x10);
    *(undefined8 *)((longlong)param_1 + 0x38) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x28);
    *(undefined8 *)((longlong)param_1 + 0x40) = *(undefined8 *)(param_5 + 0x20);
    *(undefined8 *)((longlong)param_1 + 0x48) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x38);
    *(undefined8 *)((longlong)param_1 + 0x50) = *(undefined8 *)(param_5 + 0x30);
    *(undefined8 *)((longlong)param_1 + 0x58) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x48);
    *(undefined8 *)((longlong)param_1 + 0x60) = *(undefined8 *)(param_5 + 0x40);
    *(undefined8 *)((longlong)param_1 + 0x68) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x58);
    *(undefined8 *)((longlong)param_1 + 0x70) = *(undefined8 *)(param_5 + 0x50);
    *(undefined8 *)((longlong)param_1 + 0x78) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x68);
    *(undefined8 *)((longlong)param_1 + 0x80) = *(undefined8 *)(param_5 + 0x60);
    *(undefined8 *)((longlong)param_1 + 0x88) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x78);
    *(undefined8 *)((longlong)param_1 + 0x90) = *(undefined8 *)(param_5 + 0x70);
    *(undefined8 *)((longlong)param_1 + 0x98) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x88);
    *(undefined8 *)((longlong)param_1 + 0xa0) = *(undefined8 *)(param_5 + 0x80);
    *(undefined8 *)((longlong)param_1 + 0xa8) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0x98);
    *(undefined8 *)((longlong)param_1 + 0xb0) = *(undefined8 *)(param_5 + 0x90);
    *(undefined8 *)((longlong)param_1 + 0xb8) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0xa8);
    *(undefined8 *)((longlong)param_1 + 0xc0) = *(undefined8 *)(param_5 + 0xa0);
    *(undefined8 *)((longlong)param_1 + 200) = uVar9;
    uVar9 = *(undefined8 *)(param_5 + 0xb8);
    *(undefined8 *)((longlong)param_1 + 0xd0) = *(undefined8 *)(param_5 + 0xb0);
    *(undefined8 *)((longlong)param_1 + 0xd8) = uVar9;
    uVar5 = *(undefined4 *)(param_5 + 0xc4);
    uVar6 = *(undefined4 *)(param_5 + 200);
    uVar7 = *(undefined4 *)(param_5 + 0xcc);
    *(undefined4 *)((longlong)param_1 + 0xe0) = *(undefined4 *)(param_5 + 0xc0);
    *(undefined4 *)((longlong)param_1 + 0xe4) = uVar5;
    *(undefined4 *)((longlong)param_1 + 0xe8) = uVar6;
    *(undefined4 *)((longlong)param_1 + 0xec) = uVar7;
    uVar5 = *(undefined4 *)(param_5 + 0xd4);
    uVar6 = *(undefined4 *)(param_5 + 0xd8);
    uVar7 = *(undefined4 *)(param_5 + 0xdc);
    *(undefined4 *)((longlong)param_1 + 0xf0) = *(undefined4 *)(param_5 + 0xd0);
    *(undefined4 *)((longlong)param_1 + 0xf4) = uVar5;
    *(undefined4 *)((longlong)param_1 + 0xf8) = uVar6;
    *(undefined4 *)((longlong)param_1 + 0xfc) = uVar7;
    StorPortExtendedFunction(8,param_1,&AdapterDeviceObject,(longlong)param_1 + 8);
    *(undefined4 *)((longlong)param_1 + 0x100) = 4;
    *(undefined ***)((longlong)param_1 + 0x108) = &AmdFdoWmiGuidList;
    *(code **)((longlong)param_1 + 0x110) = HwStorWmiQueryReginfo;
    *(code **)((longlong)param_1 + 0x118) = HwStorWmiQueryDataBlock;
    *(code **)((longlong)param_1 + 0x120) = HwStorWmiSetDataBlock;
    *(code **)((longlong)param_1 + 0x128) = HwStorWmiSetDataItem;
    *(code **)((longlong)param_1 + 0x138) = HwStorWmiFunctionControl;
    *(undefined8 *)((longlong)param_1 + 0x130) = 0;
    *(undefined ***)((longlong)param_1 + 0x148) = &AmdPdoWmiGuidList;
    *(undefined4 *)((longlong)param_1 + 0x140) = 2;
    *(code **)((longlong)param_1 + 0x150) = HwStorWmiQueryReginfo;
    *(code **)((longlong)param_1 + 0x158) = HwStorWmiQueryDataBlock;
    *(code **)((longlong)param_1 + 0x160) = HwStorWmiSetDataBlock;
    *(code **)((longlong)param_1 + 0x168) = HwStorWmiSetDataItem;
    *(undefined8 *)((longlong)param_1 + 0x170) = 0;
    *(code **)((longlong)param_1 + 0x178) = HwStorWmiFunctionControl;
  }
  else {
    lVar15 = *(longlong *)(param_5 + 0x40);
    if (lVar15 != 0) {
      *(int *)(lVar15 + 0x3cc) = *(int *)(lVar15 + 0x3cc) + 1;
      local_118 = (uint *)((ulonglong)local_118 & 0xffffffff00000000);
      StorPortExtendedFunction(0x2d,param_1,lVar15,0xe028);
      AmdSataPMDisabled = *(uint *)(lVar15 + 0x3d0);
      AmdSataChannelSpd = *(uint *)(lVar15 + 0x3d4);
      AmdSataNCQDisabled = *(ulong *)(lVar15 + 0x3d8);
      local_110 = local_e8;
      AmdSataDET1 = 100;
      AmdSataDET3 = 1000;
      local_e8[0] = 4;
      local_118 = (uint *)local_38;
      cVar16 = StorPortRegistryRead(param_1,Param24,1,4);
      if (((cVar16 != '\0') && (local_e8[0] == 4)) && (local_38[0] != -1)) {
        AmdSataHints = local_38[0] != 0;
      }
      goto LAB_1c0009b91;
    }
LAB_1c000a3a7:
    uVar12 = 2;
  }
  return uVar12;
}



===== HwStorPassiveInitializeRoutine @ 1c000a540 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned char __cdecl HwStorPassiveInitializeRoutine(void * __ptr64) */

uchar __cdecl HwStorPassiveInitializeRoutine(void *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  ulonglong uVar3;
  int iVar4;
  longlong lVar5;
  uchar uVar6;
  ulonglong uVar7;
  undefined1 auStack_188 [32];
  longlong *local_168;
  undefined1 local_158 [16];
  undefined1 local_148 [4];
  uint local_144;
  uint local_140;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_188;
  lVar2 = *(longlong *)((longlong)param_1 + 0x228);
  uVar6 = '\0';
  local_158[0] = 0;
  plVar1 = (longlong *)(lVar2 + 0x18);
  local_168 = plVar1;
  iVar4 = StorPortExtendedFunction(0,param_1,0x58,0x49434841);
  if (iVar4 == 0) {
    lVar5 = 0;
    uVar3 = 0x58;
    do {
      uVar7 = uVar3;
      *(undefined1 *)(lVar5 + *plVar1) = 0;
      lVar5 = lVar5 + 1;
      uVar3 = uVar7 - 1;
    } while (uVar7 - 1 != 0);
    iVar4 = (int)uVar7 + 0x1f;
    *(undefined4 *)(*plVar1 + 0xc) = 0x14;
    *(undefined4 *)*plVar1 = 2;
    *(undefined4 *)(*plVar1 + 4) = 0x18;
    *(undefined4 *)(*plVar1 + 8) = 1;
    *(undefined4 *)(*plVar1 + 0x18) = 1;
    *(int *)(*plVar1 + 0x1c) = iVar4;
    *(undefined4 *)(*plVar1 + 0x20) = 1;
    *(undefined4 *)(*plVar1 + 0x24) = 0;
    lVar5 = *plVar1;
    *(undefined4 *)(lVar5 + 0x28) = 0xdcaf9c10;
    *(undefined4 *)(lVar5 + 0x2c) = 0x481f895f;
    *(undefined4 *)(lVar5 + 0x30) = 0xced492a4;
    *(undefined4 *)(lVar5 + 0x34) = 0x3356f5d2;
    *(undefined4 *)(*plVar1 + 0x38) = 1;
    *(int *)(*plVar1 + 0x3c) = iVar4;
    *(undefined8 *)(*plVar1 + 0x40) = 0;
    *(undefined8 *)(*plVar1 + 0x48) = 0;
    *(undefined4 *)(*plVar1 + 0x50) = 0xffffffff;
    local_168 = (longlong *)local_158;
    iVar4 = StorPortExtendedFunction((int)uVar7 + 0x2f,param_1,0,*plVar1);
    if (iVar4 == 0) {
      *(uint *)(lVar2 + 0x20) = *(uint *)(lVar2 + 0x20) | 0xc;
    }
    else {
      StorPortExtendedFunction(uVar7 & 0xffffffff,param_1,*plVar1);
      *(uint *)(lVar2 + 0x20) = *(uint *)(lVar2 + 0x20) & 0xfffffff3;
      *plVar1 = 0;
    }
  }
  memset(local_148,0,0x114);
  iVar4 = RtlGetVersion(local_148);
  if ((iVar4 == 0) && ((local_144 < 6 || ((local_144 == 6 && (local_140 < 3)))))) {
    uVar6 = '\x01';
  }
  g_bIsWin8OS = uVar6;
  return '\x01';
}



===== EnumerateChannels @ 1c000a6d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned char __cdecl EnumerateChannels(void * __ptr64) */

uchar __cdecl EnumerateChannels(void *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined1 auStack_58 [32];
  undefined4 local_38;
  undefined8 local_34;
  undefined8 local_2c;
  undefined8 local_24;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  uVar4 = 0;
  if (*(char *)((longlong)param_1 + 0x1c) != '\0') {
    uVar2 = MSISingle;
    do {
      if (MSIEnabled != 0) {
        local_38 = 0;
        local_34 = 0;
        local_2c = 0;
        local_24 = 0;
        local_1c = 0;
        if (uVar2 == 0) {
          iVar1 = StorPortExtendedFunction(0xd,param_1,uVar4,&local_38);
          uVar2 = (uint)(iVar1 != 0);
          MSISingle = (uint)(iVar1 != 0);
          if (MSISingle == 0) {
            MSIMaxMSG = (int)uVar4;
          }
        }
      }
      if (*(int *)(uVar4 * 0x1b88 + 0x3f0 + (longlong)param_1) == 1) {
        AhciEnumerateChannelAsynchronously
                  ((longlong *)((longlong)param_1 + uVar4 * 0x1b88 + 0x480),1);
        uVar2 = MSISingle;
      }
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 < *(byte *)((longlong)param_1 + 0x1c));
  }
  return '\x01';
}



===== HwStorInitialize @ 1c000a7b0 =====

/* unsigned char __cdecl HwStorInitialize(void * __ptr64) */

uchar __cdecl HwStorInitialize(void *param_1)

{
  undefined4 local_res8 [8];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  if (redpc != 0) {
    memset(&local_34,0,0x24);
    local_38 = 4;
    local_34 = 0x28;
    local_30 = 1;
    StorPortExtendedFunction(0xe,param_1,0,&local_38);
  }
  local_res8[0] = 0;
  StorPortNotification(0x1000,param_1,HwStorPassiveInitializeRoutine,local_res8);
  if ((*(uint *)((longlong)param_1 + 0x18) >> 2 & 1) == 0) {
    EnumerateChannels(param_1);
  }
  return '\x01';
}



===== HwStorResetBus @ 1c000a840 =====

/* unsigned char __cdecl HwStorResetBus(void * __ptr64,unsigned long) */

uchar __cdecl HwStorResetBus(void *param_1,ulong param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if ((*(uint *)((longlong)param_1 + 0x18) >> 2 & 1) == 0) {
    if (*(byte *)((longlong)param_1 + 0x1c) <= param_2) {
      return '\0';
    }
  }
  else {
    iVar1 = *(int *)((longlong)param_1 + 0x220);
    *(int *)((longlong)param_1 + 0x220) = iVar1 + 1;
    if (iVar1 == 0) {
      *(ulong *)((longlong)param_1 + 0x224) = param_2;
      return '\x01';
    }
    param_2 = *(uint *)((longlong)param_1 + 0x224);
  }
  uVar2 = AhciHwResetBus((longlong)param_1 + (ulonglong)param_2 * 0x1b88 + 0x480);
  FireHbaNotification(*(longlong *)((longlong)param_1 + 0x228),3,
                      *(undefined4 *)((ulonglong)param_2 * 0x1b88 + 0x3f4 + (longlong)param_1),
                      (uint)uVar2 & 0xff);
  return '\x01';
}



===== InvalidCommandAutoSense @ 1c000a8c8 =====

/* unsigned char __cdecl InvalidCommandAutoSense(struct _SCSI_REQUEST_BLOCK * __ptr64,unsigned char)
    */

uchar __cdecl InvalidCommandAutoSense(_SCSI_REQUEST_BLOCK *param_1,uchar param_2)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0x20);
  if (puVar1 == (undefined8 *)0x0) {
    return '\x06';
  }
  *puVar1 = 0;
  puVar1[1] = 0;
  *(undefined2 *)(puVar1 + 2) = 0;
  *(uchar *)((longlong)puVar1 + 0xc) = param_2;
  *(undefined1 *)puVar1 = 0x70;
  *(undefined1 *)((longlong)puVar1 + 7) = 10;
  *(byte *)((longlong)puVar1 + 2) = *(byte *)((longlong)puVar1 + 2) & 0xf5 | 5;
  param_1[0xb] = (_SCSI_REQUEST_BLOCK)0x12;
  param_1[4] = (_SCSI_REQUEST_BLOCK)0x2;
  return 0x84;
}



===== IdentifyToInquiry @ 1c000a90c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned long __cdecl IdentifyToInquiry(struct _INQUIRYDATA * __ptr64,unsigned long,struct
   _IDENTIFY_DEVICE_DATA * __ptr64) */

ulong __cdecl IdentifyToInquiry(_INQUIRYDATA *param_1,ulong param_2,_IDENTIFY_DEVICE_DATA *param_3)

{
  undefined8 uVar1;
  ulong uVar2;
  _INQUIRYDATA *p_Var3;
  _INQUIRYDATA *p_Var4;
  uint uVar5;
  uint uVar6;
  longlong lVar7;
  undefined1 auStack_88 [32];
  undefined4 local_68 [4];
  uchar local_58 [48];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_88;
  if ((*(ushort *)param_3 & 0x8000) == 0) {
    if (param_2 != 0) {
      memset(param_1,0,(ulonglong)param_2);
    }
    *param_1 = (_INQUIRYDATA)((byte)*param_1 & 0xe0);
    param_1[1] = (_INQUIRYDATA)((byte)param_1[1] & 0x7f);
    if (g_bIsWin8OS == '\0') {
      FormatAtaId(local_58,(uchar *)(param_3 + 0x36),0x28);
      uVar5 = 8;
      do {
        if (local_58[uVar5 - 1] == ' ') break;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
      *(undefined8 *)(param_1 + 8) = BLANK._0_8_;
      uVar6 = 8;
      if (uVar5 < 8) {
        uVar6 = uVar5;
      }
      if (uVar6 - 1 < 8) {
        memcpy(param_1 + 8,local_58,(ulonglong)uVar6);
      }
      uVar1 = BLANK._8_8_;
      uVar5 = 0x29 - uVar6;
      *(undefined8 *)(param_1 + 0x10) = BLANK._0_8_;
      *(undefined8 *)(param_1 + 0x18) = uVar1;
      if (0x10 < 0x29 - (ulonglong)uVar6) {
        uVar5 = 0x10;
      }
      memcpy(param_1 + 0x10,local_58 + uVar6,(ulonglong)uVar5);
      FormatAtaId((uchar *)local_68,(uchar *)(param_3 + 0x2e),8);
      *(undefined4 *)(param_1 + 0x20) = local_68[0];
    }
    else {
      p_Var4 = param_1 + 8;
      lVar7 = 0xc;
      p_Var3 = p_Var4;
      do {
        *p_Var3 = p_Var3[(longlong)(param_3 + (0x37 - (longlong)p_Var4))];
        p_Var3[1] = p_Var3[(longlong)(param_3 + (0x36 - (longlong)p_Var4))];
        p_Var3 = p_Var3 + 2;
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
      p_Var4 = param_1 + 0x20;
      lVar7 = 2;
      do {
        *p_Var4 = p_Var4[(longlong)(param_3 + (0xf - (longlong)param_1))];
        p_Var4[1] = p_Var4[(longlong)(param_3 + (0xe - (longlong)param_1))];
        p_Var4 = p_Var4 + 2;
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
    }
    param_1[2] = (_INQUIRYDATA)0x6;
    param_1[3] = (_INQUIRYDATA)((byte)param_1[3] & 0xe2 | 2);
    if ((((byte)param_3[0x60] & 1) == 0) || (-1 < (char)param_3[0x8a])) {
      param_1[4] = (_INQUIRYDATA)0x1f;
    }
    else {
      param_1[4] = (_INQUIRYDATA)0x37;
    }
    param_1[7] = (_INQUIRYDATA)((byte)param_1[7] | 2);
    if (((param_2 < 0x3c) || (((byte)param_3[0x60] & 1) == 0)) || (-1 < (char)param_3[0x8a])) {
      uVar2 = 0x24;
    }
    else {
      uVar2 = 0x3c;
      *(undefined2 *)(param_1 + 0x3a) = 0xffc0;
      param_1[0x3a] = param_1[0x3b];
      param_1[0x3b] = (_INQUIRYDATA)0xc0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



===== HwStorBuildIo @ 1c000aae0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned char __cdecl HwStorBuildIo(void * __ptr64,struct _SCSI_REQUEST_BLOCK * __ptr64) */

uchar __cdecl HwStorBuildIo(void *param_1,_SCSI_REQUEST_BLOCK *param_2)

{
  undefined8 *_Dst;
  _SCSI_REQUEST_BLOCK _Var1;
  int iVar2;
  undefined8 uVar3;
  undefined1 auStack_58 [32];
  undefined4 local_38;
  undefined4 uStack_34;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_58;
  _Dst = *(undefined8 **)(param_2 + 0x38);
  if (_Dst == (undefined8 *)0x0) {
    _Var1 = (_SCSI_REQUEST_BLOCK)0x6;
  }
  else {
    if ((byte)param_2[5] < (byte)*(_SCSI_REQUEST_BLOCK *)((longlong)param_1 + 0x1c)) {
      if ((byte)*(_SCSI_REQUEST_BLOCK *)((longlong)param_1 + 0x1d) <= (byte)param_2[6]) {
        _Var1 = (_SCSI_REQUEST_BLOCK)0x21;
        goto LAB_1c000ab3c;
      }
      if ((byte)param_2[7] < (byte)*(_SCSI_REQUEST_BLOCK *)((longlong)param_1 + 0x1e))
      goto LAB_1c000ab54;
      _Var1 = (_SCSI_REQUEST_BLOCK)0x20;
    }
    else {
      _Var1 = (_SCSI_REQUEST_BLOCK)InvalidCommandAutoSense(param_2,'$');
    }
    if (_Var1 == (_SCSI_REQUEST_BLOCK)0x0) {
LAB_1c000ab54:
      local_38 = 0x180001;
      param_2[3] = (_SCSI_REQUEST_BLOCK)0x0;
      memset(_Dst,0,0xb0);
      *_Dst = param_2;
      uVar3 = StorPortGetLogicalUnit(param_1,param_2[5],param_2[6],param_2[7]);
      _Dst[1] = uVar3;
      *(undefined4 *)((longlong)_Dst + 0x4c) = *(undefined4 *)(param_2 + 0x14);
      *(undefined1 *)((longlong)_Dst + 0x3a) = 0;
      *(_SCSI_REQUEST_BLOCK *)((longlong)_Dst + 0x3d) = param_2[5];
      *(_SCSI_REQUEST_BLOCK *)((longlong)_Dst + 0x3e) = param_2[6];
      *(_SCSI_REQUEST_BLOCK *)((longlong)_Dst + 0x3f) = param_2[7];
      iVar2 = StorPortExtendedFunction(0x1c,param_1,param_2,&local_38);
      if (iVar2 == 0) {
        _Dst[4] = CONCAT44(uStack_34,local_38);
        _Dst[5] = uStack_30;
        _Dst[6] = local_28;
      }
      return '\x01';
    }
  }
LAB_1c000ab3c:
  param_2[3] = _Var1;
  StorPortNotification(0,param_1,param_2);
  return '\0';
}



===== AtaExecute @ 1c000abf8 =====

/* unsigned char __cdecl AtaExecute(struct _STOR_EXTENSION * __ptr64,struct _SCSI_REQUEST_BLOCK *
   __ptr64) */

uchar __cdecl AtaExecute(_STOR_EXTENSION *param_1,_SCSI_REQUEST_BLOCK *param_2)

{
  _SCSI_REQUEST_BLOCK *p_Var1;
  undefined1 uVar2;
  longlong lVar3;
  _SCSI_REQUEST_BLOCK _Var4;
  char cVar5;
  uchar uVar6;
  undefined4 uVar7;
  int iVar8;
  byte *pbVar9;
  longlong lVar10;
  code *pcVar11;
  short sVar12;
  ulonglong uVar13;
  undefined8 *puVar14;
  bool bVar15;
  byte bVar16;
  uint uVar17;
  ushort uVar18;
  char *pcVar19;
  ulonglong *_Dst;
  undefined1 *puVar20;
  undefined1 uVar21;
  ulonglong local_res10;
  
  lVar3 = *(longlong *)(param_2 + 0x38);
  lVar10 = *(longlong *)
            (param_1 +
            ((ulonglong)(byte)param_2[6] + (ulonglong)(byte)param_2[5] * 0x371) * 8 + 0x1ef0);
  _Var4 = param_2[0x48];
  if ((byte)_Var4 < 0x43) {
    if (_Var4 == (_SCSI_REQUEST_BLOCK)0x42) {
      if (*(uint *)(param_2 + 0x10) < 8) {
LAB_1c000acc4:
        param_2[4] = (_SCSI_REQUEST_BLOCK)0x2;
        return '\x04';
      }
      puVar20 = *(undefined1 **)(param_2 + 0x18);
      if (((uint)CONCAT11(puVar20[2],puVar20[3]) == CONCAT11(*puVar20,puVar20[1]) - 6) &&
         (uVar18 = CONCAT11(puVar20[2],puVar20[3]) >> 4, uVar18 < 0x41)) {
        _Dst = (ulonglong *)(lVar3 + 0xb1U & 0xfffffffffffffffe);
        memset(_Dst,0,0x200);
        if (uVar18 != 0) {
          puVar20 = puVar20 + 0x13;
          uVar13 = (ulonglong)uVar18;
          do {
            local_res10 = (ulonglong)
                          CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(puVar20[-9],puVar20[-8]),
                                                              puVar20[-7]),puVar20[-6]),puVar20[-5])
                                   ,puVar20[-4]);
            uVar21 = puVar20[-1];
            uVar2 = *puVar20;
            puVar20 = puVar20 + 0x10;
            *_Dst = *_Dst ^ (local_res10 ^ *_Dst) & 0xffffffffffff;
            *(ushort *)((longlong)_Dst + 6) = CONCAT11(uVar21,uVar2);
            uVar13 = uVar13 - 1;
            _Dst = _Dst + 1;
          } while (uVar13 != 0);
        }
        lVar10 = *(longlong *)(param_2 + 0x38);
        *(undefined4 *)(lVar3 + 0x48) = 0x80;
        *(undefined4 *)(lVar3 + 0x50) = 0x200;
        *(ulonglong *)(lVar3 + 0x70) = lVar10 + 0xb1U & 0xfffffffffffffffe;
        *(undefined2 *)(lVar3 + 0x38) = 0x903;
        *(undefined1 *)(lVar3 + 0xa2) = 6;
        *(undefined2 *)(lVar3 + 0x9c) = 0x101;
        *(undefined1 *)(lVar3 + 0xa5) = 0;
        return '\0';
      }
LAB_1c000b287:
      uVar6 = '&';
      goto LAB_1c000b754;
    }
    if ((byte)_Var4 < 0x1c) {
      if (_Var4 == (_SCSI_REQUEST_BLOCK)0x1b) {
        if (((byte)param_2[0x4c] & 1) == 0) {
          *(undefined1 *)(lVar3 + 0xa2) = 0xe0;
          *(undefined2 *)(lVar3 + 0x38) = 0x100;
          return '\0';
        }
        return '\x01';
      }
      if (_Var4 == (_SCSI_REQUEST_BLOCK)0x0) goto LAB_1c000ad88;
      if (_Var4 == (_SCSI_REQUEST_BLOCK)0x3) {
        if (*(uint *)(param_2 + 0x10) < 0x12) {
          return '\x06';
        }
        puVar14 = *(undefined8 **)(param_2 + 0x18);
        *puVar14 = 0;
        puVar14[1] = 0;
        *(undefined2 *)(puVar14 + 2) = 0;
        *(byte *)((longlong)puVar14 + 2) = *(byte *)((longlong)puVar14 + 2) & 0xf0;
        *(undefined1 *)puVar14 = 0x70;
        *(undefined1 *)((longlong)puVar14 + 7) = 10;
        *(undefined2 *)((longlong)puVar14 + 0xc) = 0;
        param_2[4] = (_SCSI_REQUEST_BLOCK)0x0;
        *(undefined4 *)(param_2 + 0x10) = 0x12;
        return '\x01';
      }
      if (((byte)_Var4 - 8 & 0xfffffffd) == 0) {
        if (*(int *)(param_2 + 0x10) == 0) goto LAB_1c000acc4;
        if (_Var4 == (_SCSI_REQUEST_BLOCK)0x8) {
          *(undefined4 *)(lVar3 + 0x48) = 0x48;
          *(undefined2 *)(lVar3 + 0x38) = 0x102;
        }
        else {
          *(undefined4 *)(lVar3 + 0x48) = 0x88;
          *(undefined2 *)(lVar3 + 0x38) = 0x103;
          if (((byte)param_2[0x49] & 8) == 0) {
            uVar21 = 0;
          }
          else {
            uVar21 = *(undefined1 *)(lVar10 + 0x482);
          }
          *(undefined1 *)(lVar3 + 0xa2) = uVar21;
        }
        *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9e) = param_2[0x4b];
        *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9f) = param_2[0x4a];
        *(byte *)(lVar3 + 0xa0) = (byte)param_2[0x49] & 0x1f;
        *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9d) = param_2[0x4c];
        goto LAB_1c000ad38;
      }
      if (_Var4 == (_SCSI_REQUEST_BLOCK)0x15) goto LAB_1c000b28e;
      if (_Var4 == (_SCSI_REQUEST_BLOCK)0x1a) goto LAB_1c000ac91;
    }
    else {
      if (_Var4 == (_SCSI_REQUEST_BLOCK)0x25) {
        if (*(uint *)(param_2 + 0x10) < 8) {
          return '\x12';
        }
        *(undefined2 *)(lVar3 + 0x38) = 0x901;
        *(undefined4 *)(lVar3 + 0x48) = 0x40;
        lVar10 = *(longlong *)(param_2 + 0x38);
        goto LAB_1c000b778;
      }
      if (((byte)_Var4 - 0x28 & 0xfffffffd) == 0) {
        if (*(int *)(param_2 + 0x10) == 0) goto LAB_1c000acc4;
        if (_Var4 == (_SCSI_REQUEST_BLOCK)0x28) {
          *(undefined4 *)(lVar3 + 0x48) = 0x48;
          *(undefined2 *)(lVar3 + 0x38) = 0x102;
        }
        else {
          *(undefined4 *)(lVar3 + 0x48) = 0x88;
          *(undefined2 *)(lVar3 + 0x38) = 0x103;
          if (((byte)param_2[0x49] & 8) == 0) {
            uVar21 = 0;
          }
          else {
            uVar21 = *(undefined1 *)(lVar10 + 0x482);
          }
          *(undefined1 *)(lVar3 + 0xa2) = uVar21;
        }
        *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9e) = param_2[0x4d];
        *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9f) = param_2[0x4c];
        *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa0) = param_2[0x4b];
        *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9d) = param_2[0x50];
        *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa6) = param_2[0x4a];
        *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa5) = param_2[0x4f];
LAB_1c000ad38:
        uVar7 = *(undefined4 *)(param_2 + 0x10);
LAB_1c000ad3b:
        *(undefined4 *)(lVar3 + 0x50) = uVar7;
        return '\0';
      }
      if (_Var4 == (_SCSI_REQUEST_BLOCK)0x2f) goto LAB_1c000b012;
      if (_Var4 == (_SCSI_REQUEST_BLOCK)0x35) goto LAB_1c000ad88;
    }
    goto LAB_1c000b418;
  }
  if ((byte)_Var4 < 0x92) {
    if (_Var4 == (_SCSI_REQUEST_BLOCK)0x91) {
LAB_1c000ad88:
      *(undefined2 *)(lVar3 + 0x38) = 0x104;
      return '\0';
    }
    if (_Var4 == (_SCSI_REQUEST_BLOCK)0x55) {
LAB_1c000b28e:
      if (((_Var4 != (_SCSI_REQUEST_BLOCK)0x15) || (3 < *(uint *)(param_2 + 0x10))) &&
         ((_Var4 != (_SCSI_REQUEST_BLOCK)0x55 || (7 < *(uint *)(param_2 + 0x10))))) {
        pbVar9 = *(byte **)(param_2 + 0x18);
        bVar16 = 0xff;
        if (_Var4 == (_SCSI_REQUEST_BLOCK)0x15) {
          uVar13 = (ulonglong)pbVar9[3];
          iVar8 = -4 - (uint)pbVar9[3];
          pbVar9 = pbVar9 + 4;
        }
        else {
          iVar8 = (-8 - (uint)pbVar9[1]) + (uint)*pbVar9 * -0x100;
          uVar13 = (ulonglong)(int)((uint)pbVar9[6] << 8);
          pbVar9 = pbVar9 + (ulonglong)pbVar9[7] + 8;
        }
        uVar17 = *(int *)(param_2 + 0x10) + iVar8;
        pbVar9 = pbVar9 + uVar13;
        if ((int)uVar17 < 1) {
          return '\x01';
        }
        do {
          if (((*pbVar9 & 0x40) == 0) || ((int)uVar17 < 5)) {
            if ((int)uVar17 < 3) break;
            uVar18 = (ushort)pbVar9[1];
            sVar12 = 2;
          }
          else {
            sVar12 = 4;
            uVar18 = CONCAT11(pbVar9[2],pbVar9[3]);
          }
          if (uVar18 == 0) break;
          if (((*pbVar9 & 0x3f) == 8) && (0x13 < uVar17)) {
            bVar16 = pbVar9[2] >> 2 & 1;
          }
          uVar17 = uVar17 - ((int)(short)uVar18 + (int)sVar12);
          pbVar9 = pbVar9 + ((int)(short)uVar18 + (int)sVar12);
        } while (0 < (int)uVar17);
        if (bVar16 == 0xff) {
          return '\x01';
        }
        *(byte *)(lVar10 + 0x486) = bVar16;
        *(byte *)(lVar10 + 0x47f) = bVar16;
        *(undefined1 *)(lVar10 + 0x487) = 1;
        *(undefined2 *)(lVar3 + 0x38) = 0x100;
        *(undefined1 *)(lVar3 + 0xa2) = 0xef;
        *(byte *)(lVar3 + 0x9c) = (-(bVar16 != 0) & 0x80U) + 0x82;
        return '\0';
      }
LAB_1c000acb5:
      *(undefined4 *)(param_2 + 0x10) = 0;
      return '\x12';
    }
    if (_Var4 == (_SCSI_REQUEST_BLOCK)0x5a) {
LAB_1c000ac91:
      if (((_Var4 == (_SCSI_REQUEST_BLOCK)0x1a) && (*(uint *)(param_2 + 0x10) < 4)) ||
         ((_Var4 == (_SCSI_REQUEST_BLOCK)0x5a && (*(uint *)(param_2 + 0x10) < 8))))
      goto LAB_1c000acb5;
      bVar15 = false;
      iVar8 = *(int *)(param_2 + 0x10);
      if (*(char *)(lVar10 + 0x484) == '\0') {
        uVar21 = ((byte)(&AmdSataFua)
                        [(longlong)
                         (int)*(uint *)(param_1 + (ulonglong)(byte)param_2[5] * 0x1b88 + 0x3f4) >> 3
                        ] >> (*(uint *)(param_1 + (ulonglong)(byte)param_2[5] * 0x1b88 + 0x3f4) & 7)
                 & 1) != 0;
      }
      else {
        uVar21 = *(undefined1 *)(lVar10 + 0x483);
      }
      *(undefined1 *)(lVar10 + 0x482) = uVar21;
      if (param_2[0x48] == (_SCSI_REQUEST_BLOCK)0x1a) {
        pcVar19 = *(char **)(param_2 + 0x18);
        pcVar19[0] = '\0';
        pcVar19[1] = '\0';
        pcVar19[2] = '\0';
        pcVar19[3] = '\0';
        pcVar19[1] = '\0';
        cVar5 = *(char *)(lVar10 + 0x482);
        pcVar19[3] = '\0';
        uVar17 = iVar8 - 4;
        pcVar19[2] = -(cVar5 != '\0') & 0x10;
        cVar5 = '\x03';
        *(undefined4 *)(param_2 + 0x10) = 4;
      }
      else {
        puVar14 = *(undefined8 **)(param_2 + 0x18);
        *puVar14 = 0;
        pcVar19 = (char *)((longlong)puVar14 + 1);
        *(undefined1 *)((longlong)puVar14 + 2) = 0;
        uVar17 = iVar8 - 8;
        *(byte *)((longlong)puVar14 + 3) = -(*(char *)(lVar10 + 0x482) != '\0') & 0x10;
        *(undefined2 *)((longlong)puVar14 + 6) = 0;
        *(undefined4 *)(param_2 + 0x10) = 8;
        *(undefined1 *)puVar14 = 0;
        cVar5 = (char)param_2[0x10] + -2;
      }
      *pcVar19 = cVar5;
      if ((*(char *)(lVar10 + 0x47e) != '\0') &&
         ((((byte)param_2[0x4a] & 0x3f) == 8 || (((byte)param_2[0x4a] & 0x3f) == 0x3f)))) {
        if (uVar17 < 0x14) {
          return '\x12';
        }
        bVar15 = true;
        puVar14 = (undefined8 *)
                  ((ulonglong)*(uint *)(param_2 + 0x10) + *(longlong *)(param_2 + 0x18));
        *puVar14 = 0;
        puVar14[1] = 0;
        *(undefined4 *)(puVar14 + 2) = 0;
        *(byte *)((longlong)puVar14 + 2) = *(byte *)((longlong)puVar14 + 2) & 0xfc;
        *(undefined2 *)puVar14 = 0x1208;
        cVar5 = *(char *)(lVar10 + 0x47f);
        *(undefined8 *)((longlong)puVar14 + 3) = 0;
        *(byte *)((longlong)puVar14 + 2) =
             (cVar5 << 2 ^ *(byte *)((longlong)puVar14 + 2)) & 4 ^ *(byte *)((longlong)puVar14 + 2);
        *(undefined1 *)((longlong)puVar14 + 0xb) = 0;
        *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + 0x14;
        *pcVar19 = *pcVar19 + '\x14';
        uVar17 = uVar17 - 0x14;
      }
      if ((((byte)param_2[0x4a] & 0x3f) == 0x1c) || (((byte)param_2[0x4a] & 0x3f) == 0x3f)) {
        if (uVar17 < 0xc) {
          return '\x12';
        }
        puVar14 = (undefined8 *)
                  ((ulonglong)*(uint *)(param_2 + 0x10) + *(longlong *)(param_2 + 0x18));
        bVar15 = true;
        *puVar14 = 0;
        *(undefined4 *)puVar14 = 0x6000a1c;
        *(undefined4 *)((longlong)puVar14 + 4) = 0xffffffff;
        *(undefined4 *)(puVar14 + 1) = 0;
        *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + 0xc;
        *pcVar19 = *pcVar19 + '\f';
      }
      if (bVar15) {
        return '\x01';
      }
      goto LAB_1c000b287;
    }
    if (_Var4 == (_SCSI_REQUEST_BLOCK)0x85) goto LAB_1c000b610;
    if ((_Var4 != (_SCSI_REQUEST_BLOCK)0x88) && (_Var4 != (_SCSI_REQUEST_BLOCK)0x8a)) {
      if (_Var4 != (_SCSI_REQUEST_BLOCK)0x8f) goto LAB_1c000b418;
      goto LAB_1c000b012;
    }
    if (*(int *)(param_2 + 0x10) == 0) {
      param_2[4] = (_SCSI_REQUEST_BLOCK)0x2;
      return '\x04';
    }
    if ((((param_2[0x52] == (_SCSI_REQUEST_BLOCK)0x0) && (param_2[0x53] == (_SCSI_REQUEST_BLOCK)0x0)
         ) && (param_2[0x4a] == (_SCSI_REQUEST_BLOCK)0x0)) &&
       (param_2[0x4b] == (_SCSI_REQUEST_BLOCK)0x0)) {
      if (_Var4 == (_SCSI_REQUEST_BLOCK)0x88) {
        *(undefined4 *)(lVar3 + 0x48) = 0x48;
        *(undefined2 *)(lVar3 + 0x38) = 0x102;
      }
      else {
        *(undefined4 *)(lVar3 + 0x48) = 0x88;
        *(undefined2 *)(lVar3 + 0x38) = 0x103;
        if (((byte)param_2[0x49] & 8) == 0) {
          uVar21 = 0;
        }
        else {
          uVar21 = *(undefined1 *)(lVar10 + 0x482);
        }
        *(undefined1 *)(lVar3 + 0xa2) = uVar21;
      }
      *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9e) = param_2[0x51];
      *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9f) = param_2[0x50];
      *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa0) = param_2[0x4f];
      *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9d) = param_2[0x55];
      *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa6) = param_2[0x4e];
      *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa7) = param_2[0x4d];
      *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa8) = param_2[0x4c];
      *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa5) = param_2[0x54];
      uVar7 = *(undefined4 *)(param_2 + 0x10);
      goto LAB_1c000ad3b;
    }
  }
  else if (_Var4 == (_SCSI_REQUEST_BLOCK)0x9e) {
    if (*(uint *)(param_2 + 0x10) < 0xc) {
      return '\x12';
    }
    if ((((byte)param_2[0x56] & 1) != 0) || (*(longlong *)(param_2 + 0x4a) == 0)) {
      *(undefined2 *)(lVar3 + 0x38) = 0x901;
      *(undefined4 *)(lVar3 + 0x48) = 0x40;
      lVar10 = *(longlong *)(param_2 + 0x38);
LAB_1c000b778:
      *(undefined4 *)(lVar3 + 0x50) = 0x200;
      *(ulonglong *)(lVar3 + 0x70) = lVar10 + 0xb1U & 0xfffffffffffffffe;
      pcVar11 = SCSIOP_CAPACITY_CompletionRoutine;
      goto LAB_1c000b794;
    }
  }
  else {
    if (_Var4 == (_SCSI_REQUEST_BLOCK)0xa1) {
LAB_1c000b610:
      *(undefined4 *)(lVar3 + 0x48) = 8;
      if ((1 << ((byte)param_2[0x49] >> 1 & 0xf) & 0x1c78U) != 0) {
        p_Var1 = (_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9c);
        if (param_2[0x48] == (_SCSI_REQUEST_BLOCK)0xa1) {
          *p_Var1 = param_2[0x4b];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9e) = param_2[0x4d];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9f) = param_2[0x4e];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa0) = param_2[0x4f];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9d) = param_2[0x4c];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa1) = param_2[0x50];
          _Var4 = param_2[0x51];
        }
        else {
          *p_Var1 = param_2[0x4c];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9e) = param_2[0x50];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9f) = param_2[0x52];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa0) = param_2[0x54];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9d) = param_2[0x4e];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa4) = param_2[0x4b];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa6) = param_2[0x4f];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa7) = param_2[0x51];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa8) = param_2[0x53];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa5) = param_2[0x4d];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa1) = param_2[0x55];
          _Var4 = param_2[0x56];
        }
        *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa2) = _Var4;
        if (((byte)param_2[0x4a] & 0x20) != 0) {
          if ((*(longlong *)(param_2 + 0x20) == 0) || ((byte)param_2[0xb] < 0x16))
          goto LAB_1c000b418;
          *(_SCSI_REQUEST_BLOCK **)(lVar3 + 0x78) = p_Var1;
          *(undefined1 *)(lVar3 + 0x41) = 0x10;
        }
        iVar8 = *(int *)(param_2 + 0x10);
        *(int *)(lVar3 + 0x50) = iVar8;
        if (iVar8 != 0) {
          *(uint *)(lVar3 + 0x48) =
               (-(uint)(((byte)param_2[0x4a] & 8) != 0) & 0xffffffc0) + 0x80 | 8;
        }
        pcVar11 = SCSIOP_ATA_PASSTHROUG_CompletionRoutine;
        *(undefined2 *)(lVar3 + 0x38) = 0x100;
LAB_1c000b794:
        *(code **)(lVar3 + 0x18) = pcVar11;
        return '\0';
      }
LAB_1c000b418:
      uVar6 = ' ';
      goto LAB_1c000b754;
    }
    if (_Var4 != (_SCSI_REQUEST_BLOCK)0xa2) {
      if (_Var4 == (_SCSI_REQUEST_BLOCK)0xaf) {
LAB_1c000b012:
        if (_Var4 == (_SCSI_REQUEST_BLOCK)0x2f) {
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9e) = param_2[0x4d];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9f) = param_2[0x4c];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa0) = param_2[0x4b];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9d) = param_2[0x50];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa6) = param_2[0x4a];
          _Var4 = param_2[0x4f];
        }
        else if (_Var4 == (_SCSI_REQUEST_BLOCK)0xaf) {
          if ((param_2[0x4e] != (_SCSI_REQUEST_BLOCK)0x0) ||
             (param_2[0x4f] != (_SCSI_REQUEST_BLOCK)0x0)) {
LAB_1c000b4d1:
            uVar6 = InvalidCommandAutoSense(param_2,'$');
            goto LAB_1c000b4e5;
          }
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9e) = param_2[0x4d];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9f) = param_2[0x4c];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa0) = param_2[0x4b];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9d) = param_2[0x51];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa6) = param_2[0x4a];
          _Var4 = param_2[0x50];
        }
        else {
          if (_Var4 != (_SCSI_REQUEST_BLOCK)0x8f) {
            uVar6 = '\x06';
            goto LAB_1c000b4e5;
          }
          if ((((param_2[0x52] != (_SCSI_REQUEST_BLOCK)0x0) ||
               (param_2[0x53] != (_SCSI_REQUEST_BLOCK)0x0)) ||
              (param_2[0x4a] != (_SCSI_REQUEST_BLOCK)0x0)) ||
             (param_2[0x4b] != (_SCSI_REQUEST_BLOCK)0x0)) goto LAB_1c000b4d1;
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9e) = param_2[0x51];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9f) = param_2[0x50];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa0) = param_2[0x4f];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9d) = param_2[0x55];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa6) = param_2[0x4e];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa7) = param_2[0x4d];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa8) = param_2[0x4c];
          _Var4 = param_2[0x54];
        }
        *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa5) = _Var4;
        uVar6 = '\0';
LAB_1c000b4e5:
        *(undefined4 *)(lVar3 + 0x48) = 8;
        *(undefined2 *)(lVar3 + 0x38) = 0x111;
        return uVar6;
      }
      if (_Var4 != (_SCSI_REQUEST_BLOCK)0xb5) goto LAB_1c000b418;
    }
    if (((((byte)param_2[0x4c] & 0x80) != 0) && (param_2[0x4e] == (_SCSI_REQUEST_BLOCK)0x0)) &&
       (param_2[0x4f] == (_SCSI_REQUEST_BLOCK)0x0)) {
      uVar17 = *(uint *)(param_2 + 0x10);
      if (uVar17 == 0) {
        if ((param_2[0x50] == (_SCSI_REQUEST_BLOCK)0x0) &&
           (param_2[0x51] == (_SCSI_REQUEST_BLOCK)0x0)) {
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9c) = param_2[0x49];
          *(undefined1 *)(lVar3 + 0x9e) = 0;
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9f) = param_2[0x4b];
          *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa0) = param_2[0x4a];
          *(undefined1 *)(lVar3 + 0x9d) = 0;
          _Var4 = param_2[0x48];
          *(undefined2 *)(lVar3 + 0xa1) = 0x5b00;
          *(bool *)(lVar3 + 0xa6) = _Var4 == (_SCSI_REQUEST_BLOCK)0xa2;
          goto LAB_1c000b570;
        }
      }
      else if ((uVar17 == (uint)CONCAT11(param_2[0x50],param_2[0x51]) * 0x200) &&
              ((uVar17 & 0x1ff) == 0)) {
        *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9c) = param_2[0x49];
        *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9e) = param_2[0x50];
        *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9f) = param_2[0x4b];
        *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0xa0) = param_2[0x4a];
        *(_SCSI_REQUEST_BLOCK *)(lVar3 + 0x9d) = param_2[0x51];
        *(undefined1 *)(lVar3 + 0xa1) = 0;
        uVar21 = 0x5f;
        if (param_2[0x48] == (_SCSI_REQUEST_BLOCK)0xa2) {
          uVar21 = 0x5d;
        }
        *(undefined1 *)(lVar3 + 0xa2) = uVar21;
        uVar17 = 0x80;
        if (param_2[0x48] == (_SCSI_REQUEST_BLOCK)0xa2) {
          uVar17 = 0x40;
        }
        *(uint *)(lVar3 + 0x48) = *(uint *)(lVar3 + 0x48) | uVar17;
LAB_1c000b570:
        uVar7 = *(undefined4 *)(param_2 + 0x10);
        *(undefined2 *)(lVar3 + 0x38) = 0x100;
        *(undefined4 *)(lVar3 + 0x50) = uVar7;
        return '\0';
      }
    }
  }
  uVar6 = '$';
LAB_1c000b754:
  uVar6 = InvalidCommandAutoSense(param_2,uVar6);
  return uVar6;
}



===== AtapiExecute @ 1c000b7b4 =====

/* unsigned char __cdecl AtapiExecute(struct _STOR_EXTENSION * __ptr64,struct _SCSI_REQUEST_BLOCK *
   __ptr64) */

uchar __cdecl AtapiExecute(_STOR_EXTENSION *param_1,_SCSI_REQUEST_BLOCK *param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x38);
  *(undefined2 *)(lVar1 + 0x38) = 0x200;
  memcpy((void *)(lVar1 + 0x9c),param_2 + 0x48,0x10);
  if ((*(uint *)(param_2 + 0xc) & 0xc0) == 0) {
    if (*(int *)(param_2 + 0x10) == 0) {
      *(undefined4 *)(lVar1 + 0x48) = 0;
      goto LAB_1c000b829;
    }
  }
  else if (*(int *)(param_2 + 0x10) == 0) {
    param_2[4] = (_SCSI_REQUEST_BLOCK)0x2;
    return '\x04';
  }
  *(undefined8 *)(lVar1 + 0x70) = *(undefined8 *)(param_2 + 0x18);
  *(uint *)(lVar1 + 0x48) =
       -(uint)(*(longlong *)(param_2 + 0x18) != 0) & 4 | *(uint *)(param_2 + 0xc) & 0xc0 | 2;
LAB_1c000b829:
  *(undefined4 *)(lVar1 + 0x50) = *(undefined4 *)(param_2 + 0x10);
  return '\0';
}



===== HwStorStartIo @ 1c000b840 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned char __cdecl HwStorStartIo(void * __ptr64,struct _SCSI_REQUEST_BLOCK * __ptr64) */

uchar __cdecl HwStorStartIo(void *param_1,_SCSI_REQUEST_BLOCK *param_2)

{
  ushort *puVar1;
  ushort *puVar2;
  undefined1 *puVar3;
  _SCSI_REQUEST_BLOCK _Var4;
  char cVar5;
  undefined2 uVar6;
  short sVar7;
  longlong lVar8;
  undefined8 *puVar9;
  undefined2 *puVar10;
  undefined4 *puVar11;
  longlong lVar12;
  int *piVar13;
  _STOR_EXTENSION _Var14;
  _IDE_CHANNEL _Var15;
  undefined8 uVar16;
  _UNIT **pp_Var17;
  uchar uVar18;
  byte bVar19;
  ushort uVar20;
  byte *pbVar21;
  int iVar22;
  uint uVar23;
  _IDE_CHANNEL *p_Var24;
  _STOR_EXTENSION *p_Var25;
  undefined4 *puVar26;
  ulonglong uVar27;
  int *piVar28;
  size_t _Size;
  longlong lVar29;
  byte bVar30;
  _SCSI_REQUEST_BLOCK _Var31;
  _IDE_CHANNEL *p_Var32;
  uint uVar33;
  bool bVar34;
  undefined1 auStack_e8 [32];
  uint local_c8;
  undefined4 local_c0;
  uint local_b8 [2];
  _UNIT **local_b0;
  longlong local_a8;
  int *local_a0;
  uint local_98 [2];
  _STOR_EXTENSION *local_90;
  undefined4 local_88 [4];
  uchar local_78 [48];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_e8;
  local_90 = param_1;
  lVar29 = *(longlong *)(param_2 + 0x38);
  bVar19 = 0;
  bVar34 = false;
  local_a8 = lVar29;
  p_Var24 = (_IDE_CHANNEL *)(ulonglong)(byte)param_2[5];
  _Var4 = param_2[6];
  puVar1 = (ushort *)(lVar29 + 0x38);
  local_b0 = *(_UNIT ***)(lVar29 + 8);
  p_Var32 = (_IDE_CHANNEL *)((longlong)param_1 + (longlong)p_Var24 * 0x1b88 + 1000);
  local_a0 = *(int **)((longlong)param_1 +
                      ((longlong)p_Var24 * 0x371 + (ulonglong)(byte)_Var4) * 8 + 0x1ef0);
  if (param_2[3] != (_SCSI_REQUEST_BLOCK)0x0) {
    *(int *)(p_Var32 + 0x78) = *(int *)(p_Var32 + 0x78) + 1;
    return '\x01';
  }
  uVar27 = 10;
  if (*(int *)(p_Var32 + 8) == 0) {
    _Var31 = (_SCSI_REQUEST_BLOCK)0xa;
    if ((param_2[0x48] == (_SCSI_REQUEST_BLOCK)0xa0) && (_Var4 == (_SCSI_REQUEST_BLOCK)0x0)) {
      local_98[0] = *(uint *)(*(longlong *)(*(longlong *)((longlong)param_1 + 0x228) + 8) + 0xc);
      if (AmdSataPI != 0) {
        local_98[0] = local_98[0] & AmdSataPI;
      }
      uVar33 = (uint)((*(byte *)((longlong)local_98 + ((longlong)(int)*(uint *)(p_Var32 + 0xc) >> 3)
                                ) >> (*(uint *)(p_Var32 + 0xc) & 7) & 1) != 0);
      *(uint *)(p_Var32 + 8) = uVar33;
      if (uVar33 == 1) {
        uVar18 = AhciPortChannelStart(p_Var32);
        if (uVar18 == '\0') {
          _Var31 = (_SCSI_REQUEST_BLOCK)0xa;
        }
        else {
LAB_1c000b942:
          p_Var32[0x19d] = (_IDE_CHANNEL)0x1;
          AhciPortRequestSynchronizedRoutine((longlong)(p_Var32 + 0x98),AhciHwEnumerateBus);
          _Var31 = (_SCSI_REQUEST_BLOCK)0x5;
        }
      }
    }
  }
  else {
    _Var31 = (_SCSI_REQUEST_BLOCK)0x0;
    if ((param_2[0x48] == (_SCSI_REQUEST_BLOCK)0xa0) && (_Var4 == (_SCSI_REQUEST_BLOCK)0x0)) {
      local_b8[0] = *(uint *)(*(longlong *)(*(longlong *)((longlong)param_1 + 0x228) + 8) + 0xc);
      p_Var24 = (_IDE_CHANNEL *)(ulonglong)AmdSataPI;
      if (AmdSataPI != 0) {
        local_b8[0] = local_b8[0] & AmdSataPI;
      }
      uVar33 = (uint)((*(byte *)((longlong)local_b8 + ((longlong)(int)*(uint *)(p_Var32 + 0xc) >> 3)
                                ) >> (*(uint *)(p_Var32 + 0xc) & 7) & 1) != 0);
      *(uint *)(p_Var32 + 8) = uVar33;
      if (uVar33 == 0) {
        _Var31 = (_SCSI_REQUEST_BLOCK)0xa;
        p_Var32[0x19d] = (_IDE_CHANNEL)0x1;
        AhciPortRequestSynchronizedRoutine((longlong)(p_Var32 + 0x98),AhciHwEnumerateBus);
        goto LAB_1c000ba0f;
      }
      if ((uVar33 == 1) && (p_Var32[0x90] == (_IDE_CHANNEL)0x0)) {
        p_Var24 = p_Var32;
        uVar18 = AhciPortChannelStart(p_Var32);
        if (uVar18 != '\0') goto LAB_1c000b942;
        _Var31 = (_SCSI_REQUEST_BLOCK)0xa;
      }
    }
    if (_Var31 == (_SCSI_REQUEST_BLOCK)0x0) {
      if ((*(uint *)(p_Var32 + 0xa8) >> 2 & 1) != 0) {
        if (local_b0 == (_UNIT **)0x0) {
          param_2[3] = (_SCSI_REQUEST_BLOCK)0xa;
        }
        else {
          if ((*(uint *)(local_90 + 0x18) >> 2 & 1) == 0) {
            local_c8 = 0x32;
            StorPortPauseDevice(local_90,param_2[5],param_2[6],param_2[7]);
          }
          param_2[3] = (_SCSI_REQUEST_BLOCK)0x5;
        }
        goto LAB_1c000bae5;
      }
      _Var4 = param_2[2];
      if (_Var4 == (_SCSI_REQUEST_BLOCK)0x0) {
        _Var4 = param_2[0x48];
        p_Var25 = (_STOR_EXTENSION *)CONCAT71((int7)((ulonglong)p_Var24 >> 8),_Var4);
        if (_Var4 == (_SCSI_REQUEST_BLOCK)0x12) {
          if (local_b0 == (_UNIT **)0x0) {
            uVar33 = (uint)(byte)param_2[6];
          }
          else {
            if ((*(uint *)(local_90 + 0x18) >> 2 & 1) != 0) {
              p_Var25 = local_90 + ((longlong)(int)*(uint *)(p_Var32 + 0xc) >> 3) + 0x3c0;
              uVar33 = *(uint *)(p_Var32 + 0xc) & 7;
              _Var14 = *p_Var25;
              *p_Var25 = (_STOR_EXTENSION)((byte)*p_Var25 | '\x01' << uVar33);
              if (((byte)_Var14 >> uVar33 & 1) == 0) {
                AhciHwResetBus((longlong)(p_Var32 + 0x98));
                local_a0 = *(int **)(local_90 +
                                    ((ulonglong)(byte)param_2[5] * 0x371 +
                                    (ulonglong)(byte)param_2[6]) * 8 + 0x1ef0);
              }
            }
            uVar33 = (uint)(byte)param_2[6];
            p_Var25 = *(_STOR_EXTENSION **)(p_Var32 + (ulonglong)(byte)param_2[6] * 8 + 0x1b08);
            if ((p_Var25 != (_STOR_EXTENSION *)0x0) &&
               ((*(int *)p_Var25 == 0x101 || (*(int *)p_Var25 == -0x14ebfeff)))) {
              if (*local_b0 == (_UNIT *)0x0) {
                *local_b0 = (_UNIT *)0x13579bdf;
                StorPortQuerySystemTime(local_b0 + 1);
                p_Var32[((longlong)(int)(uint)(byte)param_2[6] >> 3) + 0x80] =
                     (_IDE_CHANNEL)
                     ((byte)p_Var32[((longlong)(int)(uint)(byte)param_2[6] >> 3) + 0x80] |
                     '\x01' << ((byte)param_2[6] & 7));
                local_c8 = (uint)*(byte *)(local_a0 + 0x11f);
                if (*(byte *)(local_a0 + 0x11f) == 0) {
                  local_c8 = 1;
                }
                p_Var25 = local_90;
                StorPortSetDeviceQueueDepth(local_90,param_2[5],param_2[6],param_2[7]);
              }
              piVar13 = local_a0;
              if ((((byte)param_2[0x49] & 1) == 0) && (param_2[0x4a] != (_SCSI_REQUEST_BLOCK)0x0)) {
                *(undefined4 *)(param_2 + 0x10) = 0;
                uVar27 = 4;
                param_2[4] = (_SCSI_REQUEST_BLOCK)0x2;
                goto LAB_1c000bade;
              }
              if (((byte)param_2[0x49] & 1) == 0) {
                if (0x23 < *(uint *)(param_2 + 0x10)) {
                  bVar34 = false;
                  if (local_a0 != (int *)0x0) {
                    bVar34 = *local_a0 == 0x101;
                  }
                  if (bVar34) {
                    *(undefined4 *)(lVar29 + 0x48) = 0x40;
                    *puVar1 = 0x901;
                    lVar8 = *(longlong *)(param_2 + 0x38);
                    *(undefined4 *)(lVar29 + 0x50) = 0x200;
                    *(ulonglong *)(lVar29 + 0x70) = lVar8 + 0xb1U & 0xfffffffffffffffe;
                    *(code **)(local_a8 + 0x18) = SCSIOP_INQUIRY_CompletionRoutine;
                    goto LAB_1c000ca79;
                  }
                  bVar34 = false;
                  if (local_a0 != (int *)0x0) {
                    bVar34 = *local_a0 == -0x14ebfeff;
                  }
                  if (bVar34) goto LAB_1c000baaa;
                  goto LAB_1c000ca6d;
                }
              }
              else {
                puVar2 = (ushort *)(local_a0 + 6);
                _Var4 = param_2[0x4a];
                iVar22 = 3;
                if ((*puVar2 & 0x8000) == 0) {
                  iVar22 = 6;
                }
                if (_Var4 == (_SCSI_REQUEST_BLOCK)0x0) {
                  if (iVar22 + 4U <= *(uint *)(param_2 + 0x10)) {
                    puVar10 = *(undefined2 **)(param_2 + 0x18);
                    *puVar10 = 0;
                    *(undefined1 *)(puVar10 + 1) = 0;
                    *(char *)((longlong)puVar10 + 3) = (char)iVar22;
                    puVar10[2] = 0x8000;
                    *(undefined1 *)(puVar10 + 3) = 0x89;
                    if ((char)iVar22 == '\x06') {
                      *(undefined2 *)((longlong)puVar10 + 7) = 0xb1b0;
                      *(undefined1 *)((longlong)puVar10 + 9) = 0xb2;
                    }
                    *(uint *)(param_2 + 0x10) = iVar22 + 4U;
                    uVar27 = 1;
                    goto LAB_1c000ca6d;
                  }
                }
                else if (_Var4 == (_SCSI_REQUEST_BLOCK)0x80) {
                  if (0x17 < *(uint *)(param_2 + 0x10)) {
                    puVar11 = *(undefined4 **)(param_2 + 0x18);
                    *puVar11 = 0x14008000;
                    puVar26 = puVar11 + 1;
                    do {
                      *(undefined1 *)puVar26 =
                           *(undefined1 *)
                            ((longlong)puVar2 + (0x11 - (longlong)puVar11) + (longlong)puVar26);
                      *(undefined1 *)((longlong)puVar26 + 1) =
                           *(undefined1 *)
                            ((longlong)puVar2 + (0x10 - (longlong)puVar11) + (longlong)puVar26);
                      puVar26 = (undefined4 *)((longlong)puVar26 + 2);
                      uVar27 = uVar27 - 1;
                    } while (uVar27 != 0);
                    *(undefined4 *)(param_2 + 0x10) = 0x18;
                    goto LAB_1c000bb55;
                  }
                }
                else if (_Var4 == (_SCSI_REQUEST_BLOCK)0x89) {
                  if (0x23b < *(uint *)(param_2 + 0x10)) {
                    piVar28 = local_a0 + 6;
                    FormatAtaId(local_78,(uchar *)((longlong)local_a0 + 0x4e),0x28);
                    uVar33 = 8;
                    FormatAtaId((uchar *)local_88,(uchar *)((longlong)piVar13 + 0x46),8);
                    pbVar21 = *(byte **)(param_2 + 0x18);
                    memset(pbVar21,0,0x23c);
                    iVar22 = *piVar28;
                    pbVar21[1] = 0x89;
                    pbVar21[2] = 2;
                    *pbVar21 = (byte)((uint)iVar22 >> 8) >> 7;
                    pbVar21[3] = 0x38;
                    do {
                      if (local_78[uVar33 - 1] == ' ') break;
                      uVar33 = uVar33 - 1;
                    } while (uVar33 != 0);
                    *(undefined8 *)(pbVar21 + 8) = BLANK._0_8_;
                    _Size = 0x29;
                    if (uVar33 < 0x29) {
                      _Size = (size_t)uVar33;
                    }
                    local_b8[0] = (uint)_Size;
                    if (local_b8[0] - 1 < 8) {
                      memcpy(pbVar21 + 8,local_78,_Size);
                      _Size = (size_t)local_b8[0];
                    }
                    uVar16 = BLANK._8_8_;
                    uVar33 = 0x29 - (int)_Size;
                    if (0x10 < 0x29 - _Size) {
                      uVar33 = 0x10;
                    }
                    *(undefined8 *)(pbVar21 + 0x10) = BLANK._0_8_;
                    *(undefined8 *)(pbVar21 + 0x18) = uVar16;
                    memcpy(pbVar21 + 0x10,local_78 + _Size,(ulonglong)uVar33);
                    *(undefined4 *)(pbVar21 + 0x20) = local_88[0];
                    if (local_a0 != (int *)0x0) {
                      bVar34 = *local_a0 == 0x101;
                    }
                    lVar29 = 4;
                    pbVar21[0x38] = (-bVar34 & 0x4bU) + 0xa1;
                    pbVar21 = pbVar21 + 0x3c;
                    do {
                      uVar16 = *(undefined8 *)(piVar28 + 2);
                      *(undefined8 *)pbVar21 = *(undefined8 *)piVar28;
                      *(undefined8 *)(pbVar21 + 8) = uVar16;
                      uVar16 = *(undefined8 *)(piVar28 + 6);
                      *(undefined8 *)(pbVar21 + 0x10) = *(undefined8 *)(piVar28 + 4);
                      *(undefined8 *)(pbVar21 + 0x18) = uVar16;
                      uVar16 = *(undefined8 *)(piVar28 + 10);
                      *(undefined8 *)(pbVar21 + 0x20) = *(undefined8 *)(piVar28 + 8);
                      *(undefined8 *)(pbVar21 + 0x28) = uVar16;
                      uVar16 = *(undefined8 *)(piVar28 + 0xe);
                      *(undefined8 *)(pbVar21 + 0x30) = *(undefined8 *)(piVar28 + 0xc);
                      *(undefined8 *)(pbVar21 + 0x38) = uVar16;
                      uVar16 = *(undefined8 *)(piVar28 + 0x12);
                      *(undefined8 *)(pbVar21 + 0x40) = *(undefined8 *)(piVar28 + 0x10);
                      *(undefined8 *)(pbVar21 + 0x48) = uVar16;
                      uVar16 = *(undefined8 *)(piVar28 + 0x16);
                      *(undefined8 *)(pbVar21 + 0x50) = *(undefined8 *)(piVar28 + 0x14);
                      *(undefined8 *)(pbVar21 + 0x58) = uVar16;
                      uVar16 = *(undefined8 *)(piVar28 + 0x1a);
                      *(undefined8 *)(pbVar21 + 0x60) = *(undefined8 *)(piVar28 + 0x18);
                      *(undefined8 *)(pbVar21 + 0x68) = uVar16;
                      piVar13 = piVar28 + 0x1c;
                      uVar16 = *(undefined8 *)(piVar28 + 0x1e);
                      piVar28 = piVar28 + 0x20;
                      *(undefined8 *)(pbVar21 + 0x70) = *(undefined8 *)piVar13;
                      *(undefined8 *)(pbVar21 + 0x78) = uVar16;
                      lVar29 = lVar29 + -1;
                      pbVar21 = pbVar21 + 0x80;
                    } while (lVar29 != 0);
                    *(undefined4 *)(param_2 + 0x10) = 0x23c;
                    goto LAB_1c000bb55;
                  }
                }
                else if (_Var4 == (_SCSI_REQUEST_BLOCK)0xb0) {
                  if (0x3f < *(uint *)(param_2 + 0x10)) {
                    puVar26 = *(undefined4 **)(param_2 + 0x18);
                    memset(puVar26,0,0x40);
                    *puVar26 = 0x1000b000;
                    if ((*(byte *)((longlong)local_a0 + 0x16a) & 1) != 0) {
                      *(undefined1 *)((longlong)puVar26 + 3) = 0x3c;
                      puVar26[6] = 0x40000000;
                      puVar26[5] = 0xffff0000;
                    }
LAB_1c000bddb:
                    *(undefined4 *)(param_2 + 0x10) = 0x40;
                    goto LAB_1c000bb55;
                  }
                }
                else if (_Var4 == (_SCSI_REQUEST_BLOCK)0xb1) {
                  if (0x3f < *(uint *)(param_2 + 0x10)) {
                    puVar10 = *(undefined2 **)(param_2 + 0x18);
                    memset(puVar10,0,0x40);
                    *puVar10 = 0xb100;
                    *(undefined1 *)((longlong)puVar10 + 3) = 0x3c;
                    uVar6 = *(undefined2 *)((longlong)local_a0 + 0x1ca);
                    *(char *)((longlong)puVar10 + 5) = (char)uVar6;
                    *(char *)(puVar10 + 2) = (char)((ushort)uVar6 >> 8);
                    goto LAB_1c000bddb;
                  }
                }
                else {
                  if (_Var4 != (_SCSI_REQUEST_BLOCK)0xb2) goto LAB_1c000c068;
                  if (7 < *(uint *)(param_2 + 0x10)) {
                    puVar9 = *(undefined8 **)(param_2 + 0x18);
                    *puVar9 = 0;
                    *(undefined2 *)puVar9 = 0xb200;
                    *(undefined1 *)((longlong)puVar9 + 3) = 4;
                    bVar30 = *(byte *)((longlong)puVar9 + 5);
                    *(byte *)((longlong)puVar9 + 5) = bVar30 & 0xfe;
                    bVar30 = *(char *)((longlong)local_a0 + 0x16a) << 7 | bVar30 & 0x7e;
                    bVar30 = bVar30 ^ (bVar30 >> 6 ^ bVar30) & 2;
                    *(byte *)((longlong)puVar9 + 5) = bVar30;
                    if ((char)bVar30 < '\0') {
                      bVar19 = (byte)(*(ushort *)((longlong)local_a0 + 0xa2) >> 5) & 1;
                    }
                    *(byte *)((longlong)puVar9 + 5) = (bVar19 << 2 ^ bVar30) & 4 ^ bVar30;
                    *(undefined4 *)(param_2 + 0x10) = 8;
                    goto LAB_1c000bb55;
                  }
                }
LAB_1c000bad8:
                *(undefined4 *)(param_2 + 0x10) = 0;
              }
              uVar27 = 0x12;
              goto LAB_1c000bade;
            }
          }
          p_Var32[((longlong)(int)uVar33 >> 3) + 0x80] =
               (_IDE_CHANNEL)
               ((byte)p_Var32[((longlong)(int)uVar33 >> 3) + 0x80] & ~('\x01' << (uVar33 & 7)));
        }
        else if (_Var4 == (_SCSI_REQUEST_BLOCK)0xa0) {
          if (local_b0 != (_UNIT **)0x0) {
            if (*(uint *)(param_2 + 0x10) < 0x10) goto LAB_1c000bad8;
            if ((*(int **)(p_Var32 + (ulonglong)(byte)param_2[6] * 8 + 0x1b08) != (int *)0x0) &&
               ((iVar22 = **(int **)(p_Var32 + (ulonglong)(byte)param_2[6] * 8 + 0x1b08),
                iVar22 == 0x101 || (iVar22 == -0x14ebfeff)))) {
              puVar26 = *(undefined4 **)(param_2 + 0x18);
              *puVar26 = 0x8000000;
              *(undefined2 *)(puVar26 + 1) = 0;
              *(undefined8 *)((longlong)puVar26 + 6) = 0;
              *(undefined2 *)((longlong)puVar26 + 0xe) = 0;
              *(undefined4 *)(param_2 + 0x10) = 0x10;
              goto LAB_1c000bb55;
            }
          }
        }
        else if ((local_a0 != (int *)0x0) && (local_b0 != (_UNIT **)0x0)) {
          if ((*local_a0 == 0x101) || (_Var4 == (_SCSI_REQUEST_BLOCK)0x85)) {
            bVar19 = AtaExecute(local_90,param_2);
          }
          else {
            if (*local_a0 != -0x14ebfeff) goto LAB_1c000bade;
LAB_1c000baaa:
            bVar19 = AtapiExecute(p_Var25,param_2);
          }
          goto LAB_1c000c072;
        }
      }
      else {
        if ((local_a0 != (int *)0x0) && (local_b0 != (_UNIT **)0x0)) {
          if (0x17 < (byte)_Var4) {
            if (_Var4 == (_SCSI_REQUEST_BLOCK)0x20) {
              p_Var24 = p_Var32 + ((longlong)(int)(uint)(byte)param_2[6] >> 3) + 0x1adc;
              uVar33 = (byte)param_2[6] & 7;
              _Var15 = *p_Var24;
              *p_Var24 = (_IDE_CHANNEL)((byte)*p_Var24 | '\x01' << uVar33);
              if ((((byte)_Var15 >> uVar33 & 1) == 0) &&
                 (uVar27 = (ulonglong)(byte)param_2[6], *(int *)(p_Var32 + uVar27 * 4 + 0x248) == 0)
                 ) {
                *(undefined4 *)(p_Var32 + uVar27 * 4 + 0x248) =
                     *(undefined4 *)(p_Var32 + uVar27 * 4 + 0x1d0);
                uVar20 = 0x113;
LAB_1c000c098:
                *puVar1 = uVar20;
                goto LAB_1c000ca79;
              }
              *(uint *)(p_Var32 + 0x284) =
                   *(uint *)(p_Var32 + 0x284) |
                   *(uint *)(p_Var32 + (ulonglong)(byte)param_2[6] * 4 + 0x248);
LAB_1c000ca4f:
              p_Var24 = p_Var32 + ((longlong)(int)(uint)(byte)param_2[6] >> 3) + 0x1ae0;
              uVar33 = (byte)param_2[6] & 7;
              _Var15 = *p_Var24;
              *p_Var24 = (_IDE_CHANNEL)((byte)*p_Var24 | '\x01' << uVar33);
              if (((byte)_Var15 >> uVar33 & 1) != 0) goto LAB_1c000c068;
              uVar27 = 0;
              *puVar1 = 0x115;
              goto LAB_1c000ca6d;
            }
            if (_Var4 == (_SCSI_REQUEST_BLOCK)0x24) {
              if (((byte)param_2[4] & 1) != 0) {
                *(undefined4 *)(local_90 + 0x180) = *(undefined4 *)(param_2 + 0x40);
                *(undefined4 *)(local_90 + 0x184) = *(undefined4 *)(param_2 + 8);
              }
            }
            else if (_Var4 == (_SCSI_REQUEST_BLOCK)0x25) {
              if ((*(uint *)(param_2 + 0x40) & 1) == 0) {
                if ((*(int *)(param_2 + 8) != 9) || (*(int *)(param_2 + 0x10) != 0x18)) {
                  uVar27 = 6;
                  goto LAB_1c000bade;
                }
                puVar10 = *(undefined2 **)(param_2 + 0x18);
                uVar33 = *(uint *)(puVar10 + 2);
                *puVar10 = 1;
                uVar23 = uVar33 & 0xfffffff8;
                *(uint *)(puVar10 + 2) = uVar23;
                if ((*(byte *)((longlong)&AmdSataInternal +
                              ((longlong)(int)(uint)(byte)param_2[5] >> 3)) >>
                     ((byte)param_2[5] & 7) & 1) == 0) {
                  *(uint *)(puVar10 + 2) =
                       ((uint)*(byte *)((longlong)local_a0 + 0x333) << 4 ^ uVar23) & 0x10 ^ uVar23;
                }
                else {
                  *(uint *)(puVar10 + 2) = uVar33 & 0xffffffe8;
                }
                *(uint *)(puVar10 + 2) = *(uint *)(puVar10 + 2) & 0xfffff91f;
                *(int *)(puVar10 + 4) = local_a0[1];
              }
            }
            else if (_Var4 == (_SCSI_REQUEST_BLOCK)0x26) {
              if (*(uint *)(param_2 + 0x10) < 0x70) goto LAB_1c000c0e4;
              puVar26 = *(undefined4 **)(param_2 + 0x18);
              *puVar26 = 0x700100;
              puVar26[0x14] = 0x20000;
              puVar26[0x15] = 0x21;
              *(_STOR_EXTENSION **)(puVar26 + 0x10) = local_90;
            }
            else if (_Var4 != (_SCSI_REQUEST_BLOCK)0x27) goto LAB_1c000c068;
LAB_1c000bb55:
            uVar27 = 1;
            goto LAB_1c000bade;
          }
          if (_Var4 == (_SCSI_REQUEST_BLOCK)0x17) {
            if (wmi != 0) {
              StartIoWmiSrb((longlong)local_90,(longlong)param_2);
              return '\x01';
            }
          }
          else {
            if (_Var4 == (_SCSI_REQUEST_BLOCK)0x2) {
              if (0x1b < *(uint *)(param_2 + 0x10)) {
                lVar8 = *(longlong *)(param_2 + 0x18);
                if (*(int *)(lVar8 + 0x10) != 0x1b0500) {
                  if (((param_2[7] == (_SCSI_REQUEST_BLOCK)0x0) && ((byte)param_2[5] < 0xf)) &&
                     ((byte)param_2[6] < 8)) {
                    local_b0 = &Unit + ((ulonglong)(byte)param_2[5] * 0xf +
                                       (ulonglong)(byte)param_2[6]) * 0x1c;
                  }
                  else {
                    local_b0 = (_UNIT **)0x0;
                  }
                  uVar33 = *(uint *)(lVar8 + 0x10);
                  *(undefined4 *)(lVar8 + 0x14) = 0xc0000001;
                  uVar23 = *(uint *)(param_2 + 0x10);
                  uVar27 = (ulonglong)uVar23;
                  if (uVar23 < 0x1c) {
LAB_1c000c893:
                    *(undefined4 *)(param_2 + 0x10) = 0;
                    uVar27 = 0x12;
                  }
                  else if (uVar33 == 0x1b0501) {
                    lVar12 = *(longlong *)(param_2 + 0x18);
                    if ((lVar12 == 0) || (uVar27 - 0x1c < 0x210)) goto LAB_1c000c893;
                    cVar5 = *(char *)(lVar12 + 0x26);
                    if (cVar5 == -1) {
                      *(undefined8 *)(lVar12 + 0x1c) = 0;
                      *(undefined8 *)(lVar12 + 0x24) = 0;
                      *(undefined1 *)(lVar12 + 0x2c) = 0;
                      memcpy((void *)(lVar12 + 0x2c),local_a0 + 6,0x200);
                      *(undefined4 *)(lVar12 + 0x1c) = 0x200;
                      *(undefined1 *)(lVar12 + 0x20) = 0;
                      goto LAB_1c000c867;
                    }
                    if (cVar5 == -0x14) {
                      *(undefined1 *)(lVar29 + 0xa2) = 0xec;
                    }
                    else {
                      if (cVar5 != -0x5f) goto LAB_1c000c720;
                      *(undefined1 *)(lVar29 + 0xa2) = 0xa1;
                    }
LAB_1c000c7eb:
                    *(undefined4 *)(lVar29 + 0x44) = 0x2c;
                    *puVar1 = 0x105;
                    *(undefined4 *)(lVar29 + 0x50) = 0x200;
                    *(undefined4 *)(lVar29 + 0x48) = 0x44;
LAB_1c000c790:
                    *(undefined1 *)(lVar29 + 0x3a) = 0;
LAB_1c000c7d6:
                    uVar27 = 0;
                  }
                  else if (uVar33 < 0x1b0502) {
LAB_1c000c80e:
                    uVar27 = 6;
                  }
                  else {
                    if (uVar33 < 0x1b050a) {
LAB_1c000c6a4:
                      if ((*(byte *)(local_a0 + 0x2f) & 1) == 0) {
LAB_1c000c6b0:
                        uVar18 = ' ';
                      }
                      else {
                        lVar8 = *(longlong *)(param_2 + 0x18);
                        if (uVar23 < 0x3d) goto LAB_1c000c893;
                        if (((*(char *)(lVar8 + 0x26) == -0x50) && (*(char *)(lVar8 + 0x23) == 'O'))
                           && (*(char *)(lVar8 + 0x24) == -0x3e)) {
                          *(undefined1 *)(lVar29 + 0xa2) = 0xb0;
                          *(undefined2 *)(lVar29 + 0x9f) = 0xc24f;
                          *(undefined1 *)(lVar29 + 0x9c) = *(undefined1 *)(lVar8 + 0x20);
                          bVar19 = *(byte *)(lVar8 + 0x20);
                          if (0xcf < bVar19) {
                            if (bVar19 < 0xd2) {
                              if (0x22b < *(uint *)(param_2 + 0x10)) goto LAB_1c000c7eb;
                              goto LAB_1c000c893;
                            }
                            if ((byte)(bVar19 + 0x2e) < 3) {
LAB_1c000c796:
                              if (bVar19 == 0xda) {
                                if (*(uint *)(param_2 + 0x10) < 0x34) {
                                  *(undefined4 *)(param_2 + 0x10) = 0;
                                }
                                *(undefined1 **)(lVar29 + 0x78) = (undefined1 *)(lVar29 + 0x9c);
                                *(undefined1 *)(lVar29 + 0x41) = 0x10;
                              }
                              if ((*(char *)(lVar8 + 0x20) == -0x2c) &&
                                 (*(undefined1 *)(lVar29 + 0x9e) = *(undefined1 *)(lVar8 + 0x22),
                                 *(char *)(lVar8 + 0x20) == -0x2c)) {
                                *(undefined1 *)(lVar29 + 0x9d) = *(undefined1 *)(lVar8 + 0x21);
                              }
                              uVar20 = 0x105;
                              goto LAB_1c000c7d2;
                            }
                            if (0xd4 < bVar19) {
                              if (bVar19 < 0xd7) {
                                iVar22 = (uint)*(byte *)(lVar8 + 0x21) * 0x200;
                                if (iVar22 + 0x2cU <= *(uint *)(param_2 + 0x10)) {
                                  *(undefined1 *)(lVar29 + 0x9e) = *(undefined1 *)(lVar8 + 0x22);
                                  *(undefined1 *)(lVar29 + 0x9d) = *(undefined1 *)(lVar8 + 0x21);
                                  *puVar1 = 0x105;
                                  if (*(char *)(lVar8 + 0x20) == -0x2b) {
                                    *(undefined4 *)(lVar29 + 0x44) = 0x2c;
                                    *(undefined4 *)(lVar29 + 0x48) = 0x44;
                                  }
                                  else {
                                    *(undefined4 *)(lVar29 + 0x44) = 0x3c;
                                    *(undefined4 *)(lVar29 + 0x48) = 0x84;
                                  }
                                  *(int *)(lVar29 + 0x50) = iVar22;
                                  goto LAB_1c000c790;
                                }
                                goto LAB_1c000c893;
                              }
                              if ((byte)(bVar19 + 0x28) < 3) goto LAB_1c000c796;
                            }
                          }
                        }
LAB_1c000c720:
                        uVar18 = '$';
                      }
                      bVar19 = InvalidCommandAutoSense(param_2,uVar18);
                      uVar27 = (ulonglong)bVar19;
                      goto LAB_1c000c89b;
                    }
                    if (uVar33 < 0x1b050b) goto LAB_1c000c80e;
                    if (uVar33 < 0x1b050d) goto LAB_1c000c6a4;
                    if (uVar33 != 0x1b0600) {
                      if (uVar33 == 0x1b0779) {
                        if ((*(longlong *)(param_2 + 0x18) != 0) && (3 < uVar27 - 0x1c)) {
                          uVar33 = *(uint *)(*(longlong *)(param_2 + 0x18) + 0x1c);
                          bVar19 = 0;
                          bVar30 = 0;
                          if ((uVar33 & 1) != 0) {
                            bVar19 = 1;
                            if ((uVar33 & 2) != 0) {
                              bVar19 = 3;
                            }
                            bVar19 = bVar19 & (byte)p_Var32[200];
                          }
                          if ((uVar33 & 2) != 0) {
                            bVar30 = *(byte *)((longlong)local_a0 + 0x32f) & (byte)p_Var32[0xc9] & 3
                            ;
                          }
                          uVar20 = 0x117;
                          *(byte *)(lVar29 + 0xa2) = bVar19;
                          *(byte *)(lVar29 + 0x9d) = (byte)(uVar33 >> 2) & 1;
                          *(byte *)(lVar29 + 0x9c) = bVar30;
LAB_1c000c7d2:
                          *puVar1 = uVar20;
                          goto LAB_1c000c7d6;
                        }
                      }
                      else {
                        if (uVar33 != 0x1b0789) goto LAB_1c000c80e;
                        lVar12 = *(longlong *)(param_2 + 0x18);
                        if ((lVar12 != 0) && (7 < uVar27 - 0x1c)) {
                          iVar22 = *(int *)(lVar12 + 0x1c);
                          if (iVar22 == 1) {
                            if ((char)*(byte *)(lVar12 + 0x20) < '\0') {
                              *(byte *)((longlong)local_a0 + 0x32f) =
                                   *(byte *)(lVar12 + 0x20) & 0x7f;
                            }
                            else {
                              *(undefined1 *)((longlong)local_a0 + 0x32f) = 0xff;
                            }
                          }
                          else if (iVar22 == 2) {
                            *(undefined1 *)((longlong)local_a0 + 0x483) =
                                 *(undefined1 *)(lVar12 + 0x20);
                            *(undefined1 *)(local_a0 + 0x121) = 1;
                          }
                          else {
                            if ((iVar22 != 3) || (uVar27 - 0x1c < 8)) goto LAB_1c000c403;
                            *(undefined8 *)(lVar12 + 0x20) = *(undefined8 *)(local_a0 + 0x2c);
                          }
LAB_1c000c867:
                          *(undefined4 *)(lVar8 + 0x14) = 0;
                          goto LAB_1c000c403;
                        }
                      }
                      goto LAB_1c000c893;
                    }
                    if (hhdd == 0) goto LAB_1c000c6b0;
                    puVar3 = (undefined1 *)(lVar29 + 0x9c);
                    *(undefined1 **)(lVar29 + 0x78) = puVar3;
                    *(undefined1 *)(lVar29 + 0x41) = 0x10;
                    if ((((*(uint *)(param_2 + 0x10) < 0x4c) ||
                         (piVar13 = *(int **)(param_2 + 0x18), *piVar13 != 0x1c)) ||
                        (piVar13[7] != 0x30)) ||
                       ((ulonglong)*(uint *)(param_2 + 0x10) < (ulonglong)(uint)piVar13[0xf] + 0x4c)
                       ) goto LAB_1c000c893;
                    if ((short)piVar13[8] == 0xec) {
                      if ((uint)piVar13[0xf] < 0x18) {
                        piVar13[10] = 4;
                      }
                      else {
                        *(ushort *)(piVar13 + 0x13) = *(ushort *)(local_a0 + 0x71) & 1;
                        *(ushort *)((longlong)piVar13 + 0x4e) =
                             *(ushort *)(local_a0 + 0x71) >> 1 & 7;
                        *(ushort *)(piVar13 + 0x14) = *(ushort *)(local_a0 + 0x71) >> 4 & 1;
                        *(ushort *)((longlong)piVar13 + 0x52) =
                             *(ushort *)(local_a0 + 0x71) >> 5 & 7;
                        *(ushort *)(piVar13 + 0x15) =
                             (ushort)(*(byte *)((longlong)local_a0 + 0x1c5) & 0xf);
                        *(ushort *)((longlong)piVar13 + 0x56) = *(ushort *)(local_a0 + 0x71) >> 0xc;
                        piVar13[0x16] = *(int *)((longlong)local_a0 + 0x1c6);
                        *(undefined2 *)(piVar13 + 0x17) =
                             *(undefined2 *)((longlong)local_a0 + 0x1ca);
                        *(short *)((longlong)piVar13 + 0x5e) = (short)local_a0[0x73];
                        piVar13[0x18] = (uint)*(byte *)((longlong)local_a0 + 0x1ce);
                        piVar13[10] = 0;
                      }
LAB_1c000c403:
                      uVar27 = 1;
                      goto LAB_1c000c89b;
                    }
                    *puVar1 = 0x100;
                    *(undefined1 *)(lVar29 + 0xa2) = 0xb6;
                    *puVar3 = (char)piVar13[8];
                    sVar7 = (short)piVar13[8];
                    if (sVar7 == 0) {
                      *(char *)(lVar29 + 0x9d) = (char)piVar13[0xb];
                      *(char *)(lVar29 + 0xa5) = (char)((uint)piVar13[0xb] >> 8);
LAB_1c000c646:
                      piVar13[10] = 0;
                    }
                    else {
                      if (sVar7 == 1) goto LAB_1c000c646;
                      if (sVar7 == 0x14) {
                        *(char *)(lVar29 + 0x9e) = (char)piVar13[0xd];
                        *(char *)(lVar29 + 0x9f) = (char)((uint)piVar13[0xd] >> 8);
                        *(char *)(lVar29 + 0xa0) = (char)((uint)piVar13[0xd] >> 0x10);
                        *(char *)(lVar29 + 0xa6) = (char)((uint)piVar13[0xd] >> 0x18);
                        goto LAB_1c000c646;
                      }
                      if (sVar7 == 0x12) {
                        uVar33 = ((piVar13[0xb] - 1U & 0xffff) + 1) * 0x200;
                        if ((uint)piVar13[0xf] < uVar33) goto LAB_1c000c4a7;
                        if (uVar33 < (uint)piVar13[0xf]) goto LAB_1c000c4b1;
                        *(char *)(lVar29 + 0x9e) = (char)piVar13[0xd];
                        *(char *)(lVar29 + 0x9f) = (char)((uint)piVar13[0xd] >> 8);
                        *(char *)(lVar29 + 0xa0) = (char)((uint)piVar13[0xd] >> 0x10);
                        *(char *)(lVar29 + 0xa6) = (char)((uint)piVar13[0xd] >> 0x18);
                        *(char *)(lVar29 + 0xa7) =
                             (char)((ulonglong)*(undefined8 *)(piVar13 + 0xd) >> 0x20);
                        *(char *)(lVar29 + 0xa8) =
                             (char)((ulonglong)*(undefined8 *)(piVar13 + 0xd) >> 0x28);
                        *(char *)(lVar29 + 0x9d) = (char)piVar13[0xb];
                        *(char *)(lVar29 + 0xa5) = (char)((uint)piVar13[0xb] >> 8);
                        *(uint *)(lVar29 + 0x50) = uVar33;
LAB_1c000c515:
                        *(undefined4 *)(lVar29 + 0x44) = 0x4c;
                        *(undefined4 *)(lVar29 + 0x48) = 0x40;
                        goto LAB_1c000c646;
                      }
                      if (sVar7 == 0x13) {
                        if ((piVar13[0xb] == 1) && (0x1ff < (uint)piVar13[0xf])) {
                          *(undefined1 *)(lVar29 + 0x9d) = 1;
                          *(undefined4 *)(lVar29 + 0x50) = 0x200;
                          goto LAB_1c000c515;
                        }
LAB_1c000c54d:
                        piVar13[10] = 2;
                      }
                      else {
                        if (sVar7 != 0x10) {
                          if (sVar7 == 0x11) {
                            iVar22 = (piVar13[0xb] - 1U & 0xffff) + 1;
                            if (((*(ulonglong *)(piVar13 + 0xd) & 1) == 0) &&
                               ((uint)piVar13[0xf] < (uint)(iVar22 * 0x200))) goto LAB_1c000c4a7;
                            if (((*(ulonglong *)(piVar13 + 0xd) & 1) == 0) &&
                               ((uint)(iVar22 * 0x200) < (uint)piVar13[0xf])) goto LAB_1c000c4b1;
                            iVar22 = iVar22 * 0x200;
                            *(byte *)(lVar29 + 0x9e) = *(byte *)(piVar13 + 0xd) & 1;
                            *(char *)(lVar29 + 0x9d) = (char)piVar13[0xb];
                            *(char *)(lVar29 + 0xa5) = (char)((uint)piVar13[0xb] >> 8);
                            *(undefined4 *)(lVar29 + 0x44) = 0x4c;
                            if ((*(byte *)(piVar13 + 0xd) & 1) != 0) {
                              iVar22 = 0;
                            }
                            *(int *)(lVar29 + 0x50) = iVar22;
                            *(uint *)(lVar29 + 0x48) =
                                 ~(uint)(*(longlong *)(piVar13 + 0xd) << 7) & 0x80;
                          }
                          else {
                            if (sVar7 != 0xe5) {
                              if ((sVar7 == 0xe0) &&
                                 (*(uint *)(param_2 + 0x10) < piVar13[0xb] * 0x200 + 0x5cU)) {
                                if (0x2b < *(uint *)(param_2 + 0x10)) {
                                  piVar13[10] = 4;
                                }
                                uVar27 = 0x15;
                                goto LAB_1c000c89b;
                              }
                              piVar13[10] = 1;
                              goto LAB_1c000c685;
                            }
                            *(undefined1 *)(lVar29 + 0xa2) = 0xe5;
                            *puVar3 = 0;
                          }
                          goto LAB_1c000c646;
                        }
                        iVar22 = (piVar13[0xb] - 1U & 0xffff) + 1;
                        if (iVar22 == 0) goto LAB_1c000c54d;
                        uVar33 = iVar22 * 0x200;
                        if ((uint)piVar13[0xf] < uVar33) {
LAB_1c000c4a7:
                          iVar22 = 4;
                        }
                        else {
                          if ((uint)piVar13[0xf] <= uVar33) {
                            *(byte *)(lVar29 + 0x9e) = *(byte *)(piVar13 + 0xd) & 1;
                            *(char *)(lVar29 + 0x9d) = (char)piVar13[0xb];
                            *(char *)(lVar29 + 0xa5) = (char)((uint)piVar13[0xb] >> 8);
                            *(undefined4 *)(lVar29 + 0x44) = 0x4c;
                            *(uint *)(lVar29 + 0x50) = uVar33;
                            *(undefined4 *)(lVar29 + 0x48) = 0x80;
                            goto LAB_1c000c646;
                          }
LAB_1c000c4b1:
                          iVar22 = 3;
                        }
                        piVar13[10] = iVar22;
                      }
                    }
LAB_1c000c685:
                    if (piVar13[10] == 0) {
                      uVar27 = 0;
                      piVar13[5] = 0;
                    }
                    else {
                      uVar27 = 1;
                      piVar13[5] = -0x3effffff;
                    }
                  }
LAB_1c000c89b:
                  pp_Var17 = local_b0;
                  if ((local_b0 != (_UNIT **)0x0) && (*(char *)((longlong)local_b0 + 0xd3) != '\0'))
                  {
                    if ((char)uVar27 != '\0') goto LAB_1c000bade;
                    local_c0 = 0;
                    local_c8 = 0;
                    StorPortExtendedFunction(0x31,local_90,local_b0,param_2);
                    *(int *)(pp_Var17 + 0x1b) = *(int *)(pp_Var17 + 0x1b) + 1;
                  }
                  goto LAB_1c000ca6d;
                }
                if (0x33 < *(uint *)(param_2 + 0x10)) {
                  *(undefined8 *)(lVar8 + 0x1c) = 0;
                  *(undefined8 *)(lVar8 + 0x24) = 0;
                  *(undefined8 *)(lVar8 + 0x2c) = 0;
                  *(undefined4 *)(lVar8 + 0x20) = 7;
                  *(undefined2 *)(lVar8 + 0x1c) = 0x101;
                  *(undefined1 *)(lVar8 + 0x1e) = 0;
                  goto LAB_1c000bb55;
                }
              }
              *(undefined4 *)(param_2 + 0x10) = 0;
LAB_1c000c0e4:
              uVar27 = 0x12;
              goto LAB_1c000bade;
            }
            if (_Var4 == (_SCSI_REQUEST_BLOCK)0x7) {
              *puVar1 = 0x402;
              if (((param_2[0x48] == (_SCSI_REQUEST_BLOCK)0x1b) && (((byte)param_2[0x4c] & 1) == 0))
                 && (((byte)param_2[0x49] & 1) == 0)) {
                *(undefined4 *)(lVar29 + 0x48) = 0x80000000;
              }
              goto LAB_1c000ca79;
            }
            if (_Var4 == (_SCSI_REQUEST_BLOCK)0x8) {
              uVar20 = 0x104;
              goto LAB_1c000c098;
            }
            if (_Var4 == (_SCSI_REQUEST_BLOCK)0x12) {
              uVar18 = HwStorResetBus(local_90,(uint)(byte)param_2[5]);
              uVar27 = (ulonglong)(byte)((-(uVar18 != '\0') & 0xf7U) + 10);
              goto LAB_1c000bade;
            }
            if (_Var4 == (_SCSI_REQUEST_BLOCK)0x13) goto LAB_1c000ca4f;
          }
LAB_1c000c068:
          bVar19 = InvalidCommandAutoSense(param_2,' ');
LAB_1c000c072:
          uVar27 = (ulonglong)bVar19;
        }
LAB_1c000ca6d:
        if ((char)uVar27 == '\0') {
LAB_1c000ca79:
          if (2 < *(int *)(local_a8 + 0x24)) {
            *(uint *)(lVar29 + 0x48) = *(uint *)(lVar29 + 0x48) | 0x200;
          }
          AhciHwStartIo((longlong)(p_Var32 + 0x98),puVar1);
          return '\x01';
        }
      }
LAB_1c000bade:
      param_2[3] = SUB81(uVar27,0);
      goto LAB_1c000bae5;
    }
  }
LAB_1c000ba0f:
  param_2[3] = _Var31;
LAB_1c000bae5:
  StorPortNotification(0,local_90,param_2);
  return '\x01';
}



===== HwStorInterrupt @ 1c000caa0 =====

/* unsigned char __cdecl HwStorInterrupt(void * __ptr64) */

uchar __cdecl HwStorInterrupt(void *param_1)

{
  ulonglong uVar1;
  
  uVar1 = AhciHwIRQ(*(longlong *)((longlong)param_1 + 0x228));
  return (uchar)uVar1;
}



===== HwMSInterruptRoutine @ 1c000cab0 =====

/* unsigned char __cdecl HwMSInterruptRoutine(void * __ptr64,unsigned long) */

uchar __cdecl HwMSInterruptRoutine(void *param_1,ulong param_2)

{
  longlong lVar1;
  uint uVar2;
  byte *pbVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  bool bVar6;
  uint local_res8 [8];
  
  lVar1 = *(longlong *)((longlong)param_1 + 0x228);
  if ((MSISingle == 0) && ((*(uint *)(lVar1 + 0x2c) & 4) == 0)) {
    if (param_2 == *(ulong *)(lVar1 + 0x44)) {
      local_res8[0] = *(uint *)(lVar1 + 0x38);
      uVar2 = 0;
      bVar6 = local_res8[0] != 0;
      if (bVar6) {
        for (; (local_res8[0] >> uVar2 & 1) == 0; uVar2 = uVar2 + 1) {
        }
      }
      MSISingle = 0;
      while (bVar6) {
        pbVar3 = (byte *)((longlong)local_res8 + ((longlong)(int)uVar2 >> 3));
        *pbVar3 = *pbVar3 & ~('\x01' << (uVar2 & 7));
        AhciHwChannelInterrupt(*(longlong *)(lVar1 + 0x60 + (ulonglong)uVar2 * 8));
        uVar2 = 0;
        bVar6 = local_res8[0] != 0;
        if (bVar6) {
          for (; (local_res8[0] >> uVar2 & 1) == 0; uVar2 = uVar2 + 1) {
          }
        }
      }
      return *(int *)(lVar1 + 0x38) != 0;
    }
    if (param_2 <= MSIMaxMSG) {
      uVar4 = AhciHwChannelInterrupt(*(longlong *)(lVar1 + 0x60 + (ulonglong)param_2 * 8));
      return (uchar)uVar4;
    }
  }
  uVar5 = AhciHwIRQ(lVar1);
  return (uchar)uVar5;
}



===== IsDxCapable @ 1c000cb2c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned char __cdecl IsDxCapable(struct _STOR_EXTENSION * __ptr64,struct _STOR_ADDR_BTL8 *
   __ptr64) */

uchar __cdecl IsDxCapable(_STOR_EXTENSION *param_1,_STOR_ADDR_BTL8 *param_2)

{
  int iVar1;
  bool bVar2;
  undefined1 auStack_88 [32];
  undefined4 *local_68;
  undefined4 local_60;
  undefined4 *local_58;
  undefined4 local_50;
  undefined1 *local_48;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 local_30 [8];
  undefined4 local_28;
  undefined8 local_24;
  undefined8 local_1c;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_88;
  local_38 = 0x42696541;
  local_34 = 0x3053505f;
  local_28 = 0;
  local_24 = 0;
  local_1c = 0;
  local_48 = local_30;
  local_58 = &local_28;
  local_50 = 0x14;
  local_68 = &local_38;
  local_60 = 8;
  iVar1 = StorPortExtendedFunction(0x1b,param_1,param_2,0x3353505f);
  if (iVar1 == 0) {
    bVar2 = true;
  }
  else {
    local_48 = local_30;
    local_50 = 0x14;
    local_58 = &local_28;
    local_68 = &local_38;
    local_60 = 8;
    iVar1 = StorPortExtendedFunction(0x1b,param_1,param_2,0x3352505f);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}



===== AhciPortAcpiDSMControl @ 1c000cc34 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned long __cdecl AhciPortAcpiDSMControl(struct _STOR_EXTENSION * __ptr64,unsigned
   long,unsigned char) */

ulong __cdecl AhciPortAcpiDSMControl(_STOR_EXTENSION *param_1,ulong param_2,uchar param_3)

{
  int iVar1;
  ulong uVar2;
  undefined1 auStack_d8 [32];
  undefined4 *local_b8;
  undefined4 local_b0;
  undefined4 *local_a8;
  undefined4 local_a0;
  undefined4 *local_98;
  undefined4 local_88 [2];
  undefined4 local_80;
  undefined8 local_7c;
  undefined8 local_74;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  uint local_2c;
  undefined4 local_28;
  undefined4 local_24;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_d8;
  local_88[0] = 0;
  memset((void *)((longlong)&local_68 + 1),0,0x47);
  local_68 = 0x43696541;
  local_38 = 2;
  local_60 = 0x48;
  local_58 = 0x100002;
  local_64 = 0x4d53445f;
  local_5c = 4;
  local_44 = 0x40000;
  local_40 = 1;
  local_3c = 0x40000;
  local_34 = 0x100004;
  local_30 = 0x40000;
  local_54 = 0xe4db149b;
  uStack_50 = 0x425bfcfe;
  uStack_4c = 0x3592d8a6;
  uStack_48 = 0x7ffc787d;
  if (param_2 == 0xffffffff) {
    local_2c = 0xffffffff;
  }
  else {
    local_2c = param_2 << 0x10 | 0xffff;
  }
  local_28 = 0x40000;
  local_7c = 0;
  local_74 = 0;
  local_98 = local_88;
  local_a8 = &local_80;
  local_a0 = 0x14;
  local_b8 = &local_68;
  local_b0 = 0x48;
  local_24 = 1;
  local_80 = 0;
  iVar1 = StorPortExtendedFunction(0x1b,param_1);
  uVar2 = 0xf;
  if (iVar1 == 0) {
    uVar2 = local_74._4_4_;
  }
  return uVar2;
}



===== acpi @ 1c000cd6c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned long __cdecl acpi(struct _STOR_EXTENSION * __ptr64,struct _STOR_ADDR_BTL8 * __ptr64) */

ulong __cdecl acpi(_STOR_EXTENSION *param_1,_STOR_ADDR_BTL8 *param_2)

{
  undefined1 *puVar1;
  int *piVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  uint uVar6;
  _UNIT **pp_Var7;
  _STOR_ADDR_BTL8 *p_Var8;
  longlong lVar9;
  int *piVar10;
  ulong uVar11;
  undefined1 auStack_e8 [32];
  int **local_c8;
  undefined4 local_c0;
  int *local_b8;
  undefined4 local_b0;
  undefined1 *local_a8;
  longlong local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined1 local_88 [8];
  int *local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  int local_58 [6];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_e8;
  uVar11 = 0xc1000001;
  if (((param_2[10] == (_STOR_ADDR_BTL8)0x0) && ((byte)param_2[8] < 0xf)) && ((byte)param_2[9] < 8))
  {
    pp_Var7 = &Unit + ((ulonglong)(byte)param_2[8] * 0xf + (ulonglong)(byte)param_2[9]) * 0x1c;
  }
  else {
    pp_Var7 = (_UNIT **)0x0;
  }
  if (pp_Var7 != (_UNIT **)0x0) {
    local_58[0] = 0;
    local_58[1] = 0;
    local_58[2] = 0;
    local_58[3] = 0;
    local_58[4] = 0;
    local_a8 = local_88;
    local_90 = 0x42696541;
    local_b0 = 0x14;
    local_b8 = local_58;
    local_c8 = (int **)&local_90;
    local_c0 = 8;
    local_8c = 0x5244415f;
    p_Var8 = param_2;
    iVar3 = StorPortExtendedFunction(0x1b,param_1);
    if ((iVar3 == 0) && ((short)local_58[4] == -1)) {
      uVar4 = AhciPortAcpiDSMControl(param_1,(uint)local_58[4] >> 0x10,(uchar)p_Var8);
      *(bool *)((longlong)pp_Var7 + 0xd1) = uVar4 == 0;
    }
    local_c8 = &local_80;
    iVar3 = StorPortExtendedFunction(0,param_1,0x400,0x41534841);
    piVar2 = local_80;
    if (iVar3 == 0) {
      local_c8 = (int **)&local_78;
      *local_80 = 0x43696541;
      local_80[1] = 0x4444535f;
      local_80[2] = 0x214;
      local_80[3] = 1;
      local_80[4] = 0x2000002;
      local_78 = 0;
      local_70 = 0;
      local_68 = 0;
      local_60 = 0;
      StorPortNotification(0x1003,param_1,2,0);
      if ((byte)param_2[8] < 8) {
        local_98 = *(longlong *)
                    (param_1 +
                    ((ulonglong)(byte)param_2[8] * 0x371 + (ulonglong)(byte)param_2[9]) * 8 + 0x1ef0
                    );
      }
      else {
        local_98 = 0;
      }
      if (local_98 != 0) {
        memcpy(piVar2 + 5,(void *)(local_98 + 0x18),0x200);
      }
      StorPortNotification(0x1004,param_1,&local_78);
      if (local_98 != 0) {
        local_a8 = local_88;
        local_b0 = 0;
        local_c8 = (int **)&local_90;
        local_b8 = (int *)0x0;
        local_c0 = 8;
        StorPortExtendedFunction(0x1b,param_1,param_2,0x4444535f);
        piVar2 = local_80;
        local_a8 = local_88;
        local_b0 = 0x400;
        local_c8 = (int **)&local_90;
        local_b8 = local_80;
        local_c0 = 8;
        local_90 = 0x42696541;
        local_8c = 0x4654475f;
        iVar3 = StorPortExtendedFunction(0x1b,param_1,param_2);
        if (((iVar3 == 0) && (*piVar2 == 0x426f6541)) &&
           ((piVar2[2] == 1 &&
            (((short)piVar2[3] == 2 &&
             ((uint)*(ushort *)((longlong)piVar2 + 0xe) ==
              (*(ushort *)((longlong)piVar2 + 0xe) / 7) * 7)))))) {
          local_c8 = (int **)&local_78;
          piVar10 = piVar2 + 4;
          StorPortNotification(0x1003,param_1,2,0);
          local_98 = *(longlong *)
                      (param_1 +
                      ((ulonglong)(byte)param_2[8] * 0x371 + (ulonglong)(byte)param_2[9]) * 8 +
                      0x1ef0);
          if (local_98 != 0) {
            *(undefined4 *)(local_98 + 0x374) = 0;
            lVar9 = 0x80;
            iVar3 = 0x10;
            while( true ) {
              uVar6 = *(ushort *)((longlong)piVar2 + 0xe) / 7;
              if (0x10 < uVar6) {
                uVar6 = 0x10;
              }
              if ((int)(uVar6 + 0x10) <= iVar3) break;
              *(uint *)(local_98 + 0x374) = *(uint *)(local_98 + 0x374) | 1 << ((byte)iVar3 & 0x1f);
              *(char *)(local_98 + 0x378 + lVar9) = (char)*piVar10;
              *(undefined1 *)(local_98 + 0x379 + lVar9) = *(undefined1 *)((longlong)piVar10 + 1);
              *(undefined1 *)(local_98 + 0x37a + lVar9) = *(undefined1 *)((longlong)piVar10 + 2);
              *(undefined1 *)(local_98 + 0x37b + lVar9) = *(undefined1 *)((longlong)piVar10 + 3);
              *(char *)(local_98 + 0x37c + lVar9) = (char)piVar10[1];
              *(undefined1 *)(local_98 + 0x37d + lVar9) = *(undefined1 *)((longlong)piVar10 + 5);
              puVar1 = (undefined1 *)((longlong)piVar10 + 6);
              piVar10 = (int *)((longlong)piVar10 + 7);
              *(undefined1 *)(local_98 + 0x37e + lVar9) = *puVar1;
              *(undefined1 *)(local_98 + 0x37f + lVar9) = 0;
              lVar9 = lVar9 + 8;
              iVar3 = iVar3 + 1;
            }
            if (*(int *)(local_98 + 0x374) != 0) {
              *(undefined4 *)(local_98 + 0x370) = *(undefined4 *)(local_98 + 0x374);
              pp_Var7[2] = (_UNIT *)0x0;
              pp_Var7[3] = (_UNIT *)0x0;
              pp_Var7[5] = (_UNIT *)0x0;
              memset(pp_Var7 + 9,0,0x78);
              *(_STOR_ADDR_BTL8 *)((longlong)pp_Var7 + 0x4d) = param_2[8];
              *(_STOR_ADDR_BTL8 *)((longlong)pp_Var7 + 0x4e) = param_2[9];
              *(undefined2 *)(pp_Var7 + 9) = 0x11a;
              if (param_1[(ulonglong)(byte)param_2[8] * 0x1b88 + 0x478] != (_STOR_EXTENSION)0x0) {
                uVar5 = AhciHwStartIo((longlong)
                                      (param_1 + (ulonglong)(byte)param_2[8] * 0x1b88 + 0x480),
                                      (ushort *)(pp_Var7 + 9));
                uVar11 = 0xc1000001;
                if ((char)uVar5 != '\0') {
                  uVar11 = 0;
                }
              }
            }
          }
          StorPortNotification(0x1004,param_1,&local_78);
        }
      }
      StorPortExtendedFunction(1,param_1,local_80);
    }
  }
  return uVar11;
}



===== HwUnitControl @ 1c000d230 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* enum _SCSI_UNIT_CONTROL_STATUS __cdecl HwUnitControl(void * __ptr64,enum
   _SCSI_UNIT_CONTROL_TYPE,void * __ptr64) */

_SCSI_UNIT_CONTROL_STATUS __cdecl
HwUnitControl(void *param_1,_SCSI_UNIT_CONTROL_TYPE param_2,void *param_3)

{
  char cVar1;
  short *psVar2;
  byte *pbVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  _UNIT *p_Var7;
  _UNIT *p_Var8;
  uchar uVar9;
  int iVar10;
  _UNIT **pp_Var11;
  ushort uVar12;
  uint uVar13;
  _IDE_CHANNEL *p_Var14;
  bool bVar15;
  undefined1 local_168 [32];
  undefined8 *local_148;
  undefined1 local_138 [8];
  int *local_130;
  undefined8 local_128;
  undefined8 local_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 local_68;
  undefined8 local_60;
  undefined4 local_58;
  ulonglong local_48;
  undefined8 local_40;
  
  local_48 = __security_cookie ^ (ulonglong)local_168;
  if (param_2 == 0) {
    uVar13 = 0;
    if (*(int *)param_3 != 0) {
      do {
        if (uVar13 < 8) {
          *(undefined1 *)((ulonglong)uVar13 + 4 + (longlong)param_3) = 1;
        }
        else {
          *(undefined1 *)((ulonglong)uVar13 + 4 + (longlong)param_3) = 0;
        }
        uVar13 = uVar13 + 1;
      } while (uVar13 < *(uint *)param_3);
    }
  }
  else if (param_2 == 1) {
    psVar2 = *(short **)param_3;
    if (psVar2 == (short *)0x0) {
      return 1;
    }
    if (*psVar2 != 1) {
      return 1;
    }
    if ((((char)psVar2[5] == '\0') && (*(byte *)(psVar2 + 4) < 0xf)) &&
       (*(byte *)((longlong)psVar2 + 9) < 8)) {
      pp_Var11 = &Unit + ((ulonglong)*(byte *)(psVar2 + 4) * 0xf +
                         (ulonglong)*(byte *)((longlong)psVar2 + 9)) * 0x1c;
    }
    else {
      pp_Var11 = (_UNIT **)0x0;
    }
    if (pp_Var11 == (_UNIT **)0x0) {
      return 1;
    }
    uVar13 = 1 << ((byte)*(undefined4 *)((longlong)param_3 + 8) & 0x1f);
    if (*(char *)((longlong)param_3 + 0xc) == '\0') {
      *(uint *)((longlong)pp_Var11 + 0xc4) = *(uint *)((longlong)pp_Var11 + 0xc4) & ~uVar13;
    }
    else {
      *(uint *)((longlong)pp_Var11 + 0xc4) = *(uint *)((longlong)pp_Var11 + 0xc4) | uVar13;
    }
  }
  else if (param_2 == 2) {
    if (param_3 == (void *)0x0) {
      return 1;
    }
    if (*(short *)param_3 != 1) {
      return 1;
    }
    if (((*(char *)((longlong)param_3 + 10) == '\0') && (*(byte *)((longlong)param_3 + 8) < 0xf)) &&
       (*(byte *)((longlong)param_3 + 9) < 8)) {
      pp_Var11 = &Unit + ((ulonglong)*(byte *)((longlong)param_3 + 8) * 0xf +
                         (ulonglong)*(byte *)((longlong)param_3 + 9)) * 0x1c;
    }
    else {
      pp_Var11 = (_UNIT **)0x0;
    }
    if (pp_Var11 == (_UNIT **)0x0) {
      return 1;
    }
    p_Var7 = *(_UNIT **)param_3;
    p_Var8 = *(_UNIT **)((longlong)param_3 + 8);
    *(undefined4 *)((longlong)pp_Var11 + 0xc4) = 0;
    *(undefined1 *)((longlong)pp_Var11 + 0xd1) = 0;
    *pp_Var11 = p_Var7;
    pp_Var11[1] = p_Var8;
    pbVar3 = (byte *)((longlong)param_1 +
                     ((longlong)(int)(uint)*(byte *)((longlong)param_3 + 9) >> 3) +
                     (ulonglong)*(byte *)((longlong)param_3 + 8) * 0x1b88 + 0x46c);
    *pbVar3 = *pbVar3 | '\x01' << (*(byte *)((longlong)param_3 + 9) & 7);
    *(undefined1 *)((longlong)pp_Var11 + 0xd2) = 1;
    uVar9 = IsDxCapable(param_1,param_3);
    *(uchar *)(pp_Var11 + 0x1a) = uVar9;
    acpi(param_1,param_3);
    local_148 = &local_e8;
    local_e8 = 0;
    local_e0 = 0;
    local_d8 = 0;
    local_d0 = 0;
    uVar12 = (ushort)(*(char *)((longlong)pp_Var11 + 0xd1) == '\0') << 2;
    StorPortNotification(0x1003,param_1,2);
    if (*(byte *)((longlong)param_3 + 8) < 8) {
      local_130 = *(int **)((longlong)param_1 +
                           ((ulonglong)*(byte *)((longlong)param_3 + 8) * 0x371 +
                           (ulonglong)*(byte *)((longlong)param_3 + 9)) * 8 + 0x1ef0);
    }
    else {
      local_130 = (int *)0x0;
    }
    bVar15 = false;
    if (local_130 != (int *)0x0) {
      bVar15 = *local_130 == 0x101;
    }
    if (!bVar15) {
      bVar15 = false;
      if (local_130 != (int *)0x0) {
        bVar15 = *local_130 == -0x14ebfeff;
      }
      if (bVar15) {
        uVar12 = uVar12 ^ *(ushort *)((longlong)local_130 + 0xb2) >> 4 & 1 ^
                 (ushort)*(byte *)((longlong)local_130 + 0x47d) * 2 & 2;
      }
    }
    StorPortNotification(0x1004,param_1,&local_e8);
    StorPortExtendedFunction(0x2e,param_1,pp_Var11,uVar12);
  }
  else if (param_2 == 3) {
    psVar2 = *(short **)param_3;
    if (psVar2 == (short *)0x0) {
      return 1;
    }
    if (*psVar2 != 1) {
      return 1;
    }
    if (*(int *)(psVar2 + 2) != 4) {
      return 1;
    }
    if ((((char)psVar2[5] == '\0') && (*(byte *)(psVar2 + 4) < 0xf)) &&
       (*(byte *)((longlong)psVar2 + 9) < 8)) {
      pp_Var11 = &Unit + ((ulonglong)*(byte *)(psVar2 + 4) * 0xf +
                         (ulonglong)*(byte *)((longlong)psVar2 + 9)) * 0x1c;
    }
    else {
      pp_Var11 = (_UNIT **)0x0;
    }
    if (pp_Var11 == (_UNIT **)0x0) {
      return 1;
    }
    p_Var14 = (_IDE_CHANNEL *)((longlong)param_1 + (ulonglong)*(byte *)(psVar2 + 4) * 0x1b88 + 1000)
    ;
    if (*(int *)((longlong)param_3 + 0xc) == 1) {
      p_Var14[((longlong)(int)(uint)*(byte *)((longlong)psVar2 + 9) >> 3) + 0x84] =
           (_IDE_CHANNEL)
           ((byte)p_Var14[((longlong)(int)(uint)*(byte *)((longlong)psVar2 + 9) >> 3) + 0x84] |
           '\x01' << (*(byte *)((longlong)psVar2 + 9) & 7));
      local_148 = &local_108;
      local_108 = 0;
      local_100 = 0;
      local_f8 = 0;
      local_f0 = 0;
      StorPortNotification(0x1003,param_1,2);
      if ((*(char *)(pp_Var11 + 0x1a) != '\0') &&
         (local_130 = *(int **)((longlong)param_1 +
                               ((ulonglong)*(byte *)(psVar2 + 4) * 0x371 +
                               (ulonglong)*(byte *)((longlong)psVar2 + 9)) * 8 + 0x1ef0),
         local_130 != (int *)0x0)) {
        *(undefined1 *)((longlong)local_130 + 0x497) = 0;
      }
      if ((p_Var14[0x90] == (_IDE_CHANNEL)0x0) &&
         (uVar9 = AhciPortChannelStart(p_Var14), uVar9 != '\0')) {
        p_Var14[0x19d] = (_IDE_CHANNEL)(*(int *)(pp_Var11 + 0x19) == 0);
        AhciPortRequestSynchronizedRoutine((longlong)(p_Var14 + 0x98),AhciHwEnumerateBus);
      }
      StorPortNotification(0x1004,param_1,&local_108);
    }
    else {
      if (*(int *)((longlong)param_3 + 0xc) != 4) {
        return 1;
      }
      local_c8 = 0;
      local_148 = &local_c8;
      local_c0 = 0;
      local_b8 = 0;
      local_b0 = 0;
      StorPortNotification(0x1003,param_1,2);
      if (((*(int *)((longlong)param_3 + 8) != 3) ||
          ((*(uint *)((longlong)pp_Var11 + 0xc4) & 2) == 0)) && (*(char *)(pp_Var11 + 0x1a) != '\0')
         ) {
        p_Var14[((longlong)(int)(uint)*(byte *)((longlong)psVar2 + 9) >> 3) + 0x84] =
             (_IDE_CHANNEL)
             ((byte)p_Var14[((longlong)(int)(uint)*(byte *)((longlong)psVar2 + 9) >> 3) + 0x84] &
             ~('\x01' << (*(byte *)((longlong)psVar2 + 9) & 7)));
        if (*(byte *)(psVar2 + 4) < 8) {
          local_130 = *(int **)((longlong)param_1 +
                               ((ulonglong)*(byte *)(psVar2 + 4) * 0x371 +
                               (ulonglong)*(byte *)((longlong)psVar2 + 9)) * 8 + 0x1ef0);
        }
        else {
          local_130 = (int *)0x0;
        }
        if (local_130 != (int *)0x0) {
          *(undefined1 *)((longlong)local_130 + 0x497) = 3;
        }
      }
      if (*(int *)(p_Var14 + 0x84) == 0) {
        uVar13 = *(uint *)(*(longlong *)(p_Var14 + 0x1988) + 0x14);
        p_Var14[0x90] = (_IDE_CHANNEL)0x0;
        *(uint *)(*(longlong *)(p_Var14 + 0x1988) + 0x14) = uVar13 & 0xffbfffff;
        LOCK();
        UNLOCK();
      }
      StorPortNotification(0x1004,param_1,&local_c8);
      *(undefined4 *)((longlong)pp_Var11 + 0xcc) = *(undefined4 *)((longlong)param_3 + 0xc);
      *(undefined4 *)(pp_Var11 + 0x19) = *(undefined4 *)((longlong)param_3 + 8);
    }
  }
  else if (param_2 == 4) {
    psVar2 = *(short **)((longlong)param_3 + 8);
    if (psVar2 == (short *)0x0) {
      return 1;
    }
    if (*psVar2 != 1) {
      return 1;
    }
    if (*(int *)(psVar2 + 2) != 4) {
      return 1;
    }
    if ((((char)psVar2[5] == '\0') && (*(byte *)(psVar2 + 4) < 0xf)) &&
       (*(byte *)((longlong)psVar2 + 9) < 8)) {
      pp_Var11 = &Unit + ((ulonglong)*(byte *)(psVar2 + 4) * 0xf +
                         (ulonglong)*(byte *)((longlong)psVar2 + 9)) * 0x1c;
    }
    else {
      pp_Var11 = (_UNIT **)0x0;
    }
    if (pp_Var11 == (_UNIT **)0x0) {
      return 1;
    }
    cVar1 = *(char *)((longlong)param_3 + 0x10);
    if (*(char *)((longlong)pp_Var11 + 0xd3) == cVar1) {
      return 1;
    }
    *(char *)((longlong)pp_Var11 + 0xd3) = cVar1;
    if (cVar1 == '\0') {
      return 1;
    }
    uVar4 = *(undefined4 *)(psVar2 + 2);
    uVar5 = *(undefined4 *)(psVar2 + 4);
    uVar6 = *(undefined4 *)(psVar2 + 6);
    local_128 = 0;
    local_148 = &local_128;
    local_120 = 0;
    local_118 = 0;
    local_110 = 0;
    *(undefined4 *)pp_Var11 = *(undefined4 *)psVar2;
    *(undefined4 *)((longlong)pp_Var11 + 4) = uVar4;
    *(undefined4 *)(pp_Var11 + 1) = uVar5;
    *(undefined4 *)((longlong)pp_Var11 + 0xc) = uVar6;
    StorPortNotification(0x1003,param_1,2);
    if (*(byte *)(psVar2 + 4) < 8) {
      local_130 = *(int **)((longlong)param_1 +
                           ((ulonglong)*(byte *)(psVar2 + 4) * 0x371 +
                           (ulonglong)*(byte *)((longlong)psVar2 + 9)) * 8 + 0x1ef0);
    }
    else {
      local_130 = (int *)0x0;
    }
    if (local_130 == (int *)0x0) {
      StorPortNotification(0x1004,param_1,&local_128);
      return 1;
    }
    local_138[0] = 0;
    memset((void *)((longlong)&local_a8 + 1),0,0x57);
    local_58 = 0xffffffff;
    local_a8 = 2;
    local_a4 = 0x18;
    local_a0 = 1;
    local_80 = 0x585d326b;
    uStack_7c = 0x40880b3a;
    uStack_78 = 0xb0883989;
    uStack_74 = 0xbe58690f;
    local_9c = 0x10;
    local_90 = 1;
    local_8c = 0x20;
    local_88 = 1;
    local_70 = 1;
    local_6c = 0x20;
    local_68 = 0;
    local_60 = 0;
    StorPortNotification(0x1004,param_1,&local_128);
    local_148 = (undefined8 *)local_138;
    iVar10 = StorPortExtendedFunction(0x30,param_1,psVar2,&local_a8);
    if (iVar10 == 0) {
      *(undefined1 *)((longlong)pp_Var11 + 0xd3) = 1;
      *(undefined1 *)((longlong)pp_Var11 + 0xd5) = 1;
      local_148 = (undefined8 *)local_48;
      StorPortExtendedFunction(0x33,param_1,psVar2);
      local_148 = (undefined8 *)local_40;
      StorPortExtendedFunction(0x34,param_1,psVar2);
    }
    else {
      *(undefined1 *)((longlong)pp_Var11 + 0xd3) = 0;
      *(undefined2 *)((longlong)pp_Var11 + 0xd5) = 0;
    }
    *(undefined1 *)((longlong)pp_Var11 + 0xd4) = 0;
  }
  else if (param_2 == 5) {
    psVar2 = *(short **)((longlong)param_3 + 8);
    if (psVar2 == (short *)0x0) {
      return 1;
    }
    if (*psVar2 != 1) {
      return 1;
    }
    if (*(int *)(psVar2 + 2) != 4) {
      return 1;
    }
    if ((((char)psVar2[5] == '\0') && (*(byte *)(psVar2 + 4) < 0xf)) &&
       (*(byte *)((longlong)psVar2 + 9) < 8)) {
      pp_Var11 = &Unit + ((ulonglong)*(byte *)(psVar2 + 4) * 0xf +
                         (ulonglong)*(byte *)((longlong)psVar2 + 9)) * 0x1c;
    }
    else {
      pp_Var11 = (_UNIT **)0x0;
    }
    if (pp_Var11 == (_UNIT **)0x0) {
      return 1;
    }
    *(undefined1 *)((longlong)pp_Var11 + 0xd2) = *(undefined1 *)((longlong)param_3 + 0x10);
  }
  else if (param_2 == 6) {
    psVar2 = *(short **)((longlong)param_3 + 8);
    if (psVar2 == (short *)0x0) {
      return 1;
    }
    if (*psVar2 != 1) {
      return 1;
    }
    if (*(int *)(psVar2 + 2) != 4) {
      return 1;
    }
    if ((((char)psVar2[5] == '\0') && (*(byte *)(psVar2 + 4) < 0xf)) &&
       (*(byte *)((longlong)psVar2 + 9) < 8)) {
      pp_Var11 = &Unit + ((ulonglong)*(byte *)(psVar2 + 4) * 0xf +
                         (ulonglong)*(byte *)((longlong)psVar2 + 9)) * 0x1c;
    }
    else {
      pp_Var11 = (_UNIT **)0x0;
    }
    if (pp_Var11 == (_UNIT **)0x0) {
      return 1;
    }
    *(undefined1 *)((longlong)pp_Var11 + 0xd5) = *(undefined1 *)((longlong)param_3 + 0x14);
  }
  else if (param_2 == 7) {
    psVar2 = *(short **)((longlong)param_3 + 8);
    if (psVar2 == (short *)0x0) {
      return 1;
    }
    if (*psVar2 != 1) {
      return 1;
    }
    if (*(int *)(psVar2 + 2) != 4) {
      return 1;
    }
    if ((((char)psVar2[5] == '\0') && (*(byte *)(psVar2 + 4) < 0xf)) &&
       (*(byte *)((longlong)psVar2 + 9) < 8)) {
      pp_Var11 = &Unit + ((ulonglong)*(byte *)(psVar2 + 4) * 0xf +
                         (ulonglong)*(byte *)((longlong)psVar2 + 9)) * 0x1c;
    }
    else {
      pp_Var11 = (_UNIT **)0x0;
    }
    if (pp_Var11 == (_UNIT **)0x0) {
      return 1;
    }
  }
  else {
    if (param_2 != 8) {
      return 1;
    }
    psVar2 = *(short **)((longlong)param_3 + 8);
    if (psVar2 == (short *)0x0) {
      return 1;
    }
    if (*psVar2 != 1) {
      return 1;
    }
    if (*(int *)(psVar2 + 2) != 4) {
      return 1;
    }
  }
  return 0;
}



===== HwStorAdapterControl @ 1c000dad0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* enum _SCSI_ADAPTER_CONTROL_STATUS __cdecl HwStorAdapterControl(void * __ptr64,enum
   _SCSI_ADAPTER_CONTROL_TYPE,void * __ptr64) */

_SCSI_ADAPTER_CONTROL_STATUS __cdecl
HwStorAdapterControl(void *param_1,_SCSI_ADAPTER_CONTROL_TYPE param_2,void *param_3)

{
  longlong lVar1;
  code *pcVar2;
  int iVar3;
  _SCSI_ADAPTER_CONTROL_STATUS _Var4;
  longlong lVar5;
  uint uVar6;
  bool bVar7;
  
  if (param_2 == 0) {
    uVar6 = 0;
    if (*(int *)param_3 != 0) {
      do {
        if ((uVar6 < 0xc) && ((0x9c7U >> (uVar6 & 0x1f) & 1) != 0)) {
          *(undefined1 *)((ulonglong)uVar6 + 4 + (longlong)param_3) = 1;
        }
        else {
          *(undefined1 *)((ulonglong)uVar6 + 4 + (longlong)param_3) = 0;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)param_3);
    }
  }
  else if (param_2 == 1) {
    *(int *)((longlong)param_1 + 0x19c) = *(int *)((longlong)param_1 + 0x19c) + 1;
    *(undefined4 *)((longlong)param_1 + 0x188) = 1;
    StorPortQuerySystemTime
              ((longlong)param_1 + (ulonglong)(*(uint *)((longlong)param_1 + 0x19c) & 7) * 8 + 0x1a0
              );
    uVar6 = 0;
    if (*(char *)((longlong)param_1 + 0x1c) != '\0') {
      do {
        lVar5 = (ulonglong)uVar6 * 0x1b88;
        if (*(int *)(lVar5 + 0x3f0 + (longlong)param_1) == 1) {
          AhciPortChannelStop((_IDE_CHANNEL *)((longlong)param_1 + lVar5 + 1000));
          *(undefined4 *)(lVar5 + 0x46c + (longlong)param_1) = 0;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(byte *)((longlong)param_1 + 0x1c));
    }
    lVar5 = *(longlong *)((longlong)param_1 + 0x228);
    lVar1 = *(longlong *)(lVar5 + 8);
    *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) & 0xfffffffd;
    LOCK();
    UNLOCK();
    *(uint *)(lVar1 + 0x14) = *(uint *)(lVar1 + 0x14) & 0xfe | 0x10100;
    LOCK();
    UNLOCK();
    *(uint *)(lVar5 + 0x48) = *(uint *)(lVar5 + 0x48) & 0xfffffffe;
    *(undefined4 *)(lVar1 + 0x18) = 0;
    LOCK();
    UNLOCK();
    bVar7 = g_bIsKernCZBP != '\0';
    *(undefined4 *)(lVar5 + 0x38) = 0;
    if ((bVar7) && (*(longlong *)((longlong)param_1 + 0x3e0) != 0)) {
      StorPortExtendedFunction(0x22,param_1);
      *(undefined8 *)((longlong)param_1 + 0x3e0) = 0;
    }
  }
  else if (param_2 == 2) {
    if (AmdSataBreak != 0) {
      pcVar2 = (code *)swi(3);
      _Var4 = (*pcVar2)();
      return _Var4;
    }
    *(undefined4 *)((longlong)param_1 + 0x188) = 2;
    *(int *)((longlong)param_1 + 0x198) = *(int *)((longlong)param_1 + 0x198) + 1;
    StorPortQuerySystemTime
              ((longlong)param_1 + (ulonglong)(*(uint *)((longlong)param_1 + 0x198) & 7) * 8 + 0x1e0
              );
    AhciAdapterStart(*(undefined4 **)((longlong)param_1 + 0x228),
                     (short *)((longlong)param_1 + 0x230));
    StorPortNotification(7,param_1,0xff);
  }
  else if ((param_2 != 3) && (param_2 != 4)) {
    if (param_2 == 6) {
      if (*(int *)((longlong)param_3 + 0x14) == 1) {
        if (((g_bIsKernCZBP != '\0') && (*(longlong *)((longlong)param_1 + 0x3e0) == 0)) &&
           (iVar3 = StorPortExtendedFunction(0x20,param_1), iVar3 != 0)) {
          return 1;
        }
      }
      else if ((*(int *)((longlong)param_3 + 0x14) == 4) && (g_bIsKernCZBP != '\0')) {
        LOCK();
        _g_lOutstandingIO = _g_lOutstandingIO & 0xfffffffe;
        UNLOCK();
        LOCK();
        uVar6 = g_lPHYClock >> 0x1c;
        g_lPHYClock = g_lPHYClock & 0xefffffff;
        UNLOCK();
        if ((uVar6 & 1) != 0) {
          StorPortSetBusDataByOffset
                    (param_1,4,*(undefined4 *)((longlong)param_1 + 0x24),
                     *(undefined4 *)((longlong)param_1 + 0x84),&g_lPHYClock,0x84,4);
        }
      }
    }
    else if ((param_2 != 7) && (param_2 != 8)) {
      if (param_2 != 0xb) {
        return 1;
      }
      AhciPortAcpiDSMControl(param_1,0xffffffff,(uchar)param_3);
    }
  }
  return 0;
}



===== SCSIOP_INQUIRY_CompletionRoutine @ 1c000dd80 =====

void SCSIOP_INQUIRY_CompletionRoutine(longlong param_1,longlong param_2)

{
  int *piVar1;
  ulong uVar2;
  longlong *plVar3;
  longlong lVar4;
  bool bVar5;
  
  plVar3 = (longlong *)(-(ulonglong)(param_2 != 0) & param_2 - 0x38U);
  if (plVar3 == (longlong *)0x0) {
    lVar4 = 0;
  }
  else {
    lVar4 = *plVar3;
  }
  if (*(char *)(lVar4 + 3) == '\x01') {
    bVar5 = false;
    piVar1 = *(int **)(*(longlong *)(param_1 + -0x98) + 0x1ef0 +
                      ((ulonglong)*(byte *)(lVar4 + 5) * 0x371 + (ulonglong)*(byte *)(lVar4 + 6)) *
                      8);
    if (piVar1 != (int *)0x0) {
      bVar5 = *piVar1 == 0x101;
    }
    if (bVar5) {
      uVar2 = IdentifyToInquiry(*(_INQUIRYDATA **)(lVar4 + 0x18),*(ulong *)(lVar4 + 0x10),
                                (_IDENTIFY_DEVICE_DATA *)(piVar1 + 6));
      *(ulong *)(lVar4 + 0x10) = uVar2;
    }
  }
  return;
}



===== SCSIOP_CAPACITY_CompletionRoutine @ 1c000de00 =====

ulonglong SCSIOP_CAPACITY_CompletionRoutine(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 *puVar4;
  ushort uVar5;
  int iVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong lVar11;
  byte bVar12;
  undefined4 local_res8;
  undefined8 local_res10;
  
  uVar7 = param_2 - 0x38;
  plVar9 = (longlong *)(-(ulonglong)(param_2 != 0) & uVar7);
  if (plVar9 == (longlong *)0x0) {
    lVar10 = 0;
  }
  else {
    lVar10 = *plVar9;
  }
  if (*(char *)(lVar10 + 3) == '\x01') {
    local_res8 = 0x200;
    lVar2 = *(longlong *)
             (*(longlong *)(param_1 + -0x98) + 0x1ef0 +
             ((ulonglong)*(byte *)(lVar10 + 5) * 0x371 + (ulonglong)*(byte *)(lVar10 + 6)) * 8);
    uVar1 = (undefined1)(*(ushort *)(lVar2 + 0xec) >> 8);
    local_res10 = *(ulonglong *)(lVar2 + 0x10);
    if ((*(ushort *)(lVar2 + 0xec) & 0x1000) != 0) {
      uVar1 = (undefined1)((ushort)*(undefined2 *)(lVar2 + 0x102) >> 8);
      local_res8 = *(int *)(lVar2 + 0x102) * 2;
    }
    *(int *)(lVar2 + 8) = local_res8;
    lVar3 = *(longlong *)(lVar10 + 0x18);
    if (*(char *)(lVar10 + 0x48) == -0x62) {
      *(undefined1 *)(lVar3 + 10) = local_res8._1_1_;
      *(undefined1 *)(lVar3 + 9) = local_res8._2_1_;
      *(undefined1 *)(lVar3 + 8) = local_res8._3_1_;
      *(char *)(lVar3 + 0xb) = (char)local_res8;
    }
    else {
      *(undefined1 *)(lVar3 + 6) = local_res8._1_1_;
      *(undefined1 *)(lVar3 + 5) = local_res8._2_1_;
      *(undefined1 *)(lVar3 + 4) = local_res8._3_1_;
      *(char *)(lVar3 + 7) = (char)local_res8;
    }
    if ((*(char *)(lVar10 + 0x48) == '%') && (0xfffffffe < local_res10)) {
      local_res10 = 0xffffffff;
    }
    puVar4 = *(undefined1 **)(lVar10 + 0x18);
    if (*(char *)(lVar10 + 0x48) == -0x62) {
      puVar4[6] = local_res10._1_1_;
      puVar4[5] = local_res10._2_1_;
      puVar4[4] = local_res10._3_1_;
      puVar4[3] = local_res10._4_1_;
      puVar4[2] = local_res10._5_1_;
      puVar4[1] = local_res10._6_1_;
      uVar7 = (ulonglong)CONCAT11(uVar1,local_res10._7_1_);
      *puVar4 = local_res10._7_1_;
      puVar4[7] = (char)local_res10;
      if (*(int *)(lVar10 + 0x10) == 0x20) {
        lVar3 = *(longlong *)(lVar10 + 0x18);
        lVar8 = 0;
        lVar11 = 0x14;
        do {
          *(undefined1 *)(lVar8 + 0xc + *(longlong *)(lVar10 + 0x18)) = 0;
          lVar8 = lVar8 + 1;
          lVar11 = lVar11 + -1;
        } while (lVar11 != 0);
        uVar5 = *(ushort *)(lVar2 + 0xec) & 0xc000;
        uVar7 = (ulonglong)uVar5;
        if ((uVar5 == 0x4000) && (uVar7 = 0x2000, (*(ushort *)(lVar2 + 0xec) & 0x2000) != 0)) {
          *(byte *)(lVar3 + 0xd) =
               *(byte *)(lVar3 + 0xd) ^ (*(byte *)(lVar3 + 0xd) ^ *(byte *)(lVar2 + 0xec)) & 0xf;
          uVar7 = CONCAT71(0x20,*(byte *)(lVar3 + 0xd));
          if ((*(ushort *)(lVar2 + 0x1ba) & 0x4000) != 0) {
            bVar12 = '\x01' << (*(byte *)(lVar3 + 0xd) & 0xf);
            iVar6 = (uint)bVar12 - (*(ushort *)(lVar2 + 0x1ba) & 0x3fff);
            uVar7 = (longlong)iVar6 / (longlong)(int)(uint)bVar12 & 0xffffffff;
            *(char *)(lVar3 + 0xf) = (char)(iVar6 % (int)(uint)bVar12);
          }
        }
      }
    }
    else {
      puVar4[2] = local_res10._1_1_;
      puVar4[1] = local_res10._2_1_;
      uVar7 = (ulonglong)CONCAT11(uVar1,local_res10._3_1_);
      *puVar4 = local_res10._3_1_;
      puVar4[3] = (char)local_res10;
    }
  }
  return uVar7;
}



===== SCSIOP_ATA_PASSTHROUG_CompletionRoutine @ 1c000dfc0 =====

longlong SCSIOP_ATA_PASSTHROUG_CompletionRoutine(undefined8 param_1,longlong param_2)

{
  byte *pbVar1;
  ulonglong uVar2;
  undefined7 uVar4;
  longlong lVar3;
  longlong lVar5;
  longlong *plVar6;
  
  plVar6 = (longlong *)(-(ulonglong)(param_2 != 0) & param_2 - 0x38U);
  if (plVar6 == (longlong *)0x0) {
    lVar5 = 0;
  }
  else {
    lVar5 = *plVar6;
  }
  if ((*(byte *)(lVar5 + 0x4a) & 0x20) != 0) {
    if ((*(byte *)(param_2 + 2) & 0x10) != 0) {
      pbVar1 = *(byte **)(lVar5 + 0x20);
      pbVar1[0] = 0;
      pbVar1[1] = 0;
      pbVar1[2] = 0;
      pbVar1[3] = 0;
      pbVar1[4] = 0;
      pbVar1[5] = 0;
      pbVar1[6] = 0;
      pbVar1[7] = 0;
      pbVar1[7] = 0xe;
      pbVar1[8] = 0;
      uVar2 = CONCAT71((int7)((ulonglong)-param_2 >> 8),*pbVar1) & 0xfffffffffffffff2;
      pbVar1[2] = 0;
      pbVar1[3] = 0x1d;
      *pbVar1 = (byte)uVar2 | 0x72;
      uVar2 = CONCAT71((int7)(uVar2 >> 8),pbVar1[1]) & 0xfffffffffffffff1;
      pbVar1[1] = (byte)uVar2 | 1;
      pbVar1[8] = 0;
      pbVar1[9] = 0;
      pbVar1[10] = 0;
      pbVar1[0xb] = 0;
      pbVar1[0xc] = 0;
      pbVar1[0xd] = 0;
      pbVar1[0xe] = 0;
      pbVar1[0xf] = 0;
      pbVar1[0x10] = 0;
      pbVar1[0x11] = 0;
      pbVar1[0x12] = 0;
      pbVar1[0x13] = 0;
      pbVar1[0x14] = 0;
      pbVar1[0x15] = 0;
      pbVar1[8] = 9;
      pbVar1[9] = 0xc;
      pbVar1[10] = 0;
      uVar4 = (undefined7)(uVar2 >> 8);
      pbVar1[0xb] = *(byte *)(param_2 + 100);
      pbVar1[0xd] = *(byte *)(param_2 + 0x65);
      pbVar1[0xf] = *(byte *)(param_2 + 0x66);
      pbVar1[0x11] = *(byte *)(param_2 + 0x67);
      pbVar1[0x13] = *(byte *)(param_2 + 0x68);
      pbVar1[0x14] = *(byte *)(param_2 + 0x69);
      lVar3 = CONCAT71(uVar4,*(byte *)(param_2 + 0x6a));
      pbVar1[0x15] = *(byte *)(param_2 + 0x6a);
      if ((*(char *)(lVar5 + 0x48) == -0x7b) && ((*(byte *)(lVar5 + 0x49) & 1) != 0)) {
        pbVar1[0xc] = *(byte *)(param_2 + 0x6d);
        pbVar1[0xe] = *(byte *)(param_2 + 0x6e);
        pbVar1[0x10] = *(byte *)(param_2 + 0x6f);
        lVar3 = CONCAT71(uVar4,*(byte *)(param_2 + 0x70));
        pbVar1[0x12] = *(byte *)(param_2 + 0x70);
        pbVar1[10] = 1;
      }
      *(undefined1 *)(lVar5 + 0xb) = 0x16;
      *(undefined2 *)(lVar5 + 3) = 0x284;
      return lVar3;
    }
    *(undefined1 *)(lVar5 + 3) = 4;
  }
  return -param_2;
}



===== AhciPortCompleteRequest @ 1c000e0a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AhciPortCompleteRequest(longlong param_1,ushort *param_2)

{
  undefined1 *puVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  undefined8 *puVar9;
  byte *pbVar10;
  ushort uVar11;
  uchar uVar12;
  undefined1 uVar13;
  _UNIT **pp_Var14;
  undefined1 *puVar15;
  longlong lVar16;
  longlong lVar17;
  
  if (*param_2 < 0x100) {
    return;
  }
  lVar5 = *(longlong *)(param_2 + -0x1c);
  lVar6 = *(longlong *)(param_1 + -0x98);
  if (lVar5 == 0) {
    return;
  }
  cVar2 = *(char *)(lVar5 + 2);
  if (cVar2 == '\0') {
    uVar12 = StatusIrbToSrb((uchar)param_2[1]);
    *(uchar *)(lVar5 + 3) = uVar12;
    if (*(code **)(param_2 + -0x10) != (code *)0x0) {
      (**(code **)(param_2 + -0x10))(param_1,param_2);
    }
    goto LAB_1c000e313;
  }
  if (cVar2 == '\x02') {
    if (((*(char *)(lVar5 + 7) == '\0') && (*(byte *)(lVar5 + 5) < 0xf)) &&
       (*(byte *)(lVar5 + 6) < 8)) {
      pp_Var14 = &Unit + ((ulonglong)*(byte *)(lVar5 + 5) * 0xf + (ulonglong)*(byte *)(lVar5 + 6)) *
                         0x1c;
    }
    else {
      pp_Var14 = (_UNIT **)0x0;
    }
    lVar7 = *(longlong *)(lVar5 + 0x18);
    uVar4 = *(uint *)(lVar7 + 0x10);
    if ((pp_Var14 != (_UNIT **)0x0) && (*(char *)((longlong)pp_Var14 + 0xd3) != '\0')) {
      StorPortExtendedFunction(0x32,lVar6,pp_Var14,lVar5,0,0);
      *(int *)(pp_Var14 + 0x1b) = *(int *)(pp_Var14 + 0x1b) + -1;
    }
    lVar8 = *(longlong *)(lVar5 + 0x18);
    if (0x1b0500 < uVar4) {
      if (uVar4 < 0x1b050a) {
        if (uVar4 == 0x1b0501) {
LAB_1c000e24a:
          *(undefined4 *)(lVar8 + 0x1c) = *(undefined4 *)(param_2 + 0xc);
LAB_1c000e2b2:
          *(undefined1 *)(lVar8 + 0x20) = 0;
        }
        else {
          bVar3 = *(byte *)(lVar8 + 0x20);
          if (bVar3 < 0xd0) {
LAB_1c000e2ae:
            *(undefined4 *)(lVar8 + 0x1c) = 0;
            goto LAB_1c000e2b2;
          }
          if (bVar3 < 0xd2) goto LAB_1c000e24a;
          if (bVar3 < 0xd5) goto LAB_1c000e2ae;
          if (bVar3 == 0xd5) goto LAB_1c000e24a;
          if (((bVar3 == 0xd6) || (bVar3 < 0xd8)) || ((bVar3 < 0xda || (bVar3 != 0xda))))
          goto LAB_1c000e2ae;
          if ((param_2[1] & 0x10) != 0) {
            puVar15 = (undefined1 *)(lVar8 + 0x2c);
            lVar16 = 0;
            lVar17 = 8;
            do {
              puVar1 = (undefined1 *)(lVar16 + *(longlong *)(param_2 + 0x20));
              lVar16 = lVar16 + 1;
              *puVar15 = *puVar1;
              puVar15 = puVar15 + 1;
              lVar17 = lVar17 + -1;
            } while (lVar17 != 0);
            *(undefined4 *)(lVar8 + 0x1c) = 8;
            goto LAB_1c000e2b2;
          }
          *(undefined1 *)(lVar8 + 0x20) = 1;
        }
        *(uint *)(lVar7 + 0x14) = -(uint)((param_2[1] & 0xf) != 1) & 0xc0000001;
        *(bool *)(lVar8 + 0x20) = (char)param_2[1] != '\x01';
        if ((char)param_2[1] == '\x01') {
          uVar13 = 0;
        }
        else {
          uVar13 = (undefined1)param_2[0x32];
        }
        *(undefined1 *)(lVar8 + 0x21) = uVar13;
      }
      else {
        if (uVar4 != 0x1b0600) goto LAB_1c000e2eb;
        if (((param_2[1] & 0xf) == 1) && ((param_2[1] & 0x10) != 0)) {
          pbVar10 = *(byte **)(param_2 + 0x20);
          *(undefined8 *)(lVar7 + 0x34) = 0;
          *(byte *)(lVar7 + 0x34) = pbVar10[2];
          *(byte *)(lVar7 + 0x35) = pbVar10[3];
          *(byte *)(lVar7 + 0x36) = pbVar10[4];
          *(byte *)(lVar7 + 0x37) = pbVar10[10];
          *(byte *)(lVar7 + 0x38) = pbVar10[0xb];
          *(byte *)(lVar7 + 0x39) = pbVar10[0xc];
          *(undefined4 *)(lVar7 + 0x2c) = 0;
          *(byte *)(lVar7 + 0x2c) = pbVar10[1];
          *(byte *)(lVar7 + 0x2d) = pbVar10[9];
          *(uint *)(lVar7 + 0x40) = (uint)pbVar10[6];
          *(uint *)(lVar7 + 0x44) = (uint)*pbVar10;
          *(undefined4 *)(lVar7 + 0x28) = 0;
        }
        else {
          *(undefined4 *)(lVar7 + 0x28) = 2;
        }
        *(undefined4 *)(lVar7 + 0x14) = 0;
      }
      *(undefined1 *)(lVar5 + 3) = 1;
      goto LAB_1c000e313;
    }
LAB_1c000e2eb:
    uVar12 = (uchar)param_2[1];
  }
  else {
    uVar12 = (uchar)param_2[1];
    if (cVar2 == '\a') {
      uVar12 = StatusIrbToSrb(uVar12);
      *(uchar *)(lVar5 + 3) = uVar12;
      if (uVar12 == '\x01') {
        pbVar10 = (byte *)((ulonglong)*(byte *)(lVar5 + 5) * 0x1b88 + 0x474 + lVar6 +
                          ((longlong)(int)(uint)*(byte *)(lVar5 + 6) >> 3));
        *pbVar10 = *pbVar10 | '\x01' << (*(byte *)(lVar5 + 6) & 7);
      }
      goto LAB_1c000e313;
    }
  }
  uVar12 = StatusIrbToSrb(uVar12);
  *(uchar *)(lVar5 + 3) = uVar12;
LAB_1c000e313:
  if ((char)param_2[1] == '\x02') {
    *(undefined4 *)(lVar5 + 0x10) = *(undefined4 *)(param_2 + 0xc);
  }
  if (((*(char *)(lVar5 + 3) == '\x04') &&
      (puVar9 = *(undefined8 **)(lVar5 + 0x20), puVar9 != (undefined8 *)0x0)) &&
     (0x11 < *(byte *)(lVar5 + 0xb))) {
    if ((param_2[1] & 0x20) == 0) {
      *puVar9 = 0;
      puVar9[1] = 0;
      *(undefined2 *)(puVar9 + 2) = 0;
      *(undefined1 *)puVar9 = 0x70;
      uVar11 = param_2[2];
      *(undefined1 *)((longlong)puVar9 + 7) = 10;
      *(byte *)((longlong)puVar9 + 2) = (byte)uVar11 >> 4 | *(byte *)((longlong)puVar9 + 2) & 0xf0;
      *(undefined1 *)(lVar5 + 0xb) = 0x12;
    }
    else {
      *(undefined1 *)(lVar5 + 0xb) = *(undefined1 *)((longlong)param_2 + 9);
    }
    *(byte *)(lVar5 + 3) = *(byte *)(lVar5 + 3) | 0x80;
    *(undefined1 *)(lVar5 + 4) = 2;
  }
  StorPortNotification(0,lVar6,lVar5);
  return;
}



===== AhciPortGetPhysicalAddress @ 1c000e3a4 =====

undefined8
AhciPortGetPhysicalAddress(longlong param_1,longlong param_2,longlong param_3,ulonglong param_4)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  ulonglong local_res20;
  
  local_res20 = param_4 & 0xffffffff00000000;
  puVar2 = (undefined8 *)(-(ulonglong)(param_2 != 0) & param_2 - 0x38U);
  if (puVar2 == (undefined8 *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *puVar2;
  }
  if (param_3 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = StorPortGetPhysicalAddress(*(undefined8 *)(param_1 + -0x98),uVar1,param_3,&local_res20);
  }
  return uVar1;
}



===== AhciPortAsyncNotificationDetected @ 1c000e3f8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AhciPortAsyncNotificationDetected(longlong param_1,undefined1 param_2)

{
  undefined1 auStack_58 [32];
  undefined4 *local_38;
  undefined4 local_28 [2];
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined4 local_15;
  undefined1 local_11;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_18 = *(undefined1 *)(param_1 + -0x8c);
  local_20 = 1;
  local_1c = 4;
  local_16 = 0;
  local_15 = 0;
  local_11 = 0;
  local_38 = local_28;
  local_28[0] = 0xc1000002;
  local_17 = param_2;
  StorPortNotification(0x1007,*(undefined8 *)(param_1 + -0x98),&local_20,7);
  return;
}



===== ChannelDpcRoutine @ 1c000e480 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl ChannelDpcRoutine(struct _STOR_DPC * __ptr64,void * __ptr64,void * __ptr64,void *
   __ptr64) */

void __cdecl ChannelDpcRoutine(_STOR_DPC *param_1,void *param_2,void *param_3,void *param_4)

{
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_28 = 0;
  local_20 = 0;
  local_18 = 0;
  local_10 = 0;
  StorPortNotification(0x1003,param_2,2,0,&local_28);
  (*param_3)((longlong)param_4 + 0x98);
  StorPortNotification(0x1004,param_2,&local_28);
  return;
}



===== ProcessTimerTick @ 1c000e4f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* unsigned long __cdecl ProcessTimerTick(void * __ptr64) */

ulong __cdecl ProcessTimerTick(void *param_1)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  longlong lVar4;
  bool bVar5;
  uint local_res8 [2];
  
  local_res8[0] = *(uint *)((longlong)param_1 + 0x3b8);
  uVar1 = 0;
  bVar5 = local_res8[0] != 0;
  if (bVar5) {
    for (; (local_res8[0] >> uVar1 & 1) == 0; uVar1 = uVar1 + 1) {
    }
  }
  while (bVar5) {
    pbVar2 = (byte *)((longlong)local_res8 + ((longlong)(int)uVar1 >> 3));
    *pbVar2 = *pbVar2 & ~('\x01' << (uVar1 & 7));
    lVar4 = (ulonglong)uVar1 * 0x1b88;
    if (*(char *)(lVar4 + 0x478 + (longlong)param_1) == '\0') {
      pbVar2 = (byte *)((longlong)param_1 + ((longlong)(int)uVar1 >> 3) + 0x3b8);
      *pbVar2 = *pbVar2 & ~('\x01' << (uVar1 & 7));
    }
    iVar3 = (**(code **)(lVar4 + 0x458 + (longlong)param_1))((longlong)param_1 + lVar4 + 0x480);
    if (iVar3 == 0) {
      pbVar2 = (byte *)((longlong)param_1 + ((longlong)(int)uVar1 >> 3) + 0x3b8);
      *pbVar2 = *pbVar2 & ~('\x01' << (uVar1 & 7));
    }
    uVar1 = 0;
    bVar5 = local_res8[0] != 0;
    if (bVar5) {
      for (; (local_res8[0] >> uVar1 & 1) == 0; uVar1 = uVar1 + 1) {
      }
    }
  }
  return -(uint)(*(int *)((longlong)param_1 + 0x3b8) != 0) & 100000;
}



===== TimerDpcRoutine @ 1c000e580 =====

/* void __cdecl TimerDpcRoutine(struct _STOR_DPC * __ptr64,void * __ptr64,void * __ptr64,void *
   __ptr64) */

void __cdecl TimerDpcRoutine(_STOR_DPC *param_1,void *param_2,void *param_3,void *param_4)

{
  ulong uVar1;
  
  uVar1 = ProcessTimerTick(param_2);
  if (uVar1 != 0) {
    StorPortNotification(6,param_2,*(undefined8 *)((longlong)param_2 + 0x368),uVar1);
  }
  return;
}



===== HwStorTimer @ 1c000e5c0 =====

/* void __cdecl HwStorTimer(void * __ptr64) */

void __cdecl HwStorTimer(void *param_1)

{
  ulong uVar1;
  undefined4 local_res8 [8];
  
  if (*(int *)((longlong)param_1 + 0x188) == 1) {
    *(undefined4 *)((longlong)param_1 + 0x3b8) = 0;
  }
  else if ((*(uint *)((longlong)param_1 + 0x18) & 4) == 0) {
    if (*(int *)((longlong)param_1 + 0xb4) == 1) {
      uVar1 = ProcessTimerTick(param_1);
      if (uVar1 != 0) {
        if (g_bIsPMAttached == '\0') {
          uVar1 = uVar1 / 10;
        }
                    /* WARNING: Could not recover jumptable at 0x0001c000e624. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        StorPortNotification(6,param_1,*(undefined8 *)((longlong)param_1 + 0x368),uVar1);
        return;
      }
    }
    else {
      local_res8[0] = 0;
      StorPortNotification(0x1002,param_1,(longlong)param_1 + 0x370,0,0,local_res8);
    }
  }
  else {
    while( true ) {
      uVar1 = ProcessTimerTick(param_1);
      if (uVar1 == 0) break;
      StorPortStallExecution(uVar1);
    }
  }
  return;
}



===== AhciPortRequestSynchronizedRoutine @ 1c000e678 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AhciPortRequestSynchronizedRoutine(longlong param_1,undefined *param_2)

{
  int iVar1;
  longlong lVar2;
  bool bVar3;
  undefined4 local_res8 [2];
  undefined1 local_28 [32];
  
  lVar2 = *(longlong *)(param_1 + -0x98);
  if (((*(int *)(lVar2 + 0xb4) == 1) && ((*(uint *)(lVar2 + 0x18) & 4) == 0)) &&
     (iVar1 = *(int *)(param_1 + -0x78), iVar1 != 3)) {
    bVar3 = MSIEnabled == 0;
    *(undefined4 *)(param_1 + -0x78) = 3;
    if ((bVar3) || (MSISingle != 0)) {
      StorPortNotification(0x1003,lVar2,3,0,local_28);
      (*(code *)param_2)(param_1);
      StorPortNotification(0x1004,lVar2,local_28);
    }
    else {
      StorPortExtendedFunction(0xb,lVar2,*(undefined4 *)(param_1 + -0x8c),local_res8);
      (*(code *)param_2)(param_1);
      StorPortExtendedFunction(0xc,lVar2,*(undefined4 *)(param_1 + -0x8c),local_res8[0]);
    }
    *(int *)(param_1 + -0x78) = iVar1;
  }
  else {
    (*(code *)param_2)();
  }
  return;
}



===== AhciPortRequestWorkerRoutine @ 1c000e778 =====

void AhciPortRequestWorkerRoutine(longlong param_1,ulonglong param_2)

{
  undefined *puVar1;
  ulonglong local_res10 [3];
  
  puVar1 = *(undefined **)(param_1 + -0x98);
  if ((*(uint *)(puVar1 + 0x18) & 4) == 0) {
    local_res10[0] = param_2 & 0xffffffff00000000;
    StorPortNotification
              (0x1002,puVar1,param_1 + -0x70,ChannelWorkerDpcRoutine,(undefined8 *)(param_1 + -0x98)
               ,local_res10);
    return;
  }
  local_res10[0] = param_2;
  ChannelWorkerDpcRoutine(param_1,puVar1);
  return;
}



===== AhciPortBuildRequestSenseIrb @ 1c000e7d0 =====

undefined2 * AhciPortBuildRequestSenseIrb(undefined8 param_1,undefined2 *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  
  plVar2 = (longlong *)(-(ulonglong)(param_2 != (undefined2 *)0x0) & (ulonglong)(param_2 + -0x1c));
  if (plVar2 == (longlong *)0x0) {
    lVar1 = 0;
  }
  else {
    lVar1 = *plVar2;
  }
  if ((*(longlong *)(lVar1 + 0x20) == 0) || ((*(byte *)(lVar1 + 0xb) & 0xfe) == 0)) {
    return (undefined2 *)0x0;
  }
  *(undefined1 *)(param_2 + 1) = 0;
  *param_2 = 0x201;
  *(undefined4 *)(param_2 + 8) = 0x40;
  *(undefined8 *)(param_2 + 0x1c) = *(undefined8 *)(lVar1 + 0x20);
  *(uint *)(param_2 + 0xc) = *(byte *)(lVar1 + 0xb) & 0xfffffffe;
  *(undefined4 *)(param_2 + 0x32) = 3;
  *(undefined1 *)(param_2 + 0x34) = *(undefined1 *)(param_2 + 0xc);
  *(undefined1 *)((longlong)param_2 + 0x69) = 0;
  return param_2;
}



===== AhciPortAllocatePool @ 1c000e838 =====

undefined8 AhciPortAllocatePool(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_res8 [4];
  
  lVar1 = *(longlong *)(param_1 + -0x98);
  if ((*(uint *)(lVar1 + 0x18) >> 2 & 1) == 0) {
    iVar2 = StorPortExtendedFunction(0,lVar1,0x498,0x41534841,local_res8);
    uVar3 = 0;
    if (iVar2 == 0) {
      uVar3 = local_res8[0];
    }
  }
  else {
    uVar3 = *(undefined8 *)(lVar1 + 200);
    *(longlong *)(lVar1 + 200) = *(longlong *)(lVar1 + 200) + 0x498;
  }
  return uVar3;
}



===== AhciPortLogError @ 1c000e898 =====

void AhciPortLogError(longlong param_1,longlong *param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if ((*param_2 != 0) &&
     (puVar1 = (undefined8 *)(*param_2 + -0x38), uVar2 = 0, puVar1 != (undefined8 *)0x0)) {
    uVar2 = *puVar1;
  }
  if (AmdSataLog != 0) {
    StorPortLogError(*(undefined8 *)(param_1 + -0x98),uVar2,(char)param_2[1],
                     *(undefined1 *)((longlong)param_2 + 9),*(undefined1 *)((longlong)param_2 + 10),
                     5,*(undefined1 *)((longlong)param_2 + 0xc));
  }
  return;
}



===== StatusIrbToSrb @ 1c000e8f4 =====

/* unsigned char __cdecl StatusIrbToSrb(unsigned char) */

uchar __cdecl StatusIrbToSrb(uchar param_1)

{
  byte bVar1;
  uchar uVar2;
  
  uVar2 = '\t';
  bVar1 = param_1 & 0xf;
  if (bVar1 == 1) {
    uVar2 = '\x01';
  }
  else if (bVar1 == 2) {
    uVar2 = '\x12';
  }
  else if (bVar1 == 3) {
    uVar2 = '\x04';
  }
  else if (bVar1 == 4) {
    uVar2 = '\x06';
  }
  else if (bVar1 == 5) {
    uVar2 = '\x0e';
  }
  else if (bVar1 == 6) {
    uVar2 = '\n';
  }
  else if (bVar1 == 7) {
    uVar2 = '\x05';
  }
  return uVar2;
}



===== InitEnclosureManagement @ 1c000e948 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong InitEnclosureManagement(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  undefined1 local_58 [32];
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_28;
  undefined8 local_24;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)local_58;
  uVar2 = *(uint *)(param_1 + 0x24);
  if ((uVar2 & 0x40) != 0) {
    *(undefined4 *)(param_1 + 0x58) = 0;
    lVar1 = *(longlong *)(param_1 + 8);
    local_28 = 0;
    *(undefined2 *)(param_1 + 0x5c) = 0xff;
    local_24 = 0;
    local_38 = &local_28;
    local_30 = 0xc;
    StorPortGetBusData(param_1 + -0xe028,4,*(undefined4 *)(param_1 + -0xe004),
                       *(undefined4 *)(param_1 + -0xdfa4));
    uVar2 = *(uint *)(lVar1 + 0x1c);
    if (local_24._4_1_ == 'I') {
      uVar2 = 0x800000;
    }
    *(ulonglong *)(param_1 + 0x50) = lVar1 + (ulonglong)(uVar2 >> 0x10) * 4;
    uVar2 = *(uint *)(lVar1 + 0x20) | 0x200;
    *(uint *)(lVar1 + 0x20) = uVar2;
    LOCK();
    UNLOCK();
  }
  return (ulonglong)(uVar2 >> 8) << 8;
}



===== SgpioEnableInitiator @ 1c000e9fc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl SgpioEnableInitiator(struct _AHCI_CONTROLLER_EXTENSION * __ptr64) */

void __cdecl SgpioEnableInitiator(_AHCI_CONTROLLER_EXTENSION *param_1)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  undefined1 local_48 [32];
  undefined1 local_28;
  undefined8 local_27;
  undefined5 local_1f;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined1 uStack_15;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)local_48;
  if ((*(uint *)(param_1 + 0x24) & 0x40) != 0) {
    local_28 = 0;
    local_1f = 0;
    uStack_19 = 0;
    uStack_18 = 0;
    uStack_1a = 0x80;
    local_27 = 0x200008240030010;
    if (GpioCfg1 == 0) {
      uStack_17 = 0x37;
      uStack_16 = 0xf;
      uStack_15 = 0xf;
    }
    else {
      uStack_18 = (undefined1)GpioCfg1;
      uStack_17 = (undefined1)(GpioCfg1 >> 8);
      uStack_16 = (undefined1)(GpioCfg1 >> 0x10);
      uStack_15 = (undefined1)(GpioCfg1 >> 0x18);
    }
    memcpy(*(void **)(param_1 + 0x50),&local_28,0x14);
    lVar2 = *(longlong *)(param_1 + 8);
    iVar3 = 10;
    while ((uVar1 = *(uint *)(lVar2 + 0x20), (uVar1 >> 8 & 1) != 0 && (iVar3 != 0))) {
      StorPortStallExecution(100);
      iVar3 = iVar3 + -1;
    }
    *(uint *)(lVar2 + 0x20) = uVar1 | 0x100;
    LOCK();
    UNLOCK();
  }
  return;
}



===== __report_gsfailure @ 1c000eaf0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== ScsiPortWmiPostProcess @ 1c000eaf8 =====

void ScsiPortWmiPostProcess(longlong param_1,char param_2,uint param_3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  ulonglong uVar10;
  
  cVar1 = *(char *)(param_1 + 0x18);
  uVar9 = 0;
  uVar2 = *(uint *)(param_1 + 8);
  puVar4 = *(uint **)(param_1 + 0x10);
  if (cVar1 == '\0') {
    uVar7 = puVar4[0xc];
    uVar3 = puVar4[0xd];
    uVar10 = (ulonglong)uVar3;
    uVar5 = uVar7 + param_3;
    if (param_2 == '\x01') {
      if (uVar5 <= uVar2) {
        if (((0x2f < uVar2) && (*puVar4 = uVar5, uVar9 = uVar5, (char)puVar4[0xb] < '\0')) &&
           (puVar8 = puVar4 + 0xf, uVar6 = uVar10, uVar3 != 0)) {
          do {
            uVar5 = (int)uVar6 - 1;
            uVar6 = (ulonglong)uVar5;
            if (uVar6 * 8 + 0x48 <= (ulonglong)uVar2) {
              puVar4[uVar6 * 2 + 0x10] = puVar8[uVar6];
            }
          } while (uVar5 != 0);
          if (uVar3 != 0) {
            uVar6 = 0x48;
            do {
              if (uVar6 <= uVar2) {
                *puVar8 = uVar7;
                uVar7 = uVar7 + 7 + puVar8[1] & 0xfffffff8;
              }
              uVar6 = uVar6 + 8;
              puVar8 = puVar8 + 2;
              uVar10 = uVar10 - 1;
            } while (uVar10 != 0);
          }
        }
        goto LAB_1c000ebbb;
      }
      param_2 = '\x12';
    }
LAB_1c000eb98:
    if ((param_2 != '\x12') || (uVar2 < 0x38)) goto LAB_1c000ebbb;
    puVar4[0xc] = uVar5;
  }
  else {
    if (cVar1 == '\x01') {
      uVar5 = puVar4[0xe] + param_3;
      if (param_2 == '\x01') {
        if (0x2f < uVar2) {
          *puVar4 = uVar5;
          uVar9 = uVar5;
        }
        goto LAB_1c000ebbb;
      }
      goto LAB_1c000eb98;
    }
    if (cVar1 != '\t') goto LAB_1c000ebbb;
    uVar7 = puVar4[0xf] + param_3;
    if (param_2 == '\x01') {
      if (0x47 < uVar2) {
        *puVar4 = uVar7;
        puVar4[0x10] = param_3;
        uVar9 = uVar7;
      }
      goto LAB_1c000ebbb;
    }
    if ((param_2 != '\x12') || (uVar2 < 0x38)) goto LAB_1c000ebbb;
    puVar4[0xc] = uVar7;
  }
  *puVar4 = 0x38;
  puVar4[0xb] = 0x20;
  param_2 = '\x01';
  uVar9 = 0x38;
LAB_1c000ebbb:
  *(uint *)(param_1 + 0x1c) = uVar9;
  *(char *)(param_1 + 0x19) = param_2;
  return;
}



===== ScsiWmipProcessRequest @ 1c000ec48 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

char ScsiWmipProcessRequest
               (uint *param_1,byte param_2,undefined8 param_3,undefined8 param_4,longlong *param_5,
               uint param_6,uint *param_7,uint *param_8,undefined4 *param_9)

{
  uint uVar1;
  short sVar2;
  ulonglong uVar3;
  char cVar4;
  uint uVar5;
  code *pcVar6;
  uint uVar7;
  longlong *plVar8;
  ulonglong *puVar9;
  undefined2 *puVar10;
  int iVar11;
  longlong lVar12;
  uint *puVar13;
  ushort uVar14;
  uint uVar15;
  uint uVar16;
  undefined8 uVar17;
  ulonglong uVar18;
  undefined4 uVar19;
  short *local_38 [2];
  
  puVar13 = (uint *)0x0;
  uVar18 = 0;
  uVar15 = 0;
  *param_9 = 0;
  uVar5 = 0;
  if (param_2 != 8) {
    if (*param_1 != 0) {
      plVar8 = *(longlong **)(param_1 + 2);
      do {
        if ((*param_5 == *(longlong *)*plVar8) && (param_5[1] == ((longlong *)*plVar8)[1])) {
          uVar15 = *(uint *)(*(longlong **)(param_1 + 2) + uVar18 * 2 + 1);
          if (((2 < (byte)(param_2 - 1)) && (param_2 != 9)) ||
             ((uVar5 = param_7[0xd], -1 < (char)param_7[0xb] || (uVar5 < uVar15))))
          goto LAB_1c000ed1b;
          break;
        }
        uVar15 = (int)uVar18 + 1;
        uVar18 = (ulonglong)uVar15;
        plVar8 = plVar8 + 2;
      } while (uVar15 < *param_1);
    }
    *param_8 = 0;
    cVar4 = '\x04';
    goto LAB_1c000f08d;
  }
LAB_1c000ed1b:
  if (param_2 < 6) {
    if (param_2 != 5) {
      if (param_2 == 0) {
        if (param_6 < 0x48) goto LAB_1c000ed9b;
        param_7[0xb] = param_7[0xb] & 0xffffffef;
        uVar5 = uVar15 * 8 + 0x40;
        param_7[0xd] = uVar15;
        param_7[0xc] = uVar5;
        if (param_6 < uVar5) {
          lVar12 = 0;
          iVar11 = 0;
        }
        else {
          puVar13 = param_7 + 0xf;
          lVar12 = (ulonglong)uVar5 + (longlong)param_7;
          iVar11 = param_6 - uVar5;
        }
        uVar5 = 0;
      }
      else {
        if (param_2 != 1) {
          if (param_2 == 2) {
            if (*(code **)(param_1 + 8) != (code *)0x0) {
              cVar4 = (**(code **)(param_1 + 8))
                                (param_3,param_4,uVar18,uVar5,param_7[0xf],
                                 (ulonglong)param_7[0xe] + (longlong)param_7);
              return cVar4;
            }
          }
          else if (param_2 == 3) {
            if (*(code **)(param_1 + 10) != (code *)0x0) {
              cVar4 = (**(code **)(param_1 + 10))
                                (param_3,param_4,uVar18,uVar5,param_7[0xe],param_7[0x10],
                                 (ulonglong)param_7[0xf] + (longlong)param_7);
              return cVar4;
            }
          }
          else if (param_2 == 4) {
            pcVar6 = *(code **)(param_1 + 0xe);
            if (pcVar6 != (code *)0x0) {
              uVar17 = 0;
              goto LAB_1c000f0b0;
            }
            goto LAB_1c000f0c5;
          }
LAB_1c000ed9b:
          cVar4 = '\x04';
          goto LAB_1c000f0c8;
        }
        if (param_6 < 0x40) {
          if (param_6 < 4) {
            *(undefined1 *)param_7 = 8;
            return '\x12';
          }
          *param_7 = 0x40;
          return '\x12';
        }
        iVar11 = param_6 - param_7[0xe];
        lVar12 = (longlong)param_7 + (ulonglong)param_7[0xe];
        puVar13 = param_7 + 0xf;
        uVar15 = 1;
      }
      pcVar6 = *(code **)(param_1 + 6);
LAB_1c000ee7e:
      cVar4 = (*pcVar6)(param_3,param_4,uVar18,uVar5,uVar15,puVar13,iVar11,lVar12);
      return cVar4;
    }
    pcVar6 = *(code **)(param_1 + 0xe);
    if (pcVar6 != (code *)0x0) {
      uVar19 = 0;
      uVar17 = 0;
      goto LAB_1c000f0b5;
    }
  }
  else if (param_2 == 6) {
    pcVar6 = *(code **)(param_1 + 0xe);
    if (pcVar6 != (code *)0x0) {
      uVar17 = 1;
LAB_1c000f0b0:
      uVar19 = 1;
LAB_1c000f0b5:
      cVar4 = (*pcVar6)(param_3,param_4,uVar18,uVar17,uVar19);
      return cVar4;
    }
  }
  else {
    if (param_2 != 7) {
      if (param_2 != 8) {
        if (((param_2 == 9) && (pcVar6 = *(code **)(param_1 + 0xc), pcVar6 != (code *)0x0)) &&
           (0x47 < param_6)) {
          uVar15 = param_7[0xf];
          if (uVar15 <= param_6) {
            lVar12 = (longlong)param_7 + (ulonglong)uVar15;
            iVar11 = param_6 - uVar15;
            puVar13 = (uint *)(ulonglong)param_7[0x10];
            uVar15 = param_7[0xe];
            goto LAB_1c000ee7e;
          }
        }
        goto LAB_1c000ed9b;
      }
      cVar4 = (**(code **)(param_1 + 4))(param_3,param_4,local_38);
      if (cVar4 == '\x01') {
        uVar15 = *param_1;
        uVar18 = (ulonglong)uVar15;
        lVar12 = *(longlong *)(param_1 + 2);
        uVar16 = uVar15 * 0x20 + 0x18;
        uVar5 = uVar15 * 0x20 + 0x34;
        if (local_38[0] == (short *)0x0) {
          uVar14 = 0;
        }
        else {
          uVar14 = 0;
          sVar2 = *local_38[0];
          while (sVar2 != 0) {
            uVar14 = uVar14 + 1;
            sVar2 = local_38[0][uVar14];
          }
          uVar14 = uVar14 * 2;
        }
        uVar7 = uVar14 + uVar5;
        if ((uVar7 < uVar5) || (uVar1 = uVar7 + 2, uVar1 < uVar7)) {
          cVar4 = '\x04';
          goto LAB_1c000f07e;
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
          param_7[3] = uVar5;
          param_7[4] = uVar15;
          if (uVar15 != 0) {
            puVar13 = (uint *)(lVar12 + 0xc);
            puVar9 = (ulonglong *)(param_7 + 0xc);
            do {
              uVar3 = (*(ulonglong **)(puVar13 + -3))[1];
              puVar9[-3] = **(ulonglong **)(puVar13 + -3);
              puVar9[-2] = uVar3;
              if (puVar13[-1] == 0xffffffff) {
                *(uint *)(puVar9 + -1) = *puVar13;
                *puVar9 = 0;
                *(undefined4 *)((longlong)puVar9 + -4) = 0;
              }
              else {
                *(uint *)(puVar9 + -1) = *puVar13 | 8;
                *puVar9 = (ulonglong)uVar16;
                *(uint *)((longlong)puVar9 + -4) = puVar13[-1];
              }
              puVar9 = puVar9 + 4;
              puVar13 = puVar13 + 4;
              uVar18 = uVar18 - 1;
            } while (uVar18 != 0);
          }
          puVar10 = (undefined2 *)((ulonglong)uVar16 + (longlong)param_7);
          *puVar10 = 0x1a;
          memcpy(puVar10 + 1,L"ScsiMiniPort",0x1a);
          *(ushort *)((ulonglong)uVar5 + (longlong)param_7) = uVar14;
          memcpy((ushort *)((ulonglong)uVar5 + (longlong)param_7) + 1,local_38[0],(ulonglong)uVar14)
          ;
          param_6 = uVar1;
        }
      }
      else {
LAB_1c000f07e:
        param_6 = 0;
      }
      *param_8 = param_6;
LAB_1c000f08d:
      *param_9 = 1;
      return cVar4;
    }
    pcVar6 = *(code **)(param_1 + 0xe);
    if (pcVar6 != (code *)0x0) {
      uVar19 = 0;
      uVar17 = 1;
      goto LAB_1c000f0b5;
    }
  }
LAB_1c000f0c5:
  cVar4 = '\x01';
LAB_1c000f0c8:
  *param_9 = 1;
  return cVar4;
}



===== ScsiPortWmiFireLogicalUnitEvent @ 1c000f0ec =====

void ScsiPortWmiFireLogicalUnitEvent(undefined8 param_1)

{
  undefined4 *in_stack_00000040;
  
  in_stack_00000040[3] = 0;
  in_stack_00000040[0xd] = 0;
  in_stack_00000040[6] = 0x810d265a;
  in_stack_00000040[7] = 0x4583d849;
  in_stack_00000040[8] = 0x5c02e3a4;
  in_stack_00000040[9] = 0xc1c439bc;
  in_stack_00000040[0xb] = 0x8a;
  in_stack_00000040[0xf] = 0xc;
  in_stack_00000040[0xe] = 0x40;
  *in_stack_00000040 = 0x4c;
                    /* WARNING: Could not recover jumptable at 0x0001c000f135. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ScsiPortNotification(8,param_1,in_stack_00000040,0xff);
  return;
}



===== __security_check_cookie @ 1c000f150 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_check_icall @ 1c000f170 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c000f180 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000f1a0 =====

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



===== _guard_dispatch_icall @ 1c000f220 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c000f220. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== memcpy @ 1c000f240 =====

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

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
        if (uVar12 == 0) goto LAB_1c000f3f7;
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
LAB_1c000f3f7:
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
      if (uVar12 == 0) goto LAB_1c000f252;
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
LAB_1c000f252:
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



===== memset @ 1c000f580 =====

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
      if (uVar5 == 0) goto LAB_1c000f640;
      puVar3 = puVar3 + (uVar5 - 8);
      uVar6 = uVar6 + 1;
      switch(uVar5) {
      case 2:
        goto switchD_1c000f63d_caseD_2;
      case 3:
        goto switchD_1c000f63d_caseD_3;
      case 4:
        goto switchD_1c000f63d_caseD_4;
      case 5:
        goto switchD_1c000f63d_caseD_5;
      case 6:
        goto switchD_1c000f63d_caseD_6;
      case 7:
        goto switchD_1c000f63d_caseD_7;
      }
      while( true ) {
        puVar3[7] = uVar4;
        puVar3 = puVar3 + 8;
        uVar6 = uVar6 - 1;
        if (uVar6 == 0) break;
LAB_1c000f640:
        *puVar3 = uVar4;
switchD_1c000f63d_caseD_7:
        puVar3[1] = uVar4;
switchD_1c000f63d_caseD_6:
        puVar3[2] = uVar4;
switchD_1c000f63d_caseD_5:
        puVar3[3] = uVar4;
switchD_1c000f63d_caseD_4:
        puVar3[4] = uVar4;
switchD_1c000f63d_caseD_3:
        puVar3[5] = uVar4;
switchD_1c000f63d_caseD_2:
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



===== entry @ 1c001a000 =====

void entry(undefined8 param_1,undefined8 param_2)

{
  undefined4 local_d8;
  undefined4 local_d4;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  code *local_b8;
  code *local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_80;
  undefined2 local_7c;
  code *local_60;
  code *local_58;
  undefined4 local_20;
  code *local_10;
  
  __security_init_cookie();
  memset(&local_d4,0,0xcc);
  local_d8 = 0xd0;
  local_a8 = 0;
  local_d0 = HwStorInitialize;
  local_a0 = 0;
  local_c0 = HwStorInterrupt;
  local_d4 = 5;
  local_b8 = HwStorFindAdapter;
  local_98 = 0xe0d0;
  local_b0 = HwStorResetBus;
  local_90 = 0x2b8;
  local_60 = HwStorAdapterControl;
  local_58 = HwStorBuildIo;
  local_c8 = HwStorStartIo;
  local_10 = HwUnitControl;
  local_8c = 10;
  local_80 = 0x1010102;
  local_7c = 1;
  local_94 = 0x10;
  local_20 = 0x7e;
  StorPortInitialize(param_1,param_2,&local_d8,0);
  return;
}



===== __security_init_cookie @ 1c001a0fc =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __security_init_cookie(void)

{
  byte *pbVar1;
  byte bVar2;
  code *pcVar3;
  byte bVar4;
  byte *pbVar5;
  byte in_DL;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    pcVar3 = (code *)swi(0x29);
    pbVar5 = (byte *)(*pcVar3)(6);
    bVar4 = (byte)pbVar5;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4;
    bVar2 = *pbVar5;
    *pbVar5 = *pbVar5 + bVar4;
    *pbVar5 = *pbVar5 + bVar4 + CARRY1(bVar2,bVar4);
    bVar2 = *pbVar5;
    *pbVar5 = *pbVar5 + in_DL;
    *pbVar5 = *pbVar5 + bVar4 + CARRY1(bVar2,in_DL);
    pbVar1 = pbVar5 + -0x4fffffef;
    bVar2 = *pbVar1;
    *pbVar1 = *pbVar1 + in_DL;
    *(uint *)pbVar5 = *(int *)pbVar5 + (int)pbVar5 + (uint)CARRY1(bVar2,in_DL);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  ___security_cookie_complement = ~__security_cookie;
  return;
}


