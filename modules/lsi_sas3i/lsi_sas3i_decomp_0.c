
===== BuildIeeeScatterGather @ 140001000 =====

void BuildIeeeScatterGather
               (longlong param_1,longlong param_2,int param_3,longlong param_4,int param_5)

{
  uint *puVar1;
  undefined1 uVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  ulonglong uVar17;
  uint uVar18;
  uint uVar19;
  uint *puVar20;
  uint uVar21;
  int iVar22;
  
  puVar1 = (uint *)(param_4 + 0x60);
  uVar14 = param_5 + (uint)*(ushort *)(param_1 + 0x2ea);
  uVar15 = 0;
  iVar22 = 0;
  puVar20 = (uint *)(param_4 + (ulonglong)*(ushort *)(param_1 + 0x2ea));
  uVar18 = 0x1000000;
  if ((*(uint *)(param_2 + 0x18) & 0x80) == 0) {
    uVar18 = 0x2000000;
  }
  *(uint *)(param_4 + 0x3c) = *(uint *)(param_4 + 0x3c) | uVar18;
  uVar2 = *(undefined1 *)(param_1 + 0x218);
  uVar3 = *(ushort *)(param_1 + 0x2e2);
  uVar21 = (uint)uVar3;
  puVar6 = (uint *)StorPortGetScatterGatherList(param_1);
  uVar18 = *puVar6;
  puVar10 = puVar6 + 4;
  uVar13 = param_3 - *(int *)(param_2 + 0x40);
  if (uVar13 != 0) {
    uVar19 = puVar6[6];
    puVar6 = puVar10;
    if (uVar19 <= uVar13) {
      do {
        puVar10 = puVar6 + 6;
        uVar13 = uVar13 - uVar19;
        uVar18 = uVar18 - 1;
        uVar19 = puVar6[8];
        puVar6 = puVar10;
      } while (uVar19 <= uVar13);
    }
    uVar19 = *(uint *)(param_2 + 0x3c);
    uVar16 = 0;
    puVar6 = puVar10;
    if (uVar18 != 0) {
      do {
        uVar7 = puVar6[2] - uVar13;
        if (puVar6 != puVar10) {
          uVar7 = puVar6[2];
        }
        uVar5 = uVar19;
        iVar4 = uVar7 - uVar19;
        if (uVar7 <= uVar19) {
          uVar5 = uVar7;
          iVar4 = iVar22;
        }
        iVar22 = iVar4;
        uVar19 = uVar19 - uVar5;
        if (uVar19 == 0) break;
        uVar16 = uVar16 + 1;
        puVar6 = puVar6 + 6;
      } while (uVar16 < uVar18);
    }
    uVar18 = uVar16 + 1;
  }
  uVar8 = (ulonglong)uVar3;
  puVar6 = puVar1;
  puVar12 = (uint *)0x0;
  if (uVar18 <= uVar3 + 1) {
    uVar8 = (ulonglong)uVar18;
  }
  while( true ) {
    uVar9 = uVar8;
    puVar11 = puVar6;
    uVar17 = 0;
    if ((int)uVar8 != 0) {
      do {
        *puVar6 = *puVar10;
        puVar6[1] = puVar10[1];
        puVar11 = puVar10 + 2;
        puVar10 = puVar10 + 6;
        puVar6[2] = *puVar11;
        puVar6[3] = 0;
        puVar11 = puVar6 + 4;
        uVar9 = uVar9 - 1;
        puVar6 = puVar11;
        uVar17 = uVar8;
      } while (uVar9 != 0);
    }
    uVar15 = uVar15 + (int)uVar17;
    if (uVar18 <= uVar15) break;
    if (uVar15 == uVar21) {
      *(undefined1 *)(param_4 + 2) = uVar2;
      uVar21 = (uint)*(ushort *)(param_1 + 0x2e4);
    }
    puVar6 = puVar20;
    if (puVar12 != (uint *)0x0) {
      *(char *)((longlong)puVar12 + 0xe) = (char)uVar17;
      puVar12[2] = ((int)uVar17 + 1) * 0x10;
      puVar6 = (uint *)((longlong)puVar20 + (ulonglong)*(ushort *)(param_1 + 0x2e6));
      uVar14 = uVar14 + *(ushort *)(param_1 + 0x2e6);
    }
    *puVar11 = uVar14;
    puVar11[1] = *(uint *)(param_1 + 0x1ec);
    puVar11[3] = 0x80000000;
    uVar19 = uVar18 - uVar15;
    if (uVar21 + 1 < uVar18 - uVar15) {
      uVar19 = uVar21;
    }
    uVar8 = (ulonglong)uVar19;
    puVar12 = puVar11;
    puVar20 = puVar6;
  }
  puVar11[-1] = puVar11[-1] | 0x40000000;
  if (iVar22 != 0) {
    puVar11[-2] = puVar11[-2] - iVar22;
  }
  if (puVar12 != (uint *)0x0) {
    puVar12[2] = (uint)(byte)((char)uVar17 << 4);
    *(undefined1 *)((longlong)puVar12 + 0xe) = 0;
  }
  if (uVar13 != 0) {
    *puVar1 = *puVar1 + uVar13;
    *(int *)(param_4 + 0x68) = *(int *)(param_4 + 0x68) - uVar13;
  }
  return;
}



===== BuildScatterGather @ 140001220 =====

void BuildScatterGather(longlong param_1,longlong param_2,uint *param_3,int param_4,longlong param_5
                       ,uint param_6)

{
  undefined1 uVar1;
  ushort uVar2;
  int iVar3;
  byte bVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  ulonglong uVar17;
  uint uVar18;
  int iVar19;
  uint *puVar20;
  uint uVar21;
  int local_64;
  uint *local_58;
  
  iVar19 = 0;
  param_6 = param_6 + *(ushort *)(param_1 + 0x2ea);
  uVar13 = 0;
  local_64 = 0;
  local_58 = (uint *)(param_5 + (ulonglong)*(ushort *)(param_1 + 0x2ea));
  bVar4 = *(byte *)(param_1 + 0x2f8) & 1;
  uVar7 = *(uint *)(param_2 + 0x18) & 0x80;
  uVar18 = 0x14;
  if (uVar7 == 0) {
    uVar18 = 0x10;
  }
  uVar21 = 0x1000000;
  if (uVar7 == 0) {
    uVar21 = 0x2000000;
  }
  *(uint *)(param_5 + 0x3c) = *(uint *)(param_5 + 0x3c) | uVar21;
  uVar2 = *(ushort *)(param_1 + 0x2de);
  uVar21 = (uint)uVar2;
  uVar7 = uVar18 | 2;
  if (bVar4 == 0) {
    uVar7 = uVar18;
  }
  uVar1 = *(undefined1 *)(param_1 + 0x214);
  puVar5 = (uint *)StorPortGetScatterGatherList(param_1,param_2);
  uVar18 = *puVar5;
  puVar6 = puVar5 + 4;
  uVar14 = param_4 - *(int *)(param_2 + 0x40);
  if (uVar14 != 0) {
    uVar16 = puVar5[6];
    puVar5 = puVar6;
    if (uVar16 <= uVar14) {
      do {
        puVar6 = puVar5 + 6;
        uVar14 = uVar14 - uVar16;
        uVar18 = uVar18 - 1;
        uVar16 = puVar5[8];
        puVar5 = puVar6;
      } while (uVar16 <= uVar14);
    }
    uVar16 = *(uint *)(param_2 + 0x3c);
    uVar15 = 0;
    puVar5 = puVar6;
    if (uVar18 != 0) {
      do {
        uVar9 = puVar5[2] - uVar14;
        if (puVar5 != puVar6) {
          uVar9 = puVar5[2];
        }
        uVar8 = uVar16;
        iVar3 = uVar9 - uVar16;
        if (uVar9 <= uVar16) {
          uVar8 = uVar9;
          iVar3 = iVar19;
        }
        iVar19 = iVar3;
        uVar16 = uVar16 - uVar8;
        if (uVar16 == 0) break;
        uVar15 = uVar15 + 1;
        puVar5 = puVar5 + 6;
      } while (uVar15 < uVar18);
      local_64 = iVar19;
    }
    uVar18 = uVar15 + 1;
  }
  uVar16 = bVar4 + 2;
  uVar10 = (ulonglong)uVar2;
  puVar5 = param_3;
  puVar20 = (uint *)0x0;
  if (uVar18 <= uVar2 + 1) {
    uVar10 = (ulonglong)uVar18;
  }
  while( true ) {
    puVar12 = puVar5;
    uVar17 = 0;
    if ((int)uVar10 != 0) {
      uVar11 = uVar10;
      do {
        *puVar12 = puVar6[2] | uVar7 << 0x18;
        puVar12[1] = *puVar6;
        if (bVar4 != 0) {
          puVar12[2] = puVar6[1];
        }
        puVar12 = puVar12 + uVar16;
        puVar6 = puVar6 + 6;
        uVar11 = uVar11 - 1;
        uVar17 = uVar10;
      } while (uVar11 != 0);
    }
    uVar13 = uVar13 + (int)uVar17;
    puVar5 = puVar12 + -(ulonglong)uVar16;
    if (uVar18 <= uVar13) break;
    *puVar5 = *puVar5 | 0x80000000;
    if (uVar13 == uVar21) {
      *(undefined1 *)(param_5 + 2) = uVar1;
      uVar21 = (uint)*(ushort *)(param_1 + 0x2e0);
    }
    if (puVar20 != (uint *)0x0) {
      *(char *)((longlong)puVar20 + 2) = (char)uVar17 * (char)uVar16;
      *(ushort *)puVar20 = (ushort)(byte)(((char)uVar17 + '\x01') * (char)uVar16 * '\x04');
      local_58 = (uint *)((longlong)local_58 + (ulonglong)*(ushort *)(param_1 + 0x2e6));
      param_6 = param_6 + *(ushort *)(param_1 + 0x2e6);
    }
    *puVar12 = (bVar4 + 0x18) * 0x2000000;
    puVar12[1] = param_6;
    if (bVar4 != 0) {
      puVar12[2] = *(uint *)(param_1 + 0x1ec);
    }
    uVar15 = uVar18 - uVar13;
    if (uVar21 + 1 < uVar18 - uVar13) {
      uVar15 = uVar21;
    }
    uVar10 = (ulonglong)uVar15;
    puVar5 = local_58;
    puVar20 = puVar12;
  }
  uVar7 = *puVar5;
  *puVar5 = uVar7 | 0xc1000000;
  if (local_64 != 0) {
    *puVar5 = (uVar7 | 0xc1000000) - local_64;
  }
  if (puVar20 != (uint *)0x0) {
    *(undefined1 *)((longlong)puVar20 + 2) = 0;
    *(ushort *)puVar20 = (short)uVar17 * (bVar4 + 2) * 4 & 0xff;
  }
  if ((uVar14 != 0) && (param_3 != (uint *)0x0)) {
    *param_3 = *param_3 - uVar14;
    param_3[1] = param_3[1] + uVar14;
  }
  return;
}



===== BuildZeroLenSGE @ 140001530 =====

void BuildZeroLenSGE(longlong param_1,longlong param_2,int param_3,char param_4)

{
  if (param_4 == '\0') {
    *(undefined4 *)(param_2 + 0x60) = 0xd3000000;
    *(int *)(param_2 + 100) = param_3 + 0x70;
    *(undefined4 *)(param_2 + 0x68) = *(undefined4 *)(param_1 + 0x1ec);
    return;
  }
  *(undefined4 *)(param_2 + 0x68) = 0;
  *(undefined1 *)(param_2 + 0x6f) = 0x40;
  *(int *)(param_2 + 0x60) = param_3 + 0x70;
  *(undefined4 *)(param_2 + 100) = *(undefined4 *)(param_1 + 0x1ec);
  return;
}



===== DriverEntry @ 140001570 =====

void DriverEntry(undefined8 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 local_d8;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  code *local_b8;
  code *local_b0;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_80;
  undefined1 local_7c;
  code *local_60;
  code *local_58;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  lVar3 = 3;
  puVar1 = &local_d8;
  do {
    puVar2 = puVar1;
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
    puVar2[7] = 0;
    lVar3 = lVar3 + -1;
    puVar1 = puVar2 + 8;
  } while (lVar3 != 0);
  puVar2[8] = 0;
  puVar2[9] = 0;
  local_d0 = LSImpiHWInitialize;
  local_c8 = LSImpiStartIo;
  local_c0 = LSImpiIsr;
  local_b8 = LSImpiFindAdapter;
  local_b0 = LSImpiOSReset;
  local_60 = LSImpiAdapterControl;
  local_58 = LSImpiBuildIo;
  local_d8._0_4_ = 0xd0;
  local_80 = 0x1010102;
  local_8c = 2;
  local_d8._4_4_ = 5;
  local_7c = 1;
  local_98 = 0xb568;
  local_90 = 0x420;
  local_94 = 0x34;
  local_1c = 2;
  local_18 = 1;
  local_20 = 0x22;
  StorPortInitialize(param_1,param_2,&local_d8);
  return;
}



===== InternalLSImpiHWInitialize @ 140001690 =====

ulonglong InternalLSImpiHWInitialize(longlong param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  undefined8 uVar3;
  undefined7 extraout_var;
  uint *puVar4;
  longlong lVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong lVar8;
  
  iVar2 = StorPortExtendedFunction(0xd,param_1,0,param_1 + 0x108);
  if (iVar2 == 0) {
    *(undefined1 *)(param_1 + 0x129) = 1;
    if ((*(char *)(param_1 + 0x12a) != '\0') && (*(char *)(param_1 + 0xe96) == '\0')) {
      *(undefined1 *)(param_1 + 0x12a) = 0;
      iVar2 = StorPortExtendedFunction(0xe,param_1,1,param_1 + 0x130);
      if (iVar2 == 0) {
        *(undefined4 *)(param_1 + 0x134) = 0x28;
        *(undefined4 *)(param_1 + 0x130) = 5;
        if ((*(uint *)(param_1 + 0x138) & 1) != 0) {
          *(undefined4 *)(param_1 + 0x138) = 1;
          iVar2 = StorPortExtendedFunction(0xe,param_1,0,param_1 + 0x130);
          if (iVar2 == 0) {
            *(undefined1 *)(param_1 + 0x12a) = 1;
          }
        }
      }
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x12a) = 0;
  }
  if ((*(byte *)(param_1 + 0x12a) & *(byte *)(param_1 + 0xeb2)) != 0) {
    lVar6 = 0x10;
    lVar8 = 0xb;
    plVar7 = (longlong *)(param_1 + 0x68);
    do {
      lVar5 = *(longlong *)(param_1 + 0x10) + 0x30c + lVar6;
      lVar6 = lVar6 + 0x10;
      *plVar7 = lVar5;
      lVar8 = lVar8 + -1;
      plVar7 = plVar7 + 1;
    } while (lVar8 != 0);
  }
  if ((**(uint **)(param_1 + 0x18) & 0xf0000000) != 0x20000000) {
    return (ulonglong)*(uint **)(param_1 + 0x18) & 0xffffffffffffff00;
  }
  ClearResetHistoryBit(param_1,param_2);
  **(uint **)(param_1 + 0x50) = **(uint **)(param_1 + 0x50) | 0x40000009;
  LOCK();
  UNLOCK();
  uVar3 = FwDiagPostImmediateBuffers(param_1,param_2);
  if ((char)uVar3 == '\0') {
    LogSystemEvent(param_1,0xad01002a,0xc004af02,
                   (byte *)"FW diagnostic buffer post failed (HWInitialize)",param_2);
  }
  puVar4 = *(uint **)(param_1 + 0x50);
  *puVar4 = **(uint **)(param_1 + 0x50) & 0xfffffff7;
  LOCK();
  UNLOCK();
  *(undefined4 *)(param_1 + 0x1608) = 1;
  if ((*(int *)(param_1 + 0x630) == 0) && (*(char *)(param_1 + 0xb4a8) != '\0')) {
    bVar1 = GtfStartTimer(param_1,1,300,DetectSataPfa,0,param_2);
    puVar4 = (uint *)CONCAT71(extraout_var,bVar1);
    *(byte *)(param_1 + 0xb4ab) = bVar1;
    if ((bVar1 == 0xfe) &&
       ((*(char *)(param_1 + 0x3b8) != '\0' &&
        (puVar4 = (uint *)(ulonglong)*(uint *)(param_1 + 0x3bc),
        (*(uint *)(param_1 + 0x3bc) & 0x233) != 0)))) {
      puVar4 = (uint *)RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x233,
                                   (undefined1 *)0x0,0,param_2);
    }
  }
  if (*(char *)(param_1 + 0xe96) == '\0') {
    *(undefined1 *)(param_1 + 0xe96) = 1;
    *(undefined1 *)(param_1 + 0xe7f) = 0;
  }
  return CONCAT71((int7)((ulonglong)puVar4 >> 8),1);
}



===== LSImpiBuildIo @ 1400018d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 LSImpiBuildIo(longlong param_1,longlong param_2)

{
  uint *puVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  undefined1 uVar5;
  byte bVar6;
  byte bVar7;
  short sVar8;
  uint *puVar9;
  ulonglong uVar10;
  int iVar11;
  uint uVar12;
  ulonglong uVar13;
  uint *puVar14;
  int *piVar15;
  ushort uVar16;
  short *psVar17;
  longlong lVar18;
  uint uVar19;
  undefined1 auStackY_a8 [32];
  undefined1 local_5c [4];
  undefined1 local_58 [4];
  undefined4 local_54;
  byte local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_a8;
  cVar2 = *(char *)(param_1 + 0xeb2);
  puVar9 = *(uint **)(param_2 + 0x68);
  if (*(char *)(param_2 + 2) != '(') {
    *(undefined1 *)(param_2 + 3) = 0x22;
LAB_14000190d:
    uVar13 = StorPortNotification(0,param_1,param_2);
    return uVar13 & 0xffffffffffffff00;
  }
  if (*(int *)(param_1 + 0xec0) != 0) {
    *(undefined1 *)(param_2 + 3) = 5;
    goto LAB_14000190d;
  }
  psVar17 = (short *)((ulonglong)*(uint *)(param_2 + 0x34) + param_2);
  if (*psVar17 != 1) {
    *(undefined1 *)(param_2 + 3) = 4;
    goto LAB_14000190d;
  }
  bVar3 = *(byte *)(psVar17 + 4);
  *(byte *)((longlong)puVar9 + 0x5a) = bVar3;
  bVar4 = *(byte *)((longlong)psVar17 + 9);
  *(byte *)((longlong)puVar9 + 0x5b) = bVar4;
  uVar5 = (undefined1)psVar17[5];
  *(undefined1 *)(puVar9 + 0x17) = uVar5;
  uVar13 = 0;
  switch(*(undefined4 *)(param_2 + 0x14)) {
  case 0:
    uVar19 = 0;
    if (*(uint *)(param_2 + 0x38) != 0) {
      while( true ) {
        piVar15 = (int *)((ulonglong)*(uint *)(param_2 + 0x78 + (ulonglong)uVar19 * 4) + param_2);
        iVar11 = *piVar15;
        uVar12 = iVar11 - 0x40;
        if (uVar12 < 2) break;
        uVar19 = uVar19 + 1;
        if (*(uint *)(param_2 + 0x38) <= uVar19) {
          return CONCAT71((uint7)(uint3)(uVar12 >> 8),1);
        }
      }
      *(int **)(puVar9 + 0x10) = piVar15;
      uVar16 = (ushort)bVar3 * 0x80 + (ushort)bVar4;
      if ((uint)uVar16 < *(uint *)(param_1 + 0x678)) {
        lVar18 = *(longlong *)(param_1 + 0x378) + (ulonglong)uVar16 * 0x28;
        sVar8 = *(short *)(*(longlong *)(param_1 + 0x378) + 0x1a + (ulonglong)uVar16 * 0x28);
        if ((sVar8 != 0) && (*(char *)(lVar18 + 0x23) == '\0')) {
          bVar6 = *(byte *)(piVar15 + 6);
          *(byte *)(puVar9 + 0x16) = bVar6;
          bVar7 = *(byte *)((longlong)piVar15 + 0x19);
          *(byte *)((longlong)puVar9 + 0x59) = bVar7;
          uVar19 = *(uint *)(param_2 + 0x18);
          puVar1 = puVar9 + 0x58;
          *puVar9 = (uint)*(byte *)(lVar18 + 0x24);
          ZeroMemory((undefined1 *)puVar1,0x60);
          *(short *)puVar1 = sVar8;
          *(undefined1 *)((longlong)puVar9 + 0x163) = 0;
          *(undefined1 *)(puVar9 + 0x5d) = 0x18;
          *(ushort *)(puVar9 + 0x61) = (ushort)*(byte *)((longlong)piVar15 + 10);
          *(undefined1 *)((longlong)puVar9 + 0x195) = uVar5;
          if (iVar11 == 0x41) {
            iVar11 = *(byte *)((longlong)piVar15 + 10) - 0x10;
            puVar9[0x67] = ((int)(iVar11 + (iVar11 >> 0x1f & 3U)) >> 2) << 0x1a |
                           puVar9[0x67] & 0x3ffffff;
          }
          if (*puVar9 != 0) {
            *(ushort *)(puVar9 + 0x61) = (ushort)puVar9[0x61] | 0x4000;
          }
          if ((uVar19 & 2) == 0) {
            uVar12 = 0;
          }
          else {
            uVar12 = (*(ushort *)(param_2 + 0x26) & 3) << 8;
          }
          uVar12 = puVar9[0x67] & 0xfffff8ff | uVar12;
          puVar9[0x67] = uVar12;
          puVar9[0x67] = (*(byte *)(lVar18 + 0x22) ^ uVar12) & 0xc0 ^ uVar12;
          memmove(puVar9 + 0x68,piVar15 + 6,(ulonglong)*(byte *)((longlong)piVar15 + 10));
          if (((*(char *)(param_1 + 0xe97) != '\0') && (bVar6 = (&OpCodeProt)[bVar6], bVar6 != 0))
             && (puVar14 = (uint *)StorPortGetLogicalUnit(param_1,bVar3,bVar4,uVar5),
                (char)puVar14[1] != '\0')) {
            if (*(char *)(param_1 + 0xeb2) == '\0') {
              puVar9[0x62] = *puVar14;
            }
            else {
              *(short *)(puVar9 + 0x62) = (short)*puVar14;
            }
            uVar16 = (ushort)puVar9[0x61] & 0x1ff;
            *(ushort *)((longlong)puVar9 + 0x186) = bVar6 | 0x8500;
            if (uVar16 == 0x20) {
              *(ushort *)((longlong)puVar9 + 0x186) = bVar6 | 0xa500;
              *(byte *)((longlong)puVar9 + 0x1aa) =
                   *(byte *)((longlong)piVar15 + 0x22) & 0x1f | 0x20;
            }
            else {
              lVar18 = 0x42;
              if (uVar16 == 0x10) {
                lVar18 = 0x46;
              }
              memmove(puVar9 + 0x6d,(undefined1 *)(lVar18 + (longlong)puVar1),4);
              *(undefined2 *)((longlong)puVar9 + 0x1ba) = 0xffff;
              *(byte *)((longlong)puVar9 + 0x1a1) = bVar7 & 0x1f | 0x20;
            }
          }
          puVar9[0x5f] = *(uint *)(param_2 + 0x3c);
          uVar12 = StorPortGetPhysicalAddress(param_1,param_2,puVar1,local_5c);
          *(undefined1 *)((longlong)puVar9 + 0x172) = 0xff;
          puVar9[0x5b] = uVar12 - 0x100;
          if ((uVar19 & 0xc0) == 0) {
            if (cVar2 == '\0') {
              puVar9[0x70] = 0xd3000000;
              puVar9[0x71] = uVar12 + 0x70;
              uVar13 = (ulonglong)*(uint *)(param_1 + 0x1ec);
              puVar9[0x72] = *(uint *)(param_1 + 0x1ec);
            }
            else {
              puVar9[0x72] = 0;
              *(undefined1 *)((longlong)puVar9 + 0x1cf) = 0x40;
              puVar9[0x70] = uVar12 + 0x70;
              uVar13 = (ulonglong)*(uint *)(param_1 + 0x1ec);
              puVar9[0x71] = *(uint *)(param_1 + 0x1ec);
            }
          }
          else {
            iVar11 = (int)*(undefined8 *)(param_2 + 0x40);
            if (cVar2 == '\0') {
              uVar13 = BuildScatterGather(param_1,param_2,puVar9 + 0x70,iVar11,(longlong)puVar1,
                                          uVar12);
            }
            else {
              uVar13 = BuildIeeeScatterGather(param_1,param_2,iVar11,(longlong)puVar1,uVar12);
            }
          }
          if (*(char *)(param_1 + 0x12a) != '\0') {
            local_54 = 0x10;
            uVar13 = StorPortExtendedFunction(0xf,param_1,param_2,local_58);
            if ((int)uVar13 == 0) {
              *puVar9 = *puVar9 | (uint)local_50 << 8;
              return CONCAT71((uint7)local_50,1);
            }
          }
          break;
        }
      }
      *(undefined1 *)(param_2 + 3) = 10;
      goto LAB_140001d11;
    }
    break;
  default:
    *(undefined1 *)(param_2 + 3) = 0x22;
    goto LAB_140001d11;
  case 2:
  case 0x12:
  case 0x13:
  case 0x17:
  case 0x20:
    break;
  case 0x10:
  case 0x14:
    *(undefined1 *)(param_2 + 3) = 3;
LAB_140001d11:
    uVar13 = StorPortNotification(0,param_1,param_2);
    return uVar13 & 0xffffffffffffff00;
  case 0x24:
    uVar10 = 0;
    if (*(int *)(param_2 + 0x38) != 0) {
      do {
        uVar13 = uVar10;
        piVar15 = (int *)((ulonglong)*(uint *)(param_2 + 0x78 + uVar13 * 4) + param_2);
        if (*piVar15 == 0x61) {
          *(int **)(puVar9 + 0x12) = piVar15;
        }
        uVar19 = (int)uVar13 + 1;
        uVar10 = (ulonglong)uVar19;
      } while (uVar19 < *(uint *)(param_2 + 0x38));
    }
  }
  return CONCAT71((int7)(uVar13 >> 8),1);
}



===== LSImpiFindAdapter @ 140001d90 =====

undefined8
LSImpiFindAdapter(longlong *param_1,undefined8 param_2,undefined8 param_3,byte *param_4,
                 longlong param_5)

{
  longlong *plVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  uint uVar7;
  undefined8 *puVar8;
  longlong lVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  undefined2 uVar13;
  undefined4 uVar14;
  ushort uVar15;
  int iVar16;
  ushort uVar17;
  uint uVar18;
  undefined8 *puVar19;
  uint *puVar20;
  int iVar21;
  undefined8 *puVar22;
  char *pcVar23;
  undefined8 in_stack_ffffffffffffff88;
  uint local_58;
  ushort local_54;
  uint local_50;
  undefined3 local_4c;
  char cStack_49;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  
  uVar14 = (undefined4)((ulonglong)in_stack_ffffffffffffff88 >> 0x20);
  local_4c = 0x535054;
  cStack_49 = '0';
  local_3c = local_3c & 0xffff0000;
  local_50 = 0;
  local_40 = 0;
  local_38 = 0;
  if (*param_1 != 0) {
    ZeroMemory((undefined1 *)param_1,0xb568);
  }
  *(undefined1 *)(param_1 + 0x25) = 0;
  *(undefined1 *)((longlong)param_1 + 0xe75) = 0;
  *(undefined1 *)((longlong)param_1 + 0xb4a5) = 1;
  GtfInitialize((longlong)param_1);
  *(undefined1 *)((longlong)param_1 + 0xe7f) = 1;
  puVar8 = *(undefined8 **)(param_5 + 0x38);
  if (*(int *)(puVar8 + 1) != 0) {
    puVar22 = puVar8;
    puVar19 = (undefined8 *)0x0;
    if (*(char *)((longlong)puVar8 + 0xc) == '\0') {
      puVar22 = (undefined8 *)0x0;
      puVar19 = puVar8;
    }
    if (*(int *)(puVar8 + 3) != 0) {
      if (*(char *)((longlong)puVar8 + 0x1c) == '\0') {
        puVar19 = puVar8 + 2;
      }
      else {
        puVar8 = puVar8 + 2;
        if (puVar22 != (undefined8 *)0x0) {
          puVar8 = puVar22;
        }
        puVar22 = puVar8;
      }
    }
    if (puVar22 != (undefined8 *)0x0) {
      if (puVar19 != (undefined8 *)0x0) {
        *(undefined4 *)((longlong)param_1 + 0x15fc) = *(undefined4 *)puVar19;
      }
      *(undefined4 *)(param_1 + 0x2c0) = *(undefined4 *)puVar22;
      *(undefined4 *)((longlong)param_1 + 0x1604) = *(undefined4 *)((longlong)puVar22 + 4);
      *(undefined4 *)(param_1 + 0x2c1) = 3;
      *(undefined4 *)(param_1 + 0x2da) = 1;
      lVar9 = StorPortGetDeviceBase
                        (param_1,*(undefined4 *)(param_5 + 8),*(undefined4 *)(param_5 + 4),*puVar22,
                         CONCAT44(uVar14,*(undefined4 *)(puVar22 + 1)),
                         *(char *)((longlong)puVar22 + 0xc) == '\0');
      param_1[2] = lVar9;
      if (puVar19 != (undefined8 *)0x0) {
        lVar9 = StorPortGetDeviceBase
                          (param_1,*(undefined4 *)(param_5 + 8),*(undefined4 *)(param_5 + 4),
                           *puVar19,*(undefined4 *)(puVar19 + 1),
                           *(char *)((longlong)puVar19 + 0xc) == '\0');
        param_1[0x1f] = lVar9;
      }
      if (param_1[2] == 0) {
        pcVar23 = "could not get the chips IO address space correctly";
        uVar14 = 0xad010002;
        goto LAB_140003020;
      }
      local_44 = StorPortGetBusData(param_1,4,*(undefined4 *)(param_5 + 4),
                                    *(undefined4 *)(param_5 + 100),param_1 + 0x280,0x100);
      lVar9 = param_1[2];
      param_1[3] = lVar9;
      param_1[4] = lVar9 + 4;
      param_1[5] = lVar9 + 8;
      param_1[6] = lVar9 + 0x10;
      param_1[7] = lVar9 + 0x14;
      param_1[8] = lVar9 + 0x18;
      param_1[9] = lVar9 + 0x30;
      param_1[10] = lVar9 + 0x34;
      param_1[0xb] = lVar9 + 0x48;
      param_1[0xc] = lVar9 + 0x6c;
      lVar9 = param_1[2];
      param_1[0x1c] = lVar9 + 0x74;
      param_1[0x1d] = lVar9 + 0xc0;
      param_1[0x1e] = lVar9 + 0xc4;
      if ((*(uint *)param_1[3] & 0x7000000) == 0x3000000) {
        pcVar23 = "PCI Peer device controls this IOC";
        uVar14 = 0xad010018;
        goto LAB_140003020;
      }
      if (param_4 != (byte *)0x0) {
        ProcessParseArgumentString(param_4,(byte *)"dump",(int *)&local_50);
        ProcessParseArgumentString(param_4,(byte *)"ntldr",(int *)&local_40);
        local_50 = local_50 | local_40;
        if (local_50 != 0) {
          *(uint *)(param_1 + 0xc6) = local_50;
        }
      }
      if (2 < local_44) {
        *(uint *)(param_1 + 0xc2) = (uint)*(ushort *)((longlong)param_1 + 0x1402);
        local_38 = *(int *)(param_5 + 4) << 8 | *(uint *)(param_5 + 100);
        GetCimData((longlong)param_1,(longlong)(param_1 + 0x280),local_38);
      }
      if ((*(uint *)param_1[3] >> 0x1b & 1) != 0) {
        KickStart((longlong)param_1,1);
      }
      uVar7 = *(uint *)param_1[3];
      uVar18 = 0;
      while (uVar7 = uVar7 & 0xf0000000, uVar7 != 0x10000000) {
        if (uVar7 == 0x20000000) {
          IssueIOCFacts((longlong)param_1,1);
          if ((*(uint *)((longlong)param_1 + 0xeb4) & 0x2000) == 0) {
            KickStart((longlong)param_1,1);
          }
          else {
            IssueReset((longlong)param_1,0x40);
          }
        }
        else if ((uVar7 != 0) && (uVar11 = KickStart((longlong)param_1,1), (char)uVar11 == '\0')) {
          return 2;
        }
        lVar9 = 100;
        do {
          StorPortStallExecution(1000);
          lVar9 = lVar9 + -1;
        } while (lVar9 != 0);
        if (200 < uVar18) {
          pcVar23 = "IOC would not come to the READY state";
          uVar14 = 0xad010003;
          goto LAB_140002319;
        }
        uVar18 = uVar18 + 1;
        uVar7 = *(uint *)param_1[3];
      }
      uVar10 = IssueIOCFacts((longlong)param_1,1);
      if ((char)uVar10 == '\0') {
        return 2;
      }
      if (*(ushort *)(param_1 + 0xcd) < 0x205) {
        pcVar23 = "Invalid MPI message version reported in IOCFacts";
        uVar14 = 0xad010077;
LAB_140002319:
        LogSystemEvent((longlong)param_1,uVar14,0xc004af02,(byte *)pcVar23,1);
        return 2;
      }
      uVar2 = *(ushort *)((longlong)param_1 + 0x2ea);
      lVar9 = 10;
      uVar4 = *(ushort *)(param_1 + 0x5d);
      local_48 = (uint)*(ushort *)((longlong)param_1 + 0x2f6);
      uVar7 = 0;
      *(undefined4 *)((longlong)param_1 + 0x644) = 0x40;
      *(undefined1 *)((longlong)param_1 + 0xeb2) = 1;
      *(undefined4 *)(param_1 + 0x1c0) = 6;
      *(undefined4 *)(param_1 + 0xc9) = 0x20;
      *(undefined4 *)(param_1 + 200) = 10;
      local_54 = uVar4;
      if (*(short *)((longlong)param_1 + 0x656) != 0) {
        do {
          uVar11 = IssuePortFacts((longlong)param_1,(char)uVar7,1);
          if ((char)uVar11 == '\0') {
            return 2;
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(ushort *)((longlong)param_1 + 0x656));
      }
      plVar1 = param_1 + 0x71;
      *(undefined4 *)(param_1 + 0xb8) = 5;
      RttSetTraceParameters((longlong)plVar1,0x19000,1);
      if (param_4 == (byte *)0x0) goto LAB_140002926;
      uVar10 = ProcessParseArgumentString
                         (param_4,(byte *)"LogFullPersistentTableEvent",(int *)&local_58);
      if ((char)uVar10 != '\0') {
        *(bool *)((longlong)param_1 + 0xb4a5) = local_58 != 0;
      }
      uVar10 = ProcessParseArgumentString(param_4,(byte *)"RTTraceBufferSize",(int *)&local_58);
      if (((char)uVar10 != '\0') && (local_58 != 0)) {
        if ((local_58 & 3) != 0) {
          local_58 = local_58 + (4 - (local_58 & 3));
        }
        RttSetTraceParameters((longlong)plVar1,local_58,2);
      }
      uVar10 = ProcessParseArgumentString(param_4,(byte *)"SizeOfReplyBuffer",(int *)&local_58);
      if (((char)uVar10 != '\0') && (0x44 < local_58)) {
        if ((local_58 & 3) != 0) {
          local_58 = 4 - (local_58 & 3);
        }
        uVar4 = (ushort)local_58;
        local_54 = uVar4;
      }
      uVar10 = ProcessParseArgumentString(param_4,(byte *)"SSU_Enables",(int *)&local_58);
      if ((char)uVar10 == '\0') {
        *(undefined2 *)(param_1 + 0x1664) = 1;
        uVar13 = 1;
        if (((char)param_1[0x77] != '\0') && ((*(uint *)((longlong)param_1 + 0x3bc) & 0x110) != 0))
        {
          RttLogEvent(param_1,(char *)((longlong)param_1 + 0xe7f),(int *)plVar1,0x110,
                      (undefined1 *)0x0,0,1);
          uVar13 = (undefined2)param_1[0x1664];
        }
      }
      else {
        if (((3 < local_58) && (local_58 = 1, (char)param_1[0x77] != '\0')) &&
           ((*(uint *)((longlong)param_1 + 0x3bc) & 0x110) != 0)) {
          RttLogEvent(param_1,(char *)((longlong)param_1 + 0xe7f),(int *)plVar1,0x110,
                      (undefined1 *)&local_58,4,1);
        }
        uVar13 = (undefined2)local_58;
        *(undefined2 *)(param_1 + 0x1664) = uVar13;
      }
      *(undefined2 *)((longlong)param_1 + 0xb324) = uVar13;
      uVar10 = ProcessParseArgumentString
                         (param_4,(byte *)"NumberOfRequestMessageBuffers",(int *)&local_58);
      if (((char)uVar10 != '\0') && (local_3c = 0x10, 0x10 < local_58)) {
        local_3c = local_58 & 0xffff;
      }
      uVar10 = ProcessParseArgumentString(param_4,(byte *)"LogExceptionEvents",(int *)&local_58);
      if (((char)uVar10 != '\0') && (local_58 != 0)) {
        *(undefined2 *)(param_1 + 0xc4) = 1;
      }
      uVar10 = ProcessParseArgumentString(param_4,(byte *)"DisableRescan",(int *)&local_58);
      if (((char)uVar10 != '\0') && (local_58 != 0)) {
        *(undefined2 *)((longlong)param_1 + 0x666) = 1;
      }
      uVar10 = ProcessParseArgumentString(param_4,(byte *)"StopOnBusReset",(int *)&local_58);
      if (((char)uVar10 != '\0') && (local_58 != 0)) {
        *(undefined1 *)((longlong)param_1 + 0xe71) = 1;
      }
      uVar10 = ProcessParseArgumentString(param_4,(byte *)"StopOnDiagReset",(int *)&local_58);
      if (((char)uVar10 != '\0') && (local_58 != 0)) {
        *(undefined1 *)((longlong)param_1 + 0xe72) = 1;
      }
      uVar10 = ProcessParseArgumentString(param_4,(byte *)"StopOnOrphanedReset",(int *)&local_58);
      if (((char)uVar10 != '\0') && (local_58 != 0)) {
        *(undefined1 *)((longlong)param_1 + 0xe73) = 1;
      }
      uVar10 = ProcessParseArgumentString
                         (param_4,(byte *)"DisableFwQueueFullHandling",(int *)&local_58);
      if (((char)uVar10 != '\0') && (local_58 != 0)) {
        *(undefined1 *)((longlong)param_1 + 0xeb3) = 0;
      }
      uVar10 = ProcessParseArgumentString(param_4,(byte *)"EEDP_Enable",(int *)&local_58);
      if ((((char)uVar10 != '\0') && (local_58 != 0)) &&
         ((*(uint *)((longlong)param_1 + 0xeb4) & 0x40) != 0)) {
        *(undefined1 *)((longlong)param_1 + 0xe97) = 1;
      }
      uVar10 = ProcessParseArgumentString(param_4,(byte *)"DisableHashSASAddr",(int *)&local_58);
      if (((char)uVar10 != '\0') && (local_58 != 0)) {
        *(undefined1 *)((longlong)param_1 + 0xe8d) = 1;
      }
      uVar10 = ProcessParseArgumentString
                         (param_4,(byte *)"EnableSataSmartErrPolling",(int *)&local_58);
      if (((char)uVar10 != '\0') && (local_58 != 0)) {
        *(undefined1 *)(param_1 + 0x1695) = 1;
      }
      uVar10 = ProcessParseArgumentString(param_4,(byte *)"MaxSGList",(int *)&local_58);
      if (((char)uVar10 != '\0') && (0x10 < local_58)) {
        *(uint *)((longlong)param_1 + 0x64c) = local_58;
      }
      uVar10 = ProcessParseArgumentString(param_4,(byte *)"MaxSASQueueDepth",(int *)&local_58);
      if ((char)uVar10 != '\0') {
        uVar7 = local_58;
        if (local_58 == 0) {
          uVar7 = 1;
        }
        *(uint *)((longlong)param_1 + 0x644) = uVar7;
      }
      uVar10 = ProcessParseArgumentString(param_4,(byte *)"MaxSATAQueueDepth",(int *)&local_58);
      if ((char)uVar10 != '\0') {
        uVar7 = local_58;
        if (local_58 == 0) {
          uVar7 = 1;
        }
        *(uint *)(param_1 + 0xc9) = uVar7;
      }
      uVar10 = ProcessParseArgumentString(param_4,(byte *)"ResumeDelay",(int *)&local_58);
      if (((char)uVar10 != '\0') && (local_58 != 0)) {
        *(uint *)(param_1 + 200) = local_58;
      }
      uVar10 = ProcessParseArgumentString(param_4,(byte *)"FastPathToggleLimit",(int *)&local_58);
      if (((char)uVar10 != '\0') && (local_58 != 0)) {
        *(char *)((longlong)param_1 + 0xec6) = (char)local_58;
      }
      uVar10 = ProcessParseArgumentString(param_4,&s_PSuite,(int *)&local_58);
      if (((char)uVar10 != '\0') && (local_58 != 0)) {
        *(undefined1 *)((longlong)param_1 + 0xe6b) = 1;
      }
      uVar10 = ProcessParseArgumentString(param_4,(byte *)"MaxPersistentEntries",(int *)&local_58);
      if ((char)uVar10 != '\0') {
        uVar5 = (ushort)local_58;
        if (*(ushort *)(param_1 + 0xcb) < (ushort)local_58) {
          uVar5 = *(ushort *)(param_1 + 0xcb);
        }
        *(ushort *)((longlong)param_1 + 0x1564) = uVar5;
      }
      uVar10 = ProcessParseArgumentString(param_4,(byte *)"EnaDiag",(int *)&local_58);
      if (((char)uVar10 != '\0') && (local_58 != 0)) {
        uVar10 = ProcessParseArgumentString(param_4,&s_SSBuffSize,(int *)&local_58);
        if (((char)uVar10 != '\0') && ((local_58 != 0 && ((char)param_1[0x276] != '\0')))) {
          *(uint *)(param_1 + 0x275) = local_58;
        }
        uVar10 = ProcessParseArgumentString(param_4,&s_SSImmed,(int *)&local_58);
        if ((((char)uVar10 != '\0') && (local_58 != 0)) && ((char)param_1[0x276] != '\0')) {
          *(undefined1 *)((longlong)param_1 + 0x13af) = 1;
        }
        uVar10 = ProcessParseArgumentString(param_4,&s_TBuffSize,(int *)&local_58);
        if ((((char)uVar10 != '\0') && (local_58 != 0)) && ((char)param_1[0x273] != '\0')) {
          *(uint *)(param_1 + 0x272) = local_58;
        }
        uVar10 = ProcessParseArgumentString(param_4,&s_TImmed,(int *)&local_58);
        if ((((char)uVar10 != '\0') && (local_58 != 0)) && ((char)param_1[0x273] != '\0')) {
          *(undefined1 *)((longlong)param_1 + 0x1397) = 1;
        }
        puVar20 = (uint *)(param_1 + 0x27a);
        do {
          uVar10 = ProcessParseArgumentString(param_4,(byte *)&local_4c,(int *)&local_58);
          if ((((char)uVar10 != '\0') && (local_58 != 0)) && ((char)param_1[0x273] != '\0')) {
            *puVar20 = local_58;
          }
          cStack_49 = cStack_49 + '\x01';
          puVar20 = puVar20 + 1;
          lVar9 = lVar9 + -1;
        } while (lVar9 != 0);
        uVar10 = ProcessParseArgumentString(param_4,&s_EXBuffSize,(int *)&local_58);
        if ((((char)uVar10 != '\0') && (local_58 != 0)) && ((char)param_1[0x279] != '\0')) {
          *(uint *)(param_1 + 0x278) = local_58;
        }
        uVar10 = ProcessParseArgumentString(param_4,&s_EXImmed,(int *)&local_58);
        if ((((char)uVar10 != '\0') && (local_58 != 0)) && ((char)param_1[0x279] != '\0')) {
          *(undefined1 *)((longlong)param_1 + 0x13c7) = 1;
        }
        uVar10 = ProcessParseArgumentString(param_4,(byte *)"EXType",(int *)&local_58);
        if ((((char)uVar10 != '\0') && (local_58 != 0)) && ((char)param_1[0x279] != '\0')) {
          *(char *)((longlong)param_1 + 0x13c5) = (char)local_58;
        }
      }
      uVar10 = ProcessParseArgumentString(param_4,(byte *)"AutoFWDiagBufferUpload",(int *)&local_58)
      ;
      if ((char)uVar10 != '\0') {
        if ((local_58 == 0) || ((char)param_1[0x273] == '\0')) {
          if (((char)param_1[0x77] != '\0') && ((*(uint *)((longlong)param_1 + 0x3bc) & 0x241) != 0)
             ) {
            uVar14 = 0x241;
            goto LAB_1400028eb;
          }
        }
        else {
          *(undefined1 *)(param_1 + 0x166a) = 1;
          *(uint *)(param_1 + 0x1cc) = *(uint *)(param_1 + 0x1cc) | 0x4000;
          if (((*(uint *)(param_1 + 0x272) < 4000000) &&
              (*(undefined4 *)(param_1 + 0x272) = 4000000, (char)param_1[0x77] != '\0')) &&
             ((*(uint *)((longlong)param_1 + 0x3bc) & 0x10f) != 0)) {
            RttLogEvent(param_1,(char *)((longlong)param_1 + 0xe7f),(int *)(param_1 + 0x71),0x10f,
                        (undefined1 *)0x0,0,1);
          }
          if (((*(char *)((longlong)param_1 + 0x1397) == '\0') &&
              (*(undefined1 *)((longlong)param_1 + 0x1397) = 1, (char)param_1[0x77] != '\0')) &&
             ((*(uint *)((longlong)param_1 + 0x3bc) & 0x10f) != 0)) {
            uVar14 = 0x10f;
LAB_1400028eb:
            RttLogEvent(param_1,(char *)((longlong)param_1 + 0xe7f),(int *)(param_1 + 0x71),uVar14,
                        (undefined1 *)0x0,0,1);
          }
        }
      }
      if (local_50 != 0) {
        uVar10 = ProcessParseArgumentString(param_4,(byte *)"CrashModeMaxDevices",(int *)&local_58);
        if (((char)uVar10 == '\0') || (uVar7 = local_58, local_58 == 0)) {
          uVar7 = 0x40;
        }
        *(short *)(param_1 + 0xcb) = (short)uVar7;
      }
LAB_140002926:
      *(undefined2 *)(param_1 + 0xcc) = 1;
      if (0x80 < *(ushort *)(param_1 + 0xcb)) {
        uVar5 = 1;
        uVar10 = (ulonglong)(ushort)(((ushort)(*(ushort *)(param_1 + 0xcb) - 0x81) >> 7) + 1);
        do {
          uVar5 = uVar5 + 1;
          uVar10 = uVar10 - 1;
        } while (uVar10 != 0);
        *(ushort *)(param_1 + 0xcc) = uVar5;
        if (8 < uVar5) {
          *(undefined2 *)(param_1 + 0xcc) = 8;
        }
      }
      *(undefined1 *)(param_5 + 0x92) = 0xff;
      if (*(char *)(param_5 + 0x90) == -0x80) {
        *(undefined1 *)(param_5 + 0x90) = 4;
        *(uint *)(param_5 + 0xcc) = (uint)*(ushort *)((longlong)param_1 + 0x654);
        *(undefined4 *)(param_5 + 0xd4) = *(undefined4 *)((longlong)param_1 + 0x644);
        *(undefined4 *)(param_5 + 0xd8) = 0;
        *(ushort *)(param_1 + 0x5f) = *(ushort *)(param_1 + 0x5f) | 1;
      }
      uVar5 = *(ushort *)(param_1 + 0x5f) & 1 | 2;
      uVar6 = uVar5 * 4;
      uVar7 = (uint)(ushort)((uVar2 + uVar5 * -4) - 0x60) / (uint)uVar6;
      uVar5 = (ushort)(*(short *)((longlong)param_1 + 0x2e6) + uVar5 * -4) / uVar6;
      *(ushort *)(param_1 + 0x5c) = uVar5;
      *(short *)((longlong)param_1 + 0x2de) = (short)uVar7;
      *(uint *)((longlong)param_1 + 0x214) = uVar6 * uVar7 + 0x60 >> 2;
      if (*(char *)((longlong)param_1 + 0xeb2) != '\0') {
        uVar6 = (ushort)(uVar2 - 0x70) >> 4;
        uVar7 = (uint)uVar6;
        uVar5 = (ushort)(*(short *)((longlong)param_1 + 0x2e6) - 0x10U) >> 4;
        *(ushort *)((longlong)param_1 + 0x2e2) = uVar6;
        *(ushort *)((longlong)param_1 + 0x2e4) = uVar5;
        *(uint *)(param_1 + 0x43) = uVar6 + 6;
      }
      uVar18 = 0x101;
      if (*(uint *)((longlong)param_1 + 0x64c) != 0) {
        uVar18 = *(uint *)((longlong)param_1 + 0x64c);
      }
      *(uint *)(param_5 + 0x1c) = uVar18;
      uVar6 = (short)((int)((uVar18 & 0xffff) - uVar7) / (int)(uint)uVar5) + 1;
      if ((ushort)local_48 < uVar6) {
        *(uint *)(param_5 + 0x1c) = (local_48 & 0xffff) * (uint)uVar5 + uVar7;
      }
      else {
        local_48 = CONCAT22(local_48._2_2_,uVar6);
      }
      if (local_50 == 0) {
        uVar5 = (ushort)local_3c;
        if ((uVar5 != 0) && (uVar5 < *(ushort *)((longlong)param_1 + 0x654))) {
          *(ushort *)((longlong)param_1 + 0x654) = uVar5;
        }
      }
      else {
        local_48 = 3;
        *(undefined2 *)((longlong)param_1 + 0x654) = 4;
        *(undefined4 *)(param_5 + 0x1c) = 0x11;
        *(undefined4 *)((longlong)param_1 + 0x65a) = 0x80008;
        RttSetTraceParameters((longlong)(param_1 + 0x71),0,0);
        *(undefined1 *)((longlong)param_1 + 0x12a) = 0;
      }
      uVar6 = *(ushort *)((longlong)param_1 + 0x654);
      *(undefined4 *)(param_1 + 0xca) = *(undefined4 *)(param_5 + 0x1c);
      uVar5 = uVar6 + 0x20;
      if (local_50 != 0) {
        uVar5 = 0xc;
      }
      uVar17 = uVar5 - 1;
      if ((uVar5 & 0xf) != 0) {
        uVar17 = uVar5;
      }
      *(ushort *)((longlong)param_1 + 0x2f2) = uVar17;
      uVar15 = (uVar17 & 0xfff0) + 0x10;
      *(ushort *)((longlong)param_1 + 0x2ee) = uVar15;
      uVar5 = uVar17 + 1 + uVar6;
      if ((uVar5 & 0xf) != 0) {
        uVar5 = uVar5 + (0x10 - (uVar5 & 0xf));
      }
      uVar3 = *(ushort *)((longlong)param_1 + 0x2f4);
      if (uVar3 < uVar5) {
        uVar5 = (ushort)(uVar5 - uVar3) >> 1;
        if ((uVar5 & 0xf) != 0) {
          uVar5 = uVar5 + (0x10 - (uVar5 & 0xf));
        }
        uVar6 = uVar6 - uVar5;
        uVar17 = uVar17 - uVar5;
        uVar15 = uVar15 - uVar5;
        *(ushort *)((longlong)param_1 + 0x654) = uVar6;
        *(ushort *)((longlong)param_1 + 0x2ee) = uVar15;
        *(ushort *)((longlong)param_1 + 0x2f2) = uVar17;
        uVar5 = uVar3;
      }
      uVar7 = (uint)uVar5;
      *(ushort *)(param_1 + 0x5e) = uVar5;
      if (*(char *)((longlong)param_1 + 0x12a) != '\0') {
        uVar7 = (uint)uVar5 * (uint)*(byte *)((longlong)param_1 + 299);
      }
      *(ushort *)((longlong)param_1 + 0x2ea) = uVar2;
      if (uVar4 < *(ushort *)(param_1 + 0x5d)) {
        local_54 = *(ushort *)(param_1 + 0x5d);
      }
      else {
        *(ushort *)(param_1 + 0x5d) = uVar4;
      }
      uVar4 = *(ushort *)((longlong)param_1 + 0x1564);
      uVar5 = *(ushort *)(param_1 + 0xcb);
      *(uint *)(param_1 + 0xcf) = (uint)uVar5;
      *(undefined4 *)(param_5 + 0x18) = 0xffffff;
      *(undefined1 *)(param_5 + 0x61) = 0x80;
      *(undefined1 *)(param_5 + 0x51) = 1;
      *(undefined1 *)(param_5 + 0x54) = 0;
      *(char *)(param_5 + 0x48) = (char)param_1[0xcc];
      *(code **)(param_5 + 0x98) = LSImpiMSIIsr;
      *(undefined1 *)(param_5 + 0x91) = 1;
      *(undefined4 *)(param_5 + 0x94) = 1;
      *(undefined4 *)(param_5 + 0xa0) = 1;
      if (local_50 == 0) {
        LSImpiWmiInitialize((longlong)param_1);
        *(uint *)(param_1 + 0x3b) = local_38;
      }
      *(uint *)(param_5 + 0x8c) =
           uVar2 + 0x160 + (local_48 & 0xffff) * (uint)*(ushort *)((longlong)param_1 + 0x2e6);
      uVar18 = (int)param_1[0x278] + (int)param_1[0x275] + (int)param_1[0x272];
      iVar21 = (uint)uVar17 * (uint)local_54 +
               ((uint)*(ushort *)((longlong)param_1 + 0x1564) +
               (((uint)*(ushort *)((longlong)param_1 + 0x65c) * 0x1b +
                (uint)*(ushort *)((longlong)param_1 + 0x65a)) * 9 +
                ((uint)uVar6 * 5 + uVar7 + (uint)uVar5 * 6) * 2 + 0x66e + (uint)uVar15) * 2) * 2 +
               (uVar6 + 7) * (uint)uVar2 + (int)param_1[0x76] + (uint)uVar4 * 0x14;
      iVar16 = iVar21 + 0x100;
      if ((char)param_1[0x1695] == '\0') {
        iVar16 = iVar21;
      }
      iVar16 = uVar18 + 0x15a0 + iVar16;
      while( true ) {
        lVar9 = StorPortGetUncachedExtension(param_1,param_5,iVar16);
        *param_1 = lVar9;
        if (lVar9 != 0) break;
        if (uVar18 == 0) {
          LogSystemEvent((longlong)param_1,0xad010004,0xc004af02,
                         (byte *)"System did not give miniport the non cached memory",1);
          return 2;
        }
        LogSystemEvent((longlong)param_1,0xad010004,0xc004af02,
                       (byte *)
                       "FW Diag Buffer support disabled and non-cached extn allocation retried",1);
        iVar16 = iVar16 - uVar18;
        *(undefined1 *)(param_1 + 0x273) = 0;
        *(undefined1 *)(param_1 + 0x276) = 0;
        *(undefined1 *)(param_1 + 0x279) = 0;
        uVar18 = 0;
      }
      uVar12 = StorPortGetPhysicalAddress(param_1,0,lVar9,&local_44);
      *(int *)((longlong)param_1 + 0x1ec) = (int)(uVar12 >> 0x20);
      local_44 = (uint)uVar12 & 0x7f;
      uVar10 = (ulonglong)(0x80 - local_44);
      if ((uVar12 & 0x7f) == 0) {
        uVar10 = 0;
      }
      param_1[1] = *param_1 + uVar10;
      uVar7 = (int)uVar10 + (uint)uVar12;
      *(uint *)(param_1 + 0x3d) = uVar7;
      param_1[0x20] = (*param_1 + uVar10) - (ulonglong)uVar7;
      *(undefined1 *)((longlong)param_1 + 0xe8c) = 0;
      do {
        LsiMpiPartitionMemory((longlong)param_1,1);
        RttInitTrace(param_1 + 0x71);
        InitSysLogErrorFIFO((longlong)param_1);
        if (((char)param_1[0x77] != '\0') && ((*(uint *)((longlong)param_1 + 0x3bc) & 2) != 0)) {
          RttLogEvent(param_1,(char *)((longlong)param_1 + 0xe7f),(int *)(param_1 + 0x71),2,
                      (undefined1 *)0x0,0,1);
        }
        uVar11 = BringIOCToOperationalState((longlong)param_1,1);
        if ((char)uVar11 == '\0') {
          pcVar23 = "IOC would not come to the Operational state";
          uVar14 = 0xad010006;
          goto LAB_140002319;
        }
        uVar7 = 0;
        do {
          if ((*(char *)((longlong)param_1 + 0xe84) == '\0') &&
             (*(char *)((longlong)param_1 + 0xe85) == '\0')) {
            if (uVar7 < 120000) goto LAB_140002f0b;
            break;
          }
          PollLSImpiIsr((longlong)param_1,1);
          StorPortStallExecution(500);
          uVar7 = uVar7 + 1;
        } while (uVar7 < 120000);
        *(undefined2 *)((longlong)param_1 + 0xe84) = 0;
        LogSystemEvent((longlong)param_1,0xad01004e,0xc004af02,(byte *)"Event processing stopped",1)
        ;
        if (119999 < uVar7) {
LAB_140002f72:
          *(undefined1 *)((longlong)param_1 + 0xe8c) = 1;
          *(undefined1 *)((longlong)param_1 + 0xe45) = *(undefined1 *)(param_5 + 0x49);
          if (((char)param_1[0x77] != '\0') && ((*(uint *)((longlong)param_1 + 0x3bc) & 0x400) != 0)
             ) {
            RttLogEvent(param_1,(char *)((longlong)param_1 + 0xe7f),(int *)(param_1 + 0x71),0x400,
                        (undefined1 *)0x0,0,1);
          }
          *(undefined1 *)((longlong)param_1 + 0xeb9) = 0;
          StorPortNotification(6,param_1,WatchdogTimer,1000000);
          return 1;
        }
LAB_140002f0b:
        MapSODChecks((longlong)param_1,1);
        CompressEnclosureTable((longlong)param_1);
        if ((*(char *)((longlong)param_1 + 0xe8c) != '\0') ||
           (*(char *)((longlong)param_1 + 0xe8b) == '\0')) goto LAB_140002f72;
        *(undefined2 *)((longlong)param_1 + 0xe8b) = 0x100;
        FlushAllDPMPage0((longlong)param_1,1);
        if ((*(uint *)((longlong)param_1 + 0xeb4) & 0x2000) == 0) {
          KickStart((longlong)param_1,1);
        }
        else {
          IssueReset((longlong)param_1,0x40);
        }
      } while( true );
    }
  }
  pcVar23 = "could not get the chips BARs correctly";
  uVar14 = 0xad010001;
LAB_140003020:
  LogSystemEvent((longlong)param_1,uVar14,0xc004af02,(byte *)pcVar23,1);
  return 0;
}



===== LSImpiHWInitialize @ 140003060 =====

ulonglong LSImpiHWInitialize(longlong param_1)

{
  ulonglong uVar1;
  undefined4 local_res10 [6];
  
  uVar1 = InternalLSImpiHWInitialize(param_1,2);
  local_res10[0] = 0;
  StorPortNotification(0x1000,param_1,LSImpiPassiveInitialize,local_res10);
  return uVar1 & 0xff;
}



===== LSImpiOSReset @ 1400030b0 =====

longlong LSImpiOSReset(longlong param_1,uint param_2)

{
  longlong lVar1;
  uint local_res10 [6];
  undefined4 local_18 [2];
  uint *local_10;
  
  local_18[0] = 6;
  if (param_2 < *(ushort *)(param_1 + 0x660)) {
    local_10 = local_res10;
    local_res10[0] = param_2;
    lVar1 = StorPortSynchronizeAccess(param_1,SynchronizeReset,local_18);
    return lVar1;
  }
  return (ulonglong)(byte)(*(ushort *)(param_1 + 0x660) >> 8) << 8;
}



===== LSImpiStartIo @ 140003100 =====

ulonglong LSImpiStartIo(longlong param_1,ushort *param_2)

{
  undefined1 *puVar1;
  char cVar2;
  byte bVar3;
  ushort uVar4;
  int *piVar5;
  undefined8 *puVar6;
  int iVar7;
  ulonglong uVar8;
  longlong *plVar9;
  undefined8 uVar10;
  ushort uVar11;
  undefined4 uVar12;
  byte local_res8 [8];
  undefined4 local_38 [2];
  ushort *local_30;
  
  piVar5 = *(int **)(param_2 + 0x34);
  local_38[0] = 4;
  if ((char)param_2[1] != '(') {
    *(undefined1 *)((longlong)param_2 + 3) = 0x22;
    uVar8 = StorPortNotification(0,param_1,param_2);
    return uVar8 & 0xffffffffffffff00;
  }
  local_res8[0] = *(byte *)((longlong)piVar5 + 0x5a);
  uVar11 = (ushort)local_res8[0];
  iVar7 = piVar5[0x17];
  cVar2 = (char)piVar5[0x16];
  bVar3 = *(byte *)((longlong)piVar5 + 0x59);
  puVar1 = (undefined1 *)((longlong)piVar5 + 0x5a);
  local_30 = param_2;
  switch(*(undefined4 *)(param_2 + 10)) {
  case 0:
    if ((*(char *)(param_1 + 0xe98) == '\0') ||
       (*(undefined1 *)(param_1 + 0xe98) = 0, cVar2 != '\x03')) {
      puVar6 = (undefined8 *)**(longlong **)(param_1 + 0x5d0);
      if (*(char *)(param_1 + 0xe79) == '\0') {
        if ((*(int *)(param_1 + 0x628) == 0) && (*(int *)(param_1 + 0xec0) == 0)) {
          if (puVar6[1] == 0) {
            plVar9 = *(longlong **)(param_1 + 0x5d0) + 1;
            *(longlong **)(param_1 + 0x5d0) = plVar9;
            if (plVar9 == *(longlong **)(param_1 + 0x5e0)) {
              *(undefined8 *)(param_1 + 0x5d0) = *(undefined8 *)(param_1 + 0x5c8);
            }
            uVar11 = *(ushort *)(puVar6 + 2);
            puVar6[1] = param_2;
            *(byte *)((longlong)puVar6 + 0x12) = local_res8[0];
            uVar4 = *(ushort *)(piVar5 + 0x58);
            *(ushort *)((longlong)puVar6 + 0x14) = uVar4;
            *(char *)((longlong)puVar6 + 0x16) = (char)iVar7;
            *(char *)((longlong)puVar6 + 0x17) = (char)param_2[0x10];
            if (cVar2 == '\x12') {
              if ((((bVar3 & 1) != 0) ||
                  (*(undefined4 *)(puVar6 + 3) = 4, *(char *)(param_1 + 0x3b8) == '\0')) ||
                 ((*(uint *)(param_1 + 0x3bc) & 0x2000) == 0)) goto LAB_140003421;
              uVar12 = 0x2000;
            }
            else {
              if (((cVar2 != -0x60) || (*(char *)(param_1 + 0x3b8) == '\0')) ||
                 ((*(uint *)(param_1 + 0x3bc) & 0x2002) == 0)) goto LAB_140003421;
              uVar12 = 0x2002;
            }
            RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),uVar12,puVar1,3,4
                       );
LAB_140003421:
            memmove((void *)*puVar6,piVar5 + 0x58,(ulonglong)*(ushort *)(param_1 + 0x2ea));
            **(int **)(param_1 + 0xe8) = (uint)uVar11 * 0x10000 + *piVar5;
            LOCK();
            UNLOCK();
            piVar5 = *(int **)(param_1 + 0xf0);
            *piVar5 = (uint)uVar4 << 0x10;
            LOCK();
            UNLOCK();
            *(undefined1 *)(param_1 + 0x62c) = 0;
            return CONCAT71((int7)((ulonglong)piVar5 >> 8),1);
          }
          *(undefined1 *)((longlong)param_2 + 3) = 5;
          StorPortBusy(param_1,10);
          if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x215) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x215,puVar1,3,4)
            ;
          }
          if (*(short *)(param_1 + 0x620) != 0) {
            LogSystemEvent(param_1,0xad010012,0x8004af01,
                           (byte *)"IO returned for lack of request MFA resources",4);
          }
        }
        else {
          *(undefined1 *)((longlong)param_2 + 3) = 5;
          if ((*(char *)(param_1 + 0x62c) == '\0') &&
             ((*(undefined1 *)(param_1 + 0x62c) = 1, *(char *)(param_1 + 0x3b8) != '\0' &&
              ((*(uint *)(param_1 + 0x3bc) & 0x214) != 0)))) {
            RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x214,puVar1,3,4)
            ;
          }
        }
      }
      else {
        *(undefined1 *)((longlong)param_2 + 3) = 0x11;
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x213) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x213,puVar1,3,4);
        }
      }
    }
    else {
      memmove(*(void **)(param_2 + 0x20),*(void **)(param_1 + 0xea0),
              (ulonglong)*(uint *)(param_2 + 0x1e));
      *(undefined1 *)((longlong)param_2 + 3) = 1;
      *(undefined1 *)(*(longlong *)(piVar5 + 0x10) + 8) = 0;
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x409) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x409,puVar1,3,4);
      }
    }
    break;
  case 2:
    uVar10 = StorPortSynchronizeAccess(param_1,SynchronizeStartIoctl,local_38);
    return CONCAT71((int7)((ulonglong)uVar10 >> 8),1);
  case 7:
    if (*(int *)(param_1 + 0x630) != 0) {
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x80006) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x80006,
                    (undefined1 *)param_2,*(uint *)(param_2 + 8),4);
      }
      *(ushort **)(param_1 + 0x5e8) = param_2;
      CheckForIRShutdown(param_1,'\x01',4);
      *(undefined2 *)(param_1 + 0xb320) = 3;
      SendAndProcessSSUCommands(param_1,4);
      *(undefined2 *)(param_1 + 0xb320) = *(undefined2 *)(param_1 + 0xb324);
      return CONCAT71((uint7)(byte)((ushort)*(undefined2 *)(param_1 + 0xb324) >> 8),1);
    }
    goto LAB_1400037ef;
  case 0x12:
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x406) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x406,(undefined1 *)0x0
                  ,0,4);
      uVar11 = (ushort)local_res8[0];
    }
    if (uVar11 < *(ushort *)(param_1 + 0x660)) {
      local_30 = (ushort *)local_res8;
      *(ushort **)(param_1 + 0x5f0) = param_2;
      uVar10 = StorPortSynchronizeAccess(param_1,SynchronizeReset,local_38);
      return uVar10;
    }
    *(undefined1 *)((longlong)param_2 + 3) = 7;
    uVar8 = StorPortNotification(0,param_1,param_2);
    return uVar8 & 0xffffffffffffff00;
  case 0x13:
  case 0x20:
    uVar10 = StorPortSynchronizeAccess(param_1,SynchronizeLunTargetReset,local_38);
    return uVar10;
  case 0x17:
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x403) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x403,
                  (undefined1 *)param_2,0x80,4);
    }
    uVar10 = LSImpiWmiSrb(param_1,param_2,4);
    return uVar10;
  case 0x24:
    if (*(int *)(*(longlong *)(piVar5 + 0x12) + 0xc) == 4) {
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x80001) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x80001,
                    (undefined1 *)param_2,*(uint *)(param_2 + 8),4);
      }
      *(ushort **)(param_1 + 0x5e8) = param_2;
      uVar10 = CheckForIRShutdown(param_1,'\0',4);
      if ((char)uVar10 == '\0') {
        uVar12 = 0xd;
        if (*(short *)(param_1 + 0xb320) != 0) {
          uVar12 = 8;
        }
        *(undefined4 *)(param_1 + 0xec0) = uVar12;
        return 1;
      }
      goto LAB_140003801;
    }
  default:
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x217) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x217,
                  (undefined1 *)param_2,*(uint *)(param_2 + 8),4);
    }
LAB_1400037ef:
    *(undefined1 *)((longlong)param_2 + 3) = 0x22;
  }
  uVar10 = StorPortNotification(0,param_1,param_2);
LAB_140003801:
  return CONCAT71((int7)((ulonglong)uVar10 >> 8),1);
}



===== SynchronizeLunTargetReset @ 140003860 =====

ulonglong SynchronizeLunTargetReset(longlong param_1,int *param_2)

{
  char *pcVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  longlong lVar6;
  ushort *puVar7;
  undefined4 *puVar8;
  ulonglong uVar9;
  ulonglong in_RAX;
  ulonglong uVar10;
  undefined8 uVar11;
  char cVar12;
  ushort uVar13;
  undefined4 uVar14;
  bool bVar15;
  
  lVar5 = *(longlong *)(param_2 + 2);
  pcVar1 = (char *)(param_1 + 0xe7f);
  iVar3 = *param_2;
  lVar6 = *(longlong *)(lVar5 + 0x68);
  *pcVar1 = '\x01';
  if (lVar6 == 0) {
    if ((*(char *)(param_1 + 0x3b8) != '\0') &&
       (in_RAX = (ulonglong)*(uint *)(param_1 + 0x3bc), (*(uint *)(param_1 + 0x3bc) & 0x23c) != 0))
    {
      in_RAX = RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x388),0x23c,(undefined1 *)0x0,0,iVar3);
    }
    uVar10 = in_RAX & 0xffffffffffffff00;
    goto LAB_140003d23;
  }
  uVar10 = (ulonglong)*(uint *)(lVar5 + 0x14);
  if (*(char *)(param_1 + 0x3b8) != '\0') {
    uVar4 = *(uint *)(param_1 + 0x3bc);
    uVar10 = (ulonglong)uVar4;
    if (*(uint *)(lVar5 + 0x14) == 0x20) {
      if ((uVar4 & 0x404) != 0) {
        uVar14 = 0x404;
LAB_1400038cc:
        uVar10 = RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x388),uVar14,
                             (undefined1 *)(lVar6 + 0x5a),3,iVar3);
      }
    }
    else if ((uVar4 & 0x405) != 0) {
      uVar14 = 0x405;
      goto LAB_1400038cc;
    }
  }
  if (*(int *)(param_1 + 0xec0) == 0) {
    if ((*(int *)(param_1 + 0x628) == 0) && (*(longlong *)(param_1 + 0x5e8) == 0)) {
      uVar13 = (ushort)*(byte *)(lVar6 + 0x5a) * 0x80 + (ushort)*(byte *)(lVar6 + 0x5b);
      if (((uint)uVar13 < *(uint *)(param_1 + 0x678)) &&
         (uVar13 = *(ushort *)(*(longlong *)(param_1 + 0x378) + 0x1a + (ulonglong)uVar13 * 0x28),
         uVar13 != 0)) {
        if (*(int *)(param_1 + 0x630) == 0) {
          StorPortPause(param_1,300);
        }
        *(longlong *)(param_1 + 0x5e8) = lVar5;
        ResetActive(param_1,10,iVar3);
        uVar4 = *(uint *)(lVar5 + 0x14);
        uVar10 = (ulonglong)uVar4;
        if (uVar4 == 0x13) {
          if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x20006) != 0))
          {
            RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x388),0x20006,(byte *)(lVar6 + 0x5a),3,
                        iVar3);
          }
          puVar7 = *(ushort **)(param_1 + 800);
          ZeroMemory((undefined1 *)puVar7,0x34);
          *puVar7 = uVar13;
          *(undefined1 *)((longlong)puVar7 + 3) = 1;
          *(undefined1 *)((longlong)puVar7 + 5) = 3;
          **(int **)(param_1 + 0xe8) = (uint)*(ushort *)(param_1 + 0x66e) * 0x10000 + 6;
          LOCK();
          UNLOCK();
          puVar8 = *(undefined4 **)(param_1 + 0xf0);
          *puVar8 = 0;
          LOCK();
          UNLOCK();
          uVar10 = CONCAT71((int7)((ulonglong)puVar8 >> 8),1);
          goto LAB_140003d23;
        }
        if (uVar4 == 0x20) {
          uVar11 = SendLunResetTur(param_1,uVar13,iVar3);
          uVar10 = CONCAT71((int7)((ulonglong)uVar11 >> 8),1);
          goto LAB_140003d23;
        }
      }
      else {
        *(undefined1 *)(lVar5 + 3) = 10;
        uVar10 = StorPortNotification(0,param_1,lVar5);
        if ((*(char *)(param_1 + 0x3b8) != '\0') &&
           (uVar10 = (ulonglong)*(uint *)(param_1 + 0x3bc),
           (*(uint *)(param_1 + 0x3bc) & 0x20012) != 0)) {
          uVar11 = RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x388),0x20012,(undefined1 *)0x0,0,
                               iVar3);
          uVar10 = CONCAT71((int7)((ulonglong)uVar11 >> 8),1);
          goto LAB_140003d23;
        }
      }
    }
    else if (lVar5 == *(longlong *)(param_1 + 0x5e8)) {
      if ((*(char *)(param_1 + 0x3b8) != '\0') &&
         (uVar10 = (ulonglong)*(uint *)(param_1 + 0x3bc),
         (*(uint *)(param_1 + 0x3bc) & 0x20003) != 0)) {
        uVar10 = RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x388),0x20003,(undefined1 *)0x0,0,
                             iVar3);
      }
    }
    else {
      uVar13 = 0;
      do {
        uVar10 = (ulonglong)uVar13;
        if (*(longlong *)(param_1 + 0x1068 + uVar10 * 8) == lVar5) {
          if ((*(char *)(param_1 + 0x3b8) == '\0') ||
             (uVar10 = (ulonglong)*(uint *)(param_1 + 0x3bc),
             (*(uint *)(param_1 + 0x3bc) & 0x20004) == 0)) goto LAB_140003b1c;
          uVar11 = RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x388),0x20004,(undefined1 *)0x0,0,
                               iVar3);
          uVar10 = CONCAT71((int7)((ulonglong)uVar11 >> 8),1);
          goto LAB_140003d23;
        }
        uVar13 = uVar13 + 1;
      } while (uVar13 < 100);
      bVar2 = *(byte *)(param_1 + 0xf5f);
      if (*(longlong *)(param_1 + 0x1068 + (ulonglong)bVar2 * 8) != 0) {
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x216) != 0)) {
          RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x388),0x216,(undefined1 *)0x0,0,iVar3);
        }
        LogSystemEvent(param_1,0xad01003a,0x8004af01,(byte *)"LUN/Target reset queue is full",iVar3)
        ;
        goto LAB_140003bf1;
      }
      *(longlong *)(param_1 + 0x1068 + (ulonglong)bVar2 * 8) = lVar5;
      uVar10 = 0;
      cVar12 = '\0';
      if (bVar2 != 99) {
        cVar12 = bVar2 + 1;
      }
      *(char *)(param_1 + 0xf5f) = cVar12;
      if ((*(char *)(param_1 + 0x3b8) != '\0') &&
         (uVar10 = (ulonglong)*(uint *)(param_1 + 0x3bc),
         (*(uint *)(param_1 + 0x3bc) >> 0x11 & 1) != 0)) {
        uVar14 = 0x20000;
        goto LAB_140003c7a;
      }
    }
LAB_140003b1c:
    uVar10 = CONCAT71((int7)(uVar10 >> 8),1);
  }
  else {
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x20002) != 0)) {
      RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x388),0x20002,(undefined1 *)0x0,0,iVar3);
    }
LAB_140003bf1:
    bVar15 = lVar5 == *(longlong *)(param_1 + 0x5e8);
    uVar9 = 0;
    do {
      uVar10 = uVar9;
      if (*(longlong *)(param_1 + 0x1068 + uVar10 * 8) == lVar5) {
        bVar15 = true;
        break;
      }
      uVar13 = (short)uVar10 + 1;
      uVar9 = (ulonglong)uVar13;
    } while (uVar13 < 100);
    if (bVar15) {
      if ((*(char *)(param_1 + 0x3b8) == '\0') ||
         (uVar10 = (ulonglong)*(uint *)(param_1 + 0x3bc), (*(uint *)(param_1 + 0x3bc) & 0x23b) == 0)
         ) goto LAB_140003b1c;
      uVar14 = 0x23b;
    }
    else {
      *(undefined1 *)(lVar5 + 3) = 4;
      uVar10 = StorPortNotification(0,param_1,lVar5);
      if ((*(char *)(param_1 + 0x3b8) == '\0') ||
         (uVar10 = (ulonglong)*(uint *)(param_1 + 0x3bc),
         (*(uint *)(param_1 + 0x3bc) & 0x20012) == 0)) goto LAB_140003b1c;
      uVar14 = 0x20012;
    }
LAB_140003c7a:
    uVar11 = RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x388),uVar14,(undefined1 *)0x0,0,iVar3);
    uVar10 = CONCAT71((int7)((ulonglong)uVar11 >> 8),1);
  }
LAB_140003d23:
  *pcVar1 = '\0';
  return uVar10;
}



===== SynchronizeStartIoctl @ 140003d40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong SynchronizeStartIoctl(longlong param_1,int *param_2)

{
  char *pcVar1;
  byte bVar2;
  int iVar3;
  void *pvVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined4 uVar7;
  char cVar8;
  undefined1 auStackY_78 [32];
  void *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_78;
  pvVar4 = *(void **)(param_2 + 2);
  iVar3 = *param_2;
  local_28 = 0;
  pcVar1 = (char *)(param_1 + 0xe7f);
  local_2c = 0;
  local_30 = *(undefined4 *)(*(longlong *)((longlong)pvVar4 + 0x40) + 0x10);
  *pcVar1 = '\x01';
  local_38 = pvVar4;
  if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) >> 0x16 & 1) != 0)) {
    RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x388),0x400000,(undefined1 *)&local_38,0x11,iVar3)
    ;
  }
  if ((*(char *)(param_1 + 0xe6a) != '\0') || (*(char *)(param_1 + 0xe7c) != '\0')) {
    local_28 = 5;
    *(undefined1 *)((longlong)pvVar4 + 3) = 5;
    uVar6 = StorPortNotification(0,param_1,pvVar4);
    if ((*(char *)(param_1 + 0x3b8) != '\0') &&
       (uVar6 = (ulonglong)*(uint *)(param_1 + 0x3bc), (*(uint *)(param_1 + 0x3bc) & 0x40001a) != 0)
       ) {
      uVar6 = RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x388),0x40001a,(undefined1 *)&local_38,
                          0x11,iVar3);
    }
    uVar6 = uVar6 & 0xffffffffffffff00;
LAB_140003f3d:
    *pcVar1 = '\0';
    return uVar6;
  }
  if ((((*(char *)(param_1 + 0xec8) == '\0') && (*(int *)(param_1 + 0x628) == 0)) &&
      (*(int *)(param_1 + 0xec0) == 0)) && (*(char *)(param_1 + 0x15a0) == '\0')) {
    uVar5 = LsiHandleAppRequest(param_1,pvVar4,iVar3);
    uVar6 = CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
    goto LAB_140003f3d;
  }
  bVar2 = *(byte *)(param_1 + 0xf5d);
  if ((*(int *)(param_1 + 0xec0) == 0) &&
     (*(longlong *)(param_1 + 0xf68 + (ulonglong)bVar2 * 8) == 0)) {
    *(void **)(param_1 + 0xf68 + (ulonglong)bVar2 * 8) = pvVar4;
    uVar6 = 0;
    cVar8 = '\0';
    if (bVar2 != 0x1f) {
      cVar8 = bVar2 + 1;
    }
    *(char *)(param_1 + 0xf5d) = cVar8;
    if ((*(char *)(param_1 + 0x3b8) == '\0') ||
       (uVar6 = (ulonglong)*(uint *)(param_1 + 0x3bc), (*(uint *)(param_1 + 0x3bc) & 0x400007) == 0)
       ) goto LAB_140003ed9;
    uVar7 = 0x400007;
  }
  else {
    local_28 = 5;
    *(undefined1 *)((longlong)pvVar4 + 3) = 5;
    uVar6 = StorPortNotification(0,param_1,pvVar4);
    if ((*(char *)(param_1 + 0x3b8) == '\0') ||
       (uVar6 = (ulonglong)*(uint *)(param_1 + 0x3bc), (*(uint *)(param_1 + 0x3bc) & 0x40001b) == 0)
       ) goto LAB_140003ed9;
    uVar7 = 0x40001b;
  }
  uVar6 = RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x388),uVar7,(undefined1 *)&local_38,0x11,
                      iVar3);
LAB_140003ed9:
  *pcVar1 = '\0';
  return uVar6 & 0xffffffffffffff00;
}



===== CheckSmartInfo @ 140003f70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CheckSmartInfo(longlong param_1,longlong param_2,char *param_3,undefined2 param_4,int param_5)

{
  undefined4 *puVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  longlong lVar5;
  uint uVar6;
  ushort uVar7;
  char cVar8;
  undefined1 auStackY_a8 [32];
  uint local_78;
  uint local_74;
  undefined2 local_70;
  undefined1 local_6e;
  undefined1 local_6c;
  char local_6b;
  undefined2 local_6a;
  undefined4 local_64;
  undefined4 local_60;
  undefined1 local_5b;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_a8;
  lVar5 = *(longlong *)(param_2 + 0x68);
  bVar2 = *(byte *)(lVar5 + 0x5a);
  bVar3 = *(byte *)(lVar5 + 0x5b);
  uVar4 = *(undefined1 *)(lVar5 + 0x5c);
  if ((byte)(*param_3 + 0x8eU) < 2) {
    if (param_3[2] != ']') {
      return;
    }
    cVar8 = param_3[3];
  }
  else {
    if (param_3[0xc] != ']') {
      return;
    }
    cVar8 = param_3[0xd];
  }
  uVar7 = (ushort)bVar2 * 0x80 + (ushort)bVar3;
  if ((((uint)uVar7 < *(uint *)(param_1 + 0x678)) &&
      (puVar1 = (undefined4 *)(*(longlong *)(param_1 + 0x378) + (ulonglong)uVar7 * 0x28),
      *(short *)(*(longlong *)(param_1 + 0x378) + 0x1a + (ulonglong)uVar7 * 0x28) != 0)) &&
     ((puVar1[5] & 0x680) != 0)) {
    if ((*(uint *)(param_1 + 0xeb4) & 0x1000) != 0) {
      GetIrMapRange(param_1,(int *)&local_78,&local_74);
      uVar6 = (uint)bVar2 * 0x80 + (uint)bVar3;
      if ((local_78 <= uVar6) && (uVar6 <= local_74)) {
        return;
      }
    }
    if (*(char *)(param_1 + 0xe6c) != '\0') {
      puVar1[5] = puVar1[5] | 0x80000000;
    }
    local_6e = 5;
    local_70 = 0xffff;
    local_6c = 0x5d;
    local_64 = *puVar1;
    local_60 = puVar1[1];
    local_6b = cVar8;
    local_6a = param_4;
    local_5b = uVar4;
    SendMpiEventToApplication(param_1,0xf,&local_70,0x1c);
    if (*(char *)(param_1 + 0xe6c) != '\0') {
      SendSEPMessage(param_1,0x40,param_4,param_5);
    }
  }
  else {
    LogSystemEvent(param_1,0xad01003f,0xc004af02,(byte *)"Device not mapped (CheckSmartInfo)",
                   param_5);
  }
  return;
}



===== FindMappingTableEntry @ 140004130 =====

longlong FindMappingTableEntry(longlong param_1,short param_2,short param_3,uint param_4)

{
  longlong lVar1;
  ushort uVar2;
  
  uVar2 = param_2 * 0x80 + param_3;
  if (((*(uint *)(param_1 + 0x678) <= (uint)uVar2) ||
      (lVar1 = *(longlong *)(param_1 + 0x378) + (ulonglong)uVar2 * 0x28,
      *(short *)(*(longlong *)(param_1 + 0x378) + 0x1a + (ulonglong)uVar2 * 0x28) == 0)) ||
     ((*(uint *)(lVar1 + 0x14) & param_4) == 0)) {
    lVar1 = 0;
  }
  return lVar1;
}



===== HandleFwDiagReply @ 140004180 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HandleFwDiagReply(longlong param_1,longlong param_2,int param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  ushort uVar3;
  undefined4 uVar4;
  undefined1 auStackY_88 [32];
  longlong local_48;
  int local_40;
  uint local_3c;
  undefined1 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_88;
  if (*(char *)(param_2 + 3) == '\x1d') {
    *(undefined1 *)(param_1 + 0xe83) = 0;
    uVar3 = *(ushort *)(param_2 + 0xe) & 0x7fff;
    lVar1 = param_1 + (ulonglong)*(byte *)(param_2 + 1) * 0x18;
    if (uVar3 == 0xa0) {
      *(undefined1 *)(lVar1 + 0x1397) = 0;
    }
    *(undefined1 *)(lVar1 + 0x1399) = 1;
    *(bool *)(lVar1 + 0x139a) = uVar3 != 0xa0;
    if ((uVar3 != 0) && (uVar3 != 0xa0)) {
      *(undefined2 *)(lVar1 + 0x1399) = 0;
      LogSystemEvent(param_1,0xad01002a,0xc004af02,
                     (byte *)"FW diagnostic buffer post failed (HandleFwDiagReply)",param_3);
    }
    if ((*(char *)(lVar1 + 0x1397) != '\0') || (uVar3 == 0xa0)) goto LAB_1400043a1;
    local_48 = *(longlong *)(param_1 + 0x13f8);
    if (local_48 == 0) {
      return;
    }
    lVar1 = *(longlong *)(local_48 + 0x40);
    local_40 = *(int *)(lVar1 + 0x10);
    if (local_40 == -0x7f9b969f) {
      local_3c = -(uint)(uVar3 != 0) & 0x10;
      *(uint *)(lVar1 + 0x14) = -(uint)(uVar3 != 0) & 0x10;
      local_38 = 1;
      *(undefined1 *)(local_48 + 3) = 1;
      StorPortNotification(0,param_1);
      *(undefined8 *)(param_1 + 0x13f8) = 0;
      local_40 = *(int *)(lVar1 + 0x10);
    }
    if ((*(char *)(param_1 + 0x3b8) == '\0') || ((*(uint *)(param_1 + 0x3bc) & 0x400021) == 0))
    goto LAB_1400043a1;
    uVar4 = 0x400021;
  }
  else {
    if (*(char *)(param_2 + 3) != '\x1e') goto LAB_1400043a1;
    uVar2 = (ulonglong)*(byte *)(param_2 + 1);
    local_48 = *(longlong *)(param_1 + 0x13f8);
    if (local_48 == 0) {
      return;
    }
    lVar1 = *(longlong *)(local_48 + 0x40);
    if (((*(ushort *)(param_2 + 0xe) & 0x7fff) == 0) &&
       (*(char *)(param_1 + 0x139a + uVar2 * 0x18) != '\0')) {
      local_3c = 0;
      *(undefined4 *)(lVar1 + 0x14) = 0;
      *(undefined1 *)(param_1 + 0x139a + uVar2 * 0x18) = 0;
    }
    else {
      local_3c = 0x12;
      *(undefined4 *)(lVar1 + 0x14) = 0x12;
    }
    if (*(int *)(lVar1 + 0x1c) == 2) {
      *(undefined4 *)(param_1 + 0x139c + uVar2 * 0x18) = 0;
    }
    local_38 = 1;
    *(undefined1 *)(local_48 + 3) = 1;
    StorPortNotification(0,param_1);
    *(undefined8 *)(param_1 + 0x13f8) = 0;
    local_40 = *(int *)(lVar1 + 0x10);
    if ((*(char *)(param_1 + 0x3b8) == '\0') || ((*(uint *)(param_1 + 0x3bc) & 0x400022) == 0))
    goto LAB_1400043a1;
    uVar4 = 0x400022;
  }
  RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),uVar4,
              (undefined1 *)&local_48,0x11,param_3);
LAB_1400043a1:
  *(undefined1 *)(param_1 + 0xec8) = 0;
  CheckIoctlQueue(param_1,param_3);
  return;
}



===== LSImpiIsr @ 1400043d0 =====

void LSImpiIsr(longlong param_1)

{
  LSImpiMSIIsr(param_1,0);
  return;
}



===== LSImpiMSIIsr @ 1400043e0 =====

undefined8 LSImpiMSIIsr(longlong param_1,byte param_2)

{
  ushort uVar1;
  int iVar2;
  char cVar3;
  ushort uVar4;
  ulonglong in_RAX;
  undefined8 uVar5;
  longlong lVar6;
  uint *puVar7;
  short sVar8;
  ushort *puVar9;
  ushort uVar10;
  byte bVar11;
  uint uVar12;
  byte *pbVar13;
  longlong lVar14;
  char local_res8 [8];
  ushort local_res18 [4];
  short local_res20;
  uint local_54;
  longlong local_50;
  longlong local_48;
  ulonglong local_40;
  
  iVar2 = *(int *)(param_1 + 0x5c0);
  local_48 = 0;
  uVar1 = *(ushort *)(param_1 + 0x2f0);
  lVar14 = 0;
  if ((*(char *)(param_1 + 0xe7d) == '\0') &&
     ((*(int *)(param_1 + 0xec0) == 0 || (*(char *)(param_1 + 0xe7f) != '\0')))) {
    if (*(char *)(param_1 + 0x12a) == '\0') {
      param_2 = 0;
    }
    local_40 = (ulonglong)param_2;
    in_RAX = (ulonglong)*(ushort *)(param_1 + 0x21e + local_40 * 2);
    local_res20 = 0;
    lVar6 = *(longlong *)(param_1 + 0x308) + uVar1 * local_40 * 8;
    pbVar13 = (byte *)(lVar6 + in_RAX * 8);
    local_50 = lVar6;
    if (*(int *)(lVar6 + in_RAX * 8) != -1) {
      do {
        sVar8 = local_res20;
        uVar12 = (uint)in_RAX;
        if (*(int *)(pbVar13 + 4) == -1) break;
        local_res18[0] = *(ushort *)(pbVar13 + 2);
        if (local_res18[0] != 0) {
          lVar14 = (ulonglong)local_res18[0] * 0x20 + *(longlong *)(param_1 + 0x350);
          if (*(longlong *)(lVar14 + 8) != 0xea) {
            local_48 = *(longlong *)(lVar14 + 8);
          }
        }
        bVar11 = *pbVar13 & 0xf;
        if (((bVar11 == 0) || (bVar11 == 6)) && (*(int *)(lVar14 + 0x18) == 0)) {
          if (local_48 == 0) {
            if (local_res18[0] < *(ushort *)(param_1 + 0x66a)) {
              if ((*(char *)(param_1 + 0x3b8) != '\0') &&
                 ((*(uint *)(param_1 + 0x3bc) & 0x219) != 0)) {
                RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x219,
                            (undefined1 *)local_res18,2,iVar2);
              }
              LogSystemEvent(param_1,0xad010024,0xc004af02,
                             (byte *)"NULL Srb pointer (ISR) returned by IOC",iVar2);
              goto LAB_140004d0d;
            }
          }
          else {
            **(longlong **)(param_1 + 0x5d8) = lVar14;
            *(longlong *)(param_1 + 0x5d8) = *(longlong *)(param_1 + 0x5d8) + 8;
            if (*(longlong *)(param_1 + 0x5d8) == *(longlong *)(param_1 + 0x5e0)) {
              *(undefined8 *)(param_1 + 0x5d8) = *(undefined8 *)(param_1 + 0x5c8);
            }
            *(undefined8 *)(lVar14 + 8) = 0;
            *(undefined1 *)(*(longlong *)(*(longlong *)(local_48 + 0x68) + 0x40) + 8) = 0;
            *(undefined1 *)(local_48 + 3) = 1;
            StorPortNotification(0,param_1);
LAB_140004d0d:
            lVar6 = local_50;
          }
          local_res20 = sVar8 + 1;
          pbVar13[0] = 0xff;
          pbVar13[1] = 0xff;
          pbVar13[2] = 0xff;
          pbVar13[3] = 0xff;
          pbVar13[4] = 0xff;
          pbVar13[5] = 0xff;
          pbVar13[6] = 0xff;
          pbVar13[7] = 0xff;
          uVar10 = (short)in_RAX + 1;
          in_RAX = (ulonglong)uVar10;
          if (uVar10 == uVar1) {
            in_RAX = 0;
          }
          goto LAB_140004d30;
        }
        if (local_res18[0] != 0) {
          uVar5 = CheckHbaFwReply(param_1,(longlong)pbVar13,iVar2);
          if ((char)uVar5 != '\0') {
            if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x113) != 0))
            {
              RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x113,
                          (undefined1 *)local_res18,2,iVar2);
            }
            goto LAB_140004b15;
          }
          uVar5 = CheckMpiIoctlReply(param_1,pbVar13,iVar2);
          if ((char)uVar5 != '\0') {
            if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x107) != 0))
            {
              RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x107,
                          (undefined1 *)local_res18,2,iVar2);
            }
            goto LAB_140004b15;
          }
          uVar5 = CheckInqFlagReplies(param_1,local_res8,pbVar13,iVar2);
          if ((char)uVar5 == '\0') {
            lVar6 = CheckSsuReplies(param_1,(longlong)pbVar13);
            if ((char)lVar6 == '\0') {
              lVar6 = CheckSsuTmrReplies(param_1,(longlong)pbVar13);
              if ((char)lVar6 == '\0') {
                uVar5 = CheckTurReplies(param_1,pbVar13,iVar2);
                if ((char)uVar5 == '\0') {
                  uVar5 = CheckPfaSataReplies(param_1,(undefined4 *)pbVar13,iVar2);
                  if ((char)uVar5 == '\0') goto LAB_1400047c8;
                  goto LAB_140004b70;
                }
                if ((*(char *)(param_1 + 0x3b8) != '\0') &&
                   ((*(uint *)(param_1 + 0x3bc) & 0x10c) != 0)) {
                  RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x10c,
                              (undefined1 *)local_res18,2,iVar2);
                }
              }
              else if ((*(char *)(param_1 + 0x3b8) != '\0') &&
                      ((*(uint *)(param_1 + 0x3bc) & 0x10b) != 0)) {
                RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x10b,
                            (undefined1 *)local_res18,2,iVar2);
              }
            }
            else if ((*(char *)(param_1 + 0x3b8) != '\0') &&
                    ((*(uint *)(param_1 + 0x3bc) & 0x10a) != 0)) {
              RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x10a,
                          (undefined1 *)local_res18,2,iVar2);
            }
            goto LAB_140004b15;
          }
          if (local_res8[0] != '\0') {
            if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x108) != 0))
            {
              RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x108,
                          (undefined1 *)local_res18,2,iVar2);
            }
            goto LAB_140004b15;
          }
          if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x109) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x109,
                        (undefined1 *)local_res18,2,iVar2);
          }
          goto LAB_140004b70;
        }
LAB_1400047c8:
        if (bVar11 != 1) {
          LogSystemEvent(param_1,0xad010022,0x8004af01,(byte *)"Unexpected reply from FW",iVar2);
          if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x239) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x239,
                        (undefined1 *)0x0,0,iVar2);
          }
          goto LAB_140004c1d;
        }
        puVar9 = (ushort *)((ulonglong)*(uint *)(pbVar13 + 4) + *(longlong *)(param_1 + 0x100));
        local_54 = *(uint *)(puVar9 + 8);
        if (((((local_54 != 0) && ((short)puVar9[7] < 0)) && (local_54 != 0x30030501)) &&
            ((local_54 != 0x30030101 && (local_54 != 0x31180000)))) &&
           ((local_54 != 0x30070001 && ((local_54 & 0xffff0000) != 0x31170000)))) {
          AfdMpiLogInfoTrigger(param_1,local_54,puVar9[7],iVar2);
          if ((*(short *)(param_1 + 0x620) != 0) ||
             (uVar10 = *(ushort *)(param_1 + 0x622), *(ushort *)(param_1 + 0x622) = uVar10 + 1,
             uVar10 < 0x14)) {
            LogSystemEvent(param_1,local_54,0x4004af00,(byte *)"Available LogInfo",iVar2);
          }
          if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x238) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x238,
                        (undefined1 *)&local_54,4,iVar2);
          }
        }
        switch(*(undefined1 *)((longlong)puVar9 + 3)) {
        case 1:
          if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x806) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x806,
                        (undefined1 *)local_res18,2,iVar2);
          }
          if (((*(char *)((longlong)puVar9 + 5) != '\x02') || (local_res18[0] == 0)) ||
             (-1 < (char)*(undefined4 *)
                          ((ulonglong)local_res18[0] * 0x20 + 0x18 + *(longlong *)(param_1 + 0x350))
             )) goto LAB_140004967;
          lVar6 = *(longlong *)(local_48 + 0x68);
          cVar3 = HandleUnitAttenReset
                            (param_1,local_res18[0],(undefined8 *)puVar9,*(byte *)(lVar6 + 0x5a),
                             *(byte *)(lVar6 + 0x5b),*(char *)(lVar6 + 0x5c),'\0',iVar2);
          if (cVar3 == '\0') break;
          goto LAB_140004b7a;
        default:
          uVar5 = LsiCompleteIO(param_1,(short *)puVar9,local_res18[0],iVar2);
          cVar3 = (char)uVar5;
LAB_140004b0d:
          if (cVar3 == '\0') goto LAB_140004b7a;
          break;
        case 4:
          if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x808) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x808,
                        (undefined1 *)local_res18,2,iVar2);
          }
          if ((*(uint *)((ulonglong)local_res18[0] * 0x20 + 0x18 + *(longlong *)(param_1 + 0x350)) &
              8) != 0) {
            uVar5 = HbaApiWmiCompletion(param_1,(longlong)puVar9,local_res18[0],iVar2);
            cVar3 = (char)uVar5;
            goto LAB_140004b0d;
          }
          goto LAB_140004967;
        case 7:
          HandleEventNotification(param_1,puVar9,iVar2);
          break;
        case 0x1b:
          if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x805) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x805,
                        (undefined1 *)local_res18,2,iVar2);
          }
LAB_140004967:
          NonSCB_Func_handler(param_1,(short *)puVar9,local_res18[0],iVar2);
          break;
        case 0x1d:
        case 0x1e:
          if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x807) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x807,
                        (undefined1 *)local_res18,2,iVar2);
          }
          HandleFwDiagReply(param_1,(longlong)puVar9,iVar2);
        }
        sVar8 = local_res20;
LAB_140004b15:
        if ((local_res18[0] != 0) && (local_res18[0] <= *(ushort *)(param_1 + 0x654))) {
          lVar14 = (ulonglong)local_res18[0] * 0x20 + *(longlong *)(param_1 + 0x350);
          **(longlong **)(param_1 + 0x5d8) = lVar14;
          *(longlong *)(param_1 + 0x5d8) = *(longlong *)(param_1 + 0x5d8) + 8;
          if (*(longlong *)(param_1 + 0x5d8) == *(longlong *)(param_1 + 0x5e0)) {
            *(undefined8 *)(param_1 + 0x5d8) = *(undefined8 *)(param_1 + 0x5c8);
          }
          *(undefined4 *)(lVar14 + 0x18) = 0;
          *(undefined8 *)(lVar14 + 8) = 0;
        }
LAB_140004b70:
        if (bVar11 == 1) {
LAB_140004b7a:
          uVar10 = *(ushort *)(param_1 + 0x21c);
          *(undefined4 *)(*(longlong *)(param_1 + 0x300) + (ulonglong)uVar10 * 4) =
               *(undefined4 *)(pbVar13 + 4);
          uVar10 = uVar10 + 1;
          uVar4 = 0;
          if (uVar10 != *(ushort *)(param_1 + 0x2ee)) {
            uVar4 = uVar10;
          }
          **(uint **)(param_1 + 0x58) = (uint)uVar4;
          LOCK();
          UNLOCK();
          *(ushort *)(param_1 + 0x21c) = uVar4;
          sVar8 = local_res20;
        }
LAB_140004c1d:
        uVar10 = (short)in_RAX + 1;
        pbVar13[0] = 0xff;
        pbVar13[1] = 0xff;
        pbVar13[2] = 0xff;
        pbVar13[3] = 0xff;
        pbVar13[4] = 0xff;
        pbVar13[5] = 0xff;
        pbVar13[6] = 0xff;
        pbVar13[7] = 0xff;
        local_res20 = sVar8 + 1;
        in_RAX = 0;
        if (uVar10 != uVar1) {
          in_RAX = (ulonglong)uVar10;
        }
        lVar6 = local_50;
LAB_140004d30:
        uVar12 = (uint)in_RAX;
        pbVar13 = (byte *)(lVar6 + in_RAX * 8);
      } while (*(int *)(lVar6 + in_RAX * 8) != -1);
      if (local_res20 != 0) {
        *(short *)(param_1 + 0x21e + local_40 * 2) = (short)uVar12;
        if (*(char *)(param_1 + 0xeb2) == '\0') {
          puVar7 = *(uint **)(param_1 + 0x60);
          *puVar7 = (uint)local_40 << 0x18 | uVar12;
        }
        else {
          puVar7 = (uint *)((local_40 & 0xff) >> 3);
          **(uint **)(param_1 + 0x60 + (longlong)puVar7 * 8) = ((uint)local_40 & 7) << 0x18 | uVar12
          ;
        }
        LOCK();
        UNLOCK();
        if (*(char *)(param_1 + 0x129) == '\0') {
          puVar7 = (uint *)(ulonglong)**(uint **)(param_1 + 0x60);
        }
        if (((*(char *)(param_1 + 0xe7b) != '\0') &&
            (puVar7 = *(uint **)(param_1 + 0x5d8), puVar7 == *(uint **)(param_1 + 0x5d0))) &&
           (puVar7 = *(uint **)puVar7, *(longlong *)(puVar7 + 2) == 0)) {
          puVar7 = (uint *)StorPortResume(param_1);
          *(undefined1 *)(param_1 + 0xe7b) = 0;
        }
        return CONCAT71((int7)((ulonglong)puVar7 >> 8),1);
      }
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== LsiCompleteIO @ 140004e40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 LsiCompleteIO(longlong param_1,short *param_2,ushort param_3,int param_4)

{
  longlong lVar1;
  char *pcVar2;
  longlong lVar3;
  undefined8 *puVar4;
  byte bVar5;
  char cVar6;
  uint uVar7;
  undefined8 uVar8;
  uint7 extraout_var;
  longlong lVar9;
  undefined4 uVar10;
  char cVar11;
  undefined1 auStackY_d8 [32];
  ushort *puVar12;
  uint uVar13;
  byte local_97;
  char local_96;
  byte local_95;
  char local_94;
  longlong local_90;
  ushort local_88 [4];
  ushort local_80 [4];
  uint local_78;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 *local_68;
  byte local_60;
  byte local_5f;
  char local_5e;
  ushort local_5c;
  char local_5a;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_88[0] = param_2[7] & 0x7fff;
  local_80[0] = param_3;
  if (*(char *)((longlong)param_2 + 3) != '\0') {
    uVar8 = NonSCB_Func_handler(param_1,param_2,param_3,param_4);
    return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
  }
  local_68 = (undefined8 *)((ulonglong)param_3 * 0x20 + *(longlong *)(param_1 + 0x350));
  lVar1 = local_68[1];
  if (lVar1 == 0) {
    if (param_3 < *(ushort *)(param_1 + 0x66a)) {
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x219) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x219,
                    (undefined1 *)local_80,2,param_4);
      }
      local_68 = (undefined8 *)
                 LogSystemEvent(param_1,0xad010024,0xc004af02,
                                (byte *)"NULL Srb pointer in CompleteIO",param_4);
    }
    return CONCAT71((int7)((ulonglong)local_68 >> 8),1);
  }
  if (lVar1 == *(longlong *)(param_1 + 0x5e8)) {
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x27f) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x27f,(undefined1 *)0x0
                  ,0,param_4);
    }
    uVar8 = LogSystemEvent(param_1,0,0xc004af02,(byte *)"TM processing detected in CompleteIO",
                           param_4);
    return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
  }
  lVar9 = *(longlong *)(lVar1 + 0x68);
  local_95 = *(byte *)(lVar9 + 0x5a);
  local_97 = *(byte *)(lVar9 + 0x5b);
  local_94 = *(char *)(lVar9 + 0x5c);
  uVar10 = *(undefined4 *)(lVar1 + 0x3c);
  local_96 = *(char *)(lVar9 + 0x58);
  local_78 = *(uint *)(lVar1 + 0x18);
  local_90 = *(longlong *)(lVar9 + 0x40);
  cVar11 = (char)param_2[6];
  switch(local_88[0]) {
  case 0:
  case 0x40:
    *(undefined1 *)(lVar1 + 3) = 1;
    break;
  case 1:
    *(undefined1 *)(lVar1 + 3) = 6;
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x225) != 0)) {
      uVar10 = 0x225;
      uVar13 = 0;
      puVar12 = (ushort *)0x0;
LAB_1400053ef:
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),uVar10,
                  (undefined1 *)puVar12,uVar13,param_4);
    }
    break;
  case 3:
  case 6:
  case 7:
  case 10:
  case 0x46:
  case 0x47:
  case 0x4a:
    *(undefined1 *)(lVar1 + 3) = 4;
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x227) != 0)) {
      uVar10 = 0x227;
LAB_1400053d9:
      puVar12 = local_88;
      uVar13 = 2;
      goto LAB_1400053ef;
    }
    break;
  default:
    *(undefined1 *)(lVar1 + 3) = 4;
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x228) != 0)) {
      uVar10 = 0x228;
      goto LAB_1400053d9;
    }
    break;
  case 0x42:
    *(undefined1 *)(lVar1 + 3) = 0x21;
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x21e) != 0)) {
      puVar12 = (ushort *)&local_97;
      uVar13 = 1;
      uVar10 = 0x21e;
      goto LAB_1400053ef;
    }
    break;
  case 0x43:
    *(undefined1 *)(lVar1 + 3) = 10;
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x21a) != 0)) {
      uVar10 = 0x21a;
      uVar13 = 0;
      puVar12 = (ushort *)0x0;
      goto LAB_1400053ef;
    }
    break;
  case 0x44:
    *(undefined1 *)(lVar1 + 3) = 0x12;
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x21b) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x21b,(undefined1 *)0x0
                  ,0,param_4);
    }
    if ((*(byte *)((longlong)param_2 + 0xd) & 8) != 0) {
      *(undefined1 *)(lVar1 + 3) = 4;
      local_6c = *(undefined4 *)(param_2 + 10);
      local_70 = uVar10;
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x272) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x272,
                    (undefined1 *)&local_70,8,param_4);
      }
      LogSystemEvent(param_1,CONCAT22(*param_2,local_88[0]),0x8004af01,
                     (byte *)"LsiCompleteIO:Scsi State Terminated(Received data count logged)",
                     param_4);
    }
    break;
  case 0x45:
    if (((cVar11 - 8U & 0xdf) != 0) && ((*(byte *)((longlong)param_2 + 0xd) & 1) == 0)) {
      *(undefined1 *)(lVar1 + 3) = 0x12;
      *(undefined4 *)(lVar1 + 0x3c) = *(undefined4 *)(param_2 + 10);
    }
    break;
  case 0x48:
    cVar6 = *(char *)(param_1 + 0x161c);
    if ((((cVar6 - 3U & 0xfd) == 0) || ((cVar6 - 1U & 0xfa) != 0)) || (cVar6 == '\x05')) {
LAB_1400052d2:
      *(undefined1 *)(lVar1 + 3) = 0xe;
    }
    else {
      *(undefined1 *)(lVar1 + 3) = 2;
      if ((*(char *)(param_1 + 0x15a2) != '\0') && (*(int *)(lVar1 + 0x28) == 36000)) {
        *(undefined4 *)(lVar1 + 0x28) = 0x8c96;
      }
    }
    break;
  case 0x49:
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x21d) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x21d,(undefined1 *)0x0
                  ,0,param_4);
    }
  case 2:
    cVar11 = '\b';
    *(undefined1 *)(lVar1 + 3) = 5;
    if (*(int *)(lVar1 + 0x28) == 36000) {
      *(undefined4 *)(lVar1 + 0x28) = 35999;
    }
    break;
  case 0x4b:
    if (-1 < param_2[7]) {
LAB_1400052ac:
      if ((*(char *)(param_1 + 0xe7b) == '\0') && (*(int *)(param_1 + 0x630) == 0)) {
        StorPortPause(param_1,0x1e);
        *(undefined1 *)(param_1 + 0xe7b) = 1;
      }
      goto LAB_1400052d2;
    }
    if ((*(uint *)(param_2 + 8) & 0xffff0000) == 0x31120000) {
      if (*(char *)(param_1 + 0xe6b) == '\0') goto LAB_1400052ac;
      *(undefined1 *)(lVar1 + 3) = 4;
      *(undefined4 *)(lVar1 + 0x28) = *(undefined4 *)(param_2 + 8);
    }
    else {
      if ((*(uint *)(param_2 + 8) & 0xffff0000) != 0x31170000) goto LAB_1400052ac;
      *(undefined1 *)(lVar1 + 3) = 5;
      cVar11 = '\b';
    }
    break;
  case 0x4c:
    if ((*(char *)(param_1 + 0xe7b) == '\0') && (*(int *)(param_1 + 0x630) == 0)) {
      StorPortPause(param_1,0x1e);
      *(undefined1 *)(param_1 + 0xe7b) = 1;
    }
    *(undefined1 *)(lVar1 + 3) = 0xe;
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x21f) != 0)) {
      uVar10 = 0x21f;
      uVar13 = 0;
      puVar12 = (ushort *)0x0;
      goto LAB_1400053ef;
    }
    break;
  case 0x4d:
  case 0x4e:
  case 0x4f:
    *(undefined1 *)(lVar1 + 3) = 0xf;
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x226) != 0)) {
      uVar10 = 0x226;
      uVar13 = 0;
      puVar12 = (ushort *)0x0;
      goto LAB_1400053ef;
    }
  }
  lVar3 = local_90;
  bVar5 = *(byte *)((longlong)param_2 + 0xd);
  if (((bVar5 & 0x10) != 0) && ((char)*(undefined4 *)(param_2 + 0xe) == '\x02')) {
    *(undefined1 *)
     (*(longlong *)(param_1 + 0x378) + 0x22 +
     (ulonglong)(ushort)((ushort)local_95 * 0x80 + (ushort)local_97) * 0x28) = 0;
    bVar5 = *(byte *)((longlong)param_2 + 0xd);
  }
  if ((bVar5 & 1) == 0) {
    if ((bVar5 & 2) == 0) {
      if ((((bVar5 & 0x10) != 0) && (*(char *)(lVar1 + 3) == '\x01')) &&
         (*(int *)(param_2 + 0xe) != 0)) {
        cVar11 = '\0';
        *(undefined1 *)(lVar1 + 3) = 4;
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x22a) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x22a,
                      (undefined1 *)(param_2 + 0xe),4,param_4);
        }
        lVar9 = local_90;
        goto LAB_140005752;
      }
    }
    else {
      *(undefined1 *)(lVar1 + 3) = 4;
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x229) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x229,
                    (undefined1 *)0x0,0,param_4);
      }
    }
LAB_140005667:
    lVar9 = local_90;
  }
  else {
    if ((local_78 & 0x20) != 0) {
      memmove(*(void **)(param_1 + 0xea0),(void *)(lVar9 + 0x60),0xff);
      *(undefined1 *)(param_1 + 0xe98) = 1;
      *(undefined1 *)(lVar1 + 3) = 4;
      goto LAB_140005667;
    }
    *(undefined1 *)(lVar1 + 3) = 0x84;
    if ((local_96 == -0x7b) || (local_96 == -0x5f)) {
      uVar13 = *(uint *)(param_2 + 0xc);
    }
    else {
      uVar13 = *(uint *)(param_2 + 0xc);
      if (1 < (byte)(*(char *)(lVar9 + 0x60) + 0x8eU)) {
        bVar5 = *(byte *)(lVar9 + 0x67);
        if (0xf4 < bVar5) {
          *(undefined1 *)(lVar9 + 0x67) = 0xf4;
          bVar5 = 0xf4;
        }
        uVar13 = bVar5 + 8;
      }
    }
    uVar7 = (uint)*(byte *)(local_90 + 9);
    if (uVar13 < *(byte *)(local_90 + 9)) {
      *(char *)(local_90 + 9) = (char)uVar13;
      uVar7 = uVar13 & 0xff;
    }
    memmove(*(void **)(local_90 + 0x10),(void *)(lVar9 + 0x60),(ulonglong)uVar7);
    puVar4 = local_68;
    pcVar2 = *(char **)(lVar3 + 0x10);
    if ((local_96 == -0x7b) || (local_96 == -0x5f)) goto LAB_140005667;
    CheckSmartInfo(param_1,lVar1,pcVar2,*(undefined2 *)((longlong)local_68 + 0x14),param_4);
    if ((byte)(*pcVar2 + 0x8eU) < 2) {
      AfdScsiSenseTrigger(param_1,pcVar2[1] & 0xf,pcVar2[2],pcVar2[3],param_4);
      local_5a = pcVar2[3];
    }
    else {
      AfdScsiSenseTrigger(param_1,pcVar2[2] & 0xf,pcVar2[0xc],pcVar2[0xd],param_4);
      local_5a = pcVar2[0xd];
    }
    lVar9 = local_90;
    bVar5 = local_95;
    if ((((pcVar2[2] & 0xfU) != 6) || (pcVar2[0xc] != ')')) &&
       (((pcVar2[1] & 0xfU) != 6 || (pcVar2[2] != 0x29)))) goto LAB_140005667;
    if ((*(char *)(param_1 + 0xe96) != '\0') &&
       ((*(uint *)(*(longlong *)(param_1 + 0x378) + 0x14 +
                  (ulonglong)(ushort)((ushort)local_95 * 0x80 + (ushort)local_97) * 0x28) >> 10 & 1)
        != 0)) {
      *(char *)(local_90 + 8) = cVar11;
      local_5e = local_94;
      local_5c = local_80[0];
      local_60 = local_95;
      local_5f = local_97;
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x2000b) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x2000b,&local_60,8,
                    param_4);
      }
      cVar6 = HandleUnitAttenReset
                        (param_1,local_80[0],(undefined8 *)*puVar4,bVar5,local_97,local_94,'\x01',
                         param_4);
      if (cVar6 != '\0') {
        return (ulonglong)extraout_var << 8;
      }
    }
  }
  if (((byte)(cVar11 - 0x18U) < 0x29) &&
     ((0x10000000401U >> ((ulonglong)(byte)(cVar11 - 0x18U) & 0x3f) & 1) != 0)) {
    *(undefined1 *)(lVar1 + 3) = 4;
  }
  else if ((cVar11 - 8U & 0xdf) == 0) {
    *(undefined1 *)(lVar1 + 3) = 5;
  }
LAB_140005752:
  *(char *)(lVar9 + 8) = cVar11;
  uVar8 = StorPortNotification(0,param_1,lVar1);
  return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
}



===== PollLSImpiIsr @ 140005840 =====

void PollLSImpiIsr(longlong param_1,int param_2)

{
  int local_18 [2];
  undefined8 local_10;
  
  *(int *)(param_1 + 0x5c0) = param_2;
  local_10 = 0;
  local_18[0] = param_2;
  GtfProcessTimers(param_1,local_18);
  LSImpiMSIIsr(param_1,0);
  *(undefined4 *)(param_1 + 0x5c0) = 5;
  return;
}



===== AddDevice @ 140005880 =====

void AddDevice(longlong param_1,int param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  char cVar3;
  ushort uVar4;
  short sVar5;
  longlong lVar6;
  int *piVar7;
  ushort uVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  char *pcVar12;
  int *piVar13;
  uint *puVar14;
  uint uVar15;
  uint uVar16;
  longlong lVar17;
  int iVar18;
  undefined8 *puVar19;
  int iStackX_1c;
  uint local_78;
  
  lVar17 = (ulonglong)*(uint *)(param_1 + 0x158c) * 0x3cc + *(longlong *)(param_1 + 0x360);
  local_78 = 0;
  if (*(char *)(lVar17 + 0x3c4) != '\0') {
    do {
      puVar19 = (undefined8 *)((ulonglong)local_78 * 0x20 + lVar17);
      if (*(char *)((longlong)puVar19 + 0x1a) == '\x01') {
        uVar8 = *(ushort *)(param_1 + 0x1568) & 0xe;
        if (uVar8 == 2) {
          lVar6 = *(longlong *)(param_1 + 0x358);
          pcVar12 = (char *)(lVar6 + 0x18);
          for (uVar8 = 0; uVar8 < *(byte *)(param_1 + 0x1574); uVar8 = uVar8 + 1) {
            if ((*(short *)(pcVar12 + -6) == *(short *)(lVar17 + 0x3c0)) && (*pcVar12 == '\0')) {
              if (uVar8 != 0xffff) {
                iVar18 = *(int *)(lVar6 + 8 + (ulonglong)uVar8 * 0x24);
                puVar1 = (undefined8 *)(lVar6 + (ulonglong)uVar8 * 0x24);
                if (iVar18 == -1) {
                  if (*(char *)(param_1 + 0xe8c) == '\0') goto LAB_1400059b1;
                  pcVar12 = "Driver encl-slot mapping table is full (AddDevice)";
                  goto LAB_140005995;
                }
                uVar8 = *(ushort *)((longlong)puVar19 + 0x16);
                uVar4 = *(ushort *)((longlong)puVar1 + 0x16);
                if ((uVar8 < uVar4) ||
                   ((int)((uVar4 - 1) + (uint)*(ushort *)((longlong)puVar1 + 0x14)) <
                    (int)(uint)uVar8)) {
                  LogSystemEvent(param_1,0xad010053,0xc004af02,
                                 (byte *)"Device slot number is outside the enclosure range",param_2
                                );
                  if ((*(char *)(param_1 + 0x3b8) != '\0') &&
                     ((*(uint *)(param_1 + 0x3bc) & 0x246) != 0)) {
                    RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x246,
                                (undefined1 *)((longlong)puVar19 + 0x14),2,param_2);
                  }
                  goto LAB_140005e8b;
                }
                uVar15 = iVar18 + ((uint)uVar8 - (uint)uVar4);
                puVar2 = (undefined8 *)(*(longlong *)(param_1 + 0x378) + (ulonglong)uVar15 * 0x28);
                *puVar2 = *puVar19;
                puVar2[1] = puVar19[1];
                *(short *)((longlong)puVar2 + 0x1c) = (short)(uVar15 >> 7);
                *(ushort *)((longlong)puVar2 + 0x1e) = (ushort)uVar15 & 0x7f;
                *(undefined2 *)((longlong)puVar2 + 0x1a) = *(undefined2 *)((longlong)puVar19 + 0x14)
                ;
                *(undefined1 *)(puVar2 + 4) = 0;
                *(undefined2 *)(puVar2 + 3) = *(undefined2 *)(puVar1 + 2);
                *(uint *)((longlong)puVar2 + 0x14) = *(uint *)(puVar19 + 2) | 0x30000000;
                *(undefined1 *)((longlong)puVar2 + 0x26) = *(undefined1 *)((longlong)puVar19 + 0x1c)
                ;
                if ((*(char *)((longlong)puVar19 + 0x1b) == -4) &&
                   (uVar9 = CheckFastPathToggle(param_1), (char)uVar9 != '\0')) {
                  *(undefined1 *)((longlong)puVar2 + 0x24) = 0xc;
                }
                *(undefined1 *)(param_1 + 0x380) = 1;
                if ((*(byte *)(param_1 + 0x1568) & 1) == 0) {
                  uVar8 = *(ushort *)(puVar1 + 2);
                  if ((uVar8 == 0xffff) &&
                     (uVar8 = GetDPMPage0IndexFromID
                                        (param_1,*puVar1,*(uint *)((longlong)puVar1 + 0xc)),
                     uVar8 == 0xffff)) {
                    uVar10 = GetFirstFreeDPMPage0(param_1);
                    if ((short)uVar10 != -1) {
                      uVar11 = uVar10 & 0xffff;
                      lVar6 = *(longlong *)(param_1 + 0x15c8) + uVar11 * 0x14;
                      *(undefined8 *)(lVar6 + 8) = *puVar1;
                      *(undefined2 *)(lVar6 + 0x12) = *(undefined2 *)(puVar1 + 1);
                      *(short *)(lVar6 + 0x10) = *(short *)((longlong)puVar1 + 0x14) << 4;
                      *(undefined4 *)(lVar6 + 0x14) = *(undefined4 *)((longlong)puVar1 + 0xc);
                      *(undefined1 *)(uVar11 + *(longlong *)(param_1 + 0x1580)) = 1;
                      *(short *)(puVar1 + 2) = (short)uVar10;
                      *(undefined1 *)(uVar11 + *(longlong *)(param_1 + 0x1578)) = 1;
                      *(undefined1 *)((longlong)puVar1 + 0x1b) = 1;
                      goto LAB_140005e8b;
                    }
                    if ((*(char *)(param_1 + 0xb4a5) != '\0') &&
                       (*(char *)(param_1 + 0xb4a4) == '\0')) {
                      LogSystemEvent(param_1,0xad010045,0xc004af02,
                                     (byte *)
                                     "persistent mapping config page is full (AddDevice encl-slot)",
                                     param_2);
                      *(undefined1 *)(param_1 + 0xb4a4) = 1;
                      *(undefined1 *)((longlong)puVar1 + 0x1b) = 1;
                      goto LAB_140005e8b;
                    }
                  }
                  else {
                    *(ushort *)(puVar2 + 3) = uVar8;
                    *(ushort *)(puVar1 + 2) = uVar8;
                  }
                }
                *(undefined1 *)((longlong)puVar1 + 0x1b) = 1;
                goto LAB_140005e8b;
              }
              break;
            }
            pcVar12 = pcVar12 + 0x24;
          }
          LogSystemEvent(param_1,0xad010040,0xc004af02,(byte *)"Enclosure not found (AddDevice)",
                         param_2);
        }
        else if (uVar8 == 0) {
          piVar7 = *(int **)(param_1 + 0x378);
          uVar15 = *(uint *)(param_1 + 0x678);
          iStackX_1c = (int)((ulonglong)*puVar19 >> 0x20);
          piVar13 = piVar7;
          for (uVar10 = 0; (uint)uVar10 < uVar15; uVar10 = (ulonglong)((uint)uVar10 + 1)) {
            if ((*piVar13 == (int)*puVar19) && (piVar13[1] == iStackX_1c)) goto LAB_140005c50;
            piVar13 = piVar13 + 10;
          }
          uVar10 = 0xffffffff;
LAB_140005c50:
          if ((int)uVar10 == -1) {
            uVar16 = *(uint *)(param_1 + 0x1598);
            if (*(short *)(lVar17 + 0x3c2) != 0) {
              uVar16 = uVar16 + *(ushort *)(param_1 + 0x1566);
            }
            uVar10 = (ulonglong)uVar16;
            if (uVar16 < uVar15) {
              puVar14 = (uint *)(piVar7 + uVar10 * 10 + 5);
              do {
                if ((*puVar14 & 0x30000000) == 0) goto LAB_140005c9f;
                uVar16 = (int)uVar10 + 1;
                uVar10 = (ulonglong)uVar16;
                puVar14 = puVar14 + 10;
              } while (uVar16 < uVar15);
            }
            uVar10 = 0xffffffff;
LAB_140005c9f:
            if ((int)uVar10 == -1) {
              uVar15 = GetHighMissingMapTableIndex(param_1);
              uVar10 = (ulonglong)uVar15;
              if (uVar15 == 0xffffffff) {
                if (*(char *)(param_1 + 0xe8c) == '\0') {
LAB_1400059b1:
                  *(undefined1 *)(param_1 + 0xe8b) = 1;
                }
                else {
                  pcVar12 = "Driver address mapping table is full (AddDevice)";
LAB_140005995:
                  LogSystemEvent(param_1,0xad010027,0xc004af02,(byte *)pcVar12,param_2);
                }
                goto LAB_140005e8b;
              }
              sVar5 = *(short *)((longlong)piVar7 + uVar10 * 0x28 + 0x1a);
              if (sVar5 != 0) {
                AddToRemovalTable(param_1,sVar5,0,param_2);
                *(undefined1 *)(param_1 + 0xe89) = 1;
              }
              *(undefined1 *)((longlong)piVar7 + uVar10 * 0x28 + 0x21) = 0;
            }
          }
          piVar7 = (int *)(*(longlong *)(param_1 + 0x378) + uVar10 * 0x28);
          *(undefined8 *)piVar7 = *puVar19;
          *(undefined8 *)(piVar7 + 2) = puVar19[1];
          *(short *)(piVar7 + 7) = (short)((uint)uVar10 >> 7);
          *(ushort *)((longlong)piVar7 + 0x1e) = (ushort)uVar10 & 0x7f;
          *(undefined2 *)((longlong)piVar7 + 0x1a) = *(undefined2 *)((longlong)puVar19 + 0x14);
          *(undefined1 *)(piVar7 + 8) = 0;
          piVar7[5] = *(uint *)(puVar19 + 2) | 0x30000000;
          *(undefined1 *)((longlong)piVar7 + 0x26) = *(undefined1 *)((longlong)puVar19 + 0x1c);
          if (*(char *)((longlong)puVar19 + 0x1b) == -4) {
            if ((*(char *)(param_1 + 0xec6) == '\0') ||
               (cVar3 = *(char *)(param_1 + 0xec7), *(char *)(param_1 + 0xec7) = cVar3 + '\x01',
               cVar3 != *(char *)(param_1 + 0xec6))) {
              *(undefined1 *)(piVar7 + 9) = 0xc;
            }
            else {
              *(undefined1 *)(param_1 + 0xec7) = 0;
            }
          }
          *(undefined1 *)(param_1 + 0x380) = 1;
          if ((*(byte *)(param_1 + 0x1568) & 1) == 0) {
            uVar8 = *(ushort *)(piVar7 + 6);
            if (uVar8 == 0xffff) {
              uVar11 = GetFirstFreeDPMPage0(param_1);
              uVar8 = (ushort)uVar11;
              *(undefined1 *)((longlong)piVar7 + 0x21) = 0;
            }
            else {
              lVar6 = *(longlong *)(param_1 + 0x15c8) + (ulonglong)uVar8 * 0x14;
              if (((*(int *)(lVar6 + 8) == *piVar7) && (*(int *)(lVar6 + 0xc) == piVar7[1])) &&
                 ((*(byte *)(lVar6 + 0x10) & 0xf) == 0)) {
                *(undefined1 *)((longlong)piVar7 + 0x21) = 1;
              }
            }
            if (uVar8 == 0xffff) {
              if ((*(char *)(param_1 + 0xb4a5) != '\0') && (*(char *)(param_1 + 0xb4a4) == '\0')) {
                LogSystemEvent(param_1,0xad010045,0xc004af02,
                               (byte *)
                               "persistent mapping config page is full (AddDevice addr mapping)",
                               param_2);
                *(undefined1 *)(param_1 + 0xb4a4) = 1;
              }
            }
            else if (*(char *)((longlong)piVar7 + 0x21) == '\0') {
              *(ushort *)(piVar7 + 6) = uVar8;
              *(undefined1 *)((longlong)piVar7 + 0x21) = 1;
              uVar11 = (ulonglong)uVar8;
              lVar6 = *(longlong *)(param_1 + 0x15c8) + uVar11 * 0x14;
              *(undefined8 *)(lVar6 + 8) = *(undefined8 *)piVar7;
              *(undefined2 *)(lVar6 + 0x10) = 0;
              *(ushort *)(lVar6 + 0x12) = (ushort)uVar10;
              *(undefined4 *)(lVar6 + 0x14) = 0;
              *(undefined1 *)(uVar11 + *(longlong *)(param_1 + 0x1580)) = 1;
              *(undefined1 *)(uVar11 + *(longlong *)(param_1 + 0x1578)) = 1;
            }
          }
          *(undefined1 *)((longlong)piVar7 + 0x21) = 1;
        }
      }
LAB_140005e8b:
      *(undefined4 *)puVar19 = 0;
      *(undefined4 *)((longlong)puVar19 + 4) = 0;
      *(undefined4 *)(puVar19 + 1) = 0;
      *(undefined4 *)((longlong)puVar19 + 0xc) = 0;
      *(undefined4 *)(puVar19 + 2) = 0;
      *(undefined2 *)((longlong)puVar19 + 0x14) = 0;
      *(undefined2 *)((longlong)puVar19 + 0x16) = 0;
      *(undefined1 *)(puVar19 + 3) = 0;
      *(undefined1 *)((longlong)puVar19 + 0x19) = 0;
      *(undefined1 *)((longlong)puVar19 + 0x1a) = 0;
      *(undefined1 *)((longlong)puVar19 + 0x1b) = 0;
      local_78 = local_78 + 1;
      *(undefined1 *)((longlong)puVar19 + 0x1c) = 0;
    } while (local_78 < *(byte *)(lVar17 + 0x3c4));
  }
  if (*(char *)(param_1 + 0xe89) != '\0') {
    *(undefined1 *)(param_1 + 0xe89) = 0;
    RemoveDevice(param_1,param_2);
    return;
  }
  *(undefined1 *)(lVar17 + 0x3c4) = 0;
  *(undefined1 *)(param_1 + 0xe8a) = 1;
  *(undefined1 *)(param_1 + 0x676) = 1;
  iVar18 = 0;
  if ((uint)((*(int *)(param_1 + 0x158c) + 2) * 0x3cc) <= (uint)*(ushort *)(param_1 + 0x65c) * 0x3cc
     ) {
    iVar18 = *(int *)(param_1 + 0x158c) + 1;
  }
  *(int *)(param_1 + 0x158c) = iVar18;
  SendExtendedConfigPageMessage
            (param_1,'\x01',(char *)(param_1 + 0x15d8),0x20000000,
             (int)*(undefined8 *)(param_1 + 0x15e0),param_2);
  return;
}



===== AddOrRemoveIrVolume @ 140006010 =====

void AddOrRemoveIrVolume(longlong param_1,int param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  bool bVar3;
  char cVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  longlong lVar8;
  ulonglong uVar9;
  ushort uVar10;
  byte bVar11;
  longlong lVar12;
  uint uVar13;
  int *piVar14;
  ulonglong uVar15;
  uint local_res18;
  int iStack_44;
  
  do {
    uVar6 = 0;
    bVar3 = false;
    lVar8 = (ulonglong)*(uint *)(param_1 + 0x1594) * 0x188 + *(longlong *)(param_1 + 0x368);
    local_res18 = 0;
    if (*(char *)(lVar8 + 0x184) != '\0') {
      do {
        *(undefined1 *)(param_1 + 0x380) = 1;
        cVar4 = *(char *)(lVar8 + 0x13 + uVar6 * 0x18);
        puVar1 = (undefined8 *)(lVar8 + uVar6 * 0x18);
        if ((cVar4 == '\x01') || (cVar4 == '\x06')) {
          uVar7 = *puVar1;
          uVar10 = *(ushort *)(param_1 + 0x156c) & 3;
          if (uVar10 == 0) {
            bVar11 = *(byte *)(param_1 + 0x65f);
            uVar5 = *(ushort *)(param_1 + 0x1568) >> 4 & 1;
          }
          else {
            bVar11 = *(byte *)(param_1 + 0x65f);
            uVar5 = (uint)*(ushort *)(param_1 + 0x658) - (uint)bVar11;
          }
          uVar6 = (ulonglong)uVar5;
          lVar2 = *(longlong *)(param_1 + 0x378);
          uVar13 = (bVar11 - 1) + uVar5;
          piVar14 = (int *)(lVar2 + uVar6 * 0x28);
          if (uVar5 <= uVar13) {
            iStack_44 = (int)((ulonglong)uVar7 >> 0x20);
            do {
              uVar5 = (uint)uVar6;
              if ((*piVar14 == (int)uVar7) && (piVar14[1] == iStack_44)) {
                if (uVar5 != 0xffffffff) {
                  *(short *)(lVar2 + 0x1c + uVar6 * 0x28) = (short)(uVar5 >> 7);
                  *(ushort *)(lVar2 + 0x1e + uVar6 * 0x28) = (ushort)uVar6 & 0x7f;
                  *(undefined2 *)(lVar2 + 0x1a + uVar6 * 0x28) =
                       *(undefined2 *)((longlong)puVar1 + 0xe);
                  *(undefined4 *)(lVar2 + 0x14 + uVar6 * 0x28) = 0x30000000;
                  UpdateIrMissingCount(param_1,uVar5,puVar1,param_2);
                  goto LAB_1400063b5;
                }
                break;
              }
              uVar6 = (ulonglong)(uVar5 + 1);
              piVar14 = piVar14 + 10;
            } while (uVar5 + 1 <= uVar13);
          }
          uVar6 = GetFirstFreeIrMapTableIndex(param_1);
          uVar15 = uVar6 & 0xffffffff;
          if ((int)uVar6 == -1) {
            bVar3 = true;
          }
          else {
            uVar6 = uVar15;
            if (local_res18 < *(byte *)(lVar8 + 0x184) - 1) {
              if (uVar10 == 0) {
                uVar5 = *(ushort *)(param_1 + 0x1568) >> 4 & 1;
              }
              else {
                uVar5 = (uint)*(ushort *)(param_1 + 0x658) - (uint)bVar11;
              }
              lVar12 = (ulonglong)*(uint *)(param_1 + 0x1594) * 0x188 +
                       *(longlong *)(param_1 + 0x368);
              do {
                piVar14 = (int *)(lVar2 + uVar6 * 0x28);
                uVar13 = local_res18;
                do {
                  uVar13 = uVar13 + 1;
                  if (*(byte *)(lVar12 + 0x184) <= uVar13) goto LAB_1400062e7;
                  uVar9 = (ulonglong)uVar13;
                  cVar4 = *(char *)(lVar12 + 0x13 + uVar9 * 0x18);
                } while ((((cVar4 != '\x01') && (cVar4 != '\x06')) ||
                         (*piVar14 != *(int *)(lVar12 + uVar9 * 0x18))) ||
                        (piVar14[1] != *(int *)(lVar12 + 4 + uVar9 * 0x18)));
                do {
                  uVar13 = (int)uVar6 + 1;
                  uVar6 = (ulonglong)uVar13;
                  if ((uVar5 - 1) + (uint)bVar11 < uVar13) {
                    bVar3 = true;
                    uVar6 = uVar15;
                    goto LAB_1400062e7;
                  }
                } while ((*(uint *)(lVar2 + 0x14 + uVar6 * 0x28) & 0x10000000) != 0);
              } while( true );
            }
LAB_1400062e7:
            if (!bVar3) {
              *(short *)(lVar2 + 0x1c + uVar6 * 0x28) = (short)((uint)uVar6 >> 7);
              *(undefined8 *)(lVar2 + uVar6 * 0x28) = uVar7;
              *(ushort *)(lVar2 + 0x1e + uVar6 * 0x28) = (ushort)uVar6 & 0x7f;
              *(undefined2 *)(lVar2 + 0x1a + uVar6 * 0x28) = *(undefined2 *)((longlong)puVar1 + 0xe)
              ;
              *(undefined4 *)(lVar2 + 0x14 + uVar6 * 0x28) = 0x30000000;
              *(undefined1 *)(lVar2 + 0x21 + uVar6 * 0x28) = 0;
              UpdateIrMissingCount(param_1,(uint)uVar6,puVar1,param_2);
              goto LAB_1400063b5;
            }
          }
          LogSystemEvent(param_1,0xad01004f,0xc004af02,&s_IR_Mapping_Table_Full,param_2);
          *puVar1 = 0;
          puVar1[1] = 0;
          *(undefined4 *)(puVar1 + 2) = 0;
        }
        else {
          if (cVar4 == '\x02') {
            uVar6 = GetMapTableIndexFromWWID(param_1,*puVar1);
            if ((uint)uVar6 == 0xffffffff) {
              LogSystemEvent(param_1,0xad01003f,0xc004af02,
                             (byte *)"IR volume not mapped (Reason = 0x02)",param_2);
            }
            else {
              UpdateIrMissingCount(param_1,(uint)uVar6,puVar1,param_2);
            }
          }
          else if (cVar4 == '\a') {
            uVar5 = GetMapTableIndexFromHandle(param_1,*(short *)((longlong)puVar1 + 0xe));
            if (uVar5 == 0xffffffff) {
              LogSystemEvent(param_1,0xad01003f,0xc004af02,
                             (byte *)"IR volume not mapped (Reason = 0x07)",param_2);
            }
            else {
              *(undefined4 *)(*(longlong *)(param_1 + 0x378) + 0x14 + (ulonglong)uVar5 * 0x28) =
                   0x20000000;
              UpdateIrMissingCount(param_1,uVar5,puVar1,param_2);
            }
          }
LAB_1400063b5:
          *(undefined4 *)(puVar1 + 2) = 0;
          puVar1[1] = 0;
          *puVar1 = 0;
        }
        local_res18 = local_res18 + 1;
        uVar6 = (ulonglong)local_res18;
      } while (local_res18 < *(byte *)(lVar8 + 0x184));
    }
    *(undefined1 *)(lVar8 + 0x184) = 0;
    uVar5 = 0;
    if (*(int *)(param_1 + 0x1594) != 9) {
      uVar5 = *(int *)(param_1 + 0x1594) + 1;
    }
    *(uint *)(param_1 + 0x1594) = uVar5;
    if (*(char *)((ulonglong)uVar5 * 0x188 + 0x184 + *(longlong *)(param_1 + 0x368)) == '\0') {
      *(undefined1 *)(param_1 + 0xe85) = 0;
      if (*(char *)((ulonglong)*(uint *)(param_1 + 0x158c) * 0x3cc + 0x3c4 +
                   *(longlong *)(param_1 + 0x360)) == '\0') {
        cVar4 = '\0';
        if (*(longlong *)(param_1 + 0x5e8) == 0) {
          if (*(int *)(param_1 + 0xec0) == 0) {
            uVar7 = CheckResetQueue(param_1,param_2);
            cVar4 = (char)uVar7;
            goto LAB_1400064c2;
          }
        }
        else {
LAB_1400064c2:
          if (((*(int *)(param_1 + 0xec0) == 0) && (cVar4 == '\0')) &&
             (*(longlong *)(param_1 + 0x5e8) == 0)) {
            StorPortResume(param_1);
            ResetActive(param_1,0x40000001,param_2);
          }
        }
        if (*(char *)(param_1 + 0x380) != '\0') {
          *(undefined1 *)(param_1 + 0x380) = 0;
          *(undefined1 *)(param_1 + 0xe44) = 1;
          if ((*(int *)(param_1 + 0xec0) == 0) && (uVar10 = 0, *(short *)(param_1 + 0x660) != 0)) {
            do {
              if ((*(char *)(param_1 + 0x3b8) != '\0') &&
                 ((*(uint *)(param_1 + 0x3bc) & 0x100004) != 0)) {
                RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x100004,
                            (undefined1 *)0x0,0,param_2);
              }
              StorPortNotification(7,param_1,uVar10);
              uVar10 = uVar10 + 1;
            } while (uVar10 < *(ushort *)(param_1 + 0x660));
          }
        }
      }
      else {
        *(undefined1 *)(param_1 + 0xe84) = 1;
        UpdateMissingCount(param_1,param_2);
        uVar7 = ReadIDs(param_1,param_2);
        if ((char)uVar7 == '\0') {
          *(undefined1 *)(param_1 + 0xe86) = 0;
          RemoveDevice(param_1,param_2);
        }
      }
      return;
    }
    uVar7 = ReadIrIDs(param_1,param_2);
    if ((char)uVar7 != '\0') {
      return;
    }
    *(undefined1 *)(param_1 + 0xe87) = 0;
  } while( true );
}



===== AddToRemovalTable @ 1400065a0 =====

void AddToRemovalTable(longlong param_1,short param_2,short param_3,int param_4)

{
  longlong lVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  longlong lVar4;
  ushort uVar5;
  uint uVar6;
  ulonglong uVar7;
  short *psVar8;
  uint uVar9;
  short *psVar10;
  bool bVar11;
  short local_res10 [4];
  
  psVar8 = *(short **)(param_1 + 0x370);
  lVar4 = *(longlong *)(param_1 + 0x378);
  uVar9 = 0;
  psVar10 = (short *)(lVar4 + 0x1a);
  uVar7 = 0;
  while (uVar6 = (uint)uVar7, local_res10[0] = param_2, uVar6 < *(uint *)(param_1 + 0x678)) {
    if (*psVar10 == param_2) {
      if (uVar6 != 0xffffffff) {
        uVar2 = *(undefined1 *)(lVar4 + 0x1c + uVar7 * 0x28);
        lVar1 = lVar4 + uVar7 * 0x28;
        uVar3 = *(undefined1 *)(lVar4 + 0x1e + uVar7 * 0x28);
        *(undefined2 *)(lVar1 + 0x25) = 0;
        *(undefined2 *)(lVar1 + 0x1a) = 0;
        ResumeDevice(param_1,uVar2,uVar3,0,param_2,0xff,3,param_4);
        if (*(int *)(lVar1 + 0x14) < 0) {
          SendSEPMessage(param_1,0,local_res10[0],param_4);
          *(uint *)(lVar1 + 0x14) = *(uint *)(lVar1 + 0x14) & 0x7fffffff;
        }
        goto LAB_1400066cb;
      }
      break;
    }
    psVar10 = psVar10 + 0x14;
    uVar7 = (ulonglong)(uVar6 + 1);
  }
  LogSystemEvent(param_1,0xad01003f,0xc004af02,(byte *)"Device not mapped (AddToRemovalTable)",
                 param_4);
  if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x230) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x230,
                (undefined1 *)local_res10,2,param_4);
  }
LAB_1400066cb:
  if (*(uint *)(param_1 + 0x678) == 0) {
    return;
  }
  while ((psVar8[1] != 0 || (*psVar8 != -1))) {
    uVar9 = uVar9 + 1;
    psVar8 = psVar8 + 4;
    if (*(uint *)(param_1 + 0x678) <= uVar9) {
      return;
    }
  }
  uVar5 = *(ushort *)(param_1 + 0x1568) & 0xe;
  if (uVar5 == 2) {
    if (param_3 == 0) goto LAB_14000672e;
    *psVar8 = param_3;
    bVar11 = param_3 == -1;
  }
  else {
    bVar11 = uVar5 == 0;
  }
  if (!bVar11) {
    return;
  }
LAB_14000672e:
  psVar8[1] = local_res10[0];
  return;
}



===== AtaIdentifyTimeout @ 140006750 =====

ulonglong AtaIdentifyTimeout(longlong param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  byte bVar1;
  undefined2 *puVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x243) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x243,(undefined1 *)0x0,0
                ,param_4);
  }
  puVar2 = *(undefined2 **)(param_1 + 0x330);
  lVar4 = (ulonglong)*(uint *)(param_1 + 0x158c) * 0x3cc + *(longlong *)(param_1 + 0x360);
  bVar1 = *(byte *)(lVar4 + 0x3c7);
  *(undefined1 *)(param_1 + 0xeb1) = 1;
  ZeroMemory((undefined1 *)puVar2,0x34);
  *puVar2 = *(undefined2 *)((ulonglong)bVar1 * 0x20 + lVar4 + 0x14);
  *(undefined1 *)((longlong)puVar2 + 3) = 1;
  *(undefined1 *)((longlong)puVar2 + 5) = 1;
  uVar3 = QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x672) * 0x10000 + 6,0,param_4)
  ;
  return uVar3 & 0xffffffffffffff00;
}



===== BusTargetDevHandleMapping @ 140006830 =====

undefined8 BusTargetDevHandleMapping(longlong param_1,longlong param_2)

{
  short sVar1;
  short sVar2;
  longlong lVar3;
  bool bVar4;
  ushort uVar5;
  longlong lVar6;
  bool bVar7;
  
  lVar3 = *(longlong *)(param_2 + 0x40);
  bVar7 = false;
  bVar4 = false;
  if (*(uint *)(lVar3 + 0x18) < 0xc) {
    return 0;
  }
  sVar1 = *(short *)(lVar3 + 0x20);
  uVar5 = *(ushort *)(lVar3 + 0x1c);
  sVar2 = *(short *)(lVar3 + 0x24);
  if ((sVar1 == -1) && (uVar5 == 0xffff)) {
    if (sVar2 == -1) {
      return 0;
    }
    bVar4 = true;
  }
  if ((sVar2 == -1) && (sVar1 != -1)) {
    bVar7 = uVar5 != 0xffff;
  }
  if (bVar4) {
    if (!bVar7) {
      lVar6 = *(longlong *)(param_1 + 0x378);
      uVar5 = 0;
      if (*(uint *)(param_1 + 0x678) == 0) {
        return 0x28;
      }
      do {
        if (*(short *)(lVar6 + 0x1a) == sVar2) {
          uVar5 = *(ushort *)(lVar6 + 0x1c);
          *(uint *)(lVar3 + 0x1c) = (uint)*(ushort *)(lVar6 + 0x1e);
          *(uint *)(lVar3 + 0x20) = (uint)uVar5;
          return 0x28;
        }
        uVar5 = uVar5 + 1;
        lVar6 = lVar6 + 0x28;
      } while ((uint)uVar5 < *(uint *)(param_1 + 0x678));
      return 0x28;
    }
  }
  else if (!bVar7) {
    return 0;
  }
  if (((uVar5 < 0x80) && (uVar5 = sVar1 * 0x80 + uVar5, (uint)uVar5 < *(uint *)(param_1 + 0x678)))
     && (sVar1 = *(short *)(*(longlong *)(param_1 + 0x378) + 0x1a + (ulonglong)uVar5 * 0x28),
        sVar1 != 0)) {
    *(short *)(lVar3 + 0x24) = sVar1;
    return 0x28;
  }
  return 0x28;
}



===== CheckFastPathToggle @ 140006930 =====

ulonglong CheckFastPathToggle(longlong param_1)

{
  byte bVar1;
  uint uVar2;
  ulonglong in_RAX;
  
  if (*(byte *)(param_1 + 0xec6) != 0) {
    bVar1 = *(byte *)(param_1 + 0xec7);
    uVar2 = bVar1 + 1;
    in_RAX = (ulonglong)uVar2;
    *(char *)(param_1 + 0xec7) = (char)uVar2;
    if (bVar1 == *(byte *)(param_1 + 0xec6)) {
      *(undefined1 *)(param_1 + 0xec7) = 0;
      return (ulonglong)(uVar2 & 0xffffff00);
    }
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== ClearEnclosureEntry @ 140006960 =====

void ClearEnclosureEntry(undefined8 *param_1)

{
  *(undefined4 *)(param_1 + 1) = 0xffffffff;
  *param_1 = 0;
  *(undefined4 *)((longlong)param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 3) = 0;
  *(undefined1 *)((longlong)param_1 + 0x1c) = 0;
  *(undefined2 *)((longlong)param_1 + 0x1e) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  param_1[2] = 0xffff;
  return;
}



===== ClearMapEntry @ 140006990 =====

void ClearMapEntry(longlong param_1,undefined8 *param_2)

{
  param_2[3] = 0xffff;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  *(undefined2 *)(param_2 + 4) = 0;
  *(undefined1 *)((longlong)param_2 + 0x22) = *(undefined1 *)(param_1 + 0x65e);
  *(undefined2 *)((longlong)param_2 + 0x23) = 0;
  *(undefined1 *)((longlong)param_2 + 0x27) = 0;
  return;
}



===== CompressEnclosureTable @ 1400069c0 =====

void CompressEnclosureTable(longlong param_1)

{
  bool bVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  ushort uVar4;
  undefined8 *puVar5;
  uint uVar6;
  ushort uVar7;
  int *piVar8;
  ushort uVar9;
  
  if ((*(byte *)(param_1 + 0x1568) & 0xe) == 2) {
    uVar4 = (ushort)*(byte *)(param_1 + 0x1574);
    do {
      piVar8 = *(int **)(param_1 + 0x358);
      bVar1 = true;
      uVar9 = 0;
      if (uVar4 == 0) {
        return;
      }
      do {
        if (((*piVar8 == 0) && (piVar8[1] == 0)) && (*(char *)((longlong)piVar8 + 0x1b) != '\0')) {
          bVar1 = false;
          uVar6 = (uint)uVar9;
          if (uVar6 == uVar4 - 1) {
            piVar8[0] = 0;
            piVar8[1] = 0;
            piVar8[2] = -1;
            piVar8[3] = 0;
            piVar8[4] = 0xffff;
            piVar8[5] = 0;
            piVar8[6] = 0;
            *(undefined1 *)(piVar8 + 7) = 0;
            *(undefined2 *)((longlong)piVar8 + 0x1e) = 0;
            *(undefined1 *)(piVar8 + 8) = 0;
          }
          else {
            puVar5 = (undefined8 *)(*(longlong *)(param_1 + 0x358) + (ulonglong)uVar9 * 0x24);
            puVar3 = (undefined8 *)(*(longlong *)(param_1 + 0x358) + (ulonglong)(uVar9 + 1) * 0x24);
            uVar7 = uVar9;
            while ((int)uVar6 < (int)(uVar4 - 1)) {
              uVar2 = puVar3[1];
              uVar7 = uVar7 + 1;
              *puVar5 = *puVar3;
              puVar5[1] = uVar2;
              uVar2 = puVar3[3];
              puVar5[2] = puVar3[2];
              puVar5[3] = uVar2;
              *(undefined4 *)(puVar5 + 4) = *(undefined4 *)(puVar3 + 4);
              puVar5 = (undefined8 *)((longlong)puVar5 + 0x24);
              puVar3 = (undefined8 *)((longlong)puVar3 + 0x24);
              uVar6 = (uint)uVar7;
            }
            *puVar5 = 0;
            *(undefined4 *)(puVar5 + 1) = 0xffffffff;
            *(undefined4 *)((longlong)puVar5 + 0xc) = 0;
            puVar5[2] = 0xffff;
            *(undefined4 *)(puVar5 + 3) = 0;
            *(undefined1 *)((longlong)puVar5 + 0x1c) = 0;
            *(undefined2 *)((longlong)puVar5 + 0x1e) = 0;
            *(undefined1 *)(puVar5 + 4) = 0;
          }
          *(char *)(param_1 + 0x1574) = *(char *)(param_1 + 0x1574) + -1;
          uVar4 = (ushort)*(byte *)(param_1 + 0x1574);
        }
        uVar9 = uVar9 + 1;
        piVar8 = piVar8 + 9;
      } while (uVar9 < uVar4);
    } while (!bVar1);
  }
  return;
}



===== ContinueHashedSASAddress @ 140006b30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ContinueHashedSASAddress(longlong param_1,longlong param_2,int param_3)

{
  undefined1 uVar1;
  ulonglong uVar2;
  int *piVar3;
  undefined8 uVar4;
  uint uVar5;
  longlong lVar6;
  undefined1 *puVar7;
  uint uVar8;
  longlong lVar9;
  int *piVar10;
  byte bVar11;
  int iVar12;
  longlong lVar13;
  undefined1 auStackY_98 [32];
  undefined4 local_68;
  int local_64 [9];
  undefined1 local_40 [24];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_98;
  GtfStopTimer(param_1,*(byte *)(param_1 + 0xeb0),param_3);
  lVar6 = (ulonglong)*(uint *)(param_1 + 0x158c) * 0x3cc + *(longlong *)(param_1 + 0x360);
  piVar10 = (int *)((ulonglong)*(byte *)(lVar6 + 0x3c7) * 0x20 + lVar6);
  if (((*(ushort *)(param_2 + 0xe) & 0x7fff) == 0) && (*(char *)(param_2 + 0xd) == '\0')) {
    lVar6 = *(longlong *)(param_1 + 0xea8);
    puVar7 = (undefined1 *)((longlong)&local_68 + 1);
    lVar13 = lVar6 - ((longlong)&local_68 + 1);
    lVar9 = 0x14;
    do {
      puVar7[-1] = puVar7[lVar13 + 0x37];
      *puVar7 = puVar7[lVar13 + 0x36];
      puVar7 = puVar7 + 2;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    bVar11 = 0;
    puVar7 = local_40;
    do {
      uVar2 = (ulonglong)bVar11;
      bVar11 = bVar11 + 2;
      uVar1 = *(undefined1 *)(uVar2 + 0x15 + lVar6);
      puVar7[1] = (puVar7 + 2)[(lVar6 - (longlong)local_40) + 0x12];
      *puVar7 = uVar1;
      puVar7 = puVar7 + 2;
    } while (bVar11 < 0x14);
    iVar12 = 0;
    piVar3 = &local_68;
    uVar8 = 0;
    lVar9 = 7;
    do {
      iVar12 = iVar12 + *piVar3;
      uVar8 = uVar8 + piVar3[1];
      piVar3 = piVar3 + 2;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    *piVar10 = *piVar3 + iVar12;
    uVar5 = uVar8 | 0x80;
    if (((byte)uVar8 & 0xf0) != 0x50) {
      uVar5 = uVar8;
    }
    piVar10[1] = uVar5;
    if (*(short *)(lVar6 + 0x1b2) == 1) {
      *(undefined1 *)(piVar10 + 7) = 1;
    }
  }
  else {
    if (*(char *)((longlong)piVar10 + 0x1b) != '\x05') {
      *(char *)((longlong)piVar10 + 0x1b) = *(char *)((longlong)piVar10 + 0x1b) + '\x01';
      SendSTPIdentifyCommand(param_1,piVar10[4],(short)piVar10[5],param_3);
      return;
    }
    LogSystemEvent(param_1,0xad010051,0xc004af02,
                   (byte *)"An ATA Identify command failed on a SATA target",param_3);
  }
  if ((*(ushort *)(*(longlong *)(param_1 + 0x15e0) + 0x20) & 0x2000) != 0) {
    *(undefined1 *)((longlong)piVar10 + 0x1b) = 0xfc;
  }
  uVar4 = ReadIDs(param_1,param_3);
  if ((char)uVar4 == '\0') {
    *(undefined1 *)(param_1 + 0xe86) = 0;
    RemoveDevice(param_1,param_3);
  }
  return;
}



===== ContinueIDReadsForIrElements @ 140006d20 =====

void ContinueIDReadsForIrElements(longlong param_1,int param_2)

{
  undefined8 *puVar1;
  uint *puVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  
  lVar5 = (ulonglong)*(uint *)(param_1 + 0x1594) * 0x188 + *(longlong *)(param_1 + 0x368);
  puVar1 = (undefined8 *)(lVar5 + (ulonglong)*(byte *)(lVar5 + 0x185) * 0x18);
  if (*(short *)(param_1 + 0x1502) == 0) {
    uVar4 = *(undefined8 *)(*(longlong *)(param_1 + 0x15b8) + 0x30);
    *puVar1 = uVar4;
    *(undefined1 *)((longlong)puVar1 + 0x12) = 1;
    uVar3 = GetMapTableIndexFromWWID(param_1,uVar4);
    if ((int)uVar3 != -1) {
      puVar2 = (uint *)(*(longlong *)(param_1 + 0x378) + 0x14 + (uVar3 & 0xffffffff) * 0x28);
      *puVar2 = *puVar2 | 0x10000000;
    }
  }
  else {
    LogSystemEvent(param_1,0xad010041,0xc004af02,
                   (byte *)"Read of SAS Dev Page0 failed (ContinueIDReadsForIrElements)",param_2);
    *puVar1 = 0;
    puVar1[1] = 0;
    *(undefined4 *)(puVar1 + 2) = 0;
  }
  uVar4 = ReadIrIDs(param_1,param_2);
  if ((char)uVar4 == '\0') {
    *(undefined1 *)(param_1 + 0xe87) = 0;
    AddOrRemoveIrVolume(param_1,param_2);
  }
  return;
}



===== ContinueIDReadsForPhyEvents @ 140006df0 =====

void ContinueIDReadsForPhyEvents(longlong param_1,int param_2)

{
  int *piVar1;
  undefined1 *puVar2;
  longlong lVar3;
  byte bVar4;
  uint uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  byte bVar8;
  uint uVar9;
  char *pcVar10;
  ushort uVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  longlong lVar14;
  
  lVar14 = (ulonglong)*(uint *)(param_1 + 0x158c) * 0x3cc + *(longlong *)(param_1 + 0x360);
  puVar13 = (undefined8 *)((ulonglong)*(byte *)(lVar14 + 0x3c7) * 0x20 + lVar14);
  if (*(short *)(param_1 + 0x1502) == 0) {
    puVar2 = *(undefined1 **)(param_1 + 0x15e0);
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x100003) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x100003,puVar2,0x38,
                  param_2);
    }
    *(undefined1 *)(puVar13 + 3) = 1;
    *puVar13 = *(undefined8 *)(puVar2 + 0xc);
    puVar13[1] = *(undefined8 *)(puVar2 + 0xc);
    *(undefined2 *)((longlong)puVar13 + 0x16) = *(undefined2 *)(puVar2 + 8);
    *(undefined4 *)(puVar13 + 2) = *(undefined4 *)(puVar2 + 0x1c);
    if ((*(ushort *)(puVar2 + 0x20) & 0x2000) != 0) {
      *(undefined1 *)((longlong)puVar13 + 0x1b) = 0xfc;
    }
    if ((*(byte *)(param_1 + 0x1568) & 0xe) == 2) {
      lVar3 = *(longlong *)(param_1 + 0x358);
      uVar11 = 0;
      pcVar10 = (char *)(lVar3 + 0x18);
LAB_140006f50:
      if (uVar11 < *(byte *)(param_1 + 0x1574)) {
        if ((*(short *)(pcVar10 + -6) != *(short *)(lVar14 + 0x3c0)) || (*pcVar10 != '\0'))
        goto LAB_140006f6c;
        if (uVar11 != 0xffff) {
          if ((((byte)*(uint *)(puVar13 + 2) & 7) == 1) && ((*(uint *)(puVar13 + 2) & 0x680) != 0))
          {
            piVar1 = (int *)(lVar3 + (ulonglong)uVar11 * 0x24);
            if (*(int *)(lVar3 + 8 + (ulonglong)uVar11 * 0x24) == -1) {
              if (*(short *)(lVar14 + 0x3c2) == 0) {
                uVar5 = *(uint *)(param_1 + 0x1598);
                piVar1[2] = uVar5;
LAB_140006fc9:
                puVar12 = (undefined8 *)(*(longlong *)(param_1 + 0x378) + (ulonglong)uVar5 * 0x28);
                uVar9 = uVar5;
                if (uVar5 < *(ushort *)(piVar1 + 5) + uVar5) {
                  do {
                    *(undefined4 *)((longlong)puVar12 + 0x14) = 0x20000000;
                    uVar9 = uVar9 + 1;
                    *puVar12 = *(undefined8 *)piVar1;
                    *(int *)(puVar12 + 2) = piVar1[3];
                    *(undefined1 *)(puVar12 + 4) = 0;
                    puVar12 = puVar12 + 5;
                  } while (uVar9 < *(ushort *)(piVar1 + 5) + uVar5);
                }
              }
              else {
                uVar7 = FindEnclosureMappingSpace(param_1,piVar1,param_2);
                uVar5 = (uint)uVar7;
                piVar1[2] = uVar5;
                if (uVar5 != 0xffffffff) goto LAB_140006fc9;
                if (*(char *)(param_1 + 0xe8c) == '\0') {
                  *(undefined1 *)(param_1 + 0xe8b) = 1;
                }
                else {
                  LogSystemEvent(param_1,0xad010044,0xc004af02,
                                 (byte *)
                                 "No space available in the mapping table for this enclosure",
                                 param_2);
                }
                *puVar13 = 0;
                bVar4 = 0;
                puVar13[1] = 0;
                puVar13[2] = 0;
                *(undefined4 *)(puVar13 + 3) = 0;
                *(undefined1 *)((longlong)puVar13 + 0x1c) = 0;
                bVar8 = 0;
                if (*(char *)(lVar14 + 0x3c4) != '\0') {
                  do {
                    puVar13 = (undefined8 *)((ulonglong)bVar4 * 0x20 + lVar14);
                    if (*(char *)((longlong)puVar13 + 0x1a) == '\x01') {
                      *puVar13 = 0;
                      puVar13[1] = 0;
                      puVar13[2] = 0;
                      *(undefined4 *)(puVar13 + 3) = 0;
                      *(undefined1 *)((longlong)puVar13 + 0x1c) = 0;
                    }
                    bVar8 = *(byte *)(lVar14 + 0x3c4);
                    bVar4 = bVar4 + 1;
                  } while (bVar4 < bVar8);
                }
                *(byte *)(lVar14 + 0x3c7) = bVar8;
              }
            }
            goto LAB_1400070f8;
          }
          goto LAB_1400070e6;
        }
      }
      LogSystemEvent(param_1,0xad010040,0xc004af02,
                     (byte *)"Enclosure not found (ContinueIDReadsForPhyEvents)",param_2);
LAB_1400070e6:
      *(undefined1 *)((longlong)puVar13 + 0x1c) = 0;
      *(undefined4 *)(puVar13 + 3) = 0;
      puVar13[2] = 0;
      puVar13[1] = 0;
      *puVar13 = 0;
    }
LAB_1400070f8:
    if ((((byte)*(undefined4 *)(puVar2 + 0x1c) & 0x81) == 0x81) &&
       (*(char *)(param_1 + 0xe8d) == '\0')) {
      *(undefined1 *)((longlong)puVar13 + 0x1b) = 0;
      SendSTPIdentifyCommand
                (param_1,*(uint *)(puVar2 + 0x1c),*(undefined2 *)((longlong)puVar13 + 0x14),param_2)
      ;
      return;
    }
  }
  else {
    LogSystemEvent(param_1,0xad010041,0xc004af02,
                   (byte *)"Read of SAS Dev Page0 failed (ContinueIDReadsForPhyEvents)",param_2);
    *puVar13 = 0;
    puVar13[1] = 0;
    puVar13[2] = 0;
    *(undefined4 *)(puVar13 + 3) = 0;
    *(undefined1 *)((longlong)puVar13 + 0x1c) = 0;
  }
  uVar6 = ReadIDs(param_1,param_2);
  if ((char)uVar6 == '\0') {
    *(undefined1 *)(param_1 + 0xe86) = 0;
    RemoveDevice(param_1,param_2);
  }
  return;
LAB_140006f6c:
  uVar11 = uVar11 + 1;
  pcVar10 = pcVar10 + 0x24;
  goto LAB_140006f50;
}



===== FindEnclosureMappingSpace @ 140007140 =====

ulonglong FindEnclosureMappingSpace(longlong param_1,int *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  byte bVar4;
  uint *puVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  undefined8 *puVar9;
  uint uVar10;
  ulonglong uVar11;
  ushort uVar12;
  longlong lVar13;
  
  iVar1 = *(int *)(param_1 + 0x1598);
  uVar8 = *(uint *)(param_1 + 0x678);
  if ((*(byte *)(param_1 + 0x156c) & 3) != 0) {
    uVar8 = *(uint *)(param_1 + 0x678) - (uint)*(byte *)(param_1 + 0x65f);
  }
  uVar6 = (uint)*(ushort *)(param_1 + 0x1566) + iVar1;
  uVar12 = 0;
  if (uVar6 < uVar8) {
    lVar13 = *(longlong *)(param_1 + 0x378);
    uVar10 = uVar6;
    do {
      uVar3 = (ulonglong)uVar10;
      if (((*(int *)(lVar13 + uVar3 * 0x28) == *param_2) &&
          (*(int *)(lVar13 + 4 + uVar3 * 0x28) == param_2[1])) &&
         ((uVar2 = *(uint *)(lVar13 + 0x10 + uVar3 * 0x28), uVar2 == 0 ||
          ((param_2[3] & uVar2) != 0)))) {
        uVar12 = uVar12 + 1;
        if (uVar12 == *(ushort *)(param_2 + 5)) {
          return (ulonglong)((uVar10 - uVar12) + 1);
        }
      }
      else {
        uVar12 = 0;
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < uVar8);
  }
  uVar12 = 0;
  if (uVar6 < uVar8) {
    do {
      if ((*(uint *)(*(longlong *)(param_1 + 0x378) + 0x14 + (ulonglong)uVar6 * 0x28) & 0x20000000)
          == 0) {
        uVar12 = uVar12 + 1;
        if (uVar12 == *(ushort *)(param_2 + 5)) {
          return (ulonglong)((uVar6 - uVar12) + 1);
        }
      }
      else {
        uVar12 = 0;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar8);
  }
  do {
    do {
      uVar12 = GetHighMissingEncTableIndex(param_1);
      if (uVar12 == 0xffff) {
        return 0xffffffff;
      }
      uVar6 = *(uint *)(*(longlong *)(param_1 + 0x358) + 8 + (ulonglong)uVar12 * 0x24);
      uVar3 = (ulonglong)uVar6;
      lVar13 = *(longlong *)(param_1 + 0x358) + (ulonglong)uVar12 * 0x24;
      *(undefined1 *)(lVar13 + 0x1a) = 1;
      if (uVar6 < *(ushort *)(lVar13 + 0x14) + uVar6) {
        puVar5 = (uint *)(*(longlong *)(param_1 + 0x378) + uVar3 * 0x28 + 0x14);
        do {
          *puVar5 = *puVar5 & 0xdfffffff;
          puVar5 = puVar5 + 10;
          uVar6 = (int)uVar3 + 1;
          uVar3 = (ulonglong)uVar6;
        } while (uVar6 < (uint)*(ushort *)(lVar13 + 0x14) + *(int *)(lVar13 + 8));
      }
      uVar6 = (uint)*(ushort *)(param_1 + 0x1566) + iVar1;
      uVar12 = 0;
    } while (uVar8 <= uVar6);
    do {
      if ((*(uint *)(*(longlong *)(param_1 + 0x378) + 0x14 + (ulonglong)uVar6 * 0x28) & 0x20000000)
          == 0) {
        uVar12 = uVar12 + 1;
        if (uVar12 == *(ushort *)(param_2 + 5)) {
          uVar8 = (uVar6 - uVar12) + 1;
          uVar3 = (ulonglong)uVar8;
          uVar6 = uVar12 + uVar8;
          if (uVar8 < uVar6) {
            lVar13 = uVar3 * 0x28;
            do {
              uVar12 = 0;
              bVar4 = 0;
              if (*(char *)(param_1 + 0x1574) != '\0') {
                pcVar7 = (char *)(*(longlong *)(param_1 + 0x358) + 0x19);
                do {
                  if ((*(uint *)(pcVar7 + -0x11) <= uVar8) &&
                     (uVar8 < (uint)*(ushort *)(pcVar7 + -5) + *(uint *)(pcVar7 + -0x11))) {
                    if (*pcVar7 == '\0') {
                      *pcVar7 = '\x01';
                      AddToRemovalTable(param_1,0,*(short *)(pcVar7 + -9),param_3);
                    }
                    puVar9 = (undefined8 *)(*(longlong *)(param_1 + 0x378) + lVar13);
                    if ((*(uint *)((longlong)puVar9 + 0x14) & 0x10000000) != 0) {
                      AddToRemovalTable(param_1,*(short *)((longlong)puVar9 + 0x1a),0,param_3);
                      puVar9[3] = 0xffff;
                      *puVar9 = 0;
                      puVar9[1] = 0;
                      puVar9[2] = 0;
                      *(undefined2 *)(puVar9 + 4) = 0;
                      *(undefined1 *)((longlong)puVar9 + 0x22) = *(undefined1 *)(param_1 + 0x65e);
                      *(undefined2 *)((longlong)puVar9 + 0x23) = 0;
                      *(undefined1 *)((longlong)puVar9 + 0x27) = 0;
                    }
                  }
                  bVar4 = *(byte *)(param_1 + 0x1574);
                  uVar12 = uVar12 + 1;
                  pcVar7 = pcVar7 + 0x24;
                } while (uVar12 < bVar4);
              }
              uVar8 = uVar8 + 1;
              lVar13 = lVar13 + 0x28;
            } while (uVar8 < uVar6);
          }
          else {
            bVar4 = *(byte *)(param_1 + 0x1574);
          }
          puVar9 = *(undefined8 **)(param_1 + 0x358);
          uVar12 = 0;
          if (bVar4 != 0) {
            do {
              if (*(char *)((longlong)puVar9 + 0x19) == '\0') {
                uVar8 = *(uint *)(puVar9 + 1);
                uVar11 = (ulonglong)uVar8;
                if (uVar8 < *(ushort *)((longlong)puVar9 + 0x14) + uVar8) {
                  puVar5 = (uint *)(*(longlong *)(param_1 + 0x378) + uVar11 * 0x28 + 0x14);
                  do {
                    *puVar5 = *puVar5 | 0x20000000;
                    puVar5 = puVar5 + 10;
                    uVar8 = (int)uVar11 + 1;
                    uVar11 = (ulonglong)uVar8;
                  } while (uVar8 < (uint)*(ushort *)((longlong)puVar9 + 0x14) + *(int *)(puVar9 + 1)
                          );
                }
              }
              else {
                *puVar9 = 0;
                *(undefined4 *)(puVar9 + 1) = 0xffffffff;
                *(undefined4 *)((longlong)puVar9 + 0xc) = 0;
                puVar9[2] = 0xffff;
                *(undefined2 *)(puVar9 + 3) = 0;
                *(undefined2 *)((longlong)puVar9 + 0x1b) = 0;
                *(undefined2 *)((longlong)puVar9 + 0x1e) = 0;
                *(undefined1 *)(puVar9 + 4) = 0;
              }
              *(undefined1 *)((longlong)puVar9 + 0x1a) = 0;
              uVar12 = uVar12 + 1;
              puVar9 = (undefined8 *)((longlong)puVar9 + 0x24);
            } while (uVar12 < *(byte *)(param_1 + 0x1574));
          }
          return uVar3;
        }
      }
      else {
        uVar12 = 0;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar8);
  } while( true );
}



===== FlushAllDPMPage0 @ 140007500 =====

void FlushAllDPMPage0(longlong param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  uVar3 = 0;
  if ((*(byte *)(param_1 + 0x1568) & 1) == 0) {
    uVar2 = 0;
    if (*(ushort *)(param_1 + 0x1564) != 0) {
      do {
        uVar4 = (ulonglong)uVar2;
        if (*(char *)(uVar4 + *(longlong *)(param_1 + 0x1580)) != '\0') {
          lVar1 = *(longlong *)(param_1 + 0x15c8);
          *(undefined4 *)(lVar1 + 0x18 + uVar4 * 0x14) = 0;
          ZeroMemory(*(undefined1 **)(param_1 + 0x15d0),8);
          memmove((void *)(*(longlong *)(param_1 + 0x15d0) + 8),(void *)(lVar1 + uVar4 * 0x14 + 8),
                  0x14);
          *(undefined1 *)(param_1 + 0xe82) = 1;
          SendExtendedConfigPageMessage
                    (param_1,'\x04',(char *)(param_1 + 0x15c0),uVar2 | 0x10000,
                     (int)*(undefined8 *)(param_1 + 0x15d0),param_2);
          *(undefined1 *)(uVar4 + *(longlong *)(param_1 + 0x1580)) = 0;
          break;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(ushort *)(param_1 + 0x1564));
    }
  }
  do {
    if (*(char *)(param_1 + 0xe82) == '\0') {
      return;
    }
    PollLSImpiIsr(param_1,param_2);
    StorPortStallExecution(1000);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 60000);
  return;
}



===== FlushDPMPage0Entry @ 140007620 =====

void FlushDPMPage0Entry(longlong param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  
  if ((*(byte *)(param_1 + 0x1568) & 1) == 0) {
    uVar3 = 0;
    if (*(ushort *)(param_1 + 0x1564) != 0) {
      do {
        if (*(char *)(uVar3 + *(longlong *)(param_1 + 0x1580)) != '\0') {
          lVar1 = *(longlong *)(param_1 + 0x15c8);
          *(undefined4 *)(lVar1 + 0x18 + uVar3 * 0x14) = 0;
          ZeroMemory(*(undefined1 **)(param_1 + 0x15d0),8);
          memmove((void *)(*(longlong *)(param_1 + 0x15d0) + 8),(void *)(lVar1 + uVar3 * 0x14 + 8),
                  0x14);
          *(undefined1 *)(param_1 + 0xe82) = 1;
          SendExtendedConfigPageMessage
                    (param_1,'\x04',(char *)(param_1 + 0x15c0),(uint)uVar3 | 0x10000,
                     (int)*(undefined8 *)(param_1 + 0x15d0),param_2);
          *(undefined1 *)(uVar3 + *(longlong *)(param_1 + 0x1580)) = 0;
          return;
        }
        uVar2 = (uint)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < *(ushort *)(param_1 + 0x1564));
    }
  }
  return;
}



===== GetBusTargetFromDevHandle @ 140007710 =====

ulonglong GetBusTargetFromDevHandle
                    (longlong param_1,short param_2,undefined2 *param_3,undefined2 *param_4)

{
  ulonglong uVar1;
  ushort uVar2;
  
  uVar2 = 0;
  uVar1 = *(ulonglong *)(param_1 + 0x378);
  if (*(uint *)(param_1 + 0x678) != 0) {
    do {
      if (*(short *)(uVar1 + 0x1a) == param_2) {
        *param_3 = *(undefined2 *)(uVar1 + 0x1c);
        *param_4 = *(undefined2 *)(uVar1 + 0x1e);
        return CONCAT71((int7)(uVar1 >> 8),1);
      }
      uVar2 = uVar2 + 1;
      uVar1 = uVar1 + 0x28;
    } while ((uint)uVar2 < *(uint *)(param_1 + 0x678));
  }
  return uVar1 & 0xffffffffffffff00;
}



===== GetDPMPage0IndexFromID @ 140007760 =====

ushort GetDPMPage0IndexFromID(longlong param_1,undefined8 param_2,uint param_3)

{
  int *piVar1;
  ushort uVar2;
  int iStackX_14;
  
  uVar2 = 0;
  piVar1 = (int *)(*(longlong *)(param_1 + 0x15c8) + 8);
  if (*(ushort *)(param_1 + 0x1564) != 0) {
    iStackX_14 = (int)((ulonglong)param_2 >> 0x20);
    do {
      if ((((*(char *)((ulonglong)uVar2 + *(longlong *)(param_1 + 0x1578)) != '\0') &&
           (*piVar1 == (int)param_2)) && (piVar1[1] == iStackX_14)) &&
         (((param_3 == 0 || (piVar1[3] == 0)) || ((param_3 & piVar1[3]) != 0)))) {
        return uVar2;
      }
      uVar2 = uVar2 + 1;
      piVar1 = piVar1 + 5;
    } while (uVar2 < *(ushort *)(param_1 + 0x1564));
  }
  return 0xffff;
}



===== GetFirstFreeDPMPage0 @ 1400077e0 =====

ulonglong GetFirstFreeDPMPage0(longlong param_1)

{
  bool bVar1;
  bool bVar2;
  ulonglong uVar3;
  
  uVar3 = 0;
  bVar2 = false;
  do {
    if (*(ushort *)(param_1 + 0x1564) <= (ushort)uVar3) {
      if (!bVar2) {
        uVar3 = 0xffff;
      }
      return uVar3;
    }
    bVar1 = true;
    if (*(char *)(uVar3 + *(longlong *)(param_1 + 0x1578)) != '\0') {
      uVar3 = (ulonglong)(ushort)((ushort)uVar3 + 1);
      bVar1 = bVar2;
    }
    bVar2 = bVar1;
  } while (!bVar1);
  return uVar3;
}



===== GetFirstFreeIrMapTableIndex @ 140007840 =====

ulonglong GetFirstFreeIrMapTableIndex(longlong param_1)

{
  longlong lVar1;
  byte bVar2;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  ulonglong uVar8;
  uint *puVar9;
  byte *pbVar10;
  byte bVar11;
  uint uVar12;
  
  bVar11 = 0;
  uVar3 = 0xffffffff;
  if ((*(byte *)(param_1 + 0x156c) & 3) == 0) {
    bVar2 = *(byte *)(param_1 + 0x65f);
    uVar6 = *(ushort *)(param_1 + 0x1568) >> 4 & 1;
  }
  else {
    bVar2 = *(byte *)(param_1 + 0x65f);
    uVar6 = (uint)*(ushort *)(param_1 + 0x658) - (uint)bVar2;
  }
  uVar8 = (ulonglong)uVar6;
  uVar12 = (bVar2 - 1) + uVar6;
  lVar1 = *(longlong *)(param_1 + 0x378) + uVar8 * 0x28;
  if (uVar6 <= uVar12) {
    puVar9 = (uint *)(lVar1 + 0x14);
    uVar4 = uVar8;
    do {
      if ((*puVar9 & 0x10000000) == 0) {
        return uVar4;
      }
      uVar5 = (int)uVar4 + 1;
      uVar4 = (ulonglong)uVar5;
      puVar9 = puVar9 + 10;
    } while (uVar5 <= uVar12);
    if (uVar6 <= uVar12) {
      pbVar10 = (byte *)(lVar1 + 0x20);
      do {
        uVar4 = uVar8;
        iVar7 = (int)uVar4;
        bVar2 = *pbVar10;
        pbVar10 = pbVar10 + 0x28;
        if (bVar2 <= bVar11) {
          uVar4 = (ulonglong)uVar3;
        }
        uVar6 = iVar7 + 1;
        uVar3 = (uint)uVar4;
        if (bVar2 <= bVar11) {
          bVar2 = bVar11;
        }
        bVar11 = bVar2;
        uVar8 = (ulonglong)uVar6;
      } while (uVar6 <= uVar12);
      if (uVar3 != 0xffffffff) {
        return uVar4;
      }
    }
  }
  return 0xffffffff;
}



===== GetHighMissingEncTableIndex @ 140007910 =====

ushort GetHighMissingEncTableIndex(longlong param_1)

{
  char *pcVar1;
  ushort uVar2;
  byte bVar3;
  ushort uVar4;
  
  bVar3 = 0;
  uVar2 = 0;
  uVar4 = 0xffff;
  if (*(byte *)(param_1 + 0x1574) != 0) {
    pcVar1 = (char *)(*(longlong *)(param_1 + 0x358) + 0x1a);
    do {
      if ((bVar3 < (byte)pcVar1[-2]) && (*pcVar1 == '\0')) {
        bVar3 = pcVar1[-2];
        uVar4 = uVar2;
      }
      uVar2 = uVar2 + 1;
      pcVar1 = pcVar1 + 0x24;
    } while (uVar2 < *(byte *)(param_1 + 0x1574));
  }
  return uVar4;
}



===== GetHighMissingMapTableIndex @ 140007960 =====

int GetHighMissingMapTableIndex(longlong param_1)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  byte bVar8;
  int iVar9;
  
  bVar8 = 0;
  uVar6 = *(uint *)(param_1 + 0x678);
  iVar4 = -1;
  uVar5 = *(ushort *)(param_1 + 0x1568) >> 4 & 1;
  uVar7 = (ulonglong)uVar5;
  uVar2 = uVar6;
  if ((*(uint *)(param_1 + 0xeb4) & 0x1000) != 0) {
    if ((*(byte *)(param_1 + 0x156c) & 3) == 0) {
      uVar7 = (ulonglong)(*(byte *)(param_1 + 0x65f) + uVar5);
    }
    else {
      uVar2 = (uint)*(ushort *)(param_1 + 0x658) - (uint)*(byte *)(param_1 + 0x65f);
      if (uVar5 == uVar2) {
        uVar7 = (ulonglong)(*(byte *)(param_1 + 0x65f) + uVar2);
        uVar2 = uVar6;
      }
    }
  }
  if ((uint)uVar7 < uVar2) {
    pbVar3 = (byte *)(*(longlong *)(param_1 + 0x378) + uVar7 * 0x28 + 0x20);
    iVar9 = -1;
    do {
      bVar1 = *pbVar3;
      pbVar3 = pbVar3 + 0x28;
      iVar4 = (int)uVar7;
      if (bVar1 <= bVar8) {
        iVar4 = iVar9;
      }
      uVar6 = (int)uVar7 + 1;
      uVar7 = (ulonglong)uVar6;
      if (bVar1 <= bVar8) {
        bVar1 = bVar8;
      }
      bVar8 = bVar1;
      iVar9 = iVar4;
    } while (uVar6 < uVar2);
  }
  return iVar4;
}



===== GetIrMapRange @ 140007a20 =====

void GetIrMapRange(longlong param_1,int *param_2,uint *param_3)

{
  int iVar1;
  
  if ((*(byte *)(param_1 + 0x156c) & 3) == 0) {
    iVar1 = 0;
    *param_2 = 0;
    if ((*(byte *)(param_1 + 0x1568) & 0x10) != 0) {
      *param_2 = 1;
      *param_3 = (uint)*(byte *)(param_1 + 0x65f);
      return;
    }
  }
  else {
    iVar1 = (uint)*(ushort *)(param_1 + 0x658) - (uint)*(byte *)(param_1 + 0x65f);
    *param_2 = iVar1;
  }
  *param_3 = (*(byte *)(param_1 + 0x65f) - 1) + iVar1;
  return;
}



===== GetMapTableIndexFromHandle @ 140007a80 =====

uint GetMapTableIndexFromHandle(longlong param_1,short param_2)

{
  bool bVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  bool bVar5;
  
  bVar1 = false;
  uVar2 = 0;
  lVar3 = *(longlong *)(param_1 + 0x378);
  do {
    if (*(uint *)(param_1 + 0x678) <= uVar2) {
      if (!bVar1) {
        uVar2 = 0xffffffff;
      }
      return uVar2;
    }
    bVar5 = *(short *)(lVar3 + 0x1a) != param_2;
    if (bVar5) {
      uVar2 = uVar2 + 1;
    }
    lVar4 = lVar3 + 0x28;
    if (!bVar5) {
      lVar4 = lVar3;
      bVar1 = true;
    }
    lVar3 = lVar4;
  } while (!bVar1);
  return uVar2;
}



===== GetMapTableIndexFromWWID @ 140007ae0 =====

ulonglong GetMapTableIndexFromWWID(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  ulonglong uVar2;
  byte bVar3;
  int *piVar4;
  uint uVar5;
  int iStackX_14;
  
  if ((*(byte *)(param_1 + 0x156c) & 3) == 0) {
    bVar3 = *(byte *)(param_1 + 0x65f);
    uVar1 = *(ushort *)(param_1 + 0x1568) >> 4 & 1;
  }
  else {
    bVar3 = *(byte *)(param_1 + 0x65f);
    uVar1 = (uint)*(ushort *)(param_1 + 0x658) - (uint)bVar3;
  }
  uVar2 = (ulonglong)uVar1;
  uVar5 = (bVar3 - 1) + uVar1;
  piVar4 = (int *)(*(longlong *)(param_1 + 0x378) + uVar2 * 0x28);
  if (uVar1 <= uVar5) {
    iStackX_14 = (int)((ulonglong)param_2 >> 0x20);
    do {
      if ((*piVar4 == (int)param_2) && (piVar4[1] == iStackX_14)) {
        return uVar2;
      }
      uVar1 = (int)uVar2 + 1;
      uVar2 = (ulonglong)uVar1;
      piVar4 = piVar4 + 10;
    } while (uVar1 <= uVar5);
  }
  return 0xffffffff;
}



===== MapSODChecks @ 140007b60 =====

void MapSODChecks(longlong param_1,int param_2)

{
  longlong lVar1;
  longlong lVar2;
  short sVar3;
  char cVar4;
  byte bVar5;
  ushort uVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  
  uVar6 = *(ushort *)(param_1 + 0x1568) & 0xe;
  if (uVar6 == 2) {
    puVar7 = *(undefined4 **)(param_1 + 0x358);
    uVar9 = 0;
    if (*(char *)(param_1 + 0x1574) != '\0') {
      do {
        if (*(char *)((longlong)puVar7 + 0x1b) == '\0') {
          if (((*(byte *)(puVar7 + 6) < 0xf) &&
              (*(byte *)(puVar7 + 6) = *(byte *)(puVar7 + 6) + 1,
              (*(byte *)(param_1 + 0x1568) & 1) == 0)) && (*(short *)(puVar7 + 4) != -1)) {
            if ((*(char *)(param_1 + 0xb328) == '\0') &&
               (cVar4 = IsHbaFwDowngradeInProgress(param_1), cVar4 == '\0')) {
              lVar1 = *(longlong *)(param_1 + 0x15c8) + (ulonglong)*(ushort *)(puVar7 + 4) * 0x14;
              *(undefined4 *)(lVar1 + 8) = *puVar7;
              *(undefined4 *)(lVar1 + 0xc) = puVar7[1];
              lVar2 = *(longlong *)(param_1 + 0x378) + (ulonglong)(uint)puVar7[2] * 0x28;
              sVar3 = *(short *)(lVar2 + 0x1c) * 0x80;
              *(short *)(lVar1 + 0x12) = sVar3;
              *(short *)(lVar1 + 0x12) = *(short *)(lVar2 + 0x1e) + sVar3;
              sVar3 = *(short *)(puVar7 + 5);
              *(short *)(lVar1 + 0x10) = sVar3 << 4;
              *(ushort *)(lVar1 + 0x10) = (ushort)*(byte *)(puVar7 + 6) | sVar3 << 4;
              *(undefined4 *)(lVar1 + 0x14) = puVar7[3];
              *(undefined4 *)(lVar1 + 0x18) = 0;
              ZeroMemory(*(undefined1 **)(param_1 + 0x15d0),8);
              memmove((void *)(*(longlong *)(param_1 + 0x15d0) + 8),(void *)(lVar1 + 8),0x14);
              uVar6 = *(ushort *)(puVar7 + 4);
              *(undefined1 *)(param_1 + 0x676) = 1;
              *(undefined1 *)(param_1 + 0xe88) = 1;
              SendExtendedConfigPageMessage
                        (param_1,'\x04',(char *)(param_1 + 0x15c0),uVar6 | 0x10000,
                         (int)*(undefined8 *)(param_1 + 0x15d0),param_2);
              uVar8 = 0;
              do {
                PollLSImpiIsr(param_1,param_2);
                if (*(char *)(param_1 + 0xe88) == '\0') goto LAB_140007d4f;
                StorPortStallExecution(500);
                uVar8 = uVar8 + 1;
              } while (uVar8 < 120000);
              if (*(char *)(param_1 + 0xe88) != '\0') {
                LogSystemEvent(param_1,0xad01004b,0xc004af02,
                               (byte *)"Start-of-Day Check Failed (MapSODChecks)",param_2);
              }
            }
            else {
              *(undefined1 *)(puVar7 + 7) = 1;
              *(int *)(param_1 + 0xb334) = *(int *)(param_1 + 0xb334) + 1;
            }
          }
LAB_140007d4f:
          *(undefined1 *)((longlong)puVar7 + 0x1b) = 1;
        }
        uVar9 = uVar9 + 1;
        puVar7 = puVar7 + 9;
      } while (uVar9 < *(byte *)(param_1 + 0x1574));
    }
    if ((*(uint *)(param_1 + 0xeb4) >> 0xc & 1) != 0) {
      if ((*(byte *)(param_1 + 0x156c) & 3) == 0) {
        bVar5 = *(byte *)(param_1 + 0x65f);
        uVar9 = *(ushort *)(param_1 + 0x1568) >> 4 & 1;
      }
      else {
        bVar5 = *(byte *)(param_1 + 0x65f);
        uVar9 = (uint)*(ushort *)(param_1 + 0x658) - (uint)bVar5;
      }
      SODCheckMapEntry(param_1,*(longlong *)(param_1 + 0x378) + (ulonglong)uVar9 * 0x28,uVar9,
                       bVar5 + uVar9,param_2);
      return;
    }
  }
  else if (uVar6 == 0) {
    SODCheckMapEntry(param_1,*(longlong *)(param_1 + 0x378),0,*(uint *)(param_1 + 0x678),param_2);
  }
  return;
}



===== ProcessDPMPage0 @ 140007e20 =====

void ProcessDPMPage0(longlong param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  int *piVar6;
  short sVar7;
  ulonglong uVar8;
  uint uVar9;
  char *pcVar10;
  byte bVar11;
  ushort uVar12;
  uint uVar13;
  uint uVar14;
  uint local_res8;
  
  if ((*(ushort *)(param_1 + 0x1568) & 1) == 0) {
    uVar14 = *(uint *)(param_1 + 0xeb4) >> 0xc;
    if ((uVar14 & 1) == 0) {
      uVar13 = local_res8;
    }
    else {
      bVar11 = *(byte *)(param_1 + 0x65f);
      if ((*(byte *)(param_1 + 0x156c) & 3) == 0) {
        local_res8 = *(ushort *)(param_1 + 0x1568) >> 4 & 1;
        uVar13 = (bVar11 - 1) + local_res8;
      }
      else {
        local_res8 = (uint)*(ushort *)(param_1 + 0x658) - (uint)bVar11;
        uVar13 = (bVar11 - 1) + local_res8;
      }
    }
    piVar6 = (int *)(*(longlong *)(param_1 + 0x15c8) + 8);
    uVar8 = 0;
    if (*(short *)(param_1 + 0x1564) != 0) {
      do {
        sVar7 = (short)uVar8;
        if ((*piVar6 == 0) && (piVar6[1] == 0)) {
          *(undefined1 *)(uVar8 + *(longlong *)(param_1 + 0x1578)) = 0;
        }
        else {
          *(undefined1 *)(uVar8 + *(longlong *)(param_1 + 0x1578)) = 1;
          uVar12 = *(ushort *)((longlong)piVar6 + 10);
          uVar8 = (ulonglong)uVar12;
          bVar11 = *(byte *)(piVar6 + 2) & 0xf;
          uVar9 = (uint)uVar12;
          if (((uVar14 & 1) == 0) ||
             ((uVar12 < local_res8 || (uVar13 <= uVar12 && uVar9 != uVar13)))) {
            uVar2 = *(ushort *)(param_1 + 0x1568) & 0xe;
            if (uVar2 == 2) {
              uVar12 = *(ushort *)(param_1 + 0x1566);
              if (uVar9 < (uint)uVar12 + *(int *)(param_1 + 0x1598)) {
                uVar2 = *(ushort *)(param_1 + 0x1568) >> 5 & 1;
              }
              else {
                uVar2 = 0;
                uVar12 = *(ushort *)(piVar6 + 2) >> 4 & 0x7f;
              }
              bVar1 = *(byte *)(param_1 + 0x1574);
              if (*(ushort *)(param_1 + 0x65a) <= (ushort)bVar1) {
                pcVar10 = "Enclosure Table Full (ProcessDPMPage0)";
                uVar4 = 0xad010046;
LAB_1400080d1:
                LogSystemEvent(param_1,uVar4,0xc004af02,(byte *)pcVar10,param_2);
                return;
              }
              *(byte *)(param_1 + 0x1574) = bVar1 + 1;
              puVar5 = (undefined8 *)(*(longlong *)(param_1 + 0x358) + (ulonglong)bVar1 * 0x24);
              *puVar5 = *(undefined8 *)piVar6;
              *(uint *)(puVar5 + 1) = uVar9;
              *(int *)((longlong)puVar5 + 0xc) = piVar6[3];
              *(short *)(puVar5 + 2) = sVar7;
              *(ushort *)((longlong)puVar5 + 0x14) = uVar12;
              *(ushort *)((longlong)puVar5 + 0x16) = uVar2;
              *(byte *)(puVar5 + 3) = bVar11;
              *(undefined2 *)((longlong)puVar5 + 0x19) = 0;
              *(undefined1 *)((longlong)puVar5 + 0x1b) = 0;
              uVar3 = uVar12 + uVar9;
              puVar5 = (undefined8 *)(*(longlong *)(param_1 + 0x378) + uVar8 * 0x28);
              while (uVar9 < uVar3) {
                if (*(short *)(puVar5 + 3) != -1) {
                  LogSystemEvent(param_1,0xad010042,0xc004af02,
                                 (byte *)
                                 "encl-slot mapping of a new device conflicts with an existing entry"
                                 ,param_2);
                  break;
                }
                *puVar5 = *(undefined8 *)piVar6;
                *(int *)(puVar5 + 2) = piVar6[3];
                *(short *)((longlong)puVar5 + 0x1c) = (short)((uint)uVar8 >> 7);
                *(short *)(puVar5 + 3) = sVar7;
                *(ushort *)((longlong)puVar5 + 0x1e) = (ushort)uVar8 & 0x7f;
                uVar9 = (uint)uVar8 + 1;
                uVar8 = (ulonglong)uVar9;
                *(byte *)(puVar5 + 4) = bVar11;
                *(undefined4 *)((longlong)puVar5 + 0x14) = 0x20000000;
                puVar5 = puVar5 + 5;
              }
            }
            else if (uVar2 == 0) {
              puVar5 = (undefined8 *)(*(longlong *)(param_1 + 0x378) + uVar8 * 0x28);
              if (*(short *)(*(longlong *)(param_1 + 0x378) + 0x18 + uVar8 * 0x28) != -1) {
                pcVar10 = "addr mapping of a new device conflicts with an existing entry";
                uVar4 = 0xad010042;
                goto LAB_1400080d1;
              }
              goto LAB_140008076;
            }
          }
          else {
            puVar5 = (undefined8 *)(*(longlong *)(param_1 + 0x378) + uVar8 * 0x28);
LAB_140008076:
            *puVar5 = *(undefined8 *)piVar6;
            *(undefined4 *)((longlong)puVar5 + 0x14) = 0x20000000;
            *(byte *)(puVar5 + 4) = bVar11;
            *(short *)(puVar5 + 3) = sVar7;
            *(ushort *)((longlong)puVar5 + 0x1e) = uVar12 & 0x7f;
            *(ushort *)((longlong)puVar5 + 0x1c) = uVar12 >> 7;
          }
        }
        uVar8 = (ulonglong)(ushort)(sVar7 + 1U);
        piVar6 = piVar6 + 5;
      } while ((ushort)(sVar7 + 1U) < *(ushort *)(param_1 + 0x1564));
    }
  }
  return;
}



===== ProcessIRConfigChangeList @ 140008110 =====

void ProcessIRConfigChangeList(longlong param_1,ushort *param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  ushort *puVar5;
  undefined4 uVar6;
  ushort *puVar7;
  ulonglong uVar8;
  char *pcVar9;
  ushort uVar10;
  
  *(undefined4 *)(param_1 + 0xe90) = 0x1e;
  bVar1 = (byte)param_2[0xe];
  uVar8 = (ulonglong)bVar1;
  uVar10 = (bVar1 + 1) * 8;
  if ((((ushort)(uVar10 + 0x1c) == (ushort)((ushort)(byte)param_2[1] << 2)) &&
      ((uint)uVar10 == (uint)*param_2 << 2)) && (bVar1 != 0)) {
    if ((*(uint *)(param_2 + 0x10) & 1) != 0) {
      return;
    }
    uVar2 = *(uint *)(param_1 + 0x1590);
    lVar4 = (ulonglong)uVar2 * 0x188 + *(longlong *)(param_1 + 0x368);
    if (*(char *)(lVar4 + 0x184) == '\0') {
      *(byte *)(lVar4 + 0x184) = bVar1;
      *(undefined4 *)(lVar4 + 0x180) = *(undefined4 *)(param_2 + 0x10);
      *(undefined1 *)(lVar4 + 0x185) = 0;
      if (bVar1 != 0) {
        puVar5 = (ushort *)(lVar4 + 0xe);
        puVar7 = param_2 + 0x12;
        do {
          puVar5[-1] = *puVar7;
          *puVar5 = puVar7[1];
          *(char *)((longlong)puVar5 + 5) = (char)puVar7[2];
          puVar5[1] = puVar7[3];
          *(undefined1 *)(puVar5 + 3) = *(undefined1 *)((longlong)puVar7 + 5);
          uVar8 = uVar8 - 1;
          puVar5 = puVar5 + 0xc;
          puVar7 = puVar7 + 4;
        } while (uVar8 != 0);
      }
      iVar3 = 0;
      if (uVar2 != 9) {
        iVar3 = uVar2 + 1;
      }
      *(int *)(param_1 + 0x1590) = iVar3;
      if (*(char *)(param_1 + 0xe85) != '\0') {
        return;
      }
      if (*(char *)(param_1 + 0xe84) != '\0') {
        return;
      }
      if ((*(int *)(param_1 + 0x630) == 0) && (*(int *)(param_1 + 0xec0) == 0)) {
        StorPortPause(param_1,300);
        ResetActive(param_1,6,param_3);
      }
      *(undefined1 *)(param_1 + 0xe85) = 1;
      StartIDReadsForIrElements(param_1,param_3);
      return;
    }
    pcVar9 = "Event List Full (IRConfigChangeList)";
    uVar6 = 0xad010043;
  }
  else {
    pcVar9 = "Wrong Event Data Length (IRConfigChangeList)";
    uVar6 = 0xad01003d;
  }
  LogSystemEvent(param_1,uVar6,0xc004af02,(byte *)pcVar9,param_3);
  return;
}



===== ProcessSasEnclosureStatusChange @ 1400082a0 =====

void ProcessSasEnclosureStatusChange(longlong param_1,longlong param_2,int param_3)

{
  longlong lVar1;
  longlong lVar2;
  byte bVar3;
  int *piVar4;
  char cVar5;
  int *piVar6;
  ushort uVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 uVar10;
  char *pcVar11;
  undefined8 *puVar12;
  uint uVar13;
  ulonglong uVar14;
  int iStackX_c;
  
  *(undefined4 *)(param_1 + 0xe90) = 0x1e;
  if ((*(byte *)(param_1 + 0x1568) & 0xe) == 2) {
    if (*(char *)(param_2 + 0x1e) == '\x01') {
      if (*(short *)(param_2 + 0x28) == 0) {
        LogSystemEvent(param_1,0xad010052,0x8004af01,
                       (byte *)"An enclosure was not attached that had 0 number of slots",param_3);
      }
      else {
        uVar7 = 0;
        piVar4 = *(int **)(param_1 + 0x358);
        if (*(byte *)(param_1 + 0x1574) != 0) {
          iStackX_c = (int)((ulonglong)*(undefined8 *)(param_2 + 0x20) >> 0x20);
          piVar6 = piVar4;
LAB_140008341:
          if (((*piVar6 != (int)*(undefined8 *)(param_2 + 0x20)) || (piVar6[1] != iStackX_c)) ||
             ((piVar6[3] != 0 && ((*(uint *)(param_2 + 0x2c) & piVar6[3]) == 0))))
          goto LAB_14000835a;
          if (uVar7 != 0xffff) {
            piVar6 = piVar4 + (ulonglong)uVar7 * 9;
            if ((*(char *)((longlong)piVar4 + (ulonglong)uVar7 * 0x24 + 0x1b) != '\0') &&
               ((char)piVar6[6] == '\0')) {
              pcVar11 = "Received an add enclosure event for an enclosure that is already active";
              uVar8 = 0xad01004c;
              uVar10 = 0x8004af01;
              goto LAB_140008392;
            }
            *(undefined2 *)((longlong)piVar6 + 0x12) = *(undefined2 *)(param_2 + 0x1c);
            *(undefined2 *)((longlong)piVar6 + 0x16) = *(undefined2 *)(param_2 + 0x2a);
            uVar7 = *(ushort *)(param_2 + 0x28);
            if (*(ushort *)(piVar6 + 5) < uVar7) {
              AddToRemovalTable(param_1,0,(short)piVar6[4],param_3);
              uVar13 = piVar6[2];
              uVar14 = (ulonglong)uVar13;
              puVar12 = (undefined8 *)(*(longlong *)(param_1 + 0x378) + uVar14 * 0x28);
              if (uVar13 < *(ushort *)(piVar6 + 5) + uVar13) {
                do {
                  if (*(short *)((longlong)puVar12 + 0x1a) != 0) {
                    AddToRemovalTable(param_1,*(short *)((longlong)puVar12 + 0x1a),0,param_3);
                    *puVar12 = 0;
                    puVar12[1] = 0;
                    puVar12[2] = 0;
                    puVar12[3] = 0xffff;
                    *(undefined2 *)(puVar12 + 4) = 0;
                    *(undefined1 *)((longlong)puVar12 + 0x22) = *(undefined1 *)(param_1 + 0x65e);
                    *(undefined2 *)((longlong)puVar12 + 0x23) = 0;
                    *(undefined1 *)((longlong)puVar12 + 0x27) = 0;
                  }
                  uVar13 = (int)uVar14 + 1;
                  uVar14 = (ulonglong)uVar13;
                  puVar12 = puVar12 + 5;
                } while (uVar13 < (uint)*(ushort *)(piVar6 + 5) + piVar6[2]);
              }
              piVar6[0] = 0;
              piVar6[1] = 0;
              piVar6[2] = -1;
              piVar6[3] = 0;
              piVar6[4] = 0xffff;
              piVar6[5] = 0;
              piVar6[6] = 0;
              *(undefined1 *)(piVar6 + 7) = 0;
              *(undefined2 *)((longlong)piVar6 + 0x1e) = 0;
              *(undefined1 *)(piVar6 + 8) = 0;
              goto LAB_140008367;
            }
            if (((uVar7 < *(ushort *)(piVar6 + 5)) && ((*(byte *)(param_1 + 0x1568) & 1) == 0)) &&
               (*(ushort *)(piVar6 + 4) != 0xffff)) {
              *(ushort *)
               (*(longlong *)(param_1 + 0x15c8) + 0x10 + (ulonglong)*(ushort *)(piVar6 + 4) * 0x14)
                   = uVar7 << 4;
              *(undefined1 *)((ulonglong)*(ushort *)(piVar6 + 4) + *(longlong *)(param_1 + 0x1580))
                   = 1;
            }
            uVar13 = piVar6[3];
            uVar9 = uVar13 | *(uint *)(param_2 + 0x2c);
            piVar6[3] = uVar9;
            if (((((char)piVar6[6] != '\0') || (uVar13 != uVar9)) &&
                ((*(undefined1 *)(piVar6 + 6) = 0, (*(byte *)(param_1 + 0x1568) & 1) == 0 &&
                 ((*(ushort *)(piVar6 + 4) != 0xffff &&
                  (lVar1 = *(longlong *)(param_1 + 0x15c8) +
                           (ulonglong)*(ushort *)(piVar6 + 4) * 0x14,
                  *(char *)((longlong)piVar6 + 0x1b) == '\0')))))) &&
               (((*(byte *)(lVar1 + 0x10) & 0xf) != 0 || (uVar13 != uVar9)))) {
              *(short *)(lVar1 + 0x10) = (short)piVar6[5] << 4;
              *(int *)(lVar1 + 0x14) = piVar6[3];
              *(undefined1 *)((ulonglong)*(ushort *)(piVar6 + 4) + *(longlong *)(param_1 + 0x1580))
                   = 1;
              *(undefined1 *)((longlong)piVar6 + 0x1b) = 1;
              return;
            }
            goto LAB_1400085de;
          }
        }
LAB_140008367:
        bVar3 = *(byte *)(param_1 + 0x1574);
        if ((ushort)bVar3 < *(ushort *)(param_1 + 0x65a)) {
          *(byte *)(param_1 + 0x1574) = bVar3 + 1;
          piVar6 = (int *)(*(longlong *)(param_1 + 0x358) + (ulonglong)bVar3 * 0x24);
          *(undefined2 *)((longlong)piVar6 + 0x12) = *(undefined2 *)(param_2 + 0x1c);
          *(undefined8 *)piVar6 = *(undefined8 *)(param_2 + 0x20);
          piVar6[2] = -1;
          *(undefined2 *)(piVar6 + 5) = *(undefined2 *)(param_2 + 0x28);
          *(undefined2 *)((longlong)piVar6 + 0x16) = *(undefined2 *)(param_2 + 0x2a);
          piVar6[3] = *(int *)(param_2 + 0x2c);
          *(undefined2 *)(piVar6 + 4) = 0xffff;
LAB_1400085de:
          *(undefined1 *)((longlong)piVar6 + 0x1b) = 1;
        }
        else {
          pcVar11 = "Enclosure Table Full (ProcessSasEnclosureStatusChange)";
          uVar8 = 0xad010046;
          uVar10 = 0xc004af02;
LAB_140008392:
          LogSystemEvent(param_1,uVar8,uVar10,(byte *)pcVar11,param_3);
        }
      }
    }
    else if (*(char *)(param_2 + 0x1e) == '\x02') {
      pcVar11 = (char *)(*(longlong *)(param_1 + 0x358) + 0x18);
      for (uVar7 = 0; uVar7 < *(byte *)(param_1 + 0x1574); uVar7 = uVar7 + 1) {
        if ((*(short *)(pcVar11 + -6) == *(short *)(param_2 + 0x1c)) && (*pcVar11 == '\0')) {
          if (uVar7 != 0xffff) {
            lVar1 = *(longlong *)(param_1 + 0x358) + (ulonglong)uVar7 * 0x24;
            cVar5 = *(char *)(lVar1 + 0x1b);
            if (cVar5 == '\0') {
              if (*(byte *)(lVar1 + 0x18) < 0xf) {
                *(byte *)(lVar1 + 0x18) = *(byte *)(lVar1 + 0x18) + 1;
              }
              else {
                *(undefined1 *)(lVar1 + 0x1b) = 1;
                cVar5 = '\x01';
              }
            }
            if (*(char *)(lVar1 + 0x18) == '\0') {
              *(undefined1 *)(lVar1 + 0x18) = 1;
            }
            if ((((*(byte *)(param_1 + 0x1568) & 1) == 0) && (cVar5 == '\0')) &&
               (*(ushort *)(lVar1 + 0x10) != 0xffff)) {
              lVar2 = *(longlong *)(param_1 + 0x15c8) + (ulonglong)*(ushort *)(lVar1 + 0x10) * 0x14;
              uVar7 = *(short *)(lVar1 + 0x14) << 4;
              *(ushort *)(lVar2 + 0x10) = uVar7;
              *(ushort *)(lVar2 + 0x10) = *(byte *)(lVar1 + 0x18) | uVar7;
              *(undefined1 *)
               ((ulonglong)*(ushort *)(lVar1 + 0x10) + *(longlong *)(param_1 + 0x1580)) = 1;
            }
            *(undefined1 *)(lVar1 + 0x1b) = 1;
            return;
          }
          break;
        }
        pcVar11 = pcVar11 + 0x24;
      }
      LogSystemEvent(param_1,0xad01004d,0xc004af02,(byte *)"Removing Non-Existing Enclosure",param_3
                    );
    }
  }
  return;
LAB_14000835a:
  uVar7 = uVar7 + 1;
  piVar6 = piVar6 + 9;
  if (*(byte *)(param_1 + 0x1574) <= uVar7) goto LAB_140008367;
  goto LAB_140008341;
}



===== ProcessSasTopologyChangeList @ 1400086f0 =====

void ProcessSasTopologyChangeList(longlong param_1,ushort *param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  ushort *puVar3;
  ushort uVar4;
  longlong lVar5;
  ushort uVar6;
  longlong lVar7;
  ulonglong uVar8;
  int iVar9;
  
  *(undefined4 *)(param_1 + 0xe90) = 0x1e;
  uVar6 = (ushort)(byte)param_2[0x12];
  uVar4 = (uVar6 + 3) * 4;
  if ((((ushort)(uVar4 + 0x1c) != (ushort)((ushort)(byte)param_2[1] << 2)) ||
      ((uint)uVar4 != (uint)*param_2 << 2)) || ((byte)param_2[0x12] == 0)) {
    LogSystemEvent(param_1,0xad01003d,0xc004af02,
                   (byte *)"Wrong Event Data Length (SasTopologyChangeList)",param_3);
    return;
  }
  uVar2 = *(uint *)(param_1 + 0x1588);
  lVar5 = (ulonglong)uVar2 * 0x3cc + *(longlong *)(param_1 + 0x360);
  if (*(char *)(lVar5 + 0x3c4) == '\0') {
    puVar3 = param_2 + 0x14;
    *(ushort *)(lVar5 + 0x3c0) = param_2[0xe];
    *(ushort *)(lVar5 + 0x3c2) = param_2[0xf];
    *(char *)(lVar5 + 0x3c4) = (char)param_2[0x12];
    *(char *)(lVar5 + 0x3c5) = (char)param_2[0x10];
    *(undefined1 *)(lVar5 + 0x3c6) = *(undefined1 *)((longlong)param_2 + 0x25);
    *(undefined1 *)(lVar5 + 0x3c7) = 0;
    *(char *)(lVar5 + 0x3c8) = (char)param_2[0x13];
    if (uVar6 != 0) {
      uVar8 = (ulonglong)uVar6;
      lVar7 = lVar5;
      do {
        if ((*(byte *)((longlong)puVar3 + 3) & 0xf) == 3) {
          *(char *)(lVar5 + 0x3c4) = *(char *)(lVar5 + 0x3c4) + -1;
        }
        else {
          *(ushort *)(lVar7 + 0x14) = *puVar3;
          bVar1 = *(byte *)((longlong)puVar3 + 3);
          *(undefined1 *)(lVar7 + 0x18) = 0;
          *(byte *)(lVar7 + 0x1a) = bVar1 & 0xf;
          lVar7 = lVar7 + 0x20;
        }
        puVar3 = puVar3 + 2;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
      if (lVar7 != lVar5) {
        iVar9 = 0;
        if (((int)lVar5 - *(int *)(param_1 + 0x360)) + 0x798U <=
            (uint)*(ushort *)(param_1 + 0x65c) * 0x3cc) {
          iVar9 = uVar2 + 1;
        }
        *(int *)(param_1 + 0x1588) = iVar9;
        if ((*(char *)(param_1 + 0xe84) == '\0') && (*(char *)(param_1 + 0xe85) == '\0')) {
          if ((*(int *)(param_1 + 0x630) == 0) && (*(int *)(param_1 + 0xec0) == 0)) {
            StorPortPause(param_1,300);
            ResetActive(param_1,7,param_3);
          }
          *(undefined1 *)(param_1 + 0xe84) = 1;
          UpdateMissingCount(param_1,param_3);
          StartIDReadsForPhyEvents(param_1,param_3);
          return;
        }
      }
    }
  }
  else {
    LogSystemEvent(param_1,0xad010043,0xc004af02,(byte *)"Event List Full (SasTopologyChangeList)",
                   param_3);
  }
  return;
}



===== ReadIDs @ 140008910 =====

undefined8 ReadIDs(longlong param_1,int param_2)

{
  ulonglong uVar1;
  undefined8 uVar2;
  byte bVar3;
  longlong lVar4;
  
  uVar1 = (ulonglong)*(uint *)(param_1 + 0x158c);
  lVar4 = uVar1 * 0x3cc + *(longlong *)(param_1 + 0x360);
  bVar3 = *(byte *)(lVar4 + 0x3c7);
  while( true ) {
    if (*(byte *)(lVar4 + 0x3c4) <= bVar3) {
      return uVar1 & 0xffffffffffffff00;
    }
    uVar1 = (ulonglong)bVar3 * 0x20 + lVar4;
    if (((*(short *)(uVar1 + 0x14) != 0) && (*(char *)(uVar1 + 0x1a) == '\x01')) &&
       (*(char *)(uVar1 + 0x18) == '\0')) break;
    bVar3 = bVar3 + 1;
  }
  *(byte *)(lVar4 + 0x3c7) = bVar3;
  *(undefined1 *)(param_1 + 0xe86) = 1;
  *(undefined1 *)(param_1 + 0x676) = 1;
  uVar2 = SendExtendedConfigPageMessage
                    (param_1,'\x01',(char *)(param_1 + 0x15d8),
                     *(ushort *)(uVar1 + 0x14) | 0x20000000,(int)*(undefined8 *)(param_1 + 0x15e0),
                     param_2);
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== ReadIrIDs @ 1400089b0 =====

ulonglong ReadIrIDs(longlong param_1,int param_2)

{
  longlong lVar1;
  longlong lVar2;
  byte bVar3;
  undefined1 *puVar4;
  ushort uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined4 extraout_var;
  undefined8 uVar8;
  byte bVar9;
  longlong lVar10;
  
  uVar7 = (ulonglong)*(uint *)(param_1 + 0x1594);
  lVar10 = uVar7 * 0x188 + *(longlong *)(param_1 + 0x368);
  bVar9 = *(byte *)(lVar10 + 0x185);
  if (bVar9 < *(byte *)(lVar10 + 0x184)) {
    do {
      *(byte *)(lVar10 + 0x185) = bVar9;
      bVar3 = *(byte *)(lVar10 + 0x13 + (ulonglong)bVar9 * 0x18);
      lVar1 = lVar10 + (ulonglong)bVar9 * 0x18;
      uVar7 = (ulonglong)(bVar3 - 1);
      if (((byte)(bVar3 - 1) < 3) || (bVar3 == 6)) {
        if ((*(char *)(lVar1 + 0x12) == '\0') && (uVar7 = 0, (*(byte *)(lVar1 + 0xc) & 0xf) == 0)) {
          *(undefined1 *)(param_1 + 0xe87) = 1;
          uVar8 = SendConfigPageMessage
                            (param_1,'\x01',(undefined4 *)(param_1 + 0x15b0),
                             *(ushort *)(lVar1 + 0xe) | 0x10000000,
                             (int)*(undefined8 *)(param_1 + 0x15b8),param_2);
          return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
        }
      }
      else if (((*(char *)(param_1 + 0xeb2) != '\0') &&
               (uVar5 = (*(ushort *)(lVar1 + 0xc) & 0xf) - 1, uVar7 = (ulonglong)uVar5, uVar5 < 2))
              && (uVar7 = (ulonglong)(bVar3 - 4), (bVar3 - 4 & 0xfa) == 0)) {
        uVar6 = GetMapTableIndexFromHandle(param_1,*(short *)(lVar1 + 0x10));
        uVar7 = CONCAT44(extraout_var,uVar6);
        if (uVar6 != 0xffffffff) {
          lVar2 = *(longlong *)(param_1 + 0x378) + (ulonglong)uVar6 * 0x28;
          uVar7 = (ulonglong)(bVar3 - 4);
          if ((bVar3 - 4 & 0xfb) == 0) {
            if (*(char *)(lVar2 + 0x23) == '\0') {
              *(undefined1 *)(lVar2 + 0x23) = 1;
              puVar4 = *(undefined1 **)(param_1 + 0x328);
              ZeroMemory(puVar4,8);
              puVar4[3] = 0x15;
              *puVar4 = 0x24;
              puVar4[6] = *(undefined1 *)(lVar1 + 0x14);
              uVar8 = QueueRequestDescriptor
                                (param_1,(uint)*(ushort *)(param_1 + 0x670) * 0x10000 + 8,0,param_2)
              ;
              return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
            }
          }
          else if ((bVar3 - 5 & 0xfb) == 0) {
            uVar6 = *(uint *)(lVar2 + 0x14);
            uVar7 = (ulonglong)uVar6;
            *(undefined1 *)(lVar2 + 0x23) = 0;
            if ((int)uVar6 < 0) {
              uVar7 = (ulonglong)(uVar6 & 0x7fffffff);
              *(uint *)(lVar2 + 0x14) = uVar6 & 0x7fffffff;
            }
          }
        }
      }
      bVar9 = bVar9 + 1;
    } while (bVar9 < *(byte *)(lVar10 + 0x184));
  }
  return uVar7 & 0xffffffffffffff00;
}



===== RemoveDevice @ 140008b70 =====

void RemoveDevice(longlong param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  ushort *puVar6;
  ushort *puVar7;
  
  uVar2 = *(uint *)(param_1 + 0x678);
  uVar5 = (ulonglong)uVar2;
  uVar4 = 0;
  puVar7 = *(ushort **)(param_1 + 0x370);
  puVar6 = puVar7;
  if (uVar2 != 0) {
    do {
      if (puVar6[1] != 0) {
        puVar7 = *(ushort **)(param_1 + 0x328);
        if ((char)puVar6[2] == '\0') {
          *(undefined1 *)(param_1 + 0xe81) = 1;
          ZeroMemory((undefined1 *)puVar7,0x34);
          *puVar7 = puVar6[1];
          *(undefined1 *)((longlong)puVar7 + 3) = 1;
          *(undefined1 *)((longlong)puVar7 + 5) = 3;
          QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x670) * 0x10000 + 6,0,param_2)
          ;
          *(undefined4 *)(param_1 + 0x634) = 0xf;
          *(undefined1 *)(puVar6 + 2) = 1;
          return;
        }
        ZeroMemory((undefined1 *)puVar7,0x2c);
        *(undefined1 *)((longlong)puVar7 + 3) = 0x1b;
        *(undefined1 *)puVar7 = 0xd;
        puVar7[2] = puVar6[1];
        QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x670) * 0x10000 + 8,0,param_2);
        puVar6[1] = 0;
        *(undefined1 *)(puVar6 + 2) = 0;
        *(undefined1 *)(param_1 + 0x380) = 1;
        return;
      }
      uVar4 = uVar4 + 1;
      puVar6 = puVar6 + 4;
    } while (uVar4 < uVar2);
  }
  if (((*(byte *)(param_1 + 0x1568) & 1) == 0) && (uVar2 != 0)) {
    do {
      uVar1 = *puVar7;
      if (uVar1 != 0xffff) {
        lVar3 = *(longlong *)(param_1 + 0x15c8);
        *(undefined8 *)(lVar3 + 8 + (ulonglong)uVar1 * 0x14) = 0;
        *(undefined8 *)(lVar3 + 0x10 + (ulonglong)uVar1 * 0x14) = 0;
        *(undefined1 *)((ulonglong)*puVar7 + *(longlong *)(param_1 + 0x1580)) = 1;
        *(undefined1 *)((ulonglong)*puVar7 + *(longlong *)(param_1 + 0x1578)) = 0;
        *puVar7 = 0xffff;
      }
      puVar7 = puVar7 + 4;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  CompressEnclosureTable(param_1);
  AddDevice(param_1,param_2);
  return;
}



===== SODCheckMapEntry @ 140008d00 =====

void SODCheckMapEntry(longlong param_1,longlong param_2,uint param_3,uint param_4,int param_5)

{
  ushort uVar1;
  longlong lVar2;
  short sVar3;
  char cVar4;
  int *piVar5;
  uint uVar6;
  ulonglong uVar7;
  
  if (param_3 < param_4) {
    piVar5 = (int *)(param_2 + 4);
    uVar7 = (ulonglong)(param_4 - param_3);
    do {
      if (((uint)piVar5[4] >> 0x1d & 1) != 0) {
        if ((piVar5[-1] != 0) || (*piVar5 != 0)) {
          if (*(char *)((longlong)piVar5 + 0x1d) != '\0') goto LAB_140008ed8;
          if (((*(byte *)(piVar5 + 7) < 0xf) &&
              (*(byte *)(piVar5 + 7) = *(byte *)(piVar5 + 7) + 1,
              (*(byte *)(param_1 + 0x1568) & 1) == 0)) &&
             (uVar1 = *(ushort *)(piVar5 + 5), uVar1 != 0xffff)) {
            lVar2 = *(longlong *)(param_1 + 0x15c8);
            *(int *)(lVar2 + 8 + (ulonglong)uVar1 * 0x14) = piVar5[-1];
            lVar2 = lVar2 + (ulonglong)uVar1 * 0x14;
            *(int *)(lVar2 + 0xc) = *piVar5;
            sVar3 = (short)piVar5[6] * 0x80;
            *(short *)(lVar2 + 0x12) = sVar3;
            *(short *)(lVar2 + 0x12) = *(short *)((longlong)piVar5 + 0x1a) + sVar3;
            *(ushort *)(lVar2 + 0x10) = (ushort)*(byte *)(piVar5 + 7);
            *(undefined8 *)(lVar2 + 0x14) = 0;
            ZeroMemory(*(undefined1 **)(param_1 + 0x15d0),8);
            memmove((void *)(*(longlong *)(param_1 + 0x15d0) + 8),(void *)(lVar2 + 8),0x14);
            uVar1 = *(ushort *)(piVar5 + 5);
            *(undefined1 *)(param_1 + 0x676) = 1;
            if ((*(char *)(param_1 + 0xb328) == '\0') &&
               (cVar4 = IsHbaFwDowngradeInProgress(param_1), cVar4 == '\0')) {
              *(undefined1 *)(param_1 + 0xe88) = 1;
              SendExtendedConfigPageMessage
                        (param_1,'\x04',(char *)(param_1 + 0x15c0),uVar1 | 0x10000,
                         (int)*(undefined8 *)(param_1 + 0x15d0),param_5);
              uVar6 = 0;
              do {
                PollLSImpiIsr(param_1,param_5);
                if (*(char *)(param_1 + 0xe88) == '\0') goto LAB_140008ed4;
                StorPortStallExecution(500);
                uVar6 = uVar6 + 1;
              } while (uVar6 < 120000);
              if (*(char *)(param_1 + 0xe88) != '\0') {
                LogSystemEvent(param_1,0xad01004b,0xc004af02,
                               (byte *)"Start-of-Day Check Failed (SODCheckMapEntry)",param_5);
              }
            }
            else {
              *(undefined1 *)((ulonglong)*(ushort *)(piVar5 + 5) + *(longlong *)(param_1 + 0x1580))
                   = 1;
            }
          }
        }
LAB_140008ed4:
        *(undefined1 *)((longlong)piVar5 + 0x1d) = 1;
      }
LAB_140008ed8:
      piVar5 = piVar5 + 10;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  return;
}



===== SendSTPIdentifyCommand @ 140008f10 =====

void SendSTPIdentifyCommand(longlong param_1,uint param_2,undefined2 param_3,int param_4)

{
  char cVar1;
  ushort uVar2;
  undefined2 *puVar3;
  undefined1 uVar4;
  byte bVar5;
  int iVar6;
  
  puVar3 = *(undefined2 **)(param_1 + 0x328);
  cVar1 = *(char *)(param_1 + 0xeb2);
  uVar2 = *(ushort *)(param_1 + 0x670);
  ZeroMemory((undefined1 *)puVar3,0x40);
  *(undefined1 *)((longlong)puVar3 + 3) = 0x1c;
  puVar3[2] = 0x11;
  *puVar3 = param_3;
  *(undefined4 *)(puVar3 + 0xc) = 0x200;
  uVar4 = 0xec;
  if ((param_2 >> 0xd & 1) != 0) {
    uVar4 = 0xa1;
  }
  puVar3[0xe] = 0x8027;
  *(undefined1 *)(puVar3 + 0xf) = uVar4;
  iVar6 = *(int *)(param_1 + 0xea8) - *(int *)(param_1 + 0x100);
  if (cVar1 == '\0') {
    *(undefined4 *)(puVar3 + 0x18) = 0xd3000200;
    *(int *)(puVar3 + 0x1a) = iVar6;
    *(undefined4 *)(puVar3 + 0x1c) = *(undefined4 *)(param_1 + 0x1ec);
  }
  else {
    *(undefined4 *)(puVar3 + 0x1c) = 0x200;
    *(undefined1 *)((longlong)puVar3 + 0x3f) = 0x40;
    *(int *)(puVar3 + 0x18) = iVar6;
    *(undefined4 *)(puVar3 + 0x1a) = *(undefined4 *)(param_1 + 0x1ec);
  }
  QueueRequestDescriptor(param_1,(uint)uVar2 * 0x10000 + 8,0,param_4);
  bVar5 = GtfStartTimer(param_1,1,5,AtaIdentifyTimeout,0,param_4);
  *(byte *)(param_1 + 0xeb0) = bVar5;
  if (((bVar5 == 0xfe) && (*(char *)(param_1 + 0x3b8) != '\0')) &&
     ((*(uint *)(param_1 + 0x3bc) & 0x233) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x233,(undefined1 *)0x0,0
                ,param_4);
  }
  return;
}



===== StartIDReadsForIrElements @ 140009080 =====

void StartIDReadsForIrElements(longlong param_1,int param_2)

{
  undefined8 uVar1;
  
  uVar1 = ReadIrIDs(param_1,param_2);
  if ((char)uVar1 == '\0') {
    *(undefined1 *)(param_1 + 0xe87) = 0;
    AddOrRemoveIrVolume(param_1,param_2);
  }
  return;
}



===== StartIDReadsForPhyEvents @ 1400090c0 =====

void StartIDReadsForPhyEvents(longlong param_1,int param_2)

{
  undefined8 uVar1;
  
  uVar1 = ReadIDs(param_1,param_2);
  if ((char)uVar1 == '\0') {
    *(undefined1 *)(param_1 + 0xe86) = 0;
    RemoveDevice(param_1,param_2);
  }
  return;
}



===== UpdateIrMissingCount @ 140009100 =====

void UpdateIrMissingCount(longlong param_1,uint param_2,undefined8 *param_3,int param_4)

{
  int *piVar1;
  longlong lVar2;
  char cVar3;
  byte bVar4;
  ulonglong uVar5;
  ushort uVar6;
  int *piVar7;
  int iStackX_c;
  
  piVar1 = (int *)(*(longlong *)(param_1 + 0x378) + (ulonglong)param_2 * 0x28);
  if ((*(byte *)(param_1 + 0x1568) & 1) == 0) {
    cVar3 = *(char *)((longlong)param_3 + 0x13);
    if (cVar3 == '\x01') {
      *(undefined1 *)(piVar1 + 8) = 0;
    }
    else if (cVar3 == '\x06') {
      *(undefined2 *)(piVar1 + 8) = 0;
    }
    else if ((cVar3 == '\x02') || (cVar3 == '\a')) {
      if (*(char *)((longlong)piVar1 + 0x21) == '\0') {
        if (*(byte *)(piVar1 + 8) < 0xf) {
          *(byte *)(piVar1 + 8) = *(byte *)(piVar1 + 8) + 1;
        }
        else {
          *(undefined1 *)((longlong)piVar1 + 0x21) = 1;
        }
      }
      if ((char)piVar1[8] == '\0') {
        *(undefined1 *)(piVar1 + 8) = 1;
      }
      *(undefined2 *)((longlong)piVar1 + 0x1a) = 0;
    }
    uVar6 = *(ushort *)(piVar1 + 6);
    if (uVar6 == 0xffff) {
      if ((byte)(*(char *)((longlong)param_3 + 0x13) - 1U) < 2) {
        uVar6 = 0;
        piVar7 = (int *)(*(longlong *)(param_1 + 0x15c8) + 8);
        if (*(ushort *)(param_1 + 0x1564) != 0) {
          iStackX_c = (int)((ulonglong)*param_3 >> 0x20);
          do {
            if (((*(char *)((ulonglong)uVar6 + *(longlong *)(param_1 + 0x1578)) != '\0') &&
                (*piVar7 == (int)*param_3)) && (piVar7[1] == iStackX_c)) {
              if (uVar6 != 0xffff) goto LAB_14000922c;
              break;
            }
            uVar6 = uVar6 + 1;
            piVar7 = piVar7 + 5;
          } while (uVar6 < *(ushort *)(param_1 + 0x1564));
        }
      }
      else if (*(char *)((longlong)param_3 + 0x13) == '\a') {
        return;
      }
      uVar5 = GetFirstFreeDPMPage0(param_1);
      uVar6 = (ushort)uVar5;
      *(undefined1 *)((longlong)piVar1 + 0x21) = 0;
    }
    else {
LAB_14000922c:
      lVar2 = *(longlong *)(param_1 + 0x15c8) + (ulonglong)uVar6 * 0x14;
      if (((*(int *)(lVar2 + 8) == *piVar1) && (*(int *)(lVar2 + 0xc) == piVar1[1])) &&
         ((*(byte *)(lVar2 + 0x10) & 0xf) == *(byte *)(piVar1 + 8))) {
        *(undefined1 *)((longlong)piVar1 + 0x21) = 1;
      }
    }
    if (uVar6 == 0xffff) {
      if ((*(char *)(param_1 + 0xb4a5) != '\0') && (*(char *)(param_1 + 0xb4a4) == '\0')) {
        LogSystemEvent(param_1,0xad010045,0xc004af02,
                       (byte *)"persistent driver mapping config page is full",param_4);
        *(undefined1 *)(param_1 + 0xb4a4) = 1;
      }
      *(undefined1 *)((longlong)piVar1 + 0x21) = 1;
    }
    else if (*(char *)((longlong)piVar1 + 0x21) == '\0') {
      *(ushort *)(piVar1 + 6) = uVar6;
      *(undefined1 *)((longlong)piVar1 + 0x21) = 1;
      uVar5 = (ulonglong)uVar6;
      lVar2 = *(longlong *)(param_1 + 0x15c8) + uVar5 * 0x14;
      *(undefined8 *)(lVar2 + 8) = *(undefined8 *)piVar1;
      bVar4 = *(byte *)(piVar1 + 8);
      *(short *)(lVar2 + 0x12) = (short)param_2;
      *(undefined4 *)(lVar2 + 0x14) = 0;
      *(ushort *)(lVar2 + 0x10) = (ushort)(bVar4 & 0xf);
      *(undefined1 *)(uVar5 + *(longlong *)(param_1 + 0x1580)) = 1;
      *(undefined1 *)(uVar5 + *(longlong *)(param_1 + 0x1578)) = 1;
    }
  }
  return;
}



===== UpdateMissingCount @ 140009320 =====

longlong UpdateMissingCount(longlong param_1,int param_2)

{
  short *psVar1;
  short *psVar2;
  undefined1 *puVar3;
  uint uVar4;
  longlong lVar5;
  uint uVar6;
  undefined8 *puVar7;
  longlong lVar8;
  byte bVar9;
  longlong lVar10;
  
  uVar6 = *(uint *)(param_1 + 0x158c);
  lVar10 = (ulonglong)uVar6 * 0x3cc + *(longlong *)(param_1 + 0x360);
  bVar9 = *(byte *)(lVar10 + 0x3c7);
  if (*(byte *)(lVar10 + 0x3c4) <= bVar9) {
    *(undefined1 *)(lVar10 + 0x3c7) = 0;
    return (ulonglong)(uint3)(uVar6 >> 8) << 8;
  }
  do {
    puVar7 = (undefined8 *)((ulonglong)bVar9 * 0x20 + lVar10);
    psVar1 = (short *)((longlong)puVar7 + 0x14);
    if (*(short *)((longlong)puVar7 + 0x14) != 0) {
      if (*(char *)((longlong)puVar7 + 0x1a) == '\x05') {
        lVar5 = *(longlong *)(param_1 + 0x378);
        lVar8 = lVar5;
        for (uVar6 = 0; uVar6 < *(uint *)(param_1 + 0x678); uVar6 = uVar6 + 1) {
          psVar2 = (short *)(lVar8 + 0x1a);
          lVar8 = lVar8 + 0x28;
          if (*psVar2 == *(short *)((longlong)puVar7 + 0x14)) {
            if (uVar6 != 0xffffffff) {
              uVar4 = *(uint *)(lVar5 + 0x14 + (ulonglong)uVar6 * 0x28);
              if ((int)uVar4 < 0) {
                *(uint *)(lVar5 + 0x14 + (ulonglong)uVar6 * 0x28) = uVar4 & 0x7fffffff;
              }
              goto LAB_14000941d;
            }
            break;
          }
        }
      }
      else {
LAB_14000941d:
        if ((*(char *)((longlong)puVar7 + 0x1a) == '\x02') &&
           (*(char *)((longlong)puVar7 + 0x19) == '\0')) {
          lVar8 = *(longlong *)(param_1 + 0x378);
          for (uVar6 = 0; uVar6 < *(uint *)(param_1 + 0x678); uVar6 = uVar6 + 1) {
            psVar2 = (short *)(lVar8 + 0x1a);
            lVar8 = lVar8 + 0x28;
            if (*psVar2 == *psVar1) {
              if (uVar6 != 0xffffffff) {
                *puVar7 = 0;
                puVar7[1] = 0;
                *(undefined4 *)(puVar7 + 2) = 0;
                *psVar1 = 0;
                *(undefined4 *)((longlong)puVar7 + 0x16) = 0;
                *(undefined2 *)((longlong)puVar7 + 0x1a) = 0;
                *(undefined1 *)((longlong)puVar7 + 0x1c) = 0;
                puVar3 = (undefined1 *)(*(longlong *)(param_1 + 0x378) + (ulonglong)uVar6 * 0x28);
                if (*(char *)(*(longlong *)(param_1 + 0x378) + 0x21 + (ulonglong)uVar6 * 0x28) ==
                    '\0') {
                  if ((byte)puVar3[0x20] < 0xf) {
                    puVar3[0x20] = puVar3[0x20] + 1;
                  }
                  else {
                    puVar3[0x21] = 1;
                  }
                }
                if (puVar3[0x20] == '\0') {
                  puVar3[0x20] = 1;
                  *(undefined1 *)(param_1 + 0x380) = 1;
                }
                if ((*(char *)(param_1 + 0x3b8) != '\0') &&
                   ((*(uint *)(param_1 + 0x3bc) & 0x100005) != 0)) {
                  RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x100005,
                              puVar3,0x28,param_2);
                }
                AddToRemovalTable(param_1,*(short *)(puVar3 + 0x1a),0,param_2);
                AfdMasterTrigger(param_1,8,param_2);
                puVar3[0x23] = 0;
                if ((((*(byte *)(param_1 + 0x1568) & 0xf) == 0) && (puVar3[0x21] == '\0')) &&
                   (*(ushort *)(puVar3 + 0x18) != 0xffff)) {
                  *(ushort *)
                   (*(longlong *)(param_1 + 0x15c8) + 0x10 +
                   (ulonglong)*(ushort *)(puVar3 + 0x18) * 0x14) = (ushort)(byte)puVar3[0x20];
                  *(undefined1 *)
                   ((ulonglong)*(ushort *)(puVar3 + 0x18) + *(longlong *)(param_1 + 0x1580)) = 1;
                }
                *(byte *)(lVar10 + 0x3c7) = bVar9;
                puVar3[0x21] = 1;
                goto LAB_14000960c;
              }
              break;
            }
          }
          LogSystemEvent(param_1,0xad01004a,0xc004af02,(byte *)"Removing unmapped device",param_2);
          if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x247) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x247,
                        (undefined1 *)psVar1,2,param_2);
          }
          AddToRemovalTable(param_1,*psVar1,0,param_2);
        }
      }
    }
LAB_14000960c:
    bVar9 = bVar9 + 1;
    if (*(byte *)(lVar10 + 0x3c4) <= bVar9) {
      *(undefined1 *)(lVar10 + 0x3c7) = 0;
      return 0;
    }
  } while( true );
}



===== AfdMasterTrigger @ 140009670 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AfdMasterTrigger(longlong param_1,uint param_2,undefined4 param_3)

{
  undefined1 auStack_58 [32];
  undefined4 local_38;
  undefined4 local_28;
  uint local_24;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  if (param_2 == 1) {
    if (*(char *)(param_1 + 0x139a) != '\0') goto LAB_1400096a0;
    *(undefined1 *)(param_1 + 0x139a) = 1;
  }
  if (*(char *)(param_1 + 0x139a) == '\0') {
    return;
  }
LAB_1400096a0:
  if ((*(char *)(param_1 + 0xb350) != '\0') && ((*(uint *)(param_1 + 0xb354) & param_2) != 0)) {
    local_28 = 1;
    local_38 = param_3;
    local_24 = param_2;
    SendMpiEventToApplication(param_1,0x6e,&local_28,0xc);
  }
  return;
}



===== AfdMpiLogInfoTrigger @ 1400096f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AfdMpiLogInfoTrigger(longlong param_1,int param_2,short param_3,undefined4 param_4)

{
  bool bVar1;
  short *psVar2;
  uint uVar3;
  undefined1 auStack_58 [32];
  undefined4 local_38;
  undefined4 local_28;
  short local_24;
  int local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  bVar1 = false;
  if ((*(char *)(param_1 + 0x139a) != '\0') && (*(char *)(param_1 + 0xb350) != '\0')) {
    psVar2 = (short *)(param_1 + 0xb404);
    uVar3 = 0;
    if (*(uint *)(param_1 + 0xb400) != 0) {
      do {
        if (bVar1) goto LAB_14000976c;
        if ((*psVar2 == param_3) &&
           ((*(int *)(psVar2 + 2) == 0xffff || (*(int *)(psVar2 + 2) == param_2)))) {
          bVar1 = true;
        }
        uVar3 = uVar3 + 1;
        psVar2 = psVar2 + 4;
      } while (uVar3 < *(uint *)(param_1 + 0xb400));
      if (bVar1) {
LAB_14000976c:
        local_28 = 4;
        local_38 = param_4;
        local_24 = param_3;
        local_20 = param_2;
        SendMpiEventToApplication(param_1,0x6e,&local_28,0xc);
      }
    }
  }
  return;
}



===== AfdScsiSenseTrigger @ 1400097c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void AfdScsiSenseTrigger(longlong param_1,char param_2,char param_3,char param_4,undefined4 param_5)

{
  bool bVar1;
  char *pcVar2;
  uint uVar3;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 local_38;
  char local_34;
  char local_33;
  char local_32;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  bVar1 = false;
  if ((*(char *)(param_1 + 0x139a) != '\0') && (*(char *)(param_1 + 0xb350) != '\0')) {
    pcVar2 = (char *)(param_1 + 46000);
    uVar3 = 0;
    if (*(uint *)(param_1 + 0xb3ac) != 0) {
      do {
        if (bVar1) goto LAB_14000984b;
        if (((pcVar2[2] == param_2) && ((pcVar2[1] == -1 || (pcVar2[1] == param_3)))) &&
           ((*pcVar2 == -1 || (*pcVar2 == param_4)))) {
          bVar1 = true;
        }
        uVar3 = uVar3 + 1;
        pcVar2 = pcVar2 + 4;
      } while (uVar3 < *(uint *)(param_1 + 0xb3ac));
      if (bVar1) {
LAB_14000984b:
        local_38 = 3;
        local_48 = param_5;
        local_34 = param_4;
        local_33 = param_3;
        local_32 = param_2;
        SendMpiEventToApplication(param_1,0x6e,&local_38,0xc);
      }
    }
  }
  return;
}



===== BringIOCToOperationalState @ 1400098a0 =====

ulonglong BringIOCToOperationalState(longlong param_1,int param_2)

{
  ushort uVar1;
  undefined8 *puVar2;
  bool bVar3;
  int iVar4;
  undefined7 extraout_var;
  undefined4 *puVar5;
  int *piVar6;
  ulonglong uVar7;
  ushort uVar8;
  uint uVar9;
  
  bVar3 = SendIOCInitMessage(param_1,param_2);
  puVar5 = (undefined4 *)CONCAT71(extraout_var,bVar3);
  if (bVar3) {
    uVar8 = *(ushort *)(param_1 + 0x2f2);
    uVar1 = *(ushort *)(param_1 + 0x2e8);
    iVar4 = *(int *)(param_1 + 0x210);
    piVar6 = *(int **)(param_1 + 0x300);
    if (uVar8 != 0) {
      uVar7 = (ulonglong)uVar8;
      do {
        *piVar6 = iVar4;
        piVar6 = piVar6 + 1;
        iVar4 = iVar4 + (uint)uVar1;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
    }
    **(uint **)(param_1 + 0x58) = (uint)uVar8;
    LOCK();
    UNLOCK();
    *(ushort *)(param_1 + 0x21c) = uVar8;
    ReadAndSetSASPages(param_1,param_2);
    if (*(char *)(param_1 + 0xb4f0) != '\0') {
      SendIoUnitCtrlForPuis(param_1,*(byte *)(param_1 + 0xb4f2),param_2);
    }
    ProcessDPMPage0(param_1,param_2);
    puVar5 = (undefined4 *)EnableDisableEvents(param_1,'\x01',param_2);
    if ((char)puVar5 != '\0') {
      uVar8 = 0;
      if (*(short *)(param_1 + 0x656) != 0) {
        do {
          puVar2 = *(undefined8 **)(param_1 + 800);
          *(undefined1 *)(param_1 + 0xe80) = 1;
          *puVar2 = 0;
          *(undefined4 *)(puVar2 + 1) = 0;
          *(undefined1 *)((longlong)puVar2 + 3) = 6;
          **(int **)(param_1 + 0xe8) = (uint)*(ushort *)(param_1 + 0x66e) * 0x10000 + 8;
          LOCK();
          UNLOCK();
          puVar5 = *(undefined4 **)(param_1 + 0xf0);
          *puVar5 = 0;
          LOCK();
          UNLOCK();
          uVar9 = 0;
          if (*(int *)(param_1 + 0x618) == 0) goto LAB_140009a1e;
          do {
            puVar5 = (undefined4 *)PollLSImpiIsr(param_1,param_2);
            if (*(char *)(param_1 + 0xe80) == '\0') break;
            puVar5 = (undefined4 *)StorPortStallExecution(500);
            uVar9 = uVar9 + 1;
          } while (uVar9 < *(uint *)(param_1 + 0x618));
          if ((*(uint *)(param_1 + 0x618) <= uVar9) || (*(short *)(param_1 + 0x626) != 0))
          goto LAB_140009a1e;
          uVar8 = uVar8 + 1;
        } while (uVar8 < *(ushort *)(param_1 + 0x656));
      }
      return CONCAT71((int7)((ulonglong)puVar5 >> 8),1);
    }
  }
LAB_140009a1e:
  return (ulonglong)puVar5 & 0xffffffffffffff00;
}



===== BuildIoctlScatterGather @ 140009a40 =====

int BuildIoctlScatterGather
              (longlong param_1,longlong param_2,uint *param_3,uint param_4,short *param_5,
              int param_6,char param_7)

{
  ushort uVar1;
  short *psVar2;
  char cVar3;
  int iVar4;
  ushort uVar5;
  uint uVar6;
  uint *puVar7;
  byte bVar8;
  undefined1 uVar9;
  uint uVar10;
  uint *puVar11;
  uint *puVar12;
  uint *puVar13;
  int iVar14;
  uint uVar15;
  ulonglong uVar16;
  longlong lVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  char cVar21;
  uint uVar22;
  ulonglong uVar23;
  uint uVar24;
  uint *puVar25;
  uint local_res20;
  int local_78;
  int iVar26;
  uint local_70;
  uint local_6c;
  short local_60;
  uint *local_58;
  
  cVar3 = param_7;
  psVar2 = param_5;
  local_70 = 0;
  local_78 = 0;
  iVar26 = 0;
  bVar8 = *(byte *)(param_1 + 0x2f8) & 1;
  if (param_7 == '\0') {
    uVar5 = *(ushort *)(param_1 + 0x2e0);
    uVar24 = 0x14;
    if (*param_5 != 1) {
      uVar24 = 0x10;
    }
    if (bVar8 == 0) {
      uVar23 = 8;
      param_7 = '\x02';
      param_5._0_4_ = 0x30000000;
    }
    else {
      uVar24 = uVar24 | 2;
      param_7 = '\x03';
      uVar23 = 0xc;
      param_5._0_4_ = 0x32000000;
    }
  }
  else {
    param_7 = '\x04';
    uVar24 = 0;
    param_5._0_4_ = 0x80000000;
    uVar5 = *(ushort *)(param_1 + 0x2e4);
    uVar23 = 0x10;
  }
  uVar1 = psVar2[1];
  puVar12 = param_3 + uVar1;
  iVar18 = (int)uVar23;
  local_6c = (uint)((((uint)*(ushort *)(param_1 + 0x2ea) + (uint)uVar1 * -4) - iVar18) / uVar23);
  puVar7 = (uint *)StorPortGetScatterGatherList(param_1,param_2);
  uVar20 = param_6 - *(int *)(param_2 + 0x40);
  uVar15 = puVar7[6];
  uVar19 = *puVar7;
  puVar7 = puVar7 + 4;
  puVar11 = puVar7;
  if (uVar15 <= uVar20) {
    do {
      puVar7 = puVar11 + 6;
      uVar20 = uVar20 - uVar15;
      uVar19 = uVar19 - 1;
      uVar15 = puVar11[8];
      puVar11 = puVar7;
    } while (uVar15 <= uVar20);
  }
  uVar22 = *(uint *)(psVar2 + 2);
  uVar15 = 0;
  iVar14 = 0;
  puVar11 = puVar7;
  if (uVar19 != 0) {
    do {
      uVar10 = puVar11[2] - uVar20;
      if (puVar11 != puVar7) {
        uVar10 = puVar11[2];
      }
      uVar6 = uVar22;
      iVar4 = uVar10 - uVar22;
      if (uVar10 <= uVar22) {
        uVar6 = uVar10;
        iVar4 = iVar14;
      }
      iVar14 = iVar4;
      uVar22 = uVar22 - uVar6;
      if (uVar22 == 0) break;
      uVar15 = uVar15 + 1;
      puVar11 = puVar11 + 6;
    } while (uVar15 < uVar19);
    local_78 = iVar14;
  }
  uVar15 = uVar15 + 1;
  uVar19 = *(uint *)(param_1 + 0x650);
  if (uVar19 < uVar15) {
    if (uVar15 - uVar19 == 0) {
      iVar26 = 0;
    }
    else {
      iVar26 = puVar7[(ulonglong)uVar19 * 6 + 2] * (uVar15 - uVar19);
    }
    iVar26 = iVar26 - local_78;
    uVar15 = uVar19;
  }
  puVar11 = puVar7;
  puVar25 = (uint *)0x0;
  uVar19 = local_6c;
  local_res20 = param_4;
  local_58 = param_3;
  if (uVar15 <= local_6c + 1) {
    uVar19 = uVar15;
    local_58 = param_3;
  }
  while( true ) {
    puVar13 = puVar12;
    uVar22 = 0;
    if (uVar19 != 0) {
      uVar16 = (ulonglong)uVar19;
      do {
        if (cVar3 == '\0') {
          uVar10 = puVar11[2] | uVar24 << 0x18;
          *puVar12 = uVar10;
          uVar22 = *puVar11;
          puVar12[1] = uVar22;
          if (bVar8 != 0) {
            puVar12[2] = puVar11[1];
          }
          if ((puVar11 == puVar7) && (uVar20 != 0)) {
            *puVar12 = uVar10 - uVar20;
            puVar12[1] = uVar22 + uVar20;
          }
        }
        else {
          uVar22 = *puVar11;
          *puVar12 = uVar22;
          puVar12[1] = puVar11[1];
          uVar10 = puVar11[2];
          puVar12[2] = uVar10;
          puVar12[3] = uVar24 << 0x18;
          if ((puVar11 == puVar7) && (uVar20 != 0)) {
            puVar12[2] = uVar10 - uVar20;
            *puVar12 = uVar22 + uVar20;
          }
        }
        puVar12 = (uint *)((longlong)puVar12 + uVar23);
        puVar11 = puVar11 + 6;
        uVar16 = uVar16 - 1;
        puVar13 = puVar12;
        uVar22 = uVar19;
      } while (uVar16 != 0);
    }
    local_70 = local_70 + uVar22;
    if (uVar15 <= local_70) break;
    if (cVar3 == '\0') {
      *(uint *)((longlong)puVar13 - uVar23) = *(uint *)((longlong)puVar13 - uVar23) | 0x80000000;
    }
    if (local_70 == local_6c) {
      lVar17 = (longlong)puVar13 - (longlong)local_58 >> 2;
      uVar9 = (char)((longlong)
                     (lVar17 + (ulonglong)
                               ((uint)((longlong)puVar13 - (longlong)local_58 >> 0x3f) & 3)) >> 2);
      if (cVar3 == '\0') {
        uVar9 = (char)lVar17;
      }
      *(undefined1 *)((longlong)param_3 + 2) = uVar9;
      local_6c = (uint)uVar5;
    }
    if (puVar25 != (uint *)0x0) {
      cVar21 = (char)uVar22;
      if (cVar3 == '\0') {
        local_60._0_1_ = (char)uVar23;
        *(char *)((longlong)puVar25 + 2) = param_7 * cVar21;
        *(ushort *)puVar25 = (ushort)(byte)((cVar21 + '\x01') * (char)local_60);
      }
      else {
        *(char *)((longlong)puVar25 + 0xe) = cVar21;
        puVar25[2] = (uVar22 + 1) * iVar18;
      }
    }
    puVar12 = (uint *)((longlong)local_58 + (ulonglong)*(ushort *)(param_1 + 0x2ea));
    local_res20 = local_res20 + *(ushort *)(param_1 + 0x2ea);
    if (cVar3 == '\0') {
      *puVar13 = (uint)param_5;
      puVar13[1] = local_res20;
      if (bVar8 != 0) {
        puVar13[2] = *(uint *)(param_1 + 0x1ec);
      }
    }
    else {
      *puVar13 = local_res20;
      puVar13[1] = *(uint *)(param_1 + 0x1ec);
      puVar13[3] = (uint)param_5;
    }
    puVar25 = puVar13;
    uVar19 = uVar15 - local_70;
    local_58 = puVar12;
    if (local_6c + 1 < uVar15 - local_70) {
      uVar19 = local_6c;
    }
  }
  puVar13 = (uint *)((longlong)puVar13 - uVar23);
  if (cVar3 == '\0') {
    uVar24 = *puVar13;
    *puVar13 = uVar24 | 0xc1000000;
    if (local_78 != 0) {
      *puVar13 = (uVar24 | 0xc1000000) - local_78;
    }
    if (puVar25 != (uint *)0x0) {
      local_60 = (short)uVar23;
      *(undefined1 *)((longlong)puVar25 + 2) = 0;
      *(ushort *)puVar25 = local_60 * (short)uVar22 & 0xff;
    }
  }
  else {
    puVar13[3] = puVar13[3] | 0x40000000;
    if (local_78 != 0) {
      puVar13[2] = puVar13[2] - local_78;
    }
    if (puVar25 != (uint *)0x0) {
      *(undefined1 *)((longlong)puVar25 + 0xe) = 0;
      puVar25[2] = uVar22 * iVar18;
    }
  }
  return iVar26;
}



===== CheckForIRShutdown @ 140009e80 =====

ulonglong CheckForIRShutdown(longlong param_1,char param_2,int param_3)

{
  undefined1 *puVar1;
  ulonglong uVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  uint uVar5;
  uint local_res8 [2];
  uint local_res20 [2];
  
  uVar2 = (ulonglong)*(uint *)(param_1 + 0xeb4);
  if ((*(uint *)(param_1 + 0xeb4) >> 0xc & 1) != 0) {
    uVar2 = GetIrMapRange(param_1,(int *)local_res8,local_res20);
    if (local_res8[0] <= local_res20[0]) {
      do {
        uVar2 = (ulonglong)local_res8[0];
        if (*(short *)(*(longlong *)(param_1 + 0x378) + 0x1a + uVar2 * 0x28) != 0) {
          puVar1 = *(undefined1 **)(param_1 + 0x608);
          *(undefined8 *)(puVar1 + 1) = 0;
          *(undefined8 *)(puVar1 + 9) = 0;
          *(undefined8 *)(puVar1 + 0x11) = 0;
          *(undefined4 *)(puVar1 + 0x19) = 0;
          *(undefined2 *)(puVar1 + 0x1d) = 0;
          puVar1[0x1f] = 0;
          puVar1[3] = 0x15;
          *puVar1 = 0x20;
          *(undefined1 *)(param_1 + 0xe6a) = 1;
          **(int **)(param_1 + 0xe8) = (uint)*(ushort *)(param_1 + 0x66a) * 0x10000 + 8;
          LOCK();
          UNLOCK();
          puVar3 = *(undefined4 **)(param_1 + 0xf0);
          uVar5 = 0;
          *puVar3 = 0;
          LOCK();
          UNLOCK();
          if (param_2 != '\0') goto LAB_140009f80;
          *(undefined4 *)(param_1 + 0x634) = 6;
          goto LAB_140009f6d;
        }
        local_res8[0] = local_res8[0] + 1;
      } while (local_res8[0] <= local_res20[0]);
    }
  }
  return uVar2 & 0xffffffffffffff00;
  while( true ) {
    puVar3 = (undefined4 *)StorPortStallExecution(500);
    uVar5 = uVar5 + 1;
    if (9999 < uVar5) break;
LAB_140009f80:
    puVar3 = (undefined4 *)PollLSImpiIsr(param_1,param_3);
    if (*(char *)(param_1 + 0xe6a) == '\0') break;
  }
  if (uVar5 == 10000) {
    uVar4 = LogSystemEvent(param_1,0xad010070,0x8004af01,
                           (byte *)"No reply was received for a RAID Action System Shutdown msg",
                           param_3);
    return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
  }
LAB_140009f6d:
  return CONCAT71((int7)((ulonglong)puVar3 >> 8),1);
}



===== CheckInqFlagReplies @ 140009fe0 =====

ulonglong CheckInqFlagReplies(longlong param_1,undefined1 *param_2,byte *param_3,int param_4)

{
  char cVar1;
  longlong lVar2;
  ushort *puVar3;
  int *piVar4;
  char *pcVar5;
  char cVar6;
  uint uVar7;
  undefined8 uVar8;
  int *piVar9;
  ulonglong uVar10;
  byte bVar11;
  undefined1 uVar12;
  byte bVar13;
  size_t _Size;
  undefined8 *puVar14;
  undefined1 *puVar15;
  bool bVar16;
  bool bVar17;
  bool bVar18;
  bool local_res8;
  undefined8 in_stack_ffffffffffffff78;
  undefined4 uVar20;
  undefined1 *puVar19;
  char local_68;
  byte local_67;
  ushort local_66;
  uint local_64;
  uint local_60;
  int *local_58;
  longlong local_50;
  
  uVar20 = (undefined4)((ulonglong)in_stack_ffffffffffffff78 >> 0x20);
  cVar1 = *(char *)(param_1 + 0xeb2);
  puVar15 = (undefined1 *)0x0;
  local_66 = *(ushort *)(param_3 + 2);
  puVar14 = (undefined8 *)((ulonglong)local_66 * 0x20 + *(longlong *)(param_1 + 0x350));
  if ((*(uint *)(puVar14 + 3) & 4) == 0) {
    return (ulonglong)(*(uint *)(puVar14 + 3) & 0xffffff00);
  }
  bVar16 = (*param_3 & 0xf) != 1;
  if (!bVar16) {
    puVar15 = (undefined1 *)((ulonglong)*(uint *)(param_3 + 4) + *(longlong *)(param_1 + 0x100));
  }
  *param_2 = 1;
  lVar2 = puVar14[1];
  if (lVar2 == 0) {
    uVar8 = LogSystemEvent(param_1,0xad010024,0xc004af02,
                           (byte *)"NULL Srb when Inquiry reply processed",param_4);
    return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
  }
  local_60 = *(uint *)(lVar2 + 0x3c);
  puVar3 = (ushort *)*puVar14;
  local_68 = (char)puVar3[0x20];
  piVar4 = *(int **)(lVar2 + 0x68);
  local_67 = *(byte *)((longlong)puVar3 + 0x41);
  if (*(char *)(lVar2 + 3) == '\0') {
    *(undefined1 *)(*(longlong *)(piVar4 + 0x10) + 8) = 0;
    *(undefined1 *)(lVar2 + 3) = 1;
  }
  local_58 = piVar4;
  piVar9 = (int *)StorPortGetLogicalUnit
                            (param_1,*(undefined1 *)((longlong)piVar4 + 0x5a),
                             *(undefined1 *)((longlong)piVar4 + 0x5b),(char)piVar4[0x17]);
  puVar19 = (undefined1 *)CONCAT44(uVar20,param_4);
  local_50 = FindMappingTableEntry
                       (param_1,(ushort)*(byte *)((longlong)piVar4 + 0x5a),
                        (ushort)*(byte *)((longlong)piVar4 + 0x5b),0xffffffff);
  if (local_50 == 0) {
    *(undefined1 *)(lVar2 + 3) = 10;
    param_2 = (undefined1 *)StorPortNotification(0,param_1,lVar2,0,puVar19);
    goto LAB_14000a68d;
  }
  pcVar5 = *(char **)(lVar2 + 0x40);
  local_64 = CONCAT31((uint3)(*(uint *)(param_1 + 0xeb4) >> 0x13),
                      (char)(*(uint *)(param_1 + 0xeb4) >> 0xb)) & 0xffffff01;
  bVar17 = *(char *)(param_1 + 0xe97) != '\0';
  if (local_68 == '\x12') {
    if ((local_67 & 1) != 0) {
      if ((bVar16) ||
         ((((*(ushort *)(puVar15 + 0xe) & 0x7fff) == 0 ||
           ((*(ushort *)(puVar15 + 0xe) & 0x7fff) == 0x45)) && (puVar15[0xc] == '\0')))) {
        bVar13 = pcVar5[3];
        if (0x16 < bVar13) {
          bVar13 = 0x16;
        }
        uVar10 = 0;
        if (bVar13 != 0) {
          do {
            if (pcVar5[uVar10 + 4] == -0x70) goto LAB_14000a60c;
            bVar11 = (char)uVar10 + 1;
            uVar10 = (ulonglong)bVar11;
          } while (bVar11 < bVar13);
        }
      }
      if ((*(uint *)(local_50 + 0x14) >> 0x1e & 1) == 0) {
        uVar10 = 0;
        do {
          bVar13 = (byte)uVar10;
          if (*(char *)((longlong)piVar9 + uVar10 + 0xe) != (&vendorHP)[uVar10]) break;
          bVar13 = bVar13 + 1;
          uVar10 = (ulonglong)bVar13;
        } while (bVar13 < 8);
        if (bVar13 == 8) {
          *(uint *)(local_50 + 0x14) = *(uint *)(local_50 + 0x14) | 0x40000000;
          puVar3[0x12] = 6;
          *(undefined8 *)((longlong)puVar3 + 0x41) = 0;
          *(undefined4 *)((longlong)puVar3 + 0x49) = 0;
          *(undefined2 *)((longlong)puVar3 + 0x4d) = 0;
          *(undefined1 *)((longlong)puVar3 + 0x4f) = 0;
          *(uint *)(puVar3 + 0x30) = *(uint *)(puVar3 + 0x30) & 0xff000000;
          puVar3[0x20] = 0x1c2;
          puVar3[0xe] = 0;
          puVar3[0xf] = 0;
          goto LAB_14000a5ae;
        }
      }
      goto LAB_14000a611;
    }
    if (bVar16) {
      bVar13 = 0;
      uVar12 = 1;
    }
    else {
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x2001) != 0)) {
        puVar19 = puVar15;
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x2001,puVar15,0x34,
                    param_4);
      }
      bVar13 = puVar15[0xc];
      uVar7 = bVar13 - 8;
      if ((uVar7 & 0xdf) == 0) {
        *(byte *)(*(longlong *)(local_58 + 0x10) + 8) = bVar13;
        *(undefined1 *)(lVar2 + 3) = 5;
        param_2 = (undefined1 *)StorPortNotification(0,param_1,lVar2,local_50,puVar19);
        goto LAB_14000a68d;
      }
      if (((puVar15[0xd] & 0x10) != 0) && (uVar7 = *(uint *)(puVar15 + 0x1c), (char)uVar7 == '\x02')
         ) {
        *(undefined1 *)(local_50 + 0x22) = 0;
        *(undefined4 *)(puVar14 + 3) = 0;
        return (ulonglong)(uVar7 & 0xffffff00);
      }
      uVar10 = (ulonglong)uVar7;
      if ((*(ushort *)(puVar15 + 0xe) & 0x7fff) == 0x45) {
        if ((puVar15[0xd] & 1) != 0) goto LAB_14000a463;
        uVar12 = 0x12;
        *(undefined4 *)(lVar2 + 0x3c) = *(undefined4 *)(puVar15 + 0x14);
      }
      else {
        uVar10 = 0xffbf;
        if (((*(ushort *)(puVar15 + 0xe) & 0x7fbf) != 0) || (bVar13 != 0)) goto LAB_14000a463;
        uVar12 = 1;
      }
    }
    if (pcVar5 == (char *)0x0) {
      bVar18 = false;
      local_res8 = false;
      uVar7 = 0;
    }
    else {
      cVar6 = *pcVar5;
      bVar18 = cVar6 == '\0';
      if (bVar18) {
        *(undefined1 *)(local_50 + 0x25) = 1;
        cVar6 = *pcVar5;
      }
      local_res8 = bVar18 && bVar17;
      bVar18 = bVar18 && bVar17;
      if ((cVar6 == '\x01') && ((*(uint *)(local_50 + 0x14) & 0x400) != 0)) {
        uVar7 = local_64;
      }
      else {
        uVar7 = 0;
      }
    }
    if (piVar9 != (int *)0x0) {
      if (bVar18) {
        *(undefined1 *)(piVar9 + 1) = 0;
      }
      *(undefined1 *)((longlong)piVar9 + 5) = 0;
    }
    *(byte *)(*(longlong *)(local_58 + 0x10) + 8) = bVar13;
    *(undefined1 *)(lVar2 + 3) = uVar12;
    uVar10 = (ulonglong)*(uint *)(local_50 + 0x14);
    if ((char)*(uint *)(local_50 + 0x14) < '\0') {
      uVar10 = StorPortSetDeviceQueueDepth
                         (param_1,*(undefined1 *)((longlong)local_58 + 0x5a),
                          *(undefined1 *)((longlong)local_58 + 0x5b),(char)local_58[0x17],
                          *(undefined4 *)(param_1 + 0x648));
    }
    if (piVar9 != (int *)0x0) {
      uVar10 = 0;
      if (((local_res8) || ((char)uVar7 != '\0')) && (0x19 < local_60)) {
        if ((!local_res8) || ((pcVar5[5] & 1U) == 0)) {
          if ((char)uVar7 == '\0') goto LAB_14000a624;
          *(undefined1 *)((longlong)puVar3 + 0x41) = 1;
          *(undefined2 *)((longlong)puVar3 + 0x43) = 0x1a00;
          uVar7 = 0x1a;
          memmove((void *)((longlong)piVar9 + 6),*(void **)(lVar2 + 0x40),0x1a);
          puVar3[0xe] = 0x1a;
          puVar3[0xf] = 0;
          if (cVar1 != '\0') goto LAB_14000a3a0;
          if ((*(uint *)(puVar3 + 0x30) & 0xffffff) < 0x1a) goto LAB_14000a3d7;
          *(uint *)(puVar3 + 0x30) = *(uint *)(puVar3 + 0x30) & 0xff00001a | 0x1a;
        }
        else {
          *(undefined8 *)((longlong)puVar3 + 0x41) = 0;
          *(undefined4 *)((longlong)puVar3 + 0x49) = 0;
          uVar7 = 0xe;
          *(undefined2 *)((longlong)puVar3 + 0x4d) = 0;
          *(undefined1 *)((longlong)puVar3 + 0x4f) = 0;
          puVar3[0x20] = 0x109e;
          *(undefined1 *)((longlong)puVar3 + 0x4d) = 0xe;
          memmove((void *)((longlong)piVar9 + 6),*(void **)(lVar2 + 0x40),0xe);
          puVar3[0xe] = 0xe;
          puVar3[0xf] = 0;
          puVar3[0x12] = puVar3[0x12] & 0xfe10 | 0x10;
          if (cVar1 == '\0') {
            if ((*(uint *)(puVar3 + 0x30) & 0xffffff) < 0xe) {
LAB_14000a3d7:
              uVar10 = (ulonglong)(*(ushort *)(param_1 + 0x2f8) & 1) | 2;
              *(uint *)(puVar3 + uVar10 * 2 + 0x30) =
                   *(uint *)(puVar3 + uVar10 * 2 + 0x30) & 0xff000000;
              *(uint *)(puVar3 + uVar10 * 2 + 0x30) =
                   *(uint *)(puVar3 + uVar10 * 2 + 0x30) |
                   uVar7 - (*(uint *)(puVar3 + 0x30) & 0xffffff);
            }
            else {
              *(uint *)(puVar3 + 0x30) = *(uint *)(puVar3 + 0x30) & 0xff00000e | 0xe;
            }
          }
          else {
LAB_14000a3a0:
            if (*(uint *)(puVar3 + 0x34) < uVar7) {
              *(uint *)(puVar3 + 0x3c) = uVar7 - *(uint *)(puVar3 + 0x34);
            }
            else {
              *(uint *)(puVar3 + 0x34) = uVar7;
            }
          }
        }
LAB_14000a5ae:
        QueueRequestDescriptor
                  (param_1,(uint)local_66 * 0x10000 + *local_58,(uint)*puVar3 << 0x10,param_4);
        *param_2 = 0;
        goto LAB_14000a68d;
      }
    }
    if (!bVar16) {
LAB_14000a463:
      *(undefined4 *)(puVar14 + 3) = 0;
      return uVar10 & 0xffffffffffffff00;
    }
  }
  else {
    if (local_68 == -0x62) {
      if (bVar16) {
        if ((pcVar5[0xc] & 1U) != 0) {
          *(undefined1 *)(piVar9 + 1) = 1;
          *piVar9 = (uint)(byte)pcVar5[8] * 0x1000000 + (uint)(byte)pcVar5[9] * 0x10000 +
                    (uint)(byte)pcVar5[10] * 0x100 + (uint)(byte)pcVar5[0xb];
        }
        _Size = 0xe;
      }
      else {
        *(char *)((longlong)piVar9 + 5) = *(char *)((longlong)piVar9 + 5) + '\x01';
        if (*(byte *)((longlong)piVar9 + 5) < 4) goto LAB_14000a5ae;
        _Size = 0xe;
      }
    }
    else {
      if (local_68 != -0x3e) {
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x205) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x205,&local_68,1,
                      param_4);
        }
        *param_2 = 1;
        goto LAB_14000a68d;
      }
      if (bVar16) {
LAB_14000a60c:
        *(undefined1 *)(local_50 + 0x22) = 0x40;
      }
      else {
        *(char *)((longlong)piVar9 + 5) = *(char *)((longlong)piVar9 + 5) + '\x01';
        if (*(byte *)((longlong)piVar9 + 5) < 2) goto LAB_14000a5ae;
        LogSystemEvent(param_1,0xad010033,0xc004af02,(byte *)"SAS tape drive TLR enable failed",
                       param_4);
      }
LAB_14000a611:
      _Size = 0x1a;
    }
    memmove(*(void **)(lVar2 + 0x40),(void *)((longlong)piVar9 + 6),_Size);
  }
LAB_14000a624:
  param_2 = (undefined1 *)StorPortNotification(0,param_1,lVar2);
LAB_14000a68d:
  return CONCAT71((int7)((ulonglong)param_2 >> 8),1);
}



===== CheckIoctlQueue @ 14000a6c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 CheckIoctlQueue(longlong param_1,int param_2)

{
  byte bVar1;
  void *pvVar2;
  char cVar3;
  undefined8 uVar4;
  undefined1 auStackY_78 [32];
  void *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStackY_78;
  uVar4 = 0;
  if ((((*(char *)(param_1 + 0x15a0) == '\0') && (*(int *)(param_1 + 0x628) == 0)) &&
      (*(char *)(param_1 + 0xe6a) == '\0')) && (*(int *)(param_1 + 0xec0) == 0)) {
    if (*(char *)(param_1 + 0x15a1) == '\0') {
      do {
        bVar1 = *(byte *)(param_1 + 0xf5e);
        pvVar2 = *(void **)(param_1 + 0xf68 + (ulonglong)bVar1 * 8);
        if (pvVar2 == (void *)0x0) {
          return uVar4;
        }
        *(undefined8 *)(param_1 + 0xf68 + (ulonglong)bVar1 * 8) = 0;
        cVar3 = '\0';
        if (bVar1 != 0x1f) {
          cVar3 = bVar1 + 1;
        }
        *(char *)(param_1 + 0xf5e) = cVar3;
        local_28 = *(undefined1 *)((longlong)pvVar2 + 3);
        local_30 = *(undefined4 *)(*(longlong *)((longlong)pvVar2 + 0x40) + 0x10);
        local_2c = *(undefined4 *)(*(longlong *)((longlong)pvVar2 + 0x40) + 0x14);
        local_38 = pvVar2;
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x400008) != 0))
        {
          RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x400008,
                      (undefined1 *)&local_38,0x11,param_2);
        }
        LsiHandleAppRequest(param_1,pvVar2,param_2);
        uVar4 = 1;
      } while (*(char *)(param_1 + 0xec8) == '\0');
    }
    else {
      *(undefined1 *)(param_1 + 0x15a1) = 0;
      if (*(int *)(param_1 + 0x630) == 0) {
        StorPortPause(param_1,300);
      }
      ResetActive(param_1,0xf,param_2);
      *(undefined1 *)(param_1 + 0x15a0) = 1;
      *(undefined1 *)(param_1 + 0x15a4) = 1;
      SasBcAsyncEvent(param_1,param_2);
    }
  }
  return uVar4;
}



===== CheckMpiIoctlReply @ 14000a860 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 CheckMpiIoctlReply(longlong param_1,byte *param_2,int param_3)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  longlong lVar4;
  bool bVar5;
  short *psVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  uint uVar9;
  longlong lVar10;
  uint *puVar11;
  int *piVar12;
  undefined4 uVar13;
  longlong lVar14;
  longlong lVar15;
  longlong lVar16;
  undefined1 auStackY_a8 [32];
  longlong local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined1 local_58;
  undefined4 local_50;
  undefined8 local_4c;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_a8;
  lVar16 = 0;
  local_58 = 0;
  lVar15 = 0;
  local_5c = 0;
  puVar11 = (uint *)(*(longlong *)(param_1 + 0x350) + 0x18 +
                    (ulonglong)*(ushort *)(param_2 + 2) * 0x20);
  uVar9 = *puVar11;
  if ((uVar9 & 1) == 0) {
    return (ulonglong)(uVar9 & 0xffffff00);
  }
  *puVar11 = 0;
  if ((*param_2 & 0xf) == 1) {
    lVar10 = (ulonglong)*(uint *)(param_2 + 4) + *(longlong *)(param_1 + 0x100);
    iVar3 = *(int *)(lVar10 + 0x10);
    if ((((iVar3 != 0) && (sVar2 = *(short *)(lVar10 + 0xe), sVar2 < 0)) &&
        (bVar5 = false, *(char *)(param_1 + 0x139a) != '\0')) &&
       (*(char *)(param_1 + 0xb350) != '\0')) {
      psVar6 = (short *)(param_1 + 0xb404);
      uVar9 = 0;
      if (*(uint *)(param_1 + 0xb400) != 0) {
        do {
          if (bVar5) goto LAB_14000a95e;
          if ((*psVar6 == sVar2) &&
             ((*(int *)(psVar6 + 2) == 0xffff || (*(int *)(psVar6 + 2) == iVar3)))) {
            bVar5 = true;
          }
          uVar9 = uVar9 + 1;
          psVar6 = psVar6 + 4;
        } while (uVar9 < *(uint *)(param_1 + 0xb400));
        if (bVar5) {
LAB_14000a95e:
          local_4c = CONCAT62(local_4c._2_6_,sVar2);
          local_50 = 4;
          local_4c = CONCAT44(iVar3,(undefined4)local_4c);
          SendMpiEventToApplication(param_1,0x6e,&local_50,0xc);
        }
      }
    }
    bVar5 = false;
  }
  else {
    bVar5 = true;
    lVar10 = 0;
  }
  if ((*(char *)(param_1 + 0xec8) == '\0') && (*(longlong *)(param_1 + 0xed0) == 0)) {
LAB_14000ab12:
    if (bVar5) goto LAB_14000abe2;
  }
  else {
    lVar16 = *(longlong *)(param_1 + 0xed0);
    piVar12 = (int *)(param_1 + 0xee0);
    uVar9 = 0;
    lVar14 = lVar16 - (longlong)piVar12;
    local_60 = *(undefined4 *)(*(longlong *)(lVar16 + 0x40) + 0x10);
    lVar4 = *(longlong *)(lVar16 + 0x68);
    do {
      iVar3 = *piVar12;
      piVar1 = (int *)(lVar14 + (longlong)piVar12);
      piVar12 = piVar12 + 1;
      local_68 = lVar16;
      if (iVar3 != *piVar1) {
        if ((*(char *)(param_1 + 0x3b8) == '\0') || ((*(uint *)(param_1 + 0x3bc) & 0x40000c) == 0))
        goto LAB_14000ab0b;
        uVar13 = 0x40000c;
        goto LAB_14000aade;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < 0x10);
    uVar9 = 0;
    piVar12 = *(int **)(param_1 + 0xf20);
    if (*(ushort *)(param_1 + 0x2ec) != 0) {
      lVar14 = lVar4 - (longlong)piVar12;
LAB_14000aa20:
      iVar3 = *piVar12;
      piVar1 = (int *)(lVar14 + 0x160 + (longlong)piVar12);
      piVar12 = piVar12 + 1;
      if (iVar3 == *piVar1) goto code_r0x00014000aa33;
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x40000d) != 0)) {
        uVar13 = 0x40000d;
LAB_14000aade:
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),uVar13,
                    (undefined1 *)&local_68,0x11,param_3);
      }
LAB_14000ab0b:
      *(undefined1 *)(param_1 + 0xec8) = 0;
      goto LAB_14000ab12;
    }
LAB_14000aa3a:
    lVar15 = *(longlong *)(lVar16 + 0x40);
    *(undefined4 *)(lVar15 + 0x14) = 0;
    if (bVar5) {
      *(undefined4 *)(lVar15 + 0x1c) = 0;
      goto LAB_14000ab12;
    }
    uVar9 = 0;
    if (*(char *)(lVar10 + 2) != '\0') {
      do {
        uVar7 = (ulonglong)uVar9;
        uVar9 = uVar9 + 1;
        *(undefined4 *)(uVar7 * 4 + 0x1c + lVar15) = *(undefined4 *)(uVar7 * 4 + lVar10);
      } while (uVar9 < *(byte *)(lVar10 + 2));
    }
    if (((*(char *)(lVar10 + 3) == '\0') || (*(char *)(lVar10 + 3) == '\x16')) &&
       ((*(byte *)(lVar10 + 0xd) & 1) != 0)) {
      memmove(*(void **)(param_1 + 0xf28),(void *)(lVar4 + 0x60),(ulonglong)*(uint *)(lVar10 + 0x18)
             );
    }
  }
  if ((*(char *)(lVar10 + 3) == '\x01') &&
     (((*(longlong *)(param_1 + 0x5e8) != 0 || (*(int *)(param_1 + 0xec0) != 0)) ||
      (uVar8 = CheckResetQueue(param_1,param_3), (char)uVar8 == '\0')))) {
    local_50 = *(undefined4 *)(param_1 + 0x628);
    local_4c = 0x40000005;
    if (((*(longlong *)(param_1 + 0x5e8) == 0) && (*(char *)(param_1 + 0x15a0) == '\0')) &&
       ((*(char *)(param_1 + 0xeb8) == '\0' && (*(int *)(param_1 + 0xf38) == 0)))) {
      *(undefined4 *)(param_1 + 0x628) = 0;
      local_4c = 0xffffffff40000005;
    }
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x20020) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x20020,
                  (undefined1 *)&local_50,0xc,param_3);
    }
    StorPortResume(param_1);
  }
LAB_14000abe2:
  if ((*(char *)(param_1 + 0xec8) == '\0') && (*(longlong *)(param_1 + 0xed0) == 0)) {
    CleanUpIoctl(param_1,param_3);
  }
  else {
    *(undefined1 *)(lVar16 + 3) = 1;
    local_58 = 1;
    if (lVar15 != 0) {
      local_5c = *(undefined4 *)(lVar15 + 0x14);
    }
    StorPortNotification(0,param_1,lVar16);
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x400023) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x400023,
                  (undefined1 *)&local_68,0x11,param_3);
    }
    *(undefined1 *)(param_1 + 0xec8) = 0;
    *(undefined8 *)(param_1 + 0xed0) = 0;
  }
  uVar8 = CheckIoctlQueue(param_1,param_3);
  return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
code_r0x00014000aa33:
  uVar9 = uVar9 + 1;
  if (*(ushort *)(param_1 + 0x2ec) <= uVar9) goto LAB_14000aa3a;
  goto LAB_14000aa20;
}



===== CheckPfaSataReplies @ 14000acc0 =====

longlong CheckPfaSataReplies(longlong param_1,undefined4 *param_2,int param_3)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  lVar3 = (ulonglong)*(ushort *)((longlong)param_2 + 2) * 0x20 + *(longlong *)(param_1 + 0x350);
  uVar1 = *(uint *)(lVar3 + 0x18);
  uVar2 = (ulonglong)uVar1;
  if ((uVar1 >> 8 & 1) == 0) {
    lVar3 = (ulonglong)(uint3)(uVar1 >> 8) << 8;
  }
  else {
    if (uVar1 == 0x100) {
      GtfStopTimer(param_1,*(byte *)(param_1 + 0xb4aa),param_3);
      *(undefined4 *)(param_1 + 0xb4b4) = *param_2;
      *(undefined4 *)(param_1 + 0xb4b8) = param_2[1];
      *(undefined4 *)(lVar3 + 0x18) = 0;
      uVar2 = DetectSataPfa(param_1,0,0,param_3);
    }
    lVar3 = CONCAT71((int7)(uVar2 >> 8),1);
  }
  return lVar3;
}



===== CheckResetQueue @ 14000ad50 =====

ulonglong CheckResetQueue(longlong param_1,int param_2)

{
  byte *pbVar1;
  undefined8 *puVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  ushort *puVar6;
  byte bVar7;
  undefined4 uVar8;
  ulonglong in_RAX;
  ulonglong uVar9;
  undefined8 uVar10;
  char cVar11;
  ushort uVar12;
  undefined1 local_res8 [8];
  
  if (*(longlong *)(param_1 + 0x5e8) == 0) {
    uVar9 = (ulonglong)*(byte *)(param_1 + 0xf60);
    puVar2 = (undefined8 *)(param_1 + 0x1068 + uVar9 * 8);
    lVar4 = *(longlong *)(param_1 + 0x1068 + uVar9 * 8);
    while (lVar4 != 0) {
      *puVar2 = 0;
      cVar11 = '\0';
      if ((char)uVar9 != 'c') {
        cVar11 = (char)uVar9 + '\x01';
      }
      *(char *)(param_1 + 0xf60) = cVar11;
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x20001) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x20001,
                    (undefined1 *)0x0,0,param_2);
      }
      if (lVar4 == -1) {
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x2001d) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x2001d,
                      (undefined1 *)0x0,0,param_2);
        }
      }
      else {
        lVar5 = *(longlong *)(lVar4 + 0x68);
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x20001) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x20001,
                      (undefined1 *)(lVar5 + 0x5a),3,param_2);
        }
        pbVar1 = (byte *)(lVar5 + 0x5a);
        uVar12 = (ushort)*pbVar1 * 0x80 + (ushort)*(byte *)(lVar5 + 0x5b);
        if (((uint)uVar12 < *(uint *)(param_1 + 0x678)) &&
           (uVar12 = *(ushort *)(*(longlong *)(param_1 + 0x378) + 0x1a + (ulonglong)uVar12 * 0x28),
           uVar12 != 0)) {
          ResetActive(param_1,0x10,param_2);
          *(longlong *)(param_1 + 0x5e8) = lVar4;
          uVar3 = *(uint *)(lVar4 + 0x14);
          uVar9 = (ulonglong)uVar3;
          if (uVar3 == 0x13) {
            puVar6 = *(ushort **)(param_1 + 800);
            puVar6[0] = 0;
            puVar6[1] = 0;
            puVar6[2] = 0;
            puVar6[3] = 0;
            puVar6[4] = 0;
            puVar6[5] = 0;
            puVar6[6] = 0;
            puVar6[7] = 0;
            puVar6[8] = 0;
            puVar6[9] = 0;
            puVar6[10] = 0;
            puVar6[0xb] = 0;
            puVar6[0xc] = 0;
            puVar6[0xd] = 0;
            puVar6[0xe] = 0;
            puVar6[0xf] = 0;
            puVar6[0x10] = 0;
            puVar6[0x11] = 0;
            puVar6[0x12] = 0;
            puVar6[0x13] = 0;
            puVar6[0x14] = 0;
            puVar6[0x15] = 0;
            puVar6[0x16] = 0;
            puVar6[0x17] = 0;
            puVar6[0x18] = 0;
            puVar6[0x19] = 0;
            *puVar6 = uVar12;
            *(undefined1 *)((longlong)puVar6 + 3) = 1;
            *(undefined1 *)((longlong)puVar6 + 5) = 3;
            QueueRequestDescriptor
                      (param_1,(uint)*(ushort *)(param_1 + 0x66e) * 0x10000 + 6,0,param_2);
            if ((*(char *)(param_1 + 0x3b8) != '\0') &&
               ((*(uint *)(param_1 + 0x3bc) & 0x20006) != 0)) {
              RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x20006,pbVar1,
                          3,param_2);
            }
            uVar9 = AfdMasterTrigger(param_1,4,param_2);
          }
          else if (uVar3 == 0x20) {
            lVar4 = *(longlong *)(lVar4 + 0x68);
            bVar7 = GtfStartTimer(param_1,1,2,LunResetTurTimeout,0,param_2);
            *(byte *)(param_1 + 0x769) = bVar7;
            if (((bVar7 == 0xfe) && (*(char *)(param_1 + 0x3b8) != '\0')) &&
               ((*(uint *)(param_1 + 0x3bc) & 0x233) != 0)) {
              RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x233,
                          (undefined1 *)0x0,0,param_2);
            }
            *(undefined4 *)
             ((ulonglong)*(ushort *)(param_1 + 0x66e) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x350)
             ) = 0x40;
            puVar6 = *(ushort **)(param_1 + 800);
            puVar6[1] = 0;
            puVar6[2] = 0;
            puVar6[3] = 0;
            *(undefined1 *)(puVar6 + 10) = 0x18;
            *puVar6 = uVar12;
            uVar8 = StorPortGetPhysicalAddress
                              (param_1,*(undefined8 *)(param_1 + 0x5e8),lVar4 + 0x60,local_res8);
            *(undefined1 *)(puVar6 + 9) = 0xff;
            *(undefined4 *)(puVar6 + 6) = uVar8;
            puVar6[0x12] = 6;
            BuildZeroLenSGE(param_1,(longlong)puVar6,*(int *)(param_1 + 0x200),'\x01');
            uVar9 = QueueRequestDescriptor
                              (param_1,(uint)*(ushort *)(param_1 + 0x66e) << 0x10,
                               (uint)*puVar6 << 0x10,param_2);
            if ((*(char *)(param_1 + 0x3b8) != '\0') &&
               (uVar9 = (ulonglong)*(uint *)(param_1 + 0x3bc),
               (*(uint *)(param_1 + 0x3bc) & 0x20008) != 0)) {
              uVar10 = RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),
                                   0x20008,(undefined1 *)(lVar4 + 0x5a),3,param_2);
              return CONCAT71((int7)((ulonglong)uVar10 >> 8),1);
            }
          }
          return CONCAT71((int7)(uVar9 >> 8),1);
        }
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x2001b) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x2001b,pbVar1,3,
                      param_2);
        }
        *(undefined1 *)(lVar4 + 3) = 4;
        StorPortNotification(0,param_1,lVar4);
      }
      uVar9 = (ulonglong)*(byte *)(param_1 + 0xf60);
      puVar2 = (undefined8 *)(param_1 + 0x1068 + uVar9 * 8);
      lVar4 = *(longlong *)(param_1 + 0x1068 + uVar9 * 8);
    }
    in_RAX = 0;
    if ((*(char *)(param_1 + 0x3b8) != '\0') &&
       (in_RAX = (ulonglong)*(uint *)(param_1 + 0x3bc), (*(uint *)(param_1 + 0x3bc) & 0x2001a) != 0)
       ) {
      in_RAX = RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x2001a,
                           (undefined1 *)0x0,0,param_2);
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== CheckSsuReplies @ 14000b1e0 =====

longlong CheckSsuReplies(longlong param_1,longlong param_2)

{
  uint uVar1;
  uint7 uVar2;
  
  uVar1 = *(uint *)((ulonglong)*(ushort *)(param_2 + 2) * 0x20 + 0x18 +
                   *(longlong *)(param_1 + 0x350));
  uVar2 = (uint7)((ulonglong)*(longlong *)(param_1 + 0x350) >> 8);
  if ((uVar1 & 0x10) == 0) {
    return (ulonglong)uVar2 << 8;
  }
  if (uVar1 == 0x10) {
    *(int *)(param_1 + 0xb318) = *(int *)(param_1 + 0xb318) + -1;
  }
  return CONCAT71(uVar2,1);
}



===== CheckSsuTmrReplies @ 14000b210 =====

longlong CheckSsuTmrReplies(longlong param_1,longlong param_2)

{
  uint uVar1;
  uint7 uVar2;
  
  uVar1 = *(uint *)((ulonglong)*(ushort *)(param_2 + 2) * 0x20 + 0x18 +
                   *(longlong *)(param_1 + 0x350));
  uVar2 = (uint7)((ulonglong)*(longlong *)(param_1 + 0x350) >> 8);
  if ((uVar1 & 0x20) == 0) {
    return (ulonglong)uVar2 << 8;
  }
  if (uVar1 == 0x20) {
    *(int *)(param_1 + 0xb318) = *(int *)(param_1 + 0xb318) + -1;
  }
  return CONCAT71(uVar2,1);
}



===== CheckTurReplies @ 14000b240 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 CheckTurReplies(longlong param_1,byte *param_2,int param_3)

{
  longlong lVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  longlong lVar6;
  longlong lVar7;
  uint7 extraout_var;
  ushort uVar8;
  ulonglong uVar9;
  longlong lVar10;
  undefined1 auStackY_98 [32];
  byte local_50;
  byte local_4f;
  char local_4e;
  ushort local_4c;
  undefined1 local_4a;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_98;
  local_4c = *(ushort *)(param_2 + 2);
  lVar10 = (ulonglong)local_4c * 0x20 + *(longlong *)(param_1 + 0x350);
  if ((*(uint *)(lVar10 + 0x18) & 0x40) == 0) {
    return (ulonglong)(*(uint *)(lVar10 + 0x18) & 0xffffff00);
  }
  *(undefined4 *)(lVar10 + 0x18) = 0;
  lVar6 = *(longlong *)(param_1 + 0x5e8);
  lVar7 = *(longlong *)(lVar6 + 0x68);
  cVar2 = *(char *)(lVar7 + 0x5c);
  bVar3 = *(byte *)(lVar7 + 0x5a);
  bVar4 = *(byte *)(lVar7 + 0x5b);
  local_50 = bVar3;
  local_4f = bVar4;
  local_4e = cVar2;
  if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x20009) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x20009,&local_50,8,
                param_3);
  }
  GtfStopTimer(param_1,*(byte *)(param_1 + 0x769),param_3);
  lVar1 = ((ulonglong)*(byte *)(lVar7 + 0x5a) * 0x80 + (ulonglong)*(byte *)(lVar7 + 0x5b)) * 0x28;
  if (((*param_2 & 0xf) == 1) &&
     ((*(byte *)((ulonglong)*(uint *)(param_2 + 4) + 0xd + *(longlong *)(param_1 + 0x100)) & 1) != 0
     )) {
    if ((byte)(*(char *)(lVar7 + 0x60) + 0x8eU) < 2) {
      local_4a = *(undefined1 *)(lVar7 + 99);
    }
    else {
      local_4a = *(undefined1 *)(lVar7 + 0x6d);
    }
    if (((((*(byte *)(lVar7 + 0x62) & 0xf) == 6) && (*(char *)(lVar7 + 0x6c) == ')')) ||
        (((*(byte *)(lVar7 + 0x61) & 0xf) == 6 && (*(byte *)(lVar7 + 0x62) == 0x29)))) &&
       ((*(char *)(param_1 + 0xe96) != '\0' &&
        ((*(uint *)(*(longlong *)(param_1 + 0x378) + 0x14 + lVar1) & 0x400) != 0)))) {
      *(undefined1 *)(lVar6 + 3) = 1;
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x2000a) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x2000a,&local_50,8,
                    param_3);
      }
      *(undefined8 *)(lVar10 + 8) = *(undefined8 *)(param_1 + 0x5e8);
      HandleUnitAttenReset
                (param_1,*(ushort *)(param_1 + 0x66e),*(undefined8 **)(param_1 + 800),bVar3,bVar4,
                 cVar2,'\x01',param_3);
      lVar10 = (ulonglong)extraout_var << 8;
      goto LAB_14000b542;
    }
  }
  uVar5 = *(ushort *)(param_1 + 0x654);
  uVar9 = 1;
  if (uVar5 != 0) {
    do {
      lVar10 = uVar9 * 0x20 + *(longlong *)(param_1 + 0x350);
      if ((*(longlong *)(lVar10 + 8) != 0) &&
         (*(short *)(lVar1 + 0x1a + *(longlong *)(param_1 + 0x378)) == *(short *)(lVar10 + 0x14))) {
        if ((ushort)uVar9 <= uVar5) {
          lVar10 = IssueLunReset(param_1,param_3);
          goto LAB_14000b542;
        }
        break;
      }
      uVar8 = (ushort)uVar9 + 1;
      uVar9 = (ulonglong)uVar8;
    } while (uVar8 <= uVar5);
  }
  *(undefined1 *)(lVar6 + 3) = 1;
  StorPortNotification(0,param_1,lVar6);
  if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x2000c) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x2000c,
                (undefined1 *)(lVar7 + 0x5a),3,param_3);
  }
  *(undefined8 *)(param_1 + 0x5e8) = 0;
  lVar10 = CheckResetQueue(param_1,param_3);
  if ((char)lVar10 == '\0') {
    ResetActive(param_1,0x40000006,param_3);
    lVar10 = StorPortResume(param_1);
    if (*(char *)(param_1 + 0xec8) == '\0') {
      lVar10 = CheckIoctlQueue(param_1,param_3);
    }
  }
LAB_14000b542:
  return CONCAT71((int7)((ulonglong)lVar10 >> 8),1);
}



===== CleanUpIoctl @ 14000b590 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void CleanUpIoctl(longlong param_1,int param_2)

{
  undefined1 auStackY_78 [32];
  longlong local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_28;
  int local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = *(longlong *)(param_1 + 0xed0);
  if (local_38 != 0) {
    local_30 = *(undefined4 *)(*(longlong *)(local_38 + 0x40) + 0x10);
    local_2c = *(undefined4 *)(*(longlong *)(local_38 + 0x40) + 0x14);
    local_28 = 4;
    *(undefined1 *)(local_38 + 3) = 4;
    local_20 = param_2;
    StorPortNotification(0,param_1);
    *(undefined8 *)(param_1 + 0xed0) = 0;
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x400024) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x400024,
                  (undefined1 *)&local_38,0x19,param_2);
    }
  }
  return;
}



===== ClearResetHistoryBit @ 14000b660 =====

void ClearResetHistoryBit(longlong param_1,int param_2)

{
  EnableDiagnosticRegister(param_1,param_2);
  **(uint **)(param_1 + 0x28) = **(uint **)(param_1 + 0x28) & 0xffffffdf;
  LOCK();
  UNLOCK();
  **(undefined4 **)(param_1 + 0x20) = 0;
  LOCK();
  UNLOCK();
  return;
}



===== CompleteAllSrbs @ 14000b6a0 =====

void CompleteAllSrbs(longlong param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  uint uVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined1 uVar6;
  bool bVar7;
  
  bVar7 = *(char *)(param_1 + 0xe79) == '\0';
  uVar2 = 0x11;
  if (bVar7) {
    uVar2 = 4;
  }
  uVar3 = 1;
  uVar6 = 0x11;
  if (bVar7) {
    uVar6 = 0xe;
  }
  if (*(short *)(param_1 + 0x654) != 0) {
    plVar5 = (longlong *)(*(longlong *)(param_1 + 0x350) + 0x28);
    do {
      if (*plVar5 != 0) {
        *(undefined1 *)(*plVar5 + 3) = uVar6;
        StorPortNotification(0,param_1);
        *plVar5 = 0;
      }
      plVar5 = plVar5 + 4;
      uVar3 = uVar3 + 1;
    } while (uVar3 <= *(ushort *)(param_1 + 0x654));
  }
  plVar5 = (longlong *)(param_1 + 0xf68);
  lVar4 = 0x20;
  do {
    if (*plVar5 != 0) {
      *(undefined1 *)(*plVar5 + 3) = uVar2;
      StorPortNotification(0,param_1);
      *plVar5 = 0;
    }
    plVar5 = plVar5 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  plVar5 = (longlong *)(param_1 + 0x1068);
  lVar4 = 100;
  do {
    lVar1 = *plVar5;
    if (lVar1 != 0) {
      if (*(longlong *)(param_1 + 0x5e8) == lVar1) {
        *(undefined8 *)(param_1 + 0x5e8) = 0;
      }
      if ((((*(int *)(lVar1 + 0x14) == 0x20) || (*(int *)(lVar1 + 0x14) == 0x13)) &&
          (*(int *)(lVar1 + 0x3c) == 0)) && (*(longlong *)(lVar1 + 0x40) == 0)) {
        *(undefined1 *)(lVar1 + 3) = uVar2;
        StorPortNotification(0,param_1);
      }
      *plVar5 = 0;
    }
    plVar5 = plVar5 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  lVar4 = *(longlong *)(param_1 + 0x5e8);
  if (lVar4 != 0) {
    if (((*(int *)(lVar4 + 0x14) == 0x20) || (*(int *)(lVar4 + 0x14) == 0x13)) &&
       ((*(int *)(lVar4 + 0x3c) == 0 && (*(longlong *)(lVar4 + 0x40) == 0)))) {
      *(undefined1 *)(lVar4 + 3) = uVar2;
      StorPortNotification(0,param_1);
    }
    *(undefined8 *)(param_1 + 0x5e8) = 0;
  }
  return;
}



===== DelayedIoctlTimeout @ 14000b810 =====

void DelayedIoctlTimeout(longlong param_1)

{
  *(undefined4 *)(param_1 + 0xec0) = 1;
  KickStart(param_1,9);
  *(undefined1 *)(param_1 + 0xeb9) = 0;
                    /* WARNING: Could not recover jumptable at 0x00014000b84e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification(6,param_1,WatchdogTimer,1000000);
  return;
}



===== DetectSataPfa @ 14000b860 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong DetectSataPfa(longlong param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  uint *puVar1;
  undefined4 *puVar2;
  longlong lVar3;
  undefined2 uVar4;
  undefined2 *puVar5;
  byte bVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined7 extraout_var;
  ushort uVar9;
  int iVar10;
  uint uVar11;
  ushort uVar12;
  undefined1 auStackY_98 [32];
  undefined2 local_58;
  undefined1 local_56;
  undefined1 local_54;
  undefined1 local_53;
  undefined2 local_52;
  undefined4 local_4c;
  undefined4 local_48;
  ulonglong local_38;
  
  uVar7 = __security_cookie ^ (ulonglong)auStackY_98;
  iVar10 = *(int *)(param_1 + 0xb4ac);
  local_38 = uVar7;
LAB_14000b8a0:
  while( true ) {
    while (iVar10 == 0) {
      *(undefined2 *)(param_1 + 0xb4b0) = 0;
      *(undefined8 *)(param_1 + 0xb4b4) = 0;
      *(undefined8 *)(param_1 + 0xb4c8) = 0;
      *(undefined4 *)(param_1 + 0xb4ac) = 1;
      iVar10 = 1;
    }
    if (iVar10 == 1) {
      uVar7 = (ulonglong)*(ushort *)(param_1 + 0xb4b0);
      uVar11 = *(uint *)(param_1 + 0x678);
      if (*(ushort *)(param_1 + 0xb4b0) < uVar11) goto LAB_14000bb10;
      goto LAB_14000bb7a;
    }
    if (iVar10 != 2) break;
    uVar12 = *(ushort *)(param_1 + 0xb4b0);
    lVar3 = *(longlong *)(param_1 + 0x378) + (ulonglong)uVar12 * 0x28;
    bVar6 = *(byte *)(param_1 + 0xb4b4) & 0xf;
    if (bVar6 == 0) {
LAB_14000ba1b:
      uVar7 = *(ulonglong *)(param_1 + 0xb4c0);
      if (*(char *)(uVar7 + 8) != ']') goto LAB_14000baaf;
      puVar1 = (uint *)(lVar3 + 0x14);
      *puVar1 = *puVar1 | 0x80000000;
      iVar10 = 3;
      *(undefined4 *)(param_1 + 0xb4ac) = 3;
    }
    else {
      if (bVar6 == 1) {
        uVar7 = (ulonglong)*(uint *)(param_1 + 0xb4b8) + *(longlong *)(param_1 + 0x100);
        uVar9 = *(ushort *)(uVar7 + 0xe) & 0x7fff;
        if (((uVar9 == 0) || (uVar9 == 0x45)) && (*(char *)(uVar7 + 0xc) == '\0'))
        goto LAB_14000ba1b;
      }
      else {
        uVar7 = LogSystemEvent(param_1,0xad010074,0xc004af02,(byte *)"Log Sense has failed",param_4)
        ;
        if ((*(char *)(param_1 + 0x3b8) != '\0') &&
           (uVar7 = (ulonglong)*(uint *)(param_1 + 0x3bc), (*(uint *)(param_1 + 0x3bc) & 0x244) != 0
           )) {
          uVar7 = RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x244,
                              (undefined1 *)(lVar3 + 0x1a),2,param_4);
        }
      }
      uVar12 = *(ushort *)(param_1 + 0xb4b0);
LAB_14000baaf:
      iVar10 = 1;
      *(ushort *)(param_1 + 0xb4b0) = uVar12 + 1;
      *(undefined4 *)(param_1 + 0xb4ac) = 1;
    }
  }
  if (iVar10 == 3) {
    local_58 = 0xffff;
    local_56 = 5;
    puVar2 = (undefined4 *)
             (*(longlong *)(param_1 + 0x378) + (ulonglong)*(ushort *)(param_1 + 0xb4b0) * 0x28);
    local_54 = *(undefined1 *)(*(longlong *)(param_1 + 0xb4c0) + 8);
    local_53 = *(undefined1 *)(*(longlong *)(param_1 + 0xb4c0) + 9);
    local_52 = *(undefined2 *)((longlong)puVar2 + 0x1a);
    local_4c = *puVar2;
    local_48 = puVar2[1];
    uVar7 = SendMpiEventToApplication(param_1,0xf,&local_58,0x1c);
    iVar10 = 4;
    *(undefined4 *)(param_1 + 0xb4ac) = 4;
    goto LAB_14000b8a0;
  }
  if (iVar10 == 4) {
    uVar4 = *(undefined2 *)
             (*(longlong *)(param_1 + 0x378) + 0x1a +
             (ulonglong)*(ushort *)(param_1 + 0xb4b0) * 0x28);
    puVar5 = *(undefined2 **)(param_1 + 0x318);
    *(undefined8 *)(puVar5 + 1) = 0;
    *(undefined8 *)(puVar5 + 5) = 0;
    *(undefined8 *)(puVar5 + 9) = 0;
    *(undefined4 *)(puVar5 + 0xd) = 0;
    *(undefined1 *)(puVar5 + 0xf) = 0;
    *(undefined1 *)((longlong)puVar5 + 0x1f) = 0;
    *puVar5 = uVar4;
    *(undefined2 *)((longlong)puVar5 + 3) = 0x18;
    *(undefined4 *)(puVar5 + 6) = 0x40;
    uVar7 = QueueRequestDescriptor
                      (param_1,(uint)*(ushort *)(param_1 + 0x66c) * 0x10000 + 8,0,param_4);
    *(short *)(param_1 + 0xb4b0) = *(short *)(param_1 + 0xb4b0) + 1;
    iVar10 = 1;
    *(undefined4 *)(param_1 + 0xb4ac) = 1;
    goto LAB_14000b8a0;
  }
  goto LAB_14000bc3a;
  while( true ) {
    uVar11 = *(uint *)(param_1 + 0x678);
    uVar12 = (short)uVar7 + 1;
    uVar7 = (ulonglong)uVar12;
    if (uVar11 <= uVar12) break;
LAB_14000bb10:
    lVar3 = *(longlong *)(param_1 + 0x378);
    uVar12 = *(ushort *)(lVar3 + 0x1a + uVar7 * 0x28);
    if ((((uVar12 != 0) && (*(char *)(lVar3 + 0x23 + uVar7 * 0x28) == '\0')) &&
        (iVar10 = *(int *)(lVar3 + 0x14 + uVar7 * 0x28), -1 < iVar10)) &&
       (((bVar6 = (byte)iVar10, (char)bVar6 < '\0' && ((bVar6 & 7) == 1)) &&
        (uVar8 = IssueLogSenseToSataDevice(param_1,uVar12,param_4), (char)uVar8 != '\0')))) {
      *(short *)(param_1 + 0xb4b0) = (short)uVar7;
      *(undefined4 *)(param_1 + 0xb4ac) = 2;
      uVar11 = *(uint *)(param_1 + 0x678);
      break;
    }
  }
LAB_14000bb7a:
  if (uVar11 <= (uint)uVar7) {
    *(undefined4 *)(param_1 + 0xb4ac) = 0;
    lVar3 = *(longlong *)(param_1 + 0xb4c8);
    if (lVar3 != 0) {
      *(undefined8 *)(lVar3 + 8) = 0;
      *(undefined4 *)(lVar3 + 0x18) = 0;
      **(longlong **)(param_1 + 0x5d8) = lVar3;
      *(longlong *)(param_1 + 0x5d8) = *(longlong *)(param_1 + 0x5d8) + 8;
      if (*(longlong *)(param_1 + 0x5d8) == *(longlong *)(param_1 + 0x5e0)) {
        *(undefined8 *)(param_1 + 0x5d8) = *(undefined8 *)(param_1 + 0x5c8);
      }
    }
    bVar6 = GtfStartTimer(param_1,1,300,DetectSataPfa,0,param_4);
    uVar7 = CONCAT71(extraout_var,bVar6);
    *(byte *)(param_1 + 0xb4ab) = bVar6;
    if (((bVar6 == 0xfe) && (*(char *)(param_1 + 0x3b8) != '\0')) &&
       (uVar7 = (ulonglong)*(uint *)(param_1 + 0x3bc), (*(uint *)(param_1 + 0x3bc) & 0x233) != 0)) {
      uVar7 = RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x233,
                          (undefined1 *)0x0,0,param_4);
    }
  }
LAB_14000bc3a:
  return uVar7 & 0xffffffffffffff00;
}



===== EnableDiagnosticRegister @ 14000bc60 =====

void EnableDiagnosticRegister(longlong param_1,int param_2)

{
  bool bVar1;
  char cVar2;
  
  bVar1 = true;
  **(undefined4 **)(param_1 + 0x20) = 0;
  LOCK();
  UNLOCK();
  **(undefined4 **)(param_1 + 0x20) = 0xf;
  LOCK();
  UNLOCK();
  **(undefined4 **)(param_1 + 0x20) = 4;
  LOCK();
  UNLOCK();
  **(undefined4 **)(param_1 + 0x20) = 0xb;
  LOCK();
  UNLOCK();
  **(undefined4 **)(param_1 + 0x20) = 2;
  LOCK();
  UNLOCK();
  **(undefined4 **)(param_1 + 0x20) = 7;
  LOCK();
  UNLOCK();
  **(undefined4 **)(param_1 + 0x20) = 0xd;
  LOCK();
  UNLOCK();
  StorPortStallExecution(900);
  cVar2 = (char)**(undefined4 **)(param_1 + 0x28);
  while ((-1 < cVar2 &&
         (LogSystemEvent(param_1,0xad010029,0xc004af02,
                         (byte *)"Write Sequence to enable Diag Register access failed",param_2),
         bVar1))) {
    bVar1 = false;
    **(undefined4 **)(param_1 + 0x20) = 0;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0x20) = 0xf;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0x20) = 4;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0x20) = 0xb;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0x20) = 2;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0x20) = 7;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0x20) = 0xd;
    LOCK();
    UNLOCK();
    StorPortStallExecution(900);
    cVar2 = (char)**(undefined4 **)(param_1 + 0x28);
  }
  return;
}



===== EnableDisableEvents @ 14000bdc0 =====

ulonglong EnableDisableEvents(longlong param_1,char param_2,int param_3)

{
  undefined8 *puVar1;
  undefined4 *puVar2;
  ulonglong uVar3;
  uint uVar4;
  
  puVar1 = *(undefined8 **)(param_1 + 0x608);
  uVar4 = 0;
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  *(undefined4 *)(puVar1 + 5) = 0;
  *(undefined1 *)((longlong)puVar1 + 3) = 7;
  if (param_2 == '\0') {
    *(undefined8 *)((longlong)puVar1 + 0x14) = 0xffffffffffffffff;
    *(undefined8 *)((longlong)puVar1 + 0x1c) = 0xffffffffffffffff;
  }
  *(undefined1 *)(param_1 + 0xe69) = 1;
  **(int **)(param_1 + 0xe8) = (uint)*(ushort *)(param_1 + 0x66a) * 0x10000 + 8;
  LOCK();
  UNLOCK();
  puVar2 = *(undefined4 **)(param_1 + 0xf0);
  *puVar2 = 0;
  LOCK();
  UNLOCK();
  if (param_2 != '\0') {
    while( true ) {
      puVar2 = (undefined4 *)PollLSImpiIsr(param_1,param_3);
      if (*(char *)(param_1 + 0xe69) == '\0') break;
      StorPortStallExecution(500);
      uVar4 = uVar4 + 1;
      if (9999 < uVar4) {
        uVar3 = LogSystemEvent(param_1,0xad01003e,0xc004af02,
                               (byte *)"No Event Enable Reply Received",param_3);
        return uVar3 & 0xffffffffffffff00;
      }
    }
  }
  return CONCAT71((int7)((ulonglong)puVar2 >> 8),1);
}



===== FwDiagPostImmediateBuffers @ 14000beb0 =====

undefined8 FwDiagPostImmediateBuffers(longlong param_1,int param_2)

{
  int *piVar1;
  longlong lVar2;
  undefined1 *puVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  char cVar7;
  byte bVar8;
  ushort uVar9;
  undefined1 *puVar10;
  
  uVar6 = 0;
  do {
    uVar4 = uVar6;
    cVar7 = (char)uVar4;
    lVar2 = uVar4 * 3 + 0x271;
    piVar1 = (int *)(param_1 + lVar2 * 8);
    if ((*(char *)(param_1 + 0x10 + lVar2 * 8) != '\0') &&
       ((*(char *)((longlong)piVar1 + 0xf) != '\0' || (*(char *)((longlong)piVar1 + 0x12) != '\0')))
       ) {
      *(undefined1 *)(param_1 + 0xe83) = 1;
      if ((char)piVar1[4] == '\0') {
        uVar5 = 0;
        goto LAB_14000bfed;
      }
      puVar3 = *(undefined1 **)(param_1 + 0x608);
      *(undefined1 *)((longlong)piVar1 + 0xe) = 0;
      if (*(ushort *)(param_1 + 0x2ea) != 0) {
        puVar10 = puVar3;
        for (uVar6 = (ulonglong)*(ushort *)(param_1 + 0x2ea); uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar10 = 0;
          puVar10 = puVar10 + 1;
        }
      }
      puVar3[1] = (char)piVar1[3];
      puVar3[3] = 0x1d;
      *puVar3 = *(undefined1 *)((longlong)piVar1 + 0xd);
      *(int *)(puVar3 + 0x14) = piVar1[2];
      memmove(puVar3 + 0x24,(void *)(param_1 + 0x13d0),0x28);
      *(undefined4 *)(puVar3 + 0x10) = *(undefined4 *)(param_1 + 0x1ec);
      *(int *)(puVar3 + 0xc) = *piVar1 - *(int *)(param_1 + 0x100);
      QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x66a) * 0x10000 + 8,0,param_2);
      uVar9 = 0;
      do {
        uVar4 = PollLSImpiIsr(param_1,param_2);
        if ((char)uVar4 == '\0') {
          uVar4 = StorPortStallExecution(500);
        }
        else if (*(char *)(param_1 + 0xe83) == '\0') break;
        uVar9 = uVar9 + 1;
      } while (uVar9 < 4000);
    }
    bVar8 = cVar7 + 1;
    uVar6 = (ulonglong)bVar8;
  } while (bVar8 < 3);
  uVar5 = CONCAT71((int7)(uVar4 >> 8),1);
LAB_14000bfed:
  *(undefined1 *)(param_1 + 0xe83) = 0;
  return uVar5;
}



===== GetCimData @ 14000c020 =====

void GetCimData(longlong param_1,longlong param_2,uint param_3)

{
  *(undefined4 *)(param_1 + 0xe04) = 0;
  *(uint *)(param_1 + 0xe08) = (uint)*(ushort *)(param_2 + 2);
  *(uint *)(param_1 + 0xe0c) = (uint)*(byte *)(param_2 + 8);
  *(uint *)(param_1 + 0xe10) = (uint)*(ushort *)(param_2 + 0x2e);
  *(uint *)(param_1 + 0xe14) = (uint)*(ushort *)(param_2 + 0x2c);
  memmove((void *)(param_1 + 0xe24),&driver_version,0x15);
  *(uint *)(param_1 + 0xe4c) = param_3 >> 0x10 & 0xff;
  *(uint *)(param_1 + 0xe48) = param_3 & 0xffff;
  if (*(int *)(param_1 + 0xe14) == 0x1014) {
    *(undefined1 *)(param_1 + 0xe6c) = 1;
  }
  return;
}



===== HandleAfdTriggerIoctl @ 14000c0b0 =====

undefined8 HandleAfdTriggerIoctl(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  longlong lVar4;
  byte bVar5;
  ulonglong uVar6;
  
  *(undefined4 *)(param_2 + 0x14) = 0;
  memmove((void *)(param_2 + 0x1c),&AutoFwDiagBuffRecordVersion,4);
  iVar1 = *(int *)(param_2 + 0x20);
  if (iVar1 < 0) {
LAB_14000c445:
    *(undefined4 *)(param_2 + 0x14) = 2;
  }
  else {
    if (iVar1 < 3) {
      if (0xaf < *(uint *)(param_2 + 0x18)) {
        if (iVar1 == 0) {
          iVar1 = *(int *)(param_2 + 0x24);
          if (iVar1 == 1) {
            *(undefined4 *)(param_1 + 0xb354) = *(undefined4 *)(param_2 + 0x28);
            return 1;
          }
          if (iVar1 == 2) {
            if (*(int *)(param_2 + 0x28) - 1U < 0x14) {
              uVar6 = 0;
              *(int *)(param_1 + 0xb358) = *(int *)(param_2 + 0x28);
              if (*(int *)(param_2 + 0x28) == 0) {
                return 1;
              }
              do {
                bVar5 = (char)uVar6 + 1;
                *(undefined4 *)(param_1 + 0xb35c + uVar6 * 4) =
                     *(undefined4 *)(param_2 + 0x2c + uVar6 * 4);
                uVar6 = (ulonglong)bVar5;
              } while ((uint)bVar5 < *(uint *)(param_2 + 0x28));
              return 1;
            }
          }
          else if (iVar1 == 3) {
            if (*(int *)(param_2 + 0x28) - 1U < 0x14) {
              uVar6 = 0;
              *(int *)(param_1 + 0xb3ac) = *(int *)(param_2 + 0x28);
              if (*(int *)(param_2 + 0x28) == 0) {
                return 1;
              }
              do {
                bVar5 = (char)uVar6 + 1;
                *(undefined4 *)(param_1 + 46000 + uVar6 * 4) =
                     *(undefined4 *)(param_2 + 0x2c + uVar6 * 4);
                uVar6 = (ulonglong)bVar5;
              } while ((uint)bVar5 < *(uint *)(param_2 + 0x28));
              return 1;
            }
          }
          else {
            if (iVar1 != 4) goto LAB_14000c16d;
            if (*(int *)(param_2 + 0x28) - 1U < 0x14) {
              uVar6 = 0;
              *(int *)(param_1 + 0xb400) = *(int *)(param_2 + 0x28);
              if (*(int *)(param_2 + 0x28) == 0) {
                return 1;
              }
              do {
                bVar5 = (char)uVar6 + 1;
                *(undefined8 *)(uVar6 * 8 + 0xb404 + param_1) =
                     *(undefined8 *)(uVar6 * 8 + 0x2c + param_2);
                uVar6 = (ulonglong)bVar5;
              } while ((uint)bVar5 < *(uint *)(param_2 + 0x28));
              return 1;
            }
          }
          *(undefined4 *)(param_2 + 0x14) = 4;
          return 0;
        }
        if (iVar1 == 1) {
          iVar1 = *(int *)(param_2 + 0x24);
          if (iVar1 == 1) {
            *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(param_1 + 0xb354);
            return 1;
          }
          if (iVar1 == 2) {
            iVar1 = *(int *)(param_1 + 0xb358);
            *(int *)(param_2 + 0x28) = iVar1;
            uVar6 = 0;
            if (iVar1 == 0) {
              return 1;
            }
            do {
              bVar5 = (char)uVar6 + 1;
              *(undefined4 *)(param_2 + 0x2c + uVar6 * 4) =
                   *(undefined4 *)(param_1 + 0xb35c + uVar6 * 4);
              uVar6 = (ulonglong)bVar5;
            } while ((uint)bVar5 < *(uint *)(param_2 + 0x28));
            return 1;
          }
          if (iVar1 == 3) {
            iVar1 = *(int *)(param_1 + 0xb3ac);
            uVar6 = 0;
            *(int *)(param_2 + 0x28) = iVar1;
            if (iVar1 == 0) {
              return 1;
            }
            do {
              bVar5 = (char)uVar6 + 1;
              *(undefined4 *)(param_2 + 0x2c + uVar6 * 4) =
                   *(undefined4 *)(param_1 + 46000 + uVar6 * 4);
              uVar6 = (ulonglong)bVar5;
            } while ((uint)bVar5 < *(uint *)(param_2 + 0x28));
            return 1;
          }
          if (iVar1 == 4) {
            iVar1 = *(int *)(param_1 + 0xb400);
            *(int *)(param_2 + 0x28) = iVar1;
            uVar6 = 0;
            if (iVar1 == 0) {
              return 1;
            }
            do {
              bVar5 = (char)uVar6 + 1;
              *(undefined8 *)(uVar6 * 8 + 0x2c + param_2) =
                   *(undefined8 *)(uVar6 * 8 + 0xb404 + param_1);
              uVar6 = (ulonglong)bVar5;
            } while ((uint)bVar5 < *(uint *)(param_2 + 0x28));
            return 1;
          }
        }
        else {
          if (iVar1 != 2) {
            return 1;
          }
          iVar1 = *(int *)(param_2 + 0x24);
          if (iVar1 == 1) {
            *(undefined4 *)(param_1 + 0xb354) = 0;
            return 1;
          }
          if (iVar1 == 2) {
            *(undefined8 *)(param_1 + 0xb358) = 0;
            *(undefined8 *)(param_1 + 0xb360) = 0;
            *(undefined8 *)(param_1 + 0xb368) = 0;
            *(undefined8 *)(param_1 + 0xb370) = 0;
            *(undefined8 *)(param_1 + 0xb378) = 0;
            *(undefined8 *)(param_1 + 0xb380) = 0;
            *(undefined8 *)(param_1 + 0xb388) = 0;
            *(undefined8 *)(param_1 + 0xb390) = 0;
            *(undefined8 *)(param_1 + 0xb398) = 0;
            *(undefined8 *)(param_1 + 0xb3a0) = 0;
            *(undefined4 *)(param_1 + 0xb3a8) = 0;
            return 1;
          }
          if (iVar1 == 3) {
            *(undefined8 *)(param_1 + 0xb3ac) = 0;
            *(undefined8 *)(param_1 + 0xb3b4) = 0;
            *(undefined8 *)(param_1 + 0xb3bc) = 0;
            *(undefined8 *)(param_1 + 0xb3c4) = 0;
            *(undefined8 *)(param_1 + 0xb3cc) = 0;
            *(undefined8 *)(param_1 + 0xb3d4) = 0;
            *(undefined8 *)(param_1 + 0xb3dc) = 0;
            *(undefined8 *)(param_1 + 0xb3e4) = 0;
            *(undefined8 *)(param_1 + 0xb3ec) = 0;
            *(undefined8 *)(param_1 + 0xb3f4) = 0;
            *(undefined4 *)(param_1 + 0xb3fc) = 0;
            return 1;
          }
          if (iVar1 == 4) {
            lVar4 = 2;
            puVar2 = (undefined8 *)(param_1 + 0xb400);
            do {
              puVar3 = puVar2;
              *puVar3 = 0;
              puVar3[1] = 0;
              puVar3[2] = 0;
              puVar3[3] = 0;
              puVar3[4] = 0;
              puVar3[5] = 0;
              puVar3[6] = 0;
              puVar3[7] = 0;
              lVar4 = lVar4 + -1;
              puVar2 = puVar3 + 8;
            } while (lVar4 != 0);
            puVar3[8] = 0;
            puVar3[9] = 0;
            puVar3[10] = 0;
            puVar3[0xb] = 0;
            *(undefined4 *)(puVar3 + 0xc) = 0;
            return 1;
          }
        }
LAB_14000c16d:
        *(undefined4 *)(param_2 + 0x14) = 1;
        return 0;
      }
    }
    else {
      if (iVar1 != 3) goto LAB_14000c445;
      if (0x13 < *(uint *)(param_2 + 0x18)) {
        *(undefined4 *)(param_2 + 0x24) = 0x14;
        *(undefined4 *)(param_2 + 0x28) = 0x14;
        *(undefined4 *)(param_2 + 0x2c) = 0x14;
        return 1;
      }
    }
    *(undefined4 *)(param_2 + 0x14) = 3;
  }
  return 0;
}



===== HandleEventNotification @ 14000c470 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HandleEventNotification(longlong param_1,ushort *param_2,int param_3)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  longlong lVar4;
  bool bVar5;
  ushort *puVar6;
  longlong *plVar7;
  undefined1 uVar8;
  undefined8 *puVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  char *pcVar13;
  undefined1 uVar14;
  char cVar15;
  undefined1 local_a8 [32];
  uint local_58 [2];
  undefined4 local_50;
  ushort local_4c;
  ushort local_4a;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)local_a8;
  uVar2 = param_2[10];
  bVar5 = false;
  if ((*(char *)(param_1 + 0x139a) != '\0') && (*(char *)(param_1 + 0xb350) != '\0')) {
    puVar6 = (ushort *)(param_1 + 0xb35c);
    uVar10 = 0;
    if (*(uint *)(param_1 + 0xb358) != 0) {
      do {
        if (bVar5) goto LAB_14000c4f8;
        if ((*puVar6 == uVar2) && ((uVar2 != 0x21 || (puVar6[1] == param_2[0x15])))) {
          bVar5 = true;
        }
        uVar10 = uVar10 + 1;
        puVar6 = puVar6 + 2;
      } while (uVar10 < *(uint *)(param_1 + 0xb358));
      if (bVar5) {
LAB_14000c4f8:
        local_50 = 2;
        local_4c = uVar2;
        local_4a = param_2[0x15];
        SendMpiEventToApplication(param_1,0x6e,&local_50,0xc);
      }
    }
  }
  if ((uVar2 == 0x21) && (*(char *)(param_1 + 0x1559) != '\0')) {
    ScsiPortWmiFireLogicalUnitEvent
              (param_1,-1,0,0,(int *)&MegaSASWmiMpiEventGuid,0,0x10,(int *)(param_1 + 0x198));
  }
  if (*param_2 != 0) {
    SendMpiEventToApplication(param_1,(uint)uVar2,param_2 + 0xe,(uint)*param_2 << 2);
  }
  switch(uVar2) {
  case 1:
    if (*param_2 != 0) {
      LogSystemEvent(param_1,*(undefined4 *)(param_2 + 0xe),0x4004af00,(byte *)"Event Data logged",
                     param_3);
    }
    break;
  case 5:
    *(undefined1 *)(param_1 + 0xe44) = 1;
    if (*(short *)(param_1 + 0x620) != 0) {
      LogSystemEvent(param_1,0xad01000e,0x4004af00,(byte *)"External Hard Reset Event Received",
                     param_3);
    }
    break;
  case 10:
    *(undefined1 *)(param_1 + 0xe69) = 0;
    break;
  case 0xf:
    uVar10 = *(uint *)(param_1 + 0x678);
    uVar11 = 0;
    uVar3 = param_2[0x11];
    if (uVar10 != 0) {
      do {
        lVar4 = *(longlong *)(param_1 + 0x378) + (ulonglong)uVar11 * 0x28;
        if (*(ushort *)(*(longlong *)(param_1 + 0x378) + 0x1a + (ulonglong)uVar11 * 0x28) == uVar3)
        {
          if (uVar11 < uVar10) {
            uVar8 = (undefined1)*(undefined2 *)(lVar4 + 0x1c);
            uVar14 = (undefined1)*(undefined2 *)(lVar4 + 0x1e);
            if ((char)param_2[0xf] == '\b') {
              if (*(int *)(param_1 + 0x630) == 0) {
                PauseDevice(param_1,uVar8,uVar14,0,uVar3,300,1,1,param_3);
              }
            }
            else if ((char)param_2[0xf] == '\x0e') {
              ResumeDevice(param_1,uVar8,uVar14,0,uVar3,1,1,param_3);
            }
          }
          break;
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 < uVar10);
    }
    break;
  case 0x17:
    if (((*(char *)((longlong)param_2 + 0x1f) == '\x04') && (*(int *)(param_1 + 0xec0) == 0)) &&
       ((*(longlong **)(param_1 + 0x5d0) != *(longlong **)(param_1 + 0x5d8) ||
        (*(longlong *)(**(longlong **)(param_1 + 0x5d0) + 8) != 0)))) {
      if ((*(char *)(param_1 + 0x15a0) == '\0') && (*(char *)(param_1 + 0xec8) == '\0')) {
        if (*(int *)(param_1 + 0x630) == 0) {
          StorPortPause(param_1,300);
        }
        ResetActive(param_1,0xe,param_3);
        *(undefined1 *)(param_1 + 0x15a0) = 1;
        *(undefined1 *)(param_1 + 0x15a4) = 1;
        SasBcAsyncEvent(param_1,param_3);
      }
      else {
        *(undefined1 *)(param_1 + 0x15a1) = 1;
      }
    }
    break;
  case 0x1c:
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x100001) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x100001,
                  (undefined1 *)param_2,(uint)(byte)param_2[1] << 2,param_3);
    }
    ProcessSasTopologyChangeList(param_1,param_2,param_3);
    break;
  case 0x1d:
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x100000) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x100000,
                  (undefined1 *)param_2,(uint)(byte)param_2[1] << 2,param_3);
    }
    ProcessSasEnclosureStatusChange(param_1,(longlong)param_2,param_3);
    break;
  case 0x20:
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x100002) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x100002,
                  (undefined1 *)param_2,(uint)(byte)param_2[1] << 2,param_3);
    }
    ProcessIRConfigChangeList(param_1,param_2,param_3);
    break;
  case 0x27:
    local_58[0] = (param_2[0x10] | 0xf0000) << 8 | (uint)(byte)param_2[0xe];
    LogSystemEvent(param_1,local_58[0],0xc004af02,(byte *)"IOC temperature exceeded the threshold",
                   param_3);
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x24a) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x24a,
                  (undefined1 *)(param_2 + 0x10),2,param_3);
    }
    break;
  case 0x34:
    if ((char)param_2[0x10] == '\0') {
      local_58[0] = (*(uint *)(param_2 + 0xe) & 0xffff | 0xe0000) << 8 |
                    (uint)*(byte *)((longlong)param_2 + 0x21);
      LogSystemEvent(param_1,local_58[0],0xc004af02,(byte *)"Insufficient Power for active cable",
                     param_3);
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x24b) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x24b,
                    (undefined1 *)(param_2 + 0xe),4,param_3);
      }
    }
    else if (((char)param_2[0x10] == '\x02') &&
            ((((local_58[0] = 0xe000002, *(short *)(param_1 + 0x620) != 0 ||
               (uVar3 = *(ushort *)(param_1 + 0x622), *(ushort *)(param_1 + 0x622) = uVar3 + 1,
               uVar3 < 0x14)) &&
              (LogSystemEvent(param_1,0xe000002,0xc004af02,
                              (byte *)
                              "an active cable is present but is running at a degraded speed",
                              param_3), *(char *)(param_1 + 0x3b8) != '\0')) &&
             ((*(uint *)(param_1 + 0x3bc) & 0x253) != 0)))) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x253,
                  (undefined1 *)(param_2 + 0x10),1,param_3);
    }
    break;
  case 0x35:
    local_58[0] = (param_2[0xe] | 0xd0000) << 8 | (uint)(byte)param_2[0xf];
    LogSystemEvent(param_1,local_58[0],0x8004af01,
                   (byte *)"SMP command sent to the expander by FW failed/timed out",param_3);
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x26f) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x26f,
                  (undefined1 *)local_58,4,param_3);
    }
  }
  if ((char)param_2[3] != '\0') {
    if (*(char *)(param_1 + 0xe7f) == '\0') {
      bVar1 = *(byte *)(param_1 + 0xdae);
      lVar4 = param_1 + (ulonglong)bVar1 * 8;
      if (*(short *)(lVar4 + 0xdb0) == 0) {
        *(ushort *)(lVar4 + 0xdb0) = uVar2;
        *(undefined4 *)(lVar4 + 0xdb4) = *(undefined4 *)(param_2 + 0xc);
        cVar15 = '\0';
        if (bVar1 != 9) {
          cVar15 = bVar1 + 1;
        }
        *(uint *)(param_1 + 0x67c) = *(uint *)(param_1 + 0x67c) | 2;
        *(char *)(param_1 + 0xdae) = cVar15;
        if (*(char *)(param_1 + 0xeb9) == '\0') {
          StorPortNotification(6,param_1,WatchdogTimer,10000);
          return;
        }
        return;
      }
      uVar12 = 0xad01003c;
      pcVar13 = "queue to issue Event Ack message is full";
    }
    else {
      lVar4 = **(longlong **)(param_1 + 0x5d0);
      if (*(longlong *)(lVar4 + 8) == 0) {
        plVar7 = *(longlong **)(param_1 + 0x5d0) + 1;
        *(longlong **)(param_1 + 0x5d0) = plVar7;
        if (plVar7 == *(longlong **)(param_1 + 0x5e0)) {
          *(undefined8 *)(param_1 + 0x5d0) = *(undefined8 *)(param_1 + 0x5c8);
        }
        uVar3 = *(ushort *)(lVar4 + 0x10);
        *(undefined8 *)(lVar4 + 8) = 0xea;
        puVar9 = (undefined8 *)
                 ((longlong)(int)((uint)*(ushort *)(param_1 + 0x2ea) * (uint)uVar3) +
                 *(longlong *)(param_1 + 0x310));
        *puVar9 = 0;
        puVar9[1] = 0;
        *(undefined4 *)(puVar9 + 2) = 0;
        *(undefined1 *)((longlong)puVar9 + 3) = 8;
        *(ushort *)((longlong)puVar9 + 0xc) = uVar2;
        *(undefined4 *)(puVar9 + 2) = *(undefined4 *)(param_2 + 0xc);
        **(int **)(param_1 + 0xe8) = (uint)uVar3 * 0x10000 + 8;
        LOCK();
        UNLOCK();
        **(undefined4 **)(param_1 + 0xf0) = 0;
        LOCK();
        UNLOCK();
        return;
      }
      uVar12 = 0xad01003b;
      pcVar13 = "need to send an Event Ack for an Event, but FW Credits are exhausted";
    }
    LogSystemEvent(param_1,uVar12,0x8004af01,(byte *)pcVar13,param_3);
    *(undefined4 *)(param_1 + 0xec0) = 1;
    if (*(int *)(param_1 + 0x630) == 0) {
      StorPortPause(param_1,300);
    }
    *(undefined2 *)(param_1 + 0xebc) = 0;
    KickStart(param_1,param_3);
  }
  return;
}



===== HandleFWDowngrade @ 14000ccf0 =====

undefined1 HandleFWDowngrade(longlong param_1,char param_2,int param_3)

{
  undefined1 uVar1;
  undefined4 uVar2;
  char local_res8 [8];
  
  if (param_2 == '\0') {
    uVar2 = *(undefined4 *)(param_1 + 0xb32c);
  }
  else {
    uVar2 = 1;
    *(undefined4 *)(param_1 + 0xb32c) = 1;
  }
LAB_14000cd30:
  switch(uVar2) {
  case 1:
    *(undefined1 *)(param_1 + 0xb328) = 1;
    uVar2 = 2;
    *(undefined4 *)(param_1 + 0xb32c) = 2;
    goto LAB_14000cd30;
  case 2:
    goto switchD_14000cd47_caseD_2;
  case 3:
    if (*(short *)(param_1 + 0x1502) == 0) {
      *(undefined2 *)(param_1 + 0xb330) = *(undefined2 *)(param_1 + 0x15c4);
      *(ushort *)(param_1 + 0x15c4) = (ushort)(*(short *)(param_1 + 0x1564) * 0x14 + 8U) >> 2;
      *(undefined1 *)(param_1 + 0x676) = 0;
      SendExtendedConfigPageMessage
                (param_1,'\x06',(char *)(param_1 + 0x15c0),
                 (uint)*(ushort *)(param_1 + 0x1564) << 0x10,(int)*(undefined8 *)(param_1 + 0x15c8),
                 param_3);
      uVar2 = 4;
    }
    else {
      LogSystemEvent(param_1,0xad010047,0xc004af02,
                     (byte *)"a read of DPM Page 0 header returned an error (HandleFWDowngrade)",
                     param_3);
      uVar2 = 0;
      *(undefined1 *)(param_1 + 0xb328) = 0;
    }
    break;
  case 4:
    if (*(short *)(param_1 + 0x1502) != 0) {
      LogSystemEvent(param_1,0xad010047,0xc004af02,
                     (byte *)"a read of DPM Page 0 returned an error (HandleFWDowngrade)",param_3);
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x23e) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x23e,
                    (undefined1 *)(param_1 + 0x1502),2,param_3);
      }
      *(undefined1 *)(param_1 + 0xb328) = 0;
      uVar2 = 0;
      break;
    }
    *(short *)(param_1 + 0x15c4) = *(short *)(param_1 + 0xb330) + 5;
    uVar2 = 5;
    *(undefined4 *)(param_1 + 0xb32c) = 5;
    goto LAB_14000cd30;
  case 5:
    uVar1 = SendIOCTLMessage(param_1,*(ushort **)(param_1 + 0xb338),*(void **)(param_1 + 0xb340),
                             param_3);
    *(undefined1 *)(param_1 + 0xb348) = 0;
    *(undefined4 *)(param_1 + 0xb32c) = 6;
    return uVar1;
  case 6:
    FlushAllDPMPage0(param_1,param_3);
    uVar2 = 0;
    *(undefined1 *)(param_1 + 0xb328) = 0;
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x10e) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x10e,(undefined1 *)0x0
                  ,0,param_3);
    }
    if (*(int *)(param_1 + 0xb334) != 0) {
      UpdateMissedEnclEntryToDPM(param_1,param_3);
    }
    break;
  default:
    return 1;
  }
  *(undefined4 *)(param_1 + 0xb32c) = uVar2;
  return 1;
switchD_14000cd47_caseD_2:
  local_res8[0] = '\0';
  local_res8[1] = '\0';
  local_res8[2] = '\0';
  local_res8[3] = '\x0f';
  local_res8[4] = '\0';
  local_res8[5] = '\0';
  local_res8[6] = '\x17';
  local_res8[7] = '\0';
  SendExtendedConfigPageMessage(param_1,'\0',local_res8,0,0,param_3);
  *(undefined4 *)(param_1 + 0xb32c) = 3;
  return 1;
}



===== HandleIoctlTimeout @ 14000cfb0 =====

undefined8 HandleIoctlTimeout(longlong param_1,int *param_2)

{
  int iVar1;
  undefined2 *puVar2;
  undefined8 *puVar3;
  code *pcVar4;
  undefined8 uVar5;
  
  puVar2 = *(undefined2 **)(param_1 + 0xf20);
  iVar1 = *param_2;
  *(undefined1 *)(param_1 + 0xe7f) = 1;
  if (((*(char *)((longlong)puVar2 + 3) == '\0') && (*(int *)(param_1 + 0x628) == 0)) &&
     (*(char *)(param_1 + 0xeb9) == '\0')) {
    puVar3 = *(undefined8 **)(param_1 + 800);
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    puVar3[5] = 0;
    *(undefined4 *)(puVar3 + 6) = 0;
    *(undefined2 *)puVar3 = *puVar2;
    *(undefined1 *)((longlong)puVar3 + 3) = 1;
    *(undefined1 *)((longlong)puVar3 + 5) = 3;
    ResetActive(param_1,1,iVar1);
    **(int **)(param_1 + 0xe8) = (uint)*(ushort *)(param_1 + 0x66e) * 0x10000 + 6;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0xf0) = 0;
    LOCK();
    UNLOCK();
    AfdMasterTrigger(param_1,4,iVar1);
    uVar5 = 1000000;
    *(undefined4 *)(param_1 + 0x634) = 0xf;
    pcVar4 = WatchdogTimer;
    *(undefined1 *)(param_1 + 0xeb9) = 0;
  }
  else {
    puVar3 = *(undefined8 **)(param_1 + 0x608);
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    *(undefined4 *)(puVar3 + 5) = 0;
    *(undefined1 *)((longlong)puVar3 + 3) = 7;
    *(undefined8 *)((longlong)puVar3 + 0x14) = 0xffffffffffffffff;
    *(undefined8 *)((longlong)puVar3 + 0x1c) = 0xffffffffffffffff;
    *(undefined1 *)(param_1 + 0xe69) = 1;
    **(int **)(param_1 + 0xe8) = (uint)*(ushort *)(param_1 + 0x66a) * 0x10000 + 8;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0xf0) = 0;
    LOCK();
    UNLOCK();
    ResetActive(param_1,2,iVar1);
    uVar5 = 3000000;
    *(undefined1 *)(param_1 + 0xeb9) = 1;
    pcVar4 = DelayedIoctlTimeout;
  }
  uVar5 = StorPortNotification(6,param_1,pcVar4,uVar5);
  *(undefined1 *)(param_1 + 0xe7f) = 0;
  return CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
}



===== HandleRttIoctl @ 14000d140 =====

longlong HandleRttIoctl(longlong param_1,longlong param_2,undefined1 *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  void *pvVar3;
  uint7 uVar5;
  void *pvVar4;
  uint uVar6;
  ulonglong uVar7;
  int iVar8;
  int *_Src;
  
  *param_3 = 1;
  *(undefined4 *)(param_2 + 0x14) = 0;
  pvVar3 = memmove((void *)(param_2 + 0x1c),&RttraceRecordVersion,4);
  iVar8 = *(int *)(param_2 + 0x20);
  uVar5 = (uint7)((ulonglong)pvVar3 >> 8);
  if (iVar8 == 1) {
    if (*(uint *)(param_2 + 0x18) < 0x24) goto LAB_14000d2d5;
    *(undefined1 *)(param_2 + 0x3c) = *(undefined1 *)(param_1 + 0x3b8);
    *(undefined4 *)(param_2 + 0x38) = *(undefined4 *)(param_1 + 0x3bc);
    *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)(param_1 + 0x3b4);
    uVar6 = *(uint *)(param_1 + 0x3b0);
    *(uint *)(param_2 + 0x30) = uVar6;
    *(undefined4 *)(param_2 + 0x2c) = 0xf;
  }
  else {
    if (iVar8 != 2) {
      if (iVar8 != 3) {
        *(undefined4 *)(param_2 + 0x14) = 1;
        return (ulonglong)uVar5 << 8;
      }
      uVar7 = (ulonglong)*(uint *)(param_2 + 0x2c);
      if ((ulonglong)*(uint *)(param_2 + 0x18) < uVar7 + 0x14) {
        *(undefined4 *)(param_2 + 0x14) = 3;
        *(undefined4 *)(param_2 + 0x28) = 2;
        return (ulonglong)(uint3)(*(uint *)(param_2 + 0x18) >> 8) << 8;
      }
      if ((*(uint *)(param_2 + 0x24) & 1) == 0) {
        _Src = *(int **)(param_1 + 0x3a8);
      }
      else {
        _Src = *(int **)(param_1 + 0x398);
        *(int **)(param_1 + 0x3a8) = _Src;
        uVar7 = (ulonglong)*(uint *)(param_2 + 0x2c);
      }
      pvVar3 = (void *)(param_2 + 0x30);
      iVar8 = 0;
      uVar6 = (uint)uVar7;
      if ((uint)_Src[1] < uVar6) {
        do {
          uVar6 = (uint)uVar7;
          if (*_Src == 0) break;
          if (*_Src == 1) {
            _Src = *(int **)(param_1 + 0x388);
          }
          else {
            iVar8 = iVar8 + _Src[1];
            memmove(pvVar3,_Src,(ulonglong)(uint)_Src[1]);
            pvVar3 = (void *)((longlong)pvVar3 + (ulonglong)(uint)_Src[1]);
            _Src = (int *)((longlong)_Src + (ulonglong)(uint)_Src[1]);
          }
          uVar6 = *(uint *)(param_2 + 0x2c);
          uVar7 = (ulonglong)uVar6;
        } while ((uint)_Src[1] < uVar6 - iVar8);
      }
      uVar1 = _Src[1];
      pvVar4 = (void *)(ulonglong)uVar1;
      if ((uVar1 < uVar6 - iVar8) && (*_Src == 0)) {
        iVar8 = iVar8 + uVar1;
        pvVar4 = memmove(pvVar3,_Src,(ulonglong)uVar1);
        *(undefined4 *)(param_2 + 0x24) = 2;
        *(undefined8 *)(param_1 + 0x3a8) = 0;
      }
      else {
        *(int **)(param_1 + 0x3a8) = _Src;
        *(undefined4 *)(param_2 + 0x24) = 0;
      }
      *(int *)(param_2 + 0x2c) = iVar8;
      *(undefined4 *)(param_2 + 0x28) = 0;
      return CONCAT71((int7)((ulonglong)pvVar4 >> 8),1);
    }
    if (*(uint *)(param_2 + 0x18) < 0x24) {
LAB_14000d2d5:
      *(undefined4 *)(param_2 + 0x14) = 2;
      *(undefined4 *)(param_2 + 0x28) = 2;
      return (ulonglong)uVar5 << 8;
    }
    uVar6 = *(uint *)(param_2 + 0x2c);
    if ((uVar6 & 1) != 0) {
      *(undefined1 *)(param_1 + 0x3b8) = *(undefined1 *)(param_2 + 0x3c);
      uVar6 = *(uint *)(param_2 + 0x2c);
    }
    if ((uVar6 & 2) != 0) {
      uVar2 = *(undefined4 *)(param_2 + 0x38);
      *(undefined4 *)(param_1 + 0x3bc) = uVar2;
      *(undefined4 *)(param_2 + 0x28) = 0;
      return CONCAT71((uint7)(uint3)((uint)uVar2 >> 8),1);
    }
  }
  *(undefined4 *)(param_2 + 0x28) = 0;
  return CONCAT71((uint7)(uint3)(uVar6 >> 8),1);
}



===== HandleUnitAttenReset @ 14000d330 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
HandleUnitAttenReset
          (longlong param_1,ushort param_2,undefined8 *param_3,byte param_4,byte param_5,
          char param_6,char param_7,int param_8)

{
  int *piVar1;
  longlong *plVar2;
  int *piVar3;
  undefined2 uVar4;
  bool bVar5;
  char cVar6;
  byte bVar7;
  longlong lVar8;
  undefined8 uVar9;
  int iVar10;
  longlong lVar11;
  ushort uVar12;
  undefined1 uVar13;
  longlong lVar14;
  undefined1 auStackY_b8 [32];
  byte local_64;
  byte local_63;
  char local_62;
  ushort local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_63 = param_5;
  local_62 = param_6;
  local_64 = param_4;
  local_60 = param_2;
  lVar8 = StorPortGetLogicalUnit(param_1,param_4,param_5,param_6);
  if (lVar8 == 0) {
    LogSystemEvent(param_1,0xad010057,0xc004af02,
                   (byte *)"call to get LU Extension failed in UAR state machine",param_8);
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x232) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x232,&local_64,6,
                  param_8);
    }
    uVar13 = 0;
  }
  else {
    piVar1 = (int *)(lVar8 + 0x20);
    if ((param_7 == '\0') || (*piVar1 == 0)) {
      iVar10 = *piVar1;
LAB_14000d460:
      switch(iVar10) {
      case 0:
        if (param_7 == '\0') {
          return 1;
        }
        lVar14 = *(longlong *)(param_1 + 0x5e8);
        if ((((lVar14 != 0) &&
             (*(longlong *)((ulonglong)param_2 * 0x20 + 8 + *(longlong *)(param_1 + 0x350)) !=
              lVar14)) &&
            (lVar14 = *(longlong *)(lVar14 + 0x68), *(byte *)(lVar14 + 0x5a) == param_4)) &&
           ((*(byte *)(lVar14 + 0x5b) == param_5 && (*(char *)(lVar14 + 0x5c) == param_6)))) {
          if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x2001f) != 0))
          {
            RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x2001f,&local_64
                        ,6,param_8);
          }
          return 0;
        }
        iVar10 = 1;
        *(byte *)(lVar8 + 0x26) = param_4;
        *(byte *)(lVar8 + 0x27) = param_5;
        *(char *)(lVar8 + 0x28) = param_6;
        *(ushort *)(lVar8 + 0x2a) = param_2;
        *piVar1 = 1;
        goto LAB_14000d460;
      case 1:
        *(int *)(param_1 + 0xf38) = *(int *)(param_1 + 0xf38) + 1;
        uVar4 = *(undefined2 *)
                 (*(longlong *)(param_1 + 0x378) + 0x1a +
                 (ulonglong)(ushort)((ushort)param_4 * 0x80 + (ushort)param_5) * 0x28);
        *(undefined2 *)(lVar8 + 0x24) = uVar4;
        PauseDevice(param_1,param_4,param_5,param_6,uVar4,300,2,2,param_8);
        ResetActive(param_1,*(uint *)(param_1 + 0x628) | 0x80000000,param_8);
        iVar10 = 2;
        *piVar1 = 2;
        goto LAB_14000d460;
      case 2:
        *param_3 = 0;
        param_3[1] = 0;
        param_3[2] = 0;
        param_3[3] = 0;
        param_3[4] = 0;
        param_3[5] = 0;
        *(undefined4 *)(param_3 + 6) = 0;
        *(undefined2 *)param_3 = *(undefined2 *)(lVar8 + 0x24);
        *(undefined1 *)((longlong)param_3 + 3) = 1;
        *(undefined1 *)((longlong)param_3 + 5) = 2;
        *(char *)((longlong)param_3 + 0xd) = param_6;
        *(undefined4 *)((ulonglong)param_2 * 0x20 + 0x18 + *(longlong *)(param_1 + 0x350)) = 0x80;
        QueueRequestDescriptor(param_1,(uint)param_2 * 0x10000 + 6,0,param_8);
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x20016) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x20016,&local_64,6
                      ,param_8);
        }
        bVar7 = GtfStartTimer(param_1,1,8,UarStuckAtsTimerCallback,piVar1,param_8);
        *(byte *)(lVar8 + 0x2c) = bVar7;
        if (bVar7 == 0xfe) {
          if (*(short *)(param_1 + 0x620) != 0) {
            LogSystemEvent(param_1,0xad01007d,0x8004af01,
                           (byte *)"No timer available to time ATS in UAR state machine",param_8);
          }
          if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x233) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x233,
                        (undefined1 *)0x0,0,param_8);
          }
        }
        *piVar1 = 4;
LAB_14000dd1f:
        uVar13 = 1;
        break;
      case 3:
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x252) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x252,
                      (undefined1 *)0x0,0,param_8);
        }
        ResumeDevice(param_1,param_4,param_5,param_6,*(undefined2 *)(lVar8 + 0x24),2,2,param_8);
        lVar14 = (ulonglong)param_2 * 0x20 + *(longlong *)(param_1 + 0x350);
        *(undefined2 *)(lVar8 + 0x24) = 0;
        piVar3 = (int *)(param_1 + 0xf38);
        *piVar3 = *piVar3 + -1;
        if (*piVar3 == 0) {
          ResetActive(param_1,*(uint *)(param_1 + 0x628) & 0x7fffffff,param_8);
        }
        lVar8 = *(longlong *)(param_1 + 0x5e8);
        plVar2 = (longlong *)(lVar14 + 8);
        if ((lVar8 == 0) || (lVar8 == *plVar2)) {
          if (lVar8 == *plVar2) {
            bVar5 = true;
            if (lVar8 != 0) {
              *(undefined1 *)(lVar8 + 3) = 4;
            }
            StorPortNotification(0,param_1);
            if ((*(char *)(param_1 + 0x3b8) != '\0') &&
               ((*(uint *)(param_1 + 0x3bc) & 0x20010) != 0)) {
              RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x20010,
                          &local_64,6,param_8);
            }
          }
          else {
            bVar5 = false;
          }
          *(undefined8 *)(param_1 + 0x5e8) = 0;
          uVar9 = CheckResetQueue(param_1,param_8);
          if (((char)uVar9 == '\0') && (ResetActive(param_1,0x40000008,param_8), bVar5)) {
            StorPortResume(param_1);
          }
        }
        if ((param_2 != 0) && (param_2 <= *(ushort *)(param_1 + 0x654))) {
          StorPortNotification(0,param_1,*plVar2);
          **(longlong **)(param_1 + 0x5d8) = lVar14;
          *(longlong *)(param_1 + 0x5d8) = *(longlong *)(param_1 + 0x5d8) + 8;
          if (*(longlong *)(param_1 + 0x5d8) == *(longlong *)(param_1 + 0x5e0)) {
            *(undefined8 *)(param_1 + 0x5d8) = *(undefined8 *)(param_1 + 0x5c8);
          }
          if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x20018) != 0))
          {
            RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x20018,&local_64
                        ,6,param_8);
          }
        }
        *plVar2 = 0;
        *(undefined4 *)(lVar14 + 0x18) = 0;
        if (*(char *)(param_1 + 0xec8) == '\0') {
          CheckIoctlQueue(param_1,param_8);
        }
        *piVar1 = 0;
        goto LAB_14000dd1f;
      case 4:
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x20017) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x20017,&local_64,6
                      ,param_8);
        }
        cVar6 = GtfStopTimer(param_1,*(byte *)(lVar8 + 0x2c),param_8);
        if (((cVar6 == '\0') && (*(char *)(param_1 + 0x3b8) != '\0')) &&
           ((*(uint *)(param_1 + 0x3bc) & 0x251) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x251,
                      (undefined1 *)0x0,0,param_8);
        }
        *(undefined4 *)((ulonglong)param_2 * 0x20 + 0x18 + *(longlong *)(param_1 + 0x350)) = 0;
        if (*(short *)((longlong)param_3 + 0xe) != 0) {
          if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x235) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x235,&local_64,6
                        ,param_8);
          }
          LogSystemEvent(param_1,0xad010059,0x8004af01,
                         (byte *)"NO ATS TM reply in UAR state machine",param_8);
        }
        if ((*(char *)(param_1 + 0x12a) != '\0') && (uVar12 = 1, 1 < *(byte *)(param_1 + 299))) {
          do {
            LSImpiMSIIsr(param_1,(byte)uVar12);
            uVar12 = uVar12 + 1;
          } while (uVar12 < *(byte *)(param_1 + 299));
        }
        iVar10 = 5;
        *piVar1 = 5;
        goto LAB_14000d460;
      case 5:
        uVar12 = 1;
        if (*(ushort *)(param_1 + 0x654) != 0) {
          lVar14 = *(longlong *)(param_1 + 0x350);
          do {
            lVar11 = (ulonglong)uVar12 * 0x20;
            if ((((*(longlong *)(lVar11 + 8 + lVar14) != 0) &&
                 (*(short *)(lVar8 + 0x24) == *(short *)(lVar11 + 0x14 + lVar14))) &&
                (param_6 == *(char *)(lVar11 + 0x16 + lVar14))) && (uVar12 != param_2)) {
              *piVar1 = 7;
              iVar10 = 7;
              if ((*(char *)(param_1 + 0x3b8) == '\0') ||
                 ((*(uint *)(param_1 + 0x3bc) & 0x236) == 0)) goto LAB_14000d460;
              RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x236,&local_64
                          ,6,param_8);
              break;
            }
            uVar12 = uVar12 + 1;
          } while (uVar12 <= *(ushort *)(param_1 + 0x654));
        }
        iVar10 = *piVar1;
        if (iVar10 != 7) {
          *piVar1 = 6;
          iVar10 = 6;
        }
        goto LAB_14000d460;
      case 6:
        ResumeDevice(param_1,param_4,param_5,param_6,*(undefined2 *)(lVar8 + 0x24),2,2,param_8);
        lVar14 = (ulonglong)param_2 * 0x20 + *(longlong *)(param_1 + 0x350);
        StorPortNotification(0,param_1,*(undefined8 *)(lVar14 + 8));
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x20018) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x20018,&local_64,6
                      ,param_8);
        }
        *(undefined2 *)(lVar8 + 0x24) = 0;
        piVar3 = (int *)(param_1 + 0xf38);
        *piVar3 = *piVar3 + -1;
        if (*piVar3 == 0) {
          ResetActive(param_1,*(uint *)(param_1 + 0x628) & 0x7fffffff,param_8);
        }
        lVar8 = *(longlong *)(param_1 + 0x5e8);
        if ((lVar8 == 0) || (lVar8 == *(longlong *)(lVar14 + 8))) {
          lVar11 = *(longlong *)(lVar14 + 8);
          *(undefined8 *)(param_1 + 0x5e8) = 0;
          uVar9 = CheckResetQueue(param_1,param_8);
          if (((char)uVar9 == '\0') && (ResetActive(param_1,0x40000008,param_8), lVar8 == lVar11)) {
            StorPortResume(param_1);
          }
        }
        *(undefined8 *)(lVar14 + 8) = 0;
        *(undefined4 *)(lVar14 + 0x18) = 0;
        if (*(char *)(param_1 + 0xec8) == '\0') {
          CheckIoctlQueue(param_1,param_8);
        }
        *piVar1 = 0;
        return 0;
      case 7:
        LogSystemEvent(param_1,0xad010035,0xc004af02,
                       (byte *)"IOs still active on bus when TM reply was received(UAR)",param_8);
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x20019) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x20019,&local_64,6
                      ,param_8);
        }
        *(undefined4 *)(param_1 + 0xec0) = 1;
        KickStart(param_1,param_8);
      default:
        *piVar1 = 0;
        goto LAB_14000dd1f;
      }
    }
    else {
      uVar13 = 0;
    }
  }
  return uVar13;
}



===== InitReplyFreeQueue @ 14000dd80 =====

void InitReplyFreeQueue(longlong param_1)

{
  ushort uVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  ulonglong uVar5;
  
  uVar1 = *(ushort *)(param_1 + 0x2f2);
  uVar2 = *(ushort *)(param_1 + 0x2e8);
  iVar4 = *(int *)(param_1 + 0x210);
  piVar3 = *(int **)(param_1 + 0x300);
  if (uVar1 != 0) {
    uVar5 = (ulonglong)uVar1;
    do {
      *piVar3 = iVar4;
      piVar3 = piVar3 + 1;
      iVar4 = iVar4 + (uint)uVar2;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  **(uint **)(param_1 + 0x58) = (uint)uVar1;
  LOCK();
  UNLOCK();
  *(ushort *)(param_1 + 0x21c) = uVar1;
  return;
}



===== IssueIOCFacts @ 14000dde0 =====

ulonglong IssueIOCFacts(longlong param_1,int param_2)

{
  int iVar1;
  ushort uVar2;
  bool bVar3;
  short sVar4;
  uint uVar5;
  ulonglong uVar6;
  ushort uVar7;
  undefined4 uVar8;
  char *pcVar9;
  
  iVar1 = *(int *)(param_1 + 0x630);
  *(undefined8 *)(param_1 + 0x680) = 0;
  *(undefined4 *)(param_1 + 0x688) = 0;
  *(undefined8 *)(param_1 + 0x720) = 0;
  *(undefined8 *)(param_1 + 0x728) = 0;
  *(undefined8 *)(param_1 + 0x730) = 0;
  *(undefined8 *)(param_1 + 0x738) = 0;
  *(undefined8 *)(param_1 + 0x740) = 0;
  *(undefined8 *)(param_1 + 0x748) = 0;
  *(undefined8 *)(param_1 + 0x750) = 0;
  *(undefined8 *)(param_1 + 0x758) = 0;
  *(undefined4 *)(param_1 + 0x760) = 0;
  *(undefined1 *)(param_1 + 0x683) = 3;
  bVar3 = SendMessageViaHandShake(param_1,0,3);
  if (bVar3) {
    uVar6 = ReceiveDataViaHandshake(param_1,0x22);
    if ((char)uVar6 != '\0') {
      *(undefined2 *)(param_1 + 0x668) = *(undefined2 *)(param_1 + 0x720);
      *(short *)(param_1 + 0x2ea) = *(short *)(param_1 + 0x744) << 2;
      *(undefined2 *)(param_1 + 0x2ec) = *(undefined2 *)(param_1 + 0x744);
      *(undefined2 *)(param_1 + 0x2f4) = *(undefined2 *)(param_1 + 0x754);
      *(ushort *)(param_1 + 0x2f6) = (ushort)*(byte *)(param_1 + 0x734);
      sVar4 = *(short *)(param_1 + 0x746) << 4;
      *(short *)(param_1 + 0x2e6) = sVar4;
      if (sVar4 == 0) {
        *(undefined2 *)(param_1 + 0x2e6) = 0x80;
      }
      *(short *)(param_1 + 0x654) = *(short *)(param_1 + 0x738) + -7;
      uVar7 = *(short *)(param_1 + 0x74a) + (ushort)*(byte *)(param_1 + 0x757);
      *(ushort *)(param_1 + 0x658) = uVar7;
      *(short *)(param_1 + 0x65a) = (*(short *)(param_1 + 0x74e) + 1) * 2;
      uVar2 = *(short *)(param_1 + 0x74c) * 3;
      *(ushort *)(param_1 + 0x65c) = uVar2;
      if (uVar2 < 0x28) {
        *(undefined2 *)(param_1 + 0x65c) = 0x28;
      }
      *(undefined1 *)(param_1 + 0x65f) = *(undefined1 *)(param_1 + 0x757);
      sVar4 = 0x40;
      if (*(short *)(param_1 + 0x75a) != 0) {
        sVar4 = *(short *)(param_1 + 0x75a);
      }
      *(short *)(param_1 + 0x1564) = sVar4 + -1;
      *(undefined2 *)(param_1 + 0x662) = *(undefined2 *)(param_1 + 0x752);
      *(undefined2 *)(param_1 + 0x664) = *(undefined2 *)(param_1 + 0x758);
      *(ushort *)(param_1 + 0x656) = (ushort)*(byte *)(param_1 + 0x736);
      *(ushort *)(param_1 + 0x2e8) = (ushort)*(byte *)(param_1 + 0x756) << 2;
      if (0x400 < uVar7) {
        *(undefined2 *)(param_1 + 0x658) = 0x400;
      }
      *(undefined4 *)(param_1 + 0xeb4) = *(undefined4 *)(param_1 + 0x73c);
      if ((*(uint *)(param_1 + 0x73c) & 4) != 0) {
        *(undefined1 *)(param_1 + 0xeb3) = 1;
      }
      *(undefined1 *)(param_1 + 0x65e) = 0;
      *(undefined4 *)(param_1 + 0xe1c) = *(undefined4 *)(param_1 + 0x740);
      if (((*(uint *)(param_1 + 0x73c) >> 0xf & 1) != 0) && (1 < *(byte *)(param_1 + 0x737))) {
        *(byte *)(param_1 + 299) = *(byte *)(param_1 + 0x737);
        *(undefined1 *)(param_1 + 0x12a) = 1;
      }
      if (iVar1 == 0) {
        uVar5 = *(uint *)(param_1 + 0x73c);
        if ((uVar5 & 8) != 0) {
          *(undefined1 *)(param_1 + 0x1398) = 1;
          uVar5 = *(uint *)(param_1 + 0x73c);
        }
        if ((uVar5 & 0x10) != 0) {
          *(undefined1 *)(param_1 + 0x13b0) = 1;
          uVar5 = *(uint *)(param_1 + 0x73c);
        }
        if ((uVar5 & 0x20) != 0) {
          *(undefined1 *)(param_1 + 0x13c8) = 1;
        }
      }
      *(undefined4 *)(param_1 + 0x618) = 600000;
      if ((*(byte *)(param_1 + 0x750) & 2) != 0) {
        if (*(ushort *)(param_1 + 0x2ea) < 0x2c1) {
          return 0x201;
        }
        pcVar9 = "Max MPI message frame size is exceeded";
        uVar8 = 0xad01007a;
        goto LAB_14000e0a1;
      }
    }
  }
  pcVar9 = "Handshake of a IOCFacts message failed";
  uVar8 = 0xad01000d;
LAB_14000e0a1:
  uVar6 = LogSystemEvent(param_1,uVar8,0xc004af02,(byte *)pcVar9,param_2);
  return uVar6 & 0xffffffffffffff00;
}



===== IssueLogSenseToSataDevice @ 14000e0d0 =====

ulonglong IssueLogSenseToSataDevice(longlong param_1,ushort param_2,int param_3)

{
  char cVar1;
  longlong *plVar2;
  byte bVar3;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 uVar4;
  int iVar5;
  longlong lVar6;
  ushort *puVar7;
  ushort *puVar8;
  longlong lVar9;
  
  lVar9 = *(longlong *)(param_1 + 0xb4c8);
  cVar1 = *(char *)(param_1 + 0xeb2);
  if (lVar9 == 0) {
    plVar2 = *(longlong **)(param_1 + 0x5d0);
    lVar9 = *plVar2;
    if (*(longlong *)(lVar9 + 8) != 0) {
      return (ulonglong)plVar2 & 0xffffffffffffff00;
    }
    *(longlong *)(param_1 + 0xb4c8) = lVar9;
    *(longlong **)(param_1 + 0x5d0) = plVar2 + 1;
    if (plVar2 + 1 == *(longlong **)(param_1 + 0x5e0)) {
      *(undefined8 *)(param_1 + 0x5d0) = *(undefined8 *)(param_1 + 0x5c8);
    }
  }
  *(uint *)(lVar9 + 0x18) = *(uint *)(lVar9 + 0x18) | 0x100;
  puVar7 = (ushort *)
           ((longlong)(int)((uint)*(ushort *)(param_1 + 0x2ea) * (uint)*(ushort *)(lVar9 + 0x10)) +
           *(longlong *)(param_1 + 0x310));
  puVar8 = puVar7;
  for (lVar6 = 0x70; lVar6 != 0; lVar6 = lVar6 + -1) {
    *(undefined1 *)puVar8 = 0;
    puVar8 = (ushort *)((longlong)puVar8 + 1);
  }
  *puVar7 = param_2;
  puVar7[0x12] = 10;
  *(undefined1 *)(puVar7 + 10) = 0x18;
  puVar7[0x1e] = 0;
  puVar7[0x1f] = 0x200;
  puVar7[0xe] = 0x100;
  puVar7[0xf] = 0;
  *(int *)(puVar7 + 6) = *(int *)(param_1 + 0xea0) - *(int *)(param_1 + 0x100);
  *(undefined1 *)(puVar7 + 9) = 0xff;
  *(undefined1 *)(puVar7 + 0x20) = 0x4d;
  *(undefined1 *)(puVar7 + 0x21) = 0x6f;
  *(undefined2 *)((longlong)puVar7 + 0x47) = 1;
  iVar5 = *(int *)(param_1 + 0xb4c0) - *(int *)(param_1 + 0x100);
  if (cVar1 == '\0') {
    puVar7[0x30] = 0x100;
    puVar7[0x31] = 0xd300;
    *(int *)(puVar7 + 0x32) = iVar5;
    *(undefined4 *)(puVar7 + 0x34) = *(undefined4 *)(param_1 + 0x1ec);
  }
  else {
    puVar7[0x34] = 0x100;
    puVar7[0x35] = 0;
    *(undefined1 *)((longlong)puVar7 + 0x6f) = 0x40;
    *(int *)(puVar7 + 0x30) = iVar5;
    *(undefined4 *)(puVar7 + 0x32) = *(undefined4 *)(param_1 + 0x1ec);
  }
  QueueRequestDescriptor
            (param_1,(uint)*(ushort *)(lVar9 + 0x10) << 0x10,(uint)param_2 << 0x10,param_3);
  bVar3 = GtfStartTimer(param_1,1,5,LogSenseSataTimeout,0,param_3);
  *(byte *)(param_1 + 0xb4aa) = bVar3;
  uVar4 = extraout_var;
  if (((bVar3 == 0xfe) && (*(char *)(param_1 + 0x3b8) != '\0')) &&
     ((*(uint *)(param_1 + 0x3bc) & 0x233) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x233,(undefined1 *)0x0,0
                ,param_3);
    uVar4 = extraout_var_00;
  }
  return CONCAT71(uVar4,1);
}



===== IssueLunReset @ 14000e290 =====

void IssueLunReset(longlong param_1,int param_2)

{
  undefined2 uVar1;
  undefined8 *puVar2;
  longlong lVar3;
  
  puVar2 = *(undefined8 **)(param_1 + 800);
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x5e8) + 0x68);
  uVar1 = *(undefined2 *)
           (*(longlong *)(param_1 + 0x378) + 0x1a +
           ((ulonglong)*(byte *)(lVar3 + 0x5a) * 0x80 + (ulonglong)*(byte *)(lVar3 + 0x5b)) * 0x28);
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0;
  puVar2[5] = 0;
  *(undefined4 *)(puVar2 + 6) = 0;
  *(undefined2 *)puVar2 = uVar1;
  *(undefined1 *)((longlong)puVar2 + 3) = 1;
  *(undefined1 *)((longlong)puVar2 + 5) = 5;
  *(undefined1 *)((longlong)puVar2 + 0xd) = *(undefined1 *)(lVar3 + 0x5c);
  QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x66e) * 0x10000 + 6,0,param_2);
  if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x20007) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x20007,
                (undefined1 *)(lVar3 + 0x5a),3,param_2);
  }
  AfdMasterTrigger(param_1,4,param_2);
  return;
}



===== IssuePortFacts @ 14000e390 =====

undefined8 IssuePortFacts(longlong param_1,undefined1 param_2,int param_3)

{
  bool bVar1;
  ulonglong uVar2;
  
  *(undefined8 *)(param_1 + 0x680) = 0;
  *(undefined4 *)(param_1 + 0x688) = 0;
  *(undefined8 *)(param_1 + 0x720) = 0;
  *(undefined8 *)(param_1 + 0x728) = 0;
  *(undefined8 *)(param_1 + 0x730) = 0;
  *(undefined4 *)(param_1 + 0x738) = 0;
  *(undefined1 *)(param_1 + 0x686) = param_2;
  *(undefined1 *)(param_1 + 0x683) = 5;
  bVar1 = SendMessageViaHandShake(param_1,0,3);
  if (bVar1) {
    uVar2 = ReceiveDataViaHandshake(param_1,0xe);
    if ((char)uVar2 != '\0') {
      return CONCAT71((int7)(uVar2 >> 8),1);
    }
  }
  uVar2 = LogSystemEvent(param_1,0xad01000f,0xc004af02,
                         (byte *)"Handshake of PortFacts message failed",param_3);
  return uVar2 & 0xffffffffffffff00;
}



===== IssueReset @ 14000e440 =====

ulonglong IssueReset(longlong param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  
  **(int **)(param_1 + 0x18) = param_2 << 0x18;
  LOCK();
  UNLOCK();
  uVar2 = 0;
  do {
    piVar1 = *(int **)(param_1 + 0x48);
    if (*piVar1 == -1) break;
    if (-1 < *piVar1) {
      return CONCAT71((int7)((ulonglong)piVar1 >> 8),1);
    }
    piVar1 = (int *)StorPortStallExecution(500);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 120000);
  return (ulonglong)piVar1 & 0xffffffffffffff00;
}



===== KickStart @ 14000e4a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong KickStart(longlong param_1,int param_2)

{
  undefined1 *puVar1;
  uint *puVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  longlong lVar9;
  undefined1 *puVar10;
  char *pcVar11;
  uint local_res8 [2];
  
  local_res8[0] = **(uint **)(param_1 + 0x18);
  puVar2 = (uint *)(ulonglong)local_res8[0];
  if (local_res8[0] != 0xffffffff) {
    if ((local_res8[0] & 0xf0000000) == 0x40000000) {
      uVar7 = local_res8[0] & 0xffff;
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x240) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x240,
                    (undefined1 *)local_res8,4,param_2);
      }
      LogSystemEvent(param_1,uVar7 + 0xad0f0000,0xc004af02,(byte *)"FW Fault code logged",param_2);
      if ((short)local_res8[0] == 0x2810) {
        *(undefined2 *)(param_1 + 0xe79) = 0x101;
        puVar2 = (uint *)CompleteAllSrbs(param_1);
        if ((*(char *)(param_1 + 0x3b8) != '\0') &&
           (puVar2 = (uint *)(ulonglong)*(uint *)(param_1 + 0x3bc),
           (*(uint *)(param_1 + 0x3bc) & 0x242) != 0)) {
          puVar2 = (uint *)RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),
                                       0x242,(undefined1 *)0x0,0,param_2);
        }
        goto LAB_14000e69d;
      }
      if (*(char *)(param_1 + 0xe72) != '\0') {
        *(undefined4 *)(param_1 + 0x1524) = _DAT_0000face;
      }
      uVar7 = 1;
    }
    else {
      uVar7 = 2;
    }
    AfdMasterTrigger(param_1,uVar7,param_2);
    if (*(char *)(param_1 + 0xe72) != '\0') {
      *(undefined4 *)(param_1 + 0x1524) = _DAT_0000dead;
    }
    *(undefined1 *)(param_1 + 0xeba) = 1;
    EnableDiagnosticRegister(param_1,param_2);
    uVar7 = **(uint **)(param_1 + 0xe0);
    **(uint **)(param_1 + 0x28) = **(uint **)(param_1 + 0x28) | 4;
    LOCK();
    UNLOCK();
    lVar9 = 0x32;
    do {
      StorPortStallExecution(1000);
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    uVar5 = 0;
    uVar6 = 0;
    do {
      puVar2 = *(uint **)(param_1 + 0x28);
      uVar8 = *puVar2;
      if (uVar8 == 0xffffffff) goto LAB_14000e69d;
      if ((uVar8 & 4) == 0) break;
      StorPortStallExecution(500);
      uVar6 = uVar6 + 1;
    } while (uVar6 < 600000);
    if (uVar6 == 600000) {
      pcVar11 = "Reset of IOC failed";
      uVar4 = 0xad010023;
    }
    else {
      if ((uVar8 >> 8 & 1) != 0) {
        uVar8 = uVar8 & 0xffffefff | 0x800;
        **(uint **)(param_1 + 0x28) = uVar8;
        LOCK();
        UNLOCK();
        **(uint **)(param_1 + 0xe0) = uVar7 | 1;
        LOCK();
        UNLOCK();
      }
      **(uint **)(param_1 + 0x28) = uVar8 & 0xfffffffd;
      LOCK();
      UNLOCK();
      **(undefined4 **)(param_1 + 0x20) = 0;
      LOCK();
      UNLOCK();
      uVar3 = GtfInitialize(param_1);
      pcVar11 = (char *)(param_1 + 0x1399);
      lVar9 = 3;
      do {
        if (((pcVar11[-1] != '\0') && (*pcVar11 != '\0')) && (pcVar11[1] != '\0')) {
          puVar1 = *(undefined1 **)(param_1 + 0x608);
          if (*(ushort *)(param_1 + 0x2ea) != 0) {
            puVar10 = puVar1;
            for (uVar3 = (ulonglong)*(ushort *)(param_1 + 0x2ea); uVar3 != 0; uVar3 = uVar3 - 1) {
              *puVar10 = 0;
              puVar10 = puVar10 + 1;
            }
          }
          puVar1[1] = pcVar11[-5];
          puVar1[3] = 0x1e;
          uVar3 = QueueRequestDescriptor
                            (param_1,(uint)*(ushort *)(param_1 + 0x66a) * 0x10000 + 8,0,param_2);
          pcVar11[1] = '\0';
          pcVar11[-3] = '\x01';
        }
        pcVar11 = pcVar11 + 0x18;
        lVar9 = lVar9 + -1;
      } while (lVar9 != 0);
      if ((*(char *)(param_1 + 0xe7c) != '\0') || (*(int *)(param_1 + 0xec0) != 0)) {
LAB_14000e818:
        return CONCAT71((int7)(uVar3 >> 8),1);
      }
      do {
        local_res8[0] = **(uint **)(param_1 + 0x18);
        puVar2 = (uint *)(ulonglong)local_res8[0];
        if (local_res8[0] == 0xffffffff) goto LAB_14000e69d;
        if ((local_res8[0] & 0xf0000000) == 0x10000000) break;
        StorPortStallExecution(1000);
        uVar5 = uVar5 + 1;
      } while (uVar5 < 60000);
      uVar3 = 0;
      if (uVar5 < 60000) {
        if ((*(char *)(param_1 + 0x3b8) != '\0') &&
           (uVar3 = (ulonglong)*(uint *)(param_1 + 0x3bc),
           (*(uint *)(param_1 + 0x3bc) >> 0x12 & 1) != 0)) {
          uVar3 = RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x40000,
                              (undefined1 *)(param_1 + 0xe48),4,param_2);
        }
        goto LAB_14000e818;
      }
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) >> 9 & 1) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x200,
                    (undefined1 *)(param_1 + 0xe48),4,param_2);
      }
      pcVar11 = s_IOC_wouldn_t_come_READY_after_k;
      uVar4 = 0xad01000b;
    }
    puVar2 = (uint *)LogSystemEvent(param_1,uVar4,0xc004af02,(byte *)pcVar11,param_2);
  }
LAB_14000e69d:
  return (ulonglong)puVar2 & 0xffffffffffffff00;
}



===== LSImpiAdapterControl @ 14000e880 =====

undefined8 LSImpiAdapterControl(longlong param_1,int param_2,longlong param_3)

{
  int iVar1;
  undefined8 uVar2;
  byte bVar3;
  
  if (param_2 == 0) {
    *(undefined2 *)(param_3 + 4) = 0x101;
    *(undefined1 *)(param_3 + 6) = 1;
    return 0;
  }
  if (param_2 == 1) {
    *(undefined1 *)(param_1 + 0xe7f) = 1;
    if (*(char *)(param_1 + 0xe7c) == '\0') {
      **(uint **)(param_1 + 0x50) = **(uint **)(param_1 + 0x50) | 0x40000009;
      LOCK();
      UNLOCK();
      CheckForIRShutdown(param_1,'\x01',7);
      if (*(short *)(param_1 + 0xb320) != 0) {
        bVar3 = 8;
        do {
          if (bVar3 == 8) {
            *(undefined4 *)(param_1 + 0xb318) = 0;
            bVar3 = 9;
            *(undefined2 *)(param_1 + 0xb322) = 0;
LAB_14000eace:
            *(undefined4 *)(param_1 + 0xb31c) = 20000;
          }
          else if (bVar3 == 9) {
            SendSsuMessagesToDevices(param_1);
            bVar3 = -(*(int *)(param_1 + 0xb318) != 0) & 10;
          }
          else if (bVar3 == 10) {
            uVar2 = ProcessSsuReplies(param_1,7);
            iVar1 = (int)uVar2;
            if (iVar1 == 1) {
              if ((*(char *)(param_1 + 0x3b8) != '\0') &&
                 ((*(uint *)(param_1 + 0x3bc) & 0x80002) != 0)) {
                RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x80002,
                            (undefined1 *)(param_1 + 0xb318),4,7);
              }
              bVar3 = 0;
            }
            else if (iVar1 == 2) {
              bVar3 = 9;
            }
            else if (iVar1 == 3) {
              bVar3 = 0xb;
            }
          }
          else {
            if (bVar3 == 0xb) {
              SendSsuTmrMessagesToDevices(param_1,7);
              bVar3 = 0xc;
              goto LAB_14000eace;
            }
            if (bVar3 == 0xc) {
              uVar2 = ProcessSsuTmrReplies(param_1,7);
              if ((int)uVar2 - 1U < 2) {
                bVar3 = 0;
              }
            }
            else {
              LogSystemEvent(param_1,0xad010072,0xc004af02,
                             (byte *)"Sending SSU commands Failed in SCSI STOP ADAPTER ",7);
            }
          }
          StorPortStallExecution(500);
        } while (bVar3 != 0);
      }
      FlushAllDPMPage0(param_1,7);
      *(undefined1 *)(param_1 + 0xe7d) = 1;
      if ((*(uint *)(param_1 + 0xeb4) & 0x2000) == 0) {
        KickStart(param_1,7);
        *(undefined1 *)(param_1 + 0xe7c) = 1;
        *(undefined1 *)(param_1 + 0xe7f) = 0;
        return 0;
      }
      IssueReset(param_1,0x40);
      *(undefined1 *)(param_1 + 0xe7c) = 1;
      *(undefined1 *)(param_1 + 0xe7f) = 0;
      return 0;
    }
    *(undefined1 *)(param_1 + 0xe7d) = 1;
  }
  else if (param_2 == 2) {
    *(undefined1 *)(param_1 + 0xe7f) = 1;
    *(undefined4 *)(param_1 + 0xec0) = 1;
    *(undefined2 *)(param_1 + 0xebc) = 0;
    *(undefined1 *)(param_1 + 0xe7d) = 0;
    StorPortPause(param_1,300);
    if (((*(uint *)(param_1 + 0xeb4) & 0x2000) == 0) || (**(int **)(param_1 + 0x18) == 0)) {
      *(undefined4 *)(param_1 + 0x63c) = *(undefined4 *)(param_1 + 0x640);
      *(undefined1 *)(param_1 + 0xe7f) = 0;
      return 0;
    }
    IssueReset(param_1,0x40);
    *(undefined1 *)(param_1 + 0xe7f) = 0;
    return 0;
  }
  return 0;
}



===== LSImpiReset @ 14000eb80 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 LSImpiReset(longlong param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint *in_RAX;
  undefined8 uVar2;
  ulonglong uVar3;
  ushort local_res8 [4];
  undefined2 local_res20 [4];
  
  if (*(short *)(param_1 + 0x620) != 0) {
    in_RAX = (uint *)LogSystemEvent(param_1,0xad010016,0xc004af02,
                                    (byte *)"Task Management bus reset message issued",param_3);
  }
  uVar1 = 0;
  if ((*(char *)(param_1 + 0x3b8) != '\0') &&
     (in_RAX = (uint *)(ulonglong)*(uint *)(param_1 + 0x3bc),
     (*(uint *)(param_1 + 0x3bc) & 0x20013) != 0)) {
    in_RAX = (uint *)RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x20013,
                                 (undefined1 *)0x0,0,param_3);
  }
  if (*(char *)(param_1 + 0xe71) != '\0') {
    in_RAX = (uint *)(ulonglong)_DAT_00000002;
    *(uint *)(param_1 + 0x1524) = _DAT_00000002;
  }
  if (*(int *)(param_1 + 0xec0) == 0) {
    if (*(longlong *)(param_1 + 0x5e8) != 0) {
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x20015) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x20015,
                    (undefined1 *)0x0,0,param_3);
      }
      LogSystemEvent(param_1,0xad010036,0xc004af02,
                     (byte *)"LUN/Target reset still active when a Bus Reset request was received",
                     param_3);
      **(uint **)(param_1 + 0x50) = **(uint **)(param_1 + 0x50) | 0x40000009;
      LOCK();
      UNLOCK();
      if (*(int *)(param_1 + 0x630) == 0) {
        StorPortPause(param_1,400);
      }
      *(undefined4 *)(param_1 + 0xec0) = 1;
      uVar2 = KickStart(param_1,param_3);
      return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
    }
    in_RAX = *(uint **)(param_1 + 0x18);
    if ((*in_RAX & 0xf0000000) == 0x20000000) {
      if (*(int *)(param_1 + 0x628) == 0) {
        if (((*(char *)(param_1 + 0xec8) != '\0') && (*(byte *)(param_1 + 0xec9) == param_2)) &&
           (*(char *)((longlong)*(short **)(param_1 + 0xf20) + 3) == '\0')) {
          uVar3 = GetBusTargetFromDevHandle
                            (param_1,**(short **)(param_1 + 0xf20),local_res8,local_res20);
          if (((char)uVar3 != '\0') && (local_res8[0] != param_2)) {
            *(ushort *)(param_1 + 0x624) =
                 *(ushort *)(param_1 + 0x624) | (ushort)(1 << (param_2 & 0x1f));
            param_2 = (uint)local_res8[0];
          }
        }
        *(undefined1 *)(param_1 + 0x161c) = 0;
        *(undefined2 *)(param_1 + 0x76a) = 1;
        *(char *)(param_1 + 0xe78) = (char)param_2;
        in_RAX = (uint *)ProcessBusReset(param_1,param_3);
        if ((char)in_RAX != '\0') {
          in_RAX = (uint *)ResetActive(param_1,3,param_3);
          *(undefined1 *)(param_1 + 0xeb8) = 1;
          if (*(int *)(param_1 + 0x630) == 0) {
            in_RAX = (uint *)StorPortPause(param_1,300);
          }
          else {
            while (*(int *)(param_1 + 0x628) != 0) {
              PollLSImpiIsr(param_1,param_3);
              in_RAX = (uint *)StorPortStallExecution(500);
              uVar1 = uVar1 + 1;
              if (119999 < uVar1) {
                return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
              }
            }
          }
        }
      }
      else if ((*(char *)(param_1 + 0xe7e) != '\0') || ((char)param_2 != *(char *)(param_1 + 0xe78))
              ) {
        uVar1 = (uint)*(ushort *)(param_1 + 0x624) | 1 << (param_2 & 0x1f);
        *(short *)(param_1 + 0x624) = (short)uVar1;
        return CONCAT71((uint7)(uint3)(uVar1 >> 8),1);
      }
    }
  }
  else if ((*(char *)(param_1 + 0x3b8) != '\0') &&
          (in_RAX = (uint *)(ulonglong)*(uint *)(param_1 + 0x3bc),
          (*(uint *)(param_1 + 0x3bc) & 0x20014) != 0)) {
    uVar2 = RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x20014,
                        (undefined1 *)0x0,0,param_3);
    return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
  }
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}



===== LogSenseSataTimeout @ 14000ee80 =====

ulonglong LogSenseSataTimeout(longlong param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  ushort uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  
  uVar1 = *(ushort *)(param_1 + 0xb4b0);
  lVar2 = *(longlong *)(param_1 + 0x378);
  if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x245) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x245,(undefined1 *)0x0,0
                ,param_4);
  }
  puVar3 = *(undefined8 **)(param_1 + 0x330);
  *(undefined1 *)(param_1 + 0xb4a9) = 1;
  *puVar3 = 0;
  puVar3[1] = 0;
  puVar3[2] = 0;
  puVar3[3] = 0;
  puVar3[4] = 0;
  puVar3[5] = 0;
  *(undefined4 *)(puVar3 + 6) = 0;
  *(undefined2 *)puVar3 = *(undefined2 *)(lVar2 + (ulonglong)uVar1 * 0x28 + 0x1a);
  *(undefined1 *)((longlong)puVar3 + 3) = 1;
  *(undefined1 *)((longlong)puVar3 + 5) = 1;
  uVar4 = QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x672) * 0x10000 + 6,0,param_4)
  ;
  return uVar4 & 0xffffffffffffff00;
}



===== LsiHandleAppRequest @ 14000ef60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LsiHandleAppRequest(longlong param_1,void *param_2,int param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 *puVar7;
  char cVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  byte bVar11;
  ulonglong uVar12;
  short sVar13;
  undefined1 local_a8 [32];
  char local_68 [8];
  void *local_60;
  undefined4 local_58;
  undefined4 local_54;
  char local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)local_a8;
  lVar4 = *(longlong *)((longlong)param_2 + 0x40);
  local_58 = *(undefined4 *)(lVar4 + 0x10);
  local_50 = 0;
  local_54 = 0;
  *(void **)(param_1 + 0xed8) = param_2;
  *(void **)(param_1 + 0xed0) = param_2;
  *(undefined4 *)(param_1 + 0xf34) = 0;
  uVar2 = *(uint *)(lVar4 + 0x10);
  local_60 = param_2;
  if (uVar2 < 0x806d706a) {
    if (uVar2 == 0x806d7069) {
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x400012) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x400012,
                    (undefined1 *)&local_60,0x11,param_3);
      }
      if (*(int *)(param_1 + 0x628) == 0) {
        cVar8 = SendIOCTLMessage(param_1,(ushort *)(lVar4 + 0x1c),param_2,param_3);
        if (cVar8 != '\0') {
          return;
        }
        *(undefined4 *)((longlong)param_2 + 0x10) = 0;
      }
      else {
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x400009) != 0))
        {
          RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x400009,
                      (undefined1 *)&local_60,0x11,param_3);
        }
        *(undefined4 *)((longlong)param_2 + 0x10) = 0;
      }
      goto LAB_14000f3e1;
    }
    if (uVar2 == 0x1b0780) {
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x40000f) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x40000f,
                    (undefined1 *)&local_60,0x11,param_3);
      }
      uVar12 = 0;
      do {
        bVar11 = (byte)uVar12;
        if ((uint)*(byte *)(lVar4 + 4 + uVar12) != (int)"FIRMWARE"[uVar12]) {
          *(undefined4 *)((longlong)param_2 + 0x10) = 0;
          if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x25c) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x25c,
                        (undefined1 *)0x0,0,param_3);
          }
          break;
        }
        bVar11 = bVar11 + 1;
        uVar12 = (ulonglong)bVar11;
      } while (bVar11 < 8);
      if (bVar11 == 8) {
        HbaFwReloadFsm(param_1,'\0',0,param_3);
        return;
      }
      goto LAB_14000f3e1;
    }
    if (uVar2 == 0x800000ff) {
      if ((*(char *)(param_1 + 0x3b8) == '\0') || ((*(uint *)(param_1 + 0x3bc) & 0x400010) == 0))
      goto LAB_14000f3e1;
      uVar9 = 0x400010;
      goto LAB_14000f3dc;
    }
    if (uVar2 == 0x8043494d) {
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x400011) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x400011,
                    (undefined1 *)&local_60,0x11,param_3);
      }
      uVar12 = 0;
      do {
        bVar11 = (byte)uVar12;
        if (*(char *)(lVar4 + 4 + uVar12) != (&CIM_IOCTLVER)[uVar12]) {
          *(undefined4 *)((longlong)param_2 + 0x10) = 0;
          if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x25d) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x25d,
                        (undefined1 *)&local_60,0x11,param_3);
          }
          break;
        }
        bVar11 = bVar11 + 1;
        uVar12 = (ulonglong)bVar11;
      } while (bVar11 < 4);
      if (bVar11 == 4) {
        lVar5 = *(longlong *)((longlong)param_2 + 0x40);
        memmove((void *)(lVar5 + 0x20),&AdapPageVersion,4);
        iVar3 = *(int *)(lVar5 + 0x1c);
        if (iVar3 == 1) {
          lVar5 = *(longlong *)((longlong)param_2 + 0x40);
          if (*(uint *)(lVar5 + 0x18) < 0x58) {
            *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
          }
          else {
            memmove((void *)(lVar5 + 0x24),(void *)(param_1 + 0xe00),0x50);
            *(undefined4 *)(lVar5 + 0x3c) = 0;
            *(undefined1 *)(param_1 + 0xe44) = 0;
            *(undefined4 *)((longlong)param_2 + 0x3c) = 0x74;
          }
        }
        else if (iVar3 == 3) {
          if (*(uint *)(*(longlong *)((longlong)param_2 + 0x40) + 0x18) < 0x114) {
            *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
          }
          else {
            memmove((void *)(*(longlong *)((longlong)param_2 + 0x40) + 0x30),
                    (void *)(param_1 + 0x1400),0x100);
            *(undefined4 *)((longlong)param_2 + 0x3c) = 0x130;
          }
        }
        else if (iVar3 == 10) {
          if (*(uint *)(lVar5 + 0x18) < 0x1c) {
            *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
          }
          else {
            *(undefined4 *)(lVar5 + 0x24) = 200;
            memmove((void *)(lVar5 + 0x28),(void *)(param_1 + 0xe54),0x10);
            *(undefined4 *)((longlong)param_2 + 0x3c) = 0x38;
          }
        }
        else if (iVar3 == 0xb) {
          if (*(uint *)(lVar5 + 0x18) < 0x18) {
            *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
          }
          else {
            memmove((void *)(param_1 + 0xe54),(void *)(lVar5 + 0x24),0x10);
            *(uint *)(param_1 + 0xe60) = *(uint *)(param_1 + 0xe60) | 0x4000;
            *(undefined4 *)((longlong)param_2 + 0x3c) = 0x34;
          }
        }
        else if (iVar3 == 0xc) {
          if (*(uint *)(lVar5 + 0x18) < 0x9c48) {
            *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
          }
          else {
            memmove((void *)(lVar5 + 0x24),(void *)(param_1 + 0x16d8),40000);
            *(undefined4 *)((longlong)param_2 + 0x3c) = 0x9c64;
          }
        }
        else {
          *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
        }
      }
      goto LAB_14000f3e1;
    }
    if (uVar2 == 0x804d4150) {
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x400018) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x400018,
                    (undefined1 *)&local_60,0x11,param_3);
      }
      uVar10 = BusTargetDevHandleMapping(param_1,(longlong)param_2);
      *(int *)((longlong)param_2 + 0x3c) = (int)uVar10;
      goto LAB_14000f3e1;
    }
    if (uVar2 != 0x80646961) goto LAB_14000f5da;
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x400016) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x400016,
                  (undefined1 *)&local_60,0x11,param_3);
    }
    uVar12 = 0;
    do {
      bVar11 = (byte)uVar12;
      if (*(char *)(lVar4 + 4 + uVar12) != (&FW_DIAG_IOCTLSIG)[uVar12]) {
        *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x262) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x262,
                      (undefined1 *)&local_60,0x11,param_3);
        }
        break;
      }
      bVar11 = bVar11 + 1;
      uVar12 = (ulonglong)bVar11;
    } while (bVar11 < 8);
    if (bVar11 != 8) goto LAB_14000f3e1;
    *(void **)(param_1 + 0x13f8) = param_2;
    uVar10 = PerformFwDiagOperation(param_1,lVar4,local_68,param_3);
    if ((char)uVar10 != '\0') {
      if (local_68[0] == '\0') {
        *(undefined1 *)(param_1 + 0xec8) = 1;
        return;
      }
      goto LAB_14000f3e1;
    }
  }
  else {
    if (uVar2 == 0x80727374) {
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x400013) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x400013,
                    (undefined1 *)&local_60,0x11,param_3);
      }
      uVar12 = 0;
      do {
        bVar11 = (byte)uVar12;
        if (*(char *)(lVar4 + 4 + uVar12) != (&RST_IOCTLSIG)[uVar12]) {
          *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
          if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x25e) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x25e,
                        (undefined1 *)&local_60,0x11,param_3);
          }
          break;
        }
        bVar11 = bVar11 + 1;
        uVar12 = (ulonglong)bVar11;
      } while (bVar11 < 8);
      if (bVar11 == 8) {
        if (*(uint *)((longlong)param_2 + 0x28) < 0x1e) {
          *(undefined4 *)((longlong)param_2 + 0x28) = 0x1e;
        }
        *(undefined1 *)(param_1 + 0xec8) = 1;
        StorPortPause(param_1,400);
        ResetActive(param_1,0xb,param_3);
        puVar7 = *(undefined8 **)(param_1 + 0x608);
        *puVar7 = 0;
        puVar7[1] = 0;
        puVar7[2] = 0;
        puVar7[3] = 0;
        puVar7[4] = 0;
        *(undefined4 *)(puVar7 + 5) = 0;
        *(undefined1 *)((longlong)puVar7 + 3) = 7;
        *(undefined8 *)((longlong)puVar7 + 0x14) = 0xffffffffffffffff;
        *(undefined8 *)((longlong)puVar7 + 0x1c) = 0xffffffffffffffff;
        *(undefined1 *)(param_1 + 0xe69) = 1;
        **(int **)(param_1 + 0xe8) = (uint)*(ushort *)(param_1 + 0x66a) * 0x10000 + 8;
        LOCK();
        UNLOCK();
        **(undefined4 **)(param_1 + 0xf0) = 0;
        LOCK();
        UNLOCK();
        *(undefined4 *)(param_1 + 0x638) = 4;
        return;
      }
      goto LAB_14000f3e1;
    }
    if (uVar2 != 0x80727474) {
      if (uVar2 == 0x80727574) {
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x400015) != 0))
        {
          RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x400015,
                      (undefined1 *)&local_60,0x11,param_3);
        }
        uVar12 = 0;
        do {
          bVar11 = (byte)uVar12;
          if (*(char *)(lVar4 + 4 + uVar12) != (&AUTO_FW_DIAG_IOCTL_SIG)[uVar12]) {
            *(undefined4 *)((longlong)param_2 + 0x10) = 0;
            if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x261) != 0))
            {
              RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x261,
                          (undefined1 *)&local_60,0x11,param_3);
            }
            break;
          }
          bVar11 = bVar11 + 1;
          uVar12 = (ulonglong)bVar11;
        } while (bVar11 < 8);
        if (bVar11 == 8) {
          uVar10 = HandleAfdTriggerIoctl(param_1,lVar4);
          if ((char)uVar10 == '\0') {
            *(undefined1 *)((longlong)param_2 + 3) = 1;
          }
        }
        else {
          *(undefined4 *)(lVar4 + 0x14) = 5;
        }
        goto LAB_14000f3e1;
      }
      if (uVar2 == 0x80727676) {
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x400014) != 0))
        {
          RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x400014,
                      (undefined1 *)&local_60,0x11,param_3);
        }
        uVar12 = 0;
        do {
          bVar11 = (byte)uVar12;
          if (*(char *)(lVar4 + 4 + uVar12) != RS_IOCTL_SIGNATURE[uVar12]) {
            *(undefined4 *)((longlong)param_2 + 0x10) = 0;
            if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x25f) != 0))
            {
              RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x25f,
                          (undefined1 *)&local_60,0x11,param_3);
            }
            break;
          }
          bVar11 = bVar11 + 1;
          uVar12 = (ulonglong)bVar11;
        } while (bVar11 < 8);
        if (bVar11 == 8) {
          uVar10 = RsIoctl_sm(param_1,(longlong)param_2,0,param_3);
          if ((char)uVar10 != '\0') {
            return;
          }
          *(undefined1 *)((longlong)param_2 + 3) = 1;
        }
        goto LAB_14000f3e1;
      }
      if (uVar2 == 0x80771959) {
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x400017) != 0))
        {
          RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x400017,
                      (undefined1 *)&local_60,0x11,param_3);
        }
        uVar12 = 0;
        do {
          bVar11 = (byte)uVar12;
          if (*(char *)(lVar4 + 4 + uVar12) != (&MPI_IOCTLVER)[uVar12]) {
            *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
            if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x263) != 0))
            {
              RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x263,
                          (undefined1 *)&local_60,0x11,param_3);
            }
            break;
          }
          bVar11 = bVar11 + 1;
          uVar12 = (ulonglong)bVar11;
        } while (bVar11 < 4);
        if (bVar11 == 4) {
          lVar5 = *(longlong *)((longlong)param_2 + 0x40);
          lVar6 = *(longlong *)(param_1 + 0xf8);
          uVar9 = *(undefined4 *)(lVar5 + 0x24);
          sVar13 = (short)lVar6 + (short)*(uint *)(lVar5 + 0x20);
          puVar1 = (undefined4 *)
                   ((ulonglong)*(uint *)(lVar5 + 0x20) + *(longlong *)(param_1 + 0x10));
          iVar3 = *(int *)(lVar5 + 0x1c);
          if (iVar3 == 1) {
            if (lVar6 == 0) {
              *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
              *(undefined4 *)(lVar5 + 0x24) = uVar9;
            }
            else {
              uVar9 = in(sVar13);
              *(undefined4 *)(lVar5 + 0x24) = uVar9;
            }
          }
          else if (iVar3 == 2) {
            if (lVar6 == 0) {
              *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
              *(undefined4 *)(lVar5 + 0x24) = uVar9;
            }
            else {
              out(sVar13,uVar9);
              *(undefined4 *)(lVar5 + 0x24) = uVar9;
            }
          }
          else if (iVar3 == 3) {
            *(undefined4 *)(lVar5 + 0x24) = *puVar1;
          }
          else if (iVar3 == 4) {
            *puVar1 = uVar9;
            LOCK();
            UNLOCK();
            *(undefined4 *)(lVar5 + 0x24) = uVar9;
          }
          else {
            *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
            *(undefined4 *)(lVar5 + 0x24) = uVar9;
          }
        }
        goto LAB_14000f3e1;
      }
LAB_14000f5da:
      *(undefined1 *)((longlong)param_2 + 3) = 6;
      *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
      local_50 = 6;
      local_54 = *(undefined4 *)(lVar4 + 0x14);
      if ((*(char *)(param_1 + 0x3b8) == '\0') || ((*(uint *)(param_1 + 0x3bc) & 0x400019) == 0))
      goto LAB_14000f3e1;
      uVar9 = 0x400019;
LAB_14000f3dc:
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),uVar9,
                  (undefined1 *)&local_60,0x11,param_3);
      goto LAB_14000f3e1;
    }
    uVar12 = 0;
    do {
      bVar11 = (byte)uVar12;
      if (*(char *)(lVar4 + 4 + uVar12) != RTTRACE_IOCTL_SIG[uVar12]) {
        *(undefined4 *)((longlong)param_2 + 0x10) = 0;
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x260) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x260,
                      (undefined1 *)&local_60,0x11,param_3);
        }
        break;
      }
      bVar11 = bVar11 + 1;
      uVar12 = (ulonglong)bVar11;
    } while (bVar11 < 8);
    if (bVar11 != 8) goto LAB_14000f3e1;
    uVar10 = HandleRttIoctl(param_1,lVar4,local_68);
    if ((char)uVar10 != '\0') {
      if (local_68[0] == '\0') {
        return;
      }
      goto LAB_14000f3e1;
    }
  }
  *(undefined1 *)((longlong)param_2 + 3) = 1;
LAB_14000f3e1:
  local_50 = *(char *)((longlong)param_2 + 3);
  if ((local_50 != '\x03') && (local_50 != '\x06')) {
    if (*(int *)((longlong)param_2 + 0x3c) == 0) {
      *(undefined1 *)((longlong)param_2 + 3) = 4;
      local_50 = '\x04';
    }
    else {
      *(undefined1 *)((longlong)param_2 + 3) = 1;
      local_50 = '\x01';
    }
  }
  local_54 = *(undefined4 *)(lVar4 + 0x14);
  StorPortNotification(0,param_1,param_2);
  *(undefined8 *)(param_1 + 0xed0) = 0;
  if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x40001c) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x40001c,
                (undefined1 *)&local_60,0x11,param_3);
  }
  return;
}



===== LsiMpiPartitionMemory @ 14000fc30 =====

void LsiMpiPartitionMemory(longlong param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  longlong *plVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong lVar8;
  uint uVar9;
  longlong lVar10;
  uint uVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  undefined2 *puVar14;
  undefined1 *puVar15;
  uint uVar16;
  longlong lVar17;
  undefined1 *puVar18;
  undefined4 *puVar19;
  longlong *plVar20;
  undefined8 *puVar21;
  int iVar22;
  
  uVar1 = *(ushort *)(param_1 + 0x654);
  uVar2 = *(ushort *)(param_1 + 0x2ea);
  uVar7 = (ulonglong)uVar2;
  uVar3 = *(ushort *)(param_1 + 0x2e8);
  uVar4 = *(ushort *)(param_1 + 0x2f2);
  *(undefined2 *)(param_1 + 0x624) = 0;
  *(undefined4 *)(param_1 + 0x628) = 0;
  *(undefined4 *)(param_1 + 0xf38) = 0;
  *(undefined8 *)(param_1 + 0x634) = 0;
  *(undefined8 *)(param_1 + 0x5e8) = 0;
  *(undefined8 *)(param_1 + 0x5f0) = 0;
  *(undefined2 *)(param_1 + 0xeb8) = 0;
  *(undefined1 *)(param_1 + 0xe7e) = 0;
  *(undefined1 *)(param_1 + 0xb351) = 0;
  *(undefined2 *)(param_1 + 0xe81) = 0;
  *(undefined2 *)(param_1 + 0xeb0) = 0xfe;
  *(undefined2 *)(param_1 + 0xb4aa) = 0xfefe;
  *(undefined4 *)(param_1 + 0xe86) = 0;
  *(undefined2 *)(param_1 + 0xe84) = 0;
  *(undefined1 *)(param_1 + 0xe8a) = 0;
  *(undefined8 *)(param_1 + 0x1588) = 0;
  *(undefined8 *)(param_1 + 0x1590) = 0;
  *(undefined1 *)(param_1 + 0x1574) = 0;
  *(undefined1 *)(param_1 + 0x380) = 0;
  *(undefined1 *)(param_1 + 0x676) = 0;
  if ((((*(char *)(param_1 + 0xec8) != '\0') || (*(longlong *)(param_1 + 0xed0) != 0)) &&
      (*(char *)(param_1 + 0xe74) == '\0')) && (*(char *)(param_1 + 0xe75) == '\0')) {
    CleanUpIoctl(param_1,param_2);
  }
  uVar11 = (uint)uVar2;
  *(longlong *)(param_1 + 0x310) = *(longlong *)(param_1 + 8);
  *(int *)(param_1 + 0x1f8) = *(int *)(param_1 + 0x1e8);
  *(undefined1 *)(param_1 + 0xec8) = 0;
  *(undefined1 *)(param_1 + 0x15a4) = 0;
  lVar17 = *(longlong *)(param_1 + 8) + (ulonglong)((uVar1 + 1) * uVar11);
  *(undefined2 *)(param_1 + 0x15a0) = 0;
  *(longlong *)(param_1 + 0x608) = lVar17;
  lVar17 = lVar17 + uVar7;
  *(longlong *)(param_1 + 0x318) = lVar17;
  iVar22 = *(int *)(param_1 + 0x1e8) + (uVar1 + 2) * uVar11;
  *(ushort *)(param_1 + 0x66a) = uVar1 + 1;
  *(ulonglong *)(param_1 + 800) = uVar7 + lVar17;
  *(int *)(param_1 + 0x1fc) = iVar22;
  *(ulonglong *)(param_1 + 0x328) = (ulonglong)((uint)uVar2 * 2) + lVar17;
  *(ulonglong *)(param_1 + 0x330) = (ulonglong)((uint)uVar2 * 3) + lVar17;
  *(ulonglong *)(param_1 + 0x338) = (ulonglong)((uint)uVar2 * 4) + lVar17;
  *(uint *)(param_1 + 0x200) = iVar22 + (uint)uVar2;
  *(uint *)(param_1 + 0x204) = (uint)uVar2 * 2 + iVar22;
  *(uint *)(param_1 + 0x208) = (uint)uVar2 * 3 + iVar22;
  *(uint *)(param_1 + 0x20c) = (uint)uVar2 * 4 + iVar22;
  iVar22 = iVar22 + (uint)uVar2 * 5;
  puVar18 = (undefined1 *)(lVar17 + (ulonglong)((uint)uVar2 * 5));
  *(int *)(param_1 + 0x1f0) = iVar22;
  *(undefined1 **)(param_1 + 0x300) = puVar18;
  *(ushort *)(param_1 + 0x66c) = uVar1 + 2;
  *(ushort *)(param_1 + 0x66e) = uVar1 + 3;
  *(ushort *)(param_1 + 0x670) = uVar1 + 4;
  *(ushort *)(param_1 + 0x672) = uVar1 + 5;
  *(ushort *)(param_1 + 0x674) = uVar1 + 6;
  lVar17 = (ulonglong)*(ushort *)(param_1 + 0x2ee) * 4;
  iVar22 = iVar22 + (int)lVar17;
  puVar19 = (undefined4 *)(puVar18 + lVar17);
  if ((int)lVar17 != 0) {
    for (; lVar17 != 0; lVar17 = lVar17 + -1) {
      *puVar18 = 0;
      puVar18 = puVar18 + 1;
    }
  }
  uVar9 = (uint)*(ushort *)(param_1 + 0x2f0);
  *(undefined4 **)(param_1 + 0x308) = puVar19;
  *(int *)(param_1 + 500) = iVar22;
  if (*(char *)(param_1 + 0x12a) != '\0') {
    uVar9 = (uint)*(ushort *)(param_1 + 0x2f0) * (uint)*(byte *)(param_1 + 299);
  }
  puVar18 = (undefined1 *)((longlong)puVar19 + (ulonglong)(uVar9 * 8));
  if (uVar9 != 0) {
    for (uVar6 = (ulonglong)(uVar9 * 2); uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar19 = 0xffffffff;
      puVar19 = puVar19 + 1;
    }
  }
  puVar14 = (undefined2 *)(param_1 + 0x21e);
  for (lVar17 = 0x60; lVar17 != 0; lVar17 = lVar17 + -1) {
    *puVar14 = 0;
    puVar14 = puVar14 + 1;
  }
  uVar16 = 1;
  *(undefined1 **)(param_1 + 0x340) = puVar18;
  plVar20 = (longlong *)(puVar18 + (ulonglong)uVar4 * (ulonglong)uVar3);
  *(uint *)(param_1 + 0x210) = iVar22 + uVar9 * 8;
  uVar9 = uVar1 + 6;
  *(longlong **)(param_1 + 0x348) = plVar20;
  *(longlong **)(param_1 + 0x5c8) = plVar20;
  *(longlong **)(param_1 + 0x5d0) = plVar20;
  *(longlong **)(param_1 + 0x5d8) = plVar20;
  *(longlong **)(param_1 + 0x350) = plVar20 + ((ulonglong)uVar1 - 4);
  plVar5 = plVar20;
  if (uVar9 != 0) {
    do {
      lVar17 = (ulonglong)uVar16 * 0x20;
      *(ulonglong *)(lVar17 + *(longlong *)(param_1 + 0x350)) =
           (ulonglong)(uVar16 * uVar11) + *(longlong *)(param_1 + 0x310);
      *(undefined8 *)(*(longlong *)(param_1 + 0x350) + 8 + lVar17) = 0;
      *(short *)(*(longlong *)(param_1 + 0x350) + 0x10 + lVar17) = (short)uVar16;
      *(undefined4 *)(*(longlong *)(param_1 + 0x350) + 0x18 + lVar17) = 0;
      *(undefined1 *)(*(longlong *)(param_1 + 0x350) + 0x12 + lVar17) = 0;
      if (uVar16 <= uVar1) {
        *plVar5 = *(longlong *)(param_1 + 0x350) + lVar17;
        plVar5 = plVar5 + 1;
      }
      uVar16 = uVar16 + 1;
    } while (uVar16 <= uVar9);
  }
  plVar20 = plVar20 + (ulonglong)uVar1 + (ulonglong)uVar9 * 4;
  *(longlong **)(param_1 + 0x5e0) = plVar5;
  *(longlong **)(param_1 + 0xea0) = plVar20;
  *(longlong **)(param_1 + 0xea8) = plVar20 + 0x20;
  *(longlong **)(param_1 + 0xb4f8) = plVar20 + 0x60;
  if (*(char *)(param_1 + 0xe96) == '\0') {
    lVar17 = 0x50;
    plVar5 = plVar20 + 0x60;
    do {
      *plVar5 = 0;
      plVar5[1] = 0;
      plVar5[2] = 0;
      plVar5[3] = 0;
      plVar5[4] = 0;
      plVar5[5] = 0;
      plVar5[6] = 0;
      plVar5[7] = 0;
      lVar17 = lVar17 + -1;
      plVar5 = plVar5 + 8;
    } while (lVar17 != 0);
  }
  plVar5 = plVar20 + 0x2e0;
  if (*(char *)(param_1 + 0xb4a8) != '\0') {
    *(longlong **)(param_1 + 0xb4c0) = plVar5;
    plVar5 = plVar20 + 0x300;
  }
  uVar11 = 0;
  *(longlong **)(param_1 + 0xf20) = plVar5;
  puVar12 = (undefined8 *)((longlong)plVar5 + uVar7);
  *(undefined8 **)(param_1 + 0x378) = puVar12;
  puVar13 = (undefined8 *)((longlong)puVar12 + (ulonglong)(uint)(*(int *)(param_1 + 0x678) * 0x28));
  if (*(int *)(param_1 + 0x678) != 0) {
    do {
      ClearMapEntry(param_1,puVar12);
      uVar11 = uVar11 + 1;
      puVar12 = puVar12 + 5;
    } while (uVar11 < *(uint *)(param_1 + 0x678));
  }
  uVar11 = 0;
  *(undefined8 **)(param_1 + 0x358) = puVar13;
  puVar14 = (undefined2 *)
            ((longlong)puVar13 + (ulonglong)((uint)*(ushort *)(param_1 + 0x65a) * 0x24));
  if (*(ushort *)(param_1 + 0x65a) != 0) {
    do {
      ClearEnclosureEntry(puVar13);
      uVar11 = uVar11 + 1;
      puVar13 = (undefined8 *)((longlong)puVar13 + 0x24);
    } while (uVar11 < *(ushort *)(param_1 + 0x65a));
  }
  iVar22 = *(int *)(param_1 + 0x678);
  *(undefined2 **)(param_1 + 0x370) = puVar14;
  uVar7 = (ulonglong)(uint)(iVar22 * 8);
  puVar18 = (undefined1 *)((longlong)puVar14 + uVar7);
  if (iVar22 * 8 != 0) {
    for (; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined1 *)puVar14 = 0;
      puVar14 = (undefined2 *)((longlong)puVar14 + 1);
    }
    iVar22 = *(int *)(param_1 + 0x678);
    puVar14 = *(undefined2 **)(param_1 + 0x370);
  }
  uVar11 = 0;
  if (iVar22 != 0) {
    do {
      *puVar14 = 0xffff;
      puVar14 = puVar14 + 4;
      uVar11 = uVar11 + 1;
    } while (uVar11 < *(uint *)(param_1 + 0x678));
  }
  uVar11 = (uint)*(ushort *)(param_1 + 0x65c) * 0x3cc;
  *(undefined1 **)(param_1 + 0x360) = puVar18;
  uVar7 = (ulonglong)uVar11;
  puVar12 = (undefined8 *)(puVar18 + uVar7);
  if (uVar11 != 0) {
    for (; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar18 = 0;
      puVar18 = puVar18 + 1;
    }
  }
  *(undefined8 **)(param_1 + 0x368) = puVar12;
  lVar17 = 0x3d;
  puVar13 = puVar12 + 0x1ea;
  do {
    puVar21 = puVar12;
    *puVar21 = 0;
    puVar21[1] = 0;
    puVar21[2] = 0;
    puVar21[3] = 0;
    puVar21[4] = 0;
    puVar21[5] = 0;
    puVar21[6] = 0;
    puVar21[7] = 0;
    lVar17 = lVar17 + -1;
    puVar12 = puVar21 + 8;
  } while (lVar17 != 0);
  puVar21[8] = 0;
  puVar21[9] = 0;
  uVar11 = *(uint *)(param_1 + 0x3b0);
  if ((*(char *)(param_1 + 0xe96) == '\0') &&
     (*(undefined8 **)(param_1 + 0x388) = puVar13, uVar11 != 0)) {
    puVar12 = puVar13;
    for (uVar7 = (ulonglong)uVar11; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined1 *)puVar12 = 0;
      puVar12 = (undefined8 *)((longlong)puVar12 + 1);
    }
  }
  puVar18 = (undefined1 *)((longlong)puVar13 + (ulonglong)uVar11);
  lVar17 = 4;
  *(undefined1 **)(param_1 + 0x1578) = puVar18;
  uVar1 = *(ushort *)(param_1 + 0x1564);
  uVar11 = (uint)uVar1;
  if ((uVar1 & 3) != 0) {
    uVar11 = (uint)uVar1 + (4 - (uVar1 & 3));
  }
  uVar7 = (ulonglong)uVar11;
  puVar15 = puVar18 + uVar7;
  if (uVar11 != 0) {
    for (; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar18 = 0;
      puVar18 = puVar18 + 1;
    }
  }
  *(undefined1 **)(param_1 + 0x1580) = puVar15;
  uVar1 = *(ushort *)(param_1 + 0x1564);
  uVar11 = (uint)uVar1;
  if ((uVar1 & 3) != 0) {
    uVar11 = (uint)uVar1 + (4 - (uVar1 & 3));
  }
  uVar7 = (ulonglong)uVar11;
  puVar18 = puVar15 + uVar7;
  if (uVar11 != 0) {
    for (; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar15 = 0;
      puVar15 = puVar15 + 1;
    }
  }
  *(undefined1 **)(param_1 + 0x15c8) = puVar18;
  uVar11 = (uint)*(ushort *)(param_1 + 0x1564) * 0x14 + 8;
  uVar7 = (ulonglong)uVar11;
  puVar12 = (undefined8 *)(puVar18 + uVar7);
  if (uVar11 != 0) {
    for (; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar18 = 0;
      puVar18 = puVar18 + 1;
    }
  }
  *(undefined8 **)(param_1 + 0x15d0) = puVar12;
  puVar13 = (undefined8 *)(param_1 + 5000);
  *puVar12 = 0;
  puVar18 = (undefined1 *)((longlong)puVar12 + 0x1c);
  puVar12[1] = 0;
  puVar12[2] = 0;
  *(undefined4 *)(puVar12 + 3) = 0;
  uVar11 = 0;
  do {
    if ((*(char *)(puVar13 + 2) == '\0') || (*(uint *)(puVar13 + 1) == 0)) {
      *(undefined1 *)(puVar13 + 2) = 0;
    }
    else {
      *puVar13 = puVar18;
      puVar18 = puVar18 + *(uint *)(puVar13 + 1);
      *(char *)((longlong)puVar13 + 0xc) = (char)uVar11;
    }
    uVar11 = uVar11 + 1;
    puVar13 = puVar13 + 3;
  } while (uVar11 < 3);
  *(undefined4 *)(param_1 + 0x1630) = 0;
  *(undefined8 *)(param_1 + 0x1628) = 0;
  *(undefined1 **)(param_1 + 0x1620) = puVar18;
  *(undefined2 *)(param_1 + 0x1634) = 0;
  if (*(char *)(param_1 + 0xe96) == '\0') {
    *(ulonglong *)(param_1 + 0x1508) = ((ulonglong)(puVar18 + 0x34) & 0xfffffffffffffffc) + 4;
    *(undefined4 *)(param_1 + 0x1504) = 0x600;
  }
  lVar8 = 0xc;
  *(undefined2 *)(param_1 + 0xdac) = 0;
  lVar10 = 0xc;
  puVar12 = (undefined8 *)(param_1 + 0x76c);
  do {
    puVar13 = puVar12;
    *puVar13 = 0;
    puVar13[1] = 0;
    puVar13[2] = 0;
    puVar13[3] = 0;
    puVar13[4] = 0;
    puVar13[5] = 0;
    puVar13[6] = 0;
    puVar13[7] = 0;
    lVar10 = lVar10 + -1;
    puVar12 = puVar13 + 8;
  } while (lVar10 != 0);
  puVar13[8] = 0;
  lVar10 = 10;
  puVar13[9] = 0;
  puVar13[10] = 0;
  puVar13[0xb] = 0;
  puVar14 = (undefined2 *)(param_1 + 0xdb0);
  *(undefined2 *)(param_1 + 0xdae) = 0;
  do {
    *puVar14 = 0;
    puVar14 = puVar14 + 4;
    lVar10 = lVar10 + -1;
  } while (lVar10 != 0);
  *(undefined2 *)(param_1 + 0xf5d) = 0;
  puVar12 = (undefined8 *)(param_1 + 0xf68);
  do {
    *puVar12 = 0;
    puVar12[1] = 0;
    puVar12[2] = 0;
    puVar12[3] = 0;
    puVar12[4] = 0;
    puVar12[5] = 0;
    puVar12[6] = 0;
    puVar12[7] = 0;
    lVar17 = lVar17 + -1;
    puVar12 = puVar12 + 8;
  } while (lVar17 != 0);
  *(undefined2 *)(param_1 + 0xf5f) = 0;
  puVar12 = (undefined8 *)(param_1 + 0x1068);
  do {
    puVar13 = puVar12;
    *puVar13 = 0;
    puVar13[1] = 0;
    puVar13[2] = 0;
    puVar13[3] = 0;
    puVar13[4] = 0;
    puVar13[5] = 0;
    puVar13[6] = 0;
    puVar13[7] = 0;
    lVar8 = lVar8 + -1;
    puVar12 = puVar13 + 8;
  } while (lVar8 != 0);
  puVar13[8] = 0;
  puVar13[9] = 0;
  puVar13[10] = 0;
  puVar13[0xb] = 0;
  return;
}



===== LunResetTurTimeout @ 1400103d0 =====

ulonglong LunResetTurTimeout(longlong param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  ulonglong uVar1;
  
  if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x2001c) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x2001c,
                (undefined1 *)(*(longlong *)(*(longlong *)(param_1 + 0x5e8) + 0x68) + 0x5a),3,
                param_4);
  }
  *(undefined4 *)
   ((ulonglong)*(ushort *)(param_1 + 0x66e) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x350)) = 0;
  uVar1 = IssueLunReset(param_1,param_4);
  return uVar1 & 0xffffffffffffff00;
}



===== NonSCB_Func_handler @ 140010460 =====

void NonSCB_Func_handler(longlong param_1,short *param_2,short param_3,int param_4)

{
  longlong lVar1;
  undefined8 *puVar2;
  char cVar3;
  ushort uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  longlong lVar7;
  byte bVar8;
  char cVar9;
  byte *pbVar10;
  uint uVar11;
  
  pbVar10 = (byte *)((longlong)param_2 + 3);
  switch(*pbVar10) {
  case 1:
    uVar11 = 0;
    *(undefined4 *)(param_1 + 0x634) = 0;
    cVar3 = *(char *)((longlong)param_2 + 5);
    if (((*(char *)(param_1 + 0x15a0) != '\0') && (param_3 == *(short *)(param_1 + 0x66a))) &&
       ((cVar3 == '\x02' || (cVar3 == '\a')))) {
      *(short **)(param_1 + 0x600) = param_2;
      SasBcAsyncEvent(param_1,param_4);
      break;
    }
    if (((*(uint *)(param_1 + 0x1630) & 1) != 0) && (*(short *)(param_1 + 0x1634) == param_3)) {
      lVar7 = *(longlong *)(param_1 + 0x1628);
      lVar1 = *(longlong *)(lVar7 + 0x68);
      *(undefined4 *)(param_1 + 0x1630) = 0;
      *(undefined2 *)(param_1 + 0x1634) = 0;
      *(undefined8 *)(param_1 + 0x1628) = 0;
      *(undefined1 *)(param_1 + 0x161c) = 0;
      *(undefined1 *)(*(longlong *)(lVar1 + 0x40) + 8) = 0;
      lVar1 = *(longlong *)(lVar7 + 0x40);
      *(undefined1 *)(lVar7 + 3) = 1;
      *(undefined1 *)(lVar1 + 0x3c) = 0;
      if (param_2[7] == 0) {
        *(undefined4 *)(lVar1 + 0x14) = 0;
        *(undefined1 *)(lVar1 + 0x39) = 2;
        if (cVar3 == '\a') {
          *(undefined1 *)(lVar1 + 0x3c) = 1;
          *(undefined1 *)(lVar1 + 0x3e) = 1;
          *(char *)(lVar1 + 0x40) = (char)param_2[2];
        }
      }
      else if (param_2[7] == 6) {
        *(undefined4 *)(lVar1 + 0x14) = 0;
        *(undefined1 *)(lVar1 + 0x39) = 4;
      }
      else {
        *(undefined4 *)(lVar1 + 0x14) = 1;
        *(undefined1 *)(lVar1 + 0x39) = 3;
      }
      StorPortNotification(0);
      *(undefined1 *)(param_1 + 0xec8) = 0;
    }
    if (((*(char *)(param_1 + 0xe81) != '\0') && (cVar3 == '\x03')) &&
       (param_3 == *(short *)(param_1 + 0x670))) {
      RemoveDevice(param_1,param_4);
      break;
    }
    if (((*(char *)(param_1 + 0xeb1) != '\0') && (cVar3 == '\x01')) &&
       (param_3 == *(short *)(param_1 + 0x672))) {
      *(undefined1 *)(param_1 + 0xeb1) = 0;
      uVar6 = ReadIDs(param_1,param_4);
      if ((char)uVar6 == '\0') {
        *(undefined1 *)(param_1 + 0xe86) = 0;
        RemoveDevice(param_1,param_4);
      }
      break;
    }
    if (((*(char *)(param_1 + 0xb4a9) != '\0') && (cVar3 == '\x01')) &&
       (param_3 == *(short *)(param_1 + 0x672))) {
      *(short *)(param_1 + 0xb4b0) = *(short *)(param_1 + 0xb4b0) + 1;
      *(undefined1 *)(param_1 + 0xb4a9) = 0;
      *(undefined4 *)(param_1 + 0xb4ac) = 1;
      DetectSataPfa(param_1,0,0,param_4);
      break;
    }
    if (*(char *)(param_1 + 0xeb8) == '\0') {
      if (cVar3 != '\x05') {
        if (cVar3 != '\x03') goto LAB_1400107a1;
        if ((*(char *)(param_1 + 0xec8) != '\0') && (*(int *)(param_1 + 0xf34) == -0x21524111)) {
          puVar2 = *(undefined8 **)(param_1 + 0x608);
          *puVar2 = 0;
          puVar2[1] = 0;
          puVar2[2] = 0;
          puVar2[3] = 0;
          puVar2[4] = 0;
          *(undefined4 *)(puVar2 + 5) = 0;
          *(undefined1 *)((longlong)puVar2 + 3) = 7;
          *(undefined8 *)((longlong)puVar2 + 0x14) = 0xffffffffffffffff;
          *(undefined8 *)((longlong)puVar2 + 0x1c) = 0xffffffffffffffff;
          *(undefined1 *)(param_1 + 0xe69) = 1;
          **(int **)(param_1 + 0xe8) = (uint)*(ushort *)(param_1 + 0x66a) * 0x10000 + 8;
          LOCK();
          UNLOCK();
          **(undefined4 **)(param_1 + 0xf0) = 0;
          LOCK();
          UNLOCK();
          *(undefined1 *)(param_1 + 0xeb9) = 1;
          StorPortNotification(6,param_1,DelayedIoctlTimeout,3000000);
          break;
        }
      }
      if ((*(longlong *)(param_1 + 0x5e8) != 0) &&
         (cVar3 = ProcessTmResetReply(param_1,param_2,param_4), cVar3 != '\0')) break;
    }
    else {
      if (*(short *)(param_1 + 0x620) != 0) {
        LogSystemEvent(param_1,0xad010017,0xc004af02,
                       (byte *)"TM reply received (NonSCB_Func_handler)",param_4);
      }
      uVar6 = ProcessBusReset(param_1,param_4);
      if ((char)uVar6 != '\0') break;
      if (*(int *)(param_1 + 0xec0) != 0) {
        *(undefined1 *)(param_1 + 0xeb9) = 0;
        StorPortNotification(6,param_1,WatchdogTimer,100000);
        return;
      }
    }
LAB_1400107a1:
    ResetActive(param_1,0x40000002,param_4);
    StorPortResume(param_1);
    do {
      uVar4 = 1 << ((byte)uVar11 & 0x1f);
      if ((uVar4 & *(ushort *)(param_1 + 0x624)) != 0) {
        *(ushort *)(param_1 + 0x624) = ~uVar4 & *(ushort *)(param_1 + 0x624);
        LSImpiReset(param_1,uVar11,param_4);
        break;
      }
      uVar11 = uVar11 + 1;
    } while (uVar11 < 8);
    break;
  default:
    if (*(short *)(param_1 + 0x620) != 0) {
      LogSystemEvent(param_1,(uint)*pbVar10,0xc004af02,
                     (byte *)"Received Invalid Function ID in MPI Reply",param_4);
    }
    if ((*(char *)(param_1 + 0x3b8) == '\0') || ((*(uint *)(param_1 + 0x3bc) & 0x202) == 0)) break;
    uVar5 = 0x202;
    uVar11 = 1;
    goto LAB_140010d16;
  case 4:
    *(ushort *)(param_1 + 0x1502) = param_2[7] & 0x7fff;
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x801) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x801,
                  (undefined1 *)param_2,0x18,param_4);
    }
    if (param_3 == *(short *)(param_1 + 0x670)) {
      if (*(char *)(param_1 + 0xe88) != '\0') {
        *(undefined1 *)(param_1 + 0xe88) = 0;
      }
      if (*(char *)(param_1 + 0xe86) != '\0') {
        ContinueIDReadsForPhyEvents(param_1,param_4);
        break;
      }
      if (*(char *)(param_1 + 0xe8a) == '\0') goto LAB_140010a52;
      *(undefined1 *)(param_1 + 0xe8a) = 0;
      if (*(char *)((ulonglong)*(uint *)(param_1 + 0x158c) * 0x3cc + 0x3c4 +
                   *(longlong *)(param_1 + 0x360)) != '\0') {
        UpdateMissingCount(param_1,param_4);
        StartIDReadsForPhyEvents(param_1,param_4);
        break;
      }
      *(undefined1 *)(param_1 + 0xe84) = 0;
      if (*(char *)((ulonglong)*(uint *)(param_1 + 0x1594) * 0x188 + 0x184 +
                   *(longlong *)(param_1 + 0x368)) != '\0') {
        *(undefined1 *)(param_1 + 0xe85) = 1;
        StartIDReadsForIrElements(param_1,param_4);
        goto LAB_140010a52;
      }
      cVar3 = '\0';
      if (*(longlong *)(param_1 + 0x5e8) == 0) {
        if (*(int *)(param_1 + 0xec0) == 0) {
          uVar6 = CheckResetQueue(param_1,param_4);
          cVar3 = (char)uVar6;
          goto LAB_14001094b;
        }
      }
      else {
LAB_14001094b:
        if (((*(int *)(param_1 + 0xec0) == 0) && (cVar3 == '\0')) &&
           (*(longlong *)(param_1 + 0x5e8) == 0)) {
          StorPortResume(param_1);
          ResetActive(param_1,0x40000003,param_4);
        }
      }
      if (*(char *)(param_1 + 0x380) != '\0') {
        *(undefined1 *)(param_1 + 0x380) = 0;
        *(undefined1 *)(param_1 + 0xe44) = 1;
        if ((*(int *)(param_1 + 0xec0) == 0) && (bVar8 = 0, *(short *)(param_1 + 0x660) != 0)) {
          do {
            if ((*(char *)(param_1 + 0x3b8) != '\0') &&
               ((*(uint *)(param_1 + 0x3bc) & 0x100004) != 0)) {
              RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x100004,
                          (undefined1 *)0x0,0,param_4);
            }
            StorPortNotification(7,param_1,bVar8);
            bVar8 = bVar8 + 1;
          } while ((ushort)bVar8 < *(ushort *)(param_1 + 0x660));
        }
      }
    }
    else if (param_3 == *(short *)(param_1 + 0x672)) {
      if (*(char *)(param_1 + 0xe87) != '\0') {
        ContinueIDReadsForIrElements(param_1,param_4);
        break;
      }
    }
    else if (*(char *)(param_1 + 0xe82) != '\0') {
      *(undefined1 *)(param_1 + 0xe82) = 0;
      FlushDPMPage0Entry(param_1,param_4);
    }
LAB_140010a52:
    uVar5 = *(undefined4 *)(param_2 + 10);
    if ((((byte)((uint)uVar5 >> 0x18) & 0xf) == 0xf) && ((char)*param_2 == '\0')) {
      cVar3 = (char)param_2[3];
      cVar9 = (char)((uint)uVar5 >> 0x10);
      if (cVar3 == '\x10') {
        if (cVar9 == '\0') {
          lVar7 = 0x163c;
        }
        else {
          lVar7 = 0x1514;
          if (cVar9 == '\x01') {
            lVar7 = 0x1644;
          }
        }
      }
      else if (cVar3 == '\x12') {
        if (cVar9 == '\0') {
          lVar7 = 0x15d8;
        }
        else {
          lVar7 = 0x1514;
          if (cVar9 == '\x01') {
            lVar7 = 0x164c;
          }
        }
      }
      else if (cVar3 == '\x13') {
        if (cVar9 == '\0') {
          lVar7 = 0x1654;
        }
        else {
          lVar7 = 0x1514;
          if (cVar9 == '\x01') {
            lVar7 = 0x165c;
          }
        }
      }
      else if (cVar3 == '\x15') {
        lVar7 = 0x15e8;
      }
      else {
        lVar7 = 0x1514;
        if (cVar3 == '\x17') {
          lVar7 = 0x15c0;
        }
      }
      *(char *)(lVar7 + param_1) = (char)uVar5;
      *(char *)(lVar7 + 2 + param_1) = (char)param_2[0xb];
      *(undefined1 *)(lVar7 + 3 + param_1) = *(undefined1 *)((longlong)param_2 + 0x17);
      *(short *)(lVar7 + 4 + param_1) = param_2[2];
      *(char *)(lVar7 + 6 + param_1) = (char)param_2[3];
    }
    else {
      *(undefined4 *)(param_1 + 0x1510) = uVar5;
    }
    if (*(char *)(param_1 + 0xec5) == '\0') {
      RsIoctl_sm(param_1,0,(longlong)param_2,param_4);
    }
    else if ((char)*param_2 == '\0') {
      *(undefined4 *)(param_1 + 0x1510) = uVar5;
    }
    if (((char)param_2[3] == '\x17') && (*(char *)(param_1 + 0xb328) != '\0')) {
      HandleFWDowngrade(param_1,'\0',param_4);
    }
    break;
  case 6:
    uVar4 = param_2[7];
    *(undefined1 *)(param_1 + 0xe80) = 0;
    *(ushort *)(param_1 + 0x626) = uVar4 & 0x7fff;
    break;
  case 8:
    break;
  case 0x15:
    if ((char)*param_2 == ' ') {
      *(undefined1 *)(param_1 + 0xe6a) = 0;
      if ((*(longlong *)(param_1 + 0x5e8) != 0) &&
         ((*(int *)(*(longlong *)(param_1 + 0x5e8) + 0x14) != 7 || (*(int *)(param_1 + 0x630) == 0))
         )) {
        uVar5 = 0xd;
        if (*(short *)(param_1 + 0xb320) != 0) {
          uVar5 = 8;
        }
        *(undefined4 *)(param_1 + 0xec0) = uVar5;
      }
    }
    else if (((char)*param_2 == '$') && (uVar6 = ReadIrIDs(param_1,param_4), (char)uVar6 == '\0')) {
      *(undefined1 *)(param_1 + 0xe87) = 0;
      AddOrRemoveIrVolume(param_1,param_4);
    }
    break;
  case 0x18:
    pbVar10 = (byte *)(param_2 + 7);
    if (((*(short *)pbVar10 == 0) || (*(char *)(param_1 + 0x3b8) == '\0')) ||
       ((*(uint *)(param_1 + 0x3bc) & 0x201) == 0)) break;
    uVar5 = 0x201;
    uVar11 = 2;
LAB_140010d16:
    RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),uVar5,pbVar10,uVar11,
                param_4);
    break;
  case 0x1b:
    if ((*(char *)(param_1 + 0xe81) != '\0') && (param_3 == *(short *)(param_1 + 0x670))) {
      *(undefined1 *)(param_1 + 0xe81) = 0;
      RemoveDevice(param_1,param_4);
    }
    if ((*(char *)(param_1 + 0xb4f1) != '\0') && (param_3 == *(short *)(param_1 + 0x670))) {
      *(undefined1 *)(param_1 + 0xb4f1) = 0;
    }
    break;
  case 0x1c:
    if ((param_3 == *(short *)(param_1 + 0x670)) && (*(char *)(param_1 + 0xeb1) == '\0')) {
      ContinueHashedSASAddress(param_1,(longlong)param_2,param_4);
    }
  }
  if (*(char *)(param_1 + 0xec8) == '\0') {
    CheckIoctlQueue(param_1,param_4);
  }
  return;
}



===== PauseDevice @ 140010da0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PauseDevice(longlong param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                undefined2 param_5,undefined2 param_6,undefined4 param_7,undefined4 param_8,
                int param_9)

{
  longlong lVar1;
  undefined1 auStackY_88 [32];
  undefined4 local_48;
  undefined4 local_44;
  undefined2 local_40;
  undefined2 local_3e;
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = param_7;
  local_44 = param_8;
  local_3e = param_5;
  local_40 = param_6;
  local_3c = param_2;
  local_3b = param_3;
  local_3a = param_4;
  lVar1 = StorPortGetLogicalUnit();
  if (lVar1 == 0) {
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x232) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x232,
                  (undefined1 *)&local_48,0x10,param_9);
    }
  }
  else {
    *(char *)(lVar1 + 0x30) = *(char *)(lVar1 + 0x30) + '\x01';
    local_39 = *(undefined1 *)(lVar1 + 0x30);
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x111) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x111,
                  (undefined1 *)&local_48,0x10,param_9);
    }
    StorPortPauseDevice(param_1,param_2,param_3,param_4);
  }
  return;
}



===== PerformFwDiagOperation @ 140010f00 =====

ulonglong PerformFwDiagOperation(longlong param_1,longlong param_2,undefined1 *param_3,int param_4)

{
  longlong lVar1;
  int *piVar2;
  longlong lVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  byte bVar10;
  ulonglong uVar11;
  ushort uVar12;
  ushort uVar13;
  bool bVar14;
  
  *param_3 = 1;
  *(undefined4 *)(param_2 + 0x14) = 0;
  memmove((void *)(param_2 + 0x20),&FwDiagPageVersion,4);
  iVar5 = *(int *)(param_2 + 0x1c);
  if (iVar5 == 1) {
    uVar9 = 0;
    if (0x73 < *(uint *)(param_2 + 0x18)) {
      uVar9 = 0;
      if (*(byte *)(param_2 + 0x25) < 3) {
        piVar2 = (int *)(param_1 + ((ulonglong)*(byte *)(param_2 + 0x25) * 3 + 0x271) * 8);
        uVar11 = 0;
        do {
          uVar9 = uVar11;
          if (*(int *)(param_1 + 0x139c + uVar9 * 0x18) == *(int *)(param_2 + 0x8c)) {
            if ((char)uVar9 != -1) goto LAB_140010fc8;
            break;
          }
          bVar10 = (char)uVar9 + 1;
          uVar11 = (ulonglong)bVar10;
        } while (bVar10 < 3);
        if ((piVar2[5] == 0) && (*(int *)(param_2 + 0x8c) != 0)) {
          if ((*(char *)((longlong)piVar2 + 0xf) != '\0') &&
             (*(char *)((longlong)piVar2 + 0x12) != '\0')) {
            *(undefined1 *)((longlong)piVar2 + 0xf) = 0;
            iVar5 = *(int *)(param_2 + 0x8c);
            piVar2[5] = iVar5;
            return CONCAT71((uint7)(uint3)((uint)iVar5 >> 8),1);
          }
          if ((char)piVar2[4] == '\0') {
            *(undefined4 *)(param_2 + 0x14) = 0x13;
          }
          else {
            *(undefined1 *)((longlong)piVar2 + 0xf) = 0;
            if (*(char *)(param_2 + 0x25) == '\0') {
              memmove((void *)(param_1 + 0x13d0),(void *)(param_2 + 0x2c),0x28);
            }
            *(undefined1 *)((longlong)piVar2 + 0xd) = *(undefined1 *)(param_2 + 0x24);
            piVar2[5] = *(int *)(param_2 + 0x8c);
            uVar9 = PostFwDiagBuffer(param_1,piVar2,0,param_4);
            if ((char)uVar9 != '\0') goto LAB_140011339;
            *(undefined4 *)(param_2 + 0x14) = 0x10;
          }
          goto LAB_140010f7a;
        }
        goto LAB_140010fc8;
      }
    }
  }
  else if (iVar5 == 2) {
LAB_140011160:
    uVar7 = *(uint *)(param_2 + 0x18);
    uVar9 = (ulonglong)uVar7;
    if (iVar5 == 2) {
      if (0xb < uVar7) {
        uVar11 = 0;
        do {
          uVar9 = uVar11;
          bVar10 = (byte)uVar9;
          if (*(int *)(param_1 + 0x139c + uVar9 * 0x18) == *(int *)(param_2 + 0x24))
          goto LAB_1400111e4;
          uVar11 = (ulonglong)(byte)(bVar10 + 1);
        } while ((byte)(bVar10 + 1) < 3);
        *(undefined4 *)(param_2 + 0x14) = 0x11;
        goto LAB_140010f7a;
      }
    }
    else if (0xb < uVar7) {
      uVar11 = 0;
      do {
        uVar9 = uVar11;
        bVar10 = (byte)uVar9;
        if (*(int *)(param_1 + 0x139c + uVar9 * 0x18) == *(int *)(param_2 + 0x24))
        goto LAB_1400111e4;
        uVar11 = (ulonglong)(byte)(bVar10 + 1);
      } while ((byte)(bVar10 + 1) < 3);
      *(undefined4 *)(param_2 + 0x14) = 0x11;
      goto LAB_140010f7a;
    }
  }
  else if (iVar5 == 3) {
    uVar9 = 0;
    if (0x77 < *(uint *)(param_2 + 0x18)) {
      if (*(int *)(param_2 + 0x90) == 0) {
        bVar10 = *(byte *)(param_2 + 0x25);
        if (bVar10 < 3) {
LAB_1400110bd:
          lVar1 = param_1 + (ulonglong)bVar10 * 0x18;
          cVar4 = *(char *)(lVar1 + 0x1394);
          *(char *)(param_2 + 0x25) = cVar4;
          *(undefined1 *)(param_2 + 0x24) = *(undefined1 *)(lVar1 + 0x1395);
          if (cVar4 == '\0') {
            memmove((void *)(param_2 + 0x2c),(void *)(param_1 + 0x13d0),0x28);
          }
          uVar6 = *(undefined4 *)(lVar1 + 0x1390);
          *(undefined4 *)(param_2 + 0x8c) = 0;
          *(undefined4 *)(param_2 + 0x88) = uVar6;
          uVar6 = *(undefined4 *)(lVar1 + 0x139c);
          *(undefined2 *)(param_2 + 0x26) = 0;
          *(undefined4 *)(param_2 + 0x90) = uVar6;
          bVar14 = *(char *)(lVar1 + 0x1397) == '\0';
          uVar13 = (ushort)bVar14;
          uVar12 = (ushort)bVar14;
          *(ushort *)(param_2 + 0x26) = uVar12;
          if ((*(char *)(lVar1 + 0x1399) != '\0') || (*(char *)(lVar1 + 0x139a) != '\0')) {
            uVar13 = uVar12 | 2;
          }
          *(ushort *)(param_2 + 0x26) = uVar13;
          uVar12 = uVar13 | 4;
          if (*(char *)(lVar1 + 0x139a) == '\0') {
            uVar12 = uVar13;
          }
          *(ushort *)(param_2 + 0x26) = uVar12;
          return 1;
        }
        *(undefined4 *)(param_2 + 0x14) = 0;
      }
      else {
        bVar10 = 0;
        do {
          uVar9 = (ulonglong)bVar10;
          if (*(int *)(param_1 + 0x139c + uVar9 * 0x18) == *(int *)(param_2 + 0x90)) {
            if (bVar10 != 0xff) goto LAB_1400110bd;
            goto LAB_140010fc8;
          }
          bVar10 = bVar10 + 1;
        } while (bVar10 < 3);
        *(undefined4 *)(param_2 + 0x14) = 0x11;
      }
      goto LAB_140010f7a;
    }
  }
  else if (iVar5 == 4) {
    uVar7 = *(uint *)(param_2 + 0x2c);
    uVar9 = (ulonglong)uVar7 + 0xc;
    if (uVar9 <= *(uint *)(param_2 + 0x18)) {
      bVar10 = 0;
      do {
        uVar11 = (ulonglong)bVar10;
        uVar9 = uVar11 * 3;
        if (*(int *)(param_1 + 0x139c + uVar11 * 0x18) == *(int *)(param_2 + 0x30)) {
          if (bVar10 != 0xff) {
            lVar1 = param_1 + uVar11 * 0x18;
            uVar8 = *(uint *)(param_2 + 0x28) + uVar7;
            uVar9 = (ulonglong)uVar8;
            if (*(uint *)(lVar1 + 0x1390) < uVar8) goto LAB_140010f73;
            memmove((void *)(param_2 + 0x34),
                    (void *)((ulonglong)*(uint *)(param_2 + 0x28) + *(longlong *)(lVar1 + 5000)),
                    (ulonglong)uVar7);
            uVar9 = 0;
            uVar12 = *(ushort *)(param_2 + 0x26) | 2;
            if (*(char *)(lVar1 + 0x1396) == '\0') {
              uVar12 = *(ushort *)(param_2 + 0x26) & 0xfffd;
            }
            *(ushort *)(param_2 + 0x26) = uVar12;
            if (((*(char *)(lVar1 + 0x139a) != '\0') || ((uVar12 & 1) == 0)) ||
               (uVar9 = PostFwDiagBuffer(param_1,(int *)(lVar1 + 5000),0,param_4),
               (char)uVar9 != '\0')) goto LAB_14001133d;
            *(undefined4 *)(param_2 + 0x14) = 0x10;
            goto LAB_140010f7a;
          }
          break;
        }
        bVar10 = bVar10 + 1;
      } while (bVar10 < 3);
      goto LAB_140010fc8;
    }
  }
  else {
    uVar9 = (ulonglong)(iVar5 - 5U);
    if (iVar5 - 5U == 0) goto LAB_140011160;
  }
LAB_140010f73:
  *(undefined4 *)(param_2 + 0x14) = 3;
  goto LAB_140010f7a;
LAB_1400111e4:
  uVar9 = 0;
  if (bVar10 != 0xff) {
    uVar9 = (ulonglong)bVar10;
    lVar3 = uVar9 * 3 + 0x271;
    lVar1 = param_1 + lVar3 * 8;
    if (*(char *)(param_1 + 0x12 + lVar3 * 8) == '\0') {
      if (iVar5 == 2) {
        *(undefined4 *)(lVar1 + 0x14) = 0;
        *(undefined4 *)(param_2 + 0x14) = 0;
        return 1;
      }
      *(undefined4 *)(param_2 + 0x14) = 0x14;
    }
    else {
      uVar9 = ReleaseFwDiagBuffer(param_1,lVar1,param_4);
      if ((char)uVar9 != '\0') {
LAB_140011339:
        *param_3 = 0;
LAB_14001133d:
        return CONCAT71((int7)(uVar9 >> 8),1);
      }
      *(undefined4 *)(param_2 + 0x14) = 0x12;
    }
    goto LAB_140010f7a;
  }
LAB_140010fc8:
  *(undefined4 *)(param_2 + 0x14) = 0x11;
LAB_140010f7a:
  return uVar9 & 0xffffffffffffff00;
}



===== PostFwDiagBuffer @ 140011350 =====

ulonglong PostFwDiagBuffer(longlong param_1,int *param_2,undefined8 param_3,int param_4)

{
  undefined1 *puVar1;
  ulonglong in_RAX;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined1 *puVar4;
  
  if ((char)param_2[4] == '\0') {
    return in_RAX & 0xffffffffffffff00;
  }
  puVar1 = *(undefined1 **)(param_1 + 0x608);
  *(undefined1 *)((longlong)param_2 + 0xe) = 0;
  if (*(ushort *)(param_1 + 0x2ea) != 0) {
    puVar4 = puVar1;
    for (uVar3 = (ulonglong)*(ushort *)(param_1 + 0x2ea); uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
  }
  puVar1[1] = (char)param_2[3];
  puVar1[3] = 0x1d;
  *puVar1 = *(undefined1 *)((longlong)param_2 + 0xd);
  *(int *)(puVar1 + 0x14) = param_2[2];
  memmove(puVar1 + 0x24,(void *)(param_1 + 0x13d0),0x28);
  *(undefined4 *)(puVar1 + 0x10) = *(undefined4 *)(param_1 + 0x1ec);
  *(int *)(puVar1 + 0xc) = *param_2 - *(int *)(param_1 + 0x100);
  uVar2 = QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x66a) * 0x10000 + 8,0,param_4)
  ;
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== ProcessBusReset @ 140011430 =====

ulonglong ProcessBusReset(longlong param_1,int param_2)

{
  char cVar1;
  ushort uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  ulonglong in_RAX;
  ulonglong uVar5;
  undefined8 uVar6;
  ushort uVar7;
  
  uVar2 = *(ushort *)(param_1 + 0x654);
  cVar1 = *(char *)(param_1 + 0xe78);
  uVar7 = *(ushort *)(param_1 + 0x76a);
  if (uVar7 <= uVar2) {
    do {
      uVar5 = (ulonglong)uVar7;
      uVar7 = uVar7 + 1;
      in_RAX = uVar5 * 0x20 + *(longlong *)(param_1 + 0x350);
      if (((*(longlong *)(in_RAX + 8) != 0) && (*(int *)(in_RAX + 0x18) == 0)) &&
         (*(char *)(in_RAX + 0x12) == cVar1)) {
        *(ushort *)(param_1 + 0x76a) = uVar7;
        puVar3 = *(undefined8 **)(param_1 + 800);
        *puVar3 = 0;
        puVar3[1] = 0;
        puVar3[2] = 0;
        puVar3[3] = 0;
        puVar3[4] = 0;
        puVar3[5] = 0;
        *(undefined4 *)(puVar3 + 6) = 0;
        *(undefined2 *)puVar3 = *(undefined2 *)(in_RAX + 0x14);
        *(undefined1 *)((longlong)puVar3 + 3) = 1;
        *(undefined1 *)((longlong)puVar3 + 5) = 3;
        uVar6 = QueueRequestDescriptor
                          (param_1,(uint)*(ushort *)(param_1 + 0x66e) * 0x10000 + 6,0,param_2);
        if (*(char *)(param_1 + 0xb351) == '\0') {
          uVar6 = AfdMasterTrigger(param_1,4,param_2);
          *(undefined1 *)(param_1 + 0xb351) = 1;
        }
        *(undefined4 *)(param_1 + 0x634) = 0xf;
        return CONCAT71((int7)((ulonglong)uVar6 >> 8),1);
      }
    } while (uVar7 <= uVar2);
  }
  if (*(char *)(param_1 + 0xeb8) != '\0') {
    if (*(short *)(param_1 + 0x620) != 0) {
      in_RAX = LogSystemEvent(param_1,0xad010017,0xc004af02,
                              (byte *)"TM reply received (ProcessBusReset)",param_2);
    }
    if ((*(char *)(param_1 + 0x12a) != '\0') && (uVar7 = 1, 1 < *(byte *)(param_1 + 299))) {
      do {
        LSImpiMSIIsr(param_1,(byte)uVar7);
        in_RAX = 0;
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(byte *)(param_1 + 299));
    }
    uVar7 = 1;
    if (uVar2 != 0) {
      do {
        in_RAX = (ulonglong)uVar7 * 0x20 + *(longlong *)(param_1 + 0x350);
        if (((*(longlong *)(in_RAX + 8) != 0) && (*(char *)(in_RAX + 0x12) == cVar1)) &&
           (*(int *)(in_RAX + 0x18) == 0)) {
          LogSystemEvent(param_1,0xad010035,0xc004af02,
                         (byte *)
                         "IOs still active on bus when TM reply was received(ProcessBusReset)",
                         param_2);
          **(uint **)(param_1 + 0x50) = **(uint **)(param_1 + 0x50) | 0x40000009;
          LOCK();
          UNLOCK();
          if (*(int *)(param_1 + 0x630) == 0) {
            StorPortPause(param_1,400);
          }
          *(undefined4 *)(param_1 + 0xec0) = 1;
          in_RAX = KickStart(param_1,param_2);
          break;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 <= uVar2);
    }
    *(undefined1 *)(param_1 + 0xeb8) = 0;
    *(undefined1 *)(param_1 + 0xb351) = 0;
  }
  lVar4 = *(longlong *)(param_1 + 0x5f0);
  if ((lVar4 != 0) &&
     (in_RAX = 0, *(char *)(*(longlong *)(lVar4 + 0x68) + 0x5a) == *(char *)(param_1 + 0xe78))) {
    *(undefined8 *)(param_1 + 0x5f0) = 0;
    *(undefined1 *)(lVar4 + 3) = 1;
    in_RAX = StorPortNotification(0,param_1);
  }
  return in_RAX & 0xffffffffffffff00;
}



===== ProcessParseArgumentString @ 1400116b0 =====

ulonglong ProcessParseArgumentString(byte *param_1,byte *param_2,int *param_3)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  
  pbVar9 = (byte *)0x0;
  uVar7 = 0;
  uVar8 = 0;
  bVar1 = *param_1;
  pbVar3 = param_1;
  while (bVar1 != 0) {
    pbVar3 = pbVar3 + 1;
    uVar7 = uVar7 + 1;
    bVar1 = *pbVar3;
  }
  bVar1 = *param_2;
  pbVar3 = param_2;
  if (bVar1 != 0) {
    do {
      pbVar3 = pbVar3 + 1;
      uVar8 = uVar8 + 1;
    } while (*pbVar3 != 0);
    if (uVar7 < uVar8) {
LAB_140011896:
      return (ulonglong)pbVar3 & 0xffffffffffffff00;
    }
  }
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          bVar2 = *param_1;
          pbVar3 = (byte *)0x0;
          if ((bVar2 != 0x20) && (bVar2 != 9)) break;
          param_1 = param_1 + 1;
        }
        if (bVar2 == 0) goto LAB_140011896;
        bVar5 = bVar1;
        if (bVar2 == bVar1) {
          pbVar3 = param_2 + -(longlong)param_1;
          pbVar4 = param_1;
          do {
            param_1 = pbVar4 + 1;
            if (*pbVar4 == 0) goto LAB_140011896;
            bVar5 = pbVar3[(longlong)param_1];
            pbVar4 = param_1;
          } while (*param_1 == bVar5);
        }
        if (bVar5 == 0) break;
        do {
          bVar2 = *param_1;
          pbVar3 = (byte *)0x0;
          if (bVar2 == 0) goto LAB_140011896;
          param_1 = param_1 + 1;
        } while (bVar2 != 0x3b);
      }
      for (; (bVar2 = *param_1, bVar2 == 0x20 || (bVar2 == 9)); param_1 = param_1 + 1) {
      }
      if (bVar2 == 0x3d) break;
      do {
        bVar2 = *param_1;
        pbVar3 = (byte *)0x0;
        if (bVar2 == 0) goto LAB_140011896;
        param_1 = param_1 + 1;
      } while (bVar2 != 0x3b);
    }
    do {
      do {
        pbVar4 = param_1;
        bVar2 = pbVar4[1];
        pbVar3 = (byte *)0x0;
        param_1 = pbVar4 + 1;
      } while (bVar2 == 0x20);
    } while (bVar2 == 9);
    if (bVar2 == 0) goto LAB_140011896;
    if (bVar2 != 0x3b) break;
    param_1 = pbVar4 + 2;
  }
  *param_3 = 0;
  bVar1 = *param_1;
  if ((bVar1 == 0x30) && (pbVar4[2] == 0x78)) {
    bVar1 = pbVar4[3];
    if (bVar1 != 0) {
      iVar6 = 0;
      while ((0x3b < bVar1 ||
             (pbVar3 = (byte *)(longlong)(char)bVar1,
             (0x800000100000200U >> ((ulonglong)(longlong)(char)bVar1 & 0x3f) & 1) == 0))) {
        if ((byte)(bVar1 - 0x30) < 10) {
          iVar6 = iVar6 * 0x10 + -0x30;
        }
        else {
          pbVar3 = (byte *)(ulonglong)(bVar1 - 0x61);
          if (5 < (byte)(bVar1 - 0x61)) goto LAB_140011896;
          iVar6 = iVar6 * 0x10 + -0x57;
        }
        uVar7 = (int)pbVar9 + 1;
        pbVar9 = (byte *)(ulonglong)uVar7;
        iVar6 = iVar6 + (char)bVar1;
        *param_3 = iVar6;
        bVar1 = (pbVar9 + 2)[(longlong)param_1];
        if (bVar1 == 0) {
          return CONCAT71((uint7)(uint3)(uVar7 >> 8),1);
        }
      }
    }
  }
  else {
    while ((pbVar3 = pbVar9, bVar1 != 0 &&
           ((0x3b < bVar1 ||
            (pbVar3 = (byte *)(longlong)(char)bVar1,
            (0x800000100000200U >> ((ulonglong)pbVar3 & 0x3f) & 1) == 0))))) {
      pbVar3 = (byte *)(ulonglong)(bVar1 - 0x30);
      if (9 < (byte)(bVar1 - 0x30)) goto LAB_140011896;
      pbVar9 = (byte *)(ulonglong)((int)pbVar9 + 1);
      *param_3 = (int)(char)bVar1 + (*param_3 * 5 + -0x18) * 2;
      bVar1 = pbVar9[(longlong)param_1];
    }
  }
  return CONCAT71((int7)((ulonglong)pbVar3 >> 8),1);
}



===== ProcessSsuReplies @ 1400118b0 =====

undefined8 ProcessSsuReplies(longlong param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  
  do {
    cVar2 = PollLSImpiIsr(param_1,param_2);
    StorPortStallExecution(500);
  } while (cVar2 != '\0');
  if ((uint)*(ushort *)(param_1 + 0xb322) < *(uint *)(param_1 + 0x678)) {
    return 2;
  }
  if (*(int *)(param_1 + 0xb318) == 0) {
    return 1;
  }
  piVar1 = (int *)(param_1 + 0xb31c);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 != 0) {
    return 0;
  }
  if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x80003) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x80003,
                (undefined1 *)(param_1 + 0xb318),4,param_2);
  }
  return 3;
}



===== ProcessSsuTmrReplies @ 1400119a0 =====

undefined8 ProcessSsuTmrReplies(longlong param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  
  do {
    cVar2 = PollLSImpiIsr(param_1,param_2);
    StorPortStallExecution(500);
  } while (cVar2 != '\0');
  if (*(int *)(param_1 + 0xb318) == 0) {
    return 1;
  }
  piVar1 = (int *)(param_1 + 0xb31c);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 != 0) {
    return 0;
  }
  LogSystemEvent(param_1,0xad010071,0x8004af01,
                 (byte *)"TMR commands time out which are sent after SSU times out",param_2);
  if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x80005) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x80005,
                (undefined1 *)(param_1 + 0xb318),4,param_2);
  }
  KickStart(param_1,param_2);
  return 2;
}



===== ProcessSynchronousAction @ 140011a90 =====

undefined8 ProcessSynchronousAction(longlong param_1)

{
  ushort uVar1;
  longlong lVar2;
  longlong *in_RAX;
  uint uVar3;
  uint uVar4;
  undefined8 *puVar5;
  short sVar6;
  int iVar7;
  ulonglong uVar8;
  
  uVar4 = *(uint *)(param_1 + 0x67c);
  *(undefined1 *)(param_1 + 0xe7f) = 1;
  uVar3 = uVar4;
  if ((uVar4 & 1) != 0) {
    uVar8 = (ulonglong)*(byte *)(param_1 + 0xdad);
    iVar7 = *(int *)(param_1 + 0x76c + uVar8 * 4);
    if (iVar7 != 0) {
      do {
        **(int **)(param_1 + 0xe8) = iVar7;
        LOCK();
        UNLOCK();
        **(undefined4 **)(param_1 + 0xf0) = *(undefined4 *)(param_1 + 0xa8c + uVar8 * 4);
        LOCK();
        UNLOCK();
        *(undefined4 *)(param_1 + 0x76c + uVar8 * 4) = 0;
        uVar3 = 0;
        if ((char)uVar8 != -0x39) {
          uVar3 = (int)uVar8 + 1U & 0xff;
        }
        uVar8 = (ulonglong)uVar3;
        *(char *)(param_1 + 0xdad) = (char)uVar3;
        iVar7 = *(int *)(param_1 + 0x76c + uVar8 * 4);
      } while (iVar7 != 0);
      uVar3 = *(uint *)(param_1 + 0x67c);
    }
    in_RAX = (longlong *)0x0;
    uVar3 = uVar3 & 0xfffffffe;
    *(uint *)(param_1 + 0x67c) = uVar3;
  }
  if ((uVar4 & 2) != 0) {
    uVar8 = (ulonglong)*(byte *)(param_1 + 0xdaf);
    sVar6 = *(short *)(param_1 + 0xdb0 + uVar8 * 8);
    if (sVar6 != 0) {
      do {
        in_RAX = *(longlong **)(param_1 + 0x5d0);
        lVar2 = *in_RAX;
        if (*(longlong *)(lVar2 + 8) != 0) goto LAB_140011c49;
        *(longlong **)(param_1 + 0x5d0) = in_RAX + 1;
        if (in_RAX + 1 == *(longlong **)(param_1 + 0x5e0)) {
          *(undefined8 *)(param_1 + 0x5d0) = *(undefined8 *)(param_1 + 0x5c8);
        }
        uVar1 = *(ushort *)(lVar2 + 0x10);
        *(undefined8 *)(lVar2 + 8) = 0xea;
        puVar5 = (undefined8 *)
                 ((longlong)(int)((uint)*(ushort *)(param_1 + 0x2ea) * (uint)uVar1) +
                 *(longlong *)(param_1 + 0x310));
        *puVar5 = 0;
        puVar5[1] = 0;
        *(undefined4 *)(puVar5 + 2) = 0;
        *(short *)((longlong)puVar5 + 0xc) = sVar6;
        *(undefined1 *)((longlong)puVar5 + 3) = 8;
        *(undefined4 *)(puVar5 + 2) = *(undefined4 *)(param_1 + 0xdb4 + uVar8 * 8);
        **(int **)(param_1 + 0xe8) = (uint)uVar1 * 0x10000 + 8;
        LOCK();
        UNLOCK();
        **(undefined4 **)(param_1 + 0xf0) = 0;
        LOCK();
        UNLOCK();
        *(undefined2 *)(param_1 + 0xdb0 + uVar8 * 8) = 0;
        uVar4 = 0;
        if ((char)uVar8 != '\t') {
          uVar4 = (int)uVar8 + 1U & 0xff;
        }
        uVar8 = (ulonglong)uVar4;
        *(char *)(param_1 + 0xdaf) = (char)uVar4;
        sVar6 = *(short *)(param_1 + 0xdb0 + uVar8 * 8);
      } while (sVar6 != 0);
      uVar3 = *(uint *)(param_1 + 0x67c);
    }
    in_RAX = (longlong *)0x0;
    *(uint *)(param_1 + 0x67c) = uVar3 & 0xfffffffd;
  }
LAB_140011c49:
  *(undefined1 *)(param_1 + 0xe7f) = 0;
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}



===== ProcessTmResetReply @ 140011c60 =====

void ProcessTmResetReply(longlong param_1,short *param_2,int param_3)

{
  char cVar1;
  char cVar2;
  short sVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 uVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong lVar9;
  ushort uVar10;
  longlong *plVar11;
  undefined4 uVar12;
  bool bVar13;
  
  lVar4 = *(longlong *)(param_1 + 0x5e8);
  cVar1 = *(char *)((longlong)param_2 + 5);
  sVar3 = *param_2;
  lVar5 = *(longlong *)(lVar4 + 0x68);
  cVar2 = *(char *)(lVar5 + 0x5c);
  if (*(int *)(lVar4 + 0x14) == 0x20) {
    bVar13 = cVar1 == '\x05';
LAB_140011cb5:
    if (!bVar13) goto LAB_140011ef1;
  }
  else if (*(int *)(lVar4 + 0x14) == 0x13) {
    bVar13 = cVar1 == '\x03';
    goto LAB_140011cb5;
  }
  if ((*(char *)(param_1 + 0x12a) != '\0') && (uVar10 = 1, 1 < *(byte *)(param_1 + 299))) {
    do {
      LSImpiMSIIsr(param_1,(byte)uVar10);
      uVar10 = uVar10 + 1;
    } while (uVar10 < *(byte *)(param_1 + 299));
  }
  uVar8 = 1;
  bVar13 = false;
  if (*(ushort *)(param_1 + 0x654) != 0) {
    lVar9 = *(longlong *)(param_1 + 0x350);
    do {
      lVar7 = uVar8 * 0x20;
      if (((*(longlong *)(lVar7 + 8 + lVar9) != 0) && (*(short *)(lVar7 + 0x14 + lVar9) == sVar3))
         && ((cVar1 != '\x05' || (*(char *)(lVar7 + 0x16 + lVar9) == cVar2)))) {
        bVar13 = true;
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x2000d) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x2000d,
                      (undefined1 *)(lVar5 + 0x5a),3,param_3);
        }
        break;
      }
      uVar10 = (short)uVar8 + 1;
      uVar8 = (ulonglong)uVar10;
      bVar13 = false;
    } while (uVar10 <= *(ushort *)(param_1 + 0x654));
  }
  if (*(longlong *)(lVar4 + 0x68) == 0) goto LAB_140011ef1;
  uVar6 = 4;
  if (!bVar13) {
    uVar6 = 1;
  }
  *(undefined1 *)(lVar4 + 3) = uVar6;
  StorPortNotification(0,param_1,lVar4);
  if (cVar1 == '\x05') {
    if (*(char *)(param_1 + 0x3b8) != '\0') {
      if (bVar13) {
        if ((*(uint *)(param_1 + 0x3bc) & 0x20010) != 0) {
          uVar12 = 0x20010;
LAB_140011e54:
          RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),uVar12,
                      (undefined1 *)(lVar5 + 0x5a),3,param_3);
        }
      }
      else if ((*(uint *)(param_1 + 0x3bc) & 0x2000e) != 0) {
        uVar12 = 0x2000e;
        goto LAB_140011e54;
      }
    }
  }
  else if ((cVar1 == '\x03') && (*(char *)(param_1 + 0x3b8) != '\0')) {
    if (bVar13) {
      if ((*(uint *)(param_1 + 0x3bc) & 0x20011) != 0) {
        uVar12 = 0x20011;
        goto LAB_140011e54;
      }
    }
    else if ((*(uint *)(param_1 + 0x3bc) & 0x2000f) != 0) {
      uVar12 = 0x2000f;
      goto LAB_140011e54;
    }
  }
  plVar11 = (longlong *)(param_1 + 0x1068);
  lVar9 = 100;
  do {
    if (((*plVar11 == lVar4) && (*plVar11 = -1, *(char *)(param_1 + 0x3b8) != '\0')) &&
       ((*(uint *)(param_1 + 0x3bc) & 0x2001e) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x2001e,
                  (undefined1 *)(lVar5 + 0x5a),3,param_3);
    }
    plVar11 = plVar11 + 1;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
LAB_140011ef1:
  *(undefined8 *)(param_1 + 0x5e8) = 0;
  CheckResetQueue(param_1,param_3);
  return;
}



===== QueueRequestDescriptor @ 140011f20 =====

void QueueRequestDescriptor(longlong param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  byte bVar1;
  char cVar2;
  ulonglong uVar3;
  
  if (*(char *)(param_1 + 0xe7f) != '\0') {
    **(undefined4 **)(param_1 + 0xe8) = param_2;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0xf0) = param_3;
    LOCK();
    UNLOCK();
    return;
  }
  bVar1 = *(byte *)(param_1 + 0xdac);
  uVar3 = (ulonglong)bVar1;
  if (*(int *)(param_1 + 0x76c + uVar3 * 4) == 0) {
    *(undefined4 *)(param_1 + 0x76c + uVar3 * 4) = param_2;
    *(undefined4 *)(param_1 + 0xa8c + uVar3 * 4) = param_3;
    cVar2 = '\0';
    if (bVar1 != 199) {
      cVar2 = bVar1 + 1;
    }
    *(uint *)(param_1 + 0x67c) = *(uint *)(param_1 + 0x67c) | 1;
    *(char *)(param_1 + 0xdac) = cVar2;
    if (*(char *)(param_1 + 0xeb9) == '\0') {
                    /* WARNING: Could not recover jumptable at 0x000140011fca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      StorPortNotification(6,param_1,WatchdogTimer,10000);
      return;
    }
  }
  else {
    LogSystemEvent(param_1,0xad010039,0x8004af01,(byte *)"Request Descriptor Queue Full",param_4);
    *(undefined4 *)(param_1 + 0xec0) = 1;
    if (*(int *)(param_1 + 0x630) == 0) {
      StorPortPause(param_1,300);
    }
    *(undefined2 *)(param_1 + 0xebc) = 0;
    KickStart(param_1,param_4);
  }
  return;
}



===== ReadAndSetSASPages @ 140012030 =====

void ReadAndSetSASPages(longlong param_1,int param_2)

{
  uint *puVar1;
  byte bVar2;
  int iVar3;
  undefined8 uVar4;
  bool bVar5;
  char cVar6;
  ushort uVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  char cVar10;
  undefined8 *puVar11;
  ulonglong uVar12;
  char cVar13;
  uint uVar14;
  longlong lVar15;
  int iVar16;
  bool bVar17;
  bool bVar18;
  ushort local_res8;
  char local_res18;
  ushort local_res20;
  uint local_58;
  uint local_54;
  uint local_50 [2];
  undefined8 local_48;
  
  local_48 = 0;
  cVar6 = '\0';
  local_res8 = local_res8 & 0xff00;
  bVar17 = true;
  local_res18 = '\0';
  local_res20 = local_res8;
  cVar13 = '\x01';
  do {
    bVar5 = true;
    bVar18 = bVar17;
    switch(cVar13) {
    case '\x01':
      cVar13 = '\x02';
      bVar5 = false;
      break;
    case '\x02':
      local_58 = 0x1010000;
      cVar13 = '\x03';
      if (&local_58 == (uint *)(param_1 + 0x15b0)) {
        puVar11 = *(undefined8 **)(param_1 + 0x330);
        uVar7 = *(ushort *)(param_1 + 0x672);
      }
      else {
LAB_1400120f1:
        puVar11 = *(undefined8 **)(param_1 + 0x318);
        uVar7 = *(ushort *)(param_1 + 0x66c);
      }
      goto LAB_1400120ff;
    case '\x03':
      cVar13 = '\x04';
      goto LAB_14001215f;
    case '\x04':
      bVar2 = *(byte *)(*(longlong *)(param_1 + 0x1508) + 0xd);
      if (bVar2 == 0xff) {
        uVar7 = 0xffff;
      }
      else {
        uVar7 = (ushort)bVar2;
      }
      *(ushort *)(param_1 + 0x15f8) = uVar7;
      local_58 = 0x1080000;
      cVar13 = '\x05';
      if (&local_58 != (uint *)(param_1 + 0x15b0)) goto LAB_1400120f1;
      puVar11 = *(undefined8 **)(param_1 + 0x330);
      uVar7 = *(ushort *)(param_1 + 0x672);
      goto LAB_1400120ff;
    case '\x05':
      cVar13 = '\x06';
      goto LAB_14001215f;
    case '\x06':
      lVar15 = *(longlong *)(param_1 + 0x1508);
      *(undefined1 *)(param_1 + 0x1560) = *(undefined1 *)(lVar15 + 4);
      *(undefined2 *)(param_1 + 0x1566) = *(undefined2 *)(lVar15 + 10);
      *(undefined2 *)(param_1 + 0x1568) = *(undefined2 *)(lVar15 + 0xc);
      *(undefined2 *)(param_1 + 0x156c) = *(undefined2 *)(lVar15 + 0x10);
      if (*(short *)(param_1 + 0x1564) == 0) {
        *(undefined2 *)(param_1 + 0x1564) = *(undefined2 *)(lVar15 + 8);
      }
      if ((*(uint *)(param_1 + 0xeb4) & 0x1000) != 0) {
        GetIrMapRange(param_1,(int *)local_50,&local_54);
        uVar12 = (ulonglong)local_50[0];
        if (local_50[0] <= local_54) {
          puVar9 = (undefined4 *)(*(longlong *)(param_1 + 0x378) + uVar12 * 0x28 + 0x14);
          do {
            *puVar9 = 0x20000000;
            puVar9 = puVar9 + 10;
            uVar14 = (int)uVar12 + 1;
            uVar12 = (ulonglong)uVar14;
          } while (uVar14 <= local_54);
        }
        cVar6 = (char)local_res8;
      }
      *(undefined4 *)(param_1 + 0x1598) = 0;
      bVar17 = (*(byte *)(lVar15 + 0xc) & 0x10) != 0;
      if (bVar17) {
        *(undefined4 *)(param_1 + 0x1598) = 1;
      }
      if ((*(byte *)(lVar15 + 0x10) & 3) == 0) {
        *(uint *)(param_1 + 0x1598) = (uint)*(byte *)(param_1 + 0x65f) + (uint)bVar17;
      }
      if ((*(uint *)(param_1 + 0xeb4) & 4) != 0) {
        local_58 = 0x10000;
        cVar13 = '\a';
        if (&local_58 != (uint *)(param_1 + 0x15b0)) goto LAB_1400120f1;
        puVar11 = *(undefined8 **)(param_1 + 0x330);
        uVar7 = *(ushort *)(param_1 + 0x672);
        goto LAB_1400120ff;
      }
      cVar13 = '\t';
      bVar5 = false;
      break;
    case '\a':
      cVar13 = '\b';
      goto LAB_14001215f;
    case '\b':
      cVar13 = '\t';
      local_58 = *(uint *)(param_1 + 0x1510);
      if (*(char *)(param_1 + 0xeb3) == '\0') {
        puVar1 = (uint *)(*(longlong *)(param_1 + 0x1508) + 4);
        *puVar1 = *puVar1 | 0x20;
      }
      else {
        puVar1 = (uint *)(*(longlong *)(param_1 + 0x1508) + 4);
        *puVar1 = *puVar1 & 0xffffffdf;
      }
      uVar4 = *(undefined8 *)(param_1 + 0x1508);
      if (&local_58 == (uint *)(param_1 + 0x15b0)) {
        puVar11 = *(undefined8 **)(param_1 + 0x330);
        uVar7 = *(ushort *)(param_1 + 0x672);
      }
      else {
        puVar11 = *(undefined8 **)(param_1 + 0x318);
        uVar7 = *(ushort *)(param_1 + 0x66c);
      }
      *puVar11 = 0;
      puVar11[1] = 0;
      puVar11[2] = 0;
      puVar11[3] = 0;
      puVar11[4] = 0;
      *(undefined4 *)(puVar11 + 5) = 0;
      *(undefined4 *)((longlong)puVar11 + 0x1c) = 0xd3000000;
      *(uint *)((longlong)puVar11 + 0x14) = local_58;
      *(undefined1 *)puVar11 = 2;
      *(undefined1 *)((longlong)puVar11 + 3) = 4;
      iVar16 = *(int *)(param_1 + 0x100);
      *(uint *)((longlong)puVar11 + 0x1c) = (local_58 >> 8 & 0xff) << 2 | 0xd3000000;
      *(int *)(puVar11 + 4) = (int)uVar4 - iVar16;
      uVar8 = *(undefined4 *)(param_1 + 0x1ec);
      *(uint *)((longlong)puVar11 + 0x1c) = *(uint *)((longlong)puVar11 + 0x1c) | 0x4000000;
      goto LAB_1400121ea;
    case '\t':
      local_58 = 0x2030000;
      cVar13 = '\n';
      if (&local_58 != (uint *)(param_1 + 0x15b0)) goto LAB_1400120f1;
      puVar11 = *(undefined8 **)(param_1 + 0x330);
      uVar7 = *(ushort *)(param_1 + 0x672);
      goto LAB_1400120ff;
    case '\n':
      cVar13 = '\v';
LAB_14001215f:
      local_58 = *(uint *)(param_1 + 0x1510);
      iVar16 = (int)*(undefined8 *)(param_1 + 0x1508);
      if (&local_58 == (uint *)(param_1 + 0x15b0)) {
        puVar11 = *(undefined8 **)(param_1 + 0x330);
        uVar7 = *(ushort *)(param_1 + 0x672);
      }
      else {
        puVar11 = *(undefined8 **)(param_1 + 0x318);
        uVar7 = *(ushort *)(param_1 + 0x66c);
      }
      *puVar11 = 0;
      puVar11[1] = 0;
      puVar11[2] = 0;
      puVar11[3] = 0;
      puVar11[4] = 0;
      *(undefined4 *)(puVar11 + 5) = 0;
      *(undefined1 *)puVar11 = 1;
LAB_1400121b9:
      *(undefined1 *)((longlong)puVar11 + 3) = 4;
      *(uint *)((longlong)puVar11 + 0x14) = local_58;
      *(undefined4 *)((longlong)puVar11 + 0x1c) = 0xd3000000;
      iVar3 = *(int *)(param_1 + 0x100);
      *(uint *)((longlong)puVar11 + 0x1c) = (local_58 >> 8 & 0xff) << 2 | 0xd3000000;
      *(int *)(puVar11 + 4) = iVar16 - iVar3;
      uVar8 = *(undefined4 *)(param_1 + 0x1ec);
LAB_1400121ea:
      *(undefined4 *)((longlong)puVar11 + 0x24) = uVar8;
LAB_1400121f1:
      QueueRequestDescriptor(param_1,(uint)uVar7 * 0x10000 + 8,0,param_2);
      cVar6 = (char)local_res8;
      break;
    case '\v':
      cVar13 = '\f';
      local_58 = 0x9000000;
      *(undefined4 *)(param_1 + 0xe20) = *(undefined4 *)(*(longlong *)(param_1 + 0x1508) + 8);
      if (&local_58 != (uint *)(param_1 + 0x15b0)) goto LAB_1400120f1;
      puVar11 = *(undefined8 **)(param_1 + 0x330);
      uVar7 = *(ushort *)(param_1 + 0x672);
      goto LAB_1400120ff;
    case '\f':
      lVar15 = *(longlong *)(param_1 + 0x15a8);
      local_58 = *(uint *)(param_1 + 0x1510);
      if (lVar15 == 0) {
        uVar7 = ((ushort)(local_58 >> 8) & 0xff) << 2;
        if (*(uint *)(param_1 + 0x1504) < (uint)uVar7) {
          local_res8 = 1;
          cVar6 = '\x01';
          break;
        }
        lVar15 = *(longlong *)(param_1 + 0x1508);
        *(longlong *)(param_1 + 0x15a8) = lVar15;
        *(ulonglong *)(param_1 + 0x1508) = (ulonglong)uVar7 + lVar15;
        *(uint *)(param_1 + 0x1504) = *(uint *)(param_1 + 0x1504) - (uint)uVar7;
      }
      cVar13 = '\r';
      if (&local_58 == (uint *)(param_1 + 0x15b0)) {
        puVar11 = *(undefined8 **)(param_1 + 0x330);
        uVar7 = *(ushort *)(param_1 + 0x672);
      }
      else {
        puVar11 = *(undefined8 **)(param_1 + 0x318);
        uVar7 = *(ushort *)(param_1 + 0x66c);
      }
      *puVar11 = 0;
      puVar11[1] = 0;
      puVar11[2] = 0;
      puVar11[3] = 0;
      puVar11[4] = 0;
      *(undefined4 *)(puVar11 + 5) = 0;
      *(uint *)((longlong)puVar11 + 0x14) = local_58;
      *(undefined4 *)((longlong)puVar11 + 0x1c) = 0xd3000000;
      *(undefined1 *)puVar11 = 6;
      *(undefined1 *)((longlong)puVar11 + 3) = 4;
      iVar16 = *(int *)(param_1 + 0x100);
      *(uint *)((longlong)puVar11 + 0x1c) = (local_58 >> 8 & 0xff) << 2 | 0xd3000000;
      *(int *)(puVar11 + 4) = (int)lVar15 - iVar16;
      *(undefined4 *)((longlong)puVar11 + 0x24) = *(undefined4 *)(param_1 + 0x1ec);
      goto LAB_1400121f1;
    case '\r':
      if (*(short *)(param_1 + 0x1502) != 0x23) {
        memmove((void *)(param_1 + 0x160c),(void *)(*(longlong *)(param_1 + 0x15a8) + 0x3c),0x10);
      }
      local_58 = 0x9050000;
      cVar13 = '\x0e';
      if (&local_58 != (uint *)(param_1 + 0x15b0)) goto LAB_1400120f1;
      puVar11 = *(undefined8 **)(param_1 + 0x330);
      uVar7 = *(ushort *)(param_1 + 0x672);
      goto LAB_1400120ff;
    case '\x0e':
      local_58 = *(uint *)(param_1 + 0x1510);
      iVar16 = (int)*(undefined8 *)(param_1 + 0x1508);
      cVar13 = '\x0f';
      if (&local_58 == (uint *)(param_1 + 0x15b0)) {
        puVar11 = *(undefined8 **)(param_1 + 0x330);
        uVar7 = *(ushort *)(param_1 + 0x672);
      }
      else {
        puVar11 = *(undefined8 **)(param_1 + 0x318);
        uVar7 = *(ushort *)(param_1 + 0x66c);
      }
      *puVar11 = 0;
      puVar11[1] = 0;
      puVar11[2] = 0;
      puVar11[3] = 0;
      puVar11[4] = 0;
      *(undefined4 *)(puVar11 + 5) = 0;
      *(undefined1 *)puVar11 = 6;
      goto LAB_1400121b9;
    case '\x0f':
      cVar13 = '\x12';
      bVar5 = false;
      *(undefined4 *)(param_1 + 0x151c) = *(undefined4 *)(*(longlong *)(param_1 + 0x1508) + 0x10);
      *(undefined4 *)(param_1 + 0x1520) = *(undefined4 *)(*(longlong *)(param_1 + 0x1508) + 0x14);
      break;
    default:
      cVar13 = '\0';
      bVar18 = false;
      break;
    case '\x12':
      cVar13 = '\x13';
      if ((*(uint *)(param_1 + 0xeb4) & 0x1000) == 0) goto LAB_14001272e;
      local_58 = 0x8010000;
      if (&local_58 != (uint *)(param_1 + 0x15b0)) goto LAB_1400120f1;
      puVar11 = *(undefined8 **)(param_1 + 0x330);
      uVar7 = *(ushort *)(param_1 + 0x672);
LAB_1400120ff:
      *puVar11 = 0;
      puVar11[1] = 0;
      puVar11[2] = 0;
      puVar11[3] = 0;
      puVar11[4] = 0;
      *(undefined4 *)(puVar11 + 5) = 0;
      *(undefined1 *)((longlong)puVar11 + 3) = 4;
      *(uint *)((longlong)puVar11 + 0x14) = local_58;
      *(undefined4 *)((longlong)puVar11 + 0x1c) = 0xd3000000;
      *(int *)(puVar11 + 4) = *(int *)(param_1 + 0x1fc) + 0x2c;
      *(undefined4 *)((longlong)puVar11 + 0x24) = *(undefined4 *)(param_1 + 0x1ec);
      QueueRequestDescriptor(param_1,(uint)uVar7 * 0x10000 + 8,0,param_2);
      cVar6 = (char)local_res8;
      break;
    case '\x13':
      if ((*(uint *)(param_1 + 0xeb4) & 0x1000) != 0) {
        local_58 = *(uint *)(param_1 + 0x1510);
        *(uint *)(param_1 + 0x15b0) = local_58;
        if (*(longlong *)(param_1 + 0x15b8) == 0) {
          uVar7 = ((ushort)(local_58 >> 8) & 0xff) << 2;
          if (*(uint *)(param_1 + 0x1504) < (uint)uVar7) {
            local_res8 = 1;
            cVar6 = '\x01';
            break;
          }
          *(longlong *)(param_1 + 0x15b8) = *(longlong *)(param_1 + 0x1508);
          *(ulonglong *)(param_1 + 0x1508) = (ulonglong)uVar7 + *(longlong *)(param_1 + 0x1508);
          *(uint *)(param_1 + 0x1504) = *(uint *)(param_1 + 0x1504) - (uint)uVar7;
        }
      }
LAB_14001272e:
      cVar13 = '\x14';
      local_48._0_6_ = CONCAT42(0xf00,(undefined2)local_48);
      goto LAB_140012738;
    case '\x14':
      if (*(longlong *)(param_1 + 0x1668) == 0) {
        uVar7 = *(short *)(param_1 + 0x1640) << 2;
        if (*(uint *)(param_1 + 0x1504) < (uint)uVar7) {
          local_res8 = 1;
          cVar6 = '\x01';
          break;
        }
        *(longlong *)(param_1 + 0x1668) = *(longlong *)(param_1 + 0x1508);
        *(ulonglong *)(param_1 + 0x1508) = (ulonglong)uVar7 + *(longlong *)(param_1 + 0x1508);
        *(uint *)(param_1 + 0x1504) = *(uint *)(param_1 + 0x1504) - (uint)uVar7;
      }
      cVar13 = '\x15';
      local_48._0_6_ = CONCAT42(0xf01,(undefined2)local_48);
LAB_140012738:
      local_48._0_7_ = CONCAT16(0x10,(undefined6)local_48);
      goto LAB_14001273c;
    case '\x15':
      if (*(longlong *)(param_1 + 0x1670) == 0) {
        uVar7 = *(short *)(param_1 + 0x1648) << 2;
        if (*(uint *)(param_1 + 0x1504) < (uint)uVar7) {
          local_res8 = 1;
          cVar6 = '\x01';
          break;
        }
        *(longlong *)(param_1 + 0x1670) = *(longlong *)(param_1 + 0x1508);
        *(ulonglong *)(param_1 + 0x1508) = (ulonglong)uVar7 + *(longlong *)(param_1 + 0x1508);
        *(uint *)(param_1 + 0x1504) = *(uint *)(param_1 + 0x1504) - (uint)uVar7;
      }
      cVar13 = '\x16';
      local_48._0_6_ = CONCAT42(0xf00,(undefined2)local_48);
      local_48._0_7_ = CONCAT16(0x12,(undefined6)local_48);
      goto LAB_14001273c;
    case '\x16':
      uVar7 = *(short *)(param_1 + 0x15dc) << 2;
      if (*(longlong *)(param_1 + 0x15e0) == 0) {
        if (*(uint *)(param_1 + 0x1504) < (uint)uVar7) {
          local_res8 = 1;
          cVar6 = '\x01';
          break;
        }
        lVar15 = *(longlong *)(param_1 + 0x1508);
        uVar14 = *(uint *)(param_1 + 0x1504) - (uint)uVar7;
        *(longlong *)(param_1 + 0x15e0) = lVar15;
        *(ulonglong *)(param_1 + 0x1508) = (ulonglong)uVar7 + lVar15;
        *(uint *)(param_1 + 0x1504) = uVar14;
        if (lVar15 == 0) {
          if (uVar14 < uVar7) {
            local_res8 = 1;
            cVar6 = '\x01';
            break;
          }
          *(longlong *)(param_1 + 0x15e0) = *(longlong *)(param_1 + 0x1508);
          *(ulonglong *)(param_1 + 0x1508) = (ulonglong)uVar7 + *(longlong *)(param_1 + 0x1508);
          *(uint *)(param_1 + 0x1504) = uVar14 - uVar7;
        }
      }
      cVar13 = '\x17';
      local_48._0_6_ = CONCAT42(0xf01,(undefined2)local_48);
      local_48._0_7_ = CONCAT16(0x12,(undefined6)local_48);
      goto LAB_14001273c;
    case '\x17':
      if (*(longlong *)(param_1 + 0x1678) == 0) {
        uVar7 = *(short *)(param_1 + 0x1650) << 2;
        if (*(uint *)(param_1 + 0x1504) < (uint)uVar7) {
          local_res8 = 1;
          cVar6 = '\x01';
          break;
        }
        *(longlong *)(param_1 + 0x1678) = *(longlong *)(param_1 + 0x1508);
        *(ulonglong *)(param_1 + 0x1508) = (ulonglong)uVar7 + *(longlong *)(param_1 + 0x1508);
        *(uint *)(param_1 + 0x1504) = *(uint *)(param_1 + 0x1504) - (uint)uVar7;
      }
      cVar13 = '\x18';
      local_48._0_6_ = CONCAT42(0xf00,(undefined2)local_48);
      local_48._0_7_ = CONCAT16(0x13,(undefined6)local_48);
      goto LAB_14001273c;
    case '\x18':
      if (*(longlong *)(param_1 + 0x1680) == 0) {
        uVar7 = *(short *)(param_1 + 0x1658) << 2;
        if (*(uint *)(param_1 + 0x1504) < (uint)uVar7) {
          local_res8 = 1;
          cVar6 = '\x01';
          break;
        }
        *(longlong *)(param_1 + 0x1680) = *(longlong *)(param_1 + 0x1508);
        *(ulonglong *)(param_1 + 0x1508) = (ulonglong)uVar7 + *(longlong *)(param_1 + 0x1508);
        *(uint *)(param_1 + 0x1504) = *(uint *)(param_1 + 0x1504) - (uint)uVar7;
      }
      cVar13 = '\x19';
      local_48._0_6_ = CONCAT42(0xf01,(undefined2)local_48);
      local_48._0_7_ = CONCAT16(0x13,(undefined6)local_48);
      goto LAB_14001273c;
    case '\x19':
      if (*(longlong *)(param_1 + 0x1688) == 0) {
        uVar7 = *(short *)(param_1 + 0x1660) << 2;
        if (*(uint *)(param_1 + 0x1504) < (uint)uVar7) {
          local_res8 = 1;
          cVar6 = '\x01';
          break;
        }
        *(longlong *)(param_1 + 0x1688) = *(longlong *)(param_1 + 0x1508);
        *(ulonglong *)(param_1 + 0x1508) = (ulonglong)uVar7 + *(longlong *)(param_1 + 0x1508);
        *(uint *)(param_1 + 0x1504) = *(uint *)(param_1 + 0x1504) - (uint)uVar7;
      }
      cVar13 = ' ';
      local_48._0_6_ = CONCAT42(0xf00,(undefined2)local_48);
      local_48._0_7_ = CONCAT16(0x15,(undefined6)local_48);
      goto LAB_14001273c;
    case ' ':
      if (*(longlong *)(param_1 + 0x15f0) == 0) {
        uVar7 = *(short *)(param_1 + 0x15ec) << 2;
        if (*(uint *)(param_1 + 0x1504) < (uint)uVar7) {
          local_res8 = 1;
          cVar6 = '\x01';
          break;
        }
        *(longlong *)(param_1 + 0x15f0) = *(longlong *)(param_1 + 0x1508);
        *(ulonglong *)(param_1 + 0x1508) = (ulonglong)uVar7 + *(longlong *)(param_1 + 0x1508);
        *(uint *)(param_1 + 0x1504) = *(uint *)(param_1 + 0x1504) - (uint)uVar7;
      }
      cVar13 = -0x10;
      local_res18 = '\0';
      local_48._0_6_ = CONCAT42(0xf00,(undefined2)local_48);
      local_48._0_7_ = CONCAT16(0x17,(undefined6)local_48);
LAB_14001273c:
      local_48 = local_48 & 0xffffffffffffff00;
      SendExtendedConfigPageMessage(param_1,'\0',(char *)&local_48,0,0,param_2);
      cVar6 = (char)local_res8;
      break;
    case -0x10:
      if (local_res18 == '\0') {
        local_res20 = *(ushort *)(param_1 + 0x15c4);
      }
      *(ushort *)(param_1 + 0x15c4) = (ushort)(*(short *)(param_1 + 0x1564) * 0x14 + 8U) >> 2;
      *(undefined1 *)(param_1 + 0x676) = 0;
      if (local_res18 == '\0') {
LAB_140012b14:
        local_res18 = local_res18 + '\x01';
        SendExtendedConfigPageMessage
                  (param_1,'\x06',(char *)(param_1 + 0x15c0),
                   (uint)*(ushort *)(param_1 + 0x1564) << 0x10,
                   (int)*(undefined8 *)(param_1 + 0x15c8),param_2);
        cVar6 = (char)local_res8;
      }
      else if (*(short *)(param_1 + 0x1502) == 0) {
        cVar13 = -0xf;
        *(ushort *)(param_1 + 0x15c4) = local_res20 + 5;
        bVar5 = false;
      }
      else {
        if (local_res18 != '\x02') goto LAB_140012b14;
        *(ushort *)(param_1 + 0x1568) = *(ushort *)(param_1 + 0x1568) | 1;
        LogSystemEvent(param_1,0xad010050,0x8004af01,(byte *)"Persistency Forced Off",param_2);
        bVar5 = false;
        cVar13 = -0xf;
        cVar6 = (char)local_res8;
      }
    }
    bVar17 = false;
    if (cVar6 == '\0') {
      bVar17 = bVar18;
    }
    cVar10 = '\0';
    if (cVar6 == '\0') {
      cVar10 = cVar13;
    }
    *(char *)(param_1 + 0xec5) = cVar10;
    bVar18 = !bVar17;
    if (!bVar18) {
      if (bVar5) {
        uVar14 = 0;
        do {
          cVar6 = PollLSImpiIsr(param_1,param_2);
          if (cVar6 != '\0') break;
          StorPortStallExecution(500);
          uVar14 = uVar14 + 1;
        } while (uVar14 < 20000);
        if ((uVar14 == 20000) || (cVar10 == '\0')) {
          bVar17 = false;
        }
        cVar6 = (char)local_res8;
      }
      bVar18 = !bVar17;
    }
    cVar13 = cVar10;
    if (bVar18) {
      return;
    }
  } while( true );
}



===== ReceiveDataViaHandshake @ 140012d60 =====

ulonglong ReceiveDataViaHandshake(longlong param_1,uint param_2)

{
  ushort uVar1;
  bool bVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined2 *puVar7;
  
  bVar2 = false;
  uVar5 = 60000;
  if (*(char *)(param_1 + 0x683) == '\x06') {
    uVar5 = *(uint *)(param_1 + 0x618);
  }
  uVar6 = 0;
  puVar7 = (undefined2 *)(param_1 + 0x720);
  do {
    if (bVar2) break;
    uVar4 = 0;
    if (uVar5 != 0) {
      do {
        if (**(uint **)(param_1 + 0x48) == 0xffffffff) break;
        if ((**(uint **)(param_1 + 0x48) & 1) != 0) goto LAB_140012dd4;
        StorPortStallExecution(500);
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar5);
    }
    bVar2 = true;
LAB_140012dd4:
    *puVar7 = (short)**(undefined4 **)(param_1 + 0x18);
    **(undefined4 **)(param_1 + 0x48) = 0;
    LOCK();
    UNLOCK();
    uVar6 = uVar6 + 1;
    puVar7 = puVar7 + 1;
  } while (uVar6 < 2);
  uVar6 = 2;
  uVar5 = (uint)(byte)*(undefined2 *)(param_1 + 0x722) * 2;
  if (2 < uVar5) {
    puVar7 = (undefined2 *)(param_1 + 0x724);
    do {
      if (bVar2) break;
      uVar4 = 0;
      do {
        if (**(uint **)(param_1 + 0x48) == 0xffffffff) break;
        if ((**(uint **)(param_1 + 0x48) & 1) != 0) goto LAB_140012e48;
        StorPortStallExecution(500);
        uVar4 = uVar4 + 1;
      } while (uVar4 < 60000);
      bVar2 = true;
LAB_140012e48:
      if (uVar6 < param_2) {
        *puVar7 = (short)**(undefined4 **)(param_1 + 0x18);
      }
      **(undefined4 **)(param_1 + 0x48) = 0;
      LOCK();
      UNLOCK();
      uVar6 = uVar6 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar6 < uVar5);
  }
  uVar5 = 0;
  do {
    if (**(uint **)(param_1 + 0x48) == 0xffffffff) break;
    if ((**(uint **)(param_1 + 0x48) & 1) != 0) goto LAB_140012e9a;
    StorPortStallExecution(500);
    uVar5 = uVar5 + 1;
  } while (uVar5 < 60000);
  bVar2 = true;
LAB_140012e9a:
  **(undefined4 **)(param_1 + 0x48) = 0;
  LOCK();
  UNLOCK();
  uVar3 = 0;
  if (uVar6 >> 1 == (uint)*(byte *)(param_1 + 0x722)) {
    uVar1 = *(ushort *)(param_1 + 0x72e);
    uVar3 = (ulonglong)uVar1;
    if (((uVar1 & 0x7fff) == 0) && (!bVar2)) {
      return CONCAT71((uint7)(byte)(uVar1 >> 8),1);
    }
  }
  return uVar3 & 0xffffffffffffff00;
}



===== ReleaseFwDiagBuffer @ 140012ef0 =====

ulonglong ReleaseFwDiagBuffer(longlong param_1,longlong param_2,int param_3)

{
  undefined1 *puVar1;
  ulonglong in_RAX;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined1 *puVar4;
  
  if (*(char *)(param_2 + 0x10) == '\0') {
    return in_RAX & 0xffffffffffffff00;
  }
  puVar1 = *(undefined1 **)(param_1 + 0x608);
  if (*(ushort *)(param_1 + 0x2ea) != 0) {
    puVar4 = puVar1;
    for (uVar3 = (ulonglong)*(ushort *)(param_1 + 0x2ea); uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
  }
  puVar1[1] = *(undefined1 *)(param_2 + 0xc);
  puVar1[3] = 0x1e;
  uVar2 = QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x66a) * 0x10000 + 8,0,param_3)
  ;
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== ResetActive @ 140012f60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ResetActive(longlong param_1,uint param_2,int param_3)

{
  undefined1 auStackY_68 [32];
  undefined4 local_28;
  uint local_24;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = *(undefined4 *)(param_1 + 0x628);
  local_20 = 0;
  if ((param_2 >> 0x1e & 1) == 0) {
    *(uint *)(param_1 + 0x628) = param_2;
  }
  else if ((((*(longlong *)(param_1 + 0x5e8) == 0) && (*(char *)(param_1 + 0x15a0) == '\0')) &&
           (*(char *)(param_1 + 0xeb8) == '\0')) && (*(int *)(param_1 + 0xf38) == 0)) {
    *(undefined4 *)(param_1 + 0x628) = 0;
    local_20 = 0xffffffff;
  }
  if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x20020) != 0)) {
    local_24 = param_2;
    RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x20020,
                (undefined1 *)&local_28,0xc,param_3);
  }
  return;
}



===== ResumeDevice @ 140013020 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ResumeDevice(longlong param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                 undefined2 param_5,undefined4 param_6,undefined4 param_7,int param_8)

{
  longlong lVar1;
  undefined1 auStackY_98 [32];
  undefined4 local_58;
  undefined4 local_54;
  undefined2 local_50;
  undefined2 local_4e;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_4a;
  char local_49;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = param_6;
  local_54 = param_7;
  local_50 = 0;
  local_4e = param_5;
  local_4c = param_2;
  local_4b = param_3;
  local_4a = param_4;
  lVar1 = StorPortGetLogicalUnit();
  if (lVar1 == 0) {
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x232) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x232,
                  (undefined1 *)&local_58,0x10,param_8);
    }
  }
  else {
    local_49 = *(char *)(lVar1 + 0x30);
    while (local_49 != '\0') {
      local_49 = local_49 + -1;
      *(char *)(lVar1 + 0x30) = local_49;
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x112) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x112,
                    (undefined1 *)&local_58,0x10,param_8);
      }
      StorPortResumeDevice(param_1,param_2,param_3,param_4);
      local_49 = *(char *)(lVar1 + 0x30);
    }
  }
  return;
}



===== RsIoctl_sm @ 1400131a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 RsIoctl_sm(longlong param_1,longlong param_2,longlong param_3,int param_4)

{
  undefined1 uVar1;
  int iVar2;
  longlong lVar3;
  ushort uVar4;
  short *psVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  short *psVar8;
  longlong lVar9;
  longlong lVar10;
  undefined8 uVar11;
  undefined1 auStackY_88 [32];
  longlong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_88;
  lVar9 = 0;
  psVar8 = (short *)0x0;
  uVar4 = 0;
  uVar11 = 1;
  while( true ) {
    while( true ) {
      if (*(longlong *)(param_1 + 0x3c8) == 0) {
        if ((param_2 == 0) && (*(int *)(param_1 + 0x3c0) != 0)) {
          *(undefined4 *)(param_1 + 0x3c0) = 0;
          *(undefined1 *)(param_1 + 0xec8) = 0;
          if (*(char *)(param_1 + 0x3b8) == '\0') {
            return 1;
          }
          if ((*(uint *)(param_1 + 0x3bc) & 0x27b) == 0) {
            return 1;
          }
          RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x27b,
                      (undefined1 *)0x0,0,param_4);
          return 1;
        }
      }
      else {
        lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x3c8) + 0x40);
        psVar8 = (short *)(lVar9 + 0x24);
      }
      iVar2 = *(int *)(param_1 + 0x3c0);
      if (iVar2 != 0) break;
      if (param_3 != 0) {
        return 1;
      }
      *(undefined1 *)(param_1 + 0xec8) = 1;
      *(longlong *)(param_1 + 0x3c8) = param_2;
      *(undefined4 *)(param_1 + 0x3c0) = 1;
    }
    if (iVar2 != 1) break;
    if (*(uint *)(lVar9 + 0x18) < 0x20) {
      *(undefined4 *)(lVar9 + 0x14) = 2;
LAB_1400133d6:
      *(undefined1 *)(param_1 + 0xec8) = 0;
      *(undefined8 *)(param_1 + 0x3c8) = 0;
      *(undefined4 *)(param_1 + 0x3c0) = 0;
      return 0;
    }
    uVar4 = *psVar8 * 0x80 + psVar8[1];
    if (*(uint *)(param_1 + 0x678) <= (uint)uVar4) {
      *(undefined4 *)(lVar9 + 0x14) = 3;
      goto LAB_1400133d6;
    }
    uVar4 = *(ushort *)(*(longlong *)(param_1 + 0x378) + 0x1a + (ulonglong)uVar4 * 0x28);
    if (uVar4 == 0) {
      *(undefined4 *)(lVar9 + 0x14) = 5;
      goto LAB_1400133d6;
    }
    if (*(int *)(lVar9 + 0x20) == 1) {
      *(undefined4 *)(param_1 + 0x3c0) = 2;
    }
    else {
      if (1 < *(int *)(lVar9 + 0x20) - 2U) {
        *(undefined1 *)(param_1 + 0xec8) = 0;
        *(undefined8 *)(param_1 + 0x3c8) = 0;
        *(undefined4 *)(lVar9 + 0x14) = 1;
        *(undefined4 *)(param_1 + 0x3c0) = 0;
        LogSystemEvent(param_1,0xad010078,0x8004af01,(byte *)"Invalid function for Read slot IOCTL",
                       param_4);
        if (*(char *)(param_1 + 0x3b8) == '\0') {
          return 0;
        }
        if ((*(uint *)(param_1 + 0x3bc) & 0x248) == 0) {
          return 0;
        }
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x248,
                    (undefined1 *)(lVar9 + 0x20),4,param_4);
        return 0;
      }
      *(undefined4 *)(param_1 + 0x3c0) = 4;
    }
  }
  if (iVar2 == 2) {
    SendExtendedConfigPageMessage
              (param_1,'\x01',(char *)(param_1 + 0x15d8),uVar4 | 0x20000000,
               (int)*(undefined8 *)(param_1 + 0x15e0),param_4);
    *(undefined4 *)(param_1 + 0x3c0) = 3;
    return 1;
  }
  if (iVar2 == 3) {
    memmove((void *)(lVar9 + 0x1c),&RsIoctlRecordVersion,4);
    lVar3 = *(longlong *)(param_1 + 0x15e0);
    if (*(short *)(param_1 + 0x1502) == 0x22) {
      *(undefined4 *)(lVar9 + 0x14) = 4;
      uVar11 = 0;
      goto LAB_14001349f;
    }
    psVar5 = psVar8 + 4;
    *(undefined4 *)(psVar8 + 10) = *(undefined4 *)(lVar3 + 0x1c);
    puVar7 = (undefined1 *)(lVar3 + 0x13);
    lVar10 = 8;
    psVar8[3] = *(short *)(lVar3 + 8);
    do {
      uVar1 = *puVar7;
      puVar7 = puVar7 + -1;
      *(undefined1 *)psVar5 = uVar1;
      psVar5 = (short *)((longlong)psVar5 + 1);
      lVar10 = lVar10 + -1;
    } while (lVar10 != 0);
    *(undefined1 *)(psVar8 + 8) = *(undefined1 *)(lVar3 + 0x16);
  }
  else {
    if (iVar2 != 4) goto LAB_14001349f;
    uVar6 = 0x40;
    if (*(int *)(lVar9 + 0x20) != 2) {
      uVar6 = 0;
    }
    SendSEPMessage(param_1,uVar6,uVar4,param_4);
  }
  *(undefined4 *)(lVar9 + 0x14) = 0;
LAB_14001349f:
  local_48 = *(longlong *)(param_1 + 0x3c8);
  local_40 = *(undefined4 *)(local_48 + 0x50);
  local_3c = *(undefined4 *)(local_48 + 0x54);
  local_38 = 1;
  *(undefined1 *)(local_48 + 3) = 1;
  StorPortNotification(0,param_1,*(undefined8 *)(param_1 + 0x3c8));
  *(undefined8 *)(param_1 + 0x3c8) = 0;
  if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x400020) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x400020,
                (undefined1 *)&local_48,0x11,param_4);
  }
  *(undefined1 *)(param_1 + 0xec8) = 0;
  *(undefined4 *)(param_1 + 0x3c0) = 0;
  return uVar11;
}



===== SasBcAsyncEvent @ 1400135a0 =====

void SasBcAsyncEvent(longlong param_1,int param_2)

{
  char cVar1;
  undefined1 uVar2;
  short sVar3;
  undefined2 uVar4;
  short *psVar5;
  undefined8 *puVar6;
  uint uVar7;
  longlong lVar8;
  ushort uVar9;
  longlong lVar10;
  
  if (*(char *)(param_1 + 0x15a0) == '\0') {
    *(undefined1 *)(param_1 + 0x15a4) = 0;
    return;
  }
LAB_1400135f0:
  do {
    switch(*(undefined1 *)(param_1 + 0x15a4)) {
    case 1:
      *(undefined2 *)(param_1 + 0x159c) = 1;
      *(undefined1 *)(param_1 + 0x15a4) = 5;
      break;
    default:
      goto switchD_14001360f_caseD_2;
    case 4:
      *(short *)(param_1 + 0x159c) = *(short *)(param_1 + 0x159c) + 1;
      if (*(ushort *)(param_1 + 0x654) < *(ushort *)(param_1 + 0x159c)) {
        *(undefined1 *)(param_1 + 0x15a4) = 9;
        break;
      }
    case 5:
      *(undefined1 *)(param_1 + 0x15a4) = 4;
      lVar10 = (ulonglong)*(ushort *)(param_1 + 0x159c) * 0x20 + *(longlong *)(param_1 + 0x350);
      if (*(longlong *)(lVar10 + 8) != 0) {
        sVar3 = *(short *)(lVar10 + 0x14);
        uVar2 = *(undefined1 *)(lVar10 + 0x16);
        uVar7 = GetMapTableIndexFromHandle(param_1,sVar3);
        if ((uVar7 != 0xffffffff) &&
           ((*(uint *)(*(longlong *)(param_1 + 0x378) + 0x14 + (ulonglong)uVar7 * 0x28) >> 10 & 1)
            != 0)) {
          *(undefined1 *)(param_1 + 0x15a4) = 6;
          psVar5 = *(short **)(param_1 + 0x608);
          psVar5[0] = 0;
          psVar5[1] = 0;
          psVar5[2] = 0;
          psVar5[3] = 0;
          psVar5[4] = 0;
          psVar5[5] = 0;
          psVar5[6] = 0;
          psVar5[7] = 0;
          psVar5[8] = 0;
          psVar5[9] = 0;
          psVar5[10] = 0;
          psVar5[0xb] = 0;
          psVar5[0xc] = 0;
          psVar5[0xd] = 0;
          psVar5[0xe] = 0;
          psVar5[0xf] = 0;
          psVar5[0x10] = 0;
          psVar5[0x11] = 0;
          psVar5[0x12] = 0;
          psVar5[0x13] = 0;
          psVar5[0x14] = 0;
          psVar5[0x15] = 0;
          psVar5[0x16] = 0;
          psVar5[0x17] = 0;
          psVar5[0x18] = 0;
          psVar5[0x19] = 0;
          *psVar5 = sVar3;
          *(undefined1 *)((longlong)psVar5 + 3) = 1;
          *(undefined1 *)((longlong)psVar5 + 5) = 7;
          *(undefined1 *)((longlong)psVar5 + 0xd) = uVar2;
          psVar5[0x18] = *(short *)(lVar10 + 0x10);
          QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x66a) * 0x10000 + 6,0,param_2)
          ;
          return;
        }
      }
      break;
    case 6:
      *(undefined1 *)(param_1 + 0x15a4) = 4;
      lVar10 = (ulonglong)*(ushort *)(param_1 + 0x159c) * 0x20 + *(longlong *)(param_1 + 0x350);
      if (*(longlong *)(lVar10 + 8) != 0) {
        if (*(short *)(*(longlong *)(param_1 + 0x600) + 0xe) == 0) goto code_r0x00014001372e;
        goto LAB_140013746;
      }
      break;
    case 7:
      *(undefined1 *)(param_1 + 0x15a4) = 4;
      *(undefined1 *)(param_1 + 0x15a2) = 0;
      *(undefined1 *)(param_1 + 0x161c) = 0;
      if (*(short *)(*(longlong *)(param_1 + 0x600) + 0xe) != 0) {
        LogSystemEvent(param_1,0xad010037,0x8004af01,
                       (byte *)"Broadcast Async Event Task Management (Abort task set) error",
                       param_2);
      }
      if ((*(char *)(param_1 + 0x12a) != '\0') && (uVar9 = 1, 1 < *(byte *)(param_1 + 299))) {
        do {
          LSImpiMSIIsr(param_1,(byte)uVar9);
          uVar9 = uVar9 + 1;
        } while (uVar9 < *(byte *)(param_1 + 299));
      }
      uVar9 = 1;
      if (*(ushort *)(param_1 + 0x654) != 0) {
        lVar10 = *(longlong *)(param_1 + 0x350);
        do {
          lVar8 = (ulonglong)uVar9 * 0x20;
          if (((*(longlong *)(lVar8 + 8 + lVar10) != 0) &&
              (*(short *)(param_1 + 0x159e) == *(short *)(lVar8 + 0x14 + lVar10))) &&
             (*(char *)(param_1 + 0x15a3) == *(char *)(lVar8 + 0x16 + lVar10))) {
            LogSystemEvent(param_1,0xad010035,0xc004af02,
                           (byte *)
                           "IOs still active on bus when TM reply was received(SasBcAsyncEvent)",
                           param_2);
            *(undefined1 *)(param_1 + 0x15a4) = 8;
            *(undefined4 *)(param_1 + 0xec0) = 1;
            KickStart(param_1,param_2);
            return;
          }
          uVar9 = uVar9 + 1;
        } while (uVar9 <= *(ushort *)(param_1 + 0x654));
      }
      break;
    case 9:
      if (*(char *)(param_1 + 0x15a1) == '\0') {
        *(undefined1 *)(param_1 + 0x15a0) = 0;
        *(undefined1 *)(param_1 + 0x15a4) = 0;
        StorPortResume(param_1);
        ResetActive(param_1,0x40000007,param_2);
        CheckResetQueue(param_1,param_2);
        return;
      }
      *(undefined1 *)(param_1 + 0x15a1) = 0;
      *(undefined1 *)(param_1 + 0x15a4) = 1;
    }
  } while( true );
code_r0x00014001372e:
  cVar1 = *(char *)(*(longlong *)(param_1 + 0x600) + 4);
  if ((cVar1 != -0x80) && (cVar1 != '\b')) {
    if (cVar1 != '\0') {
LAB_140013746:
      LogSystemEvent(param_1,0xad010037,0x8004af01,
                     (byte *)"Broadcast Async Event Task Management error",param_2);
    }
    *(undefined1 *)(param_1 + 0x15a4) = 7;
    uVar4 = *(undefined2 *)(lVar10 + 0x14);
    puVar6 = *(undefined8 **)(param_1 + 0x608);
    *(undefined2 *)(param_1 + 0x159e) = uVar4;
    uVar2 = *(undefined1 *)(lVar10 + 0x16);
    *(undefined1 *)(param_1 + 0x15a3) = uVar2;
    *puVar6 = 0;
    puVar6[1] = 0;
    puVar6[2] = 0;
    puVar6[3] = 0;
    puVar6[4] = 0;
    puVar6[5] = 0;
    *(undefined4 *)(puVar6 + 6) = 0;
    *(undefined2 *)puVar6 = uVar4;
    *(undefined1 *)((longlong)puVar6 + 3) = 1;
    *(undefined1 *)((longlong)puVar6 + 5) = 2;
    *(undefined1 *)((longlong)puVar6 + 0xd) = uVar2;
    *(undefined1 *)(param_1 + 0x15a2) = 1;
    *(undefined1 *)(param_1 + 0x161c) = 2;
    QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x66a) * 0x10000 + 6,0,param_2);
    AfdMasterTrigger(param_1,4,param_2);
switchD_14001360f_caseD_2:
    return;
  }
  goto LAB_1400135f0;
}



===== SendAndProcessSSUCommands @ 1400139a0 =====

void SendAndProcessSSUCommands(longlong param_1,int param_2)

{
  int iVar1;
  undefined8 uVar2;
  byte bVar3;
  
  bVar3 = 8;
  do {
    if (bVar3 == 8) {
      *(undefined4 *)(param_1 + 0xb318) = 0;
      bVar3 = 9;
      *(undefined2 *)(param_1 + 0xb322) = 0;
LAB_140013ace:
      *(undefined4 *)(param_1 + 0xb31c) = 20000;
    }
    else if (bVar3 == 9) {
      SendSsuMessagesToDevices(param_1);
      bVar3 = -(*(int *)(param_1 + 0xb318) != 0) & 10;
    }
    else if (bVar3 == 10) {
      uVar2 = ProcessSsuReplies(param_1,param_2);
      iVar1 = (int)uVar2;
      if (iVar1 == 1) {
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x80002) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x80002,
                      (undefined1 *)(param_1 + 0xb318),4,param_2);
        }
        bVar3 = 0;
      }
      else if (iVar1 == 2) {
        bVar3 = 9;
      }
      else if (iVar1 == 3) {
        bVar3 = 0xb;
      }
    }
    else {
      if (bVar3 == 0xb) {
        SendSsuTmrMessagesToDevices(param_1,param_2);
        bVar3 = 0xc;
        goto LAB_140013ace;
      }
      if (bVar3 == 0xc) {
        uVar2 = ProcessSsuTmrReplies(param_1,param_2);
        if ((int)uVar2 - 1U < 2) {
          bVar3 = 0;
        }
      }
      else {
        LogSystemEvent(param_1,0xad010072,0xc004af02,
                       (byte *)"Sending SSU commands Failed in SCSI STOP ADAPTER ",param_2);
      }
    }
    StorPortStallExecution(500);
    if (bVar3 == 0) {
      return;
    }
  } while( true );
}



===== SendConfigPageMessage @ 140013b00 =====

void SendConfigPageMessage
               (longlong param_1,char param_2,undefined4 *param_3,undefined4 param_4,int param_5,
               int param_6)

{
  uint uVar1;
  char *pcVar2;
  ushort uVar3;
  
  if (param_3 == (undefined4 *)(param_1 + 0x15b0)) {
    pcVar2 = *(char **)(param_1 + 0x330);
    uVar3 = *(ushort *)(param_1 + 0x672);
  }
  else {
    pcVar2 = *(char **)(param_1 + 0x318);
    uVar3 = *(ushort *)(param_1 + 0x66c);
  }
  uVar1 = 0xd3000000;
  pcVar2[0] = '\0';
  pcVar2[1] = '\0';
  pcVar2[2] = '\0';
  pcVar2[3] = '\0';
  pcVar2[4] = '\0';
  pcVar2[5] = '\0';
  pcVar2[6] = '\0';
  pcVar2[7] = '\0';
  pcVar2[8] = '\0';
  pcVar2[9] = '\0';
  pcVar2[10] = '\0';
  pcVar2[0xb] = '\0';
  pcVar2[0xc] = '\0';
  pcVar2[0xd] = '\0';
  pcVar2[0xe] = '\0';
  pcVar2[0xf] = '\0';
  pcVar2[0x10] = '\0';
  pcVar2[0x11] = '\0';
  pcVar2[0x12] = '\0';
  pcVar2[0x13] = '\0';
  pcVar2[0x14] = '\0';
  pcVar2[0x15] = '\0';
  pcVar2[0x16] = '\0';
  pcVar2[0x17] = '\0';
  pcVar2[0x18] = '\0';
  pcVar2[0x19] = '\0';
  pcVar2[0x1a] = '\0';
  pcVar2[0x1b] = '\0';
  pcVar2[0x1c] = '\0';
  pcVar2[0x1d] = '\0';
  pcVar2[0x1e] = '\0';
  pcVar2[0x1f] = '\0';
  pcVar2[0x20] = '\0';
  pcVar2[0x21] = '\0';
  pcVar2[0x22] = '\0';
  pcVar2[0x23] = '\0';
  pcVar2[0x24] = '\0';
  pcVar2[0x25] = '\0';
  pcVar2[0x26] = '\0';
  pcVar2[0x27] = '\0';
  pcVar2[0x28] = '\0';
  pcVar2[0x29] = '\0';
  pcVar2[0x2a] = '\0';
  pcVar2[0x2b] = '\0';
  *pcVar2 = param_2;
  pcVar2[3] = '\x04';
  *(undefined4 *)(pcVar2 + 0x14) = *param_3;
  *(undefined4 *)(pcVar2 + 0x18) = param_4;
  pcVar2[0x1c] = '\0';
  pcVar2[0x1d] = '\0';
  pcVar2[0x1e] = '\0';
  pcVar2[0x1f] = -0x2d;
  if (param_2 == '\0') {
    *(int *)(pcVar2 + 0x20) = *(int *)(param_1 + 0x1fc) + 0x2c;
  }
  else {
    *(int *)(pcVar2 + 0x20) = param_5 - *(int *)(param_1 + 0x100);
    uVar1 = (uint)*(byte *)((longlong)param_3 + 1) << 2 | 0xd3000000;
    *(uint *)(pcVar2 + 0x1c) = uVar1;
  }
  *(undefined4 *)(pcVar2 + 0x24) = *(undefined4 *)(param_1 + 0x1ec);
  if (param_2 == '\x02') {
    *(uint *)(pcVar2 + 0x1c) = uVar1 | 0x4000000;
  }
  QueueRequestDescriptor(param_1,(uint)uVar3 * 0x10000 + 8,0,param_6);
  return;
}



===== SendExtendedConfigPageMessage @ 140013bd0 =====

void SendExtendedConfigPageMessage
               (longlong param_1,char param_2,char *param_3,undefined4 param_4,int param_5,
               int param_6)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  ushort uVar5;
  
  if (param_3 == (char *)(param_1 + 0x15d8)) {
LAB_140013c5f:
    pcVar3 = *(char **)(param_1 + 0x328);
    uVar5 = *(ushort *)(param_1 + 0x670);
    iVar4 = *(int *)(param_1 + 0x204);
  }
  else {
    if (param_3 == (char *)(param_1 + 0x15c0)) {
      cVar1 = *(char *)(param_1 + 0x676);
      if (cVar1 == '\x01') goto LAB_140013c5f;
      if (cVar1 == '\x02') {
        pcVar3 = *(char **)(param_1 + 0x330);
        uVar5 = *(ushort *)(param_1 + 0x672);
        iVar4 = *(int *)(param_1 + 0x208);
        goto LAB_140013c75;
      }
      if (cVar1 == '\x03') {
        pcVar3 = *(char **)(param_1 + 0x338);
        uVar5 = *(ushort *)(param_1 + 0x674);
        iVar4 = *(int *)(param_1 + 0x20c);
        goto LAB_140013c75;
      }
    }
    pcVar3 = *(char **)(param_1 + 0x318);
    uVar5 = *(ushort *)(param_1 + 0x66c);
    iVar4 = *(int *)(param_1 + 0x1fc);
  }
LAB_140013c75:
  *(undefined1 *)(param_1 + 0x676) = 0;
  pcVar3[0] = '\0';
  pcVar3[1] = '\0';
  pcVar3[2] = '\0';
  pcVar3[3] = '\0';
  pcVar3[4] = '\0';
  pcVar3[5] = '\0';
  pcVar3[6] = '\0';
  pcVar3[7] = '\0';
  uVar2 = 0xd3000000;
  pcVar3[8] = '\0';
  pcVar3[9] = '\0';
  pcVar3[10] = '\0';
  pcVar3[0xb] = '\0';
  pcVar3[0xc] = '\0';
  pcVar3[0xd] = '\0';
  pcVar3[0xe] = '\0';
  pcVar3[0xf] = '\0';
  pcVar3[0x10] = '\0';
  pcVar3[0x11] = '\0';
  pcVar3[0x12] = '\0';
  pcVar3[0x13] = '\0';
  pcVar3[0x14] = '\0';
  pcVar3[0x15] = '\0';
  pcVar3[0x16] = '\0';
  pcVar3[0x17] = '\0';
  pcVar3[0x18] = '\0';
  pcVar3[0x19] = '\0';
  pcVar3[0x1a] = '\0';
  pcVar3[0x1b] = '\0';
  pcVar3[0x1c] = '\0';
  pcVar3[0x1d] = '\0';
  pcVar3[0x1e] = '\0';
  pcVar3[0x1f] = '\0';
  pcVar3[0x20] = '\0';
  pcVar3[0x21] = '\0';
  pcVar3[0x22] = '\0';
  pcVar3[0x23] = '\0';
  pcVar3[0x24] = '\0';
  pcVar3[0x25] = '\0';
  pcVar3[0x26] = '\0';
  pcVar3[0x27] = '\0';
  pcVar3[0x28] = '\0';
  pcVar3[0x29] = '\0';
  pcVar3[0x2a] = '\0';
  pcVar3[0x2b] = '\0';
  *pcVar3 = param_2;
  pcVar3[3] = '\x04';
  pcVar3[0x14] = *param_3;
  pcVar3[0x16] = param_3[2];
  pcVar3[0x17] = param_3[3];
  *(undefined2 *)(pcVar3 + 4) = *(undefined2 *)(param_3 + 4);
  pcVar3[6] = param_3[6];
  *(undefined4 *)(pcVar3 + 0x18) = param_4;
  pcVar3[0x1c] = '\0';
  pcVar3[0x1d] = '\0';
  pcVar3[0x1e] = '\0';
  pcVar3[0x1f] = -0x2d;
  if (param_2 == '\0') {
    *(int *)(pcVar3 + 0x20) = iVar4 + 0x2c;
  }
  else {
    *(int *)(pcVar3 + 0x20) = param_5 - *(int *)(param_1 + 0x100);
    uVar2 = (uint)*(ushort *)(param_3 + 4) << 2 | 0xd3000000;
    *(uint *)(pcVar3 + 0x1c) = uVar2;
  }
  *(undefined4 *)(pcVar3 + 0x24) = *(undefined4 *)(param_1 + 0x1ec);
  if ((param_2 - 2U & 0xfd) == 0) {
    *(uint *)(pcVar3 + 0x1c) = uVar2 | 0x4000000;
  }
  if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x800) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x800,pcVar3,0x2c,param_6
               );
  }
  QueueRequestDescriptor(param_1,(uint)uVar5 * 0x10000 + 8,0,param_6);
  return;
}



===== SendIOCInitMessage @ 140013d80 =====

bool SendIOCInitMessage(longlong param_1,int param_2)

{
  undefined4 uVar1;
  bool bVar2;
  bool bVar3;
  ulonglong uVar4;
  longlong local_res8;
  
  uVar1 = *(undefined4 *)(param_1 + 0x1ec);
  *(undefined8 *)(param_1 + 0x680) = 0;
  *(undefined8 *)(param_1 + 0x688) = 0;
  *(undefined8 *)(param_1 + 0x690) = 0;
  bVar2 = false;
  *(undefined8 *)(param_1 + 0x698) = 0;
  *(undefined8 *)(param_1 + 0x6a0) = 0;
  *(undefined8 *)(param_1 + 0x6a8) = 0;
  *(undefined8 *)(param_1 + 0x6b0) = 0;
  *(undefined8 *)(param_1 + 0x6b8) = 0;
  *(undefined8 *)(param_1 + 0x6c0) = 0;
  *(undefined8 *)(param_1 + 0x720) = 0;
  *(undefined8 *)(param_1 + 0x728) = 0;
  *(undefined4 *)(param_1 + 0x730) = 0;
  *(undefined1 *)(param_1 + 0x683) = 2;
  *(undefined1 *)(param_1 + 0x680) = 4;
  *(undefined2 *)(param_1 + 0x68c) = *(undefined2 *)(param_1 + 0x668);
  *(undefined2 *)(param_1 + 0x68e) = 0x3600;
  *(undefined2 *)(param_1 + 0x69a) = *(undefined2 *)(param_1 + 0x2ec);
  *(undefined2 *)(param_1 + 0x69c) = *(undefined2 *)(param_1 + 0x2f0);
  *(undefined2 *)(param_1 + 0x69e) = *(undefined2 *)(param_1 + 0x2ee);
  *(undefined4 *)(param_1 + 0x6a0) = uVar1;
  *(undefined4 *)(param_1 + 0x6a4) = uVar1;
  *(undefined4 *)(param_1 + 0x6a8) = *(undefined4 *)(param_1 + 0x1f8);
  *(undefined4 *)(param_1 + 0x6ac) = uVar1;
  *(undefined4 *)(param_1 + 0x6b0) = *(undefined4 *)(param_1 + 500);
  *(undefined4 *)(param_1 + 0x6b4) = uVar1;
  *(undefined4 *)(param_1 + 0x6b8) = *(undefined4 *)(param_1 + 0x1f0);
  *(undefined4 *)(param_1 + 0x6bc) = uVar1;
  StorPortQuerySystemTime(&local_res8);
  local_res8 = (local_res8 + -0x19db1ded53e8000) / 10000;
  *(longlong *)(param_1 + 0x6c0) = local_res8;
  if (*(char *)(param_1 + 0x12a) != '\0') {
    *(undefined1 *)(param_1 + 0x697) = *(undefined1 *)(param_1 + 299);
  }
  bVar3 = SendMessageViaHandShake(param_1,0,0x12);
  if ((!bVar3) || (uVar4 = ReceiveDataViaHandshake(param_1,10), (char)uVar4 == '\0')) {
    bVar2 = true;
  }
  *(undefined1 *)(param_1 + 0xeba) = 0;
  *(undefined2 *)(param_1 + 0x21c) = 0;
  if (bVar2) {
    LogSystemEvent(param_1,0xad010010,0xc004af02,(byte *)"Handshake of IOC Init message failed",
                   param_2);
  }
  return !bVar2;
}



===== SendIOCTLMessage @ 140013f70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 SendIOCTLMessage(longlong param_1,ushort *param_2,void *param_3,int param_4)

{
  ushort uVar1;
  longlong lVar2;
  int iVar3;
  void *_Src;
  undefined1 uVar4;
  ushort uVar5;
  undefined4 uVar6;
  uint extraout_EAX;
  int iVar7;
  undefined8 uVar8;
  byte bVar9;
  byte bVar10;
  ulonglong uVar11;
  int *piVar12;
  uint uVar13;
  int iVar14;
  short sVar15;
  uint uVar16;
  char cVar17;
  size_t _Size;
  uint *_Dst;
  undefined1 auStackY_108 [32];
  byte local_c8;
  char local_c7;
  uint local_c4;
  ushort local_c0;
  ushort local_be;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  void *local_a8;
  size_t local_a0;
  longlong local_98;
  void *local_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined1 local_80;
  uint local_78;
  undefined1 uStack_74;
  undefined1 uStack_73;
  undefined1 uStack_72;
  undefined1 uStack_71;
  undefined4 uStack_70;
  undefined2 uStack_6c;
  undefined2 uStack_6a;
  undefined6 uStack_68;
  undefined2 uStack_62;
  undefined6 uStack_60;
  undefined2 uStack_5a;
  undefined6 local_58;
  undefined2 uStack_52;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_108;
  local_c0 = *(ushort *)(param_1 + 0x2ea);
  uVar1 = *(ushort *)(param_1 + 0x2e8);
  lVar2 = *(longlong *)((longlong)param_3 + 0x68);
  bVar10 = *(byte *)((longlong)param_2 + 0xb);
  uStack_74 = 0;
  uStack_73 = 0;
  uStack_72 = 0;
  uStack_71 = 0;
  uStack_70 = 0;
  uStack_6c = 0;
  uStack_6a = 0;
  uStack_68 = 0;
  uStack_62 = 0;
  uStack_60 = 0;
  uStack_5a = 0;
  local_58 = 0;
  uStack_52 = 0;
  local_80 = 0;
  local_84 = 0;
  local_bc = 0;
  local_b4 = 0;
  local_b0 = 0;
  local_88 = *(undefined4 *)(*(longlong *)((longlong)param_3 + 0x40) + 0x10);
  local_78 = (uint)bVar10;
  local_c8 = 8;
  if (bVar10 == 0) {
    uVar8 = *(undefined8 *)(param_2 + 0x24);
    uStack_74 = (undefined1)param_2[4];
    uStack_73 = (undefined1)(param_2[4] >> 8);
    uStack_72 = (undefined1)uVar8;
    uStack_71 = (undefined1)((ulonglong)uVar8 >> 8);
    uStack_70 = (undefined4)((ulonglong)uVar8 >> 0x10);
    uStack_6c = (undefined2)((ulonglong)uVar8 >> 0x30);
    uStack_6a = (undefined2)*(undefined8 *)(param_2 + 0x28);
    uStack_68 = (undefined6)((ulonglong)*(undefined8 *)(param_2 + 0x28) >> 0x10);
    uStack_62 = (undefined2)*(undefined8 *)(param_2 + 0x2c);
    uStack_60 = (undefined6)((ulonglong)*(undefined8 *)(param_2 + 0x2c) >> 0x10);
    uStack_5a = (undefined2)*(undefined8 *)(param_2 + 0x30);
    local_58 = (undefined6)((ulonglong)*(undefined8 *)(param_2 + 0x30) >> 0x10);
  }
  else if (bVar10 == 4) {
    uStack_74 = *(undefined1 *)((longlong)param_2 + 0x1f);
    uStack_73 = (undefined1)param_2[0xf];
    uStack_72 = (undefined1)param_2[7];
    uStack_70 = *(undefined4 *)(param_2 + 0x10);
  }
  bVar9 = bVar10;
  local_b8 = param_4;
  local_a8 = param_3;
  local_98 = lVar2;
  local_90 = param_3;
  if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x400001) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x400001,
                (undefined1 *)&local_78,0x28,param_4);
    bVar9 = *(byte *)((longlong)param_2 + 0xb);
  }
  if ((((bVar9 == 0x17) && (*(char *)(param_1 + 0xb348) == '\0')) && ((char)param_2[4] == '\0')) &&
     ((*(uint *)(param_2 + 10) & 0x4000000) != 0)) {
    *(ushort **)(param_1 + 0xb338) = param_2;
    *(void **)(param_1 + 0xb340) = local_a8;
    *(undefined1 *)(param_1 + 0xb348) = 1;
    uVar4 = HandleFWDowngrade(param_1,'\x01',param_4);
    return uVar4;
  }
  uVar5 = *param_2;
  _Size = (ulonglong)param_2[1] * 4;
  uVar16 = (int)_Size + 8;
  if ((short)uVar5 < 0) {
    uVar16 = uVar16 + param_2[3];
  }
  else if ((uVar5 & 1) != 0) {
    uVar16 = uVar16 + *(int *)(param_2 + 2);
  }
  uVar13 = (uint)uVar1;
  if ((short)uVar5 < 0) {
    uVar13 = uVar13 + (*(uint *)(param_2 + 2) & 0xffff);
  }
  else if ((uVar5 & 1) == 0) {
    uVar13 = uVar13 + *(int *)(param_2 + 2);
  }
  local_c4 = uVar13 + 0xff;
  if ((uVar5 & 0x4000) == 0) {
    local_c4 = uVar13;
  }
  if (local_c4 < uVar16) {
    local_c4 = uVar16;
  }
  if (*(uint *)(*(longlong *)((longlong)local_a8 + 0x40) + 0x18) < local_c4) {
    return 0;
  }
  if (*(longlong *)(**(longlong **)(param_1 + 0x5d0) + 8) != 0) {
    if (*(char *)(param_1 + 0x3b8) == '\0') {
      return 0;
    }
    if ((*(uint *)(param_1 + 0x3bc) & 0x40000b) == 0) {
      return 0;
    }
    RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x40000b,
                (undefined1 *)&local_90,0x11,param_4);
    return 0;
  }
  if (bVar10 == 1) {
    if (*(int *)(param_1 + 0x628) != 0) {
      return 0;
    }
    AfdMasterTrigger(param_1,4,param_4);
    local_c8 = 6;
    StorPortPause(param_1,300);
    ResetActive(param_1,5,param_4);
  }
  _Dst = (uint *)(lVar2 + 0x160);
  uVar16 = StorPortGetPhysicalAddress(param_1,local_a8,_Dst,&local_c4);
  local_a0 = _Size;
  memmove(_Dst,param_2 + 4,_Size);
  _Src = local_a8;
  local_be = *(ushort *)(param_1 + 0x66a);
  cVar17 = '\0';
  *(undefined4 *)(param_1 + 0xe50) = 0;
  local_c7 = '\0';
  *(undefined4 *)((ulonglong)local_be * 0x20 + 0x18 + *(longlong *)(param_1 + 0x350)) = 1;
  if (*(char *)(param_1 + 0xeb2) != '\0') {
    uVar11 = 0;
    do {
      if (bVar10 == (&IeeeSglFuncList)[uVar11]) {
        if ((bVar10 != 0x17) || (*(char *)_Dst == '\x06')) {
          cVar17 = '\x01';
          local_c7 = '\x01';
        }
        break;
      }
      bVar9 = (char)uVar11 + 1;
      uVar11 = (ulonglong)bVar9;
    } while (bVar9 < 9);
  }
  uVar5 = *param_2;
  if ((short)uVar5 < 0) {
    uVar8 = StorPortGetPhysicalAddress
                      (param_1,local_a8,param_2 + ((ulonglong)param_2[1] + 2) * 2,&local_c4);
    local_c4 = (uint)param_2[3];
    uVar6 = (undefined4)((ulonglong)uVar8 >> 0x20);
    if (local_c7 == '\0') {
      bVar10 = *(byte *)(param_1 + 0x2f8) & 1;
      sVar15 = bVar10 + 2;
      *(uint *)(local_a0 + (longlong)_Dst) = (bVar10 + 0x2a) * 0x2000000 | local_c4;
      *(int *)(local_a0 + 4 + (longlong)_Dst) = (int)uVar8;
      if (bVar10 != 0) {
        *(undefined4 *)(local_a0 + 8 + (longlong)_Dst) = uVar6;
      }
    }
    else {
      sVar15 = 4;
      *(int *)(local_a0 + (longlong)_Dst) = (int)uVar8;
      *(undefined4 *)(local_a0 + 4 + (longlong)_Dst) = uVar6;
      *(uint *)(local_a0 + 8 + (longlong)_Dst) = local_c4;
      *(undefined4 *)(local_a0 + 0xc + (longlong)_Dst) = 0x40000000;
    }
    param_2[1] = param_2[1] + sVar15;
    _Size = (ulonglong)param_2[1] << 2;
    param_2[3] = 0;
    *param_2 = 0;
    cVar17 = local_c7;
  }
  else {
    if ((uVar5 & 0x4000) != 0) {
      *(undefined1 *)(lVar2 + 0x174) = 0x18;
      uVar13 = 0;
      *(undefined1 *)(lVar2 + 0x167) = 0;
      *(undefined1 *)(lVar2 + 0x172) = 0xff;
      local_b4 = 0xff;
      if ((*param_2 & 1) == 0) {
        uVar13 = *(uint *)(param_2 + 2);
      }
      *(uint *)(lVar2 + 0x16c) = uVar16 - 0x100;
      *(ulonglong *)(param_1 + 0xf28) = (longlong)param_2 + (ulonglong)uVar1 + (ulonglong)uVar13;
      *(uint *)(lVar2 + 0x19c) = *(uint *)(lVar2 + 0x19c) & 0xfffff8ff;
      uVar5 = *param_2 & 0xbfff;
      *param_2 = uVar5;
      if (*(char *)(lVar2 + 0x163) == '\0') {
        local_b0 = (uint)*(ushort *)_Dst << 0x10;
        local_c8 = 0;
      }
    }
    if (uVar5 == 1) {
      iVar14 = 0;
      uVar13 = (param_2[1] + 2) * 4;
      goto LAB_14001437c;
    }
  }
  uVar13 = (uint)uVar1;
  iVar14 = *(int *)(param_2 + 2);
  local_bc = iVar14;
LAB_14001437c:
  iVar3 = local_b8;
  if (*(int *)(param_2 + 2) == 0) {
    iVar7 = uVar16 + (int)_Size;
    piVar12 = (int *)(_Size + (longlong)_Dst);
    if (cVar17 == '\0') {
      *piVar12 = -0x2d000000;
      piVar12[1] = iVar7;
      piVar12[2] = *(int *)(param_1 + 0x1ec);
    }
    else {
      *piVar12 = iVar7;
      piVar12[1] = *(int *)(param_1 + 0x1ec);
      piVar12[2] = 0;
      piVar12[3] = 0x40000000;
    }
  }
  else {
    BuildIoctlScatterGather
              (param_1,(longlong)_Src,_Dst,uVar16,(short *)param_2,uVar13 + (int)param_2,cVar17);
    iVar14 = local_bc;
    local_c4 = extraout_EAX;
    if (local_bc != 0) {
      iVar14 = local_bc - extraout_EAX;
    }
  }
  *(uint *)((longlong)_Src + 0x3c) = (uint)uVar1 + local_b4 + 0x1c + iVar14;
  *(void **)(param_1 + 0xed0) = _Src;
  memmove((void *)(param_1 + 0xee0),_Src,0x40);
  uVar16 = (uint)local_c0;
  *(undefined1 *)(param_1 + 0xec9) = *(undefined1 *)(local_98 + 0x5a);
  memmove(*(void **)(param_1 + 0xf20),_Dst,(ulonglong)uVar16);
  memmove(*(void **)(param_1 + 0x608),_Dst,(ulonglong)uVar16);
  *(undefined1 *)(param_1 + 0xec8) = 1;
  QueueRequestDescriptor(param_1,(uint)local_be * 0x10000 + (uint)local_c8,local_b0,iVar3);
  if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x40000e) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x40000e,
                (undefined1 *)&local_90,0x11,iVar3);
  }
  return 1;
}



===== SendIoUnitCtrlForPuis @ 140014570 =====

undefined8 SendIoUnitCtrlForPuis(longlong param_1,byte param_2,int param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  uint uVar3;
  ushort local_res10 [4];
  
  puVar1 = *(undefined8 **)(param_1 + 0x328);
  local_res10[0] = *(ushort *)(param_1 + 0x670);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  *(undefined4 *)(puVar1 + 5) = 0;
  *(uint *)(puVar1 + 4) = (uint)param_2;
  *(undefined1 *)((longlong)puVar1 + 3) = 0x1b;
  *(undefined1 *)puVar1 = 0xf;
  *(undefined1 *)((longlong)puVar1 + 6) = 0x10;
  *(undefined1 *)(param_1 + 0xb4f1) = 1;
  QueueRequestDescriptor(param_1,(uint)local_res10[0] * 0x10000 + 8,0,param_3);
  uVar3 = 0;
  do {
    uVar2 = PollLSImpiIsr(param_1,param_3);
    if (*(char *)(param_1 + 0xb4f1) == '\0') break;
    uVar2 = StorPortStallExecution(500);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 10000);
  if (uVar3 == 10000) {
    LogSystemEvent(param_1,0xad01007f,0xc004af02,
                   (byte *)"No IO unit control msg reply for PUIS feature activation",param_3);
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x254) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x254,
                  (undefined1 *)local_res10,2,param_3);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
  }
  return uVar2;
}



===== SendLunResetTur @ 1400146b0 =====

void SendLunResetTur(longlong param_1,ushort param_2,int param_3)

{
  longlong lVar1;
  ushort *puVar2;
  byte bVar3;
  undefined4 uVar4;
  undefined1 local_res10 [8];
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x5e8) + 0x68);
  bVar3 = GtfStartTimer(param_1,1,2,LunResetTurTimeout,0,param_3);
  *(byte *)(param_1 + 0x769) = bVar3;
  if (((bVar3 == 0xfe) && (*(char *)(param_1 + 0x3b8) != '\0')) &&
     ((*(uint *)(param_1 + 0x3bc) & 0x233) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x233,(undefined1 *)0x0,0
                ,param_3);
  }
  *(undefined4 *)
   ((ulonglong)*(ushort *)(param_1 + 0x66e) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x350)) = 0x40;
  puVar2 = *(ushort **)(param_1 + 800);
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  *(undefined1 *)(puVar2 + 10) = 0x18;
  *puVar2 = param_2;
  uVar4 = StorPortGetPhysicalAddress
                    (param_1,*(undefined8 *)(param_1 + 0x5e8),lVar1 + 0x60,local_res10);
  *(undefined1 *)(puVar2 + 9) = 0xff;
  *(undefined4 *)(puVar2 + 6) = uVar4;
  puVar2[0x12] = 6;
  BuildZeroLenSGE(param_1,(longlong)puVar2,*(int *)(param_1 + 0x200),'\x01');
  QueueRequestDescriptor
            (param_1,(uint)*(ushort *)(param_1 + 0x66e) << 0x10,(uint)*puVar2 << 0x10,param_3);
  if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x20008) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x20008,
                (undefined1 *)(lVar1 + 0x5a),3,param_3);
  }
  return;
}



===== SendMessageViaHandShake @ 140014830 =====

bool SendMessageViaHandShake(longlong param_1,int param_2,uint param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  undefined4 *puVar6;
  bool bVar7;
  bool bVar8;
  
  uVar3 = 10000;
  if (param_2 == 0) {
    lVar1 = 0x680;
    uVar3 = 10000;
    if (*(char *)(param_1 + 0x683) != '\x04') {
      uVar3 = 60000;
    }
  }
  else {
    lVar1 = 0x6d0;
  }
  puVar6 = (undefined4 *)(lVar1 + param_1);
  **(undefined4 **)(param_1 + 0x48) = 0;
  LOCK();
  UNLOCK();
  **(int **)(param_1 + 0x18) = (param_3 | 0x4200) << 0x10;
  LOCK();
  UNLOCK();
  uVar2 = SymWaitForDoorBell(param_1,uVar3);
  bVar8 = (char)uVar2 == '\0';
  bVar7 = (**(uint **)(param_1 + 0x18) >> 0x1b & 1) == 0;
  bVar5 = bVar7 || bVar8;
  **(undefined4 **)(param_1 + 0x48) = 0;
  LOCK();
  UNLOCK();
  if (!bVar7 && !bVar8) {
    uVar3 = 0;
    do {
      if (**(int **)(param_1 + 0x48) == -1) break;
      if (-1 < **(int **)(param_1 + 0x48)) goto LAB_140014907;
      StorPortStallExecution(500);
      uVar3 = uVar3 + 1;
    } while (uVar3 < 120000);
  }
  bVar5 = true;
LAB_140014907:
  uVar3 = 0;
  if (param_3 != 0) {
    do {
      if (bVar5) {
        return !bVar5;
      }
      **(undefined4 **)(param_1 + 0x18) = *puVar6;
      LOCK();
      UNLOCK();
      uVar4 = 0;
      do {
        if (**(int **)(param_1 + 0x48) == -1) break;
        if (-1 < **(int **)(param_1 + 0x48)) goto LAB_14001494c;
        StorPortStallExecution(500);
        uVar4 = uVar4 + 1;
      } while (uVar4 < 120000);
      bVar5 = true;
LAB_14001494c:
      uVar3 = uVar3 + 1;
      puVar6 = puVar6 + 1;
    } while (uVar3 < param_3);
  }
  return !bVar5;
}



===== SendMpiEventToApplication @ 140014980 =====

void SendMpiEventToApplication(longlong param_1,uint param_2,void *param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  undefined8 *puVar3;
  char cVar4;
  longlong lVar5;
  undefined8 *_Dst;
  
  if (((byte)(param_2 >> 5) < 4) &&
     ((*(uint *)(param_1 + 0xe54 + ((ulonglong)(param_2 >> 5) & 0xff) * 4) >> (param_2 & 0x1f) & 1)
      != 0)) {
    bVar1 = *(byte *)(param_1 + 0xe68);
    lVar5 = (ulonglong)bVar1 * 200;
    *(uint *)(lVar5 + 0x16d8 + param_1) = param_2;
    *(int *)(param_1 + 0xe64) = *(int *)(param_1 + 0xe64) + 1;
    *(undefined4 *)(lVar5 + 0x16dc + param_1) = *(undefined4 *)(param_1 + 0xe64);
    _Dst = (undefined8 *)(lVar5 + 0x16e0 + param_1);
    lVar5 = 3;
    puVar3 = _Dst;
    do {
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[3] = 0;
      puVar3[4] = 0;
      puVar3[5] = 0;
      puVar3[6] = 0;
      puVar3[7] = 0;
      lVar5 = lVar5 + -1;
      puVar3 = puVar3 + 8;
    } while (lVar5 != 0);
    uVar2 = 0xc0;
    if (param_4 < 0xc1) {
      uVar2 = param_4;
    }
    memmove(_Dst,param_3,(ulonglong)uVar2);
    cVar4 = '\0';
    if (bVar1 != 199) {
      cVar4 = bVar1 + 1;
    }
    *(char *)(param_1 + 0xe68) = cVar4;
    if (*(char *)(param_1 + 0x1559) != '\0') {
      ScsiPortWmiFireLogicalUnitEvent
                (param_1,-1,0,0,(int *)&MegaSASWmiMpiEventGuid,0,0x10,(int *)(param_1 + 0x198));
    }
  }
  return;
}



===== SendSEPMessage @ 140014ac0 =====

void SendSEPMessage(longlong param_1,undefined4 param_2,undefined2 param_3,int param_4)

{
  undefined2 *puVar1;
  
  puVar1 = *(undefined2 **)(param_1 + 0x318);
  *(undefined8 *)(puVar1 + 1) = 0;
  *(undefined8 *)(puVar1 + 5) = 0;
  *(undefined8 *)(puVar1 + 9) = 0;
  *(undefined4 *)(puVar1 + 0xd) = 0;
  puVar1[0xf] = 0;
  *(undefined4 *)(puVar1 + 6) = param_2;
  *puVar1 = param_3;
  *(undefined2 *)((longlong)puVar1 + 3) = 0x18;
  QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x66c) * 0x10000 + 8,0,param_4);
  return;
}



===== SendSsuMessage @ 140014b20 =====

ulonglong SendSsuMessage(longlong param_1,ushort param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  int iVar4;
  longlong lVar5;
  ushort *puVar6;
  ushort *puVar7;
  
  lVar2 = **(longlong **)(param_1 + 0x5d0);
  if (*(longlong *)(lVar2 + 8) != 0) {
    return (ulonglong)*(longlong **)(param_1 + 0x5d0) & 0xffffffffffffff00;
  }
  *(uint *)(lVar2 + 0x18) = *(uint *)(lVar2 + 0x18) | 0x10;
  *(ulonglong *)(lVar2 + 8) = (ulonglong)param_2;
  *(longlong *)(param_1 + 0x5d0) = *(longlong *)(param_1 + 0x5d0) + 8;
  *(int *)(param_1 + 0xb318) = *(int *)(param_1 + 0xb318) + 1;
  if (*(longlong *)(param_1 + 0x5d0) == *(longlong *)(param_1 + 0x5e0)) {
    *(undefined8 *)(param_1 + 0x5d0) = *(undefined8 *)(param_1 + 0x5c8);
  }
  iVar1 = *(int *)(param_1 + 0x1f8);
  iVar4 = (uint)*(ushort *)(param_1 + 0x2ea) * (uint)*(ushort *)(lVar2 + 0x10);
  puVar6 = (ushort *)((longlong)iVar4 + *(longlong *)(param_1 + 0x310));
  puVar7 = puVar6;
  for (lVar5 = 0x70; lVar5 != 0; lVar5 = lVar5 + -1) {
    *(undefined1 *)puVar7 = 0;
    puVar7 = (ushort *)((longlong)puVar7 + 1);
  }
  *puVar6 = param_2;
  *(undefined1 *)(puVar6 + 10) = 0x18;
  *(undefined1 *)(puVar6 + 0x20) = 0x1b;
  uVar3 = BuildZeroLenSGE(param_1,(longlong)puVar6,iVar1 + iVar4,'\x01');
  **(int **)(param_1 + 0xe8) = (uint)*(ushort *)(lVar2 + 0x10) << 0x10;
  LOCK();
  UNLOCK();
  **(int **)(param_1 + 0xf0) = (uint)param_2 << 0x10;
  LOCK();
  UNLOCK();
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== SendSsuMessagesToDevices @ 140014c20 =====

void SendSsuMessagesToDevices(longlong param_1)

{
  longlong lVar1;
  ushort uVar2;
  byte bVar3;
  char cVar4;
  undefined8 uVar5;
  ushort uVar6;
  ushort uVar7;
  
  uVar7 = *(ushort *)(param_1 + 0xb322);
  cVar4 = '\x01';
  if (*(uint *)(param_1 + 0x678) <= (uint)uVar7) {
    *(ushort *)(param_1 + 0xb322) = uVar7;
    return;
  }
  do {
    uVar2 = *(ushort *)(*(longlong *)(param_1 + 0x378) + 0x1a + (ulonglong)uVar7 * 0x28);
    lVar1 = *(longlong *)(param_1 + 0x378) + (ulonglong)uVar7 * 0x28;
    if ((((uVar2 != 0) && (*(char *)(lVar1 + 0x23) == '\0')) && (*(char *)(lVar1 + 0x25) != '\0'))
       && ((bVar3 = (byte)*(undefined4 *)(lVar1 + 0x14), (char)bVar3 < '\0' && ((bVar3 & 7) == 1))))
    {
      uVar6 = *(ushort *)(param_1 + 0xb320) & 3;
      if (uVar6 == 1) {
        if (*(char *)(lVar1 + 0x26) != '\0') goto LAB_140014cad;
      }
      else if ((uVar6 != 2) || (*(char *)(lVar1 + 0x26) == '\0')) {
LAB_140014cad:
        uVar5 = SendSsuMessage(param_1,uVar2);
        cVar4 = (char)uVar5;
      }
      if (cVar4 == '\0') break;
    }
    uVar7 = uVar7 + 1;
  } while ((uint)uVar7 < *(uint *)(param_1 + 0x678));
  *(ushort *)(param_1 + 0xb322) = uVar7;
  return;
}



===== SendSsuTmrMessagesToDevices @ 140014d00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SendSsuTmrMessagesToDevices(longlong param_1,int param_2)

{
  int *piVar1;
  ushort uVar2;
  undefined2 uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  undefined1 local_78 [32];
  undefined4 local_38;
  undefined4 local_34;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)local_78;
  plVar6 = *(longlong **)(param_1 + 0x5c8);
  piVar1 = (int *)(param_1 + 0xb318);
  *piVar1 = 0;
  if (plVar6 < *(longlong **)(param_1 + 0x5e0)) {
    do {
      lVar4 = *plVar6;
      if (*(longlong *)(lVar4 + 8) != 0) {
        *(undefined4 *)(lVar4 + 0x18) = 0x20;
        *piVar1 = *piVar1 + 1;
        uVar2 = *(ushort *)(lVar4 + 0x10);
        uVar3 = *(undefined2 *)(lVar4 + 8);
        puVar5 = (undefined8 *)
                 ((longlong)(int)((uint)*(ushort *)(param_1 + 0x2ea) * (uint)uVar2) +
                 *(longlong *)(param_1 + 0x310));
        *puVar5 = 0;
        puVar5[1] = 0;
        puVar5[2] = 0;
        puVar5[3] = 0;
        puVar5[4] = 0;
        puVar5[5] = 0;
        *(undefined4 *)(puVar5 + 6) = 0;
        *(undefined2 *)puVar5 = uVar3;
        *(undefined1 *)((longlong)puVar5 + 3) = 1;
        *(undefined1 *)((longlong)puVar5 + 5) = 3;
        **(int **)(param_1 + 0xe8) = (uint)uVar2 * 0x10000 + 6;
        LOCK();
        UNLOCK();
        **(undefined4 **)(param_1 + 0xf0) = 0;
        LOCK();
        UNLOCK();
        if (((*(char *)(param_1 + 0x139a) != '\0') && (*(char *)(param_1 + 0xb350) != '\0')) &&
           ((*(uint *)(param_1 + 0xb354) & 4) != 0)) {
          local_38 = 1;
          local_34 = 4;
          SendMpiEventToApplication(param_1,0x6e,&local_38,0xc);
        }
      }
      plVar6 = plVar6 + 1;
    } while (plVar6 < *(longlong **)(param_1 + 0x5e0));
  }
  if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x80004) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x80004,
                (undefined1 *)piVar1,4,param_2);
  }
  return;
}



===== SymWaitForDoorBell @ 140014e90 =====

ulonglong SymWaitForDoorBell(longlong param_1,uint param_2)

{
  uint *in_RAX;
  uint uVar1;
  
  uVar1 = 0;
  if (param_2 != 0) {
    do {
      in_RAX = *(uint **)(param_1 + 0x48);
      if (*in_RAX == 0xffffffff) break;
      if ((*in_RAX & 1) != 0) {
        return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
      }
      in_RAX = (uint *)StorPortStallExecution(500);
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_2);
  }
  return (ulonglong)in_RAX & 0xffffffffffffff00;
}



===== SynchronizeHandleOrphanedIoctl @ 140014f00 =====

undefined8 SynchronizeHandleOrphanedIoctl(longlong param_1,int *param_2)

{
  int iVar1;
  ulonglong in_RAX;
  
  iVar1 = *param_2;
  *(undefined1 *)(param_1 + 0xe7f) = 1;
  if (((*(char *)(param_1 + 0xec8) == '\0') && (*(longlong *)(param_1 + 0xed0) == 0)) &&
     (in_RAX = (ulonglong)*(byte *)(param_1 + 0xf5e),
     *(longlong *)(param_1 + 0xf68 + in_RAX * 8) != 0)) {
    in_RAX = CheckIoctlQueue(param_1,iVar1);
    if ((char)in_RAX != '\0') {
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x249) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x249,
                    (undefined1 *)0x0,0,iVar1);
      }
      in_RAX = LogSystemEvent(param_1,0xad010075,0x8004af01,
                              (byte *)"an orphaned ioctl found by watchdog timer on ioctl queue",
                              iVar1);
    }
  }
  *(undefined1 *)(param_1 + 0xe7f) = 0;
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== SynchronizeHandleOrphanedReset @ 140014fd0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 SynchronizeHandleOrphanedReset(longlong param_1,int *param_2)

{
  char *pcVar1;
  int iVar2;
  ulonglong in_RAX;
  
  pcVar1 = (char *)(param_1 + 0xe7f);
  iVar2 = *param_2;
  *pcVar1 = '\x01';
  if (((*(int *)(param_1 + 0x628) == 0) && (*(longlong *)(param_1 + 0x5e8) == 0)) &&
     (in_RAX = (ulonglong)*(byte *)(param_1 + 0xf60),
     *(longlong *)(param_1 + 0x1068 + in_RAX * 8) != 0)) {
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x23a) != 0)) {
      RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x388),0x23a,(undefined1 *)0x0,0,iVar2);
    }
    LogSystemEvent(param_1,0xad010075,0x8004af01,
                   (byte *)"an orphaned reset found by watchdog timer on reset queue",iVar2);
    if (*(char *)(param_1 + 0xe73) != '\0') {
      *(undefined4 *)(param_1 + 0x1524) = _DAT_0000aaaa;
    }
    in_RAX = CheckResetQueue(param_1,iVar2);
  }
  *pcVar1 = '\0';
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== SynchronizeReset @ 1400150b0 =====

void SynchronizeReset(longlong param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  *(undefined1 *)(param_1 + 0xe7f) = 1;
  LSImpiReset(param_1,**(uint **)(param_2 + 2),iVar1);
  *(undefined1 *)(param_1 + 0xe7f) = 0;
  return;
}



===== SynchronizeRestartRecovery @ 1400150e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SynchronizeRestartRecovery(longlong param_1,int *param_2)

{
  char *pcVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong lVar4;
  bool bVar5;
  char cVar6;
  int iVar7;
  undefined8 uVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined1 local_88 [32];
  longlong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)local_88;
  pcVar1 = (char *)(param_1 + 0xe7f);
  iVar2 = *param_2;
  *pcVar1 = '\x01';
  switch(*(undefined1 *)(param_1 + 0xec0)) {
  case 1:
    if (*(int *)(param_1 + 0x63c) == 0) {
      uVar9 = **(uint **)(param_1 + 0x18) & 0xf0000000;
      if (uVar9 != 0x10000000) goto LAB_140015161;
      *(undefined4 *)(param_1 + 0xec0) = 2;
      goto switchD_14001513a_caseD_2;
    }
    break;
  case 2:
switchD_14001513a_caseD_2:
    **(uint **)(param_1 + 0x50) = **(uint **)(param_1 + 0x50) | 0x40000009;
    LOCK();
    UNLOCK();
    CompleteAllSrbs(param_1);
    *(undefined2 *)(param_1 + 0xebc) = 0;
    LsiMpiPartitionMemory(param_1,iVar2);
    bVar5 = SendIOCInitMessage(param_1,iVar2);
    if (bVar5) {
      *(undefined4 *)(param_1 + 0xec0) = 3;
    }
    else {
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x20d) != 0)) {
        uVar10 = 0x20d;
LAB_14001525b:
        RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x388),uVar10,(undefined1 *)(param_1 + 0xe48),4
                    ,iVar2);
      }
LAB_140015286:
      KickStart(param_1,iVar2);
      *(undefined4 *)(param_1 + 0xec0) = 1;
    }
    break;
  case 3:
    uVar9 = **(uint **)(param_1 + 0x18) & 0xf0000000;
    if (uVar9 == 0x20000000) {
      *(undefined1 *)(param_1 + 0xec4) = 0;
      if (*(char *)(param_1 + 0xb328) != '\0') {
        HandleFWDowngrade(param_1,'\0',iVar2);
      }
      *(undefined4 *)(param_1 + 0xec0) = 4;
      goto switchD_14001513a_caseD_4;
    }
    if (uVar9 == 0xf0000000) goto LAB_1400159eb;
    *(short *)(param_1 + 0xebc) = *(short *)(param_1 + 0xebc) + 1;
    if (100 < *(ushort *)(param_1 + 0xebc)) {
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x20c) != 0)) {
        uVar10 = 0x20c;
        goto LAB_1400152f4;
      }
      goto LAB_14001531f;
    }
    break;
  case 4:
switchD_14001513a_caseD_4:
    InitReplyFreeQueue(param_1);
    ReadAndSetSASPages(param_1,iVar2);
    if (*(char *)(param_1 + 0xb4f0) != '\0') {
      SendIoUnitCtrlForPuis(param_1,*(byte *)(param_1 + 0xb4f2),iVar2);
    }
    ProcessDPMPage0(param_1,iVar2);
    EnableDisableEvents(param_1,'\x01',iVar2);
    puVar3 = *(undefined8 **)(param_1 + 800);
    *(undefined2 *)(param_1 + 0xebc) = 0;
    *puVar3 = 0;
    *(undefined4 *)(puVar3 + 1) = 0;
    *(undefined1 *)((longlong)puVar3 + 3) = 6;
    *(undefined1 *)(param_1 + 0xe80) = 1;
    **(int **)(param_1 + 0xe8) = (uint)*(ushort *)(param_1 + 0x66e) * 0x10000 + 8;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0xf0) = 0;
    LOCK();
    UNLOCK();
    *(undefined4 *)(param_1 + 0xec0) = 5;
    break;
  case 5:
    PollLSImpiIsr(param_1,iVar2);
    if (*(char *)(param_1 + 0xe80) == '\0') {
      *(undefined2 *)(param_1 + 0xebc) = 0;
      if (*(short *)(param_1 + 0x626) == 0) {
        *(char *)(param_1 + 0xec4) = *(char *)(param_1 + 0xec4) + '\x01';
        uVar10 = 4;
        if (*(ushort *)(param_1 + 0x656) <= (ushort)*(byte *)(param_1 + 0xec4)) {
          uVar10 = 6;
        }
        *(undefined4 *)(param_1 + 0xec0) = uVar10;
        break;
      }
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x20f) != 0)) {
        uVar10 = 0x20f;
        goto LAB_14001525b;
      }
      goto LAB_140015286;
    }
    *(short *)(param_1 + 0xebc) = *(short *)(param_1 + 0xebc) + 1;
    if ((ushort)((ulonglong)*(uint *)(param_1 + 0x618) / 200) < *(ushort *)(param_1 + 0xebc)) {
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x20e) != 0)) {
        uVar10 = 0x20e;
LAB_1400152f4:
        RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x388),uVar10,(undefined1 *)(param_1 + 0xe48),4
                    ,iVar2);
      }
LAB_14001531f:
      KickStart(param_1,iVar2);
      *(undefined2 *)(param_1 + 0xebc) = 0;
      *(undefined4 *)(param_1 + 0xec0) = 1;
    }
    break;
  case 6:
    if ((*(char *)(param_1 + 0xe84) == '\0') && (*(char *)(param_1 + 0xe85) == '\0')) {
      *(undefined4 *)(param_1 + 0xec0) = 7;
    }
    else {
      do {
        cVar6 = PollLSImpiIsr(param_1,iVar2);
        StorPortStallExecution(500);
      } while (cVar6 != '\0');
      *(short *)(param_1 + 0xebc) = *(short *)(param_1 + 0xebc) + 1;
      if (600 < *(ushort *)(param_1 + 0xebc)) {
        KickStart(param_1,iVar2);
        *(undefined2 *)(param_1 + 0xebc) = 0;
        *(undefined4 *)(param_1 + 0xec0) = 1;
      }
    }
    break;
  case 7:
    InternalLSImpiHWInitialize(param_1,iVar2);
    if (*(char *)(param_1 + 0xe74) != '\0') {
      lVar4 = *(longlong *)(param_1 + 0xed0);
      if (lVar4 != 0) {
        local_3c = *(undefined4 *)(*(longlong *)(lVar4 + 0x40) + 0x14);
        local_40 = *(undefined4 *)(*(longlong *)(lVar4 + 0x40) + 0x10);
        local_38 = 1;
        *(undefined1 *)(lVar4 + 3) = 1;
        local_48 = lVar4;
        StorPortNotification(0,param_1);
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x40001f) != 0))
        {
          RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x388),0x40001f,(undefined1 *)&local_48,0x11,
                      iVar2);
        }
      }
      *(undefined1 *)(param_1 + 0xe74) = 0;
      *(undefined8 *)(param_1 + 0xed0) = 0;
    }
    StorPortResume(param_1);
    StorPortReady(param_1);
    if (((*(short *)(param_1 + 0x666) == 0) && (*(char *)(param_1 + 0xe7c) == '\0')) &&
       (uVar9 = 0, *(short *)(param_1 + 0x660) != 0)) {
      do {
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x40002) != 0)) {
          RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x388),0x40002,(undefined1 *)0x0,0,iVar2);
        }
        StorPortNotification(7,param_1);
        uVar9 = uVar9 + 1;
      } while (uVar9 < *(ushort *)(param_1 + 0x660));
    }
    *(undefined1 *)(param_1 + 0xe7c) = 0;
    *(undefined4 *)(param_1 + 0xec0) = 0;
    if (*(char *)(param_1 + 0xe75) != '\0') {
      HbaFwReloadFsm(param_1,'\x01',0,iVar2);
    }
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x40000) != 0)) {
      RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x388),0x40000,(undefined1 *)0x0,0,iVar2);
    }
    break;
  case 8:
    **(uint **)(param_1 + 0x50) = **(uint **)(param_1 + 0x50) | 0x40000009;
    LOCK();
    UNLOCK();
    *(undefined4 *)(param_1 + 0xb31c) = 100;
    *(undefined4 *)(param_1 + 0xb318) = 0;
    *(undefined2 *)(param_1 + 0xb322) = 0;
LAB_140015715:
    *(undefined4 *)(param_1 + 0xec0) = 9;
    break;
  case 9:
    SendSsuMessagesToDevices(param_1);
    uVar10 = 10;
    if (*(int *)(param_1 + 0xb318) == 0) {
      uVar10 = 0xd;
    }
    *(undefined4 *)(param_1 + 0xec0) = uVar10;
    break;
  case 10:
    uVar8 = ProcessSsuReplies(param_1,iVar2);
    iVar7 = (int)uVar8;
    if (iVar7 == 1) {
      *(undefined2 *)(param_1 + 0xb320) = *(undefined2 *)(param_1 + 0xb324);
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x80002) != 0)) {
        RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x388),0x80002,(undefined1 *)(param_1 + 0xb318)
                    ,4,iVar2);
      }
      *(undefined4 *)(param_1 + 0xec0) = 0xd;
    }
    else {
      if (iVar7 == 2) goto LAB_140015715;
      if (iVar7 == 3) {
        *(undefined4 *)(param_1 + 0xec0) = 0xb;
      }
    }
    break;
  case 0xb:
    SendSsuTmrMessagesToDevices(param_1,iVar2);
    *(undefined4 *)(param_1 + 0xb31c) = 100;
    *(undefined4 *)(param_1 + 0xec0) = 0xc;
    break;
  case 0xc:
    uVar8 = ProcessSsuTmrReplies(param_1,iVar2);
    if ((int)uVar8 - 1U < 2) {
      *(undefined2 *)(param_1 + 0xb320) = *(undefined2 *)(param_1 + 0xb324);
      *(undefined4 *)(param_1 + 0xec0) = 0xd;
    }
    break;
  case 0xd:
    **(uint **)(param_1 + 0x50) = **(uint **)(param_1 + 0x50) | 0x40000009;
    LOCK();
    UNLOCK();
    *(undefined1 *)(param_1 + 0xe7c) = 1;
    FlushAllDPMPage0(param_1,iVar2);
    *(undefined2 *)(param_1 + 0xebc) = 0;
    if ((*(uint *)(param_1 + 0xeb4) & 0x2000) == 0) {
      *(undefined4 *)(param_1 + 0xec0) = 0xf;
      KickStart(param_1,iVar2);
    }
    else {
      **(undefined4 **)(param_1 + 0x18) = 0x40000000;
      LOCK();
      UNLOCK();
      *(undefined4 *)(param_1 + 0xec0) = 0xe;
    }
    break;
  case 0xe:
    if (**(int **)(param_1 + 0x48) < 0) {
      if (**(int **)(param_1 + 0x48) == -1) goto LAB_1400159eb;
      *(short *)(param_1 + 0xebc) = *(short *)(param_1 + 0xebc) + 1;
      if (300 < *(ushort *)(param_1 + 0xebc)) {
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x210) != 0)) {
          RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x388),0x210,(undefined1 *)(param_1 + 0xe48),
                      4,iVar2);
        }
        KickStart(param_1,iVar2);
      }
    }
    *(undefined4 *)(param_1 + 0xec0) = 0xf;
    *(undefined2 *)(param_1 + 0xebc) = 0;
    break;
  case 0xf:
    uVar9 = **(uint **)(param_1 + 0x18) & 0xf0000000;
    if (uVar9 == 0x10000000) {
      *(undefined1 *)(*(longlong *)(param_1 + 0x5e8) + 3) = 1;
      StorPortNotification(0,param_1);
      *(undefined8 *)(param_1 + 0x5e8) = 0;
      *(undefined4 *)(param_1 + 0xec0) = 0;
    }
    else {
LAB_140015161:
      if (uVar9 == 0xf0000000) {
LAB_1400159eb:
        iVar7 = 0;
        *(undefined4 *)(param_1 + 0xec0) = 0;
        *(undefined1 *)(param_1 + 0xeba) = 0;
        goto LAB_140015977;
      }
      *(short *)(param_1 + 0xebc) = *(short *)(param_1 + 0xebc) + 1;
      if (300 < *(ushort *)(param_1 + 0xebc)) {
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x20b) != 0)) {
          RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x388),0x20b,(undefined1 *)(param_1 + 0xe48),
                      4,iVar2);
        }
        KickStart(param_1,iVar2);
        *(undefined2 *)(param_1 + 0xebc) = 0;
      }
    }
  }
  iVar7 = *(int *)(param_1 + 0xec0);
LAB_140015977:
  uVar10 = 100000;
  if (iVar7 == 0) {
    uVar10 = 1000000;
  }
  if (*(int *)(param_1 + 0x63c) != 0) {
    iVar7 = *(int *)(param_1 + 0x63c) + -1;
    uVar10 = 1000000;
    *(int *)(param_1 + 0x63c) = iVar7;
    if (iVar7 == 0) {
      KickStart(param_1,iVar2);
    }
  }
  *(undefined1 *)(param_1 + 0xeb9) = 0;
  uVar8 = StorPortNotification(6,param_1,WatchdogTimer,uVar10);
  *pcVar1 = '\0';
  return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
}



===== UarStuckAtsTimerCallback @ 140015a40 =====

longlong UarStuckAtsTimerCallback
                   (longlong param_1,undefined8 param_2,undefined4 *param_3,int param_4)

{
  uint7 extraout_var;
  
  *param_3 = 3;
  HandleUnitAttenReset
            (param_1,*(ushort *)((longlong)param_3 + 10),(undefined8 *)0x0,
             *(byte *)((longlong)param_3 + 6),*(byte *)((longlong)param_3 + 7),
             *(char *)(param_3 + 2),'\0',param_4);
  return (ulonglong)extraout_var << 8;
}



===== UpdateMissedEnclEntryToDPM @ 140015a80 =====

void UpdateMissedEnclEntryToDPM(longlong param_1,int param_2)

{
  longlong lVar1;
  longlong lVar2;
  short sVar3;
  ushort uVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  
  if ((*(byte *)(param_1 + 0x1568) & 0xe) == 2) {
    puVar5 = *(undefined4 **)(param_1 + 0x358);
    uVar7 = 0;
    if (*(char *)(param_1 + 0x1574) != '\0') {
      do {
        if ((((*(byte *)(param_1 + 0x1568) & 1) == 0) && (*(ushort *)(puVar5 + 4) != 0xffff)) &&
           (*(char *)(puVar5 + 7) != '\0')) {
          lVar1 = *(longlong *)(param_1 + 0x15c8) + (ulonglong)*(ushort *)(puVar5 + 4) * 0x14;
          *(undefined4 *)(lVar1 + 8) = *puVar5;
          *(undefined4 *)(lVar1 + 0xc) = puVar5[1];
          lVar2 = *(longlong *)(param_1 + 0x378) + (ulonglong)(uint)puVar5[2] * 0x28;
          sVar3 = *(short *)(lVar2 + 0x1c) * 0x80;
          *(short *)(lVar1 + 0x12) = sVar3;
          *(short *)(lVar1 + 0x12) = *(short *)(lVar2 + 0x1e) + sVar3;
          sVar3 = *(short *)(puVar5 + 5);
          *(short *)(lVar1 + 0x10) = sVar3 << 4;
          *(ushort *)(lVar1 + 0x10) = (ushort)*(byte *)(puVar5 + 6) | sVar3 << 4;
          *(undefined4 *)(lVar1 + 0x14) = puVar5[3];
          *(undefined4 *)(lVar1 + 0x18) = 0;
          **(undefined8 **)(param_1 + 0x15d0) = 0;
          memmove((void *)(*(longlong *)(param_1 + 0x15d0) + 8),(void *)(lVar1 + 8),0x14);
          uVar4 = *(ushort *)(puVar5 + 4);
          *(undefined1 *)(param_1 + 0x676) = 1;
          *(undefined1 *)(param_1 + 0xe88) = 1;
          SendExtendedConfigPageMessage
                    (param_1,'\x04',(char *)(param_1 + 0x15c0),uVar4 | 0x10000,
                     (int)*(undefined8 *)(param_1 + 0x15d0),param_2);
          uVar6 = 0;
          do {
            PollLSImpiIsr(param_1,param_2);
            if (*(char *)(param_1 + 0xe88) == '\0') goto LAB_140015c33;
            StorPortStallExecution(500);
            uVar6 = uVar6 + 1;
          } while (uVar6 < 120000);
          if (*(char *)(param_1 + 0xe88) != '\0') {
            LogSystemEvent(param_1,0xad01004b,0xc004af02,
                           (byte *)"Start-of-Day Check Failed (UpdateMissedEnclEntryToDPM)",param_2)
            ;
          }
LAB_140015c33:
          *(undefined1 *)(puVar5 + 7) = 0;
        }
        uVar7 = uVar7 + 1;
        puVar5 = puVar5 + 9;
      } while (uVar7 < *(byte *)(param_1 + 0x1574));
    }
  }
  return;
}



===== WatchdogTimer @ 140015c80 =====

void WatchdogTimer(longlong param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  code *pcVar4;
  uint uVar5;
  byte bVar6;
  undefined4 uVar7;
  undefined4 local_18 [2];
  undefined8 local_10;
  
  local_18[0] = 8;
  if (*(int *)(param_1 + 0xec0) != 0) {
    local_10 = 0;
    StorPortSynchronizeAccess(param_1,SynchronizeRestartRecovery,local_18);
    return;
  }
  if (((*(int *)(param_1 + 0x628) == 0) && (*(longlong *)(param_1 + 0x5e8) == 0)) &&
     (*(longlong *)(param_1 + 0x1068 + (ulonglong)*(byte *)(param_1 + 0xf60) * 8) != 0)) {
    StorPortSynchronizeAccess(param_1,SynchronizeHandleOrphanedReset,local_18);
  }
  if (((*(char *)(param_1 + 0xec8) == '\0') && (*(longlong *)(param_1 + 0xed0) == 0)) &&
     (*(longlong *)(param_1 + 0xf68 + (ulonglong)*(byte *)(param_1 + 0xf5e) * 8) != 0)) {
    StorPortSynchronizeAccess(param_1,SynchronizeHandleOrphanedIoctl,local_18);
  }
  if ((*(char *)(param_1 + 0xe7c) != '\0') || (*(char *)(param_1 + 0xeba) != '\0'))
  goto LAB_140015e00;
  if ((*(int *)(param_1 + 0x638) == 0) ||
     (iVar3 = *(int *)(param_1 + 0x638) + -1, *(int *)(param_1 + 0x638) = iVar3, iVar3 != 0)) {
    if (*(int *)(param_1 + 0x67c) != 0) {
      local_10 = 0;
      StorPortSynchronizeAccess(param_1,ProcessSynchronousAction,local_18);
      *(undefined1 *)(param_1 + 0xeb9) = 0;
      goto LAB_140015e00;
    }
    if (*(int *)(param_1 + 0x3d0) != 0) {
      local_10 = 0;
      StorPortSynchronizeAccess(param_1,GtfProcessTimers,local_18);
    }
    if ((*(char *)(param_1 + 0xec8) != '\0') && (*(int *)(param_1 + 0xf34) != -0x21524111)) {
      uVar5 = *(int *)(param_1 + 0xf34) + 1;
      *(uint *)(param_1 + 0xf34) = uVar5;
      if ((*(longlong *)(param_1 + 0xed0) != 0) &&
         (*(int *)(*(longlong *)(param_1 + 0xed0) + 0x28) + 2U <= uVar5)) {
        LogSystemEvent(param_1,0xad010030,0x8004af01,(byte *)"An Ioctl timed out",8);
        *(undefined4 *)(param_1 + 0xf34) = 0xdeadbeef;
        StorPortPause(param_1,300);
        pcVar4 = HandleIoctlTimeout;
        goto LAB_140016185;
      }
    }
    if ((*(int *)(param_1 + 0x634) == 0) ||
       (iVar3 = *(int *)(param_1 + 0x634) + -1, *(int *)(param_1 + 0x634) = iVar3, iVar3 != 0)) {
LAB_140015fb6:
      if (((*(int *)(param_1 + 0xe90) != 0) && (*(char *)(param_1 + 0xb328) == '\0')) &&
         (cVar2 = IsHbaFwDowngradeInProgress(param_1), cVar2 == '\0')) {
        piVar1 = (int *)(param_1 + 0xe90);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          FlushDPMPage0Entry(param_1,8);
        }
      }
      if (**(uint **)(param_1 + 0x18) == 0xffffffff) {
        *(undefined1 *)(param_1 + 0xe79) = 1;
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x234) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x234,
                      (undefined1 *)0x0,0,8);
        }
        CompleteAllSrbs(param_1);
        bVar6 = 0;
        if (*(short *)(param_1 + 0x660) == 0) {
          return;
        }
        do {
          StorPortNotification(7,param_1,bVar6);
          bVar6 = bVar6 + 1;
        } while ((ushort)bVar6 < *(ushort *)(param_1 + 0x660));
        return;
      }
      uVar5 = **(uint **)(param_1 + 0x18) & 0xf0000000;
      if (uVar5 == 0x20000000) {
LAB_140015e00:
        if (*(char *)(param_1 + 0xeb9) == '\0') {
          StorPortNotification(6,param_1,WatchdogTimer,1000000);
          return;
        }
        if (*(char *)(param_1 + 0x3b8) == '\0') {
          return;
        }
        if ((*(uint *)(param_1 + 0x3bc) & 0x20a) == 0) {
          return;
        }
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x20a,
                    (undefined1 *)(param_1 + 0xe48),4,8);
        return;
      }
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x208) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x208,
                    (undefined1 *)0x0,0,8);
      }
      **(uint **)(param_1 + 0x50) = **(uint **)(param_1 + 0x50) | 0x40000009;
      LOCK();
      UNLOCK();
      *(undefined4 *)(param_1 + 0xec0) = 1;
      if (*(int *)(param_1 + 0x630) == 0) {
        StorPortPause(param_1,400);
      }
      if (uVar5 == 0x40000000) {
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x209) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x209,
                      (undefined1 *)(param_1 + 0xe48),4,8);
        }
        if (*(char *)(param_1 + 0xe6a) != '\0') {
          *(undefined4 *)(param_1 + 0xec0) = 8;
        }
        goto LAB_14001616d;
      }
      goto LAB_140016177;
    }
    if (*(char *)(param_1 + 0xe6a) == '\0') {
      if (*(int *)(param_1 + 0x628) != 0) {
        LogSystemEvent(param_1,0xad010028,0x8004af01,
                       (byte *)"No reply received from a TM Reset (15 second timeout)",8);
        if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x207) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x207,
                      (undefined1 *)0x0,0,8);
        }
        *(undefined4 *)(param_1 + 0xec0) = 1;
        goto LAB_14001616d;
      }
      goto LAB_140015fb6;
    }
    *(undefined1 *)(param_1 + 0xe6a) = 0;
    uVar7 = 8;
    if (*(short *)(param_1 + 0xb320) == 0) {
      uVar7 = 0xd;
    }
    *(undefined4 *)(param_1 + 0xec0) = uVar7;
  }
  else {
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x206) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x206,(undefined1 *)0x0
                  ,0,8);
    }
    if (*(char *)(param_1 + 0xe75) == '\0') {
      *(undefined1 *)(param_1 + 0xe74) = 1;
    }
    *(undefined4 *)(param_1 + 0xec0) = 1;
LAB_14001616d:
    KickStart(param_1,8);
LAB_140016177:
    *(undefined2 *)(param_1 + 0xebc) = 0;
  }
  pcVar4 = SynchronizeRestartRecovery;
LAB_140016185:
  local_10 = 0;
  StorPortSynchronizeAccess(param_1,pcVar4,local_18);
  return;
}



===== ZeroMemory @ 1400161d0 =====

void ZeroMemory(undefined1 *param_1,uint param_2)

{
  ulonglong uVar1;
  
  if (param_2 != 0) {
    for (uVar1 = (ulonglong)param_2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *param_1 = 0;
      param_1 = param_1 + 1;
    }
  }
  return;
}



===== FillInPortInfo @ 1400161f0 =====

void FillInPortInfo(undefined4 *param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  
  bVar4 = (byte)param_2 & 7;
  uVar1 = 3;
  if (bVar4 == 1) {
    if ((param_2 & 0x660) == 0) {
      if ((param_2 & 0x88) != 0) {
        uVar1 = 0x1f;
      }
    }
    else {
      uVar1 = 0x1e;
    }
  }
  else if (((byte)(bVar4 - 2) < 2) && (uVar1 = 3, (param_2 & 0x110) != 0)) {
    uVar1 = 0x20;
  }
  *param_1 = uVar1;
  param_1[2] = 0x1c;
  ZeroMemory((undefined1 *)(param_1 + 3),0x202);
  *(undefined2 *)(param_1 + 3) = 0x200;
  uVar2 = (uint)((param_2 & 0x440) != 0);
  param_1[0x8c] = param_3;
  uVar3 = uVar2 | 2;
  if ((param_2 & 0x220) == 0) {
    uVar3 = uVar2;
  }
  uVar2 = uVar3 | 4;
  if ((param_2 & 0x110) == 0) {
    uVar2 = uVar3;
  }
  uVar3 = uVar2 | 8;
  if ((param_2 & 0x80) == 0) {
    uVar3 = uVar2;
  }
  param_1[0x86] = uVar3;
  return;
}



===== HbaApiWmiCompletion @ 1400162d0 =====

undefined8 HbaApiWmiCompletion(longlong param_1,longlong param_2,ushort param_3,int param_4)

{
  undefined8 *puVar1;
  byte bVar2;
  undefined2 uVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  longlong lVar10;
  uint *puVar11;
  char cVar12;
  ushort local_res18 [4];
  
  uVar3 = *(undefined2 *)(param_2 + 0xe);
  cVar12 = '\x01';
  lVar10 = (ulonglong)param_3 * 0x20 + *(longlong *)(param_1 + 0x350);
  lVar5 = *(longlong *)(lVar10 + 8);
  local_res18[0] = param_3;
  if (lVar5 == 0) {
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x211) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x211,
                  (undefined1 *)local_res18,2,param_4);
    }
    uVar8 = LogSystemEvent(param_1,0xad010024,0xc004af02,
                           (byte *)"NULL Srb pointer (HbaApiWmiCompletion)",param_4);
    return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
  }
  lVar6 = *(longlong *)(lVar5 + 0x68);
  iVar4 = *(int *)(lVar6 + 0x3c);
  puVar1 = (undefined8 *)(lVar6 + 8);
  *(longlong *)(lVar6 + 0x28) = lVar10;
  bVar2 = *(byte *)(lVar6 + 0x38);
  *(undefined2 *)(lVar6 + 0x3a) = uVar3;
  if (bVar2 == 8) {
    puVar11 = (uint *)*puVar1;
    if (iVar4 != 2) {
      ProcessSASPortInfo(param_1,(int *)puVar11,lVar5);
      uVar7 = 0x1730;
      if (iVar4 == 1) {
        uVar7 = 8;
      }
      goto LAB_140016441;
    }
  }
  else {
    if ((bVar2 < 9) || ((10 < bVar2 && (bVar2 != 0xb)))) {
      uVar7 = 0;
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x212) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x212,
                    (undefined1 *)0x0,0,param_4);
      }
      cVar12 = '\x04';
      goto LAB_140016441;
    }
    puVar11 = (uint *)*puVar1;
  }
  uVar9 = ProcessSASPortAttributes(param_1,puVar11,lVar5,param_4);
  if ((char)uVar9 == '\0') {
    return uVar9 & 0xffffffffffffff00;
  }
  uVar7 = 0x23c;
LAB_140016441:
  ScsiPortWmiPostProcess((longlong)puVar1,cVar12,uVar7);
  *(undefined4 *)(lVar5 + 0x3c) = *(undefined4 *)(lVar6 + 0x24);
  *(undefined1 *)(lVar5 + 3) = *(undefined1 *)(lVar6 + 0x21);
  uVar8 = StorPortNotification(0,param_1,lVar5);
  return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
}



===== LSIWmiGetAdapHbaAttributes @ 140016490 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool LSIWmiGetAdapHbaAttributes(longlong param_1,undefined8 *param_2,longlong param_3,int param_4)

{
  short *psVar1;
  char cVar2;
  short sVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  byte bVar8;
  byte bVar9;
  char *pcVar10;
  ushort uVar11;
  undefined1 auStackY_118 [32];
  byte local_c0 [16];
  byte local_b0 [24];
  byte local_98 [80];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_118;
  lVar4 = *(longlong *)(param_1 + 0x15a8);
  lVar5 = *(longlong *)(param_3 + 0x68);
  uVar6 = *(undefined8 *)(param_1 + 0x151c);
  VersionToStr(*(uint *)(param_1 + 0xe20),(char *)local_b0);
  VersionToStr(*(uint *)(param_1 + 0xe1c),(char *)local_c0);
  *param_2 = uVar6;
  *(undefined4 *)(param_2 + 1) = 0;
  *(int *)(param_2 + 2) = *(int *)(param_1 + 0xe08) * 0x10000 + *(int *)(param_1 + 0xe14);
  *(uint *)((longlong)param_2 + 0xc) = (uint)*(ushort *)(param_1 + 0x656);
  ZeroMemory((undefined1 *)((longlong)param_2 + 0x14),0x82);
  *(undefined2 *)((longlong)param_2 + 0x14) = 0x80;
  uVar11 = 0;
  do {
    if (0x3f < uVar11) break;
    uVar7 = (ulonglong)uVar11;
    uVar11 = uVar11 + 1;
    *(ushort *)((longlong)param_2 + uVar7 * 2 + 0x16) = (ushort)(byte)"Avago Technologies"[uVar7];
  } while ("Avago Technologies"[uVar11] != '\0');
  ZeroMemory((undefined1 *)((longlong)param_2 + 0x96),0x82);
  uVar11 = 0;
  *(undefined2 *)((longlong)param_2 + 0x96) = 0x80;
  cVar2 = *(char *)(lVar4 + 0x3c);
  while ((cVar2 != '\0' && (uVar11 < 0x40))) {
    uVar7 = (ulonglong)uVar11;
    uVar11 = uVar11 + 1;
    *(ushort *)((longlong)param_2 + uVar7 * 2 + 0x98) = (ushort)*(byte *)(uVar7 + 0x3c + lVar4);
    cVar2 = *(char *)((ulonglong)uVar11 + 0x3c + lVar4);
  }
  ZeroMemory((undefined1 *)(param_2 + 0x23),0x202);
  uVar11 = 0;
  *(undefined2 *)(param_2 + 0x23) = 0x200;
  cVar2 = *(char *)(lVar4 + 0x1c);
  while ((cVar2 != '\0' && (uVar11 < 0x100))) {
    uVar7 = (ulonglong)uVar11;
    uVar11 = uVar11 + 1;
    *(ushort *)((longlong)param_2 + uVar7 * 2 + 0x11a) = (ushort)*(byte *)(uVar7 + 0x1c + lVar4);
    cVar2 = *(char *)((ulonglong)uVar11 + 0x1c + lVar4);
  }
  uVar7 = 0x10;
  do {
    bVar8 = (byte)uVar7;
    psVar1 = (short *)((longlong)param_2 + uVar7 * 2 + 0x118);
    sVar3 = *psVar1;
    if (sVar3 == 0x20) {
      *psVar1 = 0;
    }
    else if (sVar3 != 0) break;
    bVar9 = bVar8 - 1;
    uVar7 = (ulonglong)bVar9;
    bVar8 = 0;
  } while (bVar9 != 0);
  if (((uint)ChipIds != *(uint *)(param_1 + 0xe08)) ||
     (pcVar10 = _BoardDesc, _BoardDesc == (char *)0x0)) {
    pcVar10 = NoDesc;
  }
  ZeroMemory((undefined1 *)((longlong)param_2 + 0x31a),0x202);
  *(undefined2 *)((longlong)param_2 + 0x31a) = 0x200;
  uVar11 = 0;
  cVar2 = *pcVar10;
  while ((cVar2 != '\0' && (uVar11 < 0x100))) {
    uVar7 = (ulonglong)uVar11;
    uVar11 = uVar11 + 1;
    *(ushort *)((longlong)param_2 + uVar7 * 2 + 0x31c) = (ushort)(byte)pcVar10[uVar7];
    cVar2 = pcVar10[uVar11];
  }
  local_98[0] = 0x41;
  local_98[1] = 0x76;
  local_98[2] = 0x61;
  local_98[3] = 0x67;
  local_98[4] = 0x6f;
  local_98[5] = 0x20;
  memmove(local_98 + 6,(void *)(lVar4 + 0x1c),(ulonglong)bVar8);
  memmove(local_98 + (byte)(bVar8 + 4),&s__FV,3);
  memmove(local_98 + (byte)(bVar8 + 7),local_c0,0xb);
  memmove(local_98 + (byte)(bVar8 + 0x12),&s__DV,3);
  uVar7 = 0;
  do {
    bVar9 = (&DAT_14001f10c)[uVar7];
    local_98[(uint)(byte)(bVar8 + 0x15) + (int)uVar7] = bVar9;
    if (bVar9 == 0) break;
    bVar9 = (char)uVar7 + 1;
    uVar7 = (ulonglong)bVar9;
  } while (bVar9 < 0x50);
  ZeroMemory((undefined1 *)((longlong)param_2 + 0xf26),0x202);
  uVar11 = 0;
  *(undefined2 *)((longlong)param_2 + 0xf26) = 0x200;
  bVar8 = local_98[0];
  while ((bVar8 != 0 && (uVar11 < 0x100))) {
    uVar7 = (ulonglong)uVar11;
    uVar11 = uVar11 + 1;
    *(ushort *)((longlong)param_2 + uVar7 * 2 + 0xf28) = (ushort)local_98[uVar7];
    bVar8 = local_98[uVar11];
  }
  ZeroMemory((undefined1 *)((longlong)param_2 + 0x51c),0x202);
  uVar11 = 0;
  *(undefined2 *)((longlong)param_2 + 0x51c) = 0x200;
  cVar2 = *(char *)(lVar4 + 0x14);
  while ((cVar2 != '\0' && (uVar11 < 0x100))) {
    uVar7 = (ulonglong)uVar11;
    uVar11 = uVar11 + 1;
    *(ushort *)((longlong)param_2 + uVar7 * 2 + 0x51e) = (ushort)*(byte *)(uVar7 + 0x14 + lVar4);
    cVar2 = *(char *)((ulonglong)uVar11 + 0x14 + lVar4);
  }
  ZeroMemory((undefined1 *)((longlong)param_2 + 0x71e),0x202);
  uVar11 = 0;
  *(undefined2 *)((longlong)param_2 + 0x71e) = 0x200;
  cVar2 = DAT_14001f10c;
  while ((cVar2 != '\0' && (uVar11 < 0x100))) {
    uVar7 = (ulonglong)uVar11;
    uVar11 = uVar11 + 1;
    *(ushort *)((longlong)param_2 + uVar7 * 2 + 0x720) = (ushort)(byte)(&DAT_14001f10c)[uVar7];
    cVar2 = (&DAT_14001f10c)[uVar11];
  }
  ZeroMemory((undefined1 *)(param_2 + 0x124),0x202);
  uVar11 = 0;
  *(undefined2 *)(param_2 + 0x124) = 0x200;
  while ((local_b0[0] != 0 && (uVar11 < 0x100))) {
    uVar7 = (ulonglong)uVar11;
    uVar11 = uVar11 + 1;
    *(ushort *)((longlong)param_2 + uVar7 * 2 + 0x922) = (ushort)local_b0[uVar7];
    local_b0[0] = local_b0[uVar11];
  }
  ZeroMemory((undefined1 *)((longlong)param_2 + 0xb22),0x202);
  uVar11 = 0;
  *(undefined2 *)((longlong)param_2 + 0xb22) = 0x200;
  while ((local_c0[0] != 0 && (uVar11 < 0x100))) {
    uVar7 = (ulonglong)uVar11;
    uVar11 = uVar11 + 1;
    *(ushort *)((longlong)param_2 + uVar7 * 2 + 0xb24) = (ushort)local_c0[uVar7];
    local_c0[0] = local_c0[uVar11];
  }
  ZeroMemory((undefined1 *)((longlong)param_2 + 0xd24),0x202);
  uVar11 = 0;
  *(undefined2 *)((longlong)param_2 + 0xd24) = 0x200;
  do {
    if (0xff < uVar11) break;
    uVar7 = (ulonglong)uVar11;
    uVar11 = uVar11 + 1;
    *(ushort *)((longlong)param_2 + uVar7 * 2 + 0xd26) = (ushort)(byte)"lsi_sas3i"[uVar7];
  } while ("lsi_sas3i"[uVar11] != '\0');
  ZeroMemory((undefined1 *)(param_2 + 0x225),0x202);
  *(undefined2 *)(param_2 + 0x225) = 0x200;
  ZeroMemory((undefined1 *)((longlong)param_2 + 0x132a),0x202);
  *(undefined2 *)((longlong)param_2 + 0x132a) = 0x200;
  ZeroMemory((undefined1 *)((longlong)param_2 + 0x152c),0x202);
  uVar11 = 0;
  *(undefined2 *)((longlong)param_2 + 0x152c) = 0x200;
  cVar2 = MfgDomain[0];
  while ((cVar2 != '\0' && (uVar11 < 0x100))) {
    uVar7 = (ulonglong)uVar11;
    uVar11 = uVar11 + 1;
    *(ushort *)((longlong)param_2 + uVar7 * 2 + 0x152e) = (ushort)(byte)MfgDomain[uVar7];
    cVar2 = MfgDomain[uVar11];
  }
  *(undefined2 *)((longlong)param_2 + 0x152c) = 0x10;
  *(undefined1 *)(lVar5 + 0x38) = 8;
  *(undefined8 **)(lVar5 + 8) = param_2;
  uVar6 = SendHbaApiConfigMessage
                    (param_1,param_3,'\x01',(undefined4 *)(param_1 + 0x163c),0,
                     (int)*(undefined8 *)(param_1 + 0x1668),param_4);
  return (char)uVar6 != '\0';
}



===== LSImpiExecuteWmiMethod @ 140016a70 =====

ulonglong LSImpiExecuteWmiMethod
                    (longlong param_1,longlong *param_2,int param_3,undefined8 param_4,int param_5,
                    uint param_6,uint param_7,int *param_8)

{
  longlong lVar1;
  ulonglong uVar2;
  byte bVar3;
  uint uVar4;
  
  lVar1 = *param_2;
  bVar3 = 1;
  *(int *)(*(longlong *)(lVar1 + 0x68) + 0x3c) = param_5;
  uVar4 = 0;
  if (param_3 != 2) {
    bVar3 = 4;
    goto LAB_140016a9e;
  }
  if (param_5 == 1) {
    uVar4 = 8;
LAB_140016b14:
    if (param_7 < uVar4) {
LAB_140016b1a:
      bVar3 = 0x12;
      goto LAB_140016a9e;
    }
    uVar2 = LsiWmiGetSASPortInfo(param_1,param_8,lVar1,0xe);
  }
  else {
    if (param_5 == 2) {
      uVar4 = 0x23c;
      goto LAB_140016b14;
    }
    if (param_5 != 4) {
      if (param_5 != 10) {
        *param_8 = 2;
        uVar4 = param_6;
      }
      goto LAB_140016a9e;
    }
    uVar4 = 0x23c;
    if (param_7 < 0x23c) goto LAB_140016b1a;
    uVar2 = LsiWmiGetSASPortInfoByWWN(param_1,param_8,lVar1,0xe);
  }
  if ((char)uVar2 != '\0') {
    return uVar2 & 0xffffffffffffff00;
  }
LAB_140016a9e:
  ScsiPortWmiPostProcess((longlong)param_2,bVar3,uVar4);
  return (ulonglong)bVar3;
}



===== LSImpiFunctionControl @ 140016b50 =====

undefined8
LSImpiFunctionControl(longlong param_1,longlong param_2,int param_3,int param_4,char param_5)

{
  undefined8 uVar1;
  
  if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x402) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x402,(undefined1 *)0x0,0
                ,0xf);
  }
  if ((param_4 == 0) && (param_3 == 0)) {
    if (param_5 == '\0') {
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x103) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x103,
                    (undefined1 *)0x0,0,0xf);
      }
      *(undefined1 *)(param_1 + 0x1559) = 0;
    }
    else {
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x102) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x102,
                    (undefined1 *)0x0,0,0xf);
      }
      *(undefined1 *)(param_1 + 0x1559) = 1;
    }
  }
  uVar1 = ScsiPortWmiPostProcess(param_2,'\x01',0);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== LSImpiQueryWmiDataBlock @ 140016c90 =====

ulonglong LSImpiQueryWmiDataBlock
                    (longlong param_1,longlong *param_2,int param_3,undefined8 param_4,
                    undefined8 param_5,undefined4 *param_6,uint param_7,undefined8 *param_8)

{
  longlong lVar1;
  uint uVar2;
  bool bVar3;
  uint7 extraout_var;
  uint uVar4;
  byte bVar5;
  
  uVar4 = 0;
  lVar1 = *param_2;
  bVar5 = 1;
  *(undefined4 *)(*(longlong *)(lVar1 + 0x68) + 0x3c) = 0;
  if (param_3 == 0) {
LAB_140016d02:
    uVar4 = 4;
    uVar2 = 4;
    if (3 < param_7) {
      *param_6 = 4;
      goto LAB_140016d19;
    }
  }
  else {
    if (param_3 != 1) {
      if (param_3 != 2) {
        bVar5 = 4;
        goto LAB_140016d19;
      }
      goto LAB_140016d02;
    }
    uVar4 = 0x1730;
    uVar2 = 0x1730;
    if (0x172f < param_7) {
      *param_6 = 0x1730;
      bVar3 = LSIWmiGetAdapHbaAttributes(param_1,param_8,lVar1,0xb);
      if (bVar3) {
        return (ulonglong)extraout_var << 8;
      }
      goto LAB_140016d19;
    }
  }
  uVar4 = uVar2;
  bVar5 = 0x12;
LAB_140016d19:
  ScsiPortWmiPostProcess((longlong)param_2,bVar5,uVar4);
  return (ulonglong)bVar5;
}



===== LSImpiQueryWmiRegInfo @ 140016d40 =====

char * LSImpiQueryWmiRegInfo(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  *param_3 = L"MofResource";
  return "l msg reply for PUIS feature activation";
}



===== LSImpiWmiInitialize @ 140016d50 =====

void LSImpiWmiInitialize(longlong param_1)

{
  *(undefined4 *)(param_1 + 0x158) = 3;
  *(undefined ***)(param_1 + 0x160) = &LSImpiSasGuidList;
  *(code **)(param_1 + 0x168) = LSImpiQueryWmiRegInfo;
  *(code **)(param_1 + 0x170) = LSImpiQueryWmiDataBlock;
  *(code **)(param_1 + 400) = LSImpiFunctionControl;
  *(code **)(param_1 + 0x188) = LSImpiExecuteWmiMethod;
  *(undefined8 *)(param_1 + 0x180) = 0;
  *(undefined8 *)(param_1 + 0x178) = 0;
  return;
}



===== LSImpiWmiSrb @ 140016dc0 =====

undefined8 LSImpiWmiSrb(longlong param_1,ushort *param_2,int param_3)

{
  longlong lVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  
  lVar1 = *(longlong *)(param_2 + 0x34);
  uVar5 = 0;
  uVar4 = 0;
  piVar7 = (int *)0x0;
  if (*(int *)(param_2 + 0x1c) == 0) {
LAB_140016e79:
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x22f) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x22f,
                  (undefined1 *)param_2,(uint)*param_2,param_3);
    }
    LogSystemEvent(param_1,0xad010056,0xc004af02,
                   (byte *)"ExSRB does not have an expected CDB16 or 32 data block(WMI)",param_3);
    uVar2 = 4;
  }
  else {
    do {
      piVar6 = (int *)((ulonglong)*(uint *)(param_2 + (ulonglong)uVar4 * 2 + 0x3c) +
                      (longlong)param_2);
      if (*piVar6 == 0x60) {
        *(int **)(lVar1 + 0x50) = piVar6;
        piVar7 = piVar6;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(param_2 + 0x1c));
    if (piVar7 == (int *)0x0) goto LAB_140016e79;
    if ((*(byte *)((longlong)piVar7 + 9) & 1) == 0) {
      uVar2 = 1;
    }
    else {
      *(ushort **)(lVar1 + 8) = param_2;
      *(undefined8 *)(lVar1 + 0x28) = 0;
      uVar3 = ScsiPortWmiDispatchFunction
                        ((uint *)(param_1 + 0x158),*(byte *)(piVar7 + 2),param_1,lVar1 + 8,
                         *(ulonglong **)(piVar7 + 4),*(uint *)(param_2 + 0x1e),
                         *(uint **)(param_2 + 0x20));
      if ((char)uVar3 != '\0') goto LAB_140016eee;
      uVar2 = *(undefined1 *)(lVar1 + 0x21);
      uVar5 = *(undefined4 *)(lVar1 + 0x24);
    }
  }
  *(undefined4 *)(param_2 + 0x1e) = uVar5;
  *(undefined1 *)((longlong)param_2 + 3) = uVar2;
  uVar3 = StorPortNotification(0,param_1,param_2);
LAB_140016eee:
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== LsiWmiGetSASPortInfo @ 140016f10 =====

ulonglong LsiWmiGetSASPortInfo(longlong param_1,undefined4 *param_2,longlong param_3,int param_4)

{
  ulonglong uVar1;
  undefined8 uVar2;
  
  uVar1 = *(ulonglong *)(param_3 + 0x68);
  if ((*(int *)(uVar1 + 0x3c) == 2) && ((uint)param_2[1] < 0x1c)) {
    *param_2 = 4;
    return uVar1 & 0xffffffffffffff00;
  }
  *(undefined1 *)(uVar1 + 0x38) = 8;
  *(undefined4 **)(uVar1 + 8) = param_2;
  uVar2 = SendHbaApiConfigMessage
                    (param_1,param_3,'\x01',(undefined4 *)(param_1 + 0x163c),0,
                     (int)*(undefined8 *)(param_1 + 0x1668),param_4);
  if ((char)uVar2 == '\0') {
    *param_2 = 10;
    return uVar2;
  }
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== LsiWmiGetSASPortInfoByWWN @ 140016f90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong LsiWmiGetSASPortInfoByWWN(longlong param_1,int *param_2,longlong param_3,int param_4)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  int iVar5;
  byte bVar6;
  int iVar7;
  undefined4 *puVar8;
  char cVar9;
  byte bVar10;
  undefined1 auStackY_88 [32];
  undefined4 uVar11;
  char local_48 [8];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_88;
  uVar2 = param_2[4];
  lVar3 = *(longlong *)(param_3 + 0x68);
  if (uVar2 < 0x1c) {
    *param_2 = 4;
    local_40 = local_40 & 0xffffffffffffff00;
  }
  else {
    memmove(local_48,param_2,8);
    local_48[7] = local_48[7] & 0xf0;
    bVar6 = 0;
    do {
      if (local_48[7 - (ulonglong)bVar6] != *(char *)((ulonglong)bVar6 + 0x151c + param_1)) break;
      bVar6 = bVar6 + 1;
    } while (bVar6 < 8);
    if ((bVar6 == 8) && (*(char *)(*(longlong *)(param_1 + 0x1668) + 0xc) != '\0')) {
      iVar7 = 0;
      bVar6 = *(byte *)((longlong)param_2 + 7) & 0xf;
      if (bVar6 != 0) {
        cVar9 = '\0';
        bVar10 = 0;
        do {
          cVar1 = *(char *)(*(longlong *)(param_1 + 0x1668) + 0x10 + (ulonglong)bVar10 * 0x14);
          iVar5 = iVar7 + 1;
          if (cVar1 == cVar9) {
            cVar1 = cVar9;
            iVar5 = iVar7;
          }
          iVar7 = iVar5;
          cVar9 = cVar1;
          bVar10 = bVar10 + 1;
        } while (bVar10 <= bVar6);
      }
      *param_2 = iVar7;
      param_2[1] = uVar2;
      *(undefined4 *)(lVar3 + 0x3c) = 2;
      uVar4 = *(ulonglong *)(param_3 + 0x68);
      if ((*(int *)(uVar4 + 0x3c) == 2) && ((uint)param_2[1] < 0x1c)) {
        *param_2 = 4;
        return uVar4 & 0xffffffffffffff00;
      }
      puVar8 = (undefined4 *)(param_1 + 0x163c);
      *(undefined1 *)(uVar4 + 0x38) = 8;
      *(int **)(uVar4 + 8) = param_2;
      iVar7 = (int)*(undefined8 *)(param_1 + 0x1668);
      uVar11 = 0;
    }
    else {
      puVar8 = (undefined4 *)(param_1 + 0x15d8);
      *(undefined1 *)(lVar3 + 0x38) = 0xb;
      *(int **)(lVar3 + 8) = param_2;
      iVar7 = (int)*(undefined8 *)(param_1 + 0x15e0);
      uVar11 = 0xffff;
    }
    local_40 = SendHbaApiConfigMessage(param_1,param_3,'\x01',puVar8,uVar11,iVar7,param_4);
    if ((char)local_40 == '\0') {
      *param_2 = 10;
    }
    else {
      local_40 = CONCAT71((int7)(local_40 >> 8),1);
    }
  }
  return local_40;
}



===== ProcessSASPortAttributes @ 140017150 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 ProcessSASPortAttributes(longlong param_1,uint *param_2,longlong param_3,int param_4)

{
  byte *pbVar1;
  undefined1 uVar2;
  short sVar3;
  int iVar4;
  uint7 uVar7;
  undefined8 uVar5;
  ulonglong uVar6;
  uint uVar8;
  uint *puVar9;
  byte bVar10;
  ulonglong uVar11;
  undefined1 *puVar12;
  longlong lVar13;
  longlong lVar14;
  byte bVar15;
  undefined1 auStackY_288 [32];
  int local_248 [2];
  longlong alStack_240 [63];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_288;
  lVar14 = *(longlong *)(param_3 + 0x68);
  bVar10 = *(byte *)(lVar14 + 0x38);
  sVar3 = *(short *)(lVar14 + 0x3a);
  uVar7 = (uint7)(byte)((ushort)sVar3 >> 8);
  if (bVar10 == 8) {
    lVar13 = *(longlong *)(param_1 + 0x1668);
    uVar8 = *param_2;
    bVar10 = *(byte *)(lVar13 + 0xc);
    if (sVar3 == 0) {
      memset(local_248,0,0x200);
      uVar11 = 0;
      if (bVar10 != 0) {
        do {
          uVar6 = 0;
          pbVar1 = (byte *)(lVar13 + 0x10 + uVar11 * 0x14);
          if ((*(byte *)(lVar13 + 0x11 + uVar11 * 0x14) & 4) != 0) goto LAB_140017433;
          if (*(short *)(pbVar1 + 8) != 0) {
            uVar6 = (ulonglong)*pbVar1;
            local_248[uVar6 * 4] = local_248[uVar6 * 4] + 1;
            if (alStack_240[uVar6 * 2] == 0) {
              alStack_240[uVar6 * 2] = (longlong)pbVar1;
            }
          }
          bVar15 = (char)uVar11 + 1;
          uVar11 = (ulonglong)bVar15;
        } while (bVar15 < bVar10);
      }
      iVar4 = local_248[(ulonglong)uVar8 * 4];
      if (iVar4 == 0) {
        *param_2 = 6;
        return 1;
      }
      lVar13 = alStack_240[(ulonglong)uVar8 * 2];
      switch(*(byte *)(lVar13 + 3) & 0xf) {
      default:
        uVar8 = 6;
        break;
      case 8:
      case 9:
      case 10:
      case 0xb:
        uVar8 = 2;
      }
      param_2[3] = uVar8;
      FillInPortInfo(param_2 + 2,*(uint *)(lVar13 + 4),iVar4);
      *param_2 = (uint)*(ushort *)(lVar13 + 8);
      *(undefined1 *)(lVar14 + 0x38) = 9;
      uVar8 = *(ushort *)(lVar13 + 10) | 0x20000000;
LAB_140017405:
      lVar14 = *(longlong *)(param_1 + 0x15e0);
LAB_14001741a:
      uVar6 = SendHbaApiConfigMessage
                        (param_1,param_3,'\x01',(undefined4 *)(param_1 + 0x15d8),uVar8,(int)lVar14,
                         param_4);
      if ((char)uVar6 != '\0') {
        return uVar6 & 0xffffffffffffff00;
      }
LAB_140017433:
      *param_2 = 10;
      return CONCAT71((int7)(uVar6 >> 8),1);
    }
  }
  else if (8 < bVar10) {
    if (bVar10 < 0xb) {
      lVar13 = *(longlong *)(param_1 + 0x15e0);
      if (bVar10 != 9) {
        *param_2 = 0;
        if (sVar3 == 0x22) {
          uVar5 = ZeroMemory((undefined1 *)(param_2 + 0x8b),8);
          param_2[0x8d] = 0;
          return CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
        }
        if (sVar3 != 0) {
          *param_2 = 1;
          return CONCAT71(uVar7,1);
        }
        puVar9 = param_2 + 0x8b;
        puVar12 = (undefined1 *)(lVar13 + 0x13);
        lVar14 = 8;
        do {
          uVar2 = *puVar12;
          puVar12 = puVar12 + -1;
          *(undefined1 *)puVar9 = uVar2;
          puVar9 = (uint *)((longlong)puVar9 + 1);
          lVar14 = lVar14 + -1;
        } while (lVar14 != 0);
        param_2[0x8d] = 1;
        return 1;
      }
      if (sVar3 == 0) {
        puVar9 = param_2 + 0x89;
        puVar12 = (undefined1 *)(lVar13 + 0x13);
        lVar13 = 8;
        do {
          uVar2 = *puVar12;
          puVar12 = puVar12 + -1;
          *(undefined1 *)puVar9 = uVar2;
          puVar9 = (uint *)((longlong)puVar9 + 1);
          lVar13 = lVar13 + -1;
        } while (lVar13 != 0);
        *(undefined1 *)(lVar14 + 0x38) = 10;
        uVar8 = *param_2 + 0x20000000;
        goto LAB_140017405;
      }
    }
    else if (bVar10 == 0xb) {
      lVar14 = *(longlong *)(param_1 + 0x15e0);
      if (sVar3 == 0x22) {
        *param_2 = 5;
        return 1;
      }
      if (sVar3 == 0) {
        uVar11 = 0;
        do {
          if (*(char *)((lVar14 - uVar11) + 0x13) != *(char *)(uVar11 + (longlong)param_2)) {
            if ((byte)uVar11 < 8) {
              uVar8 = (uint)*(ushort *)(lVar14 + 0x18);
              goto LAB_14001741a;
            }
            break;
          }
          bVar10 = (byte)uVar11 + 1;
          uVar11 = (ulonglong)bVar10;
        } while (bVar10 < 8);
        memmove(param_2 + 0x89,param_2,8);
        FillInPortInfo(param_2 + 2,*(uint *)(lVar14 + 0x1c),1);
        uVar5 = ZeroMemory((undefined1 *)(param_2 + 0x8b),8);
        param_2[0x8d] = 0;
        *param_2 = 0;
        return CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
      }
    }
  }
  *param_2 = 1;
  return CONCAT71(uVar7,1);
}



===== ProcessSASPortInfo @ 1400174a0 =====

void ProcessSASPortInfo(longlong param_1,int *param_2,longlong param_3)

{
  short sVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  byte bVar6;
  uint uVar7;
  byte *pbVar8;
  char cVar9;
  int iVar10;
  char *pcVar11;
  byte bVar12;
  uint uVar13;
  ulonglong uVar14;
  uint uVar15;
  
  uVar15 = 0;
  lVar2 = *(longlong *)(param_1 + 0x1668);
  uVar7 = 0;
  bVar6 = *(byte *)(lVar2 + 0xc);
  sVar1 = *(short *)(*(longlong *)(param_3 + 0x68) + 0x3a);
  if (*(int *)(*(longlong *)(param_3 + 0x68) + 0x3c) == 1) {
    if (sVar1 != 0) {
      *param_2 = 1;
      return;
    }
    uVar14 = 0;
    bVar12 = 0;
    cVar9 = *(char *)(lVar2 + 0x10);
    iVar10 = 0;
    pcVar11 = (char *)(lVar2 + 0x10);
    if (bVar6 != 0) {
      do {
        bVar12 = (byte)uVar14;
        pcVar11 = (char *)(lVar2 + 0x10 + uVar14 * 0x14);
        iVar4 = iVar10 + 1;
        cVar5 = *pcVar11;
        if (*pcVar11 == cVar9) {
          iVar4 = iVar10;
          cVar5 = cVar9;
        }
        cVar9 = cVar5;
        iVar10 = iVar4;
        if (*param_2 == iVar10) break;
        bVar12 = bVar12 + 1;
        uVar14 = (ulonglong)bVar12;
      } while (bVar12 < bVar6);
    }
    if (bVar12 != bVar6) {
      *param_2 = 0;
      iVar10 = 3;
      uVar7 = *(uint *)(pcVar11 + 4);
      bVar6 = (byte)uVar7 & 7;
      if (bVar6 == 1) {
        if ((uVar7 & 0x660) != 0) {
          param_2[1] = 0x1e;
          return;
        }
        if ((uVar7 & 0x88) != 0) {
          param_2[1] = 0x1f;
          return;
        }
      }
      else if (((byte)(bVar6 - 2) < 2) && (iVar10 = 3, (uVar7 & 0x110) != 0)) {
        iVar10 = 0x20;
      }
      param_2[1] = iVar10;
      return;
    }
    *param_2 = 6;
  }
  else if (sVar1 == 0) {
    if (bVar6 != 0) {
      pbVar8 = (byte *)(lVar2 + 0x10);
      uVar14 = (ulonglong)bVar6;
      do {
        bVar6 = *pbVar8;
        pbVar8 = pbVar8 + 0x14;
        uVar7 = uVar7 & 0xff | 1 << (bVar6 & 0x1f);
        uVar14 = uVar14 - 1;
      } while (uVar14 != 0);
    }
    uVar13 = 0;
    do {
      uVar3 = uVar15 + 1;
      if (((uVar7 & 0xff) >> (uVar13 & 0x1f) & 1) == 0) {
        uVar3 = uVar15;
      }
      bVar6 = (char)uVar13 + 1;
      uVar13 = (uint)bVar6;
      uVar15 = uVar3 & 0xff;
    } while (bVar6 < 8);
    param_2[3] = uVar3 & 0xff;
    return;
  }
  return;
}



===== SendHbaApiConfigMessage @ 140017650 =====

ulonglong SendHbaApiConfigMessage
                    (longlong param_1,longlong param_2,char param_3,undefined4 *param_4,
                    undefined4 param_5,int param_6,int param_7)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  longlong *plVar4;
  char *pcVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  
  puVar8 = *(undefined8 **)(*(longlong *)(param_2 + 0x68) + 0x28);
  if (puVar8 == (undefined8 *)0x0) {
    plVar4 = *(longlong **)(param_1 + 0x5d0);
    puVar8 = (undefined8 *)*plVar4;
    if (puVar8[1] != 0) {
      return (ulonglong)plVar4 & 0xffffffffffffff00;
    }
    *(longlong **)(param_1 + 0x5d0) = plVar4 + 1;
    if (plVar4 + 1 == *(longlong **)(param_1 + 0x5e0)) {
      *(undefined8 *)(param_1 + 0x5d0) = *(undefined8 *)(param_1 + 0x5c8);
    }
  }
  pcVar5 = (char *)*puVar8;
  puVar8[1] = param_2;
  uVar1 = *(ushort *)(puVar8 + 2);
  ZeroMemory(pcVar5,0x2c);
  *pcVar5 = param_3;
  pcVar5[3] = '\x04';
  *(undefined4 *)(puVar8 + 3) = 8;
  uVar3 = *param_4;
  *(undefined4 *)(pcVar5 + 0x14) = uVar3;
  uVar6 = (uint)*(byte *)((longlong)param_4 + 1);
  *(undefined4 *)(pcVar5 + 0x18) = param_5;
  if (((byte)((uint)uVar3 >> 0x18) & 0xf) == 0xf) {
    uVar2 = *(ushort *)(param_4 + 1);
    *(ushort *)(pcVar5 + 4) = uVar2;
    uVar6 = (uint)uVar2;
    pcVar5[6] = *(char *)((longlong)param_4 + 6);
  }
  pcVar5[0x1c] = '\0';
  pcVar5[0x1d] = '\0';
  pcVar5[0x1e] = '\0';
  pcVar5[0x1f] = -0x2d;
  *(int *)(pcVar5 + 0x20) = param_6 - *(int *)(param_1 + 0x100);
  *(undefined4 *)(pcVar5 + 0x24) = *(undefined4 *)(param_1 + 0x1ec);
  *(uint *)(pcVar5 + 0x1c) = uVar6 * 4 | 0xd3000000;
  if (param_3 == '\x02') {
    *(uint *)(pcVar5 + 0x1c) = uVar6 * 4 | 0xd7000000;
  }
  uVar7 = QueueRequestDescriptor(param_1,(uint)uVar1 * 0x10000 + 8,0,param_7);
  return CONCAT71((int7)((ulonglong)uVar7 >> 8),1);
}



===== VersionToStr @ 140017790 =====

void VersionToStr(uint param_1,char *param_2)

{
  char cVar1;
  byte bVar2;
  char cVar3;
  
  cVar3 = '0';
  bVar2 = (byte)(param_1 >> 0x18);
  if (bVar2 < 10) {
    cVar1 = '0';
  }
  else {
    cVar1 = (char)((param_1 >> 0x18) / 10) + '0';
  }
  *param_2 = cVar1;
  param_2[1] = bVar2 + (char)((param_1 >> 0x18) / 10) * -10 + '0';
  param_2[2] = '.';
  bVar2 = (byte)(param_1 >> 0x10);
  if (bVar2 < 10) {
    cVar1 = '0';
  }
  else {
    cVar1 = bVar2 / 10 + 0x30;
  }
  param_2[3] = cVar1;
  param_2[4] = bVar2 + (char)((param_1 >> 0x10 & 0xff) / 10) * -10 + '0';
  param_2[5] = '.';
  bVar2 = (byte)(param_1 >> 8);
  if (bVar2 < 10) {
    cVar1 = '0';
  }
  else {
    cVar1 = bVar2 / 10 + 0x30;
  }
  param_2[6] = cVar1;
  param_2[7] = bVar2 + (char)((param_1 >> 8 & 0xff) / 10) * -10 + '0';
  param_2[8] = '.';
  if (9 < (byte)param_1) {
    cVar3 = (char)((param_1 & 0xff) / 10) + '0';
  }
  param_2[9] = cVar3;
  param_2[10] = (byte)param_1 + (char)((param_1 & 0xff) / 10) * -10 + '0';
  param_2[0xb] = '\0';
  return;
}



===== CheckHbaFwReply @ 1400178c0 =====

longlong CheckHbaFwReply(longlong param_1,longlong param_2,int param_3)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  lVar3 = (ulonglong)*(ushort *)(param_2 + 2) * 0x20 + *(longlong *)(param_1 + 0x350);
  uVar1 = *(uint *)(lVar3 + 0x18);
  if ((uVar1 >> 9 & 1) == 0) {
    return (ulonglong)(uint3)(uVar1 >> 8) << 8;
  }
  *(undefined4 *)(lVar3 + 0x18) = 0;
  uVar2 = HbaFwReloadFsm(param_1,'\x01',
                         (ulonglong)*(uint *)(param_2 + 4) + *(longlong *)(param_1 + 0x100),param_3)
  ;
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== HbaFwDownloadTimeoutHandler @ 140017910 =====

undefined1
HbaFwDownloadTimeoutHandler(longlong param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  *(undefined4 *)(param_1 + 0xb4d0) = 0xf;
  HbaFwReloadFsm(param_1,'\x01',0,param_4);
  return 0;
}



===== HbaFwEraseFlashTimeoutHandler @ 140017930 =====

undefined1
HbaFwEraseFlashTimeoutHandler(longlong param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  *(undefined4 *)(param_1 + 0xb4d0) = 0xc;
  HbaFwReloadFsm(param_1,'\x01',0,param_4);
  return 0;
}



===== HbaFwReloadFsm @ 140017950 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void HbaFwReloadFsm(longlong param_1,char param_2,longlong param_3,int param_4)

{
  int *piVar1;
  ushort uVar2;
  undefined4 uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  undefined1 *puVar7;
  byte bVar8;
  int iVar9;
  uint *puVar10;
  longlong lVar11;
  undefined4 uVar12;
  undefined1 auStackY_d8 [32];
  int *piVar13;
  uint uVar14;
  undefined4 local_98 [2];
  longlong local_90;
  undefined1 local_88 [8];
  short local_80 [2];
  undefined4 local_7c;
  int local_78;
  undefined4 local_74;
  int local_70;
  undefined4 local_6c;
  longlong local_60;
  longlong local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined1 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_d8;
  lVar4 = *(longlong *)(param_1 + 0xed0);
  piVar1 = (int *)(param_1 + 0xb4d0);
  lVar5 = *(longlong *)(lVar4 + 0x40);
  lVar6 = *(longlong *)(lVar4 + 0x68);
  local_48 = 0;
  local_4c = 0;
  local_90 = param_3;
  local_60 = lVar5;
  local_58 = lVar4;
  if (param_2 == '\0') {
    if (*piVar1 != 0) {
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x26b) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x26b,
                    (undefined1 *)piVar1,0x20,param_4);
      }
      *(undefined4 *)(lVar4 + 0x3c) = 0x1c;
      local_48 = 1;
      *(undefined1 *)(lVar4 + 3) = 1;
      local_4c = 1;
      local_50 = *(undefined4 *)(lVar5 + 0x10);
      *(undefined4 *)(lVar5 + 0x14) = 1;
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x400025) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x400025,
                    (undefined1 *)&local_58,0x11,param_4);
      }
      StorPortNotification(0,param_1,lVar4);
      *piVar1 = 0;
      *(undefined8 *)(param_1 + 0xed0) = 0;
      return;
    }
    lVar11 = param_3;
    if ((*(uint *)(lVar5 + 0x28) & 1) == 0) {
      *(undefined4 *)(lVar4 + 0x3c) = 0x1c;
      local_48 = 1;
      *(undefined1 *)(lVar4 + 3) = 1;
      local_4c = 2;
      local_50 = *(undefined4 *)(lVar5 + 0x10);
      *(undefined4 *)(lVar5 + 0x14) = 2;
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x40001d) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x40001d,
                    (undefined1 *)&local_58,0x11,param_4);
      }
      StorPortNotification(0,param_1,lVar4);
      *(undefined8 *)(param_1 + 0xed0) = 0;
      return;
    }
  }
  else {
    lVar11 = param_3;
    if ((*(char *)(param_1 + 0x3b8) != '\0') &&
       (lVar11 = param_3, (*(uint *)(param_1 + 0x3bc) & 0x400003) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x400003,
                  (undefined1 *)piVar1,0x20,param_4);
      lVar11 = param_3;
    }
  }
LAB_140017a11:
  switch(*piVar1) {
  case 0:
    iVar9 = *(int *)(lVar5 + 0x24);
    if (iVar9 == 1) {
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x400004) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x400004,
                    (undefined1 *)piVar1,0x20,param_4);
      }
      *piVar1 = 1;
      *(undefined1 *)(param_1 + 0xec8) = 1;
    }
    else if (iVar9 == 2) {
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x400005) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x400005,
                    (undefined1 *)piVar1,0x20,param_4);
      }
      *piVar1 = 2;
      *(undefined1 *)(param_1 + 0xec8) = 1;
    }
    else if (iVar9 == 3) {
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x400006) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x400006,
                    (undefined1 *)piVar1,0x20,param_4);
      }
      *piVar1 = 0x10;
      *(undefined1 *)(param_1 + 0xec8) = 1;
    }
    else {
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 599) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),599,
                    (undefined1 *)(lVar5 + 0x1c),0x18,param_4);
      }
      *(undefined4 *)(lVar4 + 0x3c) = 0x1c;
      *(undefined1 *)(lVar4 + 3) = 1;
      *(undefined4 *)(lVar5 + 0x14) = 3;
      *piVar1 = 0x13;
      *(undefined1 *)(param_1 + 0xec8) = 1;
    }
    goto LAB_140017a11;
  case 1:
    if (0x4b < *(uint *)(lVar5 + 0x18)) {
      *(undefined4 *)(lVar5 + 0x38) = 2;
      *(undefined4 *)(lVar5 + 0x3c) = 0x18;
      *(undefined4 *)(lVar5 + 0x40) = 0xff000101;
      *(undefined4 *)(lVar5 + 0x44) = 0;
      *(undefined4 *)(lVar5 + 0x48) = 4;
      *(undefined4 *)(lVar5 + 0x4c) = 0x100000;
      *(undefined2 *)(lVar5 + 0x50) = 0;
      HexVersionToString(*(uint *)(param_1 + 0xe1c),(char *)(lVar5 + 0x58));
      *(undefined4 *)(lVar5 + 0x52) = 0;
      *(undefined2 *)(lVar5 + 0x56) = 0;
      *(undefined4 *)(lVar4 + 0x3c) = 0x4c;
      *(undefined1 *)(lVar4 + 3) = 1;
      *(undefined4 *)(lVar5 + 0x14) = 0;
      *piVar1 = 0x13;
      goto LAB_140017a11;
    }
    *(undefined4 *)(lVar4 + 0x3c) = 0x1c;
    *(undefined1 *)(lVar4 + 3) = 1;
    *(undefined4 *)(lVar5 + 0x14) = 5;
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x256) != 0)) {
      uVar12 = 0x256;
      uVar14 = 0;
      piVar13 = (int *)0x0;
      goto LAB_1400185f4;
    }
    break;
  case 2:
    if (*(uint *)(lVar4 + 0x28) < 0x3c) {
      *(undefined4 *)(lVar4 + 0x28) = 0x3c;
    }
    if (*(uint *)(lVar5 + 0xc) < 0x3c) {
      *(undefined4 *)(lVar5 + 0xc) = 0x3c;
    }
    puVar10 = (uint *)StorPortGetScatterGatherList(param_1,lVar4);
    *(uint **)(lVar6 + 0x30) = puVar10;
    uVar14 = 0x101;
    if (*(uint *)(param_1 + 0x64c) != 0) {
      uVar14 = *(uint *)(param_1 + 0x64c);
    }
    if (*puVar10 <= uVar14) {
      iVar9 = 3;
      if ((*(uint *)(lVar5 + 0x28) & 4) == 0) {
        iVar9 = 0xd;
      }
      *piVar1 = iVar9;
      goto LAB_140017a11;
    }
    *(undefined4 *)(lVar4 + 0x3c) = 0x1c;
    *(undefined1 *)(lVar4 + 3) = 1;
    *(undefined4 *)(lVar5 + 0x14) = 1;
    local_78 = 0x101;
    if (*(int *)(param_1 + 0x64c) != 0) {
      local_78 = *(int *)(param_1 + 0x64c);
    }
    local_74 = **(undefined4 **)(lVar6 + 0x30);
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x26d) != 0)) {
      piVar13 = &local_78;
      uVar14 = 8;
      uVar12 = 0x26d;
LAB_1400185f4:
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),uVar12,
                  (undefined1 *)piVar13,uVar14,param_4);
    }
    break;
  case 3:
    if ((*(int *)(lVar5 + 0x60) == -0x5aa5055b) ||
       (((*(int *)(lVar5 + 0x60) == -0x5aa5155b && (*(int *)(lVar5 + 100) == 0x5aa55afa)) ||
        (*(int *)(lVar5 + 100) == 0x5aa55aea)))) {
      *(undefined4 *)(param_1 + 0xb4e0) = *(undefined4 *)(lVar5 + 0x70);
      *(undefined4 *)(param_1 + 0xb4e8) = *(undefined4 *)(lVar5 + 0x54);
      *piVar1 = 4;
      goto LAB_140017a11;
    }
    *(undefined4 *)(lVar4 + 0x3c) = 0x1c;
    *(undefined1 *)(lVar4 + 3) = 1;
    *(undefined4 *)(lVar5 + 0x14) = 7;
    local_70 = *(int *)(lVar5 + 0x60);
    local_6c = *(undefined4 *)(lVar5 + 100);
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x264) != 0)) {
      piVar13 = &local_70;
      uVar14 = 8;
      uVar12 = 0x264;
      goto LAB_1400185f4;
    }
    break;
  case 4:
    local_98[0] = 0;
    *(undefined4 *)
     ((ulonglong)*(ushort *)(param_1 + 0x66c) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x350)) =
         0x200;
    SendConfigPageMessage(param_1,'\0',local_98,0,0,param_4);
    *piVar1 = 5;
    return;
  case 5:
    *(undefined4 *)
     ((ulonglong)*(ushort *)(param_1 + 0x66c) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x350)) = 0;
    piVar13 = (int *)(lVar11 + 0xe);
    if (*(short *)piVar13 == 0) {
      local_98[0] = *(undefined4 *)(lVar11 + 0x14);
      *(undefined4 *)
       ((ulonglong)*(ushort *)(param_1 + 0x66c) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x350)) =
           0x200;
      SendConfigPageMessage
                (param_1,'\x01',local_98,0,(int)*(undefined8 *)(param_1 + 0x1508),param_4);
      *piVar1 = 6;
      return;
    }
    *(undefined4 *)(lVar4 + 0x3c) = 0x1c;
    *(undefined1 *)(lVar4 + 3) = 1;
    *(undefined4 *)(lVar5 + 0x14) = 0x10;
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x265) != 0)) {
      uVar12 = 0x265;
      uVar14 = 2;
      goto LAB_1400185f4;
    }
    break;
  case 6:
    *(undefined4 *)
     ((ulonglong)*(ushort *)(param_1 + 0x66c) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x350)) = 0;
    piVar13 = (int *)(lVar11 + 0xe);
    if (*(short *)piVar13 == 0) {
      bVar8 = *(byte *)(*(longlong *)(param_1 + 0x1508) + 0x13);
      if ((*(byte *)(param_1 + 0xb4e3) < bVar8) ||
         ((*(byte *)(param_1 + 0xb4e3) == bVar8 &&
          (*(byte *)(param_1 + 0xb4e2) < *(byte *)(*(longlong *)(param_1 + 0x1508) + 0x12))))) {
        *(undefined1 *)(param_1 + 0xb4e6) = 1;
        *piVar1 = 7;
      }
      else {
        *piVar1 = 0xd;
      }
      goto LAB_140017a11;
    }
    *(undefined4 *)(lVar4 + 0x3c) = 0x1c;
    *(undefined1 *)(lVar4 + 3) = 1;
    *(undefined4 *)(lVar5 + 0x14) = 0x10;
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x266) != 0)) {
      uVar12 = 0x266;
      uVar14 = 2;
      goto LAB_1400185f4;
    }
    break;
  case 7:
    ZeroMemory((undefined1 *)(param_1 + 0x15c0),8);
    *(undefined4 *)(param_1 + 0x15c2) = 0xf00;
    *(undefined1 *)(param_1 + 0x15c6) = 0x17;
    *(undefined1 *)(param_1 + 0x676) = 0;
    *(undefined4 *)
     ((ulonglong)*(ushort *)(param_1 + 0x66c) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x350)) =
         0x200;
    SendExtendedConfigPageMessage(param_1,'\0',(char *)(param_1 + 0x15c0),0,0,param_4);
    *piVar1 = 8;
    return;
  case 8:
    *(undefined4 *)
     ((ulonglong)*(ushort *)(param_1 + 0x66c) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x350)) = 0;
    if ((*(ushort *)(lVar11 + 0xe) & 0x7fff) == 0) {
      *(undefined2 *)(param_1 + 0xb4e4) = *(undefined2 *)(param_1 + 0x15c4);
      *(ushort *)(param_1 + 0x15c4) = (ushort)(*(short *)(param_1 + 0x1564) * 0x14 + 8U) >> 2;
      uVar2 = *(ushort *)(param_1 + 0x1564);
      *(undefined1 *)(param_1 + 0x676) = 0;
      *(undefined4 *)
       ((ulonglong)*(ushort *)(param_1 + 0x66c) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x350)) =
           0x200;
      SendExtendedConfigPageMessage
                (param_1,'\x06',(char *)(param_1 + 0x15c0),(uint)uVar2 << 0x10,
                 (int)*(undefined8 *)(param_1 + 0x15c8),param_4);
      *piVar1 = 9;
      return;
    }
    *(undefined4 *)(lVar4 + 0x3c) = 0x1c;
    *(undefined1 *)(lVar4 + 3) = 1;
    *(undefined4 *)(lVar5 + 0x14) = 0x10;
    LogSystemEvent(param_1,0xad010047,0xc004af02,
                   (byte *)"a read of DPM Page 0 header returned an error (HbaFwReloadFsm)",param_4)
    ;
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x267) != 0)) {
      uVar12 = 0x267;
LAB_1400181cb:
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),uVar12,
                  (undefined1 *)(lVar11 + 0xe),2,param_4);
    }
    goto LAB_1400181f3;
  case 9:
    *(undefined4 *)
     ((ulonglong)*(ushort *)(param_1 + 0x66c) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x350)) = 0;
    *(short *)(param_1 + 0x15c4) = *(short *)(param_1 + 0xb4e4) + 5;
    if ((*(ushort *)(lVar11 + 0xe) & 0x7fff) == 0) {
      *piVar1 = 10;
      lVar11 = local_90;
    }
    else {
      *(undefined4 *)(lVar4 + 0x3c) = 0x1c;
      *(undefined1 *)(lVar4 + 3) = 1;
      *(undefined4 *)(lVar5 + 0x14) = 0x10;
      LogSystemEvent(param_1,0xad010047,0xc004af02,
                     (byte *)"a read of DPM Page 0 returned an error (HbaFwReloadFsm)",param_4);
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x268) != 0)) {
        uVar12 = 0x268;
        goto LAB_1400181cb;
      }
LAB_1400181f3:
      *(undefined1 *)(param_1 + 0xb4e6) = 0;
      *piVar1 = 0x13;
      lVar11 = local_90;
    }
    goto LAB_140017a11;
  case 10:
    puVar7 = *(undefined1 **)(param_1 + 0x608);
    iVar9 = StorPortGetPhysicalAddress(param_1,0,puVar7,local_88);
    ZeroMemory(puVar7,0x10);
    puVar7[3] = 0x17;
    *puVar7 = 0;
    *(undefined4 *)(puVar7 + 0xc) = 0x4000000;
    bVar8 = GtfStartTimer(param_1,1,0x1e,HbaFwEraseFlashTimeoutHandler,0,param_4);
    *(byte *)(param_1 + 0xb4ed) = bVar8;
    if (((bVar8 == 0xfe) && (*(char *)(param_1 + 0x3b8) != '\0')) &&
       ((*(uint *)(param_1 + 0x3bc) & 0x233) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x233,(undefined1 *)0x0
                  ,0,param_4);
    }
    uVar2 = *(ushort *)(param_1 + 0x66a);
    *(undefined4 *)((ulonglong)uVar2 * 0x20 + 0x18 + *(longlong *)(param_1 + 0x350)) = 0x200;
    *(int *)(puVar7 + 0x14) = iVar9 + 0x10;
    *(undefined4 *)(puVar7 + 0x10) = 0xd3000000;
    *(undefined4 *)(puVar7 + 0x18) = *(undefined4 *)(param_1 + 0x1ec);
    QueueRequestDescriptor(param_1,(uint)uVar2 << 0x10 | 8,0,param_4);
    *piVar1 = 0xb;
    return;
  case 0xb:
    *(undefined4 *)
     ((ulonglong)*(ushort *)(param_1 + 0x66a) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x350)) = 0;
    GtfStopTimer(param_1,*(byte *)(param_1 + 0xb4ed),param_4);
    if ((*(ushort *)(lVar11 + 0xe) & 0x7fff) == 0) {
      *(undefined1 *)(param_1 + 0xb4e7) = 1;
      *piVar1 = 0xd;
      lVar11 = local_90;
    }
    else {
      *(undefined4 *)(lVar4 + 0x3c) = 0x1c;
      *(undefined1 *)(lVar4 + 3) = 1;
      *(undefined4 *)(lVar5 + 0x14) = 0x10;
      LogSystemEvent(param_1,0xad01009a,0xc004af02,
                     (byte *)"Error received in MPI ToolBox Clean reply command (HbaFwReloadFsm)",
                     param_4);
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x269) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x269,
                    (undefined1 *)(lVar11 + 0xe),2,param_4);
      }
      *(undefined1 *)(param_1 + 0xb4e6) = 0;
      *(undefined4 *)(param_1 + 0xec0) = 1;
      StorPortPause(param_1);
      *(undefined2 *)(param_1 + 0xebc) = 0;
      LogSystemEvent(param_1,0xad0100a0,0x4004af00,
                     (byte *)
                     "Diag Reset(miniport)-Error received in MPI ToolBox Clean reply during FW update"
                     ,param_4);
      KickStart(param_1,param_4);
      *piVar1 = 0x13;
      lVar11 = local_90;
    }
    goto LAB_140017a11;
  case 0xc:
    *(undefined4 *)
     ((ulonglong)*(ushort *)(param_1 + 0x66a) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x350)) = 0;
    *(undefined1 *)(lVar4 + 3) = 1;
    *(undefined4 *)(lVar5 + 0x14) = 1;
    LogSystemEvent(param_1,0xad01009a,0xc004af02,
                   (byte *)"MPI ToolBox Clean command timed out (HbaFwReloadFsm)",param_4);
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x26a) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x26a,(undefined1 *)0x0
                  ,0,param_4);
    }
    *(undefined4 *)(param_1 + 0xec0) = 1;
    StorPortPause(param_1);
    *(undefined2 *)(param_1 + 0xebc) = 0;
    LogSystemEvent(param_1,0xad0100a0,0x4004af00,
                   (byte *)"Diag Reset(miniport)- MPI ToolBox Clean cmd timed out during FW update",
                   param_4);
    KickStart(param_1,param_4);
    *piVar1 = 0x13;
    goto LAB_140017a11;
  case 0xd:
    if (*(char *)(lVar5 + 0x50) == '\0') {
      iVar9 = StorPortGetPhysicalAddress(param_1,lVar4,lVar6 + 0x160,local_88);
      ZeroMemory((undefined1 *)(lVar6 + 0x160),(uint)*(ushort *)(param_1 + 0x2ea));
      *(undefined1 *)(lVar6 + 0x160) = 1;
      *(undefined1 *)(lVar6 + 0x163) = 9;
      *(undefined4 *)(lVar6 + 0x178) = *(undefined4 *)(lVar5 + 0x40);
      *(undefined4 *)(lVar6 + 0x17c) = *(undefined4 *)(lVar5 + 0x48);
      *(undefined4 *)(lVar6 + 0x16c) = *(undefined4 *)(param_1 + 0xb4e8);
      if ((*(uint *)(lVar5 + 0x28) & 2) != 0) {
        *(undefined1 *)(lVar6 + 0x167) = 1;
        *(undefined4 *)(param_1 + 0xb4e8) = 0;
      }
      uVar12 = *(undefined4 *)(lVar4 + 0x18);
      uVar3 = *(undefined4 *)(lVar4 + 0x3c);
      *(undefined4 *)(lVar4 + 0x18) = 0x80;
      *(undefined4 *)(lVar4 + 0x3c) = *(undefined4 *)(lVar6 + 0x17c);
      BuildIeeeScatterGather(param_1,lVar4,(int)local_60 + 0x58,lVar6 + 0x160,iVar9);
      *(undefined4 *)(lVar4 + 0x18) = uVar12;
      *(undefined4 *)(lVar4 + 0x3c) = uVar3;
      uVar2 = *(ushort *)(param_1 + 0x66a);
      memmove(*(void **)(param_1 + 0x608),(void *)(lVar6 + 0x160),
              (ulonglong)*(ushort *)(param_1 + 0x2ea));
      bVar8 = GtfStartTimer(param_1,1,0x1e,HbaFwDownloadTimeoutHandler,0,param_4);
      *(byte *)(param_1 + 0xb4ec) = bVar8;
      if (((bVar8 == 0xfe) && (*(char *)(param_1 + 0x3b8) != '\0')) &&
         ((*(uint *)(param_1 + 0x3bc) & 0x233) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x233,
                    (undefined1 *)0x0,0,param_4);
      }
      *piVar1 = 0xe;
      *(undefined4 *)((ulonglong)uVar2 * 0x20 + 0x18 + *(longlong *)(param_1 + 0x350)) = 0x200;
      QueueRequestDescriptor(param_1,(uint)uVar2 * 0x10000 + 8,0,param_4);
      return;
    }
    *(undefined4 *)(lVar4 + 0x3c) = 0x1c;
    *(undefined1 *)(lVar4 + 3) = 1;
    *(undefined4 *)(lVar5 + 0x14) = 6;
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x25a) != 0)) {
      uVar12 = 0x25a;
      uVar14 = 0;
      piVar13 = (int *)0x0;
      goto LAB_1400185f4;
    }
    break;
  case 0xe:
    GtfStopTimer(param_1,*(byte *)(param_1 + 0xb4ec),param_4);
    *(undefined4 *)
     ((ulonglong)*(ushort *)(param_1 + 0x66a) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x350)) = 0;
    if ((*(ushort *)(lVar11 + 0xe) & 0x7fff) == 0) {
      *(undefined4 *)(lVar5 + 0x14) = 0;
      *(undefined1 *)(lVar4 + 3) = 1;
      *piVar1 = 0x13;
    }
    else {
      uVar12 = 1;
      if ((*(ushort *)(lVar11 + 0xe) & 0x7fff) == 4) {
        uVar12 = 0x10;
      }
      *(undefined4 *)(lVar5 + 0x14) = uVar12;
      local_80[0] = *(short *)(lVar11 + 0xe);
      local_7c = 0;
      if (local_80[0] < 0) {
        local_7c = *(undefined4 *)(lVar11 + 0x10);
      }
      if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x25b) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x25b,
                    (undefined1 *)local_80,8,param_4);
      }
      LogSystemEvent(param_1,0xad01009b,0xc004af02,
                     (byte *)"HBA FW download Error occured (HbaFwReloadFsm)",param_4);
      *(undefined1 *)(lVar4 + 3) = 1;
      *piVar1 = 0x13;
    }
    goto LAB_140017a11;
  case 0xf:
    *(undefined4 *)
     ((ulonglong)*(ushort *)(param_1 + 0x66a) * 0x20 + 0x18 + *(longlong *)(param_1 + 0x350)) = 0;
    *(undefined4 *)(lVar4 + 0x3c) = 0x1c;
    *(undefined1 *)(lVar4 + 3) = 1;
    *(undefined4 *)(lVar5 + 0x14) = 1;
    LogSystemEvent(param_1,0xad01009b,0xc004af02,
                   (byte *)"Firmware Download Reply Message timed out (HbaFwReloadFsm)",param_4);
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 600) != 0)) {
      piVar13 = (int *)0x0;
      uVar14 = 0;
      uVar12 = 600;
      goto LAB_1400185f4;
    }
    break;
  case 0x10:
    if (*(uint *)(lVar4 + 0x28) < 0x1e) {
      *(undefined4 *)(lVar4 + 0x28) = 0x1e;
    }
    if (*(uint *)(lVar5 + 0xc) < 0x1e) {
      *(undefined4 *)(lVar5 + 0xc) = 0x1e;
    }
    StorPortPause(param_1,400);
    ResetActive(param_1,0x16,param_4);
    EnableDisableEvents(param_1,'\0',param_4);
    *(undefined1 *)(param_1 + 0xe75) = 1;
    *(undefined4 *)(param_1 + 0x638) = 4;
    *piVar1 = 0x11;
    return;
  case 0x11:
    *(undefined1 *)(param_1 + 0xe75) = 0;
    *(undefined4 *)(lVar4 + 0x3c) = 0;
    *(undefined1 *)(lVar4 + 3) = 1;
    *(undefined8 *)(lVar5 + 0x14) = 0;
    ResetActive(param_1,0x40000016,param_4);
    *piVar1 = 0x13 - (uint)(*(char *)(param_1 + 0xb4e7) != '\0');
    goto LAB_140017a11;
  case 0x12:
    goto switchD_140017a29_caseD_12;
  case 0x13:
    *(undefined1 *)(param_1 + 0xec8) = 0;
    *(undefined8 *)(param_1 + 0xed0) = 0;
    CheckIoctlQueue(param_1,param_4);
    local_50 = *(undefined4 *)(lVar5 + 0x10);
    local_4c = *(undefined4 *)(lVar5 + 0x14);
    local_48 = *(undefined1 *)(lVar4 + 3);
    if ((*(char *)(param_1 + 0x3b8) != '\0') && ((*(uint *)(param_1 + 0x3bc) & 0x40001e) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x40001e,
                  (undefined1 *)&local_58,0x11,param_4);
    }
    StorPortNotification(0,param_1,lVar4);
    *piVar1 = 0;
    return;
  default:
    return;
  }
  *piVar1 = 0x13;
  goto LAB_140017a11;
switchD_140017a29_caseD_12:
  FlushAllDPMPage0(param_1,param_4);
  *(undefined2 *)(param_1 + 0xb4e6) = 0;
  UpdateMissedEnclEntryToDPM(param_1,param_4);
  *piVar1 = 0x13;
  goto LAB_140017a11;
}



===== HexVersionToString @ 140018c10 =====

void HexVersionToString(uint param_1,char *param_2)

{
  bool bVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  byte bStackX_a;
  byte local_res10;
  byte bStackX_11;
  
  uVar2 = param_1 >> 0x18;
  bVar1 = 99 < (byte)(param_1 >> 0x18);
  if (bVar1) {
    *param_2 = (char)((ulonglong)uVar2 / 100) + '0';
    uVar2 = uVar2 + (int)((ulonglong)uVar2 / 100) * -100;
    param_2 = param_2 + 1;
  }
  if ((byte)uVar2 < 10) {
    if (bVar1) {
      *param_2 = '0';
      goto LAB_140018c6a;
    }
  }
  else {
    *param_2 = (char)((ulonglong)(uVar2 & 0xff) / 10) + '0';
LAB_140018c6a:
    param_2 = param_2 + 1;
  }
  *param_2 = (byte)uVar2 + (char)((uVar2 & 0xff) / 10) * -10 + '0';
  bStackX_a = (byte)(param_1 >> 0x10);
  param_2[1] = '.';
  pcVar3 = param_2 + 2;
  bVar1 = bStackX_a < 100;
  if (!bVar1) {
    *pcVar3 = bStackX_a / 100 + 0x30;
    bStackX_a = bStackX_a % 100;
    pcVar3 = param_2 + 3;
  }
  if (bStackX_a < 10) {
    if (!bVar1) {
      *pcVar3 = '0';
      goto LAB_140018ce9;
    }
  }
  else {
    *pcVar3 = bStackX_a / 10 + 0x30;
LAB_140018ce9:
    pcVar3 = pcVar3 + 1;
  }
  bStackX_11 = (byte)(param_1 >> 8);
  *pcVar3 = bStackX_a % 10 + 0x30;
  pcVar3[1] = '.';
  pcVar4 = pcVar3 + 2;
  bVar1 = 99 < bStackX_11;
  if (bVar1) {
    *pcVar4 = bStackX_11 / 100 + 0x30;
    bStackX_11 = bStackX_11 % 100;
    pcVar4 = pcVar3 + 3;
  }
  if (bStackX_11 < 10) {
    if (bVar1) {
      *pcVar4 = '0';
      goto LAB_140018d62;
    }
  }
  else {
    *pcVar4 = bStackX_11 / 10 + 0x30;
LAB_140018d62:
    pcVar4 = pcVar4 + 1;
  }
  *pcVar4 = bStackX_11 % 10 + 0x30;
  local_res10 = (byte)param_1;
  pcVar4[1] = '.';
  pcVar3 = pcVar4 + 2;
  bVar1 = local_res10 < 100;
  if (!bVar1) {
    *pcVar3 = local_res10 / 100 + 0x30;
    local_res10 = local_res10 % 100;
    pcVar3 = pcVar4 + 3;
  }
  if (local_res10 < 10) {
    if (bVar1) goto LAB_140018de1;
    *pcVar3 = '0';
  }
  else {
    *pcVar3 = local_res10 / 10 + 0x30;
  }
  pcVar3 = pcVar3 + 1;
LAB_140018de1:
  *pcVar3 = local_res10 % 10 + 0x30;
  pcVar3[1] = '\0';
  return;
}



===== IsHbaFwDowngradeInProgress @ 140018e10 =====

undefined1 IsHbaFwDowngradeInProgress(longlong param_1)

{
  return *(undefined1 *)(param_1 + 0xb4e6);
}



===== RttAddRecord @ 140018e20 =====

void RttAddRecord(longlong param_1,undefined4 *param_2,undefined4 param_3,undefined1 *param_4,
                 uint param_5,undefined4 param_6)

{
  undefined1 uVar1;
  ulonglong uVar2;
  undefined4 *puVar3;
  
  *param_2 = param_3;
  param_2[1] = param_5 + 0x14;
  StorPortQuerySystemTime(param_2 + 2);
  param_2[4] = param_6;
  puVar3 = param_2 + 5;
  if (param_5 != 0) {
    uVar2 = (ulonglong)param_5;
    do {
      uVar1 = *param_4;
      param_4 = param_4 + 1;
      *(undefined1 *)puVar3 = uVar1;
      puVar3 = (undefined4 *)((longlong)puVar3 + 1);
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  *puVar3 = 0;
  puVar3[1] = 8;
  *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
  *(undefined4 **)(param_1 + 0x18) = puVar3;
  return;
}



===== RttInitTrace @ 140018eb0 =====

void RttInitTrace(undefined8 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  *(undefined4 *)((longlong)param_1 + 0x34) = 0x7fbf00;
  param_1[2] = puVar1;
  param_1[3] = puVar1;
  param_1[1] = (longlong)puVar1 + (ulonglong)*(uint *)(param_1 + 5);
  param_1[4] = 0;
  *(undefined4 *)((longlong)param_1 + 0x2c) = 0;
  if (7 < *(uint *)(param_1 + 5)) {
    *puVar1 = 0;
    *(undefined4 *)(param_1[2] + 4) = 8;
  }
  return;
}



===== RttLogEvent @ 140018ef0 =====

void RttLogEvent(undefined8 param_1,char *param_2,int *param_3,undefined4 param_4,
                undefined1 *param_5,uint param_6,int param_7)

{
  int *local_38;
  undefined4 local_30;
  undefined1 *local_28;
  char *local_20;
  uint local_18;
  int local_14;
  
  if ((param_7 == 5) || (*param_2 != '\0')) {
    RttLogEventCore(param_3,param_4,param_5,param_6,param_7);
    return;
  }
  local_28 = param_5;
  local_18 = param_6;
  local_14 = param_7;
  local_38 = param_3;
  local_30 = param_4;
  local_20 = param_2;
  StorPortSynchronizeAccess(param_1,RttLogEventSynchronized,&local_38);
  return;
}



===== RttLogEventCore @ 140018f80 =====

void RttLogEventCore(int *param_1,undefined4 param_2,undefined1 *param_3,uint param_4,
                    undefined4 param_5)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  longlong lVar5;
  ulonglong uVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  uint uVar10;
  
  uVar6 = (ulonglong)param_4;
  uVar10 = param_4 + 0x1c;
  if (uVar10 <= (uint)param_1[10]) {
    puVar4 = *(undefined4 **)(param_1 + 4);
    puVar9 = *(undefined4 **)(param_1 + 6);
    puVar3 = puVar4;
    while (puVar9 < puVar3) {
      do {
        if (uVar10 <= (uint)((int)puVar4 - (int)puVar9)) {
          *puVar9 = param_2;
          puVar9[1] = param_4 + 0x14;
          StorPortQuerySystemTime(puVar9 + 2);
          puVar9[4] = param_5;
          puVar9 = puVar9 + 5;
          if (param_4 != 0) {
            do {
              uVar1 = *param_3;
              param_3 = param_3 + 1;
              *(undefined1 *)puVar9 = uVar1;
              puVar9 = (undefined4 *)((longlong)puVar9 + 1);
              uVar6 = uVar6 - 1;
            } while (uVar6 != 0);
          }
          *puVar9 = 0;
          puVar9[1] = 8;
          param_1[0xb] = param_1[0xb] + 1;
          *(undefined4 **)(param_1 + 6) = puVar9;
          return;
        }
        uVar2 = *(uint *)(*(longlong *)(param_1 + 4) + 4);
        param_1[0xb] = param_1[0xb] + -1;
        piVar8 = (int *)((ulonglong)uVar2 + *(longlong *)(param_1 + 4));
        *(int **)(param_1 + 4) = piVar8;
        puVar4 = (undefined4 *)((ulonglong)piVar8 & 0xffffffff);
      } while (*piVar8 != 1);
      puVar3 = *(undefined4 **)param_1;
      *(undefined4 **)(param_1 + 4) = puVar3;
      puVar4 = (undefined4 *)((ulonglong)puVar3 & 0xffffffff);
    }
    if ((uint)(param_1[2] - (int)puVar9) <= uVar10) {
      *puVar9 = 1;
      *(undefined4 *)(*(longlong *)(param_1 + 6) + 4) = 8;
      if ((uint)(param_1[4] - *param_1) < uVar10) {
        lVar5 = *(longlong *)(param_1 + 4);
        iVar7 = param_1[0xb];
        do {
          iVar7 = iVar7 + -1;
          lVar5 = lVar5 + (ulonglong)*(uint *)(lVar5 + 4);
          param_1[0xb] = iVar7;
          *(longlong *)(param_1 + 4) = lVar5;
        } while ((uint)((int)lVar5 - *param_1) < uVar10);
      }
      puVar9 = *(undefined4 **)param_1;
    }
    RttAddRecord((longlong)param_1,puVar9,param_2,param_3,param_4,param_5);
  }
  return;
}



===== RttLogEventSynchronized @ 1400190d0 =====

undefined8 RttLogEventSynchronized(undefined8 param_1,undefined8 *param_2)

{
  undefined1 *puVar1;
  
  *(undefined1 *)param_2[3] = 1;
  RttLogEventCore((int *)*param_2,*(undefined4 *)(param_2 + 1),(undefined1 *)param_2[2],
                  *(uint *)(param_2 + 4),*(undefined4 *)((longlong)param_2 + 0x24));
  puVar1 = (undefined1 *)param_2[3];
  *puVar1 = 0;
  return CONCAT71((int7)((ulonglong)puVar1 >> 8),1);
}



===== RttSetTraceParameters @ 140019110 =====

void RttSetTraceParameters(longlong param_1,int param_2,int param_3)

{
  if (param_3 == 0) {
    *(undefined1 *)(param_1 + 0x30) = 0;
  }
  else if (param_3 == 1) {
    *(undefined1 *)(param_1 + 0x30) = 1;
  }
  if (param_2 != -1) {
    *(int *)(param_1 + 0x28) = param_2;
  }
  return;
}



===== CallStorPortLogSystemEvent @ 140019130 =====

void CallStorPortLogSystemEvent(longlong param_1,longlong param_2,int param_3)

{
  undefined4 local_res10 [2];
  int local_res20 [2];
  longlong local_68 [2];
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_4c;
  undefined1 local_3c;
  undefined4 local_38;
  undefined4 local_30;
  longlong local_28;
  undefined4 local_20;
  longlong *local_18;
  
  local_res10[0] = 0;
  local_68[0] = 0;
  ZeroMemory((undefined1 *)&local_58,0x48);
  local_38 = *(undefined4 *)(param_2 + 4);
  local_58 = 0x100;
  local_54 = 0x48;
  local_4c = 0;
  local_3c = 0;
  local_30 = 4;
  if (*(char *)(param_2 + 0xfe) != '\0') {
    local_68[0] = param_2 + 8;
    local_20 = 1;
    local_18 = local_68;
  }
  local_28 = param_2;
  local_res20[0] = StorPortExtendedFunction(0x10,param_1,&local_58,local_res10);
  if (((local_res20[0] != 0) && (*(char *)(param_1 + 0x3b8) != '\0')) &&
     ((*(uint *)(param_1 + 0x3bc) & 0x26c) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x26c,
                (undefined1 *)local_res20,4,param_3);
  }
  return;
}



===== InitSysLogErrorFIFO @ 140019250 =====

void InitSysLogErrorFIFO(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0xb4f8);
  *(longlong *)(param_1 + 0xb508) = lVar1;
  *(longlong *)(param_1 + 0xb510) = lVar1;
  *(longlong *)(param_1 + 0xb500) = lVar1 + 0x1400;
  return;
}



===== LSImpiPassiveInitialize @ 140019280 =====

undefined1 LSImpiPassiveInitialize(longlong param_1)

{
  StorPortNotification(0x1001,param_1,param_1 + 0xb520,SystemEventLogger);
  return 1;
}



===== LogSystemEvent @ 1400192b0 =====

void LogSystemEvent(longlong param_1,undefined4 param_2,undefined4 param_3,byte *param_4,int param_5
                   )

{
  undefined4 local_28;
  undefined4 local_24;
  byte *local_20;
  int local_18;
  
  if ((param_5 == 5) || (*(char *)(param_1 + 0xe7f) != '\0')) {
    LogSystemEventInternal(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    ZeroMemory((undefined1 *)&local_28,0x18);
    local_18 = param_5;
    local_28 = param_2;
    local_24 = param_3;
    local_20 = param_4;
    StorPortSynchronizeAccess(param_1,LogSystemEventSynchronized,&local_28);
  }
  return;
}



===== LogSystemEventInternal @ 140019350 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void LogSystemEventInternal
               (longlong param_1,undefined4 param_2,undefined4 param_3,byte *param_4,int param_5)

{
  undefined4 *puVar1;
  ushort uVar2;
  longlong lVar3;
  byte bVar4;
  undefined1 auStack_168 [32];
  undefined8 local_148;
  undefined4 *local_140;
  undefined4 local_138 [4];
  undefined4 local_128;
  undefined4 local_124;
  ushort local_120 [123];
  byte local_2a;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_168;
  if (*(char *)(param_1 + 0xe96) == '\0') {
    ZeroMemory((undefined1 *)&local_128,0x100);
    if (param_4 == (byte *)0x0) {
      local_2a = 0;
    }
    else {
      local_2a = 0;
      local_120[0] = (ushort)*param_4;
      if (local_120[0] != 0) {
        do {
          local_2a = local_2a + 1;
          if (local_2a == 0x48) {
            local_120[local_2a] = 0;
            break;
          }
          bVar4 = param_4[local_2a];
          local_120[local_2a] = (ushort)bVar4;
        } while (bVar4 != 0);
      }
    }
    local_128 = param_2;
    local_124 = param_3;
    CallStorPortLogSystemEvent(param_1,(longlong)&local_128,param_5);
  }
  else {
    puVar1 = *(undefined4 **)(param_1 + 0xb508);
    bVar4 = 0;
    *puVar1 = param_2;
    puVar1[1] = param_3;
    if (param_4 != (byte *)0x0) {
      uVar2 = (ushort)*param_4;
      *(ushort *)(puVar1 + 2) = uVar2;
      while (uVar2 != 0) {
        bVar4 = bVar4 + 1;
        if (bVar4 == 0x48) {
          *(undefined2 *)(puVar1 + 0x26) = 0;
          break;
        }
        uVar2 = (ushort)param_4[bVar4];
        *(ushort *)((longlong)puVar1 + (ulonglong)bVar4 * 2 + 8) = uVar2;
      }
    }
    *(byte *)((longlong)puVar1 + 0xfe) = bVar4;
    lVar3 = *(longlong *)(param_1 + 0xb508) + 0x100;
    *(longlong *)(param_1 + 0xb508) = lVar3;
    if (lVar3 == *(longlong *)(param_1 + 0xb500)) {
      lVar3 = *(longlong *)(param_1 + 0xb4f8);
      *(longlong *)(param_1 + 0xb508) = lVar3;
    }
    if (lVar3 == *(longlong *)(param_1 + 0xb510)) {
      *(undefined1 *)(param_1 + 0xb518) = 1;
    }
    else {
      local_140 = local_138;
      local_138[0] = 0;
      local_148 = 0;
      StorPortNotification(0x1002,param_1,param_1 + 0xb520);
    }
  }
  return;
}



===== LogSystemEventSynchronized @ 140019500 =====

undefined8 LogSystemEventSynchronized(longlong param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  
  *(undefined1 *)(param_1 + 0xe7f) = 1;
  uVar1 = LogSystemEventInternal(param_1,*param_2,param_2[1],*(byte **)(param_2 + 2),param_2[4]);
  *(undefined1 *)(param_1 + 0xe7f) = 0;
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== SystemEventLogger @ 140019540 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SystemEventLogger(undefined8 param_1,longlong param_2)

{
  byte bVar1;
  undefined1 auStackY_198 [32];
  longlong local_150;
  longlong local_148;
  longlong local_140;
  undefined1 local_138 [32];
  undefined4 local_118;
  undefined4 local_114;
  ushort local_110 [123];
  byte local_1a;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_198;
  ZeroMemory(local_138,0x20);
  StorPortExtendedFunction(0x2f,param_2,&local_140,&local_148);
  StorPortNotification(0x1003,param_2,2);
  do {
    if (*(char *)(param_2 + 0xb518) != '\0') {
      ZeroMemory((undefined1 *)&local_118,0x100);
      local_1a = 0;
      local_118 = 0xad010080;
      local_114 = 0x8004af01;
      local_110[0] = 0x53;
      do {
        local_1a = local_1a + 1;
        if (local_1a == 0x48) {
          local_110[local_1a] = 0;
          break;
        }
        bVar1 = "System Log Event dropped"[local_1a];
        local_110[local_1a] = (ushort)bVar1;
      } while (bVar1 != 0);
      CallStorPortLogSystemEvent(param_2,(longlong)&local_118,0x10);
      if ((*(char *)(param_2 + 0x3b8) != '\0') && ((*(uint *)(param_2 + 0x3bc) & 0x114) != 0)) {
        RttLogEvent(param_2,(char *)(param_2 + 0xe7f),(int *)(param_2 + 0x388),0x114,
                    (undefined1 *)0x0,0,0x10);
      }
      *(undefined1 *)(param_2 + 0xb518) = 0;
    }
    if (*(longlong *)(param_2 + 0xb510) == *(longlong *)(param_2 + 0xb508)) goto LAB_14001973a;
    CallStorPortLogSystemEvent(param_2,*(longlong *)(param_2 + 0xb510),0x10);
    *(longlong *)(param_2 + 0xb510) = *(longlong *)(param_2 + 0xb510) + 0x100;
    if (*(longlong *)(param_2 + 0xb510) == *(longlong *)(param_2 + 0xb500)) {
      *(undefined8 *)(param_2 + 0xb510) = *(undefined8 *)(param_2 + 0xb4f8);
    }
    StorPortExtendedFunction(0x2f,param_2,0,&local_150);
  } while (((local_150 - local_148) / local_140) * 1000000 < 100);
  StorPortNotification(0x1002,param_2,param_2 + 0xb520,0);
LAB_14001973a:
  StorPortNotification(0x1004,param_2,local_138);
  return;
}



===== GtfInitialize @ 140019780 =====

void GtfInitialize(longlong param_1)

{
  uint *puVar1;
  byte bVar2;
  byte bVar3;
  longlong lVar4;
  
  puVar1 = (uint *)(param_1 + 0x3d0);
  *puVar1 = 0;
  bVar3 = 0;
  *(undefined8 *)(param_1 + 0x3d8) = 0;
  lVar4 = 0;
  do {
    *(undefined8 *)(lVar4 + 0x10 + (longlong)puVar1) = 0;
    bVar2 = bVar3 & 0x1f;
    bVar3 = bVar3 + 1;
    *(undefined8 *)(lVar4 + 0x18 + (longlong)puVar1) = 0;
    *(undefined8 *)(lVar4 + 0x20 + (longlong)puVar1) = 0;
    lVar4 = lVar4 + 0x18;
    *puVar1 = *puVar1 & ~(1 << bVar2);
  } while (bVar3 < 0x14);
  return;
}



===== GtfProcessTimers @ 1400197d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 GtfProcessTimers(longlong param_1,int *param_2)

{
  undefined1 uVar1;
  int iVar2;
  char cVar3;
  ushort uVar4;
  uint uVar5;
  undefined8 *puVar6;
  byte bVar7;
  ulonglong local_res8;
  
  uVar1 = *(undefined1 *)(param_1 + 0xe7f);
  iVar2 = *param_2;
  *(undefined1 *)(param_1 + 0xe7f) = 1;
  StorPortQuerySystemTime(&local_res8);
  if ((((longlong)local_res8 < *(longlong *)(param_1 + 0x3d8)) &&
      (*(ulonglong *)(param_1 + 0x3d8) = local_res8, *(char *)(param_1 + 0x3b8) != '\0')) &&
     ((*(uint *)(param_1 + 0x3bc) & 0x115) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xe7f),(int *)(param_1 + 0x388),0x115,(undefined1 *)0x0,0
                ,iVar2);
  }
  if (9999999 < (longlong)(local_res8 - *(longlong *)(param_1 + 0x3d8))) {
    puVar6 = (undefined8 *)(param_1 + 1000);
    bVar7 = 0;
    *(ulonglong *)(param_1 + 0x3d8) = local_res8;
    do {
      uVar4 = *(ushort *)((longlong)puVar6 + -2);
      local_res8 = (ulonglong)uVar4;
      if (uVar4 != 0) {
        uVar4 = uVar4 - 1;
        local_res8 = (ulonglong)uVar4;
        *(ushort *)((longlong)puVar6 + -2) = uVar4;
        if (uVar4 == 0) {
          cVar3 = (*(code *)*puVar6)(param_1,bVar7,puVar6[1],iVar2);
          if ((cVar3 == '\0') && (*(int *)(puVar6 + -1) != 2)) {
            puVar6[-1] = 0;
            *puVar6 = 0;
            uVar5 = ~(1 << (bVar7 & 0x1f));
            local_res8 = (ulonglong)uVar5;
            puVar6[1] = 0;
            *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) & uVar5;
          }
          else {
            local_res8 = (ulonglong)*(ushort *)((longlong)puVar6 + -4);
            *(ushort *)((longlong)puVar6 + -2) = *(ushort *)((longlong)puVar6 + -4);
          }
        }
      }
      bVar7 = bVar7 + 1;
      puVar6 = puVar6 + 3;
    } while (bVar7 < 0x14);
  }
  *(undefined1 *)(param_1 + 0xe7f) = uVar1;
  return CONCAT71((int7)(local_res8 >> 8),1);
}



===== GtfStartTimer @ 140019920 =====

byte GtfStartTimer(longlong param_1,undefined4 param_2,undefined2 param_3,undefined8 param_4,
                  undefined8 param_5,int param_6)

{
  longlong lVar1;
  byte bVar2;
  undefined4 local_38;
  undefined2 local_34;
  undefined8 local_30;
  byte local_28;
  undefined8 local_20;
  int local_18;
  
  if ((param_6 != 5) && (*(char *)(param_1 + 0xe7f) == '\0')) {
    local_18 = param_6;
    local_20 = param_5;
    local_28 = 0xfe;
    local_38 = param_2;
    local_34 = param_3;
    local_30 = param_4;
    StorPortSynchronizeAccess(param_1,GtfStartTimerSynchronized,&local_38);
    return local_28;
  }
  bVar2 = 0;
  do {
    if (*(int *)(param_1 + 0x3e0 + (ulonglong)bVar2 * 0x18) == 0) {
      lVar1 = param_1 + (ulonglong)bVar2 * 0x18;
      *(undefined8 *)(lVar1 + 0x3f0) = param_5;
      *(undefined4 *)(lVar1 + 0x3e0) = param_2;
      *(undefined2 *)(lVar1 + 0x3e6) = param_3;
      *(undefined2 *)(lVar1 + 0x3e4) = param_3;
      *(undefined8 *)(lVar1 + 1000) = param_4;
      break;
    }
    bVar2 = bVar2 + 1;
  } while (bVar2 < 0x14);
  if (bVar2 == 0x14) {
    return 0xfe;
  }
  *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) | 1 << (bVar2 & 0x1f);
  return bVar2;
}



===== GtfStartTimerSynchronized @ 140019a10 =====

undefined8 GtfStartTimerSynchronized(longlong param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  byte bVar6;
  
  *(undefined1 *)(param_1 + 0xe7f) = 1;
  uVar2 = *(undefined8 *)(param_2 + 6);
  bVar6 = 0;
  uVar3 = *(undefined8 *)(param_2 + 2);
  uVar1 = *(undefined2 *)(param_2 + 1);
  do {
    uVar5 = (ulonglong)bVar6;
    if (*(int *)(param_1 + 0x3e0 + uVar5 * 0x18) == 0) {
      *(undefined4 *)(param_1 + 0x3e0 + uVar5 * 0x18) = *param_2;
      *(undefined2 *)(param_1 + 0x3e6 + uVar5 * 0x18) = uVar1;
      *(undefined2 *)(param_1 + 0x3e4 + uVar5 * 0x18) = uVar1;
      *(undefined8 *)(param_1 + 1000 + uVar5 * 0x18) = uVar3;
      *(undefined8 *)(param_1 + 0x3f0 + uVar5 * 0x18) = uVar2;
      break;
    }
    bVar6 = bVar6 + 1;
  } while (bVar6 < 0x14);
  uVar5 = uVar5 * 3;
  if (bVar6 == 0x14) {
    bVar6 = 0xfe;
  }
  else {
    uVar4 = 1 << (bVar6 & 0x1f);
    uVar5 = (ulonglong)uVar4;
    *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) | uVar4;
  }
  *(byte *)(param_2 + 4) = bVar6;
  *(undefined1 *)(param_1 + 0xe7f) = 0;
  return CONCAT71((int7)(uVar5 >> 8),1);
}



===== GtfStopTimer @ 140019ab0 =====

void GtfStopTimer(longlong param_1,byte param_2,int param_3)

{
  undefined1 local_38 [16];
  byte local_28;
  int local_18;
  
  if ((param_3 == 5) || (*(char *)(param_1 + 0xe7f) != '\0')) {
    GtfStopTimerCore((uint *)(param_1 + 0x3d0),param_2);
    return;
  }
  local_28 = param_2;
  local_18 = param_3;
  StorPortSynchronizeAccess(param_1,GtfStopTimerSynchronized,local_38);
  return;
}



===== GtfStopTimerCore @ 140019b00 =====

longlong GtfStopTimerCore(uint *param_1,byte param_2)

{
  uint uVar1;
  byte bVar2;
  ulonglong uVar3;
  byte bVar4;
  uint uVar5;
  longlong lVar6;
  
  uVar1 = *param_1;
  if (param_2 == 0xff) {
    if (uVar1 != 0) {
      *param_1 = 0;
      lVar6 = 0;
      bVar4 = 0;
      do {
        *(undefined8 *)(lVar6 + 0x10 + (longlong)param_1) = 0;
        bVar2 = bVar4 & 0x1f;
        bVar4 = bVar4 + 1;
        *(undefined8 *)(lVar6 + 0x18 + (longlong)param_1) = 0;
        *(undefined8 *)(lVar6 + 0x20 + (longlong)param_1) = 0;
        lVar6 = lVar6 + 0x18;
        *param_1 = *param_1 & ~(1 << bVar2);
      } while (bVar4 < 0x14);
      return 0;
    }
  }
  else if ((uVar1 != 0) && (uVar5 = 1 << (param_2 & 0x1f), uVar5 != 0)) {
    uVar3 = (ulonglong)param_2;
    (param_1 + uVar3 * 6 + 4)[0] = 0;
    (param_1 + uVar3 * 6 + 4)[1] = 0;
    (param_1 + uVar3 * 6 + 6)[0] = 0;
    (param_1 + uVar3 * 6 + 6)[1] = 0;
    (param_1 + uVar3 * 6 + 8)[0] = 0;
    (param_1 + uVar3 * 6 + 8)[1] = 0;
    *param_1 = *param_1 & ~uVar5;
    return 1;
  }
  return (ulonglong)(uint3)(uVar1 >> 8) << 8;
}



===== GtfStopTimerSynchronized @ 140019b90 =====

void GtfStopTimerSynchronized(longlong param_1,longlong param_2)

{
  *(undefined1 *)(param_1 + 0xe7f) = 1;
  GtfStopTimerCore((uint *)(param_1 + 0x3d0),*(byte *)(param_2 + 0x10));
  *(undefined1 *)(param_1 + 0xe7f) = 0;
  return;
}



===== __security_check_cookie @ 140019be0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_check_icall @ 140019c00 =====

void _guard_check_icall(void)

{
  return;
}



===== __report_gsfailure @ 140019c10 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __GSHandlerCheck @ 140019c20 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140019c40 =====

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



===== ScsiPortWmiDispatchFunction @ 140019ca0 =====

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



===== ScsiPortWmiFireLogicalUnitEvent @ 140019d40 =====

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
    ScsiPortNotification();
  }
  return;
}



===== ScsiPortWmiPostProcess @ 140019dc8 =====

void ScsiPortWmiPostProcess(longlong param_1,char param_2,uint param_3)

{
  char cVar1;
  
  cVar1 = ScsiWmipPostProcess(*(char *)(param_1 + 0x18),*(uint **)(param_1 + 0x10),
                              *(uint *)(param_1 + 8),param_3,param_2,(uint *)(param_1 + 0x1c));
  *(char *)(param_1 + 0x19) = cVar1;
  return;
}



===== ScsiWmipFindGuid @ 140019e00 =====

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



===== ScsiWmipPostProcess @ 140019e60 =====

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
        goto LAB_140019f28;
      }
      param_5 = '\x12';
    }
LAB_140019f06:
    if ((param_5 != '\x12') || (param_3 < 0x38)) goto LAB_140019f28;
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
        goto LAB_140019f28;
      }
      goto LAB_140019f06;
    }
    if (param_1 != '\t') goto LAB_140019f28;
    uVar5 = param_2[0xf] + param_4;
    if (param_5 == '\x01') {
      if (0x47 < param_3) {
        *param_2 = uVar5;
        param_2[0x10] = param_4;
        uVar7 = uVar5;
      }
      goto LAB_140019f28;
    }
    if ((param_5 != '\x12') || (param_3 < 0x38)) goto LAB_140019f28;
    param_2[0xc] = uVar5;
  }
  *param_2 = 0x38;
  param_2[0xb] = 0x20;
  param_5 = '\x01';
  uVar7 = 0x38;
LAB_140019f28:
  *param_6 = uVar7;
  return param_5;
}



===== ScsiWmipProcessRequest @ 140019fb0 =====

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
  psVar4 = param_9;
  psVar4[0] = 0;
  psVar4[1] = 0;
  local_38[0] = 0;
  uVar6 = 0;
  if (param_2 != 8) {
    uVar7 = ScsiWmipFindGuid(*(longlong **)(param_1 + 2),*param_1,param_5,local_res10,local_38);
    if ((char)uVar7 == '\0') {
LAB_14001a0a8:
      *param_8 = 0;
      cVar5 = '\x04';
      goto LAB_14001a3b2;
    }
    if (((byte)(param_2 - 1) < 3) || (param_2 == 9)) {
      uVar6 = param_7[0xd];
      if (((char)param_7[0xb] < '\0') && (local_38[0] <= uVar6)) goto LAB_14001a0a8;
    }
    else {
      uVar6 = 0;
    }
  }
  if (param_2 < 6) {
    if (param_2 != 5) {
      if (param_2 == 0) {
        if (param_6 < 0x48) goto LAB_14001a0ed;
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
              goto LAB_14001a3d9;
            }
            goto LAB_14001a3ec;
          }
LAB_14001a0ed:
          cVar5 = '\x04';
          goto LAB_14001a3ee;
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
LAB_14001a1cb:
      cVar5 = (*pcVar8)(param_3,param_4,local_res10[0],uVar6,uVar19,puVar14,iVar16,lVar12);
      return cVar5;
    }
    pcVar8 = *(code **)(param_1 + 0xe);
    if (pcVar8 != (code *)0x0) {
      uVar20 = 0;
      uVar17 = 0;
      goto LAB_14001a3dd;
    }
  }
  else if (param_2 == 6) {
    pcVar8 = *(code **)(param_1 + 0xe);
    if (pcVar8 != (code *)0x0) {
      uVar17 = 1;
LAB_14001a3d9:
      uVar20 = 1;
LAB_14001a3dd:
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
              goto LAB_14001a1cb;
            }
          }
          cVar5 = '\x04';
          goto LAB_14001a3ee;
        }
        goto LAB_14001a0ed;
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
          goto LAB_14001a3a5;
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
LAB_14001a3a5:
        param_6 = 0;
      }
      *param_8 = param_6;
LAB_14001a3b2:
      psVar4[0] = 1;
      psVar4[1] = 0;
      return cVar5;
    }
    pcVar8 = *(code **)(param_1 + 0xe);
    if (pcVar8 != (code *)0x0) {
      uVar20 = 0;
      uVar17 = 1;
      goto LAB_14001a3dd;
    }
  }
LAB_14001a3ec:
  cVar5 = '\x01';
LAB_14001a3ee:
  psVar4[0] = 1;
  psVar4[1] = 0;
  return cVar5;
}



===== _guard_dispatch_icall @ 14001a430 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x00014001a430. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== memmove @ 14001a440 =====

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



===== memset @ 14001a700 =====

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



===== entry @ 140021000 =====

void entry(undefined8 param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14002102c =====

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


