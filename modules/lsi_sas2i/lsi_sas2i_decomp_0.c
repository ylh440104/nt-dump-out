
===== BuildScatterGather @ 140001000 =====

void BuildScatterGather(longlong param_1,longlong param_2,uint *param_3,int param_4,uint *param_5,
                       uint param_6)

{
  undefined1 uVar1;
  char cVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  ulonglong uVar9;
  uint *puVar10;
  byte bVar11;
  uint uVar12;
  ulonglong uVar13;
  uint uVar14;
  uint uVar15;
  char cVar16;
  uint uVar17;
  uint *puVar18;
  uint uVar19;
  uint uVar20;
  uint local_res10;
  int local_64;
  uint *local_58;
  
  uVar20 = 0;
  local_64 = 0;
  local_58 = param_5;
  iVar7 = 0x30;
  uVar19 = 0x10;
  bVar11 = *(byte *)(param_1 + 0x24e) & 1;
  if ((char)*(undefined4 *)(param_2 + 0x18) < '\0') {
    param_5[0xf] = param_5[0xf] | 0x1000000;
    uVar19 = 0x14;
  }
  else {
    param_5[0xf] = param_5[0xf] | 0x2000000;
  }
  if (bVar11 == 0) {
    uVar5 = 2;
  }
  else {
    iVar7 = 0x32;
    uVar19 = uVar19 | 2;
    uVar5 = 3;
  }
  uVar15 = (uint)*(ushort *)(param_1 + 0x23a);
  uVar1 = *(undefined1 *)(param_1 + 0x214);
  puVar3 = (uint *)StorPortGetScatterGatherList(param_1,param_2);
  uVar17 = *puVar3;
  puVar4 = puVar3 + 4;
  uVar12 = param_4 - *(int *)(param_2 + 0x40);
  if (uVar12 != 0) {
    uVar8 = puVar3[6];
    if (uVar8 <= uVar12) {
      do {
        puVar3 = puVar4 + 6;
        uVar12 = uVar12 - uVar8;
        uVar17 = uVar17 - 1;
        uVar8 = puVar4[8];
        puVar4 = puVar3;
      } while (uVar8 <= uVar12);
    }
    uVar8 = *(uint *)(param_2 + 0x3c);
    uVar14 = 0;
    puVar3 = puVar4;
    if (uVar17 != 0) {
      do {
        uVar6 = puVar3[2];
        if (puVar3 == puVar4) {
          uVar6 = uVar6 - uVar12;
        }
        if (uVar8 < uVar6) {
          local_64 = uVar6 - uVar8;
          uVar6 = uVar8;
        }
        uVar8 = uVar8 - uVar6;
        if (uVar8 == 0) break;
        puVar3 = puVar3 + 6;
        uVar14 = uVar14 + 1;
      } while (uVar14 < uVar17);
    }
    uVar17 = uVar14 + 1;
  }
  uVar13 = (ulonglong)uVar5;
  puVar3 = param_3;
  puVar18 = (uint *)0x0;
  uVar8 = uVar15;
  local_res10 = uVar15;
  if (uVar17 <= uVar15 + 1) {
    uVar8 = uVar17;
  }
  while( true ) {
    puVar10 = puVar3;
    uVar14 = 0;
    if (uVar8 != 0) {
      uVar9 = (ulonglong)uVar8;
      do {
        *puVar3 = puVar4[2] | uVar19 << 0x18;
        puVar3[1] = *puVar4;
        if (bVar11 != 0) {
          puVar3[2] = puVar4[1];
        }
        puVar3 = puVar3 + uVar13;
        puVar4 = puVar4 + 6;
        uVar9 = uVar9 - 1;
      } while (uVar9 != 0);
      puVar10 = puVar3;
      uVar15 = local_res10;
      uVar14 = uVar8;
    }
    uVar20 = uVar20 + uVar14;
    cVar16 = (char)uVar14;
    cVar2 = (char)uVar5;
    if (uVar17 <= uVar20) break;
    puVar10[-uVar13] = puVar10[-uVar13] | 0x80000000;
    if (uVar20 == uVar15) {
      *(undefined1 *)((longlong)param_5 + 2) = uVar1;
      uVar15 = (uint)*(ushort *)(param_1 + 0x23c);
      local_res10 = uVar15;
    }
    if (puVar18 != (uint *)0x0) {
      *(char *)((longlong)puVar18 + 2) = cVar2 * cVar16;
      *(ushort *)puVar18 = (ushort)(byte)((cVar16 + '\x01') * cVar2 * '\x04');
    }
    param_6 = param_6 + *(ushort *)(param_1 + 0x240);
    puVar3 = (uint *)((longlong)local_58 + (ulonglong)*(ushort *)(param_1 + 0x240));
    puVar10[1] = param_6;
    *puVar10 = iVar7 << 0x18;
    if (bVar11 != 0) {
      puVar10[2] = *(uint *)(param_1 + 0x1ec);
    }
    puVar18 = puVar10;
    uVar8 = uVar15;
    local_58 = puVar3;
    if (uVar17 - uVar20 <= uVar15 + 1) {
      uVar8 = uVar17 - uVar20;
    }
  }
  puVar10[-uVar13] = puVar10[-uVar13] | 0xc1000000;
  if (local_64 != 0) {
    puVar10[-uVar13] = puVar10[-uVar13] - local_64;
  }
  if (puVar18 != (uint *)0x0) {
    *(undefined1 *)((longlong)puVar18 + 2) = 0;
    *(ushort *)puVar18 = (ushort)(byte)(cVar2 * cVar16 * '\x04');
  }
  if ((uVar12 != 0) && (param_3 != (uint *)0x0)) {
    *param_3 = *param_3 - uVar12;
    param_3[1] = param_3[1] + uVar12;
  }
  return;
}



===== BuildZeroLenSGE @ 1400012e0 =====

void BuildZeroLenSGE(longlong param_1,longlong param_2,int param_3)

{
  *(undefined4 *)(param_2 + 0x60) = 0xd3000000;
  *(int *)(param_2 + 100) = param_3 + 0x70;
  *(undefined4 *)(param_2 + 0x68) = *(undefined4 *)(param_1 + 0x1ec);
  return;
}



===== DriverEntry @ 140001300 =====

void DriverEntry(undefined8 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 local_d8;
  undefined1 *local_d0;
  code *local_c8;
  undefined1 *local_c0;
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
  local_d0 = &LSImpiHWInitialize;
  local_c8 = LSImpiStartIo;
  local_c0 = &LSImpiIsr;
  local_b8 = LSImpiFindAdapter;
  local_b0 = LSImpiOSReset;
  local_60 = LSImpiAdapterControl;
  local_58 = LSImpiBuildIo;
  local_d8._0_4_ = 0xd0;
  local_80 = 0x1010102;
  local_8c = 2;
  local_d8._4_4_ = 5;
  local_7c = 1;
  local_98 = 0x3d58;
  local_90 = 0x358;
  local_94 = 0x48;
  local_1c = 2;
  local_18 = 1;
  local_20 = 0x22;
  StorPortInitialize(param_1,param_2,&local_d8);
  return;
}



===== InternalLSImpiHWInitialize @ 140001420 =====

ulonglong InternalLSImpiHWInitialize(longlong param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  undefined8 uVar3;
  
  iVar2 = StorPortExtendedFunction(0xd,param_1,0,param_1 + 0x108);
  if (iVar2 == 0) {
    *(undefined1 *)(param_1 + 0x129) = 1;
  }
  else {
    *(undefined1 *)(param_1 + 0x12a) = 0;
  }
  if ((*(char *)(param_1 + 0x12a) != '\0') && (*(char *)(param_1 + 0xdce) == '\0')) {
    *(undefined1 *)(param_1 + 0x12a) = 0;
    iVar2 = StorPortExtendedFunction(0xe,param_1,1,param_1 + 0x130);
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x134) = 0x28;
      *(undefined4 *)(param_1 + 0x130) = 4;
      if ((*(uint *)(param_1 + 0x138) & 1) != 0) {
        *(undefined4 *)(param_1 + 0x138) = 1;
        iVar2 = StorPortExtendedFunction(0xe,param_1,0,param_1 + 0x130);
        if (iVar2 == 0) {
          *(undefined1 *)(param_1 + 0x12a) = 1;
        }
      }
    }
  }
  if ((**(uint **)(param_1 + 0x18) & 0xf0000000) != 0x20000000) {
    return (ulonglong)*(uint **)(param_1 + 0x18) & 0xffffffffffffff00;
  }
  ClearResetHistoryBit(param_1);
  **(uint **)(param_1 + 0x50) = **(uint **)(param_1 + 0x50) | 0x40000009;
  LOCK();
  UNLOCK();
  uVar3 = FwDiagPostImmediateBuffers(param_1,param_2);
  if ((char)uVar3 == '\0') {
    StorPortLogError(param_1,0,0,0,0,6,0xad01002a);
  }
  puVar1 = *(uint **)(param_1 + 0x50);
  *puVar1 = **(uint **)(param_1 + 0x50) & 0xfffffff7;
  LOCK();
  UNLOCK();
  *(undefined4 *)(param_1 + 0x1560) = 1;
  if (*(char *)(param_1 + 0xdce) == '\0') {
    *(undefined1 *)(param_1 + 0xdce) = 1;
    *(undefined1 *)(param_1 + 0xdb9) = 0;
  }
  return CONCAT71((int7)((ulonglong)puVar1 >> 8),1);
}



===== LSImpiBuildIo @ 1400015a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 LSImpiBuildIo(longlong param_1,longlong param_2)

{
  uint uVar1;
  uint *puVar2;
  byte bVar3;
  byte bVar4;
  undefined1 uVar5;
  byte bVar6;
  byte bVar7;
  short sVar8;
  uint *puVar9;
  ulonglong uVar10;
  int iVar11;
  ulonglong uVar12;
  uint *puVar13;
  int *piVar14;
  ushort uVar15;
  short *psVar16;
  longlong lVar17;
  uint uVar18;
  uint uVar19;
  undefined1 auStackY_a8 [32];
  undefined1 local_5c [4];
  longlong local_58;
  undefined1 local_50 [4];
  undefined4 local_4c;
  byte local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_a8;
  puVar9 = *(uint **)(param_2 + 0x68);
  if (*(char *)(param_2 + 2) != '(') {
    *(undefined1 *)(param_2 + 3) = 0x22;
LAB_1400015d3:
    uVar12 = StorPortNotification(0,param_1,param_2);
    return uVar12 & 0xffffffffffffff00;
  }
  if (*(int *)(param_1 + 0xdf8) != 0) {
    *(undefined1 *)(param_2 + 3) = 5;
    goto LAB_1400015d3;
  }
  psVar16 = (short *)((ulonglong)*(uint *)(param_2 + 0x34) + param_2);
  if (*psVar16 != 1) {
    *(undefined1 *)(param_2 + 3) = 4;
    goto LAB_1400015d3;
  }
  bVar3 = *(byte *)(psVar16 + 4);
  *(byte *)((longlong)puVar9 + 0x52) = bVar3;
  bVar4 = *(byte *)((longlong)psVar16 + 9);
  *(byte *)((longlong)puVar9 + 0x53) = bVar4;
  uVar5 = (undefined1)psVar16[5];
  *(undefined1 *)(puVar9 + 0x15) = uVar5;
  uVar12 = 0;
  switch(*(undefined4 *)(param_2 + 0x14)) {
  case 0:
    uVar18 = 0;
    uVar19 = 0;
    if (*(uint *)(param_2 + 0x38) != 0) {
      while( true ) {
        piVar14 = (int *)((ulonglong)*(uint *)(param_2 + 0x78 + (ulonglong)uVar19 * 4) + param_2);
        iVar11 = *piVar14;
        uVar1 = iVar11 - 0x40;
        if (uVar1 < 2) break;
        uVar19 = uVar19 + 1;
        if (*(uint *)(param_2 + 0x38) <= uVar19) {
          return CONCAT71((uint7)(uint3)(uVar1 >> 8),1);
        }
      }
      *(int **)(puVar9 + 0xe) = piVar14;
      uVar15 = (ushort)bVar3 * 0x80 + (ushort)bVar4;
      if ((uint)uVar15 < *(uint *)(param_1 + 0x5b8)) {
        local_58 = *(longlong *)(param_1 + 0x2c8) + (ulonglong)uVar15 * 0x28;
        sVar8 = *(short *)(local_58 + 0x1a);
        if (sVar8 != 0) {
          bVar6 = *(byte *)(piVar14 + 6);
          *(byte *)(puVar9 + 0x14) = bVar6;
          puVar2 = puVar9 + 0x56;
          bVar7 = *(byte *)((longlong)piVar14 + 0x19);
          *(byte *)((longlong)puVar9 + 0x51) = bVar7;
          uVar19 = *(uint *)(param_2 + 0x18);
          *puVar9 = 0;
          ZeroMemory((undefined1 *)puVar2,0x60);
          *(short *)puVar2 = sVar8;
          *(undefined1 *)((longlong)puVar9 + 0x15b) = 0;
          *(undefined1 *)(puVar9 + 0x5b) = 0x18;
          *(ushort *)(puVar9 + 0x5f) = (ushort)*(byte *)((longlong)piVar14 + 10);
          *(undefined1 *)((longlong)puVar9 + 0x18d) = uVar5;
          if (iVar11 == 0x41) {
            iVar11 = *(byte *)((longlong)piVar14 + 10) - 0x10;
            puVar9[0x65] = ((int)(iVar11 + (iVar11 >> 0x1f & 3U)) >> 2) << 0x1a |
                           puVar9[0x65] & 0x3ffffff;
          }
          if ((uVar19 & 2) != 0) {
            uVar18 = (*(ushort *)(param_2 + 0x26) & 3) << 8;
          }
          uVar18 = puVar9[0x65] & 0xfffff8ff | uVar18;
          puVar9[0x65] = uVar18;
          puVar9[0x65] = (*(byte *)(local_58 + 0x22) ^ uVar18) & 0xc0 ^ uVar18;
          memcpy(puVar9 + 0x66,piVar14 + 6,(ulonglong)*(byte *)((longlong)piVar14 + 10));
          if (((*(char *)(param_1 + 0xdcf) != '\0') && (bVar6 = (&OpCodeProt)[bVar6], bVar6 != 0))
             && (puVar13 = (uint *)StorPortGetLogicalUnit(param_1,bVar3,bVar4,uVar5),
                (char)puVar13[1] != '\0')) {
            puVar9[0x60] = *puVar13;
            uVar15 = (ushort)puVar9[0x5f] & 0x1ff;
            *(ushort *)((longlong)puVar9 + 0x17e) = bVar6 | 0x8500;
            if (uVar15 == 0x20) {
              *(ushort *)((longlong)puVar9 + 0x17e) = bVar6 | 0xa500;
              *(byte *)((longlong)puVar9 + 0x1a2) =
                   *(byte *)((longlong)piVar14 + 0x22) & 0x1f | 0x20;
            }
            else {
              lVar17 = 0x42;
              if (uVar15 == 0x10) {
                lVar17 = 0x46;
              }
              memcpy(puVar9 + 0x6b,(void *)(lVar17 + (longlong)puVar2),4);
              *(undefined2 *)((longlong)puVar9 + 0x1b2) = 0xffff;
              *(byte *)((longlong)puVar9 + 0x199) = bVar7 & 0x1f | 0x20;
            }
          }
          puVar9[0x5d] = *(uint *)(param_2 + 0x3c);
          uVar18 = StorPortGetPhysicalAddress(param_1,param_2,puVar2,local_5c);
          *(undefined1 *)((longlong)puVar9 + 0x16a) = 0xff;
          puVar9[0x59] = uVar18 - 0x100;
          if ((uVar19 & 0xc0) == 0) {
            puVar9[0x6e] = 0xd3000000;
            puVar9[0x6f] = uVar18 + 0x70;
            uVar12 = (ulonglong)*(uint *)(param_1 + 0x1ec);
            puVar9[0x70] = *(uint *)(param_1 + 0x1ec);
          }
          else {
            uVar12 = BuildScatterGather(param_1,param_2,puVar9 + 0x6e,
                                        (int)*(undefined8 *)(param_2 + 0x40),puVar2,uVar18);
          }
          if (*(char *)(param_1 + 0x12a) != '\0') {
            local_4c = 0x10;
            uVar12 = StorPortExtendedFunction(0xf,param_1,param_2,local_50);
            if ((int)uVar12 == 0) {
              *puVar9 = *puVar9 | (uint)local_48 << 8;
              return CONCAT71((uint7)local_48,1);
            }
          }
          break;
        }
      }
      *(undefined1 *)(param_2 + 3) = 10;
      goto LAB_140001961;
    }
    break;
  default:
    *(undefined1 *)(param_2 + 3) = 0x22;
    goto LAB_140001961;
  case 2:
  case 0x12:
  case 0x13:
  case 0x17:
  case 0x20:
    break;
  case 0x10:
  case 0x14:
    *(undefined1 *)(param_2 + 3) = 3;
LAB_140001961:
    uVar12 = StorPortNotification(0,param_1,param_2);
    return uVar12 & 0xffffffffffffff00;
  case 0x24:
    uVar10 = 0;
    if (*(int *)(param_2 + 0x38) != 0) {
      do {
        uVar12 = uVar10;
        piVar14 = (int *)((ulonglong)*(uint *)(param_2 + 0x78 + uVar12 * 4) + param_2);
        if (*piVar14 == 0x61) {
          *(int **)(puVar9 + 0x10) = piVar14;
        }
        uVar19 = (int)uVar12 + 1;
        uVar10 = (ulonglong)uVar19;
      } while (uVar19 < *(uint *)(param_2 + 0x38));
    }
  }
  return CONCAT71((int7)(uVar12 >> 8),1);
}



===== LSImpiFindAdapter @ 1400019d0 =====

undefined8
LSImpiFindAdapter(longlong *param_1,undefined8 param_2,undefined8 param_3,byte *param_4,
                 longlong param_5)

{
  longlong *plVar1;
  ushort uVar2;
  ushort uVar3;
  longlong lVar4;
  undefined8 *puVar5;
  uint *puVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  ushort uVar9;
  uint uVar10;
  longlong lVar11;
  int iVar12;
  ushort uVar13;
  uint uVar14;
  int iVar15;
  undefined8 *puVar16;
  undefined8 *puVar17;
  ulonglong uVar18;
  ushort uVar19;
  ushort uVar20;
  uint *in_stack_ffffffffffffff88;
  undefined4 uVar21;
  uint local_58;
  uint local_54;
  byte local_50 [4];
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_38;
  
  lVar4 = param_5;
  local_50[0] = 0x54;
  local_50[1] = 0x50;
  local_50[2] = 0x53;
  local_50[3] = '0';
  local_38 = local_38 & 0xffff0000;
  local_54 = 0;
  local_44 = 0;
  local_40 = 0;
  if (*param_1 != 0) {
    ZeroMemory((undefined1 *)param_1,0x3d58);
  }
  *(undefined1 *)(param_1 + 0x25) = 0;
  *(undefined1 *)((longlong)param_1 + 0x3d51) = 1;
  GtfInitialize((longlong)param_1);
  puVar16 = (undefined8 *)0x0;
  *(undefined1 *)((longlong)param_1 + 0xdb9) = 1;
  puVar17 = (undefined8 *)0x0;
  if (*(int *)(*(undefined8 **)(param_5 + 0x38) + 1) != 0) {
    lVar11 = 2;
    puVar5 = *(undefined8 **)(param_5 + 0x38);
    do {
      if (*(int *)(puVar5 + 1) != 0) {
        if (*(char *)((longlong)puVar5 + 0xc) == '\0') {
          puVar16 = puVar5;
        }
        else if (puVar17 == (undefined8 *)0x0) {
          puVar17 = puVar5;
        }
      }
      lVar11 = lVar11 + -1;
      puVar5 = puVar5 + 2;
    } while (lVar11 != 0);
    if (puVar17 != (undefined8 *)0x0) {
      if (puVar16 != (undefined8 *)0x0) {
        *(undefined4 *)((longlong)param_1 + 0x1554) = *(undefined4 *)puVar16;
      }
      *(undefined4 *)(param_1 + 0x2ab) = *(undefined4 *)puVar17;
      *(undefined4 *)((longlong)param_1 + 0x155c) = *(undefined4 *)((longlong)puVar17 + 4);
      *(undefined4 *)(param_1 + 0x2ac) = 3;
      *(undefined4 *)(param_1 + 0x2c5) = 1;
      in_stack_ffffffffffffff88 =
           (uint *)CONCAT44((int)((ulonglong)in_stack_ffffffffffffff88 >> 0x20),
                            *(undefined4 *)(puVar17 + 1));
      lVar11 = StorPortGetDeviceBase
                         (param_1,*(undefined4 *)(param_5 + 8),*(undefined4 *)(param_5 + 4),*puVar17
                          ,in_stack_ffffffffffffff88,*(char *)((longlong)puVar17 + 0xc) == '\0');
      param_1[2] = lVar11;
      if (puVar16 != (undefined8 *)0x0) {
        in_stack_ffffffffffffff88 =
             (uint *)CONCAT44((int)((ulonglong)in_stack_ffffffffffffff88 >> 0x20),
                              *(undefined4 *)(puVar16 + 1));
        lVar11 = StorPortGetDeviceBase
                           (param_1,*(undefined4 *)(param_5 + 8),*(undefined4 *)(param_5 + 4),
                            *puVar16,in_stack_ffffffffffffff88,
                            *(char *)((longlong)puVar16 + 0xc) == '\0');
        param_1[0x1f] = lVar11;
      }
      if (param_1[2] == 0) {
        uVar21 = 0xad010002;
      }
      else {
        puVar6 = (uint *)(param_1 + 0x26b);
        in_stack_ffffffffffffff88 = puVar6;
        local_4c = StorPortGetBusData(param_1,4,*(undefined4 *)(param_5 + 4),
                                      *(undefined4 *)(param_5 + 100),puVar6,0x100);
        lVar11 = param_1[2];
        param_1[3] = lVar11;
        param_1[4] = lVar11 + 4;
        param_1[5] = lVar11 + 8;
        param_1[6] = lVar11 + 0x10;
        param_1[7] = lVar11 + 0x14;
        param_1[8] = lVar11 + 0x18;
        param_1[9] = lVar11 + 0x30;
        param_1[10] = lVar11 + 0x34;
        param_1[0xb] = lVar11 + 0x48;
        param_1[0xc] = lVar11 + 0x6c;
        lVar11 = param_1[2];
        param_1[0x1c] = lVar11 + 0x74;
        param_1[0x1d] = lVar11 + 0xc0;
        param_1[0x1e] = lVar11 + 0xc4;
        if ((*(uint *)param_1[3] & 0x7000000) != 0x3000000) {
          if (param_4 != (byte *)0x0) {
            ProcessParseArgumentString(param_4,(byte *)"dump",(int *)&local_54);
            ProcessParseArgumentString(param_4,(byte *)"ntldr",(int *)&local_44);
            local_54 = local_54 | local_44;
            if (local_54 != 0) {
              *(uint *)(param_1 + 0xae) = local_54;
            }
          }
          if (2 < local_4c) {
            *(uint *)(param_1 + 0xaa) = (uint)*(ushort *)((longlong)param_1 + 0x135a);
            local_40 = *(int *)(param_5 + 4) << 8 | *(uint *)(param_5 + 100);
            GetCimData((longlong)param_1,(longlong)puVar6,local_40);
          }
          if ((*(uint *)param_1[3] >> 0x1b & 1) != 0) {
            KickStart((longlong)param_1,1);
          }
          puVar6 = (uint *)param_1[3];
          uVar14 = 0;
          while (uVar10 = *puVar6 & 0xf0000000, uVar10 != 0x10000000) {
            if (uVar10 == 0x20000000) {
              IssueIOCFacts((longlong)param_1);
              if ((*(uint *)((longlong)param_1 + 0xdec) & 0x2000) == 0) {
                KickStart((longlong)param_1,1);
              }
              else {
                IssueReset((longlong)param_1,0x40);
              }
            }
            else if ((uVar10 != 0) && (uVar7 = KickStart((longlong)param_1,1), (char)uVar7 == '\0'))
            {
              return 2;
            }
            lVar11 = 100;
            do {
              StorPortStallExecution(1000);
              lVar11 = lVar11 + -1;
            } while (lVar11 != 0);
            if (200 < uVar14) {
              uVar21 = 0xad010003;
              goto LAB_140001d3b;
            }
            uVar14 = uVar14 + 1;
            puVar6 = (uint *)param_1[3];
          }
          uVar8 = IssueIOCFacts((longlong)param_1);
          if ((char)uVar8 == '\0') {
            return 2;
          }
          param_5._0_2_ = *(ushort *)((longlong)param_1 + 0x23e);
          lVar11 = 10;
          uVar2 = *(ushort *)(param_1 + 0x48);
          *(undefined4 *)((longlong)param_1 + 0x584) = 0x40;
          uVar14 = 0;
          local_48 = (uint)*(ushort *)((longlong)param_1 + 0x24c);
          *(undefined4 *)(param_1 + 0xb1) = 0x20;
          *(undefined4 *)(param_1 + 0xb0) = 10;
          *(undefined2 *)(param_1 + 0x7a9) = 1;
          if (*(short *)((longlong)param_1 + 0x596) != 0) {
            do {
              uVar7 = IssuePortFacts((longlong)param_1,(char)uVar14);
              if ((char)uVar7 == '\0') {
                return 2;
              }
              uVar14 = uVar14 + 1;
            } while (uVar14 < *(ushort *)((longlong)param_1 + 0x596));
          }
          plVar1 = param_1 + 0x5b;
          *(undefined4 *)(param_1 + 0xa0) = 5;
          RttSetTraceParameters((longlong)plVar1,0x7800,1);
          if (param_4 != (byte *)0x0) {
            uVar8 = ProcessParseArgumentString(param_4,(byte *)"RTTraceBufferSize",(int *)&local_58)
            ;
            if (((char)uVar8 != '\0') && (local_58 != 0)) {
              if ((local_58 & 3) != 0) {
                local_58 = local_58 + (4 - (local_58 & 3));
              }
              RttSetTraceParameters((longlong)plVar1,local_58,2);
            }
            uVar8 = ProcessParseArgumentString(param_4,(byte *)"SizeOfReplyBuffer",(int *)&local_58)
            ;
            if (((char)uVar8 != '\0') && (0x40 < local_58)) {
              if ((local_58 & 3) != 0) {
                local_58 = 4 - (local_58 & 3);
              }
              param_5._0_2_ = (ushort)local_58;
            }
            uVar8 = ProcessParseArgumentString
                              (param_4,(byte *)"LogFullPersistentTableEvent",(int *)&local_58);
            if ((char)uVar8 != '\0') {
              *(bool *)((longlong)param_1 + 0x3d51) = local_58 != 0;
            }
            uVar8 = ProcessParseArgumentString(param_4,(byte *)"SSU_Enables",(int *)&local_58);
            if ((char)uVar8 != '\0') {
              if ((local_58 & 0xfffffffc) == 0) {
                *(ushort *)(param_1 + 0x7a9) = (ushort)local_58 & 3;
              }
              else {
                *(undefined2 *)(param_1 + 0x7a9) = 1;
                if (((char)param_1[0x61] != '\0') &&
                   ((*(uint *)((longlong)param_1 + 0x30c) & 0x110) != 0)) {
                  in_stack_ffffffffffffff88 = &local_58;
                  RttLogEvent(param_1,(char *)((longlong)param_1 + 0xdb9),(int *)plVar1,0x110,
                              (undefined1 *)in_stack_ffffffffffffff88,4,1);
                }
              }
            }
            *(short *)((longlong)param_1 + 0x3d4c) = (short)param_1[0x7a9];
            uVar8 = ProcessParseArgumentString
                              (param_4,(byte *)"NumberOfRequestMessageBuffers",(int *)&local_58);
            if (((char)uVar8 != '\0') && (local_38 = 0x10, 0x10 < local_58)) {
              local_38 = local_58 & 0xffff;
            }
            uVar8 = ProcessParseArgumentString
                              (param_4,(byte *)"LogExceptionEvents",(int *)&local_58);
            if (((char)uVar8 != '\0') && (local_58 != 0)) {
              *(undefined2 *)(param_1 + 0xac) = 1;
            }
            uVar8 = ProcessParseArgumentString(param_4,(byte *)"DisableRescan",(int *)&local_58);
            if (((char)uVar8 != '\0') && (local_58 != 0)) {
              *(undefined2 *)((longlong)param_1 + 0x5a6) = 1;
            }
            uVar8 = ProcessParseArgumentString(param_4,(byte *)"StopOnBusReset",(int *)&local_58);
            if (((char)uVar8 != '\0') && (local_58 != 0)) {
              *(undefined1 *)((longlong)param_1 + 0xdad) = 1;
            }
            uVar8 = ProcessParseArgumentString(param_4,(byte *)"StopOnDiagReset",(int *)&local_58);
            if (((char)uVar8 != '\0') && (local_58 != 0)) {
              *(undefined1 *)((longlong)param_1 + 0xdae) = 1;
            }
            uVar8 = ProcessParseArgumentString
                              (param_4,(byte *)"StopOnOrphanedReset",(int *)&local_58);
            if (((char)uVar8 != '\0') && (local_58 != 0)) {
              *(undefined1 *)((longlong)param_1 + 0xdaf) = 1;
            }
            uVar8 = ProcessParseArgumentString
                              (param_4,(byte *)"DisableFwQueueFullHandling",(int *)&local_58);
            if (((char)uVar8 != '\0') && (local_58 != 0)) {
              *(undefined1 *)((longlong)param_1 + 0xdea) = 0;
            }
            uVar8 = ProcessParseArgumentString(param_4,(byte *)"EEDP_Enable",(int *)&local_58);
            if ((((char)uVar8 != '\0') && (local_58 != 0)) &&
               ((*(uint *)((longlong)param_1 + 0xdec) & 0x40) != 0)) {
              *(undefined1 *)((longlong)param_1 + 0xdcf) = 1;
            }
            uVar8 = ProcessParseArgumentString
                              (param_4,(byte *)"DisableHashSASAddr",(int *)&local_58);
            if (((char)uVar8 != '\0') && (local_58 != 0)) {
              *(undefined1 *)((longlong)param_1 + 0xdc7) = 1;
            }
            uVar8 = ProcessParseArgumentString(param_4,(byte *)"MaxSGList",(int *)&local_58);
            if (((char)uVar8 != '\0') && (0x10 < local_58)) {
              *(uint *)((longlong)param_1 + 0x58c) = local_58;
            }
            uVar8 = ProcessParseArgumentString(param_4,(byte *)"MaxSASQueueDepth",(int *)&local_58);
            if ((char)uVar8 != '\0') {
              uVar14 = local_58;
              if (local_58 == 0) {
                uVar14 = 1;
              }
              *(uint *)((longlong)param_1 + 0x584) = uVar14;
            }
            uVar8 = ProcessParseArgumentString(param_4,(byte *)"MaxSATAQueueDepth",(int *)&local_58)
            ;
            if ((char)uVar8 != '\0') {
              uVar14 = local_58;
              if (local_58 == 0) {
                uVar14 = 1;
              }
              *(uint *)(param_1 + 0xb1) = uVar14;
            }
            uVar8 = ProcessParseArgumentString(param_4,(byte *)"ResumeDelay",(int *)&local_58);
            if (((char)uVar8 != '\0') && (local_58 != 0)) {
              *(uint *)(param_1 + 0xb0) = local_58;
            }
            uVar8 = ProcessParseArgumentString(param_4,&s_PSuite,(int *)&local_58);
            if (((char)uVar8 != '\0') && (local_58 != 0)) {
              *(undefined1 *)((longlong)param_1 + 0xda7) = 1;
            }
            uVar8 = ProcessParseArgumentString
                              (param_4,(byte *)"MaxPersistentEntries",(int *)&local_58);
            if ((char)uVar8 != '\0') {
              uVar9 = (ushort)local_58;
              if (*(ushort *)(param_1 + 0xb3) < (ushort)local_58) {
                uVar9 = *(ushort *)(param_1 + 0xb3);
              }
              *(ushort *)((longlong)param_1 + 0x14bc) = uVar9;
            }
            uVar8 = ProcessParseArgumentString(param_4,(byte *)"EnaDiag",(int *)&local_58);
            if (((char)uVar8 != '\0') && (local_58 != 0)) {
              uVar8 = ProcessParseArgumentString(param_4,&s_SSBuffSize,(int *)&local_58);
              if (((char)uVar8 != '\0') && ((local_58 != 0 && ((char)param_1[0x261] != '\0')))) {
                *(uint *)(param_1 + 0x260) = local_58;
              }
              uVar8 = ProcessParseArgumentString(param_4,&s_SSImmed,(int *)&local_58);
              if ((((char)uVar8 != '\0') && (local_58 != 0)) && ((char)param_1[0x261] != '\0')) {
                *(undefined1 *)((longlong)param_1 + 0x1307) = 1;
              }
              uVar8 = ProcessParseArgumentString(param_4,&s_TBuffSize,(int *)&local_58);
              if ((((char)uVar8 != '\0') && (local_58 != 0)) && ((char)param_1[0x25e] != '\0')) {
                *(uint *)(param_1 + 0x25d) = local_58;
              }
              uVar8 = ProcessParseArgumentString(param_4,&s_TImmed,(int *)&local_58);
              if ((((char)uVar8 != '\0') && (local_58 != 0)) && ((char)param_1[0x25e] != '\0')) {
                *(undefined1 *)((longlong)param_1 + 0x12ef) = 1;
              }
              puVar6 = (uint *)(param_1 + 0x265);
              do {
                uVar8 = ProcessParseArgumentString(param_4,local_50,(int *)&local_58);
                if ((((char)uVar8 != '\0') && (local_58 != 0)) && ((char)param_1[0x25e] != '\0')) {
                  *puVar6 = local_58;
                }
                local_50[3] = local_50[3] + '\x01';
                puVar6 = puVar6 + 1;
                lVar11 = lVar11 + -1;
              } while (lVar11 != 0);
              uVar8 = ProcessParseArgumentString(param_4,&s_EXBuffSize,(int *)&local_58);
              if ((((char)uVar8 != '\0') && (local_58 != 0)) && ((char)param_1[0x264] != '\0')) {
                *(uint *)(param_1 + 0x263) = local_58;
              }
              uVar8 = ProcessParseArgumentString(param_4,&s_EXImmed,(int *)&local_58);
              if ((((char)uVar8 != '\0') && (local_58 != 0)) && ((char)param_1[0x264] != '\0')) {
                *(undefined1 *)((longlong)param_1 + 0x131f) = 1;
              }
              uVar8 = ProcessParseArgumentString(param_4,&s_EXType,(int *)&local_58);
              if ((((char)uVar8 != '\0') && (local_58 != 0)) && ((char)param_1[0x264] != '\0')) {
                *(char *)((longlong)param_1 + 0x131d) = (char)local_58;
              }
            }
            if (local_54 != 0) {
              uVar8 = ProcessParseArgumentString
                                (param_4,(byte *)"CrashModeMaxDevices",(int *)&local_58);
              if (((char)uVar8 == '\0') || (uVar14 = local_58, local_58 == 0)) {
                uVar14 = 0x40;
              }
              *(short *)(param_1 + 0xb3) = (short)uVar14;
            }
          }
          *(undefined2 *)(param_1 + 0xb4) = 1;
          if (0x80 < *(ushort *)(param_1 + 0xb3)) {
            *(ushort *)(param_1 + 0xb4) = ((ushort)(*(ushort *)(param_1 + 0xb3) - 0x81) >> 7) + 2;
          }
          if (8 < *(ushort *)(param_1 + 0xb4)) {
            *(undefined2 *)(param_1 + 0xb4) = 8;
          }
          *(undefined1 *)(lVar4 + 0x92) = 0xff;
          if (*(char *)(lVar4 + 0x90) == -0x80) {
            *(undefined1 *)(lVar4 + 0x90) = 4;
            *(uint *)(lVar4 + 0xcc) = (uint)*(ushort *)((longlong)param_1 + 0x594);
            *(undefined4 *)(lVar4 + 0xd4) = *(undefined4 *)((longlong)param_1 + 0x584);
            *(undefined4 *)(lVar4 + 0xd8) = 0;
            *(ushort *)((longlong)param_1 + 0x24e) = *(ushort *)((longlong)param_1 + 0x24e) | 1;
          }
          uVar9 = (*(ushort *)((longlong)param_1 + 0x24e) & 1) << 2 | 8;
          uVar8 = (ulonglong)((ushort)(uVar2 - uVar9) - 0x60 & 0xffff) / (ulonglong)uVar9;
          *(short *)((longlong)param_1 + 0x23a) = (short)uVar8;
          *(ushort *)((longlong)param_1 + 0x23c) = (ushort)(uVar2 - uVar9) / uVar9;
          iVar12 = (int)uVar8;
          *(uint *)((longlong)param_1 + 0x214) = iVar12 * (uint)uVar9 + 0x60 >> 2;
          iVar15 = 0x101;
          if (*(int *)((longlong)param_1 + 0x58c) != 0) {
            iVar15 = *(int *)((longlong)param_1 + 0x58c);
          }
          *(int *)(lVar4 + 0x1c) = iVar15;
          uVar9 = (short)((int)((uint)*(ushort *)(lVar4 + 0x1c) - iVar12) /
                         (int)(uint)*(ushort *)((longlong)param_1 + 0x23c)) + 1;
          if ((ushort)local_48 < uVar9) {
            *(uint *)(lVar4 + 0x1c) =
                 (local_48 & 0xffff) * (uint)*(ushort *)((longlong)param_1 + 0x23c) + iVar12;
            uVar14 = local_48;
          }
          else {
            uVar14 = (uint)uVar9;
          }
          if (local_54 == 0) {
            uVar9 = (ushort)local_38;
            if ((uVar9 != 0) && (uVar9 < *(ushort *)((longlong)param_1 + 0x594))) {
              *(ushort *)((longlong)param_1 + 0x594) = uVar9;
            }
          }
          else {
            *(undefined2 *)((longlong)param_1 + 0x594) = 4;
            *(undefined4 *)(lVar4 + 0x1c) = 0x11;
            *(undefined4 *)((longlong)param_1 + 0x59a) = 0x80008;
            uVar14 = 3;
            RttSetTraceParameters((longlong)(param_1 + 0x5b),0,0);
            *(undefined1 *)((longlong)param_1 + 0x12a) = 0;
          }
          uVar20 = *(ushort *)((longlong)param_1 + 0x594);
          *(undefined4 *)(param_1 + 0xb2) = *(undefined4 *)(lVar4 + 0x1c);
          uVar9 = uVar20 + 0x20;
          if (local_54 != 0) {
            uVar9 = 0xc;
          }
          uVar19 = uVar9 - 1;
          if ((uVar9 & 0xf) != 0) {
            uVar19 = uVar9;
          }
          *(ushort *)(param_1 + 0x49) = uVar19;
          uVar13 = (uVar19 - (uVar19 & 0xf)) + 0x10;
          uVar9 = uVar19 + 1 + uVar20;
          *(ushort *)((longlong)param_1 + 0x244) = uVar13;
          if ((uVar9 & 0xf) != 0) {
            uVar9 = uVar9 + (0x10 - (uVar9 & 0xf));
          }
          uVar3 = *(ushort *)((longlong)param_1 + 0x24a);
          if (uVar3 < uVar9) {
            uVar9 = (ushort)(uVar9 - uVar3) >> 1;
            if ((uVar9 & 0xf) != 0) {
              uVar9 = uVar9 + (0x10 - (uVar9 & 0xf));
            }
            uVar20 = uVar20 - uVar9;
            uVar19 = uVar19 - uVar9;
            uVar13 = uVar13 - uVar9;
            *(ushort *)((longlong)param_1 + 0x594) = uVar20;
            *(ushort *)((longlong)param_1 + 0x244) = uVar13;
            *(ushort *)(param_1 + 0x49) = uVar19;
            uVar9 = uVar3;
          }
          uVar10 = (uint)uVar9;
          *(ushort *)((longlong)param_1 + 0x246) = uVar9;
          if (*(char *)((longlong)param_1 + 0x12a) != '\0') {
            uVar10 = (uint)uVar9 * (uint)*(byte *)((longlong)param_1 + 299);
          }
          *(ushort *)(param_1 + 0x48) = uVar2;
          if ((ushort)param_5 < *(ushort *)((longlong)param_1 + 0x23e)) {
            param_5._0_2_ = *(ushort *)((longlong)param_1 + 0x23e);
          }
          else {
            *(ushort *)((longlong)param_1 + 0x23e) = (ushort)param_5;
          }
          uVar9 = *(ushort *)((longlong)param_1 + 0x14bc);
          local_48 = (uint)*(ushort *)(param_1 + 0xb3);
          *(uint *)(param_1 + 0xb7) = local_48;
          *(undefined4 *)(lVar4 + 0x18) = 0xffffff;
          *(undefined1 *)(lVar4 + 0x61) = 0x80;
          local_38 = (uint)uVar9 * 0x14;
          *(undefined1 *)(lVar4 + 0x51) = 1;
          *(undefined1 *)(lVar4 + 0x54) = 0;
          *(char *)(lVar4 + 0x48) = (char)param_1[0xb4];
          *(code **)(lVar4 + 0x98) = LSImpiMSIIsr;
          *(undefined1 *)(lVar4 + 0x91) = 1;
          *(undefined4 *)(lVar4 + 0x94) = 1;
          *(undefined4 *)(lVar4 + 0xa0) = 1;
          if (local_54 == 0) {
            LSImpiWmiInitialize((longlong)param_1);
            *(uint *)(param_1 + 0x3b) = local_40;
          }
          *(int *)(lVar4 + 0x8c) =
               *(int *)(lVar4 + 0x8c) + ((uVar14 & 0xffff) + 1) * (uint)uVar2 + -0x200;
          iVar12 = (int)param_1[0x263] + (int)param_1[0x260] + (int)param_1[0x25d];
          iVar15 = ((uint)uVar2 + (uint)*(ushort *)((longlong)param_1 + 0x59a) * 4) * 7 +
                   ((uint)*(ushort *)((longlong)param_1 + 0x14bc) +
                   ((uint)*(ushort *)((longlong)param_1 + 0x59c) * 0xf3 +
                    (local_48 * 6 + 0x315 + uVar10) * 2 + (uint)uVar13) * 2) * 2 +
                   (uVar2 + 0x20) * (uint)uVar20 + (uint)uVar19 * (uint)(ushort)param_5 +
                   (int)param_1[0x60] + local_38 + iVar12;
          while( true ) {
            lVar11 = StorPortGetUncachedExtension(param_1,lVar4,iVar15);
            *param_1 = lVar11;
            if (lVar11 != 0) break;
            in_stack_ffffffffffffff88 =
                 (uint *)((ulonglong)in_stack_ffffffffffffff88 & 0xffffffffffffff00);
            StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffff88,6,0xad010004);
            if (iVar12 == 0) {
              return 2;
            }
            iVar15 = iVar15 - iVar12;
            *(undefined1 *)(param_1 + 0x25e) = 0;
            *(undefined1 *)(param_1 + 0x261) = 0;
            *(undefined1 *)(param_1 + 0x264) = 0;
            iVar12 = 0;
          }
          uVar8 = StorPortGetPhysicalAddress(param_1,0,lVar11,&local_4c);
          *(int *)((longlong)param_1 + 0x1ec) = (int)(uVar8 >> 0x20);
          local_4c = (uint)uVar8 & 0x7f;
          if ((uVar8 & 0x7f) == 0) {
            uVar18 = 0;
          }
          else {
            uVar18 = (ulonglong)(0x80 - local_4c);
          }
          uVar14 = (uint)uVar8 + (int)uVar18;
          param_1[1] = uVar18 + *param_1;
          param_1[0x20] = (uVar18 + *param_1) - (ulonglong)uVar14;
          *(uint *)(param_1 + 0x3d) = uVar14;
          *(undefined1 *)((longlong)param_1 + 0xdc6) = 0;
          do {
            LsiMpiPartitionMemory((longlong)param_1);
            RttInitTrace(param_1 + 0x5b);
            if (((char)param_1[0x61] != '\0') && ((*(uint *)((longlong)param_1 + 0x30c) & 2) != 0))
            {
              in_stack_ffffffffffffff88 = (uint *)0x0;
              RttLogEvent(param_1,(char *)((longlong)param_1 + 0xdb9),(int *)(param_1 + 0x5b),2,
                          (undefined1 *)0x0,0,1);
            }
            uVar7 = BringIOCToOperationalState((longlong)param_1,1);
            if ((char)uVar7 == '\0') {
              uVar21 = 0xad010006;
LAB_140001d3b:
              StorPortLogError(param_1,0,0,0,
                               (ulonglong)in_stack_ffffffffffffff88 & 0xffffffffffffff00,6,uVar21);
              return 2;
            }
            uVar8 = 0;
            do {
              uVar14 = (uint)uVar8;
              if ((*(char *)((longlong)param_1 + 0xdbe) == '\0') &&
                 (*(char *)((longlong)param_1 + 0xdbf) == '\0')) {
                if (uVar14 < 120000) goto LAB_1400028a2;
                break;
              }
              PollLSImpiIsr((longlong)param_1,1);
              StorPortStallExecution(500);
              uVar14 = uVar14 + 1;
              uVar8 = (ulonglong)uVar14;
            } while (uVar14 < 120000);
            in_stack_ffffffffffffff88 =
                 (uint *)((ulonglong)in_stack_ffffffffffffff88 & 0xffffffffffffff00);
            *(undefined2 *)((longlong)param_1 + 0xdbe) = 0;
            StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffff88,6,0xad01004e);
            if (119999 < uVar14) {
LAB_140002909:
              *(undefined1 *)((longlong)param_1 + 0xdc6) = 1;
              *(undefined1 *)((longlong)param_1 + 0xd81) = *(undefined1 *)(lVar4 + 0x49);
              if (((char)param_1[0x61] != '\0') &&
                 ((*(uint *)((longlong)param_1 + 0x30c) & 0x400) != 0)) {
                RttLogEvent(param_1,(char *)((longlong)param_1 + 0xdb9),(int *)(param_1 + 0x5b),
                            0x400,(undefined1 *)0x0,0,1);
              }
              *(undefined1 *)((longlong)param_1 + 0xdf1) = 0;
              StorPortNotification(6,param_1,WatchdogTimer,1000000);
              return 1;
            }
LAB_1400028a2:
            MapSODChecks((longlong)param_1,1);
            CompressEnclosureTable((longlong)param_1);
            if ((*(char *)((longlong)param_1 + 0xdc6) != '\0') ||
               (*(char *)((longlong)param_1 + 0xdc5) == '\0')) goto LAB_140002909;
            *(undefined2 *)((longlong)param_1 + 0xdc5) = 0x100;
            FlushAllDPMPage0((longlong)param_1,1);
            if ((*(uint *)((longlong)param_1 + 0xdec) & 0x2000) == 0) {
              KickStart((longlong)param_1,1);
            }
            else {
              IssueReset((longlong)param_1,0x40);
            }
          } while( true );
        }
        uVar21 = 0xad010018;
      }
      goto LAB_1400029a3;
    }
  }
  uVar21 = 0xad010001;
LAB_1400029a3:
  StorPortLogError(param_1,0,0,0,(ulonglong)in_stack_ffffffffffffff88 & 0xffffffffffffff00,6,uVar21)
  ;
  return 0;
}



===== LSImpiOSReset @ 1400029f0 =====

longlong LSImpiOSReset(longlong param_1,uint param_2)

{
  longlong lVar1;
  uint local_res10 [6];
  undefined4 local_18 [2];
  uint *local_10;
  
  local_18[0] = 6;
  if (param_2 < *(ushort *)(param_1 + 0x5a0)) {
    local_10 = local_res10;
    local_res10[0] = param_2;
    lVar1 = StorPortSynchronizeAccess(param_1,SynchronizeReset,local_18);
    return lVar1;
  }
  return (ulonglong)(byte)(*(ushort *)(param_1 + 0x5a0) >> 8) << 8;
}



===== LSImpiStartIo @ 140002a40 =====

ulonglong LSImpiStartIo(longlong param_1,ushort *param_2)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  int *piVar4;
  undefined8 *puVar5;
  int iVar6;
  ulonglong uVar7;
  longlong *plVar8;
  undefined8 uVar9;
  ushort uVar10;
  undefined4 uVar11;
  byte local_res8 [8];
  undefined1 *in_stack_ffffffffffffffa8;
  undefined1 *puVar12;
  undefined4 local_38 [2];
  ushort *local_30;
  
  piVar4 = *(int **)(param_2 + 0x34);
  local_38[0] = 4;
  if ((char)param_2[1] != '(') {
    *(undefined1 *)((longlong)param_2 + 3) = 0x22;
    uVar7 = StorPortNotification(0,param_1,param_2);
    return uVar7 & 0xffffffffffffff00;
  }
  local_res8[0] = *(byte *)((longlong)piVar4 + 0x52);
  uVar10 = (ushort)local_res8[0];
  iVar6 = piVar4[0x15];
  cVar1 = (char)piVar4[0x14];
  bVar2 = *(byte *)((longlong)piVar4 + 0x51);
  puVar12 = (undefined1 *)((longlong)piVar4 + 0x52);
  local_30 = param_2;
  switch(*(undefined4 *)(param_2 + 10)) {
  case 0:
    if ((*(char *)(param_1 + 0xdd0) == '\0') ||
       (*(undefined1 *)(param_1 + 0xdd0) = 0, cVar1 != '\x03')) {
      puVar5 = (undefined8 *)**(longlong **)(param_1 + 0x510);
      if (*(char *)(param_1 + 0xdb4) == '\0') {
        if ((*(int *)(param_1 + 0x568) == 0) && (*(int *)(param_1 + 0xdf8) == 0)) {
          if (puVar5[1] == 0) {
            plVar8 = *(longlong **)(param_1 + 0x510) + 1;
            *(longlong **)(param_1 + 0x510) = plVar8;
            if (plVar8 == *(longlong **)(param_1 + 0x520)) {
              *(undefined8 *)(param_1 + 0x510) = *(undefined8 *)(param_1 + 0x508);
            }
            uVar10 = *(ushort *)(puVar5 + 2);
            puVar5[1] = param_2;
            *(byte *)((longlong)puVar5 + 0x12) = local_res8[0];
            uVar3 = *(ushort *)(piVar4 + 0x56);
            *(ushort *)((longlong)puVar5 + 0x14) = uVar3;
            *(char *)((longlong)puVar5 + 0x16) = (char)iVar6;
            *(char *)((longlong)puVar5 + 0x17) = (char)param_2[0x10];
            if (cVar1 == '\x12') {
              if ((((bVar2 & 1) != 0) ||
                  (*(undefined1 *)((longlong)puVar5 + 0x13) = 4, *(char *)(param_1 + 0x308) == '\0')
                  ) || ((*(uint *)(param_1 + 0x30c) & 0x2000) == 0)) goto LAB_140002d62;
              uVar11 = 0x2000;
            }
            else {
              if (((cVar1 != -0x60) || (*(char *)(param_1 + 0x308) == '\0')) ||
                 ((*(uint *)(param_1 + 0x30c) & 0x2002) == 0)) goto LAB_140002d62;
              uVar11 = 0x2002;
            }
            RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),uVar11,puVar12,3,
                        4);
LAB_140002d62:
            memcpy((void *)*puVar5,piVar4 + 0x56,(ulonglong)*(ushort *)(param_1 + 0x240));
            **(int **)(param_1 + 0xe8) = (uint)uVar10 * 0x10000 + *piVar4;
            LOCK();
            UNLOCK();
            piVar4 = *(int **)(param_1 + 0xf0);
            *piVar4 = (uint)uVar3 << 0x10;
            LOCK();
            UNLOCK();
            *(undefined1 *)(param_1 + 0x56c) = 0;
            return CONCAT71((int7)((ulonglong)piVar4 >> 8),1);
          }
          *(undefined1 *)((longlong)param_2 + 3) = 5;
          StorPortBusy(param_1,10);
          if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x215) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x215,puVar12,3,4
                       );
            in_stack_ffffffffffffffa8 = puVar12;
          }
          if (*(short *)(param_1 + 0x560) != 0) {
            StorPortLogError(param_1,0,0,0,(ulonglong)in_stack_ffffffffffffffa8 & 0xffffffffffffff00
                             ,6,0xad010012);
          }
        }
        else {
          *(undefined1 *)((longlong)param_2 + 3) = 5;
          if ((*(char *)(param_1 + 0x56c) == '\0') &&
             ((*(undefined1 *)(param_1 + 0x56c) = 1, *(char *)(param_1 + 0x308) != '\0' &&
              ((*(uint *)(param_1 + 0x30c) & 0x214) != 0)))) {
            RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x214,puVar12,3,4
                       );
          }
        }
      }
      else {
        *(undefined1 *)((longlong)param_2 + 3) = 0x11;
        if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x213) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x213,puVar12,3,4);
        }
      }
    }
    else {
      memcpy(*(void **)(param_2 + 0x20),*(void **)(param_1 + 0xdd8),
             (ulonglong)*(uint *)(param_2 + 0x1e));
      *(undefined1 *)((longlong)param_2 + 3) = 1;
      *(undefined1 *)(*(longlong *)(piVar4 + 0xe) + 8) = 0;
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x409) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x409,puVar12,3,4);
      }
    }
    break;
  case 2:
    uVar9 = StorPortSynchronizeAccess(param_1,SynchronizeStartIoctl,local_38);
    return CONCAT71((int7)((ulonglong)uVar9 >> 8),1);
  case 7:
    if (*(int *)(param_1 + 0x570) != 0) {
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x80006) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x80006,
                    (undefined1 *)param_2,*(uint *)(param_2 + 8),4);
      }
      *(ushort **)(param_1 + 0x528) = param_2;
      CheckForIRShutdown(param_1,'\x01',4);
      *(undefined2 *)(param_1 + 0x3d48) = 3;
      SendAndProcessSSUCommands(param_1,4);
      *(undefined2 *)(param_1 + 0x3d48) = *(undefined2 *)(param_1 + 0x3d4c);
      return CONCAT71((uint7)(byte)((ushort)*(undefined2 *)(param_1 + 0x3d4c) >> 8),1);
    }
    goto LAB_140003130;
  case 0x12:
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x406) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x406,(undefined1 *)0x0
                  ,0,4);
      uVar10 = (ushort)local_res8[0];
    }
    if (uVar10 < *(ushort *)(param_1 + 0x5a0)) {
      local_30 = (ushort *)local_res8;
      *(ushort **)(param_1 + 0x530) = param_2;
      uVar9 = StorPortSynchronizeAccess(param_1,SynchronizeReset,local_38);
      return uVar9;
    }
    *(undefined1 *)((longlong)param_2 + 3) = 7;
    uVar7 = StorPortNotification(0,param_1,param_2);
    return uVar7 & 0xffffffffffffff00;
  case 0x13:
  case 0x20:
    uVar9 = StorPortSynchronizeAccess(param_1,SynchronizeLunTargetReset,local_38);
    return uVar9;
  case 0x17:
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x403) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x403,
                  (undefined1 *)param_2,0x80,4);
    }
    uVar9 = LSImpiWmiSrb(param_1,param_2,4);
    return uVar9;
  case 0x24:
    if (*(int *)(*(longlong *)(piVar4 + 0x10) + 0xc) == 4) {
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x80001) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x80001,
                    (undefined1 *)param_2,*(uint *)(param_2 + 8),4);
      }
      *(ushort **)(param_1 + 0x528) = param_2;
      uVar9 = CheckForIRShutdown(param_1,'\0',4);
      if ((char)uVar9 == '\0') {
        uVar11 = 0xd;
        if (*(short *)(param_1 + 0x3d48) != 0) {
          uVar11 = 8;
        }
        *(undefined4 *)(param_1 + 0xdf8) = uVar11;
        return 1;
      }
      goto LAB_140003142;
    }
  default:
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x217) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x217,
                  (undefined1 *)param_2,*(uint *)(param_2 + 8),4);
    }
LAB_140003130:
    *(undefined1 *)((longlong)param_2 + 3) = 0x22;
  }
  uVar9 = StorPortNotification(0,param_1,param_2);
LAB_140003142:
  return CONCAT71((int7)((ulonglong)uVar9 >> 8),1);
}



===== SynchronizeLunTargetReset @ 1400031a0 =====

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
  ulonglong in_RAX;
  ulonglong uVar9;
  undefined8 uVar10;
  ushort uVar11;
  undefined4 uVar12;
  undefined1 *in_stack_ffffffffffffffc8;
  
  lVar5 = *(longlong *)(param_2 + 2);
  pcVar1 = (char *)(param_1 + 0xdb9);
  iVar3 = *param_2;
  lVar6 = *(longlong *)(lVar5 + 0x68);
  *pcVar1 = '\x01';
  if (lVar6 == 0) {
    if ((*(char *)(param_1 + 0x308) != '\0') &&
       (in_RAX = (ulonglong)*(uint *)(param_1 + 0x30c), (*(uint *)(param_1 + 0x30c) & 0x23c) != 0))
    {
      in_RAX = RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x2d8),0x23c,(undefined1 *)0x0,0,iVar3);
    }
    uVar9 = in_RAX & 0xffffffffffffff00;
    goto LAB_14000366f;
  }
  if (*(int *)(lVar5 + 0x14) == 0x20) {
    if ((*(char *)(param_1 + 0x308) != '\0') &&
       (in_RAX = (ulonglong)*(uint *)(param_1 + 0x30c), (*(uint *)(param_1 + 0x30c) & 0x404) != 0))
    {
      uVar12 = 0x404;
LAB_140003219:
      in_stack_ffffffffffffffc8 = (undefined1 *)(lVar6 + 0x52);
      in_RAX = RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x2d8),uVar12,in_stack_ffffffffffffffc8,
                           3,iVar3);
    }
  }
  else if ((*(char *)(param_1 + 0x308) != '\0') &&
          (in_RAX = (ulonglong)*(uint *)(param_1 + 0x30c), (*(uint *)(param_1 + 0x30c) & 0x405) != 0
          )) {
    uVar12 = 0x405;
    goto LAB_140003219;
  }
  if (*(int *)(param_1 + 0xdf8) == 0) {
    if ((*(int *)(param_1 + 0x568) == 0) && (*(longlong *)(param_1 + 0x528) == 0)) {
      uVar11 = (ushort)*(byte *)(lVar6 + 0x52) * 0x80 + (ushort)*(byte *)(lVar6 + 0x53);
      if (((uint)uVar11 < *(uint *)(param_1 + 0x5b8)) &&
         (uVar11 = *(ushort *)(*(longlong *)(param_1 + 0x2c8) + 0x1a + (ulonglong)uVar11 * 0x28),
         uVar11 != 0)) {
        if (*(int *)(param_1 + 0x570) == 0) {
          StorPortPause(param_1,300);
        }
        *(longlong *)(param_1 + 0x528) = lVar5;
        ResetActive(param_1,10,iVar3);
        uVar4 = *(uint *)(lVar5 + 0x14);
        in_RAX = (ulonglong)uVar4;
        if (uVar4 == 0x13) {
          if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x20006) != 0))
          {
            RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x2d8),0x20006,(byte *)(lVar6 + 0x52),3,
                        iVar3);
          }
          puVar7 = *(ushort **)(param_1 + 0x270);
          ZeroMemory((undefined1 *)puVar7,0x34);
          *puVar7 = uVar11;
          *(undefined1 *)((longlong)puVar7 + 3) = 1;
          *(undefined1 *)((longlong)puVar7 + 5) = 3;
          **(int **)(param_1 + 0xe8) = (uint)*(ushort *)(param_1 + 0x5ae) * 0x10000 + 6;
          LOCK();
          UNLOCK();
          puVar8 = *(undefined4 **)(param_1 + 0xf0);
          *puVar8 = 0;
          LOCK();
          UNLOCK();
          uVar9 = CONCAT71((int7)((ulonglong)puVar8 >> 8),1);
          goto LAB_14000366f;
        }
        if (uVar4 == 0x20) {
          uVar10 = SendLunResetTur(param_1,uVar11,iVar3);
          uVar9 = CONCAT71((int7)((ulonglong)uVar10 >> 8),1);
          goto LAB_14000366f;
        }
      }
      else {
        *(undefined1 *)(lVar5 + 3) = 10;
        in_RAX = StorPortNotification(0,param_1,lVar5);
        if ((*(char *)(param_1 + 0x308) != '\0') &&
           (in_RAX = (ulonglong)*(uint *)(param_1 + 0x30c),
           (*(uint *)(param_1 + 0x30c) & 0x20012) != 0)) {
          uVar10 = RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x2d8),0x20012,(undefined1 *)0x0,0,
                               iVar3);
          uVar9 = CONCAT71((int7)((ulonglong)uVar10 >> 8),1);
          goto LAB_14000366f;
        }
      }
    }
    else if (lVar5 == *(longlong *)(param_1 + 0x528)) {
      if ((*(char *)(param_1 + 0x308) != '\0') &&
         (in_RAX = (ulonglong)*(uint *)(param_1 + 0x30c),
         (*(uint *)(param_1 + 0x30c) & 0x20003) != 0)) {
        in_RAX = RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x2d8),0x20003,(undefined1 *)0x0,0,
                             iVar3);
      }
    }
    else {
      uVar11 = 0;
      do {
        in_RAX = (ulonglong)uVar11;
        if (*(longlong *)(param_1 + 0xfc0 + in_RAX * 8) == lVar5) {
          if ((*(char *)(param_1 + 0x308) == '\0') ||
             (in_RAX = (ulonglong)*(uint *)(param_1 + 0x30c),
             (*(uint *)(param_1 + 0x30c) & 0x20004) == 0)) goto LAB_140003469;
          uVar10 = RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x2d8),0x20004,(undefined1 *)0x0,0,
                               iVar3);
          uVar9 = CONCAT71((int7)((ulonglong)uVar10 >> 8),1);
          goto LAB_14000366f;
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 < 100);
      bVar2 = *(byte *)(param_1 + 0xebc);
      if (*(longlong *)(param_1 + 0xfc0 + (ulonglong)bVar2 * 8) != 0) {
        if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x216) != 0)) {
          in_stack_ffffffffffffffc8 = (undefined1 *)0x0;
          RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x2d8),0x216,(undefined1 *)0x0,0,iVar3);
        }
        StorPortLogError(param_1,0,0,0,(ulonglong)in_stack_ffffffffffffffc8 & 0xffffffffffffff00,6,
                         0xad01003a);
        goto LAB_14000353b;
      }
      *(longlong *)(param_1 + 0xfc0 + (ulonglong)bVar2 * 8) = lVar5;
      in_RAX = 0;
      if ((byte)(bVar2 + 1) != 100) {
        in_RAX = (ulonglong)(byte)(bVar2 + 1);
      }
      *(char *)(param_1 + 0xebc) = (char)in_RAX;
      if ((*(char *)(param_1 + 0x308) != '\0') &&
         (in_RAX = (ulonglong)*(uint *)(param_1 + 0x30c),
         (*(uint *)(param_1 + 0x30c) >> 0x11 & 1) != 0)) {
        uVar12 = 0x20000;
        goto LAB_1400035c6;
      }
    }
LAB_140003469:
    uVar9 = CONCAT71((int7)(in_RAX >> 8),1);
  }
  else {
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x20002) != 0)) {
      RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x2d8),0x20002,(undefined1 *)0x0,0,iVar3);
    }
LAB_14000353b:
    uVar9 = 0;
    do {
      in_RAX = uVar9;
      if (*(longlong *)(param_1 + 0xfc0 + in_RAX * 8) == lVar5) goto LAB_1400035a2;
      uVar11 = (short)in_RAX + 1;
      uVar9 = (ulonglong)uVar11;
    } while (uVar11 < 100);
    if (lVar5 == *(longlong *)(param_1 + 0x528)) {
LAB_1400035a2:
      if ((*(char *)(param_1 + 0x308) == '\0') ||
         (in_RAX = (ulonglong)*(uint *)(param_1 + 0x30c), (*(uint *)(param_1 + 0x30c) & 0x23b) == 0)
         ) goto LAB_140003469;
      uVar12 = 0x23b;
    }
    else {
      *(undefined1 *)(lVar5 + 3) = 4;
      in_RAX = StorPortNotification(0,param_1,lVar5);
      if ((*(char *)(param_1 + 0x308) == '\0') ||
         (in_RAX = (ulonglong)*(uint *)(param_1 + 0x30c),
         (*(uint *)(param_1 + 0x30c) & 0x20012) == 0)) goto LAB_140003469;
      uVar12 = 0x20012;
    }
LAB_1400035c6:
    uVar10 = RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x2d8),uVar12,(undefined1 *)0x0,0,iVar3);
    uVar9 = CONCAT71((int7)((ulonglong)uVar10 >> 8),1);
  }
LAB_14000366f:
  *pcVar1 = '\0';
  return uVar9;
}



===== SynchronizeStartIoctl @ 140003690 =====

ulonglong SynchronizeStartIoctl(longlong param_1,int *param_2)

{
  char *pcVar1;
  byte bVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  char cVar7;
  
  iVar3 = *param_2;
  pcVar1 = (char *)(param_1 + 0xdb9);
  puVar4 = *(undefined1 **)(param_2 + 2);
  *pcVar1 = '\x01';
  if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) >> 0x16 & 1) != 0)) {
    RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x2d8),0x400000,(undefined1 *)0x0,0,iVar3);
  }
  if ((*(char *)(param_1 + 0xda6) == '\0') && (*(char *)(param_1 + 0xdb6) == '\0')) {
    if ((((*(char *)(param_1 + 0xdfe) != '\0') || (*(int *)(param_1 + 0x568) != 0)) ||
        (*(int *)(param_1 + 0xdf8) != 0)) || (*(char *)(param_1 + 0x14f8) != '\0')) {
      bVar2 = *(byte *)(param_1 + 0xeba);
      if ((*(int *)(param_1 + 0xdf8) == 0) &&
         (*(longlong *)(param_1 + 0xec0 + (ulonglong)bVar2 * 8) == 0)) {
        *(undefined1 **)(param_1 + 0xec0 + (ulonglong)bVar2 * 8) = puVar4;
        *pcVar1 = '\0';
        cVar7 = '\0';
        if ((byte)(bVar2 + 1) != ' ') {
          cVar7 = bVar2 + 1;
        }
        *(char *)(param_1 + 0xeba) = cVar7;
        return 0;
      }
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x204) != 0)) {
        RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x2d8),0x204,puVar4,0x58,iVar3);
      }
      puVar4[3] = 5;
      uVar6 = StorPortNotification(0,param_1,puVar4);
      *pcVar1 = '\0';
      return uVar6 & 0xffffffffffffff00;
    }
    uVar5 = LsiHandleAppRequest(param_1,puVar4,iVar3);
    uVar6 = CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
  }
  else {
    puVar4[3] = 5;
    uVar6 = StorPortNotification(0,param_1,puVar4);
    uVar6 = uVar6 & 0xffffffffffffff00;
  }
  *pcVar1 = '\0';
  return uVar6;
}



===== CheckSmartInfo @ 140003810 =====

void CheckSmartInfo(longlong param_1,longlong param_2,longlong param_3,undefined2 param_4,
                   int param_5)

{
  undefined4 *puVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  char cVar5;
  ushort uVar6;
  uint uVar7;
  longlong lVar8;
  undefined2 *puVar9;
  char cVar10;
  uint local_res10 [2];
  uint local_res18 [2];
  ulonglong in_stack_ffffffffffffffb8;
  
  lVar8 = *(longlong *)(param_2 + 0x68);
  bVar2 = *(byte *)(lVar8 + 0x52);
  bVar3 = *(byte *)(lVar8 + 0x53);
  uVar4 = *(undefined1 *)(lVar8 + 0x54);
  if (*(char *)(param_3 + 0xc) == ']') {
    uVar6 = (ushort)bVar2 * 0x80 + (ushort)bVar3;
    if ((((uint)uVar6 < *(uint *)(param_1 + 0x5b8)) &&
        (puVar1 = (undefined4 *)(*(longlong *)(param_1 + 0x2c8) + (ulonglong)uVar6 * 0x28),
        *(short *)(*(longlong *)(param_1 + 0x2c8) + 0x1a + (ulonglong)uVar6 * 0x28) != 0)) &&
       ((puVar1[5] & 0x680) != 0)) {
      if ((*(uint *)(param_1 + 0xdec) & 0x1000) != 0) {
        GetIrMapRange(param_1,(int *)local_res10,(int *)local_res18);
        uVar7 = (uint)bVar2 * 0x80 + (uint)bVar3;
        if ((local_res10[0] <= uVar7) && (uVar7 <= local_res18[0])) {
          return;
        }
      }
      if (*(char *)(param_1 + 0xda8) != '\0') {
        puVar1[5] = puVar1[5] | 0x80000000;
      }
      if ((*(uint *)(param_1 + 0xd90) & 0x8000) != 0) {
        bVar2 = *(byte *)(param_1 + 0xda4);
        lVar8 = (ulonglong)bVar2 * 200;
        puVar9 = (undefined2 *)(param_1 + 0x1638 + lVar8);
        *(undefined4 *)(lVar8 + 0x1630 + param_1) = 0xf;
        *(int *)(param_1 + 0xda0) = *(int *)(param_1 + 0xda0) + 1;
        *(undefined4 *)(lVar8 + 0x1634 + param_1) = *(undefined4 *)(param_1 + 0xda0);
        ZeroMemory((undefined1 *)puVar9,0xc0);
        *(undefined1 *)(puVar9 + 1) = 5;
        *puVar9 = 0xffff;
        cVar10 = bVar2 + 1;
        *(undefined1 *)(puVar9 + 2) = 0x5d;
        *(undefined1 *)((longlong)puVar9 + 5) = *(undefined1 *)(param_3 + 0xd);
        puVar9[3] = param_4;
        *(undefined4 *)(puVar9 + 6) = *puVar1;
        *(undefined4 *)(puVar9 + 8) = puVar1[1];
        *(undefined1 *)((longlong)puVar9 + 0x15) = uVar4;
        cVar5 = '\0';
        if (cVar10 != '2') {
          cVar5 = cVar10;
        }
        *(char *)(param_1 + 0xda4) = cVar5;
        if (*(char *)(param_1 + 0x14b1) != '\0') {
          ScsiPortWmiFireLogicalUnitEvent
                    (param_1,-1,0,0,(int *)&MegaSASWmiMpiEventGuid,0,0x10,(int *)(param_1 + 0x198));
        }
      }
      if (*(char *)(param_1 + 0xda8) != '\0') {
        SendSEPMessage(param_1,0x40,param_4,param_5);
      }
    }
    else {
      StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffffb8 & 0xffffffffffffff00,6,0xad01003f);
    }
  }
  return;
}



===== ConvertSenseDataFormat @ 140003a30 =====

int ConvertSenseDataFormat(char *param_1)

{
  if ((byte)(*param_1 + 0x8eU) < 2) {
    *param_1 = *param_1 + -2;
    ZeroMemory(param_1 + 4,0xe);
    param_1[0xc] = param_1[2];
    param_1[0xd] = param_1[3];
    param_1[2] = param_1[1];
    param_1[3] = '\0';
    param_1[1] = '\0';
    param_1[7] = '\n';
    return 0x12;
  }
  if (0xf4 < (byte)param_1[7]) {
    param_1[7] = -0xc;
  }
  return (byte)param_1[7] + 8;
}



===== FindMappingTableEntry @ 140003aa0 =====

longlong FindMappingTableEntry(longlong param_1,short param_2,short param_3,uint param_4)

{
  longlong lVar1;
  ushort uVar2;
  
  uVar2 = param_2 * 0x80 + param_3;
  if (((*(uint *)(param_1 + 0x5b8) <= (uint)uVar2) ||
      (lVar1 = *(longlong *)(param_1 + 0x2c8) + (ulonglong)uVar2 * 0x28,
      *(short *)(*(longlong *)(param_1 + 0x2c8) + 0x1a + (ulonglong)uVar2 * 0x28) == 0)) ||
     ((*(uint *)(lVar1 + 0x14) & param_4) == 0)) {
    lVar1 = 0;
  }
  return lVar1;
}



===== HandleFwDiagReply @ 140003af0 =====

void HandleFwDiagReply(longlong param_1,longlong param_2,int param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  ushort uVar4;
  
  if (*(char *)(param_2 + 3) == '\x1d') {
    *(undefined1 *)(param_1 + 0xdbd) = 0;
    uVar4 = *(ushort *)(param_2 + 0xe) & 0x7fff;
    lVar1 = param_1 + (ulonglong)*(byte *)(param_2 + 1) * 0x18 + 0x12e0;
    if (uVar4 == 0xa0) {
      *(undefined2 *)(lVar1 + 0x11) = 1;
      *(undefined1 *)(lVar1 + 0xf) = 0;
    }
    else {
      *(undefined2 *)(lVar1 + 0x11) = 0x101;
      if (uVar4 != 0) {
        *(undefined2 *)(lVar1 + 0x11) = 0;
        StorPortLogError(param_1,0,0,0,0,6,0xad01002a);
      }
    }
    if ((*(char *)(lVar1 + 0xf) != '\0') || (uVar4 == 0xa0)) goto LAB_140003c4b;
    lVar1 = *(longlong *)(param_1 + 0x1350);
    if (lVar1 == 0) {
      return;
    }
    if (*(int *)(*(longlong *)(lVar1 + 0x40) + 0x10) != -0x7f9b969f) goto LAB_140003c4b;
    *(uint *)(*(longlong *)(lVar1 + 0x40) + 0x14) = -(uint)(uVar4 != 0) & 0x10;
    *(undefined1 *)(lVar1 + 3) = 1;
    StorPortNotification(0,param_1);
  }
  else {
    if (*(char *)(param_2 + 3) != '\x1e') goto LAB_140003c4b;
    lVar2 = *(longlong *)(param_1 + 0x1350);
    lVar1 = param_1 + (ulonglong)*(byte *)(param_2 + 1) * 0x18;
    if (lVar2 == 0) {
      return;
    }
    lVar3 = *(longlong *)(lVar2 + 0x40);
    if (((*(ushort *)(param_2 + 0xe) & 0x7fff) == 0) && (*(char *)(lVar1 + 0x12f2) == '\0')) {
      *(undefined4 *)(lVar3 + 0x14) = 0;
    }
    else {
      *(undefined4 *)(lVar3 + 0x14) = 0x12;
    }
    if (*(int *)(lVar3 + 0x1c) == 2) {
      *(undefined4 *)(lVar1 + 0x12f4) = 0;
    }
    *(undefined1 *)(lVar2 + 3) = 1;
    StorPortNotification(0,param_1);
  }
  *(undefined8 *)(param_1 + 0x1350) = 0;
LAB_140003c4b:
  *(undefined1 *)(param_1 + 0xdfe) = 0;
  CheckIoctlQueue(param_1,param_3);
  return;
}



===== LSImpiMSIIsr @ 140003c90 =====

ulonglong LSImpiMSIIsr(longlong param_1,byte param_2)

{
  ushort uVar1;
  int iVar2;
  char cVar3;
  ushort uVar4;
  ulonglong in_RAX;
  undefined8 uVar5;
  longlong lVar6;
  ulonglong uVar7;
  longlong *plVar8;
  byte *pbVar9;
  short sVar10;
  ushort *puVar11;
  ushort uVar12;
  longlong lVar13;
  longlong lVar14;
  ushort uVar15;
  byte bVar16;
  char local_res8 [8];
  ushort local_res18 [4];
  short local_res20;
  uint *in_stack_ffffffffffffff88;
  uint7 uVar17;
  uint local_54;
  uint local_50;
  longlong local_48;
  ushort *local_40;
  
  iVar2 = *(int *)(param_1 + 0x500);
  uVar1 = *(ushort *)(param_1 + 0x246);
  lVar13 = 0;
  lVar14 = 0;
  if ((*(char *)(param_1 + 0xdb7) != '\0') ||
     ((*(int *)(param_1 + 0xdf8) != 0 && (*(char *)(param_1 + 0xdb9) == '\0')))) {
    return in_RAX & 0xffffffffffffff00;
  }
  bVar16 = 0;
  if (*(char *)(param_1 + 0x12a) != '\0') {
    bVar16 = param_2;
  }
  local_40 = (ushort *)(param_1 + 0x21a + (ulonglong)bVar16 * 2);
  uVar7 = (ulonglong)*local_40;
  local_48 = *(longlong *)(param_1 + 600) + (ulonglong)uVar1 * (ulonglong)bVar16 * 8;
  local_res20 = 0;
  pbVar9 = (byte *)(local_48 + uVar7 * 8);
  local_50 = (uint)bVar16;
  if (*(int *)(local_48 + uVar7 * 8) != -1) {
    do {
      sVar10 = local_res20;
      uVar15 = (ushort)uVar7;
      if (*(int *)(pbVar9 + 4) == -1) break;
      local_res18[0] = *(ushort *)(pbVar9 + 2);
      if (local_res18[0] != 0) {
        lVar13 = *(longlong *)
                  (*(longlong *)(param_1 + 0x2a0) + 8 + (ulonglong)local_res18[0] * 0x18);
        lVar14 = *(longlong *)(param_1 + 0x2a0) + (ulonglong)local_res18[0] * 0x18;
      }
      bVar16 = *pbVar9 & 0xf;
      if ((bVar16 == 0) && (*(char *)(lVar14 + 0x13) == '\0')) {
        if (lVar13 == 0) {
          if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x219) != 0)) {
            in_stack_ffffffffffffff88 = (uint *)local_res18;
            RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x219,
                        (undefined1 *)in_stack_ffffffffffffff88,2,iVar2);
          }
          in_stack_ffffffffffffff88 =
               (uint *)((ulonglong)in_stack_ffffffffffffff88 & 0xffffffffffffff00);
          StorPortLogError(param_1);
        }
        else {
          **(longlong **)(param_1 + 0x518) = lVar14;
          *(longlong *)(param_1 + 0x518) = *(longlong *)(param_1 + 0x518) + 8;
          if (*(longlong *)(param_1 + 0x518) == *(longlong *)(param_1 + 0x520)) {
            *(undefined8 *)(param_1 + 0x518) = *(undefined8 *)(param_1 + 0x508);
          }
          *(undefined8 *)(lVar14 + 8) = 0;
          *(undefined1 *)(*(longlong *)(*(longlong *)(lVar13 + 0x68) + 0x38) + 8) = 0;
          *(undefined1 *)(lVar13 + 3) = 1;
          StorPortNotification(0);
        }
        pbVar9[0] = 0xff;
        pbVar9[1] = 0xff;
        pbVar9[2] = 0xff;
        pbVar9[3] = 0xff;
        pbVar9[4] = 0xff;
        pbVar9[5] = 0xff;
        pbVar9[6] = 0xff;
        pbVar9[7] = 0xff;
        local_res20 = sVar10 + 1;
        uVar7 = 0;
        if ((ushort)(uVar15 + 1) != uVar1) {
          uVar7 = (ulonglong)(ushort)(uVar15 + 1);
        }
        goto LAB_1400045e4;
      }
      if (local_res18[0] != 0) {
        uVar5 = CheckMpiIoctlReply(param_1,pbVar9,iVar2);
        if ((char)uVar5 != '\0') {
          if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x107) != 0)) {
            in_stack_ffffffffffffff88 = (uint *)local_res18;
            RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x107,
                        (undefined1 *)in_stack_ffffffffffffff88,2,iVar2);
          }
          goto LAB_1400044a0;
        }
        uVar5 = CheckInqFlagReplies(param_1,local_res8,pbVar9,iVar2);
        if ((char)uVar5 == '\0') {
          lVar6 = CheckSsuReplies(param_1,(longlong)pbVar9);
          if ((char)lVar6 == '\0') {
            lVar6 = CheckSsuTmrReplies(param_1,(longlong)pbVar9);
            if ((char)lVar6 == '\0') {
              uVar5 = CheckTurReplies(param_1,pbVar9,iVar2);
              if ((char)uVar5 == '\0') goto LAB_140004131;
              if ((*(char *)(param_1 + 0x308) != '\0') &&
                 ((*(uint *)(param_1 + 0x30c) & 0x10c) != 0)) {
                in_stack_ffffffffffffff88 = (uint *)local_res18;
                RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x10c,
                            (undefined1 *)in_stack_ffffffffffffff88,2,iVar2);
              }
            }
            else if ((*(char *)(param_1 + 0x308) != '\0') &&
                    ((*(uint *)(param_1 + 0x30c) & 0x10b) != 0)) {
              in_stack_ffffffffffffff88 = (uint *)local_res18;
              RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x10b,
                          (undefined1 *)in_stack_ffffffffffffff88,2,iVar2);
            }
          }
          else if ((*(char *)(param_1 + 0x308) != '\0') &&
                  ((*(uint *)(param_1 + 0x30c) & 0x10a) != 0)) {
            in_stack_ffffffffffffff88 = (uint *)local_res18;
            RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x10a,
                        (undefined1 *)in_stack_ffffffffffffff88,2,iVar2);
          }
          goto LAB_1400044a0;
        }
        if (local_res8[0] != '\0') {
          if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x108) != 0)) {
            in_stack_ffffffffffffff88 = (uint *)local_res18;
            RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x108,
                        (undefined1 *)in_stack_ffffffffffffff88,2,iVar2);
          }
          goto LAB_1400044a0;
        }
        if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x109) != 0)) {
          in_stack_ffffffffffffff88 = (uint *)local_res18;
          RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x109,
                      (undefined1 *)in_stack_ffffffffffffff88,2,iVar2);
        }
        goto LAB_140004503;
      }
LAB_140004131:
      uVar17 = (uint7)((ulonglong)in_stack_ffffffffffffff88 >> 8);
      if (bVar16 != 1) {
        in_stack_ffffffffffffff88 = (uint *)((ulonglong)uVar17 << 8);
        StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffff88,6,0xad010022);
        if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x239) != 0)) {
          in_stack_ffffffffffffff88 = (uint *)0x0;
          RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x239,
                      (undefined1 *)0x0,0,iVar2);
        }
        goto LAB_1400045c2;
      }
      puVar11 = (ushort *)((ulonglong)*(uint *)(pbVar9 + 4) + *(longlong *)(param_1 + 0x100));
      local_54 = *(uint *)(puVar11 + 8);
      if (((((local_54 != 0) && ((short)puVar11[7] < 0)) && (local_54 != 0x30030501)) &&
          ((local_54 != 0x30030101 && (local_54 != 0x31180000)))) &&
         ((local_54 != 0x30070001 && ((local_54 & 0xffff0000) != 0x31170000)))) {
        if ((*(short *)(param_1 + 0x560) != 0) ||
           (uVar12 = *(ushort *)(param_1 + 0x562), *(ushort *)(param_1 + 0x562) = uVar12 + 1,
           uVar12 < 0x14)) {
          in_stack_ffffffffffffff88 = (uint *)((ulonglong)uVar17 << 8);
          StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffff88,6,local_54);
        }
        if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x238) != 0)) {
          in_stack_ffffffffffffff88 = &local_54;
          RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x238,
                      (undefined1 *)in_stack_ffffffffffffff88,4,iVar2);
        }
      }
      switch(*(undefined1 *)((longlong)puVar11 + 3)) {
      case 1:
        if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x806) != 0)) {
          in_stack_ffffffffffffff88 = (uint *)local_res18;
          RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x806,
                      (undefined1 *)in_stack_ffffffffffffff88,2,iVar2);
        }
        if (((*(char *)((longlong)puVar11 + 5) != '\x02') || (local_res18[0] == 0)) ||
           (-1 < *(char *)(*(longlong *)(param_1 + 0x2a0) + 0x13 + (ulonglong)local_res18[0] * 0x18)
           )) goto LAB_1400042dd;
        lVar6 = *(longlong *)(lVar13 + 0x68);
        in_stack_ffffffffffffff88 =
             (uint *)CONCAT71((int7)((ulonglong)in_stack_ffffffffffffff88 >> 8),
                              *(byte *)(lVar6 + 0x53));
        uVar5 = HandleUnitAttenReset
                          (param_1,local_res18[0],(undefined8 *)puVar11,*(byte *)(lVar6 + 0x52),
                           *(byte *)(lVar6 + 0x53),*(char *)(lVar6 + 0x54),'\0',iVar2);
        if ((char)uVar5 == '\0') break;
        goto LAB_14000450d;
      default:
        uVar5 = LsiCompleteIO(param_1,(short *)puVar11,local_res18[0],iVar2);
        cVar3 = (char)uVar5;
LAB_140004494:
        if (cVar3 == '\0') goto LAB_14000450d;
        break;
      case 4:
        if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x808) != 0)) {
          in_stack_ffffffffffffff88 = (uint *)local_res18;
          RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x808,
                      (undefined1 *)in_stack_ffffffffffffff88,2,iVar2);
        }
        if ((*(byte *)(*(longlong *)(param_1 + 0x2a0) + 0x13 + (ulonglong)local_res18[0] * 0x18) & 8
            ) != 0) {
          uVar5 = HbaApiWmiCompletion(param_1,(longlong)puVar11,local_res18[0],iVar2);
          cVar3 = (char)uVar5;
          goto LAB_140004494;
        }
        goto LAB_1400042dd;
      case 7:
        HandleEventNotification(param_1,puVar11,iVar2);
        break;
      case 0x1b:
        if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x805) != 0)) {
          in_stack_ffffffffffffff88 = (uint *)local_res18;
          RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x805,
                      (undefined1 *)in_stack_ffffffffffffff88,2,iVar2);
        }
LAB_1400042dd:
        NonSCB_Func_handler(param_1,(short *)puVar11,local_res18[0],iVar2);
        break;
      case 0x1d:
      case 0x1e:
        if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x807) != 0)) {
          in_stack_ffffffffffffff88 = (uint *)local_res18;
          RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x807,
                      (undefined1 *)in_stack_ffffffffffffff88,2,iVar2);
        }
        HandleFwDiagReply(param_1,(longlong)puVar11,iVar2);
      }
      sVar10 = local_res20;
LAB_1400044a0:
      if ((local_res18[0] != 0) && (local_res18[0] <= *(ushort *)(param_1 + 0x594))) {
        lVar14 = *(longlong *)(param_1 + 0x2a0) + (ulonglong)local_res18[0] * 0x18;
        **(longlong **)(param_1 + 0x518) = lVar14;
        *(longlong *)(param_1 + 0x518) = *(longlong *)(param_1 + 0x518) + 8;
        if (*(longlong *)(param_1 + 0x518) == *(longlong *)(param_1 + 0x520)) {
          *(undefined8 *)(param_1 + 0x518) = *(undefined8 *)(param_1 + 0x508);
        }
        *(undefined1 *)(lVar14 + 0x13) = 0;
        *(undefined8 *)(lVar14 + 8) = 0;
      }
LAB_140004503:
      if (bVar16 == 1) {
LAB_14000450d:
        uVar12 = *(ushort *)(param_1 + 0x218);
        *(undefined4 *)(*(longlong *)(param_1 + 0x250) + (ulonglong)uVar12 * 4) =
             *(undefined4 *)(pbVar9 + 4);
        uVar12 = uVar12 + 1;
        uVar4 = 0;
        if (uVar12 != *(ushort *)(param_1 + 0x244)) {
          uVar4 = uVar12;
        }
        **(uint **)(param_1 + 0x58) = (uint)uVar4;
        LOCK();
        UNLOCK();
        *(ushort *)(param_1 + 0x218) = uVar4;
        sVar10 = local_res20;
      }
LAB_1400045c2:
      local_res20 = sVar10 + 1;
      pbVar9[0] = 0xff;
      pbVar9[1] = 0xff;
      pbVar9[2] = 0xff;
      pbVar9[3] = 0xff;
      pbVar9[4] = 0xff;
      pbVar9[5] = 0xff;
      pbVar9[6] = 0xff;
      pbVar9[7] = 0xff;
      uVar7 = (ulonglong)(ushort)(uVar15 + 1);
      if ((ushort)(uVar15 + 1) == uVar1) {
        uVar7 = 0;
      }
LAB_1400045e4:
      uVar15 = (ushort)uVar7;
      pbVar9 = (byte *)(local_48 + uVar7 * 8);
    } while (*(int *)(local_48 + uVar7 * 8) != -1);
    if (local_res20 != 0) {
      *local_40 = uVar15;
      plVar8 = (longlong *)(ulonglong)uVar15;
      **(uint **)(param_1 + 0x60) = local_50 << 0x18 | (uint)uVar15;
      LOCK();
      UNLOCK();
      if (*(char *)(param_1 + 0x129) == '\0') {
        plVar8 = (longlong *)(ulonglong)**(uint **)(param_1 + 0x60);
      }
      if (((*(char *)(param_1 + 0xdb5) != '\0') &&
          (plVar8 = *(longlong **)(param_1 + 0x518), plVar8 == *(longlong **)(param_1 + 0x510))) &&
         (plVar8 = (longlong *)*plVar8, plVar8[1] == 0)) {
        plVar8 = (longlong *)StorPortResume(param_1);
        *(undefined1 *)(param_1 + 0xdb5) = 0;
      }
      return CONCAT71((int7)((ulonglong)plVar8 >> 8),1);
    }
  }
  return uVar7 & 0xffffffffffffff00;
}



===== LsiCompleteIO @ 1400046d0 =====

undefined8 LsiCompleteIO(longlong param_1,short *param_2,ushort param_3,int param_4)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  undefined4 uVar12;
  char cVar13;
  byte local_res10 [8];
  ushort local_res18 [8];
  ushort *in_stack_ffffffffffffff88;
  ushort *puVar14;
  uint uVar15;
  ushort local_54 [2];
  uint local_50;
  undefined8 *local_48;
  byte *local_40;
  
  local_54[0] = param_2[7] & 0x7fff;
  local_res18[0] = param_3;
  if (*(char *)((longlong)param_2 + 3) != '\0') {
    uVar10 = NonSCB_Func_handler(param_1,param_2,param_3,param_4);
    return CONCAT71((int7)((ulonglong)uVar10 >> 8),1);
  }
  lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x2a0) + 8 + (ulonglong)param_3 * 0x18);
  local_48 = (undefined8 *)(*(longlong *)(param_1 + 0x2a0) + (ulonglong)param_3 * 0x18);
  if (lVar6 == 0) {
    if (param_3 != *(ushort *)(param_1 + 0x5ae)) {
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x219) != 0)) {
        in_stack_ffffffffffffff88 = local_res18;
        RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x219,
                    (undefined1 *)in_stack_ffffffffffffff88,2,param_4);
      }
      local_48 = (undefined8 *)
                 StorPortLogError(param_1,0,0,0,
                                  (ulonglong)in_stack_ffffffffffffff88 & 0xffffffffffffff00,6,
                                  0xad010024);
    }
    return CONCAT71((int7)((ulonglong)local_48 >> 8),1);
  }
  cVar13 = (char)param_2[6];
  lVar7 = *(longlong *)(lVar6 + 0x68);
  local_40 = (byte *)(lVar7 + 0x52);
  bVar1 = *local_40;
  local_res10[0] = *(byte *)(lVar7 + 0x53);
  cVar2 = *(char *)(lVar7 + 0x54);
  cVar3 = *(char *)(lVar7 + 0x50);
  lVar8 = *(longlong *)(lVar7 + 0x38);
  local_50 = *(uint *)(lVar6 + 0x18);
  switch(local_54[0]) {
  case 0:
  case 0x40:
    *(undefined1 *)(lVar6 + 3) = 1;
    break;
  case 1:
    *(undefined1 *)(lVar6 + 3) = 6;
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x225) != 0)) {
      uVar15 = 0;
      puVar14 = (ushort *)0x0;
      uVar12 = 0x225;
LAB_140004bb6:
      RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),uVar12,
                  (undefined1 *)puVar14,uVar15,param_4);
    }
    break;
  case 3:
  case 6:
  case 7:
  case 0x46:
  case 0x47:
  case 0x4a:
    *(undefined1 *)(lVar6 + 3) = 4;
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x227) != 0)) {
      uVar12 = 0x227;
LAB_140004ba0:
      puVar14 = local_54;
      uVar15 = 2;
      goto LAB_140004bb6;
    }
    break;
  default:
    *(undefined1 *)(lVar6 + 3) = 4;
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x228) != 0)) {
      uVar12 = 0x228;
      goto LAB_140004ba0;
    }
    break;
  case 0x42:
    *(undefined1 *)(lVar6 + 3) = 0x21;
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x21e) != 0)) {
      puVar14 = (ushort *)local_res10;
      uVar15 = 1;
      uVar12 = 0x21e;
      goto LAB_140004bb6;
    }
    break;
  case 0x43:
    *(undefined1 *)(lVar6 + 3) = 10;
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x21a) != 0)) {
      uVar15 = 0;
      puVar14 = (ushort *)0x0;
      uVar12 = 0x21a;
      goto LAB_140004bb6;
    }
    break;
  case 0x44:
    *(undefined1 *)(lVar6 + 3) = 0x12;
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x21b) != 0)) {
      uVar15 = 0;
      puVar14 = (ushort *)0x0;
      uVar12 = 0x21b;
      goto LAB_140004bb6;
    }
    break;
  case 0x45:
    if (((cVar13 - 8U & 0xdf) != 0) && ((*(byte *)((longlong)param_2 + 0xd) & 1) == 0)) {
      *(undefined1 *)(lVar6 + 3) = 0x12;
      *(undefined4 *)(lVar6 + 0x3c) = *(undefined4 *)(param_2 + 10);
    }
    break;
  case 0x48:
    cVar4 = *(char *)(param_1 + 0x1574);
    if ((((cVar4 - 3U & 0xfd) == 0) || ((cVar4 - 1U & 0xfa) != 0)) || (cVar4 == '\x05')) {
LAB_140004a5c:
      *(undefined1 *)(lVar6 + 3) = 0xe;
    }
    else {
      *(undefined1 *)(lVar6 + 3) = 2;
      if ((*(char *)(param_1 + 0x14fa) != '\0') && (*(int *)(lVar6 + 0x28) == 36000)) {
        *(undefined4 *)(lVar6 + 0x28) = 0x8c96;
      }
    }
    break;
  case 0x49:
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x21d) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x21d,(undefined1 *)0x0
                  ,0,param_4);
    }
  case 2:
    cVar13 = '\b';
    *(undefined1 *)(lVar6 + 3) = 5;
    if (*(int *)(lVar6 + 0x28) == 36000) {
      *(undefined4 *)(lVar6 + 0x28) = 35999;
    }
    break;
  case 0x4b:
    if (-1 < param_2[7]) {
LAB_140004a35:
      if ((*(char *)(param_1 + 0xdb5) == '\0') && (*(int *)(param_1 + 0x570) == 0)) {
        StorPortPause(param_1,0x1e);
        *(undefined1 *)(param_1 + 0xdb5) = 1;
      }
      goto LAB_140004a5c;
    }
    if ((*(uint *)(param_2 + 8) & 0xffff0000) == 0x31120000) {
      if (*(char *)(param_1 + 0xda7) == '\0') goto LAB_140004a35;
      *(undefined1 *)(lVar6 + 3) = 4;
      *(undefined4 *)(lVar6 + 0x28) = *(undefined4 *)(param_2 + 8);
    }
    else {
      if ((*(uint *)(param_2 + 8) & 0xffff0000) != 0x31170000) goto LAB_140004a35;
      *(undefined1 *)(lVar6 + 3) = 5;
      cVar13 = '\b';
    }
    break;
  case 0x4c:
    if ((*(char *)(param_1 + 0xdb5) == '\0') && (*(int *)(param_1 + 0x570) == 0)) {
      StorPortPause(param_1,0x1e);
      *(undefined1 *)(param_1 + 0xdb5) = 1;
    }
    *(undefined1 *)(lVar6 + 3) = 0xe;
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x21f) != 0)) {
      uVar15 = 0;
      puVar14 = (ushort *)0x0;
      uVar12 = 0x21f;
      goto LAB_140004bb6;
    }
    break;
  case 0x4d:
  case 0x4e:
  case 0x4f:
    *(undefined1 *)(lVar6 + 3) = 0xf;
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x226) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x226,(undefined1 *)0x0
                  ,0,param_4);
    }
    StorPortLogError(param_1,lVar6,bVar1,local_res10[0],cVar2,1,local_54[0]);
  }
  if (((*(byte *)((longlong)param_2 + 0xd) & 0x10) != 0) &&
     ((char)*(undefined4 *)(param_2 + 0xe) == '\x02')) {
    *(undefined1 *)
     (*(longlong *)(param_1 + 0x2c8) + 0x22 +
     ((ulonglong)bVar1 * 0x80 + (ulonglong)local_res10[0]) * 0x28) = 0;
  }
  bVar5 = *(byte *)((longlong)param_2 + 0xd);
  if ((bVar5 & 1) == 0) {
    if ((bVar5 & 2) == 0) {
      if ((((bVar5 & 0x10) != 0) && (*(char *)(lVar6 + 3) == '\x01')) &&
         (*(int *)(param_2 + 0xe) != 0)) {
        cVar13 = '\0';
        *(undefined1 *)(lVar6 + 3) = 4;
        if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x22a) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x22a,
                      (undefined1 *)(param_2 + 0xe),4,param_4);
        }
        goto LAB_140004e77;
      }
    }
    else {
      *(undefined1 *)(lVar6 + 3) = 4;
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x229) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x229,
                    (undefined1 *)0x0,0,param_4);
      }
    }
  }
  else if ((local_50 & 0x20) == 0) {
    *(undefined1 *)(lVar6 + 3) = 0x84;
    if ((cVar3 == -0x7b) || (cVar3 == -0x5f)) {
      uVar15 = *(uint *)(param_2 + 0xc);
    }
    else {
      uVar15 = ConvertSenseDataFormat((char *)(lVar7 + 0x58));
    }
    if (uVar15 < *(byte *)(lVar8 + 9)) {
      *(char *)(lVar8 + 9) = (char)uVar15;
    }
    memcpy(*(void **)(lVar8 + 0x10),(void *)(lVar7 + 0x58),(ulonglong)*(byte *)(lVar8 + 9));
    puVar9 = local_48;
    lVar7 = *(longlong *)(lVar8 + 0x10);
    if (((((cVar3 != -0x7b) && (cVar3 != -0x5f)) &&
         (CheckSmartInfo(param_1,lVar6,lVar7,*(undefined2 *)((longlong)local_48 + 0x14),param_4),
         (*(byte *)(lVar7 + 2) & 0xf) == 6)) &&
        ((*(char *)(lVar7 + 0xc) == ')' && (*(char *)(param_1 + 0xdce) != '\0')))) &&
       ((*(uint *)(*(longlong *)(param_1 + 0x2c8) + 0x14 +
                  ((ulonglong)bVar1 * 0x80 + (ulonglong)local_res10[0]) * 0x28) >> 10 & 1) != 0)) {
      *(char *)(lVar8 + 8) = cVar13;
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x2000b) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x2000b,local_40,3,
                    param_4);
      }
      uVar11 = HandleUnitAttenReset
                         (param_1,local_res18[0],(undefined8 *)*puVar9,bVar1,local_res10[0],cVar2,
                          '\x01',param_4);
      if ((char)uVar11 != '\0') {
        return uVar11 & 0xffffffffffffff00;
      }
    }
  }
  else {
    memcpy(*(void **)(param_1 + 0xdd8),(void *)(lVar7 + 0x58),0xff);
    *(undefined1 *)(param_1 + 0xdd0) = 1;
    *(undefined1 *)(lVar6 + 3) = 4;
  }
  if (((byte)(cVar13 - 0x18U) < 0x29) &&
     ((0x10000000401U >> ((ulonglong)(byte)(cVar13 - 0x18U) & 0x3f) & 1) != 0)) {
    *(undefined1 *)(lVar6 + 3) = 4;
  }
  else if ((cVar13 - 8U & 0xdf) == 0) {
    *(undefined1 *)(lVar6 + 3) = 5;
  }
LAB_140004e77:
  *(char *)(lVar8 + 8) = cVar13;
  uVar10 = StorPortNotification(0,param_1,lVar6);
  return CONCAT71((int7)((ulonglong)uVar10 >> 8),1);
}



===== PollLSImpiIsr @ 140004f40 =====

void PollLSImpiIsr(longlong param_1,undefined4 param_2)

{
  undefined4 local_18 [2];
  undefined8 local_10;
  
  *(undefined4 *)(param_1 + 0x500) = param_2;
  local_10 = 0;
  local_18[0] = param_2;
  GtfProcessTimers(param_1,local_18);
  LSImpiMSIIsr(param_1,0);
  *(undefined4 *)(param_1 + 0x500) = 5;
  return;
}



===== AddDevice @ 140004f80 =====

void AddDevice(longlong param_1,int param_2)

{
  undefined8 *puVar1;
  ushort uVar2;
  short sVar3;
  int *piVar4;
  ushort uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  char *pcVar8;
  int *piVar9;
  uint *puVar10;
  undefined8 *puVar11;
  int iVar12;
  uint uVar13;
  undefined8 *puVar14;
  longlong lVar15;
  uint uVar16;
  ulonglong uVar17;
  longlong lVar18;
  int iStackX_c;
  undefined1 *in_stack_ffffffffffffffb8;
  undefined4 uVar19;
  
  lVar18 = (ulonglong)*(uint *)(param_1 + 0x14e4) * 0x3cc + *(longlong *)(param_1 + 0x2b0);
  uVar17 = 0;
  if (*(char *)(lVar18 + 0x3c4) != '\0') {
    do {
      puVar11 = (undefined8 *)(uVar17 * 0x20 + lVar18);
      if (*(char *)((longlong)puVar11 + 0x1a) == '\x01') {
        uVar5 = *(ushort *)(param_1 + 0x14c0) & 0xe;
        if (uVar5 == 2) {
          pcVar8 = (char *)(*(longlong *)(param_1 + 0x2a8) + 0x18);
          uVar6 = 0;
          while (uVar5 = (ushort)uVar6, uVar5 < *(byte *)(param_1 + 0x14cc)) {
            if ((*(short *)(pcVar8 + -6) == *(short *)(lVar18 + 0x3c0)) && (*pcVar8 == '\0')) {
              if (uVar5 != 0xffff) {
                puVar14 = (undefined8 *)(uVar6 * 0x1c + *(longlong *)(param_1 + 0x2a8));
                if (*(int *)(puVar14 + 1) == -1) goto LAB_140005052;
                uVar5 = *(ushort *)((longlong)puVar11 + 0x16);
                uVar2 = *(ushort *)((longlong)puVar14 + 0x16);
                if ((uVar5 < uVar2) ||
                   ((int)((uVar2 - 1) + (uint)*(ushort *)((longlong)puVar14 + 0x14)) <
                    (int)(uint)uVar5)) {
                  in_stack_ffffffffffffffb8 =
                       (undefined1 *)((ulonglong)in_stack_ffffffffffffffb8 & 0xffffffffffffff00);
                  StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffffb8,6,0xad010053);
                  if ((*(char *)(param_1 + 0x308) != '\0') &&
                     ((*(uint *)(param_1 + 0x30c) & 0x23f) != 0)) {
                    in_stack_ffffffffffffffb8 = (undefined1 *)((longlong)puVar11 + 0x14);
                    RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x23f,
                                in_stack_ffffffffffffffb8,2,param_2);
                  }
                  goto LAB_14000550f;
                }
                uVar16 = *(int *)(puVar14 + 1) + ((uint)uVar5 - (uint)uVar2);
                puVar1 = (undefined8 *)(*(longlong *)(param_1 + 0x2c8) + (ulonglong)uVar16 * 0x28);
                *puVar1 = *puVar11;
                puVar1[1] = puVar11[1];
                *(short *)((longlong)puVar1 + 0x1c) = (short)(uVar16 >> 7);
                *(ushort *)((longlong)puVar1 + 0x1e) = (ushort)uVar16 & 0x7f;
                *(undefined2 *)((longlong)puVar1 + 0x1a) = *(undefined2 *)((longlong)puVar11 + 0x14)
                ;
                *(undefined1 *)(puVar1 + 4) = 0;
                *(undefined2 *)(puVar1 + 3) = *(undefined2 *)(puVar14 + 2);
                *(uint *)((longlong)puVar1 + 0x14) = *(uint *)(puVar11 + 2) | 0x30000000;
                *(undefined1 *)((longlong)puVar1 + 0x25) = *(undefined1 *)((longlong)puVar11 + 0x1c)
                ;
                *(undefined1 *)(param_1 + 0x2d0) = 1;
                if ((*(byte *)(param_1 + 0x14c0) & 1) == 0) {
                  uVar5 = *(ushort *)(puVar14 + 2);
                  if ((uVar5 == 0xffff) &&
                     (uVar5 = GetDPMPage0IndexFromID
                                        (param_1,*puVar14,*(uint *)((longlong)puVar14 + 0xc)),
                     uVar5 == 0xffff)) {
                    uVar6 = GetFirstFreeDPMPage0(param_1);
                    if ((short)uVar6 != -1) {
                      lVar15 = *(longlong *)(param_1 + 0x1520) + 8;
                      uVar7 = uVar6 & 0xffff;
                      *(undefined8 *)(lVar15 + uVar7 * 0x14) = *puVar14;
                      lVar15 = lVar15 + uVar7 * 0x14;
                      *(undefined2 *)(lVar15 + 10) = *(undefined2 *)(puVar14 + 1);
                      *(short *)(lVar15 + 8) = *(short *)((longlong)puVar14 + 0x14) << 4;
                      *(undefined4 *)(lVar15 + 0xc) = *(undefined4 *)((longlong)puVar14 + 0xc);
                      *(undefined1 *)(uVar7 + *(longlong *)(param_1 + 0x14d8)) = 1;
                      *(short *)(puVar14 + 2) = (short)uVar6;
                      *(undefined1 *)(uVar7 + *(longlong *)(param_1 + 0x14d0)) = 1;
                      *puVar11 = 0;
                      puVar11[1] = 0;
                      puVar11[2] = 0;
                      *(undefined4 *)(puVar11 + 3) = 0;
                      *(undefined1 *)((longlong)puVar11 + 0x1c) = 0;
                      *(undefined1 *)((longlong)puVar14 + 0x1b) = 1;
                      goto LAB_14000550f;
                    }
                    if ((*(char *)(param_1 + 0x3d51) != '\0') &&
                       (*(char *)(param_1 + 0x3d50) == '\0')) {
                      in_stack_ffffffffffffffb8 =
                           (undefined1 *)((ulonglong)in_stack_ffffffffffffffb8 & 0xffffffffffffff00)
                      ;
                      StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffffb8,6,0xad010045);
                      *(undefined1 *)(param_1 + 0x3d50) = 1;
                      *(undefined1 *)((longlong)puVar14 + 0x1b) = 1;
                      goto LAB_14000550f;
                    }
                  }
                  else {
                    *(ushort *)(puVar1 + 3) = uVar5;
                    *(ushort *)(puVar14 + 2) = uVar5;
                  }
                }
                *(undefined1 *)((longlong)puVar14 + 0x1b) = 1;
                goto LAB_14000550f;
              }
              break;
            }
            pcVar8 = pcVar8 + 0x1c;
            uVar6 = (ulonglong)(ushort)(uVar5 + 1);
          }
          uVar19 = 0xad010040;
LAB_140005063:
          in_stack_ffffffffffffffb8 =
               (undefined1 *)((ulonglong)in_stack_ffffffffffffffb8 & 0xffffffffffffff00);
          StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffffb8,6,uVar19);
        }
        else if (uVar5 == 0) {
          piVar4 = *(int **)(param_1 + 0x2c8);
          uVar16 = *(uint *)(param_1 + 0x5b8);
          iStackX_c = (int)((ulonglong)*puVar11 >> 0x20);
          piVar9 = piVar4;
          for (uVar6 = 0; (uint)uVar6 < uVar16; uVar6 = (ulonglong)((uint)uVar6 + 1)) {
            if ((*piVar9 == (int)*puVar11) && (piVar9[1] == iStackX_c)) goto LAB_140005311;
            piVar9 = piVar9 + 10;
          }
          uVar6 = 0xffffffff;
LAB_140005311:
          if ((int)uVar6 == -1) {
            uVar13 = *(uint *)(param_1 + 0x14f0);
            if (*(short *)(lVar18 + 0x3c2) != 0) {
              uVar13 = uVar13 + *(ushort *)(param_1 + 0x14be);
            }
            uVar6 = (ulonglong)uVar13;
            if (uVar13 < uVar16) {
              puVar10 = (uint *)(piVar4 + uVar6 * 10 + 5);
              do {
                if ((*puVar10 & 0x30000000) == 0) goto LAB_14000535d;
                uVar13 = (int)uVar6 + 1;
                uVar6 = (ulonglong)uVar13;
                puVar10 = puVar10 + 10;
              } while (uVar13 < uVar16);
            }
            uVar6 = 0xffffffff;
LAB_14000535d:
            if ((int)uVar6 == -1) {
              uVar7 = GetHighMissingMapTableIndex(param_1);
              uVar6 = uVar7 & 0xffffffff;
              if ((int)uVar7 == -1) {
LAB_140005052:
                if (*(char *)(param_1 + 0xdc6) != '\0') {
                  uVar19 = 0xad010027;
                  goto LAB_140005063;
                }
                *(undefined1 *)(param_1 + 0xdc5) = 1;
                goto LAB_14000550f;
              }
              sVar3 = *(short *)((longlong)piVar4 + uVar6 * 0x28 + 0x1a);
              if (sVar3 != 0) {
                AddToRemovalTable(param_1,sVar3,0,param_2);
                *(undefined1 *)(param_1 + 0xdc3) = 1;
              }
              *(undefined1 *)((longlong)piVar4 + uVar6 * 0x28 + 0x21) = 0;
            }
          }
          piVar4 = (int *)(*(longlong *)(param_1 + 0x2c8) + uVar6 * 0x28);
          *(undefined8 *)piVar4 = *puVar11;
          *(undefined8 *)(piVar4 + 2) = puVar11[1];
          *(short *)(piVar4 + 7) = (short)((uint)uVar6 >> 7);
          *(ushort *)((longlong)piVar4 + 0x1e) = (ushort)uVar6 & 0x7f;
          *(undefined2 *)((longlong)piVar4 + 0x1a) = *(undefined2 *)((longlong)puVar11 + 0x14);
          *(undefined1 *)(piVar4 + 8) = 0;
          piVar4[5] = *(uint *)(puVar11 + 2) | 0x30000000;
          *(undefined1 *)((longlong)piVar4 + 0x25) = *(undefined1 *)((longlong)puVar11 + 0x1c);
          *(undefined1 *)(param_1 + 0x2d0) = 1;
          if ((*(byte *)(param_1 + 0x14c0) & 1) == 0) {
            uVar5 = *(ushort *)(piVar4 + 6);
            uVar16 = (uint)uVar5;
            if (uVar5 == 0xffff) {
              uVar7 = GetFirstFreeDPMPage0(param_1);
              uVar16 = (uint)uVar7 & 0xffff;
              *(undefined1 *)((longlong)piVar4 + 0x21) = 0;
            }
            else {
              piVar9 = (int *)(*(longlong *)(param_1 + 0x1520) + ((ulonglong)uVar5 * 5 + 2) * 4);
              if (((*piVar9 == *piVar4) && (piVar9[1] == piVar4[1])) &&
                 ((*(byte *)(piVar9 + 2) & 0xf) == 0)) {
                *(undefined1 *)((longlong)piVar4 + 0x21) = 1;
              }
            }
            if ((short)uVar16 == -1) {
              if ((*(char *)(param_1 + 0x3d51) != '\0') && (*(char *)(param_1 + 0x3d50) == '\0')) {
                in_stack_ffffffffffffffb8 =
                     (undefined1 *)((ulonglong)in_stack_ffffffffffffffb8 & 0xffffffffffffff00);
                StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffffb8,6,0xad010045);
                *(undefined1 *)(param_1 + 0x3d50) = 1;
              }
            }
            else if (*(char *)((longlong)piVar4 + 0x21) == '\0') {
              *(short *)(piVar4 + 6) = (short)uVar16;
              *(undefined1 *)((longlong)piVar4 + 0x21) = 1;
              uVar7 = (ulonglong)uVar16;
              puVar14 = (undefined8 *)(*(longlong *)(param_1 + 0x1520) + (uVar7 * 5 + 2) * 4);
              *puVar14 = *(undefined8 *)piVar4;
              *(undefined2 *)(puVar14 + 1) = 0;
              *(ushort *)((longlong)puVar14 + 10) = (ushort)uVar6;
              *(undefined4 *)((longlong)puVar14 + 0xc) = 0;
              *(undefined1 *)(uVar7 + *(longlong *)(param_1 + 0x14d8)) = 1;
              *(undefined1 *)(uVar7 + *(longlong *)(param_1 + 0x14d0)) = 1;
            }
          }
          *(undefined1 *)((longlong)piVar4 + 0x21) = 1;
        }
      }
LAB_14000550f:
      *puVar11 = 0;
      uVar16 = (int)uVar17 + 1;
      uVar17 = (ulonglong)uVar16;
      puVar11[1] = 0;
      puVar11[2] = 0;
      *(undefined4 *)(puVar11 + 3) = 0;
      *(undefined1 *)((longlong)puVar11 + 0x1c) = 0;
    } while (uVar16 < *(byte *)(lVar18 + 0x3c4));
  }
  if (*(char *)(param_1 + 0xdc3) != '\0') {
    *(undefined1 *)(param_1 + 0xdc3) = 0;
    RemoveDevice(param_1,param_2);
    return;
  }
  *(undefined1 *)(lVar18 + 0x3c4) = 0;
  *(undefined1 *)(param_1 + 0xdc4) = 1;
  *(undefined1 *)(param_1 + 0x5b6) = 1;
  iVar12 = 0;
  if ((uint)((*(int *)(param_1 + 0x14e4) + 2) * 0x3cc) <= (uint)*(ushort *)(param_1 + 0x59c) * 0x3cc
     ) {
    iVar12 = *(int *)(param_1 + 0x14e4) + 1;
  }
  *(int *)(param_1 + 0x14e4) = iVar12;
  SendExtendedConfigPageMessage
            (param_1,'\x01',(char *)(param_1 + 0x1530),0x20000000,
             (int)*(undefined8 *)(param_1 + 0x1538),param_2);
  return;
}



===== AddOrRemoveIrVolume @ 140005600 =====

void AddOrRemoveIrVolume(longlong param_1,int param_2)

{
  ulonglong *puVar1;
  ulonglong *puVar2;
  bool bVar3;
  char cVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined8 uVar7;
  short *psVar8;
  int *piVar9;
  ushort uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  ulonglong uVar14;
  longlong lVar15;
  undefined8 local_res8;
  ulonglong in_stack_ffffffffffffffb8;
  undefined4 uVar16;
  
  do {
    bVar3 = false;
    uVar11 = 0;
    lVar15 = (ulonglong)*(uint *)(param_1 + 0x14ec) * 0x148 + *(longlong *)(param_1 + 0x2b8);
    if (*(char *)(lVar15 + 0x144) != '\0') {
      do {
        *(undefined1 *)(param_1 + 0x2d0) = 1;
        cVar4 = *(char *)(lVar15 + 0x13 + (ulonglong)uVar11 * 0x14);
        puVar1 = (ulonglong *)(lVar15 + (ulonglong)uVar11 * 0x14);
        if ((cVar4 == '\x01') || (cVar4 == '\x06')) {
          uVar5 = *puVar1;
          if ((*(byte *)(param_1 + 0x14c4) & 3) == 0) {
            uVar13 = *(ushort *)(param_1 + 0x14c0) >> 4 & 1;
          }
          else {
            uVar13 = (uint)*(ushort *)(param_1 + 0x598) - (uint)*(byte *)(param_1 + 0x59f);
          }
          uVar14 = (ulonglong)uVar13;
          lVar6 = *(longlong *)(param_1 + 0x2c8);
          uVar12 = (*(byte *)(param_1 + 0x59f) - 1) + uVar13;
          piVar9 = (int *)(lVar6 + uVar14 * 0x28);
          local_res8 = uVar5;
          if (uVar13 <= uVar12) {
            local_res8._4_4_ = (int)(uVar5 >> 0x20);
            do {
              uVar13 = (uint)uVar14;
              if ((*piVar9 == (int)uVar5) && (piVar9[1] == local_res8._4_4_)) {
                if (uVar13 != 0xffffffff) {
                  *(short *)(lVar6 + 0x1c + uVar14 * 0x28) = (short)(uVar13 >> 7);
                  *(ushort *)(lVar6 + 0x1e + uVar14 * 0x28) = (ushort)uVar14 & 0x7f;
                  *(undefined2 *)(lVar6 + 0x1a + uVar14 * 0x28) =
                       *(undefined2 *)((longlong)puVar1 + 0xe);
                  *(undefined4 *)(lVar6 + 0x14 + uVar14 * 0x28) = 0x30000000;
                  goto LAB_140005899;
                }
                break;
              }
              uVar14 = (ulonglong)(uVar13 + 1);
              piVar9 = piVar9 + 10;
            } while (uVar13 + 1 <= uVar12);
          }
          uVar5 = GetFirstFreeIrMapTableIndex(param_1);
          local_res8 = CONCAT44(local_res8._4_4_,(int)uVar5);
          if ((int)uVar5 == -1) {
            bVar3 = true;
            uVar16 = 0xad01004f;
          }
          else {
            if (uVar11 < *(byte *)(lVar15 + 0x144) - 1) {
              lVar6 = CheckAllIrVolumeAddElements(param_1,(uint *)&local_res8,uVar11);
              uVar5 = local_res8;
              if ((char)lVar6 == '\0') {
                bVar3 = true;
                uVar16 = 0xad01004f;
                goto LAB_140005717;
              }
            }
            uVar14 = uVar5 & 0xffffffff;
            if (!bVar3) {
              puVar2 = (ulonglong *)(*(longlong *)(param_1 + 0x2c8) + uVar14 * 0x28);
              *puVar2 = *puVar1;
              *(short *)((longlong)puVar2 + 0x1c) = (short)((uint)uVar5 >> 7);
              *(ushort *)((longlong)puVar2 + 0x1e) = (ushort)uVar14 & 0x7f;
              *(undefined2 *)((longlong)puVar2 + 0x1a) = *(undefined2 *)((longlong)puVar1 + 0xe);
              *(undefined4 *)((longlong)puVar2 + 0x14) = 0x30000000;
              *(undefined1 *)((longlong)puVar2 + 0x21) = 0;
LAB_140005899:
              uVar13 = (uint)uVar14;
              goto LAB_14000589f;
            }
            uVar16 = 0xad01004f;
          }
LAB_140005717:
          in_stack_ffffffffffffffb8 = in_stack_ffffffffffffffb8 & 0xffffffffffffff00;
          StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffffb8,6,uVar16);
        }
        else if (cVar4 == '\x02') {
          uVar5 = GetMapTableIndexFromWWID(param_1,*puVar1);
          uVar13 = (uint)uVar5;
          if (uVar13 == 0xffffffff) {
            in_stack_ffffffffffffffb8 = in_stack_ffffffffffffffb8 & 0xffffffffffffff00;
            StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffffb8,6,0xad01003f);
          }
          else {
LAB_14000589f:
            UpdateIrMissingCount(param_1,uVar13,puVar1);
          }
        }
        else if (cVar4 == '\a') {
          psVar8 = (short *)(*(longlong *)(param_1 + 0x2c8) + 0x1a);
          uVar5 = 0;
          while (uVar13 = (uint)uVar5, uVar13 < *(uint *)(param_1 + 0x5b8)) {
            if (*psVar8 == *(short *)((longlong)puVar1 + 0xe)) {
              if (uVar13 != 0xffffffff) {
                *(undefined4 *)(*(longlong *)(param_1 + 0x2c8) + 0x14 + uVar5 * 0x28) = 0x20000000;
                goto LAB_14000589f;
              }
              break;
            }
            psVar8 = psVar8 + 0x14;
            uVar5 = (ulonglong)(uVar13 + 1);
          }
          uVar16 = 0xad01003f;
          goto LAB_140005717;
        }
        *puVar1 = 0;
        uVar11 = uVar11 + 1;
        puVar1[1] = 0;
        *(undefined4 *)(puVar1 + 2) = 0;
      } while (uVar11 < *(byte *)(lVar15 + 0x144));
    }
    *(undefined1 *)(lVar15 + 0x144) = 0;
    uVar11 = *(int *)(param_1 + 0x14ec) + 1;
    uVar5 = 0;
    if (uVar11 != 10) {
      uVar5 = (ulonglong)uVar11;
    }
    *(int *)(param_1 + 0x14ec) = (int)uVar5;
    if (*(char *)(uVar5 * 0x148 + 0x144 + *(longlong *)(param_1 + 0x2b8)) == '\0') {
      *(undefined1 *)(param_1 + 0xdbf) = 0;
      if (*(char *)((ulonglong)*(uint *)(param_1 + 0x14e4) * 0x3cc + 0x3c4 +
                   *(longlong *)(param_1 + 0x2b0)) == '\0') {
        cVar4 = '\0';
        if (*(longlong *)(param_1 + 0x528) == 0) {
          if (*(int *)(param_1 + 0xdf8) == 0) {
            uVar7 = CheckResetQueue(param_1,param_2);
            cVar4 = (char)uVar7;
            goto LAB_140005997;
          }
        }
        else {
LAB_140005997:
          if (((*(int *)(param_1 + 0xdf8) == 0) && (cVar4 == '\0')) &&
             (*(longlong *)(param_1 + 0x528) == 0)) {
            StorPortResume(param_1);
            ResetActive(param_1,0x40000001,param_2);
          }
        }
        if (*(char *)(param_1 + 0x2d0) != '\0') {
          *(undefined1 *)(param_1 + 0x2d0) = 0;
          *(undefined1 *)(param_1 + 0xd80) = 1;
          if ((*(int *)(param_1 + 0xdf8) == 0) && (uVar10 = 0, *(short *)(param_1 + 0x5a0) != 0)) {
            do {
              if ((*(char *)(param_1 + 0x308) != '\0') &&
                 ((*(uint *)(param_1 + 0x30c) & 0x100004) != 0)) {
                RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x100004,
                            (undefined1 *)0x0,0,param_2);
              }
              StorPortNotification(7,param_1,uVar10);
              uVar10 = uVar10 + 1;
            } while (uVar10 < *(ushort *)(param_1 + 0x5a0));
          }
        }
      }
      else {
        *(undefined1 *)(param_1 + 0xdbe) = 1;
        UpdateMissingCount(param_1,param_2);
        uVar7 = ReadIDs(param_1,param_2);
        if ((char)uVar7 == '\0') {
          *(undefined1 *)(param_1 + 0xdc0) = 0;
          RemoveDevice(param_1,param_2);
        }
      }
      return;
    }
    uVar7 = ReadIrIDs(param_1,param_2);
    if ((char)uVar7 != '\0') {
      return;
    }
    *(undefined1 *)(param_1 + 0xdc1) = 0;
  } while( true );
}



===== AddToRemovalTable @ 140005a80 =====

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
  ulonglong in_stack_ffffffffffffffc8;
  
  psVar8 = *(short **)(param_1 + 0x2c0);
  lVar4 = *(longlong *)(param_1 + 0x2c8);
  uVar9 = 0;
  uVar7 = 0;
  psVar10 = (short *)(lVar4 + 0x1a);
  do {
    uVar6 = (uint)uVar7;
    local_res10[0] = param_2;
    if (*(uint *)(param_1 + 0x5b8) <= uVar6) {
LAB_140005b44:
      StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffffc8 & 0xffffffffffffff00,6,0xad01003f);
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x230) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x230,
                    (undefined1 *)local_res10,2,param_4);
      }
LAB_140005bb2:
      if (*(uint *)(param_1 + 0x5b8) != 0) {
        while ((psVar8[1] != 0 || (*psVar8 != -1))) {
          uVar9 = uVar9 + 1;
          psVar8 = psVar8 + 4;
          if (*(uint *)(param_1 + 0x5b8) <= uVar9) {
            return;
          }
        }
        uVar5 = *(ushort *)(param_1 + 0x14c0) & 0xe;
        if (uVar5 == 2) {
          if (param_3 != 0) {
            *psVar8 = param_3;
          }
          bVar11 = *psVar8 == -1;
        }
        else {
          bVar11 = uVar5 == 0;
        }
        if (bVar11) {
          psVar8[1] = local_res10[0];
        }
      }
      return;
    }
    if (*psVar10 == param_2) {
      if (uVar6 != 0xffffffff) {
        uVar2 = *(undefined1 *)(lVar4 + 0x1c + uVar7 * 0x28);
        lVar1 = lVar4 + uVar7 * 0x28;
        uVar3 = *(undefined1 *)(lVar4 + 0x1e + uVar7 * 0x28);
        *(undefined2 *)(lVar1 + 0x24) = 0;
        *(undefined2 *)(lVar1 + 0x1a) = 0;
        ResumeDevice(param_1,uVar2,uVar3,0,param_2,0xff,3,param_4);
        if (*(int *)(lVar1 + 0x14) < 0) {
          SendSEPMessage(param_1,0,local_res10[0],param_4);
          *(uint *)(lVar1 + 0x14) = *(uint *)(lVar1 + 0x14) & 0x7fffffff;
        }
        goto LAB_140005bb2;
      }
      goto LAB_140005b44;
    }
    uVar7 = (ulonglong)(uVar6 + 1);
    psVar10 = psVar10 + 0x14;
  } while( true );
}



===== AtaIdentifyTimeout @ 140005c30 =====

ulonglong AtaIdentifyTimeout(longlong param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  byte bVar1;
  undefined2 *puVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x23e) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x23e,(undefined1 *)0x0,0
                ,param_4);
  }
  puVar2 = *(undefined2 **)(param_1 + 0x280);
  lVar4 = (ulonglong)*(uint *)(param_1 + 0x14e4) * 0x3cc + *(longlong *)(param_1 + 0x2b0);
  bVar1 = *(byte *)(lVar4 + 0x3c7);
  *(undefined1 *)(param_1 + 0xde9) = 1;
  ZeroMemory((undefined1 *)puVar2,0x34);
  *puVar2 = *(undefined2 *)((ulonglong)bVar1 * 0x20 + lVar4 + 0x14);
  *(undefined1 *)((longlong)puVar2 + 3) = 1;
  *(undefined1 *)((longlong)puVar2 + 5) = 1;
  uVar3 = QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x5b2) * 0x10000 + 6,0,param_4)
  ;
  return uVar3 & 0xffffffffffffff00;
}



===== BusTargetDevHandleMapping @ 140005d10 =====

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
      lVar6 = *(longlong *)(param_1 + 0x2c8);
      uVar5 = 0;
      if (*(uint *)(param_1 + 0x5b8) == 0) {
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
      } while ((uint)uVar5 < *(uint *)(param_1 + 0x5b8));
      return 0x28;
    }
  }
  else if (!bVar7) {
    return 0;
  }
  if (((uVar5 < 0x80) && (uVar5 = sVar1 * 0x80 + uVar5, (uint)uVar5 < *(uint *)(param_1 + 0x5b8)))
     && (sVar1 = *(short *)(*(longlong *)(param_1 + 0x2c8) + 0x1a + (ulonglong)uVar5 * 0x28),
        sVar1 != 0)) {
    *(short *)(lVar3 + 0x24) = sVar1;
    return 0x28;
  }
  return 0x28;
}



===== CheckAllIrVolumeAddElements @ 140005e40 =====

longlong CheckAllIrVolumeAddElements(longlong param_1,uint *param_2,uint param_3)

{
  char cVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint uVar6;
  int *piVar7;
  
  if ((*(byte *)(param_1 + 0x14c4) & 3) == 0) {
    uVar6 = *(ushort *)(param_1 + 0x14c0) >> 4 & 1;
  }
  else {
    uVar6 = (uint)*(ushort *)(param_1 + 0x598) - (uint)*(byte *)(param_1 + 0x59f);
  }
  uVar3 = (ulonglong)*param_2;
  lVar5 = (ulonglong)*(uint *)(param_1 + 0x14ec) * 0x148 + *(longlong *)(param_1 + 0x2b8);
  do {
    piVar7 = (int *)(*(longlong *)(param_1 + 0x2c8) + uVar3 * 0x28);
    uVar2 = param_3;
    do {
      uVar2 = uVar2 + 1;
      if (*(byte *)(lVar5 + 0x144) <= uVar2) {
        *param_2 = (uint)uVar3;
        return CONCAT71((int7)(uVar3 >> 8),1);
      }
      uVar4 = (ulonglong)uVar2;
      cVar1 = *(char *)(lVar5 + 0x13 + uVar4 * 0x14);
    } while ((((cVar1 != '\x01') && (cVar1 != '\x06')) ||
             (*piVar7 != *(int *)(lVar5 + uVar4 * 0x14))) ||
            (piVar7[1] != *(int *)(lVar5 + 4 + uVar4 * 0x14)));
    do {
      uVar2 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
      if ((*(byte *)(param_1 + 0x59f) - 1) + uVar6 < uVar2) {
        return (ulonglong)(uint3)(uVar2 >> 8) << 8;
      }
    } while ((*(uint *)(*(longlong *)(param_1 + 0x2c8) + 0x14 + uVar3 * 0x28) & 0x10000000) != 0);
  } while( true );
}



===== ClearEnclosureEntry @ 140005f40 =====

void ClearEnclosureEntry(undefined8 *param_1)

{
  *(undefined4 *)(param_1 + 1) = 0xffffffff;
  *param_1 = 0;
  *(undefined4 *)((longlong)param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 3) = 0;
  param_1[2] = 0xffff;
  return;
}



===== ClearMapEntry @ 140005f60 =====

void ClearMapEntry(longlong param_1,undefined8 *param_2)

{
  param_2[3] = 0xffff;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  *(undefined2 *)(param_2 + 4) = 0;
  *(undefined1 *)((longlong)param_2 + 0x22) = *(undefined1 *)(param_1 + 0x59e);
  *(undefined1 *)((longlong)param_2 + 0x23) = 0;
  return;
}



===== CompressEnclosureTable @ 140005f90 =====

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
  
  if ((*(byte *)(param_1 + 0x14c0) & 0xe) == 2) {
    uVar4 = (ushort)*(byte *)(param_1 + 0x14cc);
    do {
      piVar8 = *(int **)(param_1 + 0x2a8);
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
          }
          else {
            puVar5 = (undefined8 *)((ulonglong)uVar9 * 0x1c + *(longlong *)(param_1 + 0x2a8));
            puVar3 = (undefined8 *)((ulonglong)(uVar9 + 1) * 0x1c + *(longlong *)(param_1 + 0x2a8));
            uVar7 = uVar9;
            while ((int)uVar6 < (int)(uVar4 - 1)) {
              uVar2 = puVar3[1];
              uVar7 = uVar7 + 1;
              *puVar5 = *puVar3;
              puVar5[1] = uVar2;
              puVar5[2] = puVar3[2];
              *(undefined4 *)(puVar5 + 3) = *(undefined4 *)(puVar3 + 3);
              puVar5 = (undefined8 *)((longlong)puVar5 + 0x1c);
              puVar3 = (undefined8 *)((longlong)puVar3 + 0x1c);
              uVar6 = (uint)uVar7;
            }
            *puVar5 = 0;
            *(undefined4 *)(puVar5 + 1) = 0xffffffff;
            *(undefined4 *)((longlong)puVar5 + 0xc) = 0;
            puVar5[2] = 0xffff;
            *(undefined4 *)(puVar5 + 3) = 0;
          }
          *(char *)(param_1 + 0x14cc) = *(char *)(param_1 + 0x14cc) + -1;
          uVar4 = (ushort)*(byte *)(param_1 + 0x14cc);
        }
        uVar9 = uVar9 + 1;
        piVar8 = piVar8 + 7;
      } while (uVar9 < uVar4);
    } while (!bVar1);
  }
  return;
}



===== ContinueHashedSASAddress @ 1400060e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ContinueHashedSASAddress(longlong param_1,longlong param_2,int param_3)

{
  uint uVar1;
  int *piVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  int *piVar11;
  undefined1 auStack_98 [32];
  undefined1 local_78;
  undefined4 local_70;
  undefined4 local_68;
  undefined4 local_58;
  int local_54 [9];
  undefined1 auStack_30 [24];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_98;
  GtfStopTimer(param_1,*(byte *)(param_1 + 0xde8),param_3);
  lVar4 = (ulonglong)*(uint *)(param_1 + 0x14e4) * 0x3cc + *(longlong *)(param_1 + 0x2b0);
  piVar11 = (int *)((ulonglong)*(byte *)(lVar4 + 0x3c7) * 0x20 + lVar4);
  if (((*(ushort *)(param_2 + 0xe) & 0x7fff) == 0) && (*(char *)(param_2 + 0xd) == '\0')) {
    lVar4 = *(longlong *)(param_1 + 0xde0);
    uVar7 = 0;
    puVar10 = (undefined1 *)(lVar4 + 0x36);
    puVar9 = puVar10;
    do {
      uVar1 = uVar7 + 1;
      bVar6 = (char)uVar7 + 2;
      uVar7 = (uint)bVar6;
      (puVar9 + 2)[(longlong)local_54 + (-6 - (longlong)puVar10)] = puVar10[uVar1];
      *(undefined1 *)((longlong)local_54 + ((ulonglong)uVar1 - 4)) = *puVar9;
      puVar9 = puVar9 + 2;
    } while (bVar6 < 0x28);
    puVar10 = (undefined1 *)(lVar4 + 0x14);
    uVar7 = 0;
    do {
      bVar6 = (char)uVar7 + 2;
      *(undefined1 *)((longlong)local_54 + ((ulonglong)(uVar7 + 0x28) - 4)) =
           *(undefined1 *)((ulonglong)(uVar7 + 1) + 0x14 + lVar4);
      *(undefined1 *)((longlong)local_54 + ((ulonglong)(uVar7 + 0x29) - 4)) = *puVar10;
      puVar10 = puVar10 + 2;
      uVar7 = (uint)bVar6;
    } while (bVar6 < 0x14);
    iVar8 = 0;
    piVar2 = &local_58;
    uVar7 = 0;
    lVar5 = 7;
    do {
      iVar8 = iVar8 + *piVar2;
      uVar7 = uVar7 + piVar2[1];
      piVar2 = piVar2 + 2;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    *piVar11 = *piVar2 + iVar8;
    uVar1 = uVar7 | 0x80;
    if (((byte)uVar7 & 0xf0) != 0x50) {
      uVar1 = uVar7;
    }
    piVar11[1] = uVar1;
    if (*(short *)(lVar4 + 0x1b2) == 1) {
      *(undefined1 *)(piVar11 + 7) = 1;
    }
  }
  else {
    if (*(char *)((longlong)piVar11 + 0x1b) != '\x05') {
      *(char *)((longlong)piVar11 + 0x1b) = *(char *)((longlong)piVar11 + 0x1b) + '\x01';
      SendSTPIdentifyCommand(param_1,piVar11[4],(short)piVar11[5],param_3);
      return;
    }
    local_68 = 0xad010051;
    local_70 = 6;
    local_78 = 0;
    StorPortLogError(param_1,0,0,0);
  }
  uVar3 = ReadIDs(param_1,param_3);
  if ((char)uVar3 == '\0') {
    *(undefined1 *)(param_1 + 0xdc0) = 0;
    RemoveDevice(param_1,param_3);
  }
  return;
}



===== ContinueIDReadsForIrElements @ 1400062b0 =====

void ContinueIDReadsForIrElements(longlong param_1,int param_2)

{
  undefined8 *puVar1;
  uint *puVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  
  lVar5 = (ulonglong)*(uint *)(param_1 + 0x14ec) * 0x148 + *(longlong *)(param_1 + 0x2b8);
  puVar1 = (undefined8 *)(lVar5 + (ulonglong)*(byte *)(lVar5 + 0x145) * 0x14);
  if (*(short *)(param_1 + 0x145a) == 0) {
    uVar4 = *(undefined8 *)(*(longlong *)(param_1 + 0x1510) + 0x30);
    *puVar1 = uVar4;
    *(undefined1 *)((longlong)puVar1 + 0x12) = 1;
    uVar3 = GetMapTableIndexFromWWID(param_1,uVar4);
    if ((int)uVar3 != -1) {
      puVar2 = (uint *)(*(longlong *)(param_1 + 0x2c8) + 0x14 + (uVar3 & 0xffffffff) * 0x28);
      *puVar2 = *puVar2 | 0x10000000;
    }
  }
  else {
    StorPortLogError(param_1,0,0,0,0,6,0xad010041);
    *puVar1 = 0;
    puVar1[1] = 0;
    *(undefined4 *)(puVar1 + 2) = 0;
  }
  uVar4 = ReadIrIDs(param_1,param_2);
  if ((char)uVar4 == '\0') {
    *(undefined1 *)(param_1 + 0xdc1) = 0;
    AddOrRemoveIrVolume(param_1,param_2);
  }
  return;
}



===== ContinueIDReadsForPhyEvents @ 140006390 =====

void ContinueIDReadsForPhyEvents(longlong param_1,int param_2)

{
  undefined1 *puVar1;
  byte bVar2;
  uint uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  uint uVar6;
  char *pcVar7;
  ushort uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  longlong lVar11;
  int *piVar12;
  undefined1 *in_stack_ffffffffffffffc8;
  
  lVar11 = (ulonglong)*(uint *)(param_1 + 0x14e4) * 0x3cc + *(longlong *)(param_1 + 0x2b0);
  puVar10 = (undefined8 *)((ulonglong)*(byte *)(lVar11 + 0x3c7) * 0x20 + lVar11);
  if (*(short *)(param_1 + 0x145a) == 0) {
    puVar1 = *(undefined1 **)(param_1 + 0x1538);
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x100003) != 0)) {
      in_stack_ffffffffffffffc8 = puVar1;
      RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x100003,puVar1,0x38,
                  param_2);
    }
    *(undefined1 *)(puVar10 + 3) = 1;
    *puVar10 = *(undefined8 *)(puVar1 + 0xc);
    puVar10[1] = *(undefined8 *)(puVar1 + 0xc);
    *(undefined2 *)((longlong)puVar10 + 0x16) = *(undefined2 *)(puVar1 + 8);
    uVar3 = *(uint *)(puVar1 + 0x1c);
    *(uint *)(puVar10 + 2) = uVar3;
    if ((*(byte *)(param_1 + 0x14c0) & 0xe) == 2) {
      uVar5 = 0;
      pcVar7 = (char *)(*(longlong *)(param_1 + 0x2a8) + 0x18);
LAB_1400064e3:
      uVar8 = (ushort)uVar5;
      if (uVar8 < *(byte *)(param_1 + 0x14cc)) {
        if ((*(short *)(pcVar7 + -6) != *(short *)(lVar11 + 0x3c0)) || (*pcVar7 != '\0'))
        goto LAB_1400064ff;
        if (uVar8 != 0xffff) {
          if ((((byte)uVar3 & 7) == 1) && ((uVar3 & 0x680) != 0)) {
            piVar12 = (int *)(uVar5 * 0x1c + *(longlong *)(param_1 + 0x2a8));
            if (piVar12[2] == -1) {
              if (*(short *)(lVar11 + 0x3c2) == 0) {
                uVar3 = *(uint *)(param_1 + 0x14f0);
                piVar12[2] = uVar3;
LAB_140006559:
                puVar9 = (undefined8 *)(*(longlong *)(param_1 + 0x2c8) + (ulonglong)uVar3 * 0x28);
                uVar6 = uVar3;
                if (uVar3 < *(ushort *)(piVar12 + 5) + uVar3) {
                  do {
                    *(undefined4 *)((longlong)puVar9 + 0x14) = 0x20000000;
                    uVar6 = uVar6 + 1;
                    *puVar9 = *(undefined8 *)piVar12;
                    *(int *)(puVar9 + 2) = piVar12[3];
                    *(undefined1 *)(puVar9 + 4) = 0;
                    puVar9 = puVar9 + 5;
                  } while (uVar6 < *(ushort *)(piVar12 + 5) + uVar3);
                }
              }
              else {
                uVar5 = FindEnclosureMappingSpace(param_1,piVar12,param_2);
                uVar3 = (uint)uVar5;
                piVar12[2] = uVar3;
                if (uVar3 != 0xffffffff) goto LAB_140006559;
                if (*(char *)(param_1 + 0xdc6) == '\0') {
                  *(undefined1 *)(param_1 + 0xdc5) = 1;
                }
                else {
                  StorPortLogError(param_1,0,0,0,
                                   (ulonglong)in_stack_ffffffffffffffc8 & 0xffffffffffffff00,6,
                                   0xad010044);
                }
                bVar2 = 0;
                *puVar10 = 0;
                puVar10[1] = 0;
                puVar10[2] = 0;
                *(undefined4 *)(puVar10 + 3) = 0;
                *(undefined1 *)((longlong)puVar10 + 0x1c) = 0;
                if (*(char *)(lVar11 + 0x3c4) != '\0') {
                  do {
                    puVar10 = (undefined8 *)((ulonglong)bVar2 * 0x20 + lVar11);
                    if (*(char *)((longlong)puVar10 + 0x1a) == '\x01') {
                      *puVar10 = 0;
                      puVar10[1] = 0;
                      puVar10[2] = 0;
                      *(undefined4 *)(puVar10 + 3) = 0;
                      *(undefined1 *)((longlong)puVar10 + 0x1c) = 0;
                    }
                    bVar2 = bVar2 + 1;
                  } while (bVar2 < *(byte *)(lVar11 + 0x3c4));
                }
                *(undefined1 *)(lVar11 + 0x3c7) = *(undefined1 *)(lVar11 + 0x3c4);
              }
            }
            goto LAB_140006693;
          }
          goto LAB_140006681;
        }
      }
      StorPortLogError(param_1,0,0,0,(ulonglong)in_stack_ffffffffffffffc8 & 0xffffffffffffff00,6,
                       0xad010040);
LAB_140006681:
      *(undefined1 *)((longlong)puVar10 + 0x1c) = 0;
      *(undefined4 *)(puVar10 + 3) = 0;
      puVar10[2] = 0;
      puVar10[1] = 0;
      *puVar10 = 0;
    }
LAB_140006693:
    if ((((byte)*(undefined4 *)(puVar1 + 0x1c) & 0x81) == 0x81) &&
       (*(char *)(param_1 + 0xdc7) == '\0')) {
      *(undefined1 *)((longlong)puVar10 + 0x1b) = 0;
      SendSTPIdentifyCommand
                (param_1,*(uint *)(puVar1 + 0x1c),*(undefined2 *)((longlong)puVar10 + 0x14),param_2)
      ;
      return;
    }
  }
  else {
    StorPortLogError(param_1,0,0,0,(ulonglong)in_stack_ffffffffffffffc8 & 0xffffffffffffff00,6,
                     0xad010041);
    *puVar10 = 0;
    puVar10[1] = 0;
    puVar10[2] = 0;
    *(undefined4 *)(puVar10 + 3) = 0;
    *(undefined1 *)((longlong)puVar10 + 0x1c) = 0;
  }
  uVar4 = ReadIDs(param_1,param_2);
  if ((char)uVar4 == '\0') {
    *(undefined1 *)(param_1 + 0xdc0) = 0;
    RemoveDevice(param_1,param_2);
  }
  return;
LAB_1400064ff:
  uVar5 = (ulonglong)(ushort)(uVar8 + 1);
  pcVar7 = pcVar7 + 0x1c;
  goto LAB_1400064e3;
}



===== FindEnclosureMappingSpace @ 1400066e0 =====

ulonglong FindEnclosureMappingSpace(longlong param_1,int *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  undefined8 *puVar7;
  uint uVar8;
  longlong lVar9;
  ulonglong uVar10;
  ushort uVar11;
  
  iVar1 = *(int *)(param_1 + 0x14f0);
  uVar11 = 0;
  uVar6 = *(uint *)(param_1 + 0x5b8) - (uint)*(byte *)(param_1 + 0x59f);
  if ((*(byte *)(param_1 + 0x14c4) & 3) == 0) {
    uVar6 = *(uint *)(param_1 + 0x5b8);
  }
  uVar5 = (uint)*(ushort *)(param_1 + 0x14be) + iVar1;
  if (uVar5 < uVar6) {
    lVar9 = *(longlong *)(param_1 + 0x2c8);
    uVar8 = uVar5;
    do {
      uVar3 = (ulonglong)uVar8;
      if (((*(int *)(lVar9 + uVar3 * 0x28) == *param_2) &&
          (*(int *)(lVar9 + 4 + uVar3 * 0x28) == param_2[1])) &&
         ((uVar2 = *(uint *)(lVar9 + 0x10 + uVar3 * 0x28), uVar2 == 0 || ((param_2[3] & uVar2) != 0)
          ))) {
        uVar11 = uVar11 + 1;
        if (uVar11 == *(ushort *)(param_2 + 5)) {
          return (ulonglong)((uVar8 - uVar11) + 1);
        }
      }
      else {
        uVar11 = 0;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < uVar6);
  }
  uVar11 = 0;
  if (uVar5 < uVar6) {
    do {
      if ((*(uint *)(*(longlong *)(param_1 + 0x2c8) + 0x14 + (ulonglong)uVar5 * 0x28) & 0x20000000)
          == 0) {
        uVar11 = uVar11 + 1;
        if (uVar11 == *(ushort *)(param_2 + 5)) {
          return (ulonglong)((uVar5 - uVar11) + 1);
        }
      }
      else {
        uVar11 = 0;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar6);
  }
  do {
    do {
      uVar11 = GetHighMissingEncTableIndex(param_1);
      if (uVar11 == 0xffff) {
        return 0xffffffff;
      }
      lVar9 = (ulonglong)uVar11 * 0x1c + *(longlong *)(param_1 + 0x2a8);
      uVar5 = *(uint *)(lVar9 + 8);
      uVar3 = (ulonglong)uVar5;
      *(undefined1 *)(lVar9 + 0x1a) = 1;
      if (uVar5 < *(ushort *)(lVar9 + 0x14) + uVar5) {
        puVar4 = (uint *)(*(longlong *)(param_1 + 0x2c8) + uVar3 * 0x28 + 0x14);
        do {
          *puVar4 = *puVar4 & 0xdfffffff;
          puVar4 = puVar4 + 10;
          uVar5 = (int)uVar3 + 1;
          uVar3 = (ulonglong)uVar5;
        } while (uVar5 < (uint)*(ushort *)(lVar9 + 0x14) + *(int *)(lVar9 + 8));
      }
      uVar5 = (uint)*(ushort *)(param_1 + 0x14be) + iVar1;
      uVar11 = 0;
    } while (uVar6 <= uVar5);
    do {
      if ((*(uint *)(*(longlong *)(param_1 + 0x2c8) + 0x14 + (ulonglong)uVar5 * 0x28) & 0x20000000)
          == 0) {
        uVar11 = uVar11 + 1;
        if (uVar11 == *(ushort *)(param_2 + 5)) {
          uVar6 = (uVar5 - uVar11) + 1;
          uVar3 = (ulonglong)uVar6;
          uVar5 = uVar11 + uVar6;
          if (uVar6 < uVar5) {
            lVar9 = uVar3 * 0x28;
            do {
              uVar11 = 0;
              if (*(char *)(param_1 + 0x14cc) != '\0') {
                puVar4 = (uint *)(*(longlong *)(param_1 + 0x2a8) + 8);
                do {
                  if ((*puVar4 <= uVar6) && (uVar6 < (uint)(ushort)puVar4[3] + *puVar4)) {
                    if (*(char *)((longlong)puVar4 + 0x11) == '\0') {
                      *(undefined1 *)((longlong)puVar4 + 0x11) = 1;
                      AddToRemovalTable(param_1,0,(short)puVar4[2],param_3);
                    }
                    puVar7 = (undefined8 *)(*(longlong *)(param_1 + 0x2c8) + lVar9);
                    if ((*(uint *)((longlong)puVar7 + 0x14) & 0x10000000) != 0) {
                      AddToRemovalTable(param_1,*(short *)((longlong)puVar7 + 0x1a),0,param_3);
                      puVar7[3] = 0xffff;
                      *puVar7 = 0;
                      puVar7[1] = 0;
                      puVar7[2] = 0;
                      *(undefined2 *)(puVar7 + 4) = 0;
                      *(undefined1 *)((longlong)puVar7 + 0x22) = *(undefined1 *)(param_1 + 0x59e);
                      *(undefined1 *)((longlong)puVar7 + 0x23) = 0;
                    }
                  }
                  uVar11 = uVar11 + 1;
                  puVar4 = puVar4 + 7;
                } while (uVar11 < *(byte *)(param_1 + 0x14cc));
              }
              uVar6 = uVar6 + 1;
              lVar9 = lVar9 + 0x28;
            } while (uVar6 < uVar5);
          }
          uVar11 = 0;
          puVar7 = *(undefined8 **)(param_1 + 0x2a8);
          if (*(char *)(param_1 + 0x14cc) != '\0') {
            do {
              if (*(char *)((longlong)puVar7 + 0x19) == '\0') {
                uVar6 = *(uint *)(puVar7 + 1);
                uVar10 = (ulonglong)uVar6;
                if (uVar6 < *(ushort *)((longlong)puVar7 + 0x14) + uVar6) {
                  puVar4 = (uint *)(*(longlong *)(param_1 + 0x2c8) + uVar10 * 0x28 + 0x14);
                  do {
                    *puVar4 = *puVar4 | 0x20000000;
                    puVar4 = puVar4 + 10;
                    uVar6 = (int)uVar10 + 1;
                    uVar10 = (ulonglong)uVar6;
                  } while (uVar6 < (uint)*(ushort *)((longlong)puVar7 + 0x14) + *(int *)(puVar7 + 1)
                          );
                }
                *(undefined1 *)((longlong)puVar7 + 0x1a) = 0;
              }
              else {
                *puVar7 = 0;
                *(undefined4 *)(puVar7 + 1) = 0xffffffff;
                *(undefined4 *)((longlong)puVar7 + 0xc) = 0;
                puVar7[2] = 0xffff;
                *(undefined4 *)(puVar7 + 3) = 0;
              }
              uVar11 = uVar11 + 1;
              puVar7 = (undefined8 *)((longlong)puVar7 + 0x1c);
            } while (uVar11 < *(byte *)(param_1 + 0x14cc));
          }
          return uVar3;
        }
      }
      else {
        uVar11 = 0;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar6);
  } while( true );
}



===== FlushAllDPMPage0 @ 140006a90 =====

void FlushAllDPMPage0(longlong param_1,int param_2)

{
  uint uVar1;
  
  FlushDPMPage0Entry(param_1,param_2);
  uVar1 = 0;
  do {
    if (*(char *)(param_1 + 0xdbc) == '\0') {
      return;
    }
    PollLSImpiIsr(param_1,param_2);
    StorPortStallExecution(1000);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 60000);
  return;
}



===== FlushDPMPage0Entry @ 140006af0 =====

void FlushDPMPage0Entry(longlong param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  
  if ((*(byte *)(param_1 + 0x14c0) & 1) == 0) {
    uVar3 = 0;
    if (*(ushort *)(param_1 + 0x14bc) != 0) {
      while (*(char *)(uVar3 + *(longlong *)(param_1 + 0x14d8)) == '\0') {
        uVar2 = (uint)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
        if (*(ushort *)(param_1 + 0x14bc) <= uVar2) {
          return;
        }
      }
      lVar1 = *(longlong *)(param_1 + 0x1520);
      *(undefined4 *)(lVar1 + 0x18 + uVar3 * 0x14) = 0;
      ZeroMemory(*(undefined1 **)(param_1 + 0x1528),8);
      memcpy((void *)(*(longlong *)(param_1 + 0x1528) + 8),(void *)(lVar1 + uVar3 * 0x14 + 8),0x14);
      *(undefined1 *)(param_1 + 0xdbc) = 1;
      SendExtendedConfigPageMessage
                (param_1,'\x04',(char *)(param_1 + 0x1518),(uint)uVar3 | 0x10000,
                 (int)*(undefined8 *)(param_1 + 0x1528),param_2);
      *(undefined1 *)(uVar3 + *(longlong *)(param_1 + 0x14d8)) = 0;
    }
  }
  return;
}



===== GetBusTargetFromDevHandle @ 140006c00 =====

ulonglong GetBusTargetFromDevHandle
                    (longlong param_1,short param_2,undefined2 *param_3,undefined2 *param_4)

{
  ulonglong uVar1;
  ushort uVar2;
  
  uVar2 = 0;
  uVar1 = *(ulonglong *)(param_1 + 0x2c8);
  if (*(uint *)(param_1 + 0x5b8) != 0) {
    do {
      if (*(short *)(uVar1 + 0x1a) == param_2) {
        *param_3 = *(undefined2 *)(uVar1 + 0x1c);
        *param_4 = *(undefined2 *)(uVar1 + 0x1e);
        return CONCAT71((int7)(uVar1 >> 8),1);
      }
      uVar2 = uVar2 + 1;
      uVar1 = uVar1 + 0x28;
    } while ((uint)uVar2 < *(uint *)(param_1 + 0x5b8));
  }
  return uVar1 & 0xffffffffffffff00;
}



===== GetDPMPage0IndexFromID @ 140006c50 =====

ushort GetDPMPage0IndexFromID(longlong param_1,undefined8 param_2,uint param_3)

{
  int *piVar1;
  ushort uVar2;
  int iStackX_14;
  
  uVar2 = 0;
  piVar1 = (int *)(*(longlong *)(param_1 + 0x1520) + 8);
  if (*(ushort *)(param_1 + 0x14bc) != 0) {
    iStackX_14 = (int)((ulonglong)param_2 >> 0x20);
    do {
      if ((((*(char *)((ulonglong)uVar2 + *(longlong *)(param_1 + 0x14d0)) != '\0') &&
           (*piVar1 == (int)param_2)) && (piVar1[1] == iStackX_14)) &&
         (((param_3 == 0 || (piVar1[3] == 0)) || ((param_3 & piVar1[3]) != 0)))) {
        return uVar2;
      }
      uVar2 = uVar2 + 1;
      piVar1 = piVar1 + 5;
    } while (uVar2 < *(ushort *)(param_1 + 0x14bc));
  }
  return 0xffff;
}



===== GetEnclosureTableIndexFromId @ 140006cd0 =====

ushort GetEnclosureTableIndexFromId(longlong param_1,undefined8 param_2,uint param_3)

{
  int *piVar1;
  ushort uVar2;
  int iStackX_14;
  
  uVar2 = 0;
  piVar1 = *(int **)(param_1 + 0x2a8);
  if (*(byte *)(param_1 + 0x14cc) != 0) {
    iStackX_14 = (int)((ulonglong)param_2 >> 0x20);
    do {
      if (((*piVar1 == (int)param_2) && (piVar1[1] == iStackX_14)) &&
         ((piVar1[3] == 0 || ((param_3 & piVar1[3]) != 0)))) {
        return uVar2;
      }
      uVar2 = uVar2 + 1;
      piVar1 = piVar1 + 7;
    } while (uVar2 < *(byte *)(param_1 + 0x14cc));
  }
  return 0xffff;
}



===== GetFirstFreeDPMPage0 @ 140006d30 =====

ulonglong GetFirstFreeDPMPage0(longlong param_1)

{
  ulonglong uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (*(ushort *)(param_1 + 0x14bc) <= (ushort)uVar1) {
      return 0xffff;
    }
    if (*(char *)(uVar1 + *(longlong *)(param_1 + 0x14d0)) == '\0') break;
    uVar1 = (ulonglong)(ushort)((ushort)uVar1 + 1);
  }
  return uVar1;
}



===== GetFirstFreeIrMapTableIndex @ 140006d70 =====

ulonglong GetFirstFreeIrMapTableIndex(longlong param_1)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  byte *pbVar4;
  uint uVar5;
  ulonglong uVar6;
  uint *puVar7;
  uint uVar8;
  byte bVar9;
  ulonglong uVar10;
  
  bVar9 = 0;
  uVar10 = 0xffffffff;
  if ((*(byte *)(param_1 + 0x14c4) & 3) == 0) {
    uVar2 = *(ushort *)(param_1 + 0x14c0) >> 4 & 1;
  }
  else {
    uVar2 = (uint)*(ushort *)(param_1 + 0x598) - (uint)*(byte *)(param_1 + 0x59f);
  }
  uVar3 = (ulonglong)uVar2;
  uVar8 = (*(byte *)(param_1 + 0x59f) - 1) + uVar2;
  lVar1 = *(longlong *)(param_1 + 0x2c8) + uVar3 * 0x28;
  if (uVar2 <= uVar8) {
    puVar7 = (uint *)(lVar1 + 0x14);
    uVar6 = uVar3;
    do {
      if ((*puVar7 & 0x10000000) == 0) {
        return uVar6;
      }
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
      puVar7 = puVar7 + 10;
    } while (uVar5 <= uVar8);
    if (uVar2 <= uVar8) {
      pbVar4 = (byte *)(lVar1 + 0x20);
      do {
        if (bVar9 < *pbVar4) {
          uVar10 = uVar3;
          bVar9 = *pbVar4;
        }
        uVar2 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
        pbVar4 = pbVar4 + 0x28;
      } while (uVar2 <= uVar8);
      if ((int)uVar10 != -1) {
        return uVar10;
      }
    }
  }
  return 0xffffffff;
}



===== GetHighMissingEncTableIndex @ 140006e30 =====

ushort GetHighMissingEncTableIndex(longlong param_1)

{
  byte *pbVar1;
  ushort uVar2;
  byte bVar3;
  ushort uVar4;
  
  bVar3 = 0;
  uVar2 = 0;
  uVar4 = 0xffff;
  if (*(byte *)(param_1 + 0x14cc) != 0) {
    pbVar1 = (byte *)(*(longlong *)(param_1 + 0x2a8) + 0x18);
    do {
      if ((bVar3 < *pbVar1) && (pbVar1[2] == 0)) {
        bVar3 = *pbVar1;
        uVar4 = uVar2;
      }
      uVar2 = uVar2 + 1;
      pbVar1 = pbVar1 + 0x1c;
    } while (uVar2 < *(byte *)(param_1 + 0x14cc));
  }
  return uVar4;
}



===== GetHighMissingMapTableIndex @ 140006e80 =====

ulonglong GetHighMissingMapTableIndex(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  byte *pbVar3;
  uint uVar4;
  byte bVar5;
  ulonglong uVar6;
  
  bVar5 = 0;
  uVar6 = 0xffffffff;
  uVar1 = *(ushort *)(param_1 + 0x14c0) >> 4 & 1;
  uVar2 = (ulonglong)uVar1;
  uVar4 = *(uint *)(param_1 + 0x5b8);
  if ((*(uint *)(param_1 + 0xdec) & 0x1000) != 0) {
    if ((*(byte *)(param_1 + 0x14c4) & 3) == 0) {
      uVar4 = *(ushort *)(param_1 + 0x14c0) >> 4 & 1;
    }
    else {
      uVar4 = (uint)*(ushort *)(param_1 + 0x598) - (uint)*(byte *)(param_1 + 0x59f);
    }
    if (uVar1 == uVar4) {
      uVar2 = (ulonglong)(*(byte *)(param_1 + 0x59f) + uVar4);
      uVar4 = *(uint *)(param_1 + 0x5b8);
    }
  }
  if ((uint)uVar2 < uVar4) {
    pbVar3 = (byte *)(*(longlong *)(param_1 + 0x2c8) + uVar2 * 0x28 + 0x20);
    do {
      if (bVar5 < *pbVar3) {
        uVar6 = uVar2;
        bVar5 = *pbVar3;
      }
      uVar1 = (int)uVar2 + 1;
      uVar2 = (ulonglong)uVar1;
      pbVar3 = pbVar3 + 0x28;
    } while (uVar1 < uVar4);
  }
  return uVar6;
}



===== GetIrMapRange @ 140006f20 =====

void GetIrMapRange(longlong param_1,int *param_2,int *param_3)

{
  if ((*(byte *)(param_1 + 0x14c4) & 3) == 0) {
    *param_2 = 0;
    if ((*(byte *)(param_1 + 0x14c0) & 0x10) != 0) {
      *param_2 = 1;
      *param_3 = (uint)*(byte *)(param_1 + 0x59f) + *param_2 + -1;
      return;
    }
  }
  else {
    *param_2 = (uint)*(ushort *)(param_1 + 0x598) - (uint)*(byte *)(param_1 + 0x59f);
  }
  *param_3 = (uint)*(byte *)(param_1 + 0x59f) + *param_2 + -1;
  return;
}



===== GetMapTableIndexFromHandle @ 140006f80 =====

uint GetMapTableIndexFromHandle(longlong param_1,short param_2)

{
  uint uVar1;
  short *psVar2;
  
  uVar1 = 0;
  psVar2 = (short *)(*(longlong *)(param_1 + 0x2c8) + 0x1a);
  while( true ) {
    if (*(uint *)(param_1 + 0x5b8) <= uVar1) {
      return 0xffffffff;
    }
    if (*psVar2 == param_2) break;
    uVar1 = uVar1 + 1;
    psVar2 = psVar2 + 0x14;
  }
  return uVar1;
}



===== GetMapTableIndexFromWWID @ 140006fb0 =====

ulonglong GetMapTableIndexFromWWID(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  ulonglong uVar2;
  int *piVar3;
  uint uVar4;
  int iStackX_14;
  
  if ((*(byte *)(param_1 + 0x14c4) & 3) == 0) {
    uVar1 = *(ushort *)(param_1 + 0x14c0) >> 4 & 1;
  }
  else {
    uVar1 = (uint)*(ushort *)(param_1 + 0x598) - (uint)*(byte *)(param_1 + 0x59f);
  }
  uVar2 = (ulonglong)uVar1;
  uVar4 = (*(byte *)(param_1 + 0x59f) - 1) + uVar1;
  piVar3 = (int *)(*(longlong *)(param_1 + 0x2c8) + uVar2 * 0x28);
  if (uVar1 <= uVar4) {
    iStackX_14 = (int)((ulonglong)param_2 >> 0x20);
    do {
      if ((*piVar3 == (int)param_2) && (piVar3[1] == iStackX_14)) {
        return uVar2;
      }
      uVar1 = (int)uVar2 + 1;
      uVar2 = (ulonglong)uVar1;
      piVar3 = piVar3 + 10;
    } while (uVar1 <= uVar4);
  }
  return 0xffffffff;
}



===== MapSODChecks @ 140007030 =====

void MapSODChecks(longlong param_1,int param_2)

{
  longlong lVar1;
  longlong lVar2;
  short sVar3;
  ushort uVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  
  uVar4 = *(ushort *)(param_1 + 0x14c0) & 0xe;
  if (uVar4 == 2) {
    puVar5 = *(undefined4 **)(param_1 + 0x2a8);
    uVar7 = 0;
    if (*(char *)(param_1 + 0x14cc) != '\0') {
      do {
        if (*(char *)((longlong)puVar5 + 0x1b) == '\0') {
          if (((*(byte *)(puVar5 + 6) < 0xf) &&
              (*(byte *)(puVar5 + 6) = *(byte *)(puVar5 + 6) + 1,
              (*(byte *)(param_1 + 0x14c0) & 1) == 0)) && (*(ushort *)(puVar5 + 4) != 0xffff)) {
            lVar1 = *(longlong *)(param_1 + 0x1520) + (ulonglong)*(ushort *)(puVar5 + 4) * 0x14;
            *(undefined4 *)(lVar1 + 8) = *puVar5;
            *(undefined4 *)(lVar1 + 0xc) = puVar5[1];
            lVar2 = *(longlong *)(param_1 + 0x2c8) + (ulonglong)(uint)puVar5[2] * 0x28;
            sVar3 = *(short *)(lVar2 + 0x1c) * 0x80;
            *(short *)(lVar1 + 0x12) = sVar3;
            *(short *)(lVar1 + 0x12) = *(short *)(lVar2 + 0x1e) + sVar3;
            sVar3 = *(short *)(puVar5 + 5);
            *(short *)(lVar1 + 0x10) = sVar3 << 4;
            *(ushort *)(lVar1 + 0x10) = (ushort)*(byte *)(puVar5 + 6) | sVar3 << 4;
            *(undefined4 *)(lVar1 + 0x14) = puVar5[3];
            *(undefined4 *)(lVar1 + 0x18) = 0;
            ZeroMemory(*(undefined1 **)(param_1 + 0x1528),8);
            memcpy((void *)(*(longlong *)(param_1 + 0x1528) + 8),(void *)(lVar1 + 8),0x14);
            uVar4 = *(ushort *)(puVar5 + 4);
            uVar8 = *(ulonglong *)(param_1 + 0x1528);
            *(undefined1 *)(param_1 + 0xdc2) = 1;
            *(undefined1 *)(param_1 + 0x5b6) = 1;
            SendExtendedConfigPageMessage
                      (param_1,'\x04',(char *)(param_1 + 0x1518),uVar4 | 0x10000,(int)uVar8,param_2)
            ;
            uVar6 = 0;
            do {
              PollLSImpiIsr(param_1,param_2);
              if (*(char *)(param_1 + 0xdc2) == '\0') goto LAB_1400071f7;
              StorPortStallExecution(500);
              uVar6 = uVar6 + 1;
            } while (uVar6 < 120000);
            if (*(char *)(param_1 + 0xdc2) != '\0') {
              StorPortLogError(param_1,0,0,0,uVar8 & 0xffffffffffffff00,6,0xad01004b);
            }
          }
LAB_1400071f7:
          *(undefined1 *)((longlong)puVar5 + 0x1b) = 1;
        }
        uVar7 = uVar7 + 1;
        puVar5 = puVar5 + 7;
      } while (uVar7 < *(byte *)(param_1 + 0x14cc));
    }
    if ((*(uint *)(param_1 + 0xdec) & 0x1000) != 0) {
      if ((*(byte *)(param_1 + 0x14c4) & 3) == 0) {
        uVar7 = *(ushort *)(param_1 + 0x14c0) >> 4 & 1;
      }
      else {
        uVar7 = (uint)*(ushort *)(param_1 + 0x598) - (uint)*(byte *)(param_1 + 0x59f);
      }
      SODCheckMapEntry(param_1,*(longlong *)(param_1 + 0x2c8) + (ulonglong)uVar7 * 0x28,uVar7,
                       *(byte *)(param_1 + 0x59f) + uVar7,param_2);
      return;
    }
  }
  else if (uVar4 == 0) {
    SODCheckMapEntry(param_1,*(longlong *)(param_1 + 0x2c8),0,*(uint *)(param_1 + 0x5b8),param_2);
  }
  return;
}



===== ProcessDPMPage0 @ 1400072c0 =====

void ProcessDPMPage0(longlong param_1)

{
  byte bVar1;
  int iVar2;
  ushort uVar3;
  undefined8 *puVar4;
  uint uVar5;
  int *piVar6;
  ushort uVar7;
  uint uVar8;
  ulonglong uVar9;
  byte bVar10;
  ushort uVar11;
  uint uVar12;
  uint uVar13;
  uint local_res8;
  undefined4 uVar14;
  
  if ((*(byte *)(param_1 + 0x14c0) & 1) == 0) {
    uVar12 = *(uint *)(param_1 + 0xdec) >> 0xc;
    if ((uVar12 & 1) == 0) {
      uVar13 = local_res8;
    }
    else if ((*(byte *)(param_1 + 0x14c4) & 3) == 0) {
      local_res8 = *(ushort *)(param_1 + 0x14c0) >> 4 & 1;
      uVar13 = (*(byte *)(param_1 + 0x59f) - 1) + local_res8;
    }
    else {
      local_res8 = (uint)*(ushort *)(param_1 + 0x598) - (uint)*(byte *)(param_1 + 0x59f);
      uVar13 = (*(byte *)(param_1 + 0x59f) - 1) + local_res8;
    }
    piVar6 = (int *)(*(longlong *)(param_1 + 0x1520) + 8);
    uVar7 = 0;
    if (*(short *)(param_1 + 0x14bc) != 0) {
      do {
        if ((*piVar6 == 0) && (piVar6[1] == 0)) {
          *(undefined1 *)((ulonglong)uVar7 + *(longlong *)(param_1 + 0x14d0)) = 0;
        }
        else {
          *(undefined1 *)((ulonglong)uVar7 + *(longlong *)(param_1 + 0x14d0)) = 1;
          uVar11 = *(ushort *)((longlong)piVar6 + 10);
          uVar9 = (ulonglong)uVar11;
          bVar10 = *(byte *)(piVar6 + 2) & 0xf;
          uVar8 = (uint)uVar11;
          if (((uVar12 & 1) == 0) ||
             ((uVar11 < local_res8 || (uVar13 <= uVar11 && uVar8 != uVar13)))) {
            uVar3 = *(ushort *)(param_1 + 0x14c0) & 0xe;
            if (uVar3 == 2) {
              uVar11 = *(ushort *)(param_1 + 0x14be);
              if (uVar8 < (uint)uVar11 + *(int *)(param_1 + 0x14f0)) {
                uVar3 = *(ushort *)(param_1 + 0x14c0) >> 5 & 1;
              }
              else {
                uVar3 = 0;
                uVar11 = *(ushort *)(piVar6 + 2) >> 4 & 0x7f;
              }
              bVar1 = *(byte *)(param_1 + 0x14cc);
              if (*(ushort *)(param_1 + 0x59a) <= (ushort)bVar1) {
                uVar14 = 0xad010046;
LAB_140007573:
                StorPortLogError(param_1,0,0,0,0,6,uVar14);
                return;
              }
              *(byte *)(param_1 + 0x14cc) = bVar1 + 1;
              puVar4 = (undefined8 *)((ulonglong)bVar1 * 0x1c + *(longlong *)(param_1 + 0x2a8));
              *puVar4 = *(undefined8 *)piVar6;
              *(uint *)(puVar4 + 1) = uVar8;
              iVar2 = piVar6[3];
              *(ushort *)((longlong)puVar4 + 0x16) = uVar3;
              *(int *)((longlong)puVar4 + 0xc) = iVar2;
              *(ushort *)(puVar4 + 2) = uVar7;
              *(ushort *)((longlong)puVar4 + 0x14) = uVar11;
              *(byte *)(puVar4 + 3) = bVar10;
              *(undefined2 *)((longlong)puVar4 + 0x19) = 0;
              *(undefined1 *)((longlong)puVar4 + 0x1b) = 0;
              uVar5 = uVar11 + uVar8;
              puVar4 = (undefined8 *)(*(longlong *)(param_1 + 0x2c8) + uVar9 * 0x28);
              while (uVar8 < uVar5) {
                if (*(short *)(puVar4 + 3) != -1) {
                  StorPortLogError(param_1,0,0,0,0,6,0xad010042);
                  break;
                }
                *puVar4 = *(undefined8 *)piVar6;
                *(int *)(puVar4 + 2) = piVar6[3];
                *(short *)((longlong)puVar4 + 0x1c) = (short)(uVar9 >> 7);
                *(ushort *)(puVar4 + 3) = uVar7;
                *(ushort *)((longlong)puVar4 + 0x1e) = (ushort)uVar9 & 0x7f;
                uVar8 = (int)uVar9 + 1;
                uVar9 = (ulonglong)uVar8;
                *(byte *)(puVar4 + 4) = bVar10;
                *(undefined4 *)((longlong)puVar4 + 0x14) = 0x20000000;
                puVar4 = puVar4 + 5;
              }
            }
            else if (uVar3 == 0) {
              puVar4 = (undefined8 *)(*(longlong *)(param_1 + 0x2c8) + uVar9 * 0x28);
              if (*(short *)(*(longlong *)(param_1 + 0x2c8) + 0x18 + uVar9 * 0x28) != -1) {
                uVar14 = 0xad010042;
                goto LAB_140007573;
              }
              goto LAB_140007522;
            }
          }
          else {
            puVar4 = (undefined8 *)(*(longlong *)(param_1 + 0x2c8) + uVar9 * 0x28);
LAB_140007522:
            *puVar4 = *(undefined8 *)piVar6;
            *(undefined4 *)((longlong)puVar4 + 0x14) = 0x20000000;
            *(byte *)(puVar4 + 4) = bVar10;
            *(ushort *)(puVar4 + 3) = uVar7;
            *(ushort *)((longlong)puVar4 + 0x1e) = uVar11 & 0x7f;
            *(ushort *)((longlong)puVar4 + 0x1c) = uVar11 >> 7;
          }
        }
        uVar7 = uVar7 + 1;
        piVar6 = piVar6 + 5;
      } while (uVar7 < *(ushort *)(param_1 + 0x14bc));
    }
  }
  return;
}



===== ProcessIRConfigChangeList @ 1400075c0 =====

void ProcessIRConfigChangeList(longlong param_1,ushort *param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  ushort *puVar6;
  ushort *puVar7;
  ulonglong uVar8;
  ushort uVar9;
  undefined4 uVar10;
  
  *(undefined4 *)(param_1 + 0xdc8) = 0x1e;
  bVar1 = (byte)param_2[0xe];
  uVar8 = (ulonglong)bVar1;
  uVar9 = (bVar1 + 1) * 8;
  if ((((ushort)(uVar9 + 0x1c) == (ushort)((ushort)(byte)param_2[1] << 2)) &&
      ((uint)uVar9 == (uint)*param_2 << 2)) && (bVar1 != 0)) {
    if ((*(uint *)(param_2 + 0x10) & 1) != 0) {
      return;
    }
    uVar2 = *(uint *)(param_1 + 0x14e8);
    lVar5 = (ulonglong)uVar2 * 0x148 + *(longlong *)(param_1 + 0x2b8);
    if (*(char *)(lVar5 + 0x144) == '\0') {
      *(byte *)(lVar5 + 0x144) = bVar1;
      *(undefined4 *)(lVar5 + 0x140) = *(undefined4 *)(param_2 + 0x10);
      *(undefined1 *)(lVar5 + 0x145) = 0;
      if (bVar1 != 0) {
        puVar6 = (ushort *)(lVar5 + 0xe);
        puVar7 = param_2 + 0x12;
        do {
          puVar6[-1] = *puVar7;
          *puVar6 = puVar7[1];
          *(char *)((longlong)puVar6 + 5) = (char)puVar7[2];
          puVar6[1] = puVar7[3];
          uVar8 = uVar8 - 1;
          puVar6 = puVar6 + 10;
          puVar7 = puVar7 + 4;
        } while (uVar8 != 0);
      }
      iVar4 = uVar2 + 1;
      iVar3 = 0;
      if (iVar4 != 10) {
        iVar3 = iVar4;
      }
      *(int *)(param_1 + 0x14e8) = iVar3;
      if (*(char *)(param_1 + 0xdbf) != '\0') {
        return;
      }
      if (*(char *)(param_1 + 0xdbe) != '\0') {
        return;
      }
      if ((*(int *)(param_1 + 0x570) == 0) && (*(int *)(param_1 + 0xdf8) == 0)) {
        StorPortPause(param_1,300);
        ResetActive(param_1,6,param_3);
      }
      *(undefined1 *)(param_1 + 0xdbf) = 1;
      StartIDReadsForIrElements(param_1,param_3);
      return;
    }
    uVar10 = 0xad010043;
  }
  else {
    uVar10 = 0xad01003d;
  }
  StorPortLogError(param_1,0,0,0,0,6,uVar10);
  return;
}



===== ProcessSasEnclosureStatusChange @ 140007750 =====

void ProcessSasEnclosureStatusChange(longlong param_1,longlong param_2)

{
  longlong lVar1;
  byte bVar2;
  uint uVar3;
  ushort uVar4;
  char *pcVar5;
  undefined8 *puVar6;
  longlong lVar7;
  uint uVar8;
  undefined4 uVar9;
  
  *(undefined4 *)(param_1 + 0xdc8) = 0x1e;
  if ((*(byte *)(param_1 + 0x14c0) & 0xe) == 2) {
    if (*(char *)(param_2 + 0x1e) == '\x01') {
      if (*(short *)(param_2 + 0x28) == 0) {
        uVar9 = 0xad010052;
      }
      else {
        uVar4 = GetEnclosureTableIndexFromId
                          (param_1,*(undefined8 *)(param_2 + 0x20),*(uint *)(param_2 + 0x2c));
        if (uVar4 == 0xffff) {
          bVar2 = *(byte *)(param_1 + 0x14cc);
          if ((ushort)bVar2 < *(ushort *)(param_1 + 0x59a)) {
            *(byte *)(param_1 + 0x14cc) = bVar2 + 1;
            puVar6 = (undefined8 *)((ulonglong)bVar2 * 0x1c + *(longlong *)(param_1 + 0x2a8));
            *(undefined2 *)((longlong)puVar6 + 0x12) = *(undefined2 *)(param_2 + 0x1c);
            *puVar6 = *(undefined8 *)(param_2 + 0x20);
            *(undefined4 *)(puVar6 + 1) = 0xffffffff;
            *(undefined2 *)((longlong)puVar6 + 0x14) = *(undefined2 *)(param_2 + 0x28);
            *(undefined2 *)((longlong)puVar6 + 0x16) = *(undefined2 *)(param_2 + 0x2a);
            *(undefined4 *)((longlong)puVar6 + 0xc) = *(undefined4 *)(param_2 + 0x2c);
            *(undefined2 *)(puVar6 + 2) = 0xffff;
            goto LAB_1400078f0;
          }
          uVar9 = 0xad010046;
        }
        else {
          puVar6 = (undefined8 *)((ulonglong)uVar4 * 0x1c + *(longlong *)(param_1 + 0x2a8));
          if ((*(char *)((longlong)puVar6 + 0x1b) == '\0') || (*(char *)(puVar6 + 3) != '\0')) {
            uVar3 = *(uint *)((longlong)puVar6 + 0xc);
            *(undefined2 *)((longlong)puVar6 + 0x12) = *(undefined2 *)(param_2 + 0x1c);
            *(undefined2 *)((longlong)puVar6 + 0x16) = *(undefined2 *)(param_2 + 0x2a);
            uVar8 = uVar3 | *(uint *)(param_2 + 0x2c);
            *(uint *)((longlong)puVar6 + 0xc) = uVar8;
            if ((((*(char *)(puVar6 + 3) != '\0') || (uVar3 != uVar8)) &&
                (((*(undefined1 *)(puVar6 + 3) = 0, (*(byte *)(param_1 + 0x14c0) & 1) == 0 &&
                  (*(ushort *)(puVar6 + 2) != 0xffff)) &&
                 (lVar7 = *(longlong *)(param_1 + 0x1520) +
                          (ulonglong)*(ushort *)(puVar6 + 2) * 0x14,
                 *(char *)((longlong)puVar6 + 0x1b) == '\0')))) &&
               (((*(byte *)(lVar7 + 0x10) & 0xf) != 0 || (uVar3 != uVar8)))) {
              *(short *)(lVar7 + 0x10) = *(short *)((longlong)puVar6 + 0x14) << 4;
              *(undefined4 *)(lVar7 + 0x14) = *(undefined4 *)((longlong)puVar6 + 0xc);
              *(undefined1 *)((ulonglong)*(ushort *)(puVar6 + 2) + *(longlong *)(param_1 + 0x14d8))
                   = 1;
              *(undefined1 *)((longlong)puVar6 + 0x1b) = 1;
              return;
            }
LAB_1400078f0:
            *(undefined1 *)((longlong)puVar6 + 0x1b) = 1;
            return;
          }
          uVar9 = 0xad01004c;
        }
      }
    }
    else {
      if (*(char *)(param_2 + 0x1e) != '\x02') {
        return;
      }
      pcVar5 = (char *)(*(longlong *)(param_1 + 0x2a8) + 0x18);
      for (uVar4 = 0; uVar4 < *(byte *)(param_1 + 0x14cc); uVar4 = uVar4 + 1) {
        if ((*(short *)(pcVar5 + -6) == *(short *)(param_2 + 0x1c)) && (*pcVar5 == '\0')) {
          if (uVar4 != 0xffff) {
            lVar7 = (ulonglong)uVar4 * 0x1c + *(longlong *)(param_1 + 0x2a8);
            if (*(char *)(lVar7 + 0x1b) == '\0') {
              if (*(byte *)(lVar7 + 0x18) < 0xf) {
                *(byte *)(lVar7 + 0x18) = *(byte *)(lVar7 + 0x18) + 1;
              }
              else {
                *(undefined1 *)(lVar7 + 0x1b) = 1;
              }
            }
            if (*(char *)(lVar7 + 0x18) == '\0') {
              *(undefined1 *)(lVar7 + 0x18) = 1;
            }
            if ((((*(byte *)(param_1 + 0x14c0) & 1) == 0) && (*(char *)(lVar7 + 0x1b) == '\0')) &&
               (*(ushort *)(lVar7 + 0x10) != 0xffff)) {
              lVar1 = *(longlong *)(param_1 + 0x1520) + (ulonglong)*(ushort *)(lVar7 + 0x10) * 0x14;
              uVar4 = *(short *)(lVar7 + 0x14) << 4;
              *(ushort *)(lVar1 + 0x10) = uVar4;
              *(ushort *)(lVar1 + 0x10) = *(byte *)(lVar7 + 0x18) | uVar4;
              *(undefined1 *)
               ((ulonglong)*(ushort *)(lVar7 + 0x10) + *(longlong *)(param_1 + 0x14d8)) = 1;
            }
            *(undefined1 *)(lVar7 + 0x1b) = 1;
            return;
          }
          break;
        }
        pcVar5 = pcVar5 + 0x1c;
      }
      uVar9 = 0xad01004d;
    }
    StorPortLogError(param_1,0,0,0,0,6,uVar9);
  }
  return;
}



===== ProcessSasTopologyChangeList @ 140007a20 =====

void ProcessSasTopologyChangeList(longlong param_1,ushort *param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  ushort *puVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  int iVar7;
  undefined4 uVar8;
  
  *(undefined4 *)(param_1 + 0xdc8) = 0x1e;
  bVar1 = (byte)param_2[0x12];
  uVar2 = (uint)(ushort)((bVar1 + 3) * 4);
  if (((uVar2 + 0x1c == (uint)(byte)param_2[1] << 2) && (uVar2 == (uint)*param_2 << 2)) &&
     (bVar1 != 0)) {
    uVar2 = *(uint *)(param_1 + 0x14e0);
    lVar4 = (ulonglong)uVar2 * 0x3cc + *(longlong *)(param_1 + 0x2b0);
    if (*(char *)(lVar4 + 0x3c4) == '\0') {
      puVar3 = param_2 + 0x14;
      *(ushort *)(lVar4 + 0x3c0) = param_2[0xe];
      *(ushort *)(lVar4 + 0x3c2) = param_2[0xf];
      *(char *)(lVar4 + 0x3c4) = (char)param_2[0x12];
      *(char *)(lVar4 + 0x3c5) = (char)param_2[0x10];
      *(undefined1 *)(lVar4 + 0x3c6) = *(undefined1 *)((longlong)param_2 + 0x25);
      *(undefined1 *)(lVar4 + 0x3c7) = 0;
      *(char *)(lVar4 + 0x3c8) = (char)param_2[0x13];
      if (bVar1 == 0) {
        return;
      }
      uVar6 = (ulonglong)bVar1;
      lVar5 = lVar4;
      do {
        if ((*(byte *)((longlong)puVar3 + 3) & 0xf) == 3) {
          *(char *)(lVar4 + 0x3c4) = *(char *)(lVar4 + 0x3c4) + -1;
        }
        else {
          *(ushort *)(lVar5 + 0x14) = *puVar3;
          bVar1 = *(byte *)((longlong)puVar3 + 3);
          *(undefined1 *)(lVar5 + 0x18) = 0;
          *(byte *)(lVar5 + 0x1a) = bVar1 & 0xf;
          lVar5 = lVar5 + 0x20;
        }
        puVar3 = puVar3 + 2;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
      if (lVar5 == lVar4) {
        return;
      }
      iVar7 = 0;
      if (((int)lVar4 - *(int *)(param_1 + 0x2b0)) + 0x798U <=
          (uint)*(ushort *)(param_1 + 0x59c) * 0x3cc) {
        iVar7 = uVar2 + 1;
      }
      *(int *)(param_1 + 0x14e0) = iVar7;
      if (*(char *)(param_1 + 0xdbe) != '\0') {
        return;
      }
      if (*(char *)(param_1 + 0xdbf) != '\0') {
        return;
      }
      if ((*(int *)(param_1 + 0x570) == 0) && (*(int *)(param_1 + 0xdf8) == 0)) {
        StorPortPause(param_1,300);
        ResetActive(param_1,7,param_3);
      }
      *(undefined1 *)(param_1 + 0xdbe) = 1;
      UpdateMissingCount(param_1,param_3);
      StartIDReadsForPhyEvents(param_1,param_3);
      return;
    }
    uVar8 = 0xad010043;
  }
  else {
    uVar8 = 0xad01003d;
  }
  StorPortLogError(param_1,0,0,0,0,6,uVar8);
  return;
}



===== ReadIDs @ 140007c30 =====

undefined8 ReadIDs(longlong param_1,int param_2)

{
  ulonglong uVar1;
  undefined8 uVar2;
  byte bVar3;
  longlong lVar4;
  
  uVar1 = (ulonglong)*(uint *)(param_1 + 0x14e4);
  lVar4 = uVar1 * 0x3cc + *(longlong *)(param_1 + 0x2b0);
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
  *(undefined1 *)(param_1 + 0xdc0) = 1;
  *(undefined1 *)(param_1 + 0x5b6) = 1;
  uVar2 = SendExtendedConfigPageMessage
                    (param_1,'\x01',(char *)(param_1 + 0x1530),
                     *(ushort *)(uVar1 + 0x14) | 0x20000000,(int)*(undefined8 *)(param_1 + 0x1538),
                     param_2);
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== ReadIrIDs @ 140007cd0 =====

ulonglong ReadIrIDs(longlong param_1,int param_2)

{
  longlong lVar1;
  byte bVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  byte bVar6;
  longlong lVar7;
  
  uVar4 = (ulonglong)*(uint *)(param_1 + 0x14ec);
  lVar7 = uVar4 * 0x148 + *(longlong *)(param_1 + 0x2b8);
  bVar6 = *(byte *)(lVar7 + 0x145);
  while( true ) {
    if (*(byte *)(lVar7 + 0x144) <= bVar6) {
      return uVar4 & 0xffffffffffffff00;
    }
    *(byte *)(lVar7 + 0x145) = bVar6;
    lVar1 = lVar7 + (ulonglong)bVar6 * 0x14;
    bVar2 = *(byte *)(lVar7 + 0x13 + (ulonglong)bVar6 * 0x14);
    uVar3 = bVar2 - 1;
    uVar4 = (ulonglong)uVar3;
    if (((((byte)uVar3 < 3) || (bVar2 == 6)) && (*(char *)(lVar1 + 0x12) == '\0')) &&
       (uVar4 = 0, (*(byte *)(lVar1 + 0xc) & 0xf) == 0)) break;
    bVar6 = bVar6 + 1;
  }
  *(undefined1 *)(param_1 + 0xdc1) = 1;
  uVar5 = SendConfigPageMessage
                    (param_1,'\x01',(undefined4 *)(param_1 + 0x1508),
                     *(ushort *)(lVar1 + 0xe) | 0x10000000,(int)*(undefined8 *)(param_1 + 0x1510),
                     param_2);
  return CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
}



===== RemoveDevice @ 140007d90 =====

void RemoveDevice(longlong param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  longlong lVar3;
  undefined1 *puVar4;
  uint uVar5;
  ulonglong uVar6;
  ushort *puVar7;
  ushort *puVar8;
  
  uVar2 = *(uint *)(param_1 + 0x5b8);
  uVar6 = (ulonglong)uVar2;
  puVar8 = *(ushort **)(param_1 + 0x2c0);
  uVar5 = 0;
  puVar7 = puVar8;
  if (uVar2 != 0) {
    do {
      if (puVar7[1] != 0) {
        if ((char)puVar7[2] == '\0') {
          puVar8 = *(ushort **)(param_1 + 0x278);
          *(undefined1 *)(param_1 + 0xdbb) = 1;
          ZeroMemory((undefined1 *)puVar8,0x34);
          *puVar8 = puVar7[1];
          *(undefined1 *)((longlong)puVar8 + 3) = 1;
          *(undefined1 *)((longlong)puVar8 + 5) = 3;
          QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x5b0) * 0x10000 + 6,0,param_2)
          ;
          *(undefined4 *)(param_1 + 0x574) = 0xf;
          *(undefined1 *)(puVar7 + 2) = 1;
          return;
        }
        if ((puVar7[1] != 0) && ((char)puVar7[2] != '\0')) {
          puVar4 = *(undefined1 **)(param_1 + 0x278);
          ZeroMemory(puVar4,0x2c);
          puVar4[3] = 0x1b;
          *puVar4 = 0xd;
          *(ushort *)(puVar4 + 4) = puVar7[1];
          QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x5b0) * 0x10000 + 8,0,param_2)
          ;
          puVar7[1] = 0;
          *(undefined1 *)(puVar7 + 2) = 0;
          *(undefined1 *)(param_1 + 0x2d0) = 1;
          return;
        }
      }
      uVar5 = uVar5 + 1;
      puVar7 = puVar7 + 4;
    } while (uVar5 < uVar2);
  }
  if (((*(byte *)(param_1 + 0x14c0) & 1) == 0) && (uVar2 != 0)) {
    do {
      uVar1 = *puVar8;
      if (uVar1 != 0xffff) {
        lVar3 = *(longlong *)(param_1 + 0x1520);
        *(undefined8 *)(lVar3 + 8 + (ulonglong)uVar1 * 0x14) = 0;
        *(undefined8 *)(lVar3 + 0x10 + (ulonglong)uVar1 * 0x14) = 0;
        *(undefined1 *)((ulonglong)*puVar8 + *(longlong *)(param_1 + 0x14d8)) = 1;
        *(undefined1 *)((ulonglong)*puVar8 + *(longlong *)(param_1 + 0x14d0)) = 0;
        *puVar8 = 0xffff;
      }
      puVar8 = puVar8 + 4;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  CompressEnclosureTable(param_1);
  AddDevice(param_1,param_2);
  return;
}



===== SODCheckMapEntry @ 140007f40 =====

void SODCheckMapEntry(longlong param_1,longlong param_2,uint param_3,uint param_4,int param_5)

{
  longlong lVar1;
  ushort uVar2;
  short sVar3;
  int *piVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  
  if (param_3 < param_4) {
    piVar4 = (int *)(param_2 + 4);
    uVar6 = (ulonglong)(param_4 - param_3);
    do {
      if ((((piVar4[4] & 0x20000000U) == 0) || (piVar4[-1] != 0)) || (*piVar4 != 0)) {
        if (((piVar4[4] & 0x20000000U) != 0) && (*(char *)((longlong)piVar4 + 0x1d) == '\0')) {
          if ((*(byte *)(piVar4 + 7) < 0xf) &&
             ((*(byte *)(piVar4 + 7) = *(byte *)(piVar4 + 7) + 1,
              (*(byte *)(param_1 + 0x14c0) & 1) == 0 && (*(ushort *)(piVar4 + 5) != 0xffff)))) {
            lVar1 = *(longlong *)(param_1 + 0x1520) + (ulonglong)*(ushort *)(piVar4 + 5) * 0x14;
            *(int *)(lVar1 + 8) = piVar4[-1];
            *(int *)(lVar1 + 0xc) = *piVar4;
            sVar3 = (short)piVar4[6] * 0x80;
            *(short *)(lVar1 + 0x12) = sVar3;
            *(short *)(lVar1 + 0x12) = *(short *)((longlong)piVar4 + 0x1a) + sVar3;
            *(ushort *)(lVar1 + 0x10) = (ushort)*(byte *)(piVar4 + 7);
            *(undefined8 *)(lVar1 + 0x14) = 0;
            ZeroMemory(*(undefined1 **)(param_1 + 0x1528),8);
            memcpy((void *)(*(longlong *)(param_1 + 0x1528) + 8),(void *)(lVar1 + 8),0x14);
            uVar2 = *(ushort *)(piVar4 + 5);
            uVar7 = *(ulonglong *)(param_1 + 0x1528);
            *(undefined1 *)(param_1 + 0xdc2) = 1;
            *(undefined1 *)(param_1 + 0x5b6) = 1;
            SendExtendedConfigPageMessage
                      (param_1,'\x04',(char *)(param_1 + 0x1518),uVar2 | 0x10000,(int)uVar7,param_5)
            ;
            uVar5 = 0;
            do {
              PollLSImpiIsr(param_1,param_5);
              if (*(char *)(param_1 + 0xdc2) == '\0') goto LAB_1400080ea;
              StorPortStallExecution(500);
              uVar5 = uVar5 + 1;
            } while (uVar5 < 120000);
            if (*(char *)(param_1 + 0xdc2) != '\0') {
              StorPortLogError(param_1,0,0,0,uVar7 & 0xffffffffffffff00,6,0xad01004b);
            }
          }
          goto LAB_1400080ea;
        }
      }
      else {
LAB_1400080ea:
        *(undefined1 *)((longlong)piVar4 + 0x1d) = 1;
      }
      piVar4 = piVar4 + 10;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  return;
}



===== SendSTPIdentifyCommand @ 140008130 =====

void SendSTPIdentifyCommand(longlong param_1,uint param_2,undefined2 param_3,int param_4)

{
  ushort uVar1;
  undefined2 *puVar2;
  undefined1 uVar3;
  byte bVar4;
  
  puVar2 = *(undefined2 **)(param_1 + 0x278);
  uVar1 = *(ushort *)(param_1 + 0x5b0);
  ZeroMemory((undefined1 *)puVar2,0x40);
  *(undefined1 *)((longlong)puVar2 + 3) = 0x1c;
  puVar2[2] = 0x11;
  *puVar2 = param_3;
  *(undefined4 *)(puVar2 + 0xc) = 0x200;
  puVar2[0xe] = 0x8027;
  uVar3 = 0xec;
  if ((param_2 >> 0xd & 1) != 0) {
    uVar3 = 0xa1;
  }
  *(undefined1 *)(puVar2 + 0xf) = uVar3;
  *(undefined4 *)(puVar2 + 0x18) = 0xd3000200;
  *(int *)(puVar2 + 0x1a) = *(int *)(param_1 + 0xde0) - *(int *)(param_1 + 0x100);
  *(undefined4 *)(puVar2 + 0x1c) = *(undefined4 *)(param_1 + 0x1ec);
  QueueRequestDescriptor(param_1,(uint)uVar1 * 0x10000 + 8,0,param_4);
  bVar4 = GtfStartTimer(param_1,1,5,AtaIdentifyTimeout,0,param_4);
  *(byte *)(param_1 + 0xde8) = bVar4;
  if (((bVar4 == 0xfe) && (*(char *)(param_1 + 0x308) != '\0')) &&
     ((*(uint *)(param_1 + 0x30c) & 0x233) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x233,(undefined1 *)0x0,0
                ,param_4);
  }
  return;
}



===== StartIDReadsForIrElements @ 140008260 =====

void StartIDReadsForIrElements(longlong param_1,int param_2)

{
  undefined8 uVar1;
  
  uVar1 = ReadIrIDs(param_1,param_2);
  if ((char)uVar1 == '\0') {
    *(undefined1 *)(param_1 + 0xdc1) = 0;
    AddOrRemoveIrVolume(param_1,param_2);
  }
  return;
}



===== StartIDReadsForPhyEvents @ 1400082a0 =====

void StartIDReadsForPhyEvents(longlong param_1,int param_2)

{
  undefined8 uVar1;
  
  uVar1 = ReadIDs(param_1,param_2);
  if ((char)uVar1 == '\0') {
    *(undefined1 *)(param_1 + 0xdc0) = 0;
    RemoveDevice(param_1,param_2);
  }
  return;
}



===== UpdateIrMissingCount @ 1400082e0 =====

void UpdateIrMissingCount(longlong param_1,uint param_2,undefined8 *param_3)

{
  int *piVar1;
  longlong lVar2;
  char cVar3;
  byte bVar4;
  ushort uVar5;
  uint uVar6;
  ulonglong uVar7;
  int *piVar8;
  int iStackX_c;
  
  piVar1 = (int *)(*(longlong *)(param_1 + 0x2c8) + (ulonglong)param_2 * 0x28);
  if ((*(byte *)(param_1 + 0x14c0) & 1) == 0) {
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
    uVar7 = (ulonglong)*(ushort *)(piVar1 + 6);
    if (*(ushort *)(piVar1 + 6) == 0xffff) {
      if ((byte)(*(char *)((longlong)param_3 + 0x13) - 1U) < 2) {
        uVar7 = 0;
        piVar8 = (int *)(*(longlong *)(param_1 + 0x1520) + 8);
        if (*(ushort *)(param_1 + 0x14bc) != 0) {
          iStackX_c = (int)((ulonglong)*param_3 >> 0x20);
          do {
            if (((*(char *)(uVar7 + *(longlong *)(param_1 + 0x14d0)) != '\0') &&
                (*piVar8 == (int)*param_3)) && (piVar8[1] == iStackX_c)) {
              if ((short)uVar7 != -1) goto LAB_140008417;
              break;
            }
            uVar5 = (short)uVar7 + 1;
            uVar7 = (ulonglong)uVar5;
            piVar8 = piVar8 + 5;
          } while (uVar5 < *(ushort *)(param_1 + 0x14bc));
        }
      }
      else if (*(char *)((longlong)param_3 + 0x13) == '\a') {
        return;
      }
      uVar7 = 0;
      while( true ) {
        uVar6 = (uint)uVar7;
        if (*(ushort *)(param_1 + 0x14bc) <= (ushort)uVar7) break;
        if (*(char *)(uVar7 + *(longlong *)(param_1 + 0x14d0)) == '\0') goto LAB_140008411;
        uVar7 = (ulonglong)(ushort)((ushort)uVar7 + 1);
      }
      uVar6 = 0xffff;
LAB_140008411:
      *(undefined1 *)((longlong)piVar1 + 0x21) = 0;
    }
    else {
LAB_140008417:
      uVar6 = (uint)uVar7;
      lVar2 = *(longlong *)(param_1 + 0x1520) + uVar7 * 0x14;
      if (((*(int *)(lVar2 + 8) == *piVar1) && (*(int *)(lVar2 + 0xc) == piVar1[1])) &&
         ((*(byte *)(lVar2 + 0x10) & 0xf) == *(byte *)(piVar1 + 8))) {
        *(undefined1 *)((longlong)piVar1 + 0x21) = 1;
      }
    }
    if ((short)uVar6 == -1) {
      if ((*(char *)(param_1 + 0x3d51) != '\0') && (*(char *)(param_1 + 0x3d50) == '\0')) {
        StorPortLogError(param_1,0,0,0,0,6,0xad010045);
        *(undefined1 *)(param_1 + 0x3d50) = 1;
      }
      *(undefined1 *)((longlong)piVar1 + 0x21) = 1;
    }
    else if (*(char *)((longlong)piVar1 + 0x21) == '\0') {
      *(short *)(piVar1 + 6) = (short)uVar6;
      *(undefined1 *)((longlong)piVar1 + 0x21) = 1;
      uVar7 = (ulonglong)uVar6;
      lVar2 = *(longlong *)(param_1 + 0x1520) + uVar7 * 0x14;
      *(undefined8 *)(lVar2 + 8) = *(undefined8 *)piVar1;
      bVar4 = *(byte *)(piVar1 + 8);
      *(short *)(lVar2 + 0x12) = (short)param_2;
      *(undefined4 *)(lVar2 + 0x14) = 0;
      *(ushort *)(lVar2 + 0x10) = (ushort)(bVar4 & 0xf);
      *(undefined1 *)(uVar7 + *(longlong *)(param_1 + 0x14d8)) = 1;
      *(undefined1 *)(uVar7 + *(longlong *)(param_1 + 0x14d0)) = 1;
    }
  }
  return;
}



===== UpdateMissingCount @ 140008500 =====

ulonglong UpdateMissingCount(longlong param_1,int param_2)

{
  short *psVar1;
  byte bVar2;
  ushort uVar3;
  longlong lVar4;
  short *psVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  uint uVar8;
  undefined8 *puVar9;
  byte bVar10;
  longlong lVar11;
  short *in_stack_ffffffffffffffb8;
  
  uVar8 = *(uint *)(param_1 + 0x14e4);
  uVar7 = (ulonglong)uVar8;
  lVar11 = uVar7 * 0x3cc + *(longlong *)(param_1 + 0x2b0);
  bVar10 = *(byte *)(lVar11 + 0x3c7);
  if (*(byte *)(lVar11 + 0x3c4) <= bVar10) {
    *(undefined1 *)(lVar11 + 0x3c7) = 0;
    return (ulonglong)(uint3)(uVar8 >> 8) << 8;
  }
  do {
    puVar9 = (undefined8 *)((ulonglong)bVar10 * 0x20 + lVar11);
    psVar1 = (short *)((longlong)puVar9 + 0x14);
    if (((*(short *)((longlong)puVar9 + 0x14) != 0) &&
        (*(char *)((longlong)puVar9 + 0x1a) == '\x02')) &&
       (*(char *)((longlong)puVar9 + 0x19) == '\0')) {
      psVar5 = (short *)(*(longlong *)(param_1 + 0x2c8) + 0x1a);
      for (uVar8 = 0; uVar8 < *(uint *)(param_1 + 0x5b8); uVar8 = uVar8 + 1) {
        if (*psVar5 == *(short *)((longlong)puVar9 + 0x14)) {
          if (uVar8 != 0xffffffff) {
            *puVar9 = 0;
            puVar9[1] = 0;
            *(undefined4 *)(puVar9 + 2) = 0;
            *psVar1 = 0;
            *(undefined4 *)((longlong)puVar9 + 0x16) = 0;
            *(undefined2 *)((longlong)puVar9 + 0x1a) = 0;
            *(undefined1 *)((longlong)puVar9 + 0x1c) = 0;
            lVar4 = *(longlong *)(param_1 + 0x2c8);
            uVar6 = (ulonglong)uVar8;
            if (*(char *)(lVar4 + 0x21 + uVar6 * 0x28) == '\0') {
              bVar2 = *(byte *)(lVar4 + 0x20 + uVar6 * 0x28);
              if (bVar2 < 0xf) {
                *(byte *)(lVar4 + 0x20 + uVar6 * 0x28) = bVar2 + 1;
              }
              else {
                *(undefined1 *)(lVar4 + 0x21 + uVar6 * 0x28) = 1;
              }
            }
            if (*(char *)(lVar4 + 0x20 + uVar6 * 0x28) == '\0') {
              *(undefined1 *)(lVar4 + 0x20 + uVar6 * 0x28) = 1;
              *(undefined1 *)(param_1 + 0x2d0) = 1;
            }
            AddToRemovalTable(param_1,*(short *)(lVar4 + 0x1a + uVar6 * 0x28),0,param_2);
            uVar7 = 0;
            if (((*(byte *)(param_1 + 0x14c0) & 0xf) == 0) &&
               (*(char *)(lVar4 + 0x21 + uVar6 * 0x28) == '\0')) {
              uVar3 = *(ushort *)(lVar4 + 0x18 + uVar6 * 0x28);
              uVar7 = (ulonglong)uVar3;
              if (uVar3 != 0xffff) {
                *(ushort *)(*(longlong *)(param_1 + 0x1520) + 0x10 + (ulonglong)uVar3 * 0x14) =
                     (ushort)*(byte *)(lVar4 + 0x20 + uVar6 * 0x28);
                uVar7 = *(ulonglong *)(param_1 + 0x14d8);
                *(undefined1 *)(*(ushort *)(lVar4 + 0x18 + uVar6 * 0x28) + uVar7) = 1;
              }
            }
            *(byte *)(lVar11 + 0x3c7) = bVar10;
            *(undefined1 *)(lVar4 + 0x21 + uVar6 * 0x28) = 1;
            goto LAB_140008704;
          }
          break;
        }
        psVar5 = psVar5 + 0x14;
      }
      in_stack_ffffffffffffffb8 =
           (short *)((ulonglong)in_stack_ffffffffffffffb8 & 0xffffffffffffff00);
      StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffffb8,6,0xad01004a);
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x240) != 0)) {
        in_stack_ffffffffffffffb8 = psVar1;
        RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x240,
                    (undefined1 *)psVar1,2,param_2);
      }
      uVar7 = AddToRemovalTable(param_1,*psVar1,0,param_2);
    }
LAB_140008704:
    bVar10 = bVar10 + 1;
    if (*(byte *)(lVar11 + 0x3c4) <= bVar10) {
      *(undefined1 *)(lVar11 + 0x3c7) = 0;
      return uVar7 & 0xffffffffffffff00;
    }
  } while( true );
}



===== BringIOCToOperationalState @ 140008760 =====

undefined8 BringIOCToOperationalState(longlong param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  undefined7 extraout_var;
  int *piVar4;
  ulonglong uVar5;
  int iVar6;
  
  bVar3 = SendIOCInitMessage(param_1);
  uVar5 = CONCAT71(extraout_var,bVar3);
  if (bVar3) {
    uVar1 = *(ushort *)(param_1 + 0x248);
    uVar2 = *(ushort *)(param_1 + 0x23e);
    iVar6 = *(int *)(param_1 + 0x210);
    piVar4 = *(int **)(param_1 + 0x250);
    if (uVar1 != 0) {
      uVar5 = (ulonglong)uVar1;
      do {
        *piVar4 = iVar6;
        piVar4 = piVar4 + 1;
        iVar6 = iVar6 + (uint)uVar2;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
    **(uint **)(param_1 + 0x58) = (uint)uVar1;
    LOCK();
    UNLOCK();
    *(ushort *)(param_1 + 0x218) = uVar1;
    ReadAndSetSASPages(param_1,param_2);
    ProcessDPMPage0(param_1);
    uVar5 = EnableDisableEvents(param_1,'\x01',param_2);
    if ((char)uVar5 != '\0') {
      uVar5 = SendPortEnables(param_1,param_2);
      if ((char)uVar5 != '\0') {
        return CONCAT71((int7)(uVar5 >> 8),1);
      }
    }
  }
  return uVar5 & 0xffffffffffffff00;
}



===== BuildIoctlScatterGather @ 140008830 =====

int BuildIoctlScatterGather
              (longlong param_1,longlong param_2,uint *param_3,uint param_4,short *param_5,
              int param_6)

{
  char cVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  ulonglong uVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  char cVar15;
  uint *puVar16;
  longlong lVar17;
  byte bVar18;
  uint uVar19;
  int local_res10;
  uint local_res20;
  int local_68;
  uint *local_60;
  
  local_68 = 0;
  local_res10 = 0;
  uVar19 = 0;
  iVar2 = 0x30;
  uVar10 = 0x14;
  if (*param_5 != 1) {
    uVar10 = 0x10;
  }
  bVar18 = *(byte *)(param_1 + 0x24e) & 1;
  if (bVar18 == 0) {
    lVar17 = 2;
    uVar6 = 8;
  }
  else {
    uVar10 = uVar10 | 2;
    iVar2 = 0x32;
    lVar17 = 3;
    uVar6 = 0xc;
  }
  puVar7 = param_3 + (ushort)param_5[1];
  uVar14 = (uint)((((uint)*(ushort *)(param_1 + 0x240) + (uint)(ushort)param_5[1] * -4) - (int)uVar6
                  ) / uVar6);
  puVar3 = (uint *)StorPortGetScatterGatherList(param_1,param_2);
  uVar11 = param_6 - *(int *)(param_2 + 0x40);
  uVar12 = puVar3[6];
  uVar13 = *puVar3;
  puVar3 = puVar3 + 4;
  puVar4 = puVar3;
  if (uVar12 <= uVar11) {
    do {
      puVar3 = puVar4 + 6;
      uVar11 = uVar11 - uVar12;
      uVar13 = uVar13 - 1;
      uVar12 = puVar4[8];
      puVar4 = puVar3;
    } while (uVar12 <= uVar11);
  }
  uVar8 = *(uint *)(param_5 + 2);
  uVar12 = 0;
  puVar4 = puVar3;
  if (uVar13 != 0) {
    do {
      uVar5 = puVar4[2];
      if (puVar4 == puVar3) {
        uVar5 = uVar5 - uVar11;
      }
      if (uVar8 < uVar5) {
        local_68 = uVar5 - uVar8;
        uVar5 = uVar8;
      }
      uVar8 = uVar8 - uVar5;
      if (uVar8 == 0) break;
      puVar4 = puVar4 + 6;
      uVar12 = uVar12 + 1;
    } while (uVar12 < uVar13);
  }
  uVar12 = uVar12 + 1;
  uVar13 = *(uint *)(param_1 + 0x590);
  if (uVar13 < uVar12) {
    if (uVar12 - uVar13 == 0) {
      local_res10 = 0;
    }
    else {
      local_res10 = puVar3[(ulonglong)uVar13 * 6 + 2] * (uVar12 - uVar13);
    }
    local_res10 = local_res10 - local_68;
    uVar12 = uVar13;
  }
  puVar4 = puVar3;
  puVar16 = (uint *)0x0;
  uVar13 = uVar14;
  local_res20 = param_4;
  param_5._0_4_ = uVar14;
  local_60 = param_3;
  if (uVar12 <= uVar14 + 1) {
    uVar13 = uVar12;
    local_60 = param_3;
  }
  while( true ) {
    puVar9 = puVar7;
    uVar8 = 0;
    if (uVar13 != 0) {
      uVar6 = (ulonglong)uVar13;
      do {
        *puVar7 = puVar4[2] | uVar10 << 0x18;
        puVar7[1] = *puVar4;
        if (bVar18 != 0) {
          puVar7[2] = puVar4[1];
        }
        if ((puVar4 == puVar3) && (uVar11 != 0)) {
          *puVar7 = *puVar7 - uVar11;
          puVar7[1] = puVar7[1] + uVar11;
        }
        puVar7 = puVar7 + lVar17;
        puVar4 = puVar4 + 6;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
      puVar9 = puVar7;
      uVar14 = (uint)param_5;
      uVar8 = uVar13;
    }
    uVar19 = uVar19 + uVar8;
    cVar15 = (char)uVar8;
    cVar1 = (char)lVar17;
    if (uVar12 <= uVar19) break;
    puVar9[-lVar17] = puVar9[-lVar17] | 0x80000000;
    if (uVar19 == uVar14) {
      *(char *)((longlong)param_3 + 2) = (char)((longlong)puVar9 - (longlong)local_60 >> 2);
      uVar14 = (uint)*(ushort *)(param_1 + 0x23c);
      param_5._0_4_ = uVar14;
    }
    if (puVar16 != (uint *)0x0) {
      *(char *)((longlong)puVar16 + 2) = cVar1 * cVar15;
      *(ushort *)puVar16 = (ushort)(byte)((cVar15 + '\x01') * cVar1 * '\x04');
    }
    puVar7 = (uint *)((longlong)local_60 + (ulonglong)*(ushort *)(param_1 + 0x240));
    local_res20 = local_res20 + *(ushort *)(param_1 + 0x240);
    *puVar9 = iVar2 << 0x18;
    puVar9[1] = local_res20;
    if (bVar18 != 0) {
      puVar9[2] = *(uint *)(param_1 + 0x1ec);
    }
    puVar16 = puVar9;
    uVar13 = uVar14;
    local_60 = puVar7;
    if (uVar12 - uVar19 <= uVar14 + 1) {
      uVar13 = uVar12 - uVar19;
    }
  }
  puVar9[-lVar17] = puVar9[-lVar17] | 0xc1000000;
  if (local_68 != 0) {
    puVar9[-lVar17] = puVar9[-lVar17] - local_68;
  }
  if (puVar16 != (uint *)0x0) {
    *(undefined1 *)((longlong)puVar16 + 2) = 0;
    *(ushort *)puVar16 = (ushort)(byte)(cVar1 * cVar15 * '\x04');
  }
  return local_res10;
}



===== CheckForIRShutdown @ 140008b40 =====

ulonglong CheckForIRShutdown(longlong param_1,char param_2,undefined4 param_3)

{
  undefined8 *puVar1;
  undefined4 *puVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  uint uVar5;
  uint local_res8 [2];
  uint local_res20 [2];
  
  uVar3 = (ulonglong)*(uint *)(param_1 + 0xdec);
  if ((*(uint *)(param_1 + 0xdec) >> 0xc & 1) != 0) {
    uVar3 = GetIrMapRange(param_1,(int *)local_res8,(int *)local_res20);
    if (local_res8[0] <= local_res20[0]) {
      while (uVar5 = local_res8[0],
            *(short *)(*(longlong *)(param_1 + 0x2c8) + 0x1a + (ulonglong)uVar5 * 0x28) == 0) {
        local_res8[0] = uVar5 + 1;
        if (local_res20[0] < uVar5 + 1) {
          return (ulonglong)(uint3)(uVar5 >> 8) << 8;
        }
      }
      puVar1 = *(undefined8 **)(param_1 + 0x548);
      uVar5 = 0;
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[3] = 0;
      *(undefined1 *)((longlong)puVar1 + 3) = 0x15;
      *(undefined1 *)puVar1 = 0x20;
      *(undefined1 *)(param_1 + 0xda6) = 1;
      **(int **)(param_1 + 0xe8) = (uint)*(ushort *)(param_1 + 0x5aa) * 0x10000 + 8;
      LOCK();
      UNLOCK();
      puVar2 = *(undefined4 **)(param_1 + 0xf0);
      *puVar2 = 0;
      LOCK();
      UNLOCK();
      if (param_2 == '\0') {
        *(undefined4 *)(param_1 + 0x574) = 6;
        return CONCAT71((int7)((ulonglong)puVar2 >> 8),1);
      }
      do {
        uVar4 = PollLSImpiIsr(param_1,param_3);
        if (*(char *)(param_1 + 0xda6) == '\0') break;
        uVar4 = StorPortStallExecution(500);
        uVar5 = uVar5 + 1;
      } while (uVar5 < 10000);
      if (uVar5 == 10000) {
        uVar4 = StorPortLogError(param_1,0,0,0,0,6,0xad010070);
      }
      return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
    }
  }
  return uVar3 & 0xffffffffffffff00;
}



===== CheckInqFlagReplies @ 140008c90 =====

undefined8 CheckInqFlagReplies(longlong param_1,undefined1 *param_2,byte *param_3,int param_4)

{
  undefined8 *puVar1;
  ushort uVar2;
  uint uVar3;
  longlong lVar4;
  ushort *puVar5;
  longlong lVar6;
  char *pcVar7;
  undefined8 uVar8;
  int *piVar9;
  longlong lVar10;
  ulonglong uVar11;
  byte bVar12;
  undefined1 uVar13;
  byte bVar14;
  int iVar15;
  char cVar16;
  size_t _Size;
  undefined1 *puVar17;
  bool bVar18;
  bool bVar19;
  bool bVar20;
  bool local_res8;
  char local_res18 [8];
  int local_res20;
  ulonglong in_stack_ffffffffffffff78;
  undefined1 *puVar21;
  
  uVar2 = *(ushort *)(param_3 + 2);
  puVar17 = (undefined1 *)0x0;
  puVar1 = (undefined8 *)(*(longlong *)(param_1 + 0x2a0) + (ulonglong)uVar2 * 0x18);
  if ((*(byte *)(*(longlong *)(param_1 + 0x2a0) + 0x13 + (ulonglong)uVar2 * 0x18) & 4) == 0) {
    return 0;
  }
  bVar18 = (*param_3 & 0xf) != 1;
  if (!bVar18) {
    puVar17 = (undefined1 *)((ulonglong)*(uint *)(param_3 + 4) + *(longlong *)(param_1 + 0x100));
  }
  *param_2 = 1;
  lVar4 = puVar1[1];
  local_res20 = param_4;
  if (lVar4 == 0) {
    uVar8 = StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffff78 & 0xffffffffffffff00,6,
                             0xad010024);
    return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
  }
  uVar3 = *(uint *)(lVar4 + 0x3c);
  puVar5 = (ushort *)*puVar1;
  local_res18[0] = (char)puVar5[0x20];
  lVar6 = *(longlong *)(lVar4 + 0x68);
  bVar14 = *(byte *)((longlong)puVar5 + 0x41);
  if (*(char *)(lVar4 + 3) == '\0') {
    *(undefined1 *)(*(longlong *)(lVar6 + 0x38) + 8) = 0;
    *(undefined1 *)(lVar4 + 3) = 1;
  }
  piVar9 = (int *)StorPortGetLogicalUnit
                            (param_1,*(undefined1 *)(lVar6 + 0x52),*(undefined1 *)(lVar6 + 0x53));
  puVar21 = (undefined1 *)CONCAT44((int)(in_stack_ffffffffffffff78 >> 0x20),param_4);
  lVar10 = FindMappingTableEntry
                     (param_1,(ushort)*(byte *)(lVar6 + 0x52),(ushort)*(byte *)(lVar6 + 0x53),
                      0xffffffff);
  if (lVar10 == 0) {
    *(undefined1 *)(lVar4 + 3) = 10;
    param_2 = (undefined1 *)StorPortNotification(0,param_1,lVar4,0,puVar21);
    goto LAB_1400092c8;
  }
  pcVar7 = *(char **)(lVar4 + 0x40);
  bVar12 = (byte)(*(uint *)(param_1 + 0xdec) >> 0xb) & 1;
  bVar19 = *(char *)(param_1 + 0xdcf) != '\0';
  if (local_res18[0] == '\x12') {
    if ((bVar14 & 1) != 0) {
      if (bVar18) {
LAB_1400090e8:
        bVar14 = pcVar7[3];
        if (0x16 < bVar14) {
          bVar14 = 0x16;
        }
        uVar11 = 0;
        if (bVar14 != 0) {
          do {
            if (pcVar7[uVar11 + 4] == -0x70) goto LAB_140009244;
            bVar12 = (char)uVar11 + 1;
            uVar11 = (ulonglong)bVar12;
          } while (bVar12 < bVar14);
        }
      }
      else if ((((*(ushort *)(puVar17 + 0xe) & 0x7fff) == 0) ||
               ((*(ushort *)(puVar17 + 0xe) & 0x7fff) == 0x45)) && (puVar17[0xc] == '\0'))
      goto LAB_1400090e8;
      if ((*(uint *)(lVar10 + 0x14) >> 0x1e & 1) == 0) {
        uVar11 = 0;
        do {
          bVar14 = (byte)uVar11;
          if (*(char *)(uVar11 + 0xe + (longlong)piVar9) != (&vendorHP)[uVar11]) break;
          bVar14 = bVar14 + 1;
          uVar11 = (ulonglong)bVar14;
        } while (bVar14 < 8);
        if (bVar14 == 8) {
          *(uint *)(lVar10 + 0x14) = *(uint *)(lVar10 + 0x14) | 0x40000000;
          puVar5[0x12] = 6;
          puVar5[0x20] = 0;
          puVar5[0x21] = 0;
          puVar5[0x22] = 0;
          puVar5[0x23] = 0;
          puVar5[0x24] = 0;
          puVar5[0x25] = 0;
          puVar5[0x26] = 0;
          puVar5[0x27] = 0;
          *(uint *)(puVar5 + 0x30) = *(uint *)(puVar5 + 0x30) & 0xff000000;
          puVar5[0x20] = 0x1c2;
          puVar5[0xe] = 0;
          puVar5[0xf] = 0;
          goto LAB_1400091eb;
        }
      }
      goto LAB_140009249;
    }
    if (bVar18) {
      cVar16 = '\0';
      uVar13 = 1;
    }
    else {
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x2001) != 0)) {
        puVar21 = puVar17;
        RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x2001,puVar17,0x30,
                    local_res20);
      }
      cVar16 = puVar17[0xc];
      if ((cVar16 - 8U & 0xdf) == 0) {
        *(char *)(*(longlong *)(lVar6 + 0x38) + 8) = cVar16;
        *(undefined1 *)(lVar4 + 3) = 5;
        param_2 = (undefined1 *)StorPortNotification(0,param_1,lVar4,lVar10,puVar21);
        goto LAB_1400092c8;
      }
      if (((puVar17[0xd] & 0x10) != 0) && ((char)*(undefined4 *)(puVar17 + 0x1c) == '\x02')) {
        *(undefined1 *)(lVar10 + 0x22) = 0;
        *(undefined1 *)((longlong)puVar1 + 0x13) = 0;
        return (ulonglong)puVar1 & 0xffffffffffffff00;
      }
      if ((*(ushort *)(puVar17 + 0xe) & 0x7fff) == 0x45) {
        if ((puVar17[0xd] & 1) != 0) goto LAB_1400090b5;
        uVar13 = 0x12;
        *(undefined4 *)(lVar4 + 0x3c) = *(undefined4 *)(puVar17 + 0x14);
      }
      else {
        if (((*(ushort *)(puVar17 + 0xe) & 0x7fbf) != 0) || (cVar16 != '\0')) goto LAB_1400090b5;
        uVar13 = 1;
      }
    }
    if (pcVar7 == (char *)0x0) {
      bVar20 = false;
      local_res8 = false;
      bVar12 = 0;
    }
    else {
      bVar20 = *pcVar7 == '\0';
      if (bVar20) {
        *(undefined1 *)(lVar10 + 0x24) = 1;
      }
      local_res8 = bVar20 && bVar19;
      bVar20 = bVar20 && bVar19;
      if ((*pcVar7 != '\x01') || ((*(uint *)(lVar10 + 0x14) & 0x400) == 0)) {
        bVar12 = 0;
      }
    }
    if (piVar9 != (int *)0x0) {
      if (bVar20) {
        *(undefined1 *)(piVar9 + 1) = 0;
      }
      *(undefined1 *)((longlong)piVar9 + 5) = 0;
    }
    *(char *)(*(longlong *)(lVar6 + 0x38) + 8) = cVar16;
    *(undefined1 *)(lVar4 + 3) = uVar13;
    if ((char)*(undefined4 *)(lVar10 + 0x14) < '\0') {
      StorPortSetDeviceQueueDepth
                (param_1,*(undefined1 *)(lVar6 + 0x52),*(undefined1 *)(lVar6 + 0x53),
                 *(undefined1 *)(lVar6 + 0x54),*(undefined4 *)(param_1 + 0x588));
    }
    if ((piVar9 != (int *)0x0) && (((local_res8 || (bVar12 != 0)) && (0x19 < uVar3)))) {
      if ((!local_res8) || ((pcVar7[5] & 1U) == 0)) {
        if (bVar12 == 0) goto LAB_14000925c;
        *(undefined1 *)((longlong)puVar5 + 0x41) = 1;
        *(undefined2 *)((longlong)puVar5 + 0x43) = 0x1a00;
        iVar15 = 0x1a;
        memcpy((void *)((longlong)piVar9 + 6),*(void **)(lVar4 + 0x40),0x1a);
        puVar5[0xe] = 0x1a;
        puVar5[0xf] = 0;
        if ((*(uint *)(puVar5 + 0x30) & 0xffffff) < 0x1a) goto LAB_140009037;
        *(uint *)(puVar5 + 0x30) = *(uint *)(puVar5 + 0x30) & 0xff00001a | 0x1a;
      }
      else {
        puVar5[0x12] = 0x10;
        iVar15 = 0xe;
        puVar5[0x20] = 0;
        puVar5[0x21] = 0;
        puVar5[0x22] = 0;
        puVar5[0x23] = 0;
        puVar5[0x24] = 0;
        puVar5[0x25] = 0;
        puVar5[0x26] = 0;
        puVar5[0x27] = 0;
        puVar5[0x20] = 0x109e;
        *(undefined1 *)((longlong)puVar5 + 0x4d) = 0xe;
        memcpy((void *)((longlong)piVar9 + 6),*(void **)(lVar4 + 0x40),0xe);
        puVar5[0xe] = 0xe;
        puVar5[0xf] = 0;
        if ((*(uint *)(puVar5 + 0x30) & 0xffffff) < 0xe) {
LAB_140009037:
          uVar11 = (ulonglong)(*(ushort *)(param_1 + 0x24e) & 1) | 2;
          *(uint *)(puVar5 + uVar11 * 2 + 0x30) = *(uint *)(puVar5 + uVar11 * 2 + 0x30) & 0xff000000
          ;
          *(uint *)(puVar5 + uVar11 * 2 + 0x30) =
               *(uint *)(puVar5 + uVar11 * 2 + 0x30) |
               iVar15 - (*(uint *)(puVar5 + 0x30) & 0xffffff);
        }
        else {
          *(uint *)(puVar5 + 0x30) = *(uint *)(puVar5 + 0x30) & 0xff00000e | 0xe;
        }
      }
LAB_1400091eb:
      QueueRequestDescriptor(param_1,(uint)uVar2 << 0x10,(uint)*puVar5 << 0x10,local_res20);
      *param_2 = 0;
      goto LAB_1400092c8;
    }
    if (!bVar18) {
LAB_1400090b5:
      *(undefined1 *)((longlong)puVar1 + 0x13) = 0;
      return (ulonglong)puVar1 & 0xffffffffffffff00;
    }
  }
  else {
    if (local_res18[0] == -0x62) {
      if (bVar18) {
        if ((pcVar7[0xc] & 1U) != 0) {
          *(undefined1 *)(piVar9 + 1) = 1;
          *piVar9 = (uint)(byte)pcVar7[8] * 0x1000000 + (uint)(byte)pcVar7[9] * 0x10000 +
                    (uint)(byte)pcVar7[10] * 0x100 + (uint)(byte)pcVar7[0xb];
        }
        _Size = 0xe;
      }
      else {
        *(char *)((longlong)piVar9 + 5) = *(char *)((longlong)piVar9 + 5) + '\x01';
        if (*(byte *)((longlong)piVar9 + 5) < 4) goto LAB_1400091eb;
        _Size = 0xe;
      }
    }
    else {
      if (local_res18[0] != -0x3e) {
        if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x205) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x205,local_res18,1
                      ,local_res20);
        }
        *param_2 = 1;
        goto LAB_1400092c8;
      }
      if (bVar18) {
LAB_140009244:
        *(undefined1 *)(lVar10 + 0x22) = 0x40;
      }
      else {
        *(char *)((longlong)piVar9 + 5) = *(char *)((longlong)piVar9 + 5) + '\x01';
        if (*(byte *)((longlong)piVar9 + 5) < 2) goto LAB_1400091eb;
        StorPortLogError(param_1,0,0,0,(ulonglong)puVar21 & 0xffffffffffffff00,6,0xad010033);
      }
LAB_140009249:
      _Size = 0x1a;
    }
    memcpy(*(void **)(lVar4 + 0x40),(void *)((longlong)piVar9 + 6),_Size);
  }
LAB_14000925c:
  param_2 = (undefined1 *)StorPortNotification(0,param_1,lVar4);
LAB_1400092c8:
  return CONCAT71((int7)((ulonglong)param_2 >> 8),1);
}



===== CheckIoctlQueue @ 140009300 =====

undefined8 CheckIoctlQueue(longlong param_1,int param_2)

{
  byte bVar1;
  void *pvVar2;
  char cVar3;
  undefined8 uVar4;
  
  uVar4 = 0;
  if ((((*(char *)(param_1 + 0x14f8) == '\0') && (*(int *)(param_1 + 0x568) == 0)) &&
      (*(char *)(param_1 + 0xda6) == '\0')) && (*(int *)(param_1 + 0xdf8) == 0)) {
    if (*(char *)(param_1 + 0x14f9) != '\0') {
      *(undefined1 *)(param_1 + 0x14f9) = 0;
      if (*(int *)(param_1 + 0x570) == 0) {
        StorPortPause(param_1,300);
      }
      ResetActive(param_1,0xf,param_2);
      *(undefined1 *)(param_1 + 0x14f8) = 1;
      *(undefined1 *)(param_1 + 0x14fc) = 1;
      SasBcAsyncEvent(param_1,param_2);
      return 0;
    }
    do {
      bVar1 = *(byte *)(param_1 + 0xebb);
      pvVar2 = *(void **)(param_1 + 0xec0 + (ulonglong)bVar1 * 8);
      if (pvVar2 == (void *)0x0) {
        return uVar4;
      }
      *(undefined8 *)(param_1 + 0xec0 + (ulonglong)bVar1 * 8) = 0;
      cVar3 = '\0';
      if ((byte)(bVar1 + 1) != ' ') {
        cVar3 = bVar1 + 1;
      }
      *(char *)(param_1 + 0xebb) = cVar3;
      LsiHandleAppRequest(param_1,pvVar2,param_2);
      uVar4 = 1;
    } while (*(char *)(param_1 + 0xdfe) == '\0');
  }
  return uVar4;
}



===== CheckMpiIoctlReply @ 140009420 =====

undefined8 CheckMpiIoctlReply(longlong param_1,byte *param_2,int param_3)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  longlong lVar4;
  char cVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  char cVar8;
  int *piVar9;
  char *pcVar10;
  uint uVar11;
  longlong lVar12;
  longlong lVar13;
  bool bVar14;
  
  lVar13 = 0;
  if ((*(byte *)(*(longlong *)(param_1 + 0x2a0) + 0x13 + (ulonglong)*(ushort *)(param_2 + 2) * 0x18)
      & 1) == 0) {
    return 0;
  }
  *(undefined1 *)
   (*(longlong *)(param_1 + 0x2a0) + (ulonglong)*(ushort *)(param_2 + 2) * 0x18 + 0x13) = 0;
  bVar14 = (*param_2 & 0xf) != 1;
  if (bVar14) {
    pcVar10 = (char *)0x0;
  }
  else {
    pcVar10 = (char *)((ulonglong)*(uint *)(param_2 + 4) + *(longlong *)(param_1 + 0x100));
  }
  if (*(char *)(param_1 + 0xdfe) == '\0') goto LAB_1400095e2;
  if (*(char *)(param_1 + 0xdff) != '\0') {
    bVar2 = *(byte *)(param_1 + 0xeb9);
    *(int *)(param_1 + 0xe6c) = *(int *)(param_1 + 0xe6c) + 1;
    *(undefined1 *)((ulonglong)bVar2 + 0xe98 + param_1) =
         *(undefined1 *)(*(longlong *)(param_1 + 0xe58) + 3);
    cVar8 = bVar2 + 1;
    cVar5 = '\0';
    if (cVar8 != ' ') {
      cVar5 = cVar8;
    }
    *(char *)(param_1 + 0xeb9) = cVar5;
  }
  lVar13 = *(longlong *)(param_1 + 0xe08);
  piVar9 = (int *)(param_1 + 0xe18);
  uVar11 = 0;
  lVar12 = lVar13 - (longlong)piVar9;
  lVar4 = *(longlong *)(lVar13 + 0x68);
  do {
    iVar3 = *piVar9;
    piVar1 = (int *)(lVar12 + (longlong)piVar9);
    piVar9 = piVar9 + 1;
    if (iVar3 != *piVar1) goto LAB_1400095db;
    uVar11 = uVar11 + 1;
  } while (uVar11 < 0x10);
  piVar9 = *(int **)(param_1 + 0xe58);
  uVar11 = 0;
  if (*(ushort *)(param_1 + 0x242) != 0) {
    lVar12 = (lVar4 + 0x158) - (longlong)piVar9;
    do {
      iVar3 = *piVar9;
      piVar1 = (int *)(lVar12 + (longlong)piVar9);
      piVar9 = piVar9 + 1;
      if (iVar3 != *piVar1) goto LAB_1400095db;
      uVar11 = uVar11 + 1;
    } while (uVar11 < *(ushort *)(param_1 + 0x242));
  }
  lVar12 = *(longlong *)(lVar13 + 0x40);
  uVar6 = CsmiDispatchStateMachine(param_1,pcVar10,param_3);
  if ((char)uVar6 != '\0') goto LAB_140009681;
  *(undefined4 *)(lVar12 + 0x14) = 0;
  if (bVar14) {
    *(undefined4 *)(lVar12 + 0x1c) = 0;
    goto LAB_1400095e2;
  }
  uVar11 = 0;
  if (pcVar10[2] != '\0') {
    do {
      uVar6 = (ulonglong)uVar11;
      uVar11 = uVar11 + 1;
      *(undefined4 *)(uVar6 * 4 + 0x1c + lVar12) = *(undefined4 *)(pcVar10 + uVar6 * 4);
    } while (uVar11 < (byte)pcVar10[2]);
  }
  if (((pcVar10[3] == '\0') || (pcVar10[3] == '\x16')) && ((pcVar10[0xd] & 1U) != 0)) {
    memcpy(*(void **)(param_1 + 0xe60),(void *)(lVar4 + 0x58),(ulonglong)*(uint *)(pcVar10 + 0x18));
  }
LAB_1400095e7:
  if (pcVar10[3] == '\x01') {
    if ((*(longlong *)(param_1 + 0x528) == 0) && (*(int *)(param_1 + 0xdf8) == 0)) {
      uVar7 = CheckResetQueue(param_1,param_3);
      if ((char)uVar7 != '\0') goto LAB_140009627;
    }
    ResetActive(param_1,0x40000005,param_3);
    StorPortResume(param_1);
  }
LAB_140009627:
  if (*(char *)(param_1 + 0xdfe) == '\0') {
    if (*(longlong *)(param_1 + 0xe08) != 0) {
      *(undefined1 *)(*(longlong *)(param_1 + 0xe08) + 3) = 4;
      StorPortNotification(0,param_1);
      *(undefined8 *)(param_1 + 0xe08) = 0;
    }
    CsmiIdleAllStateMachines(param_1);
  }
  else {
    *(undefined1 *)(lVar13 + 3) = 1;
    StorPortNotification(0,param_1,lVar13);
    *(undefined1 *)(param_1 + 0xdfe) = 0;
    *(undefined8 *)(param_1 + 0xe08) = 0;
  }
LAB_140009681:
  uVar7 = CheckIoctlQueue(param_1,param_3);
  return CONCAT71((int7)((ulonglong)uVar7 >> 8),1);
LAB_1400095db:
  *(undefined1 *)(param_1 + 0xdfe) = 0;
LAB_1400095e2:
  if (!bVar14) goto LAB_1400095e7;
  goto LAB_140009627;
}



===== CheckResetQueue @ 1400096b0 =====

ulonglong CheckResetQueue(longlong param_1,int param_2)

{
  longlong *plVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  ushort *puVar5;
  char cVar6;
  ulonglong in_RAX;
  ulonglong uVar7;
  undefined8 uVar8;
  char cVar9;
  ushort uVar10;
  
  if (*(longlong *)(param_1 + 0x528) != 0) {
    return in_RAX & 0xffffffffffffff00;
  }
  uVar7 = (ulonglong)*(byte *)(param_1 + 0xebd);
  plVar1 = (longlong *)(param_1 + 0xfc0 + uVar7 * 8);
  lVar3 = *plVar1;
  do {
    if (lVar3 == 0) {
      uVar7 = 0;
      if ((*(char *)(param_1 + 0x308) != '\0') &&
         (uVar7 = (ulonglong)*(uint *)(param_1 + 0x30c), (*(uint *)(param_1 + 0x30c) & 0x2001a) != 0
         )) {
        uVar7 = RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x2001a,
                            (undefined1 *)0x0,0,param_2);
      }
      return uVar7 & 0xffffffffffffff00;
    }
    cVar9 = (char)uVar7 + '\x01';
    *plVar1 = 0;
    cVar6 = '\0';
    if (cVar9 != 'd') {
      cVar6 = cVar9;
    }
    *(char *)(param_1 + 0xebd) = cVar6;
    if (lVar3 == -1) {
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x2001d) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x2001d,
                    (undefined1 *)0x0,0,param_2);
      }
    }
    else {
      lVar4 = *(longlong *)(lVar3 + 0x68);
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x20001) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x20001,
                    (undefined1 *)(lVar4 + 0x52),3,param_2);
      }
      uVar10 = (ushort)*(byte *)(lVar4 + 0x52) * 0x80 + (ushort)*(byte *)(lVar4 + 0x53);
      if (((uint)uVar10 < *(uint *)(param_1 + 0x5b8)) &&
         (uVar10 = *(ushort *)(*(longlong *)(param_1 + 0x2c8) + 0x1a + (ulonglong)uVar10 * 0x28),
         uVar10 != 0)) {
        ResetActive(param_1,0x10,param_2);
        *(longlong *)(param_1 + 0x528) = lVar3;
        uVar2 = *(uint *)(lVar3 + 0x14);
        uVar7 = (ulonglong)uVar2;
        if (uVar2 == 0x13) {
          puVar5 = *(ushort **)(param_1 + 0x270);
          puVar5[0] = 0;
          puVar5[1] = 0;
          puVar5[2] = 0;
          puVar5[3] = 0;
          puVar5[4] = 0;
          puVar5[5] = 0;
          puVar5[6] = 0;
          puVar5[7] = 0;
          puVar5[8] = 0;
          puVar5[9] = 0;
          puVar5[10] = 0;
          puVar5[0xb] = 0;
          puVar5[0xc] = 0;
          puVar5[0xd] = 0;
          puVar5[0xe] = 0;
          puVar5[0xf] = 0;
          puVar5[0x10] = 0;
          puVar5[0x11] = 0;
          puVar5[0x12] = 0;
          puVar5[0x13] = 0;
          puVar5[0x14] = 0;
          puVar5[0x15] = 0;
          puVar5[0x16] = 0;
          puVar5[0x17] = 0;
          puVar5[0x18] = 0;
          puVar5[0x19] = 0;
          *puVar5 = uVar10;
          *(undefined1 *)((longlong)puVar5 + 3) = 1;
          *(undefined1 *)((longlong)puVar5 + 5) = 3;
          uVar7 = QueueRequestDescriptor
                            (param_1,(uint)*(ushort *)(param_1 + 0x5ae) * 0x10000 + 6,0,param_2);
          if ((*(char *)(param_1 + 0x308) != '\0') &&
             (uVar7 = (ulonglong)*(uint *)(param_1 + 0x30c),
             (*(uint *)(param_1 + 0x30c) & 0x20006) != 0)) {
            uVar7 = RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x20006,
                                (undefined1 *)(lVar4 + 0x52),3,param_2);
          }
        }
        else if (uVar2 == 0x20) {
          uVar8 = SendLunResetTur(param_1,uVar10,param_2);
          return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
        }
        return CONCAT71((int7)(uVar7 >> 8),1);
      }
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x2001b) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x2001b,
                    (byte *)(lVar4 + 0x52),3,param_2);
      }
      *(undefined1 *)(lVar3 + 3) = 4;
      StorPortNotification(0,param_1,lVar3);
    }
    uVar7 = (ulonglong)*(byte *)(param_1 + 0xebd);
    lVar3 = *(longlong *)(param_1 + 0xfc0 + uVar7 * 8);
    plVar1 = (longlong *)(param_1 + 0xfc0 + uVar7 * 8);
  } while( true );
}



===== CheckSsuReplies @ 1400099b0 =====

longlong CheckSsuReplies(longlong param_1,longlong param_2)

{
  byte bVar1;
  uint7 uVar2;
  
  bVar1 = *(byte *)(*(longlong *)(param_1 + 0x2a0) + 0x13 +
                   (ulonglong)*(ushort *)(param_2 + 2) * 0x18);
  uVar2 = (uint7)((ulonglong)*(longlong *)(param_1 + 0x2a0) >> 8);
  if ((bVar1 & 0x10) == 0) {
    return (ulonglong)uVar2 << 8;
  }
  if (bVar1 == 0x10) {
    *(int *)(param_1 + 0x3d40) = *(int *)(param_1 + 0x3d40) + -1;
  }
  return CONCAT71(uVar2,1);
}



===== CheckSsuTmrReplies @ 1400099e0 =====

longlong CheckSsuTmrReplies(longlong param_1,longlong param_2)

{
  byte bVar1;
  uint7 uVar2;
  
  bVar1 = *(byte *)(*(longlong *)(param_1 + 0x2a0) + 0x13 +
                   (ulonglong)*(ushort *)(param_2 + 2) * 0x18);
  uVar2 = (uint7)((ulonglong)*(longlong *)(param_1 + 0x2a0) >> 8);
  if ((bVar1 & 0x20) == 0) {
    return (ulonglong)uVar2 << 8;
  }
  if (bVar1 == 0x20) {
    *(int *)(param_1 + 0x3d40) = *(int *)(param_1 + 0x3d40) + -1;
  }
  return CONCAT71(uVar2,1);
}



===== CheckTurReplies @ 140009a10 =====

undefined8 CheckTurReplies(longlong param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  longlong lVar2;
  longlong lVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  short sVar7;
  ushort uVar8;
  longlong lVar9;
  longlong lVar10;
  undefined8 uVar11;
  ushort uVar12;
  ulonglong uVar13;
  
  lVar2 = *(longlong *)(param_1 + 0x2a0) + (ulonglong)*(ushort *)(param_2 + 2) * 0x18;
  if ((*(byte *)(*(longlong *)(param_1 + 0x2a0) + 0x13 + (ulonglong)*(ushort *)(param_2 + 2) * 0x18)
      & 0x40) == 0) {
    return 0;
  }
  *(undefined1 *)(lVar2 + 0x13) = 0;
  lVar9 = *(longlong *)(param_1 + 0x528);
  lVar10 = *(longlong *)(lVar9 + 0x68);
  bVar4 = *(byte *)(lVar10 + 0x52);
  pbVar1 = (byte *)(lVar10 + 0x52);
  bVar5 = *(byte *)(lVar10 + 0x53);
  cVar6 = *(char *)(lVar10 + 0x54);
  if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x20009) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x20009,pbVar1,3,param_3)
    ;
  }
  GtfStopTimer(param_1,*(byte *)(param_1 + 0x6a5),param_3);
  lVar3 = (ulonglong)(ushort)((ushort)*pbVar1 * 0x80 + (ushort)*(byte *)(lVar10 + 0x53)) * 0x28;
  sVar7 = *(short *)(lVar3 + 0x1a + *(longlong *)(param_1 + 0x2c8));
  if (((*param_2 & 0xf) == 1) &&
     ((*(byte *)((ulonglong)*(uint *)(param_2 + 4) + *(longlong *)(param_1 + 0x100) + 0xd) & 1) != 0
     )) {
    ConvertSenseDataFormat((char *)(lVar10 + 0x58));
    if (((*(byte *)(lVar10 + 0x5a) & 0xf) == 6) &&
       (((*(char *)(lVar10 + 100) == ')' && (*(char *)(param_1 + 0xdce) != '\0')) &&
        ((*(uint *)(lVar3 + 0x14 + *(longlong *)(param_1 + 0x2c8)) >> 10 & 1) != 0)))) {
      *(undefined1 *)(lVar9 + 3) = 1;
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x2000a) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x2000a,pbVar1,3,
                    param_3);
      }
      *(undefined8 *)(lVar2 + 8) = *(undefined8 *)(param_1 + 0x528);
      uVar11 = HandleUnitAttenReset
                         (param_1,*(ushort *)(param_1 + 0x5ae),*(undefined8 **)(param_1 + 0x270),
                          bVar4,bVar5,cVar6,'\x01',param_3);
      goto LAB_140009d1f;
    }
  }
  uVar8 = *(ushort *)(param_1 + 0x594);
  uVar13 = 1;
  if (uVar8 != 0) {
    do {
      uVar12 = (ushort)uVar13;
      if ((*(longlong *)(*(longlong *)(param_1 + 0x2a0) + 8 + uVar13 * 0x18) != 0) &&
         (sVar7 == *(short *)(*(longlong *)(param_1 + 0x2a0) + 0x14 + uVar13 * 0x18))) break;
      uVar12 = uVar12 + 1;
      uVar13 = (ulonglong)uVar12;
    } while (uVar12 <= uVar8);
    if (uVar12 <= uVar8) {
      uVar11 = IssueLunReset(param_1,param_3);
      goto LAB_140009d1f;
    }
  }
  *(undefined1 *)(lVar9 + 3) = 1;
  StorPortNotification(0,param_1,lVar9);
  if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x2000c) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x2000c,pbVar1,3,param_3)
    ;
  }
  *(undefined8 *)(param_1 + 0x528) = 0;
  uVar11 = CheckResetQueue(param_1,param_3);
  if ((char)uVar11 == '\0') {
    ResetActive(param_1,0x40000006,param_3);
    uVar11 = StorPortResume(param_1);
    if (*(char *)(param_1 + 0xdfe) == '\0') {
      uVar11 = CheckIoctlQueue(param_1,param_3);
    }
  }
LAB_140009d1f:
  return CONCAT71((int7)((ulonglong)uVar11 >> 8),1);
}



===== ClearResetHistoryBit @ 140009d50 =====

void ClearResetHistoryBit(longlong param_1)

{
  EnableDiagnosticRegister(param_1);
  **(uint **)(param_1 + 0x28) = **(uint **)(param_1 + 0x28) & 0xffffffdf;
  LOCK();
  UNLOCK();
  **(undefined4 **)(param_1 + 0x20) = 0;
  LOCK();
  UNLOCK();
  return;
}



===== CompleteAllSrbs @ 140009d90 =====

void CompleteAllSrbs(longlong param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  uint uVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined1 uVar6;
  bool bVar7;
  
  bVar7 = *(char *)(param_1 + 0xdb4) == '\0';
  uVar2 = 0x11;
  if (bVar7) {
    uVar2 = 4;
  }
  uVar3 = 1;
  uVar6 = 0x11;
  if (bVar7) {
    uVar6 = 0xe;
  }
  if (*(short *)(param_1 + 0x594) != 0) {
    plVar5 = (longlong *)(*(longlong *)(param_1 + 0x2a0) + 0x20);
    do {
      if (*plVar5 != 0) {
        *(undefined1 *)(*plVar5 + 3) = uVar6;
        StorPortNotification(0,param_1);
        *plVar5 = 0;
      }
      plVar5 = plVar5 + 3;
      uVar3 = uVar3 + 1;
    } while (uVar3 <= *(ushort *)(param_1 + 0x594));
  }
  plVar5 = (longlong *)(param_1 + 0xec0);
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
  plVar5 = (longlong *)(param_1 + 0xfc0);
  lVar4 = 100;
  do {
    lVar1 = *plVar5;
    if (lVar1 != 0) {
      if (*(longlong *)(param_1 + 0x528) == lVar1) {
        *(undefined8 *)(param_1 + 0x528) = 0;
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
  lVar4 = *(longlong *)(param_1 + 0x528);
  if (lVar4 != 0) {
    if (((*(int *)(lVar4 + 0x14) == 0x20) || (*(int *)(lVar4 + 0x14) == 0x13)) &&
       ((*(int *)(lVar4 + 0x3c) == 0 && (*(longlong *)(lVar4 + 0x40) == 0)))) {
      *(undefined1 *)(lVar4 + 3) = uVar2;
      StorPortNotification(0,param_1);
    }
    *(undefined8 *)(param_1 + 0x528) = 0;
  }
  return;
}



===== DelayedIoctlTimeout @ 140009f00 =====

void DelayedIoctlTimeout(longlong param_1)

{
  *(undefined4 *)(param_1 + 0xdf8) = 1;
  KickStart(param_1,9);
  *(undefined1 *)(param_1 + 0xdf1) = 0;
                    /* WARNING: Could not recover jumptable at 0x000140009f3e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification(6,param_1,WatchdogTimer,1000000);
  return;
}



===== EnableDiagnosticRegister @ 140009f50 =====

void EnableDiagnosticRegister(longlong param_1)

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
  while ((-1 < cVar2 && (StorPortLogError(param_1,0,0,0,0,6,0xad010029), bVar1))) {
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



===== EnableDisableEvents @ 14000a0a0 =====

ulonglong EnableDisableEvents(longlong param_1,char param_2,undefined4 param_3)

{
  undefined8 *puVar1;
  undefined4 *puVar2;
  ulonglong uVar3;
  uint uVar4;
  
  puVar1 = *(undefined8 **)(param_1 + 0x548);
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
  *(undefined1 *)(param_1 + 0xda5) = 1;
  **(int **)(param_1 + 0xe8) = (uint)*(ushort *)(param_1 + 0x5aa) * 0x10000 + 8;
  LOCK();
  UNLOCK();
  puVar2 = *(undefined4 **)(param_1 + 0xf0);
  *puVar2 = 0;
  LOCK();
  UNLOCK();
  if (param_2 != '\0') {
    while( true ) {
      puVar2 = (undefined4 *)PollLSImpiIsr(param_1,param_3);
      if (*(char *)(param_1 + 0xda5) == '\0') break;
      StorPortStallExecution(500);
      uVar4 = uVar4 + 1;
      if (9999 < uVar4) {
        uVar3 = StorPortLogError(param_1,0,0,0,0,6,0xad01003e);
        return uVar3 & 0xffffffffffffff00;
      }
    }
  }
  return CONCAT71((int7)((ulonglong)puVar2 >> 8),1);
}



===== FwDiagPostImmediateBuffers @ 14000a1a0 =====

undefined8 FwDiagPostImmediateBuffers(longlong param_1,int param_2)

{
  longlong lVar1;
  int *piVar2;
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
    lVar1 = uVar4 * 3 + 0x25c;
    piVar2 = (int *)(param_1 + lVar1 * 8);
    if ((*(char *)(param_1 + 0x10 + lVar1 * 8) != '\0') &&
       ((*(char *)((longlong)piVar2 + 0xf) != '\0' || (*(char *)((longlong)piVar2 + 0x12) != '\0')))
       ) {
      *(undefined1 *)(param_1 + 0xdbd) = 1;
      if ((char)piVar2[4] == '\0') {
        uVar5 = 0;
        goto LAB_14000a2d1;
      }
      puVar3 = *(undefined1 **)(param_1 + 0x548);
      *(undefined1 *)((longlong)piVar2 + 0xe) = 0;
      if (*(ushort *)(param_1 + 0x240) != 0) {
        puVar10 = puVar3;
        for (uVar6 = (ulonglong)*(ushort *)(param_1 + 0x240); uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar10 = 0;
          puVar10 = puVar10 + 1;
        }
      }
      puVar3[1] = (char)piVar2[3];
      puVar3[3] = 0x1d;
      *puVar3 = *(undefined1 *)((longlong)piVar2 + 0xd);
      *(int *)(puVar3 + 0x14) = piVar2[2];
      memcpy(puVar3 + 0x24,(void *)(param_1 + 0x1328),0x28);
      *(undefined4 *)(puVar3 + 0x10) = *(undefined4 *)(param_1 + 0x1ec);
      *(int *)(puVar3 + 0xc) = *piVar2 - *(int *)(param_1 + 0x100);
      QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x5aa) * 0x10000 + 8,0,param_2);
      uVar9 = 0;
      do {
        uVar4 = PollLSImpiIsr(param_1,param_2);
        if ((char)uVar4 == '\0') {
          uVar4 = StorPortStallExecution(500);
        }
        else if (*(char *)(param_1 + 0xdbd) == '\0') break;
        uVar9 = uVar9 + 1;
      } while (uVar9 < 4000);
    }
    bVar8 = cVar7 + 1;
    uVar6 = (ulonglong)bVar8;
  } while (bVar8 < 3);
  uVar5 = CONCAT71((int7)(uVar4 >> 8),1);
LAB_14000a2d1:
  *(undefined1 *)(param_1 + 0xdbd) = 0;
  return uVar5;
}



===== GetCimData @ 14000a300 =====

void GetCimData(longlong param_1,longlong param_2,uint param_3)

{
  ushort uVar1;
  
  *(undefined4 *)(param_1 + 0xd40) = 0;
  uVar1 = *(ushort *)(param_2 + 2);
  *(uint *)(param_1 + 0xd44) = (uint)uVar1;
  *(uint *)(param_1 + 0xd48) = (uint)*(byte *)(param_2 + 8);
  *(uint *)(param_1 + 0xd4c) = (uint)*(ushort *)(param_2 + 0x2e);
  *(uint *)(param_1 + 0xd50) = (uint)*(ushort *)(param_2 + 0x2c);
  *(uint *)(param_1 + 0xd3c) = (uVar1 == 0x7e) + 4;
  memcpy((void *)(param_1 + 0xd60),&driver_version,0x15);
  *(uint *)(param_1 + 0xd88) = param_3 >> 0x10 & 0xff;
  *(uint *)(param_1 + 0xd84) = param_3 & 0xffff;
  if (*(int *)(param_1 + 0xd50) == 0x1014) {
    *(undefined1 *)(param_1 + 0xda8) = 1;
  }
  return;
}



===== HandleEventNotification @ 14000a3b0 =====

void HandleEventNotification(longlong param_1,ushort *param_2,int param_3)

{
  byte bVar1;
  ushort uVar2;
  char cVar3;
  uint *puVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined8 *puVar7;
  byte bVar8;
  uint uVar9;
  uint uVar10;
  ulonglong uVar11;
  ushort uVar12;
  undefined1 uVar13;
  uint *puVar14;
  char cVar15;
  undefined1 uVar16;
  undefined1 local_res10;
  ushort *in_stack_ffffffffffffffa8;
  uint7 uVar17;
  undefined6 uVar18;
  undefined4 uVar19;
  
  uVar2 = param_2[10];
  uVar10 = (uint)uVar2;
  if (((byte)(uVar2 >> 5) < 4) &&
     ((*(uint *)(param_1 + 0xd90 + (ulonglong)(uVar2 >> 5 & 0xff) * 4) >> (uVar10 & 0x1f) & 1) != 0)
     ) {
    bVar1 = *(byte *)(param_1 + 0xda4);
    puVar14 = (uint *)(param_1 + 0x1630 + (ulonglong)bVar1 * 200);
    lVar6 = 3;
    *puVar14 = uVar10;
    *(int *)(param_1 + 0xda0) = *(int *)(param_1 + 0xda0) + 1;
    puVar14[1] = *(uint *)(param_1 + 0xda0);
    puVar4 = puVar14 + 2;
    do {
      puVar4[0] = 0;
      puVar4[1] = 0;
      puVar4[2] = 0;
      puVar4[3] = 0;
      puVar4[4] = 0;
      puVar4[5] = 0;
      puVar4[6] = 0;
      puVar4[7] = 0;
      puVar4[8] = 0;
      puVar4[9] = 0;
      puVar4[10] = 0;
      puVar4[0xb] = 0;
      puVar4[0xc] = 0;
      puVar4[0xd] = 0;
      puVar4[0xe] = 0;
      puVar4[0xf] = 0;
      lVar6 = lVar6 + -1;
      puVar4 = puVar4 + 0x10;
    } while (lVar6 != 0);
    uVar12 = *param_2;
    if (uVar12 != 0) {
      if (0x30 < uVar12) {
        uVar12 = 0x30;
      }
      uVar11 = 0;
      if (uVar12 != 0) {
        do {
          bVar8 = (char)uVar11 + 1;
          puVar14[uVar11 + 2] = *(uint *)(param_2 + uVar11 * 2 + 0xe);
          uVar11 = (ulonglong)bVar8;
        } while (bVar8 < uVar12);
      }
    }
    cVar15 = bVar1 + 1;
    cVar3 = '\0';
    if (cVar15 != '2') {
      cVar3 = cVar15;
    }
    *(char *)(param_1 + 0xda4) = cVar3;
LAB_14000a4d2:
    if (*(char *)(param_1 + 0x14b1) != '\0') {
      in_stack_ffffffffffffffa8 = (ushort *)&MegaSASWmiMpiEventGuid;
      ScsiPortWmiFireLogicalUnitEvent
                (param_1,-1,0,0,(int *)&MegaSASWmiMpiEventGuid,0,0x10,(int *)(param_1 + 0x198));
    }
  }
  else if (uVar2 == 0x21) goto LAB_14000a4d2;
  uVar17 = (uint7)((ulonglong)in_stack_ffffffffffffffa8 >> 8);
  switch(uVar10) {
  case 1:
    if (*param_2 == 0) break;
    uVar10 = *(uint *)(param_2 + 0xe);
    uVar19 = 3;
    goto LAB_14000a892;
  case 5:
    *(undefined1 *)(param_1 + 0xd80) = 1;
    if (*(short *)(param_1 + 0x560) == 0) break;
    uVar10 = 0xad01000e;
    goto LAB_14000a88a;
  case 10:
    *(undefined1 *)(param_1 + 0xda5) = 0;
    break;
  case 0xf:
    uVar10 = *(uint *)(param_1 + 0x5b8);
    uVar11 = 0;
    uVar9 = 0;
    uVar12 = param_2[0x11];
    if (uVar10 != 0) {
      do {
        uVar9 = (uint)uVar11;
        lVar6 = *(longlong *)(param_1 + 0x2c8) + uVar11 * 0x28;
        if (*(ushort *)(*(longlong *)(param_1 + 0x2c8) + 0x1a + uVar11 * 0x28) == uVar12) {
          local_res10 = (undefined1)*(undefined2 *)(lVar6 + 0x1c);
          uVar13 = 0;
          uVar16 = (undefined1)*(undefined2 *)(lVar6 + 0x1e);
          goto LAB_14000a6e7;
        }
        uVar9 = uVar9 + 1;
        uVar11 = (ulonglong)uVar9;
      } while (uVar9 < uVar10);
    }
    uVar16 = local_res10;
    uVar13 = local_res10;
LAB_14000a6e7:
    if (uVar9 < uVar10) {
      uVar18 = (undefined6)((ulonglong)in_stack_ffffffffffffffa8 >> 0x10);
      if ((char)param_2[0xf] == '\b') {
        if (*(int *)(param_1 + 0x570) == 0) {
          in_stack_ffffffffffffffa8 = (ushort *)CONCAT62(uVar18,uVar12);
          PauseDevice(param_1,local_res10,uVar16,uVar13,uVar12,300,1,1,param_3);
        }
      }
      else if ((char)param_2[0xf] == '\x0e') {
        in_stack_ffffffffffffffa8 = (ushort *)CONCAT62(uVar18,uVar12);
        ResumeDevice(param_1,local_res10,uVar16,uVar13,uVar12,1,1,param_3);
      }
    }
    else {
      in_stack_ffffffffffffffa8 = (ushort *)((ulonglong)uVar17 << 8);
      StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffffa8,6,0xad010075);
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x23d) != 0)) {
        in_stack_ffffffffffffffa8 = (ushort *)0x0;
        RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x23d,
                    (undefined1 *)0x0,0,param_3);
      }
    }
    break;
  case 0x17:
    if (((*(char *)((longlong)param_2 + 0x1f) == '\x04') && (*(int *)(param_1 + 0xdf8) == 0)) &&
       ((*(longlong **)(param_1 + 0x510) != *(longlong **)(param_1 + 0x518) ||
        (*(longlong *)(**(longlong **)(param_1 + 0x510) + 8) != 0)))) {
      if ((*(char *)(param_1 + 0x14f8) == '\0') && (*(char *)(param_1 + 0xdfe) == '\0')) {
        if (*(int *)(param_1 + 0x570) == 0) {
          StorPortPause(param_1,300);
        }
        ResetActive(param_1,0xe,param_3);
        *(undefined1 *)(param_1 + 0x14f8) = 1;
        *(undefined1 *)(param_1 + 0x14fc) = 1;
        SasBcAsyncEvent(param_1,param_3);
      }
      else {
        *(undefined1 *)(param_1 + 0x14f9) = 1;
      }
    }
    break;
  case 0x1c:
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x100001) != 0)) {
      in_stack_ffffffffffffffa8 = param_2;
      RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x100001,
                  (undefined1 *)param_2,(uint)(byte)param_2[1] << 2,param_3);
    }
    ProcessSasTopologyChangeList(param_1,param_2,param_3);
    break;
  case 0x1d:
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x100000) != 0)) {
      in_stack_ffffffffffffffa8 = param_2;
      RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x100000,
                  (undefined1 *)param_2,(uint)(byte)param_2[1] << 2,param_3);
    }
    ProcessSasEnclosureStatusChange(param_1,(longlong)param_2);
    break;
  case 0x20:
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x100002) != 0)) {
      in_stack_ffffffffffffffa8 = param_2;
      RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x100002,
                  (undefined1 *)param_2,(uint)(byte)param_2[1] << 2,param_3);
    }
    ProcessIRConfigChangeList(param_1,param_2,param_3);
    break;
  case 0x27:
    uVar10 = (param_2[0x10] | 0xf0000) << 8 | (uint)(byte)param_2[0xe];
LAB_14000a88a:
    uVar19 = 6;
LAB_14000a892:
    in_stack_ffffffffffffffa8 = (ushort *)((ulonglong)uVar17 << 8);
    StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffffa8,uVar19,uVar10);
  }
  if ((char)param_2[3] != '\0') {
    if (*(char *)(param_1 + 0xdb9) == '\0') {
      bVar1 = *(byte *)(param_1 + 0xcea);
      lVar6 = param_1 + (ulonglong)bVar1 * 8;
      if (*(short *)(lVar6 + 0xcec) == 0) {
        *(ushort *)(lVar6 + 0xcec) = uVar2;
        cVar15 = bVar1 + 1;
        *(undefined4 *)(lVar6 + 0xcf0) = *(undefined4 *)(param_2 + 0xc);
        cVar3 = '\0';
        if (cVar15 != '\n') {
          cVar3 = cVar15;
        }
        *(uint *)(param_1 + 0x5bc) = *(uint *)(param_1 + 0x5bc) | 2;
        *(char *)(param_1 + 0xcea) = cVar3;
        if (*(char *)(param_1 + 0xdf1) == '\0') {
          StorPortNotification(6,param_1,WatchdogTimer,10000);
          return;
        }
        return;
      }
      uVar19 = 0xad01003c;
    }
    else {
      lVar6 = **(longlong **)(param_1 + 0x510);
      if (*(longlong *)(lVar6 + 8) == 0) {
        plVar5 = *(longlong **)(param_1 + 0x510) + 1;
        *(longlong **)(param_1 + 0x510) = plVar5;
        if (plVar5 == *(longlong **)(param_1 + 0x520)) {
          *(undefined8 *)(param_1 + 0x510) = *(undefined8 *)(param_1 + 0x508);
        }
        uVar12 = *(ushort *)(lVar6 + 0x10);
        *(undefined8 *)(lVar6 + 8) = 0xea;
        puVar7 = (undefined8 *)
                 ((longlong)(int)((uint)*(ushort *)(param_1 + 0x240) * (uint)uVar12) +
                 *(longlong *)(param_1 + 0x260));
        *puVar7 = 0;
        puVar7[1] = 0;
        *(undefined4 *)(puVar7 + 2) = 0;
        *(undefined1 *)((longlong)puVar7 + 3) = 8;
        *(ushort *)((longlong)puVar7 + 0xc) = uVar2;
        *(undefined4 *)(puVar7 + 2) = *(undefined4 *)(param_2 + 0xc);
        **(int **)(param_1 + 0xe8) = (uint)uVar12 * 0x10000 + 8;
        LOCK();
        UNLOCK();
        **(undefined4 **)(param_1 + 0xf0) = 0;
        LOCK();
        UNLOCK();
        return;
      }
      uVar19 = 0xad01003b;
    }
    StorPortLogError(param_1,0,0,0,(ulonglong)in_stack_ffffffffffffffa8 & 0xffffffffffffff00,6,
                     uVar19);
    *(undefined4 *)(param_1 + 0xdf8) = 1;
    if (*(int *)(param_1 + 0x570) == 0) {
      StorPortPause(param_1,300);
    }
    *(undefined2 *)(param_1 + 0xdf4) = 0;
    KickStart(param_1,param_3);
  }
  return;
}



===== HandleIoctlTimeout @ 14000aa80 =====

undefined8 HandleIoctlTimeout(longlong param_1,int *param_2)

{
  int iVar1;
  undefined2 *puVar2;
  undefined8 *puVar3;
  code *pcVar4;
  undefined8 uVar5;
  
  puVar2 = *(undefined2 **)(param_1 + 0xe58);
  iVar1 = *param_2;
  *(undefined1 *)(param_1 + 0xdb9) = 1;
  if (((*(char *)((longlong)puVar2 + 3) == '\0') && (*(int *)(param_1 + 0x568) == 0)) &&
     (*(char *)(param_1 + 0xdf1) == '\0')) {
    puVar3 = *(undefined8 **)(param_1 + 0x270);
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
    **(int **)(param_1 + 0xe8) = (uint)*(ushort *)(param_1 + 0x5ae) * 0x10000 + 6;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0xf0) = 0;
    LOCK();
    UNLOCK();
    *(undefined4 *)(param_1 + 0x574) = 0xf;
    pcVar4 = WatchdogTimer;
    *(undefined1 *)(param_1 + 0xdf1) = 0;
    uVar5 = 1000000;
  }
  else {
    puVar3 = *(undefined8 **)(param_1 + 0x548);
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    *(undefined4 *)(puVar3 + 5) = 0;
    *(undefined1 *)((longlong)puVar3 + 3) = 7;
    *(undefined8 *)((longlong)puVar3 + 0x14) = 0xffffffffffffffff;
    *(undefined8 *)((longlong)puVar3 + 0x1c) = 0xffffffffffffffff;
    *(undefined1 *)(param_1 + 0xda5) = 1;
    **(int **)(param_1 + 0xe8) = (uint)*(ushort *)(param_1 + 0x5aa) * 0x10000 + 8;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0xf0) = 0;
    LOCK();
    UNLOCK();
    ResetActive(param_1,2,iVar1);
    uVar5 = 3000000;
    *(undefined1 *)(param_1 + 0xdf1) = 1;
    pcVar4 = DelayedIoctlTimeout;
  }
  uVar5 = StorPortNotification(6,param_1,pcVar4,uVar5);
  *(undefined1 *)(param_1 + 0xdb9) = 0;
  return CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
}



===== HandleRttIoctl @ 14000abf0 =====

longlong HandleRttIoctl(longlong param_1,longlong param_2,undefined1 *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  void *pvVar4;
  uint7 uVar7;
  ulonglong uVar5;
  void *pvVar6;
  int iVar8;
  int *_Src;
  
  *param_3 = 1;
  *(undefined4 *)(param_2 + 0x14) = 0;
  pvVar4 = memcpy((void *)(param_2 + 0x1c),&RttraceRecordVersion,4);
  iVar8 = *(int *)(param_2 + 0x20);
  uVar7 = (uint7)((ulonglong)pvVar4 >> 8);
  if (iVar8 == 1) {
    if (*(uint *)(param_2 + 0x18) < 0x24) goto LAB_14000ad82;
    *(undefined1 *)(param_2 + 0x3c) = *(undefined1 *)(param_1 + 0x308);
    *(undefined4 *)(param_2 + 0x38) = *(undefined4 *)(param_1 + 0x30c);
    *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)(param_1 + 0x304);
    uVar1 = *(uint *)(param_1 + 0x300);
    *(uint *)(param_2 + 0x30) = uVar1;
    *(undefined4 *)(param_2 + 0x2c) = 0xf;
  }
  else {
    if (iVar8 != 2) {
      if (iVar8 != 3) {
        *(undefined4 *)(param_2 + 0x14) = 1;
        return (ulonglong)uVar7 << 8;
      }
      uVar5 = (ulonglong)*(uint *)(param_2 + 0x2c) + 0x14;
      if (*(uint *)(param_2 + 0x18) < uVar5) {
        *(undefined4 *)(param_2 + 0x14) = 3;
        *(undefined4 *)(param_2 + 0x28) = 2;
        return uVar5 & 0xffffffffffffff00;
      }
      if ((*(uint *)(param_2 + 0x24) & 1) != 0) {
        *(undefined8 *)(param_1 + 0x2f8) = *(undefined8 *)(param_1 + 0x2e8);
      }
      _Src = *(int **)(param_1 + 0x2f8);
      pvVar4 = (void *)(param_2 + 0x30);
      iVar8 = 0;
      if ((uint)_Src[1] < *(uint *)(param_2 + 0x2c)) {
        do {
          if (*_Src == 0) break;
          if (*_Src == 1) {
            _Src = *(int **)(param_1 + 0x2d8);
          }
          else {
            iVar8 = iVar8 + _Src[1];
            memcpy(pvVar4,_Src,(ulonglong)(uint)_Src[1]);
            pvVar4 = (void *)((longlong)pvVar4 + (ulonglong)(uint)_Src[1]);
            _Src = (int *)((longlong)_Src + (ulonglong)(uint)_Src[1]);
          }
        } while ((uint)_Src[1] < (uint)(*(int *)(param_2 + 0x2c) - iVar8));
      }
      uVar1 = _Src[1];
      uVar3 = *(int *)(param_2 + 0x2c) - iVar8;
      pvVar6 = (void *)(ulonglong)uVar3;
      if ((uVar1 < uVar3) && (*_Src == 0)) {
        iVar8 = iVar8 + uVar1;
        pvVar6 = memcpy(pvVar4,_Src,(ulonglong)uVar1);
        *(undefined4 *)(param_2 + 0x24) = 2;
        *(undefined8 *)(param_1 + 0x2f8) = 0;
      }
      else {
        *(int **)(param_1 + 0x2f8) = _Src;
        *(undefined4 *)(param_2 + 0x24) = 0;
      }
      *(int *)(param_2 + 0x2c) = iVar8;
      *(undefined4 *)(param_2 + 0x28) = 0;
      return CONCAT71((int7)((ulonglong)pvVar6 >> 8),1);
    }
    if (*(uint *)(param_2 + 0x18) < 0x24) {
LAB_14000ad82:
      *(undefined4 *)(param_2 + 0x14) = 2;
      *(undefined4 *)(param_2 + 0x28) = 2;
      return (ulonglong)uVar7 << 8;
    }
    if ((*(uint *)(param_2 + 0x2c) & 1) != 0) {
      *(undefined1 *)(param_1 + 0x308) = *(undefined1 *)(param_2 + 0x3c);
    }
    uVar1 = *(uint *)(param_2 + 0x2c);
    if ((uVar1 & 2) != 0) {
      uVar2 = *(undefined4 *)(param_2 + 0x38);
      *(undefined4 *)(param_1 + 0x30c) = uVar2;
      *(undefined4 *)(param_2 + 0x28) = 0;
      return CONCAT71((uint7)(uint3)((uint)uVar2 >> 8),1);
    }
  }
  *(undefined4 *)(param_2 + 0x28) = 0;
  return CONCAT71((uint7)(uint3)(uVar1 >> 8),1);
}



===== HandleUnitAttenReset @ 14000ade0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
HandleUnitAttenReset
          (longlong param_1,ushort param_2,undefined8 *param_3,byte param_4,byte param_5,
          char param_6,char param_7,int param_8)

{
  int *piVar1;
  longlong lVar2;
  undefined2 uVar3;
  longlong lVar4;
  char cVar5;
  byte bVar6;
  longlong lVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  ushort uVar10;
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
  lVar7 = StorPortGetLogicalUnit(param_1,param_4,param_5,param_6);
  if (lVar7 == 0) {
    StorPortLogError(param_1,0,0,0);
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x232) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x232,&local_64,6,
                  param_8);
    }
    uVar9 = 0;
  }
  else {
    piVar1 = (int *)(lVar7 + 0x20);
    if ((param_7 == '\0') || (*piVar1 == 0)) {
LAB_14000af13:
      uVar9 = 1;
      switch(*piVar1) {
      case 0:
        if (param_7 == '\0') {
          return 1;
        }
        lVar2 = *(longlong *)(param_1 + 0x528);
        if ((((lVar2 != 0) &&
             (*(longlong *)(*(longlong *)(param_1 + 0x2a0) + 8 + (ulonglong)param_2 * 0x18) != lVar2
             )) && (lVar2 = *(longlong *)(lVar2 + 0x68), *(byte *)(lVar2 + 0x52) == param_4)) &&
           ((*(byte *)(lVar2 + 0x53) == param_5 && (*(char *)(lVar2 + 0x54) == param_6)))) {
          if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x2001f) != 0))
          {
            RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x2001f,&local_64
                        ,6,param_8);
          }
          return 0;
        }
        *(byte *)(lVar7 + 0x28) = param_4;
        *(byte *)(lVar7 + 0x29) = param_5;
        *(char *)(lVar7 + 0x2a) = param_6;
        *(ushort *)(lVar7 + 0x2c) = param_2;
        *piVar1 = 1;
        goto LAB_14000af13;
      case 1:
        uVar3 = *(undefined2 *)
                 (*(longlong *)(param_1 + 0x2c8) + 0x1a +
                 ((ulonglong)param_4 * 0x80 + (ulonglong)param_5) * 0x28);
        *(undefined2 *)(lVar7 + 0x26) = uVar3;
        PauseDevice(param_1,param_4,param_5,param_6,uVar3,300,2,2,param_8);
        ResetActive(param_1,*(uint *)(param_1 + 0x568) | 0x80000000,param_8);
        *piVar1 = 2;
        goto LAB_14000af13;
      case 2:
        *param_3 = 0;
        param_3[1] = 0;
        param_3[2] = 0;
        param_3[3] = 0;
        param_3[4] = 0;
        param_3[5] = 0;
        *(undefined4 *)(param_3 + 6) = 0;
        *(undefined2 *)param_3 = *(undefined2 *)(lVar7 + 0x26);
        *(undefined1 *)((longlong)param_3 + 3) = 1;
        *(undefined1 *)((longlong)param_3 + 5) = 2;
        *(char *)((longlong)param_3 + 0xd) = param_6;
        *(undefined1 *)(*(longlong *)(param_1 + 0x2a0) + 0x13 + (ulonglong)param_2 * 0x18) = 0x80;
        *(int *)(param_1 + 0xe74) = *(int *)(param_1 + 0xe74) + 1;
        QueueRequestDescriptor(param_1,(uint)param_2 * 0x10000 + 6,0,param_8);
        if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x20016) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x20016,&local_64,6
                      ,param_8);
        }
        bVar6 = GtfStartTimer(param_1,1,8,UarStuckAtsTimerCallback,piVar1,param_8);
        *(byte *)(lVar7 + 0x38) = bVar6;
        if (bVar6 == 0xfe) {
          if (*(short *)(param_1 + 0x560) != 0) {
            StorPortLogError(param_1,0,0,0);
          }
          if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x233) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x233,
                        (undefined1 *)0x0,0,param_8);
          }
        }
        *piVar1 = 4;
        break;
      case 3:
        if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x243) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x243,
                      (undefined1 *)0x0,0,param_8);
        }
        lVar7 = *(longlong *)(param_1 + 0x2a0) + (ulonglong)param_2 * 0x18;
        StorPortNotification
                  (0,param_1,
                   *(undefined8 *)(*(longlong *)(param_1 + 0x2a0) + 8 + (ulonglong)param_2 * 0x18));
        **(longlong **)(param_1 + 0x518) = lVar7;
        *(longlong *)(param_1 + 0x518) = *(longlong *)(param_1 + 0x518) + 8;
        if (*(longlong *)(param_1 + 0x518) == *(longlong *)(param_1 + 0x520)) {
          *(undefined8 *)(param_1 + 0x518) = *(undefined8 *)(param_1 + 0x508);
        }
        *(undefined1 *)(lVar7 + 0x13) = 0;
        *(undefined8 *)(lVar7 + 8) = 0;
        *piVar1 = 0;
        return 1;
      case 4:
        if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x20017) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x20017,&local_64,6
                      ,param_8);
        }
        cVar5 = GtfStopTimer(param_1,*(byte *)(lVar7 + 0x38),param_8);
        if (((cVar5 == '\0') && (*(char *)(param_1 + 0x308) != '\0')) &&
           ((*(uint *)(param_1 + 0x30c) & 0x242) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x242,
                      (undefined1 *)0x0,0,param_8);
        }
        *(undefined1 *)(*(longlong *)(param_1 + 0x2a0) + 0x13 + (ulonglong)param_2 * 0x18) = 0;
        if (*(short *)((longlong)param_3 + 0xe) != 0) {
          if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x235) != 0)) {
            RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x235,&local_64,6
                        ,param_8);
          }
          StorPortLogError(param_1,0,0,0);
        }
        if ((*(char *)(param_1 + 0x12a) != '\0') && (uVar10 = 1, 1 < *(byte *)(param_1 + 299))) {
          do {
            LSImpiMSIIsr(param_1,(byte)uVar10);
            uVar10 = uVar10 + 1;
          } while (uVar10 < *(byte *)(param_1 + 299));
        }
        *piVar1 = 5;
        goto LAB_14000af13;
      case 5:
        uVar10 = 1;
        if (*(ushort *)(param_1 + 0x594) != 0) {
          lVar2 = *(longlong *)(param_1 + 0x2a0);
          do {
            uVar8 = (ulonglong)uVar10;
            if ((((*(longlong *)(lVar2 + 8 + uVar8 * 0x18) != 0) &&
                 (*(short *)(lVar7 + 0x26) == *(short *)(lVar2 + 0x14 + uVar8 * 0x18))) &&
                (param_6 == *(char *)(lVar2 + 0x16 + uVar8 * 0x18))) && (uVar10 != param_2)) {
              *piVar1 = 7;
              if ((*(char *)(param_1 + 0x308) == '\0') ||
                 ((*(uint *)(param_1 + 0x30c) & 0x236) == 0)) goto LAB_14000af13;
              RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x236,&local_64
                          ,6,param_8);
              break;
            }
            uVar10 = uVar10 + 1;
          } while (uVar10 <= *(ushort *)(param_1 + 0x594));
        }
        if (*piVar1 != 7) {
          *piVar1 = 6;
        }
        goto LAB_14000af13;
      case 6:
        ResumeDevice(param_1,param_4,param_5,param_6,*(undefined2 *)(lVar7 + 0x26),2,2,param_8);
        lVar2 = *(longlong *)(param_1 + 0x2a0) + (ulonglong)param_2 * 0x18;
        StorPortNotification
                  (0,param_1,
                   *(undefined8 *)(*(longlong *)(param_1 + 0x2a0) + 8 + (ulonglong)param_2 * 0x18));
        if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x20018) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x20018,&local_64,6
                      ,param_8);
        }
        *(undefined2 *)(lVar7 + 0x26) = 0;
        *(int *)(param_1 + 0xe74) = *(int *)(param_1 + 0xe74) + -1;
        lVar7 = *(longlong *)(param_1 + 0x528);
        if ((lVar7 == 0) || (lVar7 == *(longlong *)(lVar2 + 8))) {
          lVar4 = *(longlong *)(lVar2 + 8);
          *(undefined8 *)(param_1 + 0x528) = 0;
          uVar9 = CheckResetQueue(param_1,param_8);
          if (((char)uVar9 == '\0') && (ResetActive(param_1,0x40000008,param_8), lVar7 == lVar4)) {
            StorPortResume(param_1);
          }
        }
        else {
          ResetActive(param_1,*(uint *)(param_1 + 0x568) & 0x7fffffff,param_8);
        }
        *(undefined8 *)(lVar2 + 8) = 0;
        if (*(char *)(param_1 + 0xdfe) == '\0') {
          CheckIoctlQueue(param_1,param_8);
        }
        *piVar1 = 0;
        return 0;
      case 7:
        StorPortLogError(param_1,0,0,0);
        if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x20019) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x20019,&local_64,6
                      ,param_8);
        }
        *(undefined4 *)(param_1 + 0xdf8) = 1;
        KickStart(param_1,param_8);
      default:
        *piVar1 = 0;
      }
    }
    else {
      uVar9 = 0;
    }
  }
  return uVar9;
}



===== InitReplyFreeQueue @ 14000b6e0 =====

void InitReplyFreeQueue(longlong param_1)

{
  ushort uVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  ulonglong uVar5;
  
  uVar1 = *(ushort *)(param_1 + 0x248);
  uVar2 = *(ushort *)(param_1 + 0x23e);
  iVar4 = *(int *)(param_1 + 0x210);
  piVar3 = *(int **)(param_1 + 0x250);
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
  *(ushort *)(param_1 + 0x218) = uVar1;
  return;
}



===== IssueIOCFacts @ 14000b740 =====

ulonglong IssueIOCFacts(longlong param_1)

{
  int iVar1;
  ushort uVar2;
  bool bVar3;
  short sVar4;
  ulonglong uVar5;
  
  iVar1 = *(int *)(param_1 + 0x570);
  *(undefined8 *)(param_1 + 0x5c0) = 0;
  *(undefined4 *)(param_1 + 0x5c8) = 0;
  *(undefined8 *)(param_1 + 0x660) = 0;
  *(undefined8 *)(param_1 + 0x668) = 0;
  *(undefined8 *)(param_1 + 0x670) = 0;
  *(undefined8 *)(param_1 + 0x678) = 0;
  *(undefined8 *)(param_1 + 0x680) = 0;
  *(undefined8 *)(param_1 + 0x688) = 0;
  *(undefined8 *)(param_1 + 0x690) = 0;
  *(undefined8 *)(param_1 + 0x698) = 0;
  *(undefined1 *)(param_1 + 0x5c3) = 3;
  bVar3 = SendMessageViaHandShake(param_1,0,3);
  if (bVar3) {
    uVar5 = ReceiveDataViaHandshake(param_1,0x20);
    if ((char)uVar5 != '\0') {
      *(undefined2 *)(param_1 + 0x5a8) = *(undefined2 *)(param_1 + 0x660);
      *(short *)(param_1 + 0x240) = *(short *)(param_1 + 0x684) << 2;
      *(undefined2 *)(param_1 + 0x242) = *(undefined2 *)(param_1 + 0x684);
      *(undefined2 *)(param_1 + 0x24a) = *(undefined2 *)(param_1 + 0x694);
      *(ushort *)(param_1 + 0x24c) = (ushort)*(byte *)(param_1 + 0x674);
      *(short *)(param_1 + 0x594) = *(short *)(param_1 + 0x678) + -7;
      *(ushort *)(param_1 + 0x598) =
           *(short *)(param_1 + 0x68a) + (ushort)*(byte *)(param_1 + 0x697);
      *(short *)(param_1 + 0x59a) = (*(short *)(param_1 + 0x68e) + 1) * 2;
      uVar2 = *(short *)(param_1 + 0x68c) * 3;
      *(ushort *)(param_1 + 0x59c) = uVar2;
      if (uVar2 < 0x28) {
        *(undefined2 *)(param_1 + 0x59c) = 0x28;
      }
      *(undefined1 *)(param_1 + 0x59f) = *(undefined1 *)(param_1 + 0x697);
      sVar4 = *(short *)(param_1 + 0x69a);
      if (sVar4 == 0) {
        sVar4 = 0x40;
      }
      *(short *)(param_1 + 0x14bc) = sVar4 + -1;
      *(undefined2 *)(param_1 + 0x5a2) = *(undefined2 *)(param_1 + 0x692);
      *(undefined2 *)(param_1 + 0x5a4) = *(undefined2 *)(param_1 + 0x698);
      *(ushort *)(param_1 + 0x596) = (ushort)*(byte *)(param_1 + 0x676);
      *(ushort *)(param_1 + 0x23e) = (ushort)*(byte *)(param_1 + 0x696) << 2;
      if (0x400 < *(ushort *)(param_1 + 0x598)) {
        *(undefined2 *)(param_1 + 0x598) = 0x400;
      }
      *(undefined4 *)(param_1 + 0xdec) = *(undefined4 *)(param_1 + 0x67c);
      if ((*(uint *)(param_1 + 0x67c) & 4) != 0) {
        *(undefined1 *)(param_1 + 0xdea) = 1;
      }
      *(undefined1 *)(param_1 + 0x59e) = 0;
      *(undefined4 *)(param_1 + 0xd58) = *(undefined4 *)(param_1 + 0x680);
      if (((*(uint *)(param_1 + 0x67c) >> 0xf & 1) != 0) && (1 < *(byte *)(param_1 + 0x677))) {
        *(byte *)(param_1 + 299) = *(byte *)(param_1 + 0x677);
        *(undefined1 *)(param_1 + 0x12a) = 1;
      }
      if (iVar1 == 0) {
        if ((*(uint *)(param_1 + 0x67c) & 8) != 0) {
          *(undefined1 *)(param_1 + 0x12f0) = 1;
        }
        if ((*(uint *)(param_1 + 0x67c) & 0x10) != 0) {
          *(undefined1 *)(param_1 + 0x1308) = 1;
        }
        if ((*(uint *)(param_1 + 0x67c) & 0x20) != 0) {
          *(undefined1 *)(param_1 + 0x1320) = 1;
        }
      }
      *(undefined4 *)(param_1 + 0x558) = 600000;
      if ((*(byte *)(param_1 + 0x690) & 2) != 0) {
        return 1;
      }
    }
  }
  uVar5 = StorPortLogError(param_1,0,0,0,0,6,0xad01000d);
  return uVar5 & 0xffffffffffffff00;
}



===== IssueLunReset @ 14000b9f0 =====

void IssueLunReset(longlong param_1,int param_2)

{
  undefined2 uVar1;
  undefined8 *puVar2;
  longlong lVar3;
  
  puVar2 = *(undefined8 **)(param_1 + 0x270);
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x528) + 0x68);
  uVar1 = *(undefined2 *)
           (*(longlong *)(param_1 + 0x2c8) + 0x1a +
           ((ulonglong)*(byte *)(lVar3 + 0x52) * 0x80 + (ulonglong)*(byte *)(lVar3 + 0x53)) * 0x28);
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
  *(undefined1 *)((longlong)puVar2 + 0xd) = *(undefined1 *)(lVar3 + 0x54);
  QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x5ae) * 0x10000 + 6,0,param_2);
  if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x20007) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x20007,
                (undefined1 *)(lVar3 + 0x52),3,param_2);
  }
  return;
}



===== IssuePortFacts @ 14000bae0 =====

undefined8 IssuePortFacts(longlong param_1,undefined1 param_2)

{
  bool bVar1;
  ulonglong uVar2;
  
  *(undefined8 *)(param_1 + 0x5c0) = 0;
  *(undefined4 *)(param_1 + 0x5c8) = 0;
  *(undefined8 *)(param_1 + 0x660) = 0;
  *(undefined8 *)(param_1 + 0x668) = 0;
  *(undefined8 *)(param_1 + 0x670) = 0;
  *(undefined4 *)(param_1 + 0x678) = 0;
  *(undefined1 *)(param_1 + 0x5c6) = param_2;
  *(undefined1 *)(param_1 + 0x5c3) = 5;
  bVar1 = SendMessageViaHandShake(param_1,0,3);
  if (bVar1) {
    uVar2 = ReceiveDataViaHandshake(param_1,0xe);
    if ((char)uVar2 != '\0') {
      return CONCAT71((int7)(uVar2 >> 8),1);
    }
  }
  uVar2 = StorPortLogError(param_1,0,0,0,0,6,0xad01000f);
  return uVar2 & 0xffffffffffffff00;
}



===== IssueReset @ 14000bb90 =====

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



===== KickStart @ 14000bbf0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong KickStart(longlong param_1,int param_2)

{
  uint uVar1;
  undefined1 *puVar2;
  uint *puVar3;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  longlong lVar9;
  undefined1 *puVar10;
  undefined1 *in_stack_ffffffffffffffc8;
  undefined4 uVar11;
  
  uVar1 = **(uint **)(param_1 + 0x18);
  if (uVar1 == 0xffffffff) {
    return (ulonglong)*(uint **)(param_1 + 0x18) & 0xffffffffffffff00;
  }
  if ((uVar1 & 0xf0000000) == 0x40000000) {
    in_stack_ffffffffffffffc8 =
         (undefined1 *)((ulonglong)in_stack_ffffffffffffffc8 & 0xffffffffffffff00);
    StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffffc8,6,(uVar1 & 0xffff) + 0xad0f0000);
    if (*(char *)(param_1 + 0xdae) == '\0') goto LAB_14000bc8b;
    *(undefined4 *)(param_1 + 0x147c) = _DAT_0000face;
  }
  if (*(char *)(param_1 + 0xdae) != '\0') {
    *(undefined4 *)(param_1 + 0x147c) = _DAT_0000dead;
  }
LAB_14000bc8b:
  *(undefined1 *)(param_1 + 0xdf2) = 1;
  EnableDiagnosticRegister(param_1);
  uVar1 = **(uint **)(param_1 + 0xe0);
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
    puVar3 = *(uint **)(param_1 + 0x28);
    uVar8 = *puVar3;
    if (uVar8 == 0xffffffff) goto LAB_14000bd29;
    if ((uVar8 & 4) == 0) break;
    StorPortStallExecution(500);
    uVar6 = uVar6 + 1;
  } while (uVar6 < 600000);
  if (uVar6 == 600000) {
    uVar11 = 0xad010023;
  }
  else {
    if ((uVar8 >> 8 & 1) != 0) {
      uVar8 = uVar8 & 0xffffefff | 0x800;
      **(uint **)(param_1 + 0x28) = uVar8;
      LOCK();
      UNLOCK();
      **(uint **)(param_1 + 0xe0) = uVar1 | 1;
      LOCK();
      UNLOCK();
    }
    **(uint **)(param_1 + 0x28) = uVar8 & 0xfffffffd;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0x20) = 0;
    LOCK();
    UNLOCK();
    puVar3 = (uint *)GtfInitialize(param_1);
    pcVar7 = (char *)(param_1 + 0x12f0);
    lVar9 = 3;
    do {
      if (((*pcVar7 != '\0') && (pcVar7[1] != '\0')) && (pcVar7[2] != '\0')) {
        puVar2 = *(undefined1 **)(param_1 + 0x548);
        if (*(ushort *)(param_1 + 0x240) != 0) {
          puVar10 = puVar2;
          for (uVar4 = (ulonglong)*(ushort *)(param_1 + 0x240); uVar4 != 0; uVar4 = uVar4 - 1) {
            *puVar10 = 0;
            puVar10 = puVar10 + 1;
          }
        }
        puVar2[1] = pcVar7[-4];
        puVar2[3] = 0x1e;
        puVar3 = (uint *)QueueRequestDescriptor
                                   (param_1,(uint)*(ushort *)(param_1 + 0x5aa) * 0x10000 + 8,0,
                                    param_2);
        pcVar7[2] = '\0';
        pcVar7[-2] = '\x01';
      }
      pcVar7 = pcVar7 + 0x18;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    if ((*(char *)(param_1 + 0xdb6) != '\0') || (*(int *)(param_1 + 0xdf8) != 0)) {
LAB_14000bf08:
      return CONCAT71((int7)((ulonglong)puVar3 >> 8),1);
    }
    do {
      puVar3 = *(uint **)(param_1 + 0x18);
      if (*puVar3 == 0xffffffff) goto LAB_14000bd29;
      if ((*puVar3 & 0xf0000000) == 0x10000000) {
        if (uVar5 < 60000) {
          if ((*(char *)(param_1 + 0x308) != '\0') &&
             (puVar3 = (uint *)(ulonglong)*(uint *)(param_1 + 0x30c),
             (*(uint *)(param_1 + 0x30c) >> 0x12 & 1) != 0)) {
            puVar3 = (uint *)RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),
                                         0x40000,(undefined1 *)(param_1 + 0xd84),4,param_2);
          }
          goto LAB_14000bf08;
        }
        break;
      }
      StorPortStallExecution(1000);
      uVar5 = uVar5 + 1;
    } while (uVar5 < 60000);
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) >> 9 & 1) != 0)) {
      in_stack_ffffffffffffffc8 = (undefined1 *)(param_1 + 0xd84);
      RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x200,
                  in_stack_ffffffffffffffc8,4,param_2);
    }
    uVar11 = 0xad01000b;
  }
  puVar3 = (uint *)StorPortLogError(param_1,0,0,0,
                                    (ulonglong)in_stack_ffffffffffffffc8 & 0xffffffffffffff00,6,
                                    uVar11);
LAB_14000bd29:
  return (ulonglong)puVar3 & 0xffffffffffffff00;
}



===== LSImpiAdapterControl @ 14000bf10 =====

undefined8 LSImpiAdapterControl(longlong param_1,int param_2,longlong param_3)

{
  if (param_2 == 0) {
    *(undefined2 *)(param_3 + 4) = 0x101;
    *(undefined1 *)(param_3 + 6) = 1;
  }
  else {
    if (param_2 == 1) {
      *(undefined1 *)(param_1 + 0xdb9) = 1;
      if (*(char *)(param_1 + 0xdb6) != '\0') {
        *(undefined1 *)(param_1 + 0xdb7) = 1;
        return 0;
      }
      **(uint **)(param_1 + 0x50) = **(uint **)(param_1 + 0x50) | 0x40000009;
      LOCK();
      UNLOCK();
      CheckForIRShutdown(param_1,'\x01',7);
      if (*(short *)(param_1 + 0x3d48) != 0) {
        SendAndProcessSSUCommands(param_1,7);
      }
      FlushAllDPMPage0(param_1,7);
      *(undefined1 *)(param_1 + 0xdb7) = 1;
      if ((*(uint *)(param_1 + 0xdec) & 0x2000) == 0) {
        KickStart(param_1,7);
        *(undefined1 *)(param_1 + 0xdb6) = 1;
        *(undefined1 *)(param_1 + 0xdb9) = 0;
        return 0;
      }
      IssueReset(param_1,0x40);
      *(undefined1 *)(param_1 + 0xdb6) = 1;
      *(undefined1 *)(param_1 + 0xdb9) = 0;
      return 0;
    }
    if (param_2 == 2) {
      *(undefined1 *)(param_1 + 0xdb9) = 1;
      *(undefined4 *)(param_1 + 0xdf8) = 1;
      *(undefined2 *)(param_1 + 0xdf4) = 0;
      *(undefined1 *)(param_1 + 0xdb7) = 0;
      StorPortPause(param_1,300);
      if (((*(uint *)(param_1 + 0xdec) & 0x2000) == 0) || (**(int **)(param_1 + 0x18) == 0)) {
        *(undefined4 *)(param_1 + 0x57c) = *(undefined4 *)(param_1 + 0x580);
        *(undefined1 *)(param_1 + 0xdb9) = 0;
        return 0;
      }
      IssueReset(param_1,0x40);
      *(undefined1 *)(param_1 + 0xdb9) = 0;
      return 0;
    }
  }
  return 0;
}



===== LSImpiReset @ 14000c090 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 LSImpiReset(longlong param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint *in_RAX;
  undefined8 uVar2;
  ulonglong uVar3;
  ushort local_res8 [4];
  undefined2 local_res20 [4];
  ulonglong in_stack_ffffffffffffffc8;
  
  if (*(short *)(param_1 + 0x560) != 0) {
    in_stack_ffffffffffffffc8 = in_stack_ffffffffffffffc8 & 0xffffffffffffff00;
    in_RAX = (uint *)StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffffc8,6,0xad010016);
  }
  uVar1 = 0;
  if ((*(char *)(param_1 + 0x308) != '\0') &&
     (in_RAX = (uint *)(ulonglong)*(uint *)(param_1 + 0x30c),
     (*(uint *)(param_1 + 0x30c) & 0x20013) != 0)) {
    in_stack_ffffffffffffffc8 = 0;
    in_RAX = (uint *)RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x20013,
                                 (undefined1 *)0x0,0,param_3);
  }
  if (*(char *)(param_1 + 0xdad) != '\0') {
    in_RAX = (uint *)(ulonglong)_DAT_00000002;
    *(uint *)(param_1 + 0x147c) = _DAT_00000002;
  }
  if (*(int *)(param_1 + 0xdf8) == 0) {
    if (*(longlong *)(param_1 + 0x528) != 0) {
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x20015) != 0)) {
        in_stack_ffffffffffffffc8 = 0;
        RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x20015,
                    (undefined1 *)0x0,0,param_3);
      }
      StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffffc8 & 0xffffffffffffff00,6,0xad010036);
      **(uint **)(param_1 + 0x50) = **(uint **)(param_1 + 0x50) | 0x40000009;
      LOCK();
      UNLOCK();
      if (*(int *)(param_1 + 0x570) == 0) {
        StorPortPause(param_1,400);
      }
      *(undefined4 *)(param_1 + 0xdf8) = 1;
      uVar2 = KickStart(param_1,param_3);
      return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
    }
    in_RAX = *(uint **)(param_1 + 0x18);
    if ((*in_RAX & 0xf0000000) == 0x20000000) {
      if (*(int *)(param_1 + 0x568) == 0) {
        if (((*(char *)(param_1 + 0xdfe) != '\0') && (*(byte *)(param_1 + 0xe00) == param_2)) &&
           (*(char *)((longlong)*(short **)(param_1 + 0xe58) + 3) == '\0')) {
          uVar3 = GetBusTargetFromDevHandle
                            (param_1,**(short **)(param_1 + 0xe58),local_res8,local_res20);
          if (((char)uVar3 != '\0') && (local_res8[0] != param_2)) {
            *(ushort *)(param_1 + 0x564) =
                 *(ushort *)(param_1 + 0x564) | (ushort)(1 << (param_2 & 0x1f));
            param_2 = (uint)local_res8[0];
          }
        }
        *(undefined1 *)(param_1 + 0x1574) = 0;
        *(undefined2 *)(param_1 + 0x6a6) = 1;
        *(char *)(param_1 + 0xdb3) = (char)param_2;
        in_RAX = (uint *)ProcessBusReset(param_1,param_3);
        if ((char)in_RAX != '\0') {
          in_RAX = (uint *)ResetActive(param_1,3,param_3);
          *(undefined1 *)(param_1 + 0xdf0) = 1;
          if (*(int *)(param_1 + 0x570) == 0) {
            in_RAX = (uint *)StorPortPause(param_1,300);
          }
          else {
            while (*(int *)(param_1 + 0x568) != 0) {
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
      else if ((*(char *)(param_1 + 0xdb8) != '\0') || ((char)param_2 != *(char *)(param_1 + 0xdb3))
              ) {
        uVar1 = (uint)*(ushort *)(param_1 + 0x564) | 1 << (param_2 & 0x1f);
        *(short *)(param_1 + 0x564) = (short)uVar1;
        return CONCAT71((uint7)(uint3)(uVar1 >> 8),1);
      }
    }
  }
  else if ((*(char *)(param_1 + 0x308) != '\0') &&
          (in_RAX = (uint *)(ulonglong)*(uint *)(param_1 + 0x30c),
          (*(uint *)(param_1 + 0x30c) & 0x20014) != 0)) {
    uVar2 = RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x20014,
                        (undefined1 *)0x0,0,param_3);
    return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
  }
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}



===== LsiHandleAppRequest @ 14000c3a0 =====

void LsiHandleAppRequest(longlong param_1,void *param_2,int param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 *puVar6;
  char cVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  byte bVar10;
  ulonglong uVar11;
  short sVar12;
  undefined1 uVar13;
  char local_res8 [8];
  
  lVar4 = *(longlong *)((longlong)param_2 + 0x40);
  *(void **)(param_1 + 0xe10) = param_2;
  *(void **)(param_1 + 0xe08) = param_2;
  *(undefined4 *)(param_1 + 0xe70) = 0;
  cVar7 = CsmiInitiateIoctlRequest(param_1,local_res8,param_3);
  if (cVar7 == '\0') {
    uVar2 = *(uint *)(lVar4 + 0x10);
    if (uVar2 < 0x806d706a) {
      if (uVar2 == 0x806d7069) {
        if ((*(int *)(param_1 + 0x568) == 0) &&
           (uVar9 = SendIOCTLMessage(param_1,(ushort *)(lVar4 + 0x1c),param_2,param_3),
           (char)uVar9 != '\0')) {
          return;
        }
        *(undefined4 *)((longlong)param_2 + 0x10) = 0;
        goto LAB_14000c4b9;
      }
      if (uVar2 == 0x800000ff) goto LAB_14000c4b9;
      if (uVar2 == 0x8043494d) {
        uVar11 = 0;
        do {
          bVar10 = (byte)uVar11;
          if (*(char *)(lVar4 + 4 + uVar11) != (&CIM_IOCTLVER)[uVar11]) {
            *(undefined4 *)((longlong)param_2 + 0x10) = 0;
            break;
          }
          bVar10 = bVar10 + 1;
          uVar11 = (ulonglong)bVar10;
        } while (bVar10 < 4);
        if (bVar10 != 4) goto LAB_14000c4b9;
        uVar9 = RetrieveHostDriverData(param_1,(longlong)param_2);
        uVar8 = (undefined4)uVar9;
      }
      else {
        if (uVar2 != 0x804d4150) {
          if (uVar2 == 0x80646961) {
            uVar11 = 0;
            do {
              bVar10 = (byte)uVar11;
              if (*(char *)(lVar4 + 4 + uVar11) != (&FW_DIAG_IOCTLSIG)[uVar11]) {
                *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
                break;
              }
              bVar10 = bVar10 + 1;
              uVar11 = (ulonglong)bVar10;
            } while (bVar10 < 8);
            if (bVar10 == 8) {
              *(void **)(param_1 + 0x1350) = param_2;
              uVar9 = PerformFwDiagOperation(param_1,lVar4,local_res8,param_3);
              if ((char)uVar9 == '\0') {
                *(undefined1 *)((longlong)param_2 + 3) = 1;
              }
              else if (local_res8[0] == '\0') {
                *(undefined1 *)(param_1 + 0xdfe) = 1;
                return;
              }
            }
            goto LAB_14000c4b9;
          }
          goto LAB_14000c58c;
        }
        uVar9 = BusTargetDevHandleMapping(param_1,(longlong)param_2);
        uVar8 = (undefined4)uVar9;
      }
      *(undefined4 *)((longlong)param_2 + 0x3c) = uVar8;
      goto LAB_14000c4b9;
    }
    if (uVar2 == 0x80727374) {
      uVar11 = 0;
      do {
        bVar10 = (byte)uVar11;
        if (*(char *)(lVar4 + 4 + uVar11) != (&RST_IOCTLSIG)[uVar11]) {
          *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
          break;
        }
        bVar10 = bVar10 + 1;
        uVar11 = (ulonglong)bVar10;
      } while (bVar10 < 8);
      if (bVar10 == 8) {
        if (*(uint *)((longlong)param_2 + 0x28) < 0x1e) {
          *(undefined4 *)((longlong)param_2 + 0x28) = 0x1e;
        }
        *(undefined1 *)(param_1 + 0xdfe) = 1;
        StorPortPause(param_1,400);
        ResetActive(param_1,0xb,param_3);
        puVar6 = *(undefined8 **)(param_1 + 0x548);
        *puVar6 = 0;
        puVar6[1] = 0;
        puVar6[2] = 0;
        puVar6[3] = 0;
        puVar6[4] = 0;
        *(undefined4 *)(puVar6 + 5) = 0;
        *(undefined1 *)((longlong)puVar6 + 3) = 7;
        *(undefined8 *)((longlong)puVar6 + 0x14) = 0xffffffffffffffff;
        *(undefined8 *)((longlong)puVar6 + 0x1c) = 0xffffffffffffffff;
        *(undefined1 *)(param_1 + 0xda5) = 1;
        **(int **)(param_1 + 0xe8) = (uint)*(ushort *)(param_1 + 0x5aa) * 0x10000 + 8;
        LOCK();
        UNLOCK();
        **(undefined4 **)(param_1 + 0xf0) = 0;
        LOCK();
        UNLOCK();
        *(undefined4 *)(param_1 + 0x578) = 4;
        return;
      }
      goto LAB_14000c4b9;
    }
    if (uVar2 != 0x80727474) {
      if (uVar2 == 0x80771959) {
        uVar11 = 0;
        do {
          bVar10 = (byte)uVar11;
          if (*(char *)(lVar4 + 4 + uVar11) != (&MPI_IOCTLVER)[uVar11]) {
            *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
            break;
          }
          bVar10 = bVar10 + 1;
          uVar11 = (ulonglong)bVar10;
        } while (bVar10 < 4);
        if (bVar10 == 4) {
          lVar4 = *(longlong *)((longlong)param_2 + 0x40);
          lVar5 = *(longlong *)(param_1 + 0xf8);
          uVar8 = *(undefined4 *)(lVar4 + 0x24);
          sVar12 = (short)*(uint *)(lVar4 + 0x20) + (short)lVar5;
          puVar1 = (undefined4 *)
                   ((ulonglong)*(uint *)(lVar4 + 0x20) + *(longlong *)(param_1 + 0x10));
          iVar3 = *(int *)(lVar4 + 0x1c);
          if (iVar3 == 1) {
            if (lVar5 == 0) {
              *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
              *(undefined4 *)(lVar4 + 0x24) = uVar8;
            }
            else {
              uVar8 = in(sVar12);
              *(undefined4 *)(lVar4 + 0x24) = uVar8;
            }
          }
          else if (iVar3 == 2) {
            if (lVar5 == 0) {
              *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
              *(undefined4 *)(lVar4 + 0x24) = uVar8;
            }
            else {
              out(sVar12,uVar8);
              *(undefined4 *)(lVar4 + 0x24) = uVar8;
            }
          }
          else if (iVar3 == 3) {
            *(undefined4 *)(lVar4 + 0x24) = *puVar1;
          }
          else if (iVar3 == 4) {
            *puVar1 = uVar8;
            LOCK();
            UNLOCK();
            *(undefined4 *)(lVar4 + 0x24) = uVar8;
          }
          else {
            *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
            *(undefined4 *)(lVar4 + 0x24) = uVar8;
          }
        }
        goto LAB_14000c4b9;
      }
LAB_14000c58c:
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x203) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x203,
                    (undefined1 *)(lVar4 + 0x10),4,param_3);
      }
      *(undefined1 *)((longlong)param_2 + 3) = 6;
      *(undefined4 *)((longlong)param_2 + 0x3c) = 0;
      goto LAB_14000c4b9;
    }
    uVar11 = 0;
    do {
      bVar10 = (byte)uVar11;
      if (*(char *)(lVar4 + 4 + uVar11) != RTTRACE_IOCTL_SIG[uVar11]) {
        *(undefined4 *)((longlong)param_2 + 0x10) = 0;
        break;
      }
      bVar10 = bVar10 + 1;
      uVar11 = (ulonglong)bVar10;
    } while (bVar10 < 8);
    if (bVar10 != 8) goto LAB_14000c4b9;
    uVar9 = HandleRttIoctl(param_1,lVar4,local_res8);
    if ((char)uVar9 == '\0') {
      *(undefined1 *)((longlong)param_2 + 3) = 1;
      goto LAB_14000c4b9;
    }
  }
  if (local_res8[0] == '\0') {
    return;
  }
LAB_14000c4b9:
  if ((*(char *)((longlong)param_2 + 3) != '\x03') && (*(char *)((longlong)param_2 + 3) != '\x06'))
  {
    uVar13 = 4;
    if (*(int *)((longlong)param_2 + 0x3c) != 0) {
      uVar13 = 1;
    }
    *(undefined1 *)((longlong)param_2 + 3) = uVar13;
  }
  StorPortNotification(0,param_1,param_2);
  *(undefined8 *)(param_1 + 0xe08) = 0;
  return;
}



===== LsiMpiPartitionMemory @ 14000c810 =====

void LsiMpiPartitionMemory(longlong param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  undefined8 *puVar5;
  undefined2 *puVar6;
  longlong lVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  uint *puVar10;
  uint uVar11;
  longlong lVar12;
  uint uVar13;
  undefined1 *puVar14;
  uint uVar15;
  undefined4 *puVar16;
  undefined8 *puVar17;
  undefined1 *puVar18;
  longlong lVar19;
  longlong *plVar20;
  longlong *plVar21;
  int iVar22;
  uint uVar23;
  
  uVar1 = *(ushort *)(param_1 + 0x594);
  uVar2 = *(ushort *)(param_1 + 0x240);
  uVar9 = (ulonglong)uVar2;
  uVar3 = *(ushort *)(param_1 + 0x23e);
  uVar4 = *(ushort *)(param_1 + 0x248);
  *(undefined2 *)(param_1 + 0x564) = 0;
  *(undefined4 *)(param_1 + 0x568) = 0;
  *(undefined4 *)(param_1 + 0xe74) = 0;
  *(undefined8 *)(param_1 + 0x574) = 0;
  *(undefined8 *)(param_1 + 0x528) = 0;
  *(undefined8 *)(param_1 + 0x530) = 0;
  *(undefined1 *)(param_1 + 0xdff) = 0;
  *(undefined2 *)(param_1 + 0xdf0) = 0;
  *(undefined1 *)(param_1 + 0xdb8) = 0;
  *(undefined2 *)(param_1 + 0xdbb) = 0;
  *(undefined2 *)(param_1 + 0xde8) = 0xfe;
  *(undefined4 *)(param_1 + 0xdc0) = 0;
  *(undefined2 *)(param_1 + 0xdbe) = 0;
  *(undefined1 *)(param_1 + 0xdc4) = 0;
  *(undefined8 *)(param_1 + 0x14e0) = 0;
  *(undefined8 *)(param_1 + 0x14e8) = 0;
  *(undefined1 *)(param_1 + 0x14cc) = 0;
  *(undefined1 *)(param_1 + 0x2d0) = 0;
  *(undefined1 *)(param_1 + 0x5b6) = 0;
  if ((*(char *)(param_1 + 0xdfe) != '\0') && (*(char *)(param_1 + 0xdb0) == '\0')) {
    if (*(longlong *)(param_1 + 0xe08) != 0) {
      *(undefined1 *)(*(longlong *)(param_1 + 0xe08) + 3) = 4;
      StorPortNotification(0,param_1);
      *(undefined8 *)(param_1 + 0xe08) = 0;
    }
    CsmiIdleAllStateMachines(param_1);
  }
  uVar13 = (uint)uVar2;
  *(longlong *)(param_1 + 0x260) = *(longlong *)(param_1 + 8);
  *(int *)(param_1 + 0x1f8) = *(int *)(param_1 + 0x1e8);
  *(undefined1 *)(param_1 + 0xdfe) = 0;
  *(undefined1 *)(param_1 + 0x14fc) = 0;
  lVar19 = *(longlong *)(param_1 + 8) + (ulonglong)((uVar1 + 1) * uVar13);
  *(undefined2 *)(param_1 + 0x14f8) = 0;
  *(longlong *)(param_1 + 0x548) = lVar19;
  lVar19 = lVar19 + uVar9;
  *(longlong *)(param_1 + 0x268) = lVar19;
  iVar22 = *(int *)(param_1 + 0x1e8) + (uVar1 + 2) * uVar13;
  *(ushort *)(param_1 + 0x5aa) = uVar1 + 1;
  *(ulonglong *)(param_1 + 0x270) = uVar9 + lVar19;
  *(int *)(param_1 + 0x1fc) = iVar22;
  *(ulonglong *)(param_1 + 0x278) = (ulonglong)((uint)uVar2 * 2) + lVar19;
  *(ulonglong *)(param_1 + 0x280) = (ulonglong)((uint)uVar2 * 3) + lVar19;
  *(ulonglong *)(param_1 + 0x288) = (ulonglong)((uint)uVar2 * 4) + lVar19;
  *(uint *)(param_1 + 0x200) = iVar22 + (uint)uVar2;
  *(uint *)(param_1 + 0x204) = (uint)uVar2 * 2 + iVar22;
  *(uint *)(param_1 + 0x208) = (uint)uVar2 * 3 + iVar22;
  *(uint *)(param_1 + 0x20c) = (uint)uVar2 * 4 + iVar22;
  iVar22 = iVar22 + (uint)uVar2 * 5;
  lVar19 = lVar19 + (ulonglong)((uint)uVar2 * 5);
  *(int *)(param_1 + 0x1f0) = iVar22;
  *(longlong *)(param_1 + 0x250) = lVar19;
  puVar14 = *(undefined1 **)(param_1 + 0x250);
  *(ushort *)(param_1 + 0x5ac) = uVar1 + 2;
  *(ushort *)(param_1 + 0x5ae) = uVar1 + 3;
  *(ushort *)(param_1 + 0x5b0) = uVar1 + 4;
  *(ushort *)(param_1 + 0x5b2) = uVar1 + 5;
  *(ushort *)(param_1 + 0x5b4) = uVar1 + 6;
  lVar7 = (ulonglong)*(ushort *)(param_1 + 0x244) * 4;
  iVar22 = iVar22 + (int)lVar7;
  lVar19 = lVar19 + lVar7;
  if ((int)lVar7 != 0) {
    for (; lVar7 != 0; lVar7 = lVar7 + -1) {
      *puVar14 = 0;
      puVar14 = puVar14 + 1;
    }
  }
  uVar11 = (uint)*(ushort *)(param_1 + 0x246);
  *(longlong *)(param_1 + 600) = lVar19;
  *(int *)(param_1 + 500) = iVar22;
  if (*(char *)(param_1 + 0x12a) != '\0') {
    uVar11 = (uint)*(ushort *)(param_1 + 0x246) * (uint)*(byte *)(param_1 + 299);
  }
  lVar19 = lVar19 + (ulonglong)(uVar11 * 8);
  if (uVar11 != 0) {
    puVar16 = *(undefined4 **)(param_1 + 600);
    for (uVar8 = (ulonglong)(uVar11 * 2); uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar16 = 0xffffffff;
      puVar16 = puVar16 + 1;
    }
  }
  uVar23 = uVar1 + 6;
  puVar6 = (undefined2 *)(param_1 + 0x21a);
  for (lVar7 = 0x10; lVar7 != 0; lVar7 = lVar7 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  uVar8 = 1;
  *(longlong *)(param_1 + 0x290) = lVar19;
  plVar20 = (longlong *)(lVar19 + (ulonglong)uVar4 * (ulonglong)uVar3);
  *(uint *)(param_1 + 0x210) = iVar22 + uVar11 * 8;
  *(longlong **)(param_1 + 0x298) = plVar20;
  *(longlong **)(param_1 + 0x508) = plVar20;
  *(longlong **)(param_1 + 0x510) = plVar20;
  *(longlong **)(param_1 + 0x518) = plVar20;
  *(longlong **)(param_1 + 0x2a0) = plVar20 + ((ulonglong)uVar1 - 3);
  plVar21 = plVar20;
  if (uVar23 != 0) {
    uVar11 = uVar13;
    do {
      lVar7 = uVar8 * 0x18;
      *(ulonglong *)(lVar7 + *(longlong *)(param_1 + 0x2a0)) =
           (ulonglong)uVar11 + *(longlong *)(param_1 + 0x260);
      *(undefined8 *)(*(longlong *)(param_1 + 0x2a0) + 8 + lVar7) = 0;
      *(short *)(*(longlong *)(param_1 + 0x2a0) + 0x10 + lVar7) = (short)uVar8;
      *(undefined1 *)(*(longlong *)(param_1 + 0x2a0) + 0x13 + lVar7) = 0;
      *(undefined1 *)(*(longlong *)(param_1 + 0x2a0) + 0x12 + lVar7) = 0;
      if ((uint)uVar8 <= (uint)uVar1) {
        *plVar21 = *(longlong *)(param_1 + 0x2a0) + lVar7;
        plVar21 = plVar21 + 1;
      }
      uVar15 = (uint)uVar8 + 1;
      uVar8 = (ulonglong)uVar15;
      uVar11 = uVar11 + uVar13;
    } while (uVar15 <= uVar23);
  }
  *(longlong **)(param_1 + 0x520) = plVar21;
  plVar20 = plVar20 + (ulonglong)uVar1 + (ulonglong)uVar23 * 3;
  uVar13 = 0;
  *(longlong **)(param_1 + 0xdd8) = plVar20;
  *(longlong **)(param_1 + 0xde0) = plVar20 + 0x20;
  *(longlong **)(param_1 + 0xe58) = plVar20 + 0x60;
  lVar7 = (longlong)(plVar20 + 0x60) + uVar9;
  *(longlong *)(param_1 + 0x2c8) = lVar7;
  puVar17 = *(undefined8 **)(param_1 + 0x2c8);
  lVar7 = lVar7 + (ulonglong)(uint)(*(int *)(param_1 + 0x5b8) * 0x28);
  if (*(int *)(param_1 + 0x5b8) != 0) {
    do {
      ClearMapEntry(param_1,puVar17);
      uVar13 = uVar13 + 1;
      puVar17 = puVar17 + 5;
    } while (uVar13 < *(uint *)(param_1 + 0x5b8));
  }
  uVar13 = 0;
  *(longlong *)(param_1 + 0x2a8) = lVar7;
  puVar17 = *(undefined8 **)(param_1 + 0x2a8);
  lVar7 = lVar7 + (ulonglong)*(ushort *)(param_1 + 0x59a) * 0x1c;
  if (*(ushort *)(param_1 + 0x59a) != 0) {
    do {
      ClearEnclosureEntry(puVar17);
      uVar13 = uVar13 + 1;
      puVar17 = (undefined8 *)((longlong)puVar17 + 0x1c);
    } while (uVar13 < *(ushort *)(param_1 + 0x59a));
  }
  uVar13 = *(int *)(param_1 + 0x5b8) << 3;
  *(longlong *)(param_1 + 0x2c0) = lVar7;
  puVar14 = *(undefined1 **)(param_1 + 0x2c0);
  uVar9 = (ulonglong)uVar13;
  lVar7 = lVar7 + uVar9;
  if (uVar13 != 0) {
    for (; uVar9 != 0; uVar9 = uVar9 - 1) {
      *puVar14 = 0;
      puVar14 = puVar14 + 1;
    }
  }
  uVar13 = 0;
  puVar6 = *(undefined2 **)(param_1 + 0x2c0);
  if (*(int *)(param_1 + 0x5b8) != 0) {
    do {
      *puVar6 = 0xffff;
      puVar6 = puVar6 + 4;
      uVar13 = uVar13 + 1;
    } while (uVar13 < *(uint *)(param_1 + 0x5b8));
  }
  uVar13 = (uint)*(ushort *)(param_1 + 0x59c) * 0x3cc;
  *(longlong *)(param_1 + 0x2b0) = lVar7;
  puVar14 = *(undefined1 **)(param_1 + 0x2b0);
  uVar9 = (ulonglong)uVar13;
  lVar7 = lVar7 + uVar9;
  if (uVar13 != 0) {
    for (; uVar9 != 0; uVar9 = uVar9 - 1) {
      *puVar14 = 0;
      puVar14 = puVar14 + 1;
    }
  }
  *(longlong *)(param_1 + 0x2b8) = lVar7;
  lVar19 = 0x33;
  puVar14 = (undefined1 *)(lVar7 + 0xcd0);
  puVar17 = *(undefined8 **)(param_1 + 0x2b8);
  do {
    puVar5 = puVar17;
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[4] = 0;
    puVar5[5] = 0;
    puVar5[6] = 0;
    puVar5[7] = 0;
    lVar19 = lVar19 + -1;
    puVar17 = puVar5 + 8;
  } while (lVar19 != 0);
  puVar5[8] = 0;
  puVar5[9] = 0;
  uVar13 = *(uint *)(param_1 + 0x300);
  if ((*(char *)(param_1 + 0xdce) == '\0') &&
     (*(undefined1 **)(param_1 + 0x2d8) = puVar14, uVar13 != 0)) {
    puVar18 = puVar14;
    for (uVar9 = (ulonglong)uVar13; uVar9 != 0; uVar9 = uVar9 - 1) {
      *puVar18 = 0;
      puVar18 = puVar18 + 1;
    }
  }
  puVar14 = puVar14 + uVar13;
  lVar7 = 4;
  uVar1 = *(ushort *)(param_1 + 0x14bc);
  uVar13 = (uint)uVar1;
  *(undefined1 **)(param_1 + 0x14d0) = puVar14;
  if ((uVar1 & 3) != 0) {
    uVar13 = (uint)uVar1 + (4 - (uVar1 & 3));
  }
  puVar18 = *(undefined1 **)(param_1 + 0x14d0);
  uVar9 = (ulonglong)uVar13;
  puVar14 = puVar14 + uVar9;
  if (uVar13 != 0) {
    for (; uVar9 != 0; uVar9 = uVar9 - 1) {
      *puVar18 = 0;
      puVar18 = puVar18 + 1;
    }
  }
  uVar1 = *(ushort *)(param_1 + 0x14bc);
  uVar13 = (uint)uVar1;
  *(undefined1 **)(param_1 + 0x14d8) = puVar14;
  if ((uVar1 & 3) != 0) {
    uVar13 = (uint)uVar1 + (4 - (uVar1 & 3));
  }
  puVar18 = *(undefined1 **)(param_1 + 0x14d8);
  uVar9 = (ulonglong)uVar13;
  puVar14 = puVar14 + uVar9;
  if (uVar13 != 0) {
    for (; uVar9 != 0; uVar9 = uVar9 - 1) {
      *puVar18 = 0;
      puVar18 = puVar18 + 1;
    }
  }
  *(undefined1 **)(param_1 + 0x1520) = puVar14;
  uVar13 = (uint)*(ushort *)(param_1 + 0x14bc) * 0x14 + 8;
  uVar9 = (ulonglong)uVar13;
  puVar14 = puVar14 + uVar9;
  if (uVar13 != 0) {
    puVar18 = *(undefined1 **)(param_1 + 0x1520);
    for (; uVar9 != 0; uVar9 = uVar9 - 1) {
      *puVar18 = 0;
      puVar18 = puVar18 + 1;
    }
  }
  *(undefined1 **)(param_1 + 0x1528) = puVar14;
  puVar10 = (uint *)(param_1 + 0x12e8);
  puVar17 = *(undefined8 **)(param_1 + 0x1528);
  puVar14 = puVar14 + 0x1c;
  uVar13 = 0;
  *puVar17 = 0;
  puVar17[1] = 0;
  puVar17[2] = 0;
  *(undefined4 *)(puVar17 + 3) = 0;
  do {
    if (((char)puVar10[2] == '\0') || (*puVar10 == 0)) {
      *(undefined1 *)(puVar10 + 2) = 0;
    }
    else {
      *(undefined1 **)(puVar10 + -2) = puVar14;
      puVar14 = puVar14 + *puVar10;
      *(char *)(puVar10 + 1) = (char)uVar13;
    }
    uVar13 = uVar13 + 1;
    puVar10 = puVar10 + 6;
  } while (uVar13 < 3);
  *(undefined4 *)(param_1 + 0x1588) = 0;
  *(undefined8 *)(param_1 + 0x1580) = 0;
  *(undefined1 **)(param_1 + 0x1578) = puVar14;
  *(undefined2 *)(param_1 + 0x158c) = 0;
  if (*(char *)(param_1 + 0xdce) == '\0') {
    *(ulonglong *)(param_1 + 0x1460) = ((ulonglong)(puVar14 + 0x34) & 0xfffffffffffffffc) + 4;
    *(undefined4 *)(param_1 + 0x145c) = 0x600;
  }
  lVar19 = 0xc;
  *(undefined2 *)(param_1 + 0xce8) = 0;
  lVar12 = 0xc;
  puVar17 = (undefined8 *)(param_1 + 0x6a8);
  do {
    puVar5 = puVar17;
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[4] = 0;
    puVar5[5] = 0;
    puVar5[6] = 0;
    puVar5[7] = 0;
    lVar12 = lVar12 + -1;
    puVar17 = puVar5 + 8;
  } while (lVar12 != 0);
  puVar5[8] = 0;
  lVar12 = 10;
  puVar5[9] = 0;
  puVar5[10] = 0;
  puVar5[0xb] = 0;
  puVar6 = (undefined2 *)(param_1 + 0xcec);
  *(undefined2 *)(param_1 + 0xcea) = 0;
  do {
    *puVar6 = 0;
    puVar6 = puVar6 + 4;
    lVar12 = lVar12 + -1;
  } while (lVar12 != 0);
  *(undefined2 *)(param_1 + 0xeba) = 0;
  puVar17 = (undefined8 *)(param_1 + 0xec0);
  do {
    *puVar17 = 0;
    puVar17[1] = 0;
    puVar17[2] = 0;
    puVar17[3] = 0;
    puVar17[4] = 0;
    puVar17[5] = 0;
    puVar17[6] = 0;
    puVar17[7] = 0;
    lVar7 = lVar7 + -1;
    puVar17 = puVar17 + 8;
  } while (lVar7 != 0);
  *(undefined2 *)(param_1 + 0xebc) = 0;
  puVar17 = (undefined8 *)(param_1 + 0xfc0);
  do {
    puVar5 = puVar17;
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[4] = 0;
    puVar5[5] = 0;
    puVar5[6] = 0;
    puVar5[7] = 0;
    lVar19 = lVar19 + -1;
    puVar17 = puVar5 + 8;
  } while (lVar19 != 0);
  puVar5[8] = 0;
  puVar5[9] = 0;
  puVar5[10] = 0;
  puVar5[0xb] = 0;
  return;
}



===== LunResetTurTimeout @ 14000cf90 =====

ulonglong LunResetTurTimeout(longlong param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  ulonglong uVar1;
  
  if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x2001c) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x2001c,
                (undefined1 *)(*(longlong *)(*(longlong *)(param_1 + 0x528) + 0x68) + 0x52),3,
                param_4);
  }
  *(undefined1 *)
   (*(longlong *)(param_1 + 0x2a0) + 0x13 + (ulonglong)*(ushort *)(param_1 + 0x5ae) * 0x18) = 0;
  uVar1 = IssueLunReset(param_1,param_4);
  return uVar1 & 0xffffffffffffff00;
}



===== NonSCB_Func_handler @ 14000d020 =====

void NonSCB_Func_handler(longlong param_1,short *param_2,short param_3,int param_4)

{
  undefined8 *puVar1;
  char cVar2;
  ushort uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong lVar7;
  byte bVar8;
  bool bVar9;
  ulonglong in_stack_ffffffffffffffc8;
  short *psVar10;
  uint uVar11;
  
  psVar10 = (short *)((longlong)param_2 + 3);
  switch(*(undefined1 *)psVar10) {
  case 1:
    uVar11 = 0;
    *(undefined4 *)(param_1 + 0x574) = 0;
    cVar2 = *(char *)((longlong)param_2 + 5);
    if (((*(char *)(param_1 + 0x14f8) != '\0') && (param_3 == *(short *)(param_1 + 0x5aa))) &&
       ((cVar2 == '\x02' || (cVar2 == '\a')))) {
      *(short **)(param_1 + 0x540) = param_2;
      SasBcAsyncEvent(param_1,param_4);
      break;
    }
    if (((*(uint *)(param_1 + 0x1588) & 1) != 0) && (*(short *)(param_1 + 0x158c) == param_3)) {
      lVar7 = *(longlong *)(param_1 + 0x1580);
      lVar6 = *(longlong *)(lVar7 + 0x68);
      *(undefined4 *)(param_1 + 0x1588) = 0;
      *(undefined2 *)(param_1 + 0x158c) = 0;
      *(undefined8 *)(param_1 + 0x1580) = 0;
      *(undefined1 *)(param_1 + 0x1574) = 0;
      *(undefined1 *)(*(longlong *)(lVar6 + 0x38) + 8) = 0;
      lVar6 = *(longlong *)(lVar7 + 0x40);
      *(undefined1 *)(lVar7 + 3) = 1;
      *(undefined1 *)(lVar6 + 0x3c) = 0;
      if (param_2[7] == 0) {
        *(undefined4 *)(lVar6 + 0x14) = 0;
        *(undefined1 *)(lVar6 + 0x39) = 2;
        if (cVar2 == '\a') {
          *(undefined1 *)(lVar6 + 0x3c) = 1;
          *(undefined1 *)(lVar6 + 0x3e) = 1;
          *(char *)(lVar6 + 0x40) = (char)param_2[2];
        }
      }
      else if (param_2[7] == 6) {
        *(undefined4 *)(lVar6 + 0x14) = 0;
        *(undefined1 *)(lVar6 + 0x39) = 4;
      }
      else {
        *(undefined4 *)(lVar6 + 0x14) = 1;
        *(undefined1 *)(lVar6 + 0x39) = 3;
      }
      StorPortNotification(0,param_1);
      *(undefined1 *)(param_1 + 0xdfe) = 0;
    }
    if (((*(char *)(param_1 + 0xdbb) != '\0') && (cVar2 == '\x03')) &&
       (param_3 == *(short *)(param_1 + 0x5b0))) {
      RemoveDevice(param_1,param_4);
      break;
    }
    if (((*(char *)(param_1 + 0xde9) != '\0') && (cVar2 == '\x01')) &&
       (param_3 == *(short *)(param_1 + 0x5b2))) {
      *(undefined1 *)(param_1 + 0xde9) = 0;
      uVar5 = ReadIDs(param_1,param_4);
      if ((char)uVar5 == '\0') {
        *(undefined1 *)(param_1 + 0xdc0) = 0;
        RemoveDevice(param_1,param_4);
      }
      break;
    }
    if (*(char *)(param_1 + 0xdf0) == '\0') {
      if (cVar2 != '\x05') {
        if (cVar2 != '\x03') goto LAB_14000d326;
        if ((*(char *)(param_1 + 0xdfe) != '\0') && (*(int *)(param_1 + 0xe70) == -0x21524111)) {
          puVar1 = *(undefined8 **)(param_1 + 0x548);
          *puVar1 = 0;
          puVar1[1] = 0;
          puVar1[2] = 0;
          puVar1[3] = 0;
          puVar1[4] = 0;
          *(undefined4 *)(puVar1 + 5) = 0;
          *(undefined1 *)((longlong)puVar1 + 3) = 7;
          *(undefined8 *)((longlong)puVar1 + 0x14) = 0xffffffffffffffff;
          *(undefined8 *)((longlong)puVar1 + 0x1c) = 0xffffffffffffffff;
          *(undefined1 *)(param_1 + 0xda5) = 1;
          **(int **)(param_1 + 0xe8) = (uint)*(ushort *)(param_1 + 0x5aa) * 0x10000 + 8;
          LOCK();
          UNLOCK();
          **(undefined4 **)(param_1 + 0xf0) = 0;
          LOCK();
          UNLOCK();
          *(undefined1 *)(param_1 + 0xdf1) = 1;
          StorPortNotification(6,param_1,DelayedIoctlTimeout,3000000);
          break;
        }
      }
      if ((*(longlong *)(param_1 + 0x528) != 0) &&
         (cVar2 = ProcessTmResetReply(param_1,param_2,param_4), cVar2 != '\0')) break;
    }
    else {
      if (*(short *)(param_1 + 0x560) != 0) {
        StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffffc8 & 0xffffffffffffff00,6,0xad010017);
      }
      uVar5 = ProcessBusReset(param_1,param_4);
      if ((char)uVar5 != '\0') break;
      if (*(int *)(param_1 + 0xdf8) != 0) {
        *(undefined1 *)(param_1 + 0xdf1) = 0;
        StorPortNotification(6,param_1,WatchdogTimer,100000);
        return;
      }
    }
LAB_14000d326:
    ResetActive(param_1,0x40000002,param_4);
    StorPortResume(param_1);
    do {
      uVar3 = 1 << ((byte)uVar11 & 0x1f);
      if ((uVar3 & *(ushort *)(param_1 + 0x564)) != 0) {
        *(ushort *)(param_1 + 0x564) = ~uVar3 & *(ushort *)(param_1 + 0x564);
        LSImpiReset(param_1,uVar11,param_4);
        break;
      }
      uVar11 = uVar11 + 1;
    } while (uVar11 < 8);
    break;
  case 4:
    *(ushort *)(param_1 + 0x145a) = param_2[7] & 0x7fff;
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x801) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x801,
                  (undefined1 *)param_2,0x18,param_4);
    }
    if (param_3 == *(short *)(param_1 + 0x5b0)) {
      if (*(char *)(param_1 + 0xdc2) != '\0') {
        *(undefined1 *)(param_1 + 0xdc2) = 0;
      }
      if (*(char *)(param_1 + 0xdc0) != '\0') {
        ContinueIDReadsForPhyEvents(param_1,param_4);
        break;
      }
      if (*(char *)(param_1 + 0xdc4) == '\0') goto LAB_14000d5e1;
      *(undefined1 *)(param_1 + 0xdc4) = 0;
      if (*(char *)((ulonglong)*(uint *)(param_1 + 0x14e4) * 0x3cc + 0x3c4 +
                   *(longlong *)(param_1 + 0x2b0)) != '\0') {
        UpdateMissingCount(param_1,param_4);
        StartIDReadsForPhyEvents(param_1,param_4);
        break;
      }
      *(undefined1 *)(param_1 + 0xdbe) = 0;
      if (*(char *)((ulonglong)*(uint *)(param_1 + 0x14ec) * 0x148 + 0x144 +
                   *(longlong *)(param_1 + 0x2b8)) != '\0') {
        *(undefined1 *)(param_1 + 0xdbf) = 1;
        StartIDReadsForIrElements(param_1,param_4);
        goto LAB_14000d5e1;
      }
      cVar2 = '\0';
      if (*(longlong *)(param_1 + 0x528) == 0) {
        if (*(int *)(param_1 + 0xdf8) == 0) {
          uVar5 = CheckResetQueue(param_1,param_4);
          cVar2 = (char)uVar5;
          goto LAB_14000d4d9;
        }
      }
      else {
LAB_14000d4d9:
        if (((*(int *)(param_1 + 0xdf8) == 0) && (cVar2 == '\0')) &&
           (*(longlong *)(param_1 + 0x528) == 0)) {
          StorPortResume(param_1);
          ResetActive(param_1,0x40000003,param_4);
        }
      }
      if (*(char *)(param_1 + 0x2d0) != '\0') {
        *(undefined1 *)(param_1 + 0x2d0) = 0;
        *(undefined1 *)(param_1 + 0xd80) = 1;
        if ((*(int *)(param_1 + 0xdf8) == 0) && (bVar8 = 0, *(short *)(param_1 + 0x5a0) != 0)) {
          do {
            if ((*(char *)(param_1 + 0x308) != '\0') &&
               ((*(uint *)(param_1 + 0x30c) & 0x100004) != 0)) {
              RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x100004,
                          (undefined1 *)0x0,0,param_4);
            }
            StorPortNotification(7,param_1,bVar8);
            bVar8 = bVar8 + 1;
          } while ((ushort)bVar8 < *(ushort *)(param_1 + 0x5a0));
        }
      }
    }
    else if (param_3 == *(short *)(param_1 + 0x5b2)) {
      if (*(char *)(param_1 + 0xdc1) != '\0') {
        ContinueIDReadsForIrElements(param_1,param_4);
        break;
      }
    }
    else if (*(char *)(param_1 + 0xdbc) != '\0') {
      *(undefined1 *)(param_1 + 0xdbc) = 0;
      FlushDPMPage0Entry(param_1,param_4);
    }
LAB_14000d5e1:
    uVar4 = *(undefined4 *)(param_2 + 10);
    if (((*(byte *)((longlong)param_2 + 0x17) & 0xf) == 0xf) && ((char)*param_2 == '\0')) {
      cVar2 = (char)param_2[3];
      if (cVar2 == '\x10') {
        if ((char)param_2[0xb] != '\0') {
          lVar7 = 0x159c;
          bVar9 = (char)param_2[0xb] == '\x01';
          goto LAB_14000d674;
        }
        lVar6 = 0x1594;
      }
      else if (cVar2 == '\x12') {
        if ((char)param_2[0xb] != '\0') {
          lVar7 = 0x15a4;
          bVar9 = (char)param_2[0xb] == '\x01';
          goto LAB_14000d674;
        }
        lVar6 = 0x1530;
      }
      else if (cVar2 == '\x13') {
        if ((char)param_2[0xb] == '\0') {
          lVar6 = 0x15ac;
        }
        else {
          lVar7 = 0x15b4;
          bVar9 = (char)param_2[0xb] == '\x01';
LAB_14000d674:
          lVar6 = 0x146c;
          if (bVar9) {
            lVar6 = lVar7;
          }
        }
      }
      else {
        if (cVar2 != '\x15') {
          lVar7 = 0x1518;
          bVar9 = cVar2 == '\x17';
          goto LAB_14000d674;
        }
        lVar6 = 0x1540;
      }
      *(char *)(lVar6 + param_1) = (char)uVar4;
      *(char *)(lVar6 + 2 + param_1) = (char)param_2[0xb];
      *(undefined1 *)(lVar6 + 3 + param_1) = *(undefined1 *)((longlong)param_2 + 0x17);
      *(short *)(lVar6 + 4 + param_1) = param_2[2];
      *(char *)(lVar6 + 6 + param_1) = (char)param_2[3];
    }
    else {
      *(undefined4 *)(param_1 + 0x1468) = uVar4;
    }
    if (*(char *)(param_1 + 0xdfd) != '\0') {
      if ((char)*param_2 == '\0') {
        *(undefined4 *)(param_1 + 0x1468) = uVar4;
      }
      break;
    }
    goto LAB_14000d6b2;
  case 6:
    uVar3 = param_2[7];
    *(undefined1 *)(param_1 + 0xdba) = 0;
    *(ushort *)(param_1 + 0x566) = uVar3 & 0x7fff;
    break;
  case 8:
    break;
  case 0x15:
    if ((char)*param_2 == ' ') {
      *(undefined1 *)(param_1 + 0xda6) = 0;
      if ((*(longlong *)(param_1 + 0x528) != 0) &&
         ((*(int *)(*(longlong *)(param_1 + 0x528) + 0x14) != 7 || (*(int *)(param_1 + 0x570) == 0))
         )) {
        uVar4 = 0xd;
        if (*(short *)(param_1 + 0x3d48) != 0) {
          uVar4 = 8;
        }
        *(undefined4 *)(param_1 + 0xdf8) = uVar4;
      }
    }
    break;
  case 0x18:
    psVar10 = param_2 + 7;
    if (((*psVar10 == 0) || (*(char *)(param_1 + 0x308) == '\0')) ||
       ((*(uint *)(param_1 + 0x30c) & 0x201) == 0)) break;
    uVar4 = 0x201;
    uVar11 = 2;
    goto LAB_14000d819;
  case 0x1b:
    if ((*(char *)(param_1 + 0xdbb) != '\0') && (param_3 == *(short *)(param_1 + 0x5b0))) {
      *(undefined1 *)(param_1 + 0xdbb) = 0;
      RemoveDevice(param_1,param_4);
      break;
    }
LAB_14000d6b2:
    CsmiDispatchStateMachine(param_1,(char *)param_2,param_4);
    break;
  case 0x1c:
    if (param_3 == *(short *)(param_1 + 0x5b0)) {
      ContinueHashedSASAddress(param_1,(longlong)param_2,param_4);
      break;
    }
  default:
    if (*(short *)(param_1 + 0x560) != 0) {
      StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffffc8 & 0xffffffffffffff00,5,
                       *(undefined1 *)psVar10);
    }
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x202) != 0)) {
      uVar4 = 0x202;
      uVar11 = 1;
LAB_14000d819:
      RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),uVar4,
                  (undefined1 *)psVar10,uVar11,param_4);
    }
  }
  if (*(char *)(param_1 + 0xdfe) == '\0') {
    CheckIoctlQueue(param_1,param_4);
  }
  return;
}



===== PauseDevice @ 14000d8a0 =====

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
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x232) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x232,
                  (undefined1 *)&local_48,0x10,param_9);
    }
  }
  else {
    *(char *)(lVar1 + 0x40) = *(char *)(lVar1 + 0x40) + '\x01';
    local_39 = *(undefined1 *)(lVar1 + 0x40);
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x111) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x111,
                  (undefined1 *)&local_48,0x10,param_9);
    }
    StorPortPauseDevice(param_1,param_2,param_3,param_4);
  }
  return;
}



===== PerformFwDiagOperation @ 14000da00 =====

ulonglong PerformFwDiagOperation(longlong param_1,longlong param_2,undefined1 *param_3,int param_4)

{
  longlong lVar1;
  longlong lVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  void *pvVar7;
  uint uVar8;
  ulonglong uVar9;
  void *pvVar10;
  byte bVar11;
  
  *param_3 = 1;
  *(undefined4 *)(param_2 + 0x14) = 0;
  memcpy((void *)(param_2 + 0x20),&FwDiagPageVersion,4);
  iVar5 = *(int *)(param_2 + 0x1c);
  if (iVar5 == 1) {
    pvVar10 = (void *)0x0;
    if (0x73 < *(uint *)(param_2 + 0x18)) {
      pvVar10 = (void *)0x0;
      if (*(byte *)(param_2 + 0x25) < 3) {
        piVar3 = (int *)(param_1 + (ulonglong)*(byte *)(param_2 + 0x25) * 0x18 + 0x12e0);
        pvVar7 = (void *)0x0;
        do {
          pvVar10 = pvVar7;
          if (*(int *)(param_1 + 0x12f4 + (longlong)pvVar10 * 0x18) == *(int *)(param_2 + 0x8c)) {
            if ((char)pvVar10 != -1) goto LAB_14000dab8;
            break;
          }
          bVar11 = (char)pvVar10 + 1;
          pvVar7 = (void *)(ulonglong)bVar11;
        } while (bVar11 < 3);
        if ((piVar3[5] == 0) && (*(int *)(param_2 + 0x8c) != 0)) {
          if ((*(char *)((longlong)piVar3 + 0xf) != '\0') &&
             (*(char *)((longlong)piVar3 + 0x12) != '\0')) {
            *(undefined1 *)((longlong)piVar3 + 0xf) = 0;
            iVar5 = *(int *)(param_2 + 0x8c);
            piVar3[5] = iVar5;
            return CONCAT71((uint7)(uint3)((uint)iVar5 >> 8),1);
          }
          if ((char)piVar3[4] == '\0') {
            *(undefined4 *)(param_2 + 0x14) = 0x13;
          }
          else {
            *(undefined1 *)((longlong)piVar3 + 0xf) = 0;
            if (*(char *)(param_2 + 0x25) == '\0') {
              memcpy((void *)(param_1 + 0x1328),(void *)(param_2 + 0x2c),0x28);
            }
            *(undefined1 *)((longlong)piVar3 + 0xd) = *(undefined1 *)(param_2 + 0x24);
            piVar3[5] = *(int *)(param_2 + 0x8c);
            pvVar10 = (void *)PostFwDiagBuffer(param_1,piVar3,0,param_4);
            if ((char)pvVar10 != '\0') goto LAB_14000de21;
LAB_14000db61:
            *(undefined4 *)(param_2 + 0x14) = 0x10;
          }
          goto LAB_14000dabf;
        }
        goto LAB_14000dab8;
      }
    }
  }
  else {
    pvVar10 = (void *)(ulonglong)(iVar5 - 2U);
    if (iVar5 - 2U == 0) {
LAB_14000dc73:
      if (iVar5 == 2) {
        if (0xb < *(uint *)(param_2 + 0x18)) {
          uVar9 = 0;
          do {
            bVar11 = (byte)uVar9;
            if (*(int *)(param_1 + 0x12f4 + uVar9 * 0x18) == *(int *)(param_2 + 0x24))
            goto LAB_14000dcdd;
            uVar9 = (ulonglong)(byte)(bVar11 + 1);
          } while ((byte)(bVar11 + 1) < 3);
LAB_14000dab8:
          pvVar10 = (void *)0x0;
          *(undefined4 *)(param_2 + 0x14) = 0x11;
          goto LAB_14000dabf;
        }
      }
      else if (0xb < *(uint *)(param_2 + 0x18)) {
        uVar9 = 0;
        do {
          bVar11 = (byte)uVar9;
          if (*(int *)(param_1 + 0x12f4 + uVar9 * 0x18) == *(int *)(param_2 + 0x24))
          goto LAB_14000dcdd;
          uVar9 = (ulonglong)(byte)(bVar11 + 1);
        } while ((byte)(bVar11 + 1) < 3);
        goto LAB_14000dab8;
      }
    }
    else if (iVar5 == 3) {
      pvVar10 = (void *)0x0;
      if (0x77 < *(uint *)(param_2 + 0x18)) {
        if (*(int *)(param_2 + 0x90) == 0) {
          bVar11 = *(byte *)(param_2 + 0x25);
          if (bVar11 < 3) {
LAB_14000dbc6:
            lVar1 = (ulonglong)bVar11 * 3 + 0x25c;
            cVar4 = *(char *)(param_1 + 0xc + lVar1 * 8);
            lVar1 = param_1 + lVar1 * 8;
            *(char *)(param_2 + 0x25) = cVar4;
            *(undefined1 *)(param_2 + 0x24) = *(undefined1 *)(lVar1 + 0xd);
            if (cVar4 == '\0') {
              memcpy((void *)(param_2 + 0x2c),(void *)(param_1 + 0x1328),0x28);
            }
            *(undefined4 *)(param_2 + 0x88) = *(undefined4 *)(lVar1 + 8);
            *(undefined4 *)(param_2 + 0x8c) = 0;
            uVar9 = (ulonglong)*(uint *)(lVar1 + 0x14);
            *(uint *)(param_2 + 0x90) = *(uint *)(lVar1 + 0x14);
            *(undefined2 *)(param_2 + 0x26) = 0;
            if (*(char *)(lVar1 + 0xf) == '\0') {
              uVar9 = 0;
              *(undefined2 *)(param_2 + 0x26) = 1;
            }
            else {
              *(undefined2 *)(param_2 + 0x26) = 0;
            }
            if ((*(char *)(lVar1 + 0x11) == '\0') && (*(char *)(lVar1 + 0x12) == '\0')) {
              uVar9 = 0xfffd;
              *(ushort *)(param_2 + 0x26) = *(ushort *)(param_2 + 0x26) & 0xfffd;
            }
            else {
              *(ushort *)(param_2 + 0x26) = *(ushort *)(param_2 + 0x26) | 2;
            }
            if (*(char *)(lVar1 + 0x12) == '\0') {
              *(ushort *)(param_2 + 0x26) = *(ushort *)(param_2 + 0x26) & 0xfffb;
              return 0xff01;
            }
            *(ushort *)(param_2 + 0x26) = *(ushort *)(param_2 + 0x26) | 4;
            return CONCAT71((int7)(uVar9 >> 8),1);
          }
          *(undefined4 *)(param_2 + 0x14) = 0;
          goto LAB_14000dabf;
        }
        bVar11 = 0;
        do {
          if (*(int *)(param_1 + 0x12f4 + (ulonglong)bVar11 * 0x18) == *(int *)(param_2 + 0x90)) {
            if (bVar11 != 0xff) goto LAB_14000dbc6;
            break;
          }
          bVar11 = bVar11 + 1;
        } while (bVar11 < 3);
        goto LAB_14000dab8;
      }
    }
    else if (iVar5 == 4) {
      uVar6 = *(uint *)(param_2 + 0x2c);
      pvVar10 = (void *)((ulonglong)uVar6 + 0xc);
      if (pvVar10 <= (void *)(ulonglong)*(uint *)(param_2 + 0x18)) {
        uVar9 = 0;
        do {
          if (*(int *)(param_1 + 0x12f4 + uVar9 * 0x18) == *(int *)(param_2 + 0x30)) {
            if ((char)uVar9 != -1) {
              lVar1 = param_1 + uVar9 * 0x18;
              uVar8 = *(uint *)(param_2 + 0x28) + uVar6;
              pvVar10 = (void *)(ulonglong)uVar8;
              if (*(uint *)(lVar1 + 0x12e8) < uVar8) goto LAB_14000da73;
              pvVar10 = memcpy((void *)(param_2 + 0x34),
                               (void *)((ulonglong)*(uint *)(param_2 + 0x28) +
                                       *(longlong *)(lVar1 + 0x12e0)),(ulonglong)uVar6);
              if (*(char *)(lVar1 + 0x12ee) == '\0') {
                pvVar10 = (void *)0xfffd;
                *(ushort *)(param_2 + 0x26) = *(ushort *)(param_2 + 0x26) & 0xfffd;
              }
              else {
                *(ushort *)(param_2 + 0x26) = *(ushort *)(param_2 + 0x26) | 2;
              }
              if (((*(char *)(lVar1 + 0x12f2) != '\0') ||
                  (pvVar10 = (void *)0x0, (*(byte *)(param_2 + 0x26) & 1) == 0)) ||
                 (pvVar10 = (void *)PostFwDiagBuffer(param_1,(int *)(lVar1 + 0x12e0),0,param_4),
                 (char)pvVar10 != '\0')) goto LAB_14000de24;
              goto LAB_14000db61;
            }
            break;
          }
          bVar11 = (char)uVar9 + 1;
          uVar9 = (ulonglong)bVar11;
        } while (bVar11 < 3);
        goto LAB_14000dab8;
      }
    }
    else {
      pvVar10 = (void *)(ulonglong)(iVar5 - 5U);
      if (iVar5 - 5U == 0) goto LAB_14000dc73;
    }
  }
LAB_14000da73:
  *(undefined4 *)(param_2 + 0x14) = 3;
LAB_14000dabf:
  return (ulonglong)pvVar10 & 0xffffffffffffff00;
LAB_14000dcdd:
  if (bVar11 != 0xff) {
    pvVar10 = (void *)(ulonglong)bVar11;
    lVar1 = (longlong)pvVar10 * 3 + 0x25c;
    lVar2 = param_1 + lVar1 * 8;
    if (*(char *)(param_1 + 0x12 + lVar1 * 8) == '\0') {
      if (iVar5 == 2) {
        *(undefined4 *)(lVar2 + 0x14) = 0;
        *(undefined4 *)(param_2 + 0x14) = 0;
        return 1;
      }
      *(undefined4 *)(param_2 + 0x14) = 0x14;
    }
    else {
      pvVar10 = (void *)ReleaseFwDiagBuffer(param_1,lVar2,param_4);
      if ((char)pvVar10 != '\0') {
LAB_14000de21:
        *param_3 = 0;
LAB_14000de24:
        return CONCAT71((int7)((ulonglong)pvVar10 >> 8),1);
      }
      *(undefined4 *)(param_2 + 0x14) = 0x12;
    }
    goto LAB_14000dabf;
  }
  goto LAB_14000dab8;
}



===== PostFwDiagBuffer @ 14000de30 =====

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
  puVar1 = *(undefined1 **)(param_1 + 0x548);
  *(undefined1 *)((longlong)param_2 + 0xe) = 0;
  if (*(ushort *)(param_1 + 0x240) != 0) {
    puVar4 = puVar1;
    for (uVar3 = (ulonglong)*(ushort *)(param_1 + 0x240); uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
  }
  puVar1[1] = (char)param_2[3];
  puVar1[3] = 0x1d;
  *puVar1 = *(undefined1 *)((longlong)param_2 + 0xd);
  *(int *)(puVar1 + 0x14) = param_2[2];
  memcpy(puVar1 + 0x24,(void *)(param_1 + 0x1328),0x28);
  *(undefined4 *)(puVar1 + 0x10) = *(undefined4 *)(param_1 + 0x1ec);
  *(int *)(puVar1 + 0xc) = *param_2 - *(int *)(param_1 + 0x100);
  uVar2 = QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x5aa) * 0x10000 + 8,0,param_4)
  ;
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== ProcessBusReset @ 14000df10 =====

ulonglong ProcessBusReset(longlong param_1,int param_2)

{
  char cVar1;
  ushort uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  ulonglong in_RAX;
  undefined8 uVar5;
  ushort uVar6;
  ulonglong uVar7;
  
  uVar2 = *(ushort *)(param_1 + 0x594);
  uVar6 = *(ushort *)(param_1 + 0x6a6);
  cVar1 = *(char *)(param_1 + 0xdb3);
  if (uVar6 <= uVar2) {
    do {
      uVar7 = (ulonglong)uVar6;
      uVar6 = uVar6 + 1;
      in_RAX = *(longlong *)(param_1 + 0x2a0) + uVar7 * 0x18;
      if (((*(longlong *)(*(longlong *)(param_1 + 0x2a0) + 8 + uVar7 * 0x18) != 0) &&
          (*(char *)(in_RAX + 0x13) == '\0')) && (*(char *)(in_RAX + 0x12) == cVar1)) {
        puVar4 = *(undefined8 **)(param_1 + 0x270);
        *(ushort *)(param_1 + 0x6a6) = uVar6;
        *puVar4 = 0;
        puVar4[1] = 0;
        puVar4[2] = 0;
        puVar4[3] = 0;
        puVar4[4] = 0;
        puVar4[5] = 0;
        *(undefined4 *)(puVar4 + 6) = 0;
        *(undefined2 *)puVar4 = *(undefined2 *)(in_RAX + 0x14);
        *(undefined1 *)((longlong)puVar4 + 3) = 1;
        *(undefined1 *)((longlong)puVar4 + 5) = 3;
        uVar5 = QueueRequestDescriptor
                          (param_1,(uint)*(ushort *)(param_1 + 0x5ae) * 0x10000 + 6,0,param_2);
        *(undefined4 *)(param_1 + 0x574) = 0xf;
        return CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
      }
    } while (uVar6 <= uVar2);
  }
  if (*(char *)(param_1 + 0xdf0) != '\0') {
    if (*(short *)(param_1 + 0x560) != 0) {
      in_RAX = StorPortLogError(param_1,0,0,0,0,6,0xad010017);
    }
    if ((*(char *)(param_1 + 0x12a) != '\0') && (uVar6 = 1, 1 < *(byte *)(param_1 + 299))) {
      do {
        LSImpiMSIIsr(param_1,(byte)uVar6);
        in_RAX = 0;
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(byte *)(param_1 + 299));
    }
    if (uVar2 != 0) {
      lVar3 = *(longlong *)(param_1 + 0x2a0);
      uVar7 = 1;
      do {
        in_RAX = uVar7;
        if (((*(longlong *)(lVar3 + 8 + in_RAX * 0x18) != 0) &&
            (*(char *)(lVar3 + 0x12 + in_RAX * 0x18) == cVar1)) &&
           (*(char *)(lVar3 + 0x13 + in_RAX * 0x18) == '\0')) {
          StorPortLogError(param_1,0,0,0,0,6,0xad010035);
          **(uint **)(param_1 + 0x50) = **(uint **)(param_1 + 0x50) | 0x40000009;
          LOCK();
          UNLOCK();
          if (*(int *)(param_1 + 0x570) == 0) {
            StorPortPause(param_1,400);
          }
          *(undefined4 *)(param_1 + 0xdf8) = 1;
          in_RAX = KickStart(param_1,param_2);
          break;
        }
        uVar6 = (short)in_RAX + 1;
        uVar7 = (ulonglong)uVar6;
      } while (uVar6 <= uVar2);
    }
    *(undefined1 *)(param_1 + 0xdf0) = 0;
  }
  lVar3 = *(longlong *)(param_1 + 0x530);
  if ((lVar3 != 0) &&
     (in_RAX = 0, *(char *)(*(longlong *)(lVar3 + 0x68) + 0x52) == *(char *)(param_1 + 0xdb3))) {
    *(undefined8 *)(param_1 + 0x530) = 0;
    *(undefined1 *)(lVar3 + 3) = 1;
    in_RAX = StorPortNotification(0,param_1);
  }
  return in_RAX & 0xffffffffffffff00;
}



===== ProcessParseArgumentString @ 14000e180 =====

ulonglong ProcessParseArgumentString(byte *param_1,byte *param_2,int *param_3)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  
  uVar8 = 0;
  uVar6 = 0;
  uVar7 = 0;
  bVar1 = *param_1;
  pbVar2 = param_1;
  while (bVar1 != 0) {
    pbVar2 = pbVar2 + 1;
    uVar6 = uVar6 + 1;
    bVar1 = *pbVar2;
  }
  pbVar2 = param_2;
  if (*param_2 != 0) {
    do {
      pbVar2 = pbVar2 + 1;
      uVar7 = uVar7 + 1;
    } while (*pbVar2 != 0);
    if (uVar6 < uVar7) {
LAB_14000e368:
      return (ulonglong)pbVar2 & 0xffffffffffffff00;
    }
  }
  while( true ) {
    while( true ) {
      while( true ) {
        for (; (*param_1 == 0x20 || (*param_1 == 9)); param_1 = param_1 + 1) {
        }
        pbVar2 = (byte *)0x0;
        if (*param_1 == 0) goto LAB_14000e368;
        pbVar3 = param_1;
        pbVar5 = param_2;
        if (*param_1 == *param_2) {
          do {
            pbVar2 = (byte *)0x0;
            param_1 = pbVar3 + 1;
            pbVar5 = pbVar5 + 1;
            if (*pbVar3 == 0) goto LAB_14000e368;
            pbVar3 = param_1;
          } while (*param_1 == *pbVar5);
        }
        if (*pbVar5 == 0) break;
        do {
          bVar1 = *param_1;
          pbVar2 = (byte *)0x0;
          if (bVar1 == 0) goto LAB_14000e368;
          param_1 = param_1 + 1;
        } while (bVar1 != 0x3b);
      }
      for (; (*param_1 == 0x20 || (*param_1 == 9)); param_1 = param_1 + 1) {
      }
      if (*param_1 == 0x3d) break;
      do {
        bVar1 = *param_1;
        pbVar2 = (byte *)0x0;
        if (bVar1 == 0) goto LAB_14000e368;
        param_1 = param_1 + 1;
      } while (bVar1 != 0x3b);
    }
    do {
      do {
        pbVar3 = param_1;
        bVar1 = pbVar3[1];
        pbVar2 = (byte *)0x0;
        param_1 = pbVar3 + 1;
      } while (bVar1 == 0x20);
    } while (bVar1 == 9);
    if (bVar1 == 0) goto LAB_14000e368;
    if (bVar1 != 0x3b) break;
    param_1 = pbVar3 + 2;
  }
  *param_3 = 0;
  bVar1 = *param_1;
  pbVar5 = pbVar2;
  if ((bVar1 == 0x30) && (pbVar3[2] == 0x78)) {
    pbVar3 = pbVar3 + 3;
    if (*pbVar3 != 0) {
      pbVar5 = pbVar3;
      while (((bVar1 = *pbVar5, bVar1 != 0x20 && (bVar1 != 9)) && (bVar1 != 0x3b))) {
        if ((byte)(bVar1 - 0x30) < 10) {
          iVar4 = *param_3 * 0x10 + -0x30;
        }
        else {
          pbVar2 = (byte *)(ulonglong)(bVar1 - 0x61);
          if (5 < (byte)(bVar1 - 0x61)) goto LAB_14000e368;
          iVar4 = *param_3 * 0x10 + -0x57;
        }
        uVar8 = (ulonglong)((int)uVar8 + 1);
        pbVar5 = pbVar3 + uVar8;
        *param_3 = iVar4 + (char)bVar1;
        if (*pbVar5 == 0) {
          return CONCAT71((int7)((ulonglong)pbVar5 >> 8),1);
        }
      }
    }
  }
  else {
    while ((bVar1 != 0 && (((bVar1 != 0x20 && (bVar1 != 9)) && (bVar1 != 0x3b))))) {
      pbVar2 = (byte *)(ulonglong)(bVar1 - 0x30);
      if (9 < (byte)(bVar1 - 0x30)) goto LAB_14000e368;
      pbVar5 = (byte *)(ulonglong)((int)pbVar5 + 1);
      *param_3 = (int)(char)bVar1 + (*param_3 * 5 + -0x18) * 2;
      bVar1 = pbVar5[(longlong)param_1];
    }
  }
  return CONCAT71((int7)((ulonglong)pbVar5 >> 8),1);
}



===== ProcessSsuReplies @ 14000e380 =====

undefined8 ProcessSsuReplies(longlong param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  
  do {
    cVar2 = PollLSImpiIsr(param_1,param_2);
    StorPortStallExecution(500);
  } while (cVar2 != '\0');
  if ((uint)*(ushort *)(param_1 + 0x3d4a) < *(uint *)(param_1 + 0x5b8)) {
    return 2;
  }
  if (*(int *)(param_1 + 0x3d40) == 0) {
    return 1;
  }
  piVar1 = (int *)(param_1 + 0x3d44);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 != 0) {
    return 0;
  }
  if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x80003) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x80003,
                (undefined1 *)(param_1 + 0x3d40),4,param_2);
  }
  return 3;
}



===== ProcessSsuTmrReplies @ 14000e470 =====

undefined8 ProcessSsuTmrReplies(longlong param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  ulonglong in_stack_ffffffffffffffd8;
  
  do {
    cVar2 = PollLSImpiIsr(param_1,param_2);
    StorPortStallExecution(500);
  } while (cVar2 != '\0');
  if (*(int *)(param_1 + 0x3d40) == 0) {
    return 1;
  }
  piVar1 = (int *)(param_1 + 0x3d44);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 != 0) {
    return 0;
  }
  StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffffd8 & 0xffffffffffffff00,6,0xad010071);
  if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x80005) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x80005,
                (undefined1 *)(param_1 + 0x3d40),4,param_2);
  }
  KickStart(param_1,param_2);
  return 2;
}



===== ProcessTmResetReply @ 14000e720 =====

void ProcessTmResetReply(longlong param_1,short *param_2,int param_3)

{
  char cVar1;
  char cVar2;
  short sVar3;
  longlong lVar4;
  longlong lVar5;
  bool bVar6;
  ulonglong uVar7;
  undefined1 uVar8;
  longlong lVar9;
  ushort uVar10;
  longlong *plVar11;
  undefined4 uVar12;
  
  lVar4 = *(longlong *)(param_1 + 0x528);
  bVar6 = false;
  sVar3 = *param_2;
  cVar1 = *(char *)((longlong)param_2 + 5);
  lVar5 = *(longlong *)(lVar4 + 0x68);
  cVar2 = *(char *)(lVar5 + 0x54);
  if (((*(int *)(lVar4 + 0x14) == 0x20) && (cVar1 != '\x05')) ||
     ((*(int *)(lVar4 + 0x14) == 0x13 && (cVar1 != '\x03')))) goto LAB_14000e9db;
  if ((*(char *)(param_1 + 0x12a) != '\0') && (uVar10 = 1, 1 < *(byte *)(param_1 + 299))) {
    do {
      LSImpiMSIIsr(param_1,(byte)uVar10);
      uVar10 = uVar10 + 1;
    } while (uVar10 < *(byte *)(param_1 + 299));
  }
  uVar10 = 1;
  if (*(ushort *)(param_1 + 0x594) != 0) {
    lVar9 = *(longlong *)(param_1 + 0x2a0);
    do {
      uVar7 = (ulonglong)uVar10;
      if (((*(longlong *)(lVar9 + 8 + uVar7 * 0x18) != 0) &&
          (*(short *)(lVar9 + 0x14 + uVar7 * 0x18) == sVar3)) &&
         ((cVar1 != '\x05' || (*(char *)(lVar9 + 0x16 + uVar7 * 0x18) == cVar2)))) {
        bVar6 = true;
        if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x2000d) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x2000d,
                      (undefined1 *)(lVar5 + 0x52),3,param_3);
        }
        break;
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 <= *(ushort *)(param_1 + 0x594));
  }
  if (*(longlong *)(lVar4 + 0x68) == 0) goto LAB_14000e9db;
  uVar8 = 1;
  if (bVar6) {
    uVar8 = 4;
  }
  *(undefined1 *)(lVar4 + 3) = uVar8;
  StorPortNotification(0,param_1,lVar4);
  if (cVar1 == '\x05') {
    if (bVar6) {
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x20010) != 0)) {
        uVar12 = 0x20010;
LAB_14000e937:
        RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),uVar12,
                    (undefined1 *)(lVar5 + 0x52),3,param_3);
      }
    }
    else if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x2000e) != 0))
    {
      uVar12 = 0x2000e;
      goto LAB_14000e937;
    }
  }
  else if (cVar1 == '\x03') {
    if (bVar6) {
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x20011) != 0)) {
        uVar12 = 0x20011;
        goto LAB_14000e937;
      }
    }
    else if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x2000f) != 0))
    {
      uVar12 = 0x2000f;
      goto LAB_14000e937;
    }
  }
  plVar11 = (longlong *)(param_1 + 0xfc0);
  lVar9 = 100;
  do {
    if (((*plVar11 == lVar4) && (*plVar11 = -1, *(char *)(param_1 + 0x308) != '\0')) &&
       ((*(uint *)(param_1 + 0x30c) & 0x2001e) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x2001e,
                  (undefined1 *)(lVar5 + 0x52),3,param_3);
    }
    plVar11 = plVar11 + 1;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
LAB_14000e9db:
  *(undefined8 *)(param_1 + 0x528) = 0;
  CheckResetQueue(param_1,param_3);
  return;
}



===== QueueRequestDescriptor @ 14000ea00 =====

void QueueRequestDescriptor(longlong param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  byte bVar1;
  char cVar2;
  ulonglong uVar3;
  char cVar4;
  
  if (*(char *)(param_1 + 0xdb9) != '\0') {
    **(undefined4 **)(param_1 + 0xe8) = param_2;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0xf0) = param_3;
    LOCK();
    UNLOCK();
    return;
  }
  bVar1 = *(byte *)(param_1 + 0xce8);
  uVar3 = (ulonglong)bVar1;
  if (*(int *)(param_1 + 0x6a8 + uVar3 * 4) == 0) {
    *(undefined4 *)(param_1 + 0x6a8 + uVar3 * 4) = param_2;
    *(undefined4 *)(param_1 + 0x9c8 + uVar3 * 4) = param_3;
    cVar2 = bVar1 + 1;
    cVar4 = '\0';
    if (cVar2 != -0x38) {
      cVar4 = cVar2;
    }
    *(uint *)(param_1 + 0x5bc) = *(uint *)(param_1 + 0x5bc) | 1;
    *(char *)(param_1 + 0xce8) = cVar4;
    if (*(char *)(param_1 + 0xdf1) == '\0') {
                    /* WARNING: Could not recover jumptable at 0x00014000eaa8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      StorPortNotification(6,param_1,WatchdogTimer,10000);
      return;
    }
  }
  else {
    StorPortLogError(param_1,0,0,0,0,6,0xad010039);
    *(undefined4 *)(param_1 + 0xdf8) = 1;
    if (*(int *)(param_1 + 0x570) == 0) {
      StorPortPause(param_1,300);
    }
    *(undefined2 *)(param_1 + 0xdf4) = 0;
    KickStart(param_1,param_4);
  }
  return;
}



===== ReadAndSetSASPages @ 14000eb20 =====

void ReadAndSetSASPages(longlong param_1,int param_2)

{
  uint *puVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  longlong lVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  char cVar9;
  ushort uVar10;
  undefined4 *puVar11;
  char cVar12;
  undefined8 *puVar13;
  ulonglong uVar14;
  uint uVar15;
  int iVar16;
  bool bVar17;
  char local_res8;
  short local_res18;
  uint local_res20 [2];
  ulonglong in_stack_ffffffffffffff98;
  uint local_48;
  uint local_44;
  undefined8 local_40;
  
  bVar7 = false;
  local_40 = 0;
  bVar8 = true;
  cVar9 = '\x01';
  do {
    bVar6 = true;
    bVar17 = bVar8;
    switch(cVar9) {
    case '\x01':
      cVar9 = '\x02';
      bVar6 = false;
      goto LAB_14000f579;
    case '\x02':
      local_res20[0] = 0x1010000;
      cVar9 = '\x03';
      if (local_res20 == (uint *)(param_1 + 0x1508)) {
        puVar13 = *(undefined8 **)(param_1 + 0x280);
        uVar10 = *(ushort *)(param_1 + 0x5b2);
      }
      else {
LAB_14000ebbf:
        puVar13 = *(undefined8 **)(param_1 + 0x268);
        uVar10 = *(ushort *)(param_1 + 0x5ac);
      }
      goto LAB_14000ebcd;
    case '\x03':
      cVar9 = '\x04';
      goto LAB_14000ec30;
    case '\x04':
      bVar2 = *(byte *)(*(longlong *)(param_1 + 0x1460) + 0xd);
      if (bVar2 == 0xff) {
        *(undefined2 *)(param_1 + 0x1550) = 0xffff;
      }
      else {
        *(ushort *)(param_1 + 0x1550) = (ushort)bVar2;
      }
      local_res20[0] = 0x1080000;
      cVar9 = '\x05';
      if (local_res20 != (uint *)(param_1 + 0x1508)) goto LAB_14000ebbf;
      puVar13 = *(undefined8 **)(param_1 + 0x280);
      uVar10 = *(ushort *)(param_1 + 0x5b2);
      goto LAB_14000ebcd;
    case '\x05':
      cVar9 = '\x06';
      goto LAB_14000ec30;
    case '\x06':
      lVar5 = *(longlong *)(param_1 + 0x1460);
      *(undefined1 *)(param_1 + 0x14b8) = *(undefined1 *)(lVar5 + 4);
      *(undefined2 *)(param_1 + 0x14be) = 8;
      *(undefined2 *)(param_1 + 0x14c0) = *(undefined2 *)(lVar5 + 0xc);
      *(undefined2 *)(param_1 + 0x14c4) = *(undefined2 *)(lVar5 + 0x10);
      if (*(short *)(param_1 + 0x14bc) == 0) {
        *(undefined2 *)(param_1 + 0x14bc) = *(undefined2 *)(lVar5 + 8);
      }
      if ((*(uint *)(param_1 + 0xdec) & 0x1000) != 0) {
        GetIrMapRange(param_1,(int *)&local_44,(int *)&local_48);
        uVar14 = (ulonglong)local_44;
        if (local_44 <= local_48) {
          puVar11 = (undefined4 *)(*(longlong *)(param_1 + 0x2c8) + uVar14 * 0x28 + 0x14);
          do {
            *puVar11 = 0x20000000;
            puVar11 = puVar11 + 10;
            uVar15 = (int)uVar14 + 1;
            uVar14 = (ulonglong)uVar15;
          } while (uVar15 <= local_48);
        }
      }
      *(undefined4 *)(param_1 + 0x14f0) = 0;
      *(uint *)(param_1 + 0x14f0) = (uint)((*(byte *)(lVar5 + 0xc) & 0x10) != 0);
      if ((*(byte *)(lVar5 + 0x10) & 3) == 0) {
        *(int *)(param_1 + 0x14f0) = *(int *)(param_1 + 0x14f0) + (uint)*(byte *)(param_1 + 0x59f);
      }
      if ((*(uint *)(param_1 + 0xdec) & 4) != 0) {
        local_res20[0] = 0x10000;
        cVar9 = '\a';
        if (local_res20 != (uint *)(param_1 + 0x1508)) goto LAB_14000ebbf;
        puVar13 = *(undefined8 **)(param_1 + 0x280);
        uVar10 = *(ushort *)(param_1 + 0x5b2);
        goto LAB_14000ebcd;
      }
      cVar9 = '\t';
      bVar6 = false;
      goto LAB_14000f579;
    case '\a':
      cVar9 = '\b';
      goto LAB_14000ec30;
    case '\b':
      cVar9 = '\t';
      local_res20[0] = *(uint *)(param_1 + 0x1468);
      if (*(char *)(param_1 + 0xdea) == '\0') {
        puVar1 = (uint *)(*(longlong *)(param_1 + 0x1460) + 4);
        *puVar1 = *puVar1 | 0x20;
      }
      else {
        puVar1 = (uint *)(*(longlong *)(param_1 + 0x1460) + 4);
        *puVar1 = *puVar1 & 0xffffffdf;
      }
      uVar4 = *(undefined8 *)(param_1 + 0x1460);
      if (local_res20 == (uint *)(param_1 + 0x1508)) {
        puVar13 = *(undefined8 **)(param_1 + 0x280);
        uVar10 = *(ushort *)(param_1 + 0x5b2);
      }
      else {
        puVar13 = *(undefined8 **)(param_1 + 0x268);
        uVar10 = *(ushort *)(param_1 + 0x5ac);
      }
      *puVar13 = 0;
      puVar13[1] = 0;
      puVar13[2] = 0;
      puVar13[3] = 0;
      puVar13[4] = 0;
      *(undefined4 *)(puVar13 + 5) = 0;
      *(undefined4 *)((longlong)puVar13 + 0x1c) = 0xd3000000;
      *(undefined1 *)puVar13 = 2;
      *(undefined1 *)((longlong)puVar13 + 3) = 4;
      *(uint *)((longlong)puVar13 + 0x14) = local_res20[0];
      *(undefined4 *)(puVar13 + 3) = 0;
      uVar15 = (local_res20[0] >> 8 & 0xff) << 2;
      *(int *)(puVar13 + 4) = (int)uVar4 - *(int *)(param_1 + 0x100);
      *(uint *)((longlong)puVar13 + 0x1c) = uVar15 | 0xd3000000;
      uVar3 = *(undefined4 *)(param_1 + 0x1ec);
      *(uint *)((longlong)puVar13 + 0x1c) = uVar15 | 0xd7000000;
      *(undefined4 *)((longlong)puVar13 + 0x24) = uVar3;
      goto LAB_14000ec14;
    case '\t':
      local_res20[0] = 0x2030000;
      cVar9 = '\n';
      if (local_res20 != (uint *)(param_1 + 0x1508)) goto LAB_14000ebbf;
      puVar13 = *(undefined8 **)(param_1 + 0x280);
      uVar10 = *(ushort *)(param_1 + 0x5b2);
      goto LAB_14000ebcd;
    case '\n':
      cVar9 = '\v';
LAB_14000ec30:
      local_res20[0] = *(uint *)(param_1 + 0x1468);
      iVar16 = (int)*(undefined8 *)(param_1 + 0x1460);
      if (local_res20 == (uint *)(param_1 + 0x1508)) {
        puVar13 = *(undefined8 **)(param_1 + 0x280);
        uVar10 = *(ushort *)(param_1 + 0x5b2);
      }
      else {
        puVar13 = *(undefined8 **)(param_1 + 0x268);
        uVar10 = *(ushort *)(param_1 + 0x5ac);
      }
      *puVar13 = 0;
      puVar13[1] = 0;
      puVar13[2] = 0;
      puVar13[3] = 0;
      puVar13[4] = 0;
      *(undefined4 *)(puVar13 + 5) = 0;
      *(undefined1 *)puVar13 = 1;
LAB_14000ec88:
      *(undefined1 *)((longlong)puVar13 + 3) = 4;
      *(uint *)((longlong)puVar13 + 0x14) = local_res20[0];
      *(undefined4 *)(puVar13 + 3) = 0;
      *(undefined4 *)((longlong)puVar13 + 0x1c) = 0xd3000000;
      *(int *)(puVar13 + 4) = iVar16 - *(int *)(param_1 + 0x100);
      *(uint *)((longlong)puVar13 + 0x1c) = (local_res20[0] >> 8 & 0xff) << 2 | 0xd3000000;
      goto LAB_14000ec08;
    case '\v':
      cVar9 = '\f';
      local_res20[0] = 0x9000000;
      *(undefined4 *)(param_1 + 0xd5c) = *(undefined4 *)(*(longlong *)(param_1 + 0x1460) + 8);
      if (local_res20 != (uint *)(param_1 + 0x1508)) goto LAB_14000ebbf;
      puVar13 = *(undefined8 **)(param_1 + 0x280);
      uVar10 = *(ushort *)(param_1 + 0x5b2);
      goto LAB_14000ebcd;
    case '\f':
      local_res20[0] = *(uint *)(param_1 + 0x1468);
      if (*(longlong *)(param_1 + 0x1500) == 0) {
        uVar10 = ((ushort)(local_res20[0] >> 8) & 0xff) << 2;
        if (*(uint *)(param_1 + 0x145c) < (uint)uVar10) {
          bVar7 = true;
          goto LAB_14000f579;
        }
        *(longlong *)(param_1 + 0x1500) = *(longlong *)(param_1 + 0x1460);
        *(ulonglong *)(param_1 + 0x1460) = (ulonglong)uVar10 + *(longlong *)(param_1 + 0x1460);
        *(uint *)(param_1 + 0x145c) = *(uint *)(param_1 + 0x145c) - (uint)uVar10;
      }
      iVar16 = (int)*(undefined8 *)(param_1 + 0x1500);
      cVar9 = '\r';
      if (local_res20 == (uint *)(param_1 + 0x1508)) {
        puVar13 = *(undefined8 **)(param_1 + 0x280);
        uVar10 = *(ushort *)(param_1 + 0x5b2);
      }
      else {
LAB_14000efee:
        puVar13 = *(undefined8 **)(param_1 + 0x268);
        uVar10 = *(ushort *)(param_1 + 0x5ac);
      }
      goto LAB_14000effc;
    case '\r':
      if (*(short *)(param_1 + 0x145a) != 0x23) {
        memcpy((void *)(param_1 + 0x1564),(void *)(*(longlong *)(param_1 + 0x1500) + 0x3c),0x10);
      }
      local_res20[0] = 0x9050000;
      cVar9 = '\x0e';
      if (local_res20 != (uint *)(param_1 + 0x1508)) goto LAB_14000ebbf;
      puVar13 = *(undefined8 **)(param_1 + 0x280);
      uVar10 = *(ushort *)(param_1 + 0x5b2);
      goto LAB_14000ebcd;
    case '\x0e':
      local_res20[0] = *(uint *)(param_1 + 0x1468);
      iVar16 = (int)*(undefined8 *)(param_1 + 0x1460);
      cVar9 = '\x0f';
      if (local_res20 != (uint *)(param_1 + 0x1508)) goto LAB_14000efee;
      puVar13 = *(undefined8 **)(param_1 + 0x280);
      uVar10 = *(ushort *)(param_1 + 0x5b2);
LAB_14000effc:
      *puVar13 = 0;
      puVar13[1] = 0;
      puVar13[2] = 0;
      puVar13[3] = 0;
      puVar13[4] = 0;
      *(undefined4 *)(puVar13 + 5) = 0;
      *(undefined1 *)puVar13 = 6;
      goto LAB_14000ec88;
    case '\x0f':
      cVar9 = '\x12';
      bVar6 = false;
      *(undefined4 *)(param_1 + 0x1474) = *(undefined4 *)(*(longlong *)(param_1 + 0x1460) + 0x10);
      *(undefined4 *)(param_1 + 0x1478) = *(undefined4 *)(*(longlong *)(param_1 + 0x1460) + 0x14);
      goto LAB_14000f579;
    default:
      cVar9 = '\0';
      bVar17 = false;
      goto LAB_14000f579;
    case '\x12':
      cVar9 = '\x13';
      if ((*(uint *)(param_1 + 0xdec) & 0x1000) == 0) goto LAB_14000f17e;
      local_res20[0] = 0x8010000;
      if (local_res20 != (uint *)(param_1 + 0x1508)) goto LAB_14000ebbf;
      puVar13 = *(undefined8 **)(param_1 + 0x280);
      uVar10 = *(ushort *)(param_1 + 0x5b2);
LAB_14000ebcd:
      *puVar13 = 0;
      puVar13[1] = 0;
      puVar13[2] = 0;
      puVar13[3] = 0;
      puVar13[4] = 0;
      *(undefined4 *)(puVar13 + 5) = 0;
      *(undefined1 *)puVar13 = 0;
      *(undefined1 *)((longlong)puVar13 + 3) = 4;
      *(uint *)((longlong)puVar13 + 0x14) = local_res20[0];
      *(undefined4 *)(puVar13 + 3) = 0;
      *(undefined4 *)((longlong)puVar13 + 0x1c) = 0xd3000000;
      *(int *)(puVar13 + 4) = *(int *)(param_1 + 0x1fc) + 0x2c;
LAB_14000ec08:
      *(undefined4 *)((longlong)puVar13 + 0x24) = *(undefined4 *)(param_1 + 0x1ec);
LAB_14000ec14:
      QueueRequestDescriptor(param_1,(uint)uVar10 * 0x10000 + 8,0,param_2);
      goto LAB_14000f579;
    case '\x13':
      if ((*(uint *)(param_1 + 0xdec) & 0x1000) != 0) {
        local_res20[0] = *(uint *)(param_1 + 0x1468);
        *(uint *)(param_1 + 0x1508) = local_res20[0];
        if (*(longlong *)(param_1 + 0x1510) == 0) {
          uVar10 = ((ushort)(local_res20[0] >> 8) & 0xff) << 2;
          if (*(uint *)(param_1 + 0x145c) < (uint)uVar10) {
            bVar7 = true;
            goto LAB_14000f579;
          }
          *(longlong *)(param_1 + 0x1510) = *(longlong *)(param_1 + 0x1460);
          *(ulonglong *)(param_1 + 0x1460) = (ulonglong)uVar10 + *(longlong *)(param_1 + 0x1460);
          *(uint *)(param_1 + 0x145c) = *(uint *)(param_1 + 0x145c) - (uint)uVar10;
        }
      }
LAB_14000f17e:
      cVar9 = '\x14';
      local_40._0_6_ = CONCAT42(0xf00,(undefined2)local_40);
      goto LAB_14000f188;
    case '\x14':
      if (*(longlong *)(param_1 + 0x15c0) == 0) {
        uVar10 = *(short *)(param_1 + 0x1598) << 2;
        if (*(uint *)(param_1 + 0x145c) < (uint)uVar10) {
          bVar7 = true;
          goto LAB_14000f579;
        }
        *(longlong *)(param_1 + 0x15c0) = *(longlong *)(param_1 + 0x1460);
        *(ulonglong *)(param_1 + 0x1460) = (ulonglong)uVar10 + *(longlong *)(param_1 + 0x1460);
        *(uint *)(param_1 + 0x145c) = *(uint *)(param_1 + 0x145c) - (uint)uVar10;
      }
      cVar9 = '\x15';
      local_40._0_6_ = CONCAT42(0xf01,(undefined2)local_40);
LAB_14000f188:
      local_40._0_7_ = CONCAT16(0x10,(undefined6)local_40);
      break;
    case '\x15':
      if (*(longlong *)(param_1 + 0x15c8) == 0) {
        uVar10 = *(short *)(param_1 + 0x15a0) << 2;
        if (*(uint *)(param_1 + 0x145c) < (uint)uVar10) {
          bVar7 = true;
          goto LAB_14000f579;
        }
        *(longlong *)(param_1 + 0x15c8) = *(longlong *)(param_1 + 0x1460);
        *(ulonglong *)(param_1 + 0x1460) = (ulonglong)uVar10 + *(longlong *)(param_1 + 0x1460);
        *(uint *)(param_1 + 0x145c) = *(uint *)(param_1 + 0x145c) - (uint)uVar10;
      }
      cVar9 = '\x16';
      local_40._0_6_ = CONCAT42(0xf00,(undefined2)local_40);
      local_40._0_7_ = CONCAT16(0x12,(undefined6)local_40);
      break;
    case '\x16':
      uVar10 = *(short *)(param_1 + 0x1534) << 2;
      if (*(longlong *)(param_1 + 0x1538) == 0) {
        if (*(uint *)(param_1 + 0x145c) < (uint)uVar10) {
          bVar7 = true;
          goto LAB_14000f579;
        }
        lVar5 = *(longlong *)(param_1 + 0x1460);
        uVar15 = *(uint *)(param_1 + 0x145c) - (uint)uVar10;
        *(longlong *)(param_1 + 0x1538) = lVar5;
        *(ulonglong *)(param_1 + 0x1460) = (ulonglong)uVar10 + lVar5;
        *(uint *)(param_1 + 0x145c) = uVar15;
        if (lVar5 == 0) {
          if (uVar15 < uVar10) {
            bVar7 = true;
            goto LAB_14000f579;
          }
          *(longlong *)(param_1 + 0x1538) = *(longlong *)(param_1 + 0x1460);
          *(ulonglong *)(param_1 + 0x1460) = (ulonglong)uVar10 + *(longlong *)(param_1 + 0x1460);
          *(uint *)(param_1 + 0x145c) = uVar15 - uVar10;
        }
      }
      cVar9 = '\x17';
      local_40._0_6_ = CONCAT42(0xf01,(undefined2)local_40);
      local_40._0_7_ = CONCAT16(0x12,(undefined6)local_40);
      break;
    case '\x17':
      if (*(longlong *)(param_1 + 0x15d0) == 0) {
        uVar10 = *(short *)(param_1 + 0x15a8) << 2;
        if (*(uint *)(param_1 + 0x145c) < (uint)uVar10) {
          bVar7 = true;
          goto LAB_14000f579;
        }
        *(longlong *)(param_1 + 0x15d0) = *(longlong *)(param_1 + 0x1460);
        *(ulonglong *)(param_1 + 0x1460) = (ulonglong)uVar10 + *(longlong *)(param_1 + 0x1460);
        *(uint *)(param_1 + 0x145c) = *(uint *)(param_1 + 0x145c) - (uint)uVar10;
      }
      cVar9 = '\x18';
      local_40._0_6_ = CONCAT42(0xf00,(undefined2)local_40);
      local_40._0_7_ = CONCAT16(0x13,(undefined6)local_40);
      break;
    case '\x18':
      if (*(longlong *)(param_1 + 0x15d8) == 0) {
        uVar10 = *(short *)(param_1 + 0x15b0) << 2;
        if (*(uint *)(param_1 + 0x145c) < (uint)uVar10) {
          bVar7 = true;
          goto LAB_14000f579;
        }
        *(longlong *)(param_1 + 0x15d8) = *(longlong *)(param_1 + 0x1460);
        *(ulonglong *)(param_1 + 0x1460) = (ulonglong)uVar10 + *(longlong *)(param_1 + 0x1460);
        *(uint *)(param_1 + 0x145c) = *(uint *)(param_1 + 0x145c) - (uint)uVar10;
      }
      cVar9 = '\x19';
      local_40._0_6_ = CONCAT42(0xf01,(undefined2)local_40);
      local_40._0_7_ = CONCAT16(0x13,(undefined6)local_40);
      break;
    case '\x19':
      if (*(longlong *)(param_1 + 0x15e0) == 0) {
        uVar10 = *(short *)(param_1 + 0x15b8) << 2;
        if (*(uint *)(param_1 + 0x145c) < (uint)uVar10) {
          bVar7 = true;
          goto LAB_14000f579;
        }
        *(longlong *)(param_1 + 0x15e0) = *(longlong *)(param_1 + 0x1460);
        *(ulonglong *)(param_1 + 0x1460) = (ulonglong)uVar10 + *(longlong *)(param_1 + 0x1460);
        *(uint *)(param_1 + 0x145c) = *(uint *)(param_1 + 0x145c) - (uint)uVar10;
      }
      cVar9 = ' ';
      local_40._0_6_ = CONCAT42(0xf00,(undefined2)local_40);
      local_40._0_7_ = CONCAT16(0x15,(undefined6)local_40);
      break;
    case ' ':
      if (*(longlong *)(param_1 + 0x1548) == 0) {
        uVar10 = *(short *)(param_1 + 0x1544) << 2;
        if (*(uint *)(param_1 + 0x145c) < (uint)uVar10) {
          bVar7 = true;
          goto LAB_14000f579;
        }
        *(longlong *)(param_1 + 0x1548) = *(longlong *)(param_1 + 0x1460);
        *(ulonglong *)(param_1 + 0x1460) = (ulonglong)uVar10 + *(longlong *)(param_1 + 0x1460);
        *(uint *)(param_1 + 0x145c) = *(uint *)(param_1 + 0x145c) - (uint)uVar10;
      }
      cVar9 = -0x10;
      local_res8 = '\0';
      local_40._0_6_ = CONCAT42(0xf00,(undefined2)local_40);
      local_40._0_7_ = CONCAT16(0x17,(undefined6)local_40);
      break;
    case -0x10:
      if (local_res8 == '\0') {
        local_res18 = *(short *)(param_1 + 0x151c);
      }
      *(ushort *)(param_1 + 0x151c) = (ushort)(*(short *)(param_1 + 0x14bc) * 0x14 + 8U) >> 2;
      *(undefined1 *)(param_1 + 0x5b6) = 0;
      if (local_res8 == '\0') {
LAB_14000f551:
        in_stack_ffffffffffffff98 = *(ulonglong *)(param_1 + 0x1520);
        local_res8 = local_res8 + '\x01';
        SendExtendedConfigPageMessage
                  (param_1,'\x06',(char *)(param_1 + 0x1518),
                   (uint)*(ushort *)(param_1 + 0x14bc) << 0x10,(int)in_stack_ffffffffffffff98,
                   param_2);
      }
      else if (*(short *)(param_1 + 0x145a) == 0) {
        cVar9 = -0xf;
        *(short *)(param_1 + 0x151c) = local_res18 + 5;
        bVar6 = false;
      }
      else {
        if (local_res8 != '\x02') goto LAB_14000f551;
        *(ushort *)(param_1 + 0x14c0) = *(ushort *)(param_1 + 0x14c0) | 1;
        in_stack_ffffffffffffff98 = in_stack_ffffffffffffff98 & 0xffffffffffffff00;
        StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffff98,6,0xad010050);
        bVar6 = false;
        cVar9 = -0xf;
      }
      goto LAB_14000f579;
    }
    in_stack_ffffffffffffff98 = 0;
    local_40 = local_40 & 0xffffffffffffff00;
    SendExtendedConfigPageMessage(param_1,'\0',(char *)&local_40,0,0,param_2);
LAB_14000f579:
    bVar8 = false;
    if (!bVar7) {
      bVar8 = bVar17;
    }
    cVar12 = '\0';
    if (!bVar7) {
      cVar12 = cVar9;
    }
    *(char *)(param_1 + 0xdfd) = cVar12;
    bVar17 = !bVar8;
    if (!bVar17) {
      if (bVar6) {
        uVar15 = 0;
        do {
          cVar9 = PollLSImpiIsr(param_1,param_2);
          if (cVar9 != '\0') break;
          StorPortStallExecution(500);
          uVar15 = uVar15 + 1;
        } while (uVar15 < 20000);
        if ((uVar15 == 20000) || (cVar12 == '\0')) {
          bVar8 = false;
        }
      }
      bVar17 = !bVar8;
    }
    cVar9 = cVar12;
    if (bVar17) {
      return;
    }
  } while( true );
}



===== ReceiveDataViaHandshake @ 14000f780 =====

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
  if (*(char *)(param_1 + 0x5c3) == '\x06') {
    uVar5 = *(uint *)(param_1 + 0x558);
  }
  uVar6 = 0;
  puVar7 = (undefined2 *)(param_1 + 0x660);
  do {
    if (bVar2) break;
    uVar4 = 0;
    if (uVar5 != 0) {
      do {
        if (**(uint **)(param_1 + 0x48) == 0xffffffff) break;
        if ((**(uint **)(param_1 + 0x48) & 1) != 0) goto LAB_14000f7f4;
        StorPortStallExecution(500);
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar5);
    }
    bVar2 = true;
LAB_14000f7f4:
    *puVar7 = (short)**(undefined4 **)(param_1 + 0x18);
    **(undefined4 **)(param_1 + 0x48) = 0;
    LOCK();
    UNLOCK();
    uVar6 = uVar6 + 1;
    puVar7 = puVar7 + 1;
  } while (uVar6 < 2);
  uVar6 = 2;
  uVar5 = (uint)(byte)*(undefined2 *)(param_1 + 0x662) * 2;
  if (2 < uVar5) {
    puVar7 = (undefined2 *)(param_1 + 0x664);
    do {
      if (bVar2) break;
      uVar4 = 0;
      do {
        if (**(uint **)(param_1 + 0x48) == 0xffffffff) break;
        if ((**(uint **)(param_1 + 0x48) & 1) != 0) goto LAB_14000f868;
        StorPortStallExecution(500);
        uVar4 = uVar4 + 1;
      } while (uVar4 < 60000);
      bVar2 = true;
LAB_14000f868:
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
    if ((**(uint **)(param_1 + 0x48) & 1) != 0) goto LAB_14000f8ba;
    StorPortStallExecution(500);
    uVar5 = uVar5 + 1;
  } while (uVar5 < 60000);
  bVar2 = true;
LAB_14000f8ba:
  **(undefined4 **)(param_1 + 0x48) = 0;
  LOCK();
  UNLOCK();
  uVar3 = 0;
  if (uVar6 >> 1 == (uint)*(byte *)(param_1 + 0x662)) {
    uVar1 = *(ushort *)(param_1 + 0x66e);
    uVar3 = (ulonglong)uVar1;
    if (((uVar1 & 0x7fff) == 0) && (!bVar2)) {
      return CONCAT71((uint7)(byte)(uVar1 >> 8),1);
    }
  }
  return uVar3 & 0xffffffffffffff00;
}



===== ReleaseFwDiagBuffer @ 14000f910 =====

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
  puVar1 = *(undefined1 **)(param_1 + 0x548);
  if (*(ushort *)(param_1 + 0x240) != 0) {
    puVar4 = puVar1;
    for (uVar3 = (ulonglong)*(ushort *)(param_1 + 0x240); uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
  }
  puVar1[1] = *(undefined1 *)(param_2 + 0xc);
  puVar1[3] = 0x1e;
  uVar2 = QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x5aa) * 0x10000 + 8,0,param_3)
  ;
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== ResetActive @ 14000f980 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ResetActive(longlong param_1,uint param_2,int param_3)

{
  undefined1 auStackY_68 [32];
  undefined4 local_28;
  uint local_24;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = *(undefined4 *)(param_1 + 0x568);
  local_20 = 0;
  if ((param_2 >> 0x1e & 1) == 0) {
    *(uint *)(param_1 + 0x568) = param_2;
  }
  else if ((((*(longlong *)(param_1 + 0x528) == 0) && (*(char *)(param_1 + 0x14f8) == '\0')) &&
           (*(char *)(param_1 + 0xdf0) == '\0')) && (*(int *)(param_1 + 0xe74) == 0)) {
    *(undefined4 *)(param_1 + 0x568) = 0;
    local_20 = 0xffffffff;
  }
  if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x20020) != 0)) {
    local_24 = param_2;
    RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x20020,
                (undefined1 *)&local_28,0xc,param_3);
  }
  return;
}



===== ResumeDevice @ 14000fa40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void ResumeDevice(longlong param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                 undefined2 param_5,undefined4 param_6,undefined4 param_7,int param_8)

{
  char cVar1;
  longlong lVar2;
  undefined1 auStackY_98 [32];
  undefined4 local_58;
  undefined4 local_54;
  undefined2 local_50;
  undefined2 local_4e;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_4a;
  undefined1 local_49;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = param_6;
  local_54 = param_7;
  local_50 = 0;
  local_4e = param_5;
  local_4c = param_2;
  local_4b = param_3;
  local_4a = param_4;
  lVar2 = StorPortGetLogicalUnit();
  if (lVar2 == 0) {
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x232) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x232,
                  (undefined1 *)&local_58,0x10,param_8);
    }
  }
  else {
    cVar1 = *(char *)(lVar2 + 0x40);
    while (cVar1 != '\0') {
      *(char *)(lVar2 + 0x40) = *(char *)(lVar2 + 0x40) + -1;
      local_49 = *(undefined1 *)(lVar2 + 0x40);
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x112) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x112,
                    (undefined1 *)&local_58,0x10,param_8);
      }
      StorPortResumeDevice(param_1,param_2,param_3,param_4);
      cVar1 = *(char *)(lVar2 + 0x40);
    }
  }
  return;
}



===== RetrieveHostDriverData @ 14000fbb0 =====

undefined8 RetrieveHostDriverData(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_2 + 0x40);
  memcpy((void *)(lVar2 + 0x20),&AdapPageVersion,4);
  iVar1 = *(int *)(lVar2 + 0x1c);
  if (iVar1 == 1) {
    lVar2 = *(longlong *)(param_2 + 0x40);
    if (0x57 < *(uint *)(lVar2 + 0x18)) {
      memcpy((void *)(lVar2 + 0x24),(void *)(param_1 + 0xd3c),0x50);
      *(undefined4 *)(lVar2 + 0x3c) = 0;
      *(undefined1 *)(param_1 + 0xd80) = 0;
      return 0x74;
    }
  }
  else if (iVar1 == 3) {
    if (0x113 < *(uint *)(*(longlong *)(param_2 + 0x40) + 0x18)) {
      memcpy((void *)(*(longlong *)(param_2 + 0x40) + 0x30),(void *)(param_1 + 0x1358),0x100);
      return 0x130;
    }
  }
  else if (iVar1 == 10) {
    if (0x1b < *(uint *)(lVar2 + 0x18)) {
      *(undefined4 *)(lVar2 + 0x24) = 0x32;
      memcpy((void *)(lVar2 + 0x28),(void *)(param_1 + 0xd90),0x10);
      return 0x38;
    }
  }
  else if (iVar1 == 0xb) {
    if (0x17 < *(uint *)(lVar2 + 0x18)) {
      memcpy((void *)(param_1 + 0xd90),(void *)(lVar2 + 0x24),0x10);
      return 0x34;
    }
  }
  else if ((iVar1 == 0xc) && (0x2717 < *(uint *)(lVar2 + 0x18))) {
    memcpy((void *)(lVar2 + 0x24),(void *)(param_1 + 0x1630),10000);
    return 0x2734;
  }
  return 0;
}



===== SasBcAsyncEvent @ 14000fd50 =====

void SasBcAsyncEvent(longlong param_1,int param_2)

{
  char cVar1;
  undefined1 uVar2;
  short sVar3;
  undefined2 uVar4;
  short *psVar5;
  longlong lVar6;
  undefined8 *puVar7;
  longlong lVar8;
  uint uVar9;
  ulonglong uVar10;
  ushort uVar11;
  
  if (*(char *)(param_1 + 0x14f8) == '\0') {
    *(undefined1 *)(param_1 + 0x14fc) = 0;
    return;
  }
LAB_14000fda0:
  do {
    switch(*(undefined1 *)(param_1 + 0x14fc)) {
    case 1:
      *(undefined2 *)(param_1 + 0x14f4) = 1;
      *(undefined1 *)(param_1 + 0x14fc) = 5;
      break;
    default:
      goto switchD_14000fdbf_caseD_2;
    case 4:
      *(short *)(param_1 + 0x14f4) = *(short *)(param_1 + 0x14f4) + 1;
      if (*(ushort *)(param_1 + 0x594) < *(ushort *)(param_1 + 0x14f4)) {
        *(undefined1 *)(param_1 + 0x14fc) = 9;
        break;
      }
    case 5:
      *(undefined1 *)(param_1 + 0x14fc) = 4;
      lVar8 = *(longlong *)(param_1 + 0x2a0) + (ulonglong)*(ushort *)(param_1 + 0x14f4) * 0x18;
      if (*(longlong *)
           (*(longlong *)(param_1 + 0x2a0) + 8 + (ulonglong)*(ushort *)(param_1 + 0x14f4) * 0x18) !=
          0) {
        sVar3 = *(short *)(lVar8 + 0x14);
        uVar2 = *(undefined1 *)(lVar8 + 0x16);
        uVar9 = GetMapTableIndexFromHandle(param_1,sVar3);
        if ((uVar9 != 0xffffffff) &&
           ((*(uint *)(*(longlong *)(param_1 + 0x2c8) + 0x14 + (ulonglong)uVar9 * 0x28) >> 10 & 1)
            != 0)) {
          *(undefined1 *)(param_1 + 0x14fc) = 6;
          psVar5 = *(short **)(param_1 + 0x548);
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
          psVar5[0x18] = *(short *)(lVar8 + 0x10);
          goto LAB_14000ff74;
        }
      }
      break;
    case 6:
      *(undefined1 *)(param_1 + 0x14fc) = 4;
      lVar8 = *(longlong *)(param_1 + 0x2a0) + (ulonglong)*(ushort *)(param_1 + 0x14f4) * 0x18;
      if (*(longlong *)
           (*(longlong *)(param_1 + 0x2a0) + 8 + (ulonglong)*(ushort *)(param_1 + 0x14f4) * 0x18) !=
          0) {
        lVar6 = *(longlong *)(param_1 + 0x540);
        if (*(short *)(lVar6 + 0xe) == 0) goto code_r0x00014000fed0;
        goto LAB_14000fef1;
      }
      break;
    case 7:
      *(undefined1 *)(param_1 + 0x14fc) = 4;
      *(undefined1 *)(param_1 + 0x14fa) = 0;
      *(undefined1 *)(param_1 + 0x1574) = 0;
      if (*(short *)(*(longlong *)(param_1 + 0x540) + 0xe) != 0) {
        StorPortLogError(param_1,0,0,0,0,6,0xad010037);
      }
      if ((*(char *)(param_1 + 0x12a) != '\0') && (uVar11 = 1, 1 < *(byte *)(param_1 + 299))) {
        do {
          LSImpiMSIIsr(param_1,(byte)uVar11);
          uVar11 = uVar11 + 1;
        } while (uVar11 < *(byte *)(param_1 + 299));
      }
      uVar10 = 1;
      if (*(ushort *)(param_1 + 0x594) != 0) {
        lVar8 = *(longlong *)(param_1 + 0x2a0);
        do {
          if (((*(longlong *)(lVar8 + 8 + uVar10 * 0x18) != 0) &&
              (*(short *)(param_1 + 0x14f6) == *(short *)(lVar8 + 0x14 + uVar10 * 0x18))) &&
             (*(char *)(param_1 + 0x14fb) == *(char *)(lVar8 + 0x16 + uVar10 * 0x18))) {
            StorPortLogError(param_1,0,0,0,0,6,0xad010035);
            *(undefined1 *)(param_1 + 0x14fc) = 8;
            *(undefined4 *)(param_1 + 0xdf8) = 1;
            KickStart(param_1,param_2);
            return;
          }
          uVar11 = (short)uVar10 + 1;
          uVar10 = (ulonglong)uVar11;
        } while (uVar11 <= *(ushort *)(param_1 + 0x594));
      }
      break;
    case 9:
      if (*(char *)(param_1 + 0x14f9) == '\0') {
        *(undefined1 *)(param_1 + 0x14f8) = 0;
        *(undefined1 *)(param_1 + 0x14fc) = 0;
        StorPortResume(param_1);
        ResetActive(param_1,0x40000007,param_2);
        CheckResetQueue(param_1,param_2);
        return;
      }
      *(undefined1 *)(param_1 + 0x14f9) = 0;
      *(undefined1 *)(param_1 + 0x14fc) = 1;
    }
  } while( true );
code_r0x00014000fed0:
  cVar1 = *(char *)(lVar6 + 4);
  if ((cVar1 != -0x80) && (cVar1 != '\b')) {
    if ((*(short *)(lVar6 + 0xe) != 0) || (cVar1 != '\0')) {
LAB_14000fef1:
      StorPortLogError(param_1,0,0,0,0,6,0xad010037);
    }
    *(undefined1 *)(param_1 + 0x14fc) = 7;
    uVar4 = *(undefined2 *)(lVar8 + 0x14);
    puVar7 = *(undefined8 **)(param_1 + 0x548);
    *(undefined2 *)(param_1 + 0x14f6) = uVar4;
    uVar2 = *(undefined1 *)(lVar8 + 0x16);
    *(undefined1 *)(param_1 + 0x14fb) = uVar2;
    *puVar7 = 0;
    puVar7[1] = 0;
    puVar7[2] = 0;
    puVar7[3] = 0;
    puVar7[4] = 0;
    puVar7[5] = 0;
    *(undefined4 *)(puVar7 + 6) = 0;
    *(undefined2 *)puVar7 = uVar4;
    *(undefined1 *)((longlong)puVar7 + 3) = 1;
    *(undefined1 *)((longlong)puVar7 + 5) = 2;
    *(undefined1 *)((longlong)puVar7 + 0xd) = uVar2;
    *(undefined1 *)(param_1 + 0x14fa) = 1;
    *(undefined1 *)(param_1 + 0x1574) = 2;
LAB_14000ff74:
    QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x5aa) * 0x10000 + 6,0,param_2);
switchD_14000fdbf_caseD_2:
    return;
  }
  goto LAB_14000fda0;
}



===== SendAndProcessSSUCommands @ 140010140 =====

void SendAndProcessSSUCommands(longlong param_1,int param_2)

{
  int iVar1;
  undefined8 uVar2;
  byte bVar3;
  undefined1 *in_stack_ffffffffffffffd8;
  
  bVar3 = 8;
  do {
    if (bVar3 == 8) {
      *(undefined4 *)(param_1 + 0x3d40) = 0;
      bVar3 = 9;
      *(undefined2 *)(param_1 + 0x3d4a) = 0;
LAB_140010276:
      *(undefined4 *)(param_1 + 0x3d44) = 20000;
    }
    else if (bVar3 == 9) {
      SendSsuMessagesToDevices(param_1);
      bVar3 = -(*(int *)(param_1 + 0x3d40) != 0) & 10;
    }
    else if (bVar3 == 10) {
      uVar2 = ProcessSsuReplies(param_1,param_2);
      iVar1 = (int)uVar2;
      if (iVar1 == 1) {
        if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x80002) != 0)) {
          in_stack_ffffffffffffffd8 = (undefined1 *)(param_1 + 0x3d40);
          RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x80002,
                      in_stack_ffffffffffffffd8,4,param_2);
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
        goto LAB_140010276;
      }
      if (bVar3 == 0xc) {
        uVar2 = ProcessSsuTmrReplies(param_1,param_2);
        if ((int)uVar2 - 1U < 2) {
          bVar3 = 0;
        }
      }
      else {
        in_stack_ffffffffffffffd8 =
             (undefined1 *)((ulonglong)in_stack_ffffffffffffffd8 & 0xffffffffffffff00);
        StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffffd8,6,0xad010072);
      }
    }
    StorPortStallExecution(500);
    if (bVar3 == 0) {
      return;
    }
  } while( true );
}



===== SendConfigPageMessage @ 1400102b0 =====

void SendConfigPageMessage
               (longlong param_1,char param_2,undefined4 *param_3,undefined4 param_4,int param_5,
               int param_6)

{
  char *pcVar1;
  ushort uVar2;
  
  if (param_3 == (undefined4 *)(param_1 + 0x1508)) {
    pcVar1 = *(char **)(param_1 + 0x280);
    uVar2 = *(ushort *)(param_1 + 0x5b2);
  }
  else {
    pcVar1 = *(char **)(param_1 + 0x268);
    uVar2 = *(ushort *)(param_1 + 0x5ac);
  }
  pcVar1[0] = '\0';
  pcVar1[1] = '\0';
  pcVar1[2] = '\0';
  pcVar1[3] = '\0';
  pcVar1[4] = '\0';
  pcVar1[5] = '\0';
  pcVar1[6] = '\0';
  pcVar1[7] = '\0';
  pcVar1[8] = '\0';
  pcVar1[9] = '\0';
  pcVar1[10] = '\0';
  pcVar1[0xb] = '\0';
  pcVar1[0xc] = '\0';
  pcVar1[0xd] = '\0';
  pcVar1[0xe] = '\0';
  pcVar1[0xf] = '\0';
  pcVar1[0x10] = '\0';
  pcVar1[0x11] = '\0';
  pcVar1[0x12] = '\0';
  pcVar1[0x13] = '\0';
  pcVar1[0x14] = '\0';
  pcVar1[0x15] = '\0';
  pcVar1[0x16] = '\0';
  pcVar1[0x17] = '\0';
  pcVar1[0x18] = '\0';
  pcVar1[0x19] = '\0';
  pcVar1[0x1a] = '\0';
  pcVar1[0x1b] = '\0';
  pcVar1[0x1c] = '\0';
  pcVar1[0x1d] = '\0';
  pcVar1[0x1e] = '\0';
  pcVar1[0x1f] = '\0';
  pcVar1[0x20] = '\0';
  pcVar1[0x21] = '\0';
  pcVar1[0x22] = '\0';
  pcVar1[0x23] = '\0';
  pcVar1[0x24] = '\0';
  pcVar1[0x25] = '\0';
  pcVar1[0x26] = '\0';
  pcVar1[0x27] = '\0';
  pcVar1[0x28] = '\0';
  pcVar1[0x29] = '\0';
  pcVar1[0x2a] = '\0';
  pcVar1[0x2b] = '\0';
  *pcVar1 = param_2;
  pcVar1[3] = '\x04';
  *(undefined4 *)(pcVar1 + 0x14) = *param_3;
  *(undefined4 *)(pcVar1 + 0x18) = param_4;
  pcVar1[0x1c] = '\0';
  pcVar1[0x1d] = '\0';
  pcVar1[0x1e] = '\0';
  pcVar1[0x1f] = -0x2d;
  if (param_2 == '\0') {
    *(int *)(pcVar1 + 0x20) = *(int *)(param_1 + 0x1fc) + 0x2c;
  }
  else {
    *(int *)(pcVar1 + 0x20) = param_5 - *(int *)(param_1 + 0x100);
    *(uint *)(pcVar1 + 0x1c) = (uint)*(byte *)((longlong)param_3 + 1) << 2 | 0xd3000000;
  }
  *(undefined4 *)(pcVar1 + 0x24) = *(undefined4 *)(param_1 + 0x1ec);
  if (param_2 == '\x02') {
    *(uint *)(pcVar1 + 0x1c) = *(uint *)(pcVar1 + 0x1c) | 0x4000000;
  }
  QueueRequestDescriptor(param_1,(uint)uVar2 * 0x10000 + 8,0,param_6);
  return;
}



===== SendExtendedConfigPageMessage @ 140010370 =====

void SendExtendedConfigPageMessage
               (longlong param_1,char param_2,char *param_3,undefined4 param_4,int param_5,
               int param_6)

{
  char *pcVar1;
  int iVar2;
  ushort uVar3;
  
  if (param_3 == (char *)(param_1 + 0x1530)) {
LAB_140010405:
    pcVar1 = *(char **)(param_1 + 0x278);
    uVar3 = *(ushort *)(param_1 + 0x5b0);
    iVar2 = *(int *)(param_1 + 0x204);
  }
  else {
    if (param_3 == (char *)(param_1 + 0x1518)) {
      if (*(char *)(param_1 + 0x5b6) == '\x01') goto LAB_140010405;
      if (*(char *)(param_1 + 0x5b6) == '\x02') {
        pcVar1 = *(char **)(param_1 + 0x280);
        uVar3 = *(ushort *)(param_1 + 0x5b2);
        iVar2 = *(int *)(param_1 + 0x208);
        goto LAB_14001041a;
      }
      if ((param_3 == (char *)(param_1 + 0x1518)) && (*(char *)(param_1 + 0x5b6) == '\x03')) {
        pcVar1 = *(char **)(param_1 + 0x288);
        uVar3 = *(ushort *)(param_1 + 0x5b4);
        iVar2 = *(int *)(param_1 + 0x20c);
        goto LAB_14001041a;
      }
    }
    pcVar1 = *(char **)(param_1 + 0x268);
    uVar3 = *(ushort *)(param_1 + 0x5ac);
    iVar2 = *(int *)(param_1 + 0x1fc);
  }
LAB_14001041a:
  *(undefined1 *)(param_1 + 0x5b6) = 0;
  pcVar1[0] = '\0';
  pcVar1[1] = '\0';
  pcVar1[2] = '\0';
  pcVar1[3] = '\0';
  pcVar1[4] = '\0';
  pcVar1[5] = '\0';
  pcVar1[6] = '\0';
  pcVar1[7] = '\0';
  pcVar1[8] = '\0';
  pcVar1[9] = '\0';
  pcVar1[10] = '\0';
  pcVar1[0xb] = '\0';
  pcVar1[0xc] = '\0';
  pcVar1[0xd] = '\0';
  pcVar1[0xe] = '\0';
  pcVar1[0xf] = '\0';
  pcVar1[0x10] = '\0';
  pcVar1[0x11] = '\0';
  pcVar1[0x12] = '\0';
  pcVar1[0x13] = '\0';
  pcVar1[0x14] = '\0';
  pcVar1[0x15] = '\0';
  pcVar1[0x16] = '\0';
  pcVar1[0x17] = '\0';
  pcVar1[0x18] = '\0';
  pcVar1[0x19] = '\0';
  pcVar1[0x1a] = '\0';
  pcVar1[0x1b] = '\0';
  pcVar1[0x1c] = '\0';
  pcVar1[0x1d] = '\0';
  pcVar1[0x1e] = '\0';
  pcVar1[0x1f] = '\0';
  pcVar1[0x20] = '\0';
  pcVar1[0x21] = '\0';
  pcVar1[0x22] = '\0';
  pcVar1[0x23] = '\0';
  pcVar1[0x24] = '\0';
  pcVar1[0x25] = '\0';
  pcVar1[0x26] = '\0';
  pcVar1[0x27] = '\0';
  pcVar1[0x28] = '\0';
  pcVar1[0x29] = '\0';
  pcVar1[0x2a] = '\0';
  pcVar1[0x2b] = '\0';
  *pcVar1 = param_2;
  pcVar1[3] = '\x04';
  pcVar1[0x14] = *param_3;
  pcVar1[0x16] = param_3[2];
  pcVar1[0x17] = param_3[3];
  *(undefined2 *)(pcVar1 + 4) = *(undefined2 *)(param_3 + 4);
  pcVar1[6] = param_3[6];
  *(undefined4 *)(pcVar1 + 0x18) = param_4;
  pcVar1[0x1c] = '\0';
  pcVar1[0x1d] = '\0';
  pcVar1[0x1e] = '\0';
  pcVar1[0x1f] = -0x2d;
  if (param_2 == '\0') {
    *(int *)(pcVar1 + 0x20) = iVar2 + 0x2c;
  }
  else {
    *(int *)(pcVar1 + 0x20) = param_5 - *(int *)(param_1 + 0x100);
    *(uint *)(pcVar1 + 0x1c) = (uint)*(ushort *)(param_3 + 4) << 2 | 0xd3000000;
  }
  *(undefined4 *)(pcVar1 + 0x24) = *(undefined4 *)(param_1 + 0x1ec);
  if ((param_2 - 2U & 0xfd) == 0) {
    *(uint *)(pcVar1 + 0x1c) = *(uint *)(pcVar1 + 0x1c) | 0x4000000;
  }
  if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x800) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x800,pcVar1,0x2c,param_6
               );
  }
  QueueRequestDescriptor(param_1,(uint)uVar3 * 0x10000 + 8,0,param_6);
  return;
}



===== SendIOCInitMessage @ 140010530 =====

bool SendIOCInitMessage(longlong param_1)

{
  undefined4 uVar1;
  bool bVar2;
  bool bVar3;
  ulonglong uVar4;
  longlong local_res8;
  
  uVar1 = *(undefined4 *)(param_1 + 0x1ec);
  *(undefined8 *)(param_1 + 0x5c0) = 0;
  *(undefined8 *)(param_1 + 0x5c8) = 0;
  *(undefined8 *)(param_1 + 0x5d0) = 0;
  bVar2 = false;
  *(undefined8 *)(param_1 + 0x5d8) = 0;
  *(undefined8 *)(param_1 + 0x5e0) = 0;
  *(undefined8 *)(param_1 + 0x5e8) = 0;
  *(undefined8 *)(param_1 + 0x5f0) = 0;
  *(undefined8 *)(param_1 + 0x5f8) = 0;
  *(undefined8 *)(param_1 + 0x600) = 0;
  *(undefined8 *)(param_1 + 0x660) = 0;
  *(undefined8 *)(param_1 + 0x668) = 0;
  *(undefined4 *)(param_1 + 0x670) = 0;
  *(undefined1 *)(param_1 + 0x5c3) = 2;
  *(undefined1 *)(param_1 + 0x5c0) = 4;
  *(undefined4 *)(param_1 + 0x5cc) = 0x23000200;
  *(undefined2 *)(param_1 + 0x5da) = *(undefined2 *)(param_1 + 0x242);
  *(undefined2 *)(param_1 + 0x5dc) = *(undefined2 *)(param_1 + 0x246);
  *(undefined2 *)(param_1 + 0x5de) = *(undefined2 *)(param_1 + 0x244);
  *(undefined4 *)(param_1 + 0x5e0) = uVar1;
  *(undefined4 *)(param_1 + 0x5e4) = uVar1;
  *(undefined4 *)(param_1 + 0x5e8) = *(undefined4 *)(param_1 + 0x1f8);
  *(undefined4 *)(param_1 + 0x5ec) = uVar1;
  *(undefined4 *)(param_1 + 0x5f0) = *(undefined4 *)(param_1 + 500);
  *(undefined4 *)(param_1 + 0x5f4) = uVar1;
  *(undefined4 *)(param_1 + 0x5f8) = *(undefined4 *)(param_1 + 0x1f0);
  *(undefined4 *)(param_1 + 0x5fc) = uVar1;
  StorPortQuerySystemTime(&local_res8);
  local_res8 = (local_res8 + -0x19db1ded53e8000) / 10000;
  *(longlong *)(param_1 + 0x600) = local_res8;
  if (*(char *)(param_1 + 0x12a) != '\0') {
    *(undefined1 *)(param_1 + 0x5d7) = *(undefined1 *)(param_1 + 299);
  }
  bVar3 = SendMessageViaHandShake(param_1,0,0x12);
  if ((!bVar3) || (uVar4 = ReceiveDataViaHandshake(param_1,10), (char)uVar4 == '\0')) {
    bVar2 = true;
  }
  *(undefined1 *)(param_1 + 0xdf2) = 0;
  *(undefined2 *)(param_1 + 0x218) = 0;
  if (bVar2) {
    StorPortLogError(param_1,0,0,0,0,6,0xad010010);
  }
  return !bVar2;
}



===== SendIOCTLMessage @ 140010720 =====

undefined8 SendIOCTLMessage(longlong param_1,ushort *param_2,void *param_3,int param_4)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  longlong lVar4;
  byte bVar5;
  uint uVar6;
  longlong *plVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint *_Dst;
  byte local_res8;
  uint local_64;
  int local_60;
  uint local_5c;
  uint *local_58;
  longlong local_50;
  
  uVar1 = *(ushort *)(param_1 + 0x240);
  iVar10 = 0;
  lVar4 = *(longlong *)((longlong)param_3 + 0x68);
  uVar2 = *param_2;
  uVar3 = *(ushort *)(param_1 + 0x23e);
  iVar12 = 0;
  local_res8 = 8;
  local_60 = 0;
  uVar11 = (uint)param_2[1] * 4 + 8;
  if ((short)uVar2 < 0) {
    uVar11 = uVar11 + param_2[3];
  }
  else if ((uVar2 & 1) != 0) {
    uVar11 = uVar11 + *(int *)(param_2 + 2);
  }
  local_5c = (uint)uVar3;
  if ((short)uVar2 < 0) {
    uVar6 = local_5c + (*(uint *)(param_2 + 2) & 0xffff);
  }
  else {
    uVar6 = local_5c;
    if ((uVar2 & 1) == 0) {
      uVar6 = local_5c + *(int *)(param_2 + 2);
    }
  }
  plVar7 = *(longlong **)((longlong)param_3 + 0x40);
  local_64 = uVar6 + 0xff;
  if ((uVar2 & 0x4000) == 0) {
    local_64 = uVar6;
  }
  if (local_64 < uVar11) {
    local_64 = uVar11;
  }
  if ((*(uint *)(plVar7 + 3) < local_64) ||
     (plVar7 = *(longlong **)(param_1 + 0x510), *(longlong *)(*plVar7 + 8) != 0)) {
LAB_1400107e1:
    return (ulonglong)plVar7 & 0xffffffffffffff00;
  }
  local_50 = lVar4;
  if (*(char *)((longlong)param_2 + 0xb) == '\x01') {
    if (*(int *)(param_1 + 0x568) != 0) goto LAB_1400107e1;
    local_res8 = 6;
    StorPortPause(param_1,300);
    ResetActive(param_1,5,param_4);
  }
  _Dst = (uint *)(lVar4 + 0x158);
  uVar11 = StorPortGetPhysicalAddress(param_1,param_3,_Dst,&local_64);
  memcpy(_Dst,param_2 + 4,(ulonglong)param_2[1] << 2);
  uVar2 = *(ushort *)(param_1 + 0x5aa);
  *(undefined4 *)(param_1 + 0xd8c) = 0;
  *(undefined1 *)(*(longlong *)(param_1 + 0x2a0) + 0x13 + (ulonglong)uVar2 * 0x18) = 1;
  if ((short)*param_2 < 0) {
    bVar5 = *(byte *)(param_1 + 0x24e) & 1;
    local_58 = _Dst + param_2[1];
    uVar8 = StorPortGetPhysicalAddress
                      (param_1,param_3,
                       (longlong)param_2 + (longlong)(int)((uint)param_2[1] * 4 + -4) + 0xc,
                       &local_64);
    local_64 = (uint)param_2[3];
    iVar10 = 0x56;
    if (bVar5 == 0) {
      iVar10 = 0x54;
    }
    *local_58 = iVar10 << 0x18 | local_64;
    local_58[1] = (uint)uVar8;
    if (bVar5 != 0) {
      local_58[2] = (uint)((ulonglong)uVar8 >> 0x20);
    }
    param_2[1] = param_2[1] + (ushort)(byte)(bVar5 + 2);
    param_2[3] = 0;
    *param_2 = 0;
  }
  else {
    iVar12 = 0;
    if ((*param_2 & 0x4000) != 0) {
      *(undefined1 *)(lVar4 + 0x16c) = 0x18;
      uVar6 = 0;
      *(undefined1 *)(lVar4 + 0x16a) = 0xff;
      local_60 = 0xff;
      if ((*param_2 & 1) == 0) {
        uVar6 = *(uint *)(param_2 + 2);
      }
      *(uint *)(lVar4 + 0x164) = uVar11 - 0x100;
      *(ulonglong *)(param_1 + 0xe60) = (longlong)param_2 + (ulonglong)uVar3 + (ulonglong)uVar6;
      *(uint *)(lVar4 + 0x194) = *(uint *)(lVar4 + 0x194) & 0xfffff8ff;
      *param_2 = *param_2 & 0xbfff;
      if (*(char *)(lVar4 + 0x15b) == '\0') {
        iVar12 = (uint)*(ushort *)_Dst << 0x10;
        local_res8 = 0;
      }
    }
    if (*param_2 == 1) {
      uVar6 = (uint)param_2[1] * 4 + 8;
      bVar5 = 0;
      goto LAB_1400109c1;
    }
    bVar5 = 0;
  }
  iVar10 = *(int *)(param_2 + 2);
  uVar6 = (uint)uVar3;
LAB_1400109c1:
  if (*(int *)(param_2 + 2) == 0) {
    uVar9 = (ulonglong)param_2[1];
    _Dst[uVar9] = 0xd3000000;
    _Dst[uVar9 + 1] = uVar11 + (uint)param_2[1] * 4;
    if (bVar5 != 0) {
      _Dst[uVar9 + 2] = *(uint *)(param_1 + 0x1ec);
    }
  }
  else {
    local_64 = BuildIoctlScatterGather
                         (param_1,(longlong)param_3,_Dst,uVar11,(short *)param_2,
                          uVar6 + (int)param_2);
    if (iVar10 != 0) {
      iVar10 = iVar10 - local_64;
    }
  }
  *(uint *)((longlong)param_3 + 0x3c) = local_60 + local_5c + 0x1c + iVar10;
  *(void **)(param_1 + 0xe08) = param_3;
  memcpy((void *)(param_1 + 0xe18),param_3,0x40);
  *(undefined1 *)(param_1 + 0xe00) = *(undefined1 *)(local_50 + 0x52);
  memcpy(*(void **)(param_1 + 0xe58),_Dst,(ulonglong)(uint)uVar1);
  memcpy(*(void **)(param_1 + 0x548),_Dst,(ulonglong)(uint)uVar1);
  *(undefined1 *)(param_1 + 0xdfe) = 1;
  uVar8 = QueueRequestDescriptor(param_1,(uint)uVar2 * 0x10000 + (uint)local_res8,iVar12,param_4);
  return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
}



===== SendLunResetTur @ 140010ad0 =====

void SendLunResetTur(longlong param_1,ushort param_2,int param_3)

{
  longlong lVar1;
  ushort *puVar2;
  byte bVar3;
  undefined4 uVar4;
  undefined1 local_res10 [8];
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x528) + 0x68);
  bVar3 = GtfStartTimer(param_1,1,2,LunResetTurTimeout,0,param_3);
  *(byte *)(param_1 + 0x6a5) = bVar3;
  if (((bVar3 == 0xfe) && (*(char *)(param_1 + 0x308) != '\0')) &&
     ((*(uint *)(param_1 + 0x30c) & 0x233) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x233,(undefined1 *)0x0,0
                ,param_3);
  }
  *(undefined1 *)
   (*(longlong *)(param_1 + 0x2a0) + 0x13 + (ulonglong)*(ushort *)(param_1 + 0x5ae) * 0x18) = 0x40;
  puVar2 = *(ushort **)(param_1 + 0x270);
  puVar2[0] = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  *(undefined1 *)((longlong)puVar2 + 3) = 0;
  *(undefined1 *)(puVar2 + 10) = 0x18;
  *puVar2 = param_2;
  uVar4 = StorPortGetPhysicalAddress
                    (param_1,*(undefined8 *)(param_1 + 0x528),lVar1 + 0x58,local_res10);
  *(undefined1 *)(puVar2 + 9) = 0xff;
  *(undefined4 *)(puVar2 + 6) = uVar4;
  puVar2[0x12] = 6;
  BuildZeroLenSGE(param_1,(longlong)puVar2,*(int *)(param_1 + 0x200));
  QueueRequestDescriptor
            (param_1,(uint)*(ushort *)(param_1 + 0x5ae) << 0x10,(uint)*puVar2 << 0x10,param_3);
  if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x20008) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x20008,
                (undefined1 *)(lVar1 + 0x52),3,param_3);
  }
  return;
}



===== SendMessageViaHandShake @ 140010c50 =====

bool SendMessageViaHandShake(longlong param_1,int param_2,uint param_3)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  uVar4 = 10000;
  if (param_2 == 0) {
    puVar5 = (undefined4 *)(param_1 + 0x5c0);
    uVar4 = 10000;
    if (*(char *)(param_1 + 0x5c3) != '\x04') {
      uVar4 = 60000;
    }
  }
  else {
    puVar5 = (undefined4 *)(param_1 + 0x610);
  }
  **(undefined4 **)(param_1 + 0x48) = 0;
  LOCK();
  UNLOCK();
  **(int **)(param_1 + 0x18) = (param_3 | 0x4200) << 0x10;
  LOCK();
  UNLOCK();
  uVar3 = 0;
  do {
    if (**(uint **)(param_1 + 0x48) == 0xffffffff) break;
    if ((**(uint **)(param_1 + 0x48) & 1) != 0) {
      bVar2 = 1;
      goto LAB_140010ce7;
    }
    StorPortStallExecution();
    uVar3 = uVar3 + 1;
  } while (uVar3 < uVar4);
  bVar2 = 0;
LAB_140010ce7:
  bVar1 = (bool)(bVar2 ^ 1);
  if ((**(uint **)(param_1 + 0x18) >> 0x1b & 1) == 0) {
    bVar1 = true;
  }
  **(undefined4 **)(param_1 + 0x48) = 0;
  LOCK();
  UNLOCK();
  if (!bVar1) {
    uVar4 = 0;
    do {
      if (**(int **)(param_1 + 0x48) == -1) break;
      if (-1 < **(int **)(param_1 + 0x48)) goto LAB_140010d3c;
      StorPortStallExecution(500);
      uVar4 = uVar4 + 1;
    } while (uVar4 < 120000);
  }
  bVar1 = true;
LAB_140010d3c:
  uVar4 = 0;
  if (param_3 != 0) {
    do {
      if (bVar1) {
        return !bVar1;
      }
      **(undefined4 **)(param_1 + 0x18) = *puVar5;
      LOCK();
      UNLOCK();
      uVar3 = 0;
      do {
        if (**(int **)(param_1 + 0x48) == -1) break;
        if (-1 < **(int **)(param_1 + 0x48)) goto LAB_140010d87;
        StorPortStallExecution(500);
        uVar3 = uVar3 + 1;
      } while (uVar3 < 120000);
      bVar1 = true;
LAB_140010d87:
      uVar4 = uVar4 + 1;
      puVar5 = puVar5 + 1;
    } while (uVar4 < param_3);
  }
  return !bVar1;
}



===== SendPortEnables @ 140010dc0 =====

undefined8 SendPortEnables(longlong param_1,undefined4 param_2)

{
  undefined8 *puVar1;
  undefined8 in_RAX;
  undefined8 uVar2;
  undefined7 uVar3;
  ushort uVar4;
  uint uVar5;
  
  uVar4 = 0;
  if (*(short *)(param_1 + 0x596) == 0) {
    uVar3 = (undefined7)((ulonglong)in_RAX >> 8);
  }
  else {
    do {
      puVar1 = *(undefined8 **)(param_1 + 0x270);
      *(undefined1 *)(param_1 + 0xdba) = 1;
      *puVar1 = 0;
      *(undefined4 *)(puVar1 + 1) = 0;
      *(undefined1 *)((longlong)puVar1 + 3) = 6;
      **(int **)(param_1 + 0xe8) = (uint)*(ushort *)(param_1 + 0x5ae) * 0x10000 + 8;
      LOCK();
      UNLOCK();
      **(undefined4 **)(param_1 + 0xf0) = 0;
      LOCK();
      UNLOCK();
      uVar5 = 0;
      if (*(int *)(param_1 + 0x558) == 0) {
        return 0;
      }
      do {
        uVar2 = PollLSImpiIsr(param_1,param_2);
        if (*(char *)(param_1 + 0xdba) == '\0') break;
        uVar2 = StorPortStallExecution(500);
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(param_1 + 0x558));
      if (*(uint *)(param_1 + 0x558) <= uVar5) {
        return 0;
      }
      if (*(short *)(param_1 + 0x566) != 0) {
        return 0;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(ushort *)(param_1 + 0x596));
    uVar3 = (undefined7)((ulonglong)uVar2 >> 8);
  }
  return CONCAT71(uVar3,1);
}



===== SendSEPMessage @ 140010ed0 =====

void SendSEPMessage(longlong param_1,undefined4 param_2,undefined2 param_3,int param_4)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0x268);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  *(undefined4 *)((longlong)puVar1 + 0xc) = param_2;
  *(undefined2 *)puVar1 = param_3;
  *(undefined2 *)((longlong)puVar1 + 3) = 0x18;
  QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x5ac) * 0x10000 + 8,0,param_4);
  return;
}



===== SendSsuMessage @ 140010f10 =====

ulonglong SendSsuMessage(longlong param_1,ushort param_2)

{
  longlong lVar1;
  longlong lVar2;
  ushort *puVar3;
  ushort *puVar4;
  
  lVar1 = **(longlong **)(param_1 + 0x510);
  if (*(longlong *)(lVar1 + 8) != 0) {
    return (ulonglong)*(longlong **)(param_1 + 0x510) & 0xffffffffffffff00;
  }
  *(byte *)(lVar1 + 0x13) = *(byte *)(lVar1 + 0x13) | 0x10;
  *(ulonglong *)(lVar1 + 8) = (ulonglong)param_2;
  *(longlong *)(param_1 + 0x510) = *(longlong *)(param_1 + 0x510) + 8;
  *(int *)(param_1 + 0x3d40) = *(int *)(param_1 + 0x3d40) + 1;
  if (*(longlong *)(param_1 + 0x510) == *(longlong *)(param_1 + 0x520)) {
    *(undefined8 *)(param_1 + 0x510) = *(undefined8 *)(param_1 + 0x508);
  }
  puVar3 = (ushort *)
           ((longlong)(int)((uint)*(ushort *)(param_1 + 0x240) * (uint)*(ushort *)(lVar1 + 0x10)) +
           *(longlong *)(param_1 + 0x260));
  puVar4 = puVar3;
  for (lVar2 = 0x70; lVar2 != 0; lVar2 = lVar2 + -1) {
    *(undefined1 *)puVar4 = 0;
    puVar4 = (ushort *)((longlong)puVar4 + 1);
  }
  *puVar3 = param_2;
  *(undefined1 *)((longlong)puVar3 + 3) = 0;
  *(undefined1 *)(puVar3 + 0x20) = 0x1b;
  **(int **)(param_1 + 0xe8) = (uint)*(ushort *)(lVar1 + 0x10) << 0x10;
  LOCK();
  UNLOCK();
  **(int **)(param_1 + 0xf0) = (uint)param_2 << 0x10;
  LOCK();
  UNLOCK();
  return 1;
}



===== SendSsuMessagesToDevices @ 140010fe0 =====

void SendSsuMessagesToDevices(longlong param_1)

{
  longlong lVar1;
  ushort uVar2;
  byte bVar3;
  char cVar4;
  ulonglong uVar5;
  ushort uVar6;
  ushort uVar7;
  
  uVar7 = *(ushort *)(param_1 + 0x3d4a);
  cVar4 = '\x01';
  if (*(uint *)(param_1 + 0x5b8) <= (uint)uVar7) {
    *(ushort *)(param_1 + 0x3d4a) = uVar7;
    return;
  }
  do {
    uVar2 = *(ushort *)(*(longlong *)(param_1 + 0x2c8) + 0x1a + (ulonglong)uVar7 * 0x28);
    lVar1 = *(longlong *)(param_1 + 0x2c8) + (ulonglong)uVar7 * 0x28;
    if ((((uVar2 != 0) && (*(char *)(lVar1 + 0x23) == '\0')) && (*(char *)(lVar1 + 0x24) != '\0'))
       && ((bVar3 = (byte)*(undefined4 *)(lVar1 + 0x14), (char)bVar3 < '\0' && ((bVar3 & 7) == 1))))
    {
      uVar6 = *(ushort *)(param_1 + 0x3d48) & 3;
      if (uVar6 == 1) {
        if (*(char *)(lVar1 + 0x25) != '\0') goto LAB_14001106d;
      }
      else if ((uVar6 != 2) || (*(char *)(lVar1 + 0x25) == '\0')) {
LAB_14001106d:
        uVar5 = SendSsuMessage(param_1,uVar2);
        cVar4 = (char)uVar5;
      }
      if (cVar4 == '\0') break;
    }
    uVar7 = uVar7 + 1;
  } while ((uint)uVar7 < *(uint *)(param_1 + 0x5b8));
  *(ushort *)(param_1 + 0x3d4a) = uVar7;
  return;
}



===== SendSsuTmrMessagesToDevices @ 1400110c0 =====

void SendSsuTmrMessagesToDevices(longlong param_1,int param_2)

{
  int *piVar1;
  ushort uVar2;
  undefined2 uVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  
  plVar5 = *(longlong **)(param_1 + 0x508);
  piVar1 = (int *)(param_1 + 0x3d40);
  *piVar1 = 0;
  if (plVar5 < *(longlong **)(param_1 + 0x520)) {
    do {
      lVar4 = *plVar5;
      if (*(longlong *)(lVar4 + 8) != 0) {
        *(undefined1 *)(lVar4 + 0x13) = 0x20;
        *piVar1 = *piVar1 + 1;
        uVar2 = *(ushort *)(lVar4 + 0x10);
        uVar3 = *(undefined2 *)(lVar4 + 8);
        puVar6 = (undefined8 *)
                 ((longlong)(int)((uint)*(ushort *)(param_1 + 0x240) * (uint)uVar2) +
                 *(longlong *)(param_1 + 0x260));
        *puVar6 = 0;
        puVar6[1] = 0;
        puVar6[2] = 0;
        puVar6[3] = 0;
        puVar6[4] = 0;
        puVar6[5] = 0;
        *(undefined4 *)(puVar6 + 6) = 0;
        *(undefined2 *)puVar6 = uVar3;
        *(undefined1 *)((longlong)puVar6 + 3) = 1;
        *(undefined1 *)((longlong)puVar6 + 5) = 3;
        **(int **)(param_1 + 0xe8) = (uint)uVar2 * 0x10000 + 6;
        LOCK();
        UNLOCK();
        **(undefined4 **)(param_1 + 0xf0) = 0;
        LOCK();
        UNLOCK();
      }
      plVar5 = plVar5 + 1;
    } while (plVar5 < *(longlong **)(param_1 + 0x520));
  }
  if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x80004) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x80004,
                (undefined1 *)piVar1,4,param_2);
  }
  return;
}



===== SynchronizeHandleOrphanedIoctl @ 1400111d0 =====

undefined8 SynchronizeHandleOrphanedIoctl(longlong param_1,int *param_2)

{
  int iVar1;
  ulonglong in_RAX;
  ulonglong in_stack_ffffffffffffffd8;
  
  iVar1 = *param_2;
  *(undefined1 *)(param_1 + 0xdb9) = 1;
  if (((*(char *)(param_1 + 0xdfe) == '\0') && (*(longlong *)(param_1 + 0xe08) == 0)) &&
     (in_RAX = (ulonglong)*(byte *)(param_1 + 0xebb),
     *(longlong *)(param_1 + 0xec0 + in_RAX * 8) != 0)) {
    in_RAX = CheckIoctlQueue(param_1,iVar1);
    if ((char)in_RAX != '\0') {
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x241) != 0)) {
        in_stack_ffffffffffffffd8 = 0;
        RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x241,
                    (undefined1 *)0x0,0,iVar1);
      }
      in_RAX = StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffffd8 & 0xffffffffffffff00,6,
                                0xad010076);
    }
  }
  *(undefined1 *)(param_1 + 0xdb9) = 0;
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== SynchronizeHandleOrphanedReset @ 1400112b0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 SynchronizeHandleOrphanedReset(longlong param_1,int *param_2)

{
  char *pcVar1;
  int iVar2;
  ulonglong in_RAX;
  ulonglong in_stack_ffffffffffffffd8;
  
  pcVar1 = (char *)(param_1 + 0xdb9);
  iVar2 = *param_2;
  *pcVar1 = '\x01';
  if (((*(int *)(param_1 + 0x568) == 0) && (*(longlong *)(param_1 + 0x528) == 0)) &&
     (in_RAX = (ulonglong)*(byte *)(param_1 + 0xebd),
     *(longlong *)(param_1 + 0xfc0 + in_RAX * 8) != 0)) {
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x23a) != 0)) {
      in_stack_ffffffffffffffd8 = 0;
      RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x2d8),0x23a,(undefined1 *)0x0,0,iVar2);
    }
    StorPortLogError(param_1,0,0,0,in_stack_ffffffffffffffd8 & 0xffffffffffffff00,6,0xad010074);
    if (*(char *)(param_1 + 0xdaf) != '\0') {
      *(undefined4 *)(param_1 + 0x147c) = _DAT_0000aaaa;
    }
    in_RAX = CheckResetQueue(param_1,iVar2);
  }
  *pcVar1 = '\0';
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== SynchronizeReset @ 1400113a0 =====

void SynchronizeReset(longlong param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  *(undefined1 *)(param_1 + 0xdb9) = 1;
  LSImpiReset(param_1,**(uint **)(param_2 + 2),iVar1);
  *(undefined1 *)(param_1 + 0xdb9) = 0;
  return;
}



===== SynchronizeRestartRecovery @ 1400113d0 =====

undefined8 SynchronizeRestartRecovery(longlong param_1,int *param_2)

{
  char *pcVar1;
  int iVar2;
  undefined8 *puVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  undefined8 uVar7;
  uint uVar8;
  undefined4 uVar9;
  
  pcVar1 = (char *)(param_1 + 0xdb9);
  iVar2 = *param_2;
  *pcVar1 = '\x01';
  switch(*(undefined1 *)(param_1 + 0xdf8)) {
  case 1:
    if (*(int *)(param_1 + 0x57c) != 0) break;
    uVar8 = **(uint **)(param_1 + 0x18) & 0xf0000000;
    if (uVar8 != 0x10000000) goto LAB_140011441;
    *(undefined4 *)(param_1 + 0xdf8) = 2;
  case 2:
    **(uint **)(param_1 + 0x50) = **(uint **)(param_1 + 0x50) | 0x40000009;
    LOCK();
    UNLOCK();
    CompleteAllSrbs(param_1);
    *(undefined2 *)(param_1 + 0xdf4) = 0;
    LsiMpiPartitionMemory(param_1);
    bVar4 = SendIOCInitMessage(param_1);
    if (bVar4) {
      *(undefined4 *)(param_1 + 0xdf8) = 3;
    }
    else {
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x20d) != 0)) {
        uVar9 = 0x20d;
LAB_14001153a:
        RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x2d8),uVar9,(undefined1 *)(param_1 + 0xd84),4,
                    iVar2);
      }
LAB_140011565:
      KickStart(param_1,iVar2);
      *(undefined4 *)(param_1 + 0xdf8) = 1;
    }
    break;
  case 3:
    uVar8 = **(uint **)(param_1 + 0x18) & 0xf0000000;
    if (uVar8 == 0x20000000) {
      *(undefined1 *)(param_1 + 0xdfc) = 0;
      goto switchD_14001141a_caseD_4;
    }
    if (uVar8 != 0xf0000000) {
      *(short *)(param_1 + 0xdf4) = *(short *)(param_1 + 0xdf4) + 1;
      if (*(ushort *)(param_1 + 0xdf4) < 0x65) break;
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x20c) != 0)) {
        uVar9 = 0x20c;
        goto LAB_1400115d2;
      }
      goto LAB_1400115fd;
    }
LAB_140011bf1:
    *(undefined1 *)(param_1 + 0xdf2) = 0;
    goto LAB_140011b7b;
  case 4:
switchD_14001141a_caseD_4:
    InitReplyFreeQueue(param_1);
    ReadAndSetSASPages(param_1,iVar2);
    ProcessDPMPage0(param_1);
    EnableDisableEvents(param_1,'\x01',iVar2);
    puVar3 = *(undefined8 **)(param_1 + 0x270);
    *(undefined2 *)(param_1 + 0xdf4) = 0;
    *puVar3 = 0;
    *(undefined4 *)(puVar3 + 1) = 0;
    *(undefined1 *)((longlong)puVar3 + 3) = 6;
    *(undefined1 *)(param_1 + 0xdba) = 1;
    **(int **)(param_1 + 0xe8) = (uint)*(ushort *)(param_1 + 0x5ae) * 0x10000 + 8;
    LOCK();
    UNLOCK();
    **(undefined4 **)(param_1 + 0xf0) = 0;
    LOCK();
    UNLOCK();
    *(undefined4 *)(param_1 + 0xdf8) = 5;
    break;
  case 5:
    PollLSImpiIsr(param_1,iVar2);
    if (*(char *)(param_1 + 0xdba) != '\0') {
      *(short *)(param_1 + 0xdf4) = *(short *)(param_1 + 0xdf4) + 1;
      if (*(ushort *)(param_1 + 0xdf4) <= (ushort)((ulonglong)*(uint *)(param_1 + 0x558) / 200))
      break;
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x20e) != 0)) {
        uVar9 = 0x20e;
LAB_1400115d2:
        RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x2d8),uVar9,(undefined1 *)(param_1 + 0xd84),4,
                    iVar2);
      }
LAB_1400115fd:
      KickStart(param_1,iVar2);
      *(undefined4 *)(param_1 + 0xdf8) = 1;
      *(undefined2 *)(param_1 + 0xdf4) = 0;
      break;
    }
    *(undefined2 *)(param_1 + 0xdf4) = 0;
    if (*(short *)(param_1 + 0x566) == 0) {
      *(char *)(param_1 + 0xdfc) = *(char *)(param_1 + 0xdfc) + '\x01';
      uVar9 = 6;
      if ((ushort)*(byte *)(param_1 + 0xdfc) < *(ushort *)(param_1 + 0x596)) {
        uVar9 = 4;
      }
      *(undefined4 *)(param_1 + 0xdf8) = uVar9;
      break;
    }
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x20f) != 0)) {
      uVar9 = 0x20f;
      goto LAB_14001153a;
    }
    goto LAB_140011565;
  case 6:
    if ((*(char *)(param_1 + 0xdbe) == '\0') && (*(char *)(param_1 + 0xdbf) == '\0')) {
      *(undefined4 *)(param_1 + 0xdf8) = 7;
    }
    else {
      do {
        cVar5 = PollLSImpiIsr(param_1,iVar2);
        StorPortStallExecution(500);
      } while (cVar5 != '\0');
      *(short *)(param_1 + 0xdf4) = *(short *)(param_1 + 0xdf4) + 1;
      if (600 < *(ushort *)(param_1 + 0xdf4)) {
        KickStart(param_1,iVar2);
        *(undefined4 *)(param_1 + 0xdf8) = 1;
        *(undefined2 *)(param_1 + 0xdf4) = 0;
      }
    }
    break;
  case 7:
    InternalLSImpiHWInitialize(param_1,iVar2);
    if (*(char *)(param_1 + 0xdb0) != '\0') {
      if (*(longlong *)(param_1 + 0xe08) != 0) {
        *(undefined1 *)(*(longlong *)(param_1 + 0xe08) + 3) = 1;
        StorPortNotification(0,param_1);
      }
      *(undefined1 *)(param_1 + 0xdb0) = 0;
      *(undefined8 *)(param_1 + 0xe08) = 0;
    }
    StorPortResume(param_1);
    StorPortReady(param_1);
    if (((*(short *)(param_1 + 0x5a6) == 0) && (*(char *)(param_1 + 0xdb6) == '\0')) &&
       (uVar8 = 0, *(short *)(param_1 + 0x5a0) != 0)) {
      do {
        if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x40002) != 0)) {
          RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x2d8),0x40002,(undefined1 *)0x0,0,iVar2);
        }
        StorPortNotification(7,param_1,uVar8);
        uVar8 = uVar8 + 1;
      } while (uVar8 < *(ushort *)(param_1 + 0x5a0));
    }
    *(undefined1 *)(param_1 + 0xdb6) = 0;
    *(undefined4 *)(param_1 + 0xdf8) = 0;
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x40000) != 0)) {
      RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x2d8),0x40000,(undefined1 *)0x0,0,iVar2);
    }
    break;
  case 8:
    **(uint **)(param_1 + 0x50) = **(uint **)(param_1 + 0x50) | 0x40000009;
    LOCK();
    UNLOCK();
    *(undefined4 *)(param_1 + 0x3d44) = 100;
    *(undefined4 *)(param_1 + 0x3d40) = 0;
    *(undefined2 *)(param_1 + 0x3d4a) = 0;
    goto LAB_140011941;
  case 9:
    SendSsuMessagesToDevices(param_1);
    uVar9 = 0xd;
    if (*(int *)(param_1 + 0x3d40) != 0) {
      uVar9 = 10;
    }
    *(undefined4 *)(param_1 + 0xdf8) = uVar9;
    break;
  case 10:
    uVar7 = ProcessSsuReplies(param_1,iVar2);
    iVar6 = (int)uVar7;
    if (iVar6 == 1) {
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x80002) != 0)) {
        RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x2d8),0x80002,(undefined1 *)(param_1 + 0x3d40)
                    ,4,iVar2);
      }
      *(undefined4 *)(param_1 + 0xdf8) = 0xd;
      break;
    }
    if (iVar6 != 2) {
      if (iVar6 == 3) {
        *(undefined4 *)(param_1 + 0xdf8) = 0xb;
      }
      break;
    }
LAB_140011941:
    *(undefined4 *)(param_1 + 0xdf8) = 9;
    break;
  case 0xb:
    SendSsuTmrMessagesToDevices(param_1,iVar2);
    *(undefined4 *)(param_1 + 0x3d44) = 100;
    *(undefined4 *)(param_1 + 0xdf8) = 0xc;
    break;
  case 0xc:
    uVar7 = ProcessSsuTmrReplies(param_1,iVar2);
    if ((int)uVar7 - 1U < 2) {
      *(undefined4 *)(param_1 + 0xdf8) = 0xd;
    }
    break;
  case 0xd:
    **(uint **)(param_1 + 0x50) = **(uint **)(param_1 + 0x50) | 0x40000009;
    LOCK();
    UNLOCK();
    *(undefined1 *)(param_1 + 0xdb6) = 1;
    FlushAllDPMPage0(param_1,iVar2);
    *(undefined2 *)(param_1 + 0xdf4) = 0;
    if ((*(uint *)(param_1 + 0xdec) & 0x2000) == 0) {
      *(undefined4 *)(param_1 + 0xdf8) = 0xf;
      KickStart(param_1,iVar2);
    }
    else {
      **(undefined4 **)(param_1 + 0x18) = 0x40000000;
      LOCK();
      UNLOCK();
      *(undefined4 *)(param_1 + 0xdf8) = 0xe;
    }
    break;
  case 0xe:
    if (**(int **)(param_1 + 0x48) < 0) {
      if (**(int **)(param_1 + 0x48) == -1) goto LAB_140011bf1;
      *(short *)(param_1 + 0xdf4) = *(short *)(param_1 + 0xdf4) + 1;
      if (300 < *(ushort *)(param_1 + 0xdf4)) {
        if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x210) != 0)) {
          RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x2d8),0x210,(undefined1 *)(param_1 + 0xd84),
                      4,iVar2);
        }
        KickStart(param_1,iVar2);
      }
    }
    *(undefined4 *)(param_1 + 0xdf8) = 0xf;
    *(undefined2 *)(param_1 + 0xdf4) = 0;
    break;
  case 0xf:
    uVar8 = **(uint **)(param_1 + 0x18) & 0xf0000000;
    if (uVar8 != 0x10000000) {
LAB_140011441:
      if (uVar8 != 0xf0000000) {
        *(short *)(param_1 + 0xdf4) = *(short *)(param_1 + 0xdf4) + 1;
        if (300 < *(ushort *)(param_1 + 0xdf4)) {
          if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x20b) != 0)) {
            RttLogEvent(param_1,pcVar1,(int *)(param_1 + 0x2d8),0x20b,
                        (undefined1 *)(param_1 + 0xd84),4,iVar2);
          }
          KickStart(param_1,iVar2);
          *(undefined2 *)(param_1 + 0xdf4) = 0;
        }
        break;
      }
      goto LAB_140011bf1;
    }
    *(undefined1 *)(*(longlong *)(param_1 + 0x528) + 3) = 1;
    StorPortNotification(0,param_1);
    *(undefined8 *)(param_1 + 0x528) = 0;
LAB_140011b7b:
    *(undefined4 *)(param_1 + 0xdf8) = 0;
  }
  uVar9 = 100000;
  if (*(int *)(param_1 + 0xdf8) == 0) {
    uVar9 = 1000000;
  }
  if (*(int *)(param_1 + 0x57c) != 0) {
    iVar6 = *(int *)(param_1 + 0x57c) + -1;
    uVar9 = 1000000;
    *(int *)(param_1 + 0x57c) = iVar6;
    if (iVar6 == 0) {
      KickStart(param_1,iVar2);
    }
  }
  *(undefined1 *)(param_1 + 0xdf1) = 0;
  uVar7 = StorPortNotification(6,param_1,WatchdogTimer,uVar9);
  *pcVar1 = '\0';
  return CONCAT71((int7)((ulonglong)uVar7 >> 8),1);
}



===== UarStuckAtsTimerCallback @ 140011c40 =====

ulonglong UarStuckAtsTimerCallback
                    (longlong param_1,undefined8 param_2,undefined4 *param_3,int param_4)

{
  ulonglong uVar1;
  
  *param_3 = 3;
  uVar1 = HandleUnitAttenReset
                    (param_1,*(ushort *)(param_3 + 3),(undefined8 *)0x0,*(byte *)(param_3 + 2),
                     *(byte *)((longlong)param_3 + 9),*(char *)((longlong)param_3 + 10),'\0',param_4
                    );
  return uVar1 & 0xffffffffffffff00;
}



===== WatchdogTimer @ 140011c80 =====

void WatchdogTimer(longlong param_1)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  byte bVar4;
  uint uVar5;
  undefined8 in_stack_ffffffffffffffc8;
  uint7 uVar6;
  undefined4 local_18 [2];
  undefined8 local_10;
  
  local_18[0] = 8;
  if (*(int *)(param_1 + 0xdf8) != 0) {
    local_10 = 0;
    StorPortSynchronizeAccess(param_1,SynchronizeRestartRecovery,local_18);
    return;
  }
  if (((*(int *)(param_1 + 0x568) == 0) && (*(longlong *)(param_1 + 0x528) == 0)) &&
     (*(longlong *)(param_1 + 0xfc0 + (ulonglong)*(byte *)(param_1 + 0xebd) * 8) != 0)) {
    StorPortSynchronizeAccess(param_1,SynchronizeHandleOrphanedReset,local_18);
  }
  if (((*(char *)(param_1 + 0xdfe) == '\0') && (*(longlong *)(param_1 + 0xe08) == 0)) &&
     (*(longlong *)(param_1 + 0xec0 + (ulonglong)*(byte *)(param_1 + 0xebb) * 8) != 0)) {
    StorPortSynchronizeAccess(param_1,SynchronizeHandleOrphanedIoctl,local_18);
  }
  if ((*(char *)(param_1 + 0xdb6) != '\0') || (*(char *)(param_1 + 0xdf2) != '\0'))
  goto LAB_140011df7;
  if ((*(int *)(param_1 + 0x578) == 0) ||
     (iVar1 = *(int *)(param_1 + 0x578) + -1, *(int *)(param_1 + 0x578) = iVar1, iVar1 != 0)) {
    if (*(int *)(param_1 + 0x5bc) != 0) {
      local_10 = 0;
      StorPortSynchronizeAccess(param_1,&ProcessSynchronousAction,local_18);
      *(undefined1 *)(param_1 + 0xdf1) = 0;
      goto LAB_140011df7;
    }
    if (*(int *)(param_1 + 0x310) != 0) {
      local_10 = 0;
      StorPortSynchronizeAccess(param_1,GtfProcessTimers,local_18);
    }
    uVar6 = (uint7)((ulonglong)in_stack_ffffffffffffffc8 >> 8);
    if ((*(char *)(param_1 + 0xdfe) != '\0') && (*(int *)(param_1 + 0xe70) != -0x21524111)) {
      uVar5 = *(int *)(param_1 + 0xe70) + 1;
      *(uint *)(param_1 + 0xe70) = uVar5;
      if ((*(longlong *)(param_1 + 0xe08) != 0) &&
         (*(int *)(*(longlong *)(param_1 + 0xe08) + 0x28) + 2U <= uVar5)) {
        StorPortLogError(param_1,0,*(undefined1 *)(param_1 + 0xe00),0,(ulonglong)uVar6 << 8,6,
                         0xad010030);
        *(undefined4 *)(param_1 + 0xe70) = 0xdeadbeef;
        StorPortPause(param_1,300);
        pcVar3 = HandleIoctlTimeout;
        goto LAB_140012175;
      }
    }
    if ((*(int *)(param_1 + 0x574) == 0) ||
       (iVar1 = *(int *)(param_1 + 0x574) + -1, *(int *)(param_1 + 0x574) = iVar1, iVar1 != 0)) {
LAB_140011fc2:
      if ((*(int *)(param_1 + 0xdc8) != 0) &&
         (iVar1 = *(int *)(param_1 + 0xdc8) + -1, *(int *)(param_1 + 0xdc8) = iVar1, iVar1 == 0)) {
        FlushDPMPage0Entry(param_1,8);
      }
      if (**(uint **)(param_1 + 0x18) == 0xffffffff) {
        *(undefined1 *)(param_1 + 0xdb4) = 1;
        if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x234) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x234,
                      (undefined1 *)0x0,0,8);
        }
        CompleteAllSrbs(param_1);
        bVar4 = 0;
        if (*(short *)(param_1 + 0x5a0) == 0) {
          return;
        }
        do {
          StorPortNotification(7,param_1,bVar4);
          bVar4 = bVar4 + 1;
        } while ((ushort)bVar4 < *(ushort *)(param_1 + 0x5a0));
        return;
      }
      uVar5 = **(uint **)(param_1 + 0x18) & 0xf0000000;
      if (uVar5 == 0x20000000) {
LAB_140011df7:
        if (*(char *)(param_1 + 0xdf1) == '\0') {
          StorPortNotification(6,param_1,WatchdogTimer,1000000);
          return;
        }
        if (*(char *)(param_1 + 0x308) == '\0') {
          return;
        }
        if ((*(uint *)(param_1 + 0x30c) & 0x20a) == 0) {
          return;
        }
        RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x20a,
                    (undefined1 *)(param_1 + 0xd84),4,8);
        return;
      }
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x208) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x208,
                    (undefined1 *)0x0,0,8);
      }
      **(uint **)(param_1 + 0x50) = **(uint **)(param_1 + 0x50) | 0x40000009;
      LOCK();
      UNLOCK();
      *(undefined4 *)(param_1 + 0xdf8) = 1;
      if (*(int *)(param_1 + 0x570) == 0) {
        StorPortPause(param_1,400);
      }
      if (uVar5 == 0x40000000) {
        if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x209) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x209,
                      (undefined1 *)(param_1 + 0xd84),4,8);
        }
        if (*(char *)(param_1 + 0xda6) != '\0') {
          *(undefined4 *)(param_1 + 0xdf8) = 8;
        }
        goto LAB_14001215d;
      }
      goto LAB_140012167;
    }
    if (*(char *)(param_1 + 0xda6) == '\0') {
      if (*(int *)(param_1 + 0x568) != 0) {
        StorPortLogError(param_1,0,0,0,(ulonglong)uVar6 << 8,6,0xad010028);
        if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x207) != 0)) {
          RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x207,
                      (undefined1 *)0x0,0,8);
        }
        *(undefined4 *)(param_1 + 0xdf8) = 1;
        goto LAB_14001215d;
      }
      goto LAB_140011fc2;
    }
    *(undefined1 *)(param_1 + 0xda6) = 0;
    uVar2 = 0xd;
    if (*(short *)(param_1 + 0x3d48) != 0) {
      uVar2 = 8;
    }
    *(undefined4 *)(param_1 + 0xdf8) = uVar2;
  }
  else {
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x206) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x206,(undefined1 *)0x0
                  ,0,8);
    }
    *(undefined1 *)(param_1 + 0xdb0) = 1;
    *(undefined4 *)(param_1 + 0xdf8) = 1;
LAB_14001215d:
    KickStart(param_1,8);
LAB_140012167:
    *(undefined2 *)(param_1 + 0xdf4) = 0;
  }
  pcVar3 = SynchronizeRestartRecovery;
LAB_140012175:
  local_10 = 0;
  StorPortSynchronizeAccess(param_1,pcVar3,local_18);
  return;
}



===== ZeroMemory @ 1400121c0 =====

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



===== FillInPortInfo @ 1400121e0 =====

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



===== HbaApiWmiCompletion @ 1400122c0 =====

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
  uint *puVar10;
  char cVar11;
  ushort local_res18 [8];
  ushort *in_stack_ffffffffffffffc8;
  
  uVar3 = *(undefined2 *)(param_2 + 0xe);
  cVar11 = '\x01';
  lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x2a0) + 8 + (ulonglong)param_3 * 0x18);
  local_res18[0] = param_3;
  if (lVar5 == 0) {
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x211) != 0)) {
      in_stack_ffffffffffffffc8 = local_res18;
      RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x211,
                  (undefined1 *)in_stack_ffffffffffffffc8,2,param_4);
    }
    uVar8 = StorPortLogError(param_1,0,0,0,(ulonglong)in_stack_ffffffffffffffc8 & 0xffffffffffffff00
                             ,6,0xad010024);
    return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
  }
  lVar6 = *(longlong *)(lVar5 + 0x68);
  iVar4 = *(int *)(lVar6 + 0x34);
  puVar1 = (undefined8 *)(lVar6 + 8);
  *(ulonglong *)(lVar6 + 0x28) = *(longlong *)(param_1 + 0x2a0) + (ulonglong)param_3 * 0x18;
  bVar2 = *(byte *)(lVar6 + 0x30);
  *(undefined2 *)(lVar6 + 0x32) = uVar3;
  if (bVar2 == 8) {
    puVar10 = (uint *)*puVar1;
    if (iVar4 != 2) {
      ProcessSASPortInfo(param_1,(int *)puVar10,lVar5);
      uVar7 = 0x1730;
      if (iVar4 == 1) {
        uVar7 = 8;
      }
      goto LAB_14001242b;
    }
  }
  else {
    if ((bVar2 < 9) || ((10 < bVar2 && (bVar2 != 0xb)))) {
      uVar7 = 0;
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x212) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x212,
                    (undefined1 *)0x0,0,param_4);
      }
      cVar11 = '\x04';
      goto LAB_14001242b;
    }
    puVar10 = (uint *)*puVar1;
  }
  uVar9 = ProcessSASPortAttributes(param_1,puVar10,lVar5,param_4);
  if ((char)uVar9 == '\0') {
    return uVar9 & 0xffffffffffffff00;
  }
  uVar7 = 0x23c;
LAB_14001242b:
  ScsiPortWmiPostProcess((longlong)puVar1,cVar11,uVar7);
  *(undefined4 *)(lVar5 + 0x3c) = *(undefined4 *)(lVar6 + 0x24);
  *(undefined1 *)(lVar5 + 3) = *(undefined1 *)(lVar6 + 0x21);
  uVar8 = StorPortNotification(0,param_1,lVar5);
  return CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
}



===== LSIWmiGetAdapHbaAttributes @ 140012470 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

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
  uint uVar12;
  undefined1 auStackY_118 [32];
  byte local_c0 [16];
  byte local_b0 [24];
  byte local_98 [80];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_118;
  lVar4 = *(longlong *)(param_1 + 0x1500);
  lVar5 = *(longlong *)(param_3 + 0x68);
  uVar6 = *(undefined8 *)(param_1 + 0x1474);
  VersionToStr(*(uint *)(param_1 + 0xd5c),(char *)local_b0);
  VersionToStr(*(uint *)(param_1 + 0xd58),(char *)local_c0);
  *(undefined4 *)(param_2 + 1) = 0;
  *param_2 = uVar6;
  *(int *)(param_2 + 2) = *(int *)(param_1 + 0xd44) * 0x10000 + *(int *)(param_1 + 0xd50);
  *(uint *)((longlong)param_2 + 0xc) = (uint)*(ushort *)(param_1 + 0x596);
  ZeroMemory((undefined1 *)((longlong)param_2 + 0x14),0x82);
  *(undefined2 *)((longlong)param_2 + 0x14) = 0x80;
  uVar11 = 0;
  do {
    if (0x3f < uVar11) break;
    uVar7 = (ulonglong)uVar11;
    uVar11 = uVar11 + 1;
    *(ushort *)((longlong)param_2 + uVar7 * 2 + 0x16) = (ushort)(byte)"LSI Corporation"[uVar7];
  } while ("LSI Corporation"[uVar11] != '\0');
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
  uVar7 = 0;
  do {
    if ((uint)(ushort)(&ChipIds)[uVar7] == *(uint *)(param_1 + 0xd44)) {
      pcVar10 = *(char **)(&BoardDesc + uVar7 * 8);
      if (pcVar10 != (char *)0x0) goto LAB_14001266f;
      break;
    }
    bVar9 = (char)uVar7 + 1;
    uVar7 = (ulonglong)bVar9;
  } while (bVar9 < 7);
  pcVar10 = NoDesc;
LAB_14001266f:
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
  memcpy(local_98,&s_LSI_,4);
  memcpy(local_98 + 4,(void *)(lVar4 + 0x1c),(ulonglong)bVar8);
  memcpy(local_98 + (byte)(bVar8 + 4),&s__FV,3);
  memcpy(local_98 + (byte)(bVar8 + 7),local_c0,0xb);
  memcpy(local_98 + (byte)(bVar8 + 0x12),&s__DV,3);
  uVar12 = 0;
  do {
    bVar9 = (&driver_version)[uVar12 + 9];
    local_98[(byte)(bVar8 + 0x15) + uVar12] = bVar9;
    if (bVar9 == 0) break;
    bVar9 = (char)uVar12 + 1;
    uVar12 = (uint)bVar9;
  } while (bVar9 < 0x50);
  ZeroMemory((undefined1 *)((longlong)param_2 + 0xf26),0x202);
  uVar11 = 0;
  *(undefined2 *)((longlong)param_2 + 0xf26) = 0x200;
  while ((local_98[0] != 0 && (uVar11 < 0x100))) {
    uVar7 = (ulonglong)uVar11;
    uVar11 = uVar11 + 1;
    *(ushort *)((longlong)param_2 + uVar7 * 2 + 0xf28) = (ushort)local_98[uVar7];
    local_98[0] = local_98[uVar11];
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
  cVar2 = DAT_14001b109;
  while ((cVar2 != '\0' && (uVar11 < 0x100))) {
    uVar7 = (ulonglong)uVar11;
    uVar11 = uVar11 + 1;
    *(ushort *)((longlong)param_2 + uVar7 * 2 + 0x720) = (ushort)(byte)(&DAT_14001b109)[uVar7];
    cVar2 = (&DAT_14001b109)[uVar11];
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
    *(ushort *)((longlong)param_2 + uVar7 * 2 + 0xd26) = (ushort)(byte)"lsi_sas2"[uVar7];
  } while ("lsi_sas2"[uVar11] != '\0');
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
  *(undefined1 *)(lVar5 + 0x30) = 8;
  *(undefined8 **)(lVar5 + 8) = param_2;
  uVar6 = SendHbaApiConfigMessage
                    (param_1,param_3,'\x01',(undefined4 *)(param_1 + 0x1594),0,
                     (int)*(undefined8 *)(param_1 + 0x15c0),param_4);
  return (char)uVar6 != '\0';
}



===== LSImpiExecuteWmiMethod @ 140012a60 =====

ulonglong LSImpiExecuteWmiMethod
                    (longlong param_1,longlong *param_2,int param_3,undefined8 param_4,int param_5,
                    uint param_6,uint param_7,int *param_8)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  byte bVar4;
  uint uVar5;
  
  lVar1 = *param_2;
  bVar4 = 1;
  *(int *)(*(longlong *)(lVar1 + 0x68) + 0x34) = param_5;
  uVar5 = 0;
  if (param_3 != 2) {
    bVar4 = 4;
    goto LAB_140012a8e;
  }
  if (param_5 == 1) {
    uVar5 = 8;
LAB_140012b18:
    uVar2 = uVar5;
    if (uVar5 <= param_7) {
      uVar3 = LsiWmiGetSASPortInfo(param_1,param_8,lVar1,0xe);
      if ((char)uVar3 != '\0') {
        return uVar3 & 0xffffffffffffff00;
      }
      goto LAB_140012a8e;
    }
  }
  else {
    if (param_5 == 2) {
      uVar5 = 0x23c;
      goto LAB_140012b18;
    }
    if (param_5 != 4) {
      if (param_5 != 10) {
        *param_8 = 2;
        uVar5 = param_6;
      }
      goto LAB_140012a8e;
    }
    uVar5 = 0x23c;
    uVar2 = 0x23c;
    if (0x23b < param_7) {
      uVar3 = LsiWmiGetSASPortInfoByWWN(param_1,param_8,lVar1,0xe);
      if ((char)uVar3 != '\0') {
        return uVar3 & 0xffffffffffffff00;
      }
      goto LAB_140012a8e;
    }
  }
  uVar5 = uVar2;
  bVar4 = 0x12;
LAB_140012a8e:
  ScsiPortWmiPostProcess((longlong)param_2,bVar4,uVar5);
  return (ulonglong)bVar4;
}



===== LSImpiFunctionControl @ 140012b60 =====

undefined8
LSImpiFunctionControl(longlong param_1,longlong param_2,int param_3,int param_4,char param_5)

{
  undefined8 uVar1;
  
  if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x402) != 0)) {
    RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x402,(undefined1 *)0x0,0
                ,0xf);
  }
  if ((param_4 == 0) && (param_3 == 0)) {
    if (param_5 == '\0') {
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x103) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x103,
                    (undefined1 *)0x0,0,0xf);
      }
      *(undefined1 *)(param_1 + 0x14b1) = 0;
    }
    else {
      if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x102) != 0)) {
        RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x102,
                    (undefined1 *)0x0,0,0xf);
      }
      *(undefined1 *)(param_1 + 0x14b1) = 1;
    }
  }
  uVar1 = ScsiPortWmiPostProcess(param_2,'\x01',0);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== LSImpiQueryWmiDataBlock @ 140012ca0 =====

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
  *(undefined4 *)(*(longlong *)(lVar1 + 0x68) + 0x34) = 0;
  if (param_3 == 0) {
LAB_140012d12:
    uVar4 = 4;
    uVar2 = 4;
    if (3 < param_7) {
      *param_6 = 4;
      goto LAB_140012d29;
    }
  }
  else {
    if (param_3 != 1) {
      if (param_3 != 2) {
        bVar5 = 4;
        goto LAB_140012d29;
      }
      goto LAB_140012d12;
    }
    uVar4 = 0x1730;
    uVar2 = 0x1730;
    if (0x172f < param_7) {
      *param_6 = 0x1730;
      bVar3 = LSIWmiGetAdapHbaAttributes(param_1,param_8,lVar1,0xb);
      if (bVar3) {
        return (ulonglong)extraout_var << 8;
      }
      goto LAB_140012d29;
    }
  }
  uVar4 = uVar2;
  bVar5 = 0x12;
LAB_140012d29:
  ScsiPortWmiPostProcess((longlong)param_2,bVar5,uVar4);
  return (ulonglong)bVar5;
}



===== LSImpiWmiInitialize @ 140012d60 =====

void LSImpiWmiInitialize(longlong param_1)

{
  *(undefined4 *)(param_1 + 0x158) = 3;
  *(undefined ***)(param_1 + 0x160) = &LSImpiSasGuidList;
  *(undefined1 **)(param_1 + 0x168) = &LSImpiQueryWmiRegInfo;
  *(code **)(param_1 + 0x170) = LSImpiQueryWmiDataBlock;
  *(code **)(param_1 + 400) = LSImpiFunctionControl;
  *(code **)(param_1 + 0x188) = LSImpiExecuteWmiMethod;
  *(undefined8 *)(param_1 + 0x180) = 0;
  *(undefined8 *)(param_1 + 0x178) = 0;
  return;
}



===== LSImpiWmiSrb @ 140012dd0 =====

undefined8 LSImpiWmiSrb(longlong param_1,ushort *param_2,int param_3)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  int *piVar4;
  uint uVar5;
  ulonglong uVar6;
  int *piVar7;
  ushort *in_stack_ffffffffffffffd8;
  
  lVar2 = *(longlong *)(param_2 + 0x34);
  piVar7 = (int *)0x0;
  uVar6 = 0;
  if (*(int *)(param_2 + 0x1c) == 0) {
LAB_140012e8b:
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x22f) != 0)) {
      in_stack_ffffffffffffffd8 = param_2;
      RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x22f,
                  (undefined1 *)param_2,(uint)*param_2,param_3);
    }
    StorPortLogError(param_1,0,0,0,(ulonglong)in_stack_ffffffffffffffd8 & 0xffffffffffffff00,6,
                     0xad010056);
    *(undefined1 *)((longlong)param_2 + 3) = 4;
LAB_140012ef5:
    param_2[0x1e] = 0;
    param_2[0x1f] = 0;
  }
  else {
    do {
      piVar4 = (int *)((ulonglong)*(uint *)(param_2 + uVar6 * 2 + 0x3c) + (longlong)param_2);
      if (*piVar4 == 0x60) {
        *(int **)(lVar2 + 0x48) = piVar4;
        piVar7 = piVar4;
      }
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < *(uint *)(param_2 + 0x1c));
    if (piVar7 == (int *)0x0) goto LAB_140012e8b;
    if ((*(byte *)((longlong)piVar7 + 9) & 1) == 0) {
      *(undefined1 *)((longlong)param_2 + 3) = 1;
      goto LAB_140012ef5;
    }
    *(ushort **)(lVar2 + 8) = param_2;
    *(undefined8 *)(lVar2 + 0x28) = 0;
    uVar3 = ScsiPortWmiDispatchFunction
                      ((uint *)(param_1 + 0x158),*(byte *)(piVar7 + 2),param_1,lVar2 + 8,
                       *(ulonglong **)(piVar7 + 4),*(uint *)(param_2 + 0x1e),
                       *(uint **)(param_2 + 0x20));
    if ((char)uVar3 != '\0') goto LAB_140012f0a;
    uVar1 = *(undefined4 *)(lVar2 + 0x24);
    *(undefined1 *)((longlong)param_2 + 3) = *(undefined1 *)(lVar2 + 0x21);
    *(undefined4 *)(param_2 + 0x1e) = uVar1;
  }
  uVar3 = StorPortNotification(0,param_1,param_2);
LAB_140012f0a:
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== LsiWmiGetSASPortInfo @ 140012f20 =====

ulonglong LsiWmiGetSASPortInfo(longlong param_1,undefined4 *param_2,longlong param_3,int param_4)

{
  ulonglong uVar1;
  undefined8 uVar2;
  
  uVar1 = *(ulonglong *)(param_3 + 0x68);
  if ((*(int *)(uVar1 + 0x34) == 2) && ((uint)param_2[1] < 0x1c)) {
    *param_2 = 4;
    return uVar1 & 0xffffffffffffff00;
  }
  *(undefined1 *)(uVar1 + 0x30) = 8;
  *(undefined4 **)(uVar1 + 8) = param_2;
  uVar2 = SendHbaApiConfigMessage
                    (param_1,param_3,'\x01',(undefined4 *)(param_1 + 0x1594),0,
                     (int)*(undefined8 *)(param_1 + 0x15c0),param_4);
  if ((char)uVar2 == '\0') {
    *param_2 = 10;
    return uVar2;
  }
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== LsiWmiGetSASPortInfoByWWN @ 140012fa0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong LsiWmiGetSASPortInfoByWWN(longlong param_1,int *param_2,longlong param_3,int param_4)

{
  char cVar1;
  longlong lVar2;
  byte bVar3;
  ulonglong uVar4;
  byte bVar5;
  int iVar6;
  char cVar7;
  undefined4 *puVar8;
  undefined1 auStackY_78 [32];
  undefined4 uVar9;
  char local_38 [5];
  char acStack_33 [3];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_78;
  lVar2 = *(longlong *)(param_3 + 0x68);
  if ((uint)param_2[4] < 0x1c) {
    *param_2 = 4;
    local_30 = local_30 & 0xffffffffffffff00;
  }
  else {
    memcpy(local_38,param_2,8);
    acStack_33[2] = acStack_33[2] & 0xf0;
    uVar4 = 0;
    do {
      bVar5 = (byte)uVar4;
      if (local_38[7 - (int)uVar4] != *(char *)(uVar4 + 0x1474 + param_1)) break;
      bVar5 = bVar5 + 1;
      uVar4 = (ulonglong)bVar5;
    } while (bVar5 < 8);
    if ((bVar5 == 8) && (*(char *)(*(longlong *)(param_1 + 0x15c0) + 0xc) != '\0')) {
      iVar6 = 0;
      bVar5 = *(byte *)((longlong)param_2 + 7) & 0xf;
      if (bVar5 != 0) {
        cVar7 = '\0';
        uVar4 = 0;
        do {
          cVar1 = *(char *)(*(longlong *)(param_1 + 0x15c0) + 0x10 + uVar4 * 0x14);
          if (cVar1 != cVar7) {
            iVar6 = iVar6 + 1;
            cVar7 = cVar1;
          }
          bVar3 = (char)uVar4 + 1;
          uVar4 = (ulonglong)bVar3;
        } while (bVar3 <= bVar5);
      }
      param_2[1] = param_2[4];
      *param_2 = iVar6;
      *(undefined4 *)(lVar2 + 0x34) = 2;
      uVar4 = *(ulonglong *)(param_3 + 0x68);
      if ((*(int *)(uVar4 + 0x34) == 2) && ((uint)param_2[1] < 0x1c)) {
        *param_2 = 4;
        return uVar4 & 0xffffffffffffff00;
      }
      puVar8 = (undefined4 *)(param_1 + 0x1594);
      *(undefined1 *)(uVar4 + 0x30) = 8;
      *(int **)(uVar4 + 8) = param_2;
      iVar6 = (int)*(undefined8 *)(param_1 + 0x15c0);
      uVar9 = 0;
    }
    else {
      puVar8 = (undefined4 *)(param_1 + 0x1530);
      *(undefined1 *)(lVar2 + 0x30) = 0xb;
      *(int **)(lVar2 + 8) = param_2;
      iVar6 = (int)*(undefined8 *)(param_1 + 0x1538);
      uVar9 = 0xffff;
    }
    local_30 = SendHbaApiConfigMessage(param_1,param_3,'\x01',puVar8,uVar9,iVar6,param_4);
    if ((char)local_30 == '\0') {
      *param_2 = 10;
    }
    else {
      local_30 = CONCAT71((int7)(local_30 >> 8),1);
    }
  }
  return local_30;
}



===== ProcessSASPortAttributes @ 140013130 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 ProcessSASPortAttributes(longlong param_1,uint *param_2,longlong param_3,int param_4)

{
  longlong lVar1;
  byte *pbVar2;
  short sVar3;
  int iVar4;
  longlong lVar5;
  char cVar6;
  uint7 uVar9;
  undefined8 uVar7;
  ulonglong uVar8;
  uint uVar10;
  byte bVar11;
  byte bVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  undefined1 auStackY_188 [32];
  longlong lVar15;
  int local_148 [2];
  longlong alStack_140 [31];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_188;
  lVar15 = *(longlong *)(param_3 + 0x68);
  bVar11 = *(byte *)(lVar15 + 0x30);
  sVar3 = *(short *)(lVar15 + 0x32);
  uVar9 = (uint7)(byte)((ushort)sVar3 >> 8);
  if (bVar11 == 8) {
    lVar5 = *(longlong *)(param_1 + 0x15c0);
    uVar13 = (ulonglong)*param_2;
    bVar11 = *(byte *)(lVar5 + 0xc);
    if (sVar3 == 0) {
      memset(local_148,0,0x100);
      uVar14 = 0;
      if (bVar11 != 0) {
        do {
          lVar1 = uVar14 * 5 + 4;
          uVar8 = 0;
          pbVar2 = (byte *)(lVar5 + lVar1 * 4);
          if ((*(byte *)(lVar5 + 1 + lVar1 * 4) & 4) != 0) goto LAB_140013263;
          if (*(short *)(pbVar2 + 8) != 0) {
            uVar8 = (ulonglong)*pbVar2;
            local_148[uVar8 * 4] = local_148[uVar8 * 4] + 1;
            if (alStack_140[uVar8 * 2] == 0) {
              alStack_140[uVar8 * 2] = (longlong)pbVar2;
            }
          }
          bVar12 = (char)uVar14 + 1;
          uVar14 = (ulonglong)bVar12;
        } while (bVar12 < bVar11);
      }
      iVar4 = local_148[uVar13 * 4];
      if (iVar4 == 0) {
        *param_2 = 6;
        return CONCAT71((int7)(uVar13 * 0x10 >> 8),1);
      }
      lVar5 = alStack_140[uVar13 * 2];
      switch(*(byte *)(lVar5 + 3) & 0xf) {
      default:
        param_2[3] = 6;
        break;
      case 8:
      case 9:
      case 10:
      case 0xb:
        param_2[3] = 2;
      }
      FillInPortInfo(param_2 + 2,*(uint *)(lVar5 + 4),iVar4);
      *param_2 = (uint)*(ushort *)(lVar5 + 8);
      *(undefined1 *)(lVar15 + 0x30) = 9;
      uVar8 = SendHbaApiConfigMessage
                        (param_1,param_3,'\x01',(undefined4 *)(param_1 + 0x1530),
                         *(ushort *)(lVar5 + 10) | 0x20000000,(int)*(undefined8 *)(param_1 + 0x1538)
                         ,param_4);
      cVar6 = (char)uVar8;
joined_r0x000140013432:
      if (cVar6 != '\0') {
        return uVar8 & 0xffffffffffffff00;
      }
LAB_140013263:
      *param_2 = 10;
      return CONCAT71((int7)(uVar8 >> 8),1);
    }
  }
  else if (8 < bVar11) {
    if (bVar11 < 0xb) {
      lVar5 = *(longlong *)(param_1 + 0x1538);
      if (bVar11 != 9) {
        *param_2 = 0;
        if (sVar3 == 0x22) {
          uVar7 = ZeroMemory((undefined1 *)(param_2 + 0x8b),8);
          param_2[0x8d] = 0;
          return CONCAT71((int7)((ulonglong)uVar7 >> 8),1);
        }
        if (sVar3 == 0) {
          uVar7 = SwapNodeName(lVar5 + 0xc,(undefined1 *)(param_2 + 0x8b));
          param_2[0x8d] = 1;
          return CONCAT71((int7)((ulonglong)uVar7 >> 8),1);
        }
        *param_2 = 1;
        return CONCAT71(uVar9,1);
      }
      if (sVar3 == 0) {
        SwapNodeName(lVar5 + 0xc,(undefined1 *)(param_2 + 0x89));
        *(undefined1 *)(lVar15 + 0x30) = 10;
        lVar15 = *(longlong *)(param_1 + 0x1538);
        uVar10 = *param_2 + 0x20000000;
LAB_140013246:
        uVar8 = SendHbaApiConfigMessage
                          (param_1,param_3,'\x01',(undefined4 *)(param_1 + 0x1530),uVar10,
                           (int)lVar15,param_4);
        cVar6 = (char)uVar8;
        goto joined_r0x000140013432;
      }
    }
    else if (bVar11 == 0xb) {
      lVar15 = *(longlong *)(param_1 + 0x1538);
      if (sVar3 == 0x22) {
        *param_2 = 5;
        return 1;
      }
      if (sVar3 == 0) {
        uVar13 = 0;
        do {
          if (*(char *)((longlong)(7 - (int)uVar13) + 0xc + lVar15) !=
              *(char *)(uVar13 + (longlong)param_2)) {
            if ((byte)uVar13 < 8) {
              uVar10 = (uint)*(ushort *)(lVar15 + 0x18);
              goto LAB_140013246;
            }
            break;
          }
          bVar11 = (byte)uVar13 + 1;
          uVar13 = (ulonglong)bVar11;
        } while (bVar11 < 8);
        memcpy(param_2 + 0x89,param_2,8);
        FillInPortInfo(param_2 + 2,*(uint *)(lVar15 + 0x1c),1);
        uVar7 = ZeroMemory((undefined1 *)(param_2 + 0x8b),8);
        param_2[0x8d] = 0;
        *param_2 = 0;
        return CONCAT71((int7)((ulonglong)uVar7 >> 8),1);
      }
    }
  }
  *param_2 = 1;
  return CONCAT71(uVar9,1);
}



===== ProcessSASPortInfo @ 1400134a0 =====

void ProcessSASPortInfo(longlong param_1,int *param_2,longlong param_3)

{
  char cVar1;
  short sVar2;
  longlong lVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  longlong lVar7;
  byte bVar8;
  byte *pbVar9;
  int iVar10;
  ulonglong uVar11;
  char cVar12;
  uint uVar13;
  
  uVar13 = 0;
  lVar3 = *(longlong *)(param_1 + 0x15c0);
  uVar6 = 0;
  bVar5 = *(byte *)(lVar3 + 0xc);
  sVar2 = *(short *)(*(longlong *)(param_3 + 0x68) + 0x32);
  if (*(int *)(*(longlong *)(param_3 + 0x68) + 0x34) == 1) {
    if (sVar2 == 0) {
      cVar12 = *(char *)(lVar3 + 0x10);
      lVar7 = lVar3 + 0x10;
      iVar10 = 0;
      uVar11 = 0;
      bVar8 = 0;
      if (bVar5 != 0) {
        do {
          bVar8 = (byte)uVar11;
          lVar7 = uVar11 * 5 + 4;
          cVar1 = *(char *)(lVar3 + lVar7 * 4);
          lVar7 = lVar3 + lVar7 * 4;
          if (cVar1 != cVar12) {
            iVar10 = iVar10 + 1;
            cVar12 = cVar1;
          }
          if (*param_2 == iVar10) break;
          bVar8 = bVar8 + 1;
          uVar11 = (ulonglong)bVar8;
        } while (bVar8 < bVar5);
      }
      if (bVar8 == bVar5) {
        *param_2 = 6;
        return;
      }
      *param_2 = 0;
      iVar10 = 3;
      uVar6 = *(uint *)(lVar7 + 4);
      bVar5 = (byte)uVar6 & 7;
      if (bVar5 == 1) {
        if ((uVar6 & 0x660) != 0) {
          param_2[1] = 0x1e;
          return;
        }
        if ((uVar6 & 0x88) != 0) {
          param_2[1] = 0x1f;
          return;
        }
      }
      else if (((byte)(bVar5 - 2) < 2) && (iVar10 = 3, (uVar6 & 0x110) != 0)) {
        iVar10 = 0x20;
      }
      param_2[1] = iVar10;
      return;
    }
    *param_2 = 1;
  }
  else if (sVar2 == 0) {
    if (bVar5 != 0) {
      pbVar9 = (byte *)(lVar3 + 0x10);
      uVar11 = (ulonglong)bVar5;
      do {
        bVar5 = *pbVar9;
        pbVar9 = pbVar9 + 0x14;
        uVar6 = uVar6 & 0xff | 1 << (bVar5 & 0x1f);
        uVar11 = uVar11 - 1;
      } while (uVar11 != 0);
    }
    bVar5 = 0;
    do {
      bVar8 = bVar5 + 1;
      uVar4 = uVar13 + 1;
      if ((1 << (bVar5 & 0x1f) & uVar6 & 0xff) == 0) {
        uVar4 = uVar13;
      }
      uVar13 = uVar4 & 0xff;
      bVar5 = bVar8;
    } while (bVar8 < 8);
    param_2[3] = uVar4 & 0xff;
    return;
  }
  return;
}



===== SendHbaApiConfigMessage @ 140013620 =====

ulonglong SendHbaApiConfigMessage
                    (longlong param_1,longlong param_2,char param_3,undefined4 *param_4,
                    undefined4 param_5,int param_6,int param_7)

{
  ushort uVar1;
  ushort uVar2;
  longlong *plVar3;
  char *pcVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  
  puVar7 = *(undefined8 **)(*(longlong *)(param_2 + 0x68) + 0x28);
  if (puVar7 == (undefined8 *)0x0) {
    plVar3 = *(longlong **)(param_1 + 0x510);
    puVar7 = (undefined8 *)*plVar3;
    if (puVar7[1] != 0) {
      return (ulonglong)plVar3 & 0xffffffffffffff00;
    }
    *(longlong **)(param_1 + 0x510) = plVar3 + 1;
    if (plVar3 + 1 == *(longlong **)(param_1 + 0x520)) {
      *(undefined8 *)(param_1 + 0x510) = *(undefined8 *)(param_1 + 0x508);
    }
  }
  pcVar4 = (char *)*puVar7;
  puVar7[1] = param_2;
  uVar1 = *(ushort *)(puVar7 + 2);
  ZeroMemory(pcVar4,0x2c);
  *pcVar4 = param_3;
  pcVar4[3] = '\x04';
  *(undefined1 *)((longlong)puVar7 + 0x13) = 8;
  *(undefined4 *)(pcVar4 + 0x14) = *param_4;
  uVar5 = (uint)*(byte *)((longlong)param_4 + 1);
  *(undefined4 *)(pcVar4 + 0x18) = param_5;
  if ((pcVar4[0x17] & 0xfU) == 0xf) {
    uVar2 = *(ushort *)(param_4 + 1);
    *(ushort *)(pcVar4 + 4) = uVar2;
    uVar5 = (uint)uVar2;
    pcVar4[6] = *(char *)((longlong)param_4 + 6);
  }
  pcVar4[0x1c] = '\0';
  pcVar4[0x1d] = '\0';
  pcVar4[0x1e] = '\0';
  pcVar4[0x1f] = -0x2d;
  *(int *)(pcVar4 + 0x20) = param_6 - *(int *)(param_1 + 0x100);
  *(undefined4 *)(pcVar4 + 0x24) = *(undefined4 *)(param_1 + 0x1ec);
  *(uint *)(pcVar4 + 0x1c) = uVar5 * 4 | 0xd3000000;
  if (param_3 == '\x02') {
    *(uint *)(pcVar4 + 0x1c) = uVar5 * 4 | 0xd7000000;
  }
  uVar6 = QueueRequestDescriptor(param_1,(uint)uVar1 * 0x10000 + 8,0,param_7);
  return CONCAT71((int7)((ulonglong)uVar6 >> 8),1);
}



===== SwapNodeName @ 140013760 =====

void SwapNodeName(longlong param_1,undefined1 *param_2)

{
  byte bVar1;
  byte bVar2;
  
  bVar1 = 0;
  do {
    bVar2 = bVar1 + 1;
    *param_2 = *(undefined1 *)((int)(7 - (uint)bVar1) + param_1);
    bVar1 = bVar2;
    param_2 = param_2 + 1;
  } while (bVar2 < 8);
  return;
}



===== VersionToStr @ 1400137a0 =====

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



===== CsmiCheckOutstandingTaskMgmt @ 1400138d0 =====

bool CsmiCheckOutstandingTaskMgmt(longlong param_1,int param_2)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  bool bVar5;
  
  if ((*(uint *)(param_1 + 0x1588) & 1) == 0) {
    return true;
  }
  lVar1 = *(longlong *)(param_1 + 0x1580);
  *(undefined4 *)(param_1 + 0x1588) = 0;
  *(undefined2 *)(param_1 + 0x158c) = 0;
  *(undefined8 *)(param_1 + 0x1580) = 0;
  lVar2 = *(longlong *)(lVar1 + 0x40);
  if (*(int *)(lVar2 + 0x10) == 0x1d) {
    *(undefined4 *)(lVar2 + 0x14) = 1;
  }
  *(undefined1 *)(lVar1 + 3) = 1;
  StorPortNotification(0,param_1);
  uVar3 = IssueReset(param_1,0x40);
  if ((char)uVar3 == '\0') {
    uVar4 = KickStart(param_1,param_2);
    bVar5 = (char)uVar4 != '\0';
  }
  else {
    bVar5 = true;
  }
  return bVar5;
}



===== CsmiDispatchStateMachine @ 1400139a0 =====

ulonglong CsmiDispatchStateMachine(longlong param_1,char *param_2,int param_3)

{
  ulonglong in_RAX;
  ulonglong uVar1;
  undefined8 uVar2;
  
  uVar1 = in_RAX & 0xffffffffffffff00;
  if (*(char *)(param_1 + 0x15fa) != '\0') {
    uVar1 = CsmiSasSendSmpPassThrough_sm(param_1,param_2,param_3);
    return uVar1;
  }
  if (*(char *)(param_1 + 0x15fb) != '\0') {
    uVar1 = CsmiSasSendSspPassThrough_sm(param_1,(longlong)param_2,param_3);
    return uVar1;
  }
  if (*(char *)(param_1 + 0x15fc) != '\0') {
    uVar1 = CsmiSasSendStpPassThrough_sm(param_1,(longlong)param_2,param_3);
    return uVar1;
  }
  if (*(char *)(param_1 + 0x15fd) != '\0') {
    uVar1 = CsmiSasFirmwareDownload_sm(param_1,(longlong)param_2,param_3);
    return uVar1;
  }
  if (*(char *)(param_1 + 0x15fe) != '\0') {
    uVar2 = CsmiSasGetPhyInfo_sm(param_1,param_3);
    return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
  }
  if (*(char *)(param_1 + 0x1600) != '\0') {
    uVar2 = CsmiSasSetPhyInfo_sm(param_1,param_3);
    return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
  }
  if (*(char *)(param_1 + 0x1601) != '\0') {
    *(undefined2 *)(param_1 + 0x15f8) = *(undefined2 *)(param_2 + 0xe);
    uVar2 = CsmiSasGetLinkErrors_sm(param_1,param_3);
    return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
  }
  if (*(char *)(param_1 + 0x1602) != '\0') {
    uVar2 = CsmiSasGetSataSignature_sm(param_1,param_3);
    return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
  }
  if (*(char *)(param_1 + 0x1603) != '\0') {
    uVar2 = CsmiSasGetDeviceAddress_sm(param_1,param_3);
    return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
  }
  if (*(char *)(param_1 + 0x15ff) != '\0') {
    uVar2 = CsmiSasGetConnectorInfo_sm(param_1,param_3);
    return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
  }
  if (*(char *)(param_1 + 0x1606) != '\0') {
    *(undefined2 *)(param_1 + 0x15f8) = *(undefined2 *)(param_2 + 0xe);
    uVar2 = CsmiSasPhyControl_sm(param_1,param_3);
    return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
  }
  if (*(char *)(param_1 + 0x1607) != '\0') {
    uVar2 = CsmiSasGetLocation_sm(param_1,param_3);
    uVar1 = CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
  }
  return uVar1;
}



===== CsmiFindAbortSmid @ 140013ad0 =====

ulonglong CsmiFindAbortSmid(longlong param_1,uint *param_2)

{
  longlong lVar1;
  undefined2 uVar2;
  ulonglong uVar3;
  ulonglong in_RAX;
  ulonglong uVar4;
  int iVar5;
  uint uVar6;
  
  *(undefined1 *)(param_1 + 0xdb9) = 1;
  if (*(ushort *)(param_1 + 0x594) == 0) {
    *(undefined1 *)(param_1 + 0xdb9) = 0;
    return in_RAX & 0xffffffffffffff00;
  }
  uVar3 = 0;
  while( true ) {
    uVar4 = uVar3;
    iVar5 = (int)uVar4;
    lVar1 = *(longlong *)(param_1 + 0x2a0) + uVar4 * 0x18;
    if ((*(longlong *)(*(longlong *)(param_1 + 0x2a0) + 8 + uVar4 * 0x18) != 0) &&
       (uVar4 = (ulonglong)*param_2, *(uint *)(lVar1 + 0x14) == *param_2)) break;
    uVar6 = iVar5 + 1;
    uVar3 = (ulonglong)uVar6;
    if (*(ushort *)(param_1 + 0x594) <= uVar6) {
      *(undefined1 *)(param_1 + 0xdb9) = 0;
      return uVar4 & 0xffffffffffffff00;
    }
  }
  uVar2 = *(undefined2 *)(lVar1 + 0x10);
  *(undefined2 *)(param_2 + 1) = uVar2;
  *(undefined1 *)(param_1 + 0xdb9) = 0;
  return CONCAT71((uint7)(byte)((ushort)uVar2 >> 8),1);
}



===== CsmiIdleAllStateMachines @ 140013b60 =====

void CsmiIdleAllStateMachines(longlong param_1)

{
  *(undefined8 *)(param_1 + 0x15fa) = 0;
  *(undefined4 *)(param_1 + 0x1602) = 0;
  *(undefined2 *)(param_1 + 0x1606) = 0;
  *(undefined1 *)(param_1 + 0x1608) = 0;
  *(undefined8 *)(param_1 + 0x15f0) = 0;
  return;
}



===== CsmiInitiateIoctlRequest @ 140013ba0 =====

undefined1 CsmiInitiateIoctlRequest(longlong param_1,char *param_2,int param_3)

{
  ushort uVar1;
  undefined1 *_Src;
  longlong lVar2;
  char cVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  byte bVar6;
  ulonglong uVar7;
  undefined1 uVar8;
  
  _Src = *(undefined1 **)(param_1 + 0xe08);
  uVar8 = 1;
  lVar2 = *(longlong *)(_Src + 0x40);
  if (*(int *)(param_1 + 0xd50) == 0x1590) {
    *(undefined4 *)(lVar2 + 0x14) = 0;
    *param_2 = '\x01';
    memcpy((void *)(param_1 + 0xe18),_Src,0x40);
    *(undefined1 *)(param_1 + 0xe00) = *(undefined1 *)(*(longlong *)(_Src + 0x68) + 0x52);
    if ((*(char *)(param_1 + 0x308) != '\0') && ((*(uint *)(param_1 + 0x30c) & 0x101) != 0)) {
      RttLogEvent(param_1,(char *)(param_1 + 0xdb9),(int *)(param_1 + 0x2d8),0x101,_Src,0x80,param_3
                 );
    }
    switch(*(undefined4 *)(lVar2 + 0x10)) {
    case 1:
      uVar7 = 0;
      do {
        if (*(char *)(uVar7 + 4 + lVar2) != CsmiAllSig[uVar7]) {
LAB_140013d0d:
          *param_2 = '\0';
          return 0;
        }
        bVar6 = (char)uVar7 + 1;
        uVar7 = (ulonglong)bVar6;
      } while (bVar6 < 7);
      if (*(uint *)(lVar2 + 0x18) < 0xae) {
        *(undefined4 *)(lVar2 + 0x14) = 3;
      }
      else {
        memcpy((void *)(lVar2 + 0x1c),drvFileName,0xe);
        memcpy((void *)(lVar2 + 0x6d),drvDesc,0x2c);
        *(undefined4 *)(lVar2 + 0xbe) = 2;
        *(undefined4 *)(lVar2 + 0xc2) = 0x52004f;
        *(undefined4 *)(lVar2 + 0xc6) = 0x20001;
      }
      break;
    case 2:
      uVar7 = 0;
      do {
        if (*(char *)(uVar7 + 4 + lVar2) != CsmiAllSig[uVar7]) goto LAB_140013d0d;
        bVar6 = (char)uVar7 + 1;
        uVar7 = (ulonglong)bVar6;
      } while (bVar6 < 7);
      if (*(uint *)(lVar2 + 0x18) < 0xb4) {
        *(undefined4 *)(lVar2 + 0x14) = 3;
      }
      else {
        *(undefined4 *)(lVar2 + 0x1c) = *(undefined4 *)(param_1 + 0x1554);
        *(undefined4 *)(lVar2 + 0x20) = *(undefined4 *)(param_1 + 0x1558);
        *(undefined4 *)(lVar2 + 0x24) = *(undefined4 *)(param_1 + 0x155c);
        *(int *)(lVar2 + 0x28) = *(int *)(param_1 + 0xd4c) * 0x10000 + *(int *)(param_1 + 0xd50);
        *(undefined2 *)(lVar2 + 0x2c) = *(undefined2 *)(param_1 + 0x1550);
        *(undefined2 *)(lVar2 + 0x2e) = 0x305;
        *(char *)(lVar2 + 0x30) = (char)((uint)*(undefined4 *)(param_1 + 0xd84) >> 8);
        *(byte *)(lVar2 + 0x31) = *(byte *)(param_1 + 0xd84) & 0x1f;
        *(byte *)(lVar2 + 0x32) = (byte)(*(uint *)(param_1 + 0xd84) >> 5) & 7;
        memcpy((void *)(lVar2 + 0x50),(void *)(param_1 + 0x1564),0x10);
        *(ushort *)(lVar2 + 0xa2) = (ushort)*(byte *)(param_1 + 0xd5b);
        *(ushort *)(lVar2 + 0xa4) = *(ushort *)(param_1 + 0xd5a) & 0xff;
        *(ushort *)(lVar2 + 0xa6) = (ushort)((uint)*(undefined4 *)(param_1 + 0xd58) >> 8) & 0xff;
        *(ushort *)(lVar2 + 0xa8) = *(ushort *)(param_1 + 0xd58) & 0xff;
        *(ushort *)(lVar2 + 0xaa) = (ushort)*(byte *)(param_1 + 0xd5f);
        *(ushort *)(lVar2 + 0xac) = *(ushort *)(param_1 + 0xd5e) & 0xff;
        *(ushort *)(lVar2 + 0xae) = (ushort)((uint)*(undefined4 *)(param_1 + 0xd5c) >> 8) & 0xff;
        uVar1 = *(ushort *)(param_1 + 0xd5c);
        *(undefined4 *)(lVar2 + 0xb4) = 0x20001;
        *(ushort *)(lVar2 + 0xb0) = uVar1 & 0xff;
        uVar4 = *(undefined4 *)(lVar2 + 0xb4);
        if ((*(byte *)(param_1 + 0x24e) & 4) != 0) {
          uVar4 = 0x20003;
        }
        *(undefined4 *)(lVar2 + 0xb4) = uVar4;
        ZeroMemory((undefined1 *)(lVar2 + 0xb8),0x10);
      }
      break;
    case 3:
      uVar7 = 0;
      do {
        if (*(char *)(uVar7 + 4 + lVar2) != CsmiAllSig[uVar7]) goto LAB_140013d0d;
        bVar6 = (char)uVar7 + 1;
        uVar7 = (ulonglong)bVar6;
      } while (bVar6 < 7);
      if (*(uint *)(lVar2 + 0x18) < 0x24) {
        *(undefined4 *)(lVar2 + 0x14) = 3;
      }
      else if (*(int *)(param_1 + 0x1560) == 3) {
        *(undefined4 *)(lVar2 + 0x1c) = 3;
        *(undefined4 *)(lVar2 + 0x20) = 1;
      }
      else {
        *(undefined4 *)(lVar2 + 0x1c) = 1;
      }
      break;
    case 4:
      uVar7 = 0;
      do {
        if (*(char *)(uVar7 + 4 + lVar2) != CsmiAllSig[uVar7]) goto LAB_140013d0d;
        bVar6 = (char)uVar7 + 1;
        uVar7 = (ulonglong)bVar6;
      } while (bVar6 < 7);
      if (0x2b < *(uint *)(lVar2 + 0x18)) {
        *(undefined1 **)(param_1 + 0x15f0) = _Src;
        *(undefined1 *)(param_1 + 0xdfe) = 1;
        *(undefined1 *)(param_1 + 0x15fd) = 1;
        uVar5 = CsmiSasFirmwareDownload_sm(param_1,0,param_3);
        *param_2 = '\0';
        return (char)uVar5;
      }
      *(undefined4 *)(lVar2 + 0x14) = 3;
      break;
    default:
      *(undefined4 *)(lVar2 + 0x14) = 2;
      goto LAB_140014559;
    case 0x14:
      uVar7 = 0;
      do {
        if (*(char *)(uVar7 + 4 + lVar2) != CsmiSasSig[uVar7]) goto LAB_140013d0d;
        bVar6 = (char)uVar7 + 1;
        uVar7 = (ulonglong)bVar6;
      } while (bVar6 < 7);
      if (*(uint *)(lVar2 + 0x18) < 0x804) {
        *(undefined4 *)(lVar2 + 0x14) = 3;
      }
      else {
        cVar3 = CsmiIsStateMachineActive(param_1);
        if (cVar3 == '\0') {
          *(longlong *)(param_1 + 0x15e8) = lVar2;
          *(undefined1 **)(param_1 + 0x15f0) = _Src;
          *(undefined1 *)(param_1 + 0xdfe) = 1;
          *(undefined1 *)(param_1 + 0x15fe) = 1;
          CsmiSasGetPhyInfo_sm(param_1,param_3);
          *param_2 = '\0';
          return 1;
        }
        *(undefined4 *)(lVar2 + 0x14) = 1;
      }
      break;
    case 0x15:
      uVar7 = 0;
      do {
        if (*(char *)(uVar7 + 4 + lVar2) != CsmiSasSig[uVar7]) goto LAB_140013d0d;
        bVar6 = (char)uVar7 + 1;
        uVar7 = (ulonglong)bVar6;
      } while (bVar6 < 7);
      if (*(uint *)(lVar2 + 0x18) < 8) {
        *(undefined4 *)(lVar2 + 0x14) = 3;
      }
      else {
        cVar3 = CsmiIsStateMachineActive(param_1);
        if (cVar3 == '\0') {
          *(longlong *)(param_1 + 0x15e8) = lVar2;
          *(undefined1 **)(param_1 + 0x15f0) = _Src;
          *(undefined1 *)(param_1 + 0xdfe) = 1;
          *(undefined1 *)(param_1 + 0x1600) = 1;
          CsmiSasSetPhyInfo_sm(param_1,param_3);
          *param_2 = '\0';
          return 1;
        }
        *(undefined4 *)(lVar2 + 0x14) = 1;
      }
      break;
    case 0x16:
      uVar7 = 0;
      do {
        if (*(char *)(uVar7 + 4 + lVar2) != CsmiSasSig[uVar7]) goto LAB_140013d0d;
        bVar6 = (char)uVar7 + 1;
        uVar7 = (ulonglong)bVar6;
      } while (bVar6 < 7);
      if (*(uint *)(lVar2 + 0x18) < 0x14) {
        *(undefined4 *)(lVar2 + 0x14) = 3;
      }
      else {
        cVar3 = CsmiIsStateMachineActive(param_1);
        if (cVar3 == '\0') {
          *(longlong *)(param_1 + 0x15e8) = lVar2;
          *(undefined1 **)(param_1 + 0x15f0) = _Src;
          *(undefined1 *)(param_1 + 0xdfe) = 1;
          *(undefined1 *)(param_1 + 0x1601) = 1;
          CsmiSasGetLinkErrors_sm(param_1,param_3);
          *param_2 = '\0';
          return 1;
        }
        *(undefined4 *)(lVar2 + 0x14) = 1;
      }
      break;
    case 0x17:
      uVar7 = 0;
      do {
        if (*(char *)(uVar7 + 4 + lVar2) != CsmiSasSig[uVar7]) goto LAB_140013d0d;
        bVar6 = (char)uVar7 + 1;
        uVar7 = (ulonglong)bVar6;
      } while (bVar6 < 7);
      if (0x80f < *(uint *)(lVar2 + 0x18)) {
        *(undefined1 *)(param_1 + 0xdfe) = 1;
        *(undefined1 *)(param_1 + 0x15fa) = 1;
        uVar5 = CsmiSasSendSmpPassThrough_sm(param_1,(char *)0x0,param_3);
        *param_2 = '\0';
        return (char)uVar5;
      }
      *(undefined4 *)(lVar2 + 0x14) = 3;
      break;
    case 0x18:
      uVar7 = 0;
      do {
        if (*(char *)(uVar7 + 4 + lVar2) != CsmiSasSig[uVar7]) goto LAB_140013d0d;
        bVar6 = (char)uVar7 + 1;
        uVar7 = (ulonglong)bVar6;
      } while (bVar6 < 7);
      if (0x47 < *(uint *)(lVar2 + 0x18)) {
        *(undefined1 **)(param_1 + 0x15f0) = _Src;
        *(undefined1 *)(param_1 + 0xdfe) = 1;
        *(undefined1 *)(param_1 + 0x15fb) = 1;
        uVar5 = CsmiSasSendSspPassThrough_sm(param_1,0,param_3);
        *param_2 = '\0';
        return (char)uVar5;
      }
      *(undefined4 *)(lVar2 + 0x14) = 3;
      break;
    case 0x19:
      uVar7 = 0;
      do {
        if (*(char *)(uVar7 + 4 + lVar2) != CsmiSasSig[uVar7]) goto LAB_140013d0d;
        bVar6 = (char)uVar7 + 1;
        uVar7 = (ulonglong)bVar6;
      } while (bVar6 < 7);
      if (0x2b < *(uint *)(lVar2 + 0x18)) {
        *(undefined1 **)(param_1 + 0x15f0) = _Src;
        *(undefined1 *)(param_1 + 0xdfe) = 1;
        *(undefined1 *)(param_1 + 0x15fc) = 1;
        uVar5 = CsmiSasSendStpPassThrough_sm(param_1,0,param_3);
        *param_2 = '\0';
        return (char)uVar5;
      }
      *(undefined4 *)(lVar2 + 0x14) = 3;
      break;
    case 0x1a:
      uVar7 = 0;
      do {
        if (*(char *)(uVar7 + 4 + lVar2) != CsmiSasSig[uVar7]) goto LAB_140013d0d;
        bVar6 = (char)uVar7 + 1;
        uVar7 = (ulonglong)bVar6;
      } while (bVar6 < 7);
      if (*(uint *)(lVar2 + 0x18) < 0x18) {
        *(undefined4 *)(lVar2 + 0x14) = 3;
      }
      else {
        cVar3 = CsmiIsStateMachineActive(param_1);
        if (cVar3 == '\0') {
          *(longlong *)(param_1 + 0x15e8) = lVar2;
          *(undefined1 **)(param_1 + 0x15f0) = _Src;
          *(undefined1 *)(param_1 + 0xdfe) = 1;
          *(undefined1 *)(param_1 + 0x1602) = 1;
          CsmiSasGetSataSignature_sm(param_1,param_3);
          *param_2 = '\0';
          return 1;
        }
        *(undefined4 *)(lVar2 + 0x14) = 1;
      }
      break;
    case 0x1b:
      uVar7 = 0;
      do {
        if (*(char *)(uVar7 + 4 + lVar2) != CsmiSasSig[uVar7]) goto LAB_140013d0d;
        bVar6 = (char)uVar7 + 1;
        uVar7 = (ulonglong)bVar6;
      } while (bVar6 < 7);
      if (*(uint *)(lVar2 + 0x18) < 0x14) {
        *(undefined4 *)(lVar2 + 0x14) = 3;
      }
      else {
        cVar3 = CsmiIsStateMachineActive(param_1);
        if (cVar3 == '\0') {
          *(longlong *)(param_1 + 0x15e8) = lVar2;
          *(undefined1 *)(param_1 + 0xdfe) = 1;
          CsmiSasGetScsiAddress_sm(param_1);
        }
        else {
          *(undefined4 *)(lVar2 + 0x14) = 1;
        }
      }
      break;
    case 0x1c:
      uVar7 = 0;
      do {
        if (*(char *)(uVar7 + 4 + lVar2) != CsmiSasSig[uVar7]) goto LAB_140013d0d;
        bVar6 = (char)uVar7 + 1;
        uVar7 = (ulonglong)bVar6;
      } while (bVar6 < 7);
      if (*(uint *)(lVar2 + 0x18) < 0x14) {
        *(undefined4 *)(lVar2 + 0x14) = 3;
      }
      else {
        cVar3 = CsmiIsStateMachineActive(param_1);
        if (cVar3 == '\0') {
          *(longlong *)(param_1 + 0x15e8) = lVar2;
          *(undefined1 **)(param_1 + 0x15f0) = _Src;
          *(undefined1 *)(param_1 + 0xdfe) = 1;
          *(undefined1 *)(param_1 + 0x1603) = 1;
          CsmiSasGetDeviceAddress_sm(param_1,param_3);
          *param_2 = '\0';
          return 1;
        }
        *(undefined4 *)(lVar2 + 0x14) = 1;
      }
      break;
    case 0x1d:
      uVar7 = 0;
      do {
        if (*(char *)(uVar7 + 4 + lVar2) != CsmiSasSig[uVar7]) goto LAB_140013d0d;
        bVar6 = (char)uVar7 + 1;
        uVar7 = (ulonglong)bVar6;
      } while (bVar6 < 7);
      if (*(uint *)(lVar2 + 0x18) < 0x128) {
        *(undefined4 *)(lVar2 + 0x14) = 3;
      }
      else {
        *(undefined1 *)(param_1 + 0xdfe) = 1;
        uVar5 = CsmiTaskManagement_sm(param_1,(longlong)_Src,param_3);
        *param_2 = (char)uVar5 == '\0';
      }
      break;
    case 0x1e:
      uVar7 = 0;
      do {
        if (*(char *)(uVar7 + 4 + lVar2) != CsmiSasSig[uVar7]) goto LAB_140013d0d;
        bVar6 = (char)uVar7 + 1;
        uVar7 = (ulonglong)bVar6;
      } while (bVar6 < 7);
      if (*(uint *)(lVar2 + 0x18) < (uint)*(byte *)(*(longlong *)(param_1 + 0x15c0) + 0xc) * 0x24) {
        *(undefined4 *)(lVar2 + 0x14) = 3;
      }
      else {
        cVar3 = CsmiIsStateMachineActive(param_1);
        if (cVar3 == '\0') {
          *(longlong *)(param_1 + 0x15e8) = lVar2;
          *(undefined1 **)(param_1 + 0x15f0) = _Src;
          *(undefined1 *)(param_1 + 0xdfe) = 1;
          *(undefined1 *)(param_1 + 0x15ff) = 1;
          CsmiSasGetConnectorInfo_sm(param_1,param_3);
          *param_2 = '\0';
          return 1;
        }
        *(undefined4 *)(lVar2 + 0x14) = 1;
      }
      break;
    case 0x1f:
      uVar7 = 0;
      do {
        if (*(char *)(uVar7 + 4 + lVar2) != CsmiSasSig[uVar7]) goto LAB_140013d0d;
        bVar6 = (char)uVar7 + 1;
        uVar7 = (ulonglong)bVar6;
      } while (bVar6 < 7);
      if (*(uint *)(lVar2 + 0x18) < 0x68) {
        *(undefined4 *)(lVar2 + 0x14) = 3;
      }
      else {
        cVar3 = CsmiIsStateMachineActive(param_1);
        if (cVar3 == '\0') {
          *(longlong *)(param_1 + 0x15e8) = lVar2;
          *(undefined1 **)(param_1 + 0x15f0) = _Src;
          *(undefined1 *)(param_1 + 0xdfe) = 1;
          *(undefined1 *)(param_1 + 0x1607) = 1;
          CsmiSasGetLocation_sm(param_1,param_3);
          *param_2 = '\0';
          return 1;
        }
        *(undefined4 *)(lVar2 + 0x14) = 1;
      }
      break;
    case 0x3c:
      uVar7 = 0;
      do {
        if (*(char *)(uVar7 + 4 + lVar2) != CsmiPhySig[uVar7]) goto LAB_140013d0d;
        bVar6 = (char)uVar7 + 1;
        uVar7 = (ulonglong)bVar6;
      } while (bVar6 < 7);
      if (*(uint *)(lVar2 + 0x18) < 0x234) {
        *(undefined4 *)(lVar2 + 0x14) = 3;
      }
      else {
        cVar3 = CsmiIsStateMachineActive(param_1);
        if (cVar3 == '\0') {
          *(longlong *)(param_1 + 0x15e8) = lVar2;
          *(undefined1 **)(param_1 + 0x15f0) = _Src;
          *(undefined1 *)(param_1 + 0xdfe) = 1;
          *(undefined1 *)(param_1 + 0x1606) = 1;
          CsmiSasPhyControl_sm(param_1,param_3);
          *param_2 = '\0';
          return 1;
        }
        *(undefined4 *)(lVar2 + 0x14) = 1;
      }
    }
  }
  else {
LAB_140014559:
    uVar8 = 0;
  }
  if (*param_2 != '\0') {
    *(undefined1 *)(param_1 + 0xdfe) = 0;
  }
  return uVar8;
}



===== CsmiIsStateMachineActive @ 140014610 =====

undefined1 CsmiIsStateMachineActive(longlong param_1)

{
  if (((((*(char *)(param_1 + 0x15fa) == '\0') && (*(char *)(param_1 + 0x15fb) == '\0')) &&
       (*(char *)(param_1 + 0x15fc) == '\0')) &&
      ((((*(char *)(param_1 + 0x15fd) == '\0' && (*(char *)(param_1 + 0x15fe) == '\0')) &&
        ((*(char *)(param_1 + 0x1600) == '\0' &&
         ((*(char *)(param_1 + 0x1601) == '\0' && (*(char *)(param_1 + 0x1602) == '\0')))))) &&
       (*(char *)(param_1 + 0x1603) == '\0')))) &&
     ((((*(char *)(param_1 + 0x15ff) == '\0' && (*(char *)(param_1 + 0x1604) == '\0')) &&
       (*(char *)(param_1 + 0x1605) == '\0')) &&
      ((*(char *)(param_1 + 0x1606) == '\0' && (*(char *)(param_1 + 0x1607) == '\0')))))) {
    return 0;
  }
  return 1;
}



===== CsmiSasFirmwareDownload_sm @ 1400146a0 =====

ulonglong CsmiSasFirmwareDownload_sm(longlong param_1,longlong param_2,int param_3)

{
  char cVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  uint uVar8;
  ulonglong in_RAX;
  undefined8 uVar9;
  uint *_Src;
  undefined1 local_res8 [8];
  
  lVar5 = *(longlong *)(param_1 + 0xe08);
  lVar6 = *(longlong *)(lVar5 + 0x68);
  lVar7 = *(longlong *)(lVar5 + 0x40);
  if (*(char *)(param_1 + 0xdfe) == '\0') {
    *(undefined1 *)(param_1 + 0x15fd) = 0;
    *(undefined8 *)(param_1 + 0x15f0) = 0;
  }
  else {
    while (cVar1 = *(char *)(param_1 + 0x15fd), cVar1 != '\0') {
      if (cVar1 == '\x01') {
        uVar8 = *(int *)(lVar7 + 0x1c) + 0x2c;
        in_RAX = (ulonglong)uVar8;
        if (*(uint *)(lVar7 + 0x18) < uVar8) {
          *(undefined4 *)(lVar7 + 0x14) = 3;
          *(undefined1 *)(param_1 + 0x15fd) = 0xf0;
        }
        else {
          in_RAX = (ulonglong)*(uint *)(lVar7 + 0x20);
          if ((*(uint *)(lVar7 + 0x20) & 3) != 0) {
            *(undefined4 *)(lVar7 + 0x14) = 3;
            *(undefined1 *)(param_1 + 0x15fd) = 0xf0;
          }
          if (((*(int *)(lVar7 + 0x4c) != 0x5afaa55a) || (*(int *)(lVar7 + 0x50) != -0x5aa5055b)) ||
             (*(int *)(lVar7 + 0x54) != 0x5aa55afa)) {
            *(undefined2 *)(lVar7 + 0x44) = 3;
            *(undefined4 *)(lVar7 + 0x14) = 1;
            *(undefined1 *)(param_1 + 0x15fd) = 0xf0;
          }
          *(undefined1 *)(param_1 + 0x15fd) = 2;
        }
      }
      else {
        if (cVar1 == '\x02') {
          _Src = (uint *)(lVar6 + 0x158);
          uVar8 = StorPortGetPhysicalAddress(param_1,lVar5,_Src,local_res8);
          ZeroMemory((undefined1 *)_Src,(uint)*(ushort *)(param_1 + 0x240));
          *(undefined1 *)_Src = 1;
          *(undefined1 *)(lVar6 + 0x15b) = 9;
          *(undefined1 *)(lVar6 + 0x15f) = 1;
          *(undefined4 *)(lVar6 + 0x164) = *(undefined4 *)(lVar7 + 0x1c);
          *(undefined1 *)(lVar6 + 0x16e) = 0xc;
          *(undefined4 *)(lVar6 + 0x174) = 0;
          *(undefined4 *)(lVar6 + 0x178) = *(undefined4 *)(lVar7 + 0x1c);
          *(undefined1 *)(lVar6 + 0x16f) = 0;
          uVar3 = *(undefined4 *)(lVar5 + 0x18);
          uVar4 = *(undefined4 *)(lVar5 + 0x3c);
          *(undefined4 *)(lVar5 + 0x18) = 0x80;
          *(undefined4 *)(lVar5 + 0x3c) = *(undefined4 *)(lVar7 + 0x1c);
          BuildScatterGather(param_1,lVar5,(uint *)(lVar6 + 0x17c),(int)lVar7 + 0x48,_Src,uVar8);
          *(undefined4 *)(lVar5 + 0x18) = uVar3;
          *(undefined4 *)(lVar5 + 0x3c) = uVar4;
          memcpy(*(void **)(param_1 + 0xe58),_Src,(ulonglong)*(ushort *)(param_1 + 0x240));
          uVar2 = *(ushort *)(param_1 + 0x5aa);
          memcpy(*(void **)(param_1 + 0x548),_Src,(ulonglong)*(ushort *)(param_1 + 0x240));
          uVar9 = QueueRequestDescriptor(param_1,(uint)uVar2 * 0x10000 + 8,0,param_3);
          *(undefined1 *)(param_1 + 0x15fd) = 3;
          return CONCAT71((int7)((ulonglong)uVar9 >> 8),1);
        }
        if (cVar1 != '\x03') {
          if (cVar1 == -0x10) {
            *(undefined1 *)(lVar5 + 3) = 1;
            uVar9 = StorPortNotification(0,param_1,lVar5);
            *(undefined1 *)(param_1 + 0xdfe) = 0;
            *(undefined8 *)(param_1 + 0x15f0) = 0;
            *(undefined8 *)(param_1 + 0xe08) = 0;
            *(undefined1 *)(param_1 + 0x15fd) = 0;
            return CONCAT71((int7)((ulonglong)uVar9 >> 8),1);
          }
          return 1;
        }
        if (*(short *)(param_2 + 0xe) == 0) {
          *(undefined2 *)(lVar7 + 0x44) = 0;
          *(undefined4 *)(lVar7 + 0x14) = 0;
          *(undefined1 *)(param_1 + 0x15fd) = 0xf0;
        }
        else {
          *(undefined4 *)(lVar7 + 0x44) = 0x30001;
          *(undefined4 *)(lVar7 + 0x14) = 1;
          *(undefined1 *)(param_1 + 0x15fd) = 0xf0;
        }
      }
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== CsmiSasGetConnectorInfo_sm @ 140014910 =====

void CsmiSasGetConnectorInfo_sm(longlong param_1,int param_2)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 local_res8 [2];
  
  lVar2 = *(longlong *)(param_1 + 0x15e8);
  if (*(char *)(param_1 + 0xdfe) == '\0') {
    *(undefined1 *)(param_1 + 0x15ff) = 0;
    *(undefined8 *)(param_1 + 0x15f0) = 0;
    return;
  }
  do {
    switch(*(undefined1 *)(param_1 + 0x15ff)) {
    default:
      return;
    case 1:
      *(undefined1 *)(param_1 + 0x15ff) = 2;
      break;
    case 2:
      *(undefined1 *)(param_1 + 0x15ff) = 3;
      local_res8[0] = 0x9070000;
      SendConfigPageMessage(param_1,'\0',local_res8,0,0,param_2);
      return;
    case 3:
      *(undefined1 *)(param_1 + 0x15ff) = 4;
      local_res8[0] = *(undefined4 *)(param_1 + 0x1468);
      SendConfigPageMessage
                (param_1,'\x01',local_res8,0,(int)*(undefined8 *)(param_1 + 0x1460),param_2);
      return;
    case 4:
      *(undefined1 *)(param_1 + 0x15ff) = 0xf0;
      puVar5 = (undefined4 *)(lVar2 + 0x1c);
      lVar3 = *(longlong *)(param_1 + 0x1460);
      if (lVar3 == 0) {
        bVar1 = *(byte *)(*(longlong *)(param_1 + 0x15c0) + 0xc);
        if (bVar1 != 0) {
          uVar4 = (ulonglong)bVar1;
          do {
            *puVar5 = 1;
            *(undefined1 *)(puVar5 + 5) = 1;
            *(undefined1 *)(puVar5 + 1) = 0;
            puVar5 = puVar5 + 9;
            uVar4 = uVar4 - 1;
          } while (uVar4 != 0);
        }
      }
      else if (*(byte *)(lVar3 + 0x20) != 0) {
        uVar4 = (ulonglong)*(byte *)(lVar3 + 0x20);
        puVar6 = (undefined4 *)(lVar3 + 0x24);
        do {
          memcpy(puVar5 + 1,puVar6 + 1,0x10);
          *puVar5 = *puVar6;
          *(undefined1 *)(puVar5 + 5) = *(undefined1 *)(puVar6 + 5);
          uVar4 = uVar4 - 1;
          puVar5 = puVar5 + 9;
          puVar6 = puVar6 + 7;
        } while (uVar4 != 0);
      }
      break;
    case 0xf0:
      *(undefined1 *)(param_1 + 0x15ff) = 0;
      *(undefined1 *)(*(longlong *)(param_1 + 0x15f0) + 3) = 1;
      StorPortNotification(0,param_1);
      *(undefined8 *)(param_1 + 0x15f0) = 0;
      *(undefined1 *)(param_1 + 0xdfe) = 0;
      return;
    }
  } while( true );
}



===== CsmiSasGetDeviceAddress_sm @ 140014c00 =====

void CsmiSasGetDeviceAddress_sm(longlong param_1,int param_2)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  byte bVar4;
  uint uVar5;
  undefined1 *puVar6;
  
  lVar2 = *(longlong *)(param_1 + 0x15e8);
  if (*(char *)(param_1 + 0xdfe) == '\0') {
    *(undefined1 *)(param_1 + 0x1603) = 0;
    *(undefined8 *)(param_1 + 0x15f0) = 0;
    return;
  }
LAB_140014c60:
  do {
    while( true ) {
      cVar1 = *(char *)(param_1 + 0x1603);
      if (cVar1 == '\0') {
        return;
      }
      if (cVar1 != '\x01') break;
      *(undefined1 *)(param_1 + 0x1603) = 4;
    }
    if (cVar1 == '\x04') {
      *(undefined1 *)(param_1 + 0x1603) = 5;
      lVar3 = FindMappingTableEntry
                        (param_1,(ushort)*(byte *)(lVar2 + 0x1d),(ushort)*(byte *)(lVar2 + 0x1e),
                         0xffffffff);
      if (lVar3 != 0) {
        SendExtendedConfigPageMessage
                  (param_1,'\x01',(char *)(param_1 + 0x1530),*(ushort *)(lVar3 + 0x1a) | 0x20000000,
                   (int)*(undefined8 *)(param_1 + 0x1538),param_2);
        return;
      }
    }
    else {
      if (cVar1 != '\x05') {
        *(undefined1 *)(param_1 + 0x1603) = 0;
        if (cVar1 == -0x10) {
          *(undefined1 *)(*(longlong *)(param_1 + 0x15f0) + 3) = 1;
          StorPortNotification(0,param_1);
          *(undefined8 *)(param_1 + 0x15f0) = 0;
          *(undefined1 *)(param_1 + 0xdfe) = 0;
          return;
        }
        return;
      }
      *(undefined1 *)(param_1 + 0x1603) = 0xf0;
      if (*(short *)(param_1 + 0x145a) != 0x22) {
        lVar3 = *(longlong *)(param_1 + 0x1538);
        *(undefined1 *)(lVar2 + 0x29) = *(undefined1 *)(lVar2 + 0x1f);
        puVar6 = (undefined1 *)(lVar2 + 0x20);
        uVar5 = 0;
        do {
          bVar4 = (char)uVar5 + 1;
          *puVar6 = *(undefined1 *)((longlong)(int)(7 - uVar5) + 0xc + lVar3);
          puVar6 = puVar6 + 1;
          uVar5 = (uint)bVar4;
        } while (bVar4 < 8);
        goto LAB_140014c60;
      }
    }
    *(undefined4 *)(lVar2 + 0x14) = 0x7de;
    *(undefined1 *)(param_1 + 0x1603) = 0xf0;
  } while( true );
}



===== CsmiSasGetLinkErrors_sm @ 140014d90 =====

void CsmiSasGetLinkErrors_sm(longlong param_1,int param_2)

{
  ushort uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x15f0);
  lVar3 = *(longlong *)(param_1 + 0x15e8);
  if (*(char *)(param_1 + 0xdfe) == '\0') {
    *(undefined1 *)(param_1 + 0x1601) = 0;
    *(undefined8 *)(param_1 + 0x15f0) = 0;
    return;
  }
  do {
    switch(*(undefined1 *)(param_1 + 0x1601)) {
    case 0:
      return;
    case 1:
      *(undefined1 *)(param_1 + 0x1601) = 2;
      break;
    case 2:
      *(undefined1 *)(param_1 + 0x1601) = 3;
      SendExtendedConfigPageMessage
                (param_1,'\x01',(char *)(param_1 + 0x15b4),(uint)*(byte *)(lVar3 + 0x1c),
                 (int)*(undefined8 *)(param_1 + 0x15e0),param_2);
      return;
    case 3:
      if (*(short *)(param_1 + 0x145a) == 0x22) {
        *(undefined4 *)(lVar3 + 0x14) = 0x7d2;
        *(undefined1 *)(param_1 + 0x1601) = 0xf0;
      }
      else {
        *(undefined1 *)(param_1 + 0x1601) = 4;
        lVar4 = *(longlong *)(param_1 + 0x15e0);
        *(undefined4 *)(lVar3 + 0x20) = *(undefined4 *)(lVar4 + 0xc);
        *(undefined4 *)(lVar3 + 0x24) = *(undefined4 *)(lVar4 + 0x10);
        *(undefined4 *)(lVar3 + 0x28) = *(undefined4 *)(lVar4 + 0x14);
        *(undefined4 *)(lVar3 + 0x2c) = *(undefined4 *)(lVar4 + 0x18);
      }
      break;
    case 4:
      if (*(char *)(lVar3 + 0x1d) != '\0') {
        *(undefined1 *)(param_1 + 0x1601) = 5;
        lVar2 = *(longlong *)(lVar2 + 0x68);
        ZeroMemory((undefined1 *)(lVar2 + 0x158),0x2c);
        *(undefined1 *)(lVar2 + 0x15b) = 0x1b;
        *(undefined1 *)(lVar2 + 0x166) = *(undefined1 *)(lVar3 + 0x1c);
        *(undefined1 *)(lVar2 + 0x158) = 8;
        uVar1 = *(ushort *)(param_1 + 0x5aa);
        memcpy(*(void **)(param_1 + 0x548),(void *)(lVar2 + 0x158),0x2c);
        QueueRequestDescriptor(param_1,(uint)uVar1 * 0x10000 + 8,0,param_2);
        return;
      }
      *(undefined1 *)(param_1 + 0x1601) = 0xf0;
      break;
    case 5:
      *(undefined1 *)(param_1 + 0x1601) = 0xf0;
      if (*(short *)(param_1 + 0x15f8) != 0) {
        *(undefined4 *)(lVar3 + 0x14) = 1;
      }
      break;
    default:
      *(undefined1 *)(param_1 + 0x1601) = 0;
      return;
    case 0xf0:
      *(undefined1 *)(param_1 + 0x1601) = 0;
      *(undefined1 *)(lVar2 + 3) = 1;
      StorPortNotification(0,param_1);
      *(undefined8 *)(param_1 + 0x15f0) = 0;
      *(undefined1 *)(param_1 + 0xdfe) = 0;
      return;
    }
  } while( true );
}



===== CsmiSasGetLocation_sm @ 1400150b0 =====

void CsmiSasGetLocation_sm(longlong param_1,int param_2)

{
  longlong lVar1;
  longlong lVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  ulonglong uVar6;
  byte bVar7;
  undefined1 *puVar8;
  
  lVar1 = *(longlong *)(param_1 + 0x15e8);
  bVar4 = 0;
  bVar7 = 0;
  if (*(char *)(param_1 + 0xdfe) == '\0') {
    *(undefined1 *)(param_1 + 0x1607) = 0;
    *(undefined8 *)(param_1 + 0x15f0) = 0;
    return;
  }
LAB_140015110:
  switch(*(undefined1 *)(param_1 + 0x1607)) {
  case 1:
    *(undefined1 *)(param_1 + 0x1607) = 6;
    goto LAB_140015110;
  default:
    return;
  case 6:
    *(undefined1 *)(param_1 + 0x160e) = 0;
    bVar4 = *(byte *)(lVar1 + 0x1d);
    bVar7 = *(byte *)(lVar1 + 0x1e);
    *(undefined4 *)(lVar1 + 0x24) = 0;
    *(undefined1 *)(lVar1 + 0x21) = 1;
    if (*(uint *)(lVar1 + 0x18) < 0x68) {
      *(undefined4 *)(lVar1 + 0x14) = 3;
      *(undefined1 *)(param_1 + 0x1607) = 0xf0;
      goto LAB_140015110;
    }
    uVar6 = 0;
    if (*(uint *)(param_1 + 0x5b8) != 0) {
      lVar2 = *(longlong *)(param_1 + 0x2c8);
      do {
        if (((*(ushort *)(lVar2 + 0x1c + uVar6 * 0x28) == (ushort)bVar4) &&
            (*(ushort *)(lVar2 + 0x1e + uVar6 * 0x28) == (ushort)bVar7)) &&
           ((*(uint *)(lVar2 + 0x14 + uVar6 * 0x28) & 0x680) != 0)) {
          *(undefined4 *)(lVar1 + 0x14) = 1;
          *(undefined1 *)(param_1 + 0x1607) = 0xd;
          goto LAB_140015110;
        }
        uVar5 = (int)uVar6 + 1;
        uVar6 = (ulonglong)uVar5;
      } while (uVar5 < *(uint *)(param_1 + 0x5b8));
      *(undefined4 *)(lVar1 + 0x14) = 0x7de;
      *(undefined1 *)(param_1 + 0x1607) = 0xf0;
      goto LAB_140015110;
    }
    break;
  case 0xd:
    lVar2 = FindMappingTableEntry(param_1,(ushort)bVar4,(ushort)bVar7,0xffffffff);
    if (lVar2 != 0) {
      SendExtendedConfigPageMessage
                (param_1,'\x01',(char *)(param_1 + 0x1530),*(ushort *)(lVar2 + 0x1a) | 0x20000000,
                 (int)*(undefined8 *)(param_1 + 0x1538),param_2);
      *(undefined1 *)(param_1 + 0x1607) = 0xe;
      return;
    }
    break;
  case 0xe:
    if (*(short *)(param_1 + 0x145a) == 0) {
      *(undefined4 *)(lVar1 + 0x14) = 0;
      lVar2 = *(longlong *)(param_1 + 0x1538);
      *(uint *)(lVar1 + 0x24) = *(uint *)(lVar1 + 0x24) | 1;
      puVar8 = (undefined1 *)(lVar1 + 0x28);
      uVar5 = 0;
      do {
        bVar3 = (char)uVar5 + 1;
        *puVar8 = *(undefined1 *)((longlong)(int)(7 - uVar5) + 0xc + lVar2);
        puVar8 = puVar8 + 1;
        uVar5 = (uint)bVar3;
      } while (bVar3 < 8);
      *(uint *)(lVar1 + 0x24) = *(uint *)(lVar1 + 0x24) | 2;
      ZeroMemory((undefined1 *)(lVar1 + 0x30),8);
      *(undefined1 *)(lVar1 + 0x31) = *(undefined1 *)(lVar1 + 0x1f);
      if (*(short *)(lVar2 + 10) != 0) {
        *(uint *)(lVar1 + 0x24) = *(uint *)(lVar1 + 0x24) | 0x20;
        *(undefined1 *)(lVar1 + 0x80) = *(undefined1 *)(lVar2 + 8);
        SendExtendedConfigPageMessage
                  (param_1,'\x01',(char *)(param_1 + 0x1540),*(ushort *)(lVar2 + 10) | 0x10000000,
                   (int)*(undefined8 *)(param_1 + 0x1548),param_2);
        *(undefined1 *)(param_1 + 0x1607) = 0xf;
        return;
      }
      *(undefined1 *)(param_1 + 0x1607) = 0x10;
    }
    else {
      *(undefined4 *)(lVar1 + 0x14) = 1;
      *(undefined1 *)(param_1 + 0x1607) = 0xf0;
    }
    goto LAB_140015110;
  case 0xf:
    if (*(short *)(param_1 + 0x145a) != 0) goto code_r0x0001400152ab;
    lVar2 = *(longlong *)(param_1 + 0x1548);
    *(uint *)(lVar1 + 0x24) = *(uint *)(lVar1 + 0x24) | 4;
    if ((*(int *)(lVar2 + 0xc) == 0) && (*(int *)(lVar2 + 0x10) == 0)) {
      memcpy((void *)(lVar1 + 0x38),"Internal",8);
    }
    else {
      puVar8 = (undefined1 *)(lVar1 + 0x38);
      uVar5 = 0;
      do {
        bVar4 = (char)uVar5 + 1;
        *puVar8 = *(undefined1 *)((longlong)(int)(7 - uVar5) + 0xc + lVar2);
        puVar8 = puVar8 + 1;
        uVar5 = (uint)bVar4;
      } while (bVar4 < 8);
    }
    *(uint *)(lVar1 + 0x24) = *(uint *)(lVar1 + 0x24) | 8;
    memcpy((void *)(lVar1 + 0x40),"Not Supported",0xe);
    *(uint *)(lVar1 + 0x24) = *(uint *)(lVar1 + 0x24) | 0x40;
    *(undefined1 *)(lVar1 + 0x81) = 0;
  case 0x10:
  case 0xf0:
    goto switchD_14001513a_caseD_10;
  }
  *(undefined4 *)(lVar1 + 0x14) = 0x7de;
  *(undefined1 *)(param_1 + 0x1607) = 0xf0;
  goto LAB_140015110;
code_r0x0001400152ab:
  *(undefined4 *)(lVar1 + 0x14) = 1;
  *(undefined1 *)(param_1 + 0x1607) = 0xf0;
  goto LAB_140015110;
switchD_14001513a_caseD_10:
  *(undefined1 *)(*(longlong *)(param_1 + 0x15f0) + 3) = 1;
  StorPortNotification(0,param_1);
  *(undefined8 *)(param_1 + 0x15f0) = 0;
  *(undefined1 *)(param_1 + 0xdfe) = 0;
  *(undefined1 *)(param_1 + 0x1607) = 0;
  return;
}



===== CsmiSasGetPhyInfo_sm @ 140015530 =====

void CsmiSasGetPhyInfo_sm(longlong param_1,int param_2)

{
  ushort uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uVar4;
  byte bVar5;
  int iVar6;
  byte bVar7;
  ulonglong uVar8;
  undefined1 *puVar9;
  char *pcVar10;
  uint uVar11;
  longlong lVar12;
  undefined1 *puVar13;
  
  lVar2 = *(longlong *)(param_1 + 0x15e8);
  puVar13 = (undefined1 *)(lVar2 + 0x1c);
  if (*(char *)(param_1 + 0xdfe) == '\0') {
    *(undefined1 *)(param_1 + 0x15fe) = 0;
    *(undefined8 *)(param_1 + 0x15f0) = 0;
    return;
  }
LAB_140015590:
  switch(*(undefined1 *)(param_1 + 0x15fe)) {
  default:
    return;
  case 1:
    *(undefined1 *)(param_1 + 0x15fe) = 2;
    goto LAB_140015590;
  case 2:
    *(undefined1 *)(param_1 + 0x15fe) = 3;
    SendExtendedConfigPageMessage
              (param_1,'\x01',(char *)(param_1 + 0x1594),0,(int)*(undefined8 *)(param_1 + 0x15c0),
               param_2);
    return;
  case 3:
    *(undefined1 *)(param_1 + 0x15fe) = 0xc;
    uVar8 = 0;
    lVar3 = *(longlong *)(param_1 + 0x15c0);
    *puVar13 = *(undefined1 *)(lVar3 + 0xc);
    if (*(char *)(lVar3 + 0xc) != '\0') {
      do {
        lVar12 = uVar8 * 0x40;
        uVar11 = *(uint *)(lVar3 + 0x14 + uVar8 * 0x14);
        puVar13[lVar12 + 0x20] = *(undefined1 *)(lVar3 + 0x10 + uVar8 * 0x14);
        puVar13[lVar12 + 6] = 0;
        uVar4 = puVar13[lVar12 + 6];
        if ((uVar11 & 8) != 0) {
          uVar4 = 1;
        }
        puVar13[lVar12 + 4] = 0x10;
        puVar13[lVar12 + 6] = uVar4;
        if ((uVar11 & 0x10) != 0) {
          puVar13[lVar12 + 6] = puVar13[lVar12 + 6] | 2;
        }
        if ((uVar11 & 0x20) != 0) {
          puVar13[lVar12 + 6] = puVar13[lVar12 + 6] | 4;
        }
        if ((uVar11 & 0x40) != 0) {
          puVar13[lVar12 + 6] = puVar13[lVar12 + 6] | 8;
        }
        puVar13[lVar12 + 7] = 0;
        uVar4 = puVar13[lVar12 + 7];
        if ((uVar11 & 0x80) != 0) {
          uVar4 = 1;
        }
        puVar13[lVar12 + 7] = uVar4;
        if ((uVar11 >> 8 & 1) != 0) {
          puVar13[lVar12 + 7] = puVar13[lVar12 + 7] | 2;
        }
        if ((uVar11 >> 9 & 1) != 0) {
          puVar13[lVar12 + 7] = puVar13[lVar12 + 7] | 4;
        }
        if ((uVar11 >> 10 & 1) != 0) {
          puVar13[lVar12 + 7] = puVar13[lVar12 + 7] | 8;
        }
        bVar7 = (char)uVar8 + 1;
        uVar8 = (ulonglong)bVar7;
      } while (bVar7 < *(byte *)(lVar3 + 0xc));
    }
    goto LAB_140015590;
  case 4:
    *(undefined1 *)(param_1 + 0x15fe) = 5;
    *(undefined1 *)(param_1 + 0x1609) = 0;
    goto LAB_140015590;
  case 5:
    *(undefined1 *)(param_1 + 0x15fe) = 6;
    pcVar10 = (char *)(param_1 + 0x15ac);
    uVar11 = (uint)*(byte *)(param_1 + 0x1609);
    iVar6 = (int)*(undefined8 *)(param_1 + 0x15d8);
    goto LAB_1400159b1;
  case 6:
    *(undefined1 *)(param_1 + 0x15fe) = 7;
    lVar3 = *(longlong *)(param_1 + 0x15d8);
    lVar12 = lVar2 + 0x20 + (ulonglong)*(byte *)(param_1 + 0x1609) * 0x40;
    if (*(short *)(param_1 + 0x145a) != 0x22) {
      *(byte *)(lVar12 + 0x1d) = *(byte *)(lVar3 + 0x1c) & 0xf;
      *(byte *)(lVar12 + 0x1e) = *(byte *)(lVar3 + 0x15) & 0xf | *(char *)(lVar3 + 0x14) << 4;
      *(byte *)(lVar12 + 0x1f) = *(byte *)(lVar3 + 0x14) & 0xf0 | *(byte *)(lVar3 + 0x15) >> 4;
      *(undefined1 *)(lVar12 + 0x20) = *(undefined1 *)(lVar3 + 0x16);
      if ((*(uint *)(lVar3 + 0x18) & 0x1000) != 0) {
        *(undefined1 *)(lVar12 + 0x22) = 1;
      }
      *(undefined1 *)(lVar12 + 0x38) = *(undefined1 *)(lVar3 + 0xe);
    }
    goto LAB_140015590;
  case 7:
    if ((int)(uint)*(byte *)(param_1 + 0x1609) <
        (int)(*(byte *)(*(longlong *)(param_1 + 0x15c0) + 0xc) - 1)) {
      *(byte *)(param_1 + 0x1609) = *(byte *)(param_1 + 0x1609) + 1;
      *(undefined1 *)(param_1 + 0x15fe) = 5;
    }
    else {
      *(undefined1 *)(param_1 + 0x15fe) = 8;
    }
    goto LAB_140015590;
  case 8:
    *(undefined1 *)(param_1 + 0x15fe) = 9;
    *(undefined1 *)(param_1 + 0x1609) = 0;
    goto LAB_140015590;
  case 9:
    *(undefined1 *)(param_1 + 0x15fe) = 10;
    uVar1 = *(ushort *)
             (*(longlong *)(param_1 + 0x15c0) + 0x18 + (ulonglong)*(byte *)(param_1 + 0x1609) * 0x14
             );
    break;
  case 10:
    *(undefined1 *)(param_1 + 0x15fe) = 0xb;
    if (*(short *)(param_1 + 0x145a) != 0x22) {
      bVar7 = *(byte *)(param_1 + 0x1609);
      lVar3 = *(longlong *)(param_1 + 0x1538);
      uVar11 = *(uint *)(lVar3 + 0x1c);
      bVar5 = (byte)uVar11 & 7;
      if ((uVar11 & 7) == 0) {
        puVar13[(ulonglong)bVar7 * 0x40 + 0x28] = bVar5;
      }
      else if (bVar5 == 1) {
        puVar13[(ulonglong)bVar7 * 0x40 + 0x28] = 0x10;
      }
      else if (bVar5 == 2) {
        puVar13[(ulonglong)bVar7 * 0x40 + 0x28] = 0x20;
      }
      else if (bVar5 == 3) {
        puVar13[(ulonglong)bVar7 * 0x40 + 0x28] = 0x30;
      }
      puVar13[(ulonglong)bVar7 * 0x40 + 0x2a] = 0;
      uVar4 = puVar13[(ulonglong)bVar7 * 0x40 + 0x2a];
      if ((uVar11 & 8) != 0) {
        uVar4 = 1;
      }
      puVar13[(ulonglong)bVar7 * 0x40 + 0x2a] = uVar4;
      if ((uVar11 & 0x10) != 0) {
        puVar13[(ulonglong)bVar7 * 0x40 + 0x2a] = puVar13[(ulonglong)bVar7 * 0x40 + 0x2a] | 2;
      }
      if ((uVar11 & 0x20) != 0) {
        puVar13[(ulonglong)bVar7 * 0x40 + 0x2a] = puVar13[(ulonglong)bVar7 * 0x40 + 0x2a] | 4;
      }
      if ((uVar11 & 0x40) != 0) {
        puVar13[(ulonglong)bVar7 * 0x40 + 0x2a] = puVar13[(ulonglong)bVar7 * 0x40 + 0x2a] | 8;
      }
      puVar13[(ulonglong)bVar7 * 0x40 + 0x2b] = 0;
      uVar4 = puVar13[(ulonglong)bVar7 * 0x40 + 0x2b];
      if ((uVar11 & 0x80) != 0) {
        uVar4 = 1;
      }
      puVar13[(ulonglong)bVar7 * 0x40 + 0x2b] = uVar4;
      if ((uVar11 >> 8 & 1) != 0) {
        puVar13[(ulonglong)bVar7 * 0x40 + 0x2b] = puVar13[(ulonglong)bVar7 * 0x40 + 0x2b] | 2;
      }
      if ((uVar11 >> 9 & 1) != 0) {
        puVar13[(ulonglong)bVar7 * 0x40 + 0x2b] = puVar13[(ulonglong)bVar7 * 0x40 + 0x2b] | 4;
      }
      if ((uVar11 >> 10 & 1) != 0) {
        puVar13[(ulonglong)bVar7 * 0x40 + 0x2b] = puVar13[(ulonglong)bVar7 * 0x40 + 0x2b] | 8;
      }
      uVar11 = 0;
      puVar9 = puVar13 + (ulonglong)bVar7 * 0x40 + 0x34;
      do {
        iVar6 = 7 - uVar11;
        bVar7 = (char)uVar11 + 1;
        uVar11 = (uint)bVar7;
        *puVar9 = *(undefined1 *)((longlong)iVar6 + 0xc + lVar3);
        puVar9 = puVar9 + 1;
      } while (bVar7 < 8);
    }
    goto LAB_140015590;
  case 0xb:
    if ((int)(uint)*(byte *)(param_1 + 0x1609) <
        (int)(*(byte *)(*(longlong *)(param_1 + 0x15c0) + 0xc) - 1)) {
      *(byte *)(param_1 + 0x1609) = *(byte *)(param_1 + 0x1609) + 1;
      *(undefined1 *)(param_1 + 0x15fe) = 9;
    }
    else {
      *(undefined1 *)(param_1 + 0x15fe) = 0xf0;
    }
    goto LAB_140015590;
  case 0xc:
    *(undefined1 *)(param_1 + 0x15fe) = 0xd;
    *(undefined1 *)(param_1 + 0x1609) = 0;
    goto LAB_140015590;
  case 0xd:
    *(undefined1 *)(param_1 + 0x15fe) = 0xf;
    uVar1 = *(ushort *)
             (*(longlong *)(param_1 + 0x15c0) + 0x1a + (ulonglong)*(byte *)(param_1 + 0x1609) * 0x14
             );
    break;
  case 0xf:
    *(undefined1 *)(param_1 + 0x15fe) = 0x10;
    lVar3 = *(longlong *)(param_1 + 0x1538);
    lVar12 = (ulonglong)*(byte *)(param_1 + 0x1609) * 0x40;
    if (*(short *)(param_1 + 0x145a) != 0x22) {
      uVar11 = 0;
      puVar9 = (undefined1 *)(lVar2 + 0x2c + lVar12);
      do {
        iVar6 = 7 - uVar11;
        bVar7 = (char)uVar11 + 1;
        uVar11 = (uint)bVar7;
        *puVar9 = *(undefined1 *)((longlong)iVar6 + 0xc + lVar3);
        puVar9 = puVar9 + 1;
      } while (bVar7 < 8);
      puVar13[lVar12 + 0x18] = *(undefined1 *)(param_1 + 0x1609);
    }
    goto LAB_140015590;
  case 0x10:
    goto switchD_1400155b4_caseD_10;
  case 0xf0:
    *(undefined1 *)(param_1 + 0x15fe) = 0;
    *(undefined1 *)(*(longlong *)(param_1 + 0x15f0) + 3) = 1;
    StorPortNotification(0,param_1);
    *(undefined8 *)(param_1 + 0x15f0) = 0;
    *(undefined1 *)(param_1 + 0xdfe) = 0;
    return;
  }
  iVar6 = (int)*(undefined8 *)(param_1 + 0x1538);
  pcVar10 = (char *)(param_1 + 0x1530);
  uVar11 = uVar1 | 0x20000000;
LAB_1400159b1:
  SendExtendedConfigPageMessage(param_1,'\x01',pcVar10,uVar11,iVar6,param_2);
  return;
switchD_1400155b4_caseD_10:
  if ((int)(uint)*(byte *)(param_1 + 0x1609) <
      (int)(*(byte *)(*(longlong *)(param_1 + 0x15c0) + 0xc) - 1)) {
    *(byte *)(param_1 + 0x1609) = *(byte *)(param_1 + 0x1609) + 1;
    *(undefined1 *)(param_1 + 0x15fe) = 0xd;
  }
  else {
    *(undefined1 *)(param_1 + 0x15fe) = 4;
  }
  goto LAB_140015590;
}



===== CsmiSasGetSataSignature_sm @ 140015b90 =====

void CsmiSasGetSataSignature_sm(longlong param_1,int param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x15e8);
  if (*(char *)(param_1 + 0xdfe) == '\0') {
    *(undefined1 *)(param_1 + 0x1602) = 0;
    *(undefined8 *)(param_1 + 0x15f0) = 0;
    return;
  }
  do {
    switch(*(undefined1 *)(param_1 + 0x1602)) {
    case 0:
      return;
    case 1:
      *(undefined1 *)(param_1 + 0x1602) = 2;
      break;
    case 2:
      *(undefined1 *)(param_1 + 0x1602) = 3;
      SendExtendedConfigPageMessage
                (param_1,'\x01',(char *)(param_1 + 0x15ac),(uint)*(byte *)(lVar1 + 0x1c),
                 (int)*(undefined8 *)(param_1 + 0x15d8),param_2);
      return;
    case 3:
      *(undefined1 *)(param_1 + 0x1602) = 4;
      if (*(short *)(param_1 + 0x145a) == 0x22) {
        *(undefined4 *)(lVar1 + 0x14) = 0x7d2;
        *(undefined1 *)(param_1 + 0x1602) = 0xf0;
      }
      break;
    case 4:
      *(undefined1 *)(param_1 + 0x1602) = 5;
      SendExtendedConfigPageMessage
                (param_1,'\x01',(char *)(param_1 + 0x15a4),
                 *(ushort *)(*(longlong *)(param_1 + 0x15d8) + 0xc) | 0x20000000,
                 (int)*(undefined8 *)(param_1 + 0x15d0),param_2);
      return;
    case 5:
      *(undefined1 *)(param_1 + 0x1602) = 0xf0;
      memcpy((void *)(lVar1 + 0x20),(void *)(*(longlong *)(param_1 + 0x15d0) + 0x1c),0x14);
      break;
    default:
      *(undefined1 *)(param_1 + 0x1602) = 0;
      return;
    case 0xf0:
      *(undefined1 *)(param_1 + 0x1602) = 0;
      *(undefined1 *)(*(longlong *)(param_1 + 0x15f0) + 3) = 1;
      StorPortNotification(0,param_1);
      *(undefined8 *)(param_1 + 0x15f0) = 0;
      *(undefined1 *)(param_1 + 0xdfe) = 0;
      return;
    }
  } while( true );
}



===== CsmiSasGetScsiAddress_sm @ 140015e30 =====

void CsmiSasGetScsiAddress_sm(longlong param_1)

{
  longlong lVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  byte bVar7;
  undefined1 *puVar8;
  int local_res8;
  undefined4 uStackX_c;
  
  lVar4 = *(longlong *)(param_1 + 0x15e8);
  puVar8 = (undefined1 *)(lVar4 + 0x1c);
  uVar5 = 0;
  do {
    bVar7 = (char)uVar5 + 1;
    *(undefined1 *)((longlong)&local_res8 + (longlong)(int)(7 - uVar5)) = *puVar8;
    puVar8 = puVar8 + 1;
    uVar5 = (uint)bVar7;
  } while (bVar7 < 8);
  uVar6 = 0;
  if (*(uint *)(param_1 + 0x5b8) != 0) {
    do {
      lVar1 = *(longlong *)(param_1 + 0x2c8) + uVar6 * 0x28;
      if (((*(int *)(*(longlong *)(param_1 + 0x2c8) + 8 + uVar6 * 0x28) == local_res8) &&
          (*(int *)(lVar1 + 0xc) == uStackX_c)) && (*(int *)(lVar1 + 0x14) != 0)) {
        uVar2 = *(undefined2 *)(lVar1 + 0x1c);
        uVar3 = *(undefined2 *)(lVar1 + 0x1e);
        if (((byte)*(undefined4 *)(lVar1 + 0x14) & 7) == 1) {
          *(undefined4 *)(lVar4 + 0x14) = 0;
          *(undefined1 *)(lVar4 + 0x2c) = 0xff;
          *(char *)(lVar4 + 0x2d) = (char)uVar2;
          *(char *)(lVar4 + 0x2e) = (char)uVar3;
          *(undefined1 *)(lVar4 + 0x2f) = *(undefined1 *)(lVar4 + 0x25);
          return;
        }
        *(undefined4 *)(lVar4 + 0x14) = 0x7dc;
        return;
      }
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < *(uint *)(param_1 + 0x5b8));
  }
  *(undefined4 *)(lVar4 + 0x14) = 0x7dd;
  return;
}



===== CsmiSasPhyControl_sm @ 140015f20 =====

void CsmiSasPhyControl_sm(longlong param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  char *pcVar5;
  uint uVar6;
  ulonglong uVar7;
  byte bVar8;
  
  lVar3 = *(longlong *)(param_1 + 0x15e8);
  if (*(char *)(param_1 + 0xdfe) == '\0') {
    *(undefined1 *)(param_1 + 0x1606) = 0;
    *(undefined8 *)(param_1 + 0x15f0) = 0;
switchD_140015f9a_caseD_7:
    return;
  }
LAB_140015f70:
  switch(*(undefined1 *)(param_1 + 0x1606)) {
  case 1:
    iVar2 = *(int *)(lVar3 + 0x1c);
    if (iVar2 == 0) {
      *(undefined4 *)(lVar3 + 0x14) = 0;
      *(undefined1 *)(param_1 + 0x1606) = 0xf0;
      goto LAB_140015f70;
    }
    if (((iVar2 != 0x100) && (iVar2 != 3)) ||
       ((*(short *)(lVar3 + 0x22) == 0 && (*(char *)(lVar3 + 0x24) == '\0')))) {
      if (iVar2 != 0x100) {
        SendExtendedConfigPageMessage
                  (param_1,'\x01',(char *)(param_1 + 0x1594),0,
                   (int)*(undefined8 *)(param_1 + 0x15c0),param_2);
        *(undefined1 *)(param_1 + 0x1606) = 2;
        return;
      }
      if (0x623 < *(uint *)(lVar3 + 0x18)) {
        *(undefined2 *)(lVar3 + 0x22) = 0xfc;
        *(undefined1 *)(lVar3 + 0x24) = 6;
        *(undefined2 *)(lVar3 + 0x58) = 0x802;
        *(undefined2 *)(lVar3 + 0x154) = 0x902;
        *(undefined2 *)(lVar3 + 0x250) = 0xa02;
        *(undefined2 *)(lVar3 + 0x34c) = 0x801;
        *(undefined2 *)(lVar3 + 0x448) = 0x901;
        *(undefined2 *)(lVar3 + 0x544) = 0xa01;
        *(undefined4 *)(lVar3 + 0x14) = 0;
        *(undefined1 *)(param_1 + 0x1606) = 0xf0;
        goto LAB_140015f70;
      }
    }
    break;
  case 2:
    if (*(byte *)(*(longlong *)(param_1 + 0x15c0) + 0xc) <= *(byte *)(lVar3 + 0x20)) {
      *(undefined4 *)(lVar3 + 0x14) = 0x7d2;
      *(undefined1 *)(param_1 + 0x1606) = 0xf0;
      goto LAB_140015f70;
    }
    bVar8 = *(byte *)(*(longlong *)(param_1 + 0x15c0) + 0x11 +
                     (ulonglong)*(byte *)(lVar3 + 0x20) * 0x14) & 1;
    if ((*(int *)(lVar3 + 0x1c) == 3) && (bVar8 != 0)) {
      *(undefined4 *)(lVar3 + 0x14) = 1;
      *(undefined1 *)(param_1 + 0x1606) = 0xf0;
      goto LAB_140015f70;
    }
    if (1 < *(int *)(lVar3 + 0x1c) - 1U) {
LAB_14001614b:
      SendExtendedConfigPageMessage
                (param_1,'\x01',(char *)(param_1 + 0x159c),0,(int)*(undefined8 *)(param_1 + 0x15c8),
                 param_2);
      *(undefined1 *)(param_1 + 0x1606) = 3;
      return;
    }
    uVar6 = *(uint *)(lVar3 + 0x2c) & 1;
    if ((uVar6 != 0) && (*(char *)(lVar3 + 0x24) != '\0')) {
      if (*(short *)(lVar3 + 0x22) == 0xfc) {
        if (bVar8 == 0) goto LAB_14001614b;
        *(undefined4 *)(lVar3 + 0x14) = 1;
        *(undefined1 *)(param_1 + 0x1606) = 0xf0;
      }
      else {
        *(undefined2 *)(lVar3 + 0x22) = 0xfc;
        *(undefined4 *)(lVar3 + 0x14) = 1;
        *(undefined1 *)(param_1 + 0x1606) = 0xf0;
      }
      goto LAB_140015f70;
    }
    if ((uVar6 == 0) && (*(short *)(lVar3 + 0x22) == 0)) {
      if (*(char *)(lVar3 + 0x24) == '\0') goto LAB_14001614b;
      *(undefined4 *)(lVar3 + 0x14) = 3;
      *(undefined1 *)(param_1 + 0x1606) = 0xf0;
      goto LAB_140015f70;
    }
    break;
  case 3:
    lVar4 = *(longlong *)(param_1 + 0x15c8);
    bVar8 = *(byte *)(lVar3 + 0x20);
    if (*(int *)(lVar3 + 0x1c) == 3) {
      pbVar1 = (byte *)(lVar4 + 0x16 + (ulonglong)bVar8 * 0xc);
      *pbVar1 = *pbVar1 | 8;
    }
    else {
      if (*(char *)(lVar3 + 0x24) != '\0') {
        uVar7 = (ulonglong)bVar8;
        if (*(char *)(lVar3 + 0x59) == '\b') {
          *(undefined1 *)(lVar4 + 0x17 + uVar7 * 0xc) = 0x88;
        }
        else if (*(char *)(lVar3 + 0x59) == '\t') {
          *(undefined1 *)(lVar4 + 0x17 + uVar7 * 0xc) = 0x99;
        }
        else {
          *(undefined1 *)(lVar4 + 0x17 + uVar7 * 0xc) = 0xaa;
        }
      }
      pbVar1 = (byte *)(lVar4 + 0x16 + (ulonglong)bVar8 * 0xc);
      *pbVar1 = *pbVar1 & 0xf7;
    }
    SendExtendedConfigPageMessage
              (param_1,'\x02',(char *)(param_1 + 0x159c),0,(int)*(undefined8 *)(param_1 + 0x15c8),
               param_2);
    *(undefined1 *)(param_1 + 0x1606) = 4;
    return;
  case 4:
    SendExtendedConfigPageMessage
              (param_1,'\x04',(char *)(param_1 + 0x159c),0,(int)*(undefined8 *)(param_1 + 0x15c8),
               param_2);
    *(undefined1 *)(param_1 + 0x1606) = 5;
    return;
  case 5:
    iVar2 = *(int *)(lVar3 + 0x1c);
    pcVar5 = *(char **)(param_1 + 0x268);
    ZeroMemory(pcVar5,0x2c);
    *pcVar5 = (iVar2 != 1) + '\x06';
    pcVar5[3] = '\x1b';
    pcVar5[0xe] = *(char *)(lVar3 + 0x20);
    QueueRequestDescriptor(param_1,(uint)*(ushort *)(param_1 + 0x5ac) * 0x10000 + 8,0,param_2);
    *(undefined1 *)(param_1 + 0x1606) = 6;
    return;
  case 6:
    goto switchD_140015f9a_caseD_6;
  default:
    goto switchD_140015f9a_caseD_7;
  case 0xf0:
    *(undefined1 *)(*(longlong *)(param_1 + 0x15f0) + 3) = 1;
    StorPortNotification(0,param_1);
    *(undefined8 *)(param_1 + 0x15f0) = 0;
    *(undefined1 *)(param_1 + 0xdfe) = 0;
    *(undefined1 *)(param_1 + 0x1606) = 0;
    return;
  }
  *(undefined4 *)(lVar3 + 0x14) = 3;
  *(undefined1 *)(param_1 + 0x1606) = 0xf0;
  goto LAB_140015f70;
switchD_140015f9a_caseD_6:
  if (*(short *)(param_1 + 0x15f8) == 0) {
    *(undefined4 *)(lVar3 + 0x14) = 0;
  }
  *(undefined1 *)(param_1 + 0x1606) = 0xf0;
  goto LAB_140015f70;
}



===== CsmiSasSendSmpPassThrough_sm @ 1400163f0 =====

ulonglong CsmiSasSendSmpPassThrough_sm(longlong param_1,char *param_2,int param_3)

{
  char cVar1;
  ushort uVar2;
  uint uVar3;
  void *_Src;
  longlong lVar4;
  longlong lVar5;
  ulonglong in_RAX;
  undefined8 uVar6;
  void *pvVar7;
  int iVar8;
  byte bVar9;
  uint uVar10;
  undefined1 *puVar11;
  uint *puVar12;
  undefined1 *_Src_00;
  uint local_res8 [2];
  
  _Src = *(void **)(param_1 + 0xe08);
  lVar4 = *(longlong *)((longlong)_Src + 0x68);
  lVar5 = *(longlong *)((longlong)_Src + 0x40);
  if (*(char *)(param_1 + 0xdfe) == '\0') {
    *(undefined1 *)(param_1 + 0x15fa) = 0;
    *(undefined8 *)(param_1 + 0x15f0) = 0;
    return in_RAX & 0xffffffffffffff00;
  }
  uVar3 = *(uint *)(lVar5 + 0x28);
  local_res8[0] = uVar3 + 0x3fc;
  pvVar7 = (void *)(ulonglong)local_res8[0];
  while( true ) {
    while( true ) {
      cVar1 = *(char *)(param_1 + 0x15fa);
      if (cVar1 == '\0') {
        return (ulonglong)pvVar7 & 0xffffffffffffff00;
      }
      if (cVar1 != '\x01') break;
      pvVar7 = (void *)(ulonglong)local_res8[0];
      if (((local_res8[0] == 0) || (*(uint *)(lVar5 + 0x18) < local_res8[0])) || (0xffff < uVar3)) {
        *(undefined4 *)(lVar5 + 0x14) = 3;
        *(undefined1 *)(param_1 + 0x15fa) = 0xf0;
      }
      else if (*(char *)(lVar5 + 0x1d) == -1) {
        *(undefined4 *)(lVar5 + 0x14) = 0x7d5;
        *(undefined1 *)(param_1 + 0x15fa) = 0xf0;
      }
      else {
        *(undefined1 *)(param_1 + 0x15fa) = 2;
      }
    }
    if (cVar1 == '\x02') break;
    if (cVar1 != '\x03') {
      if (cVar1 == -0x10) {
        *(undefined1 *)((longlong)_Src + 3) = 1;
        uVar6 = StorPortNotification(0,param_1,_Src);
        *(undefined1 *)(param_1 + 0xdfe) = 0;
        *(undefined8 *)(param_1 + 0x15f0) = 0;
        *(undefined8 *)(param_1 + 0xe08) = 0;
        *(undefined1 *)(param_1 + 0x15fa) = 0;
        return CONCAT71((int7)((ulonglong)uVar6 >> 8),1);
      }
      goto LAB_140016776;
    }
    *(undefined4 *)(lVar5 + 0x14) = 0;
    if (*(short *)(param_2 + 0xe) != 0) {
      *(uint *)(lVar5 + 0x14) = (uint)(*(short *)(param_2 + 0xe) != 0x45);
    }
    uVar6 = MapMpiSasStatusToCsmi(param_1,param_2[0xd]);
    *(char *)(lVar5 + 0x428) = (char)uVar6;
    pvVar7 = (void *)(ulonglong)*(ushort *)(param_2 + 4);
    *(uint *)(lVar5 + 0x42c) = (uint)*(ushort *)(param_2 + 4);
    *(undefined4 *)((longlong)_Src + 0x3c) = 0x82c;
    if (*param_2 < '\0') {
      uVar2 = *(ushort *)(param_2 + 4);
      pvVar7 = (void *)(ulonglong)uVar2;
      if (uVar2 < 0x3fd) {
        pvVar7 = memcpy((void *)(lVar5 + 0x430),param_2 + 0x18,(ulonglong)uVar2);
        goto LAB_140016511;
      }
      *(undefined4 *)(lVar5 + 0x14) = 3;
      *(undefined1 *)(param_1 + 0x15fa) = 0xf0;
    }
    else {
LAB_140016511:
      *(undefined1 *)(param_1 + 0x15fa) = 0xf0;
    }
  }
  _Src_00 = (undefined1 *)(lVar4 + 0x158);
  ZeroMemory(_Src_00,0x30);
  *(undefined1 *)(lVar4 + 0x159) = *(undefined1 *)(lVar5 + 0x1d);
  *(undefined1 *)(lVar4 + 0x15b) = 0x1a;
  *(undefined2 *)(lVar4 + 0x15c) = *(undefined2 *)(lVar5 + 0x28);
  puVar11 = (undefined1 *)(lVar5 + 0x20);
  uVar10 = 0;
  do {
    bVar9 = (char)uVar10 + 1;
    _Src_00[(longlong)(int)(7 - uVar10) + 0x10] = *puVar11;
    puVar11 = puVar11 + 1;
    uVar10 = (uint)bVar9;
  } while (bVar9 < 8);
  if ((*(ushort *)(param_1 + 0x240) - 0x3c < uVar3) || (*(ushort *)(param_1 + 0x23e) - 0x20 < 0x3fc)
     ) {
    puVar12 = (uint *)(lVar4 + 0x178);
    if (uVar3 != 0) {
      bVar9 = *(byte *)(param_1 + 0x24e);
      uVar6 = StorPortGetPhysicalAddress(param_1,_Src,lVar5 + 0x2c,local_res8);
      bVar9 = bVar9 & 1;
      local_res8[0] = *(uint *)(lVar5 + 0x28) & 0xffff;
      iVar8 = 0xd7;
      if (bVar9 == 0) {
        iVar8 = 0xd5;
      }
      *puVar12 = iVar8 << 0x18 | local_res8[0];
      *(int *)(lVar4 + 0x17c) = (int)uVar6;
      puVar12 = (uint *)(lVar4 + 0x180);
      if (bVar9 != 0) {
        *puVar12 = (uint)((ulonglong)uVar6 >> 0x20);
        puVar12 = (uint *)(lVar4 + 0x184);
      }
    }
    bVar9 = *(byte *)(param_1 + 0x24e);
    uVar6 = StorPortGetPhysicalAddress(param_1,_Src,lVar5 + 0x430,local_res8);
    bVar9 = bVar9 & 1;
    iVar8 = 0xd3;
    if (bVar9 == 0) {
      iVar8 = 0xd1;
    }
    *puVar12 = iVar8 << 0x18 | local_res8[0];
    puVar12[1] = (uint)uVar6;
    if (bVar9 != 0) {
      puVar12[2] = (uint)((ulonglong)uVar6 >> 0x20);
    }
  }
  else {
    *_Src_00 = 0x80;
    memcpy((void *)(lVar4 + 0x178),(void *)(lVar5 + 0x2c),(ulonglong)uVar3);
  }
  *(undefined4 *)((longlong)_Src + 0x3c) = 0x82c;
  memcpy((void *)(param_1 + 0xe18),_Src,0x40);
  memcpy(*(void **)(param_1 + 0xe58),_Src_00,(ulonglong)*(ushort *)(param_1 + 0x240));
  uVar2 = *(ushort *)(param_1 + 0x5aa);
  *(undefined1 *)(*(longlong *)(param_1 + 0x2a0) + 0x13 + (ulonglong)uVar2 * 0x18) = 1;
  memcpy(*(void **)(param_1 + 0x548),_Src_00,(ulonglong)*(ushort *)(param_1 + 0x240));
  pvVar7 = (void *)QueueRequestDescriptor(param_1,(uint)uVar2 * 0x10000 + 8,0,param_3);
  *(undefined1 *)(param_1 + 0x15fa) = 3;
LAB_140016776:
  return CONCAT71((int7)((ulonglong)pvVar7 >> 8),1);
}



===== CsmiSasSendSspPassThrough_sm @ 1400167a0 =====

ulonglong CsmiSasSendSspPassThrough_sm(longlong param_1,longlong param_2,int param_3)

{
  char cVar1;
  ushort uVar2;
  uint uVar3;
  undefined4 uVar4;
  longlong lVar5;
  longlong lVar6;
  void *in_RAX;
  undefined8 uVar7;
  ushort uVar8;
  undefined1 *puVar9;
  longlong lVar10;
  longlong lVar11;
  byte bVar12;
  uint uVar13;
  ulonglong uVar14;
  void *_Src;
  uint *_Src_00;
  undefined1 local_res8 [8];
  int local_res20;
  undefined4 uStackX_24;
  
  if (*(char *)(param_1 + 0xdfe) == '\0') {
    *(undefined1 *)(param_1 + 0x15fb) = 0;
    *(undefined8 *)(param_1 + 0x15f0) = 0;
    return (ulonglong)in_RAX & 0xffffffffffffff00;
  }
  _Src = *(void **)(param_1 + 0x15f0);
  lVar5 = *(longlong *)((longlong)_Src + 0x40);
  lVar11 = lVar5;
  do {
    while( true ) {
      while( true ) {
        cVar1 = *(char *)(param_1 + 0x15fb);
        if (cVar1 == '\0') {
          return (ulonglong)in_RAX & 0xffffffffffffff00;
        }
        if (cVar1 != '\x01') break;
        if ((*(char *)(lVar5 + 0x1c) == -1) && (*(char *)(lVar5 + 0x1d) == -1)) {
          *(undefined4 *)(lVar11 + 0x14) = 0x7d5;
          *(undefined1 *)(param_1 + 0x15fb) = 0xf0;
        }
        else {
          uVar13 = *(int *)(lVar5 + 0x60) + 0x154;
          in_RAX = (void *)(ulonglong)uVar13;
          if (*(uint *)(lVar11 + 0x18) < uVar13) {
            *(undefined4 *)(lVar11 + 0x14) = 3;
            *(undefined1 *)(param_1 + 0x15fb) = 0xf0;
          }
          else {
            *(undefined1 *)(param_1 + 0x15fb) = 4;
          }
        }
      }
      if (cVar1 == '\x04') break;
      if (cVar1 != '\x05') {
        if (cVar1 == -0x10) {
          *(undefined1 *)((longlong)_Src + 3) = 1;
          in_RAX = (void *)StorPortNotification(0,param_1,_Src);
          *(undefined1 *)(param_1 + 0xdfe) = 0;
          *(undefined8 *)(param_1 + 0x15f0) = 0;
          *(undefined8 *)(param_1 + 0xe08) = 0;
          *(undefined1 *)(param_1 + 0x15fb) = 0;
        }
        return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
      }
      _Src = *(void **)(param_1 + 0xe08);
      lVar11 = *(longlong *)((longlong)_Src + 0x40);
      lVar10 = *(longlong *)((longlong)_Src + 0x68);
      *(undefined2 *)(lVar11 + 0x6a) = 0;
      if (param_2 == 0) {
        in_RAX = (void *)(ulonglong)*(uint *)(lVar11 + 0x60);
        *(uint *)(lVar11 + 0x16c) = *(uint *)(lVar11 + 0x60);
        *(undefined2 *)(lVar11 + 100) = 0x200;
        *(undefined2 *)(lVar11 + 0x68) = 0;
      }
      else {
        uVar8 = *(ushort *)(param_2 + 0xe) & 0x7fff;
        bVar12 = *(byte *)(param_2 + 0xd);
        *(undefined1 *)(lVar11 + 0x69) = *(undefined1 *)(param_2 + 0xc);
        in_RAX = (void *)(ulonglong)*(uint *)(param_2 + 0x14);
        *(uint *)(lVar11 + 0x16c) = *(uint *)(param_2 + 0x14);
        *(undefined1 *)(lVar11 + 0x65) = 4;
        if ((bVar12 & 1) == 0) {
          if ((bVar12 & 0x10) == 0) {
            if (((uVar8 != 0) && (uVar8 != 0x40)) && (uVar8 != 0x45)) {
              *(undefined4 *)(lVar11 + 0x14) = 1;
              *(undefined1 *)(lVar11 + 0x65) = 3;
            }
          }
          else {
            *(undefined1 *)(lVar11 + 0x68) = 1;
            *(undefined1 *)(lVar11 + 0x6a) = 4;
            *(undefined1 *)(lVar11 + 0x6c) = *(undefined1 *)(param_2 + 0x1f);
            *(undefined1 *)(lVar11 + 0x6d) = *(undefined1 *)(param_2 + 0x1e);
            *(undefined1 *)(lVar11 + 0x6e) = *(undefined1 *)(param_2 + 0x1d);
            in_RAX = (void *)0x0;
            *(undefined1 *)(lVar11 + 0x6f) = *(undefined1 *)(param_2 + 0x1c);
          }
        }
        else {
          *(undefined1 *)(lVar11 + 0x68) = 2;
          *(undefined1 *)(lVar11 + 0x6a) = *(undefined1 *)(param_2 + 0x18);
          in_RAX = memcpy((void *)(lVar11 + 0x6c),(void *)(lVar10 + 0x58),
                          (ulonglong)*(uint *)(param_2 + 0x18));
        }
      }
      *(undefined8 *)(param_1 + 0x15f0) = 0;
      *(undefined4 *)(param_1 + 0xd8c) = 0;
      *(undefined1 *)(param_1 + 0x15fb) = 0xf0;
    }
    puVar9 = (undefined1 *)(lVar5 + 0x20);
    uVar13 = 0;
    do {
      bVar12 = (char)uVar13 + 1;
      in_RAX = (void *)0x0;
      *(undefined1 *)((longlong)&local_res20 + (longlong)(int)(7 - uVar13)) = *puVar9;
      puVar9 = puVar9 + 1;
      uVar13 = (uint)bVar12;
    } while (bVar12 < 8);
    uVar14 = 0;
    if (*(uint *)(param_1 + 0x5b8) != 0) {
      in_RAX = (void *)CONCAT44(uStackX_24,local_res20);
      do {
        lVar10 = *(longlong *)(param_1 + 0x2c8) + uVar14 * 0x28;
        if (((*(int *)(*(longlong *)(param_1 + 0x2c8) + 8 + uVar14 * 0x28) == local_res20) &&
            (*(int *)(lVar10 + 0xc) == uStackX_24)) && (*(int *)(lVar10 + 0x14) != 0)) {
          lVar6 = *(longlong *)((longlong)_Src + 0x68);
          _Src_00 = (uint *)(lVar6 + 0x158);
          uVar8 = *(ushort *)(lVar10 + 0x1a);
          uVar13 = StorPortGetPhysicalAddress(param_1,_Src,_Src_00,local_res8);
          ZeroMemory((undefined1 *)_Src_00,(uint)*(ushort *)(param_1 + 0x240));
          *(ushort *)_Src_00 = uVar8;
          *(undefined1 *)(lVar6 + 0x15b) = 0;
          *(ushort *)(lVar6 + 0x17c) = (ushort)*(byte *)(lVar5 + 0x30);
          lVar10 = 8;
          *(undefined1 *)(lVar6 + 0x16c) = 0x18;
          puVar9 = (undefined1 *)(lVar6 + 0x18c);
          do {
            *puVar9 = puVar9[(longlong)((char *)(lVar5 + 0x1c) + (0xc - (lVar6 + 0x18c)))];
            puVar9 = puVar9 + 1;
            lVar10 = lVar10 + -1;
          } while (lVar10 != 0);
          uVar3 = *(uint *)(lVar5 + 0x44);
          if ((uVar3 & 1) == 0) {
            if ((uVar3 & 2) != 0) {
              *(undefined4 *)(lVar6 + 0x194) = 0x1000000;
              goto LAB_140016ad0;
            }
            if (((uVar3 & 4) != 0) && (*(int *)(lVar5 + 0x60) == 0)) {
              *(undefined4 *)(lVar6 + 0x194) = 0;
              goto LAB_140016ad0;
            }
          }
          *(undefined4 *)(lVar6 + 0x194) = 0x2000000;
LAB_140016ad0:
          *(undefined1 *)(lVar6 + 0x16a) = 0xff;
          *(uint *)(lVar6 + 0x164) = uVar13 - 0x100;
          memcpy((void *)(lVar6 + 0x198),(void *)(lVar5 + 0x34),(ulonglong)*(byte *)(lVar5 + 0x30));
          *(undefined4 *)(lVar6 + 0x174) = *(undefined4 *)(lVar5 + 0x60);
          uVar4 = *(undefined4 *)((longlong)_Src + 0x18);
          *(uint *)((longlong)_Src + 0x18) = (*(uint *)(lVar5 + 0x44) & 3) << 6;
          *(undefined4 *)((longlong)_Src + 0x3c) = *(undefined4 *)(lVar5 + 0x60);
          BuildScatterGather(param_1,(longlong)_Src,(uint *)(lVar6 + 0x1b8),(int)lVar11 + 0x170,
                             _Src_00,uVar13);
          *(undefined4 *)((longlong)_Src + 0x18) = uVar4;
          *(int *)((longlong)_Src + 0x3c) = *(int *)(lVar5 + 0x60) + 0x174;
          memcpy((void *)(param_1 + 0xe18),_Src,0x40);
          memcpy(*(void **)(param_1 + 0xe58),_Src_00,(ulonglong)*(ushort *)(param_1 + 0x240));
          uVar2 = *(ushort *)(param_1 + 0x5aa);
          *(undefined1 *)(*(longlong *)(param_1 + 0x2a0) + 0x13 + (ulonglong)uVar2 * 0x18) = 1;
          memcpy(*(void **)(param_1 + 0x548),_Src_00,(ulonglong)*(ushort *)(param_1 + 0x240));
          uVar7 = QueueRequestDescriptor(param_1,(uint)uVar2 << 0x10,(uint)uVar8 << 0x10,param_3);
          *(undefined1 *)(param_1 + 0x15fb) = 5;
          return CONCAT71((int7)((ulonglong)uVar7 >> 8),1);
        }
        uVar13 = (int)uVar14 + 1;
        uVar14 = (ulonglong)uVar13;
      } while (uVar13 < *(uint *)(param_1 + 0x5b8));
    }
    *(undefined4 *)(lVar11 + 0x14) = 3;
    *(undefined1 *)(param_1 + 0x15fb) = 0xf0;
  } while( true );
}



===== CsmiSasSendStpPassThrough_sm @ 140016c00 =====

ulonglong CsmiSasSendStpPassThrough_sm(longlong param_1,longlong param_2,int param_3)

{
  longlong lVar1;
  char cVar2;
  undefined2 uVar3;
  ushort uVar4;
  undefined4 uVar5;
  longlong lVar6;
  byte bVar7;
  int iVar8;
  ulonglong in_RAX;
  uint7 uVar10;
  undefined8 uVar9;
  longlong lVar11;
  uint uVar12;
  undefined1 *puVar13;
  void *_Src;
  uint *_Src_00;
  undefined1 local_res8 [8];
  undefined8 local_res20;
  
  if (*(char *)(param_1 + 0xdfe) == '\0') {
    *(undefined1 *)(param_1 + 0x15fc) = 0;
    *(undefined8 *)(param_1 + 0x15f0) = 0;
    return in_RAX & 0xffffffffffffff00;
  }
  _Src = *(void **)(param_1 + 0x15f0);
  lVar6 = *(longlong *)((longlong)_Src + 0x40);
  lVar11 = lVar6;
  do {
    while( true ) {
      while( true ) {
        cVar2 = *(char *)(param_1 + 0x15fc);
        uVar10 = (uint7)(in_RAX >> 8);
        if (cVar2 == '\0') {
          return (ulonglong)uVar10 << 8;
        }
        if (cVar2 != '\x01') break;
        if ((*(char *)(lVar6 + 0x1c) == -1) && (*(char *)(lVar6 + 0x1d) == -1)) {
          *(undefined4 *)(lVar11 + 0x14) = 0x7d5;
          *(undefined1 *)(param_1 + 0x15fc) = 0xf0;
        }
        else {
          uVar12 = *(int *)(lVar6 + 0x44) + 0x88;
          in_RAX = (ulonglong)uVar12;
          if (*(uint *)(lVar11 + 0x18) < uVar12) {
            *(undefined4 *)(lVar11 + 0x14) = 3;
            *(undefined1 *)(param_1 + 0x15fc) = 0xf0;
          }
          else {
            *(undefined1 *)(param_1 + 0x15fc) = 2;
          }
        }
      }
      if (cVar2 == '\x02') break;
      if (cVar2 != '\x03') {
        if (cVar2 == -0x10) {
          *(undefined1 *)((longlong)_Src + 3) = 1;
          uVar9 = StorPortNotification(0,param_1,_Src);
          *(undefined1 *)(param_1 + 0xdfe) = 0;
          *(undefined8 *)(param_1 + 0x15f0) = 0;
          *(undefined8 *)(param_1 + 0xe08) = 0;
          *(undefined1 *)(param_1 + 0x15fc) = 0;
          return CONCAT71((int7)((ulonglong)uVar9 >> 8),1);
        }
LAB_140016fe2:
        return CONCAT71((int7)(in_RAX >> 8),1);
      }
      _Src = *(void **)(param_1 + 0xe08);
      lVar11 = *(longlong *)((longlong)_Src + 0x40);
      if ((*(short *)(param_2 + 0xe) != 0) && (*(short *)(param_2 + 0xe) != 0x45)) {
        *(undefined4 *)(lVar11 + 0x14) = 1;
      }
      uVar9 = MapMpiSasStatusToCsmi(param_1,*(undefined1 *)(param_2 + 0xd));
      *(char *)(lVar11 + 0x48) = (char)uVar9;
      memcpy((void *)(lVar11 + 0x4c),(void *)(param_2 + 0x14),0x14);
      ZeroMemory((undefined1 *)(lVar11 + 0x60),0x40);
      *(undefined4 *)(lVar11 + 0x60) = *(undefined4 *)(param_2 + 0x28);
      in_RAX = (ulonglong)*(uint *)(param_2 + 0x2c);
      *(uint *)(lVar11 + 0xa0) = *(uint *)(param_2 + 0x2c);
      *(undefined8 *)(param_1 + 0x15f0) = 0;
      *(undefined4 *)(param_1 + 0xd8c) = 0;
      *(undefined1 *)(param_1 + 0x15fc) = 0xf0;
    }
    in_RAX = (ulonglong)uVar10 << 8;
    puVar13 = (undefined1 *)(lVar6 + 0x20);
    do {
      uVar12 = (uint)in_RAX;
      bVar7 = (char)in_RAX + 1;
      in_RAX = CONCAT71((int7)(in_RAX >> 8),bVar7);
      *(undefined1 *)((longlong)&local_res20 + (longlong)(int)(7 - (uVar12 & 0xff))) = *puVar13;
      puVar13 = puVar13 + 1;
    } while (bVar7 < 8);
    uVar12 = 0;
    if (*(uint *)(param_1 + 0x5b8) != 0) {
      do {
        lVar1 = *(longlong *)(param_1 + 0x2c8) + (ulonglong)uVar12 * 0x28;
        if (((*(int *)(*(longlong *)(param_1 + 0x2c8) + 8 + (ulonglong)uVar12 * 0x28) ==
              (int)local_res20) && (*(int *)(lVar1 + 0xc) == local_res20._4_4_)) &&
           (*(int *)(lVar1 + 0x14) != 0)) {
          uVar3 = *(undefined2 *)(lVar1 + 0x1a);
          in_RAX = (ulonglong)*(uint *)(lVar1 + 0x14);
          if ((*(uint *)(lVar1 + 0x14) & 0x280) != 0) {
            lVar1 = *(longlong *)((longlong)_Src + 0x68);
            _Src_00 = (uint *)(lVar1 + 0x158);
            uVar9 = StorPortGetPhysicalAddress(param_1,_Src,_Src_00,local_res8);
            local_res20 = uVar9;
            ZeroMemory((undefined1 *)_Src_00,(uint)*(ushort *)(param_1 + 0x240));
            *(undefined2 *)_Src_00 = uVar3;
            *(undefined1 *)(lVar1 + 0x15b) = 0x1c;
            *(undefined2 *)(lVar1 + 0x15c) = *(undefined2 *)(lVar6 + 0x40);
            *(undefined4 *)(lVar1 + 0x170) = *(undefined4 *)(lVar6 + 0x44);
            memcpy((void *)(lVar1 + 0x174),(void *)(lVar6 + 0x2c),0x14);
            if (*(int *)(lVar6 + 0x44) == 0) {
              bVar7 = *(byte *)(param_1 + 0x24e) & 1;
              iVar8 = 0xd3;
              if (bVar7 == 0) {
                iVar8 = 0xd1;
              }
              *(int *)(lVar1 + 0x188) = iVar8 << 0x18;
              *(uint *)(lVar1 + 0x18c) = (uint)uVar9 + 8;
              if (bVar7 != 0) {
                *(int *)(lVar1 + 400) = local_res20._4_4_;
              }
            }
            else {
              uVar5 = *(undefined4 *)((longlong)_Src + 0x18);
              *(uint *)((longlong)_Src + 0x18) = (*(ushort *)(lVar1 + 0x15c) & 3) << 6;
              *(undefined4 *)((longlong)_Src + 0x3c) = *(undefined4 *)(lVar1 + 0x170);
              BuildScatterGather(param_1,(longlong)_Src,(uint *)(lVar1 + 0x188),(int)lVar11 + 0xa4,
                                 _Src_00,(uint)uVar9);
              *(undefined4 *)((longlong)_Src + 0x18) = uVar5;
              *(undefined4 *)(lVar1 + 0x168) = 0;
            }
            *(int *)((longlong)_Src + 0x3c) = *(int *)(lVar6 + 0x44) + 0xa8;
            memcpy((void *)(param_1 + 0xe18),_Src,0x40);
            memcpy(*(void **)(param_1 + 0xe58),_Src_00,(ulonglong)*(ushort *)(param_1 + 0x240));
            uVar4 = *(ushort *)(param_1 + 0x5aa);
            *(undefined1 *)(*(longlong *)(param_1 + 0x2a0) + 0x13 + (ulonglong)uVar4 * 0x18) = 1;
            memcpy(*(void **)(param_1 + 0x548),_Src_00,(ulonglong)*(ushort *)(param_1 + 0x240));
            in_RAX = QueueRequestDescriptor(param_1,(uint)uVar4 * 0x10000 + 8,0,param_3);
            *(undefined1 *)(param_1 + 0x15fc) = 3;
            goto LAB_140016fe2;
          }
          break;
        }
        uVar12 = uVar12 + 1;
        in_RAX = local_res20;
      } while (uVar12 < *(uint *)(param_1 + 0x5b8));
    }
    *(undefined4 *)(lVar11 + 0x14) = 3;
    *(undefined1 *)(param_1 + 0x15fc) = 0xf0;
  } while( true );
}



===== CsmiSasSetPhyInfo_sm @ 140017010 =====

void CsmiSasSetPhyInfo_sm(longlong param_1,int param_2)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  bool bVar7;
  ulonglong uVar8;
  byte bVar9;
  byte bVar10;
  
  lVar4 = *(longlong *)(param_1 + 0x15e8);
  bVar7 = false;
  if (*(char *)(param_1 + 0xdfe) == '\0') {
    *(undefined1 *)(param_1 + 0x1600) = 0;
    *(undefined8 *)(param_1 + 0x15f0) = 0;
    return;
  }
  do {
    switch(*(undefined1 *)(param_1 + 0x1600)) {
    case 0:
      return;
    case 1:
      *(undefined1 *)(param_1 + 0x1600) = 6;
      break;
    default:
      *(undefined1 *)(param_1 + 0x1600) = 0;
      return;
    case 3:
      *(undefined1 *)(param_1 + 0x1600) = 4;
      SendExtendedConfigPageMessage
                (param_1,'\x01',(char *)(param_1 + 0x159c),0,(int)*(undefined8 *)(param_1 + 0x15c8),
                 param_2);
      return;
    case 4:
      *(undefined1 *)(param_1 + 0x1600) = 5;
      lVar5 = *(longlong *)(param_1 + 0x15c8);
      lVar6 = *(longlong *)(param_1 + 0x15d8);
      if (*(byte *)(lVar4 + 0x1c) < *(byte *)(lVar5 + 0x10)) {
        uVar8 = (ulonglong)*(byte *)(lVar4 + 0x1c);
        if (*(char *)(lVar4 + 0x1d) == '\0') {
          pbVar1 = (byte *)(lVar5 + 0x15 + uVar8 * 0xc);
          *pbVar1 = *pbVar1 & 0xfe;
        }
        else if (*(char *)(lVar4 + 0x1d) == '\x01') {
          pbVar1 = (byte *)(lVar5 + 0x16 + uVar8 * 0xc);
          *pbVar1 = *pbVar1 | 8;
        }
        bVar9 = *(byte *)(lVar6 + 0x15);
        bVar2 = *(byte *)(lVar4 + 0x1e);
        bVar3 = *(byte *)(lVar4 + 0x1f);
        bVar10 = bVar9 & 0xf;
        bVar9 = bVar9 >> 4;
        if (bVar2 != 0) {
          if (bVar2 < bVar10) {
            bVar7 = true;
            *(undefined4 *)(lVar4 + 0x14) = 0x7d1;
          }
          else if (bVar9 < bVar2) {
            bVar7 = true;
            *(undefined4 *)(lVar4 + 0x14) = 0x7d1;
          }
          else {
            pbVar1 = (byte *)(lVar5 + 0x17 + uVar8 * 0xc);
            *pbVar1 = *pbVar1 ^ (*(byte *)(lVar5 + 0x17 + uVar8 * 0xc) ^ bVar2) & 0xf;
          }
        }
        if (bVar3 == 0) {
LAB_14001716a:
          if (bVar7) goto LAB_140017187;
          *(undefined4 *)(lVar4 + 0x14) = 0;
        }
        else {
          if ((bVar3 <= bVar9) && (bVar10 <= bVar3)) {
            *(byte *)(lVar5 + 0x17 + uVar8 * 0xc) =
                 *(byte *)(lVar5 + 0x17 + uVar8 * 0xc) & 0xf | bVar3 << 4;
            goto LAB_14001716a;
          }
          *(undefined4 *)(lVar4 + 0x14) = 0x7d1;
          bVar7 = true;
LAB_140017187:
          *(undefined1 *)(param_1 + 0x1600) = 0xf0;
        }
      }
      else {
        *(undefined4 *)(lVar4 + 0x14) = 3;
        bVar7 = true;
        *(undefined1 *)(param_1 + 0x1600) = 0xf0;
      }
      break;
    case 5:
      *(undefined1 *)(param_1 + 0x1600) = 0xf0;
      SendExtendedConfigPageMessage
                (param_1,'\x02',(char *)(param_1 + 0x159c),0,(int)*(undefined8 *)(param_1 + 0x15c8),
                 param_2);
      return;
    case 6:
      *(undefined1 *)(param_1 + 0x1600) = 3;
      SendExtendedConfigPageMessage
                (param_1,'\x01',(char *)(param_1 + 0x15ac),(uint)*(byte *)(lVar4 + 0x1c),
                 (int)*(undefined8 *)(param_1 + 0x15d8),param_2);
      return;
    case 0xf0:
      *(undefined1 *)(param_1 + 0x1600) = 0;
      lVar4 = *(longlong *)(param_1 + 0x15f0);
      *(undefined1 *)(lVar4 + 3) = 1;
      StorPortNotification(0,param_1,lVar4,param_2);
      *(undefined8 *)(param_1 + 0x15f0) = 0;
      *(undefined1 *)(param_1 + 0xdfe) = 0;
      return;
    }
  } while( true );
}



===== CsmiSendTaskMgmtRequest @ 140017390 =====

undefined8
CsmiSendTaskMgmtRequest(longlong param_1,undefined8 *param_2,undefined8 param_3,int param_4)

{
  ushort uVar1;
  undefined8 uVar2;
  
  *(uint *)(param_2 + 2) = *(uint *)(param_2 + 2) | 1;
  param_2[1] = param_3;
  StorPortPause(param_1,300);
  ResetActive(param_1,8,param_4);
  uVar1 = *(ushort *)(param_1 + 0x5aa);
  *(ushort *)((longlong)param_2 + 0x14) = uVar1;
  memcpy(*(void **)(param_1 + 0x548),(void *)*param_2,8);
  uVar2 = QueueRequestDescriptor(param_1,(uint)uVar1 * 0x10000 + 6,0,param_4);
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



===== CsmiTaskManagement_sm @ 140017420 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 CsmiTaskManagement_sm(longlong param_1,longlong param_2,int param_3)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  uint uVar4;
  longlong lVar5;
  short *psVar6;
  bool bVar7;
  undefined8 uVar8;
  short sVar9;
  undefined1 uVar10;
  undefined1 auStack_88 [32];
  undefined1 local_68;
  short local_66;
  longlong local_60;
  undefined1 local_58 [2];
  undefined1 local_56;
  undefined1 local_55;
  short local_54;
  int local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_88;
  lVar5 = *(longlong *)(param_2 + 0x40);
  if ((*(int *)(param_2 + 0x14) != 2) || (*(int *)(lVar5 + 0x10) != 0x1d)) {
    return 1;
  }
  uVar4 = *(uint *)(lVar5 + 0x20);
  if (((byte)uVar4 & 3) == 3) {
switchD_14001751e_caseD_4:
    *(undefined4 *)(lVar5 + 0x14) = 3;
    return 0;
  }
  if ((uVar4 & 1) == 0) {
    if ((uVar4 & 2) == 0) goto switchD_14001751e_caseD_4;
    uVar10 = 3;
  }
  else {
    cVar1 = *(char *)(lVar5 + 0x2c);
    if (cVar1 == '\x01') {
      uVar10 = 1;
    }
    else if (cVar1 == '\x02') {
      uVar10 = 2;
    }
    else if (cVar1 == '\x04') {
      uVar10 = 6;
    }
    else if (cVar1 == '\b') {
      uVar10 = 5;
    }
    else {
      if (cVar1 != -0x80) goto switchD_14001751e_caseD_4;
      uVar10 = 7;
    }
  }
  uVar2 = *(undefined1 *)(lVar5 + 0x1f);
  uVar3 = *(undefined1 *)(lVar5 + 0x24);
  local_68 = uVar2;
  local_60 = param_2;
  local_66 = FindDevHandleFromBusTarget
                       (param_1,(ushort)*(byte *)(lVar5 + 0x1d),(ushort)*(byte *)(lVar5 + 0x1e));
  if (local_66 == 0) goto switchD_14001751e_caseD_4;
  *(undefined1 *)(param_1 + 0x1574) = uVar10;
  sVar9 = 0;
  switch(uVar10) {
  case 1:
  case 7:
    local_54 = 0;
    local_56 = uVar2;
    local_55 = uVar3;
    local_50 = param_3;
    StorPortSynchronizeAccess(param_1,CsmiFindAbortSmid,local_58);
    if (local_54 == 0) {
      *(undefined4 *)(lVar5 + 0x14) = 0;
      *(undefined1 *)(lVar5 + 0x39) = 5;
      *(undefined1 *)(lVar5 + 0x3c) = 0;
      return 0;
    }
    sVar9 = local_54;
switchD_14001751e_caseD_2:
    bVar7 = CsmiCheckOutstandingTaskMgmt(param_1,param_3);
    if (bVar7) {
      psVar6 = *(short **)(param_1 + 0x1578);
      ZeroMemory((undefined1 *)psVar6,0x34);
      *psVar6 = local_66;
      *(undefined1 *)((longlong)psVar6 + 3) = 1;
      *(undefined1 *)((longlong)psVar6 + 5) = uVar10;
      *(undefined1 *)((longlong)psVar6 + 0xd) = local_68;
      psVar6[0x18] = sVar9;
LAB_1400175ab:
      uVar8 = CsmiSendTaskMgmtRequest(param_1,(undefined8 *)(param_1 + 0x1578),local_60,param_3);
      if ((char)uVar8 != '\0') {
        return 1;
      }
    }
LAB_1400175c6:
    *(undefined4 *)(lVar5 + 0x14) = 1;
    return 0;
  case 2:
  case 5:
  case 6:
    goto switchD_14001751e_caseD_2;
  case 3:
    bVar7 = CsmiCheckOutstandingTaskMgmt(param_1,param_3);
    if (!bVar7) goto LAB_1400175c6;
    psVar6 = *(short **)(param_1 + 0x1578);
    ZeroMemory((undefined1 *)psVar6,0x34);
    *psVar6 = local_66;
    *(undefined1 *)((longlong)psVar6 + 3) = 1;
    *(undefined1 *)((longlong)psVar6 + 5) = uVar10;
    *(undefined1 *)((longlong)psVar6 + 0xd) = local_68;
    goto LAB_1400175ab;
  default:
    goto switchD_14001751e_caseD_4;
  }
}



===== FindDevHandleFromBusTarget @ 140017660 =====

undefined2 FindDevHandleFromBusTarget(longlong param_1,short param_2,short param_3)

{
  longlong lVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (*(uint *)(param_1 + 0x5b8) != 0) {
    do {
      lVar1 = *(longlong *)(param_1 + 0x2c8) + (ulonglong)uVar2 * 0x28;
      if ((*(short *)(*(longlong *)(param_1 + 0x2c8) + 0x1c + (ulonglong)uVar2 * 0x28) == param_2)
         && (*(short *)(lVar1 + 0x1e) == param_3)) {
        return *(undefined2 *)(lVar1 + 0x1a);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(param_1 + 0x5b8));
  }
  return 0;
}



===== MapMpiSasStatusToCsmi @ 1400176c0 =====

undefined8 MapMpiSasStatusToCsmi(undefined8 param_1,undefined1 param_2)

{
  switch(param_2) {
  case 0:
    return 0;
  default:
    return 9;
  case 3:
    return 1;
  case 5:
    return 2;
  case 7:
    return 5;
  case 8:
    return 0xb;
  case 9:
    return 0xc;
  case 0x12:
    return 10;
  case 0x13:
    return 4;
  case 0x14:
    return 3;
  }
}



===== FUN_140017750 @ 140017750 =====

void FUN_140017750(longlong param_1,undefined4 *param_2,undefined4 param_3,undefined1 *param_4,
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



===== RttInitTrace @ 1400177e0 =====

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



===== RttLogEvent @ 140017820 =====

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



===== RttLogEventCore @ 1400178b0 =====

void RttLogEventCore(int *param_1,undefined4 param_2,undefined1 *param_3,uint param_4,
                    undefined4 param_5)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int *piVar4;
  ulonglong uVar5;
  longlong lVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  
  uVar5 = (ulonglong)param_4;
  uVar9 = param_4 + 0x1c;
  if (uVar9 <= (uint)param_1[10]) {
    puVar8 = *(undefined4 **)(param_1 + 6);
    puVar3 = *(undefined4 **)(param_1 + 4);
    while (puVar8 < puVar3) {
      do {
        if (uVar9 <= (uint)(param_1[4] - (int)puVar8)) {
          *puVar8 = param_2;
          puVar8[1] = param_4 + 0x14;
          StorPortQuerySystemTime(puVar8 + 2);
          puVar8[4] = param_5;
          puVar8 = puVar8 + 5;
          if (param_4 != 0) {
            do {
              uVar1 = *param_3;
              param_3 = param_3 + 1;
              *(undefined1 *)puVar8 = uVar1;
              puVar8 = (undefined4 *)((longlong)puVar8 + 1);
              uVar5 = uVar5 - 1;
            } while (uVar5 != 0);
          }
          *puVar8 = 0;
          puVar8[1] = 8;
          param_1[0xb] = param_1[0xb] + 1;
          *(undefined4 **)(param_1 + 6) = puVar8;
          return;
        }
        uVar2 = *(uint *)(*(longlong *)(param_1 + 4) + 4);
        param_1[0xb] = param_1[0xb] + -1;
        piVar4 = (int *)((ulonglong)uVar2 + *(longlong *)(param_1 + 4));
        *(int **)(param_1 + 4) = piVar4;
      } while (*piVar4 != 1);
      puVar3 = *(undefined4 **)param_1;
      *(undefined4 **)(param_1 + 4) = puVar3;
    }
    if ((uint)(param_1[2] - (int)puVar8) <= uVar9) {
      *puVar8 = 1;
      *(undefined4 *)(*(longlong *)(param_1 + 6) + 4) = 8;
      if ((uint)(param_1[4] - *param_1) < uVar9) {
        lVar6 = *(longlong *)(param_1 + 4);
        iVar7 = param_1[0xb];
        do {
          iVar7 = iVar7 + -1;
          lVar6 = lVar6 + (ulonglong)*(uint *)(lVar6 + 4);
          param_1[0xb] = iVar7;
          *(longlong *)(param_1 + 4) = lVar6;
        } while ((uint)((int)lVar6 - *param_1) < uVar9);
      }
      puVar8 = *(undefined4 **)param_1;
    }
    FUN_140017750((longlong)param_1,puVar8,param_2,param_3,param_4,param_5);
  }
  return;
}



===== RttLogEventSynchronized @ 140017a00 =====

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



===== RttSetTraceParameters @ 140017a40 =====

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



===== GtfInitialize @ 140017a60 =====

void GtfInitialize(longlong param_1)

{
  uint *puVar1;
  byte bVar2;
  byte bVar3;
  longlong lVar4;
  
  puVar1 = (uint *)(param_1 + 0x310);
  *puVar1 = 0;
  bVar3 = 0;
  *(undefined8 *)(param_1 + 0x318) = 0;
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



===== GtfProcessTimers @ 140017ab0 =====

undefined8 GtfProcessTimers(longlong param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  char cVar3;
  ushort uVar4;
  uint uVar5;
  undefined8 *puVar6;
  byte bVar7;
  ulonglong local_res8;
  
  uVar1 = *(undefined1 *)(param_1 + 0xdb9);
  uVar2 = *param_2;
  *(undefined1 *)(param_1 + 0xdb9) = 1;
  StorPortQuerySystemTime(&local_res8);
  if (9999999 < (longlong)(local_res8 - *(longlong *)(param_1 + 0x318))) {
    puVar6 = (undefined8 *)(param_1 + 0x328);
    bVar7 = 0;
    *(ulonglong *)(param_1 + 0x318) = local_res8;
    do {
      uVar4 = *(ushort *)((longlong)puVar6 + -2);
      local_res8 = (ulonglong)uVar4;
      if (uVar4 != 0) {
        uVar4 = uVar4 - 1;
        local_res8 = (ulonglong)uVar4;
        *(ushort *)((longlong)puVar6 + -2) = uVar4;
        if (uVar4 == 0) {
          cVar3 = (*(code *)*puVar6)(param_1,bVar7,puVar6[1],uVar2);
          if ((cVar3 == '\0') && (*(int *)(puVar6 + -1) != 2)) {
            puVar6[-1] = 0;
            *puVar6 = 0;
            uVar5 = ~(1 << (bVar7 & 0x1f));
            local_res8 = (ulonglong)uVar5;
            puVar6[1] = 0;
            *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) & uVar5;
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
  *(undefined1 *)(param_1 + 0xdb9) = uVar1;
  return CONCAT71((int7)(local_res8 >> 8),1);
}



===== GtfStartTimer @ 140017ba0 =====

byte GtfStartTimer(longlong param_1,undefined4 param_2,undefined2 param_3,undefined8 param_4,
                  undefined8 param_5,int param_6)

{
  byte bVar1;
  ulonglong uVar2;
  undefined4 local_38;
  undefined2 local_34;
  undefined8 local_30;
  byte local_28;
  undefined8 local_20;
  int local_18;
  
  if ((param_6 != 5) && (*(char *)(param_1 + 0xdb9) == '\0')) {
    local_18 = param_6;
    local_20 = param_5;
    local_28 = 0xfe;
    local_38 = param_2;
    local_34 = param_3;
    local_30 = param_4;
    StorPortSynchronizeAccess(param_1,GtfStartTimerSynchronized,&local_38);
    return local_28;
  }
  uVar2 = 0;
  do {
    bVar1 = (byte)uVar2;
    if (*(int *)(param_1 + 800 + uVar2 * 0x18) == 0) {
      *(undefined8 *)(param_1 + 0x330 + uVar2 * 0x18) = param_5;
      *(undefined4 *)(param_1 + 800 + uVar2 * 0x18) = param_2;
      *(undefined2 *)(param_1 + 0x326 + uVar2 * 0x18) = param_3;
      *(undefined2 *)(param_1 + 0x324 + uVar2 * 0x18) = param_3;
      *(undefined8 *)(param_1 + 0x328 + uVar2 * 0x18) = param_4;
      break;
    }
    bVar1 = bVar1 + 1;
    uVar2 = (ulonglong)bVar1;
  } while (bVar1 < 0x14);
  if (bVar1 == 0x14) {
    return 0xfe;
  }
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 1 << (bVar1 & 0x1f);
  return bVar1;
}



===== GtfStartTimerSynchronized @ 140017c90 =====

undefined8 GtfStartTimerSynchronized(longlong param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  byte bVar6;
  
  *(undefined1 *)(param_1 + 0xdb9) = 1;
  uVar2 = *(undefined8 *)(param_2 + 6);
  bVar6 = 0;
  uVar3 = *(undefined8 *)(param_2 + 2);
  uVar1 = *(undefined2 *)(param_2 + 1);
  do {
    if (*(int *)(param_1 + 800 + (ulonglong)bVar6 * 0x18) == 0) {
      uVar5 = (ulonglong)bVar6;
      *(undefined4 *)(param_1 + 800 + uVar5 * 0x18) = *param_2;
      *(undefined2 *)(param_1 + 0x326 + uVar5 * 0x18) = uVar1;
      *(undefined2 *)(param_1 + 0x324 + uVar5 * 0x18) = uVar1;
      *(undefined8 *)(param_1 + 0x328 + uVar5 * 0x18) = uVar3;
      *(undefined8 *)(param_1 + 0x330 + uVar5 * 0x18) = uVar2;
      break;
    }
    bVar6 = bVar6 + 1;
  } while (bVar6 < 0x14);
  uVar5 = 0;
  if (bVar6 == 0x14) {
    bVar6 = 0xfe;
  }
  else {
    uVar4 = 1 << (bVar6 & 0x1f);
    uVar5 = (ulonglong)uVar4;
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | uVar4;
  }
  *(byte *)(param_2 + 4) = bVar6;
  *(undefined1 *)(param_1 + 0xdb9) = 0;
  return CONCAT71((int7)(uVar5 >> 8),1);
}



===== GtfStopTimer @ 140017d40 =====

void GtfStopTimer(longlong param_1,byte param_2,int param_3)

{
  undefined1 local_38 [16];
  byte local_28;
  int local_18;
  
  if ((param_3 == 5) || (*(char *)(param_1 + 0xdb9) != '\0')) {
    GtfStopTimerCore((uint *)(param_1 + 0x310),param_2);
    return;
  }
  local_28 = param_2;
  local_18 = param_3;
  StorPortSynchronizeAccess(param_1,GtfStopTimerSynchronized,local_38);
  return;
}



===== GtfStopTimerCore @ 140017d90 =====

ulonglong GtfStopTimerCore(uint *param_1,byte param_2)

{
  byte bVar1;
  ulonglong uVar2;
  ulonglong in_RAX;
  byte bVar3;
  uint uVar4;
  longlong lVar5;
  
  if (param_2 == 0xff) {
    if (*param_1 != 0) {
      *param_1 = 0;
      lVar5 = 0;
      bVar3 = 0;
      do {
        *(undefined8 *)(lVar5 + 0x10 + (longlong)param_1) = 0;
        bVar1 = bVar3 & 0x1f;
        bVar3 = bVar3 + 1;
        *(undefined8 *)(lVar5 + 0x18 + (longlong)param_1) = 0;
        *(undefined8 *)(lVar5 + 0x20 + (longlong)param_1) = 0;
        lVar5 = lVar5 + 0x18;
        *param_1 = *param_1 & ~(1 << bVar1);
      } while (bVar3 < 0x14);
      return 0;
    }
  }
  else if ((*param_1 != 0) && (uVar4 = 1 << (param_2 & 0x1f), uVar4 != 0)) {
    uVar2 = (ulonglong)param_2;
    (param_1 + uVar2 * 6 + 4)[0] = 0;
    (param_1 + uVar2 * 6 + 4)[1] = 0;
    (param_1 + uVar2 * 6 + 6)[0] = 0;
    (param_1 + uVar2 * 6 + 6)[1] = 0;
    (param_1 + uVar2 * 6 + 8)[0] = 0;
    (param_1 + uVar2 * 6 + 8)[1] = 0;
    *param_1 = *param_1 & ~uVar4;
    return 1;
  }
  return in_RAX & 0xffffffffffffff00;
}



===== GtfStopTimerSynchronized @ 140017e20 =====

void GtfStopTimerSynchronized(longlong param_1,longlong param_2)

{
  *(undefined1 *)(param_1 + 0xdb9) = 1;
  GtfStopTimerCore((uint *)(param_1 + 0x310),*(byte *)(param_2 + 0x10));
  *(undefined1 *)(param_1 + 0xdb9) = 0;
  return;
}



===== __security_check_cookie @ 140017e70 =====

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



===== __GSHandlerCheck @ 140017ea0 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140017ec0 =====

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



===== ScsiPortWmiDispatchFunction @ 140017f20 =====

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



===== ScsiPortWmiFireLogicalUnitEvent @ 140017fc0 =====

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
                    /* WARNING: Could not recover jumptable at 0x000140018038. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    ScsiPortNotification(8,param_1,param_8,0xff);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000140018026. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ScsiPortNotification(8,param_1,param_8,param_2);
  return;
}



===== ScsiPortWmiPostProcess @ 140018040 =====

void ScsiPortWmiPostProcess(longlong param_1,char param_2,uint param_3)

{
  char cVar1;
  
  cVar1 = ScsiWmipPostProcess(*(char *)(param_1 + 0x18),*(uint **)(param_1 + 0x10),
                              *(uint *)(param_1 + 8),param_3,param_2,(uint *)(param_1 + 0x1c));
  *(char *)(param_1 + 0x19) = cVar1;
  return;
}



===== ScsiWmipFindGuid @ 140018074 =====

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



===== ScsiWmipPostProcess @ 1400180c8 =====

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
        goto LAB_140018190;
      }
      param_5 = '\x12';
    }
LAB_14001816e:
    if ((param_5 != '\x12') || (param_3 < 0x38)) goto LAB_140018190;
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
        goto LAB_140018190;
      }
      goto LAB_14001816e;
    }
    if (param_1 != '\t') goto LAB_140018190;
    uVar5 = param_2[0xf] + param_4;
    if (param_5 == '\x01') {
      if (0x47 < param_3) {
        *param_2 = uVar5;
        param_2[0x10] = param_4;
        uVar6 = uVar5;
      }
      goto LAB_140018190;
    }
    if ((param_5 != '\x12') || (param_3 < 0x38)) goto LAB_140018190;
    param_2[0xc] = uVar5;
  }
  *param_2 = 0x38;
  param_2[0xb] = 0x20;
  param_5 = '\x01';
  uVar6 = 0x38;
LAB_140018190:
  *param_6 = uVar6;
  return param_5;
}



===== ScsiWmipProcessRequest @ 140018218 =====

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
LAB_140018312:
      *param_8 = 0;
      cVar5 = '\x04';
      goto LAB_1400185f7;
    }
    if (((byte)(param_2 - 1) < 3) || (param_2 == 9)) {
      uVar6 = param_7[0xd];
      if (((char)param_7[0xb] < '\0') && (local_38[0] <= uVar6)) goto LAB_140018312;
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
          goto LAB_14001841d;
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
LAB_14001841d:
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
            goto LAB_14001861e;
          }
          goto LAB_14001862f;
        }
      }
LAB_140018352:
      cVar5 = '\x04';
      goto LAB_140018632;
    }
    pcVar8 = *(code **)(param_1 + 0xe);
    if (pcVar8 != (code *)0x0) {
      uVar19 = 0;
      uVar16 = 0;
      goto LAB_140018623;
    }
  }
  else if (param_2 == 6) {
    pcVar8 = *(code **)(param_1 + 0xe);
    if (pcVar8 != (code *)0x0) {
      uVar16 = 1;
LAB_14001861e:
      uVar19 = 1;
LAB_140018623:
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
        goto LAB_140018352;
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
          goto LAB_1400185ec;
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
          memcpy(puVar11 + 1,L"ScsiMiniPort",0x1a);
          *(ushort *)((ulonglong)uVar6 + (longlong)param_7) = uVar17;
          memcpy((ushort *)((ulonglong)uVar6 + (longlong)param_7) + 1,param_9,(ulonglong)uVar17);
          param_6 = uVar1;
        }
      }
      else {
LAB_1400185ec:
        param_6 = 0;
      }
      *param_8 = param_6;
LAB_1400185f7:
      psVar4[0] = 1;
      psVar4[1] = 0;
      return cVar5;
    }
    pcVar8 = *(code **)(param_1 + 0xe);
    if (pcVar8 != (code *)0x0) {
      uVar19 = 0;
      uVar16 = 1;
      goto LAB_140018623;
    }
  }
LAB_14001862f:
  cVar5 = '\x01';
LAB_140018632:
  psVar4[0] = 1;
  psVar4[1] = 0;
  return cVar5;
}



===== _guard_check_icall @ 140018658 =====

void _guard_check_icall(void)

{
  return;
}



===== _guard_dispatch_icall @ 140018670 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140018670. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== memcpy @ 140018680 =====

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
        if (uVar12 == 0) goto LAB_140018837;
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
LAB_140018837:
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
      if (uVar12 == 0) goto LAB_140018692;
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
LAB_140018692:
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



===== memset @ 1400189c0 =====

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
      if (uVar5 == 0) goto LAB_140018a80;
      puVar3 = puVar3 + (uVar5 - 8);
      uVar6 = uVar6 + 1;
      switch(uVar5) {
      case 2:
        goto switchD_140018a7d_caseD_2;
      case 3:
        goto switchD_140018a7d_caseD_3;
      case 4:
        goto switchD_140018a7d_caseD_4;
      case 5:
        goto switchD_140018a7d_caseD_5;
      case 6:
        goto switchD_140018a7d_caseD_6;
      case 7:
        goto switchD_140018a7d_caseD_7;
      }
      while( true ) {
        puVar3[7] = uVar4;
        puVar3 = puVar3 + 8;
        uVar6 = uVar6 - 1;
        if (uVar6 == 0) break;
LAB_140018a80:
        *puVar3 = uVar4;
switchD_140018a7d_caseD_7:
        puVar3[1] = uVar4;
switchD_140018a7d_caseD_6:
        puVar3[2] = uVar4;
switchD_140018a7d_caseD_5:
        puVar3[3] = uVar4;
switchD_140018a7d_caseD_4:
        puVar3[4] = uVar4;
switchD_140018a7d_caseD_3:
        puVar3[5] = uVar4;
switchD_140018a7d_caseD_2:
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



===== entry @ 14001e000 =====

void entry(undefined8 param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 14001e02c =====

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


